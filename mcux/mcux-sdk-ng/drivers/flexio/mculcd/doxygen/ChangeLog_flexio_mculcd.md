# FLEXIO_MCU_LCD

## [2.3.0]

- New Features
  - Supported passing an extra user defined parameter to GPIO functions to control the
    CS/RS/RDWR pin signal.

## [2.2.0]

- Improvements
  - Supported platforms which don't have DOZE mode control.

## [2.1.0]

- New Features
  - Supported transmit only data without command.

## [2.0.8]

- Bug Fixes
  - Fixed bug that FLEXIO_MCULCD_Init return kStatus_Success even with
    invalid parameter.
  - Fixed glitch on WR, that when initially configure the timer pin as output, or change the
    pin back to disabled, the pin may be driven low causing glitch on bus. Configure the pin
    as bidirection output first then perform a subsequent write to change to output or dsiabled
    to avoid the issue.

## [2.0.6]

- Bug Fixes
  - Fixed MISRA 10.4 issues when FLEXIO_MCULCD_DATA_BUS_WIDTH defined as signed value.

## [2.0.5]

- Improvements
  - Changed FLEXIO_MCULCD_WriteDataArrayBlocking's data parameter to const type.

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
