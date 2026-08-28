/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_SGI_COMMON_INIT_H
#define MCUX_PSA_SGI_COMMON_INIT_H

/** \file mcux_sgi_common_psa_init.h
 *
 * This file contains the declaration of the entry points associated to
 * driver initialisation and de-initialisation procedures.
 *
 */

#include "psa/crypto.h"

#include "fsl_common.h"
#include "osal_mutex.h"

#include <mcuxClSession.h>
#include <mcuxClKey.h>
#include <mcuxClAes.h> // Interface to AES-related definitions and types


#include <mcuxClExample_Session_Helper.h>
#include <mcuxClCore_Examples.h>
#include <mcuxClExample_RNG_Helper.h>

#include "mcux_sgi.h"


/* MUTEX FOR HW Modules */
extern mcux_mutex_t sgi_hwcrypto_mutex;


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
 * @brief Application init for Crypto blocks.
 *
 * Unsafe version of CRYPTO_InitHardware that does not take mutexs.
 */
status_t CRYPTO_InitHardwareUnsafe(void);

/*!
 * @brief Application Deinit for Crypto blocks.
 *
 * This function is provided to be called by MCUXpresso SDK applications.
 * It calls basic deinit for Crypto Hw acceleration and Hw entropy modules.
 */
status_t CRYPTO_DeinitHardware(void);

/*!
 * @brief Application Deinit for Crypto blocks.
 *
 * Unsafe version of CRYPTO_DeinitHardware that does not take mutexs and do not close handles.
 */
status_t CRYPTO_DeinitHardwareUnsafe(void);

#ifdef __cplusplus
}
#endif

#endif /* MCUX_PSA_SGI_COMMON_INIT_H */
