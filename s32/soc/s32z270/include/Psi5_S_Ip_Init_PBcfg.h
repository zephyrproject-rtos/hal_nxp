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
#ifndef PSI5_S_IP_INIT_PBCFG_H
#define PSI5_S_IP_INIT_PBCFG_H

/**
*   @file Psi5_S_Ip_PBcfg.h
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
#include "Psi5_S_Ip_Types.h"

/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PSI5_S_IP_INIT_PBCFG_VENDOR_ID                      43
#define PSI5_S_IP_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION       4
#define PSI5_S_IP_INIT_PBCFG_AR_RELEASE_MINOR_VERSION       7
#define PSI5_S_IP_INIT_PBCFG_AR_RELEASE_REVISION_VERSION    0
#define PSI5_S_IP_INIT_PBCFG_SW_MAJOR_VERSION               2
#define PSI5_S_IP_INIT_PBCFG_SW_MINOR_VERSION               0
#define PSI5_S_IP_INIT_PBCFG_SW_PATCH_VERSION               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Psi5_S_Ip_Types.h header file are of the same vendor */
#if (PSI5_S_IP_INIT_PBCFG_VENDOR_ID != PSI5_S_IP_TYPES_VENDOR_ID)
    #error "Psi5_S_Ip_INIT_PBcfg.h and Psi5_S_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Psi5_S_Ip_Types.h header file are of the same Autosar version */
#if ((PSI5_S_IP_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION    != PSI5_S_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
    (PSI5_S_IP_INIT_PBCFG_AR_RELEASE_MINOR_VERSION    != PSI5_S_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
    (PSI5_S_IP_INIT_PBCFG_AR_RELEASE_REVISION_VERSION != PSI5_S_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Psi5_S_Ip_INIT_PBcfg.h and Psi5_S_Ip_Types.h are different"
#endif
/* Check if current file and Psi5_S_Ip_Types.h header file are of the same software version */
#if ((PSI5_S_IP_INIT_PBCFG_SW_MAJOR_VERSION != PSI5_S_IP_TYPES_SW_MAJOR_VERSION) || \
    (PSI5_S_IP_INIT_PBCFG_SW_MINOR_VERSION != PSI5_S_IP_TYPES_SW_MINOR_VERSION) || \
    (PSI5_S_IP_INIT_PBCFG_SW_PATCH_VERSION != PSI5_S_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Psi5_S_Ip_INIT_PBcfg.h and Psi5_S_Ip_Types.h are different"
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

#define PSI5_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Psi5_MemMap.h"
#define PSI5_S_IP_CONFIG_INIT_PB \
    extern const Psi5_S_Ip_ConfigType Psi5_S_Ip_Config_Init;
#define PSI5_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Psi5_MemMap.h"

/*==================================================================================================
                                        FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/**@}*/

#endif    /* PSI5_S_IP_INIT_PBCFG_H */
