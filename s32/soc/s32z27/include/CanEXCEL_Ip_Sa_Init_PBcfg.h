/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CANEXCEL_IP_SA_INIT_PBCFG_H
#define CANEXCEL_IP_SA_INIT_PBCFG_H
/**
*   @file CanEXCEL_IP_PBcfg.h
*
*   @addtogroup CanEXCEL
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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @file           CanEXCEL_Ip_Sa_Init_PBcfg.h
*/
#define CANEXCEL_IP_SA_VENDOR_ID_INIT_PBCFG_H                     43
#define CANEXCEL_IP_SA_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG_H      4
#define CANEXCEL_IP_SA_AR_RELEASE_MINOR_VERSION_INIT_PBCFG_H      7
#define CANEXCEL_IP_SA_AR_RELEASE_REVISION_VERSION_INIT_PBCFG_H   0
#define CANEXCEL_IP_SA_SW_MAJOR_VERSION_INIT_PBCFG_H              0
#define CANEXCEL_IP_SA_SW_MINOR_VERSION_INIT_PBCFG_H              9
#define CANEXCEL_IP_SA_SW_PATCH_VERSION_INIT_PBCFG_H              0
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define CANEXCEL_IP_INIT_SA_PB_CFG \
extern const Canexcel_Ip_ConfigType CanXL_Config0; \
extern const Canexcel_Ip_ConfigType CanXL_Config1; 
#define INST_INIT_CANXL_0 0U
#define INST_INIT_CANXL_1 1U
#define CANEXCEL_IP_INIT_SA_STATE_PB_CFG \
extern Canexcel_Ip_StateType CanEXCEL_Init_State0; \
extern Canexcel_Ip_StateType CanEXCEL_Init_State1; 
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CANEXCEL_IP_PBCFG_H */

