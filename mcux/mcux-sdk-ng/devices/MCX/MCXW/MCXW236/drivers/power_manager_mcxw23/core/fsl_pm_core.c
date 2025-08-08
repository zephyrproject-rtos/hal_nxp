/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdarg.h>
#include "fsl_pm_core.h"
#include "fsl_pm_device.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/** Time it takes to prepare entering low power mode */
#define PRE_SLEEP_OVERHEAD_IN_US 200

/*******************************************************************************
 * Variables
 ******************************************************************************/
static pm_handle_t s_pmData;
static pm_handle_t *s_pmHandle = &s_pmData;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
#if (defined(FSL_PM_SUPPORT_NOTIFICATION) && FSL_PM_SUPPORT_NOTIFICATION)
static status_t PM_notifyPowerStateEntry(const pm_state_t *powerState);
static status_t PM_notifyPowerStateExit(const pm_state_t *powerState);
#endif /* FSL_PM_SUPPORT_NOTIFICATION */

/*******************************************************************************
 * Code
 ******************************************************************************/

/***************************************************************
 * Private Functions
 ***************************************************************/

/**
 * Searches the deepest possible power state in which all required
 * resources are still available. Secondly, the state transition
 * must be faster than @c maxSleepTimeInUs
 *
 * @param maxSleepTimeInUs The maximum sleep time of the power state.
 *        Use 0 when sleep time is not important.
 * @param The deepest possible state or NULL when no applicable state found.
 */
static const pm_state_t *PM_FindDeepestPossibleState(int64_t maxSleepTimeInUs)
{
    uint8_t j = 0U;

    /* The list is searched from deepest to least deep power state */
    const pm_state_t **state        = s_pmHandle->deviceOption->states + s_pmHandle->deviceOption->stateCount;
    const pm_state_t *selectedState = NULL;

    /* We're done when we have checked the first state */
    while (state != s_pmHandle->deviceOption->states)
    {
        /* Jump to the next most deepest power state */
        state--;

        /* Check whether the state's exit latency meets the maximum allowed exit latency */
        if ((maxSleepTimeInUs == 0) || ((*state)->minimumResidencyInUs <= maxSleepTimeInUs))
        {
            /* Mark this state (temporarily) as the best state */
            selectedState = *state;
            /* Check the complete array of resource masks */
            for (j = 0U; j < ARRAY_SIZE(s_pmHandle->requiredResourcesMask); j++)
            {
                /* Are all required resources available in this power mode? */
                if ((s_pmHandle->requiredResourcesMask[j] & selectedState->availableResourcesMask[j]) !=
                    s_pmHandle->requiredResourcesMask[j])
                {
                    /* No, skip this state */
                    selectedState = NULL;
                    break;
                }
            }
        }

        /* Did the state satisfy all requirements? */
        if (selectedState != NULL)
        {
            /* Yes, we found the deepest possible low power state */
            break;
        }
    }

    return selectedState;
}

#if (defined(FSL_PM_SUPPORT_NOTIFICATION) && FSL_PM_SUPPORT_NOTIFICATION)
/**
 * Calls all registered callback functions that the given power state is about to activate
 *
 * @param powerState The power state that is about to activate
 * @return kStatus_Success on success. Error code otherwise.
 */
static status_t PM_notifyPowerStateEntry(const pm_state_t *powerState)
{
    uint8_t i;
    pm_notify_callback_func_t callback;
    pm_notify_element_t *currElement = NULL;
    status_t status                  = kStatus_PMSuccess;

    /* Execute from group0 to group2. */
    for (i = (uint8_t)kPM_NotifyGroup0; i <= (uint8_t)kPM_NotifyGroup2; i++)
    {
        s_pmHandle->curNotifyGroup = (pm_notify_group_t)i;
        if (LIST_GetSize((list_handle_t) & (s_pmHandle->notifyList[i])) != 0UL)
        {
            currElement = (pm_notify_element_t *)(void *)(s_pmHandle->notifyList[i].head);

            do
            {
                callback = currElement->notifyCallback;
                status   = callback(kPM_EventEnteringSleep, powerState->mode, currElement->data);
                if (status != kStatus_Success)
                {
                    s_pmHandle->curNotifyElement = currElement;
                    return kStatus_PMNotifyEventError;
                }
                currElement = (pm_notify_element_t *)(void *)currElement->link.next;
            } while (currElement != NULL);
        }
    }

    s_pmHandle->curNotifyGroup   = kPM_NotifyGroup2;
    s_pmHandle->curNotifyElement = NULL;
    return kStatus_PMSuccess;
}

/**
 * Calls all registered callback functions that the given power state is left
 *
 * @param powerState The power state that is left
 * @return kStatus_Success on success. Error code otherwise.
 */
static status_t PM_notifyPowerStateExit(const pm_state_t *powerState)
{
    int8_t i;
    pm_notify_element_t *currElement = NULL;

    if (s_pmHandle->curNotifyElement != NULL)
    {
        i = (int8_t)(s_pmHandle->curNotifyGroup);
    }
    else
    {
        i = (int8_t)kPM_NotifyGroup2;
    }

    /* Execute from group2 to group0. */
    for (; i >= (int8_t)kPM_NotifyGroup0; i--)
    {
        if (LIST_GetSize((list_handle_t) & (s_pmHandle->notifyList[i])) != 0UL)
        {
            currElement = (pm_notify_element_t *)(void *)(s_pmHandle->notifyList[i].head);

            do
            {
                (void)(currElement->notifyCallback(kPM_EventExitingSleep, powerState->mode, currElement->data));
                if (currElement == s_pmHandle->curNotifyElement)
                {
                    break;
                }
                currElement = (pm_notify_element_t *)(void *)(currElement->link.next);
            } while (currElement != NULL);
        }
    }

    return kStatus_PMSuccess;
}
#endif /* FSL_PM_SUPPORT_NOTIFICATION */

/*!
 * @brief Set or clear the required resources. Other resources remain untouched.
 *
 * @param count The number of resources to clear
 * @param set True to set, False to clear
 * @param ap The list of the resources to clear
 *
 * @return kStatus_Success in case of success, error code otherwise
 */
static status_t PM_UpdateRequiredResources(uint32_t count, bool set, va_list ap)
{
    pm_board_resource_mask_t changedMask;
    bool hasChanged = false;
    uint32_t i;

    /* Take snapshot of required resources before the change */
    for (i = 0; i < ARRAY_SIZE(changedMask); i++)
    {
        changedMask[i] = s_pmHandle->requiredResourcesMask[i];
    }

    /* Update the requires resources mask */
    for (i = 0; i < count; i++)
    {
        board_resource_t resource = (int32_t)va_arg(ap, int32_t);
        assert(resource < kResource_Count);
        if (set)
        {
            BITMASK_SET(s_pmHandle->requiredResourcesMask, resource);
        }
        else
        {
            BITMASK_CLEAR(s_pmHandle->requiredResourcesMask, resource);
        }
    }

    /* Calculate the changed requirements */
    for (i = 0; i < ARRAY_SIZE(changedMask); i++)
    {
        changedMask[i] ^= s_pmHandle->requiredResourcesMask[i];
        hasChanged |= (changedMask[i] != 0);
    }

    /* Inform the device if resources have changed */
    if ((s_pmHandle->deviceOption->resourcesChangedCallback != NULL) && hasChanged)
    {
        s_pmHandle->deviceOption->resourcesChangedCallback(s_pmHandle->requiredResourcesMask, changedMask);
    }

    return kStatus_Success;
}

/***************************************************************
 * Public Functions
 ***************************************************************/
/*!
 * brief Initialize the power manager handle, this function should be invoked before using other power manager
 * APIs.
 *
 * note In default, the power manager is disabled.
 *
 * param handle Pointer to the pm_handle_t structure, upper layer software should pre-allocate the handle global
 * variable.
 */
void PM_Init(void)
{
    /* Initialize the device specific power manager component */
    PMDEVICE_Init();
    /* Initialize the board specific power manager component */
    PMBOARD_Init();

    /* Clear handle. */
    (void)memset(s_pmHandle, 0, sizeof(*s_pmHandle));

    s_pmHandle->enabled = false;
    /* Initial value is set to 1 as Power Manager is disabled by default */
    s_pmHandle->disableCount  = 1;
    s_pmHandle->deviceOption  = PMDEVICE_GetDeviceOption();
    s_pmHandle->timerStart    = NULL;
    s_pmHandle->timerStop     = NULL;
    s_pmHandle->getTimerCount = NULL;

#if (defined(FSL_PM_SUPPORT_NOTIFICATION) && FSL_PM_SUPPORT_NOTIFICATION)
    /* Create notify lists. */
    LIST_Init((list_handle_t) & (s_pmHandle->notifyList[kPM_NotifyGroup0]), 0UL);
    LIST_Init((list_handle_t) & (s_pmHandle->notifyList[kPM_NotifyGroup1]), 0UL);
    LIST_Init((list_handle_t) & (s_pmHandle->notifyList[kPM_NotifyGroup2]), 0UL);
#endif /* FSL_PM_SUPPORT_NOTIFICATION */

#if (defined(FSL_PM_SUPPORT_WAKEUP_SOURCE_MANAGER) && FSL_PM_SUPPORT_WAKEUP_SOURCE_MANAGER)
    LIST_Init((list_handle_t) & (s_pmHandle->wakeupSourceList), 0UL);
#endif /* FSL_PM_SUPPORT_WAKEUP_SOURCE_MANAGER */
}

/*!
 * brief Enable/disable power manager functions.
 *
 * param enable Used to enable/disable power manager functions.
 */
void PM_EnablePowerManager(bool enable)
{
    uint32_t irqMask;

    /* Check whether Power Manager has been initialized or not */
    if (s_pmHandle != NULL)
    {
        irqMask = DisableGlobalIRQ();

        if (enable == true)
        {
            assert(s_pmHandle->disableCount > 0);

            s_pmHandle->disableCount--;
            s_pmHandle->enabled = s_pmHandle->disableCount == 0;
        }
        else
        {
            s_pmHandle->disableCount++;
            s_pmHandle->enabled = false;
        }

        EnableGlobalIRQ(irqMask);
    }
}

/*!
 * brief Power manager core API, this API should be used on RTOS's IDLE task.
 *
 * This function contains several steps:
 * 1. Compute target power state based on the policy module.
 * 2. Notify upper layer software of the power mode entering.
 * 3. Enter into target power state.
 * 4. Exit from low power state, if wakeup event occurred.
 * 5. Notify upper layer software of the power mode exiting.
 *
 * The target power state is determined based on two factors:
 *   a. The input parameter should be larger than state's minimumResidencyInUs attribution.
 *   b. resConstraintsMask logical AND state's lossFeature should equal to 0, because constraint can be understand as
 * some features can not loss.
 *
 * param wakeupTime The time when the low power mode must be exited
 * param selectedMode The mode that was selected and entered
 */
status_t PM_EnterLowPower(uint64_t wakeupTime, pm_mode_t *selectedMode)
{
    status_t status = kStatus_Success;
    if (s_pmHandle->enabled)
    {
        const pm_state_t *state;
        /* Calculate the remaining time the system can go to low power, expect the wake up time
         * might already be passed. Subtract the overhead it takes till the system will eventually go to
         * low power mode. This overhead includes calling the notifiers, searching for the deepest
         * power mode etc... */
        int64_t durationInUs = (int64_t)wakeupTime - (int64_t)PMDEVICE_GetSleepTimer() - PRE_SLEEP_OVERHEAD_IN_US;
        if (durationInUs <= 0)
        {
            /* Set it to 1. 0 means infinite sleep */
            durationInUs = 1;
        }
        /* Based on remaining time and required resources, compute the deepest power state. */
        state = PM_FindDeepestPossibleState(durationInUs);

        /* Was a suitable state found? */
        if (state == NULL)
        {
            status = kStatus_PMNoAppropriatePowerStateFound;
        }

#if (defined(FSL_PM_SUPPORT_NOTIFICATION) && FSL_PM_SUPPORT_NOTIFICATION)
        if (status == kStatus_PMSuccess)
        {
            if (selectedMode != NULL)
            {
                *selectedMode = state->mode;
            }
            /* Notify the enter of power state */
            status = PM_notifyPowerStateEntry(state);
        }
#endif /* FSL_PM_SUPPORT_NOTIFICATION */
        if (status == kStatus_PMSuccess)
        {
            /* Enter into low power state. */
            state->enterFunc(wakeupTime, s_pmHandle->requiredResourcesMask);
        }

        if (status != kStatus_PMNoAppropriatePowerStateFound)
        {
#if (defined(FSL_PM_SUPPORT_NOTIFICATION) && FSL_PM_SUPPORT_NOTIFICATION)
            /* Notify the exit of power state. */
            (void)PM_notifyPowerStateExit(state);
#endif /* FSL_PM_SUPPORT_NOTIFICATION */
        }
    }
    return status;
}

#if (defined(FSL_PM_SUPPORT_NOTIFICATION) && FSL_PM_SUPPORT_NOTIFICATION)
/*!
 * brief Register notify element into the selected group.
 *
 * param groupId The group of the notify list, this will affect the execution sequence.
 * param notifyElement The pointer to pm_notify_element_t.
 * return status_t The status of register notify object behavior.
 */
status_t PM_RegisterNotify(pm_notify_group_t groupId, const pm_notify_element_t *notifyElement)
{
    assert(notifyElement != NULL);

    status_t status;
    status = LIST_AddTail((list_handle_t) & (s_pmHandle->notifyList[groupId]),
                          (list_element_handle_t) & (notifyElement->link));

    return status;
}

/*!
 * brief Update notify element's callback function and application data.
 *
 * param notifyElement The pointer to the notify element to update.
 * param callback The callback function to be updated.
 * param data Pointer to the callback function private data.
 */
void PM_UpdateNotify(void *notifyElement, pm_notify_callback_func_t callback, void *data)
{
    ((pm_notify_element_t *)notifyElement)->data           = data;
    ((pm_notify_element_t *)notifyElement)->notifyCallback = callback;
}

/*!
 * brief Remove notify element from its notify group.
 *
 * param notifyElement The pointer to the notify element to remove.
 */
status_t PM_UnregisterNotify(void *notifyElement)
{
    status_t status = kStatus_Success;

    if (LIST_RemoveElement((list_element_handle_t) & (((pm_notify_element_t *)notifyElement)->link)) != kLIST_Ok)
    {
        status = kStatus_Fail;
    }

    return status;
}
#endif /* FSL_PM_SUPPORT_NOTIFICATION */

/**
 * Set additional resources to the list of required resources.
 */
status_t PM_SetRequiredResources(uint32_t count, ...)
{
    status_t status;
    va_list ap;

    va_start(ap, count);

    status = PM_UpdateRequiredResources(count, true, ap);

    va_end(ap);

    return status;
}

/**
 * Remove the required resources from the list of required resources.
 */
status_t PM_RemoveRequiredResources(uint32_t count, ...)
{
    status_t status;
    va_list ap;

    va_start(ap, count);

    status = PM_UpdateRequiredResources(count, false, ap);

    va_end(ap);

    return status;
}

/**
 * brief Returns the currently set of required resources.
 *
 * return Required resources
 */
pm_resource_mask_t PM_GetRequiredResources(void)
{
    return s_pmHandle->requiredResourcesMask;
}
