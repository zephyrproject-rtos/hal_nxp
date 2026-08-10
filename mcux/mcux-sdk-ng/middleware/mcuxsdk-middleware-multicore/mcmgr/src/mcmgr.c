/*
 * Copyright (c) 2014-2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "mcmgr.h"
#include "mcmgr_internal_core_api.h"

mcmgr_event_t MCMGR_eventTable[kMCMGR_EventTableLength] = {0};

/* Flag indicating that MCMGR_Init() has completed (or is in progress).
 * Set to true inside MCMGR_Init() BEFORE mcmgr_platform_init_internal()
 * enables the MU RX IRQ, so re-entrant ISR dispatches during init see
 * the flag set.  Rolled back to false on platform-init failure. */
static volatile bool s_mcmgrInitialized = false;

/* Guard macro: return kStatus_MCMGR_NotReady when called before MCMGR_Init()
 * completes.  The flag s_mcmgrInitialized is set to true inside MCMGR_Init()
 * BEFORE mcmgr_platform_init_internal() is called so that any re-entrant MU ISR
 * dispatch that occurs while the MU RX IRQ is being enabled (e.g. on KW43 where
 * the NBU peer is already alive) sees the flag set and is not silently dropped. */
#define MCMGR_CHECK_INIT()                 \
    do                                     \
    {                                      \
        if (!s_mcmgrInitialized)           \
        {                                  \
            return kStatus_MCMGR_NotReady; \
        }                                  \
    } while (false)

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
    if (type >= kMCMGR_EventTableLength)
    {
        return kStatus_MCMGR_Error;
    }
    MCMGR_CHECK_INIT();

    mcmgr_core_t currentCore = MCMGR_GetCurrentCore();
    /*
     * $Branch Coverage Justification$
     * (currentCore > g_mcmgrSystem.coreCount) not covered, MCMGR_GetCurrentCore() returns currentCore from
     * register and g_mcmgrSystem is defined as const.
     */
    if ((uint32_t)currentCore < g_mcmgrSystem.coreCount) /* GCOVR_EXCL_BR_LINE */
    {
        return mcmgr_trigger_event_internal(coreNum, type, eventData, forcedWrite);
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
    /* Compatibility no-op (kept to not break existing public API). */
    return kStatus_MCMGR_Success;
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
        /* Register the internal startup-data event handlers directly into the event
         * table before the IRQ is enabled.  MCMGR_RegisterEvent() is intentionally
         * unguarded and could be used here too, but direct table writes are used to
         * make the ordering dependency on s_mcmgrInitialized explicit. */
        MCMGR_eventTable[kMCMGR_StartupDataEvent].callback     = MCMGR_StartupDataEventHandler;
        MCMGR_eventTable[kMCMGR_StartupDataEvent].callbackData = (void *)&s_mcmgrCoresContext[currentCore];

        /* In this handler we need access to the whole s_mcmgrCoresContext structure
         * so we can service requests from any core number `mcmgr_core_t`. */
        MCMGR_eventTable[kMCMGR_FeedStartupDataEvent].callback     = MCMGR_FeedStartupDataEventHandler;
        MCMGR_eventTable[kMCMGR_FeedStartupDataEvent].callbackData = (void *)s_mcmgrCoresContext;

        /* Set the initialized flag BEFORE mcmgr_platform_init_internal() enables the
         * MU RX IRQ.  On platforms such as KW43 the peer core is already alive and
         * fires a re-entrant MU ISR the instant the IRQ is unmasked.  Any guarded
         * public API function reached from that ISR dispatch (e.g. MCMGR_TriggerEvent
         * in the internal startup-data reply handlers) must see the flag set, otherwise
         * MCMGR_CHECK_INIT() returns NotReady and silently drops the event.
         * Roll the flag back if platform init fails so external callers still see
         * NotReady until a successful MCMGR_Init(). */
        s_mcmgrInitialized = true;

        mcmgr_status_t status = mcmgr_platform_init_internal(currentCore);

        if (status != kStatus_MCMGR_Success)
        {
            s_mcmgrInitialized = false;
        }

        return status;
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

    MCMGR_CHECK_INIT();

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
    mcmgr_core_t currentCore;

    MCMGR_CHECK_INIT();

    currentCore = MCMGR_GetCurrentCore();

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
    MCMGR_CHECK_INIT();

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
    MCMGR_CHECK_INIT();

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
    MCMGR_CHECK_INIT();

#if (defined(MCMGR_DEFERRED_CALLBACK_ALLOWED) && (MCMGR_DEFERRED_CALLBACK_ALLOWED == 1U))
    return mcmgr_process_deferred_rx_isr_internal();
#else
    return kStatus_MCMGR_NotImplemented;
#endif
}
