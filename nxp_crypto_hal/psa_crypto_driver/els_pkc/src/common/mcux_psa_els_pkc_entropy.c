/*
 * Copyright 2023-2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_els_pkc_entropy.c
 *
 * This file contains the implementation of the entry points associated
 * to the entropy capability as described by the PSA Cryptoprocessor
 * Driver interface specification
 *
 */

#include "mbedtls/build_info.h"
//#include "entropy_poll.h"

/* mbedTLS 4.x: include the driver random header for psa_driver_get_entropy_flags_t */
#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000)
#include "psa/crypto_driver_random.h"
#endif

#include "mcux_psa_els_pkc_entropy.h"

/* Standalone TRNG can be used if its configured to be used via cmake,
   otherwise Use 256bit RNG3 random mode if available, or else fallback to low entropy PRNG(default enabled) */
#if defined(MBEDTLS_MCUX_USE_TRNG_AS_ENTROPY_SEED)
#if defined(FSL_FEATURE_SOC_TRNG_COUNT) && (FSL_FEATURE_SOC_TRNG_COUNT > 0)
#include "fsl_trng.h"
#ifndef TRNG0
#define TRNG0 TRNG
#endif /* ifndef TRNG0 */
#endif /* FSL_FEATURE_SOC_TRNG_COUNT */
#elif defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256) && (MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256 > 0u)
#include <mcuxClRandom.h>
#include <mcuxClRandomModes.h>
#endif /* MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256 || MBEDTLS_MCUX_USE_TRNG_AS_ENTROPY_SEED */


/** \defgroup psa_entropy PSA driver entry points for entropy collection
 *
 *  Entry points for entropy collection from the TRNG source as described by the
 *  PSA Cryptoprocessor Driver interface specification. The TRNG
 *  operates by sampling the output of a fast free-running ring oscillator in a
 *  different (slower) clock domain
 *
 *  @{
 */
psa_status_t els_pkc_get_entropy(uint32_t flags, size_t *estimate_bits, uint8_t *output, size_t output_size)
{
    status_t result     = kStatus_Success;
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    if (output == NULL || estimate_bits == NULL || output_size == 0u)
    {
        status = PSA_ERROR_INVALID_ARGUMENT;
    }
    else
    {
#if defined(PSA_CRYPTO_DRIVER_THREAD_EN)
        if (mcux_mutex_lock(&els_pkc_hwcrypto_mutex) != 0)
        {
            status = PSA_ERROR_SERVICE_FAILURE;
        }
        else
        {
#endif /* defined(PSA_CRYPTO_DRIVER_THREAD_EN) */

#if defined(MBEDTLS_MCUX_USE_TRNG_AS_ENTROPY_SEED)
            /* Get random data from trng driver*/
            result = TRNG_GetRandomData(TRNG0, output, output_size);
#elif defined(MCUXCL_FEATURE_RANDOMMODES_SECSTRENGTH_256)
            mcuxClSession_Descriptor_t session;

            /* Allocate workarea space */
            uint32_t cpuWorkarea[MCUXCLRANDOMMODES_MAX_CPU_WA_BUFFER_SIZE / sizeof(uint32_t)];

            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(retSessionInit, tokenSessionInit, mcuxClSession_init(&session,
                                                                             cpuWorkarea,
                                                                             MCUXCLRANDOMMODES_MAX_CPU_WA_BUFFER_SIZE,
                                                                             NULL,
                                                                             0u));

            if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_init) != tokenSessionInit) || (MCUXCLSESSION_STATUS_OK != retSessionInit))
            {
                return PSA_ERROR_GENERIC_ERROR;
            }

            MCUX_CSSL_FP_FUNCTION_CALL_END();

            /**************************************************************************/
            /* Random init                                                            */
            /**************************************************************************/

            /* Initialize the RNG context, with maximum size */
            uint32_t rng_ctx[MCUXCLRANDOMMODES_CTR_DRBG_AES256_CONTEXT_SIZE_IN_WORDS] = {0u};

            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(retRandomInit, tokenRandInit, mcuxClRandom_init(
                                                          &session,
                                                          (mcuxClRandom_Context_t)rng_ctx,
                                                          mcuxClRandomModes_Mode_CtrDrbg_AES256_DRG3));
            if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_init) != tokenRandInit) || (MCUXCLRANDOM_STATUS_OK != retRandomInit))
            {
                return PSA_ERROR_GENERIC_ERROR;
            }

            MCUX_CSSL_FP_FUNCTION_CALL_END();

            /**************************************************************************/
            /* Generate random values.                                                */
            /**************************************************************************/

            /* Generate random values of smaller amount than one word size. */
            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(retRandGen, tokenRandGen, mcuxClRandom_generate(
                                                          &session,
                                                          output,
                                                          output_size));
            if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClRandom_generate) != tokenRandGen) || (MCUXCLRANDOM_STATUS_OK != retRandGen))
            {
                return PSA_ERROR_GENERIC_ERROR;
            }

            MCUX_CSSL_FP_FUNCTION_CALL_END();

            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(cleanup_result, cleanup_token, mcuxClSession_cleanup(&session));
            if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_cleanup) != cleanup_token) || (MCUXCLSESSION_STATUS_OK != cleanup_result))
            {
                return PSA_ERROR_GENERIC_ERROR;
            }
            MCUX_CSSL_FP_FUNCTION_CALL_END();

            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(destroy_result, destroy_token, mcuxClSession_destroy(&session));
            if((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSession_destroy) != destroy_token) || (MCUXCLSESSION_STATUS_OK != destroy_result))
            {
                return PSA_ERROR_GENERIC_ERROR;
            }
            MCUX_CSSL_FP_FUNCTION_CALL_END();

#else
            /* Call ELS to get random data */
            MCUX_CSSL_FP_FUNCTION_CALL_BEGIN(els_result, token, mcuxClEls_Prng_GetRandom(output, output_size));
            if ((MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClEls_Prng_GetRandom) != token) || (MCUXCLELS_STATUS_OK != els_result))
            {
                result = kStatus_Fail;
            }
            MCUX_CSSL_FP_FUNCTION_CALL_END();
#endif
            if (result == kStatus_Success)
            {
                *estimate_bits = output_size;
                status         = PSA_SUCCESS;
            }
            else
            {
                status = PSA_ERROR_GENERIC_ERROR;
            }

#if defined(PSA_CRYPTO_DRIVER_THREAD_EN)
        }
        if (mcux_mutex_unlock(&els_pkc_hwcrypto_mutex) != 0)
        {
            status = PSA_ERROR_SERVICE_FAILURE;
        }
#endif
    }
    if (status == PSA_SUCCESS)
    {
        *estimate_bits = output_size * 8u;
    }
    return status;
}
/** @} */ // end of psa_entropy

/*
 * mbedTLS 4.x entropy callback required when MBEDTLS_PSA_DRIVER_GET_ENTROPY is enabled.
 */
#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000) && !defined(__ZEPHYR__)
int mbedtls_platform_get_entropy(psa_driver_get_entropy_flags_t flags,
                                 size_t *estimate_bits,
                                 unsigned char *output, size_t output_size)
{
    return els_pkc_get_entropy((uint32_t) flags, estimate_bits, output, output_size);
}
#endif /* defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000) */

/*
 * FixMe: This function is required to integrate into Mbed TLS as the PSA
 * subsystem does not yet support entropy entry points. See the header
 * entropy_poll.h for details. This needs to be revised once Mbed TLS adds
 * support for entropy.
 */
int mbedtls_hardware_poll(void *data, unsigned char *output, size_t len, size_t *olen)
{
    size_t estimate_bits = 0u;
    int status = els_pkc_get_entropy(0u, &estimate_bits, output, len);

    *olen = estimate_bits / 8u;

    return status;
}
