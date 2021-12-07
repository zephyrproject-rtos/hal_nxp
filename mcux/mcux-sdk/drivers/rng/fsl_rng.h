/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FSL_RNG_DRIVER_H_
#define _FSL_RNG_DRIVER_H_

#include "fsl_common.h"

#if defined(FSL_FEATURE_SOC_LPC_RNG_COUNT) && FSL_FEATURE_SOC_LPC_RNG_COUNT

/*!
 * @addtogroup rng
 * @{
 */

/*******************************************************************************
 * Definitions
 *******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.rng"
#endif

/*! @name Driver version */
/*@{*/
/*! @brief RNG driver version 2.0.0.
 *
 * Current version: 2.0.0
 *
 * Change log:
 * - Version 2.0.0
 *   - Initial version.
 */
#define FSL_RNG_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*******************************************************************************
 * API
 *******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Gets random data.
 *
 * This function returns single 32 bit random number.
 *
 * @return random data
 */
static inline uint32_t RNG_GetRandomData(void)
{
    return OTP_API->rngRead();
}

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_FEATURE_SOC_LPC_RNG_COUNT */
#endif /*_FSL_TRNG_H_*/
