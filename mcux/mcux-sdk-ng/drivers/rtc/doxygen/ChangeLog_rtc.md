# RTC

## [2.4.0]

- New features
  - Add support for RTC clock output.
  - Add support for RTC time seconds interrupt configuration.

## [2.3.3]

- Bug Fixes
  - Fix RTC_GetDatetime function validating datetime issue.

## [2.3.2]

- Improvements
  - Handle errata 010716: Disable the counter before setting alarm register and then reenable the counter.

## [2.3.1]

- Bug Fixes
  - Fixed CERT INT31-C violations.

## [2.3.0]

- Improvements
  - Added API RTC_EnableLPOClock to set 1kHz LPO clock.
  - Added API RTC_EnableCrystalClock to replace API RTC_SetClockSource.

## [2.2.2]

- Improvements
  - Refine _rtc_interrupt_enable order.

## [2.2.1]

- Bug Fixes
  - Fixed the issue of Pa082 warning.
  - Fixed the issue of bit field mask checking.
  - Fixed the issue of hard code in RTC_Init.

## [2.2.0]

- Bug Fixes
  - Fixed MISRA C-2012 issue.
    - Fixed rule contain: rule-17.7, rule-14.4, rule-10.4, rule-10.7, rule-10.1, rule-10.3.
  - Fixed central repository code formatting issue.
- Improvements
  - Added an API for enabling wakeup pin.

## [2.1.0]

- Improvements
  - Added feature macro check for many features.

## [2.0.0]

- Initial version.
