/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef GMAC_IP_HW_ACCESS_H
#define GMAC_IP_HW_ACCESS_H

/**
*   @file
*   
*   @internal
*   @addtogroup GMAC_DRIVER GMAC Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gmac_Ip.h"
#include "Gmac_Ip_Device_Registers.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GMAC_IP_HW_ACCESS_VENDOR_ID                    43
#define GMAC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION     4
#define GMAC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION     7
#define GMAC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION  0
#define GMAC_IP_HW_ACCESS_SW_MAJOR_VERSION             3
#define GMAC_IP_HW_ACCESS_SW_MINOR_VERSION             0
#define GMAC_IP_HW_ACCESS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Gmac_Ip.h */
#if (GMAC_IP_HW_ACCESS_VENDOR_ID != GMAC_IP_VENDOR_ID)
    #error "Gmac_Ip_Hw_Access.h and Gmac_Ip.h have different vendor ids"
#endif
#if (( GMAC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION    != GMAC_IP_AR_RELEASE_MAJOR_VERSION) || \
     ( GMAC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION    != GMAC_IP_AR_RELEASE_MINOR_VERSION) || \
     ( GMAC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION != GMAC_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Gmac_Ip_Hw_Access.h and Gmac_Ip.h are different"
#endif
#if (( GMAC_IP_HW_ACCESS_SW_MAJOR_VERSION != GMAC_IP_SW_MAJOR_VERSION) || \
     ( GMAC_IP_HW_ACCESS_SW_MINOR_VERSION != GMAC_IP_SW_MINOR_VERSION) || \
     ( GMAC_IP_HW_ACCESS_SW_PATCH_VERSION != GMAC_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gmac_Ip_Hw_Access.h and Gmac_Ip.h are different"
#endif

/* Checks against Gmac_Ip_Device_Registers.h */
#if (GMAC_IP_HW_ACCESS_VENDOR_ID != GMAC_IP_DEVICE_REGISTERS_VENDOR_ID)
    #error "Gmac_Ip_Hw_Access.h and Gmac_Ip_Device_Registers.h have different vendor ids"
#endif
#if (( GMAC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION    != GMAC_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     ( GMAC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION    != GMAC_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION) || \
     ( GMAC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION != GMAC_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Gmac_Ip_Hw_Access.h and Gmac_Ip_Device_Registers.h are different"
#endif
#if (( GMAC_IP_HW_ACCESS_SW_MAJOR_VERSION != GMAC_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION) || \
     ( GMAC_IP_HW_ACCESS_SW_MINOR_VERSION != GMAC_IP_DEVICE_REGISTERS_SW_MINOR_VERSION) || \
     ( GMAC_IP_HW_ACCESS_SW_PATCH_VERSION != GMAC_IP_DEVICE_REGISTERS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gmac_Ip_Hw_Access.h and Gmac_Ip_Device_Registers.h are different"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Management Frame operation type
 */
typedef enum
{
    GMAC_MMFR_OP_WRITE = 0U,
    GMAC_MMFR_OP_READ
} Gmac_Ip_MmfrOpType;

/*!
 * @brief Management Frame information
 */
typedef struct 
{
    uint8 PhysAddr;
    uint16 PhysReg;
    uint16 MmdAddr;
    Gmac_Ip_MmfrOpType OpFrameType;
    uint16 FrameData;
    boolean SupportedClause45;
} Gmac_Ip_ManagementInfo;

/*******************************************************************************
 * Variables
 ******************************************************************************/
#define ETH_43_GMAC_START_SEC_CONST_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

extern GMAC_Type * const Gmac_apxBases[FEATURE_GMAC_NUM_INSTANCES];

extern Gmac_Ip_ChannelType * const Gmac_apxChBases[FEATURE_GMAC_NUM_INSTANCES][FEATURE_GMAC_NUM_CHANNELS];

extern Gmac_Ip_QueueType * const Gmac_apxQueueBases[FEATURE_GMAC_NUM_INSTANCES][FEATURE_GMAC_NUM_QUEUES];

#define ETH_43_GMAC_STOP_SEC_CONST_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

#define ETH_43_GMAC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

extern Gmac_Ip_StateType *Gmac_apxState[FEATURE_GMAC_NUM_INSTANCES];

#define ETH_43_GMAC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_GMAC_MemMap.h"

/*******************************************************************************
 * API
 ******************************************************************************/
#define ETH_43_GMAC_START_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"

/*!
 * @brief Initializes a starting reference point for timeout
 *
 * @param[out] StartTimeOut    The starting time from which elapsed time is measured
 * @param[out] ElapsedTimeOut  The elapsed time to be passed to GMAC_TimeoutExpired
 * @param[out] TimeoutTicksOut The timeout value (in ticks) to be passed to GMAC_TimeoutExpired
 * @param[in]  TimeoutUs       The timeout value (in microseconds)
 */
void GMAC_StartTimeOut(uint32 *StartTimeOut,
                       uint32 *ElapsedTimeOut,
                       uint32 *TimeoutTicksOut,
                       uint32 TimeoutUs);

/*!
 * @brief Checks for timeout condition.
 *
 * @param[in,out] StartTimeInOut    The starting time from which elapsed time is measured
 * @param[in,out] ElapsedTimeInOut  The accumulated elapsed time from the starting time reference
 * @param[in]     TimeoutTicks      The timeout limit (in ticks)
 */
boolean GMAC_TimeoutExpired(uint32 *StartTimeInOut,
                            uint32 *ElapsedTimeInOut,
                            uint32 TimeoutTicks);

/*!
 * @brief Adds an entry to the hash table filter.
 *
 * @param[in] Base The base address of the module
 * @param[in] Crc The CRC of a hardware address
 */
void GMAC_AddToHashTable(const GMAC_Type * Base,
                         uint32 Crc);

/*!
 * @brief Removes an entry from the hash table filter.
 *
 * @param[in] Base The base address of the module
 * @param[in] Crc The CRC of a hardware address
 */
void GMAC_RemoveFromHashTable(const GMAC_Type * Base,
                              uint32 Crc);

/*!
 * @brief Adds a VLAN tag to the VLAN hash table filter.
 *
 * @param[in] Base The base address of the module
 * @param[in] Crc  The CRC of a VLAN tag
 */
void GMAC_AddVlanToHashTable(GMAC_Type * Base,
                             uint32 Crc);

/*!
 * @brief Removes VLAN tag from the VLAN hash table filter.
 *
 * @param[in] Base The base address of the module
 * @param[in] Crc  The CRC of a VLAN tag
 */
void GMAC_RemoveVlanFromHashTable(GMAC_Type * Base,
                                  uint32 Crc);

/*!
 * @brief Writes an MII management frame.
 *
 * @param[in] Base The base address of the module
 * @param[in] ManageInfo contains some information:
 *  physAddr The address of the PHY
 *  physReg The address of the register to be accessed
 *  MmdAddr For clause 45, selects the device (MMD)
 *  OpFrameType The operation type (read/write)
 *  FrameData Data to be written, ignored if the operation is a read one
 *  SupportedClause45 True if the management frame is a clause 45 one, false for clause 22
 * @param[in] TimeoutUs Timeout for the management operation (in microseconds)
 * @retval GMAC_STATUS_SUCCESS The operation completed successfully.
 * @retval GMAC_STATUS_TIMEOUT The specified timeout expired before completing the operation.
 */
Gmac_Ip_StatusType GMAC_WriteManagementFrame(GMAC_Type * Base,
                                             const Gmac_Ip_ManagementInfo *ManageInfo,
                                             uint32 TimeoutUs);

/*!
 * @brief Reads the data field of a MII management frame.
 *
 * @param[in] base The base address of the module
 * @return The read data
 */
static inline uint16 GMAC_ReadManagementFrameData(const GMAC_Type * Base)
{
    return (uint16)(Base->MAC_MDIO_DATA & GMAC_MAC_MDIO_DATA_GD_MASK);
}

#if (FEATURE_GMAC_ASP_ALL || FEATURE_GMAC_ASP_ECC)
/*!
 * @brief Handler for GMAC safety interrupts.
 *
 * This handler invokes the installed callback, if available, and clears the
 * interrupt flags.
 *
 * @param[in] Instance Instance number
 */
void GMAC_SafetyIRQHandler(uint8 Instance);
#endif

/*!
 * @brief Handler for GMAC common interrupts.
 *
 * This handler invokes the installed callback, if available, and clears the
 * interrupt flags.
 *
 * @param[in] Instance Instance number
 */
void GMAC_CommonIRQHandler(uint8 Instance);

/*!
 * @brief Handler for GMAC receive interrupts.
 *
 * This handler invokes the installed callback, if available, and clears the
 * interrupt flags.
 *
 * @param[in] Instance Instance number
 * @param[in] Channel  Channel number
 */
void GMAC_RxIRQHandler(uint8 Instance,
                       uint8 Channel);

/*!
 * @brief Handler for GMAC transmit interrupts.
 *
 * This handler invokes the installed callback, if available, and clears the
 * interrupt flags.
 *
 * @param[in] Instance Instance number
 * @param[in] Channel Channel number
 */
void GMAC_TxIRQHandler(uint8 Instance,
                       uint8 Channel);

/*!
 * @brief Gets the power state
 *
 * @param[in] Base   The base address of the module
 * @return  The power state of the controller
 */
Gmac_Ip_PowerStateType GMAC_GetPowerState(const GMAC_Type * Base);

/*!
 * @brief Sets the power state
 *
 * @param[in] base       The base address of the module
 * @param[in] powerState The power state to transition into
 */
void GMAC_SetPowerState(GMAC_Type * Base, Gmac_Ip_PowerStateType PowerState);

/*!
 * @brief Sets the speed of the MII interface.
 *
 * @param[in] base  The base address of the module
 * @param[in] speed The MII speed
 */
void GMAC_SetSpeed(GMAC_Type * Base, Gmac_Ip_SpeedType Speed);

/*!
 * @brief Sets the Tx scheduling algorithm.
 *
 * @param[in] base    The base address of the module
 * @param[in] channel Channel number
 */
void GMAC_SetSchedAlg(GMAC_Type * Base, Gmac_Ip_TxSchedAlgoType SchedAlgo);

/*!
 * @brief Sets the weight or idle slope credit for a specific Tx Queue.
 *
 * @param[in] queueBase  The base address of the Tx Queue
 * @param[in] weight     Queue weight or idle slope credit
 */
void GMAC_SetTxQueueQuantumWeight(Gmac_Ip_QueueType * QueueBase,
                                  uint32 Weight);

/*!
 * @brief Sets the send slope, high credit and low credit for a specific Tx Queue
 *
 * @param[in] queueBase         The base address of the Tx Queue
 * @param[in] sendSlopeCredit   Queue send slope credit
 * @param[in] highCredit        Queue high credit limit
 * @param[in] lowCredit         Queue low credit limit
 */
void GMAC_SetTxQueueCreditBasedShaper(Gmac_Ip_QueueType * QueueBase,
                                      uint32 SendSlopeCredit,
                                      uint32 HighCredit,
                                      sint32 LowCredit);

/*!
 * @brief Sets the operation mode for a Tx Queue.
 *
 * @param[in] queueBase  The base address of the Tx Queue
 * @param[in] queueMode  The operation mode of the Tx Queue
 * @param[in] queueSize  Queue size in blocks of 256 bytes
 */
void GMAC_SetTxQueueOperationMode(Gmac_Ip_QueueType * QueueBase,
                                  Gmac_Ip_OperationModeType QueueMode,
                                  uint32 QueueSize);

/*!
 * @brief Enable store and forward for a specific Tx Queue.
 * @param[in] queueBase  The base address of the Tx Queue
 */
void GMAC_SetTxStoreAndForward(Gmac_Ip_QueueType * QueueBase);

/*!
 * @brief Sets the Tx threshold value.
 *
 * @param[in] queueBase       The base address of the Tx Queue
 * @param[in] thresholdValue  Threshold value
 */
void GMAC_SetTxThreshold(Gmac_Ip_QueueType * QueueBase,
                         Gmac_Ip_TxThresholdType ThresholdValue);

/*!
 * @brief Enables the given Rx Queue for generic traffic with the given VLAN priorities.
 *
 * @param[in] base         The base address of the module
 * @param[in] priorityMask VLAN priorities
 * @param[in] queueNum     Number of the queue
 */
void GMAC_EnableRxQueue(GMAC_Type * Base,
                        uint8 PriorityMask,
                        uint8 QueueNum);

/*!
 * @brief Sets the operation mode for an Rx Queue
 *
 * @param[in] queueBase  The base address of the Rx Queue
 * @param[in] queueSize  Queue size in blocks of 256 bytes
 */
void GMAC_SetRxQueueOperationMode(Gmac_Ip_QueueType * QueueBase,
                                  uint32 QueueSize);

/*!
 * @brief Sets the DMA channel mapping for Rx queues.
 *
 * @param[in] base       The base address of the module
 * @param[in] queuesNum  Number of queues
 */
void GMAC_SetRxQueuesDmaChMap(GMAC_Type * Base,
                              uint8 QueuesNum);

/*!
 * @brief Sets VLAN Tag inverse match.
 *
 * @param[in] base The base address of the module
 * @param[in] enable   Enables/Disables VLAN Tag inverse filtering
 */
void GMAC_SetVlanTagInvMatch(GMAC_Type * Base, boolean Enable);

/*!
 * @brief Sets MAC_VLAN_Tag_Data register with Rx matching relevant data.
 *
 * @param[in] base     The base address of the module
 * @param[in] enable   Enables/Disables VLAN Tag inverse filtering
 */
void GMAC_SetVlanTagDataRxMatch(GMAC_Type * Base,
                                boolean EnInnerVlanMatch,
                                boolean EnSvlanMatch,
                                boolean DisVlanTypeMatch,
                                boolean En12bitMatch);
                                
#if (FEATURE_GMAC_VLAN_RX_FILTERS_NUM > 0U)
/*!
 * @brief Read a VLAN Tag Rx filter.
 *
 * @param[in]  base               The base address of the module
 * @param[in]  filterIdx          Index of the VLAN filter
 * @param[in]  timeoutUs          Timeout value (in microseconds)
 * @param[out] vlanTag            Vlan Tag configured for the selcted Rx filter
 * @retval GMAC_STATUS_SUCCESS    The filter was successfully read.
 * @retval GMAC_STATUS_TIMEOUT    The filter could not be read before expiration
 *                                of timeout.
 */
Gmac_Ip_StatusType GMAC_ReadVlanTagRxFilter(GMAC_Type * Base,
                                           uint8 FilterIdx,
                                           uint16 * VlanTag);
#endif

#define ETH_43_GMAC_STOP_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* GMAC_IP_HW_ACCESS_H */
