# LPI2C


## [2.2.9]

- Bug Fixes
  - Set handle->chunkSize to 0 in LPI2C_MasterTransferNonBlocking().

## [2.2.8]

- Bug Fixes
  - Removed write to STAR register in LPI2C_SlaveTransferHandleIRQ handler in case of kLPI2C_SlaveRepeatedStartDetectFlag or kLPI2C_SlaveStopDetectFlag.
  - Removed configuration of FILTSDA from LPI2C_MasterSetBaudRate().
  - Set minimal possible value for FILTSDA and FILTSCL to 0.
  - Updated configuration of glitch filters in LPI2C_SlaveInit().
  - Set minimal possible value for SCFGR2[CLKHOLD] to 1.
  - Added error check to while loop in LPI2C_RunTransferStateMachine() for case kSendCommandState.

- Improvements
  - Removed receive data size limitation in LPI2C_MasterTransferBlocking() and LPI2C_MasterTransferNonBlocking().

## [2.2.7]

- Bug Fixes
  - Limited value of filtSda in LPI2C_MasterSetBaudRate().
  - Fixed configuration of MCFGR2 (FILTSDA) in LPI2C_MasterInit() - the change of FILTSDA in LPI2C_MasterSetBaudRate() could be overwritten.
  - Updated LPI2C_MasterStop() and LPI2C_MasterTransferBlocking() to send I2C STOP also in case of error.
  - Removed unused flag kLPI2C_TransferRepeatedStartFlag.

## [2.2.6]

- Bug Fixes
  - Fixed coverity issues.

## [2.2.5]

- Improvements
  - Added assert with target feature check in LPI2C_SlaveInit().
  - Added feature check to LPI2C_CommonIRQHandler().

## [2.2.4]

- Bug Fixes
  - Fixed LPI2C_MasterTransferBlocking() - the return value was sometime affected by call of LPI2C_MasterStop().

## [2.2.3]

- Bug Fixes
  - Fixed an issue that LP_FLEXCOMM_Deinit() is called incorrectly.

## [2.2.2]

- Improvements
  - Fixed doxygen warning in LPI2C_SlaveTransferHandleIRQ.

## [2.2.1]

- Bug Fixes
  - Added bus stop incase of bus stall in LPI2C_MasterTransferBlocking.

## [2.2.0]

- Improvements
  - Support the normal LPI2C in LPFLEXCOMM driver.

## [2.1.1]

- Improvements
  - Optimize slave ISR.When replying to ack/nack,first judge whether the user performs the reply in the APP.

## [2.1.0]

- New Features
  - Added new function LPI2C_SlaveEnableAckStall to enable or disable ACKSTALL.

## [2.0.1]

- Improvements
  - Supported to initialize the flexcomm layer outside the peripheral driver initialization function.

## [2.0.0]

- Initial version.
