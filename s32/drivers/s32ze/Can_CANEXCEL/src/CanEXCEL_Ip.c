/*
 * Copyright 2022 NXP
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

CANXL_SIC_Type * EXL_SIC[] = IP_CANXL_SIC_BASE_PTRS;
MC_RGM_Type * EXL_RGM[] = IP_MC_RGM_BASE_PTRS;
CANXL_MRU_Type * EXL_MRU[] = IP_CANXL_MRU_BASE_PTRS;
CANXL_GRP_CONTROL_Type * EXL_GRP[] = IP_CANXL_GRP_CONTROL_BASE_PTRS;
CANXL_DSC_CONTROL_Type * EXL_DESC_CTR[] = IP_CANXL_DSC_CONTROL_BASE_PTRS;
CANXL_MSG_DESCRIPTORS_Type * EXL_MSGD[] = IP_CANXL_MSG_DESCRIPTORS_BASE_PTRS;
CANXL_RXFIFO_CONTROL_Type * EXL_RXF_CNT[] = IP_CANXL_RXFIFO_CONTROL_BASE_PTRS;
CANXL_RXFIFO_Type * EXL_RXFIFO[] = IP_CANXL_RXFIFO_BASE_PTRS;
CANXL_FILTER_BANK_Type * EXL_FILTER[] = IP_CANXL_FILTER_BANK_BASE_PTRS;
#if (CANEXCEL_IP_HAS_TS_ENABLE == STD_ON)
CAN_TBS_Type * EXL_TBS[] = IP_CANXL_TBS_BASE_PTRS;
#endif
static CANEXCEL_StructType CANEXCEL;


/* Pointer to runtime state structure.*/
static Canexcel_Ip_StateType * Canexcel_Ip_apxState[CANXL_SIC_INSTANCE_COUNT];

static void Canexcel_Ip_MainFunction(uint8 instance, uint8 mb_idx);

static void Canexcel_Ip_MainFunction(uint8 instance, uint8 mb_idx)
{
    Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    uint32 flag_reg;
    uint8 total_mb = (((CANEXCEL.EXL_SIC[instance]->SYSMCFG & CANXL_SIC_SYSMCFG_MAXTXMB_MASK) >> CANXL_SIC_SYSMCFG_MAXTXMB_SHIFT) + ((CANEXCEL.EXL_SIC[instance]->SYSMCFG & CANXL_SIC_SYSMCFG_MAXRXMB_MASK) >> CANXL_SIC_SYSMCFG_MAXRXMB_SHIFT));
    /* Check if instance initialized */
    if ((NULL_PTR != state) && (mb_idx <= total_mb))
    {
        flag_reg = CanXL_GetMsgDescIntStatusFlag(CANEXCEL.EXL_GRP[instance], mb_idx);

        if (0U != flag_reg)
        {
            CanXL_ClearMsgDescIntStatusFlag(CANEXCEL.EXL_GRP[instance], mb_idx);
            state->msgDesc[mb_idx].noPointers = (CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[mb_idx].STA.DCSTA & CANXL_DSC_CONTROL_DCSTA_HWPOINTER_MASK) >> CANXL_DSC_CONTROL_DCSTA_HWPOINTER_SHIFT;
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
            if ((CANEXCEL.EXL_RXF_CNT[instance]->RXFIEN & CANXL_RXFIFO_CONTROL_RXFIEN_RXFIE_MASK) &&  (CANEXCEL.EXL_RXF_CNT[instance]->RXFS & CANXL_RXFIFO_CONTROL_RXFS_RXFF_MASK))
            {
            	if((CANEXCEL.EXL_RXF_CNT[instance]->RXFS & CANXL_RXFIFO_CONTROL_RXFS_RXFF_MASK) == CANXL_RXFIFO_CONTROL_RXFS_RXFF_MASK)
            	{
            		CANEXCEL.EXL_RXF_CNT[instance]->RXFS |= CANXL_RXFIFO_CONTROL_RXFS_RXFF_MASK;
            		state->rxFifo.noPointers = ((CANEXCEL.EXL_RXF_CNT[instance]->RXFCSTA & CANXL_RXFIFO_CONTROL_RXFCSTA_HWPOINTER_MASK) >> CANXL_RXFIFO_CONTROL_RXFCSTA_HWPOINTER_SHIFT);

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
        CANEXCEL.EXL_SIC[instance]->BCFG2 |= CANXL_SIC_BCFG2_TSS((uint32)time_stamp->ts64bit);
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
    if (CANEXCEL_STATUS_SUCCESS == status)
    {
        /* TODO: deactivate all pending tx, this should be move to IPW */

        /* TODO:Clear all flag */

        /* TODO: reset MB status */

        /* TODO: disable all interrupt */

       /* status = FlexCAN_Disable(pBase); */
    }
    return status;
}

Canexcel_Ip_StatusType Canexcel_Ip_Init(uint8 instance, const Canexcel_Ip_ConfigType * Config, Canexcel_Ip_StateType * pState)
{
  CANEXCEL.EXL_SIC = EXL_SIC;
  CANEXCEL.EXL_RGM = EXL_RGM;
  CANEXCEL.EXL_MRU = EXL_MRU;
  CANEXCEL.EXL_GRP = EXL_GRP;
  CANEXCEL.EXL_DESC_CTR = EXL_DESC_CTR;
  CANEXCEL.EXL_MSGD = EXL_MSGD;
  CANEXCEL.EXL_RXFIFO = EXL_RXFIFO;
  CANEXCEL.EXL_RXF_CNT = EXL_RXF_CNT;
  CANEXCEL.EXL_FILTER = EXL_FILTER;
#if (CANEXCEL_IP_HAS_TS_ENABLE == STD_ON)
  CANEXCEL.EXL_TBS = EXL_TBS;
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
      CANEXCEL.EXL_GRP[instance]->DSCCTRL = CANXL_GRP_CONTROL_DSCCTRL_TXDSC(Config->tx_mbdesc-1u);
      CANEXCEL.EXL_SIC[instance]->SYSMCFG |= (CANXL_SIC_SYSMCFG_MAXTXMB(Config->tx_mbdesc) | CANXL_SIC_SYSMCFG_MAXRXMB(Config->rx_mbdesc));
      CanXL_SetFDEnabled(CANEXCEL.EXL_SIC[instance], Config->fd_enable, Config->bitRateSwitch);
      CanXL_SetXLEnable(CANEXCEL.EXL_SIC[instance], Config->xl_enable);
      CanXL_InitBaudrate(CANEXCEL.EXL_SIC[instance], Config);
      CanXL_SetOperationMode(CANEXCEL.EXL_SIC[instance], Config->CanxlMode);
      returnResult = CanXL_ConfigCtrlOptions(CANEXCEL.EXL_SIC[instance], Config->ctrlOptions);
      for(timeElapsed = 0U; timeElapsed<Config->tx_mbdesc; timeElapsed++ )
      {
          /* Better to be moved at init because requires Freeze mode */
          CANEXCEL.EXL_MSGD[instance]->MSGDSC[timeElapsed].LSTPNT.TXLSTPTR = (uint32)&pState->msgDesc[timeElapsed].list;
      }
      for(; timeElapsed<(Config->rx_mbdesc + Config->tx_mbdesc); timeElapsed++ )
      {
          /* Better to be moved at init because requires Freeze mode */
          CANEXCEL.EXL_MSGD[instance]->MSGDSC[timeElapsed].LSTPNT.RXLSTPTR = (uint32)&pState->msgDesc[timeElapsed].list;
      }
      if (TRUE == Config->is_rx_fifo_needed)
      {
    	  CANEXCEL.EXL_RXF_CNT[instance]->RXFC = CANXL_RXFIFO_CONTROL_RXFC_RXFD(Config->pRxFifoConfig->Rx_Fifo_Depth-1U)|CANXL_RXFIFO_CONTROL_RXFC_RXFWTM(Config->pRxFifoConfig->Rx_Fifo_Watermark - 1U);
    	  uint16 dlcValue = 0u;
    	  if(Config->pRxFifoConfig->frameType == CANEXCEL_XL_FRAME)
    	  {
              Canexcel_Ip_apxState[instance]->rxFifo.isXLFrame = TRUE;
    		  dlcValue = Config->pRxFifoConfig->Rx_Fifo_Msg_Size - 1u;
    		  Canexcel_RxXlMsg * RxFifoMsgBuff= (Canexcel_RxXlMsg *)Config->pRxFifoConfig->MsgBuffersPtr;
        	  for(uint8 idx = 0; idx < Config->pRxFifoConfig->Rx_Fifo_Depth; idx++)
        	  {
        		  CANEXCEL.EXL_RXFIFO[instance]->RXFMBP[idx] = (uint32)&RxFifoMsgBuff[idx];
        	  }
    	  }
    	  else
    	  {
              Canexcel_Ip_apxState[instance]->rxFifo.isXLFrame = FALSE;
    		  dlcValue = CAN_ComputeDLCValue(Config->pRxFifoConfig->Rx_Fifo_Msg_Size);
    		  Canexcel_RxFdMsg * RxFifoMsgBuff= (Canexcel_RxFdMsg *)Config->pRxFifoConfig->MsgBuffersPtr;
        	  for(uint8 idx = 0; idx < Config->pRxFifoConfig->Rx_Fifo_Depth; idx++)
        	  {
        		  CANEXCEL.EXL_RXFIFO[instance]->RXFMBP[idx] = (uint32)&RxFifoMsgBuff[idx];
        	  }
    	  }
    	  if (Config->pRxFifoConfig->Rx_Fifo_EnFilterBank1 == TRUE)
    	  {
    		  CANEXCEL.EXL_SIC[instance]->SYSMCFG |= CANXL_SIC_SYSMCFG_FB1EN(1U);
    	  }
    	  else
    	  {
    		  CANEXCEL.EXL_SIC[instance]->SYSMCFG |= CANXL_SIC_SYSMCFG_FB1EN(0U);
    	  }
    	  CANEXCEL.EXL_RXFIFO[instance]->RXFFCTR = CANXL_RXFIFO_RXFFCTR_MBSIZE(dlcValue) | CANXL_RXFIFO_RXFFCTR_KEEPLST(Config->pRxFifoConfig->Rx_Fifo_KeepLast);
    	  /* Activate RxFifo */
    	  CANEXCEL.EXL_RXF_CNT[instance]->RXFSYSACT = CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK;
    	  Canexcel_Ip_apxState[instance]->rxFifo.isPolling = Config->pRxFifoConfig->isPolling;
      }
  }
  if (returnResult == CANEXCEL_STATUS_SUCCESS)
  {
      CanXL_ResetImaskBuff(CANEXCEL.EXL_GRP[instance], instance);
      /* Config Interrupts Line 0, this will not enable them */
      CanXL_ConfigInterrupts(instance);
      /* Clear Callbacks in case of autovariables garbage */
      Canexcel_Ip_apxState[instance] = pState;
      Canexcel_Ip_apxState[instance]->callback = Config->Callback;
      Canexcel_Ip_apxState[instance]->callbackParam = NULL_PTR;
      Canexcel_Ip_apxState[instance]->error_callback = Config->ErrorCallback;
      Canexcel_Ip_apxState[instance]->errorCallbackParam = NULL_PTR;
      Canexcel_Ip_apxState[instance]->isIntActive = FALSE;
  }
  return returnResult;
}

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

Canexcel_Ip_StatusType Canexcel_Ip_ConfigRx(uint8 instance, uint8 descNo, uint32 msgId, Canexcel_Ip_DataInfoType * info)
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
            CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CTRL.RXCTRL |= CANXL_MSG_DESCRIPTORS_RXCTRL_RXXLFRM_MASK;
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
                CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CFG2.MDFLT2XL = CANXL_MSG_DESCRIPTORS_MDFLT2XL_IDSTDa_H(msgId);
                CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CFG2.MDFLT2XL |= CANXL_MSG_DESCRIPTORS_MDFLT2XL_SEC(info->SEC) | CANXL_MSG_DESCRIPTORS_MDFLT2XL_RJCT_SDU(info->STD) | CANXL_MSG_DESCRIPTORS_MDFLT2XL_RJCT_VCAN(info->VCID);
            }
        }
        else if (info->frame == CANEXCEL_FD_FRAME)
        {
            state->msgDesc[descNo].isXLFrame = FALSE;
            CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CTRL.RXCTRL |= CANXL_MSG_DESCRIPTORS_RXCTRL_RXFDFRM_MASK;
            dlcValue = CAN_ComputeDLCValue(info->dataLength);
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
            dlcValue = CAN_ComputeDLCValue(info->dataLength);
            if (info->idType == CANEXCEL_MSG_ID_EXT)
            {
                CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CFG2.MDFLT2FD = CANXL_MSG_DESCRIPTORS_MDFLT2FD_IDE_MASK | msgId;
            }
            else
            {
                CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CFG2.MDFLT2FD = CANXL_MSG_DESCRIPTORS_MDFLT2FD_IDSTDa_H(msgId);
            }
        }
        CANEXCEL.EXL_MSGD[instance]->MSGDSC[descNo].CTRL.RXCTRL |= CANXL_MSG_DESCRIPTORS_RXCTRL_MBSIZE(dlcValue);
    }
    return returnResult;
}

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
    /* Check if the descriptor is empy or inactive (*/
    if ((CanXL_GetDesciptorState(CANEXCEL.EXL_DESC_CTR[instance], descNo) <= CANEXCEL_DESC_STATE_EMPTY) && (returnResult == CANEXCEL_STATUS_SUCCESS))
    {
        state->msgDesc[descNo].list[0U] = rxPtrList;
        CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].ACT.DCACT = 1U;
        CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].SYSLOCK.DCSYSLOCK = 1U;
        CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].PUSHPOP.DCSYSPUSH = 0U;
    }
    else
    {
        returnResult = CANEXCEL_STATUS_ERROR;
    }
    return returnResult;
}

Canexcel_Ip_StatusType Canexcel_Ip_ReceiveFD(uint8 instance, uint8 descNo, Canexcel_RxFdMsg * RxMsg, boolean isPolling)
{
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_ERROR;
    if (isPolling == FALSE)
    {
        CanXL_SetMsgBuffIntCmd(CANEXCEL.EXL_GRP[instance], descNo);
    }
    returnResult = Canexcel_Ip_RxDescriptor(instance, descNo, (uint32)&RxMsg->Header.Id);
    return returnResult;
}

Canexcel_Ip_StatusType Canexcel_Ip_ReceiveXL(uint8 instance, uint8 descNo, Canexcel_RxXlMsg * RxMsg, boolean isPolling)
{
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_ERROR;
    if (isPolling == FALSE)
    {
        CanXL_SetMsgBuffIntCmd(CANEXCEL.EXL_GRP[instance], descNo);
    }
    returnResult = Canexcel_Ip_RxDescriptor(instance, descNo, (uint32)&RxMsg->Header.Id);
    return returnResult;
}

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
        state->msgDesc[descNo].list[0u] = txPtrList;
        CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].ACT.DCACT = 1U;
        CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].SYSLOCK.DCSYSLOCK = 1U;
        CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[descNo].PUSHPOP.DCSYSPUSH = 0u;
    }
    return returnResult;
}

void static Canexcel_Ip_ConfigXlTx(uint8 instance, uint8 mbIdx, uint32 id, Canexcel_Ip_DataInfoType * info, Canexcel_TxXlMsgType * TxMsg)
{
    Canexcel_Ip_apxState[instance]->msgDesc[mbIdx].isXLFrame = TRUE;
    TxMsg->Header.timeStampL = 0U;
    TxMsg->Header.timeStampL = 0U;
    TxMsg->Header.word3 = 0U;
    TxMsg->Header.word2 = 0U;
    TxMsg->Header.word4 = 0U;
    TxMsg->Header.word2 = CANXL_TX_HEADER_MODE_MASK | ((info->priority << CANXL_TX_HEADER_PRIO_SHIFT) & CANXL_TX_HEADER_PRIO_MASK)
                       | ((info->retransmission << CANXL_TX_HEADER_RETR_SHIFT) & CANXL_TX_HEADER_RETR_MASK );
    if(info->idType == CANEXCEL_MSG_ID_EXT )
    {
        TxMsg->Header.word3 = CANXL_TX_HEADER_IDE_MASK | (id & CANXL_IP_ID_EXT_MASK);
    }
    else
    {
        TxMsg->Header.word3 = ((id << CANXL_IP_ID_STD_SHIFT) & CANXL_IP_ID_STD_MASK);
    }
    TxMsg->Header.word4 = CANXL_TX_HEADER_FDF_MASK;
    TxMsg->Header.word3 |= CANXL_TX_HEADER_XLF_MASK;
    TxMsg->Header.word4 |= (((info->dataLength - 1u) << CANXL_TX_HEADER_DLC_SHIFT) & CANXL_TX_HEADER_DLC_MASK);
}

void static Canexcel_Ip_ConfigFdTx(uint8 instance, uint8 mbIdx, uint32 id, Canexcel_Ip_DataInfoType * info, Canexcel_TxFdMsgType * TxMsg)
{
    Canexcel_Ip_apxState[instance]->msgDesc[mbIdx].isXLFrame = FALSE;
    uint16 dlcValue = 0U;
    TxMsg->Header.timeStampL = 0U;
    TxMsg->Header.timeStampL = 0U;
    TxMsg->Header.word3 = 0U;
    TxMsg->Header.word2 = 0U;
    TxMsg->Header.word4 = 0U;
    TxMsg->Header.word2 = CANXL_TX_HEADER_MODE_MASK | ((info->priority << CANXL_TX_HEADER_PRIO_SHIFT) & CANXL_TX_HEADER_PRIO_MASK)
                       | ((info->retransmission << CANXL_TX_HEADER_RETR_SHIFT) & CANXL_TX_HEADER_RETR_MASK );
    if(info->idType == CANEXCEL_MSG_ID_EXT )
    {
        TxMsg->Header.word3 = CANXL_TX_HEADER_IDE_MASK | (id & CANXL_IP_ID_EXT_MASK);
    }
    else
    {
        TxMsg->Header.word3 = ((id << CANXL_IP_ID_STD_SHIFT) & CANXL_IP_ID_STD_MASK);
    }

    dlcValue = CAN_ComputeDLCValue(info->dataLength);
    if(info->frame == CANEXCEL_FD_FRAME)
    {
        TxMsg->Header.word4 = CANXL_TX_HEADER_FDF_MASK;
        if (info->enable_brs == TRUE)
        {
            TxMsg->Header.word4 |= CANXL_TX_HEADER_BRS_MASK;
        }
    }
    TxMsg->Header.word4 |= ((dlcValue << CANXL_TX_HEADER_DLC_SHIFT) & CANXL_TX_HEADER_DLC_MASK);
}

Canexcel_Ip_StatusType Canexcel_Ip_SendFDMsg(uint8 instance, uint8 mbIdx, Canexcel_Ip_DataInfoType * info, uint32 id, uint8 * dataPtr,Canexcel_TxFdMsgType * TxMsg)
{
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_ERROR;
    if(!CanXL_IsListenOnlyModeEnabled(CANEXCEL.EXL_SIC[instance]))
    {
        Canexcel_Ip_ConfigFdTx(instance, mbIdx, id, info, TxMsg);
        CanXL_SetTxMsgBuffData(info, dataPtr, (uint8 *)&TxMsg->data[0]);
        if (info->is_polling == FALSE)
        {
            CanXL_SetMsgBuffIntCmd(CANEXCEL.EXL_GRP[instance], mbIdx);
        }
        returnResult = Canexcel_Ip_TxDescriptor(instance, mbIdx, (uint32)&TxMsg->Header.timeStampL);
    }
    return returnResult;
}

Canexcel_Ip_StatusType Canexcel_Ip_SendXLMsg(uint8 instance, uint8 mbIdx, Canexcel_Ip_DataInfoType * info, uint32 id, uint8 * dataPtr,Canexcel_TxXlMsgType * TxMsg)
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

Canexcel_Ip_StatusType Canexcel_Ip_GetTransferStatus(uint8 instance, uint8 mbIdx)
{
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_NO_TRANSFER_IN_PROGRESS;
    /* Check if the descriptor is active */
    if (CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[mbIdx].ACT.DCACT == CANXL_DSC_CONTROL_DCACT_ACT_MASK)
    {
        if (CanXL_GetDesciptorState(CANEXCEL.EXL_DESC_CTR[instance], mbIdx) == CANEXCEL_DESC_STATE_EMPTY)
        {
            returnResult = CANEXCEL_STATUS_SUCCESS;
        }
        if (CanXL_GetDesciptorState(CANEXCEL.EXL_DESC_CTR[instance], mbIdx) == CANEXCEL_DESC_STATE_FULL)
        {
            returnResult = CANEXCEL_STATUS_BUSY;
        }
        if(CanXL_GetDesciptorState(CANEXCEL.EXL_DESC_CTR[instance], mbIdx) == CANEXCEL_DESC_STATE_OVERRUN)
        {
            returnResult = CANEXCEL_STATUS_ERROR;
        }
    }
    return returnResult;
}

Canexcel_Ip_StatusType Canexcel_Ip_EnterFreezeMode(uint8 instance)
{
    return CanXL_EnterFreezeMode(CANEXCEL.EXL_SIC[instance]);
}

Canexcel_Ip_StatusType Canexcel_Ip_ExitFreezeMode(uint8 instance)
{
    return CanXL_ExitFreezeMode(CANEXCEL.EXL_SIC[instance]);
}

void Canexcel_Ip_EnableInterrupts(uint8 u8Instance)
{
    Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[u8Instance];
    CanXL_EnableInterrupts(CANEXCEL.EXL_SIC[u8Instance], u8Instance);
    if(((CANEXCEL.EXL_RXF_CNT[u8Instance]->RXFSYSACT & CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK) == CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK ) && (Canexcel_Ip_apxState[u8Instance]->rxFifo.isPolling == FALSE))
    {
    	/* Activate RxFifo Interrupts */
    	CANEXCEL.EXL_RXF_CNT[u8Instance]->RXFIEN = CANXL_RXFIFO_CONTROL_RXFIEN_RXFIE_MASK | CANXL_RXFIFO_CONTROL_RXFIEN_RXFEIE_MASK;
    }
    state->isIntActive = TRUE;
}

void Canexcel_Ip_DisableInterrupts(uint8 u8Instance)
{
    Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[u8Instance];
    CanXL_DisableInterrupts(CANEXCEL.EXL_SIC[u8Instance], u8Instance);
    if(((CANEXCEL.EXL_RXF_CNT[u8Instance]->RXFSYSACT & CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK) == CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK ) && (Canexcel_Ip_apxState[u8Instance]->rxFifo.isPolling == FALSE))
    {
    	/* Clear RxFifo Interrupts */
    	CANEXCEL.EXL_RXF_CNT[u8Instance]->RXFIEN = ~(CANXL_RXFIFO_CONTROL_RXFIEN_RXFIE_MASK | CANXL_RXFIFO_CONTROL_RXFIEN_RXFEIE_MASK);
    }
    state->isIntActive = FALSE;
}

void Canexcel_Ip_RxTxIRQHandler(uint8 instance)
{
    Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    uint32 flag_reg;
    uint32 mb_idx = 0U;
    uint8 total_mb = (((CANEXCEL.EXL_SIC[instance]->SYSMCFG & CANXL_SIC_SYSMCFG_MAXTXMB_MASK) >> CANXL_SIC_SYSMCFG_MAXTXMB_SHIFT) + ((CANEXCEL.EXL_SIC[instance]->SYSMCFG & CANXL_SIC_SYSMCFG_MAXRXMB_MASK) >> CANXL_SIC_SYSMCFG_MAXRXMB_SHIFT));
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
            state->msgDesc[mb_idx].noPointers = (CANEXCEL.EXL_DESC_CTR[instance]->DSCMBCTRLAR[mb_idx].STA.DCSTA & CANXL_DSC_CONTROL_DCSTA_HWPOINTER_MASK) >> CANXL_DSC_CONTROL_DCSTA_HWPOINTER_SHIFT;
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
            if ((CANEXCEL.EXL_RXF_CNT[instance]->RXFIEN & CANXL_RXFIFO_CONTROL_RXFIEN_RXFIE_MASK) &&  (CANEXCEL.EXL_RXF_CNT[instance]->RXFS & CANXL_RXFIFO_CONTROL_RXFS_RXFF_MASK))
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

void Canexcel_Ip_ErrIRQHandler(uint8 instance)
{
    Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    uint32 sysStatus = CANEXCEL.EXL_SIC[instance]->SYSS;

    /* Process CANEXCEL Error */
    if (NULL_PTR != state->error_callback)
    {
        if ((CANEXCEL.EXL_SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CERRIE_MASK) & sysStatus)
        {
            CANEXCEL.EXL_SIC[instance]->SYSS |= CANXL_SIC_SYSS_CERR_MASK;
            state->error_callback(instance, CANEXCEL_EVENT_ERROR, sysStatus, state);
        }
        if ((CANEXCEL.EXL_SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CFDPERRIE_MASK) & sysStatus)
        {
            CANEXCEL.EXL_SIC[instance]->SYSS |= CANXL_SIC_SYSS_CFDPERR_MASK;
            state->error_callback(instance, CANEXCEL_EVENT_ERROR_FD, sysStatus, state);
        }
        if ((CANEXCEL.EXL_SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CRXWRNIE_MASK) & sysStatus)
        {
            CANEXCEL.EXL_SIC[instance]->SYSS |= CANXL_SIC_SYSS_CRXWRN_MASK;
            state->error_callback(instance, CANEXCEL_EVENT_RX_WARNING, sysStatus, state);
        }
        if ((CANEXCEL.EXL_SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CTXWRNIE_MASK) & sysStatus)
        {
            CANEXCEL.EXL_SIC[instance]->SYSS |= CANXL_SIC_SYSS_CTXWRN_MASK;
            state->error_callback(instance, CANEXCEL_EVENT_TX_WARNING, sysStatus, state);
        }
        if ((CANEXCEL.EXL_SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CDPERRIE_MASK) & sysStatus)
        {
            CANEXCEL.EXL_SIC[instance]->SYSS |= CANXL_SIC_SYSS_CXDPERR_MASK;
            state->error_callback(instance, CANEXCEL_EVENT_ERROR_XL, sysStatus, state);
        }
        if ((CANEXCEL.EXL_SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CPERRIE_MASK) & sysStatus)
        {
            CANEXCEL.EXL_SIC[instance]->SYSS |= CANXL_SIC_SYSS_CPASERR_MASK;
            state->error_callback(instance, CANEXCEL_EVENT_ERROR_XL, sysStatus, state);
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
Canexcel_Ip_StatusType Canexcel_Ip_ConfigRxFifo(uint8 instance, Canexcel_Ip_RxFifoFilter * filterConfig)
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
			base->AFCFG = CANXL_RXFIFO_AFCFG_ACPTID(filterConfig->noIdFilters-1U);
			for(idx = 0U; idx < filterConfig->noIdFilters; idx++)
			{
				CanXL_ConfigIDFilter(base, &filterConfig->IdFilterPtr[idx], idx);
			}
			if(filterConfig->noActAddrFilters != 0)
			{
				base->AFCFG |= CANXL_RXFIFO_AFCFG_AADDREN_MASK | CANXL_RXFIFO_AFCFG_ACPTADDR(filterConfig->noActAddrFilters-1U);
				for(idx = 0U; idx < filterConfig->noActAddrFilters; idx++)
				{
					CanXL_ConfigAccAddr(base, &filterConfig->AddrFilterPtr[idx], idx);
				}
			}
			if(filterConfig->noSduFilters != 0)
			{
				base->AFCFG |= CANXL_RXFIFO_AFCFG_ASDUEN_MASK | CANXL_RXFIFO_AFCFG_ACPTSDU(filterConfig->noSduFilters-1U);
				for(idx = 0U; idx < filterConfig->noSduFilters; idx++)
				{
					CanXL_ConfigSDUFilter(base, &filterConfig->SduFilterPtr[idx], idx);
				}
			}
			if(filterConfig->noVcanFilters != 0)
			{
				base->AFCFG |= CANXL_RXFIFO_AFCFG_AVCANEN_MASK | CANXL_RXFIFO_AFCFG_ACPTVCAN(filterConfig->noVcanFilters-1U);
				for(idx = 0U; idx < filterConfig->noVcanFilters; idx++)
				{
					CanXL_ConfigSDUFilter(base, &filterConfig->VcanFilterPtr[idx], idx);
				}
			}
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

boolean Canexcel_Ip_IsXLFrameType(uint8 instance, uint8 descNo)
{
    Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    if (descNo < CANEXCEL_IP_MB_RXFIFO)
    {    
        return (state->msgDesc[descNo].isXLFrame);
    }
    else
    {
        return (state->rxFifo.isXLFrame);
    }

}
/** @} */

