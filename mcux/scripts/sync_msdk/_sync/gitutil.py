"""Thin git/subprocess helpers shared across the sync driver."""

import subprocess
from pathlib import Path
from typing import Optional


# git has an argv length limit, so long path lists are passed in chunks.
GIT_ARGV_CHUNK = 500


def run(cmd: list[str], cwd: Path, capture: bool = False, check: bool = True,
        input_text: Optional[str] = None) -> str:
    """Run `cmd`; return stripped stdout when `capture`, else "".

    Raises on non-zero exit unless `check=False`. This is the fire-and-forget /
    raise-on-failure helper; use `run_status` when you need to branch on the
    exit code without raising.
    """
    if capture:
        r = subprocess.run(
            cmd, cwd=str(cwd), capture_output=True, text=True,
            check=check, input=input_text,
        )
        return r.stdout.rstrip("\n")
    subprocess.run(cmd, cwd=str(cwd), check=check, input=input_text, text=True)
    return ""


def run_status(cmd: list[str], cwd: Path,
               input_bytes: Optional[bytes] = None,
               text: bool = True,
               env: Optional[dict] = None) -> subprocess.CompletedProcess:
    """Run `cmd` capturing returncode/stdout/stderr WITHOUT raising.

    For call sites that must branch on the exit status (git ancestor tests,
    fetches, cherry-picks, archive/untar).
    """
    return subprocess.run(
        cmd, cwd=str(cwd), capture_output=True,
        text=text, input=input_bytes, env=env,
    )


def combined_output(proc: subprocess.CompletedProcess) -> str:
    """stdout + stderr of a completed process as one searchable string."""
    return (proc.stdout or "") + (proc.stderr or "")


def run_git_chunked(base_cmd: list[str], paths: list[str], cwd: Path) -> None:
    """Run `base_cmd -- <paths>` in chunks, raising on the first failure."""
    for i in range(0, len(paths), GIT_ARGV_CHUNK):
        run(base_cmd + ["--"] + paths[i:i + GIT_ARGV_CHUNK], cwd)


def git_toplevel(path: Path) -> Path:
    """Resolve the git repository root that contains `path`."""
    top = run(["git", "rev-parse", "--show-toplevel"], path, capture=True)
    return Path(top).resolve()


def is_ancestor(repo: Path, ancestor_sha: str, descendant_sha: str) -> bool:
    """True iff `ancestor_sha` is an ancestor of `descendant_sha` in `repo`."""
    r = run_status(
        ["git", "merge-base", "--is-ancestor", ancestor_sha, descendant_sha],
        repo,
    )
    # 0 -> is ancestor, 1 -> not ancestor, other -> error (treat as unknown)
    return r.returncode == 0


def changed_files(hal_root: Path, sha: str) -> list[str]:
    """List the git-root-relative paths a single commit changes."""
    # `git show -s`/`--no-patch` cannot be combined with `--name-only`, so use
    # diff-tree directly: it lists the paths a commit changes (relative to the
    # git root), handling the normal single-parent case cleanly.
    out = run(
        ["git", "diff-tree", "--no-commit-id", "--name-only", "-r", sha],
        hal_root, capture=True, check=False,
    )
    return [line.strip() for line in out.splitlines() if line.strip()]


def print_capped(items: list[str], cap: int = 10, indent: str = "      ") -> None:
    """Print up to `cap` items, then a '... and N more' summary line."""
    for it in items[:cap]:
        print(f"{indent}- {it}")
    if len(items) > cap:
        print(f"{indent}... and {len(items) - cap} more")
