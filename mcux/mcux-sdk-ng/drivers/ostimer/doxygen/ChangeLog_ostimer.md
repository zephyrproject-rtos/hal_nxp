# OSTIMER

## [2.3.0]

- New Features
  - Added `OSTIMER_SetMatchValueSafe()` with post-write synchronization and missed-event detection.
    After writing the match registers, it waits for `OSEVENT_CTRL[MATCH_WR_RDY]` to clear, then
    checks whether the match moment has already passed:
    - Returns `kStatus_Success` and enables the interrupt if the match is still in the future, or if
      the hardware interrupt flag is already set (ISR fires immediately on enable).
    - Returns `kStatus_Fail` and leaves the interrupt **disabled** if the match was missed without
      the hardware capturing it; the caller must handle the missed event.
  - **API selection guide — `OSTIMER_SetMatchValue` vs `OSTIMER_SetMatchValueSafe`:**
    - Use `OSTIMER_SetMatchValue()` when the delta between now and `count` is reliably larger than
      ~7 OSTimer ticks (e.g. > 200 µs at 32 kHz). It omits the post-write `MATCH_WR_RDY` poll and
      missed-event check, so it returns faster. It's suitable for **most use cases**.
    - Use `OSTIMER_SetMatchValueSafe()` when the match delta is small or unpredictable. The extra
      synchronization cost (~7 OSTimer ticks) is the trade-off for a guaranteed success/fail result.
- Bug Fixes
  - Fixed `OSTIMER_GetMatchValue()` missing binary-encoded counter guard; it now returns the raw
    binary value on devices with binary-encoded registers.
- Improvements
  - Removed useless `tmp` variable in `OSTIMER_SetMatchRawValue()`.
  - Clarified return value type for counter get APIs.

## [2.2.6]

- Improvements
  - Drop the check of MATCH_WR_RDY and ostimer counter value in OSTIMER_SetMatchRawValue. In most applications, they are useless and may bring at least 7 OSTimer ticks latency, which is unacceptable when OSTimer is working under slow peripheral clock.
  - Optimize software gray code to binary conversion: replaced loop-based implementation with branchless bitwise operations.

## [2.2.5]

- Improvements
  - Support binary encoded ostimer.

## [2.2.4]

- Bug Fixes
  - Fixed CERT INT31-C violations.

## [2.2.3]

- Improvements
  - Disable and clear pending interrupts before disabling the OSTIMER clock to avoid interrupts being
    executed when the clock is already disabled.

## [2.2.2]

- Improvements
  - Support devices with different OSTIMER instance name.

## [2.2.1]

- Improvements
  - Release peripheral from reset if necessary in init function.

## [2.2.0]

- Improvements
  - Move the PMC operation out of the OSTIMER driver to board specific files.
  - Added low level APIs to control OSTIMER MATCH and interrupt.

## [2.1.2]

- Bug Fixes
  - Fixed MISRA-2012 rule 10.8.

## [2.1.1]

- Bug Fixes
  - removes the suffix 'n' for some register names and bit fields' names
- Improvements
  - Added HW CODE GRAY feature supported by CODE GRAY in SYSCTRL register group.

## [2.1.0]

- Bug Fixes
  - Added a workaround to fix the issue that no interrupt was reported when user set smaller period.
  - Fixed violation of MISRA C-2012 rule 10.3 and 11.9.
- Improvements
  - Added return value for the two APIs to set match value.
    - OSTIMER_SetMatchRawValue
    - OSTIMER_SetMatchValue

## [2.0.3]

- Bug Fixes
  - Fixed violation of MISRA C-2012 rule 10.3, 14.4, 17.7.

## [2.0.2]

- Improvements
  - Added support for OSTIMER0

## [2.0.1]

- Improvements
  - Removed the software reset function out of the initialization API.
  - Enabled interrupt directly instead of enabling deep sleep interrupt. Users need to enable the deep sleep
    interrupt in application code if needed.

## [2.0.0]

- Initial version.
