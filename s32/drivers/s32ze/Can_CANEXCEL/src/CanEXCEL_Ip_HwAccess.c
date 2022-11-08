/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file CanEXCEL_Ip_HwAccess.c
*
*   @addtogroup CanEXCEL
*   @{
*/

#include "CanEXCEL_Ip_HwAccess.h"
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* CAN FD extended data length DLC encoding */
#define FLEXCAN_IP_DLC_VALUE_12_BYTES              9U
#define FLEXCAN_IP_DLC_VALUE_16_BYTES              10U
#define FLEXCAN_IP_DLC_VALUE_20_BYTES              11U
#define FLEXCAN_IP_DLC_VALUE_24_BYTES              12U
#define FLEXCAN_IP_DLC_VALUE_32_BYTES              13U
#define FLEXCAN_IP_DLC_VALUE_48_BYTES              14U
#define FLEXCAN_IP_DLC_VALUE_64_BYTES              15U

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
static volatile uint32 Canexcel_Ip_au32ImaskBuff[CANXL_GRP_CONTROL_INSTANCE_COUNT][CANXL_GRP_CONTROL_MSGIMASKARRAY_COUNT];
static volatile uint32 Canexcel_Ip_au32DescHostInt[CANXL_GRP_CONTROL_INSTANCE_COUNT];
static volatile uint8 Canexcel_Ip_au8RxFifoInt[CANXL_GRP_CONTROL_INSTANCE_COUNT];
/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_SetErrIntCmd
 * Description   : Enable the error interrupts.
 * This function will enable Error interrupt.
 *
 *END**************************************************************************/
void CanXL_SetErrIntCmd(CANXL_SIC_Type * base, canxl_int_type_t errType, boolean enable)
{
    uint32 temp = (uint32)errType;
    if (enable)
    {
        base->SYSIE |= temp;
    }
    else
    {
        base->SYSIE &= (~temp);
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name: CAN_ComputeDLCValue
 * Description  : Computes the DLC field value, given a payload size (in bytes).
 * This is compatible only for Classical CAN Format (FDF=0) and CAN FD Format (FDF=1
 * and XLF=0), for CAN XL Format (FDF=1 and XLF=1) is size is DLC+1 value
 *END**************************************************************************/
uint8 CAN_ComputeDLCValue(uint8 payloadSize)
{
    uint32 ret = 0xFFU;                   /* 0,  1,  2,  3,  4,  5,  6,  7,  8, */
    static const uint8 payload_code[65] = {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U,
                                           /* 9 to 12 payload have DLC Code 12 Bytes */
                                           FLEXCAN_IP_DLC_VALUE_12_BYTES, FLEXCAN_IP_DLC_VALUE_12_BYTES, FLEXCAN_IP_DLC_VALUE_12_BYTES, FLEXCAN_IP_DLC_VALUE_12_BYTES,
                                           /* 13 to 16 payload have DLC Code 16 Bytes */
                                           FLEXCAN_IP_DLC_VALUE_16_BYTES, FLEXCAN_IP_DLC_VALUE_16_BYTES, FLEXCAN_IP_DLC_VALUE_16_BYTES, FLEXCAN_IP_DLC_VALUE_16_BYTES,
                                           /* 17 to 20 payload have DLC Code 20 Bytes */
                                           FLEXCAN_IP_DLC_VALUE_20_BYTES, FLEXCAN_IP_DLC_VALUE_20_BYTES, FLEXCAN_IP_DLC_VALUE_20_BYTES, FLEXCAN_IP_DLC_VALUE_20_BYTES,
                                           /* 21 to 24 payload have DLC Code 24 Bytes */
                                           FLEXCAN_IP_DLC_VALUE_24_BYTES, FLEXCAN_IP_DLC_VALUE_24_BYTES, FLEXCAN_IP_DLC_VALUE_24_BYTES, FLEXCAN_IP_DLC_VALUE_24_BYTES,
                                           /* 25 to 32 payload have DLC Code 32 Bytes */
                                           FLEXCAN_IP_DLC_VALUE_32_BYTES, FLEXCAN_IP_DLC_VALUE_32_BYTES, FLEXCAN_IP_DLC_VALUE_32_BYTES, FLEXCAN_IP_DLC_VALUE_32_BYTES,
                                           FLEXCAN_IP_DLC_VALUE_32_BYTES, FLEXCAN_IP_DLC_VALUE_32_BYTES, FLEXCAN_IP_DLC_VALUE_32_BYTES, FLEXCAN_IP_DLC_VALUE_32_BYTES,
                                           /* 33 to 48 payload have DLC Code 48 Bytes */
                                           FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES,
                                           FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES,
                                           FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES,
                                           FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES, FLEXCAN_IP_DLC_VALUE_48_BYTES,
                                           /* 49 to 64 payload have DLC Code 64 Bytes */
                                           FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES,
                                           FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES,
                                           FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES,
                                           FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES, FLEXCAN_IP_DLC_VALUE_64_BYTES
                                          };

    if (payloadSize <= 64U)
    {
        ret = payload_code[payloadSize];
    }
    else
    {
        /* The argument is not a valid payload size will return 0xFF*/
    }
    return (uint8)ret;
}

uint16 CanXL_SetDLCValue(CANXL_SIC_Type * base, uint16 payloadSize)
{
    if(CANXL_SIC_BCFG2_XLEN_MASK == (base->BCFG1 & CANXL_SIC_BCFG2_XLEN_MASK))
    {
        return (payloadSize-1);
    }
    else
    {
        return CAN_ComputeDLCValue(payloadSize);
    }
}

static uint8 CAN_ComputePayloadSize(uint8 dlcValue)
{
    uint8 ret = 8U;

    if (dlcValue <= 8U)
    {
        ret = dlcValue;
    }
    else
    {
        switch (dlcValue)
        {
            case FLEXCAN_IP_DLC_VALUE_12_BYTES:
                ret = 12U;
                break;
            case FLEXCAN_IP_DLC_VALUE_16_BYTES:
                ret = 16U;
                break;
            case FLEXCAN_IP_DLC_VALUE_20_BYTES:
                ret = 20U;
                break;
            case FLEXCAN_IP_DLC_VALUE_24_BYTES:
                ret = 24U;
                break;
            case FLEXCAN_IP_DLC_VALUE_32_BYTES:
                ret = 32U;
                break;
            case FLEXCAN_IP_DLC_VALUE_48_BYTES:
                ret = 48U;
                break;
            case FLEXCAN_IP_DLC_VALUE_64_BYTES:
                ret = 64U;
                break;
            default:
                /* The argument is not a valid DLC size */
                break;
        }
    }
    return ret;
}

Canexcel_Ip_StatusType CanXL_SoftReset(CANXL_SIC_Type * base)
{
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;
    uint32 uS2Ticks = OsIf_MicrosToTicks(CANEXCEL_IP_TIMEOUT_DURATION, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
    base->SYSMC = CANXL_SIC_SYSMC_SOFRST_MASK;
    while ((base->SYSMC & CANXL_SIC_SYSMC_SOFRST_MASK) == CANXL_SIC_SYSMC_SOFRST_MASK)
    {
        timeElapsed += OsIf_GetElapsed(&timeStart, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
        if (timeElapsed >= uS2Ticks)
        {
            returnResult = CANEXCEL_STATUS_TIMEOUT;
            break;
        }
    }
    return returnResult;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_ClearRAM
 * Description   : Clears CANEXCEL memory positions that require initialization.
 *
 *END**************************************************************************/
void CanXL_ClearRAM(CANEXCEL_StructType * CANXL, uint8 instance)
{
   uint16 idx;
   CANXL_MSG_DESCRIPTORS_Type * base_Msg_Desc = CANXL->EXL_MSGD[instance];
   for(idx=0u; idx < CANXL_MSG_DESCRIPTORS_MSGDSC_COUNT; idx++)
   {
       base_Msg_Desc->MSGDSC[idx].CTRL.RXCTRL = 0U;
       base_Msg_Desc->MSGDSC[idx].CFG1.MDFLT1FD = 0U;
       base_Msg_Desc->MSGDSC[idx].CFG2.MDFLT2FD = 0U;
       base_Msg_Desc->MSGDSC[idx].LSTPNT.RXLSTPTR = 0U;
       for(uint8 i=0;i<16u;i++)
       {
           /* Initialize the msg descriptor reserved space */
           base_Msg_Desc->MSGDSC[idx].RESERVED_0[i] = 0U;
       }
   }
   /* Clear the filter bank check the size in device reg as FILTER_BANK_SIZE */
   uint32 * ptr = (uint32 *)&CANXL->EXL_FILTER[instance]->AFCFG0;
   for(idx = 0u; idx <= FILTER_BANK_SIZE/4; idx++ )
   {
       * ptr = 0U;
       ptr++;
   }
   /* Clear and initilize RXFIFO memory */
   CANXL_RXFIFO_Type * base_RxFifo = CANXL->EXL_RXFIFO[instance];
   base_RxFifo->RXFFCTR = 0U;
   for(idx = 0u; idx < CANXL_RXFIFO_RXFFPOINTERAR_COUNT; idx++)
   {
       base_RxFifo->RXFMBP[idx] = 0U;
   }
   base_RxFifo->SECAM = 0U;
   base_RxFifo->SECAV = 0U;
   base_RxFifo->AFCFG = 0U;
   base_RxFifo->VAMRCFG = 0U;
   base_RxFifo->SAMRCFG = 0U;
   base_RxFifo->AAMRCFG = 0U;
   base_RxFifo->ACPTIDMR = 0U;
   for(idx = 0u; idx < CANXL_RXFIFO_VCANACPTFLTAR_COUNT; idx++)
   {
       base_RxFifo->VAFLT[idx] = 0U;
   }
   for(idx = 0u; idx < CANXL_RXFIFO_SDUACPTFLTAR_COUNT; idx++)
   {
       base_RxFifo->SAFLT[idx] = 0U;
   }
   for(idx = 0u; idx < CANXL_RXFIFO_ADDRACPTFLTAR_COUNT; idx++)
   {
       base_RxFifo->ADDRACPTFLTAR[idx].AAFLTL = 0U;
       base_RxFifo->ADDRACPTFLTAR[idx].AAFLTH = 0U;
   }
   for(idx = 0u; idx < CANXL_RXFIFO_IDACPTFLTAR_COUNT; idx++)
   {
       base_RxFifo->IDACPTFLTAR[idx].IDAFLTL = 0U;
       base_RxFifo->IDACPTFLTAR[idx].IDAFLTH = 0U;
   }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CANXL_EnterFreezeMode
 * Description   : Enter the freeze mode.
 *
 *END**************************************************************************/
Canexcel_Ip_StatusType CanXL_EnterFreezeMode(CANXL_SIC_Type * base)
{
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = OsIf_MicrosToTicks(CANEXCEL_IP_TIMEOUT_DURATION, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;
    boolean lowPower =  FALSE;

    /* Start critical section: implementation depends on integrator */
    if(((base->SYSS & CANXL_SIC_SYSS_FRZACKF_MASK) == CANXL_SIC_SYSS_FRZACKF_MASK) && ((base->SYSMC & CANXL_SIC_SYSMC_FRZREQ_MASK) == 0U))
    {
        if((base->SYSS & CANXL_SIC_SYSS_LPMACKF_MASK) && ((base->SYSMC & CANXL_SIC_SYSMC_LPMREQ_MASK) == CANXL_SIC_SYSMC_LPMREQ_MASK))
        {
            lowPower = TRUE;
            /* Exit low Power Mode to allow Freeze Enter Mode */
            base->SYSS |= CANXL_SIC_SYSS_LPMACKF_MASK;
            base->SYSMC &= ~CANXL_SIC_SYSMC_LPMREQ_MASK;
            timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
            while(0U == (base->SYSS & CANXL_SIC_SYSS_LPMACKF_MASK))
            {
                timeElapsed += OsIf_GetElapsed(&timeStart, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
                if (timeElapsed >= uS2Ticks)
                {
                    returnResult = CANEXCEL_STATUS_TIMEOUT;
                    break;
                }
            }
        }
        /* Request Freeze Enter Mode */
        base->SYSS |= CANXL_SIC_SYSS_FRZACKF_MASK;
        base->SYSMC |= CANXL_SIC_SYSMC_FRZREQ_MASK;
    }
    if(CANEXCEL_STATUS_SUCCESS == returnResult)
    {
        timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
        while (0U == (base->SYSS & CANXL_SIC_SYSS_FRZACKF_MASK))
        {
            timeElapsed += OsIf_GetElapsed(&timeStart, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
            if (timeElapsed >= uS2Ticks)
            {
                returnResult = CANEXCEL_STATUS_TIMEOUT;
                break;
            }
        }
    }

    if((CANEXCEL_STATUS_SUCCESS == returnResult) && TRUE == lowPower)
    {
        base->SYSS = CANXL_SIC_SYSS_LPMACKF_MASK;
        base->SYSMC |= CANXL_SIC_SYSMC_LPMREQ_MASK;
        timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
        while(0U == (base->SYSS & CANXL_SIC_SYSS_LPMACKF_MASK))
        {
            timeElapsed += OsIf_GetElapsed(&timeStart, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
            if (timeElapsed >= uS2Ticks)
            {
                returnResult = CANEXCEL_STATUS_TIMEOUT;
                break;
            }
        }
    }
    return returnResult;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CANXL_ExitFreezeMode
 * Description   : Exit the freeze mode.
 *
 *END**************************************************************************/
Canexcel_Ip_StatusType CanXL_ExitFreezeMode(CANXL_SIC_Type * base)
{
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    uint32 uS2Ticks = OsIf_MicrosToTicks(CANEXCEL_IP_TIMEOUT_DURATION, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;
    boolean lowPower =  FALSE;
    if((base->SYSS & CANXL_SIC_SYSS_FRZACKF_MASK) != 0U)
    {
        if(base->SYSS & CANXL_SIC_SYSS_LPMACKF_MASK)
        {
            lowPower = TRUE;
            base->SYSS = CANXL_SIC_SYSS_LPMACKF_MASK;
            /* Exit low Power Mode to allow Freeze Exit Mode */
            base->SYSMC &= ~CANXL_SIC_SYSMC_LPMREQ_MASK;
            timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
            while(0U == (base->SYSS & CANXL_SIC_SYSS_LPMACKF_MASK))
            {
                timeElapsed += OsIf_GetElapsed(&timeStart, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
                if (timeElapsed >= uS2Ticks)
                {
                    returnResult = CANEXCEL_STATUS_TIMEOUT;
                    break;
                }
            }
        }
    }
    if(CANEXCEL_STATUS_SUCCESS == returnResult)
    {
        base->SYSS = CANXL_SIC_SYSS_FRZACKF_MASK;
        /* Request exit Freeze Mode */
        base->SYSMC &= ~CANXL_SIC_SYSMC_FRZREQ_MASK;
        timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
        while (0U == (base->SYSS & CANXL_SIC_SYSS_FRZACKF_MASK))
        {
            timeElapsed += OsIf_GetElapsed(&timeStart, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
            if (timeElapsed >= uS2Ticks)
            {
                returnResult = CANEXCEL_STATUS_TIMEOUT;
                break;
            }
        }
    }
    if((CANEXCEL_STATUS_SUCCESS == returnResult) && (TRUE == lowPower))
    {
        base->SYSS = CANXL_SIC_SYSS_LPMACKF_MASK;
        base->SYSMC |= CANXL_SIC_SYSMC_LPMREQ_MASK;
        while(0U == (base->SYSS & CANXL_SIC_SYSS_LPMACKF_MASK))
        {
            timeElapsed += OsIf_GetElapsed(&timeStart, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
            if (timeElapsed >= uS2Ticks)
            {
                returnResult = CANEXCEL_STATUS_TIMEOUT;
                break;
            }
        }
    }
    return returnResult;
}

Canexcel_Ip_DesCntStatus CanXL_GetDescControlStatus(CANXL_DSC_CONTROL_Type * base, uint8 descNo)
{
    switch((base->DSCMBCTRLAR[descNo].STA.DCSTA & (CANXL_DSC_CONTROL_DCSTA_HWLOCK_MASK | CANXL_DSC_CONTROL_DCSTA_SYSLOCK_MASK))>>CANXL_DSC_CONTROL_DCSTA_HWLOCK_SHIFT)
    {
        case 0U:
            return CANEXCEL_DESCNTSTATUS_UNLOCKED;
        case 1U:
            return CANEXCEL_DESCNTSTATUS_LOCKED_HW;
        case 2U:
            return CANEXCEL_DESCNTSTATUS_LOCKED_SYS;
        case 3:
            return CANEXCEL_DESCNTSTATUS_INVALID;
        default:
            return CANEXCEL_DESCNTSTATUS_INVALID;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_SetOperationMode
 * Description   : Enable a FlexCAN operation mode.
 * This function will enable one of the modes listed in flexcan_operation_modes_t.
 *
 *END**************************************************************************/
void CanXL_SetOperationMode(CANXL_SIC_Type * base, Canexcel_Ip_ModesType mode)
{
    switch (mode)
    {
        case CANEXCEL_NORMAL_MODE:
            base->BCFG2 = (base->BCFG2 & ~CANXL_SIC_BCFG2_LOM_MASK) | CANXL_SIC_BCFG2_LOM(0U);
            base->BCFG2 = (base->BCFG2 & ~CANXL_SIC_BCFG2_LPB_MASK) | CANXL_SIC_BCFG2_LPB(0U);
            break;
        case CANEXCEL_LISTEN_ONLY_MODE:
            base->BCFG2 = (base->BCFG2 & ~CANXL_SIC_BCFG2_LOM_MASK) | CANXL_SIC_BCFG2_LOM(1U);;
            break;
        case CANEXCEL_LOOPBACK_MODE:
            base->BCFG2 = (base->BCFG2 & ~CANXL_SIC_BCFG2_LPB_MASK) | CANXL_SIC_BCFG2_LPB(1U);
            base->BCFG2 = (base->BCFG2 & ~CANXL_SIC_BCFG2_LOM_MASK) | CANXL_SIC_BCFG2_LOM(0U);
            base->BCFG2 = (base->BCFG2 & ~CANXL_SIC_BCFG2_TMSE_MASK);
            /* Enable Self Reception */
            CanXL_SetSelfReception(base, TRUE);
            break;
        default:
            /* Should not get here */
            break;
    }
}


void CanXL_SetTxMsgBuffData(const Canexcel_Ip_DataInfoType * info, const uint8 * data, uint8 * MB)
{
    volatile uint32 * Mb_Data_32 = (volatile uint32 *)MB;
    const uint32 * MsgData_32 = (const uint32*)data;
    uint16 idx;
    for(idx = 0u; idx< (info->dataLength & ~3U); idx +=4u )
    {
        * Mb_Data_32 = * MsgData_32;
       Mb_Data_32++;
       MsgData_32++;
    }
    for ( ; idx < info->dataLength; idx++)
    {
        MB[idx] =  data[idx];
    }

    if(info->frame == CANEXCEL_FD_FRAME)
    {
        uint8 dlcValue = CAN_ComputeDLCValue(info->dataLength);
        uint8 calcValue = CAN_ComputePayloadSize(dlcValue);
        for(idx = info->dataLength; idx<calcValue; idx++)
        {
            MB[idx] = info->fd_padding;
        }
    }
}

void CanXL_ConfigInterrupts(uint8 Instance)
{
    Canexcel_Ip_au32DescHostInt[Instance] = CANXL_SIC_SYSMDHICFG_TXDCFGHI0_0_MASK | CANXL_SIC_SYSMDHICFG_TXDCFGHI0_1_MASK | CANXL_SIC_SYSMDHICFG_TXDCFGHI0_2_MASK | CANXL_SIC_SYSMDHICFG_TXDCFGHI0_3_MASK |
                                            CANXL_SIC_SYSMDHICFG_RXDCFGHI0_0_MASK | CANXL_SIC_SYSMDHICFG_RXDCFGHI0_1_MASK | CANXL_SIC_SYSMDHICFG_RXDCFGHI0_2_MASK | CANXL_SIC_SYSMDHICFG_RXDCFGHI0_3_MASK;
}

void CanXL_EnableInterrupts(CANXL_SIC_Type * base, uint8 Instance)
{
    base->SYSMDHICFG = Canexcel_Ip_au32DescHostInt[Instance];
    /*uint8 ImaskCnt = 0U;
    for (ImaskCnt = 0U; ImaskCnt < CANXL_GRP_CONTROL_MSGIMASKARRAY_COUNT; ImaskCnt++)
    {
       base->MSGIMASK[ImaskCnt] = Canexcel_Ip_au32ImaskBuff[Instance][ImaskCnt];
    }*/
}

void CanXL_DisableInterrupts(CANXL_SIC_Type * base, uint8 Instance)
{
    Canexcel_Ip_au32DescHostInt[Instance] = base->SYSMDHICFG;
    base->SYSMDHICFG = 0U;
    /*uint8 ImaskCnt = 0U;
    for (ImaskCnt = 0U; ImaskCnt < GRP_CONTROL_MSGIMASKARRAY_COUNT; ImaskCnt++)
    {
       base->MSGIMASK[ImaskCnt] = 0U;
    }*/
}
/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_ResetImaskBuff (uses in Canexcel_Ip_Init function only)
 * Description   : Reset Imask Buffers.
 *
 *END**************************************************************************/
void CanXL_ResetImaskBuff(CANXL_GRP_CONTROL_Type * base,uint8 Instance)
{
    uint8 ImaskCnt = 0U;
    for (ImaskCnt = 0U; ImaskCnt < CANXL_GRP_CONTROL_MSGIMASKARRAY_COUNT; ImaskCnt++)
    {
        base->MSGIMASK[ImaskCnt] = 0U;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_ConfigCtrlOptions
 * Description   : configure controller depending on options
 * note: Protocol exception should not be enabled with XL frame support.
 *
 *END**************************************************************************/
Canexcel_Ip_StatusType CanXL_ConfigCtrlOptions(CANXL_SIC_Type * base, uint32 u32Options)
{
    Canexcel_Ip_StatusType status = CANEXCEL_STATUS_SUCCESS;
    if ((base->BCFG2 & CANXL_SIC_BCFG2_XLEN_MASK) && ((u32Options & CANXL_IP_PROTOCOL_EXCEPTION_U32) != 0U))
    {
        status = CANEXCEL_STATUS_ERROR;
    }
    else
    {
        /* Set protocol Exception, PEXCE must be cleared when BCFG2[XLEN] is set. */
        if ((u32Options & CANXL_IP_PROTOCOL_EXCEPTION_U32) != 0U)
        {
            /* 1b - Protocol exception feature enabled */
            base->BCFG2 |=  CANXL_SIC_BCFG2_PEXCE_MASK;
        }
        else
        {
            /* 0b - Protocol exception feature disabled */
            base->BCFG2 &=  (~CANXL_SIC_BCFG2_PEXCE_MASK);
        }
    }
    if ((u32Options & CANXL_IP_ROM_U32) != 0U)
    {
        base->BCFG2 |= CANXL_SIC_BCFG2_ROM_MASK;
    }
    else
    {
        base->BCFG2 &= (~CANXL_SIC_BCFG2_ROM_MASK);
    }
    if ((u32Options & CANXL_IP_TX_ERROR_RESPONSE_U32) != 0U)
    {
        base->BCFG2 |= CANXL_SIC_BCFG2_TFER_MASK;
    }
    else
    {
        base->BCFG2 &= (~CANXL_SIC_BCFG2_TFER_MASK);
    }
    if ((u32Options & CANXL_IP_BUSOFF_RECOVERY_U32) != 0U)
    {
        /* 0b - Automatic bus-off recovery is enabled */
        base->BCFG1 &= (~CANXL_SIC_BCFG1_ABRDIS_MASK);
    }
    else
    {
        /* 1b - Automatic bus-off recovery is disabled */
        base->BCFG1 |= CANXL_SIC_BCFG1_ABRDIS_MASK;
    }
    if ((u32Options & CANXL_IP_EDGE_FILTER_U32) != 0U)
    {
        /* 0b - Edge Filter is enabled */
        base->BCFG1 &= (~CANXL_SIC_BCFG1_ABRDIS_MASK);
    }
    else
    {
        /* 1b - Edge Filter is disabled */
        base->BCFG1 |= CANXL_SIC_BCFG1_ABRDIS_MASK;
    }
    return status;
}

void CanXL_ConfigAccAddr(CANXL_RXFIFO_Type * base, Canexcel_Ip_RxFifoFilterID_ADDR * filter, uint8 filtIdx)
{
	uint32 mask = 1UL << filtIdx%32U;
	if(filter->filterType == CANEXCEL_IP_RX_FIFO_RANGE_FILTER)
	{
		/* Enable Range Filter operation */
		base->AAMRCFG |= mask;
	}
	else
	{	/* Enable Mask Filter operation */
		base->AAMRCFG &= (~mask);
	}
	base->ADDRACPTFLTAR[filtIdx].AAFLTH = filter->idAddrFilterH;
	base->ADDRACPTFLTAR[filtIdx].AAFLTL = filter->idAddrFilterL;
}

void CanXL_ConfigIDFilter(CANXL_RXFIFO_Type * base, Canexcel_Ip_RxFifoFilterID_ADDR * filter, uint8 filtIdx)
{
	uint32 mask = 1UL << filtIdx%32U;
	if(filter->filterType == CANEXCEL_IP_RX_FIFO_RANGE_FILTER)
	{
		/* Enable Range Filter operation */
		base->ACPTIDMR |= mask;
	}
	else
	{	/* Enable Mask Filter operation */
		base->ACPTIDMR &= (~mask);
	}
	base->IDACPTFLTAR[filtIdx].IDAFLTH = filter->idAddrFilterH;
	base->IDACPTFLTAR[filtIdx].IDAFLTL = filter->idAddrFilterL;
}

void CanXL_ConfigSDUFilter(CANXL_RXFIFO_Type * base, Canexcel_Ip_RxFifoFilterSDU_CAN * filter, uint8 filtIdx)
{
	uint32 mask = 1UL << filtIdx%32U;
	if(filter->filterType == CANEXCEL_IP_RX_FIFO_RANGE_FILTER)
	{
		/* Enable Range Filter operation */
		base->SAMRCFG |= mask;
	}
	else
	{	/* Enable Mask Filter operation */
		base->SAMRCFG &= (~mask);
	}
	/* Div the register selection to 2, this register is composed form a pair of SDU filter */
	base->SAFLT[filtIdx>>2U] = 0U;
	if(filtIdx % 2  == 0U)
	{
		base->SAFLT[filtIdx>>2U] |= CANXL_RXFIFO_SAFLT_SDUa_H(filter->sduVcanFilterH) | CANXL_RXFIFO_SAFLT_SDUa_L(filter->sduVcanFilterL);
	}
	else
	{
		base->SAFLT[filtIdx>>2U] |= CANXL_RXFIFO_SAFLT_SDUb_H(filter->sduVcanFilterH) | CANXL_RXFIFO_SAFLT_SDUb_L(filter->sduVcanFilterL);
	}
}

void CanXL_ConfigVCANFilter(CANXL_RXFIFO_Type * base, Canexcel_Ip_RxFifoFilterSDU_CAN * filter, uint8 filtIdx)
{
	uint32 mask = 1UL << filtIdx%32U;
	if(filter->filterType == CANEXCEL_IP_RX_FIFO_RANGE_FILTER)
	{
		/* Enable Range Filter operation */
		base->VAMRCFG |= mask;
	}
	else
	{	/* Enable Mask Filter operation */
		base->VAMRCFG &= (~mask);
	}
	/* Div the register selection to 2, this register is composed form a pair of SDU filter */
	base->VAFLT[filtIdx>>2U] = 0U;
	if(filtIdx % 2  == 0U)
	{
		base->VAFLT[filtIdx>>2U] |= CANXL_RXFIFO_VAFLT_VCANa_H(filter->sduVcanFilterH) | CANXL_RXFIFO_VAFLT_VCANa_L(filter->sduVcanFilterL);
	}
	else
	{
		base->VAFLT[filtIdx>>2U] |= CANXL_RXFIFO_VAFLT_VCANb_H(filter->sduVcanFilterH) | CANXL_RXFIFO_VAFLT_VCANb_L(filter->sduVcanFilterL);
	}
}

/** @} */

