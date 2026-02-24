# SFA

## [2.1.4]

- Bug Fixes
  - Fixed doxygen warnings: unbalanced grouping commands.

## [2.1.3]

- Improvements
  - Add timeout for APIs with dfmea issues.

## [2.1.2]

- Improvements
  - Updated SFA_ClearStatusFlag() function to support clearing all status flags.

## [2.1.1]

- Improvements
  - Updated SFA driver code to reduce code redundancy.
  - Updated the use of macros in the driver code to enable the CUT pin function.

## [2.1.0]

- Improvements
  - Updated how the clock frequency under test is calculated.
  - Supported configuration reference clock source.
  - Added clock count limit APIs.
  - Added macros to support fields that are configurable in different instances.

## [2.0.1]

- Bug Fixes

  - Fixed the issue in SFA_Mode0Calculate function.

- Improvements

  - For the devices that support RF SFA, cast the peripheral structure to SFA_Type.

## [2.0.0]

- Initial version.
