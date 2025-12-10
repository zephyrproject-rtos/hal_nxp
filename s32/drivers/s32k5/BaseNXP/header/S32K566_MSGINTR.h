/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_MSGINTR.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_MSGINTR
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
#if !defined(S32K566_MSGINTR_H_)  /* Check if memory map has not been already included */
#define S32K566_MSGINTR_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- MSGINTR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSGINTR_Peripheral_Access_Layer MSGINTR Peripheral Access Layer
 * @{
 */

/** MSGINTR - Register Layout Typedef */
typedef struct MSGINTR_Struct {
  __O  uint32_t MSIIR0;                            /**< Message Signaled Interrupt Index 0, offset: 0x0 */
  __I  uint32_t MSIR0;                             /**< Message Signaled Interrupt 0, offset: 0x4 */
  __O  uint32_t MSIIR1;                            /**< Message Signaled Interrupt Index 1, offset: 0x8 */
  __I  uint32_t MSIR1;                             /**< Message Signaled Interrupt 1, offset: 0xC */
  __O  uint32_t MSIIR2;                            /**< Message Signaled Interrupt Index 2, offset: 0x10 */
  __I  uint32_t MSIR2;                             /**< Message Signaled Interrupt 2, offset: 0x14 */
} MSGINTR_Type, *MSGINTR_MemMapPtr;

/** Number of instances of the MSGINTR module. */
#define MSGINTR_INSTANCE_COUNT                   (7u)

/* MSGINTR - Peripheral instance base addresses */
/** Peripheral MSGINTR_0 base address */
#define IP_MSGINTR_0_BASE                        (0x400F0000u)
/** Peripheral MSGINTR_0 base pointer */
#define IP_MSGINTR_0                             ((MSGINTR_Type *)IP_MSGINTR_0_BASE)
/** Peripheral MSGINTR_1 base address */
#define IP_MSGINTR_1_BASE                        (0x400F4000u)
/** Peripheral MSGINTR_1 base pointer */
#define IP_MSGINTR_1                             ((MSGINTR_Type *)IP_MSGINTR_1_BASE)
/** Peripheral MSGINTR_2 base address */
#define IP_MSGINTR_2_BASE                        (0x400F8000u)
/** Peripheral MSGINTR_2 base pointer */
#define IP_MSGINTR_2                             ((MSGINTR_Type *)IP_MSGINTR_2_BASE)
/** Peripheral MSGINTR_3 base address */
#define IP_MSGINTR_3_BASE                        (0x400FC000u)
/** Peripheral MSGINTR_3 base pointer */
#define IP_MSGINTR_3                             ((MSGINTR_Type *)IP_MSGINTR_3_BASE)
/** Peripheral MSGINTR_4 base address */
#define IP_MSGINTR_4_BASE                        (0x40100000u)
/** Peripheral MSGINTR_4 base pointer */
#define IP_MSGINTR_4                             ((MSGINTR_Type *)IP_MSGINTR_4_BASE)
/** Peripheral MSGINTR_5 base address */
#define IP_MSGINTR_5_BASE                        (0x40104000u)
/** Peripheral MSGINTR_5 base pointer */
#define IP_MSGINTR_5                             ((MSGINTR_Type *)IP_MSGINTR_5_BASE)
/** Peripheral MSGINTR_6 base address */
#define IP_MSGINTR_6_BASE                        (0x40108000u)
/** Peripheral MSGINTR_6 base pointer */
#define IP_MSGINTR_6                             ((MSGINTR_Type *)IP_MSGINTR_6_BASE)
/** Array initializer of MSGINTR peripheral base addresses */
#define IP_MSGINTR_BASE_ADDRS                    { IP_MSGINTR_0_BASE, IP_MSGINTR_1_BASE, IP_MSGINTR_2_BASE, IP_MSGINTR_3_BASE, IP_MSGINTR_4_BASE, IP_MSGINTR_5_BASE, IP_MSGINTR_6_BASE }
/** Array initializer of MSGINTR peripheral base pointers */
#define IP_MSGINTR_BASE_PTRS                     { IP_MSGINTR_0, IP_MSGINTR_1, IP_MSGINTR_2, IP_MSGINTR_3, IP_MSGINTR_4, IP_MSGINTR_5, IP_MSGINTR_6 }

/* ----------------------------------------------------------------------------
   -- MSGINTR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSGINTR_Register_Masks MSGINTR Register Masks
 * @{
 */

/*! @name MSIIR0 - Message Signaled Interrupt Index 0 */
/*! @{ */

#define MSGINTR_MSIIR0_IBS_MASK                  (0x1FU)
#define MSGINTR_MSIIR0_IBS_SHIFT                 (0U)
#define MSGINTR_MSIIR0_IBS_WIDTH                 (5U)
#define MSGINTR_MSIIR0_IBS(x)                    (((uint32_t)(((uint32_t)(x)) << MSGINTR_MSIIR0_IBS_SHIFT)) & MSGINTR_MSIIR0_IBS_MASK)
/*! @} */

/*! @name MSIR0 - Message Signaled Interrupt 0 */
/*! @{ */

#define MSGINTR_MSIR0_SHn_MASK                   (0xFFFFFFFFU)
#define MSGINTR_MSIR0_SHn_SHIFT                  (0U)
#define MSGINTR_MSIR0_SHn_WIDTH                  (32U)
#define MSGINTR_MSIR0_SHn(x)                     (((uint32_t)(((uint32_t)(x)) << MSGINTR_MSIR0_SHn_SHIFT)) & MSGINTR_MSIR0_SHn_MASK)
/*! @} */

/*! @name MSIIR1 - Message Signaled Interrupt Index 1 */
/*! @{ */

#define MSGINTR_MSIIR1_IBS_MASK                  (0x1FU)
#define MSGINTR_MSIIR1_IBS_SHIFT                 (0U)
#define MSGINTR_MSIIR1_IBS_WIDTH                 (5U)
#define MSGINTR_MSIIR1_IBS(x)                    (((uint32_t)(((uint32_t)(x)) << MSGINTR_MSIIR1_IBS_SHIFT)) & MSGINTR_MSIIR1_IBS_MASK)
/*! @} */

/*! @name MSIR1 - Message Signaled Interrupt 1 */
/*! @{ */

#define MSGINTR_MSIR1_SHn_MASK                   (0xFFFFFFFFU)
#define MSGINTR_MSIR1_SHn_SHIFT                  (0U)
#define MSGINTR_MSIR1_SHn_WIDTH                  (32U)
#define MSGINTR_MSIR1_SHn(x)                     (((uint32_t)(((uint32_t)(x)) << MSGINTR_MSIR1_SHn_SHIFT)) & MSGINTR_MSIR1_SHn_MASK)
/*! @} */

/*! @name MSIIR2 - Message Signaled Interrupt Index 2 */
/*! @{ */

#define MSGINTR_MSIIR2_IBS_MASK                  (0x1FU)
#define MSGINTR_MSIIR2_IBS_SHIFT                 (0U)
#define MSGINTR_MSIIR2_IBS_WIDTH                 (5U)
#define MSGINTR_MSIIR2_IBS(x)                    (((uint32_t)(((uint32_t)(x)) << MSGINTR_MSIIR2_IBS_SHIFT)) & MSGINTR_MSIIR2_IBS_MASK)
/*! @} */

/*! @name MSIR2 - Message Signaled Interrupt 2 */
/*! @{ */

#define MSGINTR_MSIR2_SHn_MASK                   (0xFFFFFFFFU)
#define MSGINTR_MSIR2_SHn_SHIFT                  (0U)
#define MSGINTR_MSIR2_SHn_WIDTH                  (32U)
#define MSGINTR_MSIR2_SHn(x)                     (((uint32_t)(((uint32_t)(x)) << MSGINTR_MSIR2_SHn_SHIFT)) & MSGINTR_MSIR2_SHn_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group MSGINTR_Register_Masks */

/*!
 * @}
 */ /* end of group MSGINTR_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_MSGINTR_H_) */
