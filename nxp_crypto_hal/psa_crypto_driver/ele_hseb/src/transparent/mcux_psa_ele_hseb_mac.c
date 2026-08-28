/*
 * Copyright 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_ele_hseb_mac.c
 *
 * This file contains the implementation of the entry points associated to the
 * mac capability as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_ele_hseb_init.h"
#include "mcux_psa_ele_hseb_mac.h"
#include "mcux_psa_ele_hseb_translate.h"
#include "mcux_psa_ele_hseb_key_management.h"
#include "mcux_psa_ele_hseb_utils.h"

#include "hse_host_mac.h"
#include "hse_host_import_key.h"

/* Currently we don't have stream management; always use stream 0 */
#define STREAM_ID (0u)

#define AES_BLOCK_LENGTH (16u)

psa_status_t ele_hseb_transparent_mac_compute(const psa_key_attributes_t *attributes,
                                              const uint8_t *key_buffer,
                                              size_t key_buffer_size,
                                              psa_algorithm_t alg,
                                              const uint8_t *input,
                                              size_t input_length,
                                              uint8_t *mac,
                                              size_t mac_size,
                                              size_t *mac_length)
{
    psa_status_t status            = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status   = HSE_SRV_RSP_GENERAL_ERROR;
    psa_key_type_t key_type        = psa_get_key_type(attributes);
    size_t key_bits                = psa_get_key_bits(attributes);
    hseMacScheme_t hseb_mac_scheme = { 0 };
    hseKeyHandle_t key_handle      = { 0 };

    if (false == is_mac_key_size_supported(key_type, key_bits)) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    /* Algorithm must be a MAC algorithm */
    if (false == PSA_ALG_IS_MAC(alg)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    status = psa_to_hseb_mac_scheme(alg, &hseb_mac_scheme);
    if (PSA_SUCCESS != status) {
        return status;
    }

    /* Check MAC output buffer size */
    if (mac_size < PSA_MAC_LENGTH(key_type, key_bits, alg)) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (false == is_mac_length_supported(attributes, alg)) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Set the MAC length that is requested */
    *mac_length = PSA_MAC_LENGTH(key_type, key_bits, alg);

    /* Use a separate uint32_t to pass MAC length to HSEB APIs that require
     * a uint32_t pointer; copy back to size_t after the call. */
    uint32_t mac_length_u32 = (uint32_t) *mac_length;

    /* Key size in bytes must fit in uint16_t (max 512-bit = 64 bytes) */
    const size_t key_size_bytes = PSA_BITS_TO_BYTES(key_bits);
    if (key_size_bytes > (size_t) UINT16_MAX) {
        status = PSA_ERROR_INVALID_ARGUMENT;
        goto exit;
    }

    if (HSE_MAC_ALGO_CMAC == hseb_mac_scheme.macAlgo) {
        hseb_status = LoadAesKey(&key_handle, false,
                                 (uint16_t) key_size_bytes,
                                 key_buffer);
        if (HSE_SRV_RSP_OK != hseb_status) {
            status = ele_hseb_to_psa_status(hseb_status);
            goto exit;
        }

        hseb_status = AesCmacGenerate(key_handle, input_length, input,
                                      &mac_length_u32, mac, HSE_SGT_OPTION_NONE);
    } else { /* HSE_MAC_ALGO_HMAC */
        hseb_status = LoadHmacKey(&key_handle, false,
                                  (uint16_t) key_size_bytes,
                                  key_buffer);
        if (HSE_SRV_RSP_OK != hseb_status) {
            status = ele_hseb_to_psa_status(hseb_status);
            goto exit;
        }

        const hseHashAlgo_t hash_alg = hseb_mac_scheme.sch.hmac.hashAlgo;
        hseb_status = HmacGenerate(key_handle, hash_alg, input_length, input,
                                   &mac_length_u32, mac, HSE_SGT_OPTION_NONE);
    }

    if (HSE_SRV_RSP_OK != hseb_status) {
        *mac_length = 0u;
        status = ele_hseb_to_psa_status(hseb_status);
        goto exit;
    }

    /* Write back the actual MAC length reported by HSEB */
    *mac_length = (size_t) mac_length_u32;
    status = PSA_SUCCESS;
exit:
    (void) ele_hseb_delete_key(&key_handle, HSE_ERASE_NOT_USED);

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

static psa_status_t ele_hseb_transparent_mac_common_setup(
    ele_hseb_transparent_mac_operation_t *operation,
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg,
    hseAuthDir_t auth_direction)
{
    psa_status_t status            = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status   = HSE_SRV_RSP_GENERAL_ERROR;
    psa_key_type_t key_type        = psa_get_key_type(attributes);
    size_t key_bits                = psa_get_key_bits(attributes);
    hseMacScheme_t hseb_mac_scheme = { 0 };
    hseKeyHandle_t key_handle      = { 0 };

    if (false == is_mac_key_size_supported(key_type, key_bits)) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (HSEB_MAX_MAC_KEY_SIZE < key_buffer_size) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (false == PSA_ALG_IS_MAC(alg)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    status = psa_to_hseb_mac_scheme(alg, &hseb_mac_scheme);
    if (PSA_SUCCESS != status) {
        return status;
    }

    if (false == is_mac_length_supported(attributes, alg)) {
        return PSA_ERROR_NOT_SUPPORTED;
    }

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (PSA_KEY_TYPE_AES == key_type) {
        hseb_status = LoadAesKey(&key_handle, false,
                                 (uint16_t) (PSA_BITS_TO_BYTES(key_bits)),
                                 key_buffer);
        if (HSE_SRV_RSP_OK != hseb_status) {
            status = ele_hseb_to_psa_status(hseb_status);
            goto exit;
        }

        if (HSE_AUTH_DIR_GENERATE == auth_direction) {
            hseb_status = AesCmacGenerateStreamStart(key_handle, STREAM_ID,
                                                     0u, NULL, HSE_SGT_OPTION_NONE);
        } else {
            hseb_status = AesCmacVerifyStreamStart(key_handle, STREAM_ID,
                                                   0u, NULL, HSE_SGT_OPTION_NONE);
        }
        if (HSE_SRV_RSP_OK != hseb_status) {
            status = ele_hseb_to_psa_status(hseb_status);
            goto exit;
        }

        operation->chunk_size = PSA_BLOCK_CIPHER_BLOCK_LENGTH(key_type);
    } else if (PSA_KEY_TYPE_HMAC == key_type) {
        /* HSEB requires at least one full block of input data for HMAC START.
         * What we can do is defer START to an UPDATE call, in which we reach
         * the minimum required input length (i.e. operation->chunk_size).
         * After that we can mark is_mac_started as true.
         *
         * What also might happen is that we never reach a full block of data
         * until FINISH is called. In that case we just compute HMAC with a
         * one-shot operation.
         *
         * So we just save metadata that allows us to handle these cases.
         */
        operation->chunk_size     = PSA_HASH_BLOCK_LENGTH(PSA_ALG_GET_HASH(alg));
        operation->hash_alg       = hseb_mac_scheme.sch.hmac.hashAlgo;
        operation->is_mac_started = false;
    } else {
        status = PSA_ERROR_NOT_SUPPORTED;
        goto exit;
    }

    operation->auth_direction = auth_direction;
    operation->chunk_length   = 0u;
    operation->key_type       = key_type;
    operation->key_bits       = key_bits;
    operation->alg            = alg;
    (void) memcpy(operation->key, key_buffer, key_buffer_size);

    status = PSA_SUCCESS;
exit:
    (void) ele_hseb_delete_key(&key_handle, HSE_ERASE_NOT_USED);

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_hseb_transparent_mac_sign_setup(ele_hseb_transparent_mac_operation_t *operation,
                                                 const psa_key_attributes_t *attributes,
                                                 const uint8_t *key_buffer,
                                                 size_t key_buffer_size,
                                                 psa_algorithm_t alg)
{
    return ele_hseb_transparent_mac_common_setup(operation, attributes,
                                                 key_buffer, key_buffer_size, alg,
                                                 HSE_AUTH_DIR_GENERATE);
}

psa_status_t ele_hseb_transparent_mac_verify_setup(ele_hseb_transparent_mac_operation_t *operation,
                                                   const psa_key_attributes_t *attributes,
                                                   const uint8_t *key_buffer,
                                                   size_t key_buffer_size,
                                                   psa_algorithm_t alg)
{
    return ele_hseb_transparent_mac_common_setup(operation, attributes,
                                                 key_buffer, key_buffer_size, alg,
                                                 HSE_AUTH_DIR_VERIFY);
}

static psa_status_t cmac_update_internal(ele_hseb_transparent_mac_operation_t *operation,
                                         const uint8_t *input,
                                         size_t input_length)
{
    psa_status_t status           = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status  = HSE_SRV_RSP_GENERAL_ERROR;
    size_t overflow               = 0u;
    size_t update_length          = 0u;
    size_t left_over_length       = 0u;
    size_t remaining_input_length = 0u;
    size_t moved_length           = 0u;
    size_t final_input_shift      = 0u;
    bool is_chunk_full            = false;
    const size_t block_length     = AES_BLOCK_LENGTH;

    /* CMAC UPDATE constraints:
     *   1. input must be a non-zero multiple of the AES block size,
     *   2. we must leave at least one Byte of input deferred for the next call,
     *      just in case it is a FINISH call (it cannot be called on 0-input).
     */

    /* Place whatever we can into the chunk buffer */
    moved_length = ele_hseb_manage_chunk(operation->chunk, operation->chunk_size,
                                         &operation->chunk_length, input,
                                         input_length, &is_chunk_full, &overflow);

    if (false == is_chunk_full) {
        /* We have to have at least one full block for an UPDATE */
        return PSA_SUCCESS;
    }

    if (0u == overflow) {
        /* If we were to do an UPDATE, we must have something left over */
        return PSA_SUCCESS;
    }

    if (HSE_AUTH_DIR_GENERATE == operation->auth_direction) {
        hseb_status = AesCmacGenerateStreamUpdate(STREAM_ID, operation->chunk_length,
                                                  operation->chunk,
                                                  HSE_SGT_OPTION_NONE);
    } else {
        hseb_status = AesCmacVerifyStreamUpdate(STREAM_ID, operation->chunk_length,
                                                operation->chunk,
                                                HSE_SGT_OPTION_NONE);
    }
    if (HSE_SRV_RSP_OK != hseb_status) {
        status = ele_hseb_to_psa_status(hseb_status);
        goto exit;
    }
    operation->chunk_length   = 0u;
    operation->is_mac_started = true; // We got here; make sure this is true

    remaining_input_length = input_length - moved_length;
    update_length = (remaining_input_length / block_length) * block_length;
    left_over_length = remaining_input_length % block_length;

    if (update_length >= block_length) {
        /* We have at least one additional full block to process... */
        if (0u == left_over_length) {
            /* ...but we wouldn't be left with anything for FINISH. So we reduce
             * the UPDATE length by one block and we'll stash the last block
             * for a possible FINISH.
             */
            update_length    = update_length - block_length;
            left_over_length = block_length;
        }

        if (0u != update_length) {
            /* Make sure to not call HSEB with 0-length */
            if (HSE_AUTH_DIR_GENERATE == operation->auth_direction) {
                hseb_status = AesCmacGenerateStreamUpdate(STREAM_ID, update_length,
                                                          &input[moved_length],
                                                          HSE_SGT_OPTION_NONE);
            } else {
                hseb_status = AesCmacVerifyStreamUpdate(STREAM_ID, update_length,
                                                        &input[moved_length],
                                                        HSE_SGT_OPTION_NONE);
            }
            if (HSE_SRV_RSP_OK != hseb_status) {
                status = ele_hseb_to_psa_status(hseb_status);
                goto exit;
            }
        }
    }

    /* All went well; move the remaining data to the chunk buffer */
    final_input_shift = moved_length + update_length;
    (void) ele_hseb_manage_chunk(operation->chunk, operation->chunk_size,
                                 &operation->chunk_length,
                                 &input[final_input_shift], left_over_length,
                                 NULL, NULL);

    status = PSA_SUCCESS;
exit:
    return status;
}

static psa_status_t hmac_update_internal(ele_hseb_transparent_mac_operation_t *operation,
                                         const uint8_t *input,
                                         size_t input_length,
                                         hseKeyHandle_t *key_handle)
{
    psa_status_t status           = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status  = HSE_SRV_RSP_GENERAL_ERROR;
    bool is_chunk_full            = false;
    size_t update_length          = 0u;
    size_t left_over_length       = 0u;
    size_t remaining_input_length = 0u;
    size_t moved_length           = 0u;
    size_t final_input_shift      = 0u;
    const size_t block_length     = operation->chunk_size;

    /* Place whatever we can into the chunk buffer */
    moved_length = ele_hseb_manage_chunk(operation->chunk, operation->chunk_size,
                                         &operation->chunk_length, input,
                                         input_length, &is_chunk_full, NULL);
    if (false == is_chunk_full) {
        /* We have to have at least one full block for an UPDATE */
        return PSA_SUCCESS;
    }

    if (true == operation->is_mac_started) {
        if (HSE_AUTH_DIR_GENERATE == operation->auth_direction) {
            hseb_status = HmacGenerateUpdateStream(operation->hash_alg, STREAM_ID,
                                                   operation->chunk_length,
                                                   operation->chunk);
        } else {
            hseb_status = HmacVerifyUpdateStream(operation->hash_alg, STREAM_ID,
                                                 operation->chunk_length,
                                                 operation->chunk);
        }
    } else {
        /* The deferred START, since it must receive at least one full block */
        if (HSE_AUTH_DIR_GENERATE == operation->auth_direction) {
            hseb_status = HmacGenerateStartStream(*key_handle, operation->hash_alg,
                                                  STREAM_ID, operation->chunk_length,
                                                  operation->chunk);
        } else {
            hseb_status = HmacVerifyStartStream(*key_handle, operation->hash_alg,
                                                STREAM_ID, operation->chunk_length,
                                                operation->chunk);
        }
    }
    if (HSE_SRV_RSP_OK != hseb_status) {
        status = ele_hseb_to_psa_status(hseb_status);
        goto exit;
    }
    operation->chunk_length   = 0u;
    operation->is_mac_started = true; // We got here; make sure this is true

    remaining_input_length = input_length - moved_length;
    update_length = (remaining_input_length / block_length) * block_length;
    left_over_length = remaining_input_length % block_length;

    if (0u != update_length) {
        /* We have at least one additional full block to process */
        if (HSE_AUTH_DIR_GENERATE == operation->auth_direction) {
            hseb_status = HmacGenerateUpdateStream(operation->hash_alg, STREAM_ID,
                                                   update_length, &input[moved_length]);
        } else {
            hseb_status = HmacVerifyUpdateStream(operation->hash_alg, STREAM_ID,
                                                 update_length, &input[moved_length]);
        }
        if (HSE_SRV_RSP_OK != hseb_status) {
            status = ele_hseb_to_psa_status(hseb_status);
            goto exit;
        }
    }

    final_input_shift = moved_length + update_length;
    (void) ele_hseb_manage_chunk(operation->chunk, operation->chunk_size,
                                 &operation->chunk_length,
                                 &input[final_input_shift], left_over_length,
                                 NULL, NULL);

    status = PSA_SUCCESS;
exit:
    return status;
}

psa_status_t ele_hseb_transparent_mac_update(ele_hseb_transparent_mac_operation_t *operation,
                                             const uint8_t *input,
                                             size_t input_length)
{
    psa_status_t status          = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status = HSE_SRV_RSP_GENERAL_ERROR;
    hseKeyHandle_t key_handle    = { 0 };

    if (0u == input_length) {
        return PSA_SUCCESS;
    }

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (PSA_KEY_TYPE_AES == operation->key_type) {
        hseb_status = LoadAesKey(&key_handle, false,
                                 (uint16_t) (PSA_BITS_TO_BYTES(operation->key_bits)),
                                 operation->key);
        if (HSE_SRV_RSP_OK != hseb_status) {
            status = ele_hseb_to_psa_status(hseb_status);
            goto exit;
        }

        status = cmac_update_internal(operation, input, input_length);
        if (PSA_SUCCESS != status) {
            goto exit;
        }
    } else if (PSA_KEY_TYPE_HMAC == operation->key_type) {
        hseb_status = LoadHmacKey(&key_handle, false,
                                  (uint16_t) (PSA_BITS_TO_BYTES(operation->key_bits)),
                                  operation->key);
        if (HSE_SRV_RSP_OK != hseb_status) {
            status = ele_hseb_to_psa_status(hseb_status);
            goto exit;
        }

        status = hmac_update_internal(operation, input, input_length, &key_handle);
        if (PSA_SUCCESS != status) {
            goto exit;
        }
    } else {
        status = PSA_ERROR_INVALID_ARGUMENT;
        goto exit;
    }

    status = PSA_SUCCESS;
exit:
    (void) ele_hseb_delete_key(&key_handle, HSE_ERASE_NOT_USED);

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_hseb_transparent_mac_sign_finish(ele_hseb_transparent_mac_operation_t *operation,
                                                  uint8_t *mac,
                                                  size_t mac_size,
                                                  size_t *mac_length)
{
    psa_status_t status          = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status = HSE_SRV_RSP_GENERAL_ERROR;
    hseKeyHandle_t key_handle    = { 0 };

    /* MAC length support validated in setup(), now just validate output size */
    *mac_length = PSA_MAC_LENGTH(operation->key_type,
                                 operation->key_bits,
                                 operation->alg);

    if (mac_size < *mac_length) {
        *mac_length = 0u;
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Use a separate uint32_t for HSEB APIs that require a uint32_t pointer */
    uint32_t mac_length_u32 = (uint32_t) *mac_length;

    if (PSA_KEY_TYPE_AES == operation->key_type) {
        hseb_status = LoadAesKey(&key_handle, false,
                                 (uint16_t) (PSA_BITS_TO_BYTES(operation->key_bits)),
                                 operation->key);
        if (HSE_SRV_RSP_OK != hseb_status) {
            status = ele_hseb_to_psa_status(hseb_status);
            goto exit;
        }

        if (true == operation->is_mac_started) {
            hseb_status = AesCmacGenerateStreamFinish(STREAM_ID, operation->chunk_length,
                                                      operation->chunk,
                                                      &mac_length_u32, mac,
                                                      HSE_SGT_OPTION_NONE);
        } else {
            /* This should be only reachable iff CMAC never received at least
             * one full block length of data via UPDATE. HSEB multipart MAC
             * cannot handle cases where it receives no input during the entire
             * stream, so we use one-shot.
             */
            hseb_status = AesCmacGenerate(key_handle, operation->chunk_length,
                                          operation->chunk, &mac_length_u32,
                                          mac, HSE_SGT_OPTION_NONE);
        }
        if (HSE_SRV_RSP_OK != hseb_status) {
            status = ele_hseb_to_psa_status(hseb_status);
            goto exit;
        }
    } else if (PSA_KEY_TYPE_HMAC == operation->key_type) {
        hseb_status = LoadHmacKey(&key_handle, false,
                                  (uint16_t) (PSA_BITS_TO_BYTES(operation->key_bits)),
                                  operation->key);
        if (HSE_SRV_RSP_OK != hseb_status) {
            status = ele_hseb_to_psa_status(hseb_status);
            goto exit;
        }

        if (true == operation->is_mac_started) {
            hseb_status = HmacGenerateFinishStream(operation->hash_alg, STREAM_ID,
                                                   operation->chunk_length,
                                                   operation->chunk,
                                                   &mac_length_u32, mac);
        } else {
            /* We didn't receive enough data to START multipart HMAC,
             * so we consume the stashed data with a one-shot operation.
             */
            hseb_status = HmacGenerate(key_handle, operation->hash_alg,
                                       operation->chunk_length, operation->chunk,
                                       &mac_length_u32, mac,
                                       HSE_SGT_OPTION_NONE);
        }
        if (HSE_SRV_RSP_OK != hseb_status) {
            status = ele_hseb_to_psa_status(hseb_status);
            goto exit;
        }
    } else {
        status = PSA_ERROR_INVALID_ARGUMENT;
        goto exit;
    }

    /* Write back the actual MAC length reported by HSEB */
    *mac_length = (size_t) mac_length_u32;
    status = PSA_SUCCESS;
exit:
    (void) ele_hseb_delete_key(&key_handle, HSE_ERASE_NOT_USED);

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_hseb_transparent_mac_verify_finish(ele_hseb_transparent_mac_operation_t *operation,
                                                    const uint8_t *mac,
                                                    size_t mac_length)
{
    psa_status_t status                = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status       = HSE_SRV_RSP_GENERAL_ERROR;
    hseKeyHandle_t key_handle          = { 0 };
    const uint32_t mac_length_internal = mac_length;

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (PSA_KEY_TYPE_AES == operation->key_type) {
        hseb_status = LoadAesKey(&key_handle, false,
                                 (uint16_t) (PSA_BITS_TO_BYTES(operation->key_bits)),
                                 operation->key);
        if (HSE_SRV_RSP_OK != hseb_status) {
            status = ele_hseb_to_psa_status(hseb_status);
            goto exit;
        }

        if (true == operation->is_mac_started) {
            hseb_status = AesCmacVerifyStreamFinish(STREAM_ID, operation->chunk_length,
                                                    operation->chunk, &mac_length_internal,
                                                    mac, HSE_SGT_OPTION_NONE);
        } else {
            /* This should be only reachable iff CMAC never received at least
             * one full block length of data via UPDATE. HSEB multipart MAC
             * cannot handle cases where it receives no input during the entire
             * stream, so we use one-shot.
             */
            hseb_status = AesCmacVerify(key_handle, operation->chunk_length,
                                        operation->chunk, &mac_length_internal,
                                        mac, HSE_SGT_OPTION_NONE);
        }
        if (HSE_SRV_RSP_OK != hseb_status) {
            status = ele_hseb_to_psa_status(hseb_status);
            goto exit;
        }
    } else if (PSA_KEY_TYPE_HMAC == operation->key_type) {
        hseb_status = LoadHmacKey(&key_handle, false,
                                  (uint16_t) (PSA_BITS_TO_BYTES(operation->key_bits)),
                                  operation->key);
        if (HSE_SRV_RSP_OK != hseb_status) {
            status = ele_hseb_to_psa_status(hseb_status);
            goto exit;
        }

        if (true == operation->is_mac_started) {
            hseb_status = HmacVerifyFinishStream(operation->hash_alg, STREAM_ID,
                                                 operation->chunk_length,
                                                 operation->chunk,
                                                 &mac_length_internal, mac);
        } else {
            /* We didn't receive enough data to START multipart HMAC,
             * so we consume the stashed data with a one-shot operation.
             */
            hseb_status = HmacVerify(key_handle, operation->hash_alg,
                                     operation->chunk_length, operation->chunk,
                                     &mac_length_internal, mac);
        }
        if (HSE_SRV_RSP_OK != hseb_status) {
            status = ele_hseb_to_psa_status(hseb_status);
            goto exit;
        }
    } else {
        status = PSA_ERROR_INVALID_ARGUMENT;
        goto exit;
    }

    status = PSA_SUCCESS;
exit:
    (void) ele_hseb_delete_key(&key_handle, HSE_ERASE_NOT_USED);

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_hseb_transparent_mac_abort(ele_hseb_transparent_mac_operation_t *operation)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* We call FINISH with invalid parameters to close the stream if open */
    if (PSA_KEY_TYPE_AES == operation->key_type) {
        (void) AesCmacGenerateStreamFinish(STREAM_ID, 0u, NULL, NULL,
                                           NULL, HSE_SGT_OPTION_NONE);
    } else if (PSA_KEY_TYPE_HMAC == operation->key_type) {
        (void) HmacGenerateFinishStream(0u, STREAM_ID, 0u, NULL, NULL,
                                        NULL);
    } else {
        status = PSA_ERROR_INVALID_ARGUMENT;
        goto exit;
    }

    (void) memset(operation, 0, sizeof(ele_hseb_transparent_mac_operation_t));

    status = PSA_SUCCESS;
exit:
    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}
