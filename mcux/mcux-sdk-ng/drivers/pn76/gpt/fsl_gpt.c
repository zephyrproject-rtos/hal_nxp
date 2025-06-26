/*
 * Copyright 2021-2022,2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_gpt.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.pn_gpt"
#endif
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define GPT_CLOCK_FREQ_MHZ (CLOCK_GetGptClkFreq(0) / 1000000UL)

#define GPT_MGR_TIMER s_gptBases[0]

#define GPT_TIMER_COUNT_MAX (TIMERS_TIMEOUT_TIMER0_TIMEOUT_MASK >> TIMERS_TIMEOUT_TIMER0_TIMEOUT_SHIFT)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
static TIMERS_Type *const s_gptBases[] = TIMERS_BASE_PTRS;

static bool s_isGptTimerAvailable[FSL_FEATURE_GPT_NUMBER_OF_TIMERS];

static gpt_handle_t *s_gptHandles[FSL_FEATURE_GPT_NUMBER_OF_TIMERS];

static gpt_counter_resolution_t s_gptCounterResolution;

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * brief Timer init.
 *
 * param base    timer base pointer.
 * param config  timer configuration pointer
 */
void GPT_Init(TIMERS_Type *base, const gpt_timer_config_t *config)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* enable clock for this block, but do not disable */
    CLOCK_EnableClock(kCLOCK_Timer);
#endif

    if (config != NULL)
    {
        /* prescaler factor configuration */
        GPT_SetPrescalerFactor(base, config->prescalerFactor);
    }
}

/*!
 * brief Timer deinit.
 *
 * param base    timer base pointer.
 */
void GPT_Deinit(TIMERS_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* enable clock for this block, but do not disable */
    CLOCK_DisableClock(kCLOCK_Timer);
#endif
}

/*!
 * brief Timer start specific timers.
 *
 * param base    timer base pointer.
 * param timer   the specific timer to be start.
 * @param timeoutCount the initial timeout count of the timer. The total timeout time is determined by (1 /
 * timerCountingFreq_Hz) * timeoutCount.
 */
void GPT_StartTimer(TIMERS_Type *base, gpt_timer_id_t timer, uint32_t timeoutCount)
{
    assert((timeoutCount & (~TIMERS_TIMEOUT_TIMER0_TIMEOUT_MASK)) == 0U);
    /* as soon as the timeout value is load, the timer will start count */
    base->TIMER[timer].TIMEOUT = (base->TIMER[timer].TIMEOUT & ~TIMERS_TIMEOUT_TIMER0_TIMEOUT_MASK) |
                                 TIMERS_TIMEOUT_TIMER0_TIMEOUT(timeoutCount);
}

/*!
 * brief Timer stop specific timers.
 *
 * param base    timer base pointer.
 * param timer   the specific timer to be stop.
 */
void GPT_StopTimer(TIMERS_Type *base, gpt_timer_id_t timer)
{
    /* stop the timer firstly */
    base->TIMER[timer].TIMEOUT = 0U;
    /* disable interrupt and status */
    GPT_EnableTimeoutInterrupt(base, timer, false);
    GPT_ClearTimeoutStatus(base, timer);
}

/*
 * brief Initialize the GPT Timer Manager.
 *
 * Initializes the GPT registers and driver internal state.
 */
void GPT_MGR_Init(void)
{
    CLOCK_EnableClock(kCLOCK_Timer);

    for (uint32_t i = 0U; i < (uint32_t)FSL_FEATURE_GPT_NUMBER_OF_TIMERS; i++)
    {
        s_isGptTimerAvailable[i] = true;
        s_gptHandles[i]          = NULL;
    }

    GPT_SetPrescalerFactor(GPT_MGR_TIMER,
                           (uint8_t)(uint32_t)((uint32_t)kGPT_CounterResolution1us * GPT_CLOCK_FREQ_MHZ));

    NVIC_ClearPendingIRQ(GPT_IRQn);
    (void)EnableIRQ(GPT_IRQn);

    s_gptCounterResolution = kGPT_CounterResolution1us;
}

/*
 * brief Deinitialize the GPT Timer Manager.
 *
 * Deinitialize the GPT registers and driver internal state.
 */
void GPT_MGR_Deinit(void)
{
    NVIC_ClearPendingIRQ(GPT_IRQn);
    (void)DisableIRQ(GPT_IRQn);

    s_gptCounterResolution = kGPT_CounterResolutionInvalid;

    for (uint32_t i = 0U; i < (uint32_t)FSL_FEATURE_GPT_NUMBER_OF_TIMERS; i++)
    {
        s_isGptTimerAvailable[i] = false;
        s_gptHandles[i]          = NULL;
    }
}

/*
 * brief Request an available timer channel.
 *
 * param handle The handle for the timer channel.
 * retval kStatus_Success Requested successfully.
 * retval kStatus_Busy Request failed because all channels are busy.
 */
status_t GPT_MGR_Request(gpt_handle_t *handle)
{
    status_t status = kStatus_Busy;

    for (uint32_t i = 0U; i < (uint32_t)FSL_FEATURE_GPT_NUMBER_OF_TIMERS; i++)
    {
        if (s_isGptTimerAvailable[i])
        {
            s_isGptTimerAvailable[i] = false;

            s_gptHandles[i] = handle;
            handle->timerID = (gpt_timer_id_t)i;
            status          = kStatus_Success;
            break;
        }
    }

    return status;
}

/*
 * brief Configure the timer channel.
 *
 * After configuration, call ref GPT_MGR_Start to start the time channel.
 *
 * param handle The handle for the timer channel.
 * param enableInterrupt Pass true to use interrupt mode, pass false to use polling mode.
 * param requestTime Timer period in microsecond.
 * param callback Callback function when timer hit, only used in interrupt mode.
 * param cbParam Parameter of the callback function.
 *
 * retval kStatus_Success Configured successfully.
 * retval kStatus_InvalidArgument Failed because of invalid argument.
 */
status_t GPT_MGR_Configure(
    gpt_handle_t *handle, bool enableInterrupt, uint32_t requestTime, gpt_timer_callback_t callback, void *cbParam)
{
    if (GPT_MGR_IsAllocated(handle) != true)
    {
        return kStatus_InvalidArgument;
    }
    /* Do checking of parameters here */
    if ((s_gptCounterResolution == kGPT_CounterResolutionInvalid) || (handle->timerID > kGPT_Timer3) ||
        (requestTime > ((uint8_t)s_gptCounterResolution * GPT_TIMER_COUNT_MAX)))
    {
        return kStatus_InvalidArgument;
    }
    else
    {
        handle->enableInterrupt = enableInterrupt;

        if (enableInterrupt)
        {
            if (callback != NULL)
            {
                handle->callback = callback;
                handle->cbParam  = cbParam;
            }
            else
            {
                return kStatus_InvalidArgument;
            }
        }

        handle->timerPeriod = (requestTime / (uint8_t)s_gptCounterResolution);

        return kStatus_Success;
    }
}

/*
 * brief Start the timer channel.
 *
 * param handle The handle for the timer channel.
 *
 * retval kStatus_Success Configured successfully.
 * retval kStatus_InvalidArgument Failed because of invalid argument.
 */
status_t GPT_MGR_Start(gpt_handle_t *handle)
{
    status_t status;
    gpt_timer_id_t timerID = handle->timerID;

    if (GPT_MGR_IsAllocated(handle) != true)
    {
        return kStatus_InvalidArgument;
    }
    if (timerID > kGPT_Timer3)
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
        GPT_ClearTimeoutStatus(GPT_MGR_TIMER, timerID);

        GPT_MGR_TIMER->TIMER[timerID].TIMEOUT = handle->timerPeriod;

        if (handle->enableInterrupt)
        {
            GPT_EnableTimeoutInterrupt(GPT_MGR_TIMER, timerID, true);
        }
        else
        {
            /* for polling mode, wait until the timer is actually started */
            while (0U == GPT_GetRemainCount(GPT_MGR_TIMER, timerID))
            {
            }
        }

        status = kStatus_Success;
    }

    return status;
}

/*
 * brief Stop the timer channel.
 *
 * If the channel works in interrupt mode, this function disables the channel interrupt too.
 *
 * param handle The handle for the timer channel.
 *
 * retval kStatus_Success Configured successfully.
 * retval kStatus_InvalidArgument Failed because of invalid argument.
 */
status_t GPT_MGR_Stop(gpt_handle_t *handle)
{
    status_t status;
    gpt_timer_id_t timerID = handle->timerID;
    if (GPT_MGR_IsAllocated(handle) != true)
    {
        return kStatus_InvalidArgument;
    }

    if (timerID > kGPT_Timer3)
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
        GPT_ClearTimeoutStatus(GPT_MGR_TIMER, timerID);
        GPT_EnableTimeoutInterrupt(GPT_MGR_TIMER, timerID, false);
        GPT_MGR_TIMER->TIMER[(uint32_t)timerID].TIMEOUT = 0U;

        status = kStatus_Success;
    }

    return status;
}

/*
 * brief Restart the timer channel.
 *
 * param handle The handle for the timer channel.
 *
 * retval kStatus_Success Configured successfully.
 * retval kStatus_InvalidArgument Failed because of invalid argument.
 */
status_t GPT_MGR_Restart(gpt_handle_t *handle)
{
    status_t status;

    status = GPT_MGR_Stop(handle);

    if (kStatus_Success == status)
    {
        status = GPT_MGR_Start(handle);
    }

    return status;
}

/*
 * brief Reset the timer channel.
 *
 * param handle The handle for the timer channel.
 *
 * retval kStatus_Success Configured successfully.
 * retval kStatus_InvalidArgument Failed because of invalid argument.
 */
status_t GPT_MGR_Reset(gpt_handle_t *handle)
{
    status_t status;

    if (handle->timerID > kGPT_Timer3)
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
        s_isGptTimerAvailable[(uint32_t)handle->timerID] = true;
        handle->timerID                                  = kGPT_TimerInvalid;

        status = kStatus_Success;
    }

    return status;
}

/*
 * brief Release the timer channel.
 *
 * param handle The handle for the timer channel.
 *
 * retval kStatus_Success Configured successfully.
 * retval kStatus_InvalidArgument Failed because of invalid argument.
 */
status_t GPT_MGR_Release(gpt_handle_t *handle)
{
    if (GPT_MGR_IsAllocated(handle) != true)
    {
        return kStatus_InvalidArgument;
    }
    else
    {
        return GPT_MGR_Reset(handle);
    }
}

/*
 * brief Checks if timer has expired in polling mode.
 *
 * param handle The handle for the timer channel.
 *
 * retval kStatus_Success Timer expired.
 * retval kStatus_Busy Timer is still running.
 * retval kStatus_InvalidArgument Failed because of invalid argument.
 */
status_t GPT_MGR_Poll(gpt_handle_t *handle)
{
    status_t status;

    if (GPT_MGR_IsAllocated(handle) != true)
    {
        return kStatus_InvalidArgument;
    }
    if (handle->timerID > kGPT_Timer3)
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
        if (0U != GPT_GetRemainCount(GPT_MGR_TIMER, handle->timerID))
        {
            status = kStatus_Busy;
        }
        else
        {
            status = kStatus_Success;
        }
    }

    return status;
}

/*
 * brief Checks if timer is in used.
 *
 * param handle The handle for the timer channel.
 *
 * return Return true if the channel is free, otherwise returns false.
 */
bool GPT_MGR_IsFree(gpt_handle_t *handle)
{
    if (GPT_MGR_IsAllocated(handle) != true)
    {
        return kStatus_InvalidArgument;
    }

    else
    {
        return (handle->timerID > kGPT_Timer3) ? true : s_isGptTimerAvailable[(uint32_t)handle->timerID];
    }
}

/*
 * brief Change the prescaler to change the timer counter resolution.
 *
 * param resolution The new resolution to set.
 *
 * retval kStatus_Success Configured successfully.
 * retval kStatus_Busy Could not change the resolution because some channels are running.
 * retval kStatus_InvalidArgument Failed because of invalid argument.
 */
status_t GPT_MGR_ChangeCounterResolution(gpt_counter_resolution_t resolution)
{
    status_t status;

    if ((resolution >= kGPT_CounterResolutionMax) || (resolution == kGPT_CounterResolutionInvalid))
    {
        status = kStatus_InvalidArgument;
    }
    else if (!(s_isGptTimerAvailable[0] && s_isGptTimerAvailable[1] && s_isGptTimerAvailable[2] &&
               s_isGptTimerAvailable[3]))
    {
        status = kStatus_Busy;
    }
    else
    {
        GPT_SetPrescalerFactor(GPT_MGR_TIMER, (uint8_t)(uint32_t)((uint32_t)resolution * GPT_CLOCK_FREQ_MHZ));

        s_gptCounterResolution = resolution;
        status                 = kStatus_Success;
    }

    return status;
}

/*
 * brief Checks if timer is in allocated.
 *
 * param handle The handle for the timer channel.
 *
 * return Return true if the channel is Allocated, otherwise returns false.
 */
static bool GPT_MGR_IsAllocated(gpt_handle_t *handle)
{
    if ((s_gptHandles[0] == handle) || (s_gptHandles[1] == handle) || (s_gptHandles[2] == handle) ||
        (s_gptHandles[3] == handle))
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*
 * brief Get current timer counter resolution.
 *
 * return Current resolution.
 */
gpt_counter_resolution_t GPT_MGR_GetCounterResolution(void)
{
    return s_gptCounterResolution;
}

void GPT_DriverIRQHandler(void);
void GPT_DriverIRQHandler(void)
{
    /* Read the IRQ status register */
    uint32_t irqStatus = GPT_MGR_TIMER->INT_STATUS;

    /* Clear the interrupts */
    GPT_MGR_TIMER->INT_CLR_STATUS = irqStatus;

    /* Mask the interrupts with enable register */
    irqStatus &= GPT_MGR_TIMER->INT_ENABLE;

    for (uint32_t i = 0UL; i < (uint32_t)FSL_FEATURE_GPT_NUMBER_OF_TIMERS; i++)
    {
        if ((0UL != (irqStatus & (1UL << i))) && (NULL != s_gptHandles[i]->callback))
        {
            s_gptHandles[i]->callback(s_gptHandles[i]->cbParam);
        }
    }
}
