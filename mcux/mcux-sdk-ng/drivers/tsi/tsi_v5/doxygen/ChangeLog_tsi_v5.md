# TSI_V5

## [2.6.1]

- Improvements
  - The SHIELD register write was fixed to be rewritten.

## [2.6.0]

- Improvements
  - Add API TSI_ShieldChannelConfig to config all TSI shield channels.

## [2.5.0]

- Improvements
  - Add API TSI_EnableShieldChannels to enable/disable TSI shield channels.

## [2.4.0]

- Bug Fixes
  - Fixed some elements in the array tsi_sensitivity_xdn_option_t does not match the S_XDN bits.

## [2.3.0]

- Other Changes
  - Changed the TSI SINC cutoff divider number.

## [2.2.0]

- Improvements
  - Extended enableShield items from tsi_selfCap_config_t structure to cover three shields in the ke17z series.
  - Added interface for getting instance from TSI base address and apply it for clock and IRQ enable/disable.

## [2.1.2]

- Bug Fixes
  - Fixed the violations of MISRA C-2012 rules: 10.1, 10.8.

## [2.1.1]

- Improvements
  - Improved the module's noise immunity in mutual cap mode by setting M_TRIM2[0] to 1 in TSI_MUL1 register.
- Bug Fixes
  - Fixed the violations of MISRA C-2012 rules:
    - Rule 10.1, 10.3, 10.4, 10.8, 12.2, 14.4, 17.7.

## [2.1.0]

- Bug Fixes
  - Fixed incorrect TSI SSC clock calculation.

## [2.0.1]

- Improvements
  - Added functions for M_TX_USED bitfield for ke16z only (Unused TX mutual pins can work as GPIO).

## [2.0.0]

- Initial version.
