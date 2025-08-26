/*
 * Copyright 2018-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_component_timer_manager.h"
#include "fsl_adapter_timer.h"
#if (defined(TM_ENABLE_TIME_STAMP) && (TM_ENABLE_TIME_STAMP > 0U))
#include "fsl_adapter_time_stamp.h"
#endif

/*
 * The OSA_USED macro can only be defined when the OSA component is used.
 * If the source code of the OSA component does not exist, the OSA_USED cannot be defined.
 * OR, If OSA component is not added into project event the OSA source code exists, the OSA_USED
 * also cannot be defined.
 * The source code path of the OSA component is <MCUXpresso_SDK>/components/osa.
 *
 */
#if defined(OSA_USED)
#include "fsl_os_abstraction.h"
#if (defined(TM_COMMON_TASK_ENABLE) && (TM_COMMON_TASK_ENABLE > 0U))
#include "fsl_component_common_task.h"
#endif
#endif

#if defined(OSA_USED)
#if (defined(USE_RTOS) && (USE_RTOS > 0U))
#define TIMER_ENTER_CRITICAL() \
    OSA_SR_ALLOC();            \
    OSA_ENTER_CRITICAL()
#define TIMER_EXIT_CRITICAL() OSA_EXIT_CRITICAL()
#else
#define TIMER_ENTER_CRITICAL()
#define TIMER_EXIT_CRITICAL()
#endif
#else
#define TIMER_ENTER_CRITICAL() uint32_t regPrimask = DisableGlobalIRQ();
#define TIMER_EXIT_CRITICAL()  EnableGlobalIRQ(regPrimask);
#endif

/*****************************************************************************
******************************************************************************
* Private macros
******************************************************************************
*****************************************************************************/
#define mTmrDummyEvent_c (1UL << 16U)

#ifndef PROCESSING_TIME_UPDATE_MATCH_US
#define PROCESSING_TIME_UPDATE_MATCH_US \
    (200U +                             \
     50U) /* Value defined by measuring HAL_TimerUpdateMatchValueInTicks using fsl_adapter_ostimer, added 50 us margin */
#endif

/**@brief Timer status. */
typedef enum _timer_state
{
    kTimerStateFree_c     = 0x00, /**< The timer free status. */
    kTimerStateActive_c   = 0x01, /**< The timer active status. */
    kTimerStateReady_c    = 0x02, /**< The timer ready status. */
    kTimerStateInactive_c = 0x04, /**< The timer inactive status. */
    kTimerStateMask_c     = 0x07, /**< The timer status mask all. */
    kTimerModeMask_c      = 0x3F, /**< The timer mode mask all. */
} timer_state_t;

/*****************************************************************************
******************************************************************************
* Private type definitions
******************************************************************************
*****************************************************************************/
/*! @brief Timer handle structure for timer manager. */
typedef struct _timer_handle_struct_t
{
    struct _timer_handle_struct_t *next; /*!< LIST_ element of the link */
    volatile uint8_t tmrStatus;          /*!< Software timer status */
    volatile uint8_t tmrType;            /*!< Software timer mode*/
    hal_timer_time_t intervalInTicks;            /*!< The timer interval for recurring software timers */
    hal_timer_time_t scheduledTimeInTicks;       /*!< The scheduled software timer expiration time */
    timer_callback_t pfCallBack;         /*!< Callback function of the software timer */
    void *param;                         /*!< Parameter of callback function of the software timer */
} timer_handle_struct_t;
/*! @brief State structure for timer manager. */
typedef struct _timermanager_state
{
    timer_handle_struct_t *timerHead;    /*!< Timer list head */
    TIMER_HANDLE_DEFINE(halTimerHandle); /*!< Timer handle buffer */
#if (defined(TM_ENABLE_TIME_STAMP) && (TM_ENABLE_TIME_STAMP > 0U))
    TIME_STAMP_HANDLE_DEFINE(halTimeStampHandle); /*!< Time stamp handle buffer */
#endif
#if defined(OSA_USED)
#if (defined(TM_COMMON_TASK_ENABLE) && (TM_COMMON_TASK_ENABLE > 0U))
    common_task_message_t mTimerCommontaskMsg; /*!< Timer common_task message */
#else
    OSA_SEMAPHORE_HANDLE_DEFINE(halTimerTaskSemaphoreHandle); /*!< Task semaphore handle buffer */
    OSA_TASK_HANDLE_DEFINE(timerTaskHandle);                  /*!< Timer task id */
#endif
#endif
    volatile uint8_t numberOfActiveTimers;         /*!< Number of active software Timers*/
    volatile uint8_t numberOfLowPowerActiveTimers; /*!< Number of low power active software Timers */
    volatile uint8_t hardwareTimerIsRunning;       /*!< Underlying hardware timer is running */
    uint8_t initialized;                           /*!< Timer manager's underlying timer is initialized */
    bool hardwareTimerAlwaysOn;                    /*!< Timer manager's underlying timer is always on */
    uint32_t hardwareTimerClockHz;                 /*!< Timer manager's underlying timer clock frequency */
    uint32_t updateMatchProcTimeTicks; /*!< The time it takes to execute the HAL_TimerUpdateMatchValueInTicks function */
} timermanager_state_t;

/*****************************************************************************
******************************************************************************
* Public memory declarations
******************************************************************************
*****************************************************************************/

/*****************************************************************************
 *****************************************************************************
 * Private prototypes
 *****************************************************************************
 *****************************************************************************/

/*! -------------------------------------------------------------------------
 * \brief Function called by driver ISR on channel match in interrupt context.
 *---------------------------------------------------------------------------*/
static void HAL_TIMER_Callback(void *param);

/*! -------------------------------------------------------------------------
 * \brief     Timer thread.
 *            Called by the kernel when the timer ISR posts a timer event.
 * \param[in] param - User parameter to timer thread; not used.
 *---------------------------------------------------------------------------*/
static void TimerManagerTask(void *param);

static void TimerActivate(timer_handle_t timerHandle);

static timer_status_t TimerStop(timer_handle_t timerHandle);

/*****************************************************************************
 *****************************************************************************
 * Private memory definitions
 *****************************************************************************
 *****************************************************************************/
static timermanager_state_t s_timermanager = {0};
/*****************************************************************************
******************************************************************************
* Private API macro define
******************************************************************************
*****************************************************************************/

#define IncrementActiveTimerNumber(type)                                                                     \
    ((((type) & (uint8_t)kTimerModeLowPowerTimer) != 0U) ? (++s_timermanager.numberOfLowPowerActiveTimers) : \
                                                           (++s_timermanager.numberOfActiveTimers))
#define DecrementActiveTimerNumber(type)                                                                     \
    ((((type) & (uint8_t)kTimerModeLowPowerTimer) != 0U) ? (--s_timermanager.numberOfLowPowerActiveTimers) : \
                                                           (--s_timermanager.numberOfActiveTimers))

/*
 * \brief Detect if the timer is a low-power timer
 */
#define IsLowPowerTimer(type) ((type) & (uint8_t)kTimerModeLowPowerTimer)

#if defined(OSA_USED)
#if (defined(TM_COMMON_TASK_ENABLE) && (TM_COMMON_TASK_ENABLE > 0U))

#else
/*
 * \brief Defines the timer thread's stack
 */
static OSA_TASK_DEFINE(TimerManagerTask, TM_TASK_PRIORITY, 1, TM_TASK_STACK_SIZE, false);
#endif
#endif

/*****************************************************************************
******************************************************************************
* Private functions
******************************************************************************
*****************************************************************************/
/*!-------------------------------------------------------------------------
 * \brief     Checks whether a is greater than b.
 *
 * This function checks whether a is greater than b, taking wrapping into account only for 32 bit timers.
 * \param[in] a the first argument
 * \param[in] b the second argument
 * \return    1 when a>b else 0
 *---------------------------------------------------------------------------*/
static uint8_t IsGreaterThan(hal_timer_time_t a, hal_timer_time_t b)
{
    uint8_t resolution = HAL_TIMER_RANGE_IN_BITS;

    if (resolution == 32)
    {
        /* Take into account wrapping for 32 bit counters */
        return ((uint32_t)b - (uint32_t)a > (1U << 31));
    }
    else if (resolution == 42)
    {
        /* Assume 42bit timer will never wrap */
        return a > b;
    }
    else
    {
        /* Other resolutions are not supported by this function */
        assert(false);
        return 0;
    }
}

/*!-------------------------------------------------------------------------
 * \brief     Returns the mask of the timer resolution
 * \return    the mask of the timer resolution
 *---------------------------------------------------------------------------*/
static hal_timer_time_t GetTimerResolutionMask(void)
{
    return (((uint64_t)1 << HAL_TIMER_RANGE_IN_BITS) - 1);
}

/*!-------------------------------------------------------------------------
 * \brief     Computes the first value after a timer wrap-around based on its resolution in ticks.
 * \details   This function determines the smallest timer value after an overflow occurs,
 *            given the timer's bit range.
 * \return    The first value after the timer wraps around.
 *---------------------------------------------------------------------------*/
static hal_timer_time_t HAL_TimerGetFirstOverflowValueInTicks(void)
{
    return ((hal_timer_time_t)1 << (HAL_TIMER_RANGE_IN_BITS - 1));
}

/*!-------------------------------------------------------------------------
 * \brief     Computes the first value after a timer wrap-around based on its resolution in milliseconds.
 * \details   This function determines the smallest timer value after an overflow occurs,
 *            given the timer's bit range.
 * \return    The first value after the timer wraps around.
 *---------------------------------------------------------------------------*/
static hal_timer_time_t HAL_TimerGetFirstOverflowValueInMs(void)
{
    return COUNT_TO_MSEC(HAL_TimerGetFirstOverflowValueInTicks(), s_timermanager.hardwareTimerClockHz);
}

/*!-------------------------------------------------------------------------
 * \brief     Returns the timer status
 * \param[in] timerHandle - the handle of timer
 * \return    see definition of uint8_t
 *---------------------------------------------------------------------------*/
static uint8_t TimerGetTimerStatus(timer_handle_t timerHandle)
{
    timer_handle_struct_t *timer = (timer_handle_struct_t *)timerHandle;
    return timer->tmrStatus & (uint8_t)kTimerStateMask_c;
}

/*! -------------------------------------------------------------------------
 * \brief     Set the timer status
 * \param[in] timerHandle - the handle of timer
 * \param[in] status - the status of the timer
 *---------------------------------------------------------------------------*/
static void TimerSetTimerStatus(timer_handle_t timerHandle, uint8_t status)
{
    timer_handle_struct_t *timer = (timer_handle_struct_t *)timerHandle;
    timer->tmrStatus &= (uint8_t)(~kTimerStateMask_c);
    timer->tmrStatus |= status;
}

/*! -------------------------------------------------------------------------
 * \brief     Returns the timer type
 * \param[in] timerHandle - the handle of timer
 * \return    see definition of uint8_t
 *---------------------------------------------------------------------------*/
static uint8_t TimerGetTimerType(timer_handle_t timerHandle)
{
    timer_handle_struct_t *timer = (timer_handle_struct_t *)timerHandle;
    return timer->tmrType & (uint8_t)kTimerModeMask_c;
}

/*! -------------------------------------------------------------------------
 * \brief     Set the timer type
 * \param[in] timerHandle - the handle of timer
 * \param[in] timerType   - timer type
 *---------------------------------------------------------------------------*/
static void TimerSetTimerType(timer_handle_t timerHandle, uint8_t timerType)
{
    timer_handle_struct_t *timer = (timer_handle_struct_t *)timerHandle;
    timer->tmrType &= (uint8_t)(~kTimerModeMask_c);
    timer->tmrType |= timerType;
}

/*! -------------------------------------------------------------------------
 * \brief     Set the timer free
 * \param[in] timerHandle - the handle of timer
 * \param[in] type - timer type
 *---------------------------------------------------------------------------*/
static void TimerMarkTimerFree(timer_handle_t timerHandle)
{
    timer_handle_struct_t *timer = (timer_handle_struct_t *)timerHandle;
    timer->tmrStatus             = 0;
}

/*! -------------------------------------------------------------------------
 * \brief  Notify Timer task to run.
 * \return
 *---------------------------------------------------------------------------*/
static void NotifyTimersTask(void)
{
#if defined(OSA_USED)
    osa_status_t osaStatus;
    (void)osaStatus;
#if (defined(TM_COMMON_TASK_ENABLE) && (TM_COMMON_TASK_ENABLE > 0U))
    s_timermanager.mTimerCommontaskMsg.callback = TimerManagerTask;
    osaStatus                                   = COMMON_TASK_post_message(&s_timermanager.mTimerCommontaskMsg);
    assert(osaStatus == KOSA_StatusSuccess);
#else
    osaStatus = OSA_SemaphorePost((osa_semaphore_handle_t)s_timermanager.halTimerTaskSemaphoreHandle);
    /* An error is reported when this binary semaphore is posted a second time. This
     * can happen and the error can be ignored. */
    assert(osaStatus == KOSA_StatusSuccess || osaStatus == KOSA_StatusError);
#endif
#else
    TimerManagerTask(NULL);
#endif
}

/*! -------------------------------------------------------------------------
 * \brief Function called by driver ISR on channel match in interrupt context.
 *---------------------------------------------------------------------------*/
static void HAL_TIMER_Callback(void *param)
{
    NotifyTimersTask();
}

/*! -------------------------------------------------------------------------
 * \brief     Searches the first future timer and updates the
 *            match register with the time of this timer.
 *---------------------------------------------------------------------------*/
static void UpdateMatch()
{
    uint32_t regPrimask       = DisableGlobalIRQ();
    timer_handle_struct_t *th = s_timermanager.timerHead;
    uint8_t activeLPTimerNum, activeTimerNum;

    activeLPTimerNum = s_timermanager.numberOfLowPowerActiveTimers;
    activeTimerNum   = s_timermanager.numberOfActiveTimers;
    /* Are there active timers? */
    if ((0U != activeLPTimerNum) || (0U != activeTimerNum))
    {
        hal_timer_time_t currentTimeInTicks = HAL_TimerGetCurrentTicks((hal_timer_handle_t)s_timermanager.halTimerHandle);
        hal_timer_time_t firstFutureTime = HAL_TimerGetFirstOverflowValueInTicks(); /* Put first starting value value far in future */
        timer_state_t state;
        /* Yes, check which comes first */

        while (NULL != th)
        {
            state = (timer_state_t)TimerGetTimerStatus(th);
            if (kTimerStateActive_c == state)
            {
                /* Check whether this timer expires earlier or whether this timer
                 * has a time in the past. The latter may happen with timers with
                 * very small intervals */
                if ((!IsGreaterThan(th->scheduledTimeInTicks, firstFutureTime)) ||
                    (!IsGreaterThan(th->scheduledTimeInTicks, currentTimeInTicks)))
                {
                    firstFutureTime = th->scheduledTimeInTicks;
                }
            }
            th = th->next;
        }

        /* Configure the timer to interrupt on first future timer.
        Take into account, the processing time it takes to execute HAL_TimerUpdateMatchValueInTicks when programming new match.
        We have to make sure that, the new match is always in the future.
        If the firstFutureTime is very close to current time, it can happen,
        that by the time the match is programmed, the value of firstFutureTime is already in the past.
        If this situation is detected, we add a few ticks to the new match value to make sure the match value is in the
        future, and a timer interrupt is not missed. */
        currentTimeInTicks = HAL_TimerGetCurrentTicks((hal_timer_handle_t)s_timermanager.halTimerHandle);
        if (IsGreaterThan(firstFutureTime, currentTimeInTicks + s_timermanager.updateMatchProcTimeTicks))
        {
            HAL_TimerUpdateMatchValueInTicks((hal_timer_handle_t)s_timermanager.halTimerHandle, firstFutureTime);
        }
        else
        {
            HAL_TimerUpdateMatchValueInTicks((hal_timer_handle_t)s_timermanager.halTimerHandle,
                                      currentTimeInTicks + s_timermanager.updateMatchProcTimeTicks);
        }

        s_timermanager.hardwareTimerIsRunning = (uint8_t) true;
    }
    EnableGlobalIRQ(regPrimask);
}

/*! -------------------------------------------------------------------------
 * \brief     TimerManager task.
 *            Called by the kernel when the timer ISR posts a timer event.
 * \param[in] param
 *---------------------------------------------------------------------------*/
static void TimerManagerTask(void *param)
{
    uint8_t timerType;
    timer_state_t state;

#if defined(OSA_USED)
#if (defined(TM_COMMON_TASK_ENABLE) && (TM_COMMON_TASK_ENABLE > 0U))
    {
#else
    do
    {
        if (KOSA_StatusSuccess ==
            OSA_SemaphoreWait((osa_semaphore_handle_t)s_timermanager.halTimerTaskSemaphoreHandle, osaWaitForever_c))
        {
#endif
#endif
        uint32_t regPrimask         = DisableGlobalIRQ();
        timer_handle_struct_t *th   = s_timermanager.timerHead;
        hal_timer_time_t currentTimeInTicks = HAL_TimerGetCurrentTicks((hal_timer_handle_t)s_timermanager.halTimerHandle);

        /* Sort the list of timers chronologically to make sure the callback functions are called in the
         * correct order*/
        uint32_t swapped = 1;
        while (swapped)
        {
            swapped                         = 0;
            th                              = s_timermanager.timerHead;
            timer_handle_struct_t *previous = NULL;
            while (th && th->next)
            {
                if (IsGreaterThan(th->scheduledTimeInTicks, th->next->scheduledTimeInTicks))
                {
                    swapped = 1;
                    if (previous == NULL)
                    {
                        timer_handle_struct_t *temp = th->next->next;
                        s_timermanager.timerHead    = th->next;
                        th->next->next              = th;
                        th->next                    = temp;
                        previous                    = s_timermanager.timerHead;
                    }
                    else
                    {
                        timer_handle_struct_t *temp = th->next->next;
                        previous->next              = th->next;
                        th->next->next              = th;
                        previous                    = th->next;
                        th->next                    = temp;
                    }
                }
                else
                {
                    previous = th;
                    th       = th->next;
                }
            }
        }

        th = s_timermanager.timerHead;
        /* Loop over all timer handles */
        while (NULL != th)
        {
            timerType = TimerGetTimerType(th);
            state     = (timer_state_t)TimerGetTimerStatus(th);
            if (kTimerStateActive_c == state)
            {
                /* Has this timer expired? Take wrapping into account */
                if (IsGreaterThan(currentTimeInTicks, th->scheduledTimeInTicks))
                {
                    /* Yes, is this timer a single shot timer? */
                    /* If this is an interval timer, restart it. Otherwise, mark it as inactive. */
                    if (0U != (timerType & (uint32_t)(kTimerModeSingleShot)))
                    {
                        /* Yes, stop it */
                        timer_status_t tmStatus = TimerStop(th);
                        assert(tmStatus == kStatus_TimerSuccess);
                        (void)tmStatus;
                    }
                    else
                    {
                        /* No, it's a recurring timer. Update the scheduled time to first interval in the future */
                        while (IsGreaterThan(currentTimeInTicks, th->scheduledTimeInTicks))
                        {
                            th->scheduledTimeInTicks =
                                (th->scheduledTimeInTicks + th->intervalInTicks) & GetTimerResolutionMask();
                        }
                    }
                    /* Call the registered callback function */
                    if (NULL != th->pfCallBack)
                    {
                        EnableGlobalIRQ(regPrimask);
                        th->pfCallBack(th->param);
                        regPrimask = DisableGlobalIRQ();
                        /* Restart from head as the above callback might have changed the list/state of timers */
                        th = s_timermanager.timerHead;
                        continue;
                    }
                }
            }
            else
            {
                /* Ignore any timer that is not active. */
            }
            th = th->next;
        }

        /* Update the timer match for the next timer */
        UpdateMatch();

        EnableGlobalIRQ(regPrimask);
#if defined(OSA_USED)
#if (defined(TM_COMMON_TASK_ENABLE) && (TM_COMMON_TASK_ENABLE > 0U))
    }
#else
        }
    } while (0U != gUseRtos_c);
#endif
#endif
}

/*! -------------------------------------------------------------------------
 * \brief     stop a specified timer.
 * \param[in] timerHandle - the handle of the timer
 * \return    see definition of timer_status_t
 *---------------------------------------------------------------------------*/
static timer_status_t TimerStop(timer_handle_t timerHandle)
{
    timer_status_t status = kStatus_TimerInvalidId;
    timer_state_t state;
    uint8_t activeLPTimerNum, activeTimerNum;
    uint32_t regPrimask = DisableGlobalIRQ();
    if (NULL != timerHandle)
    {
        state  = (timer_state_t)TimerGetTimerStatus(timerHandle);
        status = kStatus_TimerSuccess;
        if ((state == kTimerStateActive_c) || (state == kTimerStateReady_c))
        {
            TimerSetTimerStatus(timerHandle, (uint8_t)kTimerStateInactive_c);
            DecrementActiveTimerNumber(TimerGetTimerType(timerHandle));
            /* if no sw active timers are enabled, */
            /* call the TimerManagerTask() to countdown the ticks and stop the hw timer*/
            activeLPTimerNum = s_timermanager.numberOfLowPowerActiveTimers;
            activeTimerNum   = s_timermanager.numberOfActiveTimers;

            if ((0U == activeTimerNum) && (0U == activeLPTimerNum))
            {
                /* Only stop the hardware timer on closing the last software timer
                  that is not 'free' if the 'always on' feature is not enabled */
                if ((0U != s_timermanager.hardwareTimerIsRunning) && (!(s_timermanager.hardwareTimerAlwaysOn)))
                {
                    HAL_TimerDisable((hal_timer_handle_t)s_timermanager.halTimerHandle);
                    s_timermanager.hardwareTimerIsRunning = 0U;
                }
            }
        }
    }
    EnableGlobalIRQ(regPrimask);
    return status;
}

/*! -------------------------------------------------------------------------
 * \brief     Activates the specified timer
 * \param[in] timerHandle - the handle of the timer
 *---------------------------------------------------------------------------*/
static void TimerActivate(timer_handle_t timerHandle)
{
    assert(timerHandle);
    uint32_t regPrimask = DisableGlobalIRQ();

    if ((uint8_t)kTimerStateInactive_c == TimerGetTimerStatus(timerHandle))
    {
        IncrementActiveTimerNumber(TimerGetTimerType(timerHandle));
        TimerSetTimerStatus(timerHandle, (uint8_t)kTimerStateActive_c);
    }

    /* Update the match register in case this timer is the first future timer */
    UpdateMatch();

    EnableGlobalIRQ(regPrimask);
}

/*****************************************************************************
******************************************************************************
* Public functions
******************************************************************************
*****************************************************************************/
/*!
 * @brief Initializes timer manager module with the user configuration structure.
 *
 *
 * @param timerConfig              Pointer to user-defined timer configuration structure.
 * @retval kStatus_TimerSuccess      Timer manager initialization successful.
 */
timer_status_t TM_Init(timer_config_t *timerConfig)
{
    hal_timer_config_t halTimerConfig;
    hal_timer_handle_t halTimerHandle = &s_timermanager.halTimerHandle[0];
    hal_timer_status_t status;
#if (defined(TM_ENABLE_TIME_STAMP) && (TM_ENABLE_TIME_STAMP > 0U))
    hal_time_stamp_config_t halTimeStampConfig;
    hal_time_stamp_handle_t halTimeStampHandle = &s_timermanager.halTimeStampHandle[0];
#endif
    assert(timerConfig);

    /* Check if TMR is already initialized */
    if (0U == s_timermanager.initialized)
    {
        halTimerConfig.timeout               = 1000;
        halTimerConfig.srcClock_Hz           = timerConfig->srcClock_Hz;
        halTimerConfig.instance              = timerConfig->instance;
        halTimerConfig.clockSrcSelect        = timerConfig->clockSrcSelect;
        s_timermanager.hardwareTimerAlwaysOn = timerConfig->hardwareTimerAlwaysOn;
        s_timermanager.hardwareTimerClockHz = timerConfig->srcClock_Hz;


        s_timermanager.updateMatchProcTimeTicks =
            (uint32_t)(PROCESSING_TIME_UPDATE_MATCH_US / (1e6 / timerConfig->srcClock_Hz));
        assert(s_timermanager.updateMatchProcTimeTicks > 0);

        status = HAL_TimerInit(halTimerHandle, &halTimerConfig);
        assert(kStatus_HAL_TimerSuccess == status);
        (void)status;

        if (s_timermanager.hardwareTimerAlwaysOn)
        {
            HAL_TimerEnable(s_timermanager.halTimerHandle);
        }

        HAL_TimerInstallCallback(halTimerHandle, HAL_TIMER_Callback, NULL);

#if defined(OSA_USED)
#if (defined(TM_COMMON_TASK_ENABLE) && (TM_COMMON_TASK_ENABLE > 0U))
        common_task_status_t commonStatus = COMMON_TASK_init();
        assert(kStatus_COMMON_TASK_Success == commonStatus);
        (void)commonStatus;
#else
        osa_status_t osaStatus;
        osaStatus = OSA_SemaphoreCreateBinary((osa_semaphore_handle_t)s_timermanager.halTimerTaskSemaphoreHandle);
        assert(KOSA_StatusSuccess == (osa_status_t)osaStatus);
        (void)osaStatus;

        osaStatus = OSA_TaskCreate((osa_task_handle_t)s_timermanager.timerTaskHandle, OSA_TASK(TimerManagerTask), NULL);
        assert(KOSA_StatusSuccess == (osa_status_t)osaStatus);
        (void)osaStatus;
#endif
#endif
#if (defined(TM_ENABLE_TIME_STAMP) && (TM_ENABLE_TIME_STAMP > 0U))
        halTimeStampConfig.srcClock_Hz    = timerConfig->timeStampSrcClock_Hz;
        halTimeStampConfig.instance       = timerConfig->timeStampInstance;
        halTimeStampConfig.clockSrcSelect = timerConfig->clockSrcSelect;
        HAL_TimeStampInit(halTimeStampHandle, &halTimeStampConfig);
#endif
        s_timermanager.initialized = 1U;
    }
    return kStatus_TimerSuccess;
}

/*!
 * @brief Deinitialize timer manager module.
 *
 */
void TM_Deinit(void)
{
    timer_state_t state;
    timer_handle_struct_t *th = s_timermanager.timerHead;

#if defined(OSA_USED)
#if (defined(TM_COMMON_TASK_ENABLE) && (TM_COMMON_TASK_ENABLE > 0U))
#else
    osa_status_t osaStatus;
    (void)osaStatus;
    osaStatus = OSA_SemaphoreDestroy((osa_semaphore_handle_t)s_timermanager.halTimerTaskSemaphoreHandle);
    assert(KOSA_StatusSuccess == (osa_status_t)osaStatus);
    osaStatus = OSA_TaskDestroy((osa_task_handle_t)s_timermanager.timerTaskHandle);
    assert(KOSA_StatusSuccess == (osa_status_t)osaStatus);
#endif
#endif

    /* Loop over all software timers still listed in the timer manager and close them if they are not in the 'free'
     * state */
    while (NULL != th)
    {
        state = (timer_state_t)TimerGetTimerStatus(th);
        if (kTimerStateFree_c != state)
        {
            /* Closing timers that are still open... */
            TM_Close(th);
        }
        else
        {
            /* Do nothing if timer is inactive */
        }
        th = th->next;
    }

    /* Deinitialize the hardware timer only if it is not marked as 'always on' (e.g. because it is used by another
     * module) */
    if (!(s_timermanager.hardwareTimerAlwaysOn))
    {
        HAL_TimerDeinit((hal_timer_handle_t)s_timermanager.halTimerHandle);
    }
    /* Clean the timer manager structure */
    (void)memset(&s_timermanager, 0x0, sizeof(s_timermanager));
}

/*!
 * @brief Power up timer manager module.
 *
 */
void TM_ExitLowpower(void)
{
#if (defined(TM_ENABLE_LOW_POWER_TIMER) && (TM_ENABLE_LOW_POWER_TIMER > 0U))
    HAL_TimerExitLowpower((hal_timer_handle_t)s_timermanager.halTimerHandle);
#endif
#if (defined(TM_ENABLE_TIME_STAMP) && (TM_ENABLE_TIME_STAMP > 0U))
    HAL_TimeStampExitLowpower(s_timermanager.halTimerHandle);
#endif
}

/*!
 * @brief Power down timer manager module.
 *
 */
void TM_EnterLowpower(void)
{
#if (defined(TM_ENABLE_LOW_POWER_TIMER) && (TM_ENABLE_LOW_POWER_TIMER > 0U))
    HAL_TimerEnterLowpower((hal_timer_handle_t)s_timermanager.halTimerHandle);
#endif
}

/*!
 * @brief Get a time-stamp value
 *
 */
hal_timer_time_t TM_GetTimestamp(void)
{
#if (defined(TM_ENABLE_TIME_STAMP) && (TM_ENABLE_TIME_STAMP > 0U))
    return HAL_GetTimeStamp((hal_time_stamp_handle_t)s_timermanager.halTimeStampHandle);
#else
    return 0U;
#endif /* TM_ENABLE_TIME_STAMP */
}

/*!
 * @brief Open a timer with user handle.
 *
 * @param timerHandle              Pointer to point to a memory space of size #TIMER_HANDLE_SIZE allocated by the
 * caller.
 * @retval kStatus_TimerSuccess    Timer open successful.
 */
timer_status_t TM_Open(timer_handle_t timerHandle)
{
    timer_handle_struct_t *timerState = timerHandle;
    assert(sizeof(timer_handle_struct_t) == TIMER_HANDLE_SIZE);
    assert(timerHandle);
    TIMER_ENTER_CRITICAL();
    TimerSetTimerStatus(timerState, (uint8_t)kTimerStateInactive_c);
    if (NULL == s_timermanager.timerHead)
    {
        s_timermanager.timerHead = timerHandle;
        timerState->next         = NULL;
    }
    else
    {
        timerState->next         = s_timermanager.timerHead;
        s_timermanager.timerHead = timerHandle;
    }
    TIMER_EXIT_CRITICAL();
    return kStatus_TimerSuccess;
}

/*!
 * @brief Close a timer with user handle.
 *
 * @param timerHandle - the handle of the timer
 *
 * @retval kStatus_TimerSuccess    Timer close successful.
 */
timer_status_t TM_Close(timer_handle_t timerHandle)
{
    timer_status_t status;
    timer_handle_struct_t *timerState = timerHandle;
    timer_handle_struct_t *timerStatePre;
    assert(timerHandle);
    TIMER_ENTER_CRITICAL();
    status = TM_Stop(timerHandle);

    assert(kStatus_TimerSuccess == status);
    (void)status;

    TimerMarkTimerFree(timerHandle);

    timerStatePre = s_timermanager.timerHead;

    if (timerStatePre != timerState)
    {
        while ((NULL != timerStatePre) && (timerStatePre->next != timerState))
        {
            timerStatePre = timerStatePre->next;
        }
        if (NULL != timerStatePre)
        {
            timerStatePre->next = timerState->next;
        }
    }
    else
    {
        s_timermanager.timerHead = timerState->next;
    }
    TIMER_EXIT_CRITICAL();
    return kStatus_TimerSuccess;
}

/*!
 * @brief   Check if all timers except the LP timers are OFF
 *
 *
 * @retval return 1 there are no active non-low power timers, 0 otherwise.
 */

uint8_t TM_AreAllTimersOff(void)
{
    return s_timermanager.numberOfActiveTimers == 0U ? 1U : 0U;
}

/*!
 * @brief  Check if a specified timer is active
 *
 * @param timerHandle - the handle of the timer
 *
 * @retval return 1 if timer is active, return 0 if timer is not active.
 */
uint8_t TM_IsTimerActive(timer_handle_t timerHandle)
{
    assert(timerHandle);
    return (uint8_t)(TimerGetTimerStatus(timerHandle) == (uint8_t)kTimerStateActive_c);
}

/*!
 * @brief  Check if a specified timer is ready
 *
 * @param timerHandle - the handle of the timer
 *
 * @retval return 1 if timer is ready, return 0 if timer is not ready.
 */
uint8_t TM_IsTimerReady(timer_handle_t timerHandle)
{
    assert(timerHandle);
    return (uint8_t)(TimerGetTimerStatus(timerHandle) == (uint8_t)kTimerStateReady_c);
}

/*!
 * @brief  Install a specified timer callback
 *
 * @param timerHandle - the handle of the timer
 * @param callback - callback function
 * @param callbackParam - parameter to callback function
 *
 * @retval kStatus_TimerSuccess    Timer install callback succeeded.
 *
 */
timer_status_t TM_InstallCallback(timer_handle_t timerHandle, timer_callback_t callback, void *callbackParam)
{
    timer_handle_struct_t *th = timerHandle;

    assert(timerHandle);
    th->pfCallBack = callback;
    th->param      = callbackParam;

    return kStatus_TimerSuccess;
}

/*!
 * @brief  Start a specified timer
 *
 * @param timerHandle - the handle of the timer
 * @param timerType - the type of the timer
 * @param timerDelay - delay till first expiration
 * @param timerInterval - interval
 *
 * @retval kStatus_TimerSuccess    Timer start successful.
 * @retval kStatus_TimerOutOfRange      The interval is out of range and could cause integer wrapping issues.
 */
timer_status_t TM_StartWithDelay(timer_handle_t timerHandle,
                                 uint8_t timerType,
                                 hal_timer_time_t timerDelayMs,
                                 hal_timer_time_t timerIntervalMs)
{
    timer_status_t status = kStatus_TimerSuccess;
    timer_handle_struct_t *th = timerHandle;

    uint32_t freq               = s_timermanager.hardwareTimerClockHz;
    hal_timer_time_t currentTimeInTicks = HAL_TimerGetCurrentTicks((hal_timer_handle_t)s_timermanager.halTimerHandle);
    uint32_t multiplier         = (uint8_t)timerType & (uint8_t)kTimerModeSetMinuteTimer ? 1000U * 1000U * 60 :
                                  (uint8_t)timerType & (uint8_t)kTimerModeSetSecondTimer ? 1000U * 1000U :
                                  (uint8_t)timerType & (uint8_t)kTimerModeSetMicrosTimer ? 1 :
                                                                                           1000U;
    hal_timer_time_t delayInTicks;

    assert(timerHandle);

    if (TimerGetTimerStatus(timerHandle) != kTimerStateInactive_c)
    {
        status = TM_Stop(timerHandle);
        assert(status == kStatus_TimerSuccess);
    }

    /* The range is limited to below value to be able to handle integer wrapping correctly */
    if (timerIntervalMs >= HAL_TimerGetFirstOverflowValueInMs())
    {
        return kStatus_TimerOutOfRange;
    }

    /* Check whether the delay is within range */
    /* The range is limited to below value to be able to handle integer wrapping correctly */
    if (timerDelayMs >= HAL_TimerGetFirstOverflowValueInMs())
    {
        return kStatus_TimerOutOfRange;
    }

    TimerSetTimerType(timerHandle, timerType);
    th->intervalInTicks = USEC_TO_COUNT((hal_timer_time_t)multiplier * timerIntervalMs, freq);
    delayInTicks               = USEC_TO_COUNT((hal_timer_time_t)multiplier * timerDelayMs, freq);

    if (!(s_timermanager.hardwareTimerAlwaysOn))
    {
        HAL_TimerEnable(s_timermanager.halTimerHandle);
    }

    th->scheduledTimeInTicks = (delayInTicks + currentTimeInTicks) & GetTimerResolutionMask();

    /* Enable timer, the timer task will do the rest of the work. */
    TimerActivate(timerHandle);

    return status;
}

/*!
 * @brief  Start a specified timer
 *
 * @param timerHandle - the handle of the timer
 * @param timerType - the type of the timer
 * @param timerTimeut - timeout
 *
 * @retval kStatus_TimerSuccess    Timer start successful.
 * @retval kStatus_TimerOutOfRange      The interval is out of range and could cause integer wrapping issues.
 */
timer_status_t TM_Start(timer_handle_t timerHandle, uint8_t timerType, hal_timer_time_t timerTimeout)
{
    return TM_StartWithDelay(timerHandle, timerType, timerTimeout, timerTimeout);
}

/*!
 * @brief  Stop a specified timer
 *
 * @param timerHandle - the handle of the timer
 *
 * @retval kStatus_TimerSuccess    Timer stop successful.
 * @retval kStatus_TimerInvalidId      No handle was passed.
 */
timer_status_t TM_Stop(timer_handle_t timerHandle)
{
    timer_status_t status;
    uint32_t regPrimask = DisableGlobalIRQ();
    status              = TimerStop(timerHandle);

    /* If this is the first future timer to expire, the match must be updated */
    /* This check is only required when explicitly stopped by user. In other cases,
     * the match is automatically updated. Hence this is in TM_Stop and not TimerStop */
    UpdateMatch();
    EnableGlobalIRQ(regPrimask);
    return status;
}

/*!
 * @brief  Returns the remaining time until timeout
 *
 * @param timerHandle - the handle of the timer
 *
 * @retval remaining time in microseconds until specified timer times out.
 */
hal_timer_time_t TM_GetRemainingTime(timer_handle_t timerHandle)
{
    timer_handle_struct_t *timerState = timerHandle;
    hal_timer_time_t currentTimeInTicks       = HAL_TimerGetCurrentTicks((hal_timer_handle_t)s_timermanager.halTimerHandle);
    uint32_t freq                     = s_timermanager.hardwareTimerClockHz;
    assert(timerHandle);
    /* Return the planned time minus current time taking into account that the timer has expired */
    return COUNT_TO_USEC(IsGreaterThan(timerState->scheduledTimeInTicks, currentTimeInTicks) ?
                             timerState->scheduledTimeInTicks - currentTimeInTicks :
                             0,
                         freq);
}

/*!
 * @brief Get the first expire time of timer
 *
 * @param timerHandle - the handle of the timer
 *
 * @retval return the first expire time in microseconds of all timers.
 */
hal_timer_time_t TM_GetFirstExpireTime(uint8_t timerType)
{
    hal_timer_time_t min = GetTimerResolutionMask();
    hal_timer_time_t remainingTime;

    timer_handle_struct_t *th = s_timermanager.timerHead;
    while (NULL != th)
    {
        if ((bool)TM_IsTimerActive(th) && ((timerType & TimerGetTimerType(th)) > 0U))
        {
            remainingTime = TM_GetRemainingTime(th);
            if (remainingTime < min)
            {
                min = remainingTime;
            }
        }
        th = th->next;
    }
    return min;
}

/*!
 * @brief Returns the handle of the timer of the first allocated timer that has the
 *        specified parameter.
 *
 * @param param - specified parameter of timer
 *
 * @retval return the handle of the timer if success.
 */
timer_handle_t TM_GetFirstTimerWithParam(void *param)
{
    timer_handle_struct_t *th = s_timermanager.timerHead;

    while (NULL != th)
    {
        if (th->param == param)
        {
            return th;
        }
        th = th->next;
    }
    return NULL;
}

/*!
 * @brief Returns not counted time before entering sleep, this function is called
 *        by Low Power module;
 *
 * @retval return microseconds that wasn't counted before entering in sleep.
 */
hal_timer_time_t TM_NotCountedTimeBeforeSleep(void)
{
#if (defined(TM_ENABLE_LOW_POWER_TIMER) && (TM_ENABLE_LOW_POWER_TIMER > 0U))
    hal_timer_time_t timeUs = 0;
    hal_timer_time_t currentTimeInUs;

    if (0U != s_timermanager.numberOfLowPowerActiveTimers)
    {
        currentTimeInUs = HAL_TimerGetCurrentTimerCount((hal_timer_handle_t)s_timermanager.halTimerHandle);
        HAL_TimerDisable((hal_timer_handle_t)s_timermanager.halTimerHandle);
        s_timermanager.hardwareTimerIsRunning = 0U;

        /* The hw timer is stopped but keep s_timermanager.hardwareTimerIsRunning = TRUE...*/
        /* The Lpm timers are considered as being in running mode, so that  */
        /* not to start the hw timer if a TMR event occurs (this shouldn't happen) */

        timeUs = (uint32_t)(currentTimeInUs - s_timermanager.previousTimeInUs);
        return timeUs;
    }
#else
    return 0;
#endif
}

/*!
 * @brief Sync low power timer in sleep mode,This function is called by Low Power module;
 *
 * @param sleepDurationTmrUs - sleep duration in TMR microseconds
 *
 */
void TM_SyncLpmTimers(uint32_t sleepDurationTmrUs)
{
#if (defined(TM_ENABLE_LOW_POWER_TIMER) && (TM_ENABLE_LOW_POWER_TIMER > 0U))

    TimersUpdateSyncTask(sleepDurationTmrUs);
    HAL_TimerEnable((hal_timer_handle_t)s_timermanager.halTimerHandle);
    s_timermanager.previousTimeInUs = HAL_TimerGetCurrentTimerCount((hal_timer_handle_t)s_timermanager.halTimerHandle);

#else
    sleepDurationTmrUs = sleepDurationTmrUs;
#endif /* #if (TM_ENABLE_LOW_POWER_TIMER) */
}

/*!
 * @brief Make timer task ready after wakeup from lowpower mode,This function is called
 *        by Low Power module;
 *
 */
void TM_MakeTimerTaskReady(void)
{
#if (defined(TM_ENABLE_LOW_POWER_TIMER) && (TM_ENABLE_LOW_POWER_TIMER > 0U))
    NotifyTimersTask();
#endif
}
