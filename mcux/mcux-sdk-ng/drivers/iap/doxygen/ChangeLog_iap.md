# IAP

## [2.0.7]

- Bug Fixes
  - Fixed IAP_ReinvokeISP bug that can't support UART ISP auto baud detection.

## [2.0.6]

- Bug Fixes
  - Fixed IAP_ReinvokeISP wrong parameter setting.

## [2.0.5]

- New Feature
  - Added support config flash memory access time.

## [2.0.4]

- Bug Fixes
  - Fixed the violations of MISRA 2012 rules 9.1

## [2.0.3]

- New Features
  - Added support for LPC 845's FAIM operation.
  - Added support for LPC 80x's fixed reference clock for flash controller.
  - Added support for LPC 5411x's Read UID command useless situation.
- Improvements
  - Improved the document and code structure.
- Bug Fixes
  - Fixed the violations of MISRA 2012 rules:
    - Rule 10.1 10.3 10.4 17.7

## [2.0.2]

- New Features
  - Added an API to read generated signature.
- Bug Fixes
  - Fixed the incorrect board support of IAP_ExtendedFlashSignatureRead().

## [2.0.1]

- New Features
  - Added an API to read factory settings for some calibration registers.
- Improvements
  - Updated the size of result array in part APIs.

## [2.0.0]

- Initial version.
