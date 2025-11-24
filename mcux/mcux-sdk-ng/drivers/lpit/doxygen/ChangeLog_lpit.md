# LPIT

## [2.1.3]

- Bug Fixes
  - Fixed doxygen generation warnings.

## [2.1.2]

- Bug Fixes
  - Fix CERT INT31-C issues.

## [2.1.1]

- Improvements
  - Release peripheral from reset if necessary in init function.

## [2.1.0]

- Improvements
  - Add new function LPIT_SetTimerValue to set timeout period.

## [2.0.2]

- Improvements
  - Improved LPIT_SetTimerPeriod implementation, configure timeout value with LPIT ticks minus 1 generate more correct interval.
  - Added timeout value configuration check for LPIT_SetTimerPeriod, at least input 3 ticks for calling LPIT_SetTimerPeriod.
- Bug Fixes
  - Fixed MISRA C-2012 rule 17.7 violations.

## [2.0.1]

- Bug Fixes
  - MISRA C-2012 issue fixed.
    - Fixed rules, containing: rule-10.3, rule-14.4, rule-15.5.

## [2.0.0]

- Initial version.
