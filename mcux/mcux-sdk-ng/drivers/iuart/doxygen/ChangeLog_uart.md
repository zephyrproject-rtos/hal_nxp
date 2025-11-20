# UART

## [2.3.2]

- Improvements
  - Make driver aarch64 compatible

## [2.3.1]

- Improvements
  - Use separate data for TX and RX in uart_transfer_t.
- Bug Fixes
  - Fixed bug that when ring buffer is used, if some data is received in ring buffer first before calling
    UART_TransferReceiveNonBlocking, the received data count returned by UART_TransferGetReceiveCount is wrong.

## [2.3.0]

- Bug Fixes
  - Fixed DMA transfer blocking issue by enabling tx idle interrupt after DMA transmission finishes.

## [2.2.1]

- Bug Fixes
  - Fixed MISRA 2012 rule 10.4 violation.

## [2.2.0]

- New Features
  - Modified uart_config_t, UART_Init and UART_GetDefaultConfig APIs so that the RTS and CTS used for hardware flow
    control can be enabled during module initialization.
  - Added API UART_SetRxRTSWatermark so that the water mark level of RTS deassertion can be configured.

## [2.1.1]

- Bug Fixes
  - Fixed MISRA 8.5 violation.

## [2.1.0]

- Improvements
  - Added timeout mechanism when waiting for certain states in transfer driver.

## [2.0.2]

- Improvements
  - Added check for transmission complete in UART_WriteBlocking, UART_TransferHandleIRQ and UART_SendSDMACallback
    to ensure all the data would be sent out to bus.
  - Modified UART_ReadBlocking so that if more than one receiver errors occur, all status flags will be cleared
    and the most severe error status will be returned.
- Bug Fixes
  - Fixed MISRA issues.
    - Fixed rules 10.1, 10.3, 10.4, 10.6, 10.7, 10.8, 11.9, 14.4.

## [2.0.1]

- Bug Fixes
  - Memset local variable SDMA transfer configuration structure to make sure unused members in structure are cleared.

## [2.0.0]

- Initial version.
