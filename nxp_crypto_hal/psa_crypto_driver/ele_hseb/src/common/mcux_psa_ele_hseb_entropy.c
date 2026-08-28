/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_ele_hseb_entropy.c
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

#include "mcux_psa_ele_hseb_translate.h"
#include "mcux_psa_ele_hseb_entropy.h"
#include "hse_host_rng.h"

/** \defgroup psa_entropy PSA driver entry points for entropy collection
 *
 *  Entry points for entropy collection from the TRNG source as described by the
 *  PSA Cryptoprocessor Driver interface specification.
 *
 *  @{
 */
psa_status_t ele_hseb_get_entropy(uint32_t flags,
                                  size_t *estimate_bits,
                                  uint8_t *output,
                                  size_t output_size)
{
    hseSrvResponse_t hseb_status = HSE_SRV_RSP_GENERAL_ERROR;
    psa_status_t status          = PSA_ERROR_CORRUPTION_DETECTED;

    if ((NULL == output) || (NULL == estimate_bits) || (0u == output_size)) {
        status = PSA_ERROR_INVALID_ARGUMENT;
        goto exit;
    }

    if (mcux_mutex_lock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* We use the highest quality, but slow, RNG for gathering entropy */
    hseb_status = GetRngNum(output, output_size, HSE_RNG_CLASS_PTG3);

    if (mcux_mutex_unlock(&ele_hseb_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    status = ele_hseb_to_psa_status(hseb_status);

    if (PSA_SUCCESS == status) {
        *estimate_bits = output_size * 8u;
    }

exit:
    return status;
}
/** @} */ // end of psa_entropy

#if defined(MBEDTLS_VERSION_NUMBER) && (MBEDTLS_VERSION_NUMBER >= 0x04000000)
int mbedtls_platform_get_entropy(psa_driver_get_entropy_flags_t flags,
                                 size_t *estimate_bits,
                                 unsigned char *output, size_t output_size)
{
    return ele_hseb_get_entropy((uint32_t)flags, estimate_bits, output, output_size);
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
    (void) data; /* Unused */

    size_t estimate_bits = 0u;
    int status           = ele_hseb_get_entropy(0u, &estimate_bits, output, len);

    *olen = estimate_bits / 8u;

    return status;
}

#if defined(MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG)
psa_status_t mbedtls_psa_external_get_random(mbedtls_psa_external_random_context_t *context,
                                             uint8_t *output,
                                             size_t output_size,
                                             size_t *output_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    size_t estimate_bits = 0u;

    status = ele_hseb_get_entropy(0u, &estimate_bits, output, output_size);
    if (PSA_SUCCESS == status) {
        *output_length = output_size;
    }

    return status;
}
#endif /* MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG */
