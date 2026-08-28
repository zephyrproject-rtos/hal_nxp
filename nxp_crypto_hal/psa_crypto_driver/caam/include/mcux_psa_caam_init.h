/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_CAAM_INIT_H
#define MCUX_PSA_CAAM_INIT_H

/** \file mcux_psa_caam_init.h
 *
 * This file contains the declaration of the entry points associated to
 * driver initialisation and de-initialisation procedures.
 *
 */

#include "psa/crypto.h"

#include "fsl_common.h"
#include "osal_mutex.h"

#define PSA_CAAM CAAM

#include "fsl_caam.h"

#define PSA_CRYPTO_DRIVER_CAAM_OPAQUE_ECB 1
#define PSA_CRYPTO_DRIVER_CAAM_OPAQUE_CCM 2
typedef enum _mcux_psa_caam_key_type {
    MCUX_PSA_CAAM_KEY_TYPE_NONE = 0,
    MCUX_PSA_CAAM_KEY_TYPE_ECB  = PSA_CRYPTO_DRIVER_CAAM_OPAQUE_ECB,
    MCUX_PSA_CAAM_KEY_TYPE_CCM  = PSA_CRYPTO_DRIVER_CAAM_OPAQUE_CCM,
} mcux_psa_caam_key_type_t;


#ifndef PSA_CRYPTO_DRIVER_CAAM_OPAQUE
#define PSA_CRYPTO_DRIVER_CAAM_OPAQUE PSA_CRYPTO_DRIVER_CAAM_OPAQUE_ECB
#endif

/* MUTEX FOR HW Modules*/
extern mcux_mutex_t caam_hwcrypto_mutex;

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
 * @brief  Convert CAAM error to PSA status
 *
 * @return PSA_SUCCESS on success. Error code from psa_status_t on
 *          failure
 */
psa_status_t caam_to_psa_status(status_t caam_status);

#ifdef __cplusplus
}
#endif

#endif /* MCUX_PSA_CAAM_INIT_H */
