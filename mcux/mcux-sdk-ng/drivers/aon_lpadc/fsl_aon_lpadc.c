/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_aon_lpadc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.aon_lpadc"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to LPADC bases for each instance. */
static LPADC_Type *const s_ADCBases[] = LPADC_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to LPADC clocks for each instance. */
static const clock_ip_name_t s_ADCClocks[] = AON_LPADC_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(AON_LPADC_RSTS)
static const SYSCON_RSTn_t s_adcResets[] = AON_LPADC_RSTS;
#endif /* ADC_RSTS */

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t ADC_GetInstance(LPADC_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    /*
     * $Branch Coverage Justification$
     * (instance >= ARRAY_SIZE(s_ADCBases)) not covered. The peripheral base
     * address is always valid and checked by assert.
     */
    for (instance = 0; instance < ARRAY_SIZE(s_ADCBases); instance++)
    {
        /*
         * $Branch Coverage Justification$
         * (s_ADCBases[instance] != base) not covered. The peripheral base
         * address is always valid and checked by assert.
         */
        if (MSDK_REG_SECURE_ADDR(s_ADCBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_ADCBases));

    return instance;
}

/*!
 * brief Gets an available pre-defined settings for ADC configuration.
 *
 * param config Pointer to ADC configuration structure, @ref adc_config_t.
 */
void ADC_GetDefaultConfig(adc_config_t *config)
{
    assert(config != NULL);

    (void)memset(config, 0U, sizeof(*config));

    config->dozeModeEn          = false;
    config->convPauseEn         = false;
    config->dynamicEleMatchEn   = true;
    config->compTime            = 0x8U;
    config->convPauseDelay      = 0U;
    config->fifo0Watermark      = 0U;
    config->calConvAvg          = kADC_CalConvAvg0;
    config->refVoltageSrc       = kADC_RefVoltageAlt1;
    config->dacSettleTime       = kADC_FastDacSettleTime;
    config->calConvSampTime     = kADC_CalConvSampTime_AdckCycle0;
    config->trigPriorityPolicy  = kADC_ConvPreemptImmedNotAutoResumed;
}

/*!
 * brief Initializes the ADC module.
 *
 * param base   ADC peripheral base address.
 * param config Pointer to configuration structure, @ref padc_config_t.
 */
void ADC_Init(LPADC_Type *base, const adc_config_t *config)
{
    assert(config != NULL);

    uint8_t tprictrl;
    uint8_t tres;
    uint8_t tcmdres;
    uint8_t hpted;

#if (defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && !FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    (void)CLOCK_EnableClock(s_ADCClocks[ADC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(AON_LPADC_RSTS)
    RESET_ReleasePeripheralReset(s_adcResets[ADC_GetInstance(base)]);
#endif

    ADC_DoSoftWareRst(base);

    ADC_DoFifoRst(base, kADC_Fifo0);
    ADC_DoFifoRst(base, kADC_Fifo1);

    /* Doze */
    if (config->dozeModeEn)
    {
        base->CTRL &= ~LPADC_CTRL_DOZEN_MASK;
    }
    else
    {
        base->CTRL |= LPADC_CTRL_DOZEN_MASK;
    }

    /* Conversion pause */
    if (config->convPauseEn)
    {
        base->PAUSE = ((base->PAUSE & ~LPADC_PAUSE_PAUSEDLY_MASK) | 
                       (LPADC_PAUSE_PAUSEEN_MASK | LPADC_PAUSE_PAUSEDLY(config->convPauseDelay)));
    }
    else
    {
        base->PAUSE &= ~LPADC_PAUSE_PAUSEDLY_MASK;
    }
    
    /* Dynamic element match */
    if (config->dynamicEleMatchEn)
    {
        base->CFG2 |= LPADC_CFG2_DEM_EN_MASK;
    }
    else
    {
        base->CFG2 &= ~LPADC_CFG2_DEM_EN_MASK;
    }

    /* Compare time, DAC settle time */
    base->CFG2 = ((base->CFG2 & ~(LPADC_CFG2_CTS_MASK | LPADC_CFG2_DAC_SETTLE_DLY_MASK)) | 
                  (LPADC_CFG2_CTS(config->compTime) | LPADC_CFG2_DAC_SETTLE_DLY(config->dacSettleTime)));
    
    /* FIFO0 watermark */
    base->FCTRL0 = LPADC_FCTRL0_FWMARK(config->fifo0Watermark);

    /* Calibration average and sample time */
    base->CTRL = ((base->CTRL & ~(LPADC_CTRL_CAL_AVGS_MASK | LPADC_CTRL_CAL_STS_MASK)) |
                  (LPADC_CTRL_CAL_AVGS(config->calConvAvg) | LPADC_CTRL_CAL_STS(config->calConvSampTime)));
    
    /* Reference */
    base->CFG = ((base->CFG & ~LPADC_CFG_REFSEL_MASK) | LPADC_CFG_REFSEL(config->refVoltageSrc));
    
    /* Trigger priority exeception handle policy */
    ADC_TRIG_PRIORITY_EXC_HANDLE_POLICY_DE(config->trigPriorityPolicy);
    
    base->CFG = ((base->CFG & ~(LPADC_CFG_TPRICTRL_MASK | LPADC_CFG_TRES_MASK |
                                LPADC_CFG_TCMDRES_MASK | LPADC_CFG_HPT_EXDI_MASK)) |
                                (LPADC_CFG_TPRICTRL(tprictrl) | LPADC_CFG_TRES(tres) |
                                LPADC_CFG_TCMDRES(tcmdres) | LPADC_CFG_HPT_EXDI(hpted)));
}

/*!
 * brief De-initializes the ADC module.
 *
 * param base ADC peripheral base address.
 */
void ADC_Deinit(LPADC_Type *base)
{
    ADC_Enable(base, false);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    (void)CLOCK_DisableClock(s_ADCClocks[ADC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
    
#if defined(ADC_RSTS)
    RESET_SetPeripheralReset(s_adcResets[ADC_GetInstance(base)]);
#endif /* ADC_RSTS */
}

/*!
 * brief Gets an available pre-defined settings for ADC trigger's configuration.
 *
 * param config Pointer to ADC trigger configuration structure, @ref adc_trig_config_t.
 */
void ADC_GetDefaultTrigConfig(adc_trig_config_t *config)
{
    assert(config != NULL);

    (void)memset(config, 0U, sizeof(*config));

    config->trigEn              = false;
    config->trigPriority        = 0U;
    config->trigDelay           = 0U;
    config->cmdIndex            = kADC_CmdNone;
    config->resFifo             = kADC_Fifo0;
}

/*!
 * brief Configure the ADC trigger source.
 *
 * param base ADC peripheral base address.
 * param index ADC trigger index, @ref adc_trig_index_t.
 * param config Pointer to ADC trigger configuration structure, @ref adc_trig_config_t.
 */
void ADC_SetTrigConfig(LPADC_Type *base, adc_trig_index_t index, const adc_trig_config_t *config)
{
    assert(index < LPADC_TCTRL_COUNT);
    assert(config != NULL);

    base->TCTRL[index] = ((base->TCTRL[index] & ~(LPADC_TCTRL_TCMD_MASK | LPADC_TCTRL_TDLY_MASK |
                          LPADC_TCTRL_TPRI_MASK | LPADC_TCTRL_FIFO_SEL_MASK)) |
                          (LPADC_TCTRL_TCMD(config->cmdIndex) | LPADC_TCTRL_TDLY(config->trigDelay) |
                          LPADC_TCTRL_TPRI(config->trigPriority) | LPADC_TCTRL_FIFO_SEL(config->resFifo)));

    if (config->trigEn)
    {
        base->TCTRL[index] |= LPADC_TCTRL_HTEN_MASK;
    }
    else
    {
        base->TCTRL[index] &= ~LPADC_TCTRL_HTEN_MASK;
    }
}

/*!
 * brief Gets an available pre-defined settings for ADC command's configuration.
 *
 * param config Pointer to ADC command configuration structure, @ref adc_cmd_config_t.
 */
void ADC_GetDefaultCmdConfig(adc_cmd_config_t *config)
{
    assert(config != NULL);

    (void)memset(config, 0U, sizeof(*config));

    config->waitTrigEn          = false;
    config->autoChanIncEn        = false;
    config->loopCnt             = 0U;
    config->chanIndex           = 0U;
    config->compValLow          = 0U;
    config->compValHigh         = 0U;
    config->convAvg             = kADC_ConvAvg1;
    config->compMode            = kADC_CompareDisabled;
    config->nextCmdIndex        = kADC_CmdNone;
    config->convSampleTime      = kADC_ConvSampleTime_AdcCycle1;
}

/*!
 * brief Do ADC command configuration.
 *
 * param base ADC peripheral base address.
 * param index ADC command index, @ref adc_cmd_index_t.
 * param config Pointer to ADC commad configuration structure, @ref adc_cmd_config_t.
 */
void ADC_SetCmdConfig(LPADC_Type *base, adc_cmd_index_t index, const adc_cmd_config_t *config)
{
    assert(((uint8_t)index != kADC_CmdNone) && ((uint8_t)index <= kADC_Cmd7));
    assert(config != NULL);

    uint32_t tmpCmdLReg = *(((volatile uint32_t *)(&(base->CMDL1))) + (((uint8_t)index - 1U) * 2U));
    uint32_t tmpCmdHReg = *(((volatile uint32_t *)(&(base->CMDH1))) + (((uint8_t)index - 1U) * 2U));

    tmpCmdLReg = ((tmpCmdLReg & ~LPADC_CMDL1_ADCH_MASK) | LPADC_CMDL1_ADCH(config->chanIndex));
    *(&(base->CMDL1) + (((uint8_t)index - 1U) * 2U)) = tmpCmdLReg;
        
    if (config->waitTrigEn)
    {
        tmpCmdHReg |= LPADC_CMDH1_WAIT_TRIG_MASK;
    }
    else
    {
        tmpCmdHReg &= ~LPADC_CMDH1_WAIT_TRIG_MASK;
    }

    if (config->autoChanIncEn)
    {
        tmpCmdHReg |= LPADC_CMDH1_LWI_MASK;
    }
    else
    {
        tmpCmdHReg &= ~LPADC_CMDH1_LWI_MASK;
    }

    tmpCmdHReg = ((tmpCmdHReg & ~(LPADC_CMDH1_NEXT_MASK | LPADC_CMDH1_LOOP_MASK | LPADC_CMDH1_AVGS_MASK | 
                                  LPADC_CMDH1_STS_MASK)) | (LPADC_CMDH1_NEXT(config->nextCmdIndex) |
                                  LPADC_CMDH1_LOOP(config->loopCnt) | LPADC_CMDH1_AVGS(config->convAvg) |
                                  LPADC_CMDH1_STS(config->convSampleTime)));

    if ((uint8_t)index <= LPADC_CV_COUNT)
    {
        tmpCmdHReg = ((tmpCmdHReg & ~LPADC_CMDH1_CMPEN_MASK) | LPADC_CMDH1_CMPEN(config->compMode));
        base->CV[(uint8_t)index - 1U] = (LPADC_CV_CVH(config->compValHigh) | LPADC_CV_CVL(config->compValLow));
    }
    
    *(&(base->CMDH1) + (((uint8_t)index - 1U) * 2U)) = tmpCmdHReg;
}

/*!
 * brief Do offset calibration.
 *
 * param base ADC peripheral base address.
 */
void ADC_DoOffsetCal(LPADC_Type *base)
{
    ADC_Enable(base, true);
  
    base->CTRL |= LPADC_CTRL_CALOFS_MASK;

    while ((base->STAT & LPADC_STAT_CAL_RDY_MASK) != LPADC_STAT_CAL_RDY_MASK)
    {
    }
    
    ADC_Enable(base, false);
}

/*!
 * brief Get the result in specified conversion FIFO.
 *
 * param base ADC peripheral base address.
 * param result Pointer to ADC result structure, @ref adc_conv_res_t.
 * param index ADC FIFO index, @ref adc_fifo_index_t
 *
 * return Status whether FIFO entry is valid.
 *   b - true Conversion FIFO result is valid.
 *   b - false Conversion FIFO result is invalid.
 */
bool ADC_GetConvRes(LPADC_Type *base, adc_conv_res_t *result, adc_fifo_index_t index)
{
    assert(result != NULL);

    uint32_t tmp32 = 0U;

    tmp32 = *(((volatile uint32_t *)(&(base->RESFIFO0))) + (uint8_t)index);

    if ((tmp32 & LPADC_RESFIFO0_VALID_MASK) != LPADC_RESFIFO0_VALID_MASK)
    {
        return false;
    }

    result->trigSrc = (uint8_t)((tmp32 & LPADC_RESFIFO0_TSRC_MASK) >> LPADC_RESFIFO0_TSRC_SHIFT);
    result->cmdSrc  = (uint8_t)((tmp32 & LPADC_RESFIFO0_CMDSRC_MASK) >> LPADC_RESFIFO0_CMDSRC_SHIFT);
    result->loopCnt = (uint8_t)((tmp32 & LPADC_RESFIFO0_LOOPCNT_MASK) >> LPADC_RESFIFO0_LOOPCNT_SHIFT);
    result->convVal = (uint16_t)((tmp32 & LPADC_RESFIFO0_D_MASK) >> LPADC_RESFIFO0_D_SHIFT);

    return true;
}
