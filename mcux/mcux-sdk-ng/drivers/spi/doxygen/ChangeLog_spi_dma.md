# SPI DMA Driver

## [2.1.1]

- Bug Fixes
  - Fixed the bug that TX data not sent to bus when transfer finish callback is called.

## [2.1.0]

- Improvements
  - Added timeout mechanism when waiting certain states in transfer driver.
- Bug Fixes
  - Fixed the bug that, when working as a slave, instance that does not have FIFO may miss some rx data.
  - Fixed master RX data overflow issue by synchronizing transmit and receive process.
  - Fixed issue that slave should not share the same non-blocking initialization API and IRQ handler with
    master to prevent dead lock issue.
  - Fixed issue that callback should be invoked after all data is sent out to bus.
  - Added code in SPI_SlaveTransferNonBlocking to empty rx buffer before initializing transfer.

## [2.0.5]

- Bug Fixes
  - Eliminated Pa082 warnings from SPI_WriteNonBlocking and SPI_GetStatusFlags.
  - Fixed MISRA issues.
    - Fixed issues 10.1, 10.3, 10.4, 10.7, 10.8, 11.9, 14.4, 17.7.

## [2.0.4]

- New Features
  - Supported 3-wire mode for SPI driver. Added new API SPI_SetPinMode() to control the transfer direction of
    the single wire. For master instance, MOSI is selected as I/O pin. For slave instance, MISO is selected
    as I/O pin.
  - Added dummy data setup API to allow users to configure the dummy data to be transferred.

## [2.0.3]

- Bug Fixes
  - Fixed the potential interrupt race condition at high baudrate when calling API SPI_MasterTransferNonBlocking.

## [2.0.2]

- New Features
  - Allowed users to set the transfer size for SPI_TransferNoBlocking non-integer times of watermark.
  - Allowed users to define the dummy data. Users only need to define the macro SPI_DUMMYDATA in applications.

## [2.0.1]

- Bug Fixes
  - Fixed SPI_Enable function parameter error.
  - Set the s_dummy variable as static variable in fsl_spi_dma.c.
- Improvements
  - Optimized the code size while not using transactional API.
  - Improved performance in polling method.
  - Added #ifndef/#endif to allow users to change the default tx value at compile time.

## [2.0.0]

- Initial version.
