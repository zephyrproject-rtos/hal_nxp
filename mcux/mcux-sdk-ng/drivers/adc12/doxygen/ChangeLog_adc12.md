# ADC12

## [2.0.8]

- Bug Fixes
  - Fix build warning when `FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL` is defined as 1.

## [2.0.7]

- Improvements
  - Change the method for judging the end of calibration. Previously, it
    was judged based on the COCO bit of the SC1 register. After the update,
    it is judged based on the CAL bit of the SC3 register. In some cases,
    SC1[COCO] was already set to 1 before calibration was performed, which
    caused calibration to fail.

## [2.0.6]

- Improvements
  - Removed useless comments of ADC12_DoAutoCalibration() function.

## [2.0.5]

- Bug Fixes
  - Fixed the violations of MISRA C-2012 rule 10.4.

## [2.0.4]

- Bug Fixes
  - Fixed the violations of MISRA C-2012 rules:
    - Rule 4.7 10.1 10.3 10.4 10.8 12.2 16.4 17.7

## [2.0.3]

- Improvements
  - Used conversion control feature macro instead of that in IO map.

## [2.0.2]

- Bug Fixes
  - Set ADC clock frequency as half of the maximum value for calibration.

## [2.0.1]

- New Features
  - Added a feature to control enablement of DMA.

## [2.0.0]

- Initial version.
