# IOCON

## [2.2.0]

- Improvements
  - Removed duplicate macro defintions.
  - Renamed 'IOCON_I2C_SLEW' macro to 'IOCON_I2C_MODE' to match its companion 'IOCON_GPIO_MODE'. The original is kept as a deprecated symbol.

## [2.1.2]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 10.3.

## [2.1.1]

- Updated left shift format with mask value instead of a constant value to automatically adapt to all platforms.

## [2.1.0]

- Added a new IOCON_PinMuxSet() function with a feature IOCON_ONE_DIMENSION for LPC845MAX board.

## [2.0.0]

- Initial version.
