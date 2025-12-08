/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_K566_DSP_GPR.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_K566_DSP_GPR
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
#if !defined(S32K566_K566_DSP_GPR_H_)  /* Check if memory map has not been already included */
#define S32K566_K566_DSP_GPR_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- K566_DSP_GPR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup K566_DSP_GPR_Peripheral_Access_Layer K566_DSP_GPR Peripheral Access Layer
 * @{
 */

/** K566_DSP_GPR - Register Layout Typedef */
typedef struct K566_DSP_GPR_Struct {
  uint8_t RESERVED_0[8192];
  __IO uint32_t GPR_RWF_0;                         /**< Read Write FUNC 0, offset: 0x2000 */
  __IO uint32_t GPR_RWF_1;                         /**< Read Write FUNC 1, offset: 0x2004 */
  uint8_t RESERVED_1[2040];
  __I  uint32_t GPR_ROF_0;                         /**< Read Only FUNC 0, offset: 0x2800 */
} K566_DSP_GPR_Type, *K566_DSP_GPR_MemMapPtr;

/** Number of instances of the K566_DSP_GPR module. */
#define K566_DSP_GPR_INSTANCE_COUNT              (1u)

/* K566_DSP_GPR - Peripheral instance base addresses */
/** Peripheral DSP_GPR base address */
#define IP_DSP_GPR_BASE                          (0x40A60000u)
/** Peripheral DSP_GPR base pointer */
#define IP_DSP_GPR                               ((K566_DSP_GPR_Type *)IP_DSP_GPR_BASE)
/** Array initializer of K566_DSP_GPR peripheral base addresses */
#define IP_K566_DSP_GPR_BASE_ADDRS               { IP_DSP_GPR_BASE }
/** Array initializer of K566_DSP_GPR peripheral base pointers */
#define IP_K566_DSP_GPR_BASE_PTRS                { IP_DSP_GPR }

/* ----------------------------------------------------------------------------
   -- K566_DSP_GPR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup K566_DSP_GPR_Register_Masks K566_DSP_GPR Register Masks
 * @{
 */

/*! @name GPR_RWF_0 - Read Write FUNC 0 */
/*! @{ */

#define K566_DSP_GPR_GPR_RWF_0_AXBS_INHIBIT_AHB_M_MASK (0x1U)
#define K566_DSP_GPR_GPR_RWF_0_AXBS_INHIBIT_AHB_M_SHIFT (0U)
#define K566_DSP_GPR_GPR_RWF_0_AXBS_INHIBIT_AHB_M_WIDTH (1U)
#define K566_DSP_GPR_GPR_RWF_0_AXBS_INHIBIT_AHB_M(x) (((uint32_t)(((uint32_t)(x)) << K566_DSP_GPR_GPR_RWF_0_AXBS_INHIBIT_AHB_M_SHIFT)) & K566_DSP_GPR_GPR_RWF_0_AXBS_INHIBIT_AHB_M_MASK)

#define K566_DSP_GPR_GPR_RWF_0_LOCK_EN0_MASK     (0x40000000U)
#define K566_DSP_GPR_GPR_RWF_0_LOCK_EN0_SHIFT    (30U)
#define K566_DSP_GPR_GPR_RWF_0_LOCK_EN0_WIDTH    (1U)
#define K566_DSP_GPR_GPR_RWF_0_LOCK_EN0(x)       (((uint32_t)(((uint32_t)(x)) << K566_DSP_GPR_GPR_RWF_0_LOCK_EN0_SHIFT)) & K566_DSP_GPR_GPR_RWF_0_LOCK_EN0_MASK)

#define K566_DSP_GPR_GPR_RWF_0_LOCK_EN1_MASK     (0x80000000U)
#define K566_DSP_GPR_GPR_RWF_0_LOCK_EN1_SHIFT    (31U)
#define K566_DSP_GPR_GPR_RWF_0_LOCK_EN1_WIDTH    (1U)
#define K566_DSP_GPR_GPR_RWF_0_LOCK_EN1(x)       (((uint32_t)(((uint32_t)(x)) << K566_DSP_GPR_GPR_RWF_0_LOCK_EN1_SHIFT)) & K566_DSP_GPR_GPR_RWF_0_LOCK_EN1_MASK)
/*! @} */

/*! @name GPR_RWF_1 - Read Write FUNC 1 */
/*! @{ */

#define K566_DSP_GPR_GPR_RWF_1_HALT_EN_MASK      (0x1U)
#define K566_DSP_GPR_GPR_RWF_1_HALT_EN_SHIFT     (0U)
#define K566_DSP_GPR_GPR_RWF_1_HALT_EN_WIDTH     (1U)
#define K566_DSP_GPR_GPR_RWF_1_HALT_EN(x)        (((uint32_t)(((uint32_t)(x)) << K566_DSP_GPR_GPR_RWF_1_HALT_EN_SHIFT)) & K566_DSP_GPR_GPR_RWF_1_HALT_EN_MASK)

#define K566_DSP_GPR_GPR_RWF_1_STOP_EN_MASK      (0x2U)
#define K566_DSP_GPR_GPR_RWF_1_STOP_EN_SHIFT     (1U)
#define K566_DSP_GPR_GPR_RWF_1_STOP_EN_WIDTH     (1U)
#define K566_DSP_GPR_GPR_RWF_1_STOP_EN(x)        (((uint32_t)(((uint32_t)(x)) << K566_DSP_GPR_GPR_RWF_1_STOP_EN_SHIFT)) & K566_DSP_GPR_GPR_RWF_1_STOP_EN_MASK)

#define K566_DSP_GPR_GPR_RWF_1_P_RESET_MASK      (0x100U)
#define K566_DSP_GPR_GPR_RWF_1_P_RESET_SHIFT     (8U)
#define K566_DSP_GPR_GPR_RWF_1_P_RESET_WIDTH     (1U)
#define K566_DSP_GPR_GPR_RWF_1_P_RESET(x)        (((uint32_t)(((uint32_t)(x)) << K566_DSP_GPR_GPR_RWF_1_P_RESET_SHIFT)) & K566_DSP_GPR_GPR_RWF_1_P_RESET_MASK)

#define K566_DSP_GPR_GPR_RWF_1_AXBS_RESET_MASK   (0x200U)
#define K566_DSP_GPR_GPR_RWF_1_AXBS_RESET_SHIFT  (9U)
#define K566_DSP_GPR_GPR_RWF_1_AXBS_RESET_WIDTH  (1U)
#define K566_DSP_GPR_GPR_RWF_1_AXBS_RESET(x)     (((uint32_t)(((uint32_t)(x)) << K566_DSP_GPR_GPR_RWF_1_AXBS_RESET_SHIFT)) & K566_DSP_GPR_GPR_RWF_1_AXBS_RESET_MASK)
/*! @} */

/*! @name GPR_ROF_0 - Read Only FUNC 0 */
/*! @{ */

#define K566_DSP_GPR_GPR_ROF_0_HALT_STATUS_MASK  (0x1U)
#define K566_DSP_GPR_GPR_ROF_0_HALT_STATUS_SHIFT (0U)
#define K566_DSP_GPR_GPR_ROF_0_HALT_STATUS_WIDTH (1U)
#define K566_DSP_GPR_GPR_ROF_0_HALT_STATUS(x)    (((uint32_t)(((uint32_t)(x)) << K566_DSP_GPR_GPR_ROF_0_HALT_STATUS_SHIFT)) & K566_DSP_GPR_GPR_ROF_0_HALT_STATUS_MASK)

#define K566_DSP_GPR_GPR_ROF_0_STOP_STATUS_MASK  (0x2U)
#define K566_DSP_GPR_GPR_ROF_0_STOP_STATUS_SHIFT (1U)
#define K566_DSP_GPR_GPR_ROF_0_STOP_STATUS_WIDTH (1U)
#define K566_DSP_GPR_GPR_ROF_0_STOP_STATUS(x)    (((uint32_t)(((uint32_t)(x)) << K566_DSP_GPR_GPR_ROF_0_STOP_STATUS_SHIFT)) & K566_DSP_GPR_GPR_ROF_0_STOP_STATUS_MASK)

#define K566_DSP_GPR_GPR_ROF_0_WAIT_STATUS_MASK  (0x4U)
#define K566_DSP_GPR_GPR_ROF_0_WAIT_STATUS_SHIFT (2U)
#define K566_DSP_GPR_GPR_ROF_0_WAIT_STATUS_WIDTH (1U)
#define K566_DSP_GPR_GPR_ROF_0_WAIT_STATUS(x)    (((uint32_t)(((uint32_t)(x)) << K566_DSP_GPR_GPR_ROF_0_WAIT_STATUS_SHIFT)) & K566_DSP_GPR_GPR_ROF_0_WAIT_STATUS_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group K566_DSP_GPR_Register_Masks */

/*!
 * @}
 */ /* end of group K566_DSP_GPR_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_K566_DSP_GPR_H_) */
