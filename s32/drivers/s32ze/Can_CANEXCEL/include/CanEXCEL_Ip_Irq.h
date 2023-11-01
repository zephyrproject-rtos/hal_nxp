/*
 * Copyright 2021-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CANEXCEL_IP_IRQ_H_
#define CANEXCEL_IP_IRQ_H_

/**
*   @file CanEXCEL_Ip_Irq.h
*
*   @addtogroup CanEXCEL
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
#include "CanEXCEL_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANEXCEL_IP_IRQ_VENDOR_ID_H                      43
#define CANEXCEL_IP_IRQ_AR_RELEASE_MAJOR_VERSION_H       4
#define CANEXCEL_IP_IRQ_AR_RELEASE_MINOR_VERSION_H       7
#define CANEXCEL_IP_IRQ_AR_RELEASE_REVISION_VERSION_H    0
#define CANEXCEL_IP_IRQ_SW_MAJOR_VERSION_H               1
#define CANEXCEL_IP_IRQ_SW_MINOR_VERSION_H               0
#define CANEXCEL_IP_IRQ_SW_PATCH_VERSION_H               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CanEXCEL_Ip.h are of the same vendor */
#if (CANEXCEL_IP_IRQ_VENDOR_ID_H != CANEXCEL_IP_VENDOR_ID_H)
    #error "CanEXCEL_Ip_Irq.h and CanEXCEL_Ip.h have different vendor ids"
#endif
/* Check if current file and CanEXCEL_Ip.h are of the same Autosar version */
#if ((CANEXCEL_IP_IRQ_AR_RELEASE_MAJOR_VERSION_H    != CANEXCEL_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (CANEXCEL_IP_IRQ_AR_RELEASE_MINOR_VERSION_H    != CANEXCEL_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (CANEXCEL_IP_IRQ_AR_RELEASE_REVISION_VERSION_H != CANEXCEL_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of CanEXCEL_Ip_Irq.h and CanEXCEL_Ip.h are different"
#endif
/* Check if current file and CanEXCEL_Ip_Cfg.h are of the same Software version */
#if ((CANEXCEL_IP_IRQ_SW_MAJOR_VERSION_H != CANEXCEL_IP_SW_MAJOR_VERSION_H) || \
     (CANEXCEL_IP_IRQ_SW_MINOR_VERSION_H != CANEXCEL_IP_SW_MINOR_VERSION_H) || \
     (CANEXCEL_IP_IRQ_SW_PATCH_VERSION_H != CANEXCEL_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of CanEXCEL_Ip_Irq.h and CanEXCEL_Ip.h are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

void Canexcel_Ip_RxTxIRQHandler(uint8 instance);
void Canexcel_Ip_MruIRQHandler(uint8 instance);
void Canexcel_Ip_ErrIRQHandler(uint8 instance);

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CANEXCEL_IP_IRQ_H_ */
