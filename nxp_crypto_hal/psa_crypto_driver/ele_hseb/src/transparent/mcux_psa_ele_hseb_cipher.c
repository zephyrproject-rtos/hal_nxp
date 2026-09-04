/*
 * Copyright 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_ele_hseb_cipher.c
 *
 * This file contains the implementation of the entry points associated to the
 * cipher capability as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */

#include "ele_hseb_crypto_primitives.h"
#include "mcux_psa_ele_hseb_utils.h"
#include "mcux_psa_ele_hseb_common_init.h"
#include "mcux_psa_ele_hseb_cipher.h"
#include "mcux_psa_ele_hseb_translate.h"
#include "mcux_psa_ele_hseb_key_management.h"

#include "hse_host_import_key.h"

#define AES_BLOCK_LENGTH (16u)

static bool is_input_length_correct(size_t input_length,
                                    psa_algorithm_t alg,
                                    psa_key_type_t key_type)
{
    /* The *_NO_PADDING and CFB modes require input length to be a multiple of block size */
    if (((PSA_ALG_ECB_NO_PADDING == alg) ||
         (PSA_ALG_CBC_NO_PADDING == alg) ||
         (PSA_ALG_CFB == alg)) &&
        (0u != (input_length % PSA_BLOCK_CIPHER_BLOCK_LENGTH(key_type)))) {
        return false;
    }
    return true;
}

psa_status_t ele_hseb_transparent_cipher_encrypt(const psa_key_attributes_t *attributes,
                                                 const uint8_t *key_buffer,
                                                 size_t key_buffer_size,
                                                 psa_algorithm_t alg,
                                                 const uint8_t *iv,
                                                 size_t iv_length,
                                                 const uint8_t *input,
                                                 size_t input_length,
                                                 uint8_t *output,
                                                 size_t output_size,
                                                 size_t *output_length)
{
    psa_status_t status              = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status     = HSE_SRV_RSP_GENERAL_ERROR;
    psa_key_type_t key_type          = psa_get_key_type(attributes);
    hseKeyHandle_t aes_key_handle    = 0u;
    hseCipherBlockMode_t cipher_mode = HSE_CIPHER_BLOCK_MODE_NULL;

    /* Key buffer or size or output buffer or output length can't be NULL */
    if (NULL == key_buffer || 0u == key_buffer_size ||
        NULL == output     || NULL == output_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (PSA_KEY_TYPE_AES != key_type) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* Algorithm must be a CIPHER algorithm */
    if (false == PSA_ALG_IS_CIPHER(alg)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Translate mode from PSA to HSE */
    cipher_mode = psa_to_hseb_cipher_mode(alg);

    if (HSE_CIPHER_BLOCK_MODE_NULL == cipher_mode) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* Check IV length for all modes except ECB */
    if ((PSA_ALG_ECB_NO_PADDING != alg) &&
        (PSA_CIPHER_IV_LENGTH(key_type, alg) != iv_length)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (false == is_input_length_correct(input_length, alg, key_type)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Check output buffer size */
    if (output_size < input_length) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Load the transparent key */
    hseb_status = LoadAesKey(&aes_key_handle, false, (uint16_t) key_buffer_size, key_buffer);
    if (HSE_SRV_RSP_OK != hseb_status) {
        status = ele_hseb_to_psa_status(hseb_status);
        goto exit;
    }

    /* Do the encryption */
    hseb_status = AesCrypt(aes_key_handle, cipher_mode, HSE_CIPHER_DIR_ENCRYPT,
                           iv, input_length, input, output);
    if (HSE_SRV_RSP_OK != hseb_status) {
        status = ele_hseb_to_psa_status(hseb_status);
        goto exit;
    }

    /* Only those algorithms are supported,
     * for which input and output lengths are equal
     */
    *output_length = input_length;

    status = PSA_SUCCESS;

exit:

    (void) ele_hseb_delete_key(&aes_key_handle, HSE_ERASE_NOT_USED);

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_hseb_transparent_cipher_decrypt(const psa_key_attributes_t *attributes,
                                                 const uint8_t *key_buffer,
                                                 size_t key_buffer_size,
                                                 psa_algorithm_t alg,
                                                 const uint8_t *input,
                                                 size_t input_length,
                                                 uint8_t *output,
                                                 size_t output_size,
                                                 size_t *output_length)
{
    psa_status_t status              = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status     = HSE_SRV_RSP_GENERAL_ERROR;
    psa_key_type_t key_type          = psa_get_key_type(attributes);
    hseKeyHandle_t aes_key_handle    = 0u;
    hseCipherBlockMode_t cipher_mode = HSE_CIPHER_BLOCK_MODE_NULL;
    size_t iv_length                 = PSA_CIPHER_IV_LENGTH(key_type, alg);
    const uint8_t *iv                = input;
    const uint8_t *input_no_iv       = NULL;
    size_t input_no_iv_length        = 0u;

    /* Key buffer or size or output buffer or output length can't be NULL */
    if (NULL == key_buffer || 0u == key_buffer_size ||
        NULL == output     || NULL == output_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (PSA_KEY_TYPE_AES != key_type) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* Algorithm must be a CIPHER algorithm */
    if (false == PSA_ALG_IS_CIPHER(alg)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* If alg takes IV, then it must by equal to AES_BLOCK_LENGTH */
    if (PSA_ALG_ECB_NO_PADDING != alg &&
        AES_BLOCK_LENGTH != iv_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Validate that input_length is large enough to subtract iv_length */
    if (input_length < iv_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Now safe to compute payload pointer and length */
    input_no_iv       = input + iv_length;
    input_no_iv_length = input_length - iv_length;

    /* Translate mode from PSA to HSE */
    cipher_mode = psa_to_hseb_cipher_mode(alg);

    if (HSE_CIPHER_BLOCK_MODE_NULL == cipher_mode) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (false == is_input_length_correct(input_no_iv_length, alg, key_type)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Check output buffer size */
    if (output_size < PSA_CIPHER_DECRYPT_OUTPUT_SIZE(key_type, alg, input_no_iv_length)) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Load the transparent key */
    hseb_status = LoadAesKey(&aes_key_handle, false, (uint16_t) key_buffer_size, key_buffer);
    if (HSE_SRV_RSP_OK != hseb_status) {
        status = ele_hseb_to_psa_status(hseb_status);
        goto exit;
    }

    /* Do the decryption */
    hseb_status = AesCrypt(aes_key_handle, cipher_mode, HSE_CIPHER_DIR_DECRYPT,
                           iv, input_no_iv_length, input_no_iv, output);
    if (HSE_SRV_RSP_OK != hseb_status) {
        status = ele_hseb_to_psa_status(hseb_status);
        goto exit;
    }

    *output_length = PSA_CIPHER_DECRYPT_OUTPUT_SIZE(key_type, alg, input_no_iv_length);

    status = PSA_SUCCESS;

exit:

    (void) ele_hseb_delete_key(&aes_key_handle, HSE_ERASE_NOT_USED);

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

static psa_status_t cipher_start_stream_internal(ele_hseb_transparent_cipher_operation_t *operation,
                                                 const uint8_t *iv)
{
    psa_status_t status          = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status = HSE_SRV_RSP_GENERAL_ERROR;
    hseKeyHandle_t key_handle    = 0u;

    hseb_status = LoadAesKey(&key_handle,
                             false,
                             (uint16_t)(PSA_BITS_TO_BYTES(operation->key_bits) & 0xFFFFU),
                             operation->key);
    status = ele_hseb_to_psa_status(hseb_status);
    if (PSA_SUCCESS != status) {
        goto exit;
    }

    if (HSE_CIPHER_DIR_ENCRYPT == operation->cipher_direction) {
        hseb_status = AesStartStreamEncrypt(key_handle,
                                            operation->cipher_mode,
                                            iv,
                                            0u, NULL, NULL,
                                            HSE_SGT_OPTION_NONE);
    } else { /* HSE_CIPHER_DIR_DECRYPT */
        hseb_status = AesStartStreamDecrypt(key_handle,
                                            operation->cipher_mode,
                                            iv,
                                            0u, NULL, NULL,
                                            HSE_SGT_OPTION_NONE);
    }
    status = ele_hseb_to_psa_status(hseb_status);

exit:
    (void) ele_hseb_delete_key(&key_handle, HSE_ERASE_NOT_USED);

    return status;
}

static psa_status_t cipher_common_setup(ele_hseb_transparent_cipher_operation_t *operation,
                                        const psa_key_attributes_t *attributes,
                                        const uint8_t *key_buffer,
                                        size_t key_buffer_size,
                                        psa_algorithm_t alg,
                                        hseCipherDir_t cipher_direction)
{
    psa_key_type_t key_type = psa_get_key_type(attributes);
    size_t key_bits         = psa_get_key_bits(attributes);
    psa_status_t status     = PSA_ERROR_CORRUPTION_DETECTED;

    /* Here we only set up the internal cipher driver context.
     * Because HSEB streaming mode requires the IV data in the START step,
     * we defer the HSEB cipher start call to ele_hseb_transparent_cipher_set_iv().
     */

    if (PSA_KEY_TYPE_AES != key_type) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    operation->cipher_mode = psa_to_hseb_cipher_mode(alg);
    if (HSE_CIPHER_BLOCK_MODE_NULL == operation->cipher_mode) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (32u < key_buffer_size) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    operation->cipher_direction = cipher_direction;
    operation->key_bits = key_bits;
    (void) memcpy(operation->key, key_buffer, key_buffer_size);

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (PSA_ALG_ECB_NO_PADDING == alg) {
        /* ECB does not take IV, so we mustn't defer the operation start call
         * to ele_hseb_transparent_cipher_set_iv(), since that will never
         * be called.
         */
        status = cipher_start_stream_internal(operation, NULL);
    } else {
        status = PSA_SUCCESS;
    }

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* If non-blocksize input is not supported, we need to manage our chunk */
    if (false == is_input_length_correct(1u, alg, key_type)) {
        operation->need_full_block = true;
    }

    return status;
}

psa_status_t ele_hseb_transparent_cipher_encrypt_setup(
    ele_hseb_transparent_cipher_operation_t *operation,
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg)
{
    return cipher_common_setup(operation, attributes, key_buffer,
                               key_buffer_size, alg, HSE_CIPHER_DIR_ENCRYPT);
}

psa_status_t ele_hseb_transparent_cipher_decrypt_setup(
    ele_hseb_transparent_cipher_operation_t *operation,
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg)
{
    return cipher_common_setup(operation, attributes, key_buffer,
                               key_buffer_size, alg, HSE_CIPHER_DIR_DECRYPT);
}

psa_status_t ele_hseb_transparent_cipher_set_iv(ele_hseb_transparent_cipher_operation_t *operation,
                                                const uint8_t *iv,
                                                size_t iv_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    /* If alg takes IV, then it must by equal to AES_BLOCK_LENGTH */
    if (HSE_CIPHER_BLOCK_MODE_ECB != operation->cipher_mode &&
        AES_BLOCK_LENGTH != iv_length) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* This is where we actually start the streaming operation, since PSA just
     * now provided the IV, which is required by the HSEB START request.
     *
     * Not applicable to ECB, since it takes no IV. ECB was started during setup
     * call.
     */
    status = cipher_start_stream_internal(operation, iv);

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

static psa_status_t cipher_update_compute(hseKeyHandle_t key_handle,
                                          hseCipherBlockMode_t cipher_mode,
                                          uint32_t input_length,
                                          const uint8_t *input,
                                          uint8_t *output,
                                          hseCipherDir_t cipher_direction)
{
    hseSrvResponse_t hseb_status = HSE_SRV_RSP_GENERAL_ERROR;

    if (HSE_CIPHER_DIR_ENCRYPT == cipher_direction) {
        hseb_status = AesUpdateStreamEncrypt(key_handle,
                                             cipher_mode,
                                             input_length,
                                             input,
                                             output,
                                             HSE_SGT_OPTION_NONE);
    } else { /* HSE_CIPHER_DIR_DECRYPT */
        hseb_status = AesUpdateStreamDecrypt(key_handle,
                                             cipher_mode,
                                             input_length,
                                             input,
                                             output,
                                             HSE_SGT_OPTION_NONE);
    }

    return ele_hseb_to_psa_status(hseb_status);
}

psa_status_t ele_hseb_transparent_cipher_update(ele_hseb_transparent_cipher_operation_t *operation,
                                                const uint8_t *input,
                                                size_t input_length,
                                                uint8_t *output,
                                                size_t output_size,
                                                size_t *output_length)
{
    psa_status_t status                    = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status           = HSE_SRV_RSP_GENERAL_ERROR;
    size_t remaining_input_length          = 0u;
    size_t usable_input_length             = 0u;
    bool is_chunk_full                     = false;
    size_t chunk_overflow                  = 0u;
    size_t expected_output_size            = 0u;
    size_t length_of_input_copied_to_chunk = 0u;
    hseKeyHandle_t key_handle              = 0u;

    *output_length = 0u;

    /* Check for a potentially small output buffer size */
    expected_output_size = output_size == 0u ? output_size : input_length;
    if (output_size < expected_output_size) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    hseb_status = LoadAesKey(&key_handle,
                             false,
                             (uint16_t)(PSA_BITS_TO_BYTES(operation->key_bits) & 0xFFFFU),
                             operation->key);
    status = ele_hseb_to_psa_status(hseb_status);
    if (PSA_SUCCESS != status) {
        goto exit;
    }

    /* 1. Fill the chunk buff as much as we can
     * 2. If chunk buff full
     *     2a. call first update
     *     2b. else we are done with this update with success.
     * 3. If we have additional data
     *     3a. If additional data length >= AES blocklen, do update on all full blocks and go to 3.
     *     3b. If additional data length <  AES blocklen, fill the chunk buffer
     * 4. Done
     */

    // 1. Fill the chunk buff as much as we can
    length_of_input_copied_to_chunk = ele_hseb_manage_chunk(operation->chunk,
                                                            sizeof(operation->chunk),
                                                            &(operation->chunk_length),
                                                            input,
                                                            input_length,
                                                            &is_chunk_full,
                                                            &chunk_overflow);

    // 2. If chunk buff full
    if (true == is_chunk_full) {
        // 2a. Call first update on chunk, clear chunk length
        status = cipher_update_compute(key_handle,
                                       operation->cipher_mode,
                                       operation->chunk_length,
                                       operation->chunk,
                                       output,
                                       operation->cipher_direction);

        *output_length          = *output_length + operation->chunk_length;
        output                  = output + operation->chunk_length;
        input                   = input + length_of_input_copied_to_chunk;
        operation->chunk_length = 0u;
    } else {
        // 2b. Else there is nothing else to do; exit soon with success
        *output_length = 0u;
        status         = PSA_SUCCESS;
        goto exit;
    }

    /* Check if the first UPDATE call passed */
    if (PSA_SUCCESS != status) {
        goto exit;
    }

    // 3. If we have additional data
    if (input_length > length_of_input_copied_to_chunk) {
        remaining_input_length = input_length - length_of_input_copied_to_chunk;

        // 3a. If additional data length >= AES blocklength (i.e. we can process at least some of it)
        if (remaining_input_length >= AES_BLOCK_LENGTH) {
            usable_input_length = (remaining_input_length / AES_BLOCK_LENGTH) * AES_BLOCK_LENGTH;

            status = cipher_update_compute(key_handle,
                                           operation->cipher_mode,
                                           usable_input_length,
                                           input,
                                           output,
                                           operation->cipher_direction);

            *output_length = *output_length + usable_input_length;
            input          = input + usable_input_length;
        }

        // There still might be a length of data < AES_BLOCK_LENGTH, save it
        remaining_input_length = remaining_input_length % AES_BLOCK_LENGTH;
        if (0u < remaining_input_length) {
            // 3b. Fill the chunk buffer
            (void) ele_hseb_manage_chunk(operation->chunk,
                                         sizeof(operation->chunk),
                                         &(operation->chunk_length),
                                         input,
                                         remaining_input_length,
                                         &is_chunk_full,
                                         &chunk_overflow);
        }
    }
    // 4. Done

exit:
    (void) ele_hseb_delete_key(&key_handle, HSE_ERASE_NOT_USED);

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

static psa_status_t cipher_finish_compute(hseKeyHandle_t key_handle,
                                          hseCipherBlockMode_t cipher_mode,
                                          uint32_t input_length,
                                          const uint8_t *input,
                                          uint8_t *output,
                                          hseCipherDir_t cipher_direction)
{
    hseSrvResponse_t hseb_status = HSE_SRV_RSP_GENERAL_ERROR;

    if (HSE_CIPHER_DIR_ENCRYPT == cipher_direction) {
        hseb_status = AesFinishStreamEncrypt(key_handle,
                                             cipher_mode,
                                             input_length,
                                             input,
                                             output,
                                             HSE_SGT_OPTION_NONE);
    } else { /* HSE_CIPHER_DIR_DECRYPT */
        hseb_status = AesFinishStreamDecrypt(key_handle,
                                             cipher_mode,
                                             input_length,
                                             input,
                                             output,
                                             HSE_SGT_OPTION_NONE);
    }

    return ele_hseb_to_psa_status(hseb_status);
}

psa_status_t ele_hseb_transparent_cipher_finish(ele_hseb_transparent_cipher_operation_t *operation,
                                                uint8_t *output,
                                                size_t output_size,
                                                size_t *output_length)
{
    psa_status_t status          = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status = HSE_SRV_RSP_GENERAL_ERROR;
    hseKeyHandle_t key_handle    = 0u;

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    hseb_status = LoadAesKey(&key_handle,
                             false,
                             (uint16_t)(PSA_BITS_TO_BYTES(operation->key_bits) & 0xFFFFU),
                             operation->key);
    status = ele_hseb_to_psa_status(hseb_status);
    if (PSA_SUCCESS != status) {
        goto exit;
    }

    if (true == operation->need_full_block) {
        /* As per HSEB spec, we must call FINISH to close off the operation,
         * so we call it on invalid data even if we correctly computed
         * everything during the very last UPDATE.
         */
        (void) cipher_finish_compute(key_handle,
                                     operation->cipher_mode,
                                     0u,
                                     NULL,
                                     NULL,
                                     operation->cipher_direction);

        /* If we needed chunk mgmt and processed everything,
         * we are successful
         */
        if (operation->chunk_length == 0u) {
            status = PSA_SUCCESS;
        } else {
            status = PSA_ERROR_INVALID_ARGUMENT;
        }

        *output_length = 0u;
    } else {
        if (0u < operation->chunk_length) {
            /* One last computation for the unprocessed chunks of non-blocksize
             * dependent ciphers
             */
            status = cipher_finish_compute(key_handle,
                                           operation->cipher_mode,
                                           operation->chunk_length,
                                           operation->chunk,
                                           output,
                                           operation->cipher_direction);
        } else {
            status = PSA_SUCCESS;
        }

        *output_length = operation->chunk_length;
    }

exit:
    (void) ele_hseb_delete_key(&key_handle, HSE_ERASE_NOT_USED);

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_hseb_transparent_cipher_abort(ele_hseb_transparent_cipher_operation_t *operation)
{
    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Call FINISH with bad inputs to invalidate the HSEB streaming operation.
     * Possibly not needed.
     */
    (void) AesFinishStreamEncrypt(0u,
                                  HSE_CIPHER_BLOCK_MODE_NULL,
                                  0u,
                                  NULL,
                                  NULL,
                                  HSE_SGT_OPTION_NONE);

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Zeroize the context */
    (void) memset(operation, 0, sizeof(ele_hseb_transparent_cipher_operation_t));

    return PSA_SUCCESS;
}
