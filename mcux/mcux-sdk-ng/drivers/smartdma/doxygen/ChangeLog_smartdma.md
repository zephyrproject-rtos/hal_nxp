# SMARTDMA

## [2.14.0]

- Improvements
  - Refine the device specific firmware selection method, use device
    Kconfig symbol to select.

## [2.13.3]

- Bug Fixes
  - Fix RT500 FlexIO QSPI MDK build warning.

## [2.13.2]

- Other Changes
  - Add more MCXN devices support.

## [2.13.1]

- Other Changes
  - Add more MCXA devices support.

## [2.13.0]

- New Features
  - Added MCXA keyscan firmware.
  - Added functions to control CTRL[EXF].

## [2.12.0]

- New Features
  - Supported MCXA mculcd and camera functions.

## [2.11.0]

- Improvements
  - Make the RT500 QSPI firmware can work with other display firmware in
    the same project.

## [2.10.0]

- New Features
  - Added new camera APIs for MCXN SoCs to support more resolutions.

## [2.9.1]

- New Features
  - Supported MCXN235, MCXN236.

## [2.9.0]

- New Features
  - Supported MCXN camera functions.
  - Supported user to select individual firmware for MIPI or FLEXIO alone, or both.
  - Added new API of enabling DMA from FlexIO to a Buffer.
  - Added new APIs of setting MIPI-DSI to enter and exit ultra low power state.

## [2.8.0]

- New Features
  - Supported converting the pixel data from RGB565 to RGB888.
  - Supported function to turn off certain pixel in a checker board pattern.

## [2.7.0]

- New Features
  - Supported data transfer in 2-dimensional way.
  - Supported data transfer in XRGB8888 format and rotate 180 degree.
  - Supported to fill data in whenever there is room in MIPI controller's FIFO rather than
    using the tx FIFO in double buffered way.

## [2.6.3]

- Bug Fixes
  - Fixed EZH_MIPIDSI_RGB565_DMA, EZH_MIPIDSI_RGB888_DMA, EZH_MIPIDSI_ARGB8888toRGB888_DMA
    issues that don't support some length.

## [2.6.2]

- Bug Fixes
  - Fixed MISRA C-2012 issues: 8.4, 11.6, 17.7.

## [2.6.1]

- Improvements
  - Optimized MIPI DSI APIs performance.

## [2.6.0]

- Improvements
  - Optimized MIPI DSI APIs performance.
- New Features
  - Added new APIs to send MIPI DSI frame with 180 degree rotation.

## [2.5.0]

- Improvements
  - Supported swap or don't swap the pixel byte before written to MIPI DSI FIFO.
  - Updated MIPI DSI firmware, make sure data has been sent out before calling
    callback function.

## [2.4.0]

- Improvements
  - Added new APIs for MIPI DSI kSMARTDMA_MIPI_XRGB2RGB_DMA.

## [2.3.0]

- Improvements
  - Added new APIs for FlexIO one SHIFTBUF, kSMARTDMA_FlexIO_DMA_ONELANE.
- Bug Fixes
  - Fixed kSMARTDMA_MIPI_RGB565_DMA color bias issue.

## [2.2.0]

- Improvements
  - Added new APIs for MIPI DSI, kSMARTDMA_MIPI_RGB565_DMA and kSMARTDMA_MIPI_RGB888_DMA.
  - Supported install firmware and callback function dynamically.

## [2.1.0]

- Improvements
  - Removed test APIs, including kSMARTDMA_LightOn, kSMARTDMA_LightOff,
    kSMARTDMA_Notify, and kSMARTDMA_Test.
  - Added new APIs, including kSMARTDMA_FlexIO_DMA_Reverse, kSMARTDMA_FlexIO_DMA_ARGB2RGB,
    kSMARTDMA_FlexIO_DMA_ARGB2RGB_Endian_Swap, and kSMARTDMA_FlexIO_DMA_ARGB2RGB_Endian_Swap_Reverse.

## [2.0.0]

- Initial version.
