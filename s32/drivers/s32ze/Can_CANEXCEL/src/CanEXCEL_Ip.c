/*
 * Copyright 2021-2023 NXP
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
#include "CanEXCEL_Ip_Irq.h"
#include "CanEXCEL_Ip_HwAccess.h"
#include "SchM_Can_43_CANEXCEL.h"

static CANEXCEL_StructType CANEXCEL;

static CANXL_SIC_Type * EXL_SIC_PTR[] = IP_CANXL_SIC_BASE_PTRS;
static MC_RGM_Type * EXL_RGM_PTR[] = IP_MC_RGM_BASE_PTRS;
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
/* Pointer to runtime state structure.*/
static Canexcel_Ip_StateType * Canexcel_Ip_apxState[CANXL_SIC_INSTANCE_COUNT];

static void Canexcel_Ip_MainFunction(uint8 instance, uint8 mb_idx);

static Canexcel_Ip_StatusType Canexcel_GetControllerMRU(uint8 instance, uint32 * pValue, uint8 command);

static void Canexcel_Ip_ConfInit(uint8 instance, const Canexcel_Ip_ConfigType * Config);
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
    if (status == CANEXCEL_STATUS_SUCCESS)
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
    /* Check if instance initialized */
    if ((NULL_PTR != state) && (mb_idx <= total_mb))
    {
        flag_reg = CanXL_GetMsgDescIntStatusFlag(CANEXCEL.EXL_GRP[instance], mb_idx);

        if (0U != flag_reg)
        {
            CanXL_ClearMsgDescIntStatusFlag(CANEXCEL.EXL_GRP[instance], mb_idx);
            state->msgDesc[mb_idx].noPointers = (uint8)((CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[mb_idx].STA.DCSTA & CANXL_DSC_CONTROL_DCSTA_HWPOINTER_MASK) >> CANXL_DSC_CONTROL_DCSTA_HWPOINTER_SHIFT);
            /* First descriptors are always allocated for Transmission */
            if (mb_idx <= CANEXCEL.EXL_GRP[instance]->DSCCTRL)
            {
                /* Process Tx MDESC */
                if (NULL_PTR != state->callback)
                {
                    state->callback(instance, CANEXCEL_EVENT_TX_COMPLETE, mb_idx, state);
                }
            }
            else
            {
                /* Process Rx MDESC */
                if (NULL_PTR != state->callback)
                {
                    state->callback(instance, CANEXCEL_EVENT_RX_COMPLETE, mb_idx, state);
                }
            }
        }
    }
    if((NULL_PTR != state) && (mb_idx == CANEXCEL_IP_MB_RXFIFO))
    {
        if (CANEXCEL.EXL_RXF_CNT[instance]->RXFSYSACT == 1U)
        {
            if (((CANEXCEL.EXL_RXF_CNT[instance]->RXFIEN & CANXL_RXFIFO_CONTROL_RXFIEN_RXFIE_MASK) != 0U) &&  ((CANEXCEL.EXL_RXF_CNT[instance]->RXFS & CANXL_RXFIFO_CONTROL_RXFS_RXFF_MASK) != 0U))
            {
                if ((CANEXCEL.EXL_RXF_CNT[instance]->RXFS & CANXL_RXFIFO_CONTROL_RXFS_RXFF_MASK) == CANXL_RXFIFO_CONTROL_RXFS_RXFF_MASK)
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
    if(Canxl_Ip_pData->fd_enable)
    {
        CanXL_SetFDBaudRate(pBase, &Canxl_Ip_pData->Fd_bitrate);
    }
    if(Canxl_Ip_pData->xl_enable)
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
  CanXL_SetMDQueueConfigs( CANEXCEL.EXL_GRP[instance], Config->QueueMDConfig);
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
    const CANXL_SIC_Type * base = CANEXCEL.EXL_SIC[instance];
    return ((0U == (base->SYSMC & (CANXL_SIC_SYSMC_LPMREQ_MASK | CANXL_SIC_SYSMC_FRZREQ_MASK))) ? TRUE : FALSE);
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
        CANEXCEL.EXL_SIC[instance]->BCFG2 |= (time_stamp->ts64bit == TRUE) ? CANXL_SIC_BCFG2_TSS(1U) : CANXL_SIC_BCFG2_TSS(0U);
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
 * Function Name : Canexcel_Ip_Init
 * Description   : Initialize the driver with the configuration
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_Init_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_Init(uint8 instance, const Canexcel_Ip_ConfigType * Config, Canexcel_Ip_StateType * pState)
{

  CANEXCEL.EXL_SIC = EXL_SIC_PTR;
  CANEXCEL.EXL_RGM = EXL_RGM_PTR;
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

  uint32 timeStart = 0U;
  uint32 timeElapsed = 0U;
  uint32 uS2Ticks = OsIf_MicrosToTicks(CANEXCEL_IP_TIMEOUT_DURATION, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
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
  if(returnResult == CANEXCEL_STATUS_SUCCESS)
  {
      returnResult = CanXL_SoftReset(CANEXCEL.EXL_SIC[instance]);
  }
  if(returnResult == CANEXCEL_STATUS_SUCCESS)
  {
      returnResult = CanXL_EnterFreezeMode(CANEXCEL.EXL_SIC[instance]);
  }
  if (returnResult == CANEXCEL_STATUS_SUCCESS)
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
        for(timeElapsed = 0U; timeElapsed<Config->tx_mbdesc; timeElapsed++ )
        {
            /* Better to be moved at init because requires Freeze mode */
            CANEXCEL.EXL_MSGD[instance]->MSGDSC[timeElapsed].LSTPNT.TXLSTPTR = (uint32)&pState->msgDesc[timeElapsed].list;
        }
        for(; timeElapsed < ((uint32)Config->rx_mbdesc + (uint32)Config->tx_mbdesc); timeElapsed++ )
        {
            /* Better to be moved at init because requires Freeze mode */
            CANEXCEL.EXL_MSGD[instance]->MSGDSC[timeElapsed].LSTPNT.RXLSTPTR = (uint32)&pState->msgDesc[timeElapsed].list;
        }
        
        if (TRUE == Config->is_rx_fifo_needed)
        {
            CANEXCEL.EXL_RXF_CNT[instance]->RXFC = CANXL_RXFIFO_CONTROL_RXFC_RXFD((uint32)Config->pRxFifoConfig.Rx_Fifo_Depth-1U)|CANXL_RXFIFO_CONTROL_RXFC_RXFWTM((uint32)Config->pRxFifoConfig.Rx_Fifo_Watermark - 1U);
            uint16 dlcValue = 0u;
            if(Config->pRxFifoConfig.frameType == CANEXCEL_XL_FRAME)
            {
                Canexcel_Ip_apxState[instance]->rxFifo.isXLFrame = TRUE;
                dlcValue = Config->pRxFifoConfig.Rx_Fifo_Msg_Size - 1u;
                const Canexcel_RxXlMsg * RxFifoMsgBuff= (Canexcel_RxXlMsg *)Config->pRxFifoConfig.MsgBuffersPtr;
                for(uint8 idx = 0; idx < Config->pRxFifoConfig.Rx_Fifo_Depth; idx++)
                {
                    CANEXCEL.EXL_RXFIFO[instance]->RXFMBP[idx] = (uint32)&RxFifoMsgBuff[idx];
                }
            }
            else
            {
                Canexcel_Ip_apxState[instance]->rxFifo.isXLFrame = FALSE;
                dlcValue = (uint16)CAN_ComputeDLCValue((uint8)(Config->pRxFifoConfig.Rx_Fifo_Msg_Size));
                const Canexcel_RxFdMsg * RxFifoMsgBuff= (Canexcel_RxFdMsg *)Config->pRxFifoConfig.MsgBuffersPtr;
                for(uint8 idx = 0; idx < Config->pRxFifoConfig.Rx_Fifo_Depth; idx++)
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
        CanXL_ResetImaskBuff(CANEXCEL.EXL_GRP[instance]);
        /* Clear Callbacks in case of autovariables garbage */
        Canexcel_Ip_apxState[instance]->u8MruMailboxAct = 0U;
        Canexcel_Ip_apxState[instance]->callback = Config->Callback;
        Canexcel_Ip_apxState[instance]->callbackParam = NULL_PTR;
        Canexcel_Ip_apxState[instance]->error_callback = Config->ErrorCallback;
        Canexcel_Ip_apxState[instance]->errorCallbackParam = NULL_PTR;
        Canexcel_Ip_apxState[instance]->isIntActive = FALSE;
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
Canexcel_Ip_StatusType Canexcel_Ip_SetRxIndividualMask(uint8 instance, uint8 descNo, Canexcel_Ip_FrameType frameType, uint32 mask)
{
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;
    if (CANEXCEL_XL_FRAME == frameType)
    {
        CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CFG1.MDFLT1XL = mask;
    }
    else
    {
        CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CFG1.MDFLT1FD = mask;
    }
    return returnResult;
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
    uint32 timeElapsed = 0U;
    Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;
    uint32 uS2Ticks = OsIf_MicrosToTicks(CANEXCEL_IP_TIMEOUT_DURATION, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
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

    if (CanXL_GetDesciptorState(CANEXCEL.EXL_DESC_CTR[instance], descNo) >= CANEXCEL_DESC_STATE_FULL)
    {
        returnResult = CANEXCEL_STATUS_BUSY;
    }
    if (returnResult == CANEXCEL_STATUS_SUCCESS)
    {
        CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CTRL.RXCTRL = 0U;
        if(info->frame == CANEXCEL_XL_FRAME)
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
        else if (info->frame == CANEXCEL_FD_FRAME)
        {
            state->msgDesc[descNo].isXLFrame = FALSE;
            CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CTRL.RXCTRL = CANXL_MSG_DESCRIPTORS_RXCTRL_RXFDFRM_MASK;
            dlcValue = (uint16)CAN_ComputeDLCValue((uint8)(info->dataLength));
            if (info->idType == CANEXCEL_MSG_ID_EXT)
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
            if (info->idType == CANEXCEL_MSG_ID_EXT)
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
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;
    uint32 uS2Ticks = OsIf_MicrosToTicks(CANEXCEL_IP_TIMEOUT_DURATION, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
    timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
    /* Update system lock Status */
    (void)CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].SYSLOCK.DCSYSLOCK;
    while (CANEXCEL_DESCNTSTATUS_LOCKED_HW == CanXL_GetDescControlStatus(CANEXCEL.EXL_DESC_CTR[instance], descNo))
    {
        timeElapsed += OsIf_GetElapsed(&timeStart, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
        if (timeElapsed >= uS2Ticks)
        {
            returnResult = CANEXCEL_STATUS_TIMEOUT;
            break;
        }
    }
    if (returnResult == CANEXCEL_STATUS_SUCCESS)
    {   /* Check if the descriptor is empty, notfull or inactive (*/
        if (CanXL_GetDesciptorState(CANEXCEL.EXL_DESC_CTR[instance], descNo) <= CANEXCEL_DESC_STATE_NOTFULL)
        {
            uint8 noOfPtrList = (uint8)((CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].STA.DCSTA & CANXL_DSC_CONTROL_DCSTA_SYSPOINTER_MASK) >> CANXL_DSC_CONTROL_DCSTA_SYSPOINTER_SHIFT);
            uint8 noOfPtrHW = (uint8)((CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].STA.DCSTA & CANXL_DSC_CONTROL_DCSTA_HWPOINTER_MASK) >> CANXL_DSC_CONTROL_DCSTA_HWPOINTER_SHIFT);
            sint32 value = (sint32)CanXL_GetMDQueueDepth(CANEXCEL.EXL_GRP[instance], descNo) - (sint32)noOfPtrList + (sint32)noOfPtrHW;
            if (value >= (sint32)0)
            {
                if(noOfPtrList == (CanXL_GetMDQueueDepth(CANEXCEL.EXL_GRP[instance], descNo)+1U))
                {
                    /* Roll Over */
                    state->msgDesc[descNo].list[0U] = rxPtrList;
                }
                else
                {
                    state->msgDesc[descNo].list[noOfPtrList] = rxPtrList;
                }
                CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].ACT.DCACT = 1U;
                CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].SYSLOCK.DCSYSLOCK = 1U;
                CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].PUSHPOP.DCSYSPUSH = 0U;
            }
            else
            {
                returnResult = CANEXCEL_STATUS_BUFF_OUT_OF_RANGE;
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
    if (isPolling == FALSE)
    {
        CanXL_SetMsgBuffIntCmd(CANEXCEL.EXL_GRP[instance], descNo);
    }
    returnResult = Canexcel_Ip_RxDescriptor(instance, descNo, (uint32)&RxMsg->Header.Id);
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
    if (isPolling == FALSE)
    {
        CanXL_SetMsgBuffIntCmd(CANEXCEL.EXL_GRP[instance], descNo);
    }
    returnResult = Canexcel_Ip_RxDescriptor(instance, descNo, (uint32)&RxMsg->Header.Id);
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
    timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
    /* Set system lock Status */
    (void)CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].SYSLOCK.DCSYSLOCK;
    while (CANEXCEL_DESCNTSTATUS_LOCKED_HW == CanXL_GetDescControlStatus(CANEXCEL.EXL_DESC_CTR[instance], descNo))
    {
        timeElapsed += OsIf_GetElapsed(&timeStart, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
        if (timeElapsed >= uS2Ticks)
        {
            returnResult = CANEXCEL_STATUS_TIMEOUT;
            break;
        }
    }
    if(returnResult == CANEXCEL_STATUS_SUCCESS)
    {
        /* Check if the descriptor is empty, notfull or inactive */
        if (CanXL_GetDesciptorState(CANEXCEL.EXL_DESC_CTR[instance], descNo) <= CANEXCEL_DESC_STATE_NOTFULL)
        {
            uint8 noOfPtrList = (uint8)((CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].STA.DCSTA & CANXL_DSC_CONTROL_DCSTA_SYSPOINTER_MASK) >> CANXL_DSC_CONTROL_DCSTA_SYSPOINTER_SHIFT);
            uint8 noOfPtrHW = (uint8)((CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].STA.DCSTA & CANXL_DSC_CONTROL_DCSTA_HWPOINTER_MASK) >> CANXL_DSC_CONTROL_DCSTA_HWPOINTER_SHIFT);
            sint32 value = (sint32)CanXL_GetMDQueueDepth(CANEXCEL.EXL_GRP[instance], descNo) - (sint32)noOfPtrList + (sint32)noOfPtrHW;
            if (value >= (sint32)0)
            {
                if(noOfPtrList == (CanXL_GetMDQueueDepth(CANEXCEL.EXL_GRP[instance], descNo)+1U))
                {
                    /* Roll Over */
                    state->msgDesc[descNo].list[0U] = txPtrList;
                }
                else
                {
                    state->msgDesc[descNo].list[noOfPtrList] = txPtrList;
                }
                CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].ACT.DCACT = 1U;
                CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].SYSLOCK.DCSYSLOCK = 1U;
                CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].PUSHPOP.DCSYSPUSH = 0U;
            }
            else
            {
                returnResult = CANEXCEL_STATUS_BUFF_OUT_OF_RANGE;
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
                       | (((uint32)info->retransmission << CANXL_TX_HEADER_RETR_SHIFT) & CANXL_TX_HEADER_RETR_MASK );
    if(info->idType == CANEXCEL_MSG_ID_EXT )
    {
        TxMsg->Header.word3 = CANXL_TX_HEADER_IDE_MASK | (id & CANXL_IP_ID_EXT_MASK) | CANXL_TX_HEADER_XLF_MASK;
    }
    else
    {
        TxMsg->Header.word3 = ((id << CANXL_IP_ID_STD_SHIFT) & CANXL_IP_ID_STD_MASK) | CANXL_TX_HEADER_XLF_MASK;
    }
    TxMsg->Header.word4 = (CANXL_TX_HEADER_FDF_MASK | ((((uint32)info->dataLength - 1u) << CANXL_TX_HEADER_DLC_SHIFT) & CANXL_TX_HEADER_DLC_MASK)) | (((uint32)info->SDT << CANXL_TX_HEADER_SDT_SHIFT)&CANXL_TX_HEADER_SDT_MASK);
}

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
                       | (((uint32)info->retransmission << CANXL_TX_HEADER_RETR_SHIFT) & CANXL_TX_HEADER_RETR_MASK );
    if(info->idType == CANEXCEL_MSG_ID_EXT )
    {
        TxMsg->Header.word3 = CANXL_TX_HEADER_IDE_MASK | (id & CANXL_IP_ID_EXT_MASK);
    }
    else
    {
        TxMsg->Header.word3 = ((id << CANXL_IP_ID_STD_SHIFT) & CANXL_IP_ID_STD_MASK);
    }

    dlcValue = (uint16)CAN_ComputeDLCValue((uint8)(info->dataLength));
    if(info->frame == CANEXCEL_FD_FRAME)
    {
        if (info->enable_brs == TRUE)
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

    if(!CanXL_IsListenOnlyModeEnabled(CANEXCEL.EXL_SIC[instance]))
    {
        if (FALSE == CanXL_IsPwmModeEnable(CANEXCEL.EXL_SIC[instance]))
        {
            Canexcel_Ip_ConfigFdTx(instance, mbIdx, id, info, TxMsg);
            CanXL_SetTxMsgBuffData(info, dataPtr, (uint8 *)&TxMsg->data[0]);
            if (info->is_polling == FALSE)
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
    if(!CanXL_IsListenOnlyModeEnabled(CANEXCEL.EXL_SIC[instance]))
    {
        Canexcel_Ip_ConfigXlTx(instance, mbIdx, id, info, TxMsg);
        CanXL_SetTxMsgBuffData(info, dataPtr, (uint8 *)&TxMsg->data[0]);
        if (info->is_polling == FALSE)
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
    /* Check if the descriptor is active */
    if (CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descIdx].ACT.DCACT == CANXL_DSC_CONTROL_DCACT_ACT_MASK)
    {
        if (CanXL_GetMDQueueDepth(CANEXCEL.EXL_GRP[instance], descIdx) == 0U)
        {
            /* In case of MD Queue depth = 0 */
            if (CanXL_GetDesciptorState(CANEXCEL.EXL_DESC_CTR[instance], descIdx) == CANEXCEL_DESC_STATE_EMPTY)
            {
                returnResult = CANEXCEL_STATUS_SUCCESS;
            }
            if (CanXL_GetDesciptorState(CANEXCEL.EXL_DESC_CTR[instance], descIdx) == CANEXCEL_DESC_STATE_FULL)
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
        if(CanXL_GetDesciptorState(CANEXCEL.EXL_DESC_CTR[instance], descIdx) == CANEXCEL_DESC_STATE_OVERRUN)
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
        if(((CANEXCEL.EXL_RXF_CNT[u8Instance]->RXFSYSACT & CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK) == CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK ) && (Canexcel_Ip_apxState[u8Instance]->rxFifo.isPolling == FALSE))
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
        if(((CANEXCEL.EXL_RXF_CNT[u8Instance]->RXFSYSACT & CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK) == CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK ) && (Canexcel_Ip_apxState[u8Instance]->rxFifo.isPolling == FALSE))
        {
            /* Clear RxFifo Interrupts */
            CANEXCEL.EXL_RXF_CNT[u8Instance]->RXFIEN = ~(CANXL_RXFIFO_CONTROL_RXFIEN_RXFIE_MASK | CANXL_RXFIFO_CONTROL_RXFIEN_RXFEIE_MASK);
        }
        state->isIntActive = FALSE;
        returnResult = CANEXCEL_STATUS_SUCCESS;
    }

    return returnResult;
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
    /* Check if instance initialized */
    if (NULL_PTR != state)
    {
        flag_reg = CanXL_GetMsgBuffIntStatusFlag(CANEXCEL.EXL_GRP[instance], mb_idx);
        while((0U == flag_reg) && (mb_idx < total_mb ))
        {
            mb_idx++;
            flag_reg = CanXL_GetMsgBuffIntStatusFlag(CANEXCEL.EXL_GRP[instance], mb_idx);
        }

        if (0U != flag_reg)
        {
            CanXL_ClearMsgDescIntStatusFlag(CANEXCEL.EXL_GRP[instance], mb_idx);
            state->msgDesc[mb_idx].noPointers = (uint8)((CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[mb_idx].STA.DCSTA & CANXL_DSC_CONTROL_DCSTA_HWPOINTER_MASK) >> CANXL_DSC_CONTROL_DCSTA_HWPOINTER_SHIFT);
            /* First descriptors are always allocated for Transmission */
            if (mb_idx <= CANEXCEL.EXL_GRP[instance]->DSCCTRL)
            {
                /* Process Tx MDESC */
                if (NULL_PTR != state->callback)
                {
                    state->callback(instance, CANEXCEL_EVENT_TX_COMPLETE, mb_idx, state);
                }
            }
            else
            {
                /* Process Rx MDESC */
                if (NULL_PTR != state->callback)
                {
                    state->callback(instance, CANEXCEL_EVENT_RX_COMPLETE, mb_idx, state);
                }
            }
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
    if (NULL_PTR != state->error_callback)
    {
        if (CANEXCEL_STATUS_SUCCESS == Canexcel_GetControllerMRU(instance, &bcanXlStatus, CANXL_MRU_CMD_READ_ST))
        {
            if (((CANEXCEL.EXL_SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CERRIE_MASK) & sysStatus) == CANXL_SIC_SYSIE_CERRIE_MASK)
            {
                CANEXCEL.EXL_SIC[instance]->SYSS = CANXL_SIC_SYSS_CERR_MASK;
                state->error_callback(instance, CANEXCEL_EVENT_ERROR, bcanXlStatus, state);
            }
            if (((CANEXCEL.EXL_SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CFDPERRIE_MASK) & sysStatus) == CANXL_SIC_SYSIE_CFDPERRIE_MASK)
            {
                CANEXCEL.EXL_SIC[instance]->SYSS = CANXL_SIC_SYSS_CFDPERR_MASK;
                state->error_callback(instance, CANEXCEL_EVENT_ERROR_FD, bcanXlStatus, state);
            }
            if (((CANEXCEL.EXL_SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CRXWRNIE_MASK) & sysStatus) == CANXL_SIC_SYSIE_CRXWRNIE_MASK)
            {
                CANEXCEL.EXL_SIC[instance]->SYSS = CANXL_SIC_SYSS_CRXWRN_MASK;
                state->error_callback(instance, CANEXCEL_EVENT_RX_WARNING, bcanXlStatus, state);
            }
            if (((CANEXCEL.EXL_SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CTXWRNIE_MASK) & sysStatus) == CANXL_SIC_SYSIE_CTXWRNIE_MASK)
            {
                CANEXCEL.EXL_SIC[instance]->SYSS = CANXL_SIC_SYSS_CTXWRN_MASK;
                state->error_callback(instance, CANEXCEL_EVENT_TX_WARNING, bcanXlStatus, state);
            }
            if (((CANEXCEL.EXL_SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CDPERRIE_MASK) & sysStatus) == CANXL_SIC_SYSIE_CDPERRIE_MASK)
            {
                CANEXCEL.EXL_SIC[instance]->SYSS = CANXL_SIC_SYSS_CXDPERR_MASK;
                state->error_callback(instance, CANEXCEL_EVENT_ERROR_XL, bcanXlStatus, state);
            }
            if (((CANEXCEL.EXL_SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CPERRIE_MASK) & sysStatus) == CANXL_SIC_SYSIE_CPERRIE_MASK)
            {
                CANEXCEL.EXL_SIC[instance]->SYSS = CANXL_SIC_SYSS_CPASERR_MASK;
                state->error_callback(instance, CANEXCEL_EVENT_PASSIVE, bcanXlStatus, state);
            }
            if (((CANEXCEL.EXL_SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CBOFFIE_MASK) & sysStatus) == CANXL_SIC_SYSIE_CBOFFIE_MASK)
            {
                CANEXCEL.EXL_SIC[instance]->SYSS = CANXL_SIC_SYSS_CBOFF_MASK;
                state->error_callback(instance, CANEXCEL_EVENT_BUSOFF, bcanXlStatus, state);
            }
        }
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_MruIRQHandler
 * Description   : IrqHandler for MRU service unit
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_MruIRQHandler_Activity */
void Canexcel_Ip_MruIRQHandler(uint8 instance)
{
    CANXL_MRU_Type * base = CANEXCEL.EXL_MRU[instance];
    Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    uint8 mbIdx = 0u;
    uint32 mask = 0u;
    if (state != NULL_PTR)
    {
        if ((base->CHXCONFIG[0u].CH_CFG0 & CANXL_MRU_CH_CFG0_IE_MASK) == CANXL_MRU_CH_CFG0_IE_MASK)
        {
            for(;mbIdx < CANXL_IP_MRU_MAILBOX_NO; mbIdx++)
            {
                uint32 tmp = base->CHXCONFIG[0u].CH_CFG1;
                mask = (uint32)( tmp & ((uint32)1U << ((uint32)mbIdx + (uint32)CANXL_MRU_CH_MBSTAT_MBS0_SHIFT)));
                if (mask != 0U)
                {
                if ((base->CHXCONFIG[0u].CH_MBSTAT & mask) == mask)
                {
                    SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_09();
                    state->u8MruMailboxAct |= (1U<<mbIdx);
                    base->CHXCONFIG[0u].CH_MBSTAT |= mask;
                    SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_09();
                }
                }
            }
        }
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
    return ((CANXL_SIC_SYSS_LPMACKF_MASK == (base->SYSS & CANXL_SIC_SYSS_LPMACKF_MASK)) ? TRUE : FALSE);
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
    if (CANEXCEL.EXL_RXF_CNT[instance]->RXFSYSACT == 0U)
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
            for(idx = 0U; idx < filterConfig->noIdFilters; idx++)
            {
                CanXL_ConfigIDFilter(base, &filterConfig->IdFilterPtr[idx], idx);
            }
            if(filterConfig->noActAddrFilters != 0U)
            {
                base->AFCFG |= CANXL_RXFIFO_AFCFG_AADDREN_MASK | CANXL_RXFIFO_AFCFG_ACPTADDR((uint32)filterConfig->noActAddrFilters-1U);
                for(idx = 0U; idx < filterConfig->noActAddrFilters; idx++)
                {
                    CanXL_ConfigAccAddr(base, &filterConfig->AddrFilterPtr[idx], idx);
                }
            }
            if(filterConfig->noSduFilters != 0U)
            {
                base->AFCFG |= CANXL_RXFIFO_AFCFG_ASDUEN_MASK | CANXL_RXFIFO_AFCFG_ACPTSDU((uint32)filterConfig->noSduFilters-1U);
                for(idx = 0U; idx < filterConfig->noSduFilters; idx++)
                {
                    CanXL_ConfigSDUFilter(base, &filterConfig->SduFilterPtr[idx], idx);
                }
            }
            if(filterConfig->noVcanFilters != 0U)
            {
                base->AFCFG |= CANXL_RXFIFO_AFCFG_AVCANEN_MASK | CANXL_RXFIFO_AFCFG_ACPTVCAN((uint32)filterConfig->noVcanFilters-1U);
                for(idx = 0U; idx < filterConfig->noVcanFilters; idx++)
                {
                    CanXL_ConfigVCANFilter(base, &filterConfig->VcanFilterPtr[idx], idx);
                }
            }
            SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_07();
            base->SECAM = filterConfig->SecMask;
            base->SECAV = filterConfig->SecFilter;

            if ((rxFifoCont_base->RXFCSTA & CANXL_RXFIFO_CONTROL_RXFCSTA_SYSLOCK_MASK) == CANXL_RXFIFO_CONTROL_RXFCSTA_SYSLOCK_MASK)
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
        if(descNo < CANXL_MSG_DESCRIPTORS_MSGDSC_COUNT)
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
            eRetVal = Canexcel_GetControllerMRU(instance, &u32StatusError, CANXL_MRU_CMD_READ_ST);
            if (eRetVal == CANEXCEL_STATUS_SUCCESS)
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

    if ((base->BCFG1 & CANXL_SIC_BCFG1_ABRDIS_MASK) == CANXL_SIC_BCFG1_ABRDIS_MASK)
    {
        eRetVal = Canexcel_GetControllerMRU(instance, &u32AckVal, CANXL_MRU_CMD_BUSOFF);
        if((eRetVal == CANEXCEL_STATUS_SUCCESS) && (u32AckVal != CANXL_MRU_CMD_BUSOFF))
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
            for(idx = 0U; idx < Config->noActAddrFilters; idx++)
            {
                CanXL_ConfigAccAddrFilterBank(base, 0U, &Config->AddrFilterPtr[idx], idx);
            }
        }
        if (Config->noSduFilters != 0U)
        {
            base->AFCFG0 |=  CANXL_FILTER_BANK_AFCFG0_ASDUEN_MASK | CANXL_FILTER_BANK_AFCFG0_ACPTSDU((uint32)Config->noSduFilters-1U);
            for(idx = 0U; idx < Config->noSduFilters; idx++)
            {
                CanXL_ConfigSDUFilterBank(base, 0U, &Config->SduFilterPtr[idx], idx);
            }
        }
        if (Config->noVcanFilters != 0U)
        {
            base->AFCFG0 |=  CANXL_FILTER_BANK_AFCFG0_AVCANEN_MASK | CANXL_FILTER_BANK_AFCFG0_ACPTVCAN((uint32)Config->noVcanFilters-1U);
            for(idx = 0U; idx < Config->noVcanFilters; idx++)
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
            for(idx = 0U; idx < Config->noActAddrFilters; idx++)
            {
                CanXL_ConfigAccAddrFilterBank(base, 1U, &Config->AddrFilterPtr[idx], idx);
            }
        }
        if (Config->noSduFilters != 0U)
        {
            base->AFCFG1 |=  CANXL_FILTER_BANK_AFCFG1_ASDUEN_MASK | CANXL_FILTER_BANK_AFCFG1_ACPTSDU((uint32)Config->noSduFilters-1U);
            for(idx = 0U; idx <= Config->noSduFilters; idx++)
            {
                CanXL_ConfigSDUFilterBank(base, 1U, &Config->SduFilterPtr[idx], idx);
            }
        }
        if (Config->noVcanFilters != 0U)
        {
            base->AFCFG1 |=  CANXL_FILTER_BANK_AFCFG1_AVCANEN_MASK | CANXL_FILTER_BANK_AFCFG1_ACPTVCAN((uint32)Config->noVcanFilters-1U);
            for(idx = 0U; idx < Config->noSduFilters; idx++)
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
            for(idx = 0U; idx < Config->noActAddrFilters; idx++)
            {
                CanXL_ConfigAccAddrRejectBank(base, 0U, &Config->AddrFilterPtr[idx], idx);
            }
        }
        if (Config->noSduFilters != 0U)
        {
            base->RFCFG0 |=  CANXL_FILTER_BANK_RFCFG0_RSDUEN_MASK | CANXL_FILTER_BANK_RFCFG0_REJSDU((uint32)Config->noSduFilters-1U);
            for(idx = 0U; idx < Config->noSduFilters; idx++)
            {
                CanXL_ConfigSDURejectBank(base, 0U, &Config->SduFilterPtr[idx], idx);
            }
        }
        if (Config->noVcanFilters != 0U)
        {
            base->RFCFG0 |=  CANXL_FILTER_BANK_RFCFG0_RVCANEN_MASK | CANXL_FILTER_BANK_RFCFG0_REJVCAN((uint32)Config->noVcanFilters-1U);
            for(idx = 0U; idx < Config->noVcanFilters; idx++)
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
            for(idx = 0U; idx < Config->noActAddrFilters; idx++)
            {
                CanXL_ConfigAccAddrRejectBank(base, 1U, &Config->AddrFilterPtr[idx], idx);
            }
        }
        if (Config->noSduFilters != 0U)
        {
            base->RFCFG1 |=  CANXL_FILTER_BANK_RFCFG1_RSDUEN_MASK | CANXL_FILTER_BANK_RFCFG1_REJSDU((uint32)Config->noSduFilters-1U);
            for(idx = 0U; idx < Config->noSduFilters; idx++)
            {
                CanXL_ConfigSDURejectBank(base, 1U, &Config->SduFilterPtr[idx], idx);
            }
        }
        if (Config->noVcanFilters != 0U)
        {
            base->RFCFG1 |=  CANXL_FILTER_BANK_RFCFG1_RVCANEN_MASK | CANXL_FILTER_BANK_RFCFG1_REJVCAN((uint32)Config->noVcanFilters-1U);
            for(idx = 0U; idx < Config->noVcanFilters; idx++)
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
        if ((CANEXCEL.EXL_FILTER[Instance]->AFCFG0 & CANXL_FILTER_BANK_AFCFG0_AADDREN_MASK) == 0U)
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
            if ((CANEXCEL.EXL_SIC[Instance]->SYSMCFG & CANXL_SIC_SYSMCFG_FB1EN_MASK) == CANXL_SIC_SYSMCFG_FB1EN_MASK)
            {
                noFilter = (uint8)((CANEXCEL.EXL_FILTER[Instance]->AFCFG1 & CANXL_FILTER_BANK_AFCFG1_ACPTADDR_MASK) >> CANXL_FILTER_BANK_AFCFG1_ACPTADDR_SHIFT);
                if ((CANEXCEL.EXL_FILTER[Instance]->AFCFG1 & CANXL_FILTER_BANK_AFCFG0_AADDREN_MASK) == 0U)
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
    if(enable == TRUE)
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

    /* It requires syslock before deactivation the MD */
    (void)CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].SYSLOCK.DCSYSLOCK;

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
        (void)CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].SYSLOCK.DCSYSLOCK;
    }
    /* If syslock retrieved, deactivate the MD */
    if(returnResult == CANEXCEL_STATUS_SUCCESS)
    {
        /* as result, the MD is deactivated(syspointer and hwpointer are reset).
         * And it can't participate in the message Tx or Rx process.
        */
        CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].ACT.DCACT = 0U;
        /* Release syslock */
        CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].SYSLOCK.DCSYSLOCK = 1U;
        /* Clear IFLAG */
        CanXL_ClearMsgDescIntStatusFlag(CANEXCEL.EXL_GRP[instance], descNo);
        /* Reset noPointers */
        state->msgDesc[descNo].noPointers = 0U;
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
    }
    return retVal;
}
/** @} */

