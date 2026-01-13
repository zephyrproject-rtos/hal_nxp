/*
 * Copyright (c) 2014-2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2019, 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCMGR_INTERNAL_CORE_API_H
#define MCMGR_INTERNAL_CORE_API_H

/*!
 * @addtogroup mcmgr_internal
 * @{
 */

/*! @brief Type definition of structure with event handler and data. */
typedef struct _mcmgr_event
{
    /*! @brief Pointer to callback function. */
    mcmgr_event_callback_t callback;
    /*! @brief Context data for callback. */
    void *callbackData;
} mcmgr_event_t;

/*! @brief Type definition of structure which contains informations and functions for one core. */
typedef struct _mcmgr_core_info
{
    mcmgr_core_type_t coreType;
    char *coreName;
} mcmgr_core_info_t;

/*! @brief Type definition of possible core states. */
typedef enum _mcmgr_core_state
{
    kMCMGR_ResetCoreState = 0,
    kMCMGR_StartupGettingLowCoreState,
    kMCMGR_StartupGettingHighCoreState,
    kMCMGR_RunningCoreState,
} mcmgr_core_state_t;

/*! @brief Type definition of structure which contains status information for a core. */
typedef struct _mcmgr_core_context
{
    /*! @brief Current state of the core. */
    mcmgr_core_state_t state;
    /*! @brief Startup data, if state >= kMCMGR_RunningCoreState */
    uint32_t startupData;
} mcmgr_core_context_t;

/*! @brief Type definition of structure with system informations */
typedef struct _mcmgr_system_info
{
    /*! @brief Count of cores in the system. */
    uint32_t coreCount;
    /*! @brief Count of memory regions in the system. */
    uint32_t memRegCount;
    /*! @brief Array of core informations. */
    const mcmgr_core_info_t *cores;
} mcmgr_system_info_t;

/*!
 * @brief Structure of mcmgr_system_info_t
 *
 * This structure contains all informations about device and all cores.
 * Should be defined and initialized in device specific file.
 */
extern const mcmgr_system_info_t g_mcmgrSystem;

/*!
 * @brief Array of mcmgr_event_t
 *
 * This array contains registered callbacks for event handling.
 */
extern mcmgr_event_t MCMGR_eventTable[];

/*!
 * @brief Array of mcmgr_core_context_t
 *
 * This array contains runtime context for each core in the system.
 */
extern volatile mcmgr_core_context_t s_mcmgrCoresContext[];

/*!
 * @brief Internal platform-specific early MCMGR initialize function,
 * usually called during the startup.
 *
 * @param[in] coreNum Current core number.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t mcmgr_early_init_internal(mcmgr_core_t coreNum);

/*!
 * @brief Internal platform-specific late MCMGR initialize function.
 *
 * @param[in] coreNum Current core number.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t mcmgr_late_init_internal(mcmgr_core_t coreNum);

/*!
 * @brief Internal platform-specific start core function.
 *
 * @param[in] coreNum Enum of the core to be started.
 * @param[in] bootAddress Boot address of the core to be started application.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t mcmgr_start_core_internal(mcmgr_core_t coreNum, void *bootAddress);

/*!
 * @brief Internal platform-specific function to get startup data
 *
 * This function read startup data provided by the master core.
 * Use only on the slave core during the startup.
 *
 * @param[in] coreNum Current core number.
 * @param[out] startupData Data to read by this function.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t mcmgr_get_startup_data_internal(mcmgr_core_t coreNum, uint32_t *startupData);

/*!
 * @brief Internal platform-specific stop core function.
 *
 * This function causes a selected core to halt code execution.
 *
 * @param[in] coreNum Enum of core to be stopped.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t mcmgr_stop_core_internal(mcmgr_core_t coreNum);

/*!
 * @brief Internal platform-specific get property of the CPU core function.
 *
 * This function provides the property of the CPU core.
 *
 * @param[in] coreNum Enum of core.
 * @param[in] property Requested property type.
 * @param[in,out] value Parameter for value of property.
 * @param[in,out] length Parameter for size of property value in bytes.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t mcmgr_get_core_property_internal(mcmgr_core_t coreNum,
                                                mcmgr_core_property_t property,
                                                void *value,
                                                uint32_t *length);

/*!
 * @brief Internal platform-specific function for remote core notification.
 *
 * This function notifies other core about occured event.
 *
 * @param[in] remoteData 32-bit data with event code and event data encoded.
 * @param[in] forcedWrite Set to TRUE when the check for previous sent data consuption is required,
 *            set to FALSE othervise.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t mcmgr_trigger_event_internal(mcmgr_core_t coreNum, uint32_t remoteData, bool forcedWrite);

/*!
 * @brief Internal platform-specific function to get current CPU core.
 *
 * This function returns enum of current core.
 *
 * @return Enum of current core.
 */
mcmgr_core_t mcmgr_get_current_core_internal(void);

mcmgr_status_t mcmgr_process_deferred_rx_isr_internal(void);


/*! @} */

#endif
