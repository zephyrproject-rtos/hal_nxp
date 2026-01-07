/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * CanEXCEL_Ip_Irq.c
 *
 *  Created on: May 5, 2022
 *      Author: nxf31634
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
#include "CanEXCEL_Ip_HwAccess.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANEXCEL_IP_IRQ_VENDOR_ID_C                      43
#define CANEXCEL_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define CANEXCEL_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       9
#define CANEXCEL_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define CANEXCEL_IP_IRQ_SW_MAJOR_VERSION_C               0
#define CANEXCEL_IP_IRQ_SW_MINOR_VERSION_C               8
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

/* Check if current file and CanEXCEL_Ip_HwAccess.h are of the same vendor */
#if (CANEXCEL_IP_IRQ_VENDOR_ID_C != CANEXCEL_IP_HWACCESS_VENDOR_ID_H)
    #error "CanEXCEL_Ip_Irq.c and CanEXCEL_Ip_HwAccess.h have different vendor ids"
#endif
/* Check if current file and CanEXCEL_Ip_HwAccess.h are of the same Autosar version */
#if ((CANEXCEL_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != CANEXCEL_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_H) || \
     (CANEXCEL_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != CANEXCEL_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_H) || \
     (CANEXCEL_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != CANEXCEL_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_H) \
)
    #error "AutoSar Version Numbers of CanEXCEL_Ip_Irq.c and CanEXCEL_Ip_HwAccess.h are different"
#endif
/* Check if current file and CanEXCEL_Ip_HwAccess.h are of the same Software version */
#if ((CANEXCEL_IP_IRQ_SW_MAJOR_VERSION_C != CANEXCEL_IP_HWACCESS_SW_MAJOR_VERSION_H) || \
     (CANEXCEL_IP_IRQ_SW_MINOR_VERSION_C != CANEXCEL_IP_HWACCESS_SW_MINOR_VERSION_H) || \
     (CANEXCEL_IP_IRQ_SW_PATCH_VERSION_C != CANEXCEL_IP_HWACCESS_SW_PATCH_VERSION_H) \
)
    #error "Software Version Numbers of CanEXCEL_Ip_Irq.c and CanEXCEL_Ip_HwAccess.h are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#define CAN_43_CANEXCEL_START_SEC_CODE
#include "Can_43_CANEXCEL_MemMap.h"

#ifndef IP_CANXL_0__MRU
#define IP_CANXL_0__MRU IP_CANEXCEL__MRU
#endif

/* Implementation of CANEXCEL0 handler for Rx\Tx and RxFIFO and MRU */
ISR(CANXL0_RX_TX_DATA_IRQHandler)
{
    Canexcel_Ip_RxTxIRQHandler(0U);

    Canexcel_Ip_MruSpuriousIRQHandler(0u);

#if (CANEXCEL_IP_HAS_DEDICATED_COM_ERR_EVT == STD_OFF)
    Canexcel_Ip_ErrIRQHandler(0U);
#endif
}

#if (CANEXCEL_IP_HAS_DEDICATED_COM_ERR_EVT == STD_ON)
/* Implementation of CANEXCEL0 Error Hw Handler*/
ISR(CANXL0_INT_ERROR_IRQHandler)
{
    Canexcel_Ip_ErrIRQHandler(0U);
}
#endif

#if (CANXL_SIC_INSTANCE_COUNT > 1U)
/* Implementation of CANEXCEL1 handler for Rx\Tx and RxFIFO and MRU */
ISR(CANXL1_RX_TX_DATA_IRQHandler)
{
    Canexcel_Ip_RxTxIRQHandler(1U);

    Canexcel_Ip_MruSpuriousIRQHandler(1u);

#if (CANEXCEL_IP_HAS_DEDICATED_COM_ERR_EVT == STD_OFF)
    Canexcel_Ip_ErrIRQHandler(1U);
#endif
}

#if (CANEXCEL_IP_HAS_DEDICATED_COM_ERR_EVT == STD_ON)
/* Implementation of CANEXCEL1 Error Hw Handler*/
ISR(CANXL1_INT_ERROR_IRQHandler)
{
    Canexcel_Ip_ErrIRQHandler(1U);
}
#endif
#endif /* (CANXL_SIC_INSTANCE_COUNT > 1U) */

#if (CANXL_SIC_INSTANCE_COUNT > 2U)
/* Implementation of CANEXCEL1 handler for Rx\Tx and RxFIFO and MRU */
ISR(CANXL2_RX_TX_DATA_IRQHandler)
{
    Canexcel_Ip_RxTxIRQHandler(2U);

    Canexcel_Ip_MruSpuriousIRQHandler(2u);

#if (CANEXCEL_IP_HAS_DEDICATED_COM_ERR_EVT == STD_OFF)
    Canexcel_Ip_ErrIRQHandler(2U);
#endif
}

#if (CANEXCEL_IP_HAS_DEDICATED_COM_ERR_EVT == STD_ON)
/* Implementation of CANEXCEL1 Error Hw Handler*/
ISR(CANXL2_INT_ERROR_IRQHandler)
{
    Canexcel_Ip_ErrIRQHandler(2U);
}
#endif
#endif /* (CANXL_SIC_INSTANCE_COUNT > 2U) */

#if (CANXL_SIC_INSTANCE_COUNT > 3U)
/* Implementation of CANEXCEL1 handler for Rx\Tx and RxFIFO and MRU */
ISR(CANXL3_RX_TX_DATA_IRQHandler)
{
    Canexcel_Ip_RxTxIRQHandler(3U);

    Canexcel_Ip_MruSpuriousIRQHandler(3u);

#if (CANEXCEL_IP_HAS_DEDICATED_COM_ERR_EVT == STD_OFF)
    Canexcel_Ip_ErrIRQHandler(3U);
#endif
}

#if (CANEXCEL_IP_HAS_DEDICATED_COM_ERR_EVT == STD_ON)
/* Implementation of CANEXCEL1 Error Hw Handler*/
ISR(CANXL3_INT_ERROR_IRQHandler)
{
    Canexcel_Ip_ErrIRQHandler(3U);
}
#endif
#endif /* (CANXL_SIC_INSTANCE_COUNT > 3U) */

#define CAN_43_CANEXCEL_STOP_SEC_CODE
#include "Can_43_CANEXCEL_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
