/*
 * Copyright 2023-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_SAR_ADC_H_
#define FSL_SAR_ADC_H_

#include "fsl_common.h"

/*!
 * @addtogroup sar_adc
 * @{
 */

/******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name Driver version */
/*! @{ */
/*! @brief SAR ADC driver version 2.3.0. */
#define FSL_SAR_ADC_DRIVER_VERSION (MAKE_VERSION(2, 3, 0))
/*! @} */

#define ADC_GROUP_COUNTS               FSL_FEATURE_ADC_CHANNEL_GROUPS_COUNT
#define ADC_THRESHOLD_COUNTS           FSL_FEATURE_ADC_THRESHOLDS_COUNT
#define ADC_SELF_TEST_THRESHOLD_COUNTS FSL_FEATURE_ADC_SELF_TEST_THRESHOLDS_COUNT

#define GET_REGINDEX(channelIndex) (uint32_t)(((uint32_t)(channelIndex)) / 32U)
#define GET_BITINDEX(channelIndex) (uint32_t)(((uint32_t)(channelIndex)) % 32U)

#define REGISTER_READWRITE(baseRegister, shiftIndex) \
    (*((volatile uint32_t *)(&(baseRegister)) + ((uint32_t)shiftIndex)))
#define REGISTER_READONLY(baseRegister, shiftIndex) \
    (*((volatile const uint32_t *)(&(baseRegister)) + ((uint32_t)shiftIndex)))

#define NCMR_IO(base, registerIndex)   REGISTER_READWRITE(((base)->NCMR0), (registerIndex))
#define JCMR_IO(base, registerIndex)   REGISTER_READWRITE(((base)->JCMR0), (registerIndex))
#define PSR_IO(base, registerIndex)    REGISTER_READWRITE(((base)->PSR0), (registerIndex))
#define DMAR_IO(base, registerIndex)   REGISTER_READWRITE(((base)->DMAR0), (registerIndex))
      
#if(ADC_GROUP_COUNTS==2U)
#define CWSELR_IO(base, registerIndex) REGISTER_READWRITE(((base)->CWSELR0), (registerIndex))
#else /* ADC_GROUP_COUNTS==3U */
#define CWSELR_IO(base, registerIndex) REGISTER_READWRITE(((base)->CWSELRPI[0U]), (registerIndex))
#endif /* ADC_GROUP_COUNTS */

#define CWENR_IO(base, registerIndex)  REGISTER_READWRITE(((base)->CWENR0), (registerIndex))
#define CIMR_IO(base, registerIndex)   REGISTER_READWRITE(((base)->CIMR0), (registerIndex))
#define CEOCFR_IO(base, registerIndex) REGISTER_READWRITE(((base)->CEOCFR0), (registerIndex))
#define AWORR_IO(base, registerIndex)  REGISTER_READWRITE(((base)->AWORR0), (registerIndex))
#define STAWR_IO(base, registerIndex)  REGISTER_READWRITE(((base)->STAW0R), (registerIndex))

#define CEOCFR_I(base, registerIndex) REGISTER_READONLY((base->CEOCFR0), (registerIndex))
#define AWORR_I(base, registerIndex)  REGISTER_READONLY((base->AWORR0), (registerIndex))
#define CDR_I(base, registerIndex)    REGISTER_READONLY((base->PCDR[0U]), (registerIndex))

#if(ADC_GROUP_COUNTS==2U)
#define WDG_SELECT_MASK(shiftIndex)  ((uint32_t)ADC_CWSELR0_WSEL_CH0_MASK << ((shiftIndex) * 4U))
#define WDG_SELECT_SHIFT(shiftIndex) (ADC_CWSELR0_WSEL_CH0_SHIFT + ((shiftIndex) * 4U))
#define WDG_SELECT(val, shiftIndex) \
    (((uint32_t)(((uint32_t)(val)) << WDG_SELECT_SHIFT(shiftIndex))) & WDG_SELECT_MASK(shiftIndex))
#else /* ADC_GROUP_COUNTS==3U */
#define WDG_SELECT_MASK(shiftIndex)  ((uint32_t)ADC_CWSELRPI_WSEL_SI0_0_MASK << ((shiftIndex) * 4U))
#define WDG_SELECT_SHIFT(shiftIndex) (ADC_CWSELRPI_WSEL_SI0_0_SHIFT + ((shiftIndex) * 4U))
#define WDG_SELECT(val, shiftIndex) \
    (((uint32_t)(((uint32_t)(val)) << WDG_SELECT_SHIFT(shiftIndex))) & WDG_SELECT_MASK(shiftIndex))
#endif /* ADC_GROUP_COUNTS */

#if(ADC_SELF_TEST_THRESHOLD_COUNTS==6U)
#define ADC_THRHLR_THRL_MASK  ADC_THRHLR0_THRL_MASK
#define ADC_THRHLR_THRL_SHIFT ADC_THRHLR0_THRL_SHIFT
#define ADC_THRHLR_THRL(val)  ADC_THRHLR0_THRL(val)

#define ADC_THRHLR_THRH_MASK  ADC_THRHLR0_THRH_MASK
#define ADC_THRHLR_THRH_SHIFT ADC_THRHLR0_THRH_SHIFT
#define ADC_THRHLR_THRH(val)  ADC_THRHLR0_THRH(val)
#endif

#define ADC_CDR_VALID_MASK   ADC_PCDR_VALID_MASK
#define ADC_CDR_VALID_SHIFT  ADC_PCDR_VALID_SHIFT
#define ADC_CDR_OVERW_MASK   ADC_PCDR_OVERW_MASK
#define ADC_CDR_OVERW_SHIFT  ADC_PCDR_OVERW_SHIFT
#define ADC_CDR_RESULT_MASK  ADC_PCDR_RESULT_MASK
#define ADC_CDR_RESULT_SHIFT ADC_PCDR_RESULT_SHIFT
#define ADC_CDR_CDATA_MASK   ADC_PCDR_CDATA_MASK
#define ADC_CDR_CDATA_SHIFT  ADC_PCDR_CDATA_SHIFT
#define ADC_STAWR_AWDE_MASK  ADC_STAW0R_AWDE_MASK

#define ADC_STAWR_THRL_MASK  ADC_STAW0R_THRL_MASK
#define ADC_STAWR_THRL_SHIFT ADC_STAW0R_THRL_SHIFT
#define ADC_STAWR_THRL(val)  ADC_STAW0R_THRL(val)

#define ADC_STAWR_THRH_MASK  ADC_STAW0R_THRH_MASK
#define ADC_STAWR_THRH_SHIFT ADC_STAW0R_THRH_SHIFT
#define ADC_STAWR_THRH(val)  ADC_STAW0R_THRH(val)

#define ADC_CALSTAT_MAX  (ADC_CALSTAT_TEST_RESULT_MASK >> ADC_CALSTAT_TEST_RESULT_SHIFT)
#define ADC_CALSTAT_SIGN ((ADC_CALSTAT_MAX + 1U) >> 1U)

/*!
 * @brief This enumeration provides the mask for the ADC end-of-conversion and end-of-chain interrupts enabling.
 */
enum _adc_conv_int_enable
{
    kADC_NormalConvChainEndIntEnable = ADC_IMR_MSKECH_MASK,  /*!< Enable end of normal chain conversion interrupt. */
    kADC_NormalConvEndIntEnable      = ADC_IMR_MSKEOC_MASK,  /*!< Enable end of normal conversion interrupt. */
    kADC_InjectConvChainEndIntEnable = ADC_IMR_MSKJECH_MASK, /*!< Enable end of inject chain conversion interrupt. */
    kADC_InjectConvEndIntEnable      = ADC_IMR_MSKJEOC_MASK, /*!< Enable end of inject conversion interrupt. */
#if defined(FSL_FEATURE_ADC_HAS_BCTUMODE) && (FSL_FEATURE_ADC_HAS_BCTUMODE==1U)
    kADC_BctuConvEndIntEnable      = ADC_IMR_MSKEOBCTU_MASK, /*!< Enable end of BCTU conversion interrupt. */
#endif /* FSL_FEATURE_ADC_HAS_BCTUMODE */
};

/*!
 * @brief This enumeration provides the mask for the ADC analog watchdog threshold interrupts enabling.
 */
enum _adc_wdg_threshold_int_enable
{
    kADC_wdg0LowThresholdIntEnable  = (1UL << 0UL),  /*!< Enable watchdog 0 low threshold interrupt. */
    kADC_wdg0HighThresholdIntEnable = (1UL << 1UL),  /*!< Enable watchdog 0 high threshold interrupt. */
    kADC_wdg1LowThresholdIntEnable  = (1UL << 2UL),  /*!< Enable watchdog 1 low threshold interrupt. */
    kADC_wdg1HighThresholdIntEnable = (1UL << 3UL),  /*!< Enable watchdog 1 high threshold interrupt. */
    kADC_wdg2LowThresholdIntEnable  = (1UL << 4UL),  /*!< Enable watchdog 2 low threshold interrupt. */
    kADC_wdg2HighThresholdIntEnable = (1UL << 5UL),  /*!< Enable watchdog 2 high threshold interrupt. */
    kADC_wdg3LowThresholdIntEnable  = (1UL << 6UL),  /*!< Enable watchdog 3 low threshold interrupt. */
    kADC_wdg3HighThresholdIntEnable = (1UL << 7UL),  /*!< Enable watchdog 3 high threshold interrupt. */
    kADC_wdg4LowThresholdIntEnable  = (1UL << 8UL),  /*!< Enable watchdog 4 low threshold interrupt. */
    kADC_wdg4HighThresholdIntEnable = (1UL << 9UL),  /*!< Enable watchdog 4 high threshold interrupt. */
    kADC_wdg5LowThresholdIntEnable  = (1UL << 10UL), /*!< Enable watchdog 5 low threshold interrupt. */
    kADC_wdg5HighThresholdIntEnable = (1UL << 11UL), /*!< Enable watchdog 5 high threshold interrupt. */
    kADC_wdg6LowThresholdIntEnable  = (1UL << 12UL), /*!< Enable watchdog 6 low threshold interrupt. */
    kADC_wdg6HighThresholdIntEnable = (1UL << 13UL), /*!< Enable watchdog 6 high threshold interrupt. */
    kADC_wdg7LowThresholdIntEnable  = (1UL << 14UL), /*!< Enable watchdog 7 low threshold interrupt. */
    kADC_wdg7HighThresholdIntEnable = (1UL << 15UL), /*!< Enable watchdog 7 high threshold interrupt. */
};

/*!
 * @brief This enumeration provides the mask for the ADC self-test related interrupts enabling.
 */
enum _adc_self_test_int_enable
{
    kADC_AlgSStep0ErrIntEnable   = ADC_STCR2_MSKERR_S0_MASK, /*!< Enable self-test algorithm S step0 error interrupt. */
    kADC_AlgSStep1ErrIntEnable   = ADC_STCR2_MSKERR_S1_MASK, /*!< Enable self-test algorithm S step1 error interrupt. */
    kADC_AlgSStep2ErrIntEnable   = ADC_STCR2_MSKERR_S2_MASK, /*!< Enable self-test algorithm S step2 error interrupt. */
    kADC_AlgCErrIntEnable        = ADC_STCR2_MSKERR_C_MASK,  /*!< Enable self-test algorithm C error interrupt. */
    kADC_AlgSEndIntEnable        = ADC_STCR2_MSKWDG_EOA_S_MASK, /*!< Enable self-test algorithm S end interrupt. */
    kADC_AlgCEndIntEnable        = ADC_STCR2_MSKWDG_EOA_C_MASK, /*!< Enable self-test algorithm C end interrupt. */
    kADC_ConvEndIntEnable        = ADC_STCR2_MSKST_EOC_MASK,    /*!< Enable self-test conversion end interrupt. */
    kADC_WdgTimeErrIntEnable     = ADC_STCR2_MSKWDTERR_MASK,    /*!< Enable watchdog time error interrupt. */
    kADC_WdgSequenceErrIntEnable = ADC_STCR2_MSKWDSERR_MASK,    /*!< Enable watchdog sequence error interrupt. */
};

/*!
 * @brief This enumeration provides the mask for the ADC end-of-conversion and end-of-chain interrupts flag.
 */
enum _adc_conv_int_flag
{
    kADC_NormalConvChainEndIntFlag = ADC_ISR_ECH_MASK,  /*!< Indicates whether the end of
                                                        normal chain conversion interrupt has occurred. */
    kADC_NormalConvEndIntFlag = ADC_ISR_EOC_MASK,       /*!< Indicates whether the end of
                                                        conversion interrupt has occurred. */
    kADC_InjectConvChainEndIntFlag = ADC_ISR_JECH_MASK, /*!< Indicates whether the end of
                                                        inject chain conversion interrupt has occurred. */
    kADC_InjectConvEndIntFlag = ADC_ISR_JEOC_MASK,      /*!< Indicates whether the end of
                                                        inject conversion interrupt has occurred. */
#if defined(FSL_FEATURE_ADC_HAS_BCTUMODE) && (FSL_FEATURE_ADC_HAS_BCTUMODE==1U)
    kADC_BctuConvEndIntFlag = ADC_ISR_EOBCTU_MASK,      /*!< Indicates whether the end of
                                                        BCTU conversion interrupt has occurred. */
#endif /* FSL_FEATURE_ADC_HAS_BCTUMODE */
};

/*!
 * @brief This enumeration provides the mask for the ADC analog watchdog threshold interrupts flag.
 */
enum _adc_wdg_threshold_int_flag
{
    kADC_wdg0LowThresholdIntFlag = (1UL << 0UL),   /*!< Indicates whether the watchdog 0 low
                                                   threshold interrupt has occurred. */
    kADC_wdg0HighThresholdIntFlag = (1UL << 1UL),  /*!< Indicates whether the watchdog 0 high
                                                   threshold interrupt has occurred. */
    kADC_wdg1LowThresholdIntFlag = (1UL << 2UL),   /*!< Indicates whether the watchdog 1 low
                                                   threshold interrupt has occurred. */
    kADC_wdg1HighThresholdIntFlag = (1UL << 3UL),  /*!< Indicates whether the watchdog 1 high
                                                   threshold interrupt has occurred. */
    kADC_wdg2LowThresholdIntFlag = (1UL << 4UL),   /*!< Indicates whether the watchdog 2 low
                                                   threshold interrupt has occurred. */
    kADC_wdg2HighThresholdIntFlag = (1UL << 5UL),  /*!< Indicates whether the watchdog 2 high
                                                   threshold interrupt has occurred. */
    kADC_wdg3LowThresholdIntFlag = (1UL << 6UL),   /*!< Indicates whether the watchdog 3 low
                                                   threshold interrupt has occurred. */
    kADC_wdg3HighThresholdIntFlag = (1UL << 7UL),  /*!< Indicates whether the watchdog 3 high
                                                   threshold interrupt has occurred. */
    kADC_wdg4LowThresholdIntFlag = (1UL << 8UL),   /*!< Indicates whether the watchdog 4 low
                                                   threshold interrupt has occurred. */
    kADC_wdg4HighThresholdIntFlag = (1UL << 9UL),  /*!< Indicates whether the watchdog 4 high
                                                   threshold interrupt has occurred. */
    kADC_wdg5LowThresholdIntFlag = (1UL << 10UL),  /*!< Indicates whether the watchdog 5 low
                                                   threshold interrupt has occurred. */
    kADC_wdg5HighThresholdIntFlag = (1UL << 11UL), /*!< Indicates whether the watchdog 5 high
                                                   threshold interrupt has occurred. */
    kADC_wdg6LowThresholdIntFlag = (1UL << 12UL),  /*!< Indicates whether the watchdog 6 low
                                                   threshold interrupt has occurred. */
    kADC_wdg6HighThresholdIntFlag = (1UL << 13UL), /*!< Indicates whether the watchdog 6 high
                                                   threshold interrupt has occurred. */
    kADC_wdg7LowThresholdIntFlag = (1UL << 14UL),  /*!< Indicates whether the watchdog 7 low
                                                   threshold interrupt has occurred. */
    kADC_wdg7HighThresholdIntFlag = (1UL << 15UL), /*!< Indicates whether the watchdog 7 high
                                                   threshold interrupt has occurred. */
};

/*!
 * @brief This enumeration provides the mask for the ADC self-test-related interrupts flag.
 */
enum _adc_self_test_int_flag
{
    kADC_AlgSStep0ErrIntFlag = ADC_STSR1_ERR_S0_MASK,    /*!< Indicates whether the
                                                         self-test algorithm S step0 error interrupt has occurred. */
    kADC_AlgSStep1ErrIntFlag = ADC_STSR1_ERR_S1_MASK,    /*!< Indicates whether the
                                                         self-test algorithm S step1 error interrupt has occurred. */
    kADC_AlgSStep2ErrIntFlag = ADC_STSR1_ERR_S2_MASK,    /*!< Indicates whether the
                                                         self-test algorithm S step2 error interrupt has occurred. */
    kADC_AlgCErrIntFlag = ADC_STSR1_ERR_C_MASK,          /*!< Indicates whether the
                                                         self-test algorithm C error interrupt has occurred. */
    kADC_AlgSEndIntFlag = ADC_STSR1_WDG_EOA_S_MASK,      /*!< Indicates whether the
                                                         algorithm S end interrupt has completed. */
    kADC_AlgCEndIntFlag = ADC_STSR1_WDG_EOA_C_MASK,      /*!< Indicates whether the
                                                         algorithm C end interrupt has completed. */
    kADC_SelfTestConvEndIntFlag = ADC_STSR1_ST_EOC_MASK, /*!< Indicates whether the
                                                         self-test end-of-conversion interrupt has completed. */
    kADC_OverWriteErrIntFlag = ADC_STSR1_OVERWR_MASK,    /*!< Indicates whether the
                                                         overwrite error interrupt has occurred. */
    kADC_WdgTimeErrIntFlag = ADC_STSR1_WDTERR_MASK,      /*!< Indicates whether the
                                                         watchdog time error interrupt has occurred. */
    kADC_WdgSequenceErrIntFlag = ADC_STSR1_WDSERR_MASK,  /*!< Indicates whether the
                                                         watchdog sequence error interrupt has occurred. */
};

#if defined(FSL_FEATURE_ADC_HAS_BCTUMODE) && (FSL_FEATURE_ADC_HAS_BCTUMODE==1U)
/*!
 * @brief This enumeration provides the selection of the Body Cross Trigger Unit (BCTU) mode.
 */
typedef enum _adc_bctu_mode
{
    kADC_BctuModeDisable        = 0x0U, /*!< BCTU disabled. */
    kADC_BctuTrig               = 0x2U, /*!< BCTU enabled, only BCTU can trigger conversion. */
    kADC_AllTrig                = 0x3U, /*!< BCTU enabled, all trigger sources can trigger conversion. */
} adc_bctu_mode_t;
#endif /* FSL_FEATURE_ADC_HAS_BCTUMODE */

#if (defined(FSL_FEATURE_ADC_HAS_CALBISTREG) && (FSL_FEATURE_ADC_HAS_CALBISTREG==1U))
/*!
 * @brief This enumeration provides the selection of the ADC conversion resolution.
 */
typedef enum _adc_conv_res
{
    kADC_ConvRes14Bit   = 0x0U, /*!< 14-bit resolution. */
    kADC_ConvRes12Bit   = 0x1U, /*!< 12-bit resolution. */
    kADC_ConvRes10Bit   = 0x2U, /*!< 10-bit resolution. */
    kADC_ConvRes8Bit   = 0x2U, /*!< 8-bit resolution. */
} adc_conv_res_t;
#endif /* FSL_FEATURE_ADC_HAS_CALBISTREG */

/*!
 * @brief This enumeration provides the selection of the ADC external trigger type.
 */
typedef enum _adc_ext_trig
{
    kADC_ExtTrigDisable = 0x0U, /*!< Normal trigger input does not start a conversion. */
    kADC_ExtTrigFallingEdge = 0x2U, /*!< Normal trigger (falling edge) input starts a conversion. */
    kADC_ExtTrigRisingEdge = 0x3U, /*!< Normal trigger (rising edge) input starts a conversion. */
} adc_ext_trig_t;

#if defined(FSL_FEATURE_ADC_HAS_AMSIO) && (FSL_FEATURE_ADC_HAS_AMSIO==1U)
/*!
 * @brief This enumeration provides the selection of the ADC conversion speed mode.
 */
typedef enum _adc_speed_mode
{
    kADC_SpeedModeNormal        = 0x0U, /*!< Normal conversion speed. */
    kADC_SpeedModeHigh          = 0x3U, /*!< High-speed conversion. */
} adc_speed_mode_t;
#endif /* FSL_FEATURE_ADC_HAS_AMSIO */

#if defined(FSL_FEATURE_ADC_HAS_MCR_AVGS) && (FSL_FEATURE_ADC_HAS_MCR_AVGS==1U)
/*!
 * @brief This enumeration provides the selection of the number of conversions ADC uses to calculate
 * the conversion result.
 */
typedef enum _adc_conv_avg
{
    kADC_ConvAvgDisable = 0x0U, /*!< Conversions averaging disabled. */
    kADC_ConvAvg4       = 0x4U, /*!< 4 conversions averaging. */
    kADC_ConvAvg8       = 0x5U, /*!< 8 conversions averaging. */
    kADC_ConvAvg16      = 0x6U, /*!< 16 conversions averaging. */
    kADC_ConvAvg32      = 0x7U, /*!< 32 conversions averaging. */
} adc_conv_avg_t;
#endif /* FSL_FEATURE_ADC_HAS_MCR_AVGS */

/*!
 * @brief This enumeration provides the selection of the ADC state.
 */
typedef enum _adc_state
{
    kADC_AdcIdle              = 0x00U, /*!< Indicates the ADC is in the IDLE state. */
    kADC_AdcPowerdown         = 0x01U, /*!< Indicates the ADC is in the power-down state. */
    kADC_AdcWait              = 0x02U, /*!< Indicates the ADC is in the wait state. */
    kADC_AdcBusyInCalibration = 0x03U, /*!< Indicates the ADC is in the calibration busy state. */
    kADC_AdcSample            = 0x04U, /*!< Indicates the ADC is in the sample state. */
    kADC_AdcConv              = 0x06U, /*!< Indicates the ADC is in the conversion state. */
} adc_state_t;

/*!
 * @brief This enumeration provides the selection of the ADC conversion mode, including normal conversion one-shot mode,
 * normal conversion scan mode, and inject conversion one-shot mode.
 */
typedef enum _adc_conv_mode
{
    kADC_NormalConvOneShotMode = 0x00U, /*!< Normal conversion one-shot mode. */
    kADC_NormalConvScanMode    = 0x01U, /*!< Normal conversion scan mode. */
    kADC_InjectConvOneShotMode = 0x02U, /*!< Inject conversion one-shot mode. */
} adc_conv_mode_t;

/*!
 * @brief This enumeration provides the selection of the ADC operating clock frequency, including half-bus
 * frequency and full bus frequency.
 */
typedef enum _adc_clock_frequency
{
#if !(defined(FSL_FEATURE_ADC_HAS_MCR_ADCLKSE) && (FSL_FEATURE_ADC_HAS_MCR_ADCLKSE==0U))
    kADC_HalfBusFrequency = 0x00U, /*!< Half of bus clock frequency. */
    kADC_FullBusFrequency = 0x01U, /*!< Equal to bus clock frequency. */
#endif /* FSL_FEATURE_ADC_HAS_MCR_ADCLKSE */
#if (defined(FSL_FEATURE_ADC_HAS_MCR_ADCLKSEL) && (FSL_FEATURE_ADC_HAS_MCR_ADCLKSEL==1U))
    kADC_ModuleClockFreq            = 0x00U, /*!< Module clock frequency. */
    kADC_ModuleClockFreqDivide2     = 0x01U, /*!< Module clock frequency / 2. */
    kADC_ModuleClockFreqDivide4     = 0x02U, /*!< Module clock frequency / 4. */
    kADC_ModuleClockFreqDivide8     = 0x03U, /*!< Module clock frequency / 8. */
#endif /* FSL_FEATURE_ADC_HAS_MCR_ADCLKSEL */
} adc_clock_frequency_t;

/*!
 * @brief This enumeration provides the selection of the ADC conversion data alignment, including the right alignment
 * and left alignment.
 */
typedef enum _adc_conv_data_align
{
    kADC_ConvDataRightAlign = 0x00U, /*!< Conversion data is right aligned. */
    kADC_ConvDataLeftAlign  = 0x01U  /*!< Conversion data is left aligned. */
} adc_conv_data_align_t;

/*!
 * @brief This enumeration provides the selection of the ADC internal analog input voltage sources for pre-sample,
 * including DVDD0P8/2, AVDD1P8/4, VREFL_1p8 and VREFH_1p8.
 */
typedef enum _adc_presample_voltage_src
{
#if(ADC_GROUP_COUNTS==2U)
    kADC_PresampleVoltageSrcDVDD  = 0x00U, /*!< Use DVDD0P8/2 as pre-sample voltage source. */
    kADC_PresampleVoltageSrcAVDD  = 0x01U, /*!< Use AVDD1P8/4 as pre-sample voltage source. */
    kADC_PresampleVoltageSrcVREFL = 0x02U, /*!< Use VREFL_1p8 as pre-sample voltage source. */
    kADC_PresampleVoltageSrcVREFH = 0x03U, /*!< Use VREFH_1p8 as pre-sample voltage source. */
#else /* ADC_GROUP_COUNTS==3U */
    kADC_PresampleVoltageSrcVREL  = 0x00U, /*!< Use VREL as pre-sample voltage source. */
    kADC_PresampleVoltageSrcVREH  = 0x01U, /*!< Use VREH as pre-sample voltage source. */
#endif /* ADC_GROUP_COUNTS */
} adc_presample_voltage_src_t;

/*!
 * @brief This enumeration provides the selection of the DMA request clear sources, including clear
 * by acknowledgment from the DMA controller and clear on a read of the data register.
 */
typedef enum _adc_dma_request_clear_src
{
    kADC_DMARequestClearByAck  = 0x00U, /*!< DMA request cleared by acknowledgment from DMA controller. */
    kADC_DMARequestClearOnRead = 0x01U, /*!< DMA request cleared on a read of the data register. */
} adc_dma_request_clear_src_t;

/*!
 * @brief This enumeration provides the selection of the ADC calibration averaging sample numbers, including
 * 16, 32, 128, and 512 averaging samples.
 */
typedef enum _adc_average_sample_numbers
{
#if (defined(FSL_FEATURE_ADC_HAS_CALBISTREG) && (FSL_FEATURE_ADC_HAS_CALBISTREG==1U))
    kADC_AverageSampleNumbers4  = 0x00U, /*!< Use 4 averaging samples during calibration. */
    kADC_AverageSampleNumbers8  = 0x01U, /*!< Use 8 averaging samples during calibration. */
    kADC_AverageSampleNumbers16 = 0x02U, /*!< Use 16 averaging samples during calibration. */
    kADC_AverageSampleNumbers32 = 0x03U, /*!< Use 32 averaging samples during calibration. */
#else
    kADC_AverageSampleNumbers16  = 0x00U, /*!< Use 16 averaging samples during calibration. */
    kADC_AverageSampleNumbers32  = 0x01U, /*!< Use 32 averaging samples during calibration. */
    kADC_AverageSampleNumbers128 = 0x02U, /*!< Use 128 averaging samples during calibration. */
    kADC_AverageSampleNumbers512 = 0x03U, /*!< Use 512 averaging samples during calibration. */
#endif /* FSL_FEATURE_ADC_HAS_CALBISTREG */
} adc_average_sample_numbers_t;

/*!
 * @brief This enumeration provides the selection of the ADC sample time of calibration conversions, including
 * 22, 8, 16 and 32 cycles of ADC_CLK.
 */
typedef enum _adc_sample_time
{
    kADC_SampleTime22 = 0x00U, /*!< Use 22 cycles of ADC_CLK as sample time of calibration conversions. */
    kADC_SampleTime8  = 0x01U, /*!< Use 8 cycles of ADC_CLK as sample time of calibration conversions. */
    kADC_SampleTime16 = 0x02U, /*!< Use 16 cycles of ADC_CLK as sample time of calibration conversions.  */
    kADC_SampleTime32 = 0x03U, /*!< Use 32 cycles of ADC_CLK  as sample time of calibration conversions. */
} adc_sample_time_t;

/*!
 * @brief This enumeration provides the selection of the ADC analog watchdog threshold low and high interrupt enable.
 */
typedef enum _adc_wdg_threshold_int
{
    kADC_LowHighThresholdIntDisable = 0x00U, /*!< Enable the ADC analog watchdog low and high threshold interrupts. */
    kADC_LowThresholdIntEnable      = 0x01U, /*!< Enable the ADC analog watchdog low threshold interrupt. */
    kADC_HighThresholdIntEnable     = 0x02U, /*!< Enable the ADC analog watchdog high threshold interrupt. */
    kADC_LowHighThresholdIntEnable  = 0x03U, /*!< Enable the ADC analog watchdog low and high threshold interrupts. */
} adc_wdg_threshold_int_t;

/*!
 * @brief This enumeration provides the selection of the ADC self-test algorithm type, including algorithm S,
 * algorithm C and algorithm S and C.
 *
 * @note The meaning of enumeration member 'kADC_SelfTestForAlgSAndC' in different conversion modes is different,
 * in the one-shot conversion mode, it means executing algorithm S; in the scan conversion mode, it means executing
 * algorithm S and C.
 */
typedef enum _adc_alg_type
{
    kADC_SelfTestForAlgS     = 0x00U, /*!< Use algorithm S for self-test. */
    kADC_SelfTestForAlgC     = 0x02U, /*!< Use algorithm C for self-test. */
    kADC_SelfTestForAlgSAndC = 0x03U, /*!< Use algorithm S for one-shot conversion mode self-test, use algorithm S
                                      and algorithm C for scan conversion mode self-test. */
} adc_alg_type_t;

/*!
 * @brief This enumeration provides the selection of the ADC self-test watchdog thresholds for algorithm S step 0 - 2,
 * and watchdog thresholds for algorithm C step 0 and step x (x = 1 - 11).
 */
typedef enum _adc_self_test_wdg_threshold
{
    kADC_SelfTestWdgThresholdForAlgSStep0 = 0U,         /*!< Self-test watchdog threshold
                                                        for the algorithm S step 0. */
#if(ADC_GROUP_COUNTS==2U)
    kADC_SelfTestWdgThresholdForAlgSStep1Integer = 1U,  /*!< Self-test watchdog threshold
                                                        for the algorithm S step 1 integer part. */
    kADC_SelfTestWdgThresholdForAlgSStep1Fraction = 2U, /*!< Self-test watchdog threshold
                                                        for the algorithm S step 1 fraction part. */
#else /* ADC_GROUP_COUNTS==3U */
    kADC_SelfTestWdgThresholdForAlgSStep1 = 2U, /*!< Self-test watchdog threshold
                                                for the algorithm S step 1 fraction part. */
#endif /* ADC_GROUP_COUNTS */
    kADC_SelfTestWdgThresholdForAlgSStep2 = 3U,         /*!< Self-test watchdog threshold
                                                        for the algorithm S step 2. */
    kADC_SelfTestWdgThresholdForAlgCStep0 = 5U,         /*!< Self-test watchdog threshold
                                                        for the algorithm C step 0. */
    kADC_SelfTestWdgThresholdForAlgCStepx = 6U,         /*!< Self-test watchdog threshold
                                                        for the algorithm C step x. */
} adc_self_test_wdg_threshold_t;

/*!
 * @brief This enumeration provides the selection of the ADC self-test watchdog timer value, including 0.1ms, 0.5ms,
 * 1ms, 2ms, 5ms, 10ms, 20ms and 50ms.
 */
typedef enum _adc_wdg_timer_val
{
    kADC_SelfTestWdgTimerVal0 = 0x00U, /*!< 0.1ms ((0008h × Prescaler) cycles at 80 MHz). */
    kADC_SelfTestWdgTimerVal1 = 0x01U, /*!< 0.5ms ((0027h × Prescaler) cycles at 80 MHz). */
    kADC_SelfTestWdgTimerVal2 = 0x02U, /*!< 1ms ((004Eh × Prescaler) cycles at 80 MHz). */
    kADC_SelfTestWdgTimerVal3 = 0x03U, /*!< 2ms ((009Ch × Prescaler) cycles at 80 MHz). */
    kADC_SelfTestWdgTimerVal4 = 0x04U, /*!< 5ms ((0187h × Prescaler) cycles at 80 MHz). */
    kADC_SelfTestWdgTimerVal5 = 0x05U, /*!< 10ms ((030Dh × Prescaler) cycles at 80 MHz). */
    kADC_SelfTestWdgTimerVal6 = 0x06U, /*!< 20ms ((061Ah × Prescaler) cycles at 80 MHz). */
    kADC_SelfTestWdgTimerVal7 = 0x07U, /*!< 50ms ((0F42h × Prescaler) cycles at 80 MHz). */
} adc_wdg_timer_val_t;

/*!
 * @brief This structure is used to configure the ADC module.
 */
typedef struct _adc_config
{
    bool enableAutoClockOff; /*!< Decides whether to enable the ADC auto clock-off function, when set to true, the
                             internal ADC clock is automatically switched off during IDLE mode to reduce power
                             consumption (without going into power-down mode). */
    bool enableOverWrite;    /*!< Decides whether to enable the latest conversion to overwrite the current value in the
                             data registers. */
    bool enableConvertPresampleVal; /*!< Decides whether to convert the pre-sampled value, if enabled, pre-sampling is
                                    followed by the conversion, sampling will be bypassed and conversion of the
                                    pre-sampled data will be done. */
#if defined(FSL_FEATURE_ADC_HAS_MCR_XSTARTEN) && (FSL_FEATURE_ADC_HAS_MCR_XSTARTEN==1U)
    bool enableAuxiliaryTrig; /*!< Decides whether to enable the auxiliary normal trigger source
                              to start a conversion. You can use this field to synchronize the 
                              start of a conversion of two ADC instances. */
#endif /* FSL_FEATURE_ADC_HAS_MCR_XSTARTEN */
#if defined(FSL_FEATURE_ADC_HAS_AMSIO) && (FSL_FEATURE_ADC_HAS_AMSIO==1U)
    adc_speed_mode_t speedMode; /*!< Selects ADC speed mode. */
#endif /* FSL_FEATURE_ADC_HAS_AMSIO */
#if defined(FSL_FEATURE_ADC_HAS_DSDR) && (FSL_FEATURE_ADC_HAS_DSDR==1U)
    uint16_t convDelay;           /*!< Specifies the delay in terms of the number of module clock cycles. In case
                                  the channel to convert changed since the last conversion and this new channel 
                                  is an external channel, the conversion starts after a delay configured by convDelay. */
#endif /* FSL_FEATURE_ADC_HAS_DSDR */
#if defined(FSL_FEATURE_ADC_HAS_BCTUMODE) && (FSL_FEATURE_ADC_HAS_BCTUMODE==1U)
    adc_bctu_mode_t bctuMode;           /*!< Selects the BCTU mode. */
#endif /* FSL_FEATURE_ADC_HAS_BCTUMODE */
#if (defined(FSL_FEATURE_ADC_HAS_CALBISTREG) && (FSL_FEATURE_ADC_HAS_CALBISTREG==1U))
    adc_conv_res_t convRes;       /*!< Specifies the number of significant bits per conversion data. */
#endif /* FSL_FEATURE_ADC_HAS_CALBISTREG */
#if defined(FSL_FEATURE_ADC_HAS_MCR_AVGS) && (FSL_FEATURE_ADC_HAS_MCR_AVGS==1U)
    adc_conv_avg_t convAvg; /*!< Selects the number of conversions ADC uses to calculate the conversion result. */
#endif /* FSL_FEATURE_ADC_HAS_MCR_AVGS */
    adc_ext_trig_t extTrig; /*!< Specifies whether the normal trigger (with trigger type) input starts a conversion. */
    adc_conv_data_align_t convDataAlign;                               /*!< Selects the conversion data alignment. */
    adc_clock_frequency_t clockFrequency;                              /*!< Selects the ADC clock frequency. */
    adc_dma_request_clear_src_t dmaRequestClearSrc;                    /*!< Selects DMA request clear source. */
    adc_presample_voltage_src_t presampleVoltageSrc[ADC_GROUP_COUNTS]; /*!< Selects analog input voltages for group 0
                                                    (corresponding to channel 0 to channel 31) and group 32
                                                    (corresponding to channel 32 to channel 63) pre-sampling. */
    uint8_t samplePhaseDuration[ADC_GROUP_COUNTS]; /*!< Sets the sample phase duration in terms of the ADC controller
                                                   clock for group 0 (corresponding to channel 0 to channel 31) and
                                                   group 32 (corresponding to channel 32 to channel 63), the minimum
                                                   acceptable value is 8, configuring to a value lower than 8 sets the
                                                   sample period to 8 cycles. */
} adc_config_t;

/*!
 * @brief This structure is used to configure the ADC conversion channel.
 */
typedef struct _adc_channel_config
{
    uint8_t channelIndex;   /*!< Sets the conversion channel index. */
    bool enableInt;         /*!< Decides Whether to enable the interrupt function of the current conversion channel. */
    bool enablePresample;   /*!< Decides whether to enable the pre-sample function of the current conversion channel. */
    bool enableDmaTransfer; /*!< Decides whether to enable the DMA transfer function of the current conversion channel.
                             */
    bool enableWdg;   /*!< Decides whether to enable the analog watchdog function of the current conversion channel. */
    uint8_t wdgIndex; /*!< Indicates which analog watchdog to provide the low and high threshold value. */
} adc_channel_config_t;

/*!
 * @brief This structure is used to configure the ADC conversion chain.
 */
typedef struct _adc_chain_config
{
    adc_conv_mode_t convMode;           /*!< Selects conversion mode. */
    bool enableGlobalChannelConvEndInt; /*!< Global control function to determine whether to enable the interrupt
                                        function of conversion channels. */
    bool enableChainConvEndInt;         /*!< Decides whether to enable the current chain end-of-conversion interrupt. */
    uint8_t channelCount;               /*!< Indicates the channel counts. */
    adc_channel_config_t *channelConfig; /*!< Chain channels configuration. */
} adc_chain_config_t;

/*!
 * @brief This structure is used to configure the ADC analog watchdog.
 */
typedef struct _adc_wdg_config
{
    uint8_t wdgIndex;                        /*!< Indicates the analog watchdog index */
    adc_wdg_threshold_int_t wdgThresholdInt; /*!< Selects watchdog threshold low or/and high interrupt
                                             to enable/disable. */
    uint16_t lowThresholdVal;                /*!< Sets the ADC analog watchdog low threshold value. */
    uint16_t highThresholdVal;               /*!< Sets the ADC analog watchdog high threshold value. */
} adc_wdg_config_t;

/*!
 * @brief This structure is used to configure the ADC calibration.
 */
typedef struct _adc_calibration_config
{
    bool enableAverage;                                /*!< Decides whether to enable averaging of calibration time. */
    adc_sample_time_t sampleTime;                      /*!< Selects sample time of calibration conversions. */
    adc_average_sample_numbers_t averageSampleNumbers; /*!< Selects calibration averaging sample numbers. */
} adc_calibration_config_t;

/*!
 * @brief This structure is used to configure the ADC user offset and gain.
 */
typedef struct _adc_user_offset_gain_config
{
    int8_t userOffset; /*!< Sets user defined gain value. */
    int16_t userGain;  /*!< Sets user defined offset value. */
} adc_user_offset_gain_config_t;

/*!
 * @brief This structure is used to configure the ADC self-test.
 */
typedef struct _adc_self_test_config
{
    adc_alg_type_t algType; /*!< Selects the self-test algorithm. */
    uint8_t algSteps;       /*!< Sets the self-test algorithm steps, it should be programmed to zero in scan mode. */
    uint8_t algSSamplePhaseDuration; /*!< Sets the self-test algorithm S conversion sampling phase duration. */
    uint8_t algCSamplePhaseDuration; /*!< Sets the self-test algorithm C conversion sampling phase duration. */
    uint8_t baudRate; /*!< Sets the baud rate for the selected algorithm in scan mode, must write to this field before
                      enabling a self-test channel. */
} adc_self_test_config_t;

/*!
 * @brief This structure is used to configure the ADC self-test watchdog for algorithm steps.
 *
 * @note The algorithm S step 2 only has the 'LowThrsholdVal'.
 */
typedef struct _adc_self_test_wdg_config
{
    adc_self_test_wdg_threshold_t wdgThresholdId; /*!< Indicates the self-test watchdog index */
    uint16_t lowThrsholdVal;                      /*!< Sets the self-test watchdog low threshold value. */
    uint16_t highThrsholdVal;                     /*!< Sets the self-test watchdog high threshold value. */
} adc_self_test_wdg_config_t;

/*!
 * @brief This structure is used to save the result information when obtaining the conversion result.
 */
typedef struct _adc_conv_result
{
    bool overWrittenFlag; /*!< Indicates when conversion data was overwritten by a newer result, the new data is written
                          or discarded according to MCR[OWREN]. */
    uint8_t convMode;     /*!< Indicates the mode of conversion for the corresponding channel. */
    uint16_t convData;    /*!< Stores the conversion data corresponding to the internal channel. */
} adc_conv_result_t;

/*!
 * @brief This structure is used to save the result information when obtaining the self-test channel conversion result.
 *
 * @note The member 'convData' is used to store self-test channel conversion results. Only when executing step 1 of
 * algorithm S, member 'convDataFraction' will be used to store the fractional part data. When executing other
 * algorithms, this member will not be used.
 */
typedef struct _adc_self_test_conv_result
{
    bool overWrittenFlag;      /*!< Indicates when conversion data is overwritten by a newer result. */
    uint16_t convData;         /*!< Stores the conversion data corresponding to the internal self-test channel.*/
    uint16_t convDataFraction; /*!< This field is only used to store the fractional part conversion result.*/
} adc_self_test_conv_result_t;

/******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name ADC Initialization, De-Initialization, and Configuration.
 * @{
 */
/*!
 * @brief This function is used to get available predefined configurations for the ADC initialization.
 *
 * @param config Pointer to the ADC configuration structure, please refer to @ref adc_config_t for details.
 */
void ADC_GetDefaultConfig(adc_config_t *config);

/*!
 * @brief This function is used to initialize the ADC.
 *
 * @param base ADC peripheral base address.
 * @param config Pointer to the ADC configuration structure, please refer to @ref adc_config_t for details.
 */
void ADC_Init(ADC_Type *base, const adc_config_t *config);

/*!
 * @brief This function is used to de-initialize the ADC.
 *
 * @param base ADC peripheral base address.
 */
void ADC_Deinit(ADC_Type *base);

/*!
 * @brief This function is used to enter or exit power-down mode.
 *
 * @details After the release of the reset, the ADC analog module will be kept in power-down mode by default. The
 * power-down mode can be set anytime. However, ADC can enter the power-down mode successfully only after completion
 * of an ongoing conversion (if there is one). In scan mode, the ongoing operation should be aborted manually before
 * or after switching mode. If the power-down mode is entered by setting MCR[PWDN], the process running in the previous
 * mode must be restarted manually (by setting the appropriate START bit in the MCR register) after exiting power-down
 * mode.
 *
 * @note After setting the ADC mode, it is recommended to use the function @ref ADC_GetAdcState to query whether the
 * ADC has correctly entered the mode.
 *
 * @param base ADC peripheral base address.
 * @param enable Indicates whether to enter or exit power-down mode.
 * - \b true Request to enter power-down mode.
 * - \b false When ADC status is in power-down mode (MSR[ADCSTATUS] = 001b), start ADC transition to IDLE mode.
 */
static inline void ADC_SetPowerDownMode(ADC_Type *base, bool enable)
{
    if (enable)
    {
        base->MCR |= ADC_MCR_PWDN_MASK;
    }
    else
    {
        base->MCR &= ~ADC_MCR_PWDN_MASK;
    }
}

/*!
 * @brief This function is used to select the ADC operating clock.
 *
 * @note Needs to enter power-down mode before changing the ADC internal operating clock.
 *
 * @param base ADC peripheral base address.
 * @param clockSelect ADC clock frequency selection, please refer to @ref adc_clock_frequency_t for details.
 */
static inline void ADC_SetOperatingClock(ADC_Type *base, adc_clock_frequency_t clockSelect)
{
#if !(defined(FSL_FEATURE_ADC_HAS_MCR_ADCLKSE) && (FSL_FEATURE_ADC_HAS_MCR_ADCLKSE==0U))
    if (kADC_HalfBusFrequency == clockSelect)
    {
        base->MCR &= ~ADC_MCR_ADCLKSE_MASK;
    }
    else
    {
        base->MCR |= ADC_MCR_ADCLKSE_MASK;
    }
#endif /* FSL_FEATURE_ADC_HAS_MCR_ADCLKSE */
#if (defined(FSL_FEATURE_ADC_HAS_MCR_ADCLKSEL) && (FSL_FEATURE_ADC_HAS_MCR_ADCLKSEL==1U))
    base->MCR = ((base->MCR & ~ADC_MCR_ADCLKSEL_MASK) | ADC_MCR_ADCLKSEL(clockSelect));
#endif /* FSL_FEATURE_ADC_HAS_MCR_ADCLKSEL */
}

#if defined(FSL_FEATURE_ADC_HAS_AMSIO) && (FSL_FEATURE_ADC_HAS_AMSIO==1U)
/*!
 * @brief This function is used to set the ADC speed mode.
 *
 *
 * @param base ADC peripheral base address.
 * @param speedMode ADC speed mode selection, please refer to @ref adc_speed_mode_t for details.
 */
static inline void ADC_SetAdcSpeedMode(ADC_Type *base, adc_speed_mode_t speedMode)
{
    base->AMSIO = ((base->AMSIO & ~ADC_AMSIO_HSEN_MASK) | ADC_AMSIO_HSEN(speedMode));
}
#endif /* FSL_FEATURE_ADC_HAS_AMSIO */

/*!
 * @}
 */

/*!
 * @name ADC main status.
 * @{
 */
/*!
 * @brief This function is used to get the ADC state.
 *
 * @param base ADC peripheral base address.
 *
 * @return ADC state, for possible states, please refer to @ref adc_state_t for details.
 */
static inline adc_state_t ADC_GetAdcState(ADC_Type *base)
{
    return (adc_state_t)(uint32_t)((base->MSR & ADC_MSR_ADCSTATUS_MASK) >> ADC_MSR_ADCSTATUS_SHIFT);
}

/*!
 * @brief This function is used to check whether the ADC auto clock-off feature has been enabled or not.
 *
 * @param base ADC peripheral base address.
 *
 * @return ADC auto clock-off feature status.
 * - \b true Auto clock-off feature has been enabled.
 * - \b false Auto clock-off feature has not been enabled.
 */
static inline bool ADC_CheckAutoClockOffEnabled(ADC_Type *base)
{
    return (0UL != ((base->MSR & ADC_MCR_ACKO_MASK) >> ADC_MCR_ACKO_SHIFT));
}

/*!
 * @brief This function is used to get the ID of the channel that is currently being converted.
 *
 * @param base ADC peripheral base address.
 *
 * @return ADC channel ID that is currently being converted.
 */
static inline uint8_t ADC_GetCurrentConvertedChannelId(ADC_Type *base)
{
    return (uint8_t)((base->MSR & ADC_MSR_CHADDR_MASK) >> ADC_MSR_CHADDR_SHIFT);
}

/*!
 * @brief This function is used to check whether the self-test conversion is in process or not.
 *
 * @param base ADC peripheral base address.
 *
 * @return Self-test conversion status.
 * - \b true Self-test conversion is in process.
 * - \b false Self-test conversion is not in process.
 */
static inline bool ADC_CheckSelfTestConvInProcess(ADC_Type *base)
{
    return (0UL != ((base->MSR & ADC_MSR_SELF_TEST_S_MASK) >> ADC_MSR_SELF_TEST_S_SHIFT));
}

#if defined(FSL_FEATURE_ADC_HAS_BCTUMODE) && (FSL_FEATURE_ADC_HAS_BCTUMODE==1U)
/*!
 * @brief This function is used to check whether the BCTU conversion was started.
 *
 * @param base ADC peripheral base address.
 *
 * @return BCTU conversion status.
 * - \b true Ongoing conversion was triggered by BCTU.
 * - \b false Conversion was not triggered by BCTU.
 */
static inline bool ADC_CheckBctuConvStatus(ADC_Type *base)
{
    return (0UL != ((base->MSR & ADC_MSR_BCTUSTART_MASK) >> ADC_MSR_BCTUSTART_SHIFT));
}
#endif /* FSL_FEATURE_ADC_HAS_BCTUMODE */

/*!
 * @brief This function is used to check whether the inject conversion is in process or not.
 *
 * @param base ADC peripheral base address.
 *
 * @return Inject conversion status.
 * - \b true Inject conversion is in process.
 * - \b false Inject conversion is not in process.
 */
static inline bool ADC_CheckInjectConvInProcess(ADC_Type *base)
{
    return (0UL != ((base->MSR & ADC_MSR_JSTART_MASK) >> ADC_MSR_JSTART_SHIFT));
}

/*!
 * @brief This function is used to check whether the inject conversion has been aborted or not.
 *
 * @param base ADC peripheral base address.
 *
 * @return Inject conversion abort status.
 * - \b true Injected conversion has been aborted.
 * - \b false Injected conversion has not been aborted.
 */
static inline bool ADC_CheckInjectConvAborted(ADC_Type *base)
{
    return (0UL != ((base->MSR & ADC_MSR_JABORT_MASK) >> ADC_MSR_JABORT_SHIFT));
}

/*!
 * @brief This function is used to check whether the normal conversion is in process or not.
 *
 * @param base ADC peripheral base address.
 *
 * @return Normal conversion status.
 * - \b true Normal conversion is in process.
 * - \b false Normal conversion is not in process.
 */
static inline bool ADC_CheckNormalConvInProcess(ADC_Type *base)
{
    return (0UL != ((base->MSR & ADC_MSR_NSTART_MASK) >> ADC_MSR_NSTART_SHIFT));
}

#if (defined(FSL_FEATURE_ADC_HAS_CALBISTREG) && (FSL_FEATURE_ADC_HAS_CALBISTREG==1U))
/*!
 * @brief This function is used to check whether the ADC is executing calibration or ready for use.
 *
 * @param base ADC peripheral base address.
 *
 * @return Calibration process status.
 * - \b true ADC is busy in a calibration process.
 * - \b false ADC is ready for use.
 */
static inline bool ADC_CheckCalibrationBusy(ADC_Type *base)
{
    return (0UL != ((base->CALBISTREG & ADC_CALBISTREG_C_T_BUSY_MASK) >> ADC_CALBISTREG_C_T_BUSY_SHIFT));
}

/*!
 * @brief This function is used to check whether the calibration has failed or passed.
 *
 * @note When the user clears the calibration failed status and then reads the status, it will display the calibration
 * passed. At this time, the calibration may not be successful. The user must read the MSR[CALBUSY] bit by function @ref
 * ADC_CheckCalibrationBusy to perform a double check.
 *
 * @return Normal conversion status.
 * - \b true Calibration failed.
 * - \b false Calibration passed (must be checked with CALBUSY = 0b).
 */
static inline bool ADC_CheckCalibrationFailed(ADC_Type *base)
{
    return (0UL != ((base->CALBISTREG & ADC_CALBISTREG_TEST_FAIL_MASK) >> ADC_CALBISTREG_TEST_FAIL_SHIFT));
}

/*!
 * @brief This function is used to clear the flag of calibration.
 *
 * @param base ADC peripheral base address.
 */
static inline void ADC_ClearCalibrationFailedFlag(ADC_Type *base)
{
    base->CALBISTREG = ADC_CALBISTREG_TEST_FAIL_MASK;
}
#else
/*!
 * @brief This function is used to check whether the ADC is executing calibration or ready for use.
 *
 * @param base ADC peripheral base address.
 *
 * @return Calibration process status.
 * - \b true ADC is busy in a calibration process.
 * - \b false ADC is ready for use.
 */
static inline bool ADC_CheckCalibrationBusy(ADC_Type *base)
{
    return (0UL != ((base->MSR & ADC_MSR_CALBUSY_MASK) >> ADC_MSR_CALBUSY_SHIFT));
}

/*!
 * @brief This function is used to check whether the calibration has failed or passed.
 *
 * @note When the user clears the calibration failed status and then reads the status, it will display the calibration
 * passed. At this time, the calibration may not be successful. The user must read the MSR[CALBUSY] bit by function @ref
 * ADC_CheckCalibrationBusy to perform a double check.
 *
 * @return Normal conversion status.
 * - \b true Calibration failed.
 * - \b false Calibration passed (must be checked with CALBUSY = 0b).
 */
static inline bool ADC_CheckCalibrationFailed(ADC_Type *base)
{
    return (0UL != ((base->MSR & ADC_MSR_CALFAIL_MASK) >> ADC_MSR_CALFAIL_SHIFT));
}

/*!
 * @brief This function is used to clear the flag of calibration.
 *
 * @param base ADC peripheral base address.
 */
static inline void ADC_ClearCalibrationFailedFlag(ADC_Type *base)
{
    base->MSR = ADC_MSR_CALFAIL_MASK;
}
#endif /* FSL_FEATURE_ADC_HAS_CALBISTREG */

/*!
 * @brief This function is used to check whether the calibration is successful or not.
 *
 * @param base ADC peripheral base address.
 *
 * @return Normal conversion status.
 * - \b true Calibrated or calibration successful.
 * - \b false Uncalibrated or calibration unsuccessful.
 */
static inline bool ADC_CheckCalibrationSuccessful(ADC_Type *base)
{
    return (0UL != ((base->MSR & ADC_MSR_CALIBRTD_MASK) >> ADC_MSR_CALIBRTD_SHIFT));
}
/*!
 * @}
 */

/*!
 * @name ADC chain and channel configuration.
 * @{
 */
/*!
 * @brief This function is used to configure the chain.
 *
 * @param base ADC peripheral base address.
 * @param config Pointer to the chain configuration structure, please refer to @ref adc_chain_config_t for details.
 */
void ADC_SetConvChainConfig(ADC_Type *base, const adc_chain_config_t *config);

/*!
 * @brief This function is used to enable the specific ADC channel to execute normal conversion.
 *
 * @param base ADC peripheral base address.
 * @param channelIndex Channel index to enable the normal conversion.
 */
static inline void ADC_EnableSpecificChannelNormalConv(ADC_Type *base, uint8_t channelIndex)
{
    NCMR_IO(base, GET_REGINDEX(channelIndex)) |= ((uint32_t)0x01U << GET_BITINDEX(channelIndex));
}

/*!
 * @brief This function is used to disable the specific ADC channel to execute the normal conversion.
 *
 * @param base ADC peripheral base address.
 * @param channelIndex Channel index to disable the normal conversion.
 */
static inline void ADC_DisableSpecificChannelNormalConv(ADC_Type *base, uint8_t channelIndex)
{
    NCMR_IO(base, GET_REGINDEX(channelIndex)) &= ~((uint32_t)0x01U << GET_BITINDEX(channelIndex));
}

/*!
 * @brief This function is used to enable the specific ADC channel to execute the inject conversion.
 *
 * @param base ADC peripheral base address.
 * @param channelIndex Channel index to enable the inject conversion.
 */
static inline void ADC_EnableSpecificChannelInjectConv(ADC_Type *base, uint8_t channelIndex)
{
    JCMR_IO(base, GET_REGINDEX(channelIndex)) |= ((uint32_t)0x01U << GET_BITINDEX(channelIndex));
}

/*!
 * @brief This function is used to disable the specific ADC channel to execute the inject conversion.
 *
 * @param base ADC peripheral base address.
 * @param channelIndex Channel index to disable the inject conversion.
 */
static inline void ADC_DisableSpecificChannelInjectConv(ADC_Type *base, uint8_t channelIndex)
{
    JCMR_IO(base, GET_REGINDEX(channelIndex)) &= ~((uint32_t)0x01U << GET_BITINDEX(channelIndex));
}

/*!
 * @brief This function is used to set the ADC conversion mode.
 *
 * @note Before setting the conversion mode, users need to check whether the ADC is in the idle status through the
 * function @ref ADC_GetAdcState.
 *
 * @param base ADC peripheral base address.
 * @param convMode ADC conversion mode, please refer to @ref adc_conv_mode_t for details.
 */
static inline void ADC_SetConvMode(ADC_Type *base, adc_conv_mode_t convMode)
{
    /* Scan mode. */
    if (convMode == kADC_NormalConvScanMode)
    {
        base->MCR |= ADC_MCR_MODE_MASK;
    }
    else /* one-shot mode. */
    {
        base->MCR &= ~ADC_MCR_MODE_MASK;
    }
}

/*!
 * @brief This function is used to start the ADC conversion chain to execute the conversion.
 *
 * @note Normal conversion supports two conversion modes, one is one-shot conversion mode, and the other is scan
 * conversion mode. Normal conversion should usually be used to convert analog samples most of the time in an
 * application, unless there is a special need. Inject conversion has a higher priority than normal conversion and it
 * runs in one-shot mode only, it can be started in IDLE condition or when normal conversion is in process.
 *
 * @param base ADC peripheral base address.
 * @param convMode Pointer to the ADC conversion chain, please refer to @ref adc_conv_mode_t for details.
 */
static inline void ADC_StartConvChain(ADC_Type *base, adc_conv_mode_t convMode)
{
    /* Inject conversion. */
    if (convMode == kADC_InjectConvOneShotMode)
    {
        base->MCR |= ADC_MCR_JSTART_MASK;
    }
    else /* Normal conversion. */
    {
        base->MCR |= ADC_MCR_NSTART_MASK;
    }
}

/*!
 * @brief This function is used to stop scan in normal conversion scan operation mode.
 *
 * @note In scan operation mode, the MCR[NSTART] field remains high after setting. Clearing this field 
 * in scan operation mode causes the current chain conversion to finish, then stop the scan.
 *
 * @param base ADC peripheral base address.
 */
static inline void ADC_StopConvChain(ADC_Type *base)
{
    base->MCR &= ~ADC_MCR_NSTART_MASK;
}

/*!
 * @brief This function is used to abort the conversion chain.
 *
 * @details Abort the current chain of conversions by setting MCR[ABORTCHAIN]. In that case, the behavior of the ADC
 * depends on MCR[MODE] (one-shot/scan conversion modes). In one-shot mode, MSR[NSTART] is automatically reset together
 * with MCR[ABORTCHAIN], an end-of-chain interrupt is not generated in the case of an abort chain. In scan mode, a new
 * chain is started. The end-of-conversion interrupt of the current aborted conversion is not generated but an
 * end-of-chain interrupt is generated.
 *
 * @note Setting this field in an IDLE state (for example, no normal/inject conversion is in process) has no effect. In
 * this case, the MCR[ABORTCHAIN] field is reset immediately.
 *
 * @param base ADC peripheral base address.
 */
static inline void ADC_AbortCurrentConvChain(ADC_Type *base)
{
    base->MCR |= ADC_MCR_ABORTCHAIN_MASK;
}

/*!
 * @brief This function is used to abort the conversion channel.
 *
 * @details Abort the current conversion and immediately start the conversion of the next channel of the chain. In the
 * case of an abort operation, MSR[NSTART/JSTART] remains set if not in the last channel of the chain, and MCR[ABORT] is
 * reset as soon as the channel is aborted. The end-of-conversion interrupt corresponds to the aborted channel is
 * not generated. This behavior is true for normal or inject conversion modes. If the last channel of a chain is
 * aborted, and the end-of-chain is reported, then an end-of-chain interrupt will be generated.
 *
 * @note This conversion can not abort while the self-test channel conversion is in process.
 *
 * @param base ADC peripheral base address.
 */
static inline void ADC_AbortCurrentConv(ADC_Type *base)
{
    base->MCR |= ADC_MCR_ABORT_MASK;
}

/*!
 * @brief This function is used to enable the ADC end-of-conversion and end-of-chain interrupts.
 *
 * @param base ADC peripheral base address.
 * @param mask Mask value to enable the ADC end-of-conversion and end-of-chain interrupts, please
 * refer to @ref _adc_conv_int_enable for details.
 */
static inline void ADC_EnableConvInt(ADC_Type *base, uint32_t mask)
{
    base->IMR |= mask;
}

/*!
 * @brief This function is used to disable the ADC end-of-conversion and end-of-chain interrupts.
 *
 * @param base ADC peripheral base address.
 * @param mask Mask value to disable the ADC end-of-conversion and end-of-chain interrupts, please
 * refer to @ref _adc_conv_int_enable for details.
 */
static inline void ADC_DisableConvInt(ADC_Type *base, uint32_t mask)
{
    base->IMR &= ~mask;
}

/*!
 * @brief This function is used to get the ADC end-of-conversion and end-of-chain interrupts status.
 *
 * @param base ADC peripheral base address.
 *
 * @return ADC end-of-conversion and end-of-chain interrupts status mask.
 */
static inline uint32_t ADC_GetConvIntStatus(ADC_Type *base)
{
    return base->ISR;
}

/*!
 * @brief This function is used to clear the ADC end-of-conversion and end-of-chain interrupts status.
 *
 * @param base ADC peripheral base address.
 * @param mask Mask value for flags to be cleared, please refer to @ref _adc_conv_int_flag for details.
 */
static inline void ADC_ClearConvIntStatus(ADC_Type *base, uint32_t mask)
{
    base->ISR = mask;
}

/*!
 * @brief This function is used to enable the specific ADC channel end-of-conversion interrupt.
 *
 * @note This function can only turn on the interrupt of a specific channel, if the interrupt occurs, the user also
 * needs to turn on the global end-of-conversion interrupt by using function @ref ADC_EnableConvInt
 *
 * @param base ADC peripheral base address.
 * @param channelIndex Channel index to enable the end-of-conversion interrupt.
 */
static inline void ADC_EnableSpecificConvChannelInt(ADC_Type *base, uint8_t channelIndex)
{
    CIMR_IO(base, GET_REGINDEX(channelIndex)) |= ((uint32_t)0x01U << GET_BITINDEX(channelIndex));
}

/*!
 * @brief This function is used to disable the specific ADC channel end-of-conversion interrupt.
 *
 * @param base ADC peripheral base address.
 * @param channelIndex Channel index to disable the end-of-conversion interrupt.
 */
static inline void ADC_DisableSpecificConvChannelInt(ADC_Type *base, uint8_t channelIndex)
{
    CIMR_IO(base, GET_REGINDEX(channelIndex)) &= ~((uint32_t)0x01U << GET_BITINDEX(channelIndex));
}

/*!
 * @brief This function is used to check whether the specific conversion channel's end-of-conversion interrupt has been
 * occured.
 *
 * @param base ADC peripheral base address.
 * @param channelIndex Channel index to check the end-of-conversion interrupt status.
 *
 * @return Channel end-of-conversion interrupt status flag of the specific channel.
 * - \b true Channel end-of-conversion interrupt has been occured.
 * - \b false Channel end-of-conversion interrupt has not been occured.
 */
static inline bool ADC_CheckSpecificConvChannelInt(ADC_Type *base, uint8_t channelIndex)
{
    return (0U != ((CEOCFR_I(base, GET_REGINDEX(channelIndex)) & ((uint32_t)0x01U << channelIndex)) >> channelIndex));
}

/*!
 * @brief This function is used to clear specific channel end-of-conversion interrupt flag.
 *
 * @param base ADC peripheral base address.
 * @param channelIndex Channel index to clear the end-of-conversion interrupt flag.
 */
static inline void ADC_ClearSpecificConvChannelInt(ADC_Type *base, uint8_t channelIndex)
{
    CEOCFR_IO(base, GET_REGINDEX(channelIndex)) = ((uint32_t)0x01U << GET_BITINDEX(channelIndex));
}
/*!
 * @}
 */

/*!
 * @name DMA transfer and pre-sample configuration.
 * @{
 */
/*!
 * @brief This function is used to enable the DMA transfer function.
 *
 * @note This function is a master switch used to control whether the data converted by the ADC is transmitted through
 * DMA. If the user configures DMA to transmit the conversion data of the channel during the chain channel configuration
 * process, then the main switch of the DMA transmission must be turned on, otherwise, data transmission cannot be
 * performed.
 *
 * @param base ADC peripheral base address.
 */
static inline void ADC_EnableDmaTransfer(ADC_Type *base)
{
    base->DMAE |= ADC_DMAE_DMAEN_MASK;
}

/*!
 * @brief This function is used to disable the DMA transfer function.
 *
 * @param base ADC peripheral base address.
 */
static inline void ADC_DisableDmaTransfer(ADC_Type *base)
{
    base->DMAE &= ~ADC_DMAE_DMAEN_MASK;
}

/*!
 * @brief This function is used to enable the specific ADC conversion channel's DMA transfer function.
 *
 * @note This function can only turn on the DMA transfer of a specific channel, before using the DMA transfer, the user
 * needs to turn on the global DMA transfer by using the function @ref ADC_EnableDmaTransfer.
 *
 * @param base ADC peripheral base address.
 * @param channelIndex Channel index to enable the DMA transfer function.
 */
static inline void ADC_EnableSpecificConvChannelDmaTransfer(ADC_Type *base, uint8_t channelIndex)
{
    DMAR_IO(base, GET_REGINDEX(channelIndex)) |= ((uint32_t)0x01U << GET_BITINDEX(channelIndex));
}

/*!
 * @brief This function is used to disable the specific ADC conversion channel's DMA transfer function.
 *
 * @param base ADC peripheral base address.
 * @param channelIndex Channel index to disable the DMA transfer function.
 */
static inline void ADC_DisableSpecificConvChannelDmaTransfer(ADC_Type *base, uint8_t channelIndex)
{
    DMAR_IO(base, GET_REGINDEX(channelIndex)) &= ~((uint32_t)0x01U << GET_BITINDEX(channelIndex));
}

/*!
 * @brief This function is used to enable the specific ADC conversion channel's pre-sample function.
 *
 * @param base ADC peripheral base address.
 * @param channelIndex Channel index to enable the pre-sample function.
 */
static inline void ADC_EnableSpecificConvChannelPresample(ADC_Type *base, uint8_t channelIndex)
{
    PSR_IO(base, GET_REGINDEX(channelIndex)) |= ((uint32_t)0x01U << GET_BITINDEX(channelIndex));
}

/*!
 * @brief This function is used to disable the specific ADC conversion channel's pre-sample function.
 *
 * @param base ADC peripheral base address.
 * @param channelIndex Channel index to disable the pre-sample function.
 */
static inline void ADC_DisableSpecificConvChannelPresample(ADC_Type *base, uint8_t channelIndex)
{
    PSR_IO(base, GET_REGINDEX(channelIndex)) &= ~((uint32_t)0x01U << GET_BITINDEX(channelIndex));
}
/*!
 * @}
 */

/*!
 * @name Analog watchdog
 * @{
 */
/*!
 * @brief This function is used to configure the analog watchdog.
 *
 * @details The analog watchdogs are used to monitor the conversion result to see if it is within defined limits,
 * specified by a higher and a lower threshold value. After the conversion of the selected channel, a comparison is
 * performed between the converted value and the threshold values. If the converted value is outside the threshold
 * values, then a corresponding threshold violation interrupt is generated.
 *
 * @param base ADC peripheral base address.
 * @param config Pointer to the analog watchdog configuration structure, please refer to @ref adc_wdg_config_t for
 * details.
 */
void ADC_SetAnalogWdgConfig(ADC_Type *base, const adc_wdg_config_t *config);

/*!
 * @brief This function is used to enable the specific ADC conversion channel's analog watchdog function.

 * @param base ADC peripheral base address.
 * @param channelIndex Conversion channel index to enable the analog watchdog function.
 */
static inline void ADC_EnableSpecificConvChannelAnalogWdg(ADC_Type *base, uint8_t channelIndex)
{
    CWENR_IO(base, GET_REGINDEX(channelIndex)) |= ((uint32_t)0x01U << GET_BITINDEX(channelIndex));
}

/*!
 * @brief This function is used to disable the specific ADC conversion channel's analog watchdog function.

 * @param base ADC peripheral base address.
 * @param channelIndex Conversion channel index to disable the analog watchdog function.
 */
static inline void ADC_DisableSpecificConvChannelAnalogWdg(ADC_Type *base, uint8_t channelIndex)
{
    CWENR_IO(base, GET_REGINDEX(channelIndex)) &= ~((uint32_t)0x01U << GET_BITINDEX(channelIndex));
}

/*!
 * @brief This function is used to check whether the specific conversion channel's converted data is out of range.
 *
 * @param base ADC peripheral base address.
 * @param channelIndex Channel index to check the converted data out of range status.
 *
 * @return Converted data out of range status of the specific conversion channel.
 * - \b true Channel converted data is out of range.
 * - \b false Channel converted data is in range.
 */
static inline bool ADC_CheckSpecificConvChannelOutofRange(ADC_Type *base, uint8_t channelIndex)
{
    return (0U != ((AWORR_I(base, GET_REGINDEX(channelIndex)) & ((uint32_t)0x1U << channelIndex)) >> channelIndex));
}

/*!
 * @brief This function is used to clear the specific conversion channel's converted data out-of-range flag.
 *
 * @param base ADC peripheral base address.
 * @param channelIndex Channel index to clear the converted data out of range flag.
 */
static inline void ADC_ClearSpecificConvChannelOutofRange(ADC_Type *base, uint8_t channelIndex)
{
    AWORR_IO(base, GET_REGINDEX(channelIndex)) = ((uint32_t)0x1U << GET_BITINDEX(channelIndex));
}

/*!
 * @brief This function is used to enable the analog watchdog threshold low or/and high interrupts.
 *
 * @param base ADC peripheral base address.
 * @param mask Mask value to enable the analog watchdog threshold low or/and high interrupts, please
 * refer to @ref _adc_wdg_threshold_int_enable for details.
 */
static inline void ADC_EnableWdgThresholdInt(ADC_Type *base, uint32_t mask)
{
    base->WTIMR |= mask;
}

/*!
 * @brief This function is used to disable the analog watchdog threshold low or/and high interrupts.
 *
 * @param base ADC peripheral base address.
 * @param mask Mask value to disable the analog watchdog threshold low or/and high interrupts, please
 * refer to @ref _adc_wdg_threshold_int_enable for details.
 */
static inline void ADC_DisableWdgThresholdInt(ADC_Type *base, uint32_t mask)
{
    base->WTIMR &= ~mask;
}

/*!
 * @brief This function is used to get the analog watchdog threshold interrupts status.
 *
 * @param base ADC peripheral base address.
 *
 * @return Analog watchdog threshold interrupts status mask.
 */
static inline uint32_t ADC_GetWdgThresholdIntStatus(ADC_Type *base)
{
    return base->WTISR;
}

/*!
 * @brief This function is used to clear the analog watchdog threshold low or/and high interrupts status.
 *
 * @param base ADC peripheral base address.
 * @param mask Mask value for flags to be cleared, please refer to @ref _adc_wdg_threshold_int_flag for details.
 */
static inline void ADC_ClearWdgThresholdIntStatus(ADC_Type *base, uint32_t mask)
{
    base->WTISR = mask;
}
/*!
 * @}
 */

/*!
 * @name Calibration and self-test
 * @{
 */
/*!
 * @brief This function is used to do the calibration.
 *
 * @details The calibration is used to reduce or eliminate the various errors. In the calibration process, the
 * calibration values for offset, gain, and capacitor mismatch are obtained. These calibration values (except gain
 * calibration) are used in a result post-processing step to reduce or eliminate the various errors contribution
 * effects. The gain calibration is used during the sample phase to define the additional charge to be loaded in order
 * to compensate for the gain failure. Calibration must be performed after every power-up reset and whenever required in
 * runtime operation. It is also recommended to run calibration if the operating conditions (particularly VrefH) change.
 * Never apply functional reset during the calibration process. If applied, calibration must be rerun after exiting a
 * reset condition; otherwise, the calibration-generated values and conversion results may be unspecified.
 *
 * @note This function executes a calibration sequence, it is recommended to run this sequence before using the ADC
 * converter. The maximum clock frequency for the calibration is 40 MHz. Before calling this function, the user needs
 * to ensure that the input clock is within 40MHz. The results of individual steps are also updated in the CALSTAT
 * register (CALSTAT[STAT_n]). The result of the last failed step is dynamically updated in the same register.
 *
 * @param base ADC peripheral base address.
 * @param config Pointer to the calibration configuration structure, please refer to @ref adc_calibration_config_t for
 * details.
 *
 * @return Status whether calibration is running passed or failed.
 * - \b true Calibration successful.
 * - \b false Calibration unsuccessful.
 */
bool ADC_DoCalibration(ADC_Type *base, const adc_calibration_config_t *config);

/*!
 * @brief This function is used to configure the user gain and offset.
 *
 * @param base ADC peripheral base address.
 * @param config Pointer to the user offset and gain configuration structure, please refer to @ref
 * adc_user_offset_gain_config_t for details.
 */
void ADC_SetUserOffsetAndGainConfig(ADC_Type *base, const adc_user_offset_gain_config_t *config);

/*!
 * @brief This function is used to configure the ADC self-test.
 *
 * @details The self-test is used to check at regular intervals whether ADC is operating correctly. When self-test is
 * enabled, ADC automatically checks its components and flags any errors it finds. The test can be enabled to check the
 * supply voltage (VDD), reference voltage (VrefH), and calibrated values.
 *
 * @note Before calling this function, please ensure the functional conversion is one-shot conversion mode normal
 * conversion type and the operating clock are equal to bus frequency. ADC self-test should be run with MCR[ADCLKSE]
 * bit set to 1. Self-test with ADCLKSE bit set to 0 can give erroneous results.
 *
 * @param base ADC peripheral base address.
 * @param config Pointer to the self-test configuration structure, please refer to @ref adc_self_test_config_t for
 * details.
 */
void ADC_SetSelfTestConfig(ADC_Type *base, const adc_self_test_config_t *config);

/*!
 * @brief This function is used to configure the ADC self-test watchdog.
 *
 * @param base ADC peripheral base address.
 * @param config Pointer to the self-test watchdog configuration structure, please refer to @ref
 * adc_self_test_wdg_config_t for details.
 */
void ADC_SetSelfTestWdgConfig(ADC_Type *base, const adc_self_test_wdg_config_t *config);

#if !(defined(FSL_FEATURE_ADC_HAS_CALSTAT) && (FSL_FEATURE_ADC_HAS_CALSTAT==0U))
/*!
 * @brief This function is used to get the test result for the last failed test.
 *
 * @param base ADC peripheral base address.
 * @param result Points to a 16-bit signed variable, and it is used to store the test result for the last failing
 * test.
 */
void ADC_GetCalibrationLastFailedTestResult(ADC_Type *base, int16_t *result);

/*!
 * @brief This function is used to get the status of the calibration steps.
 *
 * @note The status of calibration steps (step 0 to step 12) is stored in the CALSTAT register, and only the lower
 * 12 bits are available in the returned result.
 *
 * @param base ADC peripheral base address.
 *
 * @return ADC self-test interrupt status mask.
 */
static inline uint16_t ADC_GetCalibrationStepsStatus(ADC_Type *base)
{
    return (uint16_t)(base->CALSTAT & 0xFFFFU);
}
#endif /* FSL_FEATURE_ADC_HAS_CALSTAT */

/*!
 * @brief This function is used to enable the ADC self-test.
 *
 * @details Decides whether to enable the ADC self-test. The self-test test is enabled by setting STCR2[EN], this field
 * must be set before starting normal conversion and should not be changed while the conversion is in process. This
 * field should only be reset after the end-of-conversion of the last self-test channel has been received.
 *
 * @note ADC self-test should be run with MCR[ADCLKSE] bit set to 1. Self-test with ADCLKSE bit set to 0 can give
 * erroneous results. In the case of Inject Conversion mode, test channel conversion is not performed. It is performed
 * only during normal conversions.
 *
 * @param base ADC peripheral base address.
 */
static inline void ADC_EnableSelfTest(ADC_Type *base)
{
    base->STCR2 |= ADC_STCR2_EN_MASK;
}

/*!
 * @brief This function is used to disable the ADC self-test.
 *
 * @param base ADC peripheral base address.
 */
static inline void ADC_DisableSelfTest(ADC_Type *base)
{
    base->STCR2 &= ~ADC_STCR2_EN_MASK;
}

/*!
 * @brief This function is used to enable the ADC self-test watchdog threshold for algorithm S step 0/1/2
 * and algorithm C.
 *
 * @details The user can pass @ref kADC_SelfTestWdgThresholdForAlgSStep0 as parameter 'wdgID' to enable the
 * self-test watchdog threshold function for algorithm S step 0;
 * pass @ref kADC_SelfTestWdgThresholdForAlgSStep1Integer as parameter 'wdgID' to enable the self-test
 * watchdog threshold function for algorithm S step 1;
 * pass @ref kADC_SelfTestWdgThresholdForAlgSStep2 as parameter 'wdgID' to enable the self-test watchdog
 * threshold function for algorithm S step 2;
 * pass @ref kADC_SelfTestWdgThresholdForAlgCStep0 as parameter 'wdgID' to enable the self-test watchdog
 * threshold function for algorithm C;
 * Other enumerations in @ref adc_self_test_wdg_threshold_t have no use.
 *
 * @param base ADC peripheral base address.
 * @param wdgID Watchdog threshold index to enable, please refer to @ref adc_self_test_wdg_threshold_t for details.
 */
static inline void ADC_EnableSelfTestWdgThreshold(ADC_Type *base, adc_self_test_wdg_threshold_t wdgID)
{
    if ((wdgID != kADC_SelfTestWdgThresholdForAlgCStepx)
    #if(ADC_GROUP_COUNTS==2U)
      &&(wdgID != kADC_SelfTestWdgThresholdForAlgSStep1Fraction)
    #endif /* ADC_GROUP_COUNTS */
       )
    {
        STAWR_IO(base, wdgID) |= ADC_STAWR_AWDE_MASK;
    }
}

/*!
 * @brief This function is used to disable the ADC self-test watchdog threshold for algorithm S step 0/1/2
 * and algorithm C.
 *
 * @details The user can pass @ref kADC_SelfTestWdgThresholdForAlgSStep0 as parameter 'wdgID' to disable the
 * self-test watchdog threshold function for algorithm S step 0;
 * pass @ref kADC_SelfTestWdgThresholdForAlgSStep1Integer as parameter 'wdgID' to disable the self-test
 * watchdog threshold function for algorithm S step 1;
 * pass @ref kADC_SelfTestWdgThresholdForAlgSStep2 as parameter 'wdgID' to disable the self-test watchdog
 * threshold function for algorithm S step 2;
 * pass @ref kADC_SelfTestWdgThresholdForAlgCStep0 as parameter 'wdgID' to disable the self-test watchdog
 * threshold function for algorithm C;
 * Other enumerations in @ref adc_self_test_wdg_threshold_t have no use.
 *
 * @param base ADC peripheral base address.
 * @param wdgID Watchdog threshold index to disable, please refer to @ref adc_self_test_wdg_threshold_t for details.
 */
static inline void ADC_DisableSelfTestWdgThreshold(ADC_Type *base, adc_self_test_wdg_threshold_t wdgID)
{
    if ((wdgID != kADC_SelfTestWdgThresholdForAlgCStepx)
    #if(ADC_GROUP_COUNTS==2U)
      &&(wdgID != kADC_SelfTestWdgThresholdForAlgSStep1Fraction)
    #endif /* ADC_GROUP_COUNTS */
       )
    {
        STAWR_IO(base, wdgID) &= ~ADC_STAWR_AWDE_MASK;
    }
}

/*!
 * @brief This function is used to enable the ADC self-test watchdog timer for algorithm S or/and algorithm C.
 *
 * @details The user can pass @ref kADC_SelfTestForAlgS as parameter 'wdgTimerType' to enable the watchdog timer
 * for algorithm S; pass @ref kADC_SelfTestForAlgC as parameter 'wdgTimerType' to enable the watchdog timer
 * for algorithm C; pass @ref kADC_SelfTestForAlgSAndC as parameter 'wdgTimerType' to enable the watchdog timer
 * for algorithm S and C.
 *
 * @param base ADC peripheral base address.
 * @param wdgTimerType Watchdog timer type to enable, please refer to @ref adc_alg_type_t for details.
 */
static inline void ADC_EnableSelfTestWdgTimer(ADC_Type *base, adc_alg_type_t wdgTimerType)
{
    if (wdgTimerType == kADC_SelfTestForAlgS)
    {
        base->STAW0R |= ADC_STAW0R_WDTE_MASK;
    }
    else if (wdgTimerType == kADC_SelfTestForAlgC)
    {
        base->STAW4R |= ADC_STAW4R_WDTE_MASK;
    }
    else /* wdgTimerType == kADC_SelfTestForAlgSAndC */
    {
        base->STAW0R |= ADC_STAW0R_WDTE_MASK;
        base->STAW4R |= ADC_STAW4R_WDTE_MASK;
    }
}

/*!
 * @brief This function is used to disable the ADC self-test watchdog timer.
 *
 * @details The user can pass @ref kADC_SelfTestForAlgS as parameter 'wdgTimerType' to disable the watchdog timer
 * for algorithm S; pass @ref kADC_SelfTestForAlgC as parameter 'wdgTimerType' to disable the watchdog timer
 * for algorithm C; pass @ref kADC_SelfTestForAlgSAndC as parameter 'wdgTimerType' to disable the watchdog timer
 * for algorithm S and C.
 *
 * @param base ADC peripheral base address.
 * @param wdgTimerType Watchdog timer type to disable, please refer to @ref adc_alg_type_t for details.
 */
static inline void ADC_DisableSelfTestWdgTimer(ADC_Type *base, adc_alg_type_t wdgTimerType)
{
    if (wdgTimerType == kADC_SelfTestForAlgS)
    {
        base->STAW0R &= ~ADC_STAW0R_WDTE_MASK;
    }
    else if (wdgTimerType == kADC_SelfTestForAlgC)
    {
        base->STAW4R &= ~ADC_STAW4R_WDTE_MASK;
    }
    else /* wdgTimerType == kADC_SelfTestForAlgSAndC */
    {
        base->STAW0R &= ~ADC_STAW0R_WDTE_MASK;
        base->STAW4R &= ~ADC_STAW4R_WDTE_MASK;
    }
}

/*!
 * @brief This function is used to set the ADC self-test watchdog timer value.
 *
 * @param base ADC peripheral base address.
 * @param wdgTimerVal Watchdog timer value, please refer to @ref adc_wdg_timer_val_t for details.
 */
static inline void ADC_SetSelfTestWdgTimerVal(ADC_Type *base, adc_wdg_timer_val_t wdgTimerVal)
{
    base->STBRR = ((base->STBRR & (~ADC_STBRR_WDT_MASK)) | ADC_STBRR_WDT(wdgTimerVal));
}

/*!
 * @brief This function is used to get the ADC self-test channel converted data when ERR_S0/ERR_S1_INTEGER/
 * ERR_S1_FRACTION/ERR_S2/ERR_C occurred.
 *
 * @note The user can pass @ref kADC_SelfTestWdgThresholdForAlgSStep0 as parameter 'type' to get the converted
 * data when ERR_S0 occurred;
 * pass @ref kADC_SelfTestWdgThresholdForAlgSStep1Integer as parameter 'type' to get the converted data when
 * ERR_S1_INTEGER occurred;
 * pass @ref kADC_SelfTestWdgThresholdForAlgSStep1Fraction as parameter 'type' to get the converted data when
 * ERR_S1_FRACTION occurred;
 * pass @ref kADC_SelfTestWdgThresholdForAlgSStep2 as parameter 'type' to get the converted data when ERR_S2 occurred;
 * pass @ref kADC_SelfTestWdgThresholdForAlgCStep0 as parameter 'type' to get the converted data when ERR_C occurred;
 * Other enumerations in @ref adc_self_test_wdg_threshold_t have no use.
 *
 * @param base ADC peripheral base address.
 * @param type Watchdog threshold index to get the ADC self-test channel converted data, please refer to @ref
 * adc_self_test_wdg_threshold_t for details.
 */
static inline uint16_t ADC_GetSelfTestChannelConvFailedData(ADC_Type *base, adc_self_test_wdg_threshold_t type)
{
    uint16_t data = 0U;

    switch (type)
    {
        case kADC_SelfTestWdgThresholdForAlgSStep0:
            data = (uint16_t)((base->STSR3 & ADC_STSR3_DATA0_MASK) >> ADC_STSR3_DATA0_SHIFT);
            break;
#if(ADC_GROUP_COUNTS==2U)
        case kADC_SelfTestWdgThresholdForAlgSStep1Integer:
            data = (uint16_t)((base->STSR2 & ADC_STSR2_DATA0_MASK) >> ADC_STSR2_DATA0_SHIFT);
            break;
        case kADC_SelfTestWdgThresholdForAlgSStep1Fraction:
            data = (uint16_t)((base->STSR2 & ADC_STSR2_DATA1_MASK) >> ADC_STSR2_DATA1_SHIFT);
            break;
#else /* ADC_GROUP_COUNTS==3U */
        case kADC_SelfTestWdgThresholdForAlgSStep1:
            data = (uint16_t)((base->STSR2 & ADC_STSR2_DATA0_MASK) >> ADC_STSR2_DATA0_SHIFT);
            break;
#endif /* ADC_GROUP_COUNTS */
        case kADC_SelfTestWdgThresholdForAlgSStep2:
            data = (uint16_t)((base->STSR3 & ADC_STSR3_DATA1_MASK) >> ADC_STSR3_DATA1_SHIFT);
            break;
        case kADC_SelfTestWdgThresholdForAlgCStep0:
            data = (uint16_t)((base->STSR4 & ADC_STSR4_DATA1_MASK) >> ADC_STSR4_DATA1_SHIFT);
            break;

        default:
            assert(false);
            break;
    }

    return data;
}

/*!
 * @brief This function is used to enable the ADC self-test-related interrupts.
 *
 * @note Watchdog timer feature is applicable only for scan operation mode and not for one-shot operation mode.
 *
 * @param base ADC peripheral base address.
 * @param mask Mask value to enable the ADC self-test related interrupts, please refer to @ref
 * _adc_self_test_int_enable for details.
 */
static inline void ADC_EnableSelfTestInt(ADC_Type *base, uint32_t mask)
{
    base->STCR2 |= mask;
}

/*!
 * @brief This function is used to disable the ADC self-test interrupt.
 *
 * @param base ADC peripheral base address.
 * @param mask Mask value to disable the ADC self-test related interrupts, please refer to @ref
 * _adc_self_test_int_enable for details.
 */
static inline void ADC_DisableSelfTestInt(ADC_Type *base, uint32_t mask)
{
    base->STCR2 &= ~mask;
}

/*!
 * @brief This function is used to get the ADC self-test interrupts status.
 *
 * @param base ADC peripheral base address.
 *
 * @return ADC self-test related interrupts status mask.
 */
static inline uint32_t ADC_GetSelfTestIntStatus(ADC_Type *base)
{
    return base->STSR1;
}

/*!
 * @brief This function is used to clear the ADC self-test interrupts status.
 *
 * @param base ADC peripheral base address.
 * @param mask Mask value for flags to be cleared, please refer to @ref _adc_self_test_int_flag for details.
 */
static inline void ADC_ClearSelfTestIntStatus(ADC_Type *base, uint32_t mask)
{
    base->STSR1 = mask;
}
/*!
 * @}
 */

/*!
 * @name ADC conversion result
 * @{
 */
/*!
 * @brief This function is used to get the specific ADC channel's conversion result.
 *
 * @details CDR[VALID] indicates whether a new conversion is available, this field is automatically reset to 0 when the
 * data is read. CDR[OVERW] Indicates whether the previous conversion data was overwritten without having been read, in
 * which case the overwritten data is lost.
 *
 * @param base SAR ADC peripheral base address.
 * @param result Pointer to SAR ADC channels conversion result structure, please refer to @ref adc_conv_result_t for
 * details.
 * @param channelIndex Channel index to get the conversion result.
 *
 * @return Indicates whether the acquisition of the specific channel conversion result is successful or not.
 * - \b true Obtaining the specific channel conversion result successfully, and the conversion result is stored in the
 * input parameter result.
 * - \b false Obtaining the specific channel conversion result failed.
 */
bool ADC_GetChannelConvResult(ADC_Type *base, adc_conv_result_t *result, uint8_t channelIndex);

/*!
 * @brief This function is used to get the test channel converted data when algorithm S step 0, algorithm S step 2, or
 * algorithm C step executes.
 *
 * @param base ADC peripheral base address.
 * @param result Pointer to the SAR ADC self-test channel conversion result structure, please refer to @ref
 * adc_self_test_conv_result_t for details.
 *
 * @return Indicates whether the acquisition of the self-test channel conversion result is successful or not.
 * - \b true Obtaining the self-test channel conversion result successfully, and the conversion result is stored in the
 * input parameter 'result'.
 * - \b false Obtaining the self-test channel conversion result failed.
 */
bool ADC_GetSelfTestChannelConvData(ADC_Type *base, adc_self_test_conv_result_t *result);

#if !(defined(FSL_FEATURE_ADC_HAS_STDR2) && (FSL_FEATURE_ADC_HAS_STDR2==0U))
/*!
 * @brief This function is used to get the test channel converted data when algorithm S step 1 executes.
 *
 * @param base ADC peripheral base address.
 * @param result Pointer to the SAR ADC self-test channel conversion result structure, please refer to @ref
 * adc_self_test_conv_result_t for details.
 *
 * @return Indicates whether the acquisition of the self-test channel conversion result is successful or not.
 * - \b true Obtaining the self-test channel conversion result successfully, and the conversion result is stored in the
 * input parameter 'result'.
 * - \b false Obtaining the self-test channel conversion result failed.
 */
bool ADC_GetSelfTestChannelConvDataForAlgSStep1(ADC_Type *base, adc_self_test_conv_result_t *result);
#endif /* FSL_FEATURE_ADC_HAS_STDR2 */
/*!
 * @}
 */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */

#endif /* FSL_SAR_ADC_H_ */
