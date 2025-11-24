# WUU

## [2.4.1]

- Improvements
  - The semantics of `kWUU_FilterActiveDSPD` and `kWUU_ExternalPinActiveDSPD` are not
    clear enough, because on some platforms it's not 'DSPD' (deep sleep, power down) but
    PDDPD (power down, deep power down). We deprecate them and will use the more generic
    `kWUU_FilterActiveLowLeakage` and `kWUU_ExternalPinActiveLowLeakage` in the future.

## [2.4.0]

- New Features
  - Added WUU_ClearExternalWakeupPinsConfig() to clear settings of PDC and PE register.

## [2.3.0]

- New Features
  - Added WUU_ClearInternalWakeUpModulesConfig() to clear settings of DM and ME register.

## [2.2.1]

- Bug Fixes
  - Fixed WUU_SetPinFilterConfig() unable to set edge detection of pin filter config.
  - Fixed wrong macro used in WUU_GetPinFilterFlag() function.

## [2.2.0]

- New Features
  - Added the WUU_GetExternalWakeupPinFlag() and WUU_ClearExternalWakeupPinFlag() function .

## [2.1.0]

- New Features
  - Added the WUU_GetModuleInterruptFlag() function to support
    the devices that equipped MF register.

## [2.0.0]

- Initial version.
