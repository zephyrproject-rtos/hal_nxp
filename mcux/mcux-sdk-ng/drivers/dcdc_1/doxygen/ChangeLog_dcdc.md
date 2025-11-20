# DCDC

## [2.3.0]

- Improvements
  - REG3[MISC_DELAY_TIMING], REG2[LOOPCTRL_DC_R], and REG2[LOOPCTRL_DC_C] are reserved in the latest RM,
    deleted corresponding functions.

## [2.2.1]

- Improvements
  - Fixed the doxygen warning.

## [2.2.0]

- New Features

  - Added supports for i.MXRT1170 series.

- Bug Fixes

  - Fixed the warning that the DCDC_ConvertByteArrayToWord function defined but not used.

- Improvements

  - Updated rcscale to reduce the ripple when booting into DCM.

## [2.1.0]

- Improvements
  - Divided the DCDC_AdjustTargetVoltage() into two APIs for two different modes.
- Bug Fixes
  - Fixed the violations of MISRA C-2012 rules:
    - Rule 10.1, 10.4, 16.4, 17.7.

## [2.0.0]

- Initial version.
