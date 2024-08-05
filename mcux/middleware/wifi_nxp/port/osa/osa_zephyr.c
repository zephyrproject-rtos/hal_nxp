/** @file osa_zephyr.c
 *
 *  @brief OS Zephyr interaction API
 *
 *  Copyright 2008-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <inttypes.h>
#include <stdio.h>
#include <osa.h>
#include <wmlog.h>

/*** Timer Management ***/
static void timer_callback_work_handler(struct k_work *item)
{
    struct timer_data *ptimer = CONTAINER_OF(item, struct timer_data, work);

    ptimer->callback(ptimer);
}

static void timer_callback(struct k_timer *tmr)
{
    int ret;
    struct timer_data *ptimer = k_timer_user_data_get(tmr);

    ret = k_work_submit(&ptimer->work);
    if (ret < 0)
    {
        printk("timer[%p] submit to system queue fail ret %d\r\n", (void *)ptimer, ret);
    }
}

osa_status_t OSA_TimerCreate(osa_timer_handle_t timerHandle,
                             osa_timer_tick ticks,
                             void (*call_back)(osa_timer_arg_t),
                             void *cb_arg,
                             osa_timer_t reload,
                             osa_timer_activate_t activate)
{
    osa_status_t status = KOSA_StatusSuccess;

    assert(timerHandle != NULL);

    struct timer_data *ptimer = (struct timer_data *)timerHandle;

    ptimer->reload_options = reload;
    ptimer->period         = ticks;
    ptimer->callback       = call_back;
    ptimer->user_arg       = cb_arg;
    k_timer_init(&ptimer->timer, timer_callback, NULL);
    k_timer_user_data_set(&ptimer->timer, ptimer);

    /* put callback in system work queue thread to avoid non-isr operations in isr context */
    k_work_init(&ptimer->work, timer_callback_work_handler);

    if (activate == OSA_TIMER_AUTO_ACTIVATE)
    {
        if (ptimer->reload_options == KOSA_TimerOnce)
        {
            k_timer_start(&ptimer->timer, K_TICKS(ptimer->period), K_NO_WAIT);
        }
        else
        {
            k_timer_start(&ptimer->timer, K_TICKS(ptimer->period), K_TICKS(ptimer->period));
        }
    }

    return status;
}

osa_status_t OSA_TimerActivate(osa_timer_handle_t timerHandle)
{
    osa_status_t status = KOSA_StatusSuccess;

    assert(timerHandle != NULL);

    struct timer_data *ptimer = (struct timer_data *)timerHandle;

    if (ptimer->reload_options == KOSA_TimerOnce)
    {
        k_timer_start(&ptimer->timer, K_TICKS(ptimer->period), K_NO_WAIT);
    }
    else
    {
        k_timer_start(&ptimer->timer, K_TICKS(ptimer->period), K_TICKS(ptimer->period));
    }

    return status;
}

osa_status_t OSA_TimerChange(osa_timer_handle_t timerHandle, osa_timer_tick ntime, osa_timer_tick block_time)

{
    osa_status_t status = KOSA_StatusSuccess;

    assert(timerHandle != NULL);

    struct timer_data *ptimer = (struct timer_data *)timerHandle;

    ptimer->period = ntime;

    return status;
}

bool OSA_TimerIsRunning(osa_timer_handle_t timerHandle)
{
    int ret;

    assert(timerHandle != NULL);

    struct timer_data *ptimer = (struct timer_data *)timerHandle;

    ret = k_timer_remaining_ticks(&ptimer->timer);

    return ret == 0 ? false : true;
}

void *OSA_TimerGetContext(osa_timer_handle_t timerHandle)
{
    assert(timerHandle != NULL);

    struct timer_data *ptimer = (struct timer_data *)(void *)(uint32_t *)(*(uint32_t *)timerHandle);

    return ptimer->user_arg;
}

osa_status_t OSA_TimerReset(osa_timer_handle_t timerHandle)
{
    assert(timerHandle != NULL);

    return OSA_TimerActivate(timerHandle);
}

osa_status_t OSA_TimerDeactivate(osa_timer_handle_t timerHandle)
{
    osa_status_t status = KOSA_StatusSuccess;

    assert(timerHandle != NULL);

    struct timer_data *ptimer = (struct timer_data *)timerHandle;

    k_timer_stop(&ptimer->timer);

    return status;
}

osa_status_t OSA_TimerDestroy(osa_timer_handle_t timerHandle)
{
    osa_status_t status = KOSA_StatusSuccess;

    assert(timerHandle != NULL);

    struct timer_data *ptimer = (struct timer_data *)timerHandle;

    k_timer_stop(&ptimer->timer);
    k_work_cancel(&ptimer->work);
	
    return status;
}

void (*g_os_tick_hooks[MAX_CUSTOM_HOOKS])(void) = {NULL};
void (*g_os_idle_hooks[MAX_CUSTOM_HOOKS])(void) = {NULL};

/** The FreeRTOS Tick hook function. */
void vApplicationTickHook(void)
{
    int i;

    for (i = 0; i < MAX_CUSTOM_HOOKS; i++)
    {
        if (g_os_tick_hooks[i] != NULL)
        {
            g_os_tick_hooks[i]();
        }
    }
}

void vApplicationIdleHook(void)
{
    int i;
    for (i = 0; i < MAX_CUSTOM_HOOKS; i++)
    {
        if (g_os_idle_hooks[i] != NULL)
        {
            g_os_idle_hooks[i]();
        }
    }
}

int OSA_SetupIdleFunction(void (*func)(void))
{
    return 0;
}

int OSA_RemoveIdleFunction(void (*func)(void))
{
    return 0;
}

void OSA_ThreadSelfComplete(osa_task_handle_t taskHandle)
{
    //return 0;
}

uint32_t OSA_MsgQWaiting(osa_msgq_handle_t msgqHandle)
{
    return 0;
}
