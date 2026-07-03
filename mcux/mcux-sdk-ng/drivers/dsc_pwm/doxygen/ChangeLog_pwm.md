# eFlexPWM

## [2.2.1]

- Bug Fixes
  - Fixed PWM_SetupFaultProtectionConfig() using wrong macro PWM_FCTRL_FSAFE instead of PWM_FCTRL_FIE for the
    fault interrupt enable field.
  - Fixed PWM_SetupFaultProtectionConfig() using PWM_FFILT_GSTR for both FILT_CNT and FILT_PER fields instead of
    PWM_FFILT_FILT_CNT and PWM_FFILT_FILT_PER.
  - Fixed PWM_SetupOutputConfig() not programming TCTRL[OUT_TRIG_EN] bits from bVal0TriggerEnable ~
    bVal5TriggerEnable; previous code overwrote TCTRL multiple times and lost the OUT_TRIG_EN value.
  - Fixed PWM_SetupOutputConfig() not updating MASK register on devices without MASK[UPDATE_MASK] bitfield.
  - Fixed PWM_SetupSMConfig() passing the address of eStrBusClock (&psConfig->eStrBusClock) instead of its value to
    PWM_MCTRL2_STRETCH_CNT_PRSC(), and using |= which preserved stale prescaler bits; corrected to RMW.
  - Fixed PWM_SetupDeadtimeConfig() leaving CTRL[SPLIT] set when switching away from
    kPWM_IndependentWithSplitDoubleSwitchPwm mode.

## [2.2.0]

- New Features
- Supported capture PWM input filter.
- Supported different PWM deadtime count register width.
  - Bug Fixes
- Fixed wrong pwm_sm_pwm_out_t enum order issue.

## [2.1.1]

- Bug Fixes
- Fixed build error when soc not support Capture A/B features.

## [2.1.0]

- Improvements
- Supported MC56F80xxx.

## [2.0.2]

- Bug Fixes
- Fixed clear status flags API doesn't work issue.

## [2.0.1]

- Improvements
- Supported MC56F82xxx and MC56F84xxx .
  - Bug Fixes
- Fixed violations of the MISRA C-2012 rules.

## [2.0.0]

- Initial version.
