/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_DAC_H_
#define FSL_DAC_H_

#include "fsl_common.h"

/*!
 * @addtogroup qn_dac
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name Driver version */
/*! @{ */
/*! @brief DAC driver version 2.0.1. */
#define FSL_DAC_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/*! @brief the current bias of the DAC */
typedef enum _dac_amp
{
    kDAC_Amplitude50pct  = 0U,
    kDAC_Amplitude75pct  = 1U,
    kDAC_Amplitude100pct = 2U,
    kDAC_Amplitude125pct = 3U,
    kDAC_Amplitude150pct = 4U,
    kDAC_Amplitude175pct = 5U,
    kDAC_Amplitude200pct = 6U,
    kDAC_Amplitude225pct = 7U
} dac_amp_t;

/*! @brief The Miller compensation capacitance of the OPAMP */
typedef enum _dac_filter_bandwidth
{
    kDAC_FilterBandwidth56FF        = 0U, /*!< 1K~1.4K*/
    kDAC_FilterBandwidth97Point6FF  = 1U, /*!< 1.4K~3K*/
    kDAC_FilterBandwidth141Point5FF = 2U, /*!< 3K~11K*/
    kDAC_FilterBandwidth183Point1FF = 3U  /*!< >11k*/
} dac_filter_bandwidth_t;

/*! @brief Set the filter type and bandwidth */
typedef enum _dac_filter_150k_en
{
    kDAC_Filter150kEnable1Mhz   = 0U,
    kDAC_Filter150kEnable150Khz = 1U
} dac_filter_150k_en_t;

/*! @brief Set the common mode voltage of the filter output. */
typedef enum _dac_voltage_common_mode
{
    kDAC_VoltageCommonMode800mv  = 0U,  /*!< Analog output common mode voltage 800mv*/
    kDAC_VoltageCommonMode900mv  = 1U,  /*!< Analog output common mode voltage 900mv*/
    kDAC_VoltageCommonMode1000mv = 2U,  /*!< Analog output common mode voltage 1000mv*/
    kDAC_VoltageCommonMode1100mv = 3U,  /*!< Analog output common mode voltage 1100mv*/
    kDAC_VoltageCommonMode1200mv = 4U,  /*!< Analog output common mode voltage 1200mv*/
    kDAC_VoltageCommonMode1300mv = 5U,  /*!< Analog output common mode voltage 1300mv*/
    kDAC_VoltageCommonMode1400mv = 6U,  /*!< Analog output common mode voltage 1400mv*/
    kDAC_VoltageCommonMode1500mv = 7U,  /*!< Analog output common mode voltage 1500mv*/
    kDAC_VoltageCommonMode1600mv = 8U,  /*!< Analog output common mode voltage 1600mv*/
    kDAC_VoltageCommonMode1700mv = 9U,  /*!< Analog output common mode voltage 1700mv*/
    kDAC_VoltageCommonMode1800mv = 10U, /*!< Analog output common mode voltage 1800mv*/
    kDAC_VoltageCommonMode1900mv = 11U, /*!< Analog output common mode voltage 1900mv*/
    kDAC_VoltageCommonMode2000mv = 12U, /*!< Analog output common mode voltage 2000mv*/
    kDAC_VoltageCommonMode2100mv = 13U, /*!< Analog output common mode voltage 2100mv*/
    kDAC_VoltageCommonMode2200mv = 14U, /*!< Analog output common mode voltage 2200mv*/
    kDAC_VoltageCommonMode2300mv = 15U  /*!< Analog output common mode voltage 2300mv*/
} dac_voltage_common_mode_t;

/*! @brief DAC module. */
typedef enum _dac_enable
{
    kDAC_Disable = 0U, /*!< DAC module disable*/
    kDAC_Enable  = 1U  /*!< DAC module enable*/

} dac_enable_t;

/*! @brief Sin Wave .*/
typedef enum _dac_sin_enable
{
    kDAC_SinWaveDisable = 0U, /*!< Sin wave module disable*/
    kDAC_SinWaveEnable  = 1U  /*!< Sin wave module enable*/

} dac_sin_enable_t;

/*! @brief Modulator .*/
typedef enum _dac_modulator_enable
{
    kDAC_ModulatorDisable = 0U, /*!< Modulator disable*/
    kDAC_ModulatorEnable  = 1U  /*!< Modulator enable*/

} dac_modulator_enable_t;

/*! @brief Modulator output width. */
typedef enum _dac_modulator_output_width
{
    kDAC_ModulatorWidth1bit = 0U, /*!< feed back 1 bit*/
    kDAC_ModulatorWidth8bit = 1U  /*!< feed back 8 bit*/

} dac_modulator_output_width_t;

/*! @brief sigma delta modulator sample rate */
typedef enum _dac_sample_rate
{
    kDAC_SampleRate8    = 0U,
    kDAC_SampleRate16   = 1U,
    kDAC_SampleRate32   = 2U,
    kDAC_SampleRate64   = 3U,
    kDAC_SampleRate128  = 4U,
    kDAC_SampleRate256  = 5U,
    kDAC_SampleRate512  = 6U,
    kDAC_SampleRate1024 = 7U,
} dac_sample_rate_t;

/*! @brief FIFO output data align, when no modulation mode. */
typedef enum _dac_buffer_out_align
{
    kDAC_BufferOutAlignRight = 0U, /*!< right align*/
    kDAC_BufferOutAlignLeft  = 1U  /*!< left align*/

} dac_buffer_out_align_t;

/*! @brief Input data align mode. */
typedef enum _dac_buffer_in_align
{
    kDAC_BufferInAlignRight = 0U, /*!< right align*/
    kDAC_BufferInAlignLeft  = 1U  /*!< left align*/

} dac_buffer_in_align_t;

/*! @brief Trigger mode */
typedef enum _dac_trigger_mode
{
    kDAC_TriggerModeSingleMode   = 0U, /*!< single model*/
    kDAC_TriggerModeContinueMode = 1U  /*!< continue model*/

} dac_trigger_mode_t;

/*! @brief The edge of trigger signal is used to start the DAC conversion. */
typedef enum _dac_trigger_edge_select
{
    kDAC_TriggerEdgeSelectPositiveEdge = 0U, /*!< positive edge*/
    kDAC_TriggerEdgeSelectNegativeEdge = 1U, /*!< negative edge*/
    kDAC_TriggerEdgeSelectBothEdge     = 2U  /*!< both edge*/

} dac_trigger_edge_select_t;

typedef enum _dac_trigger_select
{
    kDAC_TriggerSelectGPIOA0     = 0U,  /*!< GPIOA0 trigger */
    kDAC_TriggerSelectGPIOA1     = 1U,  /*!< GPIOA1 trigger */
    kDAC_TriggerSelectGPIOA2     = 2U,  /*!< GPIOA2 trigger */
    kDAC_TriggerSelectGPIOA3     = 3U,  /*!< GPIOA3 trigger */
    kDAC_TriggerSelectGPIOA4     = 4U,  /*!< GPIOA4 trigger */
    kDAC_TriggerSelectGPIOA5     = 5U,  /*!< GPIOA5 trigger */
    kDAC_TriggerSelectGPIOA6     = 6U,  /*!< GPIOA6 trigger */
    kDAC_TriggerSelectGPIOA7     = 7U,  /*!< GPIOA7 trigger */
    kDAC_TriggerSelectGPIOA8     = 8U,  /*!< GPIOA8 trigger */
    kDAC_TriggerSelectGPIOA9     = 9U,  /*!< GPIOA9 trigger */
    kDAC_TriggerSelectGPIOA10    = 10U, /*!< GPIOA10 trigger */
    kDAC_TriggerSelectGPIOA11    = 11U, /*!< GPIOA11 trigger */
    kDAC_TriggerSelectGPIOA12    = 12U, /*!< GPIOA12 trigger */
    kDAC_TriggerSelectGPIOA13    = 13U, /*!< GPIOA13 trigger */
    kDAC_TriggerSelectGPIOA14    = 14U, /*!< GPIOA14 trigger */
    kDAC_TriggerSelectGPIOA15    = 15U, /*!< GPIOA15 trigger */
    kDAC_TriggerSelectGPIOA16    = 16U, /*!< GPIOA16 trigger */
    kDAC_TriggerSelectGPIOA17    = 17U, /*!< GPIOA17 trigger */
    kDAC_TriggerSelectGPIOA18    = 18U, /*!< GPIOA18 trigger */
    kDAC_TriggerSelectGPIOA19    = 19U, /*!< GPIOA19 trigger */
    kDAC_TriggerSelectGPIOA20    = 20U, /*!< GPIOA20 trigger */
    kDAC_TriggerSelectGPIOA21    = 21U, /*!< GPIOA21 trigger */
    kDAC_TriggerSelectGPIOA22    = 22U, /*!< GPIOA22 trigger */
    kDAC_TriggerSelectGPIOA23    = 23U, /*!< GPIOA23 trigger */
    kDAC_TriggerSelectGPIOA24    = 24U, /*!< GPIOA24 trigger */
    kDAC_TriggerSelectGPIOA25    = 25U, /*!< GPIOA25 trigger */
    kDAC_TriggerSelectGPIOA26    = 26U, /*!< GPIOA26 trigger */
    kDAC_TriggerSelectGPIOA27    = 27U, /*!< GPIOA27 trigger */
    kDAC_TriggerSelectGPIOA28    = 28U, /*!< GPIOA28 trigger */
    kDAC_TriggerSelectGPIOA29    = 29U, /*!< GPIOA29 trigger */
    kDAC_TriggerSelectGPIOA30    = 30U, /*!< GPIOA30 trigger */
    kDAC_TriggerSelectGPIOA31    = 31U, /*!< GPIOA31 trigger */
    kDAC_TriggerSelectGPIOB0     = 32u, /*!< GPIOB0 trigger */
    kDAC_TriggerSelectGPIOB1     = 33u, /*!< GPIOB1 trigger */
    kDAC_TriggerSelectGPIOB2     = 34u, /*!< GPIOB2 trigger */
    kDAC_TriggerSelectSoftware   = 35U, /*!< Software trigger */
    kDAC_TriggerSelectPWMOUT0    = 38U, /*!< PWMOUT0 trigger */
    kDAC_TriggerSelectPWMOUT1    = 39U, /*!< PWMOUT1 trigger */
    kDAC_TriggerSelectPWMOUT2    = 40U, /*!< PWMOUT2 trigger */
    kDAC_TriggerSelectPWMOUT3    = 41U, /*!< PWMOUT3 trigger */
    kDAC_TriggerSelectPWMOUT4    = 42U, /*!< PWMOUT4 trigger */
    kDAC_TriggerSelectPWMOUT5    = 43U, /*!< PWMOUT5 trigger */
    kDAC_TriggerSelectPWMOUT6    = 44U, /*!< PWMOUT6 trigger */
    kDAC_TriggerSelectPWMOUT7    = 45U, /*!< PWMOUT7 trigger */
    kDAC_TriggerSelectPWMOUT8    = 46U, /*!< PWMOUT8 trigger */
    kDAC_TriggerSelectPWMOUT9    = 47U, /*!< PWMOUT9 trigger */
    kDAC_TriggerSelectTIMER0OUT0 = 48U, /*!< TIMER0OUT0 trigger */
    kDAC_TriggerSelectTIMER0OUT1 = 49U, /*!< TIMER0OUT1 trigger */
    kDAC_TriggerSelectTIMER0OUT2 = 50U, /*!< TIMER0OUT2 trigger */
    kDAC_TriggerSelectTIMER0OUT3 = 51U, /*!< TIMER0OUT3 trigger */
    kDAC_TriggerSelectTIMER1OUT0 = 52U, /*!< TIMER1OUT0 trigger */
    kDAC_TriggerSelectTIMER1OUT1 = 53U, /*!< TIMER1OUT1 trigger */
    kDAC_TriggerSelectTIMER1OUT2 = 54U, /*!< TIMER1OUT2 trigger */
    kDAC_TriggerSelectTIMER1OUT3 = 55U, /*!< TIMER1OUT3 trigger */
    kDAC_TriggerSelectTIMER2OUT0 = 56U, /*!< TIMER2OUT0 trigger */
    kDAC_TriggerSelectTIMER2OUT1 = 57U, /*!< TIMER2OUT1 trigger */
    kDAC_TriggerSelectTIMER2OUT2 = 58U, /*!< TIMER2OUT2 trigger */
    kDAC_TriggerSelectTIMER2OUT3 = 59U, /*!< TIMER2OUT3 trigger */
    kDAC_TriggerSelectTIMER3OUT0 = 60U, /*!< TIMER3OUT0 trigger */
    kDAC_TriggerSelectTIMER3OUT1 = 61U, /*!< TIMER3OUT1 trigger */
    kDAC_TriggerSelectTIMER3OUT2 = 62U, /*!< TIMER3OUT2 trigger */
    kDAC_TriggerSelectTIMER3OUT3 = 63U, /*!< TIMER3OUT3 trigger */
} dac_trigger_select_t;

/*! @brief DAC analog configuration structure definition  */
typedef struct _dac_analog_config
{
    dac_amp_t amp;                           /*!< the current bias of the DAC */
    dac_filter_bandwidth_t filter_bandwidth; /*!< The Miller compensation capacitance of the OPAMP */
    dac_filter_150k_en_t filter_150k_en;     /*!< the filter type and bandwidth */
    dac_voltage_common_mode_t vcm;           /*!< the common mode voltage of the filter output. */
} dac_analog_config_t;

/*!
 * @brief DAC buffer flags.
 */
enum _dac_buffer_status_flags
{
    kDAC_BufferNotFullFlag = DAC_INT_BUF_NFUL_INT_MASK,
    /*!< Buffer not full interrupt. */                    /* FSL_FEATURE_DAC_HAS_WATERMARK_DETECTION */
    kDAC_BufferFullFlag      = DAC_INT_BUF_FUL_INT_MASK,  /*!< Buffer full interrupt. */
    kDAC_BufferEmptyFlag     = DAC_INT_BUF_EMT_INT_MASK,  /*!< Buffer empty interrupt*/
    kDAC_BufferHalfEmptyFlag = DAC_INT_BUF_HEMT_INT_MASK, /*!< Buffer half empty interrupt*/
    kDAC_BufferOverFlowFlag  = DAC_INT_BUF_OV_INT_MASK,   /*!< Buffer over flow interrupt*/
    kDAC_BufferUnderFlowFlag = DAC_INT_BUF_UD_INT_MASK,   /*!< Buffer under flow interrupt*/
    kDAC_BufferHalfFlag      = DAC_INT_BUF_HFUL_INT_MASK, /*!< Buffer half full interrupt*/

};

/*!
 * @brief DAC buffer interrupts.
 */
enum _dac_buffer_interrupt_enable
{
    kDAC_BufferNotFullInterruptEnable = DAC_INTEN_BUF_NFUL_INTEN_MASK,
    /*!< Buffer not full interrupt enable. */                            /* FSL_FEATURE_DAC_HAS_WATERMARK_DETECTION */
    kDAC_BufferFullInterruptEnable      = DAC_INTEN_BUF_FUL_INTEN_MASK,  /*!< Buffer full interrupt enable. */
    kDAC_BufferEmptyInterruptEnable     = DAC_INTEN_BUF_EMT_INTEN_MASK,  /*!< Buffer empty interrupt enable*/
    kDAC_BufferHalfEmptyInterruptEnable = DAC_INTEN_BUF_HEMT_INTEN_MASK, /*!< Buffer half empty interrupt enable*/
    kDAC_BufferOverFlowInterruptEnable  = DAC_INTEN_BUF_OV_INTEN_MASK,   /*!< Buffer over flow interrupt enable*/
    kDAC_BufferUnderFlowInterruptEnable = DAC_INTEN_BUF_UD_INTEN_MASK,   /*!< Buffer under flow interrupt enable*/
    kDAC_BufferHalfFullInterruptEnable  = DAC_INTEN_BUF_HFUL_INTEN_MASK, /*!< Buffer half full interrupt enable*/
};

/*! @brief DAC sin wave configuration structure definition */
typedef struct _dac_sinwave_config
{
    uint32_t freq;       /*!< Sine wave frequency */
    uint32_t amp;        /*!< Sine wave amplitude */
    uint32_t dc_offset;  /*!< DC value of sin wave */
    dac_sin_enable_t en; /*!< Sin Wave enable or disable*/
} dac_sinwave_config_t;

/*! @brief DAC Modulator configuration structure definition */
typedef struct _dac_modulator_config
{
    dac_modulator_output_width_t out_wd; /*!< Modulator output width. */
    dac_sample_rate_t smpl_rate;         /*!< Modulator down-sample rate */
    dac_modulator_enable_t en;           /*!< Modulator enable or disable */
} dac_modulator_config_t;

/*! @brief DAC trigger configuration structure definition*/
typedef struct _dac_trigger_config
{
    dac_trigger_edge_select_t edge; /*!< Trigger edge*/
    dac_trigger_mode_t mode;        /*!< Trigger mode*/
    dac_trigger_select_t src;       /*!< Trigger source*/
} dac_trigger_config_t;

/**
 * @brief  DAC initial structure definition
 */
typedef struct
{
    dac_analog_config_t ana_cfg; /*!< analog config*/

    dac_sinwave_config_t sin_cfg; /*!< sin wave config*/

    dac_modulator_config_t mod_cfg; /*!< Modulator config*/

    dac_trigger_config_t trg_cfg; /*!< trigger config*/

    uint32_t sign_inv; /*!< inverse sign */

    uint32_t gain_ctrl; /*!< dac gain */

    dac_buffer_in_align_t input; /*!< buffer in align*/

    dac_buffer_out_align_t output; /*!< buffer out align*/

    uint32_t clk_inv; /*!< DAC clock invert */

    uint32_t clk_div; /*!< DAC clock divider */

} dac_config_t;
/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif
/*!
 * @brief Initializes the DAC with configuration.
 *
 * @param base DAC peripheral base address.
 * @param config pointer to configuration structure
 * @return none
 */
void DAC_Init(DAC_Type *base, const dac_config_t *config);

/*!
 * @brief De-initialize the DAC peripheral
 *
 * @param base DAC peripheral base address.
 * @return none
 */
void DAC_Deinit(DAC_Type *base);

/*!
 * @brief Enable the DAC's converter or not.
 *
 * @param base DAC peripheral base address.
 * @param enable Enable the DAC's converter or not.
 */
static inline void DAC_Enable(DAC_Type *base, bool enable)
{
    if (enable)
    {
        base->CTRL |= DAC_CTRL_ENABLE_MASK;
    }
    else
    {
        base->CTRL &= ~DAC_CTRL_ENABLE_MASK;
    }
}
/*!
 * @brief  Sets the DAC configuration structure to default values.
 * @code
    config->ana_cfg.amp = kDAC_Amplitude100pct;
    config->ana_cfg.filter_bandwidth = kDAC_FilterBandwidth56FF;
    config->ana_cfg.filter_150k_en = kDAC_Filter150kEnable150Khz;
    config->ana_cfg.vcm    = kDAC_VoltageCommonMode1500mv;
    config->sin_cfg.en = kDAC_SinWaveDisable;
    config->mod_cfg.en = kDAC_ModulatorDisable;
    config->mod_cfg.out_wd = kDAC_ModulatorWidth1bit;
    config->mod_cfg.smpl_rate = kDAC_SampleRate8;
    config->sign_inv = 0;
    config->output = kDAC_BufferOutAlignRight;
    config->input = kDAC_BufferInAlignRight;
    config->trg_cfg.mode = kDAC_TriggerModeSingleMode;
    config->trg_cfg.edge = kDAC_TriggerEdgeSelectPositiveEdge;
    config->trg_cfg.src = kDAC_TriggerSelectSoftware;
    config->clk_div = apb_clk / 1000000 / 2 - 1;
    config->clk_inv = 0;
    config->sin_cfg.freq = 0;
    config->sin_cfg.amp = 0;
    config->sin_cfg.dc_offset = 0;

    config->gain_ctrl = 0x10;
 * @endcode
 * @param config pointer to DAC config structure
 */
void DAC_GetDefaultConfig(dac_config_t *config);

/*!
 * @brief Get DAC status flags.
 *
 * @param base DAC peripheral base address.
 * @return DAC status flags.
 */
static inline uint32_t DAC_GetStatusFlags(DAC_Type *base)
{
    return base->INT;
}

/*!
 * @brief Clears status flags with the provided mask.
 *
 * @param base DAC peripheral base address.
 * @return none
 */
static inline void DAC_ClearStatusFlags(DAC_Type *base, uint32_t mask)
{
    base->INT = mask;
}

/*!
 * @brief Enables the DAC interrupt.
 *
 * This function enables the DAC interrupt.
 *
 * @param base DAC peripheral base address.
 * @param mask interrupt source.
 */
static inline void DAC_EnableInterrupts(DAC_Type *base, uint32_t mask)
{
    base->INTEN |= mask;
}
/*!
 * @brief Disables the DAC interrupt.
 *
 * This function disables the DAC interrupt.
 *
 * @param base DAC peripheral base address.
 * @param mask interrupt source.
 */
static inline void DAC_DisableInterrupts(DAC_Type *base, uint32_t mask)
{
    base->INTEN &= ~mask;
}

/*!
 * @brief Set data into the entry of FIFO buffer.
 *
 * @param base DAC peripheral base address.
 * @param value Setting value into FIFO buffer.
 */
static inline void DAC_SetData(DAC_Type *base, uint32_t value)
{
    base->DIN = DAC_DIN_DIN(value);
}

/*!
 * @brief Do trigger the FIFO by software.
 * @param base DAC peripheral base address.
 */
static inline void DAC_DoSoftwareTrigger(DAC_Type *base)
{
    base->CLR_TRG = DAC_CLR_TRG_SW_TRG_MASK;
}
#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif /* FSL_DAC_H_*/
