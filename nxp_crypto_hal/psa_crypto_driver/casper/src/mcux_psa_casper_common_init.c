/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "mcux_psa_casper_init.h"
#include "mcux_psa_casper_common_init.h"

psa_status_t casper_common_init(void)
{
    status_t casper_status = CRYPTO_InitHardware_Casper();

    return casper_to_psa_status(casper_status);
}

psa_status_t casper_common_free(void)
{
    status_t casper_status = CRYPTO_DeinitHardware_Casper();

    return casper_to_psa_status(casper_status);
}
