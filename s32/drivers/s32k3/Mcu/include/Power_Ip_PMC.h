/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef POWER_IP_PMC_H
#define POWER_IP_PMC_H

/**
*   @file       Power_Ip_PMC.h
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
#include "Power_Ip_Types.h"
#include "StandardTypes.h"
#include "Mcal.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_PMC_VENDOR_ID                       43
#define POWER_IP_PMC_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_PMC_AR_RELEASE_MINOR_VERSION        7
#define POWER_IP_PMC_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_PMC_SW_MAJOR_VERSION                3
#define POWER_IP_PMC_SW_MINOR_VERSION                0
#define POWER_IP_PMC_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Power_Ip_PMC.h file and StandardTypes.h file are of the same Autosar version */
#if ((POWER_IP_PMC_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_PMC_AR_RELEASE_MINOR_VERSION    != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_PMC.h and StandardTypes.h are different"
#endif

/* Check if Power_Ip_PMC.h file and Mcal.h file are of the same Autosar version */
#if ((POWER_IP_PMC_AR_RELEASE_MAJOR_VERSION    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_PMC_AR_RELEASE_MINOR_VERSION    != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_PMC.h and Mcal.h are different"
#endif
#endif  /* #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if Power_Ip_PMC.h file and Power_Ip_Types.h file have same versions */
#if (POWER_IP_PMC_VENDOR_ID  != POWER_IP_TYPES_VENDOR_ID)
    #error "Power_Ip_PMC.h and Power_Ip_Types.h have different vendor IDs"
#endif

/* Check if Power_Ip_PMC.h file and Power_Ip_Types.h file are of the same Autosar version */
#if ((POWER_IP_PMC_AR_RELEASE_MAJOR_VERSION    != POWER_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_PMC_AR_RELEASE_MINOR_VERSION    != POWER_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_PMC_AR_RELEASE_REVISION_VERSION != POWER_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_PMC.h and Power_Ip_Types.h are different"
#endif

/* Check if Power_Ip_PMC.h file and Power_Ip_Types.h file are of the same Software version */
#if ((POWER_IP_PMC_SW_MAJOR_VERSION != POWER_IP_TYPES_SW_MAJOR_VERSION) || \
     (POWER_IP_PMC_SW_MINOR_VERSION != POWER_IP_TYPES_SW_MINOR_VERSION) || \
     (POWER_IP_PMC_SW_PATCH_VERSION != POWER_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Power_Ip_PMC.h and Power_Ip_Types.h are different"
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


#if (defined(POWER_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)
    #if (defined(MCAL_PMC_REG_PROT_AVAILABLE))
      #if (STD_ON == MCAL_PMC_REG_PROT_AVAILABLE)
void Power_Ip_PMC_SetUserAccessAllowed(void);
      #endif /* (STD_ON == MCAL_PMC_REG_PROT_AVAILABLE) */
    #endif
  #endif /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */
#endif

void Power_Ip_PMC_PowerInit(const Power_Ip_PMC_ConfigType * ConfigPtr);

#if (defined(POWER_IP_PMCAECONFIG_API) && (STD_ON == POWER_IP_PMCAECONFIG_API))
void Power_Ip_PMC_AE_PowerInit(const Power_Ip_PMC_ConfigType * ConfigPtr);
#endif

#if (defined(POWER_IP_ENTER_LOW_POWER_MODE))
  #if (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON)

#ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)

#define  Call_Power_Ip_PMC_PrepareLowPowerEntry() \
    OsIf_Trusted_Call(Power_Ip_PMC_PrepareLowPowerEntry)
  #else

#define  Call_Power_Ip_PMC_PrepareLowPowerEntry() \
    Power_Ip_PMC_PrepareLowPowerEntry()
  #endif  /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */
#endif /* #ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT */


void Power_Ip_PMC_PrepareLowPowerEntry(void);

  #endif /* (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON) */
#endif

#if (defined(POWER_IP_VOLTAGE_ERROR_ISR_USED))
  #if(POWER_IP_VOLTAGE_ERROR_ISR_USED == STD_ON)
void Power_Ip_PMC_VoltageErrorIsr(void);

#if (defined(POWER_IP_PMCAECONFIG_API) && (STD_ON == POWER_IP_PMCAECONFIG_API))
void Power_Ip_PMC_AE_VoltageDetectHvdOnVddintVdd15Isr(void);
void Power_Ip_PMC_AE_VoltageDetectHvdOnVddIsr(void);
void Power_Ip_PMC_AE_VoltageDetectLvdOnVddcIsr(void);
void Power_Ip_PMC_AE_VoltageDetectLvdOnVlsIsr(void);
#endif

  #endif
#endif /* (POWER_IP_VOLTAGE_ERROR_ISR_USED == STD_ON) */

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
#endif /* POWER_IP_PMC_H */

