# ELCDIF

## [2.1.0]

- New Features
  - Added API ELCDIF_SetPixelComponentOrder to support configure pixel component order.

## [2.0.7]

- Bug Fixes
  - Fixed faulty operation of CTRL1 in ELCDIF_RgbModeSetPixelFormat.

## [2.0.6]

- Bug Fixes
  - Fixed bug in ELCDIF_RgbModeStop that the API shall return until RUN bit
    is cleared, so that the RGB mode is properly stopped.

## [2.0.5]

- Bug Fixes
  - Fixed the violations of MISRA 2012 advisory rules.

## [2.0.4]

- Improvements
  - Increase outstanding transactions for better performance.
  - Added memory address conversion to support buffers which could only be
    accessed using alias address by non-core masters.

## [2.0.3]

- Improvements
  - Supported the platforms which don't have PXP handshake feature.
- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 17.7.

## [2.0.2]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 3.1, 8.4, 10.1, 10.6, 10.7,
    10.8, 14.4, 17.7
  - Removed hardcode delay in function ELCDIF_Reset.

## [2.0.1]

- Improvements
  - Added the function ELCDIF_RgbModeSetPixelFormat.

## [2.0.0]

- Initial version.
