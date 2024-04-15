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
#include "fsl_gpt.h"

/* -------------------------------------------------------------------------- */
/*                               Private definitions                          */
/* -------------------------------------------------------------------------- */
#define GPT_INDEX(x) ((x)-1u)

#ifndef TIMESTAMP_GPT_INST
/* Unless otherwise defined, allocate GPT6 arbitrarily among the 6 GPT instances
 * for the CM7 core timestamp.
 */
#define TIMESTAMP_GPT_INST GPT_INDEX(6)
#endif

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
        config.instance       = TIMESTAMP_GPT_INST;
        config.srcClock_Hz    = 32768U; /* 32kHz */
        config.clockSrcSelect = kGPT_ClockSource_LowFreq;

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
    return (uint64_t)COUNT_TO_USEC(~0UL, 32768U);
}