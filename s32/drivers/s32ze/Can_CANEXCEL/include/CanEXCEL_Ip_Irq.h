/*
 * Copyright 2021-2025 NXP
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
#define CANEXCEL_IP_IRQ_SW_MAJOR_VERSION_H               2
#define CANEXCEL_IP_IRQ_SW_MINOR_VERSION_H               0
#define CANEXCEL_IP_IRQ_SW_PATCH_VERSION_H               1
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

#define CAN_43_CANEXCEL_START_SEC_CODE
#include "Can_43_CANEXCEL_MemMap.h"
ISR(CANXL0_RX_TX_DATA_IRQHandler);
ISR(CANXL0_INT_ERROR_IRQHandler);

#if (CANXL_SIC_INSTANCE_COUNT > 1U)
ISR(CANXL1_RX_TX_DATA_IRQHandler);
ISR(CANXL1_INT_ERROR_IRQHandler);
#endif /* (CANXL_SIC_INSTANCE_COUNT > 1U) */

#if (CANXL_SIC_INSTANCE_COUNT > 2U)
ISR(CANXL2_RX_TX_DATA_IRQHandler);
ISR(CANXL2_INT_ERROR_IRQHandler);
#endif /* (CANXL_SIC_INSTANCE_COUNT > 2U) */

#if (CANXL_SIC_INSTANCE_COUNT > 3U)
ISR(CANXL3_RX_TX_DATA_IRQHandler);
ISR(CANXL3_INT_ERROR_IRQHandler);
#endif /* (CANXL_SIC_INSTANCE_COUNT > 3U) */


#define CAN_43_CANEXCEL_STOP_SEC_CODE
#include "Can_43_CANEXCEL_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CANEXCEL_IP_IRQ_H_ */
