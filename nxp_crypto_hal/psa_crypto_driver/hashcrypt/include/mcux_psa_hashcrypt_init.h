/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_HASHCRYPT_INIT_H
#define MCUX_PSA_HASHCRYPT_INIT_H

/** \file mcux_psa_hashcrypt_init.h
 *
 * This file contains the declaration of the entry points associated to
 * driver initialisation and de-initialisation procedures.
 *
 */

#include "psa/crypto.h"

#include "fsl_common.h"
#include "osal_mutex.h"

#define PSA_HASHCRYPT HASHCRYPT

#include "fsl_hashcrypt.h"

/* MUTEX FOR HW Modules*/
extern mcux_mutex_t hashcrypt_hwcrypto_mutex;

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Application init for the Hashcrypt crypto block.
 *
 * This function is provided to be called by MCUXpresso SDK applications.
 * It calls basic init for Crypto Hw acceleration and Hw entropy modules.
 */
status_t CRYPTO_InitHardware_Hashcrypt(void);

/*!
 * @brief Application Deinit the Hashcrypt crypto block.
 *
 * This function is provided to be called by MCUXpresso SDK applications.
 * It calls basic deinit for Crypto Hw acceleration and Hw entropy modules.
 */
status_t CRYPTO_DeinitHardware_Hashcrypt(void);

/*!
 * @brief  Convert HASHCRYPT error to PSA status
 *
 * @return PSA_SUCCESS on success. Error code from psa_status_t on
 *          failure
 */
psa_status_t hashcrypt_to_psa_status(status_t hashcrypt_status);

#ifdef __cplusplus
}
#endif

#endif /* MCUX_PSA_HASHCRYPT_INIT_H */
