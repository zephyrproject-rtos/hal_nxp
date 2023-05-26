/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef POWER_IP_AEC_H
#define POWER_IP_AEC_H

/**
*   @file       Power_Ip_AEC.h
*   @version    3.0.0
*
*   @brief   POWER IP driver header file.
*   @details POWER IP driver header file.
*
*   @addtogroup POWER_DRIVER Power Ip Driver
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
#include "Power_Ip.h"
#include "Power_Ip_AEC_Types.h"
#include "StandardTypes.h"
#include "Mcal.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_AEC_VENDOR_ID                       43
#define POWER_IP_AEC_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_AEC_AR_RELEASE_MINOR_VERSION        7
#define POWER_IP_AEC_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_AEC_SW_MAJOR_VERSION                3
#define POWER_IP_AEC_SW_MINOR_VERSION                0
#define POWER_IP_AEC_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_AEC.h file and Power_Ip.h file are of the same vendor */
#if (POWER_IP_AEC_VENDOR_ID != POWER_IP_VENDOR_ID)
    #error "Power_Ip_AEC.h and Power_Ip.h have different vendor ids"
#endif

/* Check if Power_Ip_AEC.h file and Power_Ip.h file are of the same Autosar version */
#if ((POWER_IP_AEC_AR_RELEASE_MAJOR_VERSION != POWER_IP_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AEC_AR_RELEASE_MINOR_VERSION != POWER_IP_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_AEC_AR_RELEASE_REVISION_VERSION != POWER_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_AEC.h and Power_Ip.h are different"
#endif

/* Check if Power_Ip_AEC.h file and Power_Ip.h file are of the same Software version */
#if ((POWER_IP_AEC_SW_MAJOR_VERSION != POWER_IP_SW_MAJOR_VERSION) || \
     (POWER_IP_AEC_SW_MINOR_VERSION != POWER_IP_SW_MINOR_VERSION) || \
     (POWER_IP_AEC_SW_PATCH_VERSION != POWER_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_AEC.h and Power_Ip.h are different"
#endif

/* Check if Power_Ip_AEC.h file and Power_Ip_AEC_Types.h file are of the same vendor */
#if (POWER_IP_AEC_VENDOR_ID != POWER_IP_AEC_TYPES_VENDOR_ID)
    #error "Power_Ip_AEC.h and Power_Ip_AEC_Types.h have different vendor ids"
#endif

/* Check if Power_Ip_AEC.h file and Power_Ip_AEC_Types.h file are of the same Autosar version */
#if ((POWER_IP_AEC_AR_RELEASE_MAJOR_VERSION != POWER_IP_AEC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AEC_AR_RELEASE_MINOR_VERSION != POWER_IP_AEC_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_AEC_AR_RELEASE_REVISION_VERSION != POWER_IP_AEC_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_AEC.h and Power_Ip_AEC_Types.h are different"
#endif

/* Check if Power_Ip_AEC.h file and Power_Ip_AEC_Types.h file are of the same Software version */
#if ((POWER_IP_AEC_SW_MAJOR_VERSION != POWER_IP_AEC_TYPES_SW_MAJOR_VERSION) || \
     (POWER_IP_AEC_SW_MINOR_VERSION != POWER_IP_AEC_TYPES_SW_MINOR_VERSION) || \
     (POWER_IP_AEC_SW_PATCH_VERSION != POWER_IP_AEC_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_AEC.h and Power_Ip_AEC_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Power_Ip_AEC.h file and StandardTypes.h file are of the same Autosar version */
#if ((POWER_IP_AEC_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AEC_AR_RELEASE_MINOR_VERSION    != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_AEC.h and StandardTypes.h are different"
#endif

/* Check if Power_Ip_AEC.h file and Mcal.h file are of the same Autosar version */
#if ((POWER_IP_AEC_AR_RELEASE_MAJOR_VERSION    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AEC_AR_RELEASE_MINOR_VERSION    != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_AEC.h and Mcal.h are different"
#endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

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
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#if (defined(POWER_IP_AECRESETCONFIG_API) && (STD_ON == POWER_IP_AECRESETCONFIG_API))
void Power_Ip_AEC_Reset_Config(const Power_Ip_AEC_ConfigType * ConfigPtr);
#endif


#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
#endif /* POWER_IP_AEC_H */


