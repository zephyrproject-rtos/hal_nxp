# CACHE LMEM

## [2.1.0]

- Improvements
  - Add memory barrier when enabling/disabling cache.

## [2.1.0]

- Improvements
  - Added new feature macro to support some device do not support PCCCR[ENWRBUF] bit field.

## [2.0.6]

- Bug Fixes
  - Fixed doxygen issue.

## [2.0.5]

- Improvements
  - Updated the cache enable function, don't enable again when it is already enabled.

## [2.0.4]

- Bug Fixes
  - Updated full name for lmem driver.
  - Fixed doxygen issue.

## [2.0.3]

- Bug Fixes
  - Fixed violation of MISRA C-2012 Rule 10.4 and 14.4.

## [2.0.2]

- Improvements
  - Moved CLCR register configuration out of the while loop, it's unnecessary to repeat this operation.

## [2.0.1]

- Bug Fixes
  - Fixed the over-4KB-size maintenance issue in invalidate/clean/clean&invalidate by range APIs.

## [2.0.0]

- Initial version.
