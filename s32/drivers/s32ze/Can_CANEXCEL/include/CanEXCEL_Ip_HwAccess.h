/*
 * Copyright 2022 NXP
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
#define CANXL_TX_HEADER_RETR_MASK                              0x38000u
#define CANXL_TX_HEADER_RETR_SHIFT                             15
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
#define CANXL_TX_HEADER_DLC_MASK                               0x3FF00u
#define CANXL_TX_HEADER_DLC_SHIFT                              8
#define CANXL_TX_HEADER_DLC_WIDTH                              10

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
    CANXL_INT_TXFIFO_UNDER= CANXL_SIC_SYSIE_CTFOERRIR_MASK     /*!< TX FIFO Underflow Interrupt */
} canxl_int_type_t;

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

void CanXL_SetErrIntCmd(CANXL_SIC_Type * base, canxl_int_type_t errType, boolean enable);
void CanXL_SetTxMsgBuffData(const Canexcel_Ip_DataInfoType * info, const uint8 * data, uint8 * MB);
void CanXL_ResetImaskBuff(CANXL_GRP_CONTROL_Type * base, uint8 Instance);
Canexcel_Ip_StatusType CanXL_SoftReset(CANXL_SIC_Type * base);
uint8 CAN_ComputeDLCValue(uint8 payloadSize);
void CanXL_ClearRAM(CANEXCEL_StructType * CANXL, uint8 instance);
void CanXL_SetOperationMode(CANXL_SIC_Type * base, Canexcel_Ip_ModesType mode);
Canexcel_Ip_DesCntStatus CanXL_GetDescControlStatus(CANXL_DSC_CONTROL_Type * base, uint8 descNo);
Canexcel_Ip_StatusType CanXL_EnterFreezeMode(CANXL_SIC_Type * base);
Canexcel_Ip_StatusType CanXL_ExitFreezeMode(CANXL_SIC_Type * base);
Canexcel_Ip_StatusType CanXL_ConfigCtrlOptions(CANXL_SIC_Type * base, uint32 u32Options);
void CanXL_DisableInterrupts(CANXL_SIC_Type * base, uint8 Instance);
void CanXL_EnableInterrupts(CANXL_SIC_Type * base, uint8 Instance);
void CanXL_ConfigInterrupts(uint8 Instance);

#if (CANEXCEL_IP_HAS_TS_ENABLE == STD_ON)
static inline void CanXL_SetTimeBaseSource(CAN_TBS_Type * base, Canexcel_Ip_TimeBaseSelType type)
{
    base->CAN_TS_SEL |= CAN_TBS_CAN_TS_SEL_TS_SEL(type);
}

static inline void CanXL_SetTimeStampCaputre(CANXL_SIC_Type * base, Canexcel_Ip_TimeStampCaptureType type)
{
    base->BCFG2 |= CANXL_SIC_BCFG2_TSCAP(type);
}
#endif /* (CANEXCEL_IP_HAS_TS_ENABLE == STD_ON) */
/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_SetMsgBuffIntCmd
 * Description   : Set the corresponding Message Descriptor interrupt
 *
 *END**************************************************************************/
static inline void CanXL_SetMsgBuffIntCmd(CANXL_GRP_CONTROL_Type * base, uint32 msgBuffIdx)
{
    uint8 ImaskCnt = msgBuffIdx/32U ;
    /* Enable the corresponding message buffer Interrupt */
    uint32 temp = 1UL << (msgBuffIdx % 32U);
    base->MSGIMASK[ImaskCnt] |= temp;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_ClearMsgBuffIntCmd
 * Description   : Disable the corresponding Message Descriptor interrupt
 *
 *END**************************************************************************/
static inline void CanXL_ClearMsgBuffIntCmd(CANXL_GRP_CONTROL_Type * base, uint32 mb_idx )
{
    uint8 ImaskCnt = mb_idx/32U ;
    /* Enable the corresponding message buffer Interrupt */
    uint32 temp = 1UL << (mb_idx % 32U);
    base->MSGIMASK[ImaskCnt] &= (~temp);
}

/*!
 * @brief Clears the interrupt flag of the message descriptor.
 *
 * @param   base        The CanXL MSG Grup Control base address
 * @param   msgBuffIdx  Index of the message descriptor
 */
static inline void CanXL_ClearMsgDescIntStatusFlag(CANXL_GRP_CONTROL_Type * base, uint32 msgBuffIdx)
{
    uint32 flag = ((uint32)1U << (msgBuffIdx % 32U));
    uint8 ImaskCnt = msgBuffIdx/32U;
    base->MSGIFLAG[ImaskCnt] = flag;
}

static inline uint8 CanXL_GetMsgDescIntStatusFlag(const CANXL_GRP_CONTROL_Type * base, uint32 msgBuffIdx)
{
    /* TODO: This need to be protected multithread access*/
    uint8 flag = 0;
    MCAL_DATA_SYNC_BARRIER();
    uint8 ImaskCnt = msgBuffIdx/32U;
    flag = (uint8)(((base->MSGIFLAG[ImaskCnt] & (1U << (msgBuffIdx % 32))) >> (msgBuffIdx % 32U)) & 1U);
    return flag;
}
/*!
 * @brief Gets the individual CanXL MB interrupt flag.
 *
 * @param   base  The FlexCAN base address
 * @param   msgBuffIdx       Index of the message buffer
 * @return  the individual Message Buffer interrupt flag (0 and 1 are the flag value)
 */
static inline uint8 CanXL_GetMsgBuffIntStatusFlag(const CANXL_GRP_CONTROL_Type * base, uint32 msgBuffIdx)
{
    /* TODO: This need to be protected multithread access*/
    uint8 flag = 0;
    uint32 mask;
    uint8 ImaskCnt = msgBuffIdx/32U;

    if (msgBuffIdx < 32U)
    {
        mask = base->MSGIMASK[ImaskCnt];
        flag = (uint8)(((base->MSGIFLAG[ImaskCnt] & mask) >> (msgBuffIdx % 32U)) & 1U);
    }
    return flag;
}

/*!
 * @brief Check if controller is in freeze mode or not.
 *
 * @param   base  The FlexCAN base address
 * @return  TRUE if controller is in freeze mode
 *          FALSE if controller is not in freeze mode
 */
static inline boolean CanXL_IsFreezeMode(const CANXL_SIC_Type * base)
{
    return ( ( ( (base->SYSMC &  CANXL_SIC_SYSMC_FRZREQ_MASK) & (base->SYSS & CANXL_SIC_SYSS_FRZACKF_MASK) ) != 0U )? TRUE : FALSE);
}

static inline Canexcel_Ip_DescState CanXL_GetDesciptorState(CANXL_DSC_CONTROL_Type * base, uint8 descNo)
{
    return (Canexcel_Ip_DescState)(base->DSCMBCTRLAR[descNo].STA.DCSTA & CANXL_DSC_CONTROL_DCSTA_STATE_MASK);
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
 * @brief Enables/Disables Flexible Data rate (if supported).
 *
 * @param   base    The CanXL SIC base address
 * @param   enable  TRUE to enable; FALSE to disable
 */
static inline void CanXL_SetFDEnabled(CANXL_SIC_Type * base,
                                        boolean enableFD,
                                        boolean enableBRS
                                       )
{
    base->BCFG2 = (base->BCFG2 & ~CANXL_SIC_BCFG2_FDEN_MASK) | CANXL_SIC_BCFG2_FDEN(enableFD ? 1UL : 0UL);
    /* Enable BitRate Switch support */
    base->BCFG1 = (base->BCFG1 & ~CANXL_SIC_BCFG1_FDRSDIS_MASK) | CANXL_SIC_BCFG1_FDRSDIS(enableBRS ? 0UL : 1UL);
    /* Disable Transmission Delay Compensation by default */
    base->BTDCC &= ~(CANXL_SIC_BTDCC_FTDCEN_MASK | CANXL_SIC_BTDCC_FTDCOFF_MASK);
}

/*!
 * @brief Enables/Disables XL Frame Support
 *
 * @param   base    The CanXL SIC base address
 * @param   enable  TRUE to enable; FALSE to disable
 */
static inline void CanXL_SetXLEnable(CANXL_SIC_Type * base,
                                     boolean enableXL
                                    )
{
    base->BCFG2 = (base->BCFG2 & ~CANXL_SIC_BCFG2_XLEN_MASK) | CANXL_SIC_BCFG2_XLEN(enableXL ? 1UL : 0UL);
    /* Disable Transmission Delay Compensation by default */
    base->BTDCC &= ~(CANXL_SIC_BTDCC_XTDCEN_MASK | CANXL_SIC_BTDCC_XTDCOFF_MASK);
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

(base->BFDCBT) = ((base->BFDCBT) | (CANXL_SIC_BFDCBT_FTSEG1(timeSeg->phaseSeg1 + timeSeg->propSeg) |
                                    CANXL_SIC_BFDCBT_FTSEG2(timeSeg->phaseSeg2) |
                                    CANXL_SIC_BFDCBT_FRJW(timeSeg->rJumpwidth)
                                 )
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

(base->BXDCBT) = ((base->BXDCBT) | (CANXL_SIC_BXDCBT_XTSEG1(timeSeg->phaseSeg1 + timeSeg->propSeg) |
                                    CANXL_SIC_BXDCBT_XTSEG2(timeSeg->phaseSeg2) |
                                    CANXL_SIC_BXDCBT_XRJW(timeSeg->rJumpwidth)
                                 )
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
(base->BNCBT) = ((base->BNCBT) | (CANXL_SIC_BNCBT_NTSEG1(timeSeg->phaseSeg1 + timeSeg->propSeg) |
                                  CANXL_SIC_BNCBT_NTSEG2(timeSeg->phaseSeg2) |
                                  CANXL_SIC_BNCBT_NRJW(timeSeg->rJumpwidth)
                                 )
                );
}

void CanXL_ConfigAccAddr(CANXL_RXFIFO_Type * base, Canexcel_Ip_RxFifoFilterID_ADDR * filter, uint8 filtIdx);
void CanXL_ConfigIDFilter(CANXL_RXFIFO_Type * base, Canexcel_Ip_RxFifoFilterID_ADDR * filter, uint8 filtIdx);
void CanXL_ConfigSDUFilter(CANXL_RXFIFO_Type * base, Canexcel_Ip_RxFifoFilterSDU_CAN * filter, uint8 filtIdx);
void CanXL_ConfigVCANFilter(CANXL_RXFIFO_Type * base, Canexcel_Ip_RxFifoFilterSDU_CAN * filter, uint8 filtIdx);

#ifdef __cplusplus
}
#endif /* __cplusplus */

/** @} */

#endif /* CANEXCEL_IP_HWACCESS_H_ */
