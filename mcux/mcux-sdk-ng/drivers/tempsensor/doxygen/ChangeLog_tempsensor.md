# TEMPSENSOR

## [2.1.2]

- Bug Fixes
  - Fixed the bug of incorrect default value of temperature sensor registers in initialization state.

## [2.1.1]

- Improvements
  - CTRL0 register fields are not needed for customer, they are trim registers for the IP that are determined during calibration.

## [2.1.0]

- Improvements
  - Supported directly access to TEMPSENSOR registers.

## [2.0.3]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 Rule 10.1, 10.3, 10.4, 10.8.

## [2.0.2]

- Bug Fixes
  - Fixed bug that FINISH flag not cleared after temperature read out.

## [2.0.1]

- Improvements
  - Updated temperature calculation formula, to get more accurate result with high or low temperature..

## [2.0.0]

- Initial version.
