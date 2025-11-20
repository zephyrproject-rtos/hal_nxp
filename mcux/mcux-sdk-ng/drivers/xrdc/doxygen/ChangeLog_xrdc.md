# XRDC

## [2.0.7]

- Improvements
  - Handle errata ERR050593.

## [2.0.6]

- Improvements
  - Supported platforms which don't have XRDC clock gate control.

## [2.0.5]

- Bug Fixes
  - Fixed XRDC_GetAndClearFirstSpecificDomainError potential array over index issue.

## [2.0.4]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 3.1, 10.1, 10.3, 10.4, 10.6,
    10.7, 10.8, 11.3, 12.2, 14.4, 17.7, 20.7.

## [2.0.3]

- Improvements
  - Added necessary driver supports for K32H844P.
  - Added new APIs concerning new features of Exclusive Access Lock and programmable domain access flags
    configurations.

## [2.0.2]

- Bug Fixes
  - Fixed wrong assert of assignIndex input check in the xRDC driver.
- Improvements
  - Added master input CPU/non-CPU check in XRDC_SetNonProcessorDomainAssignment
    and XRDC_SetProcessorDomainAssignment API.
  - Added necessary assert checks for several config inputs.

## [2.0.1]

- Improvements
  - Changed reserved bit fields in the structs into unnamed-identifier bit fields.

## [2.0.0]

- Initial version.
