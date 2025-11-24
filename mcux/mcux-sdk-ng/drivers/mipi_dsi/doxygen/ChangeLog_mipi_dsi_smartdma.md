# MIPI_DSI_SMARTDMA

## [2.3.2]

- Misc Changes
  - Updated for SMARTDMA driver firmware name change.

## [2.3.1]

- New Features
  - Updated DSI_TransferWriteMemorySMARTDMA to support transfer format of input RGB565
    and output RGB888 pixel data.

## [2.3.0]

- New Features
  - Updated DSI_TransferWriteMemorySMARTDMA, dsi_smartdma_write_mem_transfer_t
    and dsi_smartdma_handle_t to support 2-dimensional data transfer for interleaved
    pixels.

## [2.2.1]

- Bug Fixes
  - Fixed MISRA C-2012 issues: 10.1, 10.3, 11.3, 11.8, 14.4, 17.7.

## [2.2.0]

- Improvements
  - Supported swap or don't swap the pixel byte before written to MIPI DSI FIFO.

## [2.1.0]

- Improvements
  - Supported frame buffer format XRGB8888.
  - Added virtual channel setting in dsi_smartdma_write_mem_transfer_t, current
    driver only support channel 0, added for future enhancement.

## [2.0.1]

- Bug Fixes
  - Fixed the issue that driver handle not set to busy during transfer.

## [2.0.0]

- Initial version.
