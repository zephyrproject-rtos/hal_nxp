/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PSI5_IP_IRQ_H
#define PSI5_IP_IRQ_H

#if defined(__cplusplus)
extern "C" {
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Psi5_Ip_Cfg_Defines.h"
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFOPSI5ATION
==================================================================================================*/
#define PSI5_IP_IRQ_VENDOR_ID                      43
#define PSI5_IP_IRQ_AR_RELEASE_MAJOR_VERSION       4
#define PSI5_IP_IRQ_AR_RELEASE_MINOR_VERSION       7
#define PSI5_IP_IRQ_AR_RELEASE_REVISION_VERSION    0
#define PSI5_IP_IRQ_SW_MAJOR_VERSION               2
#define PSI5_IP_IRQ_SW_MINOR_VERSION               0
#define PSI5_IP_IRQ_SW_PATCH_VERSION               1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((PSI5_IP_IRQ_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (PSI5_IP_IRQ_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Psi5_Ip_Irq.h and Mcal.h are different"
    #endif
#endif

/* Checks against Psi5_Ip_Cfg_Defines.h */
#if (PSI5_IP_IRQ_VENDOR_ID != PSI5_IP_CFG_DEFINES_VENDOR_ID)
    #error "Psi5_Ip_Irq.h and Psi5_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if ((PSI5_IP_IRQ_AR_RELEASE_MAJOR_VERSION    != PSI5_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (PSI5_IP_IRQ_AR_RELEASE_MINOR_VERSION    != PSI5_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (PSI5_IP_IRQ_AR_RELEASE_REVISION_VERSION != PSI5_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Psi5_Ip_Irq.h and Psi5_Ip_Cfg_Defines.h are different"
#endif
#if ((PSI5_IP_IRQ_SW_MAJOR_VERSION != PSI5_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (PSI5_IP_IRQ_SW_MINOR_VERSION != PSI5_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (PSI5_IP_IRQ_SW_PATCH_VERSION != PSI5_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Psi5_Ip_Irq.h and Psi5_Ip_Cfg_Defines.h are different"
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

#define PSI5_START_SEC_CODE
#include "Psi5_MemMap.h"

#ifdef PSI5_IP_ENABLE_INTERRUPTS_PSI5_0_CH0
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_IRQ_Handle_PSI5_0_CH0
 * Description   : Must be mapped to the generic interrupt of instace 0 channel 0.
 *END**************************************************************************/
ISR(Psi5_IRQ_Handle_PSI5_0_CH0);
#endif

#ifdef PSI5_IP_ENABLE_INTERRUPTS_PSI5_0_CH1
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_IRQ_Handle_PSI5_0_CH0
 * Description   : Must be mapped to the generic interrupt of instace 0 channel 1.
 *END**************************************************************************/
ISR(Psi5_IRQ_Handle_PSI5_0_CH1);
#endif

#ifdef PSI5_IP_ENABLE_INTERRUPTS_PSI5_0_CH2
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_IRQ_Handle_PSI5_0_CH0
 * Description   : Must be mapped to the generic interrupt of instace 0 channel 2.
 *END**************************************************************************/
ISR(Psi5_IRQ_Handle_PSI5_0_CH2);
#endif

#ifdef PSI5_IP_ENABLE_INTERRUPTS_PSI5_0_CH3
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_IRQ_Handle_PSI5_0_CH0
 * Description   : Must be mapped to the generic interrupt of instace 0 channel 3.
 *END**************************************************************************/
ISR(Psi5_IRQ_Handle_PSI5_0_CH3);
#endif

#ifdef PSI5_IP_ENABLE_INTERRUPTS_PSI5_1_CH0
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_IRQ_Handle_PSI5_1_CH0
 * Description   : Must be mapped to the generic interrupt of instace 1 channel 0.
 *END**************************************************************************/
ISR(Psi5_IRQ_Handle_PSI5_1_CH0);
#endif

#ifdef PSI5_IP_ENABLE_INTERRUPTS_PSI5_1_CH1
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_IRQ_Handle_PSI5_1_CH0
 * Description   : Must be mapped to the generic interrupt of instace 1 channel 1.
 *END**************************************************************************/
ISR(Psi5_IRQ_Handle_PSI5_1_CH1);
#endif

#ifdef PSI5_IP_ENABLE_INTERRUPTS_PSI5_1_CH2
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_IRQ_Handle_PSI5_1_CH0
 * Description   : Must be mapped to the generic interrupt of instace 1 channel 2.
 *END**************************************************************************/
ISR(Psi5_IRQ_Handle_PSI5_1_CH2);
#endif

#ifdef PSI5_IP_ENABLE_INTERRUPTS_PSI5_1_CH3
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_IRQ_Handle_PSI5_0_CH0
 * Description   : Must be mapped to the generic interrupt of instace 1 channel 3.
 *END**************************************************************************/
ISR(Psi5_IRQ_Handle_PSI5_1_CH3);
#endif

#define PSI5_STOP_SEC_CODE
#include "Psi5_MemMap.h"

#if defined(__cplusplus)
}
#endif

/*! @}*/

/*! @}*/ /* End of addtogroup psi5 */

#endif /* PSI5_IP_H */
