# DMIC

## [2.3.3]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 10.1, 10.3, 10.4, 10.5, 10.6, 10.7, 10.8.

## [2.3.2]

- New Features
  - Supported 4 channels in driver.

## [2.3.1]

- Bug Fixes
  - Fixed the issue that DMIC_EnableChannelDma and DMIC_EnableChannelFifo did not clean relevant bits.

## [2.3.0]

- Improvements
  - Added new apis DMIC_ResetChannelDecimator/DMIC_EnableChannelGlobalSync/DMIC_DisableChannelGlobalSync.

## [2.2.1]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 14.4, 17.7, 10.4, 10.3, 10.8, 14.3.

## [2.2.0]

- Bug Fixes
  - Corrected the usage of feature FSL_FEATURE_DMIC_IO_HAS_NO_BYPASS.

## [2.1.1]

- Improvements
  - Added feature FSL_FEATURE_DMIC_HAS_NO_IOCFG for IOCFG register.

## [2.1.0]

- New Features
  - Added API DMIC_EnbleChannelInterrupt/DMIC_EnbleChannelDma to replace API DMIC_SetOperationMode.
  - Added API DMIC_SetIOCFG and marked DMIC_ConfigIO as deprecated.
  - Added API DMIC_EnableChannelSignExtend to support sign extend feature.

## [2.0.5]

- Improvements
  - Changed some parameters' value of DMIC_FifoChannel API, such as enable, resetn, and trig_level. This is
    not possible for the current code logic, so it improves the DMIC_FifoChannel logic and fixes incorrect math logic.

## [2.0.4]

- Bug Fixes
  - Fixed the issue that DMIC DMA driver(ver2.0.3) did not support calling DMIC_TransferReceiveDMA in DMA
    callback as it did before version 2.0.3. But calling DMIC_TransferReceiveDMA in callback is not recommended.

## [2.0.3]

- New Features
- Supported linked transfer in DMIC DMA driver.
- Added new API DMIC_EnableChannelFifo/DMIC_DoFifoReset/DMIC_InstallDMADescriptor.

## [2.0.2]

- New Features
  - Supported more channels in driver.

## [2.0.1]

- New Features
  - Added a control macro to enable/disable the RESET and CLOCK code in current driver.

## [2.0.0]

- Initial version.
