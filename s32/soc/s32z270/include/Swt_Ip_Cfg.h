/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SWT_IP_CFG_H
#define SWT_IP_CFG_H

/**
*   @file
*
*   @addtogroup SWT_ip_config SWT IPL Configuration
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
#include "StandardTypes.h"
#include "Swt_Ip_Init_PBcfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SWT_IP_VENDOR_ID_CFG_H                     43
#define SWT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H      4
#define SWT_IP_AR_RELEASE_MINOR_VERSION_CFG_H      7
#define SWT_IP_AR_RELEASE_REVISION_VERSION_CFG_H   0
#define SWT_IP_SW_MAJOR_VERSION_CFG_H              1
#define SWT_IP_SW_MINOR_VERSION_CFG_H              0
#define SWT_IP_SW_PATCH_VERSION_CFG_H              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against StandardTypes.h */
    #if ((SWT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SWT_IP_AR_RELEASE_MINOR_VERSION_CFG_H != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Swt_Ip_Cfg.h and StandardTypes.h are different"
    #endif
#endif

/* Check if current file and Swt_Ip_Init_PBcfg.h file are of the same vendor */
#if (SWT_IP_VENDOR_ID_CFG_H != SWT_IP_VENDOR_ID_INIT_PBCFG)
    #error "Swt_Ip_Cfg.h and Swt_Ip_Init_PBcfg.h have different vendor IDs"
#endif

/* Check if current file and Swt_Ip_Init_PBcfg.h file are of the same Autosar version */
#if ((SWT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H     != SWT_IP_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG) || \
     (SWT_IP_AR_RELEASE_MINOR_VERSION_CFG_H     != SWT_IP_AR_RELEASE_MINOR_VERSION_INIT_PBCFG) || \
     (SWT_IP_AR_RELEASE_REVISION_VERSION_CFG_H  != SWT_IP_AR_RELEASE_REVISION_VERSION_INIT_PBCFG) \
    )
    #error "AutoSar Version Numbers of Swt_Ip_Cfg.h and Swt_Ip_Init_PBcfg.h are different"
#endif

/* Check if current file and Swt_Ip_Init_PBcfg.h file are of the same software version */
#if ((SWT_IP_SW_MAJOR_VERSION_CFG_H != SWT_IP_SW_MAJOR_VERSION_INIT_PBCFG) || \
     (SWT_IP_SW_MINOR_VERSION_CFG_H != SWT_IP_SW_MINOR_VERSION_INIT_PBCFG) || \
     (SWT_IP_SW_PATCH_VERSION_CFG_H != SWT_IP_SW_PATCH_VERSION_INIT_PBCFG) \
    )
    #error "Software Version Numbers of Swt_Ip_Cfg.h and Swt_Ip_Init_PBcfg.h are different"
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

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SWT_IP_CFG_H */
