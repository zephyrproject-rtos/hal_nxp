# HASHCRYPT

## [2.0.0]

- Initial version.

## [2.0.1]

- Supported loading AES key from unaligned address.

## [2.0.2]

- Supported loading AES key from unaligned address for different compiler and core variants.

## [2.0.3]

- Remove SHA512 and AES ICB algorithm definitions

## [2.0.4]

- Add SHA context switch support

## [2.1.0]

- Update the register name and macro to align with new header.
- Fixed the sign-compare warning in hashcrypt_load_data.

## [2.1.1]

- Fix MISRA C-2012.

## [2.1.2]

- Support loading AES input data from unaligned address.

## [2.1.3]

- Fix MISRA C-2012.

## [2.1.4]

- Fix context switch cannot work when switching from AES.

## [2.1.5]

- Add data synchronization barrier inside hashcrypt_sha_ldm_stm_16_words() to prevent possible optimization issue.

## [2.2.0]

- Add AES-OFB and AES-CFB mixed IP/SW modes.

## [2.2.1]

- Add data synchronization barrier inside hashcrypt_sha_ldm_stm_16_words() prevent compiler from reordering memory write when -O2 or higher is used.

## [2.2.2]

- Add data synchronization barrier inside hashcrypt_sha_ldm_stm_16_words() to fix optimization issue

## [2.2.3]

- Added check for size in hashcrypt_aes_one_block to prevent overflowing COUNT field in MEMCTRL register, if its bigger than COUNT field do a multiple runs.

## [2.2.4]

- In all HASHCRYPT_AES_xx functions have been added setting CTRL_MODE bitfield to 0 after processing data, which decreases power consumption.

## [2.2.5]

- Add data synchronization barrier and instruction  synchronization barrier inside hashcrypt_sha_process_message_data() to fix optimization issue

## [2.2.6]

- Add data synchronization barrier inside HASHCRYPT_SHA_Update() and hashcrypt_get_data() function to fix optimization issue on MDK and ARMGCC release targets

## [2.2.7]

- Add data synchronization barrier inside HASHCRYPT_SHA_Update() to fix optimization issue on MCUX IDE release target

## [2.2.8]

- Unify hashcrypt hashing behavior between aligned and unaligned input data

## [2.2.9]

- Add handling of set ERROR bit in the STATUS register

## [2.2.10]

- Fix missing error statement in hashcrypt_save_running_hash()

## [2.2.11]

- Fix incorrect SHA-256 calculation for long messages with reload

## [2.2.12]

- Fix hardfault issue on the Keil compiler due to unaligned memcpy() input on some optimization levels

## [2.2.13]

- Added function hashcrypt_seed_prng() which loading random number into PRNG_SEED register before AES operation for SCA protection

## [2.2.14]

- Modify function hashcrypt_get_data() to prevent issue with unaligned access

## [2.2.15]

- Add wait on DIGEST BIT inside hashcrypt_sha_one_block() to fix issues with some optimization flags

## [2.2.16]

- Add DSB instruction inside hashcrypt_sha_ldm_stm_16_words() to fix issues with some optimization flags

## [2.2.17]

- Fix context size when hashcrypt built with reload feature
