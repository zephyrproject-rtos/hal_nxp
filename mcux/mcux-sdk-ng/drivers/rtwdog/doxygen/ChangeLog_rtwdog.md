# RTWDOG

## [2.1.4]

- Bug Fixes
  - Fixed CERT INT30-C, INT31-C issue.
  - Make API RTWDOG_CountToMesec return 0 if result overflow.

## [2.1.3]

- Improvements
  - Waited the over status after CS register operation in case next CS operation causes problem.

## [2.1.2]

- Bug Fixes
  - Fixed doxygen issue.

## [2.1.1]

- Bug Fixes
  - MISRA C-2012 issue fixed.
    - Fixed rules, containing: rule-10.3, rule-10.8, rule-11.9, rule-14.4, rule-15.5.

## [2.1.0]

- Improvements
  - Added an API to enable or disable the window mode.
  - Added an API to convert a raw count value to millisecond.
  - Used AT_QUICKACCESS_SECTION_CODE macro to decorate RTWDOG_Init, and copied this function from flash to
    QUICKACCESS section.

## [2.0.1]

- Bug Fixes
  - Fixed bug in the RTWDOG_Init; added check for register's unlock status when configuring the RTWDOG in
    RTWDOG_init.

## [2.0.0]

- Initial version.
