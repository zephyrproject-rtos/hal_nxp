# WDOG

## [2.2.0]

- Bug Fixes
  - Fixed the wrong behavior of workMode.enableWait, workMode.enableStop,
    workMode.enableDebug in configuration structure wdog_config_t. When set
    the items to true, WDOG will continues working in those modes.

## [2.1.1]

- Bug Fixes
  - MISRA C-2012 issue fixed: rule 10.1, 10.3, 10.4, 10.6, 10.7 and 11.9.
  - Fixed the issue of the inseparable process interrupted by other interrupt source.
    - WDOG_Init
    - WDOG_Refresh

## [2.1.0]

- New Features
  - Added new API "WDOG_TriggerSystemSoftwareReset()" to allow users to reset the system by software.
  - Added new API "WDOG_TriggerSoftwareSignal()" to allow users to trigger a WDOG_B signal by software.
  - Removed the parameter "softwareAssertion" and "softwareResetSignal" out of the wdog_config_t structure.
  - Added new parameter "enableTimeOutAssert" to the wdog_config_t structure. With this parameter
    enabled, when the WDOG timeout occurs, a WDOG_B signal will be asserted. This signal can
    be routed to external pin of the chip. Note that WDOG_B signal remains asserted until
    a power-on reset (POR) occurs.

## [2.0.1]

- New Features
  - Added control macro to enable/disable the CLOCK code in current driver.

## [2.0.0]

- Initial version.
