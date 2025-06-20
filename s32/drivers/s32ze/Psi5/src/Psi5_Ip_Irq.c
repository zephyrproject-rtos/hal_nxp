/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file Psi5_Ip_Irq.c
*
*   @addtogroup PSI5_IP PSI5 IPV Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Psi5_Ip.h"
#include "Psi5_Ip_Irq.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PSI5_IP_IRQ_VENDOR_ID_C                        43
#define PSI5_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C         4
#define PSI5_IP_IRQ_AR_RELEASE_MINOR_VERSION_C         7
#define PSI5_IP_IRQ_AR_RELEASE_REVISION_VERSION_C      0
#define PSI5_IP_IRQ_SW_MAJOR_VERSION_C                 2
#define PSI5_IP_IRQ_SW_MINOR_VERSION_C                 0
#define PSI5_IP_IRQ_SW_PATCH_VERSION_C                 1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Checks against Psi5_Ip.h */
#if (PSI5_IP_IRQ_VENDOR_ID_C != PSI5_IP_VENDOR_ID)
    #error "Psi5_Ip_Irq.c and Psi5_Ip.h have different vendor ids"
#endif
#if ((PSI5_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != PSI5_IP_AR_RELEASE_MAJOR_VERSION) || \
     (PSI5_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != PSI5_IP_AR_RELEASE_MINOR_VERSION) || \
     (PSI5_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != PSI5_IP_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Psi5_Ip_Irq.c and Psi5_Ip.h are different"
#endif
#if ((PSI5_IP_IRQ_SW_MAJOR_VERSION_C != PSI5_IP_SW_MAJOR_VERSION) || \
     (PSI5_IP_IRQ_SW_MINOR_VERSION_C != PSI5_IP_SW_MINOR_VERSION) || \
     (PSI5_IP_IRQ_SW_PATCH_VERSION_C != PSI5_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Psi5_Ip_Irq.c and Psi5_Ip.h are different"
#endif

/* Checks against Psi5_Ip_Irq.h */
#if (PSI5_IP_IRQ_VENDOR_ID_C != PSI5_IP_IRQ_VENDOR_ID)
    #error "Psi5_Ip_Irq.c and Psi5_Ip_Irq.h have different vendor ids"
#endif
#if ((PSI5_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != PSI5_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (PSI5_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != PSI5_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (PSI5_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != PSI5_IP_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Psi5_Ip_Irq.c and Psi5_Ip_Irq.h are different"
#endif
#if ((PSI5_IP_IRQ_SW_MAJOR_VERSION_C != PSI5_IP_IRQ_SW_MAJOR_VERSION) || \
     (PSI5_IP_IRQ_SW_MINOR_VERSION_C != PSI5_IP_IRQ_SW_MINOR_VERSION) || \
     (PSI5_IP_IRQ_SW_PATCH_VERSION_C != PSI5_IP_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Psi5_Ip_Irq.c and Psi5_Ip_Irq.h are different"
#endif

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

#define PSI5_START_SEC_CODE
#include "Psi5_MemMap.h"

#ifdef PSI5_IP_ENABLE_INTERRUPTS_PSI5_0_CH0
/**
 *
 * Function Name : Psi5_IRQ_Handle_PSI5_0_CH0
 * Description   : Must be mapped to the generic interrupt of instace 0 channel 0.
 */
ISR(Psi5_IRQ_Handle_PSI5_0_CH0)
{
    Psi5_Ip_IRQ_Handler(PSI5_INSTANCE0, PSI5_0_CH0);
}
#endif

#ifdef PSI5_IP_ENABLE_INTERRUPTS_PSI5_0_CH1
/**
 *
 * Function Name : Psi5_IRQ_Handle_PSI5_0_CH0
 * Description   : Must be mapped to the generic interrupt of instace 0 channel 1.
 */
ISR(Psi5_IRQ_Handle_PSI5_0_CH1)
{
    Psi5_Ip_IRQ_Handler(PSI5_INSTANCE0, PSI5_0_CH1);
}
#endif

#ifdef PSI5_IP_ENABLE_INTERRUPTS_PSI5_0_CH2
/**
 *
 * Function Name : Psi5_IRQ_Handle_PSI5_0_CH0
 * Description   : Must be mapped to the generic interrupt of instace 0 channel 2.
 */
ISR(Psi5_IRQ_Handle_PSI5_0_CH2)
{
    Psi5_Ip_IRQ_Handler(PSI5_INSTANCE0, PSI5_0_CH2);
}
#endif

#ifdef PSI5_IP_ENABLE_INTERRUPTS_PSI5_0_CH3
/**
 *
 * Function Name : Psi5_IRQ_Handle_PSI5_0_CH0
 * Description   : Must be mapped to the generic interrupt of instace 0 channel 3.
 */
ISR(Psi5_IRQ_Handle_PSI5_0_CH3)
{
    Psi5_Ip_IRQ_Handler(PSI5_INSTANCE0, PSI5_0_CH3);
}
#endif

#ifdef PSI5_IP_ENABLE_INTERRUPTS_PSI5_1_CH0
/**
 *
 * Function Name : Psi5_IRQ_Handle_PSI5_1_CH0
 * Description   : Must be mapped to the generic interrupt of instace 1 channel 0.
 */
ISR(Psi5_IRQ_Handle_PSI5_1_CH0)
{
    Psi5_Ip_IRQ_Handler(PSI5_INSTANCE1, PSI5_1_CH0);
}
#endif

#ifdef PSI5_IP_ENABLE_INTERRUPTS_PSI5_1_CH1
/**
 *
 * Function Name : Psi5_IRQ_Handle_PSI5_1_CH0
 * Description   : Must be mapped to the generic interrupt of instace 1 channel 1.
 */
ISR(Psi5_IRQ_Handle_PSI5_1_CH1)
{
    Psi5_Ip_IRQ_Handler(PSI5_INSTANCE1, PSI5_1_CH1);
}
#endif

#ifdef PSI5_IP_ENABLE_INTERRUPTS_PSI5_1_CH2
/**
 *
 * Function Name : Psi5_IRQ_Handle_PSI5_1_CH0
 * Description   : Must be mapped to the generic interrupt of instace 1 channel 2.
 */
ISR(Psi5_IRQ_Handle_PSI5_1_CH2)
{
    Psi5_Ip_IRQ_Handler(PSI5_INSTANCE1, PSI5_1_CH2);
}
#endif

#ifdef PSI5_IP_ENABLE_INTERRUPTS_PSI5_1_CH3
/**
 *
 * Function Name : Psi5_IRQ_Handle_PSI5_0_CH0
 * Description   : Must be mapped to the generic interrupt of instace 1 channel 3.
 */
ISR(Psi5_IRQ_Handle_PSI5_1_CH3)
{
    Psi5_Ip_IRQ_Handler(PSI5_INSTANCE1, PSI5_1_CH3);
}
#endif

#define PSI5_STOP_SEC_CODE
#include "Psi5_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
