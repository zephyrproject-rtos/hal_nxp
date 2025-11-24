# SYSMPU

## [2.2.3]

- Bug Fixes
  - Fixed violation of MISRA C-2012 Rule 10.4, a part of issues is ignored before.

## [2.2.2]

- Bug Fixes
  - Fixed violation of MISRA C-2012 Rule 10.1, 10.3, 10.4, 10.7, 10.6, 10.8, 12.2.

## [2.2.1]

- Bug Fixes
  - Fixed MISRA issue.

## [2.2.0]

- Improvements
  - Renamed MPU to SYSMPU.
  - Changed macro definition for slave number and fixed the get error status calculation.

## [2.1.1]

- Improvements
  - Added the feature file macro definition limitation for the
    MPU_SetRegionRwMasterAccessRights().

## [2.1.0]

- Other Changes
  - API changes:
    - Changed the mpu_region_num_t and mpu_master_t to uint32_t.
    - Changed the mpu_low_masters_access_rights_t, mpu_high_masters_access_rights_t to
      mpu_rwxrights_master_access_control_t, mpu_rwrights_master_access_control_t.
    - Changed the MPU_SetRegionLowMasterAccessRights(), MPU_SetRegionHighMasterAccessRights() to
      MPU_SetRegionRwxMasterAccessRights(), MPU_SetRegionRwMasterAccessRights().

## [2.0.0]

- Initial version.
