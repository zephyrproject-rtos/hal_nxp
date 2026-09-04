/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "mcux_psa_caam_init.h" /* CAAM Crypto port layer */

#ifdef PSA_CAAM_SECURE_STORAGE
#include "secure_storage.h"
#endif

/******************************************************************************/
/*************************** Mutex ********************************************/
/******************************************************************************/
/*
 * Define global mutexes for HW accelerator
 */
mcux_mutex_t caam_hwcrypto_mutex;

/******************************************************************************/
/******************** CRYPTO_InitHardware *************************************/
/******************************************************************************/

#if defined(FSL_FEATURE_HAS_L1CACHE) || defined(__DCACHE_PRESENT)
/* Note: If JR interface is cached and multiple jobs are being scheduled at the same time, */
/* it is recommended to move JR interfaces to non-cahed memory, rather than invalidate */
/* them before retrieving output ring data  */
/*! @brief CAAM job ring interface 0 in system memory. */
AT_NONCACHEABLE_SECTION(static caam_job_ring_interface_t s_jrif0);
// /*! @brief CAAM job ring interface 1 in system memory. */
// AT_NONCACHEABLE_SECTION(static caam_job_ring_interface_t s_jrif1);
// /*! @brief CAAM job ring interface 2 in system memory. */
// AT_NONCACHEABLE_SECTION(static caam_job_ring_interface_t s_jrif2);
// /*! @brief CAAM job ring interface 3 in system memory. */
// AT_NONCACHEABLE_SECTION(static caam_job_ring_interface_t s_jrif3);
#else
/*! @brief CAAM job ring interface 0 in system memory. */
static caam_job_ring_interface_t s_jrif0;
// /*! @brief CAAM job ring interface 1 in system memory. */
// static caam_job_ring_interface_t s_jrif1;
// /*! @brief CAAM job ring interface 2 in system memory. */
// static caam_job_ring_interface_t s_jrif2;
// /*! @brief CAAM job ring interface 3 in system memory. */
// static caam_job_ring_interface_t s_jrif3;
#endif /* __DCACHE_PRESENT || FSL_FEATURE_HAS_L1CACHE */

static bool g_isCryptoHWInitialized = false;

psa_status_t caam_to_psa_status(status_t caam_status)
{
    psa_status_t status = PSA_ERROR_HARDWARE_FAILURE;
    switch (caam_status) {
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
    status_t result          = kStatus_Fail;
    caam_config_t caamConfig = { .jobRingInterface = { NULL, NULL, NULL, NULL } };
#ifdef PSA_CAAM_SECURE_STORAGE
    psa_status_t err;
#endif

    if (g_isCryptoHWInitialized == true) {
        return kStatus_Success;
    }

    /* Mutex for access to caam_crypto HW */
    if (mcux_mutex_init(&caam_hwcrypto_mutex)) {
        return kStatus_Fail;
    }

    if ((result = mcux_mutex_lock(&caam_hwcrypto_mutex)) != 0) {
        return kStatus_Fail;
    }

    /* setup memory for job ring interfaces. */
    caamConfig.jobRingInterface[0] = &s_jrif0;
    // caamConfig.jobRingInterface[1] = &s_jrif1;
    // caamConfig.jobRingInterface[2] = &s_jrif2;
    // caamConfig.jobRingInterface[3] = &s_jrif3;

    result = CAAM_Init(PSA_CAAM, &caamConfig);

#ifdef PSA_CAAM_SECURE_STORAGE
    if (result == kStatus_Success) {
        err = secure_storage_its_initialize();
        if (err != PSA_SUCCESS) {
            result = kStatus_Fail;
        }
    }
#endif

    if (result == kStatus_Success) {
        g_isCryptoHWInitialized = true;
    }

    if (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0) {
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

    if (mcux_mutex_lock(&caam_hwcrypto_mutex) != 0) {
        return kStatus_Fail;
    }

    result = CAAM_Deinit(PSA_CAAM);

    if (result == kStatus_Success) {
        g_isCryptoHWInitialized = false;
    }

    if (mcux_mutex_unlock(&caam_hwcrypto_mutex) != 0) {
        return kStatus_Fail;
    }

    if (result == kStatus_Success) {
        mcux_mutex_free(&caam_hwcrypto_mutex);
    }

    return result;
}
