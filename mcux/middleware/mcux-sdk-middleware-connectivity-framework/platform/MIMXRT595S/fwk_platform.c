/* -------------------------------------------------------------------------- */
/*                           Copyright 2023 NXP                               */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdbool.h>

#include "fwk_platform.h"
#include "fsl_adapter_time_stamp.h"

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

static TIME_STAMP_HANDLE_DEFINE(timestampHandle);
static bool timestampInitialized = false;

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

void PLATFORM_InitTimeStamp(void)
{
    hal_time_stamp_config_t config;

    if (timestampInitialized == false)
    {
        /* Set 32k_clk for ostimer_clk. */
        CLOCK_EnableOsc32K(true);
        CLOCK_EnableClock(kCLOCK_Rtc);
        CLOCK_AttachClk(PLATFORM_OSTIMER_CLK);

        config.instance = 0;
        /* Refer to Clock Tree. */
        config.srcClock_Hz    = CLOCK_GetOsc32KFreq();
        config.clockSrcSelect = 1;

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
    /* The timestamp module always converts the timer counter to microsec
     * as the OSTIMER is a 64bits timer, the conversion can overflow after a certain counter value
     * So the timestamp module discards the 20 MSB to avoid this, so the max value of the counter is
     * 0xFFFFFFFFFFFU */
    return (uint64_t)COUNT_TO_USEC(0xFFFFFFFFFFFU, PLATFORM_OSTIMER_CLK);
}

void PLATFORM_TimeStampEnterLowPower(void)
{
    if (timestampInitialized == true)
    {
        HAL_TimeStampEnterLowpower(timestampHandle);
        CLOCK_AttachClk(kNONE_to_OSTIMER_CLK);
    }
}

void PLATFORM_TimeStampExitPowerDown(void)
{
    if (timestampInitialized == true)
    {
        CLOCK_AttachClk(PLATFORM_OSTIMER_CLK);
        HAL_TimeStampExitLowpower(timestampHandle);
    }
}
