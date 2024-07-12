/*
 * Copyright 2021-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef I3C_IP_CFG_H
#define I3C_IP_CFG_H

/**
*   @file
*
*   @addtogroup i3c_ip_config I3c IPL Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "I3c_Ip_Init_PBcfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I3C_IP_VENDOR_ID_CFG                       43
#define I3C_IP_AR_RELEASE_MAJOR_VERSION_CFG        4
#define I3C_IP_AR_RELEASE_MINOR_VERSION_CFG        7
#define I3C_IP_AR_RELEASE_REVISION_VERSION_CFG     0
#define I3C_IP_SW_MAJOR_VERSION_CFG                1
#define I3C_IP_SW_MINOR_VERSION_CFG                0
#define I3C_IP_SW_PATCH_VERSION_CFG                0
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I3c_Ip_Init_PBcfg.h file are of the same vendor */
#if (I3C_IP_VENDOR_ID_CFG != I3C_IP_VENDOR_ID_INIT_PBCFG)
    #error "I3c_Ip_Cfg.h and I3c_Ip_Init_PBcfg.h have different vendor IDs"
#endif

/* Check if current file and I3c_Ip_Init_PBcfg.h file are of the same Autosar version */
#if ((I3C_IP_AR_RELEASE_MAJOR_VERSION_CFG     != I3C_IP_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG) || \
     (I3C_IP_AR_RELEASE_MINOR_VERSION_CFG     != I3C_IP_AR_RELEASE_MINOR_VERSION_INIT_PBCFG) || \
     (I3C_IP_AR_RELEASE_REVISION_VERSION_CFG  != I3C_IP_AR_RELEASE_REVISION_VERSION_INIT_PBCFG))
    #error "AutoSar Version Numbers of I3c_Ip_Cfg.h and I3c_Ip_Init_PBcfg.h are different"
#endif

/* Check if current file and I3c_Ip_Init_PBcfg.h file are of the same software version */
#if ((I3C_IP_SW_MAJOR_VERSION_CFG != I3C_IP_SW_MAJOR_VERSION_INIT_PBCFG) || \
     (I3C_IP_SW_MINOR_VERSION_CFG != I3C_IP_SW_MINOR_VERSION_INIT_PBCFG) || \
     (I3C_IP_SW_PATCH_VERSION_CFG != I3C_IP_SW_PATCH_VERSION_INIT_PBCFG))
    #error "Software Version Numbers of I3c_Ip_Cfg.h and I3c_Ip_Init_PBcfg.h are different"
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

/** @} */

#endif /* I3C_IP_CFG_H */

