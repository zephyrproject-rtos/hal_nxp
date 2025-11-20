# FLEXIO

## [2.3.0]

- Improvements
  - Supported platforms which don't have DOZE mode control.
  - Added more pin control functions.

## [2.2.3]

- Improvements
  - Adapter the FLEXIO driver to platforms which don't have system level
    interrupt controller, such as NVIC.

## [2.2.2]

- Improvements
  - Release peripheral from reset if necessary in init function.

## [2.2.1]

- Improvements
  - Added doxygen index parameter comment in FLEXIO_SetClockMode.

## [2.2.0]

- New Features
  - Added new APIs to support FlexIO pin register.

## [2.1.0]

- Improvements
  - Added API FLEXIO_SetClockMode to set flexio channel counter and source clock.

## [2.0.4]

- Bug Fixes
  - Fixed MISRA 8.4 issues.

## [2.0.3]

- Bug Fixes
  - Fixed MISRA 10.4 issues.

## [2.0.2]

- Improvements
  - Split FLEXIO component which combines all flexio/flexio_uart/flexio_i2c/flexio_i2s drivers into several
    components: FlexIO component, flexio_uart component, flexio_i2c_master component, and flexio_i2s component.
- Bug Fixes
  - Fixed MISRA issues
    - Fixed rules 10.1, 10.3, 10.4, 10.7, 11.6, 11.9, 14.4, 17.7.

## [2.0.1]

- Bug Fixes
  - Fixed the dozen mode configuration error in FLEXIO_Init API. For enableInDoze = true, the configuration should
    be 0; for enableInDoze = false, the configuration should be 1.
