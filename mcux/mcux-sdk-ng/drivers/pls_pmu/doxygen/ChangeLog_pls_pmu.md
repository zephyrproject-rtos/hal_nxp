# PLS_PMU

## [2.1.0]
- New Features
    - Added PMU_UpdateHvdLvTrim() API to update PMU_TRIM4[HVD_LV_TRIM] bitfield.
    - Added PMU_UpdateLvdLvTrim() API to update PMU_TRIM4[LVD_LV_TRIM] bitfield.
    - These APIs support VDD_CORE_MAIN configuration during CLOCK mode setup (standard/mid drive strength).
    - Add configurable delay (CONFIG_PLS_PMU_REG_WRITE_DELAY_VAL) after PMU register writes.
        to ensure proper timing between consecutive write operations.
    - Add Kconfig option for PLS_PMU_REG_WRITE_DELAY_VAL with default value of 600us.
    - Add PMU_KeepFRO16KActiveInDpd3AndSD() to control FRO16K in DPD3 and SD modes.
    - Add high voltage glitch detection APIs:
        * PMU_EnableHighVolGlitchDetect()
        * PMU_CleanHighVolGlitchDetectReset()
        * PMU_IsHighVolGlitchDetectResetAsserted()
    - Add low voltage glitch detection APIs:
        * PMU_EnableLowVolGlitchDetect()
        * PMU_CleanLowVolGlitchDetectReset()
        * PMU_IsLowVolGlitchDetect()
    - Apply delay after all register write operations in existing and new APIs.
    - Added PMU_DoHandshakeBetweenPMUAndPAC function to ensure proper synchronization between PMU and PAC after register updates.

- Bug Fixes
    - Fixed inverted logic in PMU_EnableFRO16K() function where enable
    parameter was incorrectly mapped to register bit operations.

## [2.0.1]
- Bug Fixes
    - Fixed wrong mask macros used in PMU_UpdateVDDCoreInActiveMode() and
    PMU_UpdateVDDCoreInLpMode().

## [2.0.0]

- Initial version.
