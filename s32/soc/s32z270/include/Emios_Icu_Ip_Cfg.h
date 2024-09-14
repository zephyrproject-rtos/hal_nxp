/*
 * Copyright 2021-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_ICU_IP_CFG_H
#define EMIOS_ICU_IP_CFG_H

/**
 *   @file    Emios_Icu_Ip_Cfg.h
 *   @version 2.0.0
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
#define EMIOS_ICU_IP_CFG_SW_MAJOR_VERSION             2
#define EMIOS_ICU_IP_CFG_SW_MINOR_VERSION             0
#define EMIOS_ICU_IP_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU configuration header file are of the same vendor */
#if (EMIOS_ICU_IP_CFG_VENDOR_ID != EMIOS_ICU_IP_SA_INIT_PBCFG_VENDOR_ID)
    #error "Emios_Icu_Ip_Cfg.h and Emios_Icu_Ip_SA_INIT_PBcfg.h have different vendor IDs"
#endif
/* Check if header file and Icu configuration header file are of the same Autosar version */
#if ((EMIOS_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION != EMIOS_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION != EMIOS_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_ICU_IP_CFG_AR_RELEASE_REVISION_VERSION != EMIOS_ICU_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Icu_Ip_Cfg.h and Emios_Icu_Ip_SA_Init_PBcfg.h are different"
#endif
/* Check if header file and Icu configuration header file are of the same software version */
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
#if (STD_ON == EMIOS_ICU_IP_USED)
#ifndef ICU_EMIOS_0_CH_0_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_0_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_0_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_0_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_0_USED
    #define EMIOS_0_CH_0_USED
#else
    #error "EMIOS_0_CH_0 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_1_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_1_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_1_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_1_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_1_USED
    #define EMIOS_0_CH_1_USED
#else
    #error "EMIOS_0_CH_1 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_2_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_2_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_2_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_2_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_2_USED
    #define EMIOS_0_CH_2_USED
#else
    #error "EMIOS_0_CH_2 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_3_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_3_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_3_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_3_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_3_USED
    #define EMIOS_0_CH_3_USED
#else
    #error "EMIOS_0_CH_3 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_4_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_4_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_4_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_4_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_4_USED
    #define EMIOS_0_CH_4_USED
#else
    #error "EMIOS_0_CH_4 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_5_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_5_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_5_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_5_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_5_USED
    #define EMIOS_0_CH_5_USED
#else
    #error "EMIOS_0_CH_5 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_6_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_6_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_6_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_6_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_6_USED
    #define EMIOS_0_CH_6_USED
#else
    #error "EMIOS_0_CH_6 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_7_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_7_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_7_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_7_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_7_USED
    #define EMIOS_0_CH_7_USED
#else
    #error "EMIOS_0_CH_7 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_16_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_16_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_16_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_16_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_16_USED
    #define EMIOS_0_CH_16_USED
#else
    #error "EMIOS_0_CH_16 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_17_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_17_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_17_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_17_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_17_USED
    #define EMIOS_0_CH_17_USED
#else
    #error "EMIOS_0_CH_17 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_18_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_18_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_18_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_18_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_18_USED
    #define EMIOS_0_CH_18_USED
#else
    #error "EMIOS_0_CH_18 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_19_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_19_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_19_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_19_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_19_USED
    #define EMIOS_0_CH_19_USED
#else
    #error "EMIOS_0_CH_19 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_20_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_20_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_20_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_20_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_20_USED
    #define EMIOS_0_CH_20_USED
#else
    #error "EMIOS_0_CH_20 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_21_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_21_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_21_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_21_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_21_USED
    #define EMIOS_0_CH_21_USED
#else
    #error "EMIOS_0_CH_21 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_22_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_22_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_22_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_22_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_22_USED
    #define EMIOS_0_CH_22_USED
#else
    #error "EMIOS_0_CH_22 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_23_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_23_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_23_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_23_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_23_USED
    #define EMIOS_0_CH_23_USED
#else
    #error "EMIOS_0_CH_23 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_24_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_24_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_24_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_24_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_24_USED
    #define EMIOS_0_CH_24_USED
#else
    #error "EMIOS_0_CH_24 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_25_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_25_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_25_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_25_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_25_USED
    #define EMIOS_0_CH_25_USED
#else
    #error "EMIOS_0_CH_25 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_26_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_26_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_26_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_26_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_26_USED
    #define EMIOS_0_CH_26_USED
#else
    #error "EMIOS_0_CH_26 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_27_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_27_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_27_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_27_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_27_USED
    #define EMIOS_0_CH_27_USED
#else
    #error "EMIOS_0_CH_27 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_28_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_28_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_28_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_28_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_28_USED
    #define EMIOS_0_CH_28_USED
#else
    #error "EMIOS_0_CH_28 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_29_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_29_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_29_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_29_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_29_USED
    #define EMIOS_0_CH_29_USED
#else
    #error "EMIOS_0_CH_29 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_30_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_30_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_30_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_30_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_30_USED
    #define EMIOS_0_CH_30_USED
#else
    #error "EMIOS_0_CH_30 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_0_CH_31_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_31_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_0_CH_31_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_31_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_0_CH_31_USED
    #define EMIOS_0_CH_31_USED
#else
    #error "EMIOS_0_CH_31 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_0_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_0_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_0_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_0_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_0_USED
    #define EMIOS_1_CH_0_USED
#else
    #error "EMIOS_1_CH_0 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_1_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_1_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_1_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_1_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_1_USED
    #define EMIOS_1_CH_1_USED
#else
    #error "EMIOS_1_CH_1 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_2_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_2_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_2_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_2_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_2_USED
    #define EMIOS_1_CH_2_USED
#else
    #error "EMIOS_1_CH_2 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_3_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_3_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_3_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_3_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_3_USED
    #define EMIOS_1_CH_3_USED
#else
    #error "EMIOS_1_CH_3 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_4_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_4_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_4_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_4_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_4_USED
    #define EMIOS_1_CH_4_USED
#else
    #error "EMIOS_1_CH_4 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_5_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_5_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_5_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_5_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_5_USED
    #define EMIOS_1_CH_5_USED
#else
    #error "EMIOS_1_CH_5 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_6_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_6_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_6_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_6_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_6_USED
    #define EMIOS_1_CH_6_USED
#else
    #error "EMIOS_1_CH_6 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_7_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_7_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_7_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_7_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_7_USED
    #define EMIOS_1_CH_7_USED
#else
    #error "EMIOS_1_CH_7 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_16_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_16_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_16_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_16_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_16_USED
    #define EMIOS_1_CH_16_USED
#else
    #error "EMIOS_1_CH_16 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_17_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_17_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_17_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_17_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_17_USED
    #define EMIOS_1_CH_17_USED
#else
    #error "EMIOS_1_CH_17 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_18_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_18_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_18_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_18_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_18_USED
    #define EMIOS_1_CH_18_USED
#else
    #error "EMIOS_1_CH_18 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_19_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_19_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_19_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_19_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_19_USED
    #define EMIOS_1_CH_19_USED
#else
    #error "EMIOS_1_CH_19 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_20_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_20_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_20_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_20_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_20_USED
    #define EMIOS_1_CH_20_USED
#else
    #error "EMIOS_1_CH_20 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_21_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_21_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_21_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_21_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_21_USED
    #define EMIOS_1_CH_21_USED
#else
    #error "EMIOS_1_CH_21 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_22_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_22_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_22_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_22_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_22_USED
    #define EMIOS_1_CH_22_USED
#else
    #error "EMIOS_1_CH_22 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_23_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_23_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_23_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_23_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_23_USED
    #define EMIOS_1_CH_23_USED
#else
    #error "EMIOS_1_CH_23 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_24_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_24_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_24_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_24_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_24_USED
    #define EMIOS_1_CH_24_USED
#else
    #error "EMIOS_1_CH_24 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_25_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_25_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_25_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_25_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_25_USED
    #define EMIOS_1_CH_25_USED
#else
    #error "EMIOS_1_CH_25 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_26_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_26_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_26_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_26_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_26_USED
    #define EMIOS_1_CH_26_USED
#else
    #error "EMIOS_1_CH_26 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_27_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_27_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_27_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_27_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_27_USED
    #define EMIOS_1_CH_27_USED
#else
    #error "EMIOS_1_CH_27 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_28_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_28_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_28_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_28_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_28_USED
    #define EMIOS_1_CH_28_USED
#else
    #error "EMIOS_1_CH_28 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_29_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_29_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_29_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_29_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_29_USED
    #define EMIOS_1_CH_29_USED
#else
    #error "EMIOS_1_CH_29 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_30_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_30_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_30_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_30_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_30_USED
    #define EMIOS_1_CH_30_USED
#else
    #error "EMIOS_1_CH_30 channel cannot be used by ICU. Instance locked by another driver!"
#endif

#ifndef ICU_EMIOS_1_CH_31_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_31_ISR_USED    (STD_ON)
#endif
#ifndef EMIOS_1_CH_31_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_31_ISR_USED        (STD_ON)
#endif
/** @brief Macros to check EMIOS channels used by ICU. */
#ifndef EMIOS_1_CH_31_USED
    #define EMIOS_1_CH_31_USED
#else
    #error "EMIOS_1_CH_31 channel cannot be used by ICU. Instance locked by another driver!"
#endif


#define EMIOS_ICU_CONFIG_EXT \
        EMIOS_ICU_CONFIG_SA_INIT_PB \

#endif  /* EMIOS_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EMIOS_ICU_IP_CFG_H */

