/*
 * Copyright 2021-2025 NXP
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
#define MCL_EMIOS_GPT_IP_H
#include "Emios_Gpt_Ip.h"
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
#define MCL_EMIOS_ICU_IP_IRQ_H
#include "Emios_Icu_Ip_Irq.h"
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
#define MCL_EMIOS_OCU_IP_IRQ_H
#include "Emios_Ocu_Ip_Irq.h"
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
#define MCL_EMIOS_PWM_IP_IRQ_H
#include "Emios_Pwm_Ip_Irq.h"
#endif
/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_MCL_IP_IRQ_VENDOR_ID                       43
#define EMIOS_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_MCL_IP_IRQ_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_MCL_IP_IRQ_SW_MAJOR_VERSION                2
#define EMIOS_MCL_IP_IRQ_SW_MINOR_VERSION                0
#define EMIOS_MCL_IP_IRQ_SW_PATCH_VERSION                1
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

#ifdef MCL_EMIOS_GPT_IP_H

#if (EMIOS_MCL_IP_IRQ_VENDOR_ID != EMIOS_GPT_IP_VENDOR_ID)
    #error "Emios_Mcl_Ip_Irq.h and Emios_Gpt_Ip.h have different vendor ids"
#endif

/* Check if  header file and Emios_Gpt_Ip.h file are of the same Autosar version */
#if ((EMIOS_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION != EMIOS_GPT_IP_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION != EMIOS_GPT_IP_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_AR_RELEASE_REVISION_VERSION != EMIOS_GPT_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Mcl_Ip_Irq.h and Emios_Gpt_Ip.h are different"
#endif

/* Check if header file and Emios_Gpt_Ip.h file are of the same Software version */
#if ((EMIOS_MCL_IP_IRQ_SW_MAJOR_VERSION != EMIOS_GPT_IP_SW_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_SW_MINOR_VERSION != EMIOS_GPT_IP_SW_MINOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_SW_PATCH_VERSION != EMIOS_GPT_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Mcl_Ip_Irq.h and Emios_Gpt_Ip.h are different"
#endif

#endif /* MCL_EMIOS_GPT_IP_H */

#ifdef MCL_EMIOS_ICU_IP_IRQ_H

#if (EMIOS_MCL_IP_IRQ_VENDOR_ID != EMIOS_ICU_IP_IRQ_VENDOR_ID)
    #error "Emios_Mcl_Ip_Irq.h and Emios_Icu_Ip_Irq.h have different vendor ids"
#endif

/* Check if  header file and Emios_Icu_Ip_Irq.h file are of the same Autosar version */
#if ((EMIOS_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION != EMIOS_ICU_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION != EMIOS_ICU_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_AR_RELEASE_REVISION_VERSION != EMIOS_ICU_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Mcl_Ip_Irq.h and Emios_Icu_Ip_Irq.h are different"
#endif

/* Check if header file and Emios_Icu_Ip_Irq.h file are of the same Software version */
#if ((EMIOS_MCL_IP_IRQ_SW_MAJOR_VERSION != EMIOS_ICU_IP_IRQ_SW_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_SW_MINOR_VERSION != EMIOS_ICU_IP_IRQ_SW_MINOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_SW_PATCH_VERSION != EMIOS_ICU_IP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Mcl_Ip_Irq.h and Emios_Icu_Ip_Irq.h are different"
#endif

#endif /* MCL_EMIOS_ICU_IP_IRQ_H */

#ifdef MCL_EMIOS_OCU_IP_IRQ_H

#if (EMIOS_MCL_IP_IRQ_VENDOR_ID != EMIOS_OCU_IP_IRQ_VENDOR_ID)
    #error "Emios_Mcl_Ip_Irq.h and Emios_Ocu_Ip_Irq.h have different vendor ids"
#endif

/* Check if  header file and Emios_Ocu_Ip_Irq.h file are of the same Autosar version */
#if ((EMIOS_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION != EMIOS_OCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION != EMIOS_OCU_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_AR_RELEASE_REVISION_VERSION != EMIOS_OCU_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Mcl_Ip_Irq.h and Emios_Ocu_Ip_Irq.h are different"
#endif

/* Check if header file and Emios_Ocu_Ip_Irq.h file are of the same Software version */
#if ((EMIOS_MCL_IP_IRQ_SW_MAJOR_VERSION != EMIOS_OCU_IP_IRQ_SW_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_SW_MINOR_VERSION != EMIOS_OCU_IP_IRQ_SW_MINOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_SW_PATCH_VERSION != EMIOS_OCU_IP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Mcl_Ip_Irq.h and Emios_Ocu_Ip_Irq.h are different"
#endif

#endif /* MCL_EMIOS_OCU_IP_IRQ_H */

#ifdef MCL_EMIOS_PWM_IP_IRQ_H

#if (EMIOS_MCL_IP_IRQ_VENDOR_ID != EMIOS_PWM_IP_IRQ_VENDOR_ID)
    #error "Emios_Mcl_Ip_Irq.h and Emios_Pwm_Ip_Irq.h have different vendor ids"
#endif

/* Check if  header file and Emios_Pwm_Ip_Irq.h file are of the same Autosar version */
#if ((EMIOS_MCL_IP_IRQ_AR_RELEASE_MAJOR_VERSION != EMIOS_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_AR_RELEASE_MINOR_VERSION != EMIOS_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_AR_RELEASE_REVISION_VERSION != EMIOS_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Mcl_Ip_Irq.h and Emios_Pwm_Ip_Irq.h are different"
#endif

/* Check if header file and Emios_Pwm_Ip_Irq.h file are of the same Software version */
#if ((EMIOS_MCL_IP_IRQ_SW_MAJOR_VERSION != EMIOS_PWM_IP_IRQ_SW_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_SW_MINOR_VERSION != EMIOS_PWM_IP_IRQ_SW_MINOR_VERSION) || \
     (EMIOS_MCL_IP_IRQ_SW_PATCH_VERSION != EMIOS_PWM_IP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Mcl_Ip_Irq.h and Emios_Pwm_Ip_Irq.h are different"
#endif

#endif /* MCL_EMIOS_PWM_IP_IRQ_H */

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

#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"


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
ISR(EMIOS0_CH0_IRQ);
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
ISR(EMIOS0_CH1_IRQ);
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
ISR(EMIOS0_CH2_IRQ);
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
ISR(EMIOS0_CH3_IRQ);
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
ISR(EMIOS0_CH4_IRQ);
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
ISR(EMIOS0_CH5_IRQ);
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
ISR(EMIOS0_CH6_IRQ);
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
ISR(EMIOS0_CH7_IRQ);
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
ISR(EMIOS0_CH8_IRQ);
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
ISR(EMIOS0_CH9_IRQ);
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
ISR(EMIOS0_CH10_IRQ);
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
ISR(EMIOS0_CH11_IRQ);
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
ISR(EMIOS0_CH12_IRQ);
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
ISR(EMIOS0_CH13_IRQ);
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
ISR(EMIOS0_CH14_IRQ);
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
ISR(EMIOS0_CH15_IRQ);
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
ISR(EMIOS0_CH16_IRQ);
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
ISR(EMIOS0_CH17_IRQ);
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
ISR(EMIOS0_CH18_IRQ);
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
ISR(EMIOS0_CH19_IRQ);
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
ISR(EMIOS0_CH20_IRQ);
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
ISR(EMIOS0_CH21_IRQ);
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
ISR(EMIOS0_CH22_IRQ);
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
ISR(EMIOS0_CH23_IRQ);
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
ISR(EMIOS0_CH24_IRQ);
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
ISR(EMIOS0_CH25_IRQ);
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
ISR(EMIOS0_CH26_IRQ);
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
ISR(EMIOS0_CH27_IRQ);
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
ISR(EMIOS0_CH28_IRQ);
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
ISR(EMIOS0_CH29_IRQ);
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
ISR(EMIOS0_CH30_IRQ);
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
ISR(EMIOS0_CH31_IRQ);
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
ISR(EMIOS1_CH0_IRQ);
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
ISR(EMIOS1_CH1_IRQ);
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
ISR(EMIOS1_CH2_IRQ);
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
ISR(EMIOS1_CH3_IRQ);
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
ISR(EMIOS1_CH4_IRQ);
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
ISR(EMIOS1_CH5_IRQ);
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
ISR(EMIOS1_CH6_IRQ);
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
ISR(EMIOS1_CH7_IRQ);
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
ISR(EMIOS1_CH8_IRQ);
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
ISR(EMIOS1_CH9_IRQ);
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
ISR(EMIOS1_CH10_IRQ);
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
ISR(EMIOS1_CH11_IRQ);
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
ISR(EMIOS1_CH12_IRQ);
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
ISR(EMIOS1_CH13_IRQ);
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
ISR(EMIOS1_CH14_IRQ);
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
ISR(EMIOS1_CH15_IRQ);
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
ISR(EMIOS1_CH16_IRQ);
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
ISR(EMIOS1_CH17_IRQ);
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
ISR(EMIOS1_CH18_IRQ);
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
ISR(EMIOS1_CH19_IRQ);
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
ISR(EMIOS1_CH20_IRQ);
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
ISR(EMIOS1_CH21_IRQ);
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
ISR(EMIOS1_CH22_IRQ);
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
ISR(EMIOS1_CH23_IRQ);
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
ISR(EMIOS1_CH24_IRQ);
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
ISR(EMIOS1_CH25_IRQ);
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
ISR(EMIOS1_CH26_IRQ);
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
ISR(EMIOS1_CH27_IRQ);
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
ISR(EMIOS1_CH28_IRQ);
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
ISR(EMIOS1_CH29_IRQ);
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
ISR(EMIOS1_CH30_IRQ);
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
ISR(EMIOS1_CH31_IRQ);
#endif

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EMIOS_MCL_IP_IRQ_H */
