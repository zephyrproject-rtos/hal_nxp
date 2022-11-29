/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file    Mru_Ip.c
*   
*
*   @brief   MRU low-level driver implementations.
*   @details MRU low-level driver implementations.
*
*   @addtogroup MRU_IP_DRIVER Mru Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Mru_Ip.h"
#if (STD_ON == MRU_IP_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MRU_IP_VENDOR_ID_C                      43
#define MRU_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define MRU_IP_AR_RELEASE_MINOR_VERSION_C       7
#define MRU_IP_AR_RELEASE_REVISION_VERSION_C    0
#define MRU_IP_SW_MAJOR_VERSION_C               0
#define MRU_IP_SW_MINOR_VERSION_C               9
#define MRU_IP_SW_PATCH_VERSION_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((MRU_IP_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (MRU_IP_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Mru_Ip.c and Mcal.h are different"
    #endif
#endif

/* Check if Mru_Ip.h and Mru_Ip.c are of the same vendor */
#if (MRU_IP_VENDOR_ID != MRU_IP_VENDOR_ID_C)
    #error "Mru_Ip.h and Mru_Ip.c have different vendor ids"
#endif
/* Check if Mru_Ip.h file and Mru_Ip.c file are of the same Autosar version */
#if ((MRU_IP_AR_RELEASE_MAJOR_VERSION != MRU_IP_AR_RELEASE_MAJOR_VERSION_C) || \
     (MRU_IP_AR_RELEASE_MINOR_VERSION != MRU_IP_AR_RELEASE_MINOR_VERSION_C) || \
     (MRU_IP_AR_RELEASE_REVISION_VERSION != MRU_IP_AR_RELEASE_REVISION_VERSION_C))
#error "AutoSar Version Numbers of Mru_Ip.h and Mru_Ip.c are different"
#endif
#if ((MRU_IP_SW_MAJOR_VERSION != MRU_IP_SW_MAJOR_VERSION_C) || \
     (MRU_IP_SW_MINOR_VERSION != MRU_IP_SW_MINOR_VERSION_C) || \
     (MRU_IP_SW_PATCH_VERSION != MRU_IP_SW_PATCH_VERSION_C))
#error "Software Version Numbers of Mru_Ip.h and Mru_Ip.c are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define MRU_IP_CH_CFG0_CHE_MASK                 (0x1U)
#define MRU_IP_CH_CFG0_IE_MASK                  (0x4U)
#define MRU_IP_CH_MBSTAT_MBS0_MASK              (0x10000U)
#define MRU_IP_CH_CFG1_MBIC0_MASK               (0x10000U)
#define MRU_IP_CH_CFG1_MBIC0_SHIFT              (16U)
#define MRU_IP_NOTIFY_CH1_IS_MASK               (0x1U)
/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/ 
/*==================================================================================================
                                    GLOBAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Platform_MemMap.h"

Mru_Ip_StateStructureType Mru_Ip_axStateStructure[MRU_IP_NUMBER_OF_INSTANCES];

Mru_Ip_StateStructureType* Mru_Ip_apxStateStructureArray[MRU_IP_NUMBER_OF_INSTANCES];

#define PLATFORM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Platform_MemMap.h"
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief   This function is called by MRU ISRs.
* @details This function will process MRU interrupts.
*
* @param[in]     InstanceId            Instance Id of the hardware unit.
* @param[in]     IntGroupId            Interrupt group Id of the hardware unit.
*
* @implementsMru_Ip_IrqHandlerReceiveMb_Activity
*/
static void Mru_Ip_IrqHandlerReceiveMb(const Mru_Ip_ChannelCfgType * ChannelConfig, uint8 IntGroupId);
/*================================================================================================*/
void Mru_Ip_Init(const Mru_Ip_ConfigType *HWUnitConfigPtr)
{
    Mru_Ip_StateStructureType* State;
    uint8 InstanceId = 0u;
    uint8 CfgIndex = 0u;

#if (MRU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != HWUnitConfigPtr);
#endif
    InstanceId = HWUnitConfigPtr->InstanceId;
    State = Mru_Ip_apxStateStructureArray[InstanceId];
#if (MRU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR == State);
#endif
    Mru_Ip_apxStateStructureArray[InstanceId] = &Mru_Ip_axStateStructure[HWUnitConfigPtr->StateIndex];
    State = Mru_Ip_apxStateStructureArray[InstanceId];
    State->HWUnitConfig = HWUnitConfigPtr;

    for(CfgIndex = 0u; CfgIndex < HWUnitConfigPtr->NumChannel; CfgIndex++)
    {
        if(NULL_PTR != HWUnitConfigPtr->ChannelCfg[CfgIndex].MBLinkReceiveChCfg)
        {
            /* Enables the channel configuration before writing to registers */
            *HWUnitConfigPtr->ChannelCfg[CfgIndex].ChCFG0Add = MRU_IP_CH_CFG0_CHE_MASK;
            /* Update channel CFG1 */
            *HWUnitConfigPtr->ChannelCfg[CfgIndex].ChCFG1Add = HWUnitConfigPtr->ChannelCfg[CfgIndex].ChCFG1;
            /* Update channel CFG0 */
            *HWUnitConfigPtr->ChannelCfg[CfgIndex].ChCFG0Add = HWUnitConfigPtr->ChannelCfg[CfgIndex].ChCFG0 | MRU_IP_CH_CFG0_CHE_MASK;
        }
    }
}
/*================================================================================================*/
Mru_Ip_StatusType Mru_Ip_Transmit( const Mru_Ip_TransmitChannelType *TransmitChCfgPtr,
                      const uint32 *TxBufferPtr
                    )
{
    uint8 BufferIndex = 0u;
    Mru_Ip_StatusType Status = MRU_IP_STATUS_SUCCESS;

#if (MRU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != TransmitChCfgPtr);
    DevAssert(NULL_PTR != TxBufferPtr);
#endif

    /* Check flag of last transmission MailBox, new data will be only wrote to Maiboxes if flag is cleared by receiver */
    if(((*TransmitChCfgPtr->ChMBSTATAdd >> TransmitChCfgPtr->LastTxMBIndex) & MRU_IP_CH_MBSTAT_MBS0_MASK) == 0U)
    {
        /* Write data from Tx buffer to mailboxes */
        for(BufferIndex = 0u; BufferIndex < TransmitChCfgPtr->NumTxMB; BufferIndex++)
        {
            *TransmitChCfgPtr->MBAddList[BufferIndex] = TxBufferPtr[BufferIndex];
        }
    }
    else
    {
        Status = MRU_IP_STATUS_FAIL;
    }

    return Status;
}

/**
* @brief   This function is called by MRU ISRs.
* @details This function will process MRU interrupts.
*
* @param[in]     InstanceId            Instance Id of the hardware unit.
* @param[in]     IntGroupId            Interrupt group Id of the hardware unit.
*
* @implements Mru_Ip_IrqHandler_Activity
*/
void Mru_Ip_IrqHandler(uint8 InstanceId, uint8 IntGroupId)
{
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[InstanceId];
    uint8 ChannelIdx = 0u;
    uint32 NotifyStatus = 0u;
    const Mru_Ip_ChannelCfgType * ChannelConfig = NULL_PTR;
    
    /* Processing channels notification */
    NotifyStatus = *State->HWUnitConfig->NOTIFYAdd[IntGroupId];
    for(ChannelIdx = 0u; ChannelIdx < State->HWUnitConfig->NumChannel; ChannelIdx++)
    {
        if((NotifyStatus & MRU_IP_NOTIFY_CH1_IS_MASK) != 0u)
        {
            ChannelConfig = &State->HWUnitConfig->ChannelCfg[ChannelIdx];
            if((*ChannelConfig->ChCFG0Add & MRU_IP_CH_CFG0_IE_MASK) != 0u)
            {
                /* Receive mail box */
                Mru_Ip_IrqHandlerReceiveMb(ChannelConfig, IntGroupId);
            }
            else
            {
                /* Channel enable interrupt flag is not set, nothing to do */
            }
        }
        else
        {
            /* Channel status flag is not set, nothing to do */
        }
        NotifyStatus = NotifyStatus >> 1u;
    }
}

/**
* @brief   This function is called by MRU ISRs.
* @details This function will process MRU interrupts.
*
* @param[in]     InstanceId            Instance Id of the hardware unit.
* @param[in]     IntGroupId            Interrupt group Id of the hardware unit.
*
* @implementsMru_Ip_IrqHandlerReceiveMb_Activity
*/
static void Mru_Ip_IrqHandlerReceiveMb(const Mru_Ip_ChannelCfgType * ChannelConfig, uint8 IntGroupId)
{
    const Mru_Ip_MBLinkReceiveChannelType (* MBLinkReceiveChConfig)[2U];
    volatile uint32 * ChMBSTATAddr;
    uint32 MBStatus = 0u;
    uint32 ChCFG1 = 0u;
    uint32 MBIdx = 0u;
    uint8 BufferIdx = 0u;
    uint32 IntGroupCfg = ((uint32)IntGroupId) << MRU_IP_CH_CFG1_MBIC0_SHIFT;
    const Mru_Ip_ReceiveChannelType * ReceiveChConfig = NULL_PTR; 
    
    MBLinkReceiveChConfig = ChannelConfig->MBLinkReceiveChCfg;
    if(MBLinkReceiveChConfig != NULL_PTR)
    {
        ChMBSTATAddr = ChannelConfig->ChMBSTATAdd;
        MBStatus = *ChMBSTATAddr;
        ChCFG1 = *ChannelConfig->ChCFG1Add;
        for(MBIdx = 0u; MBIdx < ChannelConfig->NumMailbox; MBIdx++)
        {
            if(((ChCFG1 & MRU_IP_CH_CFG1_MBIC0_MASK) == IntGroupCfg) && ((MBStatus & MRU_IP_CH_MBSTAT_MBS0_MASK) != 0u))
            {
                ReceiveChConfig = MBLinkReceiveChConfig[MBIdx][IntGroupId].ReceiveChCfg;
                if(ReceiveChConfig != NULL_PTR)
                {
                    /* Copy data to RxBuffer */
                    for(BufferIdx = 0u; BufferIdx < ReceiveChConfig->NumRxMB; BufferIdx++)
                    {
                        ReceiveChConfig->RxBuffer[BufferIdx] = *ReceiveChConfig->MBAddList[BufferIdx];
                    }
                    /* To support unidirectional communication, transmitter core will check Mailbox flag of Receiver MRU is cleared for triggering next transmit session.
                    Mailbox flag should be clear after copy data to buffer and before call notification */
                    *ChMBSTATAddr = (uint32)(MRU_IP_CH_MBSTAT_MBS0_MASK << MBIdx);
                    /* Call notification function */
                    if(NULL_PTR != ReceiveChConfig->ReceiveNotification)
                    {
                        ReceiveChConfig->ReceiveNotification(ReceiveChConfig->ChannelId,
                                                            ReceiveChConfig->RxBuffer,
                                                            ReceiveChConfig->NumRxMB
                                                            );
                    }
                }
                else
                {
                    /* the mailbox was not configured using current interrupt group, nothing to do */
                }
            }
            else
            {
                /* Mailbox status flag for current interrupt group is not set, nothing to do */
            }
            MBStatus = MBStatus >> 1u;
            ChCFG1 = ChCFG1 >> 1u;
        }
    }
    else
    {
        /* the channel was not used by the driver, nothing to do */
    }           
}

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
