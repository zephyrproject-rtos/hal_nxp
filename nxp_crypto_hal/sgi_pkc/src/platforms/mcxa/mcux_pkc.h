/*
 *     Copyright 2026 NXP
 *     All rights reserved.
 *
 *     SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _MCUX_PKC_H_
#define _MCUX_PKC_H_

#include "fsl_common.h"
#include <ip_platform.h>

#include "fsl_glikey.h"

/*!
 * @addtogroup sgi_pkc
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief PKC Init after power down.
 *
 * This function enables RAM interleave, RAM execute permission, clocks, zeroize the PKC RAM and reset PKC peripheral.
 *
 * @param base PKC peripheral address.
 *
 * @return kStatus_Success upon success, kStatus_Fail otherwise
 */
status_t PKC_PowerDownWakeupInit(PKC_Type *base);

/*!
 * @brief PKC Init after power down.
 *
 * This function enables RAM interleave, RAM execute permission, clocks and reset PKC peripheral.
 *
 * @param base PKC peripheral address.
 *
 * @return kStatus_Success upon success, kStatus_Fail otherwise
 */
status_t PKC_InitNoZeroize(PKC_Type *base);

#if defined(__cplusplus)
}
#endif

/*!
 *@}
 */

#endif /* _MCUX_PKC_H_ */
