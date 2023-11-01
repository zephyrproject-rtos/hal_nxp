/*
 * Copyright 2021-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file CanEXCEL_Ip_Irq.c
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
#include "CanEXCEL_Ip_Irq.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANEXCEL_IP_IRQ_VENDOR_ID_C                      43
#define CANEXCEL_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define CANEXCEL_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define CANEXCEL_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define CANEXCEL_IP_IRQ_SW_MAJOR_VERSION_C               1
#define CANEXCEL_IP_IRQ_SW_MINOR_VERSION_C               0
#define CANEXCEL_IP_IRQ_SW_PATCH_VERSION_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CanEXCEL_Ip_Irq.h are of the same vendor */
#if (CANEXCEL_IP_IRQ_VENDOR_ID_C != CANEXCEL_IP_IRQ_VENDOR_ID_H)
    #error "CanEXCEL_Ip_Irq.c and CanEXCEL_Ip_Irq.h have different vendor ids"
#endif
/* Check if current file and CanEXCEL_Ip_Irq.h are of the same Autosar version */
#if ((CANEXCEL_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != CANEXCEL_IP_IRQ_AR_RELEASE_MAJOR_VERSION_H) || \
     (CANEXCEL_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != CANEXCEL_IP_IRQ_AR_RELEASE_MINOR_VERSION_H) || \
     (CANEXCEL_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != CANEXCEL_IP_IRQ_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of CanEXCEL_Ip_Irq.c and CanEXCEL_Ip_Irq.h are different"
#endif
/* Check if current file and CanEXCEL_Ip_Irq.h are of the same Software version */
#if ((CANEXCEL_IP_IRQ_SW_MAJOR_VERSION_C != CANEXCEL_IP_IRQ_SW_MAJOR_VERSION_H) || \
     (CANEXCEL_IP_IRQ_SW_MINOR_VERSION_C != CANEXCEL_IP_IRQ_SW_MINOR_VERSION_H) || \
     (CANEXCEL_IP_IRQ_SW_PATCH_VERSION_C != CANEXCEL_IP_IRQ_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of CanEXCEL_Ip_Irq.c and CanEXCEL_Ip_Irq.h are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

ISR(CANXL0_RX_TX_DATA_IRQHandler);
ISR(CANXL0_INT_ERROR_IRQHandler);
/* Implementation of CANEXCEL0 handler for Rx\Tx and RxFIFO and MRU */
ISR(CANXL0_RX_TX_DATA_IRQHandler)
{
    Canexcel_Ip_RxTxIRQHandler(0U);
    if ((IP_CANXL_0__MRU->CHXCONFIG[0u].CH_CFG0 & CANXL_MRU_CH_CFG0_CHE_MASK) == CANXL_MRU_CH_CFG0_CHE_MASK)
    {
        Canexcel_Ip_MruIRQHandler(0U);
    }
}
/* Implementation of CANEXCEL0 Error Hw Handler*/
ISR(CANXL0_INT_ERROR_IRQHandler)
{
    Canexcel_Ip_ErrIRQHandler(0U);
}

#if (CANXL_SIC_INSTANCE_COUNT > 1U)
ISR(CANXL1_RX_TX_DATA_IRQHandler);
ISR(CANXL1_INT_ERROR_IRQHandler);
/* Implementation of CANEXCEL1 handler for Rx\Tx and RxFIFO and MRU */
ISR(CANXL1_RX_TX_DATA_IRQHandler)
{
    Canexcel_Ip_RxTxIRQHandler(1U);
    if ((IP_CANXL_1__MRU->CHXCONFIG[0u].CH_CFG0 & CANXL_MRU_CH_CFG0_CHE_MASK) == CANXL_MRU_CH_CFG0_CHE_MASK)
    {
        Canexcel_Ip_MruIRQHandler(1U);
    }
}
/* Implementation of CANEXCEL1 Error Hw Handler*/
ISR(CANXL1_INT_ERROR_IRQHandler)
{
    Canexcel_Ip_ErrIRQHandler(1U);
}
#endif /* (CANXL_SIC_INSTANCE_COUNT > 1U) */

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
