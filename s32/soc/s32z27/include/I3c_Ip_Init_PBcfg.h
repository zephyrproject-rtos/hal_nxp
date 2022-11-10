/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef I3C_IP_INIT_PBCFG_H
#define I3C_IP_INIT_PBCFG_H

/**
*   @file
*
*   @addtogroup i3c_ip_config I3c IPL Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "I3c_Ip_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define  I3C_IP_VENDOR_ID_INIT_PBCFG                    43
#define  I3C_IP_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG     4
#define  I3C_IP_AR_RELEASE_MINOR_VERSION_INIT_PBCFG     7
#define  I3C_IP_AR_RELEASE_REVISION_VERSION_INIT_PBCFG  0
#define  I3C_IP_SW_MAJOR_VERSION_INIT_PBCFG             0
#define  I3C_IP_SW_MINOR_VERSION_INIT_PBCFG             9
#define  I3C_IP_SW_PATCH_VERSION_INIT_PBCFG             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I3c_Ip_Types header file are of the same vendor */
#if (I3C_IP_VENDOR_ID_INIT_PBCFG != I3C_IP_VENDOR_ID_TYPES)
    #error "I3c_Ip_INIT_PBcfg.h and I3c_Ip_Types.h have different vendor ids"
#endif

/* Check if current file and I3c_Ip_Types header file are of the same Autosar version */
#if ((I3C_IP_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG     != I3C_IP_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (I3C_IP_AR_RELEASE_MINOR_VERSION_INIT_PBCFG     != I3C_IP_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (I3C_IP_AR_RELEASE_REVISION_VERSION_INIT_PBCFG  != I3C_IP_AR_RELEASE_REVISION_VERSION_TYPES))
    #error "AutoSar Version Numbers of I3c_Ip_Init_PBcfg.h and I3c_Ip_Types.h are different"
#endif

/* Check if current file and I3c_Ip_Types header file are of the same software version */
#if ((I3C_IP_SW_MAJOR_VERSION_INIT_PBCFG != I3C_IP_SW_MAJOR_VERSION_TYPES) || \
     (I3C_IP_SW_MINOR_VERSION_INIT_PBCFG != I3C_IP_SW_MINOR_VERSION_TYPES) || \
     (I3C_IP_SW_PATCH_VERSION_INIT_PBCFG != I3C_IP_SW_PATCH_VERSION_TYPES))
    #error "Software Version Numbers of I3c_Ip_Init_PBcfg.h and I3c_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define I3C_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "I3c_MemMap.h"

/**
* @brief I3C Ip Master Channel 0 Config for configuration variant Init.
*/
extern const I3c_Ip_MasterConfigType I3c_Ip_MasterChannel0Config_INIT;

#define I3C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "I3c_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define I3C_START_SEC_CODE
#include "I3c_MemMap.h"

/**
* @brief I3C Master Channel 0 Callback Function.
*/
extern void s32_i3c_2_master_callback(I3c_Ip_MasterEventType Event);


#define I3C_STOP_SEC_CODE
#include "I3c_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* I3C_IP_INIT_PBCFG_H */

