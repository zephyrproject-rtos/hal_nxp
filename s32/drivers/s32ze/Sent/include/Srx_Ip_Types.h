/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file    Srx_Ip_Types.h
*   @version 2.0.1
*
*   @brief   AUTOSAR Sent - Low level header of Sent driver.
*   @details This file contains declarations of the functions defined by AutoSAR.
*
*   @addtogroup SRX_IP_DRIVER
*   @{
*/

#ifndef SRX_IP_TYPES_H
#define SRX_IP_TYPES_H


#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Srx_Ip_Defines.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SRX_IP_TYPES_VENDOR_ID                    43
#define SRX_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define SRX_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define SRX_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define SRX_IP_TYPES_SW_MAJOR_VERSION             2
#define SRX_IP_TYPES_SW_MINOR_VERSION             0
#define SRX_IP_TYPES_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Sent_Cfg.h  header file are of the same vendor */
#if (SRX_IP_TYPES_VENDOR_ID != SRX_IP_DEFINES_VENDOR_ID)
#error "Srx_Ip_Types.h and Sent_Cfg.h have different vendor ids"
#endif
/* Check if current file and Sent_Cfg.h   header file are of the same Autosar version */
#if ((SRX_IP_TYPES_AR_RELEASE_MAJOR_VERSION != SRX_IP_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (SRX_IP_TYPES_AR_RELEASE_MINOR_VERSION != SRX_IP_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (SRX_IP_TYPES_AR_RELEASE_REVISION_VERSION != SRX_IP_DEFINES_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of Srx_Ip_Types.h and Srx_Ip_Defines.h are different"
#endif

/* Check if current file and Sent_Cfg.h  header file are of the same software version */
#if ((SRX_IP_TYPES_SW_MAJOR_VERSION != SRX_IP_DEFINES_SW_MAJOR_VERSION) || \
     (SRX_IP_TYPES_SW_MINOR_VERSION != SRX_IP_DEFINES_SW_MINOR_VERSION) || \
     (SRX_IP_TYPES_SW_PATCH_VERSION != SRX_IP_DEFINES_SW_PATCH_VERSION))
  #error "Software Version Numbers of Srx_Ip_Types.h and Srx_Ip_Defines.h are different"
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef enum
{
    SRX_IP_SUCCESS                   = 0x000U,
    SRX_IP_ERROR                     = 0x001U
} Srx_Ip_StatusType;

/**
* @brief          Srx_Ip_SerialMsgType
* @details
* @internal
*/
/* @implements     Srx_Ip_SerialMsgFomatType_enum */
typedef enum
{
    SRX_IP_SHORT_SERIAL = 0,
    SRX_IP_ENHANCED_SERIAL_4_ID,
    SRX_IP_ENHANCED_SERIAL_8_ID
} Srx_Ip_SerialMsgFomatType;

/**
* @brief          Receiving mode
* @details
*
*/
typedef enum
{
    SRX_IP_POLLING = 0,
    SRX_IP_INTERRUPT,
    SRX_IP_DMA
} Srx_Ip_ReceivedMode;

/**
* @brief          Sent_StatusCRCImplementType
* @details        To chose the way to Fast/Slow message implement CRC
*
* @internal
*/
/* @implements     Srx_Ip_CRCImplementationType_enum */
typedef enum
{
    SRX_IP_RECOMMENDED_IMPLEMENTATION = 0U,  /*!< CRC Recommended Implementation */
    SRX_IP_LEGACY_IMPLEMENTATION   /*!< CRC Legacy Implementation */
} Srx_Ip_CRCImplementationType;

/* @implements     Srx_Ip_PausePulseType_enum */
typedef enum
{
    SRX_IP_PAUSE_PULSE_DISABLED = 0U,
    SRX_IP_PAUSE_PULSE_ENABLED
} Srx_Ip_PausePulseType;

/**
* @brief          SuccessiveCalibCheckType
* @details        To chose the way to Fast/Slow message implement CRC
* @internal
*/
typedef enum
{
    SRX_IP_OPTION_2_LOW_LATENCY = 0U,
    SRX_IP_OPTION_1_PREFERRED
} Srx_Ip_SuccessiveCalibCheckType;

typedef enum
{
    SRX_IP_BUS_IDLE = 0U,
    SRX_IP_CAL_RESYNC,
    SRX_IP_CAL_20_25,
    SRX_IP_SMSG_OFLW,
    SRX_IP_FMSG_OFLW,
    SRX_IP_NIB_VAL_ERR_LOW,
    SRX_IP_PP_DIAG_ERR,
    SRX_IP_CAL_LEN_ERR,
    SRX_IP_CAL_DIAG_ERR,
    SRX_IP_NIB_VAL_ERR_HIGH,
    SRX_IP_SMSG_CRC_ERR,
    SRX_IP_FMSG_CRC_ERR,
    SRX_IP_NUM_EDGES_ERR,
    SRX_IP_CLEAR_ALL
} Srx_Ip_ChannelStatusType;

/**
* @brief          Type of message should be received
* @details        Type of message should be received
*/
typedef enum
{
    SRX_IP_FAST_MSG_ONLY = 0U,
    SRX_IP_SERIAL_MSG_ONLY,
    SRX_IP_BOTH_MSG
} Srx_Ip_ReceivedMsgType;

typedef struct
{
    uint32 CompPrescaler;
    uint32 CompEnable;
    uint32 RxPrescaler;
}Srx_Ip_ChannelClkCtrType;

typedef enum
{
    SRX_IP_RANGE_20 = 0U,
    SRX_IP_RANGE_25
} Srx_Ip_ValidCalibrationPulseType;

typedef enum
{
    SRX_IP_BUS_TIMEOUT_DISABLED = 0,
    SRX_IP_RECEIVER_CLOCK_TICK_COUNTS_256 = 1U,
    SRX_IP_RECEIVER_CLOCK_TICK_COUNTS_512 = 2U,
    SRX_IP_RECEIVER_CLOCK_TICK_COUNTS_1024 = 4U,
    SRX_IP_RECEIVER_CLOCK_TICK_COUNTS_2048 = 8U
} Srx_Ip_BusTimeoutType;

typedef struct
{
    Srx_Ip_BusTimeoutType BusTimeout;
    boolean FastCrcCheckOff;
    boolean IgnoreSameFrame;
    Srx_Ip_CRCImplementationType FastCrcType;
    Srx_Ip_CRCImplementationType SlowCrcType;
    Srx_Ip_PausePulseType PausePulseEn;
    Srx_Ip_SuccessiveCalibCheckType SuccessiveCalibCheck;
    Srx_Ip_ValidCalibrationPulseType SentValidCalibrationPulse;
    boolean CrcStatusNibbleIncluding;
}Srx_Ip_ChannelConfigRegType;

/* @implements      Srx_Ip_SerialMsgType_struct */
typedef struct
{
    Srx_Ip_SerialMsgFomatType   MsgType;    /*!< Type of serial message (SHORT OR ENHANCED 4BIT/8BIT) */
    uint8               MessageId;            /*!< Serial Message ID */
    uint16              MessageData;         /*!< Data contained in the Serial Message */
    uint16               SerialCrc;            /*!< Serial Message CRC */
#if (SRX_IP_TIMESTAMP_FEATURE_ENABLE == STD_ON)
    uint32          TimestampSerial;
#endif
} Srx_Ip_SerialMsgType;

/* @implements      Srx_Ip_FastMsgType_struct */
typedef struct
{
    uint8           Length;                           /*!< Lenght of the fast message */
    uint8           DataNibble[8];   /*!< Content of each nibble in the fast message */
    uint8           StatusCommunication;                /*!< The Status Communication Nibble */
    uint8           FastCrc;                          /*!< Fast Message CRC */
#if (SRX_IP_TIMESTAMP_FEATURE_ENABLE == STD_ON)
    uint32          TimestampFast;
#endif
} Srx_Ip_FastMsgType;


/* @implements     Srx_Ip_ErrorCallBackType_typedef */
typedef void (*Srx_Ip_ErrorCallBackType)(uint8 ControllerId, uint8 ChannelId, Srx_Ip_ChannelStatusType ErrorEvent);

/* @implements     Srx_Ip_FastNotificationType_typedef */
typedef void (*Srx_Ip_FastNotificationType)(uint8 ControllerId, uint8 ChannelId, Srx_Ip_FastMsgType* FastMsgDataPtr);

/* @implements     Srx_Ip_SerialNotificationType_typedef */
typedef void (*Srx_Ip_SerialNotificationType)(uint8 ControllerId, uint8 ChannelId, Srx_Ip_SerialMsgType* SerialMsgDataPtr);

typedef struct
{
    uint8    ControllerId;           /*!< Id of Controller contain channel*/
    uint8    ControllerHwOffset;     /*!< HWOffet of Controller contain channel*/
    uint8    ChannelId;              /*!< Id of channel*/
    uint8    ChannelHwOffset;        /*!< HWOffet of channel*/
    uint8    ChannelDataLength;                         /** @brief Channel Data length */
    uint32 ChannelTickLengthUs;
    Srx_Ip_ChannelConfigRegType ChannelConfigReg;
#if (SRX_IP_DMA_FEATURE_ENABLE == STD_ON)
    uint8 FastDmaChannel;
    uint8 SerialDmaChannel;
    boolean EnableHwFiFo;
    uint32 * FastDmaBuffer;
    uint32 * SerialDmaBuffer;
#endif
} Srx_Ip_ChannelStateType;

typedef struct
{
    const uint8    ControllerId;           /*!< Id of Controller contain channel*/
    const uint8    ControllerHwOffset;     /*!< HWOffet of Controller contain channel*/
    const uint8    ChannelId;              /*!< Id of channel*/
    const uint8    ChannelHwOffset;        /*!< HWOffet of channel*/
    const uint8    ChannelDataLength;                         /** @brief Channel Data length */
    const uint32 ChannelTickLengthUs;
    const Srx_Ip_ChannelConfigRegType ChannelConfigReg;
#if (SRX_IP_DMA_FEATURE_ENABLE == STD_ON)
    const uint8 FastDmaChannel;
    const uint8 SerialDmaChannel;
    const boolean EnableHwFiFo;
    uint32 * FastDmaBuffer;
    uint32 * SerialDmaBuffer;
#endif
} Srx_Ip_ChannelUserConfigType;

/* @implements      Srx_Ip_ControllerStateType_struct */
typedef struct
{
    uint8    ControllerHwOffset;     /*!< HWOffet of Controller contain channel*/
    Srx_Ip_ChannelStateType ChnlConfig[8];
    uint8 NumberChnlConfigured;
#if (SRX_IP_TIMESTAMP_FEATURE_ENABLE == STD_ON)
    uint8 SentTimestampPrescaler;
#endif
    Srx_Ip_ReceivedMode ControllerMode;                          /** @brief Channel processing mode */
    uint32  HighFreqRxClock;
    uint32  FastMsgReadyMask;
    uint32  SerialMsgReadyMask;
    Srx_Ip_ErrorCallBackType FastErrorNotification;
    Srx_Ip_ErrorCallBackType SerialErrorNotification;
    Srx_Ip_FastNotificationType FastFrameNotification;
    Srx_Ip_SerialNotificationType SerialFrameNotification;
    boolean FastClearingEnable;
#if (SRX_IP_DMA_FEATURE_ENABLE == STD_ON)
    uint8 DmaBufferDepth;
#endif
} Srx_Ip_ControllerStateType;

/**
* @brief          Storing data of controller configuration for initial controller
* @details        Storing data of controller configuration for initial controller
*
* @implements      Srx_Ip_ControllerConfigType_struct
*/
typedef struct
{
    const uint8    ControllerId;                        /*!< Id of Controller contain channel*/
    const uint8    ControllerHwOffset;                  /*!< HWOffet of Controller contain channel*/
#if (SRX_IP_TIMESTAMP_FEATURE_ENABLE == STD_ON)
    const uint8 SentTimestampPrescaler;
#endif
    const Srx_Ip_ReceivedMode ControllerMode;           /*!<  Channel processing mode */
    const uint8 NumberChnlConfigured;                   /*!<  Number of channel configured in a Sent controller */
    const uint32  HighFreqRxClock;                      /*!<  Receiver clock */
    Srx_Ip_ErrorCallBackType FastErrorNotification;     /*!<  Pointer to FastErrorNotification */
    Srx_Ip_ErrorCallBackType SerialErrorNotification;   /*!<  Pointer to SerialErrorNotification */
    Srx_Ip_FastNotificationType FastFrameNotification;  /*!<  Pointer to FastFrameNotification */
    Srx_Ip_SerialNotificationType SerialFrameNotification;  /*!<  Pointer to SerialFrameNotification */
    boolean FastClearingEnable;                         /*!<  Enable/disable fast clearing flag */
#if (SRX_IP_DMA_FEATURE_ENABLE == STD_ON)
    const uint8 DmaBufferDepth;                         /*!<  Length of DMA buffer */
#endif
    const Srx_Ip_ChannelUserConfigType * const * const ChnlConfig; /*!<  Array pointer point to Channel of controler*/
} Srx_Ip_ControllerConfigType;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                           MACROS
=====================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
          }
#endif

#endif /* SRX_IP_H */

/** @} */
