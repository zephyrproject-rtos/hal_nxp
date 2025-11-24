# MSCAN

## [2.1.0]

- Improvements
  - Added wrong data length code(DLC) detection, report kStatus_MSCAN_DataLengthError
    when DLC is wrong.

## [2.0.7]

- Bug Fixes
  - Fix build warning.

## [2.0.6]

- Bug Fixes
  - Fix MISRA C-2012 rule 10.3.

## [2.0.5]

- Bug Fixes
  - Fixed the code error issue and simplified the algorithm in improved timing APIs.
    - MSCAN_CalculateImprovedTimingValues

## [2.0.4]

- Bug Fixes
  - Fixed the non-divisible case in improved timing API.
    - MSCAN_CalculateImprovedTimingValues

## [2.0.3]

- Bug Fixes
  - MISRA C-2012 issue check.
    - Fixed MISRA C-2012 issue in mcan driver, containing: rule-10.1, rule-10.3, rule-10.4,
      rule-10.7, rule-11.8, rule-14.4, rule-15.5, rule-16.1, rule-16.4, rule-17.7, rule-8.4, rule-8.5.

## [2.0.2]

- Bug Fixes
  - Fixed issue Clang - disable declaration alignment.
  - Fixed issue Central repository code formatting.
- Improvements
  - Implemented feature to find classical CAN improved timing configuration.

## [2.0.1]

- Bug Fixes
  - Fixed timestamp issue where it cannot be enabled.
  - Fixed standard mode frame buffer configuration.
  - Added RX Message Buffer Mask helper macro, MSCAN_RX_MB_STD_MASK, MSCAN_RX_MB_EXT_MASK.
  - Fixed dataByte[0-7] order in struct type mscan_frame_t.
  - Updated function MSCAN_WriteTxMb. The MSCAN registers are 8 bits, using 8 bits write for registers.

## [2.0.0]

- Initial version.
