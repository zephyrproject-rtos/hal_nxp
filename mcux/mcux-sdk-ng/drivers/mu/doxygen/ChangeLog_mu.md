# MU

## [2.3.1]

- Bug Fixes
  - Fixed FSL_FEATURE_MU_HAS_RESET_DEASSERT_INT macro use.

## [2.3.0]

- New Features
  - Added MU_BUSY_POLL_COUNT parameter to prevent infinite polling loops in MU operations.
  - Added timeout mechanism to all polling loops in MU driver code.
  - Added new function MU_ReceiveMsgTimeout() to include timeout mechanism.

- Improvements
  - Updated function signatures to return status codes for better error handling:
    - Changed MU_ResetBothSides to return status_t instead of void
    - Updated MU_SendMsg to return status_t for timeout indication
    - Updated MU_ReceiveMsg to use MU_TIMEOUT_VALUE (0xFFFFFFFF) as a special return value to indicate timeout
  - Enhanced documentation across all functions to clarify timeout behavior and return values.

## [2.2.0]

- New Features
  - Added API MU_GetRxStatusFlags.

## [2.1.3]

- Improvements
  - Release peripheral from reset if necessary in init function.

## [2.1.2]

- Bug Fixes
  - Fixed issue that MU_GetInstance() is defined but never used.

## [2.1.1]

- Bug Fixes
  - Fixed general interrupt comment typo.

## [2.1.0]

- Improvements
  - Added new enum mu_msg_reg_index_t.

## [2.0.7]

- Bug Fixes
  - Fixed MU_GetInterruptsPending bug that can not get general interrupt status.

## [2.0.6]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 17.7.

## [2.0.5]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 14.4, 15.5.

## [2.0.4]

- Improvements
  - Improved for the platforms which don't support
    reset assert interrupt and get the other core
    power mode.

## [2.0.3]

- Bug fixes
  - MISRA C-2012 issue fixed.
    - Fixed rules, containing: rule-10.3, rule-14.4, rule-15.5.

## [2.0.2]

- Improvements
  - Added support for MIMX8MQx.

## [2.0.1]

- Improvements
  - Added support for MCIMX7Ux_M4.

## [2.0.0]

- Initial version.
