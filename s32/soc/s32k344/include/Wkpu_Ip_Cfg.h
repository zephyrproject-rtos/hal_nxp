/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef WKPU_IP_CFG_H
#define WKPU_IP_CFG_H

/**
 *   @file    Wkpu_Ip_Cfg.h
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
#include "Wkpu_Ip_SA_Init_PBcfg.h"
/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/

#define WKPU_IP_CFG_VENDOR_ID                       43
#define WKPU_IP_CFG_AR_RELEASE_MAJOR_VERSION        4
#define WKPU_IP_CFG_AR_RELEASE_MINOR_VERSION        7
#define WKPU_IP_CFG_AR_RELEASE_REVISION_VERSION     0
#define WKPU_IP_CFG_SW_MAJOR_VERSION                3
#define WKPU_IP_CFG_SW_MINOR_VERSION                0
#define WKPU_IP_CFG_SW_PATCH_VERSION                0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WKPU_IP_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (WKPU_IP_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wkpu_Ip_Cfg.h and Std_Types.h are different"
    #endif
#endif

#if (WKPU_IP_CFG_VENDOR_ID != WKPU_IP_SA_INIT_PBCFG_VENDOR_ID)
    #error "Wkpu_Ip_Cfg.h and Wkpu_Ip_SA_INIT_PBcfg.h have different vendor ids"
#endif

/* Check if  header file and Wkpu_Ip_SA_Init_PBcfg.h file are of the same Autosar version */
#if ((WKPU_IP_CFG_AR_RELEASE_MAJOR_VERSION != WKPU_IP_SA_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (WKPU_IP_CFG_AR_RELEASE_MINOR_VERSION != WKPU_IP_SA_INIT_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (WKPU_IP_CFG_AR_RELEASE_REVISION_VERSION != WKPU_IP_SA_INIT_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wkpu_Ip_Cfg.h and Wkpu_Ip_SA_Init_PBcfg.h are different"
#endif

/* Check if header file and Wkpu_Ip_SA_Init_PBcfg.h file are of the same Software version */
#if ((WKPU_IP_CFG_SW_MAJOR_VERSION != WKPU_IP_SA_INIT_PBCFG_SW_MAJOR_VERSION) || \
     (WKPU_IP_CFG_SW_MINOR_VERSION != WKPU_IP_SA_INIT_PBCFG_SW_MINOR_VERSION) || \
     (WKPU_IP_CFG_SW_PATCH_VERSION != WKPU_IP_SA_INIT_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Wkpu_Ip_Cfg.h and Wkpu_Ip_SA_Init_PBcfg.h are different"
#endif
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#if (STD_ON == WKPU_IP_USED)
#define WKPU_IP_DEV_ERROR_DETECT          (STD_OFF)
#define WKPU_IP_SET_MODE_API             (STD_ON)
#define WKPU_IP_64_CH_USED             (STD_ON)
#define WKPU_ICU_SINGLE_INTERRUPT     (STD_ON)

/* Macro used to export generated configuration. */
#define WKPU_CONFIG_EXT \
        WKPU_CONFIG_SA_INIT_PB \

#endif /* WKPU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* WKPU_IP_CFG_TYPES_H */
