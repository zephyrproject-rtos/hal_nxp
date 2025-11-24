# SPI

## [2.0.6]

- Improvements
  - Changed SPI_DUMMYDATA to 0x00.

## [2.0.5]

- Improvements
  - Added FIFO and Tx status checking to ensure callback is invoked after Tx data is totally sent out in half-duplex transfer.

## [2.0.4]

- Improvements
  - Added timeout mechanism when waiting certain states in transfer driver.

## [2.0.3]

- Bug Fixes
  - Eliminated IAR Pa082 warning from SPI_SendTransfer, SPI_MasterTransferBlocking, SPI_SetupDummy,
    SPI_MasterTransferHandleIRQ and SPI_SlaveTransferHandleIRQ.
  - Fixed MISRA issues,
    - Fixed rules 10.1, 10.3, 10.4, 10.7, 11.6, 11.9, 14.4, 16.4, 17.7.

## [2.0.2]

- New Features
  - Added control macro to enable/disable the RESET and CLOCK code in current driver.
  - Added wait mechanism in SPI_MasterTransferBlocking API, checking if master SPI becomes IDLE when
    the EOT bit is set before returning. This confirms all data will be sent out by SPI master.

## [2.0.1]

- Improvements
  - Optimized the code to improve the performance of both blocking and nonblocking transfer.
  - Changed the default value of TX FIFO size and RX FIFO size in SPI_MasterGetDefaultConfig and
    SPI_SlaveGetDefaultConfig to 0. Because different devices may have different FIFO sizes, a fixed value
    may not be very adaptable. So, users need to configure the TX and RX FIFO size in their applications
    as they want if FIFO is enabled.
- New Features
  - Added new feature to support the ignore receive function, this update makes the transfer faster
    if no need to receive data, both blocking and nonblocking transfer can support this feature.

## [2.0.0]

- Initial version.
