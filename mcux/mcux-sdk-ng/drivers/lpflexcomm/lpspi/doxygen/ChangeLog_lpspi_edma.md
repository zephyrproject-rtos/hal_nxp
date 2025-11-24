# LPSPI_EDMA

## [2.1.4]

- Improvements
  - Reduced DMA requests - transfer up to 4 FIFO words per DMA request

## [2.1.3]

- Improvements
  - Increased transmit FIFO watermark to ensure whole transmit FIFO will be used during data transfer.

## [2.1.2]

- Bug Fixes
  - Fixed reading of TCR register
  - Workaround for errata ERR050606

## [2.1.1]

- Improvements
  - Add EDMA ext API to accommodate more types of EDMA.

## [2.1.0]

- Improvements
  - Separated LPSPI_MasterTransferEDMA functions to LPSPI_MasterTransferPrepareEDMA and LPSPI_MasterTransferEDMALite to optimize the process of transfer.

## [2.0.0]

- Initial version.
