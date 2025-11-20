# BEE

## [2.0.2]

- Bug Fixes
  - Fix MISRA issue.

## [2.0.1]

- Bug Fixes
  - Fixed bug in key user key loading sequence. BEE must be enabled during loading of user key.
  - Fixed typos in comments.
- New Features
  - Added configuration setting for endian swap, access permission and region security level.
- Improvements
  - Setting of AES nonce was moved from BEE_SetRegionKey() into separate BEE_SetRegionNonce() function.
  - Changed handling of region settings. Both regions are configured simultaneously by BEE_SetConfig() function.
    Configuration of FAC start and end address using IOMUXC_GPRs was moved to application.
  - Default value for region address offset was changed to 0.

## [2.0.0]

- Initial version.
