"""Patch model, trailer parsing, and dest_path ownership resolution.

How a patch is attributed to an entry
-------------------------------------
The checkpoint range is a slice of the single, shared hal_nxp history, so it
contains patches from *every* team/entry, not just the one being synced. Not
every commit carries a tracking trailer either. Therefore a patch's owning entry
is decided primarily by *the files it changes*, resolved with longest-prefix-
wins across the dest_paths of ALL sources in ALL entries (west lays sub-repos
out with NESTED destinations). Trailers, when present, enrich the decision and
drive the ancestor test, but are not required.
"""

import re
from dataclasses import dataclass
from pathlib import Path
from typing import Optional

from .gitutil import changed_files, run


# mcux-sdk-commit: <repo-name>: <sha>
SDK_TRAILER = re.compile(
    r"^mcux-sdk-commit:\s*(?P<repo>[^:\s]+):\s*(?P<sha>[0-9a-f]{7,40})\s*$",
    re.MULTILINE,
)
# hal-nxp-commit: <sha>
HAL_TRAILER = re.compile(
    r"^hal-nxp-commit:\s*(?P<sha>[0-9a-f]{7,40})\s*$",
    re.MULTILINE,
)


@dataclass
class Patch:
    """One hal_nxp commit in the sync range.

    `upstream_repo`/`upstream_sha` come from a tracking trailer when present
    (None otherwise); a patch is fully usable without them (it just always
    re-applies). `has_trailer` is True iff either trailer was found.
    """
    hal_sha: str
    subject: str
    upstream_repo: Optional[str] = None
    upstream_sha: Optional[str] = None
    has_trailer: bool = False


def collect_patches(hal_root: Path, since_sha: Optional[str]) -> list[Patch]:
    """Walk hal_nxp history from HEAD back to `since_sha` (exclusive).

    Returns a Patch for *every* non-checkpoint commit in range. Commits without
    a tracking trailer still need re-applying, so we do NOT drop them; trailer
    info is captured when present and left None otherwise. Order is oldest-first
    so re-application preserves original order.
    """
    rev_range = f"{since_sha}..HEAD" if since_sha else "HEAD"
    # Use a record separator that won't appear in commit messages.
    sep = "\x1e"
    fmt = f"%H%n%s%n%b{sep}"
    out = run(
        ["git", "log", "--reverse", f"--format={fmt}", rev_range],
        hal_root, capture=True,
    )
    patches = []
    for record in out.split(sep):
        record = record.strip("\n")
        if not record:
            continue
        lines = record.split("\n", 2)
        sha = lines[0].strip()
        subject = lines[1].strip() if len(lines) > 1 else ""
        body = lines[2] if len(lines) > 2 else ""

        # Skip checkpoint commits themselves.
        if subject.startswith("mcux-sync-"):
            continue

        full = subject + "\n" + body
        sdk = SDK_TRAILER.search(full)
        hal = HAL_TRAILER.search(full)

        patch = Patch(hal_sha=sha, subject=subject)
        if sdk:
            patch.upstream_repo = sdk.group("repo")
            patch.upstream_sha = sdk.group("sha")
            patch.has_trailer = True
        elif hal:
            patch.upstream_sha = hal.group("sha")
            patch.has_trailer = True
        patches.append(patch)
    return patches


# ---------------------------------------------------------------------------
# dest_path prefix table (longest-prefix-wins, across ALL entries)
# ---------------------------------------------------------------------------

def build_prefix_table(data: dict) -> list[dict]:
    """Return {prefix, entry, source, copy} for every source's dest_path.

    Sorted by descending prefix length so the first match wins. dest_path is
    already relative to the hal_nxp git root (starts with the mcux/ prefix),
    matching the paths git reports, so it is used verbatim.

    Ownership is NOT decided by the prefix alone: a source only owns files it
    actually copies. west lays sub-repos out with NESTED destinations and one
    source (mcuxsdk-core -> mcux-sdk-ng) sits at the top; without gating on the
    copy patterns it would claim every file under mcux-sdk-ng. So we keep the
    copy regexes here and apply them in owning_source_for_file(). A source with
    no copy patterns matches everything under its dest_path (prefix-only).
    """
    table = []
    for entry in data.get("entries", []):
        for src in entry.get("sources", []):
            dest = src.get("dest_path")
            if not dest:
                continue
            full = dest.strip("/")
            if not full:
                continue
            copy_res = [re.compile(pat) for pat in (src.get("copy") or [])]
            table.append({
                "prefix": full,
                "entry": entry.get("name"),
                "source": src.get("name"),
                "copy": copy_res,
            })
    # Longest prefix first so nested dest_paths are resolved correctly.
    table.sort(key=lambda e: len(e["prefix"]), reverse=True)
    return table


def owning_source_for_file(path: str, prefix_table: list[dict]) -> Optional[dict]:
    """Return the table entry that owns `path`, or None.

    A source owns `path` when (a) `path` lies under the source's dest_path prefix
    AND (b) the path relative to that prefix (i.e. relative to the upstream repo
    root, which is what the copy regexes are written against) matches one of the
    source's copy patterns. Table entries are ordered longest-prefix-first. A
    source with no copy patterns matches anything under its prefix.
    """
    for e in prefix_table:
        pfx = e["prefix"]
        if path == pfx:
            rel = ""
        elif path.startswith(pfx + "/"):
            rel = path[len(pfx) + 1:]
        else:
            continue
        copy_res = e["copy"]
        if not copy_res:
            return e
        if any(r.search(rel) for r in copy_res):
            return e
    return None


def patch_owning_entries(patch: Patch, hal_root: Path,
                         prefix_table: list[dict]) -> set[str]:
    """Which entries a patch belongs to, by resolving each changed file's owner.

    A patch that touches several nested trees (rare) can belong to more than one
    entry; each such entry re-applies it when it is synced.
    """
    entries: set[str] = set()
    for f in changed_files(hal_root, patch.hal_sha):
        owner = owning_source_for_file(f, prefix_table)
        if owner and owner["entry"]:
            entries.add(owner["entry"])
    return entries


def patch_belongs_to_entry(patch: Patch, entry: dict, hal_root: Path,
                           prefix_table: list[dict],
                           repo_names: set[str]) -> bool:
    """Decide whether a patch (trailer or not) belongs to the entry being synced.

    Primary signal: the files the patch changes resolve (longest-prefix) to a
    source owned by this entry. Secondary signal: an mcux-sdk-commit trailer
    naming one of this entry's upstream repos (catches patches whose files were
    later removed/relocated but whose trailer still ties them to the entry).
    """
    if patch.upstream_repo and patch.upstream_repo in repo_names:
        return True
    return entry.get("name") in patch_owning_entries(patch, hal_root, prefix_table)


def entry_dropped_shas(entry: dict, hal_root: Path) -> set[str]:
    """Return the set of FULL hal_nxp commit SHAs listed under `drop_patch`.

    Maintainers use this to suppress patches the tool would otherwise re-apply
    (chiefly commits that predate the trailer convention). Each list item may be
    a full/abbreviated SHA (or a "sha: reason" note); it is resolved to a full
    SHA via `git rev-parse`. Entries that cannot be resolved are warned about
    and ignored.
    """
    dropped: set[str] = set()
    for item in entry.get("drop_patch") or []:
        if isinstance(item, dict):
            # Allow `- <sha>: <reason>` mapping form for inline documentation.
            raw = next(iter(item), None)
        else:
            raw = item
        if not raw:
            continue
        # Keep only the leading token so `sha  # note` style still resolves.
        token = str(raw).split()[0].strip()
        if not token:
            continue
        full = run(["git", "rev-parse", "--verify", "--quiet",
                    f"{token}^{{commit}}"], hal_root, capture=True, check=False)
        if not full:
            print(f"  WARNING: drop_patch entry '{token}' does not resolve to a "
                  f"commit in hal_nxp; ignoring.")
            continue
        dropped.add(full.strip())
    return dropped
