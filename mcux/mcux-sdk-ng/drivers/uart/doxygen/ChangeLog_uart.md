# UART

## [2.5.1]

- Improvements
  - Use separate data for TX and RX in uart_transfer_t.
- Bug Fixes
  - Fixed bug that when ring buffer is used, if some data is received in ring buffer first before calling
    UART_TransferReceiveNonBlocking, the received data count returned by UART_TransferGetReceiveCount is wrong.

## [2.5.0]

- New Features
  - Added APIs UART_GetRxFifoCount/UART_GetTxFifoCount to get rx/tx FIFO data count.
  - Added APIs UART_SetRxFifoWatermark/UART_SetTxFifoWatermark to set rx/tx FIFO water mark.
- Bug Fixes
  - Fixed bug of race condition during UART transfer using transactional APIs, by disabling and re-enabling the
    global interrupt before and after critical operations on interrupt enable registers.
  - Fixed DMA/eDMA transfer blocking issue by enabling tx idle interrupt after DMA/eDMA transmission finishes.

## [2.4.0]

- New Features
  - Added APIs to configure 9-bit data mode, set slave address and send address.

## [2.3.0]

- Bug Fixes
  - Fixed the bug that, when framing/parity/noise/overflow flag or idle line detect flag is set, receive
    FIFO should be flushed to avoid FIFO pointer being in unknown state, since FIFO has no valid data.
- Improvements
  - Modified UART_TransferHandleIRQ so that txState will be set to idle only when all data has been sent out to bus.
  - Modified UART_TransferGetSendCount so that this API returns the real byte count that UART has sent out rather
    than the software buffer status.
  - Added timeout mechanism when waiting for certain states in transfer driver.

## [2.2.0]

- New Features
  - Added UART hardware FIFO enable/disable API.
- Improvements
  - Added check for kUART_TransmissionCompleteFlag in UART_TransferHandleIRQ, UART_SendEDMACallback and
    UART_TransferSendDMACallback to ensure all the data would be sent out to bus.
- Bug Fixes
  - Eliminated IAR Pa082 warnings from UART_TransferGetRxRingBufferLength, UART_GetEnabledInterrupts,
    UART_GetStatusFlags and UART_TransferHandleIRQ.
  - Added code in UART_ReadBlocking so that if more than one receiver errors occur, all status flags will
    be cleared and the most severe error status will be returned.
  - Fixed MISRA issues.
    - Fixed rules 10.1, 10.3, 10.4, 14.4, 11.6, 17.7.

## [2.1.6]

- Bug Fixes
  - Fixed the issue of register's being in repeatedly reading status while performing the IRQ routine.

## [2.1.5]

- Improvements
  - Added hardware flow control function support.
  - Added idle-line-detecting feature in UART_TransferNonBlocking function. If an idle line is detected, a callback
    will be triggered with status kStatus_UART_IdleLineDetected returned. This feature may be useful when the
    number of received bytes is less than the expected receive data size. Before triggering the callback, data in
    the FIFO is read out (if it has FIFO), and no interrupt will be disabled except for the case that the receive
    data size reaches 0.
  - Enabled the RX FIFO watermark function. With the idle-line-detecting feature enabled, you can set the watermark
    value to whatever you want (should not be bigger than the RX FIFO size). Data is then received and a callback
    will be triggered when data receive ends.

## [2.1.4]

- Improvements
  - Changed parameter type in UART_RTOS_Init() struct rtos_uart_config --> uart_rtos_config_t.
- Bug Fixes
  - Disabled UART receive interrupt instead of global interrupt when reading data from ring buffer.
    With ring buffer used, receive nonblocking will disable global interrupt to protect
    the ring buffer. This has a negative effect on other IPs using interrupt.

## [2.1.3]

- New Features
  - Added RX framing error and parity error status check when using interrupt transfer.

## [2.1.2]

- Bug Fixes
  - Fixed baud rate fine adjust bug to make the computed baud rate more accurate.

## [2.1.1]

- Bug Fixes
  - Removed needless check of event flags and assert in UART_RTOS_Receive.
  - Always waited for RX event flag in UART_RTOS_Receive.

## [2.1.0]

- Improvements
  - Added transactional API.

## [2.0.0]

- Initial version.
