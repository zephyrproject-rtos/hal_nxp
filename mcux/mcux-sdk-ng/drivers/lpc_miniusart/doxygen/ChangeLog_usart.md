# USART

## [2.5.2]

- Improvements
  - Fixed coverity issues.

## [2.5.1]

- Improvements
  - Fixed doxygen warning in USART_SetRxIdleTimeout.

## [2.5.0]

- New Features
  - Supported new feature of rx idle timeout.

## [2.4.0]

- Improvements
  - Used separate data for TX and RX in usart_transfer_t.
- Bug Fixes
  - Fixed bug that when ring buffer is used, if some data is received in ring buffer first before calling
    USART_TransferReceiveNonBlocking, the received data count returned by USART_TransferGetReceiveCount is wrong.

## [2.3.0]

- New Features
  - Modified usart_config_t, USART_Init and USART_GetDefaultConfig APIs so that the hardware flow control can be
    enabled during module initialization.

## [2.2.0]

- Improvements
  - Added timeout mechanism when waiting for certain states in transfer driver.
  - Fixed MISRA 10.4 issues.

## [2.1.1]

- Bug Fixes
  - Fixed the bug that in USART_SetBaudRate best_diff rather than diff should be used to compare with calculated
    baudrate.
  - Eliminated IAR pa082 warnings from USART_TransferGetRxRingBufferLength and USART_TransferHandleIRQ.
  - Fixed MISRA issues.
- Improvements
  - Rounded up the calculated sbr value in USART_SetBaudRate to achieve more acurate baudrate setting.
  - Modified USART_ReadBlocking so that if more than one receiver errors occur, all status flags will be cleared
    and the most severe error status will be returned.

## [2.1.0]

- New Features
  - Added new APIs to allow users to configure the USART continuous SCLK feature in synchronous mode transfer.

## [2.0.1]

- Bug Fixes
  - Fixed the repeated reading issue of the STAT register while dealing with the IRQ routine.
- New Features
  - Added macro gate "FSL_SDK_ENABLE_USART_DRIVER_TRANSACTIONAL_APIS" to enable/disable the transactional APIs,
    which helps reduce the code size when no nonblocking transfer is used. Enabled default configuration.
  - Added a control macro to enable/disable the RESET and CLOCK code in current driver.
  - Added macro switch gate "FSL_SDK_USART_DRIVER_ENABLE_BAUDRATE_AUTO_GENERATE" to enable/disable
    the baud rate to generate automatically. Disabling this feature will help reduce the code size to a
    certain degree. Default configuration enables auto generating of baud rate.
  - Added the check of baud rate while initializing the USART. If the baud rate calculated is not precise, the
    software assertion will be triggered.
  - Added a new API to allow users to enable the CTS, which determines whether CTS is used for flow control.

## [2.0.0]

- Initial version.
