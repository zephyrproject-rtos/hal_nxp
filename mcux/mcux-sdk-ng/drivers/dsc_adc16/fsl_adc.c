/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_adc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_adc16"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Get instance number for ADC16 module.
 *
 * @param base ADC16 peripheral base address
 */
static uint32_t ADC16_GetInstance(SADC_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to ADC16 bases for each instance. */
static SADC_Type *const s_adc16Bases[] = SADC_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to ADC16 clocks for each instance. */
static const clock_ip_name_t s_adc16Clocks[] = SARADC_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t ADC16_GetInstance(SADC_Type *base)
{
    uint32_t u32Instance;

    /* Find the instance index from base address mappings. */
    for (u32Instance = 0u; u32Instance < ARRAY_SIZE(s_adc16Bases); u32Instance++)
    {
        if (s_adc16Bases[u32Instance] == base)
        {
            break;
        }
    }

    assert(u32Instance < ARRAY_SIZE(s_adc16Bases));

    return u32Instance;
}
/*!
 * brief Initializes the ADC16 module.
 *
 * param base      ADC16 peripheral base address.
 * param psConfig  Pointer to configuration structure. See @ref adc16_config_t.
 */
void ADC16_Init(SADC_Type *base, const adc16_config_t *psConfig)
{
    assert(NULL != psConfig);

    uint32_t u32Tmp;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(s_adc16Clocks[ADC16_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* ADCx_CFG1. */
    u32Tmp = SADC_CFG1_ADICLK(psConfig->eClockSource) | SADC_CFG1_MODE(psConfig->eResolution);
    if (kADC16_SampleDisabled != psConfig->eSampleMode)
    {
        u32Tmp |= SADC_CFG1_ADLSMP_MASK;
    }
    u32Tmp |= SADC_CFG1_ADIV(psConfig->eClockDivider);
    if (true == psConfig->bEnableLowPower)
    {
        u32Tmp |= SADC_CFG1_ADLPC_MASK;
    }
    base->CFG1 = u32Tmp;

    /* ADCx_CFG2. */
    u32Tmp = base->CFG2 & ~(SADC_CFG2_ADACKEN_MASK | SADC_CFG2_ADHSC_MASK | SADC_CFG2_ADLSTS_MASK);
    if (kADC16_SampleDisabled != psConfig->eSampleMode)
    {
        u32Tmp |= SADC_CFG2_ADLSTS(psConfig->eSampleMode);
    }
    if (true == psConfig->bEnableHighSpeed)
    {
        u32Tmp |= SADC_CFG2_ADHSC_MASK;
    }
    if (true == psConfig->bEnableAsynchronousClock)
    {
        u32Tmp |= SADC_CFG2_ADACKEN_MASK;
    }
    base->CFG2 = u32Tmp;

    /* ADCx_SC2. */
    u32Tmp = base->SC2 & ~(SADC_SC2_REFSEL_MASK);
    u32Tmp |= SADC_SC2_REFSEL(psConfig->eReferenceVoltageSource);
    base->SC2 = u32Tmp;

    /*Configures Conversion trigger mode */
    ADC16_SetTriggerSource(base, kADC16_HardWareTrigger);

    /* Configures the conversion channel*/
    ADC16_AssginChannelToGroup(base, psConfig->u32GroupId, psConfig->eChannelInput);

    /* Enables the conversion interrupts. */
    if (psConfig->bEnableInterruptOnConversionCompleted)
    {
        ADC16_EnableInterrupt(base, psConfig->u32GroupId);
    }

    /*Configures Conversion trigger mode */
    ADC16_SetTriggerSource(base, psConfig->eConversionTrigger);

    /*Enable/Disable DMA*/
    if (psConfig->bEnableDMA)
    {
        base->SC2 |= SADC_SC2_DMAEN_MASK;
    }
    else
    {
        base->SC2 &= ~SADC_SC2_DMAEN_MASK;
    }

    /* ADCx_SC3. */
    /*Enable continuous conversion */
    if (true == psConfig->bEnableContinuousConversion)
    {
        base->SC3 |= SADC_SC3_ADCO_MASK;
    }
    else
    {
        base->SC3 &= ~SADC_SC3_ADCO_MASK;
    }

    /*Configures Hardware average mode*/
    ADC16_SetHardwareAverage(base, psConfig->eHardwareAverageMode);

    /* Configures the hardware compare mode*/
    ADC16_SetHardwareCompareConfig(base, psConfig->psHardwareCompare);
}

/*!
 * brief De-initializes the ADC16 module.
 *
 * param base ADC16 peripheral base address.
 */
void ADC16_Deinit(SADC_Type *base)
{
    uint32_t u32Tmp;

    /*Clear calibration complete flag */
    base->SC3 |= SADC_SC3_CALF_MASK;

    /* Abort the Conversion active */
    base->SC2 &= ~SADC_SC2_ADACT_MASK;

    /* Disable the module*/
    u32Tmp = SADC_SC1_ADCH(kADC16_ModuleDisabled);

    base->SC1[0] = ((base->SC1[0] & ~SADC_SC1_ADCH_MASK) | u32Tmp);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(s_adc16Clocks[ADC16_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}
/*!
 * brief Gets an available pre-defined settings for the converter's configuration.
 *
 * This function initializes the converter configuration structure with available settings. The default values are as
 * follows.
 * code
 *     psConfig->eReferenceVoltageSource                 = kADC16_ReferenceVoltageSourceVref;
 *     psConfig->eClockSource                            = kADC16_ClockSourceAsynchronousClock;
 *     psConfig->bEnableAsynchronousClock                = true;
 *     psConfig->eClockDivider                           = kADC16_ClockDivider8;
 *     psConfig->eResolution                             = KADC16_Resolution12bit;
 *     psConfig->eLongSampleMode                         = kADC16_SampleDisabled;
 *     psConfig->bEnableHighSpeed                        = false;
 *     psConfig->bEnableLowPower                         = false;
 *     psConfig->eChannelInput                           = kADC16_ModuleDisabled;
 *     psConfig->u32GroupId                              = 0U;
 *     psConfig->bEnableInterruptOnConversionCompleted   = false;
 *     psConfig->bEnableDMA                              = false;
 *     psConfig->eConversionTrigger                      = kADC16_ConversionTrggerDisable;
 *     psConfig->eHardwareAverageMode                    = kADC16_HardwareAverageDisabled;
 *     psConfig->bEnableContinuousConversion             = false;
 *     psConfig->psHardwareCompare                       = NULL;
 * endcode
 * param config Pointer to the configuration structure. See @ref adc16_config_t.
 */
void ADC16_GetDefaultConfig(adc16_config_t *psConfig)
{
    assert(NULL != psConfig);

    psConfig->eReferenceVoltageSource               = kADC16_ReferenceVoltageSourceVref;
    psConfig->eClockSource                          = kADC16_ClockSourceAsynchronousClock;
    psConfig->bEnableAsynchronousClock              = true;
    psConfig->eClockDivider                         = kADC16_ClockDivider8;
    psConfig->eResolution                           = kADC16_Resolution12bit;
    psConfig->eSampleMode                           = kADC16_SampleDisabled;
    psConfig->bEnableHighSpeed                      = false;
    psConfig->bEnableLowPower                       = false;
    psConfig->eChannelInput                         = kADC16_ModuleDisabled;
    psConfig->u32GroupId                            = 0U;
    psConfig->bEnableInterruptOnConversionCompleted = false;
    psConfig->eConversionTrigger                    = kADC16_SoftWareTrigger;
    psConfig->bEnableDMA                            = false;
    psConfig->eHardwareAverageMode                  = kADC16_HardwareAverageDisabled;
    psConfig->bEnableContinuousConversion           = false;
    psConfig->psHardwareCompare                     = NULL;
}

/*!
 * brief  Automates the hardware calibration.
 *
 * This auto calibration helps to adjust the plus/minus side gain automatically.
 * Execute the calibration before using the converter. Note that the hardware trigger should be used
 * during the calibration.
 *
 * param  base ADC16 peripheral base address.
 *
 * return                   Execution status.
 * retval kStatus_Success   Calibration is done successfully.
 * retval kStatus_Fail      Calibration has failed.
 */
status_t ADC16_DoAutoCalibration(SADC_Type *base)
{
    bool bHWTrigger = false;
    uint32_t u32Tmp;
    status_t status = kStatus_Success;
    uint32_t result;

    /* The calibration would be failed when in hardward mode.
     * Remember the hardware trigger state here and restore it later if the hardware trigger is enabled.*/
    if (0u != (SADC_SC2_ADTRG_MASK & base->SC2))
    {
        bHWTrigger = true;
        base->SC2 &= ~SADC_SC2_ADTRG_MASK;
    }

    /* Clear the CALF and launch the calibration. */
    base->SC3 |= SADC_SC3_CAL_MASK | SADC_SC3_CALF_MASK;
    while (false == ADC16_IsGroupConversionCompleted(base, 0U))
    {
        /* Check the CALF when the calibration is active. */
        if (0U != ((uint32_t)(SADC_SC3_CALF_MASK) & (base->SC3 & SADC_SC3_CALF_MASK)))
        {
            status = kStatus_Fail;
            break;
        }
    }

    /* Dummy read to clear COCO caused by calibration. */
    result = ADC16_GetGroupConversionValue(base, 0);
    /* Restore the hardware trigger setting if it was enabled before. */

    if (bHWTrigger)
    {
        base->SC2 |= SADC_SC2_ADTRG_MASK;
    }
    /* Check the CALF at the end of calibration. */
    if (0u != ((uint32_t)SADC_SC3_CALF_MASK & (base->SC2 & SADC_SC2_ADACT_MASK)))
    {
        status = kStatus_Fail;
    }

    if (kStatus_Success != status) /* Check if the calibration process is succeed. */
    {
        return status;
    }
    /* Calculate the calibration values. */
    u32Tmp = base->CLP0;
    u32Tmp += base->CLP1;
    u32Tmp += base->CLP2;
    u32Tmp += base->CLP3;
    u32Tmp += base->CLP4;
    u32Tmp += base->CLPS;
    u32Tmp   = 0x8000U | (u32Tmp >> 1U);
    base->PG = u32Tmp;

    (void)result;
    return kStatus_Success;
}
/*!
 * brief Configures the hardware compare mode.
 *
 * The hardware compare mode provides a way to process the conversion result automatically by using hardware. Only the
 * result
 * in the compare range is available. To compare the range, see "adc16_hardware_compare_mode_t" or the appopriate
 * reference
 * manual for more information.
 *
 * param base       ADC16 peripheral base address.
 * param psConfig   Pointer to the "adc16_hardware_compare_t" structure. Passing "NULL" disables the feature.
 */
void ADC16_SetHardwareCompareConfig(SADC_Type *base, const adc16_hardware_compare_t *psConfig)
{
    uint32_t u32Tmp = base->SC2 & ~(SADC_SC2_ACFE_MASK | SADC_SC2_ACFGT_MASK | SADC_SC2_ACREN_MASK);

    if (NULL == psConfig) /* Pass "NULL" to disable the feature. */
    {
        base->SC2 = u32Tmp;
        return;
    }
    else
    {
        /* Select the compare working mode. */
        switch (psConfig->eCompareMode)
        {
            case kADC16_LessThanThreshold:
                u32Tmp |= SADC_SC2_ACFE_MASK;
                base->CV1 = SADC_CV1_CV(psConfig->i16Value1);
                break;
            case kADC16_GreaterThanOrEqualThreshold:
                u32Tmp |= SADC_SC2_ACFGT_MASK | SADC_SC2_ACFE_MASK;
                base->CV1 = SADC_CV1_CV(psConfig->i16Value1);
                break;
            case kADC16_TriggerOutsideCompareRangeMode1:
                if ((psConfig->i16Value1 < psConfig->i16Value2) || (psConfig->i16Value1 == psConfig->i16Value2))
                {
                    u32Tmp |= SADC_SC2_ACREN_MASK | SADC_SC2_ACFE_MASK;
                }
                break;
            case kADC16_TriggerInsideCompareRangeMode1:
                if (psConfig->i16Value1 > psConfig->i16Value2)
                {
                    u32Tmp |= SADC_SC2_ACREN_MASK | SADC_SC2_ACFE_MASK;
                }
                break;
            case kADC16_TriggerInsideCompareRangeMode2:
                if ((psConfig->i16Value1 < psConfig->i16Value2) || (psConfig->i16Value1 == psConfig->i16Value2))
                {
                    u32Tmp |= SADC_SC2_ACFGT_MASK | SADC_SC2_ACREN_MASK | SADC_SC2_ACFE_MASK;
                }
                break;
            case kADC16_TriggerOutsideCompareRangeMode2:
                if (psConfig->i16Value1 > psConfig->i16Value2)
                {
                    u32Tmp |= SADC_SC2_ACFGT_MASK | SADC_SC2_ACREN_MASK | SADC_SC2_ACFE_MASK;
                }
                break;
            default:
                assert(false);
                break;
        }
    }

    base->SC2 = u32Tmp;

    if ((psConfig->eCompareMode != kADC16_LessThanThreshold) &&
        (psConfig->eCompareMode != kADC16_GreaterThanOrEqualThreshold))
    {
        base->CV1 = SADC_CV1_CV(psConfig->i16Value1);
        base->CV2 = SADC_CV2_CV(psConfig->i16Value2);
    }
}

/*!
 * brief Sets the hardware average mode.
 *
 * The hardware average mode provides a way to process the conversion result automatically by using hardware. The
 * multiple
 * conversion results are accumulated and averaged internally making them easier to read.
 *
 * param base                  ADC16 peripheral base address.
 * param eHardwareAverageMode  Setting the hardware average mode. See @ref adc16_hardware_average_mode_t.
 */
void ADC16_SetHardwareAverage(SADC_Type *base, adc16_hardware_average_mode_t eHardwareAverageMode)
{
    uint32_t u32Tmp = base->SC3 & ~(SADC_SC3_AVGE_MASK | SADC_SC3_AVGS_MASK);

    /*select hardawre average mode */
    if (kADC16_HardwareAverageDisabled != eHardwareAverageMode)
    {
        u32Tmp |= SADC_SC3_AVGE_MASK | SADC_SC3_AVGS(eHardwareAverageMode);
    }
    base->SC3 = u32Tmp;
}

/*!
 * @brief setting ADC16 trigger mode.
 *
 * @param base            ADC16 peripheral base address.
 * @param eTriggerSource  Setting the trigger conversion mode. See @ref adc16_trigger_source_t.
 */
void ADC16_SetTriggerSource(SADC_Type *base, adc16_trigger_source_t eTriggerSource)
{
    uint32_t u32Tmp = base->SC2 & ~(SADC_SC2_ADTRG_MASK);

    /*Set ADC16 trigger modes*/

    u32Tmp |= SADC_SC2_ADTRG(eTriggerSource);

    base->SC2 = u32Tmp;
}

/*!
 * @brief Turns on the ADC16 conversion.
 *
 * The u32GroupId is for Group registers.
 * For example,u32GroupId 0 is for Group A registers.
 *
 * @param base            ADC16 peripheral base address.
 * @param u32GroupId      group identification.
 */
void Adc16_DoSoftwareTrigger(SADC_Type *base, uint32_t u32GroupId)
{
    assert(u32GroupId < SADC_SC1_COUNT);

    uint32_t u32Sc1 = base->SC1[u32GroupId];

    base->SC1[u32GroupId] = u32Sc1;
}

/*!
 * @brief Aborts the ADC16 conversion.
 *
 * The u32GroupId is for Group registers.
 * For example,u32GroupId 0 is for Group A registers.
 *
 * @param base            ADC16 peripheral base address.
 * @param u32GroupId      group identification.
 */
void Adc16_AbortSoftwareTrigger(SADC_Type *base, uint32_t u32GroupId)
{
    /* Disable the module,abort the channel conversion */
    uint32_t u32Sc1 = SADC_SC1_ADCH(kADC16_ModuleDisabled);

    base->SC1[u32GroupId] = ((base->SC1[u32GroupId] & ~SADC_SC1_ADCH_MASK) | u32Sc1);
}

/*!
 * brief  Clears calibration completed flag .
 *
 * param  base ADC16 peripheral base address.
 */
void ADC16_ClearCalibrationCompletedFlag(SADC_Type *base)
{
    uint32_t u32Tmp = base->SC3 & ~(SADC_SC3_CALF_MASK);

    u32Tmp |= SADC_SC3_CALF_MASK;

    base->SC3 = u32Tmp;
}

/*!
 * brief Configures the conversion Group channel.
 *
 * This operation triggers the conversion when in software trigger mode. When in hardware trigger mode, this API
 * configures the channel while the external trigger source helps to trigger the conversion.
 *
 * Note that the " u32GroupId " has a detailed description. one for each conversion.
 * The u32GroupId parameter indicates which group of registers are used, for example,
 * u32GroupId 0 is for Group A registers. At any point, only one of ,the u32GroupId is actively
 * controlling ADC conversions.The u32GroupId 0 is used for both software and hardware trigger modes.
 * See the chip configuration information in the appropriate MCU reference manual for
 * the number of SC1n registers (u32GroupId) specific to this device. Therefore, writing to these u32GroupId does
 * not initiate a new conversion. Writing any of the u32GroupId registers while that specific u32GroupId
 * is actively controlling a conversion aborts the current conversion.
 *
 * param base          ADC16 peripheral base address.
 * param u32GroupId    group identification. u32GroupId is for Group registers.
 * param eChannel      Setting the conversion channel. See @ref adc16_input_channel_t.
 */
void ADC16_AssginChannelToGroup(SADC_Type *base, uint32_t u32GroupId, adc16_input_channel_t eChannel)
{
    assert(u32GroupId < SADC_SC1_COUNT);

    uint32_t u32Sc1 = SADC_SC1_ADCH(eChannel); /* Set the conversion channel. */

    base->SC1[u32GroupId] = ((base->SC1[u32GroupId] & ~SADC_SC1_ADCH_MASK) | u32Sc1);
}

/*!
 * brief  Checks the status of group conversion
 *
 * The u32GroupId is for Group registers.
 * For example,u32GroupId 0 is for Group A registers.
 *
 * param  base         ADC16 peripheral base address.
 * param  u32GroupId   group identification.
 */
bool ADC16_IsGroupConversionCompleted(SADC_Type *base, uint32_t u32GroupId)
{
    assert(u32GroupId < SADC_SC1_COUNT);

    bool bRet = false;

    if (0U != (base->SC1[u32GroupId] & SADC_SC1_COCO_MASK))
    {
        bRet = true;
    }
    return bRet;
}
