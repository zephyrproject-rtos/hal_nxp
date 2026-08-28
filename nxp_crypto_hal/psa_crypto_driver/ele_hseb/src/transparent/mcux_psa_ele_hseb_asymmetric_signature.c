/*
 * Copyright 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/*
 *  Generic ASN.1 parsing
 *
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */

/** \file mcux_psa_ele_hseb_asymmetric_signature.c
 *
 * This file contains the implementation of the entry points associated to the
 * asymmetric signature capability as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_ele_hseb_init.h"
#include "mcux_psa_ele_hseb_asymmetric_signature.h"
#include "mcux_psa_ele_hseb_translate.h"
#include "mcux_psa_ele_hseb_key_management.h"
#include "mcux_psa_ele_hseb_common_asymmetric_signature.h"

#include "hse_host_ecc.h"
#include "hse_host_sign.h"

/******************************************************************************

   START : COPIED AND MODIFIED SOME OF THE ASN1 PARSING FUNCTIONS FROM MBEDTLS

        Copied to prevent having to depend on the entire mbedtls stack.
        Modified to prevent symbol conflicts.

 ******************************************************************************/

/** Out of data when parsing an ASN1 data structure. */
#define HSEB_ERR_ASN1_OUT_OF_DATA                      -0x0060
/** ASN1 tag was of an unexpected value. */
#define HSEB_ERR_ASN1_UNEXPECTED_TAG                   -0x0062
/** Error when trying to determine the length or invalid length. */
#define HSEB_ERR_ASN1_INVALID_LENGTH                   -0x0064

/** Integer tag. */
#define HSEB_ASN1_INTEGER                 0x02
/** Sequence tag. */
#define HSEB_ASN1_SEQUENCE                0x10
/** Constructed bit mask. */
#define HSEB_ASN1_CONSTRUCTED             0x20

static int hseb_asn1_get_len(unsigned char **p,
                             const unsigned char *end,
                             size_t *len)
{
    if ((end - *p) < 1) {
        return HSEB_ERR_ASN1_OUT_OF_DATA;
    }

    if ((**p & 0x80) == 0) {
        *len = *(*p)++;
    } else {
        int n = (**p) & 0x7F;
        if (n == 0 || n > 4) {
            return HSEB_ERR_ASN1_INVALID_LENGTH;
        }
        if ((end - *p) <= n) {
            return HSEB_ERR_ASN1_OUT_OF_DATA;
        }
        *len = 0;
        (*p)++;
        while (n--) {
            *len = (*len << 8) | **p;
            (*p)++;
        }
    }

    if (*len > (size_t) (end - *p)) {
        return HSEB_ERR_ASN1_OUT_OF_DATA;
    }

    return 0;
}

static int hseb_asn1_get_tag(unsigned char **p,
                             const unsigned char *end,
                             size_t *len, int tag)
{
    if ((end - *p) < 1) {
        return HSEB_ERR_ASN1_OUT_OF_DATA;
    }

    if (**p != tag) {
        return HSEB_ERR_ASN1_UNEXPECTED_TAG;
    }

    (*p)++;

    return hseb_asn1_get_len(p, end, len);
}

/******************************************************************************

   END : COPIED AND MODIFIED SOME OF THE ASN1 PARSING FUNCTIONS FROM MBEDTLS

 ******************************************************************************/

static psa_status_t setkey_rsa(const psa_key_attributes_t *attributes,
                               hseKeyHandle_t *key_handle,
                               const uint8_t *key_buffer,
                               size_t key_buffer_size)
{
    psa_status_t status           = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status  = HSE_SRV_RSP_GENERAL_ERROR;
    const size_t key_bits         = psa_get_key_bits(attributes);
    const size_t key_bytes        = PSA_BITS_TO_BYTES(key_bits);
    const psa_key_type_t key_type = psa_get_key_type(attributes);
    uint8_t *p                    = (uint8_t *) key_buffer;
    const uint8_t *end            = p + key_buffer_size;
    size_t len                    = 0u;
    size_t e_length               = 0u;
    uint8_t *n                    = NULL;
    uint8_t *e                    = NULL;
    uint8_t *d                    = NULL;

    /* Parse the initial SEQUENCE tag */
    if (0 != hseb_asn1_get_tag(&p, end, &len,
                               HSEB_ASN1_CONSTRUCTED | HSEB_ASN1_SEQUENCE)) {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    if (true == PSA_KEY_TYPE_IS_KEY_PAIR(key_type)) {
        /* For reference, we need the following values from the keypair data
         * RSAPrivateKey ::= SEQUENCE {
         *      version             INTEGER,  -- must be 0
         * ==>> modulus             INTEGER,  -- n
         * ==>> publicExponent      INTEGER,  -- e
         * ==>> privateExponent     INTEGER,  -- d
         *      prime1              INTEGER,  -- p
         *      prime2              INTEGER,  -- q
         *      exponent1           INTEGER,  -- d mod (p-1)
         *      exponent2           INTEGER,  -- d mod (q-1)
         *      coefficient         INTEGER,  -- (inverse of q) mod p
         * }
         */

        /* Version not needed, but we check its presence */
        if (0 != hseb_asn1_get_tag(&p, end, &len, HSEB_ASN1_INTEGER)) {
            status = PSA_ERROR_GENERIC_ERROR;
            goto exit;
        }

        /* If first Byte of encoded value is set to 0x00 and the next Byte
         * is (Byte & 0x80 != 0), it's to prevent interpreting the encoded value
         * as a negative integer (as per two's complement representation).
         * In that case we skip that first 0x00 Byte and continue as usual.
         * Else it's a valid 0x00 Byte that's part of the key, so we don't skip.
         */

        /* Skip version field and continue with modulus n */
        p += len;
        if (0 != hseb_asn1_get_tag(&p, end, &len, HSEB_ASN1_INTEGER)) {
            status = PSA_ERROR_GENERIC_ERROR;
            goto exit;
        }
        if (*p == 0x00 && (*(p+1) & 0x80) != 0) {
            p++;
            len--;
        }
        if (len != key_bytes) {
            status = PSA_ERROR_GENERIC_ERROR;
            goto exit;
        }
        n = p;

        /* Skip modulus n and continue with exponent e */
        p += len;
        if (0 != hseb_asn1_get_tag(&p, end, &len, HSEB_ASN1_INTEGER)) {
            status = PSA_ERROR_GENERIC_ERROR;
            goto exit;
        }
        e_length = len;
        if (*p == 0x00 && (*(p+1) & 0x80) != 0) {
            p++;
            len--;
        }
        e = p;

        /* Skip exponent e and continue with exponent d */
        p += len;
        if (0 != hseb_asn1_get_tag(&p, end, &len, HSEB_ASN1_INTEGER)) {
            status = PSA_ERROR_GENERIC_ERROR;
            goto exit;
        }
        if (*p == 0x00 && (*(p+1) & 0x80) != 0) {
            p++;
            len--;
        }
        if (len != key_bytes) {
            status = PSA_ERROR_GENERIC_ERROR;
            goto exit;
        }
        d = p;

        if (e_length <= UINT16_MAX) {
            /* RSA key pairs cannot be placed into RAM key catalogs, so we use
             * the NVM key catalog for this kind of key
             */
            hseb_status = LoadRsaPair(key_handle, true, key_bits, n,
                                      (uint16_t)(e_length & 0xFFFFU), e, d);
        } else {
            hseb_status = HSE_SRV_RSP_INVALID_PARAM;
        }
    } else { /* Public Key */
             /* We need both parts of the public key.
              * RSAPublicKey ::= SEQUENCE {
              *     modulus            INTEGER,    -- n
              *     publicExponent     INTEGER  }  -- e
              */

        /* Get the modulus n */
        if (0 != hseb_asn1_get_tag(&p, end, &len, HSEB_ASN1_INTEGER)) {
            status = PSA_ERROR_GENERIC_ERROR;
            goto exit;
        }
        if (*p == 0x00 && (*(p+1) & 0x80) != 0) {
            p++;
            len--;
        }
        if (len != key_bytes) {
            status = PSA_ERROR_GENERIC_ERROR;
            goto exit;
        }
        n = p;

        /* Skip modulus n and continue with exponent e */
        p += len;
        if (0 != hseb_asn1_get_tag(&p, end, &len, HSEB_ASN1_INTEGER)) {
            status = PSA_ERROR_GENERIC_ERROR;
            goto exit;
        }
        e_length = len;
        if (*p == 0x00 && (*(p+1) & 0x80) != 0) {
            p++;
            len--;
        }
        e = p;

        if (e_length <= UINT16_MAX) {
            hseb_status = LoadRsaPublicKey(key_handle, false, key_bits, n,
                                           (uint16_t)(e_length & 0xFFFFU), e);
        } else {
            hseb_status = HSE_SRV_RSP_INVALID_PARAM;
        }
    }
    status = ele_hseb_to_psa_status(hseb_status);

exit:
    return status;
}

static psa_status_t setkey_ecc(const psa_key_attributes_t *attributes,
                               hseKeyHandle_t *key_handle,
                               const uint8_t *key_buffer,
                               size_t key_buffer_size)
{
    psa_status_t status          = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status = HSE_SRV_RSP_GENERAL_ERROR;
    psa_key_type_t key_type      = psa_get_key_type(attributes);
    size_t key_bit_length        = psa_get_key_bits(attributes);
    hseEccCurveId_t curve_id     = HSE_EC_CURVE_NONE;

    status = psa_to_hseb_curve(key_type, PSA_KEY_TYPE_ECC_GET_FAMILY(key_type),
                               key_bit_length, &curve_id);
    if (PSA_SUCCESS != status) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (true == PSA_KEY_TYPE_IS_KEY_PAIR(key_type)) {
        /* PSA represents key pairs only by the private key. We can import
         * the private key and HSE will compute the public part
         */
        hseb_status = LoadEccPrivateKey(key_handle, false, curve_id,
                                        key_bit_length, key_buffer);
    } else { /* Public key */
        hseb_status = LoadEccUncompressedPublicKey(key_handle, false, curve_id,
                                                   key_bit_length, key_buffer);
    }

    status = ele_hseb_to_psa_status(hseb_status);
    return status;
}

psa_status_t ele_hseb_transparent_sign_message(const psa_key_attributes_t *attributes,
                                               const uint8_t *key_buffer,
                                               size_t key_buffer_size,
                                               psa_algorithm_t alg,
                                               const uint8_t *input,
                                               size_t input_length,
                                               uint8_t *signature,
                                               size_t signature_size,
                                               size_t *signature_length)
{
    psa_status_t status       = PSA_ERROR_CORRUPTION_DETECTED;
    size_t output_size        = 0u;
    psa_key_type_t key_type   = psa_get_key_type(attributes);
    size_t key_bits           = psa_get_key_bits(attributes);
    hseKeyHandle_t key_handle = { 0 };

    /* Check if correct alg. Per PSA spec, the PKCS1V15_SIGN_RAW variant may
     * only be used with psa_sign_hash() and psa_verify_hash() functions.
     */
    if (false == PSA_ALG_IS_SIGN_MESSAGE(alg) ||
        PSA_ALG_RSA_PKCS1V15_SIGN_RAW == alg) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (NULL == key_buffer || 0u == key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == input || 0u == input_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == signature || NULL == signature_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    output_size = PSA_SIGN_OUTPUT_SIZE(key_type, key_bits, alg);
    if (output_size > signature_size) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (true == PSA_KEY_TYPE_IS_ECC(key_type)) {
        if (true == PSA_ALG_IS_ECDSA(alg) &&
            false == PSA_ALG_IS_DETERMINISTIC_ECDSA(alg)) {
            status = setkey_ecc(attributes, &key_handle, key_buffer,
                                key_buffer_size);
            if (PSA_SUCCESS == status) {
                status = ele_hseb_common_ecdsa_sign(key_handle, alg,
                                                    input, input_length,
                                                    signature, signature_size,
                                                    signature_length, false);
            }
        } else if (true == PSA_ALG_IS_HASH_EDDSA(alg) ||
                   PSA_ALG_PURE_EDDSA == alg) {
            /* EdDSA / PureEdDSA to be supported once key import
             * for HSEB is supported */
            status = PSA_ERROR_NOT_SUPPORTED;
        } else {
            status = PSA_ERROR_NOT_SUPPORTED;
        }
    } else if (true == PSA_KEY_TYPE_IS_RSA(key_type)) {
        if (true == PSA_ALG_IS_RSA_PKCS1V15_SIGN(alg) ||
            true == PSA_ALG_IS_RSA_PSS(alg)) {
            status = setkey_rsa(attributes, &key_handle, key_buffer,
                                key_buffer_size);
            if (PSA_SUCCESS == status) {
                status = ele_hseb_common_rsa_sign(key_handle, attributes, alg,
                                                  input, input_length,
                                                  signature, signature_size,
                                                  signature_length, false);
            }
        } else {
            status = PSA_ERROR_NOT_SUPPORTED;
        }
    } else {
        status = PSA_ERROR_NOT_SUPPORTED;
    }

    if (PSA_SUCCESS != status) {
        *signature_length = 0u;
    }

    (void) ele_hseb_delete_key(&key_handle, HSE_ERASE_NOT_USED);

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_hseb_transparent_verify_message(const psa_key_attributes_t *attributes,
                                                 const uint8_t *key_buffer,
                                                 size_t key_buffer_size,
                                                 psa_algorithm_t alg,
                                                 const uint8_t *input,
                                                 size_t input_length,
                                                 const uint8_t *signature,
                                                 size_t signature_length)
{
    psa_status_t status       = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_type_t key_type   = psa_get_key_type(attributes);
    hseKeyHandle_t key_handle = { 0 };

    /* Check if correct alg. Per PSA spec, the PKCS1V15_SIGN_RAW variant may
     * only be used with psa_sign_hash() and psa_verify_hash() functions.
     */
    if (false == PSA_ALG_IS_SIGN_MESSAGE(alg) ||
        PSA_ALG_RSA_PKCS1V15_SIGN_RAW == alg) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (NULL == key_buffer || 0u == key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == input || 0u == input_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == signature || 0u == signature_length) {
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (true == PSA_KEY_TYPE_IS_ECC(key_type)) {
        if (true == PSA_ALG_IS_ECDSA(alg) &&
            false == PSA_ALG_IS_DETERMINISTIC_ECDSA(alg)) {
            status = setkey_ecc(attributes, &key_handle, key_buffer,
                                key_buffer_size);
            if (PSA_SUCCESS == status) {
                status = ele_hseb_common_ecdsa_verify(key_handle, attributes,
                                                      alg, input, input_length,
                                                      signature, signature_length,
                                                      false);
            }
        } else if (true == PSA_ALG_IS_HASH_EDDSA(alg) ||
                   PSA_ALG_PURE_EDDSA == alg) {
            /* EdDSA / PureEdDSA to be supported once key import
             * for HSEB is supported */
            status = PSA_ERROR_NOT_SUPPORTED;
        } else {
            status = PSA_ERROR_NOT_SUPPORTED;
        }
    } else if (true == PSA_KEY_TYPE_IS_RSA(key_type)) {
        if (true == PSA_ALG_IS_RSA_PKCS1V15_SIGN(alg) ||
            true == PSA_ALG_IS_RSA_PSS(alg)) {
            status = setkey_rsa(attributes, &key_handle, key_buffer,
                                key_buffer_size);
            if (PSA_SUCCESS == status) {
                status = ele_hseb_common_rsa_verify(key_handle, attributes, alg,
                                                    input, input_length,
                                                    signature, signature_length,
                                                    false);
            }
        } else {
            status = PSA_ERROR_NOT_SUPPORTED;
        }
    } else {
        status = PSA_ERROR_NOT_SUPPORTED;
    }

    (void) ele_hseb_delete_key(&key_handle, HSE_ERASE_NOT_USED);

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_hseb_transparent_sign_hash(const psa_key_attributes_t *attributes,
                                            const uint8_t *key_buffer,
                                            size_t key_buffer_size,
                                            psa_algorithm_t alg,
                                            const uint8_t *hash,
                                            size_t hash_length,
                                            uint8_t *signature,
                                            size_t signature_size,
                                            size_t *signature_length)
{
    psa_status_t status       = PSA_ERROR_CORRUPTION_DETECTED;
    size_t output_size        = 0u;
    psa_key_type_t key_type   = psa_get_key_type(attributes);
    size_t key_bits           = psa_get_key_bits(attributes);
    hseKeyHandle_t key_handle = { 0 };

    /* Check if correct alg. Per PSA spec, the PURE_EDDSA variant may
     * only be used with psa_sign_message() and psa_verify_message() functions.
     */
    if (false == PSA_ALG_IS_SIGN_HASH(alg) ||
        PSA_ALG_PURE_EDDSA == alg) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (NULL == key_buffer || 0u == key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == hash || 0u == hash_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == signature || NULL == signature_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    output_size = PSA_SIGN_OUTPUT_SIZE(key_type, key_bits, alg);
    if (output_size > signature_size) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (true == PSA_KEY_TYPE_IS_ECC(key_type)) {
        if (true == PSA_ALG_IS_ECDSA(alg) &&
            false == PSA_ALG_IS_DETERMINISTIC_ECDSA(alg)) {
            status = setkey_ecc(attributes, &key_handle, key_buffer,
                                key_buffer_size);
            if (PSA_SUCCESS == status) {
                status = ele_hseb_common_ecdsa_sign(key_handle, alg,
                                                    hash, hash_length,
                                                    signature, signature_size,
                                                    signature_length, true);
            }
        } else if (true == PSA_ALG_IS_HASH_EDDSA(alg)) {
            /* EdDSA to be supported once key import for HSEB is supported */
            status = PSA_ERROR_NOT_SUPPORTED;
        } else {
            status = PSA_ERROR_NOT_SUPPORTED;
        }
    } else if (true == PSA_KEY_TYPE_IS_RSA(key_type)) {
        /* ELE_HSEB RSA hash sign/ver API does not align with the PSA API spec.
         * Per HSE API reference:
         *    "For RSA schemes, this [the input length] must be the length
         *     of the original (not pre-hashed) input."
         * This contition is not met by the PSA API, as we only receive hashlen.
         */
        status = PSA_ERROR_NOT_SUPPORTED;
    } else {
        status = PSA_ERROR_NOT_SUPPORTED;
    }

    if (PSA_SUCCESS != status) {
        *signature_length = 0u;
    }

    (void) ele_hseb_delete_key(&key_handle, HSE_ERASE_NOT_USED);

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_hseb_transparent_verify_hash(const psa_key_attributes_t *attributes,
                                              const uint8_t *key_buffer,
                                              size_t key_buffer_size,
                                              psa_algorithm_t alg,
                                              const uint8_t *hash,
                                              size_t hash_length,
                                              const uint8_t *signature,
                                              size_t signature_length)
{
    psa_status_t status       = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_type_t key_type   = psa_get_key_type(attributes);
    hseKeyHandle_t key_handle = { 0 };

    /* Check if correct alg. Per PSA spec, the PURE_EDDSA variant may
     * only be used with psa_sign_message() and psa_verify_message() functions.
     */
    if (false == PSA_ALG_IS_SIGN_HASH(alg) ||
        PSA_ALG_PURE_EDDSA == alg) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (NULL == key_buffer || 0u == key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == hash || 0u == hash_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (NULL == signature || 0u == signature_length) {
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (true == PSA_KEY_TYPE_IS_ECC(key_type)) {
        if (true == PSA_ALG_IS_ECDSA(alg) &&
            false == PSA_ALG_IS_DETERMINISTIC_ECDSA(alg)) {
            status = setkey_ecc(attributes, &key_handle, key_buffer,
                                key_buffer_size);
            if (PSA_SUCCESS == status) {
                status = ele_hseb_common_ecdsa_verify(key_handle, attributes,
                                                      alg, hash, hash_length,
                                                      signature, signature_length,
                                                      true);
            }
        } else if (true == PSA_ALG_IS_HASH_EDDSA(alg)) {
            /* EdDSA to be supported once key import for HSEB is supported */
            status = PSA_ERROR_NOT_SUPPORTED;
        } else {
            status = PSA_ERROR_NOT_SUPPORTED;
        }
    } else if (true == PSA_KEY_TYPE_IS_RSA(key_type)) {
        /* ELE_HSEB RSA hash sign/ver API does not align with the PSA API spec.
         * Per HSE API reference:
         *    "For RSA schemes, this [the input length] must be the length
         *     of the original (not pre-hashed) input."
         * This contition is not met by the PSA API, as we only receive hashlen.
         */
        status = PSA_ERROR_NOT_SUPPORTED;
    } else {
        status = PSA_ERROR_NOT_SUPPORTED;
    }

    (void) ele_hseb_delete_key(&key_handle, HSE_ERASE_NOT_USED);

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}
