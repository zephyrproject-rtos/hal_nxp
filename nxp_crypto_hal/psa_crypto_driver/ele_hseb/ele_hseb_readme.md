# ELE HSEB Port for the PSA Crypto API

## Key Management and Key Catalogs

The ELE HSEB component utilizes key catalogs for setting up the internal
keystore. These catalogs may be customized to enable or disable support for
various key types and key sizes. Constraints on these key catalogs may
be found in the HSE API reference manual.

MbedTLS3.x / PSA examples provided in the SDK are using the default key
catalogs, which can be found in the underlying `ele_hseb` component.
By default, key catalog initialization based on the configurations provided as
part of `ele_hseb` is done during the first call to `psa_crypto_init()`.
Please refer to the [Additional optional features](#additional-optional-features)
section and the ELE HSEB component documentation for more details on manual
catalog initialization and configuration customization.

# Additional optional features
The ELE HSEB PSA driver supports the following optional features
that can be configured with their respective Kconfig options:

* `MCUX_COMPONENT_component.psa_crypto_driver.ele_hseb.feature.autoformat_key_catalogs`

  *Enabled by default*. When disabled, this option removes automatic key catalog
  formatting during `psa_crypto_init()`. Users must manually format their key
  catalogs by calling `FormatKeyCatalogs()` and `HKF_Init()` before using PSA
  crypto operations.

  **NOTE**: If users pre-format their key catalogs when this option is enabled,
  the `psa_crypto_init()` function will reformat the key catalogs, removing all
  any previously stored keys.

* `MCUX_COMPONENT_component.psa_crypto_driver.ele_hseb.feature.use_custom_config_header`

  *Disabled by default*. When enabled, this option allows users to provide
  custom key catalog configurations tailored to their specific application use-
  cases. The provided PSA feature set may not be fully supported with
  custom configurations. Please refer to the default configuration for reference
  on how to configure your device.
  The custom configuration header file name is to be configured via the
  `CONFIG_ELE_HSEB_CUSTOM_CONFIG_HEADER` symbol and **MUST** be a quoted string.
  The provided custom Key Catalog initializer lists **MUST** be named
  `HSE_NVM_KEY_CATALOG_CFG` and `HSE_RAM_KEY_CATALOG_CFG`.
  The header file **SHOULD** be placed in the application's include path and
  will be automatically included by the ELE HSEB PSA driver during compilation.
  Otherwise the application include paths need to be updated by the user.

# Hardware Limitations

The ELE HSEB PSA driver implementation is subject to the following hardware
limitations.

* ELE HSEB does not implement correct handling of data cached by the chip's
  D-cache. As a result, the D-cache **MUST** be disabled when utilizing the ELE
  HSEB security engine.
  Additionally, due to errata *ERR052645*, the flash data prefetching
  functionality **MUST** also be disabled to prevent very rare, but possible,
  issues in software-only code.
  For an example on how to disable the D-cache and flash prefetching, please
  see the `BOARD_InitHardware()` function in MbedTLS/PSA examples for
  ELE HSEB-enabled boards.
* For PSA_KEY_TYPE_HMAC, the only supported key bit sizes are in the range
  [128, 1024].

# Supported Algorithms by Location

| Category                      | Algorithm / Hash                                            | Key Info                                                        | LOCAL_STORAGE      | ELE_HSEB (opaque)   |
| ----------------------------- | ----------------------------------------------------------- | --------------------------------------------------------------- | ------------------ | ------------------- |
| **Hash**                      | SHA_1/224/256/384/512/512_224/512_256, SHA3_224/256/384/512 | keyless                                                         | one-go + multipart | (n/a)               |
| **ECB_NO_PADDING**            | AES                                                         | -                                                               | one-go + multipart | not supported       |
| **CBC_NO_PADDING**            | AES                                                         | -                                                               | one-go + multipart | not supported       |
| **CTR**                       | AES                                                         | -                                                               | one-go + multipart | not supported       |
| **CFB**                       | AES                                                         | -                                                               | one-go + multipart | not supported       |
| **OFB**                       | AES                                                         | -                                                               | one-go + multipart | not supported       |
| **CCM**                       | AES                                                         | -                                                               | one-go only        | not supported       |
| **GCM**                       | AES                                                         | -                                                               | one-go only        | not supported       |
| **CMAC**                      | AES                                                         | -                                                               | one-go + multipart | not supported       |
| **HMAC**                      | SHA_1/224/256/384/512/512_224/512_256                       | HMAC key, [128, 1024] bits                                      | one-go + multipart | not supported       |
| **RSA sign (PKCS1V15 + PSS)** | SHA_1/224/256/384/512/512_224/512_256, SHA3_224/256/384/512 |                                                                 | supported          | generated keys only |
| **ECDSA**                     | SHA_1/224/256/384/512/512_224/512_256, SHA3_224/256/384/512 | SECP_R1: 256/384/521 bits; BRAINPOOL_P_R1: 256/320/384/512 bits | supported          | supported           |

> **HMAC key size constraint:** Only key bit sizes in the range [128, 1024] are
> supported (see [Hardware Limitations](#hardware-limitations)).

> **RSA opaque keys:** Imported RSA opaque keys are currently not supported.
> Opaque RSA keys may be used with keys generated via `psa_generate_key()`.
