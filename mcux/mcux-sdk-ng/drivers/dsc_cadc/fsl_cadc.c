/*
 * Copyright 2020, 2021, 2023 NXP
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
#define FSL_COMPONENT_ID "platform.drivers.dsc_cadc"
#endif

/*
 * Define the MACROs to help calculating the position of register field from sample index.
 */
/* ADC_ZXCTRL1 & ADC_ZXCTRL2. */
#define ADC_ZXCTRL_ZCE_MASK(u16SampleIndex) (uint16_t)(3UL << (2U * ((uint16_t)(u16SampleIndex))))
#define ADC_ZXCTRL_ZCE(u16SampleIndex, u16Value) \
    (uint16_t)(((uint16_t)(u16Value)) << (2U * ((uint16_t)(u16SampleIndex))))

/* ADC_CLIST1 & ADC_CLIST2 & ADC_CLIST3 & ADC_CLIST4 */
#define ADC_CLIST_SAMPLE_MASK(u16SampleIndex) (uint16_t)(0xFUL << (4U * ((uint16_t)(u16SampleIndex))))
#define ADC_CLIST_SAMPLE(u16SampleIndex, u16Value) \
    (uint16_t)(((uint16_t)(u16Value)) << (4U * ((uint16_t)(u16SampleIndex))))

/* ADC_GC1 & ADC_GC2. */
#define ADC_GC_GAIN_MASK(u16SampleIndex)      (uint16_t)(0x3UL << (2U * ((uint16_t)(u16SampleIndex))))
#define ADC_GC_GAIN(u16SampleIndex, u16Value) (uint16_t)(((uint16_t)(u16Value)) << (2U * ((uint16_t)(u16SampleIndex))))

#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
#define ZXCTRL3_ADDRESS (volatile uint16_t *)&(base->ZXCTRL3)
#else
#define ZXCTRL3_ADDRESS NULL
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
#define ADC_ZXCTRL_REG_ADDRESS_ARRAY                                                              \
    {                                                                                             \
        (volatile uint16_t *)&base->ZXCTRL1, (volatile uint16_t *)&base->ZXCTRL2, ZXCTRL3_ADDRESS \
    }

#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
#define CLIST5_ADDRESS (volatile uint16_t *)&base->CLIST5
#else
#define CLIST5_ADDRESS NULL
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
#define ADC_CLIST_REG_ADDRESS_ARRAY                                                                                 \
    {                                                                                                               \
        (volatile uint16_t *)&base->CLIST1, (volatile uint16_t *)&base->CLIST2, (volatile uint16_t *)&base->CLIST3, \
            (volatile uint16_t *)&base->CLIST4, CLIST5_ADDRESS,                                                     \
    }

#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
#define GC3_ADDRESS (volatile uint16_t *)&base->GC3
#else
#define GC3_ADDRESS NULL
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
#define GC3_REG_INDEX 2U
#define ADC_GC_REG_ADDRESS_ARRAY                                                      \
    {                                                                                 \
        (volatile uint16_t *)&base->GC1, (volatile uint16_t *)&base->GC2, GC3_ADDRESS \
    }

/*!
 * @brief The enumeration of channel mode type.
 */
typedef enum _cadc_channel_mode_type
{
    kCADC_SingleEndType = 1U,         /*!< The channel configured as Single-End mode. In this operate mode the ADC
                                          measures the voltage of the selected analog input and compare it against
                                          the reference voltage range. */
    kCADC_FullyDifferentialType = 2U, /*!< The channel configured as fully differential mode. In this operate mode
                                          the ADC measures the voltage difference between two analog inputs and
                                          compare that value against the reference voltage range. */
#if (defined(FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE) && FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE)
    kCADC_UnipolarDifferentType = 3U, /*!< The channel configured as Unipolar differential mode. In this operate
                                          mode, the conversions are only positive but uses the full code range of
                                          the ADC. */
#endif                                /* FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE */
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
    kCADC_EvenChannelAltSourceOddChannelNormal = 4U, /*!< The Even channel configured as alternate source, the Odd
                                                        channel configured as Normal single-end operate mode.  */
    kCADC_EvenChannelNormalOddChannelAltSource = 5U, /*!< The Even channel configured as Normal single-end operate mode,
                                                         the Odd channel configured as alternate source.  */
    kCADC_EvenChannelAltSourceOddChannelAltSource = 6U, /*!< The Even channel configured as alternate source,
                                                           the Odd channel configured as alternate source.  */
#endif                                                  /* FSL_FEATURE_CADC_RSLT2_COUNT */
} cadc_channel_mode_type_t;

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
 * @brief Calculates the channel index from the channel mode.
 *
 * @param eChannelMode Please refer to @ref cadc_channel_mode_t for details.
 */
static uint16_t CADC_CalculateChannelIndexViaChannelMode(cadc_channel_mode_t eChannelMode);

/*!
 * @brief Configures the converter A, such as clock divisor, reference voltage and so on.
 *
 * This function is to configure the converter A with converter configuration structure. As the control register bits
 * for converter A and B are not in the same order, the configuring functions are also implemented for each.
 *
 * @param base   CADC peripheral base address.
 * @param psConfig Pointer to configuration structure. See @ref cadc_converter_config_t.
 */
static void CADC_SetConverterAConfig(ADC_Type *base, const cadc_converter_config_t *psConfig);

/*!
 * @brief Configures the converter B, such as clock divisor, reference voltage and so on
 *
 * This function is to configure the converter B with converter configuration structure. As the control register bits
 * for converter A and B are not in the same order, the configuring functions are also implemented for each.
 *
 * @param base   CADC peripheral base address.
 * @param psConfig Pointer to configuration structure. See @ref cadc_converter_config_t.
 */
static void CADC_SetConverterBConfig(ADC_Type *base, const cadc_converter_config_t *psConfig);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to CADC bases for each instance. */
static ADC_Type *const s_cadcBases[] = ADC_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to CADC clocks for each instance. */
static const clock_ip_name_t s_cadcClocks[] = CADC_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t CADC_GetInstance(ADC_Type *base)
{
    uint32_t u32Instance;

    /* Find the instance index from base address mappings. */
    for (u32Instance = 0; u32Instance < ARRAY_SIZE(s_cadcBases); u32Instance++)
    {
        if (s_cadcBases[u32Instance] == base)
        {
            break;
        }
    }

    assert(u32Instance < ARRAY_SIZE(s_cadcBases));

    return u32Instance;
}

static void CADC_SetConverterAConfig(ADC_Type *base, const cadc_converter_config_t *psConfig)
{
    assert(NULL != psConfig);

    uint16_t u16Tmp;

    /* ADC_CTRL2. */
    u16Tmp = base->CTRL2 & ~(uint16_t)(ADC_CTRL2_DIV0_MASK);
    u16Tmp |= ADC_CTRL2_DIV0(psConfig->u16ClockDivisor);
    base->CTRL2 = u16Tmp;

    /* ADC_CAL. */
    u16Tmp = base->CAL & ~(uint16_t)(ADC_CAL_SEL_VREFH_A_MASK | ADC_CAL_SEL_VREFLO_A_MASK);
    if (kCADC_ReferenceVoltageChannelPad == psConfig->eHighReferenceVoltageSource)
    {
        u16Tmp |= ADC_CAL_SEL_VREFH_A_MASK;
    }
    if (kCADC_ReferenceVoltageChannelPad == psConfig->eLowReferenceVoltageSource)
    {
        u16Tmp |= ADC_CAL_SEL_VREFLO_A_MASK;
    }
    base->CAL = u16Tmp;

#if !(defined(FSL_FEATURE_CADC_NO_SPEEDMODE_BIT) && FSL_FEATURE_CADC_NO_SPEEDMODE_BIT)
    /* ADC_PWR2. */
    u16Tmp = base->PWR2 & ~(uint16_t)(ADC_PWR2_SPEEDA_MASK);
    u16Tmp |= ADC_PWR2_SPEEDA((uint16_t)(psConfig->eSpeedMode));
    base->PWR2 = u16Tmp;
#endif /* FSL_FEATURE_CADC_NO_SPEEDMODE_BIT */

#if !(defined(FSL_FEATURE_CADC_NO_SAMPLE_WINDOW) && FSL_FEATURE_CADC_NO_SAMPLE_WINDOW)
    /* ADC_CTRL3. */
    u16Tmp = base->CTRL3 & ~(uint16_t)(ADC_CTRL3_SCNT0_MASK);
    u16Tmp |= ADC_CTRL3_SCNT0(psConfig->u16SampleWindowCount);
    base->CTRL3 = u16Tmp;
#endif /* FSL_FEATURE_CADC_NO_SAMPLE_WINDOW */

    /* Enable/Disabled DMA of converter A. */
    if (psConfig->bEnableDMA)
    {
        base->CTRL1 |= ADC_CTRL1_DMAEN0_MASK;
    }
    else
    {
        base->CTRL1 &= ~ADC_CTRL1_DMAEN0_MASK;
    }

    if (psConfig->bScanInitBySync)
    {
        base->CTRL1 |= ADC_CTRL1_SYNC0_MASK;
    }
    else
    {
        base->CTRL1 &= ~ADC_CTRL1_SYNC0_MASK;
    }

    /* Power up/down the converter. */
    CADC_EnableConverterPower(base, kCADC_ConverterA, psConfig->bPowerUp);
    CADC_EnableConverter(base, kCADC_ConverterA, psConfig->bPowerUp);
}

static void CADC_SetConverterBConfig(ADC_Type *base, const cadc_converter_config_t *psConfig)
{
    assert(NULL != psConfig);

    uint16_t u16Tmp;

    /* ADC_CAL. */
    u16Tmp = base->CAL & ~(uint16_t)(ADC_CAL_SEL_VREFH_B_MASK | ADC_CAL_SEL_VREFLO_B_MASK);
    if (kCADC_ReferenceVoltageChannelPad == psConfig->eHighReferenceVoltageSource)
    {
        u16Tmp |= ADC_CAL_SEL_VREFH_B_MASK;
    }
    if (kCADC_ReferenceVoltageChannelPad == psConfig->eLowReferenceVoltageSource)
    {
        u16Tmp |= ADC_CAL_SEL_VREFLO_B_MASK;
    }
    base->CAL = u16Tmp;

#if !(defined(FSL_FEATURE_CADC_NO_SPEEDMODE_BIT) && FSL_FEATURE_CADC_NO_SPEEDMODE_BIT)
    /* ADC_PWR2. */
    u16Tmp = base->PWR2 & ~(uint16_t)(ADC_PWR2_DIV1_MASK | ADC_PWR2_SPEEDB_MASK);
    u16Tmp |= ADC_PWR2_DIV1(psConfig->u16ClockDivisor) | ADC_PWR2_SPEEDB((uint16_t)(psConfig->eSpeedMode));
    base->PWR2 = u16Tmp;
#else
    u16Tmp = base->PWR2 & (~ADC_PWR2_DIV1_MASK);
    u16Tmp |= ADC_PWR2_DIV1(psConfig->u16ClockDivisor);
    base->PWR2 = u16Tmp;
#endif /* FSL_FEATURE_CADC_NO_SPEEDMODE_BIT */

#if !(defined(FSL_FEATURE_CADC_NO_SAMPLE_WINDOW) && FSL_FEATURE_CADC_NO_SAMPLE_WINDOW)
    /* ADC_CTRL3. */
    u16Tmp = base->CTRL3 & ~(uint16_t)(ADC_CTRL3_SCNT1_MASK);
    u16Tmp |= ADC_CTRL3_SCNT1(psConfig->u16SampleWindowCount);
    base->CTRL3 = u16Tmp;
#endif /* FSL_FEATURE_CADC_NO_SAMPLE_WINDOW */

    if (psConfig->bEnableDMA)
    {
        base->CTRL2 |= ADC_CTRL2_DMAEN1_MASK;
    }
    else
    {
        base->CTRL2 &= ~(uint16_t)ADC_CTRL2_DMAEN1_MASK;
    }

    if (psConfig->bScanInitBySync)
    {
        base->CTRL2 |= ADC_CTRL2_SYNC1_MASK;
    }
    else
    {
        base->CTRL2 &= (uint16_t)~ADC_CTRL2_SYNC1_MASK;
    }

    /* Power up/down the converter. */
    CADC_EnableConverterPower(base, kCADC_ConverterB, psConfig->bPowerUp);
    CADC_EnableConverter(base, kCADC_ConverterB, psConfig->bPowerUp);
}

static uint16_t CADC_CalculateChannelIndexViaChannelMode(cadc_channel_mode_t eChannelMode)
{
    uint16_t u16Index           = 0U;
    uint32_t u32TempChannelMode = (uint32_t)eChannelMode;

    /* Gets the channel's offset */
    while (0UL == (u32TempChannelMode & 0x07UL))
    {
        u16Index += 3U;
        u32TempChannelMode >>= 3U;
    }

    return u16Index;
}

/*!
 * brief Initializes the CADC module, such as scan mode, DMA trigger source, interrupt mask and so on.
 *
 * This function is to make the initialization for using CADC module.
 * The operations are:
 *  - Enable the clock for CADC.
 *  - Set power up delay and Idle work mode.
 *  - Set DMA trigger source.
 *  - Enable the interrupts(Including High/Low limit interrupt, zero crossing interrupt interrupt, end of scan interrupt
 *    and each sample slot's scan interrupt).
 *  - Set scan mode.
 *  - Set disabled sample slot for the scan.
 *  - Set scan control options.
 *  - Set selected channels' mode.
 *  - Set gain for each channel.
 *  - Config conterA and converterB.
 *
 * param base   CADC peripheral base address.
 * param psConfig Pointer to configuration structure. See @ref cadc_config_t.
 */
void CADC_Init(ADC_Type *base, const cadc_config_t *psConfig)
{
    assert(psConfig != NULL);

    uint16_t u16Tmp;
    uint8_t u8Index;
    uint32_t u32Tmp;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enables Clock. */
    CLOCK_EnableClock(s_cadcClocks[CADC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* 1. Sets Common options. */
    /*1.1 Sets power up delay and Idle work mode.  */
#if !(defined(FSL_FEATURE_CADC_NO_AUTO_STANDBY) && FSL_FEATURE_CADC_NO_AUTO_STANDBY)
    /* ADC_PWR. */
    u16Tmp = (uint16_t)(base->PWR & ~(ADC_PWR_ASB_MASK | ADC_PWR_PUDELAY_MASK | ADC_PWR_APD_MASK));
#else
    u16Tmp     = (uint16_t)(base->PWR & ~(ADC_PWR_PUDELAY_MASK | ADC_PWR_APD_MASK));
#endif /* FSL_FEATURE_CADC_NO_AUTO_STANDBY */

    u16Tmp |= ADC_PWR_PUDELAY(psConfig->u16PowerUpDelay);
#if !(defined(FSL_FEATURE_CADC_NO_AUTO_STANDBY) && FSL_FEATURE_CADC_NO_AUTO_STANDBY)
    if (kCADC_IdleAutoStandby == psConfig->eIdleWorkMode)
    {
        u16Tmp |= ADC_PWR_ASB_MASK;
    }
    else if (kCADC_IdleAutoPowerDown == psConfig->eIdleWorkMode)
#else
    if (kCADC_IdleAutoPowerDown == psConfig->eIdleWorkMode)
#endif /* FSL_FEATURE_CADC_NO_AUTO_STANDBY */
    {
        u16Tmp |= ADC_PWR_APD_MASK;
    }
    else
    {
        /* To avoid MISRA rule 14.10 error. */
    }
    base->PWR = u16Tmp;
    /* 1.2 Configs DMA Trigger Source. */
    if (kCADC_DMATrigSrcSampleReady == psConfig->eDMATriggerSource)
    {
        base->CTRL3 |= ADC_CTRL3_DMASRC_MASK;
    }
    else /* kCADCDmaTriggerSourceAsEndOfScan. */
    {
        base->CTRL3 &= ~(uint16_t)ADC_CTRL3_DMASRC_MASK;
    }
    /* 1.3 Enables the interrupts. */
    CADC_EnableInterrupts(base, psConfig->u32EnabledInterruptMask);

    /* 2. Configs Scan related options. */
    /* 2.1 Sets current Scan mode. */
    CADC_SetScanMode(base, psConfig->eScanMode);
    /* 2.2 Sets disabled sample slot for the scan. */
    if ((psConfig->eScanMode == kCADC_ScanModeOnceParallelIndependent) ||
        (psConfig->eScanMode == kCADC_ScanModeLoopParallelIndependent) ||
        (psConfig->eScanMode == kCADC_ScanModeTriggeredParallelIndependent))
    {
        base->SDIS =
            (uint16_t)((psConfig->uDisabledSampleSlot.u32SampleDisVal & 0xFFU) |
                       (uint16_t)((uint32_t)(psConfig->uDisabledSampleSlot.u32SampleDisVal & 0xFF0000UL) >> 8UL));
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
        base->SDIS2 = ((uint16_t)((psConfig->uDisabledSampleSlot.u32SampleDisVal & 0x300UL) >> 8UL) |
                       (uint16_t)((psConfig->uDisabledSampleSlot.u32SampleDisVal & 0xC000000UL) >> 24UL));
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
    }
    else
    {
        base->SDIS = (uint16_t)(psConfig->uDisabledSampleSlot.u32SampleDisVal & 0xFFFFUL);
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
        base->SDIS2 = (uint16_t)((psConfig->uDisabledSampleSlot.u32SampleDisVal & 0xF0000UL) >> 16UL);
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
    }
    /* 2.3 Sets which samples will delay until a new sync input occurs. */
    CADC_SetScanControl(base, psConfig->uScanControl);

    /* 3. Configs Channel related options. */
    for (u8Index = 0U; u8Index < 8U; u8Index++)
    {
        u32Tmp = (uint32_t)((psConfig->u32ChannelModeMask) & (0x7UL << (3UL * (uint32_t)u8Index)));
        if (u32Tmp != 0UL)
        {
            CADC_SetChannelMode(base, (cadc_channel_mode_t)(u32Tmp));
        }
    }
    for (u8Index = 0U; u8Index < CADC_SAMPLE_SLOTS_COUNT; u8Index++)
    {
        CADC_SetChannelGain(base, (cadc_channel_number_t)u8Index, psConfig->eChannelGain[u8Index]);
        CADC_RouteChannelToSampleSlot(base, (cadc_sample_slot_index_t)u8Index, psConfig->eSampleSlot[u8Index]);
    }

    /* 4. Configs conveters related options. */
    CADC_SetConverterConfig(base, kCADC_ConverterA, &(psConfig->sConverterA));
    CADC_SetConverterConfig(base, kCADC_ConverterB, &(psConfig->sConverterB));
}

/*!
 * brief Gets an available pre-defined options(such as scan mode, DMA trigger source, interrupt mask and so on) for
 * module's configuration.
 *
 * This function initializes the module's configuration structure with an available settings.
 * The default value are:
 * code
 *   psConfig->eDMATriggerSource = kCADC_DMATrigSrcEndofScan;
 *   psConfig->eIdleWorkMode = kCADC_IdleKeepNormal;
 *   psConfig->u16PowerUpDelay = 26U;
 *   psConfig->u32EnabledInterruptMask = 0U;
 *   psConfig->eScanMode = kCADC_ScanModeTriggeredParallelSimultaneous;
 *   psConfig->uDisabledSampleSlot.u32SampleDisVal = 0xFF0F0UL;
 *   psConfig->uScanControl.u32ScanCtrlVal         = 0x0UL;
 *   psConfig->eChannelGain[x] = kCADC_SignalGainX1;
 *   psConfig->sampleSlotScanInterruptEnableMask = kCADC_NonSampleSlotMask;
 *   For the default setting of converter, please see CADC_GetConverterDefaultConfig().
 * endcode
 *
 * param psConfig Pointer to configuration structure. See @ref cadc_config_t.
 */
void CADC_GetDefaultConfig(cadc_config_t *psConfig)
{
    assert(NULL != psConfig);

    /* Initializes the configure structure to zero. */
    (void)memset(psConfig, 0, sizeof(*psConfig));

    psConfig->eIdleWorkMode           = kCADC_IdleKeepNormal;
    psConfig->eDMATriggerSource       = kCADC_DMATrigSrcEndofScan;
    psConfig->u16PowerUpDelay         = 26U;
    psConfig->u32EnabledInterruptMask = 0UL; /* Do not enable any interrupts. */

    /* Scan related options. */
    psConfig->eScanMode                           = kCADC_ScanModeTriggeredParallelSimultaneous;
    psConfig->uDisabledSampleSlot.u32SampleDisVal = 0xFF0F0UL;
    psConfig->uScanControl.u32ScanCtrlVal         = 0x0UL;

    /* Channel related options. */
    psConfig->u32ChannelModeMask =
        ((uint32_t)kCADC_ANA0_1_SingleEnd | (uint32_t)kCADC_ANA2_3_SingleEnd | (uint32_t)kCADC_ANA4_5_SingleEnd |
         (uint32_t)kCADC_ANA6_7_SingleEnd | (uint32_t)kCADC_ANB0_1_SingleEnd | (uint32_t)kCADC_ANB2_3_SingleEnd |
         (uint32_t)kCADC_ANB4_5_SingleEnd | (uint32_t)kCADC_ANB6_7_SingleEnd);
    for (uint8_t u8Index = 0U; u8Index < CADC_SAMPLE_SLOTS_COUNT; u8Index++)
    {
        psConfig->eChannelGain[u8Index] = kCADC_SignalGainX1;
        psConfig->eSampleSlot[u8Index]  = (cadc_channel_number_t)u8Index;
    }

    /* Converters related options. */
    CADC_GetConverterDefaultConfig(&(psConfig->sConverterA));
    CADC_GetConverterDefaultConfig(&(psConfig->sConverterB));
}

/*!
 * brief De-initializes the CADC module, including power down both converter and disable the clock(Optional).
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
    CADC_EnableConverter(base, kCADC_ConverterA, false);
    CADC_EnableConverter(base, kCADC_ConverterB, false);

    /* Power done both converter. */
    CADC_EnableConverterPower(base, kCADC_ConverterA, false);
    CADC_EnableConverterPower(base, kCADC_ConverterB, false);
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(s_cadcClocks[CADC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Sets mode for the specific channel(Each channel can be set as single-end, fully differential and unipolar
 * differential(Optional) mode).
 *
 * param base CADC peripheral base address.
 * param eChannelMode The channel mode to be set, please refer to @ref cadc_channel_mode_t for details.
 */
void CADC_SetChannelMode(ADC_Type *base, cadc_channel_mode_t eChannelMode)
{
    uint16_t u16ChannelIndex  = 0U;
    uint16_t u16ChannelOffset = 0U;
    uint8_t u8CtrlRegIndex    = 0U;

    /* Gets the index from channel mode */
    u16ChannelIndex = CADC_CalculateChannelIndexViaChannelMode(eChannelMode);

    /* Gets the offset of the specific channel in the Channel configure bit field */
    u16ChannelOffset = ((uint16_t)1U << (u16ChannelIndex / 3UL));
    u8CtrlRegIndex   = (u16ChannelOffset > 8U) ? 1U : 0U;

    switch ((uint32_t)eChannelMode >> u16ChannelIndex)
    {
        case (uint32_t)kCADC_SingleEndType:
        {
            if (u8CtrlRegIndex == 0U)
            {
                base->CTRL1 &= ~ADC_CTRL1_CHNCFG_L(u16ChannelOffset & 0xFU);
            }
            else
            {
                base->CTRL2 &= ~ADC_CTRL2_CHNCFG_H((u16ChannelOffset & 0xF0U) >> 4U);
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
                if (eChannelMode == kCADC_ANA6_7_SingleEnd)
                {
                    base->CLIST5 &= ~(ADC_CLIST5_SEL_TEMP_0_MASK | ADC_CLIST5_SEL_INTERNAL_0_MASK);
                }
                else if (eChannelMode == kCADC_ANB6_7_SingleEnd)
                {
                    base->CLIST5 &= ~(ADC_CLIST5_SEL_TEMP_1_MASK | ADC_CLIST5_SEL_INTERNAL_1_MASK);
                }
                else
                {
                    /* For MISRA C-2012 15.7 */
                }
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
            }
            break;
        }
        case (uint32_t)kCADC_FullyDifferentialType:
        {
            if (u8CtrlRegIndex == 0U)
            {
                base->CTRL1 |= ADC_CTRL1_CHNCFG_L(u16ChannelOffset & 0xFU);
#if (defined(FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE) && FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE)
                base->CTRL3 &= ~ADC_CTRL3_UPDEN_L(u16ChannelOffset & 0xFU);
#endif /* FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE */
            }
            else
            {
                base->CTRL2 |= ADC_CTRL2_CHNCFG_H((u16ChannelOffset & 0xF0U) >> 4U);
#if (defined(FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE) && FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE)
                base->CTRL3 &= ~ADC_CTRL3_UPDEN_H((u16ChannelOffset & 0xF0U) >> 4U);
#endif /* FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE */
            }
            break;
        }
#if (defined(FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE) && FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE)
        case (uint32_t)kCADC_UnipolarDifferentType:
        {
            if (u8CtrlRegIndex == 0U)
            {
                base->CTRL1 |= ADC_CTRL1_CHNCFG_L(u16ChannelOffset & 0xFU);
                base->CTRL3 |= ADC_CTRL3_UPDEN_L(u16ChannelOffset & 0xFU);
            }
            else
            {
                base->CTRL2 |= ADC_CTRL2_CHNCFG_H((u16ChannelOffset & 0xF0U) >> 4U);
                base->CTRL3 |= ADC_CTRL3_UPDEN_H((u16ChannelOffset & 0xF0U) >> 4U);
            }
            break;
        }
#endif /* FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE */
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
        case (uint32_t)kCADC_EvenChannelAltSourceOddChannelNormal:
        {
            base->CTRL2 &= ~ADC_CTRL2_CHNCFG_H((u16ChannelOffset & 0xF0U) >> 4U);
            if (eChannelMode == kCADC_ANA6_InternalTempSensor_ANA7_Normal)
            {
                base->CLIST5 |= ADC_CLIST5_SEL_TEMP_0_MASK;
                base->CLIST5 &= ~ADC_CLIST5_SEL_INTERNAL_0_MASK;
            }
            else if (eChannelMode == kCADC_ANB6_InternalTempSensor_ANB7_Normal)
            {
                base->CLIST5 |= ADC_CLIST5_SEL_TEMP_1_MASK;
                base->CLIST5 &= ~ADC_CLIST5_SEL_INTERNAL_1_MASK;
            }
            else
            {
                /* For MISRA C-2012 15.7 */
            }
            break;
        }
        case (uint32_t)kCADC_EvenChannelNormalOddChannelAltSource:
        {
            base->CTRL2 &= ~ADC_CTRL2_CHNCFG_H((u16ChannelOffset & 0xF0U) >> 4U);
            if (eChannelMode == kCADC_ANA6_Normal_ANA7_InternalAnalogInput)
            {
                base->CLIST5 |= ADC_CLIST5_SEL_INTERNAL_0_MASK;
                base->CLIST5 &= ~ADC_CLIST5_SEL_TEMP_0_MASK;
            }
            else if (eChannelMode == kCADC_ANB6_Normal_ANB7_InternalAnalogInput)
            {
                base->CLIST5 |= ADC_CLIST5_SEL_INTERNAL_1_MASK;
                base->CLIST5 &= ~ADC_CLIST5_SEL_TEMP_1_MASK;
            }
            else
            {
                /* For MISRA C-2012 15.7 */
            }
            break;
        }
        case (uint32_t)kCADC_EvenChannelAltSourceOddChannelAltSource:
        {
            base->CTRL2 &= ~ADC_CTRL2_CHNCFG_H((u16ChannelOffset & 0xF0U) >> 4U);
            if (eChannelMode == kCADC_ANA6_InternalTempSensor_ANA7_InternalAnalogInput)
            {
                base->CLIST5 |= ADC_CLIST5_SEL_INTERNAL_0_MASK;
                base->CLIST5 |= ADC_CLIST5_SEL_TEMP_0_MASK;
            }
            else if (eChannelMode == kCADC_ANB6_InternalTempSensor_ANB7_InternalAnalogInput)
            {
                base->CLIST5 |= ADC_CLIST5_SEL_INTERNAL_1_MASK;
                base->CLIST5 |= ADC_CLIST5_SEL_TEMP_1_MASK;
            }
            else
            {
                /* For MISRA C-2012 15.7 */
            }
            break;
        }
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
        default:
        {
            /* This branch should never be hit. */
            break;
        }
    }
}

/*!
 * brief Sets the gain(Supports X1, X2, X4) of selected channel.
 *
 * param base CADC peripheral base address.
 * param eChannelNumber The number of channel, please refer to @ref cadc_channel_number_t.
 * param eChannelGain The gain amplification, please refer to @ref cadc_channel_gain_t for details.
 */
void CADC_SetChannelGain(ADC_Type *base, cadc_channel_number_t eChannelNumber, cadc_channel_gain_t eChannelGain)
{
    volatile uint16_t *pGcRegAddrArray[] = ADC_GC_REG_ADDRESS_ARRAY;
    uint16_t u16Tmp                      = 0U;
    volatile uint16_t *pGcRegPtr         = NULL;

    pGcRegPtr = pGcRegAddrArray[(uint16_t)eChannelNumber / 8U];
    if (pGcRegPtr != NULL)
    {
        u16Tmp = (*pGcRegPtr) & (uint16_t)(~ADC_GC_GAIN_MASK((uint16_t)eChannelNumber & 7U));
        u16Tmp |= ADC_GC_GAIN((uint16_t)eChannelNumber & 7U, (uint16_t)eChannelGain);
        (*pGcRegPtr) = u16Tmp;
    }
}

/*!
 * brief Gets sample slot default configuration including zero crossing mode, high limit value, low limit value and
 * offset value.
 *
 * code
 *      psConfig->eZeroCrossingMode = kCADC_ZeroCrossingDisabled;
 *      psConfig->u16HighLimitValue  = 0x7FF8U;
 *      psConfig->u16LowLimitValue   = 0x0U;
 *      psConfig->u16OffsetValue     = 0x0U;
 * endcode
 *
 * param psConfig      Pointer to configuration structure. See @ref cadc_sample_slot_config_t.
 */
void CADC_GetSampleSlotDefaultConfig(cadc_sample_slot_config_t *psConfig)
{
    assert(psConfig != NULL);

    psConfig->eZeroCrossingMode = kCADC_ZeroCrossingDisabled;
    psConfig->u16HighLimitValue = 0x7FF8U;
    psConfig->u16LowLimitValue  = 0x0U;
    psConfig->u16OffsetValue    = 0x0U;
}

/*!
 * brief Configures the options(including zero crossing mode, high limit value, low limit value and offset value) for
 * sample slot.
 *
 * note This function can be used to set high limit value, low limit value,
 * offset value and zerocrossing mode of the sample slot.
 *
 * param base        CADC peripheral base address.
 * param eSampleIndex Index of sample slot in conversion sequence. Please refer to @ref cadc_sample_slot_index_t.
 * param psConfig      Pointer to configuration structure. See @ref cadc_sample_slot_config_t.
 */
void CADC_SetSampleSlotConfig(ADC_Type *base,
                              cadc_sample_slot_index_t eSampleIndex,
                              const cadc_sample_slot_config_t *psConfig)
{
    assert(NULL != psConfig);

    /* Sets the zero crossing mode for the selected sample slot. */
    CADC_SetSampleSlotZeroCrossingMode(base, eSampleIndex, psConfig->eZeroCrossingMode);

    /* Set limit value and offset value for the selected sample slot. */
    CADC_SetSampleSlotLowLimitValue(base, eSampleIndex, psConfig->u16LowLimitValue);
    CADC_SetSampleSlotHighLimitValue(base, eSampleIndex, psConfig->u16HighLimitValue);
    CADC_SetSampleSlotOffsetValue(base, eSampleIndex, psConfig->u16OffsetValue);
}

/*!
 * brief Sets zero crossing mode for each sample slot.
 *
 * param base CADC peripheral base address.
 * param eSampleIndex The index of sample slot.
 * param eZeroCrossingMode Zero crossing mode, please refer to @ref cadc_sample_slot_zero_crossing_mode_t for details.
 */
void CADC_SetSampleSlotZeroCrossingMode(ADC_Type *base,
                                        cadc_sample_slot_index_t eSampleIndex,
                                        cadc_sample_slot_zero_crossing_mode_t eZeroCrossingMode)
{
    uint16_t u16Tmp                          = 0U;
    volatile uint16_t *pZxctrlRegAddrArray[] = ADC_ZXCTRL_REG_ADDRESS_ARRAY;
    volatile uint16_t *pZxctrlRegPtr         = NULL;

    pZxctrlRegPtr = pZxctrlRegAddrArray[(uint16_t)eSampleIndex / 8U];
    if (pZxctrlRegPtr != NULL)
    {
        u16Tmp = (*pZxctrlRegPtr) & (uint16_t)(~ADC_ZXCTRL_ZCE_MASK((uint16_t)eSampleIndex & 7U));
        u16Tmp |= ADC_ZXCTRL_ZCE((uint16_t)eSampleIndex & 7U, eZeroCrossingMode);
        (*pZxctrlRegPtr) = u16Tmp;
    }
}

/*!
 * brief Routes the channel to the sample slot.
 *
 * param base CADC peripheral base address.
 * param eSampleIndex The index of sample slot. Please refer to @ref cadc_sample_slot_index_t for details.
 * param eChannelNumber Sample signal number, please refer to @ref cadc_channel_number_t for details.
 */
void CADC_RouteChannelToSampleSlot(ADC_Type *base,
                                   cadc_sample_slot_index_t eSampleIndex,
                                   cadc_channel_number_t eChannelNumber)
{
    volatile uint16_t *clistRegAddrArray[] = ADC_CLIST_REG_ADDRESS_ARRAY;
    volatile uint16_t *clistRegPtr         = NULL;
    uint16_t u16Tmp                        = 0U;

    /* Gets clist register address based on sampleIndex */
    clistRegPtr = clistRegAddrArray[(uint16_t)eSampleIndex / 4U];

    if (clistRegPtr != NULL)
    {
#if (defined(FSL_FEATURE_CADC_RSLT2_COUNT) && (FSL_FEATURE_CADC_RSLT2_COUNT == 4U))
        if (clistRegPtr == CLIST5_ADDRESS)
        {
            assert(eChannelNumber > kCADC_SingleEndANB7_DiffANB6pANB7n);
            u16Tmp = (*clistRegPtr) &
                     (uint16_t)(~((uint16_t)ADC_CLIST5_SAMPLE16_MASK << (2U * ((uint16_t)eSampleIndex & 7U))));
            u16Tmp |=
                (uint16_t)(((uint16_t)eChannelNumber & (ADC_RSLT_COUNT - 1U)) << (2U * ((uint16_t)eSampleIndex & 7U)));
            (*clistRegPtr) = u16Tmp;
        }
        else
#endif /* FSL_FEATURE_CADC_RSLT2_COUNT */
        {
            if (eChannelNumber <= kCADC_SingleEndANB7_DiffANB6pANB7n)
            {
                u16Tmp = (*clistRegPtr) & (uint16_t)(~ADC_CLIST_SAMPLE_MASK((uint16_t)eSampleIndex & 3U));
                u16Tmp |= ADC_CLIST_SAMPLE((uint16_t)eSampleIndex & 3U, eChannelNumber);
                (*clistRegPtr) = u16Tmp;
            }
        }
    }
}

/*!
 * brief Configures the options(such as clock divisor, reference voltage source, and so on) of the converter.
 *
 * This function can be used to configure the converter
 * The operations are:
 *  - Set clock divisor;
 *  - Set reference voltage source
 *  - Enable/Disable DMA
 *  - Power-up/power-down converter
 *
 * param base          CADC peripheral base address.
 * param eConverterId The converter Id. See @ref cadc_converter_id_t.
 * param psConfig        Pointer to configuration structure. See @ref cadc_converter_config_t.
 */
void CADC_SetConverterConfig(ADC_Type *base, cadc_converter_id_t eConverterId, const cadc_converter_config_t *psConfig)
{
    assert(NULL != psConfig);

    /* For converter A. */
    if (kCADC_ConverterA == eConverterId)
    {
        CADC_SetConverterAConfig(base, psConfig);
    }
    /* For converter B. */
    else if (kCADC_ConverterB == eConverterId)
    {
        CADC_SetConverterBConfig(base, psConfig);
    }
    else
    {
        /* For MISRA C-2012 15.7 */
    }
#if (defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX)
    CADC_SetConverterMuxAuxConfig(base, eConverterId, &(psConfig->muxAuxConfig));
#endif /* defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX */
}

/*!
 * brief Gets available pre-defined settings(such as clock divisor, reference voltage source, and so on) for each
 * converter's configuration.
 *
 * This function initializes each converter's configuration structure with an available settings.
 * The default value are:
 * code
 *   psConfig->u16ClockDivisor = 4U; (ADC clock = Peripheral clock / 5)
 *   psConfig->eSpeedMode = kCADC_SpeedMode0; (Chip specific)
 *   psConfig->eHighReferenceVoltageSource = kCADC_ReferenceVoltageVrefPad;
 *   psConfig->eLowReferenceVoltageSource = kCADC_ReferenceVoltageVrefPad;
 *   psConfig->u16SampleWindowCount = 0U; (Chip specific)
 *   psConfig->bEnableDMA         = false;
 *   psConfig->bPowerUp   = false;
 *   psConfig->bScanInitBySync  = true;
 * endcode
 * param psConfig Pointer to configuration structure. See @ref cadc_converter_config_t.
 */
void CADC_GetConverterDefaultConfig(cadc_converter_config_t *psConfig)
{
    assert(NULL != psConfig);

    /* Initializes the configure structure to zero. */
    (void)memset(psConfig, 0, sizeof(*psConfig));

    /* The default values are from power up reset state. */
    psConfig->u16ClockDivisor = 4U;
#if !(defined(FSL_FEATURE_CADC_NO_SPEEDMODE_BIT) && FSL_FEATURE_CADC_NO_SPEEDMODE_BIT)
    psConfig->eSpeedMode = kCADC_SpeedMode0;
#endif /* FSL_FEATURE_CADC_NO_SPEEDMODE_BIT */
    psConfig->eHighReferenceVoltageSource = kCADC_ReferenceVoltageVrefPad;
    psConfig->eLowReferenceVoltageSource  = kCADC_ReferenceVoltageVrefPad;
#if !(defined(FSL_FEATURE_CADC_NO_SAMPLE_WINDOW) && FSL_FEATURE_CADC_NO_SAMPLE_WINDOW)
    psConfig->u16SampleWindowCount = 0U;
#endif /* FSL_FEATURE_CADC_NO_SAMPLE_WINDOW */
    psConfig->bEnableDMA      = false;
    psConfig->bPowerUp        = false;
    psConfig->bScanInitBySync = true;

#if (defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX)
    psConfig->muxAuxConfig.expMuxOperateMode = kCADC_ExpMuxManualMode;
    psConfig->muxAuxConfig.u16AuxControl     = 0x0U;
#if !(defined(FSL_FEATURE_CADC_HAS_EXP_MUX_SEL) && (FSL_FEATURE_CADC_HAS_EXP_MUX_SEL == 0))
    psConfig->muxAuxConfig.u32MuxChannelMask = 0x0UL;
#endif /* FSL_FEATURE_CADC_HAS_EXP_MUX_SEL */
    psConfig->muxAuxConfig.disabledMuxSlot = kCADC_ExpaMuxNoDisable;
#endif /* (defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) */
}

/*!
 * brief Sets converter's reference voltage source(Including high reference voltage source and low reference voltage
 * source).
 *
 * param base CADC peripheral base address.
 * param eConverterId The converter Id. See @ref cadc_converter_id_t.
 * param eHighReferenceVoltage High voltage reference source, please refer to @ref cadc_reference_voltage_source_t.
 * param eLowReferenceVoltage  Low voltage reference source, please refer to @ref cadc_reference_voltage_source_t.
 */
void CADC_SetConverterReferenceVoltageSource(ADC_Type *base,
                                             cadc_converter_id_t eConverterId,
                                             cadc_reference_voltage_source_t eHighReferenceVoltage,
                                             cadc_reference_voltage_source_t eLowReferenceVoltage)
{
    uint16_t u16Tmp;

    /* For converter A. */
    if (kCADC_ConverterA == eConverterId)
    {
        u16Tmp = base->CAL & ~(uint16_t)(ADC_CAL_SEL_VREFH_A_MASK | ADC_CAL_SEL_VREFLO_A_MASK);
        if (kCADC_ReferenceVoltageChannelPad == eHighReferenceVoltage)
        {
            u16Tmp |= ADC_CAL_SEL_VREFH_A_MASK;
        }
        if (kCADC_ReferenceVoltageChannelPad == eLowReferenceVoltage)
        {
            u16Tmp |= ADC_CAL_SEL_VREFLO_A_MASK;
        }
        base->CAL = u16Tmp;
    }
    /* For converter B. */
    else if (kCADC_ConverterB == eConverterId)
    {
        u16Tmp = base->CAL & ~(uint16_t)(ADC_CAL_SEL_VREFH_B_MASK | ADC_CAL_SEL_VREFLO_B_MASK);
        if (kCADC_ReferenceVoltageChannelPad == eHighReferenceVoltage)
        {
            u16Tmp |= ADC_CAL_SEL_VREFH_B_MASK;
        }
        if (kCADC_ReferenceVoltageChannelPad == eLowReferenceVoltage)
        {
            u16Tmp |= ADC_CAL_SEL_VREFLO_B_MASK;
        }
        base->CAL = u16Tmp;
    }
    else
    {
        /* For MISRA C-2012 15.7 */
    }
}

/*!
 * brief Powers up/down the specific converter.
 *
 * This function is to enable the power for the converter. The converter should be powered up before the conversion.
 * Once this API is called to power up the converter, the converter would be powered on after a few moment (so-called
 * power up delay, the function CADC_SetPowerUpDelay() can be used to set the power up delay), so that the power would
 * be stable.
 *
 * param base          CADC peripheral base address.
 * param eConverterId The converter to be powered. See @ref cadc_converter_id_t.
 * param bEnable       Powers up/down the converter.
 *                      - \b true Power up the specific converter.
 *                      - \b false Power down the specific converter.
 */
void CADC_EnableConverterPower(ADC_Type *base, cadc_converter_id_t eConverterId, bool bEnable)
{
    /* For converter A. */
    if (kCADC_ConverterA == eConverterId)
    {
        if (bEnable)
        {
            base->PWR &= ~(uint16_t)ADC_PWR_PD0_MASK; /* Clear PowerDown to enable. */
            if ((base->PWR & ADC_PWR_APD_MASK) == 0U)
            {
                while ((base->PWR & ADC_PWR_PSTS0_MASK) != 0U)
                {
                }
            }
        }
        else
        {
            base->PWR |= ADC_PWR_PD0_MASK;
        }
    }
    /* For converter B. */
    else if (kCADC_ConverterB == eConverterId)
    {
        if (bEnable)
        {
            base->PWR &= ~(uint16_t)ADC_PWR_PD1_MASK; /* Clear PowerDown to enable. */
            if ((base->PWR & ADC_PWR_APD_MASK) == 0U)
            {
                while ((base->PWR & ADC_PWR_PSTS1_MASK) != 0U)
                {
                }
            }
        }
        else
        {
            base->PWR |= ADC_PWR_PD1_MASK;
        }
    }
    else
    {
        /* For MISRA C-2012 15.7 */
    }
}

#if (defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX)
/*!
 * brief Configures selected converter's expansion mux and aux settings.
 *
 * param base ADC peripheral base address.
 * param eConverterId The converter id. See cadc_converter_id_t.
 * param psMuxAuxConfig Pointer to cadc_exp_mux_aux_config_t structure.
 */
void CADC_SetConverterMuxAuxConfig(ADC_Type *base,
                                   cadc_converter_id_t eConverterId,
                                   const cadc_exp_mux_aux_config_t *psMuxAuxConfig)
{
    assert(psMuxAuxConfig != NULL);

    uint32_t u32Tmp = 0U;

    /* Reset scan. */
    CADC_ResetConverterExpMuxScan(base, eConverterId);

    CADC_SetConverterExpansionMuxOperateMode(base, eConverterId, psMuxAuxConfig->expMuxOperateMode);
    CADC_SetConverterAuxiliaryControl(base, eConverterId, psMuxAuxConfig->u16AuxControl);

    if (psMuxAuxConfig->disabledMuxSlot != kCADC_ExpaMuxNoDisable)
    {
        u32Tmp = (1UL << ((uint16_t)(psMuxAuxConfig->disabledMuxSlot)));
    }
    else
    {
        u32Tmp = (uint32_t)(psMuxAuxConfig->disabledMuxSlot);
    }

#if !(defined(FSL_FEATURE_CADC_HAS_EXP_MUX_SEL) && (FSL_FEATURE_CADC_HAS_EXP_MUX_SEL == 0))
    u32Tmp |= (psMuxAuxConfig->u32MuxChannelMask);
#endif /* FSL_FEATURE_CADC_HAS_EXP_MUX_SEL */

    if (eConverterId == kCADC_ConverterA)
    {
        base->EXPMUX4A0 = (uint16_t)(u32Tmp & 0xFFFFU);
        base->EXPMUX4A1 = (uint16_t)((u32Tmp >> 16U) & 0xFFFFU);
    }
    else
    {
        base->EXPMUX4B0 = (uint16_t)(u32Tmp & 0xFFFFU);
        base->EXPMUX4B1 = (uint16_t)((u32Tmp >> 16U) & 0xFFFFU);
    }
}
#endif /* defined(FSL_FEATURE_CADC_HAS_EXP_MUX_AUX) && FSL_FEATURE_CADC_HAS_EXP_MUX_AUX */
