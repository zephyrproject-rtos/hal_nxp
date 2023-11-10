/*
 * Copyright 2021-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file    Mru_Ip.h
*
*   @defgroup   MRU_IP_DRIVER Mru Ip Driver
*   @ingroup    Platform
*
*   @addtogroup MRU_IP_DRIVER Mru Ip Driver
*   @{
*/ 

#ifndef MRU_IP_H
#define MRU_IP_H

#ifdef __cplusplus
extern "C"{
#endif



/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mru_Ip_Types.h"
#include "Mru_Ip_DeviceRegisters.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_MRU_IP_VENDOR_ID                       43
#define CDD_PLATFORM_MRU_IP_AR_RELEASE_MAJOR_VERSION        4
#define CDD_PLATFORM_MRU_IP_AR_RELEASE_MINOR_VERSION        7
#define CDD_PLATFORM_MRU_IP_AR_RELEASE_REVISION_VERSION     0
#define CDD_PLATFORM_MRU_IP_SW_MAJOR_VERSION                1
#define CDD_PLATFORM_MRU_IP_SW_MINOR_VERSION                0
#define CDD_PLATFORM_MRU_IP_SW_PATCH_VERSION                0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Mru_Ip.h and Mru_Ip_Types.h are of the same vendor */
#if (CDD_PLATFORM_MRU_IP_VENDOR_ID != CDD_PLATFORM_MRU_IP_TYPES_VENDOR_ID)
    #error "Mru_Ip.h and Mru_Ip_Types.h have different vendor ids"
#endif
/* Check if Mru_Ip.h file and Mru_Ip_Types.h file are of the same Autosar version */
#if ((CDD_PLATFORM_MRU_IP_AR_RELEASE_MAJOR_VERSION != CDD_PLATFORM_MRU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_MRU_IP_AR_RELEASE_MINOR_VERSION != CDD_PLATFORM_MRU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_MRU_IP_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_MRU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mru_Ip.h and Mru_Ip_Types.h are different"
#endif
#if ((CDD_PLATFORM_MRU_IP_SW_MAJOR_VERSION != CDD_PLATFORM_MRU_IP_TYPES_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_MRU_IP_SW_MINOR_VERSION != CDD_PLATFORM_MRU_IP_TYPES_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_MRU_IP_SW_PATCH_VERSION != CDD_PLATFORM_MRU_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Mru_Ip.h and Mru_Ip_Types.h are different"
#endif

/* Check if Mru_Ip.h and Mru_Ip_DeviceRegisters.h are of the same vendor */
#if (CDD_PLATFORM_MRU_IP_VENDOR_ID != CDD_PLATFORM_MRU_IP_DEVICE_REGISTERS_VENDOR_ID)
    #error "Mru_Ip.h and Mru_Ip_Types.h have different vendor ids"
#endif
/* Check if Mru_Ip.h file and Mru_Ip_DeviceRegisters.h file are of the same Autosar version */
#if ((CDD_PLATFORM_MRU_IP_AR_RELEASE_MAJOR_VERSION != CDD_PLATFORM_MRU_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_MRU_IP_AR_RELEASE_MINOR_VERSION != CDD_PLATFORM_MRU_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_MRU_IP_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_MRU_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mru_Ip.h and Mru_Ip_DeviceRegisters.h are different"
#endif
#if ((CDD_PLATFORM_MRU_IP_SW_MAJOR_VERSION != CDD_PLATFORM_MRU_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_MRU_IP_SW_MINOR_VERSION != CDD_PLATFORM_MRU_IP_DEVICE_REGISTERS_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_MRU_IP_SW_PATCH_VERSION != CDD_PLATFORM_MRU_IP_DEVICE_REGISTERS_SW_PATCH_VERSION))
#error "Software Version Numbers of Mru_Ip.h and Mru_Ip_DeviceRegisters.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*==================================================================================================
*                                            ENUMS
==================================================================================================*/
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
/**
* @brief   Export the configurations.
*/
MRU_IP_CONFIG_EXT

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

/**
* @brief            MRU peripheral initialization.
* @details          The function initialize the MRU Unit specified in the configuration.
*
* @param[in]        HWUnitConfigPtr -  pointer to the specified MRU Unit configuration.
*
* @implements Mru_Ip_Init_Activity
*/
void Mru_Ip_Init(const Mru_Ip_ConfigType *HWUnitConfigPtr);

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
Mru_Ip_StatusType Mru_Ip_Transmit(const Mru_Ip_TransmitChannelType *TransmitChCfgPtr,
                     const uint32 *TxBufferPtr
                    );
/*================================================================================================*/
/**
* @brief            MRU Read Mailbox.
* @details          This function read the data from Mailboxes using the channel specified.
*
* @param[in]        ReceiveChCfgPtr - Pointer for the receive channel configuration.
* @param[in]        DataBufferPtr - Buffer pointer to receive data.
* @param[in]        Timeout - Timeout value (Unit depend to timeout method).
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
                    );
/*================================================================================================*/
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
Mru_Ip_MBStatusType Mru_Ip_GetMailboxStatus( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr );

void Mru_Ip_IrqHandler(uint8 InstanceId, uint8 IntGroupId);

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* MRU_IP_H */

/** @} */

