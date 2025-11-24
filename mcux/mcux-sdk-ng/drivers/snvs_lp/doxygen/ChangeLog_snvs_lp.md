# SNVS_LP

## [2.4.6]

- Fix a bug in SNVS_LP_EnableRxActiveTamper() where assignments to base->LPATRC2R were done wrongly to LPATRC1R.

## [2.4.5]

- Fix a bug in SNVS_LP_EnableRxActiveTamper() where assignments to base->LPATRC1R would overwrite previously set bits.

## [2.4.4]

- Make SNVS_LP_SRTC_Init()/SNVS_LP_SRTC_Deinit more transparent. Use function SNVS_LP_Init()/SNVS_LP_Deinit() instead of copy of this code in SNVS_LP_SRTC_XXX() function.

## [2.4.3]

- Fixed problem in SNVS_LP_SRTC_Init(), which is clearing bits that should stay intact.

## [2.4.2]

- Updated driver to match with new device header files.

## [2.4.1]

- Fixed MISRA issues.

## [2.4.0]

- Fix backward compatibility with version 2.2.x.

## [2.3.0]

- Add active pin, clock, voltage and temperature tamper features.

## [2.2.0]

- Fixed doxygen issues.
- Add Transition SNVS SSM state to Trusted/Non-secure from Check state.

## [2.1.2]

- Fix MISRA issues.

## [2.1.1]

- Fix IAR Pa082 warning.

## [2.1.0]

- Added APIs for Zeroizable Master Key (ZMK) and Monotonic Counter (MC).

## [2.0.0]

- Initial version.
