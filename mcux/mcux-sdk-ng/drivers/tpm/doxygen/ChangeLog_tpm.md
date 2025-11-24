# TPM

## [2.4.1]

- Improvements
  - Add Coverage Justification for uncovered code.

## [2.4.0]

- New Feature
  - Added while loop timeout for MOD CnV CnSC and SC register write sequence.
  - Change the return type from void to status_t for following API:
    - `TPM_DisableChannel`
    - `TPM_EnableChannel`
    - `TPM_SetupOutputCompare`
    - `TPM_SetTimerPeriod`
    - `TPM_StopTimer`

## [2.3.6]

- Bug Fixes
  - Fixed CERT INT30-C INT31-C issue for `TPM_SetupDualEdgeCapture`.

## [2.3.5]

- New Feature
  - Added IRQ handler entry for TPM2.

## [2.3.4]

- New Feature
  - Added common IRQ handler entry TPM_DriverIRQHandler.

## [2.3.3]

- Improvements
  - Conditionally compile interrupt handling code to solve the problem of using this driver on CPU cores that do not support interrupts.

## [2.3.2]

- Bug Fixes
  - Fixed ERR008085 TPM writing the TPMx_MOD or TPMx_CnV registers more than once may fail when the timer
    is disabled.

## [2.3.1]

- Bug Fixes
  - Fixed compilation error when macro FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL is 1.

## [2.3.0]

- Improvements
  - Create callback feature for TPM match and timer overflow interrupts.

## [2.2.4]

- Improvements
  - Add feature macros(FSL_FEATURE_TPM_HAS_GLOBAL_TIME_BASE_EN,
    FSL_FEATURE_TPM_HAS_GLOBAL_TIME_BASE_SYNC).

## [2.2.3]

- Improvements
  - Release peripheral from reset if necessary in init function.

## [2.2.2]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 10.4.

## [2.2.1]

- Bug Fixes
  - Fixed CCM issue by splitting function from TPM_SetupPwm() function to reduce function complexity.
  - Fixed violations of MISRA C-2012 rule 17.7.

## [2.2.0]

- Improvements
  - Added TPM_SetChannelPolarity to support select channel input/output polarity.
  - Added TPM_EnableChannelExtTrigger to support enable external trigger input to be used by channel.
  - Added TPM_CalculateCounterClkDiv to help calculates the counter clock prescaler.
  - Added TPM_GetChannelValue to support get TPM channel value.
  - Added new TPM configuration.
    - syncGlobalTimeBase
    - extTriggerPolarity
    - chnlPolarity
  - Added new PWM signal configuration.
    - secPauseLevel
- Bug Fixes
  - Fixed TPM_SetupPwm can't configure 0% combined PWM issues.

## [2.1.1]

- Improvements
  - Add feature macro for PWM pause level select feature.

## [2.1.0]

- Improvements
  - Added TPM_EnableChannel and TPM_DisableChannel APIs.
  - Added new PWM signal configuration.
    - pauseLevel - Support select output level when counter first enabled or paused.
    - enableComplementary - Support enable/disable generate complementary PWM signal.
    - deadTimeValue - Support deadtime insertion for each pair of channels in combined PWM mode.
- Bug Fixes
  - Fixed issues about channel MSnB:MSnA and ELSnB:ELSnA bit fields and CnV register change request acknowledgement.
    Writes to these bits are ignored when the interval between successive writes is less than the TPM clock period.

## [2.0.8]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 10.1, 10.4 ,10.7 and 14.4.

## [2.0.7]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 10.4 and 17.7.

## [2.0.6]

- Bug Fixes
  - Fixed Out-of-bounds issue.

## [2.0.5]

- Bug Fixes
  - Fixed MISRA-2012 rules.
    - Rule 10.6, 10.7

## [2.0.4]

- Bug Fixes
  - Fixed ERR050050 in functions TPM_SetupPwm/TPM_UpdatePwmDutycycle.
    When TPM was configured in EPWM mode as PS = 0, the compare event was missed on the first reload/overflow after
    writing 1 to the CnV register.

## [2.0.3]

- Bug Fixes
  - MISRA-2012 issue fixed.
    - Fixed rules: rule-12.1, rule-17.7, rule-16.3, rule-14.4, rule-1.3, rule-10.4, rule-10.3, rule-10.7,
      rule-10.1, rule-10.6, and rule-18.1.

## [2.0.2]

- Bug Fixes
  - Fixed issues in functions TPM_SetupPwm/TPM_UpdateChnlEdgeLevelSelect
    /TPM_SetupInputCapture/TPM_SetupOutputCompare/TPM_SetupDualEdgeCapture,
    wait acknowledgement when the channel is disabled.

## [2.0.1]

- Bug Fixes
  - Fixed TPM_UpdateChnIEdgeLevelSelect ACK wait issue.
  - Fixed the issue that TPM_SetupdualEdgeCapture could not set FILTER register.
  - Fixed TPM_UpdateChnEdgeLevelSelect ACK wait issue.

## [2.0.0]

- Initial version.
