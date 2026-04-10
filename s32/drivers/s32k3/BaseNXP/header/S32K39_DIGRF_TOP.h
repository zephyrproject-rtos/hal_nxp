/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K39_DIGRF_TOP.h
 * @version 1.7
 * @date 2022-11-18
 * @brief Peripheral Access Layer for S32K39_DIGRF_TOP
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
#if !defined(S32K39_DIGRF_TOP_H_)  /* Check if memory map has not been already included */
#define S32K39_DIGRF_TOP_H_

#include "S32K39_COMMON.h"

/* ----------------------------------------------------------------------------
   -- DIGRF_TOP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DIGRF_TOP_Peripheral_Access_Layer DIGRF_TOP Peripheral Access Layer
 * @{
 */

/** DIGRF_TOP - Size of Registers Arrays */
#define DIGRF_TOP_UNSTDR_COUNT                    9u
#define DIGRF_TOP_UNSRDR_COUNT                    9u
#define DIGRF_TOP_GPR_COUNT                       2u

/** DIGRF_TOP - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< LFAST Mode Configuration Register, offset: 0x0 */
  __IO uint32_t SCR;                               /**< LFAST Speed Control Register, offset: 0x4 */
  __IO uint32_t COCR;                              /**< LFAST Correlator Control Register, offset: 0x8 */
  __IO uint32_t TMCR;                              /**< LFAST Test Mode Control Register, offset: 0xC */
  __IO uint32_t ALCR;                              /**< LFAST Auto Loopback Control Register, offset: 0x10 */
  __IO uint32_t RCDCR;                             /**< LFAST Rate Change Delay Control Register, offset: 0x14 */
  __IO uint32_t SLCR;                              /**< LFAST Wakeup Delay Control Register, offset: 0x18 */
  __IO uint32_t ICR;                               /**< LFAST ICLC Control Register, offset: 0x1C */
  __IO uint32_t PICR;                              /**< LFAST Ping Control Register, offset: 0x20 */
  uint8_t RESERVED_0[8];
  __IO uint32_t RFCR;                              /**< LFAST Rx FIFO CTS Control Register, offset: 0x2C */
  __IO uint32_t TIER;                              /**< LFAST Tx Interrupt Enable Register, offset: 0x30 */
  __IO uint32_t RIER;                              /**< LFAST Rx Interrupt Enable Register, offset: 0x34 */
  __IO uint32_t RIIER;                             /**< LFAST Rx ICLC Interrupt Enable Register, offset: 0x38 */
  __IO uint32_t PLLCR;                             /**< LFAST PLL Control Register, offset: 0x3C */
  __IO uint32_t LCR;                               /**< LFAST LVDS Control Register, offset: 0x40 */
  __IO uint32_t UNSTCR;                            /**< LFAST Unsolicited Tx Control Register, offset: 0x44 */
  __IO uint32_t UNSTDR[DIGRF_TOP_UNSTDR_COUNT];    /**< LFAST Unsolicited Tx Data Registers, array offset: 0x48, array step: 0x4 */
  uint8_t RESERVED_1[20];
  __I  uint32_t GSR;                               /**< LFAST Global Status Register, offset: 0x80 */
  __I  uint32_t PISR;                              /**< LFAST Ping Status Register, offset: 0x84 */
  uint8_t RESERVED_2[12];
  __I  uint32_t DFSR;                              /**< LFAST Data Frame Status Register, offset: 0x94 */
  __IO uint32_t TISR;                              /**< LFAST Tx Interrupt Status Register, offset: 0x98 */
  __IO uint32_t RISR;                              /**< LFAST Rx Interrupt Status Register, offset: 0x9C */
  __IO uint32_t RIISR;                             /**< LFAST Rx ICLC Interrupt Status Register, offset: 0xA0 */
  __I  uint32_t PLLLSR;                            /**< LFAST PLL and LVDS Status Register, offset: 0xA4 */
  __IO uint32_t UNSRSR;                            /**< LFAST Unsolicited Rx Status Register, offset: 0xA8 */
  __I  uint32_t UNSRDR[DIGRF_TOP_UNSRDR_COUNT];    /**< LFAST Unsolicited Rx Data Register, array offset: 0xAC, array step: 0x4 */
  uint8_t RESERVED_3[4];
  __IO uint32_t GPR[DIGRF_TOP_GPR_COUNT];          /**< General Purpose registers, array offset: 0xD4, array step: 0x4 */
} DIGRF_TOP_Type, *DIGRF_TOP_MemMapPtr;

/** Number of instances of the DIGRF_TOP module. */
#define DIGRF_TOP_INSTANCE_COUNT                 (1u)

/* DIGRF_TOP - Peripheral instance base addresses */
/** Peripheral DIGRF_TOP base address */
#define IP_DIGRF_TOP_BASE                        (0x404F4000u)
/** Peripheral DIGRF_TOP base pointer */
#define IP_DIGRF_TOP                             ((DIGRF_TOP_Type *)IP_DIGRF_TOP_BASE)
/** Array initializer of DIGRF_TOP peripheral base addresses */
#define IP_DIGRF_TOP_BASE_ADDRS                  { IP_DIGRF_TOP_BASE }
/** Array initializer of DIGRF_TOP peripheral base pointers */
#define IP_DIGRF_TOP_BASE_PTRS                   { IP_DIGRF_TOP }

/* ----------------------------------------------------------------------------
   -- DIGRF_TOP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DIGRF_TOP_Register_Masks DIGRF_TOP Register Masks
 * @{
 */

/*! @name MCR - LFAST Mode Configuration Register */
/*! @{ */

#define DIGRF_TOP_MCR_DATAEN_MASK                (0x1U)
#define DIGRF_TOP_MCR_DATAEN_SHIFT               (0U)
#define DIGRF_TOP_MCR_DATAEN_WIDTH               (1U)
#define DIGRF_TOP_MCR_DATAEN(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_MCR_DATAEN_SHIFT)) & DIGRF_TOP_MCR_DATAEN_MASK)

#define DIGRF_TOP_MCR_DRFRST_MASK                (0x2U)
#define DIGRF_TOP_MCR_DRFRST_SHIFT               (1U)
#define DIGRF_TOP_MCR_DRFRST_WIDTH               (1U)
#define DIGRF_TOP_MCR_DRFRST(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_MCR_DRFRST_SHIFT)) & DIGRF_TOP_MCR_DRFRST_MASK)

#define DIGRF_TOP_MCR_CTSEN_MASK                 (0x8U)
#define DIGRF_TOP_MCR_CTSEN_SHIFT                (3U)
#define DIGRF_TOP_MCR_CTSEN_WIDTH                (1U)
#define DIGRF_TOP_MCR_CTSEN(x)                   (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_MCR_CTSEN_SHIFT)) & DIGRF_TOP_MCR_CTSEN_MASK)

#define DIGRF_TOP_MCR_TXARBD_MASK                (0x10U)
#define DIGRF_TOP_MCR_TXARBD_SHIFT               (4U)
#define DIGRF_TOP_MCR_TXARBD_WIDTH               (1U)
#define DIGRF_TOP_MCR_TXARBD(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_MCR_TXARBD_SHIFT)) & DIGRF_TOP_MCR_TXARBD_MASK)

#define DIGRF_TOP_MCR_TXEN_MASK                  (0x2000U)
#define DIGRF_TOP_MCR_TXEN_SHIFT                 (13U)
#define DIGRF_TOP_MCR_TXEN_WIDTH                 (1U)
#define DIGRF_TOP_MCR_TXEN(x)                    (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_MCR_TXEN_SHIFT)) & DIGRF_TOP_MCR_TXEN_MASK)

#define DIGRF_TOP_MCR_RXEN_MASK                  (0x4000U)
#define DIGRF_TOP_MCR_RXEN_SHIFT                 (14U)
#define DIGRF_TOP_MCR_RXEN_WIDTH                 (1U)
#define DIGRF_TOP_MCR_RXEN(x)                    (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_MCR_RXEN_SHIFT)) & DIGRF_TOP_MCR_RXEN_MASK)

#define DIGRF_TOP_MCR_DRFEN_MASK                 (0x8000U)
#define DIGRF_TOP_MCR_DRFEN_SHIFT                (15U)
#define DIGRF_TOP_MCR_DRFEN_WIDTH                (1U)
#define DIGRF_TOP_MCR_DRFEN(x)                   (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_MCR_DRFEN_SHIFT)) & DIGRF_TOP_MCR_DRFEN_MASK)

#define DIGRF_TOP_MCR_LSSEL_MASK                 (0x10000U)
#define DIGRF_TOP_MCR_LSSEL_SHIFT                (16U)
#define DIGRF_TOP_MCR_LSSEL_WIDTH                (1U)
#define DIGRF_TOP_MCR_LSSEL(x)                   (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_MCR_LSSEL_SHIFT)) & DIGRF_TOP_MCR_LSSEL_MASK)

#define DIGRF_TOP_MCR_IPGDBG_MASK                (0x1000000U)
#define DIGRF_TOP_MCR_IPGDBG_SHIFT               (24U)
#define DIGRF_TOP_MCR_IPGDBG_WIDTH               (1U)
#define DIGRF_TOP_MCR_IPGDBG(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_MCR_IPGDBG_SHIFT)) & DIGRF_TOP_MCR_IPGDBG_MASK)

#define DIGRF_TOP_MCR_MSEN_MASK                  (0x80000000U)
#define DIGRF_TOP_MCR_MSEN_SHIFT                 (31U)
#define DIGRF_TOP_MCR_MSEN_WIDTH                 (1U)
#define DIGRF_TOP_MCR_MSEN(x)                    (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_MCR_MSEN_SHIFT)) & DIGRF_TOP_MCR_MSEN_MASK)
/*! @} */

/*! @name SCR - LFAST Speed Control Register */
/*! @{ */

#define DIGRF_TOP_SCR_TDR_MASK                   (0x1U)
#define DIGRF_TOP_SCR_TDR_SHIFT                  (0U)
#define DIGRF_TOP_SCR_TDR_WIDTH                  (1U)
#define DIGRF_TOP_SCR_TDR(x)                     (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_SCR_TDR_SHIFT)) & DIGRF_TOP_SCR_TDR_MASK)

#define DIGRF_TOP_SCR_RDR_MASK                   (0x100U)
#define DIGRF_TOP_SCR_RDR_SHIFT                  (8U)
#define DIGRF_TOP_SCR_RDR_WIDTH                  (1U)
#define DIGRF_TOP_SCR_RDR(x)                     (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_SCR_RDR_SHIFT)) & DIGRF_TOP_SCR_RDR_MASK)

#define DIGRF_TOP_SCR_DRMD_MASK                  (0x10000U)
#define DIGRF_TOP_SCR_DRMD_SHIFT                 (16U)
#define DIGRF_TOP_SCR_DRMD_WIDTH                 (1U)
#define DIGRF_TOP_SCR_DRMD(x)                    (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_SCR_DRMD_SHIFT)) & DIGRF_TOP_SCR_DRMD_MASK)
/*! @} */

/*! @name COCR - LFAST Correlator Control Register */
/*! @{ */

#define DIGRF_TOP_COCR_PHSSEL_MASK               (0x1U)
#define DIGRF_TOP_COCR_PHSSEL_SHIFT              (0U)
#define DIGRF_TOP_COCR_PHSSEL_WIDTH              (1U)
#define DIGRF_TOP_COCR_PHSSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_COCR_PHSSEL_SHIFT)) & DIGRF_TOP_COCR_PHSSEL_MASK)

#define DIGRF_TOP_COCR_CORRTH_MASK               (0xEU)
#define DIGRF_TOP_COCR_CORRTH_SHIFT              (1U)
#define DIGRF_TOP_COCR_CORRTH_WIDTH              (3U)
#define DIGRF_TOP_COCR_CORRTH(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_COCR_CORRTH_SHIFT)) & DIGRF_TOP_COCR_CORRTH_MASK)

#define DIGRF_TOP_COCR_SMPSEL_MASK               (0xFF000000U)
#define DIGRF_TOP_COCR_SMPSEL_SHIFT              (24U)
#define DIGRF_TOP_COCR_SMPSEL_WIDTH              (8U)
#define DIGRF_TOP_COCR_SMPSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_COCR_SMPSEL_SHIFT)) & DIGRF_TOP_COCR_SMPSEL_MASK)
/*! @} */

/*! @name TMCR - LFAST Test Mode Control Register */
/*! @{ */

#define DIGRF_TOP_TMCR_LPFRMTH_MASK              (0xFFFFU)
#define DIGRF_TOP_TMCR_LPFRMTH_SHIFT             (0U)
#define DIGRF_TOP_TMCR_LPFRMTH_WIDTH             (16U)
#define DIGRF_TOP_TMCR_LPFRMTH(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_TMCR_LPFRMTH_SHIFT)) & DIGRF_TOP_TMCR_LPFRMTH_MASK)

#define DIGRF_TOP_TMCR_LPMOD_MASK                (0x70000U)
#define DIGRF_TOP_TMCR_LPMOD_SHIFT               (16U)
#define DIGRF_TOP_TMCR_LPMOD_WIDTH               (3U)
#define DIGRF_TOP_TMCR_LPMOD(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_TMCR_LPMOD_SHIFT)) & DIGRF_TOP_TMCR_LPMOD_MASK)

#define DIGRF_TOP_TMCR_LPON_MASK                 (0x1000000U)
#define DIGRF_TOP_TMCR_LPON_SHIFT                (24U)
#define DIGRF_TOP_TMCR_LPON_WIDTH                (1U)
#define DIGRF_TOP_TMCR_LPON(x)                   (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_TMCR_LPON_SHIFT)) & DIGRF_TOP_TMCR_LPON_MASK)

#define DIGRF_TOP_TMCR_CLKTST_MASK               (0x2000000U)
#define DIGRF_TOP_TMCR_CLKTST_SHIFT              (25U)
#define DIGRF_TOP_TMCR_CLKTST_WIDTH              (1U)
#define DIGRF_TOP_TMCR_CLKTST(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_TMCR_CLKTST_SHIFT)) & DIGRF_TOP_TMCR_CLKTST_MASK)
/*! @} */

/*! @name ALCR - LFAST Auto Loopback Control Register */
/*! @{ */

#define DIGRF_TOP_ALCR_LPFMCNT_MASK              (0xFFFFU)
#define DIGRF_TOP_ALCR_LPFMCNT_SHIFT             (0U)
#define DIGRF_TOP_ALCR_LPFMCNT_WIDTH             (16U)
#define DIGRF_TOP_ALCR_LPFMCNT(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_ALCR_LPFMCNT_SHIFT)) & DIGRF_TOP_ALCR_LPFMCNT_MASK)

#define DIGRF_TOP_ALCR_LPCNTEN_MASK              (0x10000U)
#define DIGRF_TOP_ALCR_LPCNTEN_SHIFT             (16U)
#define DIGRF_TOP_ALCR_LPCNTEN_WIDTH             (1U)
#define DIGRF_TOP_ALCR_LPCNTEN(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_ALCR_LPCNTEN_SHIFT)) & DIGRF_TOP_ALCR_LPCNTEN_MASK)
/*! @} */

/*! @name RCDCR - LFAST Rate Change Delay Control Register */
/*! @{ */

#define DIGRF_TOP_RCDCR_DRCNT_MASK               (0xF0000U)
#define DIGRF_TOP_RCDCR_DRCNT_SHIFT              (16U)
#define DIGRF_TOP_RCDCR_DRCNT_WIDTH              (4U)
#define DIGRF_TOP_RCDCR_DRCNT(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RCDCR_DRCNT_SHIFT)) & DIGRF_TOP_RCDCR_DRCNT_MASK)
/*! @} */

/*! @name SLCR - LFAST Wakeup Delay Control Register */
/*! @{ */

#define DIGRF_TOP_SLCR_LWKCNT_MASK               (0xFU)
#define DIGRF_TOP_SLCR_LWKCNT_SHIFT              (0U)
#define DIGRF_TOP_SLCR_LWKCNT_WIDTH              (4U)
#define DIGRF_TOP_SLCR_LWKCNT(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_SLCR_LWKCNT_SHIFT)) & DIGRF_TOP_SLCR_LWKCNT_MASK)

#define DIGRF_TOP_SLCR_HWKCNT_MASK               (0xFF00U)
#define DIGRF_TOP_SLCR_HWKCNT_SHIFT              (8U)
#define DIGRF_TOP_SLCR_HWKCNT_WIDTH              (8U)
#define DIGRF_TOP_SLCR_HWKCNT(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_SLCR_HWKCNT_SHIFT)) & DIGRF_TOP_SLCR_HWKCNT_MASK)

#define DIGRF_TOP_SLCR_LSCNT_MASK                (0xF0000U)
#define DIGRF_TOP_SLCR_LSCNT_SHIFT               (16U)
#define DIGRF_TOP_SLCR_LSCNT_WIDTH               (4U)
#define DIGRF_TOP_SLCR_LSCNT(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_SLCR_LSCNT_SHIFT)) & DIGRF_TOP_SLCR_LSCNT_MASK)

#define DIGRF_TOP_SLCR_HSCNT_MASK                (0xFF000000U)
#define DIGRF_TOP_SLCR_HSCNT_SHIFT               (24U)
#define DIGRF_TOP_SLCR_HSCNT_WIDTH               (8U)
#define DIGRF_TOP_SLCR_HSCNT(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_SLCR_HSCNT_SHIFT)) & DIGRF_TOP_SLCR_HSCNT_MASK)
/*! @} */

/*! @name ICR - LFAST ICLC Control Register */
/*! @{ */

#define DIGRF_TOP_ICR_ICLCPLD_MASK               (0xFFU)
#define DIGRF_TOP_ICR_ICLCPLD_SHIFT              (0U)
#define DIGRF_TOP_ICR_ICLCPLD_WIDTH              (8U)
#define DIGRF_TOP_ICR_ICLCPLD(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_ICR_ICLCPLD_SHIFT)) & DIGRF_TOP_ICR_ICLCPLD_MASK)

#define DIGRF_TOP_ICR_SNDICLC_MASK               (0x10000U)
#define DIGRF_TOP_ICR_SNDICLC_SHIFT              (16U)
#define DIGRF_TOP_ICR_SNDICLC_WIDTH              (1U)
#define DIGRF_TOP_ICR_SNDICLC(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_ICR_SNDICLC_SHIFT)) & DIGRF_TOP_ICR_SNDICLC_MASK)

#define DIGRF_TOP_ICR_ICLCSEQ_MASK               (0x20000U)
#define DIGRF_TOP_ICR_ICLCSEQ_SHIFT              (17U)
#define DIGRF_TOP_ICR_ICLCSEQ_WIDTH              (1U)
#define DIGRF_TOP_ICR_ICLCSEQ(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_ICR_ICLCSEQ_SHIFT)) & DIGRF_TOP_ICR_ICLCSEQ_MASK)
/*! @} */

/*! @name PICR - LFAST Ping Control Register */
/*! @{ */

#define DIGRF_TOP_PICR_PNGPYLD_MASK              (0xFFU)
#define DIGRF_TOP_PICR_PNGPYLD_SHIFT             (0U)
#define DIGRF_TOP_PICR_PNGPYLD_WIDTH             (8U)
#define DIGRF_TOP_PICR_PNGPYLD(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_PICR_PNGPYLD_SHIFT)) & DIGRF_TOP_PICR_PNGPYLD_MASK)

#define DIGRF_TOP_PICR_PNGAUTO_MASK              (0x8000U)
#define DIGRF_TOP_PICR_PNGAUTO_SHIFT             (15U)
#define DIGRF_TOP_PICR_PNGAUTO_WIDTH             (1U)
#define DIGRF_TOP_PICR_PNGAUTO(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_PICR_PNGAUTO_SHIFT)) & DIGRF_TOP_PICR_PNGAUTO_MASK)

#define DIGRF_TOP_PICR_PNGREQ_MASK               (0x10000U)
#define DIGRF_TOP_PICR_PNGREQ_SHIFT              (16U)
#define DIGRF_TOP_PICR_PNGREQ_WIDTH              (1U)
#define DIGRF_TOP_PICR_PNGREQ(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_PICR_PNGREQ_SHIFT)) & DIGRF_TOP_PICR_PNGREQ_MASK)
/*! @} */

/*! @name RFCR - LFAST Rx FIFO CTS Control Register */
/*! @{ */

#define DIGRF_TOP_RFCR_RCTSMN_MASK               (0x3FU)
#define DIGRF_TOP_RFCR_RCTSMN_SHIFT              (0U)
#define DIGRF_TOP_RFCR_RCTSMN_WIDTH              (6U)
#define DIGRF_TOP_RFCR_RCTSMN(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RFCR_RCTSMN_SHIFT)) & DIGRF_TOP_RFCR_RCTSMN_MASK)

#define DIGRF_TOP_RFCR_RCTSMX_MASK               (0x3F0000U)
#define DIGRF_TOP_RFCR_RCTSMX_SHIFT              (16U)
#define DIGRF_TOP_RFCR_RCTSMX_WIDTH              (6U)
#define DIGRF_TOP_RFCR_RCTSMX(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RFCR_RCTSMX_SHIFT)) & DIGRF_TOP_RFCR_RCTSMX_MASK)
/*! @} */

/*! @name TIER - LFAST Tx Interrupt Enable Register */
/*! @{ */

#define DIGRF_TOP_TIER_TXDTIE_MASK               (0x1U)
#define DIGRF_TOP_TIER_TXDTIE_SHIFT              (0U)
#define DIGRF_TOP_TIER_TXDTIE_WIDTH              (1U)
#define DIGRF_TOP_TIER_TXDTIE(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_TIER_TXDTIE_SHIFT)) & DIGRF_TOP_TIER_TXDTIE_MASK)

#define DIGRF_TOP_TIER_TXICLCIE_MASK             (0x2U)
#define DIGRF_TOP_TIER_TXICLCIE_SHIFT            (1U)
#define DIGRF_TOP_TIER_TXICLCIE_WIDTH            (1U)
#define DIGRF_TOP_TIER_TXICLCIE(x)               (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_TIER_TXICLCIE_SHIFT)) & DIGRF_TOP_TIER_TXICLCIE_MASK)

#define DIGRF_TOP_TIER_TXUNSIE_MASK              (0x4U)
#define DIGRF_TOP_TIER_TXUNSIE_SHIFT             (2U)
#define DIGRF_TOP_TIER_TXUNSIE_WIDTH             (1U)
#define DIGRF_TOP_TIER_TXUNSIE(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_TIER_TXUNSIE_SHIFT)) & DIGRF_TOP_TIER_TXUNSIE_MASK)

#define DIGRF_TOP_TIER_TXPNGIE_MASK              (0x10U)
#define DIGRF_TOP_TIER_TXPNGIE_SHIFT             (4U)
#define DIGRF_TOP_TIER_TXPNGIE_WIDTH             (1U)
#define DIGRF_TOP_TIER_TXPNGIE(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_TIER_TXPNGIE_SHIFT)) & DIGRF_TOP_TIER_TXPNGIE_MASK)

#define DIGRF_TOP_TIER_TXOVIE_MASK               (0x10000U)
#define DIGRF_TOP_TIER_TXOVIE_SHIFT              (16U)
#define DIGRF_TOP_TIER_TXOVIE_WIDTH              (1U)
#define DIGRF_TOP_TIER_TXOVIE(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_TIER_TXOVIE_SHIFT)) & DIGRF_TOP_TIER_TXOVIE_MASK)

#define DIGRF_TOP_TIER_TXIIE_MASK                (0x20000U)
#define DIGRF_TOP_TIER_TXIIE_SHIFT               (17U)
#define DIGRF_TOP_TIER_TXIIE_WIDTH               (1U)
#define DIGRF_TOP_TIER_TXIIE(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_TIER_TXIIE_SHIFT)) & DIGRF_TOP_TIER_TXIIE_MASK)
/*! @} */

/*! @name RIER - LFAST Rx Interrupt Enable Register */
/*! @{ */

#define DIGRF_TOP_RIER_RXUNSIE_MASK              (0x2U)
#define DIGRF_TOP_RIER_RXUNSIE_SHIFT             (1U)
#define DIGRF_TOP_RIER_RXUNSIE_WIDTH             (1U)
#define DIGRF_TOP_RIER_RXUNSIE(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIER_RXUNSIE_SHIFT)) & DIGRF_TOP_RIER_RXUNSIE_MASK)

#define DIGRF_TOP_RIER_RXDIE_MASK                (0x4U)
#define DIGRF_TOP_RIER_RXDIE_SHIFT               (2U)
#define DIGRF_TOP_RIER_RXDIE_WIDTH               (1U)
#define DIGRF_TOP_RIER_RXDIE(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIER_RXDIE_SHIFT)) & DIGRF_TOP_RIER_RXDIE_MASK)

#define DIGRF_TOP_RIER_RXCTSIE_MASK              (0x8U)
#define DIGRF_TOP_RIER_RXCTSIE_SHIFT             (3U)
#define DIGRF_TOP_RIER_RXCTSIE_WIDTH             (1U)
#define DIGRF_TOP_RIER_RXCTSIE(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIER_RXCTSIE_SHIFT)) & DIGRF_TOP_RIER_RXCTSIE_MASK)

#define DIGRF_TOP_RIER_RXLCEIE_MASK              (0x10000U)
#define DIGRF_TOP_RIER_RXLCEIE_SHIFT             (16U)
#define DIGRF_TOP_RIER_RXLCEIE_WIDTH             (1U)
#define DIGRF_TOP_RIER_RXLCEIE(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIER_RXLCEIE_SHIFT)) & DIGRF_TOP_RIER_RXLCEIE_MASK)

#define DIGRF_TOP_RIER_RXICIE_MASK               (0x20000U)
#define DIGRF_TOP_RIER_RXICIE_SHIFT              (17U)
#define DIGRF_TOP_RIER_RXICIE_WIDTH              (1U)
#define DIGRF_TOP_RIER_RXICIE(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIER_RXICIE_SHIFT)) & DIGRF_TOP_RIER_RXICIE_MASK)

#define DIGRF_TOP_RIER_RXSZIE_MASK               (0x40000U)
#define DIGRF_TOP_RIER_RXSZIE_SHIFT              (18U)
#define DIGRF_TOP_RIER_RXSZIE_WIDTH              (1U)
#define DIGRF_TOP_RIER_RXSZIE(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIER_RXSZIE_SHIFT)) & DIGRF_TOP_RIER_RXSZIE_MASK)

#define DIGRF_TOP_RIER_RXOFIE_MASK               (0x80000U)
#define DIGRF_TOP_RIER_RXOFIE_SHIFT              (19U)
#define DIGRF_TOP_RIER_RXOFIE_WIDTH              (1U)
#define DIGRF_TOP_RIER_RXOFIE(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIER_RXOFIE_SHIFT)) & DIGRF_TOP_RIER_RXOFIE_MASK)

#define DIGRF_TOP_RIER_RXUFIE_MASK               (0x100000U)
#define DIGRF_TOP_RIER_RXUFIE_SHIFT              (20U)
#define DIGRF_TOP_RIER_RXUFIE_WIDTH              (1U)
#define DIGRF_TOP_RIER_RXUFIE(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIER_RXUFIE_SHIFT)) & DIGRF_TOP_RIER_RXUFIE_MASK)

#define DIGRF_TOP_RIER_RXMXIE_MASK               (0x200000U)
#define DIGRF_TOP_RIER_RXMXIE_SHIFT              (21U)
#define DIGRF_TOP_RIER_RXMXIE_WIDTH              (1U)
#define DIGRF_TOP_RIER_RXMXIE(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIER_RXMXIE_SHIFT)) & DIGRF_TOP_RIER_RXMXIE_MASK)

#define DIGRF_TOP_RIER_RXMNIE_MASK               (0x400000U)
#define DIGRF_TOP_RIER_RXMNIE_SHIFT              (22U)
#define DIGRF_TOP_RIER_RXMNIE_WIDTH              (1U)
#define DIGRF_TOP_RIER_RXMNIE(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIER_RXMNIE_SHIFT)) & DIGRF_TOP_RIER_RXMNIE_MASK)

#define DIGRF_TOP_RIER_RXUOIE_MASK               (0x800000U)
#define DIGRF_TOP_RIER_RXUOIE_SHIFT              (23U)
#define DIGRF_TOP_RIER_RXUOIE_WIDTH              (1U)
#define DIGRF_TOP_RIER_RXUOIE(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIER_RXUOIE_SHIFT)) & DIGRF_TOP_RIER_RXUOIE_MASK)
/*! @} */

/*! @name RIIER - LFAST Rx ICLC Interrupt Enable Register */
/*! @{ */

#define DIGRF_TOP_RIIER_ICPONIE_MASK             (0x1U)
#define DIGRF_TOP_RIIER_ICPONIE_SHIFT            (0U)
#define DIGRF_TOP_RIIER_ICPONIE_WIDTH            (1U)
#define DIGRF_TOP_RIIER_ICPONIE(x)               (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIIER_ICPONIE_SHIFT)) & DIGRF_TOP_RIIER_ICPONIE_MASK)

#define DIGRF_TOP_RIIER_ICPOFIE_MASK             (0x2U)
#define DIGRF_TOP_RIIER_ICPOFIE_SHIFT            (1U)
#define DIGRF_TOP_RIIER_ICPOFIE_WIDTH            (1U)
#define DIGRF_TOP_RIIER_ICPOFIE(x)               (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIIER_ICPOFIE_SHIFT)) & DIGRF_TOP_RIIER_ICPOFIE_MASK)

#define DIGRF_TOP_RIIER_ICTSIE_MASK              (0x4U)
#define DIGRF_TOP_RIIER_ICTSIE_SHIFT             (2U)
#define DIGRF_TOP_RIIER_ICTSIE_WIDTH             (1U)
#define DIGRF_TOP_RIIER_ICTSIE(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIIER_ICTSIE_SHIFT)) & DIGRF_TOP_RIIER_ICTSIE_MASK)

#define DIGRF_TOP_RIIER_ICTFIE_MASK              (0x8U)
#define DIGRF_TOP_RIIER_ICTFIE_SHIFT             (3U)
#define DIGRF_TOP_RIIER_ICTFIE_WIDTH             (1U)
#define DIGRF_TOP_RIIER_ICTFIE(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIIER_ICTFIE_SHIFT)) & DIGRF_TOP_RIIER_ICTFIE_MASK)

#define DIGRF_TOP_RIIER_ICRSIE_MASK              (0x10U)
#define DIGRF_TOP_RIIER_ICRSIE_SHIFT             (4U)
#define DIGRF_TOP_RIIER_ICRSIE_WIDTH             (1U)
#define DIGRF_TOP_RIIER_ICRSIE(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIIER_ICRSIE_SHIFT)) & DIGRF_TOP_RIIER_ICRSIE_MASK)

#define DIGRF_TOP_RIIER_ICRFIE_MASK              (0x20U)
#define DIGRF_TOP_RIIER_ICRFIE_SHIFT             (5U)
#define DIGRF_TOP_RIIER_ICRFIE_WIDTH             (1U)
#define DIGRF_TOP_RIIER_ICRFIE(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIIER_ICRFIE_SHIFT)) & DIGRF_TOP_RIIER_ICRFIE_MASK)

#define DIGRF_TOP_RIIER_ICTEIE_MASK              (0x40U)
#define DIGRF_TOP_RIIER_ICTEIE_SHIFT             (6U)
#define DIGRF_TOP_RIIER_ICTEIE_WIDTH             (1U)
#define DIGRF_TOP_RIIER_ICTEIE(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIIER_ICTEIE_SHIFT)) & DIGRF_TOP_RIIER_ICTEIE_MASK)

#define DIGRF_TOP_RIIER_ICTDIE_MASK              (0x80U)
#define DIGRF_TOP_RIIER_ICTDIE_SHIFT             (7U)
#define DIGRF_TOP_RIIER_ICTDIE_WIDTH             (1U)
#define DIGRF_TOP_RIIER_ICTDIE(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIIER_ICTDIE_SHIFT)) & DIGRF_TOP_RIIER_ICTDIE_MASK)

#define DIGRF_TOP_RIIER_ICCTIE_MASK              (0x100U)
#define DIGRF_TOP_RIIER_ICCTIE_SHIFT             (8U)
#define DIGRF_TOP_RIIER_ICCTIE_WIDTH             (1U)
#define DIGRF_TOP_RIIER_ICCTIE(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIIER_ICCTIE_SHIFT)) & DIGRF_TOP_RIIER_ICCTIE_MASK)

#define DIGRF_TOP_RIIER_ICLPIE_MASK              (0x200U)
#define DIGRF_TOP_RIIER_ICLPIE_SHIFT             (9U)
#define DIGRF_TOP_RIIER_ICLPIE_WIDTH             (1U)
#define DIGRF_TOP_RIIER_ICLPIE(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIIER_ICLPIE_SHIFT)) & DIGRF_TOP_RIIER_ICLPIE_MASK)

#define DIGRF_TOP_RIIER_ICTOIE_MASK              (0x400U)
#define DIGRF_TOP_RIIER_ICTOIE_SHIFT             (10U)
#define DIGRF_TOP_RIIER_ICTOIE_WIDTH             (1U)
#define DIGRF_TOP_RIIER_ICTOIE(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIIER_ICTOIE_SHIFT)) & DIGRF_TOP_RIIER_ICTOIE_MASK)

#define DIGRF_TOP_RIIER_ICPRIE_MASK              (0x800U)
#define DIGRF_TOP_RIIER_ICPRIE_SHIFT             (11U)
#define DIGRF_TOP_RIIER_ICPRIE_WIDTH             (1U)
#define DIGRF_TOP_RIIER_ICPRIE(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIIER_ICPRIE_SHIFT)) & DIGRF_TOP_RIIER_ICPRIE_MASK)

#define DIGRF_TOP_RIIER_ICPSIE_MASK              (0x1000U)
#define DIGRF_TOP_RIIER_ICPSIE_SHIFT             (12U)
#define DIGRF_TOP_RIIER_ICPSIE_WIDTH             (1U)
#define DIGRF_TOP_RIIER_ICPSIE(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIIER_ICPSIE_SHIFT)) & DIGRF_TOP_RIIER_ICPSIE_MASK)

#define DIGRF_TOP_RIIER_ICPFIE_MASK              (0x2000U)
#define DIGRF_TOP_RIIER_ICPFIE_SHIFT             (13U)
#define DIGRF_TOP_RIIER_ICPFIE_WIDTH             (1U)
#define DIGRF_TOP_RIIER_ICPFIE(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIIER_ICPFIE_SHIFT)) & DIGRF_TOP_RIIER_ICPFIE_MASK)
/*! @} */

/*! @name PLLCR - LFAST PLL Control Register */
/*! @{ */

#define DIGRF_TOP_PLLCR_PREDIV_MASK              (0x3U)
#define DIGRF_TOP_PLLCR_PREDIV_SHIFT             (0U)
#define DIGRF_TOP_PLLCR_PREDIV_WIDTH             (2U)
#define DIGRF_TOP_PLLCR_PREDIV(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_PLLCR_PREDIV_SHIFT)) & DIGRF_TOP_PLLCR_PREDIV_MASK)

#define DIGRF_TOP_PLLCR_FBDIV_MASK               (0xFCU)
#define DIGRF_TOP_PLLCR_FBDIV_SHIFT              (2U)
#define DIGRF_TOP_PLLCR_FBDIV_WIDTH              (6U)
#define DIGRF_TOP_PLLCR_FBDIV(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_PLLCR_FBDIV_SHIFT)) & DIGRF_TOP_PLLCR_FBDIV_MASK)

#define DIGRF_TOP_PLLCR_FDIVEN_MASK              (0x100U)
#define DIGRF_TOP_PLLCR_FDIVEN_SHIFT             (8U)
#define DIGRF_TOP_PLLCR_FDIVEN_WIDTH             (1U)
#define DIGRF_TOP_PLLCR_FDIVEN(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_PLLCR_FDIVEN_SHIFT)) & DIGRF_TOP_PLLCR_FDIVEN_MASK)

#define DIGRF_TOP_PLLCR_PLCKCW_MASK              (0x600U)
#define DIGRF_TOP_PLLCR_PLCKCW_SHIFT             (9U)
#define DIGRF_TOP_PLLCR_PLCKCW_WIDTH             (2U)
#define DIGRF_TOP_PLLCR_PLCKCW(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_PLLCR_PLCKCW_SHIFT)) & DIGRF_TOP_PLLCR_PLCKCW_MASK)

#define DIGRF_TOP_PLLCR_LPCFG_MASK               (0x6000U)
#define DIGRF_TOP_PLLCR_LPCFG_SHIFT              (13U)
#define DIGRF_TOP_PLLCR_LPCFG_WIDTH              (2U)
#define DIGRF_TOP_PLLCR_LPCFG(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_PLLCR_LPCFG_SHIFT)) & DIGRF_TOP_PLLCR_LPCFG_MASK)

#define DIGRF_TOP_PLLCR_REFINV_MASK              (0x8000U)
#define DIGRF_TOP_PLLCR_REFINV_SHIFT             (15U)
#define DIGRF_TOP_PLLCR_REFINV_WIDTH             (1U)
#define DIGRF_TOP_PLLCR_REFINV(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_PLLCR_REFINV_SHIFT)) & DIGRF_TOP_PLLCR_REFINV_MASK)

#define DIGRF_TOP_PLLCR_SWPON_MASK               (0x10000U)
#define DIGRF_TOP_PLLCR_SWPON_SHIFT              (16U)
#define DIGRF_TOP_PLLCR_SWPON_WIDTH              (1U)
#define DIGRF_TOP_PLLCR_SWPON(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_PLLCR_SWPON_SHIFT)) & DIGRF_TOP_PLLCR_SWPON_MASK)

#define DIGRF_TOP_PLLCR_SWPOFF_MASK              (0x20000U)
#define DIGRF_TOP_PLLCR_SWPOFF_SHIFT             (17U)
#define DIGRF_TOP_PLLCR_SWPOFF_WIDTH             (1U)
#define DIGRF_TOP_PLLCR_SWPOFF(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_PLLCR_SWPOFF_SHIFT)) & DIGRF_TOP_PLLCR_SWPOFF_MASK)
/*! @} */

/*! @name LCR - LFAST LVDS Control Register */
/*! @{ */

#define DIGRF_TOP_LCR_LVRXOP_BR_MASK             (0x8U)
#define DIGRF_TOP_LCR_LVRXOP_BR_SHIFT            (3U)
#define DIGRF_TOP_LCR_LVRXOP_BR_WIDTH            (1U)
#define DIGRF_TOP_LCR_LVRXOP_BR(x)               (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_LCR_LVRXOP_BR_SHIFT)) & DIGRF_TOP_LCR_LVRXOP_BR_MASK)

#define DIGRF_TOP_LCR_LVRXOP_TR_MASK             (0x20U)
#define DIGRF_TOP_LCR_LVRXOP_TR_SHIFT            (5U)
#define DIGRF_TOP_LCR_LVRXOP_TR_WIDTH            (1U)
#define DIGRF_TOP_LCR_LVRXOP_TR(x)               (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_LCR_LVRXOP_TR_SHIFT)) & DIGRF_TOP_LCR_LVRXOP_TR_MASK)

#define DIGRF_TOP_LCR_LVLPEN_MASK                (0x800U)
#define DIGRF_TOP_LCR_LVLPEN_SHIFT               (11U)
#define DIGRF_TOP_LCR_LVLPEN_WIDTH               (1U)
#define DIGRF_TOP_LCR_LVLPEN(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_LCR_LVLPEN_SHIFT)) & DIGRF_TOP_LCR_LVLPEN_MASK)

#define DIGRF_TOP_LCR_LVRFEN_MASK                (0x1000U)
#define DIGRF_TOP_LCR_LVRFEN_SHIFT               (12U)
#define DIGRF_TOP_LCR_LVRFEN_WIDTH               (1U)
#define DIGRF_TOP_LCR_LVRFEN(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_LCR_LVRFEN_SHIFT)) & DIGRF_TOP_LCR_LVRFEN_MASK)

#define DIGRF_TOP_LCR_TXCMUX_MASK                (0x2000U)
#define DIGRF_TOP_LCR_TXCMUX_SHIFT               (13U)
#define DIGRF_TOP_LCR_TXCMUX_WIDTH               (1U)
#define DIGRF_TOP_LCR_TXCMUX(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_LCR_TXCMUX_SHIFT)) & DIGRF_TOP_LCR_TXCMUX_MASK)

#define DIGRF_TOP_LCR_LVTXOE_MASK                (0x4000U)
#define DIGRF_TOP_LCR_LVTXOE_SHIFT               (14U)
#define DIGRF_TOP_LCR_LVTXOE_WIDTH               (1U)
#define DIGRF_TOP_LCR_LVTXOE(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_LCR_LVTXOE_SHIFT)) & DIGRF_TOP_LCR_LVTXOE_MASK)

#define DIGRF_TOP_LCR_LVRXOFF_MASK               (0x8000U)
#define DIGRF_TOP_LCR_LVRXOFF_SHIFT              (15U)
#define DIGRF_TOP_LCR_LVRXOFF_WIDTH              (1U)
#define DIGRF_TOP_LCR_LVRXOFF(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_LCR_LVRXOFF_SHIFT)) & DIGRF_TOP_LCR_LVRXOFF_MASK)

#define DIGRF_TOP_LCR_SWONLR_MASK                (0x10000U)
#define DIGRF_TOP_LCR_SWONLR_SHIFT               (16U)
#define DIGRF_TOP_LCR_SWONLR_WIDTH               (1U)
#define DIGRF_TOP_LCR_SWONLR(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_LCR_SWONLR_SHIFT)) & DIGRF_TOP_LCR_SWONLR_MASK)

#define DIGRF_TOP_LCR_SWOFFLR_MASK               (0x20000U)
#define DIGRF_TOP_LCR_SWOFFLR_SHIFT              (17U)
#define DIGRF_TOP_LCR_SWOFFLR_WIDTH              (1U)
#define DIGRF_TOP_LCR_SWOFFLR(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_LCR_SWOFFLR_SHIFT)) & DIGRF_TOP_LCR_SWOFFLR_MASK)

#define DIGRF_TOP_LCR_SWONLD_MASK                (0x40000U)
#define DIGRF_TOP_LCR_SWONLD_SHIFT               (18U)
#define DIGRF_TOP_LCR_SWONLD_WIDTH               (1U)
#define DIGRF_TOP_LCR_SWONLD(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_LCR_SWONLD_SHIFT)) & DIGRF_TOP_LCR_SWONLD_MASK)

#define DIGRF_TOP_LCR_SWOFFLD_MASK               (0x80000U)
#define DIGRF_TOP_LCR_SWOFFLD_SHIFT              (19U)
#define DIGRF_TOP_LCR_SWOFFLD_WIDTH              (1U)
#define DIGRF_TOP_LCR_SWOFFLD(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_LCR_SWOFFLD_SHIFT)) & DIGRF_TOP_LCR_SWOFFLD_MASK)

#define DIGRF_TOP_LCR_SWSLPLR_MASK               (0x100000U)
#define DIGRF_TOP_LCR_SWSLPLR_SHIFT              (20U)
#define DIGRF_TOP_LCR_SWSLPLR_WIDTH              (1U)
#define DIGRF_TOP_LCR_SWSLPLR(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_LCR_SWSLPLR_SHIFT)) & DIGRF_TOP_LCR_SWSLPLR_MASK)

#define DIGRF_TOP_LCR_SWWKLR_MASK                (0x200000U)
#define DIGRF_TOP_LCR_SWWKLR_SHIFT               (21U)
#define DIGRF_TOP_LCR_SWWKLR_WIDTH               (1U)
#define DIGRF_TOP_LCR_SWWKLR(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_LCR_SWWKLR_SHIFT)) & DIGRF_TOP_LCR_SWWKLR_MASK)

#define DIGRF_TOP_LCR_SWSLPLD_MASK               (0x400000U)
#define DIGRF_TOP_LCR_SWSLPLD_SHIFT              (22U)
#define DIGRF_TOP_LCR_SWSLPLD_WIDTH              (1U)
#define DIGRF_TOP_LCR_SWSLPLD(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_LCR_SWSLPLD_SHIFT)) & DIGRF_TOP_LCR_SWSLPLD_MASK)

#define DIGRF_TOP_LCR_SWWKLD_MASK                (0x800000U)
#define DIGRF_TOP_LCR_SWWKLD_SHIFT               (23U)
#define DIGRF_TOP_LCR_SWWKLD_WIDTH               (1U)
#define DIGRF_TOP_LCR_SWWKLD(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_LCR_SWWKLD_SHIFT)) & DIGRF_TOP_LCR_SWWKLD_MASK)
/*! @} */

/*! @name UNSTCR - LFAST Unsolicited Tx Control Register */
/*! @{ */

#define DIGRF_TOP_UNSTCR_UNSHDR_MASK             (0x7FU)
#define DIGRF_TOP_UNSTCR_UNSHDR_SHIFT            (0U)
#define DIGRF_TOP_UNSTCR_UNSHDR_WIDTH            (7U)
#define DIGRF_TOP_UNSTCR_UNSHDR(x)               (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_UNSTCR_UNSHDR_SHIFT)) & DIGRF_TOP_UNSTCR_UNSHDR_MASK)

#define DIGRF_TOP_UNSTCR_USNDRQ_MASK             (0x10000U)
#define DIGRF_TOP_UNSTCR_USNDRQ_SHIFT            (16U)
#define DIGRF_TOP_UNSTCR_USNDRQ_WIDTH            (1U)
#define DIGRF_TOP_UNSTCR_USNDRQ(x)               (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_UNSTCR_USNDRQ_SHIFT)) & DIGRF_TOP_UNSTCR_USNDRQ_MASK)
/*! @} */

/*! @name UNSTDR - LFAST Unsolicited Tx Data Registers */
/*! @{ */

#define DIGRF_TOP_UNSTDR_UNTXD_MASK              (0xFFFFFFFFU)
#define DIGRF_TOP_UNSTDR_UNTXD_SHIFT             (0U)
#define DIGRF_TOP_UNSTDR_UNTXD_WIDTH             (32U)
#define DIGRF_TOP_UNSTDR_UNTXD(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_UNSTDR_UNTXD_SHIFT)) & DIGRF_TOP_UNSTDR_UNTXD_MASK)
/*! @} */

/*! @name GSR - LFAST Global Status Register */
/*! @{ */

#define DIGRF_TOP_GSR_LPCSDV_MASK                (0x1U)
#define DIGRF_TOP_GSR_LPCSDV_SHIFT               (0U)
#define DIGRF_TOP_GSR_LPCSDV_WIDTH               (1U)
#define DIGRF_TOP_GSR_LPCSDV(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_GSR_LPCSDV_SHIFT)) & DIGRF_TOP_GSR_LPCSDV_MASK)

#define DIGRF_TOP_GSR_LPCHDV_MASK                (0x2U)
#define DIGRF_TOP_GSR_LPCHDV_SHIFT               (1U)
#define DIGRF_TOP_GSR_LPCHDV_WIDTH               (1U)
#define DIGRF_TOP_GSR_LPCHDV(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_GSR_LPCHDV_SHIFT)) & DIGRF_TOP_GSR_LPCHDV_MASK)

#define DIGRF_TOP_GSR_LPCPDV_MASK                (0x4U)
#define DIGRF_TOP_GSR_LPCPDV_SHIFT               (2U)
#define DIGRF_TOP_GSR_LPCPDV_WIDTH               (1U)
#define DIGRF_TOP_GSR_LPCPDV(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_GSR_LPCPDV_SHIFT)) & DIGRF_TOP_GSR_LPCPDV_MASK)

#define DIGRF_TOP_GSR_LPFPDV_MASK                (0x8U)
#define DIGRF_TOP_GSR_LPFPDV_SHIFT               (3U)
#define DIGRF_TOP_GSR_LPFPDV_WIDTH               (1U)
#define DIGRF_TOP_GSR_LPFPDV(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_GSR_LPFPDV_SHIFT)) & DIGRF_TOP_GSR_LPFPDV_MASK)

#define DIGRF_TOP_GSR_LPTXDN_MASK                (0x10U)
#define DIGRF_TOP_GSR_LPTXDN_SHIFT               (4U)
#define DIGRF_TOP_GSR_LPTXDN_WIDTH               (1U)
#define DIGRF_TOP_GSR_LPTXDN(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_GSR_LPTXDN_SHIFT)) & DIGRF_TOP_GSR_LPTXDN_MASK)

#define DIGRF_TOP_GSR_DRSM_MASK                  (0x10000U)
#define DIGRF_TOP_GSR_DRSM_SHIFT                 (16U)
#define DIGRF_TOP_GSR_DRSM_WIDTH                 (1U)
#define DIGRF_TOP_GSR_DRSM(x)                    (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_GSR_DRSM_SHIFT)) & DIGRF_TOP_GSR_DRSM_MASK)

#define DIGRF_TOP_GSR_LDSM_MASK                  (0x20000U)
#define DIGRF_TOP_GSR_LDSM_SHIFT                 (17U)
#define DIGRF_TOP_GSR_LDSM_WIDTH                 (1U)
#define DIGRF_TOP_GSR_LDSM(x)                    (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_GSR_LDSM_SHIFT)) & DIGRF_TOP_GSR_LDSM_MASK)

#define DIGRF_TOP_GSR_LRMD_MASK                  (0x40000U)
#define DIGRF_TOP_GSR_LRMD_SHIFT                 (18U)
#define DIGRF_TOP_GSR_LRMD_WIDTH                 (1U)
#define DIGRF_TOP_GSR_LRMD(x)                    (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_GSR_LRMD_SHIFT)) & DIGRF_TOP_GSR_LRMD_MASK)

#define DIGRF_TOP_GSR_DUALMD_MASK                (0x80000000U)
#define DIGRF_TOP_GSR_DUALMD_SHIFT               (31U)
#define DIGRF_TOP_GSR_DUALMD_WIDTH               (1U)
#define DIGRF_TOP_GSR_DUALMD(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_GSR_DUALMD_SHIFT)) & DIGRF_TOP_GSR_DUALMD_MASK)
/*! @} */

/*! @name PISR - LFAST Ping Status Register */
/*! @{ */

#define DIGRF_TOP_PISR_RXPNGD_MASK               (0xFFU)
#define DIGRF_TOP_PISR_RXPNGD_SHIFT              (0U)
#define DIGRF_TOP_PISR_RXPNGD_WIDTH              (8U)
#define DIGRF_TOP_PISR_RXPNGD(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_PISR_RXPNGD_SHIFT)) & DIGRF_TOP_PISR_RXPNGD_MASK)
/*! @} */

/*! @name DFSR - LFAST Data Frame Status Register */
/*! @{ */

#define DIGRF_TOP_DFSR_TXFCNT_MASK               (0x7U)
#define DIGRF_TOP_DFSR_TXFCNT_SHIFT              (0U)
#define DIGRF_TOP_DFSR_TXFCNT_WIDTH              (3U)
#define DIGRF_TOP_DFSR_TXFCNT(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_DFSR_TXFCNT_SHIFT)) & DIGRF_TOP_DFSR_TXFCNT_MASK)

#define DIGRF_TOP_DFSR_TXDCNT_MASK               (0x3F00U)
#define DIGRF_TOP_DFSR_TXDCNT_SHIFT              (8U)
#define DIGRF_TOP_DFSR_TXDCNT_WIDTH              (6U)
#define DIGRF_TOP_DFSR_TXDCNT(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_DFSR_TXDCNT_SHIFT)) & DIGRF_TOP_DFSR_TXDCNT_MASK)

#define DIGRF_TOP_DFSR_RXFCNT_MASK               (0x70000U)
#define DIGRF_TOP_DFSR_RXFCNT_SHIFT              (16U)
#define DIGRF_TOP_DFSR_RXFCNT_WIDTH              (3U)
#define DIGRF_TOP_DFSR_RXFCNT(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_DFSR_RXFCNT_SHIFT)) & DIGRF_TOP_DFSR_RXFCNT_MASK)

#define DIGRF_TOP_DFSR_RXDCNT_MASK               (0x3F000000U)
#define DIGRF_TOP_DFSR_RXDCNT_SHIFT              (24U)
#define DIGRF_TOP_DFSR_RXDCNT_WIDTH              (6U)
#define DIGRF_TOP_DFSR_RXDCNT(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_DFSR_RXDCNT_SHIFT)) & DIGRF_TOP_DFSR_RXDCNT_MASK)
/*! @} */

/*! @name TISR - LFAST Tx Interrupt Status Register */
/*! @{ */

#define DIGRF_TOP_TISR_TXDTF_MASK                (0x1U)
#define DIGRF_TOP_TISR_TXDTF_SHIFT               (0U)
#define DIGRF_TOP_TISR_TXDTF_WIDTH               (1U)
#define DIGRF_TOP_TISR_TXDTF(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_TISR_TXDTF_SHIFT)) & DIGRF_TOP_TISR_TXDTF_MASK)

#define DIGRF_TOP_TISR_TXICLCF_MASK              (0x2U)
#define DIGRF_TOP_TISR_TXICLCF_SHIFT             (1U)
#define DIGRF_TOP_TISR_TXICLCF_WIDTH             (1U)
#define DIGRF_TOP_TISR_TXICLCF(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_TISR_TXICLCF_SHIFT)) & DIGRF_TOP_TISR_TXICLCF_MASK)

#define DIGRF_TOP_TISR_TXUNSF_MASK               (0x4U)
#define DIGRF_TOP_TISR_TXUNSF_SHIFT              (2U)
#define DIGRF_TOP_TISR_TXUNSF_WIDTH              (1U)
#define DIGRF_TOP_TISR_TXUNSF(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_TISR_TXUNSF_SHIFT)) & DIGRF_TOP_TISR_TXUNSF_MASK)

#define DIGRF_TOP_TISR_TXPNGF_MASK               (0x10U)
#define DIGRF_TOP_TISR_TXPNGF_SHIFT              (4U)
#define DIGRF_TOP_TISR_TXPNGF_WIDTH              (1U)
#define DIGRF_TOP_TISR_TXPNGF(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_TISR_TXPNGF_SHIFT)) & DIGRF_TOP_TISR_TXPNGF_MASK)

#define DIGRF_TOP_TISR_TXOVF_MASK                (0x10000U)
#define DIGRF_TOP_TISR_TXOVF_SHIFT               (16U)
#define DIGRF_TOP_TISR_TXOVF_WIDTH               (1U)
#define DIGRF_TOP_TISR_TXOVF(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_TISR_TXOVF_SHIFT)) & DIGRF_TOP_TISR_TXOVF_MASK)

#define DIGRF_TOP_TISR_TXIEF_MASK                (0x20000U)
#define DIGRF_TOP_TISR_TXIEF_SHIFT               (17U)
#define DIGRF_TOP_TISR_TXIEF_WIDTH               (1U)
#define DIGRF_TOP_TISR_TXIEF(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_TISR_TXIEF_SHIFT)) & DIGRF_TOP_TISR_TXIEF_MASK)
/*! @} */

/*! @name RISR - LFAST Rx Interrupt Status Register */
/*! @{ */

#define DIGRF_TOP_RISR_RXUNSF_MASK               (0x2U)
#define DIGRF_TOP_RISR_RXUNSF_SHIFT              (1U)
#define DIGRF_TOP_RISR_RXUNSF_WIDTH              (1U)
#define DIGRF_TOP_RISR_RXUNSF(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RISR_RXUNSF_SHIFT)) & DIGRF_TOP_RISR_RXUNSF_MASK)

#define DIGRF_TOP_RISR_RXDF_MASK                 (0x4U)
#define DIGRF_TOP_RISR_RXDF_SHIFT                (2U)
#define DIGRF_TOP_RISR_RXDF_WIDTH                (1U)
#define DIGRF_TOP_RISR_RXDF(x)                   (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RISR_RXDF_SHIFT)) & DIGRF_TOP_RISR_RXDF_MASK)

#define DIGRF_TOP_RISR_RXCTSF_MASK               (0x8U)
#define DIGRF_TOP_RISR_RXCTSF_SHIFT              (3U)
#define DIGRF_TOP_RISR_RXCTSF_WIDTH              (1U)
#define DIGRF_TOP_RISR_RXCTSF(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RISR_RXCTSF_SHIFT)) & DIGRF_TOP_RISR_RXCTSF_MASK)

#define DIGRF_TOP_RISR_RXLCEF_MASK               (0x10000U)
#define DIGRF_TOP_RISR_RXLCEF_SHIFT              (16U)
#define DIGRF_TOP_RISR_RXLCEF_WIDTH              (1U)
#define DIGRF_TOP_RISR_RXLCEF(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RISR_RXLCEF_SHIFT)) & DIGRF_TOP_RISR_RXLCEF_MASK)

#define DIGRF_TOP_RISR_RXICF_MASK                (0x20000U)
#define DIGRF_TOP_RISR_RXICF_SHIFT               (17U)
#define DIGRF_TOP_RISR_RXICF_WIDTH               (1U)
#define DIGRF_TOP_RISR_RXICF(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RISR_RXICF_SHIFT)) & DIGRF_TOP_RISR_RXICF_MASK)

#define DIGRF_TOP_RISR_RXSZF_MASK                (0x40000U)
#define DIGRF_TOP_RISR_RXSZF_SHIFT               (18U)
#define DIGRF_TOP_RISR_RXSZF_WIDTH               (1U)
#define DIGRF_TOP_RISR_RXSZF(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RISR_RXSZF_SHIFT)) & DIGRF_TOP_RISR_RXSZF_MASK)

#define DIGRF_TOP_RISR_RXOFF_MASK                (0x80000U)
#define DIGRF_TOP_RISR_RXOFF_SHIFT               (19U)
#define DIGRF_TOP_RISR_RXOFF_WIDTH               (1U)
#define DIGRF_TOP_RISR_RXOFF(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RISR_RXOFF_SHIFT)) & DIGRF_TOP_RISR_RXOFF_MASK)

#define DIGRF_TOP_RISR_RXUFF_MASK                (0x100000U)
#define DIGRF_TOP_RISR_RXUFF_SHIFT               (20U)
#define DIGRF_TOP_RISR_RXUFF_WIDTH               (1U)
#define DIGRF_TOP_RISR_RXUFF(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RISR_RXUFF_SHIFT)) & DIGRF_TOP_RISR_RXUFF_MASK)

#define DIGRF_TOP_RISR_RXMXF_MASK                (0x200000U)
#define DIGRF_TOP_RISR_RXMXF_SHIFT               (21U)
#define DIGRF_TOP_RISR_RXMXF_WIDTH               (1U)
#define DIGRF_TOP_RISR_RXMXF(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RISR_RXMXF_SHIFT)) & DIGRF_TOP_RISR_RXMXF_MASK)

#define DIGRF_TOP_RISR_RXMNF_MASK                (0x400000U)
#define DIGRF_TOP_RISR_RXMNF_SHIFT               (22U)
#define DIGRF_TOP_RISR_RXMNF_WIDTH               (1U)
#define DIGRF_TOP_RISR_RXMNF(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RISR_RXMNF_SHIFT)) & DIGRF_TOP_RISR_RXMNF_MASK)

#define DIGRF_TOP_RISR_RXUOF_MASK                (0x800000U)
#define DIGRF_TOP_RISR_RXUOF_SHIFT               (23U)
#define DIGRF_TOP_RISR_RXUOF_WIDTH               (1U)
#define DIGRF_TOP_RISR_RXUOF(x)                  (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RISR_RXUOF_SHIFT)) & DIGRF_TOP_RISR_RXUOF_MASK)
/*! @} */

/*! @name RIISR - LFAST Rx ICLC Interrupt Status Register */
/*! @{ */

#define DIGRF_TOP_RIISR_ICPONF_MASK              (0x1U)
#define DIGRF_TOP_RIISR_ICPONF_SHIFT             (0U)
#define DIGRF_TOP_RIISR_ICPONF_WIDTH             (1U)
#define DIGRF_TOP_RIISR_ICPONF(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIISR_ICPONF_SHIFT)) & DIGRF_TOP_RIISR_ICPONF_MASK)

#define DIGRF_TOP_RIISR_ICPOFF_MASK              (0x2U)
#define DIGRF_TOP_RIISR_ICPOFF_SHIFT             (1U)
#define DIGRF_TOP_RIISR_ICPOFF_WIDTH             (1U)
#define DIGRF_TOP_RIISR_ICPOFF(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIISR_ICPOFF_SHIFT)) & DIGRF_TOP_RIISR_ICPOFF_MASK)

#define DIGRF_TOP_RIISR_ICTSF_MASK               (0x4U)
#define DIGRF_TOP_RIISR_ICTSF_SHIFT              (2U)
#define DIGRF_TOP_RIISR_ICTSF_WIDTH              (1U)
#define DIGRF_TOP_RIISR_ICTSF(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIISR_ICTSF_SHIFT)) & DIGRF_TOP_RIISR_ICTSF_MASK)

#define DIGRF_TOP_RIISR_ICTFF_MASK               (0x8U)
#define DIGRF_TOP_RIISR_ICTFF_SHIFT              (3U)
#define DIGRF_TOP_RIISR_ICTFF_WIDTH              (1U)
#define DIGRF_TOP_RIISR_ICTFF(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIISR_ICTFF_SHIFT)) & DIGRF_TOP_RIISR_ICTFF_MASK)

#define DIGRF_TOP_RIISR_ICRSF_MASK               (0x10U)
#define DIGRF_TOP_RIISR_ICRSF_SHIFT              (4U)
#define DIGRF_TOP_RIISR_ICRSF_WIDTH              (1U)
#define DIGRF_TOP_RIISR_ICRSF(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIISR_ICRSF_SHIFT)) & DIGRF_TOP_RIISR_ICRSF_MASK)

#define DIGRF_TOP_RIISR_ICRFF_MASK               (0x20U)
#define DIGRF_TOP_RIISR_ICRFF_SHIFT              (5U)
#define DIGRF_TOP_RIISR_ICRFF_WIDTH              (1U)
#define DIGRF_TOP_RIISR_ICRFF(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIISR_ICRFF_SHIFT)) & DIGRF_TOP_RIISR_ICRFF_MASK)

#define DIGRF_TOP_RIISR_ICTEF_MASK               (0x40U)
#define DIGRF_TOP_RIISR_ICTEF_SHIFT              (6U)
#define DIGRF_TOP_RIISR_ICTEF_WIDTH              (1U)
#define DIGRF_TOP_RIISR_ICTEF(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIISR_ICTEF_SHIFT)) & DIGRF_TOP_RIISR_ICTEF_MASK)

#define DIGRF_TOP_RIISR_ICTDF_MASK               (0x80U)
#define DIGRF_TOP_RIISR_ICTDF_SHIFT              (7U)
#define DIGRF_TOP_RIISR_ICTDF_WIDTH              (1U)
#define DIGRF_TOP_RIISR_ICTDF(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIISR_ICTDF_SHIFT)) & DIGRF_TOP_RIISR_ICTDF_MASK)

#define DIGRF_TOP_RIISR_ICCTF_MASK               (0x100U)
#define DIGRF_TOP_RIISR_ICCTF_SHIFT              (8U)
#define DIGRF_TOP_RIISR_ICCTF_WIDTH              (1U)
#define DIGRF_TOP_RIISR_ICCTF(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIISR_ICCTF_SHIFT)) & DIGRF_TOP_RIISR_ICCTF_MASK)

#define DIGRF_TOP_RIISR_ICLPF_MASK               (0x200U)
#define DIGRF_TOP_RIISR_ICLPF_SHIFT              (9U)
#define DIGRF_TOP_RIISR_ICLPF_WIDTH              (1U)
#define DIGRF_TOP_RIISR_ICLPF(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIISR_ICLPF_SHIFT)) & DIGRF_TOP_RIISR_ICLPF_MASK)

#define DIGRF_TOP_RIISR_ICTOF_MASK               (0x400U)
#define DIGRF_TOP_RIISR_ICTOF_SHIFT              (10U)
#define DIGRF_TOP_RIISR_ICTOF_WIDTH              (1U)
#define DIGRF_TOP_RIISR_ICTOF(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIISR_ICTOF_SHIFT)) & DIGRF_TOP_RIISR_ICTOF_MASK)

#define DIGRF_TOP_RIISR_ICPRF_MASK               (0x800U)
#define DIGRF_TOP_RIISR_ICPRF_SHIFT              (11U)
#define DIGRF_TOP_RIISR_ICPRF_WIDTH              (1U)
#define DIGRF_TOP_RIISR_ICPRF(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIISR_ICPRF_SHIFT)) & DIGRF_TOP_RIISR_ICPRF_MASK)

#define DIGRF_TOP_RIISR_ICPSF_MASK               (0x1000U)
#define DIGRF_TOP_RIISR_ICPSF_SHIFT              (12U)
#define DIGRF_TOP_RIISR_ICPSF_WIDTH              (1U)
#define DIGRF_TOP_RIISR_ICPSF(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIISR_ICPSF_SHIFT)) & DIGRF_TOP_RIISR_ICPSF_MASK)

#define DIGRF_TOP_RIISR_ICPFF_MASK               (0x2000U)
#define DIGRF_TOP_RIISR_ICPFF_SHIFT              (13U)
#define DIGRF_TOP_RIISR_ICPFF_WIDTH              (1U)
#define DIGRF_TOP_RIISR_ICPFF(x)                 (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_RIISR_ICPFF_SHIFT)) & DIGRF_TOP_RIISR_ICPFF_MASK)
/*! @} */

/*! @name PLLLSR - LFAST PLL and LVDS Status Register */
/*! @{ */

#define DIGRF_TOP_PLLLSR_LRPDS_MASK              (0x1U)
#define DIGRF_TOP_PLLLSR_LRPDS_SHIFT             (0U)
#define DIGRF_TOP_PLLLSR_LRPDS_WIDTH             (1U)
#define DIGRF_TOP_PLLLSR_LRPDS(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_PLLLSR_LRPDS_SHIFT)) & DIGRF_TOP_PLLLSR_LRPDS_MASK)

#define DIGRF_TOP_PLLLSR_LDPDS_MASK              (0x2U)
#define DIGRF_TOP_PLLLSR_LDPDS_SHIFT             (1U)
#define DIGRF_TOP_PLLLSR_LDPDS_WIDTH             (1U)
#define DIGRF_TOP_PLLLSR_LDPDS(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_PLLLSR_LDPDS_SHIFT)) & DIGRF_TOP_PLLLSR_LDPDS_MASK)

#define DIGRF_TOP_PLLLSR_LDSLPS_MASK             (0x4U)
#define DIGRF_TOP_PLLLSR_LDSLPS_SHIFT            (2U)
#define DIGRF_TOP_PLLLSR_LDSLPS_WIDTH            (1U)
#define DIGRF_TOP_PLLLSR_LDSLPS(x)               (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_PLLLSR_LDSLPS_SHIFT)) & DIGRF_TOP_PLLLSR_LDSLPS_MASK)

#define DIGRF_TOP_PLLLSR_LRSLPS_MASK             (0x8U)
#define DIGRF_TOP_PLLLSR_LRSLPS_SHIFT            (3U)
#define DIGRF_TOP_PLLLSR_LRSLPS_WIDTH            (1U)
#define DIGRF_TOP_PLLLSR_LRSLPS(x)               (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_PLLLSR_LRSLPS_SHIFT)) & DIGRF_TOP_PLLLSR_LRSLPS_MASK)

#define DIGRF_TOP_PLLLSR_PLDCR_MASK              (0x10000U)
#define DIGRF_TOP_PLLLSR_PLDCR_SHIFT             (16U)
#define DIGRF_TOP_PLLLSR_PLDCR_WIDTH             (1U)
#define DIGRF_TOP_PLLLSR_PLDCR(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_PLLLSR_PLDCR_SHIFT)) & DIGRF_TOP_PLLLSR_PLDCR_MASK)

#define DIGRF_TOP_PLLLSR_PLLDIS_MASK             (0x20000U)
#define DIGRF_TOP_PLLLSR_PLLDIS_SHIFT            (17U)
#define DIGRF_TOP_PLLLSR_PLLDIS_WIDTH            (1U)
#define DIGRF_TOP_PLLLSR_PLLDIS(x)               (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_PLLLSR_PLLDIS_SHIFT)) & DIGRF_TOP_PLLLSR_PLLDIS_MASK)
/*! @} */

/*! @name UNSRSR - LFAST Unsolicited Rx Status Register */
/*! @{ */

#define DIGRF_TOP_UNSRSR_URPCNT_MASK             (0x7U)
#define DIGRF_TOP_UNSRSR_URPCNT_SHIFT            (0U)
#define DIGRF_TOP_UNSRSR_URPCNT_WIDTH            (3U)
#define DIGRF_TOP_UNSRSR_URPCNT(x)               (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_UNSRSR_URPCNT_SHIFT)) & DIGRF_TOP_UNSRSR_URPCNT_MASK)

#define DIGRF_TOP_UNSRSR_URXDV_MASK              (0x100U)
#define DIGRF_TOP_UNSRSR_URXDV_SHIFT             (8U)
#define DIGRF_TOP_UNSRSR_URXDV_WIDTH             (1U)
#define DIGRF_TOP_UNSRSR_URXDV(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_UNSRSR_URXDV_SHIFT)) & DIGRF_TOP_UNSRSR_URXDV_MASK)
/*! @} */

/*! @name UNSRDR - LFAST Unsolicited Rx Data Register */
/*! @{ */

#define DIGRF_TOP_UNSRDR_UNRXD_MASK              (0xFFFFFFFFU)
#define DIGRF_TOP_UNSRDR_UNRXD_SHIFT             (0U)
#define DIGRF_TOP_UNSRDR_UNRXD_WIDTH             (32U)
#define DIGRF_TOP_UNSRDR_UNRXD(x)                (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_UNSRDR_UNRXD_SHIFT)) & DIGRF_TOP_UNSRDR_UNRXD_MASK)
/*! @} */

/*! @name GPR - General Purpose registers */
/*! @{ */

#define DIGRF_TOP_GPR_GPR_MASK                   (0xFFFFFFFFU)
#define DIGRF_TOP_GPR_GPR_SHIFT                  (0U)
#define DIGRF_TOP_GPR_GPR_WIDTH                  (32U)
#define DIGRF_TOP_GPR_GPR(x)                     (((uint32_t)(((uint32_t)(x)) << DIGRF_TOP_GPR_GPR_SHIFT)) & DIGRF_TOP_GPR_GPR_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group DIGRF_TOP_Register_Masks */

/*!
 * @}
 */ /* end of group DIGRF_TOP_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K39_DIGRF_TOP_H_) */
