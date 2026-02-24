# RCM

## [2.0.5]
- Bug Fixes
  - Replace direct boolean to integer casts with explicit ternary operators for INT31-C compliance.
  - Add validation before narrowing uint32_t to uint8_t conversion using assert.
  - Add INT31-C compliance comments for safe type handling.
  - Apply fixes to RCM_ConfigureResetPinFilter and RCM_SetForceBootRomSource functions.

## [2.0.4]

- Bug Fixes
  - Fixed violation of MISRA C-2012 rule 10.3

## [2.0.3]

- Bug Fixes
  - Fixed violation of MISRA C-2012 rules.

## [2.0.2]

- Bug Fixes
  - Fixed MISRA issue.
    - Rule 10.8, rule 10.1, rule 13.2, rule 3.1.

## [2.0.1]

- Bug Fixes
  - Fixed kRCM_SourceSw bit shift issue.

## [2.0.0]

- Initial version.
