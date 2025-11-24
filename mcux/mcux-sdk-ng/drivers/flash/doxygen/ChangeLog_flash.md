# FLASH

## [3.3.0]
- New Feature
  - Support for EEPROM Quick Write on devices with FTFC

## [3.2.0]

- New Feature
  - Basic support for FTFC

## [3.1.3]

- New Feature
  - Support 512KB flash for Kinetis E serials.

## [3.1.2]

- Bug Fixes
  — Remove redundant comments.

## [3.1.1]

- Bug Fixes
  — MISRA C-2012 issue fixed: rule 10.3

## [3.1.0]

- New Feature
  - Support erase flash asynchronously.

## [3.0.2]

- Bug Fixes
  — MISRA C-2012 issue fixed: rule 8.4, 17.7, 10.4, 16.1, 21.15, 11.3, 10.7
  — building warning -Wnull-dereference on arm compiler v6

## [3.0.1]

- New Features
  - Added support FlexNVM alias for (kw37/38/39).

## [3.0.0]

- Improvements
  - Reorganized FTFx flash driver source file.
  - Extracted flash cache driver from FTFx driver.
  - Extracted flexnvm flash driver from FTFx driver.

## [2.3.1]

- Bug Fixes
  - Unified Flash IFR design from K3.
  - New encoding rule for K3 flash size.

## [2.3.0]

- New Features
  - Added support for device with LP flash (K3S/G).
  - Added flash prefetch speculation APIs.
- Improvements
  - Refined flash_cache_clear function.
  - Reorganized the member of flash_config_t struct.

## [2.2.0]

- New Features
  - Supported FTFL device in FLASH_Swap API.
  - Supported various pflash start addresses.
  - Added support for KV58 in cache clear function.
  - Added support for device with secondary flash (KW40).
- Bug Fixes
  - Compiled execute-in-ram functions as PIC binary code for driver use.
  - Added missed flexram properties.
  - Fixed unaligned variable issue for execute-in-ram function code array.

## [2.1.0]

- Improvements
  - Updated coding style to align with KSDK 2.0.
  - Different-alignment-size support for pflash and flexnvm.
  - Improved the implementation of execute-in-ram functions.

## [2.0.0]

- Initial version
