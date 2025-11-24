# SEMC

## [2.7.1]

- Bug Fixes
  - Fixed the wrong write operation to INTR register. The INTR register is a W1C register, so the right write
    operation is write directly to it to clear.

## [2.7.0]

- Improvements

  - Add new autofreshTimes parameter in semc_sdram_config_t.

- Bug Fixes

  - Fixed violations of MISRA C-2012 rule 10.4.

## [2.6.0]

- Bug Fixes
  - Fixed the SEMC SRAM function bug that some configuration options can't be set.
  - Correct legacy SEMC SRAM function feature macros.
- Improvements
  - Add new SEMC SRAM function feature macros.

## [2.5.1]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 Rule 14.3.
  - Fixed SEMC_ConfigureDBI bug that RDX not set correctly.

## [2.5.0]

- Bug Fixes
  - Fixed definitions of bitfields of BMCR0 and BMCR1 - wrong field order and incorrect semantical naming
  - The fix alters the driver API regarding configuration of AXI bus queue reordering

## [2.4.3]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 Rule 5.6.

## [2.4.2]

- Improvements
  - Deleted meaningless parameter in memory size conversion function.

## [2.4.1]

- Bug Fixes
  - Fixed PSRAM A8 configuration issue, which should be 0x06U for PSRAM while pix mux bit width is 0x04U, based on different pix mux bit width.

## [2.4.0]

- Improvements
  - Improved nor and sram timing configuration on sync mode.

## [2.3.1]

- Bug Fixes
  - Updated refresh timer period(RT) timing setting, which updated into (RT+1)*(Prescaler period) for SDRAM.
  - Supported new DBI control register 2 to configure CSX interval time(CEITV).
  - Fixed violations of the MISRA C-2012 Rule 10.8.
  - Fixed doxygen warning.

## [2.3.0]

- New Features
  - Limited burst length as 1 according to ERR050577, Auto-refresh command may possibly fail to be triggered during long time back-to-back write (or read) when SDRAM controller's burst length is greater than 1.
  - Supported 8 bits column address for SDRAM.

## [2.2.1]

- New Features
  - Added queue weight control, which can control queue a/b is working or not.
  - Updated NAND FLASH configuration API which disables and enables SEMC between configure control registers.
  - Added ONFI parameter Integrity CRC check for SEMC flash component.

## [2.2.0]

- New Features
  - Supported up to 4 PSRAM CS.
  - Added programmable delay line for DQS.
  - Added ready/wait feature for SRAM in asynchronous mode.

## [2.1.0]

- Bug Fixes
  - MISRA C-2012 issue fixed: rule 10.3, 10.4, and 14.4.
  - Updated parameter type from uint16_t into uint32_t for send IP command API.

## [2.0.4]

- Bug Fixes
  - Fixed the SEMC queueA and queueB weight configuration issue.
  - Fixed the wrong configuration of DBICR1 register in SEMC_ConfigureDBI.

## [2.0.3]

- Bug Fixes
  - Added feature macro to control WDS&WDH bit setting for NOR synchronous transfer.

## [2.0.2]

- Bug Fixes
  - Changed SEMC NAND configuration structure and verify SEMC NAND related APIs.
  - Added extended SEMC clock enable.

## [2.0.1]

- Bug Fixes
  - Fixed data size mask configure in SEMC_ConfigureIPCommand API.
  - Updated the command mode in IP command type.

## [2.0.0]

- Initial version.
