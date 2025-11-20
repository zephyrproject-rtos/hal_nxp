# QSCI

## [2.0.4]

- Bug Fixes
- Fixed DMA transfer blocking issue by enabling tx idle interrupt after DMA transmission finishes, and
  invoke completion callback after tx idle interrupt occurs.

## [2.0.3]

- Bug Fixes
- Fixed violations of the MISRA C-2012 rules.

## [2.0.2]

- Improvements
- Supported QSCI which has 13-bit integer and 3-bit fractional baud rate selection.

## [2.0.1]

- Bug Fixes
- Fixed bug that when starting the non-blocking receive, the rx idle interrupt is not enabled, and when
  receiving is done the rx idle interrupt is not disabled.

## [2.0.0]

- Initial version.
