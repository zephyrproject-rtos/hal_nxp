/*
 * Copyright 2023-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_sar_adc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.sar_adc"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to ADC bases for each instance. */
static ADC_Type *s_adcBases[] = ADC_BASE_PTRS;

/*! @brief Pointers to ADC clocks for each instance. */
static const clock_ip_name_t s_adcClocks[] = ADC_CLOCKS;
#endif /* !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) */

static adc_clock_frequency_t adcClockFreq;

/*******************************************************************************
 * Code
 ******************************************************************************/
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*!
 * brief This function is used to get the ADC instance.
 *
 * param base ADC peripheral base address.
 *
 * return ADC instance.
 */
static uint32_t ADC_GetInstance(ADC_Type *base)
{
    uint32_t instance         = 0U;
    uint8_t adcBaseSize       = ARRAY_SIZE(s_adcBases);

    /* Find the instance index from base address mappings. */
    for (; instance < adcBaseSize; ++instance)
    {
        if (MSDK_REG_SECURE_ADDR(s_adcBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < adcBaseSize);

    return instance;
}
#endif /* !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) */

/*!
 * brief This function is used to get available predefined configurations for the ADC initialization.
 *
 * param config Pointer to the ADC configuration structure, please refer to @ref adc_config_t for details.
 */
void ADC_GetDefaultConfig(adc_config_t *config)
{
    assert(config != NULL);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->enableAutoClockOff          = false;
    config->enableOverWrite             = true;
    config->enableConvertPresampleVal   = false;
#if defined(FSL_FEATURE_ADC_HAS_MCR_XSTARTEN) && (FSL_FEATURE_ADC_HAS_MCR_XSTARTEN==1U)
    config->enableAuxiliaryTrig         = false;
#endif /* FSL_FEATURE_ADC_HAS_MCR_XSTARTEN */

#if defined(FSL_FEATURE_ADC_HAS_AMSIO) && (FSL_FEATURE_ADC_HAS_AMSIO==1U)
    config->speedMode                   = kADC_SpeedModeNormal;
#endif /* FSL_FEATURE_ADC_HAS_AMSIO */
#if defined(FSL_FEATURE_ADC_HAS_DSDR) && (FSL_FEATURE_ADC_HAS_DSDR==1U)
    config->convDelay                   = 0x00U;
#endif /* FSL_FEATURE_ADC_HAS_DSDR */
#if defined(FSL_FEATURE_ADC_HAS_BCTUMODE) && (FSL_FEATURE_ADC_HAS_BCTUMODE==1U)
    config->bctuMode                    = kADC_BctuModeDisable;
#endif /* FSL_FEATURE_ADC_HAS_BCTUMODE */
#if (defined(FSL_FEATURE_ADC_HAS_CALBISTREG) && (FSL_FEATURE_ADC_HAS_CALBISTREG==1U))
    config->convRes                     = kADC_ConvRes14Bit;
#endif /* FSL_FEATURE_ADC_HAS_CALBISTREG */
#if defined(FSL_FEATURE_ADC_HAS_MCR_AVGS) && (FSL_FEATURE_ADC_HAS_MCR_AVGS==1U)
    config->convAvg                     = kADC_ConvAvgDisable;
#endif /* FSL_FEATURE_ADC_HAS_MCR_AVGS */
    config->extTrig                     = kADC_ExtTrigDisable;
#if !(defined(FSL_FEATURE_ADC_HAS_MCR_ADCLKSE) && (FSL_FEATURE_ADC_HAS_MCR_ADCLKSE==0U))
    config->clockFrequency              = kADC_FullBusFrequency;
#endif /* FSL_FEATURE_ADC_HAS_MCR_ADCLKSE */
#if (defined(FSL_FEATURE_ADC_HAS_MCR_ADCLKSEL) && (FSL_FEATURE_ADC_HAS_MCR_ADCLKSEL==1U))
    config->clockFrequency              = kADC_ModuleClockFreq;
#endif /* FSL_FEATURE_ADC_HAS_MCR_ADCLKSEL */
    config->convDataAlign               = kADC_ConvDataRightAlign;
    config->dmaRequestClearSrc          = kADC_DMARequestClearByAck;

    for (uint8_t index = 0U; index < (uint8_t)ADC_GROUP_COUNTS; ++index)
    {
        config->samplePhaseDuration[index] = 0x14U;
#if(ADC_GROUP_COUNTS==2U)
        config->presampleVoltageSrc[index] = kADC_PresampleVoltageSrcDVDD;
#else /* ADC_GROUP_COUNTS==3U */
        config->presampleVoltageSrc[index] = kADC_PresampleVoltageSrcVREL;
#endif /* ADC_GROUP_COUNTS */
    }
}

/*!
 * brief This function is used to initialize the ADC.
 *
 * param base ADC peripheral base address.
 * param config Pointer to the ADC configuration structure, please refer to @ref adc_config_t for details.
 */
void ADC_Init(ADC_Type *base, const adc_config_t *config)
{
    assert(config != NULL);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Open clock gate. */
    CLOCK_EnableClock(s_adcClocks[ADC_GetInstance(base)]);
#endif /* !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) */

    base->MCR = ((base->MCR & (~(ADC_MCR_ACKO_MASK | ADC_MCR_OWREN_MASK | ADC_MCR_WLSIDE_MASK
#if defined(FSL_FEATURE_ADC_HAS_EXTERNAL_TRIGGER) && (FSL_FEATURE_ADC_HAS_EXTERNAL_TRIGGER==1U)
                               | ADC_MCR_TRGEN_MASK | ADC_MCR_EDGE_MASK
#endif /* FSL_FEATURE_ADC_HAS_EXTERNAL_TRIGGER */
#if defined(FSL_FEATURE_ADC_HAS_MCR_XSTARTEN) && (FSL_FEATURE_ADC_HAS_MCR_XSTARTEN==1U)
                               | ADC_MCR_XSTRTEN_MASK
#endif /* FSL_FEATURE_ADC_HAS_MCR_XSTARTEN */
#if defined(FSL_FEATURE_ADC_HAS_BCTUMODE) && (FSL_FEATURE_ADC_HAS_BCTUMODE==1U)
                               | ADC_MCR_BCTUEN_MASK | ADC_MCR_BCTU_MODE_MASK
#endif /* FSL_FEATURE_ADC_HAS_BCTUMODE */
#if defined(FSL_FEATURE_ADC_HAS_MCR_AVGS) && (FSL_FEATURE_ADC_HAS_MCR_AVGS==1U)
                               | ADC_MCR_AVGEN_MASK | ADC_MCR_AVGS_MASK
#endif /* FSL_FEATURE_ADC_HAS_MCR_AVGS */
                                 )))
                 | (ADC_MCR_ACKO(config->enableAutoClockOff ? 1U : 0U) | ADC_MCR_OWREN(config->enableOverWrite ? 1U : 0U)
                 | ADC_MCR_WLSIDE(config->convDataAlign)
#if defined(FSL_FEATURE_ADC_HAS_EXTERNAL_TRIGGER) && (FSL_FEATURE_ADC_HAS_EXTERNAL_TRIGGER==1U)
                 | ADC_MCR_TRGEN(((uint32_t)config->extTrig & 0x2U) >> 1U) | ADC_MCR_EDGE((uint32_t)config->extTrig & 0x1U)
#endif /* FSL_FEATURE_ADC_HAS_EXTERNAL_TRIGGER */
#if defined(FSL_FEATURE_ADC_HAS_MCR_XSTARTEN) && FSL_FEATURE_ADC_HAS_MCR_XSTARTEN==1U
                 | ADC_MCR_XSTRTEN(config->enableAuxiliaryTrig)
#endif /* FSL_FEATURE_ADC_HAS_MCR_XSTARTEN */
#if defined(FSL_FEATURE_ADC_HAS_BCTUMODE) && (FSL_FEATURE_ADC_HAS_BCTUMODE==1U)
                 | ADC_MCR_BCTUEN((bool)((uint32_t)config->bctuMode & 0x2U)) | ADC_MCR_BCTU_MODE((bool)((uint32_t)config->bctuMode & 0x1U))
#endif /* FSL_FEATURE_ADC_HAS_BCTUMODE */
#if defined(FSL_FEATURE_ADC_HAS_MCR_AVGS) && (FSL_FEATURE_ADC_HAS_MCR_AVGS==1U)
                 | ADC_MCR_AVGEN(((uint32_t)config->convAvg & 0x4U) >> 2U) | ADC_MCR_AVGS((uint32_t)config->convAvg & 0x3U)
#endif /* FSL_FEATURE_ADC_HAS_MCR_AVGS */
                                 ));

#if defined(FSL_FEATURE_ADC_HAS_AMSIO) && (FSL_FEATURE_ADC_HAS_AMSIO==1U)
    ADC_SetAdcSpeedMode(base, config->speedMode);
#endif /* FSL_FEATURE_ADC_HAS_AMSIO */
                                 
#if (defined(FSL_FEATURE_ADC_HAS_CALBISTREG) && (FSL_FEATURE_ADC_HAS_CALBISTREG==1U))
    base->CALBISTREG = ((base->CALBISTREG & ~ADC_CALBISTREG_RESN_MASK) | ADC_CALBISTREG_RESN(config->convRes));
#endif /* FSL_FEATURE_ADC_HAS_CALBISTREG */

    /* Set the operating clock. */
    ADC_SetPowerDownMode(base, true);
    while (ADC_GetAdcState(base) != kADC_AdcPowerdown);
    
    ADC_SetOperatingClock(base, config->clockFrequency);
    adcClockFreq = config->clockFrequency;
    __ISB();

    ADC_SetPowerDownMode(base, false);
    while (ADC_GetAdcState(base) != kADC_AdcIdle);

    /* Set DMA transfer. */
    base->DMAE = ((base->DMAE & (~ADC_DMAE_DCLR_MASK)) | ADC_DMAE_DCLR(config->dmaRequestClearSrc));

    /* Set GROUPn sample phase duration. */
    base->CTR0 = ((base->CTR0 & (~ADC_CTR0_INPSAMP_MASK)) | ADC_CTR0_INPSAMP(config->samplePhaseDuration[0U]));
    base->CTR1 = ((base->CTR1 & (~ADC_CTR1_INPSAMP_MASK)) | ADC_CTR1_INPSAMP(config->samplePhaseDuration[1U]));
#if defined (FSL_FEATURE_ADC_INSTANCE_SUPPORT_GROUP3)
    if(1U == FSL_FEATURE_ADC_INSTANCE_SUPPORT_GROUP3(base))
    {
        base->CTR2 = ((base->CTR2 & (~ADC_CTR2_INPSAMP_MASK)) | ADC_CTR2_INPSAMP(config->samplePhaseDuration[2U]));
    }
#endif /* FSL_FEATURE_ADC_INSTANCE_SUPPORT_GROUP3 */

    /* Set GROUPn pre-sample voltage sources and decide whether to convert the pre-sample value. */
    base->PSCR = ((base->PSCR & (~(ADC_PSCR_PREVAL0_MASK | ADC_PSCR_PREVAL1_MASK | ADC_PSCR_PRECONV_MASK)))
                  | (ADC_PSCR_PREVAL0(config->presampleVoltageSrc[0U]) | ADC_PSCR_PREVAL1(config->presampleVoltageSrc[1U])
                  | ADC_PSCR_PRECONV(config->enableConvertPresampleVal ? 1U : 0U)));

#if defined (FSL_FEATURE_ADC_INSTANCE_SUPPORT_GROUP3)
    if(1U == FSL_FEATURE_ADC_INSTANCE_SUPPORT_GROUP3(base))
    {
        base->PSCR = ((base->PSCR & (~ADC_PSCR_PREVAL2_MASK)) | ADC_PSCR_PREVAL1(config->presampleVoltageSrc[2U]));
    }
#endif /* FSL_FEATURE_ADC_INSTANCE_SUPPORT_GROUP3 */
}

/*!
 * brief This function is used to de-initialize the ADC.
 *
 * param base ADC peripheral base address.
 */
void ADC_Deinit(ADC_Type *base)
{
    ADC_SetPowerDownMode(base, true);
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable clock gate. */
    CLOCK_DisableClock(s_adcClocks[ADC_GetInstance(base)]);
#endif /* !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) */
}

/*!
 * brief This function is used to configure the chain.
 *
 * param base ADC peripheral base address.
 * param config Pointer to the chain configuration structure, please refer to @ref adc_chain_config_t for details.
 */
void ADC_SetConvChainConfig(ADC_Type *base, const adc_chain_config_t *config)
{
    assert(config != NULL);

    uint32_t convChannelMask[ADC_GROUP_COUNTS]          = {0U};
    uint32_t convChannelPresampleMask[ADC_GROUP_COUNTS] = {0U};
    uint32_t convChannelDMAMask[ADC_GROUP_COUNTS]       = {0U};
    uint32_t convChannelWdgMask[ADC_GROUP_COUNTS]       = {0U};
    uint32_t convChannelIntMask[ADC_GROUP_COUNTS]       = {0U};

    adc_channel_config_t *chanConf = config->channelConfig;

    for (uint8_t index = 0U; index < config->channelCount; ++index)
    {
        convChannelMask[GET_REGINDEX(chanConf->channelIndex)] |=
            ((uint32_t)0x01U << GET_BITINDEX(chanConf->channelIndex));
        convChannelPresampleMask[GET_REGINDEX(chanConf->channelIndex)] |=
            (chanConf->enablePresample ? ((uint32_t)0x01U << GET_BITINDEX(chanConf->channelIndex)) : 0U);
        convChannelDMAMask[GET_REGINDEX(chanConf->channelIndex)] |=
            (chanConf->enableDmaTransfer ? ((uint32_t)0x01U << GET_BITINDEX(chanConf->channelIndex)) : 0U);
        convChannelIntMask[GET_REGINDEX(chanConf->channelIndex)] |=
            (chanConf->enableInt ? ((uint32_t)0x01U << GET_BITINDEX(chanConf->channelIndex)) : 0U);
        convChannelWdgMask[GET_REGINDEX(chanConf->channelIndex)] |=
            (chanConf->enableWdg ? ((uint32_t)0x01U << GET_BITINDEX(chanConf->channelIndex)) : 0U);

        /* Select the conversion channel's watchdog index. */
        if (chanConf->enableWdg)
        {
            CWSELR_IO(base,
                ((GET_REGINDEX(chanConf->channelIndex) * 4U) + (GET_BITINDEX(chanConf->channelIndex) >> 3U))) |=
                    WDG_SELECT(chanConf->wdgIndex, ((uint32_t)(chanConf->channelIndex) % 8U));
        }

        chanConf += 1U;
    }

    for (uint8_t index = 0U; index < (uint8_t)ADC_GROUP_COUNTS; ++index)
    {
#if defined (FSL_FEATURE_ADC_INSTANCE_SUPPORT_GROUP3)
        if(1U != FSL_FEATURE_ADC_INSTANCE_SUPPORT_GROUP3(base))
        {
            break;
        }
#endif /* FSL_FEATURE_ADC_INSTANCE_SUPPORT_GROUP3 */
            
        /* 1. Set conversion channel's interrupt.*/
        *(((volatile uint32_t *)(&(base->CIMR0))) + index) = convChannelIntMask[index];
        /* 2. Set the conversion channel's pre-sample feature.*/
        *(((volatile uint32_t *)(&(base->PSR0))) + index) = convChannelPresampleMask[index];
        /* 3. Set the conversion channel's DMA transfer feature.*/
        *(((volatile uint32_t *)(&(base->DMAR0))) + index) = convChannelDMAMask[index];
        /* 4. Set the conversion channel's watchdog feature.*/
        *(((volatile uint32_t *)(&(base->CWENR0))) + index) = convChannelWdgMask[index];
    }

    /* Set Channels conversion mode. */
    ADC_SetConvMode(base, config->convMode);

    /* Set channels to execute conversion, end-of-chain, and end-of-conversion interrupts. */
    /* Inject conversion. */
    if (config->convMode == kADC_InjectConvOneShotMode)
    {
        for (uint8_t index = 0U; index < (uint8_t)ADC_GROUP_COUNTS; ++index)
        {
#if defined (FSL_FEATURE_ADC_INSTANCE_SUPPORT_GROUP3)
            if(1U != FSL_FEATURE_ADC_INSTANCE_SUPPORT_GROUP3(base))
            {
                break;
            }
#endif /* FSL_FEATURE_ADC_INSTANCE_SUPPORT_GROUP3 */
            *(((volatile uint32_t *)(&(base->JCMR0))) + index) = convChannelMask[index];
        }

        if (config->enableGlobalChannelConvEndInt)
        {
            ADC_EnableConvInt(base, (uint32_t)kADC_InjectConvEndIntEnable);
        }
        if (config->enableChainConvEndInt)
        {
            ADC_EnableConvInt(base, (uint32_t)kADC_InjectConvChainEndIntEnable);
        }
    }
    else /* Normal conversion. */
    {
        for (uint8_t index = 0U; index < (uint8_t)ADC_GROUP_COUNTS; ++index)
        {
#if defined (FSL_FEATURE_ADC_INSTANCE_SUPPORT_GROUP3)
            if(1U != FSL_FEATURE_ADC_INSTANCE_SUPPORT_GROUP3(base))
            {
                break;
            }
#endif /* FSL_FEATURE_ADC_INSTANCE_SUPPORT_GROUP3 */
            *(((volatile uint32_t *)(&(base->NCMR0))) + index) = convChannelMask[index];
        }

        if (config->enableGlobalChannelConvEndInt)
        {
            ADC_EnableConvInt(base, (uint32_t)kADC_NormalConvEndIntEnable);
        }
        if (config->enableChainConvEndInt)
        {
            ADC_EnableConvInt(base, (uint32_t)kADC_NormalConvChainEndIntEnable);
        }
    }
}

/*!
 * brief This function is used to configure the analog watchdog.
 *
 * details The analog watchdogs are used to monitor the conversion result to see if it is within defined limits,
 * specified by a higher and a lower threshold value. After the conversion of the selected channel, a comparison is
 * performed between the converted value and the threshold values. If the converted value is outside the threshold
 * values, then a corresponding threshold violation interrupt is generated.
 *
 * param base ADC peripheral base address.
 * param config Pointer to the analog watchdog configuration structure, please refer to @ref adc_wdg_config_t for
 * details.
 * param count The number of analog watchdogs to be configured.
 */
void ADC_SetAnalogWdgConfig(ADC_Type *base, const adc_wdg_config_t *config)
{
    assert(config != NULL);

#if (defined(ADC_THRESHOLD_COUNTS) && (ADC_THRESHOLD_COUNTS==8U))
    volatile uint32_t *THRHLR[ADC_THRESHOLD_COUNTS] = {&(base->THRHLR0), &(base->THRHLR1), &(base->THRHLR2),
                                                       &(base->THRHLR3), &(base->THRHLR4), &(base->THRHLR5),
                                                       &(base->THRHLR6), &(base->THRHLR7)};
#else /* ADC_THRESHOLD_COUNTS=4U */
    volatile uint32_t *THRHLR[ADC_THRESHOLD_COUNTS] = {&(base->THRHLR[0]), &(base->THRHLR[1]),
                                                       &(base->THRHLR[2]), &(base->THRHLR[3])};
#endif /* ADC_THRESHOLD_COUNTS */

    /* Set low/high threshold values for selected channels. */
    *(THRHLR[config->wdgIndex]) = (((*(THRHLR[config->wdgIndex])) & (~(ADC_THRHLR_THRL_MASK | ADC_THRHLR_THRH_MASK))) |
                                   (ADC_THRHLR_THRL(config->lowThresholdVal) | ADC_THRHLR_THRH(config->highThresholdVal)));

    /* Enable analog watchdog low/high threshold interrupts. */
    ADC_EnableWdgThresholdInt(base, (uint32_t)(((uint32_t)config->wdgThresholdInt) << (2U * (config->wdgIndex))));
}

/*!
 * brief This function is used to do the calibration.
 *
 * details The calibration is used to reduce or eliminate the various errors. In the calibration process, the
 * calibration values for offset, gain, and capacitor mismatch are obtained. These calibration values (except gain
 * calibration) are used in a result post-processing step to reduce or eliminate the various errors contribution
 * effects. The gain calibration is used during the sample phase to define the additional charge to be loaded in order
 * to compensate for the gain failure. Calibration must be performed after every power-up reset and whenever required in
 * runtime operation. It is also recommended to run calibration if the operating conditions (particularly VrefH) change.
 * Never apply functional reset during the calibration process. If applied, calibration must be rerun after exiting a
 * reset condition; otherwise, the calibration-generated values and conversion results may be unspecified.
 *
 * note This function executes a calibration sequence, it is recommended to run this sequence before using the ADC
 * converter. The maximum clock frequency for the calibration is 40 MHz. Before calling this function, the user needs
 * to ensure that the input clock is within 40MHz. The results of individual steps are also updated in the CALSTAT
 * register (CALSTAT[STAT_n]). The result of the last failed step is dynamically updated in the same register.
 *
 * param base ADC peripheral base address.
 * param config Pointer to the calibration configuration structure, please refer to @ref adc_calibration_config_t for
 * details.
 *
 * return Status whether calibration is running passed or failed.
 * - \b true Calibration successful.
 * - \b false Calibration unsuccessful.
 */
bool ADC_DoCalibration(ADC_Type *base, const adc_calibration_config_t *config)
{
    assert(config != NULL);

    bool calibrationStatus = true;
    bool clockNeedRecovery = false;

#if (defined(FSL_FEATURE_ADC_HAS_CALBISTREG) && (FSL_FEATURE_ADC_HAS_CALBISTREG==1U))
    /* Clear the bits and set to calibration values */
    base->CALBISTREG = ((base->CALBISTREG & (~(ADC_CALBISTREG_AVG_EN_MASK |
                                              ADC_CALBISTREG_TSAMP_MASK |
                                              ADC_CALBISTREG_NR_SMPL_MASK))) |
                                             (ADC_CALBISTREG_TSAMP(config->sampleTime) |
                                              ADC_CALBISTREG_NR_SMPL(config->averageSampleNumbers) | 
                                              ADC_CALBISTREG_AVG_EN(config->enableAverage ? 1U : 0U)));
    
#if defined(FSL_FEATURE_ADC_HAS_AMSIO) && (FSL_FEATURE_ADC_HAS_AMSIO==1U)
    ADC_SetAdcSpeedMode(base, kADC_SpeedModeNormal);
#endif /* FSL_FEATURE_ADC_HAS_AMSIO */

#if defined(FSL_FEATURE_ADC_HAS_CAL2) && (FSL_FEATURE_ADC_HAS_CAL2==1U)
    base->CAL2 &= ~ADC_CAL2_ENX_MASK;
#endif /* FSL_FEATURE_ADC_HAS_CAL2 */

    /* Slow down ADC functional clock frequency. */
    if(adcClockFreq != kADC_ModuleClockFreqDivide8)
    {
        ADC_SetPowerDownMode(base, true);
        while (ADC_GetAdcState(base) != kADC_AdcPowerdown);
        
        ADC_SetOperatingClock(base, kADC_ModuleClockFreqDivide8);
        __ISB();

        ADC_SetPowerDownMode(base, false);
        while (ADC_GetAdcState(base) != kADC_AdcIdle);
        
        clockNeedRecovery = true;
    }

    /* Start calibration. */
    base->CALBISTREG |= ADC_CALBISTREG_TEST_EN_MASK;

#else
    /* Clear the bits and set to calibration values */
    base->MCR = ((base->MCR & (~(ADC_MCR_AVGEN_MASK | ADC_MCR_TSAMP_MASK | ADC_MCR_NRSMPL_MASK))) |
                 (ADC_MCR_AVGEN(config->enableAverage ? 1U : 0U) | ADC_MCR_TSAMP(config->sampleTime) |
                  ADC_MCR_NRSMPL(config->averageSampleNumbers)));

    /* Slow down ADC functional clock frequency. */
    if(adcClockFreq != kADC_HalfBusFrequency)
    {
        ADC_SetPowerDownMode(base, true);
        while (ADC_GetAdcState(base) != kADC_AdcPowerdown);

        ADC_SetOperatingClock(base, kADC_HalfBusFrequency);
        __ISB();

        ADC_SetPowerDownMode(base, false);
        while (ADC_GetAdcState(base) != kADC_AdcIdle);
        
        clockNeedRecovery = true;
    }
    
    /* Start calibration. */
    base->MCR |= ADC_MCR_CALSTART_MASK;
#endif /* FSL_FEATURE_ADC_HAS_CALBISTREG */

    /* Wait for calibration to finish. */
    while (ADC_CheckCalibrationBusy(base))
    {
    }

    /* Check the status of calibration. If calibration failed, check the pass/fail status of each calibration step
     * in the CALSTAT register look for failures, if calibration passes, double-check the MSR[CALIBRTD] bitfield.
     */
    if (ADC_CheckCalibrationFailed(base))
    {
        ADC_ClearCalibrationFailedFlag(base);
        calibrationStatus = false;
    }
    else
    {
        if (ADC_CheckCalibrationSuccessful(base))
        {
            calibrationStatus = true;
        }
        else
        {
            calibrationStatus = false;
        }
    }

    /* ADC functional clock recovery. */
    if(clockNeedRecovery)
    {
        ADC_SetPowerDownMode(base, true);
        while (ADC_GetAdcState(base) != kADC_AdcPowerdown);
        
        ADC_SetOperatingClock(base, adcClockFreq);
        __ISB();

        ADC_SetPowerDownMode(base, false);
        while (ADC_GetAdcState(base) != kADC_AdcIdle);
    }
    
    return calibrationStatus;
}

#if !(defined(FSL_FEATURE_ADC_HAS_CALSTAT) && (FSL_FEATURE_ADC_HAS_CALSTAT==0U))
/*!
 * brief This function is used to get the test result for the last failed test.
 *
 * param base ADC peripheral base address.
 * param result Points to a 16-bit signed variable, and it is used to store the test result for the last failing
 * test.
 */
void ADC_GetCalibrationLastFailedTestResult(ADC_Type *base, int16_t *result)
{
    assert(result != NULL);

    uint16_t tempResult = (uint16_t)((base->CALSTAT & ADC_CALSTAT_TEST_RESULT_MASK) >> ADC_CALSTAT_TEST_RESULT_SHIFT);

    if (0U != (tempResult & ADC_CALSTAT_SIGN))
    {
        tempResult |= (uint16_t)(~ADC_CALSTAT_MAX);
    }

    *result = (int16_t)tempResult;
}
#endif /* FSL_FEATURE_ADC_HAS_CALSTAT */

/*!
 * brief This function is used to configure the user gain and offset.
 *
 * param base ADC peripheral base address.
 * param config Pointer to the user offset and gain configuration structure, please refer to @ref
 * adc_user_offset_gain_config_t for details.
 */
void ADC_SetUserOffsetAndGainConfig(ADC_Type *base, const adc_user_offset_gain_config_t *config)
{
    assert(config != NULL);
#if !(defined(FSL_FEATURE_ADC_HAS_USROFSGN) && (FSL_FEATURE_ADC_HAS_USROFSGN==0U))
    base->USROFSGN = ((base->USROFSGN & (~(ADC_USROFSGN_GAINUSER_MASK | ADC_USROFSGN_OFFSUSER_MASK))) |
                      (ADC_USROFSGN_OFFSUSER(config->userOffset) | ADC_USROFSGN_GAINUSER(config->userGain)));
#endif /* FSL_FEATURE_ADC_HAS_USROFSGN */
#if defined(FSL_FEATURE_ADC_HAS_OFSGNUSR) && (FSL_FEATURE_ADC_HAS_OFSGNUSR==1U)
    base->OFSGNUSR = ((base->OFSGNUSR & (~(ADC_OFSGNUSR_GAIN_USER_MASK | ADC_OFSGNUSR_OFFSET_USER_MASK))) |
                      (ADC_OFSGNUSR_OFFSET_USER(config->userOffset) | ADC_OFSGNUSR_GAIN_USER(config->userGain)));
#endif /* FSL_FEATURE_ADC_HAS_OFSGNUSR */
}

/*!
 * brief This function is used to configure the ADC self-test.
 *
 * details The self-test is used to check at regular intervals whether ADC is operating correctly. When self-test is
 * enabled, ADC automatically checks its components and flags any errors it finds. The test can be enabled to check the
 * supply voltage (VDD), reference voltage (VrefH), and calibrated values.
 *
 * note Before calling this function, please ensure the functional conversion is one-shot conversion mode normal
 * conversion type and the operating clock are equal to bus frequency. ADC self-test should be run with MCR[ADCLKSE]
 * bit set to 1. Self-test with ADCLKSE bit set to 0 can give erroneous results.
 *
 * param base ADC peripheral base address.
 * param config Pointer to the self-test configuration structure, please refer to @ref adc_self_test_config_t for
 * details.
 */
void ADC_SetSelfTestConfig(ADC_Type *base, const adc_self_test_config_t *config)
{
    assert(config != NULL);

    base->STCR3 = ((base->STCR3 & (~(ADC_STCR3_ALG_MASK | ADC_STCR3_MSTEP_MASK))) | (ADC_STCR3_ALG(config->algType)));
    base->STBRR = ((base->STBRR & (~ADC_STBRR_BR_MASK)) | ADC_STBRR_BR(config->baudRate));
    base->STCR1 &= ~(ADC_STCR1_INPSAMP_C_MASK | ADC_STCR1_INPSAMP_S_MASK);

    switch (config->algType)
    {
        case kADC_SelfTestForAlgS:
            base->STCR1 |= ADC_STCR1_INPSAMP_S(config->algSSamplePhaseDuration);
            /* For one-shot, needs to select algorithm steps. */
            if (0x00U == ((base->MCR & ADC_MCR_MODE_MASK) >> ADC_MCR_MODE_SHIFT))
            {
                base->STCR3 |= ADC_STCR3_MSTEP(config->algSteps);
            }
            break;

        case kADC_SelfTestForAlgC:
            base->STCR1 |= ADC_STCR1_INPSAMP_C(config->algCSamplePhaseDuration);
            if (0x00U == ((base->MCR & ADC_MCR_MODE_MASK) >> ADC_MCR_MODE_SHIFT))
            {
                base->STCR3 |= ADC_STCR3_MSTEP(config->algSteps);
            }
            break;

        case kADC_SelfTestForAlgSAndC:
            base->STCR1 |= (ADC_STCR1_INPSAMP_S(config->algSSamplePhaseDuration) |
                            ADC_STCR1_INPSAMP_C(config->algCSamplePhaseDuration));
            break;

        default:
            assert(false);
            break;
    }
}

/*!
 * brief This function is used to configure the ADC self-test watchdog.
 *
 * param base ADC peripheral base address.
 * param config Pointer to the self-test watchdog configuration structure, please refer to @ref
 * adc_self_test_wdg_config_t for details.
 */
void ADC_SetSelfTestWdgConfig(ADC_Type *base, const adc_self_test_wdg_config_t *config)
{
    assert(config != NULL);

#if(ADC_SELF_TEST_THRESHOLD_COUNTS==6U)
    volatile uint32_t *STAWR[ADC_SELF_TEST_THRESHOLD_COUNTS] = {&(base->STAW0R), &(base->STAW1AR), &(base->STAW1BR),
                                                                &(base->STAW2R), &(base->STAW4R),  &(base->STAW5R)};
#else /* ADC_SELF_TEST_THRESHOLD_COUNTS==5U */
    volatile uint32_t *STAWR[ADC_SELF_TEST_THRESHOLD_COUNTS] = {&(base->STAW0R), &(base->STAW1R), &(base->STAW2R),
                                                                &(base->STAW4R), &(base->STAW5R)};
#endif /* ADC_SELF_TEST_THRESHOLD_COUNTS */

    /* Set low/high threshold values for selected watchdog. */
    if (config->wdgThresholdId == kADC_SelfTestWdgThresholdForAlgSStep2)
    {
        *(STAWR[config->wdgThresholdId]) = (((*(STAWR[config->wdgThresholdId])) & (~(ADC_STAWR_THRL_MASK))) |
                                            (ADC_STAWR_THRL(config->lowThrsholdVal)));
    }
    else
    {
        *(STAWR[config->wdgThresholdId]) =
            (((*(STAWR[config->wdgThresholdId])) & (~(ADC_STAWR_THRL_MASK | ADC_STAWR_THRH_MASK))) |
             (ADC_STAWR_THRL(config->lowThrsholdVal) | ADC_STAWR_THRH(config->highThrsholdVal)));
    }
}

/*!
 * brief This function is used to get the specific ADC channel's conversion result.
 *
 * details CDR[VALID] indicates whether a new conversion is available, this field is automatically reset to 0 when the
 * data is read. CDR[OVERW] Indicates whether the previous conversion data was overwritten without having been read, in
 * which case the overwritten data is lost.
 *
 * param base SAR ADC peripheral base address.
 * param result Pointer to SAR ADC channels conversion result structure, please refer to @ref adc_conv_result_t for
 * details.
 * param channelIndex Channel index to get the conversion result.
 *
 * return Indicates whether the acquisition of the specific channel conversion result is successful or not.
 * - \b true Obtaining the specific channel conversion result successfully, and the conversion result is stored in the
 * input parameter result.
 * - \b false Obtaining the specific channel conversion result failed.
 */
bool ADC_GetChannelConvResult(ADC_Type *base, adc_conv_result_t *result, uint8_t channelIndex)
{
    assert(result != NULL);

    uint32_t tmpResult = 0x00UL;

    tmpResult = CDR_I(base, channelIndex);

    if (ADC_CDR_VALID_MASK != (tmpResult & ADC_CDR_VALID_MASK))
    {
        return false;
    }

    result->overWrittenFlag = (bool)((tmpResult & ADC_CDR_OVERW_MASK) >> ADC_CDR_OVERW_SHIFT);
    result->convMode        = (uint8_t)((tmpResult & ADC_CDR_RESULT_MASK) >> ADC_CDR_RESULT_SHIFT);
    result->convData        = (uint16_t)((tmpResult & ADC_CDR_CDATA_MASK) >> ADC_CDR_CDATA_SHIFT);

    return true;
}

/*!
 * brief This function is used to get the test channel converted data when algorithm S step 0, algorithm S step 2, or
 * algorithm C step executes.
 *
 * param base ADC peripheral base address.
 * param result Pointer to the SAR ADC self-test channel conversion result structure, please refer to @ref
 * adc_self_test_conv_result_t for details.
 *
 * return Indicates whether the acquisition of the self-test channel conversion result is successful or not.
 * - \b true Obtaining the self-test channel conversion result successfully, and the conversion result is stored in the
 * input parameter 'result'.
 * - \b false Obtaining the self-test channel conversion result failed.
 */
bool ADC_GetSelfTestChannelConvData(ADC_Type *base, adc_self_test_conv_result_t *result)
{
    assert(result != NULL);

    uint32_t tmpResult = 0x00UL;

    tmpResult = base->STDR1;

    if (ADC_STDR1_VALID_MASK != (tmpResult & ADC_STDR1_VALID_MASK))
    {
        return false;
    }

    result->overWrittenFlag = (bool)((tmpResult & ADC_STDR1_OWERWR_MASK) >> ADC_STDR1_OWERWR_SHIFT);
    result->convData        = (uint16_t)((tmpResult & ADC_STDR1_TCDATA_MASK) >> ADC_STDR1_TCDATA_SHIFT);

    return true;
}

#if !(defined(FSL_FEATURE_ADC_HAS_STDR2) && (FSL_FEATURE_ADC_HAS_STDR2==0U))
/*!
 * brief This function is used to get the test channel converted data when algorithm S step 1 executes.
 *
 * param base ADC peripheral base address.
 * param result Pointer to the SAR ADC self-test channel conversion result structure, please refer to @ref
 * adc_self_test_conv_result_t for details.
 *
 * return Indicates whether the acquisition of the self-test channel conversion result is successful or not.
 * - \b true Obtaining the self-test channel conversion result successfully, and the conversion result is stored in the
 * input parameter 'result'.
 * - \b false Obtaining the self-test channel conversion result failed.
 */
bool ADC_GetSelfTestChannelConvDataForAlgSStep1(ADC_Type *base, adc_self_test_conv_result_t *result)
{
    assert(result != NULL);

    uint32_t tmpResult = 0x00UL;

    tmpResult = base->STDR2;

    if (ADC_STDR2_VALID_MASK != (tmpResult & ADC_STDR2_VALID_MASK))
    {
        return false;
    }

    result->overWrittenFlag  = (bool)((tmpResult & ADC_STDR2_OVERWR_MASK) >> ADC_STDR2_OVERWR_SHIFT);
    result->convData         = (uint16_t)((tmpResult & ADC_STDR2_IDATA_MASK) >> ADC_STDR2_IDATA_SHIFT);
    result->convDataFraction = (uint16_t)((tmpResult & ADC_STDR2_FDATA_MASK) >> ADC_STDR2_FDATA_SHIFT);

    return true;
}
#endif /* FSL_FEATURE_ADC_HAS_STDR2 */
