/*
 * Copyright 2021-2023 NXP
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
#include "SchM_Eth_43_NETC.h"

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
#define NETC_ETH_IP_SW_MAJOR_VERSION_C               1
#define NETC_ETH_IP_SW_MINOR_VERSION_C               0
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
#define NETC_ETH_IP_NANO_TO_SECONDS(x) ((x)/1000000000U)
#define NETC_ETH_IP_GET_NANOSECONDS(x) ((x)%1000000000U)
/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/
/* Formula for speed: 10Mbps * (PSPEED+1) */
#define NETC_ETH_IP_SHAPING_PSPEED_2000MBITS (199U)

#define NETC_ETH_IP_SECONDS_LOW_MASK_U64  (0xFFFFFFFFULL)

#define NETC_ETH_IP_FATAL_ERROR (0x1u)
#define NETC_ETH_IP_NON_FATAL_ERROR (0x2u)
#define NETC_ETH_IP_CORRECTABLE_ERROR (0x4u)
#define NETC_ETH_IP_PSI0_FUNCTION_INDEX (4u)
#define NETC_ETH_IP_CLEAR_ERROR_STATUS_MASK (0x80000000U)

#define NETC_ETH_IP_UCORR_STATUS_BIT ((uint32)NETC_F1_PCI_HDR_TYPE0_PCIE_CFC_AER_UCORR_ERR_STAT_UCORR_INT_ERR_MASK)
#define NETC_ETH_IP_CORR_STATUS_BIT ((uint32)NETC_F1_PCI_HDR_TYPE0_PCIE_CFC_AER_CORR_ERR_STAT_CORR_INT_ERR_MASK)
#define NETC_ETH_IP_UCORR_ERR_MASK_BIT ((uint32)NETC_F1_PCI_HDR_TYPE0_PCIE_CFC_AER_UCORR_ERR_MASK_UCORR_INT_ERR_MASK_MASK)
#define NETC_ETH_IP_CORR_ERR_MASK_BIT ((uint32)NETC_F1_PCI_HDR_TYPE0_PCIE_CFC_AER_CORR_ERR_MASK_CORR_INT_MASK_MASK)
#define NETC_ETH_IP_UCORR_ERR_MASK_SHIFT (NETC_F1_PCI_HDR_TYPE0_PCIE_CFC_AER_UCORR_ERR_MASK_UCORR_INT_ERR_MASK_SHIFT)
#define NETC_ETH_IP_CORR_ERR_MASK_SHIFT (NETC_F1_PCI_HDR_TYPE0_PCIE_CFC_AER_CORR_ERR_MASK_CORR_INT_MASK_SHIFT)
#define NETC_ETH_IP_UCORR_SEV_MASK ((uint32)NETC_F1_PCI_HDR_TYPE0_PCIE_CFC_AER_UCORR_ERR_SEV_UCORR_INT_SEV_MASK)
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
extern Netc_Eth_Ip_PCIeBaseType *netcPCIePFBase[FEATURE_NETC_NUMBER_OF_FUNC];
#define ETH_43_NETC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"

#define ETH_43_NETC_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_43_NETC_MemMap.h"
extern Netc_Eth_Ip_MACFilterHashTableEntryType *MACFilterHashTableAddrs[FEATURE_NETC_ETH_NUMBER_OF_CTRLS];

#define ETH_43_NETC_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
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
*                                        GLOBAL VARIABLES
==================================================================================================*/

#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
#ifdef NETC_ETH_0_USED
#define ETH_43_NETC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"
/** @brief Store timestamp information of transmitted frames. */
extern volatile Netc_Eth_Ip_TxManagementInfoType Netc_Eth_Ip_TxManagementInfoBuff[NETC_ETH_IP_NUM_OF_PHYSICAL_CTRLS][NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR];
extern volatile Netc_Eth_Ip_TxTimestampInfoType Netc_Eth_Ip_TxTimestampInfoBuff[NETC_ETH_IP_NUM_OF_PHYSICAL_CTRLS][NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR];
#define ETH_43_NETC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"
#endif /* NETC_ETH_0_USED */

#define ETH_43_NETC_START_SEC_VAR_CLEARED_32
#include "Eth_43_NETC_MemMap.h"
#ifdef NETC_ETH_0_USED
/** @brief Store timestamp information of transmitted frames. */

static uint32 TxTimestampInfoBuffIdx = 0U;

#endif /* NETC_ETH_0_USED */

static uint32 Netc_Eth_Ip_RxTimestampID = (uint32)0U;

#define ETH_43_NETC_STOP_SEC_VAR_CLEARED_32
#include "Eth_43_NETC_MemMap.h"

/** @brief Store timestamp information of received frames. */
/** TODO: get the maximum of descr between variants */
extern volatile Netc_Eth_Ip_RxTimestampInfoType Netc_Eth_Ip_RxTimestampInfoBuff[FEATURE_NETC_ETH_NUMBER_OF_CTRLS][NETC_ETH_IP_MAX_NUMBER_OF_RXRINGS][NETC_ETH_IP_MAX_NUMBER_OF_RXDESCRIPTORS];
#endif /* STD_ON == NETC_ETH_IP_EXTENDED_BUFF */

#define ETH_43_NETC_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_43_NETC_MemMap.h"

/** @brief Pointers to NETC internal driver state for each controller(SI). */
Netc_Eth_Ip_StateType *Netc_Eth_Ip_apxState[FEATURE_NETC_ETH_NUMBER_OF_CTRLS];

/** @brief List of Error Reporting structures that aggregate information for each Pcie function in case of an error reported to the Event Collector. EMDIO, TIMER, SWITCH, ENETC, PSI0, VSI1-7*/
volatile Netc_Eth_Ip_PcieFunctionErrorsReported Netc_Eth_Ip_ErrorStatus[FEATURE_NETC_NUMBER_OF_FUNC + FEATURE_NETC_ETH_NUM_OF_VIRTUAL_CTRLS + 1U];

/* Enabled status for Time Aware Shaper for PSI */
static boolean  Netc_Eth_Ip_PortTimeAwareShaperEnabled = FALSE;

/* Table entries for Time Aware Shaping configuration */
static Netc_Eth_Ip_TimeGateSchedulingEntryDataType Netc_Eth_Ip_EthTimeGateSchedulingEntryData;

/* The frequency of the NETC module for computing CBS parameters */
static uint32 Netc_Eth_Ip_NetcClockFrequency = 0U;

/* Key element data for ingress port filter table */
static volatile uint32 IPFKeyeData[NETC_ETH_IP_INGRESSPORTFILTERTABLE_KEYE_DATA_LEN];

/* a 16 bytes aligned table request data buffer */
VAR_ALIGN(static volatile Netc_Eth_Ip_EnetcTableDataType Netc_Eth_Ip_EnetcTableDataBuffer, NETC_ETH_IP_TABLE_ALIGNED_SIZE)

#define ETH_43_NETC_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_43_NETC_MemMap.h"

#if (NETC_ETH_IP_HAS_CACHE_MANAGEMENT == STD_ON)
/*  FEATURE_NETC_CACHABLE_BUFFERS_LMEM and FEATURE_NETC_CACHABLE_BUFFERS_CORE are generated based on the
platform and the core type in case both cache IPs are supported.
    These macros must be both defined for the driver when the cache management feature is enabled.
    They must not be simultaneosly enabled at runtime.*/
    #ifdef FEATURE_NETC_CACHABLE_BUFFERS_LMEM
        #ifdef FEATURE_NETC_CACHABLE_BUFFERS_CORE
#define ETH_43_NETC_START_SEC_CONST_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"
            #if (FEATURE_NETC_CACHABLE_BUFFERS_LMEM > 0U)
/** @brief Global variable which contains the type of CACHE Type used on the current platform.
 *          CACHE_IP_LMEM is using LMEM peripheral.
 *          CACHE_IP_CORE is using SCB peripheral.
*/
static const Cache_Ip_Type CacheType = CACHE_IP_LMEM;
            #elif (FEATURE_NETC_CACHABLE_BUFFERS_CORE > 0U)
/** @brief Global variable which contains the type of CACHE Type used on the current platform.
 *          CACHE_IP_LMEM is using LMEM peripheral.
 *          CACHE_IP_CORE is using SCB peripheral.
*/
static const Cache_Ip_Type CacheType = CACHE_IP_CORE;
            #endif
#define ETH_43_NETC_STOP_SEC_CONST_UNSPECIFIED
#include "Eth_43_NETC_MemMap.h"
        #endif /* defined (FEATURE_NETC_CACHABLE_BUFFERS_CORE) */
    #endif /* defined (FEATURE_NETC_CACHABLE_BUFFERS_LMEM) */
#endif /*NETC_HAS_CACHE_MANAGEMENT == STD_ON */

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
 */
static void Netc_Eth_Ip_InitCBDR(uint8 ctrlIndex);

/**
 * @brief This function will be used to enable and set all the configuration for interrupt.
 * @details Number of defaults MSI entries in table for ENETC is 48.
 *
 * @param ctrlIndex Number of the current SI.
 * @param config    General configuration of the controller.
 */
void Netc_Eth_Ip_EnableIrq(uint8 ctrlIndex, const Netc_Eth_Ip_ConfigType *config);

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
                                                             const uint8 *MacAddr, \
                                                             uint16 * PsiRspMessage );
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
static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_WaitVsiToPsiMsgTransmission(uint8 VsiId, const Netc_Eth_Ip_VsiToPsiMsgType *MsgCommandConfig, uint16 * PsiRspMessage);

/**
 * @brief Performs a transformation to a hardware specific value which sets the
 *        packets threshold for tx colaescing interrupt.
 *        The return value is a hardware specific value which will be set in the ICTT part of the TBxICR0 register. It will be
 *                  the greatest value which satisfies the following formula.
 *        PacketsThreshold >= 2 ^(TwoPow-1)
 *
 *
 * @param PacketsThreshold The number of packets for coalescing interrupt.
 * @return uint8 Hardware specific value which will be set in the ICTT part of the TBxICR0 register. It will be
 *                  the greatest value which satisfies the following formula.
 */
static uint8 Netc_Eth_Ip_CoalescingTxPacketsConversion (uint16 PacketsThreshold);

/**
 * @brief Setup the PCIE Event collector Error reporting registers
 *
 * @param psi0Config User Configuration
 * @return Netc_Eth_Ip_StatusType Error in case the memory access wasn't enabled beforehand.
 */
static Netc_Eth_Ip_StatusType Netc_Eth_Ip_SetupErrorReporting(const Netc_Eth_Ip_EnetcGeneralConfigType *psi0Config);

#if (NETC_ETH_IP_NUMBER_OF_VLAN_FILTER_ENTRIES > 0U)
/**
 * @brief            VLAN Filter table configuration function
 *
 * @param[in]        Config: Pointer to the configuration for initalisation
 *
 * @return           Result of the operation
 * @retval           0 : E_OK, success
 * @retval           1 : E_NOT_OK, fail
 */
static Netc_Eth_Ip_StatusType Netc_Eth_Ip_ConfigVLANFilterTable(uint8 ctrlIndex, const Netc_Eth_Ip_ConfigType * Config);
#endif

/*!
 * @brief   : Function for initializing NTMP table.
 * @details : Function enables the netc controller, initializes the tables and then diasbles the netc controller
 *
 * @param[in] ctrlIndex controller index
 * @param[in] config controller configuration
 *
 */
static inline void Netc_Eth_Ip_InitNTMPTables(uint8 ctrlIndex, const Netc_Eth_Ip_ConfigType *config);

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
static void Netc_Eth_Ip_GetCurrentTick(uint8 ctrlIndex, Netc_Eth_Ip_TimeType *TimePtr)
{
    /* Read the low register, then immediately read the high register to get a synchronised 64-bit time value */
    (*TimePtr).nanosecondsL = (uint32)(netcSIsBase[ctrlIndex]->SICTR0);
    (*TimePtr).nanosecondsH = (uint32)(netcSIsBase[ctrlIndex]->SICTR1);
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
    config->stateStructure->SiType                          =   config->SiType;
    config->stateStructure->MACFilterTableMaxNumOfEntries   = (*config->siConfig).MACFilterTableMaxNumOfEntries;
    config->stateStructure->CtrlLogicalIndex                = (*config->siConfig).CtrlLogicalIndex;
#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
    config->stateStructure->RxDataBuffAddr  = (*config).rxExternalBuffersAddr;
#endif

    /*SI runtime permissions */
    if (NETC_ETH_IP_PHYSICAL_SI == config->SiType)
    {
        config->stateStructure->SIGeneralConfig = config->generalConfig->stationInterfaceGeneralConfig;
        config->stateStructure->generalConfig = config->generalConfig;

        config->stateStructure->PcieAerUncorrectableErrEnabled = (*config->generalConfig).enableUncorrectableErrors;
        config->stateStructure->PcieAerCorrectableErrEnabled = (*config->generalConfig).enableCorrectableErrors;
        config->stateStructure->PcieAerErrorReportingCallback = (*config->generalConfig).errorReportingCallback;
    }
    else
    {
        config->stateStructure->SIGeneralConfig = NULL_PTR;
        config->stateStructure->generalConfig = NULL_PTR;

        config->stateStructure->PcieAerUncorrectableErrEnabled = FALSE;
        config->stateStructure->PcieAerCorrectableErrEnabled = FALSE;
        config->stateStructure->PcieAerErrorReportingCallback = NULL_PTR;
    }

    config->stateStructure->EnetcCommandBDConfig.commandBDAddr = (*config->siConfig).commandBDConfig.commandBDAddr;
    config->stateStructure->EnetcCommandBDConfig.lengthCBDR = (*config->siConfig).commandBDConfig.lengthCBDR;



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
        netcSIsBase[ctrlIndex]->BDR_NUM[currentTxBDR].TBPIR = 0U;
        netcSIsBase[ctrlIndex]->BDR_NUM[currentTxBDR].TBCIR = 0U;
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
            if (((uint8)0U == ctrlIndex) && ((uint8)0U == currentTxBDR))
            {
                Netc_Eth_Ip_TxManagementInfoBuff[ctrlIndex][currBDIdx].TxTimestampFlag = FALSE;
                Netc_Eth_Ip_TxManagementInfoBuff[ctrlIndex][currBDIdx].ManagementFrameFlag = FALSE;
                Netc_Eth_Ip_TxManagementInfoBuff[ctrlIndex][currBDIdx].TxTimestampRcvFlag = FALSE;
                Netc_Eth_Ip_TxManagementInfoBuff[ctrlIndex][currBDIdx].TxTimeStampID = (uint16)0xFFFFU;
                Netc_Eth_Ip_TxManagementInfoBuff[ctrlIndex][currBDIdx].TxBuffId = (uint16)0xFFFFU;
                Netc_Eth_Ip_TxManagementInfoBuff[ctrlIndex][currBDIdx].PortIndex = (uint8)0xFFU;
            }
    #endif
#endif
#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_TX_BUFFERS)
            if (!Netc_Eth_Ip_ControllerHasExternalTxBufferManagement[ctrlIndex])
            {
                /* Write in the buffer descriptor the address of the allocated buffer */
                TempTxDescr->dataBuffAddr = (uint32)((*config->paCtrlTxRingConfig)[currentTxBDR].Buffer) + \
                                                    (uint32)(currBDIdx * (*config->paCtrlTxRingConfig)[currentTxBDR].maxBuffLen);
            }
#endif

            /* Write in the buffer descriptor the address of the allocated buffer */
            TempTxDescr->dataBuffAddr = (uint32)((*config->paCtrlTxRingConfig)[currentTxBDR].Buffer) + \
                                                (uint32)(currBDIdx * (*config->paCtrlTxRingConfig)[currentTxBDR].maxBuffLen);

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
            Netc_Eth_Ip_RxTimestampInfoBuff[ctrlIndex][u8RxBDIdx][DataBuffIndex].TimestampValueInvalidForSwt = (boolean)TRUE;
#endif
            pTempDescr->configRxBD[0U] = (uint32)((*config->paCtrlRxRingConfig)[u8RxBDIdx].Buffer) + \
                                                  (uint32)(DataBuffIndex * (*config->paCtrlRxRingConfig)[u8RxBDIdx].maxBuffLen);
            pTempDescr++;
        }
#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
        }
#endif

    }
}

static void Netc_Eth_Ip_InitCBDR(uint8 ctrlIndex)
{

    netcSIsBase[ctrlIndex]->SICBDRBAR0 = (uint32)(Netc_Eth_Ip_apxState[ctrlIndex]->EnetcCommandBDConfig.commandBDAddr);
    netcSIsBase[ctrlIndex]->SICBDRLENR = NETC_F3_SI0_SICBDRLENR_LENGTH(Netc_Eth_Ip_apxState[ctrlIndex]->EnetcCommandBDConfig.lengthCBDR);
    netcSIsBase[ctrlIndex]->SICBDRPIR  = NETC_F3_SI0_SICBDRPIR_BDR_INDEX(0U);
    netcSIsBase[ctrlIndex]->SICBDRCIR  = NETC_F3_SI0_SICBDRCIR_BDR_INDEX(0U);
    netcSIsBase[ctrlIndex]->SICBDRMR   = NETC_F3_SI0_SICBDRMR_EN(1U);
}

void Netc_Eth_Ip_EnableIrq(uint8 ctrlIndex, const Netc_Eth_Ip_ConfigType *config)
{
    uint8 rxBDRIndex;
    uint8 txBDRIndex;
    Netc_Eth_Ip_MSITable *msiTableConfig;
    Netc_Eth_Ip_VfBaseType *VSIConfig;
    uint32* msiBaseAddr[] = NETC_ETH_IP_MSI_BASE_PTRS;
    NETC_F3_PCI_HDR_TYPE0_Type *PSIConfig = IP_NETC__NETC_F3_PCI_HDR_TYPE0;

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
            netcSIsBase[ctrlIndex]->INTERRUPT.PSI.PSIIER |= 0xFE00FEU;
        }
    }


    if ((*config->siConfig).siMsgMruMailboxAddr != NULL_PTR)
    {
        msiTableConfig->msiTable[NETC_ETH_IP_SITOSI_MESSAGE_MSI_TABLE_INDEX].msgAddr       = (*config->siConfig).siMsgMruMailboxAddr;
        msiTableConfig->msiTable[NETC_ETH_IP_SITOSI_MESSAGE_MSI_TABLE_INDEX].controlVector = 0x0U;
        msiTableConfig->msiTable[NETC_ETH_IP_SITOSI_MESSAGE_MSI_TABLE_INDEX].msgData       = 0xFFFFFFFFU;

        if (NETC_ETH_IP_PHYSICAL_SI == config->SiType)
        {
            netcSIsBase[ctrlIndex]->INTERRUPT.PSI.PSIIER |= 0xFE00FEU;
        }
    }

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

static inline Netc_Eth_Ip_StatusType Netc_Eth_Ip_WaitVsiToPsiMsgTransmission(uint8 VsiId, const Netc_Eth_Ip_VsiToPsiMsgType *MsgCommandConfig, uint16 * PsiRspMessage )
{
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    Netc_Eth_Ip_StatusType Status;
    Netc_Eth_Ip_StatusType PSIResponseStatus;

    /*Assure the data to be sent is synchronised*/
    MCAL_DATA_SYNC_BARRIER();
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

            /* If the message was successfully transmited, copy the index value, or the user defined Message Code, received from PSI */
            if(NETC_ETH_IP_STATUS_SUCCESS == Status )
            {
                PSIResponseStatus = (Netc_Eth_Ip_StatusType) (((Netc_Eth_Ip_VsiBaseType*) netcSIsBase[VsiId])->MSGSR.VSI_A.VSIMSGRR >> NETC_ETH_IP_PSI_MSG_POS );

                if(NETC_ETH_IP_PSITOVSI_CMD_SUCCESFUL == PSIResponseStatus)
                {
                    Status = NETC_ETH_IP_STATUS_SUCCESS;
                }
                else if(NETC_ETH_IP_PSITOVSI_SYNC_STATUS_TRUE == PSIResponseStatus)
                {
                    /*load sync state into the output partameter*/
                    *PsiRspMessage = TRUE;
                    Status = NETC_ETH_IP_STATUS_SUCCESS;
                }
                else if(NETC_ETH_IP_PSITOVSI_SYNC_STATUS_FALSE == PSIResponseStatus)
                {
                    *PsiRspMessage = FALSE;
                    Status = NETC_ETH_IP_STATUS_SUCCESS;
                }
                else /*PSI Status Return have only 4 value*/
                {
                    Status = NETC_ETH_IP_STATUS_ERROR;
                }
            }

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
        SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_00();
        if(FALSE == MACFilterHashTableAddrs[CtrlIndex][CurrentEntry].EntryStatus)
        {
            MACFilterHashTableAddrs[CtrlIndex][CurrentEntry].EntryStatus = TRUE;
            SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_00();

            MACFilterHashTableAddrs[CtrlIndex][CurrentEntry].HashValue   = HashValue;
            for(CurrentMACByte = 0U; CurrentMACByte < NETC_ETH_IP_MAC_BYTES_SIZE;CurrentMACByte++)
            {
                MACFilterHashTableAddrs[CtrlIndex][CurrentEntry].MACAddr[CurrentMACByte] = MacAddr[CurrentMACByte];
            }
            Status = NETC_ETH_IP_STATUS_SUCCESS;
            break;
        }
        else
        {
            SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_00();
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
        SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_01();
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
                    SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_01();
                }
                else
                {
                    SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_01();
                }
            }
            else
            {
                SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_01();
            }
        }
        else
        {
            SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_01();
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
                                                             const uint8 *MacAddr, \
                                                             uint16 * PsiRspMessage)
{
    Netc_Eth_Ip_StatusType Status;
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
            Status = Netc_Eth_Ip_WaitVsiToPsiMsgTransmission(VsiId, MsgCommandConfig, PsiRspMessage);
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
                Status = Netc_Eth_Ip_WaitVsiToPsiMsgTransmission(VsiId, MsgCommandConfig, PsiRspMessage);
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
                Status = Netc_Eth_Ip_WaitVsiToPsiMsgTransmission(VsiId, MsgCommandConfig, PsiRspMessage);
            }

            break;
        }
        case NETC_ETH_IP_VSITOPSI_ENABLE_MULTICAST:
        {
            /* Set class for command message. */
            MsgCommandConfig->Class   = (uint8)0x10U;
            MsgCommandConfig->Command = (uint8)0x00U;
            Status = Netc_Eth_Ip_WaitVsiToPsiMsgTransmission(VsiId, MsgCommandConfig, PsiRspMessage);
            break;
        }
        case NETC_ETH_IP_VSITOPSI_DISABLE_MULTICAST:
        {
            /* Set class for command message. */
            MsgCommandConfig->Class   = (uint8)0x10U;
            MsgCommandConfig->Command = (uint8)0x10U;
            Status = Netc_Eth_Ip_WaitVsiToPsiMsgTransmission(VsiId, MsgCommandConfig, PsiRspMessage);
            break;
        }
        case NETC_ETH_IP_VSITOPSI_CLOSE_FILTER:
        {
            /* Set class for command message. */
            MsgCommandConfig->Class   = (uint8)0x10U;
            MsgCommandConfig->Command = (uint8)0x20U;
            Status = Netc_Eth_Ip_WaitVsiToPsiMsgTransmission(VsiId, MsgCommandConfig, PsiRspMessage);
            break;
        }
        case NETC_ETH_IP_VSITOPSI_GET_SYNC_STATE:
        {
            /* Set class for command message. */
            MsgCommandConfig->Class   = (uint8)0x20U;
            MsgCommandConfig->Command = (uint8)0x00U;
            Status = Netc_Eth_Ip_WaitVsiToPsiMsgTransmission(VsiId, MsgCommandConfig, PsiRspMessage);
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

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_CoalescingTxPacketsConversion
 * Description   : Internal function for converting a number of packets to a hardware specific value using the formula:
 *                  PacketsThreshold - no of packets
 *                  TwoPow =  hardware specific value which will be set in the ICTT part of the TBxICR0 register. It will be
 *                       the greatest value which satisfies the following formula.
 *                  PacketsThreshold >= 2 ^(TwoPow-1)
 *
 *END**************************************************************************/
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

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_SendCommand
 * Description   : Internal function for adding an entry with different commands to command ring.
 *
 *END**************************************************************************/
static Netc_Eth_Ip_StatusType Netc_Eth_Ip_SendCommand(const uint8 CtrlIndex, const NetcEth_Ip_ReqHeaderTableOperationDataType *OperationData)
{
    uint32 producerIdx;
    uint32 consumerIdx;
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;
    uint32 PreviousProducerIdx;
    uint32 statusField;
    uint32 rrBit;
    uint32 errorField;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    boolean TimeExpired;

    /* read the producer and consumer index register */
    producerIdx = netcSIsBase[CtrlIndex]->SICBDRPIR;
    consumerIdx = netcSIsBase[CtrlIndex]->SICBDRCIR;

    /* check if the ring is full */
    if (((producerIdx + 0x1UL) % ((uint32)(Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.lengthCBDR) * NETC_ETH_IP_SET_OF_BD)) == consumerIdx)
    {
        status = NETC_ETH_IP_CBDRSTATUS_RINGFULL;  /* the ring is full */
    }
    else
    {
        SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_16();
        /* +++ fill in the NTMP request message header +++ */
        /* set the table address */
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_REQHEADER_ADDR_L] = (uint32)(&Netc_Eth_Ip_EnetcTableDataBuffer);

        /* set the length of request and response data buffer */
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_REQHEADER_LENGTHFIELD] = (NETC_ETH_IP_CMDBD_REQFMT_REQUEST_LENGTH(OperationData->ReqBuffLength) | NETC_ETH_IP_CMDBD_REQFMT_RESPONSE_LENGTH(OperationData->RspBuffLength));

        /* set RR = 0, CCI = 0, protocol version = 2, table id, access method and cmd */
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_REQHEADER_CONFIGFIELD] = 0x0; /* clear this field first */
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_REQHEADER_CONFIGFIELD] |= NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CMD(OperationData->Cmd);
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_REQHEADER_CONFIGFIELD] |= NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_ACCESS_METHOD(OperationData->AccessMethod);
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_REQHEADER_CONFIGFIELD] |= NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_TABLE_ID(OperationData->TableId);
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_REQHEADER_CONFIGFIELD] |= NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_VERSION(OperationData->Version);
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_REQHEADER_CONFIGFIELD] |= NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CCI(OperationData->CmdCompletionInt);
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_REQHEADER_CONFIGFIELD] |= NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_RR(0U);        /* RR bit has to be set to 0 */

        /* set NTMP version to 2.0*/
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_REQHEADER_NPFFIELD] = NETC_ETH_IP_CMDBD_REQFMT_NPF_FIELD(NETC_ETH_IP_CMDBD_REQFMT_NTMP_PROTOCOL_VERSION);
        /* --- fill in the NTMP request message header --- */
        SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_16();

        /* +++ write the produce index register and enable hardware to consume the command +++ */
        PreviousProducerIdx = producerIdx;        /* save the produce index before incrementing it manually */
        if ((producerIdx + 0x1UL) == ((uint32)(Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.lengthCBDR) * NETC_ETH_IP_SET_OF_BD))        /* adjust producer index */
        {
            producerIdx = 0x0UL;    /* when producerIdx equals ACTUAL_CBDR_LENGTH minus 1, then it would start from 0 again */
        }
        else
        {
            producerIdx += 0x1UL;   /* increase the producer index manually */
        }

        /* This is needed to make sure the descriptor gets updated with the latest values, before
           incrementing the producer index to start the actual operation */
        MCAL_DATA_SYNC_BARRIER();

        netcSIsBase[CtrlIndex]->SICBDRPIR = NETC_F3_SI0_SICBDRPIR_BDR_INDEX(producerIdx);
        /* --- write the produce index register and enable hardware to consume the command --- */

        /* +++ to make sure the hardware consumes and processes the command completely +++ */
        /* Setup timeout timer */
        Netc_Eth_Ip_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, NETC_ETH_IP_TIMEOUT_VALUE_US);
        do {
            statusField = Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[PreviousProducerIdx].MessageHeaderDataField[NETC_ETH_IP_RSPHEADER_STATUS_FIELD_INDEX];    /* get status field in the response data buffer */
            rrBit = ((statusField & (NETC_ETH_IP_CMDBD_RSPFMT_STATUS_FIELD_RR_MASK)) >> (NETC_ETH_IP_CMDBD_RSPFMT_STATUS_FIELD_RR_SHIFT));        /* get the value of RR bit in the response data buffer */
            TimeExpired = Netc_Eth_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        } while ((rrBit != 0x1U) && (FALSE == TimeExpired));        /* wait the hardware consume the command and check RR bit to see if the processing is completed (rrBit = 1). */
        /* --- to make sure the hardware consumes and processes the command completely --- */

        /* return the value of ERROR field in response data buffer indicating if there is an error for processing the command */
        errorField = ((statusField & (NETC_ETH_IP_CMDBD_RSPFMT_STATUS_FIELD_ERROR_MASK)) >> (NETC_ETH_IP_CMDBD_RSPFMT_STATUS_FIELD_ERROR_SHIFT));
        if (errorField != 0U)
        {
            status = (Netc_Eth_Ip_StatusType)errorField;     /* ERROR field should be 0. */
        }
    }
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_SendNTMP1Command_ShortFormat
 * Description   : Internal function for adding an entry with different commands to command ring (short format) for NTMP V1.0.
 *
 *END**************************************************************************/
static Netc_Eth_Ip_StatusType Netc_Eth_Ip_SendNTMP1Command_ShortFormat(uint8 CtrlIndex, const NetcEth_Ip_SetMessageHeaderTableOperationDataType *OperationData)
{
    uint32 producerIdx;
    uint32 consumerIdx;
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;
    uint32 PreviousConsumerIdx;
    uint8 statusField;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    boolean TimeExpired;

    /* read the producer and consumer index register */
    producerIdx = netcSIsBase[CtrlIndex]->SICBDRPIR;
    consumerIdx = netcSIsBase[CtrlIndex]->SICBDRCIR;

    /* check if the ring is full */
    if (((producerIdx + 0x1UL) % ((uint32)(Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.lengthCBDR) * NETC_ETH_IP_SET_OF_BD)) == consumerIdx)
    {
        status = NETC_ETH_IP_CBDRSTATUS_RINGFULL;  /* the ring is full */
    }
    else
    {
        SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_17();
        /* Fill in the configured data */
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_ADDR_L] = OperationData->Data0;
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_ADDR_H] = OperationData->Data1;
        if (OperationData->Command == 0U)
        {
            Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_DATA_1] = NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_EN(0x1U);
        }
        else
        {
            Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_DATA_1] = NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_EN(0x0U);
        }
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_DATA_2] = 0x0UL;
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_DATA_3] = 0x0UL;
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_DATA_4] = (uint32)OperationData->SI_Bitmap;
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_LENGTH_INDEX] = OperationData->Index;

        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_CMD] = NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_SF(0x1U);
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_CMD] |= NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CI(0x0U);
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_CMD] |= NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_STATUS(0x0U);
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_CMD] |= NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CLASS(OperationData->Class);
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_CMD] |= NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_COMMAND(OperationData->Command);
        SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_17();

        /* +++ write the producer index register and enable hardware to consume the command +++ */
        PreviousConsumerIdx = consumerIdx;
        if (((producerIdx + 0x1UL) % ((uint32)(Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.lengthCBDR) * NETC_ETH_IP_SET_OF_BD)) == 0U)        /* adjust producer index */
        {
            producerIdx = 0x0UL;    /* when producerIdx equals ACTUAL_CBDR_LENGTH minus 1, the producer index should start from 0 again */
        }
        else
        {
            producerIdx += 0x1UL;   /* increase the producer index manually */
        }

        /* This is needed to make sure the descriptor gets updated with the latest values, before
           incrementing the producer index to start the actual operation */
        MCAL_DATA_SYNC_BARRIER();

        netcSIsBase[CtrlIndex]->SICBDRPIR = NETC_F3_SI0_SICBDRPIR_BDR_INDEX(producerIdx);
        /* --- write the producer index register and enable hardware to consume the command --- */

        /* +++ to make sure the hardware consumes and processes the command completely +++ */
        /* Setup timeout timer */
        Netc_Eth_Ip_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, NETC_ETH_IP_TIMEOUT_VALUE_US);
        do {
            consumerIdx = netcSIsBase[CtrlIndex]->SICBDRCIR;
            TimeExpired = Netc_Eth_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        } while ((consumerIdx == PreviousConsumerIdx) && (FALSE == TimeExpired));        /* wait the hardware consume the command. */
        /* --- to make sure the hardware consumes and processes the command completely --- */

        if (TRUE == TimeExpired)
        {
            status = NETC_ETH_IP_STATUS_ERROR;
        }
        else
        {
            statusField = NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_GET_STATUS(Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[consumerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_CMD]);    /* get status field in the response data buffer */
            if (statusField != 0U)
            {
                status = NETC_ETH_IP_STATUS_ERROR;     /* STATUS field should be 0. */
            }
        }
    }
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_SetVLANFilterTableEntry
 * Description   : Internal function for adding an entry to the VLAN Filter Table.

 * implements     Netc_Eth_Ip_AddVLANFilterTableEntry_Activity
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddVLANFilterTableEntry( const uint8 ctrlIndex, const Netc_Eth_Ip_VLANFilterTableEntryDataType *VLANTableEntry)
{
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;
    NetcEth_Ip_SetMessageHeaderTableOperationDataType TableData = {0U};

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(NULL_PTR != Netc_Eth_Ip_apxState[ctrlIndex]);
#endif

    /* Fill in the configured data */
    TableData.Data0 = NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_SET_TPID(VLANTableEntry->TPID);
    TableData.Data0 |= (uint32)VLANTableEntry->VLANId;
    TableData.SI_Bitmap = VLANTableEntry->SIBitmap;
    TableData.Index = VLANTableEntry->VLANFilterTable_EID;
    /* Class 2 for VLAN Filter Table */
    TableData.Class = 2U;
    /* Command 0 for adding an entry to the VLAN Filter Table */
    TableData.Command = 0U;
    status = Netc_Eth_Ip_SendNTMP1Command_ShortFormat(ctrlIndex, &TableData);
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_QueryVLANFilterTableEntry
 * Description   : Internal function for querying the VLAN Filter Table.
 *
 * implements     Netc_Eth_Ip_QueryVLANFilterTableEntry_Activity
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_QueryVLANFilterTableEntry(const uint8 ctrlIndex, Netc_Eth_Ip_VLANFilterTableEntryDataType *VLANTableEntry)
{
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;
    NetcEth_Ip_SetMessageHeaderTableOperationDataType TableData = {0U};
    uint32 producerIdx;
    uint32 lengthOfCmDB;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(NULL_PTR != Netc_Eth_Ip_apxState[ctrlIndex]);
#endif

    /* Fill in the table entry ID */
    TableData.Index = VLANTableEntry->VLANFilterTable_EID;
    /* Class 2 for VLAN Filter Table */
    TableData.Class = 2U;
    /* Command 1 for adding an entry to the VLAN Filter Table */
    TableData.Command = 1U;
    status = Netc_Eth_Ip_SendNTMP1Command_ShortFormat(ctrlIndex, &TableData);
    producerIdx = netcSIsBase[ctrlIndex]->SICBDRPIR;

    /* the value stored in producer index register indicates the index of next entry */
    if (producerIdx > 0UL)
    {
        producerIdx -= 1UL;
    }
    else /* producerIdx increased from 15 to 0, will set it to 15, or length minus 1 */
    {
        lengthOfCmDB = ((uint32)(Netc_Eth_Ip_apxState[ctrlIndex]->EnetcCommandBDConfig.lengthCBDR) * NETC_ETH_IP_SET_OF_BD);
        producerIdx = lengthOfCmDB - 0x1UL;
    }

    if (status == NETC_ETH_IP_STATUS_SUCCESS)
    {
        VLANTableEntry->TPID = (Netc_Eth_Ip_VlanProtocolIdentifierType)NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_GET_TPID(Netc_Eth_Ip_apxState[ctrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_ADDR_L]);
        VLANTableEntry->VLANId = (uint16)(Netc_Eth_Ip_apxState[ctrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_ADDR_L] & 0x00000FFFU);
        VLANTableEntry->SIBitmap = (uint16)(Netc_Eth_Ip_apxState[ctrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_DATA_4]);
    }
    return status;
}

#if (NETC_ETH_IP_NUMBER_OF_VLAN_FILTER_ENTRIES > 0)
/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_ConfigVLANFilterTable
 * Description   : Add the configured entries to the VLAN Filter Table.
 *
 *END**************************************************************************/
static Netc_Eth_Ip_StatusType Netc_Eth_Ip_ConfigVLANFilterTable(uint8 ctrlIndex, const Netc_Eth_Ip_ConfigType * Config)
{
    uint8 VLANFilterTableIdx;
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;
    Netc_Eth_Ip_VLANFilterTableEntryDataType VLANTableEntry = {0};

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
#endif

    for (VLANFilterTableIdx = 0U; VLANFilterTableIdx < Config->generalConfig->NumberOfVLANFilterEntries; VLANFilterTableIdx++)
    {
        VLANTableEntry = (*(Config->generalConfig->VLANTableEntries))[VLANFilterTableIdx];
        status = Netc_Eth_Ip_AddVLANFilterTableEntry(ctrlIndex, &VLANTableEntry);
    }

    return status;
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_SendNTMP1Command_ShortFormat
 * Description   : Internal function for adding an entry with different commands to command ring (short format) for NTMP V1.0.
 *
 *END**************************************************************************/
static Netc_Eth_Ip_StatusType Netc_Eth_Ip_SendNTMP1Command_LongFormat(uint8 CtrlIndex, const NetcEth_Ip_SetMessageHeaderTableOperationDataType *OperationData)
{
    uint32 producerIdx;
    uint32 consumerIdx;
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;
    uint32 PreviousConsumerIdx;
    uint8 statusField;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    boolean TimeExpired;

    /* read the producer and consumer index register */
    producerIdx = netcSIsBase[CtrlIndex]->SICBDRPIR;
    consumerIdx = netcSIsBase[CtrlIndex]->SICBDRCIR;

    /* check if the ring is full */
    if (((producerIdx + 0x1UL) % ((uint32)(Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.lengthCBDR) * NETC_ETH_IP_SET_OF_BD)) == consumerIdx)
    {
        status = NETC_ETH_IP_CBDRSTATUS_RINGFULL;  /* the ring is full */
    }
    else
    {
        SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_18();
        /* Fill in the configured data */
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_ADDR_L] = OperationData->Data0;
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_ADDR_H] = 0x0UL;
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_DATA_1] = 0x0UL;
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_DATA_2] = 0x0UL;
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_DATA_3] = 0x0UL;
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_DATA_4] = 0x0UL;
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_LENGTH_INDEX] = OperationData->Index | ((uint32)(OperationData->Length) << 16U);

        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_CMD] = NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_SF(OperationData->Format);
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_CMD] |= NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CI(0x0U);
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_CMD] |= NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_STATUS(0x0U);
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_CMD] |= NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CLASS(OperationData->Class);
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_CMD] |= NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_COMMAND(OperationData->Command);
        SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_18();


        /* +++ write the producer index register and enable hardware to consume the command +++ */
        PreviousConsumerIdx = consumerIdx;
        if (((producerIdx + 0x1UL) % ((uint32)(Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.lengthCBDR) * NETC_ETH_IP_SET_OF_BD)) == 0U)        /* adjust producer index */
        {
            producerIdx = 0x0UL;    /* when producerIdx equals ACTUAL_CBDR_LENGTH minus 1, the producer index should start from 0 again */
        }
        else
        {
            producerIdx += 0x1UL;   /* increase the producer index manually */
        }

        /* This is needed to make sure the descriptor gets updated with the latest values, before
           incrementing the producer index to start the actual operation */
        MCAL_DATA_SYNC_BARRIER();

        netcSIsBase[CtrlIndex]->SICBDRPIR = NETC_F3_SI0_SICBDRPIR_BDR_INDEX(producerIdx);
        /* --- write the produce index register and enable hardware to consume the command --- */

        /* +++ to make sure the hardware consumes and processes the command completely +++ */
        /* Setup timeout timer */
        Netc_Eth_Ip_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, NETC_ETH_IP_TIMEOUT_VALUE_US);
        do {
            consumerIdx = netcSIsBase[CtrlIndex]->SICBDRCIR;
            TimeExpired = Netc_Eth_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        } while ((consumerIdx == PreviousConsumerIdx) && (FALSE == TimeExpired));        /* wait the hardware consume the command. */
        /* --- to make sure the hardware consumes and processes the command completely --- */

        if (TRUE == TimeExpired)
        {
            status = NETC_ETH_IP_STATUS_TIMEOUT;
        }
        else
        {
            statusField = NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_GET_STATUS(Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[consumerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_CMD]);    /* get status field in the response data buffer */
            if (statusField != 0U)
            {
                status = NETC_ETH_IP_STATUS_ERROR;     /* STATUS field should be 0. */
            }
        }
    }
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_SendNTMP1Command_RfsShortFormat
 * Description   : Internal function for querying statistics of a RFS entry with t commands to command ring (short format) for NTMP V1.0.
 *
 *END**************************************************************************/
static Netc_Eth_Ip_StatusType Netc_Eth_Ip_SendNTMP1Command_RfsShortFormat(const uint8 CtrlIndex, const NetcEth_Ip_SetMessageHeaderTableOperationDataType *OperationData)
{
    uint32 producerIdx;
    uint32 consumerIdx;
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;
    uint32 PreviousConsumerIdx;
    uint8 statusField;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    boolean TimeExpired;

    /* read the producer and consumer index register */
    producerIdx = netcSIsBase[CtrlIndex]->SICBDRPIR;
    consumerIdx = netcSIsBase[CtrlIndex]->SICBDRCIR;

    /* check if the ring is full */
    if (((producerIdx + 0x1UL) % ((uint32)(Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.lengthCBDR) * NETC_ETH_IP_SET_OF_BD)) == consumerIdx)
    {
        status = NETC_ETH_IP_CBDRSTATUS_RINGFULL;  /* the ring is full */
    }
    else
    {
        SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_19();
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_LENGTH_INDEX] = OperationData->Index |  (((uint32)(OperationData->Length)) << 16U);
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_CMD] = NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_SF(OperationData->Format);
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_CMD] |= NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CI(0x0U);
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_CMD] |= NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_STATUS(0x0U);
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_CMD] |= NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_CLASS(OperationData->Class);
        Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_CMD] |= NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_COMMAND(OperationData->Command);
        SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_19();


        /* +++ write the producer index register and enable hardware to consume the command +++ */
        PreviousConsumerIdx = consumerIdx;
        if (((producerIdx + 0x1UL) % ((uint32)(Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.lengthCBDR) * NETC_ETH_IP_SET_OF_BD)) == 0U)        /* adjust producer index */
        {
            producerIdx = 0x0UL;    /* when producerIdx equals ACTUAL_CBDR_LENGTH minus 1, the producer index should start from 0 again */
        }
        else
        {
            producerIdx += 0x1UL;   /* increase the producer index manually */
        }

        /* This is needed to make sure the descriptor gets updated with the latest values, before
           incrementing the producer index to start the actual operation */
        MCAL_DATA_SYNC_BARRIER();

        netcSIsBase[CtrlIndex]->SICBDRPIR = NETC_F3_SI0_SICBDRPIR_BDR_INDEX(producerIdx);
        /* --- write the produce index register and enable hardware to consume the command --- */

        /* +++ to make sure the hardware consumes and processes the command completely +++ */
        /* Setup timeout timer */
        Netc_Eth_Ip_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, NETC_ETH_IP_TIMEOUT_VALUE_US);
        do {
            consumerIdx = netcSIsBase[CtrlIndex]->SICBDRCIR;
            TimeExpired = Netc_Eth_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        } while ((consumerIdx == PreviousConsumerIdx) && (FALSE == TimeExpired));        /* wait the hardware consume the command. */
        /* --- to make sure the hardware consumes and processes the command completely --- */

        if (TRUE == TimeExpired)
        {
            status = NETC_ETH_IP_STATUS_TIMEOUT;
        }
        else
        {
            statusField = NETC_ETH_IP_CMDBD_REQFMT_CONFIG_FIELD_GET_STATUS(Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[consumerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_CMD]);    /* get status field in the response data buffer */
            if (statusField != 0U)
            {
                status = NETC_ETH_IP_STATUS_ERROR;     /* STATUS field should be 0. */
            }
        }
    }
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_FillRfsSetDataBuffer
 * Description   : Internal function for filling a local static buffer with the configured data for a Rfs table entry
 *
 *END**************************************************************************/
static void Netc_Eth_Ip_FillRfsSetDataBuffer(uint32 * RfsSetDataBuffer, const Netc_Eth_Ip_RfsEntryType * RfsTableEntry)
{
    uint8 i;

    for(i = 0; i < NETC_ETH_RFS_ENTRY_SET_DATA_BUFFER_SIZE; i++)
    {
        RfsSetDataBuffer[i] = 0;
    }

    /*EN, MODE, RESULT fields */
    RfsSetDataBuffer[28] = (uint32)(RfsTableEntry->Result) | ((uint32)(RfsTableEntry->Mode) << NETC_ETH_IP_RFS_ENTRY_MODE_FIELD_SHIFT) | ((uint32)(RfsTableEntry->Enable) << NETC_ETH_IP_RFS_ENTRY_EN_FIELD_SHIFT);

    /*L4_PROTOCOL, L4_PROTOCOL_MASK, IP_PRESENT, IP_PRESENT_M,  L4_PROT_PRESENT, L4_PROT_PRESENT_M,
      TCP_OR_UDP_PRESENT, TCP_OR_UDP_PRESENT_M, IPV4_IPV6, IPV4_IPV6_M, UDP_TCP, UDP_TCP_M fields */
    RfsSetDataBuffer[27] = (uint32)(RfsTableEntry->L4Protocol) | ((uint32)(RfsTableEntry->L4ProtocolMask) << NETC_ETH_IP_RFS_ENTRY_L4PROTMASK_FIELD_SHIFT) | ((uint32)(RfsTableEntry->IpPresent) << NETC_ETH_IP_RFS_ENTRY_IPPRESENT_FIELD_SHIFT)
                                | ((uint32)(RfsTableEntry->IpPresentMask) << NETC_ETH_IP_RFS_ENTRY_IPPRESENTMASK_FIELD_SHIFT) | ((uint32)(RfsTableEntry->L4ProtPresent) << NETC_ETH_IP_RFS_ENTRY_L4PROTPRESENT_FIELD_SHIFT) | ((uint32)(RfsTableEntry->L4ProtPresentMask) << NETC_ETH_IP_RFS_ENTRY_L4PROTPRESENTMASK_FIELD_SHIFT)
                                | ((uint32)(RfsTableEntry->TcpUdpPresent) << NETC_ETH_IP_RFS_ENTRY_TCPUDPPRESENT_FIELD_SHIFT) | ((uint32)(RfsTableEntry->TcpUdpPresentMask) << NETC_ETH_IP_RFS_ENTRY_TCPUDPPRESENTMASK_FIELD_SHIFT) | ((uint32)(RfsTableEntry->Ipv4Ipv6) << NETC_ETH_IP_RFS_ENTRY_IPV4IPV6_FIELD_SHIFT)
                                | ((uint32)(RfsTableEntry->Ipv4Ipv6Mask)<< NETC_ETH_IP_RFS_ENTRY_IPV4IPV6MASK_FIELD_SHIFT) | ((uint32)(RfsTableEntry->UdpTcp) << NETC_ETH_IP_RFS_ENTRY_UDPTCP_FIELD_SHIFT) | ((uint32)(RfsTableEntry->UdpTcpMask) << NETC_ETH_IP_RFS_ENTRY_UDPTCPMASK_FIELD_SHIFT);

    /* RFS Table bytes (Offset 0x68) corresponding to RfsSetDataBuffer position 26 are reserved */

    /*L4_DEST_PORT, L4_DEST_PORT_MASK fields */
    RfsSetDataBuffer[25] = (uint32) (RfsTableEntry->L4DestPort) | (uint32)(RfsTableEntry->L4DestPortMask << NETC_ETH_IP_RFS_ENTRY_L4DESTPORTMASK_FIELD_SHIFT);

    /*L4_SOURCE_PORT, L4_SOURCE_PORT_MASK fields */
    RfsSetDataBuffer[24] = (uint32) (RfsTableEntry->L4SrcPort) | (uint32)(RfsTableEntry->L4SrcPortMask << NETC_ETH_IP_RFS_ENTRY_L4SRCPORTMASK_FIELD_SHIFT);

    /* RFS Table bytes (Offset 0x5C and 0x58) corresponding to RfsSetDataBuffer positions 23 and 22  are reserved */

    /*DEST_IP_ADDR_MASK field*/
    RfsSetDataBuffer[21] = (uint32) NETC_ETH_IP_64BYTE_TO_SECOND_WORD(RfsTableEntry->DestIpAddrMaskHigh);
    RfsSetDataBuffer[20] = (uint32) NETC_ETH_IP_64BYTE_TO_FIRST_WORD(RfsTableEntry->DestIpAddrMaskHigh);
    RfsSetDataBuffer[19] = (uint32) NETC_ETH_IP_64BYTE_TO_SECOND_WORD(RfsTableEntry->DestIpAddrMaskLow);
    RfsSetDataBuffer[18] = (uint32) NETC_ETH_IP_64BYTE_TO_FIRST_WORD(RfsTableEntry->DestIpAddrMaskLow);

    /*DEST_IP_ADDR field*/
    RfsSetDataBuffer[17] = (uint32) NETC_ETH_IP_64BYTE_TO_SECOND_WORD(RfsTableEntry->DestIpAddrHigh);
    RfsSetDataBuffer[16] = (uint32) NETC_ETH_IP_64BYTE_TO_FIRST_WORD(RfsTableEntry->DestIpAddrHigh);
    RfsSetDataBuffer[15] = (uint32) NETC_ETH_IP_64BYTE_TO_SECOND_WORD(RfsTableEntry->DestIpAddrLow);
    RfsSetDataBuffer[14] = (uint32) NETC_ETH_IP_64BYTE_TO_FIRST_WORD(RfsTableEntry->DestIpAddrLow);

    /*SRC_IP_ADDR_MASK field*/
    RfsSetDataBuffer[13] = (uint32) NETC_ETH_IP_64BYTE_TO_SECOND_WORD(RfsTableEntry->SrcIpAddrMaskHigh);
    RfsSetDataBuffer[12] = (uint32) NETC_ETH_IP_64BYTE_TO_FIRST_WORD(RfsTableEntry->SrcIpAddrMaskHigh);
    RfsSetDataBuffer[11] = (uint32) NETC_ETH_IP_64BYTE_TO_SECOND_WORD(RfsTableEntry->SrcIpAddrMaskLow);
    RfsSetDataBuffer[10] = (uint32) NETC_ETH_IP_64BYTE_TO_FIRST_WORD(RfsTableEntry->SrcIpAddrMaskLow);

    /*SRC_IP_ADDR field*/
    RfsSetDataBuffer[9] = (uint32) NETC_ETH_IP_64BYTE_TO_SECOND_WORD(RfsTableEntry->SrcIpAddrHigh);
    RfsSetDataBuffer[8] = (uint32) NETC_ETH_IP_64BYTE_TO_FIRST_WORD(RfsTableEntry->SrcIpAddrHigh);
    RfsSetDataBuffer[7] = (uint32) NETC_ETH_IP_64BYTE_TO_SECOND_WORD(RfsTableEntry->SrcIpAddrLow);
    RfsSetDataBuffer[6] = (uint32) NETC_ETH_IP_64BYTE_TO_FIRST_WORD(RfsTableEntry->SrcIpAddrLow);

    /* RFS Table bytes (Offset 0x00 to 0x14) corresponding to RfsSetDataBuffer positions 0 to 15  are reserved */
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_SetRfsTableEntry
 * Description   : Internal function for adding an entry to the Rceive Flow Steering Table.
 *
 * implements     Netc_Eth_Ip_AddRfsTableEntry_Activity
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddRfsTableEntry(const uint8 ctrlIndex, const Netc_Eth_Ip_RfsEntryType * RfsTableEntry)
{
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;
    NetcEth_Ip_SetMessageHeaderTableOperationDataType TableData = {0U};
    static uint32 RfsSetDataBuffer[NETC_ETH_RFS_ENTRY_SET_DATA_BUFFER_SIZE];


#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(NULL_PTR != Netc_Eth_Ip_apxState[ctrlIndex]);
#endif

    /* Fill in the configured data. */
    Netc_Eth_Ip_FillRfsSetDataBuffer(RfsSetDataBuffer, RfsTableEntry);

    /* RFS Data buffer address.
       There is an alignment restrictions for the data address to be 16-byte aligned;
       hardware ignores the least significant 4 bits of the ADDR field. */
    TableData.Data0 = (uint32)  &RfsSetDataBuffer;
    TableData.Length = (uint16)( NETC_ETH_RFS_ENTRY_SET_DATA_BUFFER_SIZE * 4U);
    TableData.Index = RfsTableEntry->RfsTableEntryId;

    /*Set the format to Long format */
    TableData.Format = 0;
    /* Class 4 for RFS Table */
    TableData.Class = 4U;
    /* Command 0 for adding an entry to the RFS Table */
    TableData.Command = 0U;
    status = Netc_Eth_Ip_SendNTMP1Command_LongFormat(ctrlIndex, &TableData);
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_QueryRfsTableEntry
 * Description   : Internal function for querying the Receive Flow Steering Table.
 *
 * implements     Netc_Eth_Ip_QueryRfsTableEntry_Activity
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_QueryRfsTableEntry(const uint8 ctrlIndex, uint8 RfsEntryIdx, uint32 * RfsTableEntryAddr)
{
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;
    NetcEth_Ip_SetMessageHeaderTableOperationDataType TableData = {0U};

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(NULL_PTR != Netc_Eth_Ip_apxState[ctrlIndex]);
#endif

    /* Fill in the table entry ID */
    TableData.Index = RfsEntryIdx;
    /* Fill in the table entry address */
    TableData.Data0 = (uint32)RfsTableEntryAddr;
    /* Fill in the table entry length */
    TableData.Length = (uint16)( NETC_ETH_RFS_ENTRY_SET_DATA_BUFFER_SIZE * 4U);
    /* Class 4 for RFS Table */
    TableData.Class = 4U;
    /* Command 1 for adding an querrying to the RFS Table (Long format) */
    TableData.Command = 1U;
    /*Long format*/
    TableData.Format = 0U;

    status = Netc_Eth_Ip_SendNTMP1Command_LongFormat(ctrlIndex, &TableData);

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_QueryStatisticsRfsTableEntry
 * Description   : Internal function for querying the Receive Flow Steering Table.
 *
 * implements     Netc_Eth_Ip_QueryStatisticsRfsTableEntry_Activity
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_QueryStatisticsRfsTableEntry(const uint8 ctrlIndex, uint8 RfsEntryIdx, uint32 * MatchedFramesNb)
{
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;
    NetcEth_Ip_SetMessageHeaderTableOperationDataType TableData = {0U};
    uint32 producerIdx;
    uint32 lengthOfCmDB;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(NULL_PTR != Netc_Eth_Ip_apxState[ctrlIndex]);
#endif

    /* Fill in the table entry ID */
    TableData.Index = RfsEntryIdx;
    /* Class 4 for RFS Table */
    TableData.Class = 4U;
    /* Command 1 for adding an querrying statistical information for RFS Table Entry (Short Format) */
    TableData.Command = 2U;
    /*Short Format*/
    TableData.Format = 1U;

    /*To check what format should be sent here*/
    status = Netc_Eth_Ip_SendNTMP1Command_RfsShortFormat(ctrlIndex, &TableData);

    producerIdx = netcSIsBase[ctrlIndex]->SICBDRPIR;

    /* the value stored in producer index register indicates the index of next entry */
    if (producerIdx > 0UL)
    {
        producerIdx -= 1UL;
    }
    else /* producerIdx increased from 15 to 0, will set it to 15, or length minus 1 */
    {
        lengthOfCmDB = ((uint32)(Netc_Eth_Ip_apxState[ctrlIndex]->EnetcCommandBDConfig.lengthCBDR) * NETC_ETH_IP_SET_OF_BD);
        producerIdx = lengthOfCmDB - 0x1UL;
    }

    if (status == NETC_ETH_IP_STATUS_SUCCESS)
    {
        /*Get the number of matched frames */
        *MatchedFramesNb = Netc_Eth_Ip_apxState[ctrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_CBD_ADDR_L];
    }
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_ConfigRfsTable
 * Description   : Add the configured entries to the Receive Flow Steering Table.
 *
 *END**************************************************************************/
static Netc_Eth_Ip_StatusType Netc_Eth_Ip_ConfigRfsTable(const uint8 ctrlIndex, const Netc_Eth_Ip_ConfigType * Config)
{
    uint32 RfsTableIdx;
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;
    Netc_Eth_Ip_RfsEntryType RfsTableEntry = {0};

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
#endif

    /*Add configured entries into the RFS table*/
    for (RfsTableIdx = 0U; RfsTableIdx < Config->RfsEntriesNb; RfsTableIdx++)
    {
        RfsTableEntry = (*(Config->RfsConfigTable))[RfsTableIdx];
        status = Netc_Eth_Ip_AddRfsTableEntry(ctrlIndex, &RfsTableEntry);
    }

    /* Enable Port Receive Flow Steering Mode */
    IP_NETC__ENETC0_BASE->PRFSMR = NETC_F3_PRFSMR_RFSE(1);

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_ConfigPortTimeGateScheduling
 * Description   : Ethernet ENETC enables or disables Time Gate Scheduling function.
 *
 * implements     Netc_Eth_Ip_ConfigPortTimeGateScheduling_Activity
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_ConfigPortTimeGateScheduling( const uint8 CtrlIndex, const boolean Enable )
{
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;
    uint32 RegValue;
    uint32 GateControlListState;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    boolean TimeExpired;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
#endif

    (void)CtrlIndex;
    SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_13();
    /* read the reg value first */
    RegValue = IP_NETC__ENETC0_PORT->PTGSCR;
    if ((RegValue & ENETC_PORT_PTGSCR_TGE_MASK) != ENETC_PORT_PTGSCR_TGE_MASK)      /* time gating is disabled */
    {
        if (TRUE == Enable)
        {
            /* Software must also wait until PTGAGLSR[TG] is deasserted before re-enabling. */
            Netc_Eth_Ip_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, NETC_ETH_IP_TIMEOUT_VALUE_US);
            do {
                /* get the state of gate control list */
                GateControlListState = (IP_NETC__ENETC0_PORT->PTGAGLSR & ENETC_PORT_PTGAGLSR_TG_MASK);
                TimeExpired = Netc_Eth_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            } while ((GateControlListState != 0x0U) && (FALSE == TimeExpired));

            if (GateControlListState == 0x0U)
            {
                RegValue |= ENETC_PORT_PTGSCR_TGE(1U);    /* Enable time gating */
            }
            else
            {
                status = NETC_ETH_IP_STATUS_ERROR;  /* fail to enable time gating because Operational gate control list is active */
            }
        }
    }
    else    /* time gating is enabled */
    {
        if (FALSE == Enable)
        {
            RegValue &= ~ENETC_PORT_PTGSCR_TGE(1U);    /* Disable time gating */
        }
    }

    if (status == NETC_ETH_IP_STATUS_SUCCESS)
    {
        /* write it back. */
        IP_NETC__ENETC0_PORT->PTGSCR = RegValue;
        SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_13();

        /* if time gate scheduling is enabled, and entry data is configured, then adds the entry */
        if ( (TRUE == Enable) && (TRUE == Netc_Eth_Ip_PortTimeAwareShaperEnabled))
        {
            status = Netc_Eth_Ip_AddOrUpdateTimeGateSchedulingTableEntry(0U, &Netc_Eth_Ip_EthTimeGateSchedulingEntryData);
            /* fail to add or update the time gate schedulling table entry */
            if (status != NETC_ETH_IP_STATUS_SUCCESS)
            {
                status = NETC_ETH_IP_STATUS_ERROR;
            }
        }
    }
    else
    {
        SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_13();
    }

    return status;
}

static inline void FillInGateControlListData(const uint8 *OperationTimeIdx, const Netc_Eth_Ip_TimeGateSchedulingEntryDataType *TimeGateSchedulingTableEntry)
{
    uint8 CFGEDataIdx;
    uint16 GateEntryIdx;
    uint8 HostRequest;

    if (*OperationTimeIdx == 1U)
    {
        CFGEDataIdx = 0U;

        for (GateEntryIdx = 0U; GateEntryIdx < TimeGateSchedulingTableEntry->AdminControlListLength; GateEntryIdx++)
        {
            Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[(uint8)(NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA5) + CFGEDataIdx] = TimeGateSchedulingTableEntry->GateEntryAdminControlListData[GateEntryIdx].AdminTimeInterval;
            /* convert gate operation type */
            switch (TimeGateSchedulingTableEntry->GateEntryAdminControlListData[GateEntryIdx].AdminGateOperationType)
            {
                case NETC_ETH_HOST_REQUEST_UNCHANGED:
                    HostRequest = 0U;
                    break;
                case NETC_ETH_HOST_REQUEST_HOLD:
                    HostRequest = 1U;
                    break;
                case NETC_ETH_HOST_REQUEST_RELEASE:
                    HostRequest = 2U;
                    break;
                default:
                    HostRequest = 0U;
                    break;
            }
            Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[(uint8)(NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA6) + CFGEDataIdx] = NETC_ETH_IP_TGSTABLE_CFGE_ADMIN_TC_STATES(TimeGateSchedulingTableEntry->GateEntryAdminControlListData[GateEntryIdx].AdminTrafficClassGateStates) \
                                                                                                            | NETC_ETH_IP_TGSTABLE_CFGE_ADMIN_HR_CB(HostRequest);

            CFGEDataIdx += 2U;      /* CFGE data field index increased by 2 */
        }
        
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_AddOrUpdateTimeGateSchedulingTableEntry
 * Description   : Ethernet ENETC adds or updates Time Gate Scheduling table entry function.
 *
 * implements     Netc_Eth_Ip_AddOrUpdateTimeGateSchedulingTableEntry_Activity
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddOrUpdateTimeGateSchedulingTableEntry( const uint8 CtrlIndex,
                                                                            const Netc_Eth_Ip_TimeGateSchedulingEntryDataType *TimeGateSchedulingTableEntry
                                                                          )
{
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;
    NetcEth_Ip_ReqHeaderTableOperationDataType OperationData;
    uint8 OperationTimes;
    uint8 OperationTimeIdx;
    volatile uint64 CurrentTime = 0;
    uint32 CycleFactor;
    uint64 NewBaseTime;
    uint32 LookaheadTime;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(TimeGateSchedulingTableEntry != NULL_PTR);
#endif

    /* AdminControlListLength = 0U means to reset the gate control list or add the time gate scheduling entry without gate control list */
    OperationTimes = (TimeGateSchedulingTableEntry->AdminControlListLength > 0U) ? 2U : 1U;

    /* for adding or updating gate control list, we'll have to remove the gate control list firstly */
    for (OperationTimeIdx = 0U; OperationTimeIdx < OperationTimes; OperationTimeIdx++)
    {
        SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_14();
        /* ++++++ initialize the table request data buffer ++++++ */
        Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD] = NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_CFGEU(1U);    /* fill in Actions field */
        Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_ENTRYID_FIELD] = TimeGateSchedulingTableEntry->TimeGateSchedulingTable_EID;    /* fill in Entry ID */
        /* fill in CFGE_DATA */
        /* get the current time from 1588 timer */
        CurrentTime = IP_NETC__TMR0_BASE->TMR_CUR_TIME_L;      /* should read the Lower register first */
        CurrentTime |= ((uint64)(IP_NETC__TMR0_BASE->TMR_CUR_TIME_H)) << NETC_ETH_IP_32BIT_SHIFT;
        /* get lookaheadtime */
        LookaheadTime = IP_NETC__NETC_IERB->CFG_ENETC_INST[0U].ETGSLR + IP_NETC__ENETC0_PORT->PTGSATOR;

        /* calculate the NewBaseTime */
        if (TimeGateSchedulingTableEntry->AdminBaseTime >= (CurrentTime + LookaheadTime))
        {
            NewBaseTime = TimeGateSchedulingTableEntry->AdminBaseTime;
        }
        else
        {
            CycleFactor = (uint32)(CurrentTime + LookaheadTime - TimeGateSchedulingTableEntry->AdminBaseTime) / (TimeGateSchedulingTableEntry->AdminCycleTime);
            NewBaseTime = TimeGateSchedulingTableEntry->AdminBaseTime + (((uint64)CycleFactor + 1UL) * (uint64)(TimeGateSchedulingTableEntry->AdminCycleTime));
        }
        Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA0] = (uint32)(NewBaseTime & (0xFFFFFFFFUL));
        Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA1] = (uint32)(NewBaseTime >> NETC_ETH_IP_32BIT_SHIFT);
        Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA2] = TimeGateSchedulingTableEntry->AdminCycleTime;
        Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA3] = TimeGateSchedulingTableEntry->AdminCycleTimeExt;
        /* set Administrative Control List Length to 0 for removing the admin gate control list or adding an entry with no administrative gate control list */
        Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA4] = (OperationTimeIdx == 0U) ? 0x0UL : (uint32)(TimeGateSchedulingTableEntry->AdminControlListLength);

        FillInGateControlListData(&OperationTimeIdx, TimeGateSchedulingTableEntry);
        SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_14();

        /* ------ initialize the table request data buffer ------ */

        /* fill in operation data for config field of Request Header*/
        OperationData.CmdCompletionInt = 0x0U;                                          /* command completion interrupt disabled */
        OperationData.Version = NETC_ETH_IP_CMDBD_REQFMT_PROTOCOL_VERSION;              /* protocol version = 2 */
        OperationData.TableId = NETC_ETH_IP_TIME_GATE_SCHEDULING_TABLE_ID;
        OperationData.AccessMethod = NETC_ETH_ENTRY_ID_MATCH;                           /* only support NETC_ETH_ENTRY_ID_MATCH method */
        OperationData.Cmd = NETC_ETH_UPDATE_CMD;                                        /* can only use "update" command to add or update an time gate scheduling table entry */
        OperationData.ReqBuffLength = (NETC_ETH_IP_INGRESSPORTFILTERTABLE_REQBUFFER_LEN);
        OperationData.RspBuffLength = (NETC_ETH_IP_TGSTABLE_RSPBUFFER_LEN);

        /* send "update" command to add/remove gate control list */
        status = Netc_Eth_Ip_SendCommand(CtrlIndex, &OperationData);
#if defined(ERR_IPV_NETC_051243)
    #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == NETC_ETH_IP_STATUS_NOT_REAL_ERROR) || (status == NETC_ETH_IP_STATUS_SUCCESS))
        {
            status = NETC_ETH_IP_STATUS_SUCCESS;
        }
    #endif
#endif
    }

    return status;
}

/* inline function for initializing time gate scheduling table entries data during ENETC init */
static inline void Netc_Eth_Ip_InitTimeGateSchedulingTableEntryData(const Netc_Eth_Ip_ConfigType * Config)
{
    uint8 GateControlListIdx;

    if (((*Config->generalConfig).portTimeAwareShaperEnable) == TRUE)
    {
        /* set the flag for ports */
        Netc_Eth_Ip_PortTimeAwareShaperEnabled = TRUE;

        /* write register PTGSATOR. */
        IP_NETC__ENETC0_PORT->PTGSATOR = (uint32)((*Config->generalConfig).portTimeGateSchedulingAdvanceTimeOffsetReg);

        /* Fill in the data structure for time gate scheduling */
        Netc_Eth_Ip_EthTimeGateSchedulingEntryData.TimeGateSchedulingTable_EID = 0U;
        Netc_Eth_Ip_EthTimeGateSchedulingEntryData.AdminBaseTime = (*Config->generalConfig).portEgressAdminBaseTime;
        Netc_Eth_Ip_EthTimeGateSchedulingEntryData.AdminCycleTime = (*Config->generalConfig).portEgressAdminCycleTime;
        Netc_Eth_Ip_EthTimeGateSchedulingEntryData.AdminCycleTimeExt = (*Config->generalConfig).portEgressAdminCycleTimeExt;
        Netc_Eth_Ip_EthTimeGateSchedulingEntryData.AdminControlListLength = (*Config->generalConfig).numberOfGateControlListEntries;
        for (GateControlListIdx = 0U; GateControlListIdx < Netc_Eth_Ip_EthTimeGateSchedulingEntryData.AdminControlListLength; GateControlListIdx++)
        {
            Netc_Eth_Ip_EthTimeGateSchedulingEntryData.GateEntryAdminControlListData[GateControlListIdx].AdminTimeInterval = (*(*Config->generalConfig).TimeGateControlListEntries)[GateControlListIdx].AdminTimeInterval;
            Netc_Eth_Ip_EthTimeGateSchedulingEntryData.GateEntryAdminControlListData[GateControlListIdx].AdminTrafficClassGateStates = (*(*Config->generalConfig).TimeGateControlListEntries)[GateControlListIdx].AdminTrafficClassGateStates;
            Netc_Eth_Ip_EthTimeGateSchedulingEntryData.GateEntryAdminControlListData[GateControlListIdx].AdminGateOperationType = (*(*Config->generalConfig).TimeGateControlListEntries)[GateControlListIdx].AdminGateOperationType;
        }
    }

}

#if defined(ERR_IPV_NETC_E051130)
    #if (STD_ON == ERR_IPV_NETC_E051130)
/*  Workaround for ERR051130:
    Egress time gate scheduling can get corrupted when functional level reset is applied or when time gating is disabled
*/
/* Added 2 fake time gate control list entries for clearing the internal context for time gate scheduling feature */
static Netc_Eth_Ip_StatusType Netc_Eth_Ip_InitTimeGateSchedulingFeature(uint8 ctrlIndex)
{
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_SUCCESS;
    volatile uint64 CurrentTime = 0;
    uint8 EntryIdx;

    /* fill in struct Netc_Eth_Ip_TimeGateSchedulingEntryDataType */
    Netc_Eth_Ip_EthTimeGateSchedulingEntryData.TimeGateSchedulingTable_EID = 0U;   /* for pseudo port of ENETC */
    Netc_Eth_Ip_EthTimeGateSchedulingEntryData.AdminCycleTime = 4000000U;           /* it should be greater than the sum of time interval */
    Netc_Eth_Ip_EthTimeGateSchedulingEntryData.AdminCycleTimeExt = 100000U;
    Netc_Eth_Ip_EthTimeGateSchedulingEntryData.AdminControlListLength = 2U;         /* 2 entries */

    /* get the current time from 1588 timer */
    CurrentTime = IP_NETC__TMR0_BASE->TMR_CUR_TIME_L;      /* should read the Lower register first */
    CurrentTime |= ((uint64)(IP_NETC__TMR0_BASE->TMR_CUR_TIME_H)) << NETC_ETH_IP_32BIT_SHIFT;
    Netc_Eth_Ip_EthTimeGateSchedulingEntryData.AdminBaseTime = CurrentTime;        /* set base time to current time */

    /* fill in gate control list entries data */
    for (EntryIdx = 0U; EntryIdx < Netc_Eth_Ip_EthTimeGateSchedulingEntryData.AdminControlListLength; EntryIdx++)
    {
        Netc_Eth_Ip_EthTimeGateSchedulingEntryData.GateEntryAdminControlListData[EntryIdx].AdminTimeInterval = 2000000U;        /* the value is equal to transmit 128bytes + 20 bytes (header) frame with port speed 10M */
        Netc_Eth_Ip_EthTimeGateSchedulingEntryData.GateEntryAdminControlListData[EntryIdx].AdminTrafficClassGateStates = 0xFFU;      /* all open */
        Netc_Eth_Ip_EthTimeGateSchedulingEntryData.GateEntryAdminControlListData[EntryIdx].AdminGateOperationType = NETC_ETH_HOST_REQUEST_UNCHANGED;
    }

    /* add these 2 gate control list entries */
    Status = Netc_Eth_Ip_ConfigPortTimeGateScheduling(ctrlIndex, TRUE);

    return Status;
}
    #endif
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_GetMatchedEntries
 * Description   : Function for getting matched table entries. Num_Matched field indicates if it matches an entry.
 *
 *END**************************************************************************/
static void Netc_Eth_Ip_GetMatchedEntries(uint8 CtrlIndex, uint32 *NumOfEntry)
{
    uint32 producerIdx;
    uint32 statusField;
    uint32 lengthOfCmDB;

    producerIdx = netcSIsBase[CtrlIndex]->SICBDRPIR;

    /* the value stored in producer index register indicates the index of next entry */
    if (producerIdx > 0UL)
    {
        producerIdx -= 1UL;
    }
    else /* producerIdx increased from 15 to 0, will set it to 15, or length minus 1 */
    {
        lengthOfCmDB = ((uint32)(Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.lengthCBDR) * NETC_ETH_IP_SET_OF_BD);
        producerIdx = lengthOfCmDB - 0x1UL;
    }

    /* get status field in the response data buffer for the matched fdb entry */
    statusField = Netc_Eth_Ip_apxState[CtrlIndex]->EnetcCommandBDConfig.commandBDAddr[producerIdx].MessageHeaderDataField[NETC_ETH_IP_RSPHEADER_STATUS_FIELD_INDEX];

    /* NUM_MATCHED should equal or greater than 1 if the entry exists for any commands. */
    *NumOfEntry = (statusField & (NETC_ETH_IP_CMDBD_RSPFMT_STATUS_FIELD_NUMMATCHED_MASK));

}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_AddOrUpdateRatePolicerTableEntry
 * Description   : Add or Update rate policer table entry function.
 *
 *
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddOrUpdateRatePolicerTableEntry( const uint8 CtrlIndex,
                                                                     Netc_Eth_Ip_CommandsType Cmd,
                                                                     uint32 *MatchedEntries,
                                                                     const Netc_Eth_Ip_RatePolicerEntryDataType * RatePolicerTableEntry
                                                                   )
{
    Netc_Eth_Ip_StatusType status;
    uint32 ActionsData;
    NetcEth_Ip_ReqHeaderTableOperationDataType OperationData = {0U};

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(RatePolicerTableEntry != NULL_PTR);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* only support Add and Update commands */
    if ((NETC_ETH_ADD_CMD != Cmd) && (NETC_ETH_UPDATE_CMD != Cmd))
    {
        status = NETC_ETH_IP_STATUS_UNSUPPORTED;    /* not supported command */
    }
    else
    {
        /* set table version and CFGEU, FEEU, ... flag */
        ActionsData = (NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_CFGEU(RatePolicerTableEntry->ConfigurationElementUpdate ? 1U : 0U) \
                    | NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_FEEU(RatePolicerTableEntry->FunctionalEnableElementUpdate ? 1U : 0U)) \
                    | NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_PSEU(RatePolicerTableEntry->PolicerStateElementUpdate ? 1U : 0U) \
                    | NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_STSEU(RatePolicerTableEntry->StatisticsElementUpdate ? 1U : 0U) \
                    | NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);

        SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_15();
        /* ------initialize the table request data buffer------ */
        Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
        Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_ENTRYID_FIELD] = RatePolicerTableEntry->RatePolicerEntryId;        /* fill in Entry_ID field (Access Key) */
        Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA0] = RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Cir;  /* CFGE CIR field */
        Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA1] = RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Cbs;  /* CFGE CBS field */
        Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA2] = RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Eir;  /* CFGE EIR field */
        Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA3] = RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Ebs;  /* CFGE EBS field */
        Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA4] = NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_MREN((RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Mren) ? 1U : 0U) \
                                                                                    | NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_DOY((RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Doy) ? 1U : 0U) \
                                                                                    | NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_CM((RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Cm) ? 1U : 0U) \
                                                                                    | NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_CF((RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Cf) ? 1U : 0U) \
                                                                                    | NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_NDOR((RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Ndor) ? 1U : 0U) \
                                                                                    | NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_SDU_TYPE(RatePolicerTableEntry->RatePolicerCfgeData.Cfge_SduType);

        /* fill in Functional Enable Element Data */
        Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_CFGEDATA4] |= (NETC_ETH_IP_RATEPOLICERTABLE_FEE_DATA_FEN(RatePolicerTableEntry->RatePolicerFunctionEnable ? 1U : 0U) << NETC_ETH_IP_16BIT_SHIFT);
        SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_15();

        /* fill in operation data for config field of Request Header*/
        OperationData.CmdCompletionInt = 0x0U;                                     /* command completion interrupt disabled */
        OperationData.Version = NETC_ETH_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
        OperationData.TableId = NETC_ETH_IP_RATE_POLICER_TABLE_ID;
        OperationData.AccessMethod = NETC_ETH_ENTRY_ID_MATCH;       /* for Add and Update command, the Access Method should only be NETC_ETH_ENTRY_ID_MATCH */
        OperationData.Cmd = Cmd;
        OperationData.ReqBuffLength = (NETC_ETH_IP_RATEPOLICERTABLE_REQBUFFER_LEN);
        OperationData.RspBuffLength = (NETC_ETH_IP_TABLE_COMMON_RSPBUFFER_0BYTE_LEN);

        /* send command */
        status = Netc_Eth_Ip_SendCommand(CtrlIndex, &OperationData);
#if defined(ERR_IPV_NETC_051243)
    #if (STD_ON == ERR_IPV_NETC_051243)
        /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == NETC_ETH_IP_STATUS_NOT_REAL_ERROR) || (status == NETC_ETH_IP_STATUS_SUCCESS))
        {
    #endif
#else
        if (status == NETC_ETH_IP_STATUS_SUCCESS)
        {
#endif
            status = NETC_ETH_IP_STATUS_SUCCESS;
            Netc_Eth_Ip_GetMatchedEntries(CtrlIndex, MatchedEntries);
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_QueryRatePolicerTableEntry
 * Description   : Query Rate policer table entry function.
 *
 *
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_QueryRatePolicerTableEntry( const uint8 CtrlIndex,
                                                               uint32 *MatchedEntries,
                                                               uint32 RatePolicerEntryId,
                                                               Netc_Eth_Ip_RatePolicerEntryRspDataType * RatePolicerTableEntry
                                                             )
{
    Netc_Eth_Ip_StatusType status;
    uint32 ActionsData;
    uint32 CfgeConfigBits;
    NetcEth_Ip_ReqHeaderTableOperationDataType OperationData = {0U};
    uint8 SduType;
    uint64 TempTableDataField;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(RatePolicerTableEntry != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* always do the full query. 0x0 = Full query. */
    ActionsData = NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETH_TABLES_FULL_QUERY) \
                | NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_TABLE_VERSIONS(0U);

    SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_21();
    /* ------initialize the table request data buffer------ */
    Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* fill in Actions field */
    Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_ENTRYID_FIELD] = RatePolicerEntryId;        /* fill in Entry_ID field (Access Key) */
    SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_21();

    /* fill in operation data for config field of Request Header*/
    OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    OperationData.Version = NETC_ETH_IP_CMDBD_REQFMT_PROTOCOL_VERSION;            /* protocol version = 2 */
    OperationData.TableId = NETC_ETH_IP_RATE_POLICER_TABLE_ID;
    OperationData.AccessMethod = NETC_ETH_ENTRY_ID_MATCH;                         /* for query command, always uses NETC_ETH_ENTRY_ID_MATCH method */
    OperationData.Cmd = NETC_ETH_QUERY_CMD;
    OperationData.ReqBuffLength = (NETC_ETH_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);           /* set request data buffer length */
    OperationData.RspBuffLength = (NETC_ETH_IP_RATEPOLICERTABLE_RSPBUFFER_LEN);             /* set response data buffer length */

    /* send command */
    status = Netc_Eth_Ip_SendCommand(CtrlIndex, &OperationData);
#if defined(ERR_IPV_NETC_051243)
    #if (STD_ON == ERR_IPV_NETC_051243)
    /* Error code 0x8A is not a real error. check it on Errata. */
    if ((status == NETC_ETH_IP_STATUS_NOT_REAL_ERROR) || (status == NETC_ETH_IP_STATUS_SUCCESS))
    {
    #endif
#else
    if (status == NETC_ETH_IP_STATUS_SUCCESS)
    {
#endif
        status = NETC_ETH_IP_STATUS_SUCCESS;
        Netc_Eth_Ip_GetMatchedEntries(CtrlIndex, MatchedEntries);

        /* found a matched entry */
        if (1U == *MatchedEntries)
        {
            /* fill in "Netc_Eth_Ip_RatePolicerEntryDataType" structure with data in response data buffer */
            RatePolicerTableEntry->RatePolicerEntryId = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[0U];
            /* fill in STSE data */
            TempTableDataField = ((uint64)Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[2U]) << NETC_ETH_IP_32BIT_SHIFT;
            RatePolicerTableEntry->RatePolicerStseData.Stse_ByteCount = TempTableDataField | (uint64)(Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[1U]);
            RatePolicerTableEntry->RatePolicerStseData.Stse_DropFrames = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[3U];
            RatePolicerTableEntry->RatePolicerStseData.Stse_Dr0GrnFrames = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[5U];
            RatePolicerTableEntry->RatePolicerStseData.Stse_Dr1GrnFrames = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[7U];
            RatePolicerTableEntry->RatePolicerStseData.Stse_Dr2YlwFrames = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[9U];
            RatePolicerTableEntry->RatePolicerStseData.Stse_RemarkYlwFrames = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[11U];
            RatePolicerTableEntry->RatePolicerStseData.Stse_Dr3RedFrames = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[13U];
            RatePolicerTableEntry->RatePolicerStseData.Stse_RemarkRedFrames = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[15U];
            RatePolicerTableEntry->RatePolicerStseData.Stse_Lts = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[17U];
            RatePolicerTableEntry->RatePolicerStseData.Stse_CommittedTokenBucketInteger = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[18U];
            RatePolicerTableEntry->RatePolicerStseData.Stse_CommittedTokenBucketFractional = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[19U];   /* 1 sign bit + 31 bits fractional */
            RatePolicerTableEntry->RatePolicerStseData.Stse_ExcessTokenBucketInteger = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[20U];
            RatePolicerTableEntry->RatePolicerStseData.Stse_ExcessTokenBucketFranctional = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[21U];     /* 1 sign bit + 31 bits fractional */
            /* fill in CFGE data */
            RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Cir = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[22U];
            RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Cbs = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[23U];
            RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Eir = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[24U];
            RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Ebs = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[25U];
            CfgeConfigBits = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[26U];
            RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Mren = ((CfgeConfigBits & NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_MREN_MASK) == 0U) ? FALSE : TRUE;
            RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Doy = ((CfgeConfigBits & NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_DOY_MASK) == 0U) ? FALSE : TRUE;
            RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Cm = ((CfgeConfigBits & NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_CM_MASK) == 0U) ? FALSE : TRUE;
            RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Cf = ((CfgeConfigBits & NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_CF_MASK) == 0U) ? FALSE : TRUE;
            RatePolicerTableEntry->RatePolicerCfgeData.Cfge_Ndor = ((CfgeConfigBits & NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_NDOR_MASK) == 0U) ? FALSE : TRUE;
            SduType = (uint8)((CfgeConfigBits & NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_SDU_TYPE_MASK) >> NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_SDU_TYPE_SHIFT);
            switch (SduType)
            {
                case 0U:
                    RatePolicerTableEntry->RatePolicerCfgeData.Cfge_SduType = NETC_ETH_IP_PPDU;
                    break;
                case 1U:
                    RatePolicerTableEntry->RatePolicerCfgeData.Cfge_SduType = NETC_ETH_IP_MPDU;
                    break;
                case 2U:
                    RatePolicerTableEntry->RatePolicerCfgeData.Cfge_SduType = NETC_ETH_IP_MSDU;
                    break;
                default:
                    RatePolicerTableEntry->RatePolicerCfgeData.Cfge_SduType = NETC_ETH_IP_RSDTYPE;
                    break;
            }
            /* fill FEE data */
            RatePolicerTableEntry->RatePolicerFunctionEnable = (((CfgeConfigBits >> NETC_ETH_IP_16BIT_SHIFT) & NETC_ETH_IP_RATEPOLICERTABLE_FEE_DATA_FEN_MASK) == 0U) ? FALSE : TRUE;
            /* fill PSE data */
            RatePolicerTableEntry->MarkRedFlag = (((CfgeConfigBits >> NETC_ETH_IP_24BIT_SHIFT) & NETC_ETH_IP_RATEPOLICERTABLE_CFGE_DATA_MREN_MASK) == 0U) ? FALSE : TRUE;
        }
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_DeleteRatePolicerTableEntry
 * Description   : Delete Rate policer table entry function.
 *
 *
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_DeleteRatePolicerTableEntry( const uint8 CtrlIndex,
                                                                uint32 *MatchedEntries,
                                                                uint32 RatePolicerEntryId
                                                              )
{
    Netc_Eth_Ip_StatusType status;
    uint32 ActionsData = 0U;
    NetcEth_Ip_ReqHeaderTableOperationDataType OperationData = {0U};

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;
    SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_22();
    /* ------initialize the table request data buffer------ */
    Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;      /* Delete command will ignore ActionsData data field */
    Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_ENTRYID_FIELD] = RatePolicerEntryId;        /* fill in Entry_ID field (Access Key) */
    SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_22();

    /* fill in operation data for config field of Request Header*/
    OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
    OperationData.Version = NETC_ETH_IP_CMDBD_REQFMT_PROTOCOL_VERSION;         /* protocol version = 2 */
    OperationData.TableId = NETC_ETH_IP_RATE_POLICER_TABLE_ID;
    OperationData.AccessMethod = NETC_ETH_ENTRY_ID_MATCH;                      /* for delete command, always uses NETC_ETH_ENTRY_ID_MATCH method */
    OperationData.Cmd = NETC_ETH_DELETE_CMD;
    OperationData.ReqBuffLength = (NETC_ETH_IP_TABLE_COMMON_REQBUFFER_8BYTE_LEN);           /* set request data buffer length */
    OperationData.RspBuffLength = (NETC_ETH_IP_TABLE_COMMON_RSPBUFFER_0BYTE_LEN);           /* set response data buffer with normal length */

    /* send the "Delete" command */
    status = Netc_Eth_Ip_SendCommand(CtrlIndex, &OperationData);
#if defined(ERR_IPV_NETC_051243)
    #if (STD_ON == ERR_IPV_NETC_051243)
    /* Error code 0x8A is not a real error. check it on Errata. */
    if ((status == NETC_ETH_IP_STATUS_NOT_REAL_ERROR) || (status == NETC_ETH_IP_STATUS_SUCCESS))
    {
    #endif
#else
    if (status == NETC_ETH_IP_STATUS_SUCCESS)
    {
#endif
        status = NETC_ETH_IP_STATUS_SUCCESS;
        Netc_Eth_Ip_GetMatchedEntries(CtrlIndex, MatchedEntries);
    }

    return status;
}

Netc_Eth_Ip_StatusType Netc_Eth_Ip_CheckFrameStatus(uint8 ctrlIndex,
                                                    uint8 ring,
                                                    uint32 ConsumerIndex,
                                                    const uint8 *buff,
                                                    Netc_Eth_Ip_TimestampType *timeStampInfo,
                                                    Netc_Eth_Ip_TxStatusType *txStatus)

{

    Netc_Eth_Ip_TxBDRType *txBDR;
    uint32 LastDescrCheckIndex;
    volatile uint32 CurrDescrCheckIndex;
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
    uint32 currentTimeHigh;
    uint32 currentTimeLow;
    uint64 nanoSeconds;
#ifdef NETC_ETH_0_USED
    uint16 TimestampInfoIndex;
#endif /* NETC_ETH_0_USED */
#endif /* STD_ON == NETC_ETH_IP_EXTENDED_BUFF */
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;

    LastDescrCheckIndex= Netc_Eth_Ip_apxState[ctrlIndex]->lastTxDataBuffAddrIdx[ring];
    /* Get the addres of the current BDR to get status for it. */
    CurrDescrCheckIndex = (uint32)( (LastDescrCheckIndex + NETC_ETH_IP_PRODUCER_INCR) % \
                                    (uint32)Netc_Eth_Ip_apxState[ctrlIndex]->TxRingSize[ring] );

    /* Verification that the current frame we check is mapped on the right BD in hardware
           In Autosar case this check will never happen because the frame buffers are always provided in order
           from the upper layer.
    */
    #ifdef MCAL_ENABLE_FAULT_INJECTION
        MCAL_FAULT_INJECTION_POINT(ETH_READ_BUFFER_ADDRESS_FIP);
    #endif
    if (buff == Netc_Eth_Ip_apxState[ctrlIndex]->TxDataBuffAddr[ring][LastDescrCheckIndex])
    {
        if ((ConsumerIndex != LastDescrCheckIndex) && \
            ((boolean)TRUE == Netc_Eth_Ip_apxState[ctrlIndex]->LockTxBuffDescr[ring][LastDescrCheckIndex]))
        {
            /* Get the descriptor corresponding to the buff pointer (by looping through the descriptors) */
            txBDR = (Netc_Eth_Ip_TxBDRType *)((uint32)(Netc_Eth_Ip_apxState[ctrlIndex]->FirstTxRingDescAddr[ring]) + (((uint32)(LastDescrCheckIndex / NETC_ETH_IP_PRODUCER_INCR)) * ((uint32)(sizeof(Netc_Eth_Ip_TxBDRType)))));

            /* Check if there was a writeback in the descriptor */
            if (NETC_ETH_IP_TXBD_WRITEBACK_MASK == (txBDR->buffConfig & NETC_ETH_IP_TXBD_WRITEBACK_MASK))
            {
                /* Check the STATUS bitfield and read the possible errors and store them in info */
                if (0U != (uint16)(((Netc_Eth_Ip_TxBDRWritebackType *)txBDR)->FlagsAndStatus & NETC_ETH_IP_TX_WB_STATUS_MASK))
                {
                    *txStatus = (Netc_Eth_Ip_TxStatusType)(((const Netc_Eth_Ip_TxBDRWritebackType *)txBDR)->FlagsAndStatus & NETC_ETH_IP_TX_WB_STATUS_MASK);
                }
                else
                {
    #if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
                    /* Get the frame Timestamp */
                    if (NULL_PTR != timeStampInfo)
                    {
                        /*Read the HIGH Part from SICTR registers in a succesive manner, first the LOW part, then imediately, the HIGH part*/
                        currentTimeLow = (uint32)(netcSIsBase[ctrlIndex]->SICTR0);
                        currentTimeHigh = (uint32)(netcSIsBase[ctrlIndex]->SICTR1);

                        /*Check for overflow on Low part of the timer*/
                        if( (uint32) (((const Netc_Eth_Ip_TxBDRWritebackType *)txBDR)->Timestamp) > currentTimeLow)
                        {
                            currentTimeHigh--;
                        }

                        nanoSeconds = (uint64) ( (uint64)(((uint64)currentTimeHigh) << 32U) | (uint64)((const Netc_Eth_Ip_TxBDRWritebackType *)txBDR)->Timestamp );

                        /*Take the nanoseconds*/
                        timeStampInfo->nanoseconds = (uint32) (NETC_ETH_IP_GET_NANOSECONDS(((const Netc_Eth_Ip_TxBDRWritebackType *)txBDR)->Timestamp));

                        /*Take the seconds, the low part of 32bits*/
                        timeStampInfo->seconds = (uint32) (NETC_ETH_IP_NANO_TO_SECONDS(nanoSeconds) & NETC_ETH_IP_SECONDS_LOW_MASK_U64);

                        /*Take the seconds, the high part of 16bits*/
                        timeStampInfo->secondsHi = (uint16) ((NETC_ETH_IP_NANO_TO_SECONDS(nanoSeconds) >> 32U) & 0xFFFFU);
                    }

    #ifdef NETC_ETH_0_USED
                    if(((uint8)0U == ring) && ((uint8)0U == ctrlIndex))
                    {
                        TimestampInfoIndex = (0U != ConsumerIndex) ? ((uint16)ConsumerIndex) : (Netc_Eth_Ip_apxState[ctrlIndex]->TxRingSize[ring]);
                        Netc_Eth_Ip_TxManagementInfoBuff[0U][(TimestampInfoIndex / NETC_ETH_IP_PRODUCER_INCR) - 1U].TxTimeStampID = (uint16)(((Netc_Eth_Ip_TxBDRWritebackType *)txBDR)->TxTimestampID);
                    }
    #endif
    #else
                    (void)timeStampInfo;
    #endif

                }
            }
            else
            {
                /* The writeback will only be set if there is a problem sending the frame.
                   If the frame is sent successfully the status needs to be set manually */
                *txStatus = NETC_ETH_TX_NO_ERR;
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
    else
    {
        status = NETC_ETH_IP_STATUS_BUFF_NOT_FOUND;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_ConfigCreditBasedShaperReg
 * Description   : Internal function for configuring credit based shaper registers.
 *
 *END**************************************************************************/
static inline void Netc_Eth_Ip_ConfigCreditBasedShaperReg(const uint8 ctrlIndex, const Netc_Eth_Ip_ConfigType *config)
{
    uint8 trafficClass;
    uint32 localPtcTmSDUR;

    (void)ctrlIndex;
    if(config->generalConfig->cbsConfig != NULL_PTR)
    {
        for(trafficClass = 0U; trafficClass < NETC_ETH_IP_NUMBER_OF_PRIORITIES; trafficClass++)
        {
            /* Coonfigure the maximum frame size per shaping class, Max 2000 */
            localPtcTmSDUR = IP_NETC__ENETC0_PORT->TCT_NUM[trafficClass].PTCTMSDUR;
            localPtcTmSDUR &= ~ENETC_PORT_PTCTMSDUR_MAXSDU_MASK;
            localPtcTmSDUR |= ENETC_PORT_PTCTMSDUR_MAXSDU(config->generalConfig->cbsConfig[trafficClass]->EthMaxSizedFrame);
            IP_NETC__ENETC0_PORT->TCT_NUM[trafficClass].PTCTMSDUR = localPtcTmSDUR;

            IP_NETC__ENETC0_PORT->TCT_NUM[trafficClass].PTCCBSR0 = ENETC_PORT_PTCCBSR0_CBSE(config->generalConfig->cbsConfig[trafficClass]->EthEgressCBShaperEnable ? 1U : 0U)
                                                                                            | ENETC_PORT_PTCCBSR0_BW(config->generalConfig->cbsConfig[trafficClass]->EthEgressCBShaperBandwidth);
            IP_NETC__ENETC0_PORT->TCT_NUM[trafficClass].PTCCBSR1 = ENETC_PORT_PTCCBSR1_HI_CREDIT(config->generalConfig->cbsConfig[trafficClass]->EthEgressHiCredit);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_SetupErrorReporting
 * Description   : Internal function for configuring register used in reporting error to Pcie Event collector.
 *
 *END**************************************************************************/
static Netc_Eth_Ip_StatusType Netc_Eth_Ip_SetupErrorReporting(const Netc_Eth_Ip_EnetcGeneralConfigType *psi0Config)
{
    /** @brief Enum with the generic Pcie Functions present in the NETC SOC. */
    const Netc_Eth_Ip_PcieFunction Netc_Eth_Ip_PcieFunctionMapping[FEATURE_NETC_NUMBER_OF_FUNC] = {TIMER, EMDIO, SWITCH, ENETC};

    uint8 u8Iterator = 0U;
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_SUCCESS;

    if  (
        ((IP_NETC__NETC_F0_PCI_HDR_TYPE0->PCI_CFH_CMD & ((uint16) (NETC_F0_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN_MASK <<
                                                                  NETC_F0_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN_SHIFT) |
                                                                 (NETC_F0_PCI_HDR_TYPE0_PCI_CFH_CMD_MEM_ACCESS_MASK <<
                                                                  NETC_F0_PCI_HDR_TYPE0_PCI_CFH_CMD_MEM_ACCESS_SHIFT))) == (uint16)0U) ||
        ((IP_NETC__NETC_F1_PCI_HDR_TYPE0->PCI_CFH_CMD & ((uint16) (NETC_F1_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN_MASK <<
                                                                  NETC_F1_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN_SHIFT) |
                                                                 (NETC_F1_PCI_HDR_TYPE0_PCI_CFH_CMD_MEM_ACCESS_MASK <<
                                                                  NETC_F1_PCI_HDR_TYPE0_PCI_CFH_CMD_MEM_ACCESS_SHIFT))) == (uint16)0U) ||
        ((IP_NETC__NETC_F2_PCI_HDR_TYPE0->PCI_CFH_CMD & ((uint16) (NETC_F2_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN_MASK <<
                                                                  NETC_F2_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN_SHIFT) |
                                                                 (NETC_F2_PCI_HDR_TYPE0_PCI_CFH_CMD_MEM_ACCESS_MASK <<
                                                                  NETC_F2_PCI_HDR_TYPE0_PCI_CFH_CMD_MEM_ACCESS_SHIFT))) == (uint16)0U) ||
        ((IP_NETC__NETC_F3_PCI_HDR_TYPE0->PCI_CFH_CMD & ((uint16) (NETC_F3_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN_MASK <<
                                                                  NETC_F3_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN_SHIFT) |
                                                                 (NETC_F3_PCI_HDR_TYPE0_PCI_CFH_CMD_MEM_ACCESS_MASK <<
                                                                  NETC_F3_PCI_HDR_TYPE0_PCI_CFH_CMD_MEM_ACCESS_SHIFT))) == (uint16)0U)
        )
    {
        Status = NETC_ETH_IP_STATUS_ERROR;
    }

    for (u8Iterator = 0U; u8Iterator < FEATURE_NETC_NUMBER_OF_FUNC; u8Iterator++)
    {
        /* Initialize the error reporting structure which will revel the status on SWITCH, TIMER, EMDIO and ENETC */
        Netc_Eth_Ip_ErrorStatus[u8Iterator].Function = Netc_Eth_Ip_PcieFunctionMapping[u8Iterator];
        Netc_Eth_Ip_ErrorStatus[u8Iterator].StatusErrors = 0U;
    }

    /* Initialize the error reporting structure which will reveal the status for PSI */
    Netc_Eth_Ip_ErrorStatus[NETC_ETH_IP_PSI0_FUNCTION_INDEX].Function = PSI;
    Netc_Eth_Ip_ErrorStatus[NETC_ETH_IP_PSI0_FUNCTION_INDEX].StatusErrors = 0U;

    for (u8Iterator = FEATURE_NETC_NUMBER_OF_FUNC+1U; u8Iterator < (FEATURE_NETC_ETH_NUM_OF_VIRTUAL_CTRLS + FEATURE_NETC_NUMBER_OF_FUNC); u8Iterator++)
    {
        /* Initialize the error reporting structure which will reveal the status on each VSI */
        Netc_Eth_Ip_ErrorStatus[u8Iterator].Function = VSI;
        Netc_Eth_Ip_ErrorStatus[u8Iterator].StatusErrors = 0U;
    }

    /*For the Event Collector to assert INTA for a reported error, it must clear the interrupt disable bit:*/
    IP_NETC__IERC_F0_PCI_HDR_TYPE0->PCI_CFH_CMD = ierc_pci_PCI_CFH_CMD_INTR_DISABLE(0u);

    /* Enable the Pcie AER Error Reporting */
    if (psi0Config->enableUncorrectableErrors)
    {
        /* For the Event Collector to assert INTA for a reported error, it must enable the reporting of the error
        When set, this bit enables the generation of an interrupt when a fatal error is reported by any of the Integrated Endpoints (iEPs)
        or the Event Collector itself.*/
        IP_NETC__IERC_F0_PCI_HDR_TYPE0->PCIE_CFC_AER_ROOT_ERR_CMD |= (ierc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_NON_FATAL_ERR_RPT_EN(1U) |
                                                                    ierc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_FATAL_ERR_RPT_EN(1U));
        /*Unmask interrupts for ENETC0, SWITCH, TIMER, EMDIO*/
        for (u8Iterator = 0U; u8Iterator < FEATURE_NETC_NUMBER_OF_FUNC; u8Iterator++ )
        {
            netcPCIePFBase[u8Iterator]->PCIE_CFC_AER_UCORR_ERR_MASK = NETC_F1_PCI_HDR_TYPE0_PCIE_CFC_AER_UCORR_ERR_MASK_UCORR_INT_ERR_MASK(0U);
        }

        /*Unmask interrupts for PSI0*/
        IP_NETC__NETC_F3_PCI_HDR_TYPE0->PCIE_CFC_AER_UCORR_ERR_MASK = NETC_F3_PCI_HDR_TYPE0_PCIE_CFC_AER_UCORR_ERR_MASK_UCORR_INT_ERR_MASK(0U);

        /*Unmask interrupts for vfs*/
        for (u8Iterator = 1U; u8Iterator < FEATURE_NETC_ETH_NUM_OF_VIRTUAL_CTRLS; u8Iterator++ )
        {
            netcVFBase[u8Iterator]->PCIE_CFC_AER_UCORR_ERR_MASK = NETC_VF1_PCI_HDR_TYPE0_PCIE_CFC_AER_UCORR_ERR_MASK_UCORR_INT_ERR_MASK(0U);
        }

        for (u8Iterator = 0U; u8Iterator < FEATURE_NETC_ETH_NUMBER_OF_CTRLS; u8Iterator++ )
        {
            netcSIsBase[u8Iterator]->SIUPECR = NETC_F3_SI0_SIUPECR_RD(0U);
            netcSIsBase[u8Iterator]->SIUNSBECR = NETC_F3_SI0_SIUNSBECR_THRESHOLD(psi0Config->errorReportingSystemBusErrorsThreshold);
            netcSIsBase[u8Iterator]->SIUNMECR = NETC_F3_SI0_SIUNMECR_RD(0U) | NETC_F3_SI0_SIUNMECR_THRESHOLD(psi0Config->errorReportingMultiBitECCErrorsThreshold);
            netcSIsBase[u8Iterator]->SIUFSBECR = NETC_F3_SI0_SIUFSBECR_RD(0U);
            netcSIsBase[u8Iterator]->SIUFMECR = NETC_F3_SI0_SIUFMECR_RD(0U);
            netcSIsBase[u8Iterator]->SIUFIECR = NETC_F3_SI0_SIUFIECR_RD(0U);
        }

        /* Switch system bus error. */
        IP_NETC__SW0_COMMON->UNSBECR = NETC_F2_COMMON_UNSBECR_THRESHOLD(psi0Config->errorReportingSystemBusErrorsThreshold);


        IP_NETC__SW0_COMMON->UNMACECR = ~NETC_F2_COMMON_UNMACECR_PORT0(0U) |
                                        ~NETC_F2_COMMON_UNMACECR_PORT1(0U) |
                                        ~NETC_F2_COMMON_UNMACECR_PORT2(0U);
        IP_NETC__ENETC0_COMMON->UNMACECR = NETC_F3_COMMON_UNMACECR_PORT0(0u);

        /*Internal memory multi bit ECC error */
        IP_NETC__NETC_PRIV->UNMECR = NETC_PRIV_UNMECR_RD(0U) | NETC_PRIV_UNMECR_THRESHOLD(psi0Config->errorReportingMultiBitECCErrorsThreshold);
        IP_NETC__ENETC0_COMMON->UNMECR = NETC_F3_COMMON_UNMECR_RD(0U) | NETC_F3_COMMON_UNMECR_THRESHOLD(psi0Config->errorReportingMultiBitECCErrorsThreshold);
        IP_NETC__SW0_COMMON->UNMECR =  NETC_F2_COMMON_UNMECR_RD(0U) | NETC_F2_COMMON_UNMECR_THRESHOLD(psi0Config->errorReportingMultiBitECCErrorsThreshold);

        /*integrity error Uncorrectable Non-Fatal Integrity Faults */
        ((IP_NETC__EMDIO_GLOBAL->ERROR).EMDIO).EMDIOUNIECR = NETC_F1_GLOBAL_EMDIOUNIECR_THRESHOLD(psi0Config->errorReportigIntegrityErrorsThreshold) | NETC_F1_GLOBAL_EMDIOUNIECR_RD(0U);

        /*integrity error Uncorrectable Non-Fatal Integrity Faults*/
        IP_NETC__NETC_PRIV->UNIECR = NETC_PRIV_UNIECR_RD(0U) |NETC_PRIV_UNIECR_THRESHOLD(psi0Config->errorReportigIntegrityErrorsThreshold);
        IP_NETC__ENETC0_COMMON->UNIECR = NETC_F3_COMMON_UNIECR_RD(0U) | NETC_F3_COMMON_UNIECR_THRESHOLD(psi0Config->errorReportigIntegrityErrorsThreshold);
        IP_NETC__SW0_COMMON->UNIECR =  NETC_F2_COMMON_UNIECR_RD(0U) | NETC_F2_COMMON_UNIECR_THRESHOLD(psi0Config->errorReportigIntegrityErrorsThreshold);

        ((IP_NETC__TMR0_GLOBAL->ERROR).TIMER).TUFSBECR = NETC_F0_GLOBAL_TUFSBECR_RD(0U);
        ((IP_NETC__EMDIO_GLOBAL->ERROR).EMDIO).EMDIOUFSBECR = NETC_F1_GLOBAL_EMDIOUFSBECR_RD(0U);
        IP_NETC__SW0_COMMON->UFSBECR = NETC_F2_COMMON_UFSBECR_RD(0U);

        IP_NETC__NETC_PRIV->UFMECR = NETC_PRIV_UFMECR_RD(0U);
        IP_NETC__ENETC0_COMMON->UFMECR = NETC_F3_COMMON_UFMECR_RD(0U) ;
        IP_NETC__SW0_COMMON->UFMECR =  NETC_F2_COMMON_UFMECR_RD(0U);

        IP_NETC__NETC_PRIV->UFIECR = NETC_PRIV_UFIECR_RD(0U);
        IP_NETC__ENETC0_COMMON->UFIECR = NETC_F3_COMMON_UFIECR_RD(0U) ;
        IP_NETC__SW0_COMMON->UFIECR =  NETC_F2_COMMON_UFIECR_RD(0U);

        IP_NETC__SW0_COMMON->UFSBECR = NETC_F2_COMMON_UFSBECR_RD(0U);

    }
    if (psi0Config->enableCorrectableErrors)
    {
        /* For the Event Collector to assert INTA for a reported error, it must enable the reporting of the error
        When set, this bit enables the generation of an interrupt when a correctable error is reported by any of the Integrated Endpoints (iEPs)
        or the Event Collector itself.*/
        IP_NETC__IERC_F0_PCI_HDR_TYPE0->PCIE_CFC_AER_ROOT_ERR_CMD |= ierc_pci_PCIE_CFC_AER_ROOT_ERR_CMD_CORR_ERR_RPT_EN(1U);

        /* Function F0 (Timer) and F1 (EMDIO) must not clear mask bit, enabling reporting of correctable interrupts, to prevent loss of uncorrectable error reporting.*/
        for (u8Iterator = 2U; u8Iterator < FEATURE_NETC_NUMBER_OF_FUNC; u8Iterator++ )
        {
            netcPCIePFBase[u8Iterator]->PCIE_CFC_AER_CORR_ERR_MASK = NETC_F0_PCI_HDR_TYPE0_PCIE_CFC_AER_CORR_ERR_MASK_CORR_INT_MASK(0U);
        }

        /*Unmask interrupts for PSI0*/
        IP_NETC__NETC_F3_PCI_HDR_TYPE0->PCIE_CFC_AER_CORR_ERR_MASK = NETC_F3_PCI_HDR_TYPE0_PCIE_CFC_AER_CORR_ERR_MASK_CORR_INT_MASK(0U);

        for (u8Iterator = 1U; u8Iterator < FEATURE_NETC_ETH_NUM_OF_VIRTUAL_CTRLS; u8Iterator++ )
        {
            netcVFBase[u8Iterator]->PCIE_CFC_AER_CORR_ERR_MASK = NETC_VF1_PCI_HDR_TYPE0_PCIE_CFC_AER_CORR_ERR_MASK_CORR_INT_MASK(0U);
        }

        for (u8Iterator = 0U; u8Iterator < FEATURE_NETC_ETH_NUMBER_OF_CTRLS; u8Iterator++ )
        {
            netcSIsBase[u8Iterator]->SICMECR = NETC_F3_SI0_SICMECR_THRESHOLD(psi0Config->errorReportigSingleECCErrorsThreshold);
        }

        IP_NETC__NETC_PRIV->CMECR = NETC_PRIV_CMECR_THRESHOLD(psi0Config->errorReportigSingleECCErrorsThreshold);
        IP_NETC__ENETC0_COMMON->CMECR = NETC_F3_COMMON_CMECR_THRESHOLD(psi0Config->errorReportigSingleECCErrorsThreshold) ;
        IP_NETC__SW0_COMMON->CMECR =  NETC_F2_COMMON_CMECR_THRESHOLD(psi0Config->errorReportigSingleECCErrorsThreshold);
    }

    return Status;
}

#if (NETC_ETH_MAX_NUMBER_OF_IPFTABLE_LIST > 0U)
/* inline function for initializing ingress port filter table entries data during ENETC init */
static inline void Netc_Eth_Ip_InitIPFTableEntryData(const Netc_Eth_Ip_ConfigType * Config, uint8 IPFTableListIdx, Netc_Eth_Ip_IngressPortFilterEntryDataType *IngressPortFilterTableEntry)
{
    uint8 MacByteIdx;
    uint8 IpByteIdx;
    uint8 PayloadDataIdx;

    IngressPortFilterTableEntry->IngressPortFilterEntryID = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterEntryID;

    /* fill in cfge data */
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeTargetForSelectedFilterAction = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterCfgeData.CfgeTargetForSelectedFilterAction;
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeIpv = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterCfgeData.CfgeIpv;
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeDr = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterCfgeData.CfgeDr;
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeRelativePrecedentResolution = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterCfgeData.CfgeRelativePrecedentResolution;
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeOverrideIpv = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterCfgeData.CfgeOverrideIpv;
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeOverrideDr = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterCfgeData.CfgeOverrideDr;
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeWakeOnLanTriggerEnable = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterCfgeData.CfgeWakeOnLanTriggerEnable;
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeFilterForwardingAction = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterCfgeData.CfgeFilterForwardingAction;
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeFilterAction = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterCfgeData.CfgeFilterAction;

    /* fill in keye data */
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePrecedence = 3U;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.keyeFrmAttributeFlags = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.keyeFrmAttributeFlags;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeFrmAttributeFlagsMask = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeFrmAttributeFlagsMask;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDifferentiatedServicesCodePoint = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeDifferentiatedServicesCodePoint;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDifferentiatedServicesCodePointMask = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeDifferentiatedServicesCodePointMask;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformation = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformation;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformationMask = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformationMask;
    for (MacByteIdx = 0U; MacByteIdx < 6U; MacByteIdx++)    /* Dst Mac Address */
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[MacByteIdx] = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeDstMacAddr[MacByteIdx];
    }
    for (MacByteIdx = 0U; MacByteIdx < 6U; MacByteIdx++)    /* Dst Mac Address Mask */
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[MacByteIdx] = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeDstMacAddrMask[MacByteIdx];
    }
    for (MacByteIdx = 0U; MacByteIdx < 6U; MacByteIdx++)    /* Src Mac Address */
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[MacByteIdx] = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeSrcMacAddr[MacByteIdx];
    }
    for (MacByteIdx = 0U; MacByteIdx < 6U; MacByteIdx++)    /* Src Mac Address Mask */
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[MacByteIdx] = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeSrcMacAddrMask[MacByteIdx];
    }
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeInnerVLANTagControlInformation = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeInnerVLANTagControlInformation;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeInnerVLANTagControlInformationMask = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeInnerVLANTagControlInformationMask;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeEtherType = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeEtherType;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeEtherTypeMask = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeEtherTypeMask;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPProtocol = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeIPProtocol;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPProtocolMask = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeIPProtocolMask;
    for (IpByteIdx = 0U; IpByteIdx < 4U; IpByteIdx++)    /* IP Source Address */
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPSourceAddress[IpByteIdx] = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeIPSourceAddress[IpByteIdx];
    }
    for (IpByteIdx = 0U; IpByteIdx < 4U; IpByteIdx++)    /* IP Source Address Mask */
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPSourceAddressMask[IpByteIdx] = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeIPSourceAddressMask[IpByteIdx];
    }
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4SourcePort = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeL4SourcePort;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4SourcePortMask = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeL4SourcePortMask;
    for (IpByteIdx = 0U; IpByteIdx < 4U; IpByteIdx++)    /* IP Destination Address */
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPDestinationAddress[IpByteIdx] = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeIPDestinationAddress[IpByteIdx];
    }
    for (IpByteIdx = 0U; IpByteIdx < 4U; IpByteIdx++)    /* IP Destination Address Mask */
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPDestinationAddressMask[IpByteIdx] = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeIPDestinationAddressMask[IpByteIdx];
    }
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4DestinationPort = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeL4DestinationPort;
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4DestinationPortMask = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyeL4DestinationPortMask;

    /* fill in payload data */
    for (PayloadDataIdx = 0U; PayloadDataIdx < 24U; PayloadDataIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytes[PayloadDataIdx] = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyePayloadBytes[PayloadDataIdx];
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytesMask[PayloadDataIdx] = (*(*Config->generalConfig).IngressPortFilterTableList)[IPFTableListIdx].IngressPortFilterkeyeData.KeyePayloadBytesMask[PayloadDataIdx];
    }

}
#endif

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
    Netc_Eth_Ip_IngressPortFilterEntryDataType IngressPortFilterTableEntry = {0U};
    uint8 IPFTableListIdx;
    uint32 MatchedEntries = 0UL;

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

        /* Set Layer 3 IPv4 Header checksum validation*/
        IP_NETC__ENETC0_BASE->PARCSCR = NETC_F3_PARCSCR_L4CD((*config->generalConfig).rxCheckSumOffloadingIPV4);
        /*
        Checking only TCP offload because when it is enabled, UDP is by default enabled in configuration
        Set Layer 4 TCP and UDP checksum validation
        */
        IP_NETC__ENETC0_BASE->PARCSCR = NETC_F3_PARCSCR_L3CD((*config->generalConfig).rxCheckSumOffloadingTCPUDP);

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
                    IP_NETC__ENETC0_PORT->PMAR0 = ((uint32)(*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].primaryMACAddress[0U])          | \
                                                  (((uint32)(*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].primaryMACAddress[1U]) << 8U)  | \
                                                  (((uint32)(*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].primaryMACAddress[2U]) << 16U) | \
                                                  (((uint32)(*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].primaryMACAddress[3U]) << 24U);
                    IP_NETC__ENETC0_PORT->PMAR1 = ((uint32)(*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].primaryMACAddress[4U]) | \
                                                  (((uint32)(*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].primaryMACAddress[5U]) << 8U);
                    IP_NETC__ENETC0_PORT->POR = 0U;     /* Enable Rx and Tx Path for port (for S32N the default status for Rx and Tx path is disabled.) */
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

                /* Number of entries in a MSI table for the current SI. */
                IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSICFGR2 = NETC_ETH_IP_NUM_OF_ENTRIES_MSITABLE;

                /* Configure the number or TX and RX BD Rings for each SI */
                IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSICFGR0 &= ~(NETC_F3_PSICFGR0_NUM_TX_BDR_MASK | NETC_F3_PSICFGR0_NUM_RX_BDR_MASK);

                IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSICFGR0 |= NETC_F3_PSICFGR0_NUM_TX_BDR((*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].NumberOfTxBDR) | \
                                                                 NETC_F3_PSICFGR0_NUM_RX_BDR((*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].NumberOfRxBDR);

                /* Configure the bandwidth weight for the current SI */
                IP_NETC__ENETC0_BASE->NUM_SI[siHwId].PSICFGR0 |= NETC_F3_PSICFGR0_SIBW((*(*config->generalConfig).stationInterfaceGeneralConfig)[u8Iterator].SIBandwidthWeight);

#if (STD_ON == NETC_ETH_IP_VLAN_SUPPORT)
                SiConfig = &((*config->generalConfig->stationInterfaceGeneralConfig)[siHwId]);

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

                if (ctrlIndex != siHwId)
                {
                    /* Enable bus for virtual function. */
                    netcVFBase[u8Iterator]->PCI_CFH_CMD |= NETC_VF1_PCI_HDR_TYPE0_PCI_CFH_CMD_BUS_MASTER_EN(1U);
                }
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

        if ((*config->generalConfig).enableCorrectableErrors || (*config->generalConfig).enableUncorrectableErrors)
        {
            Status = Netc_Eth_Ip_SetupErrorReporting(config->generalConfig);
        }

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

        /* Initialize State structure */
        Netc_Eth_Ip_InitStateStructure(ctrlIndex, config);

        /* Configure Command ring */
        Netc_Eth_Ip_InitCBDR(ctrlIndex);

        /* only for PSI0 */
        if (NETC_ETH_IP_PHYSICAL_SI == Netc_Eth_Ip_apxState[ctrlIndex]->SiType)
        {
            /* pseudo port speed configuration*/
            IP_NETC__ENETC0_PORT->PCR &= ~ENETC_PORT_PCR_PSPEED_MASK;
            IP_NETC__ENETC0_PORT->PCR |= ENETC_PORT_PCR_PSPEED(NETC_ETH_IP_SHAPING_PSPEED_2000MBITS);
            /* clock frequency from configuration, used for credit based shapers*/
            Netc_Eth_Ip_NetcClockFrequency = config->netcClockFrequency;
            /* Configure Credit Based Shaper registers */
            Netc_Eth_Ip_ConfigCreditBasedShaperReg(ctrlIndex, config);

#if (NETC_ETH_MAX_NUMBER_OF_IPFTABLE_LIST > 0U)
            /* Initialize IPF table */
            if ((*config->generalConfig).numberOfIPFTableList > 0U)
            {
                /* Set the EN bit in Station interface mode register (SIMR) to enable psi0*/
                netcSIsBase[ctrlIndex]->SIMR |= NETC_F3_SI0_SIMR_EN_MASK;

                for (IPFTableListIdx = 0U; IPFTableListIdx < (*config->generalConfig).numberOfIPFTableList; IPFTableListIdx++)
                {
                    /* init IPF table entry data */
                    Netc_Eth_Ip_InitIPFTableEntryData(config, IPFTableListIdx, &IngressPortFilterTableEntry);

                    /* add static IPF table entries */
                    Status = Netc_Eth_Ip_AddIngressPortFilterTableEntry(0U, &MatchedEntries, &IngressPortFilterTableEntry);
                }

                /* Clear the EN bit in Station interface mode register (SIMR) to disalbe psi0 */
                netcSIsBase[ctrlIndex]->SIMR &= ~NETC_F3_SI0_SIMR_EN_MASK;
            }
#endif
        }

        Netc_Eth_Ip_InitNTMPTables(ctrlIndex, config);

        /* Initialize TX BDRs */
        Netc_Eth_Ip_InitTxBD(ctrlIndex, config);
        /* Initialize RX BDRs */
        Netc_Eth_Ip_InitRxBD(ctrlIndex, config);

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
 * Function Name : Netc_Eth_Ip_ConfigureCreditBasedShaper
 * Description   : function for configuring the CBS
 * implements Netc_Eth_Ip_ConfigureCreditBasedShaper_Activity
 *END**************************************************************************/
Std_ReturnType Netc_Eth_Ip_ConfigureCreditBasedShaper(const uint8 ctrlIndex, const uint8 TrafficClass, const uint64 idleSlope)
{
    Std_ReturnType status = E_OK;
    uint64 portTxRate;
    uint64 largeBandwidth;
    uint32 bandwidth;
    uint64 largeEgressHiCredit;
    uint32 egressHiCredit;
    uint32 Netc_Eth_Ip_MaxFrameSize;

#if(STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    /* A Slope of zero would cause a bandwidth of zero and this would cause a buffer leak */
    DevAssert(idleSlope > 0U);
    DevAssert(TrafficClass < NETC_ETH_IP_NUMBER_OF_PRIORITIES);
#endif

    (void)ctrlIndex;

    /*This is a pseudo-port. */
    portTxRate = 2000000000UL;

    largeBandwidth = idleSlope / (portTxRate / 10000UL); /* bandwidth is in % and 100th precision, so need to divide by 10000 */
    if( largeBandwidth < 100UL )
    {
        largeBandwidth = 100UL; /* Min of 1% bandwidth, otherwise frames would get stuck in the switch */
    }
    /* Round and convert to uint32 */
    bandwidth = (uint32)(largeBandwidth/100UL);
    bandwidth = ((uint64)((((uint64)bandwidth)*100UL)+50UL)>largeBandwidth)?bandwidth:(bandwidth+1UL);

    /* High Credit in credits
           hiCredit (bits) = maxSizedFrame * (idleSlope / portTxRate)
           bandwidth = idleSlope / portTxRate
           Then:
               hiCredit (bits) = maxSizedFrame * bandwidth

           hiCredit (credits) = hiCredit (bits) * (ClockFrequency / portTxRate)
           Then:
               hiCredit (credits) = maxSizedFrame * bandwidth * (ClockFrequency / portTxRate)
    */
    Netc_Eth_Ip_MaxFrameSize = IP_NETC__ENETC0_PORT->TCT_NUM[TrafficClass].PTCTMSDUR;
    largeEgressHiCredit = largeBandwidth * Netc_Eth_Ip_MaxFrameSize * (Netc_Eth_Ip_NetcClockFrequency / (portTxRate)) / 100UL; /* Bandwidth is in %, need to div by 100 */
    /* Round and convert to uint32 */
    egressHiCredit = (uint32)(largeEgressHiCredit/100UL);
    egressHiCredit = (((egressHiCredit*100UL)+50UL)>egressHiCredit)?egressHiCredit:(egressHiCredit+1UL);
    SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_07();
    IP_NETC__ENETC0_PORT->TCT_NUM[TrafficClass].PTCCBSR0 &= ~ENETC_PORT_PTCCBSR0_BW_MASK;
    IP_NETC__ENETC0_PORT->TCT_NUM[TrafficClass].PTCCBSR0 |= ENETC_PORT_PTCCBSR0_BW(bandwidth);
    SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_07();
    IP_NETC__ENETC0_PORT->TCT_NUM[TrafficClass].PTCCBSR1 = ENETC_PORT_PTCCBSR1_HI_CREDIT(egressHiCredit);

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_EnableCreditBasedShaper
 * Description   : function for enabling a CBS
 * implements Netc_Eth_Ip_EnableCreditBasedShaper_Activity
 *END**************************************************************************/
Std_ReturnType Netc_Eth_Ip_EnableCreditBasedShaper(const uint8 ctrlIndex, const uint8 TrafficClass, const boolean Enable)
{
    Std_ReturnType status = E_OK;

#if(STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(TrafficClass < NETC_ETH_IP_NUMBER_OF_PRIORITIES);
#endif
    (void)ctrlIndex;
    SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_08();
    /* clear the bit first */
    IP_NETC__ENETC0_PORT->TCT_NUM[TrafficClass].PTCCBSR0 &= ~ENETC_PORT_PTCCBSR0_CBSE_MASK;
    /* write the bit */
    IP_NETC__ENETC0_PORT->TCT_NUM[TrafficClass].PTCCBSR0 |= ENETC_PORT_PTCCBSR0_CBSE((TRUE==Enable)?1U:0U);
    SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_08();

    return status;
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
            SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_03();
            /* Write the interrupt settings as configured */
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].RBIER  |= (uint32)1U;
            if (RxCoalescingIsrEnabled)
            {
                /*If timer threshold is used it should be set when RBaICR0[ICEN]=0 to avoid missing a "first packet" received condition which starts the timer.*/
                netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].RBICR1 |= NETC_F3_SI0_RBICR1_ICTT( Netc_Eth_Ip_apxState[ctrlIndex]->RxTimerThreshold[ringCounter]);
                netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].RBICR0 |= NETC_F3_SI0_RBICR0_ICPT(Netc_Eth_Ip_apxState[ctrlIndex]->RxPacketsThreshold[ringCounter]);
                netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].RBICR0 |= NETC_F3_SI0_RBICR0_ICEN(1U);
                SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_03();
            }
            else
            {                
                SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_03();
            }
        }
    }
    SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_03();
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
    SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_03();

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
    SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_02();

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
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].TBICR0 &= ~NETC_F3_SI0_TBICR0_ICEN_MASK;
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].TBIER  &= ~NETC_F3_SI0_TBIER_TXFIE_MASK;
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].TBICR1 = 0U; /* &= ~NETC_F3_SI0_TBICR1_ICTT_MASK; */
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].TBICR0 &= ~NETC_F3_SI0_TBICR0_ICPT_MASK;
            /* Reset producer and consumer indexes. */
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].TBPIR = 0U;
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].TBCIR = 0U;
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
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].RBICR1 = 0U; /* &= ~NETC_F3_SI0_RBICR1_ICTT_MASK; Changed due to CWE violation*/
            netcSIsBase[ctrlIndex]->BDR_NUM[ringCounter].RBICR0 &= ~NETC_F3_SI0_RBICR0_ICPT_MASK;
            rxTmpBDR = Netc_Eth_Ip_apxState[ctrlIndex]->FirstRxRingDescAddr[ringCounter];
            /* Loop through all descriptors of the queue */
            for (currBDIdx = 0U; currBDIdx < Netc_Eth_Ip_apxState[ctrlIndex]->RxRingSize[ringCounter]; currBDIdx++)
            {
    #if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
            if (!Netc_Eth_Ip_ControllerHasExternalRxBufferManagement[ctrlIndex])
            {
    #endif
                rxTmpBDR->configRxBD[0U] = (uint32)(Netc_Eth_Ip_apxState[ctrlIndex]->FirstRxDataBufferAddr[ringCounter]) + \
                                                    (uint32)(currBDIdx * Netc_Eth_Ip_apxState[ctrlIndex]->RxDataBuffMaxLenAddr[ringCounter]);
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
        SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_02();

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
                buff->data = (uint8*) ((uint32)Netc_Eth_Ip_apxState[ctrlIndex]->FirstTxDataBufferAddr[ring] + \
                                      (currProducerIdx * Netc_Eth_Ip_apxState[ctrlIndex]->TxDataBuffMaxLenAddr[ring]));
#if (NETC_ETH_IP_HAS_EXTERNAL_TX_BUFFERS == STD_ON)
            }
#endif
            /* If used, return the buffer index */
            if (buffId != NULL_PTR)
            {
                *buffId = (uint16)(currProducerIdx);
            }

            /* When the development error is enabled we need to add a barrier first in order to avoid speculative
               exection before the previous else if condition is completed. */
            MCAL_INSTRUCTION_SYNC_BARRIER();
            MCAL_DATA_SYNC_BARRIER();
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

    /*Check if the first buffer has length of at least 16 bytes. The hardware limits the first buffer to be of at least 16bytes.*/
    if (BufferLength[NETC_ETH_IP_FIRST_BUFFER_IDX] < NETC_ETH_IP_MIN_FRAME_LENGTH)
    {
        Status = NETC_ETH_IP_STATUS_INVALID_FRAME_LENGTH;
    }
    else
    {
        while ((FreeBuffers < NumBuffers) && (NETC_ETH_IP_STATUS_SUCCESS == Status))
        {
            NextProducerIndex = (NextProducerIndex + NETC_ETH_IP_PRODUCER_INCR) % (uint32)Netc_Eth_Ip_apxState[ctrlIndex]->TxRingSize[ring];
            /* If the buffer descriptor is free */
            if (NextProducerIndex !=  Netc_Eth_Ip_apxState[ctrlIndex]->lastTxDataBuffAddrIdx[ring])
            {
                if (BufferLength[FreeBuffers] <= (uint16)(Netc_Eth_Ip_apxState[ctrlIndex]->TxBufferLength[ring]))
                {
                    FreeBuffers++;
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

    /*Check if the first buffer does not exceed 16 bytes. The hardware limits the first buffer to 16bytes.*/
    if (Buffers[NETC_ETH_IP_FIRST_BUFFER_IDX].length < NETC_ETH_IP_MIN_FRAME_LENGTH)
    {
        Status = NETC_ETH_IP_STATUS_INVALID_FRAME_LENGTH;
    }
    else
    {
        while ((FreeBuffers < NumBuffers) && (NETC_ETH_IP_STATUS_SUCCESS == Status))
        {
            NextProducerIndex = (NextProducerIndex + NETC_ETH_IP_PRODUCER_INCR) % (uint32)Netc_Eth_Ip_apxState[ctrlIndex]->TxRingSize[ring];
            /* If the buffer descriptor is free */
            if (NextProducerIndex !=  Netc_Eth_Ip_apxState[ctrlIndex]->lastTxDataBuffAddrIdx[ring])
            {
                /* If the Length doesn't exceed the size of the descriptor, move to next buffer */
                if (Buffers[FreeBuffers].length <= (uint16)(Netc_Eth_Ip_apxState[ctrlIndex]->TxBufferLength[ring]))
                {
                    FreeBuffers++;
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
    }

    if (FreeBuffers == NumBuffers)
    {
        while (BufferIndex < NumBuffers)
        {
            Netc_Eth_Ip_apxState[ctrlIndex]->LockTxBuffDescr[ring][ProducerIndex] = TRUE;
            /* Save the address of the external buffer to be used in GetTransmitStatus for correctly identifying the descriptor. */
            Netc_Eth_Ip_apxState[ctrlIndex]->TxDataBuffAddr[ring][ProducerIndex] = Buffers[BufferIndex].data;

            txBD = (Netc_Eth_Ip_TxBDRType *)((uint32)(Netc_Eth_Ip_apxState[ctrlIndex]->FirstTxRingDescAddr[ring]) + (((uint32)(ProducerIndex / NETC_ETH_IP_PRODUCER_INCR)) * ((uint32)(sizeof(Netc_Eth_Ip_TxBDRType)))));
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
                    txBD->buffConfig |= (((uint32)NETC_ETH_IP_FLQ_VALUE << NETC_ETH_IP_FLQ_SHIFT) | \
                                         ((uint32)(options->IngrOrEgrPortNumber) << NETC_ETH_IP_INGR_EGRESS_PORT_SHIFT));
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
            CacheStatus = Cache_Ip_Clean(CacheType, CACHE_IP_DATA, TRUE);
            if (E_NOT_OK == CacheStatus)
            {
                Status = NETC_ETH_IP_STATUS_CACHE_ERROR;
            }
            else
            {
#endif
            /* Update the current value of the producer index. */
            Netc_Eth_Ip_apxState[ctrlIndex]->LogicTxProducerIndex[ring] = (uint16)ProducerIndex;
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
    uint32 NextProducerIndex;
#if (STD_ON == NETC_ETH_IP_HAS_CACHE_MANAGEMENT)
    Std_ReturnType CacheStatus = E_NOT_OK;
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
            /* When the development error is enabled we need to add a barrier first in order to avoid speculative
               exection before the previous else if condition is completed. */
            MCAL_INSTRUCTION_SYNC_BARRIER();
            MCAL_DATA_SYNC_BARRIER();
            Netc_Eth_Ip_apxState[ctrlIndex]->LockTxBuffDescr[ring][ProducerIndex] = TRUE;
#else
            /* When the development error is enabled we need to add a barrier first in order to avoid speculative
               exection before the previous else if condition is completed. */
            MCAL_INSTRUCTION_SYNC_BARRIER();
            MCAL_DATA_SYNC_BARRIER();
#endif /* NETC_ETH_IP_HAS_EXTERNAL_TX_BUFFERS */
            /* Save the address of the external buffer to be used in GetTransmitStatus for correctly identifying the descriptor. */
            Netc_Eth_Ip_apxState[ctrlIndex]->TxDataBuffAddr[ring][ProducerIndex] = buff->data;
            
            txBD = (Netc_Eth_Ip_TxBDRType *)((uint32)(Netc_Eth_Ip_apxState[ctrlIndex]->FirstTxRingDescAddr[ring]) + (uint32)((ProducerIndex / NETC_ETH_IP_PRODUCER_INCR) * ((uint32)(sizeof(Netc_Eth_Ip_TxBDRType)))));
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
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
#ifdef NETC_ETH_0_USED
                    /* Resetting the management frame flag here is OK as long as there is no chance of re-using the position in the array
                    before the message it points to is processed. This is indeed ensured by the ProvideTxBuffer function which needs to
                    successfully provide a buffer if the SetManagementInfo function, which sets the flag, is to be called. */
                    Netc_Eth_Ip_TxManagementInfoBuff[0U][ProducerIndex / NETC_ETH_IP_PRODUCER_INCR].ManagementFrameFlag = FALSE;
#endif
#endif
                    /* Set Flag(FL) type; set ingress or egress port value; set value of flag qualifier(FLQ). */
                    txBD->buffConfig |= ((((uint32)NETC_ETH_IP_FLQ_VALUE) << NETC_ETH_IP_FLQ_SHIFT) | \
                                         ((uint32)options->IngrOrEgrPortNumber << NETC_ETH_IP_INGR_EGRESS_PORT_SHIFT));
                    if(1U == options->SwtMgSendingOpt)
                    {
                        txBD->buffConfig |= ((uint32)options->SwtMgSendingOpt << NETC_ETH_IP_SMSO_SHIFT) | \
                                            ((uint32)options->TimestampRefReq << NETC_ETH_IP_TSR_SHIFT)  | \
                                            ((uint32)options->InternalPriority << NETC_ETH_IP_IPV_SHIFT)  | \
                                            ((uint32)options->DiscardResilience << NETC_ETH_IP_DR_SHIFT);
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
            CacheStatus = Cache_Ip_Clean(CacheType, CACHE_IP_DATA, TRUE);
            if (E_NOT_OK == CacheStatus)
            {
                Status = NETC_ETH_IP_STATUS_CACHE_ERROR;
            }
            else
            {
#endif
            /* Update the current value of the producer index. */
            Netc_Eth_Ip_apxState[ctrlIndex]->LogicTxProducerIndex[ring] = (uint16)NextProducerIndex;
            /* Write the producer index into register to start frame sending. */
            netcSIsBase[ctrlIndex]->BDR_NUM[ring].TBPIR = NextProducerIndex;

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
    uint32 ConsumerIndex;
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(Netc_Eth_Ip_apxState[ctrlIndex] != NULL_PTR);
    DevAssert(ring < Netc_Eth_Ip_apxState[ctrlIndex]->NumberOfTxBDR);
    DevAssert(buff != NULL_PTR);
#endif
    /* Read the consumer index */
    ConsumerIndex = netcSIsBase[ctrlIndex]->BDR_NUM[ring].TBCIR;

    status = Netc_Eth_Ip_CheckFrameStatus(ctrlIndex, ring, ConsumerIndex, buff->data, &(info->timestamp), &(info->txStatus));

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_ReleaseTxBuffers
 * implements     Netc_Eth_Ip_ReleaseTxBuffers_Activity
 *END**************************************************************************/
void Netc_Eth_Ip_ReleaseTxBuffers(const uint8 CtrlIdx, const uint8 Ring)
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
    SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_29();

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
    SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_29();

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
        uint16 PsiRspMessage;
        Status = Netc_Eth_Ip_VsiToPsiMsg(CtrlIndex, NETC_ETH_IP_VSITOPSI_MAC_ADDR_SET, MacAddr, &PsiRspMessage);
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
    tempRegValue = netcSIsBase[CtrlIndex]->SIPMAR0;
    MacAddr[0U] = (uint8)(tempRegValue & 0xFFU);
    MacAddr[1U] = (uint8)((tempRegValue >> 8U) & 0xFFU);
    MacAddr[2U] = (uint8)((tempRegValue >> 16U) & 0xFFU);
    MacAddr[3U] = (uint8)((tempRegValue >> 24U) & 0xFFU);

    /* Get from physical Address high register. */
    tempRegValue = netcSIsBase[CtrlIndex]->SIPMAR1;
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

/*!
 * @brief   : Function for accessing two 32 bits counters.
 * @details : Function for extracting the counter value using base/offset
 *
 * @param[in] baseAddressValue base address in uint32
 * @param[in] offsetAddressValue offset from the base
 *
 * @return Register value
 */
static inline uint64 Netc_Eth_Ip_Extract64bitsFrom32bitsReg(const uint32 baseAddressValue, const uint32 offsetAddressValue)
{
    uint32 lessSignificantPtrValue;
    const volatile uint32 *ptrToLessSignificantData;
    uint64 lessSignificantAddressData, mostSignificantAddressData;

    /* The most significant is higher in memory, the next address to get the next 32 bits */
    lessSignificantPtrValue = baseAddressValue + offsetAddressValue;

    /* Convert back the numbers in pointers */
    ptrToLessSignificantData = (volatile uint32 *) lessSignificantPtrValue;

    /* Note that there is only one higher value buffer, should be exclusive... semaphore, what about the other cores? High level problem to be aware of */
    lessSignificantAddressData = ptrToLessSignificantData[0U];
    mostSignificantAddressData = ptrToLessSignificantData[1U];

    /* putting it all together */
    return ((mostSignificantAddressData << NETC_ETH_IP_32BIT_SHIFT) | lessSignificantAddressData);
}

/*!
 * @brief   : Function for accessing two 32 bits counters in a table.
 * @details : Function for getting the two 32 bits counters using two 32 bits accesses.
 *
 * @param[in] Reg 32bits register pointer
 *
 * @return Register value
 */
static inline uint64 Netc_Eth_Ip_GetCounterLocal(const volatile uint32 *Reg)
{
    return Netc_Eth_Ip_Extract64bitsFrom32bitsReg((uint32) Reg, 0U);
}

/*!
 * @brief   : Function for initializing NTMP table.
 * @details : Function enables the netc controller, initializes the tables and then diasbles the netc controller
 *
 * @param[in] ctrlIndex controller index
 * @param[in] config controller configuration
 *
 */
static inline void Netc_Eth_Ip_InitNTMPTables(uint8 ctrlIndex, const Netc_Eth_Ip_ConfigType *config)
{
    Netc_Eth_Ip_StatusType Status;

    /* Tables initialization should be done after enabling the controller. Set the EN bit in Station interface mode register (SIMR) to enable psi0*/
    netcSIsBase[ctrlIndex]->SIMR |= NETC_F3_SI0_SIMR_EN_MASK;

    /* only for PSI0 */
    if (NETC_ETH_IP_PHYSICAL_SI == Netc_Eth_Ip_apxState[ctrlIndex]->SiType)
    {
        /* Init Time Gate Scheduling Table*/
        /* check if TAS is enabled or not on PSI0*/
        Netc_Eth_Ip_PortTimeAwareShaperEnabled = (*config->generalConfig).portTimeAwareShaperEnable;

        if (TRUE ==  Netc_Eth_Ip_PortTimeAwareShaperEnabled)
        {
#if defined(ERR_IPV_NETC_E051130)
    #if (STD_ON == ERR_IPV_NETC_E051130)
            /* Default time gate scheduling conditions on the pseudo port */
            Status = Netc_Eth_Ip_InitTimeGateSchedulingFeature(ctrlIndex);
            if (Status == NETC_ETH_IP_STATUS_SUCCESS)
            {
    #endif
#endif
                /* Add time gate scheduling table entries data */
                Netc_Eth_Ip_InitTimeGateSchedulingTableEntryData(config);
#if defined(ERR_IPV_NETC_E051130)
    #if (STD_ON == ERR_IPV_NETC_E051130)
            }
    #endif
#endif
        }

        /* Init Vlan Filter Table*/
        #if (NETC_ETH_IP_NUMBER_OF_VLAN_FILTER_ENTRIES > 0U)
        Netc_Eth_Ip_ConfigVLANFilterTable(ctrlIndex, config);
        #endif
    }

    /* Init Receive Flow Steering Table */
    (void)Netc_Eth_Ip_ConfigRfsTable(ctrlIndex, config);

    /* After table initializatios the controller should be disabled. Clear the EN bit in Station interface mode register (SIMR) to disalbe psi0 */
    netcSIsBase[ctrlIndex]->SIMR &= ~NETC_F3_SI0_SIMR_EN_MASK;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_GetCounter64
 * implements     Netc_Eth_Ip_GetCounter64_Activity
 *END**************************************************************************/
uint64 Netc_Eth_Ip_GetCounter64(uint8 CtrlIndex, Netc_Eth_Ip_CounterType Counter)
{
    uint64 CounterValue;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
#endif

    CounterValue = Netc_Eth_Ip_GetCounterLocal((volatile uint32 *)((uint32)netcSIsBase[CtrlIndex] + (uint32)Counter));

    return CounterValue;
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
    uint32 CurrLowTime = 0U;
    uint32 CurrHighTime = 0U;
#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
#ifdef NETC_ETH_0_USED
    Netc_Eth_Ip_TimeType LatestTxTimestamp = { 0U, 0U};
    const Netc_Eth_Ip_TxTimestampResponseType *TempTxResponse;
    uint16 TxTimestampID;
#endif /* NETC_ETH_0_USED */
#else /* STD_ON == NETC_ETH_IP_EXTENDED_BUFF */
    (void)CurrLowTime;
    (void)CurrHighTime;
#endif /* STD_ON == NETC_ETH_IP_EXTENDED_BUFF */
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;
    uint32 rxIndex = 0;
    uint32 HostReason;
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

        /* Store information about received frame. */
        if (NULL_PTR != info)
        {
            info->L4cksum = ((rxBDR->configRxBD[3U] & NETC_ETH_IP_RXBD_L4_FLAG_MASK) > 0U) ? TRUE : FALSE;
            info->L3cksum = ((rxBDR->configRxBD[3U] & NETC_ETH_IP_RXBD_L3_FLAG_MASK) > 0U) ? TRUE : FALSE;
            info->finalDes = ((rxBDR->configRxBD[3U] & NETC_ETH_IP_RXBD_FINAL_MASK)  > 0U) ? TRUE : FALSE;
            info->timestampReceived = ((rxBDR->configRxBD[3U] & NETC_ETH_IP_RXBD_TIMESTAMP_FLAG_MASK) > 0U) ? TRUE : FALSE;
            info->vlanHeaderAvl = ((rxBDR->configRxBD[3U] & NETC_ETH_IP_RXBD_VLAN_HEAD_FLAG_MASK) > 0U) ? TRUE : FALSE;
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
            /* Read the low register then immediately the high register to get a synchronised 64-bit time value in nanoseconds */
            CurrLowTime = netcSIsBase[0U]->SICTR0;
            CurrHighTime = netcSIsBase[0U]->SICTR1;
#endif
        }

        if (NETC_ETH_RX_NO_RECEIVE_ERR == (Netc_Eth_Ip_RxStatusType)((rxBDR->configRxBD[3U] & NETC_ETH_IP_RXBD_ERROR_MASK) >> 16U))
        {
            HostReason = ((rxBDR->configRxBD[3U] >> NETC_ETH_IP_HOSTREASON_WB_SHIFT) & NETC_ETH_IP_HOSTREASON_WB_MASK);

            if ((NETC_ETH_IP_HOSTREASON_REGULAR_FRAME == HostReason) || (NETC_ETH_IP_HOSTREASON_SW_PTP == HostReason))
            {

#if (STD_ON == NETC_ETH_IP_HAS_CACHE_MANAGEMENT)
                /* Mark the cache lines as invalid in order to get the new data from data buffers from memory. */
                CacheStatus = Cache_Ip_Invalidate(CacheType, CACHE_IP_DATA);
                if (E_NOT_OK == CacheStatus)
                {
                    status = NETC_ETH_IP_STATUS_CACHE_ERROR;
                }
                else
                {
#endif
#if (NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS == STD_ON)
                    if (!Netc_Eth_Ip_ControllerHasExternalRxBufferManagement[ctrlIndex])
                    {
#endif
                        /* All conditions meet, return buffer data details. */
                        buff->data = (uint8 *)((uint32)(Netc_Eth_Ip_apxState[ctrlIndex]->FirstRxDataBufferAddr[ring]) + \
                                    (rxIndex * Netc_Eth_Ip_apxState[ctrlIndex]->RxDataBuffMaxLenAddr[ring]));
#if (NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS == STD_ON)
                    }
                    else
                    {
                        buff->data = (uint8*)Netc_Eth_Ip_apxState[ctrlIndex]->RxDataBuffAddr[bufferIndex];
                    }
#endif
                    buff->length = (uint16)(rxBDR->configRxBD[2U] & NETC_ETH_IP_RXBD_LENGTH_MASK);


#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
                    if(CurrLowTime < rxBDR->extendConfigRxBD[0U])
                    {
                        CurrHighTime--;
                    }
                    if (NULL_PTR != info)
                    {
                        info->PacketTimestamp = (uint64)(rxBDR->extendConfigRxBD[0U]) | (uint64)(((uint64)(CurrHighTime)) << 32U);
                    }

                    if (NETC_ETH_IP_HOSTREASON_SW_PTP == HostReason)
                    {
                        /* When the development error is enabled we need to add a barrier first in order to avoid speculative
                        exection before the previous else if condition is completed. */
                        MCAL_INSTRUCTION_SYNC_BARRIER();
                        MCAL_DATA_SYNC_BARRIER();
                        Netc_Eth_Ip_RxTimestampInfoBuff[ctrlIndex][ring][rxIndex].RingIdx = ring;
                        Netc_Eth_Ip_RxTimestampInfoBuff[ctrlIndex][ring][rxIndex].ReceivedDataPtr = buff->data;
                        Netc_Eth_Ip_RxTimestampInfoBuff[ctrlIndex][ring][rxIndex].SourcePort = (uint8)(rxBDR->configRxBD[1U] & NETC_ETH_IP_RXBD_SRC_PORT_MASK);

                        Netc_Eth_Ip_RxTimestampInfoBuff[ctrlIndex][ring][rxIndex].TimestampValue.nanosecondsL = rxBDR->extendConfigRxBD[0U];
                        Netc_Eth_Ip_RxTimestampInfoBuff[ctrlIndex][ring][rxIndex].TimestampValue.nanosecondsH = CurrHighTime;

                        SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_20();
                        Netc_Eth_Ip_RxTimestampID = (Netc_Eth_Ip_RxTimestampID % (uint32)0xFFFFU) + (uint32)1U;
                        Netc_Eth_Ip_RxTimestampInfoBuff[ctrlIndex][ring][rxIndex].TimestampID = Netc_Eth_Ip_RxTimestampID;
                        Netc_Eth_Ip_RxTimestampInfoBuff[ctrlIndex][ring][rxIndex].TimestampValueInvalidForSwt = (boolean)FALSE;
                        SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_20();

                    }
#endif

#if (STD_ON == NETC_ETH_IP_HAS_CACHE_MANAGEMENT)
                }
#endif /* STD_ON == NETC_ETH_IP_EXTENDED_BUFF */
            }

#if (STD_ON == NETC_ETH_IP_EXTENDED_BUFF)
#ifdef NETC_ETH_0_USED
            else if(NETC_ETH_IP_HOSTREASON_TIMESTAMP == HostReason)
            {
                if((0U == ctrlIndex) && (0U == ring))
                {
                    TempTxResponse = (Netc_Eth_Ip_TxTimestampResponseType *)Netc_Eth_Ip_apxState[ctrlIndex]->RxCurrentDesc[ring];
                    TxTimestampID = TempTxResponse->TxTimestampID;

                    LatestTxTimestamp.nanosecondsL = TempTxResponse->Timestamp;
                    LatestTxTimestamp.nanosecondsH = CurrHighTime;
                    if(CurrLowTime < LatestTxTimestamp.nanosecondsL)
                    {
                        LatestTxTimestamp.nanosecondsH--;
                    }

                    Netc_Eth_Ip_TxTimestampInfoBuff[ctrlIndex][TxTimestampInfoBuffIdx].TimestampValue.nanosecondsL = LatestTxTimestamp.nanosecondsL;
                    Netc_Eth_Ip_TxTimestampInfoBuff[ctrlIndex][TxTimestampInfoBuffIdx].TimestampValue.nanosecondsH =  LatestTxTimestamp.nanosecondsH;
                    Netc_Eth_Ip_TxTimestampInfoBuff[ctrlIndex][TxTimestampInfoBuffIdx].TxTimeStampID = TxTimestampID;
                    TxTimestampInfoBuffIdx++;
                    TxTimestampInfoBuffIdx = (NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR == TxTimestampInfoBuffIdx) ? 0U : TxTimestampInfoBuffIdx;

                    status = NETC_ETH_IP_STATUS_HOSTREASON_TIMESTAMP;
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

        SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_20();
        /* Go to the next index. */
        Netc_Eth_Ip_apxState[ctrlIndex]->rxCurrentIndex[ring] = (Netc_Eth_Ip_apxState[ctrlIndex]->rxCurrentIndex[ring] + 1U) % \
                                                                 Netc_Eth_Ip_apxState[ctrlIndex]->RxRingSize[ring];

        /* Increment the pointer to the current descriptor. */
        Netc_Eth_Ip_apxState[ctrlIndex]->RxCurrentDesc[ring] = (Netc_Eth_Ip_RxBDRType *)((uint32)(Netc_Eth_Ip_apxState[ctrlIndex]->FirstRxRingDescAddr[ring]) + \
                                                               (((uint32)Netc_Eth_Ip_apxState[ctrlIndex]->rxCurrentIndex[ring])  * ((uint32)(sizeof(Netc_Eth_Ip_RxBDRType)))));
        SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_20();

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
    RxBDR = (Netc_Eth_Ip_RxBDRType *)((uint32)Netc_Eth_Ip_apxState[ctrlIndex]->FirstRxRingDescAddr[ring] + (((uint32)CurrentConsumerIndex) * ((uint32)(sizeof(Netc_Eth_Ip_RxBDRType)))));

    /* Configure descriptor by setting the address of data buffer and clear the rest of it. */
#if (STD_ON == NETC_ETH_IP_HAS_EXTERNAL_RX_BUFFERS)
    bufferIndex = ring * FEATURE_NETC_RX_BDR_COUNT + CurrentConsumerIndex;

    /* In case the current controller has Internal Buffer Management for reception, restore the data buffer */
    if (!Netc_Eth_Ip_ControllerHasExternalRxBufferManagement[ctrlIndex])
    {
#endif
        RxBDR->configRxBD[0U] = ((uint32)Netc_Eth_Ip_apxState[ctrlIndex]->FirstRxDataBufferAddr[ring] + \
                             (uint32)(CurrentConsumerIndex * Netc_Eth_Ip_apxState[ctrlIndex]->RxDataBuffMaxLenAddr[ring]));
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
    SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_28();
    /* Update consumer index. */
    Netc_Eth_Ip_apxState[ctrlIndex]->LogicRxConsumerIndex[ring] = (CurrentConsumerIndex + 1U) % \
                                                                  Netc_Eth_Ip_apxState[ctrlIndex]->RxRingSize[ring];
    netcSIsBase[ctrlIndex]->BDR_NUM[ring].RBCIR = (uint32)(Netc_Eth_Ip_apxState[ctrlIndex]->LogicRxConsumerIndex[ring]);
    SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_28();


    return NETC_ETH_IP_STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_ProvideMultipleRxBuff
 * implements     Netc_Eth_Ip_ProvideMultipleRxBuff_Activity
 *END**************************************************************************/
void Netc_Eth_Ip_ProvideMultipleRxBuff(const uint8 CtrlIndex,
                                                         const uint8 Ring,
                                                         uint8* BuffList[],
                                                         uint16* BuffListSize)
{
    uint16 ConsumerIndex = 0U;
    uint16 LastRxConsumerRead = 0U;
    volatile Netc_Eth_Ip_RxBDRType *RxBDR;
    uint16 BuffListIndex = 0U;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    /* When the development error is enabled we need to add a barrier first in order to avoid speculative
        exection before the previous else if condition is completed. */
    MCAL_INSTRUCTION_SYNC_BARRIER();
    MCAL_DATA_SYNC_BARRIER();
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

    ConsumerIndex = Netc_Eth_Ip_apxState[CtrlIndex]->LogicRxConsumerIndex[Ring];
    LastRxConsumerRead = Netc_Eth_Ip_apxState[CtrlIndex]->rxCurrentIndex[Ring];
    do
    {
        RxBDR = (Netc_Eth_Ip_RxBDRType *)((uint32)(Netc_Eth_Ip_apxState[CtrlIndex]->FirstRxRingDescAddr[Ring]) + ((uint32)ConsumerIndex * ((uint32)(sizeof(Netc_Eth_Ip_RxBDRType)))));

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
    
    /* When the development error is enabled we need to add a barrier first in order to avoid speculative
        exection before the previous else if condition is completed. */
    MCAL_INSTRUCTION_SYNC_BARRIER();
    MCAL_DATA_SYNC_BARRIER();
    Netc_Eth_Ip_apxState[CtrlIndex]->LogicRxConsumerIndex[Ring] = (uint16)ConsumerIndex;
    netcSIsBase[CtrlIndex]->BDR_NUM[Ring].RBCIR = ConsumerIndex;
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
Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddMulticastDstAddrToHashFilter(const uint8 CtrlIndex, \
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
                SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_09();
                IP_NETC__ENETC0_BASE->NUM_SI[CtrlIndex].PSIMMHFR1 |= (uint32)(1U << (HashValue & NETC_ETH_IP_HASH_VALUE));
                SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_09();

            }
            else
            {
                SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_09();
                IP_NETC__ENETC0_BASE->NUM_SI[CtrlIndex].PSIMMHFR0 |= (uint32)(1U << (HashValue & NETC_ETH_IP_HASH_VALUE));
                SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_09();

            }
        }
    }
    else
    {
        uint16 PsiRspMessage;
        Status = Netc_Eth_Ip_VsiToPsiMsg(CtrlIndex, NETC_ETH_IP_VSITOPSI_ADD_RX_MAC_ADDR_FILTER, MacAddr, &PsiRspMessage);
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_RemoveMulticastDstAddrFromHashFilter
 * implements     Netc_Eth_Ip_RemoveMulticastDstAddrFromHashFilter_Activity
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_RemoveMulticastDstAddrFromHashFilter(const uint8 CtrlIndex, \
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

        if(NETC_ETH_IP_STATUS_DELETE_MAC_ADDR == Status)
        {
            /* 64 entries in table, the 5th bit of the HashValue selects between registers used. */
            if((HashValue & NETC_ETH_IP_SELECT_HASH_REGISTER) != (uint8)0U)
            {
                SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_10();
                IP_NETC__ENETC0_BASE->NUM_SI[CtrlIndex].PSIMMHFR1 &= ~(uint32)(1U << ((uint32)HashValue & NETC_ETH_IP_HASH_VALUE));
                SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_10();

            }
            else
            {
                SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_10();
                IP_NETC__ENETC0_BASE->NUM_SI[CtrlIndex].PSIMMHFR0 &= ~(uint32)(1U << ((uint32)HashValue & NETC_ETH_IP_HASH_VALUE));
                SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_10();
            }

            /*Mark the status variable as STATUS_SUCCESS, after hash deletion, since IPW expects it */
            Status = NETC_ETH_IP_STATUS_SUCCESS;
        }
    }
    else
    {
        uint16 PsiRspMessage;
        Status = Netc_Eth_Ip_VsiToPsiMsg(CtrlIndex, NETC_ETH_IP_VSITOPSI_DELETE_RX_MAC_ADDR_FILTER, MacAddr, &PsiRspMessage);
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_SetMulticastForwardAll
 * implements     Netc_Eth_Ip_SetMulticastForwardAll_Activity
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_SetMulticastForwardAll(const uint8 CtrlIndex, const boolean EnableMulticast)
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
            SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_11();
            /* Enable MAC multicast promiscuous mode. */
            IP_NETC__ENETC0_BASE->PSIPMMR |= ((uint32)1U << (CtrlIndex + NETC_F3_PSIPMMR_SI0_MAC_MP_SHIFT));
            SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_11();
        }
        else
        {
            SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_11();
            /* Disable MAC multicast promiscuous mode. */
            IP_NETC__ENETC0_BASE->PSIPMMR &= ~((uint32)1U << (CtrlIndex + NETC_F3_PSIPMMR_SI0_MAC_MP_SHIFT));
            SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_11();
        }
    }
    else
    {
        uint16 PsiRspMessage;
        if(EnableMulticast)
        {
            /* Enable MAC multicast promiscuous mode. */
            Status = Netc_Eth_Ip_VsiToPsiMsg(CtrlIndex, NETC_ETH_IP_VSITOPSI_ENABLE_MULTICAST, NULL_PTR, &PsiRspMessage);
        }
        else
        {
            /* Disable MAC multicast promiscuous mode. */
            Status = Netc_Eth_Ip_VsiToPsiMsg(CtrlIndex, NETC_ETH_IP_VSITOPSI_DISABLE_MULTICAST, NULL_PTR, &PsiRspMessage);
        }
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_CloseMulticastReceiving
 * implements     Netc_Eth_Ip_CloseMulticastReceiving_Activity
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_CloseMulticastReceiving(const uint8 CtrlIndex)
{
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_SUCCESS;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(NULL_PTR != Netc_Eth_Ip_apxState[CtrlIndex]);
#endif

    if (NETC_ETH_IP_PHYSICAL_SI == Netc_Eth_Ip_apxState[CtrlIndex]->SiType)
    {           
        SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_12();
        /* Disable MAC multicast promiscuous mode. */
        IP_NETC__ENETC0_BASE->PSIPMMR &= ~((uint32)1U << (CtrlIndex + NETC_F3_PSIPMMR_SI0_MAC_MP_SHIFT));

        IP_NETC__ENETC0_BASE->NUM_SI[CtrlIndex].PSIMMHFR1 = 0x0U;
        IP_NETC__ENETC0_BASE->NUM_SI[CtrlIndex].PSIMMHFR0 = 0x0U;


        SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_12();

    }
    else
    {
        uint16 PsiRspMessage;
        /* Disable MAC multicast promiscuous mode. */
        Status = Netc_Eth_Ip_VsiToPsiMsg(CtrlIndex, NETC_ETH_IP_VSITOPSI_CLOSE_FILTER, NULL_PTR, &PsiRspMessage);
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
        if (PacketsThreshold < Netc_Eth_Ip_apxState[CtrlIdx]->TxRingSize[RingIdx])
        {
            SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_05();
            /* First disable the Coalescing ISR AND clear the previous values. */
            netcSIsBase[CtrlIdx]->BDR_NUM[RingIdx].TBICR0 &= ~NETC_F3_SI0_TBICR0_ICEN_MASK;
            netcSIsBase[CtrlIdx]->BDR_NUM[RingIdx].TBICR1 = 0U; /* &= ~NETC_F3_SI0_TBICR1_ICTT_MASK; */
            netcSIsBase[CtrlIdx]->BDR_NUM[RingIdx].TBICR0 &= ~NETC_F3_SI0_TBICR0_ICPT_MASK;

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
            if ((PacketsThreshold == 0U) && (TimerThreshold != 0U))
            {
                netcSIsBase[CtrlIdx]->BDR_NUM[RingIdx].TBICR0 |= NETC_F3_SI0_TBICR0_ICEN_MASK;
            }
            SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_05();

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
            SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_04();
            /* First disable the Coalescing ISR AND clear the previous values. */
            netcSIsBase[CtrlIdx]->BDR_NUM[RingIdx].RBICR0 &= ~NETC_F3_SI0_RBICR0_ICEN_MASK;
            netcSIsBase[CtrlIdx]->BDR_NUM[RingIdx].RBICR1 = 0U; /* &= ~NETC_F3_SI0_RBICR1_ICTT_MASK; Changed due to CWE violation*/
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
             SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_04();

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
Netc_Eth_Ip_StatusType Netc_Eth_Ip_ManagementFrame(const uint8 CtrlIdx, uint16 BuffIdx, uint8 SwitchIndex, uint8 PortIndex, boolean Enable)
{
    uint16 CurrentIndex;
    Netc_Eth_Ip_StatusType Status;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIdx < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
#endif

    if (NETC_ETH_IP_PHYSICAL_SI == Netc_Eth_Ip_apxState[CtrlIdx]->SiType)
    {
        CurrentIndex = Netc_Eth_Ip_apxState[CtrlIdx]->LogicTxProducerIndex[0U];

        Netc_Eth_Ip_TxManagementInfoBuff[0U][CurrentIndex / (uint16)NETC_ETH_IP_PRODUCER_INCR].CtrlIdx = CtrlIdx;
        Netc_Eth_Ip_TxManagementInfoBuff[0U][CurrentIndex / (uint16)NETC_ETH_IP_PRODUCER_INCR].TxBuffId = BuffIdx;
        Netc_Eth_Ip_TxManagementInfoBuff[0U][CurrentIndex / (uint16)NETC_ETH_IP_PRODUCER_INCR].SwitchIndex = SwitchIndex;
        Netc_Eth_Ip_TxManagementInfoBuff[0U][CurrentIndex / (uint16)NETC_ETH_IP_PRODUCER_INCR].PortIndex = PortIndex;
        Netc_Eth_Ip_TxManagementInfoBuff[0U][CurrentIndex / (uint16)NETC_ETH_IP_PRODUCER_INCR].ManagementFrameFlag = Enable;
        Netc_Eth_Ip_TxManagementInfoBuff[0U][CurrentIndex / (uint16)NETC_ETH_IP_PRODUCER_INCR].TxTimestampFlag = FALSE;
        Netc_Eth_Ip_TxManagementInfoBuff[0U][CurrentIndex / (uint16)NETC_ETH_IP_PRODUCER_INCR].TxTimestampRcvFlag = FALSE;

        Status = NETC_ETH_IP_STATUS_SUCCESS;
    }
    else
    {
        Status = NETC_ETH_IP_STATUS_UNSUPPORTED;
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_TimestampTxFrame
 * implements     Netc_Eth_Ip_TimestampTxFrame_Activity
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_TimestampTxFrame(const uint8 CtrlIdx, const uint16 BuffIdx, const boolean Enable)
{
    uint16 CurrentIndex;
    volatile Netc_Eth_Ip_TxManagementInfoType *TxMgmtInfo;
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_ERROR;
    if (NETC_ETH_IP_PHYSICAL_SI == Netc_Eth_Ip_apxState[CtrlIdx]->SiType)
    {
        CurrentIndex = Netc_Eth_Ip_apxState[CtrlIdx]->LogicTxProducerIndex[0U];
        TxMgmtInfo = &Netc_Eth_Ip_TxManagementInfoBuff[0U][CurrentIndex / (uint16)NETC_ETH_IP_PRODUCER_INCR];

        if (TxMgmtInfo->TxBuffId == BuffIdx)
        {
            if ((TxMgmtInfo->ManagementFrameFlag == TRUE))
            {
                TxMgmtInfo->TxTimestampFlag = Enable;
                Status = NETC_ETH_IP_STATUS_SUCCESS;
            }
        }
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_GetTxTimestampInfo
 * implements     Netc_Eth_Ip_GetTxTimestampInfo_Activity
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetTxTimestampInfo(const uint8 CtrlIdx, \
                                                      const uint32 BuffIdx, \
                                                      Netc_Eth_Ip_TxManagementInfoType **MgmtInfo, Netc_Eth_Ip_TxTimestampInfoType **TimestampInfo)
{
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_ERROR;
    uint32 BufferIdx;
    uint16 LatestTimestampID;
    boolean FirstTimestampFlag = FALSE;
    uint32 TsBufferIdx;
    *MgmtInfo = NULL_PTR;
    *TimestampInfo = NULL_PTR;
    uint16 tempBufferIdx;
    uint8 tempCtrlIdx;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIdx < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
#endif

    /* Search for timestamps associated to the frame with BuffIdx */
    for(BufferIdx = 0U; BufferIdx < NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR; BufferIdx++)
    {
        SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_23();
        tempBufferIdx = Netc_Eth_Ip_TxManagementInfoBuff[0u][BufferIdx].TxBuffId;
        tempCtrlIdx = Netc_Eth_Ip_TxManagementInfoBuff[0u][BufferIdx].CtrlIdx;
        if ((BuffIdx == (uint32)tempBufferIdx) && (CtrlIdx == (uint32)tempCtrlIdx))
        {
            if (Netc_Eth_Ip_TxManagementInfoBuff[0u][BufferIdx].TxTimestampFlag == (boolean)TRUE)
            {
                if (Netc_Eth_Ip_TxManagementInfoBuff[0u][BufferIdx].TxTimestampRcvFlag == (boolean)FALSE)
                {
                    /* Mark the first matching timestamp found */
                    if(FALSE == FirstTimestampFlag)
                    {
                        LatestTimestampID = Netc_Eth_Ip_TxManagementInfoBuff[0u][BufferIdx].TxTimeStampID;
                        FirstTimestampFlag = TRUE;
                        *MgmtInfo =  (Netc_Eth_Ip_TxManagementInfoType *)&Netc_Eth_Ip_TxManagementInfoBuff[0u][BufferIdx];
                        Status = NETC_ETH_IP_STATUS_SUCCESS;
                    }
                    else
                    {
                        /* Update to keep track only of the latest timestamp info found */
                        if(Netc_Eth_Ip_TxManagementInfoBuff[0u][BufferIdx].TxTimeStampID > LatestTimestampID)
                        {
                            LatestTimestampID = Netc_Eth_Ip_TxManagementInfoBuff[0u][BufferIdx].TxTimeStampID;
                            *MgmtInfo =  (Netc_Eth_Ip_TxManagementInfoType *)&Netc_Eth_Ip_TxManagementInfoBuff[0u][BufferIdx];
                            *TimestampInfo = NULL_PTR;
                        }
                    }
                    for (TsBufferIdx = 0U; TsBufferIdx < NETC_ETH_0_TXBDR_0_MAX_NUM_OF_DESCR; TsBufferIdx++)
                    {
                        if (Netc_Eth_Ip_TxTimestampInfoBuff[0u][TsBufferIdx].TxTimeStampID == Netc_Eth_Ip_TxManagementInfoBuff[0u][BufferIdx].TxTimeStampID)
                        {
                            Netc_Eth_Ip_TxManagementInfoBuff[0u][BufferIdx].TxTimestampRcvFlag = TRUE;
                            *TimestampInfo = (Netc_Eth_Ip_TxTimestampInfoType *)&Netc_Eth_Ip_TxTimestampInfoBuff[0u][TsBufferIdx];
                            break;
                        }
                    }
                }
            }
        }
        SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_23();
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_ReleaseUnusedTxBuff
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
    
    /* When the development error is enabled we need to add a barrier first in order to avoid speculative
        exection before the previous else if condition is completed. */
    MCAL_INSTRUCTION_SYNC_BARRIER();
    MCAL_DATA_SYNC_BARRIER();
    Netc_Eth_Ip_apxState[CtrlIndex]->LockTxBuffDescr[Ring][CurrentProducerIdx] = FALSE;
}
#endif /* NETC_ETH_0_USED */

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_GetRxTimestampInfo
 * implements     Netc_Eth_Ip_GetRxTimestampInfo_Activity
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetRxTimestampInfo(const uint8 CtrlIdx, const uint8 *DataPtr, Netc_Eth_Ip_RxTimestampInfoType **RxTimestampInfo)
{
    uint8 RingCounter;
    uint32 DescrCounter;
    uint32 LastRxTimestampID = (uint32)0U;
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_ERROR;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIdx < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(DataPtr != NULL_PTR);
#endif

    *RxTimestampInfo = NULL_PTR;

    SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_24();
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
                            *RxTimestampInfo = (Netc_Eth_Ip_RxTimestampInfoType *)&Netc_Eth_Ip_RxTimestampInfoBuff[CtrlIdx][RingCounter][DescrCounter];
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
    SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_24();

    return Status;
}

#endif /* STD_ON == NETC_ETH_IP_EXTENDED_BUFF */

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_GetSysTime
 * implements      Netc_Eth_Ip_GetSysTime_Activity
 *END**************************************************************************/
void Netc_Eth_Ip_GetSysTime(uint8 ctrlIndex, Netc_Eth_Ip_TimeType *TimePtr)
{

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != Netc_Eth_Ip_apxState[ctrlIndex]);
    DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(NULL_PTR != TimePtr );
#endif

    Netc_Eth_Ip_GetCurrentTick(ctrlIndex, TimePtr);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_Deinit
 * implements     Netc_Eth_Ip_Deinit_Activity
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_Deinit(uint8 ctrlIndex)
{
    #if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
        DevAssert(ctrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    #endif

    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    Netc_Eth_Ip_StatusType Status = NETC_ETH_IP_STATUS_ERROR;

    /*Check if the controller is VSI. Deinit is not supported for PSI*/
    if (NETC_ETH_IP_VIRTUAL_SI == Netc_Eth_Ip_apxState[ctrlIndex]->SiType)
    {
        /*Initiate function level reset*/
        netcVFBase[ctrlIndex]->PCI_CFC_PCIE_DEV_CTL = NETC_F1_PCI_HDR_TYPE0_PCI_CFC_PCIE_DEV_CTL_INIT_FLR(1U);

        /* Wait until VSI FLR is complete */
        Netc_Eth_Ip_StartTimeOut(&StartTime, &ElapsedTime, &TimeoutTicks, NETC_ETH_IP_TIMEOUT_VALUE_US);
        do
        {
            if (NETC_F1_PCI_HDR_TYPE0_PCI_CFC_PCIE_DEV_CTL_INIT_FLR(0U) == netcVFBase[ctrlIndex]->PCI_CFC_PCIE_DEV_CTL)
            {
                Status = NETC_ETH_IP_STATUS_SUCCESS;
                break;
            }
            else
            {
                Status = NETC_ETH_IP_STATUS_TIMEOUT;
            }
        }while(!Netc_Eth_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

        /* Reset global state variable */
        Netc_Eth_Ip_apxState[ctrlIndex] = NULL_PTR;
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_PCIe_AER_Handler
 *
 *END**************************************************************************/
void Netc_Eth_Ip_PCIe_AER_Handler(uint8 ctrlIndex)
{
    uint8 i = 0U;
    uint8 relativeIndex = 0U;

    /* Error reporting for TIMER EMDIO SWITCH ENETC */
    for( i = 0U; i < FEATURE_NETC_NUMBER_OF_FUNC; i++)
    {
        Netc_Eth_Ip_ErrorStatus[i].StatusErrors = 0u;
        /* Error bit status check */
        if ((netcPCIePFBase[i]->PCIE_CFC_AER_UCORR_ERR_STAT & NETC_ETH_IP_UCORR_STATUS_BIT) != (uint32)0U)
        {
            /* Interrupt enable bit check
            Un-masked interrupts are marked as 0*/
            if ((netcPCIePFBase[i]->PCIE_CFC_AER_UCORR_ERR_MASK & ((uint32)1U << NETC_ETH_IP_UCORR_ERR_MASK_SHIFT)) == (uint32)0U)
            {
                /* Clean error status bit */
                netcPCIePFBase[i]->PCIE_CFC_AER_UCORR_ERR_STAT = (uint32)NETC_ETH_IP_UCORR_STATUS_BIT;
                /* Report error in case this feature is enabled in configuration */
                if (Netc_Eth_Ip_apxState[ctrlIndex]->PcieAerUncorrectableErrEnabled)
                {
                    /*If the reg bit is 0 - Error is Non-fatal else is Fatal*/
                    if((netcPCIePFBase[i]->PCIE_CFC_AER_UCORR_ERR_SEV & NETC_ETH_IP_UCORR_SEV_MASK) != 0U)
                    {
                        Netc_Eth_Ip_ErrorStatus[i].StatusErrors = NETC_ETH_IP_FATAL_ERROR;
                    }
                    else
                    {
                        Netc_Eth_Ip_ErrorStatus[i].StatusErrors = NETC_ETH_IP_NON_FATAL_ERROR;
                    }
                }

            }
        }
        if ((netcPCIePFBase[i]->PCIE_CFC_AER_CORR_ERR_STAT & NETC_ETH_IP_CORR_STATUS_BIT) != (uint32)0U)
        {
            /* Un-masked interrupts are marked as 0*/
            if ((netcPCIePFBase[i]->PCIE_CFC_AER_CORR_ERR_MASK & ((uint32)1U << NETC_ETH_IP_CORR_ERR_MASK_SHIFT)) == (uint32)0U)
            {
                 netcPCIePFBase[i]->PCIE_CFC_AER_CORR_ERR_STAT = NETC_ETH_IP_CORR_STATUS_BIT;
                if (Netc_Eth_Ip_apxState[ctrlIndex]->PcieAerCorrectableErrEnabled)
                {
                    SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_27();
                    Netc_Eth_Ip_ErrorStatus[i].StatusErrors |= NETC_ETH_IP_CORRECTABLE_ERROR;
                    SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_27();

                }
            }
        }
    }

    /* Error reporting for VSIx */
    for (i = FEATURE_NETC_NUMBER_OF_FUNC + 1U; i < (FEATURE_NETC_ETH_NUM_OF_VIRTUAL_CTRLS + FEATURE_NETC_NUMBER_OF_FUNC + 1U); i++)
    {
        Netc_Eth_Ip_ErrorStatus[i].StatusErrors = 0u;

        /* netcVFBase has the index 0 null since virtual station interfaces start from 1*/
        relativeIndex = i - FEATURE_NETC_NUMBER_OF_FUNC;

        if ((netcVFBase[relativeIndex]->PCIE_CFC_AER_UCORR_ERR_STAT & NETC_ETH_IP_UCORR_STATUS_BIT) != (uint32)0U)
        {
            /* Un-masked interrupts are marked as 0*/
            if ((netcVFBase[relativeIndex]->PCIE_CFC_AER_UCORR_ERR_MASK & ((uint32)1U << NETC_ETH_IP_UCORR_ERR_MASK_SHIFT)) == (uint32)0U)
            {

                netcVFBase[relativeIndex]->PCIE_CFC_AER_UCORR_ERR_STAT = NETC_ETH_IP_UCORR_STATUS_BIT;
                /*If the reg bit is 0 - Error is Non-fatal else is Fatal*/
                if((netcVFBase[relativeIndex]->PCIE_CFC_AER_UCORR_ERR_SEV & NETC_ETH_IP_UCORR_SEV_MASK) != 0U)
                {
                    if (Netc_Eth_Ip_apxState[ctrlIndex]->PcieAerUncorrectableErrEnabled)
                    {                
                        Netc_Eth_Ip_ErrorStatus[i].StatusErrors = NETC_ETH_IP_FATAL_ERROR;

                    }
                }
                else
                {
                    if (Netc_Eth_Ip_apxState[ctrlIndex]->PcieAerUncorrectableErrEnabled)
                    {
                        Netc_Eth_Ip_ErrorStatus[i].StatusErrors |= NETC_ETH_IP_NON_FATAL_ERROR;

                    }
                }

            }
        }
        if ((netcVFBase[relativeIndex]->PCIE_CFC_AER_CORR_ERR_STAT & NETC_ETH_IP_CORR_STATUS_BIT) != (uint32)0U)
        {
            /* Un-masked interrupts are marked as 0*/
            if ((netcVFBase[relativeIndex]->PCIE_CFC_AER_UCORR_ERR_MASK & ((uint32)1U << NETC_ETH_IP_CORR_ERR_MASK_SHIFT)) != (uint32)0U)
            {
                netcVFBase[relativeIndex]->PCIE_CFC_AER_CORR_ERR_STAT = NETC_ETH_IP_CORR_STATUS_BIT;
                if (Netc_Eth_Ip_apxState[ctrlIndex]->PcieAerCorrectableErrEnabled)
                {
                    SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_27();
                    Netc_Eth_Ip_ErrorStatus[i].StatusErrors |= NETC_ETH_IP_CORRECTABLE_ERROR;
                    SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_27();

                }

            }

        }
    }

    /* Uncorrectable Error reporting for PSI0 */
    if ((IP_NETC__NETC_F3_PCI_HDR_TYPE0->PCIE_CFC_AER_UCORR_ERR_STAT & NETC_ETH_IP_UCORR_STATUS_BIT) != (uint32)0U)
    {
        /* Un-masked interrupts are marked as 0*/
        if ((IP_NETC__NETC_F3_PCI_HDR_TYPE0->PCIE_CFC_AER_UCORR_ERR_MASK & ((uint32)1U << NETC_ETH_IP_UCORR_ERR_MASK_SHIFT))  == (uint32)0U)
        {
            IP_NETC__NETC_F3_PCI_HDR_TYPE0->PCIE_CFC_AER_UCORR_ERR_STAT = NETC_ETH_IP_UCORR_STATUS_BIT;
            /*If the reg bit is 0 - Error is Non-fatal else is Fatal*/
            if((IP_NETC__NETC_F3_PCI_HDR_TYPE0->PCIE_CFC_AER_UCORR_ERR_SEV & NETC_ETH_IP_UCORR_SEV_MASK) != 0U)
            {
                if (Netc_Eth_Ip_apxState[ctrlIndex]->PcieAerUncorrectableErrEnabled)
                {
                    Netc_Eth_Ip_ErrorStatus[NETC_ETH_IP_PSI0_FUNCTION_INDEX].StatusErrors = NETC_ETH_IP_FATAL_ERROR;
                }
            }
            else
            {
                if (Netc_Eth_Ip_apxState[ctrlIndex]->PcieAerUncorrectableErrEnabled)
                {
                    Netc_Eth_Ip_ErrorStatus[NETC_ETH_IP_PSI0_FUNCTION_INDEX].StatusErrors = NETC_ETH_IP_NON_FATAL_ERROR;
                }
            }

        }
    }
    /* Correctable Error reporting for PSI0 */
    if ((IP_NETC__NETC_F3_PCI_HDR_TYPE0->PCIE_CFC_AER_CORR_ERR_STAT & NETC_ETH_IP_CORR_STATUS_BIT) != (uint32)0U)
    {
        /* Un-masked interrupts are marked as 0*/
        if ((IP_NETC__NETC_F3_PCI_HDR_TYPE0->PCIE_CFC_AER_CORR_ERR_MASK & ((uint32)1U << NETC_ETH_IP_CORR_ERR_MASK_SHIFT)) == (uint32)0U)
        {
            IP_NETC__NETC_F3_PCI_HDR_TYPE0->PCIE_CFC_AER_CORR_ERR_STAT = NETC_ETH_IP_CORR_STATUS_BIT;
            if (Netc_Eth_Ip_apxState[ctrlIndex]->PcieAerCorrectableErrEnabled)
            {                
                SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_27();
                Netc_Eth_Ip_ErrorStatus[NETC_ETH_IP_PSI0_FUNCTION_INDEX].StatusErrors |= NETC_ETH_IP_CORRECTABLE_ERROR;
                SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_27();

            }

        }
    }

    if (Netc_Eth_Ip_apxState[ctrlIndex]->PcieAerErrorReportingCallback != NULL_PTR)
    {
        Netc_Eth_Ip_apxState[ctrlIndex]->PcieAerErrorReportingCallback (ctrlIndex, (const Netc_Eth_Ip_PcieFunctionErrorsReported *)&Netc_Eth_Ip_ErrorStatus);
    }
}

static inline boolean Netc_Eth_Ip_ClearErrorStatus (volatile uint32 *RegAddress)
{
    boolean returnValue = FALSE;

    if ((*RegAddress & NETC_ETH_IP_CLEAR_ERROR_STATUS_MASK) != 0U)
    {
        *RegAddress |= NETC_ETH_IP_CLEAR_ERROR_STATUS_MASK;
        returnValue = TRUE;
    }

    return returnValue;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_EnableIngressPortFiltering
 * Description   : Ethernet enables the ingress port filtering lookup function.
 * implements Netc_Eth_Ip_EnableIngressPortFiltering_Activity
 *END**************************************************************************/
Std_ReturnType Netc_Eth_Ip_EnableIngressPortFiltering( const uint8 CtrlIndex, boolean Enable )
{
    Std_ReturnType Status = E_OK;
    uint32 RegVal;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex == NETC_ETH_IP_PSI_INDEX);
#endif

    (void)CtrlIndex;

    /* Convert the value */
    RegVal = (Enable) ? (0x1UL) : (0x0UL);

    /* write the PIPFCR[EN] bit */
    IP_NETC__ENETC0_PORT->PIPFCR = RegVal;

    return Status;
}

/* inline function for filling in Access Keye data in function Netc_Eth_Ip_FillInIngressPortFilterTableReqDataBuff() */
static inline Netc_Eth_Ip_StatusType FillInAccessKeyeData(const Netc_Eth_Ip_AccessMethodType accessMethod, const volatile uint32 *pAccessKey)
{
    uint8 ItemIdx;
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;

    SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_26();
    switch (accessMethod)
    {
        case NETC_ETH_ENTRY_ID_MATCH:
            /* fill in Entry_ID field */
            Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_ENTRYID_FIELD] = pAccessKey[0U];
            break;
        case NETC_ETH_EXACT_MATCH_KEY_ELEMENT_MATCH:
            /* Not Applicable for Ingress Port Filter table*/
            status = NETC_ETH_CBDRSTATUS_ACCESSMETHOD_ERROR;
            break;
        case NETC_ETH_SEARCH_METHOD:
            /* fill in Resume_Entry_ID field */
            Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_ENTRYID_FIELD] = pAccessKey[0U];
            break;
        case NETC_ETH_TERNARY_MATCH_KEY_ELEMENT_MATCH:
            /* fill in keye_data field */
            for (ItemIdx = 1U; ItemIdx <= NETC_ETH_IP_INGRESSPORTFILTERTABLE_KEYE_DATA_LEN; ItemIdx++)
            {
                Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[ItemIdx] = pAccessKey[ItemIdx - 1U];
            }
            break;
        default:
            /* Not Applicable for Ingress Port Filter table*/
            status = NETC_ETH_CBDRSTATUS_ACCESSMETHOD_ERROR;
            break;
    }
    SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_26();

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_DumpErrorCapture
 * Description   : Function used for getting statistics over an error reported by the Event collector interrupt
 * Prerequisites: Allocate an array of Netc_Eth_Ip_ErrorCaptureRegisterInformation with a length equal to
 * NETC_ETH_IP_MAX_UNCORRECTABLE_ERROR_REPORTING_STATISTICS_LENGTH or
 * NETC_ETH_IP_MAX_CORRECTABLE_ERROR_REPORTING_STATISTICS_LENGTH or sum of them in case both uncorrectable and correctable errors are reported
 * for the function.
 * implements Netc_Eth_Ip_DumpErrorCapture_Activity
 *END**************************************************************************/
void Netc_Eth_Ip_DumpErrorCapture (     const uint8 ctrlIdx,
                                        const Netc_Eth_Ip_PcieFunction function,
                                        uint8 *numberOfRegisters,
                                        uint8 siIndex,
                                        Netc_Eth_Ip_ErrorCaptureRegisterInformation* Buffers[])
{
#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(numberOfRegisters != NULL_PTR);
    DevAssert(Netc_Eth_Ip_apxState[ctrlIdx]->SiType == NETC_ETH_IP_PHYSICAL_SI);
#endif
    uint8 countRegisters = 0U;
    uint32 sbStatus = 0U;

    switch (function)
    {
        case EMDIO:
        if (Netc_Eth_Ip_apxState[ctrlIdx]->PcieAerUncorrectableErrEnabled)
        {
            /*This is the EMDIO uncorrectable non-fatal integrity error status register*/
            if (Netc_Eth_Ip_ClearErrorStatus((volatile uint32 *)&(((IP_NETC__EMDIO_GLOBAL->ERROR).EMDIO).EMDIOUNIESR)))
            {
                if (Buffers[countRegisters] != NULL_PTR)
                {
                    Buffers[countRegisters]->RegName = EMDIOUNIESR;
                    Buffers[countRegisters]->RegRawValueLow = ((IP_NETC__EMDIO_GLOBAL->ERROR).EMDIO).EMDIOUNIESR;
                    Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                    countRegisters++;
                }
            }
            /* EMDIO system bus error status register. */
            if (Netc_Eth_Ip_ClearErrorStatus( (volatile uint32 *)&(((IP_NETC__EMDIO_GLOBAL->ERROR).EMDIO).EMDIOUFSBESR)))
            {
                if (Buffers[countRegisters] != NULL_PTR)
                {
                    /* EMDIO system bus error. */
                    Buffers[countRegisters]->RegName = EMDIOUFSBESR;
                    Buffers[countRegisters]->RegRawValueLow = ((IP_NETC__EMDIO_GLOBAL->ERROR).EMDIO).EMDIOUFSBESR;
                    Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                    countRegisters++;
                }
            }
        }
        *numberOfRegisters = countRegisters;
        break;

        case SWITCH:
            if (Netc_Eth_Ip_apxState[ctrlIdx]->PcieAerCorrectableErrEnabled)
            {
                /* Internal memory single bit ECC error*/
                if(Netc_Eth_Ip_ClearErrorStatus( (volatile uint32 *)&(IP_NETC__SW0_COMMON->CMESR)))
                {
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        /* correctable memory error */
                        Buffers[countRegisters]->RegName = CMESR;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__SW0_COMMON->CMESR;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                }
            }

            if (Netc_Eth_Ip_apxState[ctrlIdx]->PcieAerUncorrectableErrEnabled)
            {
                /* Switch system bus error.*/
                if(Netc_Eth_Ip_ClearErrorStatus((volatile uint32 *) &(IP_NETC__SW0_COMMON->UNSBESR)))
                {
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = UNSBESR;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__SW0_COMMON->UNSBESR;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        /* Indicates how many system bus error events have been encountered. UNSBESR[SB_ID] indicates the last source*/
                        Buffers[countRegisters]->RegName = UNSBECTR;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__SW0_COMMON->UNSBECTR;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                }

                if(Netc_Eth_Ip_ClearErrorStatus((volatile uint32 *) &(IP_NETC__SW0_COMMON->UNMESR0)))
                {
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        /* Memory ID + Syndrome*/
                        Buffers[countRegisters]->RegName = UNMESR0;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__SW0_COMMON->UNMESR0;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        /* Address information (row) of last ECC event.*/
                        Buffers[countRegisters]->RegName = UNMESR1;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__SW0_COMMON->UNMESR1;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        /* This is the uncorrectable non-fatal memory error count register which tracks how many events have been detected.*/
                        Buffers[countRegisters]->RegName = UNMECTR;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__SW0_COMMON->UNMECTR;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                }
                /* Incremented for each frame received with an error (except for undersized/fragment frame):
                    FIFO overflow error
                    CRC error
                    Payload length error
                    Jabber and oversized error
                    Alignment error
                A non-fatal error has occurred in the Ethernet MAC bound to PORT0. See PMa_IEVENT for details and how to clear the event*/
                if((IP_NETC__SW0_COMMON->UNMACESR & (uint32)0x01) != (uint32)0U)
                {
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = PM0_RERR;
                        Buffers[countRegisters]->RegRawValueLow = (uint32)(IP_NETC__SW0_ETH_MAC_PORT0->PM0_RERRN);
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)(IP_NETC__SW0_ETH_MAC_PORT0->PM0_RERRN >> 32U);
                        countRegisters++;
                    }
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        /* EventError.*/
                        Buffers[countRegisters]->RegName = PM0_EVENT;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__SW0_ETH_MAC_PORT0->PM0_IEVENT;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        /* A count of received MAC frames / MAC frame fragments rejected due to unknown
                        SMD value or arriving with an SMD-C when no frame is in progress.*/
                        Buffers[countRegisters]->RegName = MAC_MERGE_MMFSECR0;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__SW0_ETH_MAC_PORT0->MAC_MERGE_MMFSECR;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        /* A count of MAC frames with reassembly errors.*/
                        Buffers[countRegisters]->RegName = MAC_MERGE_MMFAECR0;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__SW0_ETH_MAC_PORT0->MAC_MERGE_MMFAECR;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                }
                if((IP_NETC__SW0_COMMON->UNMACESR & (uint32)0x02) != (uint32)0U)
                {
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = PM1_RERR;
                        Buffers[countRegisters]->RegRawValueLow = (uint32)(IP_NETC__SW0_ETH_MAC_PORT1->PM1_RERRN);
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)(IP_NETC__SW0_ETH_MAC_PORT1->PM1_RERRN >> 32U);
                        countRegisters++;
                    }
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        /* EventError.*/
                        Buffers[countRegisters]->RegName = PM1_EVENT;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__SW0_ETH_MAC_PORT1->PM1_IEVENT;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        /* A count of received MAC frames / MAC frame fragments rejected due to unknown
                        SMD value or arriving with an SMD-C when no frame is in progress.*/
                        Buffers[countRegisters]->RegName = MAC_MERGE_MMFSECR1;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__SW0_ETH_MAC_PORT1->MAC_MERGE_MMFSECR;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        /* A count of MAC frames with reassembly errors.*/
                        Buffers[countRegisters]->RegName = MAC_MERGE_MMFAECR1;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__SW0_ETH_MAC_PORT1->MAC_MERGE_MMFAECR;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                }
                /* Integrity fault*/
                if(Netc_Eth_Ip_ClearErrorStatus( (volatile uint32 *)&(IP_NETC__SW0_COMMON->UNIESR)))
                {
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = UNIESR;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__SW0_COMMON->UNIESR;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                    /* Indicates the number of non-fatal integrity faults detected which includes internal FCS and parity errors.*/
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = UNIECTR;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__SW0_COMMON->UNIECTR;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                }
                /* Fatal system bus error status register. */
                if(Netc_Eth_Ip_ClearErrorStatus( (volatile uint32 *)&(IP_NETC__SW0_COMMON->UFSBESR)))
                {
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = UFSBESR;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__SW0_COMMON->UFSBESR;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                }
                /* Uncorrectable fatal memory error status register 0.*/
                if(Netc_Eth_Ip_ClearErrorStatus( (volatile uint32 *)&(IP_NETC__SW0_COMMON->UFMESR0)))
                {
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = UFMESR0;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__SW0_COMMON->UFMESR0;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = UFMESR1;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__SW0_COMMON->UFMESR1;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                }
                /* Fatal integrity error status register. */
                if(Netc_Eth_Ip_ClearErrorStatus((volatile uint32 *) &(IP_NETC__SW0_COMMON->UFIESR)))
                {
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = UFIESR;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__SW0_COMMON->UFIESR;
                        Buffers[countRegisters]->RegRawValueHigh = 0U;
                        countRegisters++;
                    }
                }
            }
            /* Return the value of the registers that have been written */
            *numberOfRegisters = countRegisters;

            break;

        case TIMER:
            /* timer system bus error. */
            if (Netc_Eth_Ip_apxState[ctrlIdx]->PcieAerUncorrectableErrEnabled)
            {
                if (Netc_Eth_Ip_ClearErrorStatus((volatile uint32 *) &(((IP_NETC__TMR0_GLOBAL->ERROR).TIMER).TUFSBESR )))
                {
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = TUFSBESR;
                        Buffers[countRegisters]->RegRawValueLow = ((IP_NETC__TMR0_GLOBAL->ERROR).TIMER).TUFSBESR;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                }
            }
            *numberOfRegisters = countRegisters;
            break;

        case ENETC:
            if (Netc_Eth_Ip_apxState[ctrlIdx]->PcieAerCorrectableErrEnabled)
            {
                if(Netc_Eth_Ip_ClearErrorStatus((volatile uint32 *) &(IP_NETC__ENETC0_COMMON->CMESR)))
                {
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        /* correctable memory error */
                        Buffers[countRegisters]->RegName = CMESR;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__ENETC0_COMMON->CMESR;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                }
            }

            if (Netc_Eth_Ip_apxState[ctrlIdx]->PcieAerUncorrectableErrEnabled)
            {
                if(Netc_Eth_Ip_ClearErrorStatus((volatile uint32 *) &(IP_NETC__ENETC0_COMMON->UNMESR0)))
                {
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        /* Memory ID + Syndrome*/
                        Buffers[countRegisters]->RegName = UNMESR0;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__ENETC0_COMMON->UNMESR0;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        /* Address information (row) of last ECC event.*/
                        Buffers[countRegisters]->RegName = UNMESR1;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__ENETC0_COMMON->UNMESR1;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        /* This is the uncorrectable non-fatal memory error count register which tracks how many events have been detected.*/
                        Buffers[countRegisters]->RegName = UNMECTR;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__ENETC0_COMMON->UNMECTR;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                }

                if(Netc_Eth_Ip_ClearErrorStatus((volatile uint32 *) &(IP_NETC__ENETC0_COMMON->UNIESR)))
                {
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = UNIESR;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__ENETC0_COMMON->UNIESR;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = UNIECTR;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__ENETC0_COMMON->UNIECTR;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                }

                if(Netc_Eth_Ip_ClearErrorStatus((volatile uint32 *) &(IP_NETC__ENETC0_COMMON->UFMESR0)))
                {
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = UFMESR0;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__ENETC0_COMMON->UFMESR0;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = UFMESR1;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__ENETC0_COMMON->UFMESR1;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                }

                if(Netc_Eth_Ip_ClearErrorStatus((volatile uint32 *) &(IP_NETC__ENETC0_COMMON->UFIESR)))
                {
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = UFIESR;
                        Buffers[countRegisters]->RegRawValueLow = IP_NETC__ENETC0_COMMON->UFIESR;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                }
            }
            *numberOfRegisters = countRegisters;
            break;

        case PSI:
        case VSI:
        #if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
            DevAssert(siIndex < 8U);
        #endif
            if (Netc_Eth_Ip_apxState[ctrlIdx]->PcieAerUncorrectableErrEnabled)
            {
                if(Netc_Eth_Ip_ClearErrorStatus( (volatile uint32 *)&(netcSIsBase[siIndex]->SIUPESR)))
                {
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = SIUPESR;
                        Buffers[countRegisters]->RegRawValueLow = netcSIsBase[siIndex]->SIUPESR;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = SIUPECTR;
                        Buffers[countRegisters]->RegRawValueLow = netcSIsBase[siIndex]->SIUPECTR;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                }
                /* Multi-bit ECC error. */
                if(Netc_Eth_Ip_ClearErrorStatus((volatile uint32 *) &(netcSIsBase[siIndex]->SIUNMESR0)))
                {
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = SIUNMESR0;
                        Buffers[countRegisters]->RegRawValueLow = netcSIsBase[siIndex]->SIUNMESR0;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = SIUNMESR1;
                        Buffers[countRegisters]->RegRawValueLow = netcSIsBase[siIndex]->SIUNMESR1;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = SIUNMECTR;
                        Buffers[countRegisters]->RegRawValueLow = netcSIsBase[siIndex]->SIUNMECTR;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                }
                /* Fatal Multi-bit ECC error. */
                if(Netc_Eth_Ip_ClearErrorStatus((volatile uint32 *) &(netcSIsBase[siIndex]->SIUFMESR0)))
                {
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = SIUFMESR0;
                        Buffers[countRegisters]->RegRawValueLow = netcSIsBase[siIndex]->SIUFMESR0;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = SIUFMESR1;
                        Buffers[countRegisters]->RegRawValueLow = netcSIsBase[siIndex]->SIUFMESR1;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                }

                if(Netc_Eth_Ip_ClearErrorStatus((volatile uint32 *) &(netcSIsBase[siIndex]->SIUFSBESR)))
                {
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = SIUFSBESR;
                        Buffers[countRegisters]->RegRawValueLow = netcSIsBase[siIndex]->SIUFSBESR;
                        Buffers[countRegisters]->RegRawValueHigh = 0U;
                        countRegisters++;
                    }
                    for (uint8 idx = 0U; idx < Netc_Eth_Ip_apxState[ctrlIdx]->SIGeneralConfig[siIndex]->NumberOfTxBDR; idx++)
                    {
                    /*A system bus error has occurred during one or more transactions related to this transmit ring, including possibly
                    the transmit BD writeback entry itself. To avoid the possibility of referencing unreliable
                    BD writeback contents,
                    See error detect register SIUNSBESR/SIUFSBESR for more information. Write 1 to clear.*/
                        sbStatus= netcSIsBase[siIndex]->BDR_NUM[idx].TBSR;

                        if ((sbStatus & (uint32)0x00010000) != 0U)
                        {
                            sbStatus &= ~((uint32)0x00010000);
                            netcSIsBase[siIndex]->BDR_NUM[idx].TBSR = sbStatus;
                            if (Buffers[countRegisters] != NULL_PTR)
                            {
                                Buffers[countRegisters]->RegName = TBCIR;
                                Buffers[countRegisters]->RegRawValueLow = netcSIsBase[siIndex]->BDR_NUM[idx].TBCIR;
                                /* save also the current BDR with error */
                                Buffers[countRegisters]->RegRawValueHigh = (uint32)idx;
                                countRegisters++;
                            }
                        }
                    }
                    for (uint8 idx = 0U; idx < Netc_Eth_Ip_apxState[ctrlIdx]->SIGeneralConfig[siIndex]->NumberOfRxBDR; idx++)
                    {
                        sbStatus= netcSIsBase[siIndex]->BDR_NUM[idx].RBSR;
                        if ((sbStatus & (uint32)0x00010000)  != 0U)
                        {
                            sbStatus &= ~((uint32)0x00010000);
                            netcSIsBase[siIndex]->BDR_NUM[idx].RBSR = sbStatus;
                            if (Buffers[countRegisters] != NULL_PTR)
                            {
                                Buffers[countRegisters]->RegName = RBPIR;
                                Buffers[countRegisters]->RegRawValueLow = netcSIsBase[siIndex]->BDR_NUM[idx].RBPIR;
                                /* save also the current BDR with error */
                                Buffers[countRegisters]->RegRawValueHigh = (uint32)idx;
                                countRegisters++;
                            }
                        }
                    }

                    if(Netc_Eth_Ip_ClearErrorStatus( (volatile uint32 *) &(netcSIsBase[siIndex]->SIUFIESR)))
                    {
                        if (Buffers[countRegisters] != NULL_PTR)
                        {
                            Buffers[countRegisters]->RegName = SIUFIESR;
                            Buffers[countRegisters]->RegRawValueLow = netcSIsBase[siIndex]->SIUFIESR;
                            Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                            countRegisters++;
                        }
                    }
                }
            }
            if (Netc_Eth_Ip_apxState[ctrlIdx]->PcieAerCorrectableErrEnabled)
            {
                if(Netc_Eth_Ip_ClearErrorStatus( (volatile uint32 *)&(netcSIsBase[siIndex]->SICMESR)))
                {
                    if (Buffers[countRegisters] != NULL_PTR)
                    {
                        Buffers[countRegisters]->RegName = SICMESR;
                        Buffers[countRegisters]->RegRawValueLow = netcSIsBase[siIndex]->SICMESR;
                        Buffers[countRegisters]->RegRawValueHigh = (uint32)0U;
                        countRegisters++;
                    }
                }
            }
            *numberOfRegisters = countRegisters;
        break;

        default:
            *numberOfRegisters = countRegisters;
            break;
    }
}
/*FUNCTION**********************************************************************
 * Function Name : Netc_Eth_Ip_FillInIngressPortFilterTableReqDataBuff
 * Description   : Internal function for initializing the Ingress Port Filter Table Request Data Buffer.
 *
 *END**************************************************************************/
static Netc_Eth_Ip_StatusType Netc_Eth_Ip_FillInIngressPortFilterTableReqDataBuff( uint32 ActionsData,
                                                                                   const volatile uint32 *pAccessKey,
                                                                                   const Netc_Eth_Ip_IngressPortFilterCfgeDataType *pCfgeData,
                                                                                   Netc_Eth_Ip_AccessMethodType accessMethod
                                                                                 )
{
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;

    SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_25();
    /* ------initialize the table request data buffer------ */
    Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD] = ActionsData;  /* fill in Actions field */

    /* initialize ACCESS_KEY */
    status = FillInAccessKeyeData(accessMethod, pAccessKey);

    /* initialize CFGE_DATA. This portion is present only for commands which perform an update or add. */
    if (pCfgeData != NULL_PTR)
    {

        Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_INGRESSPORTFILTER_CFGE_CONFIG_FIELD] = (NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_IPV(pCfgeData->CfgeIpv) \
                                                                                            | NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_OIPV(pCfgeData->CfgeOverrideIpv ? 1U : 0U) \
                                                                                            | NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_DR(pCfgeData->CfgeDr) \
                                                                                            | NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_ODR(pCfgeData->CfgeOverrideDr ? 1U : 0U) \
                                                                                            | NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_FLTFA(pCfgeData->CfgeFilterForwardingAction) \
                                                                                            | NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_WOLTE(pCfgeData->CfgeWakeOnLanTriggerEnable ? 1U : 0U) \
                                                                                            | NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_FLTA(pCfgeData->CfgeFilterAction) \
                                                                                            | NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_RPR(pCfgeData->CfgeRelativePrecedentResolution));
        Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[NETC_ETH_IP_INGRESSPORTFILTER_CFGE_FLTATGT_FIELD] = pCfgeData->CfgeTargetForSelectedFilterAction;

    }
    SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_25();

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_AddIngressPortFilterTableEntry
 * Description   : Ethernet adds Ingress Port Filter table entry function.
 * implements Netc_Eth_Ip_AddIngressPortFilterTableEntry_Activity
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_AddIngressPortFilterTableEntry( uint8 CtrlIndex,
                                                                   uint32 *MatchedEntries,
                                                                   Netc_Eth_Ip_IngressPortFilterEntryDataType * IngressPortFilterTableEntry
                                                                 )
{
    Netc_Eth_Ip_StatusType status;
    NetcEth_Ip_ReqHeaderTableOperationDataType OperationData;
    uint32 ActionsData;
    uint8 ByteIdx;
    uint8 CfgeDataIdx;
    uint8 PayloadIdx;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex == NETC_ETH_IP_PSI_INDEX);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(IngressPortFilterTableEntry != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* set STSEU and CFGEU flag */
    ActionsData = (NETC_ETH_IP_IPFTABLE_REQFMT_ACTIONS_FIELD_STSEU(1U) | NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_CFGEU(1U));

    /* inialize KEYE_DATA */
    IPFKeyeData[0U] = IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePrecedence;
    IPFKeyeData[2U] = ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeFrmAttributeFlagsMask) << NETC_ETH_IP_16BIT_SHIFT) \
                 | IngressPortFilterTableEntry->IngressPortFilterkeyeData.keyeFrmAttributeFlags;
    IPFKeyeData[3U] = NETC_ETH_IP_IPFTABLE_KEYE_DATA_DSCPMASK(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDifferentiatedServicesCodePointMask) \
                 | NETC_ETH_IP_IPFTABLE_KEYE_DATA_DIFFSCP(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDifferentiatedServicesCodePoint);
    IPFKeyeData[4U] = ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformationMask) << NETC_ETH_IP_16BIT_SHIFT) \
                 | (IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformation << NETC_ETH_IP_8BIT_SHIFT);        /* big endian for TCI */
    IPFKeyeData[5U] = (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[0U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[1U]) << NETC_ETH_IP_8BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[2U]) << NETC_ETH_IP_16BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[3U]) << NETC_ETH_IP_24BIT_SHIFT);
    IPFKeyeData[6U] = (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[4U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[5U]) << NETC_ETH_IP_8BIT_SHIFT) \
                 | (((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[0U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[1U]) << NETC_ETH_IP_8BIT_SHIFT)) << NETC_ETH_IP_16BIT_SHIFT);
    IPFKeyeData[7U] = (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[2U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[3U]) << NETC_ETH_IP_8BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[4U]) << NETC_ETH_IP_16BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[5U]) << NETC_ETH_IP_24BIT_SHIFT);
    IPFKeyeData[8U] = (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[0U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[1U]) << NETC_ETH_IP_8BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[2U]) << NETC_ETH_IP_16BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[3U]) << NETC_ETH_IP_24BIT_SHIFT);
    IPFKeyeData[9U] = (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[4U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[5U]) << NETC_ETH_IP_8BIT_SHIFT) \
                 | (((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[0U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[1U]) << NETC_ETH_IP_8BIT_SHIFT)) << NETC_ETH_IP_16BIT_SHIFT);
    IPFKeyeData[10U] = (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[2U]) | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[3U]) << NETC_ETH_IP_8BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[4U]) << NETC_ETH_IP_16BIT_SHIFT) \
                 | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[5U]) << NETC_ETH_IP_24BIT_SHIFT);
    IPFKeyeData[11U] = ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeInnerVLANTagControlInformationMask) << NETC_ETH_IP_16BIT_SHIFT) \
                 | IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeInnerVLANTagControlInformation;
    IPFKeyeData[12U] = ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeEtherTypeMask) << NETC_ETH_IP_16BIT_SHIFT) \
                 | IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeEtherTypeMask;
    IPFKeyeData[13U] = ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPProtocolMask) << NETC_ETH_IP_8BIT_SHIFT) | (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPProtocol);
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IPFKeyeData[ByteIdx + 17U] = IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPSourceAddress[ByteIdx];
    }
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IPFKeyeData[ByteIdx + 23U] = IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPSourceAddressMask[ByteIdx];
    }
    IPFKeyeData[27U] = ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4SourcePortMask) << NETC_ETH_IP_16BIT_SHIFT) | IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4SourcePort;
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IPFKeyeData[ByteIdx + 29U] = IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPDestinationAddress[ByteIdx];
    }
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IPFKeyeData[ByteIdx + 35U] = IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPDestinationAddressMask[ByteIdx];
    }
    IPFKeyeData[39U] = ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4DestinationPortMask) << NETC_ETH_IP_16BIT_SHIFT) | IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4DestinationPort;

    CfgeDataIdx = 0U;
    PayloadIdx = 0U;
    for (ByteIdx = 0U; ByteIdx < 12U; ByteIdx++)
    {
        IPFKeyeData[CfgeDataIdx + 41U] = (uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytes[ByteIdx + PayloadIdx]) \
                                   | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytesMask[ByteIdx + PayloadIdx]) << NETC_ETH_IP_8BIT_SHIFT) \
                                   | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytes[ByteIdx + PayloadIdx + 1U]) << NETC_ETH_IP_16BIT_SHIFT) \
                                   | ((uint32)(IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytesMask[ByteIdx + PayloadIdx + 1U]) << NETC_ETH_IP_24BIT_SHIFT);
        PayloadIdx++;
        CfgeDataIdx++;
    }

    /* only supports "NETC_ETH_TERNARY_MATCH_KEY_ELEMENT_MATCH" access method */
    status = Netc_Eth_Ip_FillInIngressPortFilterTableReqDataBuff(ActionsData, &IPFKeyeData[0U], &(IngressPortFilterTableEntry->IngressPortFilterCfgeData), NETC_ETH_TERNARY_MATCH_KEY_ELEMENT_MATCH);
    if (NETC_ETH_IP_STATUS_SUCCESS == status)
    {
        /* fill in operation data for config field of Request Header*/
        OperationData.CmdCompletionInt = 0x0U;                                          /* command completion interrupt disabled */
        OperationData.Version = NETC_ETH_IP_CMDBD_REQFMT_PROTOCOL_VERSION;              /* protocol version = 2 */
        OperationData.TableId = NETC_ETH_IP_INGRESS_PORT_FILTER_TABLE_ID;
        OperationData.AccessMethod = NETC_ETH_TERNARY_MATCH_KEY_ELEMENT_MATCH;          /* for Adding an ingress port filter entry, the Access Method should only be NETC_ETH_TERNARY_MATCH_KEY_ELEMENT_MATCH */
        OperationData.Cmd = NETC_ETH_ADD_FOLLOWEDBY_QUERY_CMD;                       /* can only use "Add followed by a Query" command to add an ingress port filter table entry */
        OperationData.ReqBuffLength = (NETC_ETH_IP_INGRESSPORTFILTERTABLE_REQBUFFER_LEN);
        OperationData.RspBuffLength = (NETC_ETH_IP_INGRESSPORTFILTERTABLE_RSPBUFFER_LEN);

        /* send command */
        status = Netc_Eth_Ip_SendCommand(CtrlIndex, &OperationData);
#if defined(ERR_IPV_NETC_051243)
    #if (STD_ON == ERR_IPV_NETC_051243)
    /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == NETC_ETH_IP_STATUS_NOT_REAL_ERROR) || (status == NETC_ETH_IP_STATUS_SUCCESS))
        {
    #endif
#else
        if (status == NETC_ETH_IP_STATUS_SUCCESS)
        {
#endif
            status = NETC_ETH_IP_STATUS_SUCCESS;
            Netc_Eth_Ip_GetMatchedEntries(CtrlIndex, MatchedEntries);
            /* It's an "Add followed by a Query", but even if this entry is added successfully, the MatchedEntry is still 0. So here we can not check the MatchedEntries parameter. */
            IngressPortFilterTableEntry->IngressPortFilterEntryID = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[1U];     /* Get the Entry_ID from response data buffer */
        }
    }
    else
    {
        status = NETC_ETH_CBDRSTATUS_ACCESSMETHOD_ERROR;
    }

    return status;
}

/* inline function for filling in part of keye data in function FillInIPFTableEntryData() */
static inline void Netc_Eth_Ip_FillInKeyeDataForIPF(Netc_Eth_Ip_IngressPortFilterEntryDataType * IngressPortFilterTableEntry)
{
    uint8 ByteIdx;
    uint8 PayloadIdx;
    uint8 CfgeDataIdx;

    SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_25();
    for (ByteIdx = 2U; ByteIdx < 6U; ByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[ByteIdx] = (uint8)(Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[12U] & NETC_ETH_IP_0XFF_MASK);
        Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[12U] >>= NETC_ETH_IP_8BIT_SHIFT;
    }
    SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_25();

    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeInnerVLANTagControlInformation = (uint16)(Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[13U] & NETC_ETH_IP_0XFFFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeInnerVLANTagControlInformationMask = (uint16)((Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[13U] >> NETC_ETH_IP_16BIT_SHIFT) & NETC_ETH_IP_0XFFFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeEtherType = (uint16)(Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[14U] & NETC_ETH_IP_0XFFFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeEtherTypeMask = (uint16)((Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[14U] >> NETC_ETH_IP_16BIT_SHIFT) & NETC_ETH_IP_0XFFFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPProtocol = (uint8)(Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[15U] & NETC_ETH_IP_0XFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPProtocolMask = (uint8)((Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[15U] >> NETC_ETH_IP_8BIT_SHIFT) & NETC_ETH_IP_0XFF_MASK);
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPSourceAddress[ByteIdx] = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[ByteIdx + 19U];
    }
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPSourceAddressMask[ByteIdx] = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[ByteIdx + 25U];
    }
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4SourcePort = (uint16)(Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[29U] & NETC_ETH_IP_0XFFFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4SourcePortMask = (uint16)((Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[29U] >> NETC_ETH_IP_16BIT_SHIFT) & NETC_ETH_IP_0XFFFF_MASK);
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPDestinationAddress[ByteIdx] = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[ByteIdx + 31U];
    }
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeIPDestinationAddressMask[ByteIdx] = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[ByteIdx + 37U];
    }
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4DestinationPort = (uint16)(Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[41U] & NETC_ETH_IP_0XFFFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeL4DestinationPortMask = (uint16)((Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[41U] >> NETC_ETH_IP_16BIT_SHIFT) & NETC_ETH_IP_0XFFFF_MASK);

    CfgeDataIdx = 0U;
    PayloadIdx = 0U;
    for (ByteIdx = 0U; ByteIdx < 12U; ByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytes[ByteIdx + PayloadIdx] = (uint8)(Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[CfgeDataIdx + 43U] & NETC_ETH_IP_0XFF_MASK);
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytes[ByteIdx + PayloadIdx + 1U] = (uint8)((Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[CfgeDataIdx + 43U] >> NETC_ETH_IP_16BIT_SHIFT) & NETC_ETH_IP_0XFF_MASK);
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytesMask[ByteIdx + PayloadIdx] = (uint8)((Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[CfgeDataIdx + 43U] >> NETC_ETH_IP_8BIT_SHIFT) & NETC_ETH_IP_0XFF_MASK);
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePayloadBytesMask[ByteIdx + PayloadIdx + 1U] = (uint8)((Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[CfgeDataIdx + 43U] >> NETC_ETH_IP_24BIT_SHIFT) & NETC_ETH_IP_0XFF_MASK);
        PayloadIdx++;
        CfgeDataIdx++;
    }
}

/* inline function for filling in IngressPortFilterTableEntry data in function Netc_Eth_Ip_QueryIngressPortFilterTableEntry() */
static inline void Netc_Eth_Ip_FillInIPFTableEntryData(Netc_Eth_Ip_IngressPortFilterEntryDataType * IngressPortFilterTableEntry)
{
    uint8 ByteIdx;
    uint32 CfgeData;

    /* fill in structure Netc_Eth_Ip_IngressPortFilterEntryDataType with data from response data buffer */
    IngressPortFilterTableEntry->IngressPortFilterEntryID = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[1U];         /* Entry_ID */

    /* KEYE_DATA */
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyePrecedence = (uint16)(Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[2U] & NETC_ETH_IP_0XFFFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.keyeFrmAttributeFlags = (uint16)(Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[4U] & NETC_ETH_IP_0XFFFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeFrmAttributeFlagsMask = (uint16)((Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[4U] & NETC_ETH_IP_0XFFFF0000_MASK) >> NETC_ETH_IP_16BIT_SHIFT);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDifferentiatedServicesCodePoint = (uint8)(Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[5U] & NETC_ETH_IP_IPFTABLE_KEYE_DATA_DIFFSCP_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDifferentiatedServicesCodePointMask = (uint8)((Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[5U] & NETC_ETH_IP_IPFTABLE_KEYE_DATA_DSCPMASK_MASK) \
                                                                                                    >> NETC_ETH_IP_IPFTABLE_KEYE_DATA_DSCPMASK_SHIFT);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformation = (uint16)(Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[6U] & NETC_ETH_IP_0XFFFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeOuterVLANTagControlInformationMask = (uint16)((Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[6U] & NETC_ETH_IP_0XFFFF0000_MASK) >> NETC_ETH_IP_16BIT_SHIFT);
    SchM_Enter_Eth_43_NETC_ETH_EXCLUSIVE_AREA_25();

    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[ByteIdx] = (uint8)(Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[7U] & NETC_ETH_IP_0XFF_MASK);
        Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[7U] >>= NETC_ETH_IP_8BIT_SHIFT;
    }

    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[4U] = (uint8)(Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[8U] & NETC_ETH_IP_0XFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddr[5U] = (uint8)((Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[8U] >> NETC_ETH_IP_8BIT_SHIFT) & NETC_ETH_IP_0XFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[0U] = (uint8)((Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[8U] >> NETC_ETH_IP_16BIT_SHIFT) & NETC_ETH_IP_0XFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[1U] = (uint8)((Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[8U] >> NETC_ETH_IP_24BIT_SHIFT) & NETC_ETH_IP_0XFF_MASK);
    for (ByteIdx = 2U; ByteIdx < 6U; ByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeDstMacAddrMask[ByteIdx] = (uint8)(Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[9U] & NETC_ETH_IP_0XFF_MASK);
        Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[9U] >>= NETC_ETH_IP_8BIT_SHIFT;
    }
    for (ByteIdx = 0U; ByteIdx < 4U; ByteIdx++)
    {
        IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[ByteIdx] = (uint8)(Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[10U] & NETC_ETH_IP_0XFF_MASK);
        Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[10U] >>= NETC_ETH_IP_8BIT_SHIFT;
    }
    SchM_Exit_Eth_43_NETC_ETH_EXCLUSIVE_AREA_25();

    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[4U] = (uint8)(Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[11U] & NETC_ETH_IP_0XFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddr[5U] = (uint8)((Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[11U] >> NETC_ETH_IP_8BIT_SHIFT) & NETC_ETH_IP_0XFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[0U] = (uint8)((Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[11U] >> NETC_ETH_IP_16BIT_SHIFT) & NETC_ETH_IP_0XFF_MASK);
    IngressPortFilterTableEntry->IngressPortFilterkeyeData.KeyeSrcMacAddrMask[1U] = ((uint8)(Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[11U] >> NETC_ETH_IP_24BIT_SHIFT) & NETC_ETH_IP_0XFF_MASK);

    Netc_Eth_Ip_FillInKeyeDataForIPF(IngressPortFilterTableEntry);  /* fill in the rest part of the KEYE_DATA */

    /* Match Count data */
    IngressPortFilterTableEntry->IngressPortFilterMatchCount = (uint64)(Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[55U]);
    IngressPortFilterTableEntry->IngressPortFilterMatchCount |= ((uint64)(Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[56U]) << NETC_ETH_IP_32BIT_SHIFT);

    /* CFGE_DATA */
    CfgeData = Netc_Eth_Ip_EnetcTableDataBuffer.TableDataField[57U];             /* config field in CFGE_DATA */
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeIpv = (uint8)(CfgeData & NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_IPV_MASK);
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeOverrideIpv = (((CfgeData & NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_OIPV_MASK) >> NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_OIPV_SHIFT) != 0x0UL) ? TRUE : FALSE;
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeDr = (uint8)((CfgeData & NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_DR_MASK) >> NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_DR_SHIFT);
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeOverrideDr = (((CfgeData & NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_ODR_MASK) >> NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_ODR_SHIFT) != 0x0UL) ? TRUE : FALSE;
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeFilterForwardingAction = ((CfgeData & NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_FLTFA_MASK) >> NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_FLTFA_SHIFT);
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeWakeOnLanTriggerEnable = (((CfgeData & NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_WOLTE_MASK) >> NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_WOLTE_SHIFT) != 0x0UL) ? TRUE : FALSE;
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeFilterAction = ((CfgeData & NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_FLTA_MASK) >> NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_FLTA_SHIFT);
    IngressPortFilterTableEntry->IngressPortFilterCfgeData.CfgeRelativePrecedentResolution = (uint8)((CfgeData & NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_RPR_MASK) >> NETC_ETH_IP_IPFTABLE_CFGE_CONFIG_RPR_SHIFT);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_QueryIngressPortFilterTableEntry
 * Description   : Ethernet querys Ingress Port Filter table entry function.
 * implements Netc_Eth_Ip_QueryIngressPortFilterTableEntry_Activity
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_QueryIngressPortFilterTableEntry( const uint8 CtrlIndex,
                                                                     uint32 *MatchedEntries,
                                                                     Netc_Eth_Ip_IngressPortFilterEntryDataType * IngressPortFilterTableEntry
                                                                   )
{
    Netc_Eth_Ip_StatusType status;
    NetcEth_Ip_ReqHeaderTableOperationDataType OperationData;
    uint32 KeyeData[NETC_ETH_IP_INGRESSPORTFILTERTABLE_KEYE_DATA_LEN];
    uint32 ActionsData;


#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex == NETC_ETH_IP_PSI_INDEX);
    DevAssert(MatchedEntries != NULL_PTR);
    DevAssert(IngressPortFilterTableEntry != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* only support "full query" */
    ActionsData = NETC_ETH_IP_ENETCTABLE_REQFMT_ACTIONS_FIELD_QUERY_ACTIONS(NETC_ETH_TABLES_FULL_QUERY);

    /* inialize KEYE_DATA with Entry_ID */
    KeyeData[0U] = IngressPortFilterTableEntry->IngressPortFilterEntryID;

    status = Netc_Eth_Ip_FillInIngressPortFilterTableReqDataBuff(ActionsData, &KeyeData[0U], NULL_PTR, NETC_ETH_ENTRY_ID_MATCH);
    if (NETC_ETH_IP_STATUS_SUCCESS == status)
    {
        /* fill in operation data for config field of Request Header*/
        OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        OperationData.Version = NETC_ETH_IP_CMDBD_REQFMT_PROTOCOL_VERSION;            /* protocol version = 2 */
        OperationData.TableId = NETC_ETH_IP_INGRESS_PORT_FILTER_TABLE_ID;
        OperationData.AccessMethod = NETC_ETH_ENTRY_ID_MATCH;
        OperationData.Cmd = NETC_ETH_QUERY_CMD;
        OperationData.ReqBuffLength = (NETC_ETH_IP_INGRESSPORTFILTERTABLE_REQBUFFER_LEN);
        OperationData.RspBuffLength = (NETC_ETH_IP_INGRESSPORTFILTERTABLE_RSPBUFFER_LEN);

        /* send command */
        status = Netc_Eth_Ip_SendCommand(CtrlIndex, &OperationData);
#if defined(ERR_IPV_NETC_051243)
    #if (STD_ON == ERR_IPV_NETC_051243)
    /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == NETC_ETH_IP_STATUS_NOT_REAL_ERROR) || (status == NETC_ETH_IP_STATUS_SUCCESS))
        {
    #endif
#else
        if (status == NETC_ETH_IP_STATUS_SUCCESS)
        {
#endif
            status = NETC_ETH_IP_STATUS_SUCCESS;
            Netc_Eth_Ip_GetMatchedEntries(CtrlIndex, MatchedEntries);
            /* if found a matched entry, then fill in the structure */
            if (1U == *MatchedEntries)
            {
                Netc_Eth_Ip_FillInIPFTableEntryData(IngressPortFilterTableEntry);
            }
        }
    }
    else
    {
        status = NETC_ETH_CBDRSTATUS_ACCESSMETHOD_ERROR;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_DeleteIngressPortFilterTableEntry
 * Description   : Ethernet deletes Ingress Port Filter table entry function.
 * implements Netc_Eth_Ip_DeleteIngressPortFilterTableEntry_Activity
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_DeleteIngressPortFilterTableEntry( const uint8 CtrlIndex,
                                                                      uint32 *MatchedEntries,
                                                                      uint32 IngressPortFilterEntryId
                                                                    )
{
    Netc_Eth_Ip_StatusType status;
    NetcEth_Ip_ReqHeaderTableOperationDataType OperationData;
    uint32 KeyeData[1U];
    uint32 ActionsData = 0x0UL;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex == NETC_ETH_IP_PSI_INDEX);
    DevAssert(MatchedEntries != NULL_PTR);
#endif

    /* clear the variable MatchedEntries first */
    *MatchedEntries = 0U;

    /* inialize KEYE_DATA with Entry_ID */
    KeyeData[0U] = IngressPortFilterEntryId;

    status = Netc_Eth_Ip_FillInIngressPortFilterTableReqDataBuff(ActionsData, &KeyeData[0U], NULL_PTR, NETC_ETH_ENTRY_ID_MATCH);
    if (NETC_ETH_IP_STATUS_SUCCESS == status)
    {
        /* fill in operation data for config field of Request Header*/
        OperationData.CmdCompletionInt = 0x0U;                                        /* command completion interrupt disabled */
        OperationData.Version = NETC_ETH_IP_CMDBD_REQFMT_PROTOCOL_VERSION;            /* protocol version = 2 */
        OperationData.TableId = NETC_ETH_IP_INGRESS_PORT_FILTER_TABLE_ID;
        OperationData.AccessMethod = NETC_ETH_ENTRY_ID_MATCH;
        OperationData.Cmd = NETC_ETH_DELETE_CMD;
        OperationData.ReqBuffLength = (NETC_ETH_IP_INGRESSPORTFILTERTABLE_REQBUFFER_LEN);
        OperationData.RspBuffLength = (NETC_ETH_IP_TABLE_COMMON_RSPBUFFER_4BYTE_LEN);

        /* send command */
        status = Netc_Eth_Ip_SendCommand(CtrlIndex, &OperationData);
#if defined(ERR_IPV_NETC_051243)
    #if (STD_ON == ERR_IPV_NETC_051243)
    /* Error code 0x8A is not a real error. check it on Errata. */
        if ((status == NETC_ETH_IP_STATUS_NOT_REAL_ERROR) || (status == NETC_ETH_IP_STATUS_SUCCESS))
        {
    #endif
#else
        if (status == NETC_ETH_IP_STATUS_SUCCESS)
        {
#endif
            status = NETC_ETH_IP_STATUS_SUCCESS;
            Netc_Eth_Ip_GetMatchedEntries(CtrlIndex, MatchedEntries);
        }
    }
    else
    {
        status = NETC_ETH_CBDRSTATUS_ACCESSMETHOD_ERROR;
    }

    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_GetSyncState
 * Description   : Get Timer Syncronization state function.
 * implements Netc_Eth_Ip_GetSyncState_Activity
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_GetSyncState( const uint8 CtrlIndex,
                                            boolean *SyncState
                                                            )
{
    static volatile uint16 PSIRspMessage;
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
    DevAssert(SyncState != NULL_PTR);
#endif

    /* If the controller is of physical type it can directly read the sync state from the register,
        otherwise it must use VSI to PSI messaging to request a read from the PSI */
    if(Netc_Eth_Ip_apxState[CtrlIndex]->SiType == NETC_ETH_IP_PHYSICAL_SI)
    {
        *SyncState = (boolean)(IP_NETC__ENETC0_SI0->SITSR & NETC_F3_SI0_SITSR_SYNC_MASK);
    }
    else
    {
        status = Netc_Eth_Ip_VsiToPsiMsg(CtrlIndex, NETC_ETH_IP_VSITOPSI_GET_SYNC_STATE, NULL_PTR, (uint16 *) &PSIRspMessage);
        *SyncState = (boolean) PSIRspMessage;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Netc_Eth_Ip_SetSiPhysAddr
 * Description   : Set the MAC addresses of PSI/VSIs from the PSI controller .
 * implements Netc_Eth_Ip_SetSiPhysAddr_Activity
 *END**************************************************************************/
Netc_Eth_Ip_StatusType Netc_Eth_Ip_SetSiPhysAddr( const uint8 CtrlIndex,
                                            const uint8 SiId,
                                            const uint8 *MacAddr
                                                            )
{
    Netc_Eth_Ip_StatusType status = NETC_ETH_IP_STATUS_SUCCESS;

#if (STD_ON == NETC_ETH_IP_DEV_ERROR_DETECT)
    DevAssert(CtrlIndex == NETC_ETH_IP_PSI_INDEX);
    DevAssert(SiId < FEATURE_NETC_ETH_NUMBER_OF_CTRLS);
#endif

    /*Check if the controller is PSI. MAC changing allowed only for PSI */
    if (NETC_ETH_IP_PHYSICAL_SI == Netc_Eth_Ip_apxState[CtrlIndex]->SiType)
    {
        /*VSI MAC change*/
        if(NETC_ETH_IP_PHYSICAL_SI != Netc_Eth_Ip_apxState[SiId]->SiType)
        {
            /* For the VSIs write the MAC address in the PSIaMAR0 and PSIaMAR1 registers. */
            IP_NETC__ENETC0_BASE->NUM_SI[SiId].PSIPMAR0 =  (uint32)MacAddr[0U] | \
                                                            ((uint32)MacAddr[1U] << 8U ) | \
                                                            ((uint32)MacAddr[2U] << 16U) | \
                                                            ((uint32)MacAddr[3U] << 24U);
            IP_NETC__ENETC0_BASE->NUM_SI[SiId].PSIPMAR1 =  (uint32)MacAddr[4U] | \
                                                            ((uint32)MacAddr[5U] << 8U);
        }
        else
        {
            /* For the PSI the MAC address will be configured both for the ENETC Port and for the PSI0 */
            /* Configure the port primary MAC address */
            IP_NETC__ENETC0_PORT->PMAR0 = (uint32)MacAddr[0U] | \
                                            ((uint32)MacAddr[1U] << 8U)  | \
                                            ((uint32)MacAddr[2U] << 16U) | \
                                            ((uint32)MacAddr[3U] << 24U);
            IP_NETC__ENETC0_PORT->PMAR1 = (uint32)MacAddr[4U] | \
                                            ((uint32)MacAddr[5U] << 8U);
        }

    }
    else
    {
        status = NETC_ETH_IP_STATUS_UNSUPPORTED;
    }


    return status;
}

#define ETH_43_NETC_STOP_SEC_CODE
#include "Eth_43_NETC_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
