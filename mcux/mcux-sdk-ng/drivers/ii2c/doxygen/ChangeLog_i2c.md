# I2C

## [2.0.7]

- Bug Fixes
  - Fixed MISRA issues.
    - Fixed rules 8.4, 8.5.

## [2.0.6]

- Bug Fixes
  - Fixed the bug that, in I2C_MasterStop after the stop command is issued, the IBB flag should be cleared rather
    than set.
  - Fixed the bug that to clear kI2C_ArbitrationLostFlag and kI2C_IntPendingFlag, their bits should be written '0'
    rather than '1'.

## [2.0.5]

- Bug Fixes
  - Fixed Coverity issue of unchecked return value in I2C_RTOS_Transfer.
  - Fixed MISRA issues.
    - Fixed rules 10.1, 10.3, 10.4, 11.9, 14.4, 15.7, 16.4, 17.7.
- Improvements
  - Updated the I2C_WAIT_TIMEOUT macro to unified name I2C_RETRY_TIMES.

## [2.0.4]

- Bug Fixes
  - Fixed the issue that I2C Master transfer APIs(blocking/non-blocking) did not support the situation that master
    transfer with subaddress and transfer data size being zero, which means no data followed by the subaddress.

## [2.0.3]

- Improvements
  - Improved code readability, added new static API I2C_WaitForStatusReady for the status flag wait, and changed to
    call I2C_WaitForStatusReady instead of polling flags with reading register.

## [2.0.2]

- Improvements
  - Added I2C_WATI_TIMEOUT macro to allow users to specify the timeout times for waiting flags in functional API
    and blocking transfer API.

## [2.0.1]

- Bug Fixes
  - Added a proper handle for transfer config flag kI2C_TransferNoStartFlag to support transmit with
    kI2C_TransferNoStartFlag flag. Only supports write only or write+read with no start flag; does not support read
    only with no start flag.

## [2.0.0]

- Initial version.
