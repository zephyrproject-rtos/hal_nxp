# POWERQUAD

## [2.2.1]

- Bug Fixes
  - Fixed CERT-C issues.

## [2.2.0]

- New Features
  - Added new API PQ_Arctan2Fixed.

## [2.1.1]

- Bug Fixes
  - Remove PQ_WaitDone from PQ_ArctanFixed and PQ_ArctanhFixed because it is unnecessary.

## [2.1.0]

- Improvements
  - Fixed typo issue for biquad related function name.
  - Changed operator from "%" into "&" to reduce heavy cycle for biquad functions.

## [2.0.5]

- Improvements
  - Added a note in driver for FIR that powerquad has a hardware limitation, when using it for FIR increment calculation, the address of pSrc needs to be a continuous address.

## [2.0.4]

- Improvements
  - Supported the platforms which don't have PowerQuad clock and reset control.

## [2.0.3]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 8.4, 10.1, 10.3, 10.4, 10.6, and so on.

## [2.0.2]

- Bug Fixes
  - Fixed array size issue in fsl_powerquad_data.h file.
  - Fixed vector function pipeline issue.

## [2.0.1]

- Bug Fixes
  - Fixed build error in C++ mode.

## [2.0.0]

- Initial version.


# POWERQUAD_CMSIS

## [2.1.0]

- Improvements
  - Support use different API name, to work together with CMSIS DSP software implementation.

## [2.0.4]

- Inherit the SDK 2.0 driver.
