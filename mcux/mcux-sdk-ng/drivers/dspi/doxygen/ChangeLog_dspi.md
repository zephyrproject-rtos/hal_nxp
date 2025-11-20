# DSPI

## [2.2.7]

- Improvements
  - Added macros to disable some features.

## [2.2.6]

- Bug Fixes
  - Fixed the txData from void * to const void * in transmit API.

## [2.2.5]

- Improvements
  - Initialized the EDMA configuration structure in the DSPI EDMA driver.

## [2.2.4]

- Bug Fixes
  - Fixed bug that instance with shared TR/RX EDMA request cannot transfer 1 datawidth of data as master in
    single transfer.

## [2.2.3]

- Improvements
  - Added macro of getting maximum transfer size using EDMA way.

## [2.2.2]

- Bug Fixes
  - MISRA C-2012 issue fixed:
    - Fixed rules, containing: 10.8, 10.3.
  - Fixed the build warning issue.
  - Fixed the bug that PCS would temporarily pull down for a while during master initialization.
  - Fixed compiling error of undefined identifier g_dspiDummyData.
  - Changed the type of kDSPI_AllStatusFlag and kDSPI_AllInterruptEnable from int to uint32_t to fix Pe068
    warning of integer conversion.
  - Eliminated IAR Pa082 warning in DSPI_MasterTransferDMA.

## [2.2.1]

- Bug Fixes
  - Fixed the bug for double execution of transfer complete callback in master interrupt transfer mode.
    In the interrupt routine, the DSPI interrupt may drop in the situation of the interrupt pending by itself
    while receiving the last frame, adding check to the transfer state to execute the callback function.
  - Fixed wrong logic in DSPI_SetFifoEnable().
  - MISRA C-2012 issue fixed.
    - Fixed rules, containing: rule-12.1, rule-17.7, rule-16.4, rule-14.4, rule-10.4, rule-10.8, rule-10.3,
      rule-10.1, rule-10.6, rule-13.5, rule-11.3, rule-13.2, rule-8.3, and rule-8.5.

## [2.2.0]

- New Features
  - Added gasket feature for SPI EDMA driver, which reduces one channel used in the EDMA master transfer.
    With this feature support, only two channels are needed. For example, if the gasket feature is supported, we
    could use the DSPI_MasterTransferCreateHandleEDMA function like below:
    DSPI_MasterTransferCreateHandleEDMA(EXAMPLE_DSPI_MASTER_BASEADDR, &g_dspi_edma_m_handle, DSPI_MasterUserCallback,
    &userData, &dspiEdmaMasterRxRegToRxDataHandle, NULL,
    &dspiEdmaMasterIntermediaryToTxRegHandle);
  - Added dummy data setup API to allow users to configure the dummy data to be transferred.
  - Added new APIs for half-duplex transfer function. Users can send and receive data by one API in the
    polling/interrupt/EDMA way, and they can choose either to transmit first or to receive first. Additionally,
    the PCS pin can be configured as assert status in transmission (between transmit and receive) by setting
    the isPcsAssertInTransfer to true.

## [2.1.4]

- Bug Fixes
  - DSPI EDMA driver: the DSPI instance has been separated, so the DMA request source can now transfer up to 32767
    Bytes data in one DSPI_MasterTransferEDMA() transfer.

## [2.1.3]

- Bug Fixes
  - DSPI EDMA driver can no longer support the case that the transfer data size is odd, but the bitsPerFrame is
    greater than 8.
- Improvements
  - Added #ifndef/#endif to allow users to change the default TX value at compile time.

## [2.1.2]

- Bug Fixes
  - DSPI_MasterTransferBlocking function would hang in some corner cases (for example, some cases with bitsPerFrame
    is 4,6 and kDSPI_MasterPcsContinuous transfer mode).

## [2.1.1]

- Bug Fixes
  - Set the EOQ (End Of Queue) bit to TRUE for the last transfer in transactional APIs.

## [2.1.0]

- New Features
  - Added Transfer prefix in transactional APIs.

## [2.0.0]

- Initial version.
