# LPUART_EDMA

## [2.1.2]

- Bug Fixes
  - Fixed race condition in LPUART_ReceiveEDMA() for transfers whose size is not a multiple of 4 bytes.

## [2.1.1]

- Improvements
  - Reduced DMA requests - transfer up to 4 FIFO words per DMA request

## [2.1.0]

- Improvements
  - Added LPUART_TransferCreateHandleEDMAExt - allows configuration of when the TX transfer callback is triggered.

## [2.0.0]

- Initial version.
