/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file Netc_Eth_Ip.c
*
*   @addtogroup NETC_ETH_DRIVER NETC_ETH Driver
*   @internal
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Netc_Eth_Ip.h"
#include "OsIf.h"        /* Used for timeouts. */

#if(NETC_ETH_IP_DEV_ERROR_DETECT == STD_ON)
    #include "Devassert.h"
#endif
#if(NETC_ETH_IP_HAS_CACHE_MANAGEMENT == STD_ON)
    #include "Cache_Ip.h"
#endif

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_ETH_IP_VENDOR_ID_C                      43
#define NETC_ETH_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define NETC_ETH_IP_AR_RELEASE_MINOR_VERSION_C       7
#define NETC_ETH_IP_AR_RELEASE_REVISION_VERSION_C    0
#define NETC_ETH_IP_SW_MAJOR_VERSION_C               0
#define NETC_ETH_IP_SW_MINOR_VERSION_C               9
#define NETC_ETH_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Netc_Eth_Ip.h */
#if (NETC_ETH_IP_VENDOR_ID_C !=  NETC_ETH_IP_VENDOR_ID)
    #error "Netc_Eth_Ip.c and Netc_Eth_Ip.h have different vendor ids"
#endif
#if (( NETC_ETH_IP_AR_RELEASE_MAJOR_VERSION_C    !=  NETC_ETH_IP_AR_RELEASE_MAJOR_VERSION) || \
     ( NETC_ETH_IP_AR_RELEASE_MINOR_VERSION_C    !=  NETC_ETH_IP_AR_RELEASE_MINOR_VERSION) || \
     ( NETC_ETH_IP_AR_RELEASE_REVISION_VERSION_C !=  NETC_ETH_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Netc_Eth_Ip.c and Netc_Eth_Ip.h are different"
#endif
#if (( NETC_ETH_IP_SW_MAJOR_VERSION_C !=  NETC_ETH_IP_SW_MAJOR_VERSION) || \
     ( NETC_ETH_IP_SW_MINOR_VERSION_C !=  NETC_ETH_IP_SW_MINOR_VERSION) || \
     ( NETC_ETH_IP_SW_PATCH_VERSION_C !=  NETC_ETH_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Netc_Eth_Ip.c and Netc_Eth_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against OsIf.h */
    #if ((NETC_ETH_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (NETC_ETH_IP_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Netc_Eth_Ip.c and OsIf.h are different!"
    #endif
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#define ETH_43_NETC_START_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"
extern Netc_Eth_Ip_SiBaseType *netcSIsBase[FEATURE_NETC_ETH_NUMBER_OF_CTRLS];
extern Netc_Eth_Ip_VfBaseType *netcVFBase[FEATURE_NETC_ETH_NUMBER_OF_CTRLS];
#define ETH_43_NETC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"

#define ETH_43_NETC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"
extern Netc_Eth_Ip_MACFilterHashTableEntryType *MACFilterHashTableAddrs[FEATURE_NETC_ETH_NUMBER_OF_CTRLS];

#define ETH_43_NETC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"

#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
#ifdef NETC_ETH_0_USED
/** @brief Store timestamp information of transmitted frames. */
extern Netc_Eth_Ip_TxTimestampInfoType Netc_Eth_Ip_TxTimestampInfoBuff[NETC_ETH_IP_NUM_OF_PHYSICAL_CTRLS][NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR];
#endif /* NETC_ETH_0_USED */

/** @brief Store timestamp information of received frames. */
/** TODO: get the maximum of descr between variants */
extern Netc_Eth_Ip_RxTimestampInfoType Netc_Eth_Ip_RxTimestampInfoBuff[FEATURE_NETC_ETH_NUMBER_OF_CTRLS][NETC_ETH_IP_MAX_NUMBER_OF_RXRINGS][NETC_ETH_IP_MAX_NUMBER_OF_RXDESCRIPTORS];
static uint32 Netc_Eth_Ip_RxTimestampID = (uint32)0U;
#endif /* STD_ON == NETC_ETH_IP_EXTENDED_BUFF */

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define ETH_43_NETC_START_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"

/** @brief Pointers to NETC internal driver state for each controller(SI). */
Netc_Eth_Ip_StateType *Netc_Eth_Ip_apxState[FEATURE_NETC_ETH_NUMBER_OF_CTRLS] = { NULL_PTR };

Netc_Eth_Ip_TimeType LatestTxTimestamp = { 0U, 0U};
boolean LatestTxTimestampValidFlag = (boolean)FALSE;

#define ETH_43_NETC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"

#if ((NETC_ETH_IP_HAS_EXTERNAL_TX_BUFFERS == STD_ON) || (NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS == STD_ON))
#define ETH_43_NETC_START_SEC_CONST_BOOLEAN
#include "Eth_43_NETC_MemMap.h"

#if (NETC_ETH_IP_HAS_EXTERNAL_TX_BUFFERS == STD_ON)
/** @brief Table storing information related to the method of Tx Data Buffers Management.*/
static const boolean Netc_Eth_Ip_ControllerHasExternalTxBufferManagement[FEATURE_NETC_ETH_NUMBER_OF_CTRLS] = NETC_ETH_IP_INST_HAS_EXTERNAL_TX_BUFFERS;
#endif

#if (NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS == STD_ON)
/** @brief Table storing information related to the method of Rx Data Buffers Management.*/
static const boolean Netc_Eth_Ip_ControllerHasExternalRxBufferManagement[FEATURE_NETC_ETH_NUMBER_OF_CTRLS] = NETC_ETH_IP_INST_HAS_EXTERNAL_RX_BUFFERS;
#endif

#define ETH_43_NETC_STOP_SEC_CONST_BOOLEAN
#include "Eth_43_NETC_MemMap.h"

#endif /* ((NETC_ETH_IP_HAS_EXTERNAL_TX_BUFFERS == STD_ON) || (NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS == STD_ON)) */

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ETH_43_NETC_START_SEC_CODE
#include "Eth_43_NETC_MemMap.h"
/**
 * @brief For each controller(station interface) state structure will be initialized.
 *
 * @param ctrlIndex
 * @param config
 */
static void Netc_Eth_Ip_InitStateStructure(uint8 ctrlIndex, const Netc_Eth_Ip_ConfigType *config);
/**
 * @brief Initialize all BD rings for the current SI.
 *
 * @param ctrlIndex Number of the current SI.
 * @param config    General configuration of the controller.
 */
static void Netc_Eth_Ip_InitTxBD(uint8 ctrlIndex, const Netc_Eth_Ip_ConfigType *config);
static void Netc_Eth_Ip_InitRxBD(uint8 ctrlIndex, const Netc_Eth_Ip_ConfigType *config);

/**
 * @brief
 *
 * @param ctrlIndex
 * @param config
 */
static void Netc_Eth_Ip_InitCBDR(uint8 ctrlIndex,  const Netc_Eth_Ip_ConfigType *config);

/**
 * @brief This function will be used to enable and set all the configuration for interrupt.
 * @details Number of defaults MSI entries in table for ENETC is 48.
 *
 * @param ctrlIndex Number of the current SI.
 * @param config    General configuration of the controller.
 */
void Netc_Eth_Ip_EnableIrq(uint8 ctrlIndex, const Netc_Eth_Ip_ConfigType *config);

/**
 * @brief @brief This function will transmit a message to the PSI to change the MAC addres of the current VSI.
 *
 * @param VsiId   Index of the VSI which sends message.
 * @param MacAddr The new MAC which will be set.
 * @return Netc_Eth_Ip_StatusType
 * @internal
 */
static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_SendMsgFromVsiToPsi(uint8 VsiId, const uint8 *MacAddr);

/**
 * @brief Prepare to use a timeout.
 *
 * @param StartTimeOut Current value of selected counter.
 * @param ElapsedTimeOut Reset elapsed time to 0.
 * @param TimeoutTicksOut TimeoutUs converted from microsecond units to ticks units.
 * @param TimeoutUs Timeout value in microsecond.
 */
static inline void Netc_Eth_Ip_StartTimeOut(uint32 *StartTimeOut,
                                            uint32 *ElapsedTimeOut,
                                            uint32 *TimeoutTicksOut,
                                            uint32 TimeoutUs);

/**
 * @brief Checks for timeout expiration condition.
 *
 * @param StartTimeInOut Initial value of the counter.
 * @param ElapsedTimeInOut Current ticks passed.
 * @param TimeoutTicks Number of ticks after timout will be activated.
 *
 * @return boolean TRUE  - timout activated.
 *                 FALSE - timeout is not yet reached.
 */
static inline boolean Netc_Eth_Ip_TimeoutExpired(uint32 *StartTimeInOut,
                                                 uint32 *ElapsedTimeInOut,
                                                 uint32 TimeoutTicks);
/**
 * @brief Add MAC addr in the software table.
 *
 * @param CtrlIndex Index of the SI.
 * @param HashValue Computed hash value.
 * @param MacAddr   MAC address.
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                NETC_ETH_IP_STATUS_MAC_ADDR_TABLE_FULL - MAC table used for hash filter is full
 */
static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddMACFilterEntry(uint8 CtrlIndex, uint8 HashValue, const uint8 *MacAddr);

/**
 * @brief Compute has value for MAC addr.
 *
 * @param MacAddr MAC address.
 * @return uint8  Hash value for MacAddr.
 */
static inline uint8 Netc_Eth_Ip_ComputeMACHashValue(const uint8 *MacAddr);

/**
 * @brief Send message from the VSI to PSI.
 *
 * @param VsiId     Index of the VSI.
 * @param MsgAction Type of action. Description in types.
 * @param MacAddr   MAC address.
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                NETC_ETH_IP_STATUS_ERROR   - unsuccessfully operation
 *                                NETC_ETH_IP_STATUS_MAC_ADDR_TABLE_FULL - MAC table used for hash filter is full
 *                                NETC_ETH_IP_STATUS_TIMEOUT - Only for VSIs - the command was not processed in the allotted time
 *                                NETC_ETH_IP_STATUS_MAC_ADDR_NOT_FOUND - the current destination MAC was not
 *                                found in the hash filter table
 */
static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_VsiToPsiMsg(uint8 VsiId, \
                                                             Netc_Eth_Ip_VsiToPsiMsgActionType MsgAction, \
                                                             const uint8 *MacAddr);
/**
 * @brief Remove MAC addr in the software table.
 *
 * @param CtrlIndex Index of the SI.
 * @param HashValue Computed hash value.
 * @param MacAddr   MAC address.
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                NETC_ETH_IP_STATUS_ERROR   - unsuccessfully operation
 *                                NETC_ETH_IP_STATUS_MAC_ADDR_NOT_FOUND - the current destination MAC was not
 *                                found in the hash filter table
 */
static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_DeleteMACFilterEntry(const uint8 CtrlIndex, \
                                                                      const uint8 HashValue, \
                                                                      const uint8 *MacAddr);

/**
 * @brief Wait until the command is send from the VSI to the PSI.
 *
 * @param VsiId            Index of the SI.
 * @param MsgCommandConfig Message command.
 * @return Netc_Eth_Ip_StatusType NETC_ETH_IP_STATUS_SUCCESS - successfully operation
 *                                NETC_ETH_IP_STATUS_TIMEOUT - Only for VSIs - the command was not processed in the allotted time
 */
static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_WaitVsiToPsiMsgTransmission(uint8 VsiId, const Netc_Eth_Ip_VsiToPsiMsgType *MsgCommandConfig);
static uint8 Netc_Eth_Ip_CoalescingTxPacketsConversion (uint16 PacketsThreshold);
/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
static void Netc_Eth_Ip_GetCurrentTick(uint8 ctrlIndex, Netc_Eth_Ip_TimeType *TimePtr)
{
    uint32 NextLowNanoseconds;

    /* Read a nanosecond low register 2 times to check if it wrapped */
    (*TimePtr).nanosecondsL = (uint32)(netcSIsBase[ctrlIndex]->SICTR0);
    (*TimePtr).nanosecondsH = (uint32)(netcSIsBase[ctrlIndex]->SICTR1);
    NextLowNanoseconds      = (uint32)(netcSIsBase[ctrlIndex]->SICTR0);

    if ((*TimePtr).nanosecondsL >= NextLowNanoseconds)
    {
        (*TimePtr).nanosecondsH--;
    }
}

static inline void Netc_Eth_Ip_StartTimeOut(uint32 *StartTimeOut,
                                            uint32 *ElapsedTimeOut,
                                            uint32 *TimeoutTicksOut,
                                            uint32 TimeoutUs)
{
    *StartTimeOut    = OsIf_GetCounter(NETC_ETH_IP_TIMEOUT_TYPE);
    *ElapsedTimeOut  = 0U;
    *TimeoutTicksOut = OsIf_MicrosToTicks(TimeoutUs, NETC_ETH_IP_TIMEOUT_TYPE);
}

static inline boolean Netc_Eth_Ip_TimeoutExpired(uint32 *StartTimeInOut,
                                                 uint32 *ElapsedTimeInOut,
                                                 uint32 TimeoutTicks)
{
    *ElapsedTimeInOut += OsIf_GetElapsed(StartTimeInOut, NETC_ETH_IP_TIMEOUT_TYPE);

    return ((*ElapsedTimeInOut >= TimeoutTicks) ? TRUE : FALSE);
}

static void Netc_Eth_Ip_InitStateStructure(uint8 ctrlIndex, const Netc_Eth_Ip_ConfigType *config)
{
    uint8 u8RxBDIdx;
    uint8 u8TxBDIdx;
    uint32 currBDIdx;

    for (u8RxBDIdx = 0U; u8RxBDIdx < (*config->siConfig).NumberOfRxBDR; u8RxBDIdx++)
    {
        config->stateStructure->RxCurrentDesc[u8RxBDIdx]         = (*config->paCtrlRxRingConfig)[u8RxBDIdx].RingDesc;
        config->stateStructure->FirstRxRingDescAddr[u8RxBDIdx]   = (*config->paCtrlRxRingConfig)[u8RxBDIdx].RingDesc;
        config->stateStructure->RxRingSize[u8RxBDIdx]            = (*config->paCtrlRxRingConfig)[u8RxBDIdx].ringSize;
        config->stateStructure->rxCurrentIndex[u8RxBDIdx]        = 0U;
        config->stateStructure->FirstRxDataBufferAddr[u8RxBDIdx] = (*config->paCtrlRxRingConfig)[u8RxBDIdx].Buffer;
        config->stateStructure->RxDataBuffMaxLenAddr[u8RxBDIdx]  = (*config->paCtrlRxRingConfig)[u8RxBDIdx].maxBuffLen;
        config->stateStructure->RxCallback[u8RxBDIdx]            = (*config->paCtrlRxRingConfig)[u8RxBDIdx].Callback;
        /* If at least one controller has the Rx Interrupt coalesing enabled, then set the right threshold for all
        (0 if it is disabled, the configurated value if it is enabled).*/
        config->stateStructure->RxTimerThreshold[u8RxBDIdx]     = (*config->paCtrlRxRingConfig)[u8RxBDIdx].TimerThreshold;
        config->stateStructure->RxPacketsThreshold[u8RxBDIdx]     = (*config->paCtrlRxRingConfig)[u8RxBDIdx].PacketsThreshold;
    }

    for (u8TxBDIdx = 0U; u8TxBDIdx < (*config->siConfig).NumberOfTxBDR; u8TxBDIdx++)
    {
        config->stateStructure->LogicTxProducerIndex[u8TxBDIdx]     = 0U;
        config->stateStructure->lastTxDataBuffAddrIdx[u8TxBDIdx]    = 0U;
        config->stateStructure->TxNextDesc[u8TxBDIdx]               = (*config->paCtrlTxRingConfig)[u8TxBDIdx].RingDesc;
        config->stateStructure->FirstTxRingDescAddr[u8TxBDIdx]      = (*config->paCtrlTxRingConfig)[u8TxBDIdx].RingDesc;
        config->stateStructure->TxRingSize[u8TxBDIdx]               = (*config->paCtrlTxRingConfig)[u8TxBDIdx].ringSize;
        config->stateStructure->TxBufferLength[u8TxBDIdx]           = (*config->paCtrlTxRingConfig)[u8TxBDIdx].bufferLen;
        config->stateStructure->TxCallback[u8TxBDIdx]               = (*config->paCtrlTxRingConfig)[u8TxBDIdx].Callback;
        config->stateStructure->FirstTxDataBufferAddr[u8TxBDIdx] = (*config->paCtrlTxRingConfig)[u8TxBDIdx].Buffer;
        config->stateStructure->TxDataBuffMaxLenAddr[u8TxBDIdx]  = (*config->paCtrlTxRingConfig)[u8TxBDIdx].maxBuffLen;
        /* If at least one controller has the tx Interrupt coalesing enabled, then set the right threshold for all
        (0 if it is disabled, the configurated value if it is enabled).*/
        config->stateStructure->TxTimerThreshold[u8TxBDIdx]     = (*config->paCtrlTxRingConfig)[u8TxBDIdx].TimerThreshold;
        config->stateStructure->TxPacketsThreshold[u8TxBDIdx]     = (*config->paCtrlTxRingConfig)[u8TxBDIdx].PacketsThreshold;

        for (currBDIdx = 0; currBDIdx < (*config->paCtrlTxRingConfig)[u8TxBDIdx].ringSize; currBDIdx++)
        {
            config->stateStructure->LockTxBuffDescr[u8TxBDIdx][currBDIdx] = FALSE;
        }
    }
    /* Keep the interrupt setting for using information later. Per driver implementation the interrupts are enabled at controller level
    (either all rings or none have interrupts enabled)m we will check the first ring value configured. */
    config->stateStructure->RxInterrupts                    = (*config->siConfig).RxInterrupts;
    config->stateStructure->TxInterrupts                    = (*config->siConfig).TxInterrupts;
    config->stateStructure->VSItoPSIMsgCommand              = (*config->siConfig).VSItoPSIMsgCommand;
    config->stateStructure->NumberOfTxBDR                   = (*config->siConfig).NumberOfTxBDR;
    config->stateStructure->NumberOfRxBDR                   = (*config->siConfig).NumberOfRxBDR;
config->stateStructure->SiType                              = config->SiType;
    config->stateStructure->MACFilterTableMaxNumOfEntries   = (*config->siConfig).MACFilterTableMaxNumOfEntries;
    config->stateStructure->CtrlLogicalIndex                = (*config->siConfig).CtrlLogicalIndex;
#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
    config->stateStructure->RxDataBuffAddr  = (*config).rxExternalBuffersAddr;
#endif

    Netc_Eth_Ip_apxState[ctrlIndex] = config->stateStructure;
}

static void Netc_Eth_Ip_InitTxBD(uint8 ctrlIndex, const Netc_Eth_Ip_ConfigType *config)
{
    uint8  currentTxBDR;
    uint32 currBDIdx;
    Netc_Eth_Ip_TxBDRType *TempTxDescr;

    /* Loop through all the transmission rings used by the current controller. */
    for (currentTxBDR = 0U; currentTxBDR < (*config->siConfig).NumberOfTxBDR; currentTxBDR++)
    {
        /* Enable the queue and write the configured values for priority and weight */
        netcSIsBase[ctrlIndex]->BDR_NUM[currentTxBDR].TBMR = NETC_F3_SI0_TBMR_PRIO((*config->paCtrlTxRingConfig)[currentTxBDR].Priority) | \
                                        NETC_F3_SI0_TBMR_WRR((*config->paCtrlTxRingConfig)[currentTxBDR].Weight) | \
                                        NETC_F3_SI0_TBMR_EN_MASK;
        /* Initialize the producer and the consumer indexe with 0 value. */
        netcSIsBase[ctrlIndex]->BDR_NUM[currentTxBDR].TBPIR  = 0U;
        netcSIsBase[ctrlIndex]->BDR_NUM[currentTxBDR].TBCIR  = 0U;
        /* Write the length of the ring */
        netcSIsBase[ctrlIndex]->BDR_NUM[currentTxBDR].TBLENR = (*config->paCtrlTxRingConfig)[currentTxBDR].ringSize;
        /* Store the address of the first buffer descriptor in the current ring. */
        netcSIsBase[ctrlIndex]->BDR_NUM[currentTxBDR].TBBAR0 = (uint32)(*config->paCtrlTxRingConfig)[currentTxBDR].RingDesc;

        TempTxDescr = (*config->paCtrlTxRingConfig)[currentTxBDR].RingDesc;
        /* Loop through all descriptors of the ring. */
        for (currBDIdx = 0U; currBDIdx < (*config->paCtrlTxRingConfig)[currentTxBDR].ringSize; currBDIdx++)
        {
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
#ifdef NETC_ETH_0_USED
            if(((uint8)0U == ctrlIndex) && ((uint8)0U == currentTxBDR))
            {
                Netc_Eth_Ip_TxTimestampInfoBuff[ctrlIndex][currBDIdx].TxTimestampFlag = FALSE;
                Netc_Eth_Ip_TxTimestampInfoBuff[ctrlIndex][currBDIdx].TxTimeStampID   = (uint16)0xFFFFU;
                Netc_Eth_Ip_TxTimestampInfoBuff[ctrlIndex][currBDIdx].TxBuffId        = (uint16)0xFFFFU;
                Netc_Eth_Ip_TxTimestampInfoBuff[ctrlIndex][currBDIdx].PortIndex       = (uint8)0xFFU;
            }
#endif
#endif
#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_TX_BUFFERS)
            if (!Netc_Eth_Ip_ControllerHasExternalTxBufferManagement[ctrlIndex])
            {
#endif
                /* Write in the buffer descriptor the address of the allocated buffer */
                TempTxDescr->dataBuffAddr = (uint32)((*config->paCtrlTxRingConfig)[currentTxBDR].Buffer + \
                                                    (currBDIdx * (*config->paCtrlTxRingConfig)[currentTxBDR].maxBuffLen));
#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_TX_BUFFERS)
            }
#endif

#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
            /* Write in the buffer descriptor the extended bit */
            TempTxDescr->buffConfig = (NETC_ETH_IP_TXBD_FRAME_INTERRUPT_MASK | NETC_ETH_IP_TXBD_EXTENDED_BUFFER_MASK);
            TempTxDescr->extendBuffConfig = (NETC_ETH_IP_TXBD_FINAL_MASK & (~NETC_ETH_IP_TXBD_WRITEBACK_MASK));
#else
            /* For the last descriptor write the final flag */
            TempTxDescr->buffConfig = (NETC_ETH_IP_TXBD_FRAME_INTERRUPT_MASK | (NETC_ETH_IP_TXBD_FINAL_MASK & (~NETC_ETH_IP_TXBD_WRITEBACK_MASK)));
#endif
            TempTxDescr++;
        }
    }
}

static void Netc_Eth_Ip_InitRxBD(uint8 ctrlIndex, const Netc_Eth_Ip_ConfigType *config)
{
    uint8 u8RxBDIdx;
    uint32 DataBuffIndex;
    Netc_Eth_Ip_RxBDRType *pTempDescr;

    for (u8RxBDIdx = 0U; u8RxBDIdx < (*config->siConfig).NumberOfRxBDR; u8RxBDIdx++)
    {
        /* Enable the queue and enable the extended mode for it */
        netcSIsBase[ctrlIndex]->BDR_NUM[u8RxBDIdx].RBMR = NETC_F3_SI0_RBMR_EN_MASK;
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
        netcSIsBase[ctrlIndex]->BDR_NUM[u8RxBDIdx].RBMR |= NETC_F3_SI0_RBMR_BDS_MASK;
#endif
        /* Write the producer and consumer indexes with 0 */
        netcSIsBase[ctrlIndex]->BDR_NUM[u8RxBDIdx].RBPIR = 0U;
        netcSIsBase[ctrlIndex]->BDR_NUM[u8RxBDIdx].RBCIR = 0U;
        /* Write the length of the ring */
        netcSIsBase[ctrlIndex]->BDR_NUM[u8RxBDIdx].RBLENR = (*config->paCtrlRxRingConfig)[u8RxBDIdx].ringSize;
        /* Write in the transmission BDR register the address to the receive buffer descriptor. */
        netcSIsBase[ctrlIndex]->BDR_NUM[u8RxBDIdx].RBBAR0 = (uint32)(*config->paCtrlRxRingConfig)[u8RxBDIdx].RingDesc;
        /* Maximum size of the receive packet. Drop all packets with a bigger size. */
        netcSIsBase[ctrlIndex]->BDR_NUM[u8RxBDIdx].RBBSR = (*config->paCtrlRxRingConfig)[u8RxBDIdx].bufferLen;

#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
        if (!Netc_Eth_Ip_ControllerHasExternalRxBufferManagement[ctrlIndex])
        {
#endif
        pTempDescr = (*config->paCtrlRxRingConfig)[u8RxBDIdx].RingDesc;
        /* Loop through all descriptors of the queue */
        for (DataBuffIndex = 0U; DataBuffIndex < (*config->paCtrlRxRingConfig)[u8RxBDIdx].ringSize; DataBuffIndex++)
        {
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
            Netc_Eth_Ip_RxTimestampInfoBuff[ctrlIndex][u8RxBDIdx][DataBuffIndex].RingIdx         = (uint8)0xFF;
            Netc_Eth_Ip_RxTimestampInfoBuff[ctrlIndex][u8RxBDIdx][DataBuffIndex].ReceivedDataPtr = NULL_PTR;
            Netc_Eth_Ip_RxTimestampInfoBuff[ctrlIndex][u8RxBDIdx][DataBuffIndex].TimestampID     = (uint32)0U;
            Netc_Eth_Ip_RxTimestampInfoBuff[ctrlIndex][u8RxBDIdx][DataBuffIndex].TimestampValueInvalidForEth = (boolean)TRUE;
            Netc_Eth_Ip_RxTimestampInfoBuff[ctrlIndex][u8RxBDIdx][DataBuffIndex].TimestampValueInvalidForSwt = (boolean)TRUE;
#endif
            pTempDescr->configRxBD[0U] = (uint32)((*config->paCtrlRxRingConfig)[u8RxBDIdx].Buffer + \
                                                  (DataBuffIndex * (*config->paCtrlRxRingConfig)[u8RxBDIdx].maxBuffLen));
            pTempDescr++;
        }
#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
        }
#endif

    }
}

static void Netc_Eth_Ip_InitCBDR(uint8 ctrlIndex, const Netc_Eth_Ip_ConfigType *config)
{
    netcSIsBase[ctrlIndex]->SICBDRLENR = NETC_F3_SI0_SICBDRLENR_LENGTH((*config->siConfig).commandBDConfig.lengthCBDR);
    netcSIsBase[ctrlIndex]->SICBDRPIR  = NETC_F3_SI0_SICBDRPIR_BDR_INDEX(0U);
    netcSIsBase[ctrlIndex]->SICBDRCIR  = NETC_F3_SI0_SICBDRCIR_BDR_INDEX(0U);
    netcSIsBase[ctrlIndex]->SICBDRMR   = NETC_F3_SI0_SICBDRMR_EN_MASK;
}

void Netc_Eth_Ip_EnableIrq(uint8 ctrlIndex, const Netc_Eth_Ip_ConfigType *config)
{
    uint8 rxBDRIndex;
    uint8 txBDRIndex;
    Netc_Eth_Ip_MSITable *msiTableConfig;
    Netc_Eth_Ip_VfBaseType *VSIConfig;
    uint32* msiBaseAddr[] = NETC_ETH_IP_MSI_BASE_PTRS;
    NETC_F3_PCI_HDR_TYPE0_Type *PSIConfig = IP_NETC__NETC_F3_PCI_HDR_TYPE0;
    Netc_Eth_Ip_EnetcBaseType *enetcBase = IP_NETC__ENETC0_BASE;

    msiTableConfig = (Netc_Eth_Ip_MSITable *)msiBaseAddr[ctrlIndex];

    if (((*config->siConfig).RxInterrupts != 0U) || ((*config->siConfig).TxInterrupts != 0U))
    {
        /* Enable MSI-X for configured function(SI).This will let MSI-X to request service. */
        if (NETC_ETH_IP_PHYSICAL_SI == config->SiType)
        {
            PSIConfig->PCI_CFC_MSIX_MSG_CTL |= NETC_ETH_IP_MSI_MSG_CTL_ENABLE_MASK;
        }
        else
        {
            VSIConfig = netcVFBase[ctrlIndex];
            VSIConfig->PCI_CFC_MSIX_MSG_CTL |= NETC_ETH_IP_MSI_MSG_CTL_ENABLE_MASK;
        }

        /* Number of entries in a MSI table for the current SI. */
        enetcBase->NUM_SI[ctrlIndex].PSICFGR2 = NETC_ETH_IP_NUM_OF_ENTRIES_MSITABLE;

        if ((*config->siConfig).TxInterrupts != 0U)
        {
            msiTableConfig->msiTable[NETC_ETH_IP_TX_MSI_TABLE_INDEX].msgAddr       = (*config->siConfig).txMruMailboxAddr;
            msiTableConfig->msiTable[NETC_ETH_IP_TX_MSI_TABLE_INDEX].controlVector = 0x0U;
            msiTableConfig->msiTable[NETC_ETH_IP_TX_MSI_TABLE_INDEX].msgData       = 0xFFFFFFFFU;

            for (txBDRIndex = 0U; txBDRIndex < (*config->siConfig).NumberOfTxBDR; txBDRIndex++)
            {
                netcSIsBase[ctrlIndex]->SIMSITRVR[txBDRIndex] = NETC_ETH_IP_TX_MSI_TABLE_INDEX;
            }
        }

        if ((*config->siConfig).RxInterrupts != 0U)
        {
            msiTableConfig->msiTable[NETC_ETH_IP_RX_MSI_TABLE_INDEX].msgAddr       = (*config->siConfig).rxMruMailboxAddr;
            msiTableConfig->msiTable[NETC_ETH_IP_RX_MSI_TABLE_INDEX].controlVector = 0x0U;
            msiTableConfig->msiTable[NETC_ETH_IP_RX_MSI_TABLE_INDEX].msgData       = 0xFFFFFFFFU;

            for (rxBDRIndex = 0U; rxBDRIndex < (*config->siConfig).NumberOfRxBDR; rxBDRIndex++)
            {
                netcSIsBase[ctrlIndex]->BDR_NUM[rxBDRIndex].RBICR0 |= NETC_F3_SI0_RBICR0_ICPT(1U);
                netcSIsBase[ctrlIndex]->BDR_NUM[rxBDRIndex].RBICR0 |= NETC_F3_SI0_RBICR0_ICEN_MASK;
                netcSIsBase[ctrlIndex]->SIMSIRRVR[rxBDRIndex] = NETC_ETH_IP_RX_MSI_TABLE_INDEX;
            }
        }

        if ((NETC_ETH_IP_PHYSICAL_SI == config->SiType) &&
            ((*config->siConfig).siMsgMruMailboxAddr != NULL_PTR))
        {
            netcSIsBase[ctrlIndex]->INTERRUPT.PSI.PSIIER |= 0xFEU;
        }
    }


    if ((*config->siConfig).siMsgMruMailboxAddr != NULL_PTR)
    {
        msiTableConfig->msiTable[NETC_ETH_IP_SITOSI_MESSAGE_MSI_TABLE_INDEX].msgAddr       = (*config->siConfig).siMsgMruMailboxAddr;
        msiTableConfig->msiTable[NETC_ETH_IP_SITOSI_MESSAGE_MSI_TABLE_INDEX].controlVector = 0x0U;
        msiTableConfig->msiTable[NETC_ETH_IP_SITOSI_MESSAGE_MSI_TABLE_INDEX].msgData       = 0xFFFFFFFFU;

        if (NETC_ETH_IP_PHYSICAL_SI == config->SiType)
        {
            netcSIsBase[ctrlIndex]->INTERRUPT.PSI.PSIIER |= 0xFEU;
        }
    }

}

static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_SendMsgFromVsiToPsi(uint8 VsiId, const uint8 *MacAddr)
{
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_ERROR;
    Netc_Eth_Ip_VsiToPsiMsgType *MsgCommandConfig = Netc_Eth_Ip_apxState[VsiId]->VSItoPSIMsgCommand;

    /* Set class for command message. */
    MsgCommandConfig->Class   = (uint8)0U;
    MsgCommandConfig->Command = (uint8)0U;
    /* Set MAC address. */
    MsgCommandConfig->Data[0U] = (uint8)0U;
    MsgCommandConfig->Data[1U] = (uint8)0U;
    MsgCommandConfig->Data[2U] = MacAddr[0U];
    MsgCommandConfig->Data[3U] = MacAddr[1U];
    MsgCommandConfig->Data[4U] = MacAddr[2U];
    MsgCommandConfig->Data[5U] = MacAddr[3U];
    MsgCommandConfig->Data[6U] = MacAddr[4U];
    MsgCommandConfig->Data[7U] = MacAddr[5U];

    /* Set message command address(aligned at 64) and the size of it(6 bits code). */
    ((Netc_Eth_Ip_VsiBaseType*) netcSIsBase[VsiId])->MSGSR.VSI_A.VSIMSGSNDAR0 = ((uint32)MsgCommandConfig) | NETC_ETH_IP_VSITOPSI_MSG_SIZE;

    /* Wait until the message sent is processed by PSI. */
    Netc_Eth_Ip_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, NETC_ETH_IP_TIMEOUT_VALUE_US);
    do
    {
        /* Return the status of the message command. */
        if (NETC_ETH_IP_VSI_MSG_PROGRESS_STATUS != \
            (((Netc_Eth_Ip_VsiBaseType*) netcSIsBase[VsiId])->MSGSR.VSI_A.VSIMSGSR & NETC_ETH_IP_VSI_MSG_PROGRESS_STATUS))
        {
            Status = (Netc_Eth_Ip_StatusType)((uint16)(((Netc_Eth_Ip_VsiBaseType*) netcSIsBase[VsiId])->MSGSR.VSI_A.VSIMSGSR) & NETC_ETH_IP_VSI_MSG_STATUS);
            break;
        }
        else
        {
            Status = NETC_ETH_IP_STATUS_TIMEOUT;
        }
    }while(!Netc_Eth_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

    return Status;
}

static inline uint8 Netc_Eth_Ip_ComputeMACHashValue(const uint8 *MacAddr)
{
    uint8 HashValue = 0U;
    uint8 h0;
    uint8 h1;
    uint8 h2;
    uint8 h3;
    uint8 h4;
    uint8 h5;

    h0 = ((NETC_ETH_IP_BIT0_VALUE_FROM_BYTE(MacAddr[0U])) ^ \
         (NETC_ETH_IP_BIT6_VALUE_FROM_BYTE(MacAddr[0U])) ^ \
         (NETC_ETH_IP_BIT4_VALUE_FROM_BYTE(MacAddr[1U])) ^ \
         (NETC_ETH_IP_BIT2_VALUE_FROM_BYTE(MacAddr[2U])) ^ \
         (NETC_ETH_IP_BIT0_VALUE_FROM_BYTE(MacAddr[3U])) ^ \
         (NETC_ETH_IP_BIT6_VALUE_FROM_BYTE(MacAddr[3U])) ^ \
         (NETC_ETH_IP_BIT4_VALUE_FROM_BYTE(MacAddr[4U])) ^ \
         (NETC_ETH_IP_BIT2_VALUE_FROM_BYTE(MacAddr[5U])));

    h1 = ((NETC_ETH_IP_BIT1_VALUE_FROM_BYTE(MacAddr[0U])) ^ \
         (NETC_ETH_IP_BIT7_VALUE_FROM_BYTE(MacAddr[0U])) ^ \
         (NETC_ETH_IP_BIT5_VALUE_FROM_BYTE(MacAddr[1U])) ^ \
         (NETC_ETH_IP_BIT3_VALUE_FROM_BYTE(MacAddr[2U])) ^ \
         (NETC_ETH_IP_BIT1_VALUE_FROM_BYTE(MacAddr[3U])) ^ \
         (NETC_ETH_IP_BIT7_VALUE_FROM_BYTE(MacAddr[3U])) ^ \
         (NETC_ETH_IP_BIT5_VALUE_FROM_BYTE(MacAddr[4U])) ^ \
         (NETC_ETH_IP_BIT3_VALUE_FROM_BYTE(MacAddr[5U])));

    h2 = ((NETC_ETH_IP_BIT2_VALUE_FROM_BYTE(MacAddr[0U])) ^ \
         (NETC_ETH_IP_BIT0_VALUE_FROM_BYTE(MacAddr[1U])) ^ \
         (NETC_ETH_IP_BIT6_VALUE_FROM_BYTE(MacAddr[1U])) ^ \
         (NETC_ETH_IP_BIT4_VALUE_FROM_BYTE(MacAddr[2U])) ^ \
         (NETC_ETH_IP_BIT2_VALUE_FROM_BYTE(MacAddr[3U])) ^ \
         (NETC_ETH_IP_BIT0_VALUE_FROM_BYTE(MacAddr[4U])) ^ \
         (NETC_ETH_IP_BIT6_VALUE_FROM_BYTE(MacAddr[4U])) ^ \
         (NETC_ETH_IP_BIT4_VALUE_FROM_BYTE(MacAddr[5U])));

    h3 = ((NETC_ETH_IP_BIT3_VALUE_FROM_BYTE(MacAddr[0U])) ^ \
         (NETC_ETH_IP_BIT1_VALUE_FROM_BYTE(MacAddr[1U])) ^ \
         (NETC_ETH_IP_BIT7_VALUE_FROM_BYTE(MacAddr[1U])) ^ \
         (NETC_ETH_IP_BIT5_VALUE_FROM_BYTE(MacAddr[2U])) ^ \
         (NETC_ETH_IP_BIT3_VALUE_FROM_BYTE(MacAddr[3U])) ^ \
         (NETC_ETH_IP_BIT1_VALUE_FROM_BYTE(MacAddr[4U])) ^ \
         (NETC_ETH_IP_BIT7_VALUE_FROM_BYTE(MacAddr[4U])) ^ \
         (NETC_ETH_IP_BIT5_VALUE_FROM_BYTE(MacAddr[5U])));

    h4 = ((NETC_ETH_IP_BIT4_VALUE_FROM_BYTE(MacAddr[0U])) ^ \
         (NETC_ETH_IP_BIT2_VALUE_FROM_BYTE(MacAddr[1U])) ^ \
         (NETC_ETH_IP_BIT0_VALUE_FROM_BYTE(MacAddr[2U])) ^ \
         (NETC_ETH_IP_BIT6_VALUE_FROM_BYTE(MacAddr[2U])) ^ \
         (NETC_ETH_IP_BIT4_VALUE_FROM_BYTE(MacAddr[3U])) ^ \
         (NETC_ETH_IP_BIT2_VALUE_FROM_BYTE(MacAddr[4U])) ^ \
         (NETC_ETH_IP_BIT0_VALUE_FROM_BYTE(MacAddr[5U])) ^ \
         (NETC_ETH_IP_BIT6_VALUE_FROM_BYTE(MacAddr[5U])));

    h5 = ((NETC_ETH_IP_BIT5_VALUE_FROM_BYTE(MacAddr[0U])) ^ \
         (NETC_ETH_IP_BIT3_VALUE_FROM_BYTE(MacAddr[1U])) ^ \
         (NETC_ETH_IP_BIT1_VALUE_FROM_BYTE(MacAddr[2U])) ^ \
         (NETC_ETH_IP_BIT7_VALUE_FROM_BYTE(MacAddr[2U])) ^ \
         (NETC_ETH_IP_BIT5_VALUE_FROM_BYTE(MacAddr[3U])) ^ \
         (NETC_ETH_IP_BIT3_VALUE_FROM_BYTE(MacAddr[4U])) ^ \
         (NETC_ETH_IP_BIT1_VALUE_FROM_BYTE(MacAddr[5U])) ^ \
         (NETC_ETH_IP_BIT7_VALUE_FROM_BYTE(MacAddr[5U])));

    HashValue = (h5 << (uint8)5U) | (h4 << (uint8)4U) | (h3 << (uint8)3U) | (h2 << (uint8)2U) | (h1 << (uint8)1U) | h0;

    return HashValue;
}

static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_WaitVsiToPsiMsgTransmission(uint8 VsiId, const Netc_Eth_Ip_VsiToPsiMsgType *MsgCommandConfig)
{
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    Netc_Eth_Ip_StatusType Status;

    /* Set message command address(aligned at 64) and the size of it(6 bits code). */
    ((Netc_Eth_Ip_VsiBaseType*) netcSIsBase[VsiId])->MSGSR.VSI_A.VSIMSGSNDAR0 = ((uint32)MsgCommandConfig | NETC_ETH_IP_VSITOPSI_MSG_SIZE);

    /* Wait until the message sent is processed by PSI. */
    Netc_Eth_Ip_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, NETC_ETH_IP_TIMEOUT_VALUE_US);
    do
    {
        /* Return the status of the message command. */
        if (NETC_ETH_IP_VSI_MSG_PROGRESS_STATUS != \
            (((Netc_Eth_Ip_VsiBaseType*) netcSIsBase[VsiId])->MSGSR.VSI_A.VSIMSGSR & NETC_ETH_IP_VSI_MSG_PROGRESS_STATUS))
        {
            Status = (Netc_Eth_Ip_StatusType)((uint16)(((Netc_Eth_Ip_VsiBaseType*) netcSIsBase[VsiId])->MSGSR.VSI_A.VSIMSGSR) & NETC_ETH_IP_VSI_MSG_STATUS);
            break;
        }
        else
        {
            Status = NETC_ETH_IP_STATUS_TIMEOUT;
        }
    }while(!Netc_Eth_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

    return Status;
}

static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddMACFilterEntry(uint8 CtrlIndex, uint8 HashValue, const uint8 *MacAddr)
{
    uint8 CurrentEntry;
    uint8 CurrentMACByte;
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_MAC_ADDR_TABLE_FULL;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(NULL_PTR != Netc_Eth_Ip_apxState[CtrlIndex]);
#endif

    for(CurrentEntry = 0U; CurrentEntry < Netc_Eth_Ip_apxState[CtrlIndex]->MACFilterTableMaxNumOfEntries; CurrentEntry++)
    {
        if(FALSE == MACFilterHashTableAddrs[CtrlIndex][CurrentEntry].EntryStatus)
        {
            MACFilterHashTableAddrs[CtrlIndex][CurrentEntry].EntryStatus = TRUE;
            MACFilterHashTableAddrs[CtrlIndex][CurrentEntry].HashValue   = HashValue;
            for(CurrentMACByte = 0U; CurrentMACByte < NETC_ETH_IP_MAC_BYTES_SIZE;CurrentMACByte++)
            {
                MACFilterHashTableAddrs[CtrlIndex][CurrentEntry].MACAddr[CurrentMACByte] = MacAddr[CurrentMACByte];
            }
            Status = NETC_ETH_IP_STATUS_SUCCESS;
            break;
        }
    }
    return Status;
}

static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_DeleteMACFilterEntry(const uint8 CtrlIndex, const uint8 HashValue, const uint8 *MacAddr)
{
    uint8 MACBytesMached;
    uint8 CurrentEntry;
    Netc_Eth_Ip_StatusType Status;
    boolean MatchedEntry = FALSE;
    uint8 HashNumOfMatches = 0U;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(NULL_PTR != Netc_Eth_Ip_apxState[CtrlIndex]);
#endif

    for(CurrentEntry = 0U; CurrentEntry < Netc_Eth_Ip_apxState[CtrlIndex]->MACFilterTableMaxNumOfEntries; CurrentEntry++)
    {
        if  ((TRUE == MACFilterHashTableAddrs[CtrlIndex][CurrentEntry].EntryStatus) && \
             (HashValue == MACFilterHashTableAddrs[CtrlIndex][CurrentEntry].HashValue)
            )
        {
            HashNumOfMatches++;

            /* There will be one entry removed at a time. */
            if(MatchedEntry == FALSE)
            {
                MACBytesMached = 0U;
                while ( (MacAddr[MACBytesMached] == MACFilterHashTableAddrs[CtrlIndex][CurrentEntry].MACAddr[MACBytesMached]) && (MACBytesMached < NETC_ETH_IP_MAC_BYTES_SIZE) )
                {
                    MACBytesMached++;
                }

                if(NETC_ETH_IP_MAC_BYTES_SIZE == MACBytesMached)
                {
                    /* Provide data was matched. */
                    MatchedEntry = TRUE;
                    /* Mark entry as an empty slot. */
                    MACFilterHashTableAddrs[CtrlIndex][CurrentEntry].EntryStatus = FALSE;
                }
            }
        }
    }

    if(MatchedEntry)
    {
        if(1U == HashNumOfMatches)
        {
            Status = NETC_ETH_IP_STATUS_DELETE_MAC_ADDR;
        }
        else
        {
            Status = NETC_ETH_IP_STATUS_SUCCESS;
        }
    }
    else
    {
        Status = NETC_ETH_IP_STATUS_MAC_ADDR_NOT_FOUND;
    }

    return Status;
}

static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_VsiToPsiMsg(uint8 VsiId, \
                                                             Netc_Eth_Ip_VsiToPsiMsgActionType MsgAction, \
                                                             const uint8 *MacAddr)
{
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_ERROR;
    Netc_Eth_Ip_VsiToPsiMsgType *MsgCommandConfig = Netc_Eth_Ip_apxState[VsiId]->VSItoPSIMsgCommand;

    switch (MsgAction)
    {
        case NETC_ETH_IP_VSITOPSI_MAC_ADDR_SET:
        {
            /* Set class for command message. */
            MsgCommandConfig->Class   = (uint8)0U;
            MsgCommandConfig->Command = (uint8)0U;
            /* Set MAC address. */
            MsgCommandConfig->Data[0U] = (uint8)0U;
            MsgCommandConfig->Data[1U] = (uint8)0U;
            MsgCommandConfig->Data[2U] = MacAddr[0U];
            MsgCommandConfig->Data[3U] = MacAddr[1U];
            MsgCommandConfig->Data[4U] = MacAddr[2U];
            MsgCommandConfig->Data[5U] = MacAddr[3U];
            MsgCommandConfig->Data[6U] = MacAddr[4U];
            MsgCommandConfig->Data[7U] = MacAddr[5u];
            Status = Netc_Eth_Ip_WaitVsiToPsiMsgTransmission(VsiId, MsgCommandConfig);
            break;
        }
        case NETC_ETH_IP_VSITOPSI_ADD_RX_MAC_ADDR_FILTER:
        {
            /* Set class for command message. */
            MsgCommandConfig->Class   = (uint8)1U;
            MsgCommandConfig->Command = (uint8)0U;
            /* Compute the hash value for the MAC address. */
            MsgCommandConfig->Data[0U] = Netc_Eth_Ip_ComputeMACHashValue(MacAddr);
            MsgCommandConfig->Data[1U] = (uint8)0U;
            /* Exact match(EM) will be deactivated when hash table is used. */
            MsgCommandConfig->Data[2U] = (uint8)0U;

            Status = Netc_Eth_Ip_AddMACFilterEntry(VsiId, MsgCommandConfig->Data[0U], MacAddr);

            if(NETC_ETH_IP_STATUS_SUCCESS == Status)
            {
                Status = Netc_Eth_Ip_WaitVsiToPsiMsgTransmission(VsiId, MsgCommandConfig);
            }
            break;
        }
        case NETC_ETH_IP_VSITOPSI_DELETE_RX_MAC_ADDR_FILTER:
        {
            /* Compute the hash value for the MAC address. */
            MsgCommandConfig->Data[0U] = Netc_Eth_Ip_ComputeMACHashValue(MacAddr);
            Status = Netc_Eth_Ip_DeleteMACFilterEntry(VsiId, MsgCommandConfig->Data[0U], MacAddr);

            if(NETC_ETH_IP_STATUS_DELETE_MAC_ADDR == Status)
            {
                /* Set class for command message. */
                MsgCommandConfig->Class   = (uint8)1U;
                MsgCommandConfig->Command = (uint8)1U;
                MsgCommandConfig->Data[1U] = (uint8)0U;
                /* Exact match(EM) will be deactivated when hash table is used. */
                MsgCommandConfig->Data[2U] = (uint8)0U;
                Status = Netc_Eth_Ip_WaitVsiToPsiMsgTransmission(VsiId, MsgCommandConfig);
            }

            break;
        }
        case NETC_ETH_IP_VSITOPSI_ENABLE_MULTICAST:
        {
            /* Set class for command message. */
            MsgCommandConfig->Class   = (uint8)0x10U;
            MsgCommandConfig->Command = (uint8)0x00U;
            Status = Netc_Eth_Ip_WaitVsiToPsiMsgTransmission(VsiId, MsgCommandConfig);
            break;
        }
        case NETC_ETH_IP_VSITOPSI_DISABLE_MULTICAST:
        {
            /* Set class for command message. */
            MsgCommandConfig->Class   = (uint8)0x10U;
            MsgCommandConfig->Command = (uint8)0x10U;
            Status = Netc_Eth_Ip_WaitVsiToPsiMsgTransmission(VsiId, MsgCommandConfig);
            break;
        }
        case NETC_ETH_IP_VSITOPSI_CLOSE_FILTER:
        {
            /* Set class for command message. */
            MsgCommandConfig->Class   = (uint8)0x10U;
            MsgCommandConfig->Command = (uint8)0x20U;
            Status = Netc_Eth_Ip_WaitVsiToPsiMsgTransmission(VsiId, MsgCommandConfig);
            break;
        }
        default:
        {
            Status = NETC_ETH_IP_STATUS_UNSUPPORTED;
            break;
        }
    }

    return Status;
}

static uint8 Netc_Eth_Ip_CoalescingTxPacketsConversion (uint16 PacketsThreshold)
{
    uint16 RegVal = 1U;
    uint8 TwoPow = 0;

    for(TwoPow = 1U; TwoPow < 16U; TwoPow++)
    {
        RegVal *= 2U;

        if (RegVal > PacketsThreshold)
        {
            break;
        }
    }

    return TwoPow;
}
/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_Init
 * implements     Netc_Eth_Ip_Init_Activity 
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_Init(uint8 ctrlIndex, const Netc_Eth_Ip_ConfigType *config)
{
    uint8  u8Iterator;
    uint8  siHwId;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;

    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_SUCCESS;
#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
    const Netc_Eth_Ip_GeneralSIConfigType *SiConfig;
#endif

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(config != NULL_PTR);
#endif

    if (NETC_ETH_IP_PHYSICAL_SI == config->SiType)
    {
        /* Use generalConfig to configure the general part of NETC */

        /* Enable function to master memory transaction requests and enable function to respond to memory space accesses (register accesses).
            Setting this bit may trigger the locking of IERB registers if not already done either explicitly through the NETCRR[LOCK] bit,
            or an earlier function initializing. Setting memory access enable will load IERB register values into the function and start any
            initialization of local table memory.
            Poll OSR[STATE] bit and wait for 0b0 before continuing device configuration.
        */
        IP_NETC__NETC_F3_PCI_HDR_TYPE0->PCI_CFH_CMD = NETC_F3_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN(1U) | NETC_F3_PCI_HDR_TYPE0_PCI_CFH_CMD_MEM_ACCESS(1U);

        /* Enable the VFs;Enable memory space for VFs */
        IP_NETC__NETC_F3_PCI_HDR_TYPE0->PCIE_CFC_SRIOV_CTL |= NETC_F3_PCI_HDR_TYPE0_PCIE_CFC_SRIOV_CTL_VF_ENABLE_MASK | \
                                                              NETC_F3_PCI_HDR_TYPE0_PCIE_CFC_SRIOV_CTL_VF_MSE_MASK;

        /* Wait for a successfully ENETC init. */
        Netc_Eth_Ip_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, NETC_ETH_IP_TIMEOUT_VALUE_US);
        do
        {
            if(NETC_F3_COMMON_OSR_STATE_MASK != (IP_NETC__ENETC0_COMMON->OSR & NETC_F3_COMMON_OSR_STATE_MASK))
            {
                Status = NETC_ETH_IP_STATUS_SUCCESS;
                break;
            }
            else
            {
                Status = NETC_ETH_IP_STATUS_TIMEOUT;
            }
        }while(!Netc_Eth_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

        /** TODO: This will be supported later. */
        /* Configure the number of MSIs for all SIs - Port station interface a configuration register 2 (PSI0CFGR2 - PSI7CFGR2) */

        /* Enable/disable MAC multicast/unicast promiscuous mode. */
        IP_NETC__ENETC0_BASE->PSIPMMR = ((uint32)((*config->generalConfig).maskMACPromiscuousMulticastEnable) << NETC_F3_PSIPMMR_SI0_MAC_MP_SHIFT) | \
                                        (uint32)((*config->generalConfig).maskMACPromiscuousUnicastEnable);

#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
        /* Configure for Custom VLAN Ethertype 1 */
        IP_NETC__ENETC0_COMMON->CVLANR1 = config->generalConfig->CustomVlanEthertype1;
        /* Configure for Custom VLAN Ethertype 2 */
        IP_NETC__ENETC0_COMMON->CVLANR2 = config->generalConfig->CustomVlanEthertype2;
#endif

        /* Configure the VSIs using config->generalConfig */
        for (u8Iterator = 0U; u8Iterator < (*config->generalConfig).numberOfConfiguredSis; u8Iterator++)
        {
            /* Identify the PSI in the list of SIs to configure */
            siHwId = (*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].siId;

            /* Enable PSI; In reset configuration PSI is already started, but to be sure that will not be any problems. */
            if (TRUE == (*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].enableSi)
            {
                /** Assure that SI is not enabled. */
                netcSIsBase[siHwId]->SIMR &= ~(NETC_F3_SI0_SIMR_EN_MASK);

                if (ctrlIndex == siHwId)
                {
                    /* Master enable for a station interface.*/
                    IP_NETC__ENETC0_BASE->PMR = IP_NETC__ENETC0_BASE->PMR | (NETC_F3_PMR_SI0EN_MASK << siHwId);

                    /* For the PSI the MAC address will be configured both for the ENETC Port and for the PSI0 */
                    /* Configure the port primary MAC address */
                    IP_NETC__ENETC0_PORT->PMAR0 = (*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].primaryMACAddress[0U]          | \
                                                  ((*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].primaryMACAddress[1U] << 8U)  | \
                                                  ((*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].primaryMACAddress[2U] << 16U) | \
                                                  ((*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].primaryMACAddress[3U] << 24U);
                    IP_NETC__ENETC0_PORT->PMAR1 = (*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].primaryMACAddress[4U] | \
                                                  ((*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].primaryMACAddress[5U] << 8U);
                }
                else
                {

                    /* Master enable for a station interface.*/
                    IP_NETC__ENETC0_BASE->PMR = IP_NETC__ENETC0_BASE->PMR | (NETC_F3_PMR_SI0EN_MASK << siHwId);

                    /* For the VSIs write the MAC address in the PSIaMAR0 and PSIaMAR1 registers */
                    IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSIPMAR0 = ((uint32)(*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].primaryMACAddress[0U])          | \
                                                                    (((uint32)(*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].primaryMACAddress[1U]) << 8U)  | \
                                                                    (((uint32)(*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].primaryMACAddress[2U]) << 16U) | \
                                                                    (((uint32)(*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].primaryMACAddress[3U]) << 24U);

                    IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSIPMAR1 = ((uint32)(*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].primaryMACAddress[4U]) | \
                                                                    (((uint32)(*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].primaryMACAddress[5U] )<< 8U);
                    /* Configure where the PSI receives the message for enabled VSIs. */
                    if(NULL_PTR != config->generalConfig->RxVsiMsgCmdToPsi[siHwId - 1U])
                    {
                        IP_NETC__ENETC0_SI0->MSGSR.PSI_A.VSI_NUM[siHwId - 1U].PSIVMSGRCVAR0 = (uint32)config->generalConfig->RxVsiMsgCmdToPsi[siHwId - 1U] | \
                                                                                              NETC_ETH_IP_VSITOPSI_MSG_SIZE;
                    }
                }

                /* Configure the number or TX and RX BD Rings for each SI */
                IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSICFGR0 &= ~(NETC_F3_PSICFGR0_NUM_TX_BDR_MASK | NETC_F3_PSICFGR0_NUM_RX_BDR_MASK);

                IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSICFGR0 |= NETC_F3_PSICFGR0_NUM_TX_BDR((*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].NumberOfTxBDR) | \
                                                                 NETC_F3_PSICFGR0_NUM_RX_BDR((*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].NumberOfRxBDR);
                if (ctrlIndex != siHwId)
                {
                    /* Enable bus for virtual function. */
                    netcVFBase[u8Iterator]->PCI_CFH_CMD |= NETC_VF1_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN(1U);
                }

#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
                SiConfig = config->generalConfig->stationInterfaceGeneralConfig[u8Iterator];

                if (TRUE == SiConfig->EnableSIVlan)
                {
                    /* Enable VLAN and select tag protocol, priority code point, drop eligible indicator and VLAN identifier */
                    IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSIVLANR = NETC_F3_PSIVLANR_TPID(SiConfig->SiVLANConfig.ProtocolIdentifier) |
                                                                    NETC_F3_PSIVLANR_PCP(SiConfig->SiVLANConfig.PriorityCodePoint) |
                                                                    NETC_F3_PSIVLANR_VID(SiConfig->SiVLANConfig.VlanIdentifier) |
                                                                    NETC_F3_PSIVLANR_E(1U) | NETC_F3_PSIVLANR_DEI((uint8)SiConfig->SiVLANConfig.DropIndicator);
                }
                else
                {
                    /* Disable VLAN and select tag protocol */
                    IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSIVLANR &= ~NETC_F3_PSIVLANR_E(1U);
                }

                IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSICFGR0 &= ~(NETC_F3_PSICFGR0_SIVC_MASK | NETC_F3_PSICFGR0_SIVIE_MASK | NETC_F3_PSICFGR0_VTE_MASK);
                /* Insert VLAN Ethertype and enable insertion of the SI-based VLAN into frames sent by this SI. This config apply for generic */
                IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSICFGR0 |= NETC_F3_PSICFGR0_SIVC(SiConfig->SIVlanControl) |
                                                                 NETC_F3_PSICFGR0_SIVIE((uint8)SiConfig->EnableSoftwareVlanInsert) |
                                                                 NETC_F3_PSICFGR0_VTE((SiConfig->EnableVLANTagExtract) ? 1U : 0U); ;
#endif

                IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSICFGR0 |= NETC_F3_PSICFGR0_ASE(((*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].enableAntiSpoofing) ? 1U : 0U);
            }
        }

        /** TODO: Advanced feature configuration. TBA later. */
        /* Configure the number of MAC and VLAN filter entries for all SIs - Port station interface 0 VSI MAC address filtering configuration register (PSI0VMAFCFGR) and
                                                                             Port station interface 0 VLAN filtering configuration register (PSI0VLANFCFGR)
                                                                             Port station interface a VSI MAC address filtering configuration register (PSI1VMAFCFGR - PSI7VMAFCFGR) and
                                                                             Port station interface a VLAN filtering configuration register (PSI1VLANFCFGR - PSI7VLANFCFGR)*/
        /* Configure the internal priority to ICM priority mapping - Receive IPV to ICM priority mapping register 0 (IPV2ICMPMR0) */
        /* Configure the IPV to traffic class assignment - Transmit priority to traffic class mapping register 0 (PRIO2TCMR0) */
        /* Configure speed and other settings in Port configuration register (PCR) */
    }
    else
    {
        /* Wait until PSI start current VSI. */
        Netc_Eth_Ip_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, NETC_ETH_IP_TIMEOUT_VALUE_US);
        do
        {
            if (NETC_VF1_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN_MASK == \
                ((netcVFBase[ctrlIndex]->PCI_CFH_CMD & NETC_VF1_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN_MASK)))
            {
                Status = NETC_ETH_IP_STATUS_SUCCESS;
                break;
            }
            else
            {
                Status = NETC_ETH_IP_STATUS_TIMEOUT;
            }
        }while(!Netc_Eth_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));
    }

    /* Added to be sure this is not executed when VSI get a timeout. */
    if(NETC_ETH_IP_STATUS_SUCCESS == Status)
    {
#if (NETC_ETH_IP_VLAN_SUPPORT == STD_ON)
        /** TODO: To be configured later when with al VLAN configurations. */
        /* Configure VLAN to IPV - Station interface VLAN to IPV mapping register 0 (SIVLANIPVMR0) and Station interface VLAN to IPV mapping register 1 (SIVLANIPVMR1) */
        /* Configure IPV to BDR - Station interface IPV to ring mapping register (SIIPVBDRMR0) */
#endif
        /* Configure Command ring */
        Netc_Eth_Ip_InitCBDR(ctrlIndex, config);
        /* Initialize TX BDRs */
        Netc_Eth_Ip_InitTxBD(ctrlIndex, config);
        /* Initialize RX BDRs */
        Netc_Eth_Ip_InitRxBD(ctrlIndex, config);
        /* Initialize State structure */
        Netc_Eth_Ip_InitStateStructure(ctrlIndex, config);
        /* Check if any interrupt is enabled and configure the hardware */
         if (((*config->siConfig).siMsgMruMailboxAddr != NULL_PTR) ||
             ((*config->siConfig).TxInterrupts != 0U) ||
             ((*config->siConfig).RxInterrupts != 0U))
        {
            /* Enable interrupts for the current controller. */
            Netc_Eth_Ip_EnableIrq(ctrlIndex, config);
        }
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_EnableController
 * implements     Netc_Eth_Ip_EnableController_Activity 
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_EnableController(uint8 ctrlIndex)
{
    uint8 ringCounter = 0U;
    /* Assumption: If the Coalescing ISR is enabled on the ctrlIndex, it means all the rings will have the ISR enabled.
    Context: If at least one controller has the Tx Coalesing Isr Enabled, TxCoalescingIsrEnabled will be true if the generated thresholds will not be 0. */
    boolean TxCoalescingIsrEnabled =  ((Netc_Eth_Ip_apxState[ctrlIndex]->TxTimerThreshold[0U] != 0U) &&
                                       (Netc_Eth_Ip_apxState[ctrlIndex]->TxPacketsThreshold[0U] != 0U)) ? TRUE : FALSE ;
    boolean RxCoalescingIsrEnabled =  ((Netc_Eth_Ip_apxState[ctrlIndex]->RxTimerThreshold[0U] != 0U) &&
                                       (Netc_Eth_Ip_apxState[ctrlIndex]->RxPacketsThreshold[0U] != 0U)) ? TRUE : FALSE ;
#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(Netc_Eth_Ip_apxState[ctrlIndex] != NULL_PTR);
#endif
    if ( Netc_Eth_Ip_apxState[ctrlIndex]->RxInterrupts != 0U)
    {
        /* Tx and Rx Interrupts enabled*/
        for (ringCounter = 0U; ringCounter < Netc_Eth_Ip_apxState[ctrlIndex]->NumberOfRxBDR; ringCounter++)
        {
            /* Write the interrupt settings as configured */
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].RBIER  |= (uint32)1U;
            if (RxCoalescingIsrEnabled)
            {
                /*If timer threshold is used it should be set when RBaICR0[ICEN]=0 to avoid missing a "first packet" received condition which starts the timer.*/
                netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].RBICR1 |= NETC_F3_SI0_RBICR1_ICTT( Netc_Eth_Ip_apxState[ctrlIndex]->RxTimerThreshold[ringCounter]);
                netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].RBICR0 |= NETC_F3_SI0_RBICR0_ICPT(Netc_Eth_Ip_apxState[ctrlIndex]->RxPacketsThreshold[ringCounter]);
                netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].RBICR0 |= NETC_F3_SI0_RBICR0_ICEN(1U);
            }
        }
    }
    if ( Netc_Eth_Ip_apxState[ctrlIndex]->TxInterrupts != 0U)
    {
        for (ringCounter = 0U; ringCounter < Netc_Eth_Ip_apxState[ctrlIndex]->NumberOfTxBDR; ringCounter++)
        {

            if (TxCoalescingIsrEnabled)
            {
                netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].TBIER  = NETC_F3_SI0_TBIER_TXTIE(1U);
                /*If timer threshold is used it should be set when TBaICR0[ICEN]=0 to avoid missing a "firstpacket" transmitted condition which starts the timer.*/
                netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].TBICR1 |= NETC_F3_SI0_TBICR1_ICTT( Netc_Eth_Ip_apxState[ctrlIndex]->TxTimerThreshold[ringCounter]);
                /*If packet threshold is used it should be set when TBaICR0[ICEN] is set */
                netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].TBICR0 |= (NETC_F3_SI0_TBICR0_ICEN(1U) | NETC_F3_SI0_TBICR0_ICPT(Netc_Eth_Ip_apxState[ctrlIndex]->TxPacketsThreshold[ringCounter]));
            }
            else
            {
                netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].TBIER  = NETC_F3_SI0_TBIER_TXFIE(1U);
            }
        }
    }

    /* Set the EN bit in Station interface mode register (SIMR) */
    netcSIsBase[ctrlIndex]->SIMR |= NETC_F3_SI0_SIMR_EN_MASK;

    return NETC_ETH_IP_STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_DisableController
 * implements     Netc_Eth_Ip_DisableController_Activity 
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_DisableController(uint8 ctrlIndex)
{
    uint32 ringCounter = 0U;
    uint32 currBDIdx = 0U;
    Netc_Eth_Ip_TxBDRType *txTmpBDR;
    Netc_Eth_Ip_RxBDRType *rxTmpBDR;
    boolean isPendingRing = FALSE;
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_ERROR;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(Netc_Eth_Ip_apxState[ctrlIndex] != NULL_PTR);
#endif

    /* Check whether any transmit pending ring haven been consumed before disable the SI */
    for (ringCounter = 0U; ringCounter < Netc_Eth_Ip_apxState[ctrlIndex]->NumberOfTxBDR; ringCounter++)
    {
        if (netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].TBPIR != netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].TBCIR)
        {
            isPendingRing = TRUE;
            break;
        }
    }

    if (isPendingRing == FALSE)
    {
        /* Clear the EN bit in Station interface mode register (SIMR) */
        netcSIsBase[ctrlIndex]->SIMR &= ~NETC_F3_SI0_SIMR_EN_MASK;

        /* Restore all information related with the TX operations. */
        /* Loop through all the configured transmission rings */
        for (ringCounter = 0U; ringCounter < Netc_Eth_Ip_apxState[ctrlIndex]->NumberOfTxBDR; ringCounter++)
        {
            /* Write the interrupt settings as configured */
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].TBIER &= ~NETC_F3_SI0_TBIER_TXTIE_MASK;
            /* Reset producer and consumer indexes. */
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].TBPIR = 0U;
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].TBCIR = 0U;
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].TBICR0 &= ~NETC_F3_SI0_TBICR0_ICEN_MASK;
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].TBIER  &= ~NETC_F3_SI0_TBIER_TXFIE_MASK;
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].TBICR1 &= ~NETC_F3_SI0_TBICR1_ICTT_MASK;
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].TBICR0 &= ~NETC_F3_SI0_TBICR0_ICPT_MASK;

            txTmpBDR = Netc_Eth_Ip_apxState[ctrlIndex]->FirstTxRingDescAddr[ringCounter];
            /* Loop through all descriptors of the ring. */
            for (currBDIdx = 0U; currBDIdx < Netc_Eth_Ip_apxState[ctrlIndex]->TxRingSize[ringCounter]; currBDIdx++)
            {
    #if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
                /* Write in the buffer descriptor the extended bit */
                txTmpBDR->buffConfig |= NETC_ETH_IP_TXBD_EXTENDED_BUFFER_MASK;
                txTmpBDR->extendBuffConfig |= (NETC_ETH_IP_TXBD_FINAL_MASK & (~NETC_ETH_IP_TXBD_WRITEBACK_MASK));
    #else
                /* For the last descriptor write the final flag */
                txTmpBDR->buffConfig |= (NETC_ETH_IP_TXBD_FINAL_MASK & (~NETC_ETH_IP_TXBD_WRITEBACK_MASK));
    #endif
                txTmpBDR++;

                /* Reset TX state variable realted to each descriptor. */
                Netc_Eth_Ip_apxState[ctrlIndex]->LockTxBuffDescr[ringCounter][currBDIdx] = FALSE;
            }

            /* Reset TX state variable realted to each ring. */
            Netc_Eth_Ip_apxState[ctrlIndex]->TxNextDesc[ringCounter]    = Netc_Eth_Ip_apxState[ctrlIndex]->FirstTxRingDescAddr[ringCounter];
            Netc_Eth_Ip_apxState[ctrlIndex]->LogicTxProducerIndex[ringCounter] = 0U;
            Netc_Eth_Ip_apxState[ctrlIndex]->LogicRxConsumerIndex[ringCounter] = 0U;
            Netc_Eth_Ip_apxState[ctrlIndex]->lastTxDataBuffAddrIdx[ringCounter] = 0U;
        }

        /* Restore all information related with the RX operations. */
        for (ringCounter = 0U; ringCounter < Netc_Eth_Ip_apxState[ctrlIndex]->NumberOfRxBDR; ringCounter++)
        {
            /* Write the interrupt settings as configured */
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].RBIER &= ~NETC_F3_SI0_RBIER_RXTIE_MASK;
            /* Write the producer and consumer indexes with 0 */
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].RBPIR = 0U;
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].RBCIR = 0U;
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].RBICR0 &= ~NETC_F3_SI0_RBICR0_ICEN_MASK;
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].RBICR1 &= ~NETC_F3_SI0_RBICR1_ICTT_MASK;
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].RBICR0 &= ~NETC_F3_SI0_RBICR0_ICPT_MASK;
            rxTmpBDR = Netc_Eth_Ip_apxState[ctrlIndex]->FirstRxRingDescAddr[ringCounter];
            /* Loop through all descriptors of the queue */
            for (currBDIdx = 0U; currBDIdx < Netc_Eth_Ip_apxState[ctrlIndex]->RxRingSize[ringCounter]; currBDIdx++)
            {
    #if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
            if (!Netc_Eth_Ip_ControllerHasExternalRxBufferManagement[ctrlIndex])
            {
    #endif
                rxTmpBDR->configRxBD[0U] = (uint32)(Netc_Eth_Ip_apxState[ctrlIndex]->FirstRxDataBufferAddr[ringCounter] + \
                                                    (currBDIdx * Netc_Eth_Ip_apxState[ctrlIndex]->RxDataBuffMaxLenAddr[ringCounter]));
    #if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
            }
    #endif
                rxTmpBDR->configRxBD[1U] = 0U;
                rxTmpBDR->configRxBD[2U] = 0U;
                rxTmpBDR->configRxBD[3U] = 0U;
    #if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
                rxTmpBDR->extendConfigRxBD[0U] = 0U;
                rxTmpBDR->extendConfigRxBD[1U] = 0U;
                rxTmpBDR->extendConfigRxBD[2U] = 0U;
                rxTmpBDR->extendConfigRxBD[3U] = 0U;
    #endif
                rxTmpBDR++;
            }

            /* Reset RX state variable realted to each ring. */
            Netc_Eth_Ip_apxState[ctrlIndex]->RxCurrentDesc[ringCounter]  = Netc_Eth_Ip_apxState[ctrlIndex]->FirstRxRingDescAddr[ringCounter];
            Netc_Eth_Ip_apxState[ctrlIndex]->rxCurrentIndex[ringCounter] = 0U;
        }

        Status = NETC_ETH_IP_STATUS_SUCCESS;
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_GetTxBuff
 * implements     Netc_Eth_Ip_GetTxBuff_Activity 
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetTxBuff(uint8 ctrlIndex,
                                             uint8 ring,
                                             Netc_Eth_Ip_BufferType *buff,
                                             uint16 *buffId)
{
    uint32 nextProducerIdx;
    uint32 currProducerIdx;
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;
    boolean producerIdxOvf = FALSE;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(Netc_Eth_Ip_apxState[ctrlIndex] != NULL_PTR);
    DevAssert(ring < Netc_Eth_Ip_apxState[ctrlIndex]->NumberOfTxBDR);
    DevAssert(buff != NULL_PTR);
#endif

    currProducerIdx = Netc_Eth_Ip_apxState[ctrlIndex]->LogicTxProducerIndex[ring];

    /* Get the next producer index and the overflow status for producer counter. */
    nextProducerIdx = currProducerIdx + NETC_ETH_IP_PRODUCER_INCR;
    if (nextProducerIdx >= (uint32)Netc_Eth_Ip_apxState[ctrlIndex]->TxRingSize[ring])
    {
        nextProducerIdx = 0U;
        producerIdxOvf  = TRUE;
    }

    /* Test frame length */
    if (buff->length < NETC_ETH_IP_MIN_FRAME_LENGTH)
    {
        status = NETC_ETH_IP_STATUS_INVALID_FRAME_LENGTH;
    }
    /* ATTENTION! This mechanism is implemented to be sure that producer index will NOT be equal with the consumer index. */
    else if(nextProducerIdx == Netc_Eth_Ip_apxState[ctrlIndex]->lastTxDataBuffAddrIdx[ring])
    {
        status = NETC_ETH_IP_STATUS_TX_BUFF_BUSY;
    }
    else
    {
        if (buff->length > Netc_Eth_Ip_apxState[ctrlIndex]->TxBufferLength[ring])
        {
            status = NETC_ETH_IP_STATUS_TX_BUFF_OVERFLOW;
            buff->length = (uint16)(Netc_Eth_Ip_apxState[ctrlIndex]->TxBufferLength[ring]);
        }
        else
        {
#if (NETC_ETH_IP_HAS_EXTERNAL_TX_BUFFERS == STD_ON)
            if (!Netc_Eth_Ip_ControllerHasExternalTxBufferManagement[ctrlIndex])
            {
#endif
                buff->data = (uint8*) (Netc_Eth_Ip_apxState[ctrlIndex]->FirstTxDataBufferAddr[ring] + \
                                      (currProducerIdx * Netc_Eth_Ip_apxState[ctrlIndex]->TxDataBuffMaxLenAddr[ring]));
#if (NETC_ETH_IP_HAS_EXTERNAL_TX_BUFFERS == STD_ON)
            }
#endif
            /* If used, return the buffer index */
            if (buffId != NULL_PTR)
            {
                *buffId = (uint16)(currProducerIdx);
            }

            /* To check if we have to go to the next descriptor in GetTxBuff */
            if (FALSE == producerIdxOvf)
            {
                Netc_Eth_Ip_apxState[ctrlIndex]->TxNextDesc[ring]++;
            }
            else
            {
                /* Wrap around if you get to the end of the list and start again from the first descriptor. */
                Netc_Eth_Ip_apxState[ctrlIndex]->TxNextDesc[ring] = Netc_Eth_Ip_apxState[ctrlIndex]->FirstTxRingDescAddr[ring];
            }
            /* Marked the data buff as used. */
            Netc_Eth_Ip_apxState[ctrlIndex]->LockTxBuffDescr[ring][currProducerIdx] = TRUE;
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_GetTxMultiBuff
 * implements     Netc_Eth_Ip_GetTxMultiBuff_Activity 
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetTxMultiBuff(uint8 ctrlIndex,
                                                  uint8 ring,
                                                  uint16 NumBuffers,
                                                  const uint16 BufferLength[],
                                                  uint16 *buffId)
{
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_SUCCESS;
    uint32 ProducerIndex;
    uint32 NextProducerIndex;
    uint16 FreeBuffers = 0U;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(Netc_Eth_Ip_apxState[ctrlIndex] != NULL_PTR);
    DevAssert(ring < Netc_Eth_Ip_apxState[ctrlIndex]->NumberOfTxBDR);
#endif

    ProducerIndex = (uint32)Netc_Eth_Ip_apxState[ctrlIndex]->LogicTxProducerIndex[ring];
    NextProducerIndex = ProducerIndex;

    while ((FreeBuffers < NumBuffers) && (NETC_ETH_IP_STATUS_SUCCESS == Status))
    {
        NextProducerIndex = (NextProducerIndex + NETC_ETH_IP_PRODUCER_INCR) % (uint32)Netc_Eth_Ip_apxState[ctrlIndex]->TxRingSize[ring];
        /* If the buffer descriptor is free */
        if (NextProducerIndex !=  Netc_Eth_Ip_apxState[ctrlIndex]->lastTxDataBuffAddrIdx[ring])
        {
            if (BufferLength[FreeBuffers] <= (uint16)(Netc_Eth_Ip_apxState[ctrlIndex]->TxBufferLength[ring]))
            {
                if (BufferLength[FreeBuffers] < NETC_ETH_IP_MIN_FRAME_LENGTH)
                {
                    Status = NETC_ETH_IP_STATUS_INVALID_FRAME_LENGTH;
                }
                else
                {
                    FreeBuffers++;
                }
            }
            else
            {
                Status = NETC_ETH_IP_STATUS_TX_BUFF_OVERFLOW;
            }
        }
        else
        {
            Status = NETC_ETH_IP_STATUS_TX_BUFF_BUSY;
        }
    }

    if (FreeBuffers == NumBuffers)
    {
        *buffId = (uint16)(ProducerIndex);
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_SendMultiBufferFrame
 * implements     Netc_Eth_Ip_SendMultiBufferFrame_Activity 
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_SendMultiBufferFrame(uint8 ctrlIndex,
                                                        uint8 ring,
                                                        Netc_Eth_Ip_BufferType Buffers[],
                                                        const Netc_Eth_Ip_TxOptionsType *options,
                                                        uint16 NumBuffers)
{
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_SUCCESS;
    Netc_Eth_Ip_TxBDRType *txBD;
    uint16 FreeBuffers = 0U;
    uint16 BufferIndex = 0U;
    uint16 FrameLength = 0U;
    /* Read the producer index */
    uint32 ProducerIndex = (uint32)Netc_Eth_Ip_apxState[ctrlIndex]->LogicTxProducerIndex[ring]; /* Increment the producer index; making sure it wraps around according to the length of the ring */
    uint32 NextProducerIndex = ProducerIndex;
#if (STD_ON == NETC_ETH_IP_HAS_CACHE_MANAGEMENT)
    Std_ReturnType CacheStatus = E_NOT_OK;
#endif

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(Netc_Eth_Ip_apxState[ctrlIndex] != NULL_PTR);
    DevAssert(ring < Netc_Eth_Ip_apxState[ctrlIndex]->NumberOfTxBDR);
#endif

    while ((FreeBuffers < NumBuffers) && (NETC_ETH_IP_STATUS_SUCCESS == Status))
    {
        NextProducerIndex = (NextProducerIndex + NETC_ETH_IP_PRODUCER_INCR) % (uint32)Netc_Eth_Ip_apxState[ctrlIndex]->TxRingSize[ring];
        /* If the buffer descriptor is free */
        if (NextProducerIndex !=  Netc_Eth_Ip_apxState[ctrlIndex]->lastTxDataBuffAddrIdx[ring])
        {
            /* If the Length doesn't exceed the size of the descriptor, move to next buffer */
            if (Buffers[FreeBuffers].length <= (uint16)(Netc_Eth_Ip_apxState[ctrlIndex]->TxBufferLength[ring]))
            {
                if (Buffers[FreeBuffers].length < NETC_ETH_IP_MIN_FRAME_LENGTH)
                {
                    Status = NETC_ETH_IP_STATUS_INVALID_FRAME_LENGTH;
                }
                else
                {
                    FreeBuffers++;
                }
            }
            else
            {
                Status = NETC_ETH_IP_STATUS_TX_BUFF_OVERFLOW;
            }
            /* Calculate the size of the whole frame */
            FrameLength += Buffers[BufferIndex].length;
        }
        else
        {
            Status = NETC_ETH_IP_STATUS_TX_BUFF_BUSY;
        }
    }

    if (FreeBuffers == NumBuffers)
    {
        while (BufferIndex < NumBuffers)
        {
            Netc_Eth_Ip_apxState[ctrlIndex]->LockTxBuffDescr[ring][ProducerIndex] = TRUE;
            /* Save the address of the external buffer to be used in GetTransmitStatus for correctly identifying the descriptor. */
            Netc_Eth_Ip_apxState[ctrlIndex]->TxDataBuffAddr[ring][ProducerIndex] = Buffers[BufferIndex].data;

            txBD = Netc_Eth_Ip_apxState[ctrlIndex]->FirstTxRingDescAddr[ring] + (ProducerIndex / NETC_ETH_IP_PRODUCER_INCR);
            /* Write buffer and frame length in the buffer descriptor. */
            txBD->length = (((uint32)FrameLength << 16U) | Buffers[BufferIndex].length);
            /* Write buffer address in the descriptor. */
            txBD->dataBuffAddr = (uint32)Buffers[BufferIndex].data;
            ProducerIndex = (ProducerIndex + NETC_ETH_IP_PRODUCER_INCR) % (uint32)Netc_Eth_Ip_apxState[ctrlIndex]->TxRingSize[ring];

            /* Update buffer descriptor for transmission */
            if (BufferIndex != (NumBuffers - 1U))
            {
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
                txBD->buffConfig = NETC_ETH_IP_TXBD_FRAME_INTERRUPT_MASK | NETC_ETH_IP_TXBD_EXTENDED_BUFFER_MASK;
                txBD->extendBuffConfig = 0U;
#else
                txBD->buffConfig = NETC_ETH_IP_TXBD_FRAME_INTERRUPT_MASK;
#endif
            }
            else
            {
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
                /* Write in the buffer descriptor the extended bit */
                txBD->buffConfig = NETC_ETH_IP_TXBD_FRAME_INTERRUPT_MASK | NETC_ETH_IP_TXBD_EXTENDED_BUFFER_MASK;
                txBD->extendBuffConfig = NETC_ETH_IP_TXBD_FINAL_MASK;
#else
                /* Write the final flag and clear writeback field. */
                txBD->buffConfig = NETC_ETH_IP_TXBD_FRAME_INTERRUPT_MASK | NETC_ETH_IP_TXBD_FINAL_MASK;
#endif
            }

            if ((0U == BufferIndex) && (options != NULL_PTR))
            {
                if(NETC_ETH_IP_SWT_MANAGEMNT == options->Flag)
                {
                    /* Set Flag(FL) type; set ingress or egress port value; set value of flag qualifier(FLQ). */
                    txBD->buffConfig |= (((uint32)(NETC_ETH_IP_FLQ_VALUE << NETC_ETH_IP_FLQ_SHIFT)) | \
                                         ((uint32)(options->IngrOrEgrPortNumber << NETC_ETH_IP_INGR_EGRESS_PORT_SHIFT)));
                    if(1U == options->SwtMgSendingOpt)
                    {
                        txBD->buffConfig |= ((((uint32)options->SwtMgSendingOpt) << NETC_ETH_IP_SMSO_SHIFT) | \
                                            (((uint32)options->TimestampRefReq) << NETC_ETH_IP_TSR_SHIFT)  | \
                                            (((uint32)options->InternalPriority) << NETC_ETH_IP_IPV_SHIFT) | \
                                            (((uint32)options->DiscardResilience) << NETC_ETH_IP_DR_SHIFT));
                    }
                }
                else if (NETC_ETH_IP_TXSTART == options->Flag)
                {
                    txBD->buffConfig |= (((uint32)NETC_ETH_IP_TXSTART) << NETC_ETH_IP_FL_SHIFT)  | \
                                        (((uint32)options->TxStartEnable) << NETC_ETH_IP_TSR_SHIFT) | \
                                        (options->TxStartTime);
                }
                else
                {
                    /*MISRA C-2012 Rule 15.7*/
                }
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
                txBD->timestamp = options->Timestamp;
                txBD->extendVlanBuffConfig = ((((uint32)options->PriorityCodePoint) << NETC_ETH_IP_PCP_SHIFT) & NETC_ETH_IP_PCP_MASK) | \
                                             ((((uint32)options->DropEligible) << NETC_ETH_IP_DEI_SHIFT) & NETC_ETH_IP_DEI_MASK) | \
                                             ((((uint32)options->VlanID) << NETC_ETH_IP_VID_SHIFT) & NETC_ETH_IP_VID_MASK ) | \
                                             ((((uint32)options->TagProtocolID) << NETC_ETH_IP_TPID_SHIFT) & NETC_ETH_IP_TPID_MASK);
                txBD->extendBuffConfig |= (((uint32)options->ExtensionFlags) << NETC_ETH_IP_E_FLAGS_SHIFT) & NETC_ETH_IP_E_FLAGS_MASK;
#endif
            }

            BufferIndex++;
        }
        /* Writes in memory for BD are optimized and syncronization before starting transmission need to be done
            to assure that transmission BD is write correctly in memory. */
        MCAL_DATA_SYNC_BARRIER();

#if (STD_ON == NETC_ETH_IP_HAS_CACHE_MANAGEMENT)
            /* Before sending, Flush + Invalidate cache in order write back the contents to main memory and mark the cache lines as invalid so that
            the future reads will be done from the memory. */
            CacheStatus = Cache_Ip_Clean(CACHE_IP_LMEM, CACHE_IP_DATA, TRUE);
            if (E_NOT_OK == CacheStatus)
            {
                Status = NETC_ETH_IP_STATUS_CACHE_ERROR;
            }
            else
            {
#endif
            /* Update the current value of the producer index. */
            Netc_Eth_Ip_apxState[ctrlIndex]->LogicTxProducerIndex[ring] = ProducerIndex;
            /* Write the producer index into register to start frame sending. */
            netcSIsBase[ctrlIndex]->BDR_NUM[ring].TBPIR = ProducerIndex;
#if (STD_ON == NETC_ETH_IP_HAS_CACHE_MANAGEMENT)
            }
#endif
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_SendFrame
 * implements     Netc_Eth_Ip_SendFrame_Activity 
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_SendFrame(uint8 ctrlIndex,
                                             uint8 ring,
                                            Netc_Eth_Ip_BufferType *buff,
                                             const Netc_Eth_Ip_TxOptionsType *options)
{
    Netc_Eth_Ip_TxBDRType *txBD;
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_SUCCESS;
    uint32 ProducerIndex;
    uint16 NextProducerIndex;
#if (STD_ON == NETC_ETH_IP_HAS_CACHE_MANAGEMENT)
    Std_ReturnType CacheStatus = E_NOT_OK;
#endif
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
#ifdef NETC_ETH_0_USED
    uint16 DataBufferIndex;
    uint8 *FrameDataPtr;
#endif
#endif

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(Netc_Eth_Ip_apxState[ctrlIndex] != NULL_PTR);
    DevAssert(ring < Netc_Eth_Ip_apxState[ctrlIndex]->NumberOfTxBDR);
    DevAssert(buff != NULL_PTR);
#endif

    /* Read the producer index */
    ProducerIndex = (uint32)Netc_Eth_Ip_apxState[ctrlIndex]->LogicTxProducerIndex[ring];
    /* Increment the producer index; making sure it wraps around according to the length of the ring */
    NextProducerIndex = (ProducerIndex + NETC_ETH_IP_PRODUCER_INCR) % Netc_Eth_Ip_apxState[ctrlIndex]->TxRingSize[ring];

#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_TX_BUFFERS)
    /* Test frame length */
    if (buff->length < NETC_ETH_IP_MIN_FRAME_LENGTH)
    {
        Status = NETC_ETH_IP_STATUS_INVALID_FRAME_LENGTH;
    }
    else if (buff->length > Netc_Eth_Ip_apxState[ctrlIndex]->TxBufferLength[ring])
    {
        Status = NETC_ETH_IP_STATUS_TX_BUFF_OVERFLOW;
        buff->length = Netc_Eth_Ip_apxState[ctrlIndex]->TxBufferLength[ring];
    }
    else
    {
        /* ATTENTION! This mechanism is implemented to be sure that producer index will NOT be equal with the consumer index,
                      because in the equality case the transmition will be stopped. */
        if(NextProducerIndex != Netc_Eth_Ip_apxState[ctrlIndex]->lastTxDataBuffAddrIdx[ring])
        {
            Netc_Eth_Ip_apxState[ctrlIndex]->LockTxBuffDescr[ring][ProducerIndex] = TRUE;
#endif /* NETC_ETH_IP_HAS_EXTERNAL_TX_BUFFERS */
            /* Save the address of the external buffer to be used in GetTransmitStatus for correctly identifying the descriptor. */
            Netc_Eth_Ip_apxState[ctrlIndex]->TxDataBuffAddr[ring][ProducerIndex] = buff->data;

            txBD = Netc_Eth_Ip_apxState[ctrlIndex]->FirstTxRingDescAddr[ring] + (ProducerIndex / NETC_ETH_IP_PRODUCER_INCR);
            /* Write buffer and frame length in the buffer descriptor. */
            txBD->length = (((uint32)buff->length << 16U) | buff->length);
            /* Write buffer address in the descriptor. */
            txBD->dataBuffAddr = (uint32)buff->data;

            /* Check if there was a writeback in the descriptor */
            if (NETC_ETH_IP_TXBD_WRITEBACK_MASK == (txBD->buffConfig & NETC_ETH_IP_TXBD_WRITEBACK_MASK))
            {
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
                /* Write in the buffer descriptor the extended bit */
                txBD->buffConfig = (NETC_ETH_IP_TXBD_FRAME_INTERRUPT_MASK | NETC_ETH_IP_TXBD_EXTENDED_BUFFER_MASK);
                txBD->extendBuffConfig = NETC_ETH_IP_TXBD_FINAL_MASK;
#else
                /* Write the final flag and clear writeback field. */
                txBD->buffConfig = NETC_ETH_IP_TXBD_FRAME_INTERRUPT_MASK | NETC_ETH_IP_TXBD_FINAL_MASK;
#endif
            }
            else
            {
                /*MISRA C-2012 Rule 15.7*/
            }

            if(options != NULL_PTR)
            {
                if(NETC_ETH_IP_SWT_MANAGEMNT == options->Flag)
                {
                    /* Set Flag(FL) type; set ingress or egress port value; set value of flag qualifier(FLQ). */
                    txBD->buffConfig |= ((((uint32)NETC_ETH_IP_FLQ_VALUE) << NETC_ETH_IP_FLQ_SHIFT) | \
                                         ((uint32)options->IngrOrEgrPortNumber << NETC_ETH_IP_INGR_EGRESS_PORT_SHIFT));
                    if(1U == options->SwtMgSendingOpt)
                    {
                        txBD->buffConfig |= ((uint32)options->SwtMgSendingOpt << NETC_ETH_IP_SMSO_SHIFT) | \
                                            ((uint32)options->TimestampRefReq << NETC_ETH_IP_TSR_SHIFT)  | \
                                            ((uint32)options->InternalPriority << NETC_ETH_IP_IPV_SHIFT)  | \
                                            ((uint32)options->DiscardResilience << NETC_ETH_IP_DR_SHIFT);
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
#ifdef NETC_ETH_0_USED
                        /* If frame is transmitted as management, copy data from the used ring. */
                        if(((uint8)0U == ctrlIndex) && ((uint8)0U == ring))
                        {
                            LatestTxTimestampValidFlag = FALSE;
                            Netc_Eth_Ip_TxTimestampInfoBuff[0U][ProducerIndex / NETC_ETH_IP_PRODUCER_INCR].TxTimestampFlag = TRUE;

                            FrameDataPtr = (uint8 *)(Netc_Eth_Ip_apxState[0U]->FirstTxDataBufferAddr[0U] + \
                                                    (ProducerIndex * Netc_Eth_Ip_apxState[0U]->TxDataBuffMaxLenAddr[0U]));

                            for(DataBufferIndex = 0U; DataBufferIndex < Netc_Eth_Ip_apxState[0U]->TxBufferLength[0U]; DataBufferIndex++)
                            {
                                *FrameDataPtr = (uint8)((buff->data)[DataBufferIndex]);
                                FrameDataPtr++;
                            }

                            txBD->dataBuffAddr = (uint32)FrameDataPtr;
                        }
#endif
#endif
                    }
                }
                else if (NETC_ETH_IP_TXSTART == options->Flag)
                {
                    txBD->buffConfig |= ((((uint32)NETC_ETH_IP_TXSTART) << NETC_ETH_IP_FL_SHIFT) |
                                        (((uint32)options->TxStartEnable) << NETC_ETH_IP_TSR_SHIFT) |
                                        (options->TxStartTime));
                }
                else
                {
                    /*MISRA C-2012 Rule 15.7*/
                }
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
                txBD->timestamp = options->Timestamp;
                txBD->extendVlanBuffConfig = ((((uint32)options->PriorityCodePoint) << NETC_ETH_IP_PCP_SHIFT) & NETC_ETH_IP_PCP_MASK) | \
                                             ((((uint32)options->DropEligible) << NETC_ETH_IP_DEI_SHIFT) & NETC_ETH_IP_DEI_MASK) | \
                                             ((((uint32)options->VlanID) << NETC_ETH_IP_VID_SHIFT) & NETC_ETH_IP_VID_MASK ) | \
                                             ((((uint32)options->TagProtocolID) << NETC_ETH_IP_TPID_SHIFT) & NETC_ETH_IP_TPID_MASK);
                txBD->extendBuffConfig |= (((uint32)options->ExtensionFlags) << NETC_ETH_IP_E_FLAGS_SHIFT) & NETC_ETH_IP_E_FLAGS_MASK;
#endif
            }

            /* Writes in memory for BD are optimized and syncronization before starting transmission need to be done
               to assure that transmission BD is write correctly in memory. */
            MCAL_DATA_SYNC_BARRIER();

#if (STD_ON == NETC_ETH_IP_HAS_CACHE_MANAGEMENT)
            /* Before sending, Flush + Invalidate cache in order write back the contents to main memory and mark the cache lines as invalid so that
            the future reads will be done from the memory. */
            CacheStatus = Cache_Ip_Clean(CACHE_IP_LMEM, CACHE_IP_DATA, TRUE);
            if (E_NOT_OK == CacheStatus)
            {
                Status = NETC_ETH_IP_STATUS_CACHE_ERROR;
            }
            else
            {
#endif
            /* Update the current value of the producer index. */
            Netc_Eth_Ip_apxState[ctrlIndex]->LogicTxProducerIndex[ring] = NextProducerIndex;
            /* Write the producer index into register to start frame sending. */
            netcSIsBase[ctrlIndex]->BDR_NUM[ring].TBPIR = (uint32)NextProducerIndex;

#if (STD_ON == NETC_ETH_IP_HAS_CACHE_MANAGEMENT)
            }/*   if (E_NOT_OK == CacheStatus) */
#endif

#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_TX_BUFFERS)
        }
        else
        {
            Status = NETC_ETH_IP_STATUS_TX_BUFF_BUSY;
        }
    }
#endif

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_GetTransmitStatus
 * implements     Netc_Eth_Ip_GetTransmitStatus_Activity 
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetTransmitStatus(uint8 ctrlIndex,
                                                     uint8 ring,
                                                     const Netc_Eth_Ip_BufferType *buff,
                                                     Netc_Eth_Ip_TxInfoType *info)
{
    uint32 LastDescrCheckIndex;
    uint32 ConsumerIndex;
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;
    volatile uint32 CurrDescrCheckIndex = 0U;
    const Netc_Eth_Ip_TxBDRType *txBDR;
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
#ifdef NETC_ETH_0_USED
    uint16 TimestampInfoIndex;
#endif
#endif

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(Netc_Eth_Ip_apxState[ctrlIndex] != NULL_PTR);
    DevAssert(ring < Netc_Eth_Ip_apxState[ctrlIndex]->NumberOfTxBDR);
    DevAssert(buff != NULL_PTR);
#endif

    LastDescrCheckIndex = Netc_Eth_Ip_apxState[ctrlIndex]->lastTxDataBuffAddrIdx[ring];
    /* Get the addres of the current BDR to get status for it. */
    CurrDescrCheckIndex = (uint32)( (LastDescrCheckIndex + NETC_ETH_IP_PRODUCER_INCR) % \
                                    (uint32)Netc_Eth_Ip_apxState[ctrlIndex]->TxRingSize[ring] );

    /* Read the consumer index */
    ConsumerIndex = netcSIsBase[ctrlIndex]->BDR_NUM[ring].TBCIR;

    if ( buff->data != Netc_Eth_Ip_apxState[ctrlIndex]->TxDataBuffAddr[ring][LastDescrCheckIndex] )
    {
        status = NETC_ETH_IP_STATUS_BUFF_NOT_FOUND;
    }
    /* Check whether the frame was transmitted. Checking the consumer index only works when sending frame by frame */
    else
    {
        if ( (ConsumerIndex != LastDescrCheckIndex && \
              TRUE == Netc_Eth_Ip_apxState[ctrlIndex]->LockTxBuffDescr[ring][LastDescrCheckIndex]))
        {
            /* Get the descriptor corresponding to the buff pointer (by looping through the descriptors) */
            txBDR = Netc_Eth_Ip_apxState[ctrlIndex]->FirstTxRingDescAddr[ring] + (LastDescrCheckIndex / NETC_ETH_IP_PRODUCER_INCR);

            /* Check if there was a writeback in the descriptor */
            if (NETC_ETH_IP_TXBD_WRITEBACK_MASK == (txBDR->buffConfig & NETC_ETH_IP_TXBD_WRITEBACK_MASK))
            {
                /* Check the STATUS bitfield and read the possible errors and store them in info */
                if (0U != (uint16)(((Netc_Eth_Ip_TxBDRWritebackType *)txBDR)->FlagsAndStatus & NETC_ETH_IP_TX_WB_STATUS_MASK))
                {
                    /* Mark the status as error */
                    status = NETC_ETH_IP_STATUS_ERROR;
                    if (NULL_PTR != info)
                    {
                        info->txStatus = (Netc_Eth_Ip_TxStatusType)(((const Netc_Eth_Ip_TxBDRWritebackType *)txBDR)->FlagsAndStatus & NETC_ETH_IP_TX_WB_STATUS_MASK);
                    }
                }
                else
                {
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
#ifdef NETC_ETH_0_USED
                    if(((uint8)0U == ring) && ((uint8)0U == ctrlIndex))
                    {
                        TimestampInfoIndex = (0U != ConsumerIndex) ? ((uint16)ConsumerIndex) : (Netc_Eth_Ip_apxState[ctrlIndex]->TxRingSize[ring]);
                        Netc_Eth_Ip_TxTimestampInfoBuff[0U][(TimestampInfoIndex - 2U)/ NETC_ETH_IP_PRODUCER_INCR].TxTimeStampID = (uint16)(((Netc_Eth_Ip_TxBDRWritebackType *)txBDR)->TxTimestampID);
                    }
#endif
#endif
                }
            }

            /* Update status of the data buffer. */
            Netc_Eth_Ip_apxState[ctrlIndex]->LockTxBuffDescr[ring][LastDescrCheckIndex] = FALSE;
            /* Update the value for the last data buffer checked for the next call. */
            Netc_Eth_Ip_apxState[ctrlIndex]->lastTxDataBuffAddrIdx[ring] = CurrDescrCheckIndex;
        }
        else
        {
           status = NETC_ETH_IP_STATUS_TX_BUFF_BUSY;
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_ReleaseTxBuffers
 * implements     Netc_Eth_Ip_ReleaseTxBuffers_Activity 
 *END**************************************************************************/
void Netc_Eth_Ip_ReleaseTxBuffers(uint8 CtrlIdx, uint8 Ring)
{
    uint32 CurrDescrCheckIndex;
    uint32 ConsumerIndex;
#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIdx < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(Netc_Eth_Ip_apxState[CtrlIdx] != NULL_PTR);
    DevAssert(Ring < Netc_Eth_Ip_apxState[CtrlIdx]->NumberOfTxBDR);
#endif

    /* Read the consumer index */
    ConsumerIndex = netcSIsBase[CtrlIdx]->BDR_NUM[Ring].TBCIR;

    CurrDescrCheckIndex = (Netc_Eth_Ip_apxState[CtrlIdx]->lastTxDataBuffAddrIdx[Ring]) % \
                           (uint32)(Netc_Eth_Ip_apxState[CtrlIdx]->TxRingSize[Ring]);

    while((TRUE == Netc_Eth_Ip_apxState[CtrlIdx]->LockTxBuffDescr[Ring][CurrDescrCheckIndex]) && \
          (ConsumerIndex != CurrDescrCheckIndex))
    {
        Netc_Eth_Ip_apxState[CtrlIdx]->LockTxBuffDescr[Ring][CurrDescrCheckIndex] = FALSE;
        CurrDescrCheckIndex = (CurrDescrCheckIndex + NETC_ETH_IP_PRODUCER_INCR) % \
                              (uint32)(Netc_Eth_Ip_apxState[CtrlIdx]->TxRingSize[Ring]);
    }

    Netc_Eth_Ip_apxState[CtrlIdx]->lastTxDataBuffAddrIdx[Ring] = CurrDescrCheckIndex;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_SetMacAddr
 * implements     Netc_Eth_Ip_SetMacAddr_Activity 
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_SetMacAddr(uint8 CtrlIndex, const uint8 *MacAddr)
{
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_SUCCESS;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(MacAddr != NULL_PTR);
    DevAssert(Netc_Eth_Ip_apxState[CtrlIndex] != NULL_PTR);
#endif

    /* If the controller is the PSI it should write directly the MAC address. */
    if (NETC_ETH_IP_PHYSICAL_SI == Netc_Eth_Ip_apxState[CtrlIndex]->SiType)
    {
        IP_NETC__ENETC0_PORT->PMAR0 = ((uint32)MacAddr[0U]) | ((uint32)MacAddr[1U] << 8U) | ((uint32)MacAddr[2U] << 16U) | ((uint32)MacAddr[3U] << 24U);
        IP_NETC__ENETC0_PORT->PMAR1 = ((uint32)MacAddr[4U]) | ((uint32)MacAddr[5U] << 8U);
    }
    /* If the controller is a VSI a mailbox request is sent to the PSI to change the MAC address. */
    else
    {
        Status = Netc_Eth_Ip_VsiToPsiMsg(CtrlIndex, NETC_ETH_IP_VSITOPSI_MAC_ADDR_SET, MacAddr);
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_GetMacAddr
 * implements     Netc_Eth_Ip_GetMacAddr_Activity 
 *END**************************************************************************/
void Netc_Eth_Ip_GetMacAddr(uint8 CtrlIndex, uint8 *MacAddr)
{
    uint32 tempRegValue;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(MacAddr != NULL_PTR);
#endif

    /* Get from physical Address lower register. */
    tempRegValue = IP_NETC__ENETC0_BASE->NUM_SI[CtrlIndex].PSIPMAR0;
    MacAddr[0U] = (uint8)(tempRegValue & 0xFFU);
    MacAddr[1U] = (uint8)((tempRegValue >> 8U) & 0xFFU);
    MacAddr[2U] = (uint8)((tempRegValue >> 16U) & 0xFFU);
    MacAddr[3U] = (uint8)((tempRegValue >> 24U) & 0xFFU);

    /* Get from physical Address high register. */
    tempRegValue = IP_NETC__ENETC0_BASE->NUM_SI[CtrlIndex].PSIPMAR1;
    MacAddr[4U] = (uint8)(tempRegValue & 0xFFU);
    MacAddr[5U] = (uint8)((tempRegValue >> 8U) & 0xFFU);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_GetCounter
 * implements     Netc_Eth_Ip_GetCounter_Activity 
 *END**************************************************************************/
uint32 Netc_Eth_Ip_GetCounter(uint8 CtrlIndex, Netc_Eth_Ip_CounterType Counter)
{
    const volatile uint32 *CounterAddr;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
#endif
    /* Compute addres of the counter. */
    CounterAddr = (volatile uint32 *)((uint32)netcSIsBase[CtrlIndex] + (uint32)Counter);

    return *CounterAddr;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_IsFrameAvailable
 * implements     Netc_Eth_Ip_IsFrameAvailable_Activity 
 *END**************************************************************************/
boolean Netc_Eth_Ip_IsFrameAvailable(uint8 ctrlIndex, uint8 ring)
{
    const Netc_Eth_Ip_RxBDRType *rxBDR;
    boolean bFrameAvailable = FALSE;
    uint32 rxConsumerIdx;
    uint32 rxProducerIdx;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(Netc_Eth_Ip_apxState[ctrlIndex] != NULL_PTR);
    DevAssert(ring < Netc_Eth_Ip_apxState[ctrlIndex]->NumberOfRxBDR);
#endif

    rxConsumerIdx = netcSIsBase[ctrlIndex]->BDR_NUM[ring].RBCIR;
    rxProducerIdx = netcSIsBase[ctrlIndex]->BDR_NUM[ring].RBPIR;

    /* Get the current descriptor corresponding to the buff pointer (by looping through the descriptors) */
    rxBDR = Netc_Eth_Ip_apxState[ctrlIndex]->RxCurrentDesc[ring];

    /* If the producer index is different from consumer index, then a frame is in the point to be receive. */
    /* If the ready bit is set in the writeback descriptor at least a frame is available */
    if ( (rxProducerIdx != rxConsumerIdx) && \
          (NETC_ETH_IP_RXBD_READY_MASK == (rxBDR->configRxBD[3U] & NETC_ETH_IP_RXBD_READY_MASK)) )
    {
        bFrameAvailable = TRUE;
    }

    return bFrameAvailable;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_ReadFrame
 * implements     Netc_Eth_Ip_ReadFrame_Activity 
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_ReadFrame(uint8 ctrlIndex,
                                             uint8 ring,
                                             Netc_Eth_Ip_BufferType *buff,
                                             Netc_Eth_Ip_RxInfoType *info)
{
    const Netc_Eth_Ip_RxBDRType  *rxBDR;
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
#ifdef NETC_ETH_0_USED
    const Netc_Eth_Ip_TxTimestampResponseType *TempTxResponse;
    uint16 TxTimestampID;
    uint32 CurrLowTime;
    uint16 CurrDescrIdx;
#endif
#endif
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;
    uint32 rxIndex = 0;
    uint32 HostReason = 0xFFFFFFFFU;
#if (NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS == STD_ON)
    uint32 bufferIndex = 0;
#endif

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(Netc_Eth_Ip_apxState[ctrlIndex] != NULL_PTR);
    DevAssert(ring < Netc_Eth_Ip_apxState[ctrlIndex]->NumberOfRxBDR);
    DevAssert(buff != NULL_PTR);
#endif
#if (STD_ON == NETC_ETH_IP_HAS_CACHE_MANAGEMENT)
    Std_ReturnType CacheStatus = E_NOT_OK;
#endif
    /* Get the current descriptor corresponding to the buff pointer (by looping through the descriptors) */
    rxBDR = Netc_Eth_Ip_apxState[ctrlIndex]->RxCurrentDesc[ring];
    rxIndex = Netc_Eth_Ip_apxState[ctrlIndex]->rxCurrentIndex[ring];
#if (NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS == STD_ON)
    bufferIndex = ring * NETC_ETH_MAX_NUMBER_OF_RXBD + rxIndex;
#endif
    if (NETC_ETH_IP_RXBD_READY_MASK != (rxBDR->configRxBD[3U] & NETC_ETH_IP_RXBD_READY_MASK))
    {
        status = NETC_ETH_IP_STATUS_RX_QUEUE_EMPTY;
    }
    else
    {
        if (NETC_ETH_RX_NO_RECEIVE_ERR == (Netc_Eth_Ip_RxStatusType)((rxBDR->configRxBD[3U] & NETC_ETH_IP_RXBD_ERROR_MASK) >> 16U))
        {
            HostReason = (rxBDR->configRxBD[3U] & NETC_ETH_IP_HOSTREASON_WB_MASK);

            if(NETC_ETH_IP_HOSTREASON_REGULAR_FRAME == HostReason)
            {
#if (NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS == STD_ON)
                if (!Netc_Eth_Ip_ControllerHasExternalRxBufferManagement[ctrlIndex])
                {
#endif
                    /* All conditions meet, return buffer data details. */
                    buff->data = (Netc_Eth_Ip_apxState[ctrlIndex]->FirstRxDataBufferAddr[ring] + \
                                  (rxIndex * Netc_Eth_Ip_apxState[ctrlIndex]->RxDataBuffMaxLenAddr[ring]));
#if (NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS == STD_ON)
                }
                else
                {
                    buff->data = (uint8*)Netc_Eth_Ip_apxState[ctrlIndex]->RxDataBuffAddr[bufferIndex];
                }
#endif
                buff->length = (uint16)(rxBDR->configRxBD[2U] & NETC_ETH_IP_RXBD_LENGTH_MASK);

#if (STD_ON == NETC_ETH_IP_HAS_CACHE_MANAGEMENT)
                /* Mark the cache lines as invalid in order to get the new data from data buffers from memory. */
                CacheStatus = Cache_Ip_Invalidate(CACHE_IP_LMEM, CACHE_IP_DATA);
                if (E_NOT_OK == CacheStatus)
                {
                    status = NETC_ETH_IP_STATUS_CACHE_ERROR;
                }
#endif

#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
                Netc_Eth_Ip_RxTimestampInfoBuff[ctrlIndex][ring][rxIndex].RingIdx = ring;
                Netc_Eth_Ip_RxTimestampInfoBuff[ctrlIndex][ring][rxIndex].ReceivedDataPtr = buff->data;
                Netc_Eth_Ip_RxTimestampInfoBuff[ctrlIndex][ring][rxIndex].TimestampValue.nanosecondsL = rxBDR->extendConfigRxBD[0U];
                Netc_Eth_Ip_RxTimestampInfoBuff[ctrlIndex][ring][rxIndex].TimestampValueInvalidForEth = (boolean)FALSE;
                Netc_Eth_Ip_RxTimestampInfoBuff[ctrlIndex][ring][rxIndex].TimestampValueInvalidForSwt = (boolean)FALSE;
                Netc_Eth_Ip_RxTimestampID = (Netc_Eth_Ip_RxTimestampID % (uint32)0xFFFFU) + (uint32)1U;
                Netc_Eth_Ip_RxTimestampInfoBuff[ctrlIndex][ring][rxIndex].TimestampID = Netc_Eth_Ip_RxTimestampID;

                /* TODO: not sure if this is in nanosecondads */
                CurrLowTime = netcSIsBase[0U]->SICTR0;
                Netc_Eth_Ip_RxTimestampInfoBuff[ctrlIndex][ring][rxIndex].TimestampValue.nanosecondsH = netcSIsBase[0U]->SICTR1;
                if(CurrLowTime < info->PacketTimestamp)
                {
                    Netc_Eth_Ip_RxTimestampInfoBuff[ctrlIndex][ring][rxIndex].TimestampValue.nanosecondsH--;
                }
#endif /* STD_ON == NETC_ETH_IP_EXTENDED_BUFF */
            }
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
#ifdef NETC_ETH_0_USED
            else if(NETC_ETH_IP_HOSTREASON_TIMESTAMP == HostReason)
            {
                if((0U == ctrlIndex) && (0U == ring))
                {
                    /* TODO: not sure if this is in nanosecondads */
                    CurrLowTime = netcSIsBase[0U]->SICTR0;

                    TempTxResponse = (Netc_Eth_Ip_TxTimestampResponseType *)Netc_Eth_Ip_apxState[ctrlIndex]->RxCurrentDesc[ring];
                    TxTimestampID = TempTxResponse->TxTimestampID;

                    LatestTxTimestamp.nanosecondsL = TempTxResponse->Timestamp;
                    LatestTxTimestamp.nanosecondsH = netcSIsBase[0U]->SICTR1;
                    if(CurrLowTime < LatestTxTimestamp.nanosecondsL)
                    {
                        LatestTxTimestamp.nanosecondsH--;
                    }
                    LatestTxTimestampValidFlag = TRUE;

                    for(CurrDescrIdx = 0U; CurrDescrIdx < Netc_Eth_Ip_apxState[ctrlIndex]->TxRingSize[ring]; CurrDescrIdx++)
                    {
                        if(Netc_Eth_Ip_TxTimestampInfoBuff[0][CurrDescrIdx].TxTimeStampID == TxTimestampID)
                        {
                            Netc_Eth_Ip_TxTimestampInfoBuff[0][CurrDescrIdx].TimestampValue.nanosecondsL = TempTxResponse->Timestamp;

                            Netc_Eth_Ip_TxTimestampInfoBuff[0][CurrDescrIdx].TimestampValue.nanosecondsH = netcSIsBase[0U]->SICTR1;

                            if(CurrLowTime < Netc_Eth_Ip_TxTimestampInfoBuff[0][CurrDescrIdx].TimestampValue.nanosecondsL)
                            {
                                Netc_Eth_Ip_TxTimestampInfoBuff[0][CurrDescrIdx].TimestampValue.nanosecondsH--;
                            }
                            status = NETC_ETH_IP_STATUS_HOSTREASON_TIMESTAMP;
                            break;
                        }
                    }

                }
            }
#endif /* NETC_ETH_0_USED */
#endif /* STD_ON == NETC_ETH_IP_EXTENDED_BUFF */
            else
            {
                status = NETC_ETH_IP_STATUS_HOSTREASON_UNKNOWN;
            }
        }
        else
        {
            status = NETC_ETH_IP_STATUS_ERROR;
        }

        /* Store information about received frame. */
        if (NULL_PTR != info)
        {
            info->L4cksum = (rxBDR->configRxBD[3U] & NETC_ETH_IP_RXBD_L4_FLAG_MASK) > 0U ? TRUE : FALSE;
            info->L3cksum = (rxBDR->configRxBD[3U] & NETC_ETH_IP_RXBD_L3_FLAG_MASK) > 0U ? TRUE : FALSE;
            info->finalDes = (rxBDR->configRxBD[3U] & NETC_ETH_IP_RXBD_FINAL_MASK)  > 0U ? TRUE : FALSE;
            info->timestampReceived = (rxBDR->configRxBD[3U] & NETC_ETH_IP_RXBD_TIMESTAMP_FLAG_MASK) > 0U ? TRUE : FALSE;
            info->vlanHeaderAvl = (rxBDR->configRxBD[3U] & NETC_ETH_IP_RXBD_VLAN_HEAD_FLAG_MASK) > 0U ? TRUE : FALSE;
            info->pktLen = (uint16)(rxBDR->configRxBD[2U] & NETC_ETH_IP_RXBD_LENGTH_MASK);
            info->rxStatus = (Netc_Eth_Ip_RxStatusType)((rxBDR->configRxBD[3U] & NETC_ETH_IP_RXBD_ERROR_MASK) >> NETC_ETH_IP_RXBD_ERROR_SHIFT);
            info->hostReason = (Netc_Eth_Ip_HostReasonType)((rxBDR->configRxBD[3U] & NETC_ETH_IP_RXBD_HOST_REASON_MASK) >> NETC_ETH_IP_RXBD_HOST_REASON_SHIFT);
#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
            info->VlanInfo.ProtocolIdentifier = (Netc_Eth_Ip_VlanProtocolIdentifierType)(rxBDR->configRxBD[3U] & NETC_ETH_IP_RXBD_TPID_MASK);
            info->VlanInfo.PriorityCodePoint = (uint8)((rxBDR->configRxBD[2U] & NETC_ETH_IP_RXBD_PCP_MASK) >> NETC_ETH_IP_RXBD_PCP_SHIFT);
            info->VlanInfo.DropIndicator = (((uint8)((rxBDR->configRxBD[2U] & NETC_ETH_IP_RXBD_DEI_MASK) >> NETC_ETH_IP_RXBD_DEI_SHIFT) == 1U) ?
                                            TRUE : FALSE);
            info->VlanInfo.VlanIdentifier = (uint16)((rxBDR->configRxBD[2U] & NETC_ETH_IP_RXBD_VID_MASK) >> NETC_ETH_IP_RXBD_VID_SHIFT);
#endif
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
            info->PacketTimestamp = rxBDR->extendConfigRxBD[0U];
#endif
        }

        /* Go to the next index. */
        Netc_Eth_Ip_apxState[ctrlIndex]->rxCurrentIndex[ring] = (Netc_Eth_Ip_apxState[ctrlIndex]->rxCurrentIndex[ring] + 1U) % \
                                                                 Netc_Eth_Ip_apxState[ctrlIndex]->RxRingSize[ring];

        /* Increment the pointer to the current descriptor. */
        Netc_Eth_Ip_apxState[ctrlIndex]->RxCurrentDesc[ring] = Netc_Eth_Ip_apxState[ctrlIndex]->FirstRxRingDescAddr[ring] + \
                                                               Netc_Eth_Ip_apxState[ctrlIndex]->rxCurrentIndex[ring];
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_ProvideRxBuff
 * implements     Netc_Eth_Ip_ProvideRxBuff_Activity 
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_ProvideRxBuff(uint8 ctrlIndex,
                                                 uint8 ring,
                                                 const Netc_Eth_Ip_BufferType *buff)
{
    uint16 CurrentConsumerIndex;
    Netc_Eth_Ip_RxBDRType *RxBDR;
#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
    uint32 bufferIndex;
#endif

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(Netc_Eth_Ip_apxState[ctrlIndex] != NULL_PTR);
    DevAssert(ring < Netc_Eth_Ip_apxState[ctrlIndex]->NumberOfRxBDR);

#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
    if (Netc_Eth_Ip_ControllerHasExternalRxBufferManagement[ctrlIndex])
    {
        DevAssert(buff != NULL_PTR);
    }
#endif /* (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS) */

#endif /* (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT) */

    CurrentConsumerIndex = Netc_Eth_Ip_apxState[ctrlIndex]->LogicRxConsumerIndex[ring];
    RxBDR = Netc_Eth_Ip_apxState[ctrlIndex]->FirstRxRingDescAddr[ring] + CurrentConsumerIndex;

    /* Configure descriptor by setting the address of data buffer and clear the rest of it. */
#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
    bufferIndex = ring * FEATURE_NETC_RX_BDR_COUNT + CurrentConsumerIndex;

    /* In case the current controller has Internal Buffer Management for reception, restore the data buffer */
    if (!Netc_Eth_Ip_ControllerHasExternalRxBufferManagement[ctrlIndex])
    {
#endif
        RxBDR->configRxBD[0U] = ((uint32)Netc_Eth_Ip_apxState[ctrlIndex]->FirstRxDataBufferAddr[ring] + \
                             (CurrentConsumerIndex * (uint32)(Netc_Eth_Ip_apxState[ctrlIndex]->RxDataBuffMaxLenAddr[ring])));
#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
    }
    else
    {
        Netc_Eth_Ip_apxState[ctrlIndex]->RxDataBuffAddr[bufferIndex] = (uint32)buff->data;
        RxBDR->configRxBD[0U] = (uint32)buff->data;
    }
#else
    /* Avoid compiler warning */
    (void)buff;
#endif

    RxBDR->configRxBD[1U] = 0U;
    RxBDR->configRxBD[2U] = 0U;
    RxBDR->configRxBD[3U] = 0U;
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
    RxBDR->extendConfigRxBD[0U] = 0U;
    RxBDR->extendConfigRxBD[1U] = 0U;
    RxBDR->extendConfigRxBD[2U] = 0U;
    RxBDR->extendConfigRxBD[3U] = 0U;
#endif

    /* Update consumer index. */
    Netc_Eth_Ip_apxState[ctrlIndex]->LogicRxConsumerIndex[ring] = (CurrentConsumerIndex + 1U) % \
                                                                  Netc_Eth_Ip_apxState[ctrlIndex]->RxRingSize[ring];
    netcSIsBase[ctrlIndex]->BDR_NUM[ring].RBCIR = Netc_Eth_Ip_apxState[ctrlIndex]->LogicRxConsumerIndex[ring];

    return NETC_ETH_IP_STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_ProvideMultipleRxBuff
 * implements     Netc_Eth_Ip_ProvideMultipleRxBuff_Activity 
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_ProvideMultipleRxBuff(uint8 CtrlIndex,
                                                         uint8 Ring,
                                                         uint8* BuffList[],
                                                         uint16* BuffListSize)
{
    uint16 ConsumerIndex = 0U;
    uint16 LastRxConsumerRead = 0U;
    volatile Netc_Eth_Ip_RxBDRType *RxBDR;
    uint16 BuffListIndex = 0U;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(Netc_Eth_Ip_apxState[CtrlIndex] != NULL_PTR);
    DevAssert(Ring < Netc_Eth_Ip_apxState[CtrlIndex]->NumberOfRxBDR);
    DevAssert(BuffListSize != NULL_PTR);
    DevAssert(*BuffListSize > 1U);
#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
    if (Netc_Eth_Ip_ControllerHasExternalRxBufferManagement[CtrlIndex])
    {
        DevAssert(BuffList != NULL_PTR);
    }
#endif
#endif

    ConsumerIndex = (uint32)Netc_Eth_Ip_apxState[CtrlIndex]->LogicRxConsumerIndex[Ring];
    LastRxConsumerRead = Netc_Eth_Ip_apxState[CtrlIndex]->rxCurrentIndex[Ring];
    do
    {
        RxBDR = Netc_Eth_Ip_apxState[CtrlIndex]->FirstRxRingDescAddr[Ring] + ConsumerIndex;

#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
        /* In case the current controller has Internal Buffer Management for reception */
        if (Netc_Eth_Ip_ControllerHasExternalRxBufferManagement[CtrlIndex])
        {
            RxBDR->configRxBD[0U] = (uint32)BuffList[BuffListIndex];
        }
        else
        {
#else
            (void)BuffList;
#endif
            RxBDR->configRxBD[0U] = ((uint32)Netc_Eth_Ip_apxState[CtrlIndex]->FirstRxDataBufferAddr[Ring] + \
                                    (ConsumerIndex * (uint32)Netc_Eth_Ip_apxState[CtrlIndex]->RxDataBuffMaxLenAddr[Ring]));

#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
        }
#endif
        RxBDR->configRxBD[1U] = 0U;
        RxBDR->configRxBD[2U] = 0U;
        RxBDR->configRxBD[3U] = 0U;

#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
        RxBDR->extendConfigRxBD[0U] = 0U;
        RxBDR->extendConfigRxBD[1U] = 0U;
        RxBDR->extendConfigRxBD[2U] = 0U;
        RxBDR->extendConfigRxBD[3U] = 0U;
#endif
        ConsumerIndex = (ConsumerIndex + (uint16)1U) % Netc_Eth_Ip_apxState[CtrlIndex]->RxRingSize[Ring];
        /* Go to the next buffer */
        BuffListIndex++;
    } while((ConsumerIndex != LastRxConsumerRead) && (BuffListIndex < *BuffListSize));

    /* Return how many descriptors have been restored. */
    *BuffListSize = BuffListIndex;

    /* Update consumer index. */
    Netc_Eth_Ip_apxState[CtrlIndex]->LogicRxConsumerIndex[Ring] = ConsumerIndex;
    netcSIsBase[CtrlIndex]->BDR_NUM[Ring].RBCIR = (uint32)ConsumerIndex;

    return NETC_ETH_IP_STATUS_SUCCESS;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_GetPowerState
 * implements     Netc_Eth_Ip_GetPowerState_Activity 
 *END**************************************************************************/
Netc_Eth_Ip_PowerStateType Netc_Eth_Ip_GetPowerState(uint8 CtrlIndex)
{
    Netc_Eth_Ip_PowerStateType status = NETC_ETH_STATE_ACTIVE;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(NULL_PTR != netcSIsBase[CtrlIndex]);
#endif

    if( 0U == (netcSIsBase[CtrlIndex]->SIMR & NETC_F3_SI0_SIMR_EN_MASK))
    {
        status = NETC_ETH_STATE_INACTIVE;
    }
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_AddMulticastDstAddrToHashFilter
 * implements     Netc_Eth_Ip_AddMulticastDstAddrToHashFilter_Activity 
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddMulticastDstAddrToHashFilter(uint8 CtrlIndex, \
                                                                   const uint8 *MacAddr)
{
    uint8 HashValue;
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_SUCCESS;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(NULL_PTR != Netc_Eth_Ip_apxState[CtrlIndex]);
#endif

    if (NETC_ETH_IP_PHYSICAL_SI == Netc_Eth_Ip_apxState[CtrlIndex]->SiType)
    {
        HashValue = Netc_Eth_Ip_ComputeMACHashValue(MacAddr);

        /* Add MAC entry in the software table. */
        Status = Netc_Eth_Ip_AddMACFilterEntry(CtrlIndex, HashValue, MacAddr);

        if(NETC_ETH_IP_STATUS_SUCCESS == Status)
        {
            /* 64 entries in table, the 5th bit of the HashValue selects between registers used. */
            if(0U != ((uint32)HashValue & NETC_ETH_IP_SELECT_HASH_REGISTER))
            {
                IP_NETC__ENETC0_BASE->NUM_SI[CtrlIndex].PSIMMHFR1 |= (uint32)(1U << (HashValue & NETC_ETH_IP_HASH_VALUE));
            }
            else
            {
                IP_NETC__ENETC0_BASE->NUM_SI[CtrlIndex].PSIMMHFR0 |= (uint32)(1U << (HashValue & NETC_ETH_IP_HASH_VALUE));
            }
        }
    }
    else
    {
        Status = Netc_Eth_Ip_VsiToPsiMsg(CtrlIndex, NETC_ETH_IP_VSITOPSI_ADD_RX_MAC_ADDR_FILTER, MacAddr);
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_RemoveMulticastDstAddrFromHashFilter
 * implements     Netc_Eth_Ip_RemoveMulticastDstAddrFromHashFilter_Activity 
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_RemoveMulticastDstAddrFromHashFilter(uint8 CtrlIndex, \
                                                                        const uint8 *MacAddr)
{
    uint8 HashValue;
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_SUCCESS;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(NULL_PTR != Netc_Eth_Ip_apxState[CtrlIndex]);
#endif

    if (NETC_ETH_IP_PHYSICAL_SI == Netc_Eth_Ip_apxState[CtrlIndex]->SiType)
    {
        HashValue = Netc_Eth_Ip_ComputeMACHashValue(MacAddr);

        Status = Netc_Eth_Ip_DeleteMACFilterEntry(CtrlIndex, HashValue, MacAddr);

        if(NETC_ETH_IP_STATUS_SUCCESS == Status)
        {
            /* 64 entries in table, the 5th bit of the HashValue selects between registers used. */
            if((HashValue & NETC_ETH_IP_SELECT_HASH_REGISTER) != (uint8)0U)
            {
                IP_NETC__ENETC0_BASE->NUM_SI[CtrlIndex].PSIMMHFR1 &= ~(1U << ((uint32)HashValue & NETC_ETH_IP_HASH_VALUE));
            }
            else
            {
                IP_NETC__ENETC0_BASE->NUM_SI[CtrlIndex].PSIMMHFR0 &= ~(1U << ((uint32)HashValue & NETC_ETH_IP_HASH_VALUE));
            }
        }
    }
    else
    {
        Status = Netc_Eth_Ip_VsiToPsiMsg(CtrlIndex, NETC_ETH_IP_VSITOPSI_DELETE_RX_MAC_ADDR_FILTER, MacAddr);
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_SetMulticastForwardAll
 * implements     Netc_Eth_Ip_SetMulticastForwardAll_Activity 
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_SetMulticastForwardAll(uint8 CtrlIndex, boolean EnableMulticast)
{
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_SUCCESS;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(NULL_PTR != Netc_Eth_Ip_apxState[CtrlIndex]);
#endif

    if (NETC_ETH_IP_PHYSICAL_SI == Netc_Eth_Ip_apxState[CtrlIndex]->SiType)
    {
        if(EnableMulticast)
        {
            /* Enable MAC multicast promiscuous mode. */
            IP_NETC__ENETC0_BASE->PSIPMMR |=(uint32) (1U << (CtrlIndex + NETC_F3_PSIPMMR_SI0_MAC_MP_SHIFT));
        }
        else
        {
            /* Disable MAC multicast promiscuous mode. */
            IP_NETC__ENETC0_BASE->PSIPMMR &= ~(uint32)(1U << (CtrlIndex + NETC_F3_PSIPMMR_SI0_MAC_MP_SHIFT));
        }
    }
    else
    {
        if(EnableMulticast)
        {
            /* Enable MAC multicast promiscuous mode. */
            Status = Netc_Eth_Ip_VsiToPsiMsg(CtrlIndex, NETC_ETH_IP_VSITOPSI_ENABLE_MULTICAST, NULL_PTR);
        }
        else
        {
            /* Disable MAC multicast promiscuous mode. */
            Status = Netc_Eth_Ip_VsiToPsiMsg(CtrlIndex, NETC_ETH_IP_VSITOPSI_DISABLE_MULTICAST, NULL_PTR);
        }
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_CloseMulticastReceiving
 * implements     Netc_Eth_Ip_CloseMulticastReceiving_Activity 
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_CloseMulticastReceiving(uint8 CtrlIndex)
{
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_SUCCESS;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(NULL_PTR != Netc_Eth_Ip_apxState[CtrlIndex]);
#endif

    if (NETC_ETH_IP_PHYSICAL_SI == Netc_Eth_Ip_apxState[CtrlIndex]->SiType)
    {
        /* Disable MAC multicast promiscuous mode. */
        IP_NETC__ENETC0_BASE->PSIPMMR &= ~(uint32)(1U << (CtrlIndex + NETC_F3_PSIPMMR_SI0_MAC_MP_SHIFT));

        IP_NETC__ENETC0_BASE->NUM_SI[CtrlIndex].PSIMMHFR1 = 0x0U;
        IP_NETC__ENETC0_BASE->NUM_SI[CtrlIndex].PSIMMHFR0 = 0x0U;
    }
    else
    {
        /* Disable MAC multicast promiscuous mode. */
        Status = Netc_Eth_Ip_VsiToPsiMsg(CtrlIndex, NETC_ETH_IP_VSITOPSI_CLOSE_FILTER, NULL_PTR);
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_SetTxCoalescingThresholds
 * implements     Netc_Eth_Ip_SetTxCoalescingThresholds_Activity 
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_SetTxCoalescingThresholds(uint8 CtrlIdx, uint8 RingIdx, uint16 PacketsThreshold, uint32 TimerThreshold)
{

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIdx < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(NULL_PTR != Netc_Eth_Ip_apxState[CtrlIdx]);
#endif
    boolean TxCoalescingIsrEnabled =  ((Netc_Eth_Ip_apxState[CtrlIdx]->TxTimerThreshold[RingIdx] != 0U) &&
                                       (Netc_Eth_Ip_apxState[CtrlIdx]->TxPacketsThreshold[RingIdx] != 0U)) ? TRUE : FALSE ;

    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_ERROR;
    uint8 HwValueOfPackets = 0U;

    if (TxCoalescingIsrEnabled)
    {
        if (PacketsThreshold <= Netc_Eth_Ip_apxState[CtrlIdx]->TxRingSize[RingIdx])
        {
            /* First disable the Coalescing ISR AND clear the previous values. */
            netcSIsBase[CtrlIdx]->BDR_NUM[RingIdx].TBICR0 &= ~NETC_F3_SI0_TBICR0_ICEN_MASK;
            netcSIsBase[CtrlIdx]->BDR_NUM[RingIdx].TBICR1  &= NETC_F3_SI0_TBICR1_ICTT_MASK;
            netcSIsBase[CtrlIdx]->BDR_NUM[RingIdx].TBICR0  &= NETC_F3_SI0_TBICR0_ICPT_MASK;

            if (TimerThreshold != 0U)
            {
                /*If timer threshold is used it should be set when TBaICR0[ICEN]=0 to avoid missing a "firstpacket" transmitted condition which starts the timer.*/
                netcSIsBase[CtrlIdx]->BDR_NUM[RingIdx].TBICR1 |= NETC_F3_SI0_TBICR1_ICTT(TimerThreshold);
                Netc_Eth_Ip_apxState[CtrlIdx]->TxTimerThreshold[RingIdx] = TimerThreshold;
            }

            if (PacketsThreshold != 0U)
            {
                HwValueOfPackets = Netc_Eth_Ip_CoalescingTxPacketsConversion(PacketsThreshold);
                /*If packet threshold is used it should be set when TBaICR0[ICEN] is set */
                netcSIsBase[CtrlIdx]->BDR_NUM[RingIdx].TBICR0 |= (NETC_F3_SI0_TBICR0_ICEN_MASK | NETC_F3_SI0_TBICR0_ICPT(HwValueOfPackets));
                Netc_Eth_Ip_apxState[CtrlIdx]->TxPacketsThreshold[RingIdx] = HwValueOfPackets;
            }

            /* Case when the ICEN bit is not enabled when Timer Threshold is set */
            if ((PacketsThreshold != 0U) && (TimerThreshold == 0U))
            {
                netcSIsBase[CtrlIdx]->BDR_NUM[RingIdx].TBICR0 |= NETC_F3_SI0_TBICR0_ICEN_MASK;
            }

            Status = NETC_ETH_IP_STATUS_SUCCESS;
        }
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_SetRxCoalescingThresholds
 * implements     Netc_Eth_Ip_SetRxCoalescingThresholds_Activity 
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_SetRxCoalescingThresholds(uint8 CtrlIdx, uint8 RingIdx, uint16 PacketsThreshold, uint32 TimerThreshold)
{

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIdx < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(NULL_PTR != Netc_Eth_Ip_apxState[CtrlIdx]);
#endif
    boolean RxCoalescingIsrEnabled =  ((Netc_Eth_Ip_apxState[CtrlIdx]->RxTimerThreshold[RingIdx] != 0U) &&
                                       (Netc_Eth_Ip_apxState[CtrlIdx]->RxPacketsThreshold[RingIdx] != 0U)) ? TRUE : FALSE ;
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_ERROR;

    if (RxCoalescingIsrEnabled)
    {
        if (PacketsThreshold <= Netc_Eth_Ip_apxState[CtrlIdx]->RxRingSize[RingIdx])
        {
            /* First disable the Coalescing ISR AND clear the previous values. */
            netcSIsBase[CtrlIdx]->BDR_NUM[RingIdx].RBICR0 &= ~NETC_F3_SI0_RBICR0_ICEN_MASK;
            netcSIsBase[CtrlIdx]->BDR_NUM[RingIdx].RBICR1 &= ~NETC_F3_SI0_RBICR1_ICTT_MASK;
            netcSIsBase[CtrlIdx]->BDR_NUM[RingIdx].RBICR0 &= ~NETC_F3_SI0_RBICR0_ICPT_MASK;

            if (PacketsThreshold != 0U )
            {
                /*If timer threshold is used it should be set when RBaICR0[ICEN]=0 to avoid missing a "first packet" received condition which starts the timer.*/
                netcSIsBase[CtrlIdx]->BDR_NUM[RingIdx].RBICR0 |= NETC_F3_SI0_RBICR0_ICPT(PacketsThreshold);
                Netc_Eth_Ip_apxState[CtrlIdx]->RxPacketsThreshold[RingIdx] = PacketsThreshold;
            }

            if (TimerThreshold != 0U)
            {
                netcSIsBase[CtrlIdx]->BDR_NUM[RingIdx].RBICR1 |= NETC_F3_SI0_RBICR1_ICTT(TimerThreshold);
                Netc_Eth_Ip_apxState[CtrlIdx]->RxTimerThreshold[RingIdx] = TimerThreshold;
            }

            if ((PacketsThreshold != 0U)|| (TimerThreshold != 0U))
            {
                netcSIsBase[CtrlIdx]->BDR_NUM[RingIdx].RBICR0 |= NETC_F3_SI0_RBICR0_ICEN_MASK;
            }

            Status = NETC_ETH_IP_STATUS_SUCCESS;
        }
    }

    return Status;
}

#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
#ifdef NETC_ETH_0_USED
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_ManagementFrame
 * implements     Netc_Eth_Ip_ManagementFrame_Activity 
 *END**************************************************************************/
void Netc_Eth_Ip_ManagementFrame(uint8 CtrlIdx, uint16 BuffIdx, const Netc_Eth_Ip_TxTimestampInfoType *ManagementInfo, boolean Status)
{
    uint16 CurrentIndex;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIdx < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
#endif

    CurrentIndex = Netc_Eth_Ip_apxState[CtrlIdx]->LogicTxProducerIndex[0U];

    Netc_Eth_Ip_TxTimestampInfoBuff[0U][CurrentIndex / (uint16)NETC_ETH_IP_PRODUCER_INCR].CtrlIdx = CtrlIdx;
    Netc_Eth_Ip_TxTimestampInfoBuff[0U][CurrentIndex / (uint16)NETC_ETH_IP_PRODUCER_INCR].TxBuffId = BuffIdx;
    Netc_Eth_Ip_TxTimestampInfoBuff[0U][CurrentIndex / (uint16)NETC_ETH_IP_PRODUCER_INCR].SwitchIndex = ManagementInfo->SwitchIndex;
    Netc_Eth_Ip_TxTimestampInfoBuff[0U][CurrentIndex / (uint16)NETC_ETH_IP_PRODUCER_INCR].PortIndex = ManagementInfo->PortIndex;
    Netc_Eth_Ip_TxTimestampInfoBuff[0U][CurrentIndex / (uint16)NETC_ETH_IP_PRODUCER_INCR].ManagementFrameFlag = Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_GetTxTimestampInfo
 * implements     Netc_Eth_Ip_GetTxTimestampInfo_Activity 
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetTxTimestampInfo(const uint8 CtrlIdx, \
                                                      const uint32 BuffIdx, \
                                                      Netc_Eth_Ip_TxTimestampInfoType **TimestampInfo)
{
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_ERROR;
    uint32 BufferIdx;
    uint16 FirstTimestampID;
    uint16 LatestTimestampID;
    boolean FirstTimestampFlag = FALSE;
    *TimestampInfo = NULL_PTR;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIdx < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
#endif

    for(BufferIdx = 0U; BufferIdx < NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR; BufferIdx++)
    {
        if (BuffIdx == (uint32)Netc_Eth_Ip_TxTimestampInfoBuff[0u][BufferIdx].TxBuffId)
        {
            if(FALSE == FirstTimestampFlag)
            {
                FirstTimestampID = Netc_Eth_Ip_TxTimestampInfoBuff[0u][BufferIdx].TxTimeStampID;
                FirstTimestampFlag = TRUE;
                *TimestampInfo = &Netc_Eth_Ip_TxTimestampInfoBuff[0u][BufferIdx];
            }
            else
            {
                LatestTimestampID = Netc_Eth_Ip_TxTimestampInfoBuff[0u][BufferIdx].TxTimeStampID;

                if(LatestTimestampID > FirstTimestampID)
                {
                    *TimestampInfo = &Netc_Eth_Ip_TxTimestampInfoBuff[0u][BufferIdx];
                }
            }
            Status = NETC_ETH_IP_STATUS_SUCCESS;
        }
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_ReleaseUnusedTxBuff
 * implements     Netc_Eth_Ip_ReleaseUnusedTxBuff_Activity 
 *END**************************************************************************/
void Netc_Eth_Ip_ReleaseUnusedTxBuff(uint8 CtrlIndex, uint8 Ring)
{
    uint32 CurrentProducerIdx;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(Netc_Eth_Ip_apxState[CtrlIndex] != NULL_PTR);
    DevAssert(Ring < Netc_Eth_Ip_apxState[CtrlIndex]->NumberOfTxBDR);
#endif

    CurrentProducerIdx = Netc_Eth_Ip_apxState[CtrlIndex]->LogicTxProducerIndex[Ring];
    Netc_Eth_Ip_apxState[CtrlIndex]->LockTxBuffDescr[Ring][CurrentProducerIdx] = FALSE;

    if(CurrentProducerIdx == (uint32)0U)
    {
        Netc_Eth_Ip_apxState[CtrlIndex]->TxNextDesc[Ring] = Netc_Eth_Ip_apxState[CtrlIndex]->FirstTxRingDescAddr[Ring];
    }
    else
    {
        Netc_Eth_Ip_apxState[CtrlIndex]->TxNextDesc[Ring] = Netc_Eth_Ip_apxState[CtrlIndex]->FirstTxRingDescAddr[Ring] + \
                                                            (CurrentProducerIdx / (uint32)NETC_ETH_IP_PRODUCER_INCR);
    }
}
#endif /* NETC_ETH_0_USED */

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_GetRxTimestampInfo
 * implements     Netc_Eth_Ip_GetRxTimestampInfo_Activity 
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetRxTimestampInfo(uint8 CtrlIdx, const uint8 *DataPtr, Netc_Eth_Ip_RxTimestampInfoType **RxTimestampInfo)
{
    uint8 RingCounter;
    uint32 DescrCounter;;
    uint32 LastRxTimestampID = (uint32)0U;
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_ERROR;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIdx < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(DataPtr != NULL_PTR);
#endif

    *RxTimestampInfo = NULL_PTR;

    for (RingCounter = 0U; RingCounter < Netc_Eth_Ip_apxState[CtrlIdx]->NumberOfRxBDR; RingCounter++)
    {
        for(DescrCounter = 0U; DescrCounter < NETC_ETH_IP_MAX_NUMBER_OF_RXDESCRIPTORS; DescrCounter++)
        {
            /* Pointer for searched data was found. */
            if (DataPtr == Netc_Eth_Ip_RxTimestampInfoBuff[CtrlIdx][RingCounter][DescrCounter].ReceivedDataPtr)
            {
                if(RingCounter == Netc_Eth_Ip_RxTimestampInfoBuff[CtrlIdx][RingCounter][DescrCounter].RingIdx)
                {
                    /* Assure that current data is valid. */
                    if((boolean)FALSE == Netc_Eth_Ip_RxTimestampInfoBuff[CtrlIdx][RingCounter][DescrCounter].TimestampValueInvalidForSwt)
                    {
                        if(Netc_Eth_Ip_RxTimestampInfoBuff[CtrlIdx][RingCounter][DescrCounter].TimestampID > LastRxTimestampID)
                        {
                            Netc_Eth_Ip_RxTimestampInfoBuff[CtrlIdx][RingCounter][DescrCounter].TimestampValueInvalidForSwt = (boolean)TRUE;
                            LastRxTimestampID = Netc_Eth_Ip_RxTimestampInfoBuff[CtrlIdx][RingCounter][DescrCounter].TimestampID;
                            *RxTimestampInfo = &Netc_Eth_Ip_RxTimestampInfoBuff[CtrlIdx][RingCounter][DescrCounter];
                            Status = NETC_ETH_IP_STATUS_SUCCESS;
                        }
                        else
                        {
                            /* Mark the rest of timestamps as invalid.
                            This mechanism will helps not to read wrong timestamps for consecutives calls of function. */
                            Netc_Eth_Ip_RxTimestampInfoBuff[CtrlIdx][RingCounter][DescrCounter].TimestampValueInvalidForSwt = (boolean)TRUE;
                        }
                    }
                }
            }
        }
    }

    return Status;
}

#endif /* STD_ON == NETC_ETH_IP_EXTENDED_BUFF */

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_GetCurrentTime
 * implements     Netc_Eth_Ip_GetCurrentTime_Activity 
 *END**************************************************************************/
void Netc_Eth_Ip_GetCurrentTime(uint8 ctrlIndex, Netc_Eth_Ip_TimeType *TimePtr)
{

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex <  FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(TimePtr != NULL_PTR);
#endif

    Netc_Eth_Ip_GetCurrentTick(ctrlIndex, TimePtr);
}

#define ETH_43_NETC_STOP_SEC_CODE
#include "Eth_43_NETC_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
