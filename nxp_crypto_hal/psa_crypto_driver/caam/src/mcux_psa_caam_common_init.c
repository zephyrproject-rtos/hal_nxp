/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "mcux_psa_caam_init.h"
#include "mcux_psa_caam_common_init.h"

psa_status_t caam_common_init(void)
{
    status_t caam_status = CRYPTO_InitHardware();

    return caam_to_psa_status(caam_status);
}

psa_status_t caam_common_free(void)
{
    status_t caam_status = CRYPTO_DeinitHardware();

    return caam_to_psa_status(caam_status);
}
