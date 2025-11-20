# ERM

## [2.0.4]

- Improvements
  - Change erm_memory_channel_t to uint32_t.
  - Support channel number 16-23.

## [2.0.3]

- Bug Fixes
  - Fixed s_ermResets variable declaration issue.

## [2.0.2]

- Improvements
  - Reset the peripheral during initialization, otherwise some platforms may not work.
- Bug Fixes
  - Only keep bit 0-3 of ERM_GetInterruptStatus() as it may get other channel results in higher bits.

## [2.0.1]

- Improvements
  - Update driver to support fewer channel.
- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 10.3.

## [2.0.0]

- Initial version.
