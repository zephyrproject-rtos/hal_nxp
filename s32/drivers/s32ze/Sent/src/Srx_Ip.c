/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file    Srx_Ip.c
*   @version 2.0.1
*
*   @brief   AUTOSAR Sent - Low level part of Sent driver.
*   @details This file contains the functions defined by AutoSAR.
*
*   @addtogroup SRX_IP_DRIVER
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
#include "Srx_Ip.h"
#include "Srx_Ip_HwAccess.h"
#include "SchM_Sent.h"

#include "OsIf.h"
#ifdef SRX_IP_DMA_FEATURE_ENABLE
#if (SRX_IP_DMA_FEATURE_ENABLE == STD_ON)
  #include "Dma_Ip.h"
#endif
#endif

#ifdef SRX_IP_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == SRX_IP_ENABLE_USER_MODE_SUPPORT)
    #ifdef SRX_IP_REG_PROT_AVAILABLE
        #include "RegLockMacros.h"
    #endif
#endif
#endif
#if (STD_ON == SRX_IP_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @file           Srx_Ip.c
*/
#define SRX_IP_VENDOR_ID_C                    43
#define SRX_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define SRX_IP_AR_RELEASE_MINOR_VERSION_C     7
#define SRX_IP_AR_RELEASE_REVISION_VERSION_C  0
#define SRX_IP_SW_MAJOR_VERSION_C             2
#define SRX_IP_SW_MINOR_VERSION_C             0
#define SRX_IP_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Sent.h  header file are of the same vendor */
#if (SRX_IP_VENDOR_ID_C != SRX_IP_VENDOR_ID)
    #error "Srx_Ip.c and Srx_Ip.h have different vendor ids"
#endif
/* Check if current file and Sent.h   header file are of the same Autosar version */
#if ((SRX_IP_AR_RELEASE_MAJOR_VERSION_C != SRX_IP_AR_RELEASE_MAJOR_VERSION) || \
     (SRX_IP_AR_RELEASE_MINOR_VERSION_C != SRX_IP_AR_RELEASE_MINOR_VERSION) || \
     (SRX_IP_AR_RELEASE_REVISION_VERSION_C != SRX_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Srx_Ip.c and Srx_Ip.h are different"
#endif

/* Check if current file and Sent.h  header file are of the same software version */
#if ((SRX_IP_SW_MAJOR_VERSION_C != SRX_IP_SW_MAJOR_VERSION) || \
     (SRX_IP_SW_MINOR_VERSION_C != SRX_IP_SW_MINOR_VERSION) || \
     (SRX_IP_SW_PATCH_VERSION_C != SRX_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Srx_Ip.c and Srx_Ip.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define SRX_IP_UNINIT 0xFFU
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define SENT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sent_MemMap.h"

static Srx_Ip_ControllerStateType Srx_Ip_ControllerState[SRX_IP_INSTANCE_COUNT];

#define SENT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sent_MemMap.h"
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define SENT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Sent_MemMap.h"

static Srx_Ip_ControllerStateType* Srx_Ip_apxControllerState[SRX_INSTANCE_COUNT] = {NULL_PTR, NULL_PTR};

#define SENT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Sent_MemMap.h"

#define SENT_START_SEC_VAR_INIT_8
#include "Sent_MemMap.h"

static uint8 Srx_Ip_ChannelIdByOffset[SRX_INSTANCE_COUNT][SRX_CNL_COUNT] =
{
    {SRX_IP_UNINIT, SRX_IP_UNINIT, SRX_IP_UNINIT, SRX_IP_UNINIT, SRX_IP_UNINIT, SRX_IP_UNINIT, SRX_IP_UNINIT, SRX_IP_UNINIT},
    {SRX_IP_UNINIT, SRX_IP_UNINIT, SRX_IP_UNINIT, SRX_IP_UNINIT, SRX_IP_UNINIT, SRX_IP_UNINIT, SRX_IP_UNINIT, SRX_IP_UNINIT}
};
static uint8 Srx_Ip_ControllerIdByOffset[SRX_INSTANCE_COUNT] =
{
    SRX_IP_UNINIT, SRX_IP_UNINIT
};

#define SENT_STOP_SEC_VAR_INIT_8
#include "Sent_MemMap.h"
/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/
static void Srx_Ip_ProcessSerialMsg(uint8 HwCtrlOffset, uint8 HwChnlOffset, Srx_Ip_SerialMsgType* SerialMsg, boolean SerialClearingInterrupt);
static void Srx_Ip_ProcessFastMsg(uint8 HwCtrlOffset, uint8 HwChnlOffset, Srx_Ip_FastMsgType* FastMsg, boolean FastClearingInterrupt);
static boolean Srx_Ip_CheckChannelStatus(uint32 RegValue, Srx_Ip_ChannelStatusType Status);
static void Srx_Ip_ProcessIncomingFastMsg(uint8 ControllerId, uint32 * TempFast);
static void Srx_Ip_ProcessIncomingSerialMsg(uint8 ControllerId, uint32 * TempSerial);
static boolean Srx_Ip_ExistEnabledChannels(uint8 ControllerId);
static void Srx_Ip_VerifyChannelStatus(uint8 ControllerId, uint8 ChannelId, uint32 ChannelStatusReg);
/*================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"

/**
* @brief       Process error handler of specific channel in case not using interrupt mode with combined interrupt
* @brief       Process error handler of specific channel in case not using interrupt mode with combined interrupt.
*
* @param        HwCtrlOffset: The offset of controller.
* @param        HwChnlOffset: The offset of channel.
* @param        Mode:         Controller mode
*
* @return       void
* @implements Srx_Ip_ProcessChannelError_Activity
*
*/
void Srx_Ip_ProcessChannelError
(
    uint8 HwCtrlOffset,
    uint8 HwChnlOffset,
    Srx_Ip_ReceivedMode Mode
)
{
    /* Index of controller and channel in configuration */
    uint8 ControllerId = Srx_Ip_ControllerIdByOffset[HwCtrlOffset];
    uint8 ChannelId = Srx_Ip_ChannelIdByOffset[HwCtrlOffset][HwChnlOffset];
    uint32 ChannelStatusReg = 0U;
    const Srx_Ip_ControllerStateType * Receiver;

    SchM_Enter_Sent_SENT_EXCLUSIVE_AREA_01();
    if ((SRX_IP_UNINIT != ControllerId) && (SRX_IP_UNINIT != ChannelId))
    {   

        Receiver = Srx_Ip_apxControllerState[ControllerId];
        if ((((SRX_IP_INTERRUPT == Mode) && (SRX_IP_POLLING != Receiver->ControllerMode)) || (Mode == Receiver->ControllerMode)) && Srx_Ip_GetChannelEnable(HwCtrlOffset, HwChnlOffset))
        {   

            ChannelStatusReg = Srx_Ip_GetChannelStatus(HwCtrlOffset, HwChnlOffset);
            Srx_Ip_ClearChannelStatus(HwCtrlOffset, HwChnlOffset, SRX_IP_BUS_IDLE);

            Srx_Ip_VerifyChannelStatus(ControllerId, ChannelId, ChannelStatusReg);

            Srx_Ip_ClearChannelStatus(HwCtrlOffset, HwChnlOffset, SRX_IP_CLEAR_ALL);
        }
    }
    else
    {
        Srx_Ip_ClearChannelStatus(HwCtrlOffset, HwChnlOffset, SRX_IP_CLEAR_ALL);
    }

    SchM_Exit_Sent_SENT_EXCLUSIVE_AREA_01();
}

/**
*   @brief          This function processes Fast data
*/
static void Srx_Ip_ProcessFastMsg(uint8 HwCtrlOffset, uint8 HwChnlOffset, Srx_Ip_FastMsgType* FastMsg, boolean FastClearingInterrupt)
{
    /* Get register value of data  */
    uint32 RegReadData  = 0U;
    /* Get register value of crc  */
    uint32 RegReadCrc;
    /* Get value Timestamp */
    uint8 Index;
    /* Get raw data from the register */
    RegReadData = Srx_Ip_GetFastMessageDataRegister(HwCtrlOffset, HwChnlOffset);
    /* Get raw CRC data from the register */
    RegReadCrc =  Srx_Ip_GetFastMessageCrcRegister(HwCtrlOffset, HwChnlOffset);
    /* Nibbles of data */
    for (Index = 0U; Index < (FastMsg->Length); Index++)
    {
        FastMsg->DataNibble[Index] = (uint8)((RegReadData >> ((7U - Index) * 4U)) & 0xFU);
    }
    /* The fast message status and communication nibble */
    FastMsg->StatusCommunication = (uint8)((RegReadCrc & SRX_CH_FMSG_CRC_SCNIB_MASK) >> SRX_CH_FMSG_CRC_SCNIB_SHIFT);
    /* The CRC value */
    FastMsg->FastCrc = (uint8)((RegReadCrc & SRX_CH_FMSG_CRC_CRC4b_MASK) >> SRX_CH_FMSG_CRC_CRC4b_SHIFT);
#if (SRX_IP_TIMESTAMP_FEATURE_ENABLE == STD_ON)
    /* The TS value */
    FastMsg->TimestampFast = Srx_Ip_GetFastMessageTimestamp(HwCtrlOffset, HwChnlOffset);
#else
    /* Three fast message register need to be read in oder to self-clear F_RDY */
    (void)Srx_Ip_GetFastMessageTimestamp(HwCtrlOffset, HwChnlOffset);
#endif

    if (!FastClearingInterrupt)
    {
        Srx_Ip_ClearFastMsgReadyStatus(HwCtrlOffset, HwChnlOffset);
    }
}

/**
*   @brief          This function processes Serial data
*/
static void Srx_Ip_ProcessSerialMsg(uint8 HwCtrlOffset, uint8 HwChnlOffset, Srx_Ip_SerialMsgType* SerialMsg, boolean SerialClearingInterrupt)
{
    uint32 RegRead3 = 0U;
    uint32 RegRead2 = 0U;

    RegRead3 = Srx_Ip_GetSerialMessageBit3(HwCtrlOffset, HwChnlOffset);
    RegRead2 = Srx_Ip_GetSerialMessageBit2(HwCtrlOffset, HwChnlOffset);
    /* Checking what type of serial message is Short or Enhance */
    if (((RegRead3 & SRX_CH_SMSG_BIT3_TYPE_MASK) >> SRX_CH_SMSG_BIT3_TYPE_SHIFT) != 0U)
    {
        if (((RegRead3 & SRX_CH_SMSG_BIT3_CFG_MASK) >> SRX_CH_SMSG_BIT3_CFG_SHIFT) != 0U)
        /* Checking what the type of ID of Enhance message */
        {
            /* Enhance serial message with 4-bit ID field */
            SerialMsg->MsgType = SRX_IP_ENHANCED_SERIAL_4_ID;
            /* Id of Enhance serial message */
            SerialMsg->MessageId = (uint8)((RegRead3 & SRX_CH_SMSG_BIT3_ID7_4_ID3_0_MASK) >> SRX_CH_SMSG_BIT3_ID7_4_ID3_0_SHIFT);
            /* Data of Enhance serial message */
            SerialMsg->MessageData = (uint16)((RegRead3 & SRX_CH_SMSG_BIT3_ID3_0_DATA15_12_MASK) >> SRX_CH_SMSG_BIT3_ID3_0_DATA15_12_SHIFT);
            SerialMsg->MessageData = (SerialMsg->MessageData << 12U) | (uint16)((RegRead2 & SRX_CH_SMSG_BIT2_DATA_MASK) >> SRX_CH_SMSG_BIT2_DATA_SHIFT);
        }
        else
        {
            /* Enhance serial message with 8-bit ID field */
            SerialMsg->MsgType = SRX_IP_ENHANCED_SERIAL_8_ID;
            /* Id of Enhance serial message */
            SerialMsg->MessageId = (uint8)((((RegRead3 & SRX_CH_SMSG_BIT3_ID7_4_ID3_0_MASK) >> SRX_CH_SMSG_BIT3_ID7_4_ID3_0_SHIFT) << 4U) | ((RegRead3 & SRX_CH_SMSG_BIT3_ID3_0_DATA15_12_MASK) >> SRX_CH_SMSG_BIT3_ID3_0_DATA15_12_SHIFT));
            /* Data of Enhance serial message */
            SerialMsg->MessageData = (uint16)((RegRead2 & SRX_CH_SMSG_BIT2_DATA_MASK) >> SRX_CH_SMSG_BIT2_DATA_SHIFT);
        }
        /* CRC value of message */
        SerialMsg->SerialCrc = (uint16)((RegRead2 & SRX_CH_SMSG_BIT2_SMCRC_MASK) >> SRX_CH_SMSG_BIT2_SMCRC_SHIFT);
    }
    else
    {
        /* Short serial message */
        SerialMsg->MsgType = SRX_IP_SHORT_SERIAL;
        /* The Id of Short serial message */
        SerialMsg->MessageId = (uint8)(((RegRead2 & SRX_CH_SMSG_BIT2_DATA_MASK) >> 0x8U) & 0xFU);
        /* Get raw data that channel received */
        /* The data of Short serial message */
        SerialMsg->MessageData = (uint16)(((RegRead2 & SRX_CH_SMSG_BIT2_DATA_MASK) >> SRX_CH_SMSG_BIT2_DATA_SHIFT) & 0xFFU);
        /* CRC value of message */
        SerialMsg->SerialCrc = (uint16)((RegRead2 & 0xF0000U) >> SRX_CH_SMSG_BIT2_SMCRC_SHIFT);
    }
#if (SRX_IP_TIMESTAMP_FEATURE_ENABLE == STD_ON)
    /* TS value */
    SerialMsg->TimestampSerial = Srx_Ip_GetSerialMessageTimestamp(HwCtrlOffset,HwChnlOffset);
#else
    (void)Srx_Ip_GetSerialMessageTimestamp(HwCtrlOffset,HwChnlOffset);
#endif
    if (!SerialClearingInterrupt)
    {
        /* Clear Serial Msg status on channel */
        Srx_Ip_ClearSerialMsgReadyStatus(HwCtrlOffset, HwChnlOffset);
    }
}

/**
*   @brief        Function used to calculate the Prescaler Value.
*/

static uint32 Srx_Ip_RxPrescalerCalculate(uint32 ChannelTickLengthUs, uint32 HighFreqRxClock)
{
    uint32 Temp;

    Temp = (uint32)((ChannelTickLengthUs * HighFreqRxClock)/1000000U);
    if (((ChannelTickLengthUs * HighFreqRxClock) - (Temp * 1000000U)) >=500000U)
    {
        Temp++;
    }
    return Temp;
}

#if (SRX_IP_DMA_FEATURE_ENABLE == STD_ON)
/**
*   @brief          This function processes Fast data
*/
static void Srx_Ip_DmaProcessFastMsg(const uint32 * BufferAdrress, Srx_Ip_FastMsgType* FastMsg)
{
    /* Get register value of data  */
    uint32 RegReadData  = 0U;
    /* Get register value of crc  */
    uint32 RegReadCrc;
    uint8 Index;
    /* Get raw data from the register */
    RegReadData = BufferAdrress[0];
    /* Get raw CRC data from the register */
    RegReadCrc =  BufferAdrress[1];
    /* Nibbles of data */
    for (Index = 0U; Index < (FastMsg->Length); Index++)
    {
        FastMsg->DataNibble[Index] = (uint8)((RegReadData >> ((7U - Index) * 4U)) & 0xFU);
    }
    /* The fast message status and communication nibble */
    FastMsg->StatusCommunication = (uint8)((RegReadCrc & SRX_CH_F_DMA_CRC_SCNIB_MASK) >> SRX_CH_F_DMA_CRC_SCNIB_SHIFT);
    /* The CRC value */
    FastMsg->FastCrc = (uint8)((RegReadCrc & SRX_CH_F_DMA_CRC_CRC4b_MASK) >> SRX_CH_F_DMA_CRC_CRC4b_SHIFT);
#if (SRX_IP_TIMESTAMP_FEATURE_ENABLE == STD_ON)
    /* Get Timestamp value*/
    FastMsg->TimestampFast = BufferAdrress[2];
#endif
}

/**
*   @brief          This function processes Serial data
*/
static void Srx_Ip_DmaProcessSerialMsg(const uint32 * BufferAdrress, Srx_Ip_SerialMsgType* SerialMsg)
{
    uint32 RegRead3 = 0U;
    uint32 RegRead2 = 0U;

    RegRead3 = BufferAdrress[0];
    RegRead2 = BufferAdrress[1];
    if (((RegRead3 & SRX_CH_SMSG_BIT3_TYPE_MASK) >> SRX_CH_SMSG_BIT3_TYPE_SHIFT) != 0U)
    {
        if (((RegRead3 & SRX_CH_SMSG_BIT3_CFG_MASK) >> SRX_CH_SMSG_BIT3_CFG_SHIFT) != 0U)
        /* Checking what the type of ID of Enhance message */
        {
            /* Enhance serial message with 4-bit ID field */
            SerialMsg->MsgType = SRX_IP_ENHANCED_SERIAL_4_ID;
            /* Id of Enhance serial message */
            SerialMsg->MessageId = (uint8)((RegRead3 & SRX_CH_SMSG_BIT3_ID7_4_ID3_0_MASK) >> SRX_CH_SMSG_BIT3_ID7_4_ID3_0_SHIFT);
            /* Data of Enhance serial message */
            SerialMsg->MessageData = (uint16)((RegRead3 & SRX_CH_SMSG_BIT3_ID3_0_DATA15_12_MASK) >> SRX_CH_SMSG_BIT3_ID3_0_DATA15_12_SHIFT);
            SerialMsg->MessageData = (SerialMsg->MessageData << 12U) | (uint16)((RegRead2 & SRX_CH_SMSG_BIT2_DATA_MASK) >> SRX_CH_SMSG_BIT2_DATA_SHIFT);
        }
        else
        {
            /* Enhance serial message with 8-bit ID field */
            SerialMsg->MsgType = SRX_IP_ENHANCED_SERIAL_8_ID;
            /* Id of Enhance serial message */
            SerialMsg->MessageId = (uint8)((((RegRead3 & SRX_CH_SMSG_BIT3_ID7_4_ID3_0_MASK) >> SRX_CH_SMSG_BIT3_ID7_4_ID3_0_SHIFT) << 4U) | ((RegRead3 & SRX_CH_SMSG_BIT3_ID3_0_DATA15_12_MASK) >> SRX_CH_SMSG_BIT3_ID3_0_DATA15_12_SHIFT));
            /* Data of Enhance serial message */
            SerialMsg->MessageData = (uint16)((RegRead2 & SRX_CH_SMSG_BIT2_DATA_MASK) >> SRX_CH_SMSG_BIT2_DATA_SHIFT);
        }
        /* CRC value of message */
        SerialMsg->SerialCrc = (uint16)((RegRead2 & SRX_CH_SMSG_BIT2_SMCRC_MASK) >> SRX_CH_SMSG_BIT2_SMCRC_SHIFT);
    }
    else
    {
        /* Short serial message */
        SerialMsg->MsgType = SRX_IP_SHORT_SERIAL;
        /* The Id of Short serial message */
        SerialMsg->MessageId = (uint8)(((RegRead2 & SRX_CH_SMSG_BIT2_DATA_MASK) >> 0x8U) & 0xFU);
        /* Get raw data that channel received */
        /* The data of Short serial message */
        SerialMsg->MessageData = (uint16)(((RegRead2 & SRX_CH_SMSG_BIT2_DATA_MASK) >> SRX_CH_SMSG_BIT2_DATA_SHIFT) & 0xFFU);
        /* CRC value of message */
        SerialMsg->SerialCrc = (uint16)((RegRead2 & 0xF0000U) >> SRX_CH_SMSG_BIT2_SMCRC_SHIFT);
    }
#if (SRX_IP_TIMESTAMP_FEATURE_ENABLE == STD_ON)
    /* Get Timestamp value*/
    SerialMsg->TimestampSerial = BufferAdrress[2];
#endif
}
/**
*   @brief          This function initializes DMA for Fast
*/
/* @implements Srx_Ip_DmaNotificationHandler_Activity */
void Srx_Ip_DmaNotificationHandler
(
    uint8 HwCtrlOffset,
    uint8 HwChnlOffset,
    Srx_Ip_ReceivedMsgType ReceivedMsgType
)
{
    uint8 Index0;
    uint8 Index1;
    uint8 DmaBufferDepth;
    /* Index of channel offset in controller */
    uint8 ControllerId = Srx_Ip_ControllerIdByOffset[HwCtrlOffset];
    uint8 ChannelId = Srx_Ip_ChannelIdByOffset[HwCtrlOffset][HwChnlOffset];
    const Srx_Ip_ControllerStateType* Receiver;
    static Srx_Ip_FastMsgType SentFastFrame;
    static Srx_Ip_SerialMsgType SentSerialFrame;

    if ((SRX_IP_UNINIT != ControllerId) && (SRX_IP_UNINIT != ChannelId))
    {
        Receiver = Srx_Ip_apxControllerState[ControllerId];
        const Dma_Ip_LogicChannelTransferListType DmaChannelTransferListReceive[3] =
        {
            /* Destination configuration  */
            {
                .Param = DMA_IP_CH_SET_DESTINATION_ADDRESS, /* Dma_Ip_Set_Destination_Address */
                .Value = (uint32)Receiver->ChnlConfig[ChannelId].FastDmaBuffer
            },
            {
                .Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT, /* Dma_Ip_Set_Control_EnIntMajor */
                .Value = 1,
            },
            {
                .Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT, /* Dma_Ip_Set_Control_EnIntMajor */
                .Value = 0,
            },
        };

        if (SRX_IP_FAST_MSG_ONLY == ReceivedMsgType)
        {
            if (Receiver->ChnlConfig[ChannelId].EnableHwFiFo)
            {
                DmaBufferDepth = Receiver->DmaBufferDepth;
            }
            else
            {
                DmaBufferDepth = 1U;
            }

            if (1U < DmaBufferDepth)
            {
                (void)Dma_Ip_SetLogicChannelTransferList(Receiver->ChnlConfig[ChannelId].FastDmaChannel, &DmaChannelTransferListReceive[2], 1);

                for (Index0 = 0U; Index0 < (DmaBufferDepth - 1U); Index0++)
                {
                    (void)Dma_Ip_SetLogicChannelCommand(Receiver->ChnlConfig[ChannelId].FastDmaChannel, DMA_IP_CH_SET_SOFTWARE_REQUEST);
                }

                (void)Dma_Ip_SetLogicChannelTransferList(Receiver->ChnlConfig[ChannelId].FastDmaChannel, &DmaChannelTransferListReceive[0], 2);
            }
            SentFastFrame.Length = Receiver->ChnlConfig[ChannelId].ChannelDataLength;
            for (Index1 = 0; Index1 < DmaBufferDepth; Index1++)
            {
                Srx_Ip_DmaProcessFastMsg(&Receiver->ChnlConfig[ChannelId].FastDmaBuffer[3U * Index1], &SentFastFrame);
                if (NULL_PTR != Receiver->FastFrameNotification)
                {
                    Receiver->FastFrameNotification(ControllerId, ChannelId, &SentFastFrame);
                }
                for (Index0 = 0U; Index0 < 3U; Index0++)
                {
                    Receiver->ChnlConfig[ChannelId].FastDmaBuffer[(3U * Index1) + Index0] = 0U;
                }
            }
        }
        if (SRX_IP_SERIAL_MSG_ONLY == ReceivedMsgType)
        {
            Srx_Ip_DmaProcessSerialMsg(Receiver->ChnlConfig[ChannelId].SerialDmaBuffer, &SentSerialFrame);
            if (NULL_PTR != Receiver->SerialFrameNotification)
            {
                Receiver->SerialFrameNotification(ControllerId, ChannelId, &SentSerialFrame);
            }
            for (Index0 = 0; Index0 < 3U; Index0++)
            {
                Receiver->ChnlConfig[ChannelId].SerialDmaBuffer[Index0] = 0U;
            }
        }
    }
}

static void Srx_Ip_InitDma
(
    uint8  ControllerId,
    uint8  ChannelId
)
{
    /* Index of channel offset in controller */
    uint8 HwCtrlOffset = 0U;
    uint8 HwChnlOffset = 0U;
    const Srx_Ip_ControllerStateType* Receiver;
    const SRX_Type* BaseAdress;

    Receiver = Srx_Ip_apxControllerState[ControllerId];

    HwCtrlOffset = Receiver->ControllerHwOffset;
    HwChnlOffset = Receiver->ChnlConfig[ChannelId].ChannelHwOffset;
    BaseAdress = Srx_Ip_apxBase[HwCtrlOffset];
    const Dma_Ip_LogicChannelGlobalListType DmaChannelGlobalListReceive[1] =
    {
        /* Source  configuration */
        {
            .Param = DMA_IP_CH_SET_EN_HARDWARE_REQ, /* Dma_Ip_Set_Source_Address */
            .Value = 1U, /* Address */
        },

    };
    Dma_Ip_LogicChannelTransferListType DmaChannelTransferListReceive[12] =
    {
        /* Source  configuration */
        {
            .Param = DMA_IP_CH_SET_SOURCE_ADDRESS, /* 0.Dma_Ip_Set_Source_Address */
            .Value = (uint32) &(BaseAdress->CNL[HwChnlOffset].CH_S_DMA_RD), /* Address */
        },
        {
            .Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET, /* 1.Dma_Ip_Set_Source_SignedOffset */
            .Value = 4,
        },
        {
            .Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE, /* 2.Dma_Ip_Set_Source_TransferSize */
            .Value = DMA_IP_TRANSFER_SIZE_4_BYTE,
        },
        /* Destination configuration  */
        {
            .Param = DMA_IP_CH_SET_DESTINATION_ADDRESS, /* 3.Dma_Ip_Set_Destination_Address */
            .Value = (uint32)Receiver->ChnlConfig[ChannelId].SerialDmaBuffer,
        }, /* ADRESA */
        {
            .Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET, /* 4.Dma_Ip_Set_Destination_SignedOffset */
            .Value = 4U,
        },
        {
            .Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE, /* 5.Dma_Ip_Set_Destination_TransferSize */
            .Value = DMA_IP_TRANSFER_SIZE_4_BYTE,
        },
        {
            .Param = DMA_IP_CH_SET_SOURCE_SIGNED_LAST_ADDR_ADJ, /* 6. */
            .Value = (uint32)(-(4 * 3)),
        },
        {
            .Param = DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ, /* 7. */
            .Value = (uint32)(-(4 * 3)),
        },
        /* Minor/Major Loop config */
        {
            .Param = DMA_IP_CH_SET_MINORLOOP_SIZE, /* 8. */
            .Value = 4U,
        },
        {
            .Param = DMA_IP_CH_SET_MAJORLOOP_COUNT, /* 9.Dma_Ip_Set_MajorLoop_Count */
            .Value = (uint32)(3),
        },
        {
            .Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT, /* 10.Dma_Ip_Set_Control_EnIntMajor */
            .Value = 1,
        },
        {
            .Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST, /* 11. */
            .Value = 0,
        }
    };

    (void)Dma_Ip_SetLogicChannelTransferList(Receiver->ChnlConfig[ChannelId].SerialDmaChannel, &DmaChannelTransferListReceive[0], 12);
    (void)Dma_Ip_SetLogicChannelGlobalList(Receiver->ChnlConfig[ChannelId].SerialDmaChannel, &DmaChannelGlobalListReceive[0], 1);

    DmaChannelTransferListReceive[0].Value = (uint32) &(BaseAdress->CNL[HwChnlOffset].CH_F_DMA_RD); /* Address */
    DmaChannelTransferListReceive[3].Value = (uint32)Receiver->ChnlConfig[ChannelId].FastDmaBuffer;
    if (Receiver->ChnlConfig[ChannelId].EnableHwFiFo)
    {
        DmaChannelTransferListReceive[7].Value = 0;
        DmaChannelTransferListReceive[8].Value = 12;
        DmaChannelTransferListReceive[9].Value = 1;
    }

    (void)Dma_Ip_SetLogicChannelTransferList(Receiver->ChnlConfig[ChannelId].FastDmaChannel, &DmaChannelTransferListReceive[0], 12);
    (void)Dma_Ip_SetLogicChannelGlobalList(Receiver->ChnlConfig[ChannelId].FastDmaChannel, &DmaChannelGlobalListReceive[0], 1);
}
#endif
/*================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/
#ifdef SRX_IP_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == SRX_IP_ENABLE_USER_MODE_SUPPORT)
    #ifdef SRX_IP_REG_PROT_AVAILABLE
        FUNC(void, CAN_CODE) Srx_Ip_SetUserAccessAllowed(void)
        {
        #ifdef SRX_IP_0_REG_PROT_AVAILABLE
            #ifdef  SENT_0_BASEADDR
                SET_USER_ACCESS_ALLOWED(SENT_0_BASEADDR, SENT_PROT_MEM_U32);
            #endif
        #endif
        #ifdef SRX_IP_1_REG_PROT_AVAILABLE
            #ifdef  SENT_1_BASEADDR
                SET_USER_ACCESS_ALLOWED(SENT_1_BASEADDR, SENT_PROT_MEM_U32);
            #endif
        #endif
        }
    #endif /* SRX_IP_REG_PROT_AVAILABLE */
#endif /* (STD_ON == SRX_IP_ENABLE_USER_MODE_SUPPORT) */
#endif


/**
* @brief        Function that initializes the SENT controller.
* @details      This function initializes register for SENT controller.
*
* @param[in]    pController - Pointer point to controller configuration
*
* @return       void
* @implements Srx_Ip_InitController_Activity
*
*/
void Srx_Ip_InitController
(
    const Srx_Ip_ControllerConfigType* pController
)
{
    uint8 ControllerId;
    uint8 ChannelId;
    uint8 HwChnlOffset;
    uint8 HwCtrlOffset;
    Srx_Ip_ChannelClkCtrType ChannelClkCtr;
    Srx_Ip_ControllerStateType* Receiver;

    #if (SRX_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(pController != NULL_PTR);;
    #endif

    ControllerId = pController->ControllerId;
    #if (SRX_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Srx_Ip_apxControllerState[ControllerId] == NULL_PTR);
    #endif

    ChannelClkCtr.CompPrescaler = 0;
    ChannelClkCtr.CompEnable = 1;
    Srx_Ip_apxControllerState[ControllerId] = &Srx_Ip_ControllerState[ControllerId];
    Receiver = Srx_Ip_apxControllerState[ControllerId];

#if (SRX_IP_DMA_FEATURE_ENABLE == STD_ON)
    Receiver->DmaBufferDepth       = pController->DmaBufferDepth;
#endif
    Receiver->ControllerHwOffset = pController->ControllerHwOffset;
#if (SRX_IP_TIMESTAMP_FEATURE_ENABLE == STD_ON)
    Receiver->SentTimestampPrescaler = pController->SentTimestampPrescaler;
#endif
    Receiver->ControllerMode = pController->ControllerMode;
    Receiver->HighFreqRxClock = pController->HighFreqRxClock;
    Receiver->NumberChnlConfigured = pController->NumberChnlConfigured;
    Receiver->FastMsgReadyMask = 0;
    Receiver->SerialMsgReadyMask = 0;
    Receiver->FastErrorNotification = pController->FastErrorNotification;
    Receiver->SerialErrorNotification = pController->SerialErrorNotification;
    Receiver->FastFrameNotification = pController->FastFrameNotification;
    Receiver->SerialFrameNotification = pController->SerialFrameNotification;
    Receiver->FastClearingEnable = pController->FastClearingEnable;

    HwCtrlOffset = Receiver->ControllerHwOffset;
    Srx_Ip_ControllerIdByOffset[HwCtrlOffset] = ControllerId;
    for (ChannelId = 0; ChannelId < pController->NumberChnlConfigured; ChannelId++)
    {
        /* Copy data from controller config struct to specific channel state struct */
        Receiver->ChnlConfig[ChannelId].ControllerId        = pController->ChnlConfig[ChannelId]->ControllerId;
        Receiver->ChnlConfig[ChannelId].ControllerHwOffset  = pController->ChnlConfig[ChannelId]->ControllerHwOffset;
        Receiver->ChnlConfig[ChannelId].ChannelId           = pController->ChnlConfig[ChannelId]->ChannelId;
        Receiver->ChnlConfig[ChannelId].ChannelHwOffset     = pController->ChnlConfig[ChannelId]->ChannelHwOffset;
        Receiver->ChnlConfig[ChannelId].ChannelDataLength   = pController->ChnlConfig[ChannelId]->ChannelDataLength;
        Receiver->ChnlConfig[ChannelId].ChannelTickLengthUs = pController->ChnlConfig[ChannelId]->ChannelTickLengthUs;
        Receiver->ChnlConfig[ChannelId].ChannelConfigReg.BusTimeout      = pController->ChnlConfig[ChannelId]->ChannelConfigReg.BusTimeout;
        Receiver->ChnlConfig[ChannelId].ChannelConfigReg.FastCrcCheckOff      = pController->ChnlConfig[ChannelId]->ChannelConfigReg.FastCrcCheckOff;
        Receiver->ChnlConfig[ChannelId].ChannelConfigReg.IgnoreSameFrame      = pController->ChnlConfig[ChannelId]->ChannelConfigReg.IgnoreSameFrame;
        Receiver->ChnlConfig[ChannelId].ChannelConfigReg.FastCrcType          = pController->ChnlConfig[ChannelId]->ChannelConfigReg.FastCrcType;
        Receiver->ChnlConfig[ChannelId].ChannelConfigReg.SlowCrcType          = pController->ChnlConfig[ChannelId]->ChannelConfigReg.SlowCrcType;
        Receiver->ChnlConfig[ChannelId].ChannelConfigReg.PausePulseEn         = pController->ChnlConfig[ChannelId]->ChannelConfigReg.PausePulseEn;
        Receiver->ChnlConfig[ChannelId].ChannelConfigReg.SuccessiveCalibCheck = pController->ChnlConfig[ChannelId]->ChannelConfigReg.SuccessiveCalibCheck;
        Receiver->ChnlConfig[ChannelId].ChannelConfigReg.SentValidCalibrationPulse         = pController->ChnlConfig[ChannelId]->ChannelConfigReg.SentValidCalibrationPulse;
        Receiver->ChnlConfig[ChannelId].ChannelConfigReg.CrcStatusNibbleIncluding = pController->ChnlConfig[ChannelId]->ChannelConfigReg.CrcStatusNibbleIncluding;
#if (SRX_IP_DMA_FEATURE_ENABLE == STD_ON)
        Receiver->ChnlConfig[ChannelId].FastDmaChannel      = pController->ChnlConfig[ChannelId]->FastDmaChannel;
        Receiver->ChnlConfig[ChannelId].SerialDmaChannel    = pController->ChnlConfig[ChannelId]->SerialDmaChannel;
        Receiver->ChnlConfig[ChannelId].EnableHwFiFo       = pController->ChnlConfig[ChannelId]->EnableHwFiFo;
        Receiver->ChnlConfig[ChannelId].FastDmaBuffer       = pController->ChnlConfig[ChannelId]->FastDmaBuffer;
        Receiver->ChnlConfig[ChannelId].SerialDmaBuffer       = pController->ChnlConfig[ChannelId]->SerialDmaBuffer;
#endif
        HwChnlOffset = Receiver->ChnlConfig[ChannelId].ChannelHwOffset;
        Srx_Ip_ChannelIdByOffset[HwCtrlOffset][HwChnlOffset] = ChannelId;

        ChannelClkCtr.RxPrescaler = Srx_Ip_RxPrescalerCalculate(Receiver->ChnlConfig[ChannelId].ChannelTickLengthUs, Receiver->HighFreqRxClock);
        /* Receiver clock tick */
        Srx_Ip_SetChannelClockController(HwCtrlOffset, HwChnlOffset, &ChannelClkCtr);

        /* Number of data nibbles supported for channel */
        Srx_Ip_SetDataController(HwCtrlOffset,HwChnlOffset, (uint32)Receiver->ChnlConfig[ChannelId].ChannelDataLength);

        /* Initialize channel configuration register */
        Srx_Ip_SetChannelConfig(HwCtrlOffset, HwChnlOffset, Receiver->ControllerMode, &(Receiver->ChnlConfig[ChannelId].ChannelConfigReg));
#if (SRX_IP_DMA_FEATURE_ENABLE == STD_ON)
        /* Initialize DMA for Fast */
        if (SRX_IP_DMA == Receiver->ControllerMode)
        {
            Srx_Ip_InitDma(ControllerId, ChannelId);
            if (Receiver->ChnlConfig[ChannelId].EnableHwFiFo)
            {
                Srx_Ip_SetFIFOChannelEnable(HwCtrlOffset, HwChnlOffset);
            }
        }
#endif
        /* Clear status register for FMSG */
        Srx_Ip_ClearFastMsgReadyStatus(HwCtrlOffset, HwChnlOffset);
        /* Clear status register for SMSG */
        Srx_Ip_ClearSerialMsgReadyStatus(HwCtrlOffset, HwChnlOffset);
        
        /* Initialize channel mode register */
        Srx_Ip_SetChannelMode(HwCtrlOffset, HwChnlOffset, Receiver->ControllerMode, TRUE);

        if (Receiver->FastFrameNotification != NULL_PTR)
        {
            Receiver->FastMsgReadyMask |= ((uint32)((uint32)(0x1U) << HwChnlOffset));
        }
        if (Receiver->SerialFrameNotification != NULL_PTR)
        {
            Receiver->SerialMsgReadyMask |= ((uint32)((uint32)(0x1U) << HwChnlOffset));
        }
    }
#if (SRX_IP_TIMESTAMP_FEATURE_ENABLE == STD_ON)
    /* Set TimestampPrescaler */
    Srx_Ip_SetTimestampPrescaler(HwCtrlOffset, Receiver->SentTimestampPrescaler);
#endif
#if (SRX_IP_DMA_FEATURE_ENABLE == STD_ON)
    Srx_Ip_SetControllerFifoWaterMask(HwCtrlOffset, Receiver->DmaBufferDepth);
#endif

    Srx_Ip_SetControllerEnable(HwCtrlOffset, TRUE);
}

/**
* @brief        Function that de-initializes the SENT controller.
* @details      This function de-initializes register for SENT controller and its channel which "ControllerId" is index of controller
*
* @param[in]    ControllerId - Controller index in configuration
*
* @return       void
* @implements Srx_Ip_DeInitController_Activity
*
*/
void Srx_Ip_DeInitController
(
    uint8 ControllerId
)
{
    /* Index of Channel current Controller */
    uint8 ChannelId = 0U;
    uint8 HwCtrlOffset;
    uint8 HwChnlOffset;
    Srx_Ip_ChannelClkCtrType ChannelClkCtr;
    #if (SRX_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(ControllerId < SRX_IP_INSTANCE_COUNT);
    #endif
    const Srx_Ip_ControllerStateType * Receiver = Srx_Ip_apxControllerState[ControllerId];

    #if (SRX_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Receiver != NULL_PTR);
    #endif

    HwCtrlOffset = Receiver->ControllerHwOffset;

    ChannelClkCtr.CompPrescaler = 0;
    ChannelClkCtr.CompEnable = 1;
    ChannelClkCtr.RxPrescaler = 0;
    /* Enable controller */
    Srx_Ip_SetControllerEnable(HwCtrlOffset, FALSE);
    for (ChannelId = 0; ChannelId < SRX_CNL_COUNT; ChannelId++)
    {
        HwChnlOffset = Receiver->ChnlConfig[ChannelId].ChannelHwOffset;
        /* Disable channel */
        Srx_Ip_SetChannelEnable(HwCtrlOffset, HwChnlOffset, FALSE);
        /* Number of data nibbles supported for channel to 0 */
        Srx_Ip_SetDataController(HwCtrlOffset,HwChnlOffset, (uint32)2U);
        /* Clear status register for FMSG */
        Srx_Ip_ClearFastMsgReadyStatus(HwCtrlOffset, HwChnlOffset);
        /* Clear status register for SMSG */
        Srx_Ip_ClearSerialMsgReadyStatus(HwCtrlOffset, HwChnlOffset);

        /* Disable interrupt channel mode register */
        Srx_Ip_SetChannelMode(HwCtrlOffset, HwChnlOffset, Receiver->ControllerMode, FALSE);

        /* Receiver clock tick */
        Srx_Ip_SetChannelClockController(HwCtrlOffset, HwChnlOffset, &ChannelClkCtr);

        /* Reset to default values Channel Status Register*/
        Srx_Ip_ClearChannelStatus(HwCtrlOffset, HwChnlOffset, SRX_IP_CLEAR_ALL);

        /* Reset to default values Channel Config Register*/
        Srx_Ip_SetChannelConfig(HwCtrlOffset, HwChnlOffset, SRX_IP_POLLING, NULL_PTR);
        Srx_Ip_ChannelIdByOffset[HwCtrlOffset][HwChnlOffset] = SRX_IP_UNINIT;
    }

    Srx_Ip_apxControllerState[ControllerId] = NULL_PTR;
    Srx_Ip_ControllerIdByOffset[HwCtrlOffset] = SRX_IP_UNINIT;
}

/**
* @brief        Function that performs polling of Sent Fast and/or Serial Message on a channel.
* @details      This function performs polling of Fast and/or Serial Message on channel and notify for user by channel notification.
*
* @param        ControllerId        : The index of controller.
* @param        ChannelId           : The index of channel.
* @param        ReceivedMsgType     : The type of message should be received.
*
* @return       E_OK : Channel request has been accepted.
*               E_NOT_OK : Channel request has not been accepted.
* @implements Srx_Ip_GetChannelMsgData_Activity
*
*/
Srx_Ip_StatusType Srx_Ip_GetChannelMsgData
(
    uint8  ControllerId,
    uint8  ChannelId,
    Srx_Ip_ReceivedMsgType ReceivedMsgType
)
{
    uint32 TimeoutTicks = OsIf_MicrosToTicks(SRX_IP_TIMEOUT, SRX_IP_TIMEOUT_TYPE);
    uint32 CurrentTicks = OsIf_GetCounter(SRX_IP_TIMEOUT_TYPE); /* initialize current counter */
    uint32 ElapsedTicks = 0; /* elapsed will give timeout */
    Srx_Ip_StatusType eReturnType = SRX_IP_ERROR;
    /* Index of channel offset in controller */
    uint8 HwCtrlOffset = 0U;
    uint8 HwChnlOffset = 0U;
    /*Fast message*/
    static Srx_Ip_SerialMsgType SentSerialFrame;
    static Srx_Ip_FastMsgType SentFastFrame;
    #if (SRX_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(ControllerId < SRX_IP_INSTANCE_COUNT);
    #endif
    const Srx_Ip_ControllerStateType * Receiver = Srx_Ip_apxControllerState[ControllerId];

    #if (SRX_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Receiver != NULL_PTR);
    DevAssert(ChannelId < Receiver->NumberChnlConfigured);
    #endif

    HwCtrlOffset = Receiver->ControllerHwOffset;
    HwChnlOffset = Receiver->ChnlConfig[ChannelId].ChannelHwOffset;
    MCAL_DATA_SYNC_BARRIER();
    Srx_Ip_ClearChannelStatus(HwCtrlOffset, HwChnlOffset, SRX_IP_CLEAR_ALL);

    if ((SRX_IP_POLLING == Receiver->ControllerMode) && ((NULL_PTR != Receiver->FastFrameNotification) || (NULL_PTR != Receiver->SerialFrameNotification)))
    {
        while ((ElapsedTicks < TimeoutTicks) && Srx_Ip_GetChannelEnable(HwCtrlOffset, HwChnlOffset))
        {
            if (Srx_Ip_GetFastMsgReadyStatus(HwCtrlOffset, HwChnlOffset))
            {
                /*Data length*/
                SentFastFrame.Length = Receiver->ChnlConfig[ChannelId].ChannelDataLength;
                /*Process Sent message*/
                Srx_Ip_ProcessFastMsg(HwCtrlOffset, HwChnlOffset, &SentFastFrame, Receiver->FastClearingEnable);
                if ((ReceivedMsgType != SRX_IP_SERIAL_MSG_ONLY) && (NULL_PTR != Receiver->FastFrameNotification))
                {
                    Receiver->FastFrameNotification(ControllerId, ChannelId, &SentFastFrame);
                }
                eReturnType = SRX_IP_SUCCESS;
            }


            if (Srx_Ip_GetSerialMsgReadyStatus(HwCtrlOffset, HwChnlOffset))
            {
                Srx_Ip_ProcessSerialMsg(HwCtrlOffset, HwChnlOffset, &SentSerialFrame, Receiver->FastClearingEnable);
                if ((NULL_PTR != Receiver->SerialFrameNotification) && (ReceivedMsgType != SRX_IP_FAST_MSG_ONLY))
                {
                    Receiver->SerialFrameNotification(ControllerId, ChannelId, &SentSerialFrame);
                }
                eReturnType = (Srx_Ip_StatusType)SRX_IP_SUCCESS;
            }
            Srx_Ip_ProcessChannelError(HwCtrlOffset, HwChnlOffset, SRX_IP_POLLING);
            ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, SRX_IP_TIMEOUT_TYPE);
        }
    }

    return eReturnType;
}

static void Srx_Ip_PrepareGetCtrMsgVar
(
    uint8 ControllerId,
    Srx_Ip_ReceivedMsgType ReceivedMsgType,
    boolean * GetCondition
)
{
    /* Index of channel offset in controller */
    uint8 HwCtrlOffset = 0U;
    uint8 HwChnlOffset = 0U;
    Srx_Ip_ControllerStateType* Receiver = Srx_Ip_apxControllerState[ControllerId];
    HwCtrlOffset = Receiver->ControllerHwOffset;
    uint8 Index;

    Receiver->FastMsgReadyMask = 0U;
    Receiver->SerialMsgReadyMask = 0U;
    for (Index = 0; Index < (Receiver->NumberChnlConfigured); Index++)
    {
        HwChnlOffset = Receiver->ChnlConfig[Index].ChannelHwOffset;
        Srx_Ip_ClearChannelStatus(HwCtrlOffset, HwChnlOffset, SRX_IP_CLEAR_ALL);
        if (ReceivedMsgType != SRX_IP_SERIAL_MSG_ONLY)
        {
            Srx_Ip_ClearFastMsgReadyStatus(HwCtrlOffset, HwChnlOffset);
            Receiver->FastMsgReadyMask |= ((uint32)((uint32)(0x1U) << HwChnlOffset));
        }
        if (ReceivedMsgType != SRX_IP_FAST_MSG_ONLY)
        {
            Srx_Ip_ClearSerialMsgReadyStatus(HwCtrlOffset, HwChnlOffset);
            Receiver->SerialMsgReadyMask |= ((uint32)((uint32)(0x1U) << HwChnlOffset));
        }
    }
    if ((SRX_IP_POLLING == Receiver->ControllerMode) && ((NULL_PTR != Receiver->FastFrameNotification) || (NULL_PTR != Receiver->SerialFrameNotification)))
    {
        *GetCondition = TRUE;
    }
}


/**
* @brief        Function that performs polling of Sent Fast and/or Serial Message on all configured channel at a specific controller.
* @details      Function that performs polling of Sent Fast and/or Serial Message on all configured channel at a specific controller.
*
* @param        ControllerId        : The index of controller.
* @param        ReceivedMsgType     : The type of message should be received.
*
* @return      void
* @implements Srx_Ip_GetControllerMsgData_Activity
*
*/
void Srx_Ip_GetControllerMsgData
(
    uint8 ControllerId,
    Srx_Ip_ReceivedMsgType ReceivedMsgType
)
{
    uint32 TempFast = 0;
    uint32 TempSerial = 0;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(SRX_IP_TIMEOUT, SRX_IP_TIMEOUT_TYPE);
    uint32 CurrentTicks = OsIf_GetCounter(SRX_IP_TIMEOUT_TYPE); /* initialize current counter */
    uint32 ElapsedTicks = 0; /* elapsed will give timeout */
    boolean GetCondition = TRUE;
    /* Index of channel offset in controller */
    uint8 HwCtrlOffset = 0U;

    #if (SRX_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(ControllerId < SRX_IP_INSTANCE_COUNT);
    #endif
    const Srx_Ip_ControllerStateType* Receiver = Srx_Ip_apxControllerState[ControllerId];

    #if (SRX_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Receiver != NULL_PTR);
    #endif

    HwCtrlOffset = Receiver->ControllerHwOffset;
    Srx_Ip_PrepareGetCtrMsgVar(ControllerId, ReceivedMsgType, &GetCondition);


    while ((ElapsedTicks < TimeoutTicks) && (GetCondition) )
    {
        if (ReceivedMsgType != SRX_IP_SERIAL_MSG_ONLY)
        {
            TempFast = Srx_Ip_GetFastMsgReadyCtrlStatus(HwCtrlOffset);
            TempFast &= Receiver->FastMsgReadyMask;
        }
        Srx_Ip_ProcessIncomingFastMsg(ControllerId, &TempFast);

        if(ReceivedMsgType != SRX_IP_FAST_MSG_ONLY)
        {
            TempSerial = Srx_Ip_GetSerialMsgReadyCtrlStatus(HwCtrlOffset);
            TempSerial &= Receiver->SerialMsgReadyMask;
        }
        Srx_Ip_ProcessIncomingSerialMsg(ControllerId, &TempSerial);

        GetCondition = Srx_Ip_ExistEnabledChannels(ControllerId);

        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, SRX_IP_TIMEOUT_TYPE);

    }
    
}

/**
* @brief        This function shall enable a specific channel in order to start receiving from the bus.
* @brief        This function shall enable a specific channel in order to start receiving from the bus.
*
* @param        ControllerId        : The index of controller.
* @param        ChannelId           : The index of channel.
*
* @return       E_OK : Channel request has been accepted.
*               E_NOT_OK : Channel request has not been accepted.
* @implements Srx_Ip_StartChannelReceiving_Activity
*
*/
Srx_Ip_StatusType Srx_Ip_StartChannelReceiving
(
    uint8  ControllerId,
    uint8  ChannelId
)
{
    Srx_Ip_StatusType ReturnValue = SRX_IP_ERROR;

    #if (SRX_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(ControllerId < SRX_IP_INSTANCE_COUNT);
    #endif
    const Srx_Ip_ControllerStateType * Receiver = Srx_Ip_apxControllerState[ControllerId];

    #if (SRX_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Receiver != NULL_PTR);
    DevAssert(ChannelId < Receiver->NumberChnlConfigured);
    #endif
    /* Index of channel offset in controller */
    uint8 HwCtrlOffset = 0U;
    uint8 HwChnlOffset = 0U;
    /*Fast message*/
    static Srx_Ip_SerialMsgType SentSerialFrame;
    static Srx_Ip_FastMsgType SentFastFrame;
    HwCtrlOffset = Receiver->ControllerHwOffset;
    HwChnlOffset = Receiver->ChnlConfig[ChannelId].ChannelHwOffset;

    if (!Srx_Ip_GetChannelEnable(HwCtrlOffset, HwChnlOffset))
    {
        MCAL_DATA_SYNC_BARRIER();

        if (Srx_Ip_GetFastMsgReadyStatus(HwCtrlOffset, HwChnlOffset))
        {
            /*Data length*/
            SentFastFrame.Length = Receiver->ChnlConfig[ChannelId].ChannelDataLength;
            /*Process Sent message*/
            Srx_Ip_ProcessFastMsg(HwCtrlOffset, HwChnlOffset, &SentFastFrame, Receiver->FastClearingEnable);
        }

        if (Srx_Ip_GetSerialMsgReadyStatus(HwCtrlOffset, HwChnlOffset))
        {
            Srx_Ip_ProcessSerialMsg(HwCtrlOffset, HwChnlOffset, &SentSerialFrame, Receiver->FastClearingEnable);
        }
        Srx_Ip_ClearChannelStatus(HwCtrlOffset, HwChnlOffset, SRX_IP_CLEAR_ALL);

        Srx_Ip_SetChannelEnable(HwCtrlOffset, HwChnlOffset, TRUE);
        ReturnValue = SRX_IP_SUCCESS;
    }

    return ReturnValue;
}

/**
* @brief        This function shall disable a specific channel in order to stop receiving from the bus.
* @brief        This function shall disable a specific channel in order to stop receiving from the bus.
*
* @param        ControllerId        : The index of controller.
* @param        ChannelId           : The index of channel.
*
* @return       E_OK : Channel request has been accepted.
*               E_NOT_OK : Channel request has not been accepted.
* @implements Srx_Ip_StopChannelReceiving_Activity
*
*/
Srx_Ip_StatusType Srx_Ip_StopChannelReceiving
(
    uint8  ControllerId,
    uint8  ChannelId
)
{
    Srx_Ip_StatusType ReturnValue = SRX_IP_ERROR;
    /* Index of channel offset in controller */
    uint8 HwCtrlOffset = 0U;
    uint8 HwChnlOffset = 0U;
    static Srx_Ip_SerialMsgType SentSerialFrame;
    static Srx_Ip_FastMsgType SentFastFrame;
    #if (SRX_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(ControllerId < SRX_IP_INSTANCE_COUNT);
    #endif
    const Srx_Ip_ControllerStateType * Receiver = Srx_Ip_apxControllerState[ControllerId];

    #if (SRX_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Receiver != NULL_PTR);
    DevAssert(ChannelId < Receiver->NumberChnlConfigured);
    #endif
    HwCtrlOffset = Receiver->ControllerHwOffset;
    HwChnlOffset = Receiver->ChnlConfig[ChannelId].ChannelHwOffset;

    if (Srx_Ip_GetChannelEnable(HwCtrlOffset, HwChnlOffset))
    {
        MCAL_DATA_SYNC_BARRIER();
        Srx_Ip_SetChannelEnable(HwCtrlOffset, HwChnlOffset, FALSE);
        if (Srx_Ip_GetFastMsgReadyStatus(HwCtrlOffset, HwChnlOffset))
        {
            /*Data length*/
            SentFastFrame.Length = Receiver->ChnlConfig[ChannelId].ChannelDataLength;
            /*Process Sent message*/
            Srx_Ip_ProcessFastMsg(HwCtrlOffset, HwChnlOffset, &SentFastFrame, Receiver->FastClearingEnable);
        }

        if (Srx_Ip_GetSerialMsgReadyStatus(HwCtrlOffset, HwChnlOffset))
        {
            Srx_Ip_ProcessSerialMsg(HwCtrlOffset, HwChnlOffset, &SentSerialFrame, Receiver->FastClearingEnable);
        }
        Srx_Ip_ClearChannelStatus(HwCtrlOffset, HwChnlOffset, SRX_IP_CLEAR_ALL);
        ReturnValue = SRX_IP_SUCCESS;
    }

    return ReturnValue;
}

#if (SRX_IP_INTERRUPT_COMBINED == STD_ON)
/**
* @brief       Interrupt handler for fast and serial msg in case using combined interrupt on interrupt mode.
* @brief        Interrupt handler for fast and serial msg in case using combined interrupt on interrupt mode.
*
* @param        HwCtrlOffset:       The offset of controller.
* @param        ReceivedMsgType:    The type of message should be received.
*
* @return       void
* @implements Srx_Ip_ProcessMsgCombinedInterrupt_Activity
*
*/
void Srx_Ip_ProcessMsgCombinedInterrupt
(
    uint8 HwCtrlOffset,
    Srx_Ip_ReceivedMsgType ReceivedMsgType
)
{
    uint32 TempFast = 0;
    uint32 TempSerial = 0;
    /* Index of controller in configuration */
    uint8 ControllerId = Srx_Ip_ControllerIdByOffset[HwCtrlOffset];
    const Srx_Ip_ControllerStateType* Receiver;

#ifdef MCAL_ENABLE_FAULT_INJECTION
    /* Error injection point to check in case calling interrupt handler when driver is UINIT */
    MCAL_FAULT_INJECTION_POINT(SENT_FIP_1_CHANGE_SRX_IP_UNINIT);
#endif
    SchM_Enter_Sent_SENT_EXCLUSIVE_AREA_00();
    if (SRX_IP_UNINIT != ControllerId)
    {
        Receiver = Srx_Ip_apxControllerState[ControllerId];
        if (ReceivedMsgType == SRX_IP_FAST_MSG_ONLY)
        {
            TempFast = Srx_Ip_GetFastMsgReadyCtrlStatus(HwCtrlOffset);
            TempFast &= Srx_Ip_GetFastMsgReadyCtrlInt(HwCtrlOffset);
            TempFast &= Receiver->FastMsgReadyMask;
        }
        if (ReceivedMsgType == SRX_IP_SERIAL_MSG_ONLY)
        {
            TempSerial = Srx_Ip_GetSerialMsgReadyCtrlInt(HwCtrlOffset);
            TempSerial &= Srx_Ip_GetSerialMsgReadyCtrlStatus(HwCtrlOffset);
            TempSerial &= Receiver->SerialMsgReadyMask;
        }
        if (SRX_IP_INTERRUPT == Receiver->ControllerMode)
        {
            Srx_Ip_ProcessIncomingFastMsg(ControllerId, &TempFast);

            Srx_Ip_ProcessIncomingSerialMsg(ControllerId, &TempSerial);
        }
    }
    else
    {
        Srx_Ip_ClearCtrlFastMsgReadyStatus(HwCtrlOffset);
        Srx_Ip_ClearCtrlSerialMsgReadyStatus(HwCtrlOffset);
    }
    SchM_Exit_Sent_SENT_EXCLUSIVE_AREA_00();
}

/**
* @brief       Error handler for fast and serial incase using combined interrupt on interrupt mode.
* @brief       Error handler for fast and serial incase using combined interrupt on interrupt mode.
*
* @param        HwCtrlOffset:       The offset of controller.
*
* @return       void
* @implements Srx_Ip_ProcessErrorCombinedInterrupt_Activity
*
*/
void Srx_Ip_ProcessErrorCombinedInterrupt
(
    uint8 HwCtrlOffset
)
{
    uint8 Index;
    /* Index of controller in configuration */
    uint8 ControllerId = Srx_Ip_ControllerIdByOffset[HwCtrlOffset];
    uint8 HwChnlOffset = 0U;
    const Srx_Ip_ControllerStateType* Receiver;

    if (SRX_IP_UNINIT != ControllerId)
    {
        Receiver = Srx_Ip_apxControllerState[ControllerId];
        if (SRX_IP_INTERRUPT == Receiver->ControllerMode)
        {
            for (Index = 0; Index < (Receiver->NumberChnlConfigured) ; Index++)
            {
                HwChnlOffset = Receiver->ChnlConfig[Index].ChannelHwOffset;
                if (Srx_Ip_GetChannelEnable(HwCtrlOffset, HwChnlOffset))
                {
                    Srx_Ip_ProcessChannelError(HwCtrlOffset, HwChnlOffset, SRX_IP_INTERRUPT);
                }
            }
        }
    }
    else
    {
        for (HwChnlOffset = 0; HwChnlOffset < 8U ; HwChnlOffset++)
        {
            Srx_Ip_ClearChannelStatus(HwCtrlOffset, HwChnlOffset, SRX_IP_CLEAR_ALL);
        }
    }
}
#else
/**
* @brief       Process fast and serial msg interrupt in case using separated interrupt.
* @brief       Process fast and serial msg interrupt in case using separated interrupt.
*
* @param        HwCtrlOffset:       The offset of controller.
* @param        HwChnlOffset:       The offset of channel.
* @param        ReceivedMsgType:    The type of message should be received.
*
* @return       void
* @implements Srx_Ip_ProcessMsgChannelInterrupt_Activity
*
*/
void Srx_Ip_ProcessMsgChannelInterrupt
(
    uint8 HwCtrlOffset,
    uint8 HwChnlOffset,
    Srx_Ip_ReceivedMsgType ReceivedMsgType
)
{
    /* Index of controller and channel in configuration */
    uint8 ControllerId = Srx_Ip_ControllerIdByOffset[HwCtrlOffset];
    uint8 ChannelId = Srx_Ip_ChannelIdByOffset[HwCtrlOffset][HwChnlOffset];
    /*Fast message*/
    static Srx_Ip_SerialMsgType SentSerialFrame;
    static Srx_Ip_FastMsgType SentFastFrame;
    const Srx_Ip_ControllerStateType * Receiver;

    SchM_Enter_Sent_SENT_EXCLUSIVE_AREA_00();
    if ((SRX_IP_UNINIT != ControllerId) && (SRX_IP_UNINIT != ChannelId))
    {
        Receiver = Srx_Ip_apxControllerState[ControllerId];
        if (SRX_IP_INTERRUPT == Receiver->ControllerMode)
        {
            if (Srx_Ip_GetFastMsgReadyStatus(HwCtrlOffset, HwChnlOffset) && Srx_Ip_GetFastMsgReadyChannelInt(HwCtrlOffset, HwChnlOffset) && (ReceivedMsgType != SRX_IP_SERIAL_MSG_ONLY))
            {
                /*Data length*/
                SentFastFrame.Length = Receiver->ChnlConfig[ChannelId].ChannelDataLength;
                /*Process Sent message*/
                Srx_Ip_ProcessFastMsg(HwCtrlOffset, HwChnlOffset, &SentFastFrame, Receiver->FastClearingEnable);
                if (NULL_PTR != Receiver->FastFrameNotification)
                {
                    Receiver->FastFrameNotification(ControllerId, ChannelId, &SentFastFrame);
                }
            }

            if (Srx_Ip_GetSerialMsgReadyStatus(HwCtrlOffset, HwChnlOffset) && Srx_Ip_GetSerialMsgReadyChannelInt(HwCtrlOffset, HwChnlOffset) && (ReceivedMsgType != SRX_IP_FAST_MSG_ONLY))
            {
                Srx_Ip_ProcessSerialMsg(HwCtrlOffset, HwChnlOffset, &SentSerialFrame, Receiver->FastClearingEnable);
                if (NULL_PTR != Receiver->SerialFrameNotification)
                {
                    Receiver->SerialFrameNotification(ControllerId, ChannelId, &SentSerialFrame);
                }
            }
        }
    }
    else
    {
        Srx_Ip_ClearFastMsgReadyStatus(HwCtrlOffset, HwChnlOffset);
        Srx_Ip_ClearSerialMsgReadyStatus(HwCtrlOffset, HwChnlOffset);
    }
    SchM_Exit_Sent_SENT_EXCLUSIVE_AREA_00();
}

#endif
static boolean Srx_Ip_CheckChannelStatus(uint32 RegValue, Srx_Ip_ChannelStatusType Status)
{
    boolean RetVal = FALSE;
    uint32 TempVal;

    switch (Status)
    {
        case SRX_IP_BUS_IDLE:
            TempVal = (RegValue & SRX_CH_STATUS_BUS_IDLE(1)) >> SRX_CH_STATUS_BUS_IDLE_SHIFT;
        break;
        case SRX_IP_CAL_RESYNC:
            TempVal = (RegValue & SRX_CH_STATUS_CAL_RESYNC(1)) >> SRX_CH_STATUS_CAL_RESYNC_SHIFT;
        break;
        case SRX_IP_CAL_20_25:
            TempVal = (RegValue & SRX_CH_STATUS_CAL_20_25(1)) >> SRX_CH_STATUS_CAL_20_25_SHIFT;
        break;
        case SRX_IP_SMSG_OFLW:
            TempVal = (RegValue & SRX_CH_STATUS_SMSG_OFLW(1)) >> SRX_CH_STATUS_SMSG_OFLW_SHIFT;
        break;
        case SRX_IP_FMSG_OFLW:
            TempVal = (RegValue & SRX_CH_STATUS_FMSG_OFLW(1)) >> SRX_CH_STATUS_FMSG_OFLW_SHIFT;
        break;
        case SRX_IP_NIB_VAL_ERR_LOW:
            TempVal = (RegValue & SRX_CH_STATUS_NIB_VAL_ERR_LOW(1)) >> SRX_CH_STATUS_NIB_VAL_ERR_LOW_SHIFT;
        break;
        case SRX_IP_PP_DIAG_ERR:
            TempVal = (RegValue & SRX_CH_STATUS_PP_DIAG_ERR(1)) >> SRX_CH_STATUS_PP_DIAG_ERR_SHIFT;
        break;
        case SRX_IP_CAL_LEN_ERR:
            TempVal = (RegValue & SRX_CH_STATUS_CAL_LEN_ERR(1)) >> SRX_CH_STATUS_CAL_LEN_ERR_SHIFT;
        break;
        case SRX_IP_CAL_DIAG_ERR:
            TempVal = (RegValue & SRX_CH_STATUS_CAL_DIAG_ERR(1)) >> SRX_CH_STATUS_CAL_DIAG_ERR_SHIFT;
        break;
        case SRX_IP_NIB_VAL_ERR_HIGH:
            TempVal = (RegValue & SRX_CH_STATUS_NIB_VAL_ERR_HIGH(1)) >> SRX_CH_STATUS_NIB_VAL_ERR_HIGH_SHIFT;
        break;
        case SRX_IP_SMSG_CRC_ERR:
            TempVal = (RegValue & SRX_CH_STATUS_SMSG_CRC_ERR(1)) >> SRX_CH_STATUS_SMSG_CRC_ERR_SHIFT;
        break;
        case SRX_IP_FMSG_CRC_ERR:
            TempVal = (RegValue & SRX_CH_STATUS_FMSG_CRC_ERR(1)) >> SRX_CH_STATUS_FMSG_CRC_ERR_SHIFT;
        break;
        case SRX_IP_NUM_EDGES_ERR:
            TempVal = (RegValue & SRX_CH_STATUS_NUM_EDGES_ERR(1)) >> SRX_CH_STATUS_NUM_EDGES_ERR_SHIFT;
        break;
        default:
            TempVal = 0x00U;
        /* default statements */
        break;
    }

    if ((TempVal & 0x1U) == 0x1U)
    {
        RetVal = TRUE;
    }
    else
    {
        RetVal = FALSE;
    }

    return RetVal;
}

/**
*   @brief        Function used to process the incoming fast messages.
*/
static void Srx_Ip_ProcessIncomingFastMsg(uint8 ControllerId, uint32 * TempFast)
{   
    uint8 Index = 0; 
    uint8 HwCtrlOffset = 0U;
    uint8 HwChnlOffset = 0U;
    static Srx_Ip_FastMsgType SentFastFrame;

    #if (SRX_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(ControllerId < SRX_IP_INSTANCE_COUNT);
    #endif

    const Srx_Ip_ControllerStateType* Receiver = Srx_Ip_apxControllerState[ControllerId];

    #if (SRX_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Receiver != NULL_PTR);
    #endif

    HwCtrlOffset = Receiver->ControllerHwOffset;


    if (*TempFast != 0U)
    {
        for (Index = 0U; Index < (Receiver->NumberChnlConfigured); Index++)
        {
            HwChnlOffset = Receiver->ChnlConfig[Index].ChannelHwOffset;
            if (Srx_Ip_GetChannelEnable(HwCtrlOffset, HwChnlOffset) && ((*TempFast & ((uint32)((uint32)(0x1U) << Receiver->ChnlConfig[Index].ChannelHwOffset))) != 0U))
            {
                /*Data length*/
                SentFastFrame.Length = Receiver->ChnlConfig[Index].ChannelDataLength;
                /*Process Sent message*/
                Srx_Ip_ProcessFastMsg(HwCtrlOffset, Receiver->ChnlConfig[Index].ChannelHwOffset, &SentFastFrame, Receiver->FastClearingEnable);
                if (NULL_PTR != Receiver->FastFrameNotification)
                {
                    Receiver->FastFrameNotification(ControllerId, Index, &SentFastFrame);
                }
                *TempFast &= ~((uint32)((uint32)(0x1U) << Receiver->ChnlConfig[Index].ChannelHwOffset));
            }
            if (0U == *TempFast)
            {
                break;
            }
        }
    }
}
/**
*   @brief        Function used to process the incoming serial messages.
*/
static void Srx_Ip_ProcessIncomingSerialMsg(uint8 ControllerId, uint32 * TempSerial)
{
    uint8 Index = 0; 
    uint8 HwCtrlOffset = 0U;
    uint8 HwChnlOffset = 0U;
    static Srx_Ip_SerialMsgType SentSerialFrame;

    #if (SRX_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(ControllerId < SRX_IP_INSTANCE_COUNT);
    #endif

    const Srx_Ip_ControllerStateType* Receiver = Srx_Ip_apxControllerState[ControllerId];

    #if (SRX_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Receiver != NULL_PTR);
    #endif

    HwCtrlOffset = Receiver->ControllerHwOffset;
    
    if (*TempSerial != 0U)
    {
        for (Index = 0U; Index < (Receiver->NumberChnlConfigured); Index++)
        {
            HwChnlOffset = Receiver->ChnlConfig[Index].ChannelHwOffset;
            if (Srx_Ip_GetChannelEnable(HwCtrlOffset, HwChnlOffset) && (((*TempSerial) & ((uint32)((uint32)(0x1U) << Receiver->ChnlConfig[Index].ChannelHwOffset))) != 0U))
            {   /*Process Sent message*/
                Srx_Ip_ProcessSerialMsg(HwCtrlOffset, Receiver->ChnlConfig[Index].ChannelHwOffset, &SentSerialFrame, Receiver->FastClearingEnable);
                if (NULL_PTR != Receiver->SerialFrameNotification)
                {
                    Receiver->SerialFrameNotification(ControllerId, Index, &SentSerialFrame);
                }
                (*TempSerial) &= ~((uint32)(((uint32)0x1U) << Receiver->ChnlConfig[Index].ChannelHwOffset));
            }
            if (0U == *TempSerial)
            {
                break;
            }
        }
    }

}

/**
*   @brief        Function used to check if there are enabled channels.
*/
static boolean Srx_Ip_ExistEnabledChannels(uint8 ControllerId)
{
    boolean returnValue=FALSE;
    uint8 Index = 0; 
    uint8 HwCtrlOffset = 0U;
    uint8 HwChnlOffset = 0U;

    #if (SRX_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(ControllerId < SRX_IP_INSTANCE_COUNT);
    #endif

    const Srx_Ip_ControllerStateType* Receiver = Srx_Ip_apxControllerState[ControllerId];

    #if (SRX_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Receiver != NULL_PTR);
    #endif

    HwCtrlOffset = Receiver->ControllerHwOffset;

    for (Index = 0; Index < (Receiver->NumberChnlConfigured); Index++)
    {
        Srx_Ip_ProcessChannelError(HwCtrlOffset, HwChnlOffset, SRX_IP_POLLING);
        HwChnlOffset = Receiver->ChnlConfig[Index].ChannelHwOffset;
        /*Check if there are enabled channels*/
        if (Srx_Ip_GetChannelEnable(HwCtrlOffset, HwChnlOffset))
        {
            returnValue=TRUE;
            break;
        }
    }

    return returnValue;
}

/**
*   @brief        Function used to verify if there are errors present in the ChannelStatus register.
*/
static void Srx_Ip_VerifyChannelStatus(uint8 ControllerId, uint8 ChannelId, uint32 ChannelStatusReg)
{
    const Srx_Ip_ChannelStatusType ErrorArray[13] = {SRX_IP_BUS_IDLE,
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
                                                     SRX_IP_NUM_EDGES_ERR};
    uint8 ErrorIndex;
    const Srx_Ip_ControllerStateType * Receiver = Srx_Ip_apxControllerState[ControllerId];

    for (ErrorIndex = 0; ErrorIndex < 13U ; ErrorIndex++)
    {   /*Check which error is present in ChannelStatus register*/
        if (Srx_Ip_CheckChannelStatus(ChannelStatusReg, ErrorArray[ErrorIndex]))
        {
            if (SRX_IP_SMSG_CRC_ERR == ErrorArray[ErrorIndex])
            {
                if (NULL_PTR != Receiver->SerialErrorNotification)
                {
                    Receiver->SerialErrorNotification(ControllerId, ChannelId, ErrorArray[ErrorIndex]);
                }
            }
            else
            {
                if (NULL_PTR != Receiver->FastErrorNotification)
                {
                    Receiver->FastErrorNotification(ControllerId, ChannelId, ErrorArray[ErrorIndex]);
                }
            }
        }
    }
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
