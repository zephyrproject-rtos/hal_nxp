# FLEXSPI EDMA Driver

## [2.3.3]

- Bug Fixes
  - Fixed FLEXSPI_TransferEDMA bug that, the DMA channel not configured
    correctly when using kFLEXSPI_Read.

## [2.3.2]

- Bug Fixes
  - Fixed the bug that internal variable s_edmaPrivateHandle overflows when using
    FlexSPI2.

## [2.0.2]

- New Features
  - Provided new API FLEXSPI_TransferUpdateSizeEDMA for users to update eDMA transfer size(SSIZE/DSIZE) per DMA
    transfer.

## [2.0.0]

- Initial version.
