/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_LOCK.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_LOCK
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
#if !defined(S32K566_LOCK_H_)  /* Check if memory map has not been already included */
#define S32K566_LOCK_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- LOCK Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LOCK_Peripheral_Access_Layer LOCK Peripheral Access Layer
 * @{
 */

/** LOCK - Register Layout Typedef */
typedef struct LOCK_Struct {
  uint8_t RESERVED_0[512];
  __IO uint16_t MAC_ADAPTER_LOCK_PHY;              /**< PHY Lock, offset: 0x200 */
  uint8_t RESERVED_1[2];
  __IO uint16_t MAC_ADAPTER_LOCK_MPLLA;            /**< MPLLA Lock, offset: 0x204 */
  uint8_t RESERVED_2[2];
  __IO uint16_t MAC_ADAPTER_LOCK_MPLLB;            /**< MPLLB Lock, offset: 0x208 */
  uint8_t RESERVED_3[2];
  __IO uint16_t MAC_ADAPTER_LOCK_RAM;              /**< RAM Lock, offset: 0x20C */
  uint8_t RESERVED_4[2];
  __IO uint16_t MAC_ADAPTER_LOCK_BROADCAST;        /**< RAM Lock, offset: 0x210 */
} LOCK_Type, *LOCK_MemMapPtr;

/** Number of instances of the LOCK module. */
#define LOCK_INSTANCE_COUNT                      (1u)

/* LOCK - Peripheral instance base addresses */
/** Peripheral NETC_ENET_PHY_PHY_CTRL_EX_LOCK__LOCK base address */
#define IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__LOCK_BASE (0xFE0000u)
/** Peripheral NETC_ENET_PHY_PHY_CTRL_EX_LOCK__LOCK base pointer */
#define IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__LOCK  ((LOCK_Type *)IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__LOCK_BASE)
/** Array initializer of LOCK peripheral base addresses */
#define IP_LOCK_BASE_ADDRS                       { IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__LOCK_BASE }
/** Array initializer of LOCK peripheral base pointers */
#define IP_LOCK_BASE_PTRS                        { IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__LOCK }

/* ----------------------------------------------------------------------------
   -- LOCK Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LOCK_Register_Masks LOCK Register Masks
 * @{
 */

/*! @name MAC_ADAPTER_LOCK_PHY - PHY Lock */
/*! @{ */

#define LOCK_MAC_ADAPTER_LOCK_PHY_LOCK_OWNER_MASK (0xFU)
#define LOCK_MAC_ADAPTER_LOCK_PHY_LOCK_OWNER_SHIFT (0U)
#define LOCK_MAC_ADAPTER_LOCK_PHY_LOCK_OWNER_WIDTH (4U)
#define LOCK_MAC_ADAPTER_LOCK_PHY_LOCK_OWNER(x)  (((uint16_t)(((uint16_t)(x)) << LOCK_MAC_ADAPTER_LOCK_PHY_LOCK_OWNER_SHIFT)) & LOCK_MAC_ADAPTER_LOCK_PHY_LOCK_OWNER_MASK)

#define LOCK_MAC_ADAPTER_LOCK_PHY_LOCK_MASK      (0x80U)
#define LOCK_MAC_ADAPTER_LOCK_PHY_LOCK_SHIFT     (7U)
#define LOCK_MAC_ADAPTER_LOCK_PHY_LOCK_WIDTH     (1U)
#define LOCK_MAC_ADAPTER_LOCK_PHY_LOCK(x)        (((uint16_t)(((uint16_t)(x)) << LOCK_MAC_ADAPTER_LOCK_PHY_LOCK_SHIFT)) & LOCK_MAC_ADAPTER_LOCK_PHY_LOCK_MASK)

#define LOCK_MAC_ADAPTER_LOCK_PHY_WHOAMI_MASK    (0xF000U)
#define LOCK_MAC_ADAPTER_LOCK_PHY_WHOAMI_SHIFT   (12U)
#define LOCK_MAC_ADAPTER_LOCK_PHY_WHOAMI_WIDTH   (4U)
#define LOCK_MAC_ADAPTER_LOCK_PHY_WHOAMI(x)      (((uint16_t)(((uint16_t)(x)) << LOCK_MAC_ADAPTER_LOCK_PHY_WHOAMI_SHIFT)) & LOCK_MAC_ADAPTER_LOCK_PHY_WHOAMI_MASK)
/*! @} */

/*! @name MAC_ADAPTER_LOCK_MPLLA - MPLLA Lock */
/*! @{ */

#define LOCK_MAC_ADAPTER_LOCK_MPLLA_LOCK_OWNER_MASK (0xFU)
#define LOCK_MAC_ADAPTER_LOCK_MPLLA_LOCK_OWNER_SHIFT (0U)
#define LOCK_MAC_ADAPTER_LOCK_MPLLA_LOCK_OWNER_WIDTH (4U)
#define LOCK_MAC_ADAPTER_LOCK_MPLLA_LOCK_OWNER(x) (((uint16_t)(((uint16_t)(x)) << LOCK_MAC_ADAPTER_LOCK_MPLLA_LOCK_OWNER_SHIFT)) & LOCK_MAC_ADAPTER_LOCK_MPLLA_LOCK_OWNER_MASK)

#define LOCK_MAC_ADAPTER_LOCK_MPLLA_LOCK_MASK    (0x80U)
#define LOCK_MAC_ADAPTER_LOCK_MPLLA_LOCK_SHIFT   (7U)
#define LOCK_MAC_ADAPTER_LOCK_MPLLA_LOCK_WIDTH   (1U)
#define LOCK_MAC_ADAPTER_LOCK_MPLLA_LOCK(x)      (((uint16_t)(((uint16_t)(x)) << LOCK_MAC_ADAPTER_LOCK_MPLLA_LOCK_SHIFT)) & LOCK_MAC_ADAPTER_LOCK_MPLLA_LOCK_MASK)

#define LOCK_MAC_ADAPTER_LOCK_MPLLA_WHOAMI_MASK  (0xF000U)
#define LOCK_MAC_ADAPTER_LOCK_MPLLA_WHOAMI_SHIFT (12U)
#define LOCK_MAC_ADAPTER_LOCK_MPLLA_WHOAMI_WIDTH (4U)
#define LOCK_MAC_ADAPTER_LOCK_MPLLA_WHOAMI(x)    (((uint16_t)(((uint16_t)(x)) << LOCK_MAC_ADAPTER_LOCK_MPLLA_WHOAMI_SHIFT)) & LOCK_MAC_ADAPTER_LOCK_MPLLA_WHOAMI_MASK)
/*! @} */

/*! @name MAC_ADAPTER_LOCK_MPLLB - MPLLB Lock */
/*! @{ */

#define LOCK_MAC_ADAPTER_LOCK_MPLLB_LOCK_OWNER_MASK (0xFU)
#define LOCK_MAC_ADAPTER_LOCK_MPLLB_LOCK_OWNER_SHIFT (0U)
#define LOCK_MAC_ADAPTER_LOCK_MPLLB_LOCK_OWNER_WIDTH (4U)
#define LOCK_MAC_ADAPTER_LOCK_MPLLB_LOCK_OWNER(x) (((uint16_t)(((uint16_t)(x)) << LOCK_MAC_ADAPTER_LOCK_MPLLB_LOCK_OWNER_SHIFT)) & LOCK_MAC_ADAPTER_LOCK_MPLLB_LOCK_OWNER_MASK)

#define LOCK_MAC_ADAPTER_LOCK_MPLLB_LOCK_MASK    (0x80U)
#define LOCK_MAC_ADAPTER_LOCK_MPLLB_LOCK_SHIFT   (7U)
#define LOCK_MAC_ADAPTER_LOCK_MPLLB_LOCK_WIDTH   (1U)
#define LOCK_MAC_ADAPTER_LOCK_MPLLB_LOCK(x)      (((uint16_t)(((uint16_t)(x)) << LOCK_MAC_ADAPTER_LOCK_MPLLB_LOCK_SHIFT)) & LOCK_MAC_ADAPTER_LOCK_MPLLB_LOCK_MASK)

#define LOCK_MAC_ADAPTER_LOCK_MPLLB_WHOAMI_MASK  (0xF000U)
#define LOCK_MAC_ADAPTER_LOCK_MPLLB_WHOAMI_SHIFT (12U)
#define LOCK_MAC_ADAPTER_LOCK_MPLLB_WHOAMI_WIDTH (4U)
#define LOCK_MAC_ADAPTER_LOCK_MPLLB_WHOAMI(x)    (((uint16_t)(((uint16_t)(x)) << LOCK_MAC_ADAPTER_LOCK_MPLLB_WHOAMI_SHIFT)) & LOCK_MAC_ADAPTER_LOCK_MPLLB_WHOAMI_MASK)
/*! @} */

/*! @name MAC_ADAPTER_LOCK_RAM - RAM Lock */
/*! @{ */

#define LOCK_MAC_ADAPTER_LOCK_RAM_LOCK_OWNER_MASK (0xFU)
#define LOCK_MAC_ADAPTER_LOCK_RAM_LOCK_OWNER_SHIFT (0U)
#define LOCK_MAC_ADAPTER_LOCK_RAM_LOCK_OWNER_WIDTH (4U)
#define LOCK_MAC_ADAPTER_LOCK_RAM_LOCK_OWNER(x)  (((uint16_t)(((uint16_t)(x)) << LOCK_MAC_ADAPTER_LOCK_RAM_LOCK_OWNER_SHIFT)) & LOCK_MAC_ADAPTER_LOCK_RAM_LOCK_OWNER_MASK)

#define LOCK_MAC_ADAPTER_LOCK_RAM_LOCK_MASK      (0x80U)
#define LOCK_MAC_ADAPTER_LOCK_RAM_LOCK_SHIFT     (7U)
#define LOCK_MAC_ADAPTER_LOCK_RAM_LOCK_WIDTH     (1U)
#define LOCK_MAC_ADAPTER_LOCK_RAM_LOCK(x)        (((uint16_t)(((uint16_t)(x)) << LOCK_MAC_ADAPTER_LOCK_RAM_LOCK_SHIFT)) & LOCK_MAC_ADAPTER_LOCK_RAM_LOCK_MASK)

#define LOCK_MAC_ADAPTER_LOCK_RAM_WHOAMI_MASK    (0xF000U)
#define LOCK_MAC_ADAPTER_LOCK_RAM_WHOAMI_SHIFT   (12U)
#define LOCK_MAC_ADAPTER_LOCK_RAM_WHOAMI_WIDTH   (4U)
#define LOCK_MAC_ADAPTER_LOCK_RAM_WHOAMI(x)      (((uint16_t)(((uint16_t)(x)) << LOCK_MAC_ADAPTER_LOCK_RAM_WHOAMI_SHIFT)) & LOCK_MAC_ADAPTER_LOCK_RAM_WHOAMI_MASK)
/*! @} */

/*! @name MAC_ADAPTER_LOCK_BROADCAST - RAM Lock */
/*! @{ */

#define LOCK_MAC_ADAPTER_LOCK_BROADCAST_LOCK_OWNER_MASK (0xFU)
#define LOCK_MAC_ADAPTER_LOCK_BROADCAST_LOCK_OWNER_SHIFT (0U)
#define LOCK_MAC_ADAPTER_LOCK_BROADCAST_LOCK_OWNER_WIDTH (4U)
#define LOCK_MAC_ADAPTER_LOCK_BROADCAST_LOCK_OWNER(x) (((uint16_t)(((uint16_t)(x)) << LOCK_MAC_ADAPTER_LOCK_BROADCAST_LOCK_OWNER_SHIFT)) & LOCK_MAC_ADAPTER_LOCK_BROADCAST_LOCK_OWNER_MASK)

#define LOCK_MAC_ADAPTER_LOCK_BROADCAST_LOCK_MASK (0x80U)
#define LOCK_MAC_ADAPTER_LOCK_BROADCAST_LOCK_SHIFT (7U)
#define LOCK_MAC_ADAPTER_LOCK_BROADCAST_LOCK_WIDTH (1U)
#define LOCK_MAC_ADAPTER_LOCK_BROADCAST_LOCK(x)  (((uint16_t)(((uint16_t)(x)) << LOCK_MAC_ADAPTER_LOCK_BROADCAST_LOCK_SHIFT)) & LOCK_MAC_ADAPTER_LOCK_BROADCAST_LOCK_MASK)

#define LOCK_MAC_ADAPTER_LOCK_BROADCAST_WHOAMI_MASK (0xF000U)
#define LOCK_MAC_ADAPTER_LOCK_BROADCAST_WHOAMI_SHIFT (12U)
#define LOCK_MAC_ADAPTER_LOCK_BROADCAST_WHOAMI_WIDTH (4U)
#define LOCK_MAC_ADAPTER_LOCK_BROADCAST_WHOAMI(x) (((uint16_t)(((uint16_t)(x)) << LOCK_MAC_ADAPTER_LOCK_BROADCAST_WHOAMI_SHIFT)) & LOCK_MAC_ADAPTER_LOCK_BROADCAST_WHOAMI_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group LOCK_Register_Masks */

/*!
 * @}
 */ /* end of group LOCK_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_LOCK_H_) */
