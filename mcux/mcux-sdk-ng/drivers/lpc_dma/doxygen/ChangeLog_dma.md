# LPC_DMA

## [2.5.4]

- Bug Fixes
  - Fixed coverity issues with CERT INT30-C, CERT INT31-C compliance.

## [2.5.3]

- Improvements
  - Add assert in DMA_SetChannelXferConfig to prevent XFERCOUNT value overflow.

## [2.5.2]

- Bug Fixes
  - Use separate "SET" and "CLR" registers to modify shared registers for all channels, in case of thread-safe issue.

## [2.5.1]

- Bug Fixes
  - Fixed violation of the MISRA C-2012 rule 11.6.

## [2.5.0]

- Improvements
  - Added a new api DMA_SetChannelXferConfig to set DMA xfer config.

## [2.4.4]

- Bug Fixes
  - Fixed the issue that DMA_IRQHandle might generate redundant callbacks.
  - Fixed the issue that DMA driver cannot support channel bigger then 32.
  - Fixed violation of the MISRA C-2012 rule 13.5.

## [2.4.3]

- Improvements
  - Added features FSL_FEATURE_DMA_DESCRIPTOR_ALIGN_SIZEn/FSL_FEATURE_DMA0_DESCRIPTOR_ALIGN_SIZE/FSL_FEATURE_DMA1_DESCRIPTOR_ALIGN_SIZE to support the descriptor align size not constant in the two instances.

## [2.4.2]

- Bug Fixes
  - Fixed violation of the MISRA C-2012 rule 8.4.

## [2.4.1]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 5.7, 8.3.

## [2.4.0]

- Improvements
  - Added new APIs DMA_LoadChannelDescriptor/DMA_ChannelIsBusy to support polling transfer case.
- Bug Fixes
  - Added address alignment check for descriptor source and destination address.
  - Added DMA_ALLOCATE_DATA_TRANSFER_BUFFER for application buffer
    allocation.
  - Fixed the sign-compare warning.
  - Fixed violations of the MISRA C-2012 rules 18.1, 10.4, 11.6, 10.7, 14.4, 16.3, 20.7, 10.8, 16.1, 17.7, 10.3, 3.1, 18.1.

## [2.3.0]

- Bug Fixes
  - Removed DMA_HandleIRQ prototype definition from header file.
  - Added DMA_IRQHandle prototype definition in header file.

## [2.2.5]

- Improvements
  - Added new API DMA_SetupChannelDescriptor to support configuring wrap
    descriptor.
  - Added wrap support in function DMA_SubmitChannelTransfer.

## [2.2.4]

- Bug Fixes
  - Fixed the issue that macro DMA_CHANNEL_CFER used wrong parameter to calculate
    DSTINC.

## [2.2.3]

- Bug Fixes
  - Improved DMA driver Deinit function for correct logic order.
- Improvements
  - Added API DMA_SubmitChannelTransferParameter to support creating head
    descriptor directly.
  - Added API DMA_SubmitChannelDescriptor to support ping pong transfer.
  - Added macro DMA_ALLOCATE_HEAD_DESCRIPTOR/DMA_ALLOCATE_LINK_DESCRIPTOR to
    simplify DMA descriptor allocation.

## [2.2.2]

- Bug Fixes
  - Do not use software trigger when hardware trigger is enabled.

## [2.2.1]

- Bug Fixes
  - Fixed Coverity issue.

## [2.2.0]

- Improvements
  - Changed API DMA_SetupDMADescriptor to non-static.
  - Marked APIs below as deprecated.
    - DMA_PrepareTransfer.
    - DMA_Submit transfer.
  - Added new APIs as below:
    - DMA_SetChannelConfig.
    - DMA_PrepareChannelTransfer.
    - DMA_InstallDescriptorMemory.
    - DMA_SubmitChannelTransfer.
    - DMA_SetChannelConfigValid.
    - DMA_DoChannelSoftwareTrigger.
    - DMA_LoadChannelTransferConfig.

## [2.0.1]

- Improvements
  - Added volatile for DMA descriptor member xfercfg to avoid optimization.

## [2.0.0]

- Initial version.
