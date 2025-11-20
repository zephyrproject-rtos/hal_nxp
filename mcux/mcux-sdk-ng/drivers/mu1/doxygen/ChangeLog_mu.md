# MU

## [2.8.1]

- Bug Fixes
  - Avoid incorrect MU_BUSY_POLL_COUNT macro use.

## [2.8.0]

- New Features
  - Added MU1_BUSY_POLL_COUNT parameter to prevent infinite polling loops in MU operations.
  - Added timeout mechanism to all polling loops in MU driver code.

- Improvements
  - Updated function signatures to return status codes for better error handling:
    - Changed MU_ResetBothSides to return status_t instead of void
    - Updated MU_SendMsg to return status_t for timeout indication
    - Added new function MU_ReceiveMsgTimeout() to include timeout mechanism.
  - Enhanced documentation across all functions to clarify timeout behavior and return values.

## [2.7.0]

- New Features
  - Added API MU_GetRxStatusFlags.

## [2.6.0]

- New Features
  - Added API MU_GetInterruptsPending.

## [2.5.1]

- Bug Fixes
  - Fixed the bug that MU_TriggerGeneralPurposeInterrupts and MU_TriggerInterrupts
    may trigger previous triggered general purpose interrupts again by mistake.

## [2.5.0]

- New Features
  - Supported more than 4 general purpose interrupts.
  - Added seperate APIs for general purpose interrupts.

## [2.4.0]

- Improvements
  - Supported the case that some features only avaiable with specific instances.
    These features include Hardware Reset, Boot Peer Core, Hold Reset.
    When using the features with instances which don't support them, driver
    will report error.

## [2.3.3]

- Improvements
  - Release peripheral from reset if necessary in init function.

## [2.3.2]

- Improvements
  - Supported platforms which don't have CCR0[RSTH], CCR0[CLKE], CCR0[HR], CCR0[HRM].

## [2.3.1]

- Bug Fixes
  - Fixed build error for platforms which have CCR0[RSTH], but no CCR0[NMI].

## [2.3.0]

- New features
  - Added support for i.MX RT7xx.

## [2.2.1]

- Bug Fixes
  - Fixed issue that MU_GetInstance() is defined but never used.

## [2.2.0]

- New features
  - Added support for i.MX RT118x.
- Bug Fixes
  - Fixed general purpose interrupt bug.
- Other Changes
  - Change _mu_interrupt_trigger item value.

## [2.1.2]

- Bug Fixes
  - Fixed bug that general purpose interrupt can't be configured.

## [2.1.1]

- Bug Fixes
  - Fixed MISRA C-2012 issues.

## [2.1.0]

- Improvements
  - Added new enum mu_msg_reg_index_t.

## [2.0.0]

- Initial version.
