# TEMPMON

## [2.2.1]

- Improvements
  - Move TEMPMON calibration data mask definitions from the driver
    source file to the header file, as the driver examples also need
    to use these definitions.

## [2.2.0]

- Bug Fixes
  - Fixed the issue of inconsistency between data width and RM.

## [2.1.1]

- Bug Fixes
  - Fixed the violations of MISRA C-2012 rules:
    - Rule 10.3 10.4.

## [2.1.0]

- Bug Fixes
  - Supported minus value for alarm temperature setting.
  - Fixed wrong temperature calculation equation.

## [2.0.3]

- Improvements
  - Added temperature threshold check for high/low/panic to avoid temperature overflow.

## [2.0.2]

- Bug Fixes
  - Fixed wrong alarm value setting API, it need to clear it firstly and set a new value into it.

## [2.0.1]

- Bug Fixes
  - Fixed the violations of MISRA C-2012 rules:
    - Rule 10.1 10.3 10.4 10.8 17.7.

## [2.0.0]

- Initial version.
