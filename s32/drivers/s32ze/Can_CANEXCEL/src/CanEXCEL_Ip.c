/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file CanEXCEL_Ip.c
*
*   @addtogroup CanEXCEL
*   @{
*/

#include "CanEXCEL_Ip.h"
#include "CanEXCEL_Ip_HwAccess.h"
#include "SchM_Can_43_CANEXCEL.h"

#define CAN_43_CANEXCEL_START_SEC_VAR_INIT_UNSPECIFIED
#include "Can_43_CANEXCEL_MemMap.h"

static CANXL_SIC_Type * EXL_SIC_PTR[] = IP_CANXL_SIC_BASE_PTRS;
static CANXL_MRU_Type * EXL_MRU_PTR[] = IP_CANXL_MRU_BASE_PTRS;
static CANXL_GRP_CONTROL_Type * EXL_GRP_PTR[] = IP_CANXL_GRP_CONTROL_BASE_PTRS;
static CANXL_DSC_CONTROL_Type * EXL_DESC_CTR_PTR[] = IP_CANXL_DSC_CONTROL_BASE_PTRS;
static CANXL_MSG_DESCRIPTORS_Type * EXL_MSGD_PTR[] = IP_CANXL_MSG_DESCRIPTORS_BASE_PTRS;
static CANXL_RXFIFO_CONTROL_Type * EXL_RXF_CNT_PTR[] = IP_CANXL_RXFIFO_CONTROL_BASE_PTRS;
static CANXL_RXFIFO_Type * EXL_RXFIFO_PTR[] = IP_CANXL_RXFIFO_BASE_PTRS;
static CANXL_FILTER_BANK_Type * EXL_FILTER_PTR[] = IP_CANXL_FILTER_BANK_BASE_PTRS;
#if (CANEXCEL_IP_HAS_TS_ENABLE == STD_ON)
static CAN_TBS_Type * EXL_TBS_PTR[] = IP_CANXL_TBS_BASE_PTRS;
#endif

#define CAN_43_CANEXCEL_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Can_43_CANEXCEL_MemMap.h"

#define CAN_43_CANEXCEL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_43_CANEXCEL_MemMap.h"

static CANEXCEL_StructType CANEXCEL;

/* Pointer to runtime state structure.*/
static Canexcel_Ip_StateType * Canexcel_Ip_apxState[CANXL_SIC_INSTANCE_COUNT];

#define CAN_43_CANEXCEL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_43_CANEXCEL_MemMap.h"

#define CAN_43_CANEXCEL_START_SEC_CODE
#include "Can_43_CANEXCEL_MemMap.h"

static void Canexcel_Ip_MainFunction(uint8 instance, uint8 mb_idx);

static void ValidateFrameDLC(uint8 instance,uint32 mb_idx, Canexcel_Ip_StateType * state);

static void Canexcel_CompleteTxBuffers(uint8 instance,uint32 mb_idx, Canexcel_Ip_StateType * state);

static Canexcel_Ip_StatusType Canexcel_GetControllerMRU(uint8 instance, uint32 * pValue, uint8 command);

static void Canexcel_Ip_ConfInit(uint8 instance, const Canexcel_Ip_ConfigType * Config);

static void Canexcel_ProcessErrIRQ(uint8 instance,const Canexcel_Ip_StateType * state, uint32 bcanXlStatus, uint32 sysStatus);

 /*!
 * @brief Set the corresponding Message Descriptor interrupt
 *
 * @param   base        The CanXL MSG Grup Control base address
 * @param   mb_idx      Index of the message descriptor
 */
static inline void CanXL_SetMsgBuffIntCmd(CANXL_GRP_CONTROL_Type * base, uint32 msgBuffIdx)
{
    uint8 ImaskCnt = (uint8)(msgBuffIdx/32U) ;
    /* Enable the corresponding message buffer Interrupt */
    uint32 temp = 1UL << (msgBuffIdx % 32U);
    SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_04();
    base->MSGIMASK[ImaskCnt] |= temp;
    SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_04();
}
 /*!
 * @brief Disable the corresponding Message Descriptor interrupt
 *
 * @param   base        The CanXL MSG Grup Control base address
 * @param   mb_idx      Index of the message descriptor
 */
static inline void CanXL_ClearMsgBuffIntCmd(CANXL_GRP_CONTROL_Type * base, uint32 mb_idx)
{
    uint8 ImaskCnt = (uint8)(mb_idx/32U) ;
    /* Enable the corresponding message buffer Interrupt */
    uint32 temp = 1UL << (mb_idx % 32U);
    SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_13();
    base->MSGIMASK[ImaskCnt] &= (~temp);
    SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_13();
}

/*!
 * @brief Enables/Disables Listen Only Mode
 *
 * @param   base    The CanXL SIC base address
 * @param   enable  TRUE to enable; FALSE to disable
 */
static inline void CanXL_SetListenOnlyMode(CANXL_SIC_Type * base, boolean enable)
{
    SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_05();
    base->BCFG2 = (base->BCFG2 & ~CANXL_SIC_BCFG2_LOM_MASK) | CANXL_SIC_BCFG2_LOM(enable ? 1UL : 0UL);
    SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_05();
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
    SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_00();
    base->BCFG2 = (base->BCFG2 & ~CANXL_SIC_BCFG2_FDEN_MASK) | CANXL_SIC_BCFG2_FDEN(enableFD ? 1UL : 0UL);
    /* Enable BitRate Switch support */
    base->BCFG1 = (base->BCFG1 & ~CANXL_SIC_BCFG1_FDRSDIS_MASK) | CANXL_SIC_BCFG1_FDRSDIS(enableBRS ? 0UL : 1UL);
    /* Disable Transmission Delay Compensation by default */
    base->BTDCC &= ~(CANXL_SIC_BTDCC_FTDCEN_MASK | CANXL_SIC_BTDCC_FTDCOFF_MASK);
    SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_00();
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
    SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_14();
    base->BCFG2 = (base->BCFG2 & ~CANXL_SIC_BCFG2_XLEN_MASK) | CANXL_SIC_BCFG2_XLEN(enableXL ? 1UL : 0UL);
    /* Disable Transmission Delay Compensation by default */
    base->BTDCC &= ~(CANXL_SIC_BTDCC_XTDCEN_MASK | CANXL_SIC_BTDCC_XTDCOFF_MASK);
    SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_14();
}

/*!
 * @brief Enable/disable TDC and TDCM and TDC offset for FD phase
 *
 */
static inline void CanXL_SetTDCOffsetFD(CANXL_SIC_Type * base, boolean TDCEnable, boolean TDCMEnable, uint8 Offset)
{
    SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_10();
    base->BTDCC &= ~(CANXL_SIC_BTDCC_FTDCEN_MASK | CANXL_SIC_BTDCC_FTDMDIS_MASK | CANXL_SIC_BTDCC_FTDCOFF_MASK);
    base->BTDCC |= (CANXL_SIC_BTDCC_FTDCEN(TDCEnable ? 1UL : 0UL) | CANXL_SIC_BTDCC_FTDMDIS(TDCMEnable ? 1UL : 0UL) | CANXL_SIC_BTDCC_FTDCOFF(Offset));
    SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_10();
}

/*!
 * @brief Enable/disable TDC and TDCM and TDC offset for XL phase
 *
 */
static inline void CanXL_SetTDCOffsetXL(CANXL_SIC_Type * base, boolean TDCEnable, boolean TDCMEnable, uint8 Offset)
{
    SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_11();
    base->BTDCC &= ~(CANXL_SIC_BTDCC_XTDCEN_MASK | CANXL_SIC_BTDCC_XTDMDIS_MASK | CANXL_SIC_BTDCC_XTDCOFF_MASK);
    base->BTDCC |= (CANXL_SIC_BTDCC_XTDCEN(TDCEnable ? 1UL : 0UL) | CANXL_SIC_BTDCC_XTDMDIS(TDCMEnable ? 1UL : 0UL) | CANXL_SIC_BTDCC_XTDCOFF(Offset));
    SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_11();
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_GetControllerMRU
 * Description   : This function will handle MRU operation, by read MRU requested value
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static Canexcel_Ip_StatusType Canexcel_GetControllerMRU(uint8 instance, uint32 * pValue, uint8 command)
{
    CANXL_MRU_Type * base = CANEXCEL.EXL_MRU[instance];
    Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    Canexcel_Ip_StatusType status = CANEXCEL_STATUS_SUCCESS;
    uint32 uS2Ticks = OsIf_MicrosToTicks(CANEXCEL_IP_TIMEOUT_DURATION, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < CANXL_SIC_INSTANCE_COUNT);
    DevAssert(pValue != NULL_PTR);
#endif
    CanXL_MruEnable(base);
    /* Check the is available MRU Mailbox */
    if ((base->CHXCONFIG[0u].CH_MBSTAT & CANXL_MRU_CH_MBSTAT_MBS0_MASK) != 0U)
    {
        status = CANEXCEL_STATUS_ERROR;
    }
    if (CANEXCEL_STATUS_SUCCESS == status)
    {
        SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_08();
        base->CHXCONFIG[0u].CH_CFG0 |= CANXL_MRU_CH_CFG0_MBE0_MASK | CANXL_MRU_CH_CFG0_MBE3_MASK | CANXL_MRU_CH_CFG0_IE_MASK;
        base->CHXCONFIG[0u].CH_CFG1 |= CANXL_MRU_CH_CFG1_MBIC3_MASK;
        base->CHXCONFIG[0u].CH_MBSTAT |= CANXL_MRU_CH_MBSTAT_MBS3_MASK;
        state->u8MruMailboxAct &= (uint8)(~(1U<<CANXL_MRU_MBOX3));
        SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_08();
        base->CH1_MB0 = command;
        timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
        while ((state->u8MruMailboxAct & (1U<<CANXL_MRU_MBOX3)) == 0U)
        {
            timeElapsed += OsIf_GetElapsed(&timeStart, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
            if (timeElapsed >= uS2Ticks)
            {
                status = CANEXCEL_STATUS_TIMEOUT;
                break;
            }
        }
        if ((state->u8MruMailboxAct & (1U<<CANXL_MRU_MBOX3)) == (1U<<CANXL_MRU_MBOX3))
        {
            * pValue = base->CH1_MB3;
        }
    }
    CanXL_MruDisable(base);
    return status;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_MainFunction
 * Description   : This function will process in polling Mode an Tx\Rx operation
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static void Canexcel_Ip_MainFunction(uint8 instance, uint8 mb_idx)
{
    Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    uint32 flag_reg;
    uint8 total_mb = (uint8)((((CANEXCEL.EXL_SIC[instance]->SYSMCFG & CANXL_SIC_SYSMCFG_MAXTXMB_MASK) >> CANXL_SIC_SYSMCFG_MAXTXMB_SHIFT) + ((CANEXCEL.EXL_SIC[instance]->SYSMCFG & CANXL_SIC_SYSMCFG_MAXRXMB_MASK) >> CANXL_SIC_SYSMCFG_MAXRXMB_SHIFT)));
    uint8 queue_depth = 0U;
    uint8 CurrentHwIdx = 0U;

    /* Check if instance initialized */
    if ((NULL_PTR != state) && (mb_idx <= total_mb))
    {
        flag_reg = CanXL_GetMsgDescIntStatusFlag(CANEXCEL.EXL_GRP[instance], mb_idx);

        if (0U != flag_reg)
        {
            queue_depth = CanXL_GetMDQueueDepth(CANEXCEL.EXL_GRP[instance], mb_idx) + 1U;
            /* This check ensures that the HwPointer read is always sync with the IFLAG flag.
            * It's necessary because if the IFLAG is set again(a new message received/transmited) just after it was cleared but before read CurrentHwIdx,
            * the new message is consider to be processed(the hwpointer was plus by 1) while IFLAG is still set and the lastHwIdex is equal to CurrentHwIdx
            * so in next time driver will calculate wrongly the no of pointers (consider a roll over)
            * Note: the calculation of number of pointers based on hwpointer will not work in the case of KEEPLST is set because when UNDERUN occurred, the last buffer will be overwite,
            * but the hwpointer will not change(Hw implementation).
            */
            uint8 timeout = 0U;
            do
            {
                CanXL_ClearMsgDescIntStatusFlag(CANEXCEL.EXL_GRP[instance], mb_idx);
                CurrentHwIdx = (uint8)((CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[mb_idx].DCSTA & CANXL_DSC_CONTROL_DCSTA_HWPOINTER_MASK) >> CANXL_DSC_CONTROL_DCSTA_HWPOINTER_SHIFT);
                timeout++;
            } while ((0U != CanXL_GetMsgDescIntStatusFlag(CANEXCEL.EXL_GRP[instance], mb_idx)) && (timeout < queue_depth));
            
            if (CurrentHwIdx > (state->msgDesc[mb_idx].lastHwIdex))
            {
                state->msgDesc[mb_idx].noPointers = CurrentHwIdx - (state->msgDesc[mb_idx].lastHwIdex);
            }
            else
            {
                state->msgDesc[mb_idx].noPointers = queue_depth - (state->msgDesc[mb_idx].lastHwIdex) + CurrentHwIdx;
            }
            /* First descriptors are always allocated for Transmission */
            if (mb_idx <= CANEXCEL.EXL_GRP[instance]->DSCCTRL)
            {
                Canexcel_CompleteTxBuffers(instance, mb_idx, state);
                /* Process Tx MDESC */
                if (NULL_PTR != state->callback)
                {
                    state->callback(instance, CANEXCEL_EVENT_TX_COMPLETE, mb_idx, state);
                }
            }
            else
            {
                ValidateFrameDLC(instance, mb_idx, state);
                /* Process Rx MDESC */
                if (NULL_PTR != state->callback)
                {
                    state->callback(instance, CANEXCEL_EVENT_RX_COMPLETE, mb_idx, state);
                }
            }
            state->msgDesc[mb_idx].lastHwIdex = CurrentHwIdx;
        }
    }
    if ((NULL_PTR != state) && (mb_idx == CANEXCEL_IP_MB_RXFIFO))
    {
        if (1U == CANEXCEL.EXL_RXF_CNT[instance]->RXFSYSACT)
        {
            if ((CANEXCEL.EXL_RXF_CNT[instance]->RXFS & CANXL_RXFIFO_CONTROL_RXFS_RXFF_MASK) != 0U)
            {
                CANEXCEL.EXL_RXF_CNT[instance]->RXFS |= CANXL_RXFIFO_CONTROL_RXFS_RXFF_MASK;
                state->rxFifo.noPointers = (uint8)(((CANEXCEL.EXL_RXF_CNT[instance]->RXFCSTA & CANXL_RXFIFO_CONTROL_RXFCSTA_HWPOINTER_MASK) >> CANXL_RXFIFO_CONTROL_RXFCSTA_HWPOINTER_SHIFT));

                /* Process RxFifo for Reception */
                if (NULL_PTR != state->callback)
                {
                    state->callback(instance, CANEXCEL_EVENT_RXFIFO_COMPLETE, mb_idx, state);
                }
            }
        }
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_InitBaudrate
 * Description   : Init baudrate for given controller.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static void CanXL_InitBaudrate(CANXL_SIC_Type * pBase, const Canexcel_Ip_ConfigType * Canxl_Ip_pData)
{
    CanXL_SetBaudRate(pBase, &Canxl_Ip_pData->bitrate);
    if (Canxl_Ip_pData->fd_enable)
    {
        CanXL_SetFDBaudRate(pBase, &Canxl_Ip_pData->Fd_bitrate);
    }
    if (Canxl_Ip_pData->xl_enable)
    {
        CanXL_SetXLBaudRate(pBase, &Canxl_Ip_pData->Xl_bitrate);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_ConfInit
 * Description   : Partially configure CANEXCEL instance
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static void Canexcel_Ip_ConfInit(uint8 instance, const Canexcel_Ip_ConfigType * Config)
{
  CanXL_SetFDEnabled(CANEXCEL.EXL_SIC[instance], Config->fd_enable, Config->bitRateSwitch);
  CanXL_SetXLEnable(CANEXCEL.EXL_SIC[instance], Config->xl_enable);
  CanXL_InitBaudrate(CANEXCEL.EXL_SIC[instance], Config);
  CanXL_SetOperationMode(CANEXCEL.EXL_SIC[instance], Config->CanxlMode);
  /** To be develop for Queue Operation Config */
  CanXL_SetMDQueueConfigs(CANEXCEL.EXL_GRP[instance], Config->QueueMDConfig);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_InitRxFIFO
 * Description   : Configure Rx FIFO
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static void Canexcel_InitRxFIFO(uint8 instance, const Canexcel_Ip_ConfigType * Config)
{
    uint16 dlcValue = 0u;
    
    CANEXCEL.EXL_RXF_CNT[instance]->RXFC = CANXL_RXFIFO_CONTROL_RXFC_RXFD((uint32)Config->pRxFifoConfig.Rx_Fifo_Depth-1U)|CANXL_RXFIFO_CONTROL_RXFC_RXFWTM((uint32)Config->pRxFifoConfig.Rx_Fifo_Watermark - 1U);
    
    if (CANEXCEL_XL_FRAME == Config->pRxFifoConfig.frameType)
    {
        Canexcel_Ip_apxState[instance]->rxFifo.isXLFrame = TRUE;
        dlcValue = Config->pRxFifoConfig.Rx_Fifo_Msg_Size - 1u;
        const Canexcel_RxXlMsg * RxFifoMsgBuff= (Canexcel_RxXlMsg *)Config->pRxFifoConfig.MsgBuffersPtr;
        for (uint8 idx = 0; idx < Config->pRxFifoConfig.Rx_Fifo_Depth; idx++)
        {
            CANEXCEL.EXL_RXFIFO[instance]->RXFMBP[idx] = (uint32)&RxFifoMsgBuff[idx];
        }
    }
    else
    {
        Canexcel_Ip_apxState[instance]->rxFifo.isXLFrame = FALSE;
        dlcValue = (uint16)CAN_ComputeDLCValue((uint8)(Config->pRxFifoConfig.Rx_Fifo_Msg_Size));
        const Canexcel_RxFdMsg * RxFifoMsgBuff= (Canexcel_RxFdMsg *)Config->pRxFifoConfig.MsgBuffersPtr;
        for (uint8 idx = 0; idx < Config->pRxFifoConfig.Rx_Fifo_Depth; idx++)
        {
            CANEXCEL.EXL_RXFIFO[instance]->RXFMBP[idx] = (uint32)&RxFifoMsgBuff[idx];
        }
    }
    uint8 aux = (Config->pRxFifoConfig.Rx_Fifo_KeepLast == FALSE) ? 1U : 0U;
    CANEXCEL.EXL_RXFIFO[instance]->RXFFCTR = (CANXL_RXFIFO_RXFFCTR_MBSIZE((uint32)dlcValue) | CANXL_RXFIFO_RXFFCTR_KEEPLST((uint32)aux));
    /* Activate RxFifo */
    CANEXCEL.EXL_RXF_CNT[instance]->RXFSYSACT = CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK;
    Canexcel_Ip_apxState[instance]->rxFifo.isPolling = Config->pRxFifoConfig.isPolling;
}
 
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_GetStartMode
 * Description   : Check if the Canexcel instance is STARTED.
 *
 *END**************************************************************************/
/* implements Canexcel_Ip_GetStartMode_Activity */
boolean Canexcel_Ip_GetStartMode(uint8 instance)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < CANXL_SIC_INSTANCE_COUNT);
#endif
    const CANXL_SIC_Type * base = CANEXCEL.EXL_SIC[instance];
    return ((0U == (base->SYSS & CANXL_SIC_SYSS_NTRDY_MASK))? TRUE : FALSE);
}

#if (CANEXCEL_IP_HAS_TS_ENABLE == STD_ON)
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_ConfigTimeStamp
 * Description   : Timestamp configuration
 *
 *END**************************************************************************/
/* implements  Canexcel_Ip_ConfigTimeStamp_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_ConfigTimeStamp(uint8 instance, const Canexcel_Ip_TimeStampConf_Type * time_stamp)
{
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_ERROR;
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < CANXL_SIC_INSTANCE_COUNT);
#endif

    if (TRUE == CanXL_IsFreezeMode(CANEXCEL.EXL_SIC[instance]))
    {
        CanXL_SetTimeStampCaputre(CANEXCEL.EXL_SIC[instance], time_stamp->capture);
        /* If ts64bit True will enable the timestamp as 64 bits if false will set to 32 bits */
        CANEXCEL.EXL_SIC[instance]->BCFG2 |= (TRUE == time_stamp->ts64bit) ? CANXL_SIC_BCFG2_TSS(1U) : CANXL_SIC_BCFG2_TSS(0U);
        returnResult = CANEXCEL_STATUS_SUCCESS;
        CanXL_SetTimeBaseSource(CANEXCEL.EXL_TBS[instance], time_stamp->src);
    }
    return returnResult;
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_SetStopMode
 * Description   : Set the Canexcel instance in STOP mode.
 *
 *END**************************************************************************/
/* implements Canexcel_Ip_SetStopMode_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_SetStopMode(uint8 instance)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < CANXL_SIC_INSTANCE_COUNT);
#endif
    CANXL_SIC_Type * base = CANEXCEL.EXL_SIC[instance];
    Canexcel_Ip_StatusType status;
    status = CanXL_EnterFreezeMode(base);
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_ResetController
 * Description   : Reset controller and put it into freeze mode
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
static Canexcel_Ip_StatusType Canexcel_ResetController(uint8 instance)
{
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = OsIf_MicrosToTicks(CANEXCEL_IP_TIMEOUT_DURATION, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;
    timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);

    /* Wait Hardware to became available after clock start */
    while ((CANEXCEL.EXL_SIC[instance]->SYSS & CANXL_SIC_SYSS_FRZACKF_MASK) == 0U)
    {
        timeElapsed += OsIf_GetElapsed(&timeStart, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
        if (timeElapsed >= uS2Ticks)
        {
            returnResult = CANEXCEL_STATUS_TIMEOUT;
            break;
        }
    }

    if (CANEXCEL_STATUS_SUCCESS == returnResult)
    {
        returnResult = CanXL_SoftReset(CANEXCEL.EXL_SIC[instance]);
    }

    if (CANEXCEL_STATUS_SUCCESS == returnResult)
    {
        returnResult = CanXL_EnterFreezeMode(CANEXCEL.EXL_SIC[instance]);
    }

    return returnResult;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_Init
 * Description   : Initialize the driver with the configuration
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_Init_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_Init(uint8 instance, const Canexcel_Ip_ConfigType * Config, Canexcel_Ip_StateType * pState)
{

  CANEXCEL.EXL_SIC = EXL_SIC_PTR;
  CANEXCEL.EXL_MRU = EXL_MRU_PTR;
  CANEXCEL.EXL_GRP = EXL_GRP_PTR;
  CANEXCEL.EXL_DESC_CTR = EXL_DESC_CTR_PTR;
  CANEXCEL.EXL_MSGD = EXL_MSGD_PTR;
  CANEXCEL.EXL_RXFIFO = EXL_RXFIFO_PTR;
  CANEXCEL.EXL_RXF_CNT = EXL_RXF_CNT_PTR;
  CANEXCEL.EXL_FILTER = EXL_FILTER_PTR;
#if (CANEXCEL_IP_HAS_TS_ENABLE == STD_ON)
  CANEXCEL.EXL_TBS = EXL_TBS_PTR;
#endif
  Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < CANXL_SIC_INSTANCE_COUNT);
    DevAssert(Config != NULL_PTR);
    DevAssert(pState != NULL_PTR);
#endif
  uint8 u8MdCnt = 0U;
  uint8 u8MbCnt = 0U;

  /* Reset and put controller to freeze mode before setting registers */
  returnResult = Canexcel_ResetController(instance);

  if (CANEXCEL_STATUS_SUCCESS == returnResult)
  {
      /* CANEXCEL Data Memory Write Access Enable for Host */
      CANEXCEL.EXL_SIC[instance]->SYSMCFG &= ~CANXL_SIC_SYSMCFG_DRWRDIS_MASK;
      /* Clear Memory ram and initialize it */
      CanXL_ClearRAM(&CANEXCEL, instance);
      CANEXCEL.EXL_GRP[instance]->DSCCTRL = CANXL_GRP_CONTROL_DSCCTRL_TXDSC((uint32)Config->tx_mbdesc-1u);
      CANEXCEL.EXL_SIC[instance]->SYSMCFG |= (CANXL_SIC_SYSMCFG_MAXTXMB(Config->tx_mbdesc) | CANXL_SIC_SYSMCFG_MAXRXMB(Config->rx_mbdesc));
      Canexcel_Ip_ConfInit(instance, Config);

      returnResult = CanXL_ConfigCtrlOptions(CANEXCEL.EXL_SIC[instance], Config->ctrlOptions);
      if (CANEXCEL_STATUS_SUCCESS == returnResult)
      {
        Canexcel_Ip_apxState[instance] = pState;
        for (u8MdCnt = 0U; u8MdCnt<Config->tx_mbdesc; u8MdCnt++)
        {
            /* Better to be moved at init because requires Freeze mode */
            CANEXCEL.EXL_MSGD[instance]->MSGDSC[u8MdCnt].LSTPNT.TXLSTPTR = (uint32)&pState->msgDesc[u8MdCnt].list;
        }
        for (; u8MdCnt < (Config->rx_mbdesc + Config->tx_mbdesc); u8MdCnt++)
        {
            /* Better to be moved at init because requires Freeze mode */
            CANEXCEL.EXL_MSGD[instance]->MSGDSC[u8MdCnt].LSTPNT.RXLSTPTR = (uint32)&pState->msgDesc[u8MdCnt].list;
        }

        if (TRUE == Config->is_rx_fifo_needed)
        {
            Canexcel_InitRxFIFO(instance, Config);
        }
        CanXL_ResetImaskBuff(CANEXCEL.EXL_GRP[instance]);
        /* Clear Callbacks in case of autovariables garbage */
        Canexcel_Ip_apxState[instance]->u8MruMailboxAct = 0U;
        Canexcel_Ip_apxState[instance]->callback = Config->Callback;
        Canexcel_Ip_apxState[instance]->callbackParam = NULL_PTR;
        Canexcel_Ip_apxState[instance]->error_callback = Config->ErrorCallback;
        Canexcel_Ip_apxState[instance]->errorCallbackParam = NULL_PTR;
        Canexcel_Ip_apxState[instance]->isIntActive = FALSE;
        /* Clear all pending flags */
        for (u8MdCnt = 0U; u8MdCnt < CANXL_DSC_CONTROL_DSCMBCTRLAR_COUNT; u8MdCnt++)
        {
            Canexcel_Ip_apxState[instance]->msgDesc[u8MdCnt].lastHwIdex = 0U;
            Canexcel_Ip_apxState[instance]->msgDesc[u8MdCnt].noPointers = 0U;
            for (u8MbCnt = 0U; u8MbCnt < 16U; u8MbCnt++)
            {
                Canexcel_Ip_apxState[instance]->msgDesc[u8MdCnt].isPending[u8MbCnt] = FALSE;
            }
        }
        #if (CANEXCEL_IP_HAS_TS_ENABLE == STD_ON)
        returnResult = Canexcel_Ip_ConfigTimeStamp(instance, &Config->TimestampConfig);
        #endif
      }
  }
  return returnResult;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_SetRxIndividualMask
 * Description   : Set Individual Rx Mask ID for Message Descriptor, and frame type.
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_SetRxIndividualMask_Activity */
void Canexcel_Ip_SetRxIndividualMask(uint8 instance, uint8 descNo, Canexcel_Ip_FrameType frameType, uint32 mask)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < CANXL_SIC_INSTANCE_COUNT);
    DevAssert(descNo < CANXL_DSC_CONTROL_DSCMBCTRLAR_COUNT);
#endif
    if (CANEXCEL_XL_FRAME == frameType)
    {
        CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CFG1.MDFLT1XL = mask;
    }
    else
    {
        CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CFG1.MDFLT1FD = mask;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_ConfigRx
 * Description   : Set Individual Rx ID for Message Descriptor, and config the frame parameters from DataInfoType.
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_ConfigRx_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_ConfigRx(uint8 instance, uint8 descNo, uint32 msgId,const Canexcel_Ip_DataInfoType * info)
{
    uint16 dlcValue = 0U;
    uint32 timeStart = 0U;
    uint32 uS2Ticks = 0U;
    uint32 timeElapsed = 0U;
    Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;

    /* TODO: consider to remove this check */
    if (CanXL_GetDesciptorState(CANEXCEL.EXL_DESC_CTR[instance], descNo) >= CANEXCEL_DESC_STATE_FULL)
    {
        returnResult = CANEXCEL_STATUS_BUSY;
    }

    if (CANEXCEL_STATUS_SUCCESS == returnResult)
    {
        /* Lock the Descriptor before re-configure it  */
        #if (CANEXCEL_IP_HAS_SYSLOCK01 == STD_ON)
        CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK = 1U;
        #else
        (void)CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK;
        #endif

        /* Wait until syslock is retrieved */
        uS2Ticks = OsIf_MicrosToTicks(CANEXCEL_IP_TIMEOUT_DURATION, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
        timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
        while (CANEXCEL_DESCNTSTATUS_LOCKED_SYS != CanXL_GetDescControlStatus(CANEXCEL.EXL_DESC_CTR[instance], descNo))
        {
            timeElapsed += OsIf_GetElapsed(&timeStart, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
            if (timeElapsed >= uS2Ticks)
            {
                returnResult = CANEXCEL_STATUS_TIMEOUT;
                break;
            }
            #if (CANEXCEL_IP_HAS_SYSLOCK01 == STD_ON)
            CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK = 1U;
            #else
            (void)CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK;
            #endif
        }
    }

    if (CANEXCEL_STATUS_SUCCESS == returnResult)
    {
        CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CTRL.RXCTRL = 0U;
        if (info->frame == CANEXCEL_XL_FRAME)
        {
            state->msgDesc[descNo].isXLFrame = TRUE;
            CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CTRL.RXCTRL = CANXL_MSG_DESCRIPTORS_RXCTRL_RXXLFRM_MASK;
            dlcValue = info->dataLength - 1U;
            if (info->idType == CANEXCEL_MSG_ID_EXT)
            {
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
                /* CanXL frame type supports only STD ID frame types */
                DevAssert(FALSE);
#endif
            }
            else
            {
                CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CFG2.MDFLT2XL = (CANXL_MSG_DESCRIPTORS_MDFLT2XL_IDSTDa_H(msgId) |
                                                                            ((info->SEC) ? CANXL_MSG_DESCRIPTORS_MDFLT2XL_SEC(1U) : CANXL_MSG_DESCRIPTORS_MDFLT2XL_SEC(0U)) |
                                                                            CANXL_MSG_DESCRIPTORS_MDFLT2XL_RJCT_SDU(info->SDT) |
                                                                            CANXL_MSG_DESCRIPTORS_MDFLT2XL_RJCT_VCAN(info->VCID));
            }
        }
        else if (CANEXCEL_FD_FRAME == info->frame)
        {
            state->msgDesc[descNo].isXLFrame = FALSE;
            CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CTRL.RXCTRL = CANXL_MSG_DESCRIPTORS_RXCTRL_RXFDFRM_MASK;
            dlcValue = (uint16)CAN_ComputeDLCValue((uint8)(info->dataLength));
            if (CANEXCEL_MSG_ID_EXT == info->idType)
            {
                CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CFG2.MDFLT2FD = CANXL_MSG_DESCRIPTORS_MDFLT2FD_IDE_MASK | msgId;
            }
            else
            {
                CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CFG2.MDFLT2FD = CANXL_MSG_DESCRIPTORS_MDFLT2FD_IDSTDa_H(msgId);
            }
        }
        else
        {
            /* expected Classic Frame Type */
            state->msgDesc[descNo].isXLFrame = FALSE;
            dlcValue = (uint16)CAN_ComputeDLCValue((uint8)(info->dataLength));
            if (CANEXCEL_MSG_ID_EXT == info->idType)
            {
                CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CFG2.MDFLT2FD = CANXL_MSG_DESCRIPTORS_MDFLT2FD_IDE_MASK | msgId;
            }
            else
            {
                CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CFG2.MDFLT2FD = CANXL_MSG_DESCRIPTORS_MDFLT2FD_IDSTDa_H(msgId);
            }
        }
        SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_03();
        CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CTRL.RXCTRL |= CANXL_MSG_DESCRIPTORS_RXCTRL_MBSIZE(dlcValue);
        SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_03();

        /* Activate the Descriptor */
        CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCACT = 1U;

        /* Release System lock in order to read to receive */
        #if (CANEXCEL_IP_HAS_SYSLOCK01 == STD_ON)
        CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK = 0U;
        #else
        CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK = 1U;
        #endif
    }
    return returnResult;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_RxDescriptor
 * Description   : Push the new memory location for the Rx Message Buffer on the desired Descriptor.
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_RxDescriptor_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_RxDescriptor(uint8 instance, uint8 descNo, uint32 rxPtrList)
{
    Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;
    uint8 Active = 0U;
    boolean bSysLock = FALSE;

#if (CANEXCEL_IP_FEATURE_HAS_MSGDESC_RXCTRL_MODE == (STD_ON))
    /* Check if previous was called the ConfigRx API, the MODE bit was cleared and Descriptor was ACTIVE and release system lock  */
    if (CANXL_MSG_DESCRIPTORS_RXCTRL_MODE_MASK == (CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CTRL.RXCTRL & CANXL_MSG_DESCRIPTORS_RXCTRL_MODE_MASK))
    {
        returnResult = CANEXCEL_STATUS_ERROR;
    }
    else
#endif
    {
        Active = (uint8)(CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCACT & CANXL_DSC_CONTROL_DCACT_ACT_MASK);
        bSysLock = (CANEXCEL_DESCNTSTATUS_LOCKED_SYS == CanXL_GetDescControlStatus(CANEXCEL.EXL_DESC_CTR[instance], descNo)) ? TRUE : FALSE;

        /* Push without syslock and the descriptor must be activated first, require to call ConfigRx first */
        if ((1U == Active) && (FALSE == bSysLock))
        {
            /* Check if the descriptor is empty, notfull or inactive */
            if (CanXL_GetDesciptorState(CANEXCEL.EXL_DESC_CTR[instance], descNo) <= CANEXCEL_DESC_STATE_NOTFULL)
            {
                uint8 noOfPtrList = (uint8)((CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSTA & CANXL_DSC_CONTROL_DCSTA_SYSPOINTER_MASK) >> CANXL_DSC_CONTROL_DCSTA_SYSPOINTER_SHIFT);
                
                if (noOfPtrList >= (CanXL_GetMDQueueDepth(CANEXCEL.EXL_GRP[instance], descNo)+1U))
                {
                    /* Roll Over */
                    noOfPtrList = 0U;
                }
                /* The buffer must be processed in MainFunction/ISR before using it */
                if (FALSE == state->msgDesc[descNo].isPending[noOfPtrList])
                {
                    state->msgDesc[descNo].isPending[noOfPtrList] = TRUE;
                    state->msgDesc[descNo].list[noOfPtrList] = rxPtrList;
                    CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSPUSH = 0U;
                }
                else
                {
                    returnResult = CANEXCEL_STATUS_ERROR;
                }
            }
            else
            {
                returnResult = CANEXCEL_STATUS_ERROR;
            }
        }
        else
        {
            returnResult = CANEXCEL_STATUS_ERROR;
        }
    }
    return returnResult;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_ReceiveFD
 * Description   : Receive a Classic or FD CAN Format Message
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_ReceiveFD_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_ReceiveFD(uint8 instance, uint8 descNo, const Canexcel_RxFdMsg * RxMsg, boolean isPolling)
{
    Canexcel_Ip_StatusType returnResult;
    returnResult = Canexcel_Ip_RxDescriptor(instance, descNo, (uint32)&RxMsg->Header.Id);
    if ((CANEXCEL_STATUS_SUCCESS == returnResult) && (FALSE == isPolling))
    {
        CanXL_SetMsgBuffIntCmd(CANEXCEL.EXL_GRP[instance], descNo);
    }
    return returnResult;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_ReceiveXL
 * Description   : Receive a CAN XL Format Message
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_ReceiveXL_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_ReceiveXL(uint8 instance, uint8 descNo, const Canexcel_RxXlMsg * RxMsg, boolean isPolling)
{
    Canexcel_Ip_StatusType returnResult;
    returnResult = Canexcel_Ip_RxDescriptor(instance, descNo, (uint32)&RxMsg->Header.Id);
    if ((CANEXCEL_STATUS_SUCCESS == returnResult) && (FALSE == isPolling))
    {
        CanXL_SetMsgBuffIntCmd(CANEXCEL.EXL_GRP[instance], descNo);
    }
    return returnResult;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_TxDescriptor
 * Description   : Push the new memory location for the Tx Message Buffer on the desired Descriptor.
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_TxDescriptor_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_TxDescriptor(uint8 instance, uint8 descNo, uint32 txPtrList)
{
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;
    uint32 uS2Ticks = OsIf_MicrosToTicks(CANEXCEL_IP_TIMEOUT_DURATION, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
    /* Ensure that the buffer given was already configured by Canexcel_Ip_ConfigXlTx/Canexcel_Ip_ConfigFdTx before start the transmission */
    if (0U == ((((Canexcel_TxMsgHeaderType *)txPtrList)->word2) & CANXL_TX_HEADER_MODE_MASK))
    {
        returnResult = CANEXCEL_STATUS_ERROR;
    }
    else
    {
        /* Set system lock Status */
        #if (CANEXCEL_IP_HAS_SYSLOCK01 == STD_ON)
        CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK = 1U;
        #else
        (void)CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK;
        #endif
        timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
        while (CANEXCEL_DESCNTSTATUS_LOCKED_HW == CanXL_GetDescControlStatus(CANEXCEL.EXL_DESC_CTR[instance], descNo))
        {
            timeElapsed += OsIf_GetElapsed(&timeStart, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
            if (timeElapsed >= uS2Ticks)
            {
                returnResult = CANEXCEL_STATUS_TIMEOUT;
                break;
            }
        }
        if (CANEXCEL_STATUS_SUCCESS == returnResult)
        {
            /* Check if the descriptor is empty, notfull or inactive */
            if (CanXL_GetDesciptorState(CANEXCEL.EXL_DESC_CTR[instance], descNo) <= CANEXCEL_DESC_STATE_NOTFULL)
            {
                uint8 noOfPtrList = (uint8)((CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSTA & CANXL_DSC_CONTROL_DCSTA_SYSPOINTER_MASK) >> CANXL_DSC_CONTROL_DCSTA_SYSPOINTER_SHIFT);
                
                if (noOfPtrList >= (CanXL_GetMDQueueDepth(CANEXCEL.EXL_GRP[instance], descNo)+1U))
                {
                    /* Roll Over */
                    noOfPtrList = 0U;
                }
                /* The buffer must be processed in MainFunction/ISR before using it */
                if (FALSE == state->msgDesc[descNo].isPending[noOfPtrList])
                {
                    state->msgDesc[descNo].isPending[noOfPtrList] = TRUE;
                    state->msgDesc[descNo].list[noOfPtrList] = txPtrList;
                    CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCACT = 1U;
                    #if (CANEXCEL_IP_HAS_SYSLOCK01 == STD_ON)
                    CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK = 0U;
                    #else
                    CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK = 1U;
                    #endif
                    CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSPUSH = 0U;
                }
                else
                {
                    returnResult = CANEXCEL_STATUS_ERROR;
                }
            }
            else
            {
                returnResult = CANEXCEL_STATUS_ERROR;
            }
        }
    }

    return returnResult;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_ConfigXlTx
 * Description   : Config the MessageBuffer for Tx with CAN XL Format and the desired parameters from DataInfoType
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_ConfigXlTx_Activity */
void Canexcel_Ip_ConfigXlTx(uint8 instance, uint8 mbIdx, uint32 id,const Canexcel_Ip_DataInfoType * info, Canexcel_TxXlMsgType * TxMsg)
{
    Canexcel_Ip_apxState[instance]->msgDesc[mbIdx].isXLFrame = TRUE;
    TxMsg->Header.timeStampL = 0U;
    TxMsg->Header.timeStampL = 0U;
    TxMsg->Header.word3 = 0U;
    TxMsg->Header.word2 = 0U;
    TxMsg->Header.word4 = 0U;
    TxMsg->Header.word2 = CANXL_TX_HEADER_MODE_MASK | (((uint32)info->priority << CANXL_TX_HEADER_PRIO_SHIFT) & CANXL_TX_HEADER_PRIO_MASK)
                       | (((uint32)info->retransmission << CANXL_TX_HEADER_RETR_SHIFT) & CANXL_TX_HEADER_RETR_MASK);
    if (CANEXCEL_MSG_ID_EXT == info->idType)
    {
        TxMsg->Header.word3 = CANXL_TX_HEADER_IDE_MASK | (id & CANXL_IP_ID_EXT_MASK) | CANXL_TX_HEADER_XLF_MASK;
    }
    else
    {
        TxMsg->Header.word3 = ((id << CANXL_IP_ID_STD_SHIFT) & CANXL_IP_ID_STD_MASK) | CANXL_TX_HEADER_XLF_MASK;
    }
    TxMsg->Header.word4 = (CANXL_TX_HEADER_FDF_MASK | ((((uint32)info->dataLength - 1u) << CANXL_TX_HEADER_DLC_SHIFT) & CANXL_TX_HEADER_DLC_MASK)) | (((uint32)info->SDT << CANXL_TX_HEADER_SDT_SHIFT)&CANXL_TX_HEADER_SDT_MASK);
    TxMsg->Header.word4 |= info->VCID;
    TxMsg->AF = info->AF;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_ConfigFdTx
 * Description   : Config the MessageBuffer for Tx with CAN FD Format and the desired parameters from DataInfoType
 *
 *END**************************************************************************/
static void Canexcel_Ip_ConfigFdTx(uint8 instance, uint8 mbIdx, uint32 id,const Canexcel_Ip_DataInfoType * info, Canexcel_TxFdMsgType * TxMsg)
{
    Canexcel_Ip_apxState[instance]->msgDesc[mbIdx].isXLFrame = FALSE;
    uint16 dlcValue = 0U;
    TxMsg->Header.timeStampL = 0U;
    TxMsg->Header.timeStampL = 0U;
    TxMsg->Header.word3 = 0U;
    TxMsg->Header.word2 = 0U;
    TxMsg->Header.word4 = 0U;
    TxMsg->Header.word2 = CANXL_TX_HEADER_MODE_MASK | (((uint32)info->priority << CANXL_TX_HEADER_PRIO_SHIFT) & CANXL_TX_HEADER_PRIO_MASK)
                       | (((uint32)info->retransmission << CANXL_TX_HEADER_RETR_SHIFT) & CANXL_TX_HEADER_RETR_MASK);
    if (CANEXCEL_MSG_ID_EXT == info->idType)
    {
        TxMsg->Header.word3 = CANXL_TX_HEADER_IDE_MASK | (id & CANXL_IP_ID_EXT_MASK);
    }
    else
    {
        TxMsg->Header.word3 = ((id << CANXL_IP_ID_STD_SHIFT) & CANXL_IP_ID_STD_MASK);
    }

    dlcValue = (uint16)CAN_ComputeDLCValue((uint8)(info->dataLength));
    if (CANEXCEL_FD_FRAME == info->frame)
    {
        if (TRUE == info->enable_brs)
        {
            TxMsg->Header.word4 = CANXL_TX_HEADER_BRS_MASK | CANXL_TX_HEADER_FDF_MASK | (((uint32)dlcValue << CANXL_TX_HEADER_DLC_SHIFT) & CANXL_TX_HEADER_DLC_MASK);
        }
        else
        {
            TxMsg->Header.word4 = CANXL_TX_HEADER_FDF_MASK | (((uint32)dlcValue << CANXL_TX_HEADER_DLC_SHIFT) & CANXL_TX_HEADER_DLC_MASK);
        }
    }
    else
    {
        TxMsg->Header.word4 = (((uint32)dlcValue << CANXL_TX_HEADER_DLC_SHIFT) & CANXL_TX_HEADER_DLC_MASK);
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_SendFDMsg
 * Description   : Send a CAN Classic or FD Format Message
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_SendFDMsg_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_SendFDMsg(uint8 instance, uint8 mbIdx,const Canexcel_Ip_DataInfoType * info, uint32 id,const uint8 * dataPtr, Canexcel_TxFdMsgType * TxMsg)
{
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_ERROR;

    if (!CanXL_IsListenOnlyModeEnabled(CANEXCEL.EXL_SIC[instance]))
    {
        if (FALSE == CanXL_IsPwmModeEnable(CANEXCEL.EXL_SIC[instance]))
        {
            Canexcel_Ip_ConfigFdTx(instance, mbIdx, id, info, TxMsg);
            CanXL_SetTxMsgBuffData(info, dataPtr, (uint8 *)&TxMsg->data[0]);
            if (FALSE == info->is_polling)
            {
                CanXL_SetMsgBuffIntCmd(CANEXCEL.EXL_GRP[instance], mbIdx);
            }
            returnResult = Canexcel_Ip_TxDescriptor(instance, mbIdx, (uint32)&TxMsg->Header.timeStampL);
        }
    }
    return returnResult;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_SendXLMsg
 * Description   : Send a CAN XL Format Message
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_SendXLMsg_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_SendXLMsg(uint8 instance, uint8 mbIdx,const Canexcel_Ip_DataInfoType * info, uint32 id,const uint8 * dataPtr, Canexcel_TxXlMsgType * TxMsg)
{
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_ERROR;
    if (!CanXL_IsListenOnlyModeEnabled(CANEXCEL.EXL_SIC[instance]))
    {
        Canexcel_Ip_ConfigXlTx(instance, mbIdx, id, info, TxMsg);
        CanXL_SetTxMsgBuffData(info, dataPtr, (uint8 *)&TxMsg->data[0]);
        if (FALSE == info->is_polling)
        {
            CanXL_SetMsgBuffIntCmd(CANEXCEL.EXL_GRP[instance], mbIdx);
        }
        returnResult = Canexcel_Ip_TxDescriptor(instance, mbIdx, (uint32)&TxMsg->Header.timeStampL);
    }
    return returnResult;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_GetTransferStatus
 * Description   : Check the status transfer for a Message Descriptor
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_GetTransferStatus_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_GetTransferStatus(uint8 instance, uint8 descIdx)
{
        Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_NO_TRANSFER_IN_PROGRESS;
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(descIdx < CANXL_DSC_CONTROL_DSCMBCTRLAR_COUNT);
    DevAssert(instance < CANXL_SIC_INSTANCE_COUNT);
#endif
    /* Check if the descriptor is active */
    if (CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descIdx].DCACT == CANXL_DSC_CONTROL_DCACT_ACT_MASK)
    {
        if (0U == CanXL_GetMDQueueDepth(CANEXCEL.EXL_GRP[instance], descIdx))
        {
            /* In case of MD Queue depth = 0 */
            if (CANEXCEL_DESC_STATE_EMPTY == CanXL_GetDesciptorState(CANEXCEL.EXL_DESC_CTR[instance], descIdx))
            {
                returnResult = CANEXCEL_STATUS_SUCCESS;
            }
            if (CANEXCEL_DESC_STATE_FULL == CanXL_GetDesciptorState(CANEXCEL.EXL_DESC_CTR[instance], descIdx))
            {
                returnResult = CANEXCEL_STATUS_BUSY;
            }
        }
        else
        {
            if (CanXL_GetDesciptorHWIndex(CANEXCEL.EXL_DESC_CTR[instance], descIdx) == CanXL_GetDesciptorSysIndex(CANEXCEL.EXL_DESC_CTR[instance], descIdx))
            {
                returnResult = CANEXCEL_STATUS_SUCCESS;
            }
            else
            {
                returnResult = CANEXCEL_STATUS_BUSY;
            }
        }
        if (CANEXCEL_DESC_STATE_OVERRUN == CanXL_GetDesciptorState(CANEXCEL.EXL_DESC_CTR[instance], descIdx))
        {
            returnResult = CANEXCEL_STATUS_ERROR;
        }
    }
    return returnResult;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_EnterFreezeMode
 * Description   : Set the HW in FreezeMode
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_EnterFreezeMode_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_EnterFreezeMode(uint8 instance)
{
    return CanXL_EnterFreezeMode(CANEXCEL.EXL_SIC[instance]);
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_ExitFreezeMode
 * Description   : Set the HW in normal Run Mode
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_ExitFreezeMode_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_ExitFreezeMode(uint8 instance)
{
    return CanXL_ExitFreezeMode(CANEXCEL.EXL_SIC[instance]);
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_EnableInterrupts
 * Description   : Enable CanExcel Instance Interrupts
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_EnableInterrupts_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_EnableInterrupts(uint8 u8Instance)
{
    Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[u8Instance];
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_ERROR;

    if (TRUE == CanXL_IsFreezeMode(CANEXCEL.EXL_SIC[u8Instance]))
    {
        CanXL_EnableInterrupts(CANEXCEL.EXL_SIC[u8Instance]);
        if ((CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK == (CANEXCEL.EXL_RXF_CNT[u8Instance]->RXFSYSACT & CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK)) && (FALSE == Canexcel_Ip_apxState[u8Instance]->rxFifo.isPolling))
        {
            /* Activate RxFifo Interrupts */
            CANEXCEL.EXL_RXF_CNT[u8Instance]->RXFIEN = CANXL_RXFIFO_CONTROL_RXFIEN_RXFIE_MASK | CANXL_RXFIFO_CONTROL_RXFIEN_RXFEIE_MASK;
        }
        state->isIntActive = TRUE;
        returnResult = CANEXCEL_STATUS_SUCCESS;
    }

    return returnResult;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_DisableInterrupts
 * Description   : Disable CanExcel Instance Interrupts
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_DisableInterrupts_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_DisableInterrupts(uint8 u8Instance)
{
    Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[u8Instance];
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_ERROR;

    if (TRUE == CanXL_IsFreezeMode(CANEXCEL.EXL_SIC[u8Instance]))
    {
        CanXL_DisableInterrupts(CANEXCEL.EXL_SIC[u8Instance]);
        if (((CANEXCEL.EXL_RXF_CNT[u8Instance]->RXFSYSACT & CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK) == CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK) && (FALSE == Canexcel_Ip_apxState[u8Instance]->rxFifo.isPolling))
        {
            /* Clear RxFifo Interrupts */
            CANEXCEL.EXL_RXF_CNT[u8Instance]->RXFIEN = ~(CANXL_RXFIFO_CONTROL_RXFIEN_RXFIE_MASK | CANXL_RXFIFO_CONTROL_RXFIEN_RXFEIE_MASK);
        }
        state->isIntActive = FALSE;
        returnResult = CANEXCEL_STATUS_SUCCESS;
    }
    return returnResult;
}
static void ValidateFrameDLC(uint8 instance,uint32 mb_idx, Canexcel_Ip_StateType * state)
{
    uint8 i = 0U;
    uint8 bufferIdx = 0U;
    uint16 dlcValueConfig = (uint16)(CANEXCEL.EXL_MSGD[instance]->MSGDSC[mb_idx].CTRL.RXCTRL & CANXL_MSG_DESCRIPTORS_RXCTRL_MBSIZE_MASK)  >> CANXL_MSG_DESCRIPTORS_RXCTRL_MBSIZE_SHIFT;
    
    bufferIdx = state->msgDesc[mb_idx].lastHwIdex;
    do
    {
        if (bufferIdx > CanXL_GetMDQueueDepth(CANEXCEL.EXL_GRP[instance], (uint8)mb_idx))
        {
            bufferIdx = 0U;
        }
        Canexcel_RxHeader * RxHeader = (Canexcel_RxHeader *)state->msgDesc[mb_idx].list[bufferIdx];
        uint16 dlcValue = (uint16)(RxHeader->Control & CANXL_TX_HEADER_DLC_MASK) >> CANXL_TX_HEADER_DLC_SHIFT;
        if(dlcValue > dlcValueConfig)
        {
            /* Clear priveous value of DLC */
            RxHeader->Control &= ~CANXL_TX_HEADER_DLC_MASK;
            /* Set the truncated value of the frame as DLC */
            RxHeader->Control |= ((uint32)dlcValueConfig << CANXL_TX_HEADER_DLC_SHIFT) & CANXL_TX_HEADER_DLC_MASK;
        }
        /* The Buffer was processed, ready to be used */
        state->msgDesc[mb_idx].isPending[bufferIdx] = FALSE;
        i++;
        bufferIdx++;
    } while (i < (state->msgDesc[mb_idx].noPointers));
}

/* This function will set MODE field of all buffers completed transfering to 0 */
static void Canexcel_CompleteTxBuffers(uint8 instance,uint32 mb_idx, Canexcel_Ip_StateType * state)
{
    uint8 i = 0U;
    uint8 bufferIdx = 0U;
    Canexcel_TxMsgHeaderType * TxHeader = NULL_PTR;

    bufferIdx = state->msgDesc[mb_idx].lastHwIdex;
    do
    {
        if (bufferIdx > CanXL_GetMDQueueDepth(CANEXCEL.EXL_GRP[instance], (uint8)mb_idx))
        {
            bufferIdx = 0U;
        }
        TxHeader = (Canexcel_TxMsgHeaderType *)state->msgDesc[mb_idx].list[bufferIdx];
        /* */
        TxHeader->word2 &= ~CANXL_TX_HEADER_MODE_MASK;
        /* The Buffer was processed, ready to be used */
        state->msgDesc[mb_idx].isPending[bufferIdx] = FALSE;
        i++;
        bufferIdx++;
    } while (i < (state->msgDesc[mb_idx].noPointers));
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_RxTxIRQHandler
 * Description   : IrqHandler for Rx\Tx and RxFIFO
 *
 *END**************************************************************************/
/* implements CAN_X_MB_Y_ISR_Activity */
void Canexcel_Ip_RxTxIRQHandler(uint8 instance)
{
    Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    uint32 flag_reg;
    uint32 mb_idx = 0U;
    uint8 total_mb = (uint8)((((CANEXCEL.EXL_SIC[instance]->SYSMCFG & CANXL_SIC_SYSMCFG_MAXTXMB_MASK) >> CANXL_SIC_SYSMCFG_MAXTXMB_SHIFT) + ((CANEXCEL.EXL_SIC[instance]->SYSMCFG & CANXL_SIC_SYSMCFG_MAXRXMB_MASK) >> CANXL_SIC_SYSMCFG_MAXRXMB_SHIFT)));
    uint8 CurrentHwIdx = 0U;
    uint8 queue_depth = 0U;

    /* Check if instance initialized */
    if (NULL_PTR != state)
    {
        flag_reg = CanXL_GetMsgBuffIntStatusFlag(CANEXCEL.EXL_GRP[instance], mb_idx);
        while ((0U == flag_reg) && (mb_idx < total_mb))
        {
            mb_idx++;
            flag_reg = CanXL_GetMsgBuffIntStatusFlag(CANEXCEL.EXL_GRP[instance], mb_idx);
        }

        if (0U != flag_reg)
        {
            queue_depth = CanXL_GetMDQueueDepth(CANEXCEL.EXL_GRP[instance], (uint8)mb_idx) + 1U;
            /* This check ensures that the HwPointer read is always sync with the IFLAG flag.
            * It's necessary because if the IFLAG is set again(a new message received/transmited) just after it was cleared but before read CurrentHwIdx,
            * the new message is consider to be processed(the hwpointer was plus by 1) while IFLAG is still set and the lastHwIdex is equal to CurrentHwIdx
            * so in next time driver will calculate wrongly the no of pointers (consider a roll over)
            * Note: the calculation of number of pointers based on hwpointer will not work in the case of KEEPLST is set because when UNDERUN occurred, the last buffer will be overwite,
            * but the hwpointer will not change(Hw implementation).
            */
            uint8 timeout = 0U;
            do
            {
                CanXL_ClearMsgDescIntStatusFlag(CANEXCEL.EXL_GRP[instance], mb_idx);
                CurrentHwIdx = (uint8)((CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[mb_idx].DCSTA & CANXL_DSC_CONTROL_DCSTA_HWPOINTER_MASK) >> CANXL_DSC_CONTROL_DCSTA_HWPOINTER_SHIFT);
                timeout++;
            } while ((0U != CanXL_GetMsgDescIntStatusFlag(CANEXCEL.EXL_GRP[instance], mb_idx)) && (timeout < queue_depth));

            if (CurrentHwIdx > (state->msgDesc[mb_idx].lastHwIdex))
            {
                state->msgDesc[mb_idx].noPointers = CurrentHwIdx - (state->msgDesc[mb_idx].lastHwIdex);
            }
            else
            {
                state->msgDesc[mb_idx].noPointers = queue_depth - (state->msgDesc[mb_idx].lastHwIdex) + CurrentHwIdx;
            }
            /* First descriptors are always allocated for Transmission */
            if (mb_idx <= CANEXCEL.EXL_GRP[instance]->DSCCTRL)
            {
                Canexcel_CompleteTxBuffers(instance, mb_idx, state);
                /* Process Tx MDESC */
                if (NULL_PTR != state->callback)
                {
                    state->callback(instance, CANEXCEL_EVENT_TX_COMPLETE, mb_idx, state);
                }
            }
            else
            {
                ValidateFrameDLC(instance, mb_idx, state);
                /* Process Rx MDESC */
                if (NULL_PTR != state->callback)
                {
                    state->callback(instance, CANEXCEL_EVENT_RX_COMPLETE, mb_idx, state);
                }
            }
            state->msgDesc[mb_idx].lastHwIdex = CurrentHwIdx;
        }
        if (CANEXCEL.EXL_RXF_CNT[instance]->RXFSYSACT == 1U)
        {
            if (((CANEXCEL.EXL_RXF_CNT[instance]->RXFIEN & CANXL_RXFIFO_CONTROL_RXFIEN_RXFIE_MASK) != 0U) &&  ((CANEXCEL.EXL_RXF_CNT[instance]->RXFS & CANXL_RXFIFO_CONTROL_RXFS_RXFF_MASK) != 0U))
            {
                /* Clear the fifo flag */
              CANEXCEL.EXL_RXF_CNT[instance]->RXFS = CANXL_RXFIFO_CONTROL_RXFS_RXFF_MASK;
              /* Process RxFifo for Reception */
              if (NULL_PTR != state->callback)
              {
                  state->callback(instance, CANEXCEL_EVENT_RXFIFO_COMPLETE, CANEXCEL_IP_MB_RXFIFO, state);
              }
            }
        }
    }
    else
    {
        for (mb_idx=0U; mb_idx<CANXL_DSC_CONTROL_DSCMBCTRLAR_COUNT; mb_idx++)
        {
            CanXL_ClearMsgDescIntStatusFlag(CANEXCEL.EXL_GRP[instance], mb_idx);
        }
        /* Clear the fifo flag */
        CANEXCEL.EXL_RXF_CNT[instance]->RXFS = CANXL_RXFIFO_CONTROL_RXFS_RXFF_MASK;
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_ProcessErrIRQ
 * Description   : This is a function in order to reduce CCM of Canexcel_Ip_ErrIRQHandler
 *
 *END**************************************************************************/
static void Canexcel_ProcessErrIRQ(uint8 instance, const Canexcel_Ip_StateType * state, uint32 bcanXlStatus, uint32 sysStatus)
{
    if (CANXL_SIC_SYSIE_CERRIE_MASK == ((CANEXCEL.EXL_SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CERRIE_MASK) & sysStatus))
    {
        CANEXCEL.EXL_SIC[instance]->SYSS = CANXL_SIC_SYSS_CERR_MASK;
        /* Check if callback is registered */
        if (NULL_PTR != state->error_callback)
        {
            state->error_callback(instance, CANEXCEL_EVENT_ERROR, bcanXlStatus, state);
        }
    }
    if (CANXL_SIC_SYSIE_CFDPERRIE_MASK == ((CANEXCEL.EXL_SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CFDPERRIE_MASK) & sysStatus))
    {
        CANEXCEL.EXL_SIC[instance]->SYSS = CANXL_SIC_SYSS_CFDPERR_MASK;
        if (NULL_PTR != state->error_callback)
        {
            state->error_callback(instance, CANEXCEL_EVENT_ERROR_FD, bcanXlStatus, state);
        }
    }
    if (CANXL_SIC_SYSIE_CRXWRNIE_MASK == ((CANEXCEL.EXL_SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CRXWRNIE_MASK) & sysStatus))
    {
        CANEXCEL.EXL_SIC[instance]->SYSS = CANXL_SIC_SYSS_CRXWRN_MASK;
        if (NULL_PTR != state->error_callback)
        {
            state->error_callback(instance, CANEXCEL_EVENT_RX_WARNING, bcanXlStatus, state);
        }
    }
    if (CANXL_SIC_SYSIE_CTXWRNIE_MASK == ((CANEXCEL.EXL_SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CTXWRNIE_MASK) & sysStatus))
    {
        CANEXCEL.EXL_SIC[instance]->SYSS = CANXL_SIC_SYSS_CTXWRN_MASK;
        if (NULL_PTR != state->error_callback)
        {
            state->error_callback(instance, CANEXCEL_EVENT_TX_WARNING, bcanXlStatus, state);
        }
    }
    if (CANXL_SIC_SYSIE_CDPERRIE_MASK == ((CANEXCEL.EXL_SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CDPERRIE_MASK) & sysStatus))
    {
        CANEXCEL.EXL_SIC[instance]->SYSS = CANXL_SIC_SYSS_CXDPERR_MASK;
        if (NULL_PTR != state->error_callback)
        {
            state->error_callback(instance, CANEXCEL_EVENT_ERROR_XL, bcanXlStatus, state);
        }
    }
    if (CANXL_SIC_SYSIE_CPERRIE_MASK == ((CANEXCEL.EXL_SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CPERRIE_MASK) & sysStatus))
    {
        CANEXCEL.EXL_SIC[instance]->SYSS = CANXL_SIC_SYSS_CPASERR_MASK;
        if (NULL_PTR != state->error_callback)
        {
            state->error_callback(instance, CANEXCEL_EVENT_PASSIVE, bcanXlStatus, state);
        }
    }
    if (CANXL_SIC_SYSIE_CBOFFIE_MASK == ((CANEXCEL.EXL_SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CBOFFIE_MASK) & sysStatus))
    {
        CANEXCEL.EXL_SIC[instance]->SYSS = CANXL_SIC_SYSS_CBOFF_MASK;
        if (NULL_PTR != state->error_callback)
        {
            state->error_callback(instance, CANEXCEL_EVENT_BUSOFF, bcanXlStatus, state);
        }
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_ErrIRQHandler
 * Description   : IrqHandler for Errors
 *
 *END**************************************************************************/
/* implements  CAN_X_BUSOFF_ERROR_ISR_Activity */
void Canexcel_Ip_ErrIRQHandler(uint8 instance)
{
    const Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    uint32 sysStatus = CANEXCEL.EXL_SIC[instance]->SYSS;
    uint32 bcanXlStatus = 0U;
    /* Process CANEXCEL Error */
    if (NULL_PTR != state)
    {
        if (CANEXCEL_STATUS_SUCCESS == Canexcel_GetControllerMRU(instance, &bcanXlStatus, CANXL_MRU_CMD_LAST_ST))
        {
           Canexcel_ProcessErrIRQ(instance, state, bcanXlStatus, sysStatus);
        }
    }
    else
    {
        /* Clear all errors */
        CANEXCEL.EXL_SIC[instance]->SYSS = CANEXCEL_IP_SYSS_CLEAR_DEFAULT_VALUE_U32;
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_MruIRQHandler
 * Description   : IrqHandler for MRU service unit
 *
 *END**************************************************************************/
void Canexcel_Ip_MruIRQHandler(uint8 instance)
{
    CANXL_MRU_Type * base = CANEXCEL.EXL_MRU[instance];
    Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    uint8 mbIdx = 0u;
    uint32 mask = 0u;
    if (NULL_PTR != state)
    {
        if (CANXL_MRU_CH_CFG0_IE_MASK == (base->CHXCONFIG[0u].CH_CFG0 & CANXL_MRU_CH_CFG0_IE_MASK))
        {
            for (;mbIdx < CANXL_IP_MRU_MAILBOX_NO; mbIdx++)
            {
                uint32 tmp = base->CHXCONFIG[0u].CH_CFG1;
                mask = (uint32)(tmp & ((uint32)1U << ((uint32)mbIdx + (uint32)CANXL_MRU_CH_MBSTAT_MBS0_SHIFT)));
                if ((base->CHXCONFIG[0u].CH_MBSTAT & mask) != 0U)
                {
                    SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_09();
                    state->u8MruMailboxAct |= (1U<<mbIdx);
                    base->CHXCONFIG[0u].CH_MBSTAT |= mask;
                    SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_09();
                }
            }
        }
    }
    else
    {
        base->CHXCONFIG[0u].CH_MBSTAT = CANEXCEL_IP_CH1_MBSTAT_CLEAR_DEFAULT_VALUE_U32;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_SetErrorInt
 * Description   : Enable\Disable Error or BusOff Interrupt
 *
 *END**************************************************************************/
/* implements Canexcel_Ip_SetErrorInt_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_SetErrorInt(uint8 u8Instance, Canexcel_Ip_ErrorIntType type, boolean enable)
{
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_ERROR;
    if (TRUE == CanXL_IsFreezeMode(CANEXCEL.EXL_SIC[u8Instance]))
    {
        switch (type)
        {
        case CANEXCEL_IP_INT_RX_WARNING:
        {
            CanXL_SetErrIntCmd(CANEXCEL.EXL_SIC[u8Instance], CANXL_INT_RX_WARNING, enable);
            returnResult = CANEXCEL_STATUS_SUCCESS;
            break;
        }
        case CANEXCEL_IP_INT_TX_WARNING:
        {
            CanXL_SetErrIntCmd(CANEXCEL.EXL_SIC[u8Instance], CANXL_INT_TX_WARNING, enable);
            returnResult = CANEXCEL_STATUS_SUCCESS;
            break;
        }
        case CANEXCEL_IP_INT_ERR:
        {
            CanXL_SetErrIntCmd(CANEXCEL.EXL_SIC[u8Instance], CANXL_INT_ERR, enable);
            returnResult = CANEXCEL_STATUS_SUCCESS;
            break;
        }
        case CANEXCEL_IP_INT_ERR_FAST:
        {
            CanXL_SetErrIntCmd(CANEXCEL.EXL_SIC[u8Instance], CANXL_INT_ERR_FAST, enable);
            returnResult = CANEXCEL_STATUS_SUCCESS;
            break;
        }
        case CANEXCEL_IP_INT_ERR_XL:
        {
            CanXL_SetErrIntCmd(CANEXCEL.EXL_SIC[u8Instance], CANXL_INT_ERR_XL, enable);
            returnResult = CANEXCEL_STATUS_SUCCESS;
            break;
        }
        case CANEXCEL_IP_INT_ERR_INT:
        {
            CanXL_SetErrIntCmd(CANEXCEL.EXL_SIC[u8Instance], CANXL_INT_INT_ERR, enable);
            returnResult = CANEXCEL_STATUS_SUCCESS;
            break;
        }
        case CANEXCEL_IP_INT_BUSOFF:
        {
            CanXL_SetErrIntCmd(CANEXCEL.EXL_SIC[u8Instance], CANXL_INT_BUSOFF, enable);
            returnResult = CANEXCEL_STATUS_SUCCESS;
            break;
        }
        case CANEXCEL_IP_INT_BUSOFF_DONE:
        {
            CanXL_SetErrIntCmd(CANEXCEL.EXL_SIC[u8Instance], CANXL_INT_BUSOFF_DONE, enable);
            returnResult = CANEXCEL_STATUS_SUCCESS;
            break;
        }
        case CANEXCEL_IP_INT_FREEZE:
        {
            CanXL_SetErrIntCmd(CANEXCEL.EXL_SIC[u8Instance], CANXL_INT_FREEZE, enable);
            returnResult = CANEXCEL_STATUS_SUCCESS;
            break;
        }
        case CANEXCEL_IP_INT_PASS_ERR:
        {
            CanXL_SetErrIntCmd(CANEXCEL.EXL_SIC[u8Instance], CANXL_INT_PASIVE_ERR, enable);
            returnResult = CANEXCEL_STATUS_SUCCESS;
            break;
        }
        default :
        {
            /* Do Nothing will report CANEXCEL_STATUS_ERROR */
            break;
        }
        }
    }
    return returnResult;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_MainFunctionRead
 * Description   : Process received Rx MessageBuffer or RxFifo.
 * This function read the messages received as pulling or if the Interrupts are disabled.
 *
 *END**************************************************************************/
/* implements Canexcel_Ip_MainFunctionRead_Activity */
void Canexcel_Ip_MainFunctionRead(uint8 instance, uint8 mb_idx)
{
    Canexcel_Ip_MainFunction(instance, mb_idx);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_MainFunctionWrite
 * Description   : Process sent Tx MessageBuffer or TxFifo.
 * This function read the messages received as pulling or if the Interrupts are disabled.
 *
 *END**************************************************************************/
/* implements Canexcel_Ip_MainFunctionWrite_Activity */
void Canexcel_Ip_MainFunctionWrite(uint8 instance, uint8 mb_idx)
{
    Canexcel_Ip_MainFunction(instance, mb_idx);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_GetStopMode
 * Description   : Check if the CANEXCEL instance is STOPPED.
 *
 *END**************************************************************************/
/* implements Canexcel_Ip_GetStopMode_Activity */
boolean Canexcel_Ip_GetStopMode(uint8 instance)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < CANXL_SIC_INSTANCE_COUNT);
#endif
    const CANXL_SIC_Type * base = CANEXCEL.EXL_SIC[instance];
    return ((CANXL_SIC_SYSS_NTRDY_MASK == (base->SYSS & CANXL_SIC_SYSS_NTRDY_MASK)) ? TRUE : FALSE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_ConfigRxFifo
 * Description   : Confgure RX FIFO filter table elements.
 * This function will confgure RX FIFO filter table elements
 *END**************************************************************************/
/* implements Canexcel_Ip_ConfigRxFifo_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_ConfigRxFifo(uint8 instance,const Canexcel_Ip_RxFifoFilter * filterConfig)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < CANXL_SIC_INSTANCE_COUNT);
    DevAssert(filterConfig->noActAddrFilters < CANXL_RXFIFO_ADDRACPTFLTAR_COUNT);
    DevAssert(filterConfig->noIdFilters < CANXL_RXFIFO_IDACPTFLTAR_COUNT);
    DevAssert(filterConfig->noSduFilters < CANXL_RXFIFO_SDUACPTFLTAR_COUNT);
    DevAssert(filterConfig->noVcanFilters < CANXL_RXFIFO_VCANACPTFLTAR_COUNT);
#endif
    Canexcel_Ip_StatusType status = CANEXCEL_STATUS_SUCCESS;
    CANXL_RXFIFO_Type * base = CANEXCEL.EXL_RXFIFO[instance];
    CANXL_RXFIFO_CONTROL_Type * rxFifoCont_base = CANEXCEL.EXL_RXF_CNT[instance];
    uint8 idx;
    if (0U == CANEXCEL.EXL_RXF_CNT[instance]->RXFSYSACT)
    {
        status = CANEXCEL_STATUS_ERROR;
    }
    else
    {
        if (TRUE == CanXL_IsFreezeMode(CANEXCEL.EXL_SIC[instance]))
        {
            /* Lock the RxFIFO by System by reading register */
            (void)rxFifoCont_base->RXFSYSLOCK;
            base->AFCFG = CANXL_RXFIFO_AFCFG_ACPTID((uint32)filterConfig->noIdFilters-1U);
            SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_07();
            for (idx = 0U; idx < filterConfig->noIdFilters; idx++)
            {
                CanXL_ConfigIDFilter(base, &filterConfig->IdFilterPtr[idx], idx);
            }
            if (filterConfig->noActAddrFilters != 0U)
            {
                base->AFCFG |= CANXL_RXFIFO_AFCFG_AADDREN_MASK | CANXL_RXFIFO_AFCFG_ACPTADDR((uint32)filterConfig->noActAddrFilters-1U);
                for (idx = 0U; idx < filterConfig->noActAddrFilters; idx++)
                {
                    CanXL_ConfigAccAddr(base, &filterConfig->AddrFilterPtr[idx], idx);
                }
            }
            if (filterConfig->noSduFilters != 0U)
            {
                base->AFCFG |= CANXL_RXFIFO_AFCFG_ASDUEN_MASK | CANXL_RXFIFO_AFCFG_ACPTSDU((uint32)filterConfig->noSduFilters-1U);
                for (idx = 0U; idx < filterConfig->noSduFilters; idx++)
                {
                    CanXL_ConfigSDUFilter(base, &filterConfig->SduFilterPtr[idx], idx);
                }
            }
            if (filterConfig->noVcanFilters != 0U)
            {
                base->AFCFG |= CANXL_RXFIFO_AFCFG_AVCANEN_MASK | CANXL_RXFIFO_AFCFG_ACPTVCAN((uint32)filterConfig->noVcanFilters-1U);
                for (idx = 0U; idx < filterConfig->noVcanFilters; idx++)
                {
                    CanXL_ConfigVCANFilter(base, &filterConfig->VcanFilterPtr[idx], idx);
                }
            }
            SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_07();
            base->SECAM = filterConfig->SecMask;
            base->SECAV = filterConfig->SecFilter;

            if (CANXL_RXFIFO_CONTROL_RXFCSTA_SYSLOCK_MASK == (rxFifoCont_base->RXFCSTA & CANXL_RXFIFO_CONTROL_RXFCSTA_SYSLOCK_MASK))
            {
                /* Clear the sys lock to enable transfers */
                rxFifoCont_base->RXFSYSLOCK = CANXL_RXFIFO_CONTROL_RXFSYSLOCK_SYSLOCK_MASK;
            }
            status = CANEXCEL_STATUS_SUCCESS;
        }
        else
        {
            status = CANEXCEL_STATUS_ERROR;
        }
    }
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_IsXLFrameType
 * Description   : Check if a MessageDescritptor is set for receive XL frame type
 *END**************************************************************************/
/* implements Canexcel_Ip_IsXLFrameType_Activity */
boolean Canexcel_Ip_IsXLFrameType(uint8 instance, uint8 descNo)
{
    const Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    boolean retVal = FALSE;
    if (descNo == CANEXCEL_IP_MB_RXFIFO)
    {
        retVal = state->rxFifo.isXLFrame;
    }
    else
    {
        if (descNo < CANXL_MSG_DESCRIPTORS_MSGDSC_COUNT)
        {
            retVal = state->msgDesc[descNo].isXLFrame;
        }
    }
    return retVal;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_GetControllerTxErrorCounter
 * Description   : Return the TxErrorCounter
 *END**************************************************************************/
/* implements Canexcel_Ip_GetControllerTxErrorCounter_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_GetControllerTxErrorCounter(uint8 instance, uint8 * pValue)
{
    uint32 errorCount = 0;
    Canexcel_Ip_StatusType status = Canexcel_GetControllerMRU(instance, &errorCount, CANXL_MRU_CMD_READ_EC);
    * pValue = (uint8)((errorCount & BCANXL_EC_TEC_MASK) >> BCANXL_EC_TEC_SHIFT);
    return status;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_GetControllerRxErrorCounter
 * Description   : Return the RxErrorCounter
 *END**************************************************************************/
/* implements Canexcel_Ip_GetControllerRxErrorCounter_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_GetControllerRxErrorCounter(uint8 instance, uint8 * pValue)
{
    uint32 errorCount = 0;
    Canexcel_Ip_StatusType status = Canexcel_GetControllerMRU(instance, &errorCount, CANXL_MRU_CMD_READ_EC);
    * pValue = (uint8)((errorCount & BCANXL_EC_REC_MASK) >> BCANXL_EC_REC_SHIFT);
    return status;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_GetControllerStatus
 * Description   : Return the Bus Status
 *END**************************************************************************/
/* implements Canexcel_Ip_GetControllerStatus_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_GetControllerStatus(uint8 instance, uint8 * pValue)
{
    uint32 errorCount = 0;
    Canexcel_Ip_StatusType status =Canexcel_GetControllerMRU(instance, &errorCount, CANXL_MRU_CMD_READ_ST);
    * pValue = (uint8)((errorCount & BCANXL_ST_FLTCONF_MASK) >> BCANXL_ST_FLTCONF_SHIFT);
    return status;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_MainFunctionBusOff
 * Description   : Check if BusOff occurred
 * This function check the bus off event.
 *
 *END**************************************************************************/
/* implements Canexcel_Ip_MainFunctionBusOff_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_MainFunctionBusOff(uint8 instance)
{
    Canexcel_Ip_StatusType eRetVal = CANEXCEL_STATUS_ERROR;
    CANXL_SIC_Type * base = CANEXCEL.EXL_SIC[instance];;
    const Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    uint32 u32StatusError =0U;
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < CANXL_SIC_INSTANCE_COUNT);
#endif
    if (0U != (base->SYSS & CANXL_SIC_SYSS_CBOFF_MASK))
    {
        eRetVal = CANEXCEL_STATUS_SUCCESS;
        /* Clear BusOff Status Flag */
        base->SYSS = CANXL_SIC_SYSS_CBOFF_MASK;
        /* Invoke callback */
        if (state->error_callback != NULL_PTR)
        {
            /* Get error status */
            eRetVal = Canexcel_GetControllerMRU(instance, &u32StatusError, CANXL_MRU_CMD_LAST_ST);
            if (CANEXCEL_STATUS_SUCCESS == eRetVal)
            {
                state->error_callback(instance, CANEXCEL_EVENT_BUSOFF, u32StatusError, state);
            }
        }
    }
    return eRetVal;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_ClearErrorStatus
 * Description   : Clear error status register.
 *
 *END**************************************************************************/
/* implements  Canexcel_Ip_ClearErrorStatus_Activity */
void Canexcel_Ip_ClearErrorStatus(uint8 instance, uint32 error)
{
    CANXL_SIC_Type * base = CANEXCEL.EXL_SIC[instance];
    base->SYSS = error;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_ManualBusOffRecovery
 * Description   : Recover manually from bus-off if possible.
 *
 *END**************************************************************************/
/* implements  Canexcel_Ip_ManualBusOffRecovery_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_ManualBusOffRecovery(uint8 instance)
{
    Canexcel_Ip_StatusType eRetVal = CANEXCEL_STATUS_ERROR;
    const CANXL_SIC_Type * base = CANEXCEL.EXL_SIC[instance];
    uint32 u32AckVal = 255U;

    if (CANXL_SIC_BCFG1_ABRDIS_MASK == (base->BCFG1 & CANXL_SIC_BCFG1_ABRDIS_MASK))
    {
        eRetVal = Canexcel_GetControllerMRU(instance, &u32AckVal, CANXL_MRU_CMD_BUSOFF);
        if ((CANEXCEL_STATUS_SUCCESS == eRetVal) && (u32AckVal != CANXL_MRU_CMD_BUSOFF))
        {
            eRetVal = CANEXCEL_STATUS_ERROR;
        }
    }
    return eRetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_SetFDBaudRate
 * Description   : Set bit rate segments in FD phase.
 *
 *END**************************************************************************/
/* implements  Canexcel_Ip_SetFDBaudRate_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_SetFDBaudRate(uint8 Instance, const Canexcel_Ip_TimeSegmentType * TimeSeg, boolean BitRateSwitch)
{
    Canexcel_Ip_StatusType RetVal = CANEXCEL_STATUS_ERROR;
    CANXL_SIC_Type * Base = CANEXCEL.EXL_SIC[Instance];

#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < CANXL_SIC_INSTANCE_COUNT);
    DevAssert(TimeSeg != NULL_PTR);
#endif

    if (TRUE == CanXL_IsFreezeMode(Base))
    {
        if (TRUE == CanXL_IsFDModeEnabled(Base))
        {
            CanXL_SetFDEnabled(Base, TRUE, BitRateSwitch);
            CanXL_SetFDBaudRate(Base, TimeSeg);
            RetVal = CANEXCEL_STATUS_SUCCESS;
        }
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_SetXLBaudRate
 * Description   : Set bit rate segments in XL phase.
 *
 *END**************************************************************************/
/* implements  Canexcel_Ip_SetXLBaudRate_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_SetXLBaudRate(uint8 Instance, const Canexcel_Ip_TimeSegmentType * TimeSeg)
{
    Canexcel_Ip_StatusType RetVal = CANEXCEL_STATUS_ERROR;
    CANXL_SIC_Type * Base = CANEXCEL.EXL_SIC[Instance];

#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < CANXL_SIC_INSTANCE_COUNT);
    DevAssert(TimeSeg != NULL_PTR);
#endif

    if (TRUE == CanXL_IsFreezeMode(Base))
    {
        if (TRUE == CanXL_IsXLModeEnabled(Base))
        {
            CanXL_SetXLBaudRate(Base, TimeSeg);
            RetVal = CANEXCEL_STATUS_SUCCESS;
        }
    }

    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_SetBaudRate
 * Description   : Set bit rate segments in nomimal phase.
 *
 *END**************************************************************************/
/* implements  Canexcel_Ip_SetBaudRate_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_SetBaudRate(uint8 Instance, const Canexcel_Ip_TimeSegmentType * TimeSeg)
{
    Canexcel_Ip_StatusType RetVal = CANEXCEL_STATUS_ERROR;
    CANXL_SIC_Type * Base = CANEXCEL.EXL_SIC[Instance];
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < CANXL_SIC_INSTANCE_COUNT);
    DevAssert(TimeSeg != NULL_PTR);
#endif
    if (TRUE == CanXL_IsFreezeMode(Base))
    {
        CanXL_SetBaudRate(Base, TimeSeg);
        RetVal = CANEXCEL_STATUS_SUCCESS;
    }
    return RetVal;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_GetFDBaudRate
 * Description   : Get bit rate segments in FD phase.
 *
 *END**************************************************************************/
/* implements  Canexcel_Ip_GetFDBaudRate_Activity */
void Canexcel_Ip_GetFDBaudRate(uint8 Instance, Canexcel_Ip_TimeSegmentType * TimeSeg)
{
    const CANXL_SIC_Type * Base = CANEXCEL.EXL_SIC[Instance];

#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < CANXL_SIC_INSTANCE_COUNT);
    DevAssert(TimeSeg != NULL_PTR);
#endif
    CanXL_GetFDBaudRate(Base, TimeSeg);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_GetXLBaudRate
 * Description   : Get bit rate segments in XL phase.
 *
 *END**************************************************************************/
/* implements  Canexcel_Ip_GetXLBaudRate_Activity */
void Canexcel_Ip_GetXLBaudRate(uint8 Instance, Canexcel_Ip_TimeSegmentType * TimeSeg)
{
    const CANXL_SIC_Type * Base = CANEXCEL.EXL_SIC[Instance];
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < CANXL_SIC_INSTANCE_COUNT);
    DevAssert(TimeSeg != NULL_PTR);
#endif
    CanXL_GetXLBaudRate(Base, TimeSeg);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_GetBaudRate
 * Description   : Get bit rate segments in nomimal phase.
 *
 *END**************************************************************************/
/* implements  Canexcel_Ip_GetBaudRate_Activity */
void Canexcel_Ip_GetBaudRate(uint8 Instance, Canexcel_Ip_TimeSegmentType * TimeSeg)
{
    const CANXL_SIC_Type * Base = CANEXCEL.EXL_SIC[Instance];
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < CANXL_SIC_INSTANCE_COUNT);
    DevAssert(TimeSeg != NULL_PTR);
#endif
    CanXL_GetBaudRate(Base, TimeSeg);
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_SetListenOnlyMode
 * Description   : Enable/disable Listen Only Mode.
 *
 *END**************************************************************************/
/* implements  Canexcel_Ip_SetListenOnlyMode_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_SetListenOnlyMode(uint8 Instance, boolean Enable)
{
    Canexcel_Ip_StatusType RetVal = CANEXCEL_STATUS_ERROR;
    CANXL_SIC_Type * Base = CANEXCEL.EXL_SIC[Instance];

#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < CANXL_SIC_INSTANCE_COUNT);
#endif
    if (TRUE == CanXL_IsFreezeMode((const CANXL_SIC_Type *)Base))
    {
        CanXL_SetListenOnlyMode(Base, Enable);
        RetVal = CANEXCEL_STATUS_SUCCESS;
    }
    return RetVal;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_GetListenOnlyMode
 * Description   : Get Listen Only Mode.
 *
 *END**************************************************************************/
/* implements  Canexcel_Ip_GetListenOnlyMode_Activity */
boolean Canexcel_Ip_GetListenOnlyMode(uint8 Instance)
{
    const CANXL_SIC_Type * Base = CANEXCEL.EXL_SIC[Instance];

#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < CANXL_SIC_INSTANCE_COUNT);
#endif

    return CanXL_IsListenOnlyModeEnabled(Base);
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_SetTDCOffsetFD
 * Description   : Enables/Disables the FD Transceiver Delay Compensation feature
 * and sets the FD Transceiver Delay Compensation Offset.
 *
 *END**************************************************************************/
/* implements  Canexcel_Ip_SetTDCOffsetFD_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_SetTDCOffsetFD(uint8 Instance, boolean TDCEnable, boolean TDCMEnable, uint8 Offset)
{
    CANXL_SIC_Type * Base = CANEXCEL.EXL_SIC[Instance];
    Canexcel_Ip_StatusType RetVal = CANEXCEL_STATUS_ERROR;

#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < CANXL_SIC_INSTANCE_COUNT);
    /* When TDC disabled, TDC Measurement has no meaning! */
    DevAssert(!((FALSE == TDCEnable) && (TRUE == TDCMEnable)));
#endif
    if (TRUE == CanXL_IsFreezeMode(Base))
    {
        CanXL_SetTDCOffsetFD(Base, TDCEnable, TDCMEnable, Offset);
        RetVal = CANEXCEL_STATUS_SUCCESS;
    }
    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_SetTDCOffsetXL
 * Description   : Enables/Disables the XL Transceiver Delay Compensation feature
 * and sets the XL Transceiver Delay Compensation Offset.
 *
 *END**************************************************************************/
/* implements  Canexcel_Ip_SetTDCOffsetXL_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_SetTDCOffsetXL(uint8 Instance, boolean TDCEnable, boolean TDCMEnable, uint8 Offset)
{
    CANXL_SIC_Type * Base = CANEXCEL.EXL_SIC[Instance];
    Canexcel_Ip_StatusType RetVal = CANEXCEL_STATUS_ERROR;

#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < CANXL_SIC_INSTANCE_COUNT);
    /* When TDC disabled, TDC Measurement has no meaning! */
    DevAssert(!((FALSE == TDCEnable) && (TRUE == TDCMEnable)));
#endif

    if (TRUE == CanXL_IsFreezeMode(Base))
    {
        CanXL_SetTDCOffsetXL(Base, TDCEnable, TDCMEnable, Offset);
        RetVal = CANEXCEL_STATUS_SUCCESS;
    }
    return RetVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_ConfigTransceiverMode
 * Description   : Configure PWM Short Phase, PWM Long Phase, PWM Offset, protocol exception
 *
 *END**************************************************************************/
/* implements  Canexcel_Ip_ConfigTransceiverMode_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_ConfigTransceiverMode(uint8 Instance, const Canexcel_Ip_TransceiverModeType * Config)
{
    CANXL_SIC_Type * Base = CANEXCEL.EXL_SIC[Instance];
    Canexcel_Ip_StatusType RetVal = CANEXCEL_STATUS_ERROR;

#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < CANXL_SIC_INSTANCE_COUNT);
    DevAssert(NULL_PTR != Config);
    /* when PWM mode enabled, protocol exception must be enabled */
    DevAssert(!((TRUE == Config->PwmModeEnable) && (FALSE == Config->ProtocolExceptionEnable)));
    /* when PWM mode enabled, PWMS must be in range [1:63] */
    DevAssert(!((TRUE == Config->PwmModeEnable) && ((0U == Config->PwmShortPhase) || (Config->PwmShortPhase > 63U))));
    /* when PWM mode enabled, PWML must be in range [1:63] */
    DevAssert(!((TRUE == Config->PwmModeEnable) && ((0U == Config->PwmLongPhase) || (Config->PwmLongPhase > 63U))));
    /* when PWM mode enabled, PWMO must be in range [0:63] */
    DevAssert(!((TRUE == Config->PwmModeEnable) && (Config->PwmOffset > 63U)));
#endif
    if (TRUE == CanXL_IsFreezeMode(Base))
    {
        SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_12();
        CanXL_SetPwmModeEnable(Base, Config->PwmModeEnable);
        CanXL_SetPWMPhases(Base, Config->PwmShortPhase, Config->PwmLongPhase, Config->PwmOffset);
        CanXL_SetXLErrorResponse(Base, Config->ProtocolExceptionEnable);
        SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_12();
        RetVal = CANEXCEL_STATUS_SUCCESS;
    }
    return RetVal;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_ConfigAccFltBank0
 * Description   : Configures the 32 AF, VCAN, SDU Acceptance Filters from Filter Bank 0
 * note: This Filters Affect only the MessageDescriptors config for XL Frame reception
 *END**************************************************************************/
/* implements  Canexcel_Ip_ConfigAccFltBank0_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_ConfigAccFltBank0(uint8 Instance, const Canexcel_Ip_BankFilter * Config)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < CANXL_SIC_INSTANCE_COUNT);
    DevAssert(Config->noActAddrFilters <= CANEXCEL_IP_MAX_FILTER_BANK);
    DevAssert(Config->noSduFilters <= CANEXCEL_IP_MAX_FILTER_BANK);
    DevAssert(Config->noVcanFilters <= CANEXCEL_IP_MAX_FILTER_BANK);
#endif
    Canexcel_Ip_StatusType status = CANEXCEL_STATUS_SUCCESS;
    uint8 idx;
    CANXL_FILTER_BANK_Type * base = CANEXCEL.EXL_FILTER[Instance];
    if (TRUE == CanXL_IsFreezeMode(CANEXCEL.EXL_SIC[Instance]))
    {
        if (Config->noActAddrFilters != 0U)
        {
            base->AFCFG0 = CANXL_FILTER_BANK_AFCFG0_AADDREN_MASK | CANXL_FILTER_BANK_AFCFG0_ACPTADDR((uint32)Config->noActAddrFilters-1U);
            for (idx = 0U; idx < Config->noActAddrFilters; idx++)
            {
                CanXL_ConfigAccAddrFilterBank(base, 0U, &Config->AddrFilterPtr[idx], idx);
            }
        }
        if (Config->noSduFilters != 0U)
        {
            base->AFCFG0 |=  CANXL_FILTER_BANK_AFCFG0_ASDUEN_MASK | CANXL_FILTER_BANK_AFCFG0_ACPTSDU((uint32)Config->noSduFilters-1U);
            for (idx = 0U; idx < Config->noSduFilters; idx++)
            {
                CanXL_ConfigSDUFilterBank(base, 0U, &Config->SduFilterPtr[idx], idx);
            }
        }
        if (Config->noVcanFilters != 0U)
        {
            base->AFCFG0 |=  CANXL_FILTER_BANK_AFCFG0_AVCANEN_MASK | CANXL_FILTER_BANK_AFCFG0_ACPTVCAN((uint32)Config->noVcanFilters-1U);
            for (idx = 0U; idx < Config->noVcanFilters; idx++)
            {
                CanXL_ConfigVCANFilterBank(base, 0U, &Config->VcanFilterPtr[idx], idx);
            }
        }

    }
    else
    {
        status = CANEXCEL_STATUS_ERROR;
    }
    return status;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_ConfigAccFltBank1
 * Description   : Configures the 32 AF, VCAN, SDU Acceptance Filters from Filter Bank 1
 * note: This Filters Affect only the MessageDescriptors config for XL Frame reception
 *END**************************************************************************/
/* implements  Canexcel_Ip_ConfigAccFltBank1_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_ConfigAccFltBank1(uint8 Instance, const Canexcel_Ip_BankFilter * Config)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < CANXL_SIC_INSTANCE_COUNT);
    DevAssert(Config->noActAddrFilters <= CANEXCEL_IP_MAX_FILTER_BANK);
    DevAssert(Config->noSduFilters <= CANEXCEL_IP_MAX_FILTER_BANK);
    DevAssert(Config->noVcanFilters <= CANEXCEL_IP_MAX_FILTER_BANK);
#endif
    Canexcel_Ip_StatusType status = CANEXCEL_STATUS_SUCCESS;
    uint8 idx;
    CANXL_FILTER_BANK_Type * base = CANEXCEL.EXL_FILTER[Instance];
    if (TRUE == CanXL_IsFreezeMode(CANEXCEL.EXL_SIC[Instance]))
    {
        if (Config->noActAddrFilters != 0U)
        {
            base->AFCFG1 = CANXL_FILTER_BANK_AFCFG1_AADDREN_MASK | CANXL_FILTER_BANK_AFCFG1_ACPTADDR((uint32)Config->noActAddrFilters-1U);
            for (idx = 0U; idx < Config->noActAddrFilters; idx++)
            {
                CanXL_ConfigAccAddrFilterBank(base, 1U, &Config->AddrFilterPtr[idx], idx);
            }
        }
        if (Config->noSduFilters != 0U)
        {
            base->AFCFG1 |=  CANXL_FILTER_BANK_AFCFG1_ASDUEN_MASK | CANXL_FILTER_BANK_AFCFG1_ACPTSDU((uint32)Config->noSduFilters-1U);
            for (idx = 0U; idx <= Config->noSduFilters; idx++)
            {
                CanXL_ConfigSDUFilterBank(base, 1U, &Config->SduFilterPtr[idx], idx);
            }
        }
        if (Config->noVcanFilters != 0U)
        {
            base->AFCFG1 |=  CANXL_FILTER_BANK_AFCFG1_AVCANEN_MASK | CANXL_FILTER_BANK_AFCFG1_ACPTVCAN((uint32)Config->noVcanFilters-1U);
            for (idx = 0U; idx < Config->noSduFilters; idx++)
            {
                CanXL_ConfigVCANFilterBank(base, 1U, &Config->VcanFilterPtr[idx], idx);
            }
        }

    }
    else
    {
        status = CANEXCEL_STATUS_ERROR;
    }
    return status;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_ConfigRejFltBank0
 * Description   : Configures the 32 AF, VCAN, SDU Rejection Filters from Filter Bank 0
 * note: This Filters Affect only the MessageDescriptors config for XL Frame reception
 *END**************************************************************************/
/* implements  Canexcel_Ip_ConfigRejFltBank0_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_ConfigRejFltBank0(uint8 Instance, const Canexcel_Ip_BankFilter * Config)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < CANXL_SIC_INSTANCE_COUNT);
    DevAssert(Config->noActAddrFilters <= CANEXCEL_IP_MAX_FILTER_BANK);
    DevAssert(Config->noSduFilters <= CANEXCEL_IP_MAX_FILTER_BANK);
    DevAssert(Config->noVcanFilters <= CANEXCEL_IP_MAX_FILTER_BANK);
#endif
    Canexcel_Ip_StatusType status = CANEXCEL_STATUS_SUCCESS;
    uint8 idx;
    CANXL_FILTER_BANK_Type * base = CANEXCEL.EXL_FILTER[Instance];
    if (TRUE == CanXL_IsFreezeMode(CANEXCEL.EXL_SIC[Instance]))
    {
        if (Config->noActAddrFilters != 0U)
        {
            base->RFCFG0 = CANXL_FILTER_BANK_RFCFG0_RADDREN_MASK | CANXL_FILTER_BANK_RFCFG0_REJADDR((uint32)Config->noActAddrFilters-1U);
            for (idx = 0U; idx < Config->noActAddrFilters; idx++)
            {
                CanXL_ConfigAccAddrRejectBank(base, 0U, &Config->AddrFilterPtr[idx], idx);
            }
        }
        if (Config->noSduFilters != 0U)
        {
            base->RFCFG0 |=  CANXL_FILTER_BANK_RFCFG0_RSDUEN_MASK | CANXL_FILTER_BANK_RFCFG0_REJSDU((uint32)Config->noSduFilters-1U);
            for (idx = 0U; idx < Config->noSduFilters; idx++)
            {
                CanXL_ConfigSDURejectBank(base, 0U, &Config->SduFilterPtr[idx], idx);
            }
        }
        if (Config->noVcanFilters != 0U)
        {
            base->RFCFG0 |=  CANXL_FILTER_BANK_RFCFG0_RVCANEN_MASK | CANXL_FILTER_BANK_RFCFG0_REJVCAN((uint32)Config->noVcanFilters-1U);
            for (idx = 0U; idx < Config->noVcanFilters; idx++)
            {
                CanXL_ConfigVCANRejectBank(base, 0U, &Config->VcanFilterPtr[idx], idx);
            }
        }

    }
    else
    {
        status = CANEXCEL_STATUS_ERROR;
    }
    return status;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_ConfigRejFltBank1
 * Description   : Configures the 32 AF, VCAN, SDU Rejection Filters from Filter Bank 1
 * note: This Filters Affect only the MessageDescriptors config for XL Frame reception
 *END**************************************************************************/
/* implements  Canexcel_Ip_ConfigRejFltBank1_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_ConfigRejFltBank1(uint8 Instance, const Canexcel_Ip_BankFilter * Config)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < CANXL_SIC_INSTANCE_COUNT);
    DevAssert(Config->noActAddrFilters <= CANEXCEL_IP_MAX_FILTER_BANK);
    DevAssert(Config->noSduFilters <= CANEXCEL_IP_MAX_FILTER_BANK);
    DevAssert(Config->noVcanFilters <= CANEXCEL_IP_MAX_FILTER_BANK);
#endif
    Canexcel_Ip_StatusType status = CANEXCEL_STATUS_SUCCESS;
    uint8 idx;
    CANXL_FILTER_BANK_Type * base = CANEXCEL.EXL_FILTER[Instance];
    if (TRUE == CanXL_IsFreezeMode(CANEXCEL.EXL_SIC[Instance]))
    {
        if (Config->noActAddrFilters != 0U)
        {
            base->RFCFG1 = CANXL_FILTER_BANK_RFCFG1_RADDREN_MASK | CANXL_FILTER_BANK_RFCFG1_REJADDR((uint32)Config->noActAddrFilters-1U);
            for (idx = 0U; idx < Config->noActAddrFilters; idx++)
            {
                CanXL_ConfigAccAddrRejectBank(base, 1U, &Config->AddrFilterPtr[idx], idx);
            }
        }
        if (Config->noSduFilters != 0U)
        {
            base->RFCFG1 |=  CANXL_FILTER_BANK_RFCFG1_RSDUEN_MASK | CANXL_FILTER_BANK_RFCFG1_REJSDU((uint32)Config->noSduFilters-1U);
            for (idx = 0U; idx < Config->noSduFilters; idx++)
            {
                CanXL_ConfigSDURejectBank(base, 1U, &Config->SduFilterPtr[idx], idx);
            }
        }
        if (Config->noVcanFilters != 0U)
        {
            base->RFCFG1 |=  CANXL_FILTER_BANK_RFCFG1_RVCANEN_MASK | CANXL_FILTER_BANK_RFCFG1_REJVCAN((uint32)Config->noVcanFilters-1U);
            for (idx = 0U; idx < Config->noVcanFilters; idx++)
            {
                CanXL_ConfigVCANRejectBank(base, 1U, &Config->VcanFilterPtr[idx], idx);
            }
        }

    }
    else
    {
        status = CANEXCEL_STATUS_ERROR;
    }
    return status;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_ConfigAccAddrFilter
 * Description   : Configures the ACC Filter No from Bank0 or Bank1
 * note: This Filters Affect only the MessageDescriptors config for XL Frame reception
 *END**************************************************************************/
/* implements  Canexcel_Ip_ConfigAccAddrFilter_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_ConfigAccAddrFilter(uint8 Instance,const Canexcel_Ip_RxFifoFilterID_ADDR * filterValue, uint8 * filterNo)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < CANXL_SIC_INSTANCE_COUNT);
    DevAssert(filterValue != NULL_PTR);
    DevAssert(filterNo != NULL_PTR);
#endif
    Canexcel_Ip_StatusType status = CANEXCEL_STATUS_SUCCESS;
    uint8 noFilter = 0U;
    if (TRUE == CanXL_IsFreezeMode(CANEXCEL.EXL_SIC[Instance]))
    {
        noFilter = (uint8)((CANEXCEL.EXL_FILTER[Instance]->AFCFG0 & CANXL_FILTER_BANK_AFCFG0_ACPTADDR_MASK) >> CANXL_FILTER_BANK_AFCFG0_ACPTADDR_SHIFT);
        if (0U == (CANEXCEL.EXL_FILTER[Instance]->AFCFG0 & CANXL_FILTER_BANK_AFCFG0_AADDREN_MASK))
        {
            CANEXCEL.EXL_FILTER[Instance]->AFCFG0 |=  CANXL_FILTER_BANK_AFCFG0_AADDREN_MASK;
        }
        else
        {
            noFilter++;

        }
        if (noFilter < CANEXCEL_IP_MAX_FILTER_BANK)
        {
            * filterNo = noFilter;
            CanXL_ConfigAccAddrFilterBank(CANEXCEL.EXL_FILTER[Instance], 0U, filterValue, noFilter);
            CANEXCEL.EXL_FILTER[Instance]->AFCFG0 |= CANXL_FILTER_BANK_AFCFG0_ACPTADDR(noFilter);
        }
        else
        {
            if (CANXL_SIC_SYSMCFG_FB1EN_MASK == (CANEXCEL.EXL_SIC[Instance]->SYSMCFG & CANXL_SIC_SYSMCFG_FB1EN_MASK))
            {
                noFilter = (uint8)((CANEXCEL.EXL_FILTER[Instance]->AFCFG1 & CANXL_FILTER_BANK_AFCFG1_ACPTADDR_MASK) >> CANXL_FILTER_BANK_AFCFG1_ACPTADDR_SHIFT);
                if (0U == (CANEXCEL.EXL_FILTER[Instance]->AFCFG1 & CANXL_FILTER_BANK_AFCFG0_AADDREN_MASK))
                {
                    CANEXCEL.EXL_FILTER[Instance]->AFCFG1 |=  CANXL_FILTER_BANK_AFCFG1_AADDREN_MASK;
                }
                else
                {
                    noFilter++;
                }
                if ((CANEXCEL_IP_MAX_FILTER_BANK + noFilter) < (2U*CANEXCEL_IP_MAX_FILTER_BANK))
                {
                    * filterNo = (CANEXCEL_IP_MAX_FILTER_BANK + noFilter);
                    CanXL_ConfigAccAddrFilterBank(CANEXCEL.EXL_FILTER[Instance], 1U, filterValue, noFilter);
                }
                else
                {
                    status = CANEXCEL_STATUS_BUFF_OUT_OF_RANGE;
                }
            }
            else
            {
                status = CANEXCEL_STATUS_BUFF_OUT_OF_RANGE;
            }
        }
    }
    else
    {
        status = CANEXCEL_STATUS_ERROR;
    }
    return status;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_GetDescriptorStatus
 * Description   : Return the Message Descriptor State, and HW and SYStem pointers indexes
 *END**************************************************************************/
/* implements  Canexcel_Ip_GetDescriptorStatus_Activity */
Canexcel_Ip_DescState Canexcel_Ip_GetDescriptorStatus(uint8 Instance, uint8 descNo, uint8 * sysPoint, uint8 * hwPoint)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < CANXL_SIC_INSTANCE_COUNT);
    DevAssert(sysPoint != NULL_PTR);
    DevAssert(hwPoint != NULL_PTR);
#endif
    * hwPoint = CanXL_GetDesciptorHWIndex(CANEXCEL.EXL_DESC_CTR[Instance], descNo);
    * sysPoint = CanXL_GetDesciptorSysIndex(CANEXCEL.EXL_DESC_CTR[Instance], descNo);
    return CanXL_GetDesciptorState(CANEXCEL.EXL_DESC_CTR[Instance], descNo);
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_SetMsgBuffInterrupt
 * Description   : Enable\Disable the Message Descriptor Interrupt
 *END**************************************************************************/
/* implements  Canexcel_Ip_SetMsgBuffInterrupt_Activity */
void Canexcel_Ip_SetMsgBuffInterrupt(uint8 instance, uint8 descNo, boolean enable)
{
    if (TRUE == enable)
    {
        CanXL_SetMsgBuffIntCmd(CANEXCEL.EXL_GRP[instance], descNo);
    }
    else
    {
        CanXL_ClearMsgBuffIntCmd(CANEXCEL.EXL_GRP[instance], descNo);
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_GetMsgDescIntStatusFlag
 * Description   : Retur the Message Descriptor Interrupt Status Flag
 *END**************************************************************************/
/* implements  Canexcel_Ip_GetMsgDescIntStatusFlag_Activity */
uint8 Canexcel_Ip_GetMsgDescIntStatusFlag(uint8 instance, uint8 descNo)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < CANXL_SIC_INSTANCE_COUNT);
#endif
    const CANXL_GRP_CONTROL_Type * Base = CANEXCEL.EXL_GRP[instance];
    return CanXL_GetMsgDescIntStatusFlag(Base, descNo);
}

#if (CANXL_IP_HAS_ABORT == STD_ON)
Canexcel_Ip_StatusType Canexcel_Ip_AbortMD(uint8 instance, uint8 descNo)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < CANXL_SIC_INSTANCE_COUNT);
#endif
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;
    uint32 uS2Ticks = OsIf_MicrosToTicks(CANEXCEL_IP_TIMEOUT_DURATION, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
    uint8 u8MbCnt = 0U;
    boolean isPending = FALSE;

    for (u8MbCnt = 0U; u8MbCnt < 16U; u8MbCnt++)
    {
        if (TRUE == state->msgDesc[descNo].isPending[u8MbCnt])
        {
            isPending = TRUE;
            break;
        }
    }

    if (TRUE == isPending)
    {
        /* Request to abort the MD */
        CANEXCEL.EXL_SIC[instance]->SYSS = CANXL_SIC_SYSS_ABTACK_MASK;
        CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCABT = 1U;
        timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
        /* wait until the abort is completed */
        while (1U == CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCABT)
        {
            timeElapsed += OsIf_GetElapsed(&timeStart, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
            if (timeElapsed >= uS2Ticks)
            {
                returnResult = CANEXCEL_STATUS_TIMEOUT;
                break;
            }
        }
        if (CANEXCEL_STATUS_SUCCESS == returnResult)
        {
            /* Clear IFLAG */
            CanXL_ClearMsgDescIntStatusFlag(CANEXCEL.EXL_GRP[instance], descNo);
            /* Reset noPointers */
            state->msgDesc[descNo].noPointers = 0U;
            state->msgDesc[descNo].lastHwIdex = 0U;
            for (u8MbCnt = 0U; u8MbCnt < 16U; u8MbCnt++)
            {
                state->msgDesc[descNo].isPending[u8MbCnt] = FALSE;
            }
        }
    }
    else
    {
        returnResult = CANEXCEL_STATUS_NO_TRANSFER_IN_PROGRESS;
    }

    return returnResult;
}
#endif /* (CANXL_IP_HAS_ABORT == STD_ON) */

/* implements  Canexcel_Ip_DeactivateMD_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_DeactivateMD(uint8 instance, uint8 descNo)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < CANXL_SIC_INSTANCE_COUNT);
#endif
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;
    uint32 uS2Ticks = OsIf_MicrosToTicks(CANEXCEL_IP_TIMEOUT_DURATION, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
    uint8 u8MbCnt = 0U;
#if (CANXL_IP_HAS_ABORT == STD_ON)
    Canexcel_Ip_DescState DescState = CanXL_GetDesciptorState(CANEXCEL.EXL_DESC_CTR[instance], descNo);

    /* For the IP has Abort feature, it requires MD to be in EMPTY before deactivation */
    if (DescState > CANEXCEL_DESC_STATE_EMPTY)
    {
        returnResult = CANEXCEL_STATUS_ERROR;
    }
    else
#endif
    {
	    /* It requires syslock before deactivation the MD */
	    #if (CANEXCEL_IP_HAS_SYSLOCK01 == STD_ON)
	    CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK = 1U;
	    #else
	    (void)CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK;
	    #endif
	
	    /* Wait until syslock is retrieved */
	    timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
	    while (CANEXCEL_DESCNTSTATUS_LOCKED_SYS != CanXL_GetDescControlStatus(CANEXCEL.EXL_DESC_CTR[instance], descNo))
	    {
	        timeElapsed += OsIf_GetElapsed(&timeStart, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
	        if (timeElapsed >= uS2Ticks)
	        {
	            returnResult = CANEXCEL_STATUS_TIMEOUT;
	            break;
	        }
	        /* It requires syslock before deactivation the MD */
	        #if (CANEXCEL_IP_HAS_SYSLOCK01 == STD_ON)
	        CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK = 1U;
	        #else
	        (void)CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK;
	        #endif
	    }
	    /* If syslock retrieved, deactivate the MD */
	    if (CANEXCEL_STATUS_SUCCESS == returnResult)
	    {
	        /* as result, the MD is deactivated(syspointer and hwpointer are reset).
	         * And it can't participate in the message Tx or Rx process.
	        */
	        CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCACT = 0U;
	        /* Release syslock */
	        #if (CANEXCEL_IP_HAS_SYSLOCK01 == STD_ON)
	        CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK = 0U;
	        #else
	        CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK = 1U;
	        #endif
	        /* Clear IFLAG */
	        CanXL_ClearMsgDescIntStatusFlag(CANEXCEL.EXL_GRP[instance], descNo);
	        /* Reset noPointers */
	        state->msgDesc[descNo].noPointers = 0U;
	        state->msgDesc[descNo].lastHwIdex = 0U;
            for (u8MbCnt = 0U; u8MbCnt < 16U; u8MbCnt++)
            {
                state->msgDesc[descNo].isPending[u8MbCnt] = FALSE;
            }
	    }
    }

    return returnResult;
}
/*FUNCTION**********************************************************************
 * Function Name : Canexcel_Ip_Deinit
 * Description   : DeInitilize the Canexecel Module and restore the reset Values
 *END**************************************************************************/
/* implements  Canexcel_Ip_Deinit_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_Deinit(uint8 u8Instance)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u8Instance < CANXL_SIC_INSTANCE_COUNT);
#endif
    Canexcel_Ip_StatusType retVal;
    retVal = CanXL_EnterFreezeMode(CANEXCEL.EXL_SIC[u8Instance]);
    if (CANEXCEL_STATUS_SUCCESS == retVal)
    {
        retVal = CanXL_SoftReset(CANEXCEL.EXL_SIC[u8Instance]);
    }
    if (CANEXCEL_STATUS_SUCCESS == retVal)
    {
        /* Clear status to default values */
        CANEXCEL.EXL_SIC[u8Instance]->SYSS = CANEXCEL_IP_SYSS_CLEAR_DEFAULT_VALUE_U32;
        /* Clear Memory ram and initialize it */
        CanXL_ClearRAM(&CANEXCEL, u8Instance);
        /* Restore Default Values */
        CANEXCEL.EXL_SIC[u8Instance]->BBPRS = 0U;
        CANEXCEL.EXL_SIC[u8Instance]->BCFG1 = 0U;
        CANEXCEL.EXL_SIC[u8Instance]->BCFG2 = CANEXCEL_IP_BCFG2_DEFAULT_VALUE_U32;
        CANEXCEL.EXL_SIC[u8Instance]->BNCBT = CANEXCEL_IP_BNCBT_DEFAULT_VALUE_U32;
        CANEXCEL.EXL_SIC[u8Instance]->BFDCBT = CANEXCEL_IP_BFDCBT_DEFAULT_VALUE_U32;
        CANEXCEL.EXL_SIC[u8Instance]->BXDCBT = CANEXCEL_IP_BXDCBT_DEFAULT_VALUE_U32;
        CANEXCEL.EXL_SIC[u8Instance]->BTDCC = 0U;
        CANEXCEL.EXL_SIC[u8Instance]->BMICI = 0U;
        CANEXCEL.EXL_MRU[u8Instance]->CHXCONFIG[0u].CH_CFG0 = 0U;
    }
    return retVal;
}

#define CAN_43_CANEXCEL_STOP_SEC_CODE
#include "Can_43_CANEXCEL_MemMap.h"

/** @} */

