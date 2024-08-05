/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_ENETC_PSEUDO_MAC_PORT2.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_ENETC_PSEUDO_MAC_PORT2
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
#if !defined(S32Z2_ENETC_PSEUDO_MAC_PORT2_H_)  /* Check if memory map has not been already included */
#define S32Z2_ENETC_PSEUDO_MAC_PORT2_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- ENETC_PSEUDO_MAC_PORT2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENETC_PSEUDO_MAC_PORT2_Peripheral_Access_Layer ENETC_PSEUDO_MAC_PORT2 Peripheral Access Layer
 * @{
 */

/** ENETC_PSEUDO_MAC_PORT2 - Size of Registers Arrays */
#define ENETC_PSEUDO_MAC_PORT2_PPMROCR_COUNT      2u
#define ENETC_PSEUDO_MAC_PORT2_PPMRUFCR_COUNT     2u
#define ENETC_PSEUDO_MAC_PORT2_PPMRMFCR_COUNT     2u
#define ENETC_PSEUDO_MAC_PORT2_PPMRBFCR_COUNT     2u
#define ENETC_PSEUDO_MAC_PORT2_PPMTOCR_COUNT      2u
#define ENETC_PSEUDO_MAC_PORT2_PPMTUFCR_COUNT     2u
#define ENETC_PSEUDO_MAC_PORT2_PPMTMFCR_COUNT     2u
#define ENETC_PSEUDO_MAC_PORT2_PPMTBFCR_COUNT     2u

/** ENETC_PSEUDO_MAC_PORT2 - Register Layout Typedef */
typedef struct {
  __I  uint32_t PPMSR;                             /**< Port pseudo MAC status register, offset: 0x0 */
  uint8_t RESERVED_0[12];
  __IO uint32_t PPMCR;                             /**< Port pseudo MAC configuration register, offset: 0x10 */
  uint8_t RESERVED_1[108];
  __I  uint32_t PPMROCR[ENETC_PSEUDO_MAC_PORT2_PPMROCR_COUNT]; /**< Port pseudo MAC receive octets counter, array offset: 0x80, array step: 0x4 */
  __I  uint32_t PPMRUFCR[ENETC_PSEUDO_MAC_PORT2_PPMRUFCR_COUNT]; /**< Port pseudo MAC receive unicast frame counter register, array offset: 0x88, array step: 0x4 */
  __I  uint32_t PPMRMFCR[ENETC_PSEUDO_MAC_PORT2_PPMRMFCR_COUNT]; /**< Port pseudo MAC receive multicast frame counter register, array offset: 0x90, array step: 0x4 */
  __I  uint32_t PPMRBFCR[ENETC_PSEUDO_MAC_PORT2_PPMRBFCR_COUNT]; /**< Port pseudo MAC receive broadcast frame counter register, array offset: 0x98, array step: 0x4 */
  uint8_t RESERVED_2[32];
  __I  uint32_t PPMTOCR[ENETC_PSEUDO_MAC_PORT2_PPMTOCR_COUNT]; /**< Port pseudo MAC transmit octets counter, array offset: 0xC0, array step: 0x4 */
  __I  uint32_t PPMTUFCR[ENETC_PSEUDO_MAC_PORT2_PPMTUFCR_COUNT]; /**< Port pseudo MAC transmit unicast frame counter register, array offset: 0xC8, array step: 0x4 */
  __I  uint32_t PPMTMFCR[ENETC_PSEUDO_MAC_PORT2_PPMTMFCR_COUNT]; /**< Port pseudo MAC transmit multicast frame counter register, array offset: 0xD0, array step: 0x4 */
  __I  uint32_t PPMTBFCR[ENETC_PSEUDO_MAC_PORT2_PPMTBFCR_COUNT]; /**< Port pseudo MAC transmit broadcast frame counter register, array offset: 0xD8, array step: 0x4 */
} ENETC_PSEUDO_MAC_PORT2_Type, *ENETC_PSEUDO_MAC_PORT2_MemMapPtr;

/** Number of instances of the ENETC_PSEUDO_MAC_PORT2 module. */
#define ENETC_PSEUDO_MAC_PORT2_INSTANCE_COUNT    (1u)

/* ENETC_PSEUDO_MAC_PORT2 - Peripheral instance base addresses */
/** Peripheral NETC__ENETC0_PSEUDO_MAC_PORT base address */
#define IP_NETC__ENETC0_PSEUDO_MAC_PORT_BASE     (0x74B15000u)
/** Peripheral NETC__ENETC0_PSEUDO_MAC_PORT base pointer */
#define IP_NETC__ENETC0_PSEUDO_MAC_PORT          ((ENETC_PSEUDO_MAC_PORT2_Type *)IP_NETC__ENETC0_PSEUDO_MAC_PORT_BASE)
/** Array initializer of ENETC_PSEUDO_MAC_PORT2 peripheral base addresses */
#define IP_ENETC_PSEUDO_MAC_PORT2_BASE_ADDRS     { IP_NETC__ENETC0_PSEUDO_MAC_PORT_BASE }
/** Array initializer of ENETC_PSEUDO_MAC_PORT2 peripheral base pointers */
#define IP_ENETC_PSEUDO_MAC_PORT2_BASE_PTRS      { IP_NETC__ENETC0_PSEUDO_MAC_PORT }

/* ----------------------------------------------------------------------------
   -- ENETC_PSEUDO_MAC_PORT2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENETC_PSEUDO_MAC_PORT2_Register_Masks ENETC_PSEUDO_MAC_PORT2 Register Masks
 * @{
 */

/*! @name PPMSR - Port pseudo MAC status register */
/*! @{ */

#define ENETC_PSEUDO_MAC_PORT2_PPMSR_LSTATE_MASK (0x1U)
#define ENETC_PSEUDO_MAC_PORT2_PPMSR_LSTATE_SHIFT (0U)
#define ENETC_PSEUDO_MAC_PORT2_PPMSR_LSTATE_WIDTH (1U)
#define ENETC_PSEUDO_MAC_PORT2_PPMSR_LSTATE(x)   (((uint32_t)(((uint32_t)(x)) << ENETC_PSEUDO_MAC_PORT2_PPMSR_LSTATE_SHIFT)) & ENETC_PSEUDO_MAC_PORT2_PPMSR_LSTATE_MASK)

#define ENETC_PSEUDO_MAC_PORT2_PPMSR_RSTATE_MASK (0x100U)
#define ENETC_PSEUDO_MAC_PORT2_PPMSR_RSTATE_SHIFT (8U)
#define ENETC_PSEUDO_MAC_PORT2_PPMSR_RSTATE_WIDTH (1U)
#define ENETC_PSEUDO_MAC_PORT2_PPMSR_RSTATE(x)   (((uint32_t)(((uint32_t)(x)) << ENETC_PSEUDO_MAC_PORT2_PPMSR_RSTATE_SHIFT)) & ENETC_PSEUDO_MAC_PORT2_PPMSR_RSTATE_MASK)
/*! @} */

/*! @name PPMCR - Port pseudo MAC configuration register */
/*! @{ */

#define ENETC_PSEUDO_MAC_PORT2_PPMCR_TXPAD_MASK  (0x10000U)
#define ENETC_PSEUDO_MAC_PORT2_PPMCR_TXPAD_SHIFT (16U)
#define ENETC_PSEUDO_MAC_PORT2_PPMCR_TXPAD_WIDTH (1U)
#define ENETC_PSEUDO_MAC_PORT2_PPMCR_TXPAD(x)    (((uint32_t)(((uint32_t)(x)) << ENETC_PSEUDO_MAC_PORT2_PPMCR_TXPAD_SHIFT)) & ENETC_PSEUDO_MAC_PORT2_PPMCR_TXPAD_MASK)
/*! @} */

/*! @name PPMROCR - Port pseudo MAC receive octets counter */
/*! @{ */

#define ENETC_PSEUDO_MAC_PORT2_PPMROCR_ROCT_MASK (0xFFFFFFFFU)
#define ENETC_PSEUDO_MAC_PORT2_PPMROCR_ROCT_SHIFT (0U)
#define ENETC_PSEUDO_MAC_PORT2_PPMROCR_ROCT_WIDTH (32U)
#define ENETC_PSEUDO_MAC_PORT2_PPMROCR_ROCT(x)   (((uint32_t)(((uint32_t)(x)) << ENETC_PSEUDO_MAC_PORT2_PPMROCR_ROCT_SHIFT)) & ENETC_PSEUDO_MAC_PORT2_PPMROCR_ROCT_MASK)
/*! @} */

/*! @name PPMRUFCR - Port pseudo MAC receive unicast frame counter register */
/*! @{ */

#define ENETC_PSEUDO_MAC_PORT2_PPMRUFCR_RUCA_MASK (0xFFFFFFFFU)
#define ENETC_PSEUDO_MAC_PORT2_PPMRUFCR_RUCA_SHIFT (0U)
#define ENETC_PSEUDO_MAC_PORT2_PPMRUFCR_RUCA_WIDTH (32U)
#define ENETC_PSEUDO_MAC_PORT2_PPMRUFCR_RUCA(x)  (((uint32_t)(((uint32_t)(x)) << ENETC_PSEUDO_MAC_PORT2_PPMRUFCR_RUCA_SHIFT)) & ENETC_PSEUDO_MAC_PORT2_PPMRUFCR_RUCA_MASK)
/*! @} */

/*! @name PPMRMFCR - Port pseudo MAC receive multicast frame counter register */
/*! @{ */

#define ENETC_PSEUDO_MAC_PORT2_PPMRMFCR_RMCA_MASK (0xFFFFFFFFU)
#define ENETC_PSEUDO_MAC_PORT2_PPMRMFCR_RMCA_SHIFT (0U)
#define ENETC_PSEUDO_MAC_PORT2_PPMRMFCR_RMCA_WIDTH (32U)
#define ENETC_PSEUDO_MAC_PORT2_PPMRMFCR_RMCA(x)  (((uint32_t)(((uint32_t)(x)) << ENETC_PSEUDO_MAC_PORT2_PPMRMFCR_RMCA_SHIFT)) & ENETC_PSEUDO_MAC_PORT2_PPMRMFCR_RMCA_MASK)
/*! @} */

/*! @name PPMRBFCR - Port pseudo MAC receive broadcast frame counter register */
/*! @{ */

#define ENETC_PSEUDO_MAC_PORT2_PPMRBFCR_RBCA_MASK (0xFFFFFFFFU)
#define ENETC_PSEUDO_MAC_PORT2_PPMRBFCR_RBCA_SHIFT (0U)
#define ENETC_PSEUDO_MAC_PORT2_PPMRBFCR_RBCA_WIDTH (32U)
#define ENETC_PSEUDO_MAC_PORT2_PPMRBFCR_RBCA(x)  (((uint32_t)(((uint32_t)(x)) << ENETC_PSEUDO_MAC_PORT2_PPMRBFCR_RBCA_SHIFT)) & ENETC_PSEUDO_MAC_PORT2_PPMRBFCR_RBCA_MASK)
/*! @} */

/*! @name PPMTOCR - Port pseudo MAC transmit octets counter */
/*! @{ */

#define ENETC_PSEUDO_MAC_PORT2_PPMTOCR_TOCT_MASK (0xFFFFFFFFU)
#define ENETC_PSEUDO_MAC_PORT2_PPMTOCR_TOCT_SHIFT (0U)
#define ENETC_PSEUDO_MAC_PORT2_PPMTOCR_TOCT_WIDTH (32U)
#define ENETC_PSEUDO_MAC_PORT2_PPMTOCR_TOCT(x)   (((uint32_t)(((uint32_t)(x)) << ENETC_PSEUDO_MAC_PORT2_PPMTOCR_TOCT_SHIFT)) & ENETC_PSEUDO_MAC_PORT2_PPMTOCR_TOCT_MASK)
/*! @} */

/*! @name PPMTUFCR - Port pseudo MAC transmit unicast frame counter register */
/*! @{ */

#define ENETC_PSEUDO_MAC_PORT2_PPMTUFCR_TUCA_MASK (0xFFFFFFFFU)
#define ENETC_PSEUDO_MAC_PORT2_PPMTUFCR_TUCA_SHIFT (0U)
#define ENETC_PSEUDO_MAC_PORT2_PPMTUFCR_TUCA_WIDTH (32U)
#define ENETC_PSEUDO_MAC_PORT2_PPMTUFCR_TUCA(x)  (((uint32_t)(((uint32_t)(x)) << ENETC_PSEUDO_MAC_PORT2_PPMTUFCR_TUCA_SHIFT)) & ENETC_PSEUDO_MAC_PORT2_PPMTUFCR_TUCA_MASK)
/*! @} */

/*! @name PPMTMFCR - Port pseudo MAC transmit multicast frame counter register */
/*! @{ */

#define ENETC_PSEUDO_MAC_PORT2_PPMTMFCR_TMCA_MASK (0xFFFFFFFFU)
#define ENETC_PSEUDO_MAC_PORT2_PPMTMFCR_TMCA_SHIFT (0U)
#define ENETC_PSEUDO_MAC_PORT2_PPMTMFCR_TMCA_WIDTH (32U)
#define ENETC_PSEUDO_MAC_PORT2_PPMTMFCR_TMCA(x)  (((uint32_t)(((uint32_t)(x)) << ENETC_PSEUDO_MAC_PORT2_PPMTMFCR_TMCA_SHIFT)) & ENETC_PSEUDO_MAC_PORT2_PPMTMFCR_TMCA_MASK)
/*! @} */

/*! @name PPMTBFCR - Port pseudo MAC transmit broadcast frame counter register */
/*! @{ */

#define ENETC_PSEUDO_MAC_PORT2_PPMTBFCR_TBCA_MASK (0xFFFFFFFFU)
#define ENETC_PSEUDO_MAC_PORT2_PPMTBFCR_TBCA_SHIFT (0U)
#define ENETC_PSEUDO_MAC_PORT2_PPMTBFCR_TBCA_WIDTH (32U)
#define ENETC_PSEUDO_MAC_PORT2_PPMTBFCR_TBCA(x)  (((uint32_t)(((uint32_t)(x)) << ENETC_PSEUDO_MAC_PORT2_PPMTBFCR_TBCA_SHIFT)) & ENETC_PSEUDO_MAC_PORT2_PPMTBFCR_TBCA_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group ENETC_PSEUDO_MAC_PORT2_Register_Masks */

/*!
 * @}
 */ /* end of group ENETC_PSEUDO_MAC_PORT2_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_ENETC_PSEUDO_MAC_PORT2_H_) */
