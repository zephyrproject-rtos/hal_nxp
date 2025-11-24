# TSI_V4

## [2.1.3]

- Bug Fixes
  - Fixed the violations of MISRA C-2012 rules:
    - Rule 10.1, 10.3, 10.4, 10.8, 12.2, 14.4, 17.7.

## [2.1.2]

- Bug Fixes
  - Fixed w1c issues in status handling API.
  - Fixed register naming error in API "static inline void TSI_EnableEndOfScanDmaTransferOnly(TSI_Type *base, bool
    enable)".
  - Removed redundant status flags clear APIs when enable interrupts.

## [2.1.1]

- New Features
  - Changed void TSI_DeInit(TSI_Type *base) to void TSI_Deinit(TSI_Type *base).

## [2.0.1]

- Other Changes
  - Changed default configuration structure member order.
