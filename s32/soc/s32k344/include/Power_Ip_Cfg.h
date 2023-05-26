/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef POWER_IP_CFG_H
#define POWER_IP_CFG_H

/**
*   @file       Power_Ip_Cfg.h
*   @version    3.0.0
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup POWER_DRIVER_CONFIGURATION Power Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Power_Ip_Init_PBcfg.h"



/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_CFG_VENDOR_ID                      43
#define POWER_IP_CFG_AR_RELEASE_MAJOR_VERSION       4
#define POWER_IP_CFG_AR_RELEASE_MINOR_VERSION       7
#define POWER_IP_CFG_AR_RELEASE_REVISION_VERSION    0
#define POWER_IP_CFG_SW_MAJOR_VERSION               3
#define POWER_IP_CFG_SW_MINOR_VERSION               0
#define POWER_IP_CFG_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_Cfg.h file and Power_Ip_Init_PBcfg.h file are of the same vendor */
#if (POWER_IP_CFG_VENDOR_ID != POWER_IP_PBCFG_VENDOR_ID)
    #error "Power_Ip_Cfg.h and Power_Ip_Init_PBcfg.h have different vendor ids"
#endif

/* Check if Power_Ip_Cfg.h file and Power_Ip_Init_PBcfg.h file are of the same Autosar version */
#if ((POWER_IP_CFG_AR_RELEASE_MAJOR_VERSION != POWER_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_CFG_AR_RELEASE_MINOR_VERSION != POWER_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_CFG_AR_RELEASE_REVISION_VERSION != POWER_IP_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_Cfg.h and Power_Ip_Init_PBcfg.h are different"
#endif

/* Check if Power_Ip_Cfg.h file and Power_Ip_Init_PBcfg.h file are of the same Software version */
#if ((POWER_IP_CFG_SW_MAJOR_VERSION != POWER_IP_PBCFG_SW_MAJOR_VERSION) || \
     (POWER_IP_CFG_SW_MINOR_VERSION != POWER_IP_PBCFG_SW_MINOR_VERSION) || \
     (POWER_IP_CFG_SW_PATCH_VERSION != POWER_IP_PBCFG_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of Power_Ip_Cfg.h and Power_Ip_Init_PBcfg.h are different"
#endif

/*==================================================================================================
                                           DEFINES AND MACROS
==================================================================================================*/
#define POWER_IP_DEV_ERROR_DETECT         (STD_OFF)

#define POWER_IP_TIMEOUT_TYPE                (OSIF_COUNTER_DUMMY)

#define POWER_IP_TIMEOUT_VALUE_US            (50000U)


/**
* @brief        Support for User mode.
*               If this parameter has been configured to 'TRUE' the Power can be executed from both supervisor and user mode.
*/
#define POWER_IP_ENABLE_USER_MODE_SUPPORT    (STD_OFF)

/** Check the driver user mode is enabled only when the MCAL_ENABLE_USER_MODE_SUPPORT is enabled */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Power in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.
  #endif /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */




/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"



#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* #ifndef POWER_IP_CFG_H */
