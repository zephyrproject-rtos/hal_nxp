/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FSL_PM_CORE_H_
#define _FSL_PM_CORE_H_

#include "fsl_common.h"
#include "fsl_component_generic_list.h"

#include "fsl_pm_config.h"
#include "fsl_pm_board.h"

/*!
 * This component is the entry point for power management. It offers an interface to the application
 * to reduce power consumption by bringing the system to the lowest possible power mode at any time
 * without violating application requirements. These application requirements include resources that
 * must remain active during low power but also the time before the system must be back to normal
 * active mode. Since the application requirements change over time, the possible and selected low
 * power mode will also vary over time.
 *
 * The power manager distinguishes two major modes: active mode and low power mode. In active mode,
 * the CPU is actively used by the application. In low power mode, the application is idle and no
 * CPU time is required to execute instructions. This component only cares about low power mode.
 * It's the application that must initiate the transition to a low power mode when it no longer
 * needs to execute instructions. With an operating system, this is typically done from the idle
 * task.
 *
 * Prior to requesting the power manager to enter low power mode, the application must make clear
 * which resources must remain active by calling PM_SetRequiredResources(). Then the application can
 * call PM_EnterLowPower(). This function accepts a time after which the system will be fully
 * restored to active mode. The application typically derives this time from feedback from the
 * operating system and the radio subsystem. Both systems offer ways to request the time till next
 * task (being an operating system task or a radio task like transmit/receive order).  The power
 * manager will take this time into consideration when selecting the low power mode and make sure
 * the system is fully restored to active mode at the requested time.
 *
 * A low power mode has a given exit latency. This is the time it takes to leave the low power mode
 * and restore the system to active mode. In general, the lower the power consumption, the longer it
 * takes to restore the system. The power manager takes this property into account when selecting
 * the best low power mode given the requested wake up time.
 * The application must keep in mind that for asynchronous interrupts, i.e. interrupts that are not
 * planned upfront, the exit latency will be directly added to the interrupt latency. This means
 * that the execution of the ISR can be significantly delayed when the system is in a low power mode
 * when the interrupt happens.
 *
 * In low power mode, some timers may stall. The power manager offers functions to retrieve the time
 * the system was asleep such that the stalled timers can be restored correctly. The application can
 * call PMDEVICE_StartSleepTimer, PMDEVICE_GetSleepTimer and PMDEVICE_StopSleepTimer for this.
 * Note that asynchronous wake-up sources (e.g. a button) could cause the system to wake up before
 * the requested time. In that case, above timer can be used to accurately measure the actual time
 * the system was in a low power mode.
 *
 * Notifications can be used by the application if it wants to be informed each time the power
 * manager enters or exits a certain state. The application can use these callbacks to prepare and
 * restore the system before/after low power mode. One example is restoring the debug console as
 * the flexcomm may have lost all its context in low power mode. The application can use
 * PM_RegisterNotify() to register a callback function.
 *
 * Above functionality is split into three components:
 *          ---------------------------------------
 *          |             fsl_pm_core             |
 *          ---------------------------------------
 *          ---------------------------------------
 *          |            fsl_pm_device            |
 *          ---------------------------------------
 *          ---------------------------------------
 *          |            fsl_pm_board             |
 *          ---------------------------------------
 *
 * - fsl_pm_core: implements all generic functionality like selection of power mode based on
 *   properties of the available power modes, notification management, ...
 * - fsl_pm_device: implements all device specific functionality. It defines all the available low
 *   power modes, the available constraints in each mode and the exit latency per power mode. For
 *   each power mode, it implements a function to enter and exit this particular mode. It offers
 *   timers to wake up the system and keep track of time during low power modes.
 * - fsl_pm_board: implements board specific functionality to enter and exit power modes.
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Power manager status.
 */
enum _pm_status
{
    kStatus_PMSuccess                      = kStatus_Success,
    kStatus_PMWakeupSourceEnableError      = MAKE_STATUS(kStatusGroup_POWER_MANAGER, 1U),
    kStatus_PMWakeupSourceDisableError     = MAKE_STATUS(kStatusGroup_POWER_MANAGER, 2U),
    kStatus_PMWakeupSourceServiceBusy      = MAKE_STATUS(kStatusGroup_POWER_MANAGER, 3U),
    kStatus_PMPowerStateNotAllowed         = MAKE_STATUS(kStatusGroup_POWER_MANAGER, 4U),
    kStatus_PMNotifyEventError             = MAKE_STATUS(kStatusGroup_POWER_MANAGER, 5U),
    kStatus_PMNoAppropriatePowerStateFound = MAKE_STATUS(kStatusGroup_POWER_MANAGER, 6U),
};

/*!
 * @brief The different power modes
 */
typedef enum _pm_mode
{
    kPM_Mode_Sleep,
    kPM_Mode_DeepSleep,
    kPM_Mode_PowerDown,
    kPM_Mode_PowerDownWithCpuRetention,
    kPM_Mode_PowerOff
} pm_mode_t;

/**
 * Type definition of a resource mask
 */
typedef uint32_t *pm_resource_mask_t;

#if (defined(FSL_PM_SUPPORT_NOTIFICATION) && FSL_PM_SUPPORT_NOTIFICATION)
/*!
 * @brief Power manager event type, used in notification module to inform the upper layer software
 * of the power transition event.
 */
typedef enum _pm_event_type
{
    kPM_EventEnteringSleep = 0U, /*!< Entering a sleep state. */
    kPM_EventExitingSleep,       /*!< Exiting a sleep state. */
} pm_event_type_t;

/*!
 * @brief The enumeration of notification group.
 */
typedef enum _pm_notify_group
{
    kPM_NotifyGroup0 =
        0U,           /*!< Notify group0, before entering power state the notifiers in group0 are executed firstly. */
    kPM_NotifyGroup1, /*!< Notify group1. */
    kPM_NotifyGroup2, /*!< Notify group2, after exiting power state the notifiers in group2 are executed firstly. */
} pm_notify_group_t;

/*!
 * @brief Power manager notify callback function used with the PM_RegisterNotify() API.
 *
 * @param eventType Identify the type of power event.
 * @param mode The power mode
 * in @ref pm_device_option_t structure.
 * @param data      Pointer to a custom argument.
 */
typedef status_t (*pm_notify_callback_func_t)(pm_event_type_t eventType, pm_mode_t mode, void *data);

/*!
 * @brief Power manager notify object structure.
 */
typedef struct _pm_notify_element
{
    list_element_t link;                      /*!< For placing on the notify list. */
    pm_notify_callback_func_t notifyCallback; /*!< Registered notification callback function.  */
    void *data;                               /*!< Pointer to a custom argument. */
} pm_notify_element_t;

#endif /* FSL_PM_SUPPORT_NOTIFICATION */

/*!
 * @brief The abstraction of MCU power state.
 */
typedef struct _pm_state
{
    /** A smaller sleep time is not considered worthwhile entering this mode */
    uint32_t minimumResidencyInUs;
    /** The mode this state represents */
    pm_mode_t mode;
    /** The available resources in this power state */
    pm_resource_mask_t availableResourcesMask;
    /** Function used to enter this power state. wakeupTime holds the absolute
     * time at which the system must be awake again. requiredResourcesMask holds
     * the resources the app requested to enable during low power mode. The function
     * can use this to enable the optional/configurable resources. */
    void (*enterFunc)(uint64_t wakeupTime, pm_resource_mask_t requiredResourcesMask);
} pm_state_t;

#if (defined(FSL_PM_SUPPORT_WAKEUP_SOURCE_MANAGER) && FSL_PM_SUPPORT_WAKEUP_SOURCE_MANAGER)
/*!
 * @brief Wakeup source service function used with PM_RegisterWakeupSource() function.
 */
typedef void (*pm_wake_up_source_service_func_t)(void);

/*!
 * @brief Wakeup source object structure.
 *
 * In PM_RegisterWakeupSource(), the wakeup source object in this structure type is allocated from the heap.
 * In PM_UnregisterWakeupSource(), the wakeup source object in this structure type is destoried from the heap.
 */
typedef struct _pm_wakeup_source
{
    list_element_t link; /*!< For placing on the wake up source list. */
    uint32_t wsId; /*!< The wakeup source id that the MCU supports, this value is used to config wakeup source manager
                      hardware peripheral. NXP will provided wakeup source id for each specific MCU. */
    pm_wake_up_source_service_func_t service; /*! Wakeup source service function that should be executed if the
                                    corresponding wakeup event occurred. */
    bool enabled : 1U;                        /*!< Enable/disable wakeup source. */
    bool active : 1U;                         /*!< Indicate whether the corresponding wakeup event occurs. */
} pm_wakeup_source_t;
#endif /* FSL_PM_SUPPORT_WAKEUP_SOURCE_MANAGER */

/*!
 * @brief The definition of Power manager resource constraint group, the group contains the operation mode of each
 * constraint.
 */
typedef struct _pm_resc_group
{
    uint32_t groupSlice[PM_RESC_GROUP_ARRAY_SIZE];
} pm_resc_group_t;

/*!
 * @brief The definition of power manager resource constraint mask.
 */
typedef struct _pm_resc_mask
{
    uint32_t rescMask[PM_RESC_MASK_ARRAY_SIZE];
} pm_resc_mask_t;

/*!
 * @brief Device power related options., including power states array, power state counts.
 *
 */
typedef struct _pm_device_option
{
    /** List of supported power states, ordered by decreasing power consumption */
    const pm_state_t **states;
    /** The number of supported power states. */
    int8_t stateCount;
    /** Function called each time the required resources are changed */
    void (*resourcesChangedCallback)(pm_board_resource_mask_t requiredResources,
                                     pm_board_resource_mask_t changedResources);
} pm_device_option_t;

#if (defined(FSL_PM_SUPPORT_LP_TIMER_CONTROLLER) && FSL_PM_SUPPORT_LP_TIMER_CONTROLLER)
/**
 * Callback function definition for starting the low power timer
 *  @param: timeout The timeout value in microseconds
 */
typedef void (*pm_low_power_timer_start_func_t)(uint32_t timeout);
/**
 * Callback function definition for stopping the low power timer
 */
typedef void (*pm_low_power_timer_stop_func_t)(void);
/**
 * Callback function definition for retrieving the counter value in microseconds
 * This returns the time the counter has run since it was started.
 */
typedef uint32_t (*pm_low_power_timer_get_count_func_t)(void);
#endif /* FSL_PM_SUPPORT_LP_TIMER_CONTROLLER */

/*!
 * @brief Handle structure for power manager.
 *
 */
typedef struct _pm_handle
{
    /**
     * True when power management is enabled, False when the user requested the power
     * manager not to enter low power modes.
     */
    bool enabled;

    /** Nested call counter, used to keep track how many nested calls are made to PM_EnablePowerManager */
    int8_t disableCount; /*!< Used to support nested call to PM_EnablePowerManager. */

    /** Pointer to power management capabilities of the device */
    const pm_device_option_t *deviceOption;

    /**
     * Mask of required resources during low power state. The required resources are
     * checked against the available resources for each power state to select the deepest
     * power mode while still satisfying all resource requirements.
     */
    pm_board_resource_mask_t requiredResourcesMask;

#if (defined(FSL_PM_SUPPORT_NOTIFICATION) && FSL_PM_SUPPORT_NOTIFICATION)
    list_label_t notifyList[3U];           /*!< The header of 3 group notification. */
    pm_notify_group_t curNotifyGroup;      /*!< Store current notification group. */
    pm_notify_element_t *curNotifyElement; /*!< Store current notification element. */
#endif                                     /* FSL_PM_SUPPORT_NOTIFICATION */

#if (defined(FSL_PM_SUPPORT_LP_TIMER_CONTROLLER) && FSL_PM_SUPPORT_LP_TIMER_CONTROLLER)
    /** Pointer to function to start the wakeup timer */
    pm_low_power_timer_start_func_t timerStart;

    /** Pointer to function to stop the wakeup timer */
    pm_low_power_timer_stop_func_t timerStop;

    /** Returns the actual counter value of the wakeup timer */
    pm_low_power_timer_get_count_func_t getTimerCount;
#endif /* FSL_PM_SUPPORT_LP_TIMER_CONTROLLER */

#if (defined(FSL_PM_SUPPORT_WAKEUP_SOURCE_MANAGER) && FSL_PM_SUPPORT_WAKEUP_SOURCE_MANAGER)
    list_label_t wakeupSourceList;
#endif /* FSL_PM_SUPPORT_WAKEUP_SOURCE_MANAGER */
} pm_handle_t;

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @name Power Manager Policy
 * @{
 */

/*!
 * @brief Initialize the power manager handle, this function should be invoked before using other power manager
 * APIs.
 *
 * @note In default, the power manager is disabled.
 *
 * @param handle Pointer to the @ref pm_handle_t structure, upper layer software should pre-allocate the handle global
 * variable.
 */
void PM_Init(void);

/*!
 * @brief Enable/disable power manager functions.
 *
 * @param enable Used to enable/disable power manager functions.
 */
void PM_EnablePowerManager(bool enable);

/*!
 * @brief Power manager core API, this API should be used on RTOS's IDLE task.
 *
 * This function contains several steps:
 * 1. Compute target power state based on the policy module.
 * 2. Notify upper layer software of the power mode entering.
 * 3. Enter into target power state.
 * 4. Exit from low power state, if wakeup event occurred.
 * 5. Notify upper layer software of the power mode exiting.
 *
 * The target power state is determined based on two factors:
 *   a. The input parameter should be larger than state's exitLatency attribution.
 *   b. resConstraintsMask logical AND state's lossFeature should equal to 0, because constraint can be understand as
 * some features can not loss.
 *
 * param wakeupTime The time when the low power mode must be exited
 * param selectedMode The mode that was selected and entered
 */
status_t PM_EnterLowPower(uint64_t wakeupTime, pm_mode_t *selectedMode);

#if (defined(FSL_PM_SUPPORT_NOTIFICATION) && FSL_PM_SUPPORT_NOTIFICATION)
/*!
 * @name Notification Module Interfaces
 * @{
 */

/*!
 * @brief Register notify element into the selected group.
 *
 * @param groupId The group of the notify list, this will affect the execution sequence.
 * @param notifyElement The pointer to @ref pm_notify_element_t.
 * @return status_t The status of register notify object behavior.
 */
status_t PM_RegisterNotify(pm_notify_group_t groupId, const pm_notify_element_t *notifyElement);

/*!
 * @brief Update notify element's callback function and application data.
 *
 * @param notifyElement The pointer to the notify element to update.
 * @param callback The callback function to be updated.
 * @param data Pointer to the callback function private data.
 */
void PM_UpdateNotify(void *notifyElement, pm_notify_callback_func_t callback, void *data);

/*!
 * @brief Remove notify element from its notify group.
 *
 * @param notifyElement The pointer to the notify element to remove.
 */
status_t PM_UnregisterNotify(void *notifyElement);

/* @} */
#endif /* FSL_PM_SUPPORT_NOTIFICATION */

/*!
 * @brief Sets the required resources. These are added to the previously set resources
 *
 * @param count The number of resources to set
 * @param var_arg The list of the resources to set
 *
 * @return kStatus_Success in case of success, error code otherwise
 */
status_t PM_SetRequiredResources(uint32_t count, ...);

/*!
 * @brief Clears the required resources. Other resources remain untouched.
 *
 * @param count The number of resources to clear
 * @param var_arg The list of the resources to clear
 *
 * @return kStatus_Success in case of success, error code otherwise
 */
status_t PM_RemoveRequiredResources(uint32_t count, ...);

/*!
 * @brief Get the required resources.
 *
 * @return The bitmask of resources
 */
pm_resource_mask_t PM_GetRequiredResources(void);

#if defined(__cplusplus)
}
#endif

#endif /* _FSL_PM_CORE_H_ */
