# FLEXBUS

## [2.1.1]

- Bug Fixes
- MISRA C-2012 issue fixed: rule 10.3, 10.4, and 14.4.

## [2.1.0]

- Bug Fixes
  - Added secondary wait states (SWS), which enabled flag into configuration structure, and
    updated FLEXBUS_Init() function according to SWS.
  - Fixed MISRA issues regarding rule 10.1/10.4.

## [2.0.2]

- Bug Fixes
  - Removed dissociated chip clearing operation while initializing the FLEXBUS module. Only
    the associated chip's register will be cleared.

## [2.0.1]

- Bug Fixes
  - Corrected FLEXBUS_Deinit() function to disable clock.

## [2.0.0]

- Initial version.
