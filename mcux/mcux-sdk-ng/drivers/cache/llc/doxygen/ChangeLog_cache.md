# Last Level CACHE

## [2.1.1]

- Bug Fixes
  - Stopped reading CCUPMHI[FREERUN] in LLC_GetCapabilities() and removed the now-meaningless freeRun
    member of llc_feature_capability_t. The RM 1.13 header update deleted that bitfield, so the
    capability is no longer defined by the IP register map.

## [2.1.0]

- New Features
  - Added per-instance callback registration and common interrupt dispatch with combined status flags.
- Improvements
  - Used device feature macros for LLC way, set, and way-partition counts.
  - Split large by-range maintenance requests into bounded operations based on the cache capacity.
  - Changed LLC_SetCorrectableErrorInterruptThreshold() to a static inline function.
- Bug Fixes
  - Fixed maintenance range encoding to use the zero-based CCUCMLR2[MNTRANGE] value.
  - Rejected zero-sized and overflowing maintenance ranges.
  - Fixed physical-memory alias resolution for by-range maintenance.
  - Rejected by-range requests that cross an LLC physical-memory alias boundary instead of truncating them.
  - Fixed disabling the correctable-error interrupt to clear both detection and interrupt enable bits.

## [2.0.1]

- Bug Fixes
  - Fixed boundary check in LLC_GetInstanceByAddr() to correctly include the last address of the memory range.

## [2.0.0]

- Initial version.
