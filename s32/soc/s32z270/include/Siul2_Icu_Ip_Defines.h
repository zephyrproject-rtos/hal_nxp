/*
 * Copyright 2022-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SIUL2_ICU_IP_DEFINES_H
#define SIUL2_ICU_IP_DEFINES_H

/**
 *   @file       Siul2_Icu_Ip_Defines.h
 *   @version    1.0.0
 *
 *   @brief      AUTOSAR Icu - contains the data exported by the Icu module
 *   @details    Contains the information that will be exported by the module, as requested by Autosar.
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

#include "S32Z2_SIUL2.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_ICU_IP_DEFINES_VENDOR_ID                      43
#define SIUL2_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION       4
#define SIUL2_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION       7
#define SIUL2_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION    0
#define SIUL2_ICU_IP_DEFINES_SW_MAJOR_VERSION               1
#define SIUL2_ICU_IP_DEFINES_SW_MINOR_VERSION               0
#define SIUL2_ICU_IP_DEFINES_SW_PATCH_VERSION               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((SIUL2_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SIUL2_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Siul2_Icu_Ip_Defines.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define SIUL2_ICU_IP_USED                      (STD_ON)

#if (STD_ON == SIUL2_ICU_IP_USED)

/* Redefines the address table of the Siul2 instance. */
#define SIUL2_ICU_IP_BASE_PTRS                 { IP_SIUL2_0, IP_SIUL2_1, NULL_PTR, IP_SIUL2_3, IP_SIUL2_4, IP_SIUL2_5 }

#define SIUL2_ICU_IP_DEV_ERROR_DETECT          (STD_OFF)

/** @brief The number of Siul2 instances available on platform */
#define SIUL2_ICU_IP_NUM_OF_INSTANCES          (6U)

/** @brief The number of channels available on each instance */
#define SIUL2_ICU_IP_NUM_OF_CHANNELS           (8)

/** @brief The number of Siul2 channels are used in configuration */
#define SIUL2_ICU_IP_NUM_OF_CHANNELS_USED      ((uint8)32U)

/** @brief Adds or removes all services related to the de-initialization functionality. */
#define SIUL2_ICU_IP_DEINIT_API                 (STD_ON)

/** @brief Adds or removes all services related to mode set functionality. */
#define SIUL2_ICU_IP_SET_MODE_API               (STD_ON)

/** @brief Adds or removes all services related to dual clock edge functionality. */
#define SIUL2_ICU_IP_DUAL_CLOCK_MODE_API        (STD_ON)

/** @brief Add or remove all functions related to input state. */
#define SIUL2_ICU_IP_GET_INPUT_STATE_API        (STD_ON)
/** @brief Support for User mode. If this parameter has been configured to STD_ON, the FTM driver 
 *         code can be executed from both supervisor and user mode. */
#define SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT   (STD_OFF)

/* Verification for user mode support. */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (defined (SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT))
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Icu in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif
#endif

#define SIUL2_ICU_IP_INITIAL_INDEX_OF_CHANNELS \
  { \
      {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U}, \
      {8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U}, \
      {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, \
      {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, \
      {16U, 17U, 18U, 19U, 20U, 21U, 22U, 23U}, \
      {24U, 25U, 26U, 27U, 28U, 29U, 30U, 31U} \
  } \

#endif /* SIUL2_ICU_IP_USED */
#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* SIUL2_ICU_IP_DEFINES_H */
