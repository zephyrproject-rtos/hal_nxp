/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_SXOSC.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_SXOSC
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
#if !defined(S32K566_SXOSC_H_)  /* Check if memory map has not been already included */
#define S32K566_SXOSC_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SXOSC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SXOSC_Peripheral_Access_Layer SXOSC Peripheral Access Layer
 * @{
 */

/** SXOSC - Register Layout Typedef */
typedef struct SXOSC_Struct {
  __IO uint32_t CTRL;                              /**< Oscillator Control Register, offset: 0x0 */
  __I  uint32_t STAT;                              /**< Oscillator Status Register, offset: 0x4 */
} SXOSC_Type, *SXOSC_MemMapPtr;

/** Number of instances of the SXOSC module. */
#define SXOSC_INSTANCE_COUNT                     (1u)

/* SXOSC - Peripheral instance base addresses */
/** Peripheral LPE_SXOSC base address */
#define IP_LPE_SXOSC_BASE                        (0x42118000u)
/** Peripheral LPE_SXOSC base pointer */
#define IP_LPE_SXOSC                             ((SXOSC_Type *)IP_LPE_SXOSC_BASE)
/** Array initializer of SXOSC peripheral base addresses */
#define IP_SXOSC_BASE_ADDRS                      { IP_LPE_SXOSC_BASE }
/** Array initializer of SXOSC peripheral base pointers */
#define IP_SXOSC_BASE_PTRS                       { IP_LPE_SXOSC }

/* ----------------------------------------------------------------------------
   -- SXOSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SXOSC_Register_Masks SXOSC Register Masks
 * @{
 */

/*! @name CTRL - Oscillator Control Register */
/*! @{ */

#define SXOSC_CTRL_OSCON_MASK                    (0x1U)
#define SXOSC_CTRL_OSCON_SHIFT                   (0U)
#define SXOSC_CTRL_OSCON_WIDTH                   (1U)
#define SXOSC_CTRL_OSCON(x)                      (((uint32_t)(((uint32_t)(x)) << SXOSC_CTRL_OSCON_SHIFT)) & SXOSC_CTRL_OSCON_MASK)

#define SXOSC_CTRL_GM_SEL_MASK                   (0xE0U)
#define SXOSC_CTRL_GM_SEL_SHIFT                  (5U)
#define SXOSC_CTRL_GM_SEL_WIDTH                  (3U)
#define SXOSC_CTRL_GM_SEL(x)                     (((uint32_t)(((uint32_t)(x)) << SXOSC_CTRL_GM_SEL_SHIFT)) & SXOSC_CTRL_GM_SEL_MASK)

#define SXOSC_CTRL_EOCV_MASK                     (0xFF0000U)
#define SXOSC_CTRL_EOCV_SHIFT                    (16U)
#define SXOSC_CTRL_EOCV_WIDTH                    (8U)
#define SXOSC_CTRL_EOCV(x)                       (((uint32_t)(((uint32_t)(x)) << SXOSC_CTRL_EOCV_SHIFT)) & SXOSC_CTRL_EOCV_MASK)

#define SXOSC_CTRL_CURR_PRG_MASK                 (0x7000000U)
#define SXOSC_CTRL_CURR_PRG_SHIFT                (24U)
#define SXOSC_CTRL_CURR_PRG_WIDTH                (3U)
#define SXOSC_CTRL_CURR_PRG(x)                   (((uint32_t)(((uint32_t)(x)) << SXOSC_CTRL_CURR_PRG_SHIFT)) & SXOSC_CTRL_CURR_PRG_MASK)
/*! @} */

/*! @name STAT - Oscillator Status Register */
/*! @{ */

#define SXOSC_STAT_OSC_STAT_MASK                 (0x80000000U)
#define SXOSC_STAT_OSC_STAT_SHIFT                (31U)
#define SXOSC_STAT_OSC_STAT_WIDTH                (1U)
#define SXOSC_STAT_OSC_STAT(x)                   (((uint32_t)(((uint32_t)(x)) << SXOSC_STAT_OSC_STAT_SHIFT)) & SXOSC_STAT_OSC_STAT_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SXOSC_Register_Masks */

/*!
 * @}
 */ /* end of group SXOSC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_SXOSC_H_) */
