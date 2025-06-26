/*
 * Copyright 2021-2022 NXP.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_wdt.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.pn_wdt"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
static wdg_callback_t s_wdtCallback = NULL;

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Initialize the WDT.
 *
 * This function register the interrupt callback, set the interrupt counter threshold,
 * and sets the timeout to start WDT.
 *
 * @param base   wdt base pointer.
 * @param config The configuration.
 */
void WDT_Init(TIMERS_Type *base, const wdt_config_t *config)
{
    assert(NULL != config);

    s_wdtCallback = config->callback;

    WDT_ClearTimeoutStatus(base);

    WDT_SetInterruptThreshold(base, config->threshold);

    WDT_StartTimer(base, config->timeoutCount);
}

/*!
 * @brief De-initialize the WDT.
 *
 * This function stops the WDT, clears the interrupt flags, and unregisters
 * the callback.
 *
 * @param base   wdt base pointer.
 */
void WDT_Deinit(TIMERS_Type *base)
{
    WDT_StopTimer(base);

    s_wdtCallback = NULL;
}

/*!
 * @brief start wdt timer.
 *
 * @param base    wdt base pointer.
 * @param timeoutCount the initial timeout count of the timer. The total timeout time is determined by (1 /
 * timerCountingFreq_Hz) * timeoutCount.The maximum timeoutCount is 0x000FFFFF.
 */
void WDT_StartTimer(TIMERS_Type *base, uint32_t timeoutCount)
{
    assert((timeoutCount & (~TIMERS_WDOG_TIMEOUT_WDOG_TIMEOUT_MASK)) == 0U);
    /* as soon as the timeout value is load, the timer will start count */
    base->WDOG_TIMEOUT = timeoutCount;
}

/*!
 * @brief stop wdt.
 *
 * @param base    timer base pointer.
 */
void WDT_StopTimer(TIMERS_Type *base)
{
    /* stop the timer firstly */
    base->WDOG_TIMEOUT = 0U;
    /* disable interrupt status */
    WDT_ClearTimeoutStatus(base);
}

void WDT_HandleIRQ(TIMERS_Type *base)
{
    if (s_wdtCallback != NULL)
    {
        s_wdtCallback();
    }
}
