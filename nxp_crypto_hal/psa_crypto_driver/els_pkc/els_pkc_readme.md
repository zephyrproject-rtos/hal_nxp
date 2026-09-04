# PSA Key Locations

## PSA_KEY_LOCATION_S50_ENC_STORAGE_KEY

- **What it is:** Encrypted keys ("external" keys). Key material is encrypted by the secure
  enclave but can be **decrypted into host memory**.
  This is an EdgeLock2Go key location that can only be used in conjunction with
  the [EdgeLock2Go service](https://edgelock2go.com/).
- **Import:** Integrity-protected TLV structure containing key material + attributes.
  Only persistent keys are supported (requires PSA storage or TF-M).
  `key_id` must be set in both the TLV and attributes.
- **Loading:** Secure enclave decrypts key material into host memory. From that point,
  the key is treated as LOCAL_STORAGE.
- **Export:** Exports key material in PSA format, so without TLV container and in plaintext.
- **Algorithm support:** Same as `external` column in all tables below.

## PSA_KEY_LOCATION_S50_ENC_STORAGE_DATA

- **What it is:** Encrypted data ("external"). Same concept as ENC_STORAGE_KEY but
  for **data** rather than structured keys.
  This is an EdgeLock2Go key location that can only be used in conjunction with
  the [EdgeLock2Go service](https://edgelock2go.com/).
- **Import/Loading/Export:** Identical behavior to `S50_ENC_STORAGE_KEY`.
- **Algorithm support:** Same as `external` column.

## PSA_KEY_LOCATION_S50_BLOB_STORAGE

- **What it is:** Keys wrapped/encrypted by the secure enclave ("internal").
  Key material **never leaves the secure enclave**. It is unwrapped into a keyslot
  inside the enclave.
  This is an EdgeLock2Go key location that can only be used in conjunction with
  the [EdgeLock2Go service](https://edgelock2go.com/).
- **Import:** Integrity-protected TLV structure. Only persistent keys, so `key_id` is required.
  No validation that the secure subsystem actually supports the selected key attributes at
  import time.
- **Loading:** Key is unwrapped into a free keyslot in the secure enclave keystore.
- **Export:** Only `export_public_key` is supported.
- **Algorithm support:** Restricted to what ELS hardware supports (see `internal` column).
  Always implicitly accelerated.

## PSA_KEY_LOCATION_S50_RFC3394_STORAGE

- **What it is:** Keys wrapped using **RFC 3394 AES key-wrap** (NIST standard), protected by the secure
  enclave using the `NXP_DIE_KEK_SK` device key. Key material never leaves the enclave - it is unwrapped
  into a keyslot inside the enclave.
- **Import:** RFC 3394-wrapped blob validated by the Oracle (`Oracle_Utils.c`). AES and ECC (P-256) key
  types supported. Key is unwrapped via ELS `KeyImport` using the `NXP_DIE_KEK_SK` KEK.
- **Loading:** Key is unwrapped into a free keyslot in the secure enclave keystore using `NXP_DIE_KEK_SK`.
  Equivalent to BLOB_STORAGE after loading.
- **Export:** Only `export_public_key` is supported.
- **Copy:** The only location that supports opaque key copy (`psa_copy_key`).
- **Algorithm support:** Same as `internal` column. AES keys must be 128 or 256 bits. ECC limited to P-256.

## Supported Algorithms by Location

| Category                      | Algorithm      | external (ENC_KEY / ENC_DATA)| internal (BLOB)                     | internal (RFC3394)                     |
| ----------------------------- | -------------- | ---------------------------- | ----------------------------------- | -------------------------------------- |
| **Hash**                      | SHA_224/256/512| ELS                          | (n/a)                               | (n/a)                                  |
| **HMAC**                      | SHA_256        | ELS (single-part only)       | ELS (256-bit keys only, single-part)| ELS (256-bit keys only, single-part)   |
| **CMAC**                      | AES            | ELS                          | ELS (128/256-bit only)              | ELS (128/256-bit only)                 |
| **CBC_MAC**                   | AES            | ELS                          | ELS (128/256-bit only)              | ELS (128/256-bit only)                 |
| **CTR**                       | AES            | ELS                          | ELS                                 | ELS                                    |
| **ECB_NO_PADDING**            | AES            | ELS                          | ELS (128/256-bit only)              | ELS (128/256-bit only)                 |
| **CBC_NO_PADDING**            | AES            | ELS                          | ELS (128/256-bit only)              | ELS (128/256-bit only)                 |
| **CCM**                       | AES            | ELS                          | ELS (128/256-bit only)              | ELS (128/256-bit only)                 |
| **GCM**                       | AES            | ELS                          | ELS (128/256-bit only)              | ELS (128/256-bit only)                 |
| **ECDSA**                     | SECP_R1        | PKC                          | ELS (sign/verify hash only)         | ELS (sign/verify hash only, P-256 only)|
| **ECDH**                      | ECDH           | PKC (v1.8+)                  | not supported                       | not supported                          |
| **RSA**                       | all            | PKC                          | not applicable (RSA always external)| not applicable (RSA always external)   |
| **Key derivation (HKDF, TLS)**| all            | SW only                      | not supported                       | not supported                          |
| **Asymmetric encryption**     | all            | SW only                      | not supported                       | not supported                          |
| **Key copy (psa_copy_key)**   | -              | not supported                | not supported                       | supported                              |

> **Key constraint for internal locations (BLOB):** AES keys must be 128 or 256 bits - **192-bit is not supported**.
