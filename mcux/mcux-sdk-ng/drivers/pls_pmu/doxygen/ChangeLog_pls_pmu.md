# PLS_PMU

## [2.1.0]
- New Features
    - Added PMU_UpdateHvdLvTrim() API to update PMU_TRIM4[HVD_LV_TRIM] bitfield
    - Added PMU_UpdateLvdLvTrim() API to update PMU_TRIM4[LVD_LV_TRIM] bitfield
    - These APIs support VDD_CORE_MAIN configuration during CLOCK mode setup (standard/mid drive strength)

- Bug Fixes
    - Fixed inverted logic in PMU_EnableFRO16K() function where enable
    parameter was incorrectly mapped to register bit operations.

## [2.0.1]
- Bug Fixes
    - Fixed wrong mask macros used in PMU_UpdateVDDCoreInActiveMode() and
    PMU_UpdateVDDCoreInLpMode().

## [2.0.0]

- Initial version.
