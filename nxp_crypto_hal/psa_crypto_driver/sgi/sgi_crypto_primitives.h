/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SGI_CRYPTO_PRIMITIVES_H
#define SGI_CRYPTO_PRIMITIVES_H

/** \file sgi_crypto_primtives.h
 *
 * This file contains the declaration of the context structures related
 * to the SGI HW
 *
 */

#include <mcuxClHash.h> // Interface to the entire mcuxClHash component
#include <mcuxClHashModes.h>

#include <mcuxClMacModes.h>

#if defined(PSA_WANT_ALG_HMAC)
#include <mcuxClHmac.h>
#endif /* PSA_WANT_ALG_HMAC */

#include <mcuxClCipher.h>
#include <mcuxClCipherModes.h>
#include <mcuxClKey.h>

#include <mcuxClAeadModes.h>


/* Determine the maximum hash context size needed.
 * SHA3-224 has the largest context (376 bytes on platforms with SHA3 support),
 * which is bigger than SHA2-512 (224 bytes). Use SHA3-224 size when SHA3 is
 * available, otherwise fall back to SHA2-512. */
#if defined(MCUXCL_FEATURE_HASH_C_SHA3)
#define MCUX_SGI_HASH_CTX_SIZE_IN_WORDS  MCUXCLHASH_CONTEXT_SIZE_SHA3_224_IN_WORDS
#else
#define MCUX_SGI_HASH_CTX_SIZE_IN_WORDS  MCUXCLHASH_CONTEXT_SIZE_SHA2_512_IN_WORDS
#endif /* MCUXCL_FEATURE_HASH_C_SHA3 */

typedef struct {
    uint32_t ctx[MCUX_SGI_HASH_CTX_SIZE_IN_WORDS];
} mcux_sgi_hash_operation_t;


/* The MAC context must be large enough for the biggest supported MAC mode.
 * The composite MCUXCLMAC_MAX_CONTEXT_SIZE_IN_WORDS macro lives in an internal
 * mcuxClMac header that is not exposed to the PSA driver, so recreate the same
 * maximum here from the public per-mode macros: CMAC uses
 * MCUXCLMAC_CONTEXT_SIZE_IN_WORDS, HMAC (when enabled) uses the larger
 * MCUXCLHMAC_MAX_CONTEXT_SIZE_IN_WORDS. */
#if defined(PSA_WANT_ALG_HMAC)
#define SGI_MAC_CONTEXT_SIZE_IN_WORDS                                          \
    ((MCUXCLMAC_CONTEXT_SIZE_IN_WORDS > MCUXCLHMAC_MAX_CONTEXT_SIZE_IN_WORDS)   \
         ? MCUXCLMAC_CONTEXT_SIZE_IN_WORDS                                      \
         : MCUXCLHMAC_MAX_CONTEXT_SIZE_IN_WORDS)
#else
#define SGI_MAC_CONTEXT_SIZE_IN_WORDS MCUXCLMAC_CONTEXT_SIZE_IN_WORDS
#endif /* PSA_WANT_ALG_HMAC */

typedef struct {
    uint32_t ctx[SGI_MAC_CONTEXT_SIZE_IN_WORDS];

    uint32_t keyDesc[MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS];
#if defined(PSA_WANT_ALG_HMAC)
    /* HMAC uses a runtime-constructed mode descriptor. The multipart MAC
     * context stores only a pointer to this descriptor (see mcuxClMac_init),
     * so the descriptor must live for the whole multipart operation. Keep it
     * in the persistent operation object rather than on the stack. */
    uint32_t hmacModeDesc[MCUXCLHMAC_HMAC_MODE_DESCRIPTOR_SIZE_IN_WORDS];
#endif /* PSA_WANT_ALG_HMAC */
} sgi_mac_operation_t;


typedef struct {
    uint32_t ctx[MCUXCLAEAD_CONTEXT_SIZE];
    uint32_t keyDesc[MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS];

    psa_algorithm_t alg;
    psa_key_type_t key_type;
    uint8_t is_encrypt;
    uint32_t tag_length;

    uint8_t  body_started;
    uint32_t ad_remaining;
    uint32_t body_remaining;
    uint8_t  nonce_set;
    uint8_t  lengths_set;
} sgi_aead_operation_t;

typedef struct {
    uint32_t ctx[MCUXCLCIPHER_AES_CONTEXT_SIZE_IN_WORDS];
    uint32_t keyDesc[MCUXCLKEY_DESCRIPTOR_SIZE_IN_WORDS];
    psa_algorithm_t alg;
    psa_key_type_t key_type;
    psa_encrypt_or_decrypt_t cipher_direction;
} sgi_cipher_operation_t;
#endif /* SGI_CRYPTO_PRIMITIVES_H */
