/*
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _S32Z270_GLUE_MCUX_H_
#define _S32Z270_GLUE_MCUX_H_

#include "S32Z270_device.h"

/* PIT - Peripheral instance base addresses */
/** Peripheral PIT0 base address */
#define PIT0_BASE                                IP_PIT_0_BASE
/** Peripheral PIT0 base pointer */
#define PIT0                                     IP_PIT_0
/** Array initializer of PIT peripheral base addresses */
#define PIT_BASE_ADDRS                           IP_PIT_BASE_ADDRS
/** Array initializer of PIT peripheral base pointers */
#define PIT_BASE_PTRS                            IP_PIT_BASE_PTRS
/** Interrupt vectors for the PIT peripheral type */
#define PIT_IRQS                                 { RTU_RTUn_PIT0_IRQn }

/* I3C - Peripheral instance base addresses */
/** Peripheral I3C0 base address */
#define I3C0_BASE                                IP_I3C_0_BASE
/** Peripheral I3C0 base pointer */
#define I3C0                                     IP_I3C_0
/** Peripheral I3C1 base address */
#define I3C1_BASE                                IP_I3C_1_BASE
/** Peripheral I3C1 base pointer */
#define I3C1                                     IP_I3C_1
/** Peripheral I3C2 base address */
#define I3C2_BASE                                IP_I3C_2_BASE
/** Peripheral I3C1 base pointer */
#define I3C2                                     IP_I3C_2
/** Array initializer of I3C peripheral base addresses */
#define I3C_BASE_ADDRS                           IP_I3C_BASE_ADDRS
/** Array initializer of I3C peripheral base pointers */
#define I3C_BASE_PTRS                            IP_I3C_BASE_PTRS
/** Interrupt vectors for the I3C peripheral type */
#define I3C_IRQS                                 { RTU_I3C0_IRQn, RTU_I3C1_IRQn, RTU_I3C2_IRQn }

/*
 * These bit fields are not existed on this SoC, I3C slave request IBI will not be
 * supported because I3C functionality is not stable in this SoC. Keep define these
 * macros in order to build.
 */
#define I3C_IBIEXT2_EXT5(x)                     0
#define I3C_IBIEXT2_EXT6(x)                     0
#define I3C_IBIEXT2_EXT7(x)                     0

/* SPI - Peripheral instance base addresses */
/** Peripheral MSC_0_DSPI base address */
#define SPI0_BASE                                  IP_MSC_0_DSPI_BASE
/** Peripheral MSC_0_DSPI base pointer */
#define SPI0                                       ((SPI_Type *)SPI0_BASE)
/** Array initializer of DSPI peripheral base addresses */
#define SPI_BASE_ADDRS                             { SPI0_BASE }
/** Array initializer of DSPI peripheral base pointers */
#define SPI_BASE_PTRS                              { SPI0 }

#define SPI_IRQS                                   { RTU_MSC0_DSPI_IRQn }

/* CAN - Peripheral instance base addresses */
/** Peripheral CAN_0 base address */
#define CAN0_BASE                                   IP_CE_CAN_0_BASE
/** Peripheral CAN_0 base pointer */
#define CAN0                                        ((CAN_Type *)CAN0_BASE)
/** Peripheral CAN_1 base address */
#define CAN1_BASE                                   IP_CE_CAN_1_BASE
/** Peripheral CAN_1 base pointer */
#define CAN1                                        ((CAN_Type *)CAN1_BASE)
/** Peripheral CAN_2 base address */
#define CAN2_BASE                                   IP_CE_CAN_2_BASE
/** Peripheral CAN_2 base pointer */
#define CAN2                                        ((CAN_Type *)CAN2_BASE)
/** Peripheral CAN_3 base address */
#define CAN3_BASE                                   IP_CE_CAN_3_BASE
/** Peripheral CAN_3 base pointer */
#define CAN3                                        ((CAN_Type *)CAN3_BASE)
/** Peripheral CAN_4 base address */
#define CAN4_BASE                                   IP_CE_CAN_4_BASE
/** Peripheral CAN_4 base pointer */
#define CAN4                                        ((CAN_Type *)CAN4_BASE)
/** Peripheral CAN_5 base address */
#define CAN5_BASE                                   IP_CE_CAN_5_BASE
/** Peripheral CAN_5 base pointer */
#define CAN5                                        ((CAN_Type *)CAN5_BASE)
/** Peripheral CAN_6 base address */
#define CAN6_BASE                                   IP_CE_CAN_6_BASE
/** Peripheral CAN_6 base pointer */
#define CAN6                                        ((CAN_Type *)CAN6_BASE)
/** Peripheral CAN_7 base address */
#define CAN7_BASE                                   IP_CE_CAN_7_BASE
/** Peripheral CAN_7 base pointer */
#define CAN7                                        ((CAN_Type *)CAN7_BASE)
/** Peripheral CAN_8 base address */
#define CAN8_BASE                                   IP_CE_CAN_8_BASE
/** Peripheral CAN_8 base pointer */
#define CAN8                                        ((CAN_Type *)CAN8_BASE)
/** Peripheral CAN_9 base address */
#define CAN9_BASE                                   IP_CE_CAN_9_BASE
/** Peripheral CAN_9 base pointer */
#define CAN9                                        ((CAN_Type *)CAN9_BASE)
/** Peripheral CAN_10 base address */
#define CAN10_BASE                                  IP_CE_CAN_10_BASE
/** Peripheral CAN_10 base pointer */
#define CAN10                                       ((CAN_Type *)CAN10_BASE)
/** Peripheral CAN_11 base address */
#define CAN11_BASE                                  IP_CE_CAN_11_BASE
/** Peripheral CAN_11 base pointer */
#define CAN11                                       ((CAN_Type *)CAN11_BASE)
/** Peripheral CAN_12 base address */
#define CAN12_BASE                                  IP_CE_CAN_12_BASE
/** Peripheral CAN_12 base pointer */
#define CAN12                                       ((CAN_Type *)CAN12_BASE)
/** Peripheral CAN_13 base address */
#define CAN13_BASE                                  IP_CE_CAN_13_BASE
/** Peripheral CAN_13 base pointer */
#define CAN13                                       ((CAN_Type *)CAN13_BASE)
/** Peripheral CAN_14 base address */
#define CAN14_BASE                                  IP_CE_CAN_14_BASE
/** Peripheral CAN_14 base pointer */
#define CAN14                                       ((CAN_Type *)CAN14_BASE)
/** Peripheral CAN_15 base address */
#define CAN15_BASE                                  IP_CE_CAN_15_BASE
/** Peripheral CAN_15 base pointer */
#define CAN15                                       ((CAN_Type *)CAN15_BASE)
/** Peripheral CAN_16 base address */
#define CAN16_BASE                                  IP_CE_CAN_16_BASE
/** Peripheral CAN_16 base pointer */
#define CAN16                                       ((CAN_Type *)CAN16_BASE)
/** Peripheral CAN_17 base address */
#define CAN17_BASE                                  IP_CE_CAN_17_BASE
/** Peripheral CAN_17 base pointer */
#define CAN17                                       ((CAN_Type *)CAN17_BASE)
/** Peripheral CAN_18 base address */
#define CAN18_BASE                                  IP_CE_CAN_18_BASE
/** Peripheral CAN_18 base pointer */
#define CAN18                                       ((CAN_Type *)CAN18_BASE)
/** Peripheral CAN_19 base address */
#define CAN19_BASE                                  IP_CE_CAN_19_BASE
/** Peripheral CAN_19 base pointer */
#define CAN19                                       ((CAN_Type *)CAN19_BASE)
/** Peripheral CAN_20 base address */
#define CAN20_BASE                                  IP_CE_CAN_20_BASE
/** Peripheral CAN_20 base pointer */
#define CAN20                                       ((CAN_Type *)CAN20_BASE)
/** Peripheral CAN_21 base address */
#define CAN21_BASE                                  IP_CE_CAN_21_BASE
/** Peripheral CAN_21 base pointer */
#define CAN21                                       ((CAN_Type *)CAN21_BASE)
/** Peripheral CAN_22 base address */
#define CAN22_BASE                                  IP_CE_CAN_22_BASE
/** Peripheral CAN_22 base pointer */
#define CAN22                                       ((CAN_Type *)CAN22_BASE)
/** Peripheral CAN_23 base address */
#define CAN23_BASE                                  IP_CE_CAN_23_BASE
/** Peripheral CAN_19 base pointer */
#define CAN23                                       ((CAN_Type *)CAN23_BASE)
/** Array initializer of CAN peripheral base addresses */
#define CAN_BASE_ADDRS                              { CAN0_BASE, CAN1_BASE, CAN2_BASE, CAN3_BASE, CAN4_BASE, CAN5_BASE, \
                                                    CAN6_BASE, CAN7_BASE, CAN8_BASE, CAN9_BASE, CAN10_BASE, CAN11_BASE, \
                                                    CAN12_BASE, CAN13_BASE, CAN14_BASE, CAN15_BASE, CAN16_BASE, CAN17_BASE, \
                                                    CAN18_BASE, CAN19_BASE, CAN20_BASE, CAN21_BASE,CAN22_BASE,CAN23_BASE }
/** Array initializer of CAN peripheral base pointers */
#define CAN_BASE_PTRS                               { CAN0, CAN1, CAN2, CAN3, CAN4, CAN5, \
                                                    CAN6, CAN7, CAN8, CAN9, CAN10, CAN11, \
                                                    CAN12, CAN13, CAN14, CAN15, CAN16, CAN17, \
                                                    CAN18, CAN19, CAN20, CAN21,CAN22,CAN23 }

/** Interrupt vectors for the CAN peripheral type */
#define CAN_Rx_Warning_IRQS                         { RTU_CE_CAN0_INIT_OR_ERROR_IRQn, RTU_CE_CAN1_INIT_OR_ERROR_IRQn, RTU_CE_CAN2_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN3_INIT_OR_ERROR_IRQn, RTU_CE_CAN4_INIT_OR_ERROR_IRQn, RTU_CE_CAN5_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN6_INIT_OR_ERROR_IRQn, RTU_CE_CAN7_INIT_OR_ERROR_IRQn, RTU_CE_CAN8_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN9_INIT_OR_ERROR_IRQn, RTU_CE_CAN10_INIT_OR_ERROR_IRQn, RTU_CE_CAN11_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN12_INIT_OR_ERROR_IRQn, RTU_CE_CAN13_INIT_OR_ERROR_IRQn, RTU_CE_CAN14_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN15_INIT_OR_ERROR_IRQn, RTU_CE_CAN16_INIT_OR_ERROR_IRQn, RTU_CE_CAN17_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN18_INIT_OR_ERROR_IRQn, RTU_CE_CAN19_INIT_OR_ERROR_IRQn, RTU_CE_CAN20_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN21_INIT_OR_ERROR_IRQn, RTU_CE_CAN22_INIT_OR_ERROR_IRQn, RTU_CE_CAN23_INIT_OR_ERROR_IRQn }
#define CAN_Tx_Warning_IRQS                         { RTU_CE_CAN0_INIT_OR_ERROR_IRQn, RTU_CE_CAN1_INIT_OR_ERROR_IRQn, RTU_CE_CAN2_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN3_INIT_OR_ERROR_IRQn, RTU_CE_CAN4_INIT_OR_ERROR_IRQn, RTU_CE_CAN5_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN6_INIT_OR_ERROR_IRQn, RTU_CE_CAN7_INIT_OR_ERROR_IRQn, RTU_CE_CAN8_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN9_INIT_OR_ERROR_IRQn, RTU_CE_CAN10_INIT_OR_ERROR_IRQn, RTU_CE_CAN11_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN12_INIT_OR_ERROR_IRQn, RTU_CE_CAN13_INIT_OR_ERROR_IRQn, RTU_CE_CAN14_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN15_INIT_OR_ERROR_IRQn, RTU_CE_CAN16_INIT_OR_ERROR_IRQn, RTU_CE_CAN17_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN18_INIT_OR_ERROR_IRQn, RTU_CE_CAN19_INIT_OR_ERROR_IRQn, RTU_CE_CAN20_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN21_INIT_OR_ERROR_IRQn, RTU_CE_CAN22_INIT_OR_ERROR_IRQn, RTU_CE_CAN23_INIT_OR_ERROR_IRQn }
#define CAN_Wake_Up_IRQS                            { RTU_CE_CAN0_INIT_OR_ERROR_IRQn, RTU_CE_CAN1_INIT_OR_ERROR_IRQn, RTU_CE_CAN2_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN3_INIT_OR_ERROR_IRQn, RTU_CE_CAN4_INIT_OR_ERROR_IRQn, RTU_CE_CAN5_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN6_INIT_OR_ERROR_IRQn, RTU_CE_CAN7_INIT_OR_ERROR_IRQn, RTU_CE_CAN8_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN9_INIT_OR_ERROR_IRQn, RTU_CE_CAN10_INIT_OR_ERROR_IRQn, RTU_CE_CAN11_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN12_INIT_OR_ERROR_IRQn, RTU_CE_CAN13_INIT_OR_ERROR_IRQn, RTU_CE_CAN14_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN15_INIT_OR_ERROR_IRQn, RTU_CE_CAN16_INIT_OR_ERROR_IRQn, RTU_CE_CAN17_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN18_INIT_OR_ERROR_IRQn, RTU_CE_CAN19_INIT_OR_ERROR_IRQn, RTU_CE_CAN20_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN21_INIT_OR_ERROR_IRQn, RTU_CE_CAN22_INIT_OR_ERROR_IRQn, RTU_CE_CAN23_INIT_OR_ERROR_IRQn }
#define CAN_Error_IRQS                              { RTU_CE_CAN0_INIT_OR_ERROR_IRQn, RTU_CE_CAN1_INIT_OR_ERROR_IRQn, RTU_CE_CAN2_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN3_INIT_OR_ERROR_IRQn, RTU_CE_CAN4_INIT_OR_ERROR_IRQn, RTU_CE_CAN5_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN6_INIT_OR_ERROR_IRQn, RTU_CE_CAN7_INIT_OR_ERROR_IRQn, RTU_CE_CAN8_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN9_INIT_OR_ERROR_IRQn, RTU_CE_CAN10_INIT_OR_ERROR_IRQn, RTU_CE_CAN11_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN12_INIT_OR_ERROR_IRQn, RTU_CE_CAN13_INIT_OR_ERROR_IRQn, RTU_CE_CAN14_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN15_INIT_OR_ERROR_IRQn, RTU_CE_CAN16_INIT_OR_ERROR_IRQn, RTU_CE_CAN17_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN18_INIT_OR_ERROR_IRQn, RTU_CE_CAN19_INIT_OR_ERROR_IRQn, RTU_CE_CAN20_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN21_INIT_OR_ERROR_IRQn, RTU_CE_CAN22_INIT_OR_ERROR_IRQn, RTU_CE_CAN23_INIT_OR_ERROR_IRQn }
#define CAN_Bus_Off_IRQS                            { RTU_CE_CAN0_INIT_OR_ERROR_IRQn, RTU_CE_CAN1_INIT_OR_ERROR_IRQn, RTU_CE_CAN2_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN3_INIT_OR_ERROR_IRQn, RTU_CE_CAN4_INIT_OR_ERROR_IRQn, RTU_CE_CAN5_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN6_INIT_OR_ERROR_IRQn, RTU_CE_CAN7_INIT_OR_ERROR_IRQn, RTU_CE_CAN8_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN9_INIT_OR_ERROR_IRQn, RTU_CE_CAN10_INIT_OR_ERROR_IRQn, RTU_CE_CAN11_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN12_INIT_OR_ERROR_IRQn, RTU_CE_CAN13_INIT_OR_ERROR_IRQn, RTU_CE_CAN14_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN15_INIT_OR_ERROR_IRQn, RTU_CE_CAN16_INIT_OR_ERROR_IRQn, RTU_CE_CAN17_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN18_INIT_OR_ERROR_IRQn, RTU_CE_CAN19_INIT_OR_ERROR_IRQn, RTU_CE_CAN20_INIT_OR_ERROR_IRQn, \
                                                    RTU_CE_CAN21_INIT_OR_ERROR_IRQn, RTU_CE_CAN22_INIT_OR_ERROR_IRQn, RTU_CE_CAN23_INIT_OR_ERROR_IRQn }
#define CAN_ORed_Message_buffer_0_31_IRQS           { RTU_CE_CAN0_MB_31_0_IRQn, RTU_CE_CAN1_MB_31_0_IRQn, RTU_CE_CAN2_MB_31_0_IRQn, RTU_CE_CAN3_MB_31_0_IRQn, \
                                                    RTU_CE_CAN4_MB_31_0_IRQn, RTU_CE_CAN5_MB_31_0_IRQn, RTU_CE_CAN6_MB_31_0_IRQn, RTU_CE_CAN7_MB_31_0_IRQn, \
                                                    RTU_CE_CAN8_MB_31_0_IRQn, RTU_CE_CAN9_MB_31_0_IRQn, RTU_CE_CAN10_MB_31_0_IRQn, RTU_CE_CAN11_MB_31_0_IRQn, \
                                                    RTU_CE_CAN12_MB_31_0_IRQn, RTU_CE_CAN13_MB_31_0_IRQn, RTU_CE_CAN14_MB_31_0_IRQn, RTU_CE_CAN15_MB_31_0_IRQn, \
                                                    RTU_CE_CAN16_MB_31_0_IRQn, RTU_CE_CAN17_MB_31_0_IRQn, RTU_CE_CAN18_MB_31_0_IRQn, RTU_CE_CAN19_MB_31_0_IRQn, \
                                                    RTU_CE_CAN20_MB_31_0_IRQn, RTU_CE_CAN21_MB_31_0_IRQn, RTU_CE_CAN22_MB_31_0_IRQn, RTU_CE_CAN23_MB_31_0_IRQn }
#define CAN_ORed_Message_buffer_32_63_IRQS          { RTU_CE_CAN0_MB_63_32_IRQn, RTU_CE_CAN1_MB_63_32_IRQn, RTU_CE_CAN2_MB_63_32_IRQn, RTU_CE_CAN3_MB_63_32_IRQn, \
                                                    RTU_CE_CAN4_MB_63_32_IRQn, RTU_CE_CAN5_MB_63_32_IRQn, RTU_CE_CAN6_MB_63_32_IRQn, RTU_CE_CAN7_MB_63_32_IRQn, \
                                                    RTU_CE_CAN8_MB_63_32_IRQn, RTU_CE_CAN9_MB_63_32_IRQn, RTU_CE_CAN10_MB_63_32_IRQn, RTU_CE_CAN11_MB_63_32_IRQn, \
                                                    RTU_CE_CAN12_MB_63_32_IRQn, RTU_CE_CAN13_MB_63_32_IRQn, RTU_CE_CAN14_MB_63_32_IRQn, RTU_CE_CAN15_MB_63_32_IRQn, \
                                                    RTU_CE_CAN16_MB_63_32_IRQn, RTU_CE_CAN17_MB_63_32_IRQn, RTU_CE_CAN18_MB_63_32_IRQn, RTU_CE_CAN19_MB_63_32_IRQn, \
                                                    RTU_CE_CAN20_MB_63_32_IRQn, RTU_CE_CAN21_MB_63_32_IRQn, RTU_CE_CAN22_MB_63_32_IRQn, RTU_CE_CAN23_MB_63_32_IRQn }
#define CAN_ORed_Message_buffer_64_95_IRQS          { RTU_CE_CAN0_MB_95_64_IRQn, RTU_CE_CAN1_MB_95_64_IRQn, RTU_CE_CAN2_MB_95_64_IRQn, RTU_CE_CAN3_MB_95_64_IRQn, \
                                                    RTU_CE_CAN4_MB_95_64_IRQn, RTU_CE_CAN5_MB_95_64_IRQn, RTU_CE_CAN6_MB_95_64_IRQn, RTU_CE_CAN7_MB_95_64_IRQn, \
                                                    RTU_CE_CAN8_MB_95_64_IRQn, RTU_CE_CAN9_MB_95_64_IRQn, RTU_CE_CAN10_MB_95_64_IRQn, RTU_CE_CAN11_MB_95_64_IRQn, \
                                                    RTU_CE_CAN12_MB_95_64_IRQn, RTU_CE_CAN13_MB_95_64_IRQn, RTU_CE_CAN14_MB_95_64_IRQn, RTU_CE_CAN15_MB_95_64_IRQn, \
                                                    RTU_CE_CAN16_MB_95_64_IRQn, RTU_CE_CAN17_MB_95_64_IRQn, RTU_CE_CAN18_MB_95_64_IRQn, RTU_CE_CAN19_MB_95_64_IRQn, \
                                                    RTU_CE_CAN20_MB_95_64_IRQn, RTU_CE_CAN21_MB_95_64_IRQn, RTU_CE_CAN22_MB_95_64_IRQn, RTU_CE_CAN23_MB_95_64_IRQn }
#define CAN_ORed_Message_buffer_96_127_IRQS         { RTU_CE_CAN0_MB_127_96_IRQn, RTU_CE_CAN1_MB_127_96_IRQn, RTU_CE_CAN2_MB_127_96_IRQn, RTU_CE_CAN3_MB_127_96_IRQn, \
                                                    RTU_CE_CAN4_MB_127_96_IRQn, RTU_CE_CAN5_MB_127_96_IRQn, RTU_CE_CAN6_MB_127_96_IRQn, RTU_CE_CAN7_MB_127_96_IRQn, \
                                                    RTU_CE_CAN8_MB_127_96_IRQn, RTU_CE_CAN9_MB_127_96_IRQn, RTU_CE_CAN10_MB_127_96_IRQn, RTU_CE_CAN11_MB_127_96_IRQn, \
                                                    RTU_CE_CAN12_MB_127_96_IRQn, RTU_CE_CAN13_MB_127_96_IRQn, RTU_CE_CAN14_MB_127_96_IRQn, RTU_CE_CAN15_MB_127_96_IRQn, \
                                                    RTU_CE_CAN16_MB_127_96_IRQn, RTU_CE_CAN17_MB_127_96_IRQn, RTU_CE_CAN18_MB_127_96_IRQn, RTU_CE_CAN19_MB_127_96_IRQn, \
                                                    RTU_CE_CAN20_MB_127_96_IRQn, RTU_CE_CAN21_MB_127_96_IRQn, RTU_CE_CAN22_MB_127_96_IRQn, RTU_CE_CAN23_MB_127_96_IRQn }

#define CAN_ORed_Message_buffer_IRQS                CAN_ORed_Message_buffer_0_31_IRQS

/*!
 * @addtogroup LPI2C_Peripheral_Access_Layer LPI2C Peripheral Access Layer
 * @{
 */

/* LPI2C - Peripheral instance base addresses */
/** Peripheral LPI2C1 base address */
#define LPI2C1_BASE                              IP_LPI2C_1_BASE
/** Peripheral LPI2C1 base pointer */
#define LPI2C1                                   IP_LPI2C_1
/** Peripheral LPI2C2 base address */
#define LPI2C2_BASE                              IP_LPI2C_2_BASE
/** Peripheral LPI2C2 base pointer */
#define LPI2C2                                   IP_LPI2C_2
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         IP_LPI2C_BASE_ADDRS
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          IP_LPI2C_BASE_PTRS
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { RTU_LPI2C1_IRQn, RTU_LPI2C2_IRQn }

/* EDMA3 - Peripheral instance base addresses */

/** Peripheral DMA0 base pointer */
#define DMA0                                      ((DMA_Type *)IP_EDMA_0_MP_BASE)
/** Interrupt vectors for the DMA0 peripheral type */
#define DMA0_IRQS                                 { RTU_DMA0_0_IRQn, RTU_DMA0_1_IRQn, RTU_DMA0_2_IRQn, RTU_DMA0_3_IRQn,    \
                                                    RTU_DMA0_4_IRQn, RTU_DMA0_5_IRQn, RTU_DMA0_6_IRQn, RTU_DMA0_7_IRQn,    \
                                                    RTU_DMA0_8_IRQn, RTU_DMA0_9_IRQn, RTU_DMA0_10_IRQn, RTU_DMA0_11_IRQn,  \
                                                    RTU_DMA0_12_IRQn, RTU_DMA0_13_IRQn, RTU_DMA0_14_IRQn, RTU_DMA0_15_IRQn,\
                                                    RTU_DMA0_16_IRQn, RTU_DMA0_17_IRQn, RTU_DMA0_18_IRQn, RTU_DMA0_19_IRQn,\
                                                    RTU_DMA0_20_IRQn, RTU_DMA0_21_IRQn, RTU_DMA0_22_IRQn, RTU_DMA0_23_IRQn,\
                                                    RTU_DMA0_24_IRQn, RTU_DMA0_25_IRQn, RTU_DMA0_26_IRQn, RTU_DMA0_27_IRQn,\
                                                    RTU_DMA0_28_IRQn, RTU_DMA0_29_IRQn, RTU_DMA0_30_IRQn, RTU_DMA0_31_IRQn }

#define DMA0_ERROR_IRQS                           { RTU_DMA0_ERR_IRQn }

/** Peripheral DMA1 base pointer */
#define DMA1                                      ((DMA_Type *)IP_EDMA_1_MP_BASE)
/** Interrupt vectors for the DMA1 peripheral type */
#define DMA1_IRQS                                 { RTU_DMA1_0_IRQn, RTU_DMA1_1_IRQn, RTU_DMA1_2_IRQn, RTU_DMA1_3_IRQn,    \
                                                    RTU_DMA1_4_IRQn, RTU_DMA1_5_IRQn, RTU_DMA1_6_IRQn, RTU_DMA1_7_IRQn,    \
                                                    RTU_DMA1_8_IRQn, RTU_DMA1_9_IRQn, RTU_DMA1_10_IRQn, RTU_DMA1_11_IRQn,  \
                                                    RTU_DMA1_12_IRQn, RTU_DMA1_13_IRQn, RTU_DMA1_14_IRQn, RTU_DMA1_15_IRQn }

#define DMA1_ERROR_IRQS                           { RTU_DMA1_ERR_IRQn }

/** Peripheral DMA4 base pointer */
#define DMA4                                      ((DMA_Type *)IP_EDMA_4_MP_BASE)
/** Interrupt vectors for the DMA4 peripheral type */
#define DMA4_IRQS                                 { RTU_DMA4_0_IRQn, RTU_DMA4_1_IRQn, RTU_DMA4_2_IRQn, RTU_DMA4_3_IRQn,    \
                                                    RTU_DMA4_4_IRQn, RTU_DMA4_5_IRQn, RTU_DMA4_6_IRQn, RTU_DMA4_7_IRQn,    \
                                                    RTU_DMA4_8_IRQn, RTU_DMA4_9_IRQn, RTU_DMA4_10_IRQn, RTU_DMA4_11_IRQn,  \
                                                    RTU_DMA4_12_IRQn, RTU_DMA4_13_IRQn, RTU_DMA4_14_IRQn, RTU_DMA4_15_IRQn }

#define DMA4_ERROR_IRQS                           { RTU_DMA4_ERR_IRQn }

/** Peripheral DMA5 base pointer */
#define DMA5                                      ((DMA_Type *)IP_EDMA_5_MP_BASE)
/** Interrupt vectors for the DMA5 peripheral type */
#define DMA5_IRQS                                 { RTU_DMA5_0_IRQn, RTU_DMA5_1_IRQn, RTU_DMA5_2_IRQn, RTU_DMA5_3_IRQn,    \
                                                    RTU_DMA5_4_IRQn, RTU_DMA5_5_IRQn, RTU_DMA5_6_IRQn, RTU_DMA5_7_IRQn,    \
                                                    RTU_DMA5_8_IRQn, RTU_DMA5_9_IRQn, RTU_DMA5_10_IRQn, RTU_DMA5_11_IRQn,  \
                                                    RTU_DMA5_12_IRQn, RTU_DMA5_13_IRQn, RTU_DMA5_14_IRQn, RTU_DMA5_15_IRQn }

#define DMA5_ERROR_IRQS                           { RTU_DMA5_ERR_IRQn }

/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                             { DMA0, DMA1, DMA4, DMA5 }
/** Interrupt vectors for the DMA peripheral type */
#define DMA_IRQS                                  { DMA0_IRQS, DMA1_IRQS, DMA4_IRQS, DMA5_IRQS }
#define DMA_ERROR_IRQS                            { DMA0_ERROR_IRQS, DMA1_ERROR_IRQS, DMA4_ERROR_IRQS, DMA5_ERROR_IRQS }

#endif /* _S32Z270_GLUE_MCUX_H_ */
