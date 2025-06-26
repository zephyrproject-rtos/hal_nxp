/*
 *  Copyright 2023-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef _OSA_ZEPHYR_H_
#define _OSA_ZEPHYR_H_

#include <zephyr/kernel.h>

//#define CONFIG_MEM_POOLS 1

//#include <mem_pool_config.h>

/*** Timer Management ***/

struct timer_data;

typedef struct timer_data *os_timer_t;
typedef os_timer_t osa_timer_arg_t;
typedef int osa_timer_tick;

/** OS Timer data structure
 */
struct timer_data
{
    void (*callback)(osa_timer_arg_t);
    void *user_arg;
    int period;
    int reload_options;
    struct k_timer timer;
    struct k_work work;
};

/**
 * OS Timer Activate Options
 */
typedef enum osa_timer_activation
{
    /** Start the timer on creation. */
    OSA_TIMER_AUTO_ACTIVATE,
    /** Do not start the timer on creation. */
    OSA_TIMER_NO_ACTIVATE,
} osa_timer_activate_t;

/*! @brief Converts milliseconds to ticks*/
#define MSEC_TO_TICK(msec) k_ms_to_ticks_floor32(msec)


static inline unsigned OSA_TicksGet(void)
{
    return sys_clock_tick_get();

}

static inline uint32_t OSA_MsecToTicks(uint32_t msecs)
{
    return k_ms_to_ticks_floor32(msecs);
}

static inline unsigned long OSA_TicksToMsec(unsigned long ticks)
{
    return k_ticks_to_ms_floor32(ticks);
}

static inline void OSA_LockSchedule(void)
{
    k_sched_lock();
}

static inline void OSA_UnlockSchedule(void)
{
    k_sched_unlock();
}

static inline bool OSA_IsISR()
{
    return k_is_in_isr();
}
/**
 * \def os_get_runtime_stats(__buff__)
 *
 * Get ASCII formatted run time statistics
 *
 * Please ensure that your buffer is big enough for the formatted data to
 * fit. Failing to do this may cause memory data corruption.
 */
#define OSA_GetRuntimeStats(__buff__)

/**
 * \def os_get_task_list(__buff__)
 *
 * Get ASCII formatted task list
 *
 * Please ensure that your buffer is big enough for the formatted data to
 * fit. Failing to do this may cause memory data corruption.
 */

#define OSA_GetTaskList(__buff__)

#endif /* ! _OSA_ZEPHYR_H_ */
