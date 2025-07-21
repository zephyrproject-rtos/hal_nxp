/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* Includes */

#include "fsl_clock.h"
#include "fsl_ccm.h"
#include "fsl_device_registers.h"
#include "fsl_power.h"

/* Local Defines */

/* Local Types */

/* Local Functions */

/* Local Variables */

#ifdef CONFIG_DIRECT
/*--------------------------------------------------------------------------*/
/* Get CCM clock root enable status                                          */
/*--------------------------------------------------------------------------*/
bool CCM_RootGetEnable(uint32_t rootIdx)
{
    bool rootEnable = false;

    if (rootIdx < CLOCK_NUM_ROOT)
    {
        uint32_t rootCtrl
            = CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.RW;

        if ((rootCtrl & CCM_CLOCK_ROOT_OFF_MASK) == 0U)
        {
            rootEnable = true;
        }
    }

    return rootEnable;
}

/*--------------------------------------------------------------------------*/
/* Set CCM clock root enable status                                          */
/*--------------------------------------------------------------------------*/
bool CCM_RootSetEnable(uint32_t rootIdx, bool enable)
{
    bool updateEnable = false;

    if (rootIdx < CLOCK_NUM_ROOT)
    {
        if (enable)
        {
            CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.CLR
                = CCM_CLOCK_ROOT_OFF_MASK;
        }
        else
        {
            CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.SET
                = CCM_CLOCK_ROOT_OFF_MASK;
        }

        updateEnable = true;
    }

    return updateEnable;
}

/*--------------------------------------------------------------------------*/
/* Get CCM root source clock rate                                           */
/*--------------------------------------------------------------------------*/
static uint64_t CCM_RootGetSourceRate(uint32_t rootIdx)
{
    uint64_t rate = 0UL;

    if (rootIdx < CLOCK_NUM_ROOT)
    {
        uint32_t rootCtrl
            = CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.RW;
        uint32_t rootMux
            = (rootCtrl & CCM_CLOCK_ROOT_MUX_MASK)
            >> CCM_CLOCK_ROOT_MUX_SHIFT;
        uint32_t sourceIdx
            = g_clockRootMux[rootIdx][rootMux];

        rate = CLOCK_SourceGetRate(sourceIdx);
    }

    return rate;
}

/*--------------------------------------------------------------------------*/
/* Get CCM root clock rate                                                  */
/*--------------------------------------------------------------------------*/
uint64_t CCM_RootGetRate(uint32_t rootIdx)
{
    uint64_t rate = 0UL;

    if (rootIdx < CLOCK_NUM_ROOT)
    {
        rate = CCM_RootGetSourceRate(rootIdx);

        if (rate != 0U)
        {
            uint32_t rootCtrl
                = CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.RW;
            uint32_t rootDiv
                = (rootCtrl & CCM_CLOCK_ROOT_DIV_MASK)
                >> CCM_CLOCK_ROOT_DIV_SHIFT;

            rate = rate / (((uint64_t) rootDiv) + 1ULL);
        }
    }

    return rate;
}

/*--------------------------------------------------------------------------*/
/* Set CCM root clock rate                                                  */
/*--------------------------------------------------------------------------*/
bool CCM_RootSetRate(uint32_t rootIdx, uint64_t rate, uint32_t roundRule)
{
    bool updateRate = false;

    if ((rootIdx < CLOCK_NUM_ROOT) && (rate != 0U))
    {
        /* Get rate of source clock for root */
        uint64_t srcRate = CCM_RootGetSourceRate(rootIdx);

        /* Ensure integer divide rounds up to the nearest Hz */
        uint64_t newRate = rate + 1ULL;

        /* Calculate integer divider needed to achieve specified rate */
        uint64_t quotient = srcRate / newRate;

        /* Apply rounding rule */
        switch (roundRule)
        {
            case CLOCK_ROUND_RULE_CEILING:
                /* Ensure max root divider is not exceeded */
                if (quotient <= 255U)
                {
                    /* Apply ceiling by adding 1 to divider */
                    quotient += 1U;
                    updateRate = true;
                }
                break;

            case CLOCK_ROUND_RULE_FLOOR:
                /* Check for /0 */
                if (quotient >= 1U)
                {
                    /* Clamp to max root divider */
                    if (quotient > 256U)
                    {
                        quotient = 256U;
                    }
                    updateRate = true;
                }
                break;

            case CLOCK_ROUND_RULE_CLOSEST:
                /* If calculated divider is 0, closest is /1 */
                if (quotient == 0U)
                {
                    quotient = 1U;
                }
                /* Clamp to max root divider */
                else if (quotient >= 256U)
                {
                    quotient = 256U;
                }
                /* Otherwise, compare rates of closest dividers */
                else
                {
                    uint64_t floorRate = srcRate / quotient;
                    uint64_t ceilingRate = srcRate / (quotient + 1U);

                    uint64_t floorDelta = floorRate - newRate;
                    uint64_t ceilingDelta = newRate - ceilingRate;

                    if (ceilingDelta < floorDelta)
                    {
                        quotient += 1U;
                    }
                }
                updateRate = true;
                break;

            default:
                ; /* Intentional empty default */
                break;
        }

        if (updateRate)
        {
            uint32_t cr =
                CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.RW;
            cr &= (~(CCM_CLOCK_ROOT_DIV_MASK));
            cr |= CCM_CLOCK_ROOT_DIV(quotient - 1U);
            CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.RW = cr;
        }
    }

    return updateRate;
}

/*--------------------------------------------------------------------------*/
/* Get number of mux inputs for CCM root                                    */
/*--------------------------------------------------------------------------*/
bool CCM_RootMuxNumInputsGet(uint32_t rootIdx, uint32_t *numMuxInputs)
{
    bool rc = false;

    if (rootIdx < CLOCK_NUM_ROOT)
    {
        *numMuxInputs = CLOCK_NUM_ROOT_MUX_SEL;
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get specified mux input for CCM root                                     */
/*--------------------------------------------------------------------------*/
bool CCM_RootMuxInputGet(uint32_t rootIdx, uint32_t muxIdx,
    uint32_t *muxInput)
{
    bool rc = false;

    if ((rootIdx < CLOCK_NUM_ROOT) && (muxIdx < CLOCK_NUM_ROOT_MUX_SEL))
    {
        *muxInput = g_clockRootMux[rootIdx][muxIdx];
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CCM root parent                                                      */
/*--------------------------------------------------------------------------*/
bool CCM_RootGetParent(uint32_t rootIdx, uint32_t *sourceIdx)
{
    bool foundParent = false;

    if (rootIdx < CLOCK_NUM_ROOT)
    {
        /* Read mux state */
        uint32_t rootCtrl
            = CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.RW;
        uint32_t rootMux = (rootCtrl & CCM_CLOCK_ROOT_MUX_MASK)
            >> CCM_CLOCK_ROOT_MUX_SHIFT;

        /* Translate mux to source */
        *sourceIdx = g_clockRootMux[rootIdx][rootMux];
        foundParent = true;
    }

    return foundParent;
}

/*--------------------------------------------------------------------------*/
/* Set CCM root parent                                                      */
/*--------------------------------------------------------------------------*/
bool CCM_RootSetParent(uint32_t rootIdx, uint32_t sourceIdx)
{
    bool updateParent = false;

    if (rootIdx < CLOCK_NUM_ROOT)
    {
        uint32_t rootMux = 0U;

        /* Translate source to mux */
        while ((!updateParent) && (rootMux < CLOCK_NUM_ROOT_MUX_SEL))
        {
            if (sourceIdx == g_clockRootMux[rootIdx][rootMux])
            {
                updateParent = true;
            }
            else
            {
                rootMux++;
            }
        }

        /* Found in mux tables? */
        if (updateParent)
        {
            uint32_t cr =
                CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.RW;
            cr &= (~(CCM_CLOCK_ROOT_MUX_MASK));
            cr |= CCM_CLOCK_ROOT_MUX(rootMux);
            CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.RW = cr;
        }
    }

    return updateParent;
}

/*--------------------------------------------------------------------------*/
/* Get CCM root divider                                                     */
/*--------------------------------------------------------------------------*/
bool CCM_RootGetDiv(uint32_t rootIdx, uint32_t *divider)
{
    bool rc = false;

    if (rootIdx < CLOCK_NUM_ROOT)
    {
        *divider = ((CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.RW
            & CCM_CLOCK_ROOT_DIV_MASK) >> CCM_CLOCK_ROOT_DIV_SHIFT) + 1U;

        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CCM root divider                                                     */
/*--------------------------------------------------------------------------*/
bool CCM_RootSetDiv(uint32_t rootIdx, uint32_t divider)
{
    bool updateDiv = false;

    if ((rootIdx < CLOCK_NUM_ROOT) && (divider > 0U))
    {
        uint32_t cr = CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.RW;
        cr &= (~(CCM_CLOCK_ROOT_DIV_MASK));
        cr |= CCM_CLOCK_ROOT_DIV(divider - 1U);
        CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.RW = cr;

        updateDiv = true;
    }

    return updateDiv;
}

/*--------------------------------------------------------------------------*/
/* Get CCM GPR-selected clock enable status                                  */
/*--------------------------------------------------------------------------*/
bool CCM_GprSelGetEnable(uint32_t gprSelIdx)
{
    bool gprSelEnable = false;

    if (gprSelIdx < CLOCK_NUM_GPR_SEL)
    {
        /* Output of CCM GPR-selected mux is always enabled */
        gprSelEnable = true;
    }

    return gprSelEnable;
}

/*--------------------------------------------------------------------------*/
/* Get CCM GPR-selected rate for EXT clock                                  */
/*--------------------------------------------------------------------------*/
uint64_t CCM_GprSelExtGetRate(void)
{
    uint64_t rate = 0UL;

    const ccm_gpr_sel_attr_t *selAttr = &g_clockGprSel[CLOCK_GPR_SEL_EXT];

    uint32_t gpr = CCM_CTRL->GPR_SHARED[selAttr->selIdx].GPR_SHARED.RW;
    uint32_t muxSel = (gpr & selAttr->selMask) >> selAttr->selShift;

    /* CCM GPR0 selects mux options for EXT
     *  MUX0 = EXT1
     *  MUX1 = EXT2
     *  MUX2 = EXT3
     *  MUX3 = EXT4
     *
     *  EXT2/EXT3/EXT4 all tied to GND
     */

    if (muxSel == 0U)
    {
        rate = g_clockExt1Rate;
    }

    return rate;
}

/*--------------------------------------------------------------------------*/
/* Get CCM GPR-selected clock rate                                          */
/*--------------------------------------------------------------------------*/
uint64_t CCM_GprSelGetRate(uint32_t gprSelIdx)
{
    uint64_t rate = 0UL;

    if (gprSelIdx == CLOCK_GPR_SEL_EXT)
    {
        rate = CCM_GprSelExtGetRate();
    }
    else if (gprSelIdx < CLOCK_NUM_GPR_SEL)
    {
        const ccm_gpr_sel_attr_t *selAttr = &g_clockGprSel[gprSelIdx];

        uint32_t gpr = CCM_CTRL->GPR_SHARED[selAttr->selIdx].GPR_SHARED.RW;
        uint32_t muxSel = (gpr & selAttr->selMask) >> selAttr->selShift;
        uint32_t idx = selAttr->selMux[muxSel];

        if (idx < CLOCK_NUM_SRC)
        {
            rate = CLOCK_SourceGetRate(idx);
        }
        else
        {
            idx = idx - CLOCK_NUM_SRC;
            if (idx < CLOCK_NUM_ROOT)
            {
                rate = CCM_RootGetRate(idx);
            }
        }
    }
    else
    {
        ; /* Intentional empty else */
    }


    return rate;
}

/*--------------------------------------------------------------------------*/
/* Get number of mux inputs for GPR-selected clock                          */
/*--------------------------------------------------------------------------*/
bool CCM_GprSelMuxNumInputsGet(uint32_t gprSelIdx, uint32_t *numMuxInputs)
{
    bool rc = false;

    if (gprSelIdx < CLOCK_NUM_GPR_SEL)
    {
        *numMuxInputs = CLOCK_NUM_GPR_MUX_SEL;
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get specified mux input for for GPR-selected clock                       */
/*--------------------------------------------------------------------------*/
bool CCM_GprSelMuxInputGet(uint32_t gprSelIdx, uint32_t muxIdx,
    uint32_t *muxInput)
{
    bool rc = false;

    if ((gprSelIdx < CLOCK_NUM_GPR_SEL) && (muxIdx < CLOCK_NUM_GPR_MUX_SEL))
    {
        const ccm_gpr_sel_attr_t *selAttr = &g_clockGprSel[gprSelIdx];

        *muxInput = selAttr->selMux[muxIdx];

        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CCM GPR-selected clock parent                                        */
/*--------------------------------------------------------------------------*/
bool CCM_GprSelGetParent(uint32_t gprSelIdx, uint32_t *clkIdx)
{
    bool foundParent = false;

    if (gprSelIdx < CLOCK_NUM_GPR_SEL)
    {
        const ccm_gpr_sel_attr_t *selAttr = &g_clockGprSel[gprSelIdx];

        uint32_t gpr = CCM_CTRL->GPR_SHARED[selAttr->selIdx].GPR_SHARED.RW;
        uint32_t muxSel = (gpr & selAttr->selMask) >> selAttr->selShift;

        *clkIdx = selAttr->selMux[muxSel];

        foundParent = true;
    }

    return foundParent;
}

/*--------------------------------------------------------------------------*/
/* Set CCM GPR-selected parent                                              */
/*--------------------------------------------------------------------------*/
bool CCM_GprSelSetParent(uint32_t gprSelIdx, uint32_t clkIdx)
{
    bool updateParent = false;

    if (gprSelIdx < CLOCK_NUM_GPR_SEL)
    {
        uint32_t muxSel = 0U;

        const ccm_gpr_sel_attr_t *selAttr = &g_clockGprSel[gprSelIdx];

        /* Translate clock index into GPR select */
        while ((!updateParent) && (muxSel < CLOCK_NUM_GPR_MUX_SEL))
        {
            if (clkIdx == selAttr->selMux[muxSel])
            {
                updateParent = true;
            }
            else
            {
                muxSel++;
            }
        }

        /* Found in GPR-selected tables? */
        if (updateParent)
        {
            uint32_t gpr = CCM_CTRL->GPR_SHARED[selAttr->selIdx].GPR_SHARED.RW;
            gpr &= (~(selAttr->selMask));
            gpr |= ((muxSel << selAttr->selShift) & selAttr->selMask);
            CCM_CTRL->GPR_SHARED[selAttr->selIdx].GPR_SHARED.RW = gpr;
        }
    }

    return updateParent;
}

/*--------------------------------------------------------------------------*/
/* Set CCM GPR register                                                     */
/*--------------------------------------------------------------------------*/
bool CCM_GprValSet(uint32_t gprIdx, uint32_t gprMask, uint32_t gprVal)
{
    bool rc = false;

    if (gprIdx < CLOCK_NUM_GPR)
    {
        uint32_t gpr = CCM_CTRL->GPR_SHARED[gprIdx].GPR_SHARED.RW;
        gpr &= (~(gprMask));
        gpr |= gprVal;
        CCM_CTRL->GPR_SHARED[gprIdx].GPR_SHARED.RW = gpr;

        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CCM CGC enable status                                                */
/*--------------------------------------------------------------------------*/
bool CCM_CgcGetEnable(uint32_t cgcIdx)
{
    bool rc = false;

    if (cgcIdx < CLOCK_NUM_CGC)
    {
        uint32_t lpcgIdx = g_clockCgcAttr[cgcIdx].lpcgIdx;

        rc = CCM_LpcgDirectCtrlGetEnable(lpcgIdx);
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CCM CGC enable status                                                */
/*--------------------------------------------------------------------------*/
bool CCM_CgcSetEnable(uint32_t cgcIdx, bool enable)
{
    bool rc = false;

    if (cgcIdx < CLOCK_NUM_CGC)
    {
        uint32_t lpcgIdx = g_clockCgcAttr[cgcIdx].lpcgIdx;

        rc = CCM_LpcgDirectCtrlSetEnable(lpcgIdx, enable);
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CCM CGC rate                                                         */
/*--------------------------------------------------------------------------*/
uint64_t CCM_CgcGetRate(uint32_t cgcIdx)
{
    uint64_t rate = 0UL;

    if (cgcIdx < CLOCK_NUM_CGC)
    {
        uint32_t rootIdx = g_clockCgcAttr[cgcIdx].rootIdx;
        rate = CCM_RootGetRate(rootIdx);
    }

    return rate;
}

/*--------------------------------------------------------------------------*/
/* Get CCM CGC parent                                                       */
/*--------------------------------------------------------------------------*/
bool CCM_CgcGetParent(uint32_t cgcIdx, uint32_t *rootIdx)
{
    bool rc = false;

    if (cgcIdx < CLOCK_NUM_CGC)
    {
        *rootIdx = g_clockCgcAttr[cgcIdx].rootIdx;
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CCM LPCG direct control enable                                       */
/*--------------------------------------------------------------------------*/
bool CCM_LpcgDirectCtrlGetEnable(uint32_t lpcgIdx)
{
    bool rc = false;

    if (lpcgIdx < CCM_LPCG_LPM0_COUNT)
    {
        uint32_t lpcgDirect = CCM_CTRL->LPCG[lpcgIdx].DIRECT;

        if ((lpcgDirect & CCM_LPCG_DIRECT_ON_MASK) != 0U)
        {
            rc = true;
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CCM LPCG direct control enable                                       */
/*--------------------------------------------------------------------------*/
bool CCM_LpcgDirectCtrlSetEnable(uint32_t lpcgIdx, bool enable)
{
    bool rc = false;

    if (lpcgIdx < CCM_LPCG_LPM0_COUNT)
    {
        uint32_t lpcgDirect = CCM_CTRL->LPCG[lpcgIdx].DIRECT;

        if (enable)
        {
            lpcgDirect |= CCM_LPCG_DIRECT_ON_MASK;
        }
        else
        {
            lpcgDirect &= ~CCM_LPCG_DIRECT_ON_MASK;
        }

        CCM_CTRL->LPCG[lpcgIdx].DIRECT = lpcgDirect;

        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CCM LPCG low-power mode setting for specified CPU                    */
/*--------------------------------------------------------------------------*/
bool CCM_LpcgLpmSet(uint32_t lpcgIdx, uint32_t cpuIdx, uint32_t cpuLpmSetting)
{
    bool rc = false;

    if (lpcgIdx < CCM_LPCG_LPM0_COUNT)
    {
        uint64_t lpmSetting = ((((uint64_t) CCM_CTRL->LPCG[lpcgIdx].LPM1)
                << 32U) | ((uint64_t) CCM_CTRL->LPCG[lpcgIdx].LPM0));

        /* Insert new LPM_SETTING for this CPU */
        lpmSetting &= (~(LPMSETTING_MASK(cpuIdx)));
        lpmSetting |= LPMSETTING_DOM(cpuIdx, cpuLpmSetting);

        CCM_CTRL->LPCG[lpcgIdx].LPM0 = UINT64_L(lpmSetting);
        CCM_CTRL->LPCG[lpcgIdx].LPM1 = UINT64_H(lpmSetting);

        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CCM LPCG low-power mode setting for specified CPU                    */
/*--------------------------------------------------------------------------*/
bool CCM_LpcgLpmGet(uint32_t lpcgIdx, uint32_t cpuIdx, uint32_t *cpuLpmSetting)
{
    bool rc = false;

    if (lpcgIdx < CCM_LPCG_LPM0_COUNT)
    {
        uint64_t lpmSetting =
            ((((uint64_t) CCM_CTRL->LPCG[lpcgIdx].LPM1) << 32U) |
                ((uint64_t) CCM_CTRL->LPCG[lpcgIdx].LPM0));

        /* Extract LPM_SETTING for this CPU */
        *cpuLpmSetting = (uint32_t) (LPMSETTING_VAL(cpuIdx, lpmSetting)
            & 0xFFFFFFFFU);

        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CCM LPCG control mode(sw direct or cpu LPM)                          */
/*--------------------------------------------------------------------------*/
bool CCM_LpcgModeSet(uint32_t lpcgIdx, uint32_t lpcgMode)
{
    bool rc = false;

    if (lpcgIdx < CCM_LPCG_LPM0_COUNT)
    {
        uint32_t lpcgAuth = CCM_CTRL->LPCG[lpcgIdx].AUTHEN;

        if (lpcgMode == 0x1U)
        {
            lpcgAuth |= CCM_LPCG_AUTHEN_CPULPM_MODE_MASK;
        }
        else
        {
            lpcgAuth &= ~CCM_LPCG_AUTHEN_CPULPM_MODE_MASK;
        }

        CCM_CTRL->LPCG[lpcgIdx].AUTHEN = lpcgAuth;

        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CCM LPCG access control list                                         */
/*--------------------------------------------------------------------------*/
bool CCM_LpcgAccessSet(uint32_t lpcgIdx, uint32_t accessList)
{
    bool rc = false;

    if (lpcgIdx < CCM_LPCG_LPM0_COUNT)
    {
        uint32_t lpcgAuth = CCM_CTRL->LPCG[lpcgIdx].AUTHEN;

        lpcgAuth &= ~CCM_LPCG_AUTHEN_WHITE_LIST_MASK;
        lpcgAuth |= CCM_LPCG_AUTHEN_WHITE_LIST(accessList);

        CCM_CTRL->LPCG[lpcgIdx].AUTHEN = lpcgAuth;

        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CCM LPCG access control list                                         */
/*--------------------------------------------------------------------------*/
bool CCM_LpcgAccessGet(uint32_t lpcgIdx, uint32_t *accessList)
{
    bool rc = false;

    if (lpcgIdx < CCM_LPCG_LPM0_COUNT)
    {
        uint32_t lpcgAuth = CCM_CTRL->LPCG[lpcgIdx].AUTHEN;

        *accessList = (lpcgAuth & CCM_LPCG_AUTHEN_WHITE_LIST_MASK) >>
            CCM_LPCG_AUTHEN_WHITE_LIST_SHIFT;

        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CCM LPCG clock off handshake timeout enable                          */
/*--------------------------------------------------------------------------*/
bool CCM_LpcgTimeoutSetEnable(uint32_t lpcgIdx, bool enable)
{
    bool rc = false;

    if (lpcgIdx < CCM_LPCG_LPM0_COUNT)
    {
        uint32_t lpcgDirect = CCM_CTRL->LPCG[lpcgIdx].DIRECT;

        if (enable)
        {
            lpcgDirect |= CCM_LPCG_DIRECT_CLKOFF_ACK_TIMEOUT_EN_MASK;
        }
        else
        {
            lpcgDirect &= ~CCM_LPCG_DIRECT_CLKOFF_ACK_TIMEOUT_EN_MASK;
        }

        CCM_CTRL->LPCG[lpcgIdx].DIRECT = lpcgDirect;

        rc = true;
    }

    return rc;
}
#endif

