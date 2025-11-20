# WWDT

## [2.1.10]
- Bug Fixes
  - Chek WWDT_RSTS instead of FSL_FEATURE_WWDT_HAS_NO_RESET to determine whether the peripheral can be reset.

## [2.1.9]

- Bug Fixes
  - Fixed violation of the MISRA C-2012 rule 10.4.

## [2.1.8]

- Improvements
  - Updated the "WWDT_Init" API to add wait operation. Which can avoid the TV value read by CPU still be 0xFF (reset value)
    after WWDT_Init function returns.

## [2.1.7]

- Bug Fixes
  - Fixed the issue that the watchdog reset event affected the system from PMC.
  - Fixed the issue of setting watchdog WDPROTECT field without considering the backwards compatibility.
  - Fixed the issue of clearing bit fields by mistake in the function of WWDT_ClearStatusFlags.

## [2.1.5]

- Bug Fixes
  - deprecated a unusable API in WWWDT driver.
    - WWDT_Disable

## [2.1.4]

- Bug Fixes
  - Fixed violation of the MISRA C-2012 rules Rule 10.1, 10.3, 10.4 and 11.9.
  - Fixed the issue of the inseparable process interrupted by other interrupt source.
    - WWDT_Init

## [2.1.3]

- Bug Fixes
  - Fixed legacy issue when initializing the MOD register.

## [2.1.2]

- Improvements
  - Updated the "WWDT_ClearStatusFlags" API and "WWDT_GetStatusFlags" API to match QN9090. WDTOF is not set in case
    of WD reset. Get info from PMC instead.

## [2.1.1]

- New Features
  - Added new feature definition macro for devices which have no LCOK control bit in MOD register.
  - Implemented delay/retry in WWDT driver.

## [2.1.0]

- Improvements
  - Added new parameter in configuration when initializing WWDT module. This parameter, which must be set, allows
    the user to deliver the WWDT clock frequency.

## [2.0.0]

- Initial version.
