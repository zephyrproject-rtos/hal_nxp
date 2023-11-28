/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* Prevention from multiple including the same header */
#ifndef LCU_IP_IRQ_H_
#define LCU_IP_IRQ_H_

/**
*   @file    Lcu_Ip_Irq.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Mcl - Lcu Ip driver header file.
*   @details
*
*   @addtogroup LCU_IP_DRIVER LCU IP Driver
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
#include "Lcu_Ip_Types.h"
#include "Lcu_Ip_Hw_Access.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LCU_IP_IRQ_VENDOR_ID                       43
#define LCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION        4
#define LCU_IP_IRQ_AR_RELEASE_MINOR_VERSION        7
#define LCU_IP_IRQ_AR_RELEASE_REVISION_VERSION     0
#define LCU_IP_IRQ_SW_MAJOR_VERSION                3
#define LCU_IP_IRQ_SW_MINOR_VERSION                0
#define LCU_IP_IRQ_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Lcu_Ip_Types.h file are of the same vendor */
#if (LCU_IP_IRQ_VENDOR_ID != LCU_IP_TYPES_VENDOR_ID)
    #error "Lcu_Ip_Irq.h and Lcu_Ip_Types.h have different vendor ids"
#endif

/* Check if header file and Lcu_Ip_Types.h file are of the same Autosar version */
#if ((LCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION != LCU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_IRQ_AR_RELEASE_MINOR_VERSION != LCU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_IRQ_AR_RELEASE_REVISION_VERSION != LCU_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip_Irq.h and Lcu_Ip_Types.h are different"
#endif

/* Check if header file and Lcu_Ip_Types.h file are of the same Software version */
#if ((LCU_IP_IRQ_SW_MAJOR_VERSION != LCU_IP_TYPES_SW_MAJOR_VERSION) || \
     (LCU_IP_IRQ_SW_MINOR_VERSION != LCU_IP_TYPES_SW_MINOR_VERSION) || \
     (LCU_IP_IRQ_SW_PATCH_VERSION != LCU_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip_Irq.h and Lcu_Ip_Types.h are different"
#endif

/* Check if header file and Lcu_Ip_Hw_Access.h file are of the same vendor */
#if (LCU_IP_IRQ_VENDOR_ID != LCU_IP_HW_ACCESS_VENDOR_ID)
    #error "Lcu_Ip_Irq.h and Lcu_Ip_Hw_Access.h have different vendor ids"
#endif

/* Check if header file and Lcu_Ip_Hw_Access.h file are of the same Autosar version */
#if ((LCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION != LCU_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_IRQ_AR_RELEASE_MINOR_VERSION != LCU_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_IRQ_AR_RELEASE_REVISION_VERSION != LCU_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip_Irq.h and Lcu_Ip_Hw_Access.h are different"
#endif

/* Check if header file and Lcu_Ip_Hw_Access.h file are of the same Software version */
#if ((LCU_IP_IRQ_SW_MAJOR_VERSION != LCU_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     (LCU_IP_IRQ_SW_MINOR_VERSION != LCU_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     (LCU_IP_IRQ_SW_PATCH_VERSION != LCU_IP_HW_ACCESS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip_Irq.h and Lcu_Ip_Hw_Access.h are different"
#endif

#if (STD_ON == LCU_IP_IS_AVAILABLE)
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
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

void Lcu_Ip_IrqHandler(const uint8 HwInstance, const uint8 HwLogicCell, const uint8 HwOutput, const Lcu_Ip_Event Event);

void Lcu_IrqHandler(const uint8 HwInstance);

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#endif /* #if (STD_ON == LCU_IP_IS_AVAILABLE) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef LCU_IP_IRQ_H_ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
