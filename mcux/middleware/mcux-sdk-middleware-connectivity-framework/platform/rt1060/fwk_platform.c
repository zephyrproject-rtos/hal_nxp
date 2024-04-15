/* -------------------------------------------------------------------------- */
/*                             Copyright 2023 NXP                             */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "fwk_platform.h"
#include "fsl_adapter_time_stamp.h"
#include "fsl_clock.h"

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

static TIME_STAMP_HANDLE_DEFINE(timestampHandle);
static volatile bool timerManagerInitialized = false;
static volatile bool timestampInitialized    = false;

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

timer_status_t PLATFORM_InitTimerManager(void)
{
    /* Initialize timer manager */
    timer_config_t timerConfig;
    timer_status_t status;

    if (timerManagerInitialized == false)
    {
        timerConfig.instance    = PLATFORM_TM_INSTANCE;
        timerConfig.srcClock_Hz = CLOCK_GetFreq(kCLOCK_OscClk);

        status = TM_Init(&timerConfig);
        if (status == kStatus_TimerSuccess)
        {
            timerManagerInitialized = true;
        }
    }
    return status;
}

void PLATFORM_DeinitTimerManager(void)
{
    if (timerManagerInitialized == true)
    {
        TM_Deinit();
        timerManagerInitialized = false;
    }
}

void PLATFORM_InitTimeStamp(void)
{
    hal_time_stamp_config_t config;

    if (timestampInitialized == false)
    {
        config.instance    = 0U;
        config.srcClock_Hz = CLOCK_GetPerClkFreq();

        HAL_TimeStampInit(timestampHandle, &config);

        timestampInitialized = true;
    }
}

uint64_t PLATFORM_GetTimeStamp(void)
{
    return HAL_GetTimeStamp(timestampHandle);
}

uint64_t PLATFORM_GetMaxTimeStamp(void)
{
    /* The timestamp module always converts the timer counter to microsec. As the GPT is a 32bits timer,
     * and the calculations are 64 bit, no overflow is to be taken into account */
    return (uint64_t)COUNT_TO_USEC(~0UL, CLOCK_GetPerClkFreq());
}
