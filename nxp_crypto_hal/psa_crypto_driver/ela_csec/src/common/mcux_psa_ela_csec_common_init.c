/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "mcux_psa_ela_csec_common_init.h"

/******************************************************************************/
/*************************** Mutex ********************************************/
/******************************************************************************/
/*
 * Define global mutexes for HW accelerator
 */
mcux_mutex_t ela_csec_hwcrypto_mutex;

/******************************************************************************/
/******************** CRYPTO_InitHardware *************************************/
/******************************************************************************/

ela_csec_ctx_t g_ela_csec_ctx = {0u}; /* Global context */

bool g_isCryptoHWInitialized = false;

/*!
 * @brief Application init for Crypto blocks.
 *
 * This function is provided to be called by MCUXpresso SDK applications.
 * It calls basic init for Crypto Hw acceleration and Hw entropy modules.
 */
status_t CRYPTO_InitHardware(void)
{
    status_t result = kStatus_Fail;

    if (true == g_isCryptoHWInitialized)
    {
        return kStatus_Success;
    }

    /* Mutex for access to ele_crypto HW */
    if (mcux_mutex_init(&ela_csec_hwcrypto_mutex) != 0)
    {
        return kStatus_Fail;
    }

    if (mcux_mutex_lock(&ela_csec_hwcrypto_mutex) != 0)
    {
        return kStatus_Fail;
    }

    do
    {
        CSEC_DRV_Init(&(g_ela_csec_ctx.state));

        result = CSEC_DRV_InitRNG();
        if(kStatus_Success != result)
        {
            break;
        }

        result = kStatus_Success;
        g_isCryptoHWInitialized = true;
    } while (0);

    if (mcux_mutex_unlock(&ela_csec_hwcrypto_mutex) != 0)
    {
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
    if (false == g_isCryptoHWInitialized)
    {
        return kStatus_Success;
    }

    if (mcux_mutex_lock(&ela_csec_hwcrypto_mutex) != 0)
    {
        return kStatus_Fail;
    }

    CSEC_DRV_Deinit();
    g_isCryptoHWInitialized = false;

    if (mcux_mutex_unlock(&ela_csec_hwcrypto_mutex) != 0)
    {
        return kStatus_Fail;
    }

    (void)mcux_mutex_free(&ela_csec_hwcrypto_mutex);

    return kStatus_Success;
}


/*!
 * @brief Application Reinit for Crypto blocks.
 *
 * This function is provided to be called by MCUXpresso SDK applications.
 * It calls basic reinit for Crypto Hw acceleration and Hw entropy modules.
 */
status_t CRYPTO_ReinitHardware(void)
{
    /* Reset the init state so the hardware will be reinitialized at the next cryptographic HW acceleration operation */
    g_isCryptoHWInitialized = false;

    return kStatus_Success;
}