/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_casper.h"
#include "mcux_psa_casper_init.h" /* CASPER Crypto port layer */

/******************************************************************************/
/*************************** Mutex ********************************************/
/******************************************************************************/
/*
 * Define global mutexes for HW accelerator
 */
mcux_mutex_t casper_hwcrypto_mutex;

/******************************************************************************/
/******************** CRYPTO_InitHardware *************************************/
/******************************************************************************/

bool g_isCasperHWInitialized = false;

psa_status_t casper_to_psa_status(status_t casper_status)
{
    psa_status_t status = PSA_ERROR_HARDWARE_FAILURE;
    switch (casper_status) {
        case kStatus_InvalidArgument:
            status = PSA_ERROR_INVALID_ARGUMENT;
            break;
        case kStatus_Success:
            status = PSA_SUCCESS;
            break;
        case kStatus_Fail:
            status = PSA_ERROR_HARDWARE_FAILURE;
            break;
        default:
            status = PSA_ERROR_HARDWARE_FAILURE;
            break;
    }

    return status;
}

/*!
 * @brief Application init for the CASPER crypto block.
 *
 * This function is provided to be called by MCUXpresso SDK applications.
 * It calls basic init for Crypto Hw acceleration and Hw entropy modules.
 */
status_t CRYPTO_InitHardware_Casper(void)
{
    status_t result = kStatus_Fail;

    if (g_isCasperHWInitialized == true) {
        return kStatus_Success;
    }

    /* Mutex for access to casper_crypto HW */
    if (mcux_mutex_init(&casper_hwcrypto_mutex) != 0) {
        return kStatus_Fail;
    }

    if ((result = mcux_mutex_lock(&casper_hwcrypto_mutex)) != 0) {
        return kStatus_Fail;
    }

    CASPER_Init(PSA_CASPER);
    result = kStatus_Success;

    if (result == kStatus_Success) {
        g_isCasperHWInitialized = true;
    }

    if (mcux_mutex_unlock(&casper_hwcrypto_mutex) != 0) {
        return kStatus_Fail;
    }

    return result;
}

/*!
 * @brief Application Deinit for the CASPER crypto block.
 *
 * This function is provided to be called by MCUXpresso SDK applications.
 * It calls basic deinit for Crypto Hw acceleration and Hw entropy modules.
 */
status_t CRYPTO_DeinitHardware_Casper(void)
{
    status_t result = kStatus_Fail;

    if (g_isCasperHWInitialized == false) {
        return kStatus_Success;
    }

    if (mcux_mutex_lock(&casper_hwcrypto_mutex) != 0) {
        return kStatus_Fail;
    }

    CASPER_Deinit(PSA_CASPER);
    result = kStatus_Success;

    if (result == kStatus_Success) {
        g_isCasperHWInitialized = false;
    }

    if (mcux_mutex_unlock(&casper_hwcrypto_mutex) != 0) {
        return kStatus_Fail;
    }

    if (result == kStatus_Success) {
        (void)mcux_mutex_free(&casper_hwcrypto_mutex);
    }

    return result;
}
