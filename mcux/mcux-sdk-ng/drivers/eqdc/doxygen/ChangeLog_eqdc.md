# EQDC

## [2.3.1]

- Bug Fix
- Fixed CTRL2[CMODE] field overwritten in API EQDC_Init.

## [2.3.0]

- Improvements
- Add feature macro to support platforms which do not have compare interrupt.

## [2.2.3]

- Bug Fix
- Clear Revolution Counter Register(REV) in init function to prevent its value not equal
  to zero after reset.

## [2.2.2]

- Improvements
- Release peripheral from reset if necessary in init function.

## [2.2.1]

- Bug Fix
- Fixed violations of the MISRA C-2012 rules 20.9.

## [2.2.0]

- New features
- Supported the feature that the position counter to be initialized by Index Event Edge Mark.

## [2.1.0]

- Bug Fix
- Fixed typo in interrupt enumeration values.
  - Improvements
- Supported Count Direct Change interrupt.
- Removed unused parameter in user configuration.
- Supported ERRATA_051383 check, the CTRL[DMAEN] can't be cleared.

## [2.0.1]

- Bug Fix
- Fixed violations of the MISRA C-2012 rules 10.3, 10.6, 10.8, 14.4,
  16.4.

## [2.0.0]

- Initial version.
