/*
 * Copyright 2021-2022,2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_GPT_H_
#define FSL_GPT_H_

#include "fsl_common.h"

/*!
 * @addtogroup gpt
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief GPT driver version 2.3.0. */
#define FSL_GPT_DRIVER_VERSION (MAKE_VERSION(2, 3, 0))

/*! @brief gpt max timeout value */
#define GPT_MAX_TIMEOUT TIMERS_TIMEOUT_TIMER0_TIMEOUT_MASK

/*! @brief gpt timer id */
typedef enum _gpt_timer_id
{
    kGPT_Timer0       = 0U,    /*!< timer 0 */
    kGPT_Timer1       = 1U,    /*!< timer 1 */
    kGPT_Timer2       = 2U,    /*!< timer 2 */
    kGPT_Timer3       = 3U,    /*!< timer 3 */
    kGPT_TimerInvalid = 0xFFU, /*!< Invalid timer. */
} gpt_timer_id_t;

/*! @brief gpt timer mode */
typedef enum _gpt_timer_mode
{
    kGPT_TimerModeSingleShot        = 0U, /*!< Single shot mode */
    kGPT_TimerModeSingleFreeRunning = 1U, /*!< Free running mode */
} gpt_timer_mode_t;

/*! @brief GPT counter resolution. */
typedef enum _gpt_counter_resolution
{
    kGPT_CounterResolutionInvalid = 0U,    /*!< Invalid parameter. */
    kGPT_CounterResolution1us     = 1U,    /*!< Prescalar corresponding to 1us resolution */
    kGPT_CounterResolution2us     = 2U,    /*!< Prescalar corresponding to 2us resolution */
    kGPT_CounterResolution3us     = 3U,    /*!< Prescalar corresponding to 3us resolution */
    kGPT_CounterResolution4us     = 4U,    /*!< Prescalar corresponding to 4us resolution */
    kGPT_CounterResolution5us     = 5U,    /*!< Prescalar corresponding to 5us resolution */
    kGPT_CounterResolution1ms     = 1000U, /*!< Prescalar corresponding to 1ms resolution */
    kGPT_CounterResolutionMax,             /*!< Invalid parameter. */
} gpt_counter_resolution_t;

/*! @brief GPT Timer interface structure*/
typedef struct _gpt_timer_config
{
    uint8_t prescalerFactor; /*!< The prescalerFactor will count at system frequency and generates a tick signal used by
                                the different timers to decrement their counter. As soon as a non-zero value is loaded
                                into field PRESCALING_VALUE of the TIMERS_PRESCALER_REG, the prescaler will decrement a
                                counter at every clock cycle, starting from the prescalerFactor. Once the counter
                                reaches zero, it generates a one cycle tick signal which will be used by the timers to
                                decrement their TIMERS_[TIMER]_COUNT_REG. It will then start again counting from the
                                prescalerFactor. The prescaler will stop counting if prescalerFactor is set to 0*/
} gpt_timer_config_t;

/*! @brief Function prototype for the timers called by the GPT driver hanlder.*/
typedef void (*gpt_timer_callback_t)(void *param);

/*! @brief GPT timer manager handle. */
typedef struct _gpt_handle
{
    uint32_t timerPeriod;          /*!< Timer period. */
    gpt_timer_callback_t callback; /*!< Timer callback. */
    void *cbParam;                 /*!< Timer callback parameter. */
    gpt_timer_id_t timerID;        /*!< Timer ID. */
    bool enableInterrupt;          /*!< Enable interrupt or using polling mode. */
} gpt_handle_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name GPT Initialization and deinitialization
 * @{
 */
/*!
 * @brief Timer init.
 *
 * @param base    timer base pointer.
 * @param config  timer configuration pointer
 */
void GPT_Init(TIMERS_Type *base, const gpt_timer_config_t *config);

/*!
 * @brief Timer deinit.
 *
 * @param base    timer base pointer.
 */
void GPT_Deinit(TIMERS_Type *base);

/*! @} */

/*!
 * @name GPT functional interface
 * @{
 */

/*!
 * @brief GPT prescaler factor configuration.
 *
 * The prescalerFactor will count at system frequency and generates a tick signal used by the
 * different timers to decrement their counter. As soon as a non-zero value is loaded into
 * field PRESCALING_VALUE of the TIMERS_PRESCALER_REG, the prescaler will
 * decrement a counter at every clock cycle, starting from the prescalerFactor.
 * Once the counter reaches zero, it generates a one cycle tick signal which will be used
 * by the timers to decrement their TIMERS_[TIMERx|WDG]_COUNT_REG. It will then
 * start again counting from the prescalerFactor. The prescaler will stop counting if
 * prescalerFactor is set to 0
 *
 * @param base    timer base pointer.
 * @param prescalerFactor  The prescaler factor value.
 */
static inline void GPT_SetPrescalerFactor(TIMERS_Type *base, uint8_t prescalerFactor)
{
    base->PRESCALER = prescalerFactor;
}

/*!
 * @brief GPT get prescaler factor configuration.
 *
 * @param base    timer base pointer.
 * @retval prescalerFactor value.
 */
static inline uint8_t GPT_GetPrescalerFactor(TIMERS_Type *base)
{
    return (uint8_t)(base->PRESCALER & 0xFFU);
}

/*!
 * @brief Timer start specific timer.
 *
 * @param base    timer base pointer.
 * @param timer   the specific timer to be start.
 * @param timeoutCount the initial timeout count of the timer. The total timeout time is determined by (1 /
 * timerCountingFreq_Hz) * timeoutCount.
 */
void GPT_StartTimer(TIMERS_Type *base, gpt_timer_id_t timer, uint32_t timeoutCount);

/*!
 * @brief Timer stop specific timers.
 *
 * @param base    timer base pointer.
 * @param timer   the specific timer to be stop.
 */
void GPT_StopTimer(TIMERS_Type *base, gpt_timer_id_t timer);

/*!
 * @brief Timer set timers mode.
 *
 * @param base    timer base pointer.
 * @param timer   the specific timer to be configured.
 * @param mode    timers mode.
 */
static inline void GPT_SetTimerMode(TIMERS_Type *base, gpt_timer_id_t timer, gpt_timer_mode_t mode)
{
    base->TIMER[timer].TIMEOUT =
        (base->TIMER[timer].TIMEOUT & ~TIMERS_TIMEOUT_TIMER0_MODE_MASK) | TIMERS_TIMEOUT_TIMER0_MODE(mode);
}

/*!
 * @brief Timer timeout status enable/disable.
 *
 * @param base    timer base pointer.
 * @param timer   the specific timer to be stop.
 */
static inline void GPT_EnableTimeoutStatus(TIMERS_Type *base, gpt_timer_id_t timer)
{
    base->INT_SET_STATUS = 1UL << (uint32_t)timer;
}

/*!
 * @brief Timer clear timeout status.
 *
 * @param base    timer base pointer.
 * @param timer   the specific timer to be stop.
 */
static inline void GPT_ClearTimeoutStatus(TIMERS_Type *base, gpt_timer_id_t timer)
{
    base->INT_CLR_STATUS = 1UL << (uint32_t)timer;
}

/*!
 * @brief Timer timeout status enable/disable.
 *
 * @param base    timer base pointer.
 * @param timer   the specific timer to be stop.
 * @retval true is the timer timeout, false is the timeout still not timeout.
 */
static inline bool GPT_GetTimeoutStatus(TIMERS_Type *base, gpt_timer_id_t timer)
{
    return ((base->INT_STATUS >> (uint32_t)timer) & 1U) != 0U ? true : false;
}

/*!
 * @brief Timer timeout interrupt enable/disable.
 *
 * @param base    timer base pointer.
 * @param timer   the specific timer to be stop.
 * @param enable  true to enable the timer
 */
static inline void GPT_EnableTimeoutInterrupt(TIMERS_Type *base, gpt_timer_id_t timer, bool enable)
{
    if (enable)
    {
        base->INT_SET_ENABLE = 1UL << (uint32_t)timer;
    }
    else
    {
        base->INT_CLR_ENABLE = 1UL << (uint32_t)timer;
    }
}

/*!
 * @brief Timer get timers remain count.
 *
 * @param base    timer base pointer.
 * @param timer   the specific timer id.
 */
static inline uint32_t GPT_GetRemainCount(TIMERS_Type *base, gpt_timer_id_t timer)
{
    return base->TIMER[timer].COUNT;
}

/** @} */

/*!
 * @name GPT Timer Manager interfaces
 *
 * The Timer Manager interfaces are higher level APIs. It manage the timer channels
 * so that upper layer can require and release the channels dynamically. Also, the
 * Timer Manager interfaces manages the timer callback.
 *
 * @note Don't use Timer Manager interfaces together with the basic functional interfaces.
 *
 * @{
 */

/*!
 * @brief Initialize the GPT Timer Manager.
 *
 * Initializes the GPT registers and driver internal state.
 */
void GPT_MGR_Init(void);

/*!
 * @brief Deinitialize the GPT Timer Manager.
 *
 * Deinitialize the GPT registers and driver internal state.
 */
void GPT_MGR_Deinit(void);

/*!
 * @brief Request an available timer channel.
 *
 * @param handle The handle for the timer channel.
 * @retval kStatus_Success Requested successfully.
 * @retval kStatus_Busy Request failed because all channels are busy.
 */
status_t GPT_MGR_Request(gpt_handle_t *handle);

/*!
 * @brief Configure the timer channel.
 *
 * After configuration, call @ref GPT_MGR_Start to start the time channel.
 *
 * @param handle The handle for the timer channel.
 * @param enableInterrupt Pass true to use interrupt mode, pass false to use polling mode.
 * @param requestTime Timer period in microsecond.
 * @param callback Callback function when timer hit, only used in interrupt mode.
 * @param cbParam Parameter of the callback function.
 *
 * @retval kStatus_Success Configured successfully.
 * @retval kStatus_InvalidArgument Failed because of invalid argument.
 */
status_t GPT_MGR_Configure(
    gpt_handle_t *handle, bool enableInterrupt, uint32_t requestTime, gpt_timer_callback_t callback, void *cbParam);

/*!
 * @brief Start the timer channel.
 *
 * @param handle The handle for the timer channel.
 *
 * @retval kStatus_Success Configured successfully.
 * @retval kStatus_InvalidArgument Failed because of invalid argument.
 */
status_t GPT_MGR_Start(gpt_handle_t *handle);

/*!
 * @brief Stop the timer channel.
 *
 * If the channel works in interrupt mode, this function disables the channel interrupt too.
 *
 * @param handle The handle for the timer channel.
 *
 * @retval kStatus_Success Configured successfully.
 * @retval kStatus_InvalidArgument Failed because of invalid argument.
 */
status_t GPT_MGR_Stop(gpt_handle_t *handle);

/*!
 * @brief Restart the timer channel.
 *
 * @param handle The handle for the timer channel.
 *
 * @retval kStatus_Success Configured successfully.
 * @retval kStatus_InvalidArgument Failed because of invalid argument.
 */
status_t GPT_MGR_Restart(gpt_handle_t *handle);

/*!
 * @brief Reset the timer channel.
 *
 * @param handle The handle for the timer channel.
 *
 * @retval kStatus_Success Configured successfully.
 * @retval kStatus_InvalidArgument Failed because of invalid argument.
 */
status_t GPT_MGR_Reset(gpt_handle_t *handle);

/*!
 * @brief Release the timer channel.
 *
 * @param handle The handle for the timer channel.
 *
 * @retval kStatus_Success Configured successfully.
 * @retval kStatus_InvalidArgument Failed because of invalid argument.
 */
status_t GPT_MGR_Release(gpt_handle_t *handle);

/*!
 * @brief Checks if timer has expired in polling mode.
 *
 * @param handle The handle for the timer channel.
 *
 * @retval kStatus_Success Timer expired.
 * @retval kStatus_Busy Timer is still running.
 * @retval kStatus_InvalidArgument Failed because of invalid argument.
 */
status_t GPT_MGR_Poll(gpt_handle_t *handle);

/*!
 * @brief Checks if timer is in used.
 *
 * @param handle The handle for the timer channel.
 *
 * @return Return true if the channel is free, otherwise returns false.
 */
bool GPT_MGR_IsFree(gpt_handle_t *handle);

/*!
 * @brief Change the prescaler to change the timer counter resolution.
 *
 * @param resolution The new resolution to set.
 *
 * @retval kStatus_Success Configured successfully.
 * @retval kStatus_Busy Could not change the resolution because some channels are running.
 * @retval kStatus_InvalidArgument Failed because of invalid argument.
 */
status_t GPT_MGR_ChangeCounterResolution(gpt_counter_resolution_t resolution);
/*!
 * @brief check for the timer allocation.
 *
 * @param handle The handle for the timer channel.
 *
 * @return Return true if the channel is free, otherwise returns false.
 */
static bool GPT_MGR_IsAllocated(gpt_handle_t *handle);

/*!
 * @brief Get current timer counter resolution.
 *
 * @return Current resolution.
 */
gpt_counter_resolution_t GPT_MGR_GetCounterResolution(void);

/** @} */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */

#endif /* FSL_GPT_H_*/
