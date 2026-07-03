# FLASH

## [2.4.1]

- Improvement
  - Fixed MISRA C-2012 rule 8.6, 21.15 and 11.6.
  - Fixed MSG CERT INT30-C.

## [2.4.0]

- New Features
  - Add asynchronous flash mode support for non-blocking flash operations.
    Async mode allows applications to initiate flash operations and continue execution while the flash controller completes the operation in the background.

## [2.3.5]

- Improvement
  - Add flash_cache_disable implementation for KW45, KW47 platforms.
    In the absence of flash cache disable functionality, the flash module will use software workaround to prevent stale data from being returned, by disabling the cache and re-enabling it.

## [2.3.4]

- Improvement
  - Add the support for KW43/MCXW70 platforms.

## [2.3.3]
- Improvements
  - Added timeout for while loop in flash_command_pre_sequence, flash_command_sequence,
    flash_erase_sequence, flash_pgm_sequence and flash_command_pre_sequence API.

## [2.3.2]

- Improvement
 - Enabled the kFLASH_PropertyPflash1SectorSize property support in FLASH_GetProperty API.

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
