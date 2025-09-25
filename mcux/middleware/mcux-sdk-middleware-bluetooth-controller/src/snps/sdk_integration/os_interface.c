/* Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "os_wrapper.h"
#include "fsl_os_abstraction.h"
#include <limits.h>
#include <assert.h>

#define OS_INTERFACE_NB_OF_TASKS 2
#define OS_INTERFACE_NB_OF_SEMAPHORES 2
#define OS_INTERFACE_NB_OF_MUTEXES 1

OSA_SR_ALLOC();

static uint32_t nestingDepth = 0;

typedef struct
{
    os_priority llPrio;
    unsigned int osaPrio;
} prio_map_t;

static unsigned int GetOSAPrio(os_priority llPrio)
{
    unsigned int osaPrio = UINT_MAX;
    static const prio_map_t prioMap[] = {
        {.llPrio = os_priority_high, .osaPrio = OSA_PRIORITY_REAL_TIME},
        {.llPrio = os_priority_normal, .osaPrio = OSA_PRIORITY_HIGH},
        {.llPrio = os_priority_low, .osaPrio = OSA_PRIORITY_NORMAL}
    };

    for (int i = 0; i < (sizeof(prioMap) / sizeof(prioMap[0])); i++)
    {
        if (prioMap[i].llPrio == llPrio)
        {
            osaPrio = prioMap[i].osaPrio;
            break;
        }
    }

    assert(osaPrio < UINT_MAX);
    return osaPrio;
}

static void ThreadLL(osa_task_param_t task_param)
{
    (void)task_param;
}

static void ThreadLLHighPrio(osa_task_param_t task_param)
{
    (void)task_param;
}

os_thread_id os_thread_create(os_pthread thread, char* name,os_priority pri, void* argu, uint32_t stack_size)
{
    static OSA_TASK_DEFINE(ThreadLL, 0, 1, OS_WRAPPER_LL_THREAD_STACK_SIZE_BYTES, 0);
    static OSA_TASK_HANDLE_DEFINE(threadLLHandle);
    static bool threadLL_initialized = false;

    static OSA_TASK_DEFINE(ThreadLLHighPrio, 0, 1, OS_WRAPPER_LL_HIGH_PRIO_THREAD_STACK_SIZE_BYTES, 0);
    static OSA_TASK_HANDLE_DEFINE(threadLLHighPrioHandle);
    static bool threadLLHighPrio_initialized = false;

    osa_status_t osaStatus = KOSA_StatusError;
    osa_task_handle_t ret = NULL;
    static uint32_t count = 0;

    do
    {
        if (count >= OS_INTERFACE_NB_OF_TASKS)
        {
            assert(false);
            break;
        }

        osa_task_def_t threadDef;
        osa_task_handle_t handle = NULL;
        count++;

        if ((stack_size == OS_WRAPPER_LL_THREAD_STACK_SIZE_BYTES) && (threadLL_initialized == false))
        {
            threadLL_initialized = true;
            memcpy(&threadDef, OSA_TASK(ThreadLL), sizeof(osa_task_def_t));
            handle = threadLLHandle;
        }
        else if ((stack_size == OS_WRAPPER_LL_HIGH_PRIO_THREAD_STACK_SIZE_BYTES) && (threadLLHighPrio_initialized == false))
        {
            threadLLHighPrio_initialized = true;
            memcpy(&threadDef, OSA_TASK(ThreadLLHighPrio), sizeof(osa_task_def_t));
            handle = threadLLHighPrioHandle;
        }
        else
        {
            assert(false);
            break;
        }

        threadDef.pthread = (osa_task_ptr_t)thread;
        threadDef.tname = (uint8_t*)name;
        threadDef.tpriority = GetOSAPrio(pri);
        assert(threadDef.stacksize == stack_size);

        osaStatus = OSA_TaskCreate(handle, &threadDef, argu);
        assert_equal(osaStatus, KOSA_StatusSuccess);
        if (osaStatus != KOSA_StatusSuccess)
        {
            break;
        }

        ret = handle;

    } while (false);

    return (os_thread_id)ret;
}

void os_disable_isr(void)
{
    if (nestingDepth == 0)
    {
        OSA_ENTER_CRITICAL();
    }
    nestingDepth++;
}

void os_enable_isr(void)
{
    nestingDepth--;
    if (nestingDepth == 0)
    {
        OSA_EXIT_CRITICAL();
    }
}

os_semaphore_id os_semaphore_create(int32_t max_count,
    int32_t initial_count)
{
    (void)max_count;
    osa_semaphore_handle_t semaphore = NULL;
    osa_status_t osaStatus = KOSA_StatusError;
    static OSA_SEMAPHORE_HANDLE_DEFINE(semaphores[OS_INTERFACE_NB_OF_SEMAPHORES]);
    static uint32_t count = 0;
    do
    {
        if (count >= OS_INTERFACE_NB_OF_SEMAPHORES)
        {
            assert(false);
            break;
        }
        semaphore = (osa_semaphore_handle_t)semaphores[count];
        count++;
        osaStatus = OSA_SemaphoreCreate(semaphore, initial_count);
        assert_equal(osaStatus, KOSA_StatusSuccess);
        if (osaStatus != KOSA_StatusSuccess)
        {
            semaphore = NULL;
            break;
        }
    } while (false);
    return (os_semaphore_id)semaphore;
}

int32_t os_semaphore_wait(os_semaphore_id semaphore_id, uint32_t millisec)
{
    /* millic 0 and ~0 mean the same in snps LL and in OSA */
    return (int32_t)OSA_SemaphoreWait((osa_semaphore_handle_t)semaphore_id, millisec);
}

int32_t os_semaphore_release(
        os_semaphore_id semaphore_id)
{
    return (int32_t)OSA_SemaphorePost((osa_semaphore_handle_t)semaphore_id);
}

int32_t os_semaphore_release_isr(os_semaphore_id semaphore_id)
{
    /*
     * OSA_SemaphorePost's implementation checks if the call takes place
     * in interrupt context and calls the corresponding OS specific ISR variant
     * */
    return (int32_t)OSA_SemaphorePost((osa_semaphore_handle_t)semaphore_id);
}

os_mutex_id os_rcrsv_mutex_create(void)
{
    osa_mutex_handle_t mutex = NULL;
    osa_status_t osaStatus = KOSA_StatusError;
    static OSA_MUTEX_HANDLE_DEFINE(mutexes[OS_INTERFACE_NB_OF_MUTEXES]);
    static uint32_t count = 0;
    do
    {
        if (count >= OS_INTERFACE_NB_OF_MUTEXES)
        {
            assert(false);
            break;
        }
        mutex = (osa_mutex_handle_t)mutexes[count];
        count++;
        osaStatus = OSA_MutexCreate(mutex);
        assert_equal(osaStatus, KOSA_StatusSuccess);
        if (osaStatus != KOSA_StatusSuccess)
        {
            mutex = NULL;
            break;
        }
    } while (false);
    return (os_mutex_id)mutex;
}

int32_t os_rcrsv_mutex_release(os_mutex_id mutex_id)
{
    return (int32_t)OSA_MutexUnlock((osa_mutex_handle_t)mutex_id);
}

int32_t os_rcrsv_mutex_wait(os_mutex_id mutex_id, uint32_t millisec)
{
    /* millic 0 and ~0 mean the same in snps LL and in OSA */
    return (int32_t)OSA_MutexLock((osa_mutex_handle_t)mutex_id, millisec);
}
