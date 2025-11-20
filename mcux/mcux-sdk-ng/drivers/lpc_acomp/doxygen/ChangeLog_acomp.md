# LPC_ACOMP

## [2.1.0]

- Bug Fixes
  - Fixed one wrong enum value for the hysteresis.
  - Fixed the violations of MISRA C-2012 rules:
    - Rule 10.1, 17.7.

## [2.0.2]

- Bug Fixes
  - Fixed the out-of-bounds error of Coverity caused by missing an assert sentence to avoid
    the return value of ACOMP_GetInstance() exceeding the array bounds.

## [2.0.1]

- New Features
  - Added a control macro to enable/disable the CLOCK code in current driver.

## [2.0.0]

- Initial version.
