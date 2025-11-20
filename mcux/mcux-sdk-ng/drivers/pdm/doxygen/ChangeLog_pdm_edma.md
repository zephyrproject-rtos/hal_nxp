# PDM_EDMA

## [2.6.5]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 10.1, 10.3, 10.4, 10.5, 10.6, 10.7, 10.8.

## [2.6.4]

- Improvements
  - Add handling for runtime change of number of linked transfers

## [2.6.3]

- Improvements
  - Add EDMA ext API to accommodate more types of EDMA.

## [2.6.2]

- Improvements
  - Add macro MCUX_SDK_PDM_EDMA_PDM_ENABLE_INTERNAL to let the user decide whether to enable it when calling PDM_TransferReceiveEDMA.

## [2.6.1]

- Bug Fixes
  - Fixed violation of MISRA C-2012 Rule 10.3, 10.4.

## [2.6.0]

- Improvements
  - Updated api PDM_TransferReceiveEDMA to support channel block interleave transfer.
  - Added new api PDM_TransferSetMultiChannelInterleaveType to support channel interleave type configurations.

## [2.5.0]

- Refer PDM driver change log 2.1.0 to 2.5.0
