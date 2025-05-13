/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_ICU_IP_TYPES_H
#define EMIOS_ICU_IP_TYPES_H

/**
 *   @file       Emios_Icu_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c
 *   @version    2.0.1
 *
 *   @brief      AUTOSAR Icu - contains the data exported by the Icu module
 *   @details    Contains the information that will be exported by the module, as requested by AUTOSAR.
 *
 *   @addtogroup emios_icu_ip EMIOS IPL
 *   @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Emios_Icu_Ip_Defines.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_ICU_IP_TYPES_VENDOR_ID                     43
#define EMIOS_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION      4
#define EMIOS_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION      7
#define EMIOS_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION   0
#define EMIOS_ICU_IP_TYPES_SW_MAJOR_VERSION              2
#define EMIOS_ICU_IP_TYPES_SW_MINOR_VERSION              0
#define EMIOS_ICU_IP_TYPES_SW_PATCH_VERSION              1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#if (EMIOS_ICU_IP_TYPES_VENDOR_ID != EMIOS_ICU_IP_DEFINES_VENDOR_ID)
    #error "Emios_Icu_Ip_Types.h and Emios_Icu_Ip_Defines.h have different vendor ids"
#endif

/* Check if  header file and Emios_Icu_Ip_Defines.h file are of the same Autosar version */
#if ((EMIOS_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION != EMIOS_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION != EMIOS_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION != EMIOS_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Icu_Ip_Types.h and Emios_Icu_Ip_Defines.h are different"
#endif

/* Check if header file and Emios_Icu_Ip_Defines.h file are of the same Software version */
#if ((EMIOS_ICU_IP_TYPES_SW_MAJOR_VERSION != EMIOS_ICU_IP_DEFINES_SW_MAJOR_VERSION) || \
     (EMIOS_ICU_IP_TYPES_SW_MINOR_VERSION != EMIOS_ICU_IP_DEFINES_SW_MINOR_VERSION) || \
     (EMIOS_ICU_IP_TYPES_SW_PATCH_VERSION != EMIOS_ICU_IP_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Icu_Ip_Types.h and Emios_Icu_Ip_Defines.h are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#if (STD_ON == EMIOS_ICU_IP_USED)
/**
* @brief EMIOS Channels defines
*/
#define EMIOS_ICU_IP_CB_NONE       ((uint8)0xFF)
#define EMIOS_ICU_IP_CB_DIVERSE    ((uint8)0x07)
#define EMIOS_ICU_IP_CHANNEL_0     ((uint8)0x00)
#define EMIOS_ICU_IP_CHANNEL_7     ((uint8)0x07)
#define EMIOS_ICU_IP_CHANNEL_8     ((uint8)0x08)
#define EMIOS_ICU_IP_CHANNEL_15    ((uint8)0x0F)
#define EMIOS_ICU_IP_CHANNEL_16    ((uint8)0x10)
#define EMIOS_ICU_IP_CHANNEL_23    ((uint8)0x17)
#define EMIOS_ICU_IP_CHANNEL_24    ((uint8)0x18)

#define EMIOS_ICU_IP_MCB_INT_CLOCK_U32         ((uint32)(0x50U))
#if (EMIOS_ICU_IP_EDGE_COUNT_API == STD_ON)
#define EMIOS_ICU_IP_MCB_EXT_CLOCK_U32         ((uint32)(0x51U))
#endif

#define EMIOS_ICU_IP_CCR_CLEAR_U32             ((uint32)(0x0U))
#define EMIOS_ICU_IP_CSR_CLEAR_U32             ((uint32)(0xFFFFFFFFU))

#if ((EMIOS_ICU_IP_EDGE_COUNT_API == STD_ON) || (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON) || (EMIOS_ICU_IP_TIMESTAMP_API == STD_ON))
#define EMIOS_ICU_IP_INIT_CCNTR_U32            (0x00000000U)
#define EMIOS_ICU_IP_INIT_CADR_U32             ((uint32)EMIOS_ICU_IP_COUNTER_MASK)
#endif

#define EMIOS_ICU_IP_CCR_MODE_GPI_U32          ((uint32)(0x00))

#if (EMIOS_ICU_IP_SAIC_EDGE_CAPTURING_SUPPORT == STD_ON)
    #define EMIOS_ICU_IP_CCR_MODE_SAIC_EDGE_CAPTURING_U32         ((uint32)(0x42))
#else
    #define EMIOS_ICU_IP_CCR_MODE_SAIC_U32         ((uint32)(0x02))
#endif

#if (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)
#define EMIOS_ICU_IP_CCR_MODE_IPWM_U32         ((uint32)(0x04))
#define EMIOS_ICU_IP_CCR_MODE_IPM_U32          ((uint32)(0x05))
#endif

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/**
* @brief    eMIOS_Activation EDGE
* @details  Indicates the channel activation type(Rising, Falling, Both Edges or Opposite Edges).
*/
typedef enum
{
    /** @brief No trigger. */
    EMIOS_ICU_NO_PIN_CONTROL    = 0x0U,
    /** @brief Rising edge trigger. */
    EMIOS_ICU_RISING_EDGE       = 0x1U,
    /** @brief Rising edge trigger. */
    EMIOS_ICU_FALLING_EDGE      = 0x2U,
    /** @brief Rising and falling edge trigger */
    EMIOS_ICU_BOTH_EDGES        = 0x3U
#if (STD_ON == EMIOS_ICU_IP_SIGNAL_MEASUREMENT_USES_SAIC_MODE)
    /** @brief EMIOS_OPPOSITE_EDGES = An appropriate action shall be executed when either a falling or rising edge occur on the ICU input signal. */
    ,EMIOS_OPPOSITE_EDGES       = 0x4U
#endif   /* STD_ON == EMIOS_ICU_IP_SIGNAL_MEASUREMENT_USES_SAIC_MODE */
} eMios_Icu_Ip_EdgeType;

/** @brief Operation mode for ICU driver. */
typedef enum
{
    /** @brief No measurement mode. */
    EMIOS_ICU_MODE_NO_MEASUREMENT                   = 0x0U,
    /** @brief Signal edge detect measurement mode. */
    EMIOS_ICU_MODE_SIGNAL_EDGE_DETECT               = 0x1U,
    /** @brief Signal measurement mode.*/
    EMIOS_ICU_MODE_SIGNAL_MEASUREMENT               = 0x2U,
    /** @brief Timestamp measurement mode.*/
    EMIOS_ICU_MODE_TIMESTAMP                        = 0x4U,
    /** @brief Edge counter measurement mode.*/
    EMIOS_ICU_MODE_EDGE_COUNTER                     = 0x8U
} eMios_Icu_Ip_ModeType;

/** @brief Enable/disable DMA support for timestamp. */
typedef enum
{
    /* Disable DMA support. */
    EMIOS_ICU_MODE_WITHOUT_DMA = 0U,
    /* Enable DMA support. */
    EMIOS_ICU_MODE_WITH_DMA    = 1U
} eMios_Icu_Ip_SubModeType;

/** @brief Stores the state in which a signal measurement is. */
typedef enum
{
    /* This is the initial state of measurement */
    EMIOS_ICU_MEASUREMENT_PENDING       = 0U,
    /* First edge has triggered - measuring duty cycle */
    EMIOS_ICU_MEASUREMENT_DUTY          = 1U,
    /* Second edge has triggered - measuring period */
    EMIOS_ICU_MEASUREMENT_PERIOD        = 2U
} eMios_Icu_Ip_MeasStatusType;

/** @brief Type of operation for signal measurement. */
typedef enum
{
    /** @brief No measurement. */
    EMIOS_ICU_NO_MEASUREMENT = 0U,
    /** @brief The time measurement for OFF period. */
    EMIOS_ICU_LOW_TIME       = 1U,
    /** @brief The time measurement for ON period. */
    EMIOS_ICU_HIGH_TIME      = 2U,
    /** @brief Period measurement between two consecutive falling/raising edges. */
    EMIOS_ICU_PERIOD_TIME    = 4U,
    /** @brief The fraction of active period. */
    EMIOS_ICU_DUTY_CYCLE     = 8U
} eMios_Icu_Ip_MeasType;

#if (EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)
/** @brief Type of operation for timestamp. */
typedef enum
{
    /** @brief No timestamp. */
    EMIOS_ICU_NO_TIMESTAMP      = 0U,
    /** @brief The timestamp with circular buffer . */
    EMIOS_ICU_CIRCULAR_BUFFER   = 1U,
    /** @brief The timestamp with linear buffer . */
    EMIOS_ICU_LINEAR_BUFFER     = 2U
} eMios_Icu_Ip_TimestampBufferType;
#endif

#if (STD_ON == EMIOS_ICU_IP_GET_INPUT_LEVEL_API)
/** @brief Enumeration used for returning the level of input pin. */
typedef enum
{
    /** @brief Low level state.  */
    EMIOS_ICU_LEVEL_LOW   = 0x0U,
    /** @brief High level state. */
    EMIOS_ICU_LEVEL_HIGH  = 0x1U
} eMios_Icu_Ip_LevelType;
#endif
#if (EMIOS_ICU_IP_DUAL_CLOCK_MODE_API == STD_ON)
/** @brief Definition of prescaler type (Normal or Alternate) */
typedef enum
{
    EMIOS_ICU_NORMAL_CLK        = 0x0U,  /**< @brief Normal prescaler         */
    EMIOS_ICU_ALTERNATE_CLK     = 0x1U   /**< @brief Alternate prescaler      */
} eMios_Icu_Ip_ClockModeType;
#endif

/** @brief Definition of master bus type */
typedef enum
{
    EMIOS_ICU_BUS_A                 = 0x0U, /**< @brief Bus A            */
    EMIOS_ICU_BUS_DIVERSE           = 0x1U, /**< @brief Bus diverse      */
    EMIOS_ICU_BUS_INTERNAL_COUNTER  = 0x3U  /**< @brief Internal counter */
} eMios_Icu_Ip_BusType;

/** @brief Generic error codes. */
typedef enum
{
    /** @brief Generic operation success status. */
    EMIOS_IP_STATUS_SUCCESS                  = 0x00U,
    /** @brief Generic operation failure status. */
    EMIOS_IP_STATUS_ERROR                    = 0x01U
} eMios_Icu_Ip_StatusType;

/** @brief Selection of the signal measurement mode when IcuSignalMeasurementProperty is ICU_DUTY_CYCLE. */
typedef enum
{
    /** @brief un-initialized. */
    EMIOS_ICU_UNINIT                = 0x00U,
    /** @brief SAIC mode. */
    EMIOS_ICU_SAIC                  = 0x01U,
    /** @brief IPWM mode. */
    EMIOS_ICU_IPM                   = 0x02U,
    /** @brief IPWM mode. */
    EMIOS_ICU_IPWM                  = 0x03U
} eMios_Icu_Ip_UCModeType;


/** @brief Selects the clock divider value for the UC internal prescaler. */
typedef enum
{
    /** @brief EMIOS_PRESCALER_DIVIDE_1. */
    EMIOS_PRESCALER_DIVIDE_1                    = 0x00U,
    /** @brief EMIOS_PRESCALER_DIVIDE_2. */
    EMIOS_PRESCALER_DIVIDE_2                    = 0x01U,
    /** @brief EMIOS_PRESCALER_DIVIDE_3. */
    EMIOS_PRESCALER_DIVIDE_3                    = 0x02U,
    /** @brief EMIOS_PRESCALER_DIVIDE_4. */
    EMIOS_PRESCALER_DIVIDE_4                    = 0x03U,
    /** @brief EMIOS_PRESCALER_DIVIDE_5. */
    EMIOS_PRESCALER_DIVIDE_5                    = 0x04U,
    /** @brief EMIOS_PRESCALER_DIVIDE_6. */
    EMIOS_PRESCALER_DIVIDE_6                    = 0x05U,
    /** @brief EMIOS_PRESCALER_DIVIDE_7. */
    EMIOS_PRESCALER_DIVIDE_7                    = 0x06U,
    /** @brief EMIOS_PRESCALER_DIVIDE_8. */
    EMIOS_PRESCALER_DIVIDE_8                    = 0x07U,
    /** @brief EMIOS_PRESCALER_DIVIDE_9. */
    EMIOS_PRESCALER_DIVIDE_9                    = 0x08U,
    /** @brief EMIOS_PRESCALER_DIVIDE_10. */
    EMIOS_PRESCALER_DIVIDE_10                   = 0x09U,
    /** @brief EMIOS_PRESCALER_DIVIDE_11. */
    EMIOS_PRESCALER_DIVIDE_11                   = 0x0AU,
    /** @brief EMIOS_PRESCALER_DIVIDE_12. */
    EMIOS_PRESCALER_DIVIDE_12                   = 0x0BU,
    /** @brief EMIOS_PRESCALER_DIVIDE_13. */
    EMIOS_PRESCALER_DIVIDE_13                   = 0x0CU,
    /** @brief EMIOS_PRESCALER_DIVIDE_14. */
    EMIOS_PRESCALER_DIVIDE_14                   = 0x0DU,
    /** @brief EMIOS_PRESCALER_DIVIDE_15. */
    EMIOS_PRESCALER_DIVIDE_15                   = 0x0EU,
    /** @brief EMIOS_PRESCALER_DIVIDE_16. */
    EMIOS_PRESCALER_DIVIDE_16                   = 0x0FU
} eMios_Icu_Ip_PrescalerType;

/** @brief Selects the the input filter. */
typedef enum
{
    /** @brief EMIOS_DIGITAL_FILTER_BYPASSED. */
    EMIOS_DIGITAL_FILTER_BYPASSED              = 0x00U,
    /** @brief EMIOS_DIGITAL_FILTER_02. */
    EMIOS_DIGITAL_FILTER_02                    = 0x01U,
    /** @brief EMIOS_DIGITAL_FILTER_04. */
    EMIOS_DIGITAL_FILTER_04                    = 0x02U,
    /** @brief EMIOS_DIGITAL_FILTER_08. */
    EMIOS_DIGITAL_FILTER_08                    = 0x04U,
    /** @brief EMIOS_DIGITAL_FILTER_16. */
    EMIOS_DIGITAL_FILTER_16                    = 0x08U
} eMios_Icu_Ip_FilterType;

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** @brief The notification functions shall have no parameters and no return value.*/
typedef void (*eMios_Icu_Ip_NotifyType)(void);

/**
* @brief Structure that contains ICU Duty cycle parameters. It contains the values needed for
*        calculating duty cycles i.e Period time value and active time value.
* @implements eMios_Icu_Ip_DutyCycleType_struct
*/
typedef struct
{
    eMios_Icu_ValueType   ActiveTime;         /**< @brief Low or High time value. */
    eMios_Icu_ValueType   PeriodTime;         /**< @brief Period time value. */
} eMios_Icu_Ip_DutyCycleType;

#if (defined EMIOS_ICU_IP_WSC_SUPPORT)
#if (EMIOS_ICU_IP_WSC_SUPPORT == STD_ON)
/**
* @brief Structure that contains eMios Wheel Speet Fifo data parameters. It contains
*        the FIFO data value, Number of data entries currently contained in the FIFO,
*        Pointer write and Pointer read.
* @implements eMios_Icu_Ip_WscFifoType_struct
*/
typedef struct
{
    uint32 FifoData;                  /**< FIFO data value */
    uint8  FifoCounter;               /**< Number of data entries currently contained in the FIFO  */
    uint8  pWrite;                    /**< Pointer write */
    uint8  pRead;                     /**< Pointer read */
} eMios_Icu_Ip_WscFifoType;
#endif /* EMIOS_ICU_IP_WSC_SUPPORT */
#endif /* defined EMIOS_ICU_IP_WSC_SUPPORT */

/** @brief HLD Callback type for each channel reporting events or events and overflow . */
typedef void (*eMios_Icu_Ip_CallbackType)(uint16 callbackParam1, boolean callbackParam2);

/** @brief Callback type for each channel. */
typedef void (*eMios_Icu_Ip_LogicChStateCbType)(uint16 logicChannel, uint8 mask, boolean set);

typedef struct
{
    uint8                               hwChannel;                  /*!< Channel Id */
    eMios_Icu_Ip_UCModeType             ucMode;                     /*!< eMios UC mode of operation  */
    boolean                             FreezeEn;                   /*!< Freeze enable for UC */
    eMios_Icu_Ip_PrescalerType          Prescaler;                  /*!< Channel Prescaler */
    eMios_Icu_Ip_PrescalerType          AltPrescaler;               /*!< Channel Alternate Prescaler */
    eMios_Icu_Ip_BusType                CntBus;                     /*!< Channel Counter bus selection */
    eMios_Icu_Ip_ModeType               chMode;                     /*!< eMios module ICU mode of operation  */
    eMios_Icu_Ip_SubModeType            chSubMode;                  /*!< eMios ICU mode with or without DMA  */
    eMios_Icu_Ip_MeasType               measurementMode;            /*!< subMode selection for Signal Measurement*/
    eMios_Icu_Ip_EdgeType               edgeAlignement;             /*!< Edge alignment for measurement */
    eMios_Icu_Ip_FilterType             Filter;                     /*!< Channel Digital Input Filter */
    boolean                             filterClock;                /*!< Selects the clock source for the programmable input filter */
    eMios_Icu_Ip_CallbackType           callback;                   /*!< The HLD callback function for channels events */
    eMios_Icu_Ip_LogicChStateCbType     logicChStateCallback;       /*!< The HLD callback function for changing logic channels status */
    uint8                               callbackParams;             /*!< The HLD logical channel serviced */
    boolean                             bWithoutInterrupt;          /*!< Measurement of ICU signal property without using interrupt */
#if (EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)
    eMios_Icu_Ip_TimestampBufferType    timestampBufferType;        /*!< Timestamp buffer type for timestamp mode*/
#endif
#if ((STD_ON == EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL) || (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL))
    /** @brief Dma Channel Id. */
    uint8                               dmaChannel;
#endif /* ((STD_ON == EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL) || (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL)) */
    eMios_Icu_Ip_NotifyType             eMiosChannelNotification;   /*!< The notification and overflow have no parameters and no return value and are generated */
    eMios_Icu_Ip_NotifyType             eMiosOverflowNotification;  /*!< based on channel run environment - HLD or IPL - statically,precompile configured*/
} eMios_Icu_Ip_ChannelConfigType;

#ifdef EMIOS_ICU_IP_WSC_SUPPORT
#if (EMIOS_ICU_IP_WSC_SUPPORT == STD_ON)
/** @brief Selects the the input filter for WSC */
typedef enum
{
    /** @brief bypass the filter. */
    EMIOS_INPUT_FILTER_BYPASSED              = 0x00U,
    /** @brief 2 clock cycles */
    EMIOS_INPUT_FILTER_02                    = 0x01U,
    /** @brief 4 clock cycles */
    EMIOS_INPUT_FILTER_04                    = 0x02U,
    /** @brief 8 clock cycles */
    EMIOS_INPUT_FILTER_08                    = 0x04U,
    /** @brief 16 clock cycles */
    EMIOS_INPUT_FILTER_16                    = 0x08U,
    /** @brief 32 clock cycles */
    EMIOS_INPUT_FILTER_32                    = 0x10U,
    /** @brief 64 clock cycles */
    EMIOS_INPUT_FILTER_64                    = 0x20U,
    /** @brief 128 clock cycles. */
    EMIOS_INPUT_FILTER_128                   = 0x40U,
    /** @brief 256 clock cycles */
    EMIOS_INPUT_FILTER_256                   = 0x80U
} eMios_Icu_Ip_WscFilterType;

/** @brief Selects the the type of interrupt for WSC */
typedef enum
{

    EMIOS_FLAG_NONE              = 0x00U,   /*!< No interrupt source */
    EMIOS_FLAGCE_OVRCE_DETECT    = 0x01U,   /*!< Compare event overflow or overrun */
    EMIOS_FLAGECO_OVRECO_DETECT  = 0x02U,   /*!< Event counter overflow or overrun */
    EMIOS_FLAGPW_OVRPW_DETECT    = 0x04U,   /*!< Pulse width capture event overflow or overrun */
    EMIOS_FLAGCAP_OVRCAP_DETECT  = 0x08U,   /*!< Capture event overflow or overrun */
    EMIOS_FLAGPWO_OVRPWO_DETECT  = 0x10U,   /*!< T16PWCNT Pulse width counter overflow or overrun */
    EMIOS_FLAGFF_OVERRUN_DETECT  = 0x20U    /*!< FIFO status full or not */
} eMios_Icu_Ip_WscIsrSourceType;

/*
 * @brief Edges trigger the capture  : rising edge, falling edge, both of them or none edge
 */
typedef enum
{
    EMIOS_ICU_IP_FALLING_EDGE     = 0x00U,    /*!< Falling edge */
    EMIOS_ICU_IP_RISING_EDGE      = 0x01U,    /*!< Rising edge */
    EMIOS_ICU_IP_BOTH_EDGES       = 0x02U,    /*!< Rising and falling edge */
    EMIOS_ICU_IP_NO_TRIGGER       = 0x03U     /*!< No edge */
} eMios_Icu_Ip_WscTriggerModeType;

/*
* @brief EMIOS Wheel Speed channel modes operation
*/
typedef enum
{
    EMIOS_WHEEL_SPEED_MODE          = 0x70U,    /*!< Wheel Speed mode */
    EMIOS_SENT_MODE                 = 0x78U     /*!< SENT mode        */
} eMios_Icu_Ip_WsChannelModeType;

/*
 * @brief WSC configuration parameters structure
 */
typedef struct
{
    uint8                               HwWsChannel;        /*!< Wheel Speed Channel Id */
    eMios_Icu_Ip_WsChannelModeType      WsChannelMode;      /*!< Wheel Speed Channel mode of operation */
    boolean                             FreezeEn;           /*!< Freeze enable for Wheel Speed Channel */
    boolean                             FiFoOverwrite;      /*!< Overwrite data in FIFO */
    boolean                             FilterClockScr;     /*!< Selects the clock source for the PIF */
    eMios_Icu_Ip_WscFilterType          WscInputFilter;     /*!< Input Filter for Wheel Speed Channel */
    eMios_Icu_Ip_BusType                WscBusSelect;       /*!< The counter bus used by the WSC. */
    eMios_Icu_Ip_WscTriggerModeType     CapEdgeDetect;      /*!< Capture edge detection selection */
    eMios_Icu_Ip_NotifyType             WsCAPNotification;  /*!< The notification function for Capture Event in WSC */
    uint8                               WscNumEvent;        /*!< The number of WSC events */
    eMios_Icu_Ip_NotifyType             WsCENotification;   /*!< The notification function for Compare Event in WSC */
    eMios_Icu_Ip_NotifyType             WsCEONotification;  /*!< The notification function for Event Counter Overflow in WSC */
    eMios_Icu_Ip_WscTriggerModeType     PwEdgeDetect;       /*!< Edges trigger the capture of the pulse width counter*/
    boolean                             IntPrescalerMode;   /*!< Selects the width and application of the WSC internal prescaler. */
    uint16                              IntPrescaler;       /*!< Selects the clock divider for the WSC internal prescaler. */
    boolean                             ResetCnt;           /*!< Reset of the pulse width counter on a event */
    eMios_Icu_Ip_NotifyType             WsPWONotification;  /*!< The notification function for Pulse Width Overrun in WSC */
    eMios_Icu_Ip_NotifyType             WsPWNotification;   /*!< The notification function for Pulse Width Capture Event in WSC */
} eMios_Icu_Ip_WsChannelConfigType;

/** @brief This structure is used by the IPL driver for internal logic. */
typedef struct
{
    /** @brief The notification function for Capture Event in WSC. */
    eMios_Icu_Ip_NotifyType             WsCAPNotification;
    /** @brief The notification function for Compare Event in WSC. */
    eMios_Icu_Ip_NotifyType             WsCENotification;
    /** @brief The notification function for Event Counter Overflow in WSC. */
    eMios_Icu_Ip_NotifyType             WsCEONotification;
    /** @brief The notification function for Pulse Width Overrun in WSC. */
    eMios_Icu_Ip_NotifyType             WsPWONotification;
    /** @brief The notification function for Pulse Width Capture Event in WSC. */
    eMios_Icu_Ip_NotifyType             WsPWNotification;
    /** @brief Set enable interrupt status. */
    uint8                               EnableInterruptStatus;
} eMios_Icu_Ip_WsChStateType;
#endif
#endif /* EMIOS_ICU_IP_WSC_SUPPORT */

/**
* @brief      eTimer IP specific configuration structure type
*/
typedef struct
{
#ifdef EMIOS_ICU_IP_WSC_SUPPORT
#if (EMIOS_ICU_IP_WSC_SUPPORT == STD_ON)
    /** @brief Number of eMios Wheel speed channels in the Icu configuration */
    uint8                                  nNumWsChannels;
    /** @brief Pointer to the configured channels for eMios wheel speed channel */
    const eMios_Icu_Ip_WsChannelConfigType (*pWSChannelsConfig)[];
#endif
#endif /* EMIOS_ICU_IP_WSC_SUPPORT */
    /** @brief Number of eMios channels in the Icu configuration */
    uint8                                  nNumChannels;
    /** @brief Pointer to the configured channels for eMios */
    const eMios_Icu_Ip_ChannelConfigType  (*pChannelsConfig)[];
} eMios_Icu_Ip_ConfigType;


/** @brief This structure is used by the IPL driver for internal logic. */
typedef struct
{
    /** @brief eMios UC mode of operation. */
    eMios_Icu_Ip_UCModeType                         operationMode;
    /** @brief Master bus selection. */
    eMios_Icu_Ip_BusType                            BusSelected;
    /** @brief EMIOS channel mode. */
    eMios_Icu_Ip_ModeType                           channelMode;
    /** @brief Support DMA or not. */
    eMios_Icu_Ip_SubModeType                        dmaMode;
    /** @brief Type of edge used for activation. */
    eMios_Icu_Ip_EdgeType                           edgeTrigger;
    /** @brief Calback for other types of measurement.*/
    eMios_Icu_Ip_CallbackType                       callback;
    /** @brief Calback for HLD logic channel status changes */
    eMios_Icu_Ip_LogicChStateCbType                 logicChStateCallback;
    /** @brief Logic channel for which callback is executed. */
    uint16                                          callbackParam;
    /** @brief Measurement of ICU signal property without using interrupt. */
    boolean                                         msWithoutInterrupt;
#if (STD_ON == EMIOS_ICU_IP_TIMESTAMP_API)
    /** @brief Timestamp buffer type for timestamp mode. */
    eMios_Icu_Ip_TimestampBufferType                timestampBufferType;
    /** @brief Pointer to the buffer-array where the timestamp values shall be placed. */
    eMios_Icu_ValueType                             *eMios_Icu_Ip_aBuffer;
    /** @brief Variable for saving the size of the external buffer (number of entries). */
    uint16                                          eMios_Icu_Ip_aBufferSize;
    /** @brief Variable for saving Notification interval (number of events). */
    uint16                                          eMios_Icu_Ip_aBufferNotify;
    /** @brief Variable for saving the number of notify counts. */
    uint16                                          eMios_Icu_Ip_aNotifyCount;
    /** @brief Variable for saving the time stamp index. */
    uint16                                          eMios_Icu_Ip_aBufferIndex;
#endif /* (STD_ON == EMIOS_ICU_IP_TIMESTAMP_API) */
#if (defined(EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API) && (STD_ON == EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API))
    /** @brief Store the status of the first measurement. */
    boolean                                         firstEdge;
    /** @brief Signal measurement mode. */
    eMios_Icu_Ip_MeasType                           measurement;
    /** @brief Variable for saving the period. */
    eMios_Icu_ValueType                             eMios_Icu_Ip_aPeriod;
    /** @brief Variable for saving the pulse width of active time. */
    eMios_Icu_ValueType                             eMios_Icu_Ip_aActivePulseWidth;
#endif /* (defined(EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API) && (STD_ON == EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API)) */
#if ((STD_ON == EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL) || (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL))
    /** @brief Dma Channel Id. */
    uint8                                           dmaChannel;
#endif /* ((STD_ON == EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL) || (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL)) */
#if (defined(EMIOS_ICU_IP_EDGE_COUNT_API) && (STD_ON == EMIOS_ICU_IP_EDGE_COUNT_API))
    /** @brief Logic variable to count edges. */
    uint16                                          edgeNumbers;

#if (STD_ON == EMIOS_ICU_IP_SET_MAX_COUNTER)
    /** @brief Logic variable to count edges. */
    uint32                                          maxCounterValue;
#endif  /* STD_ON == EMIOS_ICU_IP_SET_MAX_COUNTER */
#endif /* (defined(EMIOS_ICU_IP_EDGE_COUNT_API) && (STD_ON == EMIOS_ICU_IP_EDGE_COUNT_API)) */
    /** @brief The notification functions for TIME_STAMP or SIGNAL_EDGE_DETECT mode. */
    eMios_Icu_Ip_NotifyType                         eMiosChannelNotification;
    /** @brief The notification functions for TIME_STAMP or SIGNAL_EDGE_DETECT mode. */
    eMios_Icu_Ip_NotifyType                         eMiosOverflowNotification;
    /** @brief Enables or disables the user notification call */
    boolean                                         notificationEnable;
    /* State of initialized EMIOS modules. */
    boolean                                         channelsInitState;
} eMios_Icu_Ip_ChStateType;

#endif  /* EMIOS_ICU_IP_USED */

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* EMIOS_ICU_IP_TYPES_H */
