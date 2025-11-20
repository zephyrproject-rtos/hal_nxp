# SPI

## [2.0.8]

- Bug Fixes
  - Fixed coverity issue.

## [2.0.7]

- Bug Fixes
  - Fixed the txData from void * to const void * in transmit API.

## [2.0.6]

- Improvements
  - Changed SPI_DUMMYDATA to 0x00.

## [2.0.5]

- Bug Fixes
  - Fixed bug that the transfer configuration does not take effect after the first transfer.

## [2.0.4]

- Bug Fixes
  - Fixed the issue that when transfer finish callback is invoked TX data is not sent to bus yet.

## [2.0.3]

- Improvements
  - Added timeout mechanism when waiting certain states in transfer driver.
  - Fixed MISRA 10.4 issue.

## [2.0.2]

- Bug Fixes
  - Fixed Coverity issue of incrementing null pointer in SPI_MasterTransferNonBlocking.
  - Fixed MISRA issues.
    - Fixed rules 10.1, 10.3, 10.4, 10.6, 14.4.
- New Features
  - Added enumeration for dataWidth.

## [2.0.1]

- Bug Fixes
  - Added wait mechanism in SPI_MasterTransferBlocking() API, which checks if master SPI becomes IDLE when
    the EOT bit is set before returning. This confirms that all data will be sent out by SPI master.
  - Fixed the bug that the EOT bit couldn't be set when only one frame was sent in polling mode and interrupt
    transfer mode.
- New Features
  - Added macro gate "FSL_SDK_ENABLE_SPI_DRIVER_TRANSACTIONAL_APIS" to enable/disable the transactional APIs,
    which helps reduce the code size when no nonblocking transfer is used. Enabled default configuration.
  - Added a control macro to enable/disable the RESET and CLOCK code in current driver.

## [2.0.0]

- Initial version.
