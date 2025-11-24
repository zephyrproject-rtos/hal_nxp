# COP

## [2.2.3]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 10.3.

## [2.2.2]

- Bug Fixes
- Added configuration of CWP bits in COP_Init, fixed write protection bEnableWriteProtect cannot be configured as part of cop_config_t.

## [2.2.1]

- Bug Fixes
- Fixed violations of the MISRA C-2012 rules.

## [2.2.0]

- Improvements
- Updated cop_config_t member naming.
- Deleted COP_Disable API, added COP_Enable to enable/disable COP.

## [2.1.0]

- Improvements
- API interface changes:
  - Renamed "COP_EnableInterrupts/COP_DisableInterrupts" to "COP_EnableInterrupt/COP_DisableInterrupt" and remove unnecessary parameter.
  - New Features
- Added APIs to enable/disable the COP COP Loss of Reference counter.

## [2.0.0]

- Initial version.
