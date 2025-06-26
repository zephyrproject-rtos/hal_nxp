/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef MRU_IP_TRUSTEDFUNCTIONS_H
#define MRU_IP_TRUSTEDFUNCTIONS_H

/**
*   @file Mru_Ip_TrustedFunctions.h
*
*   @addtogroup MRU_IP_DRIVER Mru Ip Driver
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
#define CDD_PLATFORM_MPU_R52_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION               2
#define CDD_PLATFORM_MPU_R52_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION               0
#define CDD_PLATFORM_MPU_R52_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION               1

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

#ifdef PLATFORM_IP_ENABLE_MRU
#if (PLATFORM_IP_ENABLE_MRU == STD_ON)

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
#if (STD_ON == MRU_IP_CHANNEL_RESET_API)
/**
* @brief            MRU Reset transmit channel.
* @details          This function reset mailboxs status which are used by transmit channel in configuration.
*
* @param[in]        TransmitChCfgPtr - Pointer for the transmit channel configuration.
*
* @return           void
*
*/
extern void Mru_Ip_ResetTransmitChannel_Privileged( const Mru_Ip_TransmitChannelType *TransmitChCfgPtr);
/**
* @brief            MRU Reset receive channel.
* @details          This function reset mailboxs status which are used by receive channel in configuration.
*
* @param[in]        ReceiveChCfgPtr - Pointer for the receive channel configuration.
*
* @return           void
*
*/
extern void Mru_Ip_ResetReceiveChannel_Privileged( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr );
#endif

#if (STD_ON == MRU_IP_INSTANCE_RESET_API)
/**
* @brief            Reset Mru Instance.
* @details          This function reset all mailbox status in a Mru instance.
*
* @param[in]        ResetInsCfgPtr – Reset Mru instance configuration pointer.
*
* @return           void
*
*/
extern void Mru_Ip_ResetInstance_Privileged( const Mru_Ip_ResetInstanceType *ResetInsCfgPtr );
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
*/
extern Mru_Ip_StatusType Mru_Ip_EnableChannel_Privileged( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr);
#endif

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
*/
extern Mru_Ip_StatusType Mru_Ip_DisableChannel_Privileged( const Mru_Ip_ReceiveChannelType *ReceiveChCfgPtr);
#endif

#endif /* MRU_IP_ENABLE_USER_MODE_SUPPORT == STD_ON */
#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#endif /* PLATFORM_IP_ENABLE_MRU == STD_ON)*/
#endif /* PLATFORM_IP_ENABLE_MRU */

#if defined(__cplusplus)
}
#endif /* __cplusplus*/

/*! @} */

#endif /* MRU_IP_TRUSTEDFUNCTIONS_H */
