/*
 *  The RSA public-key cryptosystem
 *
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */

/*
 *  The following sources were referenced in the design of this implementation
 *  of the RSA algorithm:
 *
 *  [1] A method for obtaining digital signatures and public-key cryptosystems
 *      R Rivest, A Shamir, and L Adleman
 *      http://people.csail.mit.edu/rivest/pubs.html#RSA78
 *
 *  [2] Handbook of Applied Cryptography - 1997, Chapter 8
 *      Menezes, van Oorschot and Vanstone
 *
 *  [3] Malware Guard Extension: Using SGX to Conceal Cache Attacks
 *      Michael Schwarz, Samuel Weiser, Daniel Gruss, Clémentine Maurice and
 *      Stefan Mangard
 *      https://arxiv.org/abs/1702.08719v2
 *
 */

#ifndef MCUX_PSA_MBEDTLS_ORIGIN_H
#define MCUX_PSA_MBEDTLS_ORIGIN_H
#include "mbedtls/md.h"

/* Construct a PKCS v1.5 encoding of a hashed message
 *
 * This is used both for signature generation and verification.
 *
 * Parameters:
 * - md_alg:  Identifies the hash algorithm used to generate the given hash;
 *            MBEDTLS_MD_NONE if raw data is signed.
 * - hashlen: Length of hash in case hashlen is MBEDTLS_MD_NONE.
 * - hash:    Buffer containing the hashed message or the raw data.
 * - dst_len: Length of the encoded message.
 * - dst:     Buffer to hold the encoded message.
 *
 * Assumptions:
 * - hash has size hashlen if md_alg == MBEDTLS_MD_NONE.
 * - hash has size corresponding to md_alg if md_alg != MBEDTLS_MD_NONE.
 * - dst points to a buffer of size at least dst_len.
 *
 */
int rsa_rsassa_pkcs1_v15_encode(mbedtls_md_type_t md_alg,
                                unsigned int hashlen,
                                const unsigned char *hash,
                                size_t dst_len,
                                unsigned char *dst);

/**
 * Generate and apply the MGF1 operation (from PKCS#1 v2.1) to a buffer.
 *
 * \param dst       buffer to mask
 * \param dlen      length of destination buffer
 * \param src       source of the mask generation
 * \param slen      length of the source buffer
 * \param md_alg    message digest to use
 */
int mgf_mask(unsigned char *dst,
             size_t dlen,
             unsigned char *src,
             size_t slen,
             mbedtls_md_type_t md_alg);

/**
 * Generate Hash(M') as in RFC 8017 page 43 points 5 and 6.
 *
 * \param hash      the input hash
 * \param hlen      length of the input hash
 * \param salt      the input salt
 * \param slen      length of the input salt
 * \param out       the output buffer - must be large enough for \p md_alg
 * \param md_alg    message digest to use
 */
int hash_mprime(const unsigned char *hash,
                size_t hlen,
                const unsigned char *salt,
                size_t slen,
                unsigned char *out,
                mbedtls_md_type_t md_alg);

int rsa_rsassa_pss_sign_encode(int (*f_rng)(void *, unsigned char *, size_t),
                               void *p_rng,
                               mbedtls_md_type_t md_alg,
                               size_t rsa_key_len,
                               unsigned int hashlen,
                               const unsigned char *hash,
                               int saltlen,
                               unsigned char *output,
                               size_t olen);

/**
 * \brief          This function performs a PKCS#1 v2.1 PSS verification
 *                 operation (RSASSA-PSS-VERIFY).
 *
 * \note           The \p sig buffer must be as large as the size
 *                 of \p ctx->N. For example, 128 Bytes if RSA-1024 is used.
 *
 * \note           The \c hash_id set in \p ctx (when calling
 *                 mbedtls_rsa_init() or by calling mbedtls_rsa_set_padding()
 *                 afterwards) is ignored.
 *
 * \param md_alg   The message-digest algorithm used to hash the original data.
 *                 Use #MBEDTLS_MD_NONE for signing raw data.
 * \param hashlen  The length of the message digest.
 *                 This is only used if \p md_alg is #MBEDTLS_MD_NONE.
 * \param hash     The buffer holding the message digest or raw data.
 *                 If \p md_alg is #MBEDTLS_MD_NONE, this must be a readable
 *                 buffer of length \p hashlen Bytes. If \p md_alg is not
 *                 #MBEDTLS_MD_NONE, it must be a readable buffer of length
 *                 the size of the hash corresponding to \p md_alg.
 * \param expected_salt_len The length of the salt used in padding. Use
 *                          #MBEDTLS_RSA_SALT_LEN_ANY to accept any salt length.
 * \param buf      The buffer holding the signature after rsa operation. This must be a readable
 *                 buffer of length \c rsa_key_len Bytes. For example, \c 256 Bytes
 *                 for an 2048-bit RSA modulus.
 *
 * \return         \c 0 if the verify operation was successful.
 * \return         An \c MBEDTLS_ERR_RSA_XXX error code on failure.
 */
int mbedtls_rsa_rsassa_pss_verify_check(mbedtls_md_type_t md_alg,
                                        size_t rsa_key_len,
                                        unsigned int hashlen,
                                        const unsigned char *hash,
                                        int expected_salt_len,
                                        unsigned char *buf);

#endif /* MCUX_PSA_MBEDTLS_ORIGIN_H */
