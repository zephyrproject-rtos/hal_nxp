# CASSPER

## [2.2.4]

- Fix MISRA-C 2012 issue.

## [2.2.3]

- Added macro into CASPER_Init and CASPER_Deinit to support devices without clock and reset control.

## [2.2.2]

- Enable hardware interleaving to RAMX0 and RAMX1 for CASPER by feature macro FSL_FEATURE_CASPER_RAM_HW_INTERLEAVE

## [2.2.1]

- Fix MISRA C-2012 issue.

## [2.2.0]

- Rework driver to support multiple curves at once.

## [2.1.0]

- Add ECC NIST P-521 elliptic curve.

## [2.0.10]

- Fix MISRA C-2012 issue.

## [2.0.9]

- Remove unused function Jac_oncurve().
- Fix ECC384 build.

## [2.0.8]

- Add feature macro for CASPER_RAM_OFFSET.

## [2.0.7]

- Fix MISRA C-2012 issue.

## [2.0.6]

- Bug Fixes
  - Fix IAR Pa082 warning

## [2.0.5]

- Bug Fixes
  - Fix sign-compare warning

## [2.0.4]

- For GCC compiler, enforce O1 optimize level, specifically to remove strict-aliasing option.
  This driver is very specific and requires -fno-strict-aliasing.

## [2.0.3]

- Bug Fixes
  - Fixed the bug for KPSDK-28107 RSUB, FILL and ZERO operations not implemented in enum _casper_operation.

## [2.0.2]

- Bug Fixes
  - Fixed KPSDK-25015 CASPER_MEMCPY hard-fault on LPC55xx when both source and destination
    buffers are outside of CASPER_RAM.

## [2.0.1]

- Bug Fixes
  - Fixed the bug that KPSDK-24531 double_scalar_multiplication() result may be all zeroes
    for some specific input.

## [2.0.0]

- Initial version.
