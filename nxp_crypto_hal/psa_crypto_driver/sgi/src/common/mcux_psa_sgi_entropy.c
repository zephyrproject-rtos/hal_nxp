/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_sgi_entropy.c
 *
 * This file contains the implementation of the entry points associated
 * to the entropy capability as described by the PSA Cryptoprocessor
 * Driver interface specification
 *
 */
#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000)
#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#endif

#include "mbedtls/build_info.h"

#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000)
#include "psa/crypto_driver_random.h"
#endif /* defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000) */

#include "fsl_device_registers.h"

#if defined(MBEDTLS_MCUX_USE_TRNG_AS_ENTROPY_SEED)
#if defined(FSL_FEATURE_SOC_TRNG_COUNT) && (FSL_FEATURE_SOC_TRNG_COUNT > 0)
#include "fsl_trng.h"
#ifndef TRNG0
#define TRNG0 TRNG
#endif /* ifndef TRNG0 */
#endif /* FSL_FEATURE_SOC_TRNG_COUNT */
#else
#include <mcuxClRandom.h>
#include <mcuxClRandomModes.h>
#endif /* MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256 || MBEDTLS_MCUX_USE_TRNG_AS_ENTROPY_SEED */

#include "mcux_psa_sgi_entropy.h"

/** \defgroup psa_entropy PSA driver entry points for entropy collection
 *
 *  Entry points for entropy collection from the TRNG source as described by the
 *  PSA Cryptoprocessor Driver interface specification. The TRNG
 *  operates by sampling the output of a fast free-running ring oscillator in a
 *  different (slower) clock domain
 *
 *  @{
 */
psa_status_t sgi_get_entropy(uint32_t flags,
                             size_t *estimate_bits,
                             uint8_t *output,
                             size_t output_size)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    if ((output == NULL) && (output_size == 0u)) {
        /* Special case when no amount of entropy is requested*/
        return PSA_SUCCESS;
    }

    if (output == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (output_size == 0u) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (estimate_bits == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (mcux_mutex_lock(&sgi_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

#if defined(MBEDTLS_MCUX_USE_TRNG_AS_ENTROPY_SEED)

    /* Get random data from trng driver*/
    if (TRNG_GetRandomData(TRNG0, output, output_size) != kStatus_Success) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }

#else

    /* Initialize session */
    mcuxClSession_Descriptor_t sessionDesc = { 0 };
    mcuxClSession_Handle_t session = &sessionDesc;

    /* Allocate and initialize session */
    MCUXCLEXAMPLE_ALLOCATE_AND_INITIALIZE_SESSION(session,
                                                  MCUXCLEXAMPLE_MAX_WA(
                                                      MCUXCLHASH_MAX_CPU_WA_BUFFER_SIZE,
                                                      MCUXCLRANDOM_NCINIT_WACPU_SIZE),
                                                  0u);

    /* Initialize the PRNG */
    MCUXCLEXAMPLE_INITIALIZE_PRNG(session);


    /**************************************************************************/
    /* Random init                                                            */
    /**************************************************************************/

    /* Initialize the RNG context, with maximum size */
    uint32_t rng_ctx[MCUXCLRANDOMMODES_CTR_DRBG_AES256_CONTEXT_SIZE_IN_WORDS] = { 0u };
    mcuxClRandom_Context_t pRng_ctx = (mcuxClRandom_Context_t) rng_ctx;

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(
        retRandomInit, tokenRandInit,
        mcuxClRandom_init(session, pRng_ctx, mcuxClRandomModes_Mode_CtrDrbg_AES256_DRG3));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_init) != tokenRandInit) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLRANDOM_STATUS_OK != retRandomInit) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /* Initialize the PRNG */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(prngInit_result, prngInit_token, mcuxClRandom_ncInit(session));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_ncInit) != prngInit_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLRANDOM_STATUS_OK != prngInit_result) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    /**************************************************************************/
    /* Generate random values.                                                */
    /**************************************************************************/

    /* Generate random values of smaller amount than one word size. */
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(retRandGen, tokenRandGen, mcuxClRandom_generate(session,
                                                                                     output,
                                                                                     output_size));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_generate) != tokenRandGen) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
        goto cleanup;
    }

    if (MCUXCLRANDOM_STATUS_OK != retRandGen) {
        status = PSA_ERROR_HARDWARE_FAILURE;
        goto cleanup;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

#endif /* MBEDTLS_MCUX_USE_TRNG_AS_ENTROPY_SEED */

    /* Success - set output parameters */
    *estimate_bits = output_size * 8u;
    status = PSA_SUCCESS;

cleanup:
#if !defined(MBEDTLS_MCUX_USE_TRNG_AS_ENTROPY_SEED)
    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(cleanup_result, cleanup_token, mcuxClSession_cleanup(session));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_cleanup) != cleanup_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
    } else if (MCUXCLSESSION_STATUS_OK != cleanup_result) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_GENERIC_ERROR;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();

    MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(destroy_result, destroy_token, mcuxClSession_destroy(session));

    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != destroy_token) {
        status = PSA_ERROR_CORRUPTION_DETECTED;
    } else if (MCUXCLSESSION_STATUS_OK != destroy_result) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_GENERIC_ERROR;
        }
    }
    MCUX_CSSL_FP_FUNCTION_CALL_END();
#endif /* !MBEDTLS_MCUX_USE_TRNG_AS_ENTROPY_SEED */

    /* Always unlock mutex */
    if (mcux_mutex_unlock(&sgi_hwcrypto_mutex) != 0) {
        if (status == PSA_SUCCESS) {
            status = PSA_ERROR_SERVICE_FAILURE;
        }
    }

    return status;
}

/*
 * FixMe: This function is required to integrate into Mbed TLS as the PSA
 * subsystem does not yet support entropy entry points. See the header
 * entropy_poll.h for details. This needs to be revised once Mbed TLS adds
 * support for entropy.
 */

#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000)  && \
    !defined(__ZEPHYR__)

int mbedtls_platform_get_entropy(psa_driver_get_entropy_flags_t flags,
                                 size_t *estimate_bits,
                                 unsigned char *output, size_t output_size)
{
    return sgi_get_entropy((uint32_t) flags, estimate_bits, output, output_size);
}
#endif /* defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000) */

int mbedtls_hardware_poll(void *data, unsigned char *output, size_t len, size_t *olen)
{
    size_t estimate_bits = 0u;
    int status           = sgi_get_entropy(0u, &estimate_bits, output, len);

    *olen = estimate_bits / 8u;

    return status;
}

#if defined(MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG)  && !defined(__ZEPHYR__)
#if !defined(CONFIG_PSA_NO_EXTERNAL_RNG_IN_DRIVER)
psa_status_t mbedtls_psa_external_get_random(mbedtls_psa_external_random_context_t *context,
                                             uint8_t *output,
                                             size_t output_size,
                                             size_t *output_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    size_t estimate_bits = 0u;

    (void) context;

    status = sgi_get_entropy(0u, &estimate_bits, output, output_size);
    if (PSA_SUCCESS == status) {
        *output_length = output_size;
    }

    return status;
}
#endif /* CONFIG_PSA_SGI_CRYPTO_EXTERNAL_RNG */
#endif /* MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG */
/** @} */ // end of psa_entropy
