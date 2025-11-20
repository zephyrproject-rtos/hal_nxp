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

typedef enum _clock_aon_chg
{
    kClockAonChg_auxClk,     /* RTC/AUX clk was changed or disabled, pass frequency or 0 for disable */
    kClockAonChg_Fro,        /* FRO10M_2M changed, pass 10M/2M/0 */
    kClockAonChg_clkSel,     /* ROOT_CLK_SEL_MUX changed, pass mux value */
    kClockAonChg_cpuClkDiv,  /* AON_CPU_CLK_DIV changed, pass divisor(>1) or 0 when AON_CPU_CLK is disabled */
    
}clock_aon_chg_t;

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/* Get get AON FRO10/2M Clk */
static uint32_t CLOCK_GetFroAonFreq(void);
/* Get RTC OSC Clk */
static uint32_t CLOCK_GetRtcOscFreq(void);
/* Get FRO16K (PMUIRC) Clk */
static uint32_t CLOCK_GetFro16KFreq(void);
/* Get AON_AUX_CLK freq*/
static uint32_t CLOCK_GetAonAuxFreq(void);
/* Get AON ROOT AUX freq */
static uint32_t CLOCK_GetAonRootAuxFreq(void);
/* Get CLK 16K Clk */
static uint32_t CLOCK_GetClk16KFreq(void);

#if __CORTEX_M == (33U) /* Building on the main core */
/* Get Main_Clk */
static uint32_t CLOCK_GetMainClk(void);
/* Get FRO 12M Clk */
static uint32_t CLOCK_GetFro12MFreq(void);
/* Get CLK 1M Clk */
static uint32_t CLOCK_GetClk1MFreq(void);
/* Get HF FRO Clk */
static uint32_t CLOCK_GetFroHfFreq(void);
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

static inline bool CLOCK_IsSysconDivider(clock_div_name_t div_name)
{
    return (div_name >= 0x200U);
}
#endif /* Building on the main core */

/*******************************************************************************
 * Code
 ******************************************************************************/

static void delay_ms(const uint32_t delay_ms)
{
#if __CORTEX_M == (33U) /* Building on the main core */
    const uint32_t  coreClock_Hz = CLOCK_GetCoreSysClkFreq();
#else
    const uint32_t  coreClock_Hz = CLOCK_GetAonCoreSysClkFreq();
#endif
    assert(coreClock_Hz > 0U);
    assert(delay_ms <= (UINT32_MAX/1000U)); 
    
    SDK_DelayAtLeastUs(delay_ms * 1000U, coreClock_Hz);
}


static void ADVC_PreChg(const clock_aon_chg_t change, uint32_t newValue)
{
#if defined(ADVC_DRIVER_USED) & ADVC_DRIVER_USED
    if(ADVC_IsEnabled())
    {
        uint32_t freq = 0U;       
        uint32_t root_clk_sel;
        
        if(change == kClockAonChg_clkSel)
        {
            root_clk_sel = newValue;
        }
        else
        {
            root_clk_sel = (AON__CGU->CLK_CONFIG &
                            CGU_CLK_CONFIG_ROOT_CLK_SEL_MASK) >>
                            CGU_CLK_CONFIG_ROOT_CLK_SEL_SHIFT;
        }
        
        if(root_clk_sel == 3U)
        {   /* Using ROOT_AUX_CLK */
         
            if(change == kClockAonChg_auxClk)
            {
               freq = newValue;
            }
            else
            {
               freq = CLOCK_GetAonRootAuxFreq();
            }      
        }
        else
        {   /* Using FRO */
         
            const uint32_t div = 1U << root_clk_sel;
           
            if(change == kClockAonChg_Fro)
            {
                freq = newValue;
            }
            else
            {
                freq = CLOCK_GetFroAonFreq();
            }
           
            freq /= div;
        }

        if(change == kClockAonChg_cpuClkDiv)
        {
            if(0U == newValue)
            {
                freq = 0U; /* disable */
            }
            else
            {
                freq /= newValue;
            }
        }
        else
        {
            if(AON__CGU->CLOCK_DIV & CGU_CLOCK_DIV_CLK_DIV_EN_MASK)
            {
                 const uint32_t aon_cpu_clk_div = (AON__CGU->CLOCK_DIV &
                                          CGU_CLOCK_DIV_AON_CPU_CLK_DIV_MASK) >>
                                          CGU_CLOCK_DIV_AON_CPU_CLK_DIV_SHIFT;
              
                 freq /= aon_cpu_clk_div + 1U;
            }
            else
            {
                 freq = 0U; /* AON_CPU_CLK is Disabled*/
            }
        }
        
        ADVC_PreVoltageChangeRequest(freq);
        /* ADVC functions always diables APB clk, so enable it again. */
        CLOCK_EnableClock(kCLOCK_GateAonAPB);
        
    } /* ADVC is enabled */
#endif
}

static void ADVC_PostChg(void)
{
#if defined(ADVC_DRIVER_USED) & ADVC_DRIVER_USED
    if(ADVC_IsEnabled())
    {
        ADVC_PostVoltageChangeRequest();
        /* ADVC functions always diables APB clk, so enable it again. */
        CLOCK_EnableClock(kCLOCK_GateAonAPB);
    }
#endif
}

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
        uint8_t run_advc_postchg = 1U;
        
        switch(connection)
        {
        case kFROdiv1_to_AON_CPU:
          ADVC_PreChg(kClockAonChg_clkSel, 0U);
          break;
        case kFROdiv2_to_AON_CPU:
          ADVC_PreChg(kClockAonChg_clkSel, 1U);
          break;
        case kFROdiv4_to_AON_CPU:
          ADVC_PreChg(kClockAonChg_clkSel, 2U);
          break;
        case kROOT_AUX_to_AON_CPU:
          ADVC_PreChg(kClockAonChg_clkSel, 3U);
          break;
        case kXTAL32K_to_AON_ROOT_AUX:
          ADVC_PreChg(kClockAonChg_auxClk, CLOCK_GetRtcOscFreq());
          break;
        case kAUX_to_AON_ROOT_AUX:
          ADVC_PreChg(kClockAonChg_auxClk, CLOCK_GetAonAuxFreq());  
          break;
        default: 
          run_advc_postchg = 0U;
          break;
        }
        
        CLOCK_SetClockSelect((clock_select_name_t)reg_offset, clk_sel);
        
        if(run_advc_postchg)
        {
            ADVC_PostChg();
        }
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

    if(div_name >= 0x800U)
    { /* AON clk*/
        if(div_name == 0x810U)
        {   /* AON ACMP CLK 0*/
            if(value==0)
            {
                AON__CGU->ACMP_CLK &= ~(CGU_ACMP_CLK_ACMP0_CLK_EN_MASK);
                AON__CGU->ACMP_CLK &= ~(CGU_ACMP_CLK_ACMP_CLK0_DIV_EN_MASK);
            }
            else
            {
                AON__CGU->ACMP_CLK &= ~(CGU_ACMP_CLK_AON_ACMP_CLK0_DIV_MASK);
                AON__CGU->ACMP_CLK |= (value-1U) << CGU_ACMP_CLK_AON_ACMP_CLK0_DIV_SHIFT;

                AON__CGU->ACMP_CLK |= CGU_ACMP_CLK_ACMP_CLK0_DIV_EN_MASK;
                AON__CGU->ACMP_CLK |= CGU_ACMP_CLK_ACMP0_CLK_EN_MASK;
            }
        }
        else if(div_name == 0x811U)
        {   /* AON ACMP CLK 1*/
            if(value==0)
            {
                AON__CGU->ACMP_CLK &= ~(CGU_ACMP_CLK_ACMP1_CLK_EN_MASK);
                AON__CGU->ACMP_CLK &= ~(CGU_ACMP_CLK_ACMP_CLK1_DIV_EN_MASK);
            }
            else
            {
                AON__CGU->ACMP_CLK &= ~(CGU_ACMP_CLK_AON_ACMP_CLK1_DIV_MASK);
                AON__CGU->ACMP_CLK |= (value-1U) << CGU_ACMP_CLK_AON_ACMP_CLK1_DIV_SHIFT;

                AON__CGU->ACMP_CLK |= CGU_ACMP_CLK_ACMP_CLK1_DIV_EN_MASK;
                AON__CGU->ACMP_CLK |= CGU_ACMP_CLK_ACMP1_CLK_EN_MASK;
            }

        }
        else
        {   /* The rest of AON */
            const uint32_t en_shift = div_name & 0x3U;
            const uint32_t div_shift = 3U*(en_shift+1U);
            uint32_t reg_val = AON__CGU->CLOCK_DIV;

            assert(value <= 8U);

            reg_val &= ~((7U << div_shift) | (1U << en_shift));
            
            if(value >= 1U )
            {
                reg_val |= (value - 1U) << div_shift;  
                
                /* enable divider */
                reg_val |= 1U << en_shift;
            }
            
            if(div_name == kCLOCK_DIVAonCPU)
            {   /* Changing AON CPU clock - inform ADVC: */
              
                ADVC_PreChg(kClockAonChg_cpuClkDiv, value);
                AON__CGU->CLOCK_DIV = reg_val;
                ADVC_PostChg();
            }
            else
            {
                AON__CGU->CLOCK_DIV = reg_val;
            }
        }
    }
#if __CORTEX_M == (33U) /* Building on the main core */
    else
    {
        volatile uint32_t *pDivCtrl;

        /* Unlock clock configuration */
        SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK;

        if (CLOCK_IsSysconDivider(div_name))
        {
            pDivCtrl = (volatile uint32_t *)(SYSCON_BASE + (uint32_t)div_name);
            if (div_name == kCLOCK_DivAHBAIPSCLK)
            {
                *pDivCtrl = (value) ? 0U : (1UL << SYSCON_AHBAIPSCLKDIV_HALT_SHIFT);
            }
            else
            {
                if (value > 0U)
                {
                    *pDivCtrl = (value - 1U);
                }
            }
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

    if(div_name >= 0x800)
    { /* AON clk*/
        if(div_name == 0x810U)
        {   /* AON ACMP CLK 0*/
            uint32_t reg_val = AON__CGU->ACMP_CLK;
            if((!(reg_val & CGU_ACMP_CLK_ACMP0_CLK_EN_MASK)) ||
               (!(reg_val & CGU_ACMP_CLK_ACMP_CLK0_DIV_EN_MASK)))
            {
                return 0; /* Not enabled clk or div*/
            }
            else
            {
                reg_val &=  CGU_ACMP_CLK_AON_ACMP_CLK0_DIV_MASK;
                reg_val >>=  CGU_ACMP_CLK_AON_ACMP_CLK0_DIV_SHIFT;
                return reg_val + 1U;
            }
        }
        else if(div_name == 0x811U)
        {   /* AON ACMP CLK 1*/
            uint32_t reg_val = AON__CGU->ACMP_CLK;
            if((!(reg_val & CGU_ACMP_CLK_ACMP1_CLK_EN_MASK)) ||
               (!(reg_val & CGU_ACMP_CLK_ACMP_CLK1_DIV_EN_MASK)))
            {
                return 0; /* Not enabled clk or div*/
            }
            else
            {
                reg_val &=  CGU_ACMP_CLK_AON_ACMP_CLK1_DIV_MASK;
                reg_val >>=  CGU_ACMP_CLK_AON_ACMP_CLK1_DIV_SHIFT;
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
                const uint32_t div_shift = 3U * (en_shift + 1U);
                return ((reg_val >> div_shift) & 7U) + 1U;
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
        volatile uint32_t *pDivCtrl;
        
        if (CLOCK_IsSysconDivider(div_name))
        {
            pDivCtrl = (volatile uint32_t *)(SYSCON_BASE + (uint32_t)div_name);
            if (div_name == kCLOCK_DivAHBAIPSCLK)
            {
                /* Only Halt is supported. Return 1 if not halted.*/
                return ((*pDivCtrl & SYSCON_AHBAIPSCLKDIV_HALT_MASK) >> SYSCON_AHBAIPSCLKDIV_HALT_SHIFT) ? 0 : 1;
            }
            else
            {
                return ((*pDivCtrl & 0xFFU) + 1U);
            }
        }
        else
        {
            pDivCtrl = (volatile uint32_t *)(MRCC_BASE + (uint32_t)div_name);

            if (((*pDivCtrl) & (1UL << 30U)) != 0U)
            {
                return 0;
            }
            else
            {
                return ((*pDivCtrl & 0xFFU) + 1U);
            }
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

    if(div_name >= 0x800)
    { /* AON clk*/
        if(div_name == 0x810U)
        {   /* AON ACMP CLK 0*/
            AON__CGU->ACMP_CLK &= ~(CGU_ACMP_CLK_ACMP_CLK0_DIV_EN_MASK);
        }
        else if(div_name == 0x811U)
        {   /* AON ACMP CLK 1*/
            AON__CGU->ACMP_CLK &= ~(CGU_ACMP_CLK_ACMP_CLK1_DIV_EN_MASK);
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

        if (div_name != kCLOCK_DivAHBCLK)
        {
            if (div_name == kCLOCK_DivAHBAIPSCLK)
            {
                pDivCtrl = (volatile uint32_t *)(SYSCON_BASE + (uint32_t)div_name);
            }
            
            /* Unlock clock configuration */
            SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK;

            *pDivCtrl |= (1UL << 30U);

            /* Freeze clock configuration */
            SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK;
        }
    }
#endif
}

/* Initialize the FROHF to given frequency (10M, 2M) */
status_t CLOCK_SetupFROAonClocking(uint32_t iFreq)
{
    ADVC_PreChg(kClockAonChg_Fro, iFreq);
    
    switch(iFreq)
    {
        case 10000000U:
            AON__CGU->CLK_CONFIG |= 1U << CGU_CLK_CONFIG_FRO10M_EN_SHIFT;
            AON__CGU->CLK_CONFIG &= ~(1U << CGU_CLK_CONFIG_SEL_MODE_SHIFT);
            AON__CGU->CLK_CONFIG &= ~CGU_CLK_CONFIG_FRO2M_EN_MASK;
            break;
        case 2000000U:
            AON__CGU->CLK_CONFIG |= CGU_CLK_CONFIG_FRO2M_EN_MASK;
            SDK_DelayAtLeastUs(500U, SystemCoreClock);
            AON__CGU->CLK_CONFIG |= 1U << CGU_CLK_CONFIG_SEL_MODE_SHIFT;
            AON__CGU->CLK_CONFIG &= ~CGU_CLK_CONFIG_FRO10M_EN_MASK;
            break;
        case 0U:
            /* Turn off */
            AON__CGU->CLK_CONFIG &= ~CGU_CLK_CONFIG_FRO2M_EN_MASK;
            AON__CGU->CLK_CONFIG &= ~CGU_CLK_CONFIG_FRO10M_EN_MASK;
            break;
        default:
            ADVC_PostChg();
            return kStatus_Fail;
    }
    
    ADVC_PostChg();
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
    
    /* Enable FROM12M in deep sleep */
    SCG0->SIRCCSR |= SCG_SIRCCSR_SIRCSTEN_MASK;

    /* Lock SIRCCSR */
    SCG0->SIRCCSR |= SCG_SIRCCSR_LK_MASK;

    /* Wait for SIRC clock to be valid. */
    while ((SCG0->SIRCCSR & SCG_SIRCCSR_SIRCVLD_MASK) == 0U)
    {
    }

    return (status_t)kStatus_Success;
}

/**
 * @brief Enable automatic clock control for an IP.
 * @param clk : IP identifier.
 * @return  Nothing
 */
void CLOCK_EnableAutoClockGate(clock_ip_name_t clk)
{
    const uint32_t bit_shift = CLK_PERIPHERAL_BIT_SHIFT(clk);
    const uint32_t reg_acc_offset = CLK_GATE_REG_ACC_OFFSET(clk);

    volatile uint32_t *pAcc = (volatile uint32_t *)((uint32_t)(&(MRCC->GLB_ACC0)) + reg_acc_offset);

    if (clk == kCLOCK_GateNotAvail || clk == kCLOCK_GateMTR ||
        clk == kCLOCK_GateTCU)
    {
        return;
    }

    /* Unlock clock configuration */
    SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK;

    *pAcc |= (1UL << bit_shift);

    /* Freeze clock configuration */
    SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK;
}

/**
 * @brief Disable automatic clock control for an IP.
 * @param clk : IP identifier.
 * @return  Nothing
 */
void CLOCK_DisableAutoClockGate(clock_ip_name_t clk)
{
    const uint32_t bit_shift = CLK_PERIPHERAL_BIT_SHIFT(clk);
    const uint32_t reg_acc_offset = CLK_GATE_REG_ACC_OFFSET(clk);

    volatile uint32_t *pAcc = (volatile uint32_t *)((uint32_t)(&(MRCC->GLB_ACC0)) + reg_acc_offset);

    if (clk == kCLOCK_GateNotAvail || clk == kCLOCK_GateMTR ||
        clk == kCLOCK_GateTCU)
    {
        return;
    }

    /* Unlock clock configuration */
    SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK;

    *pAcc &= ~(1UL << bit_shift);

    /* Freeze clock configuration */
    SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK;
}

#endif /* Building on the main core */

static status_t is_xtal_clkout_vbat_ok()
{
    const uint32_t ok = (AON__SMM->RTC_ANLG_XTAL & SMM_RTC_ANLG_XTAL_RTC_ALV_INDCTN_MASK);
  
    return (0U != ok) ? (status_t)kStatus_Success : (status_t)kStatus_Fail;
}

/*!
 * brief Initializes the ROSC (xtal32k).
 *
 * param vbat_over3V  Set to true is vbat voltage is greater than 3V
 * retval kStatus_Success ROSC is initialized.
 *        kStatus_Fail ROSC init failed.
 *        kStatus_Busy ROSC is used as core clock.
 */
status_t CLOCK_InitRosc(bool vbat_over3V)
{
    uint32_t supdet;
    uint32_t i = 0;
    uint32_t timeout = 500U;
    status_t status = (status_t)kStatus_Fail;

    for (i = 0; i < 3U; i++)
    {
        AON__SMM->RTC_DCDC_CNTRL = SMM_RTC_DCDC_CNTRL_ISO_MASK | SMM_RTC_DCDC_CNTRL_DGTL_RST_N_MASK;
        delay_ms(1U);
    }

    for (i = 0; i < 3U; i++)
    {
        AON__SMM->RTC_DCDC_CNTRL =
            SMM_RTC_DCDC_CNTRL_ISO_MASK | SMM_RTC_DCDC_CNTRL_DGTL_RST_N_MASK | SMM_RTC_DCDC_CNTRL_ANA_RESET_N_MASK;
        delay_ms(1U);
    }
    
    /* Enable current mirror,set initial AMP and GM, set everything else to default */
    AON__SMM->RTC_XTAL_CONFG1 = SMM_RTC_XTAL_CONFG1_CRNT_MROR_EN_MASK | SMM_RTC_XTAL_CONFG1_AMPSEL(0);
    delay_ms(2U);
    AON__SMM->RTC_XTAL_CONFG2 = SMM_RTC_XTAL_CONFG2_GMSEL(0);
    delay_ms(1U);
    
    /* XTAL_SUPDET_TM_SOX_VBAT=0 if VBAT <3 VXTAL_SUPDET_TM_SOX_VBAT=1 if VBAT >=3 */
    supdet = (vbat_over3V) ? 1U : 0U;
    AON__SMM->RTC_XTAL_CONFG2 = (AON__SMM->RTC_XTAL_CONFG2 & ~SMM_RTC_XTAL_CONFG2_SUPDET_TM_SOX_MASK) |
        SMM_RTC_XTAL_CONFG2_SUPDET_TM_SOX(supdet);
    delay_ms(1U);
    
    /* Disable bias block */
    AON__SMM->BIAS_CTRL &= ~(SMM_BIAS_CTRL_BIAS_EN_MASK | SMM_BIAS_CTRL_COARSE_MASK);
    AON__SMM->BIAS_CTRL &= ~(SMM_BIAS_CTRL_EN_OSC_IREF_CM_TRIM_1NA_MASK | SMM_BIAS_CTRL_EN_OSC_IREF_CM_TRIM_2NA_MASK);
    AON__SMM->BIAS_CTRL |= SMM_BIAS_CTRL_XTAL_SOX_4P_DIS_MASK;
    delay_ms(1U);
    
    /* Configure the load cap for RTC XO swithced mode */
    AON__SMM->RTC_XTAL_CONFG1 = (AON__SMM->RTC_XTAL_CONFG1 & ~SMM_RTC_XTAL_CONFG1_CB_XI_MASK) | SMM_RTC_XTAL_CONFG1_CB_XI(0x3);
    delay_ms(1U);
    AON__SMM->RTC_XTAL_CONFG1 = (AON__SMM->RTC_XTAL_CONFG1 & ~SMM_RTC_XTAL_CONFG1_CB_XO_MASK) | SMM_RTC_XTAL_CONFG1_CB_XO(0x3);
    delay_ms(1U);
    AON__SMM->RTC_XTAL_CONFG2 |= SMM_RTC_XTAL_CONFG2_CAP_BNK_EN_MASK;
    delay_ms(3U);
    
    /* Enable RTC alive detector */
    AON__SMM->RTC_ANLG_XTAL |= SMM_RTC_ANLG_XTAL_RTC_ALV_DTCT_EN_MASK;
    AON__RTC_AON->RTC_ALV_DTCT &= ~RTC_RTC_ALV_DTCT_BYPASS_MASK;
    AON__RTC_AON->RTC_ALV_DTCT |= RTC_RTC_ALV_DTCT_DTCT_EN_MASK;
    
    for (uint32_t dly = 0; dly <= 7U; dly++)
    {
        if (dly == 4U)
        {
          /* 4 should not be used based on RM */
          continue;
        }
        
        AON__SMM->RTC_XTAL_CONFG2 = (AON__SMM->RTC_XTAL_CONFG2 & ~SMM_RTC_XTAL_CONFG2_DLY_CAP_SOX_MASK) | SMM_RTC_XTAL_CONFG2_DLY_CAP_SOX(dly);
        
        for (uint32_t amp = 0; amp <= 3U; amp++)
        {
            /* Skip invalid AMP value (1 is not allowed, only 0, 2, 3) */
            if (amp == 1U)
                continue;
            
            for (uint32_t gm = 0; gm <= 3U; gm++)
            {
                
                /* Set another AMP and GM values */
                AON__SMM->RTC_XTAL_CONFG1 = (AON__SMM->RTC_XTAL_CONFG1 & ~SMM_RTC_XTAL_CONFG1_AMPSEL_MASK) | SMM_RTC_XTAL_CONFG1_AMPSEL(amp);
                AON__SMM->RTC_XTAL_CONFG2 = (AON__SMM->RTC_XTAL_CONFG2 & ~SMM_RTC_XTAL_CONFG2_GMSEL_MASK) | SMM_RTC_XTAL_CONFG2_GMSEL(gm);
                delay_ms(2U);

                /* Enable XTAL */
                AON__SMM->RTC_XTAL_CONFG1 |= SMM_RTC_XTAL_CONFG1_XTAL_EN_MASK;
                delay_ms(1U);
                AON__SMM->RTC_XTAL_CONFG2 |= SMM_RTC_XTAL_CONFG2_SOX_EN_MASK;
                delay_ms(100U);
                
                timeout = 500U;
                while ((is_xtal_clkout_vbat_ok() != (status_t)kStatus_Success) && timeout > 0U)
                {
                    delay_ms(1U);
                    timeout--;
                };
                
                if (timeout > 0U)
                {
                    break;
                };
                
                /* Disable XTAL */
                AON__SMM->RTC_XTAL_CONFG1 &= ~SMM_RTC_XTAL_CONFG1_XTAL_EN_MASK;
                delay_ms(2U);
            };
            
            if (timeout > 0U)
            {
                break;
            };
        };
        
        /* Use switched mode */
        AON__SMM->RTC_XTAL_CONFG1 = (AON__SMM->RTC_XTAL_CONFG1 & ~SMM_RTC_XTAL_CONFG1_CB_XI_MASK) | SMM_RTC_XTAL_CONFG1_CB_XI(0x0);
        delay_ms(100U);
        AON__SMM->RTC_XTAL_CONFG2 &= ~SMM_RTC_XTAL_CONFG2_SOX_EN_MASK;
        delay_ms(100U);
        
        timeout = 500U;
        while ((is_xtal_clkout_vbat_ok() != (status_t)kStatus_Success) && timeout > 0U)
        {
            delay_ms(1U);
            timeout--;
        };
        
        if (timeout > 0U)
        {
            status = (status_t)kStatus_Success;
            break;
        };
    };
   
    /* Enable LDO, set voltage to 0.8V */
    AON__SMM->RTC_DCDC_CNTRL = SMM_RTC_DCDC_CNTRL_ISO_MASK | SMM_RTC_DCDC_CNTRL_DGTL_RST_N_MASK |
                               SMM_RTC_DCDC_CNTRL_ANA_RESET_N_MASK | SMM_RTC_DCDC_CNTRL_LDO_EN_MASK |
                               SMM_RTC_DCDC_CNTRL_LDO_PULDWN_EN_MASK | SMM_RTC_DCDC_CNTRL_LDO_CONFIG(0x15);
    delay_ms(10U);

    /* Disable pull down */
    AON__SMM->RTC_DCDC_CNTRL &= ~SMM_RTC_DCDC_CNTRL_LDO_PULDWN_EN_MASK;
    AON__SMM->RTC_DCDC_CNTRL &= ~SMM_RTC_DCDC_CNTRL_ISO_MASK;
    AON__SMM->RTC_DCDC_CNTRL |= SMM_RTC_DCDC_CNTRL_DGTL_RST_N_MASK;
    
    /* Disable RTC alive detector */
    AON__SMM->RTC_ANLG_XTAL &= ~SMM_RTC_ANLG_XTAL_RTC_ALV_DTCT_EN_MASK;
    AON__RTC_AON->RTC_ALV_DTCT |= RTC_RTC_ALV_DTCT_BYPASS_MASK;
    AON__RTC_AON->RTC_ALV_DTCT &= ~RTC_RTC_ALV_DTCT_DTCT_EN_MASK;
    delay_ms(1U);
    
    return status;
}

/*!
 * brief De-initializes the SCG ROSC.
 *
 * This function disables the SCG ROSC clock.
 *
 * retval kStatus_Success System OSC is deinitialized.
 * retval kStatus_Busy ROSC is used by core.
 */
status_t CLOCK_DeinitRosc(void)
{
    uint32_t clk;
#if __CORTEX_M == (33U) /* Building on the main core */
    clk = CLOCK_GetClockSelect(kCLOCK_SelSCGSCS);
    if(clk == 4U)
    {
        /* Main core uses Rosc */
        return kStatus_Busy;
    }
#else  
    clk = CLOCK_GetClockSelect(kCLOKC_SelAonROOT);
    if(clk == 3U)
    {
        /* AON core uses root aux clk... */
        clk = CLOCK_GetClockSelect(kCLOKC_SelAonROOT_AUX);
        if(clk == 0U)
        {
            /* ... aon aon root aux clk uses Rosc*/
            return kStatus_Busy;
        }
    }
#endif  
  
    AON__SMM->RTC_DCDC_CNTRL &= ~(SMM_RTC_DCDC_CNTRL_ANA_RESET_N_MASK | 
                                  SMM_RTC_DCDC_CNTRL_DGTL_RST_N_MASK);   

    return (status_t)kStatus_Success;
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
            freq = CLOCK_GetFro16KFreq();
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
#if __CORTEX_M == (33U) /* Building on the main core */
            /* SYSCON register is needed for calculation. Accessible from main core only. */
            freq = CLOCK_GetFroHfFreq() / CLOCK_GetClockDiv(kCLOCK_DivAONAUXCLK);
#else /* Building on AON */
            freq = 0U;
#endif
        }
        else
        {
            freq = CLOCK_GetRtcOscFreq();
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
              freq = CLOCK_GetFroAonFreq();
              break;
            case 1U:
              freq = CLOCK_GetFroAonFreq() / 2U;
              break;
            case 2U:
              freq = CLOCK_GetFroAonFreq() / 4U;
              break;
            case 3U:
              freq = CLOCK_GetAonRootAuxFreq();
              break;
        }

        freq /= div + 1U;
    }
    return freq;
}

static uint32_t CLOCK_getAonTmrClkFreq(void)
{
    uint32_t freq = 0U;

    if(AON__CGU->CLOCK_DIV & CGU_CLOCK_DIV_COM_GRP_CLK_EN_MASK)
    {
        const uint32_t sel = (AON__CGU->PER_CLK_CONFIG &
                        CGU_PER_CLK_CONFIG_TMR_GRP_SEL_MASK) >>
                       CGU_PER_CLK_CONFIG_TMR_GRP_SEL_SHIFT;
        const uint32_t div = (AON__CGU->CLOCK_DIV &
                        CGU_CLOCK_DIV_COM_GRP_CLK_DIV_MASK) >>
                       CGU_CLOCK_DIV_COM_GRP_CLK_DIV_SHIFT;

        switch(sel)
        {
            case 0U:
              freq = CLOCK_GetFroAonFreq();
              break;
            case 1U:
              freq = CLOCK_GetFroAonFreq() / 2U;
              break;
            case 2U:
              freq = CLOCK_GetFroAonFreq() / 4U;
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
 * @brief Gets the RTC OSC clock frequency.
 *
 * @return  Clock frequency.
 */
uint32_t CLOCK_GetRtcOscFreq(void)
{
    return 32768;
}

/*!
 * @brief Gets FRO16K (PMUIRC) clock frequency.
 *
 * @return  Clock frequency.
 */
uint32_t CLOCK_GetFro16KFreq(void)
{
    uint32_t freq = 0U;

    if (AON__PMU->FRO_CTRL & PMU_FRO_CTRL_FRO16K_EN_MASK)
    {
        if (AON__PMU->FRO_CTRL & PMU_FRO_CTRL_CLOCK_SEL_MASK)
        {
            freq = 8192U;
        }
        else
        {
            freq = 16384U;
        }
    }

    return freq;
}

/*!
 * @brief Gets the AON_AUX_CLK frequency.
 *
 * @return  Clock frequency;
 */
uint32_t CLOCK_GetAonAuxFreq(void)
{
    return 32768U; /* FIXME */
}


/*! brief  Return Frequency of the AON core
 *  return Frequency of the core
 */
uint32_t CLOCK_GetAonCoreSysClkFreq(void)
{
    uint32_t freq = 0U;

    if(AON__CGU->CLOCK_DIV & CGU_CLOCK_DIV_CLK_DIV_EN_MASK)
    {
        const uint32_t sel = (AON__CGU->CLK_CONFIG &
                        CGU_CLK_CONFIG_ROOT_CLK_SEL_MASK) >>
                        CGU_CLK_CONFIG_ROOT_CLK_SEL_SHIFT;
        const uint32_t div = (AON__CGU->CLOCK_DIV &
                        CGU_CLOCK_DIV_AON_CPU_CLK_DIV_MASK) >>
                        CGU_CLOCK_DIV_AON_CPU_CLK_DIV_SHIFT;

        switch(sel)
        {
            case 0U:
              freq = CLOCK_GetFroAonFreq();
              break;
            case 1U:
              freq = CLOCK_GetFroAonFreq() / 2U;
              break;
            case 2U:
              freq = CLOCK_GetFroAonFreq() / 4U;
              break;
            case 3U:
              freq = CLOCK_GetAonRootAuxFreq();
              break;
        }

        freq /= div + 1U;
    }
    return freq; 
}

/* Get CLK 16K Clk */
/*! brief  Return Frequency of CLK 16KHz
 *  return Frequency of CLK 16KHz
 */
static uint32_t CLOCK_GetClk16KFreq(void)
{
    return (CLOCK_GetRtcOscFreq() / 2U);
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
        return 32768U;
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
            freq = CLOCK_GetFro16KFreq();
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

/*! brief  Return Frequency of the main core
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

/* Get QTMR Clk */
/*! brief  Return Frequency of QTMR functional Clock
 *  return Frequency of QTMR functional Clock
 */
uint32_t CLOCK_GetQtmrClkFreq(void)
{
    uint32_t freq = 0U;

    if(AON__CGU->PER_CLK_EN & CGU_PER_CLK_EN_QTMR0_CLK_EN_MASK)
    {
        freq = CLOCK_getAonTmrClkFreq();
    }

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

/*! brief  Return Frequency of LPTMR functional Clock
 *  return Frequency of LPTMR functional Clock
 */
uint32_t CLOCK_GetLptmrClkFreq(void)
{
    uint32_t freq   =  0U;
    uint32_t clksel = (AON__CGU->PER_CLK_CONFIG & CGU_PER_CLK_CONFIG_LPTMR_GRP_SEL_MASK) >> CGU_PER_CLK_CONFIG_LPTMR_GRP_SEL_SHIFT;
    
    if(AON__CGU->PER_CLK_EN & CGU_PER_CLK_EN_LPTMR_CLK_EN_MASK)
    {
        switch (clksel)
        {
            case 0U:
                freq = CLOCK_getAonTmrClkFreq();
                break;
            case 1U:
                freq = CLOCK_GetFro16KFreq();
                break;
            case 2U:
                freq = CLOCK_GetClk16KFreq();
                break;
            default:
                freq = 0U;
                break;
        }
    }
    
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
            freq = CLOCK_GetFro16KFreq();
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
 * @brief  Get frequency of selected AON FRO
 * @return Frequency of AON FRO (10M/2M or 0 when disabled).
 */
uint32_t CLOCK_GetFroAonFreq(void)
{
    uint32_t freq = 0U;

    /* 2MHz is selected*/
    if(AON__CGU->CLK_CONFIG & CGU_CLK_CONFIG_SEL_MODE_MASK)
    {
        if(AON__CGU->CLK_CONFIG & CGU_CLK_CONFIG_FRO2M_EN_MASK)
        {
            freq = 2000000U;
        }
    }
    /* 10MHz is selected*/
    else if(AON__CGU->CLK_CONFIG & CGU_CLK_CONFIG_FRO10M_EN_MASK)
    {
        freq = 10000000U;
    }

    return freq;
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

#if __CORTEX_M == (33U) /* Building on the main core */
/*!
 * @brief Set flash wait state.
 *
 * This function sets the flash wait state. Valid states are only 0-15.
 *
 * @param state Flash wait state (0-15)
 */
void CLOCK_SetFlashWaitState(uint8_t state)
{
    assert(state <= 15);
    FMU0->FCTRL = (FMU0->FCTRL & ~FMU_FCTRL_RWSC_MASK) | (state << FMU_FCTRL_RWSC_SHIFT);
}

/*!
 * @brief Set flash wait state based on frequency.
 *
 * This function sets the flash wait state based on frequency.
 *
 * @param freq Core frequency.
 */
void CLOCK_SetFlashWaitStateBasedOnFreq(uint32_t freq)
{
    if (freq <= 48000000U) {
        CLOCK_SetFlashWaitState(0x1U);
    }
    else if (freq <= 96000000U)
    {
        CLOCK_SetFlashWaitState(0x2U);
    }
}

/*!
 * @brief Get flash wait state.
 *
 * This function returns flash wait state.ň
 *
 * @return Returns flash wait state.
 */
uint8_t CLOCK_GetFlashWaitState()
{
    return (FMU0->FCTRL & FMU_FCTRL_RWSC_MASK) >> FMU_FCTRL_RWSC_SHIFT;
}

/*!
 * @brief Enable/disable FRO12M(SIRC) Auto trim feature
 *
 * This requires ROSC (xtal32) initialized.
 *
 * @see CLOCK_InitRosc()
 *
 * @return kStatus_Fail on error, kStatus_Success otherwise.
 */
status_t CLOCK_FRO12MAutoTrimEnable(bool enable)
{
    status_t st = (status_t)kStatus_Success;
    
    /* unlock SIRCCSR */
    SCG0->SIRCCSR &= ~(SCG_SIRCCSR_LK_MASK);
    
    if(enable)
    {
        /* select ROSC as auto trim clock source */
        SCG0->SIRCTCFG = (SCG0->SIRCTCFG & ~(SCG_SIRCTCFG_TRIMSRC_MASK)) | SCG_SIRCTCFG_TRIMSRC(3U);  

        /* enable auto trim  */
        SCG0->SIRCCSR |= SCG_SIRCCSR_SIRCTREN_MASK;
        /* enable update */
        SCG0->SIRCCSR |= SCG_SIRCCSR_SIRCTRUP_MASK;
        
        /* Wait for SIRC is valid  */
        while(!(SCG0->SIRCCSR & SCG_SIRCCSR_SIRCVLD_MASK)) {}
        
        /* Check for error */
        if(SCG0->SIRCCSR & SCG_SIRCCSR_SIRCERR_MASK)
        {     
            st = (status_t)kStatus_Fail;
        }
        else
        {
            /* Wait for trim lock */
            while(!(SCG0->SIRCCSR & SCG_SIRCCSR_TRIM_LOCK_MASK)) {}
        }
    }
    else
    {
        /* Disable auto trim  */
        SCG0->SIRCCSR &= ~(SCG_SIRCCSR_SIRCTREN_MASK);
    }
    
    /* lock SIRCCSR */
    SCG0->SIRCCSR |= SCG_SIRCCSR_LK_MASK;
    
    return st;
}

/*!
 * @brief Enable/disable FROHF(FRO96M/FIRC) Auto trim feature
 *
 * This requires ROSC (xtal32) initialized.
 *
 * @see CLOCK_InitRosc()
 *
 * @return kStatus_Fail on error, kStatus_Success otherwise.
 */
status_t CLOCK_FROHFAutoTrimEnable(bool enable)
{
    status_t st = (status_t)kStatus_Success;
    
    /* unlock FIRCCSR */
    SCG0->FIRCCSR &= ~(SCG_FIRCCSR_LK_MASK);
    
    if(enable)
    {
        /* select ROSC as auto trim clock source */
        SCG0->FIRCTCFG = (SCG0->FIRCTCFG & ~(SCG_FIRCTCFG_TRIMSRC_MASK)) | SCG_FIRCTCFG_TRIMSRC(3U);  

        /* enable auto trim  */
        SCG0->FIRCCSR |= SCG_FIRCCSR_FIRCTREN_MASK;
        /* enable update */
        SCG0->FIRCCSR |= SCG_FIRCCSR_FIRCTRUP_MASK;
        
        /* Wait for FIRC is valid  */
        while(!(SCG0->FIRCCSR & SCG_FIRCCSR_FIRCVLD_MASK)) {}
        
        /* Check for error */
        if(SCG0->FIRCCSR & SCG_FIRCCSR_FIRCERR_MASK)
        {     
            st = (status_t)kStatus_Fail;
        }
        else
        {
            /* Wait for trim lock */
            while(!(SCG0->FIRCCSR & SCG_FIRCCSR_TRIM_LOCK_MASK)) {}
        }
    }
    else
    {
        /* Disable auto trim  */
        SCG0->FIRCCSR &= ~(SCG_FIRCCSR_FIRCTREN_MASK);
    }
    
    /* lock FIRCCSR */
    SCG0->FIRCCSR |= SCG_FIRCCSR_LK_MASK;
    
    return st;
}

#endif /* Building on the main core */