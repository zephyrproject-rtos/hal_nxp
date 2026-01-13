/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "mcmgr.h"
#include "mcmgr_internal_core_api.h"
#include "fsl_device_registers.h"
#if defined(SDK_OS_FREE_RTOS)
#include "FreeRTOS.h"
#endif

#if defined(configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY)
#ifndef IMU_ISR_PRIORITY
#define IMU_ISR_PRIORITY (configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY)
#endif
#else
#ifndef IMU_ISR_PRIORITY
#define IMU_ISR_PRIORITY (4U)
#endif
#endif

mcmgr_status_t mcmgr_late_init_internal(mcmgr_core_t coreNum)
{
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
    return (mcmgr_core_t)MSCM->CPXNUM;
#elif defined(IMU_CPU_INDEX) && (IMU_CPU_INDEX == 2U)
    return kMCMGR_Core1;
#endif
}
