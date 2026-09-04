/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "mcux_psa_hashcrypt_init.h"
#include "mcux_psa_hashcrypt_common_init.h"
#include "mcux_psa_hashcrypt_entropy.h"

mcux_mutex_t rng_hwcrypto_mutex;

psa_status_t hashcrypt_common_init(void)
{
    psa_status_t status;
    status_t hashcrypt_status = CRYPTO_InitHardware_Hashcrypt();
    status = hashcrypt_to_psa_status(hashcrypt_status);

    if (status != PSA_SUCCESS) {
        return status;
    }

    if (mcux_mutex_init(&rng_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    if (mcux_mutex_lock(&rng_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Init RNG peripheral */
    status = mcux_psa_hashcrypt_entropy_init(&rng_hwcrypto_mutex);

    if (mcux_mutex_unlock(&rng_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t hashcrypt_common_free(void)
{
    status_t hashcrypt_status = CRYPTO_DeinitHardware_Hashcrypt();

    if (mcux_mutex_lock(&rng_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Deinit RNG peripheral */
    mcux_psa_hashcrypt_entropy_deinit();

    if (mcux_mutex_unlock(&rng_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    (void)mcux_mutex_free(&rng_hwcrypto_mutex);

    return hashcrypt_to_psa_status(hashcrypt_status);
}
