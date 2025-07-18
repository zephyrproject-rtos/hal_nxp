/*
 * Copyright 2023-2025, NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 O Add AON connection
 O Add setting of connections
 O Add Initialization of AON clocks
 O Add handling of AON dividers
 O add ifdefs to be able to compile on AON
 O Readouts of AON frequencies?
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
/*! @brief External RTC XTAL32K clock frequency. */
volatile uint32_t g_xtal32Freq;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/* Get get AON FRO10/2M Clk */
static uint32_t CLOCK_GetFroAonFreq(void);
/* Get RTC OSC Clk */
static uint32_t CLOCK_GetRtcOscFreq(void);

#if __CORTEX_M == (33U) /* Building on the main core */
/* Get Main_Clk */
static uint32_t CLOCK_GetMainClk(void);
/* Get FRO 12M Clk */
static uint32_t CLOCK_GetFro12MFreq(void);
/* Get CLK 1M Clk */
static uint32_t CLOCK_GetClk1MFreq(void);
/* Get HF FRO Clk */
static uint32_t CLOCK_GetFroHfFreq(void);
/* Get CLK 16K Clk */
static uint32_t CLOCK_GetClk16KFreq(void);
/* Get SOSC OSC Clk */
static uint32_t CLOCK_GetSysOscFreq(void);

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
#endif /* Building on the main core */

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
 * This fuction uses the offset in input attach id, then it reads the actual source value in
 * the register and combine the offset to obtain an actual attach id.
 * param   connection  : Clock attach id to get.
 * return  Clock source value.
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
    const uint32_t reg_offset = (uint32_t) sel_name;

    if (CLK_OF_AON_SEL(reg_offset))
    {
        const uint32_t aon_reg_offset = CLK_AON_SEL_REG_OFFSET(reg_offset);
        const uint32_t aon_reg_shift = CLK_AON_SEL_SHIFT(reg_offset);
        const uint32_t aon_reg_mask = CLK_AON_SEL_MASK(reg_offset);

        volatile uint32_t *pClkReg = (volatile uint32_t *)(AON__CGU_BASE + aon_reg_offset);

        uint32_t val = *pClkReg;
        val &= ~(aon_reg_mask << aon_reg_shift);
        val |= value << aon_reg_shift;

        *pClkReg = val;
    }
#if __CORTEX_M == (33U) /* Building on the main core */
    else
    {
        volatile uint32_t *pClkCtrl = (volatile uint32_t *)(MRCC_BASE + reg_offset);

        if (sel_name == kCLOCK_SelSCGSCS)
        {
            SCG0->RCCR = (SCG0->RCCR & ~(SCG_RCCR_SCS_MASK)) | SCG_RCCR_SCS(value);
            while ((SCG0->CSR & SCG_CSR_SCS_MASK) != SCG_CSR_SCS(value))
            {
            }
        }
        else if (sel_name == kCLOCK_SelFIRC)
        {
            SCG0->FIRCCFG = (SCG0->FIRCCFG & ~(SCG_FIRCCFG_DIV2_SEL_MASK)) | SCG_FIRCCFG_DIV2_SEL(value);
        }
        else
        {
            /* Unlock clock configuration */
            SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK;

            *pClkCtrl = value;

            /* Freeze clock configuration */
            SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK;
        }
    }
#endif /* Building on the main core */
}

/* Get the clock selection value */
uint32_t CLOCK_GetClockSelect(clock_select_name_t sel_name)
{
    uint32_t actual_sel = 0U;
    const uint32_t reg_offset = (uint32_t) sel_name;

    if (CLK_OF_AON_SEL(reg_offset))
    {
        const uint32_t aon_reg_offset = CLK_AON_SEL_REG_OFFSET(reg_offset);
        const uint32_t aon_reg_shift = CLK_AON_SEL_SHIFT(reg_offset);
        const uint32_t aon_reg_mask = CLK_AON_SEL_MASK(reg_offset);

        volatile uint32_t *pClkReg = (volatile uint32_t *)(AON__CGU_BASE + aon_reg_offset);

        actual_sel = *pClkReg;
        actual_sel >>= aon_reg_shift;
        actual_sel &= aon_reg_mask;
    }
#if __CORTEX_M == (33U) /* Building on the main core */
    else
    {
        volatile uint32_t *pClkCtrl = (volatile uint32_t *)(MRCC_BASE + reg_offset);

        if (sel_name == kCLOCK_SelSCGSCS)
        {
            actual_sel = (uint32_t)((SCG0->RCCR & SCG_RCCR_SCS_MASK) >> SCG_RCCR_SCS_SHIFT);
        }
        else if (sel_name == kCLOCK_SelFIRC)
        {
            actual_sel = (uint32_t)((SCG0->FIRCCFG & SCG_FIRCCFG_DIV2_SEL_MASK) >> SCG_FIRCCFG_DIV2_SEL_SHIFT);
        }
        else
        {
            actual_sel = *pClkCtrl;
        }
    }
#endif /* Building on the main core */

    return actual_sel;
}

/* Set the clock divider value */
void CLOCK_SetClockDiv(clock_div_name_t div_name, uint32_t value)
{
    assert(div_name <= kCLOCK_DivMax);

    if(div_name >= 0x400U)
    { /* AON clk*/
        if(div_name == 0x410U)
        {   /* AON ACMP CLK 0*/
            if(value==0)
            {
                AON__CGU->ACMP_CLK_DIV &= ~(CGU_ACMP_CLK_DIV_ACMP0_CLK_EN_MASK);
                AON__CGU->ACMP_CLK_DIV &= ~(CGU_ACMP_CLK_DIV_ACMP_CLK0_DIV_EN_MASK);
            }
            else
            {
                AON__CGU->ACMP_CLK_DIV &= ~(CGU_ACMP_CLK_DIV_AON_ACMP_CLK0_DIV_MASK);
                AON__CGU->ACMP_CLK_DIV |= (value-1U) << CGU_ACMP_CLK_DIV_AON_ACMP_CLK0_DIV_SHIFT;

                AON__CGU->ACMP_CLK_DIV |= CGU_ACMP_CLK_DIV_ACMP_CLK0_DIV_EN_MASK;
                AON__CGU->ACMP_CLK_DIV |= CGU_ACMP_CLK_DIV_ACMP0_CLK_EN_MASK;
            }
        }
        else if(div_name == 0x411U)
        {   /* AON ACMP CLK 1*/
            if(value==0)
            {
                AON__CGU->ACMP_CLK_DIV &= ~(CGU_ACMP_CLK_DIV_ACMP1_CLK_EN_MASK);
                AON__CGU->ACMP_CLK_DIV &= ~(CGU_ACMP_CLK_DIV_ACMP_CLK1_DIV_EN_MASK);
            }
            else
            {
                AON__CGU->ACMP_CLK_DIV &= ~(CGU_ACMP_CLK_DIV_AON_ACMP_CLK1_DIV_MASK);
                AON__CGU->ACMP_CLK_DIV |= (value-1U) << CGU_ACMP_CLK_DIV_AON_ACMP_CLK1_DIV_SHIFT;

                AON__CGU->ACMP_CLK_DIV |= CGU_ACMP_CLK_DIV_ACMP_CLK1_DIV_EN_MASK;
                AON__CGU->ACMP_CLK_DIV |= CGU_ACMP_CLK_DIV_ACMP1_CLK_EN_MASK;
            }

        }
        else
        {   /* The rest of AON */
            const uint32_t en_shift = div_name & 0x3U;
            const uint32_t div_shift = 3U*(en_shift+1U);
            uint32_t reg_val = AON__CGU->CLOCK_DIV;

            assert((value <= 8U) && (value > 0U));

            reg_val &= ~((7U << div_shift) | (1U << en_shift));
            reg_val |= (value - 1U) << div_shift;
            if(value >= 1U )
            {
                /* enable divider */
                reg_val |= 1U << en_shift;
            }

            AON__CGU->CLOCK_DIV = reg_val;
        }
    }
#if __CORTEX_M == (33U) /* Building on the main core */
    else
    {
      volatile uint32_t *pDivCtrl;

          /* Unlock clock configuration */
      SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK;

      if ((div_name == kCLOCK_DivAHBCLK)  || (div_name == kCLOCK_DivAHBAIPSCLK))
      {
          pDivCtrl = (volatile uint32_t *)(SYSCON_BASE + (uint32_t)div_name);
          *pDivCtrl = (value - 1U);
      }
      else
      {
          pDivCtrl = (volatile uint32_t *)(MRCC_BASE + (uint32_t)div_name);

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
      }

      /* Freeze clock configuration */
      SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK;
    }
#endif /* Building on the main core */
}

/* Get the clock divider value */
uint32_t CLOCK_GetClockDiv(clock_div_name_t div_name)
{
    assert(div_name <= kCLOCK_DivMax);

    if(div_name >= 0x400)
    { /* AON clk*/
        if(div_name == 0x410U)
        {   /* AON ACMP CLK 0*/
            uint32_t reg_val = AON__CGU->ACMP_CLK_DIV;
            if((!(reg_val & CGU_ACMP_CLK_DIV_ACMP0_CLK_EN_MASK)) ||
               (!(reg_val & CGU_ACMP_CLK_DIV_ACMP_CLK0_DIV_EN_MASK)))
            {
                return 0; /* Not enabled clk or div*/
            }
            else
            {
                reg_val &=  CGU_ACMP_CLK_DIV_AON_ACMP_CLK0_DIV_MASK;
                reg_val >>=  CGU_ACMP_CLK_DIV_AON_ACMP_CLK0_DIV_SHIFT;
                return reg_val + 1U;
            }
        }
        else if(div_name == 0x411U)
        {   /* AON ACMP CLK 1*/
            uint32_t reg_val = AON__CGU->ACMP_CLK_DIV;
            if((!(reg_val & CGU_ACMP_CLK_DIV_ACMP1_CLK_EN_MASK)) ||
               (!(reg_val & CGU_ACMP_CLK_DIV_ACMP_CLK1_DIV_EN_MASK)))
            {
                return 0; /* Not enabled clk or div*/
            }
            else
            {
                reg_val &=  CGU_ACMP_CLK_DIV_AON_ACMP_CLK1_DIV_MASK;
                reg_val >>=  CGU_ACMP_CLK_DIV_AON_ACMP_CLK1_DIV_SHIFT;
                return reg_val + 1U;
            }
        }
        else
        {   /* The rest of AON */
            const uint32_t en_shift = div_name & 0x3U;
            uint32_t reg_val = AON__CGU->CLOCK_DIV;

            const uint32_t enabled = reg_val & (1U << en_shift);
            if(enabled)
            {
                const uint32_t div_shift = 3U*(en_shift+1U);
                const uint32_t value = reg_val & (7U << div_shift);

                return value + 1U;
            }
            else
            {
                return 0;
            }
        }
    }
#if __CORTEX_M == (33U) /* Building on the main core */
    else
    {
        volatile uint32_t *pDivCtrl = (volatile uint32_t *)(MRCC_BASE + (uint32_t)div_name);

        if (((*pDivCtrl) & (1UL << 30U)) != 0U)
        {
            return 0;
        }
        else
        {
            return ((*pDivCtrl & 0xFFU) + 1U);
        }
    }
#else /* Building on AON */
    return 0U;
#endif
}

/* Halt the clock divider value */
void CLOCK_HaltClockDiv(clock_div_name_t div_name)
{
    assert(div_name <= kCLOCK_DivMax);

    if(div_name >= 0x400)
    { /* AON clk*/
        if(div_name == 0x410U)
        {   /* AON ACMP CLK 0*/
            AON__CGU->ACMP_CLK_DIV &= ~(CGU_ACMP_CLK_DIV_ACMP_CLK0_DIV_EN_MASK);
        }
        else if(div_name == 0x411U)
        {   /* AON ACMP CLK 1*/
            AON__CGU->ACMP_CLK_DIV &= ~(CGU_ACMP_CLK_DIV_ACMP_CLK1_DIV_EN_MASK);
        }
        else
        {   /* The rest of AON */
            const uint32_t en_shift = div_name & 0x3U;
            AON__CGU->CLOCK_DIV &= ~(1U << en_shift);
        }
    }
#if __CORTEX_M == (33U) /* Building on the main core */
    else
    {
        volatile uint32_t *pDivCtrl = (volatile uint32_t *)(MRCC_BASE + (uint32_t)div_name);

        /* Unlock clock configuration */
        SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK;

        *pDivCtrl |= (1UL << 30U);

        /* Freeze clock configuration */
        SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK;
    }
#endif
}

/* Initialize the FROHF to given frequency (10M, 2M) */
status_t CLOCK_SetupFROAonClocking(uint32_t iFreq)
{
    switch(iFreq)
    {
        case 10000000U:
            AON__CGU->CLK_CONFIG &= ~(1U << CGU_CLK_CONFIG_SEL_MODE_SHIFT);
            AON__CGU->CLK_CONFIG |= 1U << CGU_CLK_CONFIG_FRO10M_EN_SHIFT;
            break;
        case 2000000U:
            AON__CGU->CLK_CONFIG |= CGU_CLK_CONFIG_FRO2M_EN_MASK;
            AON__CGU->CLK_CONFIG |= 1U << CGU_CLK_CONFIG_SEL_MODE_SHIFT;
            AON__CGU->CLK_CONFIG |= 1U << CGU_CLK_CONFIG_FRO10M_EN_SHIFT;
            break;
        case 0U:
            /* Turn off */
            AON__CGU->CLK_CONFIG &= ~(1U << CGU_CLK_CONFIG_FRO10M_EN_SHIFT);
            break;
        default:
            return kStatus_Fail;
    }

    return (status_t)kStatus_Success;
}

#if __CORTEX_M == (33U) /* Building on the main core */

/* Initialize the FROHF to given frequency */
status_t CLOCK_SetupFROHFClocking(uint32_t iFreq, uint8_t div_sel)
{
    uint8_t freq_select = 0x0U;
    switch (iFreq)
    {
        case 36000000U:
            freq_select = 0U;
            break;
        case 40000000U:
            freq_select = 2U;
            break;
        case 48000000U:
            freq_select = 3U;
            break;
        case 72000000U:
            freq_select = 4U;
            break;
        case 80000000U:
            freq_select = 6U;
            break;
        case 96000000U:
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
    /* Set FIRC Divider */
    SCG0->FIRCCFG |= SCG_FIRCCFG_DIV2_SEL(div_sel);
    /* Unlock FIRCCSR */
    SCG0->FIRCCSR &= ~SCG_FIRCCSR_LK_MASK;

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

    return (status_t)kStatus_Success;
}

/* Initialize the FRO12M. */
status_t CLOCK_SetupFRO12MClocking(void)
{
    /* Unlock SIRCCSR */
    SCG0->SIRCCSR &= ~SCG_SIRCCSR_LK_MASK;

    /* Enable FRO12M clock for peripheral use */
    SCG0->SIRCCSR |= SCG_SIRCCSR_SIRC_CLK_PERIPH_EN_MASK;
    /* Enable FRO12M clock for Flash use */
    SCG0->SIRCCSR |= SCG_SIRCCSR_SIRC_CLK_FLASH_EN_MASK;

    /* Lock SIRCCSR */
    SCG0->SIRCCSR |= SCG_SIRCCSR_LK_MASK;

    /* Wait for SIRC clock to be valid. */
    while ((SCG0->SIRCCSR & SCG_SIRCCSR_SIRCVLD_MASK) == 0U)
    {
    }

    return (status_t)kStatus_Success;
}

/*!
 * brief Initializes the SCG ROSC.
 *
 * This function enables the SCG ROSC clock according to the
 * configuration.
 *
 * param config   Pointer to the configuration structure.
 * retval kStatus_Success ROSC is initialized.
 * retval kStatus_Busy ROSC has been enabled and is used by the system clock.
 * retval kStatus_ReadOnly ROSC control register is locked.
 *
 * note This function can't detect whether the system OSC has been enabled and
 * used by an IP.
 */
status_t CLOCK_InitRosc(const scg_rosc_config_t *config)
{
    assert(config);
    status_t status;

    /* De-init the ROSC first. */
    status = CLOCK_DeinitRosc();

    if (kStatus_Success != status)
    {
        return status;
    }

    CLOCK_SetRoscMonitorMode(config->monitorMode);

    /* Wait for ROSC clock to be valid. */
    while ((SCG0->ROSCCSR & SCG_ROSCCSR_ROSCVLD_MASK) != SCG_ROSCCSR_ROSCVLD_MASK)
    {
    }

    return (status_t)kStatus_Success;
}

/*!
 * brief De-initializes the SCG ROSC.
 *
 * This function disables the SCG ROSC clock.
 *
 * retval kStatus_Success System OSC is deinitialized.
 * retval kStatus_Busy System OSC is used by the system clock.
 * retval kStatus_ReadOnly System OSC control register is locked.
 *
 * note This function can't detect whether the ROSC is used by an IP.
 */
status_t CLOCK_DeinitRosc(void)
{
    uint32_t reg = SCG0->ROSCCSR;

    /* If clock is used by system, return error. */
    if ((reg & SCG_ROSCCSR_ROSCSEL_MASK) == SCG_ROSCCSR_ROSCSEL_MASK)
    {
        return (status_t)kStatus_Busy;
    }

    /* If configure register is locked, return error. */
    if ((reg & SCG_ROSCCSR_LK_MASK) == SCG_ROSCCSR_LK_MASK)
    {
        return (status_t)kStatus_ReadOnly;
    }

    /* De-initializes the SCG ROSC */
    

    return (status_t)kStatus_Success;
}

#endif /* Building on the main core */

/* Get IP Clk */
/*! brief  Return Frequency of selected clock
 *  return Frequency of selected clock
 */
uint32_t CLOCK_GetFreq(clock_name_t clockName)
{
    uint32_t freq = 0U;

    switch (clockName)
    {
#if __CORTEX_M == (33U) /* Building on the main core */
        case kCLOCK_MainClk: /* MAIN_CLK */
            freq = CLOCK_GetMainClk();
            break;
        case kCLOCK_CoreSysClk: /* Core/system clock(CPU_CLK) */
            freq = CLOCK_GetCoreSysClkFreq();
            break;
        case kCLOCK_SYSTEM_CLK: /* AHB clock */
            freq = CLOCK_GetCoreSysClkFreq();
            break;
        case kCLOCK_BusClk: /* Bus clock (AHB clock) */
            freq = CLOCK_GetCoreSysClkFreq();
            break;
        case kCLOCK_RtcOscClk: /* External Clock */
            freq = CLOCK_GetRtcOscFreq();
            break;
        case kCLOCK_FroHf: /* FROHF */
            freq = CLOCK_GetFroHfFreq();
            break;
        case kCLOCK_FroHfDiv: /* Divided by FROHF */
            freq = CLOCK_GetFroHfFreq() / ((MRCC->FROHFDIV & 0xFU) + 1U);
            break;
        case kCLOCK_Fro12M: /* FRO12M */
            freq = CLOCK_GetFro12MFreq();
            break;
        case kCLOCK_FlashCLK: /* Sirc FLASH clock */
            freq = CLOCK_GetFlashClkFreq();
            break;
        case kCLOCK_Clk1M: /* CLK1M */
            freq = CLOCK_GetClk1MFreq();
            break;
        case kCLOCK_Clk16K: /* CLK16K[0] */
            freq = CLOCK_GetClk16KFreq();
            break;
        case kCLOCK_SLOW_CLK: /* SYSTEM_CLK divided by 4 */
            freq = CLOCK_GetCoreSysClkFreq() >> 2U;
            break;
#endif /* Building on the main core */
        case kCLOCK_Fro16k: /* AON PAC and SMM clock. */
            freq = 16000U;
            break;
        case kCLOKC_FroAON: /* AON functional clock. this is wrong add kCLOKC_FroAON */
            freq = CLOCK_GetFroAonFreq();
            break;
        default:
            freq = 0U;
            break;
    }
    return freq;
}

static uint32_t CLOCK_GetAonRootAuxFreq(void)
{
    uint32_t freq = 0U;

    if(AON__CGU->CLK_CONFIG & CGU_CLK_CONFIG_ROOT_AUX_CLK_EN_MASK)
    {
        if(AON__CGU->CLK_CONFIG & CGU_CLK_CONFIG_ROOT_AUX_CLK_SEL_MASK)
        {
            freq = 1U; /* FIXME how to get aon_aux_clk freq?*/
        }
        else
        {
            freq = CLOCK_GetRtcOscFreq();
        }
    }
    return freq;
}

static uint32_t CLOCK_GetAonFroFreq(void)
{
    uint32_t freq = 0U;

    if(AON__CGU->CLK_CONFIG & CGU_CLK_CONFIG_FRO10M_EN_MASK)
    {
        if(AON__CGU->CLK_CONFIG & CGU_CLK_CONFIG_SEL_MODE_MASK)
        {
            freq = 2000000U;
        }
        else
        {
            freq = 10000000U;
        }
    }
    return freq;
}

static uint32_t CLOCK_getAonPerClkFreq(void)
{
    uint32_t freq = 0U;

    if(AON__CGU->CLOCK_DIV & CGU_CLOCK_DIV_COM_GRP_CLK_EN_MASK)
    {
        const uint32_t sel = (AON__CGU->PER_CLK_CONFIG &
                        CGU_PER_CLK_CONFIG_COM_GRP_SEL_MASK) >>
                       CGU_PER_CLK_CONFIG_COM_GRP_SEL_SHIFT;
        const uint32_t div = (AON__CGU->CLOCK_DIV &
                        CGU_CLOCK_DIV_COM_GRP_CLK_DIV_MASK) >>
                       CGU_CLOCK_DIV_COM_GRP_CLK_DIV_SHIFT;

        switch(sel)
        {
            case 0U:
              freq = CLOCK_GetAonFroFreq();
              break;
            case 1U:
              freq = CLOCK_GetAonFroFreq() / 2U;
              break;
            case 2U:
              freq = CLOCK_GetAonFroFreq() / 4U;
              break;
            case 3U:
              freq = CLOCK_GetAonRootAuxFreq();
              break;
        }

        freq /= div + 1U;
    }
    return freq;
}

#if __CORTEX_M == (33U) /* Building on the main core */
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
    uint8_t div_sel = (SCG0->FIRCCFG & SCG_FIRCCFG_DIV2_SEL_MASK) >> SCG_FIRCCFG_DIV2_SEL_SHIFT;

    if (((SCG0->FIRCCSR & SCG_FIRCCSR_FIRCEN_MASK) == 0U) ||
        ((SCG0->FIRCCSR & SCG_FIRCCSR_FIRC_FCLK_PERIPH_EN_SHIFT) == 0U))
    {
        freq = 0U;
    }

    switch ((SCG0->FIRCCFG & SCG_FIRCCFG_FREQ_SEL_MASK) >> SCG_FIRCCFG_FREQ_SEL_SHIFT)
    {
        case 0U:
            freq = 36000000U / (div_sel + 1U);
            break;
        case 2U:
            freq = 40000000U / (div_sel + 1U);
            break;
        case 3U:
            freq = 48000000U / (div_sel + 1U);
            break;
        case 4U:
            freq = 72000000U / (div_sel + 1U);
            break;
        case 6U:
            freq = 80000000U / (div_sel + 1U);
            break;
        case 7U:
            freq = 96000000U / (div_sel + 1U);
            break;
        default:
            freq = 0U;
            break;
    }

    return freq;
}

#endif /* Building on the main core */

/*!
 * @brief Gets the SCG RTC OSC clock frequency.
 *
 * @return  Clock frequency; If the clock is invalid, returns 0.
 */
uint32_t CLOCK_GetRtcOscFreq(void)
{
#if __CORTEX_M == (33U) /* Building on the main core */ /* FIXME how is RTC generated? */
    if ((SCG0->ROSCCSR & SCG_ROSCCSR_ROSCVLD_MASK) != SCG_ROSCCSR_ROSCVLD_MASK) /* RTC OSC clock is not valid. */
    {
        return 0U;
    }
    else
#endif
    {
        /* Please call CLOCK_SetXtal32Freq base on board setting before using RTC OSC clock. */
        assert(g_xtal32Freq);
        return g_xtal32Freq;
    }
}

#if __CORTEX_M == (33U) /* Building on the main core */

/*!
 * @brief Gets the SOSC system crystal oscilator clock frequency.
 *
 * @return  Clock frequency; If the clock is invalid, returns 0.
 */
static uint32_t CLOCK_GetSysOscFreq(void)
{
    if ((SCG0->ROSCCSR & SCG_ROSCCSR_ROSCVLD_MASK) == SCG_ROSCCSR_ROSCVLD_MASK) /* SOSC clock is valid. */
    {
        /* Please call CLOCK_SetXtal32Freq base on board setting before using RTC OSC clock. */
        assert(g_xtal32Freq);
        return g_xtal32Freq;
    }
    else
    {
        return 0U;
    }
}

/*!
 * @brief Gets the peripheral group N clock frequency.
 * @param id   Selects group 0 or 1
 *
 * @return  Clock frequency.
 */
static uint32_t CLOCK_GetPeriphGrpFreq(uint32_t id)
{
    uint32_t freq   =  0U;
    uint32_t clksel = (0U == id) ? (MRCC->PGRP0CLKSEL) : (MRCC->PGRP1CLKSEL);
    uint32_t clkdiv = (0U == id) ? (MRCC->PGRP0CLKDIV) : (MRCC->PGRP1CLKDIV);

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
            freq = CLOCK_GetRtcOscFreq();
            break;
        case 2U:
            freq = CLOCK_GetClk16KFreq();
            break;
        case 3U:
            freq = CLOCK_GetFroHfFreq() / ((MRCC->FROHFDIV & 0xFU) + 1U);
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}


/* Get CLK 16K Clk */
/*! brief  Return Frequency of CLK 16KHz
 *  return Frequency of CLK 16KHz
 */
static uint32_t CLOCK_GetClk16KFreq(void)
{
    return (CLOCK_GetRtcOscFreq() / 2U);
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
          case 1U: /* SOSC System Crystal Oscillator Clock */
            freq = CLOCK_GetSysOscFreq();
            break;
          case 2U: /* SIRC FRO12M*/
            freq = 12000000U; /* SIRC fro_12m ungated clock */
            break;
          case 3U: /* FIRC FRO96M*/
            freq = CLOCK_GetFroHfFreq();
            break;
          case 4U: /* ROSC XTAL32K*/
            freq = CLOCK_GetRtcOscFreq();
            break;
          case 9U: /* PMUIRC FRO16K*/
            freq = 16000U;
            break;
          case 10U: /* LPIRC FRO10M*/
            freq = 10000000U;
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
    return CLOCK_GetMainClk() / ((SYSCON->AHBCLKDIV & 0xFFU) + 1U);
}

/* Get FRO 12M FLASH Clk */
/*! brief  Return Frequency of flash
 *  return Frequency of flash 12M clock
 */
uint32_t CLOCK_GetFlashClkFreq(void)
{
    return ((SCG0->SIRCCSR & SCG_SIRCCSR_SIRC_CLK_FLASH_EN_MASK) != 0U) ? 12000000U : 0U;
}

/* Get CTimer Clk */
/*! brief  Return Frequency of CTimer functional Clock
 *  return Frequency of CTimer functional Clock
 */
uint32_t CLOCK_GetCTimerClkFreq(uint32_t id)
{
    uint32_t freq   = 0U;
    uint32_t clksel = (0U == id) ? (MRCC->CTIMERGRP0CLKSEL) : (MRCC->CTIMERGRP1CLKSEL);
    uint32_t clkdiv = (0U == id) ? (MRCC->CTIMERGRP0CLKDIV) : (MRCC->CTIMERGRP1CLKDIV);

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
            freq = CLOCK_GetRtcOscFreq();
            break;
        case 2U:
            freq = CLOCK_GetClk16KFreq();
            break;
        case 3U:
            freq = CLOCK_GetFroHfFreq() / ((MRCC->FROHFDIV & 0xFU) + 1U);
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

#endif /* Building on the main core */

/* Get LPI2C Clk */
/*! brief  Return Frequency of LPI2C functional Clock
 *  return Frequency of LPI2C functional Clock
 */
uint32_t CLOCK_GetLpi2cClkFreq(uint32_t id)
{
    uint32_t freq = 0U;

    if(id == 2U)
    {   /* AON I2C*/
        if(AON__CGU->PER_CLK_EN & CGU_PER_CLK_EN_I2C_CLK_MASK)
        {
            freq = CLOCK_getAonPerClkFreq();
        }
    }
#if __CORTEX_M == (33U) /* Building on the main core */
    else
    {   /* Main domain I2C0/1*/
        freq = CLOCK_GetPeriphGrpFreq(id);
    }
#endif
    return freq;
}

#if __CORTEX_M == (33U) /* Building on the main core */
/*! brief  Return Frequency of LPSPI functional Clock
 *  return Frequency of LPSPI functional Clock
 */
uint32_t CLOCK_GetLpspiClkFreq(uint32_t id)
{
    return CLOCK_GetPeriphGrpFreq(id);
}
#endif

/*! brief  Return Frequency of LPUART functional Clock
 *  return Frequency of LPUART functional Clock
 */
uint32_t CLOCK_GetLpuartClkFreq(uint32_t id)
{
    uint32_t freq = 0U;

    if(id == 2U)
    {   /* AON lpuart*/
        if(AON__CGU->PER_CLK_EN & CGU_PER_CLK_EN_UART_CLK_MASK)
        {
            freq = CLOCK_getAonPerClkFreq();
        }
    }
#if __CORTEX_M == (33U) /* Building on the main core */
    else
    {   /* Main domain UART0/1*/
        freq = CLOCK_GetPeriphGrpFreq(id);
    }
#endif
    return freq;
}

#if __CORTEX_M == (33U) /* Building on the main core */

/* Get UTICK0 Clk */
/*! brief  Return Frequency of UTICK0 functional Clock
 *  return Frequency of UTICK0 functional Clock
 */
uint32_t CLOCK_GetUtickClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = MRCC->UTICK0CLKSEL;

    switch (clksel)
    {
        case 0U:
        case 3U:
            freq = CLOCK_GetFro12MFreq();
            break;
        case 1U:
            freq = CLOCK_GetClk1MFreq();
            break;
        case 2U:
            freq = CLOCK_GetClk16KFreq();
            break;

        default:
            freq = 0U;
            break;
    }

    return freq;
}

/* Get WWDT0 Clk */
/*! brief  Return Frequency of WWDT0 functional Clock
 *  return Frequency of WWDT0 functional Clock
 */
uint32_t CLOCK_GetWwdtClkFreq(void)
{
    uint32_t freq   = CLOCK_GetClk1MFreq();
    uint32_t clkdiv = MRCC->WWDT0CLKDIV;

    if (true == CLOCK_IsDivHalt(clkdiv))
    {
        return 0;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of LPTMR functional Clock
 *  return Frequency of LPTMR functional Clock
 */
uint32_t CLOCK_GetLptmrClkFreq(void)
{
    return CLOCK_GetFreq(kCLOCK_SLOW_CLK);
}

/*! brief  Return Frequency of OSTIMER
 *  return Frequency of OSTIMER Clock
 */
uint32_t CLOCK_GetOstimerClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = MRCC->OSTIMER0CLKSEL;

    switch (clksel)
    {
        case 0U:
            freq = CLOCK_GetClk16KFreq();
            break;
        case 1U:
            freq = CLOCK_GetClk16KFreq();
            break;
        case 3U:
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
uint32_t CLOCK_GetAdcClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = MRCC->ADC0CLKSEL;
    uint32_t clkdiv = MRCC->ADC0CLKDIV;

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
            freq = CLOCK_GetRtcOscFreq();
            break;
        case 3U:
            freq = CLOCK_GetFroHfFreq() / ((MRCC->FROHFDIV & 0xFU) + 1U);
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
uint32_t CLOCK_GetCmpFClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = MRCC->CMP0RRCLKSEL;
    uint32_t clkdiv = MRCC->CMP0FUNCCLKDIV;

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
            freq = CLOCK_GetRtcOscFreq();
            break;
        case 3U:
            freq = CLOCK_GetFroHfFreq() / ((MRCC->FROHFDIV & 0xFU) + 1U);
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
uint32_t CLOCK_GetCmpRRClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = MRCC->CMP0RRCLKSEL;
    uint32_t clkdiv = MRCC->CMP0RRCLKDIV;

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
            freq = CLOCK_GetRtcOscFreq();
            break;
        case 3U:
            freq = CLOCK_GetFroHfFreq() / ((MRCC->FROHFDIV & 0xFU) + 1U);
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
    uint32_t clksel = MRCC->DBGTRACECLKSEL;
    uint32_t clkdiv = MRCC->DBGTRACECLKDIV;

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
            freq = CLOCK_GetClk16KFreq();
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
    uint32_t clksel = MRCC->CLKOUTCLKSEL;
    uint32_t clkdiv = MRCC->CLKOUTCLKDIV;

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
            freq = CLOCK_GetCoreSysClkFreq() >> 2U; /*SLOW_CLK*/
            break;
        case 3U:
            freq = CLOCK_GetClk16KFreq();
            break;
        case 7U:
            freq = CLOCK_GetFroHfFreq() / ((MRCC->FROHFDIV & 0xFU) + 1U);
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/* Get Periph Group Clk */
/*! brief  Return Frequency of Periph Group functional Clock
 *  return Frequency of Periph Group functional Clock
 */
uint32_t CLOCK_GetPeriphGroupClkFreq(uint32_t id)
{
    uint32_t freq   = 0U;
    uint32_t clksel = (0U == id) ? (MRCC->PGRP0CLKSEL) : (MRCC->PGRP1CLKSEL);
    uint32_t clkdiv = (0U == id) ? (MRCC->PGRP0CLKDIV) : (MRCC->PGRP1CLKDIV);

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
            freq = CLOCK_GetFroHfFreq() / ((MRCC->FROHFDIV & 0xFFU) + 1U);
            break;
        case 2U:
            freq = CLOCK_GetClk16KFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

/*! brief  Return Frequency of Systick Clock
 *  return Frequency of Systick.
 */
uint32_t CLOCK_GetSystickClkFreq(void)
{
    uint32_t freq   = 0U;
    uint32_t clksel = MRCC->SYSTICKCLKSEL;
    uint32_t clkdiv = MRCC->SYSTICKCLKDIV;

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
            freq = CLOCK_GetClk16KFreq();
            break;
        default:
            freq = 0U;
            break;
    }

    return freq / ((clkdiv & 0xFFU) + 1U);
}

#endif /* Building on the main core */

/**
 * @brief  Return Frequency of Systick Clock
 * @return Frequency of AON FRO (10M/2M or 0 when not eneabled).
 */
uint32_t CLOCK_GetFroAonFreq(void)
{
    if(CGU_CLK_CONFIG_FRO10M_EN(AON__CGU->CLK_CONFIG) == 0U)
    {
        return 0U;
    }
    else if(CGU_CLK_CONFIG_SEL_MODE(AON__CGU->CLK_CONFIG))
    {
        return 10000000U;
    }
    else
    {
        return 2000000U;
    }
}

#if __CORTEX_M == (33U) /* Building on the main core */
/**
 * @brief   Setup FROHF trim.
 * @param   config   : FROHF trim value
 * @return  returns success or fail status.
 */
status_t CLOCK_FROHFTrimConfig(firc_trim_config_t config)
{
    SCG0->FIRCTCFG = SCG_FIRCTCFG_TRIMSRC(config.trimSrc);

    if (kSCG_FircTrimNonUpdate == config.trimMode)
    {
        SCG0->FIRCSTAT = SCG_FIRCSTAT_TRIMFINE(config.trimFine);
    }

    /* Set trim mode. */
    SCG0->FIRCCSR = (uint32_t)config.trimMode;

    if ((SCG0->FIRCCSR & SCG_FIRCCSR_FIRCERR_MASK) == SCG_FIRCCSR_FIRCERR_MASK)
    {
        return (status_t)kStatus_Fail;
    }

    return (status_t)kStatus_Success;
}

/**
 * @brief   Setup FRO 12M trim.
 * @param   config   : FRO 12M trim value
 * @return  returns success or fail status.
 */
status_t CLOCK_FRO12MTrimConfig(sirc_trim_config_t config)
{
    SCG0->SIRCTCFG = SCG_SIRCTCFG_TRIMSRC(config.trimSrc);

    if (kSCG_SircTrimNonUpdate == config.trimMode)
    {
        SCG0->SIRCSTAT = SCG_SIRCSTAT_CCOTRIM(config.cltrim);
        SCG0->SIRCSTAT = SCG_SIRCSTAT_CCOTRIM(config.ccotrim);
    }

    /* Set trim mode. */
    SCG0->SIRCCSR = (uint32_t)config.trimMode;

    if ((SCG0->SIRCCSR & SCG_SIRCCSR_SIRCERR_MASK) == SCG_SIRCCSR_SIRCERR_MASK)
    {
        return (status_t)kStatus_Fail;
    }

    return (status_t)kStatus_Success;
}
#endif /* Building on the main core */

/**
 * @brief   Sets AON FRO 10M or 2M trim.
 * @param   is_fro2m : 0 for FRO10M, 1 for FRO2M
 * @param   config   : trim value
 */
void CLOCK_AON_FRO_Trim_Set(uint8_t is_fro2m, aon_fro_trim_config_t config)
{
    volatile uint32_t *reg_config = (is_fro2m) ?
                                    &AON__CGU->FRO2M_CONFIG :
                                    &AON__CGU->FRO10M_CONFIG;

    volatile uint32_t *reg_trim = (is_fro2m) ?
                                  &AON__CGU->FRO2M_TRIM :
                                  &AON__CGU->FRO10M_TRIM;
    uint32_t val;
    assert(config.fs_bp   <= 7U);
    assert(config.fs_vcco <= 3U);
    assert(config.tf      <= 7U);

    assert(config.cltrim  <= 63U);
    assert(config.ccotrim <= 63U);


    val = *reg_trim;
    val &= ~( CGU_FRO10M_TRIM_TRIM_FVCH_LV_MASK | CGU_FRO10M_TRIM_TRIM_TC_LV_MASK );
    val |= CGU_FRO10M_TRIM_TRIM_FVCH_LV((config.fs_vcco << 2U)|config.fs_bp);
    val |= CGU_FRO10M_CONFIG_TRIM_CCO_LV(config.tf);
    *reg_trim = val;

    val = *reg_config;
    val &= ~( CGU_FRO10M_CONFIG_TRIM_CLK_LV_MASK | CGU_FRO10M_CONFIG_TRIM_CCO_LV_MASK );
    val |= CGU_FRO10M_CONFIG_TRIM_CLK_LV(config.cltrim);  /* fine */
    val |= CGU_FRO10M_CONFIG_TRIM_CCO_LV(config.ccotrim); /* coarse */
    *reg_config = val;

}

/**
 * @brief   Reads AON FRO 10M or 2M trim values.
 * @param   is_fro2m : 0 for FRO10M, 1 for FRO2M
 * @param   config   : ptr to aon_fro_trim_config_t struct.
 */
void CLOCK_AON_FRO_Trim_Get(uint8_t is_fro2m, aon_fro_trim_config_t * config)
{
    volatile uint32_t *reg_config = (is_fro2m) ?
                                    &AON__CGU->FRO2M_CONFIG :
                                    &AON__CGU->FRO10M_CONFIG;

    volatile uint32_t *reg_trim = (is_fro2m) ?
                                  &AON__CGU->FRO2M_TRIM :
                                  &AON__CGU->FRO10M_TRIM;
    uint32_t val;
    assert(config);

    val = *reg_trim;
    config->fs_vcco = (val >> (CGU_FRO10M_TRIM_TRIM_FVCH_LV_SHIFT + 2U)) & 3U;
    config->fs_bp = (val >> CGU_FRO10M_TRIM_TRIM_FVCH_LV_SHIFT) & 7U;
    config->tf = (val >> CGU_FRO10M_TRIM_TRIM_TC_LV_SHIFT) & 7U;

    val = *reg_config;

    /* fine */
    config->cltrim = (val & CGU_FRO10M_CONFIG_TRIM_CLK_LV_MASK) >> CGU_FRO10M_CONFIG_TRIM_CLK_LV_SHIFT;
    /* coarse */
    config->ccotrim = (val & CGU_FRO10M_CONFIG_TRIM_CCO_LV_MASK) >> CGU_FRO10M_CONFIG_TRIM_CCO_LV_SHIFT;
}

#if __CORTEX_M == (33U) /* Building on the main core */

/*!
 * @brief Sets the ROSC monitor mode.
 *
 * This function sets the ROSC monitor mode. The mode can be disabled,
 * it can generate an interrupt when the error is disabled, or reset when the error is detected.
 *
 * @param mode Monitor mode to set.
 */
void CLOCK_SetRoscMonitorMode(scg_rosc_monitor_mode_t mode)
{
    uint32_t reg = SCG0->ROSCCSR;

    reg &= ~(SCG_ROSCCSR_ROSCCM_MASK | SCG_ROSCCSR_ROSCCMRE_MASK);

    reg |= (uint32_t)mode;

    SCG0->ROSCCSR = reg;
}

/*!
 * @brief Enable the clock for OSTIMER.
 *
 * Has no OS Timer control register in PMC, leave the function empty.
 *
 */
void CLOCK_EnableOstimer32kClock(void)
{
    /* Has no OS Timer control register in PMC, return directly */
    return;
}
#endif /* Building on the main core */
