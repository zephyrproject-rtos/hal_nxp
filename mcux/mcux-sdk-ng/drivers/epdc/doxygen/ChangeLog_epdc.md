# EPDC

## [2.0.2]

- Improvements
  - Release peripheral from reset if necessary in init function.

## [2.0.1]

- Bug Fixes
  - Fixed bug in EPDC_ClearStatusFlags and EPDC_ClearLutCompleteStatusFlags that IRQ.CLR and
    IRQx.CLR should be written to clear status.

## [2.0.0]

- Initial version.
