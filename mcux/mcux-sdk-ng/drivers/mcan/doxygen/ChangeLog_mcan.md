# MCAN

## [2.4.2]

- Bug Fixes
  - Fixed MISRA issue rule-10.3, rule-10.6, rule-10.7 and rule-15.7.

## [2.4.1]

- Bug Fixes
  - Fixed incorrect fifo1 status on message lost.

## [2.4.0]

- Improvements
  - Add MCAN_CalculateSpecifiedTimingValues() API to get CAN bit timing parameter with user-defined settings.
  - Add MCAN_FDCalculateSpecifiedTimingValues() API to get CANFD bit timing parameter with user-defined settings.

## [2.3.2]

- Bug Fixes
  - Fix MISRA C-2012 issue 10.1 and 10.4.

## [2.3.1]

- Bug Fixes
  - Fixed the issue that MCAN_TransferSendNonBlocking() API can't send remote frame.

## [2.3.0]

- Improvements
  - Add MCAN_SetMessageRamConfig() API to perform global message RAM configure.
  - Add MCAN_EnterInitialMode() API.

## [2.2.0]

- Improvements
  - Add MCAN_SetBaudRate/MCAN_SetBaudRateFD APIs to make users easy to set CAN baud rate.

## [2.1.8]

- Bug Fixes
  - Add check FIFO status code in MCAN_ReadRxFifo() to avoid read back empty frame and wrong trigger the FIFO index increase.

## [2.1.7]

- Bug Fixes
  - Fixed the clear error flags issue in MCAN_TransferHandleIRQ() API.
  - Fixed the Solve Tx interrupt issue in MCAN_TransferHandleIRQ() API which may abort the unhandled transfers.
  - Remove disable global tx interrupt from MCAN_TransferAbortSend API.

## [2.1.6]

- Bug Fixes
  - Fixed the issue of writing 1 in the following functions.
  - MCAN_TransmitAddRequest
  - MCAN_TransmitCancelRequest
  - MCAN_ClearRxBufferStatusFlag

## [2.1.5]

- Bug Fixes
  - Fix MISRA C-2012 issue.

## [2.1.4]

- Improvements
  - Updated improve timing APIs to make it can calculate the CiA recommended timing configuration.
  - Implement Transmitter Delay Compensation feature.
  - Modify the default baudRateFD value to 2M.
- Bug Fixes
  - Fixed the code error issue in MCAN_ClearStatusFlag() to avoid clear all flags.

## [2.1.3]

- Bug Fixes
  - Fixed the code error issue and simplified the algorithm in improved timing APIs.
    - MCAN_CalculateImprovedTimingValues
    - MCAN_FDCalculateImprovedTimingValues

## [2.1.2]

- Bug Fixes
  - Fixed the non-divisible case in improved timing APIs.
    - MCAN_CalculateImprovedTimingValues
    - MCAN_FDCalculateImprovedTimingValues

## [2.1.1]

- Bug Fixes
  - MISRA C-2012 issue check.
    - Fixed rules, containing: rule-10.1, rule-10.3, rule-10.4, rule-10.6, rule-10.7, rule-10.8, rule-11.9,
      rule-14.4, rule-15.5, rule-15.6, rule-15.7, rule-17.7, rule-18.4, rule-2.2, rule-21.15, rule-5.8, rule-8.3.
    - Fixed the Coverity issue of BAD_SHIFT in MCAN.
    - Fixed the issue of Pa082 warning.
    - Fixed the issue of dropping interrupt flags in handler function.

## [2.1.0]

- Bug Fixes
  - Fixed Coverity issue FORWARD_NULL.
  - Fixed Clang issue.
  - Fixed legacy issue in the driver and changed default bus data baud rate for CANFD.
- Improvements
  - Implemented feature for improved timing configuration.

## [2.0.3]

- Improvements
  - Used memset to initialize the structure before using.
  - Added function definition comment in c file.
  - Updated source file license to SPDX BSD_3.
  - Corrected capital mistake of Fifo and fifo.
  - Reset the MCAN module in LPC drivers after clock enable.

## [2.0.2]

- Bug Fixes
  - Picked MISRA fixed in release 8 branch.
  - MISRA C 2012 fixed regarding FlexCAN and MCAN address update.
- Improvements
  - Implemented for delay/retry in MCAN driver.

## [2.0.1]

- Improvements
  - LPC54608 chip did not support the FD feature, so added a feature macro for it.

## [2.0.0]

- Initial version.
