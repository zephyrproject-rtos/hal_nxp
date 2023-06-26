/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_PWM_IP_IRQ_H
#define EMIOS_PWM_IP_IRQ_H

/**
*   @file       Emios_Pwm_Ip_Irq.h
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
#include "Std_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_PWM_IP_IRQ_VENDOR_ID                    43
#define EMIOS_PWM_IP_IRQ_MODULE_ID                    121
#define EMIOS_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION     4
#define EMIOS_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION     7
#define EMIOS_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION  0
#define EMIOS_PWM_IP_IRQ_SW_MAJOR_VERSION             3
#define EMIOS_PWM_IP_IRQ_SW_MINOR_VERSION             0
#define EMIOS_PWM_IP_IRQ_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((EMIOS_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Emios_Pwm_Ip_Irq.h and Std_Types.h are different"
    #endif
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
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/**
* @brief          Interrupt handler for Emios Pwm channels.
* @details        Interrupt handler that clears the flags and calls the user notification function.
*
* @param[in]      instance    Emios instance id on which the interrupt occured.
* @param[in]      channel     Channell id within the emios instance that triggered the interrupt.
*/
void Emios_Pwm_Ip_IrqHandler(uint8 Instance, uint8 Channel);

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EMIOS_PWM_IP_IRQ_H */
