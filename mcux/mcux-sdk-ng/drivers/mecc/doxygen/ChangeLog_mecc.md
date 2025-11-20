# MECC

## [2.1.1]

- Bug fixes:
  - Add volatile to variable counter to fix armgcc 13.2.1 -Os optimization issue.

## [2.1.0]

- Bug fixes:

  - Removed Ocram1StartAddress, Ocram1EndAddress, Ocram2StartAddress, Ocram2EndAddress in mecc_config_t structure.
    Use startAddress and endAddress as instead.
  - Removed static function MECC_GetInstance().

- New Features:

  - Added new function MECC_GetPendingFlags().
  - Added new members: enableReadDataWait, enableReadAddrPipeline, enableWriteDataPipeline, enableWriteAddrPipeline
    in mecc_config_t structure to support pipeline features.

## [2.0.2]

- Bug fixes:
  - Fixed MISRA 2012 issue: 10.3, 10.4.

## [2.0.1]

- Bug fixes:
  - Fixed MISRA 2012 issue: 10.1, 10.3, 10.4, 10.6.

## [2.0.0]

- Initial version.
