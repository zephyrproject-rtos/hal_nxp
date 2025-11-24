# FTM

## [2.7.3]

- Bug Fixes
  - Fixed violations of the CERT INT30-C INT31-C.

## [2.7.2]

- Improvements
  - Add API `FTM_ERRATA_010856` for ERR010856 workaround.

## [2.7.1]

- Bug Fixes
  - Added function macro when accsee FLTCTRL register FSTATE bit to prevent access nonexistent register.
  - Added function macro to prevent access nonexistent FTM channel for API FTM_ConfigSinglePWM()
    and FTM_ConfigCombinePWM().

## [2.7.0]

- Improvements
  - Support period dithering and edge dithering feature with new APIs:
    - FTM_SetPeriodDithering()
    - FTM_SetEdgeDithering()
  - Support get channel n output and input state feature with new APIs:
    - FTM_GetChannelOutputState()
    - FTM_GetChannelInputState()
  - Support configure deadtime for specific combined channel pair with new API:
    - FTM_SetPairDeadTime()
  - Support filter clock prescale, fault output state.
  - Support new APIs to configure PWM and Modified Combine PWM:
    - FTM_ConfigSinglePWM()
    - FTM_ConfigCombinePWM()
  - Support new API to configure channel software output control:
    - FTM_SetSoftwareOutputCtrl()
    - FTM_GetSoftwareOutputValue()
    - FTM_GetSoftwareOutputEnable()
  - Support new API to update FTM counter initial value, modulo value and chanle value:
    - FTM_SetInitialModuloValue()
    - FTM_SetChannelValue()

## [2.6.1]

- Improvements
  - Release peripheral from reset if necessary in init function.

## [2.6.0]

- Improvements
  - Added support to half and full cycle reload feature with new APIs:
    - FTM_SetLdok()
    - FTM_SetHalfCycPeriod()
    - FTM_LoadFreq()
- Bug Fixes
  - Set the HWRSTCNT and SWRSTCNT bits to optional at initialization.

## [2.5.0]

- Improvements
  - Added FTM_CalculateCounterClkDiv to help calculates the counter clock prescaler.
  - Modify FTM_UpdatePwmDutycycle API to make it return pwm duty cycles status.
- Bug Fixes
  - Fixed TPM_SetupPwm can't configure 100% center align combined PWM issues.

## [2.4.1]

- Bug Fixes
  - Added function macro to determine if FTM instance has only basic features, to prevent access
    to protected register bits.

## [2.4.0]

- Improvements
  - Added CNTIN register initialization in FTM_SetTimerPeriod API.
  - Added a new API to read the captured value of a FTM channel configured in capture mode:
    - FTM_GetInputCaptureValue()

## [2.3.0]

- Improvements
  - Added support of EdgeAligned/CenterAligned/Asymmetrical combine PWM mode in FTM_SetupPWM()
    and FTM_SetupPwmMode() APIs.
  - Remove kFTM_ComplementaryPwm from support PWM mode, and add new parameter "enableComplementary"
    in structure ftm_chnl_pwm_signal_param_t.
  - Rename FTM_SetupFault() API to FTM_SetupFaultInput() to avoid ambiguity.

## [2.2.3]

- Bug Fixes
  - MISRA C-2012 issue fixed: rule 14.4 and 17.7.

## [2.2.2]

- Bug Fixes
  - Fixed the issue that when FTM instance has only TPM features cannot be initialized
    by FTM_Init() function. By added function macro to assert FTM is TPM only instance.

## [2.2.1]

- Bug Fixes
  - MISRA C-2012 issue fixed: rule 10.1, 10.3, 10.4, 10.6, 10.7 and 11.9.

## [2.2.0]

- Bug Fixes
  - Fixed the issue of comparison between signed and unsigned integer expressions.
- Improvements
  - Added support of complementary mode in FTM_SetupPWM() and FTM_SetupPwmMode() APIs.
  - Added new parameter "enableDeadtime" in structure ftm_chnl_pwm_signal_param_t.

## [2.1.1]

- Bug Fixes
  - Fixed COVERITY integer handing issue where the right operand of a left bit shift statement
    should not be a negative value. This appears in FTM_SetReloadPoints().

## [2.1.0]

- Improvements

  - Added a new API FTM_SetupPwmMode() to allow the user to set the channel match value in units
    of timer ticks. New configure structure called ftm_chnl_pwm_config_param_t was added
    to configure the channel's PWM parameters. This API is similar with FTM_SetupPwm() API,
    but the new API will not set the timer period(MOD value), it will be useful for users to
    set the PWM parameters without changing the timer period.

- Bug Fixes

  - Added feature macro to enable/disable the external trigger source configuration.

## [2.0.4]

- Improvements
  - Added a new API to enable DMA transfer:
    - FTM_EnableDmaTransfer()

## [2.0.3]

- Bug Fixes
  - Updated the FTM driver to enable fault input after configuring polarity.

## [2.0.2]

- Improvements
  - Added support to Quad Decoder feature with new APIs:
    - FTM_GetQuadDecoderFlags()
    - FTM_SetQuadDecoderModuloValue()
    - FTM_GetQuadDecoderCounterValue()
    - FTM_ClearQuadDecoderCounterValue()

## [2.0.1]

- Bug Fixes
  - Updated the FTM driver to fix write to ELSA and ELSB bits.
  - FTM combine mode: set the COMBINE bit before writing to CnV register.

## [2.0.0]

- Initial version.
