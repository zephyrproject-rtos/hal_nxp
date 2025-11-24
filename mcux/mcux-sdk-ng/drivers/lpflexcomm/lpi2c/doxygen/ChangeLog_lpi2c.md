# LPI2C

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
