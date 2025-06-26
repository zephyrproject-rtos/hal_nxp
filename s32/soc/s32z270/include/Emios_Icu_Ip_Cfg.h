/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_ICU_IP_CFG_H
#define EMIOS_ICU_IP_CFG_H

/**
 *   @file    Emios_Icu_Ip_Cfg.h
 *   @version 2.0.1
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
#include <zephyr/devicetree.h>
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
#define EMIOS_ICU_IP_CFG_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU configuration header file are of the same vendor */
#if (EMIOS_ICU_IP_CFG_VENDOR_ID != EMIOS_ICU_IP_SA_INIT_PBCFG_VENDOR_ID)
    #error "Emios_Icu_Ip_Cfg.h and Emios_Icu_Ip_SA_Init_PBcfg.h have different vendor IDs"
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

#if DT_REG_ADDR(DT_INST(0, nxp_s32_emios)) == IP_EMIOS_0_BASE
#define EMIOS_0_DRV_INST    0
#elif DT_REG_ADDR(DT_INST(1, nxp_s32_emios)) == IP_EMIOS_0_BASE
#define EMIOS_0_DRV_INST    1
#endif

#if DT_REG_ADDR(DT_INST(0, nxp_s32_emios)) == IP_EMIOS_1_BASE
#define EMIOS_1_DRV_INST    0
#elif DT_REG_ADDR(DT_INST(1, nxp_s32_emios)) == IP_EMIOS_1_BASE
#define EMIOS_1_DRV_INST    1
#endif

#define EMIOS_PWM_NODE(n)   DT_CHILD(DT_INST(n, nxp_s32_emios), pwm)

#define EMIOS_ICU_CHANNEL(node_id, ch)                                   \
        IF_ENABLED(DT_ENUM_HAS_VALUE(node_id, pwm_mode, saic),           \
                  ((DT_PROP(node_id, channel) == ch) ||))

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 0) 0
#ifndef ICU_EMIOS_0_CH_0_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_0_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_0_CH_0_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_0_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 1) 0
#ifndef ICU_EMIOS_0_CH_1_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_1_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_0_CH_1_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_1_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 2) 0
#ifndef ICU_EMIOS_0_CH_2_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_2_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_0_CH_2_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_2_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 3) 0
#ifndef ICU_EMIOS_0_CH_3_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_3_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_0_CH_3_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_3_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 4) 0
#ifndef ICU_EMIOS_0_CH_4_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_4_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_0_CH_4_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_4_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 5) 0
#ifndef ICU_EMIOS_0_CH_5_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_5_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_0_CH_5_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_5_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 6) 0
#ifndef ICU_EMIOS_0_CH_6_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_6_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_0_CH_6_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_6_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 7) 0
#ifndef ICU_EMIOS_0_CH_7_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_7_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_0_CH_7_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_7_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 16) 0
#ifndef ICU_EMIOS_0_CH_16_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_16_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_0_CH_16_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_16_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 17) 0
#ifndef ICU_EMIOS_0_CH_17_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_17_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_0_CH_17_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_17_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 18) 0
#ifndef ICU_EMIOS_0_CH_18_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_18_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_0_CH_18_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_18_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 19) 0
#ifndef ICU_EMIOS_0_CH_19_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_19_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_0_CH_19_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_19_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 20) 0
#ifndef ICU_EMIOS_0_CH_20_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_20_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_0_CH_20_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_20_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 21) 0
#ifndef ICU_EMIOS_0_CH_21_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_21_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_0_CH_21_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_21_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 22) 0
#ifndef ICU_EMIOS_0_CH_22_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_0_CH_22_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_0_CH_22_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_22_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 23) 0
#ifndef ICU_EMIOS_0_CH_23_ISR_USED
    /** @brief Macros for check EMIOS channels used by MCL. */
    #define ICU_EMIOS_0_CH_23_ISR_USED          (STD_ON)
#endif

#ifndef EMIOS_0_CH_23_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_23_ISR_USED          (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 24) 0
#ifndef ICU_EMIOS_0_CH_24_ISR_USED
    /** @brief Macros for check EMIOS channels used by MCL. */
    #define ICU_EMIOS_0_CH_24_ISR_USED          (STD_ON)
#endif

#ifndef EMIOS_0_CH_24_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_24_ISR_USED          (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 25) 0
#ifndef ICU_EMIOS_0_CH_25_ISR_USED
    /** @brief Macros for check EMIOS channels used by MCL. */
    #define ICU_EMIOS_0_CH_25_ISR_USED          (STD_ON)
#endif

#ifndef EMIOS_0_CH_25_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_25_ISR_USED          (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 26) 0
#ifndef ICU_EMIOS_0_CH_26_ISR_USED
    /** @brief Macros for check EMIOS channels used by MCL. */
    #define ICU_EMIOS_0_CH_26_ISR_USED          (STD_ON)
#endif

#ifndef EMIOS_0_CH_26_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_26_ISR_USED          (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 27) 0
#ifndef ICU_EMIOS_0_CH_27_ISR_USED
    /** @brief Macros for check EMIOS channels used by MCL. */
    #define ICU_EMIOS_0_CH_27_ISR_USED          (STD_ON)
#endif

#ifndef EMIOS_0_CH_27_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_27_ISR_USED          (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 28) 0
#ifndef ICU_EMIOS_0_CH_28_ISR_USED
    /** @brief Macros for check EMIOS channels used by MCL. */
    #define ICU_EMIOS_0_CH_28_ISR_USED          (STD_ON)
#endif

#ifndef EMIOS_0_CH_28_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_28_ISR_USED          (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 29) 0
#ifndef ICU_EMIOS_0_CH_29_ISR_USED
    /** @brief Macros for check EMIOS channels used by MCL. */
    #define ICU_EMIOS_0_CH_29_ISR_USED          (STD_ON)
#endif

#ifndef EMIOS_0_CH_29_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_29_ISR_USED          (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 30) 0
#ifndef ICU_EMIOS_0_CH_30_ISR_USED
    /** @brief Macros for check EMIOS channels used by MCL. */
    #define ICU_EMIOS_0_CH_30_ISR_USED          (STD_ON)
#endif

#ifndef EMIOS_0_CH_30_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_30_ISR_USED          (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 31) 0
#ifndef ICU_EMIOS_0_CH_31_ISR_USED
    /** @brief Macros for check EMIOS channels used by MCL. */
    #define ICU_EMIOS_0_CH_31_ISR_USED          (STD_ON)
#endif

#ifndef EMIOS_0_CH_31_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_31_ISR_USED          (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_1_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 0) 0
#ifndef ICU_EMIOS_1_CH_0_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_0_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_1_CH_0_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_0_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_1_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 1) 0
#ifndef ICU_EMIOS_1_CH_1_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_1_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_1_CH_1_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_1_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_1_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 2) 0
#ifndef ICU_EMIOS_1_CH_2_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_2_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_1_CH_2_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_2_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_1_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 3) 0
#ifndef ICU_EMIOS_1_CH_3_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_3_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_1_CH_3_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_3_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_1_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 4) 0
#ifndef ICU_EMIOS_1_CH_4_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_4_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_1_CH_4_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_4_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_1_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 5) 0
#ifndef ICU_EMIOS_1_CH_5_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_5_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_1_CH_5_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_5_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_1_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 6) 0
#ifndef ICU_EMIOS_1_CH_6_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_6_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_1_CH_6_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_6_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_1_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 7) 0
#ifndef ICU_EMIOS_1_CH_7_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_7_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_1_CH_7_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_7_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_1_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 16) 0
#ifndef ICU_EMIOS_1_CH_16_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_16_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_1_CH_16_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_16_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_1_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 17) 0
#ifndef ICU_EMIOS_1_CH_17_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_17_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_1_CH_17_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_17_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_1_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 18) 0
#ifndef ICU_EMIOS_1_CH_18_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_18_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_1_CH_18_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_18_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_1_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 19) 0
#ifndef ICU_EMIOS_1_CH_19_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_19_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_1_CH_19_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_19_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_1_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 20) 0
#ifndef ICU_EMIOS_1_CH_20_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_20_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_1_CH_20_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_20_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_1_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 21) 0
#ifndef ICU_EMIOS_1_CH_21_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_21_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_1_CH_21_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_21_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_1_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 22) 0
#ifndef ICU_EMIOS_1_CH_22_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used by ICU. */
    #define ICU_EMIOS_1_CH_22_ISR_USED    (STD_ON)
#endif

#ifndef EMIOS_1_CH_22_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_22_ISR_USED        (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_1_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 23) 0
#ifndef ICU_EMIOS_1_CH_23_ISR_USED
    /** @brief Macros for check EMIOS channels used by MCL. */
    #define ICU_EMIOS_1_CH_23_ISR_USED          (STD_ON)
#endif

#ifndef EMIOS_1_CH_23_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_1_CH_23_ISR_USED          (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */


#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 24) 0
#ifndef ICU_EMIOS_0_CH_24_ISR_USED
    /** @brief Macros for check EMIOS channels used by MCL. */
    #define ICU_EMIOS_0_CH_24_ISR_USED          (STD_ON)
#endif

#ifndef EMIOS_0_CH_24_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_24_ISR_USED          (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 25) 0
#ifndef ICU_EMIOS_0_CH_25_ISR_USED
    /** @brief Macros for check EMIOS channels used by MCL. */
    #define ICU_EMIOS_0_CH_25_ISR_USED          (STD_ON)
#endif

#ifndef EMIOS_0_CH_25_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_25_ISR_USED          (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 26) 0
#ifndef ICU_EMIOS_0_CH_26_ISR_USED
    /** @brief Macros for check EMIOS channels used by MCL. */
    #define ICU_EMIOS_0_CH_26_ISR_USED          (STD_ON)
#endif

#ifndef EMIOS_0_CH_26_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_26_ISR_USED          (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 27) 0
#ifndef ICU_EMIOS_0_CH_27_ISR_USED
    /** @brief Macros for check EMIOS channels used by MCL. */
    #define ICU_EMIOS_0_CH_27_ISR_USED          (STD_ON)
#endif

#ifndef EMIOS_0_CH_27_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_27_ISR_USED          (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 28) 0
#ifndef ICU_EMIOS_0_CH_28_ISR_USED
    /** @brief Macros for check EMIOS channels used by MCL. */
    #define ICU_EMIOS_0_CH_28_ISR_USED          (STD_ON)
#endif

#ifndef EMIOS_0_CH_28_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_28_ISR_USED          (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 29) 0
#ifndef ICU_EMIOS_0_CH_29_ISR_USED
    /** @brief Macros for check EMIOS channels used by MCL. */
    #define ICU_EMIOS_0_CH_29_ISR_USED          (STD_ON)
#endif

#ifndef EMIOS_0_CH_29_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_29_ISR_USED          (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 30) 0
#ifndef ICU_EMIOS_0_CH_30_ISR_USED
    /** @brief Macros for check EMIOS channels used by MCL. */
    #define ICU_EMIOS_0_CH_30_ISR_USED          (STD_ON)
#endif

#ifndef EMIOS_0_CH_30_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_30_ISR_USED          (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#if DT_FOREACH_CHILD_STATUS_OKAY_VARGS(EMIOS_PWM_NODE(EMIOS_0_DRV_INST), \
                                       EMIOS_ICU_CHANNEL, 31) 0
#ifndef ICU_EMIOS_0_CH_31_ISR_USED
    /** @brief Macros for check EMIOS channels used by MCL. */
    #define ICU_EMIOS_0_CH_31_ISR_USED          (STD_ON)
#endif

#ifndef EMIOS_0_CH_31_ISR_USED
    /** @brief Macros for indicate EMIOS interrupts used. */
    #define EMIOS_0_CH_31_ISR_USED          (STD_ON)
#endif
#endif /* DT_FOREACH_CHILD_STATUS_OKAY_VARGS */

#define EMIOS_ICU_CONFIG_EXT \
        EMIOS_ICU_CONFIG_SA_INIT_PB \

#endif  /* EMIOS_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EMIOS_ICU_IP_CFG_H */