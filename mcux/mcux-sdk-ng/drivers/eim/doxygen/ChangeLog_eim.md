# EIM

## [2.1.0]

- New Features
  - Enhanced EIM driver support for extended memory channels (16-30).
  - Added new API EIM_InjectDataWordBitError() and EIM_GetDataWordBitMask() to support more data words (2-6).
- Improvements
  - Change eim_memory_channel_t to uint32_t.

## [2.0.3]

- Bug Fixes
  - Fixed s_eimResets variable declaration issue.

## [2.0.2]

- Improvements
  - Reset the peripheral during initialization, otherwise some platforms may not work.
- Bug Fixes
  - Fixed incorrect register access in EIM_GetDataBitMask().

## [2.0.1]

- Improvements
  - Update driver to support fewer channel.
- Bug Fixes
  - Fixed violations of MISRA C-2012 rule 10.3.

## [2.0.0]

- Initial version.
