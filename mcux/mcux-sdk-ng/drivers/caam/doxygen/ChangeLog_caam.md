# CAAM

## [2.4.0]

- Add new APIs for native asymmetric operations (RSA, ECC) instead of only accelerating mathematical primitives
  and support for black keys and blobs for both symmetric and asymmetric operations.

## [2.3.2]

- Fix MISRA-2012 issues.

## [2.3.1]

- Modified function caam_aes_ccm_check_input_args() to allow payload be empty as is specified in NIST800-38C Section 5.3..

## [2.3.0]

- Add support for SHA HMAC.

## [2.2.4]

- Fix issue where the outputSize parameter of CAAM_HASH_Finish() has impact on hash calculation.

## [2.2.3]

- Fix DCACHE invalidation in CAAM_HASH_Finish().

## [2.2.2]

- Modify RNG to not reseed with each request.

## [2.2.1]

- Fixed AES-CCM decrypt failing with TAG length bigger than 8 byte.

## [2.2.0]

- Added API for Blob functions and CRC

## [2.1.6]

- Improve DCACHE handling. Requires CAAM used and cached memory set in write-trough mode.

## [2.1.5]

- Support EXTENDED data size for all AES, HASH and RNG operations.
- Support multiple De-Initialization/Initialization of CAAM driver within one POR event.

## [2.1.4]

- Fix MISRA-2012 issues.

## [2.1.3]

- Fix MISRA-2012 issues.

## [2.1.2]

- Add data offset feature to provide support for mirrored (high-speed) memory.

## [2.1.1]

- Add DCACHE support.

## [2.1.0]

- Add return codes check and handling.

## [2.0.3]

- Use MACRO instead of numbers in descriptor.
- Correct descriptor size mask.

## [2.0.2]

- Add Data and Instruction Synchronization Barrier in caam_input_ring_set_jobs_added()
  to make sure that the descriptor will be loaded into CAAM correctly.

## [2.0.1]

- Add Job Ring 2 and 3.

## [2.0.0]

- Initial version.
