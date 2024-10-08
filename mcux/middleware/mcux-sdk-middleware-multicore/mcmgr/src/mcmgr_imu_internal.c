/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
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
#elif defined(IMU_CPU_INDEX) && (IMU_CPU_INDEX == 2U)
#define IMU_LINK kIMU_LinkCpu2Cpu1
#endif

/* Weak MU ISR stubs */
/* implement these in your application to override */

void MU_TxEmptyFlagISR(void);
void MU_RxFullFlagISR(void);

__attribute__((weak)) void MU_TxEmptyFlagISR(void){};
__attribute__((weak)) void MU_RxFullFlagISR(void){};

/* MU ISR router */
static void imu_rx_isr(void)
{
    mcmgr_imu_remote_active_req();
    MU_RxFullFlagISR();
    IMU_ClearPendingInterrupts(IMU_LINK, IMU_MSG_FIFO_CNTL_MSG_RDY_INT_CLR_MASK);

    /* Need to release active request only after IMU interrupt clearing */
    mcmgr_imu_remote_active_rel();
}

#if defined(IMU_CPU_INDEX) && (IMU_CPU_INDEX == 1U)
int32_t RF_IMU0_IRQHandler(void)
{
    imu_rx_isr();
    SDK_ISR_EXIT_BARRIER;
    return 0;
}
#endif

#if defined(IMU_CPU_INDEX) && (IMU_CPU_INDEX == 2U)
int32_t CPU2_MSG_RDY_INT_IRQHandler(void)
{
    imu_rx_isr();
    SDK_ISR_EXIT_BARRIER;
    return 0;
}
#endif /* IMU_CPU_INDEX */
