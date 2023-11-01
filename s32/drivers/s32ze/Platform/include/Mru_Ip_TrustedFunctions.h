/*
 * Copyright 2021-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef MRU_IP_TRUSTEDFUNCTIONS_H
#define MRU_IP_TRUSTEDFUNCTIONS_H

/**
*   @file Mru_Ip_TrustedFunctions.h
*
*   @addtogroup Mru_Ip Mru IPV Driver
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Mru_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_MPU_R52_IP_TRUSTEDFUNCTIONS_VENDOR_ID                      43
#define CDD_PLATFORM_MPU_R52_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION       4
#define CDD_PLATFORM_MPU_R52_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION       7
#define CDD_PLATFORM_MPU_R52_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION    0
#define CDD_PLATFORM_MPU_R52_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION               1
#define CDD_PLATFORM_MPU_R52_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION               0
#define CDD_PLATFORM_MPU_R52_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Mpu_R52_Ip_TrustedFunctions.h and Mpu_R52_Ip_Cfg.h are of the same vendor */
#if (CDD_PLATFORM_MPU_R52_IP_TRUSTEDFUNCTIONS_VENDOR_ID != CDD_PLATFORM_MRU_IP_TYPES_VENDOR_ID)
    #error "Mpu_R52_Ip_TrustedFunctions.h and Mru_Ip_Types.h have different vendor ids"
#endif
/* Check if Mpu_R52_Ip_TrustedFunctions.h file and Mpu_R52_Ip_Cfg.h file are of the same Autosar version */
#if ((CDD_PLATFORM_MPU_R52_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_MRU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_MPU_R52_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_MRU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_MPU_R52_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_MRU_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Mpu_R52_Ip_TrustedFunctions.h and Mru_Ip_Types.h are different"
#endif
/* Check if Mpu_R52_Ip_TrustedFunctions.h file and Mpu_R52_Ip_Cfg.h file are of the same Software version */
#if ((CDD_PLATFORM_MPU_R52_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != CDD_PLATFORM_MRU_IP_TYPES_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_MPU_R52_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != CDD_PLATFORM_MRU_IP_TYPES_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_MPU_R52_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != CDD_PLATFORM_MRU_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mpu_R52_Ip_TrustedFunctions.h and Mru_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#if defined(__cplusplus)
extern "C" {
#endif

#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

#if ((STD_ON == MRU_IP_ENABLE_USER_MODE_SUPPORT) && (defined (MCAL_ENABLE_USER_MODE_SUPPORT)))
/**
* @brief            MRU peripheral initialization.
* @details          The function initialize the MRU Unit specified in the configuration.
*
* @param[in]        HWUnitConfigPtr -  pointer to the specified MRU Unit configuration.
*/
extern void Mru_Ip_Init_Privileged(const Mru_Ip_ConfigType *HWUnitConfigPtr);

/**
* @brief            MRU transmission.
* @details          This function writes the data to Mailboxes using the channel specified.
*
* @param[in]        TransmitChCfgPtr - pointer to the channel configuration where contains list of mailboxes to be written.
* @param[in]        TxBufferPtr - pointer to transmit buffer.
*
* @return           MRU_IP_STATUS_SUCCESS: Transmission command has been accepted.
*                   MRU_IP_STATUS_FAIL: Transmission command has not been accepted.
*/
extern Mru_Ip_StatusType Mru_Ip_Transmit_Privileged( const Mru_Ip_TransmitChannelType *TransmitChCfgPtr,
                                                     const uint32 *TxBufferPtr
                                                   );

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
*/
extern Mru_Ip_StatusType Mru_Ip_ReadMailbox_Privileged( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr,
                                                        uint32 *RxBufferPtr,
                                                        uint32 Timeout
                                                      );

/**
* @brief   Get mailbox status.
* @details This function get mailbox status of a specific channel.
*
* @param[in]      ReceiveChCfgPtr       Pointer for the receive channel configuration.
*
* @return Mru_Ip_MBStatusType
* @retval MRU_IP_MAILBOX_INACTIVE       Mailbox status is inactive
* @retval MRU_IP_MAILBOX_ACTIVE         Mailbox status is active
*/
extern Mru_Ip_MBStatusType Mru_Ip_GetMailboxStatus_Privileged( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr );

#endif /* MRU_IP_ENABLE_USER_MODE_SUPPORT == STD_ON */
#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#if defined(__cplusplus)
}
#endif /* __cplusplus*/

/*! @} */

#endif /* MRU_IP_TRUSTEDFUNCTIONS_H */
