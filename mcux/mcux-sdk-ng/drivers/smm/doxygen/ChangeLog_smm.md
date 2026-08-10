# SMM

## [2.2.1]
- New Features
    - Added Kconfig options `SMM_CM33_CORE_FREQUENCY` and `SMM_CM0P_CORE_FREQUENCY` to allow
      compile-time configuration of core frequency for delay calculation.
    - Added `SMM_CPU_CORE_FREQ` macro to select core frequency based on core type and Kconfig settings,
      with fallback to runtime clock query APIs.

- Improvements
    - Refactored `SMM_DisableMainCpuIso()` and `SMM_DisableAonCpuIso()` to use unified `SMM_CPU_CORE_FREQ` macro, removing duplicated preprocessor blocks.

## [2.2.0]
- New Features
    - Added APIs to clear wakeup source status.
    - Updated SMM driver register field mask names.

## [2.1.2]

- Bug Fixes
    - Fixed CERT INT31-C finding in interrupt enable/disable handling.
    - Change delay value in SMM_DisableAonCpuIso() and SMM_DisableMainCpuIso(). 

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
