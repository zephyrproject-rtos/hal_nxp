# LPSPI

## [2.2.10]

- Bug Fixes
  - Clear WIDTH bits from the TCR register before writing a new value in LPSPI_MasterTransferBlocking().

## [2.2.9]

- Bug Fixes
  - Fixed coverity issues.

## [2.2.8]

- Bug Fixes
  - Fixed coverity issues.

## [2.2.7]

- Bug Fixes
  - Fixed reading of TCR register
  - Workaround for errata ERR050606

## [2.2.6]

- Bug Fixes
  - Fixed an issue that LP_FLEXCOMM_Deinit() is called incorrectly.

## [2.2.5]

- Bug Fixes
  - Fixed the txData from void * to const void * in transmit API.

## [2.2.4]

- Improvements
  - Fixed doxygen warning in LPSPI_SlaveTransferHandleIRQ.

## [2.2.3]

- Bug Fixes
  - Disabled lpspi before LPSPI_MasterSetBaudRate incase of LPSPI opened.

## [2.2.2]

- Bug Fixes
  - Fixed 3-wire txmask of handle vaule reentrant issue.

## [2.2.1]

- Bug Fixes
  - Workaround for errata ERR051588 by clearing FIFO after transmit underrun occurs.

## [2.2.0]

- Feature
  - Added the new feature of multi-IO SPI .

## [2.1.1]

- Fixed LPSPI_MasterGetDefaultConfig incorrect default inter-transfer delay calculation.

## [2.0.0]

- Initial version.
