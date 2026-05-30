# TDET

## [2.3.2]

- New Features
  - Added common IRQ handler entry TDET_DriverIRQHandler.

## [2.3.1]

- Added support for KW43 device.

## [2.3.0]

- Added enum for TIF10.

## [2.2.0]

- Added support for chips without active tamper pins.

## [2.1.1]

- Added clearing SR_TAF and SR_DTF into TDET_Init().
  - Fix typo in kTDET_ClockType64Hz comment.

## [2.1.0]

- Added setting of disabling prescaler on tamper event into TDET_SetConfig() and TDET_GetDefaultConfig functions.

## [2.0.0]

- Initial version.
