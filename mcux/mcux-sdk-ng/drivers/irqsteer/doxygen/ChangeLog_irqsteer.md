# IRQSTEER

## [2.1.5]

- Bug Fixes
  - Fixed the violation of MISRA C-2012 Rules and CERT-C.

## [2.1.4]

- Bug Fixes
  - Fixed the bug that IRQSTEER_GetMasterNextInterrupt may check wrong register
    with platform which has odd number of CHn_MASK registers.

## [2.1.3]

- Bug Fixes
  - Fixed the violation of MISRA C-2012 Rules.

## [2.1.2]

- Improvements
  - Cleanup the index calculation.

## [2.1.1]

- Bug Fixes
  - Fixed conditional compile with FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL false.

## [2.1.0]

- New Features
  - Added new APIs IRQSTEER_InterruptIsEnabled, IRQSTEER_GetMasterIrqCount.
  - Added new configuration options FSL_IRQSTEER_USE_DRIVER_IRQ_HANDLER, and
    FSL_IRQSTEER_ENABLE_MASTER_INT.
  - Added new APIs IRQSTEER_GetMasterInterruptsStatus.

## [2.0.2]

- Bug Fixes

  - Fixed the violation of MISRA C-2012 Rules: 10.1, 10.4, 10.7, 10.8, 12.2, 17.7, 20.7.

- New Features

  - Added control macro to enable/disable the CLOCK code in current driver.

## [2.0.0]

- Initial version.
