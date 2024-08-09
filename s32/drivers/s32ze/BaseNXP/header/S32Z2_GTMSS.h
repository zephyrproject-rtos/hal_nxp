/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_GTMSS.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_GTMSS
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
#if !defined(S32Z2_GTMSS_H_)  /* Check if memory map has not been already included */
#define S32Z2_GTMSS_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- GTMSS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GTMSS_Peripheral_Access_Layer GTMSS Peripheral Access Layer
 * @{
 */

/** GTMSS - Register Layout Typedef */
typedef struct {
  __IO uint32_t IRQ_CFG0;                          /**< IRQ Configuration Register for Cluster 0, offset: 0x0 */
  __IO uint32_t IRQ_CFG1;                          /**< IRQ Confoguration Register for Cluster 1, offset: 0x4 */
  __IO uint32_t IRQ_CFG2;                          /**< IRQ Confoguration Register for Cluster 2, offset: 0x8 */
  __IO uint32_t IRQ_CFG3;                          /**< IRQ Confoguration Register for Cluster 3, offset: 0xC */
  uint8_t RESERVED_0[8176];
  __IO uint32_t DBG_DID;                           /**< Debug domain ID register, offset: 0x2000 */
} GTMSS_Type, *GTMSS_MemMapPtr;

/** Number of instances of the GTMSS module. */
#define GTMSS_INSTANCE_COUNT                     (1u)

/* GTMSS - Peripheral instance base addresses */
/** Peripheral GTMSS base address */
#define IP_GTMSS_BASE                            (0x4037C000u)
/** Peripheral GTMSS base pointer */
#define IP_GTMSS                                 ((GTMSS_Type *)IP_GTMSS_BASE)
/** Array initializer of GTMSS peripheral base addresses */
#define IP_GTMSS_BASE_ADDRS                      { IP_GTMSS_BASE }
/** Array initializer of GTMSS peripheral base pointers */
#define IP_GTMSS_BASE_PTRS                       { IP_GTMSS }

/* ----------------------------------------------------------------------------
   -- GTMSS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GTMSS_Register_Masks GTMSS Register Masks
 * @{
 */

/*! @name IRQ_CFG0 - IRQ Configuration Register for Cluster 0 */
/*! @{ */

#define GTMSS_IRQ_CFG0_FIFO0_MASK                (0x10U)
#define GTMSS_IRQ_CFG0_FIFO0_SHIFT               (4U)
#define GTMSS_IRQ_CFG0_FIFO0_WIDTH               (1U)
#define GTMSS_IRQ_CFG0_FIFO0(x)                  (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG0_FIFO0_SHIFT)) & GTMSS_IRQ_CFG0_FIFO0_MASK)

#define GTMSS_IRQ_CFG0_FIFO1_MASK                (0x20U)
#define GTMSS_IRQ_CFG0_FIFO1_SHIFT               (5U)
#define GTMSS_IRQ_CFG0_FIFO1_WIDTH               (1U)
#define GTMSS_IRQ_CFG0_FIFO1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG0_FIFO1_SHIFT)) & GTMSS_IRQ_CFG0_FIFO1_MASK)

#define GTMSS_IRQ_CFG0_FIFO2_MASK                (0x40U)
#define GTMSS_IRQ_CFG0_FIFO2_SHIFT               (6U)
#define GTMSS_IRQ_CFG0_FIFO2_WIDTH               (1U)
#define GTMSS_IRQ_CFG0_FIFO2(x)                  (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG0_FIFO2_SHIFT)) & GTMSS_IRQ_CFG0_FIFO2_MASK)

#define GTMSS_IRQ_CFG0_FIFO3_MASK                (0x80U)
#define GTMSS_IRQ_CFG0_FIFO3_SHIFT               (7U)
#define GTMSS_IRQ_CFG0_FIFO3_WIDTH               (1U)
#define GTMSS_IRQ_CFG0_FIFO3(x)                  (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG0_FIFO3_SHIFT)) & GTMSS_IRQ_CFG0_FIFO3_MASK)

#define GTMSS_IRQ_CFG0_TIM6_MASK                 (0x100U)
#define GTMSS_IRQ_CFG0_TIM6_SHIFT                (8U)
#define GTMSS_IRQ_CFG0_TIM6_WIDTH                (1U)
#define GTMSS_IRQ_CFG0_TIM6(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG0_TIM6_SHIFT)) & GTMSS_IRQ_CFG0_TIM6_MASK)

#define GTMSS_IRQ_CFG0_TIM7_MASK                 (0x200U)
#define GTMSS_IRQ_CFG0_TIM7_SHIFT                (9U)
#define GTMSS_IRQ_CFG0_TIM7_WIDTH                (1U)
#define GTMSS_IRQ_CFG0_TIM7(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG0_TIM7_SHIFT)) & GTMSS_IRQ_CFG0_TIM7_MASK)

#define GTMSS_IRQ_CFG0_ATOM1_MASK                (0x1000U)
#define GTMSS_IRQ_CFG0_ATOM1_SHIFT               (12U)
#define GTMSS_IRQ_CFG0_ATOM1_WIDTH               (1U)
#define GTMSS_IRQ_CFG0_ATOM1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG0_ATOM1_SHIFT)) & GTMSS_IRQ_CFG0_ATOM1_MASK)

#define GTMSS_IRQ_CFG0_ATOM3_MASK                (0x2000U)
#define GTMSS_IRQ_CFG0_ATOM3_SHIFT               (13U)
#define GTMSS_IRQ_CFG0_ATOM3_WIDTH               (1U)
#define GTMSS_IRQ_CFG0_ATOM3(x)                  (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG0_ATOM3_SHIFT)) & GTMSS_IRQ_CFG0_ATOM3_MASK)

#define GTMSS_IRQ_CFG0_MCS0_MASK                 (0x10000U)
#define GTMSS_IRQ_CFG0_MCS0_SHIFT                (16U)
#define GTMSS_IRQ_CFG0_MCS0_WIDTH                (1U)
#define GTMSS_IRQ_CFG0_MCS0(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG0_MCS0_SHIFT)) & GTMSS_IRQ_CFG0_MCS0_MASK)

#define GTMSS_IRQ_CFG0_MCS1_MASK                 (0x20000U)
#define GTMSS_IRQ_CFG0_MCS1_SHIFT                (17U)
#define GTMSS_IRQ_CFG0_MCS1_WIDTH                (1U)
#define GTMSS_IRQ_CFG0_MCS1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG0_MCS1_SHIFT)) & GTMSS_IRQ_CFG0_MCS1_MASK)

#define GTMSS_IRQ_CFG0_MCS2_MASK                 (0x40000U)
#define GTMSS_IRQ_CFG0_MCS2_SHIFT                (18U)
#define GTMSS_IRQ_CFG0_MCS2_WIDTH                (1U)
#define GTMSS_IRQ_CFG0_MCS2(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG0_MCS2_SHIFT)) & GTMSS_IRQ_CFG0_MCS2_MASK)

#define GTMSS_IRQ_CFG0_MCS3_MASK                 (0x80000U)
#define GTMSS_IRQ_CFG0_MCS3_SHIFT                (19U)
#define GTMSS_IRQ_CFG0_MCS3_WIDTH                (1U)
#define GTMSS_IRQ_CFG0_MCS3(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG0_MCS3_SHIFT)) & GTMSS_IRQ_CFG0_MCS3_MASK)

#define GTMSS_IRQ_CFG0_LCK_MASK                  (0x80000000U)
#define GTMSS_IRQ_CFG0_LCK_SHIFT                 (31U)
#define GTMSS_IRQ_CFG0_LCK_WIDTH                 (1U)
#define GTMSS_IRQ_CFG0_LCK(x)                    (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG0_LCK_SHIFT)) & GTMSS_IRQ_CFG0_LCK_MASK)
/*! @} */

/*! @name IRQ_CFG1 - IRQ Confoguration Register for Cluster 1 */
/*! @{ */

#define GTMSS_IRQ_CFG1_TIO3_MASK                 (0x1U)
#define GTMSS_IRQ_CFG1_TIO3_SHIFT                (0U)
#define GTMSS_IRQ_CFG1_TIO3_WIDTH                (1U)
#define GTMSS_IRQ_CFG1_TIO3(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG1_TIO3_SHIFT)) & GTMSS_IRQ_CFG1_TIO3_MASK)

#define GTMSS_IRQ_CFG1_TIO5_MASK                 (0x2U)
#define GTMSS_IRQ_CFG1_TIO5_SHIFT                (1U)
#define GTMSS_IRQ_CFG1_TIO5_WIDTH                (1U)
#define GTMSS_IRQ_CFG1_TIO5(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG1_TIO5_SHIFT)) & GTMSS_IRQ_CFG1_TIO5_MASK)

#define GTMSS_IRQ_CFG1_TIO7_MASK                 (0x4U)
#define GTMSS_IRQ_CFG1_TIO7_SHIFT                (2U)
#define GTMSS_IRQ_CFG1_TIO7_WIDTH                (1U)
#define GTMSS_IRQ_CFG1_TIO7(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG1_TIO7_SHIFT)) & GTMSS_IRQ_CFG1_TIO7_MASK)

#define GTMSS_IRQ_CFG1_TIM6_MASK                 (0x100U)
#define GTMSS_IRQ_CFG1_TIM6_SHIFT                (8U)
#define GTMSS_IRQ_CFG1_TIM6_WIDTH                (1U)
#define GTMSS_IRQ_CFG1_TIM6(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG1_TIM6_SHIFT)) & GTMSS_IRQ_CFG1_TIM6_MASK)

#define GTMSS_IRQ_CFG1_TIM7_MASK                 (0x200U)
#define GTMSS_IRQ_CFG1_TIM7_SHIFT                (9U)
#define GTMSS_IRQ_CFG1_TIM7_WIDTH                (1U)
#define GTMSS_IRQ_CFG1_TIM7(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG1_TIM7_SHIFT)) & GTMSS_IRQ_CFG1_TIM7_MASK)

#define GTMSS_IRQ_CFG1_ATOM1_MASK                (0x1000U)
#define GTMSS_IRQ_CFG1_ATOM1_SHIFT               (12U)
#define GTMSS_IRQ_CFG1_ATOM1_WIDTH               (1U)
#define GTMSS_IRQ_CFG1_ATOM1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG1_ATOM1_SHIFT)) & GTMSS_IRQ_CFG1_ATOM1_MASK)

#define GTMSS_IRQ_CFG1_ATOM3_MASK                (0x2000U)
#define GTMSS_IRQ_CFG1_ATOM3_SHIFT               (13U)
#define GTMSS_IRQ_CFG1_ATOM3_WIDTH               (1U)
#define GTMSS_IRQ_CFG1_ATOM3(x)                  (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG1_ATOM3_SHIFT)) & GTMSS_IRQ_CFG1_ATOM3_MASK)

#define GTMSS_IRQ_CFG1_MCS0_MASK                 (0x10000U)
#define GTMSS_IRQ_CFG1_MCS0_SHIFT                (16U)
#define GTMSS_IRQ_CFG1_MCS0_WIDTH                (1U)
#define GTMSS_IRQ_CFG1_MCS0(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG1_MCS0_SHIFT)) & GTMSS_IRQ_CFG1_MCS0_MASK)

#define GTMSS_IRQ_CFG1_MCS1_MASK                 (0x20000U)
#define GTMSS_IRQ_CFG1_MCS1_SHIFT                (17U)
#define GTMSS_IRQ_CFG1_MCS1_WIDTH                (1U)
#define GTMSS_IRQ_CFG1_MCS1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG1_MCS1_SHIFT)) & GTMSS_IRQ_CFG1_MCS1_MASK)

#define GTMSS_IRQ_CFG1_MCS2_MASK                 (0x40000U)
#define GTMSS_IRQ_CFG1_MCS2_SHIFT                (18U)
#define GTMSS_IRQ_CFG1_MCS2_WIDTH                (1U)
#define GTMSS_IRQ_CFG1_MCS2(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG1_MCS2_SHIFT)) & GTMSS_IRQ_CFG1_MCS2_MASK)

#define GTMSS_IRQ_CFG1_MCS3_MASK                 (0x80000U)
#define GTMSS_IRQ_CFG1_MCS3_SHIFT                (19U)
#define GTMSS_IRQ_CFG1_MCS3_WIDTH                (1U)
#define GTMSS_IRQ_CFG1_MCS3(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG1_MCS3_SHIFT)) & GTMSS_IRQ_CFG1_MCS3_MASK)

#define GTMSS_IRQ_CFG1_LCK_MASK                  (0x80000000U)
#define GTMSS_IRQ_CFG1_LCK_SHIFT                 (31U)
#define GTMSS_IRQ_CFG1_LCK_WIDTH                 (1U)
#define GTMSS_IRQ_CFG1_LCK(x)                    (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG1_LCK_SHIFT)) & GTMSS_IRQ_CFG1_LCK_MASK)
/*! @} */

/*! @name IRQ_CFG2 - IRQ Confoguration Register for Cluster 2 */
/*! @{ */

#define GTMSS_IRQ_CFG2_TIO3_MASK                 (0x1U)
#define GTMSS_IRQ_CFG2_TIO3_SHIFT                (0U)
#define GTMSS_IRQ_CFG2_TIO3_WIDTH                (1U)
#define GTMSS_IRQ_CFG2_TIO3(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG2_TIO3_SHIFT)) & GTMSS_IRQ_CFG2_TIO3_MASK)

#define GTMSS_IRQ_CFG2_TIO5_MASK                 (0x2U)
#define GTMSS_IRQ_CFG2_TIO5_SHIFT                (1U)
#define GTMSS_IRQ_CFG2_TIO5_WIDTH                (1U)
#define GTMSS_IRQ_CFG2_TIO5(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG2_TIO5_SHIFT)) & GTMSS_IRQ_CFG2_TIO5_MASK)

#define GTMSS_IRQ_CFG2_TIO7_MASK                 (0x4U)
#define GTMSS_IRQ_CFG2_TIO7_SHIFT                (2U)
#define GTMSS_IRQ_CFG2_TIO7_WIDTH                (1U)
#define GTMSS_IRQ_CFG2_TIO7(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG2_TIO7_SHIFT)) & GTMSS_IRQ_CFG2_TIO7_MASK)

#define GTMSS_IRQ_CFG2_TIM6_MASK                 (0x100U)
#define GTMSS_IRQ_CFG2_TIM6_SHIFT                (8U)
#define GTMSS_IRQ_CFG2_TIM6_WIDTH                (1U)
#define GTMSS_IRQ_CFG2_TIM6(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG2_TIM6_SHIFT)) & GTMSS_IRQ_CFG2_TIM6_MASK)

#define GTMSS_IRQ_CFG2_TIM7_MASK                 (0x200U)
#define GTMSS_IRQ_CFG2_TIM7_SHIFT                (9U)
#define GTMSS_IRQ_CFG2_TIM7_WIDTH                (1U)
#define GTMSS_IRQ_CFG2_TIM7(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG2_TIM7_SHIFT)) & GTMSS_IRQ_CFG2_TIM7_MASK)

#define GTMSS_IRQ_CFG2_ATOM1_MASK                (0x1000U)
#define GTMSS_IRQ_CFG2_ATOM1_SHIFT               (12U)
#define GTMSS_IRQ_CFG2_ATOM1_WIDTH               (1U)
#define GTMSS_IRQ_CFG2_ATOM1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG2_ATOM1_SHIFT)) & GTMSS_IRQ_CFG2_ATOM1_MASK)

#define GTMSS_IRQ_CFG2_ATOM3_MASK                (0x2000U)
#define GTMSS_IRQ_CFG2_ATOM3_SHIFT               (13U)
#define GTMSS_IRQ_CFG2_ATOM3_WIDTH               (1U)
#define GTMSS_IRQ_CFG2_ATOM3(x)                  (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG2_ATOM3_SHIFT)) & GTMSS_IRQ_CFG2_ATOM3_MASK)

#define GTMSS_IRQ_CFG2_MCS0_MASK                 (0x10000U)
#define GTMSS_IRQ_CFG2_MCS0_SHIFT                (16U)
#define GTMSS_IRQ_CFG2_MCS0_WIDTH                (1U)
#define GTMSS_IRQ_CFG2_MCS0(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG2_MCS0_SHIFT)) & GTMSS_IRQ_CFG2_MCS0_MASK)

#define GTMSS_IRQ_CFG2_MCS1_MASK                 (0x20000U)
#define GTMSS_IRQ_CFG2_MCS1_SHIFT                (17U)
#define GTMSS_IRQ_CFG2_MCS1_WIDTH                (1U)
#define GTMSS_IRQ_CFG2_MCS1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG2_MCS1_SHIFT)) & GTMSS_IRQ_CFG2_MCS1_MASK)

#define GTMSS_IRQ_CFG2_MCS2_MASK                 (0x40000U)
#define GTMSS_IRQ_CFG2_MCS2_SHIFT                (18U)
#define GTMSS_IRQ_CFG2_MCS2_WIDTH                (1U)
#define GTMSS_IRQ_CFG2_MCS2(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG2_MCS2_SHIFT)) & GTMSS_IRQ_CFG2_MCS2_MASK)

#define GTMSS_IRQ_CFG2_MCS3_MASK                 (0x80000U)
#define GTMSS_IRQ_CFG2_MCS3_SHIFT                (19U)
#define GTMSS_IRQ_CFG2_MCS3_WIDTH                (1U)
#define GTMSS_IRQ_CFG2_MCS3(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG2_MCS3_SHIFT)) & GTMSS_IRQ_CFG2_MCS3_MASK)

#define GTMSS_IRQ_CFG2_LCK_MASK                  (0x80000000U)
#define GTMSS_IRQ_CFG2_LCK_SHIFT                 (31U)
#define GTMSS_IRQ_CFG2_LCK_WIDTH                 (1U)
#define GTMSS_IRQ_CFG2_LCK(x)                    (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG2_LCK_SHIFT)) & GTMSS_IRQ_CFG2_LCK_MASK)
/*! @} */

/*! @name IRQ_CFG3 - IRQ Confoguration Register for Cluster 3 */
/*! @{ */

#define GTMSS_IRQ_CFG3_TIO3_MASK                 (0x1U)
#define GTMSS_IRQ_CFG3_TIO3_SHIFT                (0U)
#define GTMSS_IRQ_CFG3_TIO3_WIDTH                (1U)
#define GTMSS_IRQ_CFG3_TIO3(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG3_TIO3_SHIFT)) & GTMSS_IRQ_CFG3_TIO3_MASK)

#define GTMSS_IRQ_CFG3_TIO5_MASK                 (0x2U)
#define GTMSS_IRQ_CFG3_TIO5_SHIFT                (1U)
#define GTMSS_IRQ_CFG3_TIO5_WIDTH                (1U)
#define GTMSS_IRQ_CFG3_TIO5(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG3_TIO5_SHIFT)) & GTMSS_IRQ_CFG3_TIO5_MASK)

#define GTMSS_IRQ_CFG3_TIO7_MASK                 (0x4U)
#define GTMSS_IRQ_CFG3_TIO7_SHIFT                (2U)
#define GTMSS_IRQ_CFG3_TIO7_WIDTH                (1U)
#define GTMSS_IRQ_CFG3_TIO7(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG3_TIO7_SHIFT)) & GTMSS_IRQ_CFG3_TIO7_MASK)

#define GTMSS_IRQ_CFG3_ATOM1_MASK                (0x1000U)
#define GTMSS_IRQ_CFG3_ATOM1_SHIFT               (12U)
#define GTMSS_IRQ_CFG3_ATOM1_WIDTH               (1U)
#define GTMSS_IRQ_CFG3_ATOM1(x)                  (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG3_ATOM1_SHIFT)) & GTMSS_IRQ_CFG3_ATOM1_MASK)

#define GTMSS_IRQ_CFG3_ATOM3_MASK                (0x2000U)
#define GTMSS_IRQ_CFG3_ATOM3_SHIFT               (13U)
#define GTMSS_IRQ_CFG3_ATOM3_WIDTH               (1U)
#define GTMSS_IRQ_CFG3_ATOM3(x)                  (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG3_ATOM3_SHIFT)) & GTMSS_IRQ_CFG3_ATOM3_MASK)

#define GTMSS_IRQ_CFG3_MCS0_MASK                 (0x10000U)
#define GTMSS_IRQ_CFG3_MCS0_SHIFT                (16U)
#define GTMSS_IRQ_CFG3_MCS0_WIDTH                (1U)
#define GTMSS_IRQ_CFG3_MCS0(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG3_MCS0_SHIFT)) & GTMSS_IRQ_CFG3_MCS0_MASK)

#define GTMSS_IRQ_CFG3_MCS1_MASK                 (0x20000U)
#define GTMSS_IRQ_CFG3_MCS1_SHIFT                (17U)
#define GTMSS_IRQ_CFG3_MCS1_WIDTH                (1U)
#define GTMSS_IRQ_CFG3_MCS1(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG3_MCS1_SHIFT)) & GTMSS_IRQ_CFG3_MCS1_MASK)

#define GTMSS_IRQ_CFG3_MCS2_MASK                 (0x40000U)
#define GTMSS_IRQ_CFG3_MCS2_SHIFT                (18U)
#define GTMSS_IRQ_CFG3_MCS2_WIDTH                (1U)
#define GTMSS_IRQ_CFG3_MCS2(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG3_MCS2_SHIFT)) & GTMSS_IRQ_CFG3_MCS2_MASK)

#define GTMSS_IRQ_CFG3_MCS3_MASK                 (0x80000U)
#define GTMSS_IRQ_CFG3_MCS3_SHIFT                (19U)
#define GTMSS_IRQ_CFG3_MCS3_WIDTH                (1U)
#define GTMSS_IRQ_CFG3_MCS3(x)                   (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG3_MCS3_SHIFT)) & GTMSS_IRQ_CFG3_MCS3_MASK)

#define GTMSS_IRQ_CFG3_LCK_MASK                  (0x80000000U)
#define GTMSS_IRQ_CFG3_LCK_SHIFT                 (31U)
#define GTMSS_IRQ_CFG3_LCK_WIDTH                 (1U)
#define GTMSS_IRQ_CFG3_LCK(x)                    (((uint32_t)(((uint32_t)(x)) << GTMSS_IRQ_CFG3_LCK_SHIFT)) & GTMSS_IRQ_CFG3_LCK_MASK)
/*! @} */

/*! @name DBG_DID - Debug domain ID register */
/*! @{ */

#define GTMSS_DBG_DID_DID_MASK                   (0x78U)
#define GTMSS_DBG_DID_DID_SHIFT                  (3U)
#define GTMSS_DBG_DID_DID_WIDTH                  (4U)
#define GTMSS_DBG_DID_DID(x)                     (((uint32_t)(((uint32_t)(x)) << GTMSS_DBG_DID_DID_SHIFT)) & GTMSS_DBG_DID_DID_MASK)

#define GTMSS_DBG_DID_EN_MASK                    (0x40000000U)
#define GTMSS_DBG_DID_EN_SHIFT                   (30U)
#define GTMSS_DBG_DID_EN_WIDTH                   (1U)
#define GTMSS_DBG_DID_EN(x)                      (((uint32_t)(((uint32_t)(x)) << GTMSS_DBG_DID_EN_SHIFT)) & GTMSS_DBG_DID_EN_MASK)

#define GTMSS_DBG_DID_LCK_MASK                   (0x80000000U)
#define GTMSS_DBG_DID_LCK_SHIFT                  (31U)
#define GTMSS_DBG_DID_LCK_WIDTH                  (1U)
#define GTMSS_DBG_DID_LCK(x)                     (((uint32_t)(((uint32_t)(x)) << GTMSS_DBG_DID_LCK_SHIFT)) & GTMSS_DBG_DID_LCK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group GTMSS_Register_Masks */

/*!
 * @}
 */ /* end of group GTMSS_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_GTMSS_H_) */
