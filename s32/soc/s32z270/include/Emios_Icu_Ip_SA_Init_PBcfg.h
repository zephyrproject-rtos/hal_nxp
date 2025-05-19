/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_ICU_IP_SA_INIT_PBCFG_H
#define EMIOS_ICU_IP_SA_INIT_PBCFG_H

/**
 *   @file    Emios_Icu_Ip_SA_Init_PBCfg.h
 *   @version 2.0.1
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the ICU module.
 *   @details Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup emios_icu_ip EMIOS IPL
 *   @{
 */

#ifdef __cplusplus
extern "C"{
#endif

 /*==================================================================================================
 *                                         INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 *================================================================================================*/
#include "Emios_Icu_Ip_Types.h"
/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define EMIOS_ICU_IP_SA_INIT_PBCFG_VENDOR_ID                    43
#define EMIOS_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION     4
#define EMIOS_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION     7
#define EMIOS_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION  0
#define EMIOS_ICU_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION             2
#define EMIOS_ICU_IP_SA_INIT_PBCFG_SW_MINOR_VERSION             0
#define EMIOS_ICU_IP_SA_INIT_PBCFG_SW_PATCH_VERSION             1

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (EMIOS_ICU_IP_SA_INIT_PBCFG_VENDOR_ID != EMIOS_ICU_IP_TYPES_VENDOR_ID)
    #error "Emios_Icu_Ip_SA_Init_PBcfg.h and Emios_Icu_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((EMIOS_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION    != EMIOS_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION    != EMIOS_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION != EMIOS_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Icu_Ip_SA_Init_PBcfg.h and Emios_Icu_Ip_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((EMIOS_ICU_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION != EMIOS_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (EMIOS_ICU_IP_SA_INIT_PBCFG_SW_MINOR_VERSION != EMIOS_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (EMIOS_ICU_IP_SA_INIT_PBCFG_SW_PATCH_VERSION != EMIOS_ICU_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Icu_Ip_SA_Init_PBcfg.h and Emios_Icu_Ip_Types.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (STD_ON == EMIOS_ICU_IP_USED)

#define EMIOS_ICU_CONFIG_SA_INIT_PB

#endif  /* EMIOS_ICU_IP_USED */

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

#endif /* EMIOS_ICU_IP_SA_INIT_PBCFG_H */

