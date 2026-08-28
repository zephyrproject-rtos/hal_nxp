/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_DCP_ENTROPY_H
#define MCUX_PSA_DCP_ENTROPY_H

/** \file mcux_psa_dcp_entropy.h
 *
 * This file contains the declaration of the entry points associated
 * to the entropy capability as described by the PSA Cryptoprocessor
 * Driver interface specification
 *
 */

#include "psa/crypto.h"
#include "osal_mutex.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Initializes the random adapter module for a random data generator basic operation.
 *
 * @note This API should be called at the beginning of the application using the random adapter driver.
 *
 * @retval PSA_SUCCESS Rand module initialize succeed
 */
psa_status_t mcux_psa_dcp_entropy_init(mcux_mutex_t *mutex);

/*!
 * @brief DeInitilizate the random adapter module.
 *
 * @note This API should be called when not using the rand adapter driver anymore.
 *
 */
void mcux_psa_dcp_entropy_deinit(void);

/*!
 * \brief Collect entropy from a TRNG source
 *
 * \param[in]  flags         Flags to be passed to the TRNG source
 * \param[out] estimate_bits Estimation of the obtained entropy in bits
 * \param[out] output        Collected entropy from the TRNG source
 * \param[in]  output_size   Size of the output buffer
 *
 * \retval  PSA_SUCCESS on success. Error code from \ref psa_status_t on
 *          failure
 */
psa_status_t mcux_psa_dcp_entropy_get(uint32_t flags,
                                         size_t *estimate_bits,
                                         uint8_t *output,
                                         size_t output_size);
#ifdef __cplusplus
}
#endif
#endif /* MCUX_PSA_DCP_ENTROPY_H */
