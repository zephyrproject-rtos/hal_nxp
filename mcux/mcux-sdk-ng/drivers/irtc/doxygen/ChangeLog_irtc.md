# IRTC

## [2.3.3]

- Bug Fixes
  - Fix CERT INT31-C issue.

## [2.3.2]

- Bug Fixes
  - Fixed API IRTC_GetDatetime read YEARMON, DAYS, HOURMIN, SECONDS registers issue.

## [2.3.1]

- Bug Fixes
  - Fixed MISRA C-2012 issue 10.4.

## [2.3.0]

- New Feature
  - Supported platforms with multiple IRTC instances.

## [2.2.4]

- Bug Fixes
  - Fixed MISRA C-2012 issue 10.1, 10.3, 10.4, 10.7, 12.2.

## [2.2.3]

- Bug Fixes
  - Updated undefined macro names by available ones.

## [2.2.2]

- Bug Fixes
  - Fixed MISRA C-2012 issue 10.3.

## [2.2.1]

- Bug Fixes
  - Fixed MISRA issues.

## [2.2.0]

- New Feature
  - Add new APIs for CLK_SEL and CLKO to select RTC clock and enable/disable output to peripherals.
  - Supported platforms without tamper feature.

## [2.1.3]

- Bug Fixes
  - Fixed MISRA C-2012 issue 10.1 and 10.4.

## [2.1.2]

- Bug Fixes
  - Fixed kIRTC_TamperFlag flag can't be cleared issue.

## [2.1.1]

- Bug Fixes
  - MISRA C-2012 issue check.
    - Fixed rules, containing: rule-10.1, rule-10.3, rule-10.4.

## [2.1.0]

- Bug Fixes
  - Fixed incorrect leap year check in IRTC_CheckDatetimeFormat.
- New Feature
  - Added new APIs for new feature FSL_FEATURE_RTC_HAS_SUBSYSTEM.
  - Added new APIs for TAMPER, TAMPER QUEUE status get and clear.
  - Added new API to enable/disable 32 kHz RTC OSC clock during RTC register write.
  - Updated IRTC_SetTamperParams to support new feature FSL_FEATURE_RTC_HAS_FILTER23_CFG
  - Updated irtc_config_t to exclude member wakeupSelect for new feature FSL_FEATURE_RTC_HAS_NO_CTRL2_WAKEUP_MODE.

## [2.0.2]

- Bug Fixes
  - MISRA C-2012 issue check.
    - Fixed rules, containing: rule-10.1, rule-10.3, rule-10.4, rule-10.6, rule-10.8, rule-11.9, rule-12.2,
      rule-15.5, rule-16.4, rule-17.7.

## [2.0.1]

- Bug Fixes
  - Fixed the issue of hard code in IRTC_Init.

## [2.0.0]

- Initial version.
