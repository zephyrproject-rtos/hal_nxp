/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_cadc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.cadc"
#endif

/*
 * Define the MACROs to help calculating the position of register field from sample index.
 */
/* ADC_ZXCTRL1 & ADC_ZXCTRL2. */
#define ADC_ZXCTRL_ZCE_MASK(index)   (uint16_t)(3UL << (2U * ((uint16_t)(index))))
#define ADC_ZXCTRL_ZCE(index, value) (uint16_t)(((uint16_t)(value)) << (2U * ((uint16_t)(index))))
/* ADC_CLIST1 & ADC_CLIST2 & ADC_CLIST3 & ADC_CLIST4 */
#define ADC_CLIST_SAMPLE_MASK(index)   (uint16_t)(0xFUL << (4U * ((uint16_t)(index))))
#define ADC_CLIST_SAMPLE(index, value) (uint16_t)(((uint16_t)(value)) << (4U * ((uint16_t)(index))))
/* ADC_GC1 & ADC_GC2. */
#define ADC_GC_GAIN_MASK(index)   (uint16_t)(0x3UL << (2U * ((uint16_t)(index))))
#define ADC_GC_GAIN(index, value) (uint16_t)(((uint16_t)(value)) << (2U * ((uint16_t)(index))))

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Get instance number for CADC module.
 *
 * @param base CADC peripheral base address
 */
static uint32_t CADC_GetInstance(ADC_Type *base);

/*!
 * @brief Configure the converter A.
 *
 * This function is to configure the converter A with converter configuration structure. As the control register bits
 * for converter A and B are not in the same order, the configuring functions are also implemented for each.
 *
 * @param base   CADC peripheral base address.
 * @param config Pointer to configuration structure. See to "cadc_converter_config_t".
 */
static void CADC_SetConverterAConfig(ADC_Type *base, const cadc_converter_config_t *config);

/*!
 * @brief Configure the converter B.
 *
 * This function is to configure the converter B with converter configuration structure. As the control register bits
 * for converter A and B are not in the same order, the configuring functions are also implemented for each.
 *
 * @param base   CADC peripheral base address.
 * @param config Pointer to configuration structure. See to "cadc_converter_config_t".
 */
static void CADC_SetConverterBConfig(ADC_Type *base, const cadc_converter_config_t *config);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to CADC bases for each instance. */
static ADC_Type *const s_cadcBases[] = ADC_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to CADC clocks for each instance. */
static const clock_ip_name_t s_cadcClocks[] = CADC_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE) && FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE
static const uint16_t g_CADCChannelDifferentialModeMask[] = {0x0100U, 0x0200U, 0x1000U, 0x2000U,
                                                             0x400U,  0x800U,  0x4000U, 0x8000U};
#endif /* FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE */
/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t CADC_GetInstance(ADC_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_cadcBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_cadcBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_cadcBases));

    return instance;
}

/*!
 * brief Initializes the CADC module.
 *
 * This function is to make the initialization for using CADC module.
 * The operations are:
 *  - Enable the clock for CADC.
 *  - Set the global settings for CADC converter.
 *
 * param base   CADC peripheral base address.
 * param config Pointer to configuration structure. See "cadc_config_t".
 */
void CADC_Init(ADC_Type *base, const cadc_config_t *config)
{
    assert(NULL != config);

    uint16_t tmp16;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable Clock. */
    CLOCK_EnableClock(s_cadcClocks[CADC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* ADC_CTRL1. */
    tmp16 = (uint16_t)(base->CTRL1 & ~(ADC_CTRL1_SMODE_MASK));
    tmp16 |= ADC_CTRL1_SMODE(config->dualConverterScanMode);
    base->CTRL1 = tmp16;

    /* ADC_CTRL2. */
    if (config->enableSimultaneousMode)
    {
        base->CTRL2 |= ADC_CTRL2_SIMULT_MASK;
    }
    else
    {
        base->CTRL2 &= ~(uint16_t)ADC_CTRL2_SIMULT_MASK;
    }

#if !(defined(FSL_FEATURE_CADC_NO_AUTO_STANDBY) && FSL_FEATURE_CADC_NO_AUTO_STANDBY)
    /* ADC_PWR. */
    tmp16 = (uint16_t)(base->PWR & ~(ADC_PWR_ASB_MASK | ADC_PWR_PUDELAY_MASK | ADC_PWR_APD_MASK));
#else
    tmp16 = (uint16_t)(base->PWR & ~(ADC_PWR_PUDELAY_MASK | ADC_PWR_APD_MASK));
#endif /* FSL_FEATURE_CADC_NO_AUTO_STANDBY */

    tmp16 |= ADC_PWR_PUDELAY(config->powerUpDelay);
#if !(defined(FSL_FEATURE_CADC_NO_AUTO_STANDBY) && FSL_FEATURE_CADC_NO_AUTO_STANDBY)
    if (kCADC_IdleAutoStandby == config->idleWorkMode)
    {
        tmp16 |= ADC_PWR_ASB_MASK;
    }
    else if (kCADC_IdleAutoPowerDown == config->idleWorkMode)
#else
    if (kCADC_IdleAutoPowerDown == config->idleWorkMode)
#endif /* FSL_FEATURE_CADC_NO_AUTO_STANDBY */
    {
        tmp16 |= ADC_PWR_APD_MASK;
    }
    else
    {
        /* To avoid MISRA rule 14.10 error. */
    }
    base->PWR = tmp16;

    /* ADC_CTRL3. */
    if (kCADC_DMATriggerSourceAsSampleReady == config->DMATriggerSource)
    {
        base->CTRL3 |= ADC_CTRL3_DMASRC_MASK;
    }
    else /* kCADCDmaTriggerSourceAsEndOfScan. */
    {
        base->CTRL3 &= ~(uint16_t)ADC_CTRL3_DMASRC_MASK;
    }
}

/*!
 * brief Gets an available pre-defined settings for module's configuration.
 *
 * This function initializes the module's configuration structure with an available settings.
 * The default value are:
 * code
 *   config->dualConverterScanMode = kCADC_DualConverterWorkAsTriggeredParallel;
 *   config->enableSimultaneousMode = true;
 *   config->DMATriggerSource = kCADC_DMATriggerSourceAsEndOfScan;
 *   config->idleWorkMode = kCADC_IdleKeepNormal;
 *   config->powerUpDelay = 26U;
 * endcode
 * param config Pointer to configuration structure. See "cadc_config_t"
 */
void CADC_GetDefaultConfig(cadc_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    /* The default values are from power up reset state. */
    config->dualConverterScanMode  = kCADC_DualConverterWorkAsTriggeredParallel;
    config->enableSimultaneousMode = true;
    config->DMATriggerSource       = kCADC_DMATriggerSourceAsEndOfScan;
    config->idleWorkMode           = kCADC_IdleKeepNormal;
    config->powerUpDelay           = 26U;
}

/*!
 * brief Deinitializes the CADC module.
 *
 * This function is to make the de-initialization for using CADC module.
 * The operations are:
 *  - Power down both converter.
 *  - Disable the clock for CADC.
 *
 * param base CADC peripheral base address.
 */
void CADC_Deinit(ADC_Type *base)
{
    /* Stop both converter. */
    CADC_EnableConverter(base, (uint16_t)kCADC_ConverterA | (uint16_t)kCADC_ConverterB, false);
    /* Power done both converter. */
    CADC_EnableConverterPower(base, (uint16_t)kCADC_ConverterA | (uint16_t)kCADC_ConverterB, false);
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(s_cadcClocks[CADC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

static void CADC_SetConverterAConfig(ADC_Type *base, const cadc_converter_config_t *config)
{
    assert(NULL != config);

    uint16_t tmp16;

    /* ADC_CTRL2. */
    tmp16 = base->CTRL2 & ~(uint16_t)(ADC_CTRL2_DIV0_MASK);
    tmp16 |= ADC_CTRL2_DIV0(config->clockDivisor);
    base->CTRL2 = tmp16;

    /* ADC_CAL. */
    tmp16 = base->CAL & ~(uint16_t)(ADC_CAL_SEL_VREFH_A_MASK | ADC_CAL_SEL_VREFLO_A_MASK);
    if (kCADC_ReferenceVoltageChannelPad == config->highReferenceVoltageSource)
    {
        tmp16 |= ADC_CAL_SEL_VREFH_A_MASK;
    }
    if (kCADC_ReferenceVoltageChannelPad == config->lowReferenceVoltageSource)
    {
        tmp16 |= ADC_CAL_SEL_VREFLO_A_MASK;
    }
    base->CAL = tmp16;

#if !(defined(FSL_FEATURE_CADC_NO_SPEEDMODE_BIT) && FSL_FEATURE_CADC_NO_SPEEDMODE_BIT)
    /* ADC_PWR2. */
    tmp16 = base->PWR2 & ~(uint16_t)(ADC_PWR2_SPEEDA_MASK);
    tmp16 |= ADC_PWR2_SPEEDA((uint16_t)(config->speedMode));
    base->PWR2 = tmp16;
#endif /* FSL_FEATURE_CADC_NO_SPEEDMODE_BIT */

#if !(defined(FSL_FEATURE_CADC_NO_SAMPLE_WINDOW) && FSL_FEATURE_CADC_NO_SAMPLE_WINDOW)
    /* ADC_CTRL3. */
    tmp16 = base->CTRL3 & ~(uint16_t)(ADC_CTRL3_SCNT0_MASK);
    tmp16 |= ADC_CTRL3_SCNT0(config->sampleWindowCount);
    base->CTRL3 = tmp16;
#endif /* FSL_FEATURE_CADC_NO_SAMPLE_WINDOW */
}

static void CADC_SetConverterBConfig(ADC_Type *base, const cadc_converter_config_t *config)
{
    assert(NULL != config);

    uint16_t tmp16;

    /* ADC_CAL. */
    tmp16 = base->CAL & ~(uint16_t)(ADC_CAL_SEL_VREFH_B_MASK | ADC_CAL_SEL_VREFLO_B_MASK);
    if (kCADC_ReferenceVoltageChannelPad == config->highReferenceVoltageSource)
    {
        tmp16 |= ADC_CAL_SEL_VREFH_B_MASK;
    }
    if (kCADC_ReferenceVoltageChannelPad == config->lowReferenceVoltageSource)
    {
        tmp16 |= ADC_CAL_SEL_VREFLO_B_MASK;
    }
    base->CAL = tmp16;

#if !(defined(FSL_FEATURE_CADC_NO_SPEEDMODE_BIT) && FSL_FEATURE_CADC_NO_SPEEDMODE_BIT)
    /* ADC_PWR2. */
    tmp16 = base->PWR2 & ~(uint16_t)(ADC_PWR2_DIV1_MASK | ADC_PWR2_SPEEDB_MASK);
    tmp16 |= ADC_PWR2_DIV1(config->clockDivisor) | ADC_PWR2_SPEEDB((uint16_t)(config->speedMode));
    base->PWR2 = tmp16;
#endif /* FSL_FEATURE_CADC_NO_SPEEDMODE_BIT */

#if !(defined(FSL_FEATURE_CADC_NO_SAMPLE_WINDOW) && FSL_FEATURE_CADC_NO_SAMPLE_WINDOW)
    /* ADC_CTRL3. */
    tmp16 = base->CTRL3 & ~(uint16_t)(ADC_CTRL3_SCNT1_MASK);
    tmp16 |= ADC_CTRL3_SCNT1(config->sampleWindowCount);
    base->CTRL3 = tmp16;
#endif /* FSL_FEATURE_CADC_NO_SAMPLE_WINDOW */
}

/*!
 * brief Configures the converter.
 *
 * param base          CADC peripheral base address.
 * param converterMask Mask for converters to be configured. See "_cadc_converter_id".
 * param config        Pointer to configuration structure. See "cadc_converter_config_t".
 */
void CADC_SetConverterConfig(ADC_Type *base, uint16_t converterMask, const cadc_converter_config_t *config)
{
    assert(NULL != config);

    /* For converter A. */
    if ((uint16_t)kCADC_ConverterA == ((uint16_t)kCADC_ConverterA & converterMask))
    {
        CADC_SetConverterAConfig(base, config);
    }
    /* For converter B. */
    if ((uint16_t)kCADC_ConverterB == ((uint16_t)kCADC_ConverterB & converterMask))
    {
        CADC_SetConverterBConfig(base, config);
    }
}

/*!
 * brief Gets an available pre-defined settings for each converter's configuration.
 *
 * This function initializes each converter's configuration structure with an available settings.
 * The default value are:
 * code
 *   config->clockDivisor = 4U;
 *   config->speedMode = kCADC_SpeedMode0;
 *   config->highReferenceVoltageSource = kCADC_ReferenceVoltageVrefPad;
 *   config->lowReferenceVoltageSource = kCADC_ReferenceVoltageVrefPad;
 *   config->sampleWindowCount = 0U;
 * endcode
 * param config Pointer to configuration structure. See "cadc_converter_config_t"
 */
void CADC_GetDefaultConverterConfig(cadc_converter_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    /* The default values are from power up reset state. */
    config->clockDivisor = 4U;
#if !(defined(FSL_FEATURE_CADC_NO_SPEEDMODE_BIT) && FSL_FEATURE_CADC_NO_SPEEDMODE_BIT)
    config->speedMode = kCADC_SpeedMode0;
#endif /* FSL_FEATURE_CADC_NO_SPEEDMODE_BIT */
    config->highReferenceVoltageSource = kCADC_ReferenceVoltageVrefPad;
    config->lowReferenceVoltageSource  = kCADC_ReferenceVoltageVrefPad;
#if !(defined(FSL_FEATURE_CADC_NO_SAMPLE_WINDOW) && FSL_FEATURE_CADC_NO_SAMPLE_WINDOW)
    config->sampleWindowCount = 0U;
#endif /* FSL_FEATURE_CADC_NO_SAMPLE_WINDOW */
}

/*!
 * brief Enables the converter's conversion.
 *
 * This function is to enable the converter's conversion. The conversion should only be launched after the converter is
 * enabled. When this feature is asserted to be "false", the current scan is stopped and no further scans can start. All
 * the software trigger and hardware trigger are ignored.
 *
 * param base          CADC peripheral base address.
 * param converterMask Mask for converters to be operated. See "_cadc_converter_id".
 * param enable        Enable the power for converter.
 */
void CADC_EnableConverter(ADC_Type *base, uint16_t converterMask, bool enable)
{
    /* For converter A. */
    if ((uint16_t)kCADC_ConverterA == ((uint16_t)kCADC_ConverterA & converterMask))
    {
        if (enable)
        {
            base->CTRL1 &= ~(uint16_t)ADC_CTRL1_STOP0_MASK; /* Clear STOP to enable. */
        }
        else
        {
            base->CTRL1 |= ADC_CTRL1_STOP0_MASK;
        }
    }
    /* For converter B. */
    if ((uint16_t)kCADC_ConverterB == ((uint16_t)kCADC_ConverterB & converterMask))
    {
        if (enable)
        {
            base->CTRL2 &= ~(uint16_t)ADC_CTRL2_STOP1_MASK; /* Clear STOP to enable. */
        }
        else
        {
            base->CTRL2 |= ADC_CTRL2_STOP1_MASK;
        }
    }
}

/*!
 * brief Enables the input of external sync signal.
 *
 * This function is to enable the input of external sync signal. The external sync signal could be used to trigger the
 * conversion if the hardware trigger related setting is used.
 * Note: When in "Once" scan mode, this gate would be off automatically after an available sync is received. User needs
 * to enable the input again manually if another sync signal is wanted.
 *
 * param base          CADC peripheral base address.
 * param converterMask Mask for converters to be operated. See "_cadc_converter_id".
 * param enable        Enable the feature or not.
 */
void CADC_EnableConverterSyncInput(ADC_Type *base, uint16_t converterMask, bool enable)
{
    /* For converter A. */
    if ((uint16_t)kCADC_ConverterA == ((uint16_t)kCADC_ConverterA & converterMask))
    {
        if (enable)
        {
            base->CTRL1 |= ADC_CTRL1_SYNC0_MASK;
        }
        else
        {
            base->CTRL1 &= ~(uint16_t)ADC_CTRL1_SYNC0_MASK;
        }
    }
    /* For converter B. */
    if ((uint16_t)kCADC_ConverterB == ((uint16_t)kCADC_ConverterB & converterMask))
    {
        if (enable)
        {
            base->CTRL2 |= ADC_CTRL2_SYNC1_MASK;
        }
        else
        {
            base->CTRL2 &= ~(uint16_t)ADC_CTRL2_SYNC1_MASK;
        }
    }
}

/*!
 * brief Enables power for the converter.
 *
 * This function is to enable the power for the converter. The converter should be powered on before conversion.
 * Once this API is called, the converter would be powered on after a few moment (so-called power up delay), so that
 * the power would be stable.
 *
 * param base          CADC peripheral base address.
 * param converterMask Mask for converters to be operated. See "_cadc_converter_id".
 * param enable        Enable the feature or not.
 */
void CADC_EnableConverterPower(ADC_Type *base, uint16_t converterMask, bool enable)
{
    /* For converter A. */
    if ((uint16_t)kCADC_ConverterA == ((uint16_t)kCADC_ConverterA & converterMask))
    {
        if (enable)
        {
            base->PWR &= ~(uint16_t)ADC_PWR_PD0_MASK; /* Clear PowerDown to enable. */
        }
        else
        {
            base->PWR |= ADC_PWR_PD0_MASK;
        }
    }
    /* For converter B. */
    if ((uint16_t)kCADC_ConverterB == ((uint16_t)kCADC_ConverterB & converterMask))
    {
        if (enable)
        {
            base->PWR &= ~(uint16_t)ADC_PWR_PD1_MASK; /* Clear PowerDown to enable. */
        }
        else
        {
            base->PWR |= ADC_PWR_PD1_MASK;
        }
    }
}

/*!
 * brief Triggers the converter by software trigger.
 *
 * This function is to do the software trigger to the converter. The software trigger can used to start a conversion
 * sequence.
 *
 * param base          CADC peripheral base address.
 * param converterMask Mask for converters to be operated. See "_cadc_converter_id".
 */
void CADC_DoSoftwareTriggerConverter(ADC_Type *base, uint16_t converterMask)
{
    /* For converter A. */
    if ((uint16_t)kCADC_ConverterA == ((uint16_t)kCADC_ConverterA & converterMask))
    {
        base->CTRL1 |= ADC_CTRL1_START0_MASK;
    }
    /* For converter B. */
    if ((uint16_t)kCADC_ConverterB == ((uint16_t)kCADC_ConverterB & converterMask))
    {
        base->CTRL2 |= ADC_CTRL2_START1_MASK;
    }
}

/*!
 * brief Enables the DMA feature.
 *
 * param base          CADC peripheral base address.
 * param converterMask Mask for converters to be operated. See "_cadc_converter_id".
 * param enable        Enable the feature or not.
 */
void CADC_EnableConverterDMA(ADC_Type *base, uint16_t converterMask, bool enable)
{
    /* For converter A. */
    if ((uint16_t)kCADC_ConverterA == ((uint16_t)kCADC_ConverterA & converterMask))
    {
        if (enable)
        {
            base->CTRL1 |= ADC_CTRL1_DMAEN0_MASK;
        }
        else
        {
            base->CTRL1 &= ~(uint16_t)ADC_CTRL1_DMAEN0_MASK;
        }
    }
    /* For converter B. */
    if ((uint16_t)kCADC_ConverterB == ((uint16_t)kCADC_ConverterB & converterMask))
    {
        if (enable)
        {
            base->CTRL2 |= ADC_CTRL2_DMAEN1_MASK;
        }
        else
        {
            base->CTRL2 &= ~(uint16_t)ADC_CTRL2_DMAEN1_MASK;
        }
    }
}

/*!
 * brief Enables the interrupts.
 *
 * param base CADC peripheral base address.
 * param mask Mask value for interrupt events. See "_cadc_interrupt_enable".
 */
void CADC_EnableInterrupts(ADC_Type *base, uint16_t mask)
{
    uint16_t tmp16 = 0U;

    /* ADCx_CTRL1. */
    if ((uint16_t)kCADC_ConverterAEndOfScanInterruptEnable ==
        ((uint16_t)kCADC_ConverterAEndOfScanInterruptEnable & mask))
    {
        tmp16 |= ADC_CTRL1_EOSIE0_MASK;
    }
    if ((uint16_t)kCADC_ZeroCrossingInterruptEnable == ((uint16_t)kCADC_ZeroCrossingInterruptEnable & mask))
    {
        tmp16 |= ADC_CTRL1_ZCIE_MASK;
    }
    if ((uint16_t)kCADC_LowLimitInterruptEnable == ((uint16_t)kCADC_LowLimitInterruptEnable & mask))
    {
        tmp16 |= ADC_CTRL1_LLMTIE_MASK;
    }
    if ((uint16_t)kCADC_HighLimitInterruptEnable == ((uint16_t)kCADC_HighLimitInterruptEnable & mask))
    {
        tmp16 |= ADC_CTRL1_HLMTIE_MASK;
    }
    base->CTRL1 |= tmp16;

    /* ADCx_CTRL2. */
    if ((uint16_t)kCADC_ConverterBEndOfScanInterruptEnable ==
        ((uint16_t)kCADC_ConverterBEndOfScanInterruptEnable & mask))
    {
        base->CTRL2 |= ADC_CTRL2_EOSIE1_MASK;
    }
}
/*!
 * brief Disables the interrupts.
 *
 * param base CADC peripheral base address.
 * param mask Mask value for interrupt events. See "_cadc_interrupt_enable".
 */
void CADC_DisableInterrupts(ADC_Type *base, uint16_t mask)
{
    uint16_t tmp16 = 0U;

    /* ADCx_CTRL1. */
    if ((uint16_t)kCADC_ConverterAEndOfScanInterruptEnable ==
        ((uint16_t)kCADC_ConverterAEndOfScanInterruptEnable & mask))
    {
        tmp16 |= ADC_CTRL1_EOSIE0_MASK;
    }
    if ((uint16_t)kCADC_ZeroCrossingInterruptEnable == ((uint16_t)kCADC_ZeroCrossingInterruptEnable & mask))
    {
        tmp16 |= ADC_CTRL1_ZCIE_MASK;
    }
    if ((uint16_t)kCADC_LowLimitInterruptEnable == ((uint16_t)kCADC_LowLimitInterruptEnable & mask))
    {
        tmp16 |= ADC_CTRL1_LLMTIE_MASK;
    }
    if ((uint16_t)kCADC_HighLimitInterruptEnable == ((uint16_t)kCADC_HighLimitInterruptEnable & mask))
    {
        tmp16 |= ADC_CTRL1_HLMTIE_MASK;
    }
    base->CTRL1 &= (uint16_t)(~tmp16);

    /* ADCx_CTRL2. */
    if ((uint16_t)kCADC_ConverterBEndOfScanInterruptEnable ==
        ((uint16_t)kCADC_ConverterBEndOfScanInterruptEnable & mask))
    {
        base->CTRL2 &= ~(uint16_t)ADC_CTRL2_EOSIE1_MASK;
    }
}

/*!
 * brief  Gets the status flags.
 *
 * param  base CADC peripheral base address.
 *
 * return      Mask value for the event flags. See "_cadc_status_flags".
 */
uint16_t CADC_GetStatusFlags(ADC_Type *base)
{
    uint16_t tmp16 = 0U;

    /* ADC_STAT. */
    if (ADC_STAT_CIP0_MASK == (ADC_STAT_CIP0_MASK & base->STAT))
    {
        tmp16 |= (uint16_t)kCADC_ConverterAInProgressFlag;
    }
    if (ADC_STAT_CIP1_MASK == (ADC_STAT_CIP1_MASK & base->STAT))
    {
        tmp16 |= (uint16_t)kCADC_ConverterBInProgressFlag;
    }
    if (ADC_STAT_EOSI0_MASK == (ADC_STAT_EOSI0_MASK & base->STAT))
    {
        tmp16 |= (uint16_t)kCADC_ConverterAEndOfScanFlag;
    }
    if (ADC_STAT_EOSI1_MASK == (ADC_STAT_EOSI1_MASK & base->STAT))
    {
        tmp16 |= (uint16_t)kCADC_ConverterBEndOfScanFlag;
    }
    if (ADC_STAT_ZCI_MASK == (ADC_STAT_ZCI_MASK & base->STAT))
    {
        tmp16 |= (uint16_t)kCADC_ZeroCrossingFlag;
    }
    if (ADC_STAT_LLMTI_MASK == (ADC_STAT_LLMTI_MASK & base->STAT))
    {
        tmp16 |= (uint16_t)kCADC_LowLimitFlag;
    }
    if (ADC_STAT_HLMTI_MASK == (ADC_STAT_HLMTI_MASK & base->STAT))
    {
        tmp16 |= (uint16_t)kCADC_HighLimitFlag;
    }
    /* ADC_PWR. */
    if (ADC_PWR_PSTS0_MASK == (ADC_PWR_PSTS0_MASK & base->PWR))
    {
        tmp16 |= (uint16_t)kCADC_ConverterAPowerDownFlag;
    }
    if (ADC_PWR_PSTS1_MASK == (ADC_PWR_PSTS1_MASK & base->PWR))
    {
        tmp16 |= (uint16_t)kCADC_ConverterBPowerDownFlag;
    }

    return tmp16;
}

/*!
 * brief Clears the status flags.
 *
 * param base  CADC peripheral base address.
 * param flags Mask value for the event flags to be cleared. See "_cadc_status_flags".
 */
void CADC_ClearStatusFlags(ADC_Type *base, uint16_t flags)
{
    uint16_t tmp16 = 0U;

    if ((uint16_t)kCADC_ConverterAEndOfScanFlag == ((uint16_t)kCADC_ConverterAEndOfScanFlag & flags))
    {
        tmp16 |= ADC_STAT_EOSI0_MASK;
    }
    if ((uint16_t)kCADC_ConverterBEndOfScanFlag == ((uint16_t)kCADC_ConverterBEndOfScanFlag & flags))
    {
        tmp16 |= ADC_STAT_EOSI1_MASK;
    }
    base->STAT = tmp16; /* Write 1 to clear. */
}

/*
 * Mask table for channel differential pair setting.
 * The item's value would be set into ADC_CTRL1[CHNCFG_L] or ADC_CTRL2[CHNCFG_H].
 */
static const uint16_t g_CADCChannelConfigDifferentialMask[] = {
    0x0010, /* CHN0-1,   ANA0-ANA1, ADC_CTRL1[CHNCFG_L]. */
    0x0020, /* CHN2-3,   ANA2-ANA3. ADC_CTRL1[CHNCFG_L]. */
    0x0080, /* CHN4-5,   ANA4-ANA5. ADC_CTRL2[CHNCFG_H]. */
    0x0100, /* CHN6-7,   ANA6-ANA7. ADC_CTRL2[CHNCFG_H]. */
    0x0040, /* CHN8-9,   ANB0-ANB1. ADC_CTRL1[CHNCFG_L]. */
    0x0080, /* CHN10-11, ANB2-ANB3. ADC_CTRL1[CHNCFG_L]. */
    0x0200, /* CHN12-13, ANB4-ANB5. ADC_CTRL2[CHNCFG_H]. */
    0x0400  /* CHN14-15, ANB6-ANB7. ADC_CTRL2[CHNCFG_H]. */
};

/*!
 * brief Configures the sample slot.
 *
 * param base        CADC peripheral base address.
 * param sampleIndex Index of sample slot in conversion sequence. Available range is 0-15.
 * param config      Pointer to configuration structure. See "cadc_sample_config_t"
 */
void CADC_SetSampleConfig(ADC_Type *base, uint16_t sampleIndex, const cadc_sample_config_t *config)
{
    assert(NULL != config);
    assert(sampleIndex < ADC_RSLT_COUNT);

    uint16_t tmp16;

    /* Configure the differential conversion channel. */
    if ((config->channelNumber < 4U) || ((config->channelNumber >= 8U) && (config->channelNumber < 12U)))
    {
        switch (config->sampleMode)
        {
            case kCADC_SingleEndedSampleMode:
                base->CTRL1 &= (uint16_t)(~g_CADCChannelConfigDifferentialMask[config->channelNumber / 2U]);
                break;
            case kCADC_FullyDifferentialMode:
                base->CTRL1 |= g_CADCChannelConfigDifferentialMask[config->channelNumber / 2U];
#if defined(FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE) && FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE
                base->CTRL3 &= ~g_CADCChannelDifferentialModeMask[config->channelNumber / 2U];
#endif /* FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE */
                break;

#if defined(FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE) && FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE
            case kCADC_UnipolarDifferentialMode:
                base->CTRL1 |= g_CADCChannelConfigDifferentialMask[config->channelNumber / 2U];
                base->CTRL3 |= g_CADCChannelDifferentialModeMask[config->channelNumber / 2U];
                break;
#endif /* FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE */
            default:
                /* Added comments to prevent the violation of MISRA C-2012 rule. */
                break;
        }
    }
    else if (((config->channelNumber >= 4U) && (config->channelNumber < 8U)) ||
             ((config->channelNumber >= 12U) && (config->channelNumber < 16U)))
    {
        switch (config->sampleMode)
        {
            case kCADC_SingleEndedSampleMode:
                base->CTRL2 &= (uint16_t)(~g_CADCChannelConfigDifferentialMask[config->channelNumber / 2U]);
                break;
            case kCADC_FullyDifferentialMode:
                base->CTRL2 |= g_CADCChannelConfigDifferentialMask[config->channelNumber / 2U];
#if defined(FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE) && FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE
                base->CTRL3 &= ~g_CADCChannelDifferentialModeMask[config->channelNumber / 2U];
#endif /* FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE */
                break;

#if defined(FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE) && FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE
            case kCADC_UnipolarDifferentialMode:
                base->CTRL2 |= g_CADCChannelConfigDifferentialMask[config->channelNumber / 2U];
                base->CTRL3 |= g_CADCChannelDifferentialModeMask[config->channelNumber / 2U];
                break;
#endif /* FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE */
            default:
                /* Added comments to prevent the violation of MISRA C-2012 rule. */
                break;
        }
    }
    else
    {
        /* To avoid MISRA rule 14.10 error. */
    }

    /* Configure the zero crossing mode. */
    if (sampleIndex < 8U)
    {
        tmp16 = base->ZXCTRL1 & (uint16_t)(~ADC_ZXCTRL_ZCE_MASK(sampleIndex));
        tmp16 |= ADC_ZXCTRL_ZCE(sampleIndex, config->zeroCrossingMode);
        base->ZXCTRL1 = tmp16;
    }
    else if (sampleIndex < 16U)
    {
        sampleIndex -= 8U;
        tmp16 = base->ZXCTRL2 & (uint16_t)(~ADC_ZXCTRL_ZCE_MASK(sampleIndex));
        tmp16 |= ADC_ZXCTRL_ZCE(sampleIndex, config->zeroCrossingMode);
        base->ZXCTRL2 = tmp16;
        sampleIndex += 8U;
    }
    else
    {
        /* To avoid MISRA rule 14.10 error. */
    }

    /* Fill the conversion channel into sample slot. */
    if (sampleIndex < 4U)
    {
        tmp16 = base->CLIST1 & (uint16_t)(~ADC_CLIST_SAMPLE_MASK(sampleIndex));
        tmp16 |= ADC_CLIST_SAMPLE(sampleIndex, config->channelNumber);
        base->CLIST1 = tmp16;
    }
    else if (sampleIndex < 8U)
    {
        sampleIndex -= 4U;
        tmp16 = base->CLIST2 & (uint16_t)(~ADC_CLIST_SAMPLE_MASK(sampleIndex));
        tmp16 |= ADC_CLIST_SAMPLE(sampleIndex, config->channelNumber);
        base->CLIST2 = tmp16;
        sampleIndex += 4U;
    }
    else if (sampleIndex < 12U)
    {
        sampleIndex -= 8U;
        tmp16 = base->CLIST3 & (uint16_t)(~ADC_CLIST_SAMPLE_MASK(sampleIndex));
        tmp16 |= ADC_CLIST_SAMPLE(sampleIndex, config->channelNumber);
        base->CLIST3 = tmp16;
        sampleIndex += 8U;
    }
    else if (sampleIndex < 16U)
    {
        sampleIndex -= 12U;
        tmp16 = base->CLIST4 & (uint16_t)(~ADC_CLIST_SAMPLE_MASK(sampleIndex));
        tmp16 |= ADC_CLIST_SAMPLE(sampleIndex, config->channelNumber);
        base->CLIST4 = tmp16;
        sampleIndex += 12U;
    }
    else
    {
        /* To avoid MISRA rule 14.10 error. */
    }

    /* Configure the hardware comapre. */
    base->LOLIM[sampleIndex] = config->lowLimitValue;
    base->HILIM[sampleIndex] = config->highLimitValue;
    base->OFFST[sampleIndex] = config->offsetValue;

    /* Configure the gain for channel. */
    if (config->channelNumber < 8U)
    {
        tmp16 = base->GC1 & (uint16_t)(~ADC_GC_GAIN_MASK(config->channelNumber));
        tmp16 |= ADC_GC_GAIN(config->channelNumber, (uint16_t)(config->channelGain));
        base->GC1 = tmp16;
    }
    else if (config->channelNumber < 16U)
    {
        tmp16 = base->GC2 & (uint16_t)(~ADC_GC_GAIN_MASK(config->channelNumber - 8U));
        tmp16 |= ADC_GC_GAIN(config->channelNumber - 8U, (uint16_t)(config->channelGain));
        base->GC2 = tmp16;
    }
    else
    {
        /* To avoid MISRA rule 14.10 error. */
    }

    /* Configure the hardware trigger. */
    /* ADC_SCTRL. */
    if (config->enableWaitSync)
    {
        base->SCTRL |= (uint16_t)(1UL << sampleIndex);
    }
    else
    {
        base->SCTRL &= ~(uint16_t)(1UL << sampleIndex);
    }
}

#if (defined(ADC_RSLT2_COUNT) && ADC_RSLT2_COUNT)
/*!
 * brief Configs the extended sample slots.
 *
 * param base CADC peripheral base address.
 * param sampleIndex Index of sample slot in conversion sequence. Available range is 16-19.
 * param config Pointer the configuration structure. Please refer to @ref cadc_extended_sample_config_t.
 */
void CADC_SetExtendedSampleConfig(ADC_Type *base, uint16_t sampleIndex, const cadc_extended_sample_config_t *config)
{
    assert(config != NULL);
    assert(sampleIndex > (ADC_RSLT_COUNT - 1U));
    assert(sampleIndex < (ADC_RSLT_COUNT + ADC_RSLT2_COUNT));

    uint16_t tmp16 = 0U;
    if ((config->channelNumber == 6U) || (config->channelNumber == 7U) || (config->channelNumber == 14U) ||
        (config->channelNumber == 15U))
    {
        if (config->selectAlternateSource)
        {
            base->CLIST5 |= (uint16_t)(ADC_CLIST5_SEL_TEMP_0_MASK << (config->channelNumber % 6U));
        }
        else
        {
            base->CLIST5 &= (uint16_t)(~(ADC_CLIST5_SEL_TEMP_0_MASK << (config->channelNumber % 6U)));
        }

        tmp16 = base->CLIST5;
        tmp16 &= (uint16_t)(~(ADC_CLIST5_SAMPLE16_MASK << (sampleIndex - ADC_RSLT_COUNT)));
        tmp16 |= (uint16_t)((config->channelNumber) % 6U << (sampleIndex - ADC_RSLT_COUNT));
        base->CLIST5 = tmp16;

        /* Config Zero crossing mode */
        tmp16 = base->ZXCTRL3;
        tmp16 &= (uint16_t)(~(ADC_ZXCTRL3_ZCE16_MASK << (2U * (sampleIndex - ADC_RSLT_COUNT))));
        tmp16 |= (uint16_t)((uint16_t)(config->zeroCrossingMode) << (2U * (sampleIndex - ADC_RSLT_COUNT)));
        base->ZXCTRL3 = tmp16;

        tmp16 = base->GC3;
        tmp16 &= (uint16_t)(~(ADC_GC3_GAIN16_MASK << (2U * (sampleIndex - ADC_RSLT_COUNT))));
        tmp16 |= (uint16_t)((uint16_t)(config->channelGain) << (2U * (sampleIndex - ADC_RSLT_COUNT)));
        base->GC3 = tmp16;

        /* Config high limit value. */
        base->HILIM2[(sampleIndex - ADC_RSLT_COUNT)] = config->highLimitValue;

        /* Config low limit value. */
        base->LOLIM2[(sampleIndex - ADC_RSLT_COUNT)] = config->lowLimitValue;

        /* Config offset value. */
        base->OFFST2[(sampleIndex - ADC_RSLT_COUNT)] = config->offsetValue;

        /* Configure the hardware trigger. */
        if (config->enableWaitSync)
        {
            base->SCTRL2 |= (uint16_t)(1UL << (sampleIndex - ADC_RSLT_COUNT));
        }
        else
        {
            base->SCTRL2 &= ~(uint16_t)(1UL << (sampleIndex - ADC_RSLT_COUNT));
        }
    }
}
#endif /* ADC_RSLT2_COUNT */
