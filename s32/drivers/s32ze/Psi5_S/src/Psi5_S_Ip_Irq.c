/*
 * Copyright 2021-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file Psi5_S_Ip_Irq.c
*
*   @addtogroup PSI5_S_IP PSI5 IPV Driver
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
#include "Psi5_S_Ip.h"
#include "Psi5_S_Ip_Irq.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PSI5_S_IP_IRQ_VENDOR_ID_C                        43
#define PSI5_S_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C         4
#define PSI5_S_IP_IRQ_AR_RELEASE_MINOR_VERSION_C         7
#define PSI5_S_IP_IRQ_AR_RELEASE_REVISION_VERSION_C      0
#define PSI5_S_IP_IRQ_SW_MAJOR_VERSION_C                 2
#define PSI5_S_IP_IRQ_SW_MINOR_VERSION_C                 0
#define PSI5_S_IP_IRQ_SW_PATCH_VERSION_C                 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Checks against Psi5_S_Ip.h */
#if (PSI5_S_IP_IRQ_VENDOR_ID_C != PSI5_S_IP_VENDOR_ID)
    #error "Psi5_S_Ip_Irq.c and Psi5_S_Ip.h have different vendor ids"
#endif
#if ((PSI5_S_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != PSI5_S_IP_AR_RELEASE_MAJOR_VERSION) || \
     (PSI5_S_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != PSI5_S_IP_AR_RELEASE_MINOR_VERSION) || \
     (PSI5_S_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != PSI5_S_IP_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Psi5_S_Ip_Irq.c and Psi5_S_Ip.h are different"
#endif
#if ((PSI5_S_IP_IRQ_SW_MAJOR_VERSION_C != PSI5_S_IP_SW_MAJOR_VERSION) || \
     (PSI5_S_IP_IRQ_SW_MINOR_VERSION_C != PSI5_S_IP_SW_MINOR_VERSION) || \
     (PSI5_S_IP_IRQ_SW_PATCH_VERSION_C != PSI5_S_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Psi5_S_Ip_Irq.c and Psi5_S_Ip.h are different"
#endif

/* Checks against Psi5_S_Ip_Irq.h */
#if (PSI5_S_IP_IRQ_VENDOR_ID_C != PSI5_S_IP_IRQ_VENDOR_ID)
    #error "Psi5_S_Ip_Irq.c and Psi5_S_Ip_Irq.h have different vendor ids"
#endif
#if ((PSI5_S_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != PSI5_S_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (PSI5_S_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != PSI5_S_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (PSI5_S_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != PSI5_S_IP_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Psi5_S_Ip_Irq.c and Psi5_S_Ip_Irq.h are different"
#endif
#if ((PSI5_S_IP_IRQ_SW_MAJOR_VERSION_C != PSI5_S_IP_IRQ_SW_MAJOR_VERSION) || \
     (PSI5_S_IP_IRQ_SW_MINOR_VERSION_C != PSI5_S_IP_IRQ_SW_MINOR_VERSION) || \
     (PSI5_S_IP_IRQ_SW_PATCH_VERSION_C != PSI5_S_IP_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Psi5_S_Ip_Irq.c and Psi5_S_Ip_Irq.h are different"
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

#ifdef PSI5_S_IP_ENABLE_GLOBAL_INTERRUPTS_PSI5_S_INSTANCE0
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_IRQ_Global_Handle_0
 * Description   : Must be mapped to the generic interrupt of global.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Global_Handle_PSI5S_0)
{
    Psi5_S_Ip_IRQ_Global_Handler((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE0);
}
#endif

#ifdef PSI5_S_IP_ENABLE_INTERRUPTS_PSI5_S_0_CH0
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Rx_PSI5S_0_CH0
 * Description   : Must be mapped to the generic interrupt of instance 0 channel 0.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Rx_PSI5S_0_CH0)
{
    Psi5_S_Ip_IRQ_Handler_Rx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE0, (Psi5_S_Ip_HwChannelIdType)PSI5_S_0_CH0);
}
#endif

#ifdef PSI5_S_IP_ENABLE_INTERRUPTS_PSI5_S_0_CH1
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Rx_PSI5S_0_CH1
 * Description   : Must be mapped to the generic interrupt of instance 0 channel 1.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Rx_PSI5S_0_CH1)
{
    Psi5_S_Ip_IRQ_Handler_Rx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE0, (Psi5_S_Ip_HwChannelIdType)PSI5_S_0_CH1);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Tx_PSI5S_0_CH1
 * Description   : Must be mapped to the generic interrupt of instance 0 channel 1.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Tx_PSI5S_0_CH1)
{
    Psi5_S_Ip_IRQ_Handler_Tx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE0, PSI5_S_0_CH1);
}
#endif

#ifdef PSI5_S_IP_ENABLE_INTERRUPTS_PSI5_S_0_CH2
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Rx_PSI5S_0_CH2
 * Description   : Must be mapped to the generic interrupt of instance 0 channel 2.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Rx_PSI5S_0_CH2)
{
    Psi5_S_Ip_IRQ_Handler_Rx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE0, (Psi5_S_Ip_HwChannelIdType)PSI5_S_0_CH2);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Tx_PSI5S_0_CH2
 * Description   : Must be mapped to the generic interrupt of instance 0 channel 2.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Tx_PSI5S_0_CH2)
{
    Psi5_S_Ip_IRQ_Handler_Tx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE0, (Psi5_S_Ip_HwChannelIdType)PSI5_S_0_CH2);
}
#endif

#ifdef PSI5_S_IP_ENABLE_INTERRUPTS_PSI5_S_0_CH3
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Rx_PSI5S_0_CH3
 * Description   : Must be mapped to the generic interrupt of instance 0 channel 3.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Rx_PSI5S_0_CH3)
{
    Psi5_S_Ip_IRQ_Handler_Rx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE0, (Psi5_S_Ip_HwChannelIdType)PSI5_S_0_CH3);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Tx_PSI5S_0_CH3
 * Description   : Must be mapped to the generic interrupt of instance 0 channel 3.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Tx_PSI5S_0_CH3)
{
    Psi5_S_Ip_IRQ_Handler_Tx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE0, (Psi5_S_Ip_HwChannelIdType)PSI5_S_0_CH3);
}
#endif

#ifdef PSI5_S_IP_ENABLE_INTERRUPTS_PSI5_S_0_CH4
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Rx_PSI5S_0_CH4
 * Description   : Must be mapped to the generic interrupt of instance 0 channel 4.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Rx_PSI5S_0_CH4)
{
    Psi5_S_Ip_IRQ_Handler_Rx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE0, (Psi5_S_Ip_HwChannelIdType)PSI5_S_0_CH4);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Tx_PSI5S_0_CH4
 * Description   : Must be mapped to the generic interrupt of instance 0 channel 4.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Tx_PSI5S_0_CH4)
{
    Psi5_S_Ip_IRQ_Handler_Tx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE0, (Psi5_S_Ip_HwChannelIdType)PSI5_S_0_CH4);
}
#endif

#ifdef PSI5_S_IP_ENABLE_INTERRUPTS_PSI5_S_0_CH5
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Rx_PSI5S_0_CH5
 * Description   : Must be mapped to the generic interrupt of instance 0 channel 5.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Rx_PSI5S_0_CH5)
{
    Psi5_S_Ip_IRQ_Handler_Rx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE0, (Psi5_S_Ip_HwChannelIdType)PSI5_S_0_CH5);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Tx_PSI5S_0_CH5
 * Description   : Must be mapped to the generic interrupt of instance 0 channel 5.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Tx_PSI5S_0_CH5)
{
    Psi5_S_Ip_IRQ_Handler_Tx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE0, (Psi5_S_Ip_HwChannelIdType)PSI5_S_0_CH5);
}
#endif

#ifdef PSI5_S_IP_ENABLE_INTERRUPTS_PSI5_S_0_CH6
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Rx_PSI5S_0_CH6
 * Description   : Must be mapped to the generic interrupt of instance 0 channel 6.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Rx_PSI5S_0_CH6)
{
    Psi5_S_Ip_IRQ_Handler_Rx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE0, (Psi5_S_Ip_HwChannelIdType)PSI5_S_0_CH6);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Tx_PSI5S_0_CH6
 * Description   : Must be mapped to the generic interrupt of instance 0 channel 6.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Tx_PSI5S_0_CH6)
{
    Psi5_S_Ip_IRQ_Handler_Tx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE0, (Psi5_S_Ip_HwChannelIdType)PSI5_S_0_CH6);
}
#endif

#ifdef PSI5_S_IP_ENABLE_INTERRUPTS_PSI5_S_0_CH7
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Rx_PSI5S_0_CH7
 * Description   : Must be mapped to the generic interrupt of instance 0 channel 7.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Rx_PSI5S_0_CH7)
{
    Psi5_S_Ip_IRQ_Handler_Rx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE0, (Psi5_S_Ip_HwChannelIdType)PSI5_S_0_CH7);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Tx_PSI5S_0_CH7
 * Description   : Must be mapped to the generic interrupt of instance 0 channel 7.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Tx_PSI5S_0_CH7)
{
    Psi5_S_Ip_IRQ_Handler_Tx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE0, (Psi5_S_Ip_HwChannelIdType)PSI5_S_0_CH7);
}
#endif

#ifdef PSI5_S_IP_ENABLE_GLOBAL_INTERRUPTS_PSI5_S_INSTANCE1
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_IRQ_Global_Handle_1
 * Description   : Must be mapped to the generic interrupt of global.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Global_Handle_PSI5S_1)
{
    Psi5_S_Ip_IRQ_Global_Handler((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE1);
}
#endif

#ifdef PSI5_S_IP_ENABLE_INTERRUPTS_PSI5_S_1_CH0
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Rx_PSI5S_1_CH0
 * Description   : Must be mapped to the generic interrupt of instance 1 channel 0.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Rx_PSI5S_1_CH0)
{
    Psi5_S_Ip_IRQ_Handler_Rx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE1, (Psi5_S_Ip_HwChannelIdType)PSI5_S_1_CH0);
}
#endif

#ifdef PSI5_S_IP_ENABLE_INTERRUPTS_PSI5_S_1_CH1
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Rx_PSI5S_1_CH1
 * Description   : Must be mapped to the generic interrupt of instance 1 channel 1.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Rx_PSI5S_1_CH1)
{
    Psi5_S_Ip_IRQ_Handler_Rx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE1, (Psi5_S_Ip_HwChannelIdType)PSI5_S_1_CH1);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Tx_PSI5S_1_CH1
 * Description   : Must be mapped to the generic interrupt of instance 1 channel 1.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Tx_PSI5S_1_CH1)
{
    Psi5_S_Ip_IRQ_Handler_Tx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE1, (Psi5_S_Ip_HwChannelIdType)PSI5_S_1_CH1);
}
#endif

#ifdef PSI5_S_IP_ENABLE_INTERRUPTS_PSI5_S_1_CH2
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Rx_PSI5S_1_CH2
 * Description   : Must be mapped to the generic interrupt of instance 1 channel 2.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Rx_PSI5S_1_CH2)
{
    Psi5_S_Ip_IRQ_Handler_Rx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE1, (Psi5_S_Ip_HwChannelIdType)PSI5_S_1_CH2);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Tx_PSI5S_1_CH2
 * Description   : Must be mapped to the generic interrupt of instance 1 channel 2.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Tx_PSI5S_1_CH2)
{
    Psi5_S_Ip_IRQ_Handler_Tx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE1, (Psi5_S_Ip_HwChannelIdType)PSI5_S_1_CH2);
}
#endif

#ifdef PSI5_S_IP_ENABLE_INTERRUPTS_PSI5_S_1_CH3
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Rx_PSI5S_1_CH3
 * Description   : Must be mapped to the generic interrupt of instance 1 channel 3.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Rx_PSI5S_1_CH3)
{
    Psi5_S_Ip_IRQ_Handler_Rx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE1, (Psi5_S_Ip_HwChannelIdType)PSI5_S_1_CH2);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Tx_PSI5S_1_CH3
 * Description   : Must be mapped to the generic interrupt of instance 1 channel 3.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Tx_PSI5S_1_CH3)
{
    Psi5_S_Ip_IRQ_Handler_Tx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE1, (Psi5_S_Ip_HwChannelIdType)PSI5_S_1_CH2);
}
#endif

#ifdef PSI5_S_IP_ENABLE_INTERRUPTS_PSI5_S_1_CH4
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Rx_PSI5S_1_CH4
 * Description   : Must be mapped to the generic interrupt of instance 1 channel 4.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Rx_PSI5S_1_CH4)
{
    Psi5_S_Ip_IRQ_Handler_Rx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE1, (Psi5_S_Ip_HwChannelIdType)PSI5_S_1_CH4);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Tx_PSI5S_1_CH4
 * Description   : Must be mapped to the generic interrupt of instance 1 channel 4.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Tx_PSI5S_1_CH4)
{
    Psi5_S_Ip_IRQ_Handler_Tx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE1, (Psi5_S_Ip_HwChannelIdType)PSI5_S_1_CH4);
}
#endif

#ifdef PSI5_S_IP_ENABLE_INTERRUPTS_PSI5_S_1_CH5
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Rx_PSI5S_1_CH5
 * Description   : Must be mapped to the generic interrupt of instance 1 channel 5.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Rx_PSI5S_1_CH5)
{
    Psi5_S_Ip_IRQ_Handler_Rx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE1, (Psi5_S_Ip_HwChannelIdType)PSI5_S_1_CH5);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Tx_PSI5S_1_CH5
 * Description   : Must be mapped to the generic interrupt of instance 1 channel 5.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Tx_PSI5S_1_CH5)
{
    Psi5_S_Ip_IRQ_Handler_Tx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE1, (Psi5_S_Ip_HwChannelIdType)PSI5_S_1_CH5);
}
#endif

#ifdef PSI5_S_IP_ENABLE_INTERRUPTS_PSI5_S_1_CH6
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Rx_PSI5S_1_CH6
 * Description   : Must be mapped to the generic interrupt of instance 1 channel 6.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Rx_PSI5S_1_CH6)
{
    Psi5_S_Ip_IRQ_Handler_Rx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE1, (Psi5_S_Ip_HwChannelIdType)PSI5_S_1_CH6);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Tx_PSI5S_1_CH6
 * Description   : Must be mapped to the generic interrupt of instance 1 channel 6.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Tx_PSI5S_1_CH6)
{
    Psi5_S_Ip_IRQ_Handler_Tx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE1, (Psi5_S_Ip_HwChannelIdType)PSI5_S_1_CH6);
}
#endif

#ifdef PSI5_S_IP_ENABLE_INTERRUPTS_PSI5_S_1_CH7
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Rx_PSI5S_1_CH7
 * Description   : Must be mapped to the generic interrupt of instance 1 channel 7.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Rx_PSI5S_1_CH7)
{
    Psi5_S_Ip_IRQ_Handler_Rx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE1, (Psi5_S_Ip_HwChannelIdType)PSI5_S_1_CH7);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5S_IRQ_Handle_Tx_PSI5S_1_CH7
 * Description   : Must be mapped to the generic interrupt of instance 1 channel 7.
 *END**************************************************************************/
ISR(Psi5S_IRQ_Handle_Tx_PSI5S_1_CH7)
{
    Psi5_S_Ip_IRQ_Handler_Tx((Psi5_S_Ip_InstanceIdType)PSI5_S_INSTANCE1, (Psi5_S_Ip_HwChannelIdType)PSI5_S_1_CH7);
}
#endif

#define PSI5_STOP_SEC_CODE
#include "Psi5_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
