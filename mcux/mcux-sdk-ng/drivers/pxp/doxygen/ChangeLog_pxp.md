# PXP

## [2.7.0]

- New Features
  - Added the PS_LRC setting for V4.
  - Added the PXP_SetPath setting for V4.
  - Fixed the code logic, V4 do not support DATA_PATH_CTRL1.

## [2.6.1]

- Improvements
  - Release peripheral from reset if necessary in init function.

## [2.6.0]

- Bug Fixes
  - Added missing configuration option for fetch engine background value.
  - Fixed bug in PXP_SetStoreEngineConfig that the address increment for store mask is not
    linear.
  - Added channel aribitration configuration for fetch engine, channel combine for store engine.
  - Fixed wrong method of obtaining the store mask address.
  - Fixed wrong method of configuring flag shift mask/width which can only be written in word boundary.
  - Fixed wrong configurations of block store and pitch in PXP_SetStoreEngineConfig.
  - Fixed wrong method of obtaining cfaValue address and calculating word count.
  - Fixed the channel word order cannot be updated when configuring the second channel.
  - Fixed bugs in PXP_SetHistogramConfig of wrong method to obtain the store mask address and wrong
    access of 32-bit registers.

## [2.5.0]

- New Features
  - Added new API PXP_GetPorterDuffConfigExt for flexible Porter-Duff configuration.
  - Added enumerations for new AS/PS pixel formats for certain SoCs.

## [2.4.1]

- New Features
  - Added API PXP_ResetControl to reset the PXP and the control register to initialized state.

## [2.4.0]

- New Features
  - Added the API PXP_BuildRect of building a solid rectangle of given pixel value.
  - Added the interrupt enable/disable and status mask for V3.
  - Added API PXP_EnableProcessEngine to enable/disable process engines for V3.
  - Added API PXP_SetHistogramSize to re-configure the histogram size for each update.
  - Updated PXP_WfeaInit and PXP_SetWfeaConfig according to header file's update of WFE related registers.
  - Updated PXP_WfeaInit to support handshake with upstream dither store engine and added API
    PXP_WfeaEnableDitherHandshake to enable/disable the feature.
  - Added API PXP_GetLutUsage to get the occupied LUT list.
  - Updated APIs to support alpha blending engine1.
  - Added the API PXP_MemCopy to support all memory size copy.
- Bug Fixes
  - Fixed wrong naming for mux16.
  - Fixed wrong naming for enumerations in pxp_scanline_burst_t.
  - Fixed bug in PXP_GetHistogramMatchResult since there are 2 histograms engines rather than 1.
  - Fixed bug in PXP_SetFetchEngineConfig that the fetch size should not be minus one coding.

## [2.3.0]

- New Features
  - Added the configuration of fetch engine, store engine, pre-dither engine
    and histogram block.

## [2.2.2]

- Improvements
  - Disable alpha surface (AS) in PXP_Init.

## [2.2.1]

- Improvements
  - Added memory address conversion to support buffers which could only be
    accessed using alias address by non-core masters.

## [2.2.0]

- Bug Fixes
  - Fixed Porter Duff configuration error.

## [2.1.0]

- New Features
  - Added Porter Duff support.
  - Added APIs PXP_StartMemCopy and PXP_StartPictureCopy.
  - Added API PXP_SetProcessSurfaceYUVFormat.

## [2.0.2]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 3.1, 10.8, 11.6, 12.2.

## [2.0.1]

- Bug Fixes
  - Fixed the rotate function issue for i.MX 6ULL.

## [2.0.0]

- Initial version.
