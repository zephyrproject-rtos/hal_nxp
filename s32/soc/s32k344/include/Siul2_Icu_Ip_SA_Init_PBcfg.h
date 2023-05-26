/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SIUL2_ICU_IP_SA_INIT_PBCFG_H
#define SIUL2_ICU_IP_SA_INIT_PBCFG_H

/**
 *   @file    Siul2_Icu_Ip_SA_Init_PBCfg.h
 *   @version 3.0.0
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the Icu module
 *   @details Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup siul2_icu_ip SIUL2 IPL
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
#include "Siul2_Icu_Ip_Types.h"
/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define SIUL2_ICU_IP_SA_INIT_PBCFG_VENDOR_ID                     43
#define SIUL2_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define SIUL2_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define SIUL2_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define SIUL2_ICU_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION              3
#define SIUL2_ICU_IP_SA_INIT_PBCFG_SW_MINOR_VERSION              0
#define SIUL2_ICU_IP_SA_INIT_PBCFG_SW_PATCH_VERSION              0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (SIUL2_ICU_IP_SA_INIT_PBCFG_VENDOR_ID != SIUL2_ICU_IP_TYPES_VENDOR_ID)
    #error "Siul2_Icu_Ip_SA_Init_PBcfg.h and Siul2_Icu_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((SIUL2_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION    != SIUL2_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION    != SIUL2_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SIUL2_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION != SIUL2_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Siul2_Icu_Ip_SA_Init_PBcfg.h and Siul2_Icu_Ip_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((SIUL2_ICU_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION != SIUL2_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_SA_INIT_PBCFG_SW_MINOR_VERSION != SIUL2_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (SIUL2_ICU_IP_SA_INIT_PBCFG_SW_PATCH_VERSION != SIUL2_ICU_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Siul2_Icu_Ip_SA_Init_PBcfg.h and Siul2_Icu_Ip_Types.h are different"
#endif
/*==================================================================================================
 *                                       GLOBAL CONSTANTS
 *================================================================================================*/
#if (STD_ON == SIUL2_ICU_IP_USED)
#define SIUL2_ICU_CONFIG_SA_INIT_PB  \
    extern const Siul2_Icu_Ip_ChannelConfigType Siul2_Icu_Ip_0_ChannelConfig_PB_Init[32U]; \
    extern const Siul2_Icu_Ip_InstanceConfigType Siul2_Icu_Ip_0_InstanceConfig_PB_Init; \
    extern const Siul2_Icu_Ip_ConfigType Siul2_Icu_Ip_0_Config_PB_Init; \

#endif /* SIUL2_ICU_IP_USED */
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SIUL2_ICU_IP_PBCFG_SA_INIT_H */
