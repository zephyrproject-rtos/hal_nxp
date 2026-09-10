/*
 *     Copyright 2024 NXP
 *     All rights reserved.
 *
 *     SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _MCUX_ELS_H_
#define _MCUX_ELS_H_

#include <stdint.h>
#include <stddef.h>

#include "fsl_common.h"
#include <mcuxClEls.h>              // Interface to the entire nxpClEls component
#include <mcuxCsslFlowProtection.h> // Code flow protection
#include <mcuxClRandom.h>
#include <ip_platform.h>

/*!
 * @addtogroup els_pkc
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
enum
{
    kStatus_SlotUnavailable =
        MAKE_STATUS(kStatusGroup_ELS_PKC, 0), /*!< Key slot is not available to be used as PRNG kick-off. */
};

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief ELS Init after power down.
 *
 * This function load TRNG signed configuration using ELS command into ELS internal TRNG.
 * Normally all of these actions are done automatically by boot ROM, but if an application uses Power Down wake-up
 * (w/o ROM exection) or ELS reset, this function should be called before using ELS's TRNG services with approved
 * configuration.
 *
 * @return kStatus_Success upon success, kStatus_Fail otherwise
 */
status_t ELS_Load_TrngCfg();

/*!
 * @brief ELS Init after power down.
 *
 * This function enable all ELS related clocks, enable ELS and start ELS PRNG.
 * Normally all of these actions are done automatically by boot ROM, but if an application uses Power Down mode
 * this function must be called before using ELS after wake-up.
 *
 * @param base ELS peripheral address.
 *
 * @return kStatus_Success upon success, kStatus_Fail otherwise
 */
status_t ELS_PowerDownWakeupInit(ELS_Type *base);

#if defined(__cplusplus)
}
#endif

/*!
 *@}
 */

#endif /* _MCUX_ELS_H_ */
