/*
 * Copyright 2022 NXP
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

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

void Canexcel_Ip_RxTxIRQHandler(uint8 instance);
void Canexcel_Ip_ErrIRQHandler(uint8 instance);

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CANEXCEL_IP_IRQ_H_ */
