/*
 *     Copyright 2026 NXP
 *     All rights reserved.
 *
 *     SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _MCUX_SGI_H_
#define _MCUX_SGI_H_

#include "fsl_common.h"

#include "fsl_trng.h"
#include "fsl_crc.h"

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
 * @brief SGI Init after power down.
 *
 * This function enable all SGI related clocks, enable SGI and enables other needed HW used by SGI crypto library.
 *
 * @param base SGI peripheral address.
 *
 * @return kStatus_Success upon success, kStatus_Fail otherwise
 */
status_t SGI_PowerDownWakeupInit(SGI_Type *base);

#if defined(__cplusplus)
}
#endif

/*!
 *@}
 */

#endif /* _MCUX_SGI_H_ */
