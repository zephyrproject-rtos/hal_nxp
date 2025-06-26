/*
 * Copyright 2021-2025 NXP
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
#include "SchM_Can_43_CANEXCEL.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANEXCEL_IP_HWACCESS_VENDOR_ID_C                      43
#define CANEXCEL_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C       4
#define CANEXCEL_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C       7
#define CANEXCEL_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_C    0
#define CANEXCEL_IP_HWACCESS_SW_MAJOR_VERSION_C               2
#define CANEXCEL_IP_HWACCESS_SW_MINOR_VERSION_C               0
#define CANEXCEL_IP_HWACCESS_SW_PATCH_VERSION_C               1
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CanEXCEL_Ip_HwAccess.h are of the same vendor */
#if (CANEXCEL_IP_HWACCESS_VENDOR_ID_C != CANEXCEL_IP_HWACCESS_VENDOR_ID_H)
    #error "CanEXCEL_Ip_HwAccess.c and CanEXCEL_Ip_HwAccess.h have different vendor ids"
#endif
/* Check if current file and CanEXCEL_Ip_HwAccess.h are of the same Autosar version */
#if ((CANEXCEL_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C    != CANEXCEL_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_H) || \
     (CANEXCEL_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C    != CANEXCEL_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_H) || \
     (CANEXCEL_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_C != CANEXCEL_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_H) \
)
    #error "AutoSar Version Numbers of CanEXCEL_Ip_HwAccess.c and CanEXCEL_Ip_HwAccess.h are different"
#endif
/* Check if current file and CanEXCEL_Ip_HwAccess.h are of the same Software version */
#if ((CANEXCEL_IP_HWACCESS_SW_MAJOR_VERSION_C != CANEXCEL_IP_HWACCESS_SW_MAJOR_VERSION_H) || \
     (CANEXCEL_IP_HWACCESS_SW_MINOR_VERSION_C != CANEXCEL_IP_HWACCESS_SW_MINOR_VERSION_H) || \
     (CANEXCEL_IP_HWACCESS_SW_PATCH_VERSION_C != CANEXCEL_IP_HWACCESS_SW_PATCH_VERSION_H) \
)
    #error "Software Version Numbers of CanEXCEL_Ip_HwAccess.c and CanEXCEL_Ip_HwAccess.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and SchM_Can_43_CANEXCEL.h header file are of the same version */
    #if ((CANEXCEL_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C    !=  SCHM_CAN_43_CANEXCEL_AR_RELEASE_MAJOR_VERSION) || \
        (CANEXCEL_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C     !=  SCHM_CAN_43_CANEXCEL_AR_RELEASE_MINOR_VERSION) \
)
        #error "AUTOSAR Version Numbers of CanEXCEL_Ip_HwAccess.c and SchM_Can_43_CANEXCEL.h are different"
    #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* CAN FD extended data length DLC encoding */
#define CANXL_IP_DLC_VALUE_12_BYTES              9U
#define CANXL_IP_DLC_VALUE_16_BYTES              10U
#define CANXL_IP_DLC_VALUE_20_BYTES              11U
#define CANXL_IP_DLC_VALUE_24_BYTES              12U
#define CANXL_IP_DLC_VALUE_32_BYTES              13U
#define CANXL_IP_DLC_VALUE_48_BYTES              14U
#define CANXL_IP_DLC_VALUE_64_BYTES              15U

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define CAN_43_CANEXCEL_START_SEC_CODE
#include "Can_43_CANEXCEL_MemMap.h"

/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_SetMDQueueConfigs
 * Description   : Sets the Message Descriptors Queue Depth and Watermark Level
 *
 *END**************************************************************************/
void CanXL_SetMDQueueConfigs(CANXL_GRP_CONTROL_Type * base, const Canexcel_Ip_QueueConf * pConfigs)
{
    uint8 i,j=0U;
    for (i=0U;i < CANXL_GRP_CONTROL_FIFOCTRLREQ_COUNT; i++)
    {
        base->FIFOCTRL[i] = CANXL_GRP_CONTROL_FIFOCTRL_FIFODPH1(pConfigs[j].mdQueueDepth) | CANXL_GRP_CONTROL_FIFOCTRL_FIFODPH2(pConfigs[j+1u].mdQueueDepth) |
                            CANXL_GRP_CONTROL_FIFOCTRL_FIFOWTM1(pConfigs[j].mdQueueWatermark) | CANXL_GRP_CONTROL_FIFOCTRL_FIFOWTM2(pConfigs[j+1u].mdQueueWatermark);
        j=j+2u;
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_GetMDQueueDepth
 * Description   : Get the Message Descriptor Queue Depth
 *
 *END**************************************************************************/
uint8 CanXL_GetMDQueueDepth(const CANXL_GRP_CONTROL_Type * base,const uint8 MDindex)
{
    uint8 retValue = 0;
    /* Devide MDIndex to 32U in order to determine the group of the register */
    if (0U == ((MDindex >> 4U) % 2U))
    {
        retValue = (uint8)(base->FIFOCTRL[MDindex>>5U]&CANXL_GRP_CONTROL_FIFOCTRL_FIFODPH1_MASK);
    }
    else
    {
        retValue = (uint8)((base->FIFOCTRL[MDindex>>5U]&CANXL_GRP_CONTROL_FIFOCTRL_FIFODPH2_MASK)>>CANXL_GRP_CONTROL_FIFOCTRL_FIFODPH2_SHIFT);
    }
    return retValue;
}
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
    SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_06();
    if (enable)
    {
        base->SYSIE |= temp;
    }
    else
    {
        base->SYSIE &= (~temp);
    }
    SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_06();
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
                                           CANXL_IP_DLC_VALUE_12_BYTES, CANXL_IP_DLC_VALUE_12_BYTES, CANXL_IP_DLC_VALUE_12_BYTES, CANXL_IP_DLC_VALUE_12_BYTES,
                                           /* 13 to 16 payload have DLC Code 16 Bytes */
                                           CANXL_IP_DLC_VALUE_16_BYTES, CANXL_IP_DLC_VALUE_16_BYTES, CANXL_IP_DLC_VALUE_16_BYTES, CANXL_IP_DLC_VALUE_16_BYTES,
                                           /* 17 to 20 payload have DLC Code 20 Bytes */
                                           CANXL_IP_DLC_VALUE_20_BYTES, CANXL_IP_DLC_VALUE_20_BYTES, CANXL_IP_DLC_VALUE_20_BYTES, CANXL_IP_DLC_VALUE_20_BYTES,
                                           /* 21 to 24 payload have DLC Code 24 Bytes */
                                           CANXL_IP_DLC_VALUE_24_BYTES, CANXL_IP_DLC_VALUE_24_BYTES, CANXL_IP_DLC_VALUE_24_BYTES, CANXL_IP_DLC_VALUE_24_BYTES,
                                           /* 25 to 32 payload have DLC Code 32 Bytes */
                                           CANXL_IP_DLC_VALUE_32_BYTES, CANXL_IP_DLC_VALUE_32_BYTES, CANXL_IP_DLC_VALUE_32_BYTES, CANXL_IP_DLC_VALUE_32_BYTES,
                                           CANXL_IP_DLC_VALUE_32_BYTES, CANXL_IP_DLC_VALUE_32_BYTES, CANXL_IP_DLC_VALUE_32_BYTES, CANXL_IP_DLC_VALUE_32_BYTES,
                                           /* 33 to 48 payload have DLC Code 48 Bytes */
                                           CANXL_IP_DLC_VALUE_48_BYTES, CANXL_IP_DLC_VALUE_48_BYTES, CANXL_IP_DLC_VALUE_48_BYTES, CANXL_IP_DLC_VALUE_48_BYTES,
                                           CANXL_IP_DLC_VALUE_48_BYTES, CANXL_IP_DLC_VALUE_48_BYTES, CANXL_IP_DLC_VALUE_48_BYTES, CANXL_IP_DLC_VALUE_48_BYTES,
                                           CANXL_IP_DLC_VALUE_48_BYTES, CANXL_IP_DLC_VALUE_48_BYTES, CANXL_IP_DLC_VALUE_48_BYTES, CANXL_IP_DLC_VALUE_48_BYTES,
                                           CANXL_IP_DLC_VALUE_48_BYTES, CANXL_IP_DLC_VALUE_48_BYTES, CANXL_IP_DLC_VALUE_48_BYTES, CANXL_IP_DLC_VALUE_48_BYTES,
                                           /* 49 to 64 payload have DLC Code 64 Bytes */
                                           CANXL_IP_DLC_VALUE_64_BYTES, CANXL_IP_DLC_VALUE_64_BYTES, CANXL_IP_DLC_VALUE_64_BYTES, CANXL_IP_DLC_VALUE_64_BYTES,
                                           CANXL_IP_DLC_VALUE_64_BYTES, CANXL_IP_DLC_VALUE_64_BYTES, CANXL_IP_DLC_VALUE_64_BYTES, CANXL_IP_DLC_VALUE_64_BYTES,
                                           CANXL_IP_DLC_VALUE_64_BYTES, CANXL_IP_DLC_VALUE_64_BYTES, CANXL_IP_DLC_VALUE_64_BYTES, CANXL_IP_DLC_VALUE_64_BYTES,
                                           CANXL_IP_DLC_VALUE_64_BYTES, CANXL_IP_DLC_VALUE_64_BYTES, CANXL_IP_DLC_VALUE_64_BYTES, CANXL_IP_DLC_VALUE_64_BYTES
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
/*FUNCTION**********************************************************************
 *
 * Function Name: CAN_ComputePayloadSizeHw
 * Description  : Computes the a payload size (in bytes), given a DLC field value.
 * This is used for Classical and FD Frame types.
 *END**************************************************************************/
static uint8 CAN_ComputePayloadSizeHw(uint8 dlcValue)
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
            case CANXL_IP_DLC_VALUE_12_BYTES:
                ret = 12U;
                break;
            case CANXL_IP_DLC_VALUE_16_BYTES:
                ret = 16U;
                break;
            case CANXL_IP_DLC_VALUE_20_BYTES:
                ret = 20U;
                break;
            case CANXL_IP_DLC_VALUE_24_BYTES:
                ret = 24U;
                break;
            case CANXL_IP_DLC_VALUE_32_BYTES:
                ret = 32U;
                break;
            case CANXL_IP_DLC_VALUE_48_BYTES:
                ret = 48U;
                break;
            case CANXL_IP_DLC_VALUE_64_BYTES:
                ret = 64U;
                break;
            default:
                /* The argument is not a valid DLC size */
                break;
        }
    }
    return ret;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_SoftReset
 * Description   : Execute a SoftReset of the CANEXCEL Hw
 *
 *END**************************************************************************/
Canexcel_Ip_StatusType CanXL_SoftReset(CANXL_SIC_Type * base)
{
    uint32 timeStart = 0U;
    uint32 timeElapsed = 0U;
    Canexcel_Ip_StatusType returnResult = CANEXCEL_STATUS_SUCCESS;
    uint32 uS2Ticks = OsIf_MicrosToTicks(CANEXCEL_IP_TIMEOUT_DURATION, CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
    base->SYSMC = CANXL_SIC_SYSMC_SOFRST_MASK;
    timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
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
void CanXL_ClearRAM(const CANEXCEL_StructType * CANXL, uint8 instance)
{
   uint16 idx;
   CANXL_MSG_DESCRIPTORS_Type * base_Msg_Desc = CANXL->EXL_MSGD[instance];
   for (idx=0u; idx < CANXL_MSG_DESCRIPTORS_MSGDSC_COUNT; idx++)
   {
#if   (CANEXCEL_IP_FEATURE_HAS_MSGDESC_RXCTRL_MODE == (STD_ON))
       /* Set as Invalid Config Rx Msg Descriptor */
       base_Msg_Desc->MSGDSC[idx].CTRL.RXCTRL = CANXL_MSG_DESCRIPTORS_RXCTRL_MODE_MASK;
#endif
       base_Msg_Desc->MSGDSC[idx].CFG1.MDFLT1FD = 0U;
       base_Msg_Desc->MSGDSC[idx].CFG2.MDFLT2FD = 0U;
       base_Msg_Desc->MSGDSC[idx].LSTPNT.RXLSTPTR = 0U;
       for (uint8 i=0;i<16u;i++)
       {
           /* Initialize the msg descriptor reserved space */
           base_Msg_Desc->MSGDSC[idx].RESERVED_0[i] = 0U;
       }
   }
   /* Clear the filter bank check the size in device reg as CANXL_IP_FILTER_BANK_SIZE */
   volatile uint32 * ptr = (volatile uint32 *)&CANXL->EXL_FILTER[instance]->AFCFG0;
   for (idx = 0u; idx <= (uint16)(CANXL_IP_FILTER_BANK_SIZE/4U); idx++)
   {
       ptr[idx] = 0U;
   }
   /* Clear and initilize RXFIFO memory */
   CANXL_RXFIFO_Type * base_RxFifo = CANXL->EXL_RXFIFO[instance];
   base_RxFifo->RXFFCTR = 0U;
   for (idx = 0u; idx < CANXL_RXFIFO_RXFFPOINTERAR_COUNT; idx++)
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
   for (idx = 0u; idx < CANXL_RXFIFO_VCANACPTFLTAR_COUNT; idx++)
   {
       base_RxFifo->VAFLT[idx] = 0U;
   }
   for (idx = 0u; idx < CANXL_RXFIFO_SDUACPTFLTAR_COUNT; idx++)
   {
       base_RxFifo->SAFLT[idx] = 0U;
   }
   for (idx = 0u; idx < CANXL_RXFIFO_ADDRACPTFLTAR_COUNT; idx++)
   {
       base_RxFifo->ADDRACPTFLTAR[idx].AAFLTL = 0U;
       base_RxFifo->ADDRACPTFLTAR[idx].AAFLTH = 0U;
   }
   for (idx = 0u; idx < CANXL_RXFIFO_IDACPTFLTAR_COUNT; idx++)
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
    if ((CANXL_SIC_SYSS_FRZACKF_MASK == (base->SYSS & CANXL_SIC_SYSS_FRZACKF_MASK)) && (0U == (base->SYSMC & CANXL_SIC_SYSMC_FRZREQ_MASK)))
    {
        if (((base->SYSS & CANXL_SIC_SYSS_LPMACKF_MASK) != 0U) && (CANXL_SIC_SYSMC_LPMREQ_MASK == (base->SYSMC & CANXL_SIC_SYSMC_LPMREQ_MASK)))
        {
            lowPower = TRUE;
            /* Exit low Power Mode to allow Freeze Enter Mode */
            base->SYSS = CANXL_SIC_SYSS_LPMACKF_MASK;
            SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_01();
            base->SYSMC &= ~CANXL_SIC_SYSMC_LPMREQ_MASK;
            SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_01();
            timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
            while (0U == (base->SYSS & CANXL_SIC_SYSS_LPMACKF_MASK))
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
        base->SYSS = CANXL_SIC_SYSS_FRZACKF_MASK;
        SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_01();
        base->SYSMC |= CANXL_SIC_SYSMC_FRZREQ_MASK;
        SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_01();
    }
    if (CANEXCEL_STATUS_SUCCESS == returnResult)
    {
        timeElapsed = 0U;
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

    if ((CANEXCEL_STATUS_SUCCESS == returnResult) && (TRUE == lowPower))
    {
        base->SYSS = CANXL_SIC_SYSS_LPMACKF_MASK;
        SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_01();
        base->SYSMC |= CANXL_SIC_SYSMC_LPMREQ_MASK;
        SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_01();
        timeElapsed = 0U;
        timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
        while (0U == (base->SYSS & CANXL_SIC_SYSS_LPMACKF_MASK))
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
    if ((base->SYSS & CANXL_SIC_SYSS_FRZACKF_MASK) != 0U)
    {
        if ((base->SYSS & CANXL_SIC_SYSS_LPMACKF_MASK) == CANXL_SIC_SYSS_LPMACKF_MASK)
        {
            lowPower = TRUE;
            base->SYSS = CANXL_SIC_SYSS_LPMACKF_MASK;
            /* Exit low Power Mode to allow Freeze Exit Mode */
            SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_02();
            base->SYSMC &= ~CANXL_SIC_SYSMC_LPMREQ_MASK;
            SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_02();
            timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
            while (0U == (base->SYSS & CANXL_SIC_SYSS_LPMACKF_MASK))
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
    if (CANEXCEL_STATUS_SUCCESS == returnResult)
    {
        base->SYSS = CANXL_SIC_SYSS_FRZACKF_MASK;
        /* Request exit Freeze Mode */
        SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_02();
        base->SYSMC &= ~CANXL_SIC_SYSMC_FRZREQ_MASK;
        SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_02();
        timeElapsed = 0U;
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
    if ((CANEXCEL_STATUS_SUCCESS == returnResult) && (TRUE == lowPower))
    {
        base->SYSS = CANXL_SIC_SYSS_LPMACKF_MASK;
        SchM_Enter_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_02();
        base->SYSMC |= CANXL_SIC_SYSMC_LPMREQ_MASK;
        SchM_Exit_Can_43_CANEXCEL_CAN_EXCLUSIVE_AREA_02();
        timeElapsed = 0U;
        timeStart = OsIf_GetCounter(CANEXCEL_IP_SERVICE_TIMEOUT_TYPE);
        while (0U == (base->SYSS & CANXL_SIC_SYSS_LPMACKF_MASK))
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
 * Function Name : CanXL_GetDescControlStatus
 * Description   : Returns the Contol Lock status for Message Descriptor
 *END**************************************************************************/
Canexcel_Ip_DesCntStatus CanXL_GetDescControlStatus(const CANXL_DSC_CONTROL_Type * base, uint8 descNo)
{
    Canexcel_Ip_DesCntStatus status = CANEXCEL_DESCNTSTATUS_INVALID;
    switch ((base->DSCMBCTRLAR[descNo].DCSTA & (CANXL_DSC_CONTROL_DCSTA_HWLOCK_MASK | CANXL_DSC_CONTROL_DCSTA_SYSLOCK_MASK))>>CANXL_DSC_CONTROL_DCSTA_HWLOCK_SHIFT)
    {
        case 0U:
            status = CANEXCEL_DESCNTSTATUS_UNLOCKED;
            break;
        case 1U:
            status = CANEXCEL_DESCNTSTATUS_LOCKED_HW;
            break;
        case 2U:
            status = CANEXCEL_DESCNTSTATUS_LOCKED_SYS;
            break;
        default:
            status = CANEXCEL_DESCNTSTATUS_INVALID;
            break;
    }
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_SetOperationMode
 * Description   : Enable a CanEXCEL operation mode.
 * This function will enable one of the modes listed in Canexcel_Ip_ModesType.
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

/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_DeserializeRevUint32
 * Description   : Combine the user's data into a word
 *END**************************************************************************/
static inline uint32 CanXL_DeserializeRevUint32(const uint8 * Buffer)
{
    uint32 value = 0;
    /* the endianness type for the payload is litle-endian */
    value |= (uint32)Buffer[3] << 24U;
    value |= (uint32)Buffer[2] << 16U;
    value |= (uint32)Buffer[1] << 8U;
    value |= (uint32)Buffer[0];

    return value;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_SetTxMsgBuffData
 * Description   : Copy the data in the Tx Message Buffer location, based on the frame length
 *END**************************************************************************/
void CanXL_SetTxMsgBuffData(const Canexcel_Ip_DataInfoType * info, const uint8 * data, uint8 * MB)
{
    volatile uint32 * Mb_Data_32 = (volatile uint32 *)MB;
    const uint32 * MsgData_32 = (const uint32*)data;
    uint16 idx;
    
    /* Check if the buffer address is word aligned */
    if (((uint32)MsgData_32 & 0x3U) != 0U)
    {
        for (idx = 0u; idx< (info->dataLength & ~3U); idx +=4u)
        {
            Mb_Data_32[idx >> 2U] = CanXL_DeserializeRevUint32(&data[idx]);
        }
    }
    else
    {
        for (idx = 0u; idx< (info->dataLength & ~3U); idx +=4u)
        {
            * Mb_Data_32 = * MsgData_32;
            Mb_Data_32++;
            MsgData_32++;
        }
    }
    
    for (; idx < info->dataLength; idx++)
    {
        MB[idx] =  data[idx];
    }

    if (CANEXCEL_FD_FRAME == info->frame)
    {
        uint8 dlcValue = CAN_ComputeDLCValue((uint8)(info->dataLength));
        uint8 calcValue = CAN_ComputePayloadSizeHw(dlcValue);
        for (idx = info->dataLength; idx<calcValue; idx++)
        {
            MB[idx] = info->fd_padding;
        }
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_EnableInterrupts
 * Description   : Enable configured Interrupts for CanExcel controller
 *END**************************************************************************/
void CanXL_EnableInterrupts(CANXL_SIC_Type * base)
{
    base->SYSMDHICFG = CANXL_SIC_SYSMDHICFG_TXDCFGHI0_0_MASK | CANXL_SIC_SYSMDHICFG_TXDCFGHI0_1_MASK | CANXL_SIC_SYSMDHICFG_TXDCFGHI0_2_MASK | CANXL_SIC_SYSMDHICFG_TXDCFGHI0_3_MASK |
                       CANXL_SIC_SYSMDHICFG_RXDCFGHI0_0_MASK | CANXL_SIC_SYSMDHICFG_RXDCFGHI0_1_MASK | CANXL_SIC_SYSMDHICFG_RXDCFGHI0_2_MASK | CANXL_SIC_SYSMDHICFG_RXDCFGHI0_3_MASK;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_DisableInterrupts
 * Description   : Disable configured Interrupts for CanExcel controller
 *END**************************************************************************/
void CanXL_DisableInterrupts(CANXL_SIC_Type * base)
{
    base->SYSMDHICFG = 0U;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_ResetImaskBuff (uses in Canexcel_Ip_Init function only)
 * Description   : Reset Imask Buffers.
 *
 *END**************************************************************************/
void CanXL_ResetImaskBuff(CANXL_GRP_CONTROL_Type * base)
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
    if (((base->BCFG2 & CANXL_SIC_BCFG2_XLEN_MASK) != 0U) && ((u32Options & CANXL_IP_PROTOCOL_EXCEPTION_U32) != 0U))
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
        base->BCFG2 &= (~CANXL_SIC_BCFG2_EDFLTDIS_MASK);
    }
    else
    {
        /* 1b - Edge Filter is disabled */
        base->BCFG2 |= CANXL_SIC_BCFG2_EDFLTDIS_MASK;
    }

    if ((u32Options & CANXL_IP_XLER_U32) != 0U)
    {
        base->BCFG2 |= CANXL_SIC_BCFG2_XLER_MASK;
    }
    else
    {
        base->BCFG2 &= (~CANXL_SIC_BCFG2_XLER_MASK);
    }
    return status;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_ConfigAccAddr
 * Description   : Config the Acceptance Address Filter for RxFIFO
 *END**************************************************************************/
void CanXL_ConfigAccAddr(CANXL_RXFIFO_Type * base,const Canexcel_Ip_RxFifoFilterID_ADDR * filter, uint8 filtIdx)
{
    uint32 mask = 1UL << (filtIdx%32U);
    if (CANEXCEL_IP_RX_FIFO_RANGE_FILTER == filter->filterType)
    {
        /* Enable Range Filter operation */
        base->AAMRCFG |= mask;
    }
    else
    {    /* Enable Mask Filter operation */
        base->AAMRCFG &= (~mask);
    }
    base->ADDRACPTFLTAR[filtIdx].AAFLTH = filter->idAddrFilterH;
    base->ADDRACPTFLTAR[filtIdx].AAFLTL = filter->idAddrFilterL;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_ConfigIDFilter
 * Description   : Config the ID Filter for RxFIFO
 *END**************************************************************************/
void CanXL_ConfigIDFilter(CANXL_RXFIFO_Type * base,const Canexcel_Ip_RxFifoFilterID_ADDR * filter, uint8 filtIdx)
{
    uint32 mask = 1UL << (filtIdx%32U);
    if (CANEXCEL_IP_RX_FIFO_RANGE_FILTER == filter->filterType)
    {
        /* Enable Range Filter operation */
        base->ACPTIDMR |= mask;
    }
    else
    {    /* Enable Mask Filter operation */
        base->ACPTIDMR &= (~mask);
    }
    base->IDACPTFLTAR[filtIdx].IDAFLTH = filter->idAddrFilterH;
    base->IDACPTFLTAR[filtIdx].IDAFLTL = filter->idAddrFilterL;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_ConfigSDUFilter
 * Description   : Config the SDU Filter for RxFIFO
 *END**************************************************************************/
void CanXL_ConfigSDUFilter(CANXL_RXFIFO_Type * base,const Canexcel_Ip_RxFifoFilterSDU_CAN * filter, uint8 filtIdx)
{
    uint32 mask = 1UL << (filtIdx%32U);
    if (CANEXCEL_IP_RX_FIFO_RANGE_FILTER == filter->filterType)
    {
        /* Enable Range Filter operation */
        base->SAMRCFG |= mask;
    }
    else
    {    /* Enable Mask Filter operation */
        base->SAMRCFG &= (~mask);
    }
    /* Div the register selection to 2, this register is composed form a pair of SDU filter */
    base->SAFLT[filtIdx>>2U] = 0U;
    if (0U == (filtIdx % 2U))
    {
        base->SAFLT[filtIdx>>1U] |= CANXL_RXFIFO_SAFLT_SDUa_H(filter->sduVcanFilterH) | CANXL_RXFIFO_SAFLT_SDUa_L(filter->sduVcanFilterL);
    }
    else
    {
        base->SAFLT[filtIdx>>1U] |= CANXL_RXFIFO_SAFLT_SDUb_H(filter->sduVcanFilterH) | CANXL_RXFIFO_SAFLT_SDUb_L(filter->sduVcanFilterL);
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_ConfigVCANFilter
 * Description   : Config the VCAN Filter for RxFIFO
 *END**************************************************************************/
void CanXL_ConfigVCANFilter(CANXL_RXFIFO_Type * base,const Canexcel_Ip_RxFifoFilterSDU_CAN * filter, uint8 filtIdx)
{
    uint32 mask = 1UL << (filtIdx%32U);
    if (CANEXCEL_IP_RX_FIFO_RANGE_FILTER == filter->filterType)
    {
        /* Enable Range Filter operation */
        base->VAMRCFG |= mask;
    }
    else
    {    /* Enable Mask Filter operation */
        base->VAMRCFG &= (~mask);
    }
    /* Div the register selection to 2, this register is composed form a pair of SDU filter */
    base->VAFLT[filtIdx>>2U] = 0U;
    if (0U == (filtIdx % 2U))
    {
        base->VAFLT[filtIdx>>1U] |= CANXL_RXFIFO_VAFLT_VCANa_H(filter->sduVcanFilterH) | CANXL_RXFIFO_VAFLT_VCANa_L(filter->sduVcanFilterL);
    }
    else
    {
        base->VAFLT[filtIdx>>1U] |= CANXL_RXFIFO_VAFLT_VCANb_H(filter->sduVcanFilterH) | CANXL_RXFIFO_VAFLT_VCANb_L(filter->sduVcanFilterL);
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_ConfigAccAddrFilterBank
 * Description   : Config the Acceptance Address Filter as Accept for MessageDescriptor in FilterBanks
 *END**************************************************************************/
void CanXL_ConfigAccAddrFilterBank(CANXL_FILTER_BANK_Type * base, uint8 bank,const Canexcel_Ip_RxFifoFilterID_ADDR * filter, uint8 filtIdx)
{
    uint32 mask = 1UL << (filtIdx%32U);
    typedef struct {
        uint32 AAFLTx_L;
        uint32 AAFLTx_H;
    } AddrFilterAAType;
    if (0U == bank)
    {
        /* MISRA Rule 11.3: When detected for casting integer pointers to integer pointers of different size: This operation is allowed, as it does not lead to incompatible alignment. */
        volatile AddrFilterAAType * FilterStr = (volatile AddrFilterAAType *)&base->AAFLT0_0L;
        if (CANEXCEL_IP_RX_FIFO_RANGE_FILTER == filter->filterType)
        {
            /* Enable Range Filter operation */
            base->AAMRCFG0 |= mask;
        }
        else
        {    /* Enable Mask Filter operation */
            base->AAMRCFG0 &= (~mask);
        }
        FilterStr[filtIdx].AAFLTx_L = filter->idAddrFilterL;
        FilterStr[filtIdx].AAFLTx_H = filter->idAddrFilterH;
    }
    else
    {
        volatile AddrFilterAAType * FilterStr = (volatile AddrFilterAAType *)&base->AAFLT1_0L;
        if (CANEXCEL_IP_RX_FIFO_RANGE_FILTER == filter->filterType)
        {
            /* Enable Range Filter operation */
            base->AAMRCFG1 |= mask;
        }
        else
        {    /* Enable Mask Filter operation */
            base->AAMRCFG1 &= (~mask);
        }
        FilterStr[filtIdx].AAFLTx_L = filter->idAddrFilterL;
        FilterStr[filtIdx].AAFLTx_H = filter->idAddrFilterH;
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_ConfigAccAddrRejectBank
 * Description   : Config the Acceptance Address Filter as Reject for MessageDescriptor in FilterBanks
 *END**************************************************************************/
void CanXL_ConfigAccAddrRejectBank(CANXL_FILTER_BANK_Type * base, uint8 bank,const Canexcel_Ip_RxFifoFilterID_ADDR * filter, uint8 filtIdx)
{
    uint32 mask = 1UL << (filtIdx%32U);
    typedef struct {
        uint32 ARFLTx_L;
        uint32 ARFLTx_H;
    } AddrFilterType;
    if (0U == bank)
    {
        volatile AddrFilterType * FilterStr = (volatile AddrFilterType *)&base->ARFLT0_0L;
        if (CANEXCEL_IP_RX_FIFO_RANGE_FILTER == filter->filterType)
        {
            /* Enable Range Filter operation */
            base->ARMRCFG0 |= mask;
        }
        else
        {    /* Enable Mask Filter operation */
            base->ARMRCFG0 &= (~mask);
        }
        FilterStr[filtIdx].ARFLTx_L = filter->idAddrFilterL;
        FilterStr[filtIdx].ARFLTx_H = filter->idAddrFilterH;
    }
    else
    {
        volatile AddrFilterType * FilterStr = (volatile AddrFilterType *)&base->ARFLT1_0L;
        if (CANEXCEL_IP_RX_FIFO_RANGE_FILTER == filter->filterType)
        {
            /* Enable Range Filter operation */
            base->ARMRCFG1 |= mask;
        }
        else
        {    /* Enable Mask Filter operation */
            base->ARMRCFG1 &= (~mask);
        }
        FilterStr[filtIdx].ARFLTx_L = filter->idAddrFilterL;
        FilterStr[filtIdx].ARFLTx_H = filter->idAddrFilterH;
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_ConfigSDUFilterBank
 * Description   : Config the SDU Filter as Accept for MessageDescriptor in FilterBanks
 *END**************************************************************************/
void CanXL_ConfigSDUFilterBank(CANXL_FILTER_BANK_Type * base, uint8 bank,const Canexcel_Ip_RxFifoFilterSDU_CAN * filter, uint8 filtIdx)
{
    uint32 mask = 1UL << (filtIdx%32U);
    if (0U == bank)
    {
        if (CANEXCEL_IP_RX_FIFO_RANGE_FILTER == filter->filterType)
        {
            /* Enable Range Filter operation */
            base->SAMRCFG0 |= mask;
        }
        else
        {    /* Enable Mask Filter operation */
            base->SAMRCFG0 &= (~mask);
        }
        /* Div the register selection to 2, this register is composed form a pair of SDU filter */
        volatile uint32 * SAFLT = (volatile uint32 *)&base->SAFLT0_0;
        if (0U == (filtIdx % 2U))
        {
            SAFLT[filtIdx>>1U] |= CANXL_FILTER_BANK_SAFLT0_0_SDUa_H(filter->sduVcanFilterH) | CANXL_FILTER_BANK_SAFLT0_0_SDUa_L(filter->sduVcanFilterL);
        }
        else
        {
            SAFLT[filtIdx>>1U] |= CANXL_FILTER_BANK_SAFLT0_0_SDUb_H(filter->sduVcanFilterH) | CANXL_FILTER_BANK_SAFLT0_0_SDUb_L(filter->sduVcanFilterL);
        }
    }
    else
    {
        if (CANEXCEL_IP_RX_FIFO_RANGE_FILTER == filter->filterType)
        {
            /* Enable Range Filter operation */
            base->SAMRCFG1 |= mask;
        }
        else
        {    /* Enable Mask Filter operation */
            base->SAMRCFG1 &= (~mask);
        }
        /* Div the register selection to 2, this register is composed form a pair of SDU filter */
        volatile uint32 * SAFLT = (volatile uint32 *)&base->SAFLT1_0;
        if (0U == (filtIdx % 2U))
        {
            SAFLT[filtIdx>>1U] |= CANXL_FILTER_BANK_SAFLT1_0_SDUa_H(filter->sduVcanFilterH) | CANXL_FILTER_BANK_SAFLT1_0_SDUa_L(filter->sduVcanFilterL);
        }
        else
        {
            SAFLT[filtIdx>>1U] |= CANXL_FILTER_BANK_SAFLT1_0_SDUb_H(filter->sduVcanFilterH) | CANXL_FILTER_BANK_SAFLT1_0_SDUb_L(filter->sduVcanFilterL);
        }
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_ConfigSDURejectBank
 * Description   : Config the SDU Filter as Reject for MessageDescriptor in FilterBanks
 *END**************************************************************************/
void CanXL_ConfigSDURejectBank(CANXL_FILTER_BANK_Type * base, uint8 bank,const Canexcel_Ip_RxFifoFilterSDU_CAN * filter, uint8 filtIdx)
{
    uint32 mask = 1UL << (filtIdx%32U);
    if (0U == bank)
    {
        if (CANEXCEL_IP_RX_FIFO_RANGE_FILTER == filter->filterType)
        {
            /* Enable Range Filter operation */
            base->SRMRCFG0 |= mask;
        }
        else
        {    /* Enable Mask Filter operation */
            base->SRMRCFG0 &= (~mask);
        }
        /* Div the register selection to 2, this register is composed form a pair of SDU filter */
        volatile uint32 * SRFLT = (volatile uint32 *)&base->SRFLT0_0;
        if (0U == (filtIdx % 2U))
        {
            SRFLT[filtIdx>>1U] |= CANXL_FILTER_BANK_SRFLT0_0_SDUa_H(filter->sduVcanFilterH) | CANXL_FILTER_BANK_SRFLT0_0_SDUa_L(filter->sduVcanFilterL);
        }
        else
        {
            SRFLT[filtIdx>>1U] |= CANXL_FILTER_BANK_SRFLT0_0_SDUb_H(filter->sduVcanFilterH) | CANXL_FILTER_BANK_SRFLT0_0_SDUb_L(filter->sduVcanFilterL);
        }
    }
    else
    {
        if (CANEXCEL_IP_RX_FIFO_RANGE_FILTER == filter->filterType)
        {
            /* Enable Range Filter operation */
            base->SRMRCFG1 |= mask;
        }
        else
        {    /* Enable Mask Filter operation */
            base->SRMRCFG1 &= (~mask);
        }
        /* Div the register selection to 2, this register is composed form a pair of SDU filter */
        volatile uint32 * SRFLT = (volatile uint32 *)&base->SRFLT1_0;
        if (0U == (filtIdx % 2U))
        {
            SRFLT[filtIdx>>1U] |= CANXL_FILTER_BANK_SRFLT1_0_SDUa_H(filter->sduVcanFilterH) | CANXL_FILTER_BANK_SRFLT1_0_SDUa_L(filter->sduVcanFilterL);
        }
        else
        {
            SRFLT[filtIdx>>1U] |= CANXL_FILTER_BANK_SRFLT1_0_SDUb_H(filter->sduVcanFilterH) | CANXL_FILTER_BANK_SRFLT1_0_SDUb_L(filter->sduVcanFilterL);
        }
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_ConfigVCANFilterBank
 * Description   : Config the VCAN Filter as Accept for MessageDescriptor in FilterBanks
 *END**************************************************************************/
void CanXL_ConfigVCANFilterBank(CANXL_FILTER_BANK_Type * base, uint8 bank,const Canexcel_Ip_RxFifoFilterSDU_CAN * filter, uint8 filtIdx)
{
    uint32 mask = 1UL << (filtIdx%32U);
    if (0U == bank)
    {
        if (CANEXCEL_IP_RX_FIFO_RANGE_FILTER == filter->filterType)
        {
            /* Enable Range Filter operation */
            base->VAMRCFG0 |= mask;
        }
        else
        {    /* Enable Mask Filter operation */
            base->VAMRCFG0 &= (~mask);
        }
        /* Div the register selection to 2, this register is composed form a pair of SDU filter */
        volatile uint32 * VAFLT = (volatile uint32 *)&base->VAFLT0_0;
        if (0U == (filtIdx % 2U))
        {
            VAFLT[filtIdx>>1U] |= CANXL_FILTER_BANK_VAFLT0_0_VCANa_H(filter->sduVcanFilterH) | CANXL_FILTER_BANK_VAFLT0_0_VCANa_L(filter->sduVcanFilterL);
        }
        else
        {
            VAFLT[filtIdx>>1U] |= CANXL_FILTER_BANK_VAFLT0_0_VCANb_H(filter->sduVcanFilterH) | CANXL_FILTER_BANK_VAFLT0_0_VCANb_L(filter->sduVcanFilterL);
        }
    }
    else
    {
        if (CANEXCEL_IP_RX_FIFO_RANGE_FILTER == filter->filterType)
        {
            /* Enable Range Filter operation */
            base->VAMRCFG1 |= mask;
        }
        else
        {    /* Enable Mask Filter operation */
            base->VAMRCFG1 &= (~mask);
        }
        /* Div the register selection to 2, this register is composed form a pair of SDU filter */
        volatile uint32 * VAFLT = (volatile uint32 *)&base->VAFLT1_0;
        if (0U == (filtIdx % 2U))
        {
            VAFLT[filtIdx>>1U] |= CANXL_FILTER_BANK_VAFLT1_0_VCANa_H(filter->sduVcanFilterH) | CANXL_FILTER_BANK_VAFLT1_0_VCANa_L(filter->sduVcanFilterL);
        }
        else
        {
            VAFLT[filtIdx>>1U] |= CANXL_FILTER_BANK_VAFLT1_0_VCANb_H(filter->sduVcanFilterH) | CANXL_FILTER_BANK_VAFLT1_0_VCANb_L(filter->sduVcanFilterL);
        }
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : CanXL_ConfigVCANRejectBank
 * Description   : Config the VCAN Filter as Reject for MessageDescriptor in FilterBanks
 *END**************************************************************************/
void CanXL_ConfigVCANRejectBank(CANXL_FILTER_BANK_Type * base, uint8 bank,const Canexcel_Ip_RxFifoFilterSDU_CAN * filter, uint8 filtIdx)
{
    uint32 mask = 1UL << (filtIdx%32U);
    if (0U == bank)
    {
        if (CANEXCEL_IP_RX_FIFO_RANGE_FILTER == filter->filterType)
        {
            /* Enable Range Filter operation */
            base->VRMRCFG0 |= mask;
        }
        else
        {    /* Enable Mask Filter operation */
            base->VRMRCFG0 &= (~mask);
        }
        /* Div the register selection to 2, this register is composed form a pair of SDU filter */
        volatile uint32 * VRFLT = (volatile uint32 *)&base->VRFLT0_0;
        if (0U == (filtIdx % 2U))
        {
            VRFLT[filtIdx>>1U] |= CANXL_FILTER_BANK_VRFLT0_0_VCANa_H(filter->sduVcanFilterH) | CANXL_FILTER_BANK_VRFLT0_0_VCANa_L(filter->sduVcanFilterL);
        }
        else
        {
            VRFLT[filtIdx>>1U] |= CANXL_FILTER_BANK_VRFLT0_0_VCANb_H(filter->sduVcanFilterH) | CANXL_FILTER_BANK_VRFLT0_0_VCANb_L(filter->sduVcanFilterL);
        }
    }
    else
    {
        if (CANEXCEL_IP_RX_FIFO_RANGE_FILTER == filter->filterType)
        {
            /* Enable Range Filter operation */
            base->VRMRCFG1 |= mask;
        }
        else
        {    /* Enable Mask Filter operation */
            base->VRMRCFG1 &= (~mask);
        }
        /* Div the register selection to 2, this register is composed form a pair of SDU filter */
        volatile uint32 * VRFLT = (volatile uint32 *)&base->VRFLT1_0;
        if (0U == (filtIdx % 2U))
        {
            VRFLT[filtIdx>>1U] |= CANXL_FILTER_BANK_VRFLT1_0_VCANa_H(filter->sduVcanFilterH) | CANXL_FILTER_BANK_VRFLT1_0_VCANa_L(filter->sduVcanFilterL);
        }
        else
        {
            VRFLT[filtIdx>>1U] |= CANXL_FILTER_BANK_VRFLT1_0_VCANb_H(filter->sduVcanFilterH) | CANXL_FILTER_BANK_VRFLT1_0_VCANb_L(filter->sduVcanFilterL);
        }
    }
}

#define CAN_43_CANEXCEL_STOP_SEC_CODE
#include "Can_43_CANEXCEL_MemMap.h"

/** @} */

