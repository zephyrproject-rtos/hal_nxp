/*
 * Copyright 2022 NXP
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
#include "CanEXCEL_Ip_HwAccess.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

ISR(CANXL0_RX_TX_DATA_IRQHandler);
ISR(CANXL0_INT_ERROR_IRQHandler);
ISR(CANXL0_RX_TX_DATA_IRQHandler)
{
    Canexcel_Ip_RxTxIRQHandler(0U);
}

ISR(CANXL0_INT_ERROR_IRQHandler)
{
    Canexcel_Ip_ErrIRQHandler(0U);
}

#if (CANXL_SIC_INSTANCE_COUNT > 1U)
ISR(CANXL1_RX_TX_DATA_IRQHandler);
ISR(CANXL1_INT_ERROR_IRQHandler);
ISR(CANXL1_RX_TX_DATA_IRQHandler)
{
    Canexcel_Ip_RxTxIRQHandler(1U);
}

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
