# SEMA42

## [2.1.1]

- Improvements
  - Updated SEMA42_TryLock function to avoid unsigned integer operations wrap issue.

## [2.1.0]

- New Features
  - Added SEMA42_BUSY_POLL_COUNT parameter to prevent infinite polling loops in SEMA42 operations.
  - Added timeout mechanism to all polling loops in SEMA42 driver code.

- Improvements
  - Updated SEMA42_Lock function to return status_t instead of void for better error handling.
  - Enhanced documentation to clarify timeout behavior and return values.

## [2.0.4]

- Improvements
  - Release peripheral from reset if necessary in init function.

## [2.0.3]

- Improvements
  - Changed to implement SEMA42_Lock base on SEMA42_TryLock.

## [2.0.2]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 17.7.

## [2.0.1]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 10.3, 10.4, 14.4, 18.1.

## [2.0.0]

- Initial version.
