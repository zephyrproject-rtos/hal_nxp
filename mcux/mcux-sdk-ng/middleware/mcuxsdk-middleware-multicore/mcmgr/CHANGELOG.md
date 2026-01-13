# Changelog Multicore Manager

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [v5.0.1]

### Added

- Added frdmimxrt1186 unit testing

### Changed

- [KW43] Rename core#1 reset control register

### Fixed

- Added CX flag into CMakeLists.txt to allow c++ build compatibility.
- Fix path to mcmgr headers directory in doxyfile

## [v5.0.0]

### Added

- Added `MCMGR_BUSY_POLL_COUNT` macro to prevent infinite polling loops in MCMGR operations.
- Implemented timeout mechanism for all polling loops in MCMGR code.
- Added support to handle more then two cores. Breaking API change by adding parameter `coreNum` specifying core number in functions bellow.

  * MCMGR_GetStartupData(uint32_t *startupData, mcmgr_core_t coreNum)
  * MCMGR_TriggerEvent(mcmgr_event_type_t type, uint16_t eventData, mcmgr_core_t coreNum)
  * MCMGR_TriggerEventForce(mcmgr_event_type_t type, uint16_t eventData, mcmgr_core_t coreNum)
  * typedef void (*mcmgr_event_callback_t)(uint16_t data, void *context, mcmgr_core_t coreNum);

  When registering the event with function `MCMGR_RegisterEvent()` user now needs to
  provide `callbackData` pointer to array of elements per every core in system (see README.md for example).In case of systems with only two cores the `coreNum` in callback can be ignored as events can arrive only from one core.
  Please see Porting guide for more details: [PortingGuideTo_v5.md](doxygen/porting_guide_to_v5.md)
- Updated all porting files to support new MCMGR API.
- Added new platform specific include file `mcmgr_platform.h`.
  It will contain common platform specific macros that can be then used in `mcmgr` and application.
  e.g. platform core count `MCMGR_CORECOUNT 4`.
- Move all header files to new `inc` directory.
- Added new platform-specific include files `inc/platform/<platform_name>/mcmgr_platform.h`.

### Added

- Add MCXL20 porting layer and unit testing

## [v4.1.7]

### Fixed

- `mcmgr_stop_core_internal()` function now returns `kStatus_MCMGR_NotImplemented` status code instead
  of `kStatus_MCMGR_Success` when device does not support stop of secondary core.
  Ports affected: `kw32w1`, `kw45b41`, `kw45b42`, `mcxw716`, `mcxw727`.

## [v4.1.6]

### Added

- Multicore Manager moved to standalone repository.
- Add porting layers for imxrt700, mcmxw727, kw47b42.
- New MCMGR_ProcessDeferredRxIsr() API added.

## [v4.1.5]

### Added

- Add notification into MCMGR_EarlyInit and mcmgr_early_init_internal functions to avoid using uninitialized data in their implementations.

## [v4.1.4]

### Fixed

- Avoid calling tx isr callbacks when respective Messaging Unit Transmit Interrupt Enable flag is not set in the CR/TCR register.
- Messaging Unit RX and status registers are cleared after the initialization.

## [v4.1.3]

### Added

- Add porting layers for imxrt1180.

### Fixed

- mu_isr() updated to avoid calling tx isr callbacks when respective Transmit Interrupt Enable flag is not set in the CR/TCR register.
- mcmgr_mu_internal.c code adaptation to new supported SoCs.

## [v4.1.2]

### Fixed

- Update mcmgr_stop_core_internal() implementations to set core state to kMCMGR_ResetCoreState.

## [v4.1.0]

### Fixed

- Code adjustments to address MISRA C-2012 Rules

## [v4.0.3]

### Fixed

- Documentation updated to describe handshaking in a graphic form.
- Minor code adjustments based on static analysis tool findings

## [v4.0.2]

### Fixed

- Align porting layers to the updated MCUXpressoSDK feature files.

## [v4.0.1]

### Fixed

- Code formatting, removed unused code

## [v4.0.0]

### Added

- Add new MCMGR_TriggerEventForce() API.

## [v3.0.0]

### Removed

- Removed MCMGR_LoadApp(), MCMGR_MapAddress() and MCMGR_SignalReady()

### Modified

- Modified MCMGR_GetStartupData()

### Added

- Added MCMGR_EarlyInit(), MCMGR_RegisterEvent() and MCMGR_TriggerEvent()
- Added the ability for remote core monitoring and event handling

## [v2.0.1]

### Fixed

- Updated to be Misra compliant.

## [v2.0.0]

### Added

- Support for lpcxpresso54114 board.

## [v1.1.0]

### Fixed

- Ported to KSDK 2.0.0.

## [v1.0.0]

### Added

- Initial release.

[Unreleased]: https://github.com/nxp-mcuxpresso/mcux-mcmgr/compare/v5.0.1...HEAD
[v5.0.1]: https://github.com/nxp-mcuxpresso/mcux-mcmgr/compare/v5.0.0...v5.0.1
[v5.0.0]: https://github.com/nxp-mcuxpresso/mcux-mcmgr/compare/v4.1.7...v5.0.0
[v4.1.7]: https://github.com/nxp-mcuxpresso/mcux-mcmgr/compare/v4.1.6...v4.1.7
