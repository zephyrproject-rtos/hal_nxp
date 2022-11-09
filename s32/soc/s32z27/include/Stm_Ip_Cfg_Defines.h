/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef STM_IP_CFG_DEFINES_H
#define STM_IP_CFG_DEFINES_H

/**
*   @file           Stm_Ip_Cfg_Defines.h
*
*   @addtogroup     stm_ip Stm IPL
*
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "S32Z2_STM.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define STM_IP_DEFINES_VENDOR_ID_CFG                    43
#define STM_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG     4
#define STM_IP_DEFINES_AR_RELEASE_MINOR_VERSION_CFG     7
#define STM_IP_DEFINES_AR_RELEASE_REVISION_VERSION_CFG  0
#define STM_IP_DEFINES_SW_MAJOR_VERSION_CFG             0
#define STM_IP_DEFINES_SW_MINOR_VERSION_CFG             9
#define STM_IP_DEFINES_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and StandardTypes.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((STM_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG != STD_AR_RELEASE_MAJOR_VERSION) || \
         (STM_IP_DEFINES_AR_RELEASE_MINOR_VERSION_CFG != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Stm_Ip_Cfg_Defines.h and StandardTypes.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief These defines indicate that at least one channel from each module is used in all configurations.
*/
#define STM_IP_USED (STD_ON)
/**
* @brief This define is used to select between interrupt on each channel and source interrupt
*        on entire module sources hardware implementations.
*
*/
#define STM_IP_MODULE_SINGLE_INTERRUPT (STD_ON)
/**
* @brief    STM_IP_SET_CLOCK_MODE switch
* @details  Enable/disable API for Dual Mode support.
*/
#define STM_IP_SET_CLOCK_MODE     (STD_OFF)
/**
* @{
* @brief IRQ Defines for each channel used
*/
#define RTU0_STM_0_ISR_USED
/**
* @{
* @brief IRQ Defines for each channel used
*/
#define RTU0_STM_1_ISR_USED
/**
* @{
* @brief IRQ Defines for each channel used
*/
#define RTU0_STM_2_ISR_USED
/**
* @{
* @brief IRQ Defines for each channel used
*/
#define RTU0_STM_3_ISR_USED
/**
* @{
* @brief IRQ Defines for each channel used
*/
#define RTU1_STM_0_ISR_USED
/**
* @{
* @brief IRQ Defines for each channel used
*/
#define RTU1_STM_1_ISR_USED
/**
* @{
* @brief IRQ Defines for each channel used
*/
#define RTU1_STM_2_ISR_USED
/**
* @{
* @brief IRQ Defines for each channel used
*/
#define RTU1_STM_3_ISR_USED

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
#endif  /* STM_IP_CFG_DEFINES_H */
