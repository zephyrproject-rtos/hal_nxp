/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_CTU.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_CTU
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
#if !defined(S32Z2_CTU_H_)  /* Check if memory map has not been already included */
#define S32Z2_CTU_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CTU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CTU_Peripheral_Access_Layer CTU Peripheral Access Layer
 * @{
 */

/** CTU - Size of Registers Arrays */
#define CTU_TCR_COUNT                             8u
#define CTU_CLR_COUNT                             24u
#define CTU_FR_COUNT                              4u
#define CTU_FL_COUNT                              4u

/** CTU - Register Layout Typedef */
typedef struct {
  __IO uint32_t TGSISR;                            /**< Trigger Generator Subunit Input Selection Register, offset: 0x0 */
  __IO uint16_t TGSCR;                             /**< Trigger Generator Subunit Control Register, offset: 0x4 */
  __IO uint16_t TCR[CTU_TCR_COUNT];                /**< Trigger Compare Register, array offset: 0x6, array step: 0x2 */
  __IO uint16_t TGSCCR;                            /**< TGS Counter Compare Register, offset: 0x16 */
  __IO uint16_t TGSCRR;                            /**< TGS Counter Reload Register, offset: 0x18 */
  uint8_t RESERVED_0[2];
  __IO uint32_t CLCR1;                             /**< Commands List Control Register 1, offset: 0x1C */
  __IO uint32_t CLCR2;                             /**< Commands List Control Register 2, offset: 0x20 */
  __IO uint32_t THCR1;                             /**< Trigger Handler Control Register 1, offset: 0x24 */
  __IO uint32_t THCR2;                             /**< Trigger Handler Control Register 2, offset: 0x28 */
  union {                                          /* offset: 0x2C */
    __IO uint16_t A[CTU_CLR_COUNT];                  /**< Commands List Register A for ADC single-conversion mode commands, array offset: 0x2C, array step: 0x2 */
    __IO uint16_t B[CTU_CLR_COUNT];                  /**< Command List Register B for ADC dual-conversion mode commands, array offset: 0x2C, array step: 0x2 */
  } CLR;
  uint8_t RESERVED_1[16];
  __IO uint16_t FDCR;                              /**< FIFO DMA Control Register, offset: 0x6C */
  uint8_t RESERVED_2[2];
  __IO uint32_t FCR;                               /**< FIFO Control Register, offset: 0x70 */
  __IO uint32_t FTH;                               /**< FIFO Threshold Register, offset: 0x74 */
  uint8_t RESERVED_3[4];
  __IO uint32_t FST;                               /**< FIFO Status Register, offset: 0x7C */
  __I  uint32_t FR[CTU_FR_COUNT];                  /**< FIFO Right Aligned Data Register, array offset: 0x80, array step: 0x4 */
  uint8_t RESERVED_4[16];
  __I  uint32_t FL[CTU_FL_COUNT];                  /**< FIFO Signed Left Aligned Data Register, array offset: 0xA0, array step: 0x4 */
  uint8_t RESERVED_5[16];
  __IO uint16_t EFR;                               /**< Error Flag Register, offset: 0xC0 */
  __IO uint16_t IFR;                               /**< Interrupt Flag Register, offset: 0xC2 */
  __IO uint16_t IR;                                /**< Interrupt/DMA Register, offset: 0xC4 */
  __IO uint16_t COTR;                              /**< Control ON Time Register, offset: 0xC6 */
  __IO uint16_t CR;                                /**< Control Register, offset: 0xC8 */
  __IO uint16_t DFR;                               /**< Digital Filter Register, offset: 0xCA */
  __IO uint16_t EXPAR;                             /**< Expected Value A Register, offset: 0xCC */
  __IO uint16_t EXPBR;                             /**< Expected Value B Register, offset: 0xCE */
  __IO uint16_t CNTRNGR;                           /**< Counter Range Register, offset: 0xD0 */
  uint8_t RESERVED_6[2];
  __IO uint32_t LISTCSR;                           /**< List Control/Status Register, offset: 0xD4 */
} CTU_Type, *CTU_MemMapPtr;

/** Number of instances of the CTU module. */
#define CTU_INSTANCE_COUNT                       (1u)

/* CTU - Peripheral instance base addresses */
/** Peripheral CTU base address */
#define IP_CTU_BASE                              (0x40390000u)
/** Peripheral CTU base pointer */
#define IP_CTU                                   ((CTU_Type *)IP_CTU_BASE)
/** Array initializer of CTU peripheral base addresses */
#define IP_CTU_BASE_ADDRS                        { IP_CTU_BASE }
/** Array initializer of CTU peripheral base pointers */
#define IP_CTU_BASE_PTRS                         { IP_CTU }

/* ----------------------------------------------------------------------------
   -- CTU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CTU_Register_Masks CTU Register Masks
 * @{
 */

/*! @name TGSISR - Trigger Generator Subunit Input Selection Register */
/*! @{ */

#define CTU_TGSISR_I1_RE_MASK                    (0x4U)
#define CTU_TGSISR_I1_RE_SHIFT                   (2U)
#define CTU_TGSISR_I1_RE_WIDTH                   (1U)
#define CTU_TGSISR_I1_RE(x)                      (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I1_RE_SHIFT)) & CTU_TGSISR_I1_RE_MASK)

#define CTU_TGSISR_I1_FE_MASK                    (0x8U)
#define CTU_TGSISR_I1_FE_SHIFT                   (3U)
#define CTU_TGSISR_I1_FE_WIDTH                   (1U)
#define CTU_TGSISR_I1_FE(x)                      (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I1_FE_SHIFT)) & CTU_TGSISR_I1_FE_MASK)

#define CTU_TGSISR_I2_RE_MASK                    (0x10U)
#define CTU_TGSISR_I2_RE_SHIFT                   (4U)
#define CTU_TGSISR_I2_RE_WIDTH                   (1U)
#define CTU_TGSISR_I2_RE(x)                      (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I2_RE_SHIFT)) & CTU_TGSISR_I2_RE_MASK)

#define CTU_TGSISR_I2_FE_MASK                    (0x20U)
#define CTU_TGSISR_I2_FE_SHIFT                   (5U)
#define CTU_TGSISR_I2_FE_WIDTH                   (1U)
#define CTU_TGSISR_I2_FE(x)                      (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I2_FE_SHIFT)) & CTU_TGSISR_I2_FE_MASK)

#define CTU_TGSISR_I3_RE_MASK                    (0x40U)
#define CTU_TGSISR_I3_RE_SHIFT                   (6U)
#define CTU_TGSISR_I3_RE_WIDTH                   (1U)
#define CTU_TGSISR_I3_RE(x)                      (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I3_RE_SHIFT)) & CTU_TGSISR_I3_RE_MASK)

#define CTU_TGSISR_I3_FE_MASK                    (0x80U)
#define CTU_TGSISR_I3_FE_SHIFT                   (7U)
#define CTU_TGSISR_I3_FE_WIDTH                   (1U)
#define CTU_TGSISR_I3_FE(x)                      (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I3_FE_SHIFT)) & CTU_TGSISR_I3_FE_MASK)

#define CTU_TGSISR_I4_RE_MASK                    (0x100U)
#define CTU_TGSISR_I4_RE_SHIFT                   (8U)
#define CTU_TGSISR_I4_RE_WIDTH                   (1U)
#define CTU_TGSISR_I4_RE(x)                      (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I4_RE_SHIFT)) & CTU_TGSISR_I4_RE_MASK)

#define CTU_TGSISR_I4_FE_MASK                    (0x200U)
#define CTU_TGSISR_I4_FE_SHIFT                   (9U)
#define CTU_TGSISR_I4_FE_WIDTH                   (1U)
#define CTU_TGSISR_I4_FE(x)                      (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I4_FE_SHIFT)) & CTU_TGSISR_I4_FE_MASK)

#define CTU_TGSISR_I5_RE_MASK                    (0x400U)
#define CTU_TGSISR_I5_RE_SHIFT                   (10U)
#define CTU_TGSISR_I5_RE_WIDTH                   (1U)
#define CTU_TGSISR_I5_RE(x)                      (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I5_RE_SHIFT)) & CTU_TGSISR_I5_RE_MASK)

#define CTU_TGSISR_I5_FE_MASK                    (0x800U)
#define CTU_TGSISR_I5_FE_SHIFT                   (11U)
#define CTU_TGSISR_I5_FE_WIDTH                   (1U)
#define CTU_TGSISR_I5_FE(x)                      (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I5_FE_SHIFT)) & CTU_TGSISR_I5_FE_MASK)

#define CTU_TGSISR_I6_RE_MASK                    (0x1000U)
#define CTU_TGSISR_I6_RE_SHIFT                   (12U)
#define CTU_TGSISR_I6_RE_WIDTH                   (1U)
#define CTU_TGSISR_I6_RE(x)                      (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I6_RE_SHIFT)) & CTU_TGSISR_I6_RE_MASK)

#define CTU_TGSISR_I6_FE_MASK                    (0x2000U)
#define CTU_TGSISR_I6_FE_SHIFT                   (13U)
#define CTU_TGSISR_I6_FE_WIDTH                   (1U)
#define CTU_TGSISR_I6_FE(x)                      (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I6_FE_SHIFT)) & CTU_TGSISR_I6_FE_MASK)

#define CTU_TGSISR_I7_RE_MASK                    (0x4000U)
#define CTU_TGSISR_I7_RE_SHIFT                   (14U)
#define CTU_TGSISR_I7_RE_WIDTH                   (1U)
#define CTU_TGSISR_I7_RE(x)                      (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I7_RE_SHIFT)) & CTU_TGSISR_I7_RE_MASK)

#define CTU_TGSISR_I7_FE_MASK                    (0x8000U)
#define CTU_TGSISR_I7_FE_SHIFT                   (15U)
#define CTU_TGSISR_I7_FE_WIDTH                   (1U)
#define CTU_TGSISR_I7_FE(x)                      (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I7_FE_SHIFT)) & CTU_TGSISR_I7_FE_MASK)

#define CTU_TGSISR_I9_RE_MASK                    (0x40000U)
#define CTU_TGSISR_I9_RE_SHIFT                   (18U)
#define CTU_TGSISR_I9_RE_WIDTH                   (1U)
#define CTU_TGSISR_I9_RE(x)                      (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I9_RE_SHIFT)) & CTU_TGSISR_I9_RE_MASK)

#define CTU_TGSISR_I9_FE_MASK                    (0x80000U)
#define CTU_TGSISR_I9_FE_SHIFT                   (19U)
#define CTU_TGSISR_I9_FE_WIDTH                   (1U)
#define CTU_TGSISR_I9_FE(x)                      (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I9_FE_SHIFT)) & CTU_TGSISR_I9_FE_MASK)

#define CTU_TGSISR_I10_RE_MASK                   (0x100000U)
#define CTU_TGSISR_I10_RE_SHIFT                  (20U)
#define CTU_TGSISR_I10_RE_WIDTH                  (1U)
#define CTU_TGSISR_I10_RE(x)                     (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I10_RE_SHIFT)) & CTU_TGSISR_I10_RE_MASK)

#define CTU_TGSISR_I10_FE_MASK                   (0x200000U)
#define CTU_TGSISR_I10_FE_SHIFT                  (21U)
#define CTU_TGSISR_I10_FE_WIDTH                  (1U)
#define CTU_TGSISR_I10_FE(x)                     (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I10_FE_SHIFT)) & CTU_TGSISR_I10_FE_MASK)

#define CTU_TGSISR_I11_RE_MASK                   (0x400000U)
#define CTU_TGSISR_I11_RE_SHIFT                  (22U)
#define CTU_TGSISR_I11_RE_WIDTH                  (1U)
#define CTU_TGSISR_I11_RE(x)                     (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I11_RE_SHIFT)) & CTU_TGSISR_I11_RE_MASK)

#define CTU_TGSISR_I11_FE_MASK                   (0x800000U)
#define CTU_TGSISR_I11_FE_SHIFT                  (23U)
#define CTU_TGSISR_I11_FE_WIDTH                  (1U)
#define CTU_TGSISR_I11_FE(x)                     (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I11_FE_SHIFT)) & CTU_TGSISR_I11_FE_MASK)

#define CTU_TGSISR_I12_RE_MASK                   (0x1000000U)
#define CTU_TGSISR_I12_RE_SHIFT                  (24U)
#define CTU_TGSISR_I12_RE_WIDTH                  (1U)
#define CTU_TGSISR_I12_RE(x)                     (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I12_RE_SHIFT)) & CTU_TGSISR_I12_RE_MASK)

#define CTU_TGSISR_I12_FE_MASK                   (0x2000000U)
#define CTU_TGSISR_I12_FE_SHIFT                  (25U)
#define CTU_TGSISR_I12_FE_WIDTH                  (1U)
#define CTU_TGSISR_I12_FE(x)                     (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I12_FE_SHIFT)) & CTU_TGSISR_I12_FE_MASK)

#define CTU_TGSISR_I15_RE_MASK                   (0x40000000U)
#define CTU_TGSISR_I15_RE_SHIFT                  (30U)
#define CTU_TGSISR_I15_RE_WIDTH                  (1U)
#define CTU_TGSISR_I15_RE(x)                     (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I15_RE_SHIFT)) & CTU_TGSISR_I15_RE_MASK)

#define CTU_TGSISR_I15_FE_MASK                   (0x80000000U)
#define CTU_TGSISR_I15_FE_SHIFT                  (31U)
#define CTU_TGSISR_I15_FE_WIDTH                  (1U)
#define CTU_TGSISR_I15_FE(x)                     (((uint32_t)(((uint32_t)(x)) << CTU_TGSISR_I15_FE_SHIFT)) & CTU_TGSISR_I15_FE_MASK)
/*! @} */

/*! @name TGSCR - Trigger Generator Subunit Control Register */
/*! @{ */

#define CTU_TGSCR_TGS_M_MASK                     (0x1U)
#define CTU_TGSCR_TGS_M_SHIFT                    (0U)
#define CTU_TGSCR_TGS_M_WIDTH                    (1U)
#define CTU_TGSCR_TGS_M(x)                       (((uint16_t)(((uint16_t)(x)) << CTU_TGSCR_TGS_M_SHIFT)) & CTU_TGSCR_TGS_M_MASK)

#define CTU_TGSCR_MRS_SM_MASK                    (0x3EU)
#define CTU_TGSCR_MRS_SM_SHIFT                   (1U)
#define CTU_TGSCR_MRS_SM_WIDTH                   (5U)
#define CTU_TGSCR_MRS_SM(x)                      (((uint16_t)(((uint16_t)(x)) << CTU_TGSCR_MRS_SM_SHIFT)) & CTU_TGSCR_MRS_SM_MASK)

#define CTU_TGSCR_PRES_MASK                      (0xC0U)
#define CTU_TGSCR_PRES_SHIFT                     (6U)
#define CTU_TGSCR_PRES_WIDTH                     (2U)
#define CTU_TGSCR_PRES(x)                        (((uint16_t)(((uint16_t)(x)) << CTU_TGSCR_PRES_SHIFT)) & CTU_TGSCR_PRES_MASK)

#define CTU_TGSCR_ET_TM_MASK                     (0x100U)
#define CTU_TGSCR_ET_TM_SHIFT                    (8U)
#define CTU_TGSCR_ET_TM_WIDTH                    (1U)
#define CTU_TGSCR_ET_TM(x)                       (((uint16_t)(((uint16_t)(x)) << CTU_TGSCR_ET_TM_SHIFT)) & CTU_TGSCR_ET_TM_MASK)
/*! @} */

/*! @name TCR - Trigger Compare Register */
/*! @{ */

#define CTU_TCR_TCRV_MASK                        (0xFFFFU)
#define CTU_TCR_TCRV_SHIFT                       (0U)
#define CTU_TCR_TCRV_WIDTH                       (16U)
#define CTU_TCR_TCRV(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_TCR_TCRV_SHIFT)) & CTU_TCR_TCRV_MASK)
/*! @} */

/*! @name TGSCCR - TGS Counter Compare Register */
/*! @{ */

#define CTU_TGSCCR_TGSCCV_MASK                   (0xFFFFU)
#define CTU_TGSCCR_TGSCCV_SHIFT                  (0U)
#define CTU_TGSCCR_TGSCCV_WIDTH                  (16U)
#define CTU_TGSCCR_TGSCCV(x)                     (((uint16_t)(((uint16_t)(x)) << CTU_TGSCCR_TGSCCV_SHIFT)) & CTU_TGSCCR_TGSCCV_MASK)
/*! @} */

/*! @name TGSCRR - TGS Counter Reload Register */
/*! @{ */

#define CTU_TGSCRR_TGSCRV_MASK                   (0xFFFFU)
#define CTU_TGSCRR_TGSCRV_SHIFT                  (0U)
#define CTU_TGSCRR_TGSCRV_WIDTH                  (16U)
#define CTU_TGSCRR_TGSCRV(x)                     (((uint16_t)(((uint16_t)(x)) << CTU_TGSCRR_TGSCRV_SHIFT)) & CTU_TGSCRR_TGSCRV_MASK)
/*! @} */

/*! @name CLCR1 - Commands List Control Register 1 */
/*! @{ */

#define CTU_CLCR1_T0_INDEX_MASK                  (0x1FU)
#define CTU_CLCR1_T0_INDEX_SHIFT                 (0U)
#define CTU_CLCR1_T0_INDEX_WIDTH                 (5U)
#define CTU_CLCR1_T0_INDEX(x)                    (((uint32_t)(((uint32_t)(x)) << CTU_CLCR1_T0_INDEX_SHIFT)) & CTU_CLCR1_T0_INDEX_MASK)

#define CTU_CLCR1_T1_INDEX_MASK                  (0x1F00U)
#define CTU_CLCR1_T1_INDEX_SHIFT                 (8U)
#define CTU_CLCR1_T1_INDEX_WIDTH                 (5U)
#define CTU_CLCR1_T1_INDEX(x)                    (((uint32_t)(((uint32_t)(x)) << CTU_CLCR1_T1_INDEX_SHIFT)) & CTU_CLCR1_T1_INDEX_MASK)

#define CTU_CLCR1_T2_INDEX_MASK                  (0x1F0000U)
#define CTU_CLCR1_T2_INDEX_SHIFT                 (16U)
#define CTU_CLCR1_T2_INDEX_WIDTH                 (5U)
#define CTU_CLCR1_T2_INDEX(x)                    (((uint32_t)(((uint32_t)(x)) << CTU_CLCR1_T2_INDEX_SHIFT)) & CTU_CLCR1_T2_INDEX_MASK)

#define CTU_CLCR1_T3_INDEX_MASK                  (0x1F000000U)
#define CTU_CLCR1_T3_INDEX_SHIFT                 (24U)
#define CTU_CLCR1_T3_INDEX_WIDTH                 (5U)
#define CTU_CLCR1_T3_INDEX(x)                    (((uint32_t)(((uint32_t)(x)) << CTU_CLCR1_T3_INDEX_SHIFT)) & CTU_CLCR1_T3_INDEX_MASK)
/*! @} */

/*! @name CLCR2 - Commands List Control Register 2 */
/*! @{ */

#define CTU_CLCR2_T4_INDEX_MASK                  (0x1FU)
#define CTU_CLCR2_T4_INDEX_SHIFT                 (0U)
#define CTU_CLCR2_T4_INDEX_WIDTH                 (5U)
#define CTU_CLCR2_T4_INDEX(x)                    (((uint32_t)(((uint32_t)(x)) << CTU_CLCR2_T4_INDEX_SHIFT)) & CTU_CLCR2_T4_INDEX_MASK)

#define CTU_CLCR2_T5_INDEX_MASK                  (0x1F00U)
#define CTU_CLCR2_T5_INDEX_SHIFT                 (8U)
#define CTU_CLCR2_T5_INDEX_WIDTH                 (5U)
#define CTU_CLCR2_T5_INDEX(x)                    (((uint32_t)(((uint32_t)(x)) << CTU_CLCR2_T5_INDEX_SHIFT)) & CTU_CLCR2_T5_INDEX_MASK)

#define CTU_CLCR2_T6_INDEX_MASK                  (0x1F0000U)
#define CTU_CLCR2_T6_INDEX_SHIFT                 (16U)
#define CTU_CLCR2_T6_INDEX_WIDTH                 (5U)
#define CTU_CLCR2_T6_INDEX(x)                    (((uint32_t)(((uint32_t)(x)) << CTU_CLCR2_T6_INDEX_SHIFT)) & CTU_CLCR2_T6_INDEX_MASK)

#define CTU_CLCR2_T7_INDEX_MASK                  (0x1F000000U)
#define CTU_CLCR2_T7_INDEX_SHIFT                 (24U)
#define CTU_CLCR2_T7_INDEX_WIDTH                 (5U)
#define CTU_CLCR2_T7_INDEX(x)                    (((uint32_t)(((uint32_t)(x)) << CTU_CLCR2_T7_INDEX_SHIFT)) & CTU_CLCR2_T7_INDEX_MASK)
/*! @} */

/*! @name THCR1 - Trigger Handler Control Register 1 */
/*! @{ */

#define CTU_THCR1_T0_ADCE_MASK                   (0x1U)
#define CTU_THCR1_T0_ADCE_SHIFT                  (0U)
#define CTU_THCR1_T0_ADCE_WIDTH                  (1U)
#define CTU_THCR1_T0_ADCE(x)                     (((uint32_t)(((uint32_t)(x)) << CTU_THCR1_T0_ADCE_SHIFT)) & CTU_THCR1_T0_ADCE_MASK)

#define CTU_THCR1_T0_E_MASK                      (0x40U)
#define CTU_THCR1_T0_E_SHIFT                     (6U)
#define CTU_THCR1_T0_E_WIDTH                     (1U)
#define CTU_THCR1_T0_E(x)                        (((uint32_t)(((uint32_t)(x)) << CTU_THCR1_T0_E_SHIFT)) & CTU_THCR1_T0_E_MASK)

#define CTU_THCR1_T1_ADCE_MASK                   (0x100U)
#define CTU_THCR1_T1_ADCE_SHIFT                  (8U)
#define CTU_THCR1_T1_ADCE_WIDTH                  (1U)
#define CTU_THCR1_T1_ADCE(x)                     (((uint32_t)(((uint32_t)(x)) << CTU_THCR1_T1_ADCE_SHIFT)) & CTU_THCR1_T1_ADCE_MASK)

#define CTU_THCR1_T1_E_MASK                      (0x4000U)
#define CTU_THCR1_T1_E_SHIFT                     (14U)
#define CTU_THCR1_T1_E_WIDTH                     (1U)
#define CTU_THCR1_T1_E(x)                        (((uint32_t)(((uint32_t)(x)) << CTU_THCR1_T1_E_SHIFT)) & CTU_THCR1_T1_E_MASK)

#define CTU_THCR1_T2_ADCE_MASK                   (0x10000U)
#define CTU_THCR1_T2_ADCE_SHIFT                  (16U)
#define CTU_THCR1_T2_ADCE_WIDTH                  (1U)
#define CTU_THCR1_T2_ADCE(x)                     (((uint32_t)(((uint32_t)(x)) << CTU_THCR1_T2_ADCE_SHIFT)) & CTU_THCR1_T2_ADCE_MASK)

#define CTU_THCR1_T2_E_MASK                      (0x400000U)
#define CTU_THCR1_T2_E_SHIFT                     (22U)
#define CTU_THCR1_T2_E_WIDTH                     (1U)
#define CTU_THCR1_T2_E(x)                        (((uint32_t)(((uint32_t)(x)) << CTU_THCR1_T2_E_SHIFT)) & CTU_THCR1_T2_E_MASK)

#define CTU_THCR1_T3_ADCE_MASK                   (0x1000000U)
#define CTU_THCR1_T3_ADCE_SHIFT                  (24U)
#define CTU_THCR1_T3_ADCE_WIDTH                  (1U)
#define CTU_THCR1_T3_ADCE(x)                     (((uint32_t)(((uint32_t)(x)) << CTU_THCR1_T3_ADCE_SHIFT)) & CTU_THCR1_T3_ADCE_MASK)

#define CTU_THCR1_T3_E_MASK                      (0x40000000U)
#define CTU_THCR1_T3_E_SHIFT                     (30U)
#define CTU_THCR1_T3_E_WIDTH                     (1U)
#define CTU_THCR1_T3_E(x)                        (((uint32_t)(((uint32_t)(x)) << CTU_THCR1_T3_E_SHIFT)) & CTU_THCR1_T3_E_MASK)
/*! @} */

/*! @name THCR2 - Trigger Handler Control Register 2 */
/*! @{ */

#define CTU_THCR2_T4_ADCE_MASK                   (0x1U)
#define CTU_THCR2_T4_ADCE_SHIFT                  (0U)
#define CTU_THCR2_T4_ADCE_WIDTH                  (1U)
#define CTU_THCR2_T4_ADCE(x)                     (((uint32_t)(((uint32_t)(x)) << CTU_THCR2_T4_ADCE_SHIFT)) & CTU_THCR2_T4_ADCE_MASK)

#define CTU_THCR2_T4_E_MASK                      (0x40U)
#define CTU_THCR2_T4_E_SHIFT                     (6U)
#define CTU_THCR2_T4_E_WIDTH                     (1U)
#define CTU_THCR2_T4_E(x)                        (((uint32_t)(((uint32_t)(x)) << CTU_THCR2_T4_E_SHIFT)) & CTU_THCR2_T4_E_MASK)

#define CTU_THCR2_T5_ADCE_MASK                   (0x100U)
#define CTU_THCR2_T5_ADCE_SHIFT                  (8U)
#define CTU_THCR2_T5_ADCE_WIDTH                  (1U)
#define CTU_THCR2_T5_ADCE(x)                     (((uint32_t)(((uint32_t)(x)) << CTU_THCR2_T5_ADCE_SHIFT)) & CTU_THCR2_T5_ADCE_MASK)

#define CTU_THCR2_T5_E_MASK                      (0x4000U)
#define CTU_THCR2_T5_E_SHIFT                     (14U)
#define CTU_THCR2_T5_E_WIDTH                     (1U)
#define CTU_THCR2_T5_E(x)                        (((uint32_t)(((uint32_t)(x)) << CTU_THCR2_T5_E_SHIFT)) & CTU_THCR2_T5_E_MASK)

#define CTU_THCR2_T6_ADCE_MASK                   (0x10000U)
#define CTU_THCR2_T6_ADCE_SHIFT                  (16U)
#define CTU_THCR2_T6_ADCE_WIDTH                  (1U)
#define CTU_THCR2_T6_ADCE(x)                     (((uint32_t)(((uint32_t)(x)) << CTU_THCR2_T6_ADCE_SHIFT)) & CTU_THCR2_T6_ADCE_MASK)

#define CTU_THCR2_T6_E_MASK                      (0x400000U)
#define CTU_THCR2_T6_E_SHIFT                     (22U)
#define CTU_THCR2_T6_E_WIDTH                     (1U)
#define CTU_THCR2_T6_E(x)                        (((uint32_t)(((uint32_t)(x)) << CTU_THCR2_T6_E_SHIFT)) & CTU_THCR2_T6_E_MASK)

#define CTU_THCR2_T7_ADCE_MASK                   (0x1000000U)
#define CTU_THCR2_T7_ADCE_SHIFT                  (24U)
#define CTU_THCR2_T7_ADCE_WIDTH                  (1U)
#define CTU_THCR2_T7_ADCE(x)                     (((uint32_t)(((uint32_t)(x)) << CTU_THCR2_T7_ADCE_SHIFT)) & CTU_THCR2_T7_ADCE_MASK)

#define CTU_THCR2_T7_E_MASK                      (0x40000000U)
#define CTU_THCR2_T7_E_SHIFT                     (30U)
#define CTU_THCR2_T7_E_WIDTH                     (1U)
#define CTU_THCR2_T7_E(x)                        (((uint32_t)(((uint32_t)(x)) << CTU_THCR2_T7_E_SHIFT)) & CTU_THCR2_T7_E_MASK)
/*! @} */

/*! @name A - Commands List Register A for ADC single-conversion mode commands */
/*! @{ */

#define CTU_A_CH_MASK                            (0xFU)
#define CTU_A_CH_SHIFT                           (0U)
#define CTU_A_CH_WIDTH                           (4U)
#define CTU_A_CH(x)                              (((uint16_t)(((uint16_t)(x)) << CTU_A_CH_SHIFT)) & CTU_A_CH_MASK)

#define CTU_A_SU_MASK                            (0x20U)
#define CTU_A_SU_SHIFT                           (5U)
#define CTU_A_SU_WIDTH                           (1U)
#define CTU_A_SU(x)                              (((uint16_t)(((uint16_t)(x)) << CTU_A_SU_SHIFT)) & CTU_A_SU_MASK)

#define CTU_A_FIFO_MASK                          (0x1C00U)
#define CTU_A_FIFO_SHIFT                         (10U)
#define CTU_A_FIFO_WIDTH                         (3U)
#define CTU_A_FIFO(x)                            (((uint16_t)(((uint16_t)(x)) << CTU_A_FIFO_SHIFT)) & CTU_A_FIFO_MASK)

#define CTU_A_CMS_MASK                           (0x2000U)
#define CTU_A_CMS_SHIFT                          (13U)
#define CTU_A_CMS_WIDTH                          (1U)
#define CTU_A_CMS(x)                             (((uint16_t)(((uint16_t)(x)) << CTU_A_CMS_SHIFT)) & CTU_A_CMS_MASK)

#define CTU_A_LC_MASK                            (0x4000U)
#define CTU_A_LC_SHIFT                           (14U)
#define CTU_A_LC_WIDTH                           (1U)
#define CTU_A_LC(x)                              (((uint16_t)(((uint16_t)(x)) << CTU_A_LC_SHIFT)) & CTU_A_LC_MASK)

#define CTU_A_CIR_MASK                           (0x8000U)
#define CTU_A_CIR_SHIFT                          (15U)
#define CTU_A_CIR_WIDTH                          (1U)
#define CTU_A_CIR(x)                             (((uint16_t)(((uint16_t)(x)) << CTU_A_CIR_SHIFT)) & CTU_A_CIR_MASK)
/*! @} */

/*! @name B - Command List Register B for ADC dual-conversion mode commands */
/*! @{ */

#define CTU_B_CH_A_MASK                          (0xFU)
#define CTU_B_CH_A_SHIFT                         (0U)
#define CTU_B_CH_A_WIDTH                         (4U)
#define CTU_B_CH_A(x)                            (((uint16_t)(((uint16_t)(x)) << CTU_B_CH_A_SHIFT)) & CTU_B_CH_A_MASK)

#define CTU_B_CH_B_MASK                          (0x1E0U)
#define CTU_B_CH_B_SHIFT                         (5U)
#define CTU_B_CH_B_WIDTH                         (4U)
#define CTU_B_CH_B(x)                            (((uint16_t)(((uint16_t)(x)) << CTU_B_CH_B_SHIFT)) & CTU_B_CH_B_MASK)

#define CTU_B_FIFO_MASK                          (0x1C00U)
#define CTU_B_FIFO_SHIFT                         (10U)
#define CTU_B_FIFO_WIDTH                         (3U)
#define CTU_B_FIFO(x)                            (((uint16_t)(((uint16_t)(x)) << CTU_B_FIFO_SHIFT)) & CTU_B_FIFO_MASK)

#define CTU_B_CMS_MASK                           (0x2000U)
#define CTU_B_CMS_SHIFT                          (13U)
#define CTU_B_CMS_WIDTH                          (1U)
#define CTU_B_CMS(x)                             (((uint16_t)(((uint16_t)(x)) << CTU_B_CMS_SHIFT)) & CTU_B_CMS_MASK)

#define CTU_B_LC_MASK                            (0x4000U)
#define CTU_B_LC_SHIFT                           (14U)
#define CTU_B_LC_WIDTH                           (1U)
#define CTU_B_LC(x)                              (((uint16_t)(((uint16_t)(x)) << CTU_B_LC_SHIFT)) & CTU_B_LC_MASK)

#define CTU_B_CIR_MASK                           (0x8000U)
#define CTU_B_CIR_SHIFT                          (15U)
#define CTU_B_CIR_WIDTH                          (1U)
#define CTU_B_CIR(x)                             (((uint16_t)(((uint16_t)(x)) << CTU_B_CIR_SHIFT)) & CTU_B_CIR_MASK)
/*! @} */

/*! @name FDCR - FIFO DMA Control Register */
/*! @{ */

#define CTU_FDCR_DE0_MASK                        (0x1U)
#define CTU_FDCR_DE0_SHIFT                       (0U)
#define CTU_FDCR_DE0_WIDTH                       (1U)
#define CTU_FDCR_DE0(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_FDCR_DE0_SHIFT)) & CTU_FDCR_DE0_MASK)

#define CTU_FDCR_DE1_MASK                        (0x2U)
#define CTU_FDCR_DE1_SHIFT                       (1U)
#define CTU_FDCR_DE1_WIDTH                       (1U)
#define CTU_FDCR_DE1(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_FDCR_DE1_SHIFT)) & CTU_FDCR_DE1_MASK)

#define CTU_FDCR_DE2_MASK                        (0x4U)
#define CTU_FDCR_DE2_SHIFT                       (2U)
#define CTU_FDCR_DE2_WIDTH                       (1U)
#define CTU_FDCR_DE2(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_FDCR_DE2_SHIFT)) & CTU_FDCR_DE2_MASK)

#define CTU_FDCR_DE3_MASK                        (0x8U)
#define CTU_FDCR_DE3_SHIFT                       (3U)
#define CTU_FDCR_DE3_WIDTH                       (1U)
#define CTU_FDCR_DE3(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_FDCR_DE3_SHIFT)) & CTU_FDCR_DE3_MASK)
/*! @} */

/*! @name FCR - FIFO Control Register */
/*! @{ */

#define CTU_FCR_FULL_EN0_MASK                    (0x1U)
#define CTU_FCR_FULL_EN0_SHIFT                   (0U)
#define CTU_FCR_FULL_EN0_WIDTH                   (1U)
#define CTU_FCR_FULL_EN0(x)                      (((uint32_t)(((uint32_t)(x)) << CTU_FCR_FULL_EN0_SHIFT)) & CTU_FCR_FULL_EN0_MASK)

#define CTU_FCR_EMPTY_EN0_MASK                   (0x2U)
#define CTU_FCR_EMPTY_EN0_SHIFT                  (1U)
#define CTU_FCR_EMPTY_EN0_WIDTH                  (1U)
#define CTU_FCR_EMPTY_EN0(x)                     (((uint32_t)(((uint32_t)(x)) << CTU_FCR_EMPTY_EN0_SHIFT)) & CTU_FCR_EMPTY_EN0_MASK)

#define CTU_FCR_OF_EN0_MASK                      (0x4U)
#define CTU_FCR_OF_EN0_SHIFT                     (2U)
#define CTU_FCR_OF_EN0_WIDTH                     (1U)
#define CTU_FCR_OF_EN0(x)                        (((uint32_t)(((uint32_t)(x)) << CTU_FCR_OF_EN0_SHIFT)) & CTU_FCR_OF_EN0_MASK)

#define CTU_FCR_OR_EN0_MASK                      (0x8U)
#define CTU_FCR_OR_EN0_SHIFT                     (3U)
#define CTU_FCR_OR_EN0_WIDTH                     (1U)
#define CTU_FCR_OR_EN0(x)                        (((uint32_t)(((uint32_t)(x)) << CTU_FCR_OR_EN0_SHIFT)) & CTU_FCR_OR_EN0_MASK)

#define CTU_FCR_FULL_EN1_MASK                    (0x10U)
#define CTU_FCR_FULL_EN1_SHIFT                   (4U)
#define CTU_FCR_FULL_EN1_WIDTH                   (1U)
#define CTU_FCR_FULL_EN1(x)                      (((uint32_t)(((uint32_t)(x)) << CTU_FCR_FULL_EN1_SHIFT)) & CTU_FCR_FULL_EN1_MASK)

#define CTU_FCR_EMPTY_EN1_MASK                   (0x20U)
#define CTU_FCR_EMPTY_EN1_SHIFT                  (5U)
#define CTU_FCR_EMPTY_EN1_WIDTH                  (1U)
#define CTU_FCR_EMPTY_EN1(x)                     (((uint32_t)(((uint32_t)(x)) << CTU_FCR_EMPTY_EN1_SHIFT)) & CTU_FCR_EMPTY_EN1_MASK)

#define CTU_FCR_OF_EN1_MASK                      (0x40U)
#define CTU_FCR_OF_EN1_SHIFT                     (6U)
#define CTU_FCR_OF_EN1_WIDTH                     (1U)
#define CTU_FCR_OF_EN1(x)                        (((uint32_t)(((uint32_t)(x)) << CTU_FCR_OF_EN1_SHIFT)) & CTU_FCR_OF_EN1_MASK)

#define CTU_FCR_OR_EN1_MASK                      (0x80U)
#define CTU_FCR_OR_EN1_SHIFT                     (7U)
#define CTU_FCR_OR_EN1_WIDTH                     (1U)
#define CTU_FCR_OR_EN1(x)                        (((uint32_t)(((uint32_t)(x)) << CTU_FCR_OR_EN1_SHIFT)) & CTU_FCR_OR_EN1_MASK)

#define CTU_FCR_FULL_EN2_MASK                    (0x100U)
#define CTU_FCR_FULL_EN2_SHIFT                   (8U)
#define CTU_FCR_FULL_EN2_WIDTH                   (1U)
#define CTU_FCR_FULL_EN2(x)                      (((uint32_t)(((uint32_t)(x)) << CTU_FCR_FULL_EN2_SHIFT)) & CTU_FCR_FULL_EN2_MASK)

#define CTU_FCR_EMPTY_EN2_MASK                   (0x200U)
#define CTU_FCR_EMPTY_EN2_SHIFT                  (9U)
#define CTU_FCR_EMPTY_EN2_WIDTH                  (1U)
#define CTU_FCR_EMPTY_EN2(x)                     (((uint32_t)(((uint32_t)(x)) << CTU_FCR_EMPTY_EN2_SHIFT)) & CTU_FCR_EMPTY_EN2_MASK)

#define CTU_FCR_OF_EN2_MASK                      (0x400U)
#define CTU_FCR_OF_EN2_SHIFT                     (10U)
#define CTU_FCR_OF_EN2_WIDTH                     (1U)
#define CTU_FCR_OF_EN2(x)                        (((uint32_t)(((uint32_t)(x)) << CTU_FCR_OF_EN2_SHIFT)) & CTU_FCR_OF_EN2_MASK)

#define CTU_FCR_OR_EN2_MASK                      (0x800U)
#define CTU_FCR_OR_EN2_SHIFT                     (11U)
#define CTU_FCR_OR_EN2_WIDTH                     (1U)
#define CTU_FCR_OR_EN2(x)                        (((uint32_t)(((uint32_t)(x)) << CTU_FCR_OR_EN2_SHIFT)) & CTU_FCR_OR_EN2_MASK)

#define CTU_FCR_FULL_EN3_MASK                    (0x1000U)
#define CTU_FCR_FULL_EN3_SHIFT                   (12U)
#define CTU_FCR_FULL_EN3_WIDTH                   (1U)
#define CTU_FCR_FULL_EN3(x)                      (((uint32_t)(((uint32_t)(x)) << CTU_FCR_FULL_EN3_SHIFT)) & CTU_FCR_FULL_EN3_MASK)

#define CTU_FCR_EMPTY_EN3_MASK                   (0x2000U)
#define CTU_FCR_EMPTY_EN3_SHIFT                  (13U)
#define CTU_FCR_EMPTY_EN3_WIDTH                  (1U)
#define CTU_FCR_EMPTY_EN3(x)                     (((uint32_t)(((uint32_t)(x)) << CTU_FCR_EMPTY_EN3_SHIFT)) & CTU_FCR_EMPTY_EN3_MASK)

#define CTU_FCR_OF_EN3_MASK                      (0x4000U)
#define CTU_FCR_OF_EN3_SHIFT                     (14U)
#define CTU_FCR_OF_EN3_WIDTH                     (1U)
#define CTU_FCR_OF_EN3(x)                        (((uint32_t)(((uint32_t)(x)) << CTU_FCR_OF_EN3_SHIFT)) & CTU_FCR_OF_EN3_MASK)

#define CTU_FCR_OR_EN3_MASK                      (0x8000U)
#define CTU_FCR_OR_EN3_SHIFT                     (15U)
#define CTU_FCR_OR_EN3_WIDTH                     (1U)
#define CTU_FCR_OR_EN3(x)                        (((uint32_t)(((uint32_t)(x)) << CTU_FCR_OR_EN3_SHIFT)) & CTU_FCR_OR_EN3_MASK)
/*! @} */

/*! @name FTH - FIFO Threshold Register */
/*! @{ */

#define CTU_FTH_TH0_MASK                         (0xFFU)
#define CTU_FTH_TH0_SHIFT                        (0U)
#define CTU_FTH_TH0_WIDTH                        (8U)
#define CTU_FTH_TH0(x)                           (((uint32_t)(((uint32_t)(x)) << CTU_FTH_TH0_SHIFT)) & CTU_FTH_TH0_MASK)

#define CTU_FTH_TH1_MASK                         (0xFF00U)
#define CTU_FTH_TH1_SHIFT                        (8U)
#define CTU_FTH_TH1_WIDTH                        (8U)
#define CTU_FTH_TH1(x)                           (((uint32_t)(((uint32_t)(x)) << CTU_FTH_TH1_SHIFT)) & CTU_FTH_TH1_MASK)

#define CTU_FTH_TH2_MASK                         (0xFF0000U)
#define CTU_FTH_TH2_SHIFT                        (16U)
#define CTU_FTH_TH2_WIDTH                        (8U)
#define CTU_FTH_TH2(x)                           (((uint32_t)(((uint32_t)(x)) << CTU_FTH_TH2_SHIFT)) & CTU_FTH_TH2_MASK)

#define CTU_FTH_TH3_MASK                         (0xFF000000U)
#define CTU_FTH_TH3_SHIFT                        (24U)
#define CTU_FTH_TH3_WIDTH                        (8U)
#define CTU_FTH_TH3(x)                           (((uint32_t)(((uint32_t)(x)) << CTU_FTH_TH3_SHIFT)) & CTU_FTH_TH3_MASK)
/*! @} */

/*! @name FST - FIFO Status Register */
/*! @{ */

#define CTU_FST_FULL0_MASK                       (0x1U)
#define CTU_FST_FULL0_SHIFT                      (0U)
#define CTU_FST_FULL0_WIDTH                      (1U)
#define CTU_FST_FULL0(x)                         (((uint32_t)(((uint32_t)(x)) << CTU_FST_FULL0_SHIFT)) & CTU_FST_FULL0_MASK)

#define CTU_FST_EMP0_MASK                        (0x2U)
#define CTU_FST_EMP0_SHIFT                       (1U)
#define CTU_FST_EMP0_WIDTH                       (1U)
#define CTU_FST_EMP0(x)                          (((uint32_t)(((uint32_t)(x)) << CTU_FST_EMP0_SHIFT)) & CTU_FST_EMP0_MASK)

#define CTU_FST_OF0_MASK                         (0x4U)
#define CTU_FST_OF0_SHIFT                        (2U)
#define CTU_FST_OF0_WIDTH                        (1U)
#define CTU_FST_OF0(x)                           (((uint32_t)(((uint32_t)(x)) << CTU_FST_OF0_SHIFT)) & CTU_FST_OF0_MASK)

#define CTU_FST_OR0_MASK                         (0x8U)
#define CTU_FST_OR0_SHIFT                        (3U)
#define CTU_FST_OR0_WIDTH                        (1U)
#define CTU_FST_OR0(x)                           (((uint32_t)(((uint32_t)(x)) << CTU_FST_OR0_SHIFT)) & CTU_FST_OR0_MASK)

#define CTU_FST_FULL1_MASK                       (0x10U)
#define CTU_FST_FULL1_SHIFT                      (4U)
#define CTU_FST_FULL1_WIDTH                      (1U)
#define CTU_FST_FULL1(x)                         (((uint32_t)(((uint32_t)(x)) << CTU_FST_FULL1_SHIFT)) & CTU_FST_FULL1_MASK)

#define CTU_FST_EMP1_MASK                        (0x20U)
#define CTU_FST_EMP1_SHIFT                       (5U)
#define CTU_FST_EMP1_WIDTH                       (1U)
#define CTU_FST_EMP1(x)                          (((uint32_t)(((uint32_t)(x)) << CTU_FST_EMP1_SHIFT)) & CTU_FST_EMP1_MASK)

#define CTU_FST_OF1_MASK                         (0x40U)
#define CTU_FST_OF1_SHIFT                        (6U)
#define CTU_FST_OF1_WIDTH                        (1U)
#define CTU_FST_OF1(x)                           (((uint32_t)(((uint32_t)(x)) << CTU_FST_OF1_SHIFT)) & CTU_FST_OF1_MASK)

#define CTU_FST_OR1_MASK                         (0x80U)
#define CTU_FST_OR1_SHIFT                        (7U)
#define CTU_FST_OR1_WIDTH                        (1U)
#define CTU_FST_OR1(x)                           (((uint32_t)(((uint32_t)(x)) << CTU_FST_OR1_SHIFT)) & CTU_FST_OR1_MASK)

#define CTU_FST_FULL2_MASK                       (0x100U)
#define CTU_FST_FULL2_SHIFT                      (8U)
#define CTU_FST_FULL2_WIDTH                      (1U)
#define CTU_FST_FULL2(x)                         (((uint32_t)(((uint32_t)(x)) << CTU_FST_FULL2_SHIFT)) & CTU_FST_FULL2_MASK)

#define CTU_FST_EMP2_MASK                        (0x200U)
#define CTU_FST_EMP2_SHIFT                       (9U)
#define CTU_FST_EMP2_WIDTH                       (1U)
#define CTU_FST_EMP2(x)                          (((uint32_t)(((uint32_t)(x)) << CTU_FST_EMP2_SHIFT)) & CTU_FST_EMP2_MASK)

#define CTU_FST_OF2_MASK                         (0x400U)
#define CTU_FST_OF2_SHIFT                        (10U)
#define CTU_FST_OF2_WIDTH                        (1U)
#define CTU_FST_OF2(x)                           (((uint32_t)(((uint32_t)(x)) << CTU_FST_OF2_SHIFT)) & CTU_FST_OF2_MASK)

#define CTU_FST_OR2_MASK                         (0x800U)
#define CTU_FST_OR2_SHIFT                        (11U)
#define CTU_FST_OR2_WIDTH                        (1U)
#define CTU_FST_OR2(x)                           (((uint32_t)(((uint32_t)(x)) << CTU_FST_OR2_SHIFT)) & CTU_FST_OR2_MASK)

#define CTU_FST_FULL3_MASK                       (0x1000U)
#define CTU_FST_FULL3_SHIFT                      (12U)
#define CTU_FST_FULL3_WIDTH                      (1U)
#define CTU_FST_FULL3(x)                         (((uint32_t)(((uint32_t)(x)) << CTU_FST_FULL3_SHIFT)) & CTU_FST_FULL3_MASK)

#define CTU_FST_EMP3_MASK                        (0x2000U)
#define CTU_FST_EMP3_SHIFT                       (13U)
#define CTU_FST_EMP3_WIDTH                       (1U)
#define CTU_FST_EMP3(x)                          (((uint32_t)(((uint32_t)(x)) << CTU_FST_EMP3_SHIFT)) & CTU_FST_EMP3_MASK)

#define CTU_FST_OF3_MASK                         (0x4000U)
#define CTU_FST_OF3_SHIFT                        (14U)
#define CTU_FST_OF3_WIDTH                        (1U)
#define CTU_FST_OF3(x)                           (((uint32_t)(((uint32_t)(x)) << CTU_FST_OF3_SHIFT)) & CTU_FST_OF3_MASK)

#define CTU_FST_OR3_MASK                         (0x8000U)
#define CTU_FST_OR3_SHIFT                        (15U)
#define CTU_FST_OR3_WIDTH                        (1U)
#define CTU_FST_OR3(x)                           (((uint32_t)(((uint32_t)(x)) << CTU_FST_OR3_SHIFT)) & CTU_FST_OR3_MASK)
/*! @} */

/*! @name FR - FIFO Right Aligned Data Register */
/*! @{ */

#define CTU_FR_DATA_MASK                         (0xFFFU)
#define CTU_FR_DATA_SHIFT                        (0U)
#define CTU_FR_DATA_WIDTH                        (12U)
#define CTU_FR_DATA(x)                           (((uint32_t)(((uint32_t)(x)) << CTU_FR_DATA_SHIFT)) & CTU_FR_DATA_MASK)

#define CTU_FR_N_CH_MASK                         (0x70000U)
#define CTU_FR_N_CH_SHIFT                        (16U)
#define CTU_FR_N_CH_WIDTH                        (3U)
#define CTU_FR_N_CH(x)                           (((uint32_t)(((uint32_t)(x)) << CTU_FR_N_CH_SHIFT)) & CTU_FR_N_CH_MASK)

#define CTU_FR_ADC_MASK                          (0x80000U)
#define CTU_FR_ADC_SHIFT                         (19U)
#define CTU_FR_ADC_WIDTH                         (1U)
#define CTU_FR_ADC(x)                            (((uint32_t)(((uint32_t)(x)) << CTU_FR_ADC_SHIFT)) & CTU_FR_ADC_MASK)
/*! @} */

/*! @name FL - FIFO Signed Left Aligned Data Register */
/*! @{ */

#define CTU_FL_LA_DATA_MASK                      (0x7FF8U)
#define CTU_FL_LA_DATA_SHIFT                     (3U)
#define CTU_FL_LA_DATA_WIDTH                     (12U)
#define CTU_FL_LA_DATA(x)                        (((uint32_t)(((uint32_t)(x)) << CTU_FL_LA_DATA_SHIFT)) & CTU_FL_LA_DATA_MASK)

#define CTU_FL_N_CH_MASK                         (0x70000U)
#define CTU_FL_N_CH_SHIFT                        (16U)
#define CTU_FL_N_CH_WIDTH                        (3U)
#define CTU_FL_N_CH(x)                           (((uint32_t)(((uint32_t)(x)) << CTU_FL_N_CH_SHIFT)) & CTU_FL_N_CH_MASK)

#define CTU_FL_ADC_MASK                          (0x80000U)
#define CTU_FL_ADC_SHIFT                         (19U)
#define CTU_FL_ADC_WIDTH                         (1U)
#define CTU_FL_ADC(x)                            (((uint32_t)(((uint32_t)(x)) << CTU_FL_ADC_SHIFT)) & CTU_FL_ADC_MASK)
/*! @} */

/*! @name EFR - Error Flag Register */
/*! @{ */

#define CTU_EFR_MRS_RE_MASK                      (0x1U)
#define CTU_EFR_MRS_RE_SHIFT                     (0U)
#define CTU_EFR_MRS_RE_WIDTH                     (1U)
#define CTU_EFR_MRS_RE(x)                        (((uint16_t)(((uint16_t)(x)) << CTU_EFR_MRS_RE_SHIFT)) & CTU_EFR_MRS_RE_MASK)

#define CTU_EFR_SM_TO_MASK                       (0x2U)
#define CTU_EFR_SM_TO_SHIFT                      (1U)
#define CTU_EFR_SM_TO_WIDTH                      (1U)
#define CTU_EFR_SM_TO(x)                         (((uint16_t)(((uint16_t)(x)) << CTU_EFR_SM_TO_SHIFT)) & CTU_EFR_SM_TO_MASK)

#define CTU_EFR_ICE_MASK                         (0x4U)
#define CTU_EFR_ICE_SHIFT                        (2U)
#define CTU_EFR_ICE_WIDTH                        (1U)
#define CTU_EFR_ICE(x)                           (((uint16_t)(((uint16_t)(x)) << CTU_EFR_ICE_SHIFT)) & CTU_EFR_ICE_MASK)

#define CTU_EFR_MRS_O_MASK                       (0x8U)
#define CTU_EFR_MRS_O_SHIFT                      (3U)
#define CTU_EFR_MRS_O_WIDTH                      (1U)
#define CTU_EFR_MRS_O(x)                         (((uint16_t)(((uint16_t)(x)) << CTU_EFR_MRS_O_SHIFT)) & CTU_EFR_MRS_O_MASK)

#define CTU_EFR_TGS_OSM_MASK                     (0x10U)
#define CTU_EFR_TGS_OSM_SHIFT                    (4U)
#define CTU_EFR_TGS_OSM_WIDTH                    (1U)
#define CTU_EFR_TGS_OSM(x)                       (((uint16_t)(((uint16_t)(x)) << CTU_EFR_TGS_OSM_SHIFT)) & CTU_EFR_TGS_OSM_MASK)

#define CTU_EFR_ADC_OE_MASK                      (0x20U)
#define CTU_EFR_ADC_OE_SHIFT                     (5U)
#define CTU_EFR_ADC_OE_WIDTH                     (1U)
#define CTU_EFR_ADC_OE(x)                        (((uint16_t)(((uint16_t)(x)) << CTU_EFR_ADC_OE_SHIFT)) & CTU_EFR_ADC_OE_MASK)

#define CTU_EFR_ERRCMP_MASK                      (0x400U)
#define CTU_EFR_ERRCMP_SHIFT                     (10U)
#define CTU_EFR_ERRCMP_WIDTH                     (1U)
#define CTU_EFR_ERRCMP(x)                        (((uint16_t)(((uint16_t)(x)) << CTU_EFR_ERRCMP_SHIFT)) & CTU_EFR_ERRCMP_MASK)

#define CTU_EFR_LIST_BE_MASK                     (0x2000U)
#define CTU_EFR_LIST_BE_SHIFT                    (13U)
#define CTU_EFR_LIST_BE_WIDTH                    (1U)
#define CTU_EFR_LIST_BE(x)                       (((uint16_t)(((uint16_t)(x)) << CTU_EFR_LIST_BE_SHIFT)) & CTU_EFR_LIST_BE_MASK)
/*! @} */

/*! @name IFR - Interrupt Flag Register */
/*! @{ */

#define CTU_IFR_MRS_I_MASK                       (0x1U)
#define CTU_IFR_MRS_I_SHIFT                      (0U)
#define CTU_IFR_MRS_I_WIDTH                      (1U)
#define CTU_IFR_MRS_I(x)                         (((uint16_t)(((uint16_t)(x)) << CTU_IFR_MRS_I_SHIFT)) & CTU_IFR_MRS_I_MASK)

#define CTU_IFR_T0_I_MASK                        (0x2U)
#define CTU_IFR_T0_I_SHIFT                       (1U)
#define CTU_IFR_T0_I_WIDTH                       (1U)
#define CTU_IFR_T0_I(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_IFR_T0_I_SHIFT)) & CTU_IFR_T0_I_MASK)

#define CTU_IFR_T1_I_MASK                        (0x4U)
#define CTU_IFR_T1_I_SHIFT                       (2U)
#define CTU_IFR_T1_I_WIDTH                       (1U)
#define CTU_IFR_T1_I(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_IFR_T1_I_SHIFT)) & CTU_IFR_T1_I_MASK)

#define CTU_IFR_T2_I_MASK                        (0x8U)
#define CTU_IFR_T2_I_SHIFT                       (3U)
#define CTU_IFR_T2_I_WIDTH                       (1U)
#define CTU_IFR_T2_I(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_IFR_T2_I_SHIFT)) & CTU_IFR_T2_I_MASK)

#define CTU_IFR_T3_I_MASK                        (0x10U)
#define CTU_IFR_T3_I_SHIFT                       (4U)
#define CTU_IFR_T3_I_WIDTH                       (1U)
#define CTU_IFR_T3_I(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_IFR_T3_I_SHIFT)) & CTU_IFR_T3_I_MASK)

#define CTU_IFR_T4_I_MASK                        (0x20U)
#define CTU_IFR_T4_I_SHIFT                       (5U)
#define CTU_IFR_T4_I_WIDTH                       (1U)
#define CTU_IFR_T4_I(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_IFR_T4_I_SHIFT)) & CTU_IFR_T4_I_MASK)

#define CTU_IFR_T5_I_MASK                        (0x40U)
#define CTU_IFR_T5_I_SHIFT                       (6U)
#define CTU_IFR_T5_I_WIDTH                       (1U)
#define CTU_IFR_T5_I(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_IFR_T5_I_SHIFT)) & CTU_IFR_T5_I_MASK)

#define CTU_IFR_T6_I_MASK                        (0x80U)
#define CTU_IFR_T6_I_SHIFT                       (7U)
#define CTU_IFR_T6_I_WIDTH                       (1U)
#define CTU_IFR_T6_I(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_IFR_T6_I_SHIFT)) & CTU_IFR_T6_I_MASK)

#define CTU_IFR_T7_I_MASK                        (0x100U)
#define CTU_IFR_T7_I_SHIFT                       (8U)
#define CTU_IFR_T7_I_WIDTH                       (1U)
#define CTU_IFR_T7_I(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_IFR_T7_I_SHIFT)) & CTU_IFR_T7_I_MASK)

#define CTU_IFR_ADC_I_MASK                       (0x200U)
#define CTU_IFR_ADC_I_SHIFT                      (9U)
#define CTU_IFR_ADC_I_WIDTH                      (1U)
#define CTU_IFR_ADC_I(x)                         (((uint16_t)(((uint16_t)(x)) << CTU_IFR_ADC_I_SHIFT)) & CTU_IFR_ADC_I_MASK)

#define CTU_IFR_SERR_A_MASK                      (0x400U)
#define CTU_IFR_SERR_A_SHIFT                     (10U)
#define CTU_IFR_SERR_A_WIDTH                     (1U)
#define CTU_IFR_SERR_A(x)                        (((uint16_t)(((uint16_t)(x)) << CTU_IFR_SERR_A_SHIFT)) & CTU_IFR_SERR_A_MASK)

#define CTU_IFR_SERR_B_MASK                      (0x800U)
#define CTU_IFR_SERR_B_SHIFT                     (11U)
#define CTU_IFR_SERR_B_WIDTH                     (1U)
#define CTU_IFR_SERR_B(x)                        (((uint16_t)(((uint16_t)(x)) << CTU_IFR_SERR_B_SHIFT)) & CTU_IFR_SERR_B_MASK)
/*! @} */

/*! @name IR - Interrupt/DMA Register */
/*! @{ */

#define CTU_IR_IEE_MASK                          (0x1U)
#define CTU_IR_IEE_SHIFT                         (0U)
#define CTU_IR_IEE_WIDTH                         (1U)
#define CTU_IR_IEE(x)                            (((uint16_t)(((uint16_t)(x)) << CTU_IR_IEE_SHIFT)) & CTU_IR_IEE_MASK)

#define CTU_IR_MRS_IE_MASK                       (0x2U)
#define CTU_IR_MRS_IE_SHIFT                      (1U)
#define CTU_IR_MRS_IE_WIDTH                      (1U)
#define CTU_IR_MRS_IE(x)                         (((uint16_t)(((uint16_t)(x)) << CTU_IR_MRS_IE_SHIFT)) & CTU_IR_MRS_IE_MASK)

#define CTU_IR_MRS_DMAE_MASK                     (0x4U)
#define CTU_IR_MRS_DMAE_SHIFT                    (2U)
#define CTU_IR_MRS_DMAE_WIDTH                    (1U)
#define CTU_IR_MRS_DMAE(x)                       (((uint16_t)(((uint16_t)(x)) << CTU_IR_MRS_DMAE_SHIFT)) & CTU_IR_MRS_DMAE_MASK)

#define CTU_IR_DMA_DE_MASK                       (0x8U)
#define CTU_IR_DMA_DE_SHIFT                      (3U)
#define CTU_IR_DMA_DE_WIDTH                      (1U)
#define CTU_IR_DMA_DE(x)                         (((uint16_t)(((uint16_t)(x)) << CTU_IR_DMA_DE_SHIFT)) & CTU_IR_DMA_DE_MASK)

#define CTU_IR_SAF_CNT_A_EN_MASK                 (0x10U)
#define CTU_IR_SAF_CNT_A_EN_SHIFT                (4U)
#define CTU_IR_SAF_CNT_A_EN_WIDTH                (1U)
#define CTU_IR_SAF_CNT_A_EN(x)                   (((uint16_t)(((uint16_t)(x)) << CTU_IR_SAF_CNT_A_EN_SHIFT)) & CTU_IR_SAF_CNT_A_EN_MASK)

#define CTU_IR_SAF_CNT_B_EN_MASK                 (0x20U)
#define CTU_IR_SAF_CNT_B_EN_SHIFT                (5U)
#define CTU_IR_SAF_CNT_B_EN_WIDTH                (1U)
#define CTU_IR_SAF_CNT_B_EN(x)                   (((uint16_t)(((uint16_t)(x)) << CTU_IR_SAF_CNT_B_EN_SHIFT)) & CTU_IR_SAF_CNT_B_EN_MASK)

#define CTU_IR_T0_IE_MASK                        (0x100U)
#define CTU_IR_T0_IE_SHIFT                       (8U)
#define CTU_IR_T0_IE_WIDTH                       (1U)
#define CTU_IR_T0_IE(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_IR_T0_IE_SHIFT)) & CTU_IR_T0_IE_MASK)

#define CTU_IR_T1_IE_MASK                        (0x200U)
#define CTU_IR_T1_IE_SHIFT                       (9U)
#define CTU_IR_T1_IE_WIDTH                       (1U)
#define CTU_IR_T1_IE(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_IR_T1_IE_SHIFT)) & CTU_IR_T1_IE_MASK)

#define CTU_IR_T2_IE_MASK                        (0x400U)
#define CTU_IR_T2_IE_SHIFT                       (10U)
#define CTU_IR_T2_IE_WIDTH                       (1U)
#define CTU_IR_T2_IE(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_IR_T2_IE_SHIFT)) & CTU_IR_T2_IE_MASK)

#define CTU_IR_T3_IE_MASK                        (0x800U)
#define CTU_IR_T3_IE_SHIFT                       (11U)
#define CTU_IR_T3_IE_WIDTH                       (1U)
#define CTU_IR_T3_IE(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_IR_T3_IE_SHIFT)) & CTU_IR_T3_IE_MASK)

#define CTU_IR_T4_IE_MASK                        (0x1000U)
#define CTU_IR_T4_IE_SHIFT                       (12U)
#define CTU_IR_T4_IE_WIDTH                       (1U)
#define CTU_IR_T4_IE(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_IR_T4_IE_SHIFT)) & CTU_IR_T4_IE_MASK)

#define CTU_IR_T5_IE_MASK                        (0x2000U)
#define CTU_IR_T5_IE_SHIFT                       (13U)
#define CTU_IR_T5_IE_WIDTH                       (1U)
#define CTU_IR_T5_IE(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_IR_T5_IE_SHIFT)) & CTU_IR_T5_IE_MASK)

#define CTU_IR_T6_IE_MASK                        (0x4000U)
#define CTU_IR_T6_IE_SHIFT                       (14U)
#define CTU_IR_T6_IE_WIDTH                       (1U)
#define CTU_IR_T6_IE(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_IR_T6_IE_SHIFT)) & CTU_IR_T6_IE_MASK)

#define CTU_IR_T7_IE_MASK                        (0x8000U)
#define CTU_IR_T7_IE_SHIFT                       (15U)
#define CTU_IR_T7_IE_WIDTH                       (1U)
#define CTU_IR_T7_IE(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_IR_T7_IE_SHIFT)) & CTU_IR_T7_IE_MASK)
/*! @} */

/*! @name COTR - Control ON Time Register */
/*! @{ */

#define CTU_COTR_COTGT_MASK                      (0xFFU)
#define CTU_COTR_COTGT_SHIFT                     (0U)
#define CTU_COTR_COTGT_WIDTH                     (8U)
#define CTU_COTR_COTGT(x)                        (((uint16_t)(((uint16_t)(x)) << CTU_COTR_COTGT_SHIFT)) & CTU_COTR_COTGT_MASK)
/*! @} */

/*! @name CR - Control Register */
/*! @{ */

#define CTU_CR_TGSISR_RE_MASK                    (0x1U)
#define CTU_CR_TGSISR_RE_SHIFT                   (0U)
#define CTU_CR_TGSISR_RE_WIDTH                   (1U)
#define CTU_CR_TGSISR_RE(x)                      (((uint16_t)(((uint16_t)(x)) << CTU_CR_TGSISR_RE_SHIFT)) & CTU_CR_TGSISR_RE_MASK)

#define CTU_CR_GRE_MASK                          (0x2U)
#define CTU_CR_GRE_SHIFT                         (1U)
#define CTU_CR_GRE_WIDTH                         (1U)
#define CTU_CR_GRE(x)                            (((uint16_t)(((uint16_t)(x)) << CTU_CR_GRE_SHIFT)) & CTU_CR_GRE_MASK)

#define CTU_CR_MRS_SG_MASK                       (0x4U)
#define CTU_CR_MRS_SG_SHIFT                      (2U)
#define CTU_CR_MRS_SG_WIDTH                      (1U)
#define CTU_CR_MRS_SG(x)                         (((uint16_t)(((uint16_t)(x)) << CTU_CR_MRS_SG_SHIFT)) & CTU_CR_MRS_SG_MASK)

#define CTU_CR_FGRE_MASK                         (0x8U)
#define CTU_CR_FGRE_SHIFT                        (3U)
#define CTU_CR_FGRE_WIDTH                        (1U)
#define CTU_CR_FGRE(x)                           (((uint16_t)(((uint16_t)(x)) << CTU_CR_FGRE_SHIFT)) & CTU_CR_FGRE_MASK)

#define CTU_CR_CGRE_MASK                         (0x10U)
#define CTU_CR_CGRE_SHIFT                        (4U)
#define CTU_CR_CGRE_WIDTH                        (1U)
#define CTU_CR_CGRE(x)                           (((uint16_t)(((uint16_t)(x)) << CTU_CR_CGRE_SHIFT)) & CTU_CR_CGRE_MASK)

#define CTU_CR_DFE_MASK                          (0x20U)
#define CTU_CR_DFE_SHIFT                         (5U)
#define CTU_CR_DFE_WIDTH                         (1U)
#define CTU_CR_DFE(x)                            (((uint16_t)(((uint16_t)(x)) << CTU_CR_DFE_SHIFT)) & CTU_CR_DFE_MASK)

#define CTU_CR_CTU_ODIS_MASK                     (0x40U)
#define CTU_CR_CTU_ODIS_SHIFT                    (6U)
#define CTU_CR_CTU_ODIS_WIDTH                    (1U)
#define CTU_CR_CTU_ODIS(x)                       (((uint16_t)(((uint16_t)(x)) << CTU_CR_CTU_ODIS_SHIFT)) & CTU_CR_CTU_ODIS_MASK)

#define CTU_CR_CTU_ADC_R_MASK                    (0x80U)
#define CTU_CR_CTU_ADC_R_SHIFT                   (7U)
#define CTU_CR_CTU_ADC_R_WIDTH                   (1U)
#define CTU_CR_CTU_ADC_R(x)                      (((uint16_t)(((uint16_t)(x)) << CTU_CR_CTU_ADC_R_SHIFT)) & CTU_CR_CTU_ADC_R_MASK)

#define CTU_CR_T0_SG_MASK                        (0x100U)
#define CTU_CR_T0_SG_SHIFT                       (8U)
#define CTU_CR_T0_SG_WIDTH                       (1U)
#define CTU_CR_T0_SG(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_CR_T0_SG_SHIFT)) & CTU_CR_T0_SG_MASK)

#define CTU_CR_T1_SG_MASK                        (0x200U)
#define CTU_CR_T1_SG_SHIFT                       (9U)
#define CTU_CR_T1_SG_WIDTH                       (1U)
#define CTU_CR_T1_SG(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_CR_T1_SG_SHIFT)) & CTU_CR_T1_SG_MASK)

#define CTU_CR_T2_SG_MASK                        (0x400U)
#define CTU_CR_T2_SG_SHIFT                       (10U)
#define CTU_CR_T2_SG_WIDTH                       (1U)
#define CTU_CR_T2_SG(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_CR_T2_SG_SHIFT)) & CTU_CR_T2_SG_MASK)

#define CTU_CR_T3_SG_MASK                        (0x800U)
#define CTU_CR_T3_SG_SHIFT                       (11U)
#define CTU_CR_T3_SG_WIDTH                       (1U)
#define CTU_CR_T3_SG(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_CR_T3_SG_SHIFT)) & CTU_CR_T3_SG_MASK)

#define CTU_CR_T4_SG_MASK                        (0x1000U)
#define CTU_CR_T4_SG_SHIFT                       (12U)
#define CTU_CR_T4_SG_WIDTH                       (1U)
#define CTU_CR_T4_SG(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_CR_T4_SG_SHIFT)) & CTU_CR_T4_SG_MASK)

#define CTU_CR_T5_SG_MASK                        (0x2000U)
#define CTU_CR_T5_SG_SHIFT                       (13U)
#define CTU_CR_T5_SG_WIDTH                       (1U)
#define CTU_CR_T5_SG(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_CR_T5_SG_SHIFT)) & CTU_CR_T5_SG_MASK)

#define CTU_CR_T6_SG_MASK                        (0x4000U)
#define CTU_CR_T6_SG_SHIFT                       (14U)
#define CTU_CR_T6_SG_WIDTH                       (1U)
#define CTU_CR_T6_SG(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_CR_T6_SG_SHIFT)) & CTU_CR_T6_SG_MASK)

#define CTU_CR_T7_SG_MASK                        (0x8000U)
#define CTU_CR_T7_SG_SHIFT                       (15U)
#define CTU_CR_T7_SG_WIDTH                       (1U)
#define CTU_CR_T7_SG(x)                          (((uint16_t)(((uint16_t)(x)) << CTU_CR_T7_SG_SHIFT)) & CTU_CR_T7_SG_MASK)
/*! @} */

/*! @name DFR - Digital Filter Register */
/*! @{ */

#define CTU_DFR_FILTER_N_MASK                    (0xFFU)
#define CTU_DFR_FILTER_N_SHIFT                   (0U)
#define CTU_DFR_FILTER_N_WIDTH                   (8U)
#define CTU_DFR_FILTER_N(x)                      (((uint16_t)(((uint16_t)(x)) << CTU_DFR_FILTER_N_SHIFT)) & CTU_DFR_FILTER_N_MASK)
/*! @} */

/*! @name EXPAR - Expected Value A Register */
/*! @{ */

#define CTU_EXPAR_EXPA_MASK                      (0xFFFFU)
#define CTU_EXPAR_EXPA_SHIFT                     (0U)
#define CTU_EXPAR_EXPA_WIDTH                     (16U)
#define CTU_EXPAR_EXPA(x)                        (((uint16_t)(((uint16_t)(x)) << CTU_EXPAR_EXPA_SHIFT)) & CTU_EXPAR_EXPA_MASK)
/*! @} */

/*! @name EXPBR - Expected Value B Register */
/*! @{ */

#define CTU_EXPBR_EXPB_MASK                      (0xFFFFU)
#define CTU_EXPBR_EXPB_SHIFT                     (0U)
#define CTU_EXPBR_EXPB_WIDTH                     (16U)
#define CTU_EXPBR_EXPB(x)                        (((uint16_t)(((uint16_t)(x)) << CTU_EXPBR_EXPB_SHIFT)) & CTU_EXPBR_EXPB_MASK)
/*! @} */

/*! @name CNTRNGR - Counter Range Register */
/*! @{ */

#define CTU_CNTRNGR_CNTRNG_MASK                  (0xFFU)
#define CTU_CNTRNGR_CNTRNG_SHIFT                 (0U)
#define CTU_CNTRNGR_CNTRNG_WIDTH                 (8U)
#define CTU_CNTRNGR_CNTRNG(x)                    (((uint16_t)(((uint16_t)(x)) << CTU_CNTRNGR_CNTRNG_SHIFT)) & CTU_CNTRNGR_CNTRNG_MASK)
/*! @} */

/*! @name LISTCSR - List Control/Status Register */
/*! @{ */

#define CTU_LISTCSR_PAR_LIST_MASK                (0x1U)
#define CTU_LISTCSR_PAR_LIST_SHIFT               (0U)
#define CTU_LISTCSR_PAR_LIST_WIDTH               (1U)
#define CTU_LISTCSR_PAR_LIST(x)                  (((uint32_t)(((uint32_t)(x)) << CTU_LISTCSR_PAR_LIST_SHIFT)) & CTU_LISTCSR_PAR_LIST_MASK)

#define CTU_LISTCSR_LIST0_ADDR_MASK              (0x1F0000U)
#define CTU_LISTCSR_LIST0_ADDR_SHIFT             (16U)
#define CTU_LISTCSR_LIST0_ADDR_WIDTH             (5U)
#define CTU_LISTCSR_LIST0_ADDR(x)                (((uint32_t)(((uint32_t)(x)) << CTU_LISTCSR_LIST0_ADDR_SHIFT)) & CTU_LISTCSR_LIST0_ADDR_MASK)

#define CTU_LISTCSR_LIST0_BLK_MASK               (0x800000U)
#define CTU_LISTCSR_LIST0_BLK_SHIFT              (23U)
#define CTU_LISTCSR_LIST0_BLK_WIDTH              (1U)
#define CTU_LISTCSR_LIST0_BLK(x)                 (((uint32_t)(((uint32_t)(x)) << CTU_LISTCSR_LIST0_BLK_SHIFT)) & CTU_LISTCSR_LIST0_BLK_MASK)

#define CTU_LISTCSR_LIST1_ADDR_MASK              (0x1F000000U)
#define CTU_LISTCSR_LIST1_ADDR_SHIFT             (24U)
#define CTU_LISTCSR_LIST1_ADDR_WIDTH             (5U)
#define CTU_LISTCSR_LIST1_ADDR(x)                (((uint32_t)(((uint32_t)(x)) << CTU_LISTCSR_LIST1_ADDR_SHIFT)) & CTU_LISTCSR_LIST1_ADDR_MASK)

#define CTU_LISTCSR_LIST1_BLK_MASK               (0x80000000U)
#define CTU_LISTCSR_LIST1_BLK_SHIFT              (31U)
#define CTU_LISTCSR_LIST1_BLK_WIDTH              (1U)
#define CTU_LISTCSR_LIST1_BLK(x)                 (((uint32_t)(((uint32_t)(x)) << CTU_LISTCSR_LIST1_BLK_SHIFT)) & CTU_LISTCSR_LIST1_BLK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CTU_Register_Masks */

/*!
 * @}
 */ /* end of group CTU_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_CTU_H_) */
