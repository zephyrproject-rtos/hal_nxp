# MIPI_DSI

## [2.1.0]

- Bug Fixes
  - Fixed typo in member of dsi_transfer_t structure. The sendDscCmd and dscCmd shall
    be sendDcsCmd and dcsCmd.

## [2.0.3]

- Improvements
  - Supported DSI_ConfigDphy api.
  - Supported DSI_EnableVpgEnMode to config the video mode pattern generator.

## [2.0.2]

- Improvements
  - More precise calculation of the values of m & n.
  - Lookup table method to obtain DPHY-related parameters based on bandwidth.

## [2.0.1]

- Bug Fixes.
  - Fixed MISRA C-2012 issues: 10.1, 10.3, 10.4, 10.8, 21.15

## [2.0.0]

- Initial version.
