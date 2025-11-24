# GPIO

## [2.0.7]

- Bug Fixes
  - Fixed coverity MSG issues with CERT INT30-C compliance.

## [2.0.6]

- Bug Fixes
  - Fixed compile warning: 'GPIO_GetInstance' defined but not used
    when macro FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL is defined.

## [2.0.5]

- Bug Fixes
  - Fixed MISRA C-2012 issue: rule-17.7.

## [2.0.4]

- Improvements
  - Updated the GPIO_PinWrite to use atomic operation if possible.
- Bug Fixes
  - Fixed GPIO_PortToggle bug with platforms don't have register DR_TOGGLE.

## [2.0.3]

- Bug Fixes
  - MISRA C-2012 issue fixed.
    - Fixed rules, containing: rule-10.3, rule-14.4, and rule-15.5.

## [2.0.2]

- Bug Fixes
  - Fixed the bug of enabling wrong GPIO clock gate in initial API. Since some GPIO instances may not have a clock
    gate enabled, it checks the clock gate number and makes sure the clock gate is valid.

## [2.0.1]

- Improvements
  - API interface changes:
    - Refined naming of the API while keeping all original APIs, marking them
      as deprecated. Original APIs will be removed in next release. The
      main change is to update the API with prefix of _PinXXX() and
      _PortXXX().

## [2.0.0]

- Initial version.
