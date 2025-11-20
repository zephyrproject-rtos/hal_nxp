# SNVS_HP

## [2.3.2]

- Make SNVS_HP_RTC_Init()/SNVS_HP_RTC_Deinit more transparent. Use function SNVS_HP_Init()/SNVS_HP_Deinit() instead of copy of this code in SNVS_HP_RTC_XXX() function.

## [2.3.1]

- Fixed problem in SNVS_HP_RTC_Init(), which is clearing bits that should stay intact.

## [2.3.0]

- Re-map Security Violation for RT11xx specific violations.

## [2.2.0]

- Fixed doxygen issues.
- Add SNVS HP Set locks.

## [2.1.4]

- Fix MISRA issues.

## [2.1.3]

- Fixed IAR Pa082 warnings.

## [2.1.2]

- Fixed problem with initialization of the periodic interrupt frequency.
- Fixed problem with SNVS entering into fail state when HAB enters closed mode.

## [2.1.1]

- Added APIs for HP security violation status flags.

## [2.1.0]

- Added APIs for High Assurance Counter (HAC), Zeroizable Master Key (ZMK) and Software Security Violation.

## [2.0.0]

- Initial version.
