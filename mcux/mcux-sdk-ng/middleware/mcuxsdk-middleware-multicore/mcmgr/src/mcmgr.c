/*
 * Copyright (c) 2014-2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "mcmgr.h"
#include "mcmgr_internal_core_api.h"

mcmgr_event_t MCMGR_eventTable[kMCMGR_EventTableLength] = {0};

mcmgr_status_t MCMGR_RegisterEvent(mcmgr_event_type_t type, mcmgr_event_callback_t callback, void *callbackData)
{
    if (type >= kMCMGR_EventTableLength)
    {
        return kStatus_MCMGR_Error;
    }
    /* Make sure any old handler is inactive */
    MCMGR_eventTable[type].callback = ((void *)0);
    /* Install callback data first */
    MCMGR_eventTable[type].callbackData = callbackData;
    /* Install the callback */
    MCMGR_eventTable[type].callback = callback;

    return kStatus_MCMGR_Success;
}

static mcmgr_status_t MCMGR_TriggerEventCommon(mcmgr_core_t coreNum, mcmgr_event_type_t type, uint16_t eventData, bool forcedWrite)
{
    uint32_t remoteData;
    if (type >= kMCMGR_EventTableLength)
    {
        return kStatus_MCMGR_Error;
    }

    mcmgr_core_t currentCore = MCMGR_GetCurrentCore();
    /*
     * $Branch Coverage Justification$
     * (currentCore > g_mcmgrSystem.coreCount) not covered, MCMGR_GetCurrentCore() returns currentCore from
     * register and g_mcmgrSystem is defined as const.
     */
    if ((uint32_t)currentCore < g_mcmgrSystem.coreCount) /* GCOVR_EXCL_BR_LINE */
    {
        remoteData = (((uint32_t)type) << 16) | eventData;
        return mcmgr_trigger_event_internal(coreNum, remoteData, forcedWrite);
    }
    /*
     * $Line Coverage Justification$
     * Line never reached, MCMGR_GetCurrentCore() returns currentCore from
     * register and g_mcmgrSystem is defined as const.
     */
    return kStatus_MCMGR_Error; /* GCOVR_EXCL_LINE */
}

mcmgr_status_t MCMGR_TriggerEvent(mcmgr_core_t coreNum, mcmgr_event_type_t type, uint16_t eventData)
{
    return MCMGR_TriggerEventCommon(coreNum, type, eventData, false);
}

mcmgr_status_t MCMGR_TriggerEventForce(mcmgr_core_t coreNum, mcmgr_event_type_t type, uint16_t eventData)
{
    return MCMGR_TriggerEventCommon(coreNum, type, eventData, true);
}

static void MCMGR_StartupDataEventHandler(mcmgr_core_t coreNum, uint16_t startupDataChunk, void *context)
{
    mcmgr_core_context_t *coreContext = (mcmgr_core_context_t *)context;

    /*
     * $Branch Coverage Justification$
     * Not possible to get into default case/
     */
    switch (coreContext->state) /* GCOVR_EXCL_BR_LINE */
    {
        case kMCMGR_StartupGettingLowCoreState:
            coreContext->startupData = startupDataChunk; /* Receive the low part */
            coreContext->state       = kMCMGR_StartupGettingHighCoreState;
            (void)MCMGR_TriggerEvent(coreNum, kMCMGR_FeedStartupDataEvent, (uint16_t)kMCMGR_StartupGettingHighCoreState);
            break;

        case kMCMGR_StartupGettingHighCoreState:
            coreContext->startupData |= ((uint32_t)startupDataChunk) << 16;
            coreContext->state = kMCMGR_RunningCoreState;
            (void)MCMGR_TriggerEvent(coreNum, kMCMGR_FeedStartupDataEvent, (uint16_t)kMCMGR_RunningCoreState);
            break;
        /*
         * $Line Coverage Justification$
         * Not possible to get into this default case.
         */
        /* GCOVR_EXCL_START */
        default:
            /* All the cases have been listed above, the default clause should not be reached. */
            break;
    }
    /* GCOVR_EXCL_STOP */
}

static void MCMGR_FeedStartupDataEventHandler(mcmgr_core_t coreNum, uint16_t startupDataChunk, void *context)
{
    mcmgr_core_context_t *coreContext = &((mcmgr_core_context_t *)context)[coreNum];

    /*
     * $Branch Coverage Justification$
     * Not possible to get into default case/
     */
    switch ((mcmgr_core_state_t)startupDataChunk) /* GCOVR_EXCL_BR_LINE */
    {
        case kMCMGR_StartupGettingLowCoreState:
            (void)MCMGR_TriggerEvent(coreNum, kMCMGR_StartupDataEvent, (uint16_t)(coreContext->startupData & 0xFFFFU));
            coreContext->state = (mcmgr_core_state_t)startupDataChunk;
            break;

        case kMCMGR_StartupGettingHighCoreState:
            (void)MCMGR_TriggerEvent(coreNum, kMCMGR_StartupDataEvent, (uint16_t)((coreContext->startupData) >> 16));
            coreContext->state = (mcmgr_core_state_t)startupDataChunk;
            break;

        case kMCMGR_RunningCoreState:
            coreContext->state = (mcmgr_core_state_t)startupDataChunk;
            break;

        /*
         * $Line Coverage Justification$
         * Not possible to get into this default case.
         */
        /* GCOVR_EXCL_START */
        default:
            /* All the cases have been listed above, the default clause should not be reached. */
            break;
    }
    /* GCOVR_EXCL_STOP */
}

mcmgr_status_t MCMGR_EarlyInit(void)
{
    /* This function is intended to be called as close to the reset entry as possible,
       (within the startup sequence in SystemInitHook) to allow CoreUp event triggering.
       Avoid using uninitialized data here. */

    mcmgr_core_t currentCore = MCMGR_GetCurrentCore();
    /*
     * $Branch Coverage Justification$
     * (currentCore > g_mcmgrSystem.coreCount) not covered, MCMGR_GetCurrentCore() returns currentCore from
     * register and g_mcmgrSystem is defined as const.
     */
    if ((uint32_t)currentCore < g_mcmgrSystem.coreCount) /* GCOVR_EXCL_BR_LINE */
    {
        return mcmgr_early_init_internal(currentCore);
    }
    /*
     * $Line Coverage Justification$
     * Line never reached, MCMGR_GetCurrentCore() returns currentCore from
     * register and g_mcmgrSystem is defined as const.
     */
    return kStatus_MCMGR_Error; /* GCOVR_EXCL_LINE */
}

mcmgr_status_t MCMGR_Init(void)
{
    mcmgr_core_t currentCore = MCMGR_GetCurrentCore();
    /*
     * $Branch Coverage Justification$
     * (currentCore > g_mcmgrSystem.coreCount) not covered, MCMGR_GetCurrentCore() returns currentCore from
     * register and g_mcmgrSystem is defined as const.
     */
    if ((uint32_t)currentCore < g_mcmgrSystem.coreCount) /* GCOVR_EXCL_BR_LINE */
    {
        /* Register critical and generic event handlers */
        /*
         * $Branch Coverage Justification$
         * MCMGR_RegisterEvent() params are always correct here.
         */
        if (kStatus_MCMGR_Success != MCMGR_RegisterEvent(kMCMGR_StartupDataEvent, MCMGR_StartupDataEventHandler,
                                                         (void *)&s_mcmgrCoresContext[currentCore])) /* GCOVR_EXCL_BR_LINE */
        {
            /*
             * $Line Coverage Justification$
             * Line never reached, MCMGR_RegisterEvent() params are always correct here.
             */
            return kStatus_MCMGR_Error; /* GCOVR_EXCL_LINE */
        }
        /*
         * $Branch Coverage Justification$
         * MCMGR_RegisterEvent() params are always correct here.
         */
        if (kStatus_MCMGR_Success !=
            MCMGR_RegisterEvent(kMCMGR_FeedStartupDataEvent, MCMGR_FeedStartupDataEventHandler,
                                (void *)s_mcmgrCoresContext)) /* GCOVR_EXCL_BR_LINE */
                                /* In this handler we need access to whole s_mcmgrCoresContext structure
                                 * so we can service requests from any core number `mcmgr_core_t`.
                                 */
        {
            /*
             * $Line Coverage Justification$
             * Line never reached, MCMGR_RegisterEvent() params are always correct here.
             */
            return kStatus_MCMGR_Error; /* GCOVR_EXCL_LINE */
        }
        return mcmgr_late_init_internal(currentCore);
    }
    /*
     * $Line Coverage Justification$
     * Line never reached, MCMGR_GetCurrentCore() returns currentCore from
     * register and g_mcmgrSystem is defined as const.
     */
    return kStatus_MCMGR_Error; /* GCOVR_EXCL_LINE */
}

mcmgr_status_t MCMGR_StartCore(mcmgr_core_t coreNum, void *bootAddress, uint32_t startupData, mcmgr_start_mode_t mode)
{
    mcmgr_status_t ret;

    if ((uint32_t)coreNum < g_mcmgrSystem.coreCount)
    {
        /* Pass the startupData - LSB first */
        s_mcmgrCoresContext[coreNum].startupData = startupData;
        /* the startup data is sent asynchronously */
        ret = mcmgr_start_core_internal(coreNum, bootAddress);

        if (ret == kStatus_MCMGR_Success)
        {
            if (mode == kMCMGR_Start_Synchronous)
            {
#if defined(MCMGR_BUSY_POLL_COUNT) && (MCMGR_BUSY_POLL_COUNT > 0)
                uint32_t poll_count = MCMGR_BUSY_POLL_COUNT;
#endif
                /* Wait until the second core reads and confirms the startup data */
                while (s_mcmgrCoresContext[coreNum].state != kMCMGR_RunningCoreState)
                {
#if defined(MCMGR_BUSY_POLL_COUNT) && (MCMGR_BUSY_POLL_COUNT > 0)
                    if ((--poll_count) == 0u)
                    {
                        return kStatus_MCMGR_Error;
                    }
#endif
                }
            }
            return kStatus_MCMGR_Success;
        }
    }
    return kStatus_MCMGR_Error;
}

mcmgr_status_t MCMGR_GetStartupData(mcmgr_core_t coreNum, uint32_t *startupData)
{
    mcmgr_core_t currentCore = MCMGR_GetCurrentCore();

    /*
     * $Branch Coverage Justification$
     * (currentCore > g_mcmgrSystem.coreCount) not covered, MCMGR_GetCurrentCore() returns currentCore from
     * register and g_mcmgrSystem is defined as const.
     */
    if ((uint32_t)currentCore < g_mcmgrSystem.coreCount) /* GCOVR_EXCL_BR_LINE */
    {
        if (s_mcmgrCoresContext[currentCore].state == kMCMGR_ResetCoreState)
        {
            s_mcmgrCoresContext[currentCore].state = kMCMGR_StartupGettingLowCoreState;
            /*
             * $Branch Coverage Justification$
             * MCMGR_TriggerEvent() params are always correct here.
             */
            if (kStatus_MCMGR_Success !=
                MCMGR_TriggerEvent(coreNum, kMCMGR_FeedStartupDataEvent, (uint16_t)kMCMGR_StartupGettingLowCoreState)) /* GCOVR_EXCL_BR_LINE */
            {
                /*
                 * $Line Coverage Justification$
                 * Line never reached, MCMGR_TriggerEvent() params are always correct here.
                 */
                return kStatus_MCMGR_Error; /* GCOVR_EXCL_LINE */
            }
        }
        return mcmgr_get_startup_data_internal(currentCore, startupData);
    }
    /*
     * $Line Coverage Justification$
     * Line never reached, MCMGR_GetCurrentCore() returns coreNum from
     * register and g_mcmgrSystem is defined as const.
     */
    return kStatus_MCMGR_Error; /* GCOVR_EXCL_LINE */
}

mcmgr_status_t MCMGR_StopCore(mcmgr_core_t coreNum)
{
    if ((uint32_t)coreNum < g_mcmgrSystem.coreCount)
    {
        return mcmgr_stop_core_internal(coreNum);
    }
    return kStatus_MCMGR_Error;
}

int32_t MCMGR_GetVersion(void)
{
    return (int32_t)kMCMGR_Version;
}

mcmgr_status_t MCMGR_GetCoreProperty(mcmgr_core_t coreNum,
                                     mcmgr_core_property_t property,
                                     void *value,
                                     uint32_t *length)
{
    if ((uint32_t)coreNum < g_mcmgrSystem.coreCount)
    {
        return mcmgr_get_core_property_internal(coreNum, property, value, length);
    }
    return kStatus_MCMGR_Error;
}

uint32_t MCMGR_GetCoreCount(void)
{
    return g_mcmgrSystem.coreCount;
}

mcmgr_core_t MCMGR_GetCurrentCore(void)
{
    return mcmgr_get_current_core_internal();
}

mcmgr_status_t MCMGR_ProcessDeferredRxIsr(void)
{
#if (defined(MCMGR_DEFERRED_CALLBACK_ALLOWED) && (MCMGR_DEFERRED_CALLBACK_ALLOWED == 1U))
    return mcmgr_process_deferred_rx_isr_internal();
#else
    return kStatus_MCMGR_NotImplemented;
#endif
}
