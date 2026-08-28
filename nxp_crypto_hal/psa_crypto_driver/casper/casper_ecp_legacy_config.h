/*
 * Copyright 2026 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * This header re-enables legacy mbedTLS ECP/bignum symbols that are stubbed
 * out by TF-PSA-Crypto unless opted back in.
 */

#ifndef CASPER_ECP_LEGACY_CONFIG_H
#define CASPER_ECP_LEGACY_CONFIG_H

/*
 * Only activate legacy ECP/bignum support when the application requests at
 * least one ECC key operation.
 *
 * NOTE: At the point this header is processed (injected via -include, before
 * any source file's own #includes), only the CONFIG_PSA_WANT_* prefixed macros
 * are available — they come from Zephyr's autoconf.h which is passed on the
 * command line.  The bare PSA_WANT_* macros are defined later inside
 * config-psa.h (included by the TF-PSA-Crypto config header chain), so they
 * are NOT yet visible here.  Therefore the guard must use CONFIG_PSA_WANT_*.
 */
#if defined(CONFIG_PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_GENERATE) || \
    defined(CONFIG_PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_IMPORT)   || \
    defined(CONFIG_PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_EXPORT)   || \
    defined(CONFIG_PSA_WANT_KEY_TYPE_ECC_PUBLIC_KEY)        || \
    defined(CONFIG_PSA_WANT_ALG_ECDSA)                      || \
    defined(CONFIG_PSA_WANT_ALG_ECDSA_ANY)                  || \
    defined(CONFIG_PSA_WANT_ALG_ECDH)

/* Legacy mbedTLS ECP/bignum modules required by the casper key-gen port. */
#ifndef MBEDTLS_BIGNUM_C
#define MBEDTLS_BIGNUM_C
#endif

#ifndef MBEDTLS_ECP_C
#define MBEDTLS_ECP_C
#endif

#ifndef TF_PSA_CRYPTO_CONFIG_CHECK_BYPASS
#define TF_PSA_CRYPTO_CONFIG_CHECK_BYPASS
#endif

/*
 * Always enable all three SECP-R1 curves that CASPER accelerates.
 *
 * IMPORTANT: psa_crypto_driver_wrappers.h calls casper_mbedtls_psa_ecp_generate_key().
 * If the user requests ECC but does not explicitly list a SECP-R1 curve, 
 * the function would compile to nothing while the wrapper still tries to call it 
 * Enabling all three CASPER curves unconditionally whenever ECC
 * support is active ensures the function is always compiled in.
 */
#ifndef MBEDTLS_ECP_DP_SECP256R1_ENABLED
#define MBEDTLS_ECP_DP_SECP256R1_ENABLED
#endif

#ifndef MBEDTLS_ECP_DP_SECP384R1_ENABLED
#define MBEDTLS_ECP_DP_SECP384R1_ENABLED
#endif

#ifndef MBEDTLS_ECP_DP_SECP521R1_ENABLED
#define MBEDTLS_ECP_DP_SECP521R1_ENABLED
#endif

/* Also ensure the matching PSA_WANT_ECC_SECP_R1_* macros are set so that
 * psa_util_internal.c's mbedtls_ecc_group_from_psa() returns the correct
 * group IDs for CASPER-accelerated curves. */
#ifndef PSA_WANT_ECC_SECP_R1_256
#define PSA_WANT_ECC_SECP_R1_256 1
#endif

#ifndef PSA_WANT_ECC_SECP_R1_384
#define PSA_WANT_ECC_SECP_R1_384 1
#endif

#ifndef PSA_WANT_ECC_SECP_R1_521
#define PSA_WANT_ECC_SECP_R1_521 1
#endif

/*
 * mbedtls_ecc_group_from_psa() in psa_util_internal.c is gated on
 * PSA_WANT_KEY_TYPE_ECC_PUBLIC_KEY.  Ensure it is defined whenever any ECC
 * key-pair or ECDSA algorithm is requested (key-pair types imply public-key
 * support; ECDSA requires a public key for verification).
 */
#ifndef PSA_WANT_KEY_TYPE_ECC_PUBLIC_KEY
#define PSA_WANT_KEY_TYPE_ECC_PUBLIC_KEY 1
#endif

/*
 * Deterministic ECDSA signing (casper_mbedtls_ecdsa_sign_det_internal) uses
 * mbedtls_hmac_drbg_* and mbedtls_md_info_from_type(), which require
 * MBEDTLS_MD_C and MBEDTLS_HMAC_DRBG_C to be compiled in.  Enable them
 * whenever ECDSA signing is requested.
 */
#if defined(CONFIG_PSA_WANT_ALG_ECDSA) || defined(CONFIG_PSA_WANT_ALG_ECDSA_ANY)

#ifndef MBEDTLS_MD_C
#define MBEDTLS_MD_C
#endif

#ifndef MBEDTLS_HMAC_DRBG_C
#define MBEDTLS_HMAC_DRBG_C
#endif

#endif /* CONFIG_PSA_WANT_ALG_ECDSA || CONFIG_PSA_WANT_ALG_ECDSA_ANY */

#endif /* any ECC key type or ECDSA algorithm requested */

#endif /* CASPER_ECP_LEGACY_CONFIG_H */
