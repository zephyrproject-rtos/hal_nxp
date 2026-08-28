/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "mcux_psa_sgi_init.h" /* ELE Crypto port layer */

psa_status_t psa_sgi_transparent_init(void)
{
    return CRYPTO_InitHardware();
}

psa_status_t psa_sgi_transparent_free(void)
{

    return CRYPTO_DeinitHardware();
}
