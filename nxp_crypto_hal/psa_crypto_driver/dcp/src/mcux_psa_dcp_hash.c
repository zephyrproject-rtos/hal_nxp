/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_dcp_hash.c
 *
 * This file contains the implementation of the entry points associated to the
 * hash capability (single-part and multipart) as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_dcp_hash.h"

/* To be able to include the PSA style configuration */
#include "mbedtls/build_info.h"

/*!
 * @brief Returns NXP DCP hash type based on PSA identification.
 *
 * \param[in]  alg       PSA algorithm
 * @param[out] hash_algo DCP algorithm
 *
 * @return status_t
 */
static psa_status_t psa_to_dcp_hash_algo(psa_algorithm_t alg, dcp_hash_algo_t *hash_algo)
{
    uint32_t algo = PSA_ALG_GET_HASH(alg);

    switch (algo) {
        case PSA_ALG_SHA_1:
        {
            *hash_algo = kDCP_Sha1;
            break;
        }
        case PSA_ALG_SHA_256:
        {
            *hash_algo = kDCP_Sha256;
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
psa_status_t dcp_hash_setup(mcux_dcp_hash_operation_t *operation, psa_algorithm_t alg)
{
    psa_status_t status = PSA_SUCCESS;
    status_t dcp_status = kStatus_Fail;

    if (NULL == operation) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    memset(operation, 0, sizeof(mcux_dcp_hash_operation_t));

    operation->handle.channel    = kDCP_Channel0;
    operation->handle.swapConfig = kDCP_NoSwap;
    operation->handle.keySlot    = kDCP_KeySlot0;

    if ((status = psa_to_dcp_hash_algo(alg, &operation->dcp_mode)) != PSA_SUCCESS) {
        return status;
    }
    operation->psa_mode = PSA_ALG_GET_HASH(alg);

    if (mcux_mutex_lock(&dcp_hwcrypto_mutex)) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    dcp_status = DCP_HASH_Init(PSA_DCP, &operation->handle, &operation->ctx, operation->dcp_mode);
    status     = dcp_to_psa_status(dcp_status);

    if (mcux_mutex_unlock(&dcp_hwcrypto_mutex)) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t dcp_hash_clone(const mcux_dcp_hash_operation_t *source_operation,
                            mcux_dcp_hash_operation_t *target_operation)
{
    uint16_t offset        = 184u - 4u; // sizoef(dcp_hash_ctx_internal_t) -4 => handle
    uint32_t target_handle = (uint32_t) &target_operation->handle;
    if ((source_operation == NULL) || (target_operation == NULL)) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Copy source to the target*/
    memcpy(target_operation, source_operation, sizeof(mcux_dcp_hash_operation_t));

    /* overwrite handle address with target */
#if defined(__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) && defined(DCP_USE_DCACHE) && \
    (DCP_USE_DCACHE == 1U)
    offset += FSL_FEATURE_L1DCACHE_LINESIZE_BYTE;
#endif
    memcpy(&((uint8_t *) &target_operation->ctx)[offset], &target_handle,
           sizeof(&target_operation->handle));

    return PSA_SUCCESS;
}

psa_status_t dcp_hash_update(mcux_dcp_hash_operation_t *operation,
                             const uint8_t *input,
                             size_t input_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    status_t dcp_status = kStatus_Fail;

    if (NULL == operation) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (0 == input_length) {
        /* This is a valid situation, no need to call dcp_hash_update.
         * dcp_hash_finish will produce the result.
         */
        return PSA_SUCCESS;
    }

    /* if len not zero, but pointer is NULL */
    if (NULL == input) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (mcux_mutex_lock(&dcp_hwcrypto_mutex)) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    dcp_status = DCP_HASH_Update(PSA_DCP, &operation->ctx, input, input_length);
    status     = dcp_to_psa_status(dcp_status);

    if (mcux_mutex_unlock(&dcp_hwcrypto_mutex)) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t dcp_hash_finish(mcux_dcp_hash_operation_t *operation,
                             uint8_t *hash,
                             size_t hash_size,
                             size_t *hash_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    status_t dcp_status = kStatus_Fail;
    size_t out_length   = 0;

    /* Assign the output buffer size to 0. This will be updated by ELE */
    *hash_length = 0;

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

    if (!hash || hash_size < out_length) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&dcp_hwcrypto_mutex)) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    *hash_length = hash_size;
    dcp_status   = DCP_HASH_Finish(PSA_DCP, &operation->ctx, hash, hash_length);
    status       = dcp_to_psa_status(dcp_status);

    if (mcux_mutex_unlock(&dcp_hwcrypto_mutex)) {
        *hash_length = 0;
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t dcp_hash_abort(mcux_dcp_hash_operation_t *operation)
{
    /* Zeroize the context */
    memset(operation, 0, sizeof(mcux_dcp_hash_operation_t));
    return PSA_SUCCESS;
}

psa_status_t dcp_hash_compute(psa_algorithm_t alg,
                              const uint8_t *input,
                              size_t input_length,
                              uint8_t *hash,
                              size_t hash_size,
                              size_t *hash_length)
{
    psa_status_t status       = PSA_ERROR_CORRUPTION_DETECTED;
    status_t dcp_status       = kStatus_Fail;
    size_t actual_hash_length = PSA_HASH_LENGTH(PSA_ALG_SIGN_GET_HASH(alg));
    dcp_hash_algo_t mode      = (dcp_hash_algo_t) 0;

    dcp_handle_t m_handle;
    m_handle.channel    = kDCP_Channel0;
    m_handle.swapConfig = kDCP_NoSwap;
    m_handle.keySlot    = kDCP_KeySlot0;

    /* Assign the output buffer size to 0. This will be updated by ELE */
    *hash_length = 0;

    if ((status = psa_to_dcp_hash_algo(alg, &mode)) != PSA_SUCCESS) {
        return status;
    }

    if (!hash || !hash_size) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Fill the output buffer with something that isn't a valid hash
     * (barring an attack on the hash and deliberately-crafted input),
     * in case the caller doesn't check the return status properly. */

    /* If hash_size is 0 then hash may be NULL and then the
     * call to memset would have undefined behavior. */
    if (hash_size != 0) {
        memset(hash, '!', hash_size);
    }

    if (hash_size < actual_hash_length) {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&dcp_hwcrypto_mutex)) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    *hash_length = hash_size;
    dcp_status   = DCP_HASH(PSA_DCP, &m_handle, mode, input, input_length, hash, hash_length);
    status       = dcp_to_psa_status(dcp_status);

    if (mcux_mutex_unlock(&dcp_hwcrypto_mutex)) {
        *hash_length = 0;
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}
/** @} */ // end of psa_hash
