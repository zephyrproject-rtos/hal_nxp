/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_ELE_HSEB_COMMON_INIT_H
#define MCUX_PSA_ELE_HSEB_COMMON_INIT_H

/** \file ele_hseb_transparent_psa_init.h
 *
 * This file contains the declaration of the entry points associated to
 * driver initialisation and de-initialisation procedures.
 *
 */

#include "psa/crypto.h"

#include "fsl_common.h"
#include "osal_mutex.h"

#include "hse_interface.h"

extern mcux_mutex_t ele_hseb_hwcrypto_mutex;

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

#ifdef __cplusplus
}
#endif
#endif /* MCUX_PSA_ELE_HSEB_COMMON_INIT_H */
