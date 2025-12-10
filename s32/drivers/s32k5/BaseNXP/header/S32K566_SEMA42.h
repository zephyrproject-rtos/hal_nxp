/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_SEMA42.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_SEMA42
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
#if !defined(S32K566_SEMA42_H_)  /* Check if memory map has not been already included */
#define S32K566_SEMA42_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SEMA42 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SEMA42_Peripheral_Access_Layer SEMA42 Peripheral Access Layer
 * @{
 */

/** SEMA42 - Size of Registers Arrays */
#define SEMA42_GATE_COUNT                         16u

/** SEMA42 - Register Layout Typedef */
typedef struct SEMA42_Struct {
  __IO uint8_t GATE[SEMA42_GATE_COUNT];            /**< Gate, array offset: 0x0, array step: 0x1 */
  uint8_t RESERVED_0[50];
  union {                                          /* offset: 0x42 */
    __I  uint16_t R;                                 /**< Reset Gate Read, offset: 0x42 */
    __O  uint16_t W;                                 /**< Reset Gate Write, offset: 0x42 */
  } RSTGT;
} SEMA42_Type, *SEMA42_MemMapPtr;

/** Number of instances of the SEMA42 module. */
#define SEMA42_INSTANCE_COUNT                    (4u)

/* SEMA42 - Peripheral instance base addresses */
/** Peripheral CPE_SEMA42 base address */
#define IP_CPE_SEMA42_BASE                       (0x41138000u)
/** Peripheral CPE_SEMA42 base pointer */
#define IP_CPE_SEMA42                            ((SEMA42_Type *)IP_CPE_SEMA42_BASE)
/** Peripheral LPE_SEMA42 base address */
#define IP_LPE_SEMA42_BASE                       (0x42078000u)
/** Peripheral LPE_SEMA42 base pointer */
#define IP_LPE_SEMA42                            ((SEMA42_Type *)IP_LPE_SEMA42_BASE)
/** Peripheral SEMA42_0 base address */
#define IP_SEMA42_0_BASE                         (0x40154000u)
/** Peripheral SEMA42_0 base pointer */
#define IP_SEMA42_0                              ((SEMA42_Type *)IP_SEMA42_0_BASE)
/** Peripheral SEMA42_1 base address */
#define IP_SEMA42_1_BASE                         (0x404A4000u)
/** Peripheral SEMA42_1 base pointer */
#define IP_SEMA42_1                              ((SEMA42_Type *)IP_SEMA42_1_BASE)
/** Array initializer of SEMA42 peripheral base addresses */
#define IP_SEMA42_BASE_ADDRS                     { IP_CPE_SEMA42_BASE, IP_LPE_SEMA42_BASE, IP_SEMA42_0_BASE, IP_SEMA42_1_BASE }
/** Array initializer of SEMA42 peripheral base pointers */
#define IP_SEMA42_BASE_PTRS                      { IP_CPE_SEMA42, IP_LPE_SEMA42, IP_SEMA42_0, IP_SEMA42_1 }

/* ----------------------------------------------------------------------------
   -- SEMA42 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SEMA42_Register_Masks SEMA42 Register Masks
 * @{
 */

/*! @name GATE - Gate */
/*! @{ */

#define SEMA42_GATE_GTFSM_MASK                   (0xFU)
#define SEMA42_GATE_GTFSM_SHIFT                  (0U)
#define SEMA42_GATE_GTFSM_WIDTH                  (4U)
#define SEMA42_GATE_GTFSM(x)                     (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE_GTFSM_SHIFT)) & SEMA42_GATE_GTFSM_MASK)
/*! @} */

/*! @name R - Reset Gate Read */
/*! @{ */

#define SEMA42_R_RSTGTN_MASK                     (0xFFU)
#define SEMA42_R_RSTGTN_SHIFT                    (0U)
#define SEMA42_R_RSTGTN_WIDTH                    (8U)
#define SEMA42_R_RSTGTN(x)                       (((uint16_t)(((uint16_t)(x)) << SEMA42_R_RSTGTN_SHIFT)) & SEMA42_R_RSTGTN_MASK)

#define SEMA42_R_RSTGMS_MASK                     (0xF00U)
#define SEMA42_R_RSTGMS_SHIFT                    (8U)
#define SEMA42_R_RSTGMS_WIDTH                    (4U)
#define SEMA42_R_RSTGMS(x)                       (((uint16_t)(((uint16_t)(x)) << SEMA42_R_RSTGMS_SHIFT)) & SEMA42_R_RSTGMS_MASK)

#define SEMA42_R_RSTGSM_MASK                     (0x3000U)
#define SEMA42_R_RSTGSM_SHIFT                    (12U)
#define SEMA42_R_RSTGSM_WIDTH                    (2U)
#define SEMA42_R_RSTGSM(x)                       (((uint16_t)(((uint16_t)(x)) << SEMA42_R_RSTGSM_SHIFT)) & SEMA42_R_RSTGSM_MASK)
/*! @} */

/*! @name W - Reset Gate Write */
/*! @{ */

#define SEMA42_W_RSTGTN_MASK                     (0xFFU)
#define SEMA42_W_RSTGTN_SHIFT                    (0U)
#define SEMA42_W_RSTGTN_WIDTH                    (8U)
#define SEMA42_W_RSTGTN(x)                       (((uint16_t)(((uint16_t)(x)) << SEMA42_W_RSTGTN_SHIFT)) & SEMA42_W_RSTGTN_MASK)

#define SEMA42_W_RSTGDP_MASK                     (0xFF00U)
#define SEMA42_W_RSTGDP_SHIFT                    (8U)
#define SEMA42_W_RSTGDP_WIDTH                    (8U)
#define SEMA42_W_RSTGDP(x)                       (((uint16_t)(((uint16_t)(x)) << SEMA42_W_RSTGDP_SHIFT)) & SEMA42_W_RSTGDP_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SEMA42_Register_Masks */

/*!
 * @}
 */ /* end of group SEMA42_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_SEMA42_H_) */
