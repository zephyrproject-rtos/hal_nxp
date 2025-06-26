/*
 * Copyright 2022-2025 NXP
*
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**   
*   @file    Mru_Ip_Cfg.c
*   @version 2.0.1
*
*   @brief   AUTOSAR Platform - Pre-Compile configuration file code template.
*   @details Code template for Pre-Compile configuration file generation.
*
*   @addtogroup MRU_IP_DRIVER_CONFIGURATION Mru Ip Driver Configuration
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
#include "Mru_Ip.h"

/*==================================================================================================
*                        SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define CDD_PLATFORM_MRU_IP_VENDOR_ID_CFG_C                        43
#define CDD_PLATFORM_MRU_IP_AR_RELEASE_MAJOR_VERSION_CFG_C         4
#define CDD_PLATFORM_MRU_IP_AR_RELEASE_MINOR_VERSION_CFG_C         7
#define CDD_PLATFORM_MRU_IP_AR_RELEASE_REVISION_VERSION_CFG_C      0
#define CDD_PLATFORM_MRU_IP_SW_MAJOR_VERSION_CFG_C                 2
#define CDD_PLATFORM_MRU_IP_SW_MINOR_VERSION_CFG_C                 0
#define CDD_PLATFORM_MRU_IP_SW_PATCH_VERSION_CFG_C                 1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Mru_Ip.h and Mru_Ip_Cfg.c are of the same vendor */
#if (CDD_PLATFORM_MRU_IP_VENDOR_ID != CDD_PLATFORM_MRU_IP_VENDOR_ID_CFG_C)
    #error "Mru_Ip.h and Mru_Ip_Cfg.c have different vendor ids"
#endif
/* Check if Mru_Ip.h file and Mru_Ip_Cfg.c file are of the same Autosar version */
#if ((CDD_PLATFORM_MRU_IP_AR_RELEASE_MAJOR_VERSION != CDD_PLATFORM_MRU_IP_AR_RELEASE_MAJOR_VERSION_CFG_C) || \
     (CDD_PLATFORM_MRU_IP_AR_RELEASE_MINOR_VERSION != CDD_PLATFORM_MRU_IP_AR_RELEASE_MINOR_VERSION_CFG_C) || \
     (CDD_PLATFORM_MRU_IP_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_MRU_IP_AR_RELEASE_REVISION_VERSION_CFG_C))
#error "AutoSar Version Numbers of Mru_Ip.h and Mru_Ip_Cfg.c are different"
#endif
#if ((CDD_PLATFORM_MRU_IP_SW_MAJOR_VERSION != CDD_PLATFORM_MRU_IP_SW_MAJOR_VERSION_CFG_C) || \
     (CDD_PLATFORM_MRU_IP_SW_MINOR_VERSION != CDD_PLATFORM_MRU_IP_SW_MINOR_VERSION_CFG_C) || \
     (CDD_PLATFORM_MRU_IP_SW_PATCH_VERSION != CDD_PLATFORM_MRU_IP_SW_PATCH_VERSION_CFG_C))
#error "Software Version Numbers of Mru_Ip.h and Mru_Ip_Cfg.c are different"
#endif
/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_CONST_UNSPECIFIED
#include "Platform_MemMap.h"

RTU_MRU_Type* const Mru_Ip_apxRTU_Bases[RTU_MRU_INSTANCE_COUNT] = IP_RTU_MRU_BASE_PTRS;
#define PLATFORM_STOP_SEC_CONST_UNSPECIFIED
#include "Platform_MemMap.h"
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

