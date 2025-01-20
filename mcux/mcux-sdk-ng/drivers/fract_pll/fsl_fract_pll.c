/*
 * Copyright 2023 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Includes */

#include "fsl_clock.h"
#include "fsl_fract_pll.h"
#include "fsl_device_registers.h"

/* Local Defines */

/* Local Types */

/* Local Functions */

/* Local Variables */

static PLL_Type *const s_pllPtrs[] = PLL_BASE_PTRS;
static uint64_t s_vcoRates[CLOCK_NUM_PLL];
static bool s_vcoRateIsLatched[CLOCK_NUM_PLL];

/*--------------------------------------------------------------------------*/
/* Get PLL enable status                                                    */
/*--------------------------------------------------------------------------*/
bool FRACTPLL_GetEnable(uint32_t pllIdx, uint32_t enMask)
{
    bool pllEnable = false;

    if (pllIdx < CLOCK_NUM_PLL)
    {
        const PLL_Type *pll = s_pllPtrs[pllIdx];

        if ((pll->CTRL.RW & enMask) != 0U)
        {
            pllEnable = true;
        }
    }

    return pllEnable;
}

/*--------------------------------------------------------------------------*/
/* Set PLL enable status                                                    */
/*--------------------------------------------------------------------------*/
bool FRACTPLL_SetEnable(uint32_t pllIdx, uint32_t enMask, bool enable)
{
    bool enableUpdate = false;

    if (pllIdx < CLOCK_NUM_PLL)
    {
        PLL_Type *pll = s_pllPtrs[pllIdx];

        if (enable)
        {
#if (defined(FSL_FEATURE_FRAC_PLL_HAS_ERRATA_628654) && FSL_FEATURE_FRAC_PLL_HAS_ERRATA_628654)
            /* If fractional PLL, rewrite MFN (not retained during PLL disable) */
            if ((enMask == PLL_CTRL_POWERUP_MASK) && (g_pllAttrs[pllIdx].isFrac))
            {
                uint32_t pllNum = pll->NUMERATOR.RW;
                pll->NUMERATOR.RW = pllNum;
            }
#endif
            pll->CTRL.SET = enMask;
        }
        else
        {
            pll->CTRL.CLR = enMask;
        }

        enableUpdate = true;
    }

    return enableUpdate;
}

/*--------------------------------------------------------------------------*/
/* Get PLL clock rate                                                       */
/*--------------------------------------------------------------------------*/
uint64_t FRACTPLL_GetRate(uint32_t pllIdx, bool vcoOp)
{
    uint64_t rate = 0UL;

    if (pllIdx < CLOCK_NUM_PLL)
    {
        /* If latched VCO rate not yet applied, return latched rate */
        if (vcoOp && s_vcoRateIsLatched[pllIdx])
        {
            rate = s_vcoRates[pllIdx];
        }
        else
        {
            const PLL_Type *pll = s_pllPtrs[pllIdx];

            uint32_t pllDiv = pll->DIV.RW;
            uint32_t rdiv = (pllDiv & PLL_DIV_RDIV_MASK) >> PLL_DIV_RDIV_SHIFT;
            if (rdiv == 0U)
            {
                rdiv = 1U;
            }
            uint32_t mfi = (pllDiv & PLL_DIV_MFI_MASK) >> PLL_DIV_MFI_SHIFT;

            if (g_pllAttrs[pllIdx].isFrac)
            {
                uint32_t mfn = pll->NUMERATOR.RW;
                mfn = mfn / 4U;

                uint32_t mfd = pll->DENOMINATOR.RW;

                rate = (CLOCK_PLL_FREF_HZ * mfi) + ((CLOCK_PLL_FREF_HZ * mfn)
                    / mfd);
            }
            else
            {
                rate = (CLOCK_PLL_FREF_HZ * mfi);
            }

            if (vcoOp)
            {
                rate = rate / ((uint64_t) rdiv);
            }
            else
            {
                uint32_t odiv = (pllDiv & PLL_DIV_ODIV_MASK)
                    >> PLL_DIV_ODIV_SHIFT;
                if (odiv < 2U)
                {
                    odiv += 2U;
                }

                rate = rate / (((uint64_t) rdiv) * ((uint64_t) odiv));
            }
        }
    }

    return rate;
}

/*--------------------------------------------------------------------------*/
/* Update PLL clock rate                                                    */
/*--------------------------------------------------------------------------*/
bool FRACTPLL_UpdateRate(uint32_t pllIdx, uint32_t mfi, uint32_t mfn,
    uint32_t odiv)
{
    bool updateRate = false;

    if (pllIdx < CLOCK_NUM_PLL)
    {
        /* Clear out any previously latched rates */
        s_vcoRateIsLatched[pllIdx] = false;

        PLL_Type *pll = s_pllPtrs[pllIdx];

        /* Bypass PLL */
        pll->CTRL.SET = PLL_CTRL_CLKMUX_BYPASS_MASK;
        /* Disable output and PLL */
        pll->CTRL.CLR = PLL_CTRL_CLKMUX_EN_MASK | PLL_CTRL_POWERUP_MASK;
        /* Set rdiv, mfi, and odiv */
        pll->DIV.RW = PLL_DIV_MFI(mfi) | PLL_DIV_RDIV(0U)
            | PLL_DIV_ODIV(odiv);
        /* Disable spread spectrum modulation */
        pll->SPREAD_SPECTRUM.CLR = PLL_SPREAD_SPECTRUM_ENABLE_MASK;

        /* Check if MFN/MFD calculation and configuration needed */
        if (g_pllAttrs[pllIdx].isFrac)
        {
            /* Set mfn and mfd */
            pll->NUMERATOR.RW   = PLL_NUMERATOR_MFN(mfn);
            pll->DENOMINATOR.RW = PLL_DENOMINATOR_MFD(CLOCK_PLL_MFD);
        }

        /* Power up for locking */
        pll->CTRL.SET = PLL_CTRL_POWERUP_MASK;
        while ((pll->PLL_STATUS & PLL_PLL_STATUS_PLL_LOCK_MASK) == 0U)
        {
            ; /* Intentional empty default */
        }

        /* Enable PLL and clean bypass*/
        pll->CTRL.SET = PLL_CTRL_CLKMUX_EN_MASK;
        pll->CTRL.CLR = PLL_CTRL_CLKMUX_BYPASS_MASK;

        updateRate = true;
    }

    return updateRate;
}

/*--------------------------------------------------------------------------*/
/* Set PLL clock rate                                                       */
/*--------------------------------------------------------------------------*/
bool FRACTPLL_SetRate(uint32_t pllIdx, bool vcoOp, uint64_t rate)
{
    bool updateRate = false;

    if ((pllIdx < CLOCK_NUM_PLL) && (rate != 0U))
    {
        bool relockPll = false;
        uint64_t vcoRate = 0U;

        if (vcoOp)
        {
            if ((rate >= ES_MIN_HZ_PLLVCO) &&
                (rate <= ES_MAX_HZ_PLLVCO))
            {
                /* For PLLs with DFS outputs, relock PLL */
                if (g_pllAttrs[pllIdx].numDFS > 0U)
                {
                    vcoRate = rate;
                    relockPll = true;
                }
                /* For PLL without DFS outputs, defer PLL relock */
                else
                {
                    s_vcoRates[pllIdx] = rate;
                    s_vcoRateIsLatched[pllIdx] = true;
                    updateRate = true;
                }
            }
        }
        else
        {
            relockPll = true;
            vcoRate = s_vcoRates[pllIdx];
            s_vcoRateIsLatched[pllIdx] = false;
        }

        if (relockPll)
        {
            uint32_t odiv = 0U;

            /* Calculate integer divider needed to achieve specified rate */
            uint64_t quotient = vcoRate / rate;
            uint64_t remain = vcoRate % rate;

            /* ODIV min is /2 */
            if (quotient < 2U)
            {
                odiv = 2U;
            }
            /* ODIV max is /255 */
            else if (quotient >= 255U)
            {
                odiv = 255U;
            }
            else
            {
                /* Check for integer divide */
                if (remain == 0U)
                {
                    odiv = (uint32_t) quotient;
                }
                /* Else round down */
                else
                {
                    odiv = (uint32_t) (quotient + 1ULL);
                }
            }

            /* Calculate MFI */
            uint32_t mfi = (uint32_t) (vcoRate / CLOCK_PLL_FREF_HZ);

            /* MFN/MFD calculation only needed for fractional PLLs */
            uint32_t mfn = 0U;
            if (g_pllAttrs[pllIdx].isFrac)
            {
                /* Calculate MFN */
                mfn = (uint32_t) ((vcoRate - (mfi * CLOCK_PLL_FREF_HZ))
                    / ((uint64_t) CLOCK_PLL_CALC_ACCURACY_HZ));
            }

            updateRate = FRACTPLL_UpdateRate(pllIdx, mfi, mfn, odiv);
        }
    }

    return updateRate;
}

/*--------------------------------------------------------------------------*/
/* Get DFS enable status                                                    */
/*--------------------------------------------------------------------------*/
bool FRACTPLL_GetDfsEnable(uint32_t pllIdx, uint8_t dfsIdx,
    uint32_t enMask)
{
    bool dfsEnable = false;

    if (pllIdx < CLOCK_NUM_PLL)
    {
        if (dfsIdx < g_pllAttrs[pllIdx].numDFS)
        {
            const PLL_Type *pll = s_pllPtrs[pllIdx];

            if ((pll->DFS[dfsIdx].DFS_CTRL.RW & enMask) != 0U)
            {
                dfsEnable = true;
            }
        }
    }

    return dfsEnable;
}

/*--------------------------------------------------------------------------*/
/* Set DFS enable status                                                    */
/*--------------------------------------------------------------------------*/
bool FRACTPLL_SetDfsEnable(uint32_t pllIdx, uint8_t dfsIdx,
    uint32_t enMask, bool enable)
{
    bool updateEnable = false;

    if (pllIdx < CLOCK_NUM_PLL)
    {
        if (dfsIdx < g_pllAttrs[pllIdx].numDFS)
        {
            PLL_Type *pll = s_pllPtrs[pllIdx];

            if (enable)
            {
                pll->DFS[dfsIdx].DFS_CTRL.SET = enMask;
            }
            else
            {
                pll->DFS[dfsIdx].DFS_CTRL.CLR = enMask;
            }

            updateEnable = true;
        }
    }

    return updateEnable;
}

/*--------------------------------------------------------------------------*/
/* Get PLL DFS rate                                                         */
/*--------------------------------------------------------------------------*/
uint64_t FRACTPLL_GetDfsRate(uint32_t pllIdx, uint8_t dfsIdx,
    bool div2)
{
    uint64_t rate = 0UL;

    if (pllIdx < CLOCK_NUM_PLL)
    {
        if (dfsIdx < g_pllAttrs[pllIdx].numDFS)
        {
            const PLL_Type *pll = s_pllPtrs[pllIdx];

            uint32_t divider = pll->DFS[dfsIdx].DFS_DIV.RW;

            uint32_t mfi = (divider & PLL_DFS_MFI_MASK)
                >> PLL_DFS_MFI_SHIFT;
            uint32_t mfn = (divider & PLL_DFS_MFN_MASK)
                >> PLL_DFS_MFN_SHIFT;

            rate = FRACTPLL_GetRate(pllIdx, true);

            rate = (rate * 5U) / ((mfi * 5U) + mfn);

            if (div2)
            {
                rate = rate >> 1U;
            }
        }
    }

    return rate;
}

/*--------------------------------------------------------------------------*/
/* Update PLL DFS rate                                                      */
/*--------------------------------------------------------------------------*/
bool FRACTPLL_UpdateDfsRate(uint32_t pllIdx, uint8_t dfsIdx, uint32_t mfi,
    uint32_t mfn)
{
    bool updateRate = false;

    if (pllIdx < CLOCK_NUM_PLL)
    {
        if (dfsIdx < g_pllAttrs[pllIdx].numDFS)
        {
            PLL_Type *pll = s_pllPtrs[pllIdx];

            /* Bypass DFS*/
            pll->DFS[dfsIdx].DFS_CTRL.SET
                = PLL_DFS_BYPASS_EN_MASK;
            /* Disable output and DFS */
            pll->DFS[dfsIdx].DFS_CTRL.CLR
                = PLL_DFS_CLKOUT_EN_MASK
                | PLL_DFS_ENABLE_MASK;
            /* Set mfi and mfn */
            pll->DFS[dfsIdx].DFS_DIV.RW = PLL_DFS_MFI(mfi)
                | PLL_DFS_MFN(mfn);
            /* Enable output and DFS*/
            pll->DFS[dfsIdx].DFS_CTRL.SET
                = PLL_DFS_CLKOUT_EN_MASK;

            /* Enable DFS for locking*/
            pll->DFS[dfsIdx].DFS_CTRL.SET
                = PLL_DFS_ENABLE_MASK;

            /* Wait for DFS clock output to be valid */
            uint32_t dfsOkMask = 1UL << dfsIdx;
            while ((pll->DFS_STATUS & dfsOkMask) == 0U)
            {
                ; /* Intentional empty while */
            }

            /* Clean bypass */
            pll->DFS[dfsIdx].DFS_CTRL.CLR
                = PLL_DFS_BYPASS_EN_MASK;
            __DSB();
            __ISB();

            updateRate = true;
        }
    }

    return updateRate;
}

/*--------------------------------------------------------------------------*/
/* Set PLL DFS rate                                                         */
/*--------------------------------------------------------------------------*/
bool FRACTPLL_SetDfsRate(uint32_t pllIdx, uint8_t dfsIdx,
    uint64_t rate)
{
    bool updateRate = false;

    if ((pllIdx < CLOCK_NUM_PLL) && (rate != 0U))
    {
        if (dfsIdx < g_pllAttrs[pllIdx].numDFS)
        {
            uint64_t vcoRate = FRACTPLL_GetRate(pllIdx, true);

            /* DFS rate = vcoRate / (mfi + (mfn / 5))
             *
             * Integer part:
             * mfi = vcoRate / rate
             *
             * Fraction part:
             * rate * (mfi + (mfn / 5)) = vcoRate
             * (rate * mfi) + (rate * (mfn / 5)) = vcoRate
             * (rate * (mfn / 5)) = vcoRate - (rate * mfi)
             * (mfn / 5) = (vcoRate - (rate * mfi)) / rate
             * mfn = ((vcoRate * 5) - (rate * mfi * 5)) / rate
             *
             */

            /* Calculate MFI */
            uint32_t mfi = (uint32_t) ((uint64_t) (vcoRate / rate));

            /* Calculate MFN */
            uint64_t num = (vcoRate * 5UL) - (((uint64_t) mfi) * rate * 5UL);
            uint64_t quotient = num / rate;
            uint64_t remain = num % rate;

            uint32_t mfn = ((uint32_t) quotient);

            /* Round up MFN to avoid overclocking */
            if  ((remain != 0U) && (quotient < 5U))
            {
                mfn++;
            }

            /* If MFN is 5U, bump MFI and zero out MFN */
            if (mfn == 5U)
            {
                mfn = 0U;
                mfi++;
            }

            /* Clamp MFI and MFN */
            if (mfi < 2U)
            {
                mfi = 2U;
                mfn = 0U;
            }
            if (mfi > 255U)
            {
                mfi = 255U;
                mfn = 4U;
            }

            updateRate = FRACTPLL_UpdateDfsRate(pllIdx, dfsIdx, mfi, mfn);
        }
    }

    return updateRate;
}

