/*
 * Copyright 2021, 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_hscmp.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.hscmp"
#endif

#if defined(HSCMP_RSTS)
#define HSCMP_RESETS_ARRAY HSCMP_RSTS
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to HSCMP bases for each instance. */
static HSCMP_Type *const s_hscmpBases[] = HSCMP_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to HSCMP clocks for each instance. */
static const clock_ip_name_t s_hscmpClocks[] = HSCMP_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(HSCMP_RESETS_ARRAY)
/* Reset array */
static const reset_ip_name_t s_hscmpResets[] = HSCMP_RESETS_ARRAY;
#endif

/*******************************************************************************
 * Codes
 ******************************************************************************/
/*!
 * @brief Get instance number for HSCMP module.
 *
 * @param base HSCMP peripheral base address
 * @return Instance number if valid base address is provided, otherwise returns 0xFFFFFFFF
 */
uint32_t HSCMP_GetInstance(HSCMP_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_hscmpBases); instance++)
    {
        if (MSDK_REG_NONSECURE_ADDR(s_hscmpBases[instance]) == MSDK_REG_NONSECURE_ADDR(base))
        {
            break;
        }
    }

    if (instance == ARRAY_SIZE(s_hscmpBases))
    {
        instance = 0xFFFFFFFFU; /* Return 0xFFFFFFFF if invalid base address is provided. */
    }

    return instance;
}

/*!
 * @brief Initialize the HSCMP
 *
 * This function initializes the HSCMP module. The operations included are:
 * - Enabling the clock for HSCMP module.
 * - Configuring the comparator.
 * - Enabling the HSCMP module optionally.
 * @note For some devices, multiple HSCMP instance share the same clock gate. In this case, to enable the clock for
 * any instance enables all the HSCMPs. Check the chip reference manual for the clock assignment of the HSCMP.
 *
 * @param base HSCMP peripheral base address.
 * @param config Pointer to "hscmp_config_t" structure.
 */
void HSCMP_Init(HSCMP_Type *base, const hscmp_config_t *config)
{
    assert(config != NULL);

    uint32_t tmp32;
    uint32_t instance = HSCMP_GetInstance(base);

    if (instance >= ARRAY_SIZE(s_hscmpBases))
    {
        /* Invalid instance, do not attempt to initialize */
        return;
    }

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(s_hscmpClocks[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(HSCMP_RESETS_ARRAY)
    RESET_ReleasePeripheralReset(s_hscmpResets[instance]);
#endif

    /* CCR0 register, disable comparator. */
    tmp32 = base->CCR0;
    tmp32 &= ~(HSCMP_CCR0_CMP_STOP_EN_MASK | HSCMP_CCR0_CMP_EN_MASK);
    tmp32 |= config->enableStopMode ? HSCMP_CCR0_CMP_STOP_EN_MASK : 0U;
#if (defined(FSL_FEATURE_HSCMP_HAS_LINKEN) && FSL_FEATURE_HSCMP_HAS_LINKEN)
    tmp32 &= ~HSCMP_CCR0_LINKEN_MASK;
    tmp32 |= config->enableDacLink ? HSCMP_CCR0_LINKEN_MASK : 0U;
#endif
    base->CCR0 = tmp32;

    /* CCR1 register. */
    tmp32 = base->CCR1;
    tmp32 &= ~(HSCMP_CCR1_COUT_PEN_MASK | HSCMP_CCR1_COUT_SEL_MASK | HSCMP_CCR1_COUT_INV_MASK);
    tmp32 |= config->enableOutputPin ? HSCMP_CCR1_COUT_PEN_MASK : 0U;
    tmp32 |= config->useUnfilteredOutput ? HSCMP_CCR1_COUT_SEL_MASK : 0U;
    tmp32 |= config->enableInvertOutput ? HSCMP_CCR1_COUT_INV_MASK : 0U;
#if (defined(FSL_FEATURE_HSCMP_HAS_FUNC_CLK_SEL) && FSL_FEATURE_HSCMP_HAS_FUNC_CLK_SEL)
    tmp32 &= ~HSCMP_CCR1_FUNC_CLK_SEL_MASK;
    tmp32 |= HSCMP_CCR1_FUNC_CLK_SEL(config->funcClockSel);
#endif
    base->CCR1 = tmp32;

    /* CCR2 register. */
    tmp32 = base->CCR2;
    tmp32 &= ~HSCMP_CCR2_HYSTCTR_MASK;
    tmp32 |= HSCMP_CCR2_HYSTCTR(config->hysteresisMode);
#if (defined(FSL_FEATURE_HSCMP_HAS_PWR_MODE_SELECT) && FSL_FEATURE_HSCMP_HAS_PWR_MODE_SELECT)
    tmp32 &= ~(HSCMP_CCR2_CMP_HPMD_MASK | HSCMP_CCR2_CMP_NPMD_MASK);
    tmp32 |= ((uint32_t)(config->powerMode) << HSCMP_CCR2_CMP_HPMD_SHIFT);
#endif
#if (defined(FSL_FEATURE_HSCMP_HAS_OFFSET) && FSL_FEATURE_HSCMP_HAS_OFFSET)
    tmp32 &= ~HSCMP_CCR2_OFFSET_MASK;
    tmp32 |= config->enableOffset ? HSCMP_CCR2_OFFSET_MASK : 0U;
#endif
    base->CCR2 = tmp32;

    HSCMP_Enable(base, config->enableComparator); /* Enable the HSCMP module optionally. */
}

/*!
 * @brief De-initializes the HSCMP module.
 *
 * This function de-initializes the HSCMP module. The operations included are:
 * - Disabling the HSCMP module.
 * - Disabling the clock for HSCMP module.
 *
 * This function disables the clock for the HSCMP.
 * @note For some devices, multiple HSCMP instance shares the same clock gate. In this case, before disabling the
 * clock for the HSCMP, ensure that all the HSCMP instances are not used.
 *
 * @param base HSCMP peripheral base address.
 */
void HSCMP_Deinit(HSCMP_Type *base)
{
    uint32_t instance = HSCMP_GetInstance(base);

    if (instance >= ARRAY_SIZE(s_hscmpBases))
    {
        /* Invalid instance, do not attempt to initialize */
        return;
    }

    /* Disable the HSCMP module. */
    HSCMP_Enable(base, false);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(s_hscmpClocks[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(HSCMP_RESETS_ARRAY)
    RESET_PeripheralReset(s_hscmpResets[instance]);
#endif
}

/*!
 * @brief Gets an available pre-defined settings for the comparator's configuration.
 *
 * This function initializes the comparator configuration structure to these default values:
 * @code
 *   config->enableComparator    = true;
 *   config->enableStopMode      = false;
 *   config->enableOutputPin     = false;
 *   config->useUnfilteredOutput = false;
 *   config->enableInvertOutput  = false;
 *   config->hysteresisMode      = kHSCMP_HysteresisLevel0;
 *   config->powerMode           = kHSCMP_LowSpeedPowerMode;
 * @endcode
 * @param config Pointer to "hscmp_config_t" structure.
 */
void HSCMP_GetDefaultConfig(hscmp_config_t *config)
{
    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->enableComparator    = true;
    config->enableStopMode      = false;
    config->enableOutputPin     = false;
    config->useUnfilteredOutput = false;
    config->enableInvertOutput  = false;
    config->hysteresisMode      = kHSCMP_HysteresisLevel0;
#if (defined(FSL_FEATURE_HSCMP_HAS_PWR_MODE_SELECT) && FSL_FEATURE_HSCMP_HAS_PWR_MODE_SELECT)
    config->powerMode           = kHSCMP_LowSpeedPowerMode;
#endif
#if (defined(FSL_FEATURE_HSCMP_HAS_LINKEN) && FSL_FEATURE_HSCMP_HAS_LINKEN)
    config->enableDacLink       = false;
#endif
#if (defined(FSL_FEATURE_HSCMP_HAS_OFFSET) && FSL_FEATURE_HSCMP_HAS_OFFSET)
    config->enableOffset        = false;
#endif
#if (defined(FSL_FEATURE_HSCMP_HAS_FUNC_CLK_SEL) && FSL_FEATURE_HSCMP_HAS_FUNC_CLK_SEL)
    config->funcClockSel        = kHSCMP_FuncClockSource0;
#endif
}

/*!
 * @brief Select the input channels for HSCMP. This function determines which input
 *        is selected for the negative and positive Analog Mux.
 *
 * @param base HSCMP peripheral base address.
 * @param positiveChannel Positive side Analog Mux input channel number. Available range is 0-7.
 * @param negativeChannel Negative side Analog Mux input channel number. Available range is 0-7.
 */
void HSCMP_SetInputChannels(HSCMP_Type *base, uint32_t positiveChannel, uint32_t negativeChannel)
{
    uint32_t tmp32;

    tmp32 = base->CCR2;
    tmp32 &= ~(HSCMP_CCR2_PSEL_MASK | HSCMP_CCR2_MSEL_MASK);
    tmp32 |= HSCMP_CCR2_PSEL(positiveChannel) | HSCMP_CCR2_MSEL(negativeChannel);
    base->CCR2 = tmp32;
}

#if (defined(FSL_FEATURE_HSCMP_HAS_INPUT_SELECT) && FSL_FEATURE_HSCMP_HAS_INPUT_SELECT)
/*!
 * @brief Select the high-level input source for the Plus and Minus comparator ports.
 *
 * Configures CCR2.INPSEL and CCR2.INMSEL to choose between the internal DAC output
 * (IN0) and the analog 8-to-1 mux path (IN1, whose channel is selected by PSEL/MSEL).
 * Call @ref HSCMP_SetInputChannels to set the PSEL/MSEL channel when using
 * @ref kHSCMP_InputFromAnalogMux.
 *
 * @param base  HSCMP peripheral base address.
 * @param plus  Plus input of the comparator. See @ref hscmp_input_t.
 * @param minus Minus input of the comparator. See @ref hscmp_input_t.
 */
void HSCMP_SetInputMux(HSCMP_Type *base, hscmp_input_t plus, hscmp_input_t minus)
{
    uint32_t tmp32 = base->CCR2;
    tmp32 &= ~(HSCMP_CCR2_INPSEL_MASK | HSCMP_CCR2_INMSEL_MASK);
    tmp32 |= HSCMP_CCR2_INPSEL(plus) | HSCMP_CCR2_INMSEL(minus);
    base->CCR2 = tmp32;
}
#endif

/*!
 * @brief Configures the filter.
 *
 * @param base HSCMP peripheral base address.
 * @param config Pointer to "hscmp_filter_config_t" structure.
 */
void HSCMP_SetFilterConfig(HSCMP_Type *base, const hscmp_filter_config_t *config)
{
    assert(config != NULL);

    uint32_t tmp32;

    tmp32 = base->CCR1;
    tmp32 &= ~(HSCMP_CCR1_FILT_PER_MASK | HSCMP_CCR1_FILT_CNT_MASK | HSCMP_CCR1_SAMPLE_EN_MASK);
    tmp32 |= config->enableSample ? HSCMP_CCR1_SAMPLE_EN_MASK : 0U;
    tmp32 |= HSCMP_CCR1_FILT_PER(config->filterSamplePeriod) | HSCMP_CCR1_FILT_CNT(config->filterSampleCount);
    base->CCR1 = tmp32;
}

/*!
 * @brief Configure the internal DAC module.
 *
 * @param base HSCMP peripheral base address.
 * @param config Pointer to "hscmp_dac_config_t" structure. If config is "NULL", disable internal DAC.
 */
void HSCMP_SetDACConfig(HSCMP_Type *base, const hscmp_dac_config_t *config)
{
    uint32_t tmp32;

    if (config == NULL)
    {
        tmp32 = 0U; /* Disable internal DAC. */
    }
    else
    {
        tmp32 = base->DCR;
        tmp32 &= ~(HSCMP_DCR_DAC_EN_MASK | HSCMP_DCR_DACOE_MASK | HSCMP_DCR_DAC_DATA_MASK);
        tmp32 |= config->enableDacOutput ? HSCMP_DCR_DACOE_MASK : 0U;
        tmp32 |= HSCMP_DCR_DAC_DATA(config->DACValue);
#if (defined(FSL_FEATURE_HSCMP_HAS_DAC_PWR_MODE_SELECT) && FSL_FEATURE_HSCMP_HAS_DAC_PWR_MODE_SELECT)
        tmp32 &= ~HSCMP_DCR_DAC_HPMD_MASK;
        tmp32 |= config->enableLowPowerMode ? HSCMP_DCR_DAC_HPMD_MASK : 0U;
#endif
#if (defined(FSL_FEATURE_HSCMP_HAS_DAC_REF_VOL_SELECT) && FSL_FEATURE_HSCMP_HAS_DAC_REF_VOL_SELECT)
        tmp32 &= ~HSCMP_DCR_VRSEL_MASK;
        tmp32 |= HSCMP_DCR_VRSEL(config->referenceVoltageSource);
#endif
#if (defined(FSL_FEATURE_HSCMP_HAS_DAC_STOP_EN) && FSL_FEATURE_HSCMP_HAS_DAC_STOP_EN)
        tmp32 &= ~HSCMP_DCR_DAC_STOP_EN_MASK;
        tmp32 |= config->enableDacStopMode ? HSCMP_DCR_DAC_STOP_EN_MASK : 0U;
#endif
        tmp32 |= HSCMP_DCR_DAC_EN_MASK;
    }

    base->DCR = tmp32;
}

/*!
 * @brief Configure the window mode with full control over all window-related options.
 *
 * Configures CCR1 window-related bits: WINDOW_EN, WINDOW_INV, WINDOW_CLS, EVT_SEL,
 * COUTA_OWEN, and COUTA_OW. All other CCR1 bits are preserved.
 *
 * @param base   HSCMP peripheral base address.
 * @param config Pointer to "hscmp_window_config_t" structure.
 */
void HSCMP_SetWindowConfig(HSCMP_Type *base, const hscmp_window_config_t *config)
{
    assert(config != NULL);

    uint32_t tmp32;

    tmp32 = base->CCR1;
    tmp32 &= ~(HSCMP_CCR1_WINDOW_EN_MASK | HSCMP_CCR1_WINDOW_INV_MASK | HSCMP_CCR1_WINDOW_CLS_MASK |
               HSCMP_CCR1_EVT_SEL_MASK | HSCMP_CCR1_COUTA_OWEN_MASK | HSCMP_CCR1_COUTA_OW_MASK);

    tmp32 |= config->enableWindowMode ? HSCMP_CCR1_WINDOW_EN_MASK : 0U;
    tmp32 |= config->enableWindowInvert ? HSCMP_CCR1_WINDOW_INV_MASK : 0U;
    tmp32 |= config->enableWindowCloseByEvent ? HSCMP_CCR1_WINDOW_CLS_MASK : 0U;
    tmp32 |= HSCMP_CCR1_EVT_SEL(config->windowEventSelect);
    tmp32 |= config->enableCoutaOwenMode ? HSCMP_CCR1_COUTA_OWEN_MASK : 0U;
    tmp32 |= config->coutaOwLevel ? HSCMP_CCR1_COUTA_OW_MASK : 0U;

    base->CCR1 = tmp32;
}

/*!
 * @brief Configure the round-robin comparison mode.
 *
 * Configures RRCR0 (enable, sample clocks, init delay), RRCR1 (channel enable mask,
 * fixed port, fixed channel), and RRCR2 (internal timer).
 *
 * @param base   HSCMP peripheral base address.
 * @param config Pointer to "hscmp_roundrobin_config_t" structure.
 */
void HSCMP_SetRoundRobinConfig(HSCMP_Type *base, const hscmp_roundrobin_config_t *config)
{
    assert(config != NULL);

    uint32_t tmp32;

    /* RRCR0: enable, sample clocks, initialization delay modulus. */
    tmp32 = base->RRCR0;
    tmp32 &= ~(HSCMP_RRCR0_RR_EN_MASK | HSCMP_RRCR0_RR_NSAM_MASK | HSCMP_RRCR0_RR_INITMOD_MASK);
    tmp32 |= config->enableRoundRobin ? HSCMP_RRCR0_RR_EN_MASK : 0U;
    tmp32 |= HSCMP_RRCR0_RR_NSAM(config->sampleClockCount);
    tmp32 |= HSCMP_RRCR0_RR_INITMOD(config->initDelayModulus);
#if (defined(FSL_FEATURE_HSCMP_HAS_RR_TRG_SEL) && FSL_FEATURE_HSCMP_HAS_RR_TRG_SEL)
    tmp32 &= ~HSCMP_RRCR0_RR_TRG_SEL_MASK;
    tmp32 |= HSCMP_RRCR0_RR_TRG_SEL(config->triggerSelect);
#endif
#if (defined(FSL_FEATURE_HSCMP_HAS_RR_CLK_SEL) && FSL_FEATURE_HSCMP_HAS_RR_CLK_SEL)
    tmp32 &= ~HSCMP_RRCR0_RR_CLK_SEL_MASK;
    tmp32 |= HSCMP_RRCR0_RR_CLK_SEL(config->rrClockSel);
#endif
#if (defined(FSL_FEATURE_HSCMP_HAS_RR_SAMPLE_CNT) && FSL_FEATURE_HSCMP_HAS_RR_SAMPLE_CNT)
    tmp32 &= ~HSCMP_RRCR0_RR_SAMPLE_CNT_MASK;
    tmp32 |= HSCMP_RRCR0_RR_SAMPLE_CNT(config->sampleCount);
#endif
#if (defined(FSL_FEATURE_HSCMP_HAS_RR_SAMPLE_THRESHOLD) && FSL_FEATURE_HSCMP_HAS_RR_SAMPLE_THRESHOLD)
    tmp32 &= ~HSCMP_RRCR0_RR_SAMPLE_THRESHOLD_MASK;
    tmp32 |= HSCMP_RRCR0_RR_SAMPLE_THRESHOLD(config->sampleThreshold);
#endif
    base->RRCR0 = tmp32;

    /* RRCR1: per-channel enable mask, fixed port, fixed channel. */
    tmp32 = base->RRCR1;
    tmp32 &= ~(HSCMP_RRCR1_RR_CHEN_MASK | HSCMP_RRCR1_FIXP_MASK | HSCMP_RRCR1_FIXCH_MASK);
    tmp32 |= (config->channelEnableMask & HSCMP_RRCR1_RR_CHEN_MASK) << HSCMP_RRCR1_RR_CHEN_SHIFT;
    tmp32 |= (config->fixedPort == kHSCMP_RoundRobinFixedMinusPort) ? HSCMP_RRCR1_FIXP_MASK : 0U;
    tmp32 |= HSCMP_RRCR1_FIXCH(config->fixedChannel);
    base->RRCR1 = tmp32;

    /* RRCR2: internal timer reload value and enable. */
    tmp32 = base->RRCR2;
    tmp32 &= ~(HSCMP_RRCR2_RR_TIMER_RELOAD_MASK | HSCMP_RRCR2_RR_TIMER_EN_MASK);
    tmp32 |= HSCMP_RRCR2_RR_TIMER_RELOAD(config->timerReloadValue);
    tmp32 |= config->enableRRTimer ? HSCMP_RRCR2_RR_TIMER_EN_MASK : 0U;
    base->RRCR2 = tmp32;
}
