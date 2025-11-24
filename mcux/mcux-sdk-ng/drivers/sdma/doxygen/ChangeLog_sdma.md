# SDMA

## [2.4.2]

- Bug Fixes
  - Add global variable s_ramScriptLoaded to fix compatibility issues.

## [2.4.1]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 10.4, 11.8.

## [2.4.0]

- Improvements
  - Added load ram script automatically according to the peripheral type.
  - Updated sdma ram script to version I.MX7D_4_6.
  - Added api SDMA_GetRamScriptVersion to support to SDMA ram script version.
- Bug Fixes
  - Removed the SDMA_StartChannelEvents from SDMA_StartTransfer as sdma scheduler will handle it automatically

## [2.3.6]

- Bug Fixes
  - Cleared the SDMAARM_CONFIG_CSM initial value before write value 0 using OR.

## [2.3.5]

- Bug Fixes
  - Added transfer size validation to aovid overflow.

## [2.3.4]

- Bug Fixes
  - Fixed the violation of MISRA C-2012 rule 10.4.

## [2.3.3]

- Improvements
  - Improved sdma driver comments and parameters validation.

## [2.3.2]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 10.6.

## [2.3.1]

- Improvements
  - Removed clear all channel interrupt status in SDMA_HandleIRQ to avoid
    the possibility of lossing interrupt.

## [2.3.0]

- Improvements
  - Added peripheral-to-peripheral support in SDMA driver.
  - Added 24bit data width support in sdma driver.
- Bug Fixes
  - Fixed Coverity issue: left shift may overflow issue.
  - Fixed MISRA2004 issue: the operand of underlying type 'unsigned char' or 'unsigned short' caused the result cast to the underlying type.
  - Fixed violations of MISRA C-2012 rule 10.3, 11.9, 10.4, 17.7, 20.7, 14.4, 11.6, 12.2, 16.4.

## [2.2.1]

- Bug Fixes
  - Fixed MISRA 2004 issue in sdma driver.

## [2.2.0]

- Improvements
  - Added fsl_sdma_script.h to define the sdma script address and firmware.
  - Updated the format of generic register R7 to align with newest firmware.

## [2.1.1]

- Improvements
  - Added SDMA_SetDoneConfig to support hardware/software done configuration.
  - Marked SDMC_EnableSwDone as deprecated.
- Bug Fixes
  - Fixed logical dead code issue in function SDMA_SetDoneConfig.

## [2.1.0]

- Improvements
  - Added SDMA_SetMultiFifoConfig API to support multi fifo feature.
  - Added SDMA_EnableSwDone API to support software done feature.
  - Added SDMA_LoadScript API to support load script to SDMA program memory.
  - Added SDMA_DumpScript API to support dump script from SDMA program memory.
  - Added SDMA3 IRQ handler.

## [2.0.0]

- Initial version.
