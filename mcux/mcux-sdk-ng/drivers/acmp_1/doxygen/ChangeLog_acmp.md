# ACMP

## [2.0.2]

- Bug Fixes
  - Fixed the out-of-bounds error of Coverity caused by missing an assert sentence to avoid
    the return value of ACMP_GetInstance() exceeding the array bounds.
  - Fixed the violation of MISRA C-2012 rules:
    - Rule 3.1 8.3 10.3 17.7.

## [2.0.1]

- Bug Fixes
  - Fixed the missing right pair definition for extern C.

## [2.0.0]

- Initial version.
