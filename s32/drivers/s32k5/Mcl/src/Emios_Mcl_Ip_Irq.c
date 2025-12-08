/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 *    @file       Emios_Mcl_Ip_Irq.c
 *
 *    @brief      AUTOSAR Mcl EMIOS interrupt common part.
 *
 *    @addtogroup
 *    @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Emios_Mcl_Ip_Irq.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_MCL_IP_IRQ_VENDOR_ID_C                       43
#define EMIOS_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C        4
#define EMIOS_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION_C        9
#define EMIOS_MCL_IP_IRQ_AR_RELEASE_REVISION_VERSION_C     0
#define EMIOS_MCL_IP_IRQ_SW_MAJOR_VERSION_C                0
#define EMIOS_MCL_IP_IRQ_SW_MINOR_VERSION_C                8
#define EMIOS_MCL_IP_IRQ_SW_PATCH_VERSION_C                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (EMIOS_MCL_IP_IRQ_VENDOR_ID_C != EMIOS_MCL_IP_IRQ_VENDOR_ID)
    #error "Emios_Mcl_Ip_Irq.c and Emios_Mcl_Ip_Irq.h have different vendor ids"
#endif

/* Check if  source file and Emios_Mcl_Ip_Irq.h file are of the same Autosar version */
#if ((EMIOS_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != EMIOS_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != EMIOS_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != EMIOS_MCL_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Mcl_Ip_Irq.c and Emios_Mcl_Ip_Irq.h are different"
#endif

/* Check if source file and Emios_Mcl_Ip_Irq.h file are of the same Software version */
#if ((EMIOS_MCL_IP_IRQ_SW_MAJOR_VERSION_C != EMIOS_MCL_IP_IRQ_SW_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_SW_MINOR_VERSION_C != EMIOS_MCL_IP_IRQ_SW_MINOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_SW_PATCH_VERSION_C != EMIOS_MCL_IP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Mcl_Ip_Irq.c and Emios_Mcl_Ip_Irq.h are different"
#endif

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if Emios_Mcl_Ip_Irq.c file and Emios_Mcl_Ip_Irq header file are of the same vendor. */
#if (EMIOS_MCL_IP_IRQ_VENDOR_ID_C != EMIOS_MCL_IP_IRQ_VENDOR_ID)
    #error "Vendor IDs of Emios_Mcl_Ip_Irq.c and Emios_Mcl_Ip_Irq.h are different."
#endif

/* Check if Emios_Mcl_Ip_Irq.c file and Emios_Mcl_Ip_Irq header file are of the same AUTOSAR version. */
#if ((EMIOS_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != EMIOS_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != EMIOS_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != EMIOS_MCL_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Emios_Mcl_Ip_Irq.c and Emios_Mcl_Ip_Irq.h are different."
#endif

/* Check if Emios_Mcl_Ip_Irq.c file and Emios_Mcl_Ip_Irq header file are of the same software version */
#if ((EMIOS_MCL_IP_IRQ_SW_MAJOR_VERSION_C != EMIOS_MCL_IP_IRQ_SW_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_SW_MINOR_VERSION_C != EMIOS_MCL_IP_IRQ_SW_MINOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_SW_PATCH_VERSION_C != EMIOS_MCL_IP_IRQ_SW_PATCH_VERSION))
    #error "Software version numbers of Emios_Mcl_Ip_Irq.c and Emios_Mcl_Ip_Irq.h are different."
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#if (\
        (defined GPT_EMIOS_0_CH_0_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_1_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_2_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_3_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_4_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_5_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_6_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_7_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_8_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_9_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_10_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_11_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_12_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_13_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_14_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_15_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_16_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_17_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_18_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_19_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_20_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_21_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_22_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_23_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_24_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_25_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_26_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_27_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_28_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_29_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_30_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_31_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_0_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_1_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_2_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_3_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_4_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_5_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_6_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_7_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_8_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_9_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_10_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_11_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_12_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_13_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_14_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_15_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_16_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_17_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_18_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_19_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_20_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_21_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_22_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_23_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_24_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_25_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_26_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_27_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_28_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_29_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_30_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_31_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_0_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_1_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_2_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_3_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_4_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_5_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_6_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_7_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_8_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_9_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_10_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_11_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_12_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_13_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_14_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_15_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_16_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_17_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_18_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_19_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_20_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_21_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_22_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_23_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_24_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_25_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_26_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_27_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_28_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_29_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_30_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_31_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_0_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_1_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_2_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_3_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_4_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_5_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_6_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_7_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_8_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_9_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_10_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_11_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_12_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_13_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_14_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_15_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_16_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_17_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_18_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_19_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_20_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_21_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_22_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_23_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_24_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_25_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_26_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_27_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_28_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_29_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_30_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_31_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_0_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_1_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_2_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_3_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_4_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_5_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_6_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_7_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_8_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_9_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_10_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_11_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_12_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_13_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_14_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_15_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_16_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_17_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_18_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_19_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_20_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_21_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_22_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_23_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_24_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_25_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_26_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_27_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_28_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_29_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_30_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_31_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_0_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_1_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_2_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_3_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_4_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_5_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_6_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_7_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_8_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_9_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_10_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_11_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_12_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_13_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_14_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_15_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_16_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_17_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_18_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_19_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_20_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_21_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_22_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_23_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_24_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_25_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_26_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_27_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_28_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_29_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_30_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_31_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_0_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_1_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_2_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_3_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_4_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_5_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_6_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_7_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_8_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_9_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_10_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_11_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_12_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_13_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_14_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_15_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_16_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_17_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_18_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_19_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_20_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_21_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_22_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_23_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_24_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_25_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_26_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_27_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_28_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_29_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_30_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_31_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_0_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_1_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_2_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_3_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_4_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_5_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_6_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_7_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_8_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_9_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_10_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_11_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_12_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_13_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_14_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_15_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_16_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_17_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_18_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_19_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_20_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_21_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_22_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_23_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_24_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_25_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_26_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_27_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_28_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_29_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_30_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_31_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_0_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_1_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_2_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_3_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_4_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_5_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_6_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_7_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_8_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_9_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_10_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_11_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_12_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_13_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_14_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_15_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_16_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_17_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_18_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_19_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_20_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_21_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_22_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_23_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_24_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_25_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_26_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_27_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_28_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_29_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_30_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_31_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_0_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_1_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_2_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_3_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_4_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_5_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_6_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_7_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_8_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_9_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_10_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_11_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_12_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_13_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_14_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_15_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_16_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_17_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_18_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_19_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_20_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_21_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_22_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_23_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_24_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_25_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_26_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_27_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_28_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_29_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_30_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_31_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_0_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_1_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_2_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_3_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_4_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_5_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_6_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_7_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_8_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_9_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_10_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_11_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_12_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_13_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_14_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_15_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_16_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_17_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_18_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_19_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_20_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_21_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_22_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_23_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_24_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_25_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_26_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_27_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_28_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_29_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_30_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_31_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_0_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_1_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_2_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_3_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_4_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_5_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_6_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_7_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_8_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_9_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_10_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_11_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_12_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_13_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_14_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_15_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_16_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_17_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_18_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_19_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_20_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_21_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_22_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_23_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_24_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_25_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_26_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_27_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_28_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_29_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_30_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_31_ISR_USED)\
    )

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
#include "Mcl_MemMap.h"

/* Array with EMIOS bases addresses. */
extern eMIOS_Type* const  Emios_Ip_paxBase[eMIOS_INSTANCE_COUNT];

#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
#include "Mcl_MemMap.h"

#endif /* All platfrom includes. */


/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

#if (\
        (defined GPT_EMIOS_0_CH_0_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_1_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_2_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_3_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_4_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_5_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_6_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_7_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_8_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_9_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_10_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_11_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_12_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_13_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_14_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_15_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_16_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_17_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_18_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_19_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_20_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_21_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_22_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_23_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_24_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_25_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_26_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_27_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_28_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_29_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_30_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_31_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_0_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_1_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_2_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_3_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_4_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_5_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_6_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_7_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_8_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_9_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_10_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_11_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_12_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_13_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_14_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_15_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_16_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_17_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_18_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_19_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_20_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_21_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_22_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_23_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_24_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_25_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_26_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_27_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_28_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_29_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_30_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_31_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_0_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_1_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_2_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_3_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_4_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_5_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_6_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_7_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_8_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_9_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_10_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_11_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_12_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_13_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_14_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_15_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_16_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_17_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_18_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_19_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_20_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_21_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_22_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_23_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_24_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_25_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_26_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_27_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_28_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_29_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_30_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_31_ISR_USED) \
    )
static void Emios_Gpt_IrqHandler(const uint8 Instance, const uint8 Channel)
{
    /* Check that an event occurred on Emios channel */
    if (0U != ((Emios_Ip_paxBase[Instance]->CH.UC[Channel].S) & (uint32)eMIOS_S_FLAG_MASK))
    {
        /* Check that an event occurred on EMIOS channel */
        #if (defined eMIOS_C_DMA_MASK)
        if (0U != ((Emios_Ip_paxBase[Instance]->CH.UC[Channel].C) & ((uint32)(eMIOS_C_DMA_MASK | eMIOS_C_FEN_MASK))))
        #else
        if (0U != ((Emios_Ip_paxBase[Instance]->CH.UC[Channel].C) & ((uint32)(eMIOS_C_FEN_MASK))))
        #endif
        {
            Emios_Gpt_Ip_IrqHandler(Instance, Channel);
        }
        else
        {
            /* Do nothing - in case of spurious interrupts, return immediately */
        }
    }
}
#endif

#if (\
        (defined ICU_EMIOS_0_CH_0_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_1_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_2_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_3_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_4_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_5_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_6_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_7_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_8_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_9_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_10_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_11_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_12_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_13_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_14_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_15_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_16_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_17_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_18_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_19_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_20_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_21_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_22_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_23_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_24_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_25_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_26_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_27_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_28_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_29_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_30_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_31_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_0_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_1_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_2_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_3_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_4_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_5_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_6_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_7_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_8_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_9_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_10_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_11_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_12_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_13_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_14_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_15_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_16_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_17_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_18_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_19_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_20_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_21_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_22_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_23_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_24_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_25_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_26_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_27_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_28_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_29_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_30_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_31_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_0_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_1_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_2_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_3_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_4_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_5_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_6_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_7_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_8_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_9_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_10_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_11_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_12_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_13_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_14_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_15_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_16_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_17_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_18_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_19_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_20_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_21_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_22_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_23_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_24_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_25_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_26_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_27_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_28_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_29_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_30_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_31_ISR_USED) \
    )
static void Emios_Icu_IrqHandler(const uint8 Instance, const uint8 Channel)
{
    /* Check that an event occurred on Emios channel */
    if (0U != ((Emios_Ip_paxBase[Instance]->CH.UC[Channel].S) & (uint32)eMIOS_S_FLAG_MASK))
    {
        /* Check that an event occurred on EMIOS channel */
        #if (defined eMIOS_C_DMA_MASK)
        if (0U != ((Emios_Ip_paxBase[Instance]->CH.UC[Channel].C) & ((uint32)(eMIOS_C_DMA_MASK | eMIOS_C_FEN_MASK))))
        #else
        if (0U != ((Emios_Ip_paxBase[Instance]->CH.UC[Channel].C) & ((uint32)(eMIOS_C_FEN_MASK))))
        #endif
        {
            Emios_Icu_Ip_IrqHandler(Instance, Channel);
        }
        else
        {
            /* Do nothing - in case of spurious interrupts, return immediately */
        }
    }
}
#endif

#if (\
        (defined OCU_EMIOS_0_CH_0_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_1_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_2_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_3_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_4_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_5_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_6_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_7_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_8_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_9_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_10_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_11_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_12_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_13_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_14_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_15_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_16_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_17_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_18_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_19_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_20_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_21_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_22_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_23_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_24_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_25_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_26_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_27_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_28_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_29_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_30_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_31_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_0_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_1_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_2_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_3_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_4_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_5_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_6_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_7_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_8_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_9_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_10_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_11_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_12_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_13_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_14_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_15_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_16_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_17_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_18_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_19_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_20_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_21_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_22_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_23_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_24_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_25_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_26_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_27_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_28_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_29_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_30_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_31_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_0_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_1_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_2_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_3_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_4_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_5_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_6_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_7_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_8_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_9_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_10_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_11_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_12_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_13_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_14_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_15_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_16_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_17_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_18_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_19_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_20_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_21_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_22_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_23_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_24_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_25_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_26_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_27_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_28_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_29_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_30_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_31_ISR_USED) \
    )
static void Emios_Ocu_IrqHandler(const uint8 Instance, const uint8 Channel)
{
    /* Check that an event occurred on Emios channel */
    if (0U != ((Emios_Ip_paxBase[Instance]->CH.UC[Channel].S) & (uint32)eMIOS_S_FLAG_MASK))
    {
        /* Check that an event occurred on EMIOS channel */
        #if (defined eMIOS_C_DMA_MASK)
        if (0U != ((Emios_Ip_paxBase[Instance]->CH.UC[Channel].C) & ((uint32)(eMIOS_C_DMA_MASK | eMIOS_C_FEN_MASK))))
        #else
        if (0U != ((Emios_Ip_paxBase[Instance]->CH.UC[Channel].C) & ((uint32)(eMIOS_C_FEN_MASK))))
        #endif
        {
            Emios_Ocu_Ip_IrqHandler(Instance, Channel);
        }
        else
        {
            /* Do nothing - in case of spurious interrupts, return immediately */
        }
    }
}
#endif

#if (\
        (defined PWM_EMIOS_0_CH_0_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_1_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_2_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_3_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_4_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_5_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_6_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_7_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_8_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_9_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_10_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_11_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_12_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_13_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_14_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_15_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_16_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_17_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_18_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_19_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_20_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_21_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_22_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_23_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_24_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_25_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_26_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_27_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_28_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_29_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_30_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_31_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_0_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_1_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_2_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_3_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_4_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_5_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_6_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_7_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_8_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_9_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_10_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_11_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_12_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_13_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_14_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_15_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_16_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_17_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_18_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_19_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_20_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_21_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_22_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_23_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_24_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_25_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_26_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_27_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_28_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_29_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_30_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_31_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_0_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_1_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_2_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_3_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_4_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_5_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_6_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_7_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_8_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_9_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_10_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_11_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_12_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_13_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_14_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_15_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_16_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_17_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_18_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_19_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_20_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_21_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_22_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_23_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_24_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_25_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_26_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_27_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_28_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_29_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_30_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_31_ISR_USED) \
    )
static void Emios_Pwm_IrqHandler(const uint8 Instance, const uint8 Channel)
{
    /* Check that an event occurred on Emios channel */
    if (0U != ((Emios_Ip_paxBase[Instance]->CH.UC[Channel].S) & (uint32)eMIOS_S_FLAG_MASK))
    {
        /* Check that an event occurred on EMIOS channel */
        #if (defined eMIOS_C_DMA_MASK)
        if (0U != ((Emios_Ip_paxBase[Instance]->CH.UC[Channel].C) & ((uint32)(eMIOS_C_DMA_MASK | eMIOS_C_FEN_MASK))))
        #else
        if (0U != ((Emios_Ip_paxBase[Instance]->CH.UC[Channel].C) & ((uint32)(eMIOS_C_FEN_MASK))))
        #endif
        {
            Emios_Pwm_Ip_IrqHandler(Instance, Channel);
        }
        else
        {
            /* Do nothing - in case of spurious interrupts, return immediately */
        }
    }
}
#endif
/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#if (\
        (defined GPT_EMIOS_0_CH_0_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_1_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_2_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_3_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_0_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_1_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_2_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_3_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_0_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_1_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_2_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_3_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_0_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_1_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_2_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_3_ISR_USED)\
    )
/**
* @brief    Interrupt handler for Emios channels 0-3 for Emios instance 0
* @details  Process the interrupt of eMios channels 0-3
*
* @note     This will be defined only if EMIOS channels 0, 1, 2, 3 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_5_IRQ)
{
    #if (defined EMIOS_0_CH_0_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_0_ISR_USED)
        Emios_Gpt_IrqHandler(0, 0);
        #endif

        #if (defined ICU_EMIOS_0_CH_0_ISR_USED)
        Emios_Icu_IrqHandler(0, 0);
        #endif

        #if (defined OCU_EMIOS_0_CH_0_ISR_USED)
        Emios_Ocu_IrqHandler(0, 0);
        #endif

        #if (defined PWM_EMIOS_0_CH_0_ISR_USED)
        Emios_Pwm_IrqHandler(0, 0);
        #endif
    #endif

    #if (defined EMIOS_0_CH_1_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_1_ISR_USED)
        Emios_Gpt_IrqHandler(0, 1);
        #endif

        #if (defined ICU_EMIOS_0_CH_1_ISR_USED)
        Emios_Icu_IrqHandler(0, 1);
        #endif

        #if (defined OCU_EMIOS_0_CH_1_ISR_USED)
        Emios_Ocu_IrqHandler(0, 1);
        #endif

        #if (defined PWM_EMIOS_0_CH_1_ISR_USED)
        Emios_Pwm_IrqHandler(0, 1);
        #endif
    #endif

    #if (defined EMIOS_0_CH_2_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_2_ISR_USED)
        Emios_Gpt_IrqHandler(0, 2);
        #endif

        #if (defined ICU_EMIOS_0_CH_2_ISR_USED)
        Emios_Icu_IrqHandler(0, 2);
        #endif

        #if (defined OCU_EMIOS_0_CH_2_ISR_USED)
        Emios_Ocu_IrqHandler(0, 2);
        #endif

        #if (defined PWM_EMIOS_0_CH_2_ISR_USED)
        Emios_Pwm_IrqHandler(0, 2);
        #endif
    #endif

    #if (defined EMIOS_0_CH_3_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_3_ISR_USED)
        Emios_Gpt_IrqHandler(0, 3);
        #endif

        #if (defined ICU_EMIOS_0_CH_3_ISR_USED)
        Emios_Icu_IrqHandler(0, 3);
        #endif

        #if (defined OCU_EMIOS_0_CH_3_ISR_USED)
        Emios_Ocu_IrqHandler(0, 3);
        #endif

        #if (defined PWM_EMIOS_0_CH_3_ISR_USED)
        Emios_Pwm_IrqHandler(0, 3);
        #endif
    #endif

}
#endif
#if (\
        (defined GPT_EMIOS_0_CH_4_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_5_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_6_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_7_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_4_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_5_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_6_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_7_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_4_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_5_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_6_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_7_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_4_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_5_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_6_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_7_ISR_USED)\
    )
/**
* @brief    Interrupt handler for Emios channels 4-7 for Emios instance 0
* @details  Process the interrupt of eMios channels 4-7
*
* @note     This will be defined only if EMIOS channels 4, 5, 6, 7 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_4_IRQ)
{
    #if (defined EMIOS_0_CH_4_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_4_ISR_USED)
        Emios_Gpt_IrqHandler(0, 4);
        #endif

        #if (defined ICU_EMIOS_0_CH_4_ISR_USED)
        Emios_Icu_IrqHandler(0, 4);
        #endif

        #if (defined OCU_EMIOS_0_CH_4_ISR_USED)
        Emios_Ocu_IrqHandler(0, 4);
        #endif

        #if (defined PWM_EMIOS_0_CH_4_ISR_USED)
        Emios_Pwm_IrqHandler(0, 4);
        #endif
    #endif

    #if (defined EMIOS_0_CH_5_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_5_ISR_USED)
        Emios_Gpt_IrqHandler(0, 5);
        #endif

        #if (defined ICU_EMIOS_0_CH_5_ISR_USED)
        Emios_Icu_IrqHandler(0, 5);
        #endif

        #if (defined OCU_EMIOS_0_CH_5_ISR_USED)
        Emios_Ocu_IrqHandler(0, 5);
        #endif

        #if (defined PWM_EMIOS_0_CH_5_ISR_USED)
        Emios_Pwm_IrqHandler(0, 5);
        #endif
    #endif

    #if (defined EMIOS_0_CH_6_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_6_ISR_USED)
        Emios_Gpt_IrqHandler(0, 6);
        #endif

        #if (defined ICU_EMIOS_0_CH_6_ISR_USED)
        Emios_Icu_IrqHandler(0, 6);
        #endif

        #if (defined OCU_EMIOS_0_CH_6_ISR_USED)
        Emios_Ocu_IrqHandler(0, 6);
        #endif

        #if (defined PWM_EMIOS_0_CH_6_ISR_USED)
        Emios_Pwm_IrqHandler(0, 6);
        #endif
    #endif

    #if (defined EMIOS_0_CH_7_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_7_ISR_USED)
        Emios_Gpt_IrqHandler(0, 7);
        #endif

        #if (defined ICU_EMIOS_0_CH_7_ISR_USED)
        Emios_Icu_IrqHandler(0, 7);
        #endif

        #if (defined OCU_EMIOS_0_CH_7_ISR_USED)
        Emios_Ocu_IrqHandler(0, 7);
        #endif

        #if (defined PWM_EMIOS_0_CH_7_ISR_USED)
        Emios_Pwm_IrqHandler(0, 7);
        #endif
    #endif

}
#endif
#if (\
        (defined GPT_EMIOS_0_CH_8_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_9_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_10_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_11_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_8_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_9_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_10_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_11_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_8_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_9_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_10_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_11_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_8_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_9_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_10_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_11_ISR_USED)\
    )
/**
* @brief    Interrupt handler for Emios channels 8-11 for Emios instance 0
* @details  Process the interrupt of eMios channels 8-11
*
* @note     This will be defined only if EMIOS channels 8, 9, 10, 11 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_3_IRQ)
{
    #if (defined EMIOS_0_CH_8_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_8_ISR_USED)
        Emios_Gpt_IrqHandler(0, 8);
        #endif

        #if (defined ICU_EMIOS_0_CH_8_ISR_USED)
        Emios_Icu_IrqHandler(0, 8);
        #endif

        #if (defined OCU_EMIOS_0_CH_8_ISR_USED)
        Emios_Ocu_IrqHandler(0, 8);
        #endif

        #if (defined PWM_EMIOS_0_CH_8_ISR_USED)
        Emios_Pwm_IrqHandler(0, 8);
        #endif
    #endif

    #if (defined EMIOS_0_CH_9_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_9_ISR_USED)
        Emios_Gpt_IrqHandler(0, 9);
        #endif

        #if (defined ICU_EMIOS_0_CH_9_ISR_USED)
        Emios_Icu_IrqHandler(0, 9);
        #endif

        #if (defined OCU_EMIOS_0_CH_9_ISR_USED)
        Emios_Ocu_IrqHandler(0, 9);
        #endif

        #if (defined PWM_EMIOS_0_CH_9_ISR_USED)
        Emios_Pwm_IrqHandler(0, 9);
        #endif
    #endif

    #if (defined EMIOS_0_CH_10_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_10_ISR_USED)
        Emios_Gpt_IrqHandler(0, 10);
        #endif

        #if (defined ICU_EMIOS_0_CH_10_ISR_USED)
        Emios_Icu_IrqHandler(0, 10);
        #endif

        #if (defined OCU_EMIOS_0_CH_10_ISR_USED)
        Emios_Ocu_IrqHandler(0, 10);
        #endif

        #if (defined PWM_EMIOS_0_CH_10_ISR_USED)
        Emios_Pwm_IrqHandler(0, 10);
        #endif
    #endif

    #if (defined EMIOS_0_CH_11_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_11_ISR_USED)
        Emios_Gpt_IrqHandler(0, 11);
        #endif

        #if (defined ICU_EMIOS_0_CH_11_ISR_USED)
        Emios_Icu_IrqHandler(0, 11);
        #endif

        #if (defined OCU_EMIOS_0_CH_11_ISR_USED)
        Emios_Ocu_IrqHandler(0, 11);
        #endif

        #if (defined PWM_EMIOS_0_CH_11_ISR_USED)
        Emios_Pwm_IrqHandler(0, 11);
        #endif
    #endif

}
#endif
#if (\
        (defined GPT_EMIOS_0_CH_12_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_13_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_14_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_15_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_12_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_13_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_14_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_15_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_12_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_13_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_14_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_15_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_12_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_13_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_14_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_15_ISR_USED)\
    )
/**
* @brief    Interrupt handler for Emios channels 12-15 for Emios instance 0
* @details  Process the interrupt of eMios channels 12-15
*
* @note     This will be defined only if EMIOS channels 12, 13, 14, 15 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_2_IRQ)
{
    #if (defined EMIOS_0_CH_12_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_12_ISR_USED)
        Emios_Gpt_IrqHandler(0, 12);
        #endif

        #if (defined ICU_EMIOS_0_CH_12_ISR_USED)
        Emios_Icu_IrqHandler(0, 12);
        #endif

        #if (defined OCU_EMIOS_0_CH_12_ISR_USED)
        Emios_Ocu_IrqHandler(0, 12);
        #endif

        #if (defined PWM_EMIOS_0_CH_12_ISR_USED)
        Emios_Pwm_IrqHandler(0, 12);
        #endif
    #endif

    #if (defined EMIOS_0_CH_13_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_13_ISR_USED)
        Emios_Gpt_IrqHandler(0, 13);
        #endif

        #if (defined ICU_EMIOS_0_CH_13_ISR_USED)
        Emios_Icu_IrqHandler(0, 13);
        #endif

        #if (defined OCU_EMIOS_0_CH_13_ISR_USED)
        Emios_Ocu_IrqHandler(0, 13);
        #endif

        #if (defined PWM_EMIOS_0_CH_13_ISR_USED)
        Emios_Pwm_IrqHandler(0, 13);
        #endif
    #endif

    #if (defined EMIOS_0_CH_14_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_14_ISR_USED)
        Emios_Gpt_IrqHandler(0, 14);
        #endif

        #if (defined ICU_EMIOS_0_CH_14_ISR_USED)
        Emios_Icu_IrqHandler(0, 14);
        #endif

        #if (defined OCU_EMIOS_0_CH_14_ISR_USED)
        Emios_Ocu_IrqHandler(0, 14);
        #endif

        #if (defined PWM_EMIOS_0_CH_14_ISR_USED)
        Emios_Pwm_IrqHandler(0, 14);
        #endif
    #endif

    #if (defined EMIOS_0_CH_15_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_15_ISR_USED)
        Emios_Gpt_IrqHandler(0, 15);
        #endif

        #if (defined ICU_EMIOS_0_CH_15_ISR_USED)
        Emios_Icu_IrqHandler(0, 15);
        #endif

        #if (defined OCU_EMIOS_0_CH_15_ISR_USED)
        Emios_Ocu_IrqHandler(0, 15);
        #endif

        #if (defined PWM_EMIOS_0_CH_15_ISR_USED)
        Emios_Pwm_IrqHandler(0, 15);
        #endif
    #endif

}
#endif
#if (\
        (defined GPT_EMIOS_0_CH_16_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_17_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_18_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_19_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_16_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_17_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_18_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_19_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_16_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_17_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_18_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_19_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_16_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_17_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_18_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_19_ISR_USED)\
    )
/**
* @brief    Interrupt handler for Emios channels 16-19 for Emios instance 0
* @details  Process the interrupt of eMios channels 16-19
*
* @note     This will be defined only if EMIOS channels 16, 17, 18, 19 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_1_IRQ)
{
    #if (defined EMIOS_0_CH_16_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_16_ISR_USED)
        Emios_Gpt_IrqHandler(0, 16);
        #endif

        #if (defined ICU_EMIOS_0_CH_16_ISR_USED)
        Emios_Icu_IrqHandler(0, 16);
        #endif

        #if (defined OCU_EMIOS_0_CH_16_ISR_USED)
        Emios_Ocu_IrqHandler(0, 16);
        #endif

        #if (defined PWM_EMIOS_0_CH_16_ISR_USED)
        Emios_Pwm_IrqHandler(0, 16);
        #endif
    #endif

    #if (defined EMIOS_0_CH_17_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_17_ISR_USED)
        Emios_Gpt_IrqHandler(0, 17);
        #endif

        #if (defined ICU_EMIOS_0_CH_17_ISR_USED)
        Emios_Icu_IrqHandler(0, 17);
        #endif

        #if (defined OCU_EMIOS_0_CH_17_ISR_USED)
        Emios_Ocu_IrqHandler(0, 17);
        #endif

        #if (defined PWM_EMIOS_0_CH_17_ISR_USED)
        Emios_Pwm_IrqHandler(0, 17);
        #endif
    #endif

    #if (defined EMIOS_0_CH_18_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_18_ISR_USED)
        Emios_Gpt_IrqHandler(0, 18);
        #endif

        #if (defined ICU_EMIOS_0_CH_18_ISR_USED)
        Emios_Icu_IrqHandler(0, 18);
        #endif

        #if (defined OCU_EMIOS_0_CH_18_ISR_USED)
        Emios_Ocu_IrqHandler(0, 18);
        #endif

        #if (defined PWM_EMIOS_0_CH_18_ISR_USED)
        Emios_Pwm_IrqHandler(0, 18);
        #endif
    #endif

    #if (defined EMIOS_0_CH_19_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_19_ISR_USED)
        Emios_Gpt_IrqHandler(0, 19);
        #endif

        #if (defined ICU_EMIOS_0_CH_19_ISR_USED)
        Emios_Icu_IrqHandler(0, 19);
        #endif

        #if (defined OCU_EMIOS_0_CH_19_ISR_USED)
        Emios_Ocu_IrqHandler(0, 19);
        #endif

        #if (defined PWM_EMIOS_0_CH_19_ISR_USED)
        Emios_Pwm_IrqHandler(0, 19);
        #endif
    #endif

}
#endif
#if (\
        (defined GPT_EMIOS_0_CH_20_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_21_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_22_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_23_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_20_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_21_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_22_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_23_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_20_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_21_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_22_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_23_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_20_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_21_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_22_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_23_ISR_USED)\
    )
/**
* @brief    Interrupt handler for Emios channels 20-23 for Emios instance 0
* @details  Process the interrupt of eMios channels 20-23
*
* @note     This will be defined only if EMIOS channels 20, 21, 22, 23 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_0_IRQ)
{
    #if (defined EMIOS_0_CH_20_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_20_ISR_USED)
        Emios_Gpt_IrqHandler(0, 20);
        #endif

        #if (defined ICU_EMIOS_0_CH_20_ISR_USED)
        Emios_Icu_IrqHandler(0, 20);
        #endif

        #if (defined OCU_EMIOS_0_CH_20_ISR_USED)
        Emios_Ocu_IrqHandler(0, 20);
        #endif

        #if (defined PWM_EMIOS_0_CH_20_ISR_USED)
        Emios_Pwm_IrqHandler(0, 20);
        #endif
    #endif

    #if (defined EMIOS_0_CH_21_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_21_ISR_USED)
        Emios_Gpt_IrqHandler(0, 21);
        #endif

        #if (defined ICU_EMIOS_0_CH_21_ISR_USED)
        Emios_Icu_IrqHandler(0, 21);
        #endif

        #if (defined OCU_EMIOS_0_CH_21_ISR_USED)
        Emios_Ocu_IrqHandler(0, 21);
        #endif

        #if (defined PWM_EMIOS_0_CH_21_ISR_USED)
        Emios_Pwm_IrqHandler(0, 21);
        #endif
    #endif

    #if (defined EMIOS_0_CH_22_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_22_ISR_USED)
        Emios_Gpt_IrqHandler(0, 22);
        #endif

        #if (defined ICU_EMIOS_0_CH_22_ISR_USED)
        Emios_Icu_IrqHandler(0, 22);
        #endif

        #if (defined OCU_EMIOS_0_CH_22_ISR_USED)
        Emios_Ocu_IrqHandler(0, 22);
        #endif

        #if (defined PWM_EMIOS_0_CH_22_ISR_USED)
        Emios_Pwm_IrqHandler(0, 22);
        #endif
    #endif

    #if (defined EMIOS_0_CH_23_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_23_ISR_USED)
        Emios_Gpt_IrqHandler(0, 23);
        #endif

        #if (defined ICU_EMIOS_0_CH_23_ISR_USED)
        Emios_Icu_IrqHandler(0, 23);
        #endif

        #if (defined OCU_EMIOS_0_CH_23_ISR_USED)
        Emios_Ocu_IrqHandler(0, 23);
        #endif

        #if (defined PWM_EMIOS_0_CH_23_ISR_USED)
        Emios_Pwm_IrqHandler(0, 23);
        #endif
    #endif

}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_0_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_1_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_2_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_3_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_0_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_1_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_2_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_3_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_0_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_1_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_2_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_3_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_0_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_1_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_2_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_3_ISR_USED)\
    )
/**
* @brief    Interrupt handler for Emios channels 0-3 for Emios instance 1
* @details  Process the interrupt of eMios channels 0-3
*
* @note     This will be defined only if EMIOS channels 0, 1, 2, 3 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_5_IRQ)
{
    #if (defined EMIOS_1_CH_0_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_0_ISR_USED)
        Emios_Gpt_IrqHandler(1, 0);
        #endif

        #if (defined ICU_EMIOS_1_CH_0_ISR_USED)
        Emios_Icu_IrqHandler(1, 0);
        #endif

        #if (defined OCU_EMIOS_1_CH_0_ISR_USED)
        Emios_Ocu_IrqHandler(1, 0);
        #endif

        #if (defined PWM_EMIOS_1_CH_0_ISR_USED)
        Emios_Pwm_IrqHandler(1, 0);
        #endif
    #endif

    #if (defined EMIOS_1_CH_1_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_1_ISR_USED)
        Emios_Gpt_IrqHandler(1, 1);
        #endif

        #if (defined ICU_EMIOS_1_CH_1_ISR_USED)
        Emios_Icu_IrqHandler(1, 1);
        #endif

        #if (defined OCU_EMIOS_1_CH_1_ISR_USED)
        Emios_Ocu_IrqHandler(1, 1);
        #endif

        #if (defined PWM_EMIOS_1_CH_1_ISR_USED)
        Emios_Pwm_IrqHandler(1, 1);
        #endif
    #endif

    #if (defined EMIOS_1_CH_2_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_2_ISR_USED)
        Emios_Gpt_IrqHandler(1, 2);
        #endif

        #if (defined ICU_EMIOS_1_CH_2_ISR_USED)
        Emios_Icu_IrqHandler(1, 2);
        #endif

        #if (defined OCU_EMIOS_1_CH_2_ISR_USED)
        Emios_Ocu_IrqHandler(1, 2);
        #endif

        #if (defined PWM_EMIOS_1_CH_2_ISR_USED)
        Emios_Pwm_IrqHandler(1, 2);
        #endif
    #endif

    #if (defined EMIOS_1_CH_3_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_3_ISR_USED)
        Emios_Gpt_IrqHandler(1, 3);
        #endif

        #if (defined ICU_EMIOS_1_CH_3_ISR_USED)
        Emios_Icu_IrqHandler(1, 3);
        #endif

        #if (defined OCU_EMIOS_1_CH_3_ISR_USED)
        Emios_Ocu_IrqHandler(1, 3);
        #endif

        #if (defined PWM_EMIOS_1_CH_3_ISR_USED)
        Emios_Pwm_IrqHandler(1, 3);
        #endif
    #endif

}
#endif
#if (\
        (defined GPT_EMIOS_1_CH_4_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_5_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_6_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_7_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_4_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_5_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_6_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_7_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_4_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_5_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_6_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_7_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_4_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_5_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_6_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_7_ISR_USED)\
    )
/**
* @brief    Interrupt handler for Emios channels 4-7 for Emios instance 1
* @details  Process the interrupt of eMios channels 4-7
*
* @note     This will be defined only if EMIOS channels 4, 5, 6, 7 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_4_IRQ)
{
    #if (defined EMIOS_1_CH_4_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_4_ISR_USED)
        Emios_Gpt_IrqHandler(1, 4);
        #endif

        #if (defined ICU_EMIOS_1_CH_4_ISR_USED)
        Emios_Icu_IrqHandler(1, 4);
        #endif

        #if (defined OCU_EMIOS_1_CH_4_ISR_USED)
        Emios_Ocu_IrqHandler(1, 4);
        #endif

        #if (defined PWM_EMIOS_1_CH_4_ISR_USED)
        Emios_Pwm_IrqHandler(1, 4);
        #endif
    #endif

    #if (defined EMIOS_1_CH_5_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_5_ISR_USED)
        Emios_Gpt_IrqHandler(1, 5);
        #endif

        #if (defined ICU_EMIOS_1_CH_5_ISR_USED)
        Emios_Icu_IrqHandler(1, 5);
        #endif

        #if (defined OCU_EMIOS_1_CH_5_ISR_USED)
        Emios_Ocu_IrqHandler(1, 5);
        #endif

        #if (defined PWM_EMIOS_1_CH_5_ISR_USED)
        Emios_Pwm_IrqHandler(1, 5);
        #endif
    #endif

    #if (defined EMIOS_1_CH_6_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_6_ISR_USED)
        Emios_Gpt_IrqHandler(1, 6);
        #endif

        #if (defined ICU_EMIOS_1_CH_6_ISR_USED)
        Emios_Icu_IrqHandler(1, 6);
        #endif

        #if (defined OCU_EMIOS_1_CH_6_ISR_USED)
        Emios_Ocu_IrqHandler(1, 6);
        #endif

        #if (defined PWM_EMIOS_1_CH_6_ISR_USED)
        Emios_Pwm_IrqHandler(1, 6);
        #endif
    #endif

    #if (defined EMIOS_1_CH_7_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_7_ISR_USED)
        Emios_Gpt_IrqHandler(1, 7);
        #endif

        #if (defined ICU_EMIOS_1_CH_7_ISR_USED)
        Emios_Icu_IrqHandler(1, 7);
        #endif

        #if (defined OCU_EMIOS_1_CH_7_ISR_USED)
        Emios_Ocu_IrqHandler(1, 7);
        #endif

        #if (defined PWM_EMIOS_1_CH_7_ISR_USED)
        Emios_Pwm_IrqHandler(1, 7);
        #endif
    #endif

}
#endif
#if (\
        (defined GPT_EMIOS_1_CH_8_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_9_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_10_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_11_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_8_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_9_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_10_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_11_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_8_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_9_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_10_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_11_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_8_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_9_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_10_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_11_ISR_USED)\
    )
/**
* @brief    Interrupt handler for Emios channels 8-11 for Emios instance 1
* @details  Process the interrupt of eMios channels 8-11
*
* @note     This will be defined only if EMIOS channels 8, 9, 10, 11 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_3_IRQ)
{
    #if (defined EMIOS_1_CH_8_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_8_ISR_USED)
        Emios_Gpt_IrqHandler(1, 8);
        #endif

        #if (defined ICU_EMIOS_1_CH_8_ISR_USED)
        Emios_Icu_IrqHandler(1, 8);
        #endif

        #if (defined OCU_EMIOS_1_CH_8_ISR_USED)
        Emios_Ocu_IrqHandler(1, 8);
        #endif

        #if (defined PWM_EMIOS_1_CH_8_ISR_USED)
        Emios_Pwm_IrqHandler(1, 8);
        #endif
    #endif

    #if (defined EMIOS_1_CH_9_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_9_ISR_USED)
        Emios_Gpt_IrqHandler(1, 9);
        #endif

        #if (defined ICU_EMIOS_1_CH_9_ISR_USED)
        Emios_Icu_IrqHandler(1, 9);
        #endif

        #if (defined OCU_EMIOS_1_CH_9_ISR_USED)
        Emios_Ocu_IrqHandler(1, 9);
        #endif

        #if (defined PWM_EMIOS_1_CH_9_ISR_USED)
        Emios_Pwm_IrqHandler(1, 9);
        #endif
    #endif

    #if (defined EMIOS_1_CH_10_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_10_ISR_USED)
        Emios_Gpt_IrqHandler(1, 10);
        #endif

        #if (defined ICU_EMIOS_1_CH_10_ISR_USED)
        Emios_Icu_IrqHandler(1, 10);
        #endif

        #if (defined OCU_EMIOS_1_CH_10_ISR_USED)
        Emios_Ocu_IrqHandler(1, 10);
        #endif

        #if (defined PWM_EMIOS_1_CH_10_ISR_USED)
        Emios_Pwm_IrqHandler(1, 10);
        #endif
    #endif

    #if (defined EMIOS_1_CH_11_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_11_ISR_USED)
        Emios_Gpt_IrqHandler(1, 11);
        #endif

        #if (defined ICU_EMIOS_1_CH_11_ISR_USED)
        Emios_Icu_IrqHandler(1, 11);
        #endif

        #if (defined OCU_EMIOS_1_CH_11_ISR_USED)
        Emios_Ocu_IrqHandler(1, 11);
        #endif

        #if (defined PWM_EMIOS_1_CH_11_ISR_USED)
        Emios_Pwm_IrqHandler(1, 11);
        #endif
    #endif

}
#endif
#if (\
        (defined GPT_EMIOS_1_CH_12_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_13_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_14_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_15_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_12_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_13_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_14_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_15_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_12_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_13_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_14_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_15_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_12_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_13_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_14_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_15_ISR_USED)\
    )
/**
* @brief    Interrupt handler for Emios channels 12-15 for Emios instance 1
* @details  Process the interrupt of eMios channels 12-15
*
* @note     This will be defined only if EMIOS channels 12, 13, 14, 15 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_2_IRQ)
{
    #if (defined EMIOS_1_CH_12_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_12_ISR_USED)
        Emios_Gpt_IrqHandler(1, 12);
        #endif

        #if (defined ICU_EMIOS_1_CH_12_ISR_USED)
        Emios_Icu_IrqHandler(1, 12);
        #endif

        #if (defined OCU_EMIOS_1_CH_12_ISR_USED)
        Emios_Ocu_IrqHandler(1, 12);
        #endif

        #if (defined PWM_EMIOS_1_CH_12_ISR_USED)
        Emios_Pwm_IrqHandler(1, 12);
        #endif
    #endif

    #if (defined EMIOS_1_CH_13_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_13_ISR_USED)
        Emios_Gpt_IrqHandler(1, 13);
        #endif

        #if (defined ICU_EMIOS_1_CH_13_ISR_USED)
        Emios_Icu_IrqHandler(1, 13);
        #endif

        #if (defined OCU_EMIOS_1_CH_13_ISR_USED)
        Emios_Ocu_IrqHandler(1, 13);
        #endif

        #if (defined PWM_EMIOS_1_CH_13_ISR_USED)
        Emios_Pwm_IrqHandler(1, 13);
        #endif
    #endif

    #if (defined EMIOS_1_CH_14_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_14_ISR_USED)
        Emios_Gpt_IrqHandler(1, 14);
        #endif

        #if (defined ICU_EMIOS_1_CH_14_ISR_USED)
        Emios_Icu_IrqHandler(1, 14);
        #endif

        #if (defined OCU_EMIOS_1_CH_14_ISR_USED)
        Emios_Ocu_IrqHandler(1, 14);
        #endif

        #if (defined PWM_EMIOS_1_CH_14_ISR_USED)
        Emios_Pwm_IrqHandler(1, 14);
        #endif
    #endif

    #if (defined EMIOS_1_CH_15_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_15_ISR_USED)
        Emios_Gpt_IrqHandler(1, 15);
        #endif

        #if (defined ICU_EMIOS_1_CH_15_ISR_USED)
        Emios_Icu_IrqHandler(1, 15);
        #endif

        #if (defined OCU_EMIOS_1_CH_15_ISR_USED)
        Emios_Ocu_IrqHandler(1, 15);
        #endif

        #if (defined PWM_EMIOS_1_CH_15_ISR_USED)
        Emios_Pwm_IrqHandler(1, 15);
        #endif
    #endif

}
#endif
#if (\
        (defined GPT_EMIOS_1_CH_16_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_17_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_18_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_19_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_16_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_17_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_18_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_19_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_16_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_17_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_18_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_19_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_16_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_17_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_18_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_19_ISR_USED)\
    )
/**
* @brief    Interrupt handler for Emios channels 16-19 for Emios instance 1
* @details  Process the interrupt of eMios channels 16-19
*
* @note     This will be defined only if EMIOS channels 16, 17, 18, 19 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_1_IRQ)
{
    #if (defined EMIOS_1_CH_16_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_16_ISR_USED)
        Emios_Gpt_IrqHandler(1, 16);
        #endif

        #if (defined ICU_EMIOS_1_CH_16_ISR_USED)
        Emios_Icu_IrqHandler(1, 16);
        #endif

        #if (defined OCU_EMIOS_1_CH_16_ISR_USED)
        Emios_Ocu_IrqHandler(1, 16);
        #endif

        #if (defined PWM_EMIOS_1_CH_16_ISR_USED)
        Emios_Pwm_IrqHandler(1, 16);
        #endif
    #endif

    #if (defined EMIOS_1_CH_17_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_17_ISR_USED)
        Emios_Gpt_IrqHandler(1, 17);
        #endif

        #if (defined ICU_EMIOS_1_CH_17_ISR_USED)
        Emios_Icu_IrqHandler(1, 17);
        #endif

        #if (defined OCU_EMIOS_1_CH_17_ISR_USED)
        Emios_Ocu_IrqHandler(1, 17);
        #endif

        #if (defined PWM_EMIOS_1_CH_17_ISR_USED)
        Emios_Pwm_IrqHandler(1, 17);
        #endif
    #endif

    #if (defined EMIOS_1_CH_18_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_18_ISR_USED)
        Emios_Gpt_IrqHandler(1, 18);
        #endif

        #if (defined ICU_EMIOS_1_CH_18_ISR_USED)
        Emios_Icu_IrqHandler(1, 18);
        #endif

        #if (defined OCU_EMIOS_1_CH_18_ISR_USED)
        Emios_Ocu_IrqHandler(1, 18);
        #endif

        #if (defined PWM_EMIOS_1_CH_18_ISR_USED)
        Emios_Pwm_IrqHandler(1, 18);
        #endif
    #endif

    #if (defined EMIOS_1_CH_19_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_19_ISR_USED)
        Emios_Gpt_IrqHandler(1, 19);
        #endif

        #if (defined ICU_EMIOS_1_CH_19_ISR_USED)
        Emios_Icu_IrqHandler(1, 19);
        #endif

        #if (defined OCU_EMIOS_1_CH_19_ISR_USED)
        Emios_Ocu_IrqHandler(1, 19);
        #endif

        #if (defined PWM_EMIOS_1_CH_19_ISR_USED)
        Emios_Pwm_IrqHandler(1, 19);
        #endif
    #endif

}
#endif
#if (\
        (defined GPT_EMIOS_1_CH_20_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_21_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_22_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_23_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_20_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_21_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_22_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_23_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_20_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_21_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_22_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_23_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_20_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_21_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_22_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_23_ISR_USED)\
    )
/**
* @brief    Interrupt handler for Emios channels 20-23 for Emios instance 1
* @details  Process the interrupt of eMios channels 20-23
*
* @note     This will be defined only if EMIOS channels 20, 21, 22, 23 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_0_IRQ)
{
    #if (defined EMIOS_1_CH_20_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_20_ISR_USED)
        Emios_Gpt_IrqHandler(1, 20);
        #endif

        #if (defined ICU_EMIOS_1_CH_20_ISR_USED)
        Emios_Icu_IrqHandler(1, 20);
        #endif

        #if (defined OCU_EMIOS_1_CH_20_ISR_USED)
        Emios_Ocu_IrqHandler(1, 20);
        #endif

        #if (defined PWM_EMIOS_1_CH_20_ISR_USED)
        Emios_Pwm_IrqHandler(1, 20);
        #endif
    #endif

    #if (defined EMIOS_1_CH_21_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_21_ISR_USED)
        Emios_Gpt_IrqHandler(1, 21);
        #endif

        #if (defined ICU_EMIOS_1_CH_21_ISR_USED)
        Emios_Icu_IrqHandler(1, 21);
        #endif

        #if (defined OCU_EMIOS_1_CH_21_ISR_USED)
        Emios_Ocu_IrqHandler(1, 21);
        #endif

        #if (defined PWM_EMIOS_1_CH_21_ISR_USED)
        Emios_Pwm_IrqHandler(1, 21);
        #endif
    #endif

    #if (defined EMIOS_1_CH_22_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_22_ISR_USED)
        Emios_Gpt_IrqHandler(1, 22);
        #endif

        #if (defined ICU_EMIOS_1_CH_22_ISR_USED)
        Emios_Icu_IrqHandler(1, 22);
        #endif

        #if (defined OCU_EMIOS_1_CH_22_ISR_USED)
        Emios_Ocu_IrqHandler(1, 22);
        #endif

        #if (defined PWM_EMIOS_1_CH_22_ISR_USED)
        Emios_Pwm_IrqHandler(1, 22);
        #endif
    #endif

    #if (defined EMIOS_1_CH_23_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_23_ISR_USED)
        Emios_Gpt_IrqHandler(1, 23);
        #endif

        #if (defined ICU_EMIOS_1_CH_23_ISR_USED)
        Emios_Icu_IrqHandler(1, 23);
        #endif

        #if (defined OCU_EMIOS_1_CH_23_ISR_USED)
        Emios_Ocu_IrqHandler(1, 23);
        #endif

        #if (defined PWM_EMIOS_1_CH_23_ISR_USED)
        Emios_Pwm_IrqHandler(1, 23);
        #endif
    #endif

}
#endif

#if (\
        (defined GPT_EMIOS_2_CH_0_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_1_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_2_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_3_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_0_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_1_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_2_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_3_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_0_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_1_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_2_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_3_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_0_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_1_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_2_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_3_ISR_USED)\
    )
/**
* @brief    Interrupt handler for Emios channels 0-3 for Emios instance 2
* @details  Process the interrupt of eMios channels 0-3
*
* @note     This will be defined only if EMIOS channels 0, 1, 2, 3 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS2_5_IRQ)
{
    #if (defined EMIOS_2_CH_0_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_0_ISR_USED)
        Emios_Gpt_IrqHandler(2, 0);
        #endif

        #if (defined ICU_EMIOS_2_CH_0_ISR_USED)
        Emios_Icu_IrqHandler(2, 0);
        #endif

        #if (defined OCU_EMIOS_2_CH_0_ISR_USED)
        Emios_Ocu_IrqHandler(2, 0);
        #endif

        #if (defined PWM_EMIOS_2_CH_0_ISR_USED)
        Emios_Pwm_IrqHandler(2, 0);
        #endif
    #endif

    #if (defined EMIOS_2_CH_1_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_1_ISR_USED)
        Emios_Gpt_IrqHandler(2, 1);
        #endif

        #if (defined ICU_EMIOS_2_CH_1_ISR_USED)
        Emios_Icu_IrqHandler(2, 1);
        #endif

        #if (defined OCU_EMIOS_2_CH_1_ISR_USED)
        Emios_Ocu_IrqHandler(2, 1);
        #endif

        #if (defined PWM_EMIOS_2_CH_1_ISR_USED)
        Emios_Pwm_IrqHandler(2, 1);
        #endif
    #endif

    #if (defined EMIOS_2_CH_2_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_2_ISR_USED)
        Emios_Gpt_IrqHandler(2, 2);
        #endif

        #if (defined ICU_EMIOS_2_CH_2_ISR_USED)
        Emios_Icu_IrqHandler(2, 2);
        #endif

        #if (defined OCU_EMIOS_2_CH_2_ISR_USED)
        Emios_Ocu_IrqHandler(2, 2);
        #endif

        #if (defined PWM_EMIOS_2_CH_2_ISR_USED)
        Emios_Pwm_IrqHandler(2, 2);
        #endif
    #endif

    #if (defined EMIOS_2_CH_3_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_3_ISR_USED)
        Emios_Gpt_IrqHandler(2, 3);
        #endif

        #if (defined ICU_EMIOS_2_CH_3_ISR_USED)
        Emios_Icu_IrqHandler(2, 3);
        #endif

        #if (defined OCU_EMIOS_2_CH_3_ISR_USED)
        Emios_Ocu_IrqHandler(2, 3);
        #endif

        #if (defined PWM_EMIOS_2_CH_3_ISR_USED)
        Emios_Pwm_IrqHandler(2, 3);
        #endif
    #endif

}
#endif
#if (\
        (defined GPT_EMIOS_2_CH_4_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_5_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_6_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_7_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_4_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_5_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_6_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_7_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_4_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_5_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_6_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_7_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_4_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_5_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_6_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_7_ISR_USED)\
    )
/**
* @brief    Interrupt handler for Emios channels 4-7 for Emios instance 2
* @details  Process the interrupt of eMios channels 4-7
*
* @note     This will be defined only if EMIOS channels 4, 5, 6, 7 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS2_4_IRQ)
{
    #if (defined EMIOS_2_CH_4_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_4_ISR_USED)
        Emios_Gpt_IrqHandler(2, 4);
        #endif

        #if (defined ICU_EMIOS_2_CH_4_ISR_USED)
        Emios_Icu_IrqHandler(2, 4);
        #endif

        #if (defined OCU_EMIOS_2_CH_4_ISR_USED)
        Emios_Ocu_IrqHandler(2, 4);
        #endif

        #if (defined PWM_EMIOS_2_CH_4_ISR_USED)
        Emios_Pwm_IrqHandler(2, 4);
        #endif
    #endif

    #if (defined EMIOS_2_CH_5_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_5_ISR_USED)
        Emios_Gpt_IrqHandler(2, 5);
        #endif

        #if (defined ICU_EMIOS_2_CH_5_ISR_USED)
        Emios_Icu_IrqHandler(2, 5);
        #endif

        #if (defined OCU_EMIOS_2_CH_5_ISR_USED)
        Emios_Ocu_IrqHandler(2, 5);
        #endif

        #if (defined PWM_EMIOS_2_CH_5_ISR_USED)
        Emios_Pwm_IrqHandler(2, 5);
        #endif
    #endif

    #if (defined EMIOS_2_CH_6_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_6_ISR_USED)
        Emios_Gpt_IrqHandler(2, 6);
        #endif

        #if (defined ICU_EMIOS_2_CH_6_ISR_USED)
        Emios_Icu_IrqHandler(2, 6);
        #endif

        #if (defined OCU_EMIOS_2_CH_6_ISR_USED)
        Emios_Ocu_IrqHandler(2, 6);
        #endif

        #if (defined PWM_EMIOS_2_CH_6_ISR_USED)
        Emios_Pwm_IrqHandler(2, 6);
        #endif
    #endif

    #if (defined EMIOS_2_CH_7_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_7_ISR_USED)
        Emios_Gpt_IrqHandler(2, 7);
        #endif

        #if (defined ICU_EMIOS_2_CH_7_ISR_USED)
        Emios_Icu_IrqHandler(2, 7);
        #endif

        #if (defined OCU_EMIOS_2_CH_7_ISR_USED)
        Emios_Ocu_IrqHandler(2, 7);
        #endif

        #if (defined PWM_EMIOS_2_CH_7_ISR_USED)
        Emios_Pwm_IrqHandler(2, 7);
        #endif
    #endif

}
#endif
#if (\
        (defined GPT_EMIOS_2_CH_8_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_9_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_10_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_11_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_8_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_9_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_10_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_11_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_8_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_9_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_10_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_11_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_8_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_9_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_10_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_11_ISR_USED)\
    )
/**
* @brief    Interrupt handler for Emios channels 8-11 for Emios instance 2
* @details  Process the interrupt of eMios channels 8-11
*
* @note     This will be defined only if EMIOS channels 8, 9, 10, 11 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS2_3_IRQ)
{
    #if (defined EMIOS_2_CH_8_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_8_ISR_USED)
        Emios_Gpt_IrqHandler(2, 8);
        #endif

        #if (defined ICU_EMIOS_2_CH_8_ISR_USED)
        Emios_Icu_IrqHandler(2, 8);
        #endif

        #if (defined OCU_EMIOS_2_CH_8_ISR_USED)
        Emios_Ocu_IrqHandler(2, 8);
        #endif

        #if (defined PWM_EMIOS_2_CH_8_ISR_USED)
        Emios_Pwm_IrqHandler(2, 8);
        #endif
    #endif

    #if (defined EMIOS_2_CH_9_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_9_ISR_USED)
        Emios_Gpt_IrqHandler(2, 9);
        #endif

        #if (defined ICU_EMIOS_2_CH_9_ISR_USED)
        Emios_Icu_IrqHandler(2, 9);
        #endif

        #if (defined OCU_EMIOS_2_CH_9_ISR_USED)
        Emios_Ocu_IrqHandler(2, 9);
        #endif

        #if (defined PWM_EMIOS_2_CH_9_ISR_USED)
        Emios_Pwm_IrqHandler(2, 9);
        #endif
    #endif

    #if (defined EMIOS_2_CH_10_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_10_ISR_USED)
        Emios_Gpt_IrqHandler(2, 10);
        #endif

        #if (defined ICU_EMIOS_2_CH_10_ISR_USED)
        Emios_Icu_IrqHandler(2, 10);
        #endif

        #if (defined OCU_EMIOS_2_CH_10_ISR_USED)
        Emios_Ocu_IrqHandler(2, 10);
        #endif

        #if (defined PWM_EMIOS_2_CH_10_ISR_USED)
        Emios_Pwm_IrqHandler(2, 10);
        #endif
    #endif

    #if (defined EMIOS_2_CH_11_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_11_ISR_USED)
        Emios_Gpt_IrqHandler(2, 11);
        #endif

        #if (defined ICU_EMIOS_2_CH_11_ISR_USED)
        Emios_Icu_IrqHandler(2, 11);
        #endif

        #if (defined OCU_EMIOS_2_CH_11_ISR_USED)
        Emios_Ocu_IrqHandler(2, 11);
        #endif

        #if (defined PWM_EMIOS_2_CH_11_ISR_USED)
        Emios_Pwm_IrqHandler(2, 11);
        #endif
    #endif

}
#endif
#if (\
        (defined GPT_EMIOS_2_CH_12_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_13_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_14_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_15_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_12_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_13_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_14_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_15_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_12_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_13_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_14_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_15_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_12_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_13_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_14_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_15_ISR_USED)\
    )
/**
* @brief    Interrupt handler for Emios channels 12-15 for Emios instance 2
* @details  Process the interrupt of eMios channels 12-15
*
* @note     This will be defined only if EMIOS channels 12, 13, 14, 15 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS2_2_IRQ)
{
    #if (defined EMIOS_2_CH_12_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_12_ISR_USED)
        Emios_Gpt_IrqHandler(2, 12);
        #endif

        #if (defined ICU_EMIOS_2_CH_12_ISR_USED)
        Emios_Icu_IrqHandler(2, 12);
        #endif

        #if (defined OCU_EMIOS_2_CH_12_ISR_USED)
        Emios_Ocu_IrqHandler(2, 12);
        #endif

        #if (defined PWM_EMIOS_2_CH_12_ISR_USED)
        Emios_Pwm_IrqHandler(2, 12);
        #endif
    #endif

    #if (defined EMIOS_2_CH_13_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_13_ISR_USED)
        Emios_Gpt_IrqHandler(2, 13);
        #endif

        #if (defined ICU_EMIOS_2_CH_13_ISR_USED)
        Emios_Icu_IrqHandler(2, 13);
        #endif

        #if (defined OCU_EMIOS_2_CH_13_ISR_USED)
        Emios_Ocu_IrqHandler(2, 13);
        #endif

        #if (defined PWM_EMIOS_2_CH_13_ISR_USED)
        Emios_Pwm_IrqHandler(2, 13);
        #endif
    #endif

    #if (defined EMIOS_2_CH_14_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_14_ISR_USED)
        Emios_Gpt_IrqHandler(2, 14);
        #endif

        #if (defined ICU_EMIOS_2_CH_14_ISR_USED)
        Emios_Icu_IrqHandler(2, 14);
        #endif

        #if (defined OCU_EMIOS_2_CH_14_ISR_USED)
        Emios_Ocu_IrqHandler(2, 14);
        #endif

        #if (defined PWM_EMIOS_2_CH_14_ISR_USED)
        Emios_Pwm_IrqHandler(2, 14);
        #endif
    #endif

    #if (defined EMIOS_2_CH_15_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_15_ISR_USED)
        Emios_Gpt_IrqHandler(2, 15);
        #endif

        #if (defined ICU_EMIOS_2_CH_15_ISR_USED)
        Emios_Icu_IrqHandler(2, 15);
        #endif

        #if (defined OCU_EMIOS_2_CH_15_ISR_USED)
        Emios_Ocu_IrqHandler(2, 15);
        #endif

        #if (defined PWM_EMIOS_2_CH_15_ISR_USED)
        Emios_Pwm_IrqHandler(2, 15);
        #endif
    #endif

}
#endif
#if (\
        (defined GPT_EMIOS_2_CH_16_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_17_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_18_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_19_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_16_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_17_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_18_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_19_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_16_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_17_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_18_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_19_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_16_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_17_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_18_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_19_ISR_USED)\
    )
/**
* @brief    Interrupt handler for Emios channels 16-19 for Emios instance 2
* @details  Process the interrupt of eMios channels 16-19
*
* @note     This will be defined only if EMIOS channels 16, 17, 18, 19 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS2_1_IRQ)
{
    #if (defined EMIOS_2_CH_16_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_16_ISR_USED)
        Emios_Gpt_IrqHandler(2, 16);
        #endif

        #if (defined ICU_EMIOS_2_CH_16_ISR_USED)
        Emios_Icu_IrqHandler(2, 16);
        #endif

        #if (defined OCU_EMIOS_2_CH_16_ISR_USED)
        Emios_Ocu_IrqHandler(2, 16);
        #endif

        #if (defined PWM_EMIOS_2_CH_16_ISR_USED)
        Emios_Pwm_IrqHandler(2, 16);
        #endif
    #endif

    #if (defined EMIOS_2_CH_17_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_17_ISR_USED)
        Emios_Gpt_IrqHandler(2, 17);
        #endif

        #if (defined ICU_EMIOS_2_CH_17_ISR_USED)
        Emios_Icu_IrqHandler(2, 17);
        #endif

        #if (defined OCU_EMIOS_2_CH_17_ISR_USED)
        Emios_Ocu_IrqHandler(2, 17);
        #endif

        #if (defined PWM_EMIOS_2_CH_17_ISR_USED)
        Emios_Pwm_IrqHandler(2, 17);
        #endif
    #endif

    #if (defined EMIOS_2_CH_18_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_18_ISR_USED)
        Emios_Gpt_IrqHandler(2, 18);
        #endif

        #if (defined ICU_EMIOS_2_CH_18_ISR_USED)
        Emios_Icu_IrqHandler(2, 18);
        #endif

        #if (defined OCU_EMIOS_2_CH_18_ISR_USED)
        Emios_Ocu_IrqHandler(2, 18);
        #endif

        #if (defined PWM_EMIOS_2_CH_18_ISR_USED)
        Emios_Pwm_IrqHandler(2, 18);
        #endif
    #endif

    #if (defined EMIOS_2_CH_19_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_19_ISR_USED)
        Emios_Gpt_IrqHandler(2, 19);
        #endif

        #if (defined ICU_EMIOS_2_CH_19_ISR_USED)
        Emios_Icu_IrqHandler(2, 19);
        #endif

        #if (defined OCU_EMIOS_2_CH_19_ISR_USED)
        Emios_Ocu_IrqHandler(2, 19);
        #endif

        #if (defined PWM_EMIOS_2_CH_19_ISR_USED)
        Emios_Pwm_IrqHandler(2, 19);
        #endif
    #endif

}
#endif
#if (\
        (defined GPT_EMIOS_2_CH_20_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_21_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_22_ISR_USED) ||\
        (defined GPT_EMIOS_2_CH_23_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_20_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_21_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_22_ISR_USED) ||\
        (defined ICU_EMIOS_2_CH_23_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_20_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_21_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_22_ISR_USED) ||\
        (defined OCU_EMIOS_2_CH_23_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_20_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_21_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_22_ISR_USED) ||\
        (defined PWM_EMIOS_2_CH_23_ISR_USED)\
    )
/**
* @brief    Interrupt handler for Emios channels 20-23 for Emios instance 2
* @details  Process the interrupt of eMios channels 20-23
*
* @note     This will be defined only if EMIOS channels 20, 21, 22, 23 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS2_0_IRQ)
{
    #if (defined EMIOS_2_CH_20_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_20_ISR_USED)
        Emios_Gpt_IrqHandler(2, 20);
        #endif

        #if (defined ICU_EMIOS_2_CH_20_ISR_USED)
        Emios_Icu_IrqHandler(2, 20);
        #endif

        #if (defined OCU_EMIOS_2_CH_20_ISR_USED)
        Emios_Ocu_IrqHandler(2, 20);
        #endif

        #if (defined PWM_EMIOS_2_CH_20_ISR_USED)
        Emios_Pwm_IrqHandler(2, 20);
        #endif
    #endif

    #if (defined EMIOS_2_CH_21_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_21_ISR_USED)
        Emios_Gpt_IrqHandler(2, 21);
        #endif

        #if (defined ICU_EMIOS_2_CH_21_ISR_USED)
        Emios_Icu_IrqHandler(2, 21);
        #endif

        #if (defined OCU_EMIOS_2_CH_21_ISR_USED)
        Emios_Ocu_IrqHandler(2, 21);
        #endif

        #if (defined PWM_EMIOS_2_CH_21_ISR_USED)
        Emios_Pwm_IrqHandler(2, 21);
        #endif
    #endif

    #if (defined EMIOS_2_CH_22_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_22_ISR_USED)
        Emios_Gpt_IrqHandler(2, 22);
        #endif

        #if (defined ICU_EMIOS_2_CH_22_ISR_USED)
        Emios_Icu_IrqHandler(2, 22);
        #endif

        #if (defined OCU_EMIOS_2_CH_22_ISR_USED)
        Emios_Ocu_IrqHandler(2, 22);
        #endif

        #if (defined PWM_EMIOS_2_CH_22_ISR_USED)
        Emios_Pwm_IrqHandler(2, 22);
        #endif
    #endif

    #if (defined EMIOS_2_CH_23_ISR_USED)
        #if (defined GPT_EMIOS_2_CH_23_ISR_USED)
        Emios_Gpt_IrqHandler(2, 23);
        #endif

        #if (defined ICU_EMIOS_2_CH_23_ISR_USED)
        Emios_Icu_IrqHandler(2, 23);
        #endif

        #if (defined OCU_EMIOS_2_CH_23_ISR_USED)
        Emios_Ocu_IrqHandler(2, 23);
        #endif

        #if (defined PWM_EMIOS_2_CH_23_ISR_USED)
        Emios_Pwm_IrqHandler(2, 23);
        #endif
    #endif

}
#endif


#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
