# MIPI_DSI

## [2.3.0]

- Bug Fixes
  - Fixed typo in member of dsi_transfer_t structure. The sendDscCmd and dscCmd shall
    be sendDcsCmd and dcsCmd.

## [2.2.2]

- Bug Fixes
  - Fixed CERT-C violations.

## [2.2.1]

- Bug Fixes
  - Fixed issue that VACTIVE setting shall equal to the number of active lines (height), no need to minus 1.
- Improvements
  - Update DSI_Deinit to reset peripheral.
  - Update DSI_DeinitDphy to power down DPHY using DPHY_PD_REG before powering down PLL.

## [2.2.0]

- New Features
  - Added APIs to configure DBI FIFO and payload.
  - Supported new controls and configurations of DBI pixel format, PHY ready and ULPS for RT700.
  - Updated the DPI setting to use float for coefficient value for more accurate calculation.

## [2.1.6]

- Improvements
  - Release peripheral from reset if necessary in init function.

## [2.1.5]

- Other Changes
  - Changed to use new register naming.
  - Added workaround for Errata ERR011439. Avoid DCS long packet command writes with zero-length
    data payload in low-power mode, because the checksum is incorrect in this case.

## [2.1.4]

- Bug Fixes
  - Fixed the MISRA issues.

## [2.1.3]

- Bug Fixes
  - Fixed the DPI horizontal timing setting issue.

## [2.1.2]

- Improvements
  - Supported long package read.
- Bug Fixes
  - Fixed the bug that runs to hardfault when sending long packet with 4-byte unaligned address.

## [2.1.1]

- Improvements
  - Some SOC compatibility improvement.

## [2.1.0]

- Improvements
  - Improved for the platforms which does not support ULPS.

## [2.0.6]

- Bug Fixes
  - Fixed the timing issue that non-continuous HS clock mode does not work.

## [2.0.5]

- Bug Fixes
  - Fixed kDSI_InterruptGroup1BtaTo and kDSI_InterruptGroup1HtxTo
    definition error.
- Improvements
  - Changed to override MIPI_DriverIRQHandler instead of MIPI_IRQHandler.

## [2.0.4]

- Bug Fixes
  - Fixed MISRA C-2012 issues: 10.1, 10.3, 10.4, 10.4, 10.6, 10.7, 10.8,
    11.3, 11.8, 12.2, 14.4, 16.4, 17.7.

## [2.0.3]

- Improvement
  - Updated for combo phy header file.

## [2.0.2]

- New Features
  - Supported sending separate DSI command from TX data array.
- Bug Fixes
  - Disabled all interrupts in DSI_Init.

## [2.0.1]

- Improvements
  - Updated to support the DPHY which does not have
    internal DPHY PLL.

## [2.0.0]

- Initial version.
