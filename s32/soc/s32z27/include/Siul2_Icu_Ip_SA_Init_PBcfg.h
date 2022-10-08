/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SIUL2_ICU_IP_SA_INIT_PBCFG_H
#define SIUL2_ICU_IP_SA_INIT_PBCFG_H

/**
 *   @file         Siul2_Icu_Ip_PBCfg.h
 *   @version 0.8.0
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

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define SIUL2_ICU_IP_SA_INIT_PBCFG_VENDOR_ID                     43
#define SIUL2_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define SIUL2_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION      4
#define SIUL2_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define SIUL2_ICU_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION              0
#define SIUL2_ICU_IP_SA_INIT_PBCFG_SW_MINOR_VERSION              8
#define SIUL2_ICU_IP_SA_INIT_PBCFG_SW_PATCH_VERSION              0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL CONSTANTS
 *================================================================================================*/
#define SIUL2_ICU_CONFIG_SA_INIT_PB  \
    extern const Siul2_Icu_Ip_ChannelConfigType Siul2_Icu_Ip_0_ChannelConfig_PB_Init[1U]; \
    extern const Siul2_Icu_Ip_InstanceConfigType Siul2_Icu_Ip_0_InstanceConfig_PB_Init; \
    extern const Siul2_Icu_Ip_ConfigType Siul2_Icu_Ip_0_Config_PB_Init; \
    extern const Siul2_Icu_Ip_ChannelConfigType Siul2_Icu_Ip_1_ChannelConfig_PB_Init[1U]; \
    extern const Siul2_Icu_Ip_InstanceConfigType Siul2_Icu_Ip_1_InstanceConfig_PB_Init; \
    extern const Siul2_Icu_Ip_ConfigType Siul2_Icu_Ip_1_Config_PB_Init; \
    extern const Siul2_Icu_Ip_ChannelConfigType Siul2_Icu_Ip_4_ChannelConfig_PB_Init[1U]; \
    extern const Siul2_Icu_Ip_InstanceConfigType Siul2_Icu_Ip_4_InstanceConfig_PB_Init; \
    extern const Siul2_Icu_Ip_ConfigType Siul2_Icu_Ip_4_Config_PB_Init; \
    extern const Siul2_Icu_Ip_ChannelConfigType Siul2_Icu_Ip_5_ChannelConfig_PB_Init[1U]; \
    extern const Siul2_Icu_Ip_InstanceConfigType Siul2_Icu_Ip_5_InstanceConfig_PB_Init; \
    extern const Siul2_Icu_Ip_ConfigType Siul2_Icu_Ip_5_Config_PB_Init; \

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SIUL2_ICU_IP_PBCFG_SA_INIT_H */

