# SDHC

## [2.1.13]

- Improvements
  - Cleared SDHC status before transfer start in SDHC_TransferBlocking function.

## [2.1.12]

- Bug Fixes
  - Fixed the ADMA descriptor configuration issue when transfer size bigger than the max length of one descriptor.

## [2.1.11]

- Improvements
  - Used different status code for command and data interrupt callback.

## [2.1.10]

- Improvements
  - Disabled redundant interrupt per different transfer request.
  - Disabled interrupt and reset command/data pointer in handle when
    transfer completes.
- Bug Fixes
  - Fixed PA082 build warning.
  - Fixed violations of MISRA C-2012 rule 10.1, 10.3, 10.4, 4.7, 16.4, 15.7, 14.4, 10.6, 10.8, 11.3, 17.7, 13.5, 11.9.

## [2.1.9]

- Improvements
  - Added API SDHC_GetEnabledInterruptStatusFlags and used it in
    SDHC_TransferHandleIRQ.
  - Removed useless member interruptFlag in sdhc_handle_t.
  - Fixed OUT-OF BOUNDS write in function SDHC_ReceiveCommandResponse.

## [2.1.8]

- Bug Fixes
  - Disabled useless interrupt while DMA is used.
  - Fixed MDK 66-D warning.

## [2.1.7]

- Bug Fixes
  - Fixed ADMA1 descriptor configuration error.
  - Improved set clock function to check the output frequency range.

## [2.1.6]

- New Features
  - Added SDHC_CardDetectByData3 API to support detect card through DATA3.
  - Added host base address/user data parameter for all call back function.

## [2.1.5]

- New Features
  - Added NON-WORD align data addr transfer support in DMA mode.

## [2.1.4]

- New Features
  - Added response error flag to check response once read from the card.
- Bug Fixes
  - Fixed the issue of incorrect calculation of the clock divider.

## [2.1.3]

- Improvements
  - Modified some definitions to be compatible with middleware adapter.

## [2.1.2]

- Bug Fixes
  - Used function pointer for interrupt handler to reduce code size.
  - Bad status bit check behavior when waiting for initialization of an SD card.
  - Added support NON-WORD aligned data size transfer mode for SDIO card.

## [2.1.1]

- Bug Fixes
  - Fixed the compile error when ADMA1 is enabled.

## [2.1.0]

- New Features
  - Added a host descriptor to contain SDHC related attributes.
- Bug Fixes
  - Removed clock auto gated function because of that it is a hardware issue.
- Other Changes
  - Added more SDIO card related command type.
  - Changed the callback mechanism in the non-blocking transaction API.
  - Merged the two ADMA configuration functions to be one.
  - Changed the transaction API's name.
