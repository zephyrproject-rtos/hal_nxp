/*
 * Copyright 2022-2023 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_S4XX_COMMON_INIT_H
#define MCUX_PSA_S4XX_COMMON_INIT_H

/** \file ele_s4xx_transparent_psa_init.h
 *
 * This file contains the declaration of the entry points associated to
 * driver initialisation and de-initialisation procedures.
 *
 */

#include "psa/crypto.h"

#include "fsl_common.h"
#include "osal_mutex.h"

#if defined(MIMXRT1189_cm33_SERIES) || defined(MIMXRT1187_cm33_SERIES) || defined(MIMXRT1186_cm33_SERIES) || \
    defined(MIMXRT1182_SERIES) || defined(MIMXRT1181_SERIES)
#define S3MU MU_RT_S3MUA
#elif defined(MIMXRT1189_cm7_SERIES) || defined(MIMXRT1187_cm7_SERIES) || defined(MIMXRT1186_cm7_SERIES)
#define S3MU MU_APPS_S3MUA
#else
#error "No valid SoC defined"
#endif /* MIMXRT118x_cm33_SERIES | MIMXRT118x_SERIES | MIMXRT118x_cm7_SERIES */

#include "ele_crypto.h"

typedef struct
{
    uint32_t session_handle;
    uint32_t key_store_handle;
    uint32_t storage_handle;
    uint32_t data_storage_handle;
    uint32_t key_management_handle;

    bool is_fw_loaded;

} ele_s4xx_ctx_t;

#define ELE_KEYSTORE_ID (0x12345678u)

#define ELE_KEYGROUP_ID_PERSISTENT       (1)
#define ELE_KEYGROUP_ID_PERSISTENT_LIMIT ELE_KEYGROUP_ID_VOLATILE
#define ELE_KEYGROUP_ID_VOLATILE         (50)
#define ELE_KEYGROUP_ID_VOLATILE_LIMIT   (100)

#define ELE_KEYSTORE_NONCE (0xabcdef12u)
#define ELE_KEY_LIFECYCLE  (0x00000001u) /* 1 = OPEN, 2 = Closed, 4 = Closed & Locked */

/* MUTEX FOR HW Modules*/
extern mcux_mutex_t ele_hwcrypto_mutex;

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Application init for Crypto blocks.
 *
 * This function is provided to be called by MCUXpresso SDK applications.
 * It calls basic init for Crypto Hw acceleration and Hw entropy modules.
 */
status_t CRYPTO_InitHardware(void);

/*!
 * @brief Application Deinit for Crypto blocks.
 *
 * This function is provided to be called by MCUXpresso SDK applications.
 * It calls basic deinit for Crypto Hw acceleration and Hw entropy modules.
 */
status_t CRYPTO_DeinitHardware(void);

/*!
 * @brief  Convert ELE error to PSA status
 *
 * @return PSA_SUCCESS on success. Error code from psa_status_t on
 *          failure
 */
psa_status_t ele_to_psa_status(status_t ele_status);

#ifdef __cplusplus
}
#endif

#endif /* MCUX_PSA_S4XX_COMMON_INIT_H */
