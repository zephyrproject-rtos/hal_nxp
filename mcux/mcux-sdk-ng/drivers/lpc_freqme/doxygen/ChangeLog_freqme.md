# FREQME

## [2.2.0]

- Improvements
  - Add following API to support FREQME which exposes dedicated REF and TAR registers
    for clock source selection.
    - `FREQME_SetReferenceClk`
    - `FREQME_SetTargetClk`
  - Support some devices which apply a different frequency measurement formula
    (result + 1 instead of result - 2).

## [2.1.4]

- Improvements
  - Clarified pulse width measurement mode usage.

## [2.1.3]

- Bug Fixes
  - Fixed violations of the CERT INT30-C INT31-C.

## [2.1.2]

- Improvements
  - Release peripheral from reset if necessary in init function.

## [2.1.1]

- Fixed MISRA issues.

## [2.1.0]

- Updated register name.

## [2.0.0]

- Initial version.
