# CMC

## [2.4.4]

- Bug Fixes
  - Fixed doxygen warning: unbalanced grouping commands.

## [2.4.3]

- Improvements
  - Add timeout for while loop code.

## [2.4.2]

- Improvements
  - Add support for specific KW4x device variants
    - Let kCMC_SecurityViolationReset depend on whether CMC_SRS_SECVIO_MASK definition exists or not.
    - CMC_LockWriteOperationToBootRomStatusReg and CMC_CheckBootRomStatusRegWriteLocked exist only if FSL_FEATURE_CMC_HAS_NO_BOOTROM_LOCK_REGISTER is not defined

## [2.4.1]

- Improvements
  - Clear SCB SCR[SLEEPDEEP] bitfield after wakeup.

## [2.4.0]

- New Features
  - Added new interface to support CMC[DIER] register.
- Improvements
  - Updated _cmc_system_sram_arrays enumeration to support some devices that provide more sram bank.

## [2.3.1]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 10.7;

## [2.3.0]

- Improvements
  - Added new functions to support controls of BLR register.
  - Updated CMC_GetBootRomStatus() to support some devices that equipped multiple BootROM status registers.
  - Added CMC_WriteBootRomStatusReg() to write BootRom Status register.

## [2.2.1]

- Improvements
  - For some devices, SRS_JTAG bit is reserved. Added a feature macro to adapt to different devices.

## [2.2.0]

- Improvements
  - Updated _cmc_system_sram_arrays enumeration, make it more universal.
  - Updated SRAM related APIs(CMC_PowerOffSRAMAllMode(), CMC_PowerOffSRAMLowPowerOnly(),
    CMC_PowerOnSRAMAllMode(), CMC_PowerOnSRAMLowPowerOnly()), due to updates
    of registers' names.
  - Renamed CMC_GetBootConfigPinLogic() to CMC_GetISPMODEPinLogic().
  - Renamed CMC_ClearBootConfig() to CMC_ClearISPModePinLogic().
  - Updated enumeration _cmc_power_mode_protection due to some macros are deleted in header file.

## [2.1.0]

- Improvements
  - Added some macros to separate the scenes that some registers are
    reserved in some devices.

## [2.0.0]

- Initial version.
