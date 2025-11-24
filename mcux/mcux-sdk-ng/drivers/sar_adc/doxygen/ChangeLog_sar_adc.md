# SAR_ADC

## [2.3.0]

- New Feature
  - Added new feature macro a for compatibility with ADCs on some platforms
    where some instances do not support group3.

## [2.2.0]

- New Feature
  - Added new features to compatible with new platforms.

## [2.1.1]

- Improvement
  - Change ADC sample rate phase duration default value from 0x08 to 0x14.

## [2.1.0]

- New Feature
  - Added ADC_StopConvChain function to support stop scan in normal conversion scan operation mode.

## [2.0.3]

- Bug Fixes
  - Fixed the array name usage error in function ADC_GetInstance.

## [2.0.2]

- Bug Fixes
  - Fixed MISRA issues.

## [2.0.1]

- Bug Fixes
  - Fixed the bug that when calling function ADC_EnableWdgThresholdInt() in function ADC_SetAnalogWdgConfig(), the parameter was passed incorrectly.

## [2.0.0]

- Initial version.
