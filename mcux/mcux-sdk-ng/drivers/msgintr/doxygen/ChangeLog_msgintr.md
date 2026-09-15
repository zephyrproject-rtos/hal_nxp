# MSGINTR

## [2.0.4]

- Bug Fixes
  - Fixed wrong base pointer in IRQ handlers for MSGINTR instances 3 to 6, which
    read and cleared the status register of instance 2 instead of their own
    instance.
  - Added missing IRQ handlers for MSGINTR instances 7 and 8.

## [2.0.3]

- New Features
  - Added common IRQ handler entry MSGINTR_DriverIRQHandler.

## [2.0.2]

- Improvements
  - Conditional compile IRQ handlers.

## [2.0.1]

- Bug Fixes
  - Fixed MISRA issue rule 8.4, 11.9, 17.7.

## [2.0.0]

- Initial version.
