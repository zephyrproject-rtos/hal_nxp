# MMU

## [2.0.1]

- Bug Fixes
    - Add assertions to prevent unsigned integer overflow in narrowing conversions from uint32_t to uint16_t
    - Add safe type conversion with temporary variables for address-to-LUT operations
    - Add bounds checking for unit count calculations in region mapping operations
    - Follow INT31-C CERT coding standard for safe narrowing conversions

## [2.0.0]

- Initial version.
