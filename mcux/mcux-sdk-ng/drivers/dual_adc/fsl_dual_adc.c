/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_dual_adc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dual_adc"
#endif

#if defined(ADC_RSTS)
#define DUALADC_RESETS_ARRAY ADC_RSTS
#elif defined(ADC_RSTS_N)
#define DUALADC_RESETS_ARRAY ADC_RSTS_N
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Calculate the gain conversion result from the gain calibration value.
 *
 * Gain_Adj = 131072 / (131072 - gainCalValue), encoded into the 17-bit GCR register field as Q1.16.
 *
 * @param gainCalValue Signed gain calibration value within [-32768, 32767] read from the GCC register.
 * @return Gain adjustment calculation result to be written into the GCR register.
 */
static uint32_t DUALADC_CalculateGainResult(int16_t gainCalValue);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Array to map DualADC instance number to base pointer. */
static DADC_Type *const s_dualadcBases[] = DADC_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to DualADC clocks for each DualADC submodule. */
static const clock_ip_name_t s_dualadcClocks[] = ADC_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(DUALADC_RESETS_ARRAY)
/* Reset array */
static const reset_ip_name_t s_dualadcResets[] = DUALADC_RESETS_ARRAY;
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Get the instance for DualADC module.
 *
 * @param base DualADC base address
 * @return Instance number if valid base address is provided, otherwise returns 0xFFFFFFFF
 */
uint32_t DUALADC_GetInstance(DADC_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_dualadcBases); instance++)
    {
        if (MSDK_REG_NONSECURE_ADDR(s_dualadcBases[instance]) == MSDK_REG_NONSECURE_ADDR(base))
        {
            break;
        }
    }

    if (instance == ARRAY_SIZE(s_dualadcBases))
    {
        instance = 0xFFFFFFFFU; /* Return 0xFFFFFFFF if invalid base address is provided. */
    }

    return instance;
}

/*!
 * @brief Populate a dadc_config_t with reset-state defaults.
 *
 * @param config Pointer to the configuration structure to populate.
 */
void DUALADC_GetDefaultConfig(dadc_config_t *config)
{
    assert(NULL != config);

    /* CFG0 - Configuration 0 Register */
    config->conversionMode          = kDADC_CooperationMode;
    config->powerConfig             = kDADC_LowPowerConfig;
    config->enableAnalogPreEnable   = false;
    config->refVoltageSource        = kDADC_VrefH0;
    config->powerUpDelayCount       = 0x80U;
    config->triggerSource           = kDADC_TrigSelTrigger0;

    /* CFG1 - Configuration 1 Register */
    config->enableLeftJustify       = false;
    config->enableHighSpeedMode     = false;
    config->enableHighSpeedExtra    = false;
    config->tuneMode                = kDADC_TuneMode1;

    /* CTRL - Control Register */
    config->enableDoze              = false;
    config->enableLongCalSampleTime = false;
    config->calibrationAverages     = kDADC_CalibrationAverage256;

    /* PAUSE - Pause Register */
    config->enableConversionPause   = false;
    config->conversionPauseDelay    = 0U;

    /* TCTRL - Trigger Control Register */
    config->enableHardwareTrigger0  = false;
    config->hardwareTrigger0Delay   = 0U;
    config->enableHardwareTrigger1  = false;
    config->hardwareTrigger1Delay   = 0U;

    /* DE - DMA trigger source */
    config->dmaSourceA              = kDADC_DmaSrcEndOfScan;
    config->dmaSourceB              = kDADC_DmaSrcEndOfScan;
}

/*!
 * @brief Initialize the DualADC module.
 *
 * @param base   DualADC peripheral base address.
 * @param config Pointer to the initialization configuration.
 * @retval kStatus_Success           Initialization succeeded.
 * @retval kStatus_InvalidArgument   @p base is not a valid DualADC peripheral address.
 * @retval kStatus_Timeout           Reset operation times out.
 */
status_t DUALADC_Init(DADC_Type *base, const dadc_config_t *config)
{
    assert(NULL != config);

    uint32_t instance = DUALADC_GetInstance(base);
    uint32_t reg;

    if (instance >= ARRAY_SIZE(s_dualadcBases))
    {
        return kStatus_InvalidArgument;
    }

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Ungate the DualADC submodule clock. */
    CLOCK_EnableClock(s_dualadcClocks[instance]);
#endif

#if defined(DUALADC_RESETS_ARRAY)
    RESET_ReleasePeripheralReset(s_dualadcResets[instance]);
#endif

    base->CTRL |= (DADC_CTRL_RSTA_MASK | DADC_CTRL_RSTB_MASK);

    /* Add a short delay to ensure reset completion. */
    for (uint32_t i = 0; i < DUALADC_RESET_TIMEOUT; i++)
    {
        __NOP();
    }

    base->CTRL &= MCUX_MASK_INVERT_32(DADC_CTRL_RSTA_MASK | DADC_CTRL_RSTB_MASK);

    /* Disable the module before setting configuration. */
    base->CTRL &= MCUX_MASK_INVERT_32(DADC_CTRL_ADCEN_MASK);

    /* Configure CFG0: conversion mode, power, analog pre-enable, voltage reference, power-up delay, trigger source. */
    reg = base->CFG0;
    reg &= MCUX_MASK_INVERT_32(DADC_CFG0_INDEP_MASK | DADC_CFG0_TRIGSEL_MASK | DADC_CFG0_PWRSEL_MASK |
                               DADC_CFG0_PWREN_MASK | DADC_CFG0_REFSEL_MASK | DADC_CFG0_PUDLY_MASK);
    reg |= DADC_CFG0_INDEP(config->conversionMode) |
           DADC_CFG0_PWRSEL(config->powerConfig) |
           DADC_CFG0_REFSEL(config->refVoltageSource) |
           DADC_CFG0_PUDLY(config->powerUpDelayCount) |
           DADC_CFG0_TRIGSEL(config->triggerSource);
    reg |= config->enableAnalogPreEnable ? DADC_CFG0_PWREN_MASK : 0U;
    base->CFG0 = reg;

    /* Configure CFG1: result justification, high-speed mode, extra cycle, tune mode. */
    reg = base->CFG1;
    reg &= MCUX_MASK_INVERT_32(DADC_CFG1_JLEFT_MASK | DADC_CFG1_HS_MASK | DADC_CFG1_HSEXTRA_MASK |
                               DADC_CFG1_TUNE_MASK);
    reg |= DADC_CFG1_TUNE(config->tuneMode);
    reg |= config->enableLeftJustify ? DADC_CFG1_JLEFT_MASK : 0U;
    reg |= config->enableHighSpeedMode ? DADC_CFG1_HS_MASK : 0U;
    reg |= config->enableHighSpeedExtra ? DADC_CFG1_HSEXTRA_MASK : 0U;
    base->CFG1 = reg;

    /*
     * Configure CTRL: doze behavior, calibration sample time, calibration averages.
     * Calibration request bits (CAL_REQ, CALOFS, CALHS) are left at zero; ADCEN is excluded here.
     */
    reg = base->CTRL;
    reg &= MCUX_MASK_INVERT_32(DADC_CTRL_DOZEN_MASK | DADC_CTRL_CST_LONG_MASK | DADC_CTRL_CAL_AVGS_MASK);
    reg |= DADC_CTRL_CAL_AVGS(config->calibrationAverages);
    reg |= config->enableDoze ? DADC_CTRL_DOZEN_MASK : 0U;
    reg |= config->enableLongCalSampleTime ? DADC_CTRL_CST_LONG_MASK : 0U;
    base->CTRL = reg;

    /* Configure PAUSE before ADCEN is asserted. */
    reg = base->PAUSE;
    reg &= MCUX_MASK_INVERT_32(DADC_PAUSE_PAUSEEN_MASK | DADC_PAUSE_PAUSEDLY_MASK);
    reg |= config->enableConversionPause ? DADC_PAUSE_PAUSEEN_MASK : 0U;
    reg |= DADC_PAUSE_PAUSEDLY(config->conversionPauseDelay);
    base->PAUSE = reg;

    /* Configure TCTRL: hardware trigger enable and trigger delay for Trigger0 and Trigger1. */
    reg = base->TCTRL;
    reg &= MCUX_MASK_INVERT_32(DADC_TCTRL_HTEN0_MASK | DADC_TCTRL_TDLY0_MASK |
                               DADC_TCTRL_HTEN1_MASK | DADC_TCTRL_TDLY1_MASK);
    reg |= DADC_TCTRL_TDLY0(config->hardwareTrigger0Delay) |
           DADC_TCTRL_TDLY1(config->hardwareTrigger1Delay);
    reg |= config->enableHardwareTrigger0 ? DADC_TCTRL_HTEN0_MASK : 0U;
    reg |= config->enableHardwareTrigger1 ? DADC_TCTRL_HTEN1_MASK : 0U;
    base->TCTRL = reg;

    /*
     * Configure DMA trigger sources (DE[DMASRCA/B]). DMAENAA/B are not set here;
     * call DUALADC_EnableDmaA/B at runtime when DMA transfers should begin.
     */
    reg = base->DE;
    reg &= MCUX_MASK_INVERT_32(DADC_DE_DMASRCA_MASK | DADC_DE_DMASRCB_MASK);
    reg |= DADC_DE_DMASRCA(config->dmaSourceA) | DADC_DE_DMASRCB(config->dmaSourceB);
    base->DE = reg;

    return kStatus_Success;
}

/*!
 * @brief Deinitialize the DualADC module.
 *
 * @param base DualADC peripheral base address.
 * @retval kStatus_Success           Deinitialization succeeded.
 * @retval kStatus_InvalidArgument   @p base is not a valid DualADC peripheral address.
 */
status_t DUALADC_DeInit(DADC_Type *base)
{
    uint32_t instance = DUALADC_GetInstance(base);

    if (instance >= ARRAY_SIZE(s_dualadcBases))
    {
        /* Invalid instance, do not attempt to deinitialize */
        return kStatus_InvalidArgument;
    }

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Gate the DualADC submodule clock. */
    CLOCK_DisableClock(s_dualadcClocks[instance]);
#endif

#if defined(DUALADC_RESETS_ARRAY)
    RESET_PeripheralReset(s_dualadcResets[instance]);
#endif

    return kStatus_Success;
}

/*!
 * @brief Populate a dadc_cmd_config_t with reset-state defaults.
 *
 * @param config Pointer to the command configuration structure to populate.
 */
void DUALADC_GetDefaultConversionCommandConfig(dadc_cmd_config_t *config)
{
    assert(NULL != config);

    config->conversionType    = kDADC_ConversionSingleEndedA;
    config->resolutionMode    = kDADC_ResolutionStandard;
    config->sampleTimeMode    = kDADC_SampleTime3_5;
    config->hardwareAverages  = kDADC_HardwareAverageSingle;
    config->channelNumber     = 0U;
    config->enableAltBChannel = false;
    config->altBChannelNumber = 0U;
    config->enableCompare     = false;
    config->compareValueHigh  = 0U;
    config->compareValueLow   = 0U;
    config->enableWaitTrigger = false;
}

/*!
 * @brief Configure a DualADC conversion command buffer entry.
 *
 * @param base DualADC peripheral base address.
 * @param index Command buffer index, range 1-20 (maps to CMD[0]-CMD[19]).
 * @param config Pointer to the command configuration.
 */
void DUALADC_ConfigConversionCommand(DADC_Type *base, uint32_t index, const dadc_cmd_config_t *config)
{
    assert(NULL != config);
    assert(index >= 1U && index <= DADC_CMD_COUNT);

    uint32_t reg;

    index--; /* Convert to zero-based index for CMD/CV arrays. */

    /* Configure CMD register via read-modify-write; CDIS is excluded and managed separately. */
    reg = base->CMD[index];
    reg &= MCUX_MASK_INVERT_32(DADC_CMD_CMPEN_MASK | DADC_CMD_WAIT_TRIG_MASK | DADC_CMD_CTYPE_MASK |
                               DADC_CMD_MODE_MASK | DADC_CMD_STS_MASK | DADC_CMD_AVGS_MASK |
                               DADC_CMD_ADCH_MASK | DADC_CMD_ALTB_ADCH_MASK | DADC_CMD_ALTB_EN_MASK);
    reg |= DADC_CMD_CTYPE(config->conversionType) |
           DADC_CMD_MODE(config->resolutionMode) |
           DADC_CMD_STS(config->sampleTimeMode) |
           DADC_CMD_AVGS(config->hardwareAverages) |
           DADC_CMD_ADCH(config->channelNumber) |
           DADC_CMD_ALTB_ADCH(config->altBChannelNumber);
    reg |= config->enableAltBChannel ? DADC_CMD_ALTB_EN_MASK : 0U;
    reg |= config->enableCompare ? DADC_CMD_CMPEN_MASK : 0U;
    reg |= config->enableWaitTrigger ? DADC_CMD_WAIT_TRIG_MASK : 0U;
    base->CMD[index] = reg;

    /* Write compare values to the corresponding CV register when compare is enabled. */
    if (config->enableCompare)
    {
        assert(index < DADC_CV_COUNT);
        base->CV[index] = DADC_CV_CVL(config->compareValueLow) | DADC_CV_CVH(config->compareValueHigh);
    }
}

/*!
 * @brief Populate a dadc_avgt_config_t with reset-state defaults.
 *
 * @param config Pointer to the configuration structure to populate.
 */
void DUALADC_GetDefaultAverageTimerConfig(dadc_avgt_config_t *config)
{
    assert(NULL != config);

    config->enableAvgTimerA = false;
    config->repeatCountA    = 1U;
    config->intervalA       = 0U;
    config->prescalerA      = kDADC_AvgtPrescaler1;
    config->enableAvgTimerB = false;
    config->repeatCountB    = 1U;
    config->intervalB       = 0U;
    config->prescalerB      = kDADC_AvgtPrescaler1;
}

/*!
 * @brief Configure the average-with-timer feature.
 *
 * @param base   DualADC peripheral base address.
 * @param config Pointer to the average-with-timer configuration.
 */
void DUALADC_ConfigAverageTimer(DADC_Type *base, const dadc_avgt_config_t *config)
{
    assert(NULL != config);
    assert(config->repeatCountA >= 1U && config->repeatCountA <= 512U);
    assert(config->repeatCountB >= 1U && config->repeatCountB <= 512U);

    uint32_t reg;

    /* Configure AVGT_CTRL: enable flags and repeat counts for ADCA and ADCB. */
    reg = base->AVGT_CTRL;
    reg &= MCUX_MASK_INVERT_32(DADC_AVGT_CTRL_AVGTA_EN_MASK | DADC_AVGT_CTRL_AVGTA_TIMES_MASK |
                               DADC_AVGT_CTRL_AVGTB_EN_MASK | DADC_AVGT_CTRL_AVGTB_TIMES_MASK);
    reg |= DADC_AVGT_CTRL_AVGTA_TIMES(config->repeatCountA - 1U) |
           DADC_AVGT_CTRL_AVGTB_TIMES(config->repeatCountB - 1U);
    reg |= config->enableAvgTimerA ? DADC_AVGT_CTRL_AVGTA_EN_MASK : 0U;
    reg |= config->enableAvgTimerB ? DADC_AVGT_CTRL_AVGTB_EN_MASK : 0U;
    base->AVGT_CTRL = reg;

    /* Configure ITCFG: interval counts and prescalers for ADCA and ADCB. */
    reg = base->ITCFG;
    reg &= MCUX_MASK_INVERT_32(DADC_ITCFG_PRESCALERA_MASK | DADC_ITCFG_INTERVALA_MASK |
                               DADC_ITCFG_PRESCALERB_MASK | DADC_ITCFG_INTERVALB_MASK);
    reg |= DADC_ITCFG_PRESCALERA(config->prescalerA) |
           DADC_ITCFG_INTERVALA(config->intervalA) |
           DADC_ITCFG_PRESCALERB(config->prescalerB) |
           DADC_ITCFG_INTERVALB(config->intervalB);
    base->ITCFG = reg;
}

/*!
 * @brief Calculate the gain conversion result from the gain calibration value.
 *
 * Gain_Adj = 131072 / (131072 - gainCalValue), encoded into the 17-bit GCR register field as Q1.16.
 *
 * @param gainCalValue Signed gain calibration value within [-32768, 32767] read from the GCC register.
 * @return Gain adjustment calculation result to be written into the GCR register.
 */
static uint32_t DUALADC_CalculateGainResult(int16_t gainCalValue)
{
    uint32_t gainConvResult;
    int32_t denominator;

    denominator = 131072 - gainCalValue;

    /*
     * Fixed point formula equivalent to 131072.0 / (131072.0 - gainCalValue).
     * Numerator is 131072 * 16384 = 2147483648 exactly; uint32_t division yields Q17.14.
     * Shifting left by 2 converts it to the Q1.16 encoding of the 17-bit GCR field; its two
     * LSBs stay zero.
     */
    gainConvResult = 2147483648UL / (uint32_t)denominator; /* Q17.14 */

    return ((gainConvResult << 2UL) & 0x1FFFFUL);   /* Q1.16 */
}

/*!
 * @brief Perform all DualADC calibration routines.
 *
 * Must be called after @ref DUALADC_Enable to ensure ADC enabled.
 *
 * @param base DualADC peripheral base address.
 * @retval kStatus_Success  All calibration steps completed successfully.
 * @retval kStatus_Timeout  A calibration poll loop exceeded @ref DUALADC_CALIBRATION_TIMEOUT
 *                          iterations (only possible when the timeout is non-zero).
 */
status_t DUALADC_DoCalibration(DADC_Type *base)
{
    int16_t GCCa;
    int16_t GCCb;
    uint32_t GCRa;
    uint32_t GCRb;
#if DUALADC_CALIBRATION_TIMEOUT
    uint32_t timeout;
#endif
    bool adcEnabled = ((base->CTRL & DADC_CTRL_ADCEN_MASK) != 0U);

    /* Enable ADC before calibration routines. */
    if (!adcEnabled)
    {
        base->CTRL |= DADC_CTRL_ADCEN_MASK;
    }

    /* Step 1: Offset calibration - hardware updates OFSTRIM automatically. */
    base->CTRL |= DADC_CTRL_CALOFS_MASK;
#if DUALADC_CALIBRATION_TIMEOUT
    timeout = DUALADC_CALIBRATION_TIMEOUT;
#endif
    while ((base->STAT0 & DADC_STAT0_CAL_RDY_MASK) == 0U)
    {
#if DUALADC_CALIBRATION_TIMEOUT
        if (--timeout == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

    /* Step 2: High-speed calibration - only required when CFG1[HS] is set. */
    if ((base->CFG1 & DADC_CFG1_HS_MASK) != 0U)
    {
        base->CTRL |= DADC_CTRL_CALHS_MASK;
#if DUALADC_CALIBRATION_TIMEOUT
        timeout = DUALADC_CALIBRATION_TIMEOUT;
#endif
        while ((base->STAT0 & DADC_STAT0_CAL_RDY_MASK) == 0U)
        {
#if DUALADC_CALIBRATION_TIMEOUT
            if (--timeout == 0U)
            {
                return kStatus_Timeout;
            }
#endif
        }
    }

    /* Step 3: Gain and linearity calibration. */
    /* Initiate calibration; CAL_REQ auto-clears when accepted by hardware. */
    base->CTRL |= DADC_CTRL_CAL_REQ_MASK;

    /* Wait for hardware to complete ADCA and ADCB gain calibration. */
#if DUALADC_CALIBRATION_TIMEOUT
    timeout = DUALADC_CALIBRATION_TIMEOUT;
#endif
    while (((base->GCC[0] & DADC_GCC_RDY_MASK) == 0U) || ((base->GCC[1] & DADC_GCC_RDY_MASK) == 0U))
    {
#if DUALADC_CALIBRATION_TIMEOUT
        if (--timeout == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

    /* Read 16-bit signed GAIN_CAL; casting to int16_t performs sign extension. */
    GCCa = (int16_t)((base->GCC[0] & DADC_GCC_GAIN_CAL_MASK) & 0xFFFF);
    GCCb = (int16_t)((base->GCC[1] & DADC_GCC_GAIN_CAL_MASK) & 0xFFFF);

    GCRa = DUALADC_CalculateGainResult(GCCa);
    GCRb = DUALADC_CalculateGainResult(GCCb);

    /* Calculate gain adjustment and write 17-bit fixed-point result to GCR. */
    base->GCR[0] = (GCRa | DADC_GCR_RDY_MASK);
    base->GCR[1] = (GCRb | DADC_GCR_RDY_MASK);

    /* Wait for final CAL_RDY to confirm full calibration is complete. */
#if DUALADC_CALIBRATION_TIMEOUT
    timeout = DUALADC_CALIBRATION_TIMEOUT;
#endif
    while ((base->STAT0 & DADC_STAT0_CAL_RDY_MASK) == 0U)
    {
#if DUALADC_CALIBRATION_TIMEOUT
        if (--timeout == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

    /* Restore ADC enable state after calibration routines. */
    if (!adcEnabled)
    {
        base->CTRL &= MCUX_MASK_INVERT_32(DADC_CTRL_ADCEN_MASK);
    }

    return kStatus_Success;
}

/*!
 * @brief Restore calibration registers from a previously saved calibration value structure.
 *
 * @param base DualADC peripheral base address.
 * @param ptrCalibrationValue Pointer to the calibration value structure.
 */
void DUALADC_SetCalibrationValue(DADC_Type *base, const dadc_calibration_value_t *ptrCalibrationValue)
{
    assert(NULL != ptrCalibrationValue);

    uint32_t i;
    bool adcEnabled = ((base->CTRL & DADC_CTRL_ADCEN_MASK) != 0U);

    /* Disable ADC during calibration register writes to prevent instability. */
    if (adcEnabled)
    {
        base->CTRL &= MCUX_MASK_INVERT_32(DADC_CTRL_ADCEN_MASK);
    }

    /* Restore offset trim values for ADCA and ADCB. */
    base->OFSTRIM = DADC_OFSTRIM_OFSTRIMA(ptrCalibrationValue->offsetTrimA) |
                    DADC_OFSTRIM_OFSTRIMB(ptrCalibrationValue->offsetTrimB);

    /* Restore high-speed trim values for ADCA and ADCB. */
    base->HSTRIM = DADC_HSTRIM_HSTRIMA(ptrCalibrationValue->highSpeedTrimA) |
                   DADC_HSTRIM_HSTRIMB(ptrCalibrationValue->highSpeedTrimB);

    /* Restore linearity calibration tables for ADCA and ADCB. */
    for (i = 0U; i < DADC_CAL_GAR_COUNT; i++)
    {
        base->CAL_GAR[i] = ptrCalibrationValue->calGar[i];
        base->CAL_GBR[i] = ptrCalibrationValue->calGbr[i];
    }

    /* Restore gain calibration results and mark them valid so hardware uses them. */
    base->GCR[0] = DADC_GCR_GCALR(ptrCalibrationValue->gcalr[0]) | DADC_GCR_RDY_MASK;
    base->GCR[1] = DADC_GCR_GCALR(ptrCalibrationValue->gcalr[1]) | DADC_GCR_RDY_MASK;

    if (adcEnabled)
    {
        base->CTRL |= DADC_CTRL_ADCEN_MASK;
    }
}
