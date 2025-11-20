# QTMR

## [2.3.0]

- Improvements
  - Support for platforms which QTMR registers are 32-bit.

## [2.2.2]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rules: 10.1, 10.8.

## [2.2.1]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rules: 10.1, 10.8.

## [2.2.0]

- Improvements
  - Added API QTMR_SetPwmOutputToIdle to set the generated pwm signal to the configured idle value.
  - Added API QTMR_GetPwmOutputStatus to return the output status of the generated pwm signal.
  - Added API QTMR_GetPwmChannelStatus to return the channel dutycycle value.
  - Added API QTMR_SetPwmClockMode to set clock mode change peripheral clock frequency.
- Bug Fixes
  - Fixed the issue that pwm duty cycle could not be 0 and 100.

## [2.1.0]

- Bug Fixes
  - Fixed the issue QTMR_SetTimerPeriod needs to decrement down count by 1, and added new APIs to configure the LOAD register, COMP register.

## [2.0.2]

- Bug Fixes
  - Fixed the issue introduced by previous code correction for improving the output signal accuracy.

## [2.0.1]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rules: 10.1, 10.3, 11.5, 11.9.
- Improvements
  - Improved the output signal accuracy.

## [2.0.0]

- Initial version.
