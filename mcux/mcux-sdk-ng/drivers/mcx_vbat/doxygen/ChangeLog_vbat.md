# MCX_VBAT

## [2.5.0]

- New features
  - Update MCX_VBAT driver to be compatible with new platforms.

## [2.4.0]

- New features
  - Update MCX_VBAT driver to be compatible with new platforms.

## [2.3.1]

- Bug Fixes
  - Fixed violations of MISRA C-2012 low impact rules.

## [2.3.0]

- Improvements

  - OSCCTLA[FINE_AMP_GAIN] is reserved, added new macro to support this change.
  - Defined VBAT_LDORAMC_RET in case of this macro is not defined in header file.

- Bug Fixes

  - Fixed violaltions of MISRA C-2012 rule 10.8.

## [2.2.0]

- Improvements
  - Added macros to support some devices(such as MCXA family) that do not support OSC control,
    LDO control, bandgap timer, and tamper.

## [2.1.0]

- New features
  - Added functions to support tamper and clock monitor.

## [2.0.0]

- Initial version.
