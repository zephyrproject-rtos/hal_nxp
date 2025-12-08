/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_ieprc_prb.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_ieprc_prb
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
#if !defined(S32K566_ieprc_prb_H_)  /* Check if memory map has not been already included */
#define S32K566_ieprc_prb_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- ieprc_prb Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ieprc_prb_Peripheral_Access_Layer ieprc_prb Peripheral Access Layer
 * @{
 */

/** ieprc_prb - Size of Registers Arrays */
#define ieprc_prb_BUSX_COUNT                      2u

/** ieprc_prb - Register Layout Typedef */
typedef struct ieprc_prb_Struct {
  __IO uint32_t RR;                                /**< Reset register, offset: 0x0 */
  uint8_t RESERVED_0[252];
  __IO uint32_t EC_RR[ieprc_prb_BUSX_COUNT];       /**< EC Reset register, array offset: 0x100, array step: 0x4 */
} ieprc_prb_Type, *ieprc_prb_MemMapPtr;

/** Number of instances of the ieprc_prb module. */
#define ieprc_prb_INSTANCE_COUNT                 (1u)

/* ieprc_prb - Peripheral instance base addresses */
/** Peripheral IEPRC_1__IEPRC_PRB base address */
#define IP_IEPRC_1__IEPRC_PRB_BASE               (0x40130000u)
/** Peripheral IEPRC_1__IEPRC_PRB base pointer */
#define IP_IEPRC_1__IEPRC_PRB                    ((ieprc_prb_Type *)IP_IEPRC_1__IEPRC_PRB_BASE)
/** Array initializer of ieprc_prb peripheral base addresses */
#define IP_ieprc_prb_BASE_ADDRS                  { IP_IEPRC_1__IEPRC_PRB_BASE }
/** Array initializer of ieprc_prb peripheral base pointers */
#define IP_ieprc_prb_BASE_PTRS                   { IP_IEPRC_1__IEPRC_PRB }

/* ----------------------------------------------------------------------------
   -- ieprc_prb Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ieprc_prb_Register_Masks ieprc_prb Register Masks
 * @{
 */

/*! @name RR - Reset register */
/*! @{ */

#define ieprc_prb_RR_SR_MASK                     (0x1U)
#define ieprc_prb_RR_SR_SHIFT                    (0U)
#define ieprc_prb_RR_SR_WIDTH                    (1U)
#define ieprc_prb_RR_SR(x)                       (((uint32_t)(((uint32_t)(x)) << ieprc_prb_RR_SR_SHIFT)) & ieprc_prb_RR_SR_MASK)

#define ieprc_prb_RR_LOCK_MASK                   (0x2U)
#define ieprc_prb_RR_LOCK_SHIFT                  (1U)
#define ieprc_prb_RR_LOCK_WIDTH                  (1U)
#define ieprc_prb_RR_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << ieprc_prb_RR_LOCK_SHIFT)) & ieprc_prb_RR_LOCK_MASK)
/*! @} */

/*! @name EC_RR - EC Reset register */
/*! @{ */

#define ieprc_prb_EC_RR_ECSR_MASK                (0x1U)
#define ieprc_prb_EC_RR_ECSR_SHIFT               (0U)
#define ieprc_prb_EC_RR_ECSR_WIDTH               (1U)
#define ieprc_prb_EC_RR_ECSR(x)                  (((uint32_t)(((uint32_t)(x)) << ieprc_prb_EC_RR_ECSR_SHIFT)) & ieprc_prb_EC_RR_ECSR_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group ieprc_prb_Register_Masks */

/*!
 * @}
 */ /* end of group ieprc_prb_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_ieprc_prb_H_) */
