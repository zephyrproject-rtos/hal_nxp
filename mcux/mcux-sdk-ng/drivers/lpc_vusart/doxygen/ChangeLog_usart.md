# USART

## [2.3.1]

- Improvements
  - Use separate data for TX and RX in usart_transfer_t.
- Bug Fixes
  - Fixed bug that when ring buffer is used, if some data is received in ring buffer first before calling
    USART_TransferReceiveNonBlocking, the received data count returned by USART_TransferGetReceiveCount is wrong.

## [2.3.0]

- New Features
  - Modified usart_config_t, USART_Init and USART_GetDefaultConfig APIs so that the hardware flow control can be
    enabled during module initialization.

## [2.2.0]

- Bug Fixes
  - Fixed compiling error in USART_TransferSendDMA and USART_TransferReceiveDMA.
- Improvements
  - Modified USART_TransferHandleIRQ so that txState will be set to idle only when all data has been sent out to bus.
  - Modified USART_TransferGetSendCount so that this API returns the real byte count that USART has sent out rather
    than the software buffer status.
  - Added timeout mechanism when waiting for certain states in transfer driver.
  - Added check for baud rate's accuracy that returns kStatus_USART_BaudrateNotSupport when the best achieved baud
    rate is not within 3% error of configured baud rate.

## [2.1.1]

- Improvements
  - Deleted useless if condition.
  - Added check for kUSART_TxIdleFlag in USART_TransferHandleIRQ to ensure all the data would be sent out
    to bus before triggering call back.
- Bug Fixes
  - Fixed the sign-compare warning in USART_TransferHandleIRQ.
  - Eliminated IAR Pa082 warning from USART_TransferGetRxRingBufferLength and USART_TransferHandleIRQ.
  - Modified USART_ReadBlocking so that if more than one receiver errors occur, all status flags will be
    cleared and the most severe error status will be returned.
  - Fixed MISRA issues.
    - Fixed issue 2.2, 8.4, 5.7, 10.1, 10.3, 10.4, 10.8, 11.6, 11.9, 14.4, 16.4, 17.7.

## [2.1.0]

- New Features
  - Added new feature to allow users to configure the USART to synchronous transfer in both master and slave mode.

## [2.0.1]

- New Features
  - Added control macro to enable/disable the RESET and CLOCK feature in current driver.
  - Added a new API to allow users to enable the CTS which determines whether CTS is used for flow control.

## [2.0.0]

- Initial version.
