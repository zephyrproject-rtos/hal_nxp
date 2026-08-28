/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_ele_hseb_hash.c
 *
 * This file contains the implementation of the entry points associated to the
 * hash capability as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_ele_hseb_utils.h"
#include "mcux_psa_ele_hseb_hash.h"
#include "mcux_psa_ele_hseb_init.h"
#include "mcux_psa_ele_hseb_translate.h"

#include "hse_host.h"
#include "hse_host_hash.h"
#include "hse_host_impex_stream.h"

/* Currently we don't have stream management; always use stream 0 */
#define STREAM_ID (0u)

psa_status_t ele_hseb_transparent_hash_compute(psa_algorithm_t alg,
                                               const uint8_t *input,
                                               size_t input_length,
                                               uint8_t *hash,
                                               size_t hash_size,
                                               size_t *hash_length)
{
    psa_status_t status          = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status = HSE_SRV_RSP_GENERAL_ERROR;
    hseHashAlgo_t hseb_hash = HSE_HASH_ALGO_NULL;

    if (NULL == hash || 0u == hash_size) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Fill the output buffer with something that isn't a valid hash
     * (barring an attack on the hash and deliberately-crafted input),
     * in case the caller doesn't check the return status properly. */
    memset(hash, '!', hash_size);

    if (hash_size < PSA_HASH_LENGTH(alg)) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    status = psa_to_ele_hseb_hash(alg, &hseb_hash);
    if (PSA_SUCCESS != status) {
        return status;
    }

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    *hash_length = hash_size;
    hseb_status  = HashDataDefSrv(hseb_hash, input_length, input, (uint32_t *) hash_length,
                                  hash, HSE_SGT_OPTION_NONE);

    status = ele_hseb_to_psa_status(hseb_status);
    if (PSA_SUCCESS != status) {
        *hash_length = 0u;
    }

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_hseb_transparent_hash_setup(ele_hseb_hash_operation_t *operation,
                                             psa_algorithm_t alg)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status = HSE_SRV_RSP_GENERAL_ERROR;
    hseHashAlgo_t hseb_hash = HSE_HASH_ALGO_NULL;

    status = psa_to_ele_hseb_hash(alg, &hseb_hash);
    if (PSA_SUCCESS != status) {
        return status;
    }

    operation->alg          = hseb_hash;
    operation->chunk_size   = PSA_HASH_BLOCK_LENGTH(alg);
    operation->chunk_length = 0u;

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    hseb_status = HashDataStartStreamDefSrv(hseb_hash, STREAM_ID);
    status = ele_hseb_to_psa_status(hseb_status);
    if (PSA_SUCCESS == status) {
        (void) StreamCtxExport(STREAM_ID, operation->ctx);
    }

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_hseb_transparent_hash_update(ele_hseb_hash_operation_t *operation,
                                              const uint8_t *input,
                                              size_t input_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status = HSE_SRV_RSP_GENERAL_ERROR;
    size_t length_of_input_copied_to_chunk = 0u;
    size_t chunk_overflow = 0u;
    bool is_chunk_full = false;
    size_t remaining_input_length = 0u;
    size_t usable_input_length = 0u;

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    hseb_status = StreamCtxImport(STREAM_ID, operation->ctx);
    status = ele_hseb_to_psa_status(hseb_status);
    if (PSA_SUCCESS != status) {
        goto exit;
    }

    length_of_input_copied_to_chunk = ele_hseb_manage_chunk(operation->chunk,
                                                            operation->chunk_size,
                                                            &(operation->chunk_length),
                                                            input,
                                                            input_length,
                                                            &is_chunk_full,
                                                            &chunk_overflow);

    if (true == is_chunk_full) {
        hseb_status = HashDataUpdateStreamDefSrv(operation->alg, STREAM_ID,
                                                 operation->chunk_length,
                                                 input);
        status = ele_hseb_to_psa_status(hseb_status);

        input                   = input + length_of_input_copied_to_chunk;
        operation->chunk_length = 0u;
    } else {
        status = PSA_SUCCESS;
        goto exit;
    }

    if (PSA_SUCCESS != status) {
        goto exit;
    }

    if (input_length > length_of_input_copied_to_chunk) {
        remaining_input_length = input_length - length_of_input_copied_to_chunk;

        if (remaining_input_length >= operation->chunk_size) {
            usable_input_length = (remaining_input_length / operation->chunk_size) *
                                  operation->chunk_size;


            hseb_status = HashDataUpdateStreamDefSrv(operation->alg, STREAM_ID,
                                                     usable_input_length,
                                                     input);
            status = ele_hseb_to_psa_status(hseb_status);

            input = input + usable_input_length;
        }

        remaining_input_length = remaining_input_length % operation->chunk_size;
        if (0u < remaining_input_length) {
            (void) ele_hseb_manage_chunk(operation->chunk,
                                         operation->chunk_size,
                                         &(operation->chunk_length),
                                         input,
                                         remaining_input_length,
                                         &is_chunk_full,
                                         &chunk_overflow);
        }
    }

    if (PSA_SUCCESS == status) {
        (void) StreamCtxExport(STREAM_ID, operation->ctx);
    }

exit:
    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_hseb_transparent_hash_finish(ele_hseb_hash_operation_t *operation,
                                              uint8_t *hash,
                                              size_t hash_size,
                                              size_t *hash_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    hseSrvResponse_t hseb_status = HSE_SRV_RSP_GENERAL_ERROR;
    psa_algorithm_t alg = PSA_ALG_NONE;

    /* Discard status retval; unless context has been tampered with, we already
     * know that the alg is supported.
     */
    (void) ele_hseb_to_psa_hash(operation->alg, &alg);
    if (PSA_HASH_LENGTH(alg) > hash_size) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    hseb_status = StreamCtxImport(STREAM_ID, operation->ctx);
    status = ele_hseb_to_psa_status(hseb_status);
    if (PSA_SUCCESS != status) {
        goto exit;
    }

    *hash_length = hash_size;
    hseb_status = HashDataFinishStreamDefSrv(operation->alg, STREAM_ID,
                                             operation->chunk_length,
                                             operation->chunk,
                                             (uint32_t *) hash_length, hash);
    status = ele_hseb_to_psa_status(hseb_status);
    if (PSA_SUCCESS == status) {
        (void) StreamCtxExport(STREAM_ID, operation->ctx);
    }

exit:
    if (PSA_SUCCESS != status) {
        *hash_length = 0u;
    }

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_hseb_transparent_hash_clone(const ele_hseb_hash_operation_t *source_operation,
                                             ele_hseb_hash_operation_t *target_operation)
{

    (void) memcpy(target_operation,
                  source_operation,
                  sizeof(ele_hseb_hash_operation_t));

    return PSA_SUCCESS;
}

psa_status_t ele_hseb_transparent_hash_abort(ele_hseb_hash_operation_t *operation)
{
    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Call FINISH with bad inputs to invalidate the HSEB streaming operation */
    (void) HashDataFinishStreamDefSrv(operation->alg, STREAM_ID, 0u, NULL,
                                      NULL, NULL);

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Zeroize the context */
    memset(operation, 0, sizeof(ele_hseb_hash_operation_t));

    return PSA_SUCCESS;
}
