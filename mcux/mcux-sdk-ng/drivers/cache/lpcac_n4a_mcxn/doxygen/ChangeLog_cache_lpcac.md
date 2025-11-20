# CACHE LPCAC

## [2.2.1]

- Improvements
  - Add memory barrier when enabling/disabling cache.

## [2.2.0]

- Improvements
  - Used new add macros FSL_FEATURE_SYSCON_HAS_LPCAC_CTRL_PARITY_MISS_EN_BIT and FSL_FEATURE_SYSCON_HAS_LPCAC_CTRL_PARITY_FAULT_EN_BIT to
    support some platforms which PARITY_MISS_EN and PARITY_FAULT_EN bit may be reserved.

## [2.1.1]

- Bug Fixes
  - Fixed an issue of L1CACHE_InvalidateCodeCache() function, to clean cache the LPCAC_CTRL[CLR_LPCAC] should be
    set not clear.

## [2.1.0]

- Improvements
  - Supported more features, such as write buffer contron, write buffer limit and so on.

## [2.0.0]

- Initial version.
