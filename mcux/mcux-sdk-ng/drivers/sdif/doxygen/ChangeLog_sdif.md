# SDIF

## [2.1.0]

- Improvements
  - Removed reduntant member endianMode in sdif_config_t.
  - Added error status check in function SDIF_WaitCommandDone.
  - Fixed the read fifo data incomplete issue in interrupt non-dma mode.

## [2.0.15]

- Bug Fixes
  - Cleared the interrupt status before enable the interrupt to avoid interrupt generate unexpectedly.
  - Fixed the SDIF_ReadDataPortBlocking blocking at wrong condition issue.
- Improvements
  - Enabled the functionality of timeout parameter in SDIF_SendCommand.
  - Added the error recovery while sending sync clock command timeout.

## [2.0.14]

- Improvements
  - Used different status code for command and data interrupt callback.
- Bug Fixes
  - Fixed the DMA descriptor attribute field unreset when configuing the current transfer DMA descriptor issue which may cause the transfer terminate unexpected.

## [2.0.13]

- Improvements
  - Disabled redundant interrupt per different transfer request.
  - Disabled interrupt and reset command/data pointer in handle when
    transfer completes.
- Bug Fixes
  - Fixed the PA082 build warning.
  - Fixed violations of the MISRA C-2012 rules 14.4, 17.7, 10.4, 10.3, 10.8, 14.3, 10.1, 16.4, 15.7, 12.2, 11.3, 11.9.

## [2.0.12]

- Bug Fixes
  - Fixed the issue that SDIF_ConfigClockDelay didn't reset the delay field before write.
  - Removed useless fifo reset code in transfer function.
  - Fixed the divider overflow issue in function SDIF_SetCardClock.

## [2.0.11]

- Improvements
  - Added API SDIF_GetEnabledInterruptStatus/SDIF_GetEnabledDMAInterruptStatus
    and used in SDIF_TransferHandleIRQ.
  - Removed useless members interruptFlags/dmaInterruptFlags in the
    sdif_handle_t.
  - Improved SDIF_SendCommand with return success directly when timeout is 0.
  - Added timeout error check when sending update clock command in
    SDIF_SetCardClock.
  - Removed START_CMD status polling for normal command sending in
    SDIF_TransferBloking/SDIF_TransferNonBlocking.
  - Disabled timeout parameter in function SDIF_SendCommand.
- Bug Fixes
  - Added delay cycle for the default speed mode(400 K and 25 M) to fix the
    timing issue when different AHB clocks are configured.

## [2.0.10]

- Bug Fixes
  - Fixed the issue that API SDIF_EnableCardClock could not clear the clock enable bit.

## [2.0.9]

- Bug Fixes
  - Fixed MDK 66-D warning.

## [2.0.8]

- New Features
  - Added control macro to enable/disable the RESET and CLOCK code in current driver.
  - Disabled useless interrupt while DMA is used.
  - Updated SDIF driver for one instance support two cards.

## [2.0.7]

- Bug Fixes
  - Enlarged the timeout value to avoid a command conflict issue.

## [2.0.6]

- Bug Fixes
  - Removed assert(srcClock_Hz <= FSL_FEATURE_SDIF_MAX_SOURCE_CLOCK).
  - Used hardware reset instead of software reset during initialization.

## [2.0.5]

- New Features
  - Added non-word aligned data address and DMA descriptor address transfer support. Once one of the above
    addresses is not aligned, switch to host transfer mode.
- Bug Fixes
  - Fixed the issue that DMA suspended during initialization.
  - Removed useless memset function call.

## [2.0.4]

- Improvements
  - Added cardInserted/cardRemoved callback function.
  - Added host base address/user data parameter for all call back functions.

## [2.0.3]

- Improvements
  - Improved Clock Delay macro to allow the user to redefine and remove useless delay for clock below 25 MHz.

## [2.0.2]

- Bug Fixes
  - Fixed the issue that the status flag could not be cleared entirely after transfer complete.

## [2.0.1]

- New Features
  - Improved interrupt transfer callback.
- Bug Fixes
  - Added assert to limit the SDIF source clock below 52 MHz.

## [2.0.0]

- Initial version.
