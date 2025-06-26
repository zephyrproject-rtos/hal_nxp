/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file    Srx_Ip_HwAccess.h
*   @version 2.0.1
*
*   @brief   AUTOSAR Sent - Low level header of Sent driver.
*   @details This file contains declarations of the functions defined by AutoSAR.
*
*   @addtogroup SRX_IP_DRIVER
*   @{
*/

#ifndef SRX_IP_HWACCESS_H
#define SRX_IP_HWACCESS_H
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Srx_Ip_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SRX_IP_HWACCESS_VENDOR_ID                      43
#define SRX_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION       4
#define SRX_IP_HWACCESS_AR_RELEASE_MINOR_VERSION       7
#define SRX_IP_HWACCESS_AR_RELEASE_REVISION_VERSION    0
#define SRX_IP_HWACCESS_SW_MAJOR_VERSION               2
#define SRX_IP_HWACCESS_SW_MINOR_VERSION               0
#define SRX_IP_HWACCESS_SW_PATCH_VERSION               1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Srx_Ip_Cfg header file are of the same vendor */
#if (SRX_IP_HWACCESS_VENDOR_ID != SRX_IP_CFG_VENDOR_ID)
    #error "Srx_Ip_HwAccess.h and Srx_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Srx_Ip_Cfg header file are of the same Autosar version */
#if ((SRX_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION    != SRX_IP_CFG_AR_RELEASE_MAJOR_VERSION) ||    \
     (SRX_IP_HWACCESS_AR_RELEASE_MINOR_VERSION    != SRX_IP_CFG_AR_RELEASE_MINOR_VERSION) ||    \
     (SRX_IP_HWACCESS_AR_RELEASE_REVISION_VERSION != SRX_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Srx_Ip_HwAccess.h and Srx_Ip_Cfg.h are different"
#endif
/* Check if current file and Srx_Ip_Cfg header file are of the same Software version */
#if ((SRX_IP_HWACCESS_SW_MAJOR_VERSION != SRX_IP_CFG_SW_MAJOR_VERSION) || \
     (SRX_IP_HWACCESS_SW_MINOR_VERSION != SRX_IP_CFG_SW_MINOR_VERSION) || \
     (SRX_IP_HWACCESS_SW_PATCH_VERSION != SRX_IP_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Srx_Ip_HwAccess.h and Srx_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* Function-like Macro for casting boolean to uint32. */
#define SRX_IP_BOOL_TO_UINT32(x) (uint32)(x?1U:0U)
/* Reset value of CHn_STATUS Register. */
#define SRX_IP_CH_STATUS_RESET_VALUE_U32 ((uint32)(0x8FFF0000U))

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define SENT_START_SEC_CONST_UNSPECIFIED
#include "Sent_MemMap.h"
/* Table of base addresses for Srx instances. */
static SRX_Type * const Srx_Ip_apxBase[SRX_INSTANCE_COUNT] = IP_SRX_BASE_PTRS;

#define SENT_STOP_SEC_CONST_UNSPECIFIED
#include "Sent_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"

/*
 *
 */
LOCAL_INLINE void Srx_Ip_SetChannelConfig(uint8 Instance, uint8 Channel, Srx_Ip_ReceivedMode Mode, const Srx_Ip_ChannelConfigRegType* ChannelConfigReg)
{
    SRX_Type* BaseAdress;
    uint32 Temp = 0;
    BaseAdress = Srx_Ip_apxBase[Instance];
    if (SRX_IP_POLLING != Mode)
    {
        Temp = 1;
    }
    if (NULL_PTR != ChannelConfigReg)
    {
        BaseAdress->CNL[Channel].CH_CONFIG = SRX_CH_CONFIG_IE_CAL_RESYNC(Temp) |
                                              SRX_CH_CONFIG_IE_CAL_20_25(Temp) |
                                              SRX_CH_CONFIG_IE_SMSG_OFLW(Temp) |
                                              SRX_CH_CONFIG_IE_FMSG_OFLW(Temp) |
                                              SRX_CH_CONFIG_IE_PP_DIAG_ERR(Temp) |
                                              SRX_CH_CONFIG_IE_CAL_LEN_ERR(Temp) |
                                              SRX_CH_CONFIG_IE_CAL_DIAG_ERR(Temp) |
                                              SRX_CH_CONFIG_IE_NIB_VAL_ERR(Temp) |
                                              SRX_CH_CONFIG_IE_SMSG_CRC_ERR(Temp) |
                                              SRX_CH_CONFIG_IE_FMSG_CRC_ERR(Temp) |
                                              SRX_CH_CONFIG_IE_NUM_EDGES_ERR(Temp) |
                                              SRX_CH_CONFIG_DCHNG_INT(SRX_IP_BOOL_TO_UINT32(ChannelConfigReg->IgnoreSameFrame)) |
                                              SRX_CH_CONFIG_SUCC_CAL_CHK(ChannelConfigReg->SuccessiveCalibCheck) |
                                              SRX_CH_CONFIG_PAUSE_EN(ChannelConfigReg->PausePulseEn) |
                                              SRX_CH_CONFIG_SCRC_TYPE(ChannelConfigReg->SlowCrcType) |
                                              SRX_CH_CONFIG_FCRC_SC_EN(SRX_IP_BOOL_TO_UINT32(ChannelConfigReg->CrcStatusNibbleIncluding)) |
                                              SRX_CH_CONFIG_FCRC_CHK_OFF(SRX_IP_BOOL_TO_UINT32(ChannelConfigReg->FastCrcCheckOff)) |
                                              SRX_CH_CONFIG_FCRC_TYPE(ChannelConfigReg->FastCrcType) |
                                              SRX_CH_CONFIG_FIL_CNT(4) |
                                              SRX_CH_CONFIG_CAL_RNG(ChannelConfigReg->SentValidCalibrationPulse)|
                                              SRX_CH_CONFIG_BUS_IDLE_CNT(ChannelConfigReg->BusTimeout);
    }
    else
    {
        BaseAdress->CNL[Channel].CH_CONFIG = (uint32)(0x104U);
    }
}


/*
 *
 */
LOCAL_INLINE void Srx_Ip_SetChannelClockController(uint8 Instance, uint8 Channel, const Srx_Ip_ChannelClkCtrType* ChannelClkCtr)
{
    SRX_Type* BaseAdress;

    BaseAdress = Srx_Ip_apxBase[Instance];
    BaseAdress->CNL[Channel].CH_CLK_CTRL = SRX_CH_CLK_CTRL_PRSC(ChannelClkCtr->RxPrescaler);
    BaseAdress->CNL[Channel].CH_CLK_CTRL|= SRX_CH_CLK_CTRL_COMP_EN(ChannelClkCtr->CompEnable);
}

/*
 *
 */
LOCAL_INLINE void Srx_Ip_SetDataController(uint8 Instance, uint8 Channel, uint32 NumberOfNibble)
{
    SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];
    uint32 RegValue = BaseAdress->DATA_CTRL1;
    uint8 TempShift = (uint8)(4U * (7U - Channel));

    RegValue &= (~((uint32)(((uint32)7U) << TempShift)));
    RegValue |= (uint32)(((uint32)(NumberOfNibble - 1U)) << TempShift);
    BaseAdress->DATA_CTRL1 = RegValue;
}

/*
 *
 */
LOCAL_INLINE void Srx_Ip_SetChannelMode(uint8 Instance, uint8 Channel, Srx_Ip_ReceivedMode Mode, boolean Enable)
{
    SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];

    uint32 RegValue0;
    uint32 RegValue1;

    if (SRX_IP_INTERRUPT == Mode)
    {
        RegValue0 = BaseAdress->FMSG_RDY_IE;
        if (Enable)
        {
            RegValue0 |= (uint32)(((uint32)(1U)) << Channel);
        }
        else
        {
            RegValue0 &= (uint32)(~(((uint32)(1U)) << Channel));
        }
        BaseAdress->FMSG_RDY_IE = (uint32)RegValue0;

        RegValue1 = BaseAdress->SMSG_RDY_IE;
        if (Enable)
        {
            RegValue1 |= (uint32)(((uint32)(1U)) << Channel);
        }
        else
        {
            RegValue1 &= (uint32)(~(((uint32)(1U)) << Channel));
        }
        BaseAdress->SMSG_RDY_IE = (uint32)RegValue1;
    }
#if (SRX_IP_DMA_FEATURE_ENABLE == STD_ON)
    if (SRX_IP_DMA == Mode)
    {
        RegValue0 = BaseAdress->FDMA_CTRL;
        if (Enable)
        {
            RegValue0 |= (uint32)(((uint32)(1U)) << Channel);
        }
        else
        {
            RegValue0 &= (uint32)(~(((uint32)(1U)) << Channel));
        }
        BaseAdress->FDMA_CTRL = (uint32)RegValue0;

        RegValue1 = BaseAdress->SDMA_CTRL;
        if (Enable)
        {
            RegValue1 |= (uint32)(((uint32)(1U)) << Channel);
        }
        else
        {
            RegValue1 &= (uint32)(~(((uint32)(1U)) << Channel));
        }
        BaseAdress->SDMA_CTRL = (uint32)RegValue1;
    }
#endif /* (SRX_IP_DMA_FEATURE_ENABLE == STD_ON) */
    if (SRX_IP_POLLING == Mode)
    {
        (void)Enable;
        (void)Channel;
        (void)Channel;
        /* Do nothing */
    }
}

/*
 *
 */
LOCAL_INLINE void Srx_Ip_SetChannelEnable(uint8 Instance, uint8 Channel, boolean Enable)
{
    SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];
    uint32 RegValue = (uint32)BaseAdress->CHNL_EN;

    if (Enable)
    {
        RegValue |= (uint32)(((uint32)(1U)) << Channel);
    }
    else
    {
        RegValue &= (uint32)(~(((uint32)(1U)) << Channel));
    }
    BaseAdress->CHNL_EN = (uint32)RegValue;
}

/*
 *
 */
LOCAL_INLINE boolean Srx_Ip_GetChannelEnable(uint8 Instance, uint8 Channel)
{
    const SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];
    uint32 RegValue = (uint32)BaseAdress->CHNL_EN;
    boolean RetVal;

    if (((uint8)((uint8)RegValue & (1U << Channel))) == (1U << Channel))
    {
        RetVal = TRUE;
    }
    else
    {
        RetVal = FALSE;
    }

    return RetVal;
}

/*
 *
 */
LOCAL_INLINE void Srx_Ip_SetControllerEnable(uint8 Instance, boolean Enable)
{
    SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];
    uint32 RegValue = (uint32)BaseAdress->GBL_CTRL;

    if (Enable)
    {
        RegValue |= SRX_GBL_CTRL_SENT_EN(1);
    }
    else
    {
        RegValue &= ~SRX_GBL_CTRL_SENT_EN(1);
    }
    BaseAdress->GBL_CTRL = (uint32)RegValue;
}

/*
 *
 */
LOCAL_INLINE void Srx_Ip_SetControllerFifoWaterMask(uint8 Instance, uint8 FifoLevel)
{
    SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];
    uint32 RegValue = (uint32)BaseAdress->GBL_CTRL;

    RegValue &= (~SRX_GBL_CTRL_FIFOWM_MASK);
    RegValue |= SRX_GBL_CTRL_FIFOWM(FifoLevel);

    BaseAdress->GBL_CTRL = (uint32)RegValue;
}

/*
 *
 */
LOCAL_INLINE void Srx_Ip_SetTimestampPrescaler(uint8 Instance, uint8 TimestampPrescaler)
{
    SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];
    uint32 RegValue = (uint32)BaseAdress->GBL_CTRL;

    RegValue &= (~SRX_GBL_CTRL_TSPRSC_MASK);
    RegValue |= SRX_GBL_CTRL_TSPRSC(TimestampPrescaler);

    BaseAdress->GBL_CTRL = (uint32)RegValue;
}

/*
 *
 */
LOCAL_INLINE void Srx_Ip_SetFIFOChannelEnable(uint8 Instance, uint8 Channel)
{
    SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];

    BaseAdress->CHNL_FIFO_EN |= (uint32)(((uint32)(1U)) << Channel);
}

/*
 *
 */
LOCAL_INLINE void Srx_Ip_ClearFastMsgReadyStatus(uint8 Instance, uint8 Channel)
{
    SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];

    BaseAdress->FMSG_RDY = (uint32)(((uint32)(1U)) << Channel);
}
/*
 *
 */
LOCAL_INLINE void Srx_Ip_ClearSerialMsgReadyStatus(uint8 Instance, uint8 Channel)
{
    SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];

    BaseAdress->SMSG_RDY = (uint32)(((uint32)(1U)) << Channel);
}
/*
 *
 */
LOCAL_INLINE void Srx_Ip_ClearCtrlFastMsgReadyStatus(uint8 Instance)
{
    SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];

    BaseAdress->FMSG_RDY = (uint32)(0xFFU);
}
/*
 *
 */
LOCAL_INLINE void Srx_Ip_ClearCtrlSerialMsgReadyStatus(uint8 Instance)
{
    SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];

    BaseAdress->SMSG_RDY = (uint32)(0xFFU);
}

/*
 *
 */
LOCAL_INLINE uint32 Srx_Ip_GetFastMsgReadyCtrlStatus(uint8 Instance)
{
    const SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];
    uint32 RegValue;

    RegValue = BaseAdress->FMSG_RDY;

    return RegValue;
}
/*
 *
 */
LOCAL_INLINE uint32 Srx_Ip_GetSerialMsgReadyCtrlStatus(uint8 Instance)
{
    const SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];
    uint32 RegValue;

    RegValue = BaseAdress->SMSG_RDY;

    return RegValue;
}
/*
 *
 */
LOCAL_INLINE boolean Srx_Ip_GetFastMsgReadyStatus(uint8 Instance, uint8 Channel)
{
    const SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];
    uint32 RegValue;

    RegValue = BaseAdress->FMSG_RDY;

    return ((((RegValue >> Channel) & 0x1U) == 0x1U)?TRUE:FALSE);
}
/*
 *
 */
LOCAL_INLINE boolean Srx_Ip_GetSerialMsgReadyStatus(uint8 Instance, uint8 Channel)
{
    const SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];
    uint32 RegValue;

    RegValue = BaseAdress->SMSG_RDY;

    return ((((RegValue >> Channel) & 0x1U) == 0x1U)?TRUE:FALSE);
}

/*
 *
 */
LOCAL_INLINE void Srx_Ip_ClearChannelStatus(uint8 Instance, uint8 Channel, Srx_Ip_ChannelStatusType Status)
{
    SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];

    switch (Status)
    {
        case SRX_IP_BUS_IDLE:
            BaseAdress->CNL[Channel].CH_STATUS = SRX_CH_STATUS_BUS_IDLE(1);
        break;
        case SRX_IP_CAL_RESYNC:
            BaseAdress->CNL[Channel].CH_STATUS = SRX_CH_STATUS_CAL_RESYNC(1);
        break;
        case SRX_IP_CAL_20_25:
            BaseAdress->CNL[Channel].CH_STATUS = SRX_CH_STATUS_CAL_20_25(1);
        break;
        case SRX_IP_SMSG_OFLW:
            BaseAdress->CNL[Channel].CH_STATUS = SRX_CH_STATUS_SMSG_OFLW(1);
        break;
        case SRX_IP_FMSG_OFLW:
            BaseAdress->CNL[Channel].CH_STATUS = SRX_CH_STATUS_FMSG_OFLW(1);
        break;
        case SRX_IP_NIB_VAL_ERR_LOW:
            BaseAdress->CNL[Channel].CH_STATUS = SRX_CH_STATUS_NIB_VAL_ERR_LOW(1);
        break;
        case SRX_IP_PP_DIAG_ERR:
            BaseAdress->CNL[Channel].CH_STATUS = SRX_CH_STATUS_PP_DIAG_ERR(1);
        break;
        case SRX_IP_CAL_LEN_ERR:
            BaseAdress->CNL[Channel].CH_STATUS = SRX_CH_STATUS_CAL_LEN_ERR(1);
        break;
        case SRX_IP_CAL_DIAG_ERR:
            BaseAdress->CNL[Channel].CH_STATUS = SRX_CH_STATUS_CAL_DIAG_ERR(1);
        break;
        case SRX_IP_NIB_VAL_ERR_HIGH:
            BaseAdress->CNL[Channel].CH_STATUS = SRX_CH_STATUS_NIB_VAL_ERR_HIGH(1);
        break;
        case SRX_IP_SMSG_CRC_ERR:
            BaseAdress->CNL[Channel].CH_STATUS = SRX_CH_STATUS_SMSG_CRC_ERR(1);
        break;
        case SRX_IP_FMSG_CRC_ERR:
            BaseAdress->CNL[Channel].CH_STATUS = SRX_CH_STATUS_FMSG_CRC_ERR(1);
        break;
        case SRX_IP_NUM_EDGES_ERR:
            BaseAdress->CNL[Channel].CH_STATUS = SRX_CH_STATUS_NUM_EDGES_ERR(1);
        break;
        case SRX_IP_CLEAR_ALL:
            BaseAdress->CNL[Channel].CH_STATUS |= SRX_IP_CH_STATUS_RESET_VALUE_U32;
        break;
        default:
        /* default statements */
        break;
    }

}

/*
 *
 */
LOCAL_INLINE uint32 Srx_Ip_GetChannelStatus(uint8 Instance, uint8 Channel)
{
    const SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];
    uint32 RegValue = BaseAdress->CNL[Channel].CH_STATUS;

    return RegValue;
}
/*
 *
 */
LOCAL_INLINE uint32 Srx_Ip_GetFastMessageDataRegister(uint8 Instance, uint8 Channel)
{
    const SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];

    return (uint32)BaseAdress->CNL[Channel].CH_FMSG_DATA;
}

/*
 *
 */
LOCAL_INLINE uint32 Srx_Ip_GetFastMessageCrcRegister(uint8 Instance, uint8 Channel)
{
    const SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];

    return (uint32)BaseAdress->CNL[Channel].CH_FMSG_CRC;
}

/*
 *
 */
LOCAL_INLINE uint32 Srx_Ip_GetFastMessageTimestamp(uint8 Instance, uint8 Channel)
{
   const SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];

    return (uint32)BaseAdress->CNL[Channel].CH_FMSG_TS;
}

/*
 *
 */
LOCAL_INLINE uint32 Srx_Ip_GetSerialMessageTimestamp(uint8 Instance, uint8 Channel)
{
    const SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];

    return (uint32)BaseAdress->CNL[Channel].CH_SMSG_TS;
}

/*
 *
 */
LOCAL_INLINE uint32 Srx_Ip_GetSerialMessageBit3(uint8 Instance, uint8 Channel)
{
    const SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];

    return (uint32)BaseAdress->CNL[Channel].CH_SMSG_BIT3;
}

/*
 *
 */
LOCAL_INLINE uint32 Srx_Ip_GetSerialMessageBit2(uint8 Instance, uint8 Channel)
{
    const SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];

    return (uint32)BaseAdress->CNL[Channel].CH_SMSG_BIT2;
}

/*
 *
 */
LOCAL_INLINE boolean Srx_Ip_GetFastMsgReadyChannelInt(uint8 Instance, uint8 Channel)
{
    const SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];
    uint32 RegValue = BaseAdress->FMSG_RDY_IE;
    boolean RetVal = FALSE;

    if (((RegValue >> Channel) & 0x1U) == 0X1U)
    {
        RetVal = TRUE;
    }

    return RetVal;
}

/*
 *
 */
LOCAL_INLINE boolean Srx_Ip_GetSerialMsgReadyChannelInt(uint8 Instance, uint8 Channel)
{
    const SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];
    uint32 RegValue = BaseAdress->SMSG_RDY_IE;
    boolean RetVal = FALSE;

    if (((RegValue >> Channel) & 0x1U) == 0X1U)
    {
        RetVal = TRUE;
    }

    return RetVal;
}
/*
 *
 */
LOCAL_INLINE uint32 Srx_Ip_GetSerialMsgReadyCtrlInt(uint8 Instance)
{
    const SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];
    uint32 RegValue = BaseAdress->SMSG_RDY_IE;

    return RegValue;
}
/*
 *
 */
LOCAL_INLINE uint32 Srx_Ip_GetFastMsgReadyCtrlInt(uint8 Instance)
{
    const SRX_Type* BaseAdress = Srx_Ip_apxBase[Instance];
    uint32 RegValue = BaseAdress->FMSG_RDY_IE;

    return RegValue;
}

#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#ifdef __cplusplus
          }
#endif

/** @} */

#endif /* SRX_IP_HWACCESS_H */
