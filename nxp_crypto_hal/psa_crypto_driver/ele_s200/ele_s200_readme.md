# Key Locations

This section outlines the different key storage locations supported by the
PSA Crypto API integration with the S200 secure subsystem.

## `PSA_KEY_LOCATION_LOCAL_STORAGE`

Transparent keys stored in plaintext in the PSA keystore.

### Key Utilization
The general way such keys are utilized for a given crypto operation is:
1. take the plaintext key and import it into the S200,
2. do the crypto operation,
3. delete the key from the S200.

An exception to this are multipart operations, which will keep the given
key in the S200 internal keystore up until the operation is finished or aborted.

## `PSA_KEY_LOCATION_S200_KEY_STORAGE`

EdgeLock2Go opaque key storage. Such a key location cannot be used to generate
new keys on the device and may only be imported with `psa_import_key()`.
The key blobs are then stored in the PSA keystore without modification,
still encrypted. These keys are never readable in plaintext by software.

### Key Utilization
Key Utilization is the same as with `PSA_KEY_LOCATION_LOCAL_STORAGE`.

## `PSA_KEY_LOCATION_S200_KEY_STORAGE_NON_EL2GO`

Generic opaque key storage. The key blobs are stored as die-unique encrypted
blobs and can never be read in plain text after their creation.

Keys in this location may be created with:
* `psa_generate_key()` to generate opaque keys. Such keys are stored in the PSA
  keystore as die-unique encrypted blobs to preserve opacity. These keys are
  never readable in plaintext by software.
* `psa_import_key()` to import keys from external sources. The key data to be
  imported may be:
  * transparent key material that is converted to an opaque blob and stored
    encrypted in the PSA keystore,
  * an already-opaque die-unique blob that is placed into the PSA keystore
    without modification, still encrypted.
* `psa_export_key()` to export opaque key blobs. The exported data is the
  die-unique encrypted blob itself.

  The size of the key blob is the size of the transparent key material plus the
  blob overhead of 24 Bytes (`PSA_S200_NON_EL2GO_BLOB_OVERHEAD`)
  (i.e. `PSA_EXPORT_KEY_OUTPUT_SIZE(key_type, key_bits) + PSA_S200_NON_EL2GO_BLOB_OVERHEAD`)
  **except for ECC key pairs**.
  ECC key pairs are wrapped as full key pairs, so their size is
  (private key + public key) plus the blob overhead of 24 Bytes.
  Size of an ECC key pair blob can be calculated as
  `((bits + 7) / 8) * 3 + 24` Bytes.
  The macro `PSA_S200_NON_EL2GO_BLOB_EXPORT_SIZE(key_type, bits)` can be used
  to calculate the export size for non-EL2GO opaque keys.

### Key Utilization
Key Utilization is the same as with `PSA_KEY_LOCATION_LOCAL_STORAGE`.

## `PSA_KEY_LOCATION_S200_DATA_STORAGE`

EdgeLock2Go data storage. The data is unwrapped from the EL2GO blob and placed
into the PSA keystore in plaintext when imported with `psa_import_key()`.
The plaintext data may be retrieved by calling `psa_export_key()`.

# Additional optional features
The ELE S200 PSA driver supports the following additional optional features with
their respective Kconfig options:

* Hash context persistence across power cycles. Lowpower modes that preserve RAM
  will maintain hash operation state. This feature is enabled through the
  `MCUX_COMPONENT_component.psa_crypto_driver.ele_s200.feature.hash_context_persistence`
  config option.
  On legacy SDK packages, please define the `CONFIG_ELE_S2XX_ENABLE_HASH_CONTEXT_IMPORT_EXPORT`
  macro when building your application.

# Cryptographic Support for Given Key Locations

* Keyless algorithms
     * Hashes :
          * One-Go: SHA1, SHA224-SHA512, SHA3_224-SHA3_512 **(on KW45 without SHA3)**
          * Multipart: same as One-Go

* `PSA_KEY_LOCATION_LOCAL_STORAGE`
     * Ciphers :
          * Unauthenticated :
               * One-Go :
                    * AES : ECB_NO_PADDING, CBC_NO_PADDING, CTR
          * Authenticated :
               * One-Go :
                    * AES : GCM, CCM
     * MAC :
          * One-Go :
               * CMAC : AES
               * HMAC : SHA1, SHA224-SHA512 **(on KW45 only SHA256)**
          * Multipart : KW47 same as One-Go,
                        KW45 no dedicated support, but partially accelerated via Multipart Hash
     * Asymmetric Cryptography :
          * Sign/Verify Hash :
               * SECP-R1 192-521
               * Brainpool-R1 192, 224, 256, 320, 384, 512 **(on KW47 only)**
          * Sign/Verify Message :
               * Ed25519

* `PSA_KEY_LOCATION_S200_KEY_STORAGE`
     * Ciphers :
          * Unauthenticated :
               * One-Go :
                    * AES : ECB_NO_PADDING, CBC_NO_PADDING, CTR
          * Authenticated :
               * One-Go :
                    * AES : GCM, CCM
     * MAC :
          * One-Go :
               * CMAC : AES
               * HMAC : SHA1, SHA224-SHA512 **(on KW45 only SHA256)**
     * Asymmetric Cryptography :
          * Sign/Verify Hash :
               * SECP-R1 224-521
          * Sign/Verify Message :
               * Ed25519

* `PSA_KEY_LOCATION_S200_KEY_STORAGE_NON_EL2GO`
     * Ciphers :
          * Unauthenticated :
               * One-Go :
                    * AES : ECB_NO_PADDING, CBC_NO_PADDING, CTR
          * Authenticated :
               * One-Go :
                    * AES : GCM, CCM
     * MAC :
          * One-Go :
               * CMAC : AES
               * HMAC : SHA1, SHA224-SHA512 **(on KW45 only SHA256)**
     * Asymmetric Cryptography :
          * Sign/Verify Hash :
               * SECP-R1 192-521
               * Brainpool-R1 192, 224, 256, 320, 384, 512 **(on KW47 only)**
          * Sign/Verify Message :
               * Ed25519, Ed25519ph
