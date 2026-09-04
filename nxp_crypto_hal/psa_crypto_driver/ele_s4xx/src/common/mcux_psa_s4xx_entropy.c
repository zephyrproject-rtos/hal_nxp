/*
 * Copyright 2023, 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_s4xx_entropy.c
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

#include "mbedtls/build_info.h"
#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000)
#include "psa/crypto_driver_random.h"
#endif /* defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000) */

#include "ele_crypto.h"
#include "mcux_psa_s4xx_entropy.h"

/** \defgroup psa_entropy PSA driver entry points for entropy collection
 *
 *  Entry points for entropy collection from the TRNG source as described by the
 *  PSA Cryptoprocessor Driver interface specification. The TRNG
 *  operates by sampling the output of a fast free-running ring oscillator in a
 *  different (slower) clock domain
 *
 *  @{
 */
psa_status_t ele_get_entropy(uint32_t flags, size_t *estimate_bits, uint8_t *output, size_t output_size)
{
    status_t result     = kStatus_Success;
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    uint32_t trng_state = 0u;

    if (output == NULL)
    {
        status = PSA_ERROR_INVALID_ARGUMENT;
        goto end;
    }

    if (estimate_bits == NULL)
    {
        status = PSA_ERROR_INVALID_ARGUMENT;
        goto end;
    }

    if (output_size == 0)
    {
        status = PSA_ERROR_INVALID_ARGUMENT;
        goto end;
    }

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* We need proper RNG init in case of MbedTLS3.x SW-only builds.
     * Otherwise this is done in CRYPTO_InitHardware().
     */
    (void)ELE_GetTrngState(S3MU, &trng_state);
    if (kELE_TRNG_CSAL_success << 8u != trng_state)
    {
        (void)ELE_StartRng(S3MU);
    }

    /* Wait until ready */
    do
    {
        result = ELE_GetTrngState(S3MU, &trng_state);
    } while (!(((trng_state & 0xFFu) == kELE_TRNG_ready) &&
               ((trng_state & 0xFF00u) == kELE_TRNG_CSAL_success << 8u )));

    /* NOTE: If this call fails, then the most likely issue is that there is
     *       no firmware loaded into ELE, since RNG is FW-dependent.
     */
    result = ELE_RngGetRandom(S3MU, (uint32_t *)output, output_size, kNoReseed);
    status = ele_to_psa_status(result);

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (status == PSA_SUCCESS)
    {
        *estimate_bits = output_size * 8;
        status         = PSA_SUCCESS;
    }

end:
    return status;
}
/** @} */ // end of psa_entropy

#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000) && !defined(__ZEPHYR__)
int mbedtls_platform_get_entropy(psa_driver_get_entropy_flags_t flags,
                                 size_t *estimate_bits,
                                 unsigned char *output, size_t output_size)
{
    return ele_get_entropy((uint32_t)flags, estimate_bits, output, output_size);
}
#endif /* defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000) */

/*
 * For legacy mbedtls support
 */
int mbedtls_hardware_poll(void *data, unsigned char *output, size_t len, size_t *olen)
{
    size_t estimate_bits = 0;
    int status           = ele_get_entropy(0, &estimate_bits, output, len);

    *olen = estimate_bits / 8;

    return status;
}
