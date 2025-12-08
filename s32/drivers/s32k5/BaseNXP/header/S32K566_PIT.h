/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_PIT.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_PIT
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
#if !defined(S32K566_PIT_H_)  /* Check if memory map has not been already included */
#define S32K566_PIT_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- PIT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Peripheral_Access_Layer PIT Peripheral Access Layer
 * @{
 */

/** PIT - Size of Registers Arrays */
#define PIT_TIMER_COUNT                           4u

/** PIT - Register Layout Typedef */
typedef struct PIT_Struct {
  __IO uint32_t MCR;                               /**< PIT Module Control, offset: 0x0 */
  uint8_t RESERVED_0[220];
  __I  uint32_t LTMR64H;                           /**< PIT Upper Lifetimer, offset: 0xE0, available only on: LPE_PIT_RTI (missing on CPE_PIT_0, CPE_PIT_1, PIT_0, PIT_1, PIT_2, PIT_3) */
  __I  uint32_t LTMR64L;                           /**< PIT Lower Lifetimer, offset: 0xE4, available only on: LPE_PIT_RTI (missing on CPE_PIT_0, CPE_PIT_1, PIT_0, PIT_1, PIT_2, PIT_3) */
  uint8_t RESERVED_1[4];
  __IO uint32_t RTI_LDVAL_STAT;                    /**< RTI Timer Load Value Sync Status, offset: 0xEC, available only on: LPE_PIT_RTI (missing on CPE_PIT_0, CPE_PIT_1, PIT_0, PIT_1, PIT_2, PIT_3) */
  __IO uint32_t RTI_LDVAL;                         /**< RTI Timer Load Value, offset: 0xF0, available only on: LPE_PIT_RTI (missing on CPE_PIT_0, CPE_PIT_1, PIT_0, PIT_1, PIT_2, PIT_3) */
  __I  uint32_t RTI_CVAL;                          /**< Current RTI Timer Value, offset: 0xF4, available only on: LPE_PIT_RTI (missing on CPE_PIT_0, CPE_PIT_1, PIT_0, PIT_1, PIT_2, PIT_3) */
  __IO uint32_t RTI_TCTRL;                         /**< RTI Timer Control, offset: 0xF8, available only on: LPE_PIT_RTI (missing on CPE_PIT_0, CPE_PIT_1, PIT_0, PIT_1, PIT_2, PIT_3) */
  __IO uint32_t RTI_TFLG;                          /**< RTI Timer Interrupt Flag, offset: 0xFC, available only on: LPE_PIT_RTI (missing on CPE_PIT_0, CPE_PIT_1, PIT_0, PIT_1, PIT_2, PIT_3) */
  struct PIT_TIMER {                               /* offset: 0x100, array step: 0x10 */
    __IO uint32_t LDVAL;                             /**< Timer Load Value, array offset: 0x100, array step: 0x10 */
    __I  uint32_t CVAL;                              /**< Current Timer Value, array offset: 0x104, array step: 0x10 */
    __IO uint32_t TCTRL;                             /**< Timer Control, array offset: 0x108, array step: 0x10 */
    __IO uint32_t TFLG;                              /**< Timer Flag, array offset: 0x10C, array step: 0x10 */
  } TIMER[PIT_TIMER_COUNT];
} PIT_Type, *PIT_MemMapPtr;

/** Number of instances of the PIT module. */
#define PIT_INSTANCE_COUNT                       (7u)

/* PIT - Peripheral instance base addresses */
/** Peripheral CPE_PIT_0 base address */
#define IP_CPE_PIT_0_BASE                        (0x410A0000u)
/** Peripheral CPE_PIT_0 base pointer */
#define IP_CPE_PIT_0                             ((PIT_Type *)IP_CPE_PIT_0_BASE)
/** Peripheral CPE_PIT_1 base address */
#define IP_CPE_PIT_1_BASE                        (0x41150000u)
/** Peripheral CPE_PIT_1 base pointer */
#define IP_CPE_PIT_1                             ((PIT_Type *)IP_CPE_PIT_1_BASE)
/** Peripheral LPE_PIT_RTI base address */
#define IP_LPE_PIT_RTI_BASE                      (0x42160000u)
/** Peripheral LPE_PIT_RTI base pointer */
#define IP_LPE_PIT_RTI                           ((PIT_Type *)IP_LPE_PIT_RTI_BASE)
/** Peripheral PIT_0 base address */
#define IP_PIT_0_BASE                            (0x405A0000u)
/** Peripheral PIT_0 base pointer */
#define IP_PIT_0                                 ((PIT_Type *)IP_PIT_0_BASE)
/** Peripheral PIT_1 base address */
#define IP_PIT_1_BASE                            (0x40B8C000u)
/** Peripheral PIT_1 base pointer */
#define IP_PIT_1                                 ((PIT_Type *)IP_PIT_1_BASE)
/** Peripheral PIT_2 base address */
#define IP_PIT_2_BASE                            (0x40B90000u)
/** Peripheral PIT_2 base pointer */
#define IP_PIT_2                                 ((PIT_Type *)IP_PIT_2_BASE)
/** Peripheral PIT_3 base address */
#define IP_PIT_3_BASE                            (0x40B94000u)
/** Peripheral PIT_3 base pointer */
#define IP_PIT_3                                 ((PIT_Type *)IP_PIT_3_BASE)
/** Array initializer of PIT peripheral base addresses */
#define IP_PIT_BASE_ADDRS                        { IP_CPE_PIT_0_BASE, IP_CPE_PIT_1_BASE, IP_LPE_PIT_RTI_BASE, IP_PIT_0_BASE, IP_PIT_1_BASE, IP_PIT_2_BASE, IP_PIT_3_BASE }
/** Array initializer of PIT peripheral base pointers */
#define IP_PIT_BASE_PTRS                         { IP_CPE_PIT_0, IP_CPE_PIT_1, IP_LPE_PIT_RTI, IP_PIT_0, IP_PIT_1, IP_PIT_2, IP_PIT_3 }

/* ----------------------------------------------------------------------------
   -- PIT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Register_Masks PIT Register Masks
 * @{
 */

/*! @name MCR - PIT Module Control */
/*! @{ */

#define PIT_MCR_FRZ_MASK                         (0x1U)
#define PIT_MCR_FRZ_SHIFT                        (0U)
#define PIT_MCR_FRZ_WIDTH                        (1U)
#define PIT_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x)) << PIT_MCR_FRZ_SHIFT)) & PIT_MCR_FRZ_MASK)

#define PIT_MCR_MDIS_MASK                        (0x2U)
#define PIT_MCR_MDIS_SHIFT                       (1U)
#define PIT_MCR_MDIS_WIDTH                       (1U)
#define PIT_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x)) << PIT_MCR_MDIS_SHIFT)) & PIT_MCR_MDIS_MASK)

#define PIT_MCR_MDIS_RTI_MASK                    (0x4U)
#define PIT_MCR_MDIS_RTI_SHIFT                   (2U)
#define PIT_MCR_MDIS_RTI_WIDTH                   (1U)
#define PIT_MCR_MDIS_RTI(x)                      (((uint32_t)(((uint32_t)(x)) << PIT_MCR_MDIS_RTI_SHIFT)) & PIT_MCR_MDIS_RTI_MASK)
/*! @} */

/*! @name LTMR64H - PIT Upper Lifetimer */
/*! @{ */

#define PIT_LTMR64H_LTH_MASK                     (0xFFFFFFFFU)
#define PIT_LTMR64H_LTH_SHIFT                    (0U)
#define PIT_LTMR64H_LTH_WIDTH                    (32U)
#define PIT_LTMR64H_LTH(x)                       (((uint32_t)(((uint32_t)(x)) << PIT_LTMR64H_LTH_SHIFT)) & PIT_LTMR64H_LTH_MASK)
/*! @} */

/*! @name LTMR64L - PIT Lower Lifetimer */
/*! @{ */

#define PIT_LTMR64L_LTL_MASK                     (0xFFFFFFFFU)
#define PIT_LTMR64L_LTL_SHIFT                    (0U)
#define PIT_LTMR64L_LTL_WIDTH                    (32U)
#define PIT_LTMR64L_LTL(x)                       (((uint32_t)(((uint32_t)(x)) << PIT_LTMR64L_LTL_SHIFT)) & PIT_LTMR64L_LTL_MASK)
/*! @} */

/*! @name RTI_LDVAL_STAT - RTI Timer Load Value Sync Status */
/*! @{ */

#define PIT_RTI_LDVAL_STAT_RT_STAT_MASK          (0x1U)
#define PIT_RTI_LDVAL_STAT_RT_STAT_SHIFT         (0U)
#define PIT_RTI_LDVAL_STAT_RT_STAT_WIDTH         (1U)
#define PIT_RTI_LDVAL_STAT_RT_STAT(x)            (((uint32_t)(((uint32_t)(x)) << PIT_RTI_LDVAL_STAT_RT_STAT_SHIFT)) & PIT_RTI_LDVAL_STAT_RT_STAT_MASK)
/*! @} */

/*! @name RTI_LDVAL - RTI Timer Load Value */
/*! @{ */

#define PIT_RTI_LDVAL_TSV_MASK                   (0xFFFFFFFFU)
#define PIT_RTI_LDVAL_TSV_SHIFT                  (0U)
#define PIT_RTI_LDVAL_TSV_WIDTH                  (32U)
#define PIT_RTI_LDVAL_TSV(x)                     (((uint32_t)(((uint32_t)(x)) << PIT_RTI_LDVAL_TSV_SHIFT)) & PIT_RTI_LDVAL_TSV_MASK)
/*! @} */

/*! @name RTI_CVAL - Current RTI Timer Value */
/*! @{ */

#define PIT_RTI_CVAL_TVL_MASK                    (0xFFFFFFFFU)
#define PIT_RTI_CVAL_TVL_SHIFT                   (0U)
#define PIT_RTI_CVAL_TVL_WIDTH                   (32U)
#define PIT_RTI_CVAL_TVL(x)                      (((uint32_t)(((uint32_t)(x)) << PIT_RTI_CVAL_TVL_SHIFT)) & PIT_RTI_CVAL_TVL_MASK)
/*! @} */

/*! @name RTI_TCTRL - RTI Timer Control */
/*! @{ */

#define PIT_RTI_TCTRL_TEN_MASK                   (0x1U)
#define PIT_RTI_TCTRL_TEN_SHIFT                  (0U)
#define PIT_RTI_TCTRL_TEN_WIDTH                  (1U)
#define PIT_RTI_TCTRL_TEN(x)                     (((uint32_t)(((uint32_t)(x)) << PIT_RTI_TCTRL_TEN_SHIFT)) & PIT_RTI_TCTRL_TEN_MASK)

#define PIT_RTI_TCTRL_TIE_MASK                   (0x2U)
#define PIT_RTI_TCTRL_TIE_SHIFT                  (1U)
#define PIT_RTI_TCTRL_TIE_WIDTH                  (1U)
#define PIT_RTI_TCTRL_TIE(x)                     (((uint32_t)(((uint32_t)(x)) << PIT_RTI_TCTRL_TIE_SHIFT)) & PIT_RTI_TCTRL_TIE_MASK)
/*! @} */

/*! @name RTI_TFLG - RTI Timer Interrupt Flag */
/*! @{ */

#define PIT_RTI_TFLG_TIF_MASK                    (0x1U)
#define PIT_RTI_TFLG_TIF_SHIFT                   (0U)
#define PIT_RTI_TFLG_TIF_WIDTH                   (1U)
#define PIT_RTI_TFLG_TIF(x)                      (((uint32_t)(((uint32_t)(x)) << PIT_RTI_TFLG_TIF_SHIFT)) & PIT_RTI_TFLG_TIF_MASK)
/*! @} */

/*! @name LDVAL - Timer Load Value */
/*! @{ */

#define PIT_LDVAL_TSV_MASK                       (0xFFFFFFFFU)
#define PIT_LDVAL_TSV_SHIFT                      (0U)
#define PIT_LDVAL_TSV_WIDTH                      (32U)
#define PIT_LDVAL_TSV(x)                         (((uint32_t)(((uint32_t)(x)) << PIT_LDVAL_TSV_SHIFT)) & PIT_LDVAL_TSV_MASK)
/*! @} */

/*! @name CVAL - Current Timer Value */
/*! @{ */

#define PIT_CVAL_TVL_MASK                        (0xFFFFFFFFU)
#define PIT_CVAL_TVL_SHIFT                       (0U)
#define PIT_CVAL_TVL_WIDTH                       (32U)
#define PIT_CVAL_TVL(x)                          (((uint32_t)(((uint32_t)(x)) << PIT_CVAL_TVL_SHIFT)) & PIT_CVAL_TVL_MASK)
/*! @} */

/*! @name TCTRL - Timer Control */
/*! @{ */

#define PIT_TCTRL_TEN_MASK                       (0x1U)
#define PIT_TCTRL_TEN_SHIFT                      (0U)
#define PIT_TCTRL_TEN_WIDTH                      (1U)
#define PIT_TCTRL_TEN(x)                         (((uint32_t)(((uint32_t)(x)) << PIT_TCTRL_TEN_SHIFT)) & PIT_TCTRL_TEN_MASK)

#define PIT_TCTRL_TIE_MASK                       (0x2U)
#define PIT_TCTRL_TIE_SHIFT                      (1U)
#define PIT_TCTRL_TIE_WIDTH                      (1U)
#define PIT_TCTRL_TIE(x)                         (((uint32_t)(((uint32_t)(x)) << PIT_TCTRL_TIE_SHIFT)) & PIT_TCTRL_TIE_MASK)

#define PIT_TCTRL_CHN_MASK                       (0x4U)
#define PIT_TCTRL_CHN_SHIFT                      (2U)
#define PIT_TCTRL_CHN_WIDTH                      (1U)
#define PIT_TCTRL_CHN(x)                         (((uint32_t)(((uint32_t)(x)) << PIT_TCTRL_CHN_SHIFT)) & PIT_TCTRL_CHN_MASK)
/*! @} */

/*! @name TFLG - Timer Flag */
/*! @{ */

#define PIT_TFLG_TIF_MASK                        (0x1U)
#define PIT_TFLG_TIF_SHIFT                       (0U)
#define PIT_TFLG_TIF_WIDTH                       (1U)
#define PIT_TFLG_TIF(x)                          (((uint32_t)(((uint32_t)(x)) << PIT_TFLG_TIF_SHIFT)) & PIT_TFLG_TIF_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group PIT_Register_Masks */

/*!
 * @}
 */ /* end of group PIT_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_PIT_H_) */
