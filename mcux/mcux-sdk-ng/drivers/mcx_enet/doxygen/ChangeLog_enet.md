# MCX_ENET

## [2.1.4]

- Bug Fixes
  - Fixed ENET_GetMacAddr address byte order not matching ENET_SetMacAddr.

## [2.1.3]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 10.6.

## [2.1.2]

- New features
  - Added hardware checksum acceleration support.

## [2.1.1]

- Bug Fixes
  - Fixed the issue that free wrong buffer address when one frame stores in multiple buffers and memory pool is
    not enough to allocate these buffers to receive one complete frame.
  - Fixed the issue that ENET_DropFrame checks the buffer descriptor flag after it has been re-initialized.
  - Fixed the ENET_GetRxFrame FCS calculation issue.
  - Fixed the issue that there's no valid error type in the return structure when Rx error bit is set.

## [2.1.0]

- New Features
  - Added the VLAN control setting APIs in the driver.

## [2.0.1]

- Bug Fixes
  - Fixed the issue that enable/disable interrupt APIs miss part of configuration.

## [2.0.0]

- Initial version.
