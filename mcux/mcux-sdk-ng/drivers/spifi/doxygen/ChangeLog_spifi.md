# SPI Flash Interface

## [2.0.3]

- Bug Fixes
- MISRA C-2012 issue fixed: rule 10.3, 10.4, and 14.4.

## [2.0.2]

- Bug Fixes
  - Fixed the command function set issue. After the command being set, there will be no wait for the CMD flag, as
    it may have been cleared by CS deassert.

## [2.0.1]

- New Features
  - Added an API to read/write 1/2 Bytes data from/to SPIFI. This interface is useful for flash command, which only
    needs 1/2 Bytes data. The previous driver needed users to make sure of the minimum length being 4, which might
    cause issues in some flash commands.

## [2.0.0]

- Initial version.
