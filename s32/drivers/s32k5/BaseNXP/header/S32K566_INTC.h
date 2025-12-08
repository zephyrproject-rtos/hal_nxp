/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_INTC.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_INTC
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
#if !defined(S32K566_INTC_H_)  /* Check if memory map has not been already included */
#define S32K566_INTC_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- INTC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INTC_Peripheral_Access_Layer INTC Peripheral Access Layer
 * @{
 */

/** INTC - Size of Registers Arrays */
#define INTC_CPRN_COUNT                           1u
#define INTC_IACKRN_COUNT                         1u
#define INTC_EOIRN_COUNT                          1u
#define INTC_SSCIR_COUNT                          32u
#define INTC_PSR_COUNT                            1024u

/** INTC - Register Layout Typedef */
typedef struct INTC_Struct {
  __IO uint32_t BCR;                               /**< Block Configuration, offset: 0x0 */
  uint8_t RESERVED_0[12];
  __IO uint32_t CPR[INTC_CPRN_COUNT];              /**< Current Priority, array offset: 0x10, array step: 0x4 */
  uint8_t RESERVED_1[12];
  __IO uint32_t IACKR[INTC_IACKRN_COUNT];          /**< Interrupt Acknowledge, array offset: 0x20, array step: 0x4 */
  uint8_t RESERVED_2[12];
  __O  uint32_t EOIR[INTC_EOIRN_COUNT];            /**< End Of Interrupt, array offset: 0x30, array step: 0x4 */
  uint8_t RESERVED_3[12];
  __IO uint8_t SSCIR[INTC_SSCIR_COUNT];            /**< Software Set/Clear Interrupt, array offset: 0x40, array step: 0x1 */
  __IO uint16_t PSR[INTC_PSR_COUNT];               /**< Priority Select, array offset: 0x60, array step: 0x2 */
} INTC_Type, *INTC_MemMapPtr;

/** Number of instances of the INTC module. */
#define INTC_INSTANCE_COUNT                      (1u)

/* INTC - Peripheral instance base addresses */
/** Peripheral DSP4__INTC base address */
#define IP_DSP4__INTC_BASE                       (0x42600000u)
/** Peripheral DSP4__INTC base pointer */
#define IP_DSP4__INTC                            ((INTC_Type *)IP_DSP4__INTC_BASE)
/** Array initializer of INTC peripheral base addresses */
#define IP_INTC_BASE_ADDRS                       { IP_DSP4__INTC_BASE }
/** Array initializer of INTC peripheral base pointers */
#define IP_INTC_BASE_PTRS                        { IP_DSP4__INTC }

/* ----------------------------------------------------------------------------
   -- INTC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INTC_Register_Masks INTC Register Masks
 * @{
 */

/*! @name BCR - Block Configuration */
/*! @{ */

#define INTC_BCR_HVEN0_MASK                      (0x1U)
#define INTC_BCR_HVEN0_SHIFT                     (0U)
#define INTC_BCR_HVEN0_WIDTH                     (1U)
#define INTC_BCR_HVEN0(x)                        (((uint32_t)(((uint32_t)(x)) << INTC_BCR_HVEN0_SHIFT)) & INTC_BCR_HVEN0_MASK)
/*! @} */

/*! @name CPR - Current Priority */
/*! @{ */

#define INTC_CPR_PRI_MASK                        (0x3FU)
#define INTC_CPR_PRI_SHIFT                       (0U)
#define INTC_CPR_PRI_WIDTH                       (6U)
#define INTC_CPR_PRI(x)                          (((uint32_t)(((uint32_t)(x)) << INTC_CPR_PRI_SHIFT)) & INTC_CPR_PRI_MASK)
/*! @} */

/*! @name IACKR - Interrupt Acknowledge */
/*! @{ */

#define INTC_IACKR_INTVEC_MASK                   (0xFFCU)
#define INTC_IACKR_INTVEC_SHIFT                  (2U)
#define INTC_IACKR_INTVEC_WIDTH                  (10U)
#define INTC_IACKR_INTVEC(x)                     (((uint32_t)(((uint32_t)(x)) << INTC_IACKR_INTVEC_SHIFT)) & INTC_IACKR_INTVEC_MASK)

#define INTC_IACKR_VTBA_MASK                     (0xFFFFF000U)
#define INTC_IACKR_VTBA_SHIFT                    (12U)
#define INTC_IACKR_VTBA_WIDTH                    (20U)
#define INTC_IACKR_VTBA(x)                       (((uint32_t)(((uint32_t)(x)) << INTC_IACKR_VTBA_SHIFT)) & INTC_IACKR_VTBA_MASK)
/*! @} */

/*! @name EOIR - End Of Interrupt */
/*! @{ */

#define INTC_EOIR_EOI_MASK                       (0xFFFFFFFFU)
#define INTC_EOIR_EOI_SHIFT                      (0U)
#define INTC_EOIR_EOI_WIDTH                      (32U)
#define INTC_EOIR_EOI(x)                         (((uint32_t)(((uint32_t)(x)) << INTC_EOIR_EOI_SHIFT)) & INTC_EOIR_EOI_MASK)
/*! @} */

/*! @name SSCIR - Software Set/Clear Interrupt */
/*! @{ */

#define INTC_SSCIR_CLR_MASK                      (0x1U)
#define INTC_SSCIR_CLR_SHIFT                     (0U)
#define INTC_SSCIR_CLR_WIDTH                     (1U)
#define INTC_SSCIR_CLR(x)                        (((uint8_t)(((uint8_t)(x)) << INTC_SSCIR_CLR_SHIFT)) & INTC_SSCIR_CLR_MASK)

#define INTC_SSCIR_SET_MASK                      (0x2U)
#define INTC_SSCIR_SET_SHIFT                     (1U)
#define INTC_SSCIR_SET_WIDTH                     (1U)
#define INTC_SSCIR_SET(x)                        (((uint8_t)(((uint8_t)(x)) << INTC_SSCIR_SET_SHIFT)) & INTC_SSCIR_SET_MASK)
/*! @} */

/*! @name PSR - Priority Select */
/*! @{ */

#define INTC_PSR_PRIN_MASK                       (0x3FU)
#define INTC_PSR_PRIN_SHIFT                      (0U)
#define INTC_PSR_PRIN_WIDTH                      (6U)
#define INTC_PSR_PRIN(x)                         (((uint16_t)(((uint16_t)(x)) << INTC_PSR_PRIN_SHIFT)) & INTC_PSR_PRIN_MASK)

#define INTC_PSR_SWTN_MASK                       (0x100U)
#define INTC_PSR_SWTN_SHIFT                      (8U)
#define INTC_PSR_SWTN_WIDTH                      (1U)
#define INTC_PSR_SWTN(x)                         (((uint16_t)(((uint16_t)(x)) << INTC_PSR_SWTN_SHIFT)) & INTC_PSR_SWTN_MASK)

#define INTC_PSR_PRC_SELN0_MASK                  (0x8000U)
#define INTC_PSR_PRC_SELN0_SHIFT                 (15U)
#define INTC_PSR_PRC_SELN0_WIDTH                 (1U)
#define INTC_PSR_PRC_SELN0(x)                    (((uint16_t)(((uint16_t)(x)) << INTC_PSR_PRC_SELN0_SHIFT)) & INTC_PSR_PRC_SELN0_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group INTC_Register_Masks */

/*!
 * @}
 */ /* end of group INTC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_INTC_H_) */
