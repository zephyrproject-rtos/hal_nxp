# LPADC

## [2.9.4]

- Improvements
  - Update LPADC_GetDefaultConfig, change default conversionAverageMode value to:
    kLPADC_ConversionAverage128 for 3 bit width.
    kLPADC_ConversionAverage1024 for 4 bit width.

## [2.9.3]

- Improvements
  - Add timeout for while loop code.

## [2.9.2]

- Improvements
  - Fixed CERT-C issues.

## [2.9.1]

- Bug Fixes
  - Fixed incorrect channel B FIFO selection logic.

## [2.9.0]

- Bug Fixes
  - Add code to handle the case where GCC[GAIN_CAL] is a signed number.
  - Split LPADC_FinishAutoCalibration function into two functions.
  - Improved LPADC driver.

## [2.8.4]

- Bug Fixes
  - Remove function 'LPADC_SetOffsetValue' assert statement, this statement may cause runtime errors in existing code.

## [2.8.3]

- Bug Fixes
  - Fixed SDK lpadc driver examples compile issue, move condition 'commandId < ADC_CV_COUNT'
    to a more appropriate location.

## [2.8.2]

- Bug Fixes
  - Fixed the violations of MISRA C-2012 rule 18.1, 10.3, 10.1 and 10.4.

## [2.8.1]

- Bug Fixes
  - Fixed LPADC sample mode enum name mistake.

## [2.8.0]

- Improvements
  - Release peripheral from reset if necessary in init function.
- Bug Fixes
  - Fixed function LPADC_GetConvResult() issue.
  - Fixed function LPADC_SetConvCommandConfig() bugs.

## [2.7.2]

- Improvements
  - Use feature macros instead of header file macros.
- Bug Fixes
  - Fixed the violations of MISRA C-2012 rule 10.1, 10.3, 10.4 and 14.3.

## [2.7.1]

- Improvements
  - Corrected descriptions of several functions.
  - Improved function LPADC_GetOffsetValue and LPADC_SetOffsetValue.
  - Revert changes of feature macros for lpadc.
  - Use feature macros instead of header file macros.
- Bug Fixes
  - Fixed the violations of MISRA C-2012 rule 10.8.
  - Fixed the violations of MISRA C-2012 rule 10.1, 10.3, 10.4 and 14.3.

## [2.7.0]

- Improvements
  - Added supports of CFG2 register.
  - Removed some useless macros.

## [2.6.2]

- Bug Fixes
  - Fixed the violations of MISRA C-2012 rules.
  - Fixed LPADC driver code compile error issue.

## [2.6.1]

- Improvements
  - Updated the use of macros in the driver code.

## [2.6.0]

- Improvements
  - Added the API LPADC_SetOffset12BitValue() to configure 12bit ADC conversion offset trim value manually.
  - Added the API LPADC_SetOffset16BitValue() to configure 16bit ADC conversion offset trim value manually.
  - Added API to set offset calibration mode.
  - Added configuration of alternate channel.
  - Updated auto calibration API and added calibration value conversion API.
- New feature
  - Added API LPADC_EnableHardwareTriggerCommandSelection() to enable trigger commands controlled by ADC_ETC.
  - Updated LPADC_DoAutoCalibration() to allow doing something else before the ADC inititialization to be totally complete. Enhance initialization duration time of the ADC.
  - Added two new APIs to get/set calibration value.

## [2.5.2]

- Improvements
  - Added while loop, LPADC_GetConvResult() will return only when the FIFO will not be empty.

## [2.5.1]

- Bug Fixes
  - Fixed some typos in Lpadc driver comments.

## [2.5.0]

- Improvements
  - Added missing items to enable trigger interrupts.

## [2.4.0]

- New features
  - Added APIs to get/clear trigger status flags.

## [2.3.0]

- Improvements
  - Removed LPADC_MeasureTemperature() function for the LPADC supports different
    temperature sensor calculation equations.

## [2.2.1]

- Improvements
  - Optimized LPADC_MeasureTemperature() function to support the specific series
    with flash solidified calibration value.
  - Clean doxygen warnings.
- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 10.3, rule 10.8 and rule 17.7.

## [2.2.0]

- New Feature
  - Added API LPADC_MeasureTemperature() to get correct temperature from the internal sensor.
- Improvements
  - Separated lpadc_conversion_resolution_mode_t with related feature macro.
- Bug Fixes
  - Fixed the violations of MISRA C-2012 rules:
    - Rule 10.3, 10.4, 10.6, 10.7 and 17.7.

## [2.1.1]

- Improvements
  - Updated the gain calibration formula.
  - Used feature to segregate the new item kLPADC_TriggerPriorityPreemptSubsequently.

## [2.1.0]

- New Features
  - Added the API LPADC_SetOffsetValue() to support configure offset trim value manually.
  - Added the API LPADC_DoOffsetCalibration() to do offset calibration independently.
- Improvements
  - Improved the usage of macros and removed invalid macros.

## [2.0.2]

- Improvements
  - Added support for platforms with 2 FIFOs and different calibration measures.

## [2.0.1]

- Bug Fixes
  - Ensured the API LPADC_SetConvCommandConfig configure related registers correctly.

## [2.0.0]

- Initial version.
