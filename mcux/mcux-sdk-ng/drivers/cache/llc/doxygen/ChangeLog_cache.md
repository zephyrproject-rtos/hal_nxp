# Last Level CACHE

## [2.1.2]

- Bug Fixes
  - Serialized maintenance operations. The driver started an operation by writing CCUCMCR without first
    checking CCUCMAR[MNTOPACTV], so a second operation could be launched on top of an unfinished one while
    its location registers were still in use. RM 22.6.3 warns that concurrent maintenance operations may
    lead to undesired behavior, including unresponsiveness. Each operation now waits for the cache to be
    idle before it is started, and kStatus_Timeout is returned instead of overlapping two operations.
  - Sized the maintenance poll budget from the cache geometry instead of a fixed 1000 iterations. The old
    budget was smaller than the cost of a whole-cache flush, so LLC_CleanInvalidateCache() could return
    kStatus_Timeout from an operation that was progressing normally, with no API for the caller to wait on.
    The budget is now LLC_WAY_COUNT * LLC_SET_COUNT * 16, which carries margin over the measured worst case
    of every entry resident and dirty, and kStatus_Timeout means a hardware fault. The Kconfig symbol
    LLC_MAINTENANCE_TIMEOUT now defaults to 0, meaning "use that derivation"; a non-zero value still
    overrides it verbatim. Kconfig previously supplied 1000 unconditionally, which took precedence over any
    default the driver source could provide.
  - Removed the mutable global g_llcMemPhyAliasId, which returned the resolved alias index out of band from
    LLC_GetInstanceByAddr(). It made address resolution non-reentrant, was not declared in fsl_llc.h despite
    its g_ prefix, and was left equal to the column count when no window matched. Address resolution now
    returns the instance and the alias index together through a static helper.
  - Stopped copying the physical-memory base/size tables onto the stack before use. The copies duplicated
    constant data, dropped the const qualifier, and were sized from the source object, which overruns the
    destination as soon as the two are declared with different dimensions. Both tables are now indexed in
    place.
- Improvements
  - Documented that the by-address maintenance operations deliberately do not write CCUCMLR2[MNTRANGE] and
    that the hardware does not consult it for them, so a stale range value cannot widen the operation.
  - Documented that the flush set/way range operation advances way-major, which is a different traversal
    from the by-address range operation.

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
