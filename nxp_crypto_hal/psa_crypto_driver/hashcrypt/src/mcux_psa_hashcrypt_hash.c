/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_hashcrypt_hash.c
 *
 * This file contains the implementation of the entry points associated to the
 * hash capability (single-part and multipart) as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_hashcrypt_hash.h"

/* To be able to include the PSA style configuration */
#include "mbedtls/build_info.h"

static psa_status_t psa_to_hashcrypt_hash_algo(psa_algorithm_t alg, hashcrypt_algo_t *hash_algo)
{
    uint32_t algo = PSA_ALG_GET_HASH(alg);

    switch (algo) {
        case PSA_ALG_SHA_1:
        {
            *hash_algo = kHASHCRYPT_Sha1;
            break;
        }
        case PSA_ALG_SHA_256:
        {
            *hash_algo = kHASHCRYPT_Sha256;
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
psa_status_t hashcrypt_hash_setup(mcux_hashcrypt_hash_operation_t *operation, psa_algorithm_t alg)
{
    psa_status_t status       = PSA_SUCCESS;
    status_t hashcrypt_status = kStatus_Fail;

    if (NULL == operation) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    (void)memset(operation, 0, sizeof(mcux_hashcrypt_hash_operation_t));

    if ((status = psa_to_hashcrypt_hash_algo(alg, &operation->hashcrypt_mode)) != PSA_SUCCESS) {
        return status;
    }
    operation->psa_mode = PSA_ALG_GET_HASH(alg);

    if (mcux_mutex_lock(&hashcrypt_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    hashcrypt_status = HASHCRYPT_SHA_Init(PSA_HASHCRYPT, &operation->ctx,
                                          operation->hashcrypt_mode);
    status           = hashcrypt_to_psa_status(hashcrypt_status);

    if (mcux_mutex_unlock(&hashcrypt_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t hashcrypt_hash_clone(const mcux_hashcrypt_hash_operation_t *source_operation,
                                  mcux_hashcrypt_hash_operation_t *target_operation)
{
    if ((source_operation == NULL) || (target_operation == NULL)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    (void)memcpy(target_operation, source_operation, sizeof(mcux_hashcrypt_hash_operation_t));

    return PSA_SUCCESS;
}

psa_status_t hashcrypt_hash_update(mcux_hashcrypt_hash_operation_t *operation,
                                   const uint8_t *input,
                                   size_t input_length)
{
    psa_status_t status       = PSA_ERROR_CORRUPTION_DETECTED;
    status_t hashcrypt_status = kStatus_Fail;

    if (NULL == operation) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (0u == input_length) {
        /* This is a valid situation, no need to call ele_hash_update.
         * ele_hash_finish will produce the result.
         */
        return PSA_SUCCESS;
    }

    /* if len not zero, but pointer is NULL */
    if (NULL == input) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (mcux_mutex_lock(&hashcrypt_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    hashcrypt_status = HASHCRYPT_SHA_Update(PSA_HASHCRYPT, &operation->ctx, input, input_length);
    status           = hashcrypt_to_psa_status(hashcrypt_status);

    if (mcux_mutex_unlock(&hashcrypt_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t hashcrypt_hash_finish(mcux_hashcrypt_hash_operation_t *operation,
                                   uint8_t *hash,
                                   size_t hash_size,
                                   size_t *hash_length)
{
    psa_status_t status       = PSA_ERROR_CORRUPTION_DETECTED;
    status_t hashcrypt_status = kStatus_Fail;
    size_t out_length         = 0;

    /* Assign the output buffer size to 0. This will be updated by HASHCRYPT */
    *hash_length = 0;

    if (operation == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Algorithm needs to be a HASH algo */
    if (false == PSA_ALG_IS_HASH(operation->psa_mode)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (PSA_HASH_LENGTH(operation->psa_mode) > hash_size) {
        out_length = PSA_HASH_LENGTH(operation->psa_mode);
    }

    if (NULL == hash || hash_size < out_length) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&hashcrypt_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    *hash_length = hash_size;
    hashcrypt_status = HASHCRYPT_SHA_Finish(PSA_HASHCRYPT, &operation->ctx, hash, hash_length);
    status           = hashcrypt_to_psa_status(hashcrypt_status);

    if (mcux_mutex_unlock(&hashcrypt_hwcrypto_mutex) != 0) {
        *hash_length = 0;
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t hashcrypt_hash_abort(mcux_hashcrypt_hash_operation_t *operation)
{
    /* Zeroize the context */
    (void)memset(operation, 0, sizeof(mcux_hashcrypt_hash_operation_t));
    return PSA_SUCCESS;
}

psa_status_t hashcrypt_hash_compute(psa_algorithm_t alg,
                                    const uint8_t *input,
                                    size_t input_length,
                                    uint8_t *hash,
                                    size_t hash_size,
                                    size_t *hash_length)
{
    psa_status_t status       = PSA_ERROR_CORRUPTION_DETECTED;
    status_t hashcrypt_status = kStatus_Fail;
    size_t actual_hash_length = PSA_HASH_LENGTH(alg);
    hashcrypt_algo_t mode     = (hashcrypt_algo_t) 0;

    /* Assign the output buffer size to 0. This will be updated by ELE */
    *hash_length = 0;

    if ((status = psa_to_hashcrypt_hash_algo(alg, &mode)) != PSA_SUCCESS) {
        return status;
    }

    if (NULL == hash || 0u == hash_size) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Fill the output buffer with something that isn't a valid hash
     * (barring an attack on the hash and deliberately-crafted input),
     * in case the caller doesn't check the return status properly. */

    /* If hash_size is 0 then hash may be NULL and then the
     * call to memset would have undefined behavior. */
    if (hash_size != 0u) {
        (void)memset(hash, (int)'!', hash_size);
    }

    if (hash_size < actual_hash_length) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&hashcrypt_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    *hash_length = hash_size;
    hashcrypt_status = HASHCRYPT_SHA(PSA_HASHCRYPT, mode, input, input_length, hash, hash_length);
    status           = hashcrypt_to_psa_status(hashcrypt_status);

    if (mcux_mutex_unlock(&hashcrypt_hwcrypto_mutex) != 0) {
        *hash_length = 0;
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}
/** @} */ // end of psa_hash
