/*
 * Copyright 2024-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_s2xx_hash.c
 *
 * This file contains the implementation of the entry points associated to the
 * hash capability (single-part and multipart) as described by the PSA
 * Cryptoprocessor Driver interface specification
 *
 */

#include "mcux_psa_s2xx_init.h"
#include "mcux_psa_s2xx_hash.h"

/* To be able to include the PSA style configuration */
#include "mbedtls/build_info.h"

#define SHA224_DIGEST_SIZE_IN_BYTES (224u / 8u)
#define SHA256_DIGEST_SIZE_IN_BYTES (256u / 8u)
#define SHA384_DIGEST_SIZE_IN_BYTES (384u / 8u)
#define SHA512_DIGEST_SIZE_IN_BYTES (512u / 8u)

static psa_status_t translate_psa_hash_to_ele_hash(psa_algorithm_t alg, sss_algorithm_t *mode)
{
    psa_status_t status = PSA_SUCCESS;
    switch (alg)
    {
#if defined(PSA_WANT_ALG_SHA_224)
        case PSA_ALG_SHA_224:
            *mode = kAlgorithm_SSS_SHA224;
            break;
#endif /* PSA_WANT_ALG_SHA_224 */
#if defined(PSA_WANT_ALG_SHA_256)
        case PSA_ALG_SHA_256:
            *mode = kAlgorithm_SSS_SHA256;
            break;
#endif /* PSA_WANT_ALG_SHA_256 */
#if defined(PSA_WANT_ALG_SHA_384)
        case PSA_ALG_SHA_384:
            *mode = kAlgorithm_SSS_SHA384;
            break;
#endif /* PSA_WANT_ALG_SHA_384 */
#if defined(PSA_WANT_ALG_SHA_512)
        case PSA_ALG_SHA_512:
            *mode = kAlgorithm_SSS_SHA512;
            break;
#endif /* PSA_WANT_ALG_SHA_512 */
#if defined(ELE_HAVE_SHA3)
#if defined(PSA_WANT_ALG_SHA3_224)
        case PSA_ALG_SHA3_224:
            *mode = kAlgorithm_SSS_SHA3_224;
            break;
#endif /* PSA_WANT_ALG_SHA3_224 */
#if defined(PSA_WANT_ALG_SHA3_256)
        case PSA_ALG_SHA3_256:
            *mode = kAlgorithm_SSS_SHA3_256;
            break;
#endif /* PSA_WANT_ALG_SHA3_256 */
#if defined(PSA_WANT_ALG_SHA3_384)
        case PSA_ALG_SHA3_384:
            *mode = kAlgorithm_SSS_SHA3_384;
            break;
#endif /* PSA_WANT_ALG_SHA3_384 */
#if defined(PSA_WANT_ALG_SHA3_512)
        case PSA_ALG_SHA3_512:
            *mode = kAlgorithm_SSS_SHA3_512;
            break;
#endif /* PSA_WANT_ALG_SHA3_512 */
#endif /* ELE_HAVE_SHA3 */
#if defined(PSA_WANT_ALG_SHA_1)
        case PSA_ALG_SHA_1:
            *mode = kAlgorithm_SSS_SHA1;
            break;
#endif /* PSA_WANT_ALG_SHA_1 */
        default:
            status = PSA_ERROR_NOT_SUPPORTED;
            break;
    }
    return status;
}

#if defined(CONFIG_ELE_S2XX_ENABLE_HASH_CONTEXT_IMPORT_EXPORT)
#if defined(ELE_FEATURE_DIGEST_IMPORT)
/** \brief Initialize a digest context and import a context blob into it
 *
 * \param[in,out] operation Pointer to the hash operation structure containing
 *                          the context blob and the digest context to initialize.
 *
 * \retval PSA_SUCCESS The context was successfully imported and initialized.
 * \retval PSA_ERROR_GENERIC_ERROR An error occurred during context import or
 *         initialization.
 */
static psa_status_t ele_s2xx_import_digest_context(ele_s2xx_hash_operation_t *operation)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    do
    {
        if (sss_sscp_digest_context_init(&operation->ctx, &g_ele_ctx.sssSession,
                                         operation->ctx.algorithm,
                                         kMode_SSS_Digest) != kStatus_SSS_Success)
        {
            status = PSA_ERROR_GENERIC_ERROR;
            break;
        }

        if (sss_sscp_digest_import(&operation->ctx, operation->context_blob,
                                   ELE_S2XX_MULTIPART_HASH_BLOB_SIZE) != kStatus_SSS_Success)
        {
            status = PSA_ERROR_GENERIC_ERROR;
            break;
        }

        status = PSA_SUCCESS;
    } while (false);

    return status;
}
#endif /* ELE_FEATURE_DIGEST_IMPORT */

#if defined(ELE_FEATURE_DIGEST_EXPORT)
/** \brief Export a digest context blob and free the digest context
 *
 * Take the hash operation provided by PSA, which holds an active S200 context,
 * and export the context blob from it. After export, the context is freed.
 *
 * \param[in,out] operation Pointer to the hash operation structure containing
 *                          the in-progress hash context and the blob buffer.
 *
 * \retval PSA_SUCCESS The context was successfully exported and freed.
 * \retval PSA_ERROR_GENERIC_ERROR An error occurred during context export or
 *         free operation.
 */
static psa_status_t ele_s2xx_export_digest_context(ele_s2xx_hash_operation_t *operation)
{
    psa_status_t status      = PSA_ERROR_CORRUPTION_DETECTED;
    size_t context_blob_size = ELE_S2XX_MULTIPART_HASH_BLOB_SIZE;

    do
    {
        if (sss_sscp_digest_export(&operation->ctx, operation->context_blob,
                                   &context_blob_size) != kStatus_SSS_Success)
        {
            status = PSA_ERROR_GENERIC_ERROR;
            /* Don't break, we want to free the context regardless of failure */
        }

        if (sss_sscp_digest_context_free(&operation->ctx) != kStatus_SSS_Success)
        {
            status = PSA_ERROR_GENERIC_ERROR;
            break;
        }

        if (PSA_ERROR_GENERIC_ERROR == status)
        {
            /* Something went wrong, we already cleaned up, exit with error */
            break;
        }

        status = PSA_SUCCESS;
    } while (false);

    return status;
}
#endif /* ELE_FEATURE_DIGEST_EXPORT */
#endif /* CONFIG_ELE_S2XX_ENABLE_HASH_CONTEXT_IMPORT_EXPORT */

/** \defgroup psa_hash PSA driver entry points for hashing
 *
 *  Entry points for hashing operations as described by the PSA Cryptoprocessor
 *  Driver interface specification
 *
 *  @{
 */
psa_status_t ele_s2xx_transparent_hash_setup(ele_s2xx_hash_operation_t *operation, psa_algorithm_t alg)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    if (NULL == operation)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    (void)memset(operation, 0, sizeof(ele_s2xx_hash_operation_t));

    if ((status = translate_psa_hash_to_ele_hash(alg, &operation->ctx.algorithm)) != PSA_SUCCESS)
    {
        return status;
    }

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (sss_sscp_digest_context_init(&operation->ctx, &g_ele_ctx.sssSession, operation->ctx.algorithm,
                                     kMode_SSS_Digest) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    if (sss_sscp_digest_init(&operation->ctx) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

#if defined(ELE_FEATURE_DIGEST_EXPORT) && defined(CONFIG_ELE_S2XX_ENABLE_HASH_CONTEXT_IMPORT_EXPORT)
    status = ele_s2xx_export_digest_context(operation);
#endif

exit:
    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_s2xx_transparent_hash_clone(const ele_s2xx_hash_operation_t *source_operation,
                                             ele_s2xx_hash_operation_t *target_operation)
{
#if defined(ELE_FEATURE_DIGEST_CLONE) && (ELE_FEATURE_DIGEST_CLONE == 1)
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    if (source_operation == NULL || target_operation == NULL)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    (void)memset(target_operation, 0, sizeof(ele_s2xx_hash_operation_t));

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

#if defined(ELE_FEATURE_DIGEST_IMPORT) && defined(CONFIG_ELE_S2XX_ENABLE_HASH_CONTEXT_IMPORT_EXPORT)
    status = ele_s2xx_import_digest_context((ele_s2xx_hash_operation_t *)source_operation);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }
#endif

    if (sss_sscp_digest_context_init(&target_operation->ctx, &g_ele_ctx.sssSession, source_operation->ctx.algorithm,
                                     kMode_SSS_Digest) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    /* coverity[misra_c_2012_rule_11_8_violation]: cast removes const qualifier intentionally to pass to SSS clone API */
    if (sss_sscp_digest_clone((sss_sscp_digest_t *)&source_operation->ctx, &target_operation->ctx) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

#if defined(ELE_FEATURE_DIGEST_EXPORT) && defined(CONFIG_ELE_S2XX_ENABLE_HASH_CONTEXT_IMPORT_EXPORT)
    status = ele_s2xx_export_digest_context((ele_s2xx_hash_operation_t *)source_operation);
    if (PSA_SUCCESS != status)
    {
        /* On cloning failure, PSA aborts only the target op, so we need to
         * make sure we free the source op context.
         */
        (void)sss_sscp_digest_context_free((sss_sscp_digest_t *)&source_operation->ctx);
        goto exit;
    }

    /* We export twice, because we have two output contexts */
    status = ele_s2xx_export_digest_context(target_operation);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }
#endif

    status = PSA_SUCCESS;

exit:
    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
#else /* ELE_FEATURE_DIGEST_CLONE */
    (void)source_operation;
    (void)target_operation;
    return PSA_ERROR_NOT_SUPPORTED;
#endif /* ELE_FEATURE_DIGEST_CLONE */
}

psa_status_t ele_s2xx_transparent_hash_update(ele_s2xx_hash_operation_t *operation,
                                              const uint8_t *input,
                                              size_t input_length)
{
    psa_status_t status = PSA_SUCCESS;

    if (NULL == operation)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (0u == input_length)
    {
        /* This is a valid situation, no need to call ele_hash_update.
         * ele_hash_finish will produce the result.
         */
        return PSA_SUCCESS;
    }

    /* if len not zero, but pointer is NULL */
    if (NULL == input)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

#if defined(ELE_FEATURE_DIGEST_IMPORT) && defined(CONFIG_ELE_S2XX_ENABLE_HASH_CONTEXT_IMPORT_EXPORT)
    status = ele_s2xx_import_digest_context(operation);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }
#endif

    if (sss_sscp_digest_update(&operation->ctx, (uint8_t *)(uintptr_t)input, input_length) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

#if defined(ELE_FEATURE_DIGEST_EXPORT) && defined(CONFIG_ELE_S2XX_ENABLE_HASH_CONTEXT_IMPORT_EXPORT)
    status = ele_s2xx_export_digest_context(operation);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }
#endif

exit:
    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_s2xx_transparent_hash_finish(ele_s2xx_hash_operation_t *operation,
                                              uint8_t *hash,
                                              size_t hash_size,
                                              size_t *hash_length)
{
    psa_status_t status = PSA_SUCCESS;

    if (operation == NULL)
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    /* Check if hash_size is sufficient or not */
    if (NULL == hash || hash_size < operation->ctx.digestFullLen)
    {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

#if defined(ELE_FEATURE_DIGEST_IMPORT) && defined(CONFIG_ELE_S2XX_ENABLE_HASH_CONTEXT_IMPORT_EXPORT)
    status = ele_s2xx_import_digest_context(operation);
    if (PSA_SUCCESS != status)
    {
        goto exit;
    }
#endif

    if (sss_sscp_digest_finish(&operation->ctx, hash, &hash_size) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    *hash_length = operation->ctx.digestFullLen;

exit:
    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t ele_s2xx_transparent_hash_abort(ele_s2xx_hash_operation_t *operation)
{
    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    (void)sss_sscp_digest_context_free(&operation->ctx);

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Zeroize the context */
    (void)memset(operation, 0, sizeof(ele_s2xx_hash_operation_t));

    return PSA_SUCCESS;
}

psa_status_t ele_s2xx_transparent_hash_compute(psa_algorithm_t alg,
                                               const uint8_t *input,
                                               size_t input_length,
                                               uint8_t *hash,
                                               size_t hash_size,
                                               size_t *hash_length)
{
    psa_status_t status       = PSA_ERROR_CORRUPTION_DETECTED;
    size_t actual_hash_length = PSA_HASH_LENGTH(alg);
    sss_sscp_digest_t ctx     = {0};
    sss_algorithm_t mode      = {0};

    if ((status = translate_psa_hash_to_ele_hash(alg, &mode)) != PSA_SUCCESS)
    {
        return status;
    }

    if (NULL == hash || 0u == hash_size)
    {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    /* Fill the output buffer with something that isn't a valid hash
     * (barring an attack on the hash and deliberately-crafted input),
     * in case the caller doesn't check the return status properly.
     */
    (void)memset(hash, (int)'!', hash_size);

    if (hash_size < actual_hash_length)
    {
        return PSA_ERROR_BUFFER_TOO_SMALL;
    }

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (sss_sscp_digest_context_init(&ctx, &g_ele_ctx.sssSession, mode, kMode_SSS_Digest) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    *hash_length = ctx.digestFullLen;

    if (sss_sscp_digest_one_go(&ctx, input, input_length, hash, hash_length) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

    if (sss_sscp_digest_context_free(&ctx) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_GENERIC_ERROR;
        goto exit;
    }

exit:
    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}
/** @} */ // end of psa_hash
