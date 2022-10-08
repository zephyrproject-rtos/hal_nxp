/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SIUL2_ICU_IP_DEFINES_H
#define SIUL2_ICU_IP_DEFINES_H

/**
 *   @file    Siul2_Icu_Ip_Defines.h
 *   @version 0.8.0
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the Icu module
 *   @details Contains the information that will be exported by the module, as requested by Autosar.
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
#include "StandardTypes.h"
#include "S32Z27_SIUL2.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_ICU_IP_DEFINES_VENDOR_ID                    43
#define SIUL2_ICU_IP_DEFINES_MODULE_ID                    122
#define SIUL2_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define SIUL2_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION     4
#define SIUL2_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define SIUL2_ICU_IP_DEFINES_SW_MAJOR_VERSION             0
#define SIUL2_ICU_IP_DEFINES_SW_MINOR_VERSION             8
#define SIUL2_ICU_IP_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and StandardTypes.h file are of the same Autosar version */
    #if ((SIUL2_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SIUL2_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Siul2_Icu_Ip_Defines.h and StandardTypes.h are different"
    #endif
#endif
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/* Redefines the address table of the Siul2 instance. */
#define SIUL2_ICU_IP_BASE_PTRS      { IP_SIUL2_0, IP_SIUL2_1, NULL_PTR, IP_SIUL2_3, IP_SIUL2_4, IP_SIUL2_5 }                                                                                                                                                                                                                                                                            
   
#define SIUL2_ICU_IP_DEV_ERROR_DETECT (STD_OFF)

/** @brief The number of Siul2 instances available on platform */
#define SIUL2_ICU_IP_NUM_OF_INSTANCES (6U)

/** @brief The number of channels available on each instance */
#define SIUL2_ICU_IP_NUM_OF_CHANNELS  (8)
/** @brief Adds or removes all services related to the deinitialization functionality. */
#define SIUL2_ICU_IP_DEINIT_API                 (STD_ON)

/** @brief Adds or removes all services related to mode set functionality. */
#define SIUL2_ICU_IP_SET_MODE_API               (STD_ON)

/** @brief Adds or removes all services related to dual clock edge functionality. */
#define SIUL2_ICU_IP_DUAL_CLOCK_MODE_API        (STD_ON)

/** @brief Add or remove all functions related to input state. */
#define SIUL2_ICU_IP_GET_INPUT_STATE_API        (STD_ON)
/** @brief Instance of SIUL2 used by current platform. */
#define SIUL2_ICU_IP_INSTANCE                (0U)

/** @brief Support for User mode. If this parameter has been configured to STD_ON, the FTM driver 
 *         code can be executed from both supervisor and user mode. */
#define SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT   (STD_OFF)

/* Verification for user mode support. */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #if (defined (SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT))
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Icu in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
 #endif
#endif


#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* SIUL2_ICU_IP_DEFINES_H */

