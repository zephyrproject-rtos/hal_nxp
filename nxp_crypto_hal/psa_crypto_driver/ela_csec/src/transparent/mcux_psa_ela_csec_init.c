/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file mcux_psa_ela_csec_init.c
 *
 * This file contains the implementation of the entry points associated to
 * driver initialisation and de-initialisation procedures.
 *
 */

#include "psa/crypto.h"
#include "mcux_psa_ela_csec_init.h"

psa_status_t ela_csec_to_psa_status(status_t csec_status)
{
    psa_status_t psa_status = PSA_ERROR_HARDWARE_FAILURE;

    switch (csec_status)
    {
        case kStatus_SEC_RNG_SEED:
            /* Returned by CMD_RND if the seed has not been initialized */
            psa_status = PSA_ERROR_BAD_STATE;
            break;
        case kStatus_InvalidArgument:
            psa_status = PSA_ERROR_INVALID_ARGUMENT;
            break;
        case kStatus_Success:
            psa_status = PSA_SUCCESS;
            break;
        case kStatus_Fail:
            psa_status = PSA_ERROR_HARDWARE_FAILURE;
            break;
        default:
            psa_status = PSA_ERROR_HARDWARE_FAILURE;
            break;
    }

    return psa_status;
}

psa_status_t ela_csec_transparent_init(void)
{
    status_t status = CRYPTO_InitHardware();

    return ela_csec_to_psa_status(status);
}

psa_status_t ela_csec_transparent_free(void)
{
    status_t status = CRYPTO_DeinitHardware();

    return ela_csec_to_psa_status(status);
}
