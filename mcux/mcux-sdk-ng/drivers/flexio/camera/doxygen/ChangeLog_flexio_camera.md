# FLEXIO_CAMERA

## [2.2.0]

- Improvements
  - Supported platforms which don't have DOZE mode control.

## [2.1.3]

- Bug Fixes
  - Fixed MISRA 10.4 issues.

## [2.1.2]

- Improvements
  - Unified component full name to FLEXIO CAMERA (EDMA) driver.
- Bug Fixes
  - Fixed MISRA issues
    - Fixed rules 10.1, 10.3, 10.4, 10.7, 11.6, 11.9, 14.4, 17.7.

## [2.1.1]

- Bug Fixes
  - The following modifications support FlexIO using multiple instances:
    - Removed FLEXIO_Reset API in module Init APIs.
    - Updated module Deinit APIs to reset the shifter/timer configuration instead of disabling module and clock.
    - Updated module Enable APIs to only support enable operation.

## [2.1.0]

- New Features
  - Added Transfer prefix in transactional APIs.
