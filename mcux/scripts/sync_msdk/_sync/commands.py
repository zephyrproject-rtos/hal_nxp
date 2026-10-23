"""The `update` (Phase 1) and `sync` (Phase 2) subcommands."""

import sys
from pathlib import Path
from typing import Optional

from .actions import (append_remove_action, apply_actions, copy_sources,
                      source_deleted_files)
from .checkpoint import commit_import, find_last_checkpoint
from .config import (IMPORT_YAML, SCRIPT_DIR, find_entry, load_import_yaml,
                     load_import_yaml_rt, manifest_repo_for, resolve_sdk_dir,
                     save_import_yaml_rt)
from .conflicts import resolve_conflict_interactively, skip_if_cherry_pick_empty
from .gitutil import git_toplevel, is_ancestor, print_capped, run_status
from .manifest import (build_manifest_path_map, ensure_revision,
                       parse_manifest_projects, resolve_source_clone)
from .patches import (Patch, build_prefix_table, collect_patches,
                      entry_dropped_shas, patch_belongs_to_entry)


# ---------------------------------------------------------------------------
# Phase 1: update
# ---------------------------------------------------------------------------

def cmd_update(args) -> int:
    """Resolve every source's revision for an entry from the west manifest.

    Writes the resolved SHAs (and the manifest revision) back into import.yaml
    in place, preserving comments/formatting. For each source whose revision
    changes, diffs the old vs new upstream tree (restricted to the source's
    `copy` patterns) and appends every upstream-deleted file to a `type: remove`
    action, so the maintainer can review the removals before running the sync.
    """
    # ruamel round-trip so comments in import.yaml survive the write.
    y, data = load_import_yaml_rt(IMPORT_YAML)
    entry = find_entry(data, args.entry)
    sources = entry.get("sources", [])
    print(f"Entry '{args.entry}': {len(sources)} source(s)")

    sdk_dir = resolve_sdk_dir(args)
    manifest_repo = manifest_repo_for(sdk_dir)
    if not (manifest_repo / ".git").exists():
        print(f"Error: manifest repo not found at {manifest_repo} "
              f"(expected <sdk-dir>/manifests; set --sdk-dir or MCUX_SDK_DIR)",
              file=sys.stderr)
        return 1

    # Manifest revision to resolve against: explicit --manifest, else the value
    # already recorded on the entry.
    man_rev = args.manifest or (entry.get("manifest") or {}).get("revision")
    if not man_rev:
        print("Error: no manifest revision given (pass --manifest or set "
              "entry.manifest.revision)", file=sys.stderr)
        return 1
    print(f"Resolving revisions from manifest {manifest_repo} @ {man_rev}")

    projects = parse_manifest_projects(manifest_repo, man_rev)
    if not projects:
        print(f"Error: no projects parsed from manifest at {man_rev}",
              file=sys.stderr)
        return 1

    # Locate each source's local clone so old->new trees can be diffed.
    manifest_paths = build_manifest_path_map(manifest_repo, man_rev)

    updates, missing, deleted_paths = _resolve_source_revisions(
        sources, projects, manifest_paths, sdk_dir)

    # Refresh the entry-level manifest revision too.
    if entry.get("manifest") is not None:
        entry["manifest"]["revision"] = man_rev

    for name, old, new in updates:
        print(f"  {name}: {str(old)[:12]} -> {str(new)[:12]}")
    if not updates:
        print("  (all source revisions already up to date)")
    if missing:
        print(f"  WARNING: {len(missing)} source(s) not found in manifest: "
              f"{', '.join(missing)}")

    # Record upstream-deleted files into a `remove` action for review.
    added = append_remove_action(entry, deleted_paths) if deleted_paths else 0
    if deleted_paths:
        print(f"  {len(deleted_paths)} file(s) deleted upstream; "
              f"{added} new remove pattern(s) queued for review:")
        print_capped(deleted_paths)

    if args.dry_run:
        print(f"[dry-run] would update {len(updates)} revision(s), the manifest "
              f"revision, and {added} remove pattern(s) in {IMPORT_YAML.name}.")
        return 0

    save_import_yaml_rt(y, data, IMPORT_YAML)
    print(f"Wrote {len(updates)} revision update(s) and {added} remove "
          f"pattern(s) to {IMPORT_YAML.name}.")
    return 0


def _resolve_source_revisions(sources, projects, manifest_paths, sdk_dir):
    """Resolve each source's new revision; collect updates, misses, deletions.

    Mutates each source's `revision` in place. Returns
    (updates, missing, deleted_paths) where updates is [(name, old, new)].
    """
    updates = []
    missing = []
    deleted_paths = []   # hal_nxp-root-relative paths deleted upstream
    for src in sources:
        name = src.get("name")
        if not name:
            continue
        new_rev = projects.get(name)
        if not new_rev:
            missing.append(name)
            continue
        old_rev = src.get("revision")
        if str(old_rev) != str(new_rev):
            updates.append((name, old_rev, new_rev))
            # Diff old->new upstream tree for files this source copies that were
            # deleted upstream. Best-effort: skip silently if unavailable.
            deleted_paths += source_deleted_files(
                src, old_rev, new_rev, manifest_paths, sdk_dir)
        src["revision"] = new_rev
    return updates, missing, deleted_paths


# ---------------------------------------------------------------------------
# Phase 2: sync
# ---------------------------------------------------------------------------

def _load_manifest_paths(entry: dict, sdk_dir: Path) -> dict:
    """Locate each source's local clone path via the west manifest, if available."""
    manifest_repo = manifest_repo_for(sdk_dir)
    man_rev = (entry.get("manifest") or {}).get("revision")
    if manifest_repo and (manifest_repo / ".git").exists() and man_rev:
        return build_manifest_path_map(manifest_repo, man_rev)
    return {}


def select_entry_patches(data: dict, entry: dict, hal_root: Path,
                         since: Optional[str]) -> list[Patch]:
    """Collect the checkpoint range and keep ONLY patches belonging to this entry.

    The range is shared by every team's entry, so it contains unrelated patches
    and patches with no trailer. Classification is by the files each commit
    changes, resolving nested west dest_paths with longest-prefix-wins.
    """
    all_patches = collect_patches(hal_root, since)
    prefix_table = build_prefix_table(data)
    repo_names = {
        src.get("name") for src in entry.get("sources", []) if src.get("name")
    }
    patches = [
        p for p in all_patches
        if patch_belongs_to_entry(p, entry, hal_root, prefix_table, repo_names)
    ]
    print(f"{len(all_patches)} patch(es) in range; {len(patches)} belong to "
          f"entry '{entry.get('name')}'.")
    return patches


def upstream_has_patch(src: dict, upstream_sha: str, new_release_sha: str,
                       manifest_paths: dict, sdk_dir: Path) -> bool:
    """Answer "has this patch already reached the release being synced?"

    Tests, INSIDE THE SOURCE'S UPSTREAM CLONE, whether `upstream_sha` is an
    ancestor of `new_release_sha` (the revision import.yaml pins for this
    source). Conservative on any uncertainty (returns False -> the patch
    re-applies): when the clone can't be located, or either commit can't be made
    present in it (fetched if missing), we do NOT skip the patch.
    """
    clone = resolve_source_clone(src, manifest_paths, sdk_dir)
    if not clone:
        return False
    for rev in (upstream_sha, new_release_sha):
        if not ensure_revision(clone, src.get("repo"), str(rev)):
            return False
    return is_ancestor(clone, upstream_sha, new_release_sha)


def compute_reapply_set(patches: list[Patch], entry: dict, hal_root: Path,
                        manifest_paths: dict, sdk_dir: Path) -> list[Patch]:
    """Decide skip vs re-apply for each entry patch; return the re-apply set.

    A drop_patch listing wins over everything; otherwise an SDK-origin patch
    whose upstream commit is already an ancestor of the new release is skipped;
    all other patches re-apply.
    """
    # repo name -> its source dict (carries revision, repo URL, clone hints).
    src_by_repo = {
        src.get("name"): src
        for src in entry.get("sources", [])
        if src.get("name")
    }
    dropped_shas = entry_dropped_shas(entry, hal_root)

    to_reapply = []
    for p in patches:
        src = src_by_repo.get(p.upstream_repo) if p.upstream_repo else None
        new_sha = src.get("revision") if src else None

        verdict = "re-apply"
        if p.hal_sha in dropped_shas:
            verdict = "skip (drop_patch)"
        # Only SDK-origin patches with a resolvable upstream SHA can be skipped
        # by the ancestor test; trailer-less or hal_nxp-origin patches always
        # re-apply. Ignore unresolved "<...>" placeholder revisions.
        elif src and p.upstream_sha and new_sha and "<" not in str(new_sha):
            if upstream_has_patch(src, p.upstream_sha, str(new_sha),
                                  manifest_paths, sdk_dir):
                verdict = "skip (already present)"

        if verdict.startswith("skip"):
            print(f"  SKIP    {p.hal_sha[:12]} {p.subject[:56]}  ({verdict})")
        else:
            print(f"  REAPPLY {p.hal_sha[:12]} {p.subject[:56]}")
            to_reapply.append(p)
    return to_reapply


def apply_patches(to_reapply: list[Patch], hal_root: Path, dry_run: bool) -> int:
    """Cherry-pick the re-apply set on top of the imported snapshot, in order.

    Empty cherry-picks (change already present) are skipped; conflicts pause for
    interactive resolution on a TTY and abort otherwise. Returns 0 on success, 1
    if the sync was aborted.
    """
    print(f"\n{len(to_reapply)} patch(es) to re-apply on top of the imported "
          f"snapshot.")
    # Re-apply by cherry-picking the hal_nxp commits (they still carry
    # trailers). Deliberately NOT using `-x`: patch provenance is already tracked
    # by the trailers, so the original commit message is kept verbatim.
    for p in to_reapply:
        if dry_run:
            print(f"[dry-run] git cherry-pick {p.hal_sha[:12]}")
            continue

        r = run_status(["git", "cherry-pick", p.hal_sha], hal_root)
        if r.returncode != 0:
            if skip_if_cherry_pick_empty(hal_root, r):
                print(f"Skipped {p.hal_sha[:12]} (already present / empty).")
                continue
            print(f"cherry-pick conflict for {p.hal_sha[:12]}:\n"
                  f"{r.stdout}\n{r.stderr}")
            # A conflict is not fatal: let the developer resolve it by hand and
            # continue. When stdin is not a TTY (CI / piped input) we abort.
            if not resolve_conflict_interactively(hal_root, p):
                run_status(["git", "cherry-pick", "--abort"], hal_root)
                print("Aborted. Resolve manually and re-run with --since-sha.")
                return 1
            continue
        print(f"Re-applied {p.hal_sha[:12]}")
    return 0


def cmd_sync(args) -> int:
    hal_root = git_toplevel(SCRIPT_DIR)
    data = load_import_yaml(IMPORT_YAML)
    entry = find_entry(data, args.entry)

    # Phase 2a: copy upstream sources, apply the entry's remove/pin actions, then
    # commit the imported snapshot. This snapshot commit carries the
    # `mcux-sync-<entry>` checkpoint marker and MUST exist before the patch
    # re-apply below, so the cherry-picks land on top of the fresh upstream tree.
    sdk_dir = resolve_sdk_dir(args)
    west_topdir = sdk_dir
    manifest_paths = _load_manifest_paths(entry, sdk_dir)
    print(f"Copying sources into hal_nxp (west topdir {west_topdir}) ...")
    if copy_sources(entry, hal_root, west_topdir, manifest_paths,
                    args.dry_run) < 0:
        print("Copy step failed; aborting before touching history.")
        return 1
    if apply_actions(entry, hal_root, args.dry_run) < 0:
        print("Action step failed; aborting.")
        return 1
    commit_import(hal_root, entry, args.dry_run)

    # Phase 2b: find the scan range, keep this entry's patches, decide skip vs
    # re-apply, then cherry-pick the re-apply set on top of the snapshot.
    since = args.since_sha or find_last_checkpoint(hal_root, args.entry)
    if since:
        print(f"Scanning patches since checkpoint {since[:12]}")
    else:
        print("No checkpoint found; scanning full history for patches.")

    patches = select_entry_patches(data, entry, hal_root, since)
    to_reapply = compute_reapply_set(patches, entry, hal_root,
                                     manifest_paths, sdk_dir)
    if apply_patches(to_reapply, hal_root, args.dry_run) != 0:
        return 1

    # No trailing checkpoint commit: the import snapshot commit made by
    # commit_import already carries the `mcux-sync-<entry>` marker and per-source
    # SHAs, so find_last_checkpoint() uses THAT commit as the next boundary.
    return 0
