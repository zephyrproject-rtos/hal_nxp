"""import.yaml loading/saving and SDK-dir (west topdir) resolution."""

import os
import sys
from pathlib import Path

try:
    import yaml
except ImportError:
    print("Error: PyYAML is required (pip install pyyaml)", file=sys.stderr)
    raise SystemExit(1)


# Layout: mcux/scripts/sync_msdk/_sync/config.py
#   this file    -> _sync/
#   .parent      -> sync_msdk/   (SCRIPT_DIR: holds sync_msdk.py)
#   .parent x3   -> mcux/        (holds import.yaml)
SCRIPT_DIR = Path(__file__).resolve().parent.parent
IMPORT_YAML = SCRIPT_DIR.parent.parent / "import.yaml"


def load_import_yaml(path: Path) -> dict:
    """Read-only load of import.yaml (comments discarded)."""
    with open(path) as f:
        return yaml.safe_load(f)


# ruamel round-trips YAML while preserving comments, key order and formatting.
# `update` edits import.yaml in place (only the resolved `revision:` scalars),
# so it must NOT go through yaml.safe_dump (that would strip every comment).
def _ruamel():
    try:
        from ruamel.yaml import YAML
    except ImportError:
        print("Error: ruamel.yaml is required for 'update' "
              "(pip install ruamel.yaml)", file=sys.stderr)
        raise SystemExit(1)
    y = YAML()
    y.preserve_quotes = True
    # import.yaml uses 2-space block indent with a 2-space sequence offset.
    y.indent(mapping=2, sequence=4, offset=2)
    y.width = 4096  # don't wrap long scalars/comments
    return y


def load_import_yaml_rt(path: Path):
    """Comment-preserving (round-trip) load; returns (yaml, data)."""
    y = _ruamel()
    with open(path) as f:
        return y, y.load(f)


def save_import_yaml_rt(y, data, path: Path) -> None:
    with open(path, "w") as f:
        y.dump(data, f)


def resolve_sdk_dir(args) -> Path:
    """Resolve the MCUX SDK dir, which IS the west workspace topdir.

    Preference order:
      1. the --sdk-dir argument, when given;
      2. the MCUX_SDK_DIR environment variable.

    This single directory holds the source clones (west topdir), and its
    `manifests` subdirectory is the west manifest git clone.
    """
    raw = getattr(args, "sdk_dir", None) or os.environ.get("MCUX_SDK_DIR")
    if not raw:
        print("Error: SDK dir not set (pass --sdk-dir or set MCUX_SDK_DIR)",
              file=sys.stderr)
        raise SystemExit(1)
    return Path(raw).expanduser().resolve()


def manifest_repo_for(sdk_dir: Path) -> Path:
    """The west manifest git clone lives at <sdk_dir>/manifests."""
    return sdk_dir / "manifests"


def find_entry(data: dict, name: str) -> dict:
    for e in data.get("entries", []):
        if e.get("name") == name:
            return e
    print(f"Error: entry '{name}' not found in {IMPORT_YAML}", file=sys.stderr)
    raise SystemExit(1)
