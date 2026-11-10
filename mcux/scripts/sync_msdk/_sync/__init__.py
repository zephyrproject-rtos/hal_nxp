"""Internal package for the hal_nxp sync driver.

The public entry point is scripts/sync_msdk/sync_msdk.py; this package holds the
implementation split into cohesive modules:

  gitutil    - thin wrappers around git/subprocess
  config     - import.yaml load/save and SDK-dir resolution
  manifest   - west manifest parsing and source-clone location
  patches    - Patch model, trailer parsing, dest_path ownership
  checkpoint - sync checkpoint markers and the import snapshot commit
  actions    - copy / remove / pin execution
  conflicts  - interactive cherry-pick conflict resolution
  commands   - the `update` and `sync` subcommands
"""
