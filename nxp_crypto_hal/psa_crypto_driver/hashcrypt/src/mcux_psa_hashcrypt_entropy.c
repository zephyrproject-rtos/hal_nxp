/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_hashcrypt_entropy.c
 *
 * This file contains the implementation of the entry points associated
 * to the entropy capability as described by the PSA Cryptoprocessor
 * Driver interface specification
 *
 */

#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif

#include "mcux_psa_hashcrypt_entropy.h"

#if defined(CONFIG_USING_TF_PSA_CRYPTO) && (CONFIG_USING_TF_PSA_CRYPTO > 0)
#include "crypto_driver_random.h"
#endif /* defined(USING_TF_PSA_CRYPTO) && (USING_TF_PSA_CRYPTO > 0) */

static mcux_mutex_t *s_mutex = NULL;

/* Zephyr doesn't have adapter_rng in HAL, and doesnt't need it. So using TRNG directly */
#if defined(__ZEPHYR__)
#include "fsl_trng.h"
psa_status_t mcux_psa_hashcrypt_entropy_init(mcux_mutex_t *mutex)
{

    trng_config_t config;

    (void)TRNG_GetDefaultConfig(&config);
    config.sampleMode = kTRNG_SampleModeVonNeumann;

    if (kStatus_Success != TRNG_Init(TRNG, (void *)&config))
    {
        return PSA_ERROR_HARDWARE_FAILURE;
    }

    s_mutex = mutex;

    return PSA_SUCCESS;
}

void mcux_psa_hashcrypt_entropy_deinit(void)
{
    TRNG_Deinit(TRNG);

    s_mutex = NULL;
}

/** \defgroup psa_entropy PSA driver entry points for entropy collection
 *
 *  Entry points for entropy collection from the TRNG source as described by the
 *  PSA Cryptoprocessor Driver interface specification. The TRNG
 *  operates by sampling the output of a fast free-running ring oscillator in a
 *  different (slower) clock domain
 *
 *  @{
 */
psa_status_t mcux_psa_hashcrypt_entropy_get(uint32_t flags,
                                         size_t *estimate_bits,
                                         uint8_t *output,
                                         size_t output_size)
{
    (void)flags; /* Unused */

    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    if ((NULL == output) || (NULL == estimate_bits) || (0u == output_size))
    {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    *estimate_bits = 0u;

    if (mcux_mutex_lock(s_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (kStatus_Success != TRNG_GetRandomData(TRNG, output, output_size))
    {
        status = PSA_ERROR_HARDWARE_FAILURE;
    }
    else
    {
        status = PSA_SUCCESS;
    }

    if (mcux_mutex_unlock(s_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (PSA_SUCCESS == status)
    {
        *estimate_bits = output_size * 8u;
    }

    return status;
}
#else
#include "fsl_adapter_rng.h"
psa_status_t hal_rng_to_psa_status(hal_rng_status_t status)
{
    psa_status_t res;

    switch (status) {
        case kStatus_HAL_RngSuccess:
            res = PSA_SUCCESS;
            break;
        case kStatus_HAL_RngInvalidArgumen:
            res = PSA_ERROR_INVALID_ARGUMENT;
            break;
        default:
            res = PSA_ERROR_HARDWARE_FAILURE;
            break;
    }

    return res;
}

psa_status_t mcux_psa_hashcrypt_entropy_init(mcux_mutex_t *mutex)
{

    hal_rng_status_t status = HAL_RngInit();

    if ((status == kStatus_HAL_RngSuccess) || (status == KStatus_HAL_RngNotSupport))
    {
        s_mutex = mutex;

        return PSA_SUCCESS;
    }

    return hal_rng_to_psa_status(status);
}

void mcux_psa_hashcrypt_entropy_deinit(void)
{
    HAL_RngDeinit();

    s_mutex = NULL;
}

/** \defgroup psa_entropy PSA driver entry points for entropy collection
 *
 *  Entry points for entropy collection from the TRNG source as described by the
 *  PSA Cryptoprocessor Driver interface specification. The TRNG
 *  operates by sampling the output of a fast free-running ring oscillator in a
 *  different (slower) clock domain
 *
 *  @{
 */
psa_status_t mcux_psa_hashcrypt_entropy_get(uint32_t flags,
                                         size_t *estimate_bits,
                                         uint8_t *output,
                                         size_t output_size)
{
    status_t result   = kStatus_Success;
    psa_status_t err  = PSA_ERROR_CORRUPTION_DETECTED;

    if (output == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (estimate_bits == NULL) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    *estimate_bits = 0u;

    if (output_size == 0u) {
        return PSA_ERROR_INVALID_ARGUMENT;
    }

    if (mcux_mutex_lock(s_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    result = HAL_RngHwGetData((uint8_t *) output, output_size);
    if (result == KStatus_HAL_RngNotSupport)
    {
        result = HAL_RngGetData((uint8_t *) output, output_size);
    }
    err = hal_rng_to_psa_status((hal_rng_status_t) result);

    if (mcux_mutex_unlock(s_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (err == PSA_SUCCESS) {
        *estimate_bits = output_size * 8u;
    }

    return err;
}

#endif /* __ZEPHYR__ */

/** @} */ // end of psa_entropy

#if defined(CONFIG_USING_TF_PSA_CRYPTO) && (CONFIG_USING_TF_PSA_CRYPTO > 0)
int mbedtls_platform_get_entropy(psa_driver_get_entropy_flags_t flags,
                                 size_t *estimate_bits,
                                 unsigned char *output, size_t output_size)
{
    return mcux_psa_hashcrypt_entropy_get(flags, estimate_bits, output, output_size);
}
#endif /* defined(CONFIG_USING_TF_PSA_CRYPTO) && (CONFIG_USING_TF_PSA_CRYPTO > 0) */

/*
 * Keep mbedtls_hardware_poll() for backward compatibility
 */
int mbedtls_hardware_poll(void *data, unsigned char *output, size_t len, size_t *olen)
{
    size_t estimate_bits  = 0u;
    psa_status_t status = mcux_psa_hashcrypt_entropy_get(0u, &estimate_bits, output, len);

    *olen = estimate_bits / 8u;

    return status;
}
