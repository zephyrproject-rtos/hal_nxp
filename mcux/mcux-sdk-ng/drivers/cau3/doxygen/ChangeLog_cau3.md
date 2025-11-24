# CAU3

## [2.0.5]

- Improvements
  - Fix MISRA C-2012 issue.

## [2.0.4]

- Improvements
  - Fix MISRA C-2012 issue.

## [2.0.3]

- Improvements
  - Fix MISRA C-2012 issue.

## [2.0.2]

- New Features
  - Added FSL_CAU3_USE_HW_SEMA compile time macro. When enabled, all CAU3 API functions
    lock hardware semaphore on function entry and release the hardware semaphore on function return.

## [2.0.1]

- Improvements
  - Replaced static cau3_make_mems_private() with public CAU3_MakeMemsPrivate().
  - Removed the cau3_make_mems_private() from CAU3_Init to allow loading multiple images.

## [2.0.0]

- Initial version.
