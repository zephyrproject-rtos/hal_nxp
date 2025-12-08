/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_LPCMP.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_LPCMP
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
#if !defined(S32K566_LPCMP_H_)  /* Check if memory map has not been already included */
#define S32K566_LPCMP_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- LPCMP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPCMP_Peripheral_Access_Layer LPCMP Peripheral Access Layer
 * @{
 */

/** LPCMP - Register Layout Typedef */
typedef struct LPCMP_Struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
  __IO uint32_t CCR0;                              /**< Comparator Control 0, offset: 0x8 */
  __IO uint32_t CCR1;                              /**< Comparator Control 1, offset: 0xC */
  uint8_t RESERVED_0[8];
  __IO uint32_t DCR;                               /**< DAC Control, offset: 0x18 */
  __IO uint32_t IER;                               /**< Interrupt Enable, offset: 0x1C */
  __IO uint32_t CSR;                               /**< Comparator Status, offset: 0x20 */
  __IO uint32_t RRCR0;                             /**< Round-Robin Control 0, offset: 0x24 */
  uint8_t RESERVED_1[4];
  __IO uint32_t RRCSR;                             /**< Round-Robin Control and Status, offset: 0x2C */
  uint8_t RESERVED_2[4];
  __IO uint32_t HSMCR;                             /**< High-Speed Module Control, offset: 0x34 */
} LPCMP_Type, *LPCMP_MemMapPtr;

/** Number of instances of the LPCMP module. */
#define LPCMP_INSTANCE_COUNT                     (3u)

/* LPCMP - Peripheral instance base addresses */
/** Peripheral LPE_LPCMP_0 base address */
#define IP_LPE_LPCMP_0_BASE                      (0x42140000u)
/** Peripheral LPE_LPCMP_0 base pointer */
#define IP_LPE_LPCMP_0                           ((LPCMP_Type *)IP_LPE_LPCMP_0_BASE)
/** Peripheral LPE_LPCMP_1 base address */
#define IP_LPE_LPCMP_1_BASE                      (0x42144000u)
/** Peripheral LPE_LPCMP_1 base pointer */
#define IP_LPE_LPCMP_1                           ((LPCMP_Type *)IP_LPE_LPCMP_1_BASE)
/** Peripheral LPE_LPCMP_2 base address */
#define IP_LPE_LPCMP_2_BASE                      (0x42148000u)
/** Peripheral LPE_LPCMP_2 base pointer */
#define IP_LPE_LPCMP_2                           ((LPCMP_Type *)IP_LPE_LPCMP_2_BASE)
/** Array initializer of LPCMP peripheral base addresses */
#define IP_LPCMP_BASE_ADDRS                      { IP_LPE_LPCMP_0_BASE, IP_LPE_LPCMP_1_BASE, IP_LPE_LPCMP_2_BASE }
/** Array initializer of LPCMP peripheral base pointers */
#define IP_LPCMP_BASE_PTRS                       { IP_LPE_LPCMP_0, IP_LPE_LPCMP_1, IP_LPE_LPCMP_2 }

/* ----------------------------------------------------------------------------
   -- LPCMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPCMP_Register_Masks LPCMP Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define LPCMP_VERID_FEATURE_MASK                 (0xFFFFU)
#define LPCMP_VERID_FEATURE_SHIFT                (0U)
#define LPCMP_VERID_FEATURE_WIDTH                (16U)
#define LPCMP_VERID_FEATURE(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_VERID_FEATURE_SHIFT)) & LPCMP_VERID_FEATURE_MASK)

#define LPCMP_VERID_MINOR_MASK                   (0xFF0000U)
#define LPCMP_VERID_MINOR_SHIFT                  (16U)
#define LPCMP_VERID_MINOR_WIDTH                  (8U)
#define LPCMP_VERID_MINOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_VERID_MINOR_SHIFT)) & LPCMP_VERID_MINOR_MASK)

#define LPCMP_VERID_MAJOR_MASK                   (0xFF000000U)
#define LPCMP_VERID_MAJOR_SHIFT                  (24U)
#define LPCMP_VERID_MAJOR_WIDTH                  (8U)
#define LPCMP_VERID_MAJOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_VERID_MAJOR_SHIFT)) & LPCMP_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter */
/*! @{ */

#define LPCMP_PARAM_DAC_RES_MASK                 (0xFU)
#define LPCMP_PARAM_DAC_RES_SHIFT                (0U)
#define LPCMP_PARAM_DAC_RES_WIDTH                (4U)
#define LPCMP_PARAM_DAC_RES(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_PARAM_DAC_RES_SHIFT)) & LPCMP_PARAM_DAC_RES_MASK)
/*! @} */

/*! @name CCR0 - Comparator Control 0 */
/*! @{ */

#define LPCMP_CCR0_WINDOW_EN_MASK                (0x1U)
#define LPCMP_CCR0_WINDOW_EN_SHIFT               (0U)
#define LPCMP_CCR0_WINDOW_EN_WIDTH               (1U)
#define LPCMP_CCR0_WINDOW_EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR0_WINDOW_EN_SHIFT)) & LPCMP_CCR0_WINDOW_EN_MASK)

#define LPCMP_CCR0_SAMPLE_EN_MASK                (0x2U)
#define LPCMP_CCR0_SAMPLE_EN_SHIFT               (1U)
#define LPCMP_CCR0_SAMPLE_EN_WIDTH               (1U)
#define LPCMP_CCR0_SAMPLE_EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR0_SAMPLE_EN_SHIFT)) & LPCMP_CCR0_SAMPLE_EN_MASK)

#define LPCMP_CCR0_CMP_EN_MASK                   (0x4U)
#define LPCMP_CCR0_CMP_EN_SHIFT                  (2U)
#define LPCMP_CCR0_CMP_EN_WIDTH                  (1U)
#define LPCMP_CCR0_CMP_EN(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR0_CMP_EN_SHIFT)) & LPCMP_CCR0_CMP_EN_MASK)

#define LPCMP_CCR0_COUT_INV_MASK                 (0x8U)
#define LPCMP_CCR0_COUT_INV_SHIFT                (3U)
#define LPCMP_CCR0_COUT_INV_WIDTH                (1U)
#define LPCMP_CCR0_COUT_INV(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR0_COUT_INV_SHIFT)) & LPCMP_CCR0_COUT_INV_MASK)

#define LPCMP_CCR0_COUT_SEL_MASK                 (0x10U)
#define LPCMP_CCR0_COUT_SEL_SHIFT                (4U)
#define LPCMP_CCR0_COUT_SEL_WIDTH                (1U)
#define LPCMP_CCR0_COUT_SEL(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR0_COUT_SEL_SHIFT)) & LPCMP_CCR0_COUT_SEL_MASK)

#define LPCMP_CCR0_COUT_PEN_MASK                 (0x20U)
#define LPCMP_CCR0_COUT_PEN_SHIFT                (5U)
#define LPCMP_CCR0_COUT_PEN_WIDTH                (1U)
#define LPCMP_CCR0_COUT_PEN(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR0_COUT_PEN_SHIFT)) & LPCMP_CCR0_COUT_PEN_MASK)

#define LPCMP_CCR0_COUTA_OWEN_MASK               (0x40U)
#define LPCMP_CCR0_COUTA_OWEN_SHIFT              (6U)
#define LPCMP_CCR0_COUTA_OWEN_WIDTH              (1U)
#define LPCMP_CCR0_COUTA_OWEN(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR0_COUTA_OWEN_SHIFT)) & LPCMP_CCR0_COUTA_OWEN_MASK)

#define LPCMP_CCR0_COUTA_OW_MASK                 (0x80U)
#define LPCMP_CCR0_COUTA_OW_SHIFT                (7U)
#define LPCMP_CCR0_COUTA_OW_WIDTH                (1U)
#define LPCMP_CCR0_COUTA_OW(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR0_COUTA_OW_SHIFT)) & LPCMP_CCR0_COUTA_OW_MASK)

#define LPCMP_CCR0_WINDOW_INV_MASK               (0x100U)
#define LPCMP_CCR0_WINDOW_INV_SHIFT              (8U)
#define LPCMP_CCR0_WINDOW_INV_WIDTH              (1U)
#define LPCMP_CCR0_WINDOW_INV(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR0_WINDOW_INV_SHIFT)) & LPCMP_CCR0_WINDOW_INV_MASK)

#define LPCMP_CCR0_WINDOW_CLS_MASK               (0x200U)
#define LPCMP_CCR0_WINDOW_CLS_SHIFT              (9U)
#define LPCMP_CCR0_WINDOW_CLS_WIDTH              (1U)
#define LPCMP_CCR0_WINDOW_CLS(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR0_WINDOW_CLS_SHIFT)) & LPCMP_CCR0_WINDOW_CLS_MASK)

#define LPCMP_CCR0_EVT_SEL_MASK                  (0xC00U)
#define LPCMP_CCR0_EVT_SEL_SHIFT                 (10U)
#define LPCMP_CCR0_EVT_SEL_WIDTH                 (2U)
#define LPCMP_CCR0_EVT_SEL(x)                    (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR0_EVT_SEL_SHIFT)) & LPCMP_CCR0_EVT_SEL_MASK)

#define LPCMP_CCR0_CMP_STOP_EN_MASK              (0x1000U)
#define LPCMP_CCR0_CMP_STOP_EN_SHIFT             (12U)
#define LPCMP_CCR0_CMP_STOP_EN_WIDTH             (1U)
#define LPCMP_CCR0_CMP_STOP_EN(x)                (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR0_CMP_STOP_EN_SHIFT)) & LPCMP_CCR0_CMP_STOP_EN_MASK)

#define LPCMP_CCR0_FILT_CNT_MASK                 (0x70000U)
#define LPCMP_CCR0_FILT_CNT_SHIFT                (16U)
#define LPCMP_CCR0_FILT_CNT_WIDTH                (3U)
#define LPCMP_CCR0_FILT_CNT(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR0_FILT_CNT_SHIFT)) & LPCMP_CCR0_FILT_CNT_MASK)

#define LPCMP_CCR0_FILT_PER_MASK                 (0xFF000000U)
#define LPCMP_CCR0_FILT_PER_SHIFT                (24U)
#define LPCMP_CCR0_FILT_PER_WIDTH                (8U)
#define LPCMP_CCR0_FILT_PER(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR0_FILT_PER_SHIFT)) & LPCMP_CCR0_FILT_PER_MASK)
/*! @} */

/*! @name CCR1 - Comparator Control 1 */
/*! @{ */

#define LPCMP_CCR1_CMP_HPMD_MASK                 (0x1U)
#define LPCMP_CCR1_CMP_HPMD_SHIFT                (0U)
#define LPCMP_CCR1_CMP_HPMD_WIDTH                (1U)
#define LPCMP_CCR1_CMP_HPMD(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_CMP_HPMD_SHIFT)) & LPCMP_CCR1_CMP_HPMD_MASK)

#define LPCMP_CCR1_CMP_LPMD_MASK                 (0x2U)
#define LPCMP_CCR1_CMP_LPMD_SHIFT                (1U)
#define LPCMP_CCR1_CMP_LPMD_WIDTH                (1U)
#define LPCMP_CCR1_CMP_LPMD(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_CMP_LPMD_SHIFT)) & LPCMP_CCR1_CMP_LPMD_MASK)

#define LPCMP_CCR1_OFFSET_MASK                   (0x4U)
#define LPCMP_CCR1_OFFSET_SHIFT                  (2U)
#define LPCMP_CCR1_OFFSET_WIDTH                  (1U)
#define LPCMP_CCR1_OFFSET(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_OFFSET_SHIFT)) & LPCMP_CCR1_OFFSET_MASK)

#define LPCMP_CCR1_HYSTCTR_MASK                  (0x30U)
#define LPCMP_CCR1_HYSTCTR_SHIFT                 (4U)
#define LPCMP_CCR1_HYSTCTR_WIDTH                 (2U)
#define LPCMP_CCR1_HYSTCTR(x)                    (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_HYSTCTR_SHIFT)) & LPCMP_CCR1_HYSTCTR_MASK)

#define LPCMP_CCR1_CMP_SAMPLE_CLK_DIV_MASK       (0xFF00U)
#define LPCMP_CCR1_CMP_SAMPLE_CLK_DIV_SHIFT      (8U)
#define LPCMP_CCR1_CMP_SAMPLE_CLK_DIV_WIDTH      (8U)
#define LPCMP_CCR1_CMP_SAMPLE_CLK_DIV(x)         (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_CMP_SAMPLE_CLK_DIV_SHIFT)) & LPCMP_CCR1_CMP_SAMPLE_CLK_DIV_MASK)

#define LPCMP_CCR1_PSEL_MASK                     (0x70000U)
#define LPCMP_CCR1_PSEL_SHIFT                    (16U)
#define LPCMP_CCR1_PSEL_WIDTH                    (3U)
#define LPCMP_CCR1_PSEL(x)                       (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_PSEL_SHIFT)) & LPCMP_CCR1_PSEL_MASK)

#define LPCMP_CCR1_MSEL_MASK                     (0x700000U)
#define LPCMP_CCR1_MSEL_SHIFT                    (20U)
#define LPCMP_CCR1_MSEL_WIDTH                    (3U)
#define LPCMP_CCR1_MSEL(x)                       (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_MSEL_SHIFT)) & LPCMP_CCR1_MSEL_MASK)

#define LPCMP_CCR1_INPSEL_MASK                   (0x1000000U)
#define LPCMP_CCR1_INPSEL_SHIFT                  (24U)
#define LPCMP_CCR1_INPSEL_WIDTH                  (1U)
#define LPCMP_CCR1_INPSEL(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_INPSEL_SHIFT)) & LPCMP_CCR1_INPSEL_MASK)

#define LPCMP_CCR1_INMSEL_MASK                   (0x10000000U)
#define LPCMP_CCR1_INMSEL_SHIFT                  (28U)
#define LPCMP_CCR1_INMSEL_WIDTH                  (1U)
#define LPCMP_CCR1_INMSEL(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_CCR1_INMSEL_SHIFT)) & LPCMP_CCR1_INMSEL_MASK)
/*! @} */

/*! @name DCR - DAC Control */
/*! @{ */

#define LPCMP_DCR_DAC_EN_MASK                    (0x1U)
#define LPCMP_DCR_DAC_EN_SHIFT                   (0U)
#define LPCMP_DCR_DAC_EN_WIDTH                   (1U)
#define LPCMP_DCR_DAC_EN(x)                      (((uint32_t)(((uint32_t)(x)) << LPCMP_DCR_DAC_EN_SHIFT)) & LPCMP_DCR_DAC_EN_MASK)

#define LPCMP_DCR_LINK_EN_MASK                   (0x4U)
#define LPCMP_DCR_LINK_EN_SHIFT                  (2U)
#define LPCMP_DCR_LINK_EN_WIDTH                  (1U)
#define LPCMP_DCR_LINK_EN(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_DCR_LINK_EN_SHIFT)) & LPCMP_DCR_LINK_EN_MASK)

#define LPCMP_DCR_DAC_DATA_MASK                  (0xFF0000U)
#define LPCMP_DCR_DAC_DATA_SHIFT                 (16U)
#define LPCMP_DCR_DAC_DATA_WIDTH                 (8U)
#define LPCMP_DCR_DAC_DATA(x)                    (((uint32_t)(((uint32_t)(x)) << LPCMP_DCR_DAC_DATA_SHIFT)) & LPCMP_DCR_DAC_DATA_MASK)
/*! @} */

/*! @name IER - Interrupt Enable */
/*! @{ */

#define LPCMP_IER_CFR_IE_MASK                    (0x1U)
#define LPCMP_IER_CFR_IE_SHIFT                   (0U)
#define LPCMP_IER_CFR_IE_WIDTH                   (1U)
#define LPCMP_IER_CFR_IE(x)                      (((uint32_t)(((uint32_t)(x)) << LPCMP_IER_CFR_IE_SHIFT)) & LPCMP_IER_CFR_IE_MASK)

#define LPCMP_IER_CFF_IE_MASK                    (0x2U)
#define LPCMP_IER_CFF_IE_SHIFT                   (1U)
#define LPCMP_IER_CFF_IE_WIDTH                   (1U)
#define LPCMP_IER_CFF_IE(x)                      (((uint32_t)(((uint32_t)(x)) << LPCMP_IER_CFF_IE_SHIFT)) & LPCMP_IER_CFF_IE_MASK)

#define LPCMP_IER_RRF_IE_MASK                    (0x4U)
#define LPCMP_IER_RRF_IE_SHIFT                   (2U)
#define LPCMP_IER_RRF_IE_WIDTH                   (1U)
#define LPCMP_IER_RRF_IE(x)                      (((uint32_t)(((uint32_t)(x)) << LPCMP_IER_RRF_IE_SHIFT)) & LPCMP_IER_RRF_IE_MASK)

#define LPCMP_IER_DMA_EN_MASK                    (0x8U)
#define LPCMP_IER_DMA_EN_SHIFT                   (3U)
#define LPCMP_IER_DMA_EN_WIDTH                   (1U)
#define LPCMP_IER_DMA_EN(x)                      (((uint32_t)(((uint32_t)(x)) << LPCMP_IER_DMA_EN_SHIFT)) & LPCMP_IER_DMA_EN_MASK)
/*! @} */

/*! @name CSR - Comparator Status */
/*! @{ */

#define LPCMP_CSR_CFR_MASK                       (0x1U)
#define LPCMP_CSR_CFR_SHIFT                      (0U)
#define LPCMP_CSR_CFR_WIDTH                      (1U)
#define LPCMP_CSR_CFR(x)                         (((uint32_t)(((uint32_t)(x)) << LPCMP_CSR_CFR_SHIFT)) & LPCMP_CSR_CFR_MASK)

#define LPCMP_CSR_CFF_MASK                       (0x2U)
#define LPCMP_CSR_CFF_SHIFT                      (1U)
#define LPCMP_CSR_CFF_WIDTH                      (1U)
#define LPCMP_CSR_CFF(x)                         (((uint32_t)(((uint32_t)(x)) << LPCMP_CSR_CFF_SHIFT)) & LPCMP_CSR_CFF_MASK)

#define LPCMP_CSR_RRF_MASK                       (0x4U)
#define LPCMP_CSR_RRF_SHIFT                      (2U)
#define LPCMP_CSR_RRF_WIDTH                      (1U)
#define LPCMP_CSR_RRF(x)                         (((uint32_t)(((uint32_t)(x)) << LPCMP_CSR_RRF_SHIFT)) & LPCMP_CSR_RRF_MASK)

#define LPCMP_CSR_COUT_MASK                      (0x100U)
#define LPCMP_CSR_COUT_SHIFT                     (8U)
#define LPCMP_CSR_COUT_WIDTH                     (1U)
#define LPCMP_CSR_COUT(x)                        (((uint32_t)(((uint32_t)(x)) << LPCMP_CSR_COUT_SHIFT)) & LPCMP_CSR_COUT_MASK)
/*! @} */

/*! @name RRCR0 - Round-Robin Control 0 */
/*! @{ */

#define LPCMP_RRCR0_RR_EN_MASK                   (0x1U)
#define LPCMP_RRCR0_RR_EN_SHIFT                  (0U)
#define LPCMP_RRCR0_RR_EN_WIDTH                  (1U)
#define LPCMP_RRCR0_RR_EN(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCR0_RR_EN_SHIFT)) & LPCMP_RRCR0_RR_EN_MASK)

#define LPCMP_RRCR0_RR_NSAM_MASK                 (0xF8U)
#define LPCMP_RRCR0_RR_NSAM_SHIFT                (3U)
#define LPCMP_RRCR0_RR_NSAM_WIDTH                (5U)
#define LPCMP_RRCR0_RR_NSAM(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCR0_RR_NSAM_SHIFT)) & LPCMP_RRCR0_RR_NSAM_MASK)

#define LPCMP_RRCR0_RR_INITMOD_MASK              (0x3F00U)
#define LPCMP_RRCR0_RR_INITMOD_SHIFT             (8U)
#define LPCMP_RRCR0_RR_INITMOD_WIDTH             (6U)
#define LPCMP_RRCR0_RR_INITMOD(x)                (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCR0_RR_INITMOD_SHIFT)) & LPCMP_RRCR0_RR_INITMOD_MASK)

#define LPCMP_RRCR0_FIXP_MASK                    (0x10000U)
#define LPCMP_RRCR0_FIXP_SHIFT                   (16U)
#define LPCMP_RRCR0_FIXP_WIDTH                   (1U)
#define LPCMP_RRCR0_FIXP(x)                      (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCR0_FIXP_SHIFT)) & LPCMP_RRCR0_FIXP_MASK)

#define LPCMP_RRCR0_FIXCH_MASK                   (0x700000U)
#define LPCMP_RRCR0_FIXCH_SHIFT                  (20U)
#define LPCMP_RRCR0_FIXCH_WIDTH                  (3U)
#define LPCMP_RRCR0_FIXCH(x)                     (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCR0_FIXCH_SHIFT)) & LPCMP_RRCR0_FIXCH_MASK)
/*! @} */

/*! @name RRCSR - Round-Robin Control and Status */
/*! @{ */

#define LPCMP_RRCSR_RR_CH0EN_MASK                (0x1U)
#define LPCMP_RRCSR_RR_CH0EN_SHIFT               (0U)
#define LPCMP_RRCSR_RR_CH0EN_WIDTH               (1U)
#define LPCMP_RRCSR_RR_CH0EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH0EN_SHIFT)) & LPCMP_RRCSR_RR_CH0EN_MASK)

#define LPCMP_RRCSR_RR_CH1EN_MASK                (0x2U)
#define LPCMP_RRCSR_RR_CH1EN_SHIFT               (1U)
#define LPCMP_RRCSR_RR_CH1EN_WIDTH               (1U)
#define LPCMP_RRCSR_RR_CH1EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH1EN_SHIFT)) & LPCMP_RRCSR_RR_CH1EN_MASK)

#define LPCMP_RRCSR_RR_CH2EN_MASK                (0x4U)
#define LPCMP_RRCSR_RR_CH2EN_SHIFT               (2U)
#define LPCMP_RRCSR_RR_CH2EN_WIDTH               (1U)
#define LPCMP_RRCSR_RR_CH2EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH2EN_SHIFT)) & LPCMP_RRCSR_RR_CH2EN_MASK)

#define LPCMP_RRCSR_RR_CH3EN_MASK                (0x8U)
#define LPCMP_RRCSR_RR_CH3EN_SHIFT               (3U)
#define LPCMP_RRCSR_RR_CH3EN_WIDTH               (1U)
#define LPCMP_RRCSR_RR_CH3EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH3EN_SHIFT)) & LPCMP_RRCSR_RR_CH3EN_MASK)

#define LPCMP_RRCSR_RR_CH4EN_MASK                (0x10U)
#define LPCMP_RRCSR_RR_CH4EN_SHIFT               (4U)
#define LPCMP_RRCSR_RR_CH4EN_WIDTH               (1U)
#define LPCMP_RRCSR_RR_CH4EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH4EN_SHIFT)) & LPCMP_RRCSR_RR_CH4EN_MASK)

#define LPCMP_RRCSR_RR_CH5EN_MASK                (0x20U)
#define LPCMP_RRCSR_RR_CH5EN_SHIFT               (5U)
#define LPCMP_RRCSR_RR_CH5EN_WIDTH               (1U)
#define LPCMP_RRCSR_RR_CH5EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH5EN_SHIFT)) & LPCMP_RRCSR_RR_CH5EN_MASK)

#define LPCMP_RRCSR_RR_CH6EN_MASK                (0x40U)
#define LPCMP_RRCSR_RR_CH6EN_SHIFT               (6U)
#define LPCMP_RRCSR_RR_CH6EN_WIDTH               (1U)
#define LPCMP_RRCSR_RR_CH6EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH6EN_SHIFT)) & LPCMP_RRCSR_RR_CH6EN_MASK)

#define LPCMP_RRCSR_RR_CH7EN_MASK                (0x80U)
#define LPCMP_RRCSR_RR_CH7EN_SHIFT               (7U)
#define LPCMP_RRCSR_RR_CH7EN_WIDTH               (1U)
#define LPCMP_RRCSR_RR_CH7EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH7EN_SHIFT)) & LPCMP_RRCSR_RR_CH7EN_MASK)

#define LPCMP_RRCSR_RR_CH0OUT_MASK               (0x100U)
#define LPCMP_RRCSR_RR_CH0OUT_SHIFT              (8U)
#define LPCMP_RRCSR_RR_CH0OUT_WIDTH              (1U)
#define LPCMP_RRCSR_RR_CH0OUT(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH0OUT_SHIFT)) & LPCMP_RRCSR_RR_CH0OUT_MASK)

#define LPCMP_RRCSR_RR_CH1OUT_MASK               (0x200U)
#define LPCMP_RRCSR_RR_CH1OUT_SHIFT              (9U)
#define LPCMP_RRCSR_RR_CH1OUT_WIDTH              (1U)
#define LPCMP_RRCSR_RR_CH1OUT(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH1OUT_SHIFT)) & LPCMP_RRCSR_RR_CH1OUT_MASK)

#define LPCMP_RRCSR_RR_CH2OUT_MASK               (0x400U)
#define LPCMP_RRCSR_RR_CH2OUT_SHIFT              (10U)
#define LPCMP_RRCSR_RR_CH2OUT_WIDTH              (1U)
#define LPCMP_RRCSR_RR_CH2OUT(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH2OUT_SHIFT)) & LPCMP_RRCSR_RR_CH2OUT_MASK)

#define LPCMP_RRCSR_RR_CH3OUT_MASK               (0x800U)
#define LPCMP_RRCSR_RR_CH3OUT_SHIFT              (11U)
#define LPCMP_RRCSR_RR_CH3OUT_WIDTH              (1U)
#define LPCMP_RRCSR_RR_CH3OUT(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH3OUT_SHIFT)) & LPCMP_RRCSR_RR_CH3OUT_MASK)

#define LPCMP_RRCSR_RR_CH4OUT_MASK               (0x1000U)
#define LPCMP_RRCSR_RR_CH4OUT_SHIFT              (12U)
#define LPCMP_RRCSR_RR_CH4OUT_WIDTH              (1U)
#define LPCMP_RRCSR_RR_CH4OUT(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH4OUT_SHIFT)) & LPCMP_RRCSR_RR_CH4OUT_MASK)

#define LPCMP_RRCSR_RR_CH5OUT_MASK               (0x2000U)
#define LPCMP_RRCSR_RR_CH5OUT_SHIFT              (13U)
#define LPCMP_RRCSR_RR_CH5OUT_WIDTH              (1U)
#define LPCMP_RRCSR_RR_CH5OUT(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH5OUT_SHIFT)) & LPCMP_RRCSR_RR_CH5OUT_MASK)

#define LPCMP_RRCSR_RR_CH6OUT_MASK               (0x4000U)
#define LPCMP_RRCSR_RR_CH6OUT_SHIFT              (14U)
#define LPCMP_RRCSR_RR_CH6OUT_WIDTH              (1U)
#define LPCMP_RRCSR_RR_CH6OUT(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH6OUT_SHIFT)) & LPCMP_RRCSR_RR_CH6OUT_MASK)

#define LPCMP_RRCSR_RR_CH7OUT_MASK               (0x8000U)
#define LPCMP_RRCSR_RR_CH7OUT_SHIFT              (15U)
#define LPCMP_RRCSR_RR_CH7OUT_WIDTH              (1U)
#define LPCMP_RRCSR_RR_CH7OUT(x)                 (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH7OUT_SHIFT)) & LPCMP_RRCSR_RR_CH7OUT_MASK)

#define LPCMP_RRCSR_RR_CH0F_MASK                 (0x10000U)
#define LPCMP_RRCSR_RR_CH0F_SHIFT                (16U)
#define LPCMP_RRCSR_RR_CH0F_WIDTH                (1U)
#define LPCMP_RRCSR_RR_CH0F(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH0F_SHIFT)) & LPCMP_RRCSR_RR_CH0F_MASK)

#define LPCMP_RRCSR_RR_CH1F_MASK                 (0x20000U)
#define LPCMP_RRCSR_RR_CH1F_SHIFT                (17U)
#define LPCMP_RRCSR_RR_CH1F_WIDTH                (1U)
#define LPCMP_RRCSR_RR_CH1F(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH1F_SHIFT)) & LPCMP_RRCSR_RR_CH1F_MASK)

#define LPCMP_RRCSR_RR_CH2F_MASK                 (0x40000U)
#define LPCMP_RRCSR_RR_CH2F_SHIFT                (18U)
#define LPCMP_RRCSR_RR_CH2F_WIDTH                (1U)
#define LPCMP_RRCSR_RR_CH2F(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH2F_SHIFT)) & LPCMP_RRCSR_RR_CH2F_MASK)

#define LPCMP_RRCSR_RR_CH3F_MASK                 (0x80000U)
#define LPCMP_RRCSR_RR_CH3F_SHIFT                (19U)
#define LPCMP_RRCSR_RR_CH3F_WIDTH                (1U)
#define LPCMP_RRCSR_RR_CH3F(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH3F_SHIFT)) & LPCMP_RRCSR_RR_CH3F_MASK)

#define LPCMP_RRCSR_RR_CH4F_MASK                 (0x100000U)
#define LPCMP_RRCSR_RR_CH4F_SHIFT                (20U)
#define LPCMP_RRCSR_RR_CH4F_WIDTH                (1U)
#define LPCMP_RRCSR_RR_CH4F(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH4F_SHIFT)) & LPCMP_RRCSR_RR_CH4F_MASK)

#define LPCMP_RRCSR_RR_CH5F_MASK                 (0x200000U)
#define LPCMP_RRCSR_RR_CH5F_SHIFT                (21U)
#define LPCMP_RRCSR_RR_CH5F_WIDTH                (1U)
#define LPCMP_RRCSR_RR_CH5F(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH5F_SHIFT)) & LPCMP_RRCSR_RR_CH5F_MASK)

#define LPCMP_RRCSR_RR_CH6F_MASK                 (0x400000U)
#define LPCMP_RRCSR_RR_CH6F_SHIFT                (22U)
#define LPCMP_RRCSR_RR_CH6F_WIDTH                (1U)
#define LPCMP_RRCSR_RR_CH6F(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH6F_SHIFT)) & LPCMP_RRCSR_RR_CH6F_MASK)

#define LPCMP_RRCSR_RR_CH7F_MASK                 (0x800000U)
#define LPCMP_RRCSR_RR_CH7F_SHIFT                (23U)
#define LPCMP_RRCSR_RR_CH7F_WIDTH                (1U)
#define LPCMP_RRCSR_RR_CH7F(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_RRCSR_RR_CH7F_SHIFT)) & LPCMP_RRCSR_RR_CH7F_MASK)
/*! @} */

/*! @name HSMCR - High-Speed Module Control */
/*! @{ */

#define LPCMP_HSMCR_CMP_SEL_MASK                 (0xFU)
#define LPCMP_HSMCR_CMP_SEL_SHIFT                (0U)
#define LPCMP_HSMCR_CMP_SEL_WIDTH                (4U)
#define LPCMP_HSMCR_CMP_SEL(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_HSMCR_CMP_SEL_SHIFT)) & LPCMP_HSMCR_CMP_SEL_MASK)

#define LPCMP_HSMCR_AZE_SEL_MASK                 (0x1F0U)
#define LPCMP_HSMCR_AZE_SEL_SHIFT                (4U)
#define LPCMP_HSMCR_AZE_SEL_WIDTH                (5U)
#define LPCMP_HSMCR_AZE_SEL(x)                   (((uint32_t)(((uint32_t)(x)) << LPCMP_HSMCR_AZE_SEL_SHIFT)) & LPCMP_HSMCR_AZE_SEL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group LPCMP_Register_Masks */

/*!
 * @}
 */ /* end of group LPCMP_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_LPCMP_H_) */
