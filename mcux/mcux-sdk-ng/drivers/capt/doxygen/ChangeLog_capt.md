# CAPT

## [2.1.0]

- New Features
  - Added new API CAPT_PollNow, to immediately launch a one-time-only,
    simultaneous poll of all specified X pins.

## [2.0.3]

- Bug Fixes
  - Fixed bug that CAPT_GetTouchData does not get right count.

## [2.0.2]

- Bug Fixes
  - Fixed the violation of MISRA-2012 rules:
    - Rule 10.3 15.5 17.7

## [2.0.1]

- Bug Fixes
  - Fixed the out-of-bounds error of Coverity caused by missing an assert sentence to avoid
    return value of CAPT_GetInstance() exceeding array bounds.

## [2.0.0]

- Initial version.
