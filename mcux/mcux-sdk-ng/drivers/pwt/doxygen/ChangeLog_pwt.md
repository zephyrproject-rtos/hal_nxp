# PWT

## [2.0.3]

- Improvements
  - Added support for 32-bit PWT register width (e.g. MCXC353) via FSL_FEATURE_PWT_REG_WIDTH feature macro.
- New Features
  - Added TGL (input toggle) status flag support.
  - Added PWT_GetInputLevel() API to read the PWTIN level when overflow occurs.

## [2.0.2]

- Bug Fixes
  - Fixed CERT INT31-C violations.

## [2.0.1]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rules: 10.8, 10.3, 10.6.

## [2.0.0]

- Initial version.
