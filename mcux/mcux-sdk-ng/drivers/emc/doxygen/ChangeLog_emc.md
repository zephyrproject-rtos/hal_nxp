# EMC

## [2.0.4]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 10.1, 10.3, 10.4, 10.8, 11.9,
    14.2, 14.3, 14.4.

## [2.0.3]

- Improvements
  - Used SDK_DelayAtLeastUs instead of for loop during the dynamic memory
    initialization.

## [2.0.3]

- Improvements
  - Replaced deprecated enumerator CLOCK_GetFreq(kCLOCK_EMC) with
    CLOCK_GetEmcClkFreq().

## [2.0.2]

- New Features
  - Added control macro to enable/disable the CLOCK code in current driver.

## [2.0.1]

- Improvements
  - Added const for two BASE values.

## [2.0.0]

- Initial version.
