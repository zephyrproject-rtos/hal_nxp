# RTC

## [2.2.0]

- New Features
  - Created new APIs for the RTC driver.
    - RTC_EnableSubsecCounter
    - RTC_GetSubsecValue

## [2.1.3]

- Bug Fixes
  - Fixed issue that RTC_GetWakeupCount may return wrong value.

## [2.1.2]

- Bug Fixes
  - MISRA C-2012 issue fixed: rule 10.1, 10.4 and 10.7.

## [2.1.1]

- Bug Fixes
  - MISRA C-2012 issue fixed: rule 10.3 and 11.9.

## [2.1.0]

- Bug Fixes
  - Created new APIs for the RTC driver.
    - RTC_EnableTimer
    - RTC_EnableWakeUpTimerInterruptFromDPD
    - RTC_EnableAlarmTimerInterruptFromDPD
    - RTC_EnableWakeupTimer
    - RTC_GetEnabledWakeupTimer
    - RTC_SetSecondsTimerMatch
    - RTC_GetSecondsTimerMatch
    - RTC_SetSecondsTimerCount
    - RTC_GetSecondsTimerCount
  - deprecated legacy APIs for the RTC driver.
    - RTC_StartTimer
    - RTC_StopTimer
    - RTC_EnableInterrupts
    - RTC_DisableInterrupts
    - RTC_GetEnabledInterrupts

## [2.0.0]

- Initial version.
