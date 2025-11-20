# MIPI_DSI

## [2.3.0]

- Bug Fixes
  - Fixed typo in member of dsi_transfer_t structure. The sendDscCmd and dscCmd shall
    be sendDcsCmd and dcsCmd.

## [2.2.5]

- Bug Fixes
  - Fixed issue that VACTIVE setting shall equal to the number of active lines (height), no need to minus 1.

## [2.2.4]

- Bug Fixes
  - Updated the DPI setting to use float for coefficient value for more accurate calculation.

## [2.2.3]

- Bug Fixes
  - Fixed the DSI_TransferNonBlocking no interrupt issue.
  - Fixed the violations of MISRA 2012 advisory rules.

## [2.2.2]

- Bug Fixes
  - Fixed the DPI horizontal timing setting issue.
  - Fixed MISRA issue

## [2.2.1]

- Bug Fixes
  - Fixed the bug that runs to hardfault when sending long packet with 4-byte unaligned address.

## [2.2.1]

- Improvements
  - Supported long package read.

## [2.2.0]

- Improvements
  - Change parameter MIPI_DSI_Type pointer to const type.

## [2.1.0]

- Initial version.
