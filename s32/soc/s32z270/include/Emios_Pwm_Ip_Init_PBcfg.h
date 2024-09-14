/*
 * Copyright 2021-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_PWM_IP_INIT_PBCFG_H
#define EMIOS_PWM_IP_INIT_PBCFG_H

/**
*   @file       Emios_Pwm_Ip_Init_PBcfg.h
*
*   @addtogroup emios_pwm_ip Emios Pwm IPL
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
#include "Emios_Pwm_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_PWM_IP_INIT_PB_CFG_VENDOR_ID                       43
#define EMIOS_PWM_IP_INIT_PB_CFG_MODULE_ID                       121
#define EMIOS_PWM_IP_INIT_PB_CFG_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_PWM_IP_INIT_PB_CFG_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_PWM_IP_INIT_PB_CFG_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_PWM_IP_INIT_PB_CFG_SW_MAJOR_VERSION                2
#define EMIOS_PWM_IP_INIT_PB_CFG_SW_MINOR_VERSION                0
#define EMIOS_PWM_IP_INIT_PB_CFG_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Emios_Pwm_Ip_Types header file are of the same vendor */
#if (EMIOS_PWM_IP_INIT_PB_CFG_VENDOR_ID != EMIOS_PWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of Emios_Pwm_Ip_Init_PBcfg.h and Emios_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Emios_Pwm_Ip_Types header file are of the same AUTOSAR version */
#if ((EMIOS_PWM_IP_INIT_PB_CFG_AR_RELEASE_MAJOR_VERSION    != EMIOS_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_INIT_PB_CFG_AR_RELEASE_MINOR_VERSION    != EMIOS_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_PWM_IP_INIT_PB_CFG_AR_RELEASE_REVISION_VERSION != EMIOS_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Emios_Pwm_Ip_Init_PBcfg.h and Emios_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Emios_Pwm_Ip_Types header file are of the same software version */
#if ((EMIOS_PWM_IP_INIT_PB_CFG_SW_MAJOR_VERSION != EMIOS_PWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_INIT_PB_CFG_SW_MINOR_VERSION != EMIOS_PWM_IP_TYPES_SW_MINOR_VERSION) || \
     (EMIOS_PWM_IP_INIT_PB_CFG_SW_PATCH_VERSION != EMIOS_PWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Emios_Pwm_Ip_Init_PBcfg.h and Emios_Pwm_Ip_Types.h are different."
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/
/* Emios instance index for configuration PwmEmios_0/PwmEmiosChannels_0 */
#define EMIOS_PWM_IP_INIT_I0_CH0_CFG      (0U)

/* Macro to enable the mode operations. */
#ifndef EMIOS_PWM_IP_MODE_OPWFMB_USED
#define EMIOS_PWM_IP_MODE_OPWFMB_USED
#endif

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
#ifndef EMIOS_PWM_IP_PRECOMPILE_SUPPORT
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/* Channel configurations for Emios instance 0 */
/* Emios channel 0 configuration */
extern const Emios_Pwm_Ip_ChannelConfigType Emios_Pwm_Ip_Init_I0_Ch0;

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
#endif  /* EMIOS_PWM_IP_PRECOMPILE_SUPPORT */

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EMIOS_PWM_IP_INIT_PBCFG_H */

