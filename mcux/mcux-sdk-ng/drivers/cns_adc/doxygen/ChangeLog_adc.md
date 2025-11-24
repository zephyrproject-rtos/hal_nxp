# CNS_ADC

## [2.2.1]

- Improvements
  - Fixed CERT-C issues.

## [2.2.0]

- Improvements
  - Updated cns adc trigger sources.
  - Migrated cns adc trigger sources enumeration from cns_adc.h to device.h
  - Reserved single-end mode channel 15, differential mode channel 5, and channel 15.

## [2.1.0]

- Bug Fixes
  - Fixed temperature measurement error, and provided 'enableChop' member to control the ADC chop.

## [2.0.2]

- Bug Fixes

  - Fixed ADC scan channel misconfiguration issue.
  - Fixed violation of MISRA C-2012 rule 10.1 and rule 10.4.

- Improvements

  - Added new member "enableInputBufferChop" into "adc_config_t" to enable/disable input buffer chopper.

## [2.0.1]

- Bug Fixes
  - Fixed MISRA-2012 rules.
    - Rule 14.2, rule 10.3.

## [2.0.0]

- Initial version.
