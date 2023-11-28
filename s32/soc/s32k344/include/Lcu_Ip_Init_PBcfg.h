/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* Prevention from multiple including the same header */
#ifndef LCU_IP_PBCFG_INIT_H
#define LCU_IP_PBCFG_INIT_H

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
#include "Lcu_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* Inclusion of incompatible header files shall be avoided */

#define LCU_IP_INIT_PBCFG_MODULE_ID                     255
#define LCU_IP_INIT_PBCFG_VENDOR_ID                     43
#define LCU_IP_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define LCU_IP_INIT_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define LCU_IP_INIT_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define LCU_IP_INIT_PBCFG_SW_MAJOR_VERSION              3
#define LCU_IP_INIT_PBCFG_SW_MINOR_VERSION              0
#define LCU_IP_INIT_PBCFG_SW_PATCH_VERSION              0
    /* Check if header file and Lcu_Ip_Types.h file are of the same vendor */
#if (LCU_IP_INIT_PBCFG_VENDOR_ID != LCU_IP_TYPES_VENDOR_ID)
    #error "Lcu_Ip_Init_PBcfg.h and Lcu_Ip_Types.h have different vendor ids"
#endif

/* Check if header file and Lcu_Ip_Types.h file are of the same Autosar version */
#if ((LCU_IP_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION != LCU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_INIT_PBCFG_AR_RELEASE_MINOR_VERSION != LCU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_INIT_PBCFG_AR_RELEASE_REVISION_VERSION != LCU_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip_Init_PBcfg.h and Lcu_Ip_Types.h are different"
#endif

/* Check if header file and Lcu_Ip_Types.h file are of the same Software version */
#if ((LCU_IP_INIT_PBCFG_SW_MAJOR_VERSION != LCU_IP_TYPES_SW_MAJOR_VERSION) || \
     (LCU_IP_INIT_PBCFG_SW_MINOR_VERSION != LCU_IP_TYPES_SW_MINOR_VERSION) || \
     (LCU_IP_INIT_PBCFG_SW_PATCH_VERSION != LCU_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip_Init_PBcfg.h and Lcu_Ip_Types.h are different"
#endif

/*===============================================================================================
					DEFINES AND MACROS
===============================================================================================*/

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

#endif

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
