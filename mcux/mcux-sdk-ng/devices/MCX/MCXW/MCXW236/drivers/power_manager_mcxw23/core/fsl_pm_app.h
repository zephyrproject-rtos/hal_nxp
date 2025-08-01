/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_PM_APP_H_
#define _FSL_PM_APP_H_

#include "fsl_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
 * API
 ******************************************************************************/
/**
 * @brief This function stores the systick load value to be able to restore after waking up.
 *
 * @param initialTickLoad value of the systick load
 */
void PMAPP_Init(uint32_t initialTickLoad);

/**
 * @brief Enter low power mode for a specified duration.
 *
 * @param sleepDuration sleep duration in microseconds
 * @return status_t
 */
status_t PMAPP_EnterLowPower(uint32_t sleepDuration);

/**
 * @brief Print the smallest headroom before wakeup.
 *        Can be used to configure the exit_latency per application
 *
 */
void PMAPP_PrintSmallestHeadroom(void);

#if defined(__cplusplus)
}
#endif

#endif /* _FSL_PM_APP_H_ */
