/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_emios.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.emios"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to eMIOS bases for each instance. */
static EMIOS_Type *const s_eMIOSBases[] = EMIOS_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to eMIOS clocks for each instance. */
static const clock_ip_name_t s_eMIOSClocks[] = EMIOS_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * brief Configure Output Pulse Width and Frequency Modulation Buffered (OPWFMB) mode parameter.
 * 
 * This function configures OPWFMB mode PWM parameter and polarity.
 * 
 * param base    eMIOS peripheral base address.
 * param config  Pointer to PWM configuration structure.
 * param channel Channel number to configure.
 */
static void EMIOS_ConfigPulseWidthFrequencyBufferedMode(EMIOS_Type *base,
                                                        const emios_uc_pwm_config_t *config,
                                                        uint8_t channel)
{
    assert(config->period > 1U);

    base->UC[channel].A = config->dutyCycle;
    base->UC[channel].B = config->period;
    EMIOS_SetUCEdgePolarity(base, channel, (config->polarity == kEMIOS_Output_ActiveHigh) ? 0U : 1U);
}

/*!
 * brief Configure Center Aligned Output PWM with Dead Time Insertion Buffered (OPWMCB) mode parameter.
 * 
 * This function calculates OPWMCB mode PWM parameter and configures polarity.
 *
 * param base    eMIOS peripheral base address.
 * param config  Pointer to PWM configuration structure.
 * param channel Channel number to configure.
 */
static void EMIOS_ConfigCenterAlignedDeadTimeBufferedMode(EMIOS_Type *base,
                                                          const emios_uc_pwm_config_t *config,
                                                          uint8_t channel)
{
    uint32_t dutyCycle;
    uint32_t period = EMIOS_GetCounterBusPeriod(base, config->counterBus, channel);
    assert(period != 0U);
    assert(EMIOS_GetCounterBusMode(base, config->counterBus, channel) == UC_MC_MODE_MCB_UPDOWN);

    if (config->dutyCycle == config->period)
    {
        dutyCycle = 1U;
    }
    else if (config->dutyCycle == 0U || config->dutyCycle == 1U)
    {
        dutyCycle = period + 1U;
    }
    else
    {
        dutyCycle = config->dutyCycle >> 1U;
        assert(period > dutyCycle);
        dutyCycle = period - dutyCycle;
    }

    base->UC[channel].A = dutyCycle;
    base->UC[channel].B = config->deadTime;
    EMIOS_SetUCEdgePolarity(base, channel, (config->polarity == kEMIOS_Output_ActiveHigh) ? 1U : 0U);
}

/*!
 * brief Configure Output PWM Buffered (OPWMB) mode parameter.
 * 
 * This function calculates OPWMB mode PWM parameter and configures polarity.
 *
 * param base    eMIOS peripheral base address.
 * param config  Pointer to PWM configuration structure.
 * param channel Channel number to configure.
 */
static void EMIOS_ConfigEdgePlacementBufferedMode(EMIOS_Type *base,
                                                  const emios_uc_pwm_config_t *config,
                                                  uint8_t channel)
{
    uint32_t trailingEdge = config->phaseShift + config->dutyCycle;
    assert(EMIOS_GetCounterBusPeriod(base, config->counterBus, channel) != 0U);
    assert(trailingEdge <= EMIOS_GetCounterBusPeriod(base, config->counterBus, channel));
    assert(EMIOS_GetCounterBusMode(base, config->counterBus, channel) == UC_MC_MODE_MCB_UP);

    base->UC[channel].A = config->phaseShift;
    base->UC[channel].B = trailingEdge;
    EMIOS_SetUCEdgePolarity(base, channel, (config->polarity == kEMIOS_Output_ActiveHigh) ? 1U : 0U);
}

/*!
 * brief Configure Output PWM with Trigger (OPWMT) mode parameter.
 * 
 * This function calculates OPWMT mode PWM parameter and configures polarity.
 *
 * param base    eMIOS peripheral base address.
 * param config  Pointer to PWM configuration structure.
 * param channel Channel number to configure.
 */
static void EMIOS_ConfigPWMTriggerMode(EMIOS_Type *base, const emios_uc_pwm_config_t *config, uint8_t channel)
{
    uint32_t counterStart;
    uint32_t trailingEdge;
    uint32_t period = EMIOS_GetCounterBusPeriod(base, config->counterBus, channel);
    uint32_t counterBusMode = EMIOS_GetCounterBusMode(base, config->counterBus, channel);
    assert(period != 0U);
    assert(period < 0xFFFFU);
    assert(config->dutyCycle <= period);
    assert(config->phaseShift <= period);
    assert(config->triggerPosition <= period);
    assert(counterBusMode == UC_MC_MODE_MC_UP || counterBusMode == UC_MC_MODE_MCB_UP);

    if (counterBusMode == UC_MC_MODE_MC_UP)
    {
        counterStart = 0U;
    }
    else
    {
        counterStart = 1U;
    }

    if (config->dutyCycle == config->period)
    {
        trailingEdge = period + 1U;
    }
    else if (config->dutyCycle == 0U)
    {
        trailingEdge = config->phaseShift;
    }
    else
    {
        trailingEdge = (config->phaseShift + config->dutyCycle) % period;
    }

    base->UC[channel].A = config->phaseShift + counterStart;
    base->UC[channel].B = trailingEdge + counterStart;
    base->UC[channel].ALTA = config->triggerPosition + counterStart;
    EMIOS_SetUCEdgePolarity(base, channel, (config->polarity == kEMIOS_Output_ActiveHigh) ? 1U : 0U);
}

/*!
 * brief Get the eMIOS instance from peripheral base address.
 *
 * param base eMIOS peripheral base address.
 * return eMIOS instance.
 */
uint32_t EMIOS_GetInstance(EMIOS_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_eMIOSBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_eMIOSBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_eMIOSBases));

    return instance;
}

/*!
 * brief Initialize eMIOS instance.
 *
 * param base   eMIOS peripheral base address.
 * param config Pointer to user's eMIOS config structure.
 */
void EMIOS_Init(EMIOS_Type *base, const emios_config_t *config)
{
    assert(config != NULL);
    uint32_t mcrTemp;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable eMIOS clock */
    (void)CLOCK_EnableClock(s_eMIOSClocks[EMIOS_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    mcrTemp = base->MCR;
    mcrTemp |= (config->allowFreezeUC ? EMIOS_MCR_FRZ_MASK : 0U);
    mcrTemp |= (config->useGlobalTimeBase ? EMIOS_MCR_GTBE_MASK : 0U);
    mcrTemp |= EMIOS_MCR_GPRE(config->prescale);
    mcrTemp &= ~(EMIOS_MCR_GPREN_MASK | EMIOS_MCR_MDIS_MASK);

    base->MCR = mcrTemp;
    base->OUDIS = 0U;
    base->UCDIS = 0U;

    for (uint8_t i = 0U; i < EMIOS_CH_UC_UC_COUNT; i++)
    {
        base->UC[i].C = 0U;
        base->UC[i].C2 = 0U;
    }
}

/*!
 * brief Disable eMIOS module and gate eMIOS clock.
 * 
 * param base eMIOS peripheral base address
 */
void EMIOS_Deinit(EMIOS_Type *base)
{
    uint32_t mcrTemp;

    mcrTemp = base->MCR;
    mcrTemp &= ~(EMIOS_MCR_GPRE_MASK | EMIOS_MCR_GPREN_MASK | EMIOS_MCR_GTBE_MASK | EMIOS_MCR_FRZ_MASK);
    mcrTemp |= EMIOS_MCR_MDIS_MASK;

    base->MCR = mcrTemp;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Gate eMIOS clock */
    (void)CLOCK_DisableClock(s_eMIOSClocks[EMIOS_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Gets the default configuration structure.
 *
 * This function initializes the eMIOS configuration structure to default values. The default
 * values are as follows.
 *   config->prescale = 0U;
 *   config->allowFreezeUC = false;
 *   config->useGlobalTimeBase = false;
 * 
 * param config Pointer to the eMIOS configuration structure.
 */
void EMIOS_GetDefaultConfig(emios_config_t *config)
{
    assert(config != NULL);

    /* Initialize the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    /* Default eMIOS global clock prescaler value is 1. */
    config->prescale = 0U;

    /* All UCs cannot enter Freeze state when chip is in Debug mode. */
    config->allowFreezeUC = false;

    /* Use internal eMIOS counter as timebase. */
    config->useGlobalTimeBase = false;
}

/*!
 * brief Configure Unified Channel (UC) as Modulus Counter.
 *
 * This function configures a channel to operate in Modulus Counter (MC) or
 * Modulus Counter Buffered (MCB) mode. The counter can be configured for:
 * - Up count or Up/Down count modes
 * - Internal or external clock source
 * - Various reset timing options
 *
 * param base    eMIOS peripheral base address.
 * param config  Pointer to Modulus Counter configuration structure.
 * param channel Channel number to configure.
 */
void EMIOS_ConfigModulusCounter(EMIOS_Type *base, const emios_uc_mc_config_t *config, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    uint32_t reg = 0U;
    uint32_t mode = 0U;
    uint32_t temp = 0U;

    reg = base->UC[channel].C;
    reg &= ~(EMIOS_C_MODE_MASK | EMIOS_C_EDPOL_MASK | EMIOS_C_UCPREN_MASK | EMIOS_C_UCPRE_MASK);
    reg |= EMIOS_C_EDSEL_MASK;
    base->UC[channel].C = reg;

    base->UC[channel].C2 &= ~(EMIOS_C2_UCEXTPRE_MASK | EMIOS_C2_UCPRECLK_MASK);
    mode = (uint32_t)config->ucMode;
    mode &= UC_MC_MODE_MASK;

    if (mode == UC_MC_MODE_MC_UP || mode == UC_MC_MODE_MC_UPDOWN)
    {
        assert(config->period > 0U);
        base->UC[channel].CNT = 0U;     /* Modulus Counter (MC) mode */
    }
    else
    {
        assert(config->period > 1U);
        base->UC[channel].CNT = 1U;     /* Modulus Counter Buffered (MCB) mode */
    }
    base->UC[channel].A = config->period;

    reg = base->UC[channel].C;

    reg |= EMIOS_C_BSL_MASK;
    reg = (config->enableFreeze) ? (reg | EMIOS_C_FREN_MASK) : (reg & ~EMIOS_C_FREN_MASK);

    mode = (uint32_t)config->ucMode;
    temp = (uint32_t)config->clockSource;
    mode |= temp;

    if (config->ucMode == kEMIOS_MC_UpCount || config->ucMode == kEMIOS_MC_UpDownCount)
    {
        temp = (uint32_t)config->counterResetTiming;
        mode |= temp;
    }

    if (config->clockSource == kEMIOS_ClkSrcExternal)
    {
        reg = (reg & ~EMIOS_C_EDSEL_MASK) | EMIOS_C_EDSEL(config->edgeSelect);
        reg = (reg & ~EMIOS_C_EDPOL_MASK) | EMIOS_C_EDPOL(config->edgePolarity);
    }
    else
    {
        reg &= ~(EMIOS_C_EDSEL_MASK);
    }

    reg = (reg & ~EMIOS_C_MODE_MASK) | EMIOS_C_MODE(mode);

    base->UC[channel].C = reg;

    reg = base->UC[channel].C2;
    reg = (reg & ~EMIOS_C2_UCEXTPRE_MASK) | EMIOS_C2_UCEXTPRE(config->prescale);
    reg = (reg & ~EMIOS_C2_UCPRECLK_MASK) | EMIOS_C2_UCPRECLK(config->prescalerSource);
    reg = (reg & ~EMIOS_C2_UCRELDEL_INT_MASK) | EMIOS_C2_UCRELDEL_INT(config->reloadOutputDelay);
    base->UC[channel].C2 = reg;
}

/*!
 * brief Configure Unified Channel (UC) for PWM operation.
 *
 * This function configures a channel for various PWM modes:
 * - OPWFMB: Output Pulse Width and Frequency Modulation Buffered
 * - OPWMCB: Center Aligned Output PWM with Dead Time Insertion Buffered
 * - OPWMB: Output PWM Buffered
 * - OPWMT: Output PWM with Trigger
 *
 * param base    eMIOS peripheral base address.
 * param config  Pointer to PWM configuration structure.
 * param channel Channel number to configure.
 */
void EMIOS_ConfigPWM(EMIOS_Type *base, const emios_uc_pwm_config_t *config, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    uint32_t reg = 0U;
    uint32_t mode = (uint32_t)config->ucMode;
    mode &= UC_PWM_MODE_MASK;

    reg = base->UC[channel].C;
    reg &= ~(EMIOS_C_MODE_MASK | EMIOS_C_EDPOL_MASK | EMIOS_C_UCPREN_MASK | EMIOS_C_UCPRE_MASK);
    reg |= EMIOS_C_EDSEL_MASK;
    base->UC[channel].C = reg;

    base->UC[channel].C2 &= ~(EMIOS_C2_UCEXTPRE_MASK | EMIOS_C2_UCPRECLK_MASK);

    switch (mode)
    {
        case UC_PWM_MODE_OPWFMB:
            EMIOS_ConfigPulseWidthFrequencyBufferedMode(base, config, channel);
            base->UC[channel].CNT = 1U;
            break;
        case UC_PWM_MODE_OPWMCB:
            EMIOS_ConfigCenterAlignedDeadTimeBufferedMode(base, config, channel);
            break;
        case UC_PWM_MODE_OPWMB:
            EMIOS_ConfigEdgePlacementBufferedMode(base, config, channel);
            break;
        case UC_PWM_MODE_OPWMT:
            EMIOS_ConfigPWMTriggerMode(base, config, channel);
            break;
        default:
            assert(false);
            break;
    }

    reg = base->UC[channel].C;
    reg &= ~(EMIOS_C_FORCMA_MASK | EMIOS_C_FORCMB_MASK | EMIOS_C_EDSEL_MASK);

    reg = (reg & ~EMIOS_C_BSL_MASK) | EMIOS_C_BSL(config->counterBus);
    reg = (config->enableFreeze) ? (reg | EMIOS_C_FREN_MASK) : (reg & ~EMIOS_C_FREN_MASK);

    if (config->outputDisableSource != kEMIOS_OutputDisable_Source_None)
    {
        reg |= EMIOS_C_ODIS_MASK;
        reg = (reg & ~EMIOS_C_ODISSL_MASK) | EMIOS_C_ODISSL(config->outputDisableSource);
    }
    else
    {
        reg &= ~(EMIOS_C_ODIS_MASK | EMIOS_C_ODISSL_MASK);
    }

    reg = (reg & ~EMIOS_C_MODE_MASK) | EMIOS_C_MODE(config->ucMode);

    base->UC[channel].C = reg;

    reg = base->UC[channel].C2;
    reg = (reg & ~EMIOS_C2_UCEXTPRE_MASK) | EMIOS_C2_UCEXTPRE(config->prescale);
    reg = (reg & ~EMIOS_C2_UCPRECLK_MASK) | EMIOS_C2_UCPRECLK(config->prescalerSource);
    base->UC[channel].C2 = reg;
}

/*!
 * brief Configure Unified Channel (UC) for Output Compare operation.
 *
 * This function configures a channel for:
 * - SAOC: Single Action Output Compare
 * - DAOC: Double Action Output Compare
 *
 * param base    eMIOS peripheral base address.
 * param config  Pointer to Output Compare configuration structure.
 * param channel Channel number to configure.
 */
void EMIOS_ConfigOutputCompare(EMIOS_Type *base, const emios_uc_oc_config_t *config, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    uint32_t reg = 0U;
    uint32_t mode = (uint32_t)config->ucMode;
    uint32_t counterBusMode = EMIOS_GetCounterBusMode(base, config->counterBus, channel);
    mode &= UC_OC_MODE_MASK;

    if (counterBusMode == UC_MC_MODE_MCB_UP || counterBusMode == UC_MC_MODE_MCB_UPDOWN)
    {
        assert(config->leadingEdge > 0U);
    }

    reg = base->UC[channel].C;
    reg &= ~(EMIOS_C_MODE_MASK | EMIOS_C_EDPOL_MASK | EMIOS_C_UCPREN_MASK | EMIOS_C_UCPRE_MASK);
    reg |= EMIOS_C_EDSEL_MASK;
    base->UC[channel].C = reg;

    base->UC[channel].C2 &= ~(EMIOS_C2_UCEXTPRE_MASK | EMIOS_C2_UCPRECLK_MASK);

    if (mode == UC_OC_MODE_SAOC)
    {
        base->UC[channel].A = config->leadingEdge;
    }

    EMIOS_SetUCEdgePolarity(base, channel, (config->polarity == kEMIOS_Output_ActiveHigh) ? 1U : 0U);

    reg = base->UC[channel].C;
    reg &= ~(EMIOS_C_FORCMA_MASK | EMIOS_C_FORCMB_MASK);

    reg = (reg & ~EMIOS_C_BSL_MASK) | EMIOS_C_BSL(config->counterBus);
    reg = (reg & ~EMIOS_C_MODE_MASK) | EMIOS_C_MODE(config->ucMode);
    reg = (config->enableFreeze) ? (reg | EMIOS_C_FREN_MASK) : (reg & ~EMIOS_C_FREN_MASK);

    if (mode == UC_OC_MODE_SAOC)
    {
        reg = (reg & ~EMIOS_C_EDSEL_MASK) | EMIOS_C_EDSEL(config->ocBehavior);
    }
    else
    {
        reg &= ~(EMIOS_C_EDSEL_MASK);
    }

    base->UC[channel].C = reg;

    if (mode == UC_OC_MODE_DAOC)
    {
        base->UC[channel].A = config->leadingEdge;
        base->UC[channel].B = config->trailingEdge;
    }
}

/*!
 * brief Configure Unified Channel (UC) for Input Capture operation.
 *
 * This function configures a channel for various input capture modes:
 * - SAIC: Single Action Input Capture
 * - IPWM: Input Pulse Width Measurement
 * - IPM: Input Period Measurement
 * - PEC: Pulse Edge Counting
 *
 * param base    eMIOS peripheral base address.
 * param config  Pointer to Input Capture configuration structure.
 * param channel Channel number to configure.
 */
void EMIOS_ConfigInputCapture(EMIOS_Type *base, const emios_uc_ic_config_t *config, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    uint32_t reg = 0U;
    uint32_t mode = (uint32_t)config->ucMode;
    uint32_t counterBusMode = EMIOS_GetCounterBusMode(base, config->counterBus, channel);
    mode &= UC_IC_MODE_MASK;

    reg = base->UC[channel].C;
    reg &= ~(EMIOS_C_MODE_MASK | EMIOS_C_EDPOL_MASK | EMIOS_C_UCPREN_MASK | EMIOS_C_UCPRE_MASK);
    reg |= EMIOS_C_EDSEL_MASK;
    base->UC[channel].C = reg;

    base->UC[channel].C2 &= ~(EMIOS_C2_UCEXTPRE_MASK | EMIOS_C2_UCPRECLK_MASK);

    reg = base->UC[channel].C;
    reg &= ~(EMIOS_C_FORCMA_MASK | EMIOS_C_FORCMB_MASK);

    if (mode == UC_IC_MODE_SAIC || mode == UC_IC_MODE_PECC || mode == UC_IC_MODE_PECS)
    {
        reg = (reg & ~EMIOS_C_EDSEL_MASK) | EMIOS_C_EDSEL(config->edgeSelect);
    }
    else
    {
        reg &= ~(EMIOS_C_EDSEL_MASK);
    }

    reg = (reg & ~EMIOS_C_EDPOL_MASK) | EMIOS_C_EDPOL(config->edgePolarity);
    reg = (reg & ~EMIOS_C_BSL_MASK) | EMIOS_C_BSL(config->counterBus);
    reg = (reg & ~EMIOS_C_MODE_MASK) | EMIOS_C_MODE(config->ucMode);
    reg = (reg & ~EMIOS_C_FCK_MASK) | EMIOS_C_FCK(config->filterClock);
    reg = (reg & ~EMIOS_C_IF_MASK) | EMIOS_C_IF(config->filterWidth);
    reg = (config->enableFreeze) ? (reg | EMIOS_C_FREN_MASK) : (reg & ~EMIOS_C_FREN_MASK);

    base->UC[channel].C = reg;

    if (mode == UC_IC_MODE_PECC || mode == UC_IC_MODE_PECS)
    {
        if (counterBusMode == UC_MC_MODE_MCB_UP || counterBusMode == UC_MC_MODE_MCB_UPDOWN)
        {
            assert(config->startTime > 0U);
        }
        base->UC[channel].A = config->startTime;
        base->UC[channel].B = config->endTime;
    }
}

/*!
 * brief Configure Unified Channel (UC) for GPIO operation.
 *
 * This function configures a channel for:
 * - GPIO Input or output mode
 * - Edge polarity for input mode
 * - Capture flag enable/disable
 *
 * param base    eMIOS peripheral base address.
 * param config  Pointer to GPIO configuration structure.
 * param channel Channel number to configure.
 */
void EMIOS_ConfigGPIO(EMIOS_Type *base, const emios_uc_gpio_config_t *config, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    uint32_t reg = 0U;

    reg = base->UC[channel].C;
    reg = (reg & ~EMIOS_C_MODE_MASK) | EMIOS_C_MODE(config->ucMode);

    if (config->ucMode == kEMIOS_GPIO_Input)
    {
        reg = (reg & ~EMIOS_C_EDPOL_MASK) | EMIOS_C_EDPOL(config->edgePolarity);
        reg = (config->enableCaptureFlag) ? (reg & ~EMIOS_C_EDSEL_MASK) : (reg | EMIOS_C_EDSEL_MASK);
    }
    else
    {
        reg &= ~(EMIOS_C_EDPOL_MASK | EMIOS_C_EDSEL_MASK);
    }

    base->UC[channel].C = reg;
}

/*!
 * brief Update PWM configuration for a channel.
 *
 * This function updates the PWM parameters (duty cycle, period, etc.) for already configured PWM channel.
 *
 * param base    eMIOS peripheral base address.
 * param config  Pointer to PWM configuration structure.
 * param channel Channel number to update.
 */
void EMIOS_UpdatePWM(EMIOS_Type *base, const emios_uc_pwm_config_t *config, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    uint32_t mode = (uint32_t)config->ucMode;
    mode &= UC_PWM_MODE_MASK;

    switch (mode)
    {
        case UC_PWM_MODE_OPWFMB:
            EMIOS_ConfigPulseWidthFrequencyBufferedMode(base, config, channel);
            break;
        case UC_PWM_MODE_OPWMCB:
            EMIOS_ConfigCenterAlignedDeadTimeBufferedMode(base, config, channel);
            break;
        case UC_PWM_MODE_OPWMB:
            EMIOS_ConfigEdgePlacementBufferedMode(base, config, channel);
            break;
        case UC_PWM_MODE_OPWMT:
            EMIOS_ConfigPWMTriggerMode(base, config, channel);
            break;
        default:
            assert(false);
            break;
    }
}

/*!
 * brief Get Unified Channel (UC) counter bus period.
 *
 * param base    eMIOS peripheral base address.
 * param source  Counter bus to query (A, BCD, or F).
 * param channel Channel number associated with the counter bus.
 * return Period value of the UC counter bus.
 */
uint32_t EMIOS_GetCounterBusPeriod(EMIOS_Type *base, emios_counterbus_t source, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    uint32_t counterBusChannel = 0xFFU;
    uint32_t counterBusPeriod;

    switch (source)
    {
        case kEMIOS_CounterBus_A:
            counterBusChannel = EMIOS_COUNTERBUS_A;
            break;
        case kEMIOS_CounterBus_BCD:
            counterBusChannel = (uint32_t)channel & EMIOS_COUNTERBUS_BCD;
            break;
        case kEMIOS_CounterBus_F:
            counterBusChannel = EMIOS_COUNTERBUS_F;
            break;
        default:
            assert(false);
            break;
    }

    if (counterBusChannel != 0xFFU)
    {
        assert(counterBusChannel < EMIOS_CH_UC_UC_COUNT);
        counterBusPeriod = base->UC[counterBusChannel].A;
    }
    else
    {
        counterBusPeriod = 0U;
    }

    return counterBusPeriod;
}

/*!
 * brief Get Unified Channel (UC) counter bus mode.
 *
 * param base    eMIOS peripheral base address.
 * param source  Counter bus to query (A, BCD, or F).
 * param channel Channel number associated with the counter bus.
 * return Mode of the UC counter bus (MC or MCB mode).
 */
uint32_t EMIOS_GetCounterBusMode(EMIOS_Type *base, emios_counterbus_t source, uint8_t channel)
{
    assert(channel < EMIOS_CH_UC_UC_COUNT);
    uint32_t counterBusChannel = 0xFFU;
    uint32_t counterBusMode;

    switch (source)
    {
        case kEMIOS_CounterBus_A:
            counterBusChannel = EMIOS_COUNTERBUS_A;
            break;
        case kEMIOS_CounterBus_BCD:
            counterBusChannel = (uint32_t)channel & EMIOS_COUNTERBUS_BCD;
            break;
        case kEMIOS_CounterBus_F:
            counterBusChannel = EMIOS_COUNTERBUS_F;
            break;
        default:
            assert(false);
            break;
    }

    if (counterBusChannel != 0xFFU)
    {
        assert(counterBusChannel < EMIOS_CH_UC_UC_COUNT);
        counterBusMode = (base->UC[counterBusChannel].C & EMIOS_C_MODE_MASK) >> EMIOS_C_MODE_SHIFT;
        counterBusMode &= UC_MC_MODE_MASK;
    }
    else
    {
        counterBusMode = 0U;
    }

    return counterBusMode;
}
