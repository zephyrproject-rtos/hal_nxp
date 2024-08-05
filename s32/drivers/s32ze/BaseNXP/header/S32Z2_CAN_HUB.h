/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_CAN_HUB.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_CAN_HUB
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
#if !defined(S32Z2_CAN_HUB_H_)  /* Check if memory map has not been already included */
#define S32Z2_CAN_HUB_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CAN_HUB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_HUB_Peripheral_Access_Layer CAN_HUB Peripheral Access Layer
 * @{
 */

/** CAN_HUB - Register Layout Typedef */
typedef struct {
  __I  uint32_t CANNETW;                           /**< CAN Module Connected to Bus Flag, offset: 0x0 */
  uint8_t RESERVED_0[124];
  __I  uint32_t CAN0ALWGRP;                        /**< CAN0 Allowable Groups, offset: 0x80 */
  __I  uint32_t CAN1ALWGRP;                        /**< CAN1 Allowable Groups, offset: 0x84 */
  __I  uint32_t CAN2ALWGRP;                        /**< CAN2 Allowable Groups, offset: 0x88 */
  __I  uint32_t CAN3ALWGRP;                        /**< CAN3 Allowable Groups, offset: 0x8C */
  __I  uint32_t CAN4ALWGRP;                        /**< CAN4 Allowable Groups, offset: 0x90 */
  __I  uint32_t CAN5ALWGRP;                        /**< CAN5 Allowable Groups, offset: 0x94 */
  __I  uint32_t CAN6ALWGRP;                        /**< CAN6 Allowable Groups, offset: 0x98 */
  __I  uint32_t CAN7ALWGRP;                        /**< CAN7 Allowable Groups, offset: 0x9C */
  __I  uint32_t CAN8ALWGRP;                        /**< CAN8 Allowable Groups, offset: 0xA0 */
  __I  uint32_t CAN9ALWGRP;                        /**< CAN9 Allowable Groups, offset: 0xA4 */
  __I  uint32_t CAN10ALWGRP;                       /**< CAN10 Allowable Groups, offset: 0xA8 */
  __I  uint32_t CAN11ALWGRP;                       /**< CAN11 Allowable Groups, offset: 0xAC */
  __I  uint32_t CAN12ALWGRP;                       /**< CAN12 Allowable Groups, offset: 0xB0 */
  __I  uint32_t CAN13ALWGRP;                       /**< CAN13 Allowable Groups, offset: 0xB4 */
  __I  uint32_t CAN14ALWGRP;                       /**< CAN14 Allowable Groups, offset: 0xB8 */
  __I  uint32_t CAN15ALWGRP;                       /**< CAN15 Allowable Groups, offset: 0xBC */
  __I  uint32_t CAN16ALWGRP;                       /**< CAN16 Allowable Groups, offset: 0xC0 */
  __I  uint32_t CAN17ALWGRP;                       /**< CAN17 Allowable Groups, offset: 0xC4 */
  __I  uint32_t CAN18ALWGRP;                       /**< CAN18 Allowable Groups, offset: 0xC8 */
  __I  uint32_t CAN19ALWGRP;                       /**< CAN19 Allowable Groups, offset: 0xCC */
  __I  uint32_t CAN20ALWGRP;                       /**< CAN20 Allowable Groups, offset: 0xD0 */
  __I  uint32_t CAN21ALWGRP;                       /**< CAN21 Allowable Groups, offset: 0xD4 */
  __I  uint32_t CAN22ALWGRP;                       /**< CAN22 Allowable Groups, offset: 0xD8 */
  __I  uint32_t CAN23ALWGRP;                       /**< CAN23 Allowable Groups, offset: 0xDC */
  uint8_t RESERVED_1[32];
  __IO uint32_t CAN0GRPCTL;                        /**< CAN0 Module Group Control Register, offset: 0x100 */
  __IO uint32_t CAN1GRPCTL;                        /**< CAN1 Module Group Control Register, offset: 0x104 */
  __IO uint32_t CAN2GRPCTL;                        /**< CAN2 Module Group Control Register, offset: 0x108 */
  __IO uint32_t CAN3GRPCTL;                        /**< CAN3 Module Group Control Register, offset: 0x10C */
  __IO uint32_t CAN4GRPCTL;                        /**< CAN4 Module Group Control Register, offset: 0x110 */
  __IO uint32_t CAN5GRPCTL;                        /**< CAN5 Module Group Control Register, offset: 0x114 */
  __IO uint32_t CAN6GRPCTL;                        /**< CAN6 Module Group Control Register, offset: 0x118 */
  __IO uint32_t CAN7GRPCTL;                        /**< CAN7 Module Group Control Register, offset: 0x11C */
  __IO uint32_t CAN8GRPCTL;                        /**< CAN8 Module Group Control Register, offset: 0x120 */
  __IO uint32_t CAN9GRPCTL;                        /**< CAN9 Module Group Control Register, offset: 0x124 */
  __IO uint32_t CAN10GRPCTL;                       /**< CAN10 Module Group Control Register, offset: 0x128 */
  __IO uint32_t CAN11GRPCTL;                       /**< CAN11 Module Group Control Register, offset: 0x12C */
  __IO uint32_t CAN12GRPCTL;                       /**< CAN12 Module Group Control Register, offset: 0x130 */
  __IO uint32_t CAN13GRPCTL;                       /**< CAN13 Module Group Control Register, offset: 0x134 */
  __IO uint32_t CAN14GRPCTL;                       /**< CAN14 Module Group Control Register, offset: 0x138 */
  __IO uint32_t CAN15GRPCTL;                       /**< CAN15 Module Group Control Register, offset: 0x13C */
  __IO uint32_t CAN16GRPCTL;                       /**< CAN16 Module Group Control Register, offset: 0x140 */
  __IO uint32_t CAN17GRPCTL;                       /**< CAN17 Module Group Control Register, offset: 0x144 */
  __IO uint32_t CAN18GRPCTL;                       /**< CAN18 Module Group Control Register, offset: 0x148 */
  __IO uint32_t CAN19GRPCTL;                       /**< CAN19 Module Group Control Register, offset: 0x14C */
  __IO uint32_t CAN20GRPCTL;                       /**< CAN20 Module Group Control Register, offset: 0x150 */
  __IO uint32_t CAN21GRPCTL;                       /**< CAN21 Module Group Control Register, offset: 0x154 */
  __IO uint32_t CAN22GRPCTL;                       /**< CAN22 Module Group Control Register, offset: 0x158 */
  __IO uint32_t CAN23GRPCTL;                       /**< CAN23 Module Group Control Register, offset: 0x15C */
} CAN_HUB_Type, *CAN_HUB_MemMapPtr;

/** Number of instances of the CAN_HUB module. */
#define CAN_HUB_INSTANCE_COUNT                   (1u)

/* CAN_HUB - Peripheral instance base addresses */
/** Peripheral CE_CAN_HUB base address */
#define IP_CE_CAN_HUB_BASE                       (0x448BC000u)
/** Peripheral CE_CAN_HUB base pointer */
#define IP_CE_CAN_HUB                            ((CAN_HUB_Type *)IP_CE_CAN_HUB_BASE)
/** Array initializer of CAN_HUB peripheral base addresses */
#define IP_CAN_HUB_BASE_ADDRS                    { IP_CE_CAN_HUB_BASE }
/** Array initializer of CAN_HUB peripheral base pointers */
#define IP_CAN_HUB_BASE_PTRS                     { IP_CE_CAN_HUB }

/* ----------------------------------------------------------------------------
   -- CAN_HUB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_HUB_Register_Masks CAN_HUB Register Masks
 * @{
 */

/*! @name CANNETW - CAN Module Connected to Bus Flag */
/*! @{ */

#define CAN_HUB_CANNETW_STATUS_MASK              (0xFFFFFFU)
#define CAN_HUB_CANNETW_STATUS_SHIFT             (0U)
#define CAN_HUB_CANNETW_STATUS_WIDTH             (24U)
#define CAN_HUB_CANNETW_STATUS(x)                (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CANNETW_STATUS_SHIFT)) & CAN_HUB_CANNETW_STATUS_MASK)
/*! @} */

/*! @name CAN0ALWGRP - CAN0 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN0ALWGRP_ALWGRP_MASK           (0x7FFFFFFU)
#define CAN_HUB_CAN0ALWGRP_ALWGRP_SHIFT          (0U)
#define CAN_HUB_CAN0ALWGRP_ALWGRP_WIDTH          (27U)
#define CAN_HUB_CAN0ALWGRP_ALWGRP(x)             (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN0ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN0ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN1ALWGRP - CAN1 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN1ALWGRP_ALWGRP_MASK           (0x7FFFFFFU)
#define CAN_HUB_CAN1ALWGRP_ALWGRP_SHIFT          (0U)
#define CAN_HUB_CAN1ALWGRP_ALWGRP_WIDTH          (27U)
#define CAN_HUB_CAN1ALWGRP_ALWGRP(x)             (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN1ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN1ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN2ALWGRP - CAN2 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN2ALWGRP_ALWGRP_MASK           (0x7FFFFFFU)
#define CAN_HUB_CAN2ALWGRP_ALWGRP_SHIFT          (0U)
#define CAN_HUB_CAN2ALWGRP_ALWGRP_WIDTH          (27U)
#define CAN_HUB_CAN2ALWGRP_ALWGRP(x)             (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN2ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN2ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN3ALWGRP - CAN3 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN3ALWGRP_ALWGRP_MASK           (0x7FFFFFFU)
#define CAN_HUB_CAN3ALWGRP_ALWGRP_SHIFT          (0U)
#define CAN_HUB_CAN3ALWGRP_ALWGRP_WIDTH          (27U)
#define CAN_HUB_CAN3ALWGRP_ALWGRP(x)             (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN3ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN3ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN4ALWGRP - CAN4 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN4ALWGRP_ALWGRP_MASK           (0x7FFFFFFU)
#define CAN_HUB_CAN4ALWGRP_ALWGRP_SHIFT          (0U)
#define CAN_HUB_CAN4ALWGRP_ALWGRP_WIDTH          (27U)
#define CAN_HUB_CAN4ALWGRP_ALWGRP(x)             (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN4ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN4ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN5ALWGRP - CAN5 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN5ALWGRP_ALWGRP_MASK           (0x7FFFFFFU)
#define CAN_HUB_CAN5ALWGRP_ALWGRP_SHIFT          (0U)
#define CAN_HUB_CAN5ALWGRP_ALWGRP_WIDTH          (27U)
#define CAN_HUB_CAN5ALWGRP_ALWGRP(x)             (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN5ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN5ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN6ALWGRP - CAN6 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN6ALWGRP_ALWGRP_MASK           (0x7FFFFFFU)
#define CAN_HUB_CAN6ALWGRP_ALWGRP_SHIFT          (0U)
#define CAN_HUB_CAN6ALWGRP_ALWGRP_WIDTH          (27U)
#define CAN_HUB_CAN6ALWGRP_ALWGRP(x)             (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN6ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN6ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN7ALWGRP - CAN7 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN7ALWGRP_ALWGRP_MASK           (0x7FFFFFFU)
#define CAN_HUB_CAN7ALWGRP_ALWGRP_SHIFT          (0U)
#define CAN_HUB_CAN7ALWGRP_ALWGRP_WIDTH          (27U)
#define CAN_HUB_CAN7ALWGRP_ALWGRP(x)             (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN7ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN7ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN8ALWGRP - CAN8 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN8ALWGRP_ALWGRP_MASK           (0x7FFFFFFU)
#define CAN_HUB_CAN8ALWGRP_ALWGRP_SHIFT          (0U)
#define CAN_HUB_CAN8ALWGRP_ALWGRP_WIDTH          (27U)
#define CAN_HUB_CAN8ALWGRP_ALWGRP(x)             (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN8ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN8ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN9ALWGRP - CAN9 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN9ALWGRP_ALWGRP_MASK           (0x7FFFFFFU)
#define CAN_HUB_CAN9ALWGRP_ALWGRP_SHIFT          (0U)
#define CAN_HUB_CAN9ALWGRP_ALWGRP_WIDTH          (27U)
#define CAN_HUB_CAN9ALWGRP_ALWGRP(x)             (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN9ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN9ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN10ALWGRP - CAN10 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN10ALWGRP_ALWGRP_MASK          (0x7FFFFFFU)
#define CAN_HUB_CAN10ALWGRP_ALWGRP_SHIFT         (0U)
#define CAN_HUB_CAN10ALWGRP_ALWGRP_WIDTH         (27U)
#define CAN_HUB_CAN10ALWGRP_ALWGRP(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN10ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN10ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN11ALWGRP - CAN11 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN11ALWGRP_ALWGRP_MASK          (0x7FFFFFFU)
#define CAN_HUB_CAN11ALWGRP_ALWGRP_SHIFT         (0U)
#define CAN_HUB_CAN11ALWGRP_ALWGRP_WIDTH         (27U)
#define CAN_HUB_CAN11ALWGRP_ALWGRP(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN11ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN11ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN12ALWGRP - CAN12 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN12ALWGRP_ALWGRP_MASK          (0x7FFFFFFU)
#define CAN_HUB_CAN12ALWGRP_ALWGRP_SHIFT         (0U)
#define CAN_HUB_CAN12ALWGRP_ALWGRP_WIDTH         (27U)
#define CAN_HUB_CAN12ALWGRP_ALWGRP(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN12ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN12ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN13ALWGRP - CAN13 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN13ALWGRP_ALWGRP_MASK          (0x7FFFFFFU)
#define CAN_HUB_CAN13ALWGRP_ALWGRP_SHIFT         (0U)
#define CAN_HUB_CAN13ALWGRP_ALWGRP_WIDTH         (27U)
#define CAN_HUB_CAN13ALWGRP_ALWGRP(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN13ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN13ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN14ALWGRP - CAN14 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN14ALWGRP_ALWGRP_MASK          (0x7FFFFFFU)
#define CAN_HUB_CAN14ALWGRP_ALWGRP_SHIFT         (0U)
#define CAN_HUB_CAN14ALWGRP_ALWGRP_WIDTH         (27U)
#define CAN_HUB_CAN14ALWGRP_ALWGRP(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN14ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN14ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN15ALWGRP - CAN15 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN15ALWGRP_ALWGRP_MASK          (0x7FFFFFFU)
#define CAN_HUB_CAN15ALWGRP_ALWGRP_SHIFT         (0U)
#define CAN_HUB_CAN15ALWGRP_ALWGRP_WIDTH         (27U)
#define CAN_HUB_CAN15ALWGRP_ALWGRP(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN15ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN15ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN16ALWGRP - CAN16 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN16ALWGRP_ALWGRP_MASK          (0x7FFFFFFU)
#define CAN_HUB_CAN16ALWGRP_ALWGRP_SHIFT         (0U)
#define CAN_HUB_CAN16ALWGRP_ALWGRP_WIDTH         (27U)
#define CAN_HUB_CAN16ALWGRP_ALWGRP(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN16ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN16ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN17ALWGRP - CAN17 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN17ALWGRP_ALWGRP_MASK          (0x7FFFFFFU)
#define CAN_HUB_CAN17ALWGRP_ALWGRP_SHIFT         (0U)
#define CAN_HUB_CAN17ALWGRP_ALWGRP_WIDTH         (27U)
#define CAN_HUB_CAN17ALWGRP_ALWGRP(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN17ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN17ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN18ALWGRP - CAN18 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN18ALWGRP_ALWGRP_MASK          (0x7FFFFFFU)
#define CAN_HUB_CAN18ALWGRP_ALWGRP_SHIFT         (0U)
#define CAN_HUB_CAN18ALWGRP_ALWGRP_WIDTH         (27U)
#define CAN_HUB_CAN18ALWGRP_ALWGRP(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN18ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN18ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN19ALWGRP - CAN19 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN19ALWGRP_ALWGRP_MASK          (0x7FFFFFFU)
#define CAN_HUB_CAN19ALWGRP_ALWGRP_SHIFT         (0U)
#define CAN_HUB_CAN19ALWGRP_ALWGRP_WIDTH         (27U)
#define CAN_HUB_CAN19ALWGRP_ALWGRP(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN19ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN19ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN20ALWGRP - CAN20 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN20ALWGRP_ALWGRP_MASK          (0x7FFFFFFU)
#define CAN_HUB_CAN20ALWGRP_ALWGRP_SHIFT         (0U)
#define CAN_HUB_CAN20ALWGRP_ALWGRP_WIDTH         (27U)
#define CAN_HUB_CAN20ALWGRP_ALWGRP(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN20ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN20ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN21ALWGRP - CAN21 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN21ALWGRP_ALWGRP_MASK          (0x7FFFFFFU)
#define CAN_HUB_CAN21ALWGRP_ALWGRP_SHIFT         (0U)
#define CAN_HUB_CAN21ALWGRP_ALWGRP_WIDTH         (27U)
#define CAN_HUB_CAN21ALWGRP_ALWGRP(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN21ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN21ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN22ALWGRP - CAN22 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN22ALWGRP_ALWGRP_MASK          (0x7FFFFFFU)
#define CAN_HUB_CAN22ALWGRP_ALWGRP_SHIFT         (0U)
#define CAN_HUB_CAN22ALWGRP_ALWGRP_WIDTH         (27U)
#define CAN_HUB_CAN22ALWGRP_ALWGRP(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN22ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN22ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN23ALWGRP - CAN23 Allowable Groups */
/*! @{ */

#define CAN_HUB_CAN23ALWGRP_ALWGRP_MASK          (0x7FFFFFFU)
#define CAN_HUB_CAN23ALWGRP_ALWGRP_SHIFT         (0U)
#define CAN_HUB_CAN23ALWGRP_ALWGRP_WIDTH         (27U)
#define CAN_HUB_CAN23ALWGRP_ALWGRP(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN23ALWGRP_ALWGRP_SHIFT)) & CAN_HUB_CAN23ALWGRP_ALWGRP_MASK)
/*! @} */

/*! @name CAN0GRPCTL - CAN0 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN0GRPCTL_USECANBUS_MASK        (0x1FU)
#define CAN_HUB_CAN0GRPCTL_USECANBUS_SHIFT       (0U)
#define CAN_HUB_CAN0GRPCTL_USECANBUS_WIDTH       (5U)
#define CAN_HUB_CAN0GRPCTL_USECANBUS(x)          (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN0GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN0GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN0GRPCTL_HWFLTR_MASK           (0x3F0000U)
#define CAN_HUB_CAN0GRPCTL_HWFLTR_SHIFT          (16U)
#define CAN_HUB_CAN0GRPCTL_HWFLTR_WIDTH          (6U)
#define CAN_HUB_CAN0GRPCTL_HWFLTR(x)             (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN0GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN0GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN1GRPCTL - CAN1 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN1GRPCTL_USECANBUS_MASK        (0x1FU)
#define CAN_HUB_CAN1GRPCTL_USECANBUS_SHIFT       (0U)
#define CAN_HUB_CAN1GRPCTL_USECANBUS_WIDTH       (5U)
#define CAN_HUB_CAN1GRPCTL_USECANBUS(x)          (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN1GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN1GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN1GRPCTL_HWFLTR_MASK           (0x3F0000U)
#define CAN_HUB_CAN1GRPCTL_HWFLTR_SHIFT          (16U)
#define CAN_HUB_CAN1GRPCTL_HWFLTR_WIDTH          (6U)
#define CAN_HUB_CAN1GRPCTL_HWFLTR(x)             (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN1GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN1GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN2GRPCTL - CAN2 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN2GRPCTL_USECANBUS_MASK        (0x1FU)
#define CAN_HUB_CAN2GRPCTL_USECANBUS_SHIFT       (0U)
#define CAN_HUB_CAN2GRPCTL_USECANBUS_WIDTH       (5U)
#define CAN_HUB_CAN2GRPCTL_USECANBUS(x)          (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN2GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN2GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN2GRPCTL_HWFLTR_MASK           (0x3F0000U)
#define CAN_HUB_CAN2GRPCTL_HWFLTR_SHIFT          (16U)
#define CAN_HUB_CAN2GRPCTL_HWFLTR_WIDTH          (6U)
#define CAN_HUB_CAN2GRPCTL_HWFLTR(x)             (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN2GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN2GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN3GRPCTL - CAN3 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN3GRPCTL_USECANBUS_MASK        (0x1FU)
#define CAN_HUB_CAN3GRPCTL_USECANBUS_SHIFT       (0U)
#define CAN_HUB_CAN3GRPCTL_USECANBUS_WIDTH       (5U)
#define CAN_HUB_CAN3GRPCTL_USECANBUS(x)          (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN3GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN3GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN3GRPCTL_HWFLTR_MASK           (0x3F0000U)
#define CAN_HUB_CAN3GRPCTL_HWFLTR_SHIFT          (16U)
#define CAN_HUB_CAN3GRPCTL_HWFLTR_WIDTH          (6U)
#define CAN_HUB_CAN3GRPCTL_HWFLTR(x)             (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN3GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN3GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN4GRPCTL - CAN4 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN4GRPCTL_USECANBUS_MASK        (0x1FU)
#define CAN_HUB_CAN4GRPCTL_USECANBUS_SHIFT       (0U)
#define CAN_HUB_CAN4GRPCTL_USECANBUS_WIDTH       (5U)
#define CAN_HUB_CAN4GRPCTL_USECANBUS(x)          (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN4GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN4GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN4GRPCTL_HWFLTR_MASK           (0x3F0000U)
#define CAN_HUB_CAN4GRPCTL_HWFLTR_SHIFT          (16U)
#define CAN_HUB_CAN4GRPCTL_HWFLTR_WIDTH          (6U)
#define CAN_HUB_CAN4GRPCTL_HWFLTR(x)             (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN4GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN4GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN5GRPCTL - CAN5 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN5GRPCTL_USECANBUS_MASK        (0x1FU)
#define CAN_HUB_CAN5GRPCTL_USECANBUS_SHIFT       (0U)
#define CAN_HUB_CAN5GRPCTL_USECANBUS_WIDTH       (5U)
#define CAN_HUB_CAN5GRPCTL_USECANBUS(x)          (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN5GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN5GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN5GRPCTL_HWFLTR_MASK           (0x3F0000U)
#define CAN_HUB_CAN5GRPCTL_HWFLTR_SHIFT          (16U)
#define CAN_HUB_CAN5GRPCTL_HWFLTR_WIDTH          (6U)
#define CAN_HUB_CAN5GRPCTL_HWFLTR(x)             (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN5GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN5GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN6GRPCTL - CAN6 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN6GRPCTL_USECANBUS_MASK        (0x1FU)
#define CAN_HUB_CAN6GRPCTL_USECANBUS_SHIFT       (0U)
#define CAN_HUB_CAN6GRPCTL_USECANBUS_WIDTH       (5U)
#define CAN_HUB_CAN6GRPCTL_USECANBUS(x)          (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN6GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN6GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN6GRPCTL_HWFLTR_MASK           (0x3F0000U)
#define CAN_HUB_CAN6GRPCTL_HWFLTR_SHIFT          (16U)
#define CAN_HUB_CAN6GRPCTL_HWFLTR_WIDTH          (6U)
#define CAN_HUB_CAN6GRPCTL_HWFLTR(x)             (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN6GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN6GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN7GRPCTL - CAN7 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN7GRPCTL_USECANBUS_MASK        (0x1FU)
#define CAN_HUB_CAN7GRPCTL_USECANBUS_SHIFT       (0U)
#define CAN_HUB_CAN7GRPCTL_USECANBUS_WIDTH       (5U)
#define CAN_HUB_CAN7GRPCTL_USECANBUS(x)          (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN7GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN7GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN7GRPCTL_HWFLTR_MASK           (0x3F0000U)
#define CAN_HUB_CAN7GRPCTL_HWFLTR_SHIFT          (16U)
#define CAN_HUB_CAN7GRPCTL_HWFLTR_WIDTH          (6U)
#define CAN_HUB_CAN7GRPCTL_HWFLTR(x)             (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN7GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN7GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN8GRPCTL - CAN8 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN8GRPCTL_USECANBUS_MASK        (0x1FU)
#define CAN_HUB_CAN8GRPCTL_USECANBUS_SHIFT       (0U)
#define CAN_HUB_CAN8GRPCTL_USECANBUS_WIDTH       (5U)
#define CAN_HUB_CAN8GRPCTL_USECANBUS(x)          (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN8GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN8GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN8GRPCTL_HWFLTR_MASK           (0x3F0000U)
#define CAN_HUB_CAN8GRPCTL_HWFLTR_SHIFT          (16U)
#define CAN_HUB_CAN8GRPCTL_HWFLTR_WIDTH          (6U)
#define CAN_HUB_CAN8GRPCTL_HWFLTR(x)             (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN8GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN8GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN9GRPCTL - CAN9 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN9GRPCTL_USECANBUS_MASK        (0x1FU)
#define CAN_HUB_CAN9GRPCTL_USECANBUS_SHIFT       (0U)
#define CAN_HUB_CAN9GRPCTL_USECANBUS_WIDTH       (5U)
#define CAN_HUB_CAN9GRPCTL_USECANBUS(x)          (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN9GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN9GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN9GRPCTL_HWFLTR_MASK           (0x3F0000U)
#define CAN_HUB_CAN9GRPCTL_HWFLTR_SHIFT          (16U)
#define CAN_HUB_CAN9GRPCTL_HWFLTR_WIDTH          (6U)
#define CAN_HUB_CAN9GRPCTL_HWFLTR(x)             (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN9GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN9GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN10GRPCTL - CAN10 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN10GRPCTL_USECANBUS_MASK       (0x1FU)
#define CAN_HUB_CAN10GRPCTL_USECANBUS_SHIFT      (0U)
#define CAN_HUB_CAN10GRPCTL_USECANBUS_WIDTH      (5U)
#define CAN_HUB_CAN10GRPCTL_USECANBUS(x)         (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN10GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN10GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN10GRPCTL_HWFLTR_MASK          (0x3F0000U)
#define CAN_HUB_CAN10GRPCTL_HWFLTR_SHIFT         (16U)
#define CAN_HUB_CAN10GRPCTL_HWFLTR_WIDTH         (6U)
#define CAN_HUB_CAN10GRPCTL_HWFLTR(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN10GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN10GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN11GRPCTL - CAN11 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN11GRPCTL_USECANBUS_MASK       (0x1FU)
#define CAN_HUB_CAN11GRPCTL_USECANBUS_SHIFT      (0U)
#define CAN_HUB_CAN11GRPCTL_USECANBUS_WIDTH      (5U)
#define CAN_HUB_CAN11GRPCTL_USECANBUS(x)         (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN11GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN11GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN11GRPCTL_HWFLTR_MASK          (0x3F0000U)
#define CAN_HUB_CAN11GRPCTL_HWFLTR_SHIFT         (16U)
#define CAN_HUB_CAN11GRPCTL_HWFLTR_WIDTH         (6U)
#define CAN_HUB_CAN11GRPCTL_HWFLTR(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN11GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN11GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN12GRPCTL - CAN12 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN12GRPCTL_USECANBUS_MASK       (0x1FU)
#define CAN_HUB_CAN12GRPCTL_USECANBUS_SHIFT      (0U)
#define CAN_HUB_CAN12GRPCTL_USECANBUS_WIDTH      (5U)
#define CAN_HUB_CAN12GRPCTL_USECANBUS(x)         (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN12GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN12GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN12GRPCTL_HWFLTR_MASK          (0x3F0000U)
#define CAN_HUB_CAN12GRPCTL_HWFLTR_SHIFT         (16U)
#define CAN_HUB_CAN12GRPCTL_HWFLTR_WIDTH         (6U)
#define CAN_HUB_CAN12GRPCTL_HWFLTR(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN12GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN12GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN13GRPCTL - CAN13 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN13GRPCTL_USECANBUS_MASK       (0x1FU)
#define CAN_HUB_CAN13GRPCTL_USECANBUS_SHIFT      (0U)
#define CAN_HUB_CAN13GRPCTL_USECANBUS_WIDTH      (5U)
#define CAN_HUB_CAN13GRPCTL_USECANBUS(x)         (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN13GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN13GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN13GRPCTL_HWFLTR_MASK          (0x3F0000U)
#define CAN_HUB_CAN13GRPCTL_HWFLTR_SHIFT         (16U)
#define CAN_HUB_CAN13GRPCTL_HWFLTR_WIDTH         (6U)
#define CAN_HUB_CAN13GRPCTL_HWFLTR(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN13GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN13GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN14GRPCTL - CAN14 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN14GRPCTL_USECANBUS_MASK       (0x1FU)
#define CAN_HUB_CAN14GRPCTL_USECANBUS_SHIFT      (0U)
#define CAN_HUB_CAN14GRPCTL_USECANBUS_WIDTH      (5U)
#define CAN_HUB_CAN14GRPCTL_USECANBUS(x)         (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN14GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN14GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN14GRPCTL_HWFLTR_MASK          (0x3F0000U)
#define CAN_HUB_CAN14GRPCTL_HWFLTR_SHIFT         (16U)
#define CAN_HUB_CAN14GRPCTL_HWFLTR_WIDTH         (6U)
#define CAN_HUB_CAN14GRPCTL_HWFLTR(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN14GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN14GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN15GRPCTL - CAN15 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN15GRPCTL_USECANBUS_MASK       (0x1FU)
#define CAN_HUB_CAN15GRPCTL_USECANBUS_SHIFT      (0U)
#define CAN_HUB_CAN15GRPCTL_USECANBUS_WIDTH      (5U)
#define CAN_HUB_CAN15GRPCTL_USECANBUS(x)         (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN15GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN15GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN15GRPCTL_HWFLTR_MASK          (0x3F0000U)
#define CAN_HUB_CAN15GRPCTL_HWFLTR_SHIFT         (16U)
#define CAN_HUB_CAN15GRPCTL_HWFLTR_WIDTH         (6U)
#define CAN_HUB_CAN15GRPCTL_HWFLTR(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN15GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN15GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN16GRPCTL - CAN16 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN16GRPCTL_USECANBUS_MASK       (0x1FU)
#define CAN_HUB_CAN16GRPCTL_USECANBUS_SHIFT      (0U)
#define CAN_HUB_CAN16GRPCTL_USECANBUS_WIDTH      (5U)
#define CAN_HUB_CAN16GRPCTL_USECANBUS(x)         (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN16GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN16GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN16GRPCTL_HWFLTR_MASK          (0x3F0000U)
#define CAN_HUB_CAN16GRPCTL_HWFLTR_SHIFT         (16U)
#define CAN_HUB_CAN16GRPCTL_HWFLTR_WIDTH         (6U)
#define CAN_HUB_CAN16GRPCTL_HWFLTR(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN16GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN16GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN17GRPCTL - CAN17 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN17GRPCTL_USECANBUS_MASK       (0x1FU)
#define CAN_HUB_CAN17GRPCTL_USECANBUS_SHIFT      (0U)
#define CAN_HUB_CAN17GRPCTL_USECANBUS_WIDTH      (5U)
#define CAN_HUB_CAN17GRPCTL_USECANBUS(x)         (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN17GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN17GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN17GRPCTL_HWFLTR_MASK          (0x3F0000U)
#define CAN_HUB_CAN17GRPCTL_HWFLTR_SHIFT         (16U)
#define CAN_HUB_CAN17GRPCTL_HWFLTR_WIDTH         (6U)
#define CAN_HUB_CAN17GRPCTL_HWFLTR(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN17GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN17GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN18GRPCTL - CAN18 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN18GRPCTL_USECANBUS_MASK       (0x1FU)
#define CAN_HUB_CAN18GRPCTL_USECANBUS_SHIFT      (0U)
#define CAN_HUB_CAN18GRPCTL_USECANBUS_WIDTH      (5U)
#define CAN_HUB_CAN18GRPCTL_USECANBUS(x)         (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN18GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN18GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN18GRPCTL_HWFLTR_MASK          (0x3F0000U)
#define CAN_HUB_CAN18GRPCTL_HWFLTR_SHIFT         (16U)
#define CAN_HUB_CAN18GRPCTL_HWFLTR_WIDTH         (6U)
#define CAN_HUB_CAN18GRPCTL_HWFLTR(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN18GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN18GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN19GRPCTL - CAN19 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN19GRPCTL_USECANBUS_MASK       (0x1FU)
#define CAN_HUB_CAN19GRPCTL_USECANBUS_SHIFT      (0U)
#define CAN_HUB_CAN19GRPCTL_USECANBUS_WIDTH      (5U)
#define CAN_HUB_CAN19GRPCTL_USECANBUS(x)         (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN19GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN19GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN19GRPCTL_HWFLTR_MASK          (0x3F0000U)
#define CAN_HUB_CAN19GRPCTL_HWFLTR_SHIFT         (16U)
#define CAN_HUB_CAN19GRPCTL_HWFLTR_WIDTH         (6U)
#define CAN_HUB_CAN19GRPCTL_HWFLTR(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN19GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN19GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN20GRPCTL - CAN20 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN20GRPCTL_USECANBUS_MASK       (0x1FU)
#define CAN_HUB_CAN20GRPCTL_USECANBUS_SHIFT      (0U)
#define CAN_HUB_CAN20GRPCTL_USECANBUS_WIDTH      (5U)
#define CAN_HUB_CAN20GRPCTL_USECANBUS(x)         (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN20GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN20GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN20GRPCTL_HWFLTR_MASK          (0x3F0000U)
#define CAN_HUB_CAN20GRPCTL_HWFLTR_SHIFT         (16U)
#define CAN_HUB_CAN20GRPCTL_HWFLTR_WIDTH         (6U)
#define CAN_HUB_CAN20GRPCTL_HWFLTR(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN20GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN20GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN21GRPCTL - CAN21 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN21GRPCTL_USECANBUS_MASK       (0x1FU)
#define CAN_HUB_CAN21GRPCTL_USECANBUS_SHIFT      (0U)
#define CAN_HUB_CAN21GRPCTL_USECANBUS_WIDTH      (5U)
#define CAN_HUB_CAN21GRPCTL_USECANBUS(x)         (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN21GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN21GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN21GRPCTL_HWFLTR_MASK          (0x3F0000U)
#define CAN_HUB_CAN21GRPCTL_HWFLTR_SHIFT         (16U)
#define CAN_HUB_CAN21GRPCTL_HWFLTR_WIDTH         (6U)
#define CAN_HUB_CAN21GRPCTL_HWFLTR(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN21GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN21GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN22GRPCTL - CAN22 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN22GRPCTL_USECANBUS_MASK       (0x1FU)
#define CAN_HUB_CAN22GRPCTL_USECANBUS_SHIFT      (0U)
#define CAN_HUB_CAN22GRPCTL_USECANBUS_WIDTH      (5U)
#define CAN_HUB_CAN22GRPCTL_USECANBUS(x)         (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN22GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN22GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN22GRPCTL_HWFLTR_MASK          (0x3F0000U)
#define CAN_HUB_CAN22GRPCTL_HWFLTR_SHIFT         (16U)
#define CAN_HUB_CAN22GRPCTL_HWFLTR_WIDTH         (6U)
#define CAN_HUB_CAN22GRPCTL_HWFLTR(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN22GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN22GRPCTL_HWFLTR_MASK)
/*! @} */

/*! @name CAN23GRPCTL - CAN23 Module Group Control Register */
/*! @{ */

#define CAN_HUB_CAN23GRPCTL_USECANBUS_MASK       (0x1FU)
#define CAN_HUB_CAN23GRPCTL_USECANBUS_SHIFT      (0U)
#define CAN_HUB_CAN23GRPCTL_USECANBUS_WIDTH      (5U)
#define CAN_HUB_CAN23GRPCTL_USECANBUS(x)         (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN23GRPCTL_USECANBUS_SHIFT)) & CAN_HUB_CAN23GRPCTL_USECANBUS_MASK)

#define CAN_HUB_CAN23GRPCTL_HWFLTR_MASK          (0x3F0000U)
#define CAN_HUB_CAN23GRPCTL_HWFLTR_SHIFT         (16U)
#define CAN_HUB_CAN23GRPCTL_HWFLTR_WIDTH         (6U)
#define CAN_HUB_CAN23GRPCTL_HWFLTR(x)            (((uint32_t)(((uint32_t)(x)) << CAN_HUB_CAN23GRPCTL_HWFLTR_SHIFT)) & CAN_HUB_CAN23GRPCTL_HWFLTR_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CAN_HUB_Register_Masks */

/*!
 * @}
 */ /* end of group CAN_HUB_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_CAN_HUB_H_) */
