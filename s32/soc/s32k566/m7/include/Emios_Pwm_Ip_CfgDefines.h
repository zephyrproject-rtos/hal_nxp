/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_PWM_IP_CFGDEFINES_H
#define EMIOS_PWM_IP_CFGDEFINES_H

/**
*   @file       EMIOS_Pwm_Ip_CfgDefines.h
*
*   @addtogroup emios_pwm_ip EMIOS Pwm IPL
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
/* Standard Types */
#include "Std_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_PWM_IP_CFGDEFINES_VENDOR_ID                    43
#define EMIOS_PWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION     4
#define EMIOS_PWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION     9
#define EMIOS_PWM_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION  0
#define EMIOS_PWM_IP_CFGDEFINES_SW_MAJOR_VERSION             0
#define EMIOS_PWM_IP_CFGDEFINES_SW_MINOR_VERSION             8
#define EMIOS_PWM_IP_CFGDEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h are of the same AUTOSAR version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((EMIOS_PWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_PWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of EMIOS_Pwm_Ip_CfgDefines.h and Std_Types.h are different."
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/** @brief        Macros to indicate timer width */
#define EMIOS_PWM_IP_TIMER_WIDTH_24BITS

/**
* @brief        Macro to indicate that PWM driver can support call IP layer directly or must be using HLD (Autosar mode).
* @note         In current implementation, this macro is defined equal to STD_ON if EB tresos
*               tool is used, because EB tresos only supports Autosar mode.
*               If CT tool is used, this mean PWM driver can support call IP layer directly or
*               using HLD layer, so this macro can be equal to STD_ON/STD_OFF
*/
#define EMIOS_PWM_IP_AUTOSAR_MODE_IS_USED           (STD_OFF)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief       Notification function callback type.
 */
typedef void (* Emios_Pwm_Ip_CallbackType)(void * Param);

/**
 * @brief       Structure for notification
 * @details     The structure used to notification
 */
typedef struct
{
    /** @brief Callback function pointer */
    Emios_Pwm_Ip_CallbackType       CbFunction;
    /** @brief Callback function parameter pointer */
    void                          * CbParameter;
} Emios_Pwm_Ip_NotificationType;

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

#endif /* EMIOS_PWM_IP_CFGDEFINES_H */

