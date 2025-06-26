/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_DSPI.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_DSPI
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
#if !defined(S32Z2_DSPI_H_)  /* Check if memory map has not been already included */
#define S32Z2_DSPI_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- DSPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSPI_Peripheral_Access_Layer DSPI Peripheral Access Layer
 * @{
 */

/** DSPI - Size of Registers Arrays */
#define DSPI_MODE_CTAR_CTAR_COUNT                 6u
#define DSPI_TXFR_COUNT                           16u
#define DSPI_RXFR_COUNT                           16u
#define DSPI_CTARE_COUNT                          6u

/** DSPI - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< Module Configuration Register, offset: 0x0 */
  uint8_t RESERVED_0[4];
  __IO uint32_t TCR;                               /**< Transfer Count Register, offset: 0x8 */
  union {                                          /* offset: 0xC */
    __IO uint32_t CTAR[DSPI_MODE_CTAR_CTAR_COUNT];   /**< Clock and Transfer Attributes Register (In Master Mode), array offset: 0xC, array step: 0x4 */
  } MODE;
  uint8_t RESERVED_1[8];
  __IO uint32_t SR;                                /**< Status Register, offset: 0x2C */
  __IO uint32_t RSER;                              /**< DMA/Interrupt Request Select and Enable Register, offset: 0x30 */
  union {                                          /* offset: 0x34 */
    struct DSPI_PUSHR_FIFO {                         /* offset: 0x34 */
      __IO uint16_t TX;                                /**< DSPI_TX register, offset: 0x34 */
      __IO uint16_t CMD;                               /**< DSPI_CMD register, offset: 0x36 */
    } FIFO;
    __IO uint32_t PUSHR;                             /**< PUSH TX FIFO Register In Master Mode, offset: 0x34 */
  } PUSHR;
  __I  uint32_t POPR;                              /**< POP RX FIFO Register, offset: 0x38 */
  __I  uint32_t TXFR[DSPI_TXFR_COUNT];             /**< Transmit FIFO Registers, array offset: 0x3C, array step: 0x4 */
  __I  uint32_t RXFR[DSPI_RXFR_COUNT];             /**< Receive FIFO Registers, array offset: 0x7C, array step: 0x4 */
  __IO uint32_t DSICR0;                            /**< DSI Configuration Register 0, offset: 0xBC */
  __I  uint32_t SDR0;                              /**< DSI Serialization Data Register 0, offset: 0xC0 */
  __IO uint32_t ASDR0;                             /**< DSI Alternate Serialization Data Register 0, offset: 0xC4 */
  __I  uint32_t COMPR0;                            /**< DSI Transmit Comparison Register 0, offset: 0xC8 */
  __I  uint32_t DDR0;                              /**< DSI Deserialization Data Register 0, offset: 0xCC */
  __IO uint32_t DSICR1;                            /**< DSI Configuration Register 1, offset: 0xD0 */
  __IO uint32_t SSR0;                              /**< DSI Serialization Source Select Register 0, offset: 0xD4 */
  uint8_t RESERVED_2[16];
  __IO uint32_t DIMR0;                             /**< DSI Deserialized Data Interrupt Mask Register 0, offset: 0xE8 */
  __IO uint32_t DPIR0;                             /**< DSI Deserialized Data Polarity Interrupt Register 0, offset: 0xEC */
  __I  uint32_t SDR1;                              /**< DSI Serialization Data Register 1, offset: 0xF0 */
  __IO uint32_t ASDR1;                             /**< DSI Alternate Serialization Data Register 1, offset: 0xF4 */
  __I  uint32_t COMPR1;                            /**< DSI Transmit Comparison Register 1, offset: 0xF8 */
  __I  uint32_t DDR1;                              /**< DSI Deserialization Data Register 1, offset: 0xFC */
  __IO uint32_t SSR1;                              /**< DSI Serialization Source Select Register 1, offset: 0x100 */
  uint8_t RESERVED_3[16];
  __IO uint32_t DIMR1;                             /**< DSI Deserialized Data Interrupt Mask Register 1, offset: 0x114 */
  __IO uint32_t DPIR1;                             /**< DSI Deserialized Data Polarity Interrupt Register 1, offset: 0x118 */
  __IO uint32_t CTARE[DSPI_CTARE_COUNT];           /**< Clock and Transfer Attributes Register Extended, array offset: 0x11C, array step: 0x4 */
  uint8_t RESERVED_4[8];
  __I  uint32_t SREX;                              /**< Status Register Extended, offset: 0x13C */
  uint8_t RESERVED_5[16];
  __IO uint32_t TSL;                               /**< Time Slot Length Register, offset: 0x150 */
  __IO uint32_t TS_CONF;                           /**< Time Slot Configuration Register, offset: 0x154 */
} DSPI_Type, *DSPI_MemMapPtr;

/** Number of instances of the DSPI module. */
#define DSPI_INSTANCE_COUNT                      (1u)

/* DSPI - Peripheral instance base addresses */
/** Peripheral MSC_0_DSPI base address */
#define IP_MSC_0_DSPI_BASE                       (0x40340000u)
/** Peripheral MSC_0_DSPI base pointer */
#define IP_MSC_0_DSPI                            ((DSPI_Type *)IP_MSC_0_DSPI_BASE)
/** Array initializer of DSPI peripheral base addresses */
#define IP_DSPI_BASE_ADDRS                       { IP_MSC_0_DSPI_BASE }
/** Array initializer of DSPI peripheral base pointers */
#define IP_DSPI_BASE_PTRS                        { IP_MSC_0_DSPI }

/* ----------------------------------------------------------------------------
   -- DSPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSPI_Register_Masks DSPI Register Masks
 * @{
 */

/*! @name MCR - Module Configuration Register */
/*! @{ */

#define DSPI_MCR_HALT_MASK                       (0x1U)
#define DSPI_MCR_HALT_SHIFT                      (0U)
#define DSPI_MCR_HALT_WIDTH                      (1U)
#define DSPI_MCR_HALT(x)                         (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_HALT_SHIFT)) & DSPI_MCR_HALT_MASK)

#define DSPI_MCR_PES_MASK                        (0x2U)
#define DSPI_MCR_PES_SHIFT                       (1U)
#define DSPI_MCR_PES_WIDTH                       (1U)
#define DSPI_MCR_PES(x)                          (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_PES_SHIFT)) & DSPI_MCR_PES_MASK)

#define DSPI_MCR_FCPCS_MASK                      (0x4U)
#define DSPI_MCR_FCPCS_SHIFT                     (2U)
#define DSPI_MCR_FCPCS_WIDTH                     (1U)
#define DSPI_MCR_FCPCS(x)                        (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_FCPCS_SHIFT)) & DSPI_MCR_FCPCS_MASK)

#define DSPI_MCR_XSPI_MASK                       (0x8U)
#define DSPI_MCR_XSPI_SHIFT                      (3U)
#define DSPI_MCR_XSPI_WIDTH                      (1U)
#define DSPI_MCR_XSPI(x)                         (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_XSPI_SHIFT)) & DSPI_MCR_XSPI_MASK)

#define DSPI_MCR_SMPL_PT_MASK                    (0x300U)
#define DSPI_MCR_SMPL_PT_SHIFT                   (8U)
#define DSPI_MCR_SMPL_PT_WIDTH                   (2U)
#define DSPI_MCR_SMPL_PT(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_SMPL_PT_SHIFT)) & DSPI_MCR_SMPL_PT_MASK)

#define DSPI_MCR_CLR_RXF_MASK                    (0x400U)
#define DSPI_MCR_CLR_RXF_SHIFT                   (10U)
#define DSPI_MCR_CLR_RXF_WIDTH                   (1U)
#define DSPI_MCR_CLR_RXF(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_CLR_RXF_SHIFT)) & DSPI_MCR_CLR_RXF_MASK)

#define DSPI_MCR_CLR_TXF_MASK                    (0x800U)
#define DSPI_MCR_CLR_TXF_SHIFT                   (11U)
#define DSPI_MCR_CLR_TXF_WIDTH                   (1U)
#define DSPI_MCR_CLR_TXF(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_CLR_TXF_SHIFT)) & DSPI_MCR_CLR_TXF_MASK)

#define DSPI_MCR_DIS_RXF_MASK                    (0x1000U)
#define DSPI_MCR_DIS_RXF_SHIFT                   (12U)
#define DSPI_MCR_DIS_RXF_WIDTH                   (1U)
#define DSPI_MCR_DIS_RXF(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_DIS_RXF_SHIFT)) & DSPI_MCR_DIS_RXF_MASK)

#define DSPI_MCR_DIS_TXF_MASK                    (0x2000U)
#define DSPI_MCR_DIS_TXF_SHIFT                   (13U)
#define DSPI_MCR_DIS_TXF_WIDTH                   (1U)
#define DSPI_MCR_DIS_TXF(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_DIS_TXF_SHIFT)) & DSPI_MCR_DIS_TXF_MASK)

#define DSPI_MCR_MDIS_MASK                       (0x4000U)
#define DSPI_MCR_MDIS_SHIFT                      (14U)
#define DSPI_MCR_MDIS_WIDTH                      (1U)
#define DSPI_MCR_MDIS(x)                         (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_MDIS_SHIFT)) & DSPI_MCR_MDIS_MASK)

#define DSPI_MCR_PCSIS_MASK                      (0x70000U)
#define DSPI_MCR_PCSIS_SHIFT                     (16U)
#define DSPI_MCR_PCSIS_WIDTH                     (3U)
#define DSPI_MCR_PCSIS(x)                        (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_PCSIS_SHIFT)) & DSPI_MCR_PCSIS_MASK)

#define DSPI_MCR_ROOE_MASK                       (0x1000000U)
#define DSPI_MCR_ROOE_SHIFT                      (24U)
#define DSPI_MCR_ROOE_WIDTH                      (1U)
#define DSPI_MCR_ROOE(x)                         (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_ROOE_SHIFT)) & DSPI_MCR_ROOE_MASK)

#define DSPI_MCR_MTFE_MASK                       (0x4000000U)
#define DSPI_MCR_MTFE_SHIFT                      (26U)
#define DSPI_MCR_MTFE_WIDTH                      (1U)
#define DSPI_MCR_MTFE(x)                         (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_MTFE_SHIFT)) & DSPI_MCR_MTFE_MASK)

#define DSPI_MCR_FRZ_MASK                        (0x8000000U)
#define DSPI_MCR_FRZ_SHIFT                       (27U)
#define DSPI_MCR_FRZ_WIDTH                       (1U)
#define DSPI_MCR_FRZ(x)                          (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_FRZ_SHIFT)) & DSPI_MCR_FRZ_MASK)

#define DSPI_MCR_DCONF_MASK                      (0x30000000U)
#define DSPI_MCR_DCONF_SHIFT                     (28U)
#define DSPI_MCR_DCONF_WIDTH                     (2U)
#define DSPI_MCR_DCONF(x)                        (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_DCONF_SHIFT)) & DSPI_MCR_DCONF_MASK)

#define DSPI_MCR_CONT_SCKE_MASK                  (0x40000000U)
#define DSPI_MCR_CONT_SCKE_SHIFT                 (30U)
#define DSPI_MCR_CONT_SCKE_WIDTH                 (1U)
#define DSPI_MCR_CONT_SCKE(x)                    (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_CONT_SCKE_SHIFT)) & DSPI_MCR_CONT_SCKE_MASK)

#define DSPI_MCR_MSTR_MASK                       (0x80000000U)
#define DSPI_MCR_MSTR_SHIFT                      (31U)
#define DSPI_MCR_MSTR_WIDTH                      (1U)
#define DSPI_MCR_MSTR(x)                         (((uint32_t)(((uint32_t)(x)) << DSPI_MCR_MSTR_SHIFT)) & DSPI_MCR_MSTR_MASK)
/*! @} */

/*! @name TCR - Transfer Count Register */
/*! @{ */

#define DSPI_TCR_SPI_TCNT_MASK                   (0xFFFF0000U)
#define DSPI_TCR_SPI_TCNT_SHIFT                  (16U)
#define DSPI_TCR_SPI_TCNT_WIDTH                  (16U)
#define DSPI_TCR_SPI_TCNT(x)                     (((uint32_t)(((uint32_t)(x)) << DSPI_TCR_SPI_TCNT_SHIFT)) & DSPI_TCR_SPI_TCNT_MASK)
/*! @} */

/*! @name CTAR - Clock and Transfer Attributes Register (In Master Mode) */
/*! @{ */

#define DSPI_CTAR_BR_MASK                        (0xFU)
#define DSPI_CTAR_BR_SHIFT                       (0U)
#define DSPI_CTAR_BR_WIDTH                       (4U)
#define DSPI_CTAR_BR(x)                          (((uint32_t)(((uint32_t)(x)) << DSPI_CTAR_BR_SHIFT)) & DSPI_CTAR_BR_MASK)

#define DSPI_CTAR_DT_MASK                        (0xF0U)
#define DSPI_CTAR_DT_SHIFT                       (4U)
#define DSPI_CTAR_DT_WIDTH                       (4U)
#define DSPI_CTAR_DT(x)                          (((uint32_t)(((uint32_t)(x)) << DSPI_CTAR_DT_SHIFT)) & DSPI_CTAR_DT_MASK)

#define DSPI_CTAR_ASC_MASK                       (0xF00U)
#define DSPI_CTAR_ASC_SHIFT                      (8U)
#define DSPI_CTAR_ASC_WIDTH                      (4U)
#define DSPI_CTAR_ASC(x)                         (((uint32_t)(((uint32_t)(x)) << DSPI_CTAR_ASC_SHIFT)) & DSPI_CTAR_ASC_MASK)

#define DSPI_CTAR_CSSCK_MASK                     (0xF000U)
#define DSPI_CTAR_CSSCK_SHIFT                    (12U)
#define DSPI_CTAR_CSSCK_WIDTH                    (4U)
#define DSPI_CTAR_CSSCK(x)                       (((uint32_t)(((uint32_t)(x)) << DSPI_CTAR_CSSCK_SHIFT)) & DSPI_CTAR_CSSCK_MASK)

#define DSPI_CTAR_PBR_MASK                       (0x30000U)
#define DSPI_CTAR_PBR_SHIFT                      (16U)
#define DSPI_CTAR_PBR_WIDTH                      (2U)
#define DSPI_CTAR_PBR(x)                         (((uint32_t)(((uint32_t)(x)) << DSPI_CTAR_PBR_SHIFT)) & DSPI_CTAR_PBR_MASK)

#define DSPI_CTAR_PDT_MASK                       (0xC0000U)
#define DSPI_CTAR_PDT_SHIFT                      (18U)
#define DSPI_CTAR_PDT_WIDTH                      (2U)
#define DSPI_CTAR_PDT(x)                         (((uint32_t)(((uint32_t)(x)) << DSPI_CTAR_PDT_SHIFT)) & DSPI_CTAR_PDT_MASK)

#define DSPI_CTAR_PASC_MASK                      (0x300000U)
#define DSPI_CTAR_PASC_SHIFT                     (20U)
#define DSPI_CTAR_PASC_WIDTH                     (2U)
#define DSPI_CTAR_PASC(x)                        (((uint32_t)(((uint32_t)(x)) << DSPI_CTAR_PASC_SHIFT)) & DSPI_CTAR_PASC_MASK)

#define DSPI_CTAR_PCSSCK_MASK                    (0xC00000U)
#define DSPI_CTAR_PCSSCK_SHIFT                   (22U)
#define DSPI_CTAR_PCSSCK_WIDTH                   (2U)
#define DSPI_CTAR_PCSSCK(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_CTAR_PCSSCK_SHIFT)) & DSPI_CTAR_PCSSCK_MASK)

#define DSPI_CTAR_LSBFE_MASK                     (0x1000000U)
#define DSPI_CTAR_LSBFE_SHIFT                    (24U)
#define DSPI_CTAR_LSBFE_WIDTH                    (1U)
#define DSPI_CTAR_LSBFE(x)                       (((uint32_t)(((uint32_t)(x)) << DSPI_CTAR_LSBFE_SHIFT)) & DSPI_CTAR_LSBFE_MASK)

#define DSPI_CTAR_CPHA_MASK                      (0x2000000U)
#define DSPI_CTAR_CPHA_SHIFT                     (25U)
#define DSPI_CTAR_CPHA_WIDTH                     (1U)
#define DSPI_CTAR_CPHA(x)                        (((uint32_t)(((uint32_t)(x)) << DSPI_CTAR_CPHA_SHIFT)) & DSPI_CTAR_CPHA_MASK)

#define DSPI_CTAR_CPOL_MASK                      (0x4000000U)
#define DSPI_CTAR_CPOL_SHIFT                     (26U)
#define DSPI_CTAR_CPOL_WIDTH                     (1U)
#define DSPI_CTAR_CPOL(x)                        (((uint32_t)(((uint32_t)(x)) << DSPI_CTAR_CPOL_SHIFT)) & DSPI_CTAR_CPOL_MASK)

#define DSPI_CTAR_FMSZ_MASK                      (0x78000000U)
#define DSPI_CTAR_FMSZ_SHIFT                     (27U)
#define DSPI_CTAR_FMSZ_WIDTH                     (4U)
#define DSPI_CTAR_FMSZ(x)                        (((uint32_t)(((uint32_t)(x)) << DSPI_CTAR_FMSZ_SHIFT)) & DSPI_CTAR_FMSZ_MASK)

#define DSPI_CTAR_DBR_MASK                       (0x80000000U)
#define DSPI_CTAR_DBR_SHIFT                      (31U)
#define DSPI_CTAR_DBR_WIDTH                      (1U)
#define DSPI_CTAR_DBR(x)                         (((uint32_t)(((uint32_t)(x)) << DSPI_CTAR_DBR_SHIFT)) & DSPI_CTAR_DBR_MASK)
/*! @} */

/*! @name SR - Status Register */
/*! @{ */

#define DSPI_SR_POPNXTPTR_MASK                   (0xFU)
#define DSPI_SR_POPNXTPTR_SHIFT                  (0U)
#define DSPI_SR_POPNXTPTR_WIDTH                  (4U)
#define DSPI_SR_POPNXTPTR(x)                     (((uint32_t)(((uint32_t)(x)) << DSPI_SR_POPNXTPTR_SHIFT)) & DSPI_SR_POPNXTPTR_MASK)

#define DSPI_SR_RXCTR_MASK                       (0xF0U)
#define DSPI_SR_RXCTR_SHIFT                      (4U)
#define DSPI_SR_RXCTR_WIDTH                      (4U)
#define DSPI_SR_RXCTR(x)                         (((uint32_t)(((uint32_t)(x)) << DSPI_SR_RXCTR_SHIFT)) & DSPI_SR_RXCTR_MASK)

#define DSPI_SR_TXNXTPTR_MASK                    (0xF00U)
#define DSPI_SR_TXNXTPTR_SHIFT                   (8U)
#define DSPI_SR_TXNXTPTR_WIDTH                   (4U)
#define DSPI_SR_TXNXTPTR(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_SR_TXNXTPTR_SHIFT)) & DSPI_SR_TXNXTPTR_MASK)

#define DSPI_SR_TXCTR_MASK                       (0xF000U)
#define DSPI_SR_TXCTR_SHIFT                      (12U)
#define DSPI_SR_TXCTR_WIDTH                      (4U)
#define DSPI_SR_TXCTR(x)                         (((uint32_t)(((uint32_t)(x)) << DSPI_SR_TXCTR_SHIFT)) & DSPI_SR_TXCTR_MASK)

#define DSPI_SR_CMDFFF_MASK                      (0x10000U)
#define DSPI_SR_CMDFFF_SHIFT                     (16U)
#define DSPI_SR_CMDFFF_WIDTH                     (1U)
#define DSPI_SR_CMDFFF(x)                        (((uint32_t)(((uint32_t)(x)) << DSPI_SR_CMDFFF_SHIFT)) & DSPI_SR_CMDFFF_MASK)

#define DSPI_SR_RFDF_MASK                        (0x20000U)
#define DSPI_SR_RFDF_SHIFT                       (17U)
#define DSPI_SR_RFDF_WIDTH                       (1U)
#define DSPI_SR_RFDF(x)                          (((uint32_t)(((uint32_t)(x)) << DSPI_SR_RFDF_SHIFT)) & DSPI_SR_RFDF_MASK)

#define DSPI_SR_TFIWF_MASK                       (0x40000U)
#define DSPI_SR_TFIWF_SHIFT                      (18U)
#define DSPI_SR_TFIWF_WIDTH                      (1U)
#define DSPI_SR_TFIWF(x)                         (((uint32_t)(((uint32_t)(x)) << DSPI_SR_TFIWF_SHIFT)) & DSPI_SR_TFIWF_MASK)

#define DSPI_SR_RFOF_MASK                        (0x80000U)
#define DSPI_SR_RFOF_SHIFT                       (19U)
#define DSPI_SR_RFOF_WIDTH                       (1U)
#define DSPI_SR_RFOF(x)                          (((uint32_t)(((uint32_t)(x)) << DSPI_SR_RFOF_SHIFT)) & DSPI_SR_RFOF_MASK)

#define DSPI_SR_DDIF_MASK                        (0x100000U)
#define DSPI_SR_DDIF_SHIFT                       (20U)
#define DSPI_SR_DDIF_WIDTH                       (1U)
#define DSPI_SR_DDIF(x)                          (((uint32_t)(((uint32_t)(x)) << DSPI_SR_DDIF_SHIFT)) & DSPI_SR_DDIF_MASK)

#define DSPI_SR_SPEF_MASK                        (0x200000U)
#define DSPI_SR_SPEF_SHIFT                       (21U)
#define DSPI_SR_SPEF_WIDTH                       (1U)
#define DSPI_SR_SPEF(x)                          (((uint32_t)(((uint32_t)(x)) << DSPI_SR_SPEF_SHIFT)) & DSPI_SR_SPEF_MASK)

#define DSPI_SR_DPEF_MASK                        (0x400000U)
#define DSPI_SR_DPEF_SHIFT                       (22U)
#define DSPI_SR_DPEF_WIDTH                       (1U)
#define DSPI_SR_DPEF(x)                          (((uint32_t)(((uint32_t)(x)) << DSPI_SR_DPEF_SHIFT)) & DSPI_SR_DPEF_MASK)

#define DSPI_SR_CMDTCF_MASK                      (0x800000U)
#define DSPI_SR_CMDTCF_SHIFT                     (23U)
#define DSPI_SR_CMDTCF_WIDTH                     (1U)
#define DSPI_SR_CMDTCF(x)                        (((uint32_t)(((uint32_t)(x)) << DSPI_SR_CMDTCF_SHIFT)) & DSPI_SR_CMDTCF_MASK)

#define DSPI_SR_BSYF_MASK                        (0x1000000U)
#define DSPI_SR_BSYF_SHIFT                       (24U)
#define DSPI_SR_BSYF_WIDTH                       (1U)
#define DSPI_SR_BSYF(x)                          (((uint32_t)(((uint32_t)(x)) << DSPI_SR_BSYF_SHIFT)) & DSPI_SR_BSYF_MASK)

#define DSPI_SR_TFFF_MASK                        (0x2000000U)
#define DSPI_SR_TFFF_SHIFT                       (25U)
#define DSPI_SR_TFFF_WIDTH                       (1U)
#define DSPI_SR_TFFF(x)                          (((uint32_t)(((uint32_t)(x)) << DSPI_SR_TFFF_SHIFT)) & DSPI_SR_TFFF_MASK)

#define DSPI_SR_EOQF_MASK                        (0x10000000U)
#define DSPI_SR_EOQF_SHIFT                       (28U)
#define DSPI_SR_EOQF_WIDTH                       (1U)
#define DSPI_SR_EOQF(x)                          (((uint32_t)(((uint32_t)(x)) << DSPI_SR_EOQF_SHIFT)) & DSPI_SR_EOQF_MASK)

#define DSPI_SR_SPITCF_MASK                      (0x20000000U)
#define DSPI_SR_SPITCF_SHIFT                     (29U)
#define DSPI_SR_SPITCF_WIDTH                     (1U)
#define DSPI_SR_SPITCF(x)                        (((uint32_t)(((uint32_t)(x)) << DSPI_SR_SPITCF_SHIFT)) & DSPI_SR_SPITCF_MASK)

#define DSPI_SR_TXRXS_MASK                       (0x40000000U)
#define DSPI_SR_TXRXS_SHIFT                      (30U)
#define DSPI_SR_TXRXS_WIDTH                      (1U)
#define DSPI_SR_TXRXS(x)                         (((uint32_t)(((uint32_t)(x)) << DSPI_SR_TXRXS_SHIFT)) & DSPI_SR_TXRXS_MASK)

#define DSPI_SR_TCF_MASK                         (0x80000000U)
#define DSPI_SR_TCF_SHIFT                        (31U)
#define DSPI_SR_TCF_WIDTH                        (1U)
#define DSPI_SR_TCF(x)                           (((uint32_t)(((uint32_t)(x)) << DSPI_SR_TCF_SHIFT)) & DSPI_SR_TCF_MASK)
/*! @} */

/*! @name RSER - DMA/Interrupt Request Select and Enable Register */
/*! @{ */

#define DSPI_RSER_DDIF_DIRS_MASK                 (0x4000U)
#define DSPI_RSER_DDIF_DIRS_SHIFT                (14U)
#define DSPI_RSER_DDIF_DIRS_WIDTH                (1U)
#define DSPI_RSER_DDIF_DIRS(x)                   (((uint32_t)(((uint32_t)(x)) << DSPI_RSER_DDIF_DIRS_SHIFT)) & DSPI_RSER_DDIF_DIRS_MASK)

#define DSPI_RSER_CMDFFF_DIRS_MASK               (0x8000U)
#define DSPI_RSER_CMDFFF_DIRS_SHIFT              (15U)
#define DSPI_RSER_CMDFFF_DIRS_WIDTH              (1U)
#define DSPI_RSER_CMDFFF_DIRS(x)                 (((uint32_t)(((uint32_t)(x)) << DSPI_RSER_CMDFFF_DIRS_SHIFT)) & DSPI_RSER_CMDFFF_DIRS_MASK)

#define DSPI_RSER_RFDF_DIRS_MASK                 (0x10000U)
#define DSPI_RSER_RFDF_DIRS_SHIFT                (16U)
#define DSPI_RSER_RFDF_DIRS_WIDTH                (1U)
#define DSPI_RSER_RFDF_DIRS(x)                   (((uint32_t)(((uint32_t)(x)) << DSPI_RSER_RFDF_DIRS_SHIFT)) & DSPI_RSER_RFDF_DIRS_MASK)

#define DSPI_RSER_RFDF_RE_MASK                   (0x20000U)
#define DSPI_RSER_RFDF_RE_SHIFT                  (17U)
#define DSPI_RSER_RFDF_RE_WIDTH                  (1U)
#define DSPI_RSER_RFDF_RE(x)                     (((uint32_t)(((uint32_t)(x)) << DSPI_RSER_RFDF_RE_SHIFT)) & DSPI_RSER_RFDF_RE_MASK)

#define DSPI_RSER_TFIWF_RE_MASK                  (0x40000U)
#define DSPI_RSER_TFIWF_RE_SHIFT                 (18U)
#define DSPI_RSER_TFIWF_RE_WIDTH                 (1U)
#define DSPI_RSER_TFIWF_RE(x)                    (((uint32_t)(((uint32_t)(x)) << DSPI_RSER_TFIWF_RE_SHIFT)) & DSPI_RSER_TFIWF_RE_MASK)

#define DSPI_RSER_RFOF_RE_MASK                   (0x80000U)
#define DSPI_RSER_RFOF_RE_SHIFT                  (19U)
#define DSPI_RSER_RFOF_RE_WIDTH                  (1U)
#define DSPI_RSER_RFOF_RE(x)                     (((uint32_t)(((uint32_t)(x)) << DSPI_RSER_RFOF_RE_SHIFT)) & DSPI_RSER_RFOF_RE_MASK)

#define DSPI_RSER_DDIF_RE_MASK                   (0x100000U)
#define DSPI_RSER_DDIF_RE_SHIFT                  (20U)
#define DSPI_RSER_DDIF_RE_WIDTH                  (1U)
#define DSPI_RSER_DDIF_RE(x)                     (((uint32_t)(((uint32_t)(x)) << DSPI_RSER_DDIF_RE_SHIFT)) & DSPI_RSER_DDIF_RE_MASK)

#define DSPI_RSER_SPEF_RE_MASK                   (0x200000U)
#define DSPI_RSER_SPEF_RE_SHIFT                  (21U)
#define DSPI_RSER_SPEF_RE_WIDTH                  (1U)
#define DSPI_RSER_SPEF_RE(x)                     (((uint32_t)(((uint32_t)(x)) << DSPI_RSER_SPEF_RE_SHIFT)) & DSPI_RSER_SPEF_RE_MASK)

#define DSPI_RSER_DPEF_RE_MASK                   (0x400000U)
#define DSPI_RSER_DPEF_RE_SHIFT                  (22U)
#define DSPI_RSER_DPEF_RE_WIDTH                  (1U)
#define DSPI_RSER_DPEF_RE(x)                     (((uint32_t)(((uint32_t)(x)) << DSPI_RSER_DPEF_RE_SHIFT)) & DSPI_RSER_DPEF_RE_MASK)

#define DSPI_RSER_CMDTCF_RE_MASK                 (0x800000U)
#define DSPI_RSER_CMDTCF_RE_SHIFT                (23U)
#define DSPI_RSER_CMDTCF_RE_WIDTH                (1U)
#define DSPI_RSER_CMDTCF_RE(x)                   (((uint32_t)(((uint32_t)(x)) << DSPI_RSER_CMDTCF_RE_SHIFT)) & DSPI_RSER_CMDTCF_RE_MASK)

#define DSPI_RSER_TFFF_DIRS_MASK                 (0x1000000U)
#define DSPI_RSER_TFFF_DIRS_SHIFT                (24U)
#define DSPI_RSER_TFFF_DIRS_WIDTH                (1U)
#define DSPI_RSER_TFFF_DIRS(x)                   (((uint32_t)(((uint32_t)(x)) << DSPI_RSER_TFFF_DIRS_SHIFT)) & DSPI_RSER_TFFF_DIRS_MASK)

#define DSPI_RSER_TFFF_RE_MASK                   (0x2000000U)
#define DSPI_RSER_TFFF_RE_SHIFT                  (25U)
#define DSPI_RSER_TFFF_RE_WIDTH                  (1U)
#define DSPI_RSER_TFFF_RE(x)                     (((uint32_t)(((uint32_t)(x)) << DSPI_RSER_TFFF_RE_SHIFT)) & DSPI_RSER_TFFF_RE_MASK)

#define DSPI_RSER_EOQF_RE_MASK                   (0x10000000U)
#define DSPI_RSER_EOQF_RE_SHIFT                  (28U)
#define DSPI_RSER_EOQF_RE_WIDTH                  (1U)
#define DSPI_RSER_EOQF_RE(x)                     (((uint32_t)(((uint32_t)(x)) << DSPI_RSER_EOQF_RE_SHIFT)) & DSPI_RSER_EOQF_RE_MASK)

#define DSPI_RSER_CMDFFF_RE_MASK                 (0x40000000U)
#define DSPI_RSER_CMDFFF_RE_SHIFT                (30U)
#define DSPI_RSER_CMDFFF_RE_WIDTH                (1U)
#define DSPI_RSER_CMDFFF_RE(x)                   (((uint32_t)(((uint32_t)(x)) << DSPI_RSER_CMDFFF_RE_SHIFT)) & DSPI_RSER_CMDFFF_RE_MASK)

#define DSPI_RSER_TCF_RE_MASK                    (0x80000000U)
#define DSPI_RSER_TCF_RE_SHIFT                   (31U)
#define DSPI_RSER_TCF_RE_WIDTH                   (1U)
#define DSPI_RSER_TCF_RE(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_RSER_TCF_RE_SHIFT)) & DSPI_RSER_TCF_RE_MASK)
/*! @} */

/*! @name TX - DSPI_TX register */
/*! @{ */

#define DSPI_TX_TX_MASK                          (0xFFFFU)
#define DSPI_TX_TX_SHIFT                         (0U)
#define DSPI_TX_TX_WIDTH                         (16U)
#define DSPI_TX_TX(x)                            (((uint16_t)(((uint16_t)(x)) << DSPI_TX_TX_SHIFT)) & DSPI_TX_TX_MASK)
/*! @} */

/*! @name CMD - DSPI_CMD register */
/*! @{ */

#define DSPI_CMD_CMD_MASK                        (0xFFFFU)
#define DSPI_CMD_CMD_SHIFT                       (0U)
#define DSPI_CMD_CMD_WIDTH                       (16U)
#define DSPI_CMD_CMD(x)                          (((uint16_t)(((uint16_t)(x)) << DSPI_CMD_CMD_SHIFT)) & DSPI_CMD_CMD_MASK)
/*! @} */

/*! @name PUSHR - PUSH TX FIFO Register In Master Mode */
/*! @{ */

#define DSPI_PUSHR_TXDATA_MASK                   (0xFFFFU)
#define DSPI_PUSHR_TXDATA_SHIFT                  (0U)
#define DSPI_PUSHR_TXDATA_WIDTH                  (16U)
#define DSPI_PUSHR_TXDATA(x)                     (((uint32_t)(((uint32_t)(x)) << DSPI_PUSHR_TXDATA_SHIFT)) & DSPI_PUSHR_TXDATA_MASK)

#define DSPI_PUSHR_PCS_MASK                      (0x70000U)
#define DSPI_PUSHR_PCS_SHIFT                     (16U)
#define DSPI_PUSHR_PCS_WIDTH                     (3U)
#define DSPI_PUSHR_PCS(x)                        (((uint32_t)(((uint32_t)(x)) << DSPI_PUSHR_PCS_SHIFT)) & DSPI_PUSHR_PCS_MASK)

#define DSPI_PUSHR_PP_MCSC_MASK                  (0x1000000U)
#define DSPI_PUSHR_PP_MCSC_SHIFT                 (24U)
#define DSPI_PUSHR_PP_MCSC_WIDTH                 (1U)
#define DSPI_PUSHR_PP_MCSC(x)                    (((uint32_t)(((uint32_t)(x)) << DSPI_PUSHR_PP_MCSC_SHIFT)) & DSPI_PUSHR_PP_MCSC_MASK)

#define DSPI_PUSHR_PE_MASC_MASK                  (0x2000000U)
#define DSPI_PUSHR_PE_MASC_SHIFT                 (25U)
#define DSPI_PUSHR_PE_MASC_WIDTH                 (1U)
#define DSPI_PUSHR_PE_MASC(x)                    (((uint32_t)(((uint32_t)(x)) << DSPI_PUSHR_PE_MASC_SHIFT)) & DSPI_PUSHR_PE_MASC_MASK)

#define DSPI_PUSHR_CTCNT_MASK                    (0x4000000U)
#define DSPI_PUSHR_CTCNT_SHIFT                   (26U)
#define DSPI_PUSHR_CTCNT_WIDTH                   (1U)
#define DSPI_PUSHR_CTCNT(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_PUSHR_CTCNT_SHIFT)) & DSPI_PUSHR_CTCNT_MASK)

#define DSPI_PUSHR_EOQ_MASK                      (0x8000000U)
#define DSPI_PUSHR_EOQ_SHIFT                     (27U)
#define DSPI_PUSHR_EOQ_WIDTH                     (1U)
#define DSPI_PUSHR_EOQ(x)                        (((uint32_t)(((uint32_t)(x)) << DSPI_PUSHR_EOQ_SHIFT)) & DSPI_PUSHR_EOQ_MASK)

#define DSPI_PUSHR_CTAS_MASK                     (0x70000000U)
#define DSPI_PUSHR_CTAS_SHIFT                    (28U)
#define DSPI_PUSHR_CTAS_WIDTH                    (3U)
#define DSPI_PUSHR_CTAS(x)                       (((uint32_t)(((uint32_t)(x)) << DSPI_PUSHR_CTAS_SHIFT)) & DSPI_PUSHR_CTAS_MASK)

#define DSPI_PUSHR_CONT_MASK                     (0x80000000U)
#define DSPI_PUSHR_CONT_SHIFT                    (31U)
#define DSPI_PUSHR_CONT_WIDTH                    (1U)
#define DSPI_PUSHR_CONT(x)                       (((uint32_t)(((uint32_t)(x)) << DSPI_PUSHR_CONT_SHIFT)) & DSPI_PUSHR_CONT_MASK)
/*! @} */

/*! @name POPR - POP RX FIFO Register */
/*! @{ */

#define DSPI_POPR_RXDATA_MASK                    (0xFFFFFFFFU)
#define DSPI_POPR_RXDATA_SHIFT                   (0U)
#define DSPI_POPR_RXDATA_WIDTH                   (32U)
#define DSPI_POPR_RXDATA(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_POPR_RXDATA_SHIFT)) & DSPI_POPR_RXDATA_MASK)
/*! @} */

/*! @name TXFR - Transmit FIFO Registers */
/*! @{ */

#define DSPI_TXFR_TXDATA_MASK                    (0xFFFFU)
#define DSPI_TXFR_TXDATA_SHIFT                   (0U)
#define DSPI_TXFR_TXDATA_WIDTH                   (16U)
#define DSPI_TXFR_TXDATA(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_TXFR_TXDATA_SHIFT)) & DSPI_TXFR_TXDATA_MASK)

#define DSPI_TXFR_TXCMD_TXDATA_MASK              (0xFFFF0000U)
#define DSPI_TXFR_TXCMD_TXDATA_SHIFT             (16U)
#define DSPI_TXFR_TXCMD_TXDATA_WIDTH             (16U)
#define DSPI_TXFR_TXCMD_TXDATA(x)                (((uint32_t)(((uint32_t)(x)) << DSPI_TXFR_TXCMD_TXDATA_SHIFT)) & DSPI_TXFR_TXCMD_TXDATA_MASK)
/*! @} */

/*! @name RXFR - Receive FIFO Registers */
/*! @{ */

#define DSPI_RXFR_RXDATA_MASK                    (0xFFFFFFFFU)
#define DSPI_RXFR_RXDATA_SHIFT                   (0U)
#define DSPI_RXFR_RXDATA_WIDTH                   (32U)
#define DSPI_RXFR_RXDATA(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_RXFR_RXDATA_SHIFT)) & DSPI_RXFR_RXDATA_MASK)
/*! @} */

/*! @name DSICR0 - DSI Configuration Register 0 */
/*! @{ */

#define DSPI_DSICR0_DPCSx_MASK                   (0xFFU)
#define DSPI_DSICR0_DPCSx_SHIFT                  (0U)
#define DSPI_DSICR0_DPCSx_WIDTH                  (8U)
#define DSPI_DSICR0_DPCSx(x)                     (((uint32_t)(((uint32_t)(x)) << DSPI_DSICR0_DPCSx_SHIFT)) & DSPI_DSICR0_DPCSx_MASK)

#define DSPI_DSICR0_PP_MASK                      (0x100U)
#define DSPI_DSICR0_PP_SHIFT                     (8U)
#define DSPI_DSICR0_PP_WIDTH                     (1U)
#define DSPI_DSICR0_PP(x)                        (((uint32_t)(((uint32_t)(x)) << DSPI_DSICR0_PP_SHIFT)) & DSPI_DSICR0_PP_MASK)

#define DSPI_DSICR0_PE_MASK                      (0x200U)
#define DSPI_DSICR0_PE_SHIFT                     (9U)
#define DSPI_DSICR0_PE_WIDTH                     (1U)
#define DSPI_DSICR0_PE(x)                        (((uint32_t)(((uint32_t)(x)) << DSPI_DSICR0_PE_SHIFT)) & DSPI_DSICR0_PE_MASK)

#define DSPI_DSICR0_PES_MASK                     (0x400U)
#define DSPI_DSICR0_PES_SHIFT                    (10U)
#define DSPI_DSICR0_PES_WIDTH                    (1U)
#define DSPI_DSICR0_PES(x)                       (((uint32_t)(((uint32_t)(x)) << DSPI_DSICR0_PES_SHIFT)) & DSPI_DSICR0_PES_MASK)

#define DSPI_DSICR0_DMS_MASK                     (0x800U)
#define DSPI_DSICR0_DMS_SHIFT                    (11U)
#define DSPI_DSICR0_DMS_WIDTH                    (1U)
#define DSPI_DSICR0_DMS(x)                       (((uint32_t)(((uint32_t)(x)) << DSPI_DSICR0_DMS_SHIFT)) & DSPI_DSICR0_DMS_MASK)

#define DSPI_DSICR0_DSICTAS_MASK                 (0x7000U)
#define DSPI_DSICR0_DSICTAS_SHIFT                (12U)
#define DSPI_DSICR0_DSICTAS_WIDTH                (3U)
#define DSPI_DSICR0_DSICTAS(x)                   (((uint32_t)(((uint32_t)(x)) << DSPI_DSICR0_DSICTAS_SHIFT)) & DSPI_DSICR0_DSICTAS_MASK)

#define DSPI_DSICR0_DCONT_MASK                   (0x8000U)
#define DSPI_DSICR0_DCONT_SHIFT                  (15U)
#define DSPI_DSICR0_DCONT_WIDTH                  (1U)
#define DSPI_DSICR0_DCONT(x)                     (((uint32_t)(((uint32_t)(x)) << DSPI_DSICR0_DCONT_SHIFT)) & DSPI_DSICR0_DCONT_MASK)

#define DSPI_DSICR0_CID_MASK                     (0x10000U)
#define DSPI_DSICR0_CID_SHIFT                    (16U)
#define DSPI_DSICR0_CID_WIDTH                    (1U)
#define DSPI_DSICR0_CID(x)                       (((uint32_t)(((uint32_t)(x)) << DSPI_DSICR0_CID_SHIFT)) & DSPI_DSICR0_CID_MASK)

#define DSPI_DSICR0_TXSS_MASK                    (0x80000U)
#define DSPI_DSICR0_TXSS_SHIFT                   (19U)
#define DSPI_DSICR0_TXSS_WIDTH                   (1U)
#define DSPI_DSICR0_TXSS(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_DSICR0_TXSS_SHIFT)) & DSPI_DSICR0_TXSS_MASK)

#define DSPI_DSICR0_TSBC_MASK                    (0x100000U)
#define DSPI_DSICR0_TSBC_SHIFT                   (20U)
#define DSPI_DSICR0_TSBC_WIDTH                   (1U)
#define DSPI_DSICR0_TSBC(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_DSICR0_TSBC_SHIFT)) & DSPI_DSICR0_TSBC_MASK)

#define DSPI_DSICR0_ITSB_MASK                    (0x200000U)
#define DSPI_DSICR0_ITSB_SHIFT                   (21U)
#define DSPI_DSICR0_ITSB_WIDTH                   (1U)
#define DSPI_DSICR0_ITSB(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_DSICR0_ITSB_SHIFT)) & DSPI_DSICR0_ITSB_MASK)

#define DSPI_DSICR0_FMSZ5_MASK                   (0x800000U)
#define DSPI_DSICR0_FMSZ5_SHIFT                  (23U)
#define DSPI_DSICR0_FMSZ5_WIDTH                  (1U)
#define DSPI_DSICR0_FMSZ5(x)                     (((uint32_t)(((uint32_t)(x)) << DSPI_DSICR0_FMSZ5_SHIFT)) & DSPI_DSICR0_FMSZ5_MASK)

#define DSPI_DSICR0_FMSZ4_MASK                   (0x40000000U)
#define DSPI_DSICR0_FMSZ4_SHIFT                  (30U)
#define DSPI_DSICR0_FMSZ4_WIDTH                  (1U)
#define DSPI_DSICR0_FMSZ4(x)                     (((uint32_t)(((uint32_t)(x)) << DSPI_DSICR0_FMSZ4_SHIFT)) & DSPI_DSICR0_FMSZ4_MASK)
/*! @} */

/*! @name SDR0 - DSI Serialization Data Register 0 */
/*! @{ */

#define DSPI_SDR0_SER_DATA_MASK                  (0xFFFFFFFFU)
#define DSPI_SDR0_SER_DATA_SHIFT                 (0U)
#define DSPI_SDR0_SER_DATA_WIDTH                 (32U)
#define DSPI_SDR0_SER_DATA(x)                    (((uint32_t)(((uint32_t)(x)) << DSPI_SDR0_SER_DATA_SHIFT)) & DSPI_SDR0_SER_DATA_MASK)
/*! @} */

/*! @name ASDR0 - DSI Alternate Serialization Data Register 0 */
/*! @{ */

#define DSPI_ASDR0_ASER_DATA_MASK                (0xFFFFFFFFU)
#define DSPI_ASDR0_ASER_DATA_SHIFT               (0U)
#define DSPI_ASDR0_ASER_DATA_WIDTH               (32U)
#define DSPI_ASDR0_ASER_DATA(x)                  (((uint32_t)(((uint32_t)(x)) << DSPI_ASDR0_ASER_DATA_SHIFT)) & DSPI_ASDR0_ASER_DATA_MASK)
/*! @} */

/*! @name COMPR0 - DSI Transmit Comparison Register 0 */
/*! @{ */

#define DSPI_COMPR0_COMP_DATA_MASK               (0xFFFFFFFFU)
#define DSPI_COMPR0_COMP_DATA_SHIFT              (0U)
#define DSPI_COMPR0_COMP_DATA_WIDTH              (32U)
#define DSPI_COMPR0_COMP_DATA(x)                 (((uint32_t)(((uint32_t)(x)) << DSPI_COMPR0_COMP_DATA_SHIFT)) & DSPI_COMPR0_COMP_DATA_MASK)
/*! @} */

/*! @name DDR0 - DSI Deserialization Data Register 0 */
/*! @{ */

#define DSPI_DDR0_DESER_DATA_MASK                (0xFFFFFFFFU)
#define DSPI_DDR0_DESER_DATA_SHIFT               (0U)
#define DSPI_DDR0_DESER_DATA_WIDTH               (32U)
#define DSPI_DDR0_DESER_DATA(x)                  (((uint32_t)(((uint32_t)(x)) << DSPI_DDR0_DESER_DATA_SHIFT)) & DSPI_DDR0_DESER_DATA_MASK)
/*! @} */

/*! @name DSICR1 - DSI Configuration Register 1 */
/*! @{ */

#define DSPI_DSICR1_DPCS1_x_MASK                 (0xFFU)
#define DSPI_DSICR1_DPCS1_x_SHIFT                (0U)
#define DSPI_DSICR1_DPCS1_x_WIDTH                (8U)
#define DSPI_DSICR1_DPCS1_x(x)                   (((uint32_t)(((uint32_t)(x)) << DSPI_DSICR1_DPCS1_x_SHIFT)) & DSPI_DSICR1_DPCS1_x_MASK)

#define DSPI_DSICR1_DSE0_MASK                    (0x10000U)
#define DSPI_DSICR1_DSE0_SHIFT                   (16U)
#define DSPI_DSICR1_DSE0_WIDTH                   (1U)
#define DSPI_DSICR1_DSE0(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_DSICR1_DSE0_SHIFT)) & DSPI_DSICR1_DSE0_MASK)

#define DSPI_DSICR1_DSE1_MASK                    (0x20000U)
#define DSPI_DSICR1_DSE1_SHIFT                   (17U)
#define DSPI_DSICR1_DSE1_WIDTH                   (1U)
#define DSPI_DSICR1_DSE1(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_DSICR1_DSE1_SHIFT)) & DSPI_DSICR1_DSE1_MASK)

#define DSPI_DSICR1_DSI64E_MASK                  (0x40000U)
#define DSPI_DSICR1_DSI64E_SHIFT                 (18U)
#define DSPI_DSICR1_DSI64E_WIDTH                 (1U)
#define DSPI_DSICR1_DSI64E(x)                    (((uint32_t)(((uint32_t)(x)) << DSPI_DSICR1_DSI64E_SHIFT)) & DSPI_DSICR1_DSI64E_MASK)

#define DSPI_DSICR1_CSE_MASK                     (0x80000U)
#define DSPI_DSICR1_CSE_SHIFT                    (19U)
#define DSPI_DSICR1_CSE_WIDTH                    (1U)
#define DSPI_DSICR1_CSE(x)                       (((uint32_t)(((uint32_t)(x)) << DSPI_DSICR1_CSE_SHIFT)) & DSPI_DSICR1_CSE_MASK)

#define DSPI_DSICR1_TSBCNT_MASK                  (0x3F000000U)
#define DSPI_DSICR1_TSBCNT_SHIFT                 (24U)
#define DSPI_DSICR1_TSBCNT_WIDTH                 (6U)
#define DSPI_DSICR1_TSBCNT(x)                    (((uint32_t)(((uint32_t)(x)) << DSPI_DSICR1_TSBCNT_SHIFT)) & DSPI_DSICR1_TSBCNT_MASK)
/*! @} */

/*! @name SSR0 - DSI Serialization Source Select Register 0 */
/*! @{ */

#define DSPI_SSR0_SS_MASK                        (0xFFFFFFFFU)
#define DSPI_SSR0_SS_SHIFT                       (0U)
#define DSPI_SSR0_SS_WIDTH                       (32U)
#define DSPI_SSR0_SS(x)                          (((uint32_t)(((uint32_t)(x)) << DSPI_SSR0_SS_SHIFT)) & DSPI_SSR0_SS_MASK)
/*! @} */

/*! @name DIMR0 - DSI Deserialized Data Interrupt Mask Register 0 */
/*! @{ */

#define DSPI_DIMR0_MASK_MASK                     (0xFFFFFFFFU)
#define DSPI_DIMR0_MASK_SHIFT                    (0U)
#define DSPI_DIMR0_MASK_WIDTH                    (32U)
#define DSPI_DIMR0_MASK(x)                       (((uint32_t)(((uint32_t)(x)) << DSPI_DIMR0_MASK_SHIFT)) & DSPI_DIMR0_MASK_MASK)
/*! @} */

/*! @name DPIR0 - DSI Deserialized Data Polarity Interrupt Register 0 */
/*! @{ */

#define DSPI_DPIR0_DP_MASK                       (0xFFFFFFFFU)
#define DSPI_DPIR0_DP_SHIFT                      (0U)
#define DSPI_DPIR0_DP_WIDTH                      (32U)
#define DSPI_DPIR0_DP(x)                         (((uint32_t)(((uint32_t)(x)) << DSPI_DPIR0_DP_SHIFT)) & DSPI_DPIR0_DP_MASK)
/*! @} */

/*! @name SDR1 - DSI Serialization Data Register 1 */
/*! @{ */

#define DSPI_SDR1_SER_DATA_MASK                  (0xFFFFFFFFU)
#define DSPI_SDR1_SER_DATA_SHIFT                 (0U)
#define DSPI_SDR1_SER_DATA_WIDTH                 (32U)
#define DSPI_SDR1_SER_DATA(x)                    (((uint32_t)(((uint32_t)(x)) << DSPI_SDR1_SER_DATA_SHIFT)) & DSPI_SDR1_SER_DATA_MASK)
/*! @} */

/*! @name ASDR1 - DSI Alternate Serialization Data Register 1 */
/*! @{ */

#define DSPI_ASDR1_ASER_DATA_MASK                (0xFFFFFFFFU)
#define DSPI_ASDR1_ASER_DATA_SHIFT               (0U)
#define DSPI_ASDR1_ASER_DATA_WIDTH               (32U)
#define DSPI_ASDR1_ASER_DATA(x)                  (((uint32_t)(((uint32_t)(x)) << DSPI_ASDR1_ASER_DATA_SHIFT)) & DSPI_ASDR1_ASER_DATA_MASK)
/*! @} */

/*! @name COMPR1 - DSI Transmit Comparison Register 1 */
/*! @{ */

#define DSPI_COMPR1_COMP_DATA_MASK               (0xFFFFFFFFU)
#define DSPI_COMPR1_COMP_DATA_SHIFT              (0U)
#define DSPI_COMPR1_COMP_DATA_WIDTH              (32U)
#define DSPI_COMPR1_COMP_DATA(x)                 (((uint32_t)(((uint32_t)(x)) << DSPI_COMPR1_COMP_DATA_SHIFT)) & DSPI_COMPR1_COMP_DATA_MASK)
/*! @} */

/*! @name DDR1 - DSI Deserialization Data Register 1 */
/*! @{ */

#define DSPI_DDR1_DESER_DATA_MASK                (0xFFFFFFFFU)
#define DSPI_DDR1_DESER_DATA_SHIFT               (0U)
#define DSPI_DDR1_DESER_DATA_WIDTH               (32U)
#define DSPI_DDR1_DESER_DATA(x)                  (((uint32_t)(((uint32_t)(x)) << DSPI_DDR1_DESER_DATA_SHIFT)) & DSPI_DDR1_DESER_DATA_MASK)
/*! @} */

/*! @name SSR1 - DSI Serialization Source Select Register 1 */
/*! @{ */

#define DSPI_SSR1_SS_MASK                        (0xFFFFFFFFU)
#define DSPI_SSR1_SS_SHIFT                       (0U)
#define DSPI_SSR1_SS_WIDTH                       (32U)
#define DSPI_SSR1_SS(x)                          (((uint32_t)(((uint32_t)(x)) << DSPI_SSR1_SS_SHIFT)) & DSPI_SSR1_SS_MASK)
/*! @} */

/*! @name DIMR1 - DSI Deserialized Data Interrupt Mask Register 1 */
/*! @{ */

#define DSPI_DIMR1_MASK_MASK                     (0xFFFFFFFFU)
#define DSPI_DIMR1_MASK_SHIFT                    (0U)
#define DSPI_DIMR1_MASK_WIDTH                    (32U)
#define DSPI_DIMR1_MASK(x)                       (((uint32_t)(((uint32_t)(x)) << DSPI_DIMR1_MASK_SHIFT)) & DSPI_DIMR1_MASK_MASK)
/*! @} */

/*! @name DPIR1 - DSI Deserialized Data Polarity Interrupt Register 1 */
/*! @{ */

#define DSPI_DPIR1_DP_MASK                       (0xFFFFFFFFU)
#define DSPI_DPIR1_DP_SHIFT                      (0U)
#define DSPI_DPIR1_DP_WIDTH                      (32U)
#define DSPI_DPIR1_DP(x)                         (((uint32_t)(((uint32_t)(x)) << DSPI_DPIR1_DP_SHIFT)) & DSPI_DPIR1_DP_MASK)
/*! @} */

/*! @name CTARE - Clock and Transfer Attributes Register Extended */
/*! @{ */

#define DSPI_CTARE_DTCP_MASK                     (0x7FFU)
#define DSPI_CTARE_DTCP_SHIFT                    (0U)
#define DSPI_CTARE_DTCP_WIDTH                    (11U)
#define DSPI_CTARE_DTCP(x)                       (((uint32_t)(((uint32_t)(x)) << DSPI_CTARE_DTCP_SHIFT)) & DSPI_CTARE_DTCP_MASK)

#define DSPI_CTARE_FMSZE_MASK                    (0x10000U)
#define DSPI_CTARE_FMSZE_SHIFT                   (16U)
#define DSPI_CTARE_FMSZE_WIDTH                   (1U)
#define DSPI_CTARE_FMSZE(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_CTARE_FMSZE_SHIFT)) & DSPI_CTARE_FMSZE_MASK)
/*! @} */

/*! @name SREX - Status Register Extended */
/*! @{ */

#define DSPI_SREX_CMDNXTPTR_MASK                 (0xFU)
#define DSPI_SREX_CMDNXTPTR_SHIFT                (0U)
#define DSPI_SREX_CMDNXTPTR_WIDTH                (4U)
#define DSPI_SREX_CMDNXTPTR(x)                   (((uint32_t)(((uint32_t)(x)) << DSPI_SREX_CMDNXTPTR_SHIFT)) & DSPI_SREX_CMDNXTPTR_MASK)

#define DSPI_SREX_CMDCTR_MASK                    (0x1F0U)
#define DSPI_SREX_CMDCTR_SHIFT                   (4U)
#define DSPI_SREX_CMDCTR_WIDTH                   (5U)
#define DSPI_SREX_CMDCTR(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_SREX_CMDCTR_SHIFT)) & DSPI_SREX_CMDCTR_MASK)

#define DSPI_SREX_RXCTR4_MASK                    (0x800U)
#define DSPI_SREX_RXCTR4_SHIFT                   (11U)
#define DSPI_SREX_RXCTR4_WIDTH                   (1U)
#define DSPI_SREX_RXCTR4(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_SREX_RXCTR4_SHIFT)) & DSPI_SREX_RXCTR4_MASK)

#define DSPI_SREX_TXCTR4_MASK                    (0x4000U)
#define DSPI_SREX_TXCTR4_SHIFT                   (14U)
#define DSPI_SREX_TXCTR4_WIDTH                   (1U)
#define DSPI_SREX_TXCTR4(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_SREX_TXCTR4_SHIFT)) & DSPI_SREX_TXCTR4_MASK)
/*! @} */

/*! @name TSL - Time Slot Length Register */
/*! @{ */

#define DSPI_TSL_TS0_LEN_MASK                    (0x7FU)
#define DSPI_TSL_TS0_LEN_SHIFT                   (0U)
#define DSPI_TSL_TS0_LEN_WIDTH                   (7U)
#define DSPI_TSL_TS0_LEN(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_TSL_TS0_LEN_SHIFT)) & DSPI_TSL_TS0_LEN_MASK)

#define DSPI_TSL_TS1_LEN_MASK                    (0x7F00U)
#define DSPI_TSL_TS1_LEN_SHIFT                   (8U)
#define DSPI_TSL_TS1_LEN_WIDTH                   (7U)
#define DSPI_TSL_TS1_LEN(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_TSL_TS1_LEN_SHIFT)) & DSPI_TSL_TS1_LEN_MASK)

#define DSPI_TSL_TS2_LEN_MASK                    (0x7F0000U)
#define DSPI_TSL_TS2_LEN_SHIFT                   (16U)
#define DSPI_TSL_TS2_LEN_WIDTH                   (7U)
#define DSPI_TSL_TS2_LEN(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_TSL_TS2_LEN_SHIFT)) & DSPI_TSL_TS2_LEN_MASK)

#define DSPI_TSL_TS3_LEN_MASK                    (0x7F000000U)
#define DSPI_TSL_TS3_LEN_SHIFT                   (24U)
#define DSPI_TSL_TS3_LEN_WIDTH                   (7U)
#define DSPI_TSL_TS3_LEN(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_TSL_TS3_LEN_SHIFT)) & DSPI_TSL_TS3_LEN_MASK)
/*! @} */

/*! @name TS_CONF - Time Slot Configuration Register */
/*! @{ */

#define DSPI_TS_CONF_TS0_MASK                    (0xFU)
#define DSPI_TS_CONF_TS0_SHIFT                   (0U)
#define DSPI_TS_CONF_TS0_WIDTH                   (4U)
#define DSPI_TS_CONF_TS0(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_TS_CONF_TS0_SHIFT)) & DSPI_TS_CONF_TS0_MASK)

#define DSPI_TS_CONF_TS1_MASK                    (0xF0U)
#define DSPI_TS_CONF_TS1_SHIFT                   (4U)
#define DSPI_TS_CONF_TS1_WIDTH                   (4U)
#define DSPI_TS_CONF_TS1(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_TS_CONF_TS1_SHIFT)) & DSPI_TS_CONF_TS1_MASK)

#define DSPI_TS_CONF_TS2_MASK                    (0xF00U)
#define DSPI_TS_CONF_TS2_SHIFT                   (8U)
#define DSPI_TS_CONF_TS2_WIDTH                   (4U)
#define DSPI_TS_CONF_TS2(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_TS_CONF_TS2_SHIFT)) & DSPI_TS_CONF_TS2_MASK)

#define DSPI_TS_CONF_TS3_MASK                    (0xF000U)
#define DSPI_TS_CONF_TS3_SHIFT                   (12U)
#define DSPI_TS_CONF_TS3_WIDTH                   (4U)
#define DSPI_TS_CONF_TS3(x)                      (((uint32_t)(((uint32_t)(x)) << DSPI_TS_CONF_TS3_SHIFT)) & DSPI_TS_CONF_TS3_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group DSPI_Register_Masks */

/*!
 * @}
 */ /* end of group DSPI_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_DSPI_H_) */
