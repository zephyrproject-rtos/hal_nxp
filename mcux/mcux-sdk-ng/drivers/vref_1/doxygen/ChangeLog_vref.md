# VREF

## [2.5.0]

- New features
  - Add VREF_SetAdcNegChannelRef() API for ADC negative channel control
  - Add VREF_SetAdcPosChannelRef() API for ADC positive channel control
  - Add conditional LPBGEN_MASK setting based on feature availability
  - Add IBIAS_EN_MASK setting for devices with IBIAS_EN feature

## [2.4.1]

- Improvements
  - Improve doxygen documentation.

## [2.4.0]

- Improvements
  - Support TEST_UNLOCK and TRIM0 registers read and write.

## [2.3.0]

- Improvements
  - Add feature macros for compatibility with some platforms that don't have CSR[LPBG_BUF_EN] and UTRIM[TRIM2V1].

## [2.2.2]

- Bug Fixes
  - Fixed typo in vref_buffer_mode_t enumerator.

## [2.2.1]

- Improvements
  - Updated VREF driver code to reduce code redundancy.

## [2.2.0]

- Improvements
  - Remove API VREF_SetTrimVal and VREF_GetTrimVal
  - Add new API VREF_SetVrefTrimVal,VREF_SetTrim21Val,VREF_GetVrefTrimVal and VREF_GetTrim21Val
  - Updated VREF driver code to conform to VREF IP architecture.

## [2.1.0]

- Improvements
  - Remove API VREF_SetTrimVal and VREF_GetTrimVal
  - Add new API VREF_SetVrefTrimVal,VREF_SetTrim21Val,VREF_GetVrefTrimVal and VREF_GetTrim21Val
  - Updated VREF driver code to conform to VREF IP architecture.
- Bug Fixes
  - Fix issue which progeam stuck in VREF_Init

## [2.0.0]

- Initial version.
