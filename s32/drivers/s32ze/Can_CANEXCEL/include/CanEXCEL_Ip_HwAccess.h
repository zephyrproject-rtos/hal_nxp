/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef CANEXCEL_IP_HWACCESS_H_
#define CANEXCEL_IP_HWACCESS_H_

/**
*   @file CanEXCEL_Ip_HwAccess.h
*
*   @addtogroup CanEXCEL
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
#include "CanEXCEL_Ip.h"
#include "Mcal.h"
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
#include "Devassert.h"
#endif
#include "SchM_Can_43_CANEXCEL.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANEXCEL_IP_HWACCESS_VENDOR_ID_H                      43
#define CANEXCEL_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_H       4
#define CANEXCEL_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_H       7
#define CANEXCEL_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_H    0
#define CANEXCEL_IP_HWACCESS_SW_MAJOR_VERSION_H               2
#define CANEXCEL_IP_HWACCESS_SW_MINOR_VERSION_H               0
#define CANEXCEL_IP_HWACCESS_SW_PATCH_VERSION_H               1
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CanEXCEL_Ip.h are of the same vendor */
#if (CANEXCEL_IP_HWACCESS_VENDOR_ID_H != CANEXCEL_IP_VENDOR_ID_H)
    #error "CanEXCEL_Ip_HwAccess.h and CanEXCEL_Ip.h have different vendor ids"
#endif
/* Check if current file and CanEXCEL_Ip.h are of the same Autosar version */
#if ((CANEXCEL_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_H    != CANEXCEL_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (CANEXCEL_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_H    != CANEXCEL_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (CANEXCEL_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_H != CANEXCEL_IP_AR_RELEASE_REVISION_VERSION_H) \
)
    #error "AutoSar Version Numbers of CanEXCEL_Ip_HwAccess.h and CanEXCEL_Ip.h are different"
#endif
/* Check if current file and CanEXCEL_Ip.h are of the same Software version */
#if ((CANEXCEL_IP_HWACCESS_SW_MAJOR_VERSION_H != CANEXCEL_IP_SW_MAJOR_VERSION_H) || \
     (CANEXCEL_IP_HWACCESS_SW_MINOR_VERSION_H != CANEXCEL_IP_SW_MINOR_VERSION_H) || \
     (CANEXCEL_IP_HWACCESS_SW_PATCH_VERSION_H != CANEXCEL_IP_SW_PATCH_VERSION_H) \
)
    #error "Software Version Numbers of CanEXCEL_Ip_HwAccess.h and CanEXCEL_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same version */
    #if ((CANEXCEL_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_H != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (CANEXCEL_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_H != MCAL_AR_RELEASE_MINOR_VERSION) \
)
        #error "Software Version Numbers of CanEXCEL_Ip_HwAccess.h and Mcal.h are different"
    #endif

    #if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
        /* Check if current file and Devassert.h header file are of the same version */
        #if ((CANEXCEL_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_H != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
            (CANEXCEL_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_H != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
   )
            #error "Software Version Numbers of CanEXCEL_Ip_HwAccess.h and Devassert.h are different"
        #endif
    #endif

    /* Check if current file and SchM_Can_43_CANEXCEL.h header file are of the same version */
    #if ((CANEXCEL_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_H    !=  SCHM_CAN_43_CANEXCEL_AR_RELEASE_MAJOR_VERSION) || \
        (CANEXCEL_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_H     !=  SCHM_CAN_43_CANEXCEL_AR_RELEASE_MINOR_VERSION) \
)
        #error "AUTOSAR Version Numbers of CanEXCEL_Ip_HwAccess.c and SchM_Can_43_CANEXCEL.h are different"
    #endif
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#define CANXL_IP_ID_EXT_MASK                                   (0x1FFFFFFFU)
#define CANXL_IP_ID_EXT_SHIFT                                  0
#define CANXL_IP_ID_EXT_WIDTH                                  18
#define CANXL_IP_ID_STD_MASK                                   0x1FFC0000u
#define CANXL_IP_ID_STD_SHIFT                                  18
#define CANXL_IP_ID_STD_WIDTH                                  11


#define CANXL_TX_HEADER_MODE_MASK                              0x80000000u
#define CANXL_TX_HEADER_MODE_SHIFT                             31
#define CANXL_TX_HEADER_PRIO_MASK                              0x0F000000u
#define CANXL_TX_HEADER_PRIO_SHIFT                             24
#define CANXL_TX_HEADER_RETR_MASK                              0x70000u
#define CANXL_TX_HEADER_RETR_SHIFT                             16
#define CANXL_TX_HEADER_RTR_MASK                               0x80000000u
#define CANXL_TX_HEADER_RTR_SHIFT                              31
#define CANXL_TX_HEADER_IDE_MASK                               0x40000000u
#define CANXL_TX_HEADER_IDE_SHIFT                              30
#define CANXL_TX_HEADER_IDE_WIDTH                              1
#define CANXL_TX_HEADER_XLF_MASK                               0x20000000u
#define CANXL_TX_HEADER_XLF_SHIFT                              29
#define CANXL_TX_HEADER_XLF_WIDTH                              1
#define CANXL_TX_HEADER_FDF_MASK                               0x80000000u
#define CANXL_TX_HEADER_FDF_SHIFT                              31
#define CANXL_TX_HEADER_FDF_WIDTH                              1
#define CANXL_TX_HEADER_BRS_MASK                               0x20000000u
#define CANXL_TX_HEADER_BRS_SHIFT                              29
#define CANXL_TX_HEADER_BRS_WIDTH                              1
#define CANXL_TX_HEADER_XLF_MASK                               0x20000000u
#define CANXL_TX_HEADER_XLF_SHIFT                              29
#define CANXL_TX_HEADER_XLF_WIDTH                              1
#define CANXL_TX_HEADER_SDT_MASK                               0x0FF00000u
#define CANXL_TX_HEADER_SDT_SHIFT                              20
#define CANXL_TX_HEADER_SDT_WIDTH                              8
#define CANXL_TX_HEADER_DLC_MASK                               0x7FF00u
#define CANXL_TX_HEADER_DLC_SHIFT                              8
#define CANXL_TX_HEADER_DLC_WIDTH                              11

#define CANXL_MRU_MBOX0                                           0x0u
#define CANXL_MRU_MBOX1                                           0x1u
#define CANXL_MRU_MBOX2                                           0x2u
#define CANXL_MRU_MBOX3                                           0x3u

#define CANXL_MRU_CMD_BUSOFF                                      0x0u
#define CANXL_MRU_CMD_READ_EC                                     0x4u
#define CANXL_MRU_CMD_READ_ST                                     0x5u
#define CANXL_MRU_CMD_READ_TDCS                                   0x6u
#define CANXL_MRU_CMD_WRITE_TDCS                                  0x7u
#define CANXL_MRU_CMD_LAST_ST                                     0x8u

#define BCANXL_EC_TEC_MASK                                        (0xFF00u)
#define BCANXL_EC_TEC_SHIFT                                       (8u)
#define BCANXL_EC_TEC_WIDTH                                       (8u)

#define BCANXL_EC_REC_MASK                                        (0xFFu)
#define BCANXL_EC_REC_SHIFT                                       (0u)
#define BCANXL_EC_REC_WIDTH                                       (8u)

#define BCANXL_ST_FLTCONF_MASK                                    (0x0Cu)
#define BCANXL_ST_FLTCONF_SHIFT                                   (2u)
#define BCANXL_ST_FLTCONF_WIDTH                                   (2u)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*! @brief CANXL error interrupt types
 */
typedef enum
{
    CANXL_INT_FREEZE      = CANXL_SIC_SYSIE_FRZACKIE_MASK,     /*!< Un\Freeze Ack Interrupt */
    CANXL_INT_RX_WARNING  = CANXL_SIC_SYSIE_CRXWRNIE_MASK,     /*!< RX warning interrupt*/
    CANXL_INT_TX_WARNING  = CANXL_SIC_SYSIE_CTXWRNIE_MASK,     /*!< TX warning interrupt*/
    CANXL_INT_INT_ERR     = CANXL_SIC_SYSIE_IERRIE_MASK,       /*!< Internal Error Interrupt */
    CANXL_INT_PASIVE_ERR  = CANXL_SIC_SYSIE_CPERRIE_MASK,      /*!< Passive Error Interrupt */
    CANXL_INT_ERR         = CANXL_SIC_SYSIE_CERRIE_MASK,       /*!< Bus Error interrupt*/
    CANXL_INT_ERR_FAST    = CANXL_SIC_SYSIE_CFDPERRIE_MASK,    /*!< Error Fast interrupt*/
    CANXL_INT_ERR_XL      = CANXL_SIC_SYSIE_CDPERRIE_MASK,     /*!< Error XL Interrupt */
    CANXL_INT_BUSOFF_DONE = CANXL_SIC_SYSIE_CBDONEIE_MASK,     /*!< Error BusOff Done Interrupt */
    CANXL_INT_BUSOFF      = CANXL_SIC_SYSIE_CBOFFIE_MASK,      /*!< Bus off interrupt*/
    CANXL_INT_RXSMB_OVER  = CANXL_SIC_SYSIE_CRXSOERRIE_MASK,   /*!< RX SMB Overrun Error Interrupt*/
    CANXL_INT_MD_UNDER    = CANXL_SIC_SYSIE_CMDUERRIE_MASK,    /*!< MD Underrun Error Interrupt */
    CANXL_INT_MD_OVER     = CANXL_SIC_SYSIE_CMDOERRIE_MASK,    /*!< MD Overrun Error Interrupt */
    CANXL_INT_LOM         = CANXL_SIC_SYSIE_CLSERRIE_MASK,     /*!< LOM State Error Interrupt */
    CANXL_INT_RXFIFO_OVER = CANXL_SIC_SYSIE_CRFOERRIR_MASK,    /*!< RX FIFO Overflow Interrupt */
    CANXL_INT_TXFIFO_UNDER= CANXL_SIC_SYSIE_CTFUERRIR_MASK     /*!< TX FIFO Underflow Interrupt */
} canxl_int_type_t;

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_43_CANEXCEL_START_SEC_CODE
#include "Can_43_CANEXCEL_MemMap.h"

 /*!
 * @brief Set the Message Descriptors Queue Depths and WaterMark Levels
 *
 * @param   base        The CanXL MSG Grup Control base address
 * @param   pConfigs    Pointer to Configuration Structure for Message Descriptors Depths and WaterMarks
 */
void CanXL_SetMDQueueConfigs(CANXL_GRP_CONTROL_Type * base, const Canexcel_Ip_QueueConf * pConfigs);
 /*!
 * @brief Return the Message Descriptor Queue Depth
 *
 * @param   base        The CanXL MSG Grup Control base address
 * @param   MDindex      Index of the message descriptor
 * @return  The Value of the Queue Depth
 */
uint8 CanXL_GetMDQueueDepth(const CANXL_GRP_CONTROL_Type * base, const uint8 MDindex);
/*!
 * @brief   Enable Error Interrupt type
 *
 * @param   base        The CanXL SIC base address
 * @param   errType     Error type
 * @param   enable      Enable\Disable Interrupt
 */
void CanXL_SetErrIntCmd(CANXL_SIC_Type * base, canxl_int_type_t errType, boolean enable);
/*!
 * @brief   Copy the data in the Tx Message Buffer location, based on the frame length
 *
 * @param   info        The Frame Information Parameters as length, frame type
 * @param   data        Pointer to Data to be transmit
 * @param   MB          Pointer to the Message Buffer Ram Location
 */
void CanXL_SetTxMsgBuffData(const Canexcel_Ip_DataInfoType * info, const uint8 * data, uint8 * MB);
/*!
 * @brief   Disable interrupt for all Message Descriptors
 *
 * @param   base        The CanXL Grup Control base address
 */
void CanXL_ResetImaskBuff(CANXL_GRP_CONTROL_Type * base);
/*!
 * @brief   Execute Controller SoftReset action
 *
 * @param   base        The CanXL SIC base address
 * @return  CANEXCEL_STATUS_SUCCESS request was accepted,
 *          CANEXCEL_STATUS_TIMEOUT request fail
 */
Canexcel_Ip_StatusType CanXL_SoftReset(CANXL_SIC_Type * base);
 /*!
 * @brief Calculate the DLC code Value for the payload length
 *
 * @param   payloadSize        The frame payload size in bytes
 * @return  The DLC Code Value
 */
uint8 CAN_ComputeDLCValue(uint8 payloadSize);
 /*!
 * @brief Clears and initilize all RAM area used by CANEXCEL Peripheral
 *
 * @param   CANXL        The CANXL colection of base addresses for periperals embbeded in CANEXCEL
 * @param   instance    The CanXL Instance Number
 */
void CanXL_ClearRAM(const CANEXCEL_StructType * CANXL, uint8 instance);
/*!
 * @brief Return the Contol Lock status for Message Descriptor
 *
 * @param   base        The CanXL Message Descriptor Control base address
 * @return  CANEXCEL_DESCNTSTATUS_UNLOCKED Descriptor is unlocked,
 *          CANEXCEL_DESCNTSTATUS_LOCKED_HW Descriptor is lock by HW,
            CANEXCEL_DESCNTSTATUS_LOCKED_SYS Descriptor is lock by Driver,
            CANEXCEL_DESCNTSTATUS_INVALID Descriptor Status is Invalid.
 */
void CanXL_SetOperationMode(CANXL_SIC_Type * base, Canexcel_Ip_ModesType mode);
/*!
 * @brief Return the Contol Lock status for Message Descriptor
 *
 * @param   base        The CanXL Message Descriptor Control base address
 * @return  CANEXCEL_DESCNTSTATUS_UNLOCKED Descriptor is unlocked,
 *          CANEXCEL_DESCNTSTATUS_LOCKED_HW Descriptor is lock by HW,
            CANEXCEL_DESCNTSTATUS_LOCKED_SYS Descriptor is lock by Driver,
            CANEXCEL_DESCNTSTATUS_INVALID Descriptor Status is Invalid.
 */
 Canexcel_Ip_DesCntStatus CanXL_GetDescControlStatus(const CANXL_DSC_CONTROL_Type * base, uint8 descNo);
/*!
 * @brief   Set contoller to FreezeMode
 *
 * @param   base        The CanXL SIC base address
 * @return  CANEXCEL_STATUS_SUCCESS request was accepted,
 *          CANEXCEL_STATUS_TIMEOUT request fail
 */
Canexcel_Ip_StatusType CanXL_EnterFreezeMode(CANXL_SIC_Type * base);
/*!
 * @brief   Remove contoller from FreezeMode to RunMode
 *
 * @param   base        The CanXL SIC base address
 * @return  CANEXCEL_STATUS_SUCCESS request was accepted,
 *          CANEXCEL_STATUS_TIMEOUT request fail
 */
Canexcel_Ip_StatusType CanXL_ExitFreezeMode(CANXL_SIC_Type * base);
/*!
 * @brief Configure controller depending options like protocol exception, autobus Off Recovery
 *
 * @param   base        The CanXL SIC base address
 * @param   u32Options  Controller Options encoding based on bit position
 * @return  CANEXCEL_STATUS_SUCCESS if configuration was succefully set.
 *          CANEXCEL_STATUS_ERROR configuration is not allowed.
 */
Canexcel_Ip_StatusType CanXL_ConfigCtrlOptions(CANXL_SIC_Type * base, uint32 u32Options);
 /*!
 * @brief Disable config Interrupts on HW
 *
 * @param   base        The CanXL SIC base address
 */
void CanXL_DisableInterrupts(CANXL_SIC_Type * base);
 /*!
 * @brief Enable config Interrupts on HW
 *
 * @param   base        The CanXL SIC base address
 */
void CanXL_EnableInterrupts(CANXL_SIC_Type * base);

#if (CANEXCEL_IP_HAS_TS_ENABLE == STD_ON)
 /*!
 * @brief Set the corresponding Timestamp Configuration TimeBase Selector
 *
 * @param   base     The CanXL TimebaseSelector Grup Control base address
 * @param   type     Position in frame for timestamp capture point
 */
static inline void CanXL_SetTimeBaseSource(CAN_TBS_Type * base, Canexcel_Ip_TimeBaseSelType type)
{
    base->CAN_TS_SEL |= CAN_TBS_CAN_TS_SEL_TS_SEL(type);
}
 /*!
 * @brief Set the corresponding Timestamp Configuration Capture point from the frame
 *
 * @param   base        The CanXL MSG Grup Control base address
 * @param   type      Position in frame for timestamp capture point
 */
static inline void CanXL_SetTimeStampCaputre(CANXL_SIC_Type * base, Canexcel_Ip_TimeStampCaptureType type)
{
    base->BCFG2 |= CANXL_SIC_BCFG2_TSCAP(type);
}
#endif /* (CANEXCEL_IP_HAS_TS_ENABLE == STD_ON) */


/*!
 * @brief Clears the interrupt flag of the message descriptor.
 *
 * @param   base        The CanXL MSG Grup Control base address
 * @param   msgBuffIdx  Index of the message descriptor
 */
static inline void CanXL_ClearMsgDescIntStatusFlag(CANXL_GRP_CONTROL_Type * base, uint32 msgBuffIdx)
{
    uint32 flag = ((uint32)1U << (msgBuffIdx % 32U));
    uint8 ImaskCnt = (uint8)(msgBuffIdx/32U);
    base->MSGIFLAG[ImaskCnt] = flag;
}
/*!
 * @brief Gets the individual CanXL MD interrupt flag.
 *
 * @param   base             The CanEXCEL Decriptor Control base address
 * @param   msgBuffIdx       Index of the message descriptor
 * @return  The individual Message Descriptor interrupt flag (0 and 1 are the flag value)
 */
static inline uint8 CanXL_GetMsgDescIntStatusFlag(const CANXL_GRP_CONTROL_Type * base, uint32 msgBuffIdx)
{
    /* TODO: This need to be protected multithread access*/
    uint8 flag = 0;
    uint8 ImaskCnt = (uint8)(msgBuffIdx/32U);
    flag = (uint8)((((uint32)base->MSGIFLAG[ImaskCnt] & ((uint32)1U << (msgBuffIdx % 32U))) >> (msgBuffIdx % 32U)) & 1U);
    return flag;
}
/*!
 * @brief Gets the individual CanXL MB interrupt flag.
 *
 * @param   base             The CanEXCEL Decriptor Control base address
 * @param   msgBuffIdx       Index of the message descriptor
 * @return  The individual Message Descriptor interrupt flag (0 and 1 are the flag value)
 */
static inline uint8 CanXL_GetMsgBuffIntStatusFlag(const CANXL_GRP_CONTROL_Type * base, uint32 msgBuffIdx)
{
    /* TODO: This need to be protected multithread access*/
    uint8 flag = 0;
    uint32 mask;
    uint8 ImaskCnt = (uint8)(msgBuffIdx/32U);

    mask = base->MSGIMASK[ImaskCnt];
    flag = (uint8)(((base->MSGIFLAG[ImaskCnt] & mask) >> (msgBuffIdx % 32U)) & 1U);

    return flag;
}

/*!
 * @brief Check if controller is in freeze mode or not.
 *
 * @param   base  The CanEXCEL base address
 * @return  TRUE if controller is in freeze mode
 *          FALSE if controller is not in freeze mode
 */
static inline boolean CanXL_IsFreezeMode(const CANXL_SIC_Type * base)
{
    return ((((base->SYSMC &  CANXL_SIC_SYSMC_FRZREQ_MASK) & (base->SYSS & CANXL_SIC_SYSS_FRZACKF_MASK)) != 0U)? TRUE : FALSE);
}

/*!
 * @brief Check if controller is in FD mode or not.
 *
 * @param   base  The CanEXCEL base address
 * @return  TRUE if controller is in FD mode
 *          FALSE if controller is not in FD mode
 */
static inline boolean CanXL_IsFDModeEnabled(const CANXL_SIC_Type * base)
{
    return (((base->BCFG2 & (CANXL_SIC_BCFG2_FDEN_MASK)) != 0U) ? TRUE : FALSE);
}

/*!
 * @brief Check if controller is in XL mode or not.
 *
 * @param   base  The CanEXCEL base address
 * @return  TRUE if controller is in XL mode
 *          FALSE if controller is not in XL mode
 */
static inline boolean CanXL_IsXLModeEnabled(const CANXL_SIC_Type * base)
{
    return (((base->BCFG2 & (CANXL_SIC_BCFG2_XLEN_MASK)) != 0U) ? TRUE : FALSE);
}
/*!
 * @brief Return Descriptor State.
 *
 * @param   base  The CanEXCEL base address
 * @param   descNo  Index of the message descriptor
 * @return  The drescriptor state based on states
 * enumerated by Canexcel_Ip_DescState type
 */
static inline Canexcel_Ip_DescState CanXL_GetDesciptorState(const CANXL_DSC_CONTROL_Type * base, uint8 descNo)
{
    Canexcel_Ip_DescState retval;
    switch (base->DSCMBCTRLAR[descNo].DCSTA & CANXL_DSC_CONTROL_DCSTA_STATE_MASK)
    {
        case 0u:
            retval = CANEXCEL_DESC_STATE_INACTIVE;
            break;
        case 1u:
            retval = CANEXCEL_DESC_STATE_EMPTY;
            break;
        case 2u:
            retval = CANEXCEL_DESC_STATE_NOTFULL;
            break;
        case 3u:
            retval = CANEXCEL_DESC_STATE_FULL;
            break;
        default:
            retval = CANEXCEL_DESC_STATE_OVERRUN;
            break;
    }
    return retval;
}
/*!
 * @brief Return Descriptor Status of Hw Index
 *
 * @param   base  The CanEXCEL base address
 * @param   descNo  Index of the message descriptor
 * @return  The drescriptor HW index Value
 */
static inline uint8 CanXL_GetDesciptorHWIndex(const CANXL_DSC_CONTROL_Type * base, uint8 descNo)
{
    return (uint8)((base->DSCMBCTRLAR[descNo].DCSTA & CANXL_DSC_CONTROL_DCSTA_HWPOINTER_MASK) >> CANXL_DSC_CONTROL_DCSTA_HWPOINTER_SHIFT);
}
/*!
 * @brief Return Descriptor Status of System Index
 *
 * @param   base  The CanEXCEL base address
 * @param   descNo  Index of the message descriptor
 * @return  The drescriptor System index Value
 */
 static inline uint8 CanXL_GetDesciptorSysIndex(const CANXL_DSC_CONTROL_Type * base, uint8 descNo)
{
    return (uint8)((base->DSCMBCTRLAR[descNo].DCSTA & CANXL_DSC_CONTROL_DCSTA_SYSPOINTER_MASK) >> CANXL_DSC_CONTROL_DCSTA_SYSPOINTER_SHIFT);
}
/*!
 * @brief Enables/Disables the Self Reception feature.
 *
 * If enabled, CanExcel is allowed to receive frames transmitted by itself.
 *
 * @param   base  The CanExcel SIC base address
 * @param   enable Enable/Disable Self Reception
 */
static inline void CanXL_SetSelfReception(CANXL_SIC_Type * base,
                                          boolean enable)
{
    base->BCFG2 = (base->BCFG2 & ~CANXL_SIC_BCFG2_SRXEN_MASK) | CANXL_SIC_BCFG2_SRXEN(enable ? 1UL : 0UL);
}

/*!
 * @brief Checks if the listen only mode is enabled.
 *
 * @param   base    The FlexCAN base address
 * @return  TRUE if enabled; FALSE if disabled
 */
static inline boolean CanXL_IsListenOnlyModeEnabled(const CANXL_SIC_Type * base)
{
    return (((base->BCFG2 & (CANXL_SIC_BCFG2_LOM_MASK)) != 0U) ? TRUE : FALSE);
}


/*!
 * @brief Sets the CanEXCEL FD time segments for setting up data bit rate.
 *
 * @param   base The CanEXCEL base address
 * @param   timeSeg    CanEXCEL time segments, which need to be set for the bit rate.
 */
static inline void CanXL_SetFDBaudRate(CANXL_SIC_Type * base, const Canexcel_Ip_TimeSegmentType * timeSeg)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
DevAssert(timeSeg != NULL_PTR);
#endif
(base->BFDCBT) = 0U;

(base->BFDCBT) = (CANXL_SIC_BFDCBT_FTSEG1(timeSeg->phaseSeg1 + timeSeg->propSeg) |
                  CANXL_SIC_BFDCBT_FTSEG2(timeSeg->phaseSeg2) |
                  CANXL_SIC_BFDCBT_FRJW(timeSeg->rJumpwidth)
       );
}

/*!
 * @brief Sets the CanEXCEL XL time segments for setting up data bit rate.
 *
 * @param   base The CanEXCEL base address
 * @param   timeSeg    CanEXCEL time segments, which need to be set for the bit rate.
 */
static inline void CanXL_SetXLBaudRate(CANXL_SIC_Type * base, const Canexcel_Ip_TimeSegmentType * timeSeg)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
DevAssert(timeSeg != NULL_PTR);
#endif
(base->BXDCBT) = 0U;

(base->BXDCBT) = (CANXL_SIC_BXDCBT_XTSEG1(timeSeg->phaseSeg1 + timeSeg->propSeg) |
                  CANXL_SIC_BXDCBT_XTSEG2(timeSeg->phaseSeg2) |
                  CANXL_SIC_BXDCBT_XRJW(timeSeg->rJumpwidth)
       );
}

/*!
 * @brief Sets the CanEXCEL nominal time segments for setting up data bit rate.
 *
 * @param   base The CanEXCEL base address
 * @param   timeSeg    CanEXCEL time segments, which need to be set for the bit rate.
 */
static inline void CanXL_SetBaudRate(CANXL_SIC_Type * base, const Canexcel_Ip_TimeSegmentType * timeSeg)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
DevAssert(timeSeg != NULL_PTR);
#endif
(base->BNCBT) = 0U;
(base->BBPRS) = 0U;

(base->BBPRS) = CANXL_SIC_BBPRS_PRESDIV(timeSeg->preDivider);
(base->BNCBT) = (CANXL_SIC_BNCBT_NTSEG1(timeSeg->phaseSeg1 + timeSeg->propSeg) |
                  CANXL_SIC_BNCBT_NTSEG2(timeSeg->phaseSeg2) |
                  CANXL_SIC_BNCBT_NRJW(timeSeg->rJumpwidth)
       );
}


/*!
 * @brief Enables/Disables Error Response
 *
 * @param   Base    The CanXL SIC base address
 * @param   Enable  TRUE to signalize errors as protocol exception; FALSE to signalize errors with Error frames
 */
static inline void CanXL_SetXLErrorResponse(CANXL_SIC_Type * Base, boolean Enable)
{
    Base->BCFG2 = (Base->BCFG2 & ~CANXL_SIC_BCFG2_XLER_MASK) | CANXL_SIC_BCFG2_XLER(Enable ? 1UL : 0UL);
}
/*!
 * @brief Enables/Disables PWM mode
 *
 * @param   Base    The CanXL SIC base address
 * @param   Enable  TRUE to enable; FALSE to disable
 */
static inline void CanXL_SetPwmModeEnable(CANXL_SIC_Type * Base, boolean Enable)
{
    Base->BCFG2 = (Base->BCFG2 & ~CANXL_SIC_BCFG2_TMSE_MASK) | CANXL_SIC_BCFG2_TMSE(Enable ? 1UL : 0UL);
}

/*!
 * @brief Checks if the Transceiver PWM mode is enabled.
 *
 * @param   Base    The FlexCAN base address
 * @return  TRUE if enabled; FALSE if disabled
 */
static inline boolean CanXL_IsPwmModeEnable(const CANXL_SIC_Type * Base)
{
    return (((Base->BCFG2 & (CANXL_SIC_BCFG2_TMSE_MASK)) != 0U) ? TRUE : FALSE);
}

/*!
 * @brief Configure PWM phases
 *
 */
static inline void CanXL_SetPWMPhases(CANXL_SIC_Type * Base, uint8 PWMS, uint8 PWML, uint8 PWMO)
{
    Base->BMICI &= ~(CANXL_SIC_BMICI_PWMS_MASK | CANXL_SIC_BMICI_PWML_MASK | CANXL_SIC_BMICI_PWMO_MASK);
    Base->BMICI |= (CANXL_SIC_BMICI_PWMS(PWMS) | CANXL_SIC_BMICI_PWML(PWML) | CANXL_SIC_BMICI_PWMO(PWMO));
}


/*!
 * @brief Gets the CanEXCEL FD time segment.
 *
 * @param   base The CanEXCEL base address
 * @param   timeSeg    CanEXCEL time segments.
 */
static inline void CanXL_GetFDBaudRate(const CANXL_SIC_Type * base, Canexcel_Ip_TimeSegmentType * timeSeg)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(timeSeg != NULL_PTR);
#endif

    timeSeg->propSeg = 0U;
    timeSeg->phaseSeg1 = ((base->BFDCBT & CANXL_SIC_BFDCBT_FTSEG1_MASK) >> CANXL_SIC_BFDCBT_FTSEG1_SHIFT);
    timeSeg->phaseSeg2 = ((base->BFDCBT & CANXL_SIC_BFDCBT_FTSEG2_MASK) >> CANXL_SIC_BFDCBT_FTSEG2_SHIFT);
    timeSeg->rJumpwidth = ((base->BFDCBT & CANXL_SIC_BFDCBT_FRJW_MASK) >> CANXL_SIC_BFDCBT_FRJW_SHIFT);
    timeSeg->preDivider = ((base->BBPRS & CANXL_SIC_BBPRS_PRESDIV_MASK) >> CANXL_SIC_BBPRS_PRESDIV_SHIFT);
}

/*!
 * @brief Gets the CanEXCEL XL time segments.
 *
 * @param   base The CanEXCEL base address
 * @param   timeSeg    CanEXCEL time segments.
 */
static inline void CanXL_GetXLBaudRate(const CANXL_SIC_Type * base, Canexcel_Ip_TimeSegmentType * timeSeg)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(timeSeg != NULL_PTR);
#endif

    timeSeg->propSeg = 0U;
    timeSeg->phaseSeg1 = ((base->BXDCBT & CANXL_SIC_BXDCBT_XTSEG1_MASK) >> CANXL_SIC_BXDCBT_XTSEG1_SHIFT);
    timeSeg->phaseSeg2 = ((base->BXDCBT & CANXL_SIC_BXDCBT_XTSEG2_MASK) >> CANXL_SIC_BXDCBT_XTSEG2_SHIFT);
    timeSeg->rJumpwidth = ((base->BXDCBT & CANXL_SIC_BXDCBT_XRJW_MASK) >> CANXL_SIC_BXDCBT_XRJW_SHIFT);
    timeSeg->preDivider = ((base->BBPRS & CANXL_SIC_BBPRS_PRESDIV_MASK) >> CANXL_SIC_BBPRS_PRESDIV_SHIFT);
}
/*!
 * @brief Gets the CanEXCEL nominal time segments.
 *
 * @param   base The CanEXCEL base address
 * @param   timeSeg    CanEXCEL time segments.
 */
static inline void CanXL_GetBaudRate(const CANXL_SIC_Type * base, Canexcel_Ip_TimeSegmentType * timeSeg)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(timeSeg != NULL_PTR);
#endif

    timeSeg->propSeg = 0U;
    timeSeg->phaseSeg1 = ((base->BNCBT & CANXL_SIC_BNCBT_NTSEG1_MASK) >> CANXL_SIC_BNCBT_NTSEG1_SHIFT);
    timeSeg->phaseSeg2 = ((base->BNCBT & CANXL_SIC_BNCBT_NTSEG2_MASK) >> CANXL_SIC_BNCBT_NTSEG2_SHIFT);
    timeSeg->rJumpwidth = ((base->BNCBT & CANXL_SIC_BNCBT_NRJW_MASK) >> CANXL_SIC_BNCBT_NRJW_SHIFT);
    timeSeg->preDivider = ((base->BBPRS & CANXL_SIC_BBPRS_PRESDIV_MASK) >> CANXL_SIC_BBPRS_PRESDIV_SHIFT);
}
/*!
 * @brief Enable the CanEXCEL MRU Services.
 *
 * @param   base The CanEXCEL base address
 */
static inline void CanXL_MruEnable(CANXL_MRU_Type * base)
{
    base->CHXCONFIG[0u].CH_CFG0 = CANXL_MRU_CH_CFG0_CHR_MASK;
    base->CHXCONFIG[0u].CH_CFG0 = CANXL_MRU_CH_CFG0_CHE_MASK;
}
/*!
 * @brief Disable the CanEXCEL MRU Services.
 *
 * @param   base The CanEXCEL base address
 */
static inline void CanXL_MruDisable(CANXL_MRU_Type * base)
{
    base->CHXCONFIG[0u].CH_CFG0 = CANXL_MRU_CH_CFG0_CHR_MASK;
    base->CHXCONFIG[0u].CH_CFG0 &= ~CANXL_MRU_CH_CFG0_CHE_MASK;
}
 /*!
 * @brief Config the Acceptance Address Filter for RxFIFO
 *
 * @param   base The CanEXCEL RxFIFO Filters base address
 * @param   filter  The Acceptance filter configuration pointer
 * @param   filtIdx  Filter Position
 */
void CanXL_ConfigAccAddr(CANXL_RXFIFO_Type * base,const Canexcel_Ip_RxFifoFilterID_ADDR * filter, uint8 filtIdx);
 /*!
 * @brief Config the Accept ID Filter for RxFIFO
 *
 * @param   base The CanEXCEL RxFIFO Filters base address
 * @param   filter  The ID filter configuration pointer
 * @param   filtIdx  Filter Position
 */
void CanXL_ConfigIDFilter(CANXL_RXFIFO_Type * base,const Canexcel_Ip_RxFifoFilterID_ADDR * filter, uint8 filtIdx);
 /*!
 * @brief Config the Accept SDU Filter for RxFIFO
 *
 * @param   base The CanEXCEL RxFIFO Filters base address
 * @param   filter  The SDU filter configuration pointer
 * @param   filtIdx  Filter Position
 */
void CanXL_ConfigSDUFilter(CANXL_RXFIFO_Type * base,const Canexcel_Ip_RxFifoFilterSDU_CAN * filter, uint8 filtIdx);
 /*!
 * @brief Config the Accept VCAN Filter for RxFIFO
 *
 * @param   base The CanEXCEL RxFIFO Filters base address
 * @param   filter  The VCAN filter configuration pointer
 * @param   filtIdx  Filter Position
 */
void CanXL_ConfigVCANFilter(CANXL_RXFIFO_Type * base,const Canexcel_Ip_RxFifoFilterSDU_CAN * filter, uint8 filtIdx);
 /*!
 * @brief Config the Acceptance Address Filter for FilterBanks Part of MessageDescriptors Filter Process
 *
 * @param   base The CanEXCEL Filter Bank base address
 * @param   bank Filter Bank 0\1
 * @param   filter  Pointer to AF filter configuration
 * @param   filtIdx  Filter Position in the Bank
 */
void CanXL_ConfigAccAddrFilterBank(CANXL_FILTER_BANK_Type * base, uint8 bank,const Canexcel_Ip_RxFifoFilterID_ADDR * filter, uint8 filtIdx);
 /*!
 * @brief Config the Acceptance SDU for FilterBanks Part of MessageDescriptors Filter Process
 *
 * @param   base The CanEXCEL Filter Bank base address
 * @param   bank Filter Bank 0\1
 * @param   filter  Pointer to SDU configuration
 * @param   filtIdx  Filter Position in the Bank
 */
void CanXL_ConfigSDUFilterBank(CANXL_FILTER_BANK_Type * base, uint8 bank,const Canexcel_Ip_RxFifoFilterSDU_CAN * filter, uint8 filtIdx);
 /*!
 * @brief Config the Acceptance VCAN Filter for FilterBanks Part of MessageDescriptors Filter Process
 *
 * @param   base The CanEXCEL Filter Bank base address
 * @param   bank Filter Bank 0\1
 * @param   filter  Pointer to VCAN filter configuration
 * @param   filtIdx  Filter Position in the Bank
 */
void CanXL_ConfigVCANFilterBank(CANXL_FILTER_BANK_Type * base, uint8 bank,const Canexcel_Ip_RxFifoFilterSDU_CAN * filter, uint8 filtIdx);
 /*!
 * @brief Config the Rejection Address Filter for FilterBanks Part of MessageDescriptors Filter Process
 *
 * @param   base The CanEXCEL Filter Bank base address
 * @param   bank Filter Bank 0\1
 * @param   filter  Pointer to AF filter configuration
 * @param   filtIdx  Filter Position in the Bank
 */
void CanXL_ConfigAccAddrRejectBank(CANXL_FILTER_BANK_Type * base, uint8 bank,const Canexcel_Ip_RxFifoFilterID_ADDR * filter, uint8 filtIdx);
 /*!
 * @brief Config the Rejection VCAN Filter for FilterBanks Part of MessageDescriptors Filter Process
 *
 * @param   base The CanEXCEL Filter Bank base address
 * @param   bank Filter Bank 0\1
 * @param   filter  Pointer to VCAN filter configuration
 * @param   filtIdx  Filter Position in the Bank
 */
void CanXL_ConfigSDURejectBank(CANXL_FILTER_BANK_Type * base, uint8 bank,const Canexcel_Ip_RxFifoFilterSDU_CAN * filter, uint8 filtIdx);
 /*!
 * @brief Config the Rejection VCAN Filter for FilterBanks Part of MessageDescriptors Filter Process
 *
 * @param   base The CanEXCEL Filter Bank base address
 * @param   bank Filter Bank 0\1
 * @param   filter  Pointer to VCAN filter configuration
 * @param   filtIdx  Filter Position in the Bank
 */
void CanXL_ConfigVCANRejectBank(CANXL_FILTER_BANK_Type * base, uint8 bank,const Canexcel_Ip_RxFifoFilterSDU_CAN * filter, uint8 filtIdx);

 /*!
 * @brief IrqHandler for Rx\Tx and RxFIFO
 *
 * @param   instance The CanXL Instance Number
 */
void Canexcel_Ip_RxTxIRQHandler(uint8 instance);

 /*!
 * @brief IrqHandler for MRU service unit
 *
 * @param   instance The CanXL Instance Number
 */
void Canexcel_Ip_MruIRQHandler(uint8 instance);

 /*!
 * @brief IrqHandler for Errors
 *
 * @param   instance The CanXL Instance Number
 */
void Canexcel_Ip_ErrIRQHandler(uint8 instance);

#define CAN_43_CANEXCEL_STOP_SEC_CODE
#include "Can_43_CANEXCEL_MemMap.h"

#ifdef __cplusplus
}
#endif /* __cplusplus */

/** @} */

#endif /* CANEXCEL_IP_HWACCESS_H_ */
