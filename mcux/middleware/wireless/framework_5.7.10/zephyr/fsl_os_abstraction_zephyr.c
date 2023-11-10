/**
 * 2023-11-03 - Created by Sendrato.com
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>

#include "fsl_os_abstraction.h"

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(nxp_osa, LOG_LEVEL_NONE);

#define OSA_EVENT_MAX          (5)
#define OSA_EVENT_ID2IDX(x)    (((uint32_t)x)-1)
#define OSA_EVENT_IDX2ID(x)    ((osaEventId_t)(x+1))

#define OSA_MUTEX_MAX          (5)
#define OSA_MUTEX_ID2IDX(x)    (((uint32_t)x)-1)
#define OSA_MUTEX_IDX2ID(x)    ((osaMutexId_t)(x+1))

static uint8_t _osa_event_idx = 0;
static struct k_event _osa_event[OSA_EVENT_MAX] = { 0 };
static bool _osa_event_autoclear[OSA_EVENT_MAX] = { 0 };

static uint8_t _osa_mutex_idx = 0;
static struct k_mutex _osa_mutex[OSA_MUTEX_MAX] = { 0 };

uint32_t gInterruptDisableCount = 0;

/*FUNCTION**********************************************************************
 *
 * Function Name : OSA_EnableIRQGlobal
 * Description   : Disable system interrupt.
 *
 *END**************************************************************************/
void OSA_EnableIRQGlobal(void)
{
    if (gInterruptDisableCount > 0)
    {
        gInterruptDisableCount--;

        if (gInterruptDisableCount == 0)
        {
            __enable_irq();
        }
        /* call core API to enable the global interrupt*/
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : OSA_DisableIRQGlobal
 * Description   : Disable system interrupt
 * This function will disable the global interrupt by calling the core API
 *
 *END**************************************************************************/
void OSA_DisableIRQGlobal(void)
{
    /* call core API to disable the global interrupt*/
    __disable_irq();

    /* update counter*/
    gInterruptDisableCount++;
}

/**
 * @brief  This function is used to create an event object.
 *
 * This function creates an event object and set its clear mode. If autoClear
 * is TRUE, when a task gets the event flags, these flags will be cleared
 * automatically. Otherwise these flags must be cleared manually.
 *
 * @param[in] autoClear Autoclear event
 * @return              EventId of the new event, or NULL if failed.
 */
osaEventId_t OSA_EventCreate(bool_t autoClear)
{
    if (_osa_event_idx <= OSA_EVENT_MAX) {
        struct k_event *event_group = &_osa_event[_osa_event_idx];
        k_event_init(event_group);
        _osa_event_autoclear[_osa_event_idx] = autoClear;

        osaEventId_t event_id = OSA_EVENT_IDX2ID(_osa_event_idx);
        _osa_event_idx++;

       return event_id;
    }

    return NULL;
}


/**
 * @brief  Set one or more event flags of an event object
 *
 * @param[in] eventId     Pointer to the event.
 * @param[in] flagsToSet  Flags to be set.
 * @return                osaStatus_Success if set successfully,
 *                        osaStatus_Error if failed.
 */
osaStatus_t OSA_EventSet(osaEventId_t eventId, osaEventFlags_t flagsToSet)
{
    if (eventId == NULL) {
        return osaStatus_Error;
    }

    uint8_t event_idx = OSA_EVENT_ID2IDX(eventId);
    if (event_idx >= OSA_EVENT_MAX) {
        return osaStatus_Error;
    }

    struct k_event *event_group = &_osa_event[event_idx];
    if (event_group == NULL) {
        return osaStatus_Error;
    }

    k_event_post(event_group, flagsToSet);

    /* Ensure we do not yield when called from IRQ-context */
    if (!k_is_in_isr()) {
        k_yield();
    }

    return osaStatus_Success;
}


/**
 * @brief  Waits for specified event flags to be set.
 *
 * This function waits for a combination of flags to be set in an event object.
 * Applications can wait for any/all bits to be set. Also this function could
 * obtain the flags who wakeup the waiting task.
 *
 * Zephyr allows usage of full 32 bit flagsToWait.
 *
 * @param[in] eventId     Pointer to the event.
 * @param[in] flagsToWait Flags that to wait.
 * @param[in] waitAll     Wait all flags or any flag to be set.
 * @param[in] millisec    The maximum number of milliseconds to wait for the
 *                        event. If the wait condition is not met, pass
 *                        osaWaitForever_c will wait indefinitely, pass 0 will
 *                        return osaStatus_Timeout immediately.
 * @param[in] setFlags    Flags that wakeup the waiting task are obtained by
 *                        this parameter.
 *
 * @return                osaStatus_Success: if the wait condition is met and
 *                        function returns successfully.
 *                        osaStatus_Timeout: Not met wait condition within timeout.
 *                        osaStatus_Error: An incorrect parameter was passed.
 */
osaStatus_t OSA_EventWait(osaEventId_t eventId, osaEventFlags_t flagsToWait,
                            bool_t waitAll, uint32_t millisec,
                            osaEventFlags_t *pSetFlags)
{
    if (eventId == NULL) {
        return osaStatus_Error;
    }

    uint8_t event_idx = OSA_EVENT_ID2IDX(eventId);
    if (event_idx >= OSA_EVENT_MAX) {
        return osaStatus_Error;
    }

    struct k_event *event_group = &_osa_event[event_idx];
    if (event_group == NULL) {
        return osaStatus_Error;
    }

    k_timeout_t timeout;
    switch (millisec) {
        case osaWaitForever_c :
            timeout = K_FOREVER;
            break;
        case 0 :
            timeout = K_NO_WAIT;
            break;
        default :
            timeout = K_MSEC(millisec);
    }

    LOG_DBG("Waiting for events 0x%02x with timeout: %d", flagsToWait, millisec);
    // Wait for event(s)
    uint32_t flags_save = 0u;
    if (waitAll) {
        flags_save = k_event_wait_all(event_group, flagsToWait, false, timeout);
    } else {
        flags_save = k_event_wait(event_group, flagsToWait, false, timeout);
    }
    LOG_DBG("Continue with flags 0x%02x, 0x%02x with timeout: %d", flags_save, flagsToWait, millisec);

    // Remove unwanted flags_save
    flags_save &= flagsToWait;
    if (pSetFlags) {
        *pSetFlags = flags_save;
    }

    // Auto-clear flags
    bool clear_mode = _osa_event_autoclear[event_idx];
    if (clear_mode) {
        event_group->events &= ~flags_save;
    }

    // Timeout occurred when no flags have been saved by event.
    if (flags_save == 0) {
        return osaStatus_Timeout;
    }

    return osaStatus_Success;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : OSA_MutexCreate
 * Description   : This function is used to create a mutex.
 * Return        : Mutex handle of the new mutex, or NULL if failed.
 *
 *END**************************************************************************/
osaMutexId_t OSA_MutexCreate(void)
{
#if osNumberOfMutexes
    if (_osa_mutex_idx <= OSA_EVENT_MAX) {
        struct k_mutex *mutex_group = &_osa_mutex[_osa_mutex_idx];
        k_mutex_init(mutex_group);

        osaEventId_t mutex_id = OSA_MUTEX_IDX2ID(_osa_mutex_idx);
        _osa_mutex_idx++;

        return mutex_id;
    }

    return NULL;
#else
    return NULL;
#endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : OSA_MutexLock
 * Description   : This function checks the mutex's status, if it is unlocked,
 * lock it and returns osaStatus_Success, otherwise, wait for the mutex.
 * This function returns osaStatus_Success if the mutex is obtained, returns
 * osaStatus_Error if any errors occur during waiting. If the mutex has been
 * locked, pass 0 as timeout will return osaStatus_Timeout immediately.
 *
 *END**************************************************************************/
osaStatus_t OSA_MutexLock(osaMutexId_t mutexId, uint32_t millisec)
{
#if osNumberOfMutexes
    if (mutexId == NULL) {
        return osaStatus_Error;
    }

    uint8_t mutex_idx = OSA_MUTEX_ID2IDX(mutexId);
    if (mutex_idx >= OSA_MUTEX_MAX) {
        return osaStatus_Error;
    }

    struct k_mutex *mutex = &_osa_mutex[mutex_idx];
    if (mutex == NULL) {
        return osaStatus_Error;
    }

    k_timeout_t timeout;
    switch (millisec) {
    case osaWaitForever_c :
        timeout = K_FOREVER;
        break;
    case 0 :
        timeout = K_NO_WAIT;
        break;
    default :
        timeout = K_MSEC(millisec);
    }

    int res = k_mutex_lock(mutex, timeout);
    if (res == 0) {
        return osaStatus_Success; /* semaphore taken */
    } else if (res == -EAGAIN) {
        return osaStatus_Timeout;
    } else {
        return osaStatus_Error;
    }
#else
    (void)mutexId;
    (void)millisec;  
    return osaStatus_Error;
#endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : OSA_MutexUnlock
 * Description   : This function is used to unlock a mutex.
 *
 *END**************************************************************************/
osaStatus_t OSA_MutexUnlock(osaMutexId_t mutexId)
{
#if osNumberOfMutexes
    if (mutexId == NULL) {
        return osaStatus_Error;
    }

    uint8_t mutex_idx = OSA_MUTEX_ID2IDX(mutexId);
    if (mutex_idx >= OSA_MUTEX_MAX) {
        return osaStatus_Error;
    }

    struct k_mutex *mutex = &_osa_mutex[mutex_idx];
    if (mutex == NULL) {
        return osaStatus_Error;
    }

    int res = k_mutex_unlock(mutex);
    if (res == 0) {
        return osaStatus_Success; /* semaphore taken */
    } else if (res == -EAGAIN) {
        return osaStatus_Timeout;
    } else {
        return osaStatus_Error;
    }
#else
    (void)mutexId;
    (void)millisec;
    return osaStatus_Error;
#endif
}