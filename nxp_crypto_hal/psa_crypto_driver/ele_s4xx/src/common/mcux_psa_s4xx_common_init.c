/*
 * Copyright 2022-2023,2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#include "mcux_psa_s4xx_common_init.h" /* ELE Crypto port layer */

#include "ele_fw.h"      /* ELE FW, can be placed in bootable container in real world app */
#include "fsl_s3mu.h"    /* Messaging unit driver */

#if defined(CONFIG_PSA_ELE_S4XX_NVM_MANAGER) || defined(PSA_ELE_S4XX_SD_NVM_MANAGER)
#include "ele_nvm_manager.h"
#endif

#if defined(__ZEPHYR__) && defined(CONFIG_PSA_ELE_S4XX_NVM_MANAGER)
#include "mcux_psa_s4xx_zephyr_nvm_manager.h"
#endif

#if defined(PSA_ELE_S4XX_SD_NVM_MANAGER)
#include "mcux_psa_s4xx_sdmmc_nvm_manager.h"
#endif

#if defined(MBEDTLS_PSA_ITS_FILE_FATFS)
#include "psa_its_fatfs.h"
#endif

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

ele_s4xx_ctx_t g_ele_ctx = { 0u }; /* Global context */

uint32_t g_isCryptoHWInitialized = false;

psa_status_t ele_to_psa_status(status_t ele_status)
{
    psa_status_t status = PSA_ERROR_HARDWARE_FAILURE;
    switch (ele_status) {
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

    status_t result = kStatus_Fail;

    do {
        /****************** Close Key Management Service **********************/
        if (g_ele_ctx.key_management_handle != 0u) {
            result = ELE_CloseKeyService(S3MU, g_ele_ctx.key_management_handle);
            if (result != kStatus_Success) {
                break;
            }
            g_ele_ctx.key_management_handle = 0u;
        }

        /****************** Close Key Store  ***********************************/
        if (g_ele_ctx.key_store_handle != 0u) {
            result = ELE_CloseKeystore(S3MU, g_ele_ctx.key_store_handle);
            if (result != kStatus_Success) {
                break;
            }
            g_ele_ctx.key_store_handle = 0u;
        }

#if defined(CONFIG_PSA_ELE_S4XX_NVM_MANAGER)
        /****************** Close NVM storage session **************************/
        if (g_ele_ctx.storage_handle != 0u) {
            result = ELE_CloseNvmStorageService(S3MU, g_ele_ctx.storage_handle);
            if (result != kStatus_Success) {
                break;
            }
            g_ele_ctx.storage_handle = 0u;
        }
#endif /* defined(CONFIG_PSA_ELE_S4XX_NVM_MANAGER) */

        /****************** Close EdgeLock session ******************/
        if (g_ele_ctx.session_handle != 0u) {
            result = ELE_CloseSession(S3MU, g_ele_ctx.session_handle);
            if (result != kStatus_Success) {
                break;
            }
            g_ele_ctx.session_handle = 0;
        }

    } while (0);

    return result;

}


/*!
 * @brief Application init for Crypto blocks.
 *
 * This function is provided to be called by MCUXpresso SDK applications.
 * It calls basic init for Crypto Hw acceleration and Hw entropy modules.
 */
status_t CRYPTO_InitHardware(void)
{
    status_t result     = kStatus_Fail;
    uint32_t trng_state = 0u;
#if defined(CONFIG_PSA_ELE_S4XX_NVM_MANAGER) || defined(PSA_ELE_S4XX_SD_NVM_MANAGER)
    ele_nvm_manager_t manager;
#endif /* CONFIG_PSA_ELE_S4XX_NVM_MANAGER || PSA_ELE_S4XX_SD_NVM_MANAGER */

#if defined(__ZEPHYR__) && (CONFIG_PSA_ELE_S4XX_NVM_MANAGER)
    manager.nvm_read = zephyr_settings_read;
    manager.nvm_write = zephyr_settings_write;
#elif defined(PSA_ELE_S4XX_SD_NVM_MANAGER)
    manager.nvm_read = sd_file_read;
    manager.nvm_write = sd_file_write;
#endif

    if (g_isCryptoHWInitialized == true) {
        return 0;
    }

    /* Mutex for access to ele_crypto HW */
    if (mcux_mutex_init(&ele_hwcrypto_mutex)) {
        return kStatus_Fail;
    }

    if ((result = mcux_mutex_lock(&ele_hwcrypto_mutex)) != 0) {
        return kStatus_Fail;
    }

    do {
        /****************** Load EdgeLock FW and register NVM manager One time step ***********************/
        if (g_ele_ctx.is_fw_loaded != true) {
            result = ELE_LoadFw(S3MU, ele_fw);
            if (result != kStatus_Success) {
                break;
            } else {
                g_ele_ctx.is_fw_loaded = true;
            }

            /****************** Start RNG ***********************/
            result = ELE_StartRng(S3MU);
            if (result != kStatus_Success) {
                break;
            }

            do
            {
                result = ELE_GetTrngState(S3MU, &trng_state);
            } while (!(((trng_state & 0xFFu) == kELE_TRNG_ready) &&
                       ((trng_state & 0xFF00u) == kELE_TRNG_CSAL_success << 8u )));

            /****************** Initialize EdgeLock services ************/
            result = ELE_InitServices(S3MU);
            if (result != kStatus_Success) {
                break;
            }

#if defined(CONFIG_PSA_ELE_S4XX_NVM_MANAGER) || defined(PSA_ELE_S4XX_SD_NVM_MANAGER)

            /* Register for NVM Storage backend - to be done only once*/
            result = ELE_Register_NVM_Manager(&manager);
            if (result != kStatus_Success) {
                break;
            }
#endif

#if defined(MBEDTLS_PSA_ITS_FILE_FATFS) && defined(PSA_ELE_S4XX_SD_NVM_MANAGER)
            sd_ele_fs_initialize();
            sd_its_fs_initialize();
#endif
#if defined(__ZEPHYR__) && defined(CONFIG_PSA_ELE_S4XX_NVM_MANAGER)
            ele_zephyr_settings_initialize();
#endif

        }

        // Initalize rest of the handles as 0
        g_ele_ctx.data_storage_handle = 0;
        g_ele_ctx.key_management_handle = 0;
        g_ele_ctx.key_store_handle = 0;
        g_ele_ctx.session_handle = 0;
        g_ele_ctx.storage_handle = 0;

        /****************** Open EdgeLock session ******************/
        result = ELE_OpenSession(S3MU, &g_ele_ctx.session_handle);
        if (result != kStatus_Success) {
            break;
        }

#if defined(CONFIG_PSA_ELE_S4XX_NVM_MANAGER) || defined(PSA_ELE_S4XX_SD_NVM_MANAGER)

        /****************** Open NVM Storage service **************************/
        result =
            ELE_OpenNvmStorageService(S3MU, g_ele_ctx.session_handle, &g_ele_ctx.storage_handle);
        if (result != kStatus_Success) {
            break;
        }

        /***************** Import Storage master from NVM ********************/
        result = ELE_StorageMasterImport_From_NVM(S3MU, g_ele_ctx.storage_handle);
        if (result == kStatus_NoData) {
            result = kStatus_Success;
        }
        if (result != kStatus_Success) {
            break;
        }
#endif /* defined(CONFIG_PSA_ELE_S4XX_NVM_MANAGER) */

        /**************** Create/Open key Store ******************************/
        ele_keystore_t keystoreParam;
        keystoreParam.id            = ELE_KEYSTORE_ID;
        keystoreParam.nonce         = ELE_KEYSTORE_NONCE;
        keystoreParam.max_updates   = 0xffff;
        keystoreParam.min_mac_check = false;
        keystoreParam.min_mac_len   = 0u;

        result = ELE_CreateKeystore(S3MU,
                                    g_ele_ctx.session_handle,
                                    &keystoreParam,
                                    &g_ele_ctx.key_store_handle);
        if (result != kStatus_Success) {
            result = ELE_OpenKeystore(S3MU, g_ele_ctx.session_handle, &keystoreParam,
                                      &g_ele_ctx.key_store_handle, NULL, 0);
            if (result != kStatus_Success) {
                break;
            }
        }

        /****************** Key Management Open *******************************/
        result = ELE_OpenKeyService(S3MU,
                                    g_ele_ctx.key_store_handle,
                                    &g_ele_ctx.key_management_handle);
        if (result != kStatus_Success) {
            break;
        }

        g_isCryptoHWInitialized = true;

    } while (0);

    if (result != kStatus_Success) {
        ele_close_handles();
    }

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex)) {
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
        return 0;
    }

    if (mcux_mutex_lock(&ele_hwcrypto_mutex)) {
        return kStatus_Fail;
    }

    result = ele_close_handles();
    if (result == kStatus_Success) {
        g_isCryptoHWInitialized = false;
    }

    if (mcux_mutex_unlock(&ele_hwcrypto_mutex)) {
        return kStatus_Fail;
    }

    if (result == kStatus_Success) {
        mcux_mutex_free(&ele_hwcrypto_mutex);
    }

    return result;
}
