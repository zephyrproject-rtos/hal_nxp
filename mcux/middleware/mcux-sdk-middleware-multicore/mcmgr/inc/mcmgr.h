/*
 * Copyright (c) 2014-2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCMGR_H
#define MCMGR_H

#include <stdbool.h>
#include <stdint.h>

#include "mcmgr_platform.h"

/*!
 * @addtogroup mcmgr
 * @{
 */

/*! @brief Enumeration that defines MCMGR function return status codes. */
typedef enum _mcmgr_status
{
    /*! @brief Operation was successful. */
    kStatus_MCMGR_Success,
    /*! @brief Operation was not successful. */
    kStatus_MCMGR_Error,
    /*! @brief Function is not implemented. */
    kStatus_MCMGR_NotImplemented,
    /*! @brief Operation result not ready. */
    kStatus_MCMGR_NotReady

} mcmgr_status_t;

/*! @brief Enumeration that defines property of core. */
typedef enum _mcmgr_core_property
{
    /*! @brief Status of core read from hardware core status flag. */
    kMCMGR_CoreStatus,
    /*! @brief Type of Core. */
    kMCMGR_CoreType,
    /*! @brief Power Mode of Core - implementation is hardware-specific. */
    kMCMGR_CorePowerMode
} mcmgr_core_property_t;

/*! @brief Enumeration that defines the property value of core status. */
typedef enum _mcmgr_core_status
{
    /*! @brief Core is held in reset. */
    kMCMGR_InReset,
    /*! @brief Core is not in reset. */
    kMCMGR_NotInReset
} mcmgr_core_status_t;

/*! @brief Enumeration that defines property value of core type. */
typedef enum _mcmgr_core_type
{
    /*! @brief Cortex M0 */
    kMCMGR_CoreTypeCortexM0,
    /*! @brief Cortex M0+ */
    kMCMGR_CoreTypeCortexM0Plus,
    /*! @brief Cortex M4 */
    kMCMGR_CoreTypeCortexM4,
    /*! @brief Cortex M33 */
    kMCMGR_CoreTypeCortexM33,
    /*! @brief Cortex M7 */
    kMCMGR_CoreTypeCortexM7,
    /*! @brief Cortex M3 */
    kMCMGR_CoreTypeCortexM3,
    /*! @brief Cortex M3 */
    kMCMGR_CoreTypeDSPHifi1,
    /*! @brief Cortex M3 */
    kMCMGR_CoreTypeDSPHifi4
} mcmgr_core_type_t;

/*! @brief Enumeration that defines core. */
typedef enum _mcmgr_core
{
    /*! @brief Enum value for Core 0. */
    kMCMGR_Core0,
    /*! @brief Enum value for Core 1. */
    kMCMGR_Core1,
    kMCMGR_Core2,
    kMCMGR_Core3,
    kMCMGR_Core_Num
} mcmgr_core_t;

/*! @brief Enumeration that defines start type. */
typedef enum _mcmgr_start_mode
{
    /*! @brief Enum value for starting synchronously. */
    kMCMGR_Start_Synchronous,
    /*! @brief Enum value for starting asynchronously. */
    kMCMGR_Start_Asynchronous

} mcmgr_start_mode_t;

/*! @brief Type definition of event types. */
typedef enum _mcmgr_event_type_t
{
    kMCMGR_RemoteCoreUpEvent = 1,
    kMCMGR_RemoteCoreDownEvent,
    kMCMGR_RemoteExceptionEvent,
    kMCMGR_StartupDataEvent,
    kMCMGR_FeedStartupDataEvent,
    kMCMGR_RemoteRPMsgEvent,
    kMCMGR_RemoteApplicationEvent,
    kMCMGR_FreeRtosMessageBuffersEvent,
    kMCMGR_EventTableLength
} mcmgr_event_type_t;

/*! @brief Type definition of event callback function pointer. */
typedef void (*mcmgr_event_callback_t)(mcmgr_core_t coreNum, uint16_t data, void *context);

/*! @brief Set to 1 to enable exception handling. */
#ifndef MCMGR_HANDLE_EXCEPTIONS
#define MCMGR_HANDLE_EXCEPTIONS (0)
#endif

/*! @brief Set to 1 to enable deferred call in isr. */
#ifndef MCMGR_DEFERRED_CALLBACK_ALLOWED
#define MCMGR_DEFERRED_CALLBACK_ALLOWED (0)
#endif

/*!
 * @brief Maximum polling iterations for MCMGR waiting loops
 *
 * This parameter defines the maximum number of iterations for any polling loop
 * in the MCMGR code before timing out and returning an error.
 *
 * It applies to all waiting loops in MCMGR, such as waiting for a core to start,
 * waiting for a response from another core, or waiting for a resource to become
 * available.
 *
 * This is a count of loop iterations, not a time-based value.
 *
 * If defined as 0, polling loops will continue indefinitely until their exit condition
 * is met, which could potentially cause the system to hang if a core becomes
 * unresponsive.
 */
#ifndef MCMGR_BUSY_POLL_COUNT
    #ifdef CONFIG_MCMGR_BUSY_POLL_COUNT
        #define MCMGR_BUSY_POLL_COUNT CONFIG_MCMGR_BUSY_POLL_COUNT
    #else
        #define MCMGR_BUSY_POLL_COUNT 0U
    #endif
#endif

/*!
 * @brief Version of MCMGR
 *
 * Version 1.0.0, for version 1.2.3 it will be 0x00010203
 */
enum mcmgr_version_enum
{
    kMCMGR_Version = 0x00050000
};

#if defined(__cplusplus)
extern "C" {
#endif // __cplusplus

/*!
 * @brief Initialize the multicore manager, early init.
 *
 * After calling this function, MCMGR_TriggerEvent() and/or MCMGR_Init() can be called.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t MCMGR_EarlyInit(void);

/*!
 * @brief Initialize the multicore manager
 *
 * After calling this function, all API can be used.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t MCMGR_Init(void);

/*!
 * @brief Start a selected core
 *
 * This function causes a selected core to initialize and start the code execution.
 * If the secondary core application boots from RAM, then there is a need to call the function,
 * which copies this app. Image to RAM prior this function.
 *
 * @param[in] coreNum Enum of the core to be started.
 * @param[in] bootAddress Boot address of the core to be started application.
 * @param[in] startupData Data which can be get by the other core on startup.
 * @param[in] mode Start mode, use kMCMGR_Start_Synchronous for synchronous mode (wait until the
 *            core is started), kMCMGR_Start_Asynchronous for asynchronous mode (do not wait).
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t MCMGR_StartCore(mcmgr_core_t coreNum, void *bootAddress, uint32_t startupData, mcmgr_start_mode_t mode);

/*!
 * @brief Get startup data for the slave core.
 *
 * This function read startup data provided by the master core.
 * Use only on the slave core during the startup.
 *
 * @param[in] coreNum Enum of the core from which to get statup data.
 * @param[out] startupData Data to read by this function.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t MCMGR_GetStartupData(mcmgr_core_t coreNum, uint32_t *startupData);

/*!
 * @brief Stop a selected core
 *
 * This function causes a selected core to halt code execution.
 *
 * @param[in] coreNum Enum of core to be stopped.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t MCMGR_StopCore(mcmgr_core_t coreNum);

/*!
 * @brief Get version of MCMGR
 *
 * This function returns a number of MCMGR version.
 *
 * @return a number of MCMGR version.
 */
int32_t MCMGR_GetVersion(void);

/*!
 * @brief Get property of the CPU core
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
mcmgr_status_t MCMGR_GetCoreProperty(mcmgr_core_t coreNum,
                                     mcmgr_core_property_t property,
                                     void *value,
                                     uint32_t *length);

/*!
 * @brief Return the count of cores in a multicore system
 *
 * This function returns the count of cores in a multicore system.
 *
 * @return the count of cores in a system.
 */
uint32_t MCMGR_GetCoreCount(void);

/*!
 * @brief Get current CPU core
 *
 * This function returns enum of current core.
 *
 * @return Enum of current core.
 */
mcmgr_core_t MCMGR_GetCurrentCore(void);

/*!
 * @brief Register event handler
 *
 * This function registers an event handler.
 * for remote processor events handling.
 *
 * @param[in] type Type of the event.
 * @param[in] callback User callback.
 * @param[in] callbackData Data/context for user callback.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t MCMGR_RegisterEvent(mcmgr_event_type_t type, mcmgr_event_callback_t callback, void *callbackData);

/*!
 * @brief Trigger event handler
 *
 * This function triggers an event handler
 * on the remote core.
 *
 * @param[in] coreNum Enum of core to be triggered.
 * @param[in] type Type of the event.
 * @param[in] eventData Data to send to remote core.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t MCMGR_TriggerEvent(mcmgr_core_t coreNum, mcmgr_event_type_t type, uint16_t eventData);

/*!
 * @brief Trigger event handler, force version
 *
 * This function triggers an event handler
 * on the remote core, force version that does not check the consumption of previously sent data.
 *
 * @param[in] coreNum Enum of core to be triggered.
 * @param[in] type Type of the event.
 * @param[in] eventData Data to send to remote core.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_Error on failure.
 */
mcmgr_status_t MCMGR_TriggerEventForce(mcmgr_core_t coreNum, mcmgr_event_type_t type, uint16_t eventData);

/*!
 * @brief Process RX data in deffered rx task.
 *
 * This function used to be called from the application specific deffered rx task to trigger rx data processing outside the interrupt context.
 * The purpose is to make the interrupt service routine as short as possible, performing only really necessary steps
 * in the interrupt context and defer the processing outside the interrupt context.
 *
 * @return kStatus_MCMGR_Success on success or kStatus_MCMGR_NotImplemented when not supported.
 */
mcmgr_status_t MCMGR_ProcessDeferredRxIsr(void);


#if defined(__cplusplus)
}
#endif // __cplusplus

/*! @} */

#endif
