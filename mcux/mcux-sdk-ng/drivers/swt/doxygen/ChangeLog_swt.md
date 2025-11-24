# SWT

## [2.1.1]

- Improvements
  - Handle errata ERR052226: Toggling watchdog enable may cause unexpected timeout in some
    boundary conditions. Update SWT_SetTimeoutValue() update SWT with the watchdog keys to restart the counter value before setting a new timeout value.


## [2.1.0]

- Bug Fixes
  - Fixed CERT-C violations: CERT INT31-C, CERT INT30-C
- New Features
  - Added SWT_Refresh() API to automatically select a correct refresh service mode.

## [2.0.0]

- Initial version.
