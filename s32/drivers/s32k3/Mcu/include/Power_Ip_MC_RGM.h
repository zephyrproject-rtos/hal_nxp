/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef POWER_IP_MC_RGM_H
#define POWER_IP_MC_RGM_H

/**
*   @file       Power_Ip_MC_RGM.h
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
#define POWER_IP_MC_RGM_VENDOR_ID                       43
#define POWER_IP_MC_RGM_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_MC_RGM_AR_RELEASE_MINOR_VERSION        7
#define POWER_IP_MC_RGM_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_MC_RGM_SW_MAJOR_VERSION                3
#define POWER_IP_MC_RGM_SW_MINOR_VERSION                0
#define POWER_IP_MC_RGM_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Power_Ip_MC_RGM.h file and StandardTypes.h file are of the same Autosar version */
#if ((POWER_IP_MC_RGM_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_MC_RGM_AR_RELEASE_MINOR_VERSION    != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_MC_RGM.h and StandardTypes.h are different"
#endif

/* Check if Power_Ip_MC_RGM.h file and Mcal.h file are of the same Autosar version */
#if ((POWER_IP_MC_RGM_AR_RELEASE_MAJOR_VERSION    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_MC_RGM_AR_RELEASE_MINOR_VERSION    != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_MC_RGM.h and Mcal.h are different"
#endif
#endif

/* Check if Power_Ip_MC_RGM.h file and Power_Ip_Types.h file have same versions */
#if (POWER_IP_MC_RGM_VENDOR_ID  != POWER_IP_TYPES_VENDOR_ID)
    #error "Power_Ip_MC_RGM.h and Power_Ip_Types.h have different vendor IDs"
#endif

/* Check if Power_Ip_MC_RGM.h file and Power_Ip_Types.h file are of the same Autosar version */
#if ((POWER_IP_MC_RGM_AR_RELEASE_MAJOR_VERSION    != POWER_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_MC_RGM_AR_RELEASE_MINOR_VERSION    != POWER_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_MC_RGM_AR_RELEASE_REVISION_VERSION != POWER_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_MC_RGM.h and Power_Ip_Types.h are different"
#endif

/* Check if Power_Ip_MC_RGM.h file and Power_Ip_Types.h file are of the same Software version */
#if ((POWER_IP_MC_RGM_SW_MAJOR_VERSION != POWER_IP_TYPES_SW_MAJOR_VERSION) || \
     (POWER_IP_MC_RGM_SW_MINOR_VERSION != POWER_IP_TYPES_SW_MINOR_VERSION) || \
     (POWER_IP_MC_RGM_SW_PATCH_VERSION != POWER_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Power_Ip_MC_RGM.h and Power_Ip_Types.h are different"
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
    #if (defined(MCAL_MC_RGM_REG_PROT_AVAILABLE))
      #if (STD_ON == MCAL_MC_RGM_REG_PROT_AVAILABLE)
void Power_Ip_MC_RGM_SetUserAccessAllowed(void);
      #endif /* (STD_ON == MCAL_MC_RGM_REG_PROT_AVAILABLE) */
    #endif
    #if (defined(MCAL_RDC_REG_PROT_AVAILABLE))
      #if (STD_ON == MCAL_RDC_REG_PROT_AVAILABLE)
void Power_Ip_RDC_SetUserAccessAllowed(void);
      #endif /* (STD_ON == MCAL_RDC_REG_PROT_AVAILABLE) */
    #endif
  #endif
#endif /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */


#ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)

#define  Call_Power_Ip_MC_RGM_ResetInit(MC_RGM_pConfigPtr) \
    OsIf_Trusted_Call1param(Power_Ip_MC_RGM_ResetInit,(MC_RGM_pConfigPtr))
  #else

#define  Call_Power_Ip_MC_RGM_ResetInit(MC_RGM_pConfigPtr) \
    Power_Ip_MC_RGM_ResetInit(MC_RGM_pConfigPtr)
  #endif
#endif

#ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)

#define  Call_Power_Ip_MC_RGM_PerformReset(MC_RGM_pConfigPtr) \
    OsIf_Trusted_Call1param(Power_Ip_MC_RGM_PerformReset,(MC_RGM_pConfigPtr))
  #else

#define  Call_Power_Ip_MC_RGM_PerformReset(MC_RGM_pConfigPtr) \
    Power_Ip_MC_RGM_PerformReset(MC_RGM_pConfigPtr)
  #endif
#endif /* POWER_IP_ENABLE_USER_MODE_SUPPORT */


#ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)

#define  Call_Power_Ip_MC_RGM_GetResetReason() \
    OsIf_Trusted_Call_Return((uint32)Power_Ip_MC_RGM_GetResetReason)
  #else

#define  Call_Power_Ip_MC_RGM_GetResetReason() \
    Power_Ip_MC_RGM_GetResetReason()
  #endif
#endif /* POWER_IP_ENABLE_USER_MODE_SUPPORT */


#ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)

#define  Call_Power_Ip_MC_RGM_GetResetRawValue() \
    OsIf_Trusted_Call_Return(Power_Ip_MC_RGM_GetResetRawValue)
  #else

#define  Call_Power_Ip_MC_RGM_GetResetRawValue() \
    Power_Ip_MC_RGM_GetResetRawValue()
  #endif
#endif

#if (defined(POWER_IP_RESET_DURING_STANDBY_SUPPORTED))
  #if (POWER_IP_RESET_DURING_STANDBY_SUPPORTED == STD_ON)
    #if (defined(POWER_IP_ENTER_LOW_POWER_MODE))
      #if (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON)
        #ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT
          #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)

#define  Call_Power_Ip_MC_RGM_ResetDuringStandby() \
    OsIf_Trusted_Call_Return(Power_Ip_MC_RGM_ResetDuringStandby)
          #else

#define  Call_Power_Ip_MC_RGM_ResetDuringStandby() \
    Power_Ip_MC_RGM_ResetDuringStandby()
          #endif
        #endif /* POWER_IP_ENABLE_USER_MODE_SUPPORT */
      #endif /*(POWER_IP_ENTER_LOW_POWER_MODE == STD_ON) */
    #endif
  #endif
#endif /* (POWER_IP_RESET_DURING_STANDBY_SUPPORTED == STD_ON) */


void Power_Ip_MC_RGM_ResetInit(const Power_Ip_MC_RGM_ConfigType * ConfigPtr);

Power_Ip_ResetType Power_Ip_MC_RGM_GetResetReason(void);
Power_Ip_RawResetType Power_Ip_MC_RGM_GetResetRawValue(void);


#if (defined(POWER_IP_RESET_DURING_STANDBY_SUPPORTED))
  #if (POWER_IP_RESET_DURING_STANDBY_SUPPORTED == STD_ON)
    #if (defined(POWER_IP_ENTER_LOW_POWER_MODE))
      #if (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON)
uint8 Power_Ip_MC_RGM_ResetDuringStandby(void);
      #endif /*(POWER_IP_ENTER_LOW_POWER_MODE == STD_ON) */
    #endif
  #endif
#endif /* (POWER_IP_RESET_DURING_STANDBY_SUPPORTED == STD_ON) */

#if (defined(POWER_IP_PERFORM_RESET_API))
  #if (POWER_IP_PERFORM_RESET_API == STD_ON)
void Power_Ip_MC_RGM_PerformReset(const Power_Ip_MC_RGM_ConfigType * ConfigPtr);
  #endif /* (POWER_IP_PERFORM_RESET_API == STD_ON) */
#endif

#if (defined(POWER_IP_RESET_ALTERNATE_ISR_USED))
  #if (POWER_IP_RESET_ALTERNATE_ISR_USED == STD_ON)
void Power_Ip_MC_RGM_ResetAltInt(void);
#endif /* (POWER_IP_RESET_ALTERNATE_ISR_USED == STD_ON) */
#endif


#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
#endif /* POWER_IP_MC_RGM_H */

