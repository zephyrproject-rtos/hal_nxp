/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef NETC_ETH_IP_IRQ_H
#define NETC_ETH_IP_IRQ_H

/**
 *   @file Netc_Eth_Ip_Irq.h
 *
 *   @addtogroup NETC_ETH_DRIVER NETC_ETH Driver
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

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define NETC_ETH_IP_IRQ_VENDOR_ID                  43
#define NETC_ETH_IP_IRQ_AR_RELEASE_MAJOR_VERSION     4
#define NETC_ETH_IP_IRQ_AR_RELEASE_MINOR_VERSION     7
#define NETC_ETH_IP_IRQ_AR_RELEASE_REVISION_VERSION  0
#define NETC_ETH_IP_IRQ_SW_MAJOR_VERSION             2
#define NETC_ETH_IP_IRQ_SW_MINOR_VERSION             0
#define NETC_ETH_IP_IRQ_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define ETH_43_NETC_START_SEC_CODE
#include "Eth_43_NETC_MemMap.h"

/** @brief Function used for the interupt messaging from VSI to PSI. */
void Netc_Eth_Ip_MSIX_SIMsgEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize);

/** @brief Function used for the TX interrupt from SI 0. */
void Netc_Eth_Ip_0_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize);

/** @brief Function used for the TX interrupt from SI 1. */
void Netc_Eth_Ip_1_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize);

/** @brief Function used for the TX interrupt from SI 2. */
void Netc_Eth_Ip_2_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize);

/** @brief Function used for the TX interrupt from SI 3. */
void Netc_Eth_Ip_3_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize);

/** @brief Function used for the TX interrupt from SI 4. */
void Netc_Eth_Ip_4_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize);

/** @brief Function used for the TX interrupt from SI 5. */
void Netc_Eth_Ip_5_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize);

/** @brief Function used for the TX interrupt from SI 6. */
void Netc_Eth_Ip_6_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize);

/** @brief Function used for the TX interrupt from SI 7. */
void Netc_Eth_Ip_7_MSIX_TxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize);

/** @brief Function used for the RX interrupt from SI 0. */
void Netc_Eth_Ip_0_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize);

/** @brief Function used for the RX interrupt from SI 1. */
void Netc_Eth_Ip_1_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize);

/** @brief Function used for the RX interrupt from SI 2. */
void Netc_Eth_Ip_2_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize);

/** @brief Function used for the RX interrupt from SI 3. */
void Netc_Eth_Ip_3_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize);

/** @brief Function used for the RX interrupt from SI 4. */
void Netc_Eth_Ip_4_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize);

/** @brief Function used for the RX interrupt from SI 5. */
void Netc_Eth_Ip_5_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize);

/** @brief Function used for the RX interrupt from SI 6. */
void Netc_Eth_Ip_6_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize);

/** @brief Function used for the RX interrupt from SI 7. */
void Netc_Eth_Ip_7_MSIX_RxEvent(uint8 RxChannelId, const uint32 * RxBuffer, uint8 BufferSize);

ISR(Netc_Eth_Ip_ErrorReporting);


#define ETH_43_NETC_STOP_SEC_CODE
#include "Eth_43_NETC_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* NETC_ETH_IP_IRQ_H */
