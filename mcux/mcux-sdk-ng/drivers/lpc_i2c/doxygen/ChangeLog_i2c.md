# I2C

## [2.2.1]

- Bug Fixes
  - Fixed coverity issues.

## [2.2.0]

- Removed lpc_i2c_dma driver.

## [2.1.0]

- Bug Fixes
  - Fixed MISRA 8.6 violations.

## [2.0.4]

- Bug Fixes
  - Fixed wrong assignment for datasize in I2C_InitTransferStateMachineDMA.
  - Fixed wrong working flow in I2C_RunTransferStateMachineDMA to ensure master can work in no start flag and no
    stop flag mode.
  - Fixed wrong working flow in I2C_RunTransferStateMachine and added kReceiveDataBeginState in _i2c_transfer_states
    to ensure master can work in no start flag and no stop flag mode.
  - Fixed wrong handle state in I2C_MasterTransferDMAHandleIRQ. After all the data has been transfered or nak is
    returned, handle state should be changed to idle.
  - Eliminated IAR Pa082 warning in I2C_SlaveTransferHandleIRQ by assigning volatile variable to local variable and
    using local variable instead.
  - Fixed MISRA issues.
    - Fixed rules 4.7, 10.1, 10.3, 10.4, 11.1, 11.8, 14.4, 17.7.
- Improvements
  - Rounded up the calculated divider value in I2C_MasterSetBaudRate.
  - Updated the I2C_WAIT_TIMEOUT macro to unified name I2C_RETRY_TIMES.

## [2.0.3]

- Bug Fixes
  - Fixed Coverity issue of unchecked return value in I2C_RTOS_Transfer.

## [2.0.2]

- New Features
  - Added macro gate "FSL_SDK_ENABLE_I2C_DRIVER_TRANSACTIONAL_APIS" to enable/disable the transactional APIs
    which will help reduce the code size when no nonblocking transfer is used. Default configuration is enabled.
  - Added a control macro to enable/disable the RESET and CLOCK code in current driver.

## [2.0.1]

- Improvements
  - Added I2C_WATI_TIMEOUT macro to allow the user to specify the timeout times for waiting flags in functional API
    and blocking transfer API.

## [2.0.0]

- Initial version.
