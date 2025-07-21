/*
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* Includes */

#include "fsl_power.h"
#include "fsl_reset.h"
#include "fsl_device_registers.h"
#if CONFIG_DIRECT
#include "fsl_ccm.h"
#include "fsl_cpu.h"
#include "fsl_src.h"

/* Local Defines */

/* Local Types */

typedef struct {
  uint32_t LPM0;
  uint32_t LPM1;
} cpu_per_lpi_lpgc_t;

typedef struct {
    uint8_t flag0;
    uint8_t flag1;
    uint8_t flag2;
    uint8_t flag3;
    uint32_t turn;
} cpu_semaphore_t;

/* Local Functions */

static bool CPU_SwMultiWakeup(uint32_t cpuIdx);
static bool CPU_SleepModeMultiSet(uint32_t cpuIdx, uint32_t sleepMode);
static bool CPU_WdogReset(uint32_t cpuIdx);
static bool CPU_SemaphoreReset(uint32_t cpuIdx);
static bool CPU_SemaphoreRequest(uint32_t cpuIdx, uint32_t timeoutUsec);
static bool CPU_MiscCtrlSet(uint32_t cpuIdx, uint32_t mask, uint32_t val);
static bool CPU_MiscCtrlGet(uint32_t cpuIdx, uint32_t mask, uint32_t *val);
static bool CPU_IrqMaskSet(uint32_t cpuIdx, bool maskIrqs);
static bool CPU_WakeMaskSet(uint32_t cpuIdx, bool maskWakeups);
static bool CPU_LpmMixDependSet(uint32_t cpuIdx, uint32_t lpmSetting);
static bool CPU_PerLpiConfigInit(uint32_t cpuIdx);
static bool CPU_PerLpiConfigDeInit(uint32_t cpuIdx);

/* Local Variables */

static GPC_CPU_CTRL_Type *const s_gpcCpuCtrlPtrs[] = GPC_CPU_CTRL_BASE_PTRS;

static cpu_wdog_info_t const s_cpuWdogInfoM7P_0 =
{
    .secIrq = NotAvail_IRQn,
    .nonsecIrq = NotAvail_IRQn,
    .rstLine = RST_LINE_WAKEUPMIX_WDOG_5
};

static cpu_wdog_info_t const s_cpuWdogInfoM7P_1 =
{
    .secIrq = NotAvail_IRQn,
    .nonsecIrq = NotAvail_IRQn,
    .rstLine = RST_LINE_WAKEUPMIX_WDOG_6
};

static cpu_wdog_info_t const s_cpuWdogInfoM33P_S =
{
    .secIrq = NotAvail_IRQn,
    .nonsecIrq = NotAvail_IRQn,
    .rstLine = RST_LINE_NETCMIX_WDOG_7_8,
};

static cpu_wdog_info_t const s_cpuWdogInfoA55 =
{
    .secIrq = NotAvail_IRQn,
    .nonsecIrq = NotAvail_IRQn,
    .rstLine = RST_LINE_NOCMIX_WDOG_3_4
};

static cpu_mgmt_info_t const s_cpuMgmtInfo[CPU_NUM_IDX] =
{
    [CPU_IDX_M33P] =
    {
        .srcMixIdx = PWR_MIX_SLICE_IDX_AON,
        .cpuWaitReg = &BLK_CTRL_S_AONMIX->M33_CFG,
        .cpuWaitMask = BLK_CTRL_S_AONMIX_M33_CFG_WAIT_MASK,
        .rstReqIrq = NotAvail_IRQn,
        .lockupIrq = NotAvail_IRQn,
        .wdogInfo = NULL,
        .vectorRegHigh = NULL,
        .vectorRegLow = &BLK_CTRL_S_AONMIX->INITSVTOR,
        .vectorShift = 0U,
        .cmcSysSleepCtrl = GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_SUSPEND_MASK,
        .cmcMisc = GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_EN_MASK
    },

    [CPU_IDX_M7P_0] =
    {
        .srcMixIdx = PWR_MIX_SLICE_IDX_M7_0,
        .cpuWaitReg = &BLK_CTRL_S_AONMIX->M7_CFG,
        .cpuWaitMask = BLK_CTRL_S_AONMIX_M7_CFG_WAIT_MASK,
        .rstReqIrq = CM7_0_SYSRESETREQ_IRQn,
        .lockupIrq = CM7_0_LOCKUP_IRQn,
        .wdogInfo = &s_cpuWdogInfoM7P_0,
        .vectorRegHigh = NULL,
        .vectorRegLow = &BLK_CTRL_S_AONMIX->INITVTOR,
        .vectorShift = 0U,
        .cmcSysSleepCtrl = GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_SUSPEND_MASK,
        .cmcMisc = GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_EN_MASK
    },

    [CPU_IDX_A55C0] =
    {
        .srcMixIdx = PWR_MIX_SLICE_IDX_A55C0,
        .cpuWaitReg = &BLK_CTRL_S_AONMIX->CA55_CPUWAIT,
        .cpuWaitMask = BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT_MASK,
        .rstReqIrq = NotAvail_IRQn,
        .lockupIrq = NotAvail_IRQn,
        .wdogInfo = &s_cpuWdogInfoA55,
        .vectorRegHigh = &BLK_CTRL_S_AONMIX->CA55_RVBARADDR0_H,
        .vectorRegLow = &BLK_CTRL_S_AONMIX->CA55_RVBARADDR0_L,
        .vectorShift = 2U,
        .cmcSysSleepCtrl = 0U,
        .cmcMisc = GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_MASK
    },

    [CPU_IDX_A55C1] =
    {
        .srcMixIdx = PWR_MIX_SLICE_IDX_A55C1,
        .cpuWaitReg = &BLK_CTRL_S_AONMIX->CA55_CPUWAIT,
        .cpuWaitMask = BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT_MASK,
        .rstReqIrq = NotAvail_IRQn,
        .lockupIrq = NotAvail_IRQn,
        .wdogInfo = &s_cpuWdogInfoA55,
        .vectorRegHigh = &BLK_CTRL_S_AONMIX->CA55_RVBARADDR1_H,
        .vectorRegLow = &BLK_CTRL_S_AONMIX->CA55_RVBARADDR1_L,
        .vectorShift = 2U,
        .cmcSysSleepCtrl = 0U,
        .cmcMisc = GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_MASK
    },

    [CPU_IDX_A55C2] =
    {
        .srcMixIdx = PWR_MIX_SLICE_IDX_A55C2,
        .cpuWaitReg = &BLK_CTRL_S_AONMIX->CA55_CPUWAIT,
        .cpuWaitMask = BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU2_WAIT_MASK,
        .rstReqIrq = NotAvail_IRQn,
        .lockupIrq = NotAvail_IRQn,
        .wdogInfo = &s_cpuWdogInfoA55,
        .vectorRegHigh = &BLK_CTRL_S_AONMIX->CA55_RVBARADDR2_H,
        .vectorRegLow = &BLK_CTRL_S_AONMIX->CA55_RVBARADDR2_L,
        .vectorShift = 2U,
        .cmcSysSleepCtrl = 0U,
        .cmcMisc = GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_MASK
    },

    [CPU_IDX_A55C3] =
    {
        .srcMixIdx = PWR_MIX_SLICE_IDX_A55C3,
        .cpuWaitReg = &BLK_CTRL_S_AONMIX->CA55_CPUWAIT,
        .cpuWaitMask = BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU3_WAIT_MASK,
        .rstReqIrq = NotAvail_IRQn,
        .lockupIrq = NotAvail_IRQn,
        .wdogInfo = &s_cpuWdogInfoA55,
        .vectorRegHigh = &BLK_CTRL_S_AONMIX->CA55_RVBARADDR3_H,
        .vectorRegLow = &BLK_CTRL_S_AONMIX->CA55_RVBARADDR3_L,
        .vectorShift = 2U,
        .cmcSysSleepCtrl = 0U,
        .cmcMisc = GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_MASK
    },

    [CPU_IDX_A55P] =
    {
        .srcMixIdx = PWR_MIX_SLICE_IDX_A55P,
        .cpuWaitReg = NULL,
        .cpuWaitMask = 0U,
        .rstReqIrq = NotAvail_IRQn,
        .lockupIrq = NotAvail_IRQn,
        .wdogInfo = &s_cpuWdogInfoA55,
        .vectorRegHigh = NULL,
        .vectorRegLow = NULL,
        .vectorShift = 2U,
        .cmcSysSleepCtrl = GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_SUSPEND_MASK,
        .cmcMisc = GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_MASK
    },

    [CPU_IDX_M7P_1] =
    {
        .srcMixIdx = PWR_MIX_SLICE_IDX_M7_1,
        .cpuWaitReg = &BLK_CTRL_S_AONMIX->M7_1_CFG,
        .cpuWaitMask = BLK_CTRL_S_AONMIX_M7_1_CFG_WAIT_MASK,
        .rstReqIrq = CM7_1_SYSRESETREQ_IRQn,
        .lockupIrq = CM7_1_LOCKUP_IRQn,
        .wdogInfo = &s_cpuWdogInfoM7P_1,
        .vectorRegHigh = NULL,
        .vectorRegLow = &BLK_CTRL_S_AONMIX->INITVTOR_1,
        .vectorShift = 0U,
        .cmcSysSleepCtrl = GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_SUSPEND_MASK,
        .cmcMisc = GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_EN_MASK
    },

    [CPU_IDX_M33P_S] =
    {
        .srcMixIdx = PWR_MIX_SLICE_IDX_NETC,
        .cpuWaitReg = &BLK_CTRL_S_AONMIX->M33_SYNC_CFG,
        .cpuWaitMask = BLK_CTRL_S_AONMIX_M33_SYNC_CFG_WAIT_MASK,
        .rstReqIrq = CM33_1_SYSRESETREQ_IRQn,
        .lockupIrq = CM33_1_LOCKUP_IRQn,
        .wdogInfo = &s_cpuWdogInfoM33P_S,
        .vectorRegHigh = NULL,
        .vectorRegLow = &BLK_CTRL_S_AONMIX->INITSVTOR_SYNC,
        .vectorShift = 0U,
        .cmcSysSleepCtrl = GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_SUSPEND_MASK,
        .cmcMisc = GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_EN_MASK
    },
};

/* TODO may need to be refined */
static cpu_per_lpi_info_t const s_cpuPerLpiInfo[CPU_NUM_PER_LPI_IDX] =
{
    [CPU_PER_LPI_IDX_GPIO1] =
    {
        .lpcgIdx = CCM_LPCG_GPIO1,
    },

    [CPU_PER_LPI_IDX_GPIO2] =
    {
        .lpcgIdx = CCM_LPCG_GPIO2,
    },

    [CPU_PER_LPI_IDX_GPIO3] =
    {
        .lpcgIdx = CCM_LPCG_GPIO3,
    },

    [CPU_PER_LPI_IDX_GPIO4] =
    {
        .lpcgIdx = CCM_LPCG_GPIO4,
    },

    [CPU_PER_LPI_IDX_GPIO5] =
    {
        .lpcgIdx = CCM_LPCG_GPIO5,
    },

    [CPU_PER_LPI_IDX_GPIO6] =
    {
        .lpcgIdx = CCM_LPCG_GPIO6,
    },

    [CPU_PER_LPI_IDX_GPIO7] =
    {
        .lpcgIdx = CCM_LPCG_GPIO7,
    },

    [CPU_PER_LPI_IDX_CAN1] =
    {
        .lpcgIdx = CCM_LPCG_CAN1,
    },

    [CPU_PER_LPI_IDX_CAN2] =
    {
        .lpcgIdx = CCM_LPCG_CAN2,
    },

    [CPU_PER_LPI_IDX_CAN3] =
    {
        .lpcgIdx = CCM_LPCG_CAN3,
    },

    [CPU_PER_LPI_IDX_CAN4] =
    {
        .lpcgIdx = CCM_LPCG_CAN4,
    },

    [CPU_PER_LPI_IDX_CAN5] =
    {
        .lpcgIdx = CCM_LPCG_CAN5,
    },

    [CPU_PER_LPI_IDX_LPUART1] =
    {
        .lpcgIdx = CCM_LPCG_LPUART1,
    },

    [CPU_PER_LPI_IDX_LPUART2] =
    {
        .lpcgIdx = CCM_LPCG_LPUART2,
    },

    [CPU_PER_LPI_IDX_LPUART3] =
    {
        .lpcgIdx = CCM_LPCG_LPUART3,
    },

    [CPU_PER_LPI_IDX_LPUART4] =
    {
        .lpcgIdx = CCM_LPCG_LPUART4,
    },

    [CPU_PER_LPI_IDX_LPUART5] =
    {
        .lpcgIdx = CCM_LPCG_LPUART5,
    },

    [CPU_PER_LPI_IDX_LPUART6] =
    {
        .lpcgIdx = CCM_LPCG_LPUART6,
    },

    [CPU_PER_LPI_IDX_LPUART7] =
    {
        .lpcgIdx = CCM_LPCG_LPUART7,
    },

    [CPU_PER_LPI_IDX_LPUART8] =
    {
        .lpcgIdx = CCM_LPCG_LPUART8,
    },

    [CPU_PER_LPI_IDX_LPUART9] =
    {
        .lpcgIdx = CCM_LPCG_LPUART9,
    },

    [CPU_PER_LPI_IDX_LPUART10] =
    {
        .lpcgIdx = CCM_LPCG_LPUART10,
    },

    [CPU_PER_LPI_IDX_LPUART11] =
    {
        .lpcgIdx = CCM_LPCG_LPUART11,
    },

    [CPU_PER_LPI_IDX_LPUART12] =
    {
        .lpcgIdx = CCM_LPCG_LPUART12,
    },

    [CPU_PER_LPI_IDX_WDOG3] =
    {
        .lpcgIdx = CCM_LPCG_WDOG3,
    },

    [CPU_PER_LPI_IDX_WDOG4] =
    {
        .lpcgIdx = CCM_LPCG_WDOG4,
    },

    [CPU_PER_LPI_IDX_WDOG5] =
    {
        .lpcgIdx = CCM_LPCG_WDOG5,
    },

    [CPU_PER_LPI_IDX_WDOG6] =
    {
        .lpcgIdx = CCM_LPCG_WDOG6,
    },

    [CPU_PER_LPI_IDX_WDOG7] =
    {
        .lpcgIdx = CCM_LPCG_WDOG7,
    },

    [CPU_PER_LPI_IDX_WDOG8] =
    {
        .lpcgIdx = CCM_LPCG_WDOG8,
    }
};

static uint32_t s_cpuSemaAddr[CPU_NUM_IDX];

/* Global Variables */

extern void GPC_SM_REQ_IRQHandler(void);

/*--------------------------------------------------------------------------*/
/* Initialize CMC/GPC interfaces for the CPU                                */
/*--------------------------------------------------------------------------*/
bool CPU_Init(uint32_t cpuIdx, uint32_t cpuSemaAddr)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        /* Save semaphore address */
        s_cpuSemaAddr[cpuIdx] = cpuSemaAddr;

        /* Reset semaphore */
        (void) CPU_SemaphoreReset(cpuIdx);

        /* Configure system-level sleep control default */
        uint32_t sysSleepCtrl = s_cpuMgmtInfo[cpuIdx].cmcSysSleepCtrl;
        s_gpcCpuCtrlPtrs[cpuIdx]->CMC_SYS_SLEEP_CTRL = sysSleepCtrl;

        /* Configure IRQ_MUX and SLEEPHOLD default */
        uint32_t cmcMisc = s_cpuMgmtInfo[cpuIdx].cmcMisc;
        s_gpcCpuCtrlPtrs[cpuIdx]->CMC_MISC = cmcMisc;

        /* Enable LPCG handshake step by default */
        //s_gpcCpuCtrlPtrs[cpuIdx]->CMC_SLEEP_LPCG_CTRL &=
        //    ~GPC_CPU_CTRL_CMC_SLEEP_LPCG_CTRL_DISABLE_MASK;
        //s_gpcCpuCtrlPtrs[cpuIdx]->CMC_WAKEUP_LPCG_CTRL &=
        //    ~GPC_CPU_CTRL_CMC_WAKEUP_LPCG_CTRL_DISABLE_MASK;

        /* CPUs supporting SLEEPHOLD should not enable A55 handshake */
        if ((cmcMisc & GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_EN_MASK) != 0U)
        {
            s_gpcCpuCtrlPtrs[cpuIdx]->CMC_SLEEP_A55_HDSK_CTRL |= 
                GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_CTRL_DISABLE_MASK;

            s_gpcCpuCtrlPtrs[cpuIdx]->CMC_WAKEUP_A55_HDSK_CTRL |= 
                GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_CTRL_DISABLE_MASK;
        }

        /* Apply GPC domain assignment */
        GPC_GLOBAL->GPC_CPU_DOMAIN_ASSIGNMENT[cpuIdx] = CPU2GPC(cpuIdx);

        /* For all CPUs except M33P, remove sleep status in evaluation
         * of system suspend until started.
         */
        rc = CPU_SleepForceSet(cpuIdx, (cpuIdx != CPU_IDX_M33P));

        /* Initialize peripheral low-power interfaces */
        if (rc)
        {
            rc = CPU_PerLpiConfigInit(cpuIdx);
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPUWAIT signal                                                       */
/*--------------------------------------------------------------------------*/
bool CPU_WaitSet(uint32_t cpuIdx, bool enableCpuWait)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        if (s_cpuMgmtInfo[cpuIdx].cpuWaitReg != NULL)
        {
            __IO uint32_t *cpuWaitReg = s_cpuMgmtInfo[cpuIdx].cpuWaitReg;

            uint32_t cpuWaitVal = *cpuWaitReg;

            if (enableCpuWait)
            {
                cpuWaitVal |= s_cpuMgmtInfo[cpuIdx].cpuWaitMask;
            }
            else
            {
                cpuWaitVal &= ~s_cpuMgmtInfo[cpuIdx].cpuWaitMask;
            }

            *cpuWaitReg = cpuWaitVal;

            rc = true;
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CPUWAIT signal                                                       */
/*--------------------------------------------------------------------------*/
bool CPU_WaitGet(uint32_t cpuIdx, bool *cpuWait)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        if (s_cpuMgmtInfo[cpuIdx].cpuWaitReg != NULL)
        {
            __IO const uint32_t *cpuWaitReg = s_cpuMgmtInfo[cpuIdx].cpuWaitReg;

            if ((*cpuWaitReg & s_cpuMgmtInfo[cpuIdx].cpuWaitMask) == 0U)
            {
                *cpuWait = false;
            }
            else
            {
                *cpuWait = true;
            }

            rc = true;
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Generate SW_WAKEUP event                                                 */
/*--------------------------------------------------------------------------*/
bool CPU_SwWakeup(uint32_t cpuIdx)
{
    bool rc = false;

    /* Assert SW_WAKEUP */
    rc = CPU_MiscCtrlSet(cpuIdx,
        GPC_CPU_CTRL_CMC_MISC_SW_WAKEUP_MASK,
        GPC_CPU_CTRL_CMC_MISC_SW_WAKEUP_MASK);

    /* Wait for CPU to wake */
    if (rc)
    {
        uint32_t fsmStat;
        do
        {
            rc = CPU_FsmStateGet(cpuIdx, &fsmStat);
        } while (rc && (fsmStat == CPU_FSM_STATE_IDLE_SLEEP));
    }

    /* Deassert SW_WAKEUP */
    if (rc)
    {
        rc = CPU_MiscCtrlSet(cpuIdx,
            GPC_CPU_CTRL_CMC_MISC_SW_WAKEUP_MASK,
            0);
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Generate SW_WAKEUP event for multiple CPUs                               */
/*--------------------------------------------------------------------------*/
static bool CPU_SwMultiWakeup(uint32_t cpuIdx)
{
    bool rc = false;

    uint32_t cpuIdxCur = cpuIdx;
    uint32_t cpuIdxEnd = cpuIdx;
    if (cpuIdx == CPU_IDX_A55P)
    {
        cpuIdxCur = CPU_IDX_A55P;
        cpuIdxEnd = CPU_IDX_A55C0;
    }
    do
    {
        /* Wake each CPU */
        rc = CPU_SwWakeup(cpuIdxCur);
        --cpuIdxCur;
    } while (rc && (cpuIdxCur >= cpuIdxEnd));

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Reset CPU WDOG modules                                                   */
/*--------------------------------------------------------------------------*/
static bool CPU_WdogReset(uint32_t cpuIdx)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        cpu_wdog_info_t const *wdogInfo = s_cpuMgmtInfo[cpuIdx].wdogInfo;

        if (wdogInfo != NULL)
        {
            /* Assert WDOG module reset */
            uint32_t rstline = wdogInfo->rstLine;
            rc = SRC_MixSetResetLine(rstline, RST_LINE_CTRL_ASSERT);
            
            /* Wait for reset assertion to complete */
            uint32_t resetType = RST_LINE_CTRL_UNKNOWN;
            while (rc && (resetType != RST_LINE_CTRL_ASSERT))
            {
                rc = SRC_MixGetResetLine(rstline, &resetType);
            }
            
            /* Deassert WDOG module reset */
            if (rc)
            {
                rc = SRC_MixSetResetLine(rstline, RST_LINE_CTRL_DEASSERT);
            }
            
            /* Wait for reset deassertion to complete */
            resetType = RST_LINE_CTRL_UNKNOWN;
            while (rc && (resetType != RST_LINE_CTRL_DEASSERT))
            {
                rc = SRC_MixGetResetLine(rstline, &resetType);
            }
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Reset CPU semaphore                                                      */
/*--------------------------------------------------------------------------*/
static bool CPU_SemaphoreReset(uint32_t cpuIdx)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        if (s_cpuSemaAddr[cpuIdx] != 0U)
        {
            cpu_semaphore_t *sema = (cpu_semaphore_t *) s_cpuSemaAddr[cpuIdx];

            sema->flag0 = 0U;
            sema->flag1 = 0U;
            sema->turn = 0U;
        }
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Request CPU semaphore with timeout                                       */
/*--------------------------------------------------------------------------*/
static bool CPU_SemaphoreRequest(uint32_t cpuIdx, uint32_t timeoutUsec)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        if (s_cpuSemaAddr[cpuIdx] != 0U)
        {
            cpu_semaphore_t *sema = (cpu_semaphore_t *) s_cpuSemaAddr[cpuIdx];

            sema->flag0 = 1U;
            sema->turn = 1U;

            uint32_t pollUsec = 0U;

            bool busy = (sema->flag1 == 1U) && (sema->turn == 1U);

            /* Poll until CPU semaphore released */
            while (busy && (pollUsec < timeoutUsec))
            {
                SystemTimeDelay(1U);
                ++pollUsec;
                busy = (sema->flag1 == 1U) && (sema->turn == 1U);
            }

            rc = !busy;
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Enable/disable CPU IRQs                                                  */
/*--------------------------------------------------------------------------*/
bool CPU_IrqSet(uint32_t cpuIdx, bool enableCpuIrq)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        IRQn_Type rstReqIrq = s_cpuMgmtInfo[cpuIdx].rstReqIrq;
        if (rstReqIrq != NotAvail_IRQn)
        {
            if (enableCpuIrq)
            {
                /* Configure CPU SYSRESETREQ handler */
                NVIC_EnableIRQ(rstReqIrq);
            }
            else
            {
                NVIC_DisableIRQ(rstReqIrq);
            }
        }

        IRQn_Type lockupIrq = s_cpuMgmtInfo[cpuIdx].lockupIrq;
        if (lockupIrq != NotAvail_IRQn)
        {
            if (enableCpuIrq)
            {
                /* Configure CPU LOCKUP handler */
                NVIC_EnableIRQ(lockupIrq);
            }
            else
            {
                NVIC_DisableIRQ(lockupIrq);
                NVIC_ClearPendingIRQ(lockupIrq);
            }
        }
        
        IRQn_Type secWdogIrq = NotAvail_IRQn;
        IRQn_Type nonsecWdogIrq = NotAvail_IRQn;
        cpu_wdog_info_t const *wdogInfo = s_cpuMgmtInfo[cpuIdx].wdogInfo;
        if (wdogInfo != NULL)
        {
            secWdogIrq = wdogInfo->secIrq;
            nonsecWdogIrq = wdogInfo->nonsecIrq;
        }

        if (secWdogIrq != NotAvail_IRQn)
        {
            if (enableCpuIrq)
            {
                /* Only configure once per cluster */
                if (NVIC_GetEnableIRQ(secWdogIrq) == 0U)
                {
                    /* Configure secure WDOG handler */
                    NVIC_EnableIRQ(secWdogIrq);
                }
            }
            else
            {
                NVIC_DisableIRQ(secWdogIrq);
            }
        }

        if (nonsecWdogIrq != NotAvail_IRQn)
        {
            if (enableCpuIrq)
            {
                /* Only configure once per cluster */
                if (NVIC_GetEnableIRQ(nonsecWdogIrq) == 0U)
                {
                    /* Configure secure WDOG handler */
                    NVIC_EnableIRQ(nonsecWdogIrq);
                }
            }
            else
            {
                NVIC_DisableIRQ(nonsecWdogIrq);
            }
        }
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set GPC shandshakes associated with CPU                                  */
/*--------------------------------------------------------------------------*/
bool CPU_GpcHandshakeSet(uint32_t cpuIdx,bool enableHandshake)
{
    bool rc = false;

    switch(cpuIdx)
    {
        case CPU_IDX_M7P_0:
            PWR_LpHandshakeMaskSet(PWR_MIX_SLICE_IDX_M7_0, enableHandshake);
            rc = true;
            break;

        case CPU_IDX_M7P_1:
            PWR_LpHandshakeMaskSet(PWR_MIX_SLICE_IDX_M7_1, enableHandshake);
            rc = true;
            break;

        case CPU_IDX_M33P_S:
            PWR_LpHandshakeMaskSet(PWR_MIX_SLICE_IDX_NETC, enableHandshake);
            rc = true;
            break;

        case CPU_IDX_A55P:
            {
                PWR_LpHandshakeMaskSet(PWR_MIX_SLICE_IDX_A55P, enableHandshake);
                uint32_t srcMixIdx = PWR_MIX_SLICE_IDX_A55C0;
                while (srcMixIdx <= PWR_MIX_SLICE_IDX_A55C_LAST)
                {
                    PWR_LpHandshakeMaskSet(srcMixIdx, enableHandshake);
                    srcMixIdx++;
                }
            }
            rc = true;
            break;

        default:
            ; /* Intentional empty default */
            break;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPU reset signal                                                     */
/*--------------------------------------------------------------------------*/
bool CPU_ResetSet(uint32_t cpuIdx, uint32_t resetType)
{
    bool rc = false;

    switch(cpuIdx)
    {
        case CPU_IDX_M7P_0:
            rc = SRC_MixSetResetLine(RST_LINE_M70MIX, resetType);
            if (rc && (resetType == RST_LINE_CTRL_ASSERT))
            {
                rc = CPU_WaitSet(CPU_IDX_M7P_0, true);
            }
            break;

        case CPU_IDX_M7P_1:
            rc = SRC_MixSetResetLine(RST_LINE_M71MIX, resetType);
            if (rc && (resetType == RST_LINE_CTRL_ASSERT))
            {
                rc = CPU_WaitSet(CPU_IDX_M7P_1, true);
            }
            break;

        case CPU_IDX_M33P_S:
            rc = SRC_MixSetResetLine(RST_LINE_NETCMIX_M33, resetType);
            if (rc && (resetType == RST_LINE_CTRL_ASSERT))
            {
                rc = CPU_WaitSet(CPU_IDX_M33P_S, true);
            }
            break;

        case CPU_IDX_A55P:
            {
                /* FIXME: Prior to reset of A55, enable the non-cooperate reset control */
                if (resetType == RST_LINE_CTRL_ASSERT)
                {
                    BLK_CTRL_NS_AONMIX->AONMIX_MISC |= BLK_CTRL_NS_AONMIX_AONMIX_MISC_CA55_Idle_mask_non_cooperative_MASK;
                }

                /* Prior to reset of A55, quiese the GIC interfaces */
                if (resetType == RST_LINE_CTRL_ASSERT)
                {
                    /* Request CPU semaphore for atomic access to GIC */
                    (void) CPU_SemaphoreRequest(CPU_IDX_A55P, 100U);

                    uint32_t gicdIdxLast = CPU_IDX_A55C_LAST - CPU_IDX_A55C0;
                    for (uint32_t gicdIdx = 0U; gicdIdx <= gicdIdxLast; gicdIdx++)
                    {
#if 0
                        GICR_Type *const gicrPtrs[] = GICR_BASE_PTRS;
                        GICR_Type *GICR = gicrPtrs[gicdIdx];

                        /* Set ProcessorSleep to quiesce GIC redistributor instance */
                        GICR->GICR_WAKER |= GICR_WAKER_PROCESSORSLEEP_MASK;

                        /* Wait for ChildrenAsleep */
                        while ((GICR->GICR_WAKER & GICR_WAKER_CHILDRENASLEEP_MASK) == 0U)
                        {
                            /* Set ProcessorSleep to quiesce GIC redistributor instance */
                            GICR->GICR_WAKER |= GICR_WAKER_PROCESSORSLEEP_MASK;
                        }
#endif
                    }
                }

                /* Apply reset to A55 cluster */
                rc = SRC_MixSetResetLine(RST_LINE_CORTEXAMIX_PLATFORM, resetType);

                if (rc && (resetType == RST_LINE_CTRL_ASSERT))
                {
                    /* Wait for A55 cluster reset phase to complete */
                    rc = SRC_MixRstExit(PWR_MIX_SLICE_IDX_A55P, 100U);
                }

                /* Apply reset to all A55 CPUs */
                uint32_t lineIdx = RST_LINE_CORTEXAMIX_CORE0;
                uint32_t lineIdxEnd = RST_LINE_CORTEXAMIX_CORE0 + 
                                      CPU_IDX_A55C_LAST - CPU_IDX_A55C0;
                uint32_t cpuIdxA55 = CPU_IDX_A55C0;
                while(rc  && (lineIdx <= lineIdxEnd))
                {
                    uint32_t srcMixIdx = s_cpuMgmtInfo[cpuIdxA55].srcMixIdx;
                    /* Skip unpowered A55 CPUs */                    
                    if (SRC_MixIsPwrSwitchOn(srcMixIdx))
                    {
                        rc = SRC_MixSetResetLine(lineIdx, resetType);
                        if (rc && (resetType == RST_LINE_CTRL_ASSERT))
                        {
                            rc = CPU_WaitSet(cpuIdxA55, true);
                        }
                    }
                    ++lineIdx;
                    ++cpuIdxA55;
                }

                /* FIXME: After reset of A55, clear the non-cooperate reset control */
                if (resetType == RST_LINE_CTRL_DEASSERT)
                {
                    BLK_CTRL_NS_AONMIX->AONMIX_MISC &= ~BLK_CTRL_NS_AONMIX_AONMIX_MISC_CA55_Idle_mask_non_cooperative_MASK;
                }
            }
            break;

        default:
            ; /* Intentional empty default */
            break;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CPU reset signal                                                     */
/*--------------------------------------------------------------------------*/
bool CPU_ResetGet(uint32_t cpuIdx, uint32_t *resetType)
{
    bool rc = false;

    switch(cpuIdx)
    {
        case CPU_IDX_M7P_0:
            rc = SRC_MixGetResetLine(RST_LINE_M70MIX, resetType);
            break;

        case CPU_IDX_M7P_1:
            rc = SRC_MixGetResetLine(RST_LINE_M71MIX, resetType);
            break;

        case CPU_IDX_M33P_S:
            rc = SRC_MixGetResetLine(RST_LINE_NETCMIX_M33, resetType);
            break;

        case CPU_IDX_A55P:
            {
                /* Get reset status of A55 cluster */
                rc = SRC_MixGetResetLine(RST_LINE_CORTEXAMIX_PLATFORM, 
                                         resetType);

                /* Check if reset status of A55 CPUs matches cluster  */
                uint32_t lineIdx = RST_LINE_CORTEXAMIX_CORE0;
                uint32_t lineIdxEnd = RST_LINE_CORTEXAMIX_CORE0 + 
                                      CPU_IDX_A55C_LAST - CPU_IDX_A55C0;
                uint32_t cpuIdxA55 = CPU_IDX_A55C0;
                while(rc  && (lineIdx <= lineIdxEnd) && 
                      (*resetType != RST_LINE_CTRL_UNKNOWN))
                {
                    uint32_t srcMixIdx = s_cpuMgmtInfo[cpuIdxA55].srcMixIdx;
                    /* Skip unpowered A55 CPUs */                    
                    if (SRC_MixIsPwrSwitchOn(srcMixIdx))
                    {
                        uint32_t resetTypeA55;
                        rc = SRC_MixGetResetLine(lineIdx, &resetTypeA55);
                        if (rc && (resetTypeA55 != *resetType))
                        {
                            *resetType = RST_LINE_CTRL_UNKNOWN;
                        }
                    }
                    ++lineIdx;
                    ++cpuIdxA55;
                }
            }
            break;

        default:
            ; /* Intentional empty default */
            break;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CPU FSM state                                                        */
/*--------------------------------------------------------------------------*/
bool CPU_FsmStateGet(uint32_t cpuIdx, uint32_t *fsmState)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        uint32_t modeStat = s_gpcCpuCtrlPtrs[cpuIdx]->CMC_MODE_STAT;
        *fsmState = (modeStat & GPC_CPU_CTRL_CMC_MODE_STAT_FSM_STATE_MASK) >>
            GPC_CPU_CTRL_CMC_MODE_STAT_FSM_STATE_SHIFT;

        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPU run mode                                                         */
/*--------------------------------------------------------------------------*/
bool CPU_RunModeSet(uint32_t cpuIdx, uint32_t runMode)
{
    bool rc = false;
    uint32_t curRunMode;

    if (cpuIdx < CPU_NUM_IDX)
    {
        if (CPU_RunModeGet(cpuIdx, &curRunMode))
        {
            switch(runMode)
            {
                case CPU_RUN_MODE_START:
                    /* if CPU stopped, power up respective mix and release */
                    if (curRunMode == CPU_RUN_MODE_STOP)
                    {
                        /* Make sure MIX of CPU is powered */
                        (void) SRC_MixSoftPowerUp(s_cpuMgmtInfo[cpuIdx].srcMixIdx);

                        /* Include CPU in HW-controlled MIX voting logic */
                        rc = CPU_LpmConfigInit(cpuIdx);

                        /* Release CPUWAIT */
                        if (rc)
                        {
                            rc = CPU_WaitSet(cpuIdx, false);
                        }

                        /* Enable SM IRQs associated with this CPU */
                        if (rc)
                        {
                            rc = CPU_IrqSet(cpuIdx, true);
                        }
                    }
                    /* If CPU sleeping, use SW_WAKEUP */
                    else if (curRunMode == CPU_RUN_MODE_SLEEP)
                    {
                        /* Perform SW wakeup */
                        rc = CPU_SwWakeup(cpuIdx);
                    }
                    /* If CPU in hold, release */
                    else if (curRunMode == CPU_RUN_MODE_HOLD)
                    {
                        /* Include CPU in HW-controlled MIX voting logic
                         *
                         * NOTE:  Current RUN mode for CPU started by ROM
                         *        will be HOLD.  Ensure LPM configuration
                         *        is done here even though it may be 
                         *        redundant for OFF -> HOLD -> START
                         */
                        rc = CPU_LpmConfigInit(cpuIdx);

                        /* Release CPUWAIT */
                        if (rc)
                        {
                            rc = CPU_WaitSet(cpuIdx, false);
                        }

                        /* Enable SM IRQs associated with this CPU */
                        if (rc)
                        {
                            rc = CPU_IrqSet(cpuIdx, true);
                        }
                    }
                    /* other current states should result in error */
                    else
                    {
                        ; /* Intentional empty else */
                    }
                    break;

                case CPU_RUN_MODE_HOLD:
                    /* if CPU stopped, power up respective mix and hold */
                    if (curRunMode == CPU_RUN_MODE_STOP)
                    {
                        /* Make sure MIX of CPU is powered */
                        (void) SRC_MixSoftPowerUp(s_cpuMgmtInfo[cpuIdx].srcMixIdx);

                        /* Include CPU in HW-controlled MIX voting logic */
                        rc = CPU_LpmConfigInit(cpuIdx);
                    }
                    /* other current states should result in error */
                    break;

                case CPU_RUN_MODE_STOP:
                    /* If CPU not already stopped, reset CPU and hold */
                    if (curRunMode != CPU_RUN_MODE_STOP)
                    {
                        /* Force MIX voting logic to request ON during reset */
                        rc = CPU_LpmConfigDeInit(cpuIdx, CPU_PD_LPM_ON_ALWAYS);

                        /* Disable top-level IRQs */
                        if (rc)
                        {
                            rc = CPU_IrqMaskSet(cpuIdx, true);
                        }

                        /* Reset CPU sleep mode */
                        if (rc)
                        {
                            rc = CPU_SleepModeMultiSet(cpuIdx, CPU_SLEEP_MODE_RUN);
                        }

                        /* Wake all sleeping CPUs */
                        if (rc)
                        {
                            /* Perform SW wakeup */
                            rc = CPU_SwMultiWakeup(cpuIdx);
                        }
                        
                        if (rc)
                        {
                            /* Process MIX handshakes until CPU MIX is ready */
                            while (!SRC_MixIsPwrReady(s_cpuMgmtInfo[cpuIdx].srcMixIdx))
                            {
                                //if (NVIC_GetPendingIRQ(GPC_SM_REQ_IRQn) == 1U)
                                //{
                                //    GPC_SM_REQ_IRQHandler();
                                //    NVIC_ClearPendingIRQ(GPC_SM_REQ_IRQn);
                                //}
                            }

                            /* Inhibit GPC LP handshake during CPU reset */
                            rc = CPU_GpcHandshakeSet(cpuIdx, false);
                        }

                        /* Assert CPU platform reset to force stoppage */
                        if (rc)
                        {
                            rc = CPU_ResetSet(cpuIdx, RST_LINE_CTRL_ASSERT);
                        }

                        /* Wait for reset assertion to complete */
                        uint32_t resetType = RST_LINE_CTRL_UNKNOWN;
                        while (rc && (resetType != RST_LINE_CTRL_ASSERT))
                        {
                            rc = CPU_ResetGet(cpuIdx, &resetType);
                        }

                        /* Reset WDOGs for this CPU
                         *
                         * NOTE:  WDOGs associated with this CPU will be
                         *  reset to prevent NVIC of CPU being stopped from 
                         *  latching a new occurrence of the WDOG IRQ after 
                         *  release of CPU reset.
                         */
                        if (rc)
                        {
                            rc = CPU_WdogReset(cpuIdx);
                        }

                        /* Deassert CPU platform reset */
                        if (rc)
                        {
                            rc = CPU_ResetSet(cpuIdx, RST_LINE_CTRL_DEASSERT);
                        }

                        /* Wait for reset deassertion to complete */
                        resetType = RST_LINE_CTRL_UNKNOWN;
                        while (rc && (resetType != RST_LINE_CTRL_DEASSERT))
                        {
                            rc = CPU_ResetGet(cpuIdx, &resetType);
                        }

                        /* Disable SM IRQs associated with this CPU */
                        if (rc)
                        {
                            rc = CPU_IrqSet(cpuIdx, false);
                        }

                        /* Remove CPU from HW-controlled MIX voting logic */
                        if (rc)
                        {
                            rc = CPU_LpmConfigDeInit(cpuIdx, CPU_PD_LPM_ON_NEVER);
                        }

                        /* Deinitialize peripheral low-power interfaces */
                        if (rc)
                        {
                            rc = CPU_PerLpiConfigDeInit(cpuIdx);
                        }

                        /* Reset CPU semaphore */
                        if (rc)
                        {
                            rc = CPU_SemaphoreReset(cpuIdx);
                        }

                        /* Restore GPC LP handshake */
                        if (rc)
                        {
                            rc = CPU_GpcHandshakeSet(cpuIdx, true);
                        }
                    }
                    /* other current states should result in error */
                    break;

                default:
                    ; /* Intentional empty default */
                    break;
            }
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CPU run mode                                                         */
/*--------------------------------------------------------------------------*/
bool CPU_RunModeGet(uint32_t cpuIdx, uint32_t *runMode)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        if (SRC_MixIsPwrReady(s_cpuMgmtInfo[cpuIdx].srcMixIdx))
        {
            uint32_t cpuIdxCur = cpuIdx;
            uint32_t cpuIdxEnd = cpuIdx;
            if (cpuIdx == CPU_IDX_A55P)
            {
                cpuIdxCur = CPU_IDX_A55C0;
                cpuIdxEnd = CPU_IDX_A55C_LAST;
            }
            do
            {
                bool cpuWait;
                rc = CPU_WaitGet(cpuIdxCur, &cpuWait);
                if (rc)
                {
                    if (cpuWait)
                    {
                        *runMode = CPU_RUN_MODE_HOLD;
                    }
                    else
                    {
                        *runMode = CPU_RUN_MODE_START;
                    }
                }
                ++cpuIdxCur;
            } while (rc && (cpuIdxCur <= cpuIdxEnd) && 
                    (*runMode == CPU_RUN_MODE_HOLD));
        }
        else
        {
            /* Check if CPU power gated as a result of entering SLEEP */
            uint32_t fsmState;
            rc = CPU_FsmStateGet(cpuIdx, &fsmState);
            if (rc)
            {
                if (fsmState != CPU_FSM_STATE_IDLE_RUN)
                {
                    *runMode = CPU_RUN_MODE_SLEEP;
                }
                else
                {
                    *runMode = CPU_RUN_MODE_STOP;
                }
            }
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPU sleep mode                                                       */
/*--------------------------------------------------------------------------*/
bool CPU_SleepModeSet(uint32_t cpuIdx, uint32_t sleepMode)
{
    bool rc = false;

    if ((cpuIdx < CPU_NUM_IDX) && (sleepMode <= CPU_NUM_SLEEP_MODES))
    {
        /* Set targeted sleep mode */
        uint32_t cmcModeCtrl = s_gpcCpuCtrlPtrs[cpuIdx]->CMC_MODE_CTRL;
        cmcModeCtrl &= (~GPC_CPU_CTRL_CMC_MODE_CTRL_CPU_MODE_TARGET_MASK);
        cmcModeCtrl |= GPC_CPU_CTRL_CMC_MODE_CTRL_CPU_MODE_TARGET(sleepMode);
        s_gpcCpuCtrlPtrs[cpuIdx]->CMC_MODE_CTRL = cmcModeCtrl;

        /* Configure sleep-hold interface */
        if ((s_cpuMgmtInfo[cpuIdx].cmcMisc &
            GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_EN_MASK) != 0U)
        {
            /* Enable sleep-hold interface unless sleep mode is RUN */
            uint32_t cmcMisc = s_gpcCpuCtrlPtrs[cpuIdx]->CMC_MISC;
            if (sleepMode == CPU_SLEEP_MODE_RUN)
            {
                 cmcMisc &= ~GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_EN_MASK;
            }
            else
            {
                cmcMisc |= GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_EN_MASK;
            }
            s_gpcCpuCtrlPtrs[cpuIdx]->CMC_MISC = cmcMisc;
        }

        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPU sleep mode for multiple CPUs                                     */
/*--------------------------------------------------------------------------*/
static bool CPU_SleepModeMultiSet(uint32_t cpuIdx, uint32_t sleepMode)
{
    bool rc = false;

    if ((cpuIdx < CPU_NUM_IDX) && (sleepMode <= CPU_NUM_SLEEP_MODES))
    {
        uint32_t cpuIdxCur = cpuIdx;
        uint32_t cpuIdxEnd = cpuIdx;
        if (cpuIdx == CPU_IDX_A55P)
        {
            cpuIdxCur = CPU_IDX_A55C0;
            cpuIdxEnd = CPU_IDX_A55P;
        }
        do
        {
            /* Set sleep mode for each CPU */
            rc = CPU_SleepModeSet(cpuIdxCur, sleepMode);
            ++cpuIdxCur;
        } while (rc && (cpuIdxCur <= cpuIdxEnd));
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CPU sleep mode                                                       */
/*--------------------------------------------------------------------------*/
bool CPU_SleepModeGet(uint32_t cpuIdx, uint32_t *sleepMode)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        *sleepMode = (s_gpcCpuCtrlPtrs[cpuIdx]->CMC_MODE_CTRL & 
            GPC_CPU_CTRL_CMC_MODE_CTRL_CPU_MODE_TARGET_MASK) >> 
            GPC_CPU_CTRL_CMC_MODE_CTRL_CPU_MODE_TARGET_SHIFT;
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPU sleep force control                                              */
/*--------------------------------------------------------------------------*/
bool CPU_SleepForceSet(uint32_t cpuIdx, bool sleepForce)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        uint32_t sleepForceReg = GPC_GLOBAL->GPC_SYS_SLEEP;
        uint32_t sleepMask =
            1UL << (cpuIdx + GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU_DISABLE_SHIFT);

        if (sleepForce)
        {
            sleepForceReg |= sleepMask;

            /* Mask GPC wakeups to ensure wakeup request deasserted
             * prior to forcing sleep for this CPU.
             */
            rc = CPU_WakeMaskSet(cpuIdx, true);
        }
        else
        {
            sleepForceReg &= ~sleepMask;

            rc = true;
        }

        GPC_GLOBAL->GPC_SYS_SLEEP = sleepForceReg;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CPU sleep force control                                              */
/*--------------------------------------------------------------------------*/
bool CPU_SleepForceGet(uint32_t cpuIdx, bool *sleepForce)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        uint32_t sleepForceReg = GPC_GLOBAL->GPC_SYS_SLEEP;
        uint32_t sleepMask =
            1UL << (cpuIdx + GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU_DISABLE_SHIFT);

        if ((sleepForceReg & sleepMask) != 0U)
        {
            *sleepForce = true;
        }
        else
        {
            *sleepForce = false;
        }

        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set system-level sleep control                                           */
/*--------------------------------------------------------------------------*/
bool CPU_SystemSleepSet(uint32_t cpuIdx, uint32_t sysSleep)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        s_gpcCpuCtrlPtrs[cpuIdx]->CMC_SYS_SLEEP_CTRL = sysSleep;
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get system-level sleep control                                           */
/*--------------------------------------------------------------------------*/
bool CPU_SystemSleepGet(uint32_t cpuIdx, uint32_t *sysSleep)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        *sysSleep = s_gpcCpuCtrlPtrs[cpuIdx]->CMC_SYS_SLEEP_CTRL;
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get system-level sleep status                                            */
/*--------------------------------------------------------------------------*/
bool CPU_SystemSleepStatusGet(uint32_t *sysSleepStat)
{
    bool rc = true;

    /* Check conditions to enter system sleep */
    *sysSleepStat = CPU_SLEEP_MODE_SUSPEND;
    uint32_t cpuIdx = 0U;
    for (cpuIdx = 0U; cpuIdx < CPU_NUM_IDX; cpuIdx++)
    {
        if (cpuIdx != CPU_IDX_M33P)
        {
            /* Check if sleep is forced for the CPU */
            bool sleepForce;
            if (CPU_SleepForceGet(cpuIdx, &sleepForce))
            {
                /* If sleep is not forced, consider the CPU mode */
                if (!sleepForce)
                {
                    uint32_t cpuModeStat =
                        (s_gpcCpuCtrlPtrs[cpuIdx]->CMC_PIN_STAT &
                        GPC_CPU_CTRL_CMC_PIN_STAT_CPU_MODE_STAT_MASK) >>
                        GPC_CPU_CTRL_CMC_PIN_STAT_CPU_MODE_STAT_SHIFT;

                    /* Keep track of lowest CPU mode (RUN is lowest) */
                    if (cpuModeStat < *sysSleepStat)
                    {
                        *sysSleepStat = cpuModeStat;
                    }
                }
            }
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set misc CPU controls                                                    */
/*--------------------------------------------------------------------------*/
static bool CPU_MiscCtrlSet(uint32_t cpuIdx, uint32_t mask, uint32_t val)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        uint32_t cmcMisc = s_gpcCpuCtrlPtrs[cpuIdx]->CMC_MISC;
        cmcMisc &= ~mask;
        cmcMisc |= val;
        s_gpcCpuCtrlPtrs[cpuIdx]->CMC_MISC = cmcMisc;
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get misc CPU controls                                                    */
/*--------------------------------------------------------------------------*/
static bool CPU_MiscCtrlGet(uint32_t cpuIdx, uint32_t mask, uint32_t *val)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        uint32_t cmcMisc = s_gpcCpuCtrlPtrs[cpuIdx]->CMC_MISC;
        *val = cmcMisc & mask;
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set wake mux (GPC/GIC)                                                   */
/*--------------------------------------------------------------------------*/
bool CPU_WakeMuxSet(uint32_t cpuIdx, bool gicWake)
{
    uint32_t val = 0U;

    if (gicWake)
    {
        val = GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_MASK;
    }

    return CPU_MiscCtrlSet(cpuIdx, GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_MASK, val);
}

/*--------------------------------------------------------------------------*/
/* Get wake mux (GPC/GIC)                                                   */
/*--------------------------------------------------------------------------*/
bool CPU_WakeMuxGet(uint32_t cpuIdx, bool *gicWake)
{
    uint32_t val = 0U;

    bool rc = CPU_MiscCtrlGet(cpuIdx, GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_MASK, &val);

    if (rc)
    {
        if (val != 0U)
        {
            *gicWake = true;
        }
        else
        {
            *gicWake = false;
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set GPC IRQ wake mask                                                    */
/*--------------------------------------------------------------------------*/
bool CPU_IrqWakeSet(uint32_t cpuIdx, uint32_t maskIdx, uint32_t maskVal)
{
    bool rc = false;

    if ((cpuIdx < CPU_NUM_IDX) && 
        (maskIdx < GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_COUNT))
    {
        s_gpcCpuCtrlPtrs[cpuIdx]->CMC_IRQ_WAKEUP_MASK[maskIdx] = maskVal;
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get GPC IRQ wake mask                                                    */
/*--------------------------------------------------------------------------*/
bool CPU_IrqWakeGet(uint32_t cpuIdx, uint32_t maskIdx, uint32_t *maskVal)
{
    bool rc = false;

    if ((cpuIdx < CPU_NUM_IDX) && 
        (maskIdx < GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_COUNT))
    {
        *maskVal = s_gpcCpuCtrlPtrs[cpuIdx]->CMC_IRQ_WAKEUP_MASK[maskIdx];
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set GPC non-IRQ wake mask                                                */
/*--------------------------------------------------------------------------*/
bool CPU_NonIrqWakeSet(uint32_t cpuIdx, uint32_t maskVal)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        s_gpcCpuCtrlPtrs[cpuIdx]->CMC_NON_IRQ_WAKEUP_MASK = maskVal;
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get GPC IRQ wake mask                                                    */
/*--------------------------------------------------------------------------*/
bool CPU_NonIrqWakeGet(uint32_t cpuIdx, uint32_t *maskVal)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        *maskVal = s_gpcCpuCtrlPtrs[cpuIdx]->CMC_NON_IRQ_WAKEUP_MASK;
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPU top-level IRQ mask                                               */
/*--------------------------------------------------------------------------*/
static bool CPU_IrqMaskSet(uint32_t cpuIdx, bool maskIrqs)
{
    bool rc = true;
    uint32_t irqMaskVal;

    if (maskIrqs)
    {
        irqMaskVal = 0x0U;
    }
    else
    {
        irqMaskVal = 0xFFFFFFFFU;
    }

    switch(cpuIdx)
    {
        case CPU_IDX_M7P_0:
            BLK_CTRL_S_AONMIX->CM7_0_IRQ_MASK0 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM7_0_IRQ_MASK1 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM7_0_IRQ_MASK2 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM7_0_IRQ_MASK3 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM7_0_IRQ_MASK4 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM7_0_IRQ_MASK5 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM7_0_IRQ_MASK6 = irqMaskVal;
            break;

        case CPU_IDX_M7P_1:
            BLK_CTRL_S_AONMIX->CM7_1_IRQ_MASK0 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM7_1_IRQ_MASK1 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM7_1_IRQ_MASK2 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM7_1_IRQ_MASK3 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM7_1_IRQ_MASK4 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM7_1_IRQ_MASK5 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM7_1_IRQ_MASK6 = irqMaskVal;
            break;

        case CPU_IDX_M33P_S:
            BLK_CTRL_S_AONMIX->CM33_SYNC_IRQ_MASK0 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM33_SYNC_IRQ_MASK1 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM33_SYNC_IRQ_MASK2 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM33_SYNC_IRQ_MASK3 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM33_SYNC_IRQ_MASK4 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM33_SYNC_IRQ_MASK5 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM33_SYNC_IRQ_MASK6 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM33_SYNC_IRQ_MASK7 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM33_SYNC_IRQ_MASK8 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM33_SYNC_IRQ_MASK9 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM33_SYNC_IRQ_MASK10 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM33_SYNC_IRQ_MASK11 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CM33_SYNC_IRQ_MASK12 = irqMaskVal;
            break;

        case CPU_IDX_A55P:
            BLK_CTRL_S_AONMIX->CA55_IRQ_MASK[0] = irqMaskVal;
            BLK_CTRL_S_AONMIX->CA55_IRQ_MASK[1] = irqMaskVal;
            BLK_CTRL_S_AONMIX->CA55_IRQ_MASK[2] = irqMaskVal;
            BLK_CTRL_S_AONMIX->CA55_IRQ_MASK[3] = irqMaskVal;
            BLK_CTRL_S_AONMIX->CA55_IRQ_MASK[4] = irqMaskVal;
            BLK_CTRL_S_AONMIX->CA55_IRQ_MASK[5] = irqMaskVal;
            BLK_CTRL_S_AONMIX->CA55_IRQ_MASK6 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CA55_IRQ_MASK7 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CA55_IRQ_MASK8 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CA55_IRQ_MASK9 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CA55_IRQ_MASK10 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CA55_IRQ_MASK11 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CA55_IRQ_MASK12 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CA55_IRQ_MASK13 = irqMaskVal;
            BLK_CTRL_S_AONMIX->CA55_IRQ_MASK14 = irqMaskVal;
            break;

        default:
            ; /* Intentional empty default */
            break;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPU GPC wake mask                                                    */
/*--------------------------------------------------------------------------*/
static bool CPU_WakeMaskSet(uint32_t cpuIdx, bool maskWakeups)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        /* Mask/unmask GPC wakeups */
        for (uint32_t idx = 0;
            idx < GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_COUNT;
            idx++)
        {
            if (maskWakeups)
            {
                s_gpcCpuCtrlPtrs[cpuIdx]->CMC_IRQ_WAKEUP_MASK[idx] = 0xFFFFFFFFU;
            }
            else
            {
                s_gpcCpuCtrlPtrs[cpuIdx]->CMC_IRQ_WAKEUP_MASK[idx] = 0x0U;
            }
        }

        if (maskWakeups)
        {
            /* Mask all GPC non-IRQ wakeups */
            s_gpcCpuCtrlPtrs[cpuIdx]->CMC_NON_IRQ_WAKEUP_MASK = 0xFFFFFFFFU;

            /* Reset wakeup IRQ_MUX to GPC */
            rc = CPU_WakeMuxSet(cpuIdx, false);
        }
        else
        {
            /* Configure GPC non-IRQ wakeups to reset default */
            s_gpcCpuCtrlPtrs[cpuIdx]->CMC_NON_IRQ_WAKEUP_MASK = 0x1U;

            rc = true;
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set GPC wake mask for multiple CPUs                                      */
/*--------------------------------------------------------------------------*/
static bool CPU_WakeMaskMultiSet(uint32_t cpuIdx, bool maskWakeups)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        uint32_t cpuIdxCur = cpuIdx;
        uint32_t cpuIdxEnd = cpuIdx;
        if (cpuIdx == CPU_IDX_A55P)
        {
            cpuIdxCur = CPU_IDX_A55C0;
            cpuIdxEnd = CPU_IDX_A55P;
        }
        do
        {
            /* Set GPC wake mask for each CPU */
            rc = CPU_WakeMaskSet(cpuIdxCur, maskWakeups);
            ++cpuIdxCur;
        } while (rc && (cpuIdxCur <= cpuIdxEnd));
    }

    return rc;
}


/*--------------------------------------------------------------------------*/
/* Set CPU power domain LPM config                                          */
/*--------------------------------------------------------------------------*/
bool CPU_LpmConfigSet(uint32_t cpuIdx, uint32_t srcMixIdx,
    uint32_t lpmSetting, uint32_t retMask)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        if (lpmSetting < CPU_NUM_PD_LPM)
        {
             rc = SRC_MixCpuLpmSet(srcMixIdx, cpuIdx, lpmSetting);
        }

        if (rc == true)
        {
            rc = SRC_MemRetentionModeSet(srcMixIdx, retMask);
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPU MIX-level LPM dependencies                                       */
/*--------------------------------------------------------------------------*/
static bool CPU_LpmMixDependSet(uint32_t cpuIdx, uint32_t lpmSetting)
{    
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        /* Initialize LPM response for CPU MIX */
        uint32_t srcMixIdx = s_cpuMgmtInfo[cpuIdx].srcMixIdx;
        rc = SRC_MixCpuLpmSet(srcMixIdx, cpuIdx, lpmSetting);

        /* Initialize LPM response for dependent MIXes */
        if (rc)
        {
            rc = SRC_MixCpuLpmSet(PWR_MIX_SLICE_IDX_DDR, cpuIdx, 
                lpmSetting);
        }
        
        if (rc)
        {
            rc = SRC_MixCpuLpmSet(PWR_MIX_SLICE_IDX_NOC, cpuIdx, 
                lpmSetting);
        }
        
        if (rc)
        {
            rc = SRC_MixCpuLpmSet(PWR_MIX_SLICE_IDX_WAKEUP, cpuIdx, 
                lpmSetting);
        }
    }

    return rc;   
}

/*--------------------------------------------------------------------------*/
/* Initialize CPU power domain LPM config                                   */
/*--------------------------------------------------------------------------*/
bool CPU_LpmConfigInit(uint32_t cpuIdx)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        /* Initialize CPU LPM MIX dependencies */
        rc = CPU_LpmMixDependSet(cpuIdx, CPU_PD_LPM_ON_RUN_WAIT_STOP);

        if (rc)
        {
            /* Check if starting an A55 CPU */
            if ((cpuIdx >= CPU_IDX_A55C0) && (cpuIdx <= CPU_IDX_A55C_LAST))
            {
                /* Check if first CPU of A55P being started */
                if (PWR_NumChildPowered(PWR_MIX_SLICE_IDX_A55P) == 1U)
                {
                    /* Include A55P sleep status in evaluation of system suspend */
                    rc = CPU_SleepForceSet(CPU_IDX_A55P, false);

                    /* Enable top-level IRQs */
                    if (rc)
                    {
                        rc = CPU_IrqMaskSet(CPU_IDX_A55P, false);
                    }

                    /* Reset GPC wake masks */
                    if (rc)
                    {
                        rc = CPU_WakeMaskMultiSet(CPU_IDX_A55P, false);
                    }

                    /* Initialize A55P LPM MIX dependencies */
                    if (rc)
                    {
                        rc = CPU_LpmMixDependSet(CPU_IDX_A55P, CPU_PD_LPM_ON_RUN_WAIT_STOP);
                    }
                }
            }
            else
            {
                /* Include CPU sleep status in evaluation of system suspend */
                rc = CPU_SleepForceSet(cpuIdx, false);

                /* Enable top-level IRQs */
                if (rc)
                {
                    rc = CPU_IrqMaskSet(cpuIdx, false);
                }

                /* Reset GPC wake masks */
                if (rc)
                {
                    rc = CPU_WakeMaskSet(cpuIdx, false);
                }
            }
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Deinitialize CPU power domain LPM config                                 */
/*--------------------------------------------------------------------------*/
bool CPU_LpmConfigDeInit(uint32_t cpuIdx, uint32_t lpmSetting)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        /* Remove CPU sleep status in evaluation of system suspend */
        if (lpmSetting == CPU_PD_LPM_ON_NEVER)
        {
            (void) CPU_SleepForceSet(cpuIdx, true);
        }

        uint32_t cpuIdxCur = cpuIdx;
        uint32_t cpuIdxEnd = cpuIdx;
        if (cpuIdx == CPU_IDX_A55P)
        {
            cpuIdxCur = CPU_IDX_A55C0;
            cpuIdxEnd = CPU_IDX_A55P;
        }
        do
        {
            /* Remove CPU LPM MIX dependencies */
            rc = CPU_LpmMixDependSet(cpuIdxCur, lpmSetting);
            ++cpuIdxCur;
        } while (rc && (cpuIdxCur <= cpuIdxEnd));
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPU peripheral low-power interface config                            */
/*--------------------------------------------------------------------------*/
bool CPU_PerLpiConfigSet(uint32_t cpuIdx, uint32_t perLpiIdx,
    uint32_t lpmSetting)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        if (perLpiIdx < CPU_NUM_PER_LPI_IDX)
        {
            if (lpmSetting < CPU_NUM_PD_LPM)
            {
                uint32_t lpcgIdx = s_cpuPerLpiInfo[perLpiIdx].lpcgIdx;

                /* Update LPM setting for this CPU */
                rc = CCM_LpcgLpmSet(lpcgIdx, cpuIdx, lpmSetting);

                uint32_t accessList;
                if (rc)
                {
                    /* Query access list of this LPCG */
                    rc = CCM_LpcgAccessGet(lpcgIdx, &accessList);
                }

                if (rc)
                {
                    /* Add CPU to LPCG access list */
                    accessList |= WHITELIST_MASK(cpuIdx);

                    rc = CCM_LpcgAccessSet(lpcgIdx, accessList);
                }                

                if (rc)
                {
                    /* Move LPCG to hardware control (LPM_MODE = 1) */
                    rc = CCM_LpcgModeSet(lpcgIdx, LPCG_CPU_LPM_EN);
                }                
            }
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CPU peripheral low-power interface config                            */
/*--------------------------------------------------------------------------*/
bool CPU_PerLpiConfigGet(uint32_t cpuIdx, uint32_t perLpiIdx,
    uint32_t *lpmSetting)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        if (perLpiIdx < CPU_NUM_PER_LPI_IDX)
        {
            uint32_t lpcgIdx = s_cpuPerLpiInfo[perLpiIdx].lpcgIdx;

            rc = CCM_LpcgLpmGet(lpcgIdx, cpuIdx, lpmSetting);
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Initialize CPU peripheral low-power interface config                     */
/*--------------------------------------------------------------------------*/
static bool CPU_PerLpiConfigInit(uint32_t cpuIdx)
{
    bool rc = false;

    /* LPI init applied during M33P CPU init */
    if (cpuIdx == CPU_IDX_M33P)
    {
        uint32_t perLpiIdx = 0U;
        do
        {
            uint32_t lpcgIdx = s_cpuPerLpiInfo[perLpiIdx].lpcgIdx;

            /* Default LPCG access list to SM only */
            uint32_t accessList = WHITELIST_MASK(CPU_IDX_M33P);
            rc = CCM_LpcgAccessSet(lpcgIdx, accessList);

            perLpiIdx++;
        } while (rc && (perLpiIdx < CPU_NUM_PER_LPI_IDX));
    }
    else
    {
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* DeInitialize CPU peripheral low-power interface config                   */
/*--------------------------------------------------------------------------*/
static bool CPU_PerLpiConfigDeInit(uint32_t cpuIdx)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        uint32_t perLpiIdx = 0U;
        do
        {
            uint32_t accessList;
            bool hasAccess = false;
            uint32_t lpcgIdx = s_cpuPerLpiInfo[perLpiIdx].lpcgIdx;

            /* Query access list of this LPCG */
            rc = CCM_LpcgAccessGet(lpcgIdx, &accessList);

            if (rc)
            {
                hasAccess = (accessList & WHITELIST_MASK(cpuIdx)) != 0U;
            }

            if (rc && hasAccess)
            {
                /* Remove CPU from access list */
                accessList &= (~(WHITELIST_MASK(cpuIdx)));

                /* Check if only SM remains in the access list */
                if (accessList == WHITELIST_MASK(CPU_IDX_M33P))
                {
                    /* Move LPCG to software control (LPM_MODE = 0) */
                    rc = CCM_LpcgModeSet(lpcgIdx, 0U);                        
                }
            }

            if (rc && hasAccess)
            {
                /* Update access list */
                rc = CCM_LpcgAccessSet(lpcgIdx, accessList);
            }

            if (rc && hasAccess)
            {
                /* Reset LPM setting for this CPU */
                rc = CCM_LpcgLpmSet(lpcgIdx, cpuIdx,
                    CPU_PD_LPM_ON_NEVER);
            }

            perLpiIdx++;
        } while (rc && (perLpiIdx < CPU_NUM_PER_LPI_IDX));
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Handle notification of MIX power up                                      */
/*--------------------------------------------------------------------------*/
void CPU_MixPowerUpNotify(uint32_t srcMixIdx)
{
}

/*--------------------------------------------------------------------------*/
/* Handle notification of MIX power down                                    */
/*--------------------------------------------------------------------------*/
void CPU_MixPowerDownNotify(uint32_t srcMixIdx)
{
}

/*--------------------------------------------------------------------------*/
/* Set CPU reset vector                                                     */
/*--------------------------------------------------------------------------*/
bool CPU_ResetVectorSet(uint32_t cpuIdx, uint64_t vector)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        /* Get vector attributes */
        uint32_t vectorShift = s_cpuMgmtInfo[cpuIdx].vectorShift;
        __IO uint32_t *vectorRegLow = s_cpuMgmtInfo[cpuIdx].vectorRegLow;
        __IO uint32_t *vectorRegHigh = s_cpuMgmtInfo[cpuIdx].vectorRegHigh;

        /* Check if CPU has vector */
        if (vectorRegLow != NULL)
        {
            /* Set lower 32-bit vector */
            *vectorRegLow = (uint32_t) ((vector & 0xFFFFFFFFULL) >> vectorShift);

            /* Check if CPU has 64-bit vector */
            if (vectorRegHigh != NULL)
            {
                /* Set upper 32-bit vector */
                *vectorRegHigh = (uint32_t) (vector >> (32U + vectorShift));
            }

            rc = true;
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CPU reset vector                                                     */
/*--------------------------------------------------------------------------*/
bool CPU_ResetVectorGet(uint32_t cpuIdx, uint64_t *vector)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        /* Get vector attributes */
        uint32_t vectorShift = s_cpuMgmtInfo[cpuIdx].vectorShift;
        __IO const uint32_t *vectorRegLow = s_cpuMgmtInfo[cpuIdx].vectorRegLow;
        __IO const uint32_t *vectorRegHigh = s_cpuMgmtInfo[cpuIdx].vectorRegHigh;

        /* Check if CPU has vector */
        if (vectorRegLow != NULL)
        {
            /* Check if CPU has 64-bit vector */
            if (vectorRegHigh != NULL)
            {
                /* Get 64-bit vector */
                *vector = (((uint64_t) *vectorRegHigh) << (32U + vectorShift))
                    | (((uint64_t) *vectorRegLow) << vectorShift);
            }
            else
            {
                /* Get 32-bit vector */
                *vector = ((uint64_t) *vectorRegLow) << vectorShift;
            }

            rc = true;
        }
    }

    return rc;
}

#else

#endif
