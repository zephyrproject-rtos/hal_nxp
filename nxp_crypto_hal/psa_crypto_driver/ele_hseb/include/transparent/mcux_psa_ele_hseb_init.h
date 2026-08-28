/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_ELE_HSEB_INIT_H
#define MCUX_PSA_ELE_HSEB_INIT_H

/** \file mcux_psa_ele_hseb_init.h
 *
 * This file contains the declaration of the entry points associated to
 * driver initialisation and de-initialisation procedures.
 *
 */

#include "psa/crypto.h"
#include "mcux_psa_ele_hseb_common_init.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief  Initialises the ELE_HSEB driver
 *
 * @return PSA_SUCCESS on success, PSA_GENERIC_ERROR on failure. If a failure
 *         does happen, it may likely be caused by not having HSE firmware
 *         installed on the device.
 */
psa_status_t ele_hseb_transparent_init(void);

/*!
 * @brief  De-Initialises the ELE_HSEB driver
 *
 * @return PSA_SUCCESS on success, PSA_GENERIC_ERROR on failure.
 */
psa_status_t ele_hseb_transparent_free(void);

#ifdef __cplusplus
}
#endif
#endif /* MCUX_PSA_ELE_HSEB_INIT_H */
