/*
 * Copyright 2024 NXP
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

/* Local Functions */
static void SRC_MemSetLpMode(uint32_t srcMixIdx, bool enableLpMode);
static void SRC_MixSetA55HdskMode(uint32_t srcMixIdx, uint8_t hdskMode);
static void SRC_MixSetA55CpuWait(uint32_t srcMixIdx, bool enableCpuWait);
static void SRC_MixSetCpuWait(uint32_t srcMixIdx, bool enableCpuWait);
static void SRC_MixSetCpuSleepMode(uint32_t srcMixIdx,uint32_t sleepMode);
static bool SRC_MixPowerDownCompleted(uint32_t srcMixIdx);
static bool SRC_MixPowerUpCompleted(uint32_t srcMixIdx);
static bool SRC_MixPowerDownPoll(uint32_t srcMixIdx, uint32_t timeoutUsec);
static bool SRC_MixRstExitPoll(uint32_t srcMixIdx, uint32_t timeoutUsec);

/* Local Variables */
static src_mix_slice_t *const s_srcMixPtrs[] = SRC_MIX_BASE_PTRS;

/*--------------------------------------------------------------------------*/
/* Initialize SRC MIX LPM configuration and ISOs                            */
/*--------------------------------------------------------------------------*/
bool SRC_MixInit(uint32_t srcMixIdx)
{
    bool rc = false;

    if (srcMixIdx < PWR_NUM_MIX_SLICE)
    {
        src_mix_slice_t *srcMix = s_srcMixPtrs[srcMixIdx];
        uint32_t authenCtrl = g_pwrMixMgmtInfo[srcMixIdx].authenCtrl;
        uint64_t lpmSetting = g_pwrMixMgmtInfo[srcMixIdx].lpmSetting;

        srcMix->AUTHEN_CTRL = authenCtrl;
        srcMix->LPM_SETTING_1 = UINT64_L(lpmSetting);
        srcMix->LPM_SETTING_2 = UINT64_H(lpmSetting);

        /* Clear MIX IP-level ISOs */
        uint32_t ipIsoMask = g_pwrMixMgmtInfo[srcMixIdx].ipIsoMask;
        if (ipIsoMask != 0U)
        {
            srcMix->SLICE_SW_CTRL &= (~ipIsoMask);
        }

        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Configure SRC MIX LPM mode (SW vs HW/GPC control)                        */
/*--------------------------------------------------------------------------*/
bool SRC_MixLpmModeSet(uint32_t srcMixIdx, bool gpcLpmCtrl)
{
    bool rc = false;

    if (srcMixIdx < PWR_NUM_MIX_SLICE)
    {
        src_mix_slice_t *srcMix = s_srcMixPtrs[srcMixIdx];

        uint32_t authenCtrl = srcMix->AUTHEN_CTRL;

        if (gpcLpmCtrl)
        {
            authenCtrl |= AUTHEN_CTRL_LPM_MODE_MASK;
        }
        else
        {
            authenCtrl &= ~AUTHEN_CTRL_LPM_MODE_MASK;
        }

        srcMix->AUTHEN_CTRL = authenCtrl;

        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Configure CPU LPM response for specified power domain                    */
/*--------------------------------------------------------------------------*/
bool SRC_MixCpuLpmSet(uint32_t srcMixIdx, uint32_t cpuIdx,
    uint32_t cpuLpmSetting)
{
    bool rc = false;

    if (srcMixIdx < PWR_NUM_MIX_SLICE)
    {
        if ((g_pwrMixMgmtInfo[srcMixIdx].flags & PWR_MIX_FLAG_LPMSET) != 0U)
        {
            src_mix_slice_t *srcMix = s_srcMixPtrs[srcMixIdx];

            uint64_t lpmSetting = ((((uint64_t) srcMix->LPM_SETTING_2) << 32U)
                | ((uint64_t) srcMix->LPM_SETTING_1));

            /* Insert new LPM_SETTING for this CPU */
            lpmSetting &= (~(LPMSETTING_MASK(cpuIdx)));
            lpmSetting |= LPMSETTING_DOM(cpuIdx, cpuLpmSetting);

            srcMix->LPM_SETTING_1 = UINT64_L(lpmSetting);
            srcMix->LPM_SETTING_2 = UINT64_H(lpmSetting);

            rc = true;
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Configure CPU LPM response for specified power domain                    */
/*--------------------------------------------------------------------------*/
bool SRC_MixCpuLpmGet(uint32_t srcMixIdx, uint32_t cpuIdx,
    uint32_t *cpuLpmSetting)
{
    bool rc = false;

    if (srcMixIdx < PWR_NUM_MIX_SLICE)
    {
        const src_mix_slice_t *srcMix = s_srcMixPtrs[srcMixIdx];

        uint64_t lpmSetting = ((((uint64_t) srcMix->LPM_SETTING_2) << 32U) |
            ((uint64_t) srcMix->LPM_SETTING_1));


        /* Extract LPM_SETTING for this CPU */
        *cpuLpmSetting = (uint32_t) (LPMSETTING_VAL(cpuIdx, lpmSetting)
            & 0xFFFFFFFFU);

        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Configure low-power mode of MEM slice                                    */
/*--------------------------------------------------------------------------*/
static void SRC_MemSetLpMode(uint32_t srcMixIdx, bool enableLpMode)
{
#if 0
    static src_mem_slice_t *const s_srcMemPtrs[] = SRC_MEM_BASE_PTRS;

    if (srcMixIdx < PWR_NUM_MIX_SLICE)
    {
        uint32_t memMask = g_pwrMixMgmtInfo[srcMixIdx].memMask;

        /* Loop over memory slices in mix */
        while (memMask != 0U)
        {
            /* Convert mask into index */
            uint8_t memIdx = 31U - __CLZ(memMask);

            src_mem_slice_t *srcMem = s_srcMemPtrs[memIdx];
            if (enableLpMode)
            {
                srcMem->MEM_CTRL |= SRC_MEM_MEM_CTRL_MEM_LP_EN_MASK;
            }
            else
            {
                srcMem->MEM_CTRL &= (~SRC_MEM_MEM_CTRL_MEM_LP_EN_MASK);
            }

            /* Clear memory mask bit to mark done */
            memMask &= (~(1UL << (memIdx)));
        }
    }
#else
#endif
}

/*--------------------------------------------------------------------------*/
/* Configure retention mode of MEM slice                                    */
/*--------------------------------------------------------------------------*/
bool SRC_MemRetentionModeSet(uint32_t srcMixIdx, uint32_t memRetMask)
{
    bool rc = false;
    static src_mem_slice_t *const s_srcMemPtrs[] = SRC_MEM_BASE_PTRS;

    if (srcMixIdx < PWR_NUM_MIX_SLICE)
    {
        uint32_t memMask = g_pwrMixMgmtInfo[srcMixIdx].memMask;

        /* Loop over memory slices  */
        while (memMask != 0U)
        {
            /* Convert mask into index */
            uint8_t memIdx = 31U - __CLZ(memMask);

            src_mem_slice_t *srcMem = s_srcMemPtrs[memIdx];
            if ((memRetMask & (1UL << memIdx)) != 0U)
            {
                srcMem->MEM_CTRL |= SRC_MEM_MEM_CTRL_MEM_LP_MODE_MASK;
            }
            else
            {
                srcMem->MEM_CTRL &= (~SRC_MEM_MEM_CTRL_MEM_LP_MODE_MASK);
            }

            /* Clear memory mask bit to mark done */
            memMask &= (~(1UL << (memIdx)));
        }
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get mask reflecting memory instances within this power domain            */
/*--------------------------------------------------------------------------*/
bool SRC_MemMaskGet(uint32_t srcMixIdx, uint32_t *retMask)
{
    bool rc = false;

    if (srcMixIdx < PWR_NUM_MIX_SLICE)
    {
        *retMask = g_pwrMixMgmtInfo[srcMixIdx].memMask;
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Configure A55 handshake mode of MIX slice                                */
/*--------------------------------------------------------------------------*/
static void SRC_MixSetA55HdskMode(uint32_t srcMixIdx, uint8_t hdskMode)
{

    if ((srcMixIdx == PWR_MIX_SLICE_IDX_A55P) ||
        ((srcMixIdx >= PWR_MIX_SLICE_IDX_A55C0) &&
        (srcMixIdx <= PWR_MIX_SLICE_IDX_A55C_LAST)))
    {
        src_mix_slice_t *srcMix = s_srcMixPtrs[srcMixIdx];

        /* Configure A55 handshake */
        uint32_t hwReg = srcMix->A55_HDSK_ACK_CTRL;
        hwReg &= ~A55_HDSK_ACK_CTRL_CNT_MODE_MASK;
        hwReg |= A55_HDSK_ACK_CTRL_CNT_MODE(hdskMode);
        srcMix->A55_HDSK_ACK_CTRL = hwReg;
    }
}

/*--------------------------------------------------------------------------*/
/* Configure A55 CPUWAIT signals of a MIX slice                             */
/*--------------------------------------------------------------------------*/
static void SRC_MixSetA55CpuWait(uint32_t srcMixIdx, bool enableCpuWait)
{
    if ((srcMixIdx == PWR_MIX_SLICE_IDX_A55P) ||
        ((srcMixIdx >= PWR_MIX_SLICE_IDX_A55C0) &&
        (srcMixIdx <= PWR_MIX_SLICE_IDX_A55C_LAST)))
    {
        SRC_MixSetCpuWait(srcMixIdx, enableCpuWait);
    }
}

/*--------------------------------------------------------------------------*/
/* Configure CPUWAIT signal of CPUs in MIX                                  */
/*--------------------------------------------------------------------------*/
static void SRC_MixSetCpuWait(uint32_t srcMixIdx, bool enableCpuWait)
{
    if (srcMixIdx < PWR_NUM_MIX_SLICE)
    {
        uint32_t cpuMask = g_pwrMixMgmtInfo[srcMixIdx].cpuMask;

        /* Loop over CPUs in MIX */
        while (cpuMask != 0U)
        {
            /* Convert mask into index */
            uint8_t cpuIdx = 31U - __CLZ(cpuMask);

            (void) CPU_WaitSet(cpuIdx, enableCpuWait);

            /* Clear CPU mask bit to mark done */
            cpuMask &= (~(1UL << (cpuIdx)));
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Configure sleep mode of CPUs in MIX                                      */
/*--------------------------------------------------------------------------*/
static void SRC_MixSetCpuSleepMode(uint32_t srcMixIdx, uint32_t sleepMode)
{
    if (srcMixIdx < PWR_NUM_MIX_SLICE)
    {
        uint32_t cpuMask = g_pwrMixMgmtInfo[srcMixIdx].cpuMask;

        /* Loop over CPUs in MIX */
        while (cpuMask != 0U)
        {
            /* Convert mask into index */
            uint8_t cpuIdx = 31U - __CLZ(cpuMask);

            (void) CPU_SleepModeSet(cpuIdx, sleepMode);

            /* Clear CPU mask bit to mark done */
            cpuMask &= (~(1UL << (cpuIdx)));
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Check if MIX power up sequence is complete.                              */
/*--------------------------------------------------------------------------*/
static bool SRC_MixPowerDownCompleted(uint32_t srcMixIdx)
{
    bool rc = false;

    if (srcMixIdx < PWR_NUM_MIX_SLICE)
    {
        uint32_t statMask;
        uint32_t statVal;
        if ((g_pwrMixMgmtInfo[srcMixIdx].flags & PWR_MIX_FLAG_SWITCHABLE) != 0U)
        {
            statMask = PWR_MIX_FUNC_STAT_MASK;
            statVal = PWR_MIX_FUNC_STAT_PDN;
        }
        else
        {
            statMask = PWR_MIX_PSW_STAT_MASK;
            statVal = PWR_MIX_PSW_STAT_PDN;
        }

        const src_mix_slice_t *srcMix = s_srcMixPtrs[srcMixIdx];

        if ((srcMix->FUNC_STAT & statMask) == statVal)
        {
            rc = true;
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Check if MIX power down sequence is complete.                            */
/*--------------------------------------------------------------------------*/
static bool SRC_MixPowerUpCompleted(uint32_t srcMixIdx)
{
    bool rc = false;

    if (srcMixIdx < PWR_NUM_MIX_SLICE)
    {
        uint32_t statMask;
        uint32_t statVal;
        if ((g_pwrMixMgmtInfo[srcMixIdx].flags & PWR_MIX_FLAG_SWITCHABLE) != 0U)
        {
            statMask = PWR_MIX_FUNC_STAT_MASK;
            statVal = PWR_MIX_FUNC_STAT_PUP;
        }
        else
        {
            statMask = PWR_MIX_PSW_STAT_MASK;
            statVal = PWR_MIX_PSW_STAT_PUP;
        }

        const src_mix_slice_t *srcMix = s_srcMixPtrs[srcMixIdx];

        if ((srcMix->FUNC_STAT & statMask) == statVal)
        {
            rc = true;
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Poll until MIX slice powered down completed or timeout reached           */
/*--------------------------------------------------------------------------*/
static bool SRC_MixPowerDownPoll(uint32_t srcMixIdx, uint32_t timeoutUsec)
{
    bool rc = false;

    if (srcMixIdx < PWR_NUM_MIX_SLICE)
    {
        uint32_t pollUsec = 0U;

        rc = SRC_MixPowerDownCompleted(srcMixIdx);

        /* Poll until MIX power down complete or timeout reached */
        while ((!rc) && (pollUsec < timeoutUsec))
        {
            SystemTimeDelay(1U);
            ++pollUsec;
            rc = SRC_MixPowerDownCompleted(srcMixIdx);
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Poll until MIX slice has exited the reset phase or timeout reached       */
/*--------------------------------------------------------------------------*/
static bool SRC_MixRstExitPoll(uint32_t srcMixIdx, uint32_t timeoutUsec)
{
    bool rc = false;

    if (srcMixIdx < PWR_NUM_MIX_SLICE)
    {
        const src_mix_slice_t *srcMix = s_srcMixPtrs[srcMixIdx];
        uint32_t pollUsec = 0U;

        rc = ((srcMix->FSM_STAT & SRC_XSPR_FSM_STAT_RST_STAT_MASK) ==
            (0x9U << SRC_XSPR_FSM_STAT_RST_STAT_SHIFT));

        /* Block until MIX reset phase has exited or timeout reached */
        while ((!rc) && (pollUsec < timeoutUsec))
        {
            SystemTimeDelay(1U);
            ++pollUsec;
            rc = ((srcMix->FSM_STAT & SRC_XSPR_FSM_STAT_RST_STAT_MASK) ==
                (0x9U << SRC_XSPR_FSM_STAT_RST_STAT_SHIFT));
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Software-controlled power down of MIX slice                              */
/*--------------------------------------------------------------------------*/
void SRC_MixSoftPowerDown(uint32_t srcMixIdx)
{
    if (srcMixIdx < PWR_NUM_MIX_SLICE)
    {
        src_mix_slice_t *srcMix = s_srcMixPtrs[srcMixIdx];

        /* Inhibit GPC LP handshake */
        PWR_LpHandshakeMaskSet(srcMixIdx, false);

        /* Switch to software-based power control */
        (void) SRC_MixLpmModeSet(srcMixIdx, false);

        /* MIXes with GPC CMC must have target sleep mode = RUN
         * to complete soft power down
         */
        (void) SRC_MixSetCpuSleepMode(srcMixIdx, CPU_SLEEP_MODE_RUN);

        /* Check if already OFF */
        if (0U == (srcMix->FUNC_STAT & FUNC_STAT_PSW_STAT_MASK))
        {
            /* Enable low-power memory control */
            SRC_MemSetLpMode(srcMixIdx, true);

            /* A55 must have CPUWAIT released to complete power down handshake.
             * Skipping this step will cause power down handshake to complete
             * (A55_HDSK_STAT bit set) on next power up.
             */
            SRC_MixSetA55CpuWait(srcMixIdx, false);

            /* A55 core will deny Q-channel request for power down if not idle.
             * Ignore A55 handshake since we are forcibly taking down the MIX.
             */
            SRC_MixSetA55HdskMode(srcMixIdx, SRC_MIX_A55_HDSK_ACK_IGNORE);

            /* Request software-controlled power down */
            srcMix->SLICE_SW_CTRL |= SLICE_SW_CTRL_PDN_SOFT_MASK;

            /* Wait for power down sequence to compete */
            if ((g_pwrMixMgmtInfo[srcMixIdx].flags & PWR_MIX_FLAG_SSI_TIMEOUT) == 0U)
            {
                while (!SRC_MixPowerDownCompleted(srcMixIdx))
                {
                    ; /* Intentional empty while */
                }
            }
            else
            {
                /* Poll MIX power down complete or timeout reached */
                if (!SRC_MixPowerDownPoll(srcMixIdx, 100U))
                {
                    /* Use LPCG handshake timeout to complete power down */
                    uint32_t lpcgIdx = g_pwrMixMgmtInfo[srcMixIdx].ssiLpcgIdx;
                    (void) CCM_LpcgTimeoutSetEnable(lpcgIdx, true);
                    (void) SRC_MixPowerDownPoll(srcMixIdx, 1U);
                    (void) CCM_LpcgTimeoutSetEnable(lpcgIdx, false);
                }
            }

            /* Restore A55 handshake */
            SRC_MixSetA55HdskMode(srcMixIdx, SRC_MIX_A55_HDSK_ACK_WAIT);

            /* Assert CPUWAIT to hold CPU for next power up */
            SRC_MixSetCpuWait(srcMixIdx, true);
        }

        /* Restore GPC LP handshake */
        PWR_LpHandshakeMaskSet(srcMixIdx, true);

        /* HW power control cannot be restored if forcibly powering down */
    }
}

/*--------------------------------------------------------------------------*/
/* Software-controlled power up of MIX slice                                */
/*--------------------------------------------------------------------------*/
bool SRC_MixSoftPowerUp(uint32_t srcMixIdx)
{
    bool trans = false;

    if (srcMixIdx < PWR_NUM_MIX_SLICE)
    {
        src_mix_slice_t *srcMix = s_srcMixPtrs[srcMixIdx];

        /* Inhibit GPC LP handshake */
        PWR_LpHandshakeMaskSet(srcMixIdx, false);

        /* Switch to software-based power control */
        (void) SRC_MixLpmModeSet(srcMixIdx, false);

        /* Check if already ON */
        if (0U != (srcMix->FUNC_STAT & FUNC_STAT_PSW_STAT_MASK))
        {
            /* Enable low-power memory control */
            SRC_MemSetLpMode(srcMixIdx, true);

            /* For MIXes that default to OFF, synchronize the software-controlled
             * OFF state which requires MEM_LP_EN by forcing a power off cycle.
             * MIXes that default to OFF can be detected by inspecting the
             * MEM_STAT field.
             */
            if (0U == (srcMix->FUNC_STAT & FUNC_STAT_MEM_STAT_MASK))
            {
                /* Ignore A55 since it is already powered down */
                SRC_MixSetA55HdskMode(srcMixIdx,
                    SRC_MIX_A55_HDSK_ACK_IGNORE);

                /* Request software-controlled power down */
                srcMix->SLICE_SW_CTRL |= SLICE_SW_CTRL_PDN_SOFT_MASK;

                /* Wait for power down sequence to compete */
                while (!SRC_MixPowerDownCompleted(srcMixIdx))
                {
                    ; /* Intentional empty while */
                }

                /* Restore A55 handshake */
                SRC_MixSetA55HdskMode(srcMixIdx, SRC_MIX_A55_HDSK_ACK_WAIT);
            }

            /* Request software-controlled power up */
            srcMix->SLICE_SW_CTRL &= ~SLICE_SW_CTRL_PDN_SOFT_MASK;

            /* Wait for power up sequence to complete */
            while (!SRC_MixPowerUpCompleted(srcMixIdx))
            {
                ; /* Intentional empty while */
            }

            /* Indicate a transition happened */
            trans = true;
        }

        /* Restore GPC LP handshake */
        PWR_LpHandshakeMaskSet(srcMixIdx, true);

        /* Restore HW/SW power control */
        if ((g_pwrMixMgmtInfo[srcMixIdx].authenCtrl &
            AUTHEN_CTRL_LPM_MODE_MASK) != 0U)
        {
            /* Switching from SW to HW control requires LPM_SETTING to
             * configured to a common value (not always on/off).  Restore
             * default LPM_SETTING to meet this requirement.
             */
            uint64_t lpmSetting = g_pwrMixMgmtInfo[srcMixIdx].lpmSetting;
            srcMix->LPM_SETTING_1 = UINT64_L(lpmSetting);
            srcMix->LPM_SETTING_2 = UINT64_H(lpmSetting);

            (void) SRC_MixLpmModeSet(srcMixIdx, true);
        }
    }

    return trans;
}

/*--------------------------------------------------------------------------*/
/* Check if MIX slice is powered                                            */
/*--------------------------------------------------------------------------*/
bool SRC_MixIsPwrSwitchOn(uint32_t srcMixIdx)
{
    bool isPwrSwitchOn = false;

    if (srcMixIdx < PWR_NUM_MIX_SLICE)
    {
        const src_mix_slice_t *srcMix = s_srcMixPtrs[srcMixIdx];

        if (0U == (srcMix->FUNC_STAT & FUNC_STAT_PSW_STAT_MASK))
        {
            isPwrSwitchOn = true;
        }
    }

    return isPwrSwitchOn;
}

/*--------------------------------------------------------------------------*/
/* Check if MIX slice is ready                                              */
/*--------------------------------------------------------------------------*/
bool SRC_MixIsPwrReady(uint32_t srcMixIdx)
{
    return SRC_MixPowerUpCompleted(srcMixIdx);
}

/*--------------------------------------------------------------------------*/
/* Block until MIX slice reset phase exits                                  */
/*--------------------------------------------------------------------------*/
bool SRC_MixRstExit(uint32_t srcMixIdx, uint32_t timeoutUsec)
{
    /* Poll until MIX has exited reset phase or timeout reached */
    bool rc = SRC_MixRstExitPoll(srcMixIdx, timeoutUsec);
    if (!rc)
    {
        if ((g_pwrMixMgmtInfo[srcMixIdx].flags & PWR_MIX_FLAG_SSI_TIMEOUT) != 0U)
        {
            /* Use LPCG handshake timeout to complete reset exit */
            uint32_t lpcgIdx = g_pwrMixMgmtInfo[srcMixIdx].ssiLpcgIdx;
            (void) CCM_LpcgTimeoutSetEnable(lpcgIdx, true);
            rc = SRC_MixRstExitPoll(srcMixIdx, 1U);
            (void) CCM_LpcgTimeoutSetEnable(lpcgIdx, false);
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Configure reset signal of MIX slice                                      */
/*--------------------------------------------------------------------------*/
bool SRC_MixSetResetLine(uint32_t lineIdx, uint32_t resetType)
{
    bool updateReset = false;

    if (lineIdx < RST_NUM_LINE)
    {
        uint32_t rstMask = g_rstLineInfo[lineIdx].lineMask;
        __IO uint32_t* const lineReg = g_rstLineInfo[lineIdx].lineReg;
        bool assertLow = g_rstLineInfo[lineIdx].assertLow;
        uint32_t hwReg = *lineReg;

        if ((resetType == RST_LINE_CTRL_ASSERT) ||
            (resetType == RST_LINE_CTRL_TOGGLE))
        {
            if (assertLow)
            {
                hwReg &= ~rstMask;
            }
            else
            {
                hwReg |= rstMask;
            }
        }
        else
        {
            if (assertLow)
            {
                hwReg |= rstMask;
            }
            else
            {
                hwReg &= ~rstMask;
            }
        }

        *lineReg = hwReg;

        if (resetType == RST_LINE_CTRL_TOGGLE)
        {
            /* Insert delay during reset toggle */
            SystemTimeDelay(g_rstLineInfo[lineIdx].toggleUsec);

            if (assertLow)
            {
                hwReg |= rstMask;
            }
            else
            {
                hwReg &= ~rstMask;
            }
            *lineReg = hwReg;
        }

        updateReset = true;
    }

    return updateReset;
}

/*--------------------------------------------------------------------------*/
/* Read reset signal of MIX slice                                           */
/*--------------------------------------------------------------------------*/
bool SRC_MixGetResetLine(uint32_t lineIdx, uint32_t *resetType)
{
    bool updateReset = false;

    if (lineIdx < RST_NUM_LINE)
    {
        uint32_t statMask = g_rstLineInfo[lineIdx].statMask;
        __IO const uint32_t* const statReg = g_rstLineInfo[lineIdx].statReg;
        bool assertLow = g_rstLineInfo[lineIdx].assertLow;
        uint32_t hwReg = *statReg;

        if ((hwReg & statMask) == 0U)
        {
            if (assertLow)
            {
                *resetType = RST_LINE_CTRL_ASSERT;
            }
            else
            {
                *resetType = RST_LINE_CTRL_DEASSERT;
            }

        }
        else
        {
            if (assertLow)
            {
                *resetType = RST_LINE_CTRL_DEASSERT;
            }
            else
            {
                *resetType = RST_LINE_CTRL_ASSERT;
            }
        }

        updateReset = true;
    }

    return updateReset;
}

/*--------------------------------------------------------------------------*/
/* Disable isolation for certain PHYs in MIXes                              */
/*--------------------------------------------------------------------------*/
#if 0
void SRC_MixIsolationSetup(uint32_t isoMask, bool enable)
{
    src_generic_t *src = (src_generic_t *)SRC_GEN_BASE;

    if (enable)
    {
        src->SP_ISO_CTRL |= isoMask;
    }
    else
    {
        src->SP_ISO_CTRL &= ~isoMask;
    }
}
#endif
#else

#endif
