/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PSI5_IP_INIT_PBCFG_H
#define PSI5_IP_INIT_PBCFG_H

/**
*   @file Psi5_Ip_Init_PBcfg.h
*
*   @addtogroup PSI5_IP PSI5 IPV Driver
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
#include "Psi5_Ip_Types.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PSI5_IP_INIT_PBCFG_VENDOR_ID                    43
#define PSI5_IP_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION     4
#define PSI5_IP_INIT_PBCFG_AR_RELEASE_MINOR_VERSION     7
#define PSI5_IP_INIT_PBCFG_AR_RELEASE_REVISION_VERSION  0
#define PSI5_IP_INIT_PBCFG_SW_MAJOR_VERSION             2
#define PSI5_IP_INIT_PBCFG_SW_MINOR_VERSION             0
#define PSI5_IP_INIT_PBCFG_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Psi5_Ip_Types.h header file are of the same vendor */
#if (PSI5_IP_INIT_PBCFG_VENDOR_ID != PSI5_IP_TYPES_VENDOR_ID)
    #error "Psi5_Ip_INIT_PBcfg.h and Psi5_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Psi5_Ip_Types.h header file are of the same Autosar version */
#if ((PSI5_IP_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION    != PSI5_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
    (PSI5_IP_INIT_PBCFG_AR_RELEASE_MINOR_VERSION    != PSI5_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
    (PSI5_IP_INIT_PBCFG_AR_RELEASE_REVISION_VERSION != PSI5_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Psi5_Ip_INIT_PBcfg.h and Psi5_Ip_Types.h are different"
#endif
/* Check if current file and Psi5_Ip_Types.h header file are of the same software version */
#if ((PSI5_IP_INIT_PBCFG_SW_MAJOR_VERSION != PSI5_IP_TYPES_SW_MAJOR_VERSION) || \
    (PSI5_IP_INIT_PBCFG_SW_MINOR_VERSION != PSI5_IP_TYPES_SW_MINOR_VERSION) || \
    (PSI5_IP_INIT_PBCFG_SW_PATCH_VERSION != PSI5_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Psi5_Ip_INIT_PBcfg.h and Psi5_Ip_Types.h are different"
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

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/**@}*/

#endif /* PSI5_IP_INIT_PBCFG_H */

