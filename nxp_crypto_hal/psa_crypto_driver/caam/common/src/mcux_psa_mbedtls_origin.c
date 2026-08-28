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

#include "mcux_psa_mbedtls_origin.h"
#include "mcux_psa_util_wrapcheck_static_inline.h"

#include "psa_crypto_rsa.h"

#include "mbedtls/error.h"
#include "mbedtls/oid.h"

extern int mbedtls_oid_get_oid_by_md(mbedtls_md_type_t md_alg, const char **oid, size_t *olen);

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
                                unsigned char *dst)
{
    size_t oid_size  = 0;
    size_t nb_pad    = dst_len;
    unsigned char *p = dst;
    const char *oid  = NULL;

    /* Are we signing hashed or raw data? */
    if (md_alg != MBEDTLS_MD_NONE) {
        unsigned char md_size = mbedtls_md_get_size_from_type(md_alg);
        if (md_size == 0) {
            return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
        }

        if (mbedtls_oid_get_oid_by_md(md_alg, &oid, &oid_size) != 0) {
            return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
        }

        if (hashlen != md_size) {
            return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
        }

        /* Double-check that 8 + hashlen + oid_size can be used as a
         * 1-byte ASN.1 length encoding and that there's no overflow. */
        if (8 + hashlen + oid_size  >= 0x80         ||
            10 + hashlen            <  hashlen      ||
            10 + hashlen + oid_size <  10 + hashlen) {
            return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
        }

        /*
         * Static bounds check:
         * - Need 10 bytes for five tag-length pairs.
         *   (Insist on 1-byte length encodings to protect against variants of
         *    Bleichenbacher's forgery attack against lax PKCS#1v1.5 verification)
         * - Need hashlen bytes for hash
         * - Need oid_size bytes for hash alg OID.
         */
        if (nb_pad < 10 + hashlen + oid_size) {
            return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
        }
        nb_pad -= 10 + hashlen + oid_size;
    } else {
        if (nb_pad < hashlen) {
            return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
        }

        nb_pad -= hashlen;
    }

    /* Need space for signature header and padding delimiter (3 bytes),
     * and 8 bytes for the minimal padding */
    if (nb_pad < 3 + 8) {
        return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
    }
    nb_pad -= 3;

    /* Now nb_pad is the amount of memory to be filled
     * with padding, and at least 8 bytes long. */

    /* Write signature header and padding */
    *p++ = 0;
    *p++ = MBEDTLS_RSA_SIGN;
    memset(p, 0xFF, nb_pad);
    p += nb_pad;
    *p++ = 0;

    /* Are we signing raw data? */
    if (md_alg == MBEDTLS_MD_NONE) {
        memcpy(p, hash, hashlen);
        return 0;
    }

    /* Signing hashed data, add corresponding ASN.1 structure
     *
     * DigestInfo ::= SEQUENCE {
     *   digestAlgorithm DigestAlgorithmIdentifier,
     *   digest Digest }
     * DigestAlgorithmIdentifier ::= AlgorithmIdentifier
     * Digest ::= OCTET STRING
     *
     * Schematic:
     * TAG-SEQ + LEN [ TAG-SEQ + LEN [ TAG-OID  + LEN [ OID  ]
     *                                 TAG-NULL + LEN [ NULL ] ]
     *                 TAG-OCTET + LEN [ HASH ] ]
     */
    *p++ = MBEDTLS_ASN1_SEQUENCE | MBEDTLS_ASN1_CONSTRUCTED;
    *p++ = (unsigned char) (0x08 + oid_size + hashlen);
    *p++ = MBEDTLS_ASN1_SEQUENCE | MBEDTLS_ASN1_CONSTRUCTED;
    *p++ = (unsigned char) (0x04 + oid_size);
    *p++ = MBEDTLS_ASN1_OID;
    *p++ = (unsigned char) oid_size;
    memcpy(p, oid, oid_size);
    p += oid_size;
    *p++ = MBEDTLS_ASN1_NULL;
    *p++ = 0x00;
    *p++ = MBEDTLS_ASN1_OCTET_STRING;
    *p++ = (unsigned char) hashlen;
    memcpy(p, hash, hashlen);
    p += hashlen;

    /* Just a sanity-check, should be automatic
     * after the initial bounds check. */
    if (p != dst + dst_len) {
        mbedtls_platform_zeroize(dst, dst_len);
        return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
    }

    return 0;
}

int mgf_mask(unsigned char *dst,
             size_t dlen,
             unsigned char *src,
             size_t slen,
             mbedtls_md_type_t md_alg)
{
    unsigned char counter[4];
    unsigned char *p;
    unsigned int hlen;
    size_t i, use_len;
    unsigned char mask[MBEDTLS_MD_MAX_SIZE];
    int ret = 0;
    const mbedtls_md_info_t *md_info;
    mbedtls_md_context_t md_ctx;

    mbedtls_md_init(&md_ctx);
    md_info = mbedtls_md_info_from_type(md_alg);
    if (md_info == NULL) {
        return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
    }

    mbedtls_md_init(&md_ctx);
    if ((ret = mbedtls_md_setup(&md_ctx, md_info, 0)) != 0) {
        goto exit;
    }

    hlen = mbedtls_md_get_size(md_info);

    memset(mask, 0, sizeof(mask));
    memset(counter, 0, 4);

    /* Generate and apply dbMask */
    p = dst;

    while (dlen > 0) {
        use_len = hlen;
        if (dlen < hlen) {
            use_len = dlen;
        }

        if ((ret = mbedtls_md_starts(&md_ctx)) != 0) {
            goto exit;
        }
        if ((ret = mbedtls_md_update(&md_ctx, src, slen)) != 0) {
            goto exit;
        }
        if ((ret = mbedtls_md_update(&md_ctx, counter, 4)) != 0) {
            goto exit;
        }
        if ((ret = mbedtls_md_finish(&md_ctx, mask)) != 0) {
            goto exit;
        }

        for (i = 0; i < use_len; ++i) {
            *p++ ^= mask[i];
        }

        counter[3]++;

        dlen -= use_len;
    }

exit:
    mbedtls_platform_zeroize(mask, sizeof(mask));
    mbedtls_md_free(&md_ctx);

    return ret;
}

int hash_mprime(const unsigned char *hash,
                size_t hlen,
                const unsigned char *salt,
                size_t slen,
                unsigned char *out,
                mbedtls_md_type_t md_alg)
{
    const unsigned char zeros[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

    mbedtls_md_context_t md_ctx;
    int ret = MBEDTLS_ERR_ERROR_CORRUPTION_DETECTED;

    const mbedtls_md_info_t *md_info = mbedtls_md_info_from_type(md_alg);
    if (md_info == NULL) {
        return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
    }

    mbedtls_md_init(&md_ctx);
    if ((ret = mbedtls_md_setup(&md_ctx, md_info, 0)) != 0) {
        goto exit;
    }
    if ((ret = mbedtls_md_starts(&md_ctx)) != 0) {
        goto exit;
    }
    if ((ret = mbedtls_md_update(&md_ctx, zeros, sizeof(zeros))) != 0) {
        goto exit;
    }
    if ((ret = mbedtls_md_update(&md_ctx, hash, hlen)) != 0) {
        goto exit;
    }
    if ((ret = mbedtls_md_update(&md_ctx, salt, slen)) != 0) {
        goto exit;
    }
    if ((ret = mbedtls_md_finish(&md_ctx, out)) != 0) {
        goto exit;
    }

exit:
    mbedtls_md_free(&md_ctx);

    return ret;
}

int rsa_rsassa_pss_sign_encode(int (*f_rng)(void *, unsigned char *, size_t),
                               void *p_rng,
                               mbedtls_md_type_t md_alg,
                               size_t rsa_key_len,
                               unsigned int hashlen,
                               const unsigned char *hash,
                               int saltlen,
                               unsigned char *output,
                               size_t olen)
{
    unsigned char *p    = output;
    unsigned char *salt = NULL;
    size_t slen, min_slen, hlen, offset = 0;
    int ret = MBEDTLS_ERR_ERROR_CORRUPTION_DETECTED;
    size_t msb;

    if (md_alg == MBEDTLS_MD_NONE || hashlen == 0 || hash == NULL) {
        return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
    }

    if (f_rng == NULL) {
        return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
    }

    /* Gather length of hash to sign */
    hlen = mbedtls_md_get_size_from_type(md_alg);

    if (hashlen != hlen) {
        return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
    }

    if (saltlen == MBEDTLS_RSA_SALT_LEN_ANY) {
        /* Calculate the largest possible salt length, up to the hash size.
         * Normally this is the hash length, which is the maximum salt length
         * according to FIPS 185-4 §5.5 (e) and common practice. If there is not
         * enough room, use the maximum salt length that fits. The constraint is
         * that the hash length plus the salt length plus 2 bytes must be at most
         * the key length. This complies with FIPS 186-4 §5.5 (e) and RFC 8017
         * (PKCS#1 v2.2) §9.1.1 step 3. */
        min_slen = hlen - 2;
        /* Guard hlen+min_slen+2 addition against wrap */
        if (mcux_psa_add_size_t_wrapcheck(hlen, min_slen + 2U)) {
            return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
        } else if (olen < hlen + min_slen + 2U) {
            return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
        } else if (olen >= hlen + hlen + 2U) {
            slen = hlen;
        } else {
            /* Guard olen-hlen-2U subtraction against wrap */
            if (mcux_psa_sub_size_t_wrapcheck(olen, hlen + 2U)) {
                return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
            }
            slen = olen - hlen - 2U;
        }
    } else if ((saltlen < 0) || (saltlen + hlen + 2 > olen)) {
        return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
    } else {
        slen = (size_t) saltlen;
    }

    memset(output, 0, olen);

    /* Note: EMSA-PSS encoding is over the length of N - 1 bits */
    /* Guard rsa_key_len*8 multiplication against wrap */
    if (mcux_psa_mul_size_t_wrapcheck(rsa_key_len, 8U)) {
        return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
    }
    msb = rsa_key_len * 8U - 1U;
    p += olen - hlen - slen - 2;
    *p++ = 0x01;

    /* Generate salt of length slen in place in the encoded message */
    salt = p;
    if ((ret = f_rng(p_rng, salt, slen)) != 0) {
        return MBEDTLS_ERROR_ADD(MBEDTLS_ERR_RSA_RNG_FAILED, ret);
    }

    p += slen;

    /* Generate H = Hash( M' ) */
    ret = hash_mprime(hash, hashlen, salt, slen, p, md_alg);
    if (ret != 0) {
        return ret;
    }

    /* Compensate for boundary condition when applying mask */
    if (msb % 8 == 0) {
        offset = 1;
    }

    /* maskedDB: Apply dbMask to DB */
    ret = mgf_mask(output + offset, olen - hlen - 1 - offset, p, hlen, md_alg);
    if (ret != 0) {
        return ret;
    }

    output[0] &= 0xFF >> (olen * 8 - msb);

    p += hlen;
    *p++ = 0xBC;

    return 0;
}

/*
 * Implementation of the PKCS#1 v2.1 RSASSA-PSS-VERIFY function
 */
int mbedtls_rsa_rsassa_pss_verify_check(mbedtls_md_type_t md_alg,
                                        size_t rsa_key_len,
                                        unsigned int hashlen,
                                        const unsigned char *hash,
                                        int expected_salt_len,
                                        unsigned char *buf)
{
    int ret = MBEDTLS_ERR_ERROR_CORRUPTION_DETECTED;
    size_t siglen;
    unsigned char *p;
    unsigned char *hash_start;
    unsigned char result[MBEDTLS_MD_MAX_SIZE];
    size_t observed_salt_len, msb;

    if (md_alg == MBEDTLS_MD_NONE || hashlen == 0 || hash == NULL) {
        return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
    }

    siglen = rsa_key_len;

    if (siglen < 16) {
        return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
    }

    p = buf;

    if (buf[siglen - 1] != 0xBC) {
        return MBEDTLS_ERR_RSA_INVALID_PADDING;
    }

    /* Gather length of hash to sign */
    size_t exp_hashlen = mbedtls_md_get_size_from_type(md_alg);

    if (hashlen != exp_hashlen) {
        return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
    }

    /*
     * Note: EMSA-PSS verification is over the length of N - 1 bits
     */
    msb = rsa_key_len * 8 - 1;

    if (buf[0] >> (8 - siglen * 8 + msb)) {
        return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
    }

    /* Compensate for boundary condition when applying mask */
    if (msb % 8 == 0) {
        p++;
        siglen -= 1;
    }

    if (siglen < hashlen + 2) {
        return MBEDTLS_ERR_RSA_BAD_INPUT_DATA;
    }
    hash_start = p + siglen - hashlen - 1;

    ret = mgf_mask(p, siglen - hashlen - 1, hash_start, hashlen, md_alg);
    if (ret != 0) {
        return ret;
    }

    buf[0] &= 0xFF >> (siglen * 8 - msb);

    while (p < hash_start - 1 && *p == 0) {
        p++;
    }

    if (*p++ != 0x01) {
        return MBEDTLS_ERR_RSA_INVALID_PADDING;
    }

    observed_salt_len = (size_t) (hash_start - p);

    if (expected_salt_len != MBEDTLS_RSA_SALT_LEN_ANY &&
        observed_salt_len != (size_t) expected_salt_len) {
        return MBEDTLS_ERR_RSA_INVALID_PADDING;
    }

    /*
     * Generate H = Hash( M' )
     */
    ret = hash_mprime(hash, hashlen, p, observed_salt_len, result, md_alg);
    if (ret != 0) {
        return ret;
    }

    if (memcmp(hash_start, result, hashlen) != 0) {
        return MBEDTLS_ERR_RSA_VERIFY_FAILED;
    }

    return 0;
}
