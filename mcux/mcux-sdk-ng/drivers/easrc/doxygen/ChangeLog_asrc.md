# eASRC

## [2.0.7]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 10.1, 10.3, 10.4, 10.5, 10.6, 10.7, 10.8, 12.4.

## [2.0.6]

- Improvements
  - Updated use of definitions in the function ASRC_SetSlotConfig and ASRC_EnableContextSlot.

## [2.0.5]

- Improvements
  - Fixed the typo and multichannel configuration issues in asrc driver.
  - Updated the asrc firmware table for better THD performance.

## [2.0.4]

- Improvements
  - Corrected the data width support by IEC60958,
  - Updated the default stage1 result to float to avoid convert result distortion.

## [2.0.3]

- Bug Fixes
  - Corrected the btis shift index used in function ASRC_TransferBlocking.
  - Ensured the resampler and prefilter are not in bypass mode when the convertion require the function.

## [2.0.2]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 10.1, 10.3, 10.4, 14.3, 14.4, 16.3, 16.1, 16.8, 17.7.

## [2.0.1]

- Bug Fixes
  - Fixed the context id hard code issue in the function ASRC_TransferInCreateHandleSDMA/ASRC_TransferOutCreateHandleSDMA.
- Improvements
  - Added support for the data size bigger than 64K in sdma driver.

## [2.0.0]

- Initial version.
