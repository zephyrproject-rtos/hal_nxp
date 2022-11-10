/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SWT_IP_INIT_PBCFG_H
#define SWT_IP_INIT_PBCFG_H

/**
*   @file
*
*   @addtogroup Swt
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
#include "Swt_Ip_Cfg_Defines.h"
#include "Swt_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SWT_IP_VENDOR_ID_INIT_PBCFG                    43
#define SWT_IP_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG     4
#define SWT_IP_AR_RELEASE_MINOR_VERSION_INIT_PBCFG     7
#define SWT_IP_AR_RELEASE_REVISION_VERSION_INIT_PBCFG  0
#define SWT_IP_SW_MAJOR_VERSION_INIT_PBCFG             0
#define SWT_IP_SW_MINOR_VERSION_INIT_PBCFG             9
#define SWT_IP_SW_PATCH_VERSION_INIT_PBCFG             0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Swt_Ip_Cfg_Defines header file are of the same vendor */
#if (SWT_IP_VENDOR_ID_INIT_PBCFG != SWT_IP_CFG_DEFINES_VENDOR_ID)
#error "Swt_Ip_Init_PBcfg.h and Swt_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if current file and Swt_Ip_Cfg_Defines header file are of the same Autosar version */
#if ((SWT_IP_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG    != SWT_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (SWT_IP_AR_RELEASE_MINOR_VERSION_INIT_PBCFG    != SWT_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (SWT_IP_AR_RELEASE_REVISION_VERSION_INIT_PBCFG != SWT_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Swt_Ip_Init_PBcfg.h and Swt_Ip_Cfg_Defines.h are different"
#endif

/* Check if current file and Swt_Ip_Cfg_Defines header file are of the same software version */
#if ((SWT_IP_SW_MAJOR_VERSION_INIT_PBCFG != SWT_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (SWT_IP_SW_MINOR_VERSION_INIT_PBCFG != SWT_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (SWT_IP_SW_PATCH_VERSION_INIT_PBCFG != SWT_IP_CFG_DEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of Swt_Ip_Init_PBcfg.h and Swt_Ip_Cfg_Defines.h are different"
#endif

/* Check if current file and Swt_Ip_Types.h header file are of the same vendor */
#if (SWT_IP_VENDOR_ID_INIT_PBCFG != SWT_IP_TYPES_VENDOR_ID)
#error "Swt_Ip_Init_PBcfg.h and Swt_Ip_Types.h have different vendor ids"
#endif

#if ((SWT_IP_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG    != SWT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SWT_IP_AR_RELEASE_MINOR_VERSION_INIT_PBCFG    != SWT_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SWT_IP_AR_RELEASE_REVISION_VERSION_INIT_PBCFG != SWT_IP_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Swt_Ip_Init_PBcfg.h and Swt_Ip_Types.h are different"
#endif

#if ((SWT_IP_SW_MAJOR_VERSION_INIT_PBCFG != SWT_IP_TYPES_SW_MAJOR_VERSION) || \
     (SWT_IP_SW_MINOR_VERSION_INIT_PBCFG != SWT_IP_TYPES_SW_MINOR_VERSION) || \
     (SWT_IP_SW_PATCH_VERSION_INIT_PBCFG != SWT_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Swt_Ip_Init_PBcfg.h and Swt_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

extern const Swt_Ip_ConfigType Swt_Ip_Cfg0;
extern const Swt_Ip_ConfigType Swt_Ip_Cfg1;
extern const Swt_Ip_ConfigType Swt_Ip_Cfg2;
extern const Swt_Ip_ConfigType Swt_Ip_Cfg3;
extern const Swt_Ip_ConfigType Swt_Ip_Cfg4;

#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SWT_43_INSTANCE_IP_INIT_PBCFG_H */



