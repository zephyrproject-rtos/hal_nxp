"""Phase-2 copy / remove / pin execution, plus the update-time deletion scan."""

import re
import subprocess
from pathlib import Path

from .gitutil import (GIT_ARGV_CHUNK, print_capped, run, run_git_chunked,
                      run_status)
from .manifest import ensure_revision, resolve_source_clone


# ---------------------------------------------------------------------------
# Upstream deletion scan (used by `update`)
# ---------------------------------------------------------------------------

def upstream_deleted_files(clone: Path, old_rev: str, new_rev: str,
                           copy_pats: list[str], dest_rel: str) -> list[str]:
    """hal_nxp-root-relative paths DELETED between `old_rev` and `new_rev`.

    Restricted to files the source actually copies (matching `copy_pats`). Each
    returned path is `dest_rel/<repo-relative-path>`, i.e. exactly where the file
    lives in hal_nxp, so it can feed a `type: remove` action verbatim. Files
    upstream deletes are otherwise invisible to the Phase-2 overlay copy.
    """
    diff = run(
        ["git", "diff", "--name-only", "--diff-filter=D",
         f"{old_rev}", f"{new_rev}"],
        clone, capture=True, check=False,
    )
    copy_res = [re.compile(p) for p in copy_pats]
    deleted = []
    for rel in diff.splitlines():
        rel = rel.strip()
        if not rel:
            continue
        # A source with copy patterns only owns files those patterns match.
        if copy_res and not any(r.search(rel) for r in copy_res):
            continue
        deleted.append(f"{dest_rel}/{rel}" if dest_rel else rel)
    return deleted


def append_remove_action(entry, paths: list[str]) -> int:
    """Record `paths` into the entry's `actions` as a `type: remove` action.

    Patterns are anchored, regex-escaped (`^<path>$`) so each matches exactly one
    file, and are appended to an existing auto-generated remove action when
    present (or a new one otherwise), skipping duplicates. Returns the number of
    newly added patterns. The action is tagged with an auto-generated `note` so
    re-running `update` reuses the same block.
    """
    if not paths:
        return 0
    auto_note = "auto: upstream-deleted files (added by sync_msdk.py update)"
    actions = entry.get("actions")
    if actions is None:
        actions = []
        entry["actions"] = actions

    target = None
    for action in actions:
        if action.get("type") == "remove" and action.get("note") == auto_note:
            target = action
            break
    if target is None:
        target = {"type": "remove", "note": auto_note, "patterns": []}
        actions.append(target)
    if target.get("patterns") is None:
        target["patterns"] = []

    existing = set(target["patterns"])
    added = 0
    for p in paths:
        pat = f"^{re.escape(p)}$"
        if pat not in existing:
            target["patterns"].append(pat)
            existing.add(pat)
            added += 1
    return added


def source_deleted_files(src: dict, old_rev, new_rev, manifest_paths: dict,
                         sdk_dir: Path) -> list[str]:
    """Best-effort list of paths this source deletes going old_rev -> new_rev.

    Locates the source's local clone, guarantees both revisions are present
    (fetching if needed), then delegates to upstream_deleted_files(). Returns []
    (with a warning) when the clone or a revision cannot be resolved, so `update`
    never aborts on it.
    """
    name = src.get("name", "?")
    dest_rel = (src.get("dest_path") or "").strip("/")
    copy_pats = src.get("copy") or []
    clone = resolve_source_clone(src, manifest_paths, sdk_dir)
    if not clone:
        print(f"  WARNING: {name}: clone not found under {sdk_dir}; "
              f"cannot compute upstream deletions.")
        return []
    for rev in (old_rev, new_rev):
        if not ensure_revision(clone, src.get("repo"), str(rev)):
            print(f"  WARNING: {name}: revision {str(rev)[:12]} not in clone "
                  f"and could not be fetched; skipping deletion scan.")
            return []
    return upstream_deleted_files(clone, str(old_rev), str(new_rev),
                                  copy_pats, dest_rel)


# ---------------------------------------------------------------------------
# Copy (Phase 2a)
# ---------------------------------------------------------------------------

def copy_sources(entry: dict, hal_root: Path, west_topdir: Path,
                 manifest_paths: dict, dry_run: bool) -> int:
    """Overlay each source's `copy`-matched files at its `revision` into dest_path.

    The exact pinned `revision` is fetched into the clone first (see
    ensure_revision): the extraction always reads the pinned SHA, never
    "whatever is currently checked out". Overlay semantics (no pre-clean): files
    deleted upstream are handled by `update` appending them to a `remove` action.
    Returns the number of files copied (0 in dry-run, but still validates), or
    -1 on error.
    """
    total = 0
    for src in entry.get("sources", []):
        name = src.get("name", "?")
        rev = src.get("revision")
        dest_rel = (src.get("dest_path") or "").strip("/")
        copy_pats = src.get("copy") or []
        if not rev or "<" in str(rev):
            print(f"  [copy] {name}: SKIP (revision unresolved: {rev})")
            continue
        clone = resolve_source_clone(src, manifest_paths, west_topdir)
        if not clone:
            print(f"  [copy] {name}: ERROR clone not found under {west_topdir}")
            return -1
        # Guarantee the EXACT pinned revision is available before extraction.
        if not ensure_revision(clone, src.get("repo"), rev):
            print(f"  [copy] {name}: ERROR revision {str(rev)[:12]} not in "
                  f"clone {clone} and could not be fetched from "
                  f"{src.get('repo') or 'origin'}")
            return -1

        copy_res = [re.compile(p) for p in copy_pats]
        files = run(["git", "ls-tree", "-r", "--name-only", rev],
                    clone, capture=True).splitlines()
        matched = [f for f in files if any(r.search(f) for r in copy_res)]
        # dest_path is already relative to the hal_nxp git root.
        dest_root = hal_root / dest_rel

        print(f"  [copy] {name} @ {str(rev)[:12]}: {len(matched)} file(s) "
              f"-> {dest_root.relative_to(hal_root)}")
        if dry_run:
            total += len(matched)
            continue
        # Stream the selected paths out of the clone at the exact revision via
        # `git archive` and untar straight into the destination. This preserves
        # each file's repo-relative path and never touches the clone's worktree.
        dest_root.mkdir(parents=True, exist_ok=True)
        # git archive has an argv length limit; chunk the path list.
        for i in range(0, len(matched), GIT_ARGV_CHUNK):
            chunk = matched[i:i + GIT_ARGV_CHUNK]
            archive = run_status(
                ["git", "archive", "--format=tar", rev, "--"] + chunk,
                clone, text=False,
            )
            if archive.returncode != 0:
                print(f"  [copy] {name}: git archive failed: "
                      f"{archive.stderr.decode(errors='replace')}")
                return -1
            untar = run_status(
                ["tar", "-x", "-C", str(dest_root)],
                clone, input_bytes=archive.stdout, text=False,
            )
            if untar.returncode != 0:
                print(f"  [copy] {name}: tar extract failed: "
                      f"{untar.stderr.decode(errors='replace')}")
                return -1
        total += len(matched)
    return total


# ---------------------------------------------------------------------------
# Actions: remove / pin (Phase 2a)
# ---------------------------------------------------------------------------

def _iter_repo_files(hal_root: Path) -> list[str]:
    """All tracked + untracked (non-ignored) files, relative to hal_root."""
    out = run(["git", "ls-files", "--cached", "--others", "--exclude-standard"],
              hal_root, capture=True)
    return [l for l in out.splitlines() if l]


def apply_actions(entry: dict, hal_root: Path, dry_run: bool) -> int:
    """Execute the entry-level `actions` list in order (`remove` and `pin`).

    Patterns/files are Python regexes matched against paths relative to the
    hal_nxp repo root. Returns 0 on success, -1 on error.
    """
    actions = entry.get("actions") or []
    if not actions:
        print("  [actions] none")
        return 0
    for idx, action in enumerate(actions):
        atype = action.get("type")
        if atype == "remove":
            rc = _apply_remove(action, idx, hal_root, dry_run)
        elif atype == "pin":
            rc = _apply_pin(action, idx, hal_root, dry_run)
        else:
            print(f"  [action #{idx}] ERROR unsupported type: {atype}")
            return -1
        if rc < 0:
            return -1
    return 0


def _apply_remove(action: dict, idx: int, hal_root: Path, dry_run: bool) -> int:
    pats = [re.compile(p) for p in (action.get("patterns") or [])]
    files = _iter_repo_files(hal_root)
    victims = [f for f in files if any(r.search(f) for r in pats)]
    print(f"  [remove #{idx}] {len(victims)} file(s) match {len(pats)} pattern(s)")
    if dry_run:
        print_capped(victims)
        return 0
    for v in victims:
        fp = hal_root / v
        try:
            if fp.is_file() or fp.is_symlink():
                fp.unlink()
        except OSError as e:
            print(f"      WARN could not remove {v}: {e}")
    return 0


def _apply_pin(action: dict, idx: int, hal_root: Path, dry_run: bool) -> int:
    commit = action.get("commit") or "HEAD"
    file_res = [re.compile(p) for p in (action.get("patterns") or [])]
    # Enumerate files present at that commit, keep matches, check them out.
    tree = run(["git", "ls-tree", "-r", "--name-only", commit],
               hal_root, capture=True, check=False).splitlines()
    targets = [f for f in tree if any(r.search(f) for r in file_res)]
    print(f"  [pin #{idx}] {len(targets)} file(s) from {commit[:12]}")
    if dry_run:
        print_capped(targets)
        return 0
    try:
        run_git_chunked(["git", "checkout", "-q", commit], targets, hal_root)
    except subprocess.CalledProcessError as e:
        print(f"      ERROR git checkout failed: {e}")
        return -1
    return 0
