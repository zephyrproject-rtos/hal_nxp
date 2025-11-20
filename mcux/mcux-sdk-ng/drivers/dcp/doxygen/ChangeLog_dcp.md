# DCP

## [2.1.7]

- Bug Fix
  - Reduce optimization level for critical functions working with SRF.

## [2.1.6]

- Bug Fix
  - MISRA C-2012 issue fix.

## [2.1.5]

- Improvements
  - Added support when DCACHE enabled. Input and output buffers should be in non-cached memory or handled properly (DCACHE Clean and Invalidate).

## [2.1.4]

- Bug Fix
  - Fix CRC-32 computation issue on the code's block boundary size.

## [2.1.3]

- Bug Fix
  - MISRA C-2012 issue fixed: rule 10.1, 10.3, 10.4, 11.9, 14.4, 16.4 and 17.7.

## [2.1.2]

- Bug Fix
  - Fix sign-compare warning in dcp_reverse_and_copy.

## [2.1.1]

- Improvements
  - Added DCP status clearing when channel operation is complete.

## [2.1.0]

- New Features
  - Added byte/word swap feature for key, input, and output data.

## [2.0.0]

- Initial version.
