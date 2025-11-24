# SMM

## [2.1.1]

- Bug Fixes
    - Fixed violation of CERT INT31-C.
    - Added a workaround for an issue where the `SMM->STAT` register was incorrectly mapped

- Improvements
    - Refined comments throughout the `fsl_smm.h` header file to improve clarity and consistency.

## [2.1.0]

- New Features
    - Added APIs to control deep sleep counter.
    - Added APIs to enable/disable interrupts.
    - Added APIs to get/clear interrupt flags.

## [2.0.1]

- Bug Fixes
    - Added missed " of FSL_COMPONENT_ID.
    - Fixed issues of SMM_EnableWakeupSourceToMainCpu() and SMM_EnableWakeupSourceToAonCpu().

## [2.0.0]

- Initial version.
