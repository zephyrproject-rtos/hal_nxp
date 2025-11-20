# IAP

## [2.1.5]

- Improvements
  - Update Flash_Program src parameter to const.
  - Check CPU frequency <= 100MHZ for Flash Erase and Program.
  - Add BOOTLOADER_UserEntry API.

## [2.1.4]

- Bug Fixes
  - Fixed misra issue.

## [2.1.3]

- Bug Fixes
  - Fix the CFPA version wasn’t transferred into SDK driver.

## [2.1.2]

- Bug Fixes
  - Fix IAP driver status definitions don't match ROM_API.pdf from User Manual.

## [2.1.1]

- Bug Fixes
  - The last 17 pages are reserved for chips with 640KB flash.

## [2.1.0]

- New Features
  - Added new API FLASH_Read for users to read flash.
  - Added new API skboot_authenticate for image authentication api.
  - Added new AP kb_init, kb_deinit, kb_execute for users to operate BOOT ROM.

## [2.0.3]

- Bug Fixes
  - Resolve incompatibility issue.

## [2.0.2]

- Bug Fixes
  - MISRA C-2012 issue fixed: rule 11.1.
- Improvements
  - Improved the format of IAP driver version, using versionMajor to obtain the major version of bootloader.

## [2.0.1]

- Improvements
  - Removed the enumeration item kSysToFlashFreq_100MHz which cannot be supported.
  - Removed the invalid FFR commands.
  - Improved the format of IAP driver version, using S_VersionMajor to obtain the major version of bootloader.

## [2.0.0]

- Initial version.
