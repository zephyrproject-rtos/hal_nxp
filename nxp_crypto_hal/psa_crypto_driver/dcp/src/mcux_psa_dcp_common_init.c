/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "mcux_psa_dcp_init.h"
#include "mcux_psa_dcp_common_init.h"
#include "mcux_psa_dcp_entropy.h"

mcux_mutex_t rng_hwcrypto_mutex;

psa_status_t dcp_common_init(void)
{
    psa_status_t status;

    /* Init DCP peripheral */
    status_t dcp_status = CRYPTO_InitHardware();
    status = dcp_to_psa_status(dcp_status);

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
    status = mcux_psa_dcp_entropy_init(&rng_hwcrypto_mutex);

    if (mcux_mutex_unlock(&rng_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    return status;
}

psa_status_t dcp_common_free(void)
{
    psa_status_t status;

    /* Deinit DCP peripheral */
    status_t dcp_status = CRYPTO_DeinitHardware();
    status = dcp_to_psa_status(dcp_status);

    if (mcux_mutex_lock(&rng_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    /* Deinit RNG peripheral */
    mcux_psa_dcp_entropy_deinit();

    if (mcux_mutex_unlock(&rng_hwcrypto_mutex) != 0) {
        return PSA_ERROR_SERVICE_FAILURE;
    }

    (void)mcux_mutex_free(&rng_hwcrypto_mutex);

    return status;
}
