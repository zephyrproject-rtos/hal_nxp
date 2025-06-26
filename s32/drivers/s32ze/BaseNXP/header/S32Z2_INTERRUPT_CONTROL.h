/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_INTERRUPT_CONTROL.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_INTERRUPT_CONTROL
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
#if !defined(S32Z2_INTERRUPT_CONTROL_H_)  /* Check if memory map has not been already included */
#define S32Z2_INTERRUPT_CONTROL_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- INTERRUPT_CONTROL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INTERRUPT_CONTROL_Peripheral_Access_Layer INTERRUPT_CONTROL Peripheral Access Layer
 * @{
 */

/** INTERRUPT_CONTROL - Size of Registers Arrays */
#define INTERRUPT_CONTROL_ISRX_COUNT              1u
#define INTERRUPT_CONTROL_ICRX_COUNT              1u
#define INTERRUPT_CONTROL_IGRX_COUNT              1u
#define INTERRUPT_CONTROL_IVAX_COUNT              6u
#define INTERRUPT_CONTROL_ICFGX_COUNT             23u

/** INTERRUPT_CONTROL - Register Layout Typedef */
typedef struct {
  __I  uint32_t ISRX[INTERRUPT_CONTROL_ISRX_COUNT]; /**< Interrupt Status Register, array offset: 0x0, array step: 0x4 */
  uint8_t RESERVED_0[28];
  __IO uint32_t ICRX[INTERRUPT_CONTROL_ICRX_COUNT]; /**< Interrupt Clear Register, array offset: 0x20, array step: 0x4 */
  uint8_t RESERVED_1[28];
  __IO uint32_t IGRX[INTERRUPT_CONTROL_IGRX_COUNT]; /**< Interrupt Generation Register, array offset: 0x40, array step: 0x4 */
  uint8_t RESERVED_2[28];
  __IO uint32_t IMR0;                              /**< Interrupt Mask Register, offset: 0x60 */
  uint8_t RESERVED_3[124];
  __IO uint32_t IGMR;                              /**< IGM Register, offset: 0xE0 */
  uint8_t RESERVED_4[36];
  __IO uint32_t IVAX[INTERRUPT_CONTROL_IVAX_COUNT]; /**< Interrupt Vector Address, array offset: 0x108, array step: 0x4 */
  uint8_t RESERVED_5[224];
  __IO uint32_t ICFG0;                             /**< ICFG0 Register, offset: 0x200 */
  __IO uint32_t ICFG1;                             /**< ICFG1 Register, offset: 0x204 */
  __IO uint32_t ICFG2;                             /**< ICFG2 Register, offset: 0x208 */
  __IO uint32_t ICFG3;                             /**< ICFG3 Register, offset: 0x20C */
  __IO uint32_t ICFG4;                             /**< ICFG4 Register, offset: 0x210 */
  __IO uint32_t ICFG5;                             /**< ICFG5 Register, offset: 0x214 */
  __IO uint32_t ICFG6;                             /**< ICFG6 Register, offset: 0x218 */
  uint8_t RESERVED_6[4];
  __IO uint32_t ICFG8;                             /**< ICFG8 Register, offset: 0x220 */
  __IO uint32_t ICFGX[INTERRUPT_CONTROL_ICFGX_COUNT]; /**< ICFGx Register, array offset: 0x224, array step: 0x4 */
} INTERRUPT_CONTROL_Type, *INTERRUPT_CONTROL_MemMapPtr;

/** Number of instances of the INTERRUPT_CONTROL module. */
#define INTERRUPT_CONTROL_INSTANCE_COUNT         (1u)

/* INTERRUPT_CONTROL - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2__INTERRUPT_CONTROL base address */
#define IP_CEVA_SPF2__INTERRUPT_CONTROL_BASE     (0x24402100u)
/** Peripheral CEVA_SPF2__INTERRUPT_CONTROL base pointer */
#define IP_CEVA_SPF2__INTERRUPT_CONTROL          ((INTERRUPT_CONTROL_Type *)IP_CEVA_SPF2__INTERRUPT_CONTROL_BASE)
/** Array initializer of INTERRUPT_CONTROL peripheral base addresses */
#define IP_INTERRUPT_CONTROL_BASE_ADDRS          { IP_CEVA_SPF2__INTERRUPT_CONTROL_BASE }
/** Array initializer of INTERRUPT_CONTROL peripheral base pointers */
#define IP_INTERRUPT_CONTROL_BASE_PTRS           { IP_CEVA_SPF2__INTERRUPT_CONTROL }

/* ----------------------------------------------------------------------------
   -- INTERRUPT_CONTROL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INTERRUPT_CONTROL_Register_Masks INTERRUPT_CONTROL Register Masks
 * @{
 */

/*! @name ISRX - Interrupt Status Register */
/*! @{ */

#define INTERRUPT_CONTROL_ISRX_ISR_MASK          (0xFFFFFFFFU)
#define INTERRUPT_CONTROL_ISRX_ISR_SHIFT         (0U)
#define INTERRUPT_CONTROL_ISRX_ISR_WIDTH         (32U)
#define INTERRUPT_CONTROL_ISRX_ISR(x)            (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ISRX_ISR_SHIFT)) & INTERRUPT_CONTROL_ISRX_ISR_MASK)
/*! @} */

/*! @name ICRX - Interrupt Clear Register */
/*! @{ */

#define INTERRUPT_CONTROL_ICRX_ICR_MASK          (0xFFFFFFFFU)
#define INTERRUPT_CONTROL_ICRX_ICR_SHIFT         (0U)
#define INTERRUPT_CONTROL_ICRX_ICR_WIDTH         (32U)
#define INTERRUPT_CONTROL_ICRX_ICR(x)            (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICRX_ICR_SHIFT)) & INTERRUPT_CONTROL_ICRX_ICR_MASK)
/*! @} */

/*! @name IGRX - Interrupt Generation Register */
/*! @{ */

#define INTERRUPT_CONTROL_IGRX_IGR_MASK          (0xFFFFFFFFU)
#define INTERRUPT_CONTROL_IGRX_IGR_SHIFT         (0U)
#define INTERRUPT_CONTROL_IGRX_IGR_WIDTH         (32U)
#define INTERRUPT_CONTROL_IGRX_IGR(x)            (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_IGRX_IGR_SHIFT)) & INTERRUPT_CONTROL_IGRX_IGR_MASK)
/*! @} */

/*! @name IMR0 - Interrupt Mask Register */
/*! @{ */

#define INTERRUPT_CONTROL_IMR0_IMR_0_MASK        (0x1U)
#define INTERRUPT_CONTROL_IMR0_IMR_0_SHIFT       (0U)
#define INTERRUPT_CONTROL_IMR0_IMR_0_WIDTH       (1U)
#define INTERRUPT_CONTROL_IMR0_IMR_0(x)          (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_IMR0_IMR_0_SHIFT)) & INTERRUPT_CONTROL_IMR0_IMR_0_MASK)

#define INTERRUPT_CONTROL_IMR0_IMR0L_MASK        (0x1EU)
#define INTERRUPT_CONTROL_IMR0_IMR0L_SHIFT       (1U)
#define INTERRUPT_CONTROL_IMR0_IMR0L_WIDTH       (4U)
#define INTERRUPT_CONTROL_IMR0_IMR0L(x)          (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_IMR0_IMR0L_SHIFT)) & INTERRUPT_CONTROL_IMR0_IMR0L_MASK)

#define INTERRUPT_CONTROL_IMR0_IMR0_5_MASK       (0x20U)
#define INTERRUPT_CONTROL_IMR0_IMR0_5_SHIFT      (5U)
#define INTERRUPT_CONTROL_IMR0_IMR0_5_WIDTH      (1U)
#define INTERRUPT_CONTROL_IMR0_IMR0_5(x)         (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_IMR0_IMR0_5_SHIFT)) & INTERRUPT_CONTROL_IMR0_IMR0_5_MASK)

#define INTERRUPT_CONTROL_IMR0_IMR0H_MASK        (0xFFFFFFC0U)
#define INTERRUPT_CONTROL_IMR0_IMR0H_SHIFT       (6U)
#define INTERRUPT_CONTROL_IMR0_IMR0H_WIDTH       (26U)
#define INTERRUPT_CONTROL_IMR0_IMR0H(x)          (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_IMR0_IMR0H_SHIFT)) & INTERRUPT_CONTROL_IMR0_IMR0H_MASK)
/*! @} */

/*! @name IGMR - IGM Register */
/*! @{ */

#define INTERRUPT_CONTROL_IGMR_GM0_MASK          (0x1U)
#define INTERRUPT_CONTROL_IGMR_GM0_SHIFT         (0U)
#define INTERRUPT_CONTROL_IGMR_GM0_WIDTH         (1U)
#define INTERRUPT_CONTROL_IGMR_GM0(x)            (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_IGMR_GM0_SHIFT)) & INTERRUPT_CONTROL_IGMR_GM0_MASK)

#define INTERRUPT_CONTROL_IGMR_CIL_MASK          (0x10000U)
#define INTERRUPT_CONTROL_IGMR_CIL_SHIFT         (16U)
#define INTERRUPT_CONTROL_IGMR_CIL_WIDTH         (1U)
#define INTERRUPT_CONTROL_IGMR_CIL(x)            (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_IGMR_CIL_SHIFT)) & INTERRUPT_CONTROL_IGMR_CIL_MASK)

#define INTERRUPT_CONTROL_IGMR_CILP_MASK         (0x20000U)
#define INTERRUPT_CONTROL_IGMR_CILP_SHIFT        (17U)
#define INTERRUPT_CONTROL_IGMR_CILP_WIDTH        (1U)
#define INTERRUPT_CONTROL_IGMR_CILP(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_IGMR_CILP_SHIFT)) & INTERRUPT_CONTROL_IGMR_CILP_MASK)

#define INTERRUPT_CONTROL_IGMR_ICUE_MASK         (0x80000000U)
#define INTERRUPT_CONTROL_IGMR_ICUE_SHIFT        (31U)
#define INTERRUPT_CONTROL_IGMR_ICUE_WIDTH        (1U)
#define INTERRUPT_CONTROL_IGMR_ICUE(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_IGMR_ICUE_SHIFT)) & INTERRUPT_CONTROL_IGMR_ICUE_MASK)
/*! @} */

/*! @name IVAX - Interrupt Vector Address */
/*! @{ */

#define INTERRUPT_CONTROL_IVAX_IVAX_MASK         (0xFFFFFF00U)
#define INTERRUPT_CONTROL_IVAX_IVAX_SHIFT        (8U)
#define INTERRUPT_CONTROL_IVAX_IVAX_WIDTH        (24U)
#define INTERRUPT_CONTROL_IVAX_IVAX(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_IVAX_IVAX_SHIFT)) & INTERRUPT_CONTROL_IVAX_IVAX_MASK)
/*! @} */

/*! @name ICFG0 - ICFG0 Register */
/*! @{ */

#define INTERRUPT_CONTROL_ICFG0_ISR_MASK         (0x1U)
#define INTERRUPT_CONTROL_ICFG0_ISR_SHIFT        (0U)
#define INTERRUPT_CONTROL_ICFG0_ISR_WIDTH        (1U)
#define INTERRUPT_CONTROL_ICFG0_ISR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG0_ISR_SHIFT)) & INTERRUPT_CONTROL_ICFG0_ISR_MASK)

#define INTERRUPT_CONTROL_ICFG0_IMR_MASK         (0x2U)
#define INTERRUPT_CONTROL_ICFG0_IMR_SHIFT        (1U)
#define INTERRUPT_CONTROL_ICFG0_IMR_WIDTH        (1U)
#define INTERRUPT_CONTROL_ICFG0_IMR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG0_IMR_SHIFT)) & INTERRUPT_CONTROL_ICFG0_IMR_MASK)

#define INTERRUPT_CONTROL_ICFG0_IMOD_MASK        (0xCU)
#define INTERRUPT_CONTROL_ICFG0_IMOD_SHIFT       (2U)
#define INTERRUPT_CONTROL_ICFG0_IMOD_WIDTH       (2U)
#define INTERRUPT_CONTROL_ICFG0_IMOD(x)          (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG0_IMOD_SHIFT)) & INTERRUPT_CONTROL_ICFG0_IMOD_MASK)

#define INTERRUPT_CONTROL_ICFG0_IVI_MASK         (0x1C0U)
#define INTERRUPT_CONTROL_ICFG0_IVI_SHIFT        (6U)
#define INTERRUPT_CONTROL_ICFG0_IVI_WIDTH        (3U)
#define INTERRUPT_CONTROL_ICFG0_IVI(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG0_IVI_SHIFT)) & INTERRUPT_CONTROL_ICFG0_IVI_MASK)

#define INTERRUPT_CONTROL_ICFG0_IPR_MASK         (0x7000U)
#define INTERRUPT_CONTROL_ICFG0_IPR_SHIFT        (12U)
#define INTERRUPT_CONTROL_ICFG0_IPR_WIDTH        (3U)
#define INTERRUPT_CONTROL_ICFG0_IPR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG0_IPR_SHIFT)) & INTERRUPT_CONTROL_ICFG0_IPR_MASK)
/*! @} */

/*! @name ICFG1 - ICFG1 Register */
/*! @{ */

#define INTERRUPT_CONTROL_ICFG1_ISR_MASK         (0x1U)
#define INTERRUPT_CONTROL_ICFG1_ISR_SHIFT        (0U)
#define INTERRUPT_CONTROL_ICFG1_ISR_WIDTH        (1U)
#define INTERRUPT_CONTROL_ICFG1_ISR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG1_ISR_SHIFT)) & INTERRUPT_CONTROL_ICFG1_ISR_MASK)

#define INTERRUPT_CONTROL_ICFG1_IMR_MASK         (0x2U)
#define INTERRUPT_CONTROL_ICFG1_IMR_SHIFT        (1U)
#define INTERRUPT_CONTROL_ICFG1_IMR_WIDTH        (1U)
#define INTERRUPT_CONTROL_ICFG1_IMR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG1_IMR_SHIFT)) & INTERRUPT_CONTROL_ICFG1_IMR_MASK)

#define INTERRUPT_CONTROL_ICFG1_IMOD_MASK        (0xCU)
#define INTERRUPT_CONTROL_ICFG1_IMOD_SHIFT       (2U)
#define INTERRUPT_CONTROL_ICFG1_IMOD_WIDTH       (2U)
#define INTERRUPT_CONTROL_ICFG1_IMOD(x)          (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG1_IMOD_SHIFT)) & INTERRUPT_CONTROL_ICFG1_IMOD_MASK)

#define INTERRUPT_CONTROL_ICFG1_IVI_MASK         (0x1C0U)
#define INTERRUPT_CONTROL_ICFG1_IVI_SHIFT        (6U)
#define INTERRUPT_CONTROL_ICFG1_IVI_WIDTH        (3U)
#define INTERRUPT_CONTROL_ICFG1_IVI(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG1_IVI_SHIFT)) & INTERRUPT_CONTROL_ICFG1_IVI_MASK)

#define INTERRUPT_CONTROL_ICFG1_IPR_MASK         (0x7000U)
#define INTERRUPT_CONTROL_ICFG1_IPR_SHIFT        (12U)
#define INTERRUPT_CONTROL_ICFG1_IPR_WIDTH        (3U)
#define INTERRUPT_CONTROL_ICFG1_IPR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG1_IPR_SHIFT)) & INTERRUPT_CONTROL_ICFG1_IPR_MASK)
/*! @} */

/*! @name ICFG2 - ICFG2 Register */
/*! @{ */

#define INTERRUPT_CONTROL_ICFG2_ISR_MASK         (0x1U)
#define INTERRUPT_CONTROL_ICFG2_ISR_SHIFT        (0U)
#define INTERRUPT_CONTROL_ICFG2_ISR_WIDTH        (1U)
#define INTERRUPT_CONTROL_ICFG2_ISR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG2_ISR_SHIFT)) & INTERRUPT_CONTROL_ICFG2_ISR_MASK)

#define INTERRUPT_CONTROL_ICFG2_IMR_MASK         (0x2U)
#define INTERRUPT_CONTROL_ICFG2_IMR_SHIFT        (1U)
#define INTERRUPT_CONTROL_ICFG2_IMR_WIDTH        (1U)
#define INTERRUPT_CONTROL_ICFG2_IMR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG2_IMR_SHIFT)) & INTERRUPT_CONTROL_ICFG2_IMR_MASK)

#define INTERRUPT_CONTROL_ICFG2_IMOD_MASK        (0xCU)
#define INTERRUPT_CONTROL_ICFG2_IMOD_SHIFT       (2U)
#define INTERRUPT_CONTROL_ICFG2_IMOD_WIDTH       (2U)
#define INTERRUPT_CONTROL_ICFG2_IMOD(x)          (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG2_IMOD_SHIFT)) & INTERRUPT_CONTROL_ICFG2_IMOD_MASK)

#define INTERRUPT_CONTROL_ICFG2_IVI_MASK         (0x1C0U)
#define INTERRUPT_CONTROL_ICFG2_IVI_SHIFT        (6U)
#define INTERRUPT_CONTROL_ICFG2_IVI_WIDTH        (3U)
#define INTERRUPT_CONTROL_ICFG2_IVI(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG2_IVI_SHIFT)) & INTERRUPT_CONTROL_ICFG2_IVI_MASK)

#define INTERRUPT_CONTROL_ICFG2_IPR_MASK         (0x7000U)
#define INTERRUPT_CONTROL_ICFG2_IPR_SHIFT        (12U)
#define INTERRUPT_CONTROL_ICFG2_IPR_WIDTH        (3U)
#define INTERRUPT_CONTROL_ICFG2_IPR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG2_IPR_SHIFT)) & INTERRUPT_CONTROL_ICFG2_IPR_MASK)
/*! @} */

/*! @name ICFG3 - ICFG3 Register */
/*! @{ */

#define INTERRUPT_CONTROL_ICFG3_ISR_MASK         (0x1U)
#define INTERRUPT_CONTROL_ICFG3_ISR_SHIFT        (0U)
#define INTERRUPT_CONTROL_ICFG3_ISR_WIDTH        (1U)
#define INTERRUPT_CONTROL_ICFG3_ISR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG3_ISR_SHIFT)) & INTERRUPT_CONTROL_ICFG3_ISR_MASK)

#define INTERRUPT_CONTROL_ICFG3_IMR_MASK         (0x2U)
#define INTERRUPT_CONTROL_ICFG3_IMR_SHIFT        (1U)
#define INTERRUPT_CONTROL_ICFG3_IMR_WIDTH        (1U)
#define INTERRUPT_CONTROL_ICFG3_IMR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG3_IMR_SHIFT)) & INTERRUPT_CONTROL_ICFG3_IMR_MASK)

#define INTERRUPT_CONTROL_ICFG3_IMOD_MASK        (0xCU)
#define INTERRUPT_CONTROL_ICFG3_IMOD_SHIFT       (2U)
#define INTERRUPT_CONTROL_ICFG3_IMOD_WIDTH       (2U)
#define INTERRUPT_CONTROL_ICFG3_IMOD(x)          (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG3_IMOD_SHIFT)) & INTERRUPT_CONTROL_ICFG3_IMOD_MASK)

#define INTERRUPT_CONTROL_ICFG3_IVI_MASK         (0x1C0U)
#define INTERRUPT_CONTROL_ICFG3_IVI_SHIFT        (6U)
#define INTERRUPT_CONTROL_ICFG3_IVI_WIDTH        (3U)
#define INTERRUPT_CONTROL_ICFG3_IVI(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG3_IVI_SHIFT)) & INTERRUPT_CONTROL_ICFG3_IVI_MASK)

#define INTERRUPT_CONTROL_ICFG3_IPR_MASK         (0x7000U)
#define INTERRUPT_CONTROL_ICFG3_IPR_SHIFT        (12U)
#define INTERRUPT_CONTROL_ICFG3_IPR_WIDTH        (3U)
#define INTERRUPT_CONTROL_ICFG3_IPR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG3_IPR_SHIFT)) & INTERRUPT_CONTROL_ICFG3_IPR_MASK)
/*! @} */

/*! @name ICFG4 - ICFG4 Register */
/*! @{ */

#define INTERRUPT_CONTROL_ICFG4_ISR_MASK         (0x1U)
#define INTERRUPT_CONTROL_ICFG4_ISR_SHIFT        (0U)
#define INTERRUPT_CONTROL_ICFG4_ISR_WIDTH        (1U)
#define INTERRUPT_CONTROL_ICFG4_ISR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG4_ISR_SHIFT)) & INTERRUPT_CONTROL_ICFG4_ISR_MASK)

#define INTERRUPT_CONTROL_ICFG4_IMR_MASK         (0x2U)
#define INTERRUPT_CONTROL_ICFG4_IMR_SHIFT        (1U)
#define INTERRUPT_CONTROL_ICFG4_IMR_WIDTH        (1U)
#define INTERRUPT_CONTROL_ICFG4_IMR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG4_IMR_SHIFT)) & INTERRUPT_CONTROL_ICFG4_IMR_MASK)

#define INTERRUPT_CONTROL_ICFG4_IMOD_MASK        (0xCU)
#define INTERRUPT_CONTROL_ICFG4_IMOD_SHIFT       (2U)
#define INTERRUPT_CONTROL_ICFG4_IMOD_WIDTH       (2U)
#define INTERRUPT_CONTROL_ICFG4_IMOD(x)          (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG4_IMOD_SHIFT)) & INTERRUPT_CONTROL_ICFG4_IMOD_MASK)

#define INTERRUPT_CONTROL_ICFG4_IVI_MASK         (0x1C0U)
#define INTERRUPT_CONTROL_ICFG4_IVI_SHIFT        (6U)
#define INTERRUPT_CONTROL_ICFG4_IVI_WIDTH        (3U)
#define INTERRUPT_CONTROL_ICFG4_IVI(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG4_IVI_SHIFT)) & INTERRUPT_CONTROL_ICFG4_IVI_MASK)

#define INTERRUPT_CONTROL_ICFG4_IPR_MASK         (0x7000U)
#define INTERRUPT_CONTROL_ICFG4_IPR_SHIFT        (12U)
#define INTERRUPT_CONTROL_ICFG4_IPR_WIDTH        (3U)
#define INTERRUPT_CONTROL_ICFG4_IPR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG4_IPR_SHIFT)) & INTERRUPT_CONTROL_ICFG4_IPR_MASK)
/*! @} */

/*! @name ICFG5 - ICFG5 Register */
/*! @{ */

#define INTERRUPT_CONTROL_ICFG5_ISR_MASK         (0x1U)
#define INTERRUPT_CONTROL_ICFG5_ISR_SHIFT        (0U)
#define INTERRUPT_CONTROL_ICFG5_ISR_WIDTH        (1U)
#define INTERRUPT_CONTROL_ICFG5_ISR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG5_ISR_SHIFT)) & INTERRUPT_CONTROL_ICFG5_ISR_MASK)

#define INTERRUPT_CONTROL_ICFG5_IMR_MASK         (0x2U)
#define INTERRUPT_CONTROL_ICFG5_IMR_SHIFT        (1U)
#define INTERRUPT_CONTROL_ICFG5_IMR_WIDTH        (1U)
#define INTERRUPT_CONTROL_ICFG5_IMR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG5_IMR_SHIFT)) & INTERRUPT_CONTROL_ICFG5_IMR_MASK)

#define INTERRUPT_CONTROL_ICFG5_IMOD_MASK        (0xCU)
#define INTERRUPT_CONTROL_ICFG5_IMOD_SHIFT       (2U)
#define INTERRUPT_CONTROL_ICFG5_IMOD_WIDTH       (2U)
#define INTERRUPT_CONTROL_ICFG5_IMOD(x)          (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG5_IMOD_SHIFT)) & INTERRUPT_CONTROL_ICFG5_IMOD_MASK)

#define INTERRUPT_CONTROL_ICFG5_IVI_MASK         (0x1C0U)
#define INTERRUPT_CONTROL_ICFG5_IVI_SHIFT        (6U)
#define INTERRUPT_CONTROL_ICFG5_IVI_WIDTH        (3U)
#define INTERRUPT_CONTROL_ICFG5_IVI(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG5_IVI_SHIFT)) & INTERRUPT_CONTROL_ICFG5_IVI_MASK)

#define INTERRUPT_CONTROL_ICFG5_IPR_MASK         (0x7000U)
#define INTERRUPT_CONTROL_ICFG5_IPR_SHIFT        (12U)
#define INTERRUPT_CONTROL_ICFG5_IPR_WIDTH        (3U)
#define INTERRUPT_CONTROL_ICFG5_IPR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG5_IPR_SHIFT)) & INTERRUPT_CONTROL_ICFG5_IPR_MASK)
/*! @} */

/*! @name ICFG6 - ICFG6 Register */
/*! @{ */

#define INTERRUPT_CONTROL_ICFG6_ISR_MASK         (0x1U)
#define INTERRUPT_CONTROL_ICFG6_ISR_SHIFT        (0U)
#define INTERRUPT_CONTROL_ICFG6_ISR_WIDTH        (1U)
#define INTERRUPT_CONTROL_ICFG6_ISR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG6_ISR_SHIFT)) & INTERRUPT_CONTROL_ICFG6_ISR_MASK)

#define INTERRUPT_CONTROL_ICFG6_IMR_MASK         (0x2U)
#define INTERRUPT_CONTROL_ICFG6_IMR_SHIFT        (1U)
#define INTERRUPT_CONTROL_ICFG6_IMR_WIDTH        (1U)
#define INTERRUPT_CONTROL_ICFG6_IMR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG6_IMR_SHIFT)) & INTERRUPT_CONTROL_ICFG6_IMR_MASK)

#define INTERRUPT_CONTROL_ICFG6_IMOD_MASK        (0xCU)
#define INTERRUPT_CONTROL_ICFG6_IMOD_SHIFT       (2U)
#define INTERRUPT_CONTROL_ICFG6_IMOD_WIDTH       (2U)
#define INTERRUPT_CONTROL_ICFG6_IMOD(x)          (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG6_IMOD_SHIFT)) & INTERRUPT_CONTROL_ICFG6_IMOD_MASK)

#define INTERRUPT_CONTROL_ICFG6_IVI_MASK         (0x1C0U)
#define INTERRUPT_CONTROL_ICFG6_IVI_SHIFT        (6U)
#define INTERRUPT_CONTROL_ICFG6_IVI_WIDTH        (3U)
#define INTERRUPT_CONTROL_ICFG6_IVI(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG6_IVI_SHIFT)) & INTERRUPT_CONTROL_ICFG6_IVI_MASK)

#define INTERRUPT_CONTROL_ICFG6_IPR_MASK         (0x7000U)
#define INTERRUPT_CONTROL_ICFG6_IPR_SHIFT        (12U)
#define INTERRUPT_CONTROL_ICFG6_IPR_WIDTH        (3U)
#define INTERRUPT_CONTROL_ICFG6_IPR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG6_IPR_SHIFT)) & INTERRUPT_CONTROL_ICFG6_IPR_MASK)
/*! @} */

/*! @name ICFG8 - ICFG8 Register */
/*! @{ */

#define INTERRUPT_CONTROL_ICFG8_ISR_MASK         (0x1U)
#define INTERRUPT_CONTROL_ICFG8_ISR_SHIFT        (0U)
#define INTERRUPT_CONTROL_ICFG8_ISR_WIDTH        (1U)
#define INTERRUPT_CONTROL_ICFG8_ISR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG8_ISR_SHIFT)) & INTERRUPT_CONTROL_ICFG8_ISR_MASK)

#define INTERRUPT_CONTROL_ICFG8_IMR_MASK         (0x2U)
#define INTERRUPT_CONTROL_ICFG8_IMR_SHIFT        (1U)
#define INTERRUPT_CONTROL_ICFG8_IMR_WIDTH        (1U)
#define INTERRUPT_CONTROL_ICFG8_IMR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG8_IMR_SHIFT)) & INTERRUPT_CONTROL_ICFG8_IMR_MASK)

#define INTERRUPT_CONTROL_ICFG8_IMOD_MASK        (0xCU)
#define INTERRUPT_CONTROL_ICFG8_IMOD_SHIFT       (2U)
#define INTERRUPT_CONTROL_ICFG8_IMOD_WIDTH       (2U)
#define INTERRUPT_CONTROL_ICFG8_IMOD(x)          (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG8_IMOD_SHIFT)) & INTERRUPT_CONTROL_ICFG8_IMOD_MASK)

#define INTERRUPT_CONTROL_ICFG8_IVI_MASK         (0x1C0U)
#define INTERRUPT_CONTROL_ICFG8_IVI_SHIFT        (6U)
#define INTERRUPT_CONTROL_ICFG8_IVI_WIDTH        (3U)
#define INTERRUPT_CONTROL_ICFG8_IVI(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG8_IVI_SHIFT)) & INTERRUPT_CONTROL_ICFG8_IVI_MASK)

#define INTERRUPT_CONTROL_ICFG8_IPR_MASK         (0x7000U)
#define INTERRUPT_CONTROL_ICFG8_IPR_SHIFT        (12U)
#define INTERRUPT_CONTROL_ICFG8_IPR_WIDTH        (3U)
#define INTERRUPT_CONTROL_ICFG8_IPR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFG8_IPR_SHIFT)) & INTERRUPT_CONTROL_ICFG8_IPR_MASK)
/*! @} */

/*! @name ICFGX - ICFGx Register */
/*! @{ */

#define INTERRUPT_CONTROL_ICFGX_ISR_MASK         (0x1U)
#define INTERRUPT_CONTROL_ICFGX_ISR_SHIFT        (0U)
#define INTERRUPT_CONTROL_ICFGX_ISR_WIDTH        (1U)
#define INTERRUPT_CONTROL_ICFGX_ISR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFGX_ISR_SHIFT)) & INTERRUPT_CONTROL_ICFGX_ISR_MASK)

#define INTERRUPT_CONTROL_ICFGX_IMR_MASK         (0x2U)
#define INTERRUPT_CONTROL_ICFGX_IMR_SHIFT        (1U)
#define INTERRUPT_CONTROL_ICFGX_IMR_WIDTH        (1U)
#define INTERRUPT_CONTROL_ICFGX_IMR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFGX_IMR_SHIFT)) & INTERRUPT_CONTROL_ICFGX_IMR_MASK)

#define INTERRUPT_CONTROL_ICFGX_IMOD_MASK        (0xCU)
#define INTERRUPT_CONTROL_ICFGX_IMOD_SHIFT       (2U)
#define INTERRUPT_CONTROL_ICFGX_IMOD_WIDTH       (2U)
#define INTERRUPT_CONTROL_ICFGX_IMOD(x)          (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFGX_IMOD_SHIFT)) & INTERRUPT_CONTROL_ICFGX_IMOD_MASK)

#define INTERRUPT_CONTROL_ICFGX_IVI_MASK         (0x1C0U)
#define INTERRUPT_CONTROL_ICFGX_IVI_SHIFT        (6U)
#define INTERRUPT_CONTROL_ICFGX_IVI_WIDTH        (3U)
#define INTERRUPT_CONTROL_ICFGX_IVI(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFGX_IVI_SHIFT)) & INTERRUPT_CONTROL_ICFGX_IVI_MASK)

#define INTERRUPT_CONTROL_ICFGX_IPR_MASK         (0x7000U)
#define INTERRUPT_CONTROL_ICFGX_IPR_SHIFT        (12U)
#define INTERRUPT_CONTROL_ICFGX_IPR_WIDTH        (3U)
#define INTERRUPT_CONTROL_ICFGX_IPR(x)           (((uint32_t)(((uint32_t)(x)) << INTERRUPT_CONTROL_ICFGX_IPR_SHIFT)) & INTERRUPT_CONTROL_ICFGX_IPR_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group INTERRUPT_CONTROL_Register_Masks */

/*!
 * @}
 */ /* end of group INTERRUPT_CONTROL_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_INTERRUPT_CONTROL_H_) */
