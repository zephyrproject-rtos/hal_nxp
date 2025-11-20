# PLU

## [2.2.1]

- Bug Fixes
  - Fixed MISRA C-2012 rule 10.3 and rule 17.7.

## [2.2.0]

- Bug Fixes
  - Fixed wrong parameter of the PLU_EnableWakeIntRequest function.

## [2.1.0]

- New Features
  - Added 4 new APIs to support Niobe4's wake-up/interrupt control feature, including PLU_GetDefaultWakeIntConfig()
    PLU_EnableWakeIntRequest(), PLU_LatchInterrupt() and PLU_ClearLatchedInterrupt().
- Other Changes
  - Changed the register name LUT_INP to LUT_INP_MUX due to register map update.

## [2.0.1]

- New Features
  - Added control macro to enable/disable the RESET and CLOCK code in current driver.

## [2.0.0]

- Initial version.
