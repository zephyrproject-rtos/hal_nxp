# LPCMP

## [2.3.2]

- Improvements
  - Fixed LPCMP CERT-C issues.

## [2.3.1]

- Improvements
  - Update LPCMP driver to be compatible with platforms
    that do not support LPCMP nano power mode selection.

## [2.3.0]

- New Feature
  - Added some new features for platforms which support
    - Plus input source selection.
    - Minus input source selection.
    - CMP to DAC link.
- Improvements
  - Removed some new features for platforms which doesn't support
    - Functional clock source selection.
    - DAC high power mode selection.
    - Round Robin clock source selection.
    - Round Robin trigger source selection.
    - Round Robin channel sample numbers setting.
    - Round Robin channel sample time threshold setting.
    - Round Robin internal trigger configuration.

## [2.2.0]

- Improvements
  - Change FSL_FEATURE_LPCMP_HAS_NO_CCR0_CMP_STOP_EN to FSL_FEATURE_LPCMP_HAS_CCR0_CMP_STOP_EN.

## [2.1.3]

- New Feature
  - Added new macro to handle the case where some instances do not have the CCR0 CMP_STOP_EN bit field.

## [2.1.2]

- New Feature
  - Add macros to be compatible with some platforms that do not have the CCR0 CMP_STOP_EN bitfield.

## [2.1.1]

- Improvements
  - Release peripheral from reset if necessary in init function.

## [2.1.0]

- New Features:
  - Supported round robin mode and window mode feature.

## [2.0.3]

- Bug Fixes:
  - Fixed the violation of MISRA-2012 rule 17.7.

## [2.0.2]

- Bug Fixes:
  - The current API LPCMP_ClearStatusFlags has to check w1c bits.

## [2.0.1]

- Added control macro to enable/disable the CLOCK code in current driver.

## [2.0.0]

- Initial version.
