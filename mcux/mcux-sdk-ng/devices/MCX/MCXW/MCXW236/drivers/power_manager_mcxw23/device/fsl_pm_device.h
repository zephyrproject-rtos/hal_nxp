/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2025 NXP                          */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

#ifndef _PM_DEVICE_H_
#define _PM_DEVICE_H_

/**
 * This component implements device specific power management functions.
 *
 * This component defines the supported low power modes and all the properties. These can be
 * retrieved with PMDEVICE_GetDeviceOption. This function is typically only called by fsl_pm_core.
 *
 * A sleep timer, that will remain active in low power modes, is available to the application to
 * measure the time the system was asleep.
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */
#include "fsl_common.h"
#include "fsl_pm_core.h"

/* -------------------------------------------------------------------------- */
/*                              Public type definition                        */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Public prototypes                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Initialize platform specific resources for low power support
 */
void PMDEVICE_Init(void);

/*!
 * \brief Retrieves the supported low power option
 */
const pm_device_option_t *PMDEVICE_GetDeviceOption(void);

/*!
 * \brief Returns the counter value of the sleep timer
 */
uint64_t PMDEVICE_GetSleepTimer(void);

/*!
 * \brief Starts the sleep timer
 */
void PMDEVICE_StartSleepTimer(void);

/*!
 * \brief Stops the sleep timer
 */
void PMDEVICE_StopSleepTimer(void);

#endif /* _PM_DEVICE_H_ */
