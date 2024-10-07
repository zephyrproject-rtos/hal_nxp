/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SRX_IP_CFG_H
#define SRX_IP_CFG_H

/**
*   @file    Srx_Ip_Cfg.h
*
*   @version 2.0.1
*
*   @brief   AUTOSAR Sent - module interface
*
*   @addtogroup SENT_DRIVER
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
#include "Srx_Ip_Types.h"
#include "Srx_Ip_Init_PBcfg.h"
#include "S32Z2_SRX.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @file           Srx_Ip_Cfg.h
*/
#define SRX_IP_CFG_VENDOR_ID                     43
#define SRX_IP_CFG_AR_RELEASE_MAJOR_VERSION      4
#define SRX_IP_CFG_AR_RELEASE_MINOR_VERSION      7
#define SRX_IP_CFG_AR_RELEASE_REVISION_VERSION   0
#define SRX_IP_CFG_SW_MAJOR_VERSION              2
#define SRX_IP_CFG_SW_MINOR_VERSION              0
#define SRX_IP_CFG_SW_PATCH_VERSION              1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Srx_Ip_Init_PBcfg.h */
#if (SRX_IP_CFG_VENDOR_ID != SRX_IP_PBCFG_INIT_VENDOR_ID)
    #error "Srx_Ip_Cfg.h and Srx_Ip_Init_PBcfg.h have different vendor ids"
#endif
#if ((SRX_IP_CFG_AR_RELEASE_MAJOR_VERSION    != SRX_IP_PBCFG_INIT_AR_RELEASE_MAJOR_VERSION) || \
     (SRX_IP_CFG_AR_RELEASE_MINOR_VERSION    != SRX_IP_PBCFG_INIT_AR_RELEASE_MINOR_VERSION) || \
     (SRX_IP_CFG_AR_RELEASE_REVISION_VERSION != SRX_IP_PBCFG_INIT_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Srx_Ip_Cfg.h and Srx_Ip_Init_PBcfg.h are different"
#endif
#if ((SRX_IP_CFG_SW_MAJOR_VERSION != SRX_IP_PBCFG_INIT_SW_MAJOR_VERSION) || \
     (SRX_IP_CFG_SW_MINOR_VERSION != SRX_IP_PBCFG_INIT_SW_MINOR_VERSION) || \
     (SRX_IP_CFG_SW_PATCH_VERSION != SRX_IP_PBCFG_INIT_SW_PATCH_VERSION))
    #error "Software Version Numbers of Srx_Ip_Cfg.h and Srx_Ip_Init_PBcfg.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((SRX_IP_CFG_AR_RELEASE_MAJOR_VERSION  != MCAL_AR_RELEASE_MAJOR_VERSION) || \
           (SRX_IP_CFG_AR_RELEASE_MINOR_VERSION  != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Srx_Ip_Cfg.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SRX_IP_CFG_H */


