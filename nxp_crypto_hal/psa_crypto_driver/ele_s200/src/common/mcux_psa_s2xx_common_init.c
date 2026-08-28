/*
 * Copyright 2024-2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "mcux_psa_s2xx_common_init.h" /* ELE Crypto port layer */

#if (defined(ELEMU_HAS_LOADABLE_FW) && ELEMU_HAS_LOADABLE_FW)
#include "ele_200_fw.h"
#endif /* ELEMU_HAS_LOADABLE_FW */

/******************************************************************************/
/*************************** Definitions **************************************/
/******************************************************************************/
/**
 * @brief Default session ID for ELE S2XX
 *
 * Using value of 1 to prevent possible issues with software resets,
 * as value of 0 may only be used _once_ with the OPEN SESSION command.
 */
#define PSA_ELE_S2XX_DEFAULT_SESSION_ID (1u)

/******************************************************************************/
/*************************** Mutex ********************************************/
/******************************************************************************/
/*
 * Define global mutexes for HW accelerator
 */
mcux_mutex_t ele_hwcrypto_mutex;

/******************************************************************************/
/******************** CRYPTO_InitHardware *************************************/
/******************************************************************************/

ele_s2xx_ctx_t g_ele_ctx = {0u}; /* Global context */

static bool g_isCryptoHWInitialized = false;

psa_status_t ele_to_psa_status(status_t ele_status)
{
    psa_status_t status = PSA_ERROR_HARDWARE_FAILURE;
    switch (ele_status)
    {
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

static status_t ele_close_handles(void)
{
    sss_status_t status = kStatus_SSS_Fail;

    do
    {
        /****************** Close RNG Context **********************/
        status = sss_sscp_rng_free(&g_ele_ctx.rngctx);
        if (status != kStatus_SSS_Success)
        {
            break;
        }

        /****************** Close Key Store  ***********************************/
        status = sss_sscp_key_store_free(&g_ele_ctx.keyStore);
        if (status != kStatus_SSS_Success)
        {
            break;
        }

        /****************** Close EdgeLock session ******************/
        status = sss_sscp_close_session(&g_ele_ctx.sssSession);
        if (status != kStatus_SSS_Success)
        {
            break;
        }

        /****************** Close SSCP context ******************/
        sscp_mu_deinit(&g_ele_ctx.sscpContext);

    } while (false);

    return 0;
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

#if defined(ELE200_EXTENDED_FEATURES) && \
    (defined(ELEMU_HAS_LOADABLE_FW) && ELEMU_HAS_LOADABLE_FW)
    /* Firmware is loadable only on A2.1 revision of KW47 and MCXW72. Add check
     * to prevent loading failure on other revisions with an early exit.
     */
    if (false == IS_CHIP_REVISION_A2_1())
    {
        return kStatus_Fail;
    }
#endif

    if (true == g_isCryptoHWInitialized)
    {
        return kStatus_Success;
    }

    /* Mutex for access to ele_crypto HW */
    if (mcux_mutex_init(&ele_hwcrypto_mutex) != 0)
    {
        return kStatus_Fail;
    }

    if ((result = mcux_mutex_lock(&ele_hwcrypto_mutex)) != 0)
    {
        return kStatus_Fail;
    }

    if ((result = CRYPTO_InitHardwareUnsafe()) != kStatus_Success)
    {
        (void)ele_close_handles();
    }

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return kStatus_Fail;
    }

    return result;
}


/*!
 * @brief Application init for Crypto blocks.
 *
 * Unsafe version of CRYPTO_InitHardware that does not take mutexs.
 *
 * @warning This function does not acquire any mutex locks and is not thread-safe.
 *          If called incorrectly by an application (e.g., from multiple threads
 *          concurrently or without proper external synchronization), this may
 *          cause race conditions, undefined behavior, or hardware access issues.
 *          Use CRYPTO_InitHardware() for thread-safe initialization.
 */
status_t CRYPTO_InitHardwareUnsafe(void)
{
    status_t result     = kStatus_Fail;
    sss_sscp_rng_t rctx = {0u};

    if (true == g_isCryptoHWInitialized)
    {
        return kStatus_Success;
    }

    do
    {
        /****************** Wait for ELE MU is ready ***********************/
        if (kStatus_Success != ELEMU_mu_wait_for_ready(ELEMUA, ELE_MAX_SUBSYSTEM_WAIT))
        {
            result = kStatus_Fail;
            break;
        }

#if (defined(ELEMU_HAS_LOADABLE_FW) && ELEMU_HAS_LOADABLE_FW)
        if (kStatus_Success != ELEMU_loadFw(ELEMUA, (uint32_t *)fw))
        {
            result = kStatus_Fail;
            break;
        }
#endif /* ELEMU_HAS_LOADABLE_FW */

        /****************** Init SSCP service   ***********************/
        if (kStatus_SSCP_Success != sscp_mu_init(&g_ele_ctx.sscpContext, (ELEMU_Type *)(uintptr_t)ELEMUA))
        {
            result = kStatus_Fail;
            break;
        }
        /****************** Open ELE Session  ***********************/
        if (kStatus_SSS_Success != sss_sscp_open_session(&g_ele_ctx.sssSession, PSA_ELE_S2XX_DEFAULT_SESSION_ID, ELE_SUBSYSTEM, &g_ele_ctx.sscpContext))
        {
            result = kStatus_Fail;
            break;
        }

        if (kStatus_SSS_Success != sss_sscp_key_store_init(&g_ele_ctx.keyStore, &g_ele_ctx.sssSession))
        {
            result = kStatus_Fail;
            break;
        }

        /****************** Start RNG ***********************/
        /* RNG call used to init ELE TRNG required e.g. by sss_sscp_key_store_generate_key service
       if TRNG initialization is no needed for used operations, the following code can be removed
       to increase the perfomance.*/
        if (kStatus_SSS_Success != sss_sscp_rng_context_init(&g_ele_ctx.sssSession, &rctx, ELE_HIGH_QUALITY_RNG))
        {
            result = kStatus_Fail;
            break;
        }

        /*Providing NULL output buffer, as we just need to initialize TRNG, not get random data*/
        if (kStatus_SSS_Success != sss_sscp_rng_get_random(&rctx, NULL, 0x0u))
        {
            result = kStatus_Fail;
            break;
        }

        if (kStatus_SSS_Success != sss_sscp_rng_free(&rctx))
        {
            result = kStatus_Fail;
            break;
        }

        result                  = kStatus_Success;
        g_isCryptoHWInitialized = true;
    } while (false);

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

    if (g_isCryptoHWInitialized == false)
    {
        return 0;
    }

    if (mcux_mutex_lock(&ele_hwcrypto_mutex) != 0)
    {
        return kStatus_Fail;
    }

    result = ele_close_handles();
    if (result == kStatus_Success)
    {
        g_isCryptoHWInitialized = false;
    }

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex) != 0)
    {
        return kStatus_Fail;
    }

    if (result == kStatus_Success)
    {
        (void)mcux_mutex_free(&ele_hwcrypto_mutex);
    }

    return result;
}

/*!
 * @brief Application Deinit for Crypto blocks.
 *
 * Unsafe version of CRYPTO_DeinitHardware that does not take mutexs and do not close handles.
 *
 * @warning This function does not acquire any mutex locks and is not thread-safe.
 *          If called incorrectly by an application (e.g., from multiple threads
 *          concurrently or without proper external synchronization), this may
 *          cause race conditions, undefined behavior, or hardware access issues.
 *          Use CRYPTO_InitHardware() for thread-safe initialization.
 */
status_t CRYPTO_DeinitHardwareUnsafe(void)
{
    if (g_isCryptoHWInitialized == false)
    {
        return 0;
    }

    g_isCryptoHWInitialized = false;

    (void)ELEMU_LP_WakeupPathInit(ELEMUA);
    return kStatus_Success;
}

/*!
 * @brief Application reset for Crypto blocks.
 *
 * Wait for the secure subsystem module to be running
 * This function is provided to be called by MCUXpresso SDK applications.
 * It calls basic reinit for Crypto Hw acceleration and Hw entropy modules.
 */
void CRYPTO_ELEMU_reset(void)
{
    (void)CRYPTO_DeinitHardware();
    (void)ELEMU_LP_WakeupPathInit(ELEMUA);
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