/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "mcux_psa_dcp_init.h" /* DCP Crypto port layer */

/******************************************************************************/
/*************************** Mutex ********************************************/
/******************************************************************************/
/*
 * Define global mutexes for HW accelerator
 */
mcux_mutex_t dcp_hwcrypto_mutex;

/******************************************************************************/
/******************** CRYPTO_InitHardware *************************************/
/******************************************************************************/

uint32_t g_isCryptoHWInitialized = false;

psa_status_t dcp_to_psa_status(status_t dcp_status)
{
    psa_status_t status = PSA_ERROR_HARDWARE_FAILURE;
    switch (dcp_status) {
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
 * @brief Application init for Crypto blocks.
 *
 * This function is provided to be called by MCUXpresso SDK applications.
 * It calls basic init for Crypto Hw acceleration and Hw entropy modules.
 */
status_t CRYPTO_InitHardware(void)
{
    status_t result = kStatus_Fail;

    if (g_isCryptoHWInitialized == true) {
        return kStatus_Success;
    }

    /* Mutex for access to DCP HW */
    if (mcux_mutex_init(&dcp_hwcrypto_mutex)) {
        return kStatus_Fail;
    }

    if ((result = mcux_mutex_lock(&dcp_hwcrypto_mutex)) != 0) {
        return kStatus_Fail;
    }

    /* Get default DCP config */
    dcp_config_t dcpConfig;
    DCP_GetDefaultConfig(&dcpConfig);

    /* Reset and initialize DCP */
    DCP_Init(PSA_DCP, &dcpConfig);

    result                  = kStatus_Success;
    g_isCryptoHWInitialized = true;

    if (mcux_mutex_unlock(&dcp_hwcrypto_mutex)) {
        return kStatus_Fail;
    }

    return result;
}

/*!
 * @brief Application Deinit for Crypto blocks.
 *
 * This function is provided to be called by MCUXpresso SDK applications.
 * It calls basic deinit for Crypto Hw acceleration and Hw entropy modules.
 */
status_t CRYPTO_DeinitHardware(void)
{
    status_t result = kStatus_Fail;

    if (g_isCryptoHWInitialized == false) {
        return kStatus_Success;
    }

    if (mcux_mutex_lock(&dcp_hwcrypto_mutex)) {
        return kStatus_Fail;
    }

    /* Deinitialize DCP peripheral */
    DCP_Deinit(PSA_DCP);
    result = kStatus_Success;

    if (result == kStatus_Success) {
        g_isCryptoHWInitialized = false;
    }

    if (mcux_mutex_unlock(&dcp_hwcrypto_mutex)) {
        return kStatus_Fail;
    }

    if (result == kStatus_Success) {
        mcux_mutex_free(&dcp_hwcrypto_mutex);
    }

    return result;
}
