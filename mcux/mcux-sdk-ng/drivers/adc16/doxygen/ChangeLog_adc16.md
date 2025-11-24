# ADC16

## [2.3.0]

- Improvements
  - Added new API ADC16_EnableAsynchronousClockOutput() to enable/disable ADACK output.
  - In ADC16_GetDefaultConfig(), set enableAsynchronousClock to false.

## [2.2.0]

- Improvements
  - Added hardware average mode in adc_config_t structure, then the hardware average mode
    can be set by invoking ADC16_Init() function.

## [2.1.0]

- New Features:
  - Supported KM series' new ADC reference voltage source, bandgap from PMC.

## [2.0.3]

- Bug Fixes
  - Fixed IAR warning Pa082: the order of volatile access should be defined.

## [2.0.2]

- Improvements
  - Used conversion control feature macro instead of that in IO map.

## [2.0.1]

- Bug Fixes
  - Fixed MISRA-2012 rules.
    - Rule 16.4, 10.1, 13.2, 14.4 and 17.7.

## [2.0.0]

- Initial version
