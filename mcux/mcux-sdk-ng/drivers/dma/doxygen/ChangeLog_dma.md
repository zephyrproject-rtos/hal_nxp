# DMA

## [2.1.2]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 10.3.

## [2.1.1]

- Improvements
  - Corrected the dma channel feature macro from FSL_FEATURE_DMAMUX_MODULE_CHANNEL  to FSL_FEATURE_DMA_MODULE_CHANNEL.

## [2.1.0]

- Improvements
  - Added api DMA_PrepareTransferConfig to expose option address increment.
  - Added api DMA_EnableAutoStopRequest to support auto stop request feature.

## [2.0.2]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 10.4, 10.3, 14.4, 16.4, 11.6, 10.1.

## [2.0.1]

- Bug Fixes
  - By adding parenthesis, fixed the build fail of DMA driver due to rule 12.5, MISRA C 2004.

## [2.0.0]

- Initial version.
