# SPC

## [2.8.0]

- Improvements
  - Added feature macros to support some platforms which do not have system LDO, VDD_SYS, DCDC_BURST_CFG.


- Bug Fixes
  - Fixed doxygen warnings: 
    1. unbalanced grouping commands.
    2. Argument 'base' of command @param is not found in the argument
      list of sfa_callback_t(status_t status)
    3. Explicit link request to 'kStatus_SPC_CORELDOVoltageSetFail.' could not be resolved


## [2.7.1]

- Improvements
  - Make configuration structure pointers const in SPC driver API for Higher Power mode

## [2.7.0]

- Improvements
  - Added new APIs to control VDD Core Glitch Detector.

## [2.6.1]

- Improvements
  - Add timeout for while loop code.

## [2.6.0]

- New Features
  - Added new feature FSL_FEATURE_SPC_HAS_SC_SPC_LP_REQ_BIT for compatibility with
    new platforms that do not support the SPC SC[SPC_LP_REQ] bitfield.

## [2.5.0]

- New Features
  - Added new function group to support high power feature.

## [2.4.1]

- Improvements
  - Added the new feature FSL_FEATURE_SPC_HAS_SC_REG_BUSY to support the device which has the SC[REG_BUSY] bitfield.

## [2.4.0]

- Improvements
  - Set functions of VD_SYS_CFG[LVSEL] configuration as deprecated,
    since this bit filed is reserved for all devices.

## [2.3.0]

- Improvements

  - Added SPC_SetSRAMOperateVoltage() to set SRAM operate voltage.

- Bug Fixes

  - Fixed the issue in SPC_SetDCDCBurstConfig() function.
  - Fixed a bug that is SPC has VDD_DS the voltage is not configured correctly.

## [2.2.0]

- Bug Fixes

  - The default value of ACTIVE_CFG[CORELDO_VDD_DS] bit is 1, removed code of set that bit.
  - Fixed an issue of SPC_SetDCDCBurstConfig() to avoid program stuck in a while loop.
  - Removed some duplicate code that never reached.

- Improvements

  - Added two APIs to control Vdd core glitch detect feature in Active/lowpower modes.

## [2.1.0]

- Improvements

  - Improved the spc_dcdc_voltage_level_t enumeration.
  - Added some low power request check APIs.
  - Added SPC_SoftwareGatePowerSwitch() and SPC_PowerModeControlPowerSwitch() function.
  - If APIs' parameters is in type of structure pointer, set it to const structure pointer.

- Bug Fixes

  - Fixed the issue in SPC_SetDCDCRefreshCount() function.
  - Fixed some issues in voltage detect enable APIs.
  - Fixed some issues in Bandgap control APIs.
  - Fixed some issues in regulator active/lowpower mode configuration APIs.

## [2.0.2]

- Bug Fixes
  - Fixed the doxygen issue by adding missed comments.

## [2.0.1]

- Bug Fixes
  - The enumerator spc_core_ldo_voltage_level_t may different for different devices,
    added the macro to separate different scenes.

## [2.0.0]

- Initial version.
