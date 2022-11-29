/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file    Mru_Ip.h
*   
*
*   @brief   MRU IP driver header file.
*   @details MRU IP driver header file.

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
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MRU_IP_VENDOR_ID                       43
#define MRU_IP_AR_RELEASE_MAJOR_VERSION        4
#define MRU_IP_AR_RELEASE_MINOR_VERSION        7
#define MRU_IP_AR_RELEASE_REVISION_VERSION     0
#define MRU_IP_SW_MAJOR_VERSION                0
#define MRU_IP_SW_MINOR_VERSION                9
#define MRU_IP_SW_PATCH_VERSION                0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Mru_Ip.h and Mru_Ip_Types.h are of the same vendor */
#if (MRU_IP_VENDOR_ID != MRU_IP_TYPES_VENDOR_ID)
    #error "Mru_Ip.h and Mru_Ip_Types.h have different vendor ids"
#endif
/* Check if Mru_Ip.h file and Mru_Ip_Types.h file are of the same Autosar version */
#if ((MRU_IP_AR_RELEASE_MAJOR_VERSION != MRU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MRU_IP_AR_RELEASE_MINOR_VERSION != MRU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MRU_IP_AR_RELEASE_REVISION_VERSION != MRU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mru_Ip.h and Mru_Ip_Types.h are different"
#endif
#if ((MRU_IP_SW_MAJOR_VERSION != MRU_IP_TYPES_SW_MAJOR_VERSION) || \
     (MRU_IP_SW_MINOR_VERSION != MRU_IP_TYPES_SW_MINOR_VERSION) || \
     (MRU_IP_SW_PATCH_VERSION != MRU_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Mru_Ip.h and Mru_Ip_Types.h are different"
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


void Mru_Ip_IrqHandler(uint8 InstanceId, uint8 IntGroupId);

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* MRU_IP_H */

/** @} */

