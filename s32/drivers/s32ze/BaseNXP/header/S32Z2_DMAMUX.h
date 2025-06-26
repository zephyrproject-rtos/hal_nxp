/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_DMAMUX.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_DMAMUX
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
#if !defined(S32Z2_DMAMUX_H_)  /* Check if memory map has not been already included */
#define S32Z2_DMAMUX_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- DMAMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Peripheral_Access_Layer DMAMUX Peripheral Access Layer
 * @{
 */

/** DMAMUX - Size of Registers Arrays */
#define DMAMUX_CHCFG_COUNT                        32u

/** DMAMUX - Register Layout Typedef */
typedef struct {
  __IO uint8_t CHCFG[DMAMUX_CHCFG_COUNT];         /**< Channel Configuration, array offset: 0x0, array step: 0x1, irregular array, not all indices are valid */
} DMAMUX_Type, *DMAMUX_MemMapPtr;

/** Number of instances of the DMAMUX module. */
#define DMAMUX_INSTANCE_COUNT                    (6u)

/* DMAMUX - Peripheral instance base addresses */
/** Peripheral CE_DMAMUX base address */
#define IP_CE_DMAMUX_BASE                        (0x448D8000u)
/** Peripheral CE_DMAMUX base pointer */
#define IP_CE_DMAMUX                             ((DMAMUX_Type *)IP_CE_DMAMUX_BASE)
/** Peripheral DMAMUX_0A base address */
#define IP_DMAMUX_0A_BASE                        (0x405A0000u)
/** Peripheral DMAMUX_0A base pointer */
#define IP_DMAMUX_0A                             ((DMAMUX_Type *)IP_DMAMUX_0A_BASE)
/** Peripheral DMAMUX_0B base address */
#define IP_DMAMUX_0B_BASE                        (0x405B0000u)
/** Peripheral DMAMUX_0B base pointer */
#define IP_DMAMUX_0B                             ((DMAMUX_Type *)IP_DMAMUX_0B_BASE)
/** Peripheral DMAMUX_1 base address */
#define IP_DMAMUX_1_BASE                         (0x40DA0000u)
/** Peripheral DMAMUX_1 base pointer */
#define IP_DMAMUX_1                              ((DMAMUX_Type *)IP_DMAMUX_1_BASE)
/** Peripheral DMAMUX_4 base address */
#define IP_DMAMUX_4_BASE                         (0x425A0000u)
/** Peripheral DMAMUX_4 base pointer */
#define IP_DMAMUX_4                              ((DMAMUX_Type *)IP_DMAMUX_4_BASE)
/** Peripheral DMAMUX_5 base address */
#define IP_DMAMUX_5_BASE                         (0x42DA0000u)
/** Peripheral DMAMUX_5 base pointer */
#define IP_DMAMUX_5                              ((DMAMUX_Type *)IP_DMAMUX_5_BASE)
/** Array initializer of DMAMUX peripheral base addresses */
#define IP_DMAMUX_BASE_ADDRS                     { IP_CE_DMAMUX_BASE, IP_DMAMUX_0A_BASE, IP_DMAMUX_0B_BASE, IP_DMAMUX_1_BASE, IP_DMAMUX_4_BASE, IP_DMAMUX_5_BASE }
/** Array initializer of DMAMUX peripheral base pointers */
#define IP_DMAMUX_BASE_PTRS                      { IP_CE_DMAMUX, IP_DMAMUX_0A, IP_DMAMUX_0B, IP_DMAMUX_1, IP_DMAMUX_4, IP_DMAMUX_5 }

/* ----------------------------------------------------------------------------
   -- DMAMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Register_Masks DMAMUX Register Masks
 * @{
 */

/*! @name CHCONF - Channel Configuration */
/*! @{ */

#define DMAMUX_CHCONF_SOURCE_MASK                (0x3FU)
#define DMAMUX_CHCONF_SOURCE_SHIFT               (0U)
#define DMAMUX_CHCONF_SOURCE_WIDTH               (6U)
#define DMAMUX_CHCONF_SOURCE(x)                  (((uint8_t)(((uint8_t)(x)) << DMAMUX_CHCONF_SOURCE_SHIFT)) & DMAMUX_CHCONF_SOURCE_MASK)

#define DMAMUX_CHCONF_TRIG_MASK                  (0x40U)
#define DMAMUX_CHCONF_TRIG_SHIFT                 (6U)
#define DMAMUX_CHCONF_TRIG_WIDTH                 (1U)
#define DMAMUX_CHCONF_TRIG(x)                    (((uint8_t)(((uint8_t)(x)) << DMAMUX_CHCONF_TRIG_SHIFT)) & DMAMUX_CHCONF_TRIG_MASK)

#define DMAMUX_CHCONF_ENBL_MASK                  (0x80U)
#define DMAMUX_CHCONF_ENBL_SHIFT                 (7U)
#define DMAMUX_CHCONF_ENBL_WIDTH                 (1U)
#define DMAMUX_CHCONF_ENBL(x)                    (((uint8_t)(((uint8_t)(x)) << DMAMUX_CHCONF_ENBL_SHIFT)) & DMAMUX_CHCONF_ENBL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group DMAMUX_Register_Masks */

/*!
 * @}
 */ /* end of group DMAMUX_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_DMAMUX_H_) */
