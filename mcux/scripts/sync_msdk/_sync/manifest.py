"""West manifest parsing and location of each source's local clone."""

from pathlib import Path
from typing import Optional

import yaml

from .gitutil import run, run_status


def _iter_manifest_projects(manifest_repo: Path, rev: str):
    """Yield every west-manifest project dict found at `rev`.

    Projects live in submanifests/*.yml (and the top-level west.yml); we
    enumerate the tree at `rev` and safe_load each YAML (read-only), yielding the
    `manifest.projects` entries.
    """
    out = run(["git", "ls-tree", "-r", "--name-only", rev],
              manifest_repo, capture=True)
    for f in out.splitlines():
        if not f.endswith((".yml", ".yaml")):
            continue
        content = run(["git", "show", f"{rev}:{f}"],
                      manifest_repo, capture=True, check=False)
        if not content.strip():
            continue
        try:
            doc = yaml.safe_load(content)
        except yaml.YAMLError:
            continue
        man = doc.get("manifest") if isinstance(doc, dict) else None
        if not isinstance(man, dict):
            continue
        for proj in man.get("projects", []) or []:
            if isinstance(proj, dict):
                yield proj


def _index_manifest(manifest_repo: Path, rev: str, select) -> dict:
    """Build {project-key -> select(proj)} over every manifest project at `rev`.

    Keyed by BOTH `repo-path` and `name` so an import.yaml source `name` (== the
    upstream GitHub repo name == the manifest `repo-path`) resolves regardless of
    which the manifest used. First definition wins. Projects whose `select(proj)`
    is falsy are skipped.
    """
    index: dict = {}
    for proj in _iter_manifest_projects(manifest_repo, rev):
        v = select(proj)
        if not v:
            continue
        for key in (proj.get("repo-path"), proj.get("name")):
            if key and key not in index:
                index[key] = v
    return index


def parse_manifest_projects(manifest_repo: Path, rev: str) -> dict:
    """{project-key -> revision} for locating each source's pinned SHA."""
    return _index_manifest(manifest_repo, rev, lambda p: p.get("revision"))


def build_manifest_path_map(manifest_repo: Path, rev: str) -> dict:
    """{project-key -> checkout path} (west `path:`, defaulting to name).

    Used to locate each source's local clone so its files can be copied.
    """
    return _index_manifest(manifest_repo, rev,
                           lambda p: p.get("path") or p.get("name"))


def resolve_source_clone(src: dict, manifest_paths: dict,
                         west_topdir: Path) -> Optional[Path]:
    """Locate the local clone directory for a source.

    Preference order:
      1. the west `path:` for the source's name from the manifest;
      2. west topdir / name as a last resort.
    Returns the path if it is a git repo, else None.
    """
    name = src.get("name")
    candidates = []
    if name and name in manifest_paths and manifest_paths[name]:
        candidates.append(Path(manifest_paths[name]))
    if name:
        candidates.append(Path(name))
    for c in candidates:
        d = c if c.is_absolute() else (west_topdir / c)
        d = d.resolve()
        if (d / ".git").exists():
            return d
    return None


def ensure_revision(clone: Path, repo_url: Optional[str], rev: str) -> bool:
    """Guarantee commit `rev` exists as an object in `clone` before extraction.

    The west workspace clone is whatever the maintainer last checked out /
    fetched, so the exact SHA pinned in import.yaml is NOT guaranteed to be
    present locally. If the object is already present, do nothing; otherwise
    fetch that specific revision from the source's `repo` URL (falling back to
    `origin`), then re-test. Returns True when `rev` resolves to a commit.
    """
    def present() -> bool:
        chk = run_status(["git", "cat-file", "-e", f"{rev}^{{commit}}"], clone)
        return chk.returncode == 0

    if present():
        return True

    # Try fetching the exact revision. Prefer the explicit source repo URL so we
    # pull from the same GitHub repo import.yaml pins against; fall back to the
    # clone's configured `origin` remote.
    remotes = [r for r in (repo_url, "origin") if r]
    for remote in remotes:
        fetched = run_status(["git", "fetch", "--quiet", remote, rev], clone)
        if fetched.returncode == 0 and present():
            return True
    return present()
