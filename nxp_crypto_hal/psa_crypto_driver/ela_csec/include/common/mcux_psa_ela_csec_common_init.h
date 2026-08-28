/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_ELA_CSEC_COMMON_INIT_H
#define MCUX_PSA_ELA_CSEC_COMMON_INIT_H

/** \file ela_csec_transparent_psa_init.h
 *
 * This file contains the declaration of the entry points associated to
 * driver initialisation and de-initialisation procedures.
 *
 */

#include "psa/crypto.h"

#include "fsl_common.h"
#include "osal_mutex.h"

#include "ela_csec_driver.h"
#include "ela_csec_hw_access.h"

/* Define a common timeout value for the CSEC driver calls */
#define ELA_CSEC_CALL_TIMEOUT (1u)

/* ELA_CSEC key size in bytes */
#define ELA_CSEC_KEY_SIZE (16u)

typedef struct
{
    csec_state_t state;
} ela_csec_ctx_t;

/* MUTEX FOR HW Modules*/
extern mcux_mutex_t ela_csec_hwcrypto_mutex;

/* Global context for ELA_CSEC */
extern ela_csec_ctx_t g_ela_csec_ctx;

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
 * @brief Application Reinit for Crypto blocks.
 *
 * This function is provided to be called by MCUXpresso SDK applications.
 * It calls basic reinit for Crypto Hw acceleration and Hw entropy modules.
 */
status_t CRYPTO_ReinitHardware(void);


/*!
 * @brief  Convert ELA_CSEC error to PSA status
 *
 * @return PSA_SUCCESS on success. Error code from psa_status_t on
 *          failure
 */
psa_status_t ela_csec_to_psa_status(status_t ela_csec_status);

#ifdef __cplusplus
}
#endif

#endif /* MCUX_PSA_ELA_CSEC_COMMON_INIT_H */
