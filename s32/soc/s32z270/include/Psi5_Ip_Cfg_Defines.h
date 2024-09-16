/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PSI5_IP_CFG_DEFINES_H
#define PSI5_IP_CFG_DEFINES_H

/**
*   @file Psi5_Ip_Cfg_Defines.h
*
*   @addtogroup PSI5_IP PSI5 IPV Driver
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
#include "S32Z2_PSI5.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PSI5_IP_CFG_DEFINES_VENDOR_ID                    43
#define PSI5_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define PSI5_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define PSI5_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define PSI5_IP_CFG_DEFINES_SW_MAJOR_VERSION             2
#define PSI5_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define PSI5_IP_CFG_DEFINES_SW_PATCH_VERSION             1
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
/* @brief Enables / Disables multipartition support */
#define PSI5_IP_MULTIPARTITION_SUPPORT                 (STD_ON)

#define PSI5_IP_DEV_ERROR_DETECT                       (STD_OFF)

/* Define for HW channelId of channel Psi5Channel_0 */
#define PSI5_0_CH0    (0U)
#define PSI5_IP_ENABLE_INTERRUPTS_PSI5_0_CH0


#define PSI5_IP_DMA_IS_USED                            (STD_OFF)
#define PSI5_IP_DMA_PSI5_FRAME_IS_USED                 (STD_OFF)
#define PSI5_IP_DMA_SMC_FRAME_IS_USED                  (STD_OFF)

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

#endif /* PSI5_IP_CFG_DEFINES_H */

