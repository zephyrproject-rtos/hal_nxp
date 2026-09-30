"""Sync checkpoint markers and the imported-snapshot commit.

The import snapshot commit carries the `mcux-sync-<entry>` marker in its title
(per-source SHAs in its body), so it doubles as the checkpoint for the next
sync. No separate empty marker commit is created.
"""

from pathlib import Path
from typing import Optional

from .gitutil import run


def checkpoint_marker(entry_name: str) -> str:
    return f"mcux-sync-{entry_name}"


def find_last_checkpoint(hal_root: Path, entry_name: str) -> Optional[str]:
    """SHA of the most recent commit whose title starts with the marker, or None."""
    marker = checkpoint_marker(entry_name)
    out = run(
        ["git", "log", "--format=%H %s", "-n", "2000"],
        hal_root, capture=True, check=False,
    )
    for line in out.splitlines():
        sha, _, subject = line.partition(" ")
        if subject.startswith(marker):
            return sha
    return None


def entry_dest_prefixes(entry: dict) -> list[str]:
    """Return the dest_path prefixes for every source in the entry.

    dest_path is already relative to the hal_nxp git root (starts with the mcux/
    prefix), so it is used verbatim. Used to scope `git add` so the import commit
    only stages the trees this entry manages.
    """
    prefixes = []
    for src in entry.get("sources", []):
        dest = (src.get("dest_path") or "").strip("/")
        if dest:
            prefixes.append(dest)
    return prefixes


def commit_import(hal_root: Path, entry: dict, dry_run: bool) -> bool:
    """Stage the entry's dest_path trees and commit them as the upstream snapshot.

    This commit MUST exist before patches are re-applied so cherry-pick runs on
    top of the new upstream tree, not the stale previous HEAD. Returns True if a
    commit was created (or would be, in dry-run), False if nothing to commit.
    """
    prefixes = entry_dest_prefixes(entry)
    if not prefixes:
        print("  [import] no dest paths to stage")
        return False
    # -A picks up new/modified/deleted files under each prefix.
    run(["git", "add", "-A", "--"] + prefixes, hal_root)
    staged = run(["git", "diff", "--cached", "--name-only"],
                 hal_root, capture=True, check=False)
    if not staged.strip():
        print("  [import] tree already matches upstream; nothing to commit")
        return False
    n_staged = len([l for l in staged.splitlines() if l.strip()])
    marker = checkpoint_marker(entry["name"])
    man_rev = (entry.get("manifest") or {}).get("revision", "?")
    title = f"{marker}: import {entry['name']} sources @ {man_rev}"
    # Record the per-source revisions in the body: this commit carries the
    # imported tree AND doubles as the sync checkpoint.
    # `- name: revision` list form (not bare `name: revision`): the leading
    # `- ` stops git from treating these as a trailer block, so `git commit -s`
    # leaves a blank line before the appended Signed-off-by.
    body_lines = [
        f"- {src.get('name', '?')}: {src.get('revision', '?')}"
        for src in entry.get("sources", [])
    ]
    message = title + ("\n\n" + "\n".join(body_lines) + "\n" if body_lines
                       else "")
    if dry_run:
        print(f"[dry-run] would commit imported snapshot ({n_staged} path(s)):\n"
              f"{message}\n")
        return True
    run(["git", "commit", "-q", "-s", "-m", message], hal_root)
    print(f"Committed imported snapshot ({n_staged} path(s)): {title}")
    return True
