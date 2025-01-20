/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_smartcard_phy.h"
#include "fsl_port.h"
#include "fsl_smartcard_uart.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.smartcard_phy_gpio"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static uint32_t smartcard_phy_gpio_InterfaceClockInit(smartcard_interface_config_t const *config, uint32_t srcClock_Hz);
static void smartcard_phy_gpio_InterfaceClockDeinit(smartcard_interface_config_t const *config);
static void smartcard_phy_gpio_ClockStart(smartcard_interface_config_t const *config);
static void smartcard_phy_gpio_ClockStop(smartcard_interface_config_t const *config);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief This function initializes clock module used for card clock generation
 */
static uint32_t smartcard_phy_gpio_InterfaceClockInit(smartcard_interface_config_t const *config, uint32_t srcClock_Hz)
{
    assert((NULL != config));

#if defined(FSL_FEATURE_SOC_FTM_COUNT) && (FSL_FEATURE_SOC_FTM_COUNT)
    assert(config->clockModule < FSL_FEATURE_SOC_FTM_COUNT);

    uint32_t periph_clk_mhz = 0u;
    uint16_t ftmModValue;
    uint32_t ftm_base[] = FTM_BASE_ADDRS;
    FTM_Type *base      = (FTM_Type *)ftm_base[config->clockModule];

    /* Retrieve FTM system clock */
    periph_clk_mhz = srcClock_Hz / 1000000u;
    /* Calculate MOD value */
    ftmModValue = ((periph_clk_mhz * 1000u / 2u) / (config->smartCardClock / 1000u)) - 1u;
    /* un-gate FTM peripheral clock */
    switch (config->clockModule)
    {
        case 0u:
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
            CLOCK_EnableClock(kCLOCK_Ftm0);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
            break;
#if FSL_FEATURE_SOC_FTM_COUNT > 1u
        case 1u:
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
            CLOCK_EnableClock(kCLOCK_Ftm1);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
            break;
#endif
#if FSL_FEATURE_SOC_FTM_COUNT > 2u
        case 2u:
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
            CLOCK_EnableClock(kCLOCK_Ftm2);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
            break;
#endif
#if FSL_FEATURE_SOC_FTM_COUNT > 3u
        case 3u:
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
            CLOCK_EnableClock(kCLOCK_Ftm3);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
            break;
#endif
        default:
            return 0;
            break;
    }
    /* Initialize FTM driver */
    /* Reset FTM prescaler to 'Divide by 1' to be same clock as peripheral clock  */
    base->SC &= ~FTM_SC_PS_MASK;
    /* Disable FTM counter firstly */
    base->SC &= ~FTM_SC_CLKS_MASK;
    /* Set initial counter value */
    base->CNTIN = 0u;
    /* Set MOD value */
    base->MOD = ftmModValue;
    /*  Set counter to operates in Up-counting mode */
    base->SC &= ~FTM_SC_CPWMS_MASK;
    /* Configure mode to output compare, toggle output on match */
    base->CONTROLS[config->clockModuleChannel].CnSC |= FTM_CnSC_ELSA_MASK;
    base->CONTROLS[config->clockModuleChannel].CnSC &= ~FTM_CnSC_ELSB_MASK;
    base->CONTROLS[config->clockModuleChannel].CnSC |= FTM_CnSC_MSA_MASK;
    base->CONTROLS[config->clockModuleChannel].CnSC &= ~FTM_CnSC_MSB_MASK;
    /* Configure a match value to toggle output at */
    base->CONTROLS[config->clockModuleChannel].CnV = 1u;
    /* Re-calculate the actually configured SMARTCARD clock and return to caller */
    return (uint32_t)(((periph_clk_mhz * 1000u / 2u) / (base->MOD + 1u)) * 1000u);

#elif defined(FSL_FEATURE_SOC_TPM_COUNT) && (FSL_FEATURE_SOC_TPM_COUNT)
    assert(config->clockModule < FSL_FEATURE_SOC_TPM_COUNT);

    uint32_t periph_clk_mhz = 0u;
    uint16_t tpmModValue;
    uint32_t tpm_base[] = TPM_BASE_ADDRS;
    TPM_Type *base      = (TPM_Type *)tpm_base[config->clockModule];

    /* Retrieve TPM system clock */
    periph_clk_mhz = srcClock_Hz / 1000000u;
    /* Calculate MOD value */
    tpmModValue = ((periph_clk_mhz * 1000u / 2u) / (config->smartCardClock / 1000u)) - 1u;
    /* un-gate TPM peripheral clock */
    switch (config->clockModule)
    {
        case 0u:
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
            CLOCK_EnableClock(kCLOCK_Tpm0);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
            break;
#if FSL_FEATURE_SOC_TPM_COUNT > 1u
        case 1u:
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
            CLOCK_EnableClock(kCLOCK_Tpm1);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
            break;
#endif
#if FSL_FEATURE_SOC_TPM_COUNT > 2u
        case 2u:
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
            CLOCK_EnableClock(kCLOCK_Tpm2);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
            break;
#endif
#if FSL_FEATURE_SOC_TPM_COUNT > 3u
        case 3u:
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
            CLOCK_EnableClock(kCLOCK_Tpm3);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
            break;
#endif
        default:
            break;
    }
    /* Initialize TPM driver */
    /* Reset TPM prescaler to 'Divide by 1' to be same clock as peripheral clock  */
    base->SC &= ~TPM_SC_PS_MASK;
    /* Disable TPM counter firstly */
    base->SC &= ~TPM_SC_CMOD_MASK;
    /* Set MOD value */
    base->MOD = tpmModValue;
    /*  Set counter to operates in Up-counting mode */
    base->SC &= ~TPM_SC_CPWMS_MASK;
    /* Configure mode to output compare, toggle output on match */
    base->CONTROLS[config->clockModuleChannel].CnSC |= TPM_CnSC_ELSA_MASK | TPM_CnSC_MSA_MASK;
    /* Configure a match value to toggle output at */
    base->CONTROLS[config->clockModuleChannel].CnV = 1u;
    /* Re-calculate the actually configured smartcard clock and return to caller */
    return (uint32_t)(((periph_clk_mhz * 1000u / 2u) / (base->MOD + 1u)) * 1000u);
#else
    return 0u;
#endif
}

/*!
 * @brief This function de-initialize clock module used for card clock generation
 */
static void smartcard_phy_gpio_InterfaceClockDeinit(smartcard_interface_config_t const *config)
{
#if defined(FSL_FEATURE_SOC_FTM_COUNT) && (FSL_FEATURE_SOC_FTM_COUNT)
    assert(config->clockModule < FSL_FEATURE_SOC_FTM_COUNT);
    /* gate FTM peripheral clock */
    switch (config->clockModule)
    {
        case 0u:
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
            CLOCK_DisableClock(kCLOCK_Ftm0);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
            break;
#if FSL_FEATURE_SOC_FTM_COUNT > 1
        case 1u:
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
            CLOCK_DisableClock(kCLOCK_Ftm1);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
            break;
#endif
#if FSL_FEATURE_SOC_FTM_COUNT > 2
        case 2u:
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
            CLOCK_DisableClock(kCLOCK_Ftm2);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
            break;
#endif
#if FSL_FEATURE_SOC_FTM_COUNT > 3
        case 3u:
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
            CLOCK_DisableClock(kCLOCK_Ftm3);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
            break;
#endif
        default:
            break;
    }
#elif defined(FSL_FEATURE_SOC_TPM_COUNT) && (FSL_FEATURE_SOC_TPM_COUNT)
    assert(config->clockModule < FSL_FEATURE_SOC_TPM_COUNT);
    /* gate TPM peripheral clock */
    switch (config->clockModule)
    {
        case 0u:
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
            CLOCK_DisableClock(kCLOCK_Tpm0);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
            break;
#if FSL_FEATURE_SOC_TPM_COUNT > 1
        case 1u:
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
            CLOCK_DisableClock(kCLOCK_Tpm1);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
            break;
#endif
#if FSL_FEATURE_SOC_TPM_COUNT > 2
        case 2u:
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
            CLOCK_DisableClock(kCLOCK_Tpm2);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
            break;
#endif
#if FSL_FEATURE_SOC_TPM_COUNT > 3
        case 3u:
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
            CLOCK_DisableClock(kCLOCK_Tpm3);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
            break;
#endif
        default:
            break;
    }
#endif
}

/*!
 * @brief This function enables generation of SMARTCARD clock.
 */
static void smartcard_phy_gpio_ClockStart(smartcard_interface_config_t const *config)
{
#if defined(FSL_FEATURE_SOC_FTM_COUNT) && (FSL_FEATURE_SOC_FTM_COUNT)
    assert(config->clockModule < FSL_FEATURE_SOC_FTM_COUNT);

    uint32_t ftm_base[] = FTM_BASE_ADDRS;
    FTM_Type *base      = (FTM_Type *)ftm_base[config->clockModule];

    /* Set clock source to start the counter : System clock */
    base->SC |= FTM_SC_CLKS(1u);
#elif defined(FSL_FEATURE_SOC_TPM_COUNT) && (FSL_FEATURE_SOC_TPM_COUNT)
    assert(config->clockModule < FSL_FEATURE_SOC_TPM_COUNT);

    uint32_t tpm_base[] = TPM_BASE_ADDRS;
    TPM_Type *base      = (TPM_Type *)tpm_base[config->clockModule];

    /* Activate counter by selection of incrementing TPm counter on every clock */
    base->SC |= TPM_SC_CMOD(1u);
#endif
}

/*!
 * @brief This function stops generation of SMARTCARD clock.
 */
static void smartcard_phy_gpio_ClockStop(smartcard_interface_config_t const *config)
{
#if defined(FSL_FEATURE_SOC_FTM_COUNT) && (FSL_FEATURE_SOC_FTM_COUNT)
    assert(config->clockModule < FSL_FEATURE_SOC_FTM_COUNT);

    uint32_t ftm_base[] = FTM_BASE_ADDRS;
    FTM_Type *base      = (FTM_Type *)ftm_base[config->clockModule];

    /* Set clock source to start the counter : System clock */
    base->SC &= ~FTM_SC_CLKS_MASK;
#elif defined(FSL_FEATURE_SOC_TPM_COUNT) && (FSL_FEATURE_SOC_TPM_COUNT)
    assert(config->clockModule < FSL_FEATURE_SOC_TPM_COUNT);

    uint32_t tpm_base[] = TPM_BASE_ADDRS;
    TPM_Type *base      = (TPM_Type *)tpm_base[config->clockModule];

    /* Set clock source to start the counter : System clock */
    base->SC &= ~TPM_SC_CMOD_MASK;
#endif
}

void SMARTCARD_PHY_GetDefaultConfig(smartcard_interface_config_t *config)
{
    assert((NULL != config));

    /* Initializes the configure structure to zero. */
    memset(config, 0, sizeof(*config));

    config->clockToResetDelay = SMARTCARD_INIT_DELAY_CLOCK_CYCLES;
    config->vcc               = kSMARTCARD_VoltageClassB3_3V;
}

status_t SMARTCARD_PHY_Init(void *base, smartcard_interface_config_t const *config, uint32_t srcClock_Hz)
{
    if ((NULL == config) || (0u == srcClock_Hz))
    {
        return kStatus_SMARTCARD_InvalidInput;
    }

    /* Configure GPIO(CMDVCC, RST, INT, VSEL0, VSEL1) pins */
    uint32_t gpio_base[] = GPIO_BASE_ADDRS;

    /* Set RST pin to zero context and CMDVCC to high */
    ((GPIO_Type *)gpio_base[config->resetPort])->PCOR |= (1u << config->resetPin);
    ((GPIO_Type *)gpio_base[config->controlPort])->PSOR |= (1u << config->controlPin);
    /* Set CMDVCC, RESET pins as output pins */
    ((GPIO_Type *)gpio_base[config->resetPort])->PDDR |= (1u << config->resetPin);
    ((GPIO_Type *)gpio_base[config->controlPort])->PDDR |= (1u << config->controlPin);

    /* SMARTCARD clock initialization */
    if (config->smartCardClock != smartcard_phy_gpio_InterfaceClockInit(config, srcClock_Hz))
    {
        return kStatus_SMARTCARD_OtherError;
    }

    return kStatus_SMARTCARD_Success;
}

void SMARTCARD_PHY_Deinit(void *base, smartcard_interface_config_t const *config)
{
    assert((NULL != config));

    /* Stop SMARTCARD clock */
    smartcard_phy_gpio_InterfaceClockDeinit(config);
}

status_t SMARTCARD_PHY_Activate(void *base, smartcard_context_t *context, smartcard_reset_type_t resetType)
{
    if ((NULL == context) || (NULL == context->timeDelay))
    {
        return kStatus_SMARTCARD_InvalidInput;
    }

    context->timersState.initCharTimerExpired = false;
    context->resetType                        = resetType;
    uint32_t gpio_base[]                      = GPIO_BASE_ADDRS;
    uint32_t port_base[]                      = PORT_BASE_ADDRS;

    if (resetType == kSMARTCARD_ColdReset)
    { /* Ensure that RST is LOW and CMD is low here so that PHY goes in normal mode */
        ((GPIO_Type *)gpio_base[context->interfaceConfig.resetPort])->PCOR |= (1u << context->interfaceConfig.resetPin);
        ((GPIO_Type *)gpio_base[context->interfaceConfig.controlPort])->PCOR |=
            (1u << context->interfaceConfig.controlPin);
        /* Start generation of SMARTCARD clock */
        smartcard_phy_gpio_ClockStart(&context->interfaceConfig);
        /* Set DATA pin from 0 to idle state */
        PORT_SetPinMux((PORT_Type *)port_base[context->interfaceConfig.dataPort], context->interfaceConfig.dataPin,
                       (port_mux_t)context->interfaceConfig.dataPinMux);
    }
    else if (resetType == kSMARTCARD_WarmReset)
    { /* Ensure that card is already active */
        if (!context->cardParams.active)
        { /* Card is not active;hence return */
            return kStatus_SMARTCARD_CardNotActivated;
        }
        /* Pull RESET low to start warm Activation sequence */
        ((GPIO_Type *)gpio_base[context->interfaceConfig.resetPort])->PCOR |= (1u << context->interfaceConfig.resetPin);
    }
    else
    {
        return kStatus_SMARTCARD_InvalidInput;
    }
    /* Wait for sometime as specified by EMV before pulling RST High
     * As per EMV delay <= 42000 Clock cycles
     * as per PHY delay >= 1us */
    uint32_t temp = (uint32_t)((float)(1 + (float)(((float)(1000u * context->interfaceConfig.clockToResetDelay)) /
                                                   ((float)context->interfaceConfig.smartCardClock))));
    context->timeDelay(temp);

    /* Pull reset HIGH Now to mark the end of Activation sequence */
    ((GPIO_Type *)gpio_base[context->interfaceConfig.resetPort])->PSOR |= (1u << context->interfaceConfig.resetPin);

    /* Enable external timer for TS detection time-out */
    smartcard_uart_TimerStart(context->interfaceConfig.tsTimerId,
                              (SMARTCARD_INIT_DELAY_CLOCK_CYCLES + SMARTCARD_INIT_DELAY_CLOCK_CYCLES_ADJUSTMENT) *
                                  (CLOCK_GetFreq(kCLOCK_CoreSysClk) / context->interfaceConfig.smartCardClock));
    /* Here the card was activated */
    context->cardParams.active = true;

    return kStatus_SMARTCARD_Success;
}

status_t SMARTCARD_PHY_Deactivate(void *base, smartcard_context_t *context)
{
    if ((NULL == context) || (NULL == context->timeDelay))
    {
        return kStatus_SMARTCARD_InvalidInput;
    }

    uint32_t gpio_base[] = GPIO_BASE_ADDRS;
    uint32_t port_base[] = PORT_BASE_ADDRS;
    /* Put RST low to start Deactivation sequence */
    ((GPIO_Type *)gpio_base[context->interfaceConfig.resetPort])->PCOR |= (1u << context->interfaceConfig.resetPin);
    /* Stop SMARTCARD clock */
    smartcard_phy_gpio_ClockStop(&context->interfaceConfig);
    /* Put IO line down */
    /* Set IO pin as GPIO & Pull it low */
    ((GPIO_Type *)gpio_base[context->interfaceConfig.dataPort])->PCOR |= (1u << context->interfaceConfig.dataPin);
    PORT_SetPinMux((PORT_Type *)port_base[context->interfaceConfig.dataPort], context->interfaceConfig.dataPin,
                   kPORT_MuxAsGpio);
    /* Turn off SMARTCARD Vcc */
    ((GPIO_Type *)gpio_base[context->interfaceConfig.controlPort])->PSOR |= (1u << context->interfaceConfig.controlPin);
    /* According EMV 4.3 specification deactivation sequence should be done within 100ms.
     * The period is measured from the time that RST is set to state L to the time that Vcc
     * reaches 0.4 V or less.
     */
    context->timeDelay(100);
    /* Here the card was deactivated */
    context->cardParams.active = false;

    return kStatus_SMARTCARD_Success;
}

status_t SMARTCARD_PHY_Control(void *base,
                               smartcard_context_t *context,
                               smartcard_interface_control_t control,
                               uint32_t param)
{
    if ((NULL == context))
    {
        return kStatus_SMARTCARD_InvalidInput;
    }

    switch (control)
    {
        case kSMARTCARD_InterfaceSetVcc:
            /* Set card parameter to VCC level set by caller */
            context->interfaceConfig.vcc = (smartcard_card_voltage_class_t)param;
            break;
        case kSMARTCARD_InterfaceSetClockToResetDelay:
            /* Set interface clock to Reset delay set by caller */
            context->interfaceConfig.clockToResetDelay = param;
            break;
        default:
            return kStatus_SMARTCARD_InvalidInput;
    }

    return kStatus_SMARTCARD_Success;
}
