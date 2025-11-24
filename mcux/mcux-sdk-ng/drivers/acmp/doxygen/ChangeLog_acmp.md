# ACMP

## [2.4.0]

- New Feature
  - Supported the plateforms which don't have continuous mode.

## [2.3.0]

- Improvements
  - Expose C0 register FILTER_CNT bitfield and FPR bitfield to the user.

## [2.2.0]

- Improvements
  - Updated feature macros for roundrobin mode, window mode, filter mode, and 3V domain removes.

## [2.1.0]

- New Feature
  - Supported the plateforms which don't have hysteresis mode.

## [2.0.6]

- Bug Fixes
  - Fixed the wrong comments, the DAC value should range from 0 to 255.

## [2.0.5]

- Bug Fixes
  - Fixed the out-of-bounds error of Coverity caused by missing an assert sentence to avoid
    the return value of ACMP_GetInstance() exceeding the array bounds.
  - Fixed the violations of MISRA C-2012 rules:
    - Rule 10.1, 14.4, 16.4, 17.7.

## [2.0.4]

- Bug Fixes
  - Avoided changing w1c bit in ACMP_SetRoundRobinPreState().

## [2.0.3]

- New Features
  - Added feature functions for usage of different power domains(1.8 V and 3 V). These functions are first enabled in ULP1. They are about:
    - ACMP_EnableLinkToDAC()
    - ACMP_SetDiscreteModeConfig()
    - ACMP_GetDefaultDiscreteModeConfig()

## [2.0.2]

- Other Changes
  - Changed coding style of peripheral base address from "s_acmpBases" to "s_acmpBase".

## [2.0.1]

- Bug Fixes
  - Fixed bug regarding the function "ACMP_SetRoundRobinConfig". It will not continue execution but returns directly
    after disabling round robin mode.
