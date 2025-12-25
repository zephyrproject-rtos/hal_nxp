/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _S32K566_GLUE_MCUX_H_
#define _S32K566_GLUE_MCUX_H_

#include "S32K566_device.h"

/* LPUART - Peripheral instance base addresses */
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                    IP_LPUART_BASE_ADDRS
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                     IP_LPUART_BASE_PTRS
/** Interrupt vectors for the LPUART peripheral type */
#if defined(CONFIG_CPU_CORTEX_M7)
#define LPUART_RX_TX_IRQS                    { CM7_LPE_LPUART0_INT0_3_IRQn, CM7_LPE_LPUART1_INT0_3_IRQn, CM7_LPE_LPUART2_INT0_3_IRQn,                    \
                                               CM7_LPUART0_INT0_1_IRQn, CM7_LPUART1_INT0_1_IRQn, CM7_LPUART2_INT0_1_IRQn, CM7_LPUART3_INT0_1_IRQn,       \
                                               CM7_LPUART4_INT0_1_IRQn, CM7_LPUART5_INT0_1_IRQn, CM7_LPUART6_INT0_1_IRQn, CM7_LPUART7_INT0_1_IRQn,       \
                                               CM7_LPUART8_INT0_1_IRQn, CM7_LPUART9_INT0_1_IRQn, CM7_LPUART10_INT0_1_IRQn, CM7_LPUART11_INT0_1_IRQn,     \
                                               CM7_LPUART12_INT0_1_IRQn, CM7_LPUART13_INT0_1_IRQn, CM7_LPUART14_INT0_1_IRQn, CM7_LPUART15_INT0_1_IRQn,   \
                                               CM7_LPUART16_INT0_1_IRQn, CM7_LPUART17_INT0_1_IRQn, CM7_LPUART18_INT0_1_IRQn, CM7_LPUART19_INT0_1_IRQn,   \
                                               CM7_LPUART20_INT0_1_IRQn, NotAvail_IRQn                                                                   \
                                            }
#else
#define LPUART_RX_TX_IRQS                    { R52_LPE_LPUART0_INT0_3_IRQn, R52_LPE_LPUART1_INT0_3_IRQn, R52_LPE_LPUART2_INT0_3_IRQn,                    \
                                               R52_LPUART0_INT0_1_IRQn, R52_LPUART1_INT0_1_IRQn, R52_LPUART2_INT0_1_IRQn, R52_LPUART3_INT0_1_IRQn,       \
                                               R52_LPUART4_INT0_1_IRQn, R52_LPUART5_INT0_1_IRQn, R52_LPUART6_INT0_1_IRQn, R52_LPUART7_INT0_1_IRQn,       \
                                               R52_LPUART8_INT0_1_IRQn, R52_LPUART9_INT0_1_IRQn, R52_LPUART10_INT0_1_IRQn, R52_LPUART11_INT0_1_IRQn,     \
                                               R52_LPUART12_INT0_1_IRQn, R52_LPUART13_INT0_1_IRQn, R52_LPUART14_INT0_1_IRQn, R52_LPUART15_INT0_1_IRQn,   \
                                               R52_LPUART16_INT0_1_IRQn, R52_LPUART17_INT0_1_IRQn, R52_LPUART18_INT0_1_IRQn, R52_LPUART19_INT0_1_IRQn,   \
                                               R52_LPUART20_INT0_1_IRQn, NotAvail_IRQn                                                                   \
                                            }
#endif /* CONFIG_CPU_CORTEX_M7 */
/* ----------------------------------------------------------------------------
   -- FTM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTM_Peripheral_Access_Layer FTM Peripheral Access Layer
 * @{
 */

/* FTM - Peripheral instance base addresses */
/** Peripheral FTM0 base address */
#define FTM0_BASE                                IP_LPE_FTM_BASE
/** Peripheral FTM0 base pointer */
#define FTM0                                     IP_LPE_FTM
/** Array initializer of FTM peripheral base addresses */
#define FTM_BASE_ADDRS                           IP_FTM_BASE_ADDRS
/** Array initializer of FTM peripheral base pointers */
#define FTM_BASE_PTRS                            IP_FTM_BASE_PTRS

/*!
 * @}
 */ /* end of group FTM_Peripheral_Access_Layer */
/* LPI2C - Peripheral instance base addresses */

/** Peripheral LPE_LPI2C0 base address */
#define LPE_LPI2C_BASE                           IP_LPE_LPI2C_BASE
/** Peripheral LPE_LPI2C0 base pointer */
#define LPE_LPI2C                                IP_LPE_LPI2C
/** Peripheral LPI2C0 base address */
#define LPI2C0_BASE                              IP_LPI2C_0_BASE
/** Peripheral LPI2C0 base pointer */
#define LPI2C0                                   IP_LPI2C_0
/** Peripheral LPI2C1 base address */
#define LPI2C1_BASE                              IP_LPI2C_1_BASE
/** Peripheral LPI2C1 base pointer */
#define LPI2C1                                   IP_LPI2C_1
/** Peripheral LPI2C2 base address */
#define LPI2C2_BASE                              IP_LPI2C_2_BASE
/** Peripheral LPI2C2 base pointer */
#define LPI2C2                                   IP_LPI2C_2
/** Peripheral LPI2C3 base address */
#define LPI2C3_BASE                              IP_LPI2C_3_BASE
/** Peripheral LPI2C3 base pointer */
#define LPI2C3                                   IP_LPI2C_3
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         IP_LPI2C_BASE_ADDRS
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          IP_LPI2C_BASE_PTRS
/** Interrupt vectors for the LPI2C peripheral type */
#if defined(CONFIG_CPU_CORTEX_M7)
#define LPI2C_IRQS                               { CM7_LPE_LPI2C_INT0_3_IRQn, CM7_LPI2C0_INT0_1_IRQn, CM7_LPI2C1_INT0_1_IRQn, CM7_LPI2C2_INT0_1_IRQn, CM7_LPI2C3_INT0_1_IRQn }
#else
#define LPI2C_IRQS                               { R52_LPE_LPI2C_INT0_3_IRQn, R52_LPI2C0_INT0_1_IRQn, R52_LPI2C1_INT0_1_IRQn, R52_LPI2C2_INT0_1_IRQn, R52_LPI2C3_INT0_1_IRQn }
#endif /* CONFIG_CPU_CORTEX_M7 */

/* CAN - Peripheral instance base addresses */
/** Peripheral CAN_0 base address */
#define CAN0_BASE                                IP_FLEXCAN_0_BASE
/** Peripheral CAN_0 base pointer */
#define CAN0                                     ((CAN_Type *)CAN0_BASE)
/** Peripheral CAN_1 base address */
#define CAN1_BASE                                IP_FLEXCAN_1_BASE
/** Peripheral CAN_1 base pointer */
#define CAN1                                     ((CAN_Type *)CAN1_BASE)
/** Peripheral CAN_2 base address */
#define CAN2_BASE                                IP_FLEXCAN_2_BASE
/** Peripheral CAN_2 base pointer */
#define CAN2                                     ((CAN_Type *)CAN2_BASE)
/** Peripheral CAN_3 base address */
#define CAN3_BASE                                IP_FLEXCAN_3_BASE
/** Peripheral CAN_3 base pointer */
#define CAN3                                     ((CAN_Type *)CAN3_BASE)
/** Peripheral CAN_4 base address */
#define CAN4_BASE                                IP_FLEXCAN_4_BASE
/** Peripheral CAN_4 base pointer */
#define CAN4                                     ((CAN_Type *)CAN4_BASE)
/** Peripheral CAN_5 base address */
#define CAN5_BASE                                IP_FLEXCAN_5_BASE
/** Peripheral CAN_5 base pointer */
#define CAN5                                     ((CAN_Type *)CAN5_BASE)
/** Peripheral CAN_6 base address */
#define CAN6_BASE                                IP_FLEXCAN_6_BASE
/** Peripheral CAN_6 base pointer */
#define CAN6                                     ((CAN_Type *)CAN6_BASE)
/** Peripheral CAN_7 base address */
#define CAN7_BASE                                IP_FLEXCAN_7_BASE
/** Peripheral CAN_7 base pointer */
#define CAN7                                     ((CAN_Type *)CAN7_BASE)
/** Peripheral CAN_8 base address */
#define CAN8_BASE                                IP_FLEXCAN_8_BASE
/** Peripheral CAN_8 base pointer */
#define CAN8                                     ((CAN_Type *)CAN8_BASE)
/** Peripheral CAN_9 base address */
#define CAN9_BASE                                IP_FLEXCAN_9_BASE
/** Peripheral CAN_9 base pointer */
#define CAN9                                     ((CAN_Type *)CAN9_BASE)
/** Peripheral CAN_10 base address */
#define CAN10_BASE                               IP_FLEXCAN_10_BASE
/** Peripheral CAN_10 base pointer */
#define CAN10                                    ((CAN_Type *)CAN10_BASE)
/** Peripheral CAN_11 base address */
#define CAN11_BASE                               IP_FLEXCAN_11_BASE
/** Peripheral CAN_11 base pointer */
#define CAN11                                    ((CAN_Type *)CAN11_BASE)
/** Peripheral CAN_12 base address */
#define CAN12_BASE                               IP_FLEXCAN_12_BASE
/** Peripheral CAN_12 base pointer */
#define CAN12                                    ((CAN_Type *)CAN12_BASE)
/** Peripheral CAN_13 base address */
#define CAN13_BASE                               IP_FLEXCAN_13_BASE
/** Peripheral CAN_13 base pointer */
#define CAN13                                    ((CAN_Type *)CAN13_BASE)
/** Peripheral CAN_14 base address */
#define CAN14_BASE                               IP_FLEXCAN_14_BASE
/** Peripheral CAN_14 base pointer */
#define CAN14                                    ((CAN_Type *)CAN14_BASE)
/** Peripheral CAN_15 base address */
#define CAN15_BASE                               IP_FLEXCAN_15_BASE
/** Peripheral CAN_15 base pointer */
#define CAN15                                    ((CAN_Type *)CAN15_BASE)
/** Peripheral CAN_16 base address */
#define CAN16_BASE                               IP_FLEXCAN_16_BASE
/** Peripheral CAN_16 base pointer */
#define CAN16                                    ((CAN_Type *)CAN16_BASE)
/** Peripheral LPE_CAN base address */
#define LPE_CAN_BASE                             IP_LPE_FLEXCAN_BASE
/** Peripheral LPE_CAN base pointer */
#define LPE_CAN                                  ((CAN_Type *)LPE_CAN_BASE)
/** Array initializer of CAN peripheral base addresses */
#define CAN_BASE_ADDRS                           {CAN0_BASE, CAN1_BASE, CAN2_BASE, CAN3_BASE, CAN4_BASE, CAN5_BASE,                 \
                                                  CAN6_BASE, CAN7_BASE, CAN8_BASE, CAN9_BASE, CAN10_BASE, CAN11_BASE,               \
                                                  CAN12_BASE, CAN13_BASE, CAN14_BASE, CAN15_BASE, CAN16_BASE, LPE_CAN_BASE}
/** Array initializer of CAN peripheral base pointers */
#define CAN_BASE_PTRS                            {CAN0, CAN1, CAN2, CAN3, CAN4, CAN5, CAN6, CAN7, CAN8, CAN9, CAN10, CAN11,         \
                                                  CAN12, CAN13, CAN14, CAN15, CAN16, LPE_CAN}
#if defined(CONFIG_CPU_CORTEX_M7)
/** Interrupt vectors for the CAN peripheral type */
#define CAN_Rx_Warning_IRQS                      { CM7_FLEXCAN0_INT0_8_IRQn, CM7_FLEXCAN1_INT0_8_IRQn, CM7_FLEXCAN2_INT0_8_IRQn,     \
                                                   CM7_FLEXCAN3_INT0_8_IRQn, CM7_FLEXCAN4_INT0_8_IRQn, CM7_FLEXCAN5_INT0_8_IRQn,     \
                                                   CM7_FLEXCAN6_INT0_8_IRQn, CM7_FLEXCAN7_INT0_8_IRQn, CM7_FLEXCAN8_INT0_8_IRQn,     \
                                                   CM7_FLEXCAN9_INT0_8_IRQn, CM7_FLEXCAN10_INT0_8_IRQn, CM7_FLEXCAN11_INT0_8_IRQn,   \
                                                   CM7_FLEXCAN12_INT0_8_IRQn, CM7_FLEXCAN13_INT0_8_IRQn, CM7_FLEXCAN14_INT0_8_IRQn,  \
                                                   CM7_FLEXCAN15_INT0_8_IRQn, CM7_FLEXCAN16_INT0_8_IRQn, CM7_LPE_FLEXCAN_INT0_8_IRQn }

#define CAN_Tx_Warning_IRQS                      { CM7_FLEXCAN0_INT0_8_IRQn, CM7_FLEXCAN1_INT0_8_IRQn, CM7_FLEXCAN2_INT0_8_IRQn,     \
                                                   CM7_FLEXCAN3_INT0_8_IRQn, CM7_FLEXCAN4_INT0_8_IRQn, CM7_FLEXCAN5_INT0_8_IRQn,     \
                                                   CM7_FLEXCAN6_INT0_8_IRQn, CM7_FLEXCAN7_INT0_8_IRQn, CM7_FLEXCAN8_INT0_8_IRQn,     \
                                                   CM7_FLEXCAN9_INT0_8_IRQn, CM7_FLEXCAN10_INT0_8_IRQn, CM7_FLEXCAN11_INT0_8_IRQn,   \
                                                   CM7_FLEXCAN12_INT0_8_IRQn, CM7_FLEXCAN13_INT0_8_IRQn, CM7_FLEXCAN14_INT0_8_IRQn,  \
                                                   CM7_FLEXCAN15_INT0_8_IRQn, CM7_FLEXCAN16_INT0_8_IRQn, CM7_LPE_FLEXCAN_INT0_8_IRQn }

#define CAN_Wake_Up_IRQS                         { CM7_FLEXCAN0_INT0_8_IRQn, CM7_FLEXCAN1_INT0_8_IRQn, CM7_FLEXCAN2_INT0_8_IRQn,     \
                                                   CM7_FLEXCAN3_INT0_8_IRQn, CM7_FLEXCAN4_INT0_8_IRQn, CM7_FLEXCAN5_INT0_8_IRQn,     \
                                                   CM7_FLEXCAN6_INT0_8_IRQn, CM7_FLEXCAN7_INT0_8_IRQn, CM7_FLEXCAN8_INT0_8_IRQn,     \
                                                   CM7_FLEXCAN9_INT0_8_IRQn, CM7_FLEXCAN10_INT0_8_IRQn, CM7_FLEXCAN11_INT0_8_IRQn,   \
                                                   CM7_FLEXCAN12_INT0_8_IRQn, CM7_FLEXCAN13_INT0_8_IRQn, CM7_FLEXCAN14_INT0_8_IRQn,  \
                                                   CM7_FLEXCAN15_INT0_8_IRQn, CM7_FLEXCAN16_INT0_8_IRQn, CM7_LPE_FLEXCAN_INT0_8_IRQn }

#define CAN_Error_IRQS                           { CM7_FLEXCAN0_INT0_8_IRQn, CM7_FLEXCAN1_INT0_8_IRQn, CM7_FLEXCAN2_INT0_8_IRQn,     \
                                                   CM7_FLEXCAN3_INT0_8_IRQn, CM7_FLEXCAN4_INT0_8_IRQn, CM7_FLEXCAN5_INT0_8_IRQn,     \
                                                   CM7_FLEXCAN6_INT0_8_IRQn, CM7_FLEXCAN7_INT0_8_IRQn, CM7_FLEXCAN8_INT0_8_IRQn,     \
                                                   CM7_FLEXCAN9_INT0_8_IRQn, CM7_FLEXCAN10_INT0_8_IRQn, CM7_FLEXCAN11_INT0_8_IRQn,   \
                                                   CM7_FLEXCAN12_INT0_8_IRQn, CM7_FLEXCAN13_INT0_8_IRQn, CM7_FLEXCAN14_INT0_8_IRQn,  \
                                                   CM7_FLEXCAN15_INT0_8_IRQn, CM7_FLEXCAN16_INT0_8_IRQn, CM7_LPE_FLEXCAN_INT0_8_IRQn }

#define CAN_Bus_Off_IRQS                         { CM7_FLEXCAN0_INT0_8_IRQn, CM7_FLEXCAN1_INT0_8_IRQn, CM7_FLEXCAN2_INT0_8_IRQn,     \
                                                   CM7_FLEXCAN3_INT0_8_IRQn, CM7_FLEXCAN4_INT0_8_IRQn, CM7_FLEXCAN5_INT0_8_IRQn,     \
                                                   CM7_FLEXCAN6_INT0_8_IRQn, CM7_FLEXCAN7_INT0_8_IRQn, CM7_FLEXCAN8_INT0_8_IRQn,     \
                                                   CM7_FLEXCAN9_INT0_8_IRQn, CM7_FLEXCAN10_INT0_8_IRQn, CM7_FLEXCAN11_INT0_8_IRQn,   \
                                                   CM7_FLEXCAN12_INT0_8_IRQn, CM7_FLEXCAN13_INT0_8_IRQn, CM7_FLEXCAN14_INT0_8_IRQn,  \
                                                   CM7_FLEXCAN15_INT0_8_IRQn, CM7_FLEXCAN16_INT0_8_IRQn, CM7_LPE_FLEXCAN_INT0_8_IRQn }

#define CAN_ORed_Message_buffer_0_96_IRQS        { CM7_FLEXCAN0_INT9_15_IRQn, CM7_FLEXCAN1_INT9_15_IRQn, CM7_FLEXCAN2_INT9_15_IRQn,   \
                                                   CM7_FLEXCAN3_INT9_15_IRQn, CM7_FLEXCAN4_INT9_15_IRQn, CM7_FLEXCAN5_INT9_15_IRQn,   \
                                                   CM7_FLEXCAN6_INT9_15_IRQn, CM7_FLEXCAN7_INT9_15_IRQn, CM7_FLEXCAN8_INT9_15_IRQn,   \
                                                   CM7_FLEXCAN9_INT9_15_IRQn, CM7_FLEXCAN10_INT9_15_IRQn, CM7_FLEXCAN11_INT9_15_IRQn, \
                                                   CM7_FLEXCAN12_INT9_15_IRQn, CM7_FLEXCAN13_INT9_15_IRQn, CM7_FLEXCAN14_INT9_15_IRQn,\
                                                   CM7_FLEXCAN15_INT9_15_IRQn, CM7_FLEXCAN16_INT9_15_IRQn, CM7_LPE_FLEXCAN_INT9_15_IRQn }
#else
#define CAN_Rx_Warning_IRQS                      { R52_FLEXCAN0_INT0_8_IRQn, R52_FLEXCAN1_INT0_8_IRQn, R52_FLEXCAN2_INT0_8_IRQn,     \
                                                   R52_FLEXCAN3_INT0_8_IRQn, R52_FLEXCAN4_INT0_8_IRQn, R52_FLEXCAN5_INT0_8_IRQn,     \
                                                   R52_FLEXCAN6_INT0_8_IRQn, R52_FLEXCAN7_INT0_8_IRQn, R52_FLEXCAN8_INT0_8_IRQn,     \
                                                   R52_FLEXCAN9_INT0_8_IRQn, R52_FLEXCAN10_INT0_8_IRQn, R52_FLEXCAN11_INT0_8_IRQn,   \
                                                   R52_FLEXCAN12_INT0_8_IRQn, R52_FLEXCAN13_INT0_8_IRQn, R52_FLEXCAN14_INT0_8_IRQn,  \
                                                   R52_FLEXCAN15_INT0_8_IRQn, R52_FLEXCAN16_INT0_8_IRQn, R52_LPE_FLEXCAN_INT0_8_IRQn }

#define CAN_Tx_Warning_IRQS                      { R52_FLEXCAN0_INT0_8_IRQn, R52_FLEXCAN1_INT0_8_IRQn, R52_FLEXCAN2_INT0_8_IRQn,     \
                                                   R52_FLEXCAN3_INT0_8_IRQn, R52_FLEXCAN4_INT0_8_IRQn, R52_FLEXCAN5_INT0_8_IRQn,     \
                                                   R52_FLEXCAN6_INT0_8_IRQn, R52_FLEXCAN7_INT0_8_IRQn, R52_FLEXCAN8_INT0_8_IRQn,     \
                                                   R52_FLEXCAN9_INT0_8_IRQn, R52_FLEXCAN10_INT0_8_IRQn, R52_FLEXCAN11_INT0_8_IRQn,   \
                                                   R52_FLEXCAN12_INT0_8_IRQn, R52_FLEXCAN13_INT0_8_IRQn, R52_FLEXCAN14_INT0_8_IRQn,  \
                                                   R52_FLEXCAN15_INT0_8_IRQn, R52_FLEXCAN16_INT0_8_IRQn, R52_LPE_FLEXCAN_INT0_8_IRQn }

#define CAN_Wake_Up_IRQS                         { R52_FLEXCAN0_INT0_8_IRQn, R52_FLEXCAN1_INT0_8_IRQn, R52_FLEXCAN2_INT0_8_IRQn,     \
                                                   R52_FLEXCAN3_INT0_8_IRQn, R52_FLEXCAN4_INT0_8_IRQn, R52_FLEXCAN5_INT0_8_IRQn,     \
                                                   R52_FLEXCAN6_INT0_8_IRQn, R52_FLEXCAN7_INT0_8_IRQn, R52_FLEXCAN8_INT0_8_IRQn,     \
                                                   R52_FLEXCAN9_INT0_8_IRQn, R52_FLEXCAN10_INT0_8_IRQn, R52_FLEXCAN11_INT0_8_IRQn,   \
                                                   R52_FLEXCAN12_INT0_8_IRQn, R52_FLEXCAN13_INT0_8_IRQn, R52_FLEXCAN14_INT0_8_IRQn,  \
                                                   R52_FLEXCAN15_INT0_8_IRQn, R52_FLEXCAN16_INT0_8_IRQn, R52_LPE_FLEXCAN_INT0_8_IRQn }

#define CAN_Error_IRQS                           { R52_FLEXCAN0_INT0_8_IRQn, R52_FLEXCAN1_INT0_8_IRQn, R52_FLEXCAN2_INT0_8_IRQn,     \
                                                   R52_FLEXCAN3_INT0_8_IRQn, R52_FLEXCAN4_INT0_8_IRQn, R52_FLEXCAN5_INT0_8_IRQn,     \
                                                   R52_FLEXCAN6_INT0_8_IRQn, R52_FLEXCAN7_INT0_8_IRQn, R52_FLEXCAN8_INT0_8_IRQn,     \
                                                   R52_FLEXCAN9_INT0_8_IRQn, R52_FLEXCAN10_INT0_8_IRQn, R52_FLEXCAN11_INT0_8_IRQn,   \
                                                   R52_FLEXCAN12_INT0_8_IRQn, R52_FLEXCAN13_INT0_8_IRQn, R52_FLEXCAN14_INT0_8_IRQn,  \
                                                   R52_FLEXCAN15_INT0_8_IRQn, R52_FLEXCAN16_INT0_8_IRQn, R52_LPE_FLEXCAN_INT0_8_IRQn }

#define CAN_Bus_Off_IRQS                         { R52_FLEXCAN0_INT0_8_IRQn, R52_FLEXCAN1_INT0_8_IRQn, R52_FLEXCAN2_INT0_8_IRQn,     \
                                                   R52_FLEXCAN3_INT0_8_IRQn, R52_FLEXCAN4_INT0_8_IRQn, R52_FLEXCAN5_INT0_8_IRQn,     \
                                                   R52_FLEXCAN6_INT0_8_IRQn, R52_FLEXCAN7_INT0_8_IRQn, R52_FLEXCAN8_INT0_8_IRQn,     \
                                                   R52_FLEXCAN9_INT0_8_IRQn, R52_FLEXCAN10_INT0_8_IRQn, R52_FLEXCAN11_INT0_8_IRQn,   \
                                                   R52_FLEXCAN12_INT0_8_IRQn, R52_FLEXCAN13_INT0_8_IRQn, R52_FLEXCAN14_INT0_8_IRQn,  \
                                                   R52_FLEXCAN15_INT0_8_IRQn, R52_FLEXCAN16_INT0_8_IRQn, R52_LPE_FLEXCAN_INT0_8_IRQn }

#define CAN_ORed_Message_buffer_0_96_IRQS        { R52_FLEXCAN0_INT9_15_IRQn, R52_FLEXCAN1_INT9_15_IRQn, R52_FLEXCAN2_INT9_15_IRQn,   \
                                                   R52_FLEXCAN3_INT9_15_IRQn, R52_FLEXCAN4_INT9_15_IRQn, R52_FLEXCAN5_INT9_15_IRQn,   \
                                                   R52_FLEXCAN6_INT9_15_IRQn, R52_FLEXCAN7_INT9_15_IRQn, R52_FLEXCAN8_INT9_15_IRQn,   \
                                                   R52_FLEXCAN9_INT9_15_IRQn, R52_FLEXCAN10_INT9_15_IRQn, R52_FLEXCAN11_INT9_15_IRQn, \
                                                   R52_FLEXCAN12_INT9_15_IRQn, R52_FLEXCAN13_INT9_15_IRQn, R52_FLEXCAN14_INT9_15_IRQn,\
                                                   R52_FLEXCAN15_INT9_15_IRQn, R52_FLEXCAN16_INT9_15_IRQn, R52_LPE_FLEXCAN_INT9_15_IRQn }
#endif /* CONFIG_CPU_CORTEX_M7 */

#define CAN_ORed_Message_buffer_IRQS             CAN_ORed_Message_buffer_0_96_IRQS

/* DMA - Peripheral instance base addresses */

/** Peripheral DMA0 base pointer */
#define DMA3_BASE                                 IP_LPE_EDMA3_BASE

#define DMA3                                      ((DMA_Type*)DMA3_BASE)

#define DMA_BASE_ADDRS                            { IP_LPE_EDMA3_BASE }

/* DMAMUX - Peripheral instance base addresses */
/** Peripheral DMAMUX0 base address */
#define DMAMUX0_BASE                             IP_DMAMUX_0_BASE
/** Peripheral DMAMUX0 base pointer */
#define DMAMUX0                                  IP_DMAMUX_0
/** Peripheral DMAMUX1 base address */
#define DMAMUX1_BASE                             IP_DMAMUX_1_BASE
/** Peripheral DMAMUX1 base pointer */
#define DMAMUX1                                  IP_DMAMUX_1
/** Peripheral LPE_DMAMUX base address */
#define LPE_DMAMUX_BASE                          IP_LPE_DMAMUX_BASE
/** Peripheral LPE_DMAMUX base pointer */
#define LPE_DMAMUX                               IP_LPE_DMAMUX
/** Array initializer of DMAMUX peripheral base addresses */
#define DMAMUX_BASE_ADDRS                        IP_DMAMUX_BASE_ADDRS
/** Array initializer of DMAMUX peripheral base pointers */
#define DMAMUX_BASE_PTRS                         IP_DMAMUX_BASE_PTRS

/* DMA5 - Peripheral instance base addresses */
#define EDMA5_BASE                               IP_EDMA5_BASE
/* DMA5 - Peripheral instance base addresses */
#define EDMA5                                    ((DMA5_Type *)EDMA5_BASE)
/* DMA5 - Peripheral instance base addresses */
#define DMA5_BASE_ADDRS                          { IP_EDMA5_BASE }

#endif  /* _S32K566_GLUE_MCUX_H_ */
