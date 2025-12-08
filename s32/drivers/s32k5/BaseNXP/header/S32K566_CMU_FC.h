/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_CMU_FC.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_CMU_FC
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
#if !defined(S32K566_CMU_FC_H_)  /* Check if memory map has not been already included */
#define S32K566_CMU_FC_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CMU_FC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMU_FC_Peripheral_Access_Layer CMU_FC Peripheral Access Layer
 * @{
 */

/** CMU_FC - Register Layout Typedef */
typedef struct CMU_FC_Struct {
  __IO uint32_t GCR;                               /**< Global Configuration Register, offset: 0x0 */
  __IO uint32_t RCCR;                              /**< Reference Count Configuration Register, offset: 0x4 */
  __IO uint32_t HTCR;                              /**< High Threshold Configuration Register, offset: 0x8 */
  __IO uint32_t LTCR;                              /**< Low Threshold Configuration Register, offset: 0xC */
  __IO uint32_t SR;                                /**< Status Register, offset: 0x10 */
  __IO uint32_t IER;                               /**< Interrupt Enable Register, offset: 0x14 */
  uint8_t RESERVED_0[40];
  __I  uint32_t MCC;                               /**< Monitored Clock Count Register, offset: 0x40 */
  __I  uint32_t MCFC;                              /**< Monitored Clock Fault Count Register, offset: 0x44 */
  uint8_t RESERVED_1[24];
  __IO uint32_t LOCCCR;                            /**< Loss of Clock Count Configuration Register, offset: 0x60 */
  __IO uint32_t LOCE;                              /**< Loss of Clock Enables Register, offset: 0x64 */
  __IO uint32_t LOCFI;                             /**< Loss Of Clock Fault Injection Register, offset: 0x68 */
  uint8_t RESERVED_2[4];
  __IO uint32_t LOCI;                              /**< Loss of Clock Status Register, offset: 0x70 */
} CMU_FC_Type, *CMU_FC_MemMapPtr;

/** Number of instances of the CMU_FC module. */
#define CMU_FC_INSTANCE_COUNT                    (12u)

/* CMU_FC - Peripheral instance base addresses */
/** Peripheral CMU_FC_0 base address */
#define IP_CMU_FC_0_BASE                         (0x404C4000u)
/** Peripheral CMU_FC_0 base pointer */
#define IP_CMU_FC_0                              ((CMU_FC_Type *)IP_CMU_FC_0_BASE)
/** Peripheral CMU_FC_1 base address */
#define IP_CMU_FC_1_BASE                         (0x404C4080u)
/** Peripheral CMU_FC_1 base pointer */
#define IP_CMU_FC_1                              ((CMU_FC_Type *)IP_CMU_FC_1_BASE)
/** Peripheral CMU_FC_2 base address */
#define IP_CMU_FC_2_BASE                         (0x404C4100u)
/** Peripheral CMU_FC_2 base pointer */
#define IP_CMU_FC_2                              ((CMU_FC_Type *)IP_CMU_FC_2_BASE)
/** Peripheral CMU_FC_3 base address */
#define IP_CMU_FC_3_BASE                         (0x404C4180u)
/** Peripheral CMU_FC_3 base pointer */
#define IP_CMU_FC_3                              ((CMU_FC_Type *)IP_CMU_FC_3_BASE)
/** Peripheral CPE_CMU_FC_0 base address */
#define IP_CPE_CMU_FC_0_BASE                     (0x41084000u)
/** Peripheral CPE_CMU_FC_0 base pointer */
#define IP_CPE_CMU_FC_0                          ((CMU_FC_Type *)IP_CPE_CMU_FC_0_BASE)
/** Peripheral CPE_CMU_FC_1 base address */
#define IP_CPE_CMU_FC_1_BASE                     (0x41084080u)
/** Peripheral CPE_CMU_FC_1 base pointer */
#define IP_CPE_CMU_FC_1                          ((CMU_FC_Type *)IP_CPE_CMU_FC_1_BASE)
/** Peripheral LPE_CMU_FC_0 base address */
#define IP_LPE_CMU_FC_0_BASE                     (0x42124000u)
/** Peripheral LPE_CMU_FC_0 base pointer */
#define IP_LPE_CMU_FC_0                          ((CMU_FC_Type *)IP_LPE_CMU_FC_0_BASE)
/** Peripheral LPE_CMU_FC_1 base address */
#define IP_LPE_CMU_FC_1_BASE                     (0x42124080u)
/** Peripheral LPE_CMU_FC_1 base pointer */
#define IP_LPE_CMU_FC_1                          ((CMU_FC_Type *)IP_LPE_CMU_FC_1_BASE)
/** Peripheral LPE_CMU_FC_2 base address */
#define IP_LPE_CMU_FC_2_BASE                     (0x42124100u)
/** Peripheral LPE_CMU_FC_2 base pointer */
#define IP_LPE_CMU_FC_2                          ((CMU_FC_Type *)IP_LPE_CMU_FC_2_BASE)
/** Peripheral LPE_CMU_FC_3 base address */
#define IP_LPE_CMU_FC_3_BASE                     (0x42124180u)
/** Peripheral LPE_CMU_FC_3 base pointer */
#define IP_LPE_CMU_FC_3                          ((CMU_FC_Type *)IP_LPE_CMU_FC_3_BASE)
/** Peripheral LPE_CMU_FC_4 base address */
#define IP_LPE_CMU_FC_4_BASE                     (0x42124200u)
/** Peripheral LPE_CMU_FC_4 base pointer */
#define IP_LPE_CMU_FC_4                          ((CMU_FC_Type *)IP_LPE_CMU_FC_4_BASE)
/** Peripheral LPE_CMU_FC_5 base address */
#define IP_LPE_CMU_FC_5_BASE                     (0x42124280u)
/** Peripheral LPE_CMU_FC_5 base pointer */
#define IP_LPE_CMU_FC_5                          ((CMU_FC_Type *)IP_LPE_CMU_FC_5_BASE)
/** Array initializer of CMU_FC peripheral base addresses */
#define IP_CMU_FC_BASE_ADDRS                     { IP_CMU_FC_0_BASE, IP_CMU_FC_1_BASE, IP_CMU_FC_2_BASE, IP_CMU_FC_3_BASE, IP_CPE_CMU_FC_0_BASE, IP_CPE_CMU_FC_1_BASE, IP_LPE_CMU_FC_0_BASE, IP_LPE_CMU_FC_1_BASE, IP_LPE_CMU_FC_2_BASE, IP_LPE_CMU_FC_3_BASE, IP_LPE_CMU_FC_4_BASE, IP_LPE_CMU_FC_5_BASE }
/** Array initializer of CMU_FC peripheral base pointers */
#define IP_CMU_FC_BASE_PTRS                      { IP_CMU_FC_0, IP_CMU_FC_1, IP_CMU_FC_2, IP_CMU_FC_3, IP_CPE_CMU_FC_0, IP_CPE_CMU_FC_1, IP_LPE_CMU_FC_0, IP_LPE_CMU_FC_1, IP_LPE_CMU_FC_2, IP_LPE_CMU_FC_3, IP_LPE_CMU_FC_4, IP_LPE_CMU_FC_5 }

/* ----------------------------------------------------------------------------
   -- CMU_FC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMU_FC_Register_Masks CMU_FC Register Masks
 * @{
 */

/*! @name GCR - Global Configuration Register */
/*! @{ */

#define CMU_FC_GCR_FCE_MASK                      (0x1U)
#define CMU_FC_GCR_FCE_SHIFT                     (0U)
#define CMU_FC_GCR_FCE_WIDTH                     (1U)
#define CMU_FC_GCR_FCE(x)                        (((uint32_t)(((uint32_t)(x)) << CMU_FC_GCR_FCE_SHIFT)) & CMU_FC_GCR_FCE_MASK)

#define CMU_FC_GCR_OTFE_MASK                     (0x8000U)
#define CMU_FC_GCR_OTFE_SHIFT                    (15U)
#define CMU_FC_GCR_OTFE_WIDTH                    (1U)
#define CMU_FC_GCR_OTFE(x)                       (((uint32_t)(((uint32_t)(x)) << CMU_FC_GCR_OTFE_SHIFT)) & CMU_FC_GCR_OTFE_MASK)
/*! @} */

/*! @name RCCR - Reference Count Configuration Register */
/*! @{ */

#define CMU_FC_RCCR_REF_CNT_MASK                 (0xFFFFU)
#define CMU_FC_RCCR_REF_CNT_SHIFT                (0U)
#define CMU_FC_RCCR_REF_CNT_WIDTH                (16U)
#define CMU_FC_RCCR_REF_CNT(x)                   (((uint32_t)(((uint32_t)(x)) << CMU_FC_RCCR_REF_CNT_SHIFT)) & CMU_FC_RCCR_REF_CNT_MASK)
/*! @} */

/*! @name HTCR - High Threshold Configuration Register */
/*! @{ */

#define CMU_FC_HTCR_HFREF_MASK                   (0xFFFFFFU)
#define CMU_FC_HTCR_HFREF_SHIFT                  (0U)
#define CMU_FC_HTCR_HFREF_WIDTH                  (24U)
#define CMU_FC_HTCR_HFREF(x)                     (((uint32_t)(((uint32_t)(x)) << CMU_FC_HTCR_HFREF_SHIFT)) & CMU_FC_HTCR_HFREF_MASK)
/*! @} */

/*! @name LTCR - Low Threshold Configuration Register */
/*! @{ */

#define CMU_FC_LTCR_LFREF_MASK                   (0xFFFFFFU)
#define CMU_FC_LTCR_LFREF_SHIFT                  (0U)
#define CMU_FC_LTCR_LFREF_WIDTH                  (24U)
#define CMU_FC_LTCR_LFREF(x)                     (((uint32_t)(((uint32_t)(x)) << CMU_FC_LTCR_LFREF_SHIFT)) & CMU_FC_LTCR_LFREF_MASK)
/*! @} */

/*! @name SR - Status Register */
/*! @{ */

#define CMU_FC_SR_FLL_MASK                       (0x1U)
#define CMU_FC_SR_FLL_SHIFT                      (0U)
#define CMU_FC_SR_FLL_WIDTH                      (1U)
#define CMU_FC_SR_FLL(x)                         (((uint32_t)(((uint32_t)(x)) << CMU_FC_SR_FLL_SHIFT)) & CMU_FC_SR_FLL_MASK)

#define CMU_FC_SR_FHH_MASK                       (0x2U)
#define CMU_FC_SR_FHH_SHIFT                      (1U)
#define CMU_FC_SR_FHH_WIDTH                      (1U)
#define CMU_FC_SR_FHH(x)                         (((uint32_t)(((uint32_t)(x)) << CMU_FC_SR_FHH_SHIFT)) & CMU_FC_SR_FHH_MASK)

#define CMU_FC_SR_RS_MASK                        (0x10U)
#define CMU_FC_SR_RS_SHIFT                       (4U)
#define CMU_FC_SR_RS_WIDTH                       (1U)
#define CMU_FC_SR_RS(x)                          (((uint32_t)(((uint32_t)(x)) << CMU_FC_SR_RS_SHIFT)) & CMU_FC_SR_RS_MASK)

#define CMU_FC_SR_OTFD_MASK                      (0x8000U)
#define CMU_FC_SR_OTFD_SHIFT                     (15U)
#define CMU_FC_SR_OTFD_WIDTH                     (1U)
#define CMU_FC_SR_OTFD(x)                        (((uint32_t)(((uint32_t)(x)) << CMU_FC_SR_OTFD_SHIFT)) & CMU_FC_SR_OTFD_MASK)
/*! @} */

/*! @name IER - Interrupt Enable Register */
/*! @{ */

#define CMU_FC_IER_FLLIE_MASK                    (0x1U)
#define CMU_FC_IER_FLLIE_SHIFT                   (0U)
#define CMU_FC_IER_FLLIE_WIDTH                   (1U)
#define CMU_FC_IER_FLLIE(x)                      (((uint32_t)(((uint32_t)(x)) << CMU_FC_IER_FLLIE_SHIFT)) & CMU_FC_IER_FLLIE_MASK)

#define CMU_FC_IER_FHHIE_MASK                    (0x2U)
#define CMU_FC_IER_FHHIE_SHIFT                   (1U)
#define CMU_FC_IER_FHHIE_WIDTH                   (1U)
#define CMU_FC_IER_FHHIE(x)                      (((uint32_t)(((uint32_t)(x)) << CMU_FC_IER_FHHIE_SHIFT)) & CMU_FC_IER_FHHIE_MASK)

#define CMU_FC_IER_FLLAIE_MASK                   (0x4U)
#define CMU_FC_IER_FLLAIE_SHIFT                  (2U)
#define CMU_FC_IER_FLLAIE_WIDTH                  (1U)
#define CMU_FC_IER_FLLAIE(x)                     (((uint32_t)(((uint32_t)(x)) << CMU_FC_IER_FLLAIE_SHIFT)) & CMU_FC_IER_FLLAIE_MASK)

#define CMU_FC_IER_FHHAIE_MASK                   (0x8U)
#define CMU_FC_IER_FHHAIE_SHIFT                  (3U)
#define CMU_FC_IER_FHHAIE_WIDTH                  (1U)
#define CMU_FC_IER_FHHAIE(x)                     (((uint32_t)(((uint32_t)(x)) << CMU_FC_IER_FHHAIE_SHIFT)) & CMU_FC_IER_FHHAIE_MASK)
/*! @} */

/*! @name MCC - Monitored Clock Count Register */
/*! @{ */

#define CMU_FC_MCC_MET_COUNT_MASK                (0xFFFFFFU)
#define CMU_FC_MCC_MET_COUNT_SHIFT               (0U)
#define CMU_FC_MCC_MET_COUNT_WIDTH               (24U)
#define CMU_FC_MCC_MET_COUNT(x)                  (((uint32_t)(((uint32_t)(x)) << CMU_FC_MCC_MET_COUNT_SHIFT)) & CMU_FC_MCC_MET_COUNT_MASK)
/*! @} */

/*! @name MCFC - Monitored Clock Fault Count Register */
/*! @{ */

#define CMU_FC_MCFC_FAULT_COUNT_MASK             (0xFFFFFFU)
#define CMU_FC_MCFC_FAULT_COUNT_SHIFT            (0U)
#define CMU_FC_MCFC_FAULT_COUNT_WIDTH            (24U)
#define CMU_FC_MCFC_FAULT_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << CMU_FC_MCFC_FAULT_COUNT_SHIFT)) & CMU_FC_MCFC_FAULT_COUNT_MASK)
/*! @} */

/*! @name LOCCCR - Loss of Clock Count Configuration Register */
/*! @{ */

#define CMU_FC_LOCCCR_LOC_COUNT_MASK             (0xFFFFU)  /* Merged from fields with different position or width, of widths (8, 16), largest definition used */
#define CMU_FC_LOCCCR_LOC_COUNT_SHIFT            (0U)
#define CMU_FC_LOCCCR_LOC_COUNT_WIDTH            (16U)
#define CMU_FC_LOCCCR_LOC_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << CMU_FC_LOCCCR_LOC_COUNT_SHIFT)) & CMU_FC_LOCCCR_LOC_COUNT_MASK)  /* Merged from fields with different position or width, of widths (8, 16), largest definition used */
/*! @} */

/*! @name LOCE - Loss of Clock Enables Register */
/*! @{ */

#define CMU_FC_LOCE_LOCE0_MASK                   (0x1U)
#define CMU_FC_LOCE_LOCE0_SHIFT                  (0U)
#define CMU_FC_LOCE_LOCE0_WIDTH                  (1U)
#define CMU_FC_LOCE_LOCE0(x)                     (((uint32_t)(((uint32_t)(x)) << CMU_FC_LOCE_LOCE0_SHIFT)) & CMU_FC_LOCE_LOCE0_MASK)
/*! @} */

/*! @name LOCFI - Loss Of Clock Fault Injection Register */
/*! @{ */

#define CMU_FC_LOCFI_LOCFI0_MASK                 (0x1U)
#define CMU_FC_LOCFI_LOCFI0_SHIFT                (0U)
#define CMU_FC_LOCFI_LOCFI0_WIDTH                (1U)
#define CMU_FC_LOCFI_LOCFI0(x)                   (((uint32_t)(((uint32_t)(x)) << CMU_FC_LOCFI_LOCFI0_SHIFT)) & CMU_FC_LOCFI_LOCFI0_MASK)
/*! @} */

/*! @name LOCI - Loss of Clock Status Register */
/*! @{ */

#define CMU_FC_LOCI_LOCI0_MASK                   (0x1U)
#define CMU_FC_LOCI_LOCI0_SHIFT                  (0U)
#define CMU_FC_LOCI_LOCI0_WIDTH                  (1U)
#define CMU_FC_LOCI_LOCI0(x)                     (((uint32_t)(((uint32_t)(x)) << CMU_FC_LOCI_LOCI0_SHIFT)) & CMU_FC_LOCI_LOCI0_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CMU_FC_Register_Masks */

/*!
 * @}
 */ /* end of group CMU_FC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_CMU_FC_H_) */
