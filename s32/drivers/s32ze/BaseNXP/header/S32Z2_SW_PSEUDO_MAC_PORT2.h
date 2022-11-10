/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_SW_PSEUDO_MAC_PORT2.h
 * @version 1.8
 * @date 2022-07-13
 * @brief Peripheral Access Layer for S32Z2_SW_PSEUDO_MAC_PORT2
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
#if !defined(S32Z2_SW_PSEUDO_MAC_PORT2_H_)  /* Check if memory map has not been already included */
#define S32Z2_SW_PSEUDO_MAC_PORT2_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SW_PSEUDO_MAC_PORT2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SW_PSEUDO_MAC_PORT2_Peripheral_Access_Layer SW_PSEUDO_MAC_PORT2 Peripheral Access Layer
 * @{
 */

/** SW_PSEUDO_MAC_PORT2 - Size of Registers Arrays */
#define SW_PSEUDO_MAC_PORT2_PPMROCR_COUNT         2u
#define SW_PSEUDO_MAC_PORT2_PPMRUFCR_COUNT        2u
#define SW_PSEUDO_MAC_PORT2_PPMRMFCR_COUNT        2u
#define SW_PSEUDO_MAC_PORT2_PPMRBFCR_COUNT        2u
#define SW_PSEUDO_MAC_PORT2_PPMTOCR_COUNT         2u
#define SW_PSEUDO_MAC_PORT2_PPMTUFCR_COUNT        2u
#define SW_PSEUDO_MAC_PORT2_PPMTMFCR_COUNT        2u
#define SW_PSEUDO_MAC_PORT2_PPMTBFCR_COUNT        2u

/** SW_PSEUDO_MAC_PORT2 - Register Layout Typedef */
typedef struct {
  uint8_t RESERVED_0[4096];
  __I  uint32_t PPMSR;                             /**< Port pseudo MAC status register, offset: 0x1000 */
  uint8_t RESERVED_1[124];
  __I  uint32_t PPMROCR[SW_PSEUDO_MAC_PORT2_PPMROCR_COUNT]; /**< Port pseudo MAC receive octets counter, array offset: 0x1080, array step: 0x4 */
  __I  uint32_t PPMRUFCR[SW_PSEUDO_MAC_PORT2_PPMRUFCR_COUNT]; /**< Port pseudo MAC receive unicast frame counter register, array offset: 0x1088, array step: 0x4 */
  __I  uint32_t PPMRMFCR[SW_PSEUDO_MAC_PORT2_PPMRMFCR_COUNT]; /**< Port pseudo MAC receive multicast frame counter register, array offset: 0x1090, array step: 0x4 */
  __I  uint32_t PPMRBFCR[SW_PSEUDO_MAC_PORT2_PPMRBFCR_COUNT]; /**< Port pseudo MAC receive broadcast frame counter register, array offset: 0x1098, array step: 0x4 */
  uint8_t RESERVED_2[32];
  __I  uint32_t PPMTOCR[SW_PSEUDO_MAC_PORT2_PPMTOCR_COUNT]; /**< Port pseudo MAC transmit octets counter, array offset: 0x10C0, array step: 0x4 */
  __I  uint32_t PPMTUFCR[SW_PSEUDO_MAC_PORT2_PPMTUFCR_COUNT]; /**< Port pseudo MAC transmit unicast frame counter register, array offset: 0x10C8, array step: 0x4 */
  __I  uint32_t PPMTMFCR[SW_PSEUDO_MAC_PORT2_PPMTMFCR_COUNT]; /**< Port pseudo MAC transmit multicast frame counter register, array offset: 0x10D0, array step: 0x4 */
  __I  uint32_t PPMTBFCR[SW_PSEUDO_MAC_PORT2_PPMTBFCR_COUNT]; /**< Port pseudo MAC transmit broadcast frame counter register, array offset: 0x10D8, array step: 0x4 */
} SW_PSEUDO_MAC_PORT2_Type, *SW_PSEUDO_MAC_PORT2_MemMapPtr;

/** Number of instances of the SW_PSEUDO_MAC_PORT2 module. */
#define SW_PSEUDO_MAC_PORT2_INSTANCE_COUNT       (1u)

/* SW_PSEUDO_MAC_PORT2 - Peripheral instance base addresses */
/** Peripheral NETC__SW0_PSEUDO_MAC_PORT2 base address */
#define IP_NETC__SW0_PSEUDO_MAC_PORT2_BASE       (0x74A0C000u)
/** Peripheral NETC__SW0_PSEUDO_MAC_PORT2 base pointer */
#define IP_NETC__SW0_PSEUDO_MAC_PORT2            ((SW_PSEUDO_MAC_PORT2_Type *)IP_NETC__SW0_PSEUDO_MAC_PORT2_BASE)
/** Array initializer of SW_PSEUDO_MAC_PORT2 peripheral base addresses */
#define IP_SW_PSEUDO_MAC_PORT2_BASE_ADDRS        { IP_NETC__SW0_PSEUDO_MAC_PORT2_BASE }
/** Array initializer of SW_PSEUDO_MAC_PORT2 peripheral base pointers */
#define IP_SW_PSEUDO_MAC_PORT2_BASE_PTRS         { IP_NETC__SW0_PSEUDO_MAC_PORT2 }

/* ----------------------------------------------------------------------------
   -- SW_PSEUDO_MAC_PORT2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SW_PSEUDO_MAC_PORT2_Register_Masks SW_PSEUDO_MAC_PORT2 Register Masks
 * @{
 */

/*! @name PPMSR - Port pseudo MAC status register */
/*! @{ */

#define SW_PSEUDO_MAC_PORT2_PPMSR_LSTATE_MASK    (0x1U)
#define SW_PSEUDO_MAC_PORT2_PPMSR_LSTATE_SHIFT   (0U)
#define SW_PSEUDO_MAC_PORT2_PPMSR_LSTATE_WIDTH   (1U)
#define SW_PSEUDO_MAC_PORT2_PPMSR_LSTATE(x)      (((uint32_t)(((uint32_t)(x)) << SW_PSEUDO_MAC_PORT2_PPMSR_LSTATE_SHIFT)) & SW_PSEUDO_MAC_PORT2_PPMSR_LSTATE_MASK)

#define SW_PSEUDO_MAC_PORT2_PPMSR_RSTATE_MASK    (0x100U)
#define SW_PSEUDO_MAC_PORT2_PPMSR_RSTATE_SHIFT   (8U)
#define SW_PSEUDO_MAC_PORT2_PPMSR_RSTATE_WIDTH   (1U)
#define SW_PSEUDO_MAC_PORT2_PPMSR_RSTATE(x)      (((uint32_t)(((uint32_t)(x)) << SW_PSEUDO_MAC_PORT2_PPMSR_RSTATE_SHIFT)) & SW_PSEUDO_MAC_PORT2_PPMSR_RSTATE_MASK)
/*! @} */

/*! @name PPMROCR - Port pseudo MAC receive octets counter */
/*! @{ */

#define SW_PSEUDO_MAC_PORT2_PPMROCR_ROCT_MASK    (0xFFFFFFFFU)
#define SW_PSEUDO_MAC_PORT2_PPMROCR_ROCT_SHIFT   (0U)
#define SW_PSEUDO_MAC_PORT2_PPMROCR_ROCT_WIDTH   (32U)
#define SW_PSEUDO_MAC_PORT2_PPMROCR_ROCT(x)      (((uint32_t)(((uint32_t)(x)) << SW_PSEUDO_MAC_PORT2_PPMROCR_ROCT_SHIFT)) & SW_PSEUDO_MAC_PORT2_PPMROCR_ROCT_MASK)
/*! @} */

/*! @name PPMRUFCR - Port pseudo MAC receive unicast frame counter register */
/*! @{ */

#define SW_PSEUDO_MAC_PORT2_PPMRUFCR_RUCA_MASK   (0xFFFFFFFFU)
#define SW_PSEUDO_MAC_PORT2_PPMRUFCR_RUCA_SHIFT  (0U)
#define SW_PSEUDO_MAC_PORT2_PPMRUFCR_RUCA_WIDTH  (32U)
#define SW_PSEUDO_MAC_PORT2_PPMRUFCR_RUCA(x)     (((uint32_t)(((uint32_t)(x)) << SW_PSEUDO_MAC_PORT2_PPMRUFCR_RUCA_SHIFT)) & SW_PSEUDO_MAC_PORT2_PPMRUFCR_RUCA_MASK)
/*! @} */

/*! @name PPMRMFCR - Port pseudo MAC receive multicast frame counter register */
/*! @{ */

#define SW_PSEUDO_MAC_PORT2_PPMRMFCR_RMCA_MASK   (0xFFFFFFFFU)
#define SW_PSEUDO_MAC_PORT2_PPMRMFCR_RMCA_SHIFT  (0U)
#define SW_PSEUDO_MAC_PORT2_PPMRMFCR_RMCA_WIDTH  (32U)
#define SW_PSEUDO_MAC_PORT2_PPMRMFCR_RMCA(x)     (((uint32_t)(((uint32_t)(x)) << SW_PSEUDO_MAC_PORT2_PPMRMFCR_RMCA_SHIFT)) & SW_PSEUDO_MAC_PORT2_PPMRMFCR_RMCA_MASK)
/*! @} */

/*! @name PPMRBFCR - Port pseudo MAC receive broadcast frame counter register */
/*! @{ */

#define SW_PSEUDO_MAC_PORT2_PPMRBFCR_RBCA_MASK   (0xFFFFFFFFU)
#define SW_PSEUDO_MAC_PORT2_PPMRBFCR_RBCA_SHIFT  (0U)
#define SW_PSEUDO_MAC_PORT2_PPMRBFCR_RBCA_WIDTH  (32U)
#define SW_PSEUDO_MAC_PORT2_PPMRBFCR_RBCA(x)     (((uint32_t)(((uint32_t)(x)) << SW_PSEUDO_MAC_PORT2_PPMRBFCR_RBCA_SHIFT)) & SW_PSEUDO_MAC_PORT2_PPMRBFCR_RBCA_MASK)
/*! @} */

/*! @name PPMTOCR - Port pseudo MAC transmit octets counter */
/*! @{ */

#define SW_PSEUDO_MAC_PORT2_PPMTOCR_TOCT_MASK    (0xFFFFFFFFU)
#define SW_PSEUDO_MAC_PORT2_PPMTOCR_TOCT_SHIFT   (0U)
#define SW_PSEUDO_MAC_PORT2_PPMTOCR_TOCT_WIDTH   (32U)
#define SW_PSEUDO_MAC_PORT2_PPMTOCR_TOCT(x)      (((uint32_t)(((uint32_t)(x)) << SW_PSEUDO_MAC_PORT2_PPMTOCR_TOCT_SHIFT)) & SW_PSEUDO_MAC_PORT2_PPMTOCR_TOCT_MASK)
/*! @} */

/*! @name PPMTUFCR - Port pseudo MAC transmit unicast frame counter register */
/*! @{ */

#define SW_PSEUDO_MAC_PORT2_PPMTUFCR_TUCA_MASK   (0xFFFFFFFFU)
#define SW_PSEUDO_MAC_PORT2_PPMTUFCR_TUCA_SHIFT  (0U)
#define SW_PSEUDO_MAC_PORT2_PPMTUFCR_TUCA_WIDTH  (32U)
#define SW_PSEUDO_MAC_PORT2_PPMTUFCR_TUCA(x)     (((uint32_t)(((uint32_t)(x)) << SW_PSEUDO_MAC_PORT2_PPMTUFCR_TUCA_SHIFT)) & SW_PSEUDO_MAC_PORT2_PPMTUFCR_TUCA_MASK)
/*! @} */

/*! @name PPMTMFCR - Port pseudo MAC transmit multicast frame counter register */
/*! @{ */

#define SW_PSEUDO_MAC_PORT2_PPMTMFCR_TMCA_MASK   (0xFFFFFFFFU)
#define SW_PSEUDO_MAC_PORT2_PPMTMFCR_TMCA_SHIFT  (0U)
#define SW_PSEUDO_MAC_PORT2_PPMTMFCR_TMCA_WIDTH  (32U)
#define SW_PSEUDO_MAC_PORT2_PPMTMFCR_TMCA(x)     (((uint32_t)(((uint32_t)(x)) << SW_PSEUDO_MAC_PORT2_PPMTMFCR_TMCA_SHIFT)) & SW_PSEUDO_MAC_PORT2_PPMTMFCR_TMCA_MASK)
/*! @} */

/*! @name PPMTBFCR - Port pseudo MAC transmit broadcast frame counter register */
/*! @{ */

#define SW_PSEUDO_MAC_PORT2_PPMTBFCR_TBCA_MASK   (0xFFFFFFFFU)
#define SW_PSEUDO_MAC_PORT2_PPMTBFCR_TBCA_SHIFT  (0U)
#define SW_PSEUDO_MAC_PORT2_PPMTBFCR_TBCA_WIDTH  (32U)
#define SW_PSEUDO_MAC_PORT2_PPMTBFCR_TBCA(x)     (((uint32_t)(((uint32_t)(x)) << SW_PSEUDO_MAC_PORT2_PPMTBFCR_TBCA_SHIFT)) & SW_PSEUDO_MAC_PORT2_PPMTBFCR_TBCA_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SW_PSEUDO_MAC_PORT2_Register_Masks */

/*!
 * @}
 */ /* end of group SW_PSEUDO_MAC_PORT2_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_SW_PSEUDO_MAC_PORT2_H_) */
