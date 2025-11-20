# LIN

## [2.2.4]

- Improvements
  - Added Kconfig item LIN_LPUART_TRANSMISSION_COMPLETE_TIMEOUT, user can configure it to
    none zero value for the while loop to break after retrying LIN_LPUART_TRANSMISSION_COMPLETE_TIMEOUT times.

## [2.2.3]

- Improvements
  - Conditionally compile interrupt handling code to solve the problem of using this driver on CPU cores that do not support interrupts.

## [2.2.2]

- Bug Fixes
  - Fixed bug in LIN_LPUART_Init, while disabling the LPUART ERROR IRQ, the variable g_linLpuartErrIrqId should
    be used instead of g_linLpuartRxTxIrqId. This is a typo issue.

## [2.2.1]

- Bug Fixes
  - Fixed bug in LIN_LPUART_GetTransmitStatus and LIN_LPUART_GetReceiveStatus, if the current event ID is
    timeout, then the timeout service has already been executed, LIN_TIMEOUT should be returned.
  - Fixed bug in LIN_LPUART_AutobaudTimerValEval, if the calculated MasterBaudrate is 0 which means the baudrate
    is not supported, then there is no need to update the baudrate configuration, just set the node to idle state.
  - Fixed issue in LIN_LPUART_CheckWakeupSignal, the check on the timerGetTimeIntervalCallback should be executed
    after the first falling edge rather than the second.

## [2.2.0]

- Bug Fixes
  - Fixed bug that for lin slave once break field is detected before completing the last frame no error status is
    raised.

## [2.1.1]

- Bug Fixes
  - Fixed the MISRA C-2012 issue.
    - Fixed rules, containing: rule-10.8, 10.3.
  - Fixed bug in LIN_MakeChecksumByte, when frame ID is 0x3D the PID should be 0x7D.

## [2.1.0]

- Improvements
  - Updated the driver to support LIN stack.
    - For LIN_LPUART_Init() function, if run successfully, the return is LIN_SUCCESS instead of LIN_INITIALIZED.
    - Changed the LIN event ID name from "LIN_RECV_SYNC_OK" to "LIN_SYNC_OK".
    - Changed the LIN event ID name from "LIN_RECV_SYNV_ERROR" to "LIN_SYNV_ERROR".
    - Changed the definition macro name "LIN_MAKE_PARITY" to "MAKE_PARITY".
    - Changed the definition macro name "LIN_CHECK_PARITY" to "CHECK_PARITY".
- Bug Fixes
  - Fixed the MISRA C-2012 issue.
    - Fixed rules, containing: rule-17.7, rule-14.4, rule-11.9, rule-10.4, rule-10.3, rule-10.7, rule-10.1, rule-8.6,
      rule-8.4, rule-11.3, rule-10.8, and rule-16.1.

## [2.0.1]

- Bug Fixes
  - Fixed bug where resting LPUART FIFO initializes the LPUART module.

## [2.0.0]

- Initial version.
