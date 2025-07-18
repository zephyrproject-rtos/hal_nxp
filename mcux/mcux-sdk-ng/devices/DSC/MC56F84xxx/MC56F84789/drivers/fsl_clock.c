/*
 * Copyright 2020-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_clock.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.clock"
#endif

#define OCCS_MAX_PLL_CLK_FREQ 400000000UL
#define OCCS_MIN_PLL_CLK_FREQ 240000000UL

#define OCCS_INTERNAL_FIRC_N_FREQ 8000000UL
#define OCCS_INTERNAL_FIRC_S_FREQ 400000UL
#define OCCS_INTERNAL_SIRC_FREQ   32000UL

#define OCCS_MAX_CLK_IN_FREQ  50000000UL
#define OCCS_MIN_CRYSTAL_FREQ 4000000UL
#define OCCS_MAX_CRYSTAL_FREQ 16000000UL

#define OCCS_EXT_CLK_CHECK_REF_FREQ (OCCS_INTERNAL_FIRC_N_FREQ)

static volatile uint32_t g_u32ClockClkin0Freq;
static volatile uint32_t g_u32ClockClkin1Freq;
static volatile uint32_t g_u32ClockXtalFreq;

/*
 * CLOCK_SetClkConfig runtime configuration doesn't support assert.
 * clk_assert is supposed to figure out wrong clock configuration.
 */
#if defined(NDEBUG)
#define clk_assert(x)
#else
#define clk_assert(x) \
    if (!(x))         \
    {                 \
        while (1)     \
        {             \
        }             \
    }
#endif

/*!
 * brief Get the crystal OSC reference clock frequency.
 *
 * return Crystal oscillator clock frequency in Hz.
 */
static uint32_t CLOCK_GetXtalFreq(void)
{
    uint32_t u32Freq = 0U;
    if ((OCCS->OSCTL2 & OCCS_OSCTL2_COPD_MASK) == 0U)
    {
        /* Please call CLOCK_SetXtalFreq based on board setting before using OSC clock. */
        assert(0U != g_u32ClockXtalFreq);
        if ((OCCS->OSCTL1 & OCCS_OSCTL1_OSC_DIV2_MASK) == 0U)
        {
            u32Freq = g_u32ClockXtalFreq;
        }
        else
        {
            u32Freq = g_u32ClockXtalFreq / 2U;
        }
    }
    return u32Freq;
}

/*!
 * brief Get the external reference clock frequency.
 * it could be crystal osc, or clkin0, or clkin1.
 * if it is from crystal osc, please call CLOCK_SetXtalFreq in advance
 * if it is from clkin0, please call CLOCK_SetClkin0Freq in advance
 * if it is from clkin1, please call CLOCK_SetClkin1Freq in advance
 * return Clock frequency in Hz.
 */
static uint32_t CLOCK_GetExtClockFreq(void)
{
    uint32_t u32Freq;
    if ((OCCS->OSCTL1 & OCCS_OSCTL1_EXT_SEL_MASK) == 0U)
    {
        u32Freq = CLOCK_GetXtalFreq();
    }
    else
    {
        if ((SIM->MISC0 & SIM_MISC0_CLKINSEL_MASK) == 0U)
        {
            assert(0U != g_u32ClockClkin0Freq);
            u32Freq = g_u32ClockClkin0Freq;
        }
        else
        {
            assert(0U != g_u32ClockClkin1Freq);
            u32Freq = g_u32ClockClkin1Freq;
        }
    }
    return u32Freq;
}

/*!
 * brief Get internal fast RC oscillator frequency(8M/400K).
 *
 * return Clock frequency in Hz.
 */
static uint32_t CLOCK_GetFastIrcFreq(void)
{
    uint32_t u32Freq = 0U;

    if ((OCCS->OSCTL1 & OCCS_OSCTL1_ROPD_MASK) == 0U)
    {
        if ((OCCS->OSCTL1 & OCCS_OSCTL1_ROSB_MASK) == 0U)
        {
            u32Freq = OCCS_INTERNAL_FIRC_N_FREQ;
        }
        else
        {
            u32Freq = OCCS_INTERNAL_FIRC_S_FREQ;
        }
    }
    return u32Freq;
}

/*!
 * brief Get internal slow RC oscillator frequency(200K).
 *
 * return Clock frequency in Hz.
 */
static uint32_t CLOCK_GetSlowIrcFreq(void)
{
    uint32_t u32Freq = 0U;
    if ((OCCS->OSCTL2 & OCCS_OSCTL2_ROPD32K_MASK) == 0U)
    {
        u32Freq = OCCS_INTERNAL_SIRC_FREQ;
    }
    return u32Freq;
}

/*!
 * brief Get frequency of selected master oscillator.
 *
 * return Clock frequency in Hz.
 */
static uint32_t CLOCK_GetMstrOscFreq(void)
{
    uint32_t u32MstrOsc     = 0U;
    uint8_t u8MstrOscClkSrc = (uint8_t)((OCCS->CTRL & OCCS_CTRL_PRECS_MASK) >> OCCS_CTRL_PRECS_SHIFT);
    switch ((clock_mstr_osc_clk_src_t)u8MstrOscClkSrc)
    {
        case kCLOCK_MstrOscClkSrcExt:
            u32MstrOsc = CLOCK_GetExtClockFreq();
            break;
        case kCLOCK_MstrOscClkSrcSirc:
            u32MstrOsc = CLOCK_GetSlowIrcFreq();
            break;
        case kCLOCK_MstrOscClkSrcFirc:
            u32MstrOsc = CLOCK_GetFastIrcFreq();
            break;
        default:
            /*not supported*/
            assert(false);
            break;
    }
    return u32MstrOsc;
}

/*!
 * brief Get PLL output frequency, after divide 2.
 *
 * return Clock frequency in Hz.
 */
static uint32_t CLOCK_GetPllDiv2Freq(void)
{
    uint32_t u32Freq = 0U;
    if ((OCCS->CTRL & OCCS_CTRL_PLLPD_MASK) == 0U)
    {
        uint32_t u32MstrOsc = CLOCK_GetMstrOscFreq();
        uint16_t u16PllDiv  = ((OCCS->DIVBY & OCCS_DIVBY_PLLDB_MASK) >> OCCS_DIVBY_PLLDB_SHIFT) + 1U;
        u32Freq             = u32MstrOsc * ((uint32_t)u16PllDiv) / 2UL;
    }
    return u32Freq;
}

/*!
 * brief Get master 2x frequency.
 *
 * return Clock frequency in Hz.
 */
static uint32_t CLOCK_GetMstr2xFreq(void)
{
    uint32_t u32Freq;
    uint16_t u16DivShift;

    if ((OCCS->CTRL & OCCS_CTRL_ZSRC_MASK) == OCCS_CTRL_ZSRC(kCLOCK_Mstr2xClkSrcPllDiv2))
    {
        u32Freq = CLOCK_GetPllDiv2Freq();
    }
    else
    {
        u32Freq = CLOCK_GetMstrOscFreq();
    }

    u16DivShift = (OCCS->DIVBY & OCCS_DIVBY_COD_MASK) >> OCCS_DIVBY_COD_SHIFT;
    if (u16DivShift > 8U)
    {
        u16DivShift = 8U;
    }

    u32Freq >>= u16DivShift;
    return u32Freq;
}

/*!
 * brief Get QSCI clock frequency.
 *
 * param eQsciClkName QSCI clock name.
 *
 * return Clock frequency in Hz.
 */
static uint32_t CLOCK_GetQsciFreq(clock_ip_name_t eQsciClkName)
{
    uint32_t u32Freq     = CLOCK_GetFreq(kCLOCK_Bus2xClk);
    uint16_t u16BitIndex = SIM_PCR_SCI0_CR_SHIFT + (uint16_t)eQsciClkName - (uint16_t)kCLOCK_QSCI0;

    if ((SIM->PCR & (1UL << u16BitIndex)) == 0U)
    {
        /* Not 2X clock */
        u32Freq /= 2U;
    }
    return u32Freq;
}

/*!
 * brief Get system-level clock frequency.
 *
 * param eClkName System-level clock name.
 *
 * return The required clock's frequency in Hz.
 */
uint32_t CLOCK_GetFreq(clock_name_t eClkName)
{
    uint32_t u32Freq = 0U;
    switch (eClkName)
    {
        case kCLOCK_Mstr2xClk:
        case kCLOCK_Bus2xClk:
            u32Freq = CLOCK_GetMstr2xFreq();
            break;

        case kCLOCK_SysClk:
        case kCLOCK_BusClk:
            u32Freq = CLOCK_GetMstr2xFreq() / 2U;
            break;

        case kCLOCK_FlashClk:
            u32Freq = CLOCK_GetMstr2xFreq() / 8U;
            break;

        case kCLOCK_FastIrcClk:
            u32Freq = CLOCK_GetFastIrcFreq();
            break;

        case kCLOCK_SlowIrcClk:
            u32Freq = CLOCK_GetSlowIrcFreq();
            break;

        case kCLOCK_CrystalOscClk:
            u32Freq = CLOCK_GetXtalFreq();
            break;

        case kCLOCK_ExtClk:
            u32Freq = CLOCK_GetExtClockFreq();
            break;

        case kCLOCK_MstrOscClk:
            u32Freq = CLOCK_GetMstrOscFreq();
            break;

        case kCLOCK_PllDiv2Clk:
            u32Freq = CLOCK_GetPllDiv2Freq();
            break;

        default:
            assert(false);
            break;
    }
    return u32Freq;
}

/*!
 * brief Get IP clock frequency.
 *
 * param eIpClkName IP clock name.
 *
 * return The required IP clock's frequency in Hz.
 */
uint32_t CLOCK_GetIpClkSrcFreq(clock_ip_name_t eIpClkName)
{
    uint32_t u32Freq = 0U;
    switch (eIpClkName)
    {
        case kCLOCK_TA0:
        case kCLOCK_TA1:
        case kCLOCK_TA2:
        case kCLOCK_TA3:
        case kCLOCK_TB0:
        case kCLOCK_TB1:
        case kCLOCK_TB2:
        case kCLOCK_TB3:
            /* Qtimer has various clock source, this function only return bus clock for it. */
            u32Freq = CLOCK_GetFreq(kCLOCK_BusClk);
            break;

        case kCLOCK_QSCI0:
        case kCLOCK_QSCI1:
        case kCLOCK_QSCI2:
            u32Freq = CLOCK_GetQsciFreq(eIpClkName);
            break;

        case kCLOCK_I2C1:
        case kCLOCK_I2C0:
        case kCLOCK_QSPI0:
        case kCLOCK_QSPI1:
        case kCLOCK_QSPI2:
        case kCLOCK_CYCADC:
        case kCLOCK_DAC:
        case kCLOCK_PDB0:
        case kCLOCK_PDB1:
        case kCLOCK_QDC:
        case kCLOCK_CRC:
        case kCLOCK_CMPA:
        case kCLOCK_CMPB:
        case kCLOCK_CMPC:
        case kCLOCK_CMPD:
        case kCLOCK_PWMACH0:
        case kCLOCK_PWMACH1:
        case kCLOCK_PWMACH2:
        case kCLOCK_PWMACH3:
        case kCLOCK_PWMBCH0:
        case kCLOCK_PWMBCH1:
        case kCLOCK_PWMBCH2:
        case kCLOCK_PWMBCH3:
            u32Freq = CLOCK_GetFreq(kCLOCK_BusClk);
            break;

        case kCLOCK_PIT1:
        case kCLOCK_PIT0:
        case kCLOCK_FLEXCAN:
        case kCLOCK_SARADC:
            /* For these IPs, check IP's RM to know which clock source is selected and
             * get corresponding clock separately */
            break;

        default:
            assert(false);
            break;
    }

    return u32Freq;
}

/*!
 * brief Set Clock IN 0 frequency.
 *
 * It is a must to call this function in advance if system is operated by clkin0.
 *
 * param u32Freq Clock IN 0 frequency in Hz.
 */
void CLOCK_SetClkin0Freq(uint32_t u32Freq)
{
    assert(u32Freq != 0U);
    assert(u32Freq <= OCCS_MAX_CLK_IN_FREQ);
    g_u32ClockClkin0Freq = u32Freq;
}

/*!
 * brief Set Clock IN 1 frequency.
 *
 * It is a must to call this function in advance if system is operated by clkin1
 *
 * param u32Freq Clock IN 1 frequency in Hz.
 */
void CLOCK_SetClkin1Freq(uint32_t u32Freq)
{
    assert(u32Freq != 0U);
    assert(u32Freq <= OCCS_MAX_CLK_IN_FREQ);
    g_u32ClockClkin1Freq = u32Freq;
}

/*!
 * brief Set crystal oscillator frequency.
 *
 * It is a must to call this function in advance if system is operated by crystal oscillator.
 *
 * param u32Freq Crystal oscillator frequency in Hz.
 */
void CLOCK_SetXtalFreq(uint32_t u32Freq)
{
    assert(u32Freq >= OCCS_MIN_CRYSTAL_FREQ);
    assert(u32Freq <= OCCS_MAX_CRYSTAL_FREQ);
    g_u32ClockXtalFreq = u32Freq;
}

/*!
 * brief Config clock register access protection mode.
 *
 * param psConfig Pointer for protection configuration.
 */
void CLOCK_SetProtectionConfig(clock_protection_config_t *psConfig)
{
    OCCS->PROT =
        OCCS_PROT_FRQEP(psConfig->eFrqEP) | OCCS_PROT_OSCEP(psConfig->eOscEP) | OCCS_PROT_PLLEP(psConfig->ePllEP);
}

/*!
 * brief Config output clock.
 *
 * param psConfig Pointer for clock output configuration.
 */
void CLOCK_SetOutputClockConfig(clock_output_config_t *psConfig)
{
    uint16_t u16Reg;

    assert(NULL != psConfig);

    /* clock output0 and clock output1 share the same divider */
    u16Reg = SIM_CLKOUT_CLKODIV(psConfig->eClkDiv);

    if (psConfig->bClkOut0En)
    {
        u16Reg &= ~((uint16_t)SIM_CLKOUT_CLKDIS0_MASK);
        u16Reg |= SIM_CLKOUT_CLKOSEL0(psConfig->eClkOut0Src);
    }
    else
    {
        u16Reg |= SIM_CLKOUT_CLKDIS0_MASK;
    }

    if (psConfig->bClkOut1En)
    {
        u16Reg &= ~((uint16_t)SIM_CLKOUT_CLKDIS1_MASK);
        u16Reg |= SIM_CLKOUT_CLKOSEL1(psConfig->eClkOut1Src);
    }
    else
    {
        u16Reg |= SIM_CLKOUT_CLKDIS1_MASK;
    }

    SIM->CLKOUT = u16Reg;
}

/*!
 * brief Config mcu operation clock.
 *
 * param psConfig Pointer for clock configuration.
 */
void CLOCK_SetClkConfig(clock_config_t *psConfig)
{
    /* sysClkSrc switch back to mstr_osc */
    OCCS->CTRL &= ~((uint16_t)OCCS_CTRL_ZSRC_MASK);

    /* wait the switch done */
    while ((OCCS->STAT & OCCS_STAT_ZSRCS_MASK) != OCCS_STAT_ZSRCS(kCLOCK_Mstr2xClkSrcMstrOsc))
    {
    }

    /* disable PLL */
    OCCS->CTRL |= OCCS_CTRL_PLLPD_MASK;

    /* Enable clock firstly */
    if (psConfig->bFircEnable)
    {
        OCCS->OSCTL1 &= ~((uint16_t)OCCS_OSCTL1_ROPD_MASK);
        if (kCLOCK_FircSel_8M == psConfig->eFircSel)
        {
            OCCS->OSCTL1 &= ~((uint16_t)OCCS_OSCTL1_ROSB_MASK);
        }
        else
        {
            OCCS->OSCTL1 |= OCCS_OSCTL1_ROSB_MASK;
        }
    }

    if (psConfig->bSircEnable)
    {
        OCCS->OSCTL2 &= ~((uint16_t)OCCS_OSCTL2_ROPD32K_MASK);
    }

    if (psConfig->bCrystalOscEnable)
    {
        /* set crystal osc mode */
        if (psConfig->eCrystalOscMode == kCLOCK_CrystalOscModeFSP)
        {
            OCCS->OSCTL1 &= ~((uint16_t)OCCS_OSCTL1_COHL_MASK);
        }
        else
        {
            /* kCLOCK_CrystalOscModeLCP */
            OCCS->OSCTL1 |= OCCS_OSCTL1_COHL_MASK;
        }

        /* Not support bypass mode, disable it by default */
        OCCS->OSCTL1 &= ~((uint16_t)OCCS_OSCTL1_CLK_MODE_MASK);

        if (psConfig->bCrystalFreqDiv2)
        {
            OCCS->OSCTL1 |= OCCS_OSCTL1_OSC_DIV2_MASK;
        }
        else
        {
            OCCS->OSCTL1 &= ~((uint16_t)OCCS_OSCTL1_OSC_DIV2_MASK);
        }

        /* Enable the crystal oscillation and wait it get stable */
        OCCS->OSCTL2 &= ~((uint16_t)OCCS_OSCTL2_COPD_MASK);
        while ((OCCS->STAT & OCCS_STAT_OSC_OK_MASK) == 0U)
        {
        }

        if (psConfig->bCrystalOscMonitorEnable)
        {
            OCCS->OSCTL2 |= OCCS_OSCTL2_MON_ENABLE_MASK;
        }
        else
        {
            OCCS->OSCTL2 &= ~((uint16_t)OCCS_OSCTL2_MON_ENABLE_MASK);
        }
    }

    if (kCLOCK_ExtClkSrcCrystalOsc == psConfig->eExtClkSrc)
    {
        OCCS->OSCTL1 &= ~((uint16_t)(OCCS_OSCTL1_CLK_MODE_MASK | OCCS_OSCTL1_EXT_SEL_MASK));
    }
    else
    {
        if (kCLOCK_SelClkIn0 == psConfig->eClkInSel)
        {
            SIM->MISC0 &= ~((uint16_t)SIM_MISC0_CLKINSEL_MASK);
        }
        else
        {
            /* kCLOCK_SelClkIn1 */
            SIM->MISC0 |= SIM_MISC0_CLKINSEL_MASK;
        }
        OCCS->OSCTL1 |= OCCS_OSCTL1_EXT_SEL_MASK;
    }

    /* Safety check before PRECS switch.
     * Here should only check each clock enable in config as below.
     * The reason not check the enable bit in register for FIRC/SIRC/Crystal oscillator,
     * is that they may be turned off at next step. */
    switch (psConfig->eMstrOscClkSrc)
    {
        case kCLOCK_MstrOscClkSrcFirc:
            clk_assert(psConfig->bFircEnable);
            break;

        case kCLOCK_MstrOscClkSrcSirc:
            clk_assert(psConfig->bSircEnable);
            break;

        case kCLOCK_MstrOscClkSrcExt:
            if (kCLOCK_ExtClkSrcCrystalOsc == psConfig->eExtClkSrc)
            {
                clk_assert(psConfig->bCrystalOscEnable);
            }
            else
            {
                /* the external clock is from clkin, SW can't verify if it is on */
            }
            break;

        default:
            clk_assert(false);
    }

    /* mstr_osc switch to setting value */
    OCCS->CTRL = (OCCS->CTRL & (~((uint16_t)OCCS_CTRL_PRECS_MASK))) | OCCS_CTRL_PRECS(psConfig->eMstrOscClkSrc);

    /* wait 6 NOP for the clock transition done */
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();

    /* turn off all disable clock source */
    if (!(psConfig->bFircEnable))
    {
        OCCS->OSCTL1 |= OCCS_OSCTL1_ROPD_MASK;
    }

    if (!(psConfig->bSircEnable))
    {
        OCCS->OSCTL2 |= OCCS_OSCTL2_ROPD32K_MASK;
    }

    if (!(psConfig->bCrystalOscEnable))
    {
        OCCS->OSCTL2 |= OCCS_OSCTL2_COPD_MASK;
    }

    /* setting pll */
    if (psConfig->bPllEnable)
    {
        uint32_t u32MstrOscClkFreq = 0U;
        uint16_t u16PllDiv;
        clk_assert(psConfig->u32PllClkFreq >= OCCS_MIN_PLL_CLK_FREQ);
        clk_assert(psConfig->u32PllClkFreq <= OCCS_MAX_PLL_CLK_FREQ);

        switch (psConfig->eMstrOscClkSrc)
        {
            case kCLOCK_MstrOscClkSrcExt:
                u32MstrOscClkFreq = CLOCK_GetExtClockFreq();
                break;
            case kCLOCK_MstrOscClkSrcFirc:
                u32MstrOscClkFreq = CLOCK_GetFastIrcFreq();
                clk_assert(u32MstrOscClkFreq == OCCS_INTERNAL_FIRC_N_FREQ);
                break;
            default:
                /* not support other configurations */
                clk_assert(false);
        }

        clk_assert(0U != u32MstrOscClkFreq);

        /* Check and config the PLL multiplier */
        u16PllDiv = (uint16_t)(psConfig->u32PllClkFreq / u32MstrOscClkFreq);

        clk_assert(u16PllDiv >= 1U);
        clk_assert(u16PllDiv <= 64U);

        OCCS->DIVBY = (OCCS->DIVBY & (~((uint16_t)OCCS_DIVBY_PLLDB_MASK))) | OCCS_DIVBY_PLLDB(u16PllDiv - 1U);
        OCCS->CTRL |= OCCS_CTRL_LCKON_MASK;

        /* power on PLL and wait it get locked */
        OCCS->CTRL &= ~((uint16_t)OCCS_CTRL_PLLPD_MASK);
        while ((OCCS->STAT & OCCS_STAT_LCK0_MASK) == 0U)
        {
        }
        while ((OCCS->STAT & OCCS_STAT_LCK1_MASK) == 0U)
        {
        }
    }

    OCCS->DIVBY = (OCCS->DIVBY & (~((uint16_t)OCCS_DIVBY_COD_MASK))) | OCCS_DIVBY_COD(psConfig->eMstr2xClkPostScale);

    /* switch mstr_clk_2x to desired source.
     * Note: it is already switched to mstr_osc at the beginning of this function
     */
    if (psConfig->eMstr2xClkSrc == kCLOCK_Mstr2xClkSrcPllDiv2)
    {
        uint32_t u32Mstr2xClkFreq;
        clk_assert((OCCS->CTRL & OCCS_CTRL_PLLPD_MASK) == 0U);

        u32Mstr2xClkFreq = (psConfig->u32PllClkFreq / 2U) >> ((uint16_t)(psConfig->eMstr2xClkPostScale));
        clk_assert(u32Mstr2xClkFreq <= (SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY * 2U));

        OCCS->CTRL |= OCCS_CTRL_ZSRC_MASK;
        while ((OCCS->STAT & OCCS_STAT_ZSRCS_MASK) != OCCS_STAT_ZSRCS(kCLOCK_Mstr2xClkSrcPllDiv2))
        {
        }
    }
}

/*!
 * brief Evaluate external clock frequency and return its frequency in Hz.
 *
 * This function should be called only when internal FIRC is on and in RUN mode(8M).
 * The evaluated result accuracy depends on:
 * 1. FIRC accuracy, now it is +/-3%.
 * 2. Truncation error, because the external clock and FIRC is not synchronised.
 * 3. External clock frequency, low accuracy for lower external clock frequency.
 * 4. MCU mstr 2x clock.
 *
 * For example, for namely 8M external clock, evaluated result may be range in 8M+/-8%.
 *
 * return Evaluated external frequency in Hz.
 */
uint32_t CLOCK_EvaluateExtClkFreq(void)
{
    /* Start evaluation and wait it finished. */
    OCCS->CLKCHKR |= OCCS_CLKCHKR_CHK_ENA_MASK;
    while (0U != (OCCS->CLKCHKR & OCCS_CLKCHKR_CHK_ENA_MASK))
    {
    }

    return (OCCS_EXT_CLK_CHECK_REF_FREQ / 128UL) * OCCS->CLKCHKT;
}

/*!
 * brief Enable/Disable PLL monitor interrupt.
 *
 * This function should be called only when PLL is on and its reference clock is external clock.
 * This function is for safety purpose when external clock is lost due to HW failure.
 * The normal flow to call this function:
 * 1. Call CLOCK_SetClkConfig to enable PLL and external clock to feed the PLL.
 * 2. Call CLOCK_ClearPLLMonitorFlag.
 * 3. Call CLOCK_SetPllLossofRefererntTripPoint (optional, setting value is for kCLOCK_PllMonitorLostofReferClk type).
 * 4. Call this function.
 * 5. Enable OCCS interrupt with highest priority 3.
 * 6. When OCCS interrupt occurs, recover clock from the disaster in OCCS_DriveISRHandler function. Such kind of clock
 * recovery is application dependent, and a demo OCCS_DriveISRHandler has been shown in fsl_clock.c
 *
 * param eType PLL monitor type.
 * param bEnable Enable or disable.
 */
void CLOCK_EnablePLLMonitorInterrupt(clock_pll_monitor_type_t eType, bool bEnable)
{
    /* PLL must be on and get locked and its ref clock must be ext clock. */
    assert(0U == (OCCS->CTRL & OCCS_CTRL_PLLPD_MASK));
    assert(OCCS_CTRL_PRECS(kCLOCK_MstrOscClkSrcExt) == (OCCS->CTRL & OCCS_CTRL_PRECS_MASK));
    assert(OCCS_STAT_LCK0_MASK == (OCCS->STAT & OCCS_STAT_LCK0_MASK));
    assert(OCCS_STAT_LCK1_MASK == (OCCS->STAT & OCCS_STAT_LCK1_MASK));

    switch (eType)
    {
        case kCLOCK_PllMonitorUnLockCoarse:
            if (bEnable)
            {
                /* enable falling edge of LCK0, that is pll coarse unlock */
                OCCS->CTRL = (OCCS->CTRL & (~((uint16_t)OCCS_CTRL_PLLIE0_MASK))) | OCCS_CTRL_PLLIE0(2U);
            }
            else
            {
                OCCS->CTRL &= ~((uint16_t)OCCS_CTRL_PLLIE0_MASK);
            }
            break;

        case kCLOCK_PllMonitorUnLockFine:
            if (bEnable)
            {
                /* enable falling edge of LCK1, that is pll fine unlock */
                OCCS->CTRL = (OCCS->CTRL & (~((uint16_t)OCCS_CTRL_PLLIE1_MASK))) | OCCS_CTRL_PLLIE1(2U);
            }
            else
            {
                OCCS->CTRL &= ~((uint16_t)OCCS_CTRL_PLLIE1_MASK);
            }
            break;

        case kCLOCK_PllMonitorLostofReferClk:
            if (bEnable)
            {
                OCCS->CTRL |= OCCS_CTRL_LOCIE_MASK;
            }
            else
            {
                OCCS->CTRL &= ~((uint16_t)OCCS_CTRL_LOCIE_MASK);
            }
            break;

        case kCLOCK_PllMonitorAll:
            if (bEnable)
            {
                OCCS->CTRL = (OCCS->CTRL &
                              (~((uint16_t)(OCCS_CTRL_PLLIE0_MASK | OCCS_CTRL_PLLIE1_MASK | OCCS_CTRL_LOCIE_MASK)))) |
                             (OCCS_CTRL_PLLIE0(2U) | OCCS_CTRL_PLLIE1(2U) | OCCS_CTRL_LOCIE_MASK);
            }
            else
            {
                OCCS->CTRL &= (~((uint16_t)(OCCS_CTRL_PLLIE0_MASK | OCCS_CTRL_PLLIE1_MASK | OCCS_CTRL_LOCIE_MASK)));
            }
            break;

        default:
            assert(false);
            break;
    }
}

/*!
 * brief OCCS Interrupt handler.
 *
 * This function handle situation when the PLL unlock/loss of reference clock.
 * The handle process is application dependent and here demo how to recover the clock.
 */
void OCCS_DriverIRQHandler(void);
void OCCS_DriverIRQHandler(void)
{
    /* For the case that OCCS interrupt priority is 3 and re-enable PLL in this handler,
     * another OCCS interrupt occurs, this cause a nested OCCS interrupt, which is not desired.
     * So disable the OCCS interrupt at beginning. */
    DisableIRQ(OCCS_IRQn);

    /* Only handle the case that the external clock is used as MstrOSC */
    if (OCCS_CTRL_PRECS(kCLOCK_MstrOscClkSrcExt) == (OCCS->CTRL & OCCS_CTRL_PRECS_MASK))
    {
        OCCS->OSCTL1 &= ~((uint16_t)(OCCS_OSCTL1_ROPD_MASK | OCCS_OSCTL1_ROSB_MASK));

        /* Switch MstrOSC to internal 8M clock, which is from FIRC, and wait transition done */
        OCCS->CTRL = (OCCS->CTRL & (~((uint16_t)OCCS_CTRL_PRECS_MASK))) | OCCS_CTRL_PRECS(kCLOCK_MstrOscClkSrcFirc);
        __NOP();
        __NOP();
        __NOP();
        __NOP();
        __NOP();
        __NOP();

        /* Switch System clock to MstrOSC and wait transition done */
        OCCS->CTRL = (OCCS->CTRL & (~((uint16_t)OCCS_CTRL_ZSRC_MASK))) | OCCS_CTRL_ZSRC(kCLOCK_Mstr2xClkSrcMstrOsc);
        while ((OCCS->STAT & OCCS_STAT_ZSRCS_MASK) != OCCS_STAT_ZSRCS(kCLOCK_Mstr2xClkSrcMstrOsc))
        {
        }

        /* Now the system get alive because its clock source is guaranteed. */

        /* Setting PLL and wait it get locked */
        OCCS->CTRL |= OCCS_CTRL_PLLPD_MASK; /* power down PLL firstly */
        OCCS->DIVBY = (OCCS->DIVBY & (~((uint16_t)OCCS_DIVBY_PLLDB_MASK))) | OCCS_DIVBY_PLLDB(49U);
        OCCS->CTRL &= ~((uint16_t)OCCS_CTRL_PLLPD_MASK);
        while ((OCCS->STAT & OCCS_STAT_LCK0_MASK) == 0U)
        {
        }
        while ((OCCS->STAT & OCCS_STAT_LCK1_MASK) == 0U)
        {
        }

        /* Switch System clock to PLL and wait transition done */
        OCCS->CTRL = (OCCS->CTRL & (~((uint16_t)OCCS_CTRL_ZSRC_MASK))) | OCCS_CTRL_ZSRC(kCLOCK_Mstr2xClkSrcPllDiv2);
        while ((OCCS->STAT & OCCS_STAT_ZSRCS_MASK) != OCCS_STAT_ZSRCS(kCLOCK_Mstr2xClkSrcPllDiv2))
        {
        }

        /* Add Application related code here , say shut down critical hardware to prevent damage. */
    }

    /* No matter what kind of interrupt, clear all flags */
    OCCS->STAT = OCCS_STAT_LOLI1_MASK | OCCS_STAT_LOLI0_MASK | OCCS_STAT_LOCI_MASK;
}
