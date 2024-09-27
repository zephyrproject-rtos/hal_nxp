/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32ZE_RTD_2_0_0_D2407_ASR_REL_4_7_REV_0000_20240726
*
*   Copyright 2021-2024 NXP
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef PSI5_S_IP_CFG_DEFINES_H
#define PSI5_S_IP_CFG_DEFINES_H

/**
*   @file Psi5_S_Ip_Cfg_Defines.h
*
*   @addtogroup PSI5_S_IP PSI5 IPV Driver
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
==================================================================================================*/
#include "S32Z2_PSI5_S.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PSI5_S_IP_CFG_DEFINES_VENDOR_ID                    43
#define PSI5_S_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define PSI5_S_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define PSI5_S_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define PSI5_S_IP_CFG_DEFINES_SW_MAJOR_VERSION             2
#define PSI5_S_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define PSI5_S_IP_CFG_DEFINES_SW_PATCH_VERSION             0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/* Define for HW channelId of channel Psi5SChannel_0 */
#define PSI5_S_0_CH0    (0U)
#define PSI5_S_IP_ENABLE_INTERRUPTS_PSI5_S_0_CH0


#define PSI5_S_IP_ENABLE_GLOBAL_INTERRUPTS_PSI5_S_INSTANCE0


#define PSI5_S_IP_DMA_IS_USED                       (STD_OFF)
#define PSI5_S_IP_DEBUG_MODE                        (STD_OFF)
#define PSI5_S_IP_DEV_ERROR_DETECT                  (STD_OFF)

/* @brief Enables / Disables multipartition support */
#define PSI5_S_IP_MULTIPARTITION_SUPPORT            (STD_ON)
/* @brief Psi5S Osif source counter. This parameter is used to select between different OsIf counter implementation */
#define PSI5_S_IP_TIMEOUT_TYPE                      (OSIF_COUNTER_DUMMY)
/* @brief Number of loops before returning PSI5_S_STATUS_TIMEOUT */
#define PSI5_S_IP_TIMEOUT_VALUE_US                  (0U)

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PSI5_S_IP_CFG_DEFINES_H */
