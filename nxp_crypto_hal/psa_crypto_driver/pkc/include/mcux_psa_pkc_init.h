/*
 * Copyright 2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_PKC_INIT_H
#define MCUX_PSA_PKC_INIT_H

/** \file mcux_psa_pkc_init.h
 *
 * This file contains the declaration of the entry points associated to
 * driver initialisation and de-initialisation procedures.
 *
 */

#include "psa/crypto.h"

#include "fsl_common.h"
#include "osal_mutex.h"

#include <mcuxClExample_Session_Helper.h>
#include <mcuxClCore_Examples.h>
#include <mcuxClExample_RNG_Helper.h>

#include "mcux_pkc.h"

/* MUTEX FOR HW Modules*/
extern mcux_mutex_t pkc_hwcrypto_mutex;

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Application init for the PKC crypto block.
 *
 * This function is provided to be called by MCUXpresso SDK applications.
 * It calls basic init for Crypto Hw acceleration and Hw entropy modules.
 */
status_t psa_pkc_init(void);

/*!
 * @brief Application Deinit for the PKC crypto block.
 *
 * This function is provided to be called by MCUXpresso SDK applications.
 * It calls basic deinit for Crypto Hw acceleration and Hw entropy modules.
 */
status_t psa_pkc_deinit(void);

#ifdef __cplusplus
}
#endif

#endif /* MCUX_PSA_PKC_INIT_H */
