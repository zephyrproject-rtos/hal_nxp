# WDOG8

## [2.0.2]

- Bug Fixes
  - Fixed CERT INT31-C violations on bool-to-uint8_t casts in WDOG8_Init and
    on the bitwise complement in WDOG8_Disable.

## [2.0.1]

- Bug Fixes
  - MISRA C-2012 issue fixed: rule 10.3, 10.4, 10.6, 10.7 and 11.9.
  - Fixed the issue of the inseparable process interrupted by other interrupt source.
    - WDOG8_Refresh

## [2.0.0]

- Initial version.
