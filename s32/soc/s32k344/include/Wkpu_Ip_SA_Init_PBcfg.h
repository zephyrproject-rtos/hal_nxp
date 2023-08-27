/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef WKPU_IP_SA_INIT_PBCFG_H
#define WKPU_IP_SA_INIT_PBCFG_H

/**
 *   @file    Wkpu_Ip_SA_Init_PBCfg.c
 *   @version 3.0.0
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the Icu module
 *   @details Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup wkpu_icu_ip WKPU IPL
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
#include "Wkpu_Ip_Types.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define WKPU_IP_SA_INIT_PBCFG_VENDOR_ID                     43
#define WKPU_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define WKPU_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define WKPU_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define WKPU_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION              3
#define WKPU_IP_SA_INIT_PBCFG_SW_MINOR_VERSION              0
#define WKPU_IP_SA_INIT_PBCFG_SW_PATCH_VERSION              0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (WKPU_IP_SA_INIT_PBCFG_VENDOR_ID != WKPU_IP_TYPES_VENDOR_ID)
    #error "Wkpu_Ip_SA_INIT_PBcfg.h and Wkpu_Ip_Types.h have different vendor IDs"
#endif

/* Check if source file and ICU header file are of the same AutoSar version */
#if ((WKPU_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION != WKPU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WKPU_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION != WKPU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WKPU_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION != WKPU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wkpu_Ip_SA_INIT_PBcfg.h and Wkpu_Ip_Types.h are different"
#endif

/* Check if source file and ICU header file are of the same Software version */
#if ((WKPU_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION != WKPU_IP_TYPES_SW_MAJOR_VERSION) || \
     (WKPU_IP_SA_INIT_PBCFG_SW_MINOR_VERSION != WKPU_IP_TYPES_SW_MINOR_VERSION) || \
     (WKPU_IP_SA_INIT_PBCFG_SW_PATCH_VERSION != WKPU_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Wkpu_Ip_SA_INIT_PBcfg.h and Wkpu_Ip_Types.h are different"
#endif
/*==================================================================================================
 *                                       GLOBAL CONSTANTS
 *================================================================================================*/
#if (STD_ON == WKPU_IP_USED)
#define WKPU_CONFIG_SA_INIT_PB  \
    extern const Wkpu_Ip_ChannelConfigType Wkpu_Ip_ChannelConfig_PB_Init[64U]; \
    extern Wkpu_Ip_NmiCfgType Wkpu_Ip_NMIConfig_PB_Init[1U]; \
    extern const Wkpu_Ip_IrqConfigType Wkpu_Ip_Config_PB_Init; \

#endif /* WKPU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* WKPU_IP_SA_INIT_PBCFG_H */
