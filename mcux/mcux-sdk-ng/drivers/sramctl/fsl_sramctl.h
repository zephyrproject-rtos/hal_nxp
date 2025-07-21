/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_SRAMCTL_H_
#define FSL_SRAMCTL_H_

#include "fsl_device_registers.h"
#include "fsl_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @addtogroup lpi2c
 * @{
 */

/*!
 * @name Driver version
 * @{
 */
/*! @brief SRAMCTL driver version. */
#define FSL_SRAMCTL_DRIVER_VERSION (MAKE_VERSION(3, 0, 0))

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * brief Initialize memory
 *
 * param instance_idx instance index
 * param start_addr
 * param end_addr
 */
void SRAMCTL_InitMem(uint32_t instance_idx, uint32_t start_addr, uint32_t end_addr);

#if defined(__cplusplus)
extern "C" {
#endif


#if defined(__cplusplus)
}
#endif
/*! @} */
#endif /* FSL_SRAMCTL_H_ */
