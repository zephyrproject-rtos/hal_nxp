# DCDC

## [2.1.0]

- Improvements
  - Divided the DCDC_AdjustTargetVoltage() into two APIs for two different modes.

## [2.0.4]

- Bug Fixes
  - Fixed MISRA-2012 rules.
    - Rule 16.4, 16.3 and 16.1.

## [2.0.3]

- Bug Fixes
  - Fixed MISRA-2012 rules.
    - Rule 14.4, 10.1, 10.4 and 17.7.

## [2.0.2]

- Bug Fixes
  - Updated judgement condition in DCDC_AdjustTargetVoltage API to avoid the program counter always being trapped
    while in loop.

## [2.0.1]

- New Features
  - Added support to the devices with "1P45" or "1P5" registers' naming for the lower voltage's power output.

## [2.0.0]

- Initial version.
