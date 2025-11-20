# ASRC

## [2.1.3]

- Bug Fixes
  - Fixed function did not match the specified channel pair issue.

## [2.1.2]

- Improvements
  - Correct feature name in source file by changing FSL_FEATURE_ASRC_PARAMETER_REGISTER_NAME_ASPRM
    to FSL_FEATURE_ASRC_PARAMETER_REGISTER_NAME_ASRPM.
  - Removed the asrc_clock_source_t from driver header file, as SOC header file will provide detail definition.
- Bug Fixes
  - Fixed the ASRC_SetChannelPairConfig/ASRC_ChannelPairEnable functions missing functionality when using channel pair B/C.
  - Fixed violations of the MISRA C-2012 rules 10.7.

## [2.1.1]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 10.1，10.4, 12.2.

## [2.1.0]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 10.3, 10.4, 14.4, 10.1, 17.7, 11.9, 8.6, 12.2, 11.6.

## [2.0.1]

- Improvements
  - Added feature macro FSL_FEATURE_ASRC_PARAMETER_REGISTER_NAME_ASPRM for ASRC parameter register.
- Bug Fixes
  - Fixed the unused build warning in asrc edma driver.

## [2.0.0]

- Initial version.
