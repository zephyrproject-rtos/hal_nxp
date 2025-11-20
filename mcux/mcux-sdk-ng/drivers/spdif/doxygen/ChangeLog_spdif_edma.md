# SPDIF DMA Driver

## [2.0.8]

- Improvements
  - Add EDMA ext API to accommodate more types of EDMA.

## [2.0.7]

- Bug Fixes
  - Fixed the incompatibility issue with edma4 driver.

## [2.0.6]

- Bug Fixes
  - Add feature macro to determine whether to use the API MEMORY_ConvertMemoryMapAddress to translate TCD addresses for DLAST_SGA.

## [2.0.5]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 11.3.

## [2.0.4]

- Bug Fixes
  - Added udata/qdata buffer address validation in driver IRQ handler to ensure that NULL pointer dereferences do not occur.

## [2.0.3]

- Bug Fixes
  - MISRA C-2012 issue fixed: rule 10.3, 10.4, and 14.4.

## [2.0.2]

- Bug Fixes
  - Corrected operator used for size value assertion in
    SPDIF_ReadBlocking/SPDIF_WriteBlocking.

## [2.0.1]

- Bug Fixes
  - Corrected the feature macro name used to define s_edmaPrivateHandle.

## [2.0.0]

- Initial version.
