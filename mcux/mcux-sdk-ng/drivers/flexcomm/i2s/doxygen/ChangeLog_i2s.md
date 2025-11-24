# I2S

## [2.3.2]

- Bug Fixes
  - Fixed warning for comparison between pointer and integer.

## [2.3.1]

- Bug Fixes
  - Updated the value of TX/RX software transfer state machine after transfer contents are submitted to avoid race condition.

## [2.3.0]

- Improvements
  - Added api I2S_InstallDMADescriptorMemory/I2S_TransferSendLoopDMA/I2S_TransferReceiveLoopDMA to support loop transfer.
  - Added api I2S_EmptyTxFifo to support blocking flush tx fifo.
  - Updated api I2S_TransferAbortDMA by removed the blocking flush tx fifo from this function.
- Bug Fixes
  - Removed the while loop in abort transfer function to fix the dead loop issue under specific user case.

## [2.2.2]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 8.4.

## [2.2.1]

- Improvements
  - Added feature FSL_FEATURE_FLEXCOMM_INSTANCE_I2S_SUPPORT_SECONDARY_CHANNELn for the SOC has parts of instance support secondary channel.
- Bug Fixes
  - Added volatile statement for the state variable of i2s_handle and enable the mainline channel pair before enable interrupt to avoid the issue of code excution reordering which may cause the interrupt generated unexpectedly.

## [2.2.0]

- Improvements
  - Added 8/16/24 bits mono data format transfer support in I2S driver.
  - Added new apis I2S_SetBitClockRate.
- Bug Fixes
  - Fixed the PA082 build warning.
  - Fixed the sign-compare warning.
  - Fixed violations of the MISRA C-2012 rules 10.4, 10.8, 11.9, 10.1, 11.3, 13.5, 11.8, 10.3, 10.7.
  - Fixed the Operand don't affect result Coverity issue.

## [2.1.0]

- Improvements
  - Added a feature for the FLEXCOMM which supports I2S and has interconnection with DMIC.
  - Used a feature to control PDMDATA instead of I2S_CFG1_PDMDATA.
  - Added member bytesPerFrame in i2s_dma_handle_t, used for DMA transfer width configure,
    instead of using sizeof(uint32_t) hardcode.
  - Used the macro provided by DMA driver to define the I2S DMA descriptor.
- Bug Fixes
  - Fixed the issue that I2S DMA driver always generated duplicate callback.

## [2.0.3]

- New Features
  - Added a feature to remove configuration for the second channel on LPC51U68.

## [2.0.2]

- New Features
  - Added ENABLE_IRQ handle after register I2S interrupt handle.

## [2.0.1]

- Improvements
  - Unified the component full name to FLEXCOMM I2S (DMA) driver.

## [2.0.0]

- Initial version.
