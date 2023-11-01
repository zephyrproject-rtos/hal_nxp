/*
 * Copyright 2021-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file    Mru_Ip.c
*
*   @defgroup   MRU_IP_DRIVER Mru Ip Driver
*   @ingroup    Platform
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
#include "OsIf.h"
#if (STD_ON == MRU_IP_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_MRU_IP_VENDOR_ID_C                      43
#define CDD_PLATFORM_MRU_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define CDD_PLATFORM_MRU_IP_AR_RELEASE_MINOR_VERSION_C       7
#define CDD_PLATFORM_MRU_IP_AR_RELEASE_REVISION_VERSION_C    0
#define CDD_PLATFORM_MRU_IP_SW_MAJOR_VERSION_C               1
#define CDD_PLATFORM_MRU_IP_SW_MINOR_VERSION_C               0
#define CDD_PLATFORM_MRU_IP_SW_PATCH_VERSION_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((CDD_PLATFORM_MRU_IP_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_PLATFORM_MRU_IP_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Mru_Ip.c and Mcal.h are different"
    #endif
#endif

/* Check if Mru_Ip.h and Mru_Ip.c are of the same vendor */
#if (CDD_PLATFORM_MRU_IP_VENDOR_ID != CDD_PLATFORM_MRU_IP_VENDOR_ID_C)
    #error "Mru_Ip.h and Mru_Ip.c have different vendor ids"
#endif
/* Check if Mru_Ip.h file and Mru_Ip.c file are of the same Autosar version */
#if ((CDD_PLATFORM_MRU_IP_AR_RELEASE_MAJOR_VERSION != CDD_PLATFORM_MRU_IP_AR_RELEASE_MAJOR_VERSION_C) || \
     (CDD_PLATFORM_MRU_IP_AR_RELEASE_MINOR_VERSION != CDD_PLATFORM_MRU_IP_AR_RELEASE_MINOR_VERSION_C) || \
     (CDD_PLATFORM_MRU_IP_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_MRU_IP_AR_RELEASE_REVISION_VERSION_C))
#error "AutoSar Version Numbers of Mru_Ip.h and Mru_Ip.c are different"
#endif
#if ((CDD_PLATFORM_MRU_IP_SW_MAJOR_VERSION != CDD_PLATFORM_MRU_IP_SW_MAJOR_VERSION_C) || \
     (CDD_PLATFORM_MRU_IP_SW_MINOR_VERSION != CDD_PLATFORM_MRU_IP_SW_MINOR_VERSION_C) || \
     (CDD_PLATFORM_MRU_IP_SW_PATCH_VERSION != CDD_PLATFORM_MRU_IP_SW_PATCH_VERSION_C))
#error "Software Version Numbers of Mru_Ip.h and Mru_Ip.c are different"
#endif

/* Check if OsIf.h and Mru_Ip.c are of the same vendor */
#if (OSIF_VENDOR_ID != CDD_PLATFORM_MRU_IP_VENDOR_ID_C)
    #error "OsIf.h and Mru_Ip.c have different vendor ids"
#endif
/* Check if OsIf.h file and Mru_Ip.c file are of the same Autosar version */
#if ((OSIF_AR_RELEASE_MAJOR_VERSION != CDD_PLATFORM_MRU_IP_AR_RELEASE_MAJOR_VERSION_C) || \
     (OSIF_AR_RELEASE_MINOR_VERSION != CDD_PLATFORM_MRU_IP_AR_RELEASE_MINOR_VERSION_C) || \
     (OSIF_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_MRU_IP_AR_RELEASE_REVISION_VERSION_C))
#error "AutoSar Version Numbers of OsIf.h and Mru_Ip.c are different"
#endif
#if ((OSIF_SW_MAJOR_VERSION != CDD_PLATFORM_MRU_IP_SW_MAJOR_VERSION_C) || \
     (OSIF_SW_MINOR_VERSION != CDD_PLATFORM_MRU_IP_SW_MINOR_VERSION_C) || \
     (OSIF_SW_PATCH_VERSION != CDD_PLATFORM_MRU_IP_SW_PATCH_VERSION_C))
#error "Software Version Numbers of OsIf.h and Mru_Ip.c are different"
#endif

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if ((STD_ON == MRU_IP_ENABLE_USER_MODE_SUPPORT) && (defined (MCAL_ENABLE_USER_MODE_SUPPORT)))
    #define Call_Mru_Ip_Init(pHWUnitConfigPtr) \
                OsIf_Trusted_Call1param(Mru_Ip_Init_Privileged,(pHWUnitConfigPtr))
    #define Call_Mru_Ip_Transmit(pTransmitChCfgPtr,pTxBufferPtr) \
                OsIf_Trusted_Call_Return2param(Mru_Ip_Transmit_Privileged,(pTransmitChCfgPtr),(pTxBufferPtr))
    #define Call_Mru_Ip_ReadMailbox(ReceiveChCfgPtr,RxBufferPtr,Timeout) \
                OsIf_Trusted_Call_Return3param(Mru_Ip_ReadMailbox_Privileged,(ReceiveChCfgPtr),(RxBufferPtr),(Timeout))
    #define Call_Mru_Ip_GetMailboxStatus(ReceiveChCfgPtr) \
                OsIf_Trusted_Call_Return1param(Mru_Ip_GetMailboxStatus_Privileged,(ReceiveChCfgPtr))
#else /*STD_ON == MRU_IP_ENABLE_USER_MODE_SUPPORT*/
    #define Call_Mru_Ip_Init(pHWUnitConfigPtr) \
                Mru_Ip_Init_Privileged((pHWUnitConfigPtr))
    #define Call_Mru_Ip_Transmit(pTransmitChCfgPtr,pTxBufferPtr) \
                Mru_Ip_Transmit_Privileged((pTransmitChCfgPtr),(pTxBufferPtr))
    #define Call_Mru_Ip_ReadMailbox(ReceiveChCfgPtr,RxBufferPtr,Timeout) \
                Mru_Ip_ReadMailbox_Privileged((ReceiveChCfgPtr),(RxBufferPtr),(Timeout))
    #define Call_Mru_Ip_GetMailboxStatus(ReceiveChCfgPtr) \
                Mru_Ip_GetMailboxStatus_Privileged((ReceiveChCfgPtr))
#endif /*STD_ON == MRU_IP_ENABLE_USER_MODE_SUPPORT*/
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

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
static void Mru_Ip_IrqHandlerReceiveMb(const Mru_Ip_ChannelCfgType * ChannelConfig, uint8 IntGroupId);
void Mru_Ip_Init_Privileged(const Mru_Ip_ConfigType *HWUnitConfigPtr);
Mru_Ip_StatusType Mru_Ip_Transmit_Privileged( const Mru_Ip_TransmitChannelType *TransmitChCfgPtr,
                                              const uint32 *TxBufferPtr
                                            );
Mru_Ip_StatusType Mru_Ip_ReadMailbox_Privileged( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr,
                                                 uint32 *RxBufferPtr,
                                                 uint32 Timeout
                                               );
Mru_Ip_MBStatusType Mru_Ip_GetMailboxStatus_Privileged( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr );
/*================================================================================================*/
void Mru_Ip_Init_Privileged(const Mru_Ip_ConfigType *HWUnitConfigPtr)
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
Mru_Ip_StatusType Mru_Ip_Transmit_Privileged( const Mru_Ip_TransmitChannelType *TransmitChCfgPtr,
                      const uint32 *TxBufferPtr
                    )
{
    uint8 BufferIndex = 0u;
    Mru_Ip_StatusType Status = MRU_IP_STATUS_SUCCESS;
    uint32 LastMbStatus = (*(TransmitChCfgPtr->ChMBSTATAdd)>> (TransmitChCfgPtr->LastTxMBIndex)) & MRU_IP_CH_MBSTAT_MBS0_MASK;

#if (MRU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != TransmitChCfgPtr);
    DevAssert(NULL_PTR != TxBufferPtr);
#endif

    /* In case overwriting is not allowed, need to check flag of last transmission MailBox,
       new data will be only wrote to Maiboxes if flag is cleared by receiver. */
    if ((TRUE == TransmitChCfgPtr->bOverwriteMBEnb ) || (0U == LastMbStatus ))
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

Mru_Ip_StatusType Mru_Ip_ReadMailbox_Privileged( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr,
                                                 uint32 *RxBufferPtr,
                                                 uint32 Timeout
                                               )
{
    uint32 CurrentTicks = 0u;
    uint32 ElapsedTicks = 0u;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(Timeout, PLATFORM_TIMEOUT_TYPE);
    Mru_Ip_StatusType Status = MRU_IP_STATUS_SUCCESS;
    uint8 InstanceId = ReceiveChCfgPtr->InstanceId;
    uint8 ChannelIdx = ReceiveChCfgPtr->ChannelIndex;
    uint32 MailboxStatus = 0u;
    const Mru_Ip_ChannelCfgType * ChannelConfig = NULL_PTR;
    uint8 LastRxMailboxIdx= ReceiveChCfgPtr->NumRxMB -1U;
    uint8 LastRxMailbox= (uint8)(ReceiveChCfgPtr->ListRxMB[LastRxMailboxIdx]); /* Last mailbox used in ReceiveChCfgPtr */
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[InstanceId];
    uint8 MbIdx=0;
    
#if (MRU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != ReceiveChCfgPtr);
    DevAssert(NULL_PTR != RxBufferPtr);
#endif
    ChannelConfig = &State->HWUnitConfig->ChannelCfg[ChannelIdx];

    /* Get current ticks */
    CurrentTicks = OsIf_GetCounter(PLATFORM_TIMEOUT_TYPE);
    do
    {
        MailboxStatus = *ChannelConfig->ChMBSTATAdd;
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, PLATFORM_TIMEOUT_TYPE);
        /* Check last mailbox status */
    }while(( 0U == ((MRU_IP_CH_MBSTAT_MBS0_MASK<<LastRxMailbox) & MailboxStatus)) && (ElapsedTicks < TimeoutTicks));
    
    /* Check last mailbox status */
    if( 0U != ((MRU_IP_CH_MBSTAT_MBS0_MASK<<LastRxMailbox) & MailboxStatus))
    {
        /*Last MB in ReceiveChCfgPtr is active*/
        for(MbIdx=0; MbIdx < ReceiveChCfgPtr->NumRxMB; MbIdx++)
        {
            /* Copy data from Mailbox to buffer */
            RxBufferPtr[MbIdx] = *ReceiveChCfgPtr->MBAddList[MbIdx];
        }
        /* Clear Mailbox Status*/
        *ChannelConfig->ChMBSTATAdd = (uint32)(MRU_IP_CH_MBSTAT_MBS0_MASK << LastRxMailbox);
        /* Call notification function */
        if(NULL_PTR != ReceiveChCfgPtr->ReceiveNotification)
        {
            ReceiveChCfgPtr->ReceiveNotification(ReceiveChCfgPtr->ChannelId,
                                                RxBufferPtr,
                                                ReceiveChCfgPtr->NumRxMB
                                                );
        }
    }
    else
    {
        if(ElapsedTicks >= TimeoutTicks)
        {
            Status = MRU_IP_STATUS_TIMEOUT;
        }
        else
        {
            /* if mailbox status is inactive, return fail*/
            Status = MRU_IP_STATUS_FAIL;
        }
    }
    return Status;
}

Mru_Ip_MBStatusType Mru_Ip_GetMailboxStatus_Privileged( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr )
{
    Mru_Ip_MBStatusType MbStatus = MRU_IP_MAILBOX_INACTIVE;
    uint8 InstanceId = ReceiveChCfgPtr->InstanceId;
    uint8 ChannelIdx = ReceiveChCfgPtr->ChannelIndex;
    uint32 MailboxStatus = 0u;
    const Mru_Ip_ChannelCfgType * ChannelConfig = NULL_PTR;
    uint8 LastRxMailboxIdx= ReceiveChCfgPtr->NumRxMB -1U;
    uint8 LastRxMailbox= (uint8)(ReceiveChCfgPtr->ListRxMB[LastRxMailboxIdx]); /* Last mailbox used in ReceiveChCfgPtr */
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[InstanceId];
    
#if (MRU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != ReceiveChCfgPtr);
#endif
    ChannelConfig = &State->HWUnitConfig->ChannelCfg[ChannelIdx];
    MailboxStatus = *ChannelConfig->ChMBSTATAdd;
    /* Check last mailbox status */
    if( 0U != ((MRU_IP_CH_MBSTAT_MBS0_MASK<<LastRxMailbox) & MailboxStatus))
    {
        /*Last MB in ReceiveChCfgPtr is active*/
        MbStatus = MRU_IP_MAILBOX_ACTIVE;
    }

    return MbStatus;
}

/**
* @brief            MRU peripheral initialization.
* @details          The function initialize the MRU Unit specified in the configuration.
*
* @param[in]        HWUnitConfigPtr -  pointer to the specified MRU Unit configuration.
*
* @implements Mru_Ip_Init_Activity
*/
void Mru_Ip_Init(const Mru_Ip_ConfigType *HWUnitConfigPtr)
{
    Call_Mru_Ip_Init(HWUnitConfigPtr);
}

/**
* @brief            MRU transmission.
* @details          This function writes the data to Mailboxes using the channel specified.
*
* @param[in]        TransmitChCfgPtr - pointer to the channel configuration where contains list of mailboxes to be written.
* @param[in]        TxBufferPtr - pointer to transmit buffer.
*
* @return           MRU_IP_STATUS_SUCCESS: Transmission command has been accepted.
*                   MRU_IP_STATUS_FAIL: Transmission command has not been accepted.
*
* @implements Mru_Ip_Transmit_Activity
*/
Mru_Ip_StatusType Mru_Ip_Transmit( const Mru_Ip_TransmitChannelType *TransmitChCfgPtr,
                                   const uint32 *TxBufferPtr
                    )
{
    return (Mru_Ip_StatusType)Call_Mru_Ip_Transmit(TransmitChCfgPtr, TxBufferPtr);
}

/**
* @brief            MRU Read Mailbox.
* @details          This function read the data from Mailboxes using the channel specified with polling mode.
*
* @param[in]        ReceiveChCfgPtr - Pointer for the receive channel configuration.
* @param[in]        RxBufferPtr - Buffer pointer to receive data.
* @param[in]        Timeout - time-out
*
* @return           MRU_IP_STATUS_SUCCESS: Receive command has been accepted.
*                   MRU_IP_STATUS_FAIL: Receive command has not been accepted.
*                   MRU_IP_STATUS_TIMEOUT: Receive command has been timeout.
*
* @implements Mru_Ip_ReadMailbox_Activity
*/
Mru_Ip_StatusType Mru_Ip_ReadMailbox( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr,
                                      uint32 *RxBufferPtr,
                                      uint32 Timeout
                    )
{
    return (Mru_Ip_StatusType)Call_Mru_Ip_ReadMailbox(ReceiveChCfgPtr, RxBufferPtr, Timeout);
}

/**
* @brief   Get mailbox status.
* @details This function get mailbox status of a specific channel.
*
* @param[in]      ReceiveChCfgPtr       Pointer for the receive channel configuration.
*
* @return Mru_Ip_MBStatusType
* @retval MRU_IP_MAILBOX_INACTIVE       Mailbox status is inactive
* @retval MRU_IP_MAILBOX_ACTIVE         Mailbox status is active
*
* @implements    Mru_Ip_GetMailboxStatus_Activity
*/
Mru_Ip_MBStatusType Mru_Ip_GetMailboxStatus( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr )
{
    return (Mru_Ip_MBStatusType)Call_Mru_Ip_GetMailboxStatus(ReceiveChCfgPtr);
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
    const Mru_Ip_MBLinkReceiveChannelType (* MBLinkReceiveChConfig)[NUMBER_OF_INTERRUPT_GROUP];
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
            MBStatus = MBStatus >> MRU_CH_MBSTAT_MBS0_WIDTH;
            ChCFG1 = ChCFG1 >> MRU_CH_CFG1_MBIC0_WIDTH;
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
