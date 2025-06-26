/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_ADC_H_
#define FSL_ADC_H_

#include "fsl_common.h"

/*!
 * @addtogroup qn_adc
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name Driver version */
/*! @{ */
/*! @brief QN ADC driver version 2.0.2. */
#define FSL_ADC_DRIVER_VERSION (MAKE_VERSION(2, 0, 2))
/*! @} */

/*!
 * @brief Clock source.
 */
typedef enum _adc_clock
{
    kADC_Clock31P25K = 0U, /* ADC clock 31.25K */
    kADC_Clock62P5K,       /* ADC clock 62.5K */
    kADC_Clock125K,        /* ADC clock 125K */
    kADC_Clock250K,        /* ADC clock 250K */
    kADC_Clock500K,        /* ADC clock 500K */
    kADC_Clock1M,          /* ADC clock 1M */
    kADC_Clock2M,          /* ADC clock 2M */
    kADC_Clock32K,         /* ADC clock 32K(Note: 32K clock source) */
} adc_clock_t;

/*!
 * @brief Reference voltage source.
 */
typedef enum _adc_ref_source
{
    kADC_RefSourceBandgapWithDriver = 0U, /*!< Internal 1.2v. */
    kADC_RefSourceExtWithDriver,          /*!< External reference with driver @PA07. */
    kADC_RefSourceExtWithoutDriver,       /*!< External reference without driver @PA07. */
    kADC_RefSourceVccWithDriver,          /*!< VCC. */
} adc_ref_source_t;

/*!
 * @brief Data format
 */
typedef enum _adc_data_format
{
    kADC_DataFormat0WithoutIdx = ((uint32_t)(0U << ADC_CTRL_CH_IDX_EN_SHIFT)), /* Data format0 without channel index */
    kADC_DataFormat0WithIdx    = ((uint32_t)(1U << ADC_CTRL_CH_IDX_EN_SHIFT)), /* Data format0 with channel index */
    kADC_DataFormat1WithoutIdx = ((uint32_t)(2U << ADC_CTRL_CH_IDX_EN_SHIFT)), /* Data format1 without channel index */
    kADC_DataFormat1WithIdx    = ((uint32_t)(3U << ADC_CTRL_CH_IDX_EN_SHIFT)), /* Data format1 with channel index */
    kADC_ForceUnsigned         = 0x80000000U,
} adc_data_format_t;

/*!
 * @brief Cic down sample rate
 */
typedef enum _adc_down_sample
{
    kADC_DownSample32  = 1U, /*!< Down sample 32 */
    kADC_DownSample64  = 3U, /*!< Down sample 64 */
    kADC_DownSample128 = 5U, /*!< Down sample 128 */
    kADC_DownSample256 = 4U, /*!< Down sample 256 */
} adc_down_sample_t;

/*!
 * @brief ADC reference gain
 */
typedef enum _adc_ref_gain
{
    kADC_RefGain1 = 0U, /*!< Reference gain 1 */
    kADC_RefGain1P5,    /*!< Reference gain 1.5 */
} adc_ref_gain_t;

/*!
 * @brief ADC gain
 */
typedef enum _adc_gain
{
    kADC_Gain0P5 = 0U, /*!< ADC gain 0.5 */
    kADC_Gain1,        /*!< ADC gain 1 */
    kADC_Gain1P5,      /*!< ADC gain 1.5 */
    kADC_Gain2,        /*!< ADC gain 2 */
} adc_gain_t;

/*!
 * @brief ADC vinn select
 */
typedef enum _adc_vinn_select
{
    kADC_VinnSelectVref = 0U, /*!< Select Vref as VINN */
    kADC_VinnSelectVref0P75,  /*!< Select 0.75Vref as VINN */
    kADC_VinnSelectVref0P5,   /*!< Select 0.5Vref as VINN */
    kADC_VinnSelectAvss,      /*!< Select AVSS as VINN */
} adc_vinn_select_t;

/*!
 * @brief PGA gain
 */
typedef enum _adc_pga_gain
{
    kADC_PgaBypass = ADC_CFG_PGA_BP(1),   /*!< PGA bypass */
    kADC_PgaGain1  = ADC_CFG_PGA_GAIN(0), /*!< PGA gain 1 */
    kADC_PgaGain2  = ADC_CFG_PGA_GAIN(1), /*!< PGA gain 2 */
    kADC_PgaGain4  = ADC_CFG_PGA_GAIN(2), /*!< PGA gain 4 */
    kADC_PgaGain8  = ADC_CFG_PGA_GAIN(3), /*!< PGA gain 8 */
    kADC_PgaGain16 = ADC_CFG_PGA_GAIN(4), /*!< PGA gain 16 */
} adc_pga_gain_t;

/*!
 * @brief Convert mode
 */
typedef enum _adc_conv_mode
{
    kADC_ConvModeSingle     = (ADC_CTRL_CONV_MODE(1) | ADC_CTRL_SCAN_EN(0)), /*!< Single convert mode */
    kADC_ConvModeBurst      = (ADC_CTRL_CONV_MODE(0) | ADC_CTRL_SCAN_EN(0)), /*!< Burst convert mode */
    kADC_ConvModeSingleScan = (ADC_CTRL_CONV_MODE(1) | ADC_CTRL_SCAN_EN(1)), /*!< Single scan convert mode */
    kADC_ConvModeBurstScan  = (ADC_CTRL_CONV_MODE(0) | ADC_CTRL_SCAN_EN(1)), /*!< Burst scan convert mode */
} adc_conv_mode_t;

/*!
 * @brief PGA adjust direction
 */
typedef enum _adc_pga_adjust_direction
{
    kADC_PgaAdjustMoveDown = 0U, /*!< PGA adjust move down */
    kADC_PgaAdjustMoveUp,        /*!< PGA adjust move up */
} adc_pga_adjust_direction_t;

/*!
 * @brief VCM voltage select
 */
typedef enum _adc_vcm_voltage
{
    kADC_VcmVoltage1D16 = 0U, /*!< VCM voltage selection 1/16VCC */
    kADC_VcmVoltage1D8,       /*!< VCM voltage selection 1/8VCC */
    kADC_VcmVoltage2D8,       /*!< VCM voltage selection 2/8VCC */
    kADC_VcmVoltage3D8,       /*!< VCM voltage selection 3/8VCC */
    kADC_VcmVoltage4D8,       /*!< VCM voltage selection 4/8VCC */
    kADC_VcmVoltage5D8,       /*!< VCM voltage selection 5/8VCC */
    kADC_VcmVoltage6D8,       /*!< VCM voltage selection 6/8VCC */
    kADC_VcmVoltage7D8,       /*!< VCM voltage selection 7/8VCC */
} adc_vcm_voltage_t;

/*!
 * @brief Interrupts
 * @note kADC_InterruptMaskEnable item is the ADC interrupts mask
 */
enum _adc_interrupt_enable
{
    kADC_InterruptMaskEnable      = (int)ADC_INTEN_ADC_INTEN_MASK, /*!< Interrupt enalbe mask */
    kADC_InterruptDataReadyEnable = ADC_INTEN_DAT_RDY_INTEN_MASK,  /*!< Data ready interrupt enable. */
    kADC_InterruptCompareEnable   = ADC_INTEN_WCMP_INTEN_MASK,     /*!< Window comparation interrupt enable. */
    kADC_InterruptOverflowEnable  = ADC_INTEN_FIFO_OF_INTEN_MASK,  /*!< Fifo overflow enable. */
};

/*!
 * @brief Status flag
 */
enum _adc_status_flags
{
    kADC_InterruptFlag     = (int)ADC_INT_ADC_INT_MASK, /*!< Interrupt flag */
    kADC_DataReadyFlag     = ADC_INT_DAT_RDY_INT_MASK,  /*!< Data ready flag */
    kADC_WindowCompareFlag = ADC_INT_WCMP_INT_MASK,     /*!< Window comparation flag */
    kADC_OverflowFlag      = ADC_INT_FIFO_OF_INT_MASK,  /*!< Fifo overflow flag */
};

typedef enum _adc_trigger_select
{
    kADC_TriggerSelectGPIOA0     = 0U,  /*!< GPIOA0 trigger */
    kADC_TriggerSelectGPIOA1     = 1U,  /*!< GPIOA1 trigger */
    kADC_TriggerSelectGPIOA2     = 2U,  /*!< GPIOA2 trigger */
    kADC_TriggerSelectGPIOA3     = 3U,  /*!< GPIOA3 trigger */
    kADC_TriggerSelectGPIOA4     = 4U,  /*!< GPIOA4 trigger */
    kADC_TriggerSelectGPIOA5     = 5U,  /*!< GPIOA5 trigger */
    kADC_TriggerSelectGPIOA6     = 6U,  /*!< GPIOA6 trigger */
    kADC_TriggerSelectGPIOA7     = 7U,  /*!< GPIOA7 trigger */
    kADC_TriggerSelectGPIOA8     = 8U,  /*!< GPIOA8 trigger */
    kADC_TriggerSelectGPIOA9     = 9U,  /*!< GPIOA9 trigger */
    kADC_TriggerSelectGPIOA10    = 10U, /*!< GPIOA10 trigger */
    kADC_TriggerSelectGPIOA11    = 11U, /*!< GPIOA11 trigger */
    kADC_TriggerSelectGPIOA12    = 12U, /*!< GPIOA12 trigger */
    kADC_TriggerSelectGPIOA13    = 13U, /*!< GPIOA13 trigger */
    kADC_TriggerSelectGPIOA14    = 14U, /*!< GPIOA14 trigger */
    kADC_TriggerSelectGPIOA15    = 15U, /*!< GPIOA15 trigger */
    kADC_TriggerSelectGPIOA16    = 16U, /*!< GPIOA16 trigger */
    kADC_TriggerSelectGPIOA17    = 17U, /*!< GPIOA17 trigger */
    kADC_TriggerSelectGPIOA18    = 18U, /*!< GPIOA18 trigger */
    kADC_TriggerSelectGPIOA19    = 19U, /*!< GPIOA19 trigger */
    kADC_TriggerSelectGPIOA20    = 20U, /*!< GPIOA20 trigger */
    kADC_TriggerSelectGPIOA21    = 21U, /*!< GPIOA21 trigger */
    kADC_TriggerSelectGPIOA22    = 22U, /*!< GPIOA22 trigger */
    kADC_TriggerSelectGPIOA23    = 23U, /*!< GPIOA23 trigger */
    kADC_TriggerSelectGPIOA24    = 24U, /*!< GPIOA24 trigger */
    kADC_TriggerSelectGPIOA25    = 25U, /*!< GPIOA25 trigger */
    kADC_TriggerSelectGPIOA26    = 26U, /*!< GPIOA26 trigger */
    kADC_TriggerSelectGPIOA27    = 27U, /*!< GPIOA27 trigger */
    kADC_TriggerSelectGPIOA28    = 28U, /*!< GPIOA28 trigger */
    kADC_TriggerSelectGPIOA29    = 29U, /*!< GPIOA29 trigger */
    kADC_TriggerSelectGPIOA30    = 30U, /*!< GPIOA30 trigger */
    kADC_TriggerSelectGPIOA31    = 31U, /*!< GPIOA31 trigger */
    kADC_TriggerSelectGPIOB0     = 32u, /*!< GPIOB0 trigger */
    kADC_TriggerSelectGPIOB1     = 33u, /*!< GPIOB1 trigger */
    kADC_TriggerSelectGPIOB2     = 34u, /*!< GPIOB2 trigger */
    kADC_TriggerSelectSoftware   = 35U, /*!< Software trigger */
    kADC_TriggerSelectRNG        = 36U, /*!< RNG trigger */
    kADC_TriggerSelectPWMOUT0    = 38U, /*!< PWMOUT0 trigger */
    kADC_TriggerSelectPWMOUT1    = 39U, /*!< PWMOUT1 trigger */
    kADC_TriggerSelectPWMOUT2    = 40U, /*!< PWMOUT2 trigger */
    kADC_TriggerSelectPWMOUT3    = 41U, /*!< PWMOUT3 trigger */
    kADC_TriggerSelectPWMOUT4    = 42U, /*!< PWMOUT4 trigger */
    kADC_TriggerSelectPWMOUT5    = 43U, /*!< PWMOUT5 trigger */
    kADC_TriggerSelectPWMOUT6    = 44U, /*!< PWMOUT6 trigger */
    kADC_TriggerSelectPWMOUT7    = 45U, /*!< PWMOUT7 trigger */
    kADC_TriggerSelectPWMOUT8    = 46U, /*!< PWMOUT8 trigger */
    kADC_TriggerSelectPWMOUT9    = 47U, /*!< PWMOUT9 trigger */
    kADC_TriggerSelectTIMER0OUT0 = 48U, /*!< TIMER0OUT0 trigger */
    kADC_TriggerSelectTIMER0OUT1 = 49U, /*!< TIMER0OUT1 trigger */
    kADC_TriggerSelectTIMER0OUT2 = 50U, /*!< TIMER0OUT2 trigger */
    kADC_TriggerSelectTIMER0OUT3 = 51U, /*!< TIMER0OUT3 trigger */
    kADC_TriggerSelectTIMER1OUT0 = 52U, /*!< TIMER1OUT0 trigger */
    kADC_TriggerSelectTIMER1OUT1 = 53U, /*!< TIMER1OUT1 trigger */
    kADC_TriggerSelectTIMER1OUT2 = 54U, /*!< TIMER1OUT2 trigger */
    kADC_TriggerSelectTIMER1OUT3 = 55U, /*!< TIMER1OUT3 trigger */
    kADC_TriggerSelectTIMER2OUT0 = 56U, /*!< TIMER2OUT0 trigger */
    kADC_TriggerSelectTIMER2OUT1 = 57U, /*!< TIMER2OUT1 trigger */
    kADC_TriggerSelectTIMER2OUT2 = 58U, /*!< TIMER2OUT2 trigger */
    kADC_TriggerSelectTIMER2OUT3 = 59U, /*!< TIMER2OUT3 trigger */
    kADC_TriggerSelectTIMER3OUT0 = 60U, /*!< TIMER3OUT0 trigger */
    kADC_TriggerSelectTIMER3OUT1 = 61U, /*!< TIMER3OUT1 trigger */
    kADC_TriggerSelectTIMER3OUT2 = 62U, /*!< TIMER3OUT2 trigger */
    kADC_TriggerSelectTIMER3OUT3 = 63U, /*!< TIMER3OUT3 trigger */
} adc_trigger_select_t;

/*!
 * @brief Define structure for configuring the block
 */
typedef struct _adc_config
{
    uint32_t channelEnable;             /*!< Channel enable, each bit represent one channel */
    uint32_t channelConfig;             /*!< Channel configure for Sigma Delta(SD) select,
                                            0: indicate the channel use SD configure0
                                            1: indicate the channel use SD configura1. */
    adc_trigger_select_t triggerSource; /*!< Triger source select, only one triger source can be selected. */
    adc_conv_mode_t convMode;           /*!< Convert mode.
                                            Single convert, only one conversion performed and the first channel
                                                from LSB @channelEnable with 1 set will be converted.
                                            Burst convert, stop until ADC enable bit cleared and the first channel
                                                from LSB @channelEnable with 1 set will be converted.
                                            Single Scan convert, scan all channels with 1 set @channelEnable,
                                                automatic stoped after all channels conversion complete.
                                            Burst Scan convert, scan all channels with 1 set @channelEnable,
                                                stop until ADC enable bit cleared */
    adc_clock_t clock;                  /*!< Select the ADC working clock */
    adc_ref_source_t refSource;         /*!< Select the reference voltage source. */
    adc_data_format_t dataFormat;       /*!< Select the Data format */
} adc_config_t;

/*!
 * @brief Define structure for configuring Sigma Delta(SD) block
 */
typedef struct _adc_sd_config
{
    adc_gain_t gain;              /*!< ADC gain */
    adc_ref_gain_t refGain;       /*!< ADC reference gain */
    adc_pga_gain_t pgaGain;       /*!< PGA gain */
    adc_vinn_select_t vinnSelect; /*!< Vinn select, take effect when single-ended channel configured */
    adc_down_sample_t downSample; /*!< Down sample rate */

    adc_pga_adjust_direction_t adjustDirection; /*!< PGA adjust direction */
    uint8_t adjustValue;                        /*!< PGA adjust value,Passing 0 to disable PGA adjust feature
                                                     adjustment = (adjustValue[5] + 1)*(adjustValue[3:0] + 1)*40mv */

    adc_vcm_voltage_t vcmSelect; /*!< ADC input Voltage of Common Mode(VCM) selection */
} adc_sd_config_t;

/*!
 * @brief ADC window comparison configuration.
 */
typedef struct _adc_window_compare_config
{
    int16_t lowValue;  /*!< Setting window low threshold.*/
    int16_t highValue; /*!< Setting window high threshold.*/
} adc_window_compare_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization
 * @{
 */

/*!
 * @brief Initialize the ADC module.
 *
 * This function initializes the ADC module, including:
 *  - Enable ADC module clock.
 *  - Reset ADC module.
 *  - Configure the ADC with user configuration.
 *
 * @param base ADC peripheral base address.
 * @param config Pointer to configuration structure, see to #adc_config_t.
 */
void ADC_Init(ADC_Type *base, const adc_config_t *config);

/*!
 * @brief Deinitialize the ADC module.
 *
 * This function de-nitializes the ADC module, including:
 *  - Disable the ADC module clock.
 *
 * @param base ADC peripheral base address.
 */
void ADC_Deinit(ADC_Type *base);

/*!
 * @brief Gets an available pre-defined settings for initial configuration.
 *
 * This function initializes the initial configuration structure with an available settings. The default values are:
 * @code
 *   config->channelEnable  = 0;
 *   config->channelConfig  = 0;
 *   config->triggerSource  = kADC_TriggerSelectSoftware;
 *   config->convMode       = kADC_ConvModeSingle;
 *   config->clock          = kADC_Clock500K;
 *   config->refSource      = kADC_RefSourceBandgapWithDriver;
 *   config->dataFormat     = kADC_DataFormat1WithIdx;
 * @endcode
 * @param config Pointer to configuration structure.
 */
void ADC_GetDefaultConfig(adc_config_t *config);

/*!
 * @brief Set the sigma delta configuration
 *
 * This function set the sigma delta with user configuration.
 * There are two SD configuration registers, and the idx parameter is used to choose the register.
 *
 * @param base  ADC peripheral base address.
 * @param idx   Configure register index, 0 for register CFG0 and 1 for register CFG1
 * @param config Pointer to the "adc_sd_config_t" structure
 */
void ADC_SetSdConfig(ADC_Type *base, uint8_t idx, const adc_sd_config_t *config);

/*!
 * @brief Gets an available pre-defined settings for SD configuration.
 *
 * This function initializes the initial configuration structure with an available settings. The default values are:
 * @code
 *   config->gain               = kADC_Gain1;
 *   config->refGain            = kADC_RefGain1P5;
 *   config->pgaGain            = kADC_PgaGain1;
 *   config->vinnSelect         = kADC_VinnSelectVref0P75;
 *   config->downSample         = kADC_DownSample256;
 *   config->adjustDirection    = kADC_PgaAdjustMoveDown;
 *   config->adjustValue        = 0;
 *   config->vcmSelect          = kADC_VcmVoltage4D8;
 * @endcode
 * @param config Pointer to configuration structure.
 */
void ADC_GetSdDefaultConfig(adc_sd_config_t *config);

/*!
 * @brief Get Bandgap calibration result.
 *
 * @param base ADC peripheral base address.
 *
 * @return Bandgap voltage in mv.
 */
float ADC_GetBandgapCalibrationResult(ADC_Type *base, uint8_t idx);

/*!
 * @brief Get VINN calibration result.
 *
 * This function is use to measure the VINN value with channel 20.
 *
 * @param base ADC peripheral base address.
 * @param idx Configure register index, 0 for register CFG0 and 1 for register CFG1.
 *
 * @return VINN calibration result.
 */
uint32_t ADC_GetVinnCalibrationResult(ADC_Type *base, const adc_config_t *config);

/*!
 * @brief Get VINN calibration result.
 *
 * This function is use to measure the offset value with channel 15.
 *
 * @param base ADC peripheral base address.
 * @param idx Configure register index, 0 for register CFG0 and 1 for register CFG1.
 *
 * @return Offset calibration result.
 */
uint32_t ADC_GetOffsetCalibrationResult(ADC_Type *base, const adc_config_t *config);

/*!
 * @brief Enable the internal temperature sensor measurement.
 *
 * @param base ADC peripheral base address.
 * @param enable Switcher to enable the feature or not.
 */
static inline void ADC_EnableTemperatureSensor(ADC_Type *base, bool enable)
{
    if (enable)
    {
        base->BG_BF |= ADC_BG_BF_TEMP_EN_MASK;
    }
    else
    {
        base->BG_BF &= ~ADC_BG_BF_TEMP_EN_MASK;
    }
}

/*!
 * @brief Enable the internal battery monitor.
 *
 * @param enable Switcher to enable the feature or not.
 */
static inline void ADC_EnableBatteryMonitor(bool enable)
{
    if (enable)
    {
        SYSCON->ANA_EN |= SYSCON_ANA_EN_BAT_MON_EN_MASK;
    }
    else
    {
        SYSCON->ANA_EN &= ~SYSCON_ANA_EN_BAT_MON_EN_MASK;
    }
}

/*!
 * @brief Configures the window compare mode.
 *
 * @param base     ADC peripheral base address.
 * @param config   Pointer to the "adc_window_compare_config_t" structure. Passing "NULL" disables the feature.
 */
void ADC_WindowCompareConfig(ADC_Type *base, const adc_window_compare_config_t *config);

/*!
 * @brief Enable/Disable the ADC.
 *
 * @param base     ADC peripheral base address.
 * @param enable   true to enable the ADC, false to disable.
 */
static inline void ADC_Enable(ADC_Type *base, bool enable)
{
    volatile uint32_t delayX;

    if (enable)
    {
        base->CTRL |= ADC_CTRL_ENABLE_MASK;
    }
    else
    {
        base->CTRL &= ~ADC_CTRL_ENABLE_MASK;
    }

    /* Note: ADC need one cycle to get ready before triggered */
    for (delayX = 0; delayX < 256; delayX++)
    {
    }
}

/*!
 * @brief Do trigger conversion by software.
 *
 * @param base ADC peripheral base address.
 */
static inline void ADC_DoSoftwareTrigger(ADC_Type *base)
{
    base->CTRL |= ADC_CTRL_SW_START_MASK;
}

/*! @}*/

/*!
 * @name Interrupts.
 * @{
 */

/*!
 * @brief Enable interrupts for conversion sequences.
 *
 * @param base ADC peripheral base address.
 * @param mask Mask value for the interrupts. See "_adc_interrupt_enable".
 */
static inline void ADC_EnableInterrupts(ADC_Type *base, uint32_t mask)
{
    base->INTEN |= mask;
}

/*!
 * @brief Disable interrupts for conversion sequences.
 *
 * @param base ADC peripheral base address.
 * @param mask Mask value for the interrupts. See "_adc_interrupt_enable".
 */
static inline void ADC_DisableInterrupts(ADC_Type *base, uint32_t mask)
{
    base->INTEN &= ~mask;
}

/*! @}*/

/*!
 * @name Status.
 * @{
 */

/*!
 * @brief Get status flags of ADC module.
 *
 * @param base ADC peripheral base address.
 *
 * @return Mask of status flags of module. See "_adc_status_flags".
 */
static inline uint32_t ADC_GetStatusFlags(ADC_Type *base)
{
    return base->INT;
}

/*!
 * @brief Clear status flags of ADC module.
 *
 * @param base ADC peripheral base address.
 * @param mask Mask of status flags of module, see to "_adc_status_flags".
 */
static inline void ADC_ClearStatusFlags(ADC_Type *base, uint32_t mask)
{
    base->INT = mask;
}

/*! @}*/

/*!
 * @name Data result.
 * @{
 */

/*!
 * @brief Get the conversion value.
 *
 * @param base ADC peripheral base address.
 *
 * @return Conversion result value.
 */
static inline uint32_t ADC_GetConversionResult(ADC_Type *base)
{
    return base->DATA;
}

/*!
 * @brief Conversion result to mv.
 *
 * @param base ADC peripheral base address.
 * @param ch ADC channel number.
 * @param idx Configure register index, 0 for register CFG0 and 1 for register CFG1
 * @param verf ADC reference voltage in mv.
 * @param vinn ADC conversion result get from ADC_GetConversionResult function.
 * @param result ADC conversion result get from ADC_GetConversionResult() function.
 *
 * @return Conversion result in mv.
 */
float ADC_ConversionResult2Mv(ADC_Type *base, uint8_t ch, uint8_t idx, float vref, uint32_t vinn, uint32_t result);

/*!
 * @brief Empty conversion buffer.
 *
 * @param base ADC peripheral base address.
 */
static inline void ADC_EmptyChannelConversionBuffer(ADC_Type *base)
{
    while (ADC_GetStatusFlags(base) & kADC_DataReadyFlag)
    {
        (void)base->DATA;
    }
}

/*! @}*/

/*!
 * @name Advanced Features
 * @{
 */

/*!
 * @brief Enable/Disable the signal invert.
 *
 * @param base ADC peripheral base address.
 * @param enable true to enable the signal invert, false to disable.
 */
static inline void ADC_EnableInputSignalInvert(ADC_Type *base, bool enable)
{
    if (enable)
    {
        base->CTRL |= ADC_CTRL_SIG_INV_EN_MASK;
    }
    else
    {
        base->CTRL &= ~ADC_CTRL_SIG_INV_EN_MASK;
    }
}

/*!
 * @brief Enable/Disable the PGA chopper
 *
 * @param base ADC peripheral base address.
 * @param enable true to enable the PGA chopper, false to disable.
 */
static inline void ADC_PgaChopperEnable(ADC_Type *base, bool enable)
{
    if (enable)
    {
        base->BG_BF |= ADC_BG_BF_PGA_CHOP_EN_MASK;
    }
    else
    {
        base->BG_BF &= ~ADC_BG_BF_PGA_CHOP_EN_MASK;
    }
}

/*! @}*/

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */

#endif /* FSL_ADC_H_ */
