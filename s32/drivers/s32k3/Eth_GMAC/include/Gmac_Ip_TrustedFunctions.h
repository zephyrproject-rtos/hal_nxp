/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef GMAC_IP_TRUSTEDFUNCTIONS_H
#define GMAC_IP_TRUSTEDFUNCTIONS_H

/**
*   @file
*
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

#include "Gmac_Ip_Device_Registers.h"
#include "Gmac_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GMAC_IP_TRUSTEDFUNCTIONS_VENDOR_ID                    43
#define GMAC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION     4
#define GMAC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION     7
#define GMAC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION  0
#define GMAC_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION             3
#define GMAC_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION             0
#define GMAC_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Checks against Gmac_Ip_Device_Registers.h */
#if (GMAC_IP_TRUSTEDFUNCTIONS_VENDOR_ID != GMAC_IP_DEVICE_REGISTERS_VENDOR_ID)
    #error "Gmac_Ip_TrustedFunctions.h and Gmac_Ip_Device_Registers.h have different vendor ids"
#endif
#if ((GMAC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != GMAC_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (GMAC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != GMAC_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (GMAC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != GMAC_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Gmac_Ip_TrustedFunctions.h and Gmac_Ip_Device_Registers.h are different"
#endif
#if ((GMAC_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != GMAC_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION) || \
     (GMAC_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != GMAC_IP_DEVICE_REGISTERS_SW_MINOR_VERSION) || \
     (GMAC_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != GMAC_IP_DEVICE_REGISTERS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gmac_Ip_TrustedFunctions.h and Gmac_Ip_Device_Registers.h are different"
#endif

/* Checks against Gmac_Ip_Cfg.h */
#if (GMAC_IP_TRUSTEDFUNCTIONS_VENDOR_ID != GMAC_IP_CFG_VENDOR_ID)
    #error "Gmac_Ip_TrustedFunctions.h and Gmac_Ip_Cfg.h have different vendor ids"
#endif
#if (( GMAC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != GMAC_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     ( GMAC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != GMAC_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     ( GMAC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != GMAC_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Gmac_Ip_TrustedFunctions.h and Gmac_Ip_Cfg.h are different"
#endif
#if (( GMAC_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != GMAC_IP_CFG_SW_MAJOR_VERSION) || \
     ( GMAC_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != GMAC_IP_CFG_SW_MINOR_VERSION) || \
     ( GMAC_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != GMAC_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gmac_Ip_TrustedFunctions.h and Gmac_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define ETH_43_GMAC_START_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"

#if (STD_ON == GMAC_SET_USER_ACCESS_ALLOWED_AVAILABLE)
extern void Gmac_Ip_SetUserAccessAllowed(const GMAC_Type *Base);
extern void Gmac_Ip_ClrUserAccessAllowed(const GMAC_Type *Base);
#endif

#define ETH_43_GMAC_STOP_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* GMAC_IP_TRUSTEDFUNCTIONS_H */
