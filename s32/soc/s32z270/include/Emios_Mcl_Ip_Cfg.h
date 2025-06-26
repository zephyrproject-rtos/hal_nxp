/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_MCL_IP_CFG_H_
#define EMIOS_MCL_IP_CFG_H_
/**
*   @file Emios_Mcl_Ip_Cfg.h
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
/* Include all variants header files. */
#include "Emios_Mcl_Ip_Init_PBcfg.h"

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_MCL_IP_CFG_VENDOR_ID                       43
#define EMIOS_MCL_IP_CFG_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_MCL_IP_CFG_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_MCL_IP_CFG_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_MCL_IP_CFG_SW_MAJOR_VERSION                2
#define EMIOS_MCL_IP_CFG_SW_MINOR_VERSION                0
#define EMIOS_MCL_IP_CFG_SW_PATCH_VERSION                1
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Emios_Mcl_Ip_Init_PBcfg.h file are of the same vendor */
#if (EMIOS_MCL_IP_CFG_VENDOR_ID != EMIOS_MCL_IP_INIT_PBCFG_VENDOR_ID)
    #error "Emios_Mcl_Ip_Cfg.h and Emios_Mcl_Ip_Init_PBcfg.h have different vendor ids"
#endif

/* Check if header file and Emios_Mcl_Ip_Init_PBcfg.h file are of the same Autosar version */
#if ((EMIOS_MCL_IP_CFG_AR_RELEASE_MAJOR_VERSION != EMIOS_MCL_IP_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_CFG_AR_RELEASE_MINOR_VERSION != EMIOS_MCL_IP_INIT_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_MCL_IP_CFG_AR_RELEASE_REVISION_VERSION != EMIOS_MCL_IP_INIT_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Emios_Mcl_Ip_Cfg.h and Emios_Mcl_Ip_Init_PBcfg.h are different"
#endif

/* Check if header file and Emios_Mcl_Ip_INIT_PBcfg.h file are of the same Software version */
#if ((EMIOS_MCL_IP_CFG_SW_MAJOR_VERSION != EMIOS_MCL_IP_INIT_PBCFG_SW_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_CFG_SW_MINOR_VERSION != EMIOS_MCL_IP_INIT_PBCFG_SW_MINOR_VERSION) || \
     (EMIOS_MCL_IP_CFG_SW_PATCH_VERSION != EMIOS_MCL_IP_INIT_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Emios_Mcl_Ip_Cfg.h and Emios_Mcl_Ip_Init_PBcfg.h are different"
#endif
    
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Enable/Disable EMIOS support from MCL. */
#define EMIOS_IP_IS_AVAILABLE                      STD_ON

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

#endif /* EMIOS_MCL_IP_CFG_H_ */

