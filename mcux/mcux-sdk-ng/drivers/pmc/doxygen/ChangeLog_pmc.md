# PMC

## [2.0.4]
- Bug Fixes
  - Add validation before narrowing uint32_t to uint8_t conversions using assert
  - Replace direct boolean to integer casts with explicit ternary operators
  - Add INT31-C compliance comments for safe narrowing conversions
  - Apply fixes to PMC_ConfigureLowVoltDetect, PMC_ConfigureLowVoltWarning, and PMC_ConfigureBandgapBuffer functions

## [2.0.3]

- Bug Fixes
  - Fixed the violation of MISRA C-2012 rule 11.3.

## [2.0.2]

- Bug Fixes
  - Fixed the violations of MISRA 2012 rules:
    - Rule 10.3.

## [2.0.1]

- Bug Fixes
  - Fixed MISRA issues.
    - Rule 10.8, Rule 10.3.

## [2.0.0]

- Initial version.
