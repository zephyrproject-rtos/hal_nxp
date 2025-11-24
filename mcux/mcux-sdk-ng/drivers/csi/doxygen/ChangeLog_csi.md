# CSI

## [2.2.0]

- Improvements
  - Update driver to invoke callback whenere there is a full frame received.

## [2.1.5]

- Improvements
  - Updated for new CSI register and macro names.

## [2.1.4]

- Improvements
  - Added memory address conversion to support buffers which could only be
    accessed using alias address by non-core masters.

## [2.1.3]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 17.7.

## [2.1.2]

- Improvements
  - Supported new CSI_Type register naming.

## [2.1.1]

- Bug Fixes
  - Fixed IAR build warning Pa082.
  - Fixed violations of the MISRA C-2012 rules 8.4, 10.1, 10.3, 10.4, 10.6,
    11.6, 14.4, 17.7.

## [2.1.0]

- New Features
  - Added 16-bit and 24-bit data bus support.
- Bug Fixes:
  - Fixed the bug that CSI writes to wrong buffer when empty buffer
    not submitted in time.

## [2.0.3]

- Bug Fixes
  - Fixed wrong circular queue delta calculation.
  - Fixed double buffering capture issue where, when the transfer is ongoing
    and the device has empty buffer slot, the function
    CSI_TransferSubmitEmptyBuffer sets the empty buffer to CSI device.

## [2.0.2]

- New Features
  - Added fragment mode support.

## [2.0.1]

- Improvements
  - Switched DMA output buffer at the first data after each VSYNC.
    It originally happened when the DMA transfer was done.

## [2.0.0]

- Initial version.
