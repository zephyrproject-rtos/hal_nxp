/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z27_CE_DMAMUX.h
 * @version 1.7
 * @date 2022-03-16
 * @brief Peripheral Access Layer for S32Z27_CE_DMAMUX
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
#if !defined(S32Z27_CE_DMAMUX_H_)  /* Check if memory map has not been already included */
#define S32Z27_CE_DMAMUX_H_

#include "S32Z27_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CE_DMAMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CE_DMAMUX_Peripheral_Access_Layer CE_DMAMUX Peripheral Access Layer
 * @{
 */

/** CE_DMAMUX - Size of Registers Arrays */
#define CE_DMAMUX_CHCFG_COUNT                     32u

/** CE_DMAMUX - Register Layout Typedef */
typedef struct {
  __IO uint8_t CHCONF[CE_DMAMUX_CHCFG_COUNT];      /**< Channel Configuration register, array offset: 0x0, array step: 0x1 */
} CE_DMAMUX_Type, *CE_DMAMUX_MemMapPtr;

/** Number of instances of the CE_DMAMUX module. */
#define CE_DMAMUX_INSTANCE_COUNT                 (1u)

/* CE_DMAMUX - Peripheral instance base addresses */
/** Peripheral CE_DMAMUX base address */
#define IP_CE_DMAMUX_BASE                        (0x448D8000u)
/** Peripheral CE_DMAMUX base pointer */
#define IP_CE_DMAMUX                             ((CE_DMAMUX_Type *)IP_CE_DMAMUX_BASE)
/** Array initializer of CE_DMAMUX peripheral base addresses */
#define IP_CE_DMAMUX_BASE_ADDRS                  { IP_CE_DMAMUX_BASE }
/** Array initializer of CE_DMAMUX peripheral base pointers */
#define IP_CE_DMAMUX_BASE_PTRS                   { IP_CE_DMAMUX }

/* ----------------------------------------------------------------------------
   -- CE_DMAMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CE_DMAMUX_Register_Masks CE_DMAMUX Register Masks
 * @{
 */

/*! @name CHCONF - Channel Configuration register */
/*! @{ */

#define CE_DMAMUX_CHCONF_SOURCE_MASK             (0x3FU)
#define CE_DMAMUX_CHCONF_SOURCE_SHIFT            (0U)
#define CE_DMAMUX_CHCONF_SOURCE_WIDTH            (6U)
#define CE_DMAMUX_CHCONF_SOURCE(x)               (((uint8_t)(((uint8_t)(x)) << CE_DMAMUX_CHCONF_SOURCE_SHIFT)) & CE_DMAMUX_CHCONF_SOURCE_MASK)

#define CE_DMAMUX_CHCONF_TRIG_MASK               (0x40U)
#define CE_DMAMUX_CHCONF_TRIG_SHIFT              (6U)
#define CE_DMAMUX_CHCONF_TRIG_WIDTH              (1U)
#define CE_DMAMUX_CHCONF_TRIG(x)                 (((uint8_t)(((uint8_t)(x)) << CE_DMAMUX_CHCONF_TRIG_SHIFT)) & CE_DMAMUX_CHCONF_TRIG_MASK)

#define CE_DMAMUX_CHCONF_ENBL_MASK               (0x80U)
#define CE_DMAMUX_CHCONF_ENBL_SHIFT              (7U)
#define CE_DMAMUX_CHCONF_ENBL_WIDTH              (1U)
#define CE_DMAMUX_CHCONF_ENBL(x)                 (((uint8_t)(((uint8_t)(x)) << CE_DMAMUX_CHCONF_ENBL_SHIFT)) & CE_DMAMUX_CHCONF_ENBL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CE_DMAMUX_Register_Masks */

/*!
 * @}
 */ /* end of group CE_DMAMUX_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z27_CE_DMAMUX_H_) */
