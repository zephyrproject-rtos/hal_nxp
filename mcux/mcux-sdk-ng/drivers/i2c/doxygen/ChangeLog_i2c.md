# I2C

## [2.0.10]

- Bug Fixes
  - Fixed coverity issues.

## [2.0.9]

- Bug Fixes
  - Fixed the MISRA-2012 violations.
    - Fixed rule 8.4, 10.1, 10.4, 13.5, 20.8.

## [2.0.8]

- Bug Fixes
  - Fixed the bug that DFEN bit of I2C Status register 2 could not be set in I2C_MasterInit.
  - MISRA C-2012 issue fixed: rule 14.2, 15.7, and 16.4.
  - Eliminated IAR Pa082 warnings from I2C_MasterTransferDMA and I2C_MasterTransferCallbackDMA by assigning volatile
    variables to local variables and using local variables instead.
  - Fixed MISRA issues.
    - Fixed rules 10.1, 10.3, 10.4, 11.9, 14.4, 15.7, 17.7.
- Improvements
  - Improved timeout mechanism when waiting certain state in transfer API.
  - Updated the I2C_WAIT_TIMEOUT macro to unified name I2C_RETRY_TIMES.
  - Moved the master manually acknowledge byte operation into static function I2C_MasterAckByte.
  - Fixed control/status clean flow issue inside I2C_MasterReadBlocking to avoid potential issue that pending status
    is cleaned before it's proceeded.

## [2.0.7]

- Bug Fixes
  - Fixed the issue for MISRA-2012 check.
    - Fixed rule 11.9 ,15.7 ,14.4 ,10.4 ,10.8 ,10.3, 10.1, 10.6, 13.5, 11.3, 13.2, 17.7, 5.7, 8.3, 8.5, 11.1, 16.1.
  - Fixed Coverity issue of unchecked return value in I2C_RTOS_Transfer.
  - Fixed variable redefine issue by moving i2cBases from fsl_i2c.h to fsl_i2c.c.
- Improvements
  - Added I2C_MASTER_FACK_CONTROL macro to enable FACK control for master transfer receive flow with IP supporting
    double buffer, then master could hold the SCL by manually setting TX AK/NAK during data transfer.

## [2.0.6]

- Bug Fixes
  - Fixed the issue that I2C Master transfer APIs(blocking/non-blocking) did not support the situation of master
    transfer with subaddress and transfer data size being zero, which means no data followed by the subaddress.

## [2.0.5]

- Improvements
  - Added I2C_WATI_TIMEOUT macro to allow the user to specify the timeout times for waiting flags in functional API
    and blocking transfer API.

## [2.0.4]

- Bug Fixes
  - Added a proper handle for transfer config flag kI2C_TransferNoStartFlag to support transmit with
    kI2C_TransferNoStartFlag flag. Support write only or write+read with no start flag; does not support read only
    with no start flag.

## [2.0.3]

- Bug Fixes
  - Removed enableHighDrive member in the master/slave configuration structure because the operation to HDRS bit is
    useless, the user need to use DSE bit in port register to configure the high drive capability.
  - Added register reset operation in I2C_MasterInit and I2C_SlaveInit APIs. Fixed issue where I2C could not switch
    between master and slave mode.
  - Improved slave IRQ handler to handle the corner case that stop flag and address match flag come synchronously.

## [2.0.2]

- Bug Fixes
  - Fixed issue in master receive and slave transmit mode with no stop flag. The master could not
    succeed to start next transfer because the master could not send out re-start signal.
  - Fixed the out-of-order issue of data transfer due to memory barrier.
  - Added hold time configuration for slave. By leaving the SCL divider and MULT reset values when configured to
    slave mode, the setup and hold time of the slave is then reduced outside of spec for lower baudrates. This can
    cause intermittent arbitration loss on the master side.
- New Features
  - Added address nak event for master.
  - Added general call event for slave.

## [2.0.1]

- New Features
  - Added double buffer enable configuration for SoCs which have the DFEN bit in S2 register.
  - Added flexible transmit/receive buffer size support in I2C_SlaveHandleIRQ.
  - Added start flag clear, address match, and release bus operation in I2C_SlaveWrite/ReadBlocking API.
- Bug Fixes
  - Changed the kI2C_SlaveRepeatedStartEvent to kI2C_SlaveStartEvent.

## [2.0.0]

- Initial version.
