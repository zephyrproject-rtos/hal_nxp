/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_PROFILER.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_PROFILER
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
#if !defined(S32Z2_PROFILER_H_)  /* Check if memory map has not been already included */
#define S32Z2_PROFILER_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- PROFILER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PROFILER_Peripheral_Access_Layer PROFILER Peripheral Access Layer
 * @{
 */

/** PROFILER - Size of Registers Arrays */
#define PROFILER_PROF_CNTX_COUNT                  8u
#define PROFILER_PROF_EV_MASKX_COUNT              8u

/** PROFILER - Register Layout Typedef */
typedef struct {
  __IO uint32_t PROF_CTL;                          /**< PROF CTL Register, offset: 0x0 */
  __IO uint32_t PROF_PAUSE;                        /**< PROF PAUSE Register, offset: 0x4 */
  __IO uint32_t PROF_CTRL0;                        /**< PROF CTRL0 Register, offset: 0x8 */
  __IO uint32_t PROF_CTRL1;                        /**< PROF CTRL1 Register, offset: 0xC */
  __I  uint32_t FRCC;                              /**< FRCC Register, offset: 0x10 */
  uint8_t RESERVED_0[12];
  __I  uint32_t PROF_CNTX[PROFILER_PROF_CNTX_COUNT]; /**< PROF CNTx Register, array offset: 0x20, array step: 0x4 */
  uint8_t RESERVED_1[64];
  __IO uint32_t PROF_EV_MASKX[PROFILER_PROF_EV_MASKX_COUNT]; /**< PROF EV MASKx Register, array offset: 0x80, array step: 0x4 */
} PROFILER_Type, *PROFILER_MemMapPtr;

/** Number of instances of the PROFILER module. */
#define PROFILER_INSTANCE_COUNT                  (1u)

/* PROFILER - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2__PROFILER base address */
#define IP_CEVA_SPF2__PROFILER_BASE              (0x24400300u)
/** Peripheral CEVA_SPF2__PROFILER base pointer */
#define IP_CEVA_SPF2__PROFILER                   ((PROFILER_Type *)IP_CEVA_SPF2__PROFILER_BASE)
/** Array initializer of PROFILER peripheral base addresses */
#define IP_PROFILER_BASE_ADDRS                   { IP_CEVA_SPF2__PROFILER_BASE }
/** Array initializer of PROFILER peripheral base pointers */
#define IP_PROFILER_BASE_PTRS                    { IP_CEVA_SPF2__PROFILER }

/* ----------------------------------------------------------------------------
   -- PROFILER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PROFILER_Register_Masks PROFILER Register Masks
 * @{
 */

/*! @name PROF_CTL - PROF CTL Register */
/*! @{ */

#define PROFILER_PROF_CTL_FRCC_RST_MASK          (0x1U)
#define PROFILER_PROF_CTL_FRCC_RST_SHIFT         (0U)
#define PROFILER_PROF_CTL_FRCC_RST_WIDTH         (1U)
#define PROFILER_PROF_CTL_FRCC_RST(x)            (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_CTL_FRCC_RST_SHIFT)) & PROFILER_PROF_CTL_FRCC_RST_MASK)

#define PROFILER_PROF_CTL_PROF_CNT0_RST_MASK     (0x2U)
#define PROFILER_PROF_CTL_PROF_CNT0_RST_SHIFT    (1U)
#define PROFILER_PROF_CTL_PROF_CNT0_RST_WIDTH    (1U)
#define PROFILER_PROF_CTL_PROF_CNT0_RST(x)       (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_CTL_PROF_CNT0_RST_SHIFT)) & PROFILER_PROF_CTL_PROF_CNT0_RST_MASK)

#define PROFILER_PROF_CTL_PROF_CNT1_RST_MASK     (0x4U)
#define PROFILER_PROF_CTL_PROF_CNT1_RST_SHIFT    (2U)
#define PROFILER_PROF_CTL_PROF_CNT1_RST_WIDTH    (1U)
#define PROFILER_PROF_CTL_PROF_CNT1_RST(x)       (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_CTL_PROF_CNT1_RST_SHIFT)) & PROFILER_PROF_CTL_PROF_CNT1_RST_MASK)

#define PROFILER_PROF_CTL_PROF_CNT2_RST_MASK     (0x8U)
#define PROFILER_PROF_CTL_PROF_CNT2_RST_SHIFT    (3U)
#define PROFILER_PROF_CTL_PROF_CNT2_RST_WIDTH    (1U)
#define PROFILER_PROF_CTL_PROF_CNT2_RST(x)       (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_CTL_PROF_CNT2_RST_SHIFT)) & PROFILER_PROF_CTL_PROF_CNT2_RST_MASK)

#define PROFILER_PROF_CTL_PROF_CNT3_RST_MASK     (0x10U)
#define PROFILER_PROF_CTL_PROF_CNT3_RST_SHIFT    (4U)
#define PROFILER_PROF_CTL_PROF_CNT3_RST_WIDTH    (1U)
#define PROFILER_PROF_CTL_PROF_CNT3_RST(x)       (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_CTL_PROF_CNT3_RST_SHIFT)) & PROFILER_PROF_CTL_PROF_CNT3_RST_MASK)

#define PROFILER_PROF_CTL_PROF_CNT4_RST_MASK     (0x20U)
#define PROFILER_PROF_CTL_PROF_CNT4_RST_SHIFT    (5U)
#define PROFILER_PROF_CTL_PROF_CNT4_RST_WIDTH    (1U)
#define PROFILER_PROF_CTL_PROF_CNT4_RST(x)       (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_CTL_PROF_CNT4_RST_SHIFT)) & PROFILER_PROF_CTL_PROF_CNT4_RST_MASK)

#define PROFILER_PROF_CTL_PROF_CNT5_RST_MASK     (0x40U)
#define PROFILER_PROF_CTL_PROF_CNT5_RST_SHIFT    (6U)
#define PROFILER_PROF_CTL_PROF_CNT5_RST_WIDTH    (1U)
#define PROFILER_PROF_CTL_PROF_CNT5_RST(x)       (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_CTL_PROF_CNT5_RST_SHIFT)) & PROFILER_PROF_CTL_PROF_CNT5_RST_MASK)

#define PROFILER_PROF_CTL_PROF_CNT6_RST_MASK     (0x80U)
#define PROFILER_PROF_CTL_PROF_CNT6_RST_SHIFT    (7U)
#define PROFILER_PROF_CTL_PROF_CNT6_RST_WIDTH    (1U)
#define PROFILER_PROF_CTL_PROF_CNT6_RST(x)       (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_CTL_PROF_CNT6_RST_SHIFT)) & PROFILER_PROF_CTL_PROF_CNT6_RST_MASK)

#define PROFILER_PROF_CTL_PROF_CNT7_RST_MASK     (0x100U)
#define PROFILER_PROF_CTL_PROF_CNT7_RST_SHIFT    (8U)
#define PROFILER_PROF_CTL_PROF_CNT7_RST_WIDTH    (1U)
#define PROFILER_PROF_CTL_PROF_CNT7_RST(x)       (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_CTL_PROF_CNT7_RST_SHIFT)) & PROFILER_PROF_CTL_PROF_CNT7_RST_MASK)
/*! @} */

/*! @name PROF_PAUSE - PROF PAUSE Register */
/*! @{ */

#define PROFILER_PROF_PAUSE_FRCC_PAUSE_MASK      (0x1U)
#define PROFILER_PROF_PAUSE_FRCC_PAUSE_SHIFT     (0U)
#define PROFILER_PROF_PAUSE_FRCC_PAUSE_WIDTH     (1U)
#define PROFILER_PROF_PAUSE_FRCC_PAUSE(x)        (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_PAUSE_FRCC_PAUSE_SHIFT)) & PROFILER_PROF_PAUSE_FRCC_PAUSE_MASK)

#define PROFILER_PROF_PAUSE_PROF_CNT0_PAUSE_MASK (0x2U)
#define PROFILER_PROF_PAUSE_PROF_CNT0_PAUSE_SHIFT (1U)
#define PROFILER_PROF_PAUSE_PROF_CNT0_PAUSE_WIDTH (1U)
#define PROFILER_PROF_PAUSE_PROF_CNT0_PAUSE(x)   (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_PAUSE_PROF_CNT0_PAUSE_SHIFT)) & PROFILER_PROF_PAUSE_PROF_CNT0_PAUSE_MASK)

#define PROFILER_PROF_PAUSE_PROF_CNT1_PAUSE_MASK (0x4U)
#define PROFILER_PROF_PAUSE_PROF_CNT1_PAUSE_SHIFT (2U)
#define PROFILER_PROF_PAUSE_PROF_CNT1_PAUSE_WIDTH (1U)
#define PROFILER_PROF_PAUSE_PROF_CNT1_PAUSE(x)   (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_PAUSE_PROF_CNT1_PAUSE_SHIFT)) & PROFILER_PROF_PAUSE_PROF_CNT1_PAUSE_MASK)

#define PROFILER_PROF_PAUSE_PROF_CNT2_PAUSE_MASK (0x8U)
#define PROFILER_PROF_PAUSE_PROF_CNT2_PAUSE_SHIFT (3U)
#define PROFILER_PROF_PAUSE_PROF_CNT2_PAUSE_WIDTH (1U)
#define PROFILER_PROF_PAUSE_PROF_CNT2_PAUSE(x)   (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_PAUSE_PROF_CNT2_PAUSE_SHIFT)) & PROFILER_PROF_PAUSE_PROF_CNT2_PAUSE_MASK)

#define PROFILER_PROF_PAUSE_PROF_CNT3_PAUSE_MASK (0x10U)
#define PROFILER_PROF_PAUSE_PROF_CNT3_PAUSE_SHIFT (4U)
#define PROFILER_PROF_PAUSE_PROF_CNT3_PAUSE_WIDTH (1U)
#define PROFILER_PROF_PAUSE_PROF_CNT3_PAUSE(x)   (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_PAUSE_PROF_CNT3_PAUSE_SHIFT)) & PROFILER_PROF_PAUSE_PROF_CNT3_PAUSE_MASK)

#define PROFILER_PROF_PAUSE_PROF_CNT4_PAUSE_MASK (0x20U)
#define PROFILER_PROF_PAUSE_PROF_CNT4_PAUSE_SHIFT (5U)
#define PROFILER_PROF_PAUSE_PROF_CNT4_PAUSE_WIDTH (1U)
#define PROFILER_PROF_PAUSE_PROF_CNT4_PAUSE(x)   (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_PAUSE_PROF_CNT4_PAUSE_SHIFT)) & PROFILER_PROF_PAUSE_PROF_CNT4_PAUSE_MASK)

#define PROFILER_PROF_PAUSE_PROF_CNT5_PAUSE_MASK (0x40U)
#define PROFILER_PROF_PAUSE_PROF_CNT5_PAUSE_SHIFT (6U)
#define PROFILER_PROF_PAUSE_PROF_CNT5_PAUSE_WIDTH (1U)
#define PROFILER_PROF_PAUSE_PROF_CNT5_PAUSE(x)   (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_PAUSE_PROF_CNT5_PAUSE_SHIFT)) & PROFILER_PROF_PAUSE_PROF_CNT5_PAUSE_MASK)

#define PROFILER_PROF_PAUSE_PROF_CNT6_PAUSE_MASK (0x80U)
#define PROFILER_PROF_PAUSE_PROF_CNT6_PAUSE_SHIFT (7U)
#define PROFILER_PROF_PAUSE_PROF_CNT6_PAUSE_WIDTH (1U)
#define PROFILER_PROF_PAUSE_PROF_CNT6_PAUSE(x)   (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_PAUSE_PROF_CNT6_PAUSE_SHIFT)) & PROFILER_PROF_PAUSE_PROF_CNT6_PAUSE_MASK)

#define PROFILER_PROF_PAUSE_PROF_CNT7_PAUSE_MASK (0x100U)
#define PROFILER_PROF_PAUSE_PROF_CNT7_PAUSE_SHIFT (8U)
#define PROFILER_PROF_PAUSE_PROF_CNT7_PAUSE_WIDTH (1U)
#define PROFILER_PROF_PAUSE_PROF_CNT7_PAUSE(x)   (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_PAUSE_PROF_CNT7_PAUSE_SHIFT)) & PROFILER_PROF_PAUSE_PROF_CNT7_PAUSE_MASK)
/*! @} */

/*! @name PROF_CTRL0 - PROF CTRL0 Register */
/*! @{ */

#define PROFILER_PROF_CTRL0_PROF_CNT0_SEL_MASK   (0xFFU)
#define PROFILER_PROF_CTRL0_PROF_CNT0_SEL_SHIFT  (0U)
#define PROFILER_PROF_CTRL0_PROF_CNT0_SEL_WIDTH  (8U)
#define PROFILER_PROF_CTRL0_PROF_CNT0_SEL(x)     (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_CTRL0_PROF_CNT0_SEL_SHIFT)) & PROFILER_PROF_CTRL0_PROF_CNT0_SEL_MASK)

#define PROFILER_PROF_CTRL0_PROF_CNT1_SEL_MASK   (0xFF00U)
#define PROFILER_PROF_CTRL0_PROF_CNT1_SEL_SHIFT  (8U)
#define PROFILER_PROF_CTRL0_PROF_CNT1_SEL_WIDTH  (8U)
#define PROFILER_PROF_CTRL0_PROF_CNT1_SEL(x)     (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_CTRL0_PROF_CNT1_SEL_SHIFT)) & PROFILER_PROF_CTRL0_PROF_CNT1_SEL_MASK)

#define PROFILER_PROF_CTRL0_PROF_CNT2_SEL_MASK   (0xFF0000U)
#define PROFILER_PROF_CTRL0_PROF_CNT2_SEL_SHIFT  (16U)
#define PROFILER_PROF_CTRL0_PROF_CNT2_SEL_WIDTH  (8U)
#define PROFILER_PROF_CTRL0_PROF_CNT2_SEL(x)     (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_CTRL0_PROF_CNT2_SEL_SHIFT)) & PROFILER_PROF_CTRL0_PROF_CNT2_SEL_MASK)

#define PROFILER_PROF_CTRL0_PROF_CNT3_SEL_MASK   (0xFF000000U)
#define PROFILER_PROF_CTRL0_PROF_CNT3_SEL_SHIFT  (24U)
#define PROFILER_PROF_CTRL0_PROF_CNT3_SEL_WIDTH  (8U)
#define PROFILER_PROF_CTRL0_PROF_CNT3_SEL(x)     (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_CTRL0_PROF_CNT3_SEL_SHIFT)) & PROFILER_PROF_CTRL0_PROF_CNT3_SEL_MASK)
/*! @} */

/*! @name PROF_CTRL1 - PROF CTRL1 Register */
/*! @{ */

#define PROFILER_PROF_CTRL1_PROF_CNT4_SEL_MASK   (0xFFU)
#define PROFILER_PROF_CTRL1_PROF_CNT4_SEL_SHIFT  (0U)
#define PROFILER_PROF_CTRL1_PROF_CNT4_SEL_WIDTH  (8U)
#define PROFILER_PROF_CTRL1_PROF_CNT4_SEL(x)     (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_CTRL1_PROF_CNT4_SEL_SHIFT)) & PROFILER_PROF_CTRL1_PROF_CNT4_SEL_MASK)

#define PROFILER_PROF_CTRL1_PROF_CNT5_SEL_MASK   (0xFF00U)
#define PROFILER_PROF_CTRL1_PROF_CNT5_SEL_SHIFT  (8U)
#define PROFILER_PROF_CTRL1_PROF_CNT5_SEL_WIDTH  (8U)
#define PROFILER_PROF_CTRL1_PROF_CNT5_SEL(x)     (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_CTRL1_PROF_CNT5_SEL_SHIFT)) & PROFILER_PROF_CTRL1_PROF_CNT5_SEL_MASK)

#define PROFILER_PROF_CTRL1_PROF_CNT6_SEL_MASK   (0xFF0000U)
#define PROFILER_PROF_CTRL1_PROF_CNT6_SEL_SHIFT  (16U)
#define PROFILER_PROF_CTRL1_PROF_CNT6_SEL_WIDTH  (8U)
#define PROFILER_PROF_CTRL1_PROF_CNT6_SEL(x)     (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_CTRL1_PROF_CNT6_SEL_SHIFT)) & PROFILER_PROF_CTRL1_PROF_CNT6_SEL_MASK)

#define PROFILER_PROF_CTRL1_PROF_CNT7_SEL_MASK   (0xFF000000U)
#define PROFILER_PROF_CTRL1_PROF_CNT7_SEL_SHIFT  (24U)
#define PROFILER_PROF_CTRL1_PROF_CNT7_SEL_WIDTH  (8U)
#define PROFILER_PROF_CTRL1_PROF_CNT7_SEL(x)     (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_CTRL1_PROF_CNT7_SEL_SHIFT)) & PROFILER_PROF_CTRL1_PROF_CNT7_SEL_MASK)
/*! @} */

/*! @name FRCC - FRCC Register */
/*! @{ */

#define PROFILER_FRCC_FRCC_MASK                  (0xFFFFFFFFU)
#define PROFILER_FRCC_FRCC_SHIFT                 (0U)
#define PROFILER_FRCC_FRCC_WIDTH                 (32U)
#define PROFILER_FRCC_FRCC(x)                    (((uint32_t)(((uint32_t)(x)) << PROFILER_FRCC_FRCC_SHIFT)) & PROFILER_FRCC_FRCC_MASK)
/*! @} */

/*! @name PROF_CNTX - PROF CNTx Register */
/*! @{ */

#define PROFILER_PROF_CNTX_PROF_CNTx_MASK        (0xFFFFFFFFU)
#define PROFILER_PROF_CNTX_PROF_CNTx_SHIFT       (0U)
#define PROFILER_PROF_CNTX_PROF_CNTx_WIDTH       (32U)
#define PROFILER_PROF_CNTX_PROF_CNTx(x)          (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_CNTX_PROF_CNTx_SHIFT)) & PROFILER_PROF_CNTX_PROF_CNTx_MASK)
/*! @} */

/*! @name PROF_EV_MASKX - PROF EV MASKx Register */
/*! @{ */

#define PROFILER_PROF_EV_MASKX_PROF_MF0_MASK     (0xFFU)
#define PROFILER_PROF_EV_MASKX_PROF_MF0_SHIFT    (0U)
#define PROFILER_PROF_EV_MASKX_PROF_MF0_WIDTH    (8U)
#define PROFILER_PROF_EV_MASKX_PROF_MF0(x)       (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_EV_MASKX_PROF_MF0_SHIFT)) & PROFILER_PROF_EV_MASKX_PROF_MF0_MASK)

#define PROFILER_PROF_EV_MASKX_PROF_MF1_MASK     (0xFF00U)
#define PROFILER_PROF_EV_MASKX_PROF_MF1_SHIFT    (8U)
#define PROFILER_PROF_EV_MASKX_PROF_MF1_WIDTH    (8U)
#define PROFILER_PROF_EV_MASKX_PROF_MF1(x)       (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_EV_MASKX_PROF_MF1_SHIFT)) & PROFILER_PROF_EV_MASKX_PROF_MF1_MASK)

#define PROFILER_PROF_EV_MASKX_PROF_MF2_MASK     (0xF0000U)
#define PROFILER_PROF_EV_MASKX_PROF_MF2_SHIFT    (16U)
#define PROFILER_PROF_EV_MASKX_PROF_MF2_WIDTH    (4U)
#define PROFILER_PROF_EV_MASKX_PROF_MF2(x)       (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_EV_MASKX_PROF_MF2_SHIFT)) & PROFILER_PROF_EV_MASKX_PROF_MF2_MASK)

#define PROFILER_PROF_EV_MASKX_PROF_MF3_MASK     (0xF00000U)
#define PROFILER_PROF_EV_MASKX_PROF_MF3_SHIFT    (20U)
#define PROFILER_PROF_EV_MASKX_PROF_MF3_WIDTH    (4U)
#define PROFILER_PROF_EV_MASKX_PROF_MF3(x)       (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_EV_MASKX_PROF_MF3_SHIFT)) & PROFILER_PROF_EV_MASKX_PROF_MF3_MASK)

#define PROFILER_PROF_EV_MASKX_PROF_MF4_MASK     (0xF000000U)
#define PROFILER_PROF_EV_MASKX_PROF_MF4_SHIFT    (24U)
#define PROFILER_PROF_EV_MASKX_PROF_MF4_WIDTH    (4U)
#define PROFILER_PROF_EV_MASKX_PROF_MF4(x)       (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_EV_MASKX_PROF_MF4_SHIFT)) & PROFILER_PROF_EV_MASKX_PROF_MF4_MASK)

#define PROFILER_PROF_EV_MASKX_PROF_MF5_MASK     (0xF0000000U)
#define PROFILER_PROF_EV_MASKX_PROF_MF5_SHIFT    (28U)
#define PROFILER_PROF_EV_MASKX_PROF_MF5_WIDTH    (4U)
#define PROFILER_PROF_EV_MASKX_PROF_MF5(x)       (((uint32_t)(((uint32_t)(x)) << PROFILER_PROF_EV_MASKX_PROF_MF5_SHIFT)) & PROFILER_PROF_EV_MASKX_PROF_MF5_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group PROFILER_Register_Masks */

/*!
 * @}
 */ /* end of group PROFILER_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_PROFILER_H_) */
