/*
 * Copyright 2021-2022 NXP.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_WDT_H_
#define FSL_WDT_H_

#include "fsl_common.h"

/*!
 * @addtogroup wdt
 * @{
 */

/*******************************************************************************
 * Definitions
 *******************************************************************************/

/*! @brief Defines WDT driver version 2.1.0. */
#define FSL_WDT_DRIVER_VERSION (MAKE_VERSION(2, 1, 0))

/*!
 * @brief Callback function when WDT interrupt happens.
 */
typedef void (*wdg_callback_t)(void);

/*!
 * @brief WDT configuration structure
 */
typedef struct
{
    uint32_t timeoutCount; /*!< Timeout value set to register WDOG_TIMEOUT.
                                The maximum timeoutCount is 0x000FFFFF. */
    uint32_t threshold;    /*!< Time threshold to trigger interrupt. */
    wdg_callback_t callback; /*!< Callback when interrupt happens. */
} wdt_config_t;

/*******************************************************************************
 * API
 *******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @brief Initialize the WDT.
 *
 * This function register the interrupt callback, set the interrupt counter threshold,
 * and sets the timeout to start WDT.
 *
 * @param base   wdt base pointer.
 * @param config The configuration.
 */
void WDT_Init(TIMERS_Type *base, const wdt_config_t *config);

/*!
 * @brief De-initialize the WDT.
 *
 * This function stops the WDT, clears the interrupt flags, and unregisters
 * the callback.
 *
 * @param base   wdt base pointer.
 */
void WDT_Deinit(TIMERS_Type *base);

/*!
 * @brief start wdt timer.
 *
 * @param base    wdt base pointer.
 * @param timeoutCount the initial timeout count of the timer. The total timeout time is determined by (1 /
 * timerCountingFreq_Hz) * timeoutCount.The maximum timeoutCount is 0x000FFFFF.
 */
void WDT_StartTimer(TIMERS_Type *base, uint32_t timeoutCount);

/*!
 * @brief stop wdt timer.
 *
 * @param base    timer base pointer.
 */
void WDT_StopTimer(TIMERS_Type *base);

/*!
 * @brief Sets the WDT triggerthreshold.
 *
 * The Watchdog timer includes a "timeout pre-emption" feature whereby
 * the non-maskable interrupt output intreq_wdg_o is asserted high when
 * the counter reaches the value specified in field WDOG_INT_THRESHOLD
 * defined in register TIMERS_WDOG_TRIGGER_INT_REG.
 * @param base WDT peripheral base address
 * @param threshold WDT triggerthreshold value.
 */
static inline void WDT_SetInterruptThreshold(TIMERS_Type *base, uint32_t threshold)
{
    base->WDOG_TRIGGER_INT = TIMERS_WDOG_TRIGGER_INT_WDOG_INT_THRESHOLD(threshold);
}

/*!
 * @brief This function force sets the timeout status flag, even when WDT counter does not reach threshold.
 *
 * @param base    timer base pointer.
 */
static inline void WDT_SetTimeoutStatus(TIMERS_Type *base)
{
    base->WDOG_INT_SET_STATUS = TIMERS_WDOG_INT_SET_STATUS_WDOG_TIMEOUT_SET_STATUS_MASK;
}

/*!
 * @brief Timer clear timeout status.
 *
 * @param base    timer base pointer.
 */
static inline void WDT_ClearTimeoutStatus(TIMERS_Type *base)
{
    base->WDOG_INT_CLR_STATUS = TIMERS_WDOG_INT_CLR_STATUS_WDOG_TIMEOUT_CLR_STATUS_MASK;
}

/*!
 * @brief WDT timeout status enable/disable.
 *
 * @param base    timer base pointer.
 * @retval true is the timer timeout, false is the timeout still not timeout.
 */
static inline bool WDT_GetTimeoutStatus(TIMERS_Type *base)
{
    return ((base->WDOG_INT_STATUS & TIMERS_WDOG_INT_STATUS_WDOG_TIMEOUT_STATUS_MASK) != 0U);
}

/*!
 * @brief WDT get wdt remain count.
 *
 * @param base    timer base pointer.
 */
static inline uint32_t WDT_GetRemainCount(TIMERS_Type *base)
{
    return base->WDOG_COUNT;
}

/*!
 * @brief Feed WDT timer.
 *
 * This is a mandatory step, if this function isn't called after enabling the WDT, WDT will
 * ignore timeout errors and will not generate a WDT interrupt or reset the chip.
 *
 * @param base WDT peripheral base address
 */
static inline void WDT_Feed(TIMERS_Type *base)
{
    base->WDOG_TIMEOUT |= TIMERS_WDOG_TIMEOUT_WDOG_KICK_MASK;
}

/*!
 * @brief WDT IRQ handler.
 *
 * Call this function in the ISR.
 *
 * @param base WDT peripheral base address
 */
void WDT_HandleIRQ(TIMERS_Type *base);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @}*/

#endif /* FSL_WDT_H_ */
