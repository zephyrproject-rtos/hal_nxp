/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_ICU_IP_CFG_H
#define EMIOS_ICU_IP_CFG_H

/**
 *   @file    Emios_Icu_Ip_Cfg.h
 *   @version 3.0.0
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the ICU module.
 *   @details Contains the information that will be exported by the module, as requested by AUTOSAR.
 *
 *   @addtogroup emios_icu_ip EMIOS IPL
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
/* Include all variants header files. */
#include "Emios_Icu_Ip_SA_Init_PBcfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_ICU_IP_CFG_VENDOR_ID                    43
#define EMIOS_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define EMIOS_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION     7
#define EMIOS_ICU_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define EMIOS_ICU_IP_CFG_SW_MAJOR_VERSION             3
#define EMIOS_ICU_IP_CFG_SW_MINOR_VERSION             0
#define EMIOS_ICU_IP_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#if (STD_ON == EMIOS_ICU_IP_USED)
#if (EMIOS_ICU_IP_CFG_VENDOR_ID != EMIOS_ICU_IP_SA_INIT_PBCFG_VENDOR_ID)
    #error "Emios_Icu_Ip_Cfg.h and Emios_Icu_Ip_SA_INIT_PBcfg.h have different vendor IDs"
#endif

/* Check if  header file and Emios_Icu_Ip_SA_Init_PBcfg.h file are of the same Autosar version */
#if ((EMIOS_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION != EMIOS_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION != EMIOS_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_ICU_IP_CFG_AR_RELEASE_REVISION_VERSION != EMIOS_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Icu_Ip_Cfg.h and Emios_Icu_Ip_SA_Init_PBcfg.h are different"
#endif

/* Check if header file and Emios_Icu_Ip_SA_Init_PBcfg.h file are of the same Software version */
#if ((EMIOS_ICU_IP_CFG_SW_MAJOR_VERSION != EMIOS_ICU_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION) || \
     (EMIOS_ICU_IP_CFG_SW_MINOR_VERSION != EMIOS_ICU_IP_SA_INIT_PBCFG_SW_MINOR_VERSION) || \
     (EMIOS_ICU_IP_CFG_SW_PATCH_VERSION != EMIOS_ICU_IP_SA_INIT_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Icu_Ip_Cfg.h and Emios_Icu_Ip_SA_Init_PBcfg.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_0_USED
    #define EMIOS_0_CH_0_USED
#else
    #error "EMIOS_0_CH_0 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_1_USED
    #define EMIOS_0_CH_1_USED
#else
    #error "EMIOS_0_CH_1 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_2_USED
    #define EMIOS_0_CH_2_USED
#else
    #error "EMIOS_0_CH_2 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_3_USED
    #define EMIOS_0_CH_3_USED
#else
    #error "EMIOS_0_CH_3 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_4_USED
    #define EMIOS_0_CH_4_USED
#else
    #error "EMIOS_0_CH_4 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_5_USED
    #define EMIOS_0_CH_5_USED
#else
    #error "EMIOS_0_CH_5 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_6_USED
    #define EMIOS_0_CH_6_USED
#else
    #error "EMIOS_0_CH_6 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_7_USED
    #define EMIOS_0_CH_7_USED
#else
    #error "EMIOS_0_CH_7 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_8_USED
    #define EMIOS_0_CH_8_USED
#else
    #error "EMIOS_0_CH_8 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_9_USED
    #define EMIOS_0_CH_9_USED
#else
    #error "EMIOS_0_CH_9 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_10_USED
    #define EMIOS_0_CH_10_USED
#else
    #error "EMIOS_0_CH_10 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_11_USED
    #define EMIOS_0_CH_11_USED
#else
    #error "EMIOS_0_CH_11 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_12_USED
    #define EMIOS_0_CH_12_USED
#else
    #error "EMIOS_0_CH_12 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_13_USED
    #define EMIOS_0_CH_13_USED
#else
    #error "EMIOS_0_CH_13 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_14_USED
    #define EMIOS_0_CH_14_USED
#else
    #error "EMIOS_0_CH_14 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_15_USED
    #define EMIOS_0_CH_15_USED
#else
    #error "EMIOS_0_CH_15 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_16_USED
    #define EMIOS_0_CH_16_USED
#else
    #error "EMIOS_0_CH_16 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_17_USED
    #define EMIOS_0_CH_17_USED
#else
    #error "EMIOS_0_CH_17 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_18_USED
    #define EMIOS_0_CH_18_USED
#else
    #error "EMIOS_0_CH_18 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_19_USED
    #define EMIOS_0_CH_19_USED
#else
    #error "EMIOS_0_CH_19 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_20_USED
    #define EMIOS_0_CH_20_USED
#else
    #error "EMIOS_0_CH_20 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_21_USED
    #define EMIOS_0_CH_21_USED
#else
    #error "EMIOS_0_CH_21 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_0_CH_22_USED
    #define EMIOS_0_CH_22_USED
#else
    #error "EMIOS_0_CH_22 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_0_USED
    #define EMIOS_1_CH_0_USED
#else
    #error "EMIOS_1_CH_0 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_1_USED
    #define EMIOS_1_CH_1_USED
#else
    #error "EMIOS_1_CH_1 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_2_USED
    #define EMIOS_1_CH_2_USED
#else
    #error "EMIOS_1_CH_2 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_3_USED
    #define EMIOS_1_CH_3_USED
#else
    #error "EMIOS_1_CH_3 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_4_USED
    #define EMIOS_1_CH_4_USED
#else
    #error "EMIOS_1_CH_4 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_5_USED
    #define EMIOS_1_CH_5_USED
#else
    #error "EMIOS_1_CH_5 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_6_USED
    #define EMIOS_1_CH_6_USED
#else
    #error "EMIOS_1_CH_6 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_7_USED
    #define EMIOS_1_CH_7_USED
#else
    #error "EMIOS_1_CH_7 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_8_USED
    #define EMIOS_1_CH_8_USED
#else
    #error "EMIOS_1_CH_8 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_9_USED
    #define EMIOS_1_CH_9_USED
#else
    #error "EMIOS_1_CH_9 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_10_USED
    #define EMIOS_1_CH_10_USED
#else
    #error "EMIOS_1_CH_10 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_11_USED
    #define EMIOS_1_CH_11_USED
#else
    #error "EMIOS_1_CH_11 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_12_USED
    #define EMIOS_1_CH_12_USED
#else
    #error "EMIOS_1_CH_12 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_13_USED
    #define EMIOS_1_CH_13_USED
#else
    #error "EMIOS_1_CH_13 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_14_USED
    #define EMIOS_1_CH_14_USED
#else
    #error "EMIOS_1_CH_14 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_15_USED
    #define EMIOS_1_CH_15_USED
#else
    #error "EMIOS_1_CH_15 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_16_USED
    #define EMIOS_1_CH_16_USED
#else
    #error "EMIOS_1_CH_16 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_17_USED
    #define EMIOS_1_CH_17_USED
#else
    #error "EMIOS_1_CH_17 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_18_USED
    #define EMIOS_1_CH_18_USED
#else
    #error "EMIOS_1_CH_18 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_19_USED
    #define EMIOS_1_CH_19_USED
#else
    #error "EMIOS_1_CH_19 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_20_USED
    #define EMIOS_1_CH_20_USED
#else
    #error "EMIOS_1_CH_20 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_21_USED
    #define EMIOS_1_CH_21_USED
#else
    #error "EMIOS_1_CH_21 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_1_CH_22_USED
    #define EMIOS_1_CH_22_USED
#else
    #error "EMIOS_1_CH_22 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_0_USED
    #define EMIOS_2_CH_0_USED
#else
    #error "EMIOS_2_CH_0 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_1_USED
    #define EMIOS_2_CH_1_USED
#else
    #error "EMIOS_2_CH_1 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_2_USED
    #define EMIOS_2_CH_2_USED
#else
    #error "EMIOS_2_CH_2 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_3_USED
    #define EMIOS_2_CH_3_USED
#else
    #error "EMIOS_2_CH_3 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_4_USED
    #define EMIOS_2_CH_4_USED
#else
    #error "EMIOS_2_CH_4 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_5_USED
    #define EMIOS_2_CH_5_USED
#else
    #error "EMIOS_2_CH_5 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_6_USED
    #define EMIOS_2_CH_6_USED
#else
    #error "EMIOS_2_CH_6 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_7_USED
    #define EMIOS_2_CH_7_USED
#else
    #error "EMIOS_2_CH_7 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_8_USED
    #define EMIOS_2_CH_8_USED
#else
    #error "EMIOS_2_CH_8 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_9_USED
    #define EMIOS_2_CH_9_USED
#else
    #error "EMIOS_2_CH_9 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_10_USED
    #define EMIOS_2_CH_10_USED
#else
    #error "EMIOS_2_CH_10 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_11_USED
    #define EMIOS_2_CH_11_USED
#else
    #error "EMIOS_2_CH_11 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_12_USED
    #define EMIOS_2_CH_12_USED
#else
    #error "EMIOS_2_CH_12 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_13_USED
    #define EMIOS_2_CH_13_USED
#else
    #error "EMIOS_2_CH_13 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_14_USED
    #define EMIOS_2_CH_14_USED
#else
    #error "EMIOS_2_CH_14 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_15_USED
    #define EMIOS_2_CH_15_USED
#else
    #error "EMIOS_2_CH_15 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_16_USED
    #define EMIOS_2_CH_16_USED
#else
    #error "EMIOS_2_CH_16 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_17_USED
    #define EMIOS_2_CH_17_USED
#else
    #error "EMIOS_2_CH_17 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_18_USED
    #define EMIOS_2_CH_18_USED
#else
    #error "EMIOS_2_CH_18 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_19_USED
    #define EMIOS_2_CH_19_USED
#else
    #error "EMIOS_2_CH_19 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_20_USED
    #define EMIOS_2_CH_20_USED
#else
    #error "EMIOS_2_CH_20 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_21_USED
    #define EMIOS_2_CH_21_USED
#else
    #error "EMIOS_2_CH_21 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
#ifndef EMIOS_2_CH_22_USED
    #define EMIOS_2_CH_22_USED
#else
    #error "EMIOS_2_CH_22 channel cannot be used by ICU. Instance locked by another driver!"
#endif
    
#define EMIOS_ICU_CONFIG_EXT \
        EMIOS_ICU_CONFIG_SA_INIT_PB \

#endif  /* EMIOS_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EMIOS_ICU_IP_CFG_H */

