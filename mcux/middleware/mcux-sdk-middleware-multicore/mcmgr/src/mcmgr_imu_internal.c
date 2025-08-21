/*
 * Copyright 2020-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_device_registers.h"
#include "fsl_imu.h"
#include "mcmgr.h"
#include "mcmgr_internal_core_api.h"
#include "mcmgr_imu_internal.h"

#define IMU_ISR_COUNT (2U)

#if defined(IMU_CPU_INDEX) && (IMU_CPU_INDEX == 1U)
#define IMU_LINK kIMU_LinkCpu1Cpu2
#define IMU_IRQ RF_IMU0_IRQn
#elif defined(IMU_CPU_INDEX) && (IMU_CPU_INDEX == 2U)
#define IMU_LINK kIMU_LinkCpu2Cpu1
#define IMU_IRQ CPU2_MSG_RDY_INT_IRQn
#endif

/* Weak MU ISR stubs */
/* implement these in your application to override */

void MU_TxEmptyFlagISR(mcmgr_core_t coreNum);
void MU_RxFullFlagISR(mcmgr_core_t coreNum);

__attribute__((weak)) void MU_TxEmptyFlagISR(mcmgr_core_t coreNum){};
__attribute__((weak)) void MU_RxFullFlagISR(mcmgr_core_t coreNum){};

/* MU ISR router */
static void imu_rx_isr(mcmgr_core_t coreNum)
{
    mcmgr_imu_remote_active_req();
#if (defined(MCMGR_DEFERRED_CALLBACK_ALLOWED) && (MCMGR_DEFERRED_CALLBACK_ALLOWED == 1U))
    NVIC_DisableIRQ((IRQn_Type)IMU_IRQ);
    mcmgr_imu_deferred_call(1U);
#else
    IMU_ClearPendingInterrupts(IMU_LINK, IMU_MSG_FIFO_CNTL_MSG_RDY_INT_CLR_MASK);
    MU_RxFullFlagISR(coreNum);
#endif
    /* Need to release active request only after IMU interrupt clearing */
    mcmgr_imu_remote_active_rel();
}

#if defined(IMU_CPU_INDEX) && (IMU_CPU_INDEX == 1U)
int32_t RF_IMU0_IRQHandler(void)
{
    imu_rx_isr(kMCMGR_Core1);
    SDK_ISR_EXIT_BARRIER;
    return 0;
}
#endif

#if defined(IMU_CPU_INDEX) && (IMU_CPU_INDEX == 2U)
int32_t CPU2_MSG_RDY_INT_IRQHandler(void)
{
    imu_rx_isr(kMCMGR_Core0);
    SDK_ISR_EXIT_BARRIER;
    return 0;
}
#endif /* IMU_CPU_INDEX */
