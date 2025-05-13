/*
 * Copyright 2021-2025 NXP
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
#define EMIOS_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION_C        7
#define EMIOS_MCL_IP_IRQ_AR_RELEASE_REVISION_VERSION_C     0
#define EMIOS_MCL_IP_IRQ_SW_MAJOR_VERSION_C                2
#define EMIOS_MCL_IP_IRQ_SW_MINOR_VERSION_C                0
#define EMIOS_MCL_IP_IRQ_SW_PATCH_VERSION_C                1
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
#define MCL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mcl_MemMap.h"

/* Array with EMIOS bases addresses. */
extern eMIOS_Type* Emios_Ip_paxBase[eMIOS_INSTANCE_COUNT];

#define MCL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
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
        if (0U != ((Emios_Ip_paxBase[Instance]->CH.UC[Channel].C) & ((uint32)(eMIOS_C_DMA_MASK | eMIOS_C_FEN_MASK))))
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
        if (0U != ((Emios_Ip_paxBase[Instance]->CH.UC[Channel].C) & ((uint32)(eMIOS_C_DMA_MASK | eMIOS_C_FEN_MASK))))
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
        if (0U != ((Emios_Ip_paxBase[Instance]->CH.UC[Channel].C) & ((uint32)(eMIOS_C_DMA_MASK | eMIOS_C_FEN_MASK))))
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
        if (0U != ((Emios_Ip_paxBase[Instance]->CH.UC[Channel].C) & ((uint32)(eMIOS_C_DMA_MASK | eMIOS_C_FEN_MASK))))
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
#if (\
        (defined GPT_EMIOS_0_CH_8_ISR_USED)  ||\
        (defined GPT_EMIOS_0_CH_10_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_12_ISR_USED) ||\
        (defined GPT_EMIOS_0_CH_14_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_8_ISR_USED)  ||\
        (defined GPT_EMIOS_1_CH_10_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_12_ISR_USED) ||\
        (defined GPT_EMIOS_1_CH_14_ISR_USED) \
    )
static void Emios_Gpt_Wsc_IrqHandler(const uint8 Instance, const uint8 Channel)
{
    uint32 u32WsChannelFlag = eMIOS_WSS_FLAGCAP_MASK | eMIOS_WSS_FLAGCE_MASK | eMIOS_WSS_FLAGECO_MASK | eMIOS_WSS_FLAGPWO_MASK | eMIOS_WSS_FLAGPW_MASK | eMIOS_WSS_FLAGFF_MASK;

    /* Check that an event occurred on Emios wheel speed channel */
    if (0U != ((Emios_Ip_paxBase[Instance]->CH.WSC[Channel/2].WSS) & (uint32)u32WsChannelFlag))
    {
        /* Check that an event occurred on EMIOS wheel speed channel */
        if (0U != ((Emios_Ip_paxBase[Instance]->CH.WSC[Channel/2].WSC1) & ((uint32)eMIOS_WSC1_FEN_MASK)))
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
        (defined ICU_EMIOS_0_CH_8_ISR_USED)  ||\
        (defined ICU_EMIOS_0_CH_10_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_12_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_14_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_8_ISR_USED)  ||\
        (defined ICU_EMIOS_1_CH_10_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_12_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_14_ISR_USED) \
    )
static void Emios_Icu_Wsc_IrqHandler(const uint8 Instance, const uint8 Channel)
{
    uint32 u32WsChannelFlag = eMIOS_WSS_FLAGCAP_MASK | eMIOS_WSS_FLAGCE_MASK | eMIOS_WSS_FLAGECO_MASK | eMIOS_WSS_FLAGPWO_MASK | eMIOS_WSS_FLAGPW_MASK | eMIOS_WSS_FLAGFF_MASK;

    /* Check that an event occurred on Emios wheel speed channel */
    if (0U != ((Emios_Ip_paxBase[Instance]->CH.WSC[Channel/2].WSS) & (uint32)u32WsChannelFlag))
    {
        /* Check that an event occurred on EMIOS wheel speed channel */
        if (0U != ((Emios_Ip_paxBase[Instance]->CH.WSC[Channel/2].WSC1) & ((uint32)eMIOS_WSC1_FEN_MASK)))
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
        (defined OCU_EMIOS_0_CH_8_ISR_USED)  ||\
        (defined OCU_EMIOS_0_CH_10_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_12_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_14_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_8_ISR_USED)  ||\
        (defined OCU_EMIOS_1_CH_10_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_12_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_14_ISR_USED) \
    )
static void Emios_Ocu_Wsc_IrqHandler(const uint8 Instance, const uint8 Channel)
{
    uint32 u32WsChannelFlag = eMIOS_WSS_FLAGCAP_MASK | eMIOS_WSS_FLAGCE_MASK | eMIOS_WSS_FLAGECO_MASK | eMIOS_WSS_FLAGPWO_MASK | eMIOS_WSS_FLAGPW_MASK | eMIOS_WSS_FLAGFF_MASK;

    /* Check that an event occurred on Emios wheel speed channel */
    if (0U != ((Emios_Ip_paxBase[Instance]->CH.WSC[Channel/2].WSS) & (uint32)u32WsChannelFlag))
    {
        /* Check that an event occurred on EMIOS wheel speed channel */
        if (0U != ((Emios_Ip_paxBase[Instance]->CH.WSC[Channel/2].WSC1) & ((uint32)eMIOS_WSC1_FEN_MASK)))
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
        (defined PWM_EMIOS_0_CH_8_ISR_USED)  ||\
        (defined PWM_EMIOS_0_CH_10_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_12_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_14_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_8_ISR_USED)  ||\
        (defined PWM_EMIOS_1_CH_10_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_12_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_14_ISR_USED) \
    )
static void Emios_Pwm_Wsc_IrqHandler(const uint8 Instance, const uint8 Channel)
{
    uint32 u32WsChannelFlag = eMIOS_WSS_FLAGCAP_MASK | eMIOS_WSS_FLAGCE_MASK | eMIOS_WSS_FLAGECO_MASK | eMIOS_WSS_FLAGPWO_MASK | eMIOS_WSS_FLAGPW_MASK | eMIOS_WSS_FLAGFF_MASK;

    /* Check that an event occurred on Emios wheel speed channel */
    if (0U != ((Emios_Ip_paxBase[Instance]->CH.WSC[Channel/2].WSS) & (uint32)u32WsChannelFlag))
    {
        /* Check that an event occurred on EMIOS wheel speed channel */
        if (0U != ((Emios_Ip_paxBase[Instance]->CH.WSC[Channel/2].WSC1) & ((uint32)eMIOS_WSC1_FEN_MASK)))
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
        (defined ICU_EMIOS_0_CH_0_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_0_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_0_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 0 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 0
*
* @note     This will be defined only if EMIOS channel 0 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH0_IRQ)
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
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_1_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_1_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_1_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_1_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 1 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 1
*
* @note     This will be defined only if EMIOS channel 1 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH1_IRQ)
{
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
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_2_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_2_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_2_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_2_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 2 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 2
*
* @note     This will be defined only if EMIOS channel 2 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH2_IRQ)
{
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
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_3_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_3_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_3_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_3_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 3 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 3
*
* @note     This will be defined only if EMIOS channel 3 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH3_IRQ)
{
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
        (defined ICU_EMIOS_0_CH_4_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_4_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_4_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 4 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 4
*
* @note     This will be defined only if EMIOS channel 4 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH4_IRQ)
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
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_5_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_5_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_5_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_5_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 5 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 5
*
* @note     This will be defined only if EMIOS channel 5 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH5_IRQ)
{
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
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_6_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_6_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_6_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_6_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 6 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 6
*
* @note     This will be defined only if EMIOS channel 6 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH6_IRQ)
{
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
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_7_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_7_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_7_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_7_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 7 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 7
*
* @note     This will be defined only if EMIOS channel 7 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH7_IRQ)
{
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
        (defined ICU_EMIOS_0_CH_8_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_8_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_8_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 8 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 8
*
* @note     This will be defined only if EMIOS channel 8 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH8_IRQ)
{
    #if (defined EMIOS_0_CH_8_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_8_ISR_USED)
        Emios_Gpt_Wsc_IrqHandler(0, 8);
        #endif

        #if (defined ICU_EMIOS_0_CH_8_ISR_USED)
        Emios_Icu_Wsc_IrqHandler(0, 8);
        #endif

        #if (defined OCU_EMIOS_0_CH_8_ISR_USED)
        Emios_Ocu_Wsc_IrqHandler(0, 8);
        #endif

        #if (defined PWM_EMIOS_0_CH_8_ISR_USED)
        Emios_Pwm_Wsc_IrqHandler(0, 8);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_9_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_9_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_9_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_9_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 9 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 9
*
* @note     This will be defined only if EMIOS channel 9 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH9_IRQ)
{
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
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_10_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_10_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_10_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_10_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 10 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 10
*
* @note     This will be defined only if EMIOS channel 10 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH10_IRQ)
{
    #if (defined EMIOS_0_CH_10_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_10_ISR_USED)
        Emios_Gpt_Wsc_IrqHandler(0, 10);
        #endif

        #if (defined ICU_EMIOS_0_CH_10_ISR_USED)
        Emios_Icu_Wsc_IrqHandler(0, 10);
        #endif

        #if (defined OCU_EMIOS_0_CH_10_ISR_USED)
        Emios_Ocu_Wsc_IrqHandler(0, 10);
        #endif

        #if (defined PWM_EMIOS_0_CH_10_ISR_USED)
        Emios_Pwm_Wsc_IrqHandler(0, 10);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_11_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_11_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_11_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_11_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 11 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 11
*
* @note     This will be defined only if EMIOS channel 11 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH11_IRQ)
{
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
        (defined ICU_EMIOS_0_CH_12_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_12_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_12_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 12 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 12
*
* @note     This will be defined only if EMIOS channel 12 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH12_IRQ)
{
     #if (defined EMIOS_0_CH_12_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_12_ISR_USED)
        Emios_Gpt_Wsc_IrqHandler(0, 12);
        #endif

        #if (defined ICU_EMIOS_0_CH_12_ISR_USED)
        Emios_Icu_Wsc_IrqHandler(0, 12);
        #endif

        #if (defined OCU_EMIOS_0_CH_12_ISR_USED)
        Emios_Ocu_Wsc_IrqHandler(0, 12);
        #endif

        #if (defined PWM_EMIOS_0_CH_12_ISR_USED)
        Emios_Pwm_Wsc_IrqHandler(0, 12);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_13_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_13_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_13_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_13_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 13 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 13
*
* @note     This will be defined only if EMIOS channel 13 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH13_IRQ)
{
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
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_14_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_14_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_14_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_14_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 14 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 14
*
* @note     This will be defined only if EMIOS channel 14 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH14_IRQ)
{
    #if (defined EMIOS_0_CH_14_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_14_ISR_USED)
        Emios_Gpt_Wsc_IrqHandler(0, 14);
        #endif

        #if (defined ICU_EMIOS_0_CH_14_ISR_USED)
        Emios_Icu_Wsc_IrqHandler(0, 14);
        #endif

        #if (defined OCU_EMIOS_0_CH_14_ISR_USED)
        Emios_Ocu_Wsc_IrqHandler(0, 14);
        #endif

        #if (defined PWM_EMIOS_0_CH_14_ISR_USED)
        Emios_Pwm_Wsc_IrqHandler(0, 14);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_15_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_15_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_15_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_15_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 15 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 15
*
* @note     This will be defined only if EMIOS channel 15 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH15_IRQ)
{
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
        (defined ICU_EMIOS_0_CH_16_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_16_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_16_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 16 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 16
*
* @note     This will be defined only if EMIOS channel 16 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH16_IRQ)
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
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_17_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_17_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_17_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_17_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 17 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 17
*
* @note     This will be defined only if EMIOS channel 17 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH17_IRQ)
{
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
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_18_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_18_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_18_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_18_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 18 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 18
*
* @note     This will be defined only if EMIOS channel 18 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH18_IRQ)
{
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
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_19_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_19_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_19_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_19_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 19 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 19
*
* @note     This will be defined only if EMIOS channel 19 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH19_IRQ)
{
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
        (defined ICU_EMIOS_0_CH_20_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_20_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_20_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 20 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 20
*
* @note     This will be defined only if EMIOS channel 20 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH20_IRQ)
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
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_21_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_21_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_21_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_21_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 21 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 21
*
* @note     This will be defined only if EMIOS channel 21 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH21_IRQ)
{
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
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_22_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_22_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_22_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_22_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 22 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 22
*
* @note     This will be defined only if EMIOS channel 22 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH22_IRQ)
{
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
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_23_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_23_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_23_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_23_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 23 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 23
*
* @note     This will be defined only if EMIOS channel 23 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH23_IRQ)
{
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
        (defined GPT_EMIOS_0_CH_24_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_24_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_24_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_24_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 24 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 24
*
* @note     This will be defined only if EMIOS channel 24 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH24_IRQ)
{
    #if (defined EMIOS_0_CH_24_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_24_ISR_USED)
        Emios_Gpt_IrqHandler(0, 24);
        #endif

        #if (defined ICU_EMIOS_0_CH_24_ISR_USED)
        Emios_Icu_IrqHandler(0, 24);
        #endif

        #if (defined OCU_EMIOS_0_CH_24_ISR_USED)
        Emios_Ocu_IrqHandler(0, 24);
        #endif

        #if (defined PWM_EMIOS_0_CH_24_ISR_USED)
        Emios_Pwm_IrqHandler(0, 24);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_25_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_25_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_25_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_25_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 25 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 25
*
* @note     This will be defined only if EMIOS channel 25 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH25_IRQ)
{
    #if (defined EMIOS_0_CH_25_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_25_ISR_USED)
        Emios_Gpt_IrqHandler(0, 25);
        #endif

        #if (defined ICU_EMIOS_0_CH_25_ISR_USED)
        Emios_Icu_IrqHandler(0, 25);
        #endif

        #if (defined OCU_EMIOS_0_CH_25_ISR_USED)
        Emios_Ocu_IrqHandler(0, 25);
        #endif

        #if (defined PWM_EMIOS_0_CH_25_ISR_USED)
        Emios_Pwm_IrqHandler(0, 25);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_26_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_26_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_26_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_26_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 26 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 26
*
* @note     This will be defined only if EMIOS channel 26 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH26_IRQ)
{
    #if (defined EMIOS_0_CH_26_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_26_ISR_USED)
        Emios_Gpt_IrqHandler(0, 26);
        #endif

        #if (defined ICU_EMIOS_0_CH_26_ISR_USED)
        Emios_Icu_IrqHandler(0, 26);
        #endif

        #if (defined OCU_EMIOS_0_CH_26_ISR_USED)
        Emios_Ocu_IrqHandler(0, 26);
        #endif

        #if (defined PWM_EMIOS_0_CH_26_ISR_USED)
        Emios_Pwm_IrqHandler(0, 26);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_27_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_27_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_27_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_27_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 27 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 27
*
* @note     This will be defined only if EMIOS channel 27 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH27_IRQ)
{
    #if (defined EMIOS_0_CH_27_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_27_ISR_USED)
        Emios_Gpt_IrqHandler(0, 27);
        #endif

        #if (defined ICU_EMIOS_0_CH_27_ISR_USED)
        Emios_Icu_IrqHandler(0, 27);
        #endif

        #if (defined OCU_EMIOS_0_CH_27_ISR_USED)
        Emios_Ocu_IrqHandler(0, 27);
        #endif

        #if (defined PWM_EMIOS_0_CH_27_ISR_USED)
        Emios_Pwm_IrqHandler(0, 27);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_28_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_28_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_28_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_28_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 28 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 28
*
* @note     This will be defined only if EMIOS channel 28 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH28_IRQ)
{
    #if (defined EMIOS_0_CH_28_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_28_ISR_USED)
        Emios_Gpt_IrqHandler(0, 28);
        #endif

        #if (defined ICU_EMIOS_0_CH_28_ISR_USED)
        Emios_Icu_IrqHandler(0, 28);
        #endif

        #if (defined OCU_EMIOS_0_CH_28_ISR_USED)
        Emios_Ocu_IrqHandler(0, 28);
        #endif

        #if (defined PWM_EMIOS_0_CH_28_ISR_USED)
        Emios_Pwm_IrqHandler(0, 28);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_29_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_29_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_29_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_29_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 29 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 29
*
* @note     This will be defined only if EMIOS channel 29 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH29_IRQ)
{
    #if (defined EMIOS_0_CH_29_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_29_ISR_USED)
        Emios_Gpt_IrqHandler(0, 29);
        #endif

        #if (defined ICU_EMIOS_0_CH_29_ISR_USED)
        Emios_Icu_IrqHandler(0, 29);
        #endif

        #if (defined OCU_EMIOS_0_CH_29_ISR_USED)
        Emios_Ocu_IrqHandler(0, 29);
        #endif

        #if (defined PWM_EMIOS_0_CH_29_ISR_USED)
        Emios_Pwm_IrqHandler(0, 29);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_30_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_30_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_30_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_30_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 30 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 30
*
* @note     This will be defined only if EMIOS channel 30 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH30_IRQ)
{
    #if (defined EMIOS_0_CH_30_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_30_ISR_USED)
        Emios_Gpt_IrqHandler(0, 30);
        #endif

        #if (defined ICU_EMIOS_0_CH_30_ISR_USED)
        Emios_Icu_IrqHandler(0, 30);
        #endif

        #if (defined OCU_EMIOS_0_CH_30_ISR_USED)
        Emios_Ocu_IrqHandler(0, 30);
        #endif

        #if (defined PWM_EMIOS_0_CH_30_ISR_USED)
        Emios_Pwm_IrqHandler(0, 30);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_0_CH_31_ISR_USED) ||\
        (defined ICU_EMIOS_0_CH_31_ISR_USED) ||\
        (defined OCU_EMIOS_0_CH_31_ISR_USED) ||\
        (defined PWM_EMIOS_0_CH_31_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 31 for Emios instance 0
* @details  Process the interrupt of EMIOS channel 31
*
* @note     This will be defined only if EMIOS channel 31 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_CH31_IRQ)
{
    #if (defined EMIOS_0_CH_31_ISR_USED)
        #if (defined GPT_EMIOS_0_CH_31_ISR_USED)
        Emios_Gpt_IrqHandler(0, 31);
        #endif

        #if (defined ICU_EMIOS_0_CH_31_ISR_USED)
        Emios_Icu_IrqHandler(0, 31);
        #endif

        #if (defined OCU_EMIOS_0_CH_31_ISR_USED)
        Emios_Ocu_IrqHandler(0, 31);
        #endif

        #if (defined PWM_EMIOS_0_CH_31_ISR_USED)
        Emios_Pwm_IrqHandler(0, 31);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_0_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_0_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_0_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_0_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 0 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 0
*
* @note     This will be defined only if EMIOS channel 0 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH0_IRQ)
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
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_1_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_1_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_1_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_1_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 1 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 1
*
* @note     This will be defined only if EMIOS channel 1 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH1_IRQ)
{
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
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_2_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_2_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_2_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_2_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 2 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 2
*
* @note     This will be defined only if EMIOS channel 2 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH2_IRQ)
{
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
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_3_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_3_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_3_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_3_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 3 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 3
*
* @note     This will be defined only if EMIOS channel 3 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH3_IRQ)
{
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
        (defined ICU_EMIOS_1_CH_4_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_4_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_4_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 4 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 4
*
* @note     This will be defined only if EMIOS channel 4 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH4_IRQ)
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
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_5_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_5_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_5_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_5_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 5 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 5
*
* @note     This will be defined only if EMIOS channel 5 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH5_IRQ)
{
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
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_6_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_6_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_6_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_6_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 6 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 6
*
* @note     This will be defined only if EMIOS channel 6 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH6_IRQ)
{
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
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_7_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_7_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_7_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_7_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 7 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 7
*
* @note     This will be defined only if EMIOS channel 7 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH7_IRQ)
{
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
        (defined ICU_EMIOS_1_CH_8_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_8_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_8_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 8 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 8
*
* @note     This will be defined only if EMIOS channel 8 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH8_IRQ)
{
    #if (defined EMIOS_1_CH_8_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_8_ISR_USED)
        Emios_Gpt_Wsc_IrqHandler(1, 8);
        #endif

        #if (defined ICU_EMIOS_1_CH_8_ISR_USED)
        Emios_Icu_Wsc_IrqHandler(1, 8);
        #endif

        #if (defined OCU_EMIOS_1_CH_8_ISR_USED)
        Emios_Ocu_Wsc_IrqHandler(1, 8);
        #endif

        #if (defined PWM_EMIOS_1_CH_8_ISR_USED)
        Emios_Pwm_Wsc_IrqHandler(1, 8);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_9_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_9_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_9_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_9_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 9 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 9
*
* @note     This will be defined only if EMIOS channel 9 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH9_IRQ)
{
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
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_10_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_10_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_10_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_10_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 10 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 10
*
* @note     This will be defined only if EMIOS channel 10 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH10_IRQ)
{
    #if (defined EMIOS_1_CH_10_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_10_ISR_USED)
        Emios_Gpt_Wsc_IrqHandler(1, 10);
        #endif

        #if (defined ICU_EMIOS_1_CH_10_ISR_USED)
        Emios_Icu_Wsc_IrqHandler(1, 10);
        #endif

        #if (defined OCU_EMIOS_1_CH_10_ISR_USED)
        Emios_Ocu_Wsc_IrqHandler(1, 10);
        #endif

        #if (defined PWM_EMIOS_1_CH_10_ISR_USED)
        Emios_Pwm_Wsc_IrqHandler(1, 10);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_11_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_11_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_11_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_11_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 11 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 11
*
* @note     This will be defined only if EMIOS channel 11 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH11_IRQ)
{
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
        (defined ICU_EMIOS_1_CH_12_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_12_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_12_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 12 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 12
*
* @note     This will be defined only if EMIOS channel 12 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH12_IRQ)
{
    #if (defined EMIOS_1_CH_12_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_12_ISR_USED)
        Emios_Gpt_Wsc_IrqHandler(1, 12);
        #endif

        #if (defined ICU_EMIOS_1_CH_12_ISR_USED)
        Emios_Icu_Wsc_IrqHandler(1, 12);
        #endif

        #if (defined OCU_EMIOS_1_CH_12_ISR_USED)
        Emios_Ocu_Wsc_IrqHandler(1, 12);
        #endif

        #if (defined PWM_EMIOS_1_CH_12_ISR_USED)
        Emios_Pwm_Wsc_IrqHandler(1, 12);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_13_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_13_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_13_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_13_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 13 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 13
*
* @note     This will be defined only if EMIOS channel 13 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH13_IRQ)
{
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
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_14_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_14_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_14_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_14_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 14 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 14
*
* @note     This will be defined only if EMIOS channel 14 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH14_IRQ)
{
    #if (defined EMIOS_1_CH_14_ISR_USED)
            #if (defined GPT_EMIOS_1_CH_14_ISR_USED)
            Emios_Gpt_Wsc_IrqHandler(1, 14);
            #endif

            #if (defined ICU_EMIOS_1_CH_14_ISR_USED)
            Emios_Icu_Wsc_IrqHandler(1, 14);
            #endif

            #if (defined OCU_EMIOS_1_CH_14_ISR_USED)
            Emios_Ocu_Wsc_IrqHandler(1, 14);
            #endif

            #if (defined PWM_EMIOS_1_CH_14_ISR_USED)
            Emios_Pwm_Wsc_IrqHandler(1, 14);
            #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_15_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_15_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_15_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_15_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 15 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 15
*
* @note     This will be defined only if EMIOS channel 15 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH15_IRQ)
{
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
        (defined ICU_EMIOS_1_CH_16_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_16_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_16_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 16 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 16
*
* @note     This will be defined only if EMIOS channel 16 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH16_IRQ)
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
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_17_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_17_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_17_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_17_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 17 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 17
*
* @note     This will be defined only if EMIOS channel 17 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH17_IRQ)
{
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
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_18_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_18_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_18_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_18_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 18 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 18
*
* @note     This will be defined only if EMIOS channel 18 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH18_IRQ)
{
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
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_19_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_19_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_19_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_19_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 19 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 19
*
* @note     This will be defined only if EMIOS channel 19 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH19_IRQ)
{
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
        (defined ICU_EMIOS_1_CH_20_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_20_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_20_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 20 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 20
*
* @note     This will be defined only if EMIOS channel 20 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH20_IRQ)
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
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_21_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_21_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_21_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_21_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 21 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 21
*
* @note     This will be defined only if EMIOS channel 21 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH21_IRQ)
{
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
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_22_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_22_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_22_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_22_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 22 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 22
*
* @note     This will be defined only if EMIOS channel 22 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH22_IRQ)
{
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
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_23_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_23_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_23_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_23_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 23 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 23
*
* @note     This will be defined only if EMIOS channel 23 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH23_IRQ)
{
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
        (defined GPT_EMIOS_1_CH_24_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_24_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_24_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_24_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 24 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 24
*
* @note     This will be defined only if EMIOS channel 24 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH24_IRQ)
{
    #if (defined EMIOS_1_CH_24_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_24_ISR_USED)
        Emios_Gpt_IrqHandler(1, 24);
        #endif

        #if (defined ICU_EMIOS_1_CH_24_ISR_USED)
        Emios_Icu_IrqHandler(1, 24);
        #endif

        #if (defined OCU_EMIOS_1_CH_24_ISR_USED)
        Emios_Ocu_IrqHandler(1, 24);
        #endif

        #if (defined PWM_EMIOS_1_CH_24_ISR_USED)
        Emios_Pwm_IrqHandler(1, 24);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_25_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_25_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_25_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_25_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 25 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 25
*
* @note     This will be defined only if EMIOS channel 25 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH25_IRQ)
{
    #if (defined EMIOS_1_CH_25_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_25_ISR_USED)
        Emios_Gpt_IrqHandler(1, 25);
        #endif

        #if (defined ICU_EMIOS_1_CH_25_ISR_USED)
        Emios_Icu_IrqHandler(1, 25);
        #endif

        #if (defined OCU_EMIOS_1_CH_25_ISR_USED)
        Emios_Ocu_IrqHandler(1, 25);
        #endif

        #if (defined PWM_EMIOS_1_CH_25_ISR_USED)
        Emios_Pwm_IrqHandler(1, 25);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_26_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_26_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_26_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_26_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 26 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 26
*
* @note     This will be defined only if EMIOS channel 26 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH26_IRQ)
{
    #if (defined EMIOS_1_CH_26_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_26_ISR_USED)
        Emios_Gpt_IrqHandler(1, 26);
        #endif

        #if (defined ICU_EMIOS_1_CH_26_ISR_USED)
        Emios_Icu_IrqHandler(1, 26);
        #endif

        #if (defined OCU_EMIOS_1_CH_26_ISR_USED)
        Emios_Ocu_IrqHandler(1, 26);
        #endif

        #if (defined PWM_EMIOS_1_CH_26_ISR_USED)
        Emios_Pwm_IrqHandler(1, 26);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_27_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_27_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_27_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_27_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 27 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 27
*
* @note     This will be defined only if EMIOS channel 27 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH27_IRQ)
{
    #if (defined EMIOS_1_CH_27_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_27_ISR_USED)
        Emios_Gpt_IrqHandler(1, 27);
        #endif

        #if (defined ICU_EMIOS_1_CH_27_ISR_USED)
        Emios_Icu_IrqHandler(1, 27);
        #endif

        #if (defined OCU_EMIOS_1_CH_27_ISR_USED)
        Emios_Ocu_IrqHandler(1, 27);
        #endif

        #if (defined PWM_EMIOS_1_CH_27_ISR_USED)
        Emios_Pwm_IrqHandler(1, 27);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_28_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_28_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_28_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_28_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 28 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 28
*
* @note     This will be defined only if EMIOS channel 28 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH28_IRQ)
{
    #if (defined EMIOS_1_CH_28_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_28_ISR_USED)
        Emios_Gpt_IrqHandler(1, 28);
        #endif

        #if (defined ICU_EMIOS_1_CH_28_ISR_USED)
        Emios_Icu_IrqHandler(1, 28);
        #endif

        #if (defined OCU_EMIOS_1_CH_28_ISR_USED)
        Emios_Ocu_IrqHandler(1, 28);
        #endif

        #if (defined PWM_EMIOS_1_CH_28_ISR_USED)
        Emios_Pwm_IrqHandler(1, 28);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_29_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_29_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_29_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_29_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 29 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 29
*
* @note     This will be defined only if EMIOS channel 29 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH29_IRQ)
{
    #if (defined EMIOS_1_CH_29_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_29_ISR_USED)
        Emios_Gpt_IrqHandler(1, 29);
        #endif

        #if (defined ICU_EMIOS_1_CH_29_ISR_USED)
        Emios_Icu_IrqHandler(1, 29);
        #endif

        #if (defined OCU_EMIOS_1_CH_29_ISR_USED)
        Emios_Ocu_IrqHandler(1, 29);
        #endif

        #if (defined PWM_EMIOS_1_CH_29_ISR_USED)
        Emios_Pwm_IrqHandler(1, 29);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_30_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_30_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_30_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_30_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 30 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 30
*
* @note     This will be defined only if EMIOS channel 30 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH30_IRQ)
{
    #if (defined EMIOS_1_CH_30_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_30_ISR_USED)
        Emios_Gpt_IrqHandler(1, 30);
        #endif

        #if (defined ICU_EMIOS_1_CH_30_ISR_USED)
        Emios_Icu_IrqHandler(1, 30);
        #endif

        #if (defined OCU_EMIOS_1_CH_30_ISR_USED)
        Emios_Ocu_IrqHandler(1, 30);
        #endif

        #if (defined PWM_EMIOS_1_CH_30_ISR_USED)
        Emios_Pwm_IrqHandler(1, 30);
        #endif
    #endif
}
#endif

#if (\
        (defined GPT_EMIOS_1_CH_31_ISR_USED) ||\
        (defined ICU_EMIOS_1_CH_31_ISR_USED) ||\
        (defined OCU_EMIOS_1_CH_31_ISR_USED) ||\
        (defined PWM_EMIOS_1_CH_31_ISR_USED)\
    )
/**
* @brief    Interrupt handler for EMIOS channel 31 for Emios instance 1
* @details  Process the interrupt of EMIOS channel 31
*
* @note     This will be defined only if EMIOS channel 31 is configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_CH31_IRQ)
{
    #if (defined EMIOS_1_CH_31_ISR_USED)
        #if (defined GPT_EMIOS_1_CH_31_ISR_USED)
        Emios_Gpt_IrqHandler(1, 31);
        #endif

        #if (defined ICU_EMIOS_1_CH_31_ISR_USED)
        Emios_Icu_IrqHandler(1, 31);
        #endif

        #if (defined OCU_EMIOS_1_CH_31_ISR_USED)
        Emios_Ocu_IrqHandler(1, 31);
        #endif

        #if (defined PWM_EMIOS_1_CH_31_ISR_USED)
        Emios_Pwm_IrqHandler(1, 31);
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
