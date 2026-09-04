/*
 * Copyright 2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_ele_hseb_common_asymmetric_signature.c
 *
 * This file contains the implementation of internal helper functions shared
 * by the transparent and opaque asymmetric signature drivers. All functions
 * operate on a pre-resolved HSE key handle and perform no key loading or
 * key deletion.
 */

#include "mcux_psa_ele_hseb_common_asymmetric_signature.h"
#include "mcux_psa_ele_hseb_translate.h"
#include "mcux_psa_ele_hseb_utils.h"

#include "hse_host_ecc.h"
#include "hse_host_sign.h"
#include "psa/crypto_values.h"

static size_t ele_hseb_get_rsa_pss_salt_length(const psa_key_attributes_t *attributes,
                                               psa_algorithm_t alg)
{
    /* PSA requires either saltlength == hashlength OR, if not possible,
     * largest possible salt length for given parameter combination.
     */
    if (psa_get_key_bits(attributes) == 1024u &&
        PSA_ALG_SHA_512 == PSA_ALG_GET_HASH(alg)) {
        return 62u;
    } else {
        return PSA_HASH_LENGTH(alg);
    }
}

psa_status_t ele_hseb_common_ecdsa_sign(hseKeyHandle_t key_handle,
                                        psa_algorithm_t alg,
                                        const uint8_t *input,
                                        size_t input_length,
                                        uint8_t *signature,
                                        size_t signature_size,
                                        size_t *signature_length,
                                        bool is_input_hashed)
{
    psa_status_t status                   = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status          = HSE_SRV_RSP_GENERAL_ERROR;
    hseSignScheme_t sign_scheme           = { 0 };
    uint8_t r[PSA_SIGNATURE_MAX_SIZE / 2] = { 0u };
    size_t rlen                           = sizeof(r);
    uint8_t s[PSA_SIGNATURE_MAX_SIZE / 2] = { 0u };
    size_t slen                           = sizeof(s);

    status = psa_to_ele_hseb_ecdsa(alg, &sign_scheme);
    if (PSA_SUCCESS != status) {
        goto exit;
    }

    hseb_status = EcdsaSign(key_handle, sign_scheme.sch.ecdsa.hashAlgo,
                            input_length, input, HSE_BOOL_TO_UINT(is_input_hashed),
                            HSE_SGT_OPTION_NONE, (uint32_t *) &rlen, r, (uint32_t *) &slen, s);
    status = ele_hseb_to_psa_status(hseb_status);

    /* Helps with overflow check and validates output parameters returned by HSEB */
    if ((rlen > (PSA_SIGNATURE_MAX_SIZE / 2)) ||
        (slen > (PSA_SIGNATURE_MAX_SIZE / 2))) {
        status = PSA_ERROR_HARDWARE_FAILURE;
    }

    /* This should already be checked by the caller, but we re-check to be sure.
     * If the caller got us here, we have most likely already overwritten something past the buffer.
     */
    if ((rlen + slen) > signature_size) {
        status = PSA_ERROR_BUFFER_TOO_SMALL;
    }

exit:
    if (PSA_SUCCESS != status) {
        *signature_length = 0u;
    } else {
        (void) memcpy(signature, r, rlen);
        (void) memcpy(signature + rlen, s, slen);
        *signature_length = rlen + slen;
    }

    return status;
}

psa_status_t ele_hseb_common_ecdsa_verify(hseKeyHandle_t key_handle,
                                          const psa_key_attributes_t *attributes,
                                          psa_algorithm_t alg,
                                          const uint8_t *input,
                                          size_t input_length,
                                          const uint8_t *signature,
                                          size_t signature_length,
                                          bool is_input_hashed)
{
    psa_status_t status          = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status = HSE_SRV_RSP_GENERAL_ERROR;
    hseSignScheme_t sign_scheme  = { 0 };
    size_t rlen                  = signature_length / 2u;
    size_t slen                  = signature_length / 2u;
    const uint8_t *r             = signature;
    const uint8_t *s             = signature + rlen;

    if (2u * PSA_BITS_TO_BYTES(psa_get_key_bits(attributes)) != signature_length) {
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    status = psa_to_ele_hseb_ecdsa(alg, &sign_scheme);
    if (PSA_SUCCESS != status) {
        goto exit;
    }

    hseb_status = EcdsaVerify(key_handle, sign_scheme.sch.ecdsa.hashAlgo,
                              input_length, input, HSE_BOOL_TO_UINT(is_input_hashed),
                              HSE_SGT_OPTION_NONE, (uint32_t *) &rlen, r, (uint32_t *) &slen, s);
    status = ele_hseb_to_psa_status(hseb_status);

exit:
    return status;
}

psa_status_t ele_hseb_common_rsa_sign(hseKeyHandle_t key_handle,
                                      const psa_key_attributes_t *attributes,
                                      psa_algorithm_t alg,
                                      const uint8_t *input,
                                      size_t input_length,
                                      uint8_t *signature,
                                      size_t signature_size,
                                      size_t *signature_length,
                                      bool is_input_hashed)
{
    psa_status_t status          = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status = HSE_SRV_RSP_GENERAL_ERROR;
    hseHashAlgo_t hseb_hash      = { 0 };
    size_t salt_length           = 0u;

    *signature_length = signature_size;

    if (true == PSA_ALG_IS_RSA_PKCS1V15_SIGN(alg)) {
        if (PSA_ALG_RSA_PKCS1V15_SIGN_RAW == alg) {
            /* HSEB does not support a signature scheme without a specified
             * hash algorithm.
             */
            status = PSA_ERROR_NOT_SUPPORTED;
            goto exit;
        } else {
            status = psa_to_ele_hseb_hash(alg, &hseb_hash);
            if (PSA_SUCCESS != status) {
                goto exit;
            }

            hseb_status = RsaPkcs1v15SignSrv(key_handle, hseb_hash,
                                             input_length, (uint8_t *) input,
                                             HSE_BOOL_TO_UINT(is_input_hashed),
                                             HSE_SGT_OPTION_NONE,
                                             (uint32_t *) signature_length, signature);
        }
    } else if (true == PSA_ALG_IS_RSA_PSS(alg)) {
        status = psa_to_ele_hseb_hash(alg, &hseb_hash);
        if (PSA_SUCCESS != status) {
            goto exit;
        }

        salt_length = ele_hseb_get_rsa_pss_salt_length(attributes, alg);

        hseb_status = RsaPssSignSrv(key_handle, salt_length, hseb_hash,
                                    input_length, input, HSE_BOOL_TO_UINT(is_input_hashed),
                                    HSE_SGT_OPTION_NONE,
                                    (uint32_t *) signature_length, signature);
    } else {
        status = PSA_ERROR_NOT_SUPPORTED;
        goto exit;
    }
    status = ele_hseb_to_psa_status(hseb_status);

exit:
    return status;
}

psa_status_t ele_hseb_common_rsa_verify(hseKeyHandle_t key_handle,
                                        const psa_key_attributes_t *attributes,
                                        psa_algorithm_t alg,
                                        const uint8_t *input,
                                        size_t input_length,
                                        const uint8_t *signature,
                                        size_t signature_length,
                                        bool is_input_hashed)
{
    psa_status_t status          = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status = HSE_SRV_RSP_GENERAL_ERROR;
    hseHashAlgo_t hseb_hash      = { 0 };
    size_t salt_length           = 0u;

    if (PSA_BITS_TO_BYTES(psa_get_key_bits(attributes)) != signature_length) {
        return PSA_ERROR_INVALID_SIGNATURE;
    }

    if (true == PSA_ALG_IS_RSA_PKCS1V15_SIGN(alg)) {
        if (PSA_ALG_RSA_PKCS1V15_SIGN_RAW == alg) {
            /* HSEB does not support a signature scheme without a specified
             * hash algorithm.
             */
            status = PSA_ERROR_NOT_SUPPORTED;
            goto exit;
        } else {
            status = psa_to_ele_hseb_hash(alg, &hseb_hash);
            if (PSA_SUCCESS != status) {
                goto exit;
            }

            hseb_status = RsaPkcs1v15VerSrv(key_handle, hseb_hash, input_length,
                                            input, HSE_BOOL_TO_UINT(is_input_hashed),
                                            HSE_SGT_OPTION_NONE,
                                            (uint32_t *) &signature_length, signature);
        }
    } else if (true == PSA_ALG_IS_RSA_PSS(alg)) {
        status = psa_to_ele_hseb_hash(alg, &hseb_hash);
        if (PSA_SUCCESS != status) {
            goto exit;
        }

        salt_length = ele_hseb_get_rsa_pss_salt_length(attributes, alg);

        hseb_status = RsaPssVerSrv(key_handle, salt_length, hseb_hash,
                                   input_length, input, HSE_BOOL_TO_UINT(is_input_hashed),
                                   HSE_SGT_OPTION_NONE, (uint32_t *) &signature_length,
                                   signature);
    } else {
        status = PSA_ERROR_NOT_SUPPORTED;
        goto exit;
    }
    status = ele_hseb_to_psa_status(hseb_status);

exit:
    return status;
}
