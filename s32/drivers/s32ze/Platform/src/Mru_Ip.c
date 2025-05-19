/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
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
#include "SchM_Platform.h"
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
#define CDD_PLATFORM_MRU_IP_SW_MAJOR_VERSION_C               2
#define CDD_PLATFORM_MRU_IP_SW_MINOR_VERSION_C               0
#define CDD_PLATFORM_MRU_IP_SW_PATCH_VERSION_C               1
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
#ifdef PLATFORM_IP_ENABLE_MRU
#if (PLATFORM_IP_ENABLE_MRU == STD_ON)

#if ((STD_ON == MRU_IP_ENABLE_USER_MODE_SUPPORT) && (defined (MCAL_ENABLE_USER_MODE_SUPPORT)))
    #define Call_Mru_Ip_Init(pHWUnitConfigPtr) \
                OsIf_Trusted_Call1param(Mru_Ip_Init_Privileged,(pHWUnitConfigPtr))
    #define Call_Mru_Ip_Transmit(pTransmitChCfgPtr,pTxBufferPtr) \
                OsIf_Trusted_Call_Return2param(Mru_Ip_Transmit_Privileged,(pTransmitChCfgPtr),(pTxBufferPtr))
#if (STD_ON == MRU_IP_CHANNEL_RESET_API)
    #define Call_Mru_Ip_ResetTransmitChannel(pTransmitChCfgPtr) \
                OsIf_Trusted_Call1param(Mru_Ip_ResetTransmitChannel_Privileged,(pTransmitChCfgPtr))
    #define Call_Mru_Ip_ResetReceiveChannel(pReceiveChCfgPtr) \
                OsIf_Trusted_Call1param(Mru_Ip_ResetReceiveChannel_Privileged,(pReceiveChCfgPtr))
#endif
#if (STD_ON == MRU_IP_INSTANCE_RESET_API)
    #define Call_Mru_Ip_ResetInstance(pResetInsCfgPtr) \
                OsIf_Trusted_Call1param(Mru_Ip_ResetInstance_Privileged,(pResetInsCfgPtr))
#endif
    #define Call_Mru_Ip_ReadMailbox(ReceiveChCfgPtr,RxBufferPtr,Timeout) \
                OsIf_Trusted_Call_Return3param(Mru_Ip_ReadMailbox_Privileged,(ReceiveChCfgPtr),(RxBufferPtr),(Timeout))
    #define Call_Mru_Ip_GetMailboxStatus(ReceiveChCfgPtr) \
                OsIf_Trusted_Call_Return1param(Mru_Ip_GetMailboxStatus_Privileged,(ReceiveChCfgPtr))
#if (STD_ON == MRU_IP_CHANNEL_ENABLE_API)
    #define Call_Mru_Ip_EnableChannel(ReceiveChCfgPtr) \
                OsIf_Trusted_Call_Return1param(Mru_Ip_EnableChannel_Privileged,(ReceiveChCfgPtr))
#endif
#if (STD_ON == MRU_IP_CHANNEL_DISABLE_API)
    #define Call_Mru_Ip_DisableChannel(ReceiveChCfgPtr) \
                OsIf_Trusted_Call_Return1param(Mru_Ip_DisableChannel_Privileged,(ReceiveChCfgPtr))
#endif
#else /*STD_ON == MRU_IP_ENABLE_USER_MODE_SUPPORT*/
    #define Call_Mru_Ip_Init(pHWUnitConfigPtr) \
                Mru_Ip_Init_Privileged((pHWUnitConfigPtr))
    #define Call_Mru_Ip_Transmit(pTransmitChCfgPtr,pTxBufferPtr) \
                Mru_Ip_Transmit_Privileged((pTransmitChCfgPtr),(pTxBufferPtr))
#if (STD_ON == MRU_IP_CHANNEL_RESET_API)
    #define Call_Mru_Ip_ResetTransmitChannel(pTransmitChCfgPtr) \
                Mru_Ip_ResetTransmitChannel_Privileged((pTransmitChCfgPtr))
    #define Call_Mru_Ip_ResetReceiveChannel(pReceiveChCfgPtr) \
                Mru_Ip_ResetReceiveChannel_Privileged((pReceiveChCfgPtr))
#endif
#if (STD_ON == MRU_IP_INSTANCE_RESET_API)
    #define Call_Mru_Ip_ResetInstance(pResetInsCfgPtr) \
                Mru_Ip_ResetInstance_Privileged((pResetInsCfgPtr))
#endif
    #define Call_Mru_Ip_ReadMailbox(ReceiveChCfgPtr,RxBufferPtr,Timeout) \
                Mru_Ip_ReadMailbox_Privileged((ReceiveChCfgPtr),(RxBufferPtr),(Timeout))
    #define Call_Mru_Ip_GetMailboxStatus(ReceiveChCfgPtr) \
                Mru_Ip_GetMailboxStatus_Privileged((ReceiveChCfgPtr))
#if (STD_ON == MRU_IP_CHANNEL_ENABLE_API)
    #define Call_Mru_Ip_EnableChannel(ReceiveChCfgPtr) \
                Mru_Ip_EnableChannel_Privileged((ReceiveChCfgPtr))
#endif
#if (STD_ON == MRU_IP_CHANNEL_DISABLE_API)
    #define Call_Mru_Ip_DisableChannel(ReceiveChCfgPtr) \
                Mru_Ip_DisableChannel_Privileged((ReceiveChCfgPtr))
#endif
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

#define PLATFORM_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Platform_MemMap.h"

VAR_SEC_NOCACHE(Mru_Ip_axStateStructure) Mru_Ip_StateStructureType Mru_Ip_axStateStructure[MRU_IP_NUMBER_OF_INSTANCES];

VAR_SEC_NOCACHE(Mru_Ip_apxStateStructureArray) Mru_Ip_StateStructureType* Mru_Ip_apxStateStructureArray[MRU_IP_NUMBER_OF_INSTANCES];

#define PLATFORM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
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
static void Mru_Ip_ProcessActiveMb(const Mru_Ip_ReceiveChannelType * pReceiveChConfig,
                                   volatile uint32 *pu32ChMbStatAddr,
                                   uint32 u32MbIndex);
void Mru_Ip_Init_Privileged(const Mru_Ip_ConfigType *HWUnitConfigPtr);
Mru_Ip_StatusType Mru_Ip_Transmit_Privileged( const Mru_Ip_TransmitChannelType *TransmitChCfgPtr,
                                              const uint32 *TxBufferPtr
                                            );
#if (STD_ON == MRU_IP_CHANNEL_RESET_API)
void Mru_Ip_ResetTransmitChannel_Privileged( const Mru_Ip_TransmitChannelType *TransmitChCfgPtr );
void Mru_Ip_ResetReceiveChannel_Privileged( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr );
#endif
#if (STD_ON == MRU_IP_INSTANCE_RESET_API)
void Mru_Ip_ResetInstance_Privileged( const Mru_Ip_ResetInstanceType *ResetInsCfgPtr );
#endif
Mru_Ip_StatusType Mru_Ip_ReadMailbox_Privileged( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr,
                                                 uint32 *RxBufferPtr,
                                                 uint32 Timeout
                                               );
Mru_Ip_MBStatusType Mru_Ip_GetMailboxStatus_Privileged( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr );
#if (STD_ON == MRU_IP_CHANNEL_ENABLE_API)
Mru_Ip_StatusType Mru_Ip_EnableChannel_Privileged( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr);
#endif
#if (STD_ON == MRU_IP_CHANNEL_DISABLE_API)
Mru_Ip_StatusType Mru_Ip_DisableChannel_Privileged( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr);
#endif
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
    Mru_Ip_apxStateStructureArray[InstanceId] = &Mru_Ip_axStateStructure[HWUnitConfigPtr->StateIndex];
    State = Mru_Ip_apxStateStructureArray[InstanceId];
    State->HWUnitConfig = HWUnitConfigPtr;

    for(CfgIndex = 0u; CfgIndex < HWUnitConfigPtr->NumChannel; CfgIndex++)
    {
        if((NULL_PTR != HWUnitConfigPtr->ChannelCfg[CfgIndex].MBLinkReceiveChCfg) &&
           (FALSE == HWUnitConfigPtr->ChannelCfg[CfgIndex].bSkipInitChannel))
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
#if (MRU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != TransmitChCfgPtr);
    DevAssert(NULL_PTR != TxBufferPtr);
#endif
    uint8 BufferIndex = 0u;
    Mru_Ip_StatusType Status = MRU_IP_STATUS_SUCCESS;
    uint32 LastMbStatus = (*(TransmitChCfgPtr->ChMBSTATAdd)>> (TransmitChCfgPtr->LastTxMBIndex)) & MRU_IP_CH_MBSTAT_MBS0_MASK;

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
/*================================================================================================*/
#if (STD_ON == MRU_IP_CHANNEL_RESET_API)
void Mru_Ip_ResetTransmitChannel_Privileged( const Mru_Ip_TransmitChannelType *TransmitChCfgPtr)
{
#if (MRU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != TransmitChCfgPtr);
#endif
    uint8 MailboxUsedNum= TransmitChCfgPtr->NumTxMB;
    uint8 Mailbox_Idx = 0U;
    uint8 MailboxId = 0U;
    
    SchM_Enter_Platform_PLATFORM_EXCLUSIVE_AREA_09();
    for(Mailbox_Idx = 0; Mailbox_Idx < MailboxUsedNum ; Mailbox_Idx++)
    {
        MailboxId = TransmitChCfgPtr->TxMBList[Mailbox_Idx];    /* Get mailbox ID is used*/
        *TransmitChCfgPtr->ChMBSTATAdd = MRU_IP_CH_MBSTAT_MBS0_MASK << MailboxId ;  /* Clear mailbox status */
    }
    SchM_Exit_Platform_PLATFORM_EXCLUSIVE_AREA_09();
}
/*================================================================================================*/
void Mru_Ip_ResetReceiveChannel_Privileged(const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr )
{
#if (MRU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != ReceiveChCfgPtr);
#endif
    uint8 InstanceId = ReceiveChCfgPtr->InstanceId;
    uint8 ChannelIdx = ReceiveChCfgPtr->ChannelIndex;
    uint8 MailboxUsedNum= ReceiveChCfgPtr->NumRxMB;
    const Mru_Ip_ChannelCfgType * ChannelConfig = NULL_PTR;
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[InstanceId];
    uint8 Mailbox_Idx = 0U;
    uint8 MailboxId = 0U;
    
    ChannelConfig = &State->HWUnitConfig->ChannelCfg[ChannelIdx];
    SchM_Enter_Platform_PLATFORM_EXCLUSIVE_AREA_10();
    for(Mailbox_Idx = 0; Mailbox_Idx < MailboxUsedNum ; Mailbox_Idx++)
    {
        MailboxId = ReceiveChCfgPtr->ListRxMB[Mailbox_Idx]; /* Get mailbox ID is used*/
        *ChannelConfig->ChMBSTATAdd = MRU_IP_CH_MBSTAT_MBS0_MASK << MailboxId ;  /* Clear mailbox status */
    }
    SchM_Exit_Platform_PLATFORM_EXCLUSIVE_AREA_10();
}
#endif /* STD_ON == MRU_IP_CHANNEL_RESET_API */
/*================================================================================================*/
#if (STD_ON == MRU_IP_INSTANCE_RESET_API)
void Mru_Ip_ResetInstance_Privileged(const Mru_Ip_ResetInstanceType *ResetInsCfgPtr )
{
#if (MRU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != ResetInsCfgPtr);
#endif
    uint8 MruChannelNum = ResetInsCfgPtr->NumChannel;
    uint8 ChannelIdx = 0;
    uint32 MBStatusMask= 0;

    SchM_Enter_Platform_PLATFORM_EXCLUSIVE_AREA_11();
    /* Reset all MB channel in Mru instance id */
    for (ChannelIdx = 0 ; ChannelIdx < MruChannelNum ; ChannelIdx++)
    {
        MBStatusMask = ResetInsCfgPtr->MruResetChOfInsCfg[ChannelIdx].MBStatusMask;
        /* Clear all mailbox status on the channel */
        *ResetInsCfgPtr->MruResetChOfInsCfg[ChannelIdx].ChMBSTATAdd = MBStatusMask;
    }
    SchM_Exit_Platform_PLATFORM_EXCLUSIVE_AREA_11();
}
#endif /* STD_ON == MRU_IP_INSTANCE_RESET_API */
/*================================================================================================*/
Mru_Ip_StatusType Mru_Ip_ReadMailbox_Privileged( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr,
                                                 uint32 *RxBufferPtr,
                                                 uint32 Timeout
                                               )
{
#if (MRU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != ReceiveChCfgPtr);
    DevAssert(NULL_PTR != RxBufferPtr);
#endif
    uint32 CurrentTicks = 0u;
    uint32 ElapsedTicks = 0u;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(Timeout, PLATFORM_TIMEOUT_TYPE);
    Mru_Ip_StatusType Status = MRU_IP_STATUS_SUCCESS;
    uint8 InstanceId = ReceiveChCfgPtr->InstanceId;
    uint8 ChannelIdx = ReceiveChCfgPtr->ChannelIndex;
    uint32 MailboxStatus = 0u;
    const Mru_Ip_ChannelCfgType * ChannelConfig = NULL_PTR;
    uint8 LastRxMailboxIdx = ReceiveChCfgPtr->NumRxMB -1U;
#if (MRU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((sint8)LastRxMailboxIdx >= (sint8)0);
#endif
    uint8 LastRxMailbox= (uint8)(ReceiveChCfgPtr->ListRxMB[LastRxMailboxIdx]); /* Last mailbox used in ReceiveChCfgPtr */
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[InstanceId];
    uint8 MbIdx=0;
    
    ChannelConfig = &State->HWUnitConfig->ChannelCfg[ChannelIdx];
    /* Get last mailbox status */
    MailboxStatus = *ChannelConfig->ChMBSTATAdd;
    /* Get current ticks */
    CurrentTicks = OsIf_GetCounter(PLATFORM_TIMEOUT_TYPE);
    while(( 0U == ((MRU_IP_CH_MBSTAT_MBS0_MASK<<LastRxMailbox) & MailboxStatus)) && (ElapsedTicks < TimeoutTicks))
    {
        MailboxStatus = *ChannelConfig->ChMBSTATAdd;
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, PLATFORM_TIMEOUT_TYPE);
        /* Check last mailbox status */
    }
    
    /* Check last mailbox status */
    if(( 0U != ((MRU_IP_CH_MBSTAT_MBS0_MASK<<LastRxMailbox) & MailboxStatus)) && (ElapsedTicks < TimeoutTicks))
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
        Status = MRU_IP_STATUS_TIMEOUT;
    }
    return Status;
}

Mru_Ip_MBStatusType Mru_Ip_GetMailboxStatus_Privileged( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr )
{
#if (MRU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != ReceiveChCfgPtr);
#endif
    Mru_Ip_MBStatusType MbStatus = MRU_IP_MAILBOX_INACTIVE;
    uint8 InstanceId = ReceiveChCfgPtr->InstanceId;
    uint8 ChannelIdx = ReceiveChCfgPtr->ChannelIndex;
    uint32 MailboxStatus = 0u;
    const Mru_Ip_ChannelCfgType * ChannelConfig = NULL_PTR;
    uint8 LastRxMailboxIdx = ReceiveChCfgPtr->NumRxMB -1U;
#if (MRU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert((sint8)LastRxMailboxIdx >= (sint8)0);
#endif
    uint8 LastRxMailbox= (uint8)(ReceiveChCfgPtr->ListRxMB[LastRxMailboxIdx]); /* Last mailbox used in ReceiveChCfgPtr */
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[InstanceId];
    
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

#if (STD_ON == MRU_IP_CHANNEL_ENABLE_API)
Mru_Ip_StatusType Mru_Ip_EnableChannel_Privileged( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr)
{
#if (MRU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != ReceiveChCfgPtr);
#endif
    const Mru_Ip_ChannelCfgType * ChannelConfig = NULL_PTR;
    uint8 RxMailboxUsedNum= ReceiveChCfgPtr->NumRxMB;
    uint8 LastRxMailboxId= ReceiveChCfgPtr->ListRxMB[RxMailboxUsedNum -1];
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[ReceiveChCfgPtr->InstanceId];
    uint32 LastMailboxEnableBitMask = (MRU_IP_CH_CFG0_MBE0_MASK << LastRxMailboxId);
    Mru_Ip_StatusType Status = MRU_IP_STATUS_SUCCESS;
    uint32 LastMailboxEnableBitValue = 0U ;  

    if (0U < RxMailboxUsedNum)
    {
        ChannelConfig = &State->HWUnitConfig->ChannelCfg[ReceiveChCfgPtr->ChannelIndex];
        /* Get latest mailbox enable bit of ReceiveChCfgPtr */
        LastMailboxEnableBitValue= *(ChannelConfig->ChCFG0Add) & LastMailboxEnableBitMask ;
        if(0U == LastMailboxEnableBitValue)   /* Last Mailbox Enable Bit is disable */
        {
            SchM_Enter_Platform_PLATFORM_EXCLUSIVE_AREA_07();
            /* Enable latest Mailbox which is used by ReceiveChCfgPtr */
            *ChannelConfig->ChCFG0Add |= LastMailboxEnableBitMask;
            SchM_Exit_Platform_PLATFORM_EXCLUSIVE_AREA_07();
        }
        else    
        {
            /* Last Mailbox Enable Bit is enabled already*/
        }
    }
    else
    {
        Status = MRU_IP_STATUS_FAIL;
    }
    return Status;
}

#endif  /* STD_ON == MRU_IP_CHANNEL_ENABLE_API*/

#if (STD_ON == MRU_IP_CHANNEL_DISABLE_API)
Mru_Ip_StatusType Mru_Ip_DisableChannel_Privileged( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr)
{
#if (MRU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != ReceiveChCfgPtr);
#endif
    uint8 InstanceId = ReceiveChCfgPtr->InstanceId;
    uint8 ChannelIdx = ReceiveChCfgPtr->ChannelIndex;
    const Mru_Ip_ChannelCfgType * ChannelConfig = NULL_PTR;
    uint8 RxMailboxUsedNum= ReceiveChCfgPtr->NumRxMB;
    uint8 LastRxMailboxId= ReceiveChCfgPtr->ListRxMB[RxMailboxUsedNum -1];
    uint32 LastMailboxStatusBitMask = (MRU_IP_CH_MBSTAT_MBS0_MASK << LastRxMailboxId);
    const Mru_Ip_StateStructureType* State = Mru_Ip_apxStateStructureArray[InstanceId];
    volatile uint32 * ChMBSTATAddr;     /* Mailbox status address*/
    uint8 RxMailbox_Idx = 0U;
    Mru_Ip_StatusType Status = MRU_IP_STATUS_SUCCESS;
    
    if (0U < RxMailboxUsedNum)
    {
        ChannelConfig = &State->HWUnitConfig->ChannelCfg[ChannelIdx];
        ChMBSTATAddr = ChannelConfig->ChMBSTATAdd;
        
        SchM_Enter_Platform_PLATFORM_EXCLUSIVE_AREA_08();
        /* Disable latest Mailbox which is used by ReceiveChCfgPtr */
        *ChannelConfig->ChCFG0Add &= ~(MRU_IP_CH_CFG0_MBE0_MASK << LastRxMailboxId);
        SchM_Exit_Platform_PLATFORM_EXCLUSIVE_AREA_08();

        if( 0U != (*ChMBSTATAddr & LastMailboxStatusBitMask ))   /* If Mailbox status is active */
        { 
            for (RxMailbox_Idx =0 ; RxMailbox_Idx < RxMailboxUsedNum ; RxMailbox_Idx++)
            {
                /* Read Rx mailboxs data which are used in ReceiveChCfgPtr*/
                ReceiveChCfgPtr->RxBuffer[RxMailbox_Idx] = *ReceiveChCfgPtr->MBAddList[RxMailbox_Idx];
            }
            /* Clear Latest Mailbox Status*/
            *ChMBSTATAddr = (uint32)LastMailboxStatusBitMask;
            /* Call notification function */
            if(NULL_PTR != ReceiveChCfgPtr->ReceiveNotification)
            {
                ReceiveChCfgPtr->ReceiveNotification(ReceiveChCfgPtr->ChannelId,
                                                    ReceiveChCfgPtr->RxBuffer,
                                                    ReceiveChCfgPtr->NumRxMB
                                                    );
            }
        }
    }
    else
    {
        Status = MRU_IP_STATUS_FAIL;
    }
    return Status;
}
#endif  /* STD_ON == MRU_IP_CHANNEL_DISABLE_API*/
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

#if (STD_ON == MRU_IP_CHANNEL_RESET_API)
/**
* @brief            Reset transmit channel.
* @details          This function reset mailboxs status which are used by transmit channel in configuration.
*
* @param[in]        TransmitChCfgPtr - Pointer for the transmit channel configuration.
*
* @return           void.
*
* @implements Mru_Ip_ResetTransmitChannel_Activity
*/
void Mru_Ip_ResetTransmitChannel( const Mru_Ip_TransmitChannelType *TransmitChCfgPtr
                    )
{
    Call_Mru_Ip_ResetTransmitChannel(TransmitChCfgPtr);
}
/**
* @brief            Reset receive channel.
* @details          This function reset mailboxs status which are used by receive channel in configuration.
*
* @param[in]        ReceiveChCfgPtr - Pointer for the receive channel configuration.
*
* @return           void.
*
* @implements Mru_Ip_ResetReceiveChannel_Activity
*/
void Mru_Ip_ResetReceiveChannel( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr
                    )
{
    Call_Mru_Ip_ResetReceiveChannel(ReceiveChCfgPtr);
}
#endif /* STD_ON == MRU_IP_CHANNEL_RESET_API */


#if (STD_ON == MRU_IP_INSTANCE_RESET_API)
/**
* @brief            Reset Mru Instance.
* @details          This function reset all mailbox status in a Mru instance.
*
* @param[in]        ResetInsCfgPtr – Reset instance ID which is defined in generated code
*
* @return           void.
*
* @implements Mru_Ip_ResetInstance_Activity
*/
void Mru_Ip_ResetInstance( const Mru_Ip_ResetInstanceType *ResetInsCfgPtr)
{
    Call_Mru_Ip_ResetInstance(ResetInsCfgPtr);
}
#endif
/**
* @brief            MRU Read Mailbox.
* @details          This function read the data from Mailboxes using the channel specified with polling mode.
*
* @param[in]        ReceiveChCfgPtr - Pointer for the receive channel configuration.
* @param[in]        RxBufferPtr - Buffer pointer to receive data.
* @param[in]        Timeout - time-out
*
* @return           MRU_IP_STATUS_SUCCESS: Receive command has been accepted.
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

#if (STD_ON == MRU_IP_CHANNEL_ENABLE_API)
/**
* @brief            MRU Enable channel.
* @details          This function enable interrupt capability of a logical receive channel.
*
* @param[in]        ReceiveChCfgPtr - Pointer for the receive channel configuration.
*
* @return           Mru_Ip_StatusType
* @retval           MRU_IP_STATUS_SUCCESS: Receive command has been accepted.
*                   MRU_IP_STATUS_FAIL: Receive command has not been accepted.
*
* @implements Mru_Ip_EnableChannel_Activity
*/
Mru_Ip_StatusType Mru_Ip_EnableChannel(const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr)
{
    return (Mru_Ip_StatusType)Call_Mru_Ip_EnableChannel(ReceiveChCfgPtr);
}
#endif /*STD_ON == MRU_IP_CHANNEL_ENABLE_API*/

#if (STD_ON == MRU_IP_CHANNEL_DISABLE_API)
/**
* @brief            MRU Disable channel.
* @details          This function disable interrupt capability and Mru mailbox read functional of a logical receive channel. 
*                   Before actual disabling logical Mru channel , Mru_Ip_DisableChannel
*                   will try to see if there is any on-going request is pending and execute it immediately. 
*                   After disabling operation is done, any new request will be ignored. 
*                   The pending interrupt inside interrupt controller cannot be cleared and will be treated like spurious interrupt.
*
* @param[in]        ReceiveChCfgPtr - Pointer for the receive channel configuration.
*
* @return           Mru_Ip_StatusType
* @retval           MRU_IP_STATUS_SUCCESS: Receive command has been accepted.
*                   MRU_IP_STATUS_FAIL: Receive command has not been accepted.
*
* @implements Mru_Ip_DisableChannel_Activity
*/
Mru_Ip_StatusType Mru_Ip_DisableChannel(const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr)
{
    return (Mru_Ip_StatusType)Call_Mru_Ip_DisableChannel(ReceiveChCfgPtr);
}
#endif /*STD_ON == MRU_IP_CHANNEL_DISABLE_API*/
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
    const Mru_Ip_MBLinkReceiveChannelType (* MBLinkReceiveChConfig)[NOTIFY_STATUS_COUNT];
    volatile uint32 * ChMBSTATAddr;
    uint32 MBStatus = 0u;
    uint32 ChCFG1 = 0u;
    uint32 MBIdx = 0u;
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
                Mru_Ip_ProcessActiveMb(ReceiveChConfig, ChMBSTATAddr, MBIdx);
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

/**
* @brief   Process the active mailbox.
* @details This function process the active mailbox when ISR is called.
*
* @param[in]     pReceiveChConfig    Pointer of the receive channel configuration.
* @param[in]     pu32ChMbStatAddr    The address of the channel mailbox status register.
* @param[in]     u32MbIndex          Index of mailbox.
*
*/
static void Mru_Ip_ProcessActiveMb(const Mru_Ip_ReceiveChannelType * pReceiveChConfig,
                                   volatile uint32 *pu32ChMbStatAddr,
                                   uint32 u32MbIndex)
{
    uint8 u8BufferIdx;

    if(pReceiveChConfig != NULL_PTR)
    {
        /* Copy data to RxBuffer */
        for(u8BufferIdx = 0u; u8BufferIdx < pReceiveChConfig->NumRxMB; u8BufferIdx++)
        {
            pReceiveChConfig->RxBuffer[u8BufferIdx] = *pReceiveChConfig->MBAddList[u8BufferIdx];
        }
        /* To support unidirectional communication, transmitter core will check Mailbox flag of Receiver MRU is cleared for triggering next transmit session.
        Mailbox flag should be clear after copy data to buffer and before call notification */
        *pu32ChMbStatAddr = (uint32)(MRU_IP_CH_MBSTAT_MBS0_MASK << u32MbIndex);
        /* Call notification function */
        if(NULL_PTR != pReceiveChConfig->ReceiveNotification)
        {
            pReceiveChConfig->ReceiveNotification(pReceiveChConfig->ChannelId,
                                                  pReceiveChConfig->RxBuffer,
                                                  pReceiveChConfig->NumRxMB
                                                 );
        }
    }
    else
    {
        /* the mailbox was not configured using current interrupt group, nothing to do */
    }
}
#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#endif /* PLATFORM_IP_ENABLE_MRU == STD_ON)*/
#endif /* PLATFORM_IP_ENABLE_MRU */

#ifdef __cplusplus
}
#endif

/** @} */
