/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "mcux_psa_hashcrypt_init.h" /* HASHCRYPT Crypto port layer */


/******************************************************************************/
/*************************** Mutex ********************************************/
/******************************************************************************/
/*
 * Define global mutexes for HW accelerator
 */
mcux_mutex_t hashcrypt_hwcrypto_mutex;

/******************************************************************************/
/******************** CRYPTO_InitHardware *************************************/
/******************************************************************************/


bool g_isHashcryptHWInitialized = false;

psa_status_t hashcrypt_to_psa_status(status_t hashcrypt_status)
{
    psa_status_t status = PSA_ERROR_HARDWARE_FAILURE;
    switch (hashcrypt_status) {
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
 * @brief Application init for the Hashcrypt crypto block.
 *
 * This function is provided to be called by MCUXpresso SDK applications.
 * It calls basic init for Crypto Hw acceleration and Hw entropy modules.
 */
status_t CRYPTO_InitHardware_Hashcrypt(void)
{
    status_t result          = kStatus_Fail;

    if (g_isHashcryptHWInitialized == true) {
        return kStatus_Success;
    }

    /* Mutex for access to hashcrypt_crypto HW */
    if (mcux_mutex_init(&hashcrypt_hwcrypto_mutex) != 0) {
        return kStatus_Fail;
    }

    if ((result = mcux_mutex_lock(&hashcrypt_hwcrypto_mutex)) != 0) {
        return kStatus_Fail;
    }

    HASHCRYPT_Init(PSA_HASHCRYPT);
    result = kStatus_Success;

    if (result == kStatus_Success) {
        g_isHashcryptHWInitialized = true;
    }

    if (mcux_mutex_unlock(&hashcrypt_hwcrypto_mutex) != 0) {
        return kStatus_Fail;
    }

    return result;
}

/*!
 * @brief Application Deinit the Hashcrypt crypto block.
 *
 * This function is provided to be called by MCUXpresso SDK applications.
 * It calls basic deinit for Crypto Hw acceleration and Hw entropy modules.
 */
status_t CRYPTO_DeinitHardware_Hashcrypt(void)
{
    status_t result = kStatus_Fail;

    if (g_isHashcryptHWInitialized == false) {
        return kStatus_Success;
    }

    if (mcux_mutex_lock(&hashcrypt_hwcrypto_mutex) != 0) {
        return kStatus_Fail;
    }

    HASHCRYPT_Deinit(PSA_HASHCRYPT);
    result = kStatus_Success;

    if (result == kStatus_Success) {
        g_isHashcryptHWInitialized = false;
    }

    if (mcux_mutex_unlock(&hashcrypt_hwcrypto_mutex) != 0) {
        return kStatus_Fail;
    }

    if (result == kStatus_Success) {
        (void)mcux_mutex_free(&hashcrypt_hwcrypto_mutex);
    }

    return result;
}
