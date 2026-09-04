# PKC Component for the PSA Crypto API

## Architecture

The PKC component provides asymmetric cryptography operations using the PKC
(Public Key Cryptography) hardware accelerator. It is a **shared component**
designed to be used alongside a SGI PSA driver that provides
symmetric crypto, hashing, entropy, and key descriptor management.

Dependencies:
* **SGI common key management** - `sgi_create_key_descriptor()` is used to
  build key descriptors for PKC operations.
* **SGI entropy** - `sgi_get_entropy()` is used for random key generation.

## Supported ECC Curves

The following ECC curves are supported, each gated by a `PSA_WANT_ECC_*`
compile-time flag:

| Family                          | Key Sizes (bits)          | Condition                             |
|---------------------------------|---------------------------|---------------------------------------|
| `PSA_ECC_FAMILY_SECP_R1`       | 192, 224, 256, 384, 521   | -                                     |
| `PSA_ECC_FAMILY_BRAINPOOL_P_R1`| 256, 384, 512             | -                                     |
| `PSA_ECC_FAMILY_SECP_K1`       | 192, 256                  | Requires `MCUXCL_FEATURE_ECC_SECPK1_CURVES` |

## Supported Operations

### Asymmetric Signature

* Sign Hash (`pkc_sign_hash`):
    * `PSA_ALG_ECDSA` (randomized only; deterministic ECDSA is **not**
      supported and returns `PSA_ERROR_NOT_SUPPORTED`)
    * Requires `PSA_KEY_TYPE_ECC_KEY_PAIR`

* Verify Hash (`pkc_verify_hash`):
    * `PSA_ALG_ECDSA`
    * Accepts both `PSA_KEY_TYPE_ECC_KEY_PAIR` and
      `PSA_KEY_TYPE_ECC_PUBLIC_KEY`
    * For key pairs, the public key is derived internally via the lock-free
      `pkc_internal_export_ecp_public_key()`.

### Key Generation

* `pkc_generate_key` - generates random ECC key pairs for supported curves.

### Export Public Key

* `pkc_transparent_export_public_key` - exports the public key in SEC1
  uncompressed point format (`0x04 || X || Y`):
    * For a `PSA_KEY_TYPE_ECC_PUBLIC_KEY` handle the stored point is copied
      out directly (the leading `0x04` uncompressed tag is required).
    * For a `PSA_KEY_TYPE_ECC_KEY_PAIR` handle the public point is derived
      on-chip as `Q = d * G` using the shared secure scalar 
	  multiplication helper `sgi_ecc_derive_public_key()`, then the
      `0x04` tag is prepended.

### Key Agreement

* `pkc_key_agreement` - raw ECDH key agreement
  (`PSA_ALG_IS_RAW_KEY_AGREEMENT`). Returns the raw shared secret; callers
  should chain with a key derivation function for use as key material.

## Additional Features

## Cryptographic Summary

| Operation          | Algorithm                      | Key Types               | Curves                                                          |
|--------------------|--------------------------------|-------------------------|-----------------------------------------------------------------|
| Sign Hash          | `PSA_ALG_ECDSA` (randomized)   | ECC Key Pair            | SECP_R1, Brainpool_P_R1, SECP_K1                               |
| Verify Hash        | `PSA_ALG_ECDSA`                | ECC Key Pair, Public Key| SECP_R1, Brainpool_P_R1, SECP_K1                               |
| Key Generation     | -                              | ECC Key Pair            | SECP_R1, Brainpool_P_R1, SECP_K1                               |
| Export Public Key  | -                              | ECC Key Pair, Public Key| SECP_R1, Brainpool_P_R1, SECP_K1                               |
| Key Agreement      | `PSA_ALG_ECDH`                 | ECC Key Pair            | SECP_R1, Brainpool_P_R1, SECP_K1                               |
