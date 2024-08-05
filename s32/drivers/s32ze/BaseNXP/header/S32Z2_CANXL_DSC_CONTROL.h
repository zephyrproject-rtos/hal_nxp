/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_CANXL_DSC_CONTROL.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_CANXL_DSC_CONTROL
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
#if !defined(S32Z2_CANXL_DSC_CONTROL_H_)  /* Check if memory map has not been already included */
#define S32Z2_CANXL_DSC_CONTROL_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CANXL_DSC_CONTROL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CANXL_DSC_CONTROL_Peripheral_Access_Layer CANXL_DSC_CONTROL Peripheral Access Layer
 * @{
 */

/** CANXL_DSC_CONTROL - Size of Registers Arrays */
#define CANXL_DSC_CONTROL_DSCMBCTRLAR_COUNT       128u

/** CANXL_DSC_CONTROL - Register Layout Typedef */
typedef struct {
  struct CANXL_DSC_CONTROL_DSCMBCTRLAR {           /* offset: 0x0, array step: 0x20 */
    __I  uint32_t DCSTA;                             /**< Descriptor Control Status, array offset: 0x0, array step: 0x20 */
    __IO uint32_t DCSYSPUSH;                         /**< Descriptor Control System Push, array offset: 0x4, array step: 0x20 */
    __IO uint32_t DCSYSLOCK;                         /**< Descriptor Control System Lock, array offset: 0x8, array step: 0x20 */
    uint8_t RESERVED_0[8];
    __IO uint32_t DCACT;                             /**< Descriptor Control Activation, array offset: 0x14, array step: 0x20 */
    uint8_t RESERVED_1[8];
  } DSCMBCTRLAR[CANXL_DSC_CONTROL_DSCMBCTRLAR_COUNT];
} CANXL_DSC_CONTROL_Type, *CANXL_DSC_CONTROL_MemMapPtr;

/** Number of instances of the CANXL_DSC_CONTROL module. */
#define CANXL_DSC_CONTROL_INSTANCE_COUNT         (2u)

/* CANXL_DSC_CONTROL - Peripheral instance base addresses */
/** Peripheral CANXL_0__DSC_CONTROL base address */
#define IP_CANXL_0__DSC_CONTROL_BASE             (0x47424000u)
/** Peripheral CANXL_0__DSC_CONTROL base pointer */
#define IP_CANXL_0__DSC_CONTROL                  ((CANXL_DSC_CONTROL_Type *)IP_CANXL_0__DSC_CONTROL_BASE)
/** Peripheral CANXL_1__DSC_CONTROL base address */
#define IP_CANXL_1__DSC_CONTROL_BASE             (0x47524000u)
/** Peripheral CANXL_1__DSC_CONTROL base pointer */
#define IP_CANXL_1__DSC_CONTROL                  ((CANXL_DSC_CONTROL_Type *)IP_CANXL_1__DSC_CONTROL_BASE)
/** Array initializer of CANXL_DSC_CONTROL peripheral base addresses */
#define IP_CANXL_DSC_CONTROL_BASE_ADDRS          { IP_CANXL_0__DSC_CONTROL_BASE, IP_CANXL_1__DSC_CONTROL_BASE }
/** Array initializer of CANXL_DSC_CONTROL peripheral base pointers */
#define IP_CANXL_DSC_CONTROL_BASE_PTRS           { IP_CANXL_0__DSC_CONTROL, IP_CANXL_1__DSC_CONTROL }

/* ----------------------------------------------------------------------------
   -- CANXL_DSC_CONTROL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CANXL_DSC_CONTROL_Register_Masks CANXL_DSC_CONTROL Register Masks
 * @{
 */

/*! @name DCSTA - Descriptor Control Status */
/*! @{ */

#define CANXL_DSC_CONTROL_DCSTA_STATE_MASK       (0x7U)
#define CANXL_DSC_CONTROL_DCSTA_STATE_SHIFT      (0U)
#define CANXL_DSC_CONTROL_DCSTA_STATE_WIDTH      (3U)
#define CANXL_DSC_CONTROL_DCSTA_STATE(x)         (((uint32_t)(((uint32_t)(x)) << CANXL_DSC_CONTROL_DCSTA_STATE_SHIFT)) & CANXL_DSC_CONTROL_DCSTA_STATE_MASK)

#define CANXL_DSC_CONTROL_DCSTA_HWLOCK_MASK      (0x40U)
#define CANXL_DSC_CONTROL_DCSTA_HWLOCK_SHIFT     (6U)
#define CANXL_DSC_CONTROL_DCSTA_HWLOCK_WIDTH     (1U)
#define CANXL_DSC_CONTROL_DCSTA_HWLOCK(x)        (((uint32_t)(((uint32_t)(x)) << CANXL_DSC_CONTROL_DCSTA_HWLOCK_SHIFT)) & CANXL_DSC_CONTROL_DCSTA_HWLOCK_MASK)

#define CANXL_DSC_CONTROL_DCSTA_SYSLOCK_MASK     (0x80U)
#define CANXL_DSC_CONTROL_DCSTA_SYSLOCK_SHIFT    (7U)
#define CANXL_DSC_CONTROL_DCSTA_SYSLOCK_WIDTH    (1U)
#define CANXL_DSC_CONTROL_DCSTA_SYSLOCK(x)       (((uint32_t)(((uint32_t)(x)) << CANXL_DSC_CONTROL_DCSTA_SYSLOCK_SHIFT)) & CANXL_DSC_CONTROL_DCSTA_SYSLOCK_MASK)

#define CANXL_DSC_CONTROL_DCSTA_HWPOINTER_MASK   (0x1F00U)
#define CANXL_DSC_CONTROL_DCSTA_HWPOINTER_SHIFT  (8U)
#define CANXL_DSC_CONTROL_DCSTA_HWPOINTER_WIDTH  (5U)
#define CANXL_DSC_CONTROL_DCSTA_HWPOINTER(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_DSC_CONTROL_DCSTA_HWPOINTER_SHIFT)) & CANXL_DSC_CONTROL_DCSTA_HWPOINTER_MASK)

#define CANXL_DSC_CONTROL_DCSTA_SYSPOINTER_MASK  (0x1F0000U)
#define CANXL_DSC_CONTROL_DCSTA_SYSPOINTER_SHIFT (16U)
#define CANXL_DSC_CONTROL_DCSTA_SYSPOINTER_WIDTH (5U)
#define CANXL_DSC_CONTROL_DCSTA_SYSPOINTER(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_DSC_CONTROL_DCSTA_SYSPOINTER_SHIFT)) & CANXL_DSC_CONTROL_DCSTA_SYSPOINTER_MASK)

#define CANXL_DSC_CONTROL_DCSTA_WTMARK_MASK      (0xF000000U)
#define CANXL_DSC_CONTROL_DCSTA_WTMARK_SHIFT     (24U)
#define CANXL_DSC_CONTROL_DCSTA_WTMARK_WIDTH     (4U)
#define CANXL_DSC_CONTROL_DCSTA_WTMARK(x)        (((uint32_t)(((uint32_t)(x)) << CANXL_DSC_CONTROL_DCSTA_WTMARK_SHIFT)) & CANXL_DSC_CONTROL_DCSTA_WTMARK_MASK)
/*! @} */

/*! @name DCSYSPUSH - Descriptor Control System Push */
/*! @{ */

#define CANXL_DSC_CONTROL_DCSYSPUSH_PUSH_MASK    (0xFU)
#define CANXL_DSC_CONTROL_DCSYSPUSH_PUSH_SHIFT   (0U)
#define CANXL_DSC_CONTROL_DCSYSPUSH_PUSH_WIDTH   (4U)
#define CANXL_DSC_CONTROL_DCSYSPUSH_PUSH(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_DSC_CONTROL_DCSYSPUSH_PUSH_SHIFT)) & CANXL_DSC_CONTROL_DCSYSPUSH_PUSH_MASK)
/*! @} */

/*! @name DCSYSLOCK - Descriptor Control System Lock */
/*! @{ */

#define CANXL_DSC_CONTROL_DCSYSLOCK_SYSLOCK_MASK (0x1U)
#define CANXL_DSC_CONTROL_DCSYSLOCK_SYSLOCK_SHIFT (0U)
#define CANXL_DSC_CONTROL_DCSYSLOCK_SYSLOCK_WIDTH (1U)
#define CANXL_DSC_CONTROL_DCSYSLOCK_SYSLOCK(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_DSC_CONTROL_DCSYSLOCK_SYSLOCK_SHIFT)) & CANXL_DSC_CONTROL_DCSYSLOCK_SYSLOCK_MASK)
/*! @} */

/*! @name DCACT - Descriptor Control Activation */
/*! @{ */

#define CANXL_DSC_CONTROL_DCACT_ACT_MASK         (0x1U)
#define CANXL_DSC_CONTROL_DCACT_ACT_SHIFT        (0U)
#define CANXL_DSC_CONTROL_DCACT_ACT_WIDTH        (1U)
#define CANXL_DSC_CONTROL_DCACT_ACT(x)           (((uint32_t)(((uint32_t)(x)) << CANXL_DSC_CONTROL_DCACT_ACT_SHIFT)) & CANXL_DSC_CONTROL_DCACT_ACT_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CANXL_DSC_CONTROL_Register_Masks */

/*!
 * @}
 */ /* end of group CANXL_DSC_CONTROL_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_CANXL_DSC_CONTROL_H_) */
