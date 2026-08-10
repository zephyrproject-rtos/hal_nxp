/*
 * Copyright 2022-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "mcmgr.h"
#include "mcmgr_internal_core_api.h"
#include "fsl_device_registers.h"
#include "mcmgr_imu_internal.h"

#if defined(SDK_OS_FREE_RTOS)
#include "FreeRTOS.h"
#endif

static mcmgr_status_t mcmgr_platform_init_internal_early(mcmgr_core_t coreNum);

#ifndef IMU_ISR_PRIORITY
#define IMU_ISR_PRIORITY (4U)
#endif

/* The highest interrupt priority that can be used by any interrupt service
 * routine that makes calls to interrupt safe FreeRTOS API functions
 * (higher priorities are lower numeric values) */
#if defined(configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY)
#if IMU_ISR_PRIORITY < configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY
#error "IMU_ISR_PRIORITY value must be greater than or equal to configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY"
#endif
#endif

static mcmgr_status_t mcmgr_platform_init_internal_early(mcmgr_core_t coreNum)
{
    mcmgr_status_t status = kStatus_MCMGR_Error;

    (void)coreNum;

    mcmgr_imu_remote_active_req();

    /*
     * $Branch Coverage Justification$
     * (kStatus_Success != IMU_Init(IMU_LINK)) not covered, IMU_Init function link parameter is
     * macro/enum and can't be changed during the runtime.
     */
    if (kStatus_Success != IMU_Init(IMU_LINK)) /* GCOVR_EXCL_BR_LINE */
    {
        /*
         * $Line Coverage Justification$
         * Line never reached, IMU_Init function link parameter is
         * macro/enum and can't be changed during the runtime.
         */
        return kStatus_MCMGR_Error; /* GCOVR_EXCL_LINE */
    }

    /* Trigger core up event here, core is starting! */
#if (defined(MCMGR_BUILD_FOR_CORE_0))
    status = mcmgr_trigger_event_internal(kMCMGR_Core1, kMCMGR_RemoteCoreUpEvent, 0U, false);
#else
    status = mcmgr_trigger_event_internal(kMCMGR_Core0, kMCMGR_RemoteCoreUpEvent, 0U, false);
#endif

    mcmgr_imu_remote_active_rel();

    /* Trigger core up event here, core is starting! */
    return status;
}

mcmgr_status_t mcmgr_platform_init_internal(mcmgr_core_t coreNum)
{
    mcmgr_status_t status = mcmgr_platform_init_internal_early(coreNum);
    if (status != kStatus_MCMGR_Success)
    {
        return status;
    }

    (void)coreNum; /* Unused */

#if defined(IMU_CPU_INDEX) && (IMU_CPU_INDEX == 1U)
    NVIC_SetPriority((IRQn_Type)RF_IMU0_IRQn, IMU_ISR_PRIORITY);
    NVIC_EnableIRQ((IRQn_Type)RF_IMU0_IRQn);
#elif defined(IMU_CPU_INDEX) && (IMU_CPU_INDEX == 2U)
    NVIC_SetPriority((IRQn_Type)CPU2_MSG_RDY_INT_IRQn, IMU_ISR_PRIORITY);
    NVIC_EnableIRQ((IRQn_Type)CPU2_MSG_RDY_INT_IRQn);
#endif

    return kStatus_MCMGR_Success;
}

mcmgr_core_t mcmgr_get_current_core_internal(void)
{
#if defined(IMU_CPU_INDEX) && (IMU_CPU_INDEX == 1U)
    return kMCMGR_Core0;
#elif defined(IMU_CPU_INDEX) && (IMU_CPU_INDEX == 2U)
    return kMCMGR_Core1;
#endif
}
