/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_ELA_CSEC_INIT_H
#define MCUX_PSA_ELA_CSEC_INIT_H

/** \file mcux_psa_ela_csec_init.h
 *
 * This file contains the declaration of the entry points associated to
 * driver initialisation and de-initialisation procedures.
 *
 */

#include "psa/crypto.h"
#include "mcux_psa_ela_csec_common_init.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief  Initialises the ELA_CSEC driver
 *
 * @return PSA_SUCCESS on success. Error code from psa_status_t on
 *          failure
 */
psa_status_t ela_csec_transparent_init(void);

/*!
 * @brief  De-Initialises the ELA_CSEC driver
 *
 * @return PSA_SUCCESS on success. Error code from psa_status_t on
 *          failure
 */
psa_status_t ela_csec_transparent_free(void);

#ifdef __cplusplus
}
#endif

#endif /* MCUX_PSA_ELA_CSEC_INIT_H */
