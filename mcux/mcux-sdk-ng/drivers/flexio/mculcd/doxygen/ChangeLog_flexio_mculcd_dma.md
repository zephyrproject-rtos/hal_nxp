# FLEXIO_MCU_LCD_DMA

## [2.0.6]

- New Features
  - Supported passing an extra user defined parameter to GPIO functions to control the
    RDWR pin signal.

## [2.0.5]

- New Features
  - Supported transmit only data without command.

## [2.0.4]

- Bug Fixes
  - Fixed MISRA 10.4 issues.

## [2.0.3]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 10.1, 10.3, 10.4, 10.6, 14.4, 17.7.

## [2.0.2]

- Improvements
  - Unified component full name to FLEXIO_MCU_LCD (EDMA) driver.

## [2.0.1]

- Bug Fixes
  - The following modification to support FlexIO using multiple instances:
    - Removed FLEXIO_Reset API in module Init APIs.
    - Updated module Deinit APIs to reset the shifter/timer configuration instead of disabling module and clock.
    - Updated module Enable APIs to only support enable operation.

## [2.0.0]

- Initial version.
