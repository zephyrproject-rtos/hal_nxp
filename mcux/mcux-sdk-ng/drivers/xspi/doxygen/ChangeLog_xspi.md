# XSPI

## [2.5.2]

- Improvements
  - Fixed an issue with incorrect cache range address calculation. It caused issue when the cache operation size
    is equal to a multiple of the cache line size + 1.

## [2.5.1]

- Improvements
  - Updated default value of sfpArbitrationLockTimeoutValue and ipAccessTimeoutValue to 0xFFFFFFFFUL.
  - Added #if defined(CACHE64_CTRL0_BASE) ... #endif section to support some devices that do not support CACHE64.

## [2.5.0]

- Improvements
  - Updated XSPI_TransferBlocking() to support use case the transfersize bigger than page size.
  - Updated xspi_device_interface_type_t to support changes of page size for hyperram interface.
  - Updated XSPI_ReadBlocking() to fix an potential issue which cause TIMEOUT error.

## [2.4.0]

- New Features
  - Added functions of control cache64.

## [2.3.0]

- Improvements
  - Added new interface: XSPI_StartIpAccessNonBlocking();
  - Provied driver Irq handler for xspi driver;
  - Use ERRSTAT[ARB_WIN] to replace FSMSTAT[VLD].

## [2.2.1]

- Improvements
  - Moved some frequently used variables(s_tgSfarsRegOffset, s_tgIpcrsRegOffset, s_sfpTgIpcrRegOffset,
    s_sfpTgIpSfarRegOffset, s_tgMdadRegOffset) to common code to offload of stack.
  - Added return status in case of timeout flag asserted during IP read access.
- Bug Fixes
  - Fixed violations of MISRA C-2012 rules.

## [2.2.0]

- Improvements
  - Improved xspi_device_config_t structure, removed some not-device related members.
  - Improved xspi_config_t structure, removed some device related settings.
  - Renamed XSPI_SetFlashConfig() to XSPI_SetDeviceConfig().
  - Decoupled settings of IP access, AHB access.
  - Added low-level interfaces to support IP access(including SFP), and AHB access(including
    performance monitor).

## [2.1.0]

- Bug Fixes
  - Fixed issue of XSPI_Init() function, set MCR[MDIS] to disable clocks before settings of MCR register.
  - Unused deviceConfig in XSPI_GetDefaultConfig() function.
- Improvements
  - Updated structure for dllconfig, added method to allow user custom dll parameters.
  - Updated XSPI_UpdateDllValue() function to align with changes of dllconfig.
  - Move device specific value to device feature file.

## [2.0.1]

- Bug Fixes
  - Fixed the XSPI DLL function.
  - Added ALIGN and X16Mode macro definition in driver.
  - updated XSPI PSRAM example.

## [2.0.0]

- Initial version.
