/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_SPI.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_SPI
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32Z2_SPI_H_)  /* Check if memory map has not been already included */
#define S32Z2_SPI_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI_Peripheral_Access_Layer SPI Peripheral Access Layer
 * @{
 */

/** SPI - Size of Registers Arrays */
#define SPI_MODE_CTAR_CTAR_COUNT                  6u
#define SPI_MODE_CTAR_SLAVE_CTAR_SLAVE_COUNT      1u
#define SPI_TXFR_COUNT                            5u
#define SPI_RXFR_COUNT                            5u
#define SPI_CTARE_COUNT                           6u

/** SPI - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< Module Configuration Register, offset: 0x0 */
  uint8_t RESERVED_0[4];
  __IO uint32_t TCR;                               /**< Transfer Count Register, offset: 0x8 */
  union {                                          /* offset: 0xC */
    __IO uint32_t CTAR[SPI_MODE_CTAR_CTAR_COUNT];    /**< Clock and Transfer Attributes Register (in Master mode), array offset: 0xC, array step: 0x4 */
    __IO uint32_t CTAR_SLAVE[SPI_MODE_CTAR_SLAVE_CTAR_SLAVE_COUNT];   /**< Clock and Transfer Attributes Register (in Slave mode), array offset: 0xC, array step: 0x4 */
  } MODE;
  uint8_t RESERVED_1[8];
  __IO uint32_t SR;                                /**< Status Register, offset: 0x2C */
  __IO uint32_t RSER;                              /**< DMA/Interrupt Request Select and Enable Register, offset: 0x30 */
  union {                                          /* offset: 0x34 */
    struct SPI_PUSHR_FIFO {                          /* offset: 0x34 */
      __IO uint16_t TX;                                /**< SPI_TX register, offset: 0x34 */
      __IO uint16_t CMD;                               /**< SPI_CMD register, offset: 0x36 */
    } FIFO;
    __IO uint32_t PUSHR;                             /**< PUSH TX FIFO Register In Master Mode, offset: 0x34 */
    __IO uint32_t PUSHR_SLAVE;                       /**< PUSH TX FIFO Register In Slave Mode, offset: 0x34 */
  } PUSHR;
  __I  uint32_t POPR;                              /**< POP RX FIFO Register, offset: 0x38 */
  __I  uint32_t TXFR[SPI_TXFR_COUNT];              /**< Transmit FIFO Registers, array offset: 0x3C, array step: 0x4 */
  uint8_t RESERVED_2[44];
  __I  uint32_t RXFR[SPI_RXFR_COUNT];              /**< Receive FIFO Registers, array offset: 0x7C, array step: 0x4 */
  uint8_t RESERVED_3[140];
  __IO uint32_t CTARE[SPI_CTARE_COUNT];            /**< Clock and Transfer Attributes Register Extended, array offset: 0x11C, array step: 0x4 */
  uint8_t RESERVED_4[8];
  __I  uint32_t SREX;                              /**< Status Register Extended, offset: 0x13C */
} SPI_Type, *SPI_MemMapPtr;

/** Number of instances of the SPI module. */
#define SPI_INSTANCE_COUNT                       (10)

/* SPI - Peripheral instance base addresses */
/** Peripheral SPI_0 base address */
#define IP_SPI_0_BASE                            (0x40130000u)
/** Peripheral SPI_0 base pointer */
#define IP_SPI_0                                 ((SPI_Type *)IP_SPI_0_BASE)
/** Peripheral SPI_1 base address */
#define IP_SPI_1_BASE                            (0x40140000u)
/** Peripheral SPI_1 base pointer */
#define IP_SPI_1                                 ((SPI_Type *)IP_SPI_1_BASE)
/** Peripheral SPI_2 base address */
#define IP_SPI_2_BASE                            (0x40930000u)
/** Peripheral SPI_2 base pointer */
#define IP_SPI_2                                 ((SPI_Type *)IP_SPI_2_BASE)
/** Peripheral SPI_3 base address */
#define IP_SPI_3_BASE                            (0x40940000u)
/** Peripheral SPI_3 base pointer */
#define IP_SPI_3                                 ((SPI_Type *)IP_SPI_3_BASE)
/** Peripheral SPI_4 base address */
#define IP_SPI_4_BASE                            (0x40950000u)
/** Peripheral SPI_4 base pointer */
#define IP_SPI_4                                 ((SPI_Type *)IP_SPI_4_BASE)
/** Peripheral SPI_5 base address */
#define IP_SPI_5_BASE                            (0x42130000u)
/** Peripheral SPI_5 base pointer */
#define IP_SPI_5                                 ((SPI_Type *)IP_SPI_5_BASE)
/** Peripheral SPI_6 base address */
#define IP_SPI_6_BASE                            (0x42140000u)
/** Peripheral SPI_6 base pointer */
#define IP_SPI_6                                 ((SPI_Type *)IP_SPI_6_BASE)
/** Peripheral SPI_7 base address */
#define IP_SPI_7_BASE                            (0x42150000u)
/** Peripheral SPI_7 base pointer */
#define IP_SPI_7                                 ((SPI_Type *)IP_SPI_7_BASE)
/** Peripheral SPI_8 base address */
#define IP_SPI_8_BASE                            (0x42930000u)
/** Peripheral SPI_8 base pointer */
#define IP_SPI_8                                 ((SPI_Type *)IP_SPI_8_BASE)
/** Peripheral SPI_9 base address */
#define IP_SPI_9_BASE                            (0x42940000u)
/** Peripheral SPI_9 base pointer */
#define IP_SPI_9                                 ((SPI_Type *)IP_SPI_9_BASE)
/** Array initializer of SPI peripheral base addresses */
#define IP_SPI_BASE_ADDRS                        { IP_SPI_0_BASE, IP_SPI_1_BASE, IP_SPI_2_BASE, IP_SPI_3_BASE, IP_SPI_4_BASE, IP_SPI_5_BASE, IP_SPI_6_BASE, IP_SPI_7_BASE, IP_SPI_8_BASE, IP_SPI_9_BASE }
/** Array initializer of SPI peripheral base pointers */
#define IP_SPI_BASE_PTRS                         { IP_SPI_0, IP_SPI_1, IP_SPI_2, IP_SPI_3, IP_SPI_4, IP_SPI_5, IP_SPI_6, IP_SPI_7, IP_SPI_8, IP_SPI_9 }

/* ----------------------------------------------------------------------------
   -- SPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI_Register_Masks SPI Register Masks
 * @{
 */

/*! @name MCR - Module Configuration Register */
/*! @{ */

#define SPI_MCR_HALT_MASK                        (0x1U)
#define SPI_MCR_HALT_SHIFT                       (0U)
#define SPI_MCR_HALT_WIDTH                       (1U)
#define SPI_MCR_HALT(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_MCR_HALT_SHIFT)) & SPI_MCR_HALT_MASK)

#define SPI_MCR_PES_MASK                         (0x2U)
#define SPI_MCR_PES_SHIFT                        (1U)
#define SPI_MCR_PES_WIDTH                        (1U)
#define SPI_MCR_PES(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_MCR_PES_SHIFT)) & SPI_MCR_PES_MASK)

#define SPI_MCR_FCPCS_MASK                       (0x4U)
#define SPI_MCR_FCPCS_SHIFT                      (2U)
#define SPI_MCR_FCPCS_WIDTH                      (1U)
#define SPI_MCR_FCPCS(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_MCR_FCPCS_SHIFT)) & SPI_MCR_FCPCS_MASK)

#define SPI_MCR_XSPI_MASK                        (0x8U)
#define SPI_MCR_XSPI_SHIFT                       (3U)
#define SPI_MCR_XSPI_WIDTH                       (1U)
#define SPI_MCR_XSPI(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_MCR_XSPI_SHIFT)) & SPI_MCR_XSPI_MASK)

#define SPI_MCR_SMPL_PT_MASK                     (0x300U)
#define SPI_MCR_SMPL_PT_SHIFT                    (8U)
#define SPI_MCR_SMPL_PT_WIDTH                    (2U)
#define SPI_MCR_SMPL_PT(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_MCR_SMPL_PT_SHIFT)) & SPI_MCR_SMPL_PT_MASK)

#define SPI_MCR_CLR_RXF_MASK                     (0x400U)
#define SPI_MCR_CLR_RXF_SHIFT                    (10U)
#define SPI_MCR_CLR_RXF_WIDTH                    (1U)
#define SPI_MCR_CLR_RXF(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_MCR_CLR_RXF_SHIFT)) & SPI_MCR_CLR_RXF_MASK)

#define SPI_MCR_CLR_TXF_MASK                     (0x800U)
#define SPI_MCR_CLR_TXF_SHIFT                    (11U)
#define SPI_MCR_CLR_TXF_WIDTH                    (1U)
#define SPI_MCR_CLR_TXF(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_MCR_CLR_TXF_SHIFT)) & SPI_MCR_CLR_TXF_MASK)

#define SPI_MCR_DIS_RXF_MASK                     (0x1000U)
#define SPI_MCR_DIS_RXF_SHIFT                    (12U)
#define SPI_MCR_DIS_RXF_WIDTH                    (1U)
#define SPI_MCR_DIS_RXF(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_MCR_DIS_RXF_SHIFT)) & SPI_MCR_DIS_RXF_MASK)

#define SPI_MCR_DIS_TXF_MASK                     (0x2000U)
#define SPI_MCR_DIS_TXF_SHIFT                    (13U)
#define SPI_MCR_DIS_TXF_WIDTH                    (1U)
#define SPI_MCR_DIS_TXF(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_MCR_DIS_TXF_SHIFT)) & SPI_MCR_DIS_TXF_MASK)

#define SPI_MCR_MDIS_MASK                        (0x4000U)
#define SPI_MCR_MDIS_SHIFT                       (14U)
#define SPI_MCR_MDIS_WIDTH                       (1U)
#define SPI_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_MCR_MDIS_SHIFT)) & SPI_MCR_MDIS_MASK)

#define SPI_MCR_PCSIS_MASK                       (0x1F0000U)
#define SPI_MCR_PCSIS_SHIFT                      (16U)
#define SPI_MCR_PCSIS_WIDTH                      (5U)
#define SPI_MCR_PCSIS(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_MCR_PCSIS_SHIFT)) & SPI_MCR_PCSIS_MASK)

#define SPI_MCR_ROOE_MASK                        (0x1000000U)
#define SPI_MCR_ROOE_SHIFT                       (24U)
#define SPI_MCR_ROOE_WIDTH                       (1U)
#define SPI_MCR_ROOE(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_MCR_ROOE_SHIFT)) & SPI_MCR_ROOE_MASK)

#define SPI_MCR_MTFE_MASK                        (0x4000000U)
#define SPI_MCR_MTFE_SHIFT                       (26U)
#define SPI_MCR_MTFE_WIDTH                       (1U)
#define SPI_MCR_MTFE(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_MCR_MTFE_SHIFT)) & SPI_MCR_MTFE_MASK)

#define SPI_MCR_FRZ_MASK                         (0x8000000U)
#define SPI_MCR_FRZ_SHIFT                        (27U)
#define SPI_MCR_FRZ_WIDTH                        (1U)
#define SPI_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_MCR_FRZ_SHIFT)) & SPI_MCR_FRZ_MASK)

#define SPI_MCR_DCONF_MASK                       (0x30000000U)
#define SPI_MCR_DCONF_SHIFT                      (28U)
#define SPI_MCR_DCONF_WIDTH                      (2U)
#define SPI_MCR_DCONF(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_MCR_DCONF_SHIFT)) & SPI_MCR_DCONF_MASK)

#define SPI_MCR_CONT_SCKE_MASK                   (0x40000000U)
#define SPI_MCR_CONT_SCKE_SHIFT                  (30U)
#define SPI_MCR_CONT_SCKE_WIDTH                  (1U)
#define SPI_MCR_CONT_SCKE(x)                     (((uint32_t)(((uint32_t)(x)) << SPI_MCR_CONT_SCKE_SHIFT)) & SPI_MCR_CONT_SCKE_MASK)

#define SPI_MCR_MSTR_MASK                        (0x80000000U)
#define SPI_MCR_MSTR_SHIFT                       (31U)
#define SPI_MCR_MSTR_WIDTH                       (1U)
#define SPI_MCR_MSTR(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_MCR_MSTR_SHIFT)) & SPI_MCR_MSTR_MASK)
/*! @} */

/*! @name TCR - Transfer Count Register */
/*! @{ */

#define SPI_TCR_SPI_TCNT_MASK                    (0xFFFF0000U)
#define SPI_TCR_SPI_TCNT_SHIFT                   (16U)
#define SPI_TCR_SPI_TCNT_WIDTH                   (16U)
#define SPI_TCR_SPI_TCNT(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_TCR_SPI_TCNT_SHIFT)) & SPI_TCR_SPI_TCNT_MASK)
/*! @} */

/*! @name CTAR - Clock and Transfer Attributes Register (in Master mode) */
/*! @{ */

#define SPI_CTAR_BR_MASK                         (0xFU)
#define SPI_CTAR_BR_SHIFT                        (0U)
#define SPI_CTAR_BR_WIDTH                        (4U)
#define SPI_CTAR_BR(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_BR_SHIFT)) & SPI_CTAR_BR_MASK)

#define SPI_CTAR_DT_MASK                         (0xF0U)
#define SPI_CTAR_DT_SHIFT                        (4U)
#define SPI_CTAR_DT_WIDTH                        (4U)
#define SPI_CTAR_DT(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_DT_SHIFT)) & SPI_CTAR_DT_MASK)

#define SPI_CTAR_ASC_MASK                        (0xF00U)
#define SPI_CTAR_ASC_SHIFT                       (8U)
#define SPI_CTAR_ASC_WIDTH                       (4U)
#define SPI_CTAR_ASC(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_ASC_SHIFT)) & SPI_CTAR_ASC_MASK)

#define SPI_CTAR_CSSCK_MASK                      (0xF000U)
#define SPI_CTAR_CSSCK_SHIFT                     (12U)
#define SPI_CTAR_CSSCK_WIDTH                     (4U)
#define SPI_CTAR_CSSCK(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_CSSCK_SHIFT)) & SPI_CTAR_CSSCK_MASK)

#define SPI_CTAR_PBR_MASK                        (0x30000U)
#define SPI_CTAR_PBR_SHIFT                       (16U)
#define SPI_CTAR_PBR_WIDTH                       (2U)
#define SPI_CTAR_PBR(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_PBR_SHIFT)) & SPI_CTAR_PBR_MASK)

#define SPI_CTAR_PDT_MASK                        (0xC0000U)
#define SPI_CTAR_PDT_SHIFT                       (18U)
#define SPI_CTAR_PDT_WIDTH                       (2U)
#define SPI_CTAR_PDT(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_PDT_SHIFT)) & SPI_CTAR_PDT_MASK)

#define SPI_CTAR_PASC_MASK                       (0x300000U)
#define SPI_CTAR_PASC_SHIFT                      (20U)
#define SPI_CTAR_PASC_WIDTH                      (2U)
#define SPI_CTAR_PASC(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_PASC_SHIFT)) & SPI_CTAR_PASC_MASK)

#define SPI_CTAR_PCSSCK_MASK                     (0xC00000U)
#define SPI_CTAR_PCSSCK_SHIFT                    (22U)
#define SPI_CTAR_PCSSCK_WIDTH                    (2U)
#define SPI_CTAR_PCSSCK(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_PCSSCK_SHIFT)) & SPI_CTAR_PCSSCK_MASK)

#define SPI_CTAR_LSBFE_MASK                      (0x1000000U)
#define SPI_CTAR_LSBFE_SHIFT                     (24U)
#define SPI_CTAR_LSBFE_WIDTH                     (1U)
#define SPI_CTAR_LSBFE(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_LSBFE_SHIFT)) & SPI_CTAR_LSBFE_MASK)

#define SPI_CTAR_CPHA_MASK                       (0x2000000U)
#define SPI_CTAR_CPHA_SHIFT                      (25U)
#define SPI_CTAR_CPHA_WIDTH                      (1U)
#define SPI_CTAR_CPHA(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_CPHA_SHIFT)) & SPI_CTAR_CPHA_MASK)

#define SPI_CTAR_CPOL_MASK                       (0x4000000U)
#define SPI_CTAR_CPOL_SHIFT                      (26U)
#define SPI_CTAR_CPOL_WIDTH                      (1U)
#define SPI_CTAR_CPOL(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_CPOL_SHIFT)) & SPI_CTAR_CPOL_MASK)

#define SPI_CTAR_FMSZ_MASK                       (0x78000000U)
#define SPI_CTAR_FMSZ_SHIFT                      (27U)
#define SPI_CTAR_FMSZ_WIDTH                      (4U)
#define SPI_CTAR_FMSZ(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_FMSZ_SHIFT)) & SPI_CTAR_FMSZ_MASK)

#define SPI_CTAR_DBR_MASK                        (0x80000000U)
#define SPI_CTAR_DBR_SHIFT                       (31U)
#define SPI_CTAR_DBR_WIDTH                       (1U)
#define SPI_CTAR_DBR(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_DBR_SHIFT)) & SPI_CTAR_DBR_MASK)
/*! @} */

/*! @name CTAR_SLAVE - Clock and Transfer Attributes Register (in Slave mode) */
/*! @{ */

#define SPI_CTAR_SLAVE_PP_MASK                   (0x800000U)
#define SPI_CTAR_SLAVE_PP_SHIFT                  (23U)
#define SPI_CTAR_SLAVE_PP_WIDTH                  (1U)
#define SPI_CTAR_SLAVE_PP(x)                     (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_SLAVE_PP_SHIFT)) & SPI_CTAR_SLAVE_PP_MASK)

#define SPI_CTAR_SLAVE_PE_MASK                   (0x1000000U)
#define SPI_CTAR_SLAVE_PE_SHIFT                  (24U)
#define SPI_CTAR_SLAVE_PE_WIDTH                  (1U)
#define SPI_CTAR_SLAVE_PE(x)                     (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_SLAVE_PE_SHIFT)) & SPI_CTAR_SLAVE_PE_MASK)

#define SPI_CTAR_SLAVE_CPHA_MASK                 (0x2000000U)
#define SPI_CTAR_SLAVE_CPHA_SHIFT                (25U)
#define SPI_CTAR_SLAVE_CPHA_WIDTH                (1U)
#define SPI_CTAR_SLAVE_CPHA(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_SLAVE_CPHA_SHIFT)) & SPI_CTAR_SLAVE_CPHA_MASK)

#define SPI_CTAR_SLAVE_CPOL_MASK                 (0x4000000U)
#define SPI_CTAR_SLAVE_CPOL_SHIFT                (26U)
#define SPI_CTAR_SLAVE_CPOL_WIDTH                (1U)
#define SPI_CTAR_SLAVE_CPOL(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_SLAVE_CPOL_SHIFT)) & SPI_CTAR_SLAVE_CPOL_MASK)

#define SPI_CTAR_SLAVE_FMSZ_MASK                 (0xF8000000U)
#define SPI_CTAR_SLAVE_FMSZ_SHIFT                (27U)
#define SPI_CTAR_SLAVE_FMSZ_WIDTH                (5U)
#define SPI_CTAR_SLAVE_FMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_SLAVE_FMSZ_SHIFT)) & SPI_CTAR_SLAVE_FMSZ_MASK)
/*! @} */

/*! @name SR - Status Register */
/*! @{ */

#define SPI_SR_POPNXTPTR_MASK                    (0xFU)
#define SPI_SR_POPNXTPTR_SHIFT                   (0U)
#define SPI_SR_POPNXTPTR_WIDTH                   (4U)
#define SPI_SR_POPNXTPTR(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_SR_POPNXTPTR_SHIFT)) & SPI_SR_POPNXTPTR_MASK)

#define SPI_SR_RXCTR_MASK                        (0xF0U)
#define SPI_SR_RXCTR_SHIFT                       (4U)
#define SPI_SR_RXCTR_WIDTH                       (4U)
#define SPI_SR_RXCTR(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_SR_RXCTR_SHIFT)) & SPI_SR_RXCTR_MASK)

#define SPI_SR_TXNXTPTR_MASK                     (0xF00U)
#define SPI_SR_TXNXTPTR_SHIFT                    (8U)
#define SPI_SR_TXNXTPTR_WIDTH                    (4U)
#define SPI_SR_TXNXTPTR(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_SR_TXNXTPTR_SHIFT)) & SPI_SR_TXNXTPTR_MASK)

#define SPI_SR_TXCTR_MASK                        (0xF000U)
#define SPI_SR_TXCTR_SHIFT                       (12U)
#define SPI_SR_TXCTR_WIDTH                       (4U)
#define SPI_SR_TXCTR(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_SR_TXCTR_SHIFT)) & SPI_SR_TXCTR_MASK)

#define SPI_SR_CMDFFF_MASK                       (0x10000U)
#define SPI_SR_CMDFFF_SHIFT                      (16U)
#define SPI_SR_CMDFFF_WIDTH                      (1U)
#define SPI_SR_CMDFFF(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_SR_CMDFFF_SHIFT)) & SPI_SR_CMDFFF_MASK)

#define SPI_SR_RFDF_MASK                         (0x20000U)
#define SPI_SR_RFDF_SHIFT                        (17U)
#define SPI_SR_RFDF_WIDTH                        (1U)
#define SPI_SR_RFDF(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_SR_RFDF_SHIFT)) & SPI_SR_RFDF_MASK)

#define SPI_SR_TFIWF_MASK                        (0x40000U)
#define SPI_SR_TFIWF_SHIFT                       (18U)
#define SPI_SR_TFIWF_WIDTH                       (1U)
#define SPI_SR_TFIWF(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_SR_TFIWF_SHIFT)) & SPI_SR_TFIWF_MASK)

#define SPI_SR_RFOF_MASK                         (0x80000U)
#define SPI_SR_RFOF_SHIFT                        (19U)
#define SPI_SR_RFOF_WIDTH                        (1U)
#define SPI_SR_RFOF(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_SR_RFOF_SHIFT)) & SPI_SR_RFOF_MASK)

#define SPI_SR_SPEF_MASK                         (0x200000U)
#define SPI_SR_SPEF_SHIFT                        (21U)
#define SPI_SR_SPEF_WIDTH                        (1U)
#define SPI_SR_SPEF(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_SR_SPEF_SHIFT)) & SPI_SR_SPEF_MASK)

#define SPI_SR_CMDTCF_MASK                       (0x800000U)
#define SPI_SR_CMDTCF_SHIFT                      (23U)
#define SPI_SR_CMDTCF_WIDTH                      (1U)
#define SPI_SR_CMDTCF(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_SR_CMDTCF_SHIFT)) & SPI_SR_CMDTCF_MASK)

#define SPI_SR_BSYF_MASK                         (0x1000000U)
#define SPI_SR_BSYF_SHIFT                        (24U)
#define SPI_SR_BSYF_WIDTH                        (1U)
#define SPI_SR_BSYF(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_SR_BSYF_SHIFT)) & SPI_SR_BSYF_MASK)

#define SPI_SR_TFFF_MASK                         (0x2000000U)
#define SPI_SR_TFFF_SHIFT                        (25U)
#define SPI_SR_TFFF_WIDTH                        (1U)
#define SPI_SR_TFFF(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_SR_TFFF_SHIFT)) & SPI_SR_TFFF_MASK)

#define SPI_SR_TFUF_MASK                         (0x8000000U)
#define SPI_SR_TFUF_SHIFT                        (27U)
#define SPI_SR_TFUF_WIDTH                        (1U)
#define SPI_SR_TFUF(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_SR_TFUF_SHIFT)) & SPI_SR_TFUF_MASK)

#define SPI_SR_EOQF_MASK                         (0x10000000U)
#define SPI_SR_EOQF_SHIFT                        (28U)
#define SPI_SR_EOQF_WIDTH                        (1U)
#define SPI_SR_EOQF(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_SR_EOQF_SHIFT)) & SPI_SR_EOQF_MASK)

#define SPI_SR_TXRXS_MASK                        (0x40000000U)
#define SPI_SR_TXRXS_SHIFT                       (30U)
#define SPI_SR_TXRXS_WIDTH                       (1U)
#define SPI_SR_TXRXS(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_SR_TXRXS_SHIFT)) & SPI_SR_TXRXS_MASK)

#define SPI_SR_TCF_MASK                          (0x80000000U)
#define SPI_SR_TCF_SHIFT                         (31U)
#define SPI_SR_TCF_WIDTH                         (1U)
#define SPI_SR_TCF(x)                            (((uint32_t)(((uint32_t)(x)) << SPI_SR_TCF_SHIFT)) & SPI_SR_TCF_MASK)
/*! @} */

/*! @name RSER - DMA/Interrupt Request Select and Enable Register */
/*! @{ */

#define SPI_RSER_CMDFFF_DIRS_MASK                (0x8000U)
#define SPI_RSER_CMDFFF_DIRS_SHIFT               (15U)
#define SPI_RSER_CMDFFF_DIRS_WIDTH               (1U)
#define SPI_RSER_CMDFFF_DIRS(x)                  (((uint32_t)(((uint32_t)(x)) << SPI_RSER_CMDFFF_DIRS_SHIFT)) & SPI_RSER_CMDFFF_DIRS_MASK)

#define SPI_RSER_RFDF_DIRS_MASK                  (0x10000U)
#define SPI_RSER_RFDF_DIRS_SHIFT                 (16U)
#define SPI_RSER_RFDF_DIRS_WIDTH                 (1U)
#define SPI_RSER_RFDF_DIRS(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_RSER_RFDF_DIRS_SHIFT)) & SPI_RSER_RFDF_DIRS_MASK)

#define SPI_RSER_RFDF_RE_MASK                    (0x20000U)
#define SPI_RSER_RFDF_RE_SHIFT                   (17U)
#define SPI_RSER_RFDF_RE_WIDTH                   (1U)
#define SPI_RSER_RFDF_RE(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_RSER_RFDF_RE_SHIFT)) & SPI_RSER_RFDF_RE_MASK)

#define SPI_RSER_TFIWF_RE_MASK                   (0x40000U)
#define SPI_RSER_TFIWF_RE_SHIFT                  (18U)
#define SPI_RSER_TFIWF_RE_WIDTH                  (1U)
#define SPI_RSER_TFIWF_RE(x)                     (((uint32_t)(((uint32_t)(x)) << SPI_RSER_TFIWF_RE_SHIFT)) & SPI_RSER_TFIWF_RE_MASK)

#define SPI_RSER_RFOF_RE_MASK                    (0x80000U)
#define SPI_RSER_RFOF_RE_SHIFT                   (19U)
#define SPI_RSER_RFOF_RE_WIDTH                   (1U)
#define SPI_RSER_RFOF_RE(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_RSER_RFOF_RE_SHIFT)) & SPI_RSER_RFOF_RE_MASK)

#define SPI_RSER_SPEF_RE_MASK                    (0x200000U)
#define SPI_RSER_SPEF_RE_SHIFT                   (21U)
#define SPI_RSER_SPEF_RE_WIDTH                   (1U)
#define SPI_RSER_SPEF_RE(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_RSER_SPEF_RE_SHIFT)) & SPI_RSER_SPEF_RE_MASK)

#define SPI_RSER_CMDTCF_RE_MASK                  (0x800000U)
#define SPI_RSER_CMDTCF_RE_SHIFT                 (23U)
#define SPI_RSER_CMDTCF_RE_WIDTH                 (1U)
#define SPI_RSER_CMDTCF_RE(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_RSER_CMDTCF_RE_SHIFT)) & SPI_RSER_CMDTCF_RE_MASK)

#define SPI_RSER_TFFF_DIRS_MASK                  (0x1000000U)
#define SPI_RSER_TFFF_DIRS_SHIFT                 (24U)
#define SPI_RSER_TFFF_DIRS_WIDTH                 (1U)
#define SPI_RSER_TFFF_DIRS(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_RSER_TFFF_DIRS_SHIFT)) & SPI_RSER_TFFF_DIRS_MASK)

#define SPI_RSER_TFFF_RE_MASK                    (0x2000000U)
#define SPI_RSER_TFFF_RE_SHIFT                   (25U)
#define SPI_RSER_TFFF_RE_WIDTH                   (1U)
#define SPI_RSER_TFFF_RE(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_RSER_TFFF_RE_SHIFT)) & SPI_RSER_TFFF_RE_MASK)

#define SPI_RSER_TFUF_RE_MASK                    (0x8000000U)
#define SPI_RSER_TFUF_RE_SHIFT                   (27U)
#define SPI_RSER_TFUF_RE_WIDTH                   (1U)
#define SPI_RSER_TFUF_RE(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_RSER_TFUF_RE_SHIFT)) & SPI_RSER_TFUF_RE_MASK)

#define SPI_RSER_EOQF_RE_MASK                    (0x10000000U)
#define SPI_RSER_EOQF_RE_SHIFT                   (28U)
#define SPI_RSER_EOQF_RE_WIDTH                   (1U)
#define SPI_RSER_EOQF_RE(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_RSER_EOQF_RE_SHIFT)) & SPI_RSER_EOQF_RE_MASK)

#define SPI_RSER_CMDFFF_RE_MASK                  (0x40000000U)
#define SPI_RSER_CMDFFF_RE_SHIFT                 (30U)
#define SPI_RSER_CMDFFF_RE_WIDTH                 (1U)
#define SPI_RSER_CMDFFF_RE(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_RSER_CMDFFF_RE_SHIFT)) & SPI_RSER_CMDFFF_RE_MASK)

#define SPI_RSER_TCF_RE_MASK                     (0x80000000U)
#define SPI_RSER_TCF_RE_SHIFT                    (31U)
#define SPI_RSER_TCF_RE_WIDTH                    (1U)
#define SPI_RSER_TCF_RE(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_RSER_TCF_RE_SHIFT)) & SPI_RSER_TCF_RE_MASK)
/*! @} */

/*! @name TX - SPI_TX register */
/*! @{ */

#define SPI_TX_TX_MASK                           (0xFFFFU)
#define SPI_TX_TX_SHIFT                          (0U)
#define SPI_TX_TX_WIDTH                          (16U)
#define SPI_TX_TX(x)                             (((uint16_t)(((uint16_t)(x)) << SPI_TX_TX_SHIFT)) & SPI_TX_TX_MASK)
/*! @} */

/*! @name CMD - SPI_CMD register */
/*! @{ */

#define SPI_CMD_CMD_MASK                         (0xFFFFU)
#define SPI_CMD_CMD_SHIFT                        (0U)
#define SPI_CMD_CMD_WIDTH                        (16U)
#define SPI_CMD_CMD(x)                           (((uint16_t)(((uint16_t)(x)) << SPI_CMD_CMD_SHIFT)) & SPI_CMD_CMD_MASK)
/*! @} */

/*! @name PUSHR - PUSH TX FIFO Register In Master Mode */
/*! @{ */

#define SPI_PUSHR_TXDATA_MASK                    (0xFFFFU)
#define SPI_PUSHR_TXDATA_SHIFT                   (0U)
#define SPI_PUSHR_TXDATA_WIDTH                   (16U)
#define SPI_PUSHR_TXDATA(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_PUSHR_TXDATA_SHIFT)) & SPI_PUSHR_TXDATA_MASK)

#define SPI_PUSHR_PCS_MASK                       (0x1F0000U)
#define SPI_PUSHR_PCS_SHIFT                      (16U)
#define SPI_PUSHR_PCS_WIDTH                      (5U)
#define SPI_PUSHR_PCS(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_PUSHR_PCS_SHIFT)) & SPI_PUSHR_PCS_MASK)

#define SPI_PUSHR_PP_MCSC_MASK                   (0x1000000U)
#define SPI_PUSHR_PP_MCSC_SHIFT                  (24U)
#define SPI_PUSHR_PP_MCSC_WIDTH                  (1U)
#define SPI_PUSHR_PP_MCSC(x)                     (((uint32_t)(((uint32_t)(x)) << SPI_PUSHR_PP_MCSC_SHIFT)) & SPI_PUSHR_PP_MCSC_MASK)

#define SPI_PUSHR_PE_MASC_MASK                   (0x2000000U)
#define SPI_PUSHR_PE_MASC_SHIFT                  (25U)
#define SPI_PUSHR_PE_MASC_WIDTH                  (1U)
#define SPI_PUSHR_PE_MASC(x)                     (((uint32_t)(((uint32_t)(x)) << SPI_PUSHR_PE_MASC_SHIFT)) & SPI_PUSHR_PE_MASC_MASK)

#define SPI_PUSHR_CTCNT_MASK                     (0x4000000U)
#define SPI_PUSHR_CTCNT_SHIFT                    (26U)
#define SPI_PUSHR_CTCNT_WIDTH                    (1U)
#define SPI_PUSHR_CTCNT(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_PUSHR_CTCNT_SHIFT)) & SPI_PUSHR_CTCNT_MASK)

#define SPI_PUSHR_EOQ_MASK                       (0x8000000U)
#define SPI_PUSHR_EOQ_SHIFT                      (27U)
#define SPI_PUSHR_EOQ_WIDTH                      (1U)
#define SPI_PUSHR_EOQ(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_PUSHR_EOQ_SHIFT)) & SPI_PUSHR_EOQ_MASK)

#define SPI_PUSHR_CTAS_MASK                      (0x70000000U)
#define SPI_PUSHR_CTAS_SHIFT                     (28U)
#define SPI_PUSHR_CTAS_WIDTH                     (3U)
#define SPI_PUSHR_CTAS(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_PUSHR_CTAS_SHIFT)) & SPI_PUSHR_CTAS_MASK)

#define SPI_PUSHR_CONT_MASK                      (0x80000000U)
#define SPI_PUSHR_CONT_SHIFT                     (31U)
#define SPI_PUSHR_CONT_WIDTH                     (1U)
#define SPI_PUSHR_CONT(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_PUSHR_CONT_SHIFT)) & SPI_PUSHR_CONT_MASK)
/*! @} */

/*! @name PUSHR_SLAVE - PUSH TX FIFO Register In Slave Mode */
/*! @{ */

#define SPI_PUSHR_SLAVE_TXDATA_MASK              (0xFFFFU)
#define SPI_PUSHR_SLAVE_TXDATA_SHIFT             (0U)
#define SPI_PUSHR_SLAVE_TXDATA_WIDTH             (16U)
#define SPI_PUSHR_SLAVE_TXDATA(x)                (((uint32_t)(((uint32_t)(x)) << SPI_PUSHR_SLAVE_TXDATA_SHIFT)) & SPI_PUSHR_SLAVE_TXDATA_MASK)
/*! @} */

/*! @name POPR - POP RX FIFO Register */
/*! @{ */

#define SPI_POPR_RXDATA_MASK                     (0xFFFFFFFFU)
#define SPI_POPR_RXDATA_SHIFT                    (0U)
#define SPI_POPR_RXDATA_WIDTH                    (32U)
#define SPI_POPR_RXDATA(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_POPR_RXDATA_SHIFT)) & SPI_POPR_RXDATA_MASK)
/*! @} */

/*! @name TXFR - Transmit FIFO Registers */
/*! @{ */

#define SPI_TXFR_TXDATA_MASK                     (0xFFFFU)
#define SPI_TXFR_TXDATA_SHIFT                    (0U)
#define SPI_TXFR_TXDATA_WIDTH                    (16U)
#define SPI_TXFR_TXDATA(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_TXFR_TXDATA_SHIFT)) & SPI_TXFR_TXDATA_MASK)

#define SPI_TXFR_TXCMD_TXDATA_MASK               (0xFFFF0000U)
#define SPI_TXFR_TXCMD_TXDATA_SHIFT              (16U)
#define SPI_TXFR_TXCMD_TXDATA_WIDTH              (16U)
#define SPI_TXFR_TXCMD_TXDATA(x)                 (((uint32_t)(((uint32_t)(x)) << SPI_TXFR_TXCMD_TXDATA_SHIFT)) & SPI_TXFR_TXCMD_TXDATA_MASK)
/*! @} */

/*! @name RXFR - Receive FIFO Registers */
/*! @{ */

#define SPI_RXFR_RXDATA_MASK                     (0xFFFFFFFFU)
#define SPI_RXFR_RXDATA_SHIFT                    (0U)
#define SPI_RXFR_RXDATA_WIDTH                    (32U)
#define SPI_RXFR_RXDATA(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_RXFR_RXDATA_SHIFT)) & SPI_RXFR_RXDATA_MASK)
/*! @} */

/*! @name CTARE - Clock and Transfer Attributes Register Extended */
/*! @{ */

#define SPI_CTARE_DTCP_MASK                      (0x7FFU)
#define SPI_CTARE_DTCP_SHIFT                     (0U)
#define SPI_CTARE_DTCP_WIDTH                     (11U)
#define SPI_CTARE_DTCP(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_CTARE_DTCP_SHIFT)) & SPI_CTARE_DTCP_MASK)

#define SPI_CTARE_FMSZE_MASK                     (0x10000U)
#define SPI_CTARE_FMSZE_SHIFT                    (16U)
#define SPI_CTARE_FMSZE_WIDTH                    (1U)
#define SPI_CTARE_FMSZE(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_CTARE_FMSZE_SHIFT)) & SPI_CTARE_FMSZE_MASK)
/*! @} */

/*! @name SREX - Status Register Extended */
/*! @{ */

#define SPI_SREX_CMDNXTPTR_MASK                  (0xFU)
#define SPI_SREX_CMDNXTPTR_SHIFT                 (0U)
#define SPI_SREX_CMDNXTPTR_WIDTH                 (4U)
#define SPI_SREX_CMDNXTPTR(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_SREX_CMDNXTPTR_SHIFT)) & SPI_SREX_CMDNXTPTR_MASK)

#define SPI_SREX_CMDCTR_MASK                     (0x1F0U)
#define SPI_SREX_CMDCTR_SHIFT                    (4U)
#define SPI_SREX_CMDCTR_WIDTH                    (5U)
#define SPI_SREX_CMDCTR(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_SREX_CMDCTR_SHIFT)) & SPI_SREX_CMDCTR_MASK)

#define SPI_SREX_RXCTR4_MASK                     (0x800U)
#define SPI_SREX_RXCTR4_SHIFT                    (11U)
#define SPI_SREX_RXCTR4_WIDTH                    (1U)
#define SPI_SREX_RXCTR4(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_SREX_RXCTR4_SHIFT)) & SPI_SREX_RXCTR4_MASK)

#define SPI_SREX_TXCTR4_MASK                     (0x4000U)
#define SPI_SREX_TXCTR4_SHIFT                    (14U)
#define SPI_SREX_TXCTR4_WIDTH                    (1U)
#define SPI_SREX_TXCTR4(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_SREX_TXCTR4_SHIFT)) & SPI_SREX_TXCTR4_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SPI_Register_Masks */

/*!
 * @}
 */ /* end of group SPI_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_SPI_H_) */
