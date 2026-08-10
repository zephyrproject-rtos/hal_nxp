#!/usr/bin/env python3
"""
sync_msdk.py - Drive the SDK -> hal_nxp sync from import.yaml.

This is the thin CLI entry point. The implementation lives in the `_sync`
package next to this file (see _sync/__init__.py for the module map).

Two-phase workflow (see sync-guide.md for the concepts and import-schema.md for
the import.yaml field reference):

  Phase 1 - update (run by the maintainer when a new release lands):
      python sync_msdk.py update --manifest <manifest-revision> --entry <entry-name>
    Refreshes each source's `revision` for the entry and, by diffing the old vs
    new upstream tree, appends upstream-deleted files to a `type: remove` action
    so the human can review them before syncing.

  Phase 2 - sync (run after import.yaml has been reviewed):
      python sync_msdk.py sync --entry <entry-name>
    1. Copies each source's `copy`-matched files into its `dest_path`, applies
       the entry-level `remove`/`pin` actions, and commits the result as the
       imported snapshot. That commit carries the `mcux-sync-<entry>` marker in
       its title (per-source SHAs in its body), so it doubles as the checkpoint
       for the next sync.
    2. Walks the hal_nxp history back to the last `mcux-sync-<entry>` checkpoint
       (or `--since-sha`) and collects every patch commit in range.
    3. Classifies each patch to its owning entry (by the files it changes, with
       longest-prefix-wins over all sources' dest_paths) and, for the entry
       being synced, decides skip vs re-apply, then cherry-picks the re-apply
       set on top of the snapshot commit from step 1.

See sync-guide.md for how patches are attributed to entries, the `drop_patch`
manual skip list, trailer conventions, and MCUX_SDK_DIR / west-workspace layout.
"""

import argparse
import sys
from pathlib import Path

# Allow `python scripts/sync_msdk/sync_msdk.py ...` from any cwd by putting
# sync_msdk/ (which holds the _sync package) on sys.path.
sys.path.insert(0, str(Path(__file__).resolve().parent))

from _sync.commands import cmd_sync, cmd_update  # noqa: E402


def main() -> int:
    parser = argparse.ArgumentParser(description="hal_nxp sync driver (import.yaml)")
    sub = parser.add_subparsers(dest="command", required=True)

    up = sub.add_parser("update", help="Phase 1: resolve+write per-source revisions")
    up.add_argument("--entry", required=True)
    up.add_argument("--manifest", default=None,
                    help="Manifest revision/tag to resolve against "
                         "(default: entry.manifest.revision in import.yaml)")
    up.add_argument("--sdk-dir", default=None,
                    help="MCUX SDK dir (== west topdir); its `manifests` "
                         "subdir is the west manifest git clone. "
                         "(default: $MCUX_SDK_DIR)")
    up.add_argument("--dry-run", action="store_true")
    up.set_defaults(func=cmd_update)

    sy = sub.add_parser("sync", help="Phase 2: copy + commit snapshot + re-apply patches")
    sy.add_argument("--entry", required=True)
    sy.add_argument("--since-sha", default=None,
                    help="Override the scan start (default: last checkpoint)")
    sy.add_argument("--sdk-dir", default=None,
                    help="MCUX SDK dir (== west topdir) holding the source "
                         "clones; its `manifests` subdir is the west manifest "
                         "git clone. (default: $MCUX_SDK_DIR)")
    sy.add_argument("--dry-run", action="store_true")
    sy.set_defaults(func=cmd_sync)

    args = parser.parse_args()
    return args.func(args)


if __name__ == "__main__":
    raise SystemExit(main())
