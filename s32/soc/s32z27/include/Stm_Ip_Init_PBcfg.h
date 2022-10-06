/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef STM_IP_INIT_PBCFG_H
#define STM_IP_INIT_PBCFG_H

/**
*   @file          Stm_Ip_PBcfg.h
*
*   @addtogroup    stm_ip Stm IPL
*
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Stm_Ip_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define STM_IP_VENDOR_ID_INIT_PBCFG_H                    43
#define STM_IP_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG_H     4
#define STM_IP_AR_RELEASE_MINOR_VERSION_INIT_PBCFG_H     4
#define STM_IP_AR_RELEASE_REVISION_VERSION_INIT_PBCFG_H  0
#define STM_IP_SW_MAJOR_VERSION_INIT_PBCFG_H             0
#define STM_IP_SW_MINOR_VERSION_INIT_PBCFG_H             8
#define STM_IP_SW_PATCH_VERSION_INIT_PBCFG_H             0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (STM_IP_VENDOR_ID_INIT_PBCFG_H != STM_IP_TYPES_VENDOR_ID)
    #error "Stm_Ip_INIT_PBcfg.h and Stm_Ip_Types.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((STM_IP_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG_H != STM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (STM_IP_AR_RELEASE_MINOR_VERSION_INIT_PBCFG_H != STM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (STM_IP_AR_RELEASE_REVISION_VERSION_INIT_PBCFG_H != STM_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Stm_Ip_INIT_PBcfg.h and Stm_Ip_Types.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((STM_IP_SW_MAJOR_VERSION_INIT_PBCFG_H != STM_IP_TYPES_SW_MAJOR_VERSION) || \
     (STM_IP_SW_MINOR_VERSION_INIT_PBCFG_H != STM_IP_TYPES_SW_MINOR_VERSION) || \
     (STM_IP_SW_PATCH_VERSION_INIT_PBCFG_H != STM_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Stm_Ip_INIT_PBcfg.h and Stm_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define RTU0_STM_0_CH_0 &RTU0_STM_0_ChannelConfig_PB[0]
#define RTU0_STM_0_CH_1 &RTU0_STM_0_ChannelConfig_PB[1]
#define RTU0_STM_0_CH_2 &RTU0_STM_0_ChannelConfig_PB[2]
#define RTU0_STM_0_CH_3 &RTU0_STM_0_ChannelConfig_PB[3]
#define RTU0_STM_1_CH_0 &RTU0_STM_1_ChannelConfig_PB[0]
#define RTU0_STM_1_CH_1 &RTU0_STM_1_ChannelConfig_PB[1]
#define RTU0_STM_1_CH_2 &RTU0_STM_1_ChannelConfig_PB[2]
#define RTU0_STM_1_CH_3 &RTU0_STM_1_ChannelConfig_PB[3]
#define RTU0_STM_2_CH_0 &RTU0_STM_2_ChannelConfig_PB[0]
#define RTU0_STM_2_CH_1 &RTU0_STM_2_ChannelConfig_PB[1]
#define RTU0_STM_2_CH_2 &RTU0_STM_2_ChannelConfig_PB[2]
#define RTU0_STM_2_CH_3 &RTU0_STM_2_ChannelConfig_PB[3]
#define RTU0_STM_3_CH_0 &RTU0_STM_3_ChannelConfig_PB[0]
#define RTU0_STM_3_CH_1 &RTU0_STM_3_ChannelConfig_PB[1]
#define RTU0_STM_3_CH_2 &RTU0_STM_3_ChannelConfig_PB[2]
#define RTU0_STM_3_CH_3 &RTU0_STM_3_ChannelConfig_PB[3]

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"
extern const Stm_Ip_InstanceConfigType RTU0_STM_0_InitConfig_PB;
extern const Stm_Ip_InstanceConfigType RTU0_STM_1_InitConfig_PB;
extern const Stm_Ip_InstanceConfigType RTU0_STM_2_InitConfig_PB;
extern const Stm_Ip_InstanceConfigType RTU0_STM_3_InitConfig_PB;
extern const Stm_Ip_ChannelConfigType RTU0_STM_0_ChannelConfig_PB[4U];
extern const Stm_Ip_ChannelConfigType RTU0_STM_1_ChannelConfig_PB[4U];
extern const Stm_Ip_ChannelConfigType RTU0_STM_2_ChannelConfig_PB[4U];
extern const Stm_Ip_ChannelConfigType RTU0_STM_3_ChannelConfig_PB[4U];
#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* STM_IP_PBCFG_H */
