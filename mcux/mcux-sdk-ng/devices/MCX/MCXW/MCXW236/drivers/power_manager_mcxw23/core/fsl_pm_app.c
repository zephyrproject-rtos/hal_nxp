/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_pm_app.h"
#include "fsl_pm_core.h"
#include "fsl_pm_device.h"
#include "fsl_debug_console.h"
#ifdef SDK_OS_FREE_RTOS
#include "task.h"
#endif /* SDK_OS_FREE_RTOS */

static uint32_t s_initialSysTickLoad = 0;
static uint64_t s_systickStopTimeUs  = 0;

static uint32_t s_smallestHeadroom    = 0xffffffff;
static uint32_t s_lastPrintedHeadroom = 0xffffffff;

void PMAPP_Init(uint32_t initialTickLoad)
{
    s_initialSysTickLoad = initialTickLoad;
}

status_t PMAPP_EnterLowPower(uint32_t sleepDuration)
{
    status_t status             = kStatus_Success;
    pm_mode_t sleepMode         = kPM_Mode_Sleep;
    uint64_t expectedWakeUpTime = 0;

    /* The sleep timer is used to measure how long the system was asleep */
    PMDEVICE_StartSleepTimer();

    /* Capture the time at which the systick timer is stopped */
    s_systickStopTimeUs = PMDEVICE_GetSleepTimer();

#ifdef SDK_OS_FREE_RTOS
    /* Disable Systicks for tickless mode */
    SysTick->CTRL &= ~(SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk);
#endif /* SDK_OS_FREE_RTOS */

    /* Calculate the expected wake up time */
    expectedWakeUpTime = s_systickStopTimeUs + sleepDuration;

    /* Now enter low power mode till the first event, being OS or radio. */
    status = PM_EnterLowPower(expectedWakeUpTime, &sleepMode);
    assert_equal(status, kStatus_Success);

    /* Did we enter another mode than sleep? */
    if (sleepMode != kPM_Mode_Sleep)
    {
        /* Yes, check whether the system woke up in time. In sleep mode this check is not
         * needed as the system immediately resumes when the interrupt happens. Therefore,
         * the system will not use a wake up timer and hence we would always fail below
         * check */
        uint64_t currentTime = PMDEVICE_GetSleepTimer();

        int32_t wakeupHeadroom = (int32_t)((int64_t)expectedWakeUpTime - (int64_t)currentTime);

        if (wakeupHeadroom < 0)
        {
            PRINTF("Wake up too late by %d us\n", -wakeupHeadroom);
            assert(false);
        }
        else if (wakeupHeadroom < s_smallestHeadroom)
        {
            s_smallestHeadroom = wakeupHeadroom;
        }
    }
#ifdef SDK_OS_FREE_RTOS
    uint32_t systickValue;
    uint64_t systickRestartTimeUs;

    /* Assert if the initial systick load has not been initialized */
    assert(s_initialSysTickLoad != 0);

    /* Use the sleep timer to check how long systick was suspended */
    systickRestartTimeUs = PMDEVICE_GetSleepTimer();

    /* Calculate the new systick value after low power mode */
    /* Systick is counting down. Convert the value */
    systickValue = s_initialSysTickLoad - SysTick->VAL;
    /* And add the time it was stopped */

    systickValue +=
        (uint64_t)(systickRestartTimeUs - s_systickStopTimeUs) * (uint32_t)(CLOCK_GetCoreSysClkFreq() / 1000000);

    uint32_t correction = systickValue / s_initialSysTickLoad;
    /* Inform OS about the skipped OS ticks */
    vTaskStepTick(correction);

    /* Adjust the phase of systick. SysTick->VAL does not accept any value other than 0.
     * Hence, LOAD is manipulated to adjust the phase. It is restored to the
     * correct value in the SysTick ISR */
    SysTick->LOAD = MAX(1, s_initialSysTickLoad - (systickValue % s_initialSysTickLoad) - 1);
    SysTick->VAL  = 0;

    /* Re-enable systicks before releasing interrupts in case an interrupt fires
     * directly, otherwise we could loose some precision */
    SysTick->CTRL |= (SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk);
#else
    (void)s_initialSysTickLoad;
#endif /* SDK_OS_FREE_RTOS */

    return status;
}

void PMAPP_PrintSmallestHeadroom(void)
{
    if (s_lastPrintedHeadroom != s_smallestHeadroom)
    {
        PRINTF("Smallest headroom after wake up: %u\n", s_smallestHeadroom);
        s_lastPrintedHeadroom = s_smallestHeadroom;
    }
}
