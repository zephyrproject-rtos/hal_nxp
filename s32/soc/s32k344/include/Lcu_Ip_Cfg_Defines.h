/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* Prevention from multiple including the same header */
#ifndef LCU_IP_CFG_DEFINES_H_
#define LCU_IP_CFG_DEFINES_H_

#include "StandardTypes.h"
#include "PlatformTypes.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LCU_IP_CFG_DEFINES_VENDOR_ID                       43
#define LCU_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define LCU_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define LCU_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define LCU_IP_CFG_DEFINES_SW_MAJOR_VERSION                3
#define LCU_IP_CFG_DEFINES_SW_MINOR_VERSION                0
#define LCU_IP_CFG_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and StandardTypes header file are of the same Autosar version */
#if ((LCU_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Lcu_Ip_Cfg_Defines.h and StandardTypes.h are different"
#endif

/* Check if header file and PlatformTypes header file are of the same Autosar version */
#if ((LCU_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Lcu_Ip_Cfg_Defines.h and PlatformTypes.h are different"
#endif
#endif

/*===============================================================================================
                                       DEFINES AND MACROS
===============================================================================================*/

/* LCU Available */
#define LCU_IP_IS_AVAILABLE                      STD_ON

/* SYNC Functions Available */
#define LCU_IP_SYNC_FUNC_IS_AVAILABLE            STD_ON

/* SYNC Functions Available */
#define LCU_IP_ASYNC_FUNC_IS_AVAILABLE           STD_OFF

/* Support DEV ERROR DETECT */
#define LCU_IP_DEV_ERROR_DETECT                  STD_OFF

/* LCU multi cores */
#define LCU_IP_MULTICORE_IS_AVAILABLE            STD_OFF


/*-------------------------------------------------------------------/
/                       LCU HARDWARE INSTANCES                       /
/-------------------------------------------------------------------*/
#define LCU_IP_HW_INST_0                         ((uint8)(0U))
#define LCU_IP_HW_INST_1                         ((uint8)(1U))

/*-------------------------------------------------------------------/
/                       LCU OPERATION MODE                          /
/-------------------------------------------------------------------*/
#define LCU_IP_INTERRUPT_MODE                    ((uint8)(0U))
#define LCU_IP_POLLING_MODE                      ((uint8)(1U))

/*-------------------------------------------------------------------/
/                       LCU HARDWARE LOGIC CELLS                     /
/-------------------------------------------------------------------*/
#define LCU_IP_HW_LC_0                           ((uint8)(0U))
#define LCU_IP_HW_LC_1                           ((uint8)(1U))
#define LCU_IP_HW_LC_2                           ((uint8)(2U))

/*-------------------------------------------------------------------/
/                       LCU SOFTWARE OVERRIDE VALUE                  /
/-------------------------------------------------------------------*/
#define LCU_IP_SW_OVERRIDE_LOGIC_LOW             ((uint8)(0U))
#define LCU_IP_SW_OVERRIDE_LOGIC_HIGH            ((uint8)(1U))

/*-------------------------------------------------------------------/
/                       LCU SOFTWARE SYNC MODE                       /
/-------------------------------------------------------------------*/
#define LCU_IP_SW_SYNC_IMMEDIATE                 ((boolean)(FALSE))
#define LCU_IP_SW_SYNC_ON_RISING_EDGE            ((boolean)(TRUE))

/*-------------------------------------------------------------------/
/                       LCU INTERRUPT/DMA                            /
/-------------------------------------------------------------------*/
#define LCU_IP_DMA_DISABLE                       ((uint8)(0U))
#define LCU_IP_DMA_ENABLE                        ((uint8)(1U))
#define LCU_IP_INT_DISABLE                       ((uint8)(0U))
#define LCU_IP_INT_ENABLE                        ((uint8)(1U))

/*-------------------------------------------------------------------/
/                       LCU OUTPUT POLARITY                          /
/-------------------------------------------------------------------*/
#define LCU_IP_OUTPOL_NOT_INVERTED               ((uint8)(0U))
#define LCU_IP_OUTPOL_INVERTED                   ((uint8)(1U))

/*-------------------------------------------------------------------/
/                       LCU FORCE OUTPUT POLARITY                    /
/-------------------------------------------------------------------*/
#define LCU_IP_FORCE_POL_NOT_INVERTED            ((uint8)(0U))
#define LCU_IP_FORCE_POL_INVERTED                ((uint8)(1U))

/*-------------------------------------------------------------------/
/                       LCU FORCE SENSITIVITY                        /
/-------------------------------------------------------------------*/
#define LCU_IP_FORCE_SENSE_NOT_AFFECT            ((uint8)(0U))
#define LCU_IP_FORCE_SENSE_AFFECT                ((uint8)(1U))

/*-------------------------------------------------------------------/
/                       LCU SW SYNC_SEL                              /
/-------------------------------------------------------------------*/
#define LCU_IP_SW_SYNC_SEL_INPUT0                ((uint8)(0U))
#define LCU_IP_SW_SYNC_SEL_INPUT1                ((uint8)(1U))
#define LCU_IP_SW_SYNC_SEL_INPUT2                ((uint8)(2U))
#define LCU_IP_SW_SYNC_SEL_INPUT3                ((uint8)(3U))

/*-------------------------------------------------------------------/
/                  LCU SOFTWARE OVERRIDE ENABLE/DISABLE              /
/-------------------------------------------------------------------*/
#define LCU_IP_SW_OVERRIDE_DISABLE               ((uint8)(0U))
#define LCU_IP_SW_OVERRIDE_ENABLE                ((uint8)(1U))

/*-------------------------------------------------------------------/
/                       LCU OUTPUT ENABLE/DISABLE                    /
/-------------------------------------------------------------------*/
#define LCU_IP_OUTPUT_DISABLE                    ((uint8)(0U))
#define LCU_IP_OUTPUT_ENABLE                     ((uint8)(1U))

/*-------------------------------------------------------------------/
/                       LCU DEBUG MODE ENABLE/DISABLE                /
/-------------------------------------------------------------------*/
#define LCU_IP_DEBUG_DISABLE                     ((boolean)(FALSE))
#define LCU_IP_DEBUG_ENABLE                      ((boolean)(TRUE))

/*-------------------------------------------------------------------/
/                       LCU SOURCE MUX SELECT                        /
/-------------------------------------------------------------------*/
#define LCU_IP_MUX_SEL_LOGIC_0                   ((uint8)(0U))
#define LCU_IP_MUX_SEL_LU_IN_0                   ((uint8)(1U))
#define LCU_IP_MUX_SEL_LU_IN_1                   ((uint8)(2U))
#define LCU_IP_MUX_SEL_LU_IN_2                   ((uint8)(3U))
#define LCU_IP_MUX_SEL_LU_IN_3                   ((uint8)(4U))
#define LCU_IP_MUX_SEL_LU_IN_4                   ((uint8)(5U))
#define LCU_IP_MUX_SEL_LU_IN_5                   ((uint8)(6U))
#define LCU_IP_MUX_SEL_LU_IN_6                   ((uint8)(7U))
#define LCU_IP_MUX_SEL_LU_IN_7                   ((uint8)(8U))
#define LCU_IP_MUX_SEL_LU_IN_8                   ((uint8)(9U))
#define LCU_IP_MUX_SEL_LU_IN_9                   ((uint8)(10U))
#define LCU_IP_MUX_SEL_LU_IN_10                  ((uint8)(11U))
#define LCU_IP_MUX_SEL_LU_IN_11                  ((uint8)(12U))
#define LCU_IP_MUX_SEL_LU_OUT_0                  ((uint8)(13U))
#define LCU_IP_MUX_SEL_LU_OUT_1                  ((uint8)(14U))
#define LCU_IP_MUX_SEL_LU_OUT_2                  ((uint8)(15U))
#define LCU_IP_MUX_SEL_LU_OUT_3                  ((uint8)(16U))
#define LCU_IP_MUX_SEL_LU_OUT_4                  ((uint8)(17U))
#define LCU_IP_MUX_SEL_LU_OUT_5                  ((uint8)(18U))
#define LCU_IP_MUX_SEL_LU_OUT_6                  ((uint8)(19U))
#define LCU_IP_MUX_SEL_LU_OUT_7                  ((uint8)(20U))
#define LCU_IP_MUX_SEL_LU_OUT_8                  ((uint8)(21U))
#define LCU_IP_MUX_SEL_LU_OUT_9                  ((uint8)(22U))
#define LCU_IP_MUX_SEL_LU_OUT_10                 ((uint8)(23U))
#define LCU_IP_MUX_SEL_LU_OUT_11                 ((uint8)(24U))

/*-------------------------------------------------------------------/
/                       LCU SYNC_SEL                                 /
/-------------------------------------------------------------------*/
#define LCU_IP_SYNC_SEL_INPUT0                   ((uint8)(0U))
#define LCU_IP_SYNC_SEL_INPUT1                   ((uint8)(1U))
#define LCU_IP_SYNC_SEL_INPUT2                   ((uint8)(2U))
#define LCU_IP_SYNC_SEL_INPUT3                   ((uint8)(3U))

/*-------------------------------------------------------------------/
/                       LCU FORCE_SEL                                /
/-------------------------------------------------------------------*/
#define LCU_IP_FORCE_SEL_INPUT0                  ((uint8)(0U))
#define LCU_IP_FORCE_SEL_INPUT1                  ((uint8)(1U))
#define LCU_IP_FORCE_SEL_INPUT2                  ((uint8)(2U))
#define LCU_IP_FORCE_SEL_INPUT3                  ((uint8)(3U))

/*-------------------------------------------------------------------/
/                       LCU CLEAR FORCE SIGNAL MODE                  /
/-------------------------------------------------------------------*/
#define LCU_IP_CLEAR_FORCE_SIGNAL_IMMEDIATE                             ((uint8)(0U))
#define LCU_IP_CLEAR_FORCE_SIGNAL_ON_RISING_EDGE                        ((uint8)(1U))
#define LCU_IP_CLEAR_FORCE_SIGNAL_AFTER_CLEAR_STATUS                    ((uint8)(2U))
#define LCU_IP_CLEAR_FORCE_SIGNAL_ON_RISING_EDGE_AFTER_CLEAR_STATUS     ((uint8)(3U))

#endif  /* #ifndef LCU_IP_CFG_DEFINES_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
