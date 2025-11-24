# I3C_DMA

## [2.1.9]

- Improvements
  - Fixed Coverity CERT-C violations.

## [2.1.8]

- Bug Fixes
  - Updated the logic to handle Rx termination and complete event to adapt different situation.
- Improvements
  - Added the MCTRLDONE flag check after STOP request to ensure the completion of whole transfer operation.

## [2.1.7]

- Bug Fixes
  - Fixed the issue to use subaddress to read/write data with RT500/600 DMA.

## [2.1.6]

- Improvements
  - Added the FSL_FEATURE_I3C_HAS_NO_MASTER_DMA_WDATA_REG to select the correct register to write data based on specific Soc.

## [2.1.5]

- New features
  - Supported I3C HDR-DDR transfer with DMA.
- Improvements
  - Added workaround for RT500/600 I3C DMA transfer.
  - Removed I3C IRQ handler calling in the Tx EDMA callback. Previously driver doesn't use the END byte which can trigger the complete
    interrupt for controller sending and receiving, now let I3C event handler deal with I3C events.
  - Used linked DMA to transfer all I3C subaddress and data without handling of intermediate states, simplifying code logic.
  - Prepare the Tx DMA before I3C START to ensure there's no time delay between START and transmitting data.

## [2.1.4]

- Improvements
  - Used linked DMA transfer to reduce the latency between DMA transfers previous data and the END byte.

## [2.1.3]

- Bug Fixes
  - Fixed the MISRA issue rule 10.4, 11.3.

## [2.1.2]

- Bug Fixes
  - Fixed the issue that I3C slave send the last byte data without using the END type register.

## [2.1.1]

- Bug Fixes
  - Fixed MISRA issue rule 9.1.

## [2.1.0]

- Improvements
  - Deleted legacy IBI data request code.

## [2.0.1]

- Bug Fixes
  - Fixed issue that bus STOP occurs when Tx FIFO still takes data.
- Improvements
  - Fixed the build warning due to armgcc strict check.

## [2.0.0]

- Initial version.
