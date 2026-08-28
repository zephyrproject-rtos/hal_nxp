/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_caam_hash.c
 *
 * This file contains the implementation of the entry points associated to the
 * hash capability (single-part and multipart) as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_caam_hash.h"

/* To be able to include the PSA style configuration */
#include "mbedtls/build_info.h"

static psa_status_t psa_to_caam_hash_algo(psa_algorithm_t alg, caam_hash_algo_t *hash_algo)
{
    uint32_t algo = PSA_ALG_GET_HASH(alg);

    switch (algo) {
        case PSA_ALG_SHA_1:
        {
            *hash_algo = kCAAM_Sha1;
            break;
        }
        case PSA_ALG_SHA_224:
        {
            *hash_algo = kCAAM_Sha224;
            break;
        }
        case PSA_ALG_SHA_256:
        {
            *hash_algo = kCAAM_Sha256;
            break;
        }
        case PSA_ALG_SHA_384:
        {
            *hash_algo = kCAAM_Sha384;
            break;
        }
        case PSA_ALG_SHA_512:
        {
            *hash_algo = kCAAM_Sha512;
            break;
        }
        default:
        {
            return PSA_ERROR_NOT_SUPPORTED;
        }
    }

    return PSA_SUCCESS;
}

/** \defgroup psa_hash PSA driver entry points for hashing
 *
 *  Entry points for hashing operations as described by the PSA Cryptoprocessor
 *  Driver interface specification
 *
 *  @{
 */
psa_status_t caam_hash_setup(mcux_caam_hash_operation_t *operation, psa_algorithm_t alg)
{
    psa_status_t status  = PSA_SUCCESS;
    status_t caam_status = kStatus_Fail;

    if (NULL == operation) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    memset(operation, 0, sizeof(mcux_caam_hash_operation_t));

    operation->handle.jobRing = kCAAM_JobRing0;

    if ((status = psa_to_caam_hash_algo(alg, &operation->caam_mode)) != PSA_SUCCESS) {
        return status;
    }
    operation->psa_mode = PSA_ALG_GET_HASH(alg);

    if (mcux_mutex_lock(&caam_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    caam_status = CAAM_HASH_Init(PSA_CAAM,
                                 &operation->handle,
                                 &operation->ctx,
                                 operation->caam_mode,
                                 NULL,
                                 0u);
    status      = caam_to_psa_status(caam_status);

    if (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t caam_hash_clone(const mcux_caam_hash_operation_t *source_operation,
                             mcux_caam_hash_operation_t *target_operation)
{
    uint16_t offset =
        332 -
        12u; // sizoef(caam_hash_ctx_internal_t)-sizeof(caam_hash_algo_t) -sizeof(caam_hash_algo_state_t) -4 => handle
    uint32_t target_handle = (uint32_t) &target_operation->handle;

    if ((source_operation == NULL) || (target_operation == NULL)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    memcpy(target_operation, source_operation, sizeof(mcux_caam_hash_operation_t));
    memcpy(&((uint8_t *) &target_operation->ctx)[offset], &target_handle,
           sizeof(&target_operation->handle));

    return PSA_SUCCESS;
}

psa_status_t caam_hash_update(mcux_caam_hash_operation_t *operation,
                              const uint8_t *input,
                              size_t input_length)
{
    psa_status_t status  = PSA_ERROR_CORRUPTION_DETECTED;
    status_t caam_status = kStatus_Fail;

    if (NULL == operation) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (0 == input_length) {
        /* This is a valid situation, no need to call ele_hash_update.
         * ele_hash_finish will produce the result.
         */
        return PSA_SUCCESS;
    }

    /* if len not zero, but pointer is NULL */
    if (NULL == input) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (mcux_mutex_lock(&caam_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    caam_status = CAAM_HASH_Update(&operation->ctx, input, input_length);
    status      = caam_to_psa_status(caam_status);

    if (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t caam_hash_finish(mcux_caam_hash_operation_t *operation,
                              uint8_t *hash,
                              size_t hash_size,
                              size_t *hash_length)
{
    psa_status_t status  = PSA_ERROR_CORRUPTION_DETECTED;
    status_t caam_status = kStatus_Fail;
    size_t out_length    = 0;

    if (operation == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Algorithm needs to be a HASH algo */
    if (!PSA_ALG_IS_HASH(operation->psa_mode)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (PSA_HASH_LENGTH(operation->psa_mode) > hash_size) {
        out_length = PSA_HASH_LENGTH(operation->psa_mode);
    }

    if ((hash == NULL) || (hash_size < out_length)) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Assign the output buffer size to 0. This will be updated */
    *hash_length = 0;

    if (mcux_mutex_lock(&caam_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    caam_status = CAAM_HASH_Finish(&operation->ctx, hash, hash_length);
    status      = caam_to_psa_status(caam_status);

    if (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t caam_hash_abort(mcux_caam_hash_operation_t *operation)
{
    /* Zeroize the context */
    memset(operation, 0, sizeof(mcux_caam_hash_operation_t));
    return PSA_SUCCESS;
}

psa_status_t caam_hash_compute(psa_algorithm_t alg,
                               const uint8_t *input,
                               size_t input_length,
                               uint8_t *hash,
                               size_t hash_size,
                               size_t *hash_length)
{
    psa_status_t status       = PSA_ERROR_CORRUPTION_DETECTED;
    status_t caam_status      = kStatus_Fail;
    size_t actual_hash_length = PSA_HASH_LENGTH(alg);
    caam_hash_algo_t mode     = (caam_hash_algo_t) 0;
    caam_handle_t caam_handle = { .jobRing = kCAAM_JobRing0 };

    if ((status = psa_to_caam_hash_algo(alg, &mode)) != PSA_SUCCESS) {
        return status;
    }

    if ((hash == NULL) || (hash_size == 0u)) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Fill the output buffer with something that isn't a valid hash
     * (barring an attack on the hash and deliberately-crafted input),
     * in case the caller doesn't check the return status properly. */

    /* If hash_size is 0 then hash may be NULL and then the
     * call to memset would have undefined behavior. */
    memset(hash, (int) '!', hash_size);

    if (hash_size < actual_hash_length) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Assign the output buffer size to 0. This will be updated */
    *hash_length = 0;

    if (mcux_mutex_lock(&caam_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    caam_status = CAAM_HASH(PSA_CAAM,
                            &caam_handle,
                            mode,
                            input,
                            input_length,
                            NULL,
                            0,
                            hash,
                            hash_length);
    status      = caam_to_psa_status(caam_status);

    if (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}
/** @} */ // end of psa_hash
