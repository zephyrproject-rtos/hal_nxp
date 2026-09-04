/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_ele_hseb_init.c
 *
 * This file contains the implementation of the entry points associated to
 * driver initialisation and de-initialisation procedures.
 *
 */

#include "psa/crypto.h"
#include "mcux_psa_ele_hseb_init.h"

psa_status_t ele_hseb_transparent_init(void)
{
    status_t status = CRYPTO_InitHardware();

    return status == kStatus_Success ? PSA_SUCCESS : PSA_ERROR_GENERIC_ERROR;
}

psa_status_t ele_hseb_transparent_free(void)
{
    status_t status = CRYPTO_DeinitHardware();

    return status == kStatus_Success ? PSA_SUCCESS : PSA_ERROR_GENERIC_ERROR;
}
