# MMDC

## [2.1.4]

- Bug Fixes
  - Changed the MMDC_DeviceInit() calling order that a change to move the MMDC_DeviceInit call after all of the calibrations and
    before the fine tuning within the MMDC_Init function.

## [2.1.3]

- Bug Fixes
  - Fixed Coverity issues.

## [2.1.2]

- Improvements
  - Added new feature for MARCR register.
  - Added kMMDC_DisableDerate option for LPDDR2.

## [2.1.1]

- Improvements
  - Improved the MMDC clock gate control.
  - Added MMDC change freq API prototype.

## [2.1.0]

- Improvements
  - Improved MMDC initialization flow, use single MMDC_Init to do MMDC.
    initialization, timing configuration, device calibration, and initialization.
  - Removed MMDC_DeviceCalibration, add separate
    MMDC_ReadDQSGatingCalibration,
    MMDC_WriteLevelingCalibration,
    MMDC_WriteCalibration,
    MMDC_ReadCalibration and MMDC_DoFineTuning.
  - Added uint8_t targetCS for MMDC_DeviceInit to handle CS0/CS1.
  - Changed return value bool to status_t.

## [2.0.0]

- Initial version.
