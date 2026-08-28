/*
 * Copyright 2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_ele_hseb_aead.c
 *
 * This file contains the implementation of the entry points associated to the
 * aead capability (single-part) as described by the PSA Cryptoprocessor
 * Driver interface specification.
 */

#include "mcux_psa_ele_hseb_aead.h"
#include "mcux_psa_ele_hseb_common_init.h"
#include "mcux_psa_ele_hseb_translate.h"
#include "mcux_psa_ele_hseb_key_management.h"

#include "hse_host_aead.h"
#include "hse_host_import_key.h"

#include "mcux_psa_util_wrapcheck_static_inline.h"

/**
 * \brief Translate PSA AEAD algorithm and key type to HSE parameters,
 *        and validate the tag length.
 *
 * \param[in]  alg        PSA AEAD algorithm (may include tag length override)
 * \param[in]  key_type   PSA key type
 * \param[out] tag_length Tag length encoded in the algorithm
 *
 * \retval PSA_SUCCESS on success.
 *         PSA_ERROR_NOT_SUPPORTED if the algorithm/key type combo is not supported.
 *         PSA_ERROR_INVALID_ARGUMENT if the tag length is invalid for the algorithm.
 */
static psa_status_t aead_check_alg_and_tag_length(psa_algorithm_t alg,
                                                  psa_key_type_t key_type,
                                                  size_t *tag_length)
{
    psa_algorithm_t default_alg = PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(alg);
    *tag_length                 = PSA_ALG_AEAD_GET_TAG_LENGTH(alg);

    if (PSA_KEY_TYPE_AES != key_type) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (PSA_ALG_GCM == default_alg) {
        if ((4u  == *tag_length) || (8u  == *tag_length) || (12u == *tag_length) ||
            (13u == *tag_length) || (14u == *tag_length) || (15u == *tag_length) ||
            (16u == *tag_length)) {
            return PSA_SUCCESS;
        } else {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }

    if (PSA_ALG_CCM == default_alg) {
        if ((4u  == *tag_length) || (6u  == *tag_length) || (8u  == *tag_length) ||
            (10u == *tag_length) || (12u == *tag_length) || (14u == *tag_length) ||
            (16u == *tag_length)) {
            return PSA_SUCCESS;
        } else {
            return PSA_ERROR_INVALID_ARGUMENT;
        }
    }

    return PSA_ERROR_NOT_SUPPORTED;
}

/** \defgroup psa_aead PSA transparent key driver entry points for AEAD
 *
 *  Entry points for single-part AEAD encryption and decryption as described
 *  by the PSA Cryptoprocessor Driver interface specification.
 *
 *  @{
 */

psa_status_t ele_hseb_transparent_aead_encrypt(const psa_key_attributes_t *attributes,
                                               const uint8_t *key_buffer,
                                               size_t key_buffer_size,
                                               psa_algorithm_t alg,
                                               const uint8_t *nonce,
                                               size_t nonce_length,
                                               const uint8_t *additional_data,
                                               size_t additional_data_length,
                                               const uint8_t *plaintext,
                                               size_t plaintext_length,
                                               uint8_t *ciphertext,
                                               size_t ciphertext_size,
                                               size_t *ciphertext_length)
{
    psa_status_t status          = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status = HSE_SRV_RSP_GENERAL_ERROR;
    psa_key_type_t key_type      = psa_get_key_type(attributes);
    size_t key_bits              = psa_get_key_bits(attributes);
    psa_algorithm_t default_alg  = PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(alg);
    hseKeyHandle_t key_handle    = 0u;
    size_t tag_length            = 0u;
    uint8_t *tag                 = NULL;

    if (false == PSA_ALG_IS_AEAD(alg)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Validate algorithm, key type, and tag length */
    status = aead_check_alg_and_tag_length(alg, key_type, &tag_length);
    if (PSA_SUCCESS != status) {
        return status;
    }

    if ((NULL == key_buffer) || (0u == key_buffer_size)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if ((PSA_BYTES_TO_BITS(key_buffer_size) != key_bits) ||
        ((128u != key_bits) && (192u != key_bits) && (256u != key_bits))) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if ((NULL == nonce) || (0u == nonce_length)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if ((NULL == ciphertext) || (NULL == ciphertext_length)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (true == mcux_psa_add_size_t_wrapcheck(plaintext_length, tag_length)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Output buffer must fit plaintext + tag */
    if (ciphertext_size < (plaintext_length + tag_length)) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    *ciphertext_length = 0u;

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    hseb_status = LoadAesKey(&key_handle, false,
                             (uint16_t) PSA_BITS_TO_BYTES(key_bits),
                             key_buffer);
    if (HSE_SRV_RSP_OK != hseb_status) {
        status = ele_hseb_to_psa_status(hseb_status);
        goto exit;
    }

    /* Tag is placed directly after the ciphertext in the output buffer */
    tag = ciphertext + plaintext_length;

    if (PSA_ALG_GCM == default_alg) {
        hseb_status = AesGcmEncrypt(key_handle,
                                    (uint32_t) nonce_length,
                                    nonce,
                                    (uint32_t) additional_data_length,
                                    additional_data,
                                    (uint32_t) plaintext_length,
                                    plaintext,
                                    (uint32_t) tag_length,
                                    tag,
                                    ciphertext,
                                    HSE_SGT_OPTION_NONE);
    } else if (PSA_ALG_CCM == default_alg) {
        hseb_status = AesCcmEncrypt(key_handle,
                                    (uint32_t) nonce_length,
                                    nonce,
                                    (uint32_t) additional_data_length,
                                    additional_data,
                                    (uint32_t) plaintext_length,
                                    plaintext,
                                    (uint32_t) tag_length,
                                    tag,
                                    ciphertext);
    } else {
        status = PSA_ERROR_NOT_SUPPORTED;
        goto exit;
    }

    if (HSE_SRV_RSP_OK != hseb_status) {
        status = ele_hseb_to_psa_status(hseb_status);
        goto exit;
    }

    *ciphertext_length = plaintext_length + tag_length;
    status = PSA_SUCCESS;

exit:
    (void) ele_hseb_delete_key(&key_handle, HSE_ERASE_NOT_USED);

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_hseb_transparent_aead_decrypt(const psa_key_attributes_t *attributes,
                                               const uint8_t *key_buffer,
                                               size_t key_buffer_size,
                                               psa_algorithm_t alg,
                                               const uint8_t *nonce,
                                               size_t nonce_length,
                                               const uint8_t *additional_data,
                                               size_t additional_data_length,
                                               const uint8_t *ciphertext,
                                               size_t ciphertext_length,
                                               uint8_t *plaintext,
                                               size_t plaintext_size,
                                               size_t *plaintext_length)
{
    psa_status_t status          = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status = HSE_SRV_RSP_GENERAL_ERROR;
    psa_key_type_t key_type      = psa_get_key_type(attributes);
    size_t key_bits              = psa_get_key_bits(attributes);
    psa_algorithm_t default_alg  = PSA_ALG_AEAD_WITH_DEFAULT_LENGTH_TAG(alg);
    hseKeyHandle_t key_handle    = 0u;
    size_t tag_length            = 0u;
    size_t cipher_length         = 0u;
    uint8_t *tag                 = NULL;

    if (false == PSA_ALG_IS_AEAD(alg)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Validate algorithm, key type, and tag length */
    status = aead_check_alg_and_tag_length(alg, key_type, &tag_length);
    if (PSA_SUCCESS != status) {
        return status;
    }

    if ((NULL == key_buffer) || (0u == key_buffer_size)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if ((PSA_BYTES_TO_BITS(key_buffer_size) != key_bits) ||
        ((128u != key_bits) && (192u != key_bits) && (256u != key_bits))) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if ((NULL == nonce) || (0u == nonce_length)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Ciphertext cannot be NULL and must be at least tag_length */
    if ((NULL == ciphertext) || (ciphertext_length < tag_length)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if ((NULL == plaintext) || (NULL == plaintext_length)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* The ciphertext buffer holds cipher || tag */
    cipher_length = ciphertext_length - tag_length;

    /* Output plaintext buffer must be large enough */
    if (plaintext_size < cipher_length) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    *plaintext_length = 0u;

    /* Tag is at the end of the ciphertext input buffer */
    tag = (uint8_t *) (ciphertext + cipher_length);

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Load transparent AES key into HSE RAM keystore */
    hseb_status = LoadAesKey(&key_handle, false,
                             (uint16_t) PSA_BITS_TO_BYTES(key_bits),
                             key_buffer);
    if (HSE_SRV_RSP_OK != hseb_status) {
        status = ele_hseb_to_psa_status(hseb_status);
        goto exit;
    }

    if (PSA_ALG_GCM == default_alg) {
        hseb_status = AesGcmDecrypt(key_handle,
                                    (uint32_t) nonce_length,
                                    nonce,
                                    (uint32_t) additional_data_length,
                                    additional_data,
                                    (uint32_t) cipher_length,
                                    ciphertext,
                                    (uint32_t) tag_length,
                                    tag,
                                    plaintext,
                                    HSE_SGT_OPTION_NONE);
    } else if (PSA_ALG_CCM == default_alg) {
        hseb_status = AesCcmDecrypt(key_handle,
                                    (uint32_t) nonce_length,
                                    nonce,
                                    (uint32_t) additional_data_length,
                                    additional_data,
                                    (uint32_t) cipher_length,
                                    ciphertext,
                                    (uint32_t) tag_length,
                                    tag,
                                    plaintext);
    } else {
        status = PSA_ERROR_NOT_SUPPORTED;
        goto exit;
    }

    if (HSE_SRV_RSP_OK != hseb_status) {
        status = ele_hseb_to_psa_status(hseb_status);
        goto exit;
    }

    *plaintext_length = cipher_length;
    status = PSA_SUCCESS;

exit:
    (void) ele_hseb_delete_key(&key_handle, HSE_ERASE_NOT_USED);

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

/** @} */ // end of psa_aead
