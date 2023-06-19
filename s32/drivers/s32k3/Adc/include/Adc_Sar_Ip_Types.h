/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ADC_SAR_IP_TYPES_H
#define ADC_SAR_IP_TYPES_H

/**
*   @file
*
*   @addtogroup adc_sar_ip Adc Sar IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "Adc_Sar_Ip_CfgDefines.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_SAR_IP_VENDOR_ID_TYPES                      43
#define ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_TYPES       4
#define ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_TYPES       7
#define ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_TYPES    0
#define ADC_SAR_IP_SW_MAJOR_VERSION_TYPES               3
#define ADC_SAR_IP_SW_MINOR_VERSION_TYPES               0
#define ADC_SAR_IP_SW_PATCH_VERSION_TYPES               0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Adc_Sar_Ip_Types.h file and Adc_Sar_Ip_CfgDefines.h file are of the same vendor */
#if (ADC_SAR_IP_VENDOR_ID_TYPES != ADC_SAR_IP_VENDOR_ID_CFGDEFINES)
    #error "Adc_Sar_Ip_Types.h and Adc_Sar_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Adc_Sar_Ip_Types.h file and Adc_Sar_Ip_CfgDefines.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_TYPES != ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_TYPES != ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_TYPES != ADC_SAR_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_Types.h and Adc_Sar_Ip_CfgDefines.h are different"
#endif

/* Check if Adc_Sar_Ip_Types.h file and Adc_Sar_Ip_CfgDefines.h file are of the same Software version */
#if ((ADC_SAR_IP_SW_MAJOR_VERSION_TYPES != ADC_SAR_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_SW_MINOR_VERSION_TYPES != ADC_SAR_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (ADC_SAR_IP_SW_PATCH_VERSION_TYPES != ADC_SAR_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Adc_Sar_Ip_Types.h and Adc_Sar_Ip_CfgDefines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Adc_Sar_Ip_Types.h file and StandardTypes.h file are of the same Autosar version */
#if ((ADC_SAR_IP_AR_RELEASE_MAJOR_VERSION_TYPES != STD_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_SAR_IP_AR_RELEASE_MINOR_VERSION_TYPES != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Adc_Sar_Ip_Types.h and StandardTypes.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                              STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*!
 * @brief ADC_SAR status return type
 *
 * This enum is used as return type
 *
 * Implements : Adc_Sar_Ip_StatusType_Class
 */
typedef enum
{
    ADC_SAR_IP_STATUS_SUCCESS = 0x00U,  /*!< Function completed successfully */
    ADC_SAR_IP_STATUS_ERROR = 0x01U,    /*!< Function didn't complete successfully */
    ADC_SAR_IP_STATUS_TIMEOUT = 0x02U   /*!< Function timed out */
} Adc_Sar_Ip_StatusType;

/*!
 * @brief Conversion mode selection (One-shot or Scan)
 *
 * This enum is used to configure the conversion mode
 *
 * Implements : Adc_Sar_Ip_ConvModeType_Class
 */
typedef enum
{
    ADC_SAR_IP_CONV_MODE_ONESHOT = 0x00U,  /*!< One-shot conversion mode */
    ADC_SAR_IP_CONV_MODE_SCAN = 0x01U      /*!< Scan conversion mode */
} Adc_Sar_Ip_ConvModeType;

/*!
 * @brief Converter input clock
 *
 * This enum is used to configure the converter input clock
 *
 * Implements : Adc_Sar_Ip_ClockSelType_Class
 */
typedef enum
{
    ADC_SAR_IP_CLK_FULL_BUS = 0x00U,       /*!< Adc module clock   */
    ADC_SAR_IP_CLK_HALF_BUS = 0x01U,       /*!< Adc module clock/2 */
#if FEATURE_ADC_HAS_CLKSEL_EXTENDED
    ADC_SAR_IP_CLK_QUARTER_BUS = 0x02U,    /*!< Adc module clock/4 */
#endif /* FEATURE_ADC_HAS_CLKSEL_EXTENDED */
} Adc_Sar_Ip_ClockSelType;

#if FEATURE_ADC_HAS_CTU
/*!
 * @brief CTU Mode selection
 *
 * This enum is used to configure the mode in which CTU is used
 *
 * Implements : Adc_Sar_Ip_CtuModeType_Class
 */
typedef enum
{
    ADC_SAR_IP_CTU_MODE_DISABLED = 0x00U,  /*!< CTU Mode disabled */
    ADC_SAR_IP_CTU_MODE_CONTROL = 0x01U,    /*!< CTU is in Control Mode */
    ADC_SAR_IP_CTU_MODE_TRIGGER = 0x02U    /*!< CTU is in Trigger Mode */
} Adc_Sar_Ip_CtuModeType;
#endif /* FEATURE_ADC_HAS_CTU */

#if (ADC_SAR_IP_EXTERNAL_TRIGGER_ENABLE)
#if (FEATURE_ADC_HAS_INJ_EXT_TRIGGER || FEATURE_ADC_HAS_EXT_TRIGGER)
/*!
 * @brief External Trigger selection
 *
 * This enum is used to configure the external trigger
 *
 * Implements : Adc_Sar_Ip_ExtTriggerEdgeType_Class
 */
typedef enum
{
    ADC_SAR_IP_EXT_TRIG_EDGE_DISABLED = 0x00U, /*!< Injected trigger disabled */
    ADC_SAR_IP_EXT_TRIG_EDGE_FALLING = 0x01U,  /*!< Injected trigger on Falling Edge */
    ADC_SAR_IP_EXT_TRIG_EDGE_RISING = 0x02U,   /*!< Injected trigger on Rising Edge */
} Adc_Sar_Ip_ExtTriggerEdgeType;

/*!
 * @brief External Trigger Source Enable
 *
 * This enum is used to enable the external trigger source to start the conversion.
 *
 * Implements : Adc_Sar_Ip_ExtTriggerSourceType_Class
 */
typedef enum {
#if (FEATURE_ADC_HAS_EXT_TRIGGER)
    ADC_SAR_IP_NORMAL_EXT_TRIG     = 0x00U,       /*!< Enables normal trigger input */
#if (FEATURE_ADC_HAS_AUX_EXT_TRIGGER)
    ADC_SAR_IP_AUX_NORMAL_EXT_TRIG = 0x01U,       /*!< Enables auxiliary normal trigger input */
    ADC_SAR_IP_ALL_NORMAL_EXT_TRIG = 0x02U,       /*!< Enables normal and auxiliary trigger inputs */
#endif /* (FEATURE_ADC_HAS_AUX_EXT_TRIGGER) */
#endif /* (FEATURE_ADC_HAS_EXT_TRIGGER) */
#if (FEATURE_ADC_HAS_INJ_EXT_TRIGGER)
    ADC_SAR_IP_INJECTED_EXT_TRIG   = 0x03U,       /*!< Enables injection trigger input */
#endif /* (FEATURE_ADC_HAS_INJ_EXT_TRIGGER) */
} Adc_Sar_Ip_ExtTriggerSourceType;
#endif /* (FEATURE_ADC_HAS_INJ_EXT_TRIGGER || FEATURE_ADC_HAS_EXT_TRIGGER) */
#endif /* (ADC_SAR_IP_EXTERNAL_TRIGGER_ENABLE) */

/*!
 * @brief Conversion chain selection
 *
 * This enum is used to configure type of the conversion
 *
 * Implements : Adc_Sar_Ip_ConvChainType_Class
 */
typedef enum
{
    ADC_SAR_IP_CONV_CHAIN_NORMAL = 0x00U,      /*!< Selects the "Normal" Conversion Chain */
    ADC_SAR_IP_CONV_CHAIN_INJECTED = 0x01U,    /*!< Selects the "Injected" Conversion Chain */
    ADC_SAR_IP_CONV_CHAIN_CTU = 0x02U          /*!< Selects the "CTU" Conversion Chain */
} Adc_Sar_Ip_ConvChainType;

/*!
 * @brief Data alignment selection
 *
 * This enum is used to configure data alignment
 *
 * Implements : Adc_Sar_Ip_DataAlignedType_Class
 */
typedef enum
{
    ADC_SAR_IP_DATA_ALIGNED_RIGHT = 0x00U,     /*!< Measured data is right-aligned */
    ADC_SAR_IP_DATA_ALIGNED_LEFT = 0x01U       /*!< Measured data is left-aligned */
} Adc_Sar_Ip_DataAlignedType;

/*!
 * @brief Clear DMA source
 *
 * This enum is used to configure source used to clear a DMA request
 *
 * Implements : Adc_Sar_Ip_ClearSourceType_Class
 */
typedef enum {
    ADC_SAR_IP_DMA_REQ_CLEAR_ON_ACK = 0x00U,    /*!< Clear DMA Request on Ack from DMA Controller */
    ADC_SAR_IP_DMA_REQ_CLEAR_ON_READ = 0x01U,   /*!< Clear DMA Request on read of Data Registers */
} Adc_Sar_Ip_ClearSourceType;

#if FEATURE_ADC_HAS_PRESAMPLING
/*!
 * @brief Presampling Voltage selection
 *
 * This enum is used to configure the presampling voltage
 *
 * Implements : Adc_Sar_Ip_PresamplingSourceType_Class
 */
typedef enum {
#if (ADC_PSCR_PREVAL0_WIDTH > 1u)
    ADC_SAR_IP_PRESAMPLE_DVDD = ADC_SAR_IP_PRESAMPLE_DVDD_EVAL,   /*!< Presampling from DVDD */
    ADC_SAR_IP_PRESAMPLE_AVDD = ADC_SAR_IP_PRESAMPLE_AVDD_EVAL,    /*!< Presampling from AVDD */
#endif /* (ADC_PSCR_PREVAL0_WIDTH > 1u) */
    ADC_SAR_IP_PRESAMPLE_VREFL = ADC_SAR_IP_PRESAMPLE_VREFL_EVAL, /*!< Presampling from VREFL */
    ADC_SAR_IP_PRESAMPLE_VREFH = ADC_SAR_IP_PRESAMPLE_VREFH_EVAL  /*!< Presampling from VREFH */
} Adc_Sar_Ip_PresamplingSourceType;
#endif /* FEATURE_ADC_HAS_PRESAMPLING */

/*!
 * @brief Channel group selection
 *
 * This enum is used to select the group of ADC channels
 *
 * Implements : Adc_Sar_Ip_ChanGroupType_Class
 */
typedef enum {
    ADC_SAR_IP_CHAN_GROUP_0 = 0x00U,           /*!< Channels Group (0-31) */
    ADC_SAR_IP_CHAN_GROUP_1 = 0x01U,           /*!< Channels Group (32-63) */
#if (ADC_SAR_IP_NUM_GROUP_CHAN > 2u)
    ADC_SAR_IP_CHAN_GROUP_2 = 0x02U,           /*!< Channels Group (64-95) */
#endif /* (ADC_SAR_IP_NUM_GROUP_CHAN > 2u) */
} Adc_Sar_Ip_ChanGroupType;

#if FEATURE_ADC_HAS_AVERAGING
/*!
 * @brief Averaging selection
 *
 * This enum is used to select the number of conversions to average
 * in order to get the conversion data.
 *
 * Implements : Adc_Sar_Ip_AvgSelectType_Class
 */
typedef enum {
    ADC_SAR_IP_AVG_4_CONV = 0x00U,        /*!< 4 conversions per conversion data */
    ADC_SAR_IP_AVG_8_CONV = 0x01U,        /*!< 8 conversions per conversion data */
    ADC_SAR_IP_AVG_16_CONV = 0x02U,       /*!< 16 conversions per conversion data */
    ADC_SAR_IP_AVG_32_CONV = 0x03U,       /*!< 32 conversions per conversion data */
} Adc_Sar_Ip_AvgSelectType;
#endif /* FEATURE_ADC_HAS_AVERAGING */

#if (ADC_SAR_IP_SET_RESOLUTION == STD_ON)
/**
* @brief          Adc group conversion resolution.
* @details        Used for value received by Tressos interface configuration.
*
*/
typedef enum
{
    ADC_SAR_IP_RESOLUTION_14   = 0U, /**< @brief 14-bit per conversion data */
    ADC_SAR_IP_RESOLUTION_12   = 1U, /**< @brief 12-bit per conversion data */
    ADC_SAR_IP_RESOLUTION_10   = 2U, /**< @brief 10-bit per conversion data */
    ADC_SAR_IP_RESOLUTION_8    = 3U, /**< @brief 8-bit per conversion data */
} Adc_Sar_Ip_Resolution;
#endif /* (ADC_SAR_IP_SET_RESOLUTION == STD_ON) */

#if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
/*!
 * @brief Defines the channel notification header
 *
 * This header is used for individual channel notification callbacks
 *
 * Implements : Adc_Sar_Ip_ChanNotificationType_Class
 */
typedef void Adc_Sar_Ip_ChanNotificationType(const uint16 PhysicalChanId);
#endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */

#if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
/*!
 * @brief Defines the watchdog notification header
 *
 * This header is used for out of range watchdog notification callbacks
 * u8Flags will contain which WDG flag was triggered(low and/or high). These
 * are defined by ADC_SAR_IP_WDG_LOW_FLAG and ADC_SAR_IP_WDG_HIGH_FLAG
 *
 * Implements : Adc_Sar_Ip_WdgChanNotificationType_Class
 */
typedef void Adc_Sar_Ip_WdgNotificationType(const uint16 ChanIdx, const uint8 Flags);
#endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */

/*!
 * @brief Defines the channel configuration
 *
 * This structure is used to configure channels
 *
 * Implements : Adc_Sar_Ip_ChanConfigType_Class
 */
typedef struct
{
    uint8 ChanIndex;
    boolean PresamplingEnable;
#if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
    uint8 WdgThreshRegIndex;
    boolean WdgNotificationEn;
#endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
#if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
    boolean EndOfConvNotification;
#endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
    boolean EndOfConvDmaEnable;
} Adc_Sar_Ip_ChanConfigType;

/*!
 * @brief Defines the ADC clock configuration
 *
 * This structure is used to the ADC_SAR clock
 *
 * Implements : Adc_Sar_Ip_ClockConfigType_Class
 */
typedef struct
{
    Adc_Sar_Ip_ClockSelType ClkSelect;         /*!< Selected clock */
#if FEATURE_ADC_HAS_HIGH_SPEED_ENABLE
    boolean HighSpeedConvEn; /* Enables high speed conversion or calibration */
#endif /* FEATURE_ADC_HAS_HIGH_SPEED_ENABLE */
#if FEATURE_ADC_HAS_CONVERSION_TIMING
    uint8 SampleTimeArr[ADC_SAR_IP_NUM_GROUP_CHAN];  /*!< Sample time for each channel group */
#endif /* FEATURE_ADC_HAS_CONVERSION_TIMING */
    uint8 PowerDownDelay;                     /*!< Delay before entering Power Down */
#if FEATURE_ADC_HAS_CLOCK_DIVIDER
    boolean ClkDivEnable;               /*!< Clock divider enable */
#endif /* FEATURE_ADC_HAS_CLOCK_DIVIDER */
#if FEATURE_ADC_HAS_AVERAGING
    boolean AvgEn;
    Adc_Sar_Ip_AvgSelectType AvgSel;
#endif /* FEATURE_ADC_HAS_AVERAGING */
} Adc_Sar_Ip_ClockConfigType;

#if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
/*!
 * @brief Defines the upper and lower thresholds for analog watchdog.
 *
 * This structure is used to configure the analog watchdog threshold registers.
 *
 * Implements : Adc_Sar_Ip_WdgThresholdType_Class
 */
typedef struct
{
    uint8 WdgIndex;               /*!< Watchdog threshold register index */
    uint16 LowThreshold;         /*!< Lower threshold */
    uint16 HighThreshold;        /*!< Upper threshold */
    boolean LowThresholdIntEn;     /*!< Enable interrupt when lower threshold exceeded */
    boolean HighThresholdIntEn;    /*!< Enable interrupt when upper threshold exceeded */
} Adc_Sar_Ip_WdgThresholdType;
#endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */

/*!
 * @brief Defines the data regarding a conversion, beyond the conversion data.
 *
 * This structure is used to return information about conversions beyond just conversion data
 *
 * Implements : Adc_Sar_Ip_ChanResultType_Class
 */
typedef struct {
    uint8 AdcChnIdx;       /*!< ADC Channel Index */
    boolean ValidFlag;       /*!< Data Valid Flag */
    boolean OverWrittenFlag; /*!< Data Overwritten Flag */
    uint16 ConvData;   /*!< Conversion Data */
} Adc_Sar_Ip_ChanResultType;

/*!
 * @brief Defines configuration of channels in a chain
 *
 * This structure is used to configure channels in chain.
 *
 * Implements : Adc_Sar_Ip_ChansIdxMaskType_Class
 */
typedef struct
{
    uint32 ChanMaskArr[ADC_SAR_IP_NUM_GROUP_CHAN];  /*!< Bit-mask used to configure channels in chain */
} Adc_Sar_Ip_ChansIdxMaskType;

#if (STD_ON == ADC_SAR_IP_SELFTEST_ENABLED)
/*!
 * @brief Defines configuration of self-test threshold values
 *
 * This structure is used to configure self-test threshold values.
 *
 * Implements : Adc_Sar_Ip_SelfTestThresholdType_Class
 */
typedef struct
{
#ifdef ADC_STAW0R_AWDE
    uint16 AdcSTAW0RHighVal;  /*!< Adc STAW0R threshold high value */
    uint16 AdcSTAW0RLowVal;   /*!< Adc STAW0R threshold low value */
#endif /* ADC_STAW0R_AWDE */
#ifdef ADC_STAW1R_AWDE
    uint16 AdcSTAW1RLowVal;   /*!< Adc STAW1R threshold low value */
#endif /* ADC_STAW1AR_AWDE */
#ifdef ADC_STAW1AR_AWDE
    uint16 AdcSTAW1ARHighVal; /*!< Adc STAW1AR threshold high value */
    uint16 AdcSTAW1ARLowVal;  /*!< Adc STAW1AR threshold low value */
    uint16 AdcSTAW1BRHighVal; /*!< Adc STAW1BR threshold high value */
    uint16 AdcSTAW1BRLowVal;  /*!< Adc STAW1BR threshold low value */
#endif /* ADC_STAW1AR_AWDE */
#ifdef ADC_STAW2R_AWDE
    uint16 AdcSTAW2RLowVal;   /*!< Adc STAW2R threshold low value */
#endif /* ADC_STAW2R_AWDE */
#ifdef ADC_STAW4R_AWDE
    uint16 AdcSTAW4RHighVal;  /*!< Adc STAW4R threshold high value */
    sint16 AdcSTAW4RLowVal;   /*!< Adc STAW4R threshold low value */
    uint16 AdcSTAW5RHighVal;  /*!< Adc STAW5R threshold high value */
    sint16 AdcSTAW5RLowVal;   /*!< Adc STAW5R threshold low value */
#endif /* ADC_STAW4R_AWDE */
} Adc_Sar_Ip_SelfTestThresholdType;
#endif /* (STD_ON == ADC_SAR_IP_SELFTEST_ENABLED) */

/*!
 * @brief Defines the module configuration
 *
 * This structure is used to configure the ADC_SAR module
 *
 * Implements : Adc_Sar_Ip_ConfigType_Class
 */
typedef struct
{
    Adc_Sar_Ip_ConvModeType ConvMode;  /*!< Conversion Mode (One-shot or Scan) */
#if (ADC_SAR_IP_SET_RESOLUTION == STD_ON)
    Adc_Sar_Ip_Resolution AdcResolution; /*!< Adc resolution */
    boolean BypassResolution;            /*!< Bypass Adc resolution processing for the result */
#endif /* (ADC_SAR_IP_SET_RESOLUTION == STD_ON) */
    Adc_Sar_Ip_ClockSelType ClkSelect; /*!< Clock input */
    Adc_Sar_Ip_ClockSelType CalibrationClkSelect; /*!< Clock input for calibration */
#if FEATURE_ADC_HAS_HIGH_SPEED_ENABLE
    boolean HighSpeedConvEn; /* Enables high speed conversion or calibration */
#endif /* FEATURE_ADC_HAS_HIGH_SPEED_ENABLE */
#if FEATURE_ADC_HAS_CTU
    Adc_Sar_Ip_CtuModeType CtuMode;     /*!< CTU mode */
#endif /* FEATURE_ADC_HAS_CTU */
#if (ADC_SAR_IP_EXTERNAL_TRIGGER_ENABLE)
#if FEATURE_ADC_HAS_INJ_EXT_TRIGGER
    Adc_Sar_Ip_ExtTriggerEdgeType InjectedEdge;   /*!< Injected Trigger selection */
#endif /* FEATURE_ADC_HAS_INJ_EXT_TRIGGER */
#if FEATURE_ADC_HAS_EXT_TRIGGER
    Adc_Sar_Ip_ExtTriggerEdgeType ExtTrigger;     /*!< External Trigger selection */
    boolean NormalExtTrgEn;                       /*!< Enables normal trigger source */
#if FEATURE_ADC_HAS_AUX_EXT_TRIGGER
    boolean NormalAuxExtTrgEn;                    /*!< Enables auxiliary normal trigger source */
#endif /* FEATURE_ADC_HAS_AUX_EXT_TRIGGER */
#endif /* FEATURE_ADC_HAS_EXT_TRIGGER */
#endif /* (ADC_SAR_IP_EXTERNAL_TRIGGER_ENABLE) */
#if FEATURE_ADC_HAS_CONVERSION_TIMING
    uint8 SampleTimeArr[ADC_SAR_IP_NUM_GROUP_CHAN]; /*!< Sample time for each channel group */
#endif /* FEATURE_ADC_HAS_CONVERSION_TIMING */
#if FEATURE_ADC_HAS_PRESAMPLING
    boolean BypassSampling;  /* PSCR[PRECONV] */
    Adc_Sar_Ip_PresamplingSourceType PresamplingSourceArr[ADC_SAR_IP_NUM_GROUP_CHAN]; /*!< Presampling sources for each channel group */
#endif /* FEATURE_ADC_HAS_PRESAMPLING */
    boolean AutoClockOff; /*!< Enable Auto Clock Off */
    boolean OverwriteEnable; /*!< Overwrite new conversion data over old data */
    Adc_Sar_Ip_DataAlignedType DataAlign; /*!< Data alignment in conversion result register */
#if FEATURE_ADC_SAR_DECODE_DELAY
    uint16 DecodeDelay; /*!< Delay for decoding Input MUX channels */
#endif /* FEATURE_ADC_SAR_DECODE_DELAY */
    uint8 PowerDownDelay; /*!< Delay before entering Power Down */
#if FEATURE_ADC_HAS_CLOCK_DIVIDER
    boolean ClkDivEnable;               /*!< Clock divider enable */
#endif /* FEATURE_ADC_HAS_CLOCK_DIVIDER */
#if (STD_ON == ADC_SAR_IP_SELFTEST_ENABLED)
    const Adc_Sar_Ip_SelfTestThresholdType * SelfTestThresholdConfig; /*!< Self test threshold configuration */
#endif /* (STD_ON == ADC_SAR_IP_SELFTEST_ENABLED) */
#if FEATURE_ADC_HAS_AVERAGING
    boolean AvgEn;
    Adc_Sar_Ip_AvgSelectType AvgSel;
#endif /* FEATURE_ADC_HAS_AVERAGING */
    uint8 UsrOffset;
    uint16 UsrGain;
    boolean DmaEnable;                         /* Enables DMA */
    Adc_Sar_Ip_ClearSourceType DmaClearSource; /* Select event to clear DMA request */

    uint32 ChanMaskNormal[ADC_SAR_IP_NUM_GROUP_CHAN];     /*!< Bit-mask used to configure Normal Chain */
    uint32 ChanMaskInjected[ADC_SAR_IP_NUM_GROUP_CHAN];   /*!< Bit-mask used to configure Injected Chain */

    uint8 NumChannels;
    const Adc_Sar_Ip_ChanConfigType * ChannelConfigsPtr;

#if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
    uint8 NumWdgThresholds;
    const Adc_Sar_Ip_WdgThresholdType * WdgThresholds;
#endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */

#if (STD_ON == ADC_SAR_IP_ECH_ENABLED)
    void (*EndOfNormalChainNotification)(void);
#endif /* (STD_ON == ADC_SAR_IP_ECH_ENABLED) */
#if (STD_ON == ADC_SAR_IP_JECH_ENABLED)
    void (*EndOfInjectedChainNotification)(void);
#endif /* (STD_ON == ADC_SAR_IP_JECH_ENABLED) */
#if FEATURE_ADC_HAS_CTU
#if (STD_ON == ADC_SAR_IP_EOCTU_ENABLED)
    void (*EndOfCtuConversionNotification)(void);
#endif /* (STD_ON == ADC_SAR_IP_EOCTU_ENABLED) */
#endif /* FEATURE_ADC_HAS_CTU */

    /* Individual channel notifications */
#if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
    Adc_Sar_Ip_ChanNotificationType * EndOfConvNotification;
#endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
#if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
    Adc_Sar_Ip_WdgNotificationType * WdgOutOfRangeNotification;
#endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
} Adc_Sar_Ip_ConfigType;

/*!
 * @brief Structure used to store runtime info
 *
 * This structure is used to store ADC SAR runtime info
 *
 * Implements : Adc_Sar_Ip_StateStructType_Class
 */
typedef struct
{
    boolean InitStatus;                                   /*!< Check if the driver was initialized. */
    Adc_Sar_Ip_DataAlignedType DataAlign;           /*!< Data alignment in conversion result register */
    Adc_Sar_Ip_ClockSelType CalibrationClkSelect;   /*!< Clock input for calibration */
#if (ADC_SAR_IP_SET_RESOLUTION == STD_ON)
    boolean BypassResolution;                       /*!< Adc raw data result */
#endif /* (ADC_SAR_IP_SET_RESOLUTION == STD_ON) */
#if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
    uint32 ChanWdgThresholdIndex[ADC_SAR_IP_CDR_COUNT]; /*!< Channel index to threshold index mapping */
#endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */

    /* General notifications */
#if (STD_ON == ADC_SAR_IP_ECH_ENABLED)
    void (*EndOfNormalChainNotification)(void);
#endif /* (STD_ON == ADC_SAR_IP_ECH_ENABLED) */
#if (STD_ON == ADC_SAR_IP_JECH_ENABLED)
    void (*EndOfInjectedChainNotification)(void);
#endif /* (STD_ON == ADC_SAR_IP_JECH_ENABLED) */
#if FEATURE_ADC_HAS_CTU
#if (STD_ON == ADC_SAR_IP_EOCTU_ENABLED)
    void (*EndOfCtuConversionNotification)(void);
#endif /* (STD_ON == ADC_SAR_IP_EOCTU_ENABLED) */
#endif /* FEATURE_ADC_HAS_CTU */

    /* Individual channel notifications */
#if (STD_ON == ADC_SAR_IP_EOC_ENABLED)
    Adc_Sar_Ip_ChanNotificationType * EndOfConvNotification;
#endif /* (STD_ON == ADC_SAR_IP_EOC_ENABLED) */
#if (STD_ON == ADC_SAR_IP_WDG_ENABLED)
    Adc_Sar_Ip_WdgNotificationType * WdgOutOfRangeNotification;
#endif /* (STD_ON == ADC_SAR_IP_WDG_ENABLED) */
} Adc_Sar_Ip_StateStructType;

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_SAR_IP_TYPES_H */
