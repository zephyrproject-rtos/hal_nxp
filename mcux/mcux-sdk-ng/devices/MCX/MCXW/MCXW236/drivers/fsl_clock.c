/*
 * Copyright 2017-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_common.h"
#include "fsl_clock.h"
#include "fsl_power.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.clock"
#endif

/** External clock rate on the CLKIN pin in Hz. If not used,
    set this to 0. Otherwise, set it to the exact rate in Hz this pin is
    being driven at. */
static uint32_t s_Ext_Clk_Freq = 32000000U;
static uint32_t s_PLU_ClkIn_Freq = 0U;

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/* Clock Selection for IP */
/**
 * brief   Configure the clock selection muxes.
 * param   connection  : Clock to be configured.
 * return  Nothing
 */
void CLOCK_AttachClk(clock_attach_id_t connection)
{
    uint8_t mux;
    uint8_t sel;
    uint16_t item;
    uint32_t i;
    volatile uint32_t *pClkSel;

    pClkSel = &(SYSCON->SYSTICKCLKSELX[0]);

    if (connection != kNONE_to_NONE)
    {
        for (i = 0U; i < 2U; i++)
        {
            if (connection == 0U)
            {
                break;
            }
            item = (uint16_t)GET_ID_ITEM(connection);
            if (item)
            {
                mux = GET_ID_ITEM_MUX(item);
                sel = GET_ID_ITEM_SEL(item);
                if (mux == CM_RTCOSC32KCLKSEL)
                {
                    PMC->RTCOSC32K |= sel;
                }
                else
                {
                    pClkSel[mux] = sel;
                }
            }
            connection = GET_ID_NEXT_ITEM(connection); /* pick up next descriptor */
        }
    }
}

/* Return the actual clock attach id */
/**
 * brief   Get the actual clock attach id.
 * This fuction uses the offset in input attach id, then it reads the actual source value in
 * the register and combine the offset to obtain an actual attach id.
 * param   attachId  : Clock attach id to get.
 * return  Clock source value.
 */
clock_attach_id_t CLOCK_GetClockAttachId(clock_attach_id_t attachId)
{
    uint8_t mux;
    uint8_t actualSel;
    uint32_t i;
    uint32_t actualAttachId = 0U;
    uint32_t selector       = GET_ID_SELECTOR(attachId);
    volatile uint32_t *pClkSel;

    pClkSel = &(SYSCON->SYSTICKCLKSELX[0]);

    if (attachId == kNONE_to_NONE)
    {
        return kNONE_to_NONE;
    }

    for (i = 0U; i < 2U; i++)
    {
        mux = GET_ID_ITEM_MUX(attachId);
        if (attachId)
        {
            if (mux == CM_RTCOSC32KCLKSEL)
            {
                actualSel = PMC->RTCOSC32K;
            }
            else
            {
                actualSel = pClkSel[mux];
            }

            /* Consider the combination of two registers */
            actualAttachId |= CLK_ATTACH_ID(mux, actualSel, i);
        }
        attachId = GET_ID_NEXT_ITEM(attachId); /* pick up next descriptor */
    }

    actualAttachId |= selector;

    return (clock_attach_id_t)actualAttachId;
}

/* Set IP Clock Divider */
/**
 * brief   Setup peripheral clock dividers.
 * param   div_name    : Clock divider name
 * param divided_by_value: Value to be divided
 * param reset :  Whether to reset the divider counter.
 * return  Nothing
 */
void CLOCK_SetClkDiv(clock_div_name_t div_name, uint32_t divided_by_value, bool reset)
{
    volatile uint32_t *pClkDiv;

    if (div_name > kCLOCK_DivMax)
    {
        return;
    }

    pClkDiv = &(SYSCON->SYSTICKCLKDIV0);
    if (reset)
    {
        pClkDiv[div_name] = 1U << 29U;
    }
    if (divided_by_value == 0U) /* halt */
    {
        pClkDiv[div_name] = 1U << 30U;
    }
    else
    {
        pClkDiv[div_name] = (divided_by_value - 1U);
    }

    __ISB();
    __DSB();
}

/* Set RTC 1KHz Clock Divider */
/**
 * brief   Setup rtc 1khz clock divider.
 * param divided_by_value: Value to be divided
 * return  Nothing
 */
void CLOCK_SetRtc1khzClkDiv(uint32_t divided_by_value)
{
    uint32_t rtcOsk32K = PMC->RTCOSC32K & ~(PMC_RTCOSC32K_CLK1KHZDIV_MASK);
    PMC->RTCOSC32K     = rtcOsk32K | ((divided_by_value - 28U) << PMC_RTCOSC32K_CLK1KHZDIV_SHIFT);
}

/* Set RTC 1KHz Clock Divider */
/**
 * brief   Setup rtc 1hz clock divider.
 * param divided_by_value: Value to be divided
 * return  Nothing
 */
void CLOCK_SetRtc1hzClkDiv(uint32_t divided_by_value)
{
    if (divided_by_value == 0U) /* halt */
    {
        PMC->RTCOSC32K |= (1U << PMC_RTCOSC32K_CLK1HZDIVHALT_SHIFT);
    }
    else
    {
        uint32_t rtcOsk32K = PMC->RTCOSC32K & ~(PMC_RTCOSC32K_CLK1HZDIV_MASK);
        PMC->RTCOSC32K     = rtcOsk32K | ((divided_by_value - 31744U) << PMC_RTCOSC32K_CLK1HZDIV_SHIFT);
    }
}

void CLOCK_Enable1MFRO(bool enable)
{
    if (enable)
    {
        SYSCON->CLOCK_CTRL |= 1UL << SYSCON_CLOCK_CTRL_FRO1MHZ_CLK_ENA_SHIFT;
        SYSCON->CLOCK_CTRL |= 1UL << SYSCON_CLOCK_CTRL_FRO1MHZ_UTICK_ENA_SHIFT;
    }
    else
    {
        SYSCON->CLOCK_CTRL &= ~(1UL << SYSCON_CLOCK_CTRL_FRO1MHZ_UTICK_ENA_SHIFT);
        SYSCON->CLOCK_CTRL &= ~(1UL << SYSCON_CLOCK_CTRL_FRO1MHZ_CLK_ENA_SHIFT);
    }
}

/* Set FRO Clocking */
status_t CLOCK_SetupFROClocking(uint32_t iFreq)
{
    switch (iFreq)
    {
        case kFreq_12MHz:
            ANACTRL->FRO192M_CTRL |= ANACTRL_FRO192M_CTRL_ENA_12MHZCLK(1);
            CLOCK_AttachClk(kFRO12M_to_MAIN_CLK);
            break;
        case kFreq_24MHz:
            ANACTRL->FRO192M_CTRL |= ANACTRL_FRO192M_CTRL_ENA_24MHZCLK(1);
            CLOCK_AttachClk(kFRO24M_to_MAIN_CLK);
            break;
        case kFreq_32MHz:
            ANACTRL->FRO192M_CTRL |= ANACTRL_FRO192M_CTRL_ENA_32MHZCLK(1);
            CLOCK_AttachClk(kFRO_HF_to_MAIN_CLK);
            break;
        case kFreq_48MHz:
            ANACTRL->FRO192M_CTRL |= ANACTRL_FRO192M_CTRL_ENA_48MHZCLK(1);
            /* This FRO cannot be used as main clock */
            break;
        case kFreq_64MHz:
            ANACTRL->FRO192M_CTRL |= ANACTRL_FRO192M_CTRL_ENA_64MHZCLK(1);
            /* This FRO cannot be used as main clock */
            break;
        default:
            return kStatus_Fail;
            break;
    }
    __ISB();
    __DSB();

    return kStatus_Success;
}

/* Disable FRO */
status_t CLOCK_DisableFROClock(uint32_t iFreq)
{
    switch (iFreq)
    {
        case kFreq_12MHz:
            ANACTRL->FRO192M_CTRL &= ~(ANACTRL_FRO192M_CTRL_ENA_12MHZCLK(1));
            break;
        case kFreq_24MHz:
            ANACTRL->FRO192M_CTRL &= ~(ANACTRL_FRO192M_CTRL_ENA_24MHZCLK(1));
            break;
        case kFreq_32MHz:
            ANACTRL->FRO192M_CTRL &= ~(ANACTRL_FRO192M_CTRL_ENA_32MHZCLK(1));
            break;
        case kFreq_48MHz:
            ANACTRL->FRO192M_CTRL &= ~(ANACTRL_FRO192M_CTRL_ENA_48MHZCLK(1));
            break;
        case kFreq_64MHz:
            ANACTRL->FRO192M_CTRL &= ~(ANACTRL_FRO192M_CTRL_ENA_64MHZCLK(1));
            break;
        default:
            return kStatus_Fail;
            break;
    }
    __ISB();
    __DSB();

    return kStatus_Success;
}

/* Set the FLASH wait states for the passed frequency */
/**
 * brief	Set the flash wait states for the input freuqency.
 * param	iFreq	: Input frequency in Hz
 * return	Nothing
 */
void CLOCK_SetFLASHAccessCyclesForFreq(uint32_t iFreq)
{
    uint32_t flashControl;
    uint32_t numExtraWaitStates = 0;

    // We take 10% margin on the 16MHz frequency where we need to switch from 0 to 1
    if (iFreq >= 14400000)
    {
        numExtraWaitStates = 1;
    }

    flashControl = FMU0->FCTRL & ~(FMU_FCTRL_RWSC_MASK);

    FMU0->FCTRL = flashControl | (numExtraWaitStates << FMU_FCTRL_RWSC_SHIFT);
}

/**
 * brief	Get the actual flash wait states.
 * return	ReadWaitStates
 */
uint32_t CLOCK_GetFLASHAccessCycles(void)
{
    return (FMU0->FCTRL & FMU_FCTRL_RWSC_MASK) >> FMU_FCTRL_RWSC_SHIFT;
}

/**
 * brief	Set the flash wait states.
 * param	ReadWaitStates
 */
void CLOCK_SetFLASHAccessCycles(uint32_t ReadWaitStates)
{
    uint32_t flash_control = FMU0->FCTRL & ~(FMU_FCTRL_RWSC_MASK);
    FMU0->FCTRL            = flash_control | (ReadWaitStates << FMU_FCTRL_RWSC_SHIFT);
}

/* Get CLOCK OUT Clk */
uint32_t CLOCK_GetClockOutClkFreq(void)
{
    uint32_t freq = 0U;

    switch (SYSCON->CLKOUTSEL)
    {
        case CLKOUTSEL_MAINCLK:
            freq = CLOCK_GetCoreSysClkFreq();
            break;

        case CLKOUTSEL_CLKIN:
            freq = CLOCK_GetExtClkFreq();
            break;

        case CLKOUTSEL_FRO_32MHz:
            freq = CLOCK_GetFroHfFreq();
            break;

        case CLKOUTSEL_FRO_1MHz:
            freq = CLOCK_GetFro1MFreq();
            break;

        case CLKOUTSEL_FRO_24MHz:
            freq = CLOCK_GetFro24MFreq();
            break;

        case CLKOUTSEL_32K_OSC:
            freq = CLOCK_GetOsc32KFreq();
            break;

        default:
            // All other values mean NO_CLOCK
            freq = 0;
            break;
    }
    return freq / ((SYSCON->CLKOUTDIV & SYSCON_CLKOUTDIV_DIV_MASK) + 1U);
}

/* Get SCTIMER Clk */
uint32_t CLOCK_GetSctClkFreq(void)
{
    uint32_t freq = 0U;

    switch (SYSCON->SCTCLKSEL)
    {
        case SCTCLKSEL_MAINCLK:
            freq = CLOCK_GetCoreSysClkFreq();
            break;

        case SCTCLKSEL_NO_CLOCK:
            freq = 0;
            break;

        case SCTCLKSEL_CLKIN:
            freq = CLOCK_GetExtClkFreq();
            break;

        case SCTCLKSEL_FRO_32MHz:
            freq = CLOCK_GetFroHfFreq();
            break;

        default:
            // All other values mean FRO_24MHz
            freq = CLOCK_GetFro24MFreq();
            break;
    }

    return freq / ((SYSCON->SCTCLKDIV & SYSCON_SCTCLKDIV_DIV_MASK) + 1U);
}

/* Get FRO 12M Clk */
uint32_t CLOCK_GetFro12MFreq(void)
{
    return (PMC->PDRUNCFG0 & PMC_PDRUNCFG0_PDEN_FRO192M_MASK) ?
               0 :
               (ANACTRL->FRO192M_CTRL & ANACTRL_FRO192M_CTRL_ENA_12MHZCLK_MASK) ? kFreq_12MHz : 0U;
}

/* Get FRO 24M Clk */
uint32_t CLOCK_GetFro24MFreq(void)
{
    return (PMC->PDRUNCFG0 & PMC_PDRUNCFG0_PDEN_FRO192M_MASK) ?
               0 :
               (ANACTRL->FRO192M_CTRL & ANACTRL_FRO192M_CTRL_ENA_24MHZCLK_MASK) ? kFreq_24MHz : 0U;
}

/* Get FRO 24M Clk */
uint32_t CLOCK_GetFro48MFreq(void)
{
    return (PMC->PDRUNCFG0 & PMC_PDRUNCFG0_PDEN_FRO192M_MASK) ?
               0 :
               (ANACTRL->FRO192M_CTRL & ANACTRL_FRO192M_CTRL_ENA_48MHZCLK_MASK) ? kFreq_48MHz : 0U;
}

/* Get FRO 64M Clk */
uint32_t CLOCK_GetFro64MFreq(void)
{
    return (PMC->PDRUNCFG0 & PMC_PDRUNCFG0_PDEN_FRO192M_MASK) ?
               0 :
               (ANACTRL->FRO192M_CTRL & ANACTRL_FRO192M_CTRL_ENA_64MHZCLK_MASK) ? kFreq_64MHz : 0U;
}

/* Get FRO 1M Clk */
uint32_t CLOCK_GetFro1MFreq(void)
{
    return (SYSCON->CLOCK_CTRL & SYSCON_CLOCK_CTRL_FRO1MHZ_CLK_ENA_MASK) ? kFreq_1MHz : 0U;
}

/* Get EXT OSC Clk */
uint32_t CLOCK_GetExtClkFreq(void)
{
    return (SYSCON->CLOCK_CTRL & SYSCON_CLOCK_CTRL_CLKIN_ENA_MASK) ? s_Ext_Clk_Freq : 0U;
}

/* Get WATCH DOG Clk */
uint32_t CLOCK_GetWdtClkFreq(void)
{
    return CLOCK_GetFro1MFreq() / ((SYSCON->WDTCLKDIV & SYSCON_WDTCLKDIV_DIV_MASK) + 1U);
}

/* Get HF FRO Clk */
uint32_t CLOCK_GetFroHfFreq(void)
{
    return (PMC->PDRUNCFG0 & PMC_PDRUNCFG0_PDEN_FRO192M_MASK) ?
               0 :
               (ANACTRL->FRO192M_CTRL & ANACTRL_FRO192M_CTRL_ENA_32MHZCLK_MASK) ? kFreq_32MHz : 0U;
}

/* Get RTC OSC Clk */
uint32_t CLOCK_GetOsc32KFreq(void)
{
    return (((PMC->PDRUNCFG0 & PMC_PDRUNCFG0_PDEN_FRO32K_MASK) == 0) &&
            ((PMC->RTCOSC32K & PMC_RTCOSC32K_SEL_MASK) == 0)) ?
               CLK_RTC_32K_CLK :
               /* Disabled check on power as the osc might be off when the clock is supplied externally */
               ((/*((PMC->PDRUNCFG0 & PMC_PDRUNCFG0_PDEN_XTAL32K_MASK) == 0) && */
                 ((PMC->RTCOSC32K & PMC_RTCOSC32K_SEL_MASK) != 0)) ?
                    CLK_RTC_32K_CLK :
                    0U);
}

/* Get MAIN Clk */
uint32_t CLOCK_GetCoreSysClkFreq(void)
{
    uint32_t freq = 0U;

    switch (SYSCON->MAINCLKSELB)
    {
        case MAINCLKSELB_MAINCLKAOUT:
            switch (SYSCON->MAINCLKSELA)
            {
                case MAINCLKSELA_FRO_12MHz:
                case MAINCLKSELA_FRO_12MHz_ALTERNATE_VALUE1:
                    freq = CLOCK_GetFro12MFreq();
                    break;

                case MAINCLKSELA_FRO_1MHz:
                case MAINCLKSELA_FRO_1MHz_ALTERNATE_VALUE1:
                    freq = CLOCK_GetFro1MFreq();
                    break;

                case MAINCLKSELA_FRO_32MHz:
                case MAINCLKSELA_FRO_32MHz_ALTERNATE_VALUE1:
                    freq = CLOCK_GetFroHfFreq();
                    break;

                case MAINCLKSELA_CLKIN:
                case MAINCLKSELA_CLKIN_ALTERNATE_VALUE1:
                    freq = CLOCK_GetExtClkFreq();
                    break;

                default:
                    break;
            }
            break;

        case MAINCLKSELB_FRO_24MHz:
            freq = CLOCK_GetFro24MFreq();
            break;

        case MAINCLKSELB_32K_OSC:
        case MAINCLKSELB_32K_OSC_ALTERNATE_VALUE1:
            freq = CLOCK_GetOsc32KFreq();
            break;

        default:
            break;
    }

    return freq;
}

/* Get FLEXCOMM input clock */
uint32_t CLOCK_GetFlexCommInputClock(uint32_t id)
{
    uint32_t freq = 0U;

    switch (SYSCON->FCCLKSELX[id])
    {
        case FCCLKSEL_MAINCLK:
            freq = CLOCK_GetCoreSysClkFreq();
            break;

        case FCCLKSEL_FRO_12MHz:
            freq = CLOCK_GetFro12MFreq();
            break;

        case FCCLKSEL_FRO_32MHz_DIV:
            freq = CLOCK_GetFroHfFreq() / ((SYSCON->FROHFDIV & SYSCON_FROHFDIV_DIV_MASK) + 1U);
            break;

        case FCCLKSEL_FRO_1MHz:
            freq = CLOCK_GetFro1MFreq();
            break;

        case FCCLKSEL_FRO_24MHz:
            freq = CLOCK_GetFro24MFreq();
            break;

        case FCCLKSEL_32K_OSC:
            freq = CLOCK_GetOsc32KFreq();
            break;

        default:
            // All other values mean NO_CLOCK
            freq = 0;
            break;
    }

    return freq;
}

uint32_t CLOCK_GetFlexCommClkFreq(uint32_t id)
{
    uint32_t freq   = 0U;
    uint32_t frgMul = 0U;
    uint32_t frgDiv = 0U;

    freq   = CLOCK_GetFlexCommInputClock(id);
    frgMul = (SYSCON->FLEXFRGXCTRL[id] & SYSCON_FLEXFRG0CTRL_MULT_MASK) >> 8U;
    frgDiv = SYSCON->FLEXFRGXCTRL[id] & SYSCON_FLEXFRG0CTRL_DIV_MASK;
    return (uint32_t)(((uint64_t)freq * ((uint64_t)frgDiv + 1ULL)) / (frgMul + frgDiv + 1UL));
}

/* Get SPIFI Clk */
uint32_t CLOCK_GetSpifiClkFreq(void)
{
    uint32_t freq = 0U;

    switch (SYSCON->SPIFICLKSEL)
    {
        case SPIFICLKSEL_MAINCLK:
            freq = CLOCK_GetCoreSysClkFreq();
            break;

        case SPIFICLKSEL_FRO_64MHz:
            freq = CLOCK_GetFro64MFreq();
            break;

        case SPIFICLKSEL_FRO_32MHz:
            freq = CLOCK_GetFroHfFreq();
            break;

        case SPIFICLKSEL_FRO_32MHz_DIV:
            freq = CLOCK_GetFroHfFreq() / ((SYSCON->FROHFDIV & SYSCON_FROHFDIV_DIV_MASK) + 1U);
            break;

        default:
            // All other values mean FRO_48MHz
            freq = CLOCK_GetFro48MFreq();
            break;
    }

    return freq;
}

/* Get CTimer Clk */
uint32_t CLOCK_GetCTimerClkFreq(uint32_t id)
{
    uint32_t freq = 0U;

    switch (SYSCON->CTIMERCLKSELX[id])
    {
        case CTIMERCLKSEL_MAINCLK:
            freq = CLOCK_GetCoreSysClkFreq();
            break;

        case CTIMERCLKSEL_FRO_32MHz:
            freq = CLOCK_GetFroHfFreq();
            break;

        case CTIMERCLKSEL_FRO_1MHz:
            freq = CLOCK_GetFro1MFreq();
            break;

        case CTIMERCLKSEL_FRO_24MHz:
            freq = CLOCK_GetFro24MFreq();
            break;

        case CTIMERCLKSEL_32K_OSC:
            freq = CLOCK_GetOsc32KFreq();
            break;

        default:
            // All other values mean NO_CLOCK
            freq = 0;
            break;
    }

    return freq;
}

/* Get Systick Clk */
uint32_t CLOCK_GetSystickClkFreq(uint32_t id)
{
    volatile uint32_t *pSystickClkDiv;

    pSystickClkDiv = &(SYSCON->SYSTICKCLKDIV0);
    uint32_t freq  = 0U;

    if (id >= SYSCON_SYSTICKCLKSEL_SYSTICKCLKSELX_SYSTICKCLKSELX_COUNT)
    {
        return 0;
    }

    switch ((uint32_t)(SYSCON->SYSTICKCLKSELX[id]))
    {
        case SYSTICKCLKSEL_SYSTICK_DIV:
            freq = CLOCK_GetCoreSysClkFreq() / ((pSystickClkDiv[id] & SYSCON_SYSTICKCLKDIV0_DIV_MASK) + 1U);
            break;

        case SYSTICKCLKSEL_FRO_1MHz:
            freq = CLOCK_GetFro1MFreq();
            break;

        case SYSTICKCLKSEL_32K_OSC:
            freq = CLOCK_GetOsc32KFreq();
            break;

        default:
            // All other values mean NO_CLOCK
            freq = 0;
            break;
    }

    return freq;
}

/* Set FlexComm Clock */
uint32_t CLOCK_SetFlexCommClock(uint32_t id, uint32_t freq)
{
    uint32_t input = CLOCK_GetFlexCommClkFreq(id);
    uint32_t mul;

    if ((freq > kFreq_32MHz) || (freq > input) || (input / freq >= 2))
    {
        /* FRG output frequency should be less than equal to 32MHz */
        return 0;
    }
    else
    {
        mul                      = ((uint64_t)(input - freq) * 256) / ((uint64_t)freq);
        SYSCON->FLEXFRGXCTRL[id] = (mul << 8U) | 0xFFU;
        return 1;
    }
}

/* Get IP Clk */
uint32_t CLOCK_GetFreq(clock_name_t clockName)
{
    uint32_t freq;
    switch (clockName)
    {
        case kCLOCK_CoreSysClk:
            freq = CLOCK_GetCoreSysClkFreq() / ((SYSCON->AHBCLKDIV & SYSCON_AHBCLKDIV_DIV_MASK) + 1U);
            break;
        case kCLOCK_BusClk:
            freq = CLOCK_GetCoreSysClkFreq() / ((SYSCON->AHBCLKDIV & SYSCON_AHBCLKDIV_DIV_MASK) + 1U);
            break;
        case kCLOCK_ClockOut:
            freq = CLOCK_GetClockOutClkFreq();
            break;
        case kCLOCK_FroHf:
            freq = CLOCK_GetFroHfFreq();
            break;
        case kCLOCK_Fro12M:
            freq = CLOCK_GetFro12MFreq();
            break;
        case kCLOCK_Fro24M:
            freq = CLOCK_GetFro24MFreq();
            break;
        case kCLOCK_ExtClk:
            freq = CLOCK_GetExtClkFreq();
            break;
        case kCLOCK_WdtClk:
            freq = CLOCK_GetWdtClkFreq();
            break;
        case kCLOCK_Sct:
            freq = CLOCK_GetSctClkFreq();
            break;
        case kCLOCK_Flexcomm0:
            freq = CLOCK_GetFlexCommClkFreq(0U);
            break;
        case kCLOCK_Flexcomm1:
            freq = CLOCK_GetFlexCommClkFreq(1U);
            break;
        case kCLOCK_Flexcomm2:
            freq = CLOCK_GetFlexCommClkFreq(2U);
            break;
        case kCLOCK_CTimer0:
            freq = CLOCK_GetCTimerClkFreq(0U);
            break;
        case kCLOCK_CTimer1:
            freq = CLOCK_GetCTimerClkFreq(1U);
            break;
        case kCLOCK_CTimer2:
            freq = CLOCK_GetCTimerClkFreq(2U);
            break;
        case kCLOCK_CTimer3:
            freq = CLOCK_GetCTimerClkFreq(3U);
            break;
        case kCLOCK_CTimer4:
            freq = CLOCK_GetCTimerClkFreq(4U);
            break;
        case kCLOCK_Systick:
            freq = CLOCK_GetSystickClkFreq(0U);
            break;
        case kCLOCK_SpifiClk:
            freq = CLOCK_GetSpifiClkFreq();
            break;
        default:
            freq = 0U;
            break;
    }
    return freq;
}

/* Get Systick Clk */
uint32_t CLOCK_GetOSTimerClkFreq(void)
{
    uint32_t freq = 0U;

    switch ((PMC->OSTIMERr & PMC_OSTIMER_OSTIMERCLKSEL_MASK) << PMC_OSTIMER_CLOCKENABLE_SHIFT)
    {
        case OSTIMERCLKSEL_32768:
            freq = 32768;
            break;

        case OSTIMERCLKSEL_FRO_1MHz:
            freq = CLOCK_GetFro1MFreq();
            break;

        default:
            /* All other values mean NO_CLOCK */
            freq = 0;
            break;
    }

    return freq;
}

/*! @brief Enable the OSTIMER 32k clock.
 *  @return  Nothing
 */
void CLOCK_EnableOstimer32kClock(void)
{
    PMC->OSTIMERr |= PMC_OSTIMER_CLOCKENABLE_MASK;
}

/**
 * brief   Initialize the external osc clock to given frequency.
 * Crystal oscillator with an operating frequency of 32 MHz.
 * param   iFreq   : Desired frequency (must be equal to exact rate in Hz)
 * return  returns success or fail status.
 */
status_t CLOCK_SetupExtClocking(uint32_t iFreq)
{
    if (iFreq != 32000000U)
    {
        return kStatus_Fail;
    }

    /* Enable 32MHz crystal. */
    POWER_PeripheralPowerOn(kPOWERCFG_BLE);
    SYSCON->CLOCK_CTRL |= SYSCON_CLOCK_CTRL_CLKIN_ENA(1);

    s_Ext_Clk_Freq = iFreq;
    return kStatus_Success;
}

void CLOCK_Select32kOscClkSrc(osc_32k_clock_source_t clockSrc)
{
    uint32_t reg = PMC->RTCOSC32K & ~PMC_RTCOSC32K_SEL_MASK;
    if (clockSrc == kCLOCK_Osc32kClockSrc_FRO || clockSrc == kCLOCK_Osc32kClockSrc_XTAL)
    {
        PMC->RTCOSC32K = reg | PMC_RTCOSC32K_SEL(clockSrc);
    }
}

/* Set PLU CLKIN Clk */
/**
 * brief   Initialize the PLU CLKIN clock to given frequency.
 * param   iFreq   : Desired frequency (must be equal to exact rate in Hz)
 * return  returns success or fail status.
 */
status_t CLOCK_SetupPLUClkInClocking(uint32_t iFreq)
{
    s_PLU_ClkIn_Freq = iFreq;
    return kStatus_Success;
}

/* Get PLU CLKIN Clk */
/*! brief  Return Frequency of PLU CLKIN Clock
 *  return Frequency of PLU CLKIN Clock
 */
uint32_t CLOCK_GetPLUClkInFreq(void)
{
    return s_PLU_ClkIn_Freq;
}
