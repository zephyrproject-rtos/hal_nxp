# CMP

## [2.2.1]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 10.1,
    rule 10.4, and rule 17.7.

## [2.2.0]

- Improvements:
  - Added API to configure the sampling mode and clock divider of the CMP Filter.
  - Supported CMP filter sampling mode configuration.

## [2.1.0]

- New Features:
  - Added API to get default CMP user configuration structure.
  - Supported CMP filter clock divider settings.
  - Combined the settings of VREF source and VREF value into one API CMP_SetVREF().
  - Extracted CMP input source selection from CMP_Init() to CMP_SetInputChannels().
- Improvements:
  - Formatted API naming, variable naming and comment style for better readability.
  - Added comments for APIs in source file.

## [2.0.1]

- Bug Fixes
  - Fixed missing 'const' qualifier for structure variable in function parameter.

## [2.0.0]

- Initial version.
