/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SIUL2_ICU_IP_CFG_H
#define SIUL2_ICU_IP_CFG_H

/**
 *   @file    Siul2_Icu_Ip_Cfg.h
 *   @version 0.9.0
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
#include "StandardTypes.h"
#include "Siul2_Icu_Ip_SA_Init_PBcfg.h"
/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define SIUL2_ICU_IP_CFG_VENDOR_ID                       43
#define SIUL2_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION        4
#define SIUL2_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION        7
#define SIUL2_ICU_IP_CFG_AR_RELEASE_REVISION_VERSION     0
#define SIUL2_ICU_IP_CFG_SW_MAJOR_VERSION                0
#define SIUL2_ICU_IP_CFG_SW_MINOR_VERSION                9
#define SIUL2_ICU_IP_CFG_SW_PATCH_VERSION                0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and StandardTypes.h file are of the same Autosar version */
    #if ((SIUL2_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SIUL2_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Siul2_Icu_Ip_Cfg.h and StandardTypes.h are different"
    #endif
#endif
#if (SIUL2_ICU_IP_CFG_VENDOR_ID != SIUL2_ICU_IP_SA_INIT_PBCFG_VENDOR_ID)
    #error "Siul2_Icu_Ip_Cfg.h and Siul2_Icu_Ip_SA_INIT_PBcfg.h have different vendor IDs"
#endif

/* Check if  header file and Siul2_Icu_Ip_SA_Init_PBcfg.h file are of the same Autosar version */
#if ((SIUL2_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION != SIUL2_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION != SIUL2_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (SIUL2_ICU_IP_CFG_AR_RELEASE_REVISION_VERSION != SIUL2_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Siul2_Icu_Ip_Cfg.h and Siul2_Icu_Ip_SA_Init_PBcfg.h are different"
#endif

/* Check if header file and Siul2_Icu_Ip_SA_Init_PBcfg.h file are of the same Software version */
#if ((SIUL2_ICU_IP_CFG_SW_MAJOR_VERSION != SIUL2_ICU_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_CFG_SW_MINOR_VERSION != SIUL2_ICU_IP_SA_INIT_PBCFG_SW_MINOR_VERSION) || \
     (SIUL2_ICU_IP_CFG_SW_PATCH_VERSION != SIUL2_ICU_IP_SA_INIT_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Siul2_Icu_Ip_Cfg.h and Siul2_Icu_Ip_SA_Init_PBcfg.h are different"
#endif
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief SIUL2 external ISRs configured for ICU channels. */
#define SIUL2_0_ICU_EIRQ_SINGLE_INT (STD_ON)
#define SIUL2_1_ICU_EIRQ_SINGLE_INT (STD_ON)
#define SIUL2_4_ICU_EIRQ_SINGLE_INT (STD_ON)
#define SIUL2_5_ICU_EIRQ_SINGLE_INT (STD_ON)

/* Macro used to export generated configuration. */
#define SIUL2_ICU_CONFIG_EXT \
        SIUL2_ICU_CONFIG_SA_INIT_PB \


#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* SIUL2_ICU_IP_CFG_H */
