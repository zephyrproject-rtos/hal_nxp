# LCDIFv2

## [2.3.3]

- Other Changes
  - Removed PDI_PARA register operation due to IP change.

## [2.3.2]

- Bug Fixes
  - Fixed the violations of MISRA 2012 advisory rules.

## [2.3.1]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 10.4.

## [2.3.0]

- New Features:
  - Added API to calculate global alpha based on desired blended alpha.

## [2.2.3]

- Improvements
  - Added memory address conversion to support buffers which could only be
    accessed using alias address by non-core masters.

## [2.2.2]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 10.1, 10.2, 10.4, 10.6, 12.2.

## [2.2.1]

- Improvements
  - Updated for the new LCDIFV2_Type structure.

## [2.2.0]

- Bug Fixes
  - Fixed LCDIFV2_GetPorterDuffConfig issue that does not set color mode
    correctly.
- Other Changes
  - Removed the store functions.

## [2.1.1]

- Bug Fixes
  - Fixed the issue that LCDIFV2_SetLut could not access the last index.

## [2.1.0]

- New Features:
  - Added function to get Porter Duff configuration.

## [2.0.1]

- Bug Fixes
  - Fixed the issue that register value not reset by
    LCDIFV2_Deinit and LCDIFV2_Reset.

## [2.0.0]

- Initial version.
