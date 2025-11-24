# QSPI

## [2.3.1]

- Improvements
  - Fixed Coverity MSG issues.

## [2.3.0]

- New Features
  - Applied the QSPI IP update with register field changes.
  - Added Soc specific driver to integrate Soc configuration.
- Changed
  - Updated the QSPI LUT update function to be compatible with different sequence unit.
  - Added new feature macro FSL_FEATURE_QSPI_HAS_SOC_SPECIFIC_CONFIG which represents there're Soc specific QSPI configurations.
    Soc specific driver should cover these configurations. Previous Soc specific code in the common driver should be masked.

## [2.2.5]

- Bug Fixes
  - Fixed the txData from void * to const void * in transmit API.

## [2.2.4]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 10.3.

## [2.2.3]

- Bug Fixes
  - Cleared buffer generic configuration when do software reset.

## [2.2.2]

- Bug Fixes
  - MISRA C-2012 issue fixed: rule 10.1 and 11.9.

## [2.2.1]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 10.1, 10.3, 10.4, 10.6, 10.8, 11.3, 11.6, 11.8, 11.9, 14.4, 16.1, 16.4, 17.7.

## [2.2.0]

- New Features
  - Added new API QSPI_ClearCache to clear cache for new IP feature FSL_FEATURE_QSPI_SOCCR_HAS_CLR_LPCAC.
- Bug Fixes
  - Fixed the QSPI_WriteBlocking API programming issue for low watermark, caused by previous improvement change of
    using TX watermark signal to fill the TX FIFO. Reverted change to previous implementation to use TX FIFO full
    flag for filling the FIFO. Improved previous API by accessing TX data register directly.
  - Fixed the issue that QSPI_SetIPCommandSize incorrectly triggered a transaction.
  - Fixed clock divider accurate issue when using internal QSPI internal divider.
  - Fixed build fail issue for some devices' not supporting API QSPI_SetDqsConfig for DQS configuration.

## [2.1.0]

- New Features
  - Added new API QSPI_SetDqsConfig for DQS configuration.
- Improvements
  - Updated the QSPI_WriteBlocking API to fill the TX FIFO once there are bytes of TX watermark room in the FIFO.
    This will improve the performance of filling TX FIFO when watermark is high.

## [2.0.2]

- Improvements
  - New Macro function:
    - Added QSPI_LUT_SEQ() function for users to set LUT table easily.
    - Added LUT command macros for users to easy use.
  - Comment update:
    - Added the comments for the limitation of QSPI_ReadBlocking and QSPI_TransferReceiveBlocking.

## [2.0.1]

- Improvements
  - New API:
    - QSPI_SetReadArea to set the read area.
- Bug Fixes
  - Fixed the issue that QSPI_UpdateLUT function only updated first LUT.
  - Fixed issue that some function that hardcode QSPI0 as base.

## [2.0.0]

- Initial version.
