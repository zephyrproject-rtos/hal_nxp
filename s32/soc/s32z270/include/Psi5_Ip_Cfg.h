/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PSI5_IP_CFG_H
#define PSI5_IP_CFG_H

/**
*   @file Psi5_Ip_Cfg.h
*
*   @addtogroup PSI5_IP PSI5 IPV Driver
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
#include "Mcal.h"

#include "Psi5_Ip_Init_PBcfg.h"

#include "Psi5_Ip_Types.h"
#include "Psi5_Ip_Cfg_Defines.h"
#if (STD_ON == PSI5_IP_DMA_IS_USED)
#include "CDD_Mcl.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PSI5_IP_CFG_VENDOR_ID                    43
#define PSI5_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define PSI5_IP_CFG_AR_RELEASE_MINOR_VERSION     7
#define PSI5_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define PSI5_IP_CFG_SW_MAJOR_VERSION             2
#define PSI5_IP_CFG_SW_MINOR_VERSION             0
#define PSI5_IP_CFG_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Psi5_Ip_Cfg.h and Psi5_Ip_Init_PBcfg.h header file are of the same vendor */
#if (PSI5_IP_CFG_VENDOR_ID != PSI5_IP_INIT_PBCFG_VENDOR_ID)
    #error "Psi5_Ip_Cfg.h and Psi5_Ip_Init_PBcfg.h have different vendor ids"
#endif
/* Check if Psi5_Ip_Cfg.h and Psi5_Ip_Init_PBcfg.h header file are of the same Autosar version */
#if ((PSI5_IP_CFG_AR_RELEASE_MAJOR_VERSION    != PSI5_IP_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
    (PSI5_IP_CFG_AR_RELEASE_MINOR_VERSION    != PSI5_IP_INIT_PBCFG_AR_RELEASE_MINOR_VERSION) || \
    (PSI5_IP_CFG_AR_RELEASE_REVISION_VERSION != PSI5_IP_INIT_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Psi5_Ip_Cfg.h and Psi5_Ip_Init_PBcfg.h are different"
#endif
/* Check if Psi5_Ip_Cfg.h and Psi5_Ip_Init_PBcfg.h header file are of the same software version */
#if ((PSI5_IP_CFG_SW_MAJOR_VERSION != PSI5_IP_INIT_PBCFG_SW_MAJOR_VERSION) || \
    (PSI5_IP_CFG_SW_MINOR_VERSION != PSI5_IP_INIT_PBCFG_SW_MINOR_VERSION) || \
    (PSI5_IP_CFG_SW_PATCH_VERSION != PSI5_IP_INIT_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Psi5_Ip_Cfg.h and Psi5_Ip_Init_PBcfg.h are different"
#endif
    
/* Checks against Psi5_Ip_Types.h */
#if (PSI5_IP_CFG_VENDOR_ID != PSI5_IP_TYPES_VENDOR_ID)
    #error "Psi5_Ip_Cfg.h and Psi5_Ip_Types.h have different vendor ids"
#endif
#if ((PSI5_IP_CFG_AR_RELEASE_MAJOR_VERSION    != PSI5_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
    (PSI5_IP_CFG_AR_RELEASE_MINOR_VERSION    != PSI5_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
    (PSI5_IP_CFG_AR_RELEASE_REVISION_VERSION != PSI5_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Psi5_Ip.h and Psi5_Ip_Types.h are different"
#endif
#if ((PSI5_IP_CFG_SW_MAJOR_VERSION != PSI5_IP_TYPES_SW_MAJOR_VERSION) || \
    (PSI5_IP_CFG_SW_MINOR_VERSION != PSI5_IP_TYPES_SW_MINOR_VERSION) || \
    (PSI5_IP_CFG_SW_PATCH_VERSION != PSI5_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Psi5_Ip_Cfg.h and Psi5_Ip_Types.h are different"
#endif

/* Checks against Psi5_Ip_Cfg_Defines.h */
#if (PSI5_IP_CFG_VENDOR_ID != PSI5_IP_CFG_DEFINES_VENDOR_ID)
    #error "Psi5_Ip_Cfg.h and Psi5_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if ((PSI5_IP_CFG_AR_RELEASE_MAJOR_VERSION    != PSI5_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
    (PSI5_IP_CFG_AR_RELEASE_MINOR_VERSION    != PSI5_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
    (PSI5_IP_CFG_AR_RELEASE_REVISION_VERSION != PSI5_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Psi5_Ip_Cfg.h and Psi5_Ip_Cfg_Defines.h are different"
#endif
#if ((PSI5_IP_CFG_SW_MAJOR_VERSION != PSI5_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
    (PSI5_IP_CFG_SW_MINOR_VERSION != PSI5_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
    (PSI5_IP_CFG_SW_PATCH_VERSION != PSI5_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Psi5_Ip_Cfg.h and Psi5_Ip_Cfg_Defines.h are different"
#endif

#if (STD_ON == PSI5_IP_DMA_IS_USED)
/* Check Psi5_Ip_Cfg.h against CDD_Mcl.h file versions */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((PSI5_IP_CFG_AR_RELEASE_MAJOR_VERSION != CDD_MCL_AR_RELEASE_MAJOR_VERSION) || \
        (PSI5_IP_CFG_AR_RELEASE_MINOR_VERSION != CDD_MCL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Psi5_Ip_Cfg.h and CDD_Mcl.h are different"
    #endif
#endif
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief   Collection of all configuration structures declarations.
*/
#define PSI5_IP_CONFIG_EXT
/**
* @brief   Switches the Psi5_Ip_Transmit() API ON or OFF.
*
* @api
*
*/
#define PSI5_IP_TRANSMIT_API                         (STD_ON)

/**
* @brief   Switches the Psi5_Ip_GetTransmissionStatus() API ON or OFF.
*
* @api
*
*/
#define PSI5_IP_GET_TRANSMISSION_STATUS_API          (STD_ON)

/**
* @brief   Switches the Psi5_Ip_GetPsi5Frame() API ON or OFF.
*
* @api
*
*/
#define PSI5_IP_GET_PSI5_FRAME_API                   (STD_ON)

/**
* @brief   Switches the Psi5_Ip_GetSmcFrame() API ON or OFF.
*
* @api
*
*/
#define PSI5_IP_GET_SMC_FRAME_API                    (STD_ON)

/**
* @brief   Switches the Psi5_Ip_SetGlobalSync() API ON or OFF.
*
* @api
*
*/
#define PSI5_IP_SET_GLOBAL_SYNC_API                  (STD_ON)

/**
* @brief   Switches the Psi5_Ip_SetChannelSync() API ON or OFF.
*
* @api
*
*/
#define PSI5_IP_SET_CHANNEL_SYNC_API                 (STD_ON)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define PSI5_START_SEC_CODE
#include "Psi5_MemMap.h"

#define PSI5_STOP_SEC_CODE
#include "Psi5_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PSI5_IP_CFG_H */

