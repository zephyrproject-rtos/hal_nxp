/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef WKPU_IP_DEFINES_H
#define WKPU_IP_DEFINES_H

/**
 *   @file    Wkpu_Ip_Defines.h
 *   @version 3.0.0
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the Icu module
 *   @details Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup wkpu_icu_ip WKPU IPL
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
#include "S32K344_WKPU.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WKPU_IP_DEFINES_VENDOR_ID                    43
#define WKPU_IP_DEFINES_MODULE_ID                    122
#define WKPU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define WKPU_IP_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define WKPU_IP_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define WKPU_IP_DEFINES_SW_MAJOR_VERSION             3
#define WKPU_IP_DEFINES_SW_MINOR_VERSION             0
#define WKPU_IP_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WKPU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (WKPU_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Wkpu_Ip_Defines.h and Std_Types.h are different"
    #endif
#endif
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#define WKPU_IP_USED    (STD_ON)

#if (STD_ON == WKPU_IP_USED)
#define WKPU_IP_NMI_API    (STD_ON)

#if (defined (WKPU_IP_NMI_API) && (STD_ON == WKPU_IP_NMI_API))
/*! @brief The distance between cores */
#define WKPU_IP_CORE_OFFSET_SIZE  (8U)
#define WKPU_IP_SUPPORT_NONE_REQUEST
#define WKPU_IP_SUPPORT_NON_MASK_INT
/** @brief The WKPU core array */
#define WKPU_IP_CORE_ARRAY { \
WKPU_CORE0      /*!< Core 0*/, \
WKPU_CORE1      /*!< Core 1*/ \
}
#define WKPU_IP_NMI_CORE_CNT      (1U)
#define WKPU_IP_NMI_NUM_CORES     (2U)
#endif

#define WKPU_IP_SUPPORT_INTERRUPT_REQUEST
#define WKPU_IP_NUM_OF_CHANNELS       (64)
/** @brief The number of Wkpu channels are used in configuration */
#define WKPU_IP_NUM_OF_CHANNELS_USED  ((uint8)64U)
#define WKPU_IP_NUM_OF_CHANNELS_IN_ONE_REG  (32U)
/** @brief Switch for enabling Standby wakeup support  on or off */
#define WKPU_IP_STANDBY_WAKEUP_SUPPORT (STD_OFF)

#define WKPU_IP_INITIAL_INDEX_OF_CHANNELS \
    {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U, 16U, 17U, 18U, 19U, 20U, 21U, 22U, 23U, 24U, 25U, 26U, 27U, 28U, 29U, 30U, 31U, 32U, 33U, 34U, 35U, 36U, 37U, 38U, 39U, 40U, 41U, 42U, 43U, 44U, 45U, 46U, 47U, 48U, 49U, 50U, 51U, 52U, 53U, 54U, 55U, 56U, 57U, 58U, 59U, 60U, 61U, 62U, 63U}

#endif /* WKPU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* WKPU_IP_DEFINES_H */
