# SAI_SDMA

## [2.6.0]

- Improvements
  - Removed deprecated API (SAI_TransferTxSetFormatSDMA,SAI_TransferRxSetFormatSDMA) and replaced them with new API (SAI_TransferRxSetConfigSDMA,SAI_TransferRxSetConfigSDMA)

## [2.5.3]

- Bug Fixes
  - Fixed the internal state of bd pool can not be reset in SAI_TransferTerminateSendSDMA.

## [2.5.2]

- Improvements
  - Change feature "FSL_FEATURE_SAI_FIFO_COUNT" to "FSL_FEATURE_SAI_HAS_FIFO".
  - Added feature "FSL_FEATURE_SAI_FIFO_COUNTn(x)" to align SAI fifo count function with IP in function

## [2.5.1]

- Bug Fixes
  - Fixed the incorrect internal queue state after abort the transfer in callback.

## [2.5.0]

- Bug Fixes
  - Fixed the incorrect driver queue state after calling abort function.
- Improvements
  - Added new api SAI_TransferTerminateSendSDMA/SAI_TransferTerminateReceiveSDMA.

## [2.4.1]

- Bug Fixes
  - Fixed the handler array s_sdmaPrivateHandle overflow issue.

## [2.4.0]

- Bug Fixes
  - Fixed burst length overflow issue when using multi fifo.
  - Added alignment check between transfer size and the fifo width.
  - Fixed violations of MISRA C-2012 rule 10.6.

## [2.3.1]

- Refer SAI driver change log 2.1.0 to 2.3.1
