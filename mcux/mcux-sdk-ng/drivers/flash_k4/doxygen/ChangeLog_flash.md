# FLASH

## [2.3.3]
- Improvements
  - Added timeout for while loop in flash_command_pre_sequence, flash_command_sequence,
    flash_erase_sequence, flash_pgm_sequence and flash_command_pre_sequence API.

## [2.3.2]

- Improvement
 - Enabled the kFLASH_PropertyPflash1SectorSize properity support in FLASH_GetProperty API.

## [2.3.1]

- Improvement
 - Clear flash cache before every erase to prevent the possibility of returning stale data.

## [2.3.0]

- New features
 - Add support for MCX N series

## [2.2.1]

- Improvement
  - To fix the potential unsigned integer overflow in the operation, added a check to ensure that the
    addition does not exceed the maximum value.

## [2.2.0]

- New Features
  - Add the support for MW30.

## [2.1.2]

- Improvement
  - Add the support for KW47/MCXW72 phantoms.

## [2.1.1]

- Improvement
  - Add the conditional compiling flag '#if defined(RF_FMU)' to make the driver be compatible with the non-radio phantoms.

## [2.1.0]

- Bug Fixes
  - Fix flash driver run error in flash memory

## [2.0.0]

- Initial version.
