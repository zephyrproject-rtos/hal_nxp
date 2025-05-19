/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_MCL_IP_CFG_DEFINES_H
#define EMIOS_MCL_IP_CFG_DEFINES_H
/**
*   @file Emios_Mcl_Ip_Cfg_Defines.h
*
*   @version 2.0.1
*
*   @brief   AUTOSAR Mcl - MCL driver header file.
*   @details 
*
*   @addtogroup MCL_DRIVER MCL Driver
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
#include "Emios_Mcl_Ip_Cfg_DeviceRegisters.h"
#include "Emios_Icu_Ip_Cfg.h"
#include "Emios_Pwm_Ip_CfgDefines.h"

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_MCL_IP_CFG_DEFINES_VENDOR_ID                       43
#define EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_MCL_IP_CFG_DEFINES_SW_MAJOR_VERSION                2
#define EMIOS_MCL_IP_CFG_DEFINES_SW_MINOR_VERSION                0
#define EMIOS_MCL_IP_CFG_DEFINES_SW_PATCH_VERSION                1
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (EMIOS_MCL_IP_CFG_DEFINES_VENDOR_ID != EMIOS_MCL_IP_CFG_DEVICEREGISTERS_VENDOR_ID)
    #error "Emios_Mcl_Ip_Cfg_Defines.h and Emios_Mcl_Ip_Cfg_DeviceRegisters.h have different vendor ids"
#endif

/* Check if  header file and Emios_Mcl_Ip_Cfg_DeviceRegisters.h file are of the same Autosar version */
#if ((EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != EMIOS_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != EMIOS_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != EMIOS_MCL_IP_CFG_DEVICEREGISTERS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Mcl_Ip_Cfg_Defines.h and Emios_Mcl_Ip_Cfg_DeviceRegisters.h are different"
#endif

/* Check if header file and Emios_Mcl_Ip_Cfg_DeviceRegisters.h file are of the same Software version */
#if ((EMIOS_MCL_IP_CFG_DEFINES_SW_MAJOR_VERSION != EMIOS_MCL_IP_CFG_DEVICEREGISTERS_SW_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_CFG_DEFINES_SW_MINOR_VERSION != EMIOS_MCL_IP_CFG_DEVICEREGISTERS_SW_MINOR_VERSION) || \
     (EMIOS_MCL_IP_CFG_DEFINES_SW_PATCH_VERSION != EMIOS_MCL_IP_CFG_DEVICEREGISTERS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Mcl_Ip_Cfg_Defines.h and Emios_Mcl_Ip_Cfg_DeviceRegisters.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if this header file and Emios_Icu_Ip_Cfg.h file are of the same Autosar version */
    #if ((EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != EMIOS_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != EMIOS_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Emios_Mcl_Ip_Cfg_Defines.h and Emios_Icu_Ip_Cfg.h are different"
    #endif
    /* Check if this header file and Emios_Pwm_Ip_CfgDefines.h file are of the same Autosar version */
    #if ((EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != EMIOS_PWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != EMIOS_PWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Emios_Mcl_Ip_Cfg_Defines.h and Emios_Pwm_Ip_CfgDefines.h are different"
    #endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Timer width */
#define EMIOS_MCL_IP_24BITS_TIMER_WIDTH       STD_OFF




/*-----------------------------------------------/
/  EMIOS HW MASTER BUSES                        /
/-----------------------------------------------*/
#define EMIOS_CH_0                        ((uint16)0U)
#define EMIOS_CH_16                        ((uint16)16U)
#define EMIOS_CH_23                        ((uint16)23U)
#define EMIOS_CH_24                        ((uint16)24U)

/* Macros that indicate EMIOS channels used by MCL. */

/* Macros used to save logic MCL EMIOS channel encoding. */

#define EMIOS_MCL_IP_DEV_ERROR_DETECT      (STD_OFF)

/** @brief Disable EMIOS multicore support at IP layer */
#define EMIOS_IP_MULTICORE_IS_AVAILABLE     (STD_OFF)



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

#endif /* EMIOS_MCL_IP_CFG_DEFINES_H */

