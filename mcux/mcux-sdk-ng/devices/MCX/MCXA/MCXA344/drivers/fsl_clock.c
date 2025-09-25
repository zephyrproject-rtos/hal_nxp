/*
 * Copyright 2023, NXP
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

/*******************************************************************************
 * Variables
 ******************************************************************************/
/** External clock rate on the CLKIN pin in Hz. If not used,
    set this to 0. Otherwise, set it to the exact rate in Hz this pin is
    being driven at. */
volatile static uint32_t s_Ext_Clk_Freq = 16000000U;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* Get FRO 12M Clk */
static uint32_t CLOCK_GetFro12MFreq(void);
/* Get LF FRO_DIV Clk */
static uint32_t CLOCK_GetFroLfDivFreq(void);
/* Get CLK 1M Clk */
static uint32_t CLOCK_GetClk1MFreq(void);
/* Get HF FRO Clk */
static uint32_t CLOCK_GetFroHfFreq(void);
/* Get HF FRO_DIV Clk */
static uint32_t CLOCK_GetFroHfDivFreq(void);
/* Get CLK 45M Clk */
static uint32_t CLOCK_GetClk45MFreq(void);
/* Get CLK 16K Clk */
static uint32_t CLOCK_GetClk16KFreq(uint8_t id);
/* Get EXT OSC Clk */
static uint32_t CLOCK_GetExtClkFreq(void);
/* Get Main_Clk */
uint32_t CLOCK_GetMainClk(void);
/* Get FRO_16K */
static uint32_t CLOCK_GetFRO16KFreq(void);

/* Check if DIV is halt */
static inline bool CLOCK_IsDivHalt(uint32_t div_value)
{
    if (0U != (div_value & (1UL << 30U)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

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
    const uint32_t reg_offset = CLK_ATTACH_REG_OFFSET(connection);
    const uint32_t clk_sel    = CLK_ATTACH_CLK_SEL(connection);

    if (kNONE_to_NONE != connection)
    {
        CLOCK_SetClockSelect((clock_select_name_t)reg_offset, clk_sel);
    }
}

/* Return the actual clock attach id */
/**
 * brief   Get the actual clock attach id.
 * This fuction uses the offset in input attach id, then it reads the actual
 * source value in the register and combine the offset to obtain an actual
 * attach id.
 * value.
 */
clock_attach_id_t CLOCK_GetClockAttachId(clock_attach_id_t connection)
{
    const uint32_t reg_offset = CLK_ATTACH_REG_OFFSET(connection);
    uint32_t actual_sel       = 0U;
    uint32_t clock_attach_id  = 0U;

    if (kNONE_to_NONE == connection)
    {
        return kNONE_to_NONE;
    }

    actual_sel      = CLOCK_GetClockSelect((clock_select_name_t)reg_offset);
    clock_attach_id = CLK_ATTACH_MUX(reg_offset, actual_sel);

    return (clock_attach_id_t)clock_attach_id;
}

/* Set the clock selection value */
void CLOCK_SetClockSelect(clock_select_name_t sel_name, uint32_t value)
{
    volatile uint32_t *pClkCtrl = (volatile uint32_t *)(MRCC0_BASE + (uint32_t)sel_name);
    assert(sel_name <= kCLOCK_SelMax);

    if (sel_name == kCLOCK_SelSCGSCS)
    {
        SCG0->RCCR = (SCG0->RCCR & ~(SCG_RCCR_SCS_MASK)) | SCG_RCCR_SCS(value);
        while ((SCG0->CSR & SCG_CSR_SCS_MASK) != SCG_CSR_SCS(value))
        {
        }
    }
    else
    {
        /* Unlock clock configuration */
        SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_UNLOCK_MASK;

        *pClkCtrl = value;

        /* Freeze clock configuration */
        SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_UNLOCK_MASK;
    }
}

/* Get the clock selection value */
uint32_t CLOCK_GetClockSelect(clock_select_name_t sel_name)
{
    volatile uint32_t *pClkCtrl = (volatile uint32_t *)(MRCC0_BASE + (uint32_t)sel_name);
    uint32_t actual_sel         = 0U;
    assert(sel_name <= kCLOCK_SelMax);

    if (sel_name == kCLOCK_SelSCGSCS)
    {
        actual_sel = (uint32_t)((SCG0->RCCR & SCG_RCCR_SCS_MASK) >> SCG_RCCR_SCS_SHIFT);
    }
    else
    {
        actual_sel = *pClkCtrl;
    }

    return actual_sel;
}

/* Set the clock divider value */
void CLOCK_SetClockDiv(clock_div_name_t div_name, uint32_t value)
{
    volatile uint32_t *pDivCtrl = (volatile uint32_t *)(MRCC0_BASE + (uint32_t)div_name);
    assert(div_name <= kCLOCK_DivMax);

    /* Unlock clock configuration */
    SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_UNLOCK_MASK;

    /* halt and reset clock dividers */
    *pDivCtrl = 0x3UL << 29U;

    if (value == 0U) /*!<  halt */
    {
        *pDivCtrl |= (1UL << 30U);
    }
    else
    {
        *pDivCtrl = (value - 1U);
    }

    /* Freeze clock configuration */
    SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_UNLOCK_MASK;
}

/* Get the clock divider value */
uint32_t CLOCK_GetClockDiv(clock_div_name_t div_name)
{
    volatile uint32_t *pDivCtrl = (volatile uint32_t *)(MRCC0_BASE + (uint32_t)div_name);
    assert(div_name <= kCLOCK_DivMax);

    if (((*pDivCtrl) & (1UL << 30U)) != 0U)
    {
        return 0;
    }
    else
    {
        return ((*pDivCtrl & 0xFFU) + 1U);
    }
}

/* Halt the clock divider value */
void CLOCK_HaltClockDiv(clock_div_name_t div_name)
{
    volatile uint32_t *pDivCtrl = (volatile uint32_t *)(MRCC0_BASE + (uint32_t)div_name);
    assert(div_name <= kCLOCK_DivMax);

    /* Unlock clock configuration */
    SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_UNLOCK_MASK;

    *pDivCtrl |= (1UL << 30U);

    /* Freeze clock configuration */
    SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_UNLOCK_MASK;
}

/* Initialize the FROHF to given frequency (45,60,90,180) */
status_t CLOCK_SetupFROHFClocking(uint32_t iFreq)
{
    uint8_t freq_select = 0x0U;
    switch (iFreq)
    {
        case 45000000U:
            freq_select = 1U;
            break;
        case 60000000U:
            freq_select = 3U;
            break;
        case 90000000U:
            freq_select = 5U;
            break;
        case 180000000U:
            freq_select = 7U;
            break;
        default:
            freq_select = 0xFU;
            break;
    }

    if (0xFU == freq_select)
    {
        return kStatus_Fail;
    }

    /* Set FIRC frequency */
    SCG0->FIRCCFG = SCG_FIRCCFG_FREQ_SEL(freq_select);

    /* Unlock FIRCCSR */
    SCG0->FIRCCSR &= ~SCG_FIRCCSR_LK_MASK;

    /* Enable CLK 45 MHz clock for peripheral use */
    SCG0->FIRCCSR |= SCG_FIRCCSR_FIRC_SCLK_PERIPH_EN_MASK;
    /* Enable FIRC HF clock for peripheral use */
    SCG0->FIRCCSR |= SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN_MASK;
    /* Enable FIRC */
    SCG0->FIRCCSR |= SCG_FIRCCSR_FIRCEN_MASK;

    /* Lock FIRCCSR */
    SCG0->FIRCCSR |= SCG_FIRCCSR_LK_MASK;

    /* Wait for FIRC clock to be valid. */
    while ((SCG0->FIRCCSR & SCG_FIRCCSR_FIRCVLD_MASK) == 0U)
    {
    }

    return kStatus_Success;
}

/* Initialize the FRO12M. */
status_t CLOCK_SetupFRO12MClocking(void)
{
    /* Unlock SIRCCSR */
    SCG0->SIRCCSR &= ~SCG_SIRCCSR_LK_MASK;

    /* Enable FRO12M clock for peripheral use */
    SCG0->SIRCCSR |= SCG_SIRCCSR_SIRC_CLK_PERIPH_EN_MASK;

    /* Lock SIRCCSR */
    SCG0->SIRCCSR |= SCG_SIRCCSR_LK_MASK;

    /* Wait for SIRC clock to be valid. */
    while ((SCG0->SIRCCSR & SCG_SIRCCSR_SIRCVLD_MASK) == 0U)
    {
    }

    /* Release FROLFDIV */
    SYSCON->FROLFDIV &= ~SYSCON_FROLFDIV_HALT_MASK;

    return kStatus_Success;
}

/*!
 * brief   Initialize the FRO16K.
 * This function turns on FRO16K.
 * return  returns success or fail status.
 */
status_t CLOCK_SetupFRO16KClocking(uint8_t clk_16k_enable_mask)
{
    /* Enable clk_16k */
    VBAT0->FROCTLA |= VBAT_FROCTLA_FRO_EN_MASK;
    VBAT0->FROLCKA |= VBAT_FROLCKA_LOCK_MASK;

    /* Enable clk_16k output clock to corresponding modules according to the
     * enable_mask. */
    VBAT0->FROCLKE |= VBAT_FROCLKE_CLKE(((uint32_t)clk_16k_enable_mask));

    return kStatus_Success;
}

/*!
 * brief   Initialize the external osc clock to given frequency.
 * param   iFreq   : Desired frequency (must be equal to exact rate in Hz)
 * return  returns success or fail status.
 */
status_t CLOCK_SetupExtClocking(uint32_t iFreq)
{
    uint8_t range = 0U;

    if ((iFreq >= 8000000U) && (iFreq < 16000000U))
    {
        range = 0U;
    }
    else if ((iFreq >= 16000000U) && (iFreq < 25000000U))
    {
        range = 1U;
    }
    else if ((iFreq >= 25000000U) && (iFreq < 40000000U))
    {
        range = 2U;
    }
    else if ((iFreq >= 40000000U) && (iFreq <= 50000000U))
    {
        range = 3U;
    }
    else
    {
        return kStatus_InvalidArgument;
    }

    /* If configure register is locked, return error. */
    if ((SCG0->SOSCCSR & SCG_SOSCCSR_LK_MASK) != 0U)
    {
        return kStatus_ReadOnly;
    }

    /* De-initializes the SCG SOSC */
    SCG0->SOSCCSR = SCG_SOSCCSR_SOSCERR_MASK;

    /* Enable LDO */
    SCG0->LDOCSR |= SCG_LDOCSR_LDOEN_MASK;

    /* Select SOSC source(internal crystal oscillator) and Configure SOSC range */
    SCG0->SOSCCFG = SCG_SOSCCFG_EREFS_MASK | SCG_SOSCCFG_RANGE(range);

    /* Unlock SOSCCSR */
    SCG0->SOSCCSR &= ~SCG_SOSCCSR_LK_MASK;

    /* Enable SOSC clock monitor and Enable SOSC */
    SCG0->SOSCCSR |= (SCG_SOSCCSR_SOSCCM_MASK | SCG_SOSCCSR_SOSCEN_MASK);

    /* Wait for SOSC clock to be valid. */
    while ((SCG0->SOSCCSR & SCG_SOSCCSR_SOSCVLD_MASK) == 0U)
    {
    }

    s_Ext_Clk_Freq = iFreq;

    return kStatus_Success;
}

/*!
 * @brief   Initialize the external reference clock to given frequency.
 * param   iFreq   : Desired frequency (must be equal to exact rate in Hz)
 * return  returns success or fail status.
 */
status_t CLOCK_SetupExtRefClocking(uint32_t iFreq)
{
    if (iFreq > 50000000U)
    {
        return kStatus_InvalidArgument;
    }

    /* If configure register is locked, return error. */
    if ((SCG0->SOSCCSR & SCG_SOSCCSR_LK_MASK) != 0U)
    {
        return kStatus_ReadOnly;
    }

    /* De-initializes the SCG SOSC */
    SCG0->SOSCCSR = SCG_SOSCCSR_SOSCERR_MASK;

    /* Enable LDO */
    SCG0->LDOCSR |= SCG_LDOCSR_LDOEN_MASK;

    /* Select SOSC source (external reference clock)*/
    SCG0->SOSCCFG &= ~SCG_SOSCCFG_EREFS_MASK;

    /* Unlock SOSCCSR */
    SCG0->SOSCCSR &= ~SCG_SOSCCSR_LK_MASK;

    /* Enable SOSC clock monitor and Enable SOSC */
    SCG0->SOSCCSR |= (SCG_SOSCCSR_SOSCCM_MASK | SCG_SOSCCSR_SOSCEN_MASK);

    /* Wait for SOSC clock to be valid. */
    while ((SCG0->SOSCCSR & SCG_SOSCCSR_SOSCVLD_MASK) == 0U)
    {
    }

    s_Ext_Clk_Freq = iFreq;

    return kStatus_Success;
}

/* Get IP Clk */
/*! brief  Return Frequency of selected clock
 *  return Frequency of selected clock
 */
uint32_t CLOCK_GetFreq(clock_name_t clockName)
{
    uint32_t freq = 0U;

    switch (clockName)
    {
        case kCLOCK_MainClk: /* MAIN_CLK */
            freq = CLOCK_GetMainClk();
            break;
        case kCLOCK_CoreSysClk: /* Core/system clock(CPU_CLK) */
            freq = CLOCK_GetCoreSysClkFreq();
            break;
        case kCLOCK_SYSTEM_CLK: /* AHB clock */
            freq = CLOCK_GetCoreSysClkFreq();
            break;
        case kCLOCK_BusClk: /* Bus clock */
            freq = (CLOCK_GetCoreSysClkFreq() >> 1);
            break;
        case kCLOCK_ExtClk: /* External Clock */
            freq = CLOCK_GetExtClkFreq();
            break;
        case kCLOCK_FroHf: /* FROHF */
            freq = CLOCK_GetFroHfFreq();
            break;
        case kCLOCK_FroHfDiv: /* Divided by FROHF */
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case kCLOCK_Clk45M: /* CLK_45M */
            freq = CLOCK_GetClk45MFreq();
            break;
        case kCLOCK_Fro12M: /* FRO12M */
            freq = CLOCK_GetFro12MFreq();
            break;
        case kCLOCK_Fro12MDiv: /* FRO_LF_DIV */
            freq = CLOCK_GetFro12MFreq() / ((SYSCON->FROLFDIV & 0xfU) + 1U);
            break;
        case kCLOCK_Clk1M: /* CLK1M */
            freq = CLOCK_GetClk1MFreq();
            break;
        case kCLOCK_Fro16K: /* FRO16K */
            freq = CLOCK_GetFRO16KFreq();
            break;
        case kCLOCK_Clk16K0: /* CLK16K[0] */
            freq = CLOCK_GetClk16KFreq(0);
            break;
        case kCLOCK_Clk16K1: /* CLK16K[1] */
            freq = CLOCK_GetClk16KFreq(1);
            break;
        case kCLOCK_SLOW_CLK: /* SYSTEM_CLK divided by 6 */
            freq = (CLOCK_GetCoreSysClkFreq() / 6);
            break;
        default:
            freq = 0U;
            break;
    }
    return freq;
}

/* Get FRO 12M Clk */
/*! brief  Return Frequency of FRO 12MHz
 *  return Frequency of FRO 12MHz
 */
static uint32_t CLOCK_GetFro12MFreq(void)
{
    return ((SCG0->SIRCCSR & SCG_SIRCCSR_SIRC_CLK_PERIPH_EN_MASK) != 0U) ? 12000000U : 0U;
}

/* Get CLK 1M Clk */
/*! brief  Return Frequency of CLK 1MHz
 *  return Frequency of CLK 1MHz
 */
static uint32_t CLOCK_GetClk1MFreq(void)
{
    return 1000000U;
}

/* Get HF FRO Clk */
/*! brief  Return Frequency of High-Freq output of FRO
 *  return Frequency of High-Freq output of FRO
 */
static uint32_t CLOCK_GetFroHfFreq(void)
{
    uint32_t freq;

    if (((SCG0->FIRCCSR & SCG_FIRCCSR_FIRCEN_MASK) == 0U) ||
        ((SCG0->FIRCCSR & SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN_SHIFT) == 0U))
    {
        freq = 0U;
    }

    switch ((SCG0->FIRCCFG & SCG_FIRCCFG_FREQ_SEL_MASK) >> SCG_FIRCCFG_FREQ_SEL_SHIFT)
    {
        case 1U:
            freq = 45000000U;
            break;
        case 3U:
            freq = 60000000U;
            break;
        case 5U:
            freq = 90000000U;
            break;
        case 7U:
            freq = 180000000U;
            break;
        default:
            freq = 0U;
            break;
    }

    return freq;
}

/* Get HF FRO DIV Clk */
/*! brief  Return Frequency of High-Freq output of FRO
 *  return Frequency of High-Freq output of FRO
 */
static uint32_t CLOCK_GetFroHfDivFreq(void)
{
    return CLOCK_GetFroHfFreq() / ((SYSCON->FROHFDIV & SYSCON_FROHFDIV_DIV_MASK) + 1U);
}

/* Get LF FRO DIV Clk */
/*! brief  Return Frequency of High-Freq output of FRO
 *  return Frequency of High-Freq output of FRO
 */
static uint32_t CLOCK_GetFroLfDivFreq(void)
{
    return CLOCK_GetFro12MFreq() / ((SYSCON->FROLFDIV & SYSCON_FROLFDIV_DIV_MASK) + 1U);
}

/* Get CLK_45M frequency */
/*! brief  Return Frequency of CLK 45MHz
 *  return Frequency of CLK 45MHz
 */
static uint32_t CLOCK_GetClk45MFreq(void)
{
    if ((SCG0->FIRCCSR & SCG_FIRCCSR_FIRC_SCLK_PERIPH_EN_MASK) == 0U)
    {
        return 0U;
    }
    else
    {
        return 45000000U;
    }
}

/*! brief  Return Frequency of FRO16K
 *  return Frequency of FRO_16K
 */
static uint32_t CLOCK_GetFRO16KFreq(void)
{
    return ((VBAT0->FROCTLA & VBAT_FROCTLA_FRO_EN_MASK) != 0U) ? 16000U : 0U;
}
/* Get CLK 16K Clk */
/*! brief  Return Frequency of CLK 16KHz
 *  return Frequency of CLK 16KHz
 */
static uint32_t CLOCK_GetClk16KFreq(uint8_t id)
{
    return (((VBAT0->FROCTLA & VBAT_FROCTLA_FRO_EN_MASK) != 0U) &&
            ((VBAT0->FROCLKE & VBAT_FROCLKE_CLKE((((uint32_t)id) << 1U))) != 0U)) ?
               16000U :
               0U;
}

/* Get EXT OSC Clk */
/*! brief  Return Frequency of External Clock
 *  return Frequency of External Clock. If no external clock is used returns 0.
 */
static uint32_t CLOCK_GetExtClkFreq(void)
{
    return ((SCG0->SOSCCSR & SCG_SOSCCSR_SOSCVLD_MASK) != 0U) ? s_Ext_Clk_Freq : 0U;
}

/* Get MAIN Clk */
/*! brief  Return Frequency of Core System
 *  return Frequency of Core System
 */
uint32_t CLOCK_GetMainClk(void)
{
    uint32_t freq = 0U;

    switch ((SCG0->CSR & SCG_CSR_SCS_MASK) >> SCG_CSR_SCS_SHIFT)
    {
        case 1U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 2U:
            freq = CLOCK_GetFro12MFreq();
            break;
        case 3U:
            freq = CLOCK_GetFroHfFreq();
            break;
        case 4U:
            freq = CLOCK_GetClk16KFreq(1);
            break;
        default:
            freq = 0U;
            break;
    }

    return freq;
}

/*! brief  Return Frequency of core
 *  return Frequency of the core
 */
uint32_t CLOCK_GetCoreSysClkFreq(void)
{
    return CLOCK_GetMainClk() / ((SYSCON->AHBCLKDIV & SYSCON_AHBCLKDIV_DIV_MASK) + 1U);
}

/* Get CTimer Clk */
/*! brief  Return Frequency of CTimer functional Clock
 *  return Frequency of CTimer functional Clock
 */
uint32_t CLOCK_GetCTimerClkFreq(uint32_t id)
{
    uint32_t freq   = 0U;
    uint32_t clksel = 0U;
    uint32_t clkdiv = 0U;

    switch (id)
    {
        case 0U:
            clksel = MRCC0->MRCC_CTIMER0_CLKSEL;
            clkdiv = MRCC0->MRCC_CTIMER0_CLKDIV;
            break;
        case 1U:
            clksel = MRCC0->MRCC_CTIMER1_CLKSEL;
            clkdiv = MRCC0->MRCC_CTIMER1_CLKDIV;
            break;
        case 2U:
            clksel = MRCC0->MRCC_CTIMER2_CLKSEL;
            clkdiv = MRCC0->MRCC_CTIMER2_CLKDIV;
            break;
        default:
            clksel = MRCC0->MRCC_CTIMER0_CLKSEL;
            clkdiv = MRCC0->MRCC_CTIMER0_CLKDIV;
            break;
    }

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFroLfDivFreq();
            break;
        case 1U:
            freq = CLOCK_GetFroHfFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 4U:
            freq = CLOCK_GetClk16KFreq(1);
            break;
        case 5U:
            freq = CLOCK_GetClk1MFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/* Get LPI2C Clk */
/*! brief  Return Frequency of LPI2C functional Clock
 *  return Frequency of LPI2C functional Clock
 */
uint32_t CLOCK_GetLpi2cClkFreq(uint32_t id)
{
    uint32_t freq = 0U;

    uint32_t clksel = 0U;
    uint32_t clkdiv = 0U;

    switch (id)
    {
        case 0U:
            clksel = MRCC0->MRCC_LPI2C0_CLKSEL;
            clkdiv = MRCC0->MRCC_LPI2C0_CLKDIV;
            break;
        case 1U:
            clksel = MRCC0->MRCC_LPI2C1_CLKSEL;
            clkdiv = MRCC0->MRCC_LPI2C1_CLKDIV;
            break;
        default:
            clksel = MRCC0->MRCC_LPI2C0_CLKSEL;
            clkdiv = MRCC0->MRCC_LPI2C0_CLKDIV;
            break;
    }

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFroLfDivFreq();
            break;
        case 2U:
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 5U:
            freq = CLOCK_GetClk1MFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of LPSPI Clock
 *  return Frequency of LPSPI Clock
 */
uint32_t CLOCK_GetLpspiClkFreq(uint32_t id)
{
    uint32_t freq   = 0U;
    uint32_t clksel = (0U == id) ? (MRCC0->MRCC_LPSPI0_CLKSEL) : (MRCC0->MRCC_LPSPI1_CLKSEL);
    uint32_t clkdiv = (0U == id) ? (MRCC0->MRCC_LPSPI0_CLKDIV) : (MRCC0->MRCC_LPSPI1_CLKDIV);

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFroLfDivFreq();
            break;
        case 2U:
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 5U:
            freq = CLOCK_GetClk1MFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of LPUART Clock
 *  return Frequency of LPUART Clock
 */
uint32_t CLOCK_GetLpuartClkFreq(uint32_t id)
{
    uint32_t freq   = 0U;
    uint32_t clksel = 0U;
    uint32_t clkdiv = 0U;

    switch (id)
    {
        case 0U:
            clksel = MRCC0->MRCC_LPUART0_CLKSEL;
            clkdiv = MRCC0->MRCC_LPUART0_CLKDIV;
            break;
        case 1U:
            clksel = MRCC0->MRCC_LPUART1_CLKSEL;
            clkdiv = MRCC0->MRCC_LPUART1_CLKDIV;
            break;
        case 2U:
            clksel = MRCC0->MRCC_LPUART2_CLKSEL;
            clkdiv = MRCC0->MRCC_LPUART2_CLKDIV;
            break;
        case 3U:
            clksel = MRCC0->MRCC_LPUART3_CLKSEL;
            clkdiv = MRCC0->MRCC_LPUART3_CLKDIV;
            break;
        default:
            clksel = MRCC0->MRCC_LPUART0_CLKSEL;
            clkdiv = MRCC0->MRCC_LPUART0_CLKDIV;
            break;
    }

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFroLfDivFreq();
            break;
        case 2U:
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 4U:
            freq = CLOCK_GetClk16KFreq(1);
            break;
        case 5U:
            freq = CLOCK_GetClk1MFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of LPTMR Clock
 *  return Frequency of LPTMR Clock
 */
uint32_t CLOCK_GetLptmrClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = (MRCC0->MRCC_LPTMR0_CLKSEL);
    uint32_t clkdiv = (MRCC0->MRCC_LPTMR0_CLKDIV);

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFroLfDivFreq();
            break;
        case 2U:
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 5U:
            freq = CLOCK_GetClk1MFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of OSTIMER
 *  return Frequency of OSTIMER Clock
 */
uint32_t CLOCK_GetOstimerClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = (MRCC0->MRCC_OSTIMER0_CLKSEL);

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetClk16KFreq(1);
            break;
        case 2U:
            freq = CLOCK_GetClk1MFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq;
}

/*! brief  Return Frequency of Adc Clock
 *  return Frequency of Adc.
 */
uint32_t CLOCK_GetAdcClkFreq(uint32_t id)
{
    uint32_t freq = 0U;

    uint32_t clksel = MRCC0->MRCC_ADC_CLKSEL;
    uint32_t clkdiv = MRCC0->MRCC_ADC_CLKDIV;

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFroLfDivFreq();
            break;
        case 1U:
            freq = CLOCK_GetFroHfFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 5U:
            freq = CLOCK_GetClk1MFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of CMP Function Clock
 *  return Frequency of CMP Function.
 */
uint32_t CLOCK_GetCmpFClkFreq(uint32_t id)
{
    uint32_t freq   = 0U;
    uint32_t clksel = 0U;
    uint32_t clkdiv = 0U;

    switch (id)
    {
        case 0U:
            clksel = MRCC0->MRCC_CMP0_RR_CLKSEL;
            clkdiv = MRCC0->MRCC_CMP0_FUNC_CLKDIV;
            break;
        case 1U:
            clksel = MRCC0->MRCC_CMP1_RR_CLKSEL;
            clkdiv = MRCC0->MRCC_CMP1_FUNC_CLKDIV;
            break;
        case 2U:
            clksel = MRCC0->MRCC_CMP2_RR_CLKSEL;
            clkdiv = MRCC0->MRCC_CMP2_FUNC_CLKDIV;
            break;
        default:
            clksel = MRCC0->MRCC_CMP0_RR_CLKSEL;
            clkdiv = MRCC0->MRCC_CMP0_FUNC_CLKDIV;
            break;
    }

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFroLfDivFreq();
            break;
        case 2U:
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 5U:
            freq = CLOCK_GetClk1MFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of CMP Round Robin Clock
 *  return Frequency of CMP Round Robin.
 */
uint32_t CLOCK_GetCmpRRClkFreq(uint32_t id)
{
    uint32_t freq   = 0U;
    uint32_t clksel = 0U;
    uint32_t clkdiv = 0U;

    switch (id)
    {
        case 0U:
            clksel = MRCC0->MRCC_CMP0_RR_CLKSEL;
            clkdiv = MRCC0->MRCC_CMP0_RR_CLKDIV;
            break;
        case 1U:
            clksel = MRCC0->MRCC_CMP1_RR_CLKSEL;
            clkdiv = MRCC0->MRCC_CMP1_RR_CLKDIV;
            break;
        case 2U:
            clksel = MRCC0->MRCC_CMP2_RR_CLKSEL;
            clkdiv = MRCC0->MRCC_CMP2_RR_CLKDIV;
            break;
        default:
            clksel = MRCC0->MRCC_CMP0_RR_CLKSEL;
            clkdiv = MRCC0->MRCC_CMP0_RR_CLKDIV;
            break;
    }

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFroLfDivFreq();
            break;
        case 2U:
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 5U:
            freq = CLOCK_GetClk1MFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of Trace Clock
 *  return Frequency of Trace.
 */
uint32_t CLOCK_GetTraceClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = (MRCC0->MRCC_DBG_TRACE_CLKSEL);
    uint32_t clkdiv = (MRCC0->MRCC_DBG_TRACE_CLKDIV);

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetCoreSysClkFreq();
            break;
        case 1U:
            freq = CLOCK_GetClk1MFreq();
            break;
        case 2U:
            freq = CLOCK_GetClk16KFreq(1);
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of CLKOUT Clock
 *  return Frequency of CLKOUT.
 */
uint32_t CLOCK_GetClkoutClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = (MRCC0->MRCC_CLKOUT_CLKSEL);
    uint32_t clkdiv = (MRCC0->MRCC_CLKOUT_CLKDIV);

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetFro12MFreq();
            break;
        case 1U:
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case 2U:
            freq = CLOCK_GetExtClkFreq();
            break;
        case 3U:
            freq = CLOCK_GetClk16KFreq(1);
            break;
        case 6U:
            freq = CLOCK_GetFreq(kCLOCK_SLOW_CLK);
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of WWDT Clock
 *  return Frequency of WWDT.
 */
uint32_t CLOCK_GetWwdtClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clkdiv = (MRCC0->MRCC_WWDT0_CLKDIV);

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    freq = CLOCK_GetClk1MFreq();

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of FlexCAN FCLK
 *  return Frequency of FlexCAN FCLK.
 */
uint32_t CLOCK_GetFlexcanClkFreq(void)
{
    uint32_t freq = 0U;

    uint32_t clksel = MRCC0->MRCC_FLEXCAN0_CLKSEL;
    uint32_t clkdiv = MRCC0->MRCC_FLEXCAN0_CLKDIV;

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    switch (clksel)
    {
        case 1U:
            freq = CLOCK_GetFroHfFreq();
            break;
        case 2U:
            freq = CLOCK_GetFroHfDivFreq();
            break;
        case 3U:
            freq = CLOCK_GetExtClkFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/**
 * @brief   Setup FRO 12M trim.
 * @param   config   : FRO 12M trim value
 * @return  returns success or fail status.
 */
status_t CLOCK_FRO12MTrimConfig(sirc_trim_config_t config)
{
    SCG0->SIRCTCFG = SCG_SIRCTCFG_TRIMDIV(config.trimDiv) | SCG_SIRCTCFG_TRIMSRC(config.trimSrc);

    if (kSCG_SircTrimNonUpdate == config.trimMode)
    {
        SCG0->SIRCSTAT = SCG_SIRCSTAT_CCOTRIM(config.cltrim);
        SCG0->SIRCSTAT = SCG_SIRCSTAT_CCOTRIM(config.ccotrim);
    }

    /* Set trim mode. */
    SCG0->SIRCCSR =
        (SCG0->SIRCCSR & ~(SCG_SIRCCSR_SIRCTREN_MASK | SCG_SIRCCSR_SIRCTRUP_MASK)) | (uint32_t)config.trimMode;

    if ((SCG0->SIRCCSR & SCG_SIRCCSR_SIRCVLD_MASK) == 0U)
    {
        return (status_t)kStatus_Fail;
    }

    if ((SCG0->SIRCCSR & SCG_SIRCCSR_SIRCERR_MASK) == SCG_SIRCCSR_SIRCERR_MASK)
    {
        return (status_t)kStatus_Fail;
    }

    if ((SCG0->SIRCCSR & SCG_SIRCCSR_TRIM_LOCK_MASK) == 0U)
    {
        return (status_t)kStatus_Fail;
    }

    return (status_t)kStatus_Success;
}

/*!
 * @brief Sets the system OSC monitor mode.
 *
 * This function sets the system OSC monitor mode. The mode can be disabled,
 * it can generate an interrupt when the error is disabled, or reset when the
 * error is detected.
 *
 * @param mode Monitor mode to set.
 */
void CLOCK_SetSysOscMonitorMode(scg_sosc_monitor_mode_t mode)
{
    uint32_t reg = SCG0->SOSCCSR;

    reg &= ~(SCG_SOSCCSR_SOSCCM_MASK | SCG_SOSCCSR_SOSCCMRE_MASK);

    reg |= (uint32_t)mode;

    SCG0->SOSCCSR = reg;
}

/*!
 * @brief   Set the additional number of wait-states added to account for the
 * ratio of system clock period to flash access time during full speed power
 * mode.
 * @param   system_freq_hz  : Input frequency
 * @param   mode            : Active run mode (voltage level).
 * @return  success or fail status
 */
status_t CLOCK_SetFLASHAccessCyclesForFreq(uint32_t system_freq_hz, run_mode_t mode)
{
    uint32_t num_wait_states_added = 3UL; /* Default 3 additional wait states */
    switch ((uint32_t)mode)
    {
        case (uint32_t)kMD_Mode:
        {
            if (system_freq_hz > 45000000U)
            {
                return kStatus_Fail;
            }
            else if (system_freq_hz > 22500000U)
            {
                num_wait_states_added = 1U;
            }
            else
            {
                num_wait_states_added = 0U;
            }
            break;
        }
        case (uint32_t)kOD_Mode:
        {
            if (system_freq_hz > 180000000U)
            {
                return kStatus_Fail;
            }
            else if (system_freq_hz > 90000000U)
            {
                num_wait_states_added = 4U;
            }
            else if (system_freq_hz > 60000000U)
            {
                num_wait_states_added = 2U;
            }
            else if (system_freq_hz > 36000000U)
            {
                num_wait_states_added = 1U;
            }
            else
            {
                num_wait_states_added = 0U;
            }
            break;
        }
        default:
            num_wait_states_added = 0U;
            break;
    }

    /* additional wait-states are added */
    FMU0->FCTRL = (FMU0->FCTRL & ~FMU_FCTRL_RWSC_MASK) | FMU_FCTRL_RWSC(num_wait_states_added);

    return kStatus_Success;
}