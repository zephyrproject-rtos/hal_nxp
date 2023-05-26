/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SIUL2_ICU_IP_CFG_H
#define SIUL2_ICU_IP_CFG_H

/**
 *   @file    Siul2_Icu_Ip_Cfg.h
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
#include "Std_Types.h"
#include "Siul2_Icu_Ip_SA_Init_PBcfg.h"
/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define SIUL2_ICU_IP_CFG_VENDOR_ID                       43
#define SIUL2_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION        4
#define SIUL2_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION        7
#define SIUL2_ICU_IP_CFG_AR_RELEASE_REVISION_VERSION     0
#define SIUL2_ICU_IP_CFG_SW_MAJOR_VERSION                3
#define SIUL2_ICU_IP_CFG_SW_MINOR_VERSION                0
#define SIUL2_ICU_IP_CFG_SW_PATCH_VERSION                0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((SIUL2_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SIUL2_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Siul2_Icu_Ip_Cfg.h and Std_Types.h are different"
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
#if (STD_ON == SIUL2_ICU_IP_USED)
/** @brief SIUL2 external ISRs configured for ICU channels. */
#define IRQ_ICU_SINGLE_INTERRUPT STD_OFF
#define SIUL2_ICU_IRQ_CH_0_ISR_USED
#define SIUL2_ICU_IRQ_CH_1_ISR_USED
#define SIUL2_ICU_IRQ_CH_2_ISR_USED
#define SIUL2_ICU_IRQ_CH_3_ISR_USED
#define SIUL2_ICU_IRQ_CH_4_ISR_USED
#define SIUL2_ICU_IRQ_CH_5_ISR_USED
#define SIUL2_ICU_IRQ_CH_6_ISR_USED
#define SIUL2_ICU_IRQ_CH_7_ISR_USED
#define SIUL2_ICU_IRQ_CH_8_ISR_USED
#define SIUL2_ICU_IRQ_CH_9_ISR_USED
#define SIUL2_ICU_IRQ_CH_10_ISR_USED
#define SIUL2_ICU_IRQ_CH_11_ISR_USED
#define SIUL2_ICU_IRQ_CH_12_ISR_USED
#define SIUL2_ICU_IRQ_CH_13_ISR_USED
#define SIUL2_ICU_IRQ_CH_14_ISR_USED
#define SIUL2_ICU_IRQ_CH_15_ISR_USED
#define SIUL2_ICU_IRQ_CH_16_ISR_USED
#define SIUL2_ICU_IRQ_CH_17_ISR_USED
#define SIUL2_ICU_IRQ_CH_18_ISR_USED
#define SIUL2_ICU_IRQ_CH_19_ISR_USED
#define SIUL2_ICU_IRQ_CH_20_ISR_USED
#define SIUL2_ICU_IRQ_CH_21_ISR_USED
#define SIUL2_ICU_IRQ_CH_22_ISR_USED
#define SIUL2_ICU_IRQ_CH_23_ISR_USED
#define SIUL2_ICU_IRQ_CH_24_ISR_USED
#define SIUL2_ICU_IRQ_CH_25_ISR_USED
#define SIUL2_ICU_IRQ_CH_26_ISR_USED
#define SIUL2_ICU_IRQ_CH_27_ISR_USED
#define SIUL2_ICU_IRQ_CH_28_ISR_USED
#define SIUL2_ICU_IRQ_CH_29_ISR_USED
#define SIUL2_ICU_IRQ_CH_30_ISR_USED
#define SIUL2_ICU_IRQ_CH_31_ISR_USED

/* Macro used to export generated configuration. */
#define SIUL2_ICU_CONFIG_EXT \
        SIUL2_ICU_CONFIG_SA_INIT_PB \

#endif /* SIUL2_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* SIUL2_ICU_IP_CFG_H */
