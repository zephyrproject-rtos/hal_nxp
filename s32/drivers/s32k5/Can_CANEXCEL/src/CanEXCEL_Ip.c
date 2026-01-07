/*
 * Copyright 2024-2025 NXP
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

#define MAX_CAN_FD_FRAME_SIZE                   (uint8)(64u)

#define CAN_43_CANEXCEL_START_SEC_VAR_INIT_UNSPECIFIED
#include "Can_43_CANEXCEL_MemMap.h"


static CANXL_SIC_Type * SIC_PTR[] = IP_CANXL_SIC_BASE_PTRS;
static CANXL_MRU_Type * MRU_PTR[] = IP_CANXL_MRU_BASE_PTRS;
static CANXL_GRP_CONTROL_Type * GRP_PTR[] = IP_CANXL_GRP_CONTROL_BASE_PTRS;
static CANXL_DSC_CONTROL_Type * DESC_CTR_PTR[] = IP_CANXL_DSC_CONTROL_BASE_PTRS;
static CANXL_MSG_DESCRIPTORS_Type * MSGD_PTR[] = IP_CANXL_MSG_DESCRIPTORS_BASE_PTRS;
static CANXL_RXFIFO_CONTROL_Type * RXF_CNT_PTR[] = IP_CANXL_RXFIFO_CONTROL_BASE_PTRS;
static CANXL_RXFIFO_Type * RXFIFO_PTR[] = IP_CANXL_RXFIFO_BASE_PTRS;
static CANXL_FILTER_BANK_Type * FILTER_PTR[] = IP_CANXL_FILTER_BANK_BASE_PTRS;
#if (CANEXCEL_IP_HAS_TS_ENABLE == STD_ON)
static CAN_TBS_Type * TBS_PTR[] = IP_CANXL_TBS_BASE_PTRS;
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

static Canexcel_Ip_StatusType Canexcel_GetControllerMRU(uint8 instance, uint32 * pValue, uint8 command);

static void Canexcel_Ip_ConfInit(uint8 instance, const Canexcel_Ip_ConfigType * Config);

static void Canexcel_ProcessErrIRQ(uint8 instance,const Canexcel_Ip_StateType * state, uint32 bcanXlStatus, uint32 sysStatus);

static uint8 Canexcel_Ip_GetNumOfRxFifoBuffAvailable(uint8 u8Instance);

/**
 *  @brief     Get the number of RX FIFO buffers with completed tranfser
 *  @details   This function returns the total number of buffers completed transfer.
 *
 *  Note:      For Rx buffer, completed transfer means that a frame was successfully received by the buffer.
 *
 *  @param[in] u8Instance A CanEXCEL instance number
 *  @return    Number of buffers completed transfer
 */
/* implements Canexcel_Ip_GetNumOfRxFifoBuffAvailable_Activity */
static uint8 Canexcel_Ip_GetNumOfRxFifoBuffAvailable(uint8 u8Instance)
{
    const Canexcel_Ip_RXFIFOhandleType * pRxFifoState = &Canexcel_Ip_apxState[u8Instance]->rxFifo;
    uint8 u8NumPtr = 0U;
    uint8 u8QueueDepth = (uint8)((CANEXCEL.RXF_CNT[u8Instance]->RXFC & CANXL_RXFIFO_CONTROL_RXFC_RXFD_MASK) + 1u);
    uint8 u8CurrentHwIdx = 0U;
    Canexcel_Ip_RxFifoState RxFifoStatus = CanXL_GetRxFifoStatus(CANEXCEL.RXF_CNT[u8Instance], NULL_PTR, &u8CurrentHwIdx);
    /* This function will not modify pRxFifoState->currBufferIdx as it only read queue information */
    uint8 currBufferIdxTemp = pRxFifoState->currBufferIdx;

    if (u8CurrentHwIdx > currBufferIdxTemp)
    {
        u8NumPtr = (uint8)(u8CurrentHwIdx - currBufferIdxTemp);
    }
    else if ((u8CurrentHwIdx < currBufferIdxTemp))
    {
        /* u8QueueDepth is maximum 32 and it is always greater than or equal to currBufferIdxTemp, u8CurrentHwIdx */
        u8NumPtr = (uint8)(u8QueueDepth - currBufferIdxTemp + u8CurrentHwIdx);
    }
    else /* (u8CurrentHwIdx is equal to currBufferIdxTemp) */
    {
        /* If the queue is full it means that it's roll over */
        if (CANEXCEL_FIFO_STATE_FULL == RxFifoStatus)
        {
            u8NumPtr = u8QueueDepth;
        }
    }

    return u8NumPtr;
}


 /*!
 * @brief Set the corresponding Message Descriptor interrupt
 *
 * @param   base        The CanXL MSG Grup Control base address
 * @param   mb_idx      Index of the message descriptor
 */
static inline void CanXL_SetMsgBuffIntCmd(CANXL_GRP_CONTROL_Type * base, uint8 msgBuffIdx)
{
    uint8 ImaskCnt = (msgBuffIdx/32U) ;
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
static inline void CanXL_ClearMsgBuffIntCmd(CANXL_GRP_CONTROL_Type * base, uint8 mb_idx)
{
    uint8 ImaskCnt =  (mb_idx/32U) ;
    /* Enable the corresponding message buffer Interrupt */
    uint32 temp = 1UL << (mb_idx % 32U);
    SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_13();
    base->MSGIMASK[ImaskCnt] &= (~temp);
    SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_13();
}

 /*!
 * @brief Get the corresponding Message Descriptor interrupt enable flag
 *
 * @param   base        The CanXL MSG Grup Control base address
 * @param   mb_idx      Index of the message descriptor
 */
static inline boolean CanXL_GetMsgBuffIntCmd(const CANXL_GRP_CONTROL_Type * base, uint8 msgBuffIdx)
{
    uint8 ImaskCnt = (msgBuffIdx/32U) ;
    /* Enable the corresponding message buffer Interrupt */
    uint32 temp = 1UL << (msgBuffIdx % 32U);
    return ((base->MSGIMASK[ImaskCnt] & temp) != 0u)? TRUE: FALSE;
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
    CANXL_MRU_Type * base = CANEXCEL.MRU[instance];
    Canexcel_Ip_StatusType status = CANEXCEL_STATUS_SUCCESS;
    uint32 uS2Ticks = OsIf_MicrosToTicks(CANEXCEL_IP_TIMEOUT_DURATION, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(instance < CANXL_SIC_INSTANCE_COUNT));
    DevAssert((boolean volatile)(pValue != NULL_PTR));
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
        base->CHXCONFIG[0u].CH_MBSTAT = CANXL_MRU_CH_MBSTAT_MBS0_MASK | CANXL_MRU_CH_MBSTAT_MBS3_MASK;
        base->CHXCONFIG[0u].CH_CFG0 |= CANXL_MRU_CH_CFG0_MBE0_MASK | CANXL_MRU_CH_CFG0_MBE3_MASK | CANXL_MRU_CH_CFG0_IE_MASK;
        base->CHXCONFIG[0u].CH_CFG1 |= CANXL_MRU_CH_CFG1_MBIC3_MASK;
        SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_08();
        base->CH1_MB0 = command;
        timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
        while((base->CHXCONFIG[0u].CH_MBSTAT & CANXL_MRU_CH_MBSTAT_MBS3_MASK) == 0U)
        {
            timeElapsed = OsIf_GetElapsed(&timeStart, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
            if (timeElapsed >= uS2Ticks)
            {
                status = CANEXCEL_STATUS_TIMEOUT;
                break;
            }
            else
            {
                uS2Ticks -= timeElapsed;
            }
        }
        if ((base->CHXCONFIG[0u].CH_MBSTAT & CANXL_MRU_CH_MBSTAT_MBS3_MASK) != 0U)
        {
            * pValue = base->CH1_MB3;
        }
        base->CHXCONFIG[0u].CH_MBSTAT = CANXL_MRU_CH_MBSTAT_MBS0_MASK | CANXL_MRU_CH_MBSTAT_MBS3_MASK;
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
    const Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    uint32 flag_reg;
    uint8 total_mb = (uint8)((((CANEXCEL.SIC[instance]->SYSMCFG & CANXL_SIC_SYSMCFG_MAXTXMB_MASK) >> CANXL_SIC_SYSMCFG_MAXTXMB_SHIFT) + ((CANEXCEL.SIC[instance]->SYSMCFG & CANXL_SIC_SYSMCFG_MAXRXMB_MASK) >> CANXL_SIC_SYSMCFG_MAXRXMB_SHIFT)));

    /* Check if instance initialized */
    if ((NULL_PTR != state) && (mb_idx <= total_mb))
    {
        flag_reg = CanXL_GetMsgDescIntStatusFlag(CANEXCEL.GRP[instance], mb_idx);

        if (0U != flag_reg)
        {
            CanXL_ClearMsgDescIntStatusFlag(CANEXCEL.GRP[instance], mb_idx);

            /* First descriptors are always allocated for Transmission */
            if (mb_idx <= CANEXCEL.GRP[instance]->DSCCTRL)
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
    if ((NULL_PTR != state) && (mb_idx == CANEXCEL_IP_MB_RXFIFO))
    {
        if (1U == CANEXCEL.RXF_CNT[instance]->RXFSYSACT)
        {
            if ((CANEXCEL.RXF_CNT[instance]->RXFS & CANXL_RXFIFO_CONTROL_RXFS_RXFF_MASK) != 0U)
            {
                CANEXCEL.RXF_CNT[instance]->RXFS |= CANXL_RXFIFO_CONTROL_RXFS_RXFF_MASK;

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
  CanXL_SetFDEnabled(CANEXCEL.SIC[instance], Config->fd_enable, Config->bitRateSwitch);
  CanXL_SetXLEnable(CANEXCEL.SIC[instance], Config->xl_enable);
  CanXL_InitBaudrate(CANEXCEL.SIC[instance], Config);
  CanXL_SetOperationMode(CANEXCEL.SIC[instance], Config->CanxlMode);
  /** To be develop for Queue Operation Config */
  CanXL_SetMDQueueConfigs(CANEXCEL.GRP[instance], Config->QueueMDConfig);
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

    CANEXCEL.RXF_CNT[instance]->RXFC = CANXL_RXFIFO_CONTROL_RXFC_RXFD((uint32)Config->pRxFifoConfig.Rx_Fifo_Depth-1U)|CANXL_RXFIFO_CONTROL_RXFC_RXFWTM((uint32)Config->pRxFifoConfig.Rx_Fifo_Watermark - 1U);

    dlcValue = Config->pRxFifoConfig.Rx_Fifo_Msg_Size - 1u;
    const uint32 *RxFifoMsgBuff = Config->pRxFifoConfig.MsgBuffersPtr;
    for (uint8 idx = 0u; idx < Config->pRxFifoConfig.Rx_Fifo_Depth; idx++)
    {
        CANEXCEL.RXFIFO[instance]->RXFMBP[idx] = (uint32)&RxFifoMsgBuff[idx * (CANEXCEL_IP_MAX_SIZEOF_FIFO_OBJ_HEADER + (Config->pRxFifoConfig.Rx_Fifo_Msg_Size / sizeof(uint32)))];
    }

    uint8 aux = (Config->pRxFifoConfig.Rx_Fifo_KeepLast == FALSE) ? 0U : 1U;
    CANEXCEL.RXFIFO[instance]->RXFFCTR = (CANXL_RXFIFO_RXFFCTR_MBSIZE((uint32)dlcValue) | CANXL_RXFIFO_RXFFCTR_KEEPLST((uint32)aux));
    /* Activate RxFifo */
    CANEXCEL.RXF_CNT[instance]->RXFSYSACT = CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK;
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
    DevAssert((boolean volatile)(instance < CANXL_SIC_INSTANCE_COUNT));
#endif
    const CANXL_SIC_Type * base = CANEXCEL.SIC[instance];
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
    DevAssert((boolean volatile)(instance < CANXL_SIC_INSTANCE_COUNT));
#endif

    if (TRUE == CanXL_IsFreezeMode(CANEXCEL.SIC[instance]))
    {
        CanXL_SetTimeStampCaputre(CANEXCEL.SIC[instance], time_stamp->capture);
        /* If ts64bit True will enable the timestamp as 64 bits if false will set to 32 bits */
        CANEXCEL.SIC[instance]->BCFG2 |= (TRUE == time_stamp->ts64bit) ? CANXL_SIC_BCFG2_TSS(1U) : CANXL_SIC_BCFG2_TSS(0U);
        returnResult = CANEXCEL_STATUS_SUCCESS;
        CanXL_SetTimeBaseSource(CANEXCEL.TBS[instance], time_stamp->src);
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
    DevAssert((boolean volatile)(instance < CANXL_SIC_INSTANCE_COUNT));
#endif
    CANXL_SIC_Type * base = CANEXCEL.SIC[instance];
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
    while ((CANEXCEL.SIC[instance]->SYSS & CANXL_SIC_SYSS_FRZACKF_MASK) == 0U)
    {
        timeElapsed = OsIf_GetElapsed(&timeStart, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
        if (timeElapsed >= uS2Ticks)
        {
            returnResult = CANEXCEL_STATUS_TIMEOUT;
            break;
        }
        else
        {
            uS2Ticks -= timeElapsed;
        }
    }

    if (CANEXCEL_STATUS_SUCCESS == returnResult)
    {
        returnResult = CanXL_SoftReset(CANEXCEL.SIC[instance]);
    }

    if (CANEXCEL_STATUS_SUCCESS == returnResult)
    {
        returnResult = CanXL_EnterFreezeMode(CANEXCEL.SIC[instance]);
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

  CANEXCEL.SIC = SIC_PTR;
  CANEXCEL.MRU = MRU_PTR;
  CANEXCEL.GRP = GRP_PTR;
  CANEXCEL.DESC_CTR = DESC_CTR_PTR;
  CANEXCEL.MSGD = MSGD_PTR;
  CANEXCEL.RXFIFO = RXFIFO_PTR;
  CANEXCEL.RXF_CNT = RXF_CNT_PTR;
  CANEXCEL.FILTER = FILTER_PTR;
#if (CANEXCEL_IP_HAS_TS_ENABLE == STD_ON)
  CANEXCEL.TBS = TBS_PTR;
#endif
  Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(instance < CANXL_SIC_INSTANCE_COUNT));
    DevAssert((boolean volatile)(Config != NULL_PTR));
    DevAssert((boolean volatile)(pState != NULL_PTR));
#endif
  uint8 u8MdCnt = 0U;
  uint8 u8MbCnt = 0U;

  pState->msgDescListPtr = Config->allocatedMsgDescList;

  /* Reset and put controller to freeze mode before setting registers.
     By executing soft reset, the internal logic and memory mapped registers of CANEXCEL will be reset.
     This will clear all pending interrupt flags as required by requirement CPR_RTD_01182.*/
  returnResult = Canexcel_ResetController(instance);

  if (CANEXCEL_STATUS_SUCCESS == returnResult)
  {
      /* CANEXCEL Data Memory Write Access Enable for Host */
      CANEXCEL.SIC[instance]->SYSMCFG &= ~CANXL_SIC_SYSMCFG_DRWRDIS_MASK;
      /* Clear Memory ram and initialize it */
      CanXL_ClearRAM(&CANEXCEL, instance);
      CANEXCEL.GRP[instance]->DSCCTRL = CANXL_GRP_CONTROL_DSCCTRL_TXDSC((uint32)Config->tx_mbdesc-1u);
      CANEXCEL.SIC[instance]->SYSMCFG |= (CANXL_SIC_SYSMCFG_MAXTXMB(Config->tx_mbdesc) | CANXL_SIC_SYSMCFG_MAXRXMB(Config->rx_mbdesc));
      Canexcel_Ip_ConfInit(instance, Config);

      returnResult = CanXL_ConfigCtrlOptions(CANEXCEL.SIC[instance], Config->ctrlOptions);
      if (CANEXCEL_STATUS_SUCCESS == returnResult)
      {
        Canexcel_Ip_apxState[instance] = pState;
        for (u8MdCnt = 0U; u8MdCnt<Config->tx_mbdesc; u8MdCnt++)
        {
            /* Better to be moved at init because requires Freeze mode */
            CANEXCEL.MSGD[instance]->MSGDSC[u8MdCnt].LSTPNT.TXLSTPTR = (uint32)&pState->msgDescListPtr[u8MdCnt].list;
        }
        for (; u8MdCnt < (Config->rx_mbdesc + Config->tx_mbdesc); u8MdCnt++)
        {
            /* Better to be moved at init because requires Freeze mode */
            CANEXCEL.MSGD[instance]->MSGDSC[u8MdCnt].LSTPNT.RXLSTPTR = (uint32)&pState->msgDescListPtr[u8MdCnt].list;
        }

        if (TRUE == Config->is_rx_fifo_needed)
        {
            Canexcel_InitRxFIFO(instance, Config);
        }
        CanXL_ResetImaskBuff(CANEXCEL.GRP[instance]);
        /* Clear Callbacks in case of autovariables garbage */
        Canexcel_Ip_apxState[instance]->callback = Config->Callback;
        Canexcel_Ip_apxState[instance]->callbackParam = NULL_PTR;
        Canexcel_Ip_apxState[instance]->error_callback = Config->ErrorCallback;
        Canexcel_Ip_apxState[instance]->errorCallbackParam = NULL_PTR;
        Canexcel_Ip_apxState[instance]->isIntActive = FALSE;
        /* Clear all pending flags */
        for (u8MdCnt = 0U; u8MdCnt < (Config->rx_mbdesc + Config->tx_mbdesc); u8MdCnt++)
        {
            Canexcel_Ip_apxState[instance]->msgDescListPtr[u8MdCnt].lastHwIdex = 0U;
            Canexcel_Ip_apxState[instance]->msgDescListPtr[u8MdCnt].noPointers = 0U;
            Canexcel_Ip_apxState[instance]->msgDescListPtr[u8MdCnt].currBufferIdx = 0U;
            for (u8MbCnt = 0U; u8MbCnt < 16U; u8MbCnt++)
            {
                Canexcel_Ip_apxState[instance]->msgDescListPtr[u8MdCnt].isPending[u8MbCnt] = FALSE;
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
 * Function Name : Canexcel_Ip_ConfigRx
 * Description   : Set Individual Rx ID for Message Descriptor, and config the frame parameters from DataInfoType.
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_ConfigRx_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_ConfigRx(uint8 instance, uint8 descNo, const Canexcel_Ip_RxMdConfigType * info)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(instance < CANXL_SIC_INSTANCE_COUNT));
    DevAssert((boolean volatile)(descNo < CANXL_DSC_CONTROL_DSCMBCTRLAR_COUNT));
    DevAssert((boolean volatile)(NULL_PTR != info));
#endif
    uint16 dlcValue = 0U;
    uint32 timeStart = 0U;
    uint32 uS2Ticks = 0U;
    uint32 timeElapsed = 0U;
    uint8 RTRRRSMask = (TRUE == info->RTRRRSMask) ? 1U : 0U;
    uint8 IDEMask = (TRUE == info->IDEMask) ? 1U : 0U;
    uint8 MskRNG = (CANEXCEL_IP_RX_FIFO_MASK_FILTER == info->IdFilterType) ? 0U : 1U;
    uint8 RTRRRS = (TRUE == info->RTRRRS) ? 1U : 0U;
    uint32 RXCTRLTemp = 0U;

    const Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;

    /* TODO: consider to remove this check */
    if (CanXL_GetDesciptorState(CANEXCEL.DESC_CTR[instance], descNo) >= CANEXCEL_DESC_STATE_FULL)
    {
        returnResult = CANEXCEL_STATUS_BUSY;
    }

    if (CANEXCEL_STATUS_SUCCESS == returnResult)
    {
        /* Lock the Descriptor before re-configure it  */
        #if (CANEXCEL_IP_HAS_SYSLOCK01 == STD_ON)
        CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK = 1U;
        #else
        (void)CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK;
        #endif

        /* Wait until syslock is retrieved */
        uS2Ticks = OsIf_MicrosToTicks(CANEXCEL_IP_TIMEOUT_DURATION, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
        timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
        while (CANEXCEL_DESCNTSTATUS_LOCKED_SYS != CanXL_GetDescControlStatus(CANEXCEL.DESC_CTR[instance], descNo))
        {
            timeElapsed = OsIf_GetElapsed(&timeStart, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
            if (timeElapsed >= uS2Ticks)
            {
                returnResult = CANEXCEL_STATUS_TIMEOUT;
                break;
            }
            else
            {
                uS2Ticks -= timeElapsed;
            }
            #if (CANEXCEL_IP_HAS_SYSLOCK01 == STD_ON)
            CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK = 1U;
            #else
            (void)CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK;
            #endif
        }
    }

    if (CANEXCEL_STATUS_SUCCESS == returnResult)
    {
        if (info->frame == CANEXCEL_XL_FRAME)
        {
            state->msgDescListPtr[descNo].isXLFrame = TRUE;
            RXCTRLTemp = CANXL_MSG_DESCRIPTORS_RXCTRL_RXXLFRM_MASK;
            dlcValue = info->MbSize - (uint16)1U;
            if (info->idType == CANEXCEL_MSG_ID_EXT)
            {
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
                /* CanXL frame type supports only STD ID frame types */
                DevAssert((boolean volatile)(FALSE));
#endif
            }
            else
            {
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
                /* Must provide XlParamsFilterPtr when configuring CANEXCEL_XL_FRAME */
                DevAssert((boolean volatile)(NULL_PTR != info->XlParamsFilterPtr));
#endif
                CANEXCEL.MSGD[instance]->MSGDSC[descNo].CFG1.MDFLT1XL = CANXL_MSG_DESCRIPTORS_MDFLT1XL_SECMSK((TRUE == info->XlParamsFilterPtr->SecMask) ? 1U : 0U) | \
                                                                            CANXL_MSG_DESCRIPTORS_MDFLT1XL_RRSMSK(RTRRRSMask) | \
                                                                            CANXL_MSG_DESCRIPTORS_MDFLT1XL_IDEMSK(IDEMask) | \
                                                                            CANXL_MSG_DESCRIPTORS_MDFLT1XL_MSKRNG(MskRNG) | \
                                                                            CANXL_MSG_DESCRIPTORS_MDFLT1XL_IDSTDa_L(info->IdL) | \
                                                                            CANXL_MSG_DESCRIPTORS_MDFLT1XL_FBSEL(info->XlParamsFilterPtr->FilterBankSel) | \
                                                                            CANXL_MSG_DESCRIPTORS_MDFLT1XL_ACCPT_ADDR(info->XlParamsFilterPtr->AccptAddrPos) | \
                                                                            CANXL_MSG_DESCRIPTORS_MDFLT1XL_ACCPT_SDU(info->XlParamsFilterPtr->AccptSduPos) | \
                                                                            CANXL_MSG_DESCRIPTORS_MDFLT1XL_ACCPT_VCAN(info->XlParamsFilterPtr->AccptVcanPos);

                CANEXCEL.MSGD[instance]->MSGDSC[descNo].CFG2.MDFLT2XL = CANXL_MSG_DESCRIPTORS_MDFLT2XL_SEC((TRUE == info->XlParamsFilterPtr->Sec) ? 1U : 0U) | \
                                                                            CANXL_MSG_DESCRIPTORS_MDFLT2XL_RRS(RTRRRS) | \
                                                                            CANXL_MSG_DESCRIPTORS_MDFLT2XL_IDSTDa_H(info->IdH) | \
                                                                            CANXL_MSG_DESCRIPTORS_MDFLT2XL_RJCT_ADDR(info->XlParamsFilterPtr->RejAddrPos) | \
                                                                            CANXL_MSG_DESCRIPTORS_MDFLT2XL_RJCT_SDU(info->XlParamsFilterPtr->RejSduPos) | \
                                                                            CANXL_MSG_DESCRIPTORS_MDFLT2XL_RJCT_VCAN(info->XlParamsFilterPtr->RejVcanPos);

                RXCTRLTemp |= CANXL_MSG_DESCRIPTORS_RXCTRL_ADDRROA((TRUE == info->XlParamsFilterPtr->AddrRoa) ? 1U : 0U);
                RXCTRLTemp |= CANXL_MSG_DESCRIPTORS_RXCTRL_SDUROA((TRUE == info->XlParamsFilterPtr->SduRoa) ? 1U : 0U);
                RXCTRLTemp |= CANXL_MSG_DESCRIPTORS_RXCTRL_VCANROA((TRUE == info->XlParamsFilterPtr->VcanRoa) ? 1U : 0U);
            }
        }
        else
        {
            state->msgDescListPtr[descNo].isXLFrame = FALSE;

            if (CANEXCEL_FD_FRAME == info->frame)
            {
                RXCTRLTemp = CANXL_MSG_DESCRIPTORS_RXCTRL_RXFDFRM_MASK;
            }
        #if (CANEXCEL_IP_FEATURE_HAS_MSGDESC_RXCTRL_FDMODSEL == STD_ON)
            else if (CANEXCEL_CLASIC_FD_FRAME == info->frame)
            {
                RXCTRLTemp = CANXL_MSG_DESCRIPTORS_RXCTRL_FDMODSEL_MASK;
            }
        #endif
            else
            {
                /* CANEXCEL_CLASIC_FRAME, nothing to do, RXCTRLTemp = 0 */
            }

            dlcValue = (uint16)CAN_ComputeDLCValue((info->MbSize < MAX_CAN_FD_FRAME_SIZE)?(uint8)(info->MbSize):MAX_CAN_FD_FRAME_SIZE);

            CANEXCEL.MSGD[instance]->MSGDSC[descNo].CFG1.MDFLT1FD = CANXL_MSG_DESCRIPTORS_MDFLT1FD_RTRMSK(RTRRRSMask) | \
                                                                        CANXL_MSG_DESCRIPTORS_MDFLT1FD_IDEMSK(IDEMask) | \
                                                                        CANXL_MSG_DESCRIPTORS_MDFLT1FD_MSKRNG(MskRNG) | \
                                                                        ((CANEXCEL_MSG_ID_EXT == info->idType) ? info->IdL : CANXL_MSG_DESCRIPTORS_MDFLT1FD_IDSTDa_L(info->IdL));

            CANEXCEL.MSGD[instance]->MSGDSC[descNo].CFG2.MDFLT2FD = CANXL_MSG_DESCRIPTORS_MDFLT2FD_RTR(RTRRRS) | \
                                                                        ((CANEXCEL_MSG_ID_EXT == info->idType) ? (info->IdH | CANXL_MSG_DESCRIPTORS_MDFLT2FD_IDE_MASK) : CANXL_MSG_DESCRIPTORS_MDFLT2FD_IDSTDa_H(info->IdH));
        }

        SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_03();
        CANEXCEL.MSGD[instance]->MSGDSC[descNo].CTRL.RXCTRL = RXCTRLTemp | CANXL_MSG_DESCRIPTORS_RXCTRL_MBSIZE(dlcValue);
        SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_03();

        /* Activate the Descriptor */
        CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCACT = 1U;

        /* Release System lock in order to read to receive */
        #if (CANEXCEL_IP_HAS_SYSLOCK01 == STD_ON)
        CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK = 0U;
        #else
        CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK = 1U;
        #endif
    }
    return returnResult;
}



/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_RxFifoPop
 * Description   : Pop received data from the RxFIFO.
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_RxFifoPop_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_RxFifoPop(uint8 instance)
{
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;
    uint8 Active = 0U;
    Canexcel_Ip_RxFifoState rxFifoState = CANEXCEL_FIFO_STATE_INACTIVE;

    Active = (uint8)((CANEXCEL.RXF_CNT[instance]->RXFSYSACT & CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK) >> CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_SHIFT);
    rxFifoState = CanXL_GetRxFifoStatus(CANEXCEL.RXF_CNT[instance], NULL_PTR, NULL_PTR);
    /* Before performing Pop operation, the RxFifo must be activated first*/
    if (1U == Active)
    {
        /* Check if theere is data to pop from RX FIFO */
        if (rxFifoState >= CANEXCEL_FIFO_STATE_NOTFULL)
        {

            CANEXCEL.RXF_CNT[instance]->RXFSYSPOP = 0u;
        }
        else
        {
            returnResult = CANEXCEL_STATUS_NO_DATA_AVAILABLE;
        }
    }
    else
    {
        returnResult = CANEXCEL_STATUS_ERROR;
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
    const Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;
    uint8 Active = 0U;
    boolean bSysLock = FALSE;

#if (CANEXCEL_IP_FEATURE_HAS_MSGDESC_RXCTRL_MODE == (STD_ON))
    /* Check if previous was called the ConfigRx API, the MODE bit was cleared and Descriptor was ACTIVE and release system lock  */
    if (CANXL_MSG_DESCRIPTORS_RXCTRL_MODE_MASK == (CANEXCEL.MSGD[instance]->MSGDSC[descNo].CTRL.RXCTRL & CANXL_MSG_DESCRIPTORS_RXCTRL_MODE_MASK))
    {
        returnResult = CANEXCEL_STATUS_ERROR;
    }
    else
#endif
    {
        Active = (uint8)(CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCACT & CANXL_DSC_CONTROL_DCACT_ACT_MASK);
        bSysLock = (CANEXCEL_DESCNTSTATUS_LOCKED_SYS == CanXL_GetDescControlStatus(CANEXCEL.DESC_CTR[instance], descNo)) ? TRUE : FALSE;

        /* Push without syslock and the descriptor must be activated first, require to call ConfigRx first */
        if ((1U == Active) && (FALSE == bSysLock))
        {
            /* Check if the descriptor is empty, notfull or inactive */
            if (CanXL_GetDesciptorState(CANEXCEL.DESC_CTR[instance], descNo) <= CANEXCEL_DESC_STATE_NOTFULL)
            {
                uint8 noOfPtrList = (uint8)((CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSTA & CANXL_DSC_CONTROL_DCSTA_SYSPOINTER_MASK) >> CANXL_DSC_CONTROL_DCSTA_SYSPOINTER_SHIFT);

                if (noOfPtrList >= (CanXL_GetMDQueueDepth(CANEXCEL.GRP[instance], descNo)+1U))
                {
                    /* Roll Over */
                    noOfPtrList = 0U;
                }
                /* The buffer must be processed in MainFunction/ISR before using it */
                if (FALSE == state->msgDescListPtr[descNo].isPending[noOfPtrList])
                {
                    state->msgDescListPtr[descNo].isPending[noOfPtrList] = TRUE;
                    state->msgDescListPtr[descNo].list[noOfPtrList] = rxPtrList;
                    CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSPUSH = 0U;
                }
                else
                {
                    returnResult = CANEXCEL_STATUS_BUSY;
                }
            }
            else
            {
                returnResult = CANEXCEL_STATUS_BUSY;
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
Canexcel_Ip_StatusType Canexcel_Ip_ReceiveFD(uint8 instance, uint8 descNo, const uint32 * RxMsg)
{
    Canexcel_Ip_StatusType returnResult;
    returnResult = Canexcel_Ip_RxDescriptor(instance, descNo, (uint32)RxMsg);

    return returnResult;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_ReceiveXL
 * Description   : Receive a CAN XL Format Message
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_ReceiveXL_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_ReceiveXL(uint8 instance, uint8 descNo, const uint32 * RxMsg)
{
    Canexcel_Ip_StatusType returnResult;
    returnResult = Canexcel_Ip_RxDescriptor(instance, descNo, (uint32)RxMsg);

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
    const Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;

    /* Ensure that the buffer given was already configured by Canexcel_Ip_ConfigXlTx/Canexcel_Ip_ConfigFdTx before start the transmission */
    if (0U == ((((uint32 *)txPtrList)[TX_WORD2]) & CANXL_TX_HEADER_MODE_MASK))
    {
        returnResult = CANEXCEL_STATUS_ERROR;
    }
    else
    {
        /* Check if the descriptor is empty, notfull or inactive */
        if (CanXL_GetDesciptorState(CANEXCEL.DESC_CTR[instance], descNo) <= CANEXCEL_DESC_STATE_NOTFULL)
        {
            uint8 noOfPtrList = (uint8)((CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSTA & CANXL_DSC_CONTROL_DCSTA_SYSPOINTER_MASK) >> CANXL_DSC_CONTROL_DCSTA_SYSPOINTER_SHIFT);

            if (noOfPtrList >= (CanXL_GetMDQueueDepth(CANEXCEL.GRP[instance], descNo)+1U))
            {
                /* Roll Over */
                noOfPtrList = 0U;
            }
            /* The buffer must be processed in MainFunction/ISR before using it */
            if (FALSE == state->msgDescListPtr[descNo].isPending[noOfPtrList])
            {
                state->msgDescListPtr[descNo].isPending[noOfPtrList] = TRUE;
                state->msgDescListPtr[descNo].list[noOfPtrList] = txPtrList;
                CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCACT = 1U;
                #if (CANEXCEL_IP_HAS_SYSLOCK01 == STD_ON)
                CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK = 0U;
                MCAL_DATA_SYNC_BARRIER();
                MCAL_INSTRUCTION_SYNC_BARRIER();
                #else
                CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK = 1U;
                MCAL_DATA_SYNC_BARRIER();
                MCAL_INSTRUCTION_SYNC_BARRIER();
                #endif
                CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSPUSH = 0U;

            }
            else
            {
                returnResult = CANEXCEL_STATUS_BUSY;
            }
        }
        else
        {
            returnResult = CANEXCEL_STATUS_BUSY;
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
void Canexcel_Ip_ConfigXlTx(uint32 id,const Canexcel_Ip_TxDataInfoType * info, uint32 * TxMsg)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(NULL_PTR != info));
    DevAssert((boolean volatile)(NULL_PTR != info->XlParamsPtr));
    DevAssert((boolean volatile)(NULL_PTR != TxMsg));
    #ifdef ERR_IPV_CANEXCEL_E052084
    /* System must program retransmission counter greater than 0. */
    DevAssert((boolean volatile)(info->retransmission > 0U));
    #endif
    DevAssert((boolean volatile)(CANEXCEL_XL_FRAME == info->frame));
#endif
    /* Initialize a fixed value for timestamp in order to check if the frame is transmitted successfully or not after CANEXCEL completed transfer(HwPointer is updated):
     * - timeStampL and timeStampH are remained -> frame was aborted (due to retransmission counter exhaust)
     * - timeStampL and timeStampH are overwritten to a different value -> Frame Transmitted Successfully
     */
    TxMsg[TX_TIMESTAMPL] = CANXL_IP_TX_TIMESTAMPL_INIT_VALUE;
    TxMsg[TX_TIMESTAMPH] = CANXL_IP_TX_TIMESTAMPH_INIT_VALUE;
    TxMsg[TX_WORD3] = 0U;
    TxMsg[TX_WORD2] = 0U;
    TxMsg[TX_WORD4] = 0U;
    TxMsg[TX_WORD2] = CANXL_TX_HEADER_MODE_MASK | (((uint32)info->priority << CANXL_TX_HEADER_PRIO_SHIFT) & CANXL_TX_HEADER_PRIO_MASK)
                       | (((uint32)info->retransmission << CANXL_TX_HEADER_RETR_SHIFT) & CANXL_TX_HEADER_RETR_MASK);
    if (CANEXCEL_MSG_ID_EXT == info->idType)
    {
        TxMsg[TX_WORD3] = CANXL_TX_HEADER_IDE_MASK | (id & CANXL_IP_ID_EXT_MASK) | CANXL_TX_HEADER_XLF_MASK;
    }
    else
    {
        TxMsg[TX_WORD3] = ((id << CANXL_IP_ID_STD_SHIFT) & CANXL_IP_ID_STD_MASK) | CANXL_TX_HEADER_XLF_MASK;
    }
    TxMsg[TX_WORD4] = (CANXL_TX_HEADER_FDF_MASK | ((((uint32)info->dataLength - 1u) << CANXL_TX_HEADER_DLC_SHIFT) & CANXL_TX_HEADER_DLC_MASK)) | (((uint32)info->XlParamsPtr->SDT << CANXL_TX_HEADER_SDT_SHIFT)&CANXL_TX_HEADER_SDT_MASK);
    TxMsg[TX_WORD4] |= info->XlParamsPtr->VCID | (((uint32)((TRUE == info->XlParamsPtr->SEC) ? 1U : 0U) << CANXL_TX_HEADER_SEC_SHIFT) & CANXL_TX_HEADER_SEC_MASK);
    TxMsg[TX_XL_AF] = info->XlParamsPtr->AF;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_ConfigFdTx
 * Description   : Config the MessageBuffer for Tx with CAN FD Format and the desired parameters from DataInfoType
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_ConfigFdTx_Activity */
void Canexcel_Ip_ConfigFdTx(uint32 id, const Canexcel_Ip_TxDataInfoType * info, uint32 * TxMsg)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(NULL_PTR != info));
    DevAssert((boolean volatile)(NULL_PTR != TxMsg));
    #ifdef ERR_IPV_CANEXCEL_E052084
    /* System must program retransmission counter greater than 0. */
    DevAssert((boolean volatile)(info->retransmission > 0U));
    #endif
    DevAssert((boolean volatile)((CANEXCEL_FD_FRAME == info->frame) || (CANEXCEL_CLASIC_FRAME == info->frame)));
#endif
    uint16 dlcValue = 0U;
    /* Initialize a fixed value for timestamp in order to check if the frame is transmitted successfully or not after CANEXCEL completed transfer(HwPointer is updated):
     * - timeStampL and timeStampH are remained -> frame was aborted (due to retransmission counter exhaust)
     * - timeStampL and timeStampH are overwritten to a different value -> Frame Transmitted Successfully
     */
    TxMsg[TX_TIMESTAMPL] = CANXL_IP_TX_TIMESTAMPL_INIT_VALUE;
    TxMsg[TX_TIMESTAMPH] = CANXL_IP_TX_TIMESTAMPH_INIT_VALUE;
    TxMsg[TX_WORD3] = 0U;
    TxMsg[TX_WORD2] = 0U;
    TxMsg[TX_WORD4] = 0U;
    TxMsg[TX_WORD2] = CANXL_TX_HEADER_MODE_MASK | (((uint32)info->priority << CANXL_TX_HEADER_PRIO_SHIFT) & CANXL_TX_HEADER_PRIO_MASK)
                       | (((uint32)info->retransmission << CANXL_TX_HEADER_RETR_SHIFT) & CANXL_TX_HEADER_RETR_MASK);
    if (CANEXCEL_MSG_ID_EXT == info->idType)
    {
        TxMsg[TX_WORD3] = CANXL_TX_HEADER_IDE_MASK | (id & CANXL_IP_ID_EXT_MASK);
    }
    else
    {
        TxMsg[TX_WORD3] = ((id << CANXL_IP_ID_STD_SHIFT) & CANXL_IP_ID_STD_MASK);
    }

    dlcValue = (uint16)CAN_ComputeDLCValue((info->dataLength < MAX_CAN_FD_FRAME_SIZE)?(uint8)(info->dataLength):MAX_CAN_FD_FRAME_SIZE);
    if (CANEXCEL_FD_FRAME == info->frame)
    {
        if (TRUE == info->enable_brs)
        {
            TxMsg[TX_WORD4] = CANXL_TX_HEADER_BRS_MASK | CANXL_TX_HEADER_FDF_MASK | (((uint32)dlcValue << CANXL_TX_HEADER_DLC_SHIFT) & CANXL_TX_HEADER_DLC_MASK);
        }
        else
        {
            TxMsg[TX_WORD4] = CANXL_TX_HEADER_FDF_MASK | (((uint32)dlcValue << CANXL_TX_HEADER_DLC_SHIFT) & CANXL_TX_HEADER_DLC_MASK);
        }
    }
    else
    {
        TxMsg[TX_WORD4] = (((uint32)dlcValue << CANXL_TX_HEADER_DLC_SHIFT) & CANXL_TX_HEADER_DLC_MASK);
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_SendFDMsg
 * Description   : Send a CAN Classic or FD Format Message
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_SendFDMsg_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_SendFDMsg(uint8 instance, uint8 mbIdx,const Canexcel_Ip_TxDataInfoType * info, uint32 id,const uint8 * dataPtr, uint32 * TxMsg)
{
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_ERROR;

    if (!CanXL_IsListenOnlyModeEnabled(CANEXCEL.SIC[instance]))
    {
        if (FALSE == CanXL_IsPwmModeEnable(CANEXCEL.SIC[instance]))
        {
            if (NULL_PTR != info)
            {
                Canexcel_Ip_ConfigFdTx(id, info, TxMsg);
                if (NULL_PTR != dataPtr)
                {
                    CanXL_SetTxMsgBuffData(info, dataPtr, &TxMsg[TX_FD_DATA]);
                }
            }

            returnResult = Canexcel_Ip_TxDescriptor(instance, mbIdx, (uint32)TxMsg);
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
Canexcel_Ip_StatusType Canexcel_Ip_SendXLMsg(uint8 instance, uint8 mbIdx,const Canexcel_Ip_TxDataInfoType * info, uint32 id,const uint8 * dataPtr, uint32 * TxMsg)
{
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_ERROR;
    if (!CanXL_IsListenOnlyModeEnabled(CANEXCEL.SIC[instance]))
    {
        if (NULL_PTR != info)
        {
            Canexcel_Ip_ConfigXlTx(id, info, TxMsg);
            if (NULL_PTR != dataPtr)
            {
                CanXL_SetTxMsgBuffData(info, dataPtr, &TxMsg[TX_XL_DATA]);
            }
        }
        returnResult = Canexcel_Ip_TxDescriptor(instance, mbIdx, (uint32)TxMsg);
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
    DevAssert((boolean volatile)(descIdx < CANXL_DSC_CONTROL_DSCMBCTRLAR_COUNT));
    DevAssert((boolean volatile)(instance < CANXL_SIC_INSTANCE_COUNT));
#endif
    /* Check if the descriptor is active */
    if (CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descIdx].DCACT == CANXL_DSC_CONTROL_DCACT_ACT_MASK)
    {
        if (0U == CanXL_GetMDQueueDepth(CANEXCEL.GRP[instance], descIdx))
        {
            /* In case of MD Queue depth = 0 */
            if (CANEXCEL_DESC_STATE_EMPTY == CanXL_GetDesciptorState(CANEXCEL.DESC_CTR[instance], descIdx))
            {
                returnResult = CANEXCEL_STATUS_SUCCESS;
            }
            if (CANEXCEL_DESC_STATE_FULL == CanXL_GetDesciptorState(CANEXCEL.DESC_CTR[instance], descIdx))
            {
                returnResult = CANEXCEL_STATUS_BUSY;
            }
        }
        else
        {
            if (CanXL_GetDesciptorHWIndex(CANEXCEL.DESC_CTR[instance], descIdx) == CanXL_GetDesciptorSysIndex(CANEXCEL.DESC_CTR[instance], descIdx))
            {
                returnResult = CANEXCEL_STATUS_SUCCESS;
            }
            else
            {
                returnResult = CANEXCEL_STATUS_BUSY;
            }
        }
        if (CANEXCEL_DESC_STATE_OVERRUN == CanXL_GetDesciptorState(CANEXCEL.DESC_CTR[instance], descIdx))
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
    return CanXL_EnterFreezeMode(CANEXCEL.SIC[instance]);
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
    return CanXL_ExitFreezeMode(CANEXCEL.SIC[instance]);
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

    if (TRUE == CanXL_IsFreezeMode(CANEXCEL.SIC[u8Instance]))
    {
        CanXL_EnableInterrupts(CANEXCEL.SIC[u8Instance]);
        if ((CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK == (CANEXCEL.RXF_CNT[u8Instance]->RXFSYSACT & CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK)) && (FALSE == Canexcel_Ip_apxState[u8Instance]->rxFifo.isPolling))
        {
            /* Activate RxFifo Interrupts */
            CANEXCEL.RXF_CNT[u8Instance]->RXFIEN = CANXL_RXFIFO_CONTROL_RXFIEN_RXFIE_MASK | CANXL_RXFIFO_CONTROL_RXFIEN_RXFEIE_MASK;
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

    if (TRUE == CanXL_IsFreezeMode(CANEXCEL.SIC[u8Instance]))
    {
        CanXL_DisableInterrupts(CANEXCEL.SIC[u8Instance]);
        if (((CANEXCEL.RXF_CNT[u8Instance]->RXFSYSACT & CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK) == CANXL_RXFIFO_CONTROL_RXFSYSACT_ACT_MASK) && (FALSE == Canexcel_Ip_apxState[u8Instance]->rxFifo.isPolling))
        {
            /* Clear RxFifo Interrupts */
            CANEXCEL.RXF_CNT[u8Instance]->RXFIEN = ~(CANXL_RXFIFO_CONTROL_RXFIEN_RXFIE_MASK | CANXL_RXFIFO_CONTROL_RXFIEN_RXFEIE_MASK);
        }
        state->isIntActive = FALSE;
        returnResult = CANEXCEL_STATUS_SUCCESS;
    }
    return returnResult;
}



/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_GetNumOfBuffAvailable
 * Description   : Get number of buffers completed tranfser
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_GetNumOfBuffAvailable_Activity */
uint8 Canexcel_Ip_GetNumOfBuffAvailable(uint8 u8Instance, uint8 u8DescNo)
{
    const Canexcel_Ip_MDhandleType * pDcState = &Canexcel_Ip_apxState[u8Instance]->msgDescListPtr[u8DescNo];
    uint8 u8NumPtr = 0U;
    uint8 u8QueueDepth = CanXL_GetMDQueueDepth(CANEXCEL.GRP[u8Instance], (uint8)u8DescNo) + 1U;
    uint8 u8CurrentHwIdx = 0U;
    Canexcel_Ip_DescState DcStatus = CanXL_GetDesciptorStatus(CANEXCEL.DESC_CTR[u8Instance], u8DescNo, NULL_PTR, &u8CurrentHwIdx);
    /* This function will not modify pDcState->currBufferIdx as it only read queue information */
    uint8 currBufferIdxTemp = pDcState->currBufferIdx;

    if (u8CurrentHwIdx > currBufferIdxTemp)
    {
        u8NumPtr = (uint8)(u8CurrentHwIdx - currBufferIdxTemp);
    }
    else if ((u8CurrentHwIdx < currBufferIdxTemp))
    {
        /* u8QueueDepth is maximum 16 and it is always greater than or equal to currBufferIdxTemp, u8CurrentHwIdx */
        u8NumPtr = (uint8)(u8QueueDepth - currBufferIdxTemp + u8CurrentHwIdx);
    }
    else /* (u8CurrentHwIdx is equal to currBufferIdxTemp) */
    {
        /* check if the queue is roll over */
        if (currBufferIdxTemp >= u8QueueDepth)
        {
            currBufferIdxTemp = 0U;
        }

        /* If the queue is empty(completed all transfers) and at least one buffers pending, it means that it's roll over */
        if ((TRUE == pDcState->isPending[currBufferIdxTemp]) && (CANEXCEL_DESC_STATE_EMPTY == DcStatus))
        {
            u8NumPtr = u8QueueDepth;
        }
    }

    return u8NumPtr;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_GetTxBuffStatus
 * Description   : Pop a tx buffer completed transfer and get status if required
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_GetTxBuffStatus_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_GetTxBuffStatus(uint8 u8Instance, uint8 u8DescNo, uint32 * pTxPtrList, Canexcel_Ip_TxBuffStatusType * pTxBuffStatus)
{
    Canexcel_Ip_StatusType RetVal = CANEXCEL_STATUS_NO_DATA_AVAILABLE;
    Canexcel_Ip_MDhandleType * pDcState = &Canexcel_Ip_apxState[u8Instance]->msgDescListPtr[u8DescNo];
    uint8 u8NumPtr = 0U;

    u8NumPtr = Canexcel_Ip_GetNumOfBuffAvailable(u8Instance, u8DescNo);
    if (u8NumPtr > 0U)
    {
        if (pDcState->currBufferIdx > CanXL_GetMDQueueDepth(CANEXCEL.GRP[u8Instance], (uint8)u8DescNo))
        {
            pDcState->currBufferIdx = 0U;
        }
        /* Release the buffer's lock so it can be used later */
        pDcState->isPending[pDcState->currBufferIdx] = FALSE;

        if (NULL_PTR != pTxPtrList)
        {
            *pTxPtrList = pDcState->list[pDcState->currBufferIdx];
        }

        if (NULL_PTR != pTxBuffStatus)
        {
            const uint32 * Header =  (uint32 *)pDcState->list[pDcState->currBufferIdx];
            /* check if transmission success by reading timestamp */
            if ((CANXL_IP_TX_TIMESTAMPH_INIT_VALUE == Header[TX_TIMESTAMPH]) && (CANXL_IP_TX_TIMESTAMPL_INIT_VALUE == Header[TX_TIMESTAMPL]))
            {
                pTxBuffStatus->NoError = FALSE;
            }
            else
            {
                pTxBuffStatus->NoError = TRUE;
                pTxBuffStatus->timeStampL = Header[TX_TIMESTAMPL];
                pTxBuffStatus->timeStampH = Header[TX_TIMESTAMPH];
            }
        }

        pDcState->currBufferIdx++;

        if (u8NumPtr == 1U)
        {
            RetVal = CANEXCEL_STATUS_SUCCESS;
        }
        else
        {
            RetVal = CANEXCEL_STATUS_MORE_DATA_AVAILABLE;
        }
    }
    else
    {
        RetVal = CANEXCEL_STATUS_NO_DATA_AVAILABLE;
    }

    return RetVal;
}



/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_GetRxFifoStatus
 * Description   : Pop a rx FIFO buffer with completed transfer and get status if required
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_GetRxFifoStatus_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_GetRxFifoStatus(uint8 u8Instance, uint32 * pRxPtrList, Canexcel_Ip_RxDataInfoType * pRxBuffInfor, boolean checkForSpecificFrameType)
{
    Canexcel_Ip_StatusType RetVal = CANEXCEL_STATUS_NO_DATA_AVAILABLE;
    Canexcel_Ip_RXFIFOhandleType * pRxFifoState = &Canexcel_Ip_apxState[u8Instance]->rxFifo;
    uint8 u8NumPtr = 0U;
    uint16 TimestampWordOff = 0U;
    Canexcel_Ip_FrameType frameTypeToCheckFor = CANEXCEL_CLASIC_FRAME;

    u8NumPtr = Canexcel_Ip_GetNumOfRxFifoBuffAvailable(u8Instance);
    if ((u8NumPtr > 0U) && (NULL_PTR != pRxBuffInfor) && (NULL_PTR != pRxPtrList))
    {
        frameTypeToCheckFor = pRxBuffInfor->frame;

        if (pRxFifoState->currBufferIdx > ((CANEXCEL.RXF_CNT[u8Instance]->RXFC & CANXL_RXFIFO_CONTROL_RXFC_RXFD_MASK) >> CANXL_RXFIFO_CONTROL_RXFC_RXFD_SHIFT))
        {
            pRxFifoState->currBufferIdx = 0U;
        }

        *pRxPtrList = CANEXCEL.RXFIFO[u8Instance]->RXFMBP[pRxFifoState->currBufferIdx];

        /* Extract information from Rx Buffer */
        const uint32 *Header = (uint32 *)CANEXCEL.RXFIFO[u8Instance]->RXFMBP[pRxFifoState->currBufferIdx];

        /* CPR_RTD_00284:The driver shall check if the length parameter of any received data packet is bigger than the maximum accepted value defined by the protocol specification/configuration.
         * If the length exceeds the maximum then the processing flow shall continue with the maximum length value defined by protocol specification/configuration.
         */
        uint16 dlcValue = (uint16)((Header[RX_CONTROL] & CANXL_TX_HEADER_DLC_MASK) >> CANXL_TX_HEADER_DLC_SHIFT);
        uint16 dlcValueConfig = (uint16)((CANEXCEL.RXFIFO[u8Instance]->RXFFCTR & CANXL_RXFIFO_RXFFCTR_MBSIZE_MASK) >> CANXL_RXFIFO_RXFFCTR_MBSIZE_SHIFT);
        if (dlcValue > dlcValueConfig)
        {
            dlcValue = dlcValueConfig;
        }

        /* Check XLF bit, 1 is a XL frame else is CAN or CANFD frame */
        if ((Header[RX_CONTROL] & CANXL_RX_HEADER_XLF_MASK) != 0U)
        {
            /* XL Frame */
            pRxBuffInfor->frame = CANEXCEL_XL_FRAME;


            pRxBuffInfor->dataLength = (uint16)((dlcValue + 1U) & 0xFFFFu);

            if (NULL_PTR != pRxBuffInfor->XlParamsPtr)
            {
                pRxBuffInfor->XlParamsPtr->SDT = (uint8)((Header[RX_CONTROL] & CANXL_RX_HEADER_SDT_MASK) >> CANXL_RX_HEADER_SDT_SHIFT);

                pRxBuffInfor->XlParamsPtr->SEC = ((Header[RX_CONTROL] & CANXL_RX_HEADER_SEC_MASK) != 0U) ? TRUE : FALSE;

                pRxBuffInfor->XlParamsPtr->VCID = (uint8)((Header[RX_CONTROL] & CANXL_RX_HEADER_VCID_MASK) >> CANXL_RX_HEADER_VCID_SHIFT);

                pRxBuffInfor->XlParamsPtr->AF = ((uint32 *)CANEXCEL.RXFIFO[u8Instance]->RXFMBP[pRxFifoState->currBufferIdx])[RX_XL_AF];
            }
        }
        else
        {
            /* Check FDF bit, 1 is a FD frame else is CAN classic frame */
            if ((Header[RX_CONTROL] & CANXL_RX_HEADER_FDF_MASK) != 0U)
            {
                /* FD Frame */
                pRxBuffInfor->frame = CANEXCEL_FD_FRAME;
            }
            else
            {
                /* CAN Classic Frame */
                pRxBuffInfor->frame = CANEXCEL_CLASIC_FRAME;
            }
            pRxBuffInfor->dataLength = CAN_ComputePayloadSizeHw((uint8)dlcValue);
        }

        /* Check IDE bit, 0 is standard frame, 1 is extended frame */
        if ((Header[RX_ID] & CANXL_RX_HEADER_IDE_MASK) != 0U)
        {
            pRxBuffInfor->idType = CANEXCEL_MSG_ID_EXT;
            pRxBuffInfor->MessageId = (Header[RX_ID]) & CANXL_IP_ID_EXT_MASK;
        }
        else
        {
            pRxBuffInfor->idType = CANEXCEL_MSG_ID_STD;
            pRxBuffInfor->MessageId = (Header[RX_ID] & CANXL_IP_ID_STD_MASK) >> CANXL_IP_ID_STD_SHIFT;
        }

        pRxBuffInfor->enable_brs = ((Header[RX_CONTROL] & CANXL_RX_HEADER_BRS_MASK) != 0U) ? TRUE : FALSE;

        TimestampWordOff = pRxBuffInfor->dataLength / 4u;
        if ((pRxBuffInfor->dataLength % 4U) != 0U)
        {
            /* The timestamp offset is alway next word after payload.
             * For example, if data length is 9 then 3 first words allocated for payload => timestamp offset = 4th words */
            TimestampWordOff++;
        }
        TimestampWordOff = (uint16)(((uint32)TimestampWordOff + (uint16)RX_HEADER_END) & 0xFFFFu);
        if (CANEXCEL_XL_FRAME == pRxBuffInfor->frame)
        {
            TimestampWordOff++; /* plush one word AF for XL format */
        }
        /* TimestampWordOff is calculated dynamically on data length which is checked against with maximum payload length(MBSIZE) plus static parts(header + AF)
         * => out of memory is not happened.
         */
        pRxBuffInfor->timeStampL = ((uint32 *)CANEXCEL.RXFIFO[u8Instance]->RXFMBP[pRxFifoState->currBufferIdx])[TimestampWordOff];
        pRxBuffInfor->timeStampH = ((uint32 *)CANEXCEL.RXFIFO[u8Instance]->RXFMBP[pRxFifoState->currBufferIdx])[(uint16)(((uint32)TimestampWordOff + 1U) & 0xFFFFu)];

        if (
            (
                ((frameTypeToCheckFor != CANEXCEL_XL_FRAME) && (pRxBuffInfor->frame == CANEXCEL_XL_FRAME))||
                ((frameTypeToCheckFor == CANEXCEL_XL_FRAME) && (pRxBuffInfor->frame != CANEXCEL_XL_FRAME))
            ) &&
            checkForSpecificFrameType
           )
        {
            RetVal = CANEXCEL_STATUS_NO_DATA_AVAILABLE;
        }
        else
        {
            pRxFifoState->currBufferIdx++;

            if (u8NumPtr == 1U)
            {
                RetVal = CANEXCEL_STATUS_SUCCESS;
            }
            else
            {
                RetVal = CANEXCEL_STATUS_MORE_DATA_AVAILABLE;
            }
        }
    }
    else
    {
        RetVal = CANEXCEL_STATUS_NO_DATA_AVAILABLE;
    }

    return RetVal;
}



/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_GetRxBuffStatus
 * Description   : Pop a rx buffer completed transfer and get status if required
 *
 *END**************************************************************************/
 /* implements Canexcel_Ip_GetRxBuffStatus_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_GetRxBuffStatus(uint8 u8Instance, uint8 u8DescNo, uint32 * pRxPtrList, Canexcel_Ip_RxDataInfoType * pRxBuffInfor, uint8 ** pData)
{
    Canexcel_Ip_StatusType RetVal = CANEXCEL_STATUS_NO_DATA_AVAILABLE;
    Canexcel_Ip_MDhandleType * pDcState = &Canexcel_Ip_apxState[u8Instance]->msgDescListPtr[u8DescNo];
    uint8 u8NumPtr = 0U;
    uint16 TimestampWordOff = 0U;

    u8NumPtr = Canexcel_Ip_GetNumOfBuffAvailable(u8Instance, u8DescNo);
    if (u8NumPtr > 0U)
    {
        if (pDcState->currBufferIdx > CanXL_GetMDQueueDepth(CANEXCEL.GRP[u8Instance], (uint8)u8DescNo))
        {
            pDcState->currBufferIdx = 0U;
        }
        /* Release the buffer's lock so it can be used later */
        pDcState->isPending[pDcState->currBufferIdx] = FALSE;

        if (NULL_PTR != pRxPtrList)
        {
            *pRxPtrList = pDcState->list[pDcState->currBufferIdx];
        }

        /* Extract information from Rx Buffer */
        if (NULL_PTR != pRxBuffInfor)
        {
            const uint32 * Header =  (uint32 *)pDcState->list[pDcState->currBufferIdx];

            /* CPR_RTD_00284:The driver shall check if the length parameter of any received data packet is bigger than the maximum accepted value defined by the protocol specification/configuration.
             * If the length exceeds the maximum then the processing flow shall continue with the maximum length value defined by protocol specification/configuration.
            */
            uint16 dlcValue = (uint16)((Header[RX_CONTROL] & CANXL_TX_HEADER_DLC_MASK) >> CANXL_TX_HEADER_DLC_SHIFT);
            uint16 dlcValueConfig = (uint16)((CANEXCEL.MSGD[u8Instance]->MSGDSC[u8DescNo].CTRL.RXCTRL & CANXL_MSG_DESCRIPTORS_RXCTRL_MBSIZE_MASK)  >> CANXL_MSG_DESCRIPTORS_RXCTRL_MBSIZE_SHIFT);
            if(dlcValue > dlcValueConfig)
            {
                dlcValue = dlcValueConfig;
            }

            /* Check XLF bit, 1 is a XL frame else is CAN or CANFD frame */
            if ((Header[RX_CONTROL] & CANXL_RX_HEADER_XLF_MASK) != 0U)
            {
                /* XL Frame */
                pRxBuffInfor->frame = CANEXCEL_XL_FRAME;

                if (NULL_PTR != pData)
                {
                    *pData = (uint8 *)&(((uint32 *)pDcState->list[pDcState->currBufferIdx])[RX_XL_DATA]);
                }

                pRxBuffInfor->dataLength = (uint16)(dlcValue + 1U);

                if (NULL_PTR != pRxBuffInfor->XlParamsPtr)
                {
                    pRxBuffInfor->XlParamsPtr->SDT = (uint8)((Header[RX_CONTROL] & CANXL_RX_HEADER_SDT_MASK) >> CANXL_RX_HEADER_SDT_SHIFT);

                    pRxBuffInfor->XlParamsPtr->SEC = ((Header[RX_CONTROL] & CANXL_RX_HEADER_SEC_MASK) != 0U) ? TRUE : FALSE;

                    pRxBuffInfor->XlParamsPtr->VCID = (uint8)((Header[RX_CONTROL] & CANXL_RX_HEADER_VCID_MASK) >> CANXL_RX_HEADER_VCID_SHIFT);

                    pRxBuffInfor->XlParamsPtr->AF = ((uint32 *)pDcState->list[pDcState->currBufferIdx])[RX_XL_AF];
                }
            }
            else
            {
                /* Check FDF bit, 1 is a FD frame else is CAN classic frame */
                if ((Header[RX_CONTROL] & CANXL_RX_HEADER_FDF_MASK) != 0U)
                {
                    /* FD Frame */
                    pRxBuffInfor->frame = CANEXCEL_FD_FRAME;
                }
                else
                {
                    /* CAN Classic Frame */
                    pRxBuffInfor->frame = CANEXCEL_CLASIC_FRAME;
                }
                if (NULL_PTR != pData)
                {
                    *pData = (uint8 *)&(((uint32 *)pDcState->list[pDcState->currBufferIdx])[RX_FD_DATA]);
                }
                pRxBuffInfor->dataLength = CAN_ComputePayloadSizeHw((uint8)dlcValue);
            }

            /* Check IDE bit, 0 is standard frame, 1 is extended frame */
            if ((Header[RX_ID] & CANXL_RX_HEADER_IDE_MASK) != 0U)
            {
                pRxBuffInfor->idType = CANEXCEL_MSG_ID_EXT;
                pRxBuffInfor->MessageId = (Header[RX_ID]) & CANXL_IP_ID_EXT_MASK;
            }
            else
            {
                pRxBuffInfor->idType = CANEXCEL_MSG_ID_STD;
                pRxBuffInfor->MessageId = (Header[RX_ID] & CANXL_IP_ID_STD_MASK) >> CANXL_IP_ID_STD_SHIFT;
            }

            pRxBuffInfor->enable_brs = ((Header[RX_CONTROL] & CANXL_RX_HEADER_BRS_MASK) != 0U) ? TRUE : FALSE;

            TimestampWordOff = pRxBuffInfor->dataLength / 4U;
            if ((pRxBuffInfor->dataLength % 4U) != 0U)
            {
                /* The timestamp offset is alway next word after payload.
                * For example, if data length is 9 then 3 first words allocated for payload => timestamp offset = 4th words */
                TimestampWordOff++;
            }
            TimestampWordOff += (uint16)RX_HEADER_END;
            if (CANEXCEL_XL_FRAME == pRxBuffInfor->frame)
            {
                TimestampWordOff++; /* plush one word AF for XL format */
            }
            /* TimestampWordOff is calculated dynamically on data length which is checked against with maximum payload length(MBSIZE) plus static parts(header + AF)
             * => out of memory is not happened.
            */
            pRxBuffInfor->timeStampL = ((uint32 *)pDcState->list[pDcState->currBufferIdx])[TimestampWordOff];
            pRxBuffInfor->timeStampH = ((uint32 *)pDcState->list[pDcState->currBufferIdx])[TimestampWordOff + 1U];
        }

        pDcState->currBufferIdx++;

        if (u8NumPtr == 1U)
        {
            RetVal = CANEXCEL_STATUS_SUCCESS;
        }
        else
        {
            RetVal = CANEXCEL_STATUS_MORE_DATA_AVAILABLE;
        }
    }
    else
    {
        RetVal = CANEXCEL_STATUS_NO_DATA_AVAILABLE;
    }

    return RetVal;
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
    const Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    uint32 flag_reg;
    uint8 mb_idx = 0U;
    uint8 total_mb = (uint8)((((CANEXCEL.SIC[instance]->SYSMCFG & CANXL_SIC_SYSMCFG_MAXTXMB_MASK) >> CANXL_SIC_SYSMCFG_MAXTXMB_SHIFT) + ((CANEXCEL.SIC[instance]->SYSMCFG & CANXL_SIC_SYSMCFG_MAXRXMB_MASK) >> CANXL_SIC_SYSMCFG_MAXRXMB_SHIFT)));

    /* Check if instance initialized */
    if (NULL_PTR != state)
    {
        flag_reg = CanXL_GetMsgBuffIntStatusFlag(CANEXCEL.GRP[instance], mb_idx);
        while ((0U == flag_reg) && (mb_idx < total_mb))
        {
            mb_idx++;
            flag_reg = CanXL_GetMsgBuffIntStatusFlag(CANEXCEL.GRP[instance], mb_idx);
        }

        if (0U != flag_reg)
        {
            CanXL_ClearMsgDescIntStatusFlag(CANEXCEL.GRP[instance], mb_idx);

            /* First descriptors are always allocated for Transmission */
            if (mb_idx <= CANEXCEL.GRP[instance]->DSCCTRL)
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
        if (CANEXCEL.RXF_CNT[instance]->RXFSYSACT == 1U)
        {
            if (((CANEXCEL.RXF_CNT[instance]->RXFIEN & CANXL_RXFIFO_CONTROL_RXFIEN_RXFIE_MASK) != 0U) &&  ((CANEXCEL.RXF_CNT[instance]->RXFS & CANXL_RXFIFO_CONTROL_RXFS_RXFF_MASK) != 0U))
            {
                /* Clear the fifo flag */
              CANEXCEL.RXF_CNT[instance]->RXFS = CANXL_RXFIFO_CONTROL_RXFS_RXFF_MASK;
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
        /*clear  interrupt flags only if interrupts are enabled*/
        for (mb_idx=0U; mb_idx<CANXL_DSC_CONTROL_DSCMBCTRLAR_COUNT; mb_idx++)
        {
            flag_reg = CanXL_GetMsgBuffIntStatusFlag(CANEXCEL.GRP[instance], mb_idx);
            if(flag_reg != 0u)
            {
                CanXL_ClearMsgDescIntStatusFlag(CANEXCEL.GRP[instance], mb_idx);
            }
        }
        if((CANEXCEL.RXF_CNT[instance]->RXFIEN & CANXL_RXFIFO_CONTROL_RXFIEN_RXFIE_MASK) != 0U)
        {
            /* Clear the fifo flag */
            CANEXCEL.RXF_CNT[instance]->RXFS = CANXL_RXFIFO_CONTROL_RXFS_RXFF_MASK;
        }
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
    if (CANXL_SIC_SYSIE_CERRIE_MASK == ((CANEXCEL.SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CERRIE_MASK) & sysStatus))
    {
        CANEXCEL.SIC[instance]->SYSS = CANXL_SIC_SYSS_CERR_MASK;
        /* Check if callback is registered */
        if (NULL_PTR != state->error_callback)
        {
            state->error_callback(instance, CANEXCEL_EVENT_ERROR, bcanXlStatus, state);
        }
    }
    if (CANXL_SIC_SYSIE_CFDPERRIE_MASK == ((CANEXCEL.SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CFDPERRIE_MASK) & sysStatus))
    {
        CANEXCEL.SIC[instance]->SYSS = CANXL_SIC_SYSS_CFDPERR_MASK;
        if (NULL_PTR != state->error_callback)
        {
            state->error_callback(instance, CANEXCEL_EVENT_ERROR_FD, bcanXlStatus, state);
        }
    }
    if (CANXL_SIC_SYSIE_CRXWRNIE_MASK == ((CANEXCEL.SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CRXWRNIE_MASK) & sysStatus))
    {
        CANEXCEL.SIC[instance]->SYSS = CANXL_SIC_SYSS_CRXWRN_MASK;
        if (NULL_PTR != state->error_callback)
        {
            state->error_callback(instance, CANEXCEL_EVENT_RX_WARNING, bcanXlStatus, state);
        }
    }
    if (CANXL_SIC_SYSIE_CTXWRNIE_MASK == ((CANEXCEL.SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CTXWRNIE_MASK) & sysStatus))
    {
        CANEXCEL.SIC[instance]->SYSS = CANXL_SIC_SYSS_CTXWRN_MASK;
        if (NULL_PTR != state->error_callback)
        {
            state->error_callback(instance, CANEXCEL_EVENT_TX_WARNING, bcanXlStatus, state);
        }
    }
    if (CANXL_SIC_SYSIE_CDPERRIE_MASK == ((CANEXCEL.SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CDPERRIE_MASK) & sysStatus))
    {
        CANEXCEL.SIC[instance]->SYSS = CANXL_SIC_SYSS_CXDPERR_MASK;
        if (NULL_PTR != state->error_callback)
        {
            state->error_callback(instance, CANEXCEL_EVENT_ERROR_XL, bcanXlStatus, state);
        }
    }
    if (CANXL_SIC_SYSIE_CPERRIE_MASK == ((CANEXCEL.SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CPERRIE_MASK) & sysStatus))
    {
        CANEXCEL.SIC[instance]->SYSS = CANXL_SIC_SYSS_CPASERR_MASK;
        if (NULL_PTR != state->error_callback)
        {
            state->error_callback(instance, CANEXCEL_EVENT_PASSIVE, bcanXlStatus, state);
        }
    }
    if (CANXL_SIC_SYSIE_CBOFFIE_MASK == ((CANEXCEL.SIC[instance]->SYSIE & CANXL_SIC_SYSIE_CBOFFIE_MASK) & sysStatus))
    {
        CANEXCEL.SIC[instance]->SYSS = CANXL_SIC_SYSS_CBOFF_MASK;
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
    uint32 sysStatus = CANEXCEL.SIC[instance]->SYSS;
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
        /* Clear all errors with interrupts enabled*/
        if (0u != (CANEXCEL.SIC[instance]->SYSIE & sysStatus))
        {
            CANEXCEL.SIC[instance]->SYSS = (CANEXCEL.SIC[instance]->SYSIE & sysStatus);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_MruSpuriousIRQHandler
 * Description   : Spurious IrqHandler for MRU service unit
 *
 *END**************************************************************************/
void Canexcel_Ip_MruSpuriousIRQHandler(uint8 instance)
{
    /*disable MRU interrupt, if interrupt enabled because of some HW glitch. The MRU event is handled in polling mode*/
    if (0u != (CANEXCEL.SIC[instance]->SYSIE & CANXL_SIC_SYSIE_MRUIE_MASK))
    {
        CanXL_SetErrIntCmd(CANEXCEL.SIC[instance], CANXL_INT_MRU, FALSE);
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_SetErrorInt
 * Description   : Enable\Disable Error or BusOff Interrupt
 *
 *END**************************************************************************/
/* implements Canexcel_Ip_SetErrorInt_Activity */
void Canexcel_Ip_SetErrorInt(uint8 u8Instance, Canexcel_Ip_ErrorIntType type, boolean enable)
{
    switch (type)
    {
        case CANEXCEL_IP_INT_RX_WARNING:
        {
            CanXL_SetErrIntCmd(CANEXCEL.SIC[u8Instance], CANXL_INT_RX_WARNING, enable);
            break;
        }
        case CANEXCEL_IP_INT_TX_WARNING:
        {
            CanXL_SetErrIntCmd(CANEXCEL.SIC[u8Instance], CANXL_INT_TX_WARNING, enable);
            break;
        }
        case CANEXCEL_IP_INT_ERR:
        {
            CanXL_SetErrIntCmd(CANEXCEL.SIC[u8Instance], CANXL_INT_ERR, enable);
            break;
        }
        case CANEXCEL_IP_INT_ERR_FAST:
        {
            CanXL_SetErrIntCmd(CANEXCEL.SIC[u8Instance], CANXL_INT_ERR_FAST, enable);
            break;
        }
        case CANEXCEL_IP_INT_ERR_XL:
        {
            CanXL_SetErrIntCmd(CANEXCEL.SIC[u8Instance], CANXL_INT_ERR_XL, enable);
            break;
        }
        case CANEXCEL_IP_INT_ERR_INT:
        {
            CanXL_SetErrIntCmd(CANEXCEL.SIC[u8Instance], CANXL_INT_INT_ERR, enable);
            break;
        }
        case CANEXCEL_IP_INT_BUSOFF:
        {
            CanXL_SetErrIntCmd(CANEXCEL.SIC[u8Instance], CANXL_INT_BUSOFF, enable);
            break;
        }
        case CANEXCEL_IP_INT_BUSOFF_DONE:
        {
            CanXL_SetErrIntCmd(CANEXCEL.SIC[u8Instance], CANXL_INT_BUSOFF_DONE, enable);
            break;
        }
        case CANEXCEL_IP_INT_FREEZE:
        {
            CanXL_SetErrIntCmd(CANEXCEL.SIC[u8Instance], CANXL_INT_FREEZE, enable);
            break;
        }
        case CANEXCEL_IP_INT_PASS_ERR:
        {
            CanXL_SetErrIntCmd(CANEXCEL.SIC[u8Instance], CANXL_INT_PASIVE_ERR, enable);
            break;
        }
        case CANEXCEL_IP_INT_MRUIE:
            CanXL_SetErrIntCmd(CANEXCEL.SIC[u8Instance], CANXL_INT_MRU, enable);
        break;
        default :
        {
            /* Do Nothing */
            break;
        }
    }
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
    DevAssert((boolean volatile)(instance < CANXL_SIC_INSTANCE_COUNT));
#endif
    const CANXL_SIC_Type * base = CANEXCEL.SIC[instance];
    return ((CANXL_SIC_SYSS_NTRDY_MASK == (base->SYSS & CANXL_SIC_SYSS_NTRDY_MASK)) ? TRUE : FALSE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_GetMdUnderrunError
 * Description   : Check if a MD  rx buffer underrun error was reported by CANEXCEL.
 *                 Error status cleared after read complete.
 *
 *END**************************************************************************/
boolean Canexcel_Ip_GetMdUnderrunError(uint8 instance)
{
    boolean isCMDUERR = FALSE;
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(instance < CANXL_SIC_INSTANCE_COUNT));
#endif
    isCMDUERR = ((CANXL_SIC_SYSS_CMDUERR_MASK == (CANEXCEL.SIC[instance]->SYSS & CANXL_SIC_SYSS_CMDUERR_MASK)) ? TRUE : FALSE);
    CANEXCEL.SIC[instance]->SYSS = CANXL_SIC_SYSS_CMDUERR_MASK;

    return isCMDUERR;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_GetRxFifoOverrunError
 * Description   : Check if a RXFIFO buffer overrun error was reported by CANEXCEL.
 *                 Error status cleared after read complete.
 *
 *END**************************************************************************/
boolean Canexcel_Ip_GetRxFifoOverrunError(uint8 instance)
{
    boolean isRXFEF = FALSE;
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(instance < CANXL_SIC_INSTANCE_COUNT));
#endif
    isRXFEF = ((CANXL_RXFIFO_CONTROL_RXFS_RXFEF_MASK == (CANEXCEL.RXF_CNT[instance]->RXFS & CANXL_RXFIFO_CONTROL_RXFS_RXFEF_MASK)) ? TRUE : FALSE);
    CANEXCEL.RXF_CNT[instance]->RXFS = CANXL_RXFIFO_CONTROL_RXFS_RXFEF_MASK;

    return isRXFEF;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_Get_RX_SMB_OverrunError
 * Description   : Check if a the internal two Rx SMB (SMB0 or SMB1) are ovewritten by a received frame
 *                 Error status cleared after read complete.
 *
 *END**************************************************************************/
boolean Canexcel_Ip_Get_RX_SMB_OverrunError(uint8 instance)
{
    boolean isCRXOERR = FALSE;
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(instance < CANXL_SIC_INSTANCE_COUNT));
#endif

    isCRXOERR = ((CANXL_SIC_SYSS_CRXOERR_MASK == (CANEXCEL.SIC[instance]->SYSS & CANXL_SIC_SYSS_CRXOERR_MASK)) ? TRUE : FALSE);
    CANEXCEL.SIC[instance]->SYSS = CANXL_SIC_SYSS_CRXOERR_MASK;

    return isCRXOERR;
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
    DevAssert((boolean volatile)(instance < CANXL_SIC_INSTANCE_COUNT));
    DevAssert((boolean volatile)(filterConfig->noActAddrFilters < CANXL_RXFIFO_ADDRACPTFLTAR_COUNT));
    DevAssert((boolean volatile)(filterConfig->noIdFilters < CANXL_RXFIFO_IDACPTFLTAR_COUNT));
    DevAssert((boolean volatile)(filterConfig->noSduFilters < CANXL_RXFIFO_SDUACPTFLTAR_COUNT));
    DevAssert((boolean volatile)(filterConfig->noVcanFilters < CANXL_RXFIFO_VCANACPTFLTAR_COUNT));
#endif
    Canexcel_Ip_StatusType status = CANEXCEL_STATUS_SUCCESS;
    CANXL_RXFIFO_Type * base = CANEXCEL.RXFIFO[instance];
    CANXL_RXFIFO_CONTROL_Type * rxFifoCont_base = CANEXCEL.RXF_CNT[instance];
    uint8 idx;
    if (0U == CANEXCEL.RXF_CNT[instance]->RXFSYSACT)
    {
        status = CANEXCEL_STATUS_ERROR;
    }
    else
    {
        if (TRUE == CanXL_IsFreezeMode(CANEXCEL.SIC[instance]))
        {
            #if (CANEXCEL_IP_HAS_SYSLOCK01 == STD_ON)
            /* Lock the RxFIFO by System by Writing 1 */
            rxFifoCont_base->RXFSYSLOCK = CANXL_RXFIFO_CONTROL_RXFSYSLOCK_SYSLOCK_MASK;
            #else
            /* Lock the RxFIFO by System by reading register */
            (void)rxFifoCont_base->RXFSYSLOCK;
            #endif
            SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_07();
            if (filterConfig->noIdFilters != 0U)
            {
                base->AFCFG = CANXL_RXFIFO_AFCFG_ACPTID((uint32)filterConfig->noIdFilters - 1U);
                for (idx = 0U; idx < filterConfig->noIdFilters; idx++)
                {
                    CanXL_ConfigIDFilter(base, &filterConfig->IdFilterPtr[idx], idx);
                }
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
                #if (CANEXCEL_IP_HAS_SYSLOCK01 == STD_ON)
                /* Clear the sys lock to enable transfers */
                rxFifoCont_base->RXFSYSLOCK = 0U;
                #else
                /* Clear the sys lock to enable transfers */
                rxFifoCont_base->RXFSYSLOCK = CANXL_RXFIFO_CONTROL_RXFSYSLOCK_SYSLOCK_MASK;
                #endif
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
boolean Canexcel_Ip_IsXLFrameType(uint8 instance, uint8 descNo,  uint8 maxNoOfMbDesc)
{
    const Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    boolean retVal = FALSE;
    if (descNo < maxNoOfMbDesc)
    {
        retVal = state->msgDescListPtr[descNo].isXLFrame;
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
    CANXL_SIC_Type * base = CANEXCEL.SIC[instance];;
    const Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    uint32 u32StatusError =0U;
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(instance < CANXL_SIC_INSTANCE_COUNT));
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
    CANXL_SIC_Type * base = CANEXCEL.SIC[instance];
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
    const CANXL_SIC_Type * base = CANEXCEL.SIC[instance];
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
    CANXL_SIC_Type * Base = CANEXCEL.SIC[Instance];

#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(Instance < CANXL_SIC_INSTANCE_COUNT));
    DevAssert((boolean volatile)(TimeSeg != NULL_PTR));
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
    CANXL_SIC_Type * Base = CANEXCEL.SIC[Instance];

#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(Instance < CANXL_SIC_INSTANCE_COUNT));
    DevAssert((boolean volatile)(TimeSeg != NULL_PTR));
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
    CANXL_SIC_Type * Base = CANEXCEL.SIC[Instance];
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(Instance < CANXL_SIC_INSTANCE_COUNT));
    DevAssert((boolean volatile)(TimeSeg != NULL_PTR));
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
    const CANXL_SIC_Type * Base = CANEXCEL.SIC[Instance];

#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(Instance < CANXL_SIC_INSTANCE_COUNT));
    DevAssert((boolean volatile)(TimeSeg != NULL_PTR));
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
    const CANXL_SIC_Type * Base = CANEXCEL.SIC[Instance];
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(Instance < CANXL_SIC_INSTANCE_COUNT));
    DevAssert((boolean volatile)(TimeSeg != NULL_PTR));
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
    const CANXL_SIC_Type * Base = CANEXCEL.SIC[Instance];
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(Instance < CANXL_SIC_INSTANCE_COUNT));
    DevAssert((boolean volatile)(TimeSeg != NULL_PTR));
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
    CANXL_SIC_Type * Base = CANEXCEL.SIC[Instance];

#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(Instance < CANXL_SIC_INSTANCE_COUNT));
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
    const CANXL_SIC_Type * Base = CANEXCEL.SIC[Instance];

#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(Instance < CANXL_SIC_INSTANCE_COUNT));
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
    CANXL_SIC_Type * Base = CANEXCEL.SIC[Instance];
    Canexcel_Ip_StatusType RetVal = CANEXCEL_STATUS_ERROR;

#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(Instance < CANXL_SIC_INSTANCE_COUNT));
    /* When TDC disabled, TDC Measurement has no meaning! */
    DevAssert((boolean volatile)(!((FALSE == TDCEnable) && (TRUE == TDCMEnable))));
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
    CANXL_SIC_Type * Base = CANEXCEL.SIC[Instance];
    Canexcel_Ip_StatusType RetVal = CANEXCEL_STATUS_ERROR;

#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(Instance < CANXL_SIC_INSTANCE_COUNT));
    /* When TDC disabled, TDC Measurement has no meaning! */
    DevAssert((boolean volatile)(!((FALSE == TDCEnable) && (TRUE == TDCMEnable))));
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
    CANXL_SIC_Type * Base = CANEXCEL.SIC[Instance];
    Canexcel_Ip_StatusType RetVal = CANEXCEL_STATUS_ERROR;

#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(Instance < CANXL_SIC_INSTANCE_COUNT));
    DevAssert((boolean volatile)(NULL_PTR != Config));
    /* when PWM mode enabled, protocol exception must be enabled */
    DevAssert((boolean volatile)(!((TRUE == Config->PwmModeEnable) && (FALSE == Config->ProtocolExceptionEnable))));
    /* when PWM mode enabled, PWMS must be in range [1:63] */
    DevAssert((boolean volatile)(!((TRUE == Config->PwmModeEnable) && ((0U == Config->PwmShortPhase) || (Config->PwmShortPhase > 63U)))));
    /* when PWM mode enabled, PWML must be in range [1:63] */
    DevAssert((boolean volatile)(!((TRUE == Config->PwmModeEnable) && ((0U == Config->PwmLongPhase) || (Config->PwmLongPhase > 63U)))));
    /* when PWM mode enabled, PWMO must be in range [0:63] */
    DevAssert((boolean volatile)(!((TRUE == Config->PwmModeEnable) && (Config->PwmOffset > 63U))));
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
    DevAssert((boolean volatile)(Instance < CANXL_SIC_INSTANCE_COUNT));
    DevAssert((boolean volatile)(Config->noActAddrFilters <= CANEXCEL_IP_MAX_FILTER_BANK));
    DevAssert((boolean volatile)(Config->noSduFilters <= CANEXCEL_IP_MAX_FILTER_BANK));
    DevAssert((boolean volatile)(Config->noVcanFilters <= CANEXCEL_IP_MAX_FILTER_BANK));
#endif
    Canexcel_Ip_StatusType status = CANEXCEL_STATUS_SUCCESS;
    uint8 idx;
    CANXL_FILTER_BANK_Type * base = CANEXCEL.FILTER[Instance];
    if (TRUE == CanXL_IsFreezeMode(CANEXCEL.SIC[Instance]))
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
    DevAssert((boolean volatile)(Instance < CANXL_SIC_INSTANCE_COUNT));
    DevAssert((boolean volatile)(Config->noActAddrFilters <= CANEXCEL_IP_MAX_FILTER_BANK));
    DevAssert((boolean volatile)(Config->noSduFilters <= CANEXCEL_IP_MAX_FILTER_BANK));
    DevAssert((boolean volatile)(Config->noVcanFilters <= CANEXCEL_IP_MAX_FILTER_BANK));
#endif
    Canexcel_Ip_StatusType status = CANEXCEL_STATUS_SUCCESS;
    uint8 idx;
    CANXL_FILTER_BANK_Type * base = CANEXCEL.FILTER[Instance];
    if (TRUE == CanXL_IsFreezeMode(CANEXCEL.SIC[Instance]))
    {
        /* Enable Filter bank #1 */
        CANEXCEL.SIC[Instance]->SYSMCFG |= CANXL_SIC_SYSMCFG_FB1EN_MASK;
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
            for (idx = 0U; idx < Config->noSduFilters; idx++)
            {
                CanXL_ConfigSDUFilterBank(base, 1U, &Config->SduFilterPtr[idx], idx);
            }
        }
        if (Config->noVcanFilters != 0U)
        {
            base->AFCFG1 |=  CANXL_FILTER_BANK_AFCFG1_AVCANEN_MASK | CANXL_FILTER_BANK_AFCFG1_ACPTVCAN((uint32)Config->noVcanFilters-1U);
            for (idx = 0U; idx < Config->noVcanFilters; idx++)
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
    DevAssert((boolean volatile)(Instance < CANXL_SIC_INSTANCE_COUNT));
    DevAssert((boolean volatile)(Config->noActAddrFilters <= CANEXCEL_IP_MAX_FILTER_BANK));
    DevAssert((boolean volatile)(Config->noSduFilters <= CANEXCEL_IP_MAX_FILTER_BANK));
    DevAssert((boolean volatile)(Config->noVcanFilters <= CANEXCEL_IP_MAX_FILTER_BANK));
#endif
    Canexcel_Ip_StatusType status = CANEXCEL_STATUS_SUCCESS;
    uint8 idx;
    CANXL_FILTER_BANK_Type * base = CANEXCEL.FILTER[Instance];
    if (TRUE == CanXL_IsFreezeMode(CANEXCEL.SIC[Instance]))
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
    DevAssert((boolean volatile)(Instance < CANXL_SIC_INSTANCE_COUNT));
    DevAssert((boolean volatile)(Config->noActAddrFilters <= CANEXCEL_IP_MAX_FILTER_BANK));
    DevAssert((boolean volatile)(Config->noSduFilters <= CANEXCEL_IP_MAX_FILTER_BANK));
    DevAssert((boolean volatile)(Config->noVcanFilters <= CANEXCEL_IP_MAX_FILTER_BANK));
#endif
    Canexcel_Ip_StatusType status = CANEXCEL_STATUS_SUCCESS;
    uint8 idx;
    CANXL_FILTER_BANK_Type * base = CANEXCEL.FILTER[Instance];
    if (TRUE == CanXL_IsFreezeMode(CANEXCEL.SIC[Instance]))
    {
        /* Enable Filter bank #1 */
        CANEXCEL.SIC[Instance]->SYSMCFG |= CANXL_SIC_SYSMCFG_FB1EN_MASK;
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
    DevAssert((boolean volatile)(Instance < CANXL_SIC_INSTANCE_COUNT));
    DevAssert((boolean volatile)(filterValue != NULL_PTR));
    DevAssert((boolean volatile)(filterNo != NULL_PTR));
#endif
    Canexcel_Ip_StatusType status = CANEXCEL_STATUS_SUCCESS;
    uint8 noFilter = 0U;
    if (TRUE == CanXL_IsFreezeMode(CANEXCEL.SIC[Instance]))
    {
        noFilter = (uint8)((CANEXCEL.FILTER[Instance]->AFCFG0 & CANXL_FILTER_BANK_AFCFG0_ACPTADDR_MASK) >> CANXL_FILTER_BANK_AFCFG0_ACPTADDR_SHIFT);
        if (0U == (CANEXCEL.FILTER[Instance]->AFCFG0 & CANXL_FILTER_BANK_AFCFG0_AADDREN_MASK))
        {
            CANEXCEL.FILTER[Instance]->AFCFG0 |=  CANXL_FILTER_BANK_AFCFG0_AADDREN_MASK;
        }
        else
        {
            noFilter++;

        }
        if (noFilter < CANEXCEL_IP_MAX_FILTER_BANK)
        {
            * filterNo = noFilter;
            CanXL_ConfigAccAddrFilterBank(CANEXCEL.FILTER[Instance], 0U, filterValue, noFilter);
            CANEXCEL.FILTER[Instance]->AFCFG0 |= CANXL_FILTER_BANK_AFCFG0_ACPTADDR(noFilter);
        }
        else
        {
            if (CANXL_SIC_SYSMCFG_FB1EN_MASK == (CANEXCEL.SIC[Instance]->SYSMCFG & CANXL_SIC_SYSMCFG_FB1EN_MASK))
            {
                noFilter = (uint8)((CANEXCEL.FILTER[Instance]->AFCFG1 & CANXL_FILTER_BANK_AFCFG1_ACPTADDR_MASK) >> CANXL_FILTER_BANK_AFCFG1_ACPTADDR_SHIFT);
                if (0U == (CANEXCEL.FILTER[Instance]->AFCFG1 & CANXL_FILTER_BANK_AFCFG0_AADDREN_MASK))
                {
                    CANEXCEL.FILTER[Instance]->AFCFG1 |=  CANXL_FILTER_BANK_AFCFG1_AADDREN_MASK;
                }
                else
                {
                    noFilter++;
                }
                if (noFilter < CANEXCEL_IP_MAX_FILTER_BANK)
                {
                    * filterNo = (CANEXCEL_IP_MAX_FILTER_BANK + noFilter);
                    CanXL_ConfigAccAddrFilterBank(CANEXCEL.FILTER[Instance], 1U, filterValue, noFilter);
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
    DevAssert((boolean volatile)(Instance < CANXL_SIC_INSTANCE_COUNT));
#endif

    return CanXL_GetDesciptorStatus(CANEXCEL.DESC_CTR[Instance], descNo, sysPoint, hwPoint);
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_SetMsgDescInterrupt
 * Description   : Enable\Disable the Message Descriptor Interrupt
 *END**************************************************************************/
/* implements  Canexcel_Ip_SetMsgDescInterrupt_Activity */
void Canexcel_Ip_SetMsgDescInterrupt(uint8 instance, uint8 descNo, boolean enable)
{
    if (TRUE == enable)
    {
        CanXL_SetMsgBuffIntCmd(CANEXCEL.GRP[instance], descNo);
    }
    else
    {
        CanXL_ClearMsgBuffIntCmd(CANEXCEL.GRP[instance], descNo);
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Canexcel_Ip_GetMsgDescInterrupt
 * Description   : Get the Message Descriptor Interrupt control status
 *END**************************************************************************/
/* implements  Canexcel_Ip_GetMsgDescInterrupt_Activity */
boolean Canexcel_Ip_GetMsgDescInterrupt(uint8 instance, uint8 descNo)
{
   return  CanXL_GetMsgBuffIntCmd(CANEXCEL.GRP[instance], descNo);
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
    DevAssert((boolean volatile)(instance < CANXL_SIC_INSTANCE_COUNT));
#endif
    const CANXL_GRP_CONTROL_Type * Base = CANEXCEL.GRP[instance];
    return CanXL_GetMsgDescIntStatusFlag(Base, descNo);
}

#if (CANXL_IP_HAS_ABORT == STD_ON)
Canexcel_Ip_StatusType Canexcel_Ip_AbortMD(uint8 instance, uint8 descNo)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(instance < CANXL_SIC_INSTANCE_COUNT));
#endif
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    const Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;
    uint32 uS2Ticks = OsIf_MicrosToTicks(CANEXCEL_IP_TIMEOUT_DURATION, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
    uint8 u8MbCnt = 0U;
    boolean isPending = FALSE;

    for (u8MbCnt = 0U; u8MbCnt < 16U; u8MbCnt++)
    {
        if (TRUE == state->msgDescListPtr[descNo].isPending[u8MbCnt])
        {
            isPending = TRUE;
            break;
        }
    }

    if (TRUE == isPending)
    {
        boolean descIntCtrl = CanXL_GetMsgBuffIntCmd(CANEXCEL.GRP[instance], descNo);
        CanXL_ClearMsgBuffIntCmd(CANEXCEL.GRP[instance], descNo);
        /* Request to abort the MD */
        CANEXCEL.SIC[instance]->SYSS = CANXL_SIC_SYSS_ABTACK_MASK;
        CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCABT = 1U;
        timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
        /* wait until the abort is completed */
        while (1U == CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCABT)
        {
            timeElapsed = OsIf_GetElapsed(&timeStart, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
            if (timeElapsed >= uS2Ticks)
            {
                returnResult = CANEXCEL_STATUS_TIMEOUT;
                break;
            }
            else
            {
                uS2Ticks -= timeElapsed;
            }
        }
        if (CANEXCEL_STATUS_SUCCESS == returnResult)
        {
            /* Clear IFLAG */
            CanXL_ClearMsgDescIntStatusFlag(CANEXCEL.GRP[instance], descNo);
            /* Reset noPointers */
            state->msgDescListPtr[descNo].noPointers = 0U;
            state->msgDescListPtr[descNo].lastHwIdex = 0U;
            state->msgDescListPtr[descNo].currBufferIdx = 0U;
            for (u8MbCnt = 0U; u8MbCnt < 16U; u8MbCnt++)
            {
                state->msgDescListPtr[descNo].isPending[u8MbCnt] = FALSE;
            }
        }
        if(descIntCtrl)
        {
            CanXL_SetMsgBuffIntCmd(CANEXCEL.GRP[instance], descNo);
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
    DevAssert((boolean volatile)(instance < CANXL_SIC_INSTANCE_COUNT));
#endif
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    const Canexcel_Ip_StateType * state = Canexcel_Ip_apxState[instance];
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;
    uint32 uS2Ticks = OsIf_MicrosToTicks(CANEXCEL_IP_TIMEOUT_DURATION, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
    uint8 u8MbCnt = 0U;
#if (CANXL_IP_HAS_ABORT == STD_ON)
    Canexcel_Ip_DescState DescState = CanXL_GetDesciptorState(CANEXCEL.DESC_CTR[instance], descNo);

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
	    CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK = 1U;
	    #else
	    (void)CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK;
	    #endif

	    /* Wait until syslock is retrieved */
	    timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
	    while (CANEXCEL_DESCNTSTATUS_LOCKED_SYS != CanXL_GetDescControlStatus(CANEXCEL.DESC_CTR[instance], descNo))
	    {
	        timeElapsed = OsIf_GetElapsed(&timeStart, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
	        if (timeElapsed >= uS2Ticks)
	        {
	            returnResult = CANEXCEL_STATUS_TIMEOUT;
	            break;
	        }
            else
            {
                uS2Ticks -= timeElapsed;
            }
	        /* It requires syslock before deactivation the MD */
	        #if (CANEXCEL_IP_HAS_SYSLOCK01 == STD_ON)
	        CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK = 1U;
	        #else
	        (void)CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK;
	        #endif
	    }
	    /* If syslock retrieved, deactivate the MD */
	    if (CANEXCEL_STATUS_SUCCESS == returnResult)
	    {
	        /* as result, the MD is deactivated(syspointer and hwpointer are reset).
	         * And it can't participate in the message Tx or Rx process.
	        */
	        CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCACT = 0U;
	        /* Release syslock */
	        #if (CANEXCEL_IP_HAS_SYSLOCK01 == STD_ON)
	        CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK = 0U;
	        #else
	        CANEXCEL.DESC_CTR[instance]->DSCMBCTRLAR[descNo].DCSYSLOCK = 1U;
	        #endif
	        /* Clear IFLAG */
	        CanXL_ClearMsgDescIntStatusFlag(CANEXCEL.GRP[instance], descNo);
	        /* Reset noPointers */
	        state->msgDescListPtr[descNo].noPointers = 0U;
	        state->msgDescListPtr[descNo].lastHwIdex = 0U;
            state->msgDescListPtr[descNo].currBufferIdx = 0U;
            for (u8MbCnt = 0U; u8MbCnt < 16U; u8MbCnt++)
            {
                state->msgDescListPtr[descNo].isPending[u8MbCnt] = FALSE;
            }
	    }
    }

    return returnResult;
}



/* implements  Canexcel_Ip_DeactivateRXFIFO_Activity */
Canexcel_Ip_StatusType Canexcel_Ip_DeactivateRXFIFO(uint8 instance)
{
#if (CANEXCEL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((boolean volatile)(instance < CANXL_SIC_INSTANCE_COUNT));
#endif
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;
    uint32 uS2Ticks = OsIf_MicrosToTicks(CANEXCEL_IP_TIMEOUT_DURATION, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);

/* It requires syslock before deactivation the RXFIFO */
#if (CANEXCEL_IP_HAS_SYSLOCK01 == STD_ON)
    CANEXCEL.RXF_CNT[instance]->RXFSYSLOCK = CANXL_RXFIFO_CONTROL_RXFSYSLOCK_SYSLOCK_MASK;
#else
    (void)CANEXCEL.RXF_CNT[instance]->RXFSYSLOCK;
#endif

    /* Wait until syslock is retrieved */
    timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
    while (CANXL_RXFIFO_CONTROL_RXFCSTA_SYSLOCK_MASK != (CANEXCEL.RXF_CNT[instance]->RXFCSTA & CANXL_RXFIFO_CONTROL_RXFCSTA_SYSLOCK_MASK))
    {
        timeElapsed = OsIf_GetElapsed(&timeStart, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
        if (timeElapsed >= uS2Ticks)
        {
            returnResult = CANEXCEL_STATUS_TIMEOUT;
            break;
        }
        else
        {
            uS2Ticks -= timeElapsed;
        }
/* It requires syslock before deactivation the RXFIFO */
#if (CANEXCEL_IP_HAS_SYSLOCK01 == STD_ON)
        CANEXCEL.RXF_CNT[instance]->RXFSYSLOCK = CANXL_RXFIFO_CONTROL_RXFSYSLOCK_SYSLOCK_MASK;
#else
        (void)CANEXCEL.RXF_CNT[instance]->RXFSYSLOCK;
#endif
    }
    /* If syslock retrieved, deactivate the MD */
    if (CANEXCEL_STATUS_SUCCESS == returnResult)
    {
        /* as result, the RXFIFO is deactivated(syspointer and hwpointer are reset).
         * And it can't participate in the message  Rx process.
         */
        CANEXCEL.RXF_CNT[instance]->RXFSYSACT = 0u;
/* Release syslock */
#if (CANEXCEL_IP_HAS_SYSLOCK01 == STD_ON)
        /* Clear the sys lock to enable transfers */
        CANEXCEL.RXF_CNT[instance]->RXFSYSLOCK = 0U;
#else
        /* Clear the sys lock to enable transfers */
        CANEXCEL.RXF_CNT[instance]->RXFSYSLOCK = CANXL_RXFIFO_CONTROL_RXFSYSLOCK_SYSLOCK_MASK;
#endif
        /* Clear IFLAG */
        CANEXCEL.RXF_CNT[instance]->RXFS |= CANXL_RXFIFO_CONTROL_RXFS_RXFF_MASK;
        /* Reset currBufferIdx */
        Canexcel_Ip_apxState[instance]->rxFifo.currBufferIdx = 0U;
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
    DevAssert((boolean volatile)(u8Instance < CANXL_SIC_INSTANCE_COUNT));
#endif
    Canexcel_Ip_StatusType retVal;

    retVal = CanXL_SoftReset(CANEXCEL.SIC[u8Instance]);
    if (CANEXCEL_STATUS_SUCCESS == retVal)
    {
        retVal = CanXL_EnterFreezeMode(CANEXCEL.SIC[u8Instance]);
    }
    if (CANEXCEL_STATUS_SUCCESS == retVal)
    {
        /* Clear status to default values */
        CANEXCEL.SIC[u8Instance]->SYSS = CANEXCEL_IP_SYSS_CLEAR_DEFAULT_VALUE_U32;
        /* Clear Memory ram and initialize it */
        CanXL_ClearRAM(&CANEXCEL, u8Instance);
        /* Restore Default Values */
        CANEXCEL.SIC[u8Instance]->BBPRS = 0U;
        CANEXCEL.SIC[u8Instance]->BCFG1 = 0U;
        CANEXCEL.SIC[u8Instance]->BCFG2 = CANEXCEL_IP_BCFG2_DEFAULT_VALUE_U32;
        CANEXCEL.SIC[u8Instance]->BNCBT = CANEXCEL_IP_BNCBT_DEFAULT_VALUE_U32;
        CANEXCEL.SIC[u8Instance]->BFDCBT = CANEXCEL_IP_BFDCBT_DEFAULT_VALUE_U32;
        CANEXCEL.SIC[u8Instance]->BXDCBT = CANEXCEL_IP_BXDCBT_DEFAULT_VALUE_U32;
        CANEXCEL.SIC[u8Instance]->BTDCC = 0U;
        CANEXCEL.SIC[u8Instance]->BMICI = 0U;
        CANEXCEL.MRU[u8Instance]->CHXCONFIG[0u].CH_CFG0 = 0U;
    }
    return retVal;
}

#define CAN_43_CANEXCEL_STOP_SEC_CODE
#include "Can_43_CANEXCEL_MemMap.h"

/** @} */

