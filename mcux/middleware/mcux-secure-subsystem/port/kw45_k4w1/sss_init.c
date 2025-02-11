/*! *********************************************************************************
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * \file
 *
 * SPDX-License-Identifier: BSD-3-Clause
 ********************************************************************************** */

#include "sss_crypto.h"

sss_sscp_key_store_t g_keyStore;
sss_sscp_session_t g_sssSession;
sscp_context_t g_sscpContext;

static uint32_t g_isCryptoHWInitialized = SSS_CRYPTOHW_NONINITIALIZED;

/******************************************************************************/
/*************************** Mutex ********************************************/
/******************************************************************************/
#if defined(MBEDTLS_THREADING_C)

/**
 * \def MBEDTLS_MCUX_FREERTOS_THREADING_ALT
 * You can comment this macro if you provide your own alternate implementation.
 *
 */
#if defined(SDK_OS_FREE_RTOS)
#define MBEDTLS_MCUX_FREERTOS_THREADING_ALT
#endif

#if defined(MBEDTLS_MCUX_FREERTOS_THREADING_ALT)
/**
 * @brief Initializes the mbedTLS mutex functions.
 *
 * Provides mbedTLS access to mutex create, destroy, take and free.
 *
 * @see MBEDTLS_THREADING_ALT
 */
static void CRYPTO_ConfigureThreadingMcux(void);
#endif /* defined(MBEDTLS_MCUX_FREERTOS_THREADING_ALT) */

#endif /* defined(MBEDTLS_THREADING_C) */

/******************************************************************************/
/******************** CRYPTO_InitHardware **************************************/
/******************************************************************************/
/*!
 * @brief Application init for various Crypto blocks.
 *
 * This function is provided to be called by MCUXpresso SDK applications.
 * It calls basic init for Crypto Hw acceleration and Hw entropy modules.
 */
status_t CRYPTO_InitHardware(void)
{
#if defined(MBEDTLS_NXP_SSSAPI)
#if defined(MBEDTLS_THREADING_C) && defined(MBEDTLS_THREADING_ALT)
    CRYPTO_ConfigureThreadingMcux();
#endif /* (MBEDTLS_THREADING_C) && defined(MBEDTLS_THREADING_ALT) */
#endif
    status_t ret;
    do
    {
        if (g_isCryptoHWInitialized == SSS_CRYPTOHW_INITIALIZED)
        {
            ret = kStatus_Success;
            break;
        }
        ret = kStatus_Fail;

        sss_sscp_rng_t rctx;
        if (ELEMU_mu_wait_for_ready(ELEMUA, SSS_MAX_SUBSYTEM_WAIT) != kStatus_Success)
        {
            break;
        }
#if (defined(ELEMU_HAS_LOADABLE_FW) && ELEMU_HAS_LOADABLE_FW)
        if (ELEMU_loadFwLocal(ELEMUA) != kStatus_ELEMU_Success)
        {
            break;
        }
#endif /* ELEMU_HAS_LOADABLE_FW */
        if (sscp_mu_init(&g_sscpContext, (ELEMU_Type *)(uintptr_t)ELEMUA) != kStatus_SSCP_Success)
        {
            break;
        }
        if (sss_sscp_open_session(&g_sssSession, 0u, SSS_SUBSYSTEM, &g_sscpContext) != kStatus_SSS_Success)
        {
            break;
        }
        if (sss_sscp_key_store_init(&g_keyStore, &g_sssSession) != kStatus_SSS_Success)
        {
            break;
        }

        /* RNG call used to init ELE TRNG required e.g. by sss_sscp_key_store_generate_key service
        if TRNG initialization is no needed for used operations, the following code can be removed
        to increase the perfomance.*/
        if (sss_sscp_rng_context_init(&g_sssSession, &rctx, SSS_HIGH_QUALITY_RNG) != kStatus_SSS_Success)
        {
            break;
        }
        /*Providing NULL output buffer, as we just need to initialize TRNG, not get random data*/
        if (sss_sscp_rng_get_random(&rctx, NULL, 0x0u) != kStatus_SSS_Success)
        {
            break;
        }
        if (sss_sscp_rng_free(&rctx) != kStatus_SSS_Success)
        {
            break;
        }
        g_isCryptoHWInitialized = SSS_CRYPTOHW_INITIALIZED;
        ret                     = kStatus_Success;

    } while (false);
    return ret;
}

/*!
 * @brief Application reinit for various Crypto blocks.
 *
 * This function is provided to be called after wake up from low power Power Down
 * or Deep Power Down modes to reinit Crypto HW blocks.
 */
status_t CRYPTO_ReinitHardware(void)
{
    /* Reset the init state so the hardware will be reinitialized at the next cryptographic HW acceleration operation */
    g_isCryptoHWInitialized = SSS_CRYPTOHW_NONINITIALIZED;

    return kStatus_Success;
}

/*!
 * @brief This function will allow reinitizialize the cryptographic HW acceleration
 * next time we need it, typically after lowpower mode.
 */
void CRYPTO_DeinitHardware(void)
{
    g_isCryptoHWInitialized = SSS_CRYPTOHW_NONINITIALIZED;
}

void CRYPTO_ELEMU_reset(void)
{
    CRYPTO_DeinitHardware();
    (void)ELEMU_LP_WakeupPathInit(ELEMUA);
}

/******************************************************************************/
/*************************** Mutex ********************************************/
/******************************************************************************/
#if defined(MBEDTLS_THREADING_C)

/**
 * \def MBEDTLS_MCUX_FREERTOS_THREADING_ALT
 * You can comment this macro if you provide your own alternate implementation.
 *
 */
#if defined(SDK_OS_FREE_RTOS)
#define MBEDTLS_MCUX_FREERTOS_THREADING_ALT
#endif

/*
 * Define global mutexes for HW accelerator
 */

#if defined(MBEDTLS_MCUX_FREERTOS_THREADING_ALT)
/**
 * @brief Initializes the mbedTLS mutex functions.
 *
 * Provides mbedTLS access to mutex create, destroy, take and free.
 *
 * @see MBEDTLS_THREADING_ALT
 */
static void CRYPTO_ConfigureThreadingMcux(void);
#endif /* defined(MBEDTLS_MCUX_FREERTOS_THREADING_ALT) */

#endif /* defined(MBEDTLS_THREADING_C) */

/*-----------------------------------------------------------*/
/*--------- mbedTLS threading functions for FreeRTOS --------*/
/*--------------- See MBEDTLS_THREADING_ALT -----------------*/
/*-----------------------------------------------------------*/
#if defined(MBEDTLS_MCUX_FREERTOS_THREADING_ALT)
/* Threading mutex implementations for mbedTLS. */
#include "mbedtls/threading.h"
#include "threading_alt.h"

/**
 * @brief Implementation of mbedtls_mutex_init for thread-safety.
 *
 */
void mcux_mbedtls_mutex_init(mbedtls_threading_mutex_t *mutex)
{
    mutex->mutex = xSemaphoreCreateMutex();

    if (mutex->mutex != NULL)
    {
        mutex->is_valid = 1;
    }
    else
    {
        mutex->is_valid = 0;
    }
}

/**
 * @brief Implementation of mbedtls_mutex_free for thread-safety.
 *
 */
void mcux_mbedtls_mutex_free(mbedtls_threading_mutex_t *mutex)
{
    if (mutex->is_valid == 1)
    {
        vSemaphoreDelete(mutex->mutex);
        mutex->is_valid = 0;
    }
}

/**
 * @brief Implementation of mbedtls_mutex_lock for thread-safety.
 *
 * @return 0 if successful, MBEDTLS_ERR_THREADING_MUTEX_ERROR if timeout,
 * MBEDTLS_ERR_THREADING_BAD_INPUT_DATA if the mutex is not valid.
 */
int mcux_mbedtls_mutex_lock(mbedtls_threading_mutex_t *mutex)
{
    int ret = MBEDTLS_ERR_THREADING_BAD_INPUT_DATA;

    if (mutex->is_valid == 1)
    {
        if (xSemaphoreTake(mutex->mutex, portMAX_DELAY))
        {
            ret = 0;
        }
        else
        {
            ret = MBEDTLS_ERR_THREADING_MUTEX_ERROR;
        }
    }

    return ret;
}

/**
 * @brief Implementation of mbedtls_mutex_unlock for thread-safety.
 *
 * @return 0 if successful, MBEDTLS_ERR_THREADING_MUTEX_ERROR if timeout,
 * MBEDTLS_ERR_THREADING_BAD_INPUT_DATA if the mutex is not valid.
 */
int mcux_mbedtls_mutex_unlock(mbedtls_threading_mutex_t *mutex)
{
    int ret = MBEDTLS_ERR_THREADING_BAD_INPUT_DATA;

    if (mutex->is_valid == 1)
    {
        if (xSemaphoreGive(mutex->mutex))
        {
            ret = 0;
        }
        else
        {
            ret = MBEDTLS_ERR_THREADING_MUTEX_ERROR;
        }
    }

    return ret;
}

static void CRYPTO_ConfigureThreadingMcux(void)
{
    /* Configure mbedtls to use FreeRTOS mutexes. */
    mbedtls_threading_set_alt(mcux_mbedtls_mutex_init, mcux_mbedtls_mutex_free, mcux_mbedtls_mutex_lock,
                              mcux_mbedtls_mutex_unlock);
}
#endif /* defined(MBEDTLS_MCUX_FREERTOS_THREADING_ALT) */
