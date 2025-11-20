# I3C_EDMA

## [2.2.12]

- Bug Fixes
  - Fixed the issue that EDMA transfer configuration use wrong parameter.

## [2.2.11]

- Improvements
  - Fixed Coverity CERT-C violations.

## [2.2.10]

- Bug Fixes
  - Fixed the issue that slave start event is cleared when it has not been handled.
- Added
  - Supported I3C HDR-DDR transfer with EDMA.
- Changed
  - Used linked EDMA to transfer all I3C subaddress and data without handling of intermediate states, simplifying code logic.
  - Prepare DMA before I3C START to ensure there's no time delay between START and transmitting data.
  - Added the MCTRLDONE flag check after START and STOP request to ensure all states are handled properly.

## [2.2.9]

- Bug Fixes
  - Fixed MISRA issue rule 11.3.
  - Added the master control done flag waiting code after STOP in case the bus is not idle when transfer function finishes.

## [2.2.8]

- Improvements
  - Removed I3C IRQ handler calling in the EDMA callback. Previously driver doesn't use the END byte which can trigger the STOP
    interrupt for controller sending and receiving, now let I3C event handler deal with all I3C events.
- Bug Fixes
  - Fixed the bug that the END type Tx register is not used when command length or data length is one byte.

## [2.2.7]

- Bug Fixes
  - Fixed MISRA issue rule 11.6.

## [2.2.6]

- New features
  - Added the I3C private read/write with 0x7E address as start.

## [2.2.5]

- Improvements
  - Added the workaround for RT1180 I3C EDMA issue ERR052086.

## [2.2.4]

- Bug Fixes
  - Fixed the issue that I3C master sends the last byte data without using the END type register.

## [2.2.3]

- Bug Fixes
  - Fixed issue that slave polulates the last byte when Tx FIFO may be full.

## [2.2.2]

- Bug Fixes
  - Fixed I3C MISRA issue rule 10.4, 11.3.

## [2.2.1]

- Bug Fixes
  - Fixed the issue that I3C slave send the last byte data without using the END type register.
- Improvements
  - There's no need to reserve two bytes FIFO for DMA transfer which is for IP issue workaround.

## [2.2.0]

- Improvements
  - Deleted legacy IBI data request code.

## [2.1.0]

- Bug Fixes
  - Fixed MISRA issue rule 8.4, 8.6, 11.8.

## [2.0.1]

- Bug Fixes
  - Fixed MISRA issue rule 9.1.

## [2.0.0]

- Initial version.
