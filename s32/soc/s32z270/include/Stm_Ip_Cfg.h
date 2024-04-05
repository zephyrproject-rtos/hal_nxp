/*
 * Copyright 2022-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef STM_IP_CFG_H
#define STM_IP_CFG_H
/**
*   @file           Stm_Ip_Cfg.h
*
*   @addtogroup stm_ip Stm IPL
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
#include "Stm_Ip_Init_PBcfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define STM_IP_VENDOR_ID_CFG                    43
#define STM_IP_AR_RELEASE_MAJOR_VERSION_CFG     4
#define STM_IP_AR_RELEASE_MINOR_VERSION_CFG     7
#define STM_IP_AR_RELEASE_REVISION_VERSION_CFG  0
#define STM_IP_SW_MAJOR_VERSION_CFG             1
#define STM_IP_SW_MINOR_VERSION_CFG             0
#define STM_IP_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (STM_IP_VENDOR_ID_CFG != STM_IP_VENDOR_ID_INIT_PBCFG_H)
    #error "Stm_Ip_Cfg.h and Stm_Ip_Init_PBcfg.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((STM_IP_AR_RELEASE_MAJOR_VERSION_CFG != STM_IP_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG_H) || \
     (STM_IP_AR_RELEASE_MINOR_VERSION_CFG != STM_IP_AR_RELEASE_MINOR_VERSION_INIT_PBCFG_H) || \
     (STM_IP_AR_RELEASE_REVISION_VERSION_CFG != STM_IP_AR_RELEASE_REVISION_VERSION_INIT_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Stm_Ip_Cfg.h and Stm_Ip_Init_PBcfg.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((STM_IP_SW_MAJOR_VERSION_CFG != STM_IP_SW_MAJOR_VERSION_INIT_PBCFG_H) || \
     (STM_IP_SW_MINOR_VERSION_CFG != STM_IP_SW_MINOR_VERSION_INIT_PBCFG_H) || \
     (STM_IP_SW_PATCH_VERSION_CFG != STM_IP_SW_PATCH_VERSION_INIT_PBCFG_H) \
    )
    #error "Software Version Numbers of Stm_Ip_Cfg.h and Stm_Ip_Init_PBcfg.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Dev error detect switch
*/
#define STM_IP_DEV_ERROR_DETECT     (STD_OFF)
/*================================================================================================*/
/**
* @brief    STM_IP_CHANGE_NEXT_TIMEOUT_VALUE switch
* @details  Enable/disable support for changing timeout value during timer running
*/
#define STM_IP_CHANGE_NEXT_TIMEOUT_VALUE     (STD_OFF)
/*================================================================================================*/
#define STM_IP_PREDEFTIMER_FUNCTIONALITY_API     (STD_OFF)
/*================================================================================================*/
/**
* @brief    STM_IP_ABSOLUTE_COUTNING_API switch
* @details  Enable/disable support for absolute compare value
*/
#define STM_IP_ABSOLUTE_COUNTING_API    (STD_ON)
/*================================================================================================*/

/**
* @brief    STM_IP_ENABLE_USER_MODE_SUPPORT switch
* @details  Enable/disable support usermode.If this parameter has been configured to TRUE the GPT driver code can be executed from both supervisor and user mode.
*/
#define STM_IP_ENABLE_USER_MODE_SUPPORT     (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef STM_IP_ENABLE_USER_MODE_SUPPORT
        #if (STD_ON == STM_IP_ENABLE_USER_MODE_SUPPORT)
            #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Gpt in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.
        #endif /* (STD_ON == STM_IP_ENABLE_USER_MODE_SUPPORT) */
    #endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
#endif /* ifdef MCAL_ENABLE_USER_MODE_SUPPORT*/

/**
*   @brief      GPT_STM_INSTANCE_COUNT
*   @details    GPT_STM_INSTANCE_COUNT
*/
#if (defined(CRS_FSS_AND_RTU_BASE_ADDR_OF_STM_REGISTERS_CONCATENATED) && (CRS_FSS_AND_RTU_BASE_ADDR_OF_STM_REGISTERS_CONCATENATED == STD_ON))
#define GPT_STM_INSTANCE_COUNT (STM_INSTANCE_COUNT + RTU_STM_INSTANCE_COUNT)
#else
#define GPT_STM_INSTANCE_COUNT (STM_INSTANCE_COUNT)
#endif

/*================================================================================================*/

/* Channels number instance RTU0_STM_0 */
#define RTU0_STM_0_IP_CHANNELS_NUMBER  (4U)
#define RTU0_STM_0_IP_EXISTS
#define RTU0_STM_0_IP_INSTANCE_NUMBER  (3U)/* Channels number instance RTU0_STM_1 */
#define RTU0_STM_1_IP_CHANNELS_NUMBER  (4U)
#define RTU0_STM_1_IP_EXISTS
#define RTU0_STM_1_IP_INSTANCE_NUMBER  (4U)/* Channels number instance RTU0_STM_2 */
#define RTU0_STM_2_IP_CHANNELS_NUMBER  (4U)
#define RTU0_STM_2_IP_EXISTS
#define RTU0_STM_2_IP_INSTANCE_NUMBER  (5U)/* Channels number instance RTU0_STM_3 */
#define RTU0_STM_3_IP_CHANNELS_NUMBER  (4U)
#define RTU0_STM_3_IP_EXISTS
#define RTU0_STM_3_IP_INSTANCE_NUMBER  (6U)/* Channels number instance RTU1_STM_0 */
#define RTU1_STM_0_IP_CHANNELS_NUMBER  (4U)
#define RTU1_STM_0_IP_EXISTS
#define RTU1_STM_0_IP_INSTANCE_NUMBER  (7U)/* Channels number instance RTU1_STM_1 */
#define RTU1_STM_1_IP_CHANNELS_NUMBER  (4U)
#define RTU1_STM_1_IP_EXISTS
#define RTU1_STM_1_IP_INSTANCE_NUMBER  (8U)/* Channels number instance RTU1_STM_2 */
#define RTU1_STM_2_IP_CHANNELS_NUMBER  (4U)
#define RTU1_STM_2_IP_EXISTS
#define RTU1_STM_2_IP_INSTANCE_NUMBER  (9U)/* Channels number instance RTU1_STM_3 */
#define RTU1_STM_3_IP_CHANNELS_NUMBER  (4U)
#define RTU1_STM_3_IP_EXISTS
#define RTU1_STM_3_IP_INSTANCE_NUMBER  (10U)/* Channels number instance CE_STM_0 */
#define CE_STM_0_IP_CHANNELS_NUMBER  (4U)
#define CE_STM_0_IP_EXISTS
#define CE_STM_0_IP_INSTANCE_NUMBER  (0U)/* Channels number instance CE_STM_1 */
#define CE_STM_1_IP_CHANNELS_NUMBER  (4U)
#define CE_STM_1_IP_EXISTS
#define CE_STM_1_IP_INSTANCE_NUMBER  (1U)/* Channels number instance CE_STM_2 */
#define CE_STM_2_IP_CHANNELS_NUMBER  (4U)
#define CE_STM_2_IP_EXISTS
#define CE_STM_2_IP_INSTANCE_NUMBER  (2U)/* Channels number instance SMU_STM_0 */
#define SMU_STM_0_IP_CHANNELS_NUMBER  (4U)
#define SMU_STM_0_IP_EXISTS
#define SMU_STM_0_IP_INSTANCE_NUMBER  (11U)/* Channels number instance SMU_STM_2 */
#define SMU_STM_2_IP_CHANNELS_NUMBER  (4U)
#define SMU_STM_2_IP_EXISTS
#define SMU_STM_2_IP_INSTANCE_NUMBER  (12U)
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

#endif  /* STM_IP_CFG_H */
