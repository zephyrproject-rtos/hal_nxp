# SCTIMER

## [2.5.1]

- Bug Fixes
  - Fixed bug in SCTIMER_SetupCaptureAction: When kSCTIMER_Counter_H is selected, events 12-15 and
    capture registers 12-15 CAPn_H field can't be used.

## [2.5.0]

- Improvements
  - Add SCTIMER_GetCaptureValue API to get capture value in capture registers.

## [2.4.9]

- Improvements
  - Supported platforms which don't have system level SCTIMER reset.

## [2.4.8]

- Bug Fixes
  - Fixed the issue that the SCTIMER_UpdatePwmDutycycle() can't writes MATCH_H bit and RELOADn_H.

## [2.4.7]

- Bug Fixes
  - Fixed the issue that the SCTIMER_UpdatePwmDutycycle() can't configure 100% duty cycle PWM.

## [2.4.6]

- Bug Fixes
  - Fixed the issue where the H register was not written as a word along with the L register.
  - Fixed the issue that the SCTIMER_SetCOUNTValue() is not configured with high 16 bits in unify mode.

## [2.4.5]

- Bug Fixes
  - Fix SCT_EV_STATE_STATEMSKn macro build error.

## [2.4.4]

- Bug Fixes
  - Fix MISRA C-2012 issue 10.8.

## [2.4.3]

- Bug Fixes
  - Fixed the wrong way of writing CAPCTRL and REGMODE registers in SCTIMER_SetupCaptureAction.

## [2.4.2]

- Bug Fixes
  - Fixed SCTIMER_SetupPwm 100% duty cycle issue.

## [2.4.1]

- Bug Fixes
  - Fixed the issue that MATCHn_H bit and RELOADn_H bit could not be written.

## [2.4.0]

## [2.3.0]

- Bug Fixes
  - Fixed the potential overflow issue of pulseperiod variable in SCTIMER_SetupPwm/SCTIMER_UpdatePwmDutycycle API.
  - Fixed the issue of SCTIMER_CreateAndScheduleEvent API does not correctly work with 32 bit unified counter.
  - Fixed the issue of position of clear counter operation in SCTIMER_Init API.
- Improvements
  - Update SCTIMER_SetupPwm/SCTIMER_UpdatePwmDutycycle to support generate 0% and 100% PWM signal.
  - Add SCTIMER_SetupEventActiveDirection API to configure event activity direction.
  - Update SCTIMER_StartTimer/SCTIMER_StopTimer API to support start/stop low counter and high counter at the same time.
  - Add SCTIMER_SetCounterState/SCTIMER_GetCounterState API to write/read counter current state value.
  - Update APIs to make it meaningful.
    - SCTIMER_SetEventInState
    - SCTIMER_ClearEventInState
    - SCTIMER_GetEventInState

## [2.2.0]

- Improvements
  - Updated for 16-bit register access.

## [2.1.3]

- Bug Fixes
  - Fixed the issue of uninitialized variables in SCTIMER_SetupPwm.
  - Fixed the issue that the Low 16-bit and high 16-bit work independently in SCTIMER driver.
- Improvements
  - Added an enumerable macro of unify counter for user.
    - kSCTIMER_Counter_U
  - Created new APIs for the RTC driver.
    - SCTIMER_SetupStateLdMethodAction
    - SCTIMER_SetupNextStateActionwithLdMethod
    - SCTIMER_SetCOUNTValue
    - SCTIMER_GetCOUNTValue
    - SCTIMER_SetEventInState
    - SCTIMER_ClearEventInState
    - SCTIMER_GetEventInState
  - Deprecated legacy APIs for the RTC driver.
    - SCTIMER_SetupNextStateAction

## [2.1.2]

- Bug Fixes
  - MISRA C-2012 issue fixed: rule 10.3, 10.4, 10.6, 10.7, 11.9, 14.2 and 15.5.

## [2.1.1]

- Improvements
  - Updated the register and macro names to align with the header of devices.

## [2.1.0]

- Bug Fixes
  - Fixed issue where SCT application level Interrupt handler function is occupied by SCT driver.
  - Fixed issue where wrong value for INSYNC field inside SCTIMER_Init function.
  - Fixed issue to change Default value for INSYNC field inside SCTIMER_GetDefaultConfig.

## [2.0.1]

- New Features
  - Added control macro to enable/disable the RESET and CLOCK code in current driver.

## [2.0.0]

- Initial version.
