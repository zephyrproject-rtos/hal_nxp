/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _S32K344_GLUE_MCUX_H_
#define _S32K344_GLUE_MCUX_H_

#include "S32K344_device.h"

/* LPUART - Peripheral instance base addresses */
/** Peripheral LPUART_0 base address */
#define LPUART0_BASE                         IP_LPUART_0_BASE
/** Peripheral LPUART_0 base pointer */
#define LPUART0                              IP_LPUART_0
/** Peripheral LPUART_1 base address */
#define LPUART1_BASE                         IP_LPUART_1_BASE
/** Peripheral LPUART_1 base pointer */
#define LPUART1                              IP_LPUART_1
/** Peripheral LPUART_2 base address */
#define LPUART2_BASE                         IP_LPUART_2_BASE
/** Peripheral LPUART_2 base pointer */
#define LPUART2                              IP_LPUART_2
/** Peripheral LPUART_3 base address */
#define LPUART3_BASE                         IP_LPUART_3_BASE
/** Peripheral LPUART_3 base pointer */
#define LPUART3                              IP_LPUART_3
/** Peripheral LPUART_4 base address */
#define LPUART4_BASE                         IP_LPUART_4_BASE
/** Peripheral LPUART_4 base pointer */
#define LPUART4                              IP_LPUART_4
/** Peripheral LPUART_5 base address */
#define LPUART5_BASE                         IP_LPUART_5_BASE
/** Peripheral LPUART_5 base pointer */
#define LPUART5                              IP_LPUART_5
/** Peripheral LPUART_6 base address */
#define LPUART6_BASE                         IP_LPUART_6_BASE
/** Peripheral LPUART_6 base pointer */
#define LPUART6                              IP_LPUART_6
/** Peripheral LPUART_7 base address */
#define LPUART7_BASE                         IP_LPUART_7_BASE
/** Peripheral LPUART_7 base pointer */
#define LPUART7                              IP_LPUART_7
/** Peripheral LPUART_8 base address */
#define LPUART8_BASE                         IP_LPUART_8_BASE
/** Peripheral LPUART_8 base pointer */
#define LPUART8                              IP_LPUART_8
/** Peripheral LPUART_9 base address */
#define LPUART9_BASE                         IP_LPUART_9_BASE
/** Peripheral LPUART_9 base pointer */
#define LPUART9                              IP_LPUART_9
/** Peripheral LPUART_10 base address */
#define LPUART10_BASE                        IP_LPUART_10_BASE
/** Peripheral LPUART_10 base pointer */
#define LPUART10                             IP_LPUART_10
/** Peripheral LPUART_11 base address */
#define LPUART11_BASE                        IP_LPUART_11_BASE
/** Peripheral LPUART_11 base pointer */
#define LPUART11                             IP_LPUART_11
/** Peripheral LPUART_12 base address */
#define LPUART12_BASE                        IP_LPUART_12_BASE
/** Peripheral LPUART_12 base pointer */
#define LPUART12                             IP_LPUART_12
/** Peripheral LPUART_13 base address */
#define LPUART13_BASE                        IP_LPUART_13_BASE
/** Peripheral LPUART_13 base pointer */
#define LPUART13                             IP_LPUART_13
/** Peripheral LPUART_14 base address */
#define LPUART14_BASE                        IP_LPUART_14_BASE
/** Peripheral LPUART_14 base pointer */
#define LPUART14                             IP_LPUART_14
/** Peripheral LPUART_15 base address */
#define LPUART15_BASE                        IP_LPUART_15_BASE
/** Peripheral LPUART_15 base pointer */
#define LPUART15                             IP_LPUART_15
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                    IP_LPUART_BASE_ADDRS
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                     IP_LPUART_BASE_PTRS
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                    { LPUART0_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn, LPUART4_IRQn, LPUART5_IRQn, LPUART6_IRQn, LPUART7_IRQn, LPUART8_IRQn, LPUART9_IRQn, LPUART10_IRQn, LPUART11_IRQn, LPUART12_IRQn, LPUART13_IRQn, LPUART14_IRQn, LPUART15_IRQn }

/* CAN - Peripheral instance base addresses */
/** Peripheral CAN_0 base address */
#define CAN0_BASE                                IP_CAN_0_BASE
/** Peripheral CAN_0 base pointer */
#define CAN0                                     ((CAN_Type *)CAN0_BASE)
/** Peripheral CAN_1 base address */
#define CAN1_BASE                                IP_CAN_1_BASE
/** Peripheral CAN_1 base pointer */
#define CAN1                                     ((CAN_Type *)CAN1_BASE)
/** Peripheral CAN_2 base address */
#define CAN2_BASE                                IP_CAN_2_BASE
/** Peripheral CAN_2 base pointer */
#define CAN2                                     ((CAN_Type *)CAN2_BASE)
/** Peripheral CAN_3 base address */
#define CAN3_BASE                                IP_CAN_3_BASE
/** Peripheral CAN_3 base pointer */
#define CAN3                                     ((CAN_Type *)CAN3_BASE)
/** Peripheral CAN_4 base address */
#define CAN4_BASE                                IP_CAN_4_BASE
/** Peripheral CAN_4 base pointer */
#define CAN4                                     ((CAN_Type *)CAN4_BASE)
/** Peripheral CAN_5 base address */
#define CAN5_BASE                                IP_CAN_5_BASE
/** Peripheral CAN_5 base pointer */
#define CAN5                                     ((CAN_Type *)CAN5_BASE)
/** Array initializer of CAN peripheral base addresses */
#define CAN_BASE_ADDRS                           { CAN0_BASE, CAN1_BASE, CAN2_BASE, CAN3_BASE, CAN4_BASE, CAN5_BASE }
/** Array initializer of CAN peripheral base pointers */
#define CAN_BASE_PTRS                            { CAN0, CAN1, CAN2, CAN3, CAN4, CAN5 }
/** Interrupt vectors for the CAN peripheral type */
#define CAN_Rx_Warning_IRQS                      { FlexCAN0_0_IRQn, FlexCAN1_0_IRQn, FlexCAN2_0_IRQn, FlexCAN3_0_IRQn, FlexCAN4_0_IRQn, FlexCAN5_0_IRQn}
#define CAN_Tx_Warning_IRQS                      { FlexCAN0_0_IRQn, FlexCAN1_0_IRQn, FlexCAN2_0_IRQn, FlexCAN3_0_IRQn, FlexCAN4_0_IRQn, FlexCAN5_0_IRQn}
#define CAN_Wake_Up_IRQS                         { FlexCAN0_0_IRQn, FlexCAN1_0_IRQn, FlexCAN2_0_IRQn, FlexCAN3_0_IRQn, FlexCAN4_0_IRQn, FlexCAN5_0_IRQn}
#define CAN_Error_IRQS                           { FlexCAN0_0_IRQn, FlexCAN1_0_IRQn, FlexCAN2_0_IRQn, FlexCAN3_0_IRQn, FlexCAN4_0_IRQn, FlexCAN5_0_IRQn}
#define CAN_Bus_Off_IRQS                         { FlexCAN0_0_IRQn, FlexCAN1_0_IRQn, FlexCAN2_0_IRQn, FlexCAN3_0_IRQn, FlexCAN4_0_IRQn, FlexCAN5_0_IRQn}
#define CAN_ORed_Message_buffer_0_31_IRQS        { FlexCAN0_1_IRQn, FlexCAN1_1_IRQn, FlexCAN2_1_IRQn, FlexCAN3_1_IRQn, FlexCAN4_1_IRQn, FlexCAN5_1_IRQn}
#define CAN_ORed_Message_buffer_32_63_IRQS       { FlexCAN0_2_IRQn, FlexCAN1_2_IRQn, FlexCAN2_2_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn}
#define CAN_ORed_Message_buffer_64_95_IRQS       { FlexCAN0_1_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn}
#define CAN_ORed_Message_buffer_IRQS             CAN_ORed_Message_buffer_0_31_IRQS

#endif  /* _S32K344_GLUE_MCUX_H_ */
