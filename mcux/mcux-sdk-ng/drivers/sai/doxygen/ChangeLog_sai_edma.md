# SAI_EDMA

## [2.7.6]

- Bug Fixes
  - Fixed SAI_TransferRxSetConfigEDMA using the TX FIFO-combine enum kSAI_FifoCombineModeEnabledOnRead (value 1) for the RX path. On RCR4 that value selects write-combine instead of the read-combine required by multi-channel RX DMA, and the assert validated the same wrong value and silently passed. The RX assert and documentation now use kSAI_RXFifoCombineModeEnabledOnRead (value 2). Note: multi-channel RX code that previously passed the old value will now assert in debug builds, surfacing the misconfiguration instead of hiding it.

## [2.7.5]

- Bug Fixes
  - Fixed Coverity DEADCODE finding by removing the unreachable offset overflow branch in SAI_TransferSendEDMA and SAI_TransferReceiveEDMA.

## [2.7.4]

- Bug Fixes
  - Fixed MSG finding for platforms with multiple FIFO size support.

## [2.7.3]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 10.1, 10.3, 10.4, 10.5, 10.6, 10.7, 10.8, 12.4.

## [2.7.2]

- Improvements
  - Add macros MCUX_SDK_SAI_EDMA_TX_ENABLE_INTERNAL and MCUX_SDK_SAI_EDMA_RX_ENABLE_INTERNAL to let the user decide whether to enable SAI when calling SAI_TransferSendEDMA/SAI_TransferReceiveEDMA.

## [2.7.1]

- Improvements
  - Add EDMA ext API to accommodate more types of EDMA.

## [2.7.0]

- Improvements
  - Updated api SAI_TransferReceiveEDMA to support voice channel block interleave transfer.
  - Updated api SAI_TransferSendEDMA to support voice channel block interleave transfer.
  - Added new api SAI_TransferSetInterleaveType to support channel interleave type configurations.

## [2.6.0]

- Improvements
  - Removed deprecated APIs.

## [2.5.1]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 20.7.

## [2.5.0]

- Improvements
  - Added new api SAI_TransferSendLoopEDMA/SAI_TransferReceiveLoopEDMA to support loop transfer.
  - Added multi sai channel transfer support.

## [2.4.0]

- Improvements
  - Added new api SAI_TransferGetValidTransferSlotsEDMA which can be used to get valid transfer slot count in the sai edma transfer queue.
  - Deprecated the api SAI_TransferRxSetFormatEDMA and SAI_TransferTxSetFormatEDMA.
- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 10.3,10.4.

## [2.3.2]

- Refer SAI driver change log 2.1.0 to 2.3.2
