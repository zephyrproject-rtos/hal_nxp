# PINT

## [2.2.0]

  - Fixed
    - Fixed the issue that clear interrupt flag when it's not handled. This causes events to be lost.
  - Changed
    - Used one callback for one PINT instance. It's unnecessary to provide different callbacks for all PINT events.

## [2.1.13]

- Improvements
  - Added instance array for PINT to adapt more devices.
  - Used release reset instead of reset PINT which may clear other related registers out of PINT.

## [2.1.12]

- Bug Fixes
  - Fixed coverity issue.

## [2.1.11]

- Bug Fixes
  - Fixed MISRA C-2012 rule 10.7 violation.

## [2.1.10]

- New Features
  - Added the driver support for MCXN10 platform with combined interrupt handler.

## [2.1.9]

- Bug Fixes
  - Fixed MISRA-2012 rule 8.4.

## [2.1.8]

- Bug Fixes
  - Fixed MISRA-2012 rule 10.1 rule 10.4 rule 10.8 rule 18.1 rule 20.9.

## [2.1.7]

- Improvements
  - Added fully support for the SECPINT, making it can be used just like PINT.

## [2.1.6]

- Bug Fixes
  - Fixed the bug of not enabling common pint clock when enabling security pint clock.

## [2.1.5]

- Bug Fixes
  - Fixed issue for MISRA-2012 check.
    - Fixed rule 10.1 rule 10.3 rule 10.4 rule 10.8 rule 14.4.
  - Changed interrupt init order to make pin interrupt configuration more reasonable.

## [2.1.4]

- Improvements
  - Added feature to control distinguish PINT/SECPINT relevant interrupt/clock configurations for PINT_Init and PINT_Deinit API.

  - Swapped the order of clearing PIN interrupt status flag and clearing pending NVIC interrupt
    in PINT_EnableCallback and PINT_EnableCallbackByIndex function.

  - Bug Fixes

    - Fixed build issue caused by incorrect macro definitions.

## [2.1.3]

- Bug fix:
  - Updated PINT_PinInterruptClrStatus to clear PINT interrupt status when the bit is asserted and check whether was triggered by edge-sensitive mode.
  - Write 1 to IST corresponding bit will clear interrupt status only in edge-sensitive mode and will switch the active level for this pin in level-sensitive mode.
  - Fixed MISRA c-2012 rule 10.1, rule 10.6, rule 10.7.
  - Added FSL_FEATURE_SECPINT_NUMBER_OF_CONNECTED_OUTPUTS to distinguish IRQ relevant array definitions for SECPINT/PINT on lpc55s69 board.
  - Fixed PINT driver c++ build error and remove index offset operation.

## [2.1.2]

- Improvement:
  - Improved way of initialization for SECPINT/PINT in PINT_Init API.

## [2.1.1]

- Improvement:
  - Enabled secure pint interrupt and add secure interrupt handle.

## [2.1.0]

- Added PINT_EnableCallbackByIndex/PINT_DisableCallbackByIndex APIs to enable/disable callback by index.

## [2.0.2]

- Added control macro to enable/disable the RESET and CLOCK code in current driver.

## [2.0.1]

- Bug fix:
  - Updated PINT driver to clear interrupt only in Edge sensitive.

## [2.0.0]

- Initial version.
