# ECSPI

## [2.3.3]

- Bug Fixes
  - Fixed the txData from void * to const void * in transmit API

## [2.3.2]

- Improvements
  - Changed ECSPI_DUMMYDATA to 0x00.

## [2.3.1]

- Bug Fixes
  - Fixed ECSPI_GetInstance potential issue that return wrong instance number.

## [2.3.0]

- Bug Fixes
  - Fixed burst length issue,the burst length range shall range from 1-4096 bits, so the width shall be uint8_t rather than uint16_t.

## [2.2.0]

- Bug Fixes
  - Removed the useless channel configuration of waveform, since the waveform can not be configured when not using
    the exchange bit(ECSPIx_CONREG[XCH]) for the transfer.
  - Fixed violations of MISRA C-2012 rules: 10.1, 11.9, 8.4.

## [2.1.1]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rules: 10.1, 10.3, 10.4, 11.9, 14.4, 15.7, 17.7.

## [2.1.0]

- Improvements
  - Added timeout mechanism when waiting certain states in transfer driver.

## [2.0.2]

- Bug Fixes
  - Fixed violations of MISRA C-2012 rules: 10.1, 10.3, 10.4

## [2.0.1]

- Bug Fixes
  - Memset local variable SDMA transfer configuration structure to make sure unused members in structure are
    cleared.
  - Fixed sign-compare warning in ECSPI_SendTransfer.

## [2.0.0]

- Initial version.
