# IMU

## [2.2.0]

- New Features
  - Added IMU_BUSY_POLL_COUNT parameter to prevent infinite polling loops in IMU operations.
  - Added timeout mechanism to all polling loops in IMU driver code.

- Improvements
  - Enhanced error handling in blocking functions to return timeout status.
  - Updated documentation to clarify timeout behavior and return values.
  - Added IMU_ERR_TIMEOUT error code for timeout conditions.

## [2.1.1]

- Bug Fixes
  - Fix MISRA C-2012 violations.
  - Fixed IMU_GetStatusFlags bug that returns wrong RX FIFO status.

## [2.1.0]

- Improvements:
  - Updated API prototype, remove CIU2_Type from parameters.

## [2.0.0]

- Initial version.
