/*
 *  Copyright 2008-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*! \file wm_os.h
 *  \brief OS Abstraction Layer
 *
 * The OS abstraction layer provides wrapper APIs over some of the
 * commonly used OS primitives. Since the behaviour and semantics of the various
 * OSes differs widely, some abstraction APIs require a specific handling as
 * listed below.
 *
 * \section wm_os_usage Usage
 *
 * The OS abstraction layer provides the following types of primitives:
 *
 * - Thread: Create or delete a thread using os_thread_create() or
 *    os_thread_delete(). Block a thread using os_thread_sleep(). Complete a
 *    thread's execution using os_thread_self_complete().
 * - Message Queue: Create or delete a message queue using os_queue_create() or
 *    os_queue_delete(). Send a message using os_queue_send() and received a
 *    message using os_queue_recv().
 * - Mutex: Create or delete a mutex using os_mutex_create() or
 *    os_mutex_delete(). Acquire a mutex using os_mutex_get() and release it
 *    using os_mutex_put().
 * - Semaphores: Create or delete a semaphore using os_semaphore_create() /
 *    os_semaphore_create_counting() or os_semaphore_delete. Acquire a semaphore
 *    using os_semaphore_get() and release it using os_semaphore_put().
 * - Timers: Create or delete a timer using os_timer_create() or
 *    os_timer_delete(). Change the timer using os_timer_change(). Activate or
 *    de-activate the timer using os_timer_activate() or
 *    os_timer_deactivate(). Reset a timer using os_timer_reset().
 * - Dynamic Memory Allocation: Dynamically allocate memory using
 *    os_mem_alloc(), os_mem_calloc() or os_mem_realloc() and free it using
 *    os_mem_free().
 *
 */

#ifndef _WM_OS_H_
#define _WM_OS_H_

#include <string.h>

#if defined(SDK_OS_FREE_RTOS)
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "timers.h"
#include "portmacro.h"

#if defined(CPU_MIMXRT1062DVL6A)
#include "clock_config.h"
#endif

#elif __ZEPHYR__

#include "nxp_wifi.h"
#include <zephyr/kernel.h>
#if defined(CONFIG_POSIX_API)
#include <sys/time.h>
#include <time.h>
#endif

#define PRINTF printk

#endif

#include <wmerrno.h>
#include <wm_utils.h>

#ifdef CONFIG_OS_DEBUG
#define os_dprintf(...) PRINTF("[OS]" __VA_ARGS__)
#else
#define os_dprintf(...)
#endif

#if defined(SDK_OS_FREE_RTOS)
bool is_isr_context(void);

/* the OS timer register is loaded with CNTMAX */
#define CNTMAX                 ((SystemCoreClock / configTICK_RATE_HZ) - 1UL)
#define CPU_CLOCK_TICKSPERUSEC (SystemCoreClock / 1000000U)
#define USECSPERTICK           (1000000U / configTICK_RATE_HZ)

/** Force a context switch */
#define os_thread_relinquish() taskYIELD()
unsigned os_ticks_get(void);
#elif __ZEPHYR__
#define is_isr_context() k_is_in_isr()
/** Force a context switch */
#define os_thread_relinquish() k_yield()

/** Get current OS tick counter value
 *
 * \return 32 bit value of ticks since boot-up
 */
static inline unsigned os_ticks_get(void)
{
    return k_uptime_get_32();
}
#endif

#if 0
#if defined(SDK_OS_FREE_RTOS)
/** Get (wraparound safe) current OS tick counter.
 *
 * Returns a 64 bit unsigned integer. To give a rough idea,
 * for an OS tick period of 1 mS it takes thousands of years
 * before the counter value returned by this API to wrap around.
 * Thus, users of this API can ignore the wrap around problem.
 *
 * \return 64 bit value of ticks since boot-up
 */
static inline unsigned long long os_total_ticks_get()
{
    if (is_isr_context())
        return xTaskGetTotalTickCountFromISR();
    else
        return xTaskGetTotalTickCount();
}
#elif __ZEPHYR__
/** Get (wraparound safe) current OS tick counter.
 *
 * Returns a 64 bit unsigned integer. To give a rough idea,
 * for an OS tick period of 1 mS it takes thousands of years
 * before the counter value returned by this API to wrap around.
 * Thus, users of this API can ignore the wrap around problem.
 *
 * \return 64 bit value of ticks since boot-up
 */
static inline unsigned long long os_total_ticks_get()
{
    return k_uptime_get();
}
#endif
#endif

#if defined(SDK_OS_FREE_RTOS)
/** Get ticks to next thread wakeup */
#define os_ticks_to_unblock() xTaskGetUnblockTime()
#endif

/**
 * Returns time in micro-secs since bootup
 *
 * @note The value returned will wrap around after sometime and caller is
 * expected to guard itself against this.
 *
 * @return Time in micro-secs since bootup
 */
unsigned int os_get_timestamp(void);

#if defined(SDK_OS_FREE_RTOS)
/** Convert milliseconds to OS ticks
 *
 * This function converts the given millisecond value to the number of OS
 * ticks.
 *
 * This is useful as functions like os_thread_sleep() accept only ticks
 * as input.
 *
 * @param[in] msecs Milliseconds
 *
 * @return Number of OS ticks corresponding to msecs
 */
/*! @brief Convert the milliseconds to ticks in FreeRTOS. */
uint32_t os_msec_to_ticks(uint32_t msecs);

/** Convert ticks to milliseconds
 *
 * This function converts the given ticks value to milliseconds. This is useful
 * as some functions, like os_ticks_get(), return values in units of OS ticks.
 *
 * @param[in] ticks OS ticks
 *
 * @return Number of milliseconds corresponding to ticks
 */
unsigned long os_ticks_to_msec(unsigned long ticks);
#elif __ZEPHYR__
/** Convert milliseconds to OS ticks
 *
 * This function converts the given millisecond value to the number of OS
 * ticks.
 *
 * This is useful as functions like os_thread_sleep() accept only ticks
 * as input.
 *
 * @param[in] msecs Milliseconds
 *
 * @return Number of OS ticks corresponding to msecs
 */
/*! @brief Convert the milliseconds to ticks in FreeRTOS. */

static inline uint32_t os_msec_to_ticks(uint32_t msecs)
{
    return k_ms_to_ticks_near32(msecs);
}

/** Convert ticks to milliseconds
 *
 * This function converts the given ticks value to milliseconds. This is useful
 * as some functions, like os_ticks_get(), return values in units of OS ticks.
 *
 * @param[in] ticks OS ticks
 *
 * @return Number of milliseconds corresponding to ticks
 */
static inline unsigned long os_ticks_to_msec(unsigned long ticks)
{
    return k_ticks_to_ms_near32(ticks);
}
#endif

/*** Thread Management ***/
typedef void *os_thread_arg_t;

#if defined(SDK_OS_FREE_RTOS)
/**
 * Structure to be used during call to the function
 * os_thread_create(). Please use the macro \ref os_thread_stack_define
 * instead of using this structure directly.
 */
typedef struct os_thread_stack
{
    /** Total stack size */
    size_t size;
} os_thread_stack_t;

/**
 * Helper macro to define the stack size (in bytes) before a new thread is
 * created using the function os_thread_create().
 */
#define os_thread_stack_define(stackname, stacksize) \
    os_thread_stack_t stackname = {(stacksize) / (sizeof(portSTACK_TYPE))}

#elif __ZEPHYR__
/**
 * Structure to be used during call to the function
 * os_thread_create(). Please use the macro \ref os_thread_stack_define
 * instead of using this structure directly.
 */
typedef struct
{
    struct k_thread thread;
    uint32_t size;
    k_thread_stack_t *stack;
} os_thread_stack_t;

#ifdef CONFIG_NO_OPTIMIZATIONS
/**
 * Helper macro to define the stack size (in bytes) before a new thread is
 * created using the function os_thread_create().
 * Double stack size for -O0 optimization level as threads consume much more stack memory.
 */
#define os_thread_stack_define(stackname, stacksize)           \
    K_THREAD_STACK_DEFINE(stackname##_stack, (stacksize * 2)); \
    os_thread_stack_t stackname = {                            \
        .size  = K_THREAD_STACK_SIZEOF(stackname##_stack),     \
        .stack = stackname##_stack,                            \
    };
#else
/**
 * Helper macro to define the stack size (in bytes) before a new thread is
 * created using the function os_thread_create().
 */
#define os_thread_stack_define(stackname, stacksize)       \
    K_THREAD_STACK_DEFINE(stackname##_stack, stacksize);   \
    os_thread_stack_t stackname = {                        \
        .size  = K_THREAD_STACK_SIZEOF(stackname##_stack), \
        .stack = stackname##_stack,                        \
    };
#endif
#endif

#if defined(SDK_OS_FREE_RTOS)

typedef TaskHandle_t os_thread_t;

const char *get_current_taskname(void);

#elif __ZEPHYR__

struct zep_thread
{
    k_tid_t id;
    struct k_sem event;
};

typedef struct zep_thread *os_thread_t;

static inline const char *get_current_taskname(void)
{
    k_tid_t tid      = k_current_get();
    const char *name = k_thread_name_get(tid);
    if (name == NULL)
    {
        return "Unknown";
    }
    return name;
}

/**
 * Function wrapper used to account for Zephyr's 3 arguments
 * to a task entry function (OS abstraction expects 1 argument)
 */
void thread_wrapper(void *entry, void *arg, void *unused);

#endif

/** Create new thread
 *
 * This function starts a new thread.  The new thread starts execution by
 * invoking main_func(). The parameter arg is passed as the sole argument of
 * main_func().
 *
 * After finishing execution, the new thread should either call:
 * - os_thread_self_complete() to suspend itself OR
 * - os_thread_delete() to delete itself
 *
 * Failing to do this and just returning from main_func() will result in
 * undefined behavior.
 *
 *
 * @param[out] thandle Pointer to a thread handle
 * @param[in] name Name of the new thread. A copy of this string will be
 * made by the OS for itself. The maximum name length is defined by the
 * macro configMAX_TASK_NAME_LEN in FreeRTOS header file . Any name length
 * above it will be truncated.
 * @param[in] main_func Function pointer to new thread function
 * @param[in] arg The sole argument passed to main_func()
 * @param[in] stack A pointer to initialized object of type \ref
 * os_thread_stack_t. The object should be created and initialized using
 * os_thread_stack_define().
 * @param[in] prio The priority of the new thread. One value among
 * OS_PRIO_0, OS_PRIO_1, OS_PRIO_2, OS_PRIO_3 and OS_PRIO_4 should be
 * passed. OS_PRIO_0 represents the highest priority and OS_PRIO_4
 * represents the lowest priority.
 *
 * @return WM_SUCCESS if thread was created successfully
 * @return -WM_FAIL if thread creation failed
 */
int os_thread_create(os_thread_t *thandle,
                     const char *name,
                     void (*main_func)(os_thread_arg_t arg),
                     void *arg,
                     os_thread_stack_t *stack,
                     int prio);

#if defined(SDK_OS_FREE_RTOS)
os_thread_t os_get_current_task_handle(void);
#elif __ZEPHYR__
static inline os_thread_t os_get_current_task_handle(void)
{
    return k_thread_custom_data_get();
}
#endif

/** Terminate a thread
 *
 * This function deletes a thread. The task being deleted will be removed from
 * all ready, blocked, suspended and event lists.
 *
 * @param[in] thandle Pointer to the thread handle of the thread to be
 * deleted. If self deletion is required NULL should be passed.
 *
 * @return WM_SUCCESS if operation success
 * @return -WM_FAIL if operation fails
 */
int os_thread_delete(os_thread_t *thandle);

/** Sleep for specified number of OS ticks
 *
 * This function causes the calling thread to sleep and block for the given
 * number of OS ticks. The actual time that the task remains blocked depends on
 * the tick rate. The function os_msec_to_ticks() is provided to convert from
 * real-time to ticks.
 *
 * Any other thread can wake up this task specifically using the API
 * os_thread_wait_abort()
 *
 * @param[in] ticks Number of ticks to sleep
 *
 * @return 0 If slept for given ticks or more
 * @return Positive value if woken up before given ticks.
 * @note The value returned is amount of ticks left before the task was
 * to be originally scheduled to be woken up. So if sleep was for 10 ticks
 * and the task is woken up after 8 ticks then 2 will be returned.
 */
#if defined(SDK_OS_FREE_RTOS)
void os_thread_sleep(uint32_t ticks);
#elif __ZEPHYR__
static inline void os_thread_sleep(uint32_t ticks)
{
    os_dprintf("OS: Thread Sleep: %d\r\n", ticks);
    k_sleep(K_TICKS(ticks));
    return;
}
#endif

/** Suspend the given thread
 *
 * - The function os_thread_self_complete() will \b permanently suspend the
 * given thread. Passing NULL will suspend the current thread. This
 * function never returns.
 * - The thread continues to consume system resources. To delete the thread
 * the function os_thread_delete() needs to be called separately.
 *
 * @param[in] thandle Pointer to thread handle
 */
#if defined(SDK_OS_FREE_RTOS)
void os_thread_self_complete(os_thread_t *thandle);
#elif __ZEPHYR__
static inline void os_thread_self_complete(os_thread_t *thandle)
{
    /* Suspend self until someone calls delete. This is required because in
     * freeRTOS, main functions of a thread cannot return.
     */
    if (thandle != NULL)
    {
        os_dprintf("OS: Thread Complete: %p\r\n", thandle);
        k_thread_suspend((*thandle)->id);
    }
    else
    {
        os_dprintf("OS: Thread Complete: SELF\r\n");
        k_thread_suspend(k_current_get());
    }

    /*
     * We do not want this function to return ever.
     */
    while (true)
    {
        os_thread_sleep(os_msec_to_ticks(60000));
    }
}
#endif

#if defined(SDK_OS_FREE_RTOS)

#ifndef CONFIG_WIFI_MAX_PRIO
#error Define CONFIG_WIFI_MAX_PRIO in wifi_config.h
#elif CONFIG_WIFI_MAX_PRIO < 4
#error CONFIG_WIFI_MAX_PRIO must be defined to be greater than or equal to 4
#endif
#define OS_PRIO_0                                CONFIG_WIFI_MAX_PRIO /** High **/
#define OS_PRIO_1                                (CONFIG_WIFI_MAX_PRIO - 1)
#define OS_PRIO_2                                (CONFIG_WIFI_MAX_PRIO - 2)
#define OS_PRIO_3                                (CONFIG_WIFI_MAX_PRIO - 3)
#define OS_PRIO_4                                (CONFIG_WIFI_MAX_PRIO - 4) /** Low **/

#elif __ZEPHYR__

#ifndef CONFIG_WIFI_MAX_PRIO
#define CONFIG_WIFI_MAX_PRIO 1
#endif
#define OS_PRIO_0 CONFIG_WIFI_MAX_PRIO /** High **/
#define OS_PRIO_1 (CONFIG_WIFI_MAX_PRIO + 1)
#define OS_PRIO_2 (CONFIG_WIFI_MAX_PRIO + 2)
#define OS_PRIO_3 (CONFIG_WIFI_MAX_PRIO + 3)
#define OS_PRIO_4 (CONFIG_WIFI_MAX_PRIO + 4) /** Low **/

#endif

#if defined(SDK_OS_FREE_RTOS)

/** Structure used for queue definition */
typedef struct os_queue_pool
{
    /** Size of the queue */
    int size;
} os_queue_pool_t;

/** Define OS Queue pool
 *
 * This macro helps define the name and size of the queue to be created
 * using the function os_queue_create().
 */
#define os_queue_pool_define(poolname, poolsize) os_queue_pool_t poolname = {poolsize};

typedef QueueHandle_t os_queue_t;

#elif __ZEPHYR__

/** Structure used for queue definition */
typedef struct
{
    int size;
    char *buffer;
} os_queue_pool_t;

/** Define OS Queue pool
 *
 * This macro helps define the name and size of the queue to be created
 * using the function os_queue_create().
 */
#define os_queue_pool_define(poolname, poolsize) \
    char __aligned(4) poolname##_pool[poolsize]; \
    os_queue_pool_t poolname = {                 \
        .size   = poolsize,                      \
        .buffer = poolname##_pool,               \
    };

typedef struct k_msgq *os_queue_t;

#endif

/** Create an OS queue
 *
 * This function creates a new queue instance. This allocates the storage
 * required by the new queue and returns a handle for the queue.
 *
 * @param[out] qhandle Pointer to the handle of the newly created queue
 * @param[in] name String specifying the name of the queue
 * @param[in] msgsize The number of bytes each item in the queue will
 * require. Items are queued by copy, not by reference, so this is the
 * number of bytes that will be copied for each posted item. Each item on
 * the queue must be the same size.
 * @param[in] poolname The object of the type \ref os_queue_pool_t. The
 * helper macro os_queue_pool_define() helps to define this object.
 *
 * @return WM_SUCCESS if queue creation was successful
 * @return -WM_FAIL if queue creation failed
 */
int os_queue_create(os_queue_t *qhandle, const char *name, int msgsize, os_queue_pool_t *poolname);

/** Wait Forever */
#if defined(SDK_OS_FREE_RTOS)
#define OS_WAIT_FOREVER                          portMAX_DELAY
#elif __ZEPHYR__
#define OS_WAIT_FOREVER                           UINT32_MAX
#endif

/** Do Not Wait */
#define OS_NO_WAIT 0

/** Post an item to the back of the queue.
 *
 * This function posts an item to the back of a queue. The item is queued by
 * copy, not by reference. This function can also be called from an interrupt
 * service routine.
 *
 * @param[in] qhandle Pointer to the handle of the queue
 * @param[in] msg A pointer to the item that is to be placed on the
 * queue. The size of the items the queue will hold was defined when the
 * queue was created, so this many bytes will be copied from msg
 * into the queue storage area.
 * @param[in] wait The maximum amount of time, in OS ticks, the task should
 * block waiting for space to become available on the queue, should it already
 * be full. The function os_msec_to_ticks() can be used to convert from
 * real-time to OS ticks. The special values \ref OS_WAIT_FOREVER and \ref
 * OS_NO_WAIT are provided to respectively wait infinitely or return
 * immediately.
 *
 * @return WM_SUCCESS if send operation was successful
 * @return -WM_E_INVAL if invalid parameters are passed
 * @return -WM_FAIL if send operation failed
 */
int os_queue_send(os_queue_t *qhandle, const void *msg, unsigned long wait);

/** Receive an item from queue
 *
 * This function receives an item from a queue. The item is received by copy so
 * a buffer of adequate size must be provided. The number of bytes copied into
 * the buffer was defined when the queue was created.
 *
 * @param[in] qhandle Pointer to handle of the queue
 * @param[out] msg Pointer to the buffer into which the received item will
 * be copied. The size of the items in the queue was defined when the queue was
 * created. This pointer should point to a buffer as many bytes in size.
 * @param[in] wait The maximum amount of time, in OS ticks, the task should
 * block waiting for messages to arrive on the queue, should it already
 * be empty. The function os_msec_to_ticks() can be used to convert from
 * real-time to OS ticks. The special values \ref OS_WAIT_FOREVER and \ref
 * OS_NO_WAIT are provided to respectively wait infinitely or return
 * immediately.
 *
 * @return WM_SUCCESS if receive operation was successful
 * @return -WM_E_INVAL if invalid parameters are passed
 * @return -WM_FAIL if receive operation failed
 *
 * \note This function must not be used in an interrupt service routine.
 */
int os_queue_recv(os_queue_t *qhandle, void *msg, unsigned long wait);

/** Delete queue
 *
 * This function deletes a queue. It frees all the memory allocated for storing
 * of items placed on the queue.
 *
 * @param[in] qhandle Pointer to handle of the queue to be deleted.
 *
 * @return Currently always returns WM_SUCCESS
 */
int os_queue_delete(os_queue_t *qhandle);

/** Return the number of messages stored in queue.
 *
 * @param[in] qhandle Pointer to handle of the queue to be queried.
 *
 * @returns Number of items in the queue
 * @return -WM_E_INVAL if invalid parameters are passed
 */
int os_queue_get_msgs_waiting(os_queue_t *qhandle);

#if defined(SDK_OS_FREE_RTOS)

/* Critical Sections */
static inline unsigned long os_enter_critical_section(void)
{
    taskENTER_CRITICAL();
    return WM_SUCCESS;
}

static inline void os_exit_critical_section(unsigned long state)
{
    taskEXIT_CRITICAL();
}

#elif __ZEPHYR__

/* Critical Sections */
static inline unsigned long os_enter_critical_section(void)
{
    return irq_lock();
}

static inline void os_exit_critical_section(unsigned long state)
{
    return irq_unlock(state);
}

#endif

#if defined(SDK_OS_FREE_RTOS)

/*** Tick function */
#define MAX_CUSTOM_HOOKS                         4U

extern void (*g_os_tick_hooks[MAX_CUSTOM_HOOKS])(void);
extern void (*g_os_idle_hooks[MAX_CUSTOM_HOOKS])(void);

/*** Tick function */

/** Setup idle function
 *
 * This function sets up a callback function which will be called whenever the
 * system enters the idle thread context.
 *
 *  @param[in] func The callback function
 *
 *  @return WM_SUCCESS on success
 *  @return -WM_FAIL on error
 */
int os_setup_idle_function(void (*func)(void));
#elif __ZEPHYR__
static inline int os_setup_idle_function(void (*func)(void))
{
    return -WM_FAIL;
}
#endif

/** Setup tick function
 *
 * This function sets up a callback function which will be called on every
 * SysTick interrupt.
 *
 *  @param[in] func The callback function
 *
 *  @return WM_SUCCESS on success
 *  @return -WM_FAIL on error
 */
#if defined(SDK_OS_FREE_RTOS)
int os_setup_tick_function(void (*func)(void));
#elif __ZEPHYR__
static inline int os_setup_tick_function(void (*func)(void))
{
    return -WM_FAIL;
}
#endif

/** Remove idle function
 *
 *  This function removes an idle callback function that was registered
 *  previously using os_setup_idle_function().
 *
 *  @param[in] func The callback function
 *
 *  @return WM_SUCCESS on success
 *  @return -WM_FAIL on error
 */
#if defined(SDK_OS_FREE_RTOS)
int os_remove_idle_function(void (*func)(void));
#elif __ZEPHYR__
static inline int os_remove_idle_function(void (*func)(void))
{
    return -WM_FAIL;
}
#endif

/** Remove tick function
 *
 *  This function removes a tick callback function that was registered
 *  previously using os_setup_tick_function().
 *
 *  @param[in] func Callback function
 *  @return WM_SUCCESS on success
 *  @return -WM_FAIL on error
 */
#if defined(SDK_OS_FREE_RTOS)
int os_remove_tick_function(void (*func)(void));
#elif __ZEPHYR__
static inline int os_remove_tick_function(void (*func)(void))
{
    return -WM_FAIL;
}
#endif

#if defined(SDK_OS_FREE_RTOS)
/*** Mutex ***/
typedef SemaphoreHandle_t os_mutex_t;
#elif __ZEPHYR__
/*** Mutex ***/
typedef struct k_mutex *os_mutex_t;
#endif

/** Priority Inheritance Enabled */
#define OS_MUTEX_INHERIT 1
/** Priority Inheritance Disabled */
#define OS_MUTEX_NO_INHERIT 0

/** Create mutex
 *
 * This function creates a mutex.
 *
 * @param [out] mhandle Pointer to a mutex handle
 * @param [in] name Name of the mutex
 * @param [in] flags Priority inheritance selection. Valid options are \ref
 * OS_MUTEX_INHERIT or \ref OS_MUTEX_NO_INHERIT.
 *
 * @note Currently non-inheritance in mutex is not supported.
 *
 * @return WM_SUCCESS on success
 * @return -WM_FAIL on error
 */
int os_mutex_create(os_mutex_t *mhandle, const char *name, int flags);

/** Acquire mutex
 *
 * This function acquires a mutex. Only one thread can acquire a mutex at any
 * given time. If already acquired the callers will be blocked for the specified
 * time duration.
 *
 * @param[in] mhandle Pointer to mutex handle
 * @param[in] wait The maximum amount of time, in OS ticks, the task should
 * block waiting for the mutex to be acquired. The function os_msec_to_ticks()
 * can be used to convert from real-time to OS ticks. The special values \ref
 * OS_WAIT_FOREVER and \ref OS_NO_WAIT are provided to respectively wait
 * infinitely or return immediately.
 *
 * @return WM_SUCCESS when mutex is acquired
 * @return -WM_E_INVAL if invalid parameters are passed
 * @return -WM_FAIL on failure
 */
int os_mutex_get(os_mutex_t *mhandle, unsigned long wait);

/** Release mutex
 *
 * This function releases a mutex previously acquired using os_mutex_get().
 *
 * @note The mutex should be released from the same thread context from which it
 * was acquired. If you wish to acquire and release in different contexts,
 * please use os_semaphore_get() and os_semaphore_put() variants.
 *
 * @param[in] mhandle Pointer to the mutex handle
 *
 * @return WM_SUCCESS when mutex is released
 * @return -WM_E_INVAL if invalid parameters are passed
 * @return -WM_FAIL on failure
 */
int os_mutex_put(os_mutex_t *mhandle);

/**
 * Create recursive mutex
 *
 * This function creates a recursive mutex. A mutex used recursively can be
 * 'get' repeatedly by the owner. The mutex doesn't become available again
 * until the owner has called os_recursive_mutex_put() for each
 * successful 'get' request.
 *
 * @note This type of mutex uses a priority inheritance mechanism so a
 * task 'get'ing a mutex MUST ALWAYS 'put' the mutex back once no longer
 * required.
 *
 * @param[out] mhandle Pointer to a mutex handle
 * @param[in] name Name of the mutex as NULL terminated string
 *
 * @return WM_SUCCESS on success
 * @return -WM_E_INVAL on invalid parameter.
 * @return -WM_FAIL on error
 */
int os_recursive_mutex_create(os_mutex_t *mhandle, const char *name);

/**
 * Get recursive mutex
 *
 * This function recursively obtains, or 'get's, a mutex. The mutex must
 * have previously been created using a call to
 * os_recursive_mutex_create().
 *
 * @param[in] mhandle Pointer to mutex handle obtained from
 * os_recursive_mutex_create().
 * @param[in] wait The maximum amount of time, in OS ticks, the task should
 * block waiting for the mutex to be acquired. The function os_msec_to_ticks()
 * can be used to convert from real-time to OS ticks. The special values \ref
 * OS_WAIT_FOREVER and \ref OS_NO_WAIT are provided to respectively wait
 * for portMAX_DELAY (0xffffffff) or return immediately.
 *
 * @return WM_SUCCESS when recursive mutex is acquired
 * @return -WM_FAIL on failure

 */
int os_recursive_mutex_get(os_mutex_t *mhandle, unsigned long wait);

/**
 * Put recursive mutex
 *
 * This function recursively releases, or 'give's, a mutex. The mutex must
 * have previously been created using a call to
 * os_recursive_mutex_create()
 *
 * @param[in] mhandle Pointer to the mutex handle
 *
 * @return WM_SUCCESS when mutex is released
 * @return -WM_FAIL on failure
 */
int os_recursive_mutex_put(os_mutex_t *mhandle);

/** Delete mutex
 *
 * This function deletes a mutex.
 *
 * @param[in] mhandle Pointer to the mutex handle
 *
 * @note A mutex should not be deleted if other tasks are blocked on it.
 *
 * @return WM_SUCCESS on success
 */
int os_mutex_delete(os_mutex_t *mhandle);

/*** Event Notification ***/

/**
 * Wait for task notification
 *
 * This function waits for task notification from other task or interrupt
 * context. This is similar to binary semaphore, but uses less RAM and much
 * faster than semaphore mechanism
 *
 * @param[in] wait_time Timeout specified in no. of OS ticks
 *
 * @return WM_SUCCESS when notification is successful
 * @return -WM_FAIL on failure or timeout
 */
#if defined(SDK_OS_FREE_RTOS)
int os_event_notify_get(unsigned long wait_time);
#elif __ZEPHYR__
static inline int os_event_notify_get(unsigned long wait_time)
{
    os_thread_t task = os_get_current_task_handle();
    int ret          = k_sem_take(&task->event, K_TICKS(wait_time));
    return ret == 0 ? -WM_FAIL : WM_SUCCESS;
}
#endif

/**
 * Give task notification
 *
 * This function gives task notification so that waiting task can be
 * unblocked. This is similar to binary semaphore, but uses less RAM and much
 * faster than semaphore mechanism
 *
 * @param[in] task Task handle to be notified
 *
 * @return WM_SUCCESS when notification is successful
 * @return -WM_FAIL on failure or timeout
 */
#if defined(SDK_OS_FREE_RTOS)
int os_event_notify_put(os_thread_t task);
#elif __ZEPHYR__
static inline int os_event_notify_put(os_thread_t task)
{
    k_sem_give(&task->event);
    return WM_SUCCESS;
}
#endif

#if defined(SDK_OS_FREE_RTOS)
/*** Semaphore ***/
typedef SemaphoreHandle_t os_semaphore_t;
#elif __ZEPHYR__
/*** Semaphore ***/
typedef struct k_sem *os_semaphore_t;
#endif

/** Create binary semaphore
 *
 * This function creates a binary semaphore. A binary semaphore can be acquired
 * by only one entity at a given time.
 *
 * @param[out] mhandle Pointer to a semaphore handle
 * @param[in] name Name of the semaphore
 *
 * @return WM_SUCCESS on success
 * @return -WM_FAIL on error
 */
int os_semaphore_create(os_semaphore_t *mhandle, const char *name);

/** Create counting semaphore
 *
 * This function creates a counting semaphore. A counting semaphore can be
 * acquired 'count' number of times at a given time.
 *
 * @param[out] mhandle Pointer to a semaphore handle
 * @param[in] name Name of the semaphore
 * @param[in] maxcount The maximum count value that can be reached. When
 * the semaphore reaches this value it can no longer be 'put'
 * @param[in] initcount The count value assigned to the semaphore when it
 * is created. For e.g. If '0' is passed, then os_semaphore_get() will
 * block until some other thread does an os_semaphore_put().
 *
 * @return WM_SUCCESS on success
 * @return -WM_FAIL on error
 */
int os_semaphore_create_counting(os_semaphore_t *mhandle,
                                 const char *name,
                                 unsigned long maxcount,
                                 unsigned long initcount);

/** Acquire semaphore
 *
 * This function acquires a semaphore. At a given time, a binary semaphore can
 * be acquired only once, while a counting semaphore can be acquired as many as
 * 'count' number of times. Once this condition is reached, the other callers of
 * this function will be blocked for the specified time duration.
 *
 * @param[in] mhandle Pointer to a semaphore handle
 * @param[in] wait The maximum amount of time, in OS ticks, the task should
 * block waiting for the semaphore to be acquired. The function
 * os_msec_to_ticks() can be used to convert from real-time to OS ticks. The
 * special values \ref OS_WAIT_FOREVER and \ref OS_NO_WAIT are provided to
 * respectively wait infinitely or return immediately.
 *
 * @return WM_SUCCESS when semaphore is acquired
 * @return -WM_E_INVAL if invalid parameters are passed
 * @return -WM_FAIL on failure
 */
int os_semaphore_get(os_semaphore_t *mhandle, unsigned long wait);

/** Release semaphore
 *
 * This function releases a semaphore previously acquired using
 * os_semaphore_get().
 *
 * @note This function can also be called from interrupt-context.
 *
 * @param[in] mhandle Pointer to a semaphore handle
 *
 * @return WM_SUCCESS when semaphore is released
 * @return -WM_E_INVAL if invalid parameters are passed
 * @return -WM_FAIL on failure
 */
int os_semaphore_put(os_semaphore_t *mhandle);

/** Get semaphore count
 *
 * This function returns the current value of a semaphore.
 *
 * @param[in] mhandle Pointer to a semaphore handle
 *
 * @return current value of the semaphore
 */
int os_semaphore_getcount(os_semaphore_t *mhandle);

/** Delete a semaphore
 *
 * This function deletes the semaphore.
 *
 * @param [in] mhandle Pointer to a semaphore handle
 *
 * @note Do not delete a semaphore that has tasks blocked on it (tasks that are
 * in the Blocked state waiting for the semaphore to become available)
 *
 * @return WM_SUCCESS on success
 */
int os_semaphore_delete(os_semaphore_t *mhandle);

/*
 * Reader Writer Locks
 * This is a generic implementation of reader writer locks
 * which is reader priority.
 * Not only it provides mutual exclusion but also synchronization.
 * Six APIs are exposed to user which include.
 * -# Create a reader writer lock
 * -# Delete a reader writer lock
 * -# Reader lock
 * -# Reader unlock
 * -# Writer lock
 * -# Writer unlock
 * The locking operation is timeout based.
 * Caller can give a timeout from 0 (no wait) to
 * infinite (wait forever)
 */

typedef struct _rw_lock os_rw_lock_t;
/** This is prototype of reader callback */
typedef int (*cb_fn)(os_rw_lock_t *plock, unsigned int wait_time);

struct _rw_lock
{
    /** Mutex for reader mutual exclusion */
    os_mutex_t reader_mutex;
    /** Mutex for write mutual exclusion */
    os_mutex_t write_mutex;
    /** Lock which when held by reader,
     *  writer cannot enter critical section
     */
    os_semaphore_t rw_lock;
    /** Function being called when first reader gets
     *  the lock
     */
    cb_fn reader_cb;
    /** Counter to maintain number of readers
     *  in critical section
     */
    unsigned int reader_count;
};

int os_rwlock_create_with_cb(os_rw_lock_t *lock, const char *mutex_name, const char *lock_name, cb_fn r_fn);

/** Create reader-writer lock
 *
 * This function creates a reader-writer lock.
 *
 * @param[in] lock Pointer to a reader-writer lock handle
 * @param[in] mutex_name Name of the mutex
 * @param[in] lock_name Name of the lock
 *
 * @return WM_SUCCESS on success
 * @return -WM_FAIL on error
 */
int os_rwlock_create(os_rw_lock_t *lock, const char *mutex_name, const char *lock_name);

/** Delete a reader-write lock
 *
 * This function deletes a reader-writer lock.
 *
 * @param[in] lock Pointer to the reader-writer lock handle
 *
 */
void os_rwlock_delete(os_rw_lock_t *lock);

/** Acquire writer lock
 *
 * This function acquires a writer lock. While readers can acquire the lock on a
 * sharing basis, writers acquire the lock in an exclusive manner.
 *
 * @param[in] lock Pointer to the reader-writer lock handle
 * @param[in] wait_time The maximum amount of time, in OS ticks, the task should
 * block waiting for the lock to be acquired. The function os_msec_to_ticks()
 * can be used to convert from real-time to OS ticks. The special values \ref
 * OS_WAIT_FOREVER and \ref OS_NO_WAIT are provided to respectively wait
 * infinitely or return immediately.
 *
 * @return  WM_SUCCESS on success
 * @return  -WM_FAIL on error
 *
 */
int os_rwlock_write_lock(os_rw_lock_t *lock, unsigned int wait_time);

/** Release writer lock
 *
 * This function releases a writer lock previously acquired using
 * os_rwlock_write_lock().
 *
 * @param[in] lock Pointer to the reader-writer lock handle
 */
void os_rwlock_write_unlock(os_rw_lock_t *lock);

/** Acquire reader lock
 *
 * This function acquires a reader lock. While readers can acquire the lock on a
 * sharing basis, writers acquire the lock in an exclusive manner.
 *
 * @param[in] lock pointer to the reader-writer lock handle
 * @param[in] wait_time The maximum amount of time, in OS ticks, the task should
 * block waiting for the lock to be acquired. The function os_msec_to_ticks()
 * can be used to convert from real-time to OS ticks. The special values \ref
 * OS_WAIT_FOREVER and \ref OS_NO_WAIT are provided to respectively wait
 * infinitely or return immediately.
 *
 * @return  WM_SUCCESS on success
 * @return  -WM_FAIL on error
 *
 */
int os_rwlock_read_lock(os_rw_lock_t *lock, unsigned int wait_time);

/** Release reader lock
 *
 * This function releases a reader lock previously acquired using
 * os_rwlock_read_lock().
 *
 * @param[in] lock pointer to the reader-writer lock handle
 *
 * @return WM_SUCCESS if unlock operation successful.
 * @return -WM_FAIL if unlock operation failed.
 */
int os_rwlock_read_unlock(os_rw_lock_t *lock);

/*** Timer Management ***/
#if defined(SDK_OS_FREE_RTOS)
typedef TimerHandle_t os_timer_t;
typedef os_timer_t os_timer_arg_t;
typedef TickType_t os_timer_tick;
#elif __ZEPHYR__
struct timer_data;

typedef struct timer_data *os_timer_t;
typedef os_timer_t os_timer_arg_t;
typedef int os_timer_tick;

/** OS Timer data structure
 */
struct timer_data
{
    void (*callback)(os_timer_arg_t);
    void *user_arg;
    int period;
    int reload_options;
    struct k_timer timer;
    struct k_work work;
};
#endif

/** OS Timer reload Options
 *
 */
typedef enum os_timer_reload
{
    /**
     * Create one shot timer. Timer will be in the dormant state after
     * it expires.
     */
    OS_TIMER_ONE_SHOT,
    /**
     * Create a periodic timer. Timer will auto-reload after it expires.
     */
    OS_TIMER_PERIODIC,
} os_timer_reload_t;

/**
 * OS Timer Activate Options
 */
typedef enum os_timer_activate
{
    /** Start the timer on creation. */
    OS_TIMER_AUTO_ACTIVATE,
    /** Do not start the timer on creation. */
    OS_TIMER_NO_ACTIVATE,
} os_timer_activate_t;

/** Create timer
 *
 * This function creates a timer.
 *
 * @param[out] timer_t Pointer to the timer handle
 * @param[in] name Name of the timer
 * @param[in] ticks Period in ticks
 * @param[in] call_back Timer expire callback function
 * @param[in] cb_arg Timer callback data
 * @param[in] reload Reload Options, valid values include \ref OS_TIMER_ONE_SHOT
 * or \ref OS_TIMER_PERIODIC.
 * @param[in] activate Activate Options, valid values include \ref
 * OS_TIMER_AUTO_ACTIVATE or \ref OS_TIMER_NO_ACTIVATE
 *
 * @return WM_SUCCESS if timer created successfully
 * @return -WM_FAIL if timer creation fails
 */
int os_timer_create(os_timer_t *timer_t,
                    const char *name,
                    os_timer_tick ticks,
                    void (*call_back)(os_timer_arg_t),
                    void *cb_arg,
                    os_timer_reload_t reload,
                    os_timer_activate_t activate);

/** Activate timer
 *
 * This function activates (or starts) a timer that was previously created using
 * os_timer_create(). If the timer had already started and was already in the
 * active state, then this call is equivalent to os_timer_reset().
 *
 * @param[in] timer_t Pointer to a timer handle
 *
 * @return WM_SUCCESS if timer activated successfully
 * @return -WM_E_INVAL if invalid parameters are passed
 * @return -WM_FAIL if timer fails to activate
 */
int os_timer_activate(os_timer_t *timer_t);

/** Change timer period
 *
 * This function changes the period of a timer that was previously created using
 * os_time_create(). This function changes the period of an active or dormant
 * state timer.
 *
 * @param[in] timer_t Pointer to a timer handle
 * @param[in] ntime Time in ticks after which the timer will expire
 * @param[in] block_time  This option is currently not supported
 *
 * @return WM_SUCCESS on success
 * @return -WM_E_INVAL if invalid parameters are passed
 * @return -WM_FAIL on failure
 */
int os_timer_change(os_timer_t *timer_t, os_timer_tick ntime, os_timer_tick block_time);

/** Check the timer active state
 *
 * This function checks if the timer is in the active or dormant state. A timer
 * is in the dormant state if (a) it has been created but not started, or (b) it
 * has expired and a one-shot timer.
 *
 * @param [in] timer_t Pointer to a timer handle
 *
 * @return true if timer is active
 * @return false if time is not active
 */
bool os_timer_is_running(os_timer_t *timer_t);

/**
 * Get the timer context
 *
 * This function helps to retrieve the timer context i.e. 'cb_arg' passed
 * to os_timer_create().
 *
 * @param[in] timer_t Pointer to timer handle. The timer handle is received
 * in the timer callback.
 *
 * @return The timer context i.e. the callback argument passed to
 * os_timer_create().
 */
void *os_timer_get_context(os_timer_t *timer_t);

/** Reset timer
 *
 * This function resets a timer that was previously created using using
 * os_timer_create(). If the timer had already been started and was already in
 * the active state, then this call will cause the timer to re-evaluate its
 * expiry time so that it is relative to when os_timer_reset() was called. If
 * the timer was in the dormant state then this call behaves in the same way as
 * os_timer_activate().
 *
 * @param[in] timer_t Pointer to a timer handle
 *
 * @return WM_SUCCESS on success
 * @return -WM_E_INVAL if invalid parameters are passed
 * @return -WM_FAIL on failure
 */
int os_timer_reset(os_timer_t *timer_t);

/** Deactivate timer
 *
 * This function deactivates (or stops) a timer that was previously started.
 *
 * @param [in] timer_t handle populated by os_timer_create()
 *
 * @return WM_SUCCESS on success
 * @return -WM_E_INVAL if invalid parameters are passed
 * @return -WM_FAIL on failure
 */
int os_timer_deactivate(os_timer_t *timer_t);

/** Delete timer
 *
 * This function deletes a timer.
 *
 * @param[in] timer_t Pointer to a timer handle
 *
 * @return WM_SUCCESS on success
 * @return -WM_E_INVAL if invalid parameters are passed
 * @return -WM_FAIL on failure
 */
int os_timer_delete(os_timer_t *timer_t);

/** Allocate memory
 *
 * This function allocates memory dynamically.
 *
 *  @param[in] size Size of the memory to be allocated
 *
 * @return Pointer to the allocated memory
 * @return NULL if allocation fails
 */
void *os_mem_alloc(size_t size);

/** Allocate memory and zero it
 *
 * This function allocates memory dynamically and sets the memory contents to
 * zero.
 *
 * @param[in] size Size of the memory to be allocated
 *
 * @return Pointer to the allocated memory
 * @return NULL if allocation fails
 */
void *os_mem_calloc(size_t size);

/** Reallocate memory
 *
 * This function attempts to resize a previously allocated memory block.
 *
 *  @param[in] old_ptr Pointer to earlier allocated memory
 *  @param[in] new_size The new size
 *
 * @return Pointer to the newly resized memory block
 * @return NULL if reallocation fails
 */
void *os_mem_realloc(void *old_ptr, size_t new_size);

/** Free Memory
 *
 * This function frees dynamically allocated memory using any of the dynamic
 * allocation primitives.
 *
 * @param[in] ptr Pointer to the memory to be freed
 */
void os_mem_free(void *ptr);

/** This function dumps complete statistics
 *  of the heap memory.
 */
#ifdef CONFIG_HEAP_STAT
/** This function dumps complete statistics
 *  of the heap memory.
 */
#if defined(SDK_OS_FREE_RTOS)
void os_dump_mem_stats(void);
#elif __ZEPHYR__
static inline void os_dump_mem_stats(void)
{
    return;
}
#endif

#endif

typedef unsigned int event_group_handle_t;

typedef enum flag_rtrv_option_t_
{
    EF_AND,
    EF_AND_CLEAR,
    EF_OR,
    EF_OR_CLEAR
} flag_rtrv_option_t;

#define EF_NO_WAIT      0
#define EF_WAIT_FOREVER 0xFFFFFFFFUL
#define EF_NO_EVENTS    0x7

int os_event_flags_create(event_group_handle_t *hnd);
int os_event_flags_get(event_group_handle_t hnd,
                       unsigned requested_flags,
                       flag_rtrv_option_t option,
                       unsigned *actual_flags_ptr,
                       unsigned wait_option);
int os_event_flags_set(event_group_handle_t hnd, unsigned flags_to_set, flag_rtrv_option_t option);

/**** OS init call **********/
WEAK int os_init(void);

void _os_delay(int cnt);

#if defined(SDK_OS_FREE_RTOS)

/**
 * \def os_get_runtime_stats(__buff__)
 *
 * Get ASCII formatted run time statistics
 *
 * Please ensure that your buffer is big enough for the formatted data to
 * fit. Failing to do this may cause memory data corruption.
 */
#define os_get_runtime_stats(__buff__) vTaskGetRunTimeStats(__buff__)

/**
 * \def os_get_task_list(__buff__)
 *
 * Get ASCII formatted task list
 *
 * Please ensure that your buffer is big enough for the formatted data to
 * fit. Failing to do this may cause memory data corruption.
 */

#define os_get_task_list(__buff__) vTaskList(__buff__)

/** Disables all interrupts at NVIC level */
void os_disable_all_interrupts(void);

/** Enable all interrupts at NVIC lebel */
void os_enable_all_interrupts(void);

/** Disable all tasks schedule */
static inline void os_lock_schedule(void)
{
    vTaskSuspendAll();
}

/** Enable all tasks schedule */
static inline void os_unlock_schedule(void)
{
    xTaskResumeAll();
}

#elif __ZEPHYR__

/** Disables all interrupts at NVIC level */
static inline void os_disable_all_interrupts(void)
{
    __disable_irq();
}

/** Enable all interrupts at NVIC lebel */
static inline void os_enable_all_interrupts(void)
{
    __enable_irq();
}

/** Disable all tasks schedule */
static inline void os_lock_schedule(void)
{
    k_sched_lock();
}

/** Enable all tasks schedule */
static inline void os_unlock_schedule(void)
{
    k_sched_unlock();
}

#endif

/* Init value for rand generator seed */
extern uint32_t wm_rand_seed;

/** This function initialize the seed for rand generator
 *  @return a uint32_t random numer
 */
static inline void os_srand(uint32_t seed)
{
    wm_rand_seed = seed;
}

/** This function generate a random number
 *  @return a uint32_t random numer
 */
static inline uint32_t os_rand()
{
    if (wm_rand_seed == -1)
        os_srand(os_ticks_get());
    wm_rand_seed = (uint32_t)((((uint64_t)wm_rand_seed * 279470273UL) % 4294967291UL) & 0xFFFFFFFFUL);
    return wm_rand_seed;
}

/** This function generate a random number in a range
 *  @param [in] low  range low
 *  @param [in] high range high
 *  @return a uint32_t random numer
 */
static inline uint32_t os_rand_range(uint32_t low, uint32_t high)
{
    uint32_t tmp;
    if (low == high)
        return low;
    if (low > high)
    {
        tmp  = low;
        low  = high;
        high = tmp;
    }
    return (low + os_rand() % (high - low));
}

#if defined(SDK_OS_FREE_RTOS)

void os_dump_threadinfo(char *name);


void os_get_num_of_tasks(uint8_t *num_tasks);
#endif

#endif /* ! _WM_OS_H_ */
