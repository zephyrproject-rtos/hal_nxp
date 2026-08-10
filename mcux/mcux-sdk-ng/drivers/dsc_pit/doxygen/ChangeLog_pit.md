# PIT

## [2.3.3]

- Bug Fixes
- Fixed CERT INT31-C violations in the CTRL register accesses: complements of 16-bit register masks are now explicitly
  cast to uint16_t before the read-modify-write, and the bool bEnableNegativeEdge field is normalized to 1U/0U before
  the PIT_CTRL_PRESET_POLARITY() write.

## [2.3.2]

- Improvements
- Guarded slave mode support (pit_config_t.bEnableSlaveMode, PIT_EnableSlaveMode(), and the CTRL SLAVE bitfield write)
  behind FSL_FEATURE_PIT_CTRL_HAS_SLAVE so devices whose PIT CTRL has no SLAVE bit build correctly.

## [2.3.1]

- Bug Fixes
- Fixed violations of MISRA C-2012 rule 10.3.

## [2.3.0]

- Improvements
- Filtered Preset input to reset PIT counter.
- Support SYNC_OUT output stretch and toggle mode.
- Added PIT_SetPresetFiltConfig() to set FILT register configurations.
- Added PIT_SetSyncOutConfig() to set SYNC register configurations.

## [2.2.1]

- Bug Fixes
- Fixed violations of the MISRA C-2012 rules.

## [2.2.0]

- Improvements
- Updated pit_config_t member naming.
- Removed some APIs for prescaler and clock source selection.

## [2.1.0]

- Improvements
- Updated PIT clock source and PIT prescaler with more meaningful comments.
- Updated PIT_SetTimerPeriod() and PIT_GetCurrentTimerCount() with 16-bit parameter.
- Deleted mask parameter for PIT_ClearStatusFlags/PIT_EnableInterrupts/PIT_DisableInterrupts.
- Added PIT_SetTimerClockSource() API to configure clock source.
- Added PIT_EnableSlaveMode() API to configure slave mode.

## [2.0.1]

- New Features
- Added PIT_SetTimerPrescaler() API to configure clock prescaler value.

## [2.0.0]

- Initial version.
