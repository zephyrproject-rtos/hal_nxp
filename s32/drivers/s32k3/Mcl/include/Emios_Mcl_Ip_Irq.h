/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_MCL_IP_IRQ_H
#define EMIOS_MCL_IP_IRQ_H

/**
 *    @file       Emios_Mcl_Ip_Irq.h
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
#include "OsIf.h"
#include "Emios_Mcl_Ip_Cfg_Defines.h"

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_MCL_IP_IRQ_VENDOR_ID                       43
#define EMIOS_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_MCL_IP_IRQ_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_MCL_IP_IRQ_SW_MAJOR_VERSION                3
#define EMIOS_MCL_IP_IRQ_SW_MINOR_VERSION                0
#define EMIOS_MCL_IP_IRQ_SW_PATCH_VERSION                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (EMIOS_MCL_IP_IRQ_VENDOR_ID != EMIOS_MCL_IP_CFG_DEFINES_VENDOR_ID)
    #error "Emios_Mcl_Ip_Irq.h and Emios_Mcl_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if  header file and Emios_Mcl_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((EMIOS_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION != EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION != EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_AR_RELEASE_REVISION_VERSION != EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Mcl_Ip_Irq.h and Emios_Mcl_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Emios_Mcl_Ip_Cfg_Defines.h file are of the same Software version */
#if ((EMIOS_MCL_IP_IRQ_SW_MAJOR_VERSION != EMIOS_MCL_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_SW_MINOR_VERSION != EMIOS_MCL_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_SW_PATCH_VERSION != EMIOS_MCL_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Mcl_Ip_Irq.h and Emios_Mcl_Ip_Cfg_Defines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK

    /* Check if this header file and OsIf.h file are of the same Autosar version */
    #if ((EMIOS_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Emios_Mcl_Ip_Irq.h and OsIf.h are different"
    #endif

#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
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
        (defined GPT_EMIOS_2_CH_31_ISR_USED)\
    )

        extern void Emios_Gpt_Ip_IrqHandler(uint8 instance, uint8 channel);
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
        (defined ICU_EMIOS_2_CH_31_ISR_USED)\
    )

        extern void Emios_Icu_Ip_IrqHandler(uint8 instance, uint8 channel);
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
        (defined OCU_EMIOS_2_CH_31_ISR_USED)\
    )

        extern void Emios_Ocu_Ip_IrqHandler(uint8 instance, uint8 channel);
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
        (defined PWM_EMIOS_2_CH_31_ISR_USED)\
    )

        extern void Emios_Pwm_Ip_IrqHandler(uint8 instance, uint8 channel);
    #endif


#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

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
* @brief    Interrupt handler for EMIOS channels 0-3 for Emios instance 0
* @details  Process the interrupt of EMIOS channels 0-3
*
* @note     This will be defined only if EMIOS channels 0, 1, 2, 3 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_5_IRQ);
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
* @brief    Interrupt handler for EMIOS channels 4-7 for Emios instance 0
* @details  Process the interrupt of EMIOS channels 4-7
*
* @note     This will be defined only if EMIOS channels 4, 5, 6, 7 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_4_IRQ);
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
* @brief    Interrupt handler for EMIOS channels 8-11 for Emios instance 0
* @details  Process the interrupt of EMIOS channels 8-11
*
* @note     This will be defined only if EMIOS channels 8, 9, 10, 11 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_3_IRQ);
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
* @brief    Interrupt handler for EMIOS channels 12-15 for Emios instance 0
* @details  Process the interrupt of EMIOS channels 12-15
*
* @note     This will be defined only if EMIOS channels 12, 13, 14, 15 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_2_IRQ);
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
* @brief    Interrupt handler for EMIOS channels 16-19 for Emios instance 0
* @details  Process the interrupt of EMIOS channels 16-19
*
* @note     This will be defined only if EMIOS channels 16, 17, 18, 19 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_1_IRQ);
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
* @brief    Interrupt handler for EMIOS channels 20-23 for Emios instance 0
* @details  Process the interrupt of EMIOS channels 20-23
*
* @note     This will be defined only if EMIOS channels 20, 21, 22, 23 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS0_0_IRQ);
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
* @brief    Interrupt handler for EMIOS channels 0-3 for Emios instance 1
* @details  Process the interrupt of EMIOS channels 0-3
*
* @note     This will be defined only if EMIOS channels 0, 1, 2, 3 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_5_IRQ);
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
* @brief    Interrupt handler for EMIOS channels 4-7 for Emios instance 1
* @details  Process the interrupt of EMIOS channels 4-7
*
* @note     This will be defined only if EMIOS channels 4, 5, 6, 7 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_4_IRQ);
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
* @brief    Interrupt handler for EMIOS channels 8-11 for Emios instance 1
* @details  Process the interrupt of EMIOS channels 8-11
*
* @note     This will be defined only if EMIOS channels 8, 9, 10, 11 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_3_IRQ);
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
* @brief    Interrupt handler for EMIOS channels 12-15 for Emios instance 1
* @details  Process the interrupt of EMIOS channels 12-15
*
* @note     This will be defined only if EMIOS channels 12, 13, 14, 15 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_2_IRQ);
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
* @brief    Interrupt handler for EMIOS channels 16-19 for Emios instance 1
* @details  Process the interrupt of EMIOS channels 16-19
*
* @note     This will be defined only if EMIOS channels 16, 17, 18, 19 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_1_IRQ);
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
* @brief    Interrupt handler for EMIOS channels 20-23 for Emios instance 1
* @details  Process the interrupt of EMIOS channels 20-23
*
* @note     This will be defined only if EMIOS channels 20, 21, 22, 23 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS1_0_IRQ);
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
* @brief    Interrupt handler for EMIOS channels 0-3 for Emios instance 2
* @details  Process the interrupt of EMIOS channels 0-3
*
* @note     This will be defined only if EMIOS channels 0, 1, 2, 3 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS2_5_IRQ);
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
* @brief    Interrupt handler for EMIOS channels 4-7 for Emios instance 2
* @details  Process the interrupt of EMIOS channels 4-7
*
* @note     This will be defined only if EMIOS channels 4, 5, 6, 7 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS2_4_IRQ);
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
* @brief    Interrupt handler for EMIOS channels 8-11 for Emios instance 2
* @details  Process the interrupt of EMIOS channels 8-11
*
* @note     This will be defined only if EMIOS channels 8, 9, 10, 11 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS2_3_IRQ);
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
* @brief    Interrupt handler for EMIOS channels 12-15 for Emios instance 2
* @details  Process the interrupt of EMIOS channels 12-15
*
* @note     This will be defined only if EMIOS channels 12, 13, 14, 15 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS2_2_IRQ);
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
* @brief    Interrupt handler for EMIOS channels 16-19 for Emios instance 2
* @details  Process the interrupt of EMIOS channels 16-19
*
* @note     This will be defined only if EMIOS channels 16, 17, 18, 19 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS2_1_IRQ);
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
* @brief    Interrupt handler for EMIOS channels 20-23 for Emios instance 2
* @details  Process the interrupt of EMIOS channels 20-23
*
* @note     This will be defined only if EMIOS channels 20, 21, 22, 23 are configured in GPT, ICU,
*           OCU or PWM mode.
*/
ISR(EMIOS2_0_IRQ);
#endif


#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EMIOS_MCL_IP_IRQ_H */
