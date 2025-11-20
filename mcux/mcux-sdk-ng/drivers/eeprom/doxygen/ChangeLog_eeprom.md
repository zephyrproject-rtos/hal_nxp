# EEPROM

## [2.1.3]

- Bug Fixes
  - Corrected EEPROM clock divider(CLKDIV) calculation equation.

## [2.1.2]

- Bug Fixes
  - MISRA C-2012 issue fixed: rule 10.3, 10.4, and 14.4.

## [2.1.1]

- Bug Fixes
  - Fixed Coverity BAD_SHIFT issues.
  - Fixed Coverity MISRA issues regarding rule 10.1/10.3/10.4/10.8/17.7.
  - Updated parameter type from int into uint32_t for EEPROM_Write().

## [2.1.0]

- New Features
  - Added a new API to support write/read EEPROM and data check on LPC8N04.

## [2.0.0]

- Initial version.
