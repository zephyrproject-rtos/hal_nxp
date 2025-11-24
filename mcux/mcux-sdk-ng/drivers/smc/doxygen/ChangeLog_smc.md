# SMC

## [2.0.7]

- Bug Fixes
  - Fixed MISRA-2012 issue 10.3.

## [2.0.6]

- Bug Fixes
  - Fixed issue for MISRA-2012 check.
    - Fixed rule 10.3, rule 11.3.

## [2.0.5]

- Bug Fixes
  - Fixed issue for MISRA-2012 check.
    - Fixed rule 15.7, rule 14.4, rule 10.3, rule 10.1, rule 10.4.

## [2.0.4]

- Bug Fixes
  - When entering stop modes, used RAM function for the flash synchronization issue.
    Application should make sure that, the RW data of fsl_smc.c is located in
    memory region which is not powered off in stop modes.

## [2.0.3]

- Improvements
  - Added APIs SMC_PreEnterStopModes, SMC_PreEnterWaitModes, SMC_PostExitWaitModes,
    and SMC_PostExitStopModes.

## [2.0.2]

- Bug Fixes
  - Added DSB before WFI while ISB after WFI.
- Other Changes
  - Updated SMC_SetPowerModeVlpw implementation.

## [2.0.1]

- Other Changes
  - Updated for KL8x.

## [2.0.0]

- Initial version.
