# DAC

## [2.1.3]

- Improvements
  - 'dac_config_t' already contains a member 'enableOpampBuffer',
    but it is not used. This update uses 'enableOpampBuffer' to
    control the configuration of GCR[BUF_EN].

## [2.1.2]

- Improvements
  - Release peripheral from reset if necessary in init function.

## [2.1.1]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules.

## [2.1.0]

- New Features
  - Added support for period trigger mode.
  - Added support for sync trigger between dac instances.
  - Added support for configuring DAC sync cycles.
  - Added support for internal reference current selection.
  - Enabled buffer mode manually for K4 series board.

## [2.0.2]

- Bug Fixes
  - Fixed MISRA C-2012 rule 10.3 and rule 17.7.

## [2.0.1]

- New Features
  - Added a control macro to enable/disable the CLOCK code in current driver.

## [2.0.0]

- Initial version.
