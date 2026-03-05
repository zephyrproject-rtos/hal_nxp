/*!
 * Copyright 2021-2024, 2026 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * \file fwk_platform.c
 * \brief PLATFORM abstraction for general purpose use
 *
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>
#include <stdbool.h>

#include "fwk_config.h"
#include "fwk_platform.h"
#include "fwk_platform_rng.h"
#include "fsl_clock.h"

#if defined(gPlatformUseTimerManager_d) && (gPlatformUseTimerManager_d > 0)
#include "fsl_component_timer_manager.h"
#include "fsl_adapter_time_stamp.h"
#endif

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

#if !defined(TIMER_PORT_TYPE_MRT) && !defined(TIMER_PORT_TYPE_CTIMER)
#define TIMER_PORT_TYPE_MRT    1
#define TIMER_PORT_TYPE_CTIMER 0
#endif

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

#if defined(TIMER_PORT_TYPE_MRT) && (TIMER_PORT_TYPE_MRT > 0)
#elif defined(TIMER_PORT_TYPE_CTIMER) && (TIMER_PORT_TYPE_CTIMER > 0)
#if (PLATFORM_TM_INSTANCE == 0)
#define PLATFORM_CTIMER_CLOCK_SRC kLPOSC_to_CTIMER0
#define PLATFORM_IRQ_HANDLER
#elif (PLATFORM_TM_INSTANCE == 1)
#define PLATFORM_CTIMER_CLOCK_SRC kLPOSC_to_CTIMER1
#elif (PLATFORM_TM_INSTANCE == 2)
#define PLATFORM_CTIMER_CLOCK_SRC kLPOSC_to_CTIMER2
#elif (PLATFORM_TM_INSTANCE == 3)
#define PLATFORM_CTIMER_CLOCK_SRC kLPOSC_to_CTIMER3
#else
#error "PLATFORM_TM_INSTANCE: unsupported value."
#endif /* PLATFORM_TM_INSTANCE */
#endif /* TIMER_PORT_TYPE_MRT TIMER_PORT_TYPE_CTIMER */

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

#if defined(gPlatformUseTimerManager_d) && (gPlatformUseTimerManager_d > 0)
static TIME_STAMP_HANDLE_DEFINE(timestampHandle);
static bool timestampInitialized    = false;
static bool timerManagerInitialized = false;
#endif

#if defined(TIMER_PORT_TYPE_CTIMER) && (TIMER_PORT_TYPE_CTIMER > 0)
static const IRQn_Type s_ctimerIRQ[] = CTIMER_IRQS;
#endif

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

int PLATFORM_InitTimerManager(void)
{
    int ret = 0;
#if defined(gPlatformUseTimerManager_d) && (gPlatformUseTimerManager_d > 0)
    timer_config_t config;

    do
    {
        if (timerManagerInitialized == true)
        {
            break;
        }

        config.instance = PLATFORM_TM_INSTANCE;
#if defined(TIMER_PORT_TYPE_MRT) && (TIMER_PORT_TYPE_MRT > 0)
        config.srcClock_Hz    = SystemCoreClock;
        config.clockSrcSelect = 2U;
#elif defined(TIMER_PORT_TYPE_CTIMER) && (TIMER_PORT_TYPE_CTIMER > 0)
        CLOCK_AttachClk(PLATFORM_CTIMER_CLOCK_SRC);
        config.srcClock_Hz = CLOCK_GetCTimerClkFreq(PLATFORM_TM_INSTANCE);
        NVIC_SetPriority(s_ctimerIRQ[PLATFORM_TM_INSTANCE], ((1U << (__NVIC_PRIO_BITS)) - 1));
#endif

        if (TM_Init(&config) != kStatus_TimerSuccess)
        {
            ret = -1;
            break;
        }

        PLATFORM_InitTimeStamp();

        timerManagerInitialized = true;
    } while (false);
#endif

    return ret;
}

void PLATFORM_InitTimeStamp(void)
{
#if defined(gPlatformUseTimerManager_d) && (gPlatformUseTimerManager_d > 0)
    hal_time_stamp_config_t config;

    if (timestampInitialized == false)
    {
        CLOCK_AttachClk(kCLK32K_to_OSTIMER_CLK);

        config.instance       = 0;
        config.srcClock_Hz    = CLOCK_GetOSTimerClkFreq();
        config.clockSrcSelect = 1;

        HAL_TimeStampInit((hal_time_stamp_handle_t)timestampHandle, &config);

        timestampInitialized = true;
    }
#endif
}

uint64_t PLATFORM_GetTimeStamp(void)
{
#if defined(gPlatformUseTimerManager_d) && (gPlatformUseTimerManager_d > 0)
    return HAL_GetTimeStamp(timestampHandle);
#else
    return 0U;
#endif
}

uint64_t PLATFORM_GetMaxTimeStamp(void)
{
#if defined(gPlatformUseTimerManager_d) && (gPlatformUseTimerManager_d > 0)
    /* The timestamp module always converts the timer counter to microsec
     * as the OSTIMER is a 64bits timer, the conversion can overflow after a certain counter value
     * So the timestamp module discards the 20 MSB to avoid this, so the max value of the counter is
     * 0xFFFFFFFFFFFU */
    return (uint64_t)COUNT_TO_USEC(0xFFFFFFFFFFFU, CLOCK_GetOSTimerClkFreq());
#else
    return 0U;
#endif
}

void PLATFORM_TimeStampEnterLowPower(void)
{
#if defined(gPlatformUseTimerManager_d) && (gPlatformUseTimerManager_d > 0)
    if (timestampInitialized == true)
    {
        HAL_TimeStampEnterLowpower(timestampHandle);
        CLOCK_AttachClk(kNONE_to_OSTIMER_CLK);
    }
#endif
}

void PLATFORM_TimeStampExitPowerDown(void)
{
#if defined(gPlatformUseTimerManager_d) && (gPlatformUseTimerManager_d > 0)
    if (timestampInitialized == true)
    {
        CLOCK_AttachClk(kCLK32K_to_OSTIMER_CLK);
        HAL_TimeStampExitLowpower(timestampHandle);
    }
#endif
}

int PLATFORM_RequestRngSeed(void)
{
    /* Not implemented */
    return 1;
}

int PLATFORM_SendRngSeed(uint8_t *seed, uint16_t seed_size)
{
    /* Not implemented */
    (void)seed;
    (void)seed_size;
    return 1;
}
