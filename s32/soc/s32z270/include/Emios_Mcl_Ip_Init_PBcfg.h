/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_MCL_IP_INIT_PBCFG_H
#define EMIOS_MCL_IP_INIT_PBCFG_H
    /**
*   @file Emios_Mcl_Ip_INIT_PBcfg.h
*
*   @version 2.0.1
*
*   @brief   AUTOSAR Mcl - MCL driver header file.
*   @details 
*
*   @addtogroup MCL_DRIVER MCL Driver
*   @{
*/
#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Emios_Mcl_Ip_Types.h"

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_MCL_IP_INIT_PBCFG_MODULE_ID                     255
#define EMIOS_MCL_IP_INIT_PBCFG_VENDOR_ID                     43
#define EMIOS_MCL_IP_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define EMIOS_MCL_IP_INIT_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define EMIOS_MCL_IP_INIT_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define EMIOS_MCL_IP_INIT_PBCFG_SW_MAJOR_VERSION              2
#define EMIOS_MCL_IP_INIT_PBCFG_SW_MINOR_VERSION              0
#define EMIOS_MCL_IP_INIT_PBCFG_SW_PATCH_VERSION              1
    /*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (EMIOS_MCL_IP_INIT_PBCFG_VENDOR_ID != EMIOS_MCL_IP_TYPES_VENDOR_ID)
    #error "Emios_Mcl_Ip_INIT_PBcfg.h and Emios_Mcl_Ip_Types.h have different vendor ids"
#endif

/* Check if  header file and Emios_Mcl_Ip_Types.h file are of the same Autosar version */
#if ((EMIOS_MCL_IP_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION != EMIOS_MCL_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_INIT_PBCFG_AR_RELEASE_MINOR_VERSION != EMIOS_MCL_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_MCL_IP_INIT_PBCFG_AR_RELEASE_REVISION_VERSION != EMIOS_MCL_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Mcl_Ip_INIT_PBcfg.h and Emios_Mcl_Ip_Types.h are different"
#endif

/* Check if header file and Emios_Mcl_Ip_Types.h file are of the same Software version */
#if ((EMIOS_MCL_IP_INIT_PBCFG_SW_MAJOR_VERSION != EMIOS_MCL_IP_TYPES_SW_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_INIT_PBCFG_SW_MINOR_VERSION != EMIOS_MCL_IP_TYPES_SW_MINOR_VERSION) || \
     (EMIOS_MCL_IP_INIT_PBCFG_SW_PATCH_VERSION != EMIOS_MCL_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Mcl_Ip_INIT_PBcfg.h and Emios_Mcl_Ip_Types.h are different"
#endif
    /*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcl_MemMap.h"


/* Emios instance configuration of global parameters */
extern const Emios_Ip_GlobalConfigType Emios_Ip_0_GlobalConfig;

/* EMIOS configuration structure used for initialization. */
extern const Emios_Mcl_Ip_ConfigType Emios_Mcl_Ip_0_Config;

#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcl_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif

