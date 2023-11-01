/*
 * Copyright 2021-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef MRU_IP_DEVICE_REGISTERS_H_
#define MRU_IP_DEVICE_REGISTERS_H_

/**
*   @file Mru_Ip_DeviceRegisters.h
*
*   @addtogroup MRU_IP_DRIVER Mru Ip Driver
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "StandardTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_MRU_IP_DEVICE_REGISTERS_VENDOR_ID                      43
#define CDD_PLATFORM_MRU_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION       4
#define CDD_PLATFORM_MRU_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION       7
#define CDD_PLATFORM_MRU_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION    0
#define CDD_PLATFORM_MRU_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION               1
#define CDD_PLATFORM_MRU_IP_DEVICE_REGISTERS_SW_MINOR_VERSION               0
#define CDD_PLATFORM_MRU_IP_DEVICE_REGISTERS_SW_PATCH_VERSION               0

/* Mailbox Interrupt Configuration */
#if (defined(S32E2XX) || defined(S32Z2XX))
    #define INTERRUPT_GROUP_0  0x00u
    #define INTERRUPT_GROUP_1  0x01u
#elif defined(S32NZ5X)
    #define INTERRUPT_GROUP_0  0x00u
    #define INTERRUPT_GROUP_1  0x01u
    #define INTERRUPT_GROUP_2  0x02u
    #define INTERRUPT_GROUP_3  0x03u
#endif


#endif /* MRU_IP_DEVICE_REGISTERS_H_ */

/** @} */
