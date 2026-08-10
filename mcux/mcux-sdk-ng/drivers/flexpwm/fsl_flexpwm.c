/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_flexpwm.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.flexpwm"
#endif

#if defined(PWM_RSTS)
#define FLEXPWM_RESETS_ARRAY PWM_RSTS
#elif defined(FLEXPWM_RSTS)
#define FLEXPWM_RESETS_ARRAY FLEXPWM_RSTS
#elif defined(FLEXPWM_RSTS_N)
#define FLEXPWM_RESETS_ARRAY FLEXPWM_RSTS_N
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Array to map FlexPWM instance number to base pointer. */
static PWM_Type *const s_flexpwmBases[] = PWM_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to FlexPWM clocks for each FlexPWM submodule. */
static const clock_ip_name_t s_flexpwmClocks[][FSL_FEATURE_PWM_SUBMODULE_COUNT] = PWM_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(FLEXPWM_RESETS_ARRAY)
/* Reset array */
static const reset_ip_name_t s_flexpwmResets[] = FLEXPWM_RESETS_ARRAY;
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Get the instance for FlexPWM module.
 *
 * @param base FlexPWM base address
 * @return Instance number if valid base address is provided, otherwise returns ARRAY_SIZE(s_flexpwmBases)
 */
uint32_t FLEXPWM_GetInstance(PWM_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_flexpwmBases); instance++)
    {
        if (MSDK_REG_NONSECURE_ADDR(s_flexpwmBases[instance]) == MSDK_REG_NONSECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_flexpwmBases));

    return instance;
}

/*!
 * @brief Initialize the FlexPWM module.
 *
 * This function initializes the FlexPWM peripheral by:
 * - Enabling clocks for all submodules (SM0-SM3)
 * - Releasing peripheral reset (if supported by platform)
 *
 * After calling this function, the FlexPWM module is ready for configuration.
 * Additional configuration functions (FLEXPWM_ConfigSubmodule, FLEXPWM_ConfigPWM, etc.)
 * should be called to set up the desired PWM behavior.
 *
 * @param base FlexPWM peripheral base address.
 * @return kStatus_Success if initialization is successful.
 *         kStatus_InvalidArgument if the base address is invalid.
 */
status_t FLEXPWM_Init(PWM_Type *base)
{
    uint32_t instance = FLEXPWM_GetInstance(base);

    if (instance >= ARRAY_SIZE(s_flexpwmBases))
    {
        /* Invalid instance, do not attempt to initialize */
        return kStatus_InvalidArgument;
    }

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)

    for (uint32_t i = 0; i < (uint32_t)FSL_FEATURE_PWM_SUBMODULE_COUNT; i++)
    {
        /* Ungate the FlexPWM submodule clock*/
        CLOCK_EnableClock(s_flexpwmClocks[instance][i]);
    }
#endif

#if defined(FLEXPWM_RESETS_ARRAY)
    RESET_ReleasePeripheralReset(s_flexpwmResets[instance]);
#endif

    return kStatus_Success;
}

/*!  
 * @brief Deinitialize the FlexPWM module.
 *
 * This function deinitializes the FlexPWM peripheral by:
 * - Disabling clocks for all submodules (SM0-SM3)
 * - Asserting peripheral reset (if supported by platform)
 *
 * After calling this function, all FlexPWM registers are reset.
 *
 * @param base FlexPWM peripheral base address.
 * @return kStatus_Success if deinitialization is successful.
 *         kStatus_InvalidArgument if the base address is invalid.
 */
status_t FLEXPWM_DeInit(PWM_Type *base)
{
    uint32_t instance = FLEXPWM_GetInstance(base);

    if (instance >= ARRAY_SIZE(s_flexpwmBases))
    {
        /* Invalid instance, do not attempt to deinitialize */
        return kStatus_InvalidArgument;
    }

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    for (uint32_t i = 0; i < (uint32_t)FSL_FEATURE_PWM_SUBMODULE_COUNT; i++)
    {
        /* Gate the FlexPWM submodule clock */
        CLOCK_DisableClock(s_flexpwmClocks[instance][i]);
    }
#endif

#if defined(FLEXPWM_RESETS_ARRAY)
    RESET_PeripheralReset(s_flexpwmResets[instance]);
#endif

    return kStatus_Success;
}

/*!
 * @brief Get default configuration for FlexPWM submodule.
 *
 * This function initializes the FlexPWM submodule configuration structure with safe default values.
 *
 * @param config Pointer to the submodule configuration structure.
 */
void FLEXPWM_GetDefaultSubmoduleConfig(flexpwm_submodule_config_t *config)
{
    assert(NULL != config);

    /* Set default clock source to IPBus clock with no prescaling */
    config->clockSource = kFLEXPWM_ClockSource_IPBusClock;
    config->prescaler = kFLEXPWM_Prescale_Divide_1;

    /* Set default counter configuration */
    config->counterConfig.initValue = 0U;
    config->counterConfig.modValue = 0xFFFFU;
    config->counterConfig.initSource = kFLEXPWM_InitSource_LocalSync;

    /* Set default reload configuration */
    config->reloadConfig.loadMode = kFLEXPWM_LoadMode_Opportunity;
    config->reloadConfig.loadFrequency = 0U;  /* Every PWM cycle */
    config->reloadConfig.enableHalfCycleReload = false;
    config->reloadConfig.enableFullCycleReload = true;
    config->reloadConfig.reloadSource = kFLEXPWM_ReloadSource_LocalReload;
    config->reloadConfig.halfCycleValue = 0x7FFFU;

    /* Set default operating modes: PWM stops in Debug and Wait modes */
    config->enableDebugMode = false;
#if !(defined(FSL_FEATURE_PWM_HAS_NO_WAITEN) && FSL_FEATURE_PWM_HAS_NO_WAITEN)
    config->enableWaitMode = false;
#endif
}

/*!
 * @brief Configure a FlexPWM submodule.
 *
 * This function configures the basic parameters of a FlexPWM submodule.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param config Pointer to the submodule configuration structure.
 */
void FLEXPWM_ConfigSubmodule(PWM_Type *base, uint8_t submodule, const flexpwm_submodule_config_t *config)
{
    assert(NULL != config);
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);

    uint16_t reg;

    /* Configure CTRL2 register: CLK_SEL, INIT_SEL, RELOAD_SEL, DBGEN, WAITEN */
    reg = base->SM[submodule].CTRL2;

    /* Clear all relevant bit fields in one operation */
#if !(defined(FSL_FEATURE_PWM_HAS_NO_WAITEN) && FSL_FEATURE_PWM_HAS_NO_WAITEN)
    reg &= MCUX_MASK_INVERT_16(PWM_CTRL2_CLK_SEL_MASK | PWM_CTRL2_INIT_SEL_MASK |
                                PWM_CTRL2_RELOAD_SEL_MASK | PWM_CTRL2_WAITEN_MASK |
                                PWM_CTRL2_DBGEN_MASK);
#else
    reg &= MCUX_MASK_INVERT_16(PWM_CTRL2_CLK_SEL_MASK | PWM_CTRL2_INIT_SEL_MASK |
                                PWM_CTRL2_RELOAD_SEL_MASK | PWM_CTRL2_DBGEN_MASK);
#endif

    /* Set new values using OR operations */
    reg |= PWM_CTRL2_CLK_SEL(config->clockSource) | PWM_CTRL2_INIT_SEL(config->counterConfig.initSource);

    /* Set conditional bits using ternary operators */
    reg = (config->reloadConfig.reloadSource == kFLEXPWM_ReloadSource_MasterReload) ?
          (reg | PWM_CTRL2_RELOAD_SEL_MASK) : reg;
    reg = (config->enableDebugMode) ? (reg | PWM_CTRL2_DBGEN_MASK) : reg;

#if !(defined(FSL_FEATURE_PWM_HAS_NO_WAITEN) && FSL_FEATURE_PWM_HAS_NO_WAITEN)
    reg = (config->enableWaitMode) ? (reg | PWM_CTRL2_WAITEN_MASK) : reg;
#endif

    /* Write back CTRL2 register */
    base->SM[submodule].CTRL2 = reg;

    /* Configure CTRL register: PRSC, LDMOD, LDFQ, HALF, FULL */
    reg = base->SM[submodule].CTRL;

    /* Clear all relevant bit fields */
    reg &= MCUX_MASK_INVERT_16(PWM_CTRL_PRSC_MASK | PWM_CTRL_LDMOD_MASK | PWM_CTRL_LDFQ_MASK |
                                PWM_CTRL_HALF_MASK | PWM_CTRL_FULL_MASK);

    /* Set prescaler (PRSC[6:4]) */
    reg |= PWM_CTRL_PRSC(config->prescaler);

    /* Set load frequency (LDFQ[15:12]) */
    reg |= PWM_CTRL_LDFQ(config->reloadConfig.loadFrequency);

    /* Conditionally set load mode (LDMOD[2]) */
    reg = (config->reloadConfig.loadMode == kFLEXPWM_LoadMode_Immediate) ?
          (reg | PWM_CTRL_LDMOD_MASK) : reg;

    /* Conditionally set half-cycle reload (HALF[11]) */
    reg = (config->reloadConfig.enableHalfCycleReload) ? (reg | PWM_CTRL_HALF_MASK) : reg;

    /* Conditionally set full-cycle reload (FULL[10]) */
    reg = (config->reloadConfig.enableFullCycleReload) ? (reg | PWM_CTRL_FULL_MASK) : reg;

    /* Write back CTRL register */
    base->SM[submodule].CTRL = reg;

    /* Configure counter initial value (INIT register) */
    base->SM[submodule].INIT = config->counterConfig.initValue;

    /* Configure counter modulo value (VAL1 register) */
    base->SM[submodule].VAL1 = config->counterConfig.modValue;

    /* Configure half-cycle reload point (VAL0 register) */
    base->SM[submodule].VAL0 = config->reloadConfig.halfCycleValue;
}

/*!
 * @brief Configure PWM output for a FlexPWM submodule.
 *
 * This function configures the PWM output parameters for a FlexPWM submodule.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param config Pointer to the PWM configuration structure.
 */
void FLEXPWM_ConfigPWM(PWM_Type *base, uint8_t submodule, const flexpwm_pwm_config_t *config)
{
    assert(NULL != config);
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);

    uint16_t reg;
    uint16_t submoduleMask = (uint16_t)((1UL << (uint32_t)submodule) & 0xFFFFU);

    /* Configure SMxOCTRL register: POLA, POLB */
    reg = base->SM[submodule].OCTRL;

    /* Clear polarity bits */
    reg &= MCUX_MASK_INVERT_16(PWM_OCTRL_POLA_MASK | PWM_OCTRL_POLB_MASK);

    /* Set polarity for PWM_A */
    reg = (config->pwma.polarity == kFLEXPWM_Polarity_ActiveLow) ? (reg | PWM_OCTRL_POLA_MASK) : reg;

    /* Set polarity for PWM_B */
    reg = (config->pwmb.polarity == kFLEXPWM_Polarity_ActiveLow) ? (reg | PWM_OCTRL_POLB_MASK) : reg;

    /* Write back OCTRL register */
    base->SM[submodule].OCTRL = reg;

    /* Configure SMxCTRL2 register: INDEP */
    reg = base->SM[submodule].CTRL2;

    /* Clear relevant bit fields */
    reg &= MCUX_MASK_INVERT_16(PWM_CTRL2_INDEP_MASK);

    /* Set INDEP mode (0=complementary, 1=independent) */
    reg = (config->complementary) ? reg : (reg | PWM_CTRL2_INDEP_MASK);

    /* Write back CTRL2 register */
    base->SM[submodule].CTRL2 = reg;

    /* Configure compare values based on operating mode */
    if (config->complementary)
    {
        /* In complementary mode, only configure the selected channel */
        if (config->ipolSource == kFLEXPWM_IPOL_PWM23)
        {
            /* PWM23 is selected as the complementary source - configure PWM_A */
            base->SM[submodule].VAL2 = config->pwma.compareValue_ON;
            base->SM[submodule].VAL3 = config->pwma.compareValue_OFF;
        }
        else /* kFLEXPWM_IPOL_PWM45 */
        {
            /* PWM45 is selected as the complementary source - configure PWM_B */
            base->SM[submodule].VAL4 = config->pwmb.compareValue_ON;
            base->SM[submodule].VAL5 = config->pwmb.compareValue_OFF;
        }

        /* Set MCTRL[IPOL] for the corresponding submodule (bit 12+submodule) */
        if (config->ipolSource == kFLEXPWM_IPOL_PWM45)
        {
            base->MCTRL |= (submoduleMask << PWM_MCTRL_IPOL_SHIFT);
        }
        else
        {
            base->MCTRL &= MCUX_MASK_INVERT_16(submoduleMask << PWM_MCTRL_IPOL_SHIFT);
        }
    }
    else
    {
        /* In independent mode, configure both channels */
        base->SM[submodule].VAL2 = config->pwma.compareValue_ON;
        base->SM[submodule].VAL3 = config->pwma.compareValue_OFF;
        base->SM[submodule].VAL4 = config->pwmb.compareValue_ON;
        base->SM[submodule].VAL5 = config->pwmb.compareValue_OFF;
    }
}

/*!
 * @brief Configure PWM_X output for a FlexPWM submodule.
 *
 * This function configures the PWM_X output parameters for a FlexPWM submodule.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param pwmx Pointer to the PWM_X configuration structure.
 */
void FLEXPWM_ConfigPWMChannelX(PWM_Type *base, uint8_t submodule, const flexpwm_pwm_channel_config_t *pwmx)
{
    assert(NULL != pwmx);
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);

    uint16_t reg;

    /* Configure SMxOCTRL register: POLX */
    reg = base->SM[submodule].OCTRL;

    /* Clear polarity bits */
    reg &= MCUX_MASK_INVERT_16(PWM_OCTRL_POLX_MASK);

    /* Set polarity for PWM_X */
    reg = (pwmx->polarity == kFLEXPWM_Polarity_ActiveLow) ? (reg | PWM_OCTRL_POLX_MASK) : reg;

    /* Write back OCTRL register */
    base->SM[submodule].OCTRL = reg;

    /* Configure compare values */
    base->SM[submodule].VAL0 = pwmx->compareValue_ON;
    base->SM[submodule].VAL1 = pwmx->compareValue_OFF;
}

/*!
 * @brief Get default configuration for force output.
 *
 * @param config Pointer to the force output configuration structure.
 */
void FLEXPWM_GetDefaultForceOutConfig(flexpwm_force_out_config_t *config)
{
    assert(NULL != config);

    /* Set default FORCE_OUT trigger source to local software force */
    config->forceSource = kFLEXPWM_ForceOutputSource_LocalForce;

    /* Configure PWM_A (PWM23) to use generated PWM signal by default */
    config->pwma.source = kFLEXPWM_ForcePwmSource_Generated;
    config->pwma.softwareValue = false;  /* Logic 0 */

    /* Configure PWM_B (PWM45) to use generated PWM signal by default */
    config->pwmb.source = kFLEXPWM_ForcePwmSource_Generated;
    config->pwmb.softwareValue = false;  /* Logic 0 */

    /* Set default initial values for all PWM outputs */
    config->pwma_initialValue = false;   /* PWM_A starts at logic 0 */
    config->pwmb_initialValue = false;   /* PWM_B starts at logic 0 */
    config->pwmx_initialValue = false;   /* PWM_X starts at logic 0 */
}

/*!
 * @brief Configure FORCE_OUT for a FlexPWM submodule.
 *
 * This function configures the FORCE_OUT event parameters for a FlexPWM submodule.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param config Pointer to the force output configuration structure.
 */
void FLEXPWM_ConfigForceOut(PWM_Type *base, uint8_t submodule, const flexpwm_force_out_config_t *config)
{
    assert(NULL != config);
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);

    uint16_t reg;

    /* Configure CTRL2 register: FORCE_SEL, PWM23_INIT, PWM45_INIT, PWMX_INIT */
    reg = base->SM[submodule].CTRL2;

    /* Clear all relevant bit fields */
    reg &= MCUX_MASK_INVERT_16(PWM_CTRL2_FORCE_SEL_MASK | PWM_CTRL2_PWM23_INIT_MASK |
                               PWM_CTRL2_PWM45_INIT_MASK | PWM_CTRL2_PWMX_INIT_MASK);

    /* Set FORCE_SEL (force trigger source) */
    reg |= PWM_CTRL2_FORCE_SEL(config->forceSource);

    /* Set initial value for PWM_A (PWM23) */
    reg = (config->pwma_initialValue) ? (reg | PWM_CTRL2_PWM23_INIT_MASK) : reg;

    /* Set initial value for PWM_B (PWM45) */
    reg = (config->pwmb_initialValue) ? (reg | PWM_CTRL2_PWM45_INIT_MASK) : reg;

    /* Set initial value for PWM_X */
    reg = (config->pwmx_initialValue) ? (reg | PWM_CTRL2_PWMX_INIT_MASK) : reg;

    /* Write back CTRL2 register */
    base->SM[submodule].CTRL2 = reg;

    /* Configure DTSRCSEL register for PWM source selection (read-modify-write) */
    reg = base->DTSRCSEL;

    /* Clear the relevant SMxSEL23 and SMxSEL45 fields for this submodule */
    switch (submodule)
    {
        case 0U:
            reg &= MCUX_MASK_INVERT_16((uint16_t)PWM_DTSRCSEL_SM0SEL23_MASK | (uint16_t)PWM_DTSRCSEL_SM0SEL45_MASK);
            reg |= PWM_DTSRCSEL_SM0SEL23(config->pwma.source) | PWM_DTSRCSEL_SM0SEL45(config->pwmb.source);
            break;
        case 1U:
            reg &= MCUX_MASK_INVERT_16((uint16_t)PWM_DTSRCSEL_SM1SEL23_MASK | (uint16_t)PWM_DTSRCSEL_SM1SEL45_MASK);
            reg |= PWM_DTSRCSEL_SM1SEL23(config->pwma.source) | PWM_DTSRCSEL_SM1SEL45(config->pwmb.source);
            break;
        case 2U:
            reg &= MCUX_MASK_INVERT_16((uint16_t)PWM_DTSRCSEL_SM2SEL23_MASK | (uint16_t)PWM_DTSRCSEL_SM2SEL45_MASK);
            reg |= PWM_DTSRCSEL_SM2SEL23(config->pwma.source) | PWM_DTSRCSEL_SM2SEL45(config->pwmb.source);
            break;
#if defined(FSL_FEATURE_PWM_SUBMODULE_COUNT) && (FSL_FEATURE_PWM_SUBMODULE_COUNT == 4)
        case 3U:
            reg &= MCUX_MASK_INVERT_16((uint16_t)PWM_DTSRCSEL_SM3SEL23_MASK | (uint16_t)PWM_DTSRCSEL_SM3SEL45_MASK);
            reg |= PWM_DTSRCSEL_SM3SEL23(config->pwma.source) | PWM_DTSRCSEL_SM3SEL45(config->pwmb.source);
            break;
#endif
        default:
            assert(false);
            break;
    }

    /* Write back DTSRCSEL register */
    base->DTSRCSEL = reg;

    /* Configure SWCOUT register for software-controlled output values (read-modify-write) */
    reg = base->SWCOUT;

    /* Clear and set the relevant SMxOUT23 and SMxOUT45 fields for this submodule */
    switch (submodule)
    {
        case 0U:
            reg &= MCUX_MASK_INVERT_16((uint16_t)PWM_SWCOUT_SM0OUT23_MASK | (uint16_t)PWM_SWCOUT_SM0OUT45_MASK);
            reg |= PWM_SWCOUT_SM0OUT23(config->pwma.softwareValue ? 1U : 0U) |
                   PWM_SWCOUT_SM0OUT45(config->pwmb.softwareValue ? 1U : 0U);
            break;
        case 1U:
            reg &= MCUX_MASK_INVERT_16((uint16_t)PWM_SWCOUT_SM1OUT23_MASK | (uint16_t)PWM_SWCOUT_SM1OUT45_MASK);
            reg |= PWM_SWCOUT_SM1OUT23(config->pwma.softwareValue ? 1U : 0U) |
                   PWM_SWCOUT_SM1OUT45(config->pwmb.softwareValue ? 1U : 0U);
            break;
        case 2U:
            reg &= MCUX_MASK_INVERT_16((uint16_t)PWM_SWCOUT_SM2OUT23_MASK | (uint16_t)PWM_SWCOUT_SM2OUT45_MASK);
            reg |= PWM_SWCOUT_SM2OUT23(config->pwma.softwareValue ? 1U : 0U) |
                   PWM_SWCOUT_SM2OUT45(config->pwmb.softwareValue ? 1U : 0U);
            break;
#if defined(FSL_FEATURE_PWM_SUBMODULE_COUNT) && (FSL_FEATURE_PWM_SUBMODULE_COUNT == 4)
        case 3U:
            reg &= MCUX_MASK_INVERT_16((uint16_t)PWM_SWCOUT_SM3OUT23_MASK | (uint16_t)PWM_SWCOUT_SM3OUT45_MASK);
            reg |= PWM_SWCOUT_SM3OUT23(config->pwma.softwareValue ? 1U : 0U) |
                   PWM_SWCOUT_SM3OUT45(config->pwmb.softwareValue ? 1U : 0U);
            break;
#endif
        default:
            assert(false);
            break;
    }

    /* Write back SWCOUT register */
    base->SWCOUT = reg;
}

/*!
 * @brief Get default configuration for fault protection.
 *
 * @param config Pointer to the fault protection configuration structure.
 */
void FLEXPWM_GetDefaultFaultConfig(flexpwm_fault_config_t *config)
{
    assert(NULL != config);

    config->faultInputActiveLevel = true;        /* Active high (common for external circuits) */

    config->faultClearingMode = kFLEXPWM_FaultClearingMode_Automatic;  /* Automatic fault clearing */

    config->enableSafetyMode = true;             /* Safe mode (most conservative) */
    config->enableFullCycleRecovery = true;      /* Re-enable at full PWM cycle start */
    config->enableHalfCycleRecovery = false;     /* No half-cycle re-enable by default */
    config->enableCombinatorialPath = true;      /* Allow combinational path for fastest response */
}

/*!
 * @brief Get default configuration for fault submodule protection.
 *
 * @param config Pointer to the fault submodule configuration structure.
 */
void FLEXPWM_GetDefaultFaultSubmoduleConfig(flexpwm_fault_submodule_config_t *config)
{
    assert(NULL != config);

    /* PWM_A: All faults affect this output, High-Z output behavior */
    config->pwma.disableMask_ch0 = 0x0FU; /* FAULT0-3 can disable PWM_A */
    config->pwma.outputBehavior = kFLEXPWM_FaultOutput_HighZ;

    /* PWM_B: All faults affect this output, High-Z output behavior */
    config->pwmb.disableMask_ch0 = 0x0FU; /* FAULT0-3 can disable PWM_B */
    config->pwmb.outputBehavior = kFLEXPWM_FaultOutput_HighZ;

    /* PWM_X: All faults affect this output, High-Z output behavior */
    config->pwmx.disableMask_ch0 = 0x0FU; /* FAULT0-3 can disable PWM_X */
    config->pwmx.outputBehavior = kFLEXPWM_FaultOutput_HighZ;

#if defined(FSL_FEATURE_PWM_FAULT_CH_COUNT) && (FSL_FEATURE_PWM_FAULT_CH_COUNT > 1)
    /* Dual-channel platform: Configure fault channel 1 (FAULT4-7) */
    config->pwma.disableMask_ch1 = 0x0FU; /* FAULT4-7 can disable PWM_A */
    config->pwmb.disableMask_ch1 = 0x0FU; /* FAULT4-7 can disable PWM_B */
    config->pwmx.disableMask_ch1 = 0x0FU; /* FAULT4-7 can disable PWM_X */
#endif
}

/*!
 * @brief Get default configuration for fault filter.
 *
 * @param config Pointer to the fault filter configuration structure.
 */
void FLEXPWM_GetDefaultFaultFilterConfig(flexpwm_fault_filter_config_t *config)
{
    assert(NULL != config);

    config->filterPeriod = 0x08U;    /* 8 IPBus clock cycles sampling period */
    config->filterCount = 0x04U;     /* 7 samples (4+3) required for debounce */
    config->enableGlitchStretch = true;  /* Enable glitch stretching */
}

/*!
 * @brief Configure fault protection for a FlexPWM fault channel.
 *
 * @param base FlexPWM peripheral base address.
 * @param faultChannel Fault channel number (0 or 1 for dual-channel platforms).
 * @param config Pointer to the fault protection configuration structure.
 * @param faultMask Fault input selection mask for the channel. Each bit corresponds to one fault input:
 *                  - bit[0] = FAULT0 (or FAULT4 for channel 1)
 *                  - bit[1] = FAULT1 (or FAULT5 for channel 1)
 *                  - bit[2] = FAULT2 (or FAULT6 for channel 1)
 *                  - bit[3] = FAULT3 (or FAULT7 for channel 1)
 *                  Example: 0x05 = configure FAULT0 and FAULT2 with the same settings.
 *                  Can use flexpwm_fault_mask_t enum values (kFLEXPWM_FaultMask_0/1/2/3) and
 *                  OR them together for multiple faults:
 *                  (kFLEXPWM_FaultMask_0 | kFLEXPWM_FaultMask_2) = 0x05.
 */
void FLEXPWM_ConfigFaultProtection(PWM_Type *base, uint8_t faultChannel, const flexpwm_fault_config_t *config,
                                   uint16_t faultMask)
{
    assert(NULL != config);
    assert(0U != faultMask);  /* At least one fault input must be selected */
    assert(faultChannel < (uint8_t)FSL_FEATURE_PWM_FAULT_CH_COUNT);

    uint16_t reg;
    uint16_t flvl_mask_bits;   /* Mask bits for FLVL field */
    uint16_t fauto_mask_bits;  /* Mask bits for FAUTO field */
    uint16_t fsafe_mask_bits;  /* Mask bits for FSAFE field */
    uint16_t ffull_mask_bits;  /* Mask bits for FFULL field */
    uint16_t fhalf_mask_bits;  /* Mask bits for FHALF field */
    uint16_t nocomb_mask_bits; /* Mask bits for NOCOMB field */

    /* Convert faultMask to actual bit positions for each field */
    flvl_mask_bits = faultMask << PWM_FCTRL_FLVL_SHIFT;
    fauto_mask_bits = faultMask << PWM_FCTRL_FAUTO_SHIFT;
    fsafe_mask_bits = faultMask << PWM_FCTRL_FSAFE_SHIFT;
    ffull_mask_bits = faultMask << PWM_FSTS_FFULL_SHIFT;
    fhalf_mask_bits = faultMask << PWM_FSTS_FHALF_SHIFT;
    nocomb_mask_bits = faultMask << PWM_FCTRL2_NOCOMB_SHIFT;

    /* Configure FCTRL register: FLVL, FAUTO, FSAFE - selective bit update */
    reg = *FLEXPWM_GET_FCTRL_REG(base, faultChannel);

    /* Clear only the bits selected by faultMask in each field */
    reg &= MCUX_MASK_INVERT_16(flvl_mask_bits | fauto_mask_bits | fsafe_mask_bits);

    /* Set bits according to config values */
    reg |= (config->faultInputActiveLevel) ? (flvl_mask_bits & PWM_FCTRL_FLVL_MASK) : 0U;

    reg |= (config->faultClearingMode == kFLEXPWM_FaultClearingMode_Automatic) ?
           (fauto_mask_bits & PWM_FCTRL_FAUTO_MASK) : 0U;

    reg |= (config->enableSafetyMode) ? (fsafe_mask_bits & PWM_FCTRL_FSAFE_MASK) : 0U;

    /* Write back FCTRL register */
    *FLEXPWM_GET_FCTRL_REG(base, faultChannel) = reg;

    /* Configure FSTS register: FFULL, FHALF (fault recovery timing) - selective bit update */
    reg = *FLEXPWM_GET_FSTS_REG(base, faultChannel);

    /* Clear only the bits selected by faultMask in each field */
    reg &= MCUX_MASK_INVERT_16(ffull_mask_bits | fhalf_mask_bits);

    /* Set bits according to config values */
    reg |= (config->enableFullCycleRecovery) ? (ffull_mask_bits & PWM_FSTS_FFULL_MASK) : 0U;
    reg |= (config->enableHalfCycleRecovery) ? (fhalf_mask_bits & PWM_FSTS_FHALF_MASK) : 0U;

    /* Write back FSTS register */
    *FLEXPWM_GET_FSTS_REG(base, faultChannel) = reg;

    /* Configure FCTRL2 register: NOCOMB (combinational path control) - selective bit update */
    reg = *FLEXPWM_GET_FCTRL2_REG(base, faultChannel);

    /* Clear only the bits selected by faultMask in the NOCOMB field */
    reg &= MCUX_MASK_INVERT_16(nocomb_mask_bits);

    /* Set bits according to config values */
    reg |= (config->enableCombinatorialPath) ? (nocomb_mask_bits & PWM_FCTRL2_NOCOMB_MASK) : 0U;

    /* Write back FCTRL2 register */
    *FLEXPWM_GET_FCTRL2_REG(base, faultChannel) = reg;
}

/*!
 * @brief Configure fault submodule protection for a FlexPWM submodule.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param config Pointer to the fault submodule configuration structure.
 */
void FLEXPWM_ConfigFaultSubmodule(PWM_Type *base, uint8_t submodule, const flexpwm_fault_submodule_config_t *config)
{
    assert(NULL != config);
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);

    uint16_t reg;

    /* Configure DISMAP register: Fault disable mapping for each output */
    /* DISMAP[0] maps FAULT0-3, DISMAP[1] maps FAULT4-7 (if supported) */

    /* Configure PWM_A disable mapping (DISMAP[0]) */
    reg = base->SM[submodule].DISMAP[0];

    /* Clear DIS0A bits (bits 0-3) */
    reg &= MCUX_MASK_INVERT_16(PWM_DISMAP_DIS0A_MASK);

    /* Set DIS0A based on disableMask_ch0 */
    reg |= PWM_DISMAP_DIS0A(config->pwma.disableMask_ch0);

    /* Clear DIS0B bits (bits 4-7) */
    reg &= MCUX_MASK_INVERT_16(PWM_DISMAP_DIS0B_MASK);

    /* Set DIS0B based on disableMask_ch0 */
    reg |= PWM_DISMAP_DIS0B(config->pwmb.disableMask_ch0);

    /* Clear DIS0X bits (bits 8-11) */
    reg &= MCUX_MASK_INVERT_16(PWM_DISMAP_DIS0X_MASK);

    /* Set DIS0X based on disableMask_ch0 */
    reg |= PWM_DISMAP_DIS0X(config->pwmx.disableMask_ch0);

    /* Write back DISMAP[0] register */
    base->SM[submodule].DISMAP[0] = reg;

#if defined(FSL_FEATURE_PWM_FAULT_CH_COUNT) && (FSL_FEATURE_PWM_FAULT_CH_COUNT > 1)
    /* Dual-channel platform: Configure DISMAP[1] for FAULT4-7 */
    reg = base->SM[submodule].DISMAP[1];

    /* Clear DIS1A bits (bits 0-3) */
    reg &= MCUX_MASK_INVERT_16(PWM_DISMAP_DIS1A_MASK);

    /* Set DIS1A based on disableMask_ch1 */
    reg |= PWM_DISMAP_DIS1A(config->pwma.disableMask_ch1);

    /* Clear DIS1B bits (bits 4-7) */
    reg &= MCUX_MASK_INVERT_16(PWM_DISMAP_DIS1B_MASK);

    /* Set DIS1B based on disableMask_ch1 */
    reg |= PWM_DISMAP_DIS1B(config->pwmb.disableMask_ch1);

    /* Clear DIS1X bits (bits 8-11) */
    reg &= MCUX_MASK_INVERT_16(PWM_DISMAP_DIS1X_MASK);

    /* Set DIS1X based on disableMask_ch1 */
    reg |= PWM_DISMAP_DIS1X(config->pwmx.disableMask_ch1);

    /* Write back DISMAP[1] register */
    base->SM[submodule].DISMAP[1] = reg;
#endif

    /* Configure OCTRL register: Fault output behavior (PWMAFS/PWMBFS/PWMXFS) */
    reg = base->SM[submodule].OCTRL;

    /* Clear fault state bits */
    reg &= MCUX_MASK_INVERT_16((uint16_t)PWM_OCTRL_PWMAFS_MASK | (uint16_t)PWM_OCTRL_PWMBFS_MASK |
                               (uint16_t)PWM_OCTRL_PWMXFS_MASK);

    /* Set PWMAFS (PWM_A fault output behavior) */
    reg |= PWM_OCTRL_PWMAFS(config->pwma.outputBehavior);

    /* Set PWMBFS (PWM_B fault output behavior) */
    reg |= PWM_OCTRL_PWMBFS(config->pwmb.outputBehavior);

    /* Set PWMXFS (PWM_X fault output behavior) */
    reg |= PWM_OCTRL_PWMXFS(config->pwmx.outputBehavior);

    /* Write back OCTRL register */
    base->SM[submodule].OCTRL = reg;
}

/*!
 * @brief Configure fault filter for a FlexPWM fault channel.
 *
 * @param base FlexPWM peripheral base address.
 * @param faultChannel Fault channel number (0 or 1).
 * @param config Pointer to the fault filter configuration structure.
 */
void FLEXPWM_ConfigFaultFilter(PWM_Type *base, uint8_t faultChannel, const flexpwm_fault_filter_config_t *config)
{
    assert(NULL != config);
    assert(faultChannel < (uint8_t)FSL_FEATURE_PWM_FAULT_CH_COUNT);

    uint16_t reg;

    /* Hardware requirement: must clear FILT_PER first before writing a new value */
    *FLEXPWM_GET_FFILT_REG(base, faultChannel) &= MCUX_MASK_INVERT_16(PWM_FFILT_FILT_PER_MASK);

    /* Build and write filter configuration value */
    reg = *FLEXPWM_GET_FFILT_REG(base, faultChannel);

    /* Clear the relevant bit fields */
    reg &= MCUX_MASK_INVERT_16(PWM_FFILT_FILT_PER_MASK | PWM_FFILT_FILT_CNT_MASK | PWM_FFILT_GSTR_MASK);

    /* Set FILT_PER (filter sampling period) */
    reg |= PWM_FFILT_FILT_PER(config->filterPeriod);

    /* Set FILT_CNT (filter count for stable samples) */
    reg |= PWM_FFILT_FILT_CNT(config->filterCount);

    /* Set GSTR (glitch stretching enable) */
    reg = (config->enableGlitchStretch) ? (reg | PWM_FFILT_GSTR_MASK) : reg;

    /* Write back FFILT register */
    *FLEXPWM_GET_FFILT_REG(base, faultChannel) = reg;
}

/*!
 * @brief Get default configuration for output trigger.
 *
 * @param config Pointer to the output trigger configuration structure.
 */
void FLEXPWM_GetDefaultOutputTriggerConfig(flexpwm_output_trigger_config_t *config)
{
    assert(NULL != config);

    /* Disable all output triggers by default */
    config->outTriggerEnable = 0U;

    /* Set default trigger frequency to every PWM cycle */
    config->triggerFrequency = kFLEXPWM_TriggerFrequency_EveryCycle;

    /* Set default MUX trigger sources to generated trigger signal */
    config->muxTrig0Source = kFLEXPWM_TriggerMuxSource_GeneratedTrigger;
    config->muxTrig1Source = kFLEXPWM_TriggerMuxSource_GeneratedTrigger;

#if (defined(FSL_FEATURE_PWM_MCTRL2_HAS_STRETCH_CNT_PRSC_BITFIELD) &&   \
             FSL_FEATURE_PWM_MCTRL2_HAS_STRETCH_CNT_PRSC_BITFIELD)
    /* Set default stretch prescaler to no prescaling */
    config->stretchPrescaler = kFLEXPWM_StretchPrescaler_None;
#endif
}

/*!
 * @brief Configure output trigger for a FlexPWM submodule.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param config Pointer to the output trigger configuration structure.
 */
void FLEXPWM_ConfigOutputTrigger(PWM_Type *base, uint8_t submodule, const flexpwm_output_trigger_config_t *config)
{
    assert(NULL != config);
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);

    uint16_t reg;

    /* Configure SMxTCTRL register: OUT_TRIG_EN, TRGFRQ, PWBOT1, PWAOT0 */
    reg = base->SM[submodule].TCTRL;

    /* Clear the relevant bit fields */
    reg &= MCUX_MASK_INVERT_16(PWM_TCTRL_OUT_TRIG_EN_MASK | PWM_TCTRL_TRGFRQ_MASK |
                               PWM_TCTRL_PWBOT1_MASK | PWM_TCTRL_PWAOT0_MASK);

    /* Set OUT_TRIG_EN (6-bit mask for VAL0-5 trigger sources) */
    reg |= PWM_TCTRL_OUT_TRIG_EN(config->outTriggerEnable & PWM_TCTRL_OUT_TRIG_EN_MASK);

    /* Set TRGFRQ (trigger frequency control) */
    reg = (kFLEXPWM_TriggerFrequency_OnReload == config->triggerFrequency) ? (reg | PWM_TCTRL_TRGFRQ_MASK) : reg;

    /* Set PWBOT1 (PWM_MUX_TRIG1 source selection) */
    reg = (kFLEXPWM_TriggerMuxSource_PWMOutput == config->muxTrig1Source) ? (reg | PWM_TCTRL_PWBOT1_MASK) : reg;

    /* Set PWAOT0 (PWM_MUX_TRIG0 source selection) */
    reg = (kFLEXPWM_TriggerMuxSource_PWMOutput == config->muxTrig0Source) ? (reg | PWM_TCTRL_PWAOT0_MASK) : reg;

    /* Write back SMxTCTRL register */
    base->SM[submodule].TCTRL = reg;

#if (defined(FSL_FEATURE_PWM_MCTRL2_HAS_STRETCH_CNT_PRSC_BITFIELD) &&   \
             FSL_FEATURE_PWM_MCTRL2_HAS_STRETCH_CNT_PRSC_BITFIELD)
    /* Configure MCTRL2[STRETCH_CNT_PRSC] for trigger signal stretch prescaler */
    reg = base->MCTRL2;

    /* Clear STRETCH_CNT_PRSC bits */
    reg &= MCUX_MASK_INVERT_16(PWM_MCTRL2_STRETCH_CNT_PRSC_MASK);

    /* Set STRETCH_CNT_PRSC to specified value */
    reg |= PWM_MCTRL2_STRETCH_CNT_PRSC(config->stretchPrescaler);

    base->MCTRL2 = reg;
#endif
}

/*!
 * @brief Get default configuration for input capture.
 *
 * @param config Pointer to the input capture configuration structure.
 */
void FLEXPWM_GetDefaultInputCaptureConfig(flexpwm_input_capture_config_t *config)
{
    assert(NULL != config);

    /* Capture_A default configuration */
    config->captureA.edge0 = kFLEXPWM_CaptureEdge_Disabled;
    config->captureA.edge1 = kFLEXPWM_CaptureEdge_Disabled;
    config->captureA.oneshot = false;
    config->captureA.inputSelect = kFLEXPWM_CaptureInput_RawSignal;
    config->captureA.enableEdgeCounter = false;
    config->captureA.edgeCompareValue = 0U;
    config->captureA.fifoWatermark = kFLEXPWM_CaptureFifoWatermark_1;

    /* Capture_B default configuration */
    config->captureB.edge0 = kFLEXPWM_CaptureEdge_Disabled;
    config->captureB.edge1 = kFLEXPWM_CaptureEdge_Disabled;
    config->captureB.oneshot = false;
    config->captureB.inputSelect = kFLEXPWM_CaptureInput_RawSignal;
    config->captureB.enableEdgeCounter = false;
    config->captureB.edgeCompareValue = 0U;
    config->captureB.fifoWatermark = kFLEXPWM_CaptureFifoWatermark_1;

    /* Capture_X default configuration */
    config->captureX.edge0 = kFLEXPWM_CaptureEdge_Disabled;
    config->captureX.edge1 = kFLEXPWM_CaptureEdge_Disabled;
    config->captureX.oneshot = false;
    config->captureX.inputSelect = kFLEXPWM_CaptureInput_RawSignal;
    config->captureX.enableEdgeCounter = false;
    config->captureX.edgeCompareValue = 0U;
    config->captureX.fifoWatermark = kFLEXPWM_CaptureFifoWatermark_1;
}

#if (defined(FSL_FEATURE_PWM_HAS_INPUT_FILTER_CAPTURE) && FSL_FEATURE_PWM_HAS_INPUT_FILTER_CAPTURE)
/*!
 * @brief Get default configuration for capture filter.
 *
 * @param config Pointer to the capture filter configuration structure.
 */
void FLEXPWM_GetDefaultCaptureFilterConfig(flexpwm_capture_filter_config_t *config)
{
    assert(NULL != config);

    /* Capture_A filter default configuration (bypassed) */
    config->captureA.filterPeriod = 0U;
    config->captureA.filterCount = 0U;  /* 3 consecutive samples */

    /* Capture_B filter default configuration (bypassed) */
    config->captureB.filterPeriod = 0U;
    config->captureB.filterCount = 0U;  /* 3 consecutive samples */

    /* Capture_X filter default configuration (bypassed) */
    config->captureX.filterPeriod = 0U;
    config->captureX.filterCount = 0U;  /* 3 consecutive samples */
}
#endif

/*!
 * @brief Configure input capture for a FlexPWM submodule.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param config Pointer to the input capture configuration structure.
 */
void FLEXPWM_ConfigInputCapture(PWM_Type *base, uint8_t submodule, const flexpwm_input_capture_config_t *config)
{
    assert(NULL != config);
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);

    uint16_t reg;

#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELA) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELA)
    /* Configure Capture_A channel (SMxCAPTCTRLA register) */
    reg = base->SM[submodule].CAPTCTRLA;

    /* Clear the relevant bit fields (excluding ARMA bit 0 and read-only CA0CNT/CA1CNT bits 10-15) */
    reg &= MCUX_MASK_INVERT_16(PWM_CAPTCTRLA_ONESHOTA_MASK | PWM_CAPTCTRLA_EDGA0_MASK | PWM_CAPTCTRLA_EDGA1_MASK |
                               PWM_CAPTCTRLA_INP_SELA_MASK | PWM_CAPTCTRLA_EDGCNTA_EN_MASK |
                               PWM_CAPTCTRLA_CFAWM_MASK);

    /* Set EDGA0 (edge detector 0) */
    reg |= PWM_CAPTCTRLA_EDGA0(config->captureA.edge0);

    /* Set EDGA1 (edge detector 1) */
    reg |= PWM_CAPTCTRLA_EDGA1(config->captureA.edge1);

    /* Set ONESHOTA (one-shot mode) */
    reg = (config->captureA.oneshot) ? (reg | PWM_CAPTCTRLA_ONESHOTA_MASK) : reg;

    /* Set INP_SELA (input source selection) */
    reg = (kFLEXPWM_CaptureInput_EdgeCounter == config->captureA.inputSelect) ?
          (reg | PWM_CAPTCTRLA_INP_SELA_MASK) : reg;

    /* Set EDGCNTA_EN (edge counter enable) */
    reg = (config->captureA.enableEdgeCounter) ? (reg | PWM_CAPTCTRLA_EDGCNTA_EN_MASK) : reg;

    /* Set CFAWM (FIFO watermark) */
    reg |= PWM_CAPTCTRLA_CFAWM(config->captureA.fifoWatermark);

    /* Write back SMxCAPTCTRLA register */
    base->SM[submodule].CAPTCTRLA = reg;

    /* Configure SMxCAPTCOMPA register (edge counter compare value) */
    reg = base->SM[submodule].CAPTCOMPA;

    /* Clear EDGCMPA field (bits 0-7) */
    reg &= MCUX_MASK_INVERT_16(PWM_CAPTCOMPA_EDGCMPA_MASK);

    /* Set EDGCMPA */
    reg |= PWM_CAPTCOMPA_EDGCMPA(config->captureA.edgeCompareValue);

    /* Write back SMxCAPTCOMPA register */
    base->SM[submodule].CAPTCOMPA = reg;
#endif

#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELB) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELB)
    /* Configure Capture_B channel (SMxCAPTCTRLB register) */
    reg = base->SM[submodule].CAPTCTRLB;

    /* Clear the relevant bit fields (excluding ARMB bit 0 and read-only CB0CNT/CB1CNT bits 10-15) */
    reg &= MCUX_MASK_INVERT_16(PWM_CAPTCTRLB_ONESHOTB_MASK | PWM_CAPTCTRLB_EDGB0_MASK | PWM_CAPTCTRLB_EDGB1_MASK |
                               PWM_CAPTCTRLB_INP_SELB_MASK | PWM_CAPTCTRLB_EDGCNTB_EN_MASK |
                               PWM_CAPTCTRLB_CFBWM_MASK);

    /* Set EDGB0 (edge detector 0) */
    reg |= PWM_CAPTCTRLB_EDGB0(config->captureB.edge0);

    /* Set EDGB1 (edge detector 1) */
    reg |= PWM_CAPTCTRLB_EDGB1(config->captureB.edge1);

    /* Set ONESHOTB (one-shot mode) */
    reg = (config->captureB.oneshot) ? (reg | PWM_CAPTCTRLB_ONESHOTB_MASK) : reg;

    /* Set INP_SELB (input source selection) */
    reg = (kFLEXPWM_CaptureInput_EdgeCounter == config->captureB.inputSelect) ?
          (reg | PWM_CAPTCTRLB_INP_SELB_MASK) : reg;

    /* Set EDGCNTB_EN (edge counter enable) */
    reg = (config->captureB.enableEdgeCounter) ? (reg | PWM_CAPTCTRLB_EDGCNTB_EN_MASK) : reg;

    /* Set CFBWM (FIFO watermark) */
    reg |= PWM_CAPTCTRLB_CFBWM(config->captureB.fifoWatermark);

    /* Write back SMxCAPTCTRLB register */
    base->SM[submodule].CAPTCTRLB = reg;

    /* Configure SMxCAPTCOMPB register (edge counter compare value) */
    reg = base->SM[submodule].CAPTCOMPB;

    /* Clear EDGCMPB field (bits 0-7) */
    reg &= MCUX_MASK_INVERT_16(PWM_CAPTCOMPB_EDGCMPB_MASK);

    /* Set EDGCMPB */
    reg |= PWM_CAPTCOMPB_EDGCMPB(config->captureB.edgeCompareValue);

    /* Write back SMxCAPTCOMPB register */
    base->SM[submodule].CAPTCOMPB = reg;
#endif

#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELX) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELX)
    /* Configure Capture_X channel (SMxCAPTCTRLX register) */
    reg = base->SM[submodule].CAPTCTRLX;

    /* Clear the relevant bit fields (excluding ARMX bit 0 and read-only CX0CNT/CX1CNT bits 10-15) */
    reg &= MCUX_MASK_INVERT_16(PWM_CAPTCTRLX_ONESHOTX_MASK | PWM_CAPTCTRLX_EDGX0_MASK | PWM_CAPTCTRLX_EDGX1_MASK |
                               PWM_CAPTCTRLX_INP_SELX_MASK | PWM_CAPTCTRLX_EDGCNTX_EN_MASK |
                               PWM_CAPTCTRLX_CFXWM_MASK);

    /* Set EDGX0 (edge detector 0) */
    reg |= PWM_CAPTCTRLX_EDGX0(config->captureX.edge0);

    /* Set EDGX1 (edge detector 1) */
    reg |= PWM_CAPTCTRLX_EDGX1(config->captureX.edge1);

    /* Set ONESHOTX (one-shot mode) */
    reg = (config->captureX.oneshot) ? (reg | PWM_CAPTCTRLX_ONESHOTX_MASK) : reg;

    /* Set INP_SELX (input source selection) */
    reg = (kFLEXPWM_CaptureInput_EdgeCounter == config->captureX.inputSelect) ?
          (reg | PWM_CAPTCTRLX_INP_SELX_MASK) : reg;

    /* Set EDGCNTX_EN (edge counter enable) */
    reg = (config->captureX.enableEdgeCounter) ? (reg | PWM_CAPTCTRLX_EDGCNTX_EN_MASK) : reg;

    /* Set CFXWM (FIFO watermark) */
    reg |= PWM_CAPTCTRLX_CFXWM(config->captureX.fifoWatermark);

    /* Write back SMxCAPTCTRLX register */
    base->SM[submodule].CAPTCTRLX = reg;

    /* Configure SMxCAPTCOMPX register (edge counter compare value) */
    reg = base->SM[submodule].CAPTCOMPX;

    /* Clear EDGCMPX field (bits 0-7) */
    reg &= MCUX_MASK_INVERT_16(PWM_CAPTCOMPX_EDGCMPX_MASK);

    /* Set EDGCMPX */
    reg |= PWM_CAPTCOMPX_EDGCMPX(config->captureX.edgeCompareValue);

    /* Write back SMxCAPTCOMPX register */
    base->SM[submodule].CAPTCOMPX = reg;
#endif
}

#if (defined(FSL_FEATURE_PWM_HAS_INPUT_FILTER_CAPTURE) && FSL_FEATURE_PWM_HAS_INPUT_FILTER_CAPTURE)
/*!
 * @brief Configure input capture filter for a FlexPWM submodule.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param config Pointer to the capture filter configuration structure.
 */
void FLEXPWM_ConfigInputCaptureFilter(PWM_Type *base, uint8_t submodule, const flexpwm_capture_filter_config_t *config)
{
    assert(NULL != config);
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);

    uint16_t reg;

#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELA) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELA)
    /* Configure Capture_A filter (SMxCAPTFILTA register) */
    /* Hardware requirement: must clear CAPTA_FILT_PER first before writing a new value */
    base->SM[submodule].CAPTFILTA &= MCUX_MASK_INVERT_16(PWM_CAPTFILTA_CAPTA_FILT_PER_MASK);

    /* Build and write filter configuration value */
    reg = base->SM[submodule].CAPTFILTA;
    reg &= MCUX_MASK_INVERT_16(PWM_CAPTFILTA_CAPTA_FILT_PER_MASK | PWM_CAPTFILTA_CAPTA_FILT_CNT_MASK);
    reg |= PWM_CAPTFILTA_CAPTA_FILT_PER(config->captureA.filterPeriod);
    reg |= PWM_CAPTFILTA_CAPTA_FILT_CNT(config->captureA.filterCount);
    base->SM[submodule].CAPTFILTA = reg;
#endif

#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELB) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELB)
    /* Configure Capture_B filter (SMxCAPTFILTB register) */
    /* Hardware requirement: must clear CAPTB_FILT_PER first before writing a new value */
    base->SM[submodule].CAPTFILTB &= MCUX_MASK_INVERT_16(PWM_CAPTFILTB_CAPTB_FILT_PER_MASK);

    /* Build and write filter configuration value */
    reg = base->SM[submodule].CAPTFILTB;
    reg &= MCUX_MASK_INVERT_16(PWM_CAPTFILTB_CAPTB_FILT_PER_MASK | PWM_CAPTFILTB_CAPTB_FILT_CNT_MASK);
    reg |= PWM_CAPTFILTB_CAPTB_FILT_PER(config->captureB.filterPeriod);
    reg |= PWM_CAPTFILTB_CAPTB_FILT_CNT(config->captureB.filterCount);
    base->SM[submodule].CAPTFILTB = reg;
#endif

#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELX) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELX)
    /* Configure Capture_X filter (SMxCAPTFILTX register) */
    /* Hardware requirement: must clear CAPTX_FILT_PER first before writing a new value */
    base->SM[submodule].CAPTFILTX &= MCUX_MASK_INVERT_16(PWM_CAPTFILTX_CAPTX_FILT_PER_MASK);

    /* Build and write filter configuration value */
    reg = base->SM[submodule].CAPTFILTX;
    reg &= MCUX_MASK_INVERT_16(PWM_CAPTFILTX_CAPTX_FILT_PER_MASK | PWM_CAPTFILTX_CAPTX_FILT_CNT_MASK);
    reg |= PWM_CAPTFILTX_CAPTX_FILT_PER(config->captureX.filterPeriod);
    reg |= PWM_CAPTFILTX_CAPTX_FILT_CNT(config->captureX.filterCount);
    base->SM[submodule].CAPTFILTX = reg;
#endif
}
#endif

/*!
 * @brief Read captured value from a FlexPWM capture channel.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param captureIndex Capture channel and edge detector index.
 * @return The captured counter value (16-bit).
 */
uint16_t FLEXPWM_GetInputCaptureValue(PWM_Type *base, uint8_t submodule, flexpwm_capture_index_t captureIndex)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);

    uint16_t value;

    /* Read the corresponding CVAL register based on capture index */
    switch (captureIndex)
    {
#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELX) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELX)
        case kFLEXPWM_Capture_X_Edge0:
            value = base->SM[submodule].CVAL0;
            break;
        case kFLEXPWM_Capture_X_Edge1:
            value = base->SM[submodule].CVAL1;
            break;
#endif
#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELA) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELA)
        case kFLEXPWM_Capture_A_Edge0:
            value = base->SM[submodule].CVAL2;
            break;
        case kFLEXPWM_Capture_A_Edge1:
            value = base->SM[submodule].CVAL3;
            break;
#endif
#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELB) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELB)
        case kFLEXPWM_Capture_B_Edge0:
            value = base->SM[submodule].CVAL4;
            break;
        case kFLEXPWM_Capture_B_Edge1:
            value = base->SM[submodule].CVAL5;
            break;
#endif
        default:
            value = 0U;
            break;
    }

    return value;
}

/*!
 * @brief Read captured cycle counter value from a FlexPWM capture channel.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param captureIndex Capture channel and edge detector index.
 * @return The captured cycle counter value (16-bit).
 */
uint16_t FLEXPWM_GetInputCaptureCycle(PWM_Type *base, uint8_t submodule, flexpwm_capture_index_t captureIndex)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);

    uint16_t cycle;

    /* Read the corresponding CVALxCYC register based on capture index */
    switch (captureIndex)
    {
#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELX) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELX)
        case kFLEXPWM_Capture_X_Edge0:
            cycle = base->SM[submodule].CVAL0CYC;
            break;
        case kFLEXPWM_Capture_X_Edge1:
            cycle = base->SM[submodule].CVAL1CYC;
            break;
#endif
#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELA) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELA)
        case kFLEXPWM_Capture_A_Edge0:
            cycle = base->SM[submodule].CVAL2CYC;
            break;
        case kFLEXPWM_Capture_A_Edge1:
            cycle = base->SM[submodule].CVAL3CYC;
            break;
#endif
#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELB) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELB)
        case kFLEXPWM_Capture_B_Edge0:
            cycle = base->SM[submodule].CVAL4CYC;
            break;
        case kFLEXPWM_Capture_B_Edge1:
            cycle = base->SM[submodule].CVAL5CYC;
            break;
#endif
        default:
            cycle = 0U;
            break;
    }

    return cycle;
}

/*!
 * @brief Enable input capture for a FlexPWM capture channel.
 *
 * This function enables input capture operation for the specified capture channel by setting
 * the corresponding ARM bit (ARMA/ARMB/ARMX) in the capture control register.
 *
 * The ARM bit serves as the master enable for the capture channel. When set:
 * - Edge detectors become active and monitor the selected input signal
 * - Capture events store counter values to FIFO
 * - Capture flags are set when FIFO watermark is reached
 *
 * @note ARM bit behavior in one-shot mode:
 *       When the capture channel is configured for one-shot mode (ONESHOT = 1), the ARM bit
 *       automatically clears after two capture events complete. The user must re-enable
 *       capture by calling this function again.
 *
 * @note Prerequisites:
 *       Before enabling capture, ensure:
 *       1. Capture channel is configured (FLEXPWM_ConfigInputCapture)
 *       2. Edge detectors are configured (EDGA0/EDGA1, EDGB0/EDGB1, or EDGX0/EDGX1)
 *       3. Counter is running (FLEXPWM_EnableSubmoduleCounter)
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param channel Capture channel selection (use flexpwm_capture_channel_t enum).
 *                - kFLEXPWM_Capture_A: Enable Capture_A (sets CAPTCTRLA[ARMA])
 *                - kFLEXPWM_Capture_B: Enable Capture_B (sets CAPTCTRLB[ARMB])
 *                - kFLEXPWM_Capture_X: Enable Capture_X (sets CAPTCTRLX[ARMX])
 */
void FLEXPWM_EnableInputCapture(PWM_Type *base, uint8_t submodule, flexpwm_capture_channel_t channel)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);

    switch (channel)
    {
#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELA) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELA)
        case kFLEXPWM_Capture_A:
            base->SM[submodule].CAPTCTRLA |= PWM_CAPTCTRLA_ARMA_MASK;
            break;
#endif
#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELB) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELB)
        case kFLEXPWM_Capture_B:
            base->SM[submodule].CAPTCTRLB |= PWM_CAPTCTRLB_ARMB_MASK;
            break;
#endif
#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELX) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELX)
        case kFLEXPWM_Capture_X:
            base->SM[submodule].CAPTCTRLX |= PWM_CAPTCTRLX_ARMX_MASK;
            break;
#endif
        default:
            assert(false);  /* Invalid channel selection */
            break;
    }
}

/*!
 * @brief Disable input capture for a FlexPWM capture channel.
 *
 * This function disables input capture operation for the specified capture channel by clearing
 * the corresponding ARM bit (ARMA/ARMB/ARMX) in the capture control register.
 *
 * When the ARM bit is cleared:
 * - Edge detection stops immediately
 * - No new capture events are recorded
 * - Existing FIFO contents remain unchanged (can still be read)
 * - Capture flags remain unchanged (must be cleared separately if needed)
 *
 * @note FIFO handling:
 *       Disabling capture does not flush the FIFO. Any previously captured values remain
 *       readable. Clear the capture flags (CFx0/CFx1) separately if needed.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param channel Capture channel selection (use flexpwm_capture_channel_t enum).
 *                - kFLEXPWM_Capture_A: Disable Capture_A (clears CAPTCTRLA[ARMA])
 *                - kFLEXPWM_Capture_B: Disable Capture_B (clears CAPTCTRLB[ARMB])
 *                - kFLEXPWM_Capture_X: Disable Capture_X (clears CAPTCTRLX[ARMX])
 */
void FLEXPWM_DisableInputCapture(PWM_Type *base, uint8_t submodule, flexpwm_capture_channel_t channel)
{
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);

    switch (channel)
    {
#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELA) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELA)
        case kFLEXPWM_Capture_A:
            base->SM[submodule].CAPTCTRLA &= MCUX_MASK_INVERT_16(PWM_CAPTCTRLA_ARMA_MASK);
            break;
#endif
#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELB) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELB)
        case kFLEXPWM_Capture_B:
            base->SM[submodule].CAPTCTRLB &= MCUX_MASK_INVERT_16(PWM_CAPTCTRLB_ARMB_MASK);
            break;
#endif
#if (defined(FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELX) && FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELX)
        case kFLEXPWM_Capture_X:
            base->SM[submodule].CAPTCTRLX &= MCUX_MASK_INVERT_16(PWM_CAPTCTRLX_ARMX_MASK);
            break;
#endif
        default:
            assert(false);  /* Invalid channel selection */
            break;
    }
}

/*!
 * @brief Configure DMA for a FlexPWM submodule.
 *
 * @param base FlexPWM peripheral base address.
 * @param submodule Submodule number (0-3).
 * @param config Pointer to DMA configuration structure.
 */
void FLEXPWM_ConfigDMA(PWM_Type *base, uint8_t submodule, const flexpwm_dma_config_t *config)
{
    assert(NULL != config);
    assert(submodule < (uint8_t)FSL_FEATURE_PWM_SUBMODULE_COUNT);

    uint16_t reg;

    /* Read current DMAEN register value */
    reg = base->SM[submodule].DMAEN;

    /* Clear CAPTDE and FAND bits */
    reg &= MCUX_MASK_INVERT_16(PWM_DMAEN_CAPTDE_MASK | PWM_DMAEN_FAND_MASK);

    /* Configure capture DMA enable source selection */
    reg |= PWM_DMAEN_CAPTDE(config->captureSource);

    /* Configure FIFO watermark AND/OR control */
    if (config->fifoWatermarkAND)
    {
        reg |= PWM_DMAEN_FAND_MASK;
    }

    /* Write back to DMAEN register */
    base->SM[submodule].DMAEN = reg;
}

