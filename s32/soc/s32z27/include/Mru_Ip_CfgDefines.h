/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MRU_IP_CFG_DEFINES_H_
#define MRU_IP_CFG_DEFINES_H_

#ifdef __cplusplus
extern "C"
{
#endif
/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "StandardTypes.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_MRU_IP_CFG_DEFINES_VENDOR_ID                          43
#define CDD_PLATFORM_MRU_IP_CFG_DEFINES_SW_MAJOR_VERSION                   1
#define CDD_PLATFORM_MRU_IP_CFG_DEFINES_SW_MINOR_VERSION                   0
#define CDD_PLATFORM_MRU_IP_CFG_DEFINES_SW_PATCH_VERSION                   0
#define CDD_PLATFORM_MRU_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION           4
#define CDD_PLATFORM_MRU_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION           7
#define CDD_PLATFORM_MRU_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION        0
/*==================================================================================================
                                            CONSTANTS
==================================================================================================*/
 
/*==================================================================================================
 *                                     DEFINES AND MACROS
==================================================================================================*/

#define NOTIFY_STATUS_COUNT 2U


#define MRU_IP_CH_CFG0_CHE_MASK                 (0x1U)
#define MRU_IP_CH_CFG0_IE_MASK                  (0x4U)
#define MRU_IP_CH_MBSTAT_MBS0_MASK              (0x10000U)
#define MRU_CH_MBSTAT_MBS0_WIDTH                (1U)
#define MRU_IP_CH_CFG1_MBIC0_MASK               (0x10000U)
#define MRU_IP_CH_CFG1_MBIC0_SHIFT              (16U)
#define NUMBER_OF_INTERRUPT_GROUP               (2U)
#define MRU_CH_CFG1_MBIC0_WIDTH                 (1U)

#define MRU_IP_NOTIFY_CH1_IS_MASK               (0x1U) /*The notify status mask of first channel*/

#define PLATFORM_TIMEOUT_TYPE                   (OSIF_COUNTER_DUMMY)

#ifdef __cplusplus
}
#endif

#endif /* MRU_IP_CFG_DEFINES_H_ */

/** @} */
