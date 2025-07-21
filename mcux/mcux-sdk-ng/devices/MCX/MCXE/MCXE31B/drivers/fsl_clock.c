/*
 * Copyright 2025 NXP
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

#define CLOCK_MUX_DC_REG(mux, dc) (*((volatile uint32_t *)((uint32_t)(&(MC_CGM->MUX_0_DC_0)) + (mux)*0x40U + (dc)*4U)))
#define CLOCK_MUX_CSS_REG(mux)    (*((volatile uint32_t *)((uint32_t)(&(MC_CGM->MUX_0_CSS)) + (mux)*0x40U)))

/* Pcfs settings that are dependent on device */
#define CLOCK_IP_DYNAMIC_IDD_CHANGE 2360U /* microA per MHz */
#define CLOCK_IP_A_MAX_SIZE         4U
static const uint32_t AMax[CLOCK_IP_A_MAX_SIZE]     = {5U, 10U, 150U, 200U};
static const uint32_t PcfsRate[CLOCK_IP_A_MAX_SIZE] = {12U, 48U, 112U, 184U};
/*******************************************************************************
 * Variables
 *****************************************************************************/
volatile uint32_t g_xtal0Freq         = 0U;
volatile uint32_t g_emacRmiiTxClkFreq = 0U;
volatile uint32_t g_emacRxClkFreq     = 0U;

/*******************************************************************************
 * Functions
 *****************************************************************************/

void CLOCK_EnableClock(clock_ip_name_t clk)
{
    uint32_t bitMask = 1UL << MC_ME_COFB_CLKEN_BIT(clk);

    assert(clk != 0U);

    /* Enable the clock only if not enabled. */
    if ((MC_ME_COFB_STAT_REG(clk) & bitMask) == 0U)
    {
        MC_ME_COFB_CLKEN_REG(clk) |= bitMask;                    /* Turn on clock. */
        MC_ME_PRTN_PCONF_REG(clk) |= MC_ME_PRTN0_PCONF_PCE_MASK; /* Trun on clock for the partition. */
        MC_ME_PRTN_PUPD_REG(clk) |= MC_ME_PRTN0_PUPD_PCUD_MASK;  /* Enable partition clock update. */

        CLOCK_McmeEnterKey();

        while (MC_ME_PRTN_PUPD_REG(clk) & MC_ME_PRTN0_PUPD_PCUD_MASK)
        {
        }
    }
    else
    {
        /* Already enabled. */
    }
}

void CLOCK_DisableClock(clock_ip_name_t clk)
{
    uint32_t bitMask = 1UL << MC_ME_COFB_CLKEN_BIT(clk);

    assert(clk != 0U);

    /* Disable the clock only if enabled. */
    if ((MC_ME_COFB_STAT_REG(clk) & bitMask) != 0U)
    {
        MC_ME_COFB_CLKEN_REG(clk) &= ~bitMask;                  /* Turn off  clock. */
        MC_ME_PRTN_PUPD_REG(clk) |= MC_ME_PRTN0_PUPD_PCUD_MASK; /* Enable partition clock update. */

        CLOCK_McmeEnterKey();

        while (MC_ME_PRTN_PUPD_REG(clk) & MC_ME_PRTN0_PUPD_PCUD_MASK)
        {
        }
    }
    else
    {
        /* Already disabled, nothing to do. */
    }
}

void CLOCK_SetClkDiv(clock_div_name_t div_name, uint32_t divider)
{
    if (0U == divider)
    {
        CLOCK_TUPLE_DIV_DC_REG(div_name) &= ~MC_CGM_MUX_0_DC_0_DE_MASK;
    }
    else
    {
        CLOCK_TUPLE_DIV_DC_REG(div_name) = MC_CGM_MUX_0_DC_0_DE_MASK | ((divider - 1U) << MC_CGM_MUX_0_DC_0_DIV_SHIFT);

        /* Check update finished. */
        while ((CLOCK_TUPLE_DIV_UPD_STAT_REG(div_name) & MC_CGM_MUX_0_DIV_UPD_STAT_DIV_STAT_MASK) != 0U)
        {
        }
    }
}

status_t CLOCK_SetFircDiv(clock_firc_div_t divider)
{
    status_t ret = kStatus_Success;
    if ((CONFIGURATION->CONFIG_REG_GPR & CONFIGURATION_CONFIG_REG_GPR_APP_CORE_ACC_MASK) ==
        CONFIGURATION_CONFIG_REG_GPR_APP_CORE_ACC(0x5U))
    {
        CONFIGURATION->CONFIG_REG_GPR =
            (CONFIGURATION->CONFIG_REG_GPR & ~CONFIGURATION_CONFIG_REG_GPR_FIRC_DIV_SEL_MASK) |
            CONFIGURATION_CONFIG_REG_GPR_FIRC_DIV_SEL((uint32_t)divider);
    }
    else
    {
        ret = kStatus_Fail;
    }
    return ret;
}

void CLOCK_AttachClk(clock_attach_id_t connection)
{
    uint32_t mux = (connection & 0xFF00U) >> 8U;
    uint32_t src = connection & 0xFFU;

    assert(mux < 12U);

    if ((mux != 5U) && (mux != 6U) && (mux != 11U)) /* For hardware-controlled clock multiplexer. */
    {
        while ((CLOCK_TUPLE_MUX_CSS_REG(connection) & MC_CGM_MUX_0_CSS_SWIP_MASK) != 0)
        {
        }
        CLOCK_TUPLE_MUX_CSC_REG(connection) = (src << MC_CGM_MUX_0_CSC_SELCTL_SHIFT) | MC_CGM_MUX_0_CSC_CLK_SW_MASK;
        while ((CLOCK_TUPLE_MUX_CSS_REG(connection) & MC_CGM_MUX_0_CSS_CLK_SW_MASK) == 0)
        {
        }
        while ((CLOCK_TUPLE_MUX_CSS_REG(connection) & MC_CGM_MUX_0_CSS_SWIP_MASK) != 0)
        {
        }
    }
    else /* For software-controlled clock multiplexer. */
    {
        if (src == 0xFFU)
        {
            CLOCK_TUPLE_MUX_CSC_REG(connection) = MC_CGM_MUX_5_CSC_CG_MASK;
        }
        else
        {
            CLOCK_TUPLE_MUX_CSC_REG(connection) = MC_CGM_MUX_5_CSC_SELCTL(src);
        }
    }
}

/* ProgressiveClockFrequencySwitch */
void CLOCK_ProgressiveClockFrequencySwitch(clock_attach_id_t connection, clock_pcfs_config_t const *config)
{
    assert(config != NULL);

    uint32_t src = connection & 0xFFU;

    /* Only MUX_0 supported. */
    assert(((connection & 0xFF00U) >> 8U) == 0U);

    uint32_t Finput = 0U;
    uint32_t Fsafe  = 0U;
    uint32_t Rate   = 0U;
    uint32_t Amax, i, temp1, temp2, temp3, k;

    uint32_t sdur;
    uint32_t divcInit;
    uint32_t divcRate;
    uint64_t divStartValue;
    uint32_t divEndValue;

    Finput = config->clkSrcFreq / 1000000U;
    Fsafe  = CLOCK_GetFircClkFreq() / 1000000U;

    Amax = (config->maxAllowableIDDchange * 1000000U / (Finput * CLOCK_IP_DYNAMIC_IDD_CHANGE));
    Rate = Amax;

    /* Round pcfs rate by rounding amax */
    if (Amax <= AMax[0U])
    {
        Rate = PcfsRate[0U];
    }
    else if (Amax >= AMax[CLOCK_IP_A_MAX_SIZE - 1U])
    {
        Rate = PcfsRate[CLOCK_IP_A_MAX_SIZE - 1U];
    }
    else
    {
        for (i = 1U; i < CLOCK_IP_A_MAX_SIZE; i++)
        {
            if (AMax[CLOCK_IP_A_MAX_SIZE - 1U] < Amax)
            {
                Rate = PcfsRate[i - 1U];
            }
        }
    }

    /* Calculate K by using formula k = ceil(0.5 + sqrt(0.25 - (2000 * (1 -(Finput/fsafe)) / Rate))) */

    temp1 = 256U + ((2048000 * Finput) / (Fsafe * Rate)) - (2048000 / Rate); /* * 1024. */
    temp2 = 1UL << 30U; /* The second-to-top bit is set: use 1uL<<30 for uint32 type  */
    temp3 = 0U;

    /* "one" starts at the highest power of four <= than the argument */
    while (temp2 > temp1)
    {
        temp2 = temp2 >> 2;
    }
    /* Implement sqrt from K formula by using a square-root computing in embedded C */
    while (temp2 != 0U)
    {
        if (temp1 >= (temp3 + temp2))
        {
            temp1 = temp1 - (temp3 + temp2);
            temp3 = temp3 + (temp2 << 1U);
        }

        temp3 = temp3 >> 1U;
        temp2 = temp2 >> 2U;
    }

    k = (64U + 127U + (temp3 << 2U)) >>
        7U; /* Calculated K from k = ceil(0.5 + sqrt(0.25 - (2000 * (1 -(Fi/Fsafe)) / Rate))) */

    sdur          = config->stepDuration * Fsafe;
    divcInit      = Rate * k;
    divcRate      = Rate;
    divStartValue = 999U + (((uint64_t)Rate * k * (k + 1U)) >> 1U);
    divEndValue   = (Finput * 1000U / Fsafe) - 1U;

    /* Configure pcfs registers */
    MC_CGM->PCFS_SDUR  = MC_CGM_PCFS_SDUR_SDUR(sdur);
    MC_CGM->PCFS_DIVC8 = MC_CGM_PCFS_DIVC8_RATE(divcRate) | MC_CGM_PCFS_DIVC8_INIT(divcInit);
    MC_CGM->PCFS_DIVE8 = MC_CGM_PCFS_DIVE8_DIVE(divEndValue);
    MC_CGM->PCFS_DIVS8 = MC_CGM_PCFS_DIVS8_DIVS((uint32_t)divStartValue);

    while ((CLOCK_TUPLE_MUX_CSS_REG(connection) & MC_CGM_MUX_0_CSS_SWIP_MASK) != 0)
    {
    }
    CLOCK_TUPLE_MUX_CSC_REG(connection) = (src << MC_CGM_MUX_0_CSC_SELCTL_SHIFT) | MC_CGM_MUX_0_CSC_CLK_SW_MASK |
                                          MC_CGM_MUX_0_CSC_RAMPDOWN_MASK | MC_CGM_MUX_0_CSC_RAMPUP_MASK;
    while ((CLOCK_TUPLE_MUX_CSS_REG(connection) & MC_CGM_MUX_0_CSS_CLK_SW_MASK) == 0)
    {
    }
    while ((CLOCK_TUPLE_MUX_CSS_REG(connection) & MC_CGM_MUX_0_CSS_SWIP_MASK) != 0)
    {
    }
}

void CLOCK_SelectSafeClock(clock_attach_id_t connection)
{
    uint32_t mux = (connection & 0xFF00U) >> 8U;

    if ((mux != 5U) && (mux != 6U) && (mux != 11U)) /* For hardware-controlled clock multiplexer. */
    {
        CLOCK_TUPLE_MUX_CSC_REG(connection) |= MC_CGM_MUX_0_CSC_SAFE_SW_MASK;

        while ((CLOCK_TUPLE_MUX_CSS_REG(connection) & MC_CGM_MUX_0_CSS_SAFE_SW_MASK) == 0)
        {
        }
    }
}

uint32_t CLOCK_GetClkSelectState(clock_attach_id_t connection)
{
    return ((CLOCK_TUPLE_MUX_CSS_REG(connection) & MC_CGM_MUX_5_CSS_SELSTAT_MASK) >> MC_CGM_MUX_5_CSS_SELSTAT_SHIFT);
}

uint32_t CLOCK_GetClkSwitchTriggerCause(clock_attach_id_t connection)
{
    uint32_t mux     = (connection & 0xFF00U) >> 8U;
    uint32_t trigger = 0U;

    if ((mux != 5U) && (mux != 6U) && (mux != 11U)) /* For hardware-controlled clock multiplexer. */
    {
        trigger = (CLOCK_TUPLE_MUX_CSS_REG(connection) & MC_CGM_MUX_0_CSS_SWTRG_MASK) >> MC_CGM_MUX_0_CSS_SWTRG_SHIFT;
    }

    return trigger;
}

void CLOCK_InitFxosc(const fxosc_config_t *config)
{
    CLOCK_EnableClock(kCLOCK_Fxosc);
    if ((FXOSC->STAT & FXOSC_STAT_OSC_STAT_MASK) != 0U)
    {
        FXOSC->CTRL &= ~FXOSC_CTRL_OSCON_MASK;                          /* Disable FXOSC first. */
        SDK_DelayAtLeastUs(2U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY); /*Wait for at least 2us
                                                                           before enabling FXOSC
                                                                           again. */
    }

    FXOSC->CTRL = config->workMode | FXOSC_CTRL_OSCON_MASK | FXOSC_CTRL_GM_SEL(config->overdriveProtect) |
                  FXOSC_CTRL_EOCV(config->startupDelay);

    while ((FXOSC->STAT & FXOSC_STAT_OSC_STAT_MASK) == 0U)
    {
    }

    g_xtal0Freq = config->freqHz;
}

#if defined(FSL_FEATURE_MC_CGM_HAS_SXOSC) && (FSL_FEATURE_MC_CGM_HAS_SXOSC != 0U)
void CLOCK_InitSxosc(bool enable, uint8_t startupDelay)
{
    if (enable)
    {
        CLOCK_EnableClock(kCLOCK_Sxosc); /* Check and enable SXOSC clock in MC_ME. */

        SXOSC->SXOSC_CTRL &= ~SXOSC_SXOSC_CTRL_OSCON_MASK;
        SXOSC->SXOSC_CTRL &= ~SXOSC_SXOSC_CTRL_EOCV_MASK;

        SXOSC->SXOSC_CTRL = SXOSC_SXOSC_CTRL_OSCON_MASK | SXOSC_SXOSC_CTRL_EOCV(startupDelay);

        while ((SXOSC->SXOSC_STAT & SXOSC_SXOSC_STAT_OSC_STAT_MASK) == 0U)
        {
        }
    }
    else
    {
        SXOSC->SXOSC_CTRL &= ~SXOSC_SXOSC_CTRL_OSCON_MASK;
        /* CLOCK_DisableClock(kCLOCK_Sxosc); */
    }
}
#endif /* FSL_FEATURE_MC_CGM_HAS_SXOSC */

void CLOCK_InitPll(const pll_config_t *config)
{
    uint32_t i;

    assert(config->stepSize <= 1023U);
    assert(config->stepNum <= 2047U);

    CLOCK_EnableClock(kCLOCK_Pll);

    if ((PLL->PLLCR & PLL_PLLCR_PLLPD_MASK) == 0U)
    {
        CLOCK_DeinitPll();
        SDK_DelayAtLeastUs(6U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    }

    PLL->PLLDV = PLL_PLLDV_ODIV2(config->postDiv) | PLL_PLLDV_RDIV(config->preDiv) | PLL_PLLDV_MFI(config->multiplier);

    if (config->workMode == kPLL_ModeFractional)
    {
        PLL->PLLFD =
            PLL_PLLFD_SDMEN_MASK | PLL_PLLFD_SDM2_MASK | PLL_PLLFD_SDM3_MASK | PLL_PLLFD_MFN(config->fracLoopDiv);
    }
    else
    {
        PLL->PLLFD = 0U;
    }

    if (config->workMode == kPLL_ModeSSCG)
    {
        assert(config->stepSize * config->stepNum < 18432U);
        PLL->PLLFM =
            PLL_PLLFM_SPREADCTL_MASK | PLL_PLLFM_STEPNO(config->stepNum) | PLL_PLLFM_STEPSIZE(config->stepSize);
        PLL->PLLFD = PLL_PLLFD_SDMEN_MASK;
    }
    else
    {
        PLL->PLLFM = PLL_PLLFM_SSCGBYP_MASK; /* Bypass SSCG. */
    }

    PLL->PLLCAL2 &= ~PLL_PLLCAL2_ULKCTL_MASK;
    PLL->PLLCAL2 |= PLL_PLLCAL2_ULKCTL(config->accuracy);

    for (i = 0U; i < PLL_PLLODIV_COUNT; i++)
    {
        if (config->outDiv[i] != 0U)
        {
            PLL->PLLODIV[i] &= ~PLL_PLLODIV_DIV_MASK;
            PLL->PLLODIV[i] |= PLL_PLLODIV_DIV(config->outDiv[i] - 1U);
        }
        else
        {
            /* Do nonthing. */;
        }
    }

    PLL->PLLCR &= ~PLL_PLLCR_PLLPD_MASK; /* Enable PLL.*/

    while ((PLL->PLLSR & PLL_PLLSR_LOCK_MASK) == 0U)
    {
    }

    for (i = 0U; i < PLL_PLLODIV_COUNT; i++)
    {
        if (config->outDiv[i] != 0U)
        {
            PLL->PLLODIV[i] |= PLL_PLLODIV_DE_MASK;
        }
        else
        {
            PLL->PLLODIV[i] &= ~PLL_PLLODIV_DE_MASK;
        }
    }
}

uint32_t CLOCK_GetPllPhiClkFreq(uint32_t index)
{
    uint32_t freq   = 0U;
    uint32_t div    = 0U;
    uint32_t temp   = 0U;
    uint64_t temp64 = 0U;

    assert(index < PLL_PLLODIV_COUNT);

    if (((PLL->PLLCR & PLL_PLLCR_PLLPD_MASK) == 0U) && ((PLL->PLLODIV[index] & PLL_PLLODIV_DE_MASK) != 0U))
    {
        div = (PLL->PLLDV & PLL_PLLDV_RDIV_MASK) >> PLL_PLLDV_RDIV_SHIFT;
        div = (div == 0U) ? 1U : div;

        if ((PLL->PLLFD & PLL_PLLFD_SDMEN_MASK) != 0U) /* Fractional mode. */
        {
            freq   = CLOCK_GetFxoscFreq() / 1000U / div;
            temp   = (PLL->PLLDV & PLL_PLLDV_MFI_MASK) >> PLL_PLLDV_MFI_SHIFT;
            temp64 = (uint64_t)temp * 18432U + (uint64_t)(PLL->PLLFD & PLL_PLLFD_MFN_MASK);
            temp64 = temp64 * 1000U / 18432U;
            freq   = (uint32_t)((uint64_t)freq * temp64);
        }
        else
        {
            freq = CLOCK_GetFxoscFreq() * ((PLL->PLLDV & PLL_PLLDV_MFI_MASK) >> PLL_PLLDV_MFI_SHIFT) / div;
        }

        freq /= (PLL->PLLDV & PLL_PLLDV_ODIV2_MASK) >> PLL_PLLDV_ODIV2_SHIFT;
        freq /= ((PLL->PLLODIV[index] & PLL_PLLODIV_DIV_MASK) >> PLL_PLLODIV_DIV_SHIFT) + 1U;
    }
    else
    {
        freq = 0U;
    }

    return freq;
}

uint32_t CLOCK_GetFircClkFreq(void)
{
    uint32_t fircDivSel = CONFIGURATION->CONFIG_REG_GPR & CONFIGURATION_CONFIG_REG_GPR_FIRC_DIV_SEL_MASK;
    uint32_t freq       = 0U;

    switch (fircDivSel)
    {
        case CONFIGURATION_CONFIG_REG_GPR_FIRC_DIV_SEL(3U):
            freq = CLOCK_FIRC_CLK_FREQ;
            break;
        case CONFIGURATION_CONFIG_REG_GPR_FIRC_DIV_SEL(2U):
            freq = CLOCK_FIRC_CLK_FREQ / 16U;
            break;
        default:
            freq = CLOCK_FIRC_CLK_FREQ / 2U;
            break;
    }

    return freq;
}

uint32_t CLOCK_GetFxoscFreq(void)
{
    uint32_t freq = 0U;
    if ((FXOSC->STAT & FXOSC_STAT_OSC_STAT_MASK) != 0U)
    {
        freq = g_xtal0Freq;
    }
    else
    {
        freq = 0U;
    }
    return freq;
}

#if defined(FSL_FEATURE_MC_CGM_HAS_SXOSC) && (FSL_FEATURE_MC_CGM_HAS_SXOSC != 0U)
uint32_t CLOCK_GetSxoscFreq(void)
{
    uint32_t freq = 0U;
    if ((SXOSC->SXOSC_STAT & SXOSC_SXOSC_STAT_OSC_STAT_MASK) != 0U)
    {
        freq = CLOCK_SXOSC_CLK_FREQ;
    }
    else
    {
        freq = 0U;
    }
    return freq;
}
#endif /* FSL_FEATURE_MC_CGM_HAS_SXOSC */

static inline uint32_t CLOCK_GetMux0ClkFreq(void)
{
    uint32_t freq = 0U;
    switch (MC_CGM->MUX_0_CSS & MC_CGM_MUX_0_CSS_SELSTAT_MASK)
    {
        case MC_CGM_MUX_0_CSS_SELSTAT(CLOCK_FIRC_CLK):
            freq = CLOCK_GetFircClkFreq();
            break;
        case MC_CGM_MUX_0_CSS_SELSTAT(CLOCK_PLL_PHI0_CLK):
            freq = CLOCK_GetPllPhiClkFreq(0U);
            break;
        default:
            break;
    }

    return freq;
}

uint32_t CLOCK_GetCoreClkFreq(void)
{
    uint32_t freq = 0U;

    if ((MC_CGM->MUX_0_DC_0 & MC_CGM_MUX_0_DC_0_DE_MASK) != 0U)
    {
        freq = CLOCK_GetMux0ClkFreq();
        freq = freq / (((MC_CGM->MUX_0_DC_0 & MC_CGM_MUX_0_DC_0_DIV_MASK) >> MC_CGM_MUX_0_DC_0_DIV_SHIFT) + 1U);
    }
    else
    {
        freq = 0U;
    }

    return freq;
}

uint32_t CLOCK_GetAipsPlatClkFreq(void)
{
    uint32_t freq = 0U;

    if ((MC_CGM->MUX_0_DC_1 & MC_CGM_MUX_0_DC_1_DE_MASK) != 0U)
    {
        freq = CLOCK_GetMux0ClkFreq();
        freq = freq / (((MC_CGM->MUX_0_DC_1 & MC_CGM_MUX_0_DC_1_DIV_MASK) >> MC_CGM_MUX_0_DC_1_DIV_SHIFT) + 1U);
    }
    else
    {
        freq = 0U;
    }

    return freq;
}

uint32_t CLOCK_GetAipsSlowClkFreq(void)
{
    uint32_t freq = 0U;

    if ((MC_CGM->MUX_0_DC_2 & MC_CGM_MUX_0_DC_2_DE_MASK) != 0U)
    {
        freq = CLOCK_GetMux0ClkFreq();
        freq = freq / (((MC_CGM->MUX_0_DC_2 & MC_CGM_MUX_0_DC_2_DIV_MASK) >> MC_CGM_MUX_0_DC_2_DIV_SHIFT) + 1U);
    }
    else
    {
        freq = 0U;
    }

    return freq;
}

uint32_t CLOCK_GetHseClkFreq(void)
{
    uint32_t freq = 0U;

    if ((MC_CGM->MUX_0_DC_3 & MC_CGM_MUX_0_DC_3_DE_MASK) != 0U)
    {
        freq = CLOCK_GetMux0ClkFreq();
        freq = freq / (((MC_CGM->MUX_0_DC_3 & MC_CGM_MUX_0_DC_3_DIV_MASK) >> MC_CGM_MUX_0_DC_3_DIV_SHIFT) + 1U);
    }
    else
    {
        freq = 0U;
    }

    return freq;
}

uint32_t CLOCK_GetDcmClkFreq(void)
{
    uint32_t freq = 0U;

    if ((MC_CGM->MUX_0_DC_4 & MC_CGM_MUX_0_DC_4_DE_MASK) != 0U)
    {
        freq = CLOCK_GetMux0ClkFreq();
        freq = freq / (((MC_CGM->MUX_0_DC_4 & MC_CGM_MUX_0_DC_4_DIV_MASK) >> MC_CGM_MUX_0_DC_4_DIV_SHIFT) + 1U);
    }
    else
    {
        freq = 0U;
    }

    return freq;
}

#if defined(FSL_FEATURE_MC_CGM_HAS_LBIST_CLK_DIV) && (FSL_FEATURE_MC_CGM_HAS_LBIST_CLK_DIV != 0U)
uint32_t CLOCK_GetLbistClkFreq(void)
{
    uint32_t freq = 0U;

    if ((MC_CGM->MUX_0_DC_5 & MC_CGM_MUX_0_DC_5_DE_MASK) != 0U)
    {
        freq = CLOCK_GetMux0ClkFreq();
        freq = freq / (((MC_CGM->MUX_0_DC_5 & MC_CGM_MUX_0_DC_5_DIV_MASK) >> MC_CGM_MUX_0_DC_5_DIV_SHIFT) + 1U);
    }
    else
    {
        freq = 0U;
    }

    return freq;
}
#endif /* FSL_FEATURE_MC_CGM_HAS_LBIST_CLK_DIV */

#if defined(FSL_FEATURE_CLOCK_HAS_QSPI) && (FSL_FEATURE_CLOCK_HAS_QSPI != 0U)
uint32_t CLOCK_GetQspiClkFreq(void)
{
    uint32_t freq = 0U;

    if ((MC_CGM->MUX_0_DC_6 & MC_CGM_MUX_0_DC_6_DE_MASK) != 0U)
    {
        freq = CLOCK_GetMux0ClkFreq();
        freq = freq / (((MC_CGM->MUX_0_DC_6 & MC_CGM_MUX_0_DC_6_DIV_MASK) >> MC_CGM_MUX_0_DC_6_DIV_SHIFT) + 1U);
    }
    else
    {
        freq = 0U;
    }

    return freq;
}
#endif /* FSL_FEATURE_CLOCK_HAS_QSPI */

uint32_t CLOCK_GetStmClkFreq(uint32_t index)
{
    uint32_t freq = 0U;
    uint32_t mux  = index + 1U;

    assert(index < 2U);

    if ((CLOCK_MUX_DC_REG(mux, 0U) & MC_CGM_MUX_1_DC_0_DE_MASK) != 0U)
    {
        switch (CLOCK_MUX_CSS_REG(mux) & MC_CGM_MUX_1_CSS_SELSTAT_MASK)
        {
            case MC_CGM_MUX_1_CSS_SELSTAT(CLOCK_FIRC_CLK):
                freq = CLOCK_GetFircClkFreq();
                break;
            case MC_CGM_MUX_1_CSS_SELSTAT(CLOCK_FXOSC_CLK):
                freq = CLOCK_GetFxoscFreq();
                break;
            case MC_CGM_MUX_1_CSS_SELSTAT(CLOCK_AIPS_PLAT_CLK):
                freq = CLOCK_GetAipsPlatClkFreq();
                break;
            default:
                break;
        }

        freq /= ((CLOCK_MUX_DC_REG(mux, 0U) & MC_CGM_MUX_1_DC_0_DIV_MASK) >> MC_CGM_MUX_1_DC_0_DIV_SHIFT) + 1U;
    }
    else
    {
        freq = 0U;
    }

    return freq;
}

#if defined(FSL_FEATURE_CLOCK_HAS_EMAC) && (FSL_FEATURE_CLOCK_HAS_EMAC != 0U)
void CLOCK_SetEmacRmiiTxClkFreq(uint32_t freq)
{
    g_emacRmiiTxClkFreq = freq;
}

void CLOCK_SetEmacRxClkFreq(uint32_t freq)
{
    g_emacRxClkFreq = freq;
}

uint32_t CLOCK_GetEmacRxClkFreq(void)
{
    uint32_t freq = 0U;

    if ((CLOCK_MUX_DC_REG(7U, 0U) & MC_CGM_MUX_7_DC_0_DE_MASK) != 0U)
    {
        switch (CLOCK_MUX_CSS_REG(7U) & MC_CGM_MUX_7_CSS_SELSTAT_MASK)
        {
            case MC_CGM_MUX_7_CSS_SELSTAT(CLOCK_FIRC_CLK):
                freq = CLOCK_GetFircClkFreq();
                break;
            case MC_CGM_MUX_7_CSS_SELSTAT(CLOCK_EMAC_RMII_TX_CLK):
                freq = g_emacRmiiTxClkFreq;
                break;
            case MC_CGM_MUX_7_CSS_SELSTAT(CLOCK_EMAC_RX_CLK):
                freq = g_emacRxClkFreq;
                break;
            default:
                break;
        }

        freq /= ((CLOCK_MUX_DC_REG(7U, 0U) & MC_CGM_MUX_7_DC_0_DIV_MASK) >> MC_CGM_MUX_7_DC_0_DIV_SHIFT) + 1U;
    }
    else
    {
        freq = 0U;
    }

    return freq;
}

uint32_t CLOCK_GetEmacTxClkFreq(void)
{
    uint32_t freq = 0U;

    if ((CLOCK_MUX_DC_REG(8U, 0U) & MC_CGM_MUX_8_DC_0_DE_MASK) != 0U)
    {
        switch (CLOCK_MUX_CSS_REG(8U) & MC_CGM_MUX_8_CSS_SELSTAT_MASK)
        {
            case MC_CGM_MUX_8_CSS_SELSTAT(CLOCK_FIRC_CLK):
                freq = CLOCK_GetFircClkFreq();
                break;
            case MC_CGM_MUX_8_CSS_SELSTAT(CLOCK_EMAC_RMII_TX_CLK):
                freq = g_emacRmiiTxClkFreq;
                break;
            default:
                break;
        }

        freq /= ((CLOCK_MUX_DC_REG(8U, 0U) & MC_CGM_MUX_8_DC_0_DIV_MASK) >> MC_CGM_MUX_8_DC_0_DIV_SHIFT) + 1U;
    }
    else
    {
        freq = 0U;
    }

    return freq;
}

uint32_t CLOCK_GetEmacTsClkFreq(void)
{
    uint32_t freq = 0U;

    if ((CLOCK_MUX_DC_REG(9U, 0U) & MC_CGM_MUX_9_DC_0_DE_MASK) != 0U)
    {
        switch (CLOCK_MUX_CSS_REG(9U) & MC_CGM_MUX_9_CSS_SELSTAT_MASK)
        {
            case MC_CGM_MUX_9_CSS_SELSTAT(CLOCK_FIRC_CLK):
                freq = CLOCK_GetFircClkFreq();
                break;
            case MC_CGM_MUX_9_CSS_SELSTAT(CLOCK_FXOSC_CLK):
                freq = CLOCK_GetFxoscFreq();
                break;
            case MC_CGM_MUX_9_CSS_SELSTAT(CLOCK_PLL_PHI0_CLK):
                freq = CLOCK_GetPllPhiClkFreq(0U);
                break;
            case MC_CGM_MUX_9_CSS_SELSTAT(CLOCK_EMAC_RMII_TX_CLK):
                freq = g_emacRmiiTxClkFreq;
                break;
            case MC_CGM_MUX_9_CSS_SELSTAT(CLOCK_EMAC_RX_CLK):
                freq = g_emacRxClkFreq;
                break;
            default:
                break;
        }

        freq /= ((CLOCK_MUX_DC_REG(9U, 0U) & MC_CGM_MUX_9_DC_0_DIV_MASK) >> MC_CGM_MUX_9_DC_0_DIV_SHIFT) + 1U;
    }
    else
    {
        freq = 0U;
    }

    return freq;
}
#endif /* FSL_FEATURE_CLOCK_HAS_EMAC */

#if defined(FSL_FEATURE_CLOCK_HAS_QSPI) && (FSL_FEATURE_CLOCK_HAS_QSPI != 0U)
uint32_t CLOCK_GetQspiSfckFreq(void)
{
    uint32_t freq = 0U;

    if ((CLOCK_MUX_DC_REG(10U, 0U) & MC_CGM_MUX_10_DC_0_DE_MASK) != 0U)
    {
        switch (CLOCK_MUX_CSS_REG(10U) & MC_CGM_MUX_10_CSS_SELSTAT_MASK)
        {
            case MC_CGM_MUX_10_CSS_SELSTAT(CLOCK_FIRC_CLK):
                freq = CLOCK_GetFircClkFreq();
                break;
            case MC_CGM_MUX_10_CSS_SELSTAT(CLOCK_FXOSC_CLK):
                freq = CLOCK_GetFxoscFreq();
                break;
            case MC_CGM_MUX_10_CSS_SELSTAT(CLOCK_PLL_PHI1_CLK):
                freq = CLOCK_GetPllPhiClkFreq(1U);
                break;
            default:
                break;
        }

        freq /= ((CLOCK_MUX_DC_REG(10U, 0U) & MC_CGM_MUX_10_DC_0_DIV_MASK) >> MC_CGM_MUX_10_DC_0_DIV_SHIFT) + 1U;
    }
    else
    {
        freq = 0U;
    }

    return freq;
}
#endif

uint32_t CLOCK_GetFlexcanPeClkFreq(uint32_t index)
{
    uint32_t freq = 0U;
    assert(index < 6U);
    if (index < 3U)
    {
        if ((MC_CGM->MUX_3_DC_0 & MC_CGM_MUX_3_DC_0_DE_MASK) != 0U)
        {
            switch (MC_CGM->MUX_3_CSS & MC_CGM_MUX_3_CSS_SELSTAT_MASK)
            {
                case MC_CGM_MUX_3_CSS_SELSTAT(CLOCK_FIRC_CLK):
                    freq = CLOCK_GetFircClkFreq();
                    break;
                case MC_CGM_MUX_3_CSS_SELSTAT(CLOCK_FXOSC_CLK):
                    freq = CLOCK_GetFxoscFreq();
                    break;
                case MC_CGM_MUX_3_CSS_SELSTAT(CLOCK_AIPS_PLAT_CLK):
                    freq = CLOCK_GetAipsPlatClkFreq();
                    break;
                default:
                    break;
            }

            freq /= ((MC_CGM->MUX_3_DC_0 & MC_CGM_MUX_3_DC_0_DIV_MASK) >> MC_CGM_MUX_3_DC_0_DIV_SHIFT) + 1U;
        }
        else
        {
            freq = 0U;
        }
    }
#if defined(FSL_FEATURE_MC_CGM_HAS_MUX_4) && (FSL_FEATURE_MC_CGM_HAS_MUX_4 != 0U)
    else
    {
        if ((MC_CGM->MUX_4_DC_0 & MC_CGM_MUX_4_DC_0_DE_MASK) != 0U)
        {
            switch (MC_CGM->MUX_4_CSS & MC_CGM_MUX_4_CSS_SELSTAT_MASK)
            {
                case MC_CGM_MUX_4_CSS_SELSTAT(CLOCK_FIRC_CLK):
                    freq = CLOCK_GetFircClkFreq();
                    break;
                case MC_CGM_MUX_4_CSS_SELSTAT(CLOCK_FXOSC_CLK):
                    freq = CLOCK_GetFxoscFreq();
                    break;
                case MC_CGM_MUX_4_CSS_SELSTAT(CLOCK_AIPS_PLAT_CLK):
                    freq = CLOCK_GetAipsPlatClkFreq();
                    break;
                default:
                    break;
            }
            freq /= ((MC_CGM->MUX_4_DC_0 & MC_CGM_MUX_4_DC_0_DIV_MASK) >> MC_CGM_MUX_4_DC_0_DIV_SHIFT) + 1U;
        }
        else
        {
            freq = 0U;
        }
    }
#endif /* FSL_FEATURE_MC_CGM_HAS_MUX_4 */

    return freq;
}

uint32_t CLOCK_GetFreq(clock_name_t name)
{
    uint32_t freq = 0U;

    switch (name)
    {
        case kCLOCK_CoreSysClk:
        case kCLOCK_Adc0Clk:
        case kCLOCK_Adc1Clk:
#if defined(FSL_FEATURE_SOC_ADC_COUNT) && (FSL_FEATURE_SOC_ADC_COUNT > 2U)
        case kCLOCK_Adc2Clk:
#endif /* FSL_FEATURE_SOC_ADC_COUNT */
        case kCLOCK_BctuClk:
        case kCLOCK_EmiosClk:
        case kCLOCK_FlexioClk:
            freq = CLOCK_GetCoreClkFreq();
            break;
        case kCLOCK_AipsPlatClk: /* AIPS_PLAT_CLK*/
        case kCLOCK_Lpspi0Clk:
        case kCLOCK_Lpuart0Clk:
#if defined(FSL_FEATURE_SOC_LPUART_COUNT) && (FSL_FEATURE_SOC_LPUART_COUNT > 8U)
        case kCLOCK_Lpuart8Clk:
#endif /* FSL_FEATURE_SOC_LPUART_COUNT */
            freq = CLOCK_GetAipsPlatClkFreq();
            break;
        case kCLOCK_AipsSlowClk: /* AIPS_SLOW_CLK */
        case kCLOCK_Cmp0Clk:
#if defined(FSL_FEATURE_SOC_LPCMP_COUNT) && (FSL_FEATURE_SOC_LPCMP_COUNT > 1U)
        case kCLOCK_Cmp1Clk:
#endif /* FSL_FEATURE_SOC_LPCMP_COUNT */
#if defined(FSL_FEATURE_SOC_LPCMP_COUNT) && (FSL_FEATURE_SOC_LPCMP_COUNT > 2U)
        case kCLOCK_Cmp2Clk:
#endif /* FSL_FEATURE_SOC_LPCMP_COUNT */
        case kCLOCK_Lpi2c0Clk:
        case kCLOCK_Lpi2c1Clk:
        case kCLOCK_Lpspi1Clk:
        case kCLOCK_Lpspi2Clk:
        case kCLOCK_Lpspi3Clk:
#if defined(FSL_FEATURE_SOC_LPSPI_COUNT) && (FSL_FEATURE_SOC_LPSPI_COUNT > 4U)
        case kCLOCK_Lpspi4Clk:
        case kCLOCK_Lpspi5Clk:
#endif /* FSL_FEATURE_SOC_LPSPI_COUNT */
        case kCLOCK_Lpuart1Clk:
        case kCLOCK_Lpuart2Clk:
        case kCLOCK_Lpuart3Clk:
#if defined(FSL_FEATURE_SOC_LPUART_COUNT) && (FSL_FEATURE_SOC_LPUART_COUNT > 4U)
        case kCLOCK_Lpuart4Clk:
        case kCLOCK_Lpuart5Clk:
        case kCLOCK_Lpuart6Clk:
        case kCLOCK_Lpuart7Clk:
#endif /* FSL_FEATURE_SOC_LPUART_COUNT */
#if defined(FSL_FEATURE_SOC_LPUART_COUNT) && (FSL_FEATURE_SOC_LPUART_COUNT > 8U)
        case kCLOCK_Lpuart9Clk:
        case kCLOCK_Lpuart10Clk:
        case kCLOCK_Lpuart11Clk:
        case kCLOCK_Lpuart12Clk:
        case kCLOCK_Lpuart13Clk:
        case kCLOCK_Lpuart14Clk:
        case kCLOCK_Lpuart15Clk:
#endif /* FSL_FEATURE_SOC_LPUART_COUNT */
        case kCLOCK_Pit0Clk:
        case kCLOCK_Pit1Clk:
#if defined(FSL_FEATURE_SOC_PIT_COUNT) && (FSL_FEATURE_SOC_PIT_COUNT > 2U)
        case kCLOCK_Pit2Clk:
#endif /* FSL_FEATURE_SOC_PIT_COUNT */
#if defined(FSL_FEATURE_SOC_I2S_COUNT) && (FSL_FEATURE_SOC_I2S_COUNT != 0U)
        case kCLOCK_Sai0Clk:
        case kCLOCK_Sai1Clk:
#endif /* FSL_FEATURE_SOC_I2S_COUNT */
            freq = CLOCK_GetAipsSlowClkFreq();
            break;
        case kCLOCK_HseClk:
            freq = CLOCK_GetHseClkFreq();
            break;
        case kCLOCK_DcmClk:
            freq = CLOCK_GetDcmClkFreq();
            break;
#if defined(FSL_FEATURE_MC_CGM_HAS_LBIST_CLK_DIV) && (FSL_FEATURE_MC_CGM_HAS_LBIST_CLK_DIV != 0U)
        case kCLOCK_LbistClk:
            freq = CLOCK_GetLbistClkFreq();
            break;
#endif /* FSL_FEATURE_MC_CGM_HAS_LBIST_CLK_DIV */
#if defined(FSL_FEATURE_CLOCK_HAS_QSPI) && (FSL_FEATURE_CLOCK_HAS_QSPI != 0U)
        case kCLOCK_QspiClk:
            freq = CLOCK_GetQspiClkFreq();
            break;
#endif /* FSL_FEATURE_CLOCK_HAS_QSPI */
        case kCLOCK_FircClk:
            freq = CLOCK_GetFircClkFreq();
            break;
        case kCLOCK_SircClk:
            freq = CLOCK_SIRC_CLK_FREQ;
            break;
        case kCLOCK_FxoscClk:
            freq = CLOCK_GetFxoscFreq();
            break;
#if defined(FSL_FEATURE_MC_CGM_HAS_SXOSC) && (FSL_FEATURE_MC_CGM_HAS_SXOSC != 0U)
        case kCLOCK_SxoscClk:
            freq = CLOCK_GetSxoscFreq();
            break;
#endif /* FSL_FEATURE_MC_CGM_HAS_SXOSC */
        case kCLOCK_PllPhi0Clk:
            freq = CLOCK_GetPllPhiClkFreq(0U);
            break;
        case kCLOCK_PllPhi1Clk:
            freq = CLOCK_GetPllPhiClkFreq(1U);
            break;
        case kCLOCK_Flexcan0Clk:
            freq = CLOCK_GetFlexcanPeClkFreq(0);
            break;
        case kCLOCK_Flexcan1Clk:
            freq = CLOCK_GetFlexcanPeClkFreq(1);
            break;
        case kCLOCK_Flexcan2Clk:
            freq = CLOCK_GetFlexcanPeClkFreq(2);
            break;
#if defined(FSL_FEATURE_SOC_FLEXCAN_COUNT) && (FSL_FEATURE_SOC_FLEXCAN_COUNT > 3U)
        case kCLOCK_Flexcan3Clk:
            freq = CLOCK_GetFlexcanPeClkFreq(3);
            break;
        case kCLOCK_Flexcan4Clk:
            freq = CLOCK_GetFlexcanPeClkFreq(4);
            break;
        case kCLOCK_Flexcan5Clk:
            freq = CLOCK_GetFlexcanPeClkFreq(5);
            break;
#endif /* FSL_FEATURE_SOC_FLEXCAN_COUNT > 3U */
        case kCLOCK_Stm0Clk:
            freq = CLOCK_GetStmClkFreq(0U);
            break;
#if defined(FSL_FEATURE_SOC_STM_COUNT) && (FSL_FEATURE_SOC_STM_COUNT == 2U)
        case kCLOCK_Stm1Clk:
            freq = CLOCK_GetStmClkFreq(1U);
            break;
#endif /* FSL_FEATURE_SOC_STM_COUNT == 2U */
#if defined(FSL_FEATURE_CLOCK_HAS_QSPI) && (FSL_FEATURE_CLOCK_HAS_QSPI > 0U)
        case kCLOCK_QspiSfClk:
            freq = CLOCK_GetQspiSfckFreq();
            break;
#endif /* FSL_FEATURE_CLOCK_HAS_QSPI */
        default:
            freq = 0U;
    }

    return freq;
}
