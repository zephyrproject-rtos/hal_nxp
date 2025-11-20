# LPSCI

## [2.1.1]

- Improvements
  - Use separate data for TX and RX in lpsci_transfer_t.

## [2.1.0]

- Bug Fixes
  - Fixed DMA transfer blocking issue by enabling tx idle interrupt after DMA transmission finishes.

## [2.0.8]

- Improvements
  - Modified LPSCI_TransferHandleIRQ so that txState will be set to idle only when all data has been sent out to bus.
  - Modified LPSCI_TransferGetSendCount so that this API returns the real byte count that LPSCI has sent out rather
    than the software buffer status.
- Bug Fixes
  - Fixed bug of race condition during LPSCI transfer using transactional APIs, by disabling and re-enabling the
    global interrupt before and after critical operations on interrupt enable register.

## [2.0.7]

- Improvements
  - Added check for kLPSCI_TransmissionCompleteFlag in LPSCI_WriteBlocking, LPSCI_TransferHandleIRQ and
    LPSCI_TransferSendDMACallback to ensure all the data would be sent out to bus.
  - Modified LPSCI_ReadBlocking so that if more than one receiver errors occur, all status flags will be
    cleared and the most severe error status will be returned.
- Bug Fixes
  - Eliminated IAR Pa082 warnings from LPSCI_TransferGetRxRingBufferLength, LPSCI_GetEnabledInterrupts,
    LPSCI_GetStatusFlags and LPSCI_TransferHandleIRQ.

## [2.0.6]

- Improvements
  - Removed the operation of enabling the TX and RX interrupt when setting the TX and RX DMA to request enabled.
    Affected APIs are LPSCI_EnableTxDMA() and LPSCI_EnableRxDMA().

## [2.0.5]

- Bug Fixes
  - Fixed the issue of register's being in repeated reading status while dealing with the IRQ routine.

## [2.0.4]

- New Features
  - Added idle-line-detecting feature in LPSCI_TransferNonBlocking function. If an idle line is detected, a
    callback will be triggered with status kStatus_LPSCI_IdleLineDetected returned. This feature may be useful when
    the received Bytes is less than the expected received data size. Before triggering the callback, data in the
    FIFO (if it has FIFO) is read out, and no interrupt will be disabled, except for that the received data size
    reaches 0.

## [2.0.3]

- Improvements
  - Changed parameter type in LPSCI_RTOS_Init() from struct rtos_lpsci_config to lpsci_rtos_config_t.
- Bug Fixes
  - When reading data from ring buffer, disabled LPSCI receive interrupt instead of disabling all NVICs to avoid
    the possible negative effect on other IPs which are using interrupt.

## [2.0.2]

- Improvements
  - Added RX framing error and parity error status check when using interrupt transfer.

## [2.0.1]

- Improvements
  - Updated baudrate setting code to check whether the value is valid or not.
    Do not change baudrate and return values if the value is not valid.
  - Removed needless check of event flags and assert in LPSCI_RTOS_Receive.
  - Always wait for RX event flag in LPSCI_RTOS_Receive.

## [2.0.0]

- Initial version.
