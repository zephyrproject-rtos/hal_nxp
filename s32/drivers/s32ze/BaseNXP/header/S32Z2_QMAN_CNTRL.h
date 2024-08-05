/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_QMAN_CNTRL.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_QMAN_CNTRL
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
#if !defined(S32Z2_QMAN_CNTRL_H_)  /* Check if memory map has not been already included */
#define S32Z2_QMAN_CNTRL_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- QMAN_CNTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QMAN_CNTRL_Peripheral_Access_Layer QMAN_CNTRL Peripheral Access Layer
 * @{
 */

/** QMAN_CNTRL - Register Layout Typedef */
typedef struct {
  __IO uint32_t QMAN_IDM_CROSS;                    /**< QMAN IDM CROSS, offset: 0x0 */
  __I  uint32_t QMAN_ACTIVE;                       /**< QMAN ACTIVE, offset: 0x4 */
  uint8_t RESERVED_0[12];
  __IO uint32_t QMAN_VI_MASK;                      /**< QMAN VI MASK, offset: 0x14 */
  __IO uint32_t QMAN_IRQ_STATUS;                   /**< QMAN IRQ STATUS, offset: 0x18 */
  __IO uint32_t QMAN_RST;                          /**< QMAN RST, offset: 0x1C */
  uint8_t RESERVED_1[4];
  __IO uint32_t QMAN_QFULL;                        /**< QMAN QFULL, offset: 0x24 */
  __IO uint32_t QMAN_QFULL_MASK;                   /**< QMAN QFULL MASK, offset: 0x28 */
  uint8_t RESERVED_2[4];
  __IO uint32_t QMAN_PAUSE;                        /**< QMAN PAUSE, offset: 0x30 */
} QMAN_CNTRL_Type, *QMAN_CNTRL_MemMapPtr;

/** Number of instances of the QMAN_CNTRL module. */
#define QMAN_CNTRL_INSTANCE_COUNT                (1u)

/* QMAN_CNTRL - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2__QMAN_CNTRL base address */
#define IP_CEVA_SPF2__QMAN_CNTRL_BASE            (0x24401180u)
/** Peripheral CEVA_SPF2__QMAN_CNTRL base pointer */
#define IP_CEVA_SPF2__QMAN_CNTRL                 ((QMAN_CNTRL_Type *)IP_CEVA_SPF2__QMAN_CNTRL_BASE)
/** Array initializer of QMAN_CNTRL peripheral base addresses */
#define IP_QMAN_CNTRL_BASE_ADDRS                 { IP_CEVA_SPF2__QMAN_CNTRL_BASE }
/** Array initializer of QMAN_CNTRL peripheral base pointers */
#define IP_QMAN_CNTRL_BASE_PTRS                  { IP_CEVA_SPF2__QMAN_CNTRL }

/* ----------------------------------------------------------------------------
   -- QMAN_CNTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QMAN_CNTRL_Register_Masks QMAN_CNTRL Register Masks
 * @{
 */

/*! @name QMAN_IDM_CROSS - QMAN IDM CROSS */
/*! @{ */

#define QMAN_CNTRL_QMAN_IDM_CROSS_Q0_IDM_CROS_MASK (0x1U)
#define QMAN_CNTRL_QMAN_IDM_CROSS_Q0_IDM_CROS_SHIFT (0U)
#define QMAN_CNTRL_QMAN_IDM_CROSS_Q0_IDM_CROS_WIDTH (1U)
#define QMAN_CNTRL_QMAN_IDM_CROSS_Q0_IDM_CROS(x) (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_IDM_CROSS_Q0_IDM_CROS_SHIFT)) & QMAN_CNTRL_QMAN_IDM_CROSS_Q0_IDM_CROS_MASK)

#define QMAN_CNTRL_QMAN_IDM_CROSS_Q1_IDM_CROS_MASK (0x2U)
#define QMAN_CNTRL_QMAN_IDM_CROSS_Q1_IDM_CROS_SHIFT (1U)
#define QMAN_CNTRL_QMAN_IDM_CROSS_Q1_IDM_CROS_WIDTH (1U)
#define QMAN_CNTRL_QMAN_IDM_CROSS_Q1_IDM_CROS(x) (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_IDM_CROSS_Q1_IDM_CROS_SHIFT)) & QMAN_CNTRL_QMAN_IDM_CROSS_Q1_IDM_CROS_MASK)

#define QMAN_CNTRL_QMAN_IDM_CROSS_Q2_IDM_CROS_MASK (0x4U)
#define QMAN_CNTRL_QMAN_IDM_CROSS_Q2_IDM_CROS_SHIFT (2U)
#define QMAN_CNTRL_QMAN_IDM_CROSS_Q2_IDM_CROS_WIDTH (1U)
#define QMAN_CNTRL_QMAN_IDM_CROSS_Q2_IDM_CROS(x) (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_IDM_CROSS_Q2_IDM_CROS_SHIFT)) & QMAN_CNTRL_QMAN_IDM_CROSS_Q2_IDM_CROS_MASK)

#define QMAN_CNTRL_QMAN_IDM_CROSS_Q3_IDM_CROS_MASK (0x8U)
#define QMAN_CNTRL_QMAN_IDM_CROSS_Q3_IDM_CROS_SHIFT (3U)
#define QMAN_CNTRL_QMAN_IDM_CROSS_Q3_IDM_CROS_WIDTH (1U)
#define QMAN_CNTRL_QMAN_IDM_CROSS_Q3_IDM_CROS(x) (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_IDM_CROSS_Q3_IDM_CROS_SHIFT)) & QMAN_CNTRL_QMAN_IDM_CROSS_Q3_IDM_CROS_MASK)
/*! @} */

/*! @name QMAN_ACTIVE - QMAN ACTIVE */
/*! @{ */

#define QMAN_CNTRL_QMAN_ACTIVE_Q0_ACTIVE_MASK    (0x1U)
#define QMAN_CNTRL_QMAN_ACTIVE_Q0_ACTIVE_SHIFT   (0U)
#define QMAN_CNTRL_QMAN_ACTIVE_Q0_ACTIVE_WIDTH   (1U)
#define QMAN_CNTRL_QMAN_ACTIVE_Q0_ACTIVE(x)      (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_ACTIVE_Q0_ACTIVE_SHIFT)) & QMAN_CNTRL_QMAN_ACTIVE_Q0_ACTIVE_MASK)

#define QMAN_CNTRL_QMAN_ACTIVE_Q1_ACTIVE_MASK    (0x2U)
#define QMAN_CNTRL_QMAN_ACTIVE_Q1_ACTIVE_SHIFT   (1U)
#define QMAN_CNTRL_QMAN_ACTIVE_Q1_ACTIVE_WIDTH   (1U)
#define QMAN_CNTRL_QMAN_ACTIVE_Q1_ACTIVE(x)      (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_ACTIVE_Q1_ACTIVE_SHIFT)) & QMAN_CNTRL_QMAN_ACTIVE_Q1_ACTIVE_MASK)

#define QMAN_CNTRL_QMAN_ACTIVE_Q2_ACTIVE_MASK    (0x4U)
#define QMAN_CNTRL_QMAN_ACTIVE_Q2_ACTIVE_SHIFT   (2U)
#define QMAN_CNTRL_QMAN_ACTIVE_Q2_ACTIVE_WIDTH   (1U)
#define QMAN_CNTRL_QMAN_ACTIVE_Q2_ACTIVE(x)      (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_ACTIVE_Q2_ACTIVE_SHIFT)) & QMAN_CNTRL_QMAN_ACTIVE_Q2_ACTIVE_MASK)

#define QMAN_CNTRL_QMAN_ACTIVE_Q3_ACTIVE_MASK    (0x8U)
#define QMAN_CNTRL_QMAN_ACTIVE_Q3_ACTIVE_SHIFT   (3U)
#define QMAN_CNTRL_QMAN_ACTIVE_Q3_ACTIVE_WIDTH   (1U)
#define QMAN_CNTRL_QMAN_ACTIVE_Q3_ACTIVE(x)      (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_ACTIVE_Q3_ACTIVE_SHIFT)) & QMAN_CNTRL_QMAN_ACTIVE_Q3_ACTIVE_MASK)
/*! @} */

/*! @name QMAN_VI_MASK - QMAN VI MASK */
/*! @{ */

#define QMAN_CNTRL_QMAN_VI_MASK_FNUM_VI_MASK_MASK (0x80000000U)
#define QMAN_CNTRL_QMAN_VI_MASK_FNUM_VI_MASK_SHIFT (31U)
#define QMAN_CNTRL_QMAN_VI_MASK_FNUM_VI_MASK_WIDTH (1U)
#define QMAN_CNTRL_QMAN_VI_MASK_FNUM_VI_MASK(x)  (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_VI_MASK_FNUM_VI_MASK_SHIFT)) & QMAN_CNTRL_QMAN_VI_MASK_FNUM_VI_MASK_MASK)
/*! @} */

/*! @name QMAN_IRQ_STATUS - QMAN IRQ STATUS */
/*! @{ */

#define QMAN_CNTRL_QMAN_IRQ_STATUS_Q0_EMPTY_VI_MASK (0x1U)
#define QMAN_CNTRL_QMAN_IRQ_STATUS_Q0_EMPTY_VI_SHIFT (0U)
#define QMAN_CNTRL_QMAN_IRQ_STATUS_Q0_EMPTY_VI_WIDTH (1U)
#define QMAN_CNTRL_QMAN_IRQ_STATUS_Q0_EMPTY_VI(x) (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_IRQ_STATUS_Q0_EMPTY_VI_SHIFT)) & QMAN_CNTRL_QMAN_IRQ_STATUS_Q0_EMPTY_VI_MASK)

#define QMAN_CNTRL_QMAN_IRQ_STATUS_Q1_EMPTY_VI_MASK (0x2U)
#define QMAN_CNTRL_QMAN_IRQ_STATUS_Q1_EMPTY_VI_SHIFT (1U)
#define QMAN_CNTRL_QMAN_IRQ_STATUS_Q1_EMPTY_VI_WIDTH (1U)
#define QMAN_CNTRL_QMAN_IRQ_STATUS_Q1_EMPTY_VI(x) (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_IRQ_STATUS_Q1_EMPTY_VI_SHIFT)) & QMAN_CNTRL_QMAN_IRQ_STATUS_Q1_EMPTY_VI_MASK)

#define QMAN_CNTRL_QMAN_IRQ_STATUS_Q2_EMPTY_VI_MASK (0x4U)
#define QMAN_CNTRL_QMAN_IRQ_STATUS_Q2_EMPTY_VI_SHIFT (2U)
#define QMAN_CNTRL_QMAN_IRQ_STATUS_Q2_EMPTY_VI_WIDTH (1U)
#define QMAN_CNTRL_QMAN_IRQ_STATUS_Q2_EMPTY_VI(x) (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_IRQ_STATUS_Q2_EMPTY_VI_SHIFT)) & QMAN_CNTRL_QMAN_IRQ_STATUS_Q2_EMPTY_VI_MASK)

#define QMAN_CNTRL_QMAN_IRQ_STATUS_Q3_EMPTY_VI_MASK (0x8U)
#define QMAN_CNTRL_QMAN_IRQ_STATUS_Q3_EMPTY_VI_SHIFT (3U)
#define QMAN_CNTRL_QMAN_IRQ_STATUS_Q3_EMPTY_VI_WIDTH (1U)
#define QMAN_CNTRL_QMAN_IRQ_STATUS_Q3_EMPTY_VI(x) (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_IRQ_STATUS_Q3_EMPTY_VI_SHIFT)) & QMAN_CNTRL_QMAN_IRQ_STATUS_Q3_EMPTY_VI_MASK)

#define QMAN_CNTRL_QMAN_IRQ_STATUS_FNUM_VI_MASK  (0x80000000U)
#define QMAN_CNTRL_QMAN_IRQ_STATUS_FNUM_VI_SHIFT (31U)
#define QMAN_CNTRL_QMAN_IRQ_STATUS_FNUM_VI_WIDTH (1U)
#define QMAN_CNTRL_QMAN_IRQ_STATUS_FNUM_VI(x)    (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_IRQ_STATUS_FNUM_VI_SHIFT)) & QMAN_CNTRL_QMAN_IRQ_STATUS_FNUM_VI_MASK)
/*! @} */

/*! @name QMAN_RST - QMAN RST */
/*! @{ */

#define QMAN_CNTRL_QMAN_RST_Q0_RST_MASK          (0x1U)
#define QMAN_CNTRL_QMAN_RST_Q0_RST_SHIFT         (0U)
#define QMAN_CNTRL_QMAN_RST_Q0_RST_WIDTH         (1U)
#define QMAN_CNTRL_QMAN_RST_Q0_RST(x)            (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_RST_Q0_RST_SHIFT)) & QMAN_CNTRL_QMAN_RST_Q0_RST_MASK)

#define QMAN_CNTRL_QMAN_RST_Q1_RST_MASK          (0x2U)
#define QMAN_CNTRL_QMAN_RST_Q1_RST_SHIFT         (1U)
#define QMAN_CNTRL_QMAN_RST_Q1_RST_WIDTH         (1U)
#define QMAN_CNTRL_QMAN_RST_Q1_RST(x)            (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_RST_Q1_RST_SHIFT)) & QMAN_CNTRL_QMAN_RST_Q1_RST_MASK)

#define QMAN_CNTRL_QMAN_RST_Q2_RST_MASK          (0x4U)
#define QMAN_CNTRL_QMAN_RST_Q2_RST_SHIFT         (2U)
#define QMAN_CNTRL_QMAN_RST_Q2_RST_WIDTH         (1U)
#define QMAN_CNTRL_QMAN_RST_Q2_RST(x)            (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_RST_Q2_RST_SHIFT)) & QMAN_CNTRL_QMAN_RST_Q2_RST_MASK)

#define QMAN_CNTRL_QMAN_RST_Q3_RST_MASK          (0x8U)
#define QMAN_CNTRL_QMAN_RST_Q3_RST_SHIFT         (3U)
#define QMAN_CNTRL_QMAN_RST_Q3_RST_WIDTH         (1U)
#define QMAN_CNTRL_QMAN_RST_Q3_RST(x)            (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_RST_Q3_RST_SHIFT)) & QMAN_CNTRL_QMAN_RST_Q3_RST_MASK)
/*! @} */

/*! @name QMAN_QFULL - QMAN QFULL */
/*! @{ */

#define QMAN_CNTRL_QMAN_QFULL_Q0_FULL_MASK       (0x1U)
#define QMAN_CNTRL_QMAN_QFULL_Q0_FULL_SHIFT      (0U)
#define QMAN_CNTRL_QMAN_QFULL_Q0_FULL_WIDTH      (1U)
#define QMAN_CNTRL_QMAN_QFULL_Q0_FULL(x)         (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_QFULL_Q0_FULL_SHIFT)) & QMAN_CNTRL_QMAN_QFULL_Q0_FULL_MASK)

#define QMAN_CNTRL_QMAN_QFULL_Q1_FULL_MASK       (0x2U)
#define QMAN_CNTRL_QMAN_QFULL_Q1_FULL_SHIFT      (1U)
#define QMAN_CNTRL_QMAN_QFULL_Q1_FULL_WIDTH      (1U)
#define QMAN_CNTRL_QMAN_QFULL_Q1_FULL(x)         (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_QFULL_Q1_FULL_SHIFT)) & QMAN_CNTRL_QMAN_QFULL_Q1_FULL_MASK)

#define QMAN_CNTRL_QMAN_QFULL_Q2_FULL_MASK       (0x4U)
#define QMAN_CNTRL_QMAN_QFULL_Q2_FULL_SHIFT      (2U)
#define QMAN_CNTRL_QMAN_QFULL_Q2_FULL_WIDTH      (1U)
#define QMAN_CNTRL_QMAN_QFULL_Q2_FULL(x)         (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_QFULL_Q2_FULL_SHIFT)) & QMAN_CNTRL_QMAN_QFULL_Q2_FULL_MASK)

#define QMAN_CNTRL_QMAN_QFULL_Q3_FULL_MASK       (0x8U)
#define QMAN_CNTRL_QMAN_QFULL_Q3_FULL_SHIFT      (3U)
#define QMAN_CNTRL_QMAN_QFULL_Q3_FULL_WIDTH      (1U)
#define QMAN_CNTRL_QMAN_QFULL_Q3_FULL(x)         (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_QFULL_Q3_FULL_SHIFT)) & QMAN_CNTRL_QMAN_QFULL_Q3_FULL_MASK)
/*! @} */

/*! @name QMAN_QFULL_MASK - QMAN QFULL MASK */
/*! @{ */

#define QMAN_CNTRL_QMAN_QFULL_MASK_Q0_QFULL_MASK_MASK (0x1U)
#define QMAN_CNTRL_QMAN_QFULL_MASK_Q0_QFULL_MASK_SHIFT (0U)
#define QMAN_CNTRL_QMAN_QFULL_MASK_Q0_QFULL_MASK_WIDTH (1U)
#define QMAN_CNTRL_QMAN_QFULL_MASK_Q0_QFULL_MASK(x) (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_QFULL_MASK_Q0_QFULL_MASK_SHIFT)) & QMAN_CNTRL_QMAN_QFULL_MASK_Q0_QFULL_MASK_MASK)

#define QMAN_CNTRL_QMAN_QFULL_MASK_Q1_QFULL_MASK_MASK (0x2U)
#define QMAN_CNTRL_QMAN_QFULL_MASK_Q1_QFULL_MASK_SHIFT (1U)
#define QMAN_CNTRL_QMAN_QFULL_MASK_Q1_QFULL_MASK_WIDTH (1U)
#define QMAN_CNTRL_QMAN_QFULL_MASK_Q1_QFULL_MASK(x) (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_QFULL_MASK_Q1_QFULL_MASK_SHIFT)) & QMAN_CNTRL_QMAN_QFULL_MASK_Q1_QFULL_MASK_MASK)

#define QMAN_CNTRL_QMAN_QFULL_MASK_Q2_QFULL_MASK_MASK (0x4U)
#define QMAN_CNTRL_QMAN_QFULL_MASK_Q2_QFULL_MASK_SHIFT (2U)
#define QMAN_CNTRL_QMAN_QFULL_MASK_Q2_QFULL_MASK_WIDTH (1U)
#define QMAN_CNTRL_QMAN_QFULL_MASK_Q2_QFULL_MASK(x) (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_QFULL_MASK_Q2_QFULL_MASK_SHIFT)) & QMAN_CNTRL_QMAN_QFULL_MASK_Q2_QFULL_MASK_MASK)

#define QMAN_CNTRL_QMAN_QFULL_MASK_Q3_QFULL_MASK_MASK (0x8U)
#define QMAN_CNTRL_QMAN_QFULL_MASK_Q3_QFULL_MASK_SHIFT (3U)
#define QMAN_CNTRL_QMAN_QFULL_MASK_Q3_QFULL_MASK_WIDTH (1U)
#define QMAN_CNTRL_QMAN_QFULL_MASK_Q3_QFULL_MASK(x) (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_QFULL_MASK_Q3_QFULL_MASK_SHIFT)) & QMAN_CNTRL_QMAN_QFULL_MASK_Q3_QFULL_MASK_MASK)
/*! @} */

/*! @name QMAN_PAUSE - QMAN PAUSE */
/*! @{ */

#define QMAN_CNTRL_QMAN_PAUSE_QMAN_PAUSE_MASK    (0x1U)
#define QMAN_CNTRL_QMAN_PAUSE_QMAN_PAUSE_SHIFT   (0U)
#define QMAN_CNTRL_QMAN_PAUSE_QMAN_PAUSE_WIDTH   (1U)
#define QMAN_CNTRL_QMAN_PAUSE_QMAN_PAUSE(x)      (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_PAUSE_QMAN_PAUSE_SHIFT)) & QMAN_CNTRL_QMAN_PAUSE_QMAN_PAUSE_MASK)

#define QMAN_CNTRL_QMAN_PAUSE_QMAN_PAUSE_STATUS_MASK (0x2U)
#define QMAN_CNTRL_QMAN_PAUSE_QMAN_PAUSE_STATUS_SHIFT (1U)
#define QMAN_CNTRL_QMAN_PAUSE_QMAN_PAUSE_STATUS_WIDTH (1U)
#define QMAN_CNTRL_QMAN_PAUSE_QMAN_PAUSE_STATUS(x) (((uint32_t)(((uint32_t)(x)) << QMAN_CNTRL_QMAN_PAUSE_QMAN_PAUSE_STATUS_SHIFT)) & QMAN_CNTRL_QMAN_PAUSE_QMAN_PAUSE_STATUS_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group QMAN_CNTRL_Register_Masks */

/*!
 * @}
 */ /* end of group QMAN_CNTRL_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_QMAN_CNTRL_H_) */
