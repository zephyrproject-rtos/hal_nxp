"""Interactive cherry-pick conflict resolution."""

import os
import sys
from pathlib import Path

from .gitutil import combined_output, print_capped, run, run_status
from .patches import Patch


def conflicted_files(hal_root: Path) -> list[str]:
    """Paths git currently reports as unmerged (conflicted)."""
    out = run(["git", "diff", "--name-only", "--diff-filter=U"],
              hal_root, capture=True, check=False)
    return [l.strip() for l in out.splitlines() if l.strip()]


def cherry_pick_in_progress(hal_root: Path) -> bool:
    """True while a cherry-pick sequence is still active (CHERRY_PICK_HEAD set)."""
    git_dir = run(["git", "rev-parse", "--git-dir"], hal_root, capture=True)
    return (hal_root / git_dir / "CHERRY_PICK_HEAD").exists()


def skip_if_cherry_pick_empty(hal_root: Path, proc) -> bool:
    """If a failed cherry-pick came out "empty", run `--skip` and return True.

    An empty cherry-pick means the change is already in HEAD. Returns False when
    it was a genuine (non-empty) failure the caller must handle.
    """
    if "empty" in combined_output(proc).lower():
        run_status(["git", "cherry-pick", "--skip"], hal_root)
        return True
    return False


def resolve_conflict_interactively(hal_root: Path, patch: Patch) -> bool:
    """Pause on a cherry-pick conflict and let the developer resolve it by hand.

    Returns True when the conflict has been dealt with (committed/continued or
    skipped) and the sync loop may proceed. Returns False when the caller should
    abort the whole sync (developer asked to abort, or no TTY so it is not safe
    to wait for input).
    """
    if not sys.stdin.isatty():
        print("Not running interactively (no TTY); cannot resolve the conflict "
              "here.")
        return False

    sha = patch.hal_sha[:12]
    print("\n" + "=" * 72)
    print(f"Cherry-pick of {sha} ({patch.subject[:60]}) hit a conflict.")
    print("Resolve it in another shell (edit files, `git add` them), then come")
    print("back here and choose how to proceed:")
    print("=" * 72)

    while True:
        files = conflicted_files(hal_root)
        if files:
            print(f"\nStill {len(files)} conflicted file(s):")
            print_capped(files, cap=20, indent="    ")
        else:
            print("\nNo conflicted files remain (all resolved / staged).")

        print("\nOptions:")
        print("  [c] continue  - stage resolved files and finish this patch")
        print("  [s] skip      - drop this patch and move on")
        print("  [a] abort     - abort the cherry-pick and stop the whole sync")
        try:
            choice = input("Your choice [c/s/a]: ").strip().lower()
        except EOFError:
            print("\nEOF on input; aborting.")
            return False

        if choice in ("c", "continue"):
            if _continue_cherry_pick(hal_root, sha):
                return True
            continue
        if choice in ("s", "skip"):
            run_status(["git", "cherry-pick", "--skip"], hal_root)
            print(f"Skipped {sha} at developer's request.")
            return True
        if choice in ("a", "abort"):
            print("Aborting sync at developer's request.")
            return False
        print("Unrecognized choice; please pick one of c/s/a.")


def _continue_cherry_pick(hal_root: Path, sha: str) -> bool:
    """Stage resolved files and finish the current cherry-pick.

    Returns True when the patch is finished (committed or skipped-as-empty) and
    the loop should move on; False when the developer must keep resolving.
    """
    run(["git", "add", "-A"], hal_root)
    remaining = conflicted_files(hal_root)
    if remaining:
        print(f"Cannot continue: {len(remaining)} file(s) still conflicted. "
              f"Resolve and `git add` them first.")
        return False
    cont = run_status(
        ["git", "cherry-pick", "--continue"], hal_root,
        env={**os.environ, "GIT_EDITOR": "true"},
    )
    if cont.returncode != 0:
        # If the resolution left nothing to commit, git reports the cherry-pick
        # as empty (or the sequence is already finished); treat as "already
        # present" and skip.
        if skip_if_cherry_pick_empty(hal_root, cont) or \
                not cherry_pick_in_progress(hal_root):
            print(f"Nothing to commit after resolution; skipped {sha}.")
            return True
        print(f"git cherry-pick --continue failed:\n{cont.stdout}\n"
              f"{cont.stderr}")
        return False
    print(f"Re-applied {sha} after manual resolution.")
    return True
