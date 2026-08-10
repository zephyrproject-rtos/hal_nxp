/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_mau.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_mau"
#endif

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Clock name array for MAU. */
static const clock_ip_name_t s_mauClockName[] = MAU_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * brief Enables the MAU peripheral clock.
 *
 * This function enables the clock gate in the SIM module for the MAU peripheral.
 * Call this before using any MAU computation functions.
 */
void MAU_Init(void)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Ungate the clock. */
    CLOCK_EnableClock(s_mauClockName[0]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(SIM_MISC0_MAU_EN_MASK)
    SIM->MISC0 |= SIM_MISC0_MAU_EN_MASK;
#endif
}

/*!
 * brief Disables the MAU peripheral clock.
 *
 * This function disables the clock gate in the SIM module for the MAU peripheral.
 */
void MAU_Deinit(void)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Gate the clock. */
    CLOCK_DisableClock(s_mauClockName[0]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}
