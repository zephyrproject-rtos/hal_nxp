/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32ZE_RTD_2_0_0_D2407_ASR_REL_4_7_REV_0000_20240726
*
*   Copyright 2021-2024 NXP
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef PSI5_S_IP_CFG_H
#define PSI5_S_IP_CFG_H

/**
*   @file Psi5_S_Ip_Cfg.h
*
*   @addtogroup PSI5_S_IP PSI5 IPV Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Psi5_S_Ip_Init_PBcfg.h"

#include "Psi5_S_Ip_Types.h"
#include "Psi5_S_Ip_Cfg_Defines.h"
#if (STD_ON == PSI5_S_IP_DMA_IS_USED)
#include "CDD_Mcl.h"
#include "CDD_Mcl_Cfg.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PSI5_S_IP_CFG_VENDOR_ID                    43
#define PSI5_S_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define PSI5_S_IP_CFG_AR_RELEASE_MINOR_VERSION     7
#define PSI5_S_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define PSI5_S_IP_CFG_SW_MAJOR_VERSION             2
#define PSI5_S_IP_CFG_SW_MINOR_VERSION             0
#define PSI5_S_IP_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks current file and Psi5_S_Ip_Init_PBcfg.h header file are of the same vendor */
#if (PSI5_S_IP_CFG_VENDOR_ID != PSI5_S_IP_INIT_PBCFG_VENDOR_ID)
    #error "Psi5_S_Ip_Cfg.h and Psi5_S_Ip_Init_PBcfg.h have different vendor ids"
#endif
/* Check if current file and Psi5_S_Ip_Init_PBcfg.h header file are of the same Autosar version */
#if ((PSI5_S_IP_CFG_AR_RELEASE_MAJOR_VERSION    != PSI5_S_IP_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
    (PSI5_S_IP_CFG_AR_RELEASE_MINOR_VERSION    != PSI5_S_IP_INIT_PBCFG_AR_RELEASE_MINOR_VERSION) || \
    (PSI5_S_IP_CFG_AR_RELEASE_REVISION_VERSION != PSI5_S_IP_INIT_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Psi5_S_Ip_Cfg.h and Psi5_S_Ip_Init_PBcfg.h are different"
#endif
/* Check if current file and Psi5_S_Ip_Init_PBcfg.h header file are of the same software version */
#if ((PSI5_S_IP_CFG_SW_MAJOR_VERSION != PSI5_S_IP_INIT_PBCFG_SW_MAJOR_VERSION) || \
    (PSI5_S_IP_CFG_SW_MINOR_VERSION != PSI5_S_IP_INIT_PBCFG_SW_MINOR_VERSION) || \
    (PSI5_S_IP_CFG_SW_PATCH_VERSION != PSI5_S_IP_INIT_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Psi5_S_Ip_Cfg.h and Psi5_S_Ip_Init_PBcfg.h are different"
#endif

/* Checks against Psi5_S_Ip_Types.h */
#if (PSI5_S_IP_CFG_VENDOR_ID != PSI5_S_IP_TYPES_VENDOR_ID)
    #error "Psi5_S_Ip_Cfg.h and Psi5_S_Ip_Types.h have different vendor ids"
#endif
#if ((PSI5_S_IP_CFG_AR_RELEASE_MAJOR_VERSION    != PSI5_S_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
    (PSI5_S_IP_CFG_AR_RELEASE_MINOR_VERSION    != PSI5_S_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
    (PSI5_S_IP_CFG_AR_RELEASE_REVISION_VERSION != PSI5_S_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Psi5_S_Ip.h and Psi5_S_Ip_Types.h are different"
#endif
#if ((PSI5_S_IP_CFG_SW_MAJOR_VERSION != PSI5_S_IP_TYPES_SW_MAJOR_VERSION) || \
    (PSI5_S_IP_CFG_SW_MINOR_VERSION != PSI5_S_IP_TYPES_SW_MINOR_VERSION) || \
    (PSI5_S_IP_CFG_SW_PATCH_VERSION != PSI5_S_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Psi5_S_Ip_Cfg.h and Psi5_S_Ip_Types.h are different"
#endif

/* Checks against Psi5_S_Ip_Cfg_Defines.h */
#if (PSI5_S_IP_CFG_VENDOR_ID != PSI5_S_IP_CFG_DEFINES_VENDOR_ID)
    #error "Psi5_S_Ip_Cfg.h and Psi5_S_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if ((PSI5_S_IP_CFG_AR_RELEASE_MAJOR_VERSION    != PSI5_S_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
    (PSI5_S_IP_CFG_AR_RELEASE_MINOR_VERSION    != PSI5_S_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
    (PSI5_S_IP_CFG_AR_RELEASE_REVISION_VERSION != PSI5_S_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Psi5_S_Ip_Cfg.h and Psi5_S_Ip_Cfg_Defines.h are different"
#endif
#if ((PSI5_S_IP_CFG_SW_MAJOR_VERSION != PSI5_S_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
    (PSI5_S_IP_CFG_SW_MINOR_VERSION != PSI5_S_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
    (PSI5_S_IP_CFG_SW_PATCH_VERSION != PSI5_S_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Psi5_S_Ip_Cfg.h and Psi5_S_Ip_Cfg_Defines.h are different"
#endif

#if (STD_ON == PSI5_S_IP_DMA_IS_USED)
/* Check Psi5_S_Ip_Cfg.h against CDD_Mcl.h file versions */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((PSI5_S_IP_CFG_AR_RELEASE_MAJOR_VERSION != CDD_MCL_AR_RELEASE_MAJOR_VERSION) || \
        (PSI5_S_IP_CFG_AR_RELEASE_MINOR_VERSION != CDD_MCL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Psi5_S_Ip_Cfg.h and CDD_Mcl.h are different"
    #endif
#endif
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief    Collection of all configuration structures declarations.
*/
#define PSI5_S_IP_CONFIG_EXT \
    PSI5_S_IP_CONFIG_INIT_PB

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


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PSI5_S_IP_CFG_H */
