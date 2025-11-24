# LLWU

## [2.0.5]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 10.3.
  - Fixed the issue that function LLWU_SetExternalWakeupPinMode() does not work on
    32-bit width platforms.

## [2.0.4]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 10.3, 10.4, 10.6, 10.7, 11.3.
  - Fixed issue that LLWU_ClearExternalWakeupPinFlag may clear other filter
    flags by mistake on platforms with 32-bit LLWU registers.

## [2.0.3]

- Bug Fixes
  - Fixed MISRA-2012 rules.
    - Rule 16.4.

## [2.0.2]

- Improvements
  - Corrected driver function LLWU_SetResetPinMode parameter name.
- Bug Fixes
  - Fixed MISRA-2012 rules.
    - Rule 14.4, 10.8, 10.4, 10.3.

## [2.0.1]

- Other Changes
  - Updates for KL8x.

## [2.0.0]

- Initial version.
