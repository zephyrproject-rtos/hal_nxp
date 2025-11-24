# LCDIC

## [2.2.0]

- New Features
  - Add software timeout when waiting for CMD done.

## [2.1.0]

- New Features
  - Add seperate APIs for send and receive data in non-blocking way.
- Others
  - Return error status when sending or receiving data larger than 0x40000,
    current driver doesn't support this.

## [2.0.3]

- Bug Fixes
  - Fixed potential issue that clock may not be send out when sending
    data array.

## [2.0.2]

- Bug Fixes
  - Fixed build error with MDK 5.37.

## [2.0.1]

- Bug Fixes
  - Added delay after setting LCDIC_EN to make sure LCDIC is out of reset.

## [2.0.0]

- Initial version.
