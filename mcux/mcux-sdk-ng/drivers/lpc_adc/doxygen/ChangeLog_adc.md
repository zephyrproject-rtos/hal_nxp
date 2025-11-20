# LPC_ADC

## [2.6.0]

- New Features
  - Added new feature macro to distinguish whether the GPADC_CTRL0_GPADC_TSAMP control bit is on the device.
  - Added new variable extendSampleTimeNumber to indicate the ADC extend sample time.
- Bugfix
  - Fixed the bug that incorrectly sets the PASS_ENABLE bit based on the sample time setting.

## [2.5.3]

- Improvements
  - Release peripheral from reset if necessary in init function.

## [2.5.2]

- Improvements
  - Integrated different sequence's sample time numbers into one variable.
- Bug Fixes
  - Fixed violation of MISRA C-2012 rule 20.9 .

## [2.5.1]

- Bug Fixes
  - Fixed ADC conversion sequence priority misconfiguration issue in the ADC_SetConvSeqAHighPriority() and ADC_SetConvSeqBHighPriority() APIs.
- Improvements
  - Supported configuration ADC conversion sequence sampling time.

## [2.5.0]

- Improvements
  - Add missing parameter tag of ADC_DoOffsetCalibration().
- Bug Fixes
  - Removed a duplicated API with typo in name: ADC_EnableShresholdCompareInterrupt().

## [2.4.1]

- Bug Fixes
  - Enabled self-calibration after clock divider be changed to make sure the frequency update be taken.

## [2.4.0]

- New Features
  - Added new API ADC_DoOffsetCalibration() which supports a specific operation frequency.
- Other Changes
  - Marked the ADC_DoSelfCalibration(ADC_Type *base) as deprecated.
- Bug Fixes
  - Fixed the violations of MISRA C-2012 rules:
    - Rule 10.1 10.3 10.4 10.7 10.8 17.7.

## [2.3.2]

- Improvements
  - Added delay after enabling using the ADC GPADC_CTRL0 LDO_POWER_EN bit for JN5189/QN9090.
- New Features
  - Added support for platforms which have only one ADC sequence control/result register.

## [2.3.1]

- Bug Fixes
  - Avoided writing ADC STARTUP register in ADC_Init().
  - Fixed Coverity zero divider error in ADC_DoSelfCalibration().

## [2.3.0]

- Improvements
  - Updated "ADC_Init()""ADC_GetChannelConversionResult()" API and "adc_resolution_t" structure to match QN9090.
  - Added "ADC_EnableTemperatureSensor" API.

## [2.2.1]

- Improvements
  - Added a brief delay in uSec after ADC calibration start.

## [2.2.0]

- Improvements
  - Updated "ADC_DoSelfCalibration" API and "adc_config_t" structure to match LPC845.

## [2.1.0]

- Improvements
  - Renamed "ADC_EnableShresholdCompareInterrupt" to "ADC_EnableThresholdCompareInterrupt".

## [2.0.0]

- Initial version.
