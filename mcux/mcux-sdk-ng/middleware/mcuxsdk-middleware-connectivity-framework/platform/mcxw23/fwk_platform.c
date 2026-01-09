/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */
#include "fsl_common.h"
#include "fsl_rom_api.h"
#include "fsl_trng.h"
#include "fsl_power.h"
#include "fsl_component_timer_manager.h"
#include "fwk_platform.h"
#ifdef TIMER_PORT_TYPE_CTIMER
#include "fsl_ctimer.h"
#else
#include "fsl_ostimer.h"
#endif /* TIMER_PORT_TYPE_CTIMER */
#include "fwk_platform_ics.h"
/* -------------------------------------------------------------------------- */
/*                                 Definitions                                */
/* -------------------------------------------------------------------------- */
#ifdef TIMER_PORT_TYPE_CTIMER
#ifndef SOC_CTIMER_INSTANCE
#define SOC_CTIMER_INSTANCE 0U
#define SOC_CTIMER_BASE     CTIMER0
#endif
#else
#ifndef SOC_OSTIMER_INSTANCE
#define SOC_OSTIMER_INSTANCE 0U
#define SOC_OSTIMER_BASE     OSTIMER
#endif
#endif /* TIMER_PORT_TYPE_CTIMER */

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

#ifdef TIMER_PORT_TYPE_CTIMER
int PLATFORM_InitTimerManager(void)
{
    /*Initialize timer manager*/
    timer_config_t timerConfig;
    timer_status_t status;
    static int     timer_manager_initialized = 0;

    if (timer_manager_initialized == 0)
    {
        timerConfig.instance              = SOC_CTIMER_INSTANCE;
        timerConfig.srcClock_Hz           = CLOCK_GetCTimerClkFreq(SOC_CTIMER_INSTANCE);
        timerConfig.clockSrcSelect        = 0;
        timerConfig.hardwareTimerAlwaysOn = true;

        status = TM_Init(&timerConfig);
        assert_equal(kStatus_TimerSuccess, status);
        (void)status;
        timer_manager_initialized = 1;
    }

    return 0;
}
#else
int PLATFORM_InitTimerManager(void)
{
    /*Initialize timer manager*/
    timer_config_t timerConfig;
    timer_status_t status;
    static int     timer_manager_initialized = 0;

    if (timer_manager_initialized == 0)
    {
        timerConfig.instance              = SOC_OSTIMER_INSTANCE;
        timerConfig.srcClock_Hz           = CLOCK_GetOSTimerClkFreq();
        timerConfig.clockSrcSelect        = 0;
        timerConfig.hardwareTimerAlwaysOn = true;
#if SOC_OSTIMER_INSTANCE == 0U
#else  /* SOC_OSTIMER_INSTANCE */
#error Adapt the IRQn to match the OSTIMER instance
#endif /* SOC_OSTIMER_INSTANCE */

        status = TM_Init(&timerConfig);
        assert_equal(kStatus_TimerSuccess, status);
        (void)status;
        timer_manager_initialized = 1;
    }

    return 0;
}
#endif /*TIMER_PORT_TYPE_CTIMER*/

uint64_t PLATFORM_GetTimeStamp(void)
{
#ifdef TIMER_PORT_TYPE_CTIMER
    return (uint64_t)(CTIMER_GetTimerCountValue(SOC_CTIMER_BASE) / CLOCK_GetCTimerClkFreq(0));
#else

    return (uint64_t)(OSTIMER_GetCurrentTimerValue(SOC_OSTIMER_BASE) / CLOCK_GetOSTimerClkFreq());
#endif /* TIMER_PORT_TYPE_CTIMER */
}

uint64_t PLATFORM_GetMaxTimeStamp(void)
{
#ifdef TIMER_PORT_TYPE_CTIMER
    return (uint32_t)COUNT_TO_USEC((((uint64_t)1 << 32) - 1), CLOCK_GetCTimerClkFreq(0));
#else
    return (uint64_t)COUNT_TO_USEC((((uint64_t)1 << 42) - 1), CLOCK_GetOSTimerClkFreq());
#endif /* TIMER_PORT_TYPE_CTIMER */
}

void PLATFORM_Delay(uint64_t delayUs)
{
    SDK_DelayAtLeastUs((uint32_t)delayUs, SystemCoreClock);
}

void PLATFORM_GetMCUUid(uint8_t *aOutUid16B, uint8_t *pOutLen)
{
    flash_config_t flashInstance;
    status_t       status;

    status = FLASH_Init(&flashInstance);
    assert_equal(status, kStatus_Success);

    if (status == kStatus_Success)
    {
        status = FFR_GetUUID(&flashInstance, aOutUid16B);
        assert_equal(status, kStatus_Success);
        *pOutLen = 16;
    }
}

void PLATFORM_ResetCpu(void)
{
    POWER_Reset();
}

int PLATFORM_SendRngSeed(uint8_t *seed, uint16_t seed_size)
{
    /* Not implemented */
    (void)seed;
    (void)seed_size;
    return 1;
}

int PLATFORM_RequestRngSeed(void)
{
    /* Not implemented */
    return 1;
}

void PLATFORM_RemoteActiveReq(void)
{
    /* Not implemented */
}

void PLATFORM_RemoteActiveRel(void)
{
    /* Not implemented */
}

void PLATFORM_RegisterNbuTemperatureRequestEventCb(nbu_temp_req_event_callback_t cb)
{
    /* Not implemented */
    (void)cb;
}

int PLATFORM_InitCrypto(void)
{
    /* Not implemented */
    return 0;
}

int PLATFORM_TerminateCrypto(void)
{
    /* Not implemented */
    return 0;
}

int PLATFORM_ResetCrypto(void)
{
    /* Not implemented */
    return 0;
}
