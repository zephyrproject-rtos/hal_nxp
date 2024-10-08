/*
 * Copyright 2020-2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "mcmgr.h"
#include "mcmgr_internal_core_api.h"
#include "fsl_device_registers.h"
#include "fsl_imu.h"
#include "mcmgr_imu_internal.h"

#if defined(IMU_CPU_INDEX) && (IMU_CPU_INDEX == 1U)
#define IMU_LINK kIMU_LinkCpu1Cpu2
#elif defined(IMU_CPU_INDEX) && (IMU_CPU_INDEX == 2U)
#define IMU_LINK kIMU_LinkCpu2Cpu1
#endif
/* Count of cores in the system */
#define MCMGR_CORECOUNT 2

/* Count of memory regions in the system */
#define MCMGR_MEMREGCOUNT 2

/* MCMGR MU channel index - used for passing startupData */
#define MCMGR_IMU_CHANNEL 1

#define IMU_RX_ISR_Handler(x)    IMU_RX_ISR(x)
#define IMU_RX_ISR(number)       MU_RxFullFlagISR
#define mcmgr_mu_channel_handler IMU_RX_ISR_Handler(MCMGR_IMU_CHANNEL)

__attribute__((weak)) void mcmgr_imu_remote_active_req(void){};
__attribute__((weak)) void mcmgr_imu_remote_active_rel(void){};

volatile mcmgr_core_context_t s_mcmgrCoresContext[MCMGR_CORECOUNT] = {
    {.state = kMCMGR_ResetCoreState, .startupData = 0}, {.state = kMCMGR_ResetCoreState, .startupData = 0}};

/* Initialize structure with informations of all cores */
static const mcmgr_core_info_t s_mcmgrCores[MCMGR_CORECOUNT] = {
    {.coreType = kMCMGR_CoreTypeCortexM33, .coreName = "Main"},
    {.coreType = kMCMGR_CoreTypeCortexM3, .coreName = "Secondary"}};

const mcmgr_system_info_t g_mcmgrSystem = {
    .coreCount = MCMGR_CORECOUNT, .memRegCount = MCMGR_MEMREGCOUNT, .cores = s_mcmgrCores};

mcmgr_status_t mcmgr_early_init_internal(mcmgr_core_t coreNum)
{
    /* This function is intended to be called as close to the reset entry as possible,
       (within the startup sequence in SystemInitHook) to allow CoreUp event triggering.
       Avoid using uninitialized data here. */
    mcmgr_status_t status = kStatus_MCMGR_Error;

    mcmgr_imu_remote_active_req();

    if (kStatus_Success != IMU_Init(IMU_LINK))
    {
        return kStatus_MCMGR_Error; /* coco validated: line never reached, IMU_Init function link parameter is
                                       macro/enum and can't be changed during the runtime */
    }

    /* Trigger core up event here, core is starting! */
    status = MCMGR_TriggerEvent(kMCMGR_RemoteCoreUpEvent, 0);

    mcmgr_imu_remote_active_rel();

    /* Trigger core up event here, core is starting! */
    return status;
}

mcmgr_status_t mcmgr_start_core_internal(mcmgr_core_t coreNum, void *bootAddress)
{
    mcmgr_status_t status = kStatus_MCMGR_Success;

    do
    {
        if (coreNum != kMCMGR_Core1)
        {
            status = kStatus_MCMGR_Error;
            break;
        }
        else if ((RFMC->RF2P4GHZ_CTRL & RFMC_RF2P4GHZ_CTRL_CPU_RST_LOCK_MASK) != 0U)
        {
            /* The CPU_RST bit is locked, which is used by boot ROM code to force the radio CPU to remain in reset if
             * the radio flash verification fails */
            status = kStatus_MCMGR_Error;
            break;
        }

        /* Release NBU CPU from reset */
        RFMC->RF2P4GHZ_CTRL &= ~(RFMC_RF2P4GHZ_CTRL_CPU_RST_MASK);
        CIU2->CIU2_CPU_CPU2_CTRL = 0x1;
    } while (false);

    return status;
}

mcmgr_status_t mcmgr_get_startup_data_internal(mcmgr_core_t coreNum, uint32_t *startupData)
{
    mcmgr_status_t status = kStatus_MCMGR_Error;

    if (coreNum != kMCMGR_Core1)
    {
        return kStatus_MCMGR_Error;
    }
    if (startupData == ((void *)0))
    {
        return kStatus_MCMGR_Error;
    }

    mcmgr_imu_remote_active_req();

    if (s_mcmgrCoresContext[coreNum].state >= kMCMGR_RunningCoreState)
    {
        *startupData = s_mcmgrCoresContext[coreNum].startupData;
        status       = kStatus_MCMGR_Success;
    }
    else
    {
        status = kStatus_MCMGR_NotReady;
    }

    mcmgr_imu_remote_active_rel();

    return status;
}

mcmgr_status_t mcmgr_stop_core_internal(mcmgr_core_t coreNum)
{
    if (coreNum != kMCMGR_Core1)
    {
        return kStatus_MCMGR_Error;
    }
    /* TODO IMU not supported */
    return kStatus_MCMGR_Success;
}

mcmgr_status_t mcmgr_get_core_property_internal(mcmgr_core_t coreNum,
                                                mcmgr_core_property_t property,
                                                void *value,
                                                uint32_t *length)
{
    return kStatus_MCMGR_NotImplemented;
}

mcmgr_status_t mcmgr_trigger_event_internal(uint32_t remoteData, bool forcedWrite)
{
    int32_t ret;
    mcmgr_status_t status = kStatus_MCMGR_Error;

    mcmgr_imu_remote_active_req();

    /* The IMU driver does not provide the "forcedWrite possibility", it allways
       needs to wait until the previosly triggered transaction is finished. Thus the
      forcedWrite paramter is ignored here and the IMU_SendMsgsBlocking() API is used. */

    /* This is a blocking call */
    ret = IMU_SendMsgsBlocking(IMU_LINK, &remoteData, 1, false);

    mcmgr_imu_remote_active_rel();

    if (ret > 0)
    {
        status = kStatus_MCMGR_Success;
    }
    else
    {
        status = kStatus_MCMGR_Error;
    }

    return status;
}

/*!
 * @brief ISR handler
 *
 * This function is called when data from MU is received
 */
void mcmgr_mu_channel_handler(void)
{
    uint32_t data;
    uint16_t eventType;
    uint16_t eventData;
    bool needAckLock;
    int32_t receivedCount = 0;

    mcmgr_imu_remote_active_req();

    /* Non-blocking version of the receive function needs to be called here to avoid
       deadlock in ISR. The RX register must contain the payload now because the RX flag/event
       has been identified before reaching this point (mcmgr_mu_channel_handler function). */
    receivedCount = IMU_TryReceiveMsgs(IMU_LINK, &data, 1, &needAckLock);
    if (receivedCount != 0)
    {
        /* To be MISRA compliant, return value needs to be checked even it could not never be 0 */
        if (0U != data)
        {
            eventType = (uint16_t)(data >> 16u);
            eventData = (uint16_t)(data & 0x0000FFFFu);

            if (((mcmgr_event_type_t)eventType >= kMCMGR_RemoteCoreUpEvent) &&
                ((mcmgr_event_type_t)eventType < kMCMGR_EventTableLength))
            {
                if (MCMGR_eventTable[(mcmgr_event_type_t)eventType].callback != ((void *)0))
                {
                    MCMGR_eventTable[(mcmgr_event_type_t)eventType].callback(
                        eventData, MCMGR_eventTable[(mcmgr_event_type_t)eventType].callbackData);
                }
            }
        }
    }

    mcmgr_imu_remote_active_rel();
}

#if defined(MCMGR_HANDLE_EXCEPTIONS) && (MCMGR_HANDLE_EXCEPTIONS == 1)
/* coco begin validated: reached after __coveragescanner_save() call becasue it is not possible to return from this ISR
 * and coverage data would not be stored */
/* This overrides the weak DefaultISR implementation from startup file */
void DefaultISR(void)
{
    uint32_t exceptionNumber = __get_IPSR();
    (void)MCMGR_TriggerEvent(kMCMGR_RemoteExceptionEvent, (uint16_t)exceptionNumber);
    for (;;)
    {
    } /* stop here */
}

void HardFault_Handler(void)
{
    DefaultISR();
}

void NMI_Handler(void)
{
    DefaultISR();
}

void MemManage_Handler(void)
{
    DefaultISR();
}

void BusFault_Handler(void)
{
    DefaultISR();
}

void UsageFault_Handler(void)
{
    DefaultISR();
}
/* coco end */
#endif /* MCMGR_HANDLE_EXCEPTIONS */
