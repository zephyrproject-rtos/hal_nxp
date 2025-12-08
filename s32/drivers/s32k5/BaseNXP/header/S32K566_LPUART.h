/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_LPUART.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_LPUART
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
#if !defined(S32K566_LPUART_H_)  /* Check if memory map has not been already included */
#define S32K566_LPUART_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- LPUART Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPUART_Peripheral_Access_Layer LPUART Peripheral Access Layer
 * @{
 */

/** LPUART - Size of Registers Arrays */
#define LPUART_TIMEOUT_COUNT                      4u
#define LPUART_TCBR_COUNT                         128u
#define LPUART_TDBR_COUNT                         256u

/** LPUART - Register Layout Typedef */
typedef struct LPUART_Struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
  __IO uint32_t GLOBAL;                            /**< Global, offset: 0x8 */
  __IO uint32_t PINCFG;                            /**< Pin Configuration, offset: 0xC */
  __IO uint32_t BAUD;                              /**< Baud Rate, offset: 0x10 */
  __IO uint32_t STAT;                              /**< Status, offset: 0x14 */
  __IO uint32_t CTRL;                              /**< Control, offset: 0x18 */
  __IO uint32_t DATA;                              /**< Data, offset: 0x1C */
  __IO uint32_t MATCH;                             /**< Match Address, offset: 0x20 */
  __IO uint32_t MODIR;                             /**< MODEM IrDA, offset: 0x24 */
  __IO uint32_t FIFO;                              /**< FIFO, offset: 0x28 */
  __IO uint32_t WATER;                             /**< Watermark, offset: 0x2C */
  __I  uint32_t DATARO;                            /**< Data Read-Only, offset: 0x30 */
  uint8_t RESERVED_0[12];
  __IO uint32_t MCR;                               /**< MODEM Control, offset: 0x40, not available in all instances (available on 3 out of 25) */
  __IO uint32_t MSR;                               /**< MODEM Status, offset: 0x44, not available in all instances (available on 3 out of 25) */
  __IO uint32_t REIR;                              /**< Receiver Extended Idle, offset: 0x48, not available in all instances (available on 3 out of 25) */
  __IO uint32_t TEIR;                              /**< Transmitter Extended Idle, offset: 0x4C, not available in all instances (available on 3 out of 25) */
  __IO uint32_t HDCR;                              /**< Half Duplex Control, offset: 0x50, not available in all instances (available on 3 out of 25) */
  uint8_t RESERVED_1[4];
  __IO uint32_t TOCR;                              /**< Timeout Control, offset: 0x58, not available in all instances (available on 3 out of 25) */
  __IO uint32_t TOSR;                              /**< Timeout Status, offset: 0x5C, not available in all instances (available on 3 out of 25) */
  __IO uint32_t TIMEOUT[LPUART_TIMEOUT_COUNT];     /**< Timeout N, array offset: 0x60, array step: 0x4, not available in all instances (available on 3 out of 25) */
  uint8_t RESERVED_2[400];
  __O  uint32_t TCBR[LPUART_TCBR_COUNT];           /**< Transmit Command Burst, array offset: 0x200, array step: 0x4, not available in all instances (available on 3 out of 25) */
  __O  uint32_t TDBR[LPUART_TDBR_COUNT];           /**< Transmit Data Burst, array offset: 0x400, array step: 0x4, not available in all instances (available on 3 out of 25) */
} LPUART_Type, *LPUART_MemMapPtr;

/** Number of instances of the LPUART module. */
#define LPUART_INSTANCE_COUNT                    (25u)

/* LPUART - Peripheral instance base addresses */
/** Peripheral LPE_LPUART_0 base address */
#define IP_LPE_LPUART_0_BASE                     (0x42184000u)
/** Peripheral LPE_LPUART_0 base pointer */
#define IP_LPE_LPUART_0                          ((LPUART_Type *)IP_LPE_LPUART_0_BASE)
/** Peripheral LPE_LPUART_1 base address */
#define IP_LPE_LPUART_1_BASE                     (0x42188000u)
/** Peripheral LPE_LPUART_1 base pointer */
#define IP_LPE_LPUART_1                          ((LPUART_Type *)IP_LPE_LPUART_1_BASE)
/** Peripheral LPE_LPUART_2 base address */
#define IP_LPE_LPUART_2_BASE                     (0x4218C000u)
/** Peripheral LPE_LPUART_2 base pointer */
#define IP_LPE_LPUART_2                          ((LPUART_Type *)IP_LPE_LPUART_2_BASE)
/** Peripheral LPUART_0 base address */
#define IP_LPUART_0_BASE                         (0x400E0000u)
/** Peripheral LPUART_0 base pointer */
#define IP_LPUART_0                              ((LPUART_Type *)IP_LPUART_0_BASE)
/** Peripheral LPUART_1 base address */
#define IP_LPUART_1_BASE                         (0x400E4000u)
/** Peripheral LPUART_1 base pointer */
#define IP_LPUART_1                              ((LPUART_Type *)IP_LPUART_1_BASE)
/** Peripheral LPUART_2 base address */
#define IP_LPUART_2_BASE                         (0x402C8000u)
/** Peripheral LPUART_2 base pointer */
#define IP_LPUART_2                              ((LPUART_Type *)IP_LPUART_2_BASE)
/** Peripheral LPUART_3 base address */
#define IP_LPUART_3_BASE                         (0x402CC000u)
/** Peripheral LPUART_3 base pointer */
#define IP_LPUART_3                              ((LPUART_Type *)IP_LPUART_3_BASE)
/** Peripheral LPUART_4 base address */
#define IP_LPUART_4_BASE                         (0x402D0000u)
/** Peripheral LPUART_4 base pointer */
#define IP_LPUART_4                              ((LPUART_Type *)IP_LPUART_4_BASE)
/** Peripheral LPUART_5 base address */
#define IP_LPUART_5_BASE                         (0x402D4000u)
/** Peripheral LPUART_5 base pointer */
#define IP_LPUART_5                              ((LPUART_Type *)IP_LPUART_5_BASE)
/** Peripheral LPUART_6 base address */
#define IP_LPUART_6_BASE                         (0x402D8000u)
/** Peripheral LPUART_6 base pointer */
#define IP_LPUART_6                              ((LPUART_Type *)IP_LPUART_6_BASE)
/** Peripheral LPUART_7 base address */
#define IP_LPUART_7_BASE                         (0x402DC000u)
/** Peripheral LPUART_7 base pointer */
#define IP_LPUART_7                              ((LPUART_Type *)IP_LPUART_7_BASE)
/** Peripheral LPUART_8 base address */
#define IP_LPUART_8_BASE                         (0x402E0000u)
/** Peripheral LPUART_8 base pointer */
#define IP_LPUART_8                              ((LPUART_Type *)IP_LPUART_8_BASE)
/** Peripheral LPUART_9 base address */
#define IP_LPUART_9_BASE                         (0x402E4000u)
/** Peripheral LPUART_9 base pointer */
#define IP_LPUART_9                              ((LPUART_Type *)IP_LPUART_9_BASE)
/** Peripheral LPUART_10 base address */
#define IP_LPUART_10_BASE                        (0x402B8000u)
/** Peripheral LPUART_10 base pointer */
#define IP_LPUART_10                             ((LPUART_Type *)IP_LPUART_10_BASE)
/** Peripheral LPUART_11 base address */
#define IP_LPUART_11_BASE                        (0x402BC000u)
/** Peripheral LPUART_11 base pointer */
#define IP_LPUART_11                             ((LPUART_Type *)IP_LPUART_11_BASE)
/** Peripheral LPUART_12 base address */
#define IP_LPUART_12_BASE                        (0x402C0000u)
/** Peripheral LPUART_12 base pointer */
#define IP_LPUART_12                             ((LPUART_Type *)IP_LPUART_12_BASE)
/** Peripheral LPUART_13 base address */
#define IP_LPUART_13_BASE                        (0x402C4000u)
/** Peripheral LPUART_13 base pointer */
#define IP_LPUART_13                             ((LPUART_Type *)IP_LPUART_13_BASE)
/** Peripheral LPUART_14 base address */
#define IP_LPUART_14_BASE                        (0x406CC000u)
/** Peripheral LPUART_14 base pointer */
#define IP_LPUART_14                             ((LPUART_Type *)IP_LPUART_14_BASE)
/** Peripheral LPUART_15 base address */
#define IP_LPUART_15_BASE                        (0x406D0000u)
/** Peripheral LPUART_15 base pointer */
#define IP_LPUART_15                             ((LPUART_Type *)IP_LPUART_15_BASE)
/** Peripheral LPUART_16 base address */
#define IP_LPUART_16_BASE                        (0x406D4000u)
/** Peripheral LPUART_16 base pointer */
#define IP_LPUART_16                             ((LPUART_Type *)IP_LPUART_16_BASE)
/** Peripheral LPUART_17 base address */
#define IP_LPUART_17_BASE                        (0x408C4000u)
/** Peripheral LPUART_17 base pointer */
#define IP_LPUART_17                             ((LPUART_Type *)IP_LPUART_17_BASE)
/** Peripheral LPUART_18 base address */
#define IP_LPUART_18_BASE                        (0x408C8000u)
/** Peripheral LPUART_18 base pointer */
#define IP_LPUART_18                             ((LPUART_Type *)IP_LPUART_18_BASE)
/** Peripheral LPUART_19 base address */
#define IP_LPUART_19_BASE                        (0x408CC000u)
/** Peripheral LPUART_19 base pointer */
#define IP_LPUART_19                             ((LPUART_Type *)IP_LPUART_19_BASE)
/** Peripheral LPUART_20 base address */
#define IP_LPUART_20_BASE                        (0x408D0000u)
/** Peripheral LPUART_20 base pointer */
#define IP_LPUART_20                             ((LPUART_Type *)IP_LPUART_20_BASE)
/** Peripheral LPUART_21 base address */
#define IP_LPUART_21_BASE                        (0x406F4000u)
/** Peripheral LPUART_21 base pointer */
#define IP_LPUART_21                             ((LPUART_Type *)IP_LPUART_21_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define IP_LPUART_BASE_ADDRS                     { IP_LPE_LPUART_0_BASE, IP_LPE_LPUART_1_BASE, IP_LPE_LPUART_2_BASE, IP_LPUART_0_BASE, IP_LPUART_1_BASE, IP_LPUART_2_BASE, IP_LPUART_3_BASE, IP_LPUART_4_BASE, IP_LPUART_5_BASE, IP_LPUART_6_BASE, IP_LPUART_7_BASE, IP_LPUART_8_BASE, IP_LPUART_9_BASE, IP_LPUART_10_BASE, IP_LPUART_11_BASE, IP_LPUART_12_BASE, IP_LPUART_13_BASE, IP_LPUART_14_BASE, IP_LPUART_15_BASE, IP_LPUART_16_BASE, IP_LPUART_17_BASE, IP_LPUART_18_BASE, IP_LPUART_19_BASE, IP_LPUART_20_BASE, IP_LPUART_21_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define IP_LPUART_BASE_PTRS                      { IP_LPE_LPUART_0, IP_LPE_LPUART_1, IP_LPE_LPUART_2, IP_LPUART_0, IP_LPUART_1, IP_LPUART_2, IP_LPUART_3, IP_LPUART_4, IP_LPUART_5, IP_LPUART_6, IP_LPUART_7, IP_LPUART_8, IP_LPUART_9, IP_LPUART_10, IP_LPUART_11, IP_LPUART_12, IP_LPUART_13, IP_LPUART_14, IP_LPUART_15, IP_LPUART_16, IP_LPUART_17, IP_LPUART_18, IP_LPUART_19, IP_LPUART_20, IP_LPUART_21 }

/* ----------------------------------------------------------------------------
   -- LPUART Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPUART_Register_Masks LPUART Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define LPUART_VERID_FEATURE_MASK                (0xFFFFU)
#define LPUART_VERID_FEATURE_SHIFT               (0U)
#define LPUART_VERID_FEATURE_WIDTH               (16U)
#define LPUART_VERID_FEATURE(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_VERID_FEATURE_SHIFT)) & LPUART_VERID_FEATURE_MASK)

#define LPUART_VERID_MINOR_MASK                  (0xFF0000U)
#define LPUART_VERID_MINOR_SHIFT                 (16U)
#define LPUART_VERID_MINOR_WIDTH                 (8U)
#define LPUART_VERID_MINOR(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_VERID_MINOR_SHIFT)) & LPUART_VERID_MINOR_MASK)

#define LPUART_VERID_MAJOR_MASK                  (0xFF000000U)
#define LPUART_VERID_MAJOR_SHIFT                 (24U)
#define LPUART_VERID_MAJOR_WIDTH                 (8U)
#define LPUART_VERID_MAJOR(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_VERID_MAJOR_SHIFT)) & LPUART_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter */
/*! @{ */

#define LPUART_PARAM_TXFIFO_MASK                 (0xFFU)
#define LPUART_PARAM_TXFIFO_SHIFT                (0U)
#define LPUART_PARAM_TXFIFO_WIDTH                (8U)
#define LPUART_PARAM_TXFIFO(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_PARAM_TXFIFO_SHIFT)) & LPUART_PARAM_TXFIFO_MASK)

#define LPUART_PARAM_RXFIFO_MASK                 (0xFF00U)
#define LPUART_PARAM_RXFIFO_SHIFT                (8U)
#define LPUART_PARAM_RXFIFO_WIDTH                (8U)
#define LPUART_PARAM_RXFIFO(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_PARAM_RXFIFO_SHIFT)) & LPUART_PARAM_RXFIFO_MASK)
/*! @} */

/*! @name GLOBAL - Global */
/*! @{ */

#define LPUART_GLOBAL_RST_MASK                   (0x2U)
#define LPUART_GLOBAL_RST_SHIFT                  (1U)
#define LPUART_GLOBAL_RST_WIDTH                  (1U)
#define LPUART_GLOBAL_RST(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_GLOBAL_RST_SHIFT)) & LPUART_GLOBAL_RST_MASK)
/*! @} */

/*! @name PINCFG - Pin Configuration */
/*! @{ */

#define LPUART_PINCFG_TRGSEL_MASK                (0x3U)
#define LPUART_PINCFG_TRGSEL_SHIFT               (0U)
#define LPUART_PINCFG_TRGSEL_WIDTH               (2U)
#define LPUART_PINCFG_TRGSEL(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_PINCFG_TRGSEL_SHIFT)) & LPUART_PINCFG_TRGSEL_MASK)
/*! @} */

/*! @name BAUD - Baud Rate */
/*! @{ */

#define LPUART_BAUD_SBR_MASK                     (0x1FFFU)
#define LPUART_BAUD_SBR_SHIFT                    (0U)
#define LPUART_BAUD_SBR_WIDTH                    (13U)
#define LPUART_BAUD_SBR(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_SBR_SHIFT)) & LPUART_BAUD_SBR_MASK)

#define LPUART_BAUD_SBNS_MASK                    (0x2000U)
#define LPUART_BAUD_SBNS_SHIFT                   (13U)
#define LPUART_BAUD_SBNS_WIDTH                   (1U)
#define LPUART_BAUD_SBNS(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_SBNS_SHIFT)) & LPUART_BAUD_SBNS_MASK)

#define LPUART_BAUD_RXEDGIE_MASK                 (0x4000U)
#define LPUART_BAUD_RXEDGIE_SHIFT                (14U)
#define LPUART_BAUD_RXEDGIE_WIDTH                (1U)
#define LPUART_BAUD_RXEDGIE(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_RXEDGIE_SHIFT)) & LPUART_BAUD_RXEDGIE_MASK)

#define LPUART_BAUD_LBKDIE_MASK                  (0x8000U)
#define LPUART_BAUD_LBKDIE_SHIFT                 (15U)
#define LPUART_BAUD_LBKDIE_WIDTH                 (1U)
#define LPUART_BAUD_LBKDIE(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_LBKDIE_SHIFT)) & LPUART_BAUD_LBKDIE_MASK)

#define LPUART_BAUD_RESYNCDIS_MASK               (0x10000U)
#define LPUART_BAUD_RESYNCDIS_SHIFT              (16U)
#define LPUART_BAUD_RESYNCDIS_WIDTH              (1U)
#define LPUART_BAUD_RESYNCDIS(x)                 (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_RESYNCDIS_SHIFT)) & LPUART_BAUD_RESYNCDIS_MASK)

#define LPUART_BAUD_BOTHEDGE_MASK                (0x20000U)
#define LPUART_BAUD_BOTHEDGE_SHIFT               (17U)
#define LPUART_BAUD_BOTHEDGE_WIDTH               (1U)
#define LPUART_BAUD_BOTHEDGE(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_BOTHEDGE_SHIFT)) & LPUART_BAUD_BOTHEDGE_MASK)

#define LPUART_BAUD_MATCFG_MASK                  (0xC0000U)
#define LPUART_BAUD_MATCFG_SHIFT                 (18U)
#define LPUART_BAUD_MATCFG_WIDTH                 (2U)
#define LPUART_BAUD_MATCFG(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_MATCFG_SHIFT)) & LPUART_BAUD_MATCFG_MASK)

#define LPUART_BAUD_RDMAE_MASK                   (0x200000U)
#define LPUART_BAUD_RDMAE_SHIFT                  (21U)
#define LPUART_BAUD_RDMAE_WIDTH                  (1U)
#define LPUART_BAUD_RDMAE(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_RDMAE_SHIFT)) & LPUART_BAUD_RDMAE_MASK)

#define LPUART_BAUD_TDMAE_MASK                   (0x800000U)
#define LPUART_BAUD_TDMAE_SHIFT                  (23U)
#define LPUART_BAUD_TDMAE_WIDTH                  (1U)
#define LPUART_BAUD_TDMAE(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_TDMAE_SHIFT)) & LPUART_BAUD_TDMAE_MASK)

#define LPUART_BAUD_OSR_MASK                     (0x1F000000U)
#define LPUART_BAUD_OSR_SHIFT                    (24U)
#define LPUART_BAUD_OSR_WIDTH                    (5U)
#define LPUART_BAUD_OSR(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_OSR_SHIFT)) & LPUART_BAUD_OSR_MASK)

#define LPUART_BAUD_M10_MASK                     (0x20000000U)
#define LPUART_BAUD_M10_SHIFT                    (29U)
#define LPUART_BAUD_M10_WIDTH                    (1U)
#define LPUART_BAUD_M10(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_M10_SHIFT)) & LPUART_BAUD_M10_MASK)

#define LPUART_BAUD_MAEN2_MASK                   (0x40000000U)
#define LPUART_BAUD_MAEN2_SHIFT                  (30U)
#define LPUART_BAUD_MAEN2_WIDTH                  (1U)
#define LPUART_BAUD_MAEN2(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_MAEN2_SHIFT)) & LPUART_BAUD_MAEN2_MASK)

#define LPUART_BAUD_MAEN1_MASK                   (0x80000000U)
#define LPUART_BAUD_MAEN1_SHIFT                  (31U)
#define LPUART_BAUD_MAEN1_WIDTH                  (1U)
#define LPUART_BAUD_MAEN1(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_MAEN1_SHIFT)) & LPUART_BAUD_MAEN1_MASK)
/*! @} */

/*! @name STAT - Status */
/*! @{ */

#define LPUART_STAT_LBKFE_MASK                   (0x1U)
#define LPUART_STAT_LBKFE_SHIFT                  (0U)
#define LPUART_STAT_LBKFE_WIDTH                  (1U)
#define LPUART_STAT_LBKFE(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_LBKFE_SHIFT)) & LPUART_STAT_LBKFE_MASK)

#define LPUART_STAT_AME_MASK                     (0x2U)
#define LPUART_STAT_AME_SHIFT                    (1U)
#define LPUART_STAT_AME_WIDTH                    (1U)
#define LPUART_STAT_AME(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_AME_SHIFT)) & LPUART_STAT_AME_MASK)

#define LPUART_STAT_MSF_MASK                     (0x100U)
#define LPUART_STAT_MSF_SHIFT                    (8U)
#define LPUART_STAT_MSF_WIDTH                    (1U)
#define LPUART_STAT_MSF(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_MSF_SHIFT)) & LPUART_STAT_MSF_MASK)

#define LPUART_STAT_TSF_MASK                     (0x200U)
#define LPUART_STAT_TSF_SHIFT                    (9U)
#define LPUART_STAT_TSF_WIDTH                    (1U)
#define LPUART_STAT_TSF(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_TSF_SHIFT)) & LPUART_STAT_TSF_MASK)

#define LPUART_STAT_MA2F_MASK                    (0x4000U)
#define LPUART_STAT_MA2F_SHIFT                   (14U)
#define LPUART_STAT_MA2F_WIDTH                   (1U)
#define LPUART_STAT_MA2F(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_MA2F_SHIFT)) & LPUART_STAT_MA2F_MASK)

#define LPUART_STAT_MA1F_MASK                    (0x8000U)
#define LPUART_STAT_MA1F_SHIFT                   (15U)
#define LPUART_STAT_MA1F_WIDTH                   (1U)
#define LPUART_STAT_MA1F(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_MA1F_SHIFT)) & LPUART_STAT_MA1F_MASK)

#define LPUART_STAT_PF_MASK                      (0x10000U)
#define LPUART_STAT_PF_SHIFT                     (16U)
#define LPUART_STAT_PF_WIDTH                     (1U)
#define LPUART_STAT_PF(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_PF_SHIFT)) & LPUART_STAT_PF_MASK)

#define LPUART_STAT_FE_MASK                      (0x20000U)
#define LPUART_STAT_FE_SHIFT                     (17U)
#define LPUART_STAT_FE_WIDTH                     (1U)
#define LPUART_STAT_FE(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_FE_SHIFT)) & LPUART_STAT_FE_MASK)

#define LPUART_STAT_NF_MASK                      (0x40000U)
#define LPUART_STAT_NF_SHIFT                     (18U)
#define LPUART_STAT_NF_WIDTH                     (1U)
#define LPUART_STAT_NF(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_NF_SHIFT)) & LPUART_STAT_NF_MASK)

#define LPUART_STAT_OR_MASK                      (0x80000U)
#define LPUART_STAT_OR_SHIFT                     (19U)
#define LPUART_STAT_OR_WIDTH                     (1U)
#define LPUART_STAT_OR(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_OR_SHIFT)) & LPUART_STAT_OR_MASK)

#define LPUART_STAT_IDLE_MASK                    (0x100000U)
#define LPUART_STAT_IDLE_SHIFT                   (20U)
#define LPUART_STAT_IDLE_WIDTH                   (1U)
#define LPUART_STAT_IDLE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_IDLE_SHIFT)) & LPUART_STAT_IDLE_MASK)

#define LPUART_STAT_RDRF_MASK                    (0x200000U)
#define LPUART_STAT_RDRF_SHIFT                   (21U)
#define LPUART_STAT_RDRF_WIDTH                   (1U)
#define LPUART_STAT_RDRF(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_RDRF_SHIFT)) & LPUART_STAT_RDRF_MASK)

#define LPUART_STAT_TC_MASK                      (0x400000U)
#define LPUART_STAT_TC_SHIFT                     (22U)
#define LPUART_STAT_TC_WIDTH                     (1U)
#define LPUART_STAT_TC(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_TC_SHIFT)) & LPUART_STAT_TC_MASK)

#define LPUART_STAT_TDRE_MASK                    (0x800000U)
#define LPUART_STAT_TDRE_SHIFT                   (23U)
#define LPUART_STAT_TDRE_WIDTH                   (1U)
#define LPUART_STAT_TDRE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_TDRE_SHIFT)) & LPUART_STAT_TDRE_MASK)

#define LPUART_STAT_RAF_MASK                     (0x1000000U)
#define LPUART_STAT_RAF_SHIFT                    (24U)
#define LPUART_STAT_RAF_WIDTH                    (1U)
#define LPUART_STAT_RAF(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_RAF_SHIFT)) & LPUART_STAT_RAF_MASK)

#define LPUART_STAT_LBKDE_MASK                   (0x2000000U)
#define LPUART_STAT_LBKDE_SHIFT                  (25U)
#define LPUART_STAT_LBKDE_WIDTH                  (1U)
#define LPUART_STAT_LBKDE(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_LBKDE_SHIFT)) & LPUART_STAT_LBKDE_MASK)

#define LPUART_STAT_BRK13_MASK                   (0x4000000U)
#define LPUART_STAT_BRK13_SHIFT                  (26U)
#define LPUART_STAT_BRK13_WIDTH                  (1U)
#define LPUART_STAT_BRK13(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_BRK13_SHIFT)) & LPUART_STAT_BRK13_MASK)

#define LPUART_STAT_RWUID_MASK                   (0x8000000U)
#define LPUART_STAT_RWUID_SHIFT                  (27U)
#define LPUART_STAT_RWUID_WIDTH                  (1U)
#define LPUART_STAT_RWUID(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_RWUID_SHIFT)) & LPUART_STAT_RWUID_MASK)

#define LPUART_STAT_RXINV_MASK                   (0x10000000U)
#define LPUART_STAT_RXINV_SHIFT                  (28U)
#define LPUART_STAT_RXINV_WIDTH                  (1U)
#define LPUART_STAT_RXINV(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_RXINV_SHIFT)) & LPUART_STAT_RXINV_MASK)

#define LPUART_STAT_MSBF_MASK                    (0x20000000U)
#define LPUART_STAT_MSBF_SHIFT                   (29U)
#define LPUART_STAT_MSBF_WIDTH                   (1U)
#define LPUART_STAT_MSBF(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_MSBF_SHIFT)) & LPUART_STAT_MSBF_MASK)

#define LPUART_STAT_RXEDGIF_MASK                 (0x40000000U)
#define LPUART_STAT_RXEDGIF_SHIFT                (30U)
#define LPUART_STAT_RXEDGIF_WIDTH                (1U)
#define LPUART_STAT_RXEDGIF(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_RXEDGIF_SHIFT)) & LPUART_STAT_RXEDGIF_MASK)

#define LPUART_STAT_LBKDIF_MASK                  (0x80000000U)
#define LPUART_STAT_LBKDIF_SHIFT                 (31U)
#define LPUART_STAT_LBKDIF_WIDTH                 (1U)
#define LPUART_STAT_LBKDIF(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_LBKDIF_SHIFT)) & LPUART_STAT_LBKDIF_MASK)
/*! @} */

/*! @name CTRL - Control */
/*! @{ */

#define LPUART_CTRL_PT_MASK                      (0x1U)
#define LPUART_CTRL_PT_SHIFT                     (0U)
#define LPUART_CTRL_PT_WIDTH                     (1U)
#define LPUART_CTRL_PT(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_PT_SHIFT)) & LPUART_CTRL_PT_MASK)

#define LPUART_CTRL_PE_MASK                      (0x2U)
#define LPUART_CTRL_PE_SHIFT                     (1U)
#define LPUART_CTRL_PE_WIDTH                     (1U)
#define LPUART_CTRL_PE(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_PE_SHIFT)) & LPUART_CTRL_PE_MASK)

#define LPUART_CTRL_ILT_MASK                     (0x4U)
#define LPUART_CTRL_ILT_SHIFT                    (2U)
#define LPUART_CTRL_ILT_WIDTH                    (1U)
#define LPUART_CTRL_ILT(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_ILT_SHIFT)) & LPUART_CTRL_ILT_MASK)

#define LPUART_CTRL_WAKE_MASK                    (0x8U)
#define LPUART_CTRL_WAKE_SHIFT                   (3U)
#define LPUART_CTRL_WAKE_WIDTH                   (1U)
#define LPUART_CTRL_WAKE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_WAKE_SHIFT)) & LPUART_CTRL_WAKE_MASK)

#define LPUART_CTRL_M_MASK                       (0x10U)
#define LPUART_CTRL_M_SHIFT                      (4U)
#define LPUART_CTRL_M_WIDTH                      (1U)
#define LPUART_CTRL_M(x)                         (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_M_SHIFT)) & LPUART_CTRL_M_MASK)

#define LPUART_CTRL_RSRC_MASK                    (0x20U)
#define LPUART_CTRL_RSRC_SHIFT                   (5U)
#define LPUART_CTRL_RSRC_WIDTH                   (1U)
#define LPUART_CTRL_RSRC(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_RSRC_SHIFT)) & LPUART_CTRL_RSRC_MASK)

#define LPUART_CTRL_LOOPS_MASK                   (0x80U)
#define LPUART_CTRL_LOOPS_SHIFT                  (7U)
#define LPUART_CTRL_LOOPS_WIDTH                  (1U)
#define LPUART_CTRL_LOOPS(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_LOOPS_SHIFT)) & LPUART_CTRL_LOOPS_MASK)

#define LPUART_CTRL_IDLECFG_MASK                 (0x700U)
#define LPUART_CTRL_IDLECFG_SHIFT                (8U)
#define LPUART_CTRL_IDLECFG_WIDTH                (3U)
#define LPUART_CTRL_IDLECFG(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_IDLECFG_SHIFT)) & LPUART_CTRL_IDLECFG_MASK)

#define LPUART_CTRL_M7_MASK                      (0x800U)
#define LPUART_CTRL_M7_SHIFT                     (11U)
#define LPUART_CTRL_M7_WIDTH                     (1U)
#define LPUART_CTRL_M7(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_M7_SHIFT)) & LPUART_CTRL_M7_MASK)

#define LPUART_CTRL_SWAP_MASK                    (0x1000U)
#define LPUART_CTRL_SWAP_SHIFT                   (12U)
#define LPUART_CTRL_SWAP_WIDTH                   (1U)
#define LPUART_CTRL_SWAP(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_SWAP_SHIFT)) & LPUART_CTRL_SWAP_MASK)

#define LPUART_CTRL_MA2IE_MASK                   (0x4000U)
#define LPUART_CTRL_MA2IE_SHIFT                  (14U)
#define LPUART_CTRL_MA2IE_WIDTH                  (1U)
#define LPUART_CTRL_MA2IE(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_MA2IE_SHIFT)) & LPUART_CTRL_MA2IE_MASK)

#define LPUART_CTRL_MA1IE_MASK                   (0x8000U)
#define LPUART_CTRL_MA1IE_SHIFT                  (15U)
#define LPUART_CTRL_MA1IE_WIDTH                  (1U)
#define LPUART_CTRL_MA1IE(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_MA1IE_SHIFT)) & LPUART_CTRL_MA1IE_MASK)

#define LPUART_CTRL_SBK_MASK                     (0x10000U)
#define LPUART_CTRL_SBK_SHIFT                    (16U)
#define LPUART_CTRL_SBK_WIDTH                    (1U)
#define LPUART_CTRL_SBK(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_SBK_SHIFT)) & LPUART_CTRL_SBK_MASK)

#define LPUART_CTRL_RWU_MASK                     (0x20000U)
#define LPUART_CTRL_RWU_SHIFT                    (17U)
#define LPUART_CTRL_RWU_WIDTH                    (1U)
#define LPUART_CTRL_RWU(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_RWU_SHIFT)) & LPUART_CTRL_RWU_MASK)

#define LPUART_CTRL_RE_MASK                      (0x40000U)
#define LPUART_CTRL_RE_SHIFT                     (18U)
#define LPUART_CTRL_RE_WIDTH                     (1U)
#define LPUART_CTRL_RE(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_RE_SHIFT)) & LPUART_CTRL_RE_MASK)

#define LPUART_CTRL_TE_MASK                      (0x80000U)
#define LPUART_CTRL_TE_SHIFT                     (19U)
#define LPUART_CTRL_TE_WIDTH                     (1U)
#define LPUART_CTRL_TE(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_TE_SHIFT)) & LPUART_CTRL_TE_MASK)

#define LPUART_CTRL_ILIE_MASK                    (0x100000U)
#define LPUART_CTRL_ILIE_SHIFT                   (20U)
#define LPUART_CTRL_ILIE_WIDTH                   (1U)
#define LPUART_CTRL_ILIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_ILIE_SHIFT)) & LPUART_CTRL_ILIE_MASK)

#define LPUART_CTRL_RIE_MASK                     (0x200000U)
#define LPUART_CTRL_RIE_SHIFT                    (21U)
#define LPUART_CTRL_RIE_WIDTH                    (1U)
#define LPUART_CTRL_RIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_RIE_SHIFT)) & LPUART_CTRL_RIE_MASK)

#define LPUART_CTRL_TCIE_MASK                    (0x400000U)
#define LPUART_CTRL_TCIE_SHIFT                   (22U)
#define LPUART_CTRL_TCIE_WIDTH                   (1U)
#define LPUART_CTRL_TCIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_TCIE_SHIFT)) & LPUART_CTRL_TCIE_MASK)

#define LPUART_CTRL_TIE_MASK                     (0x800000U)
#define LPUART_CTRL_TIE_SHIFT                    (23U)
#define LPUART_CTRL_TIE_WIDTH                    (1U)
#define LPUART_CTRL_TIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_TIE_SHIFT)) & LPUART_CTRL_TIE_MASK)

#define LPUART_CTRL_PEIE_MASK                    (0x1000000U)
#define LPUART_CTRL_PEIE_SHIFT                   (24U)
#define LPUART_CTRL_PEIE_WIDTH                   (1U)
#define LPUART_CTRL_PEIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_PEIE_SHIFT)) & LPUART_CTRL_PEIE_MASK)

#define LPUART_CTRL_FEIE_MASK                    (0x2000000U)
#define LPUART_CTRL_FEIE_SHIFT                   (25U)
#define LPUART_CTRL_FEIE_WIDTH                   (1U)
#define LPUART_CTRL_FEIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_FEIE_SHIFT)) & LPUART_CTRL_FEIE_MASK)

#define LPUART_CTRL_NEIE_MASK                    (0x4000000U)
#define LPUART_CTRL_NEIE_SHIFT                   (26U)
#define LPUART_CTRL_NEIE_WIDTH                   (1U)
#define LPUART_CTRL_NEIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_NEIE_SHIFT)) & LPUART_CTRL_NEIE_MASK)

#define LPUART_CTRL_ORIE_MASK                    (0x8000000U)
#define LPUART_CTRL_ORIE_SHIFT                   (27U)
#define LPUART_CTRL_ORIE_WIDTH                   (1U)
#define LPUART_CTRL_ORIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_ORIE_SHIFT)) & LPUART_CTRL_ORIE_MASK)

#define LPUART_CTRL_TXINV_MASK                   (0x10000000U)
#define LPUART_CTRL_TXINV_SHIFT                  (28U)
#define LPUART_CTRL_TXINV_WIDTH                  (1U)
#define LPUART_CTRL_TXINV(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_TXINV_SHIFT)) & LPUART_CTRL_TXINV_MASK)

#define LPUART_CTRL_TXDIR_MASK                   (0x20000000U)
#define LPUART_CTRL_TXDIR_SHIFT                  (29U)
#define LPUART_CTRL_TXDIR_WIDTH                  (1U)
#define LPUART_CTRL_TXDIR(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_TXDIR_SHIFT)) & LPUART_CTRL_TXDIR_MASK)

#define LPUART_CTRL_R9T8_MASK                    (0x40000000U)
#define LPUART_CTRL_R9T8_SHIFT                   (30U)
#define LPUART_CTRL_R9T8_WIDTH                   (1U)
#define LPUART_CTRL_R9T8(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_R9T8_SHIFT)) & LPUART_CTRL_R9T8_MASK)

#define LPUART_CTRL_R8T9_MASK                    (0x80000000U)
#define LPUART_CTRL_R8T9_SHIFT                   (31U)
#define LPUART_CTRL_R8T9_WIDTH                   (1U)
#define LPUART_CTRL_R8T9(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_R8T9_SHIFT)) & LPUART_CTRL_R8T9_MASK)
/*! @} */

/*! @name DATA - Data */
/*! @{ */

#define LPUART_DATA_R0T0_MASK                    (0x1U)
#define LPUART_DATA_R0T0_SHIFT                   (0U)
#define LPUART_DATA_R0T0_WIDTH                   (1U)
#define LPUART_DATA_R0T0(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R0T0_SHIFT)) & LPUART_DATA_R0T0_MASK)

#define LPUART_DATA_R1T1_MASK                    (0x2U)
#define LPUART_DATA_R1T1_SHIFT                   (1U)
#define LPUART_DATA_R1T1_WIDTH                   (1U)
#define LPUART_DATA_R1T1(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R1T1_SHIFT)) & LPUART_DATA_R1T1_MASK)

#define LPUART_DATA_R2T2_MASK                    (0x4U)
#define LPUART_DATA_R2T2_SHIFT                   (2U)
#define LPUART_DATA_R2T2_WIDTH                   (1U)
#define LPUART_DATA_R2T2(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R2T2_SHIFT)) & LPUART_DATA_R2T2_MASK)

#define LPUART_DATA_R3T3_MASK                    (0x8U)
#define LPUART_DATA_R3T3_SHIFT                   (3U)
#define LPUART_DATA_R3T3_WIDTH                   (1U)
#define LPUART_DATA_R3T3(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R3T3_SHIFT)) & LPUART_DATA_R3T3_MASK)

#define LPUART_DATA_R4T4_MASK                    (0x10U)
#define LPUART_DATA_R4T4_SHIFT                   (4U)
#define LPUART_DATA_R4T4_WIDTH                   (1U)
#define LPUART_DATA_R4T4(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R4T4_SHIFT)) & LPUART_DATA_R4T4_MASK)

#define LPUART_DATA_R5T5_MASK                    (0x20U)
#define LPUART_DATA_R5T5_SHIFT                   (5U)
#define LPUART_DATA_R5T5_WIDTH                   (1U)
#define LPUART_DATA_R5T5(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R5T5_SHIFT)) & LPUART_DATA_R5T5_MASK)

#define LPUART_DATA_R6T6_MASK                    (0x40U)
#define LPUART_DATA_R6T6_SHIFT                   (6U)
#define LPUART_DATA_R6T6_WIDTH                   (1U)
#define LPUART_DATA_R6T6(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R6T6_SHIFT)) & LPUART_DATA_R6T6_MASK)

#define LPUART_DATA_R7T7_MASK                    (0x80U)
#define LPUART_DATA_R7T7_SHIFT                   (7U)
#define LPUART_DATA_R7T7_WIDTH                   (1U)
#define LPUART_DATA_R7T7(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R7T7_SHIFT)) & LPUART_DATA_R7T7_MASK)

#define LPUART_DATA_R8T8_MASK                    (0x100U)
#define LPUART_DATA_R8T8_SHIFT                   (8U)
#define LPUART_DATA_R8T8_WIDTH                   (1U)
#define LPUART_DATA_R8T8(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R8T8_SHIFT)) & LPUART_DATA_R8T8_MASK)

#define LPUART_DATA_R9T9_MASK                    (0x200U)
#define LPUART_DATA_R9T9_SHIFT                   (9U)
#define LPUART_DATA_R9T9_WIDTH                   (1U)
#define LPUART_DATA_R9T9(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R9T9_SHIFT)) & LPUART_DATA_R9T9_MASK)

#define LPUART_DATA_LINBRK_MASK                  (0x400U)
#define LPUART_DATA_LINBRK_SHIFT                 (10U)
#define LPUART_DATA_LINBRK_WIDTH                 (1U)
#define LPUART_DATA_LINBRK(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_LINBRK_SHIFT)) & LPUART_DATA_LINBRK_MASK)

#define LPUART_DATA_IDLINE_MASK                  (0x800U)
#define LPUART_DATA_IDLINE_SHIFT                 (11U)
#define LPUART_DATA_IDLINE_WIDTH                 (1U)
#define LPUART_DATA_IDLINE(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_IDLINE_SHIFT)) & LPUART_DATA_IDLINE_MASK)

#define LPUART_DATA_RXEMPT_MASK                  (0x1000U)
#define LPUART_DATA_RXEMPT_SHIFT                 (12U)
#define LPUART_DATA_RXEMPT_WIDTH                 (1U)
#define LPUART_DATA_RXEMPT(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_RXEMPT_SHIFT)) & LPUART_DATA_RXEMPT_MASK)

#define LPUART_DATA_FRETSC_MASK                  (0x2000U)
#define LPUART_DATA_FRETSC_SHIFT                 (13U)
#define LPUART_DATA_FRETSC_WIDTH                 (1U)
#define LPUART_DATA_FRETSC(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_FRETSC_SHIFT)) & LPUART_DATA_FRETSC_MASK)

#define LPUART_DATA_PARITYE_MASK                 (0x4000U)
#define LPUART_DATA_PARITYE_SHIFT                (14U)
#define LPUART_DATA_PARITYE_WIDTH                (1U)
#define LPUART_DATA_PARITYE(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_PARITYE_SHIFT)) & LPUART_DATA_PARITYE_MASK)

#define LPUART_DATA_NOISY_MASK                   (0x8000U)
#define LPUART_DATA_NOISY_SHIFT                  (15U)
#define LPUART_DATA_NOISY_WIDTH                  (1U)
#define LPUART_DATA_NOISY(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_NOISY_SHIFT)) & LPUART_DATA_NOISY_MASK)
/*! @} */

/*! @name MATCH - Match Address */
/*! @{ */

#define LPUART_MATCH_MA1_MASK                    (0x3FFU)
#define LPUART_MATCH_MA1_SHIFT                   (0U)
#define LPUART_MATCH_MA1_WIDTH                   (10U)
#define LPUART_MATCH_MA1(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_MATCH_MA1_SHIFT)) & LPUART_MATCH_MA1_MASK)

#define LPUART_MATCH_MA2_MASK                    (0x3FF0000U)
#define LPUART_MATCH_MA2_SHIFT                   (16U)
#define LPUART_MATCH_MA2_WIDTH                   (10U)
#define LPUART_MATCH_MA2(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_MATCH_MA2_SHIFT)) & LPUART_MATCH_MA2_MASK)
/*! @} */

/*! @name MODIR - MODEM IrDA */
/*! @{ */

#define LPUART_MODIR_TXCTSE_MASK                 (0x1U)
#define LPUART_MODIR_TXCTSE_SHIFT                (0U)
#define LPUART_MODIR_TXCTSE_WIDTH                (1U)
#define LPUART_MODIR_TXCTSE(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_TXCTSE_SHIFT)) & LPUART_MODIR_TXCTSE_MASK)

#define LPUART_MODIR_TXRTSE_MASK                 (0x2U)
#define LPUART_MODIR_TXRTSE_SHIFT                (1U)
#define LPUART_MODIR_TXRTSE_WIDTH                (1U)
#define LPUART_MODIR_TXRTSE(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_TXRTSE_SHIFT)) & LPUART_MODIR_TXRTSE_MASK)

#define LPUART_MODIR_TXRTSPOL_MASK               (0x4U)
#define LPUART_MODIR_TXRTSPOL_SHIFT              (2U)
#define LPUART_MODIR_TXRTSPOL_WIDTH              (1U)
#define LPUART_MODIR_TXRTSPOL(x)                 (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_TXRTSPOL_SHIFT)) & LPUART_MODIR_TXRTSPOL_MASK)

#define LPUART_MODIR_RXRTSE_MASK                 (0x8U)
#define LPUART_MODIR_RXRTSE_SHIFT                (3U)
#define LPUART_MODIR_RXRTSE_WIDTH                (1U)
#define LPUART_MODIR_RXRTSE(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_RXRTSE_SHIFT)) & LPUART_MODIR_RXRTSE_MASK)

#define LPUART_MODIR_TXCTSC_MASK                 (0x10U)
#define LPUART_MODIR_TXCTSC_SHIFT                (4U)
#define LPUART_MODIR_TXCTSC_WIDTH                (1U)
#define LPUART_MODIR_TXCTSC(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_TXCTSC_SHIFT)) & LPUART_MODIR_TXCTSC_MASK)

#define LPUART_MODIR_TXCTSSRC_MASK               (0x20U)
#define LPUART_MODIR_TXCTSSRC_SHIFT              (5U)
#define LPUART_MODIR_TXCTSSRC_WIDTH              (1U)
#define LPUART_MODIR_TXCTSSRC(x)                 (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_TXCTSSRC_SHIFT)) & LPUART_MODIR_TXCTSSRC_MASK)

#define LPUART_MODIR_RTSWATER_MASK               (0xF00U)  /* Merged from fields with different position or width, of widths (2, 4), largest definition used */
#define LPUART_MODIR_RTSWATER_SHIFT              (8U)
#define LPUART_MODIR_RTSWATER_WIDTH              (4U)
#define LPUART_MODIR_RTSWATER(x)                 (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_RTSWATER_SHIFT)) & LPUART_MODIR_RTSWATER_MASK)  /* Merged from fields with different position or width, of widths (2, 4), largest definition used */

#define LPUART_MODIR_TNP_MASK                    (0x30000U)
#define LPUART_MODIR_TNP_SHIFT                   (16U)
#define LPUART_MODIR_TNP_WIDTH                   (2U)
#define LPUART_MODIR_TNP(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_TNP_SHIFT)) & LPUART_MODIR_TNP_MASK)

#define LPUART_MODIR_IREN_MASK                   (0x40000U)
#define LPUART_MODIR_IREN_SHIFT                  (18U)
#define LPUART_MODIR_IREN_WIDTH                  (1U)
#define LPUART_MODIR_IREN(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_IREN_SHIFT)) & LPUART_MODIR_IREN_MASK)
/*! @} */

/*! @name FIFO - FIFO */
/*! @{ */

#define LPUART_FIFO_RXFIFOSIZE_MASK              (0x7U)
#define LPUART_FIFO_RXFIFOSIZE_SHIFT             (0U)
#define LPUART_FIFO_RXFIFOSIZE_WIDTH             (3U)
#define LPUART_FIFO_RXFIFOSIZE(x)                (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_RXFIFOSIZE_SHIFT)) & LPUART_FIFO_RXFIFOSIZE_MASK)

#define LPUART_FIFO_RXFE_MASK                    (0x8U)
#define LPUART_FIFO_RXFE_SHIFT                   (3U)
#define LPUART_FIFO_RXFE_WIDTH                   (1U)
#define LPUART_FIFO_RXFE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_RXFE_SHIFT)) & LPUART_FIFO_RXFE_MASK)

#define LPUART_FIFO_TXFIFOSIZE_MASK              (0x70U)
#define LPUART_FIFO_TXFIFOSIZE_SHIFT             (4U)
#define LPUART_FIFO_TXFIFOSIZE_WIDTH             (3U)
#define LPUART_FIFO_TXFIFOSIZE(x)                (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_TXFIFOSIZE_SHIFT)) & LPUART_FIFO_TXFIFOSIZE_MASK)

#define LPUART_FIFO_TXFE_MASK                    (0x80U)
#define LPUART_FIFO_TXFE_SHIFT                   (7U)
#define LPUART_FIFO_TXFE_WIDTH                   (1U)
#define LPUART_FIFO_TXFE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_TXFE_SHIFT)) & LPUART_FIFO_TXFE_MASK)

#define LPUART_FIFO_RXUFE_MASK                   (0x100U)
#define LPUART_FIFO_RXUFE_SHIFT                  (8U)
#define LPUART_FIFO_RXUFE_WIDTH                  (1U)
#define LPUART_FIFO_RXUFE(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_RXUFE_SHIFT)) & LPUART_FIFO_RXUFE_MASK)

#define LPUART_FIFO_TXOFE_MASK                   (0x200U)
#define LPUART_FIFO_TXOFE_SHIFT                  (9U)
#define LPUART_FIFO_TXOFE_WIDTH                  (1U)
#define LPUART_FIFO_TXOFE(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_TXOFE_SHIFT)) & LPUART_FIFO_TXOFE_MASK)

#define LPUART_FIFO_RXIDEN_MASK                  (0x1C00U)
#define LPUART_FIFO_RXIDEN_SHIFT                 (10U)
#define LPUART_FIFO_RXIDEN_WIDTH                 (3U)
#define LPUART_FIFO_RXIDEN(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_RXIDEN_SHIFT)) & LPUART_FIFO_RXIDEN_MASK)

#define LPUART_FIFO_RXFLUSH_MASK                 (0x4000U)
#define LPUART_FIFO_RXFLUSH_SHIFT                (14U)
#define LPUART_FIFO_RXFLUSH_WIDTH                (1U)
#define LPUART_FIFO_RXFLUSH(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_RXFLUSH_SHIFT)) & LPUART_FIFO_RXFLUSH_MASK)

#define LPUART_FIFO_TXFLUSH_MASK                 (0x8000U)
#define LPUART_FIFO_TXFLUSH_SHIFT                (15U)
#define LPUART_FIFO_TXFLUSH_WIDTH                (1U)
#define LPUART_FIFO_TXFLUSH(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_TXFLUSH_SHIFT)) & LPUART_FIFO_TXFLUSH_MASK)

#define LPUART_FIFO_RXUF_MASK                    (0x10000U)
#define LPUART_FIFO_RXUF_SHIFT                   (16U)
#define LPUART_FIFO_RXUF_WIDTH                   (1U)
#define LPUART_FIFO_RXUF(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_RXUF_SHIFT)) & LPUART_FIFO_RXUF_MASK)

#define LPUART_FIFO_TXOF_MASK                    (0x20000U)
#define LPUART_FIFO_TXOF_SHIFT                   (17U)
#define LPUART_FIFO_TXOF_WIDTH                   (1U)
#define LPUART_FIFO_TXOF(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_TXOF_SHIFT)) & LPUART_FIFO_TXOF_MASK)

#define LPUART_FIFO_RXEMPT_MASK                  (0x400000U)
#define LPUART_FIFO_RXEMPT_SHIFT                 (22U)
#define LPUART_FIFO_RXEMPT_WIDTH                 (1U)
#define LPUART_FIFO_RXEMPT(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_RXEMPT_SHIFT)) & LPUART_FIFO_RXEMPT_MASK)

#define LPUART_FIFO_TXEMPT_MASK                  (0x800000U)
#define LPUART_FIFO_TXEMPT_SHIFT                 (23U)
#define LPUART_FIFO_TXEMPT_WIDTH                 (1U)
#define LPUART_FIFO_TXEMPT(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_FIFO_TXEMPT_SHIFT)) & LPUART_FIFO_TXEMPT_MASK)
/*! @} */

/*! @name WATER - Watermark */
/*! @{ */

#define LPUART_WATER_TXWATER_MASK                (0xFU)  /* Merged from fields with different position or width, of widths (2, 4), largest definition used */
#define LPUART_WATER_TXWATER_SHIFT               (0U)
#define LPUART_WATER_TXWATER_WIDTH               (4U)
#define LPUART_WATER_TXWATER(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_WATER_TXWATER_SHIFT)) & LPUART_WATER_TXWATER_MASK)  /* Merged from fields with different position or width, of widths (2, 4), largest definition used */

#define LPUART_WATER_TXCOUNT_MASK                (0x1F00U)  /* Merged from fields with different position or width, of widths (3, 5), largest definition used */
#define LPUART_WATER_TXCOUNT_SHIFT               (8U)
#define LPUART_WATER_TXCOUNT_WIDTH               (5U)
#define LPUART_WATER_TXCOUNT(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_WATER_TXCOUNT_SHIFT)) & LPUART_WATER_TXCOUNT_MASK)  /* Merged from fields with different position or width, of widths (3, 5), largest definition used */

#define LPUART_WATER_RXWATER_MASK                (0xF0000U)  /* Merged from fields with different position or width, of widths (2, 4), largest definition used */
#define LPUART_WATER_RXWATER_SHIFT               (16U)
#define LPUART_WATER_RXWATER_WIDTH               (4U)
#define LPUART_WATER_RXWATER(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_WATER_RXWATER_SHIFT)) & LPUART_WATER_RXWATER_MASK)  /* Merged from fields with different position or width, of widths (2, 4), largest definition used */

#define LPUART_WATER_RXCOUNT_MASK                (0x1F000000U)  /* Merged from fields with different position or width, of widths (3, 5), largest definition used */
#define LPUART_WATER_RXCOUNT_SHIFT               (24U)
#define LPUART_WATER_RXCOUNT_WIDTH               (5U)
#define LPUART_WATER_RXCOUNT(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_WATER_RXCOUNT_SHIFT)) & LPUART_WATER_RXCOUNT_MASK)  /* Merged from fields with different position or width, of widths (3, 5), largest definition used */
/*! @} */

/*! @name DATARO - Data Read-Only */
/*! @{ */

#define LPUART_DATARO_DATA_MASK                  (0xFFFFU)
#define LPUART_DATARO_DATA_SHIFT                 (0U)
#define LPUART_DATARO_DATA_WIDTH                 (16U)
#define LPUART_DATARO_DATA(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_DATARO_DATA_SHIFT)) & LPUART_DATARO_DATA_MASK)
/*! @} */

/*! @name MCR - MODEM Control */
/*! @{ */

#define LPUART_MCR_CTS_MASK                      (0x1U)
#define LPUART_MCR_CTS_SHIFT                     (0U)
#define LPUART_MCR_CTS_WIDTH                     (1U)
#define LPUART_MCR_CTS(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_MCR_CTS_SHIFT)) & LPUART_MCR_CTS_MASK)

#define LPUART_MCR_DSR_MASK                      (0x2U)
#define LPUART_MCR_DSR_SHIFT                     (1U)
#define LPUART_MCR_DSR_WIDTH                     (1U)
#define LPUART_MCR_DSR(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_MCR_DSR_SHIFT)) & LPUART_MCR_DSR_MASK)

#define LPUART_MCR_RIN_MASK                      (0x4U)
#define LPUART_MCR_RIN_SHIFT                     (2U)
#define LPUART_MCR_RIN_WIDTH                     (1U)
#define LPUART_MCR_RIN(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_MCR_RIN_SHIFT)) & LPUART_MCR_RIN_MASK)

#define LPUART_MCR_DCD_MASK                      (0x8U)
#define LPUART_MCR_DCD_SHIFT                     (3U)
#define LPUART_MCR_DCD_WIDTH                     (1U)
#define LPUART_MCR_DCD(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_MCR_DCD_SHIFT)) & LPUART_MCR_DCD_MASK)

#define LPUART_MCR_DTR_MASK                      (0x100U)
#define LPUART_MCR_DTR_SHIFT                     (8U)
#define LPUART_MCR_DTR_WIDTH                     (1U)
#define LPUART_MCR_DTR(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_MCR_DTR_SHIFT)) & LPUART_MCR_DTR_MASK)

#define LPUART_MCR_RTS_MASK                      (0x200U)
#define LPUART_MCR_RTS_SHIFT                     (9U)
#define LPUART_MCR_RTS_WIDTH                     (1U)
#define LPUART_MCR_RTS(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_MCR_RTS_SHIFT)) & LPUART_MCR_RTS_MASK)
/*! @} */

/*! @name MSR - MODEM Status */
/*! @{ */

#define LPUART_MSR_DCTS_MASK                     (0x1U)
#define LPUART_MSR_DCTS_SHIFT                    (0U)
#define LPUART_MSR_DCTS_WIDTH                    (1U)
#define LPUART_MSR_DCTS(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_MSR_DCTS_SHIFT)) & LPUART_MSR_DCTS_MASK)

#define LPUART_MSR_DDSR_MASK                     (0x2U)
#define LPUART_MSR_DDSR_SHIFT                    (1U)
#define LPUART_MSR_DDSR_WIDTH                    (1U)
#define LPUART_MSR_DDSR(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_MSR_DDSR_SHIFT)) & LPUART_MSR_DDSR_MASK)

#define LPUART_MSR_DRI_MASK                      (0x4U)
#define LPUART_MSR_DRI_SHIFT                     (2U)
#define LPUART_MSR_DRI_WIDTH                     (1U)
#define LPUART_MSR_DRI(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_MSR_DRI_SHIFT)) & LPUART_MSR_DRI_MASK)

#define LPUART_MSR_DDCD_MASK                     (0x8U)
#define LPUART_MSR_DDCD_SHIFT                    (3U)
#define LPUART_MSR_DDCD_WIDTH                    (1U)
#define LPUART_MSR_DDCD(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_MSR_DDCD_SHIFT)) & LPUART_MSR_DDCD_MASK)

#define LPUART_MSR_CTS_MASK                      (0x10U)
#define LPUART_MSR_CTS_SHIFT                     (4U)
#define LPUART_MSR_CTS_WIDTH                     (1U)
#define LPUART_MSR_CTS(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_MSR_CTS_SHIFT)) & LPUART_MSR_CTS_MASK)

#define LPUART_MSR_DSR_MASK                      (0x20U)
#define LPUART_MSR_DSR_SHIFT                     (5U)
#define LPUART_MSR_DSR_WIDTH                     (1U)
#define LPUART_MSR_DSR(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_MSR_DSR_SHIFT)) & LPUART_MSR_DSR_MASK)

#define LPUART_MSR_RIN_MASK                      (0x40U)
#define LPUART_MSR_RIN_SHIFT                     (6U)
#define LPUART_MSR_RIN_WIDTH                     (1U)
#define LPUART_MSR_RIN(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_MSR_RIN_SHIFT)) & LPUART_MSR_RIN_MASK)

#define LPUART_MSR_DCD_MASK                      (0x80U)
#define LPUART_MSR_DCD_SHIFT                     (7U)
#define LPUART_MSR_DCD_WIDTH                     (1U)
#define LPUART_MSR_DCD(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_MSR_DCD_SHIFT)) & LPUART_MSR_DCD_MASK)
/*! @} */

/*! @name REIR - Receiver Extended Idle */
/*! @{ */

#define LPUART_REIR_IDTIME_MASK                  (0x3FFFU)
#define LPUART_REIR_IDTIME_SHIFT                 (0U)
#define LPUART_REIR_IDTIME_WIDTH                 (14U)
#define LPUART_REIR_IDTIME(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_REIR_IDTIME_SHIFT)) & LPUART_REIR_IDTIME_MASK)
/*! @} */

/*! @name TEIR - Transmitter Extended Idle */
/*! @{ */

#define LPUART_TEIR_IDTIME_MASK                  (0x3FFFU)
#define LPUART_TEIR_IDTIME_SHIFT                 (0U)
#define LPUART_TEIR_IDTIME_WIDTH                 (14U)
#define LPUART_TEIR_IDTIME(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_TEIR_IDTIME_SHIFT)) & LPUART_TEIR_IDTIME_MASK)
/*! @} */

/*! @name HDCR - Half Duplex Control */
/*! @{ */

#define LPUART_HDCR_TXSTALL_MASK                 (0x1U)
#define LPUART_HDCR_TXSTALL_SHIFT                (0U)
#define LPUART_HDCR_TXSTALL_WIDTH                (1U)
#define LPUART_HDCR_TXSTALL(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_HDCR_TXSTALL_SHIFT)) & LPUART_HDCR_TXSTALL_MASK)

#define LPUART_HDCR_RXSEL_MASK                   (0x2U)
#define LPUART_HDCR_RXSEL_SHIFT                  (1U)
#define LPUART_HDCR_RXSEL_WIDTH                  (1U)
#define LPUART_HDCR_RXSEL(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_HDCR_RXSEL_SHIFT)) & LPUART_HDCR_RXSEL_MASK)

#define LPUART_HDCR_RXWRMSK_MASK                 (0x4U)
#define LPUART_HDCR_RXWRMSK_SHIFT                (2U)
#define LPUART_HDCR_RXWRMSK_WIDTH                (1U)
#define LPUART_HDCR_RXWRMSK(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_HDCR_RXWRMSK_SHIFT)) & LPUART_HDCR_RXWRMSK_MASK)

#define LPUART_HDCR_RXMSK_MASK                   (0x8U)
#define LPUART_HDCR_RXMSK_SHIFT                  (3U)
#define LPUART_HDCR_RXMSK_WIDTH                  (1U)
#define LPUART_HDCR_RXMSK(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_HDCR_RXMSK_SHIFT)) & LPUART_HDCR_RXMSK_MASK)

#define LPUART_HDCR_RTSEXT_MASK                  (0xFF00U)
#define LPUART_HDCR_RTSEXT_SHIFT                 (8U)
#define LPUART_HDCR_RTSEXT_WIDTH                 (8U)
#define LPUART_HDCR_RTSEXT(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_HDCR_RTSEXT_SHIFT)) & LPUART_HDCR_RTSEXT_MASK)
/*! @} */

/*! @name TOCR - Timeout Control */
/*! @{ */

#define LPUART_TOCR_TOEN_MASK                    (0xFU)
#define LPUART_TOCR_TOEN_SHIFT                   (0U)
#define LPUART_TOCR_TOEN_WIDTH                   (4U)
#define LPUART_TOCR_TOEN(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_TOCR_TOEN_SHIFT)) & LPUART_TOCR_TOEN_MASK)

#define LPUART_TOCR_TOIE_MASK                    (0xF00U)
#define LPUART_TOCR_TOIE_SHIFT                   (8U)
#define LPUART_TOCR_TOIE_WIDTH                   (4U)
#define LPUART_TOCR_TOIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_TOCR_TOIE_SHIFT)) & LPUART_TOCR_TOIE_MASK)
/*! @} */

/*! @name TOSR - Timeout Status */
/*! @{ */

#define LPUART_TOSR_TOZ_MASK                     (0xFU)
#define LPUART_TOSR_TOZ_SHIFT                    (0U)
#define LPUART_TOSR_TOZ_WIDTH                    (4U)
#define LPUART_TOSR_TOZ(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_TOSR_TOZ_SHIFT)) & LPUART_TOSR_TOZ_MASK)

#define LPUART_TOSR_TOF_MASK                     (0xF00U)
#define LPUART_TOSR_TOF_SHIFT                    (8U)
#define LPUART_TOSR_TOF_WIDTH                    (4U)
#define LPUART_TOSR_TOF(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_TOSR_TOF_SHIFT)) & LPUART_TOSR_TOF_MASK)
/*! @} */

/*! @name TIMEOUT - Timeout N */
/*! @{ */

#define LPUART_TIMEOUT_TIMEOUT_MASK              (0x3FFFU)
#define LPUART_TIMEOUT_TIMEOUT_SHIFT             (0U)
#define LPUART_TIMEOUT_TIMEOUT_WIDTH             (14U)
#define LPUART_TIMEOUT_TIMEOUT(x)                (((uint32_t)(((uint32_t)(x)) << LPUART_TIMEOUT_TIMEOUT_SHIFT)) & LPUART_TIMEOUT_TIMEOUT_MASK)

#define LPUART_TIMEOUT_CFG_MASK                  (0xC0000000U)
#define LPUART_TIMEOUT_CFG_SHIFT                 (30U)
#define LPUART_TIMEOUT_CFG_WIDTH                 (2U)
#define LPUART_TIMEOUT_CFG(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_TIMEOUT_CFG_SHIFT)) & LPUART_TIMEOUT_CFG_MASK)
/*! @} */

/*! @name TCBR - Transmit Command Burst */
/*! @{ */

#define LPUART_TCBR_DATA_MASK                    (0xFFFFU)
#define LPUART_TCBR_DATA_SHIFT                   (0U)
#define LPUART_TCBR_DATA_WIDTH                   (16U)
#define LPUART_TCBR_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_TCBR_DATA_SHIFT)) & LPUART_TCBR_DATA_MASK)
/*! @} */

/*! @name TDBR - Transmit Data Burst */
/*! @{ */

#define LPUART_TDBR_DATA0_MASK                   (0xFFU)
#define LPUART_TDBR_DATA0_SHIFT                  (0U)
#define LPUART_TDBR_DATA0_WIDTH                  (8U)
#define LPUART_TDBR_DATA0(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_TDBR_DATA0_SHIFT)) & LPUART_TDBR_DATA0_MASK)

#define LPUART_TDBR_DATA1_MASK                   (0xFF00U)
#define LPUART_TDBR_DATA1_SHIFT                  (8U)
#define LPUART_TDBR_DATA1_WIDTH                  (8U)
#define LPUART_TDBR_DATA1(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_TDBR_DATA1_SHIFT)) & LPUART_TDBR_DATA1_MASK)

#define LPUART_TDBR_DATA2_MASK                   (0xFF0000U)
#define LPUART_TDBR_DATA2_SHIFT                  (16U)
#define LPUART_TDBR_DATA2_WIDTH                  (8U)
#define LPUART_TDBR_DATA2(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_TDBR_DATA2_SHIFT)) & LPUART_TDBR_DATA2_MASK)

#define LPUART_TDBR_DATA3_MASK                   (0xFF000000U)
#define LPUART_TDBR_DATA3_SHIFT                  (24U)
#define LPUART_TDBR_DATA3_WIDTH                  (8U)
#define LPUART_TDBR_DATA3(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_TDBR_DATA3_SHIFT)) & LPUART_TDBR_DATA3_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group LPUART_Register_Masks */

/*!
 * @}
 */ /* end of group LPUART_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_LPUART_H_) */
