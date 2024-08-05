/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_FEED_DMACRC.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_FEED_DMACRC
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
#if !defined(S32Z2_FEED_DMACRC_H_)  /* Check if memory map has not been already included */
#define S32Z2_FEED_DMACRC_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- FEED_DMACRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FEED_DMACRC_Peripheral_Access_Layer FEED_DMACRC Peripheral Access Layer
 * @{
 */

/** FEED_DMACRC - Size of Registers Arrays */
#define FEED_DMACRC_CONTROL_REGISTER_COUNT        8u

/** FEED_DMACRC - Register Layout Typedef */
typedef struct {
  __IO uint32_t GEC;                               /**< Global Enable CRC Register, offset: 0x0 */
  uint8_t RESERVED_0[12];
  struct FEED_DMACRC_CONTROL_REGISTER {            /* offset: 0x10, array step: 0x10 */
    __IO uint32_t CTL;                               /**< CRC Control Register, array offset: 0x10, array step: 0x10 */
    __IO uint32_t ICRC;                              /**< Initial CRC Value Register, array offset: 0x14, array step: 0x10 */
    __I  uint32_t FCRC;                              /**< Final CRC Value Register, array offset: 0x18, array step: 0x10 */
    uint8_t RESERVED_0[4];
  } CONTROL_REGISTER[FEED_DMACRC_CONTROL_REGISTER_COUNT];
} FEED_DMACRC_Type, *FEED_DMACRC_MemMapPtr;

/** Number of instances of the FEED_DMACRC module. */
#define FEED_DMACRC_INSTANCE_COUNT               (1u)

/* FEED_DMACRC - Peripheral instance base addresses */
/** Peripheral AES__FEED_DMACRC base address */
#define IP_AES__FEED_DMACRC_BASE                 (0x47230000u)
/** Peripheral AES__FEED_DMACRC base pointer */
#define IP_AES__FEED_DMACRC                      ((FEED_DMACRC_Type *)IP_AES__FEED_DMACRC_BASE)
/** Array initializer of FEED_DMACRC peripheral base addresses */
#define IP_FEED_DMACRC_BASE_ADDRS                { IP_AES__FEED_DMACRC_BASE }
/** Array initializer of FEED_DMACRC peripheral base pointers */
#define IP_FEED_DMACRC_BASE_PTRS                 { IP_AES__FEED_DMACRC }

/* ----------------------------------------------------------------------------
   -- FEED_DMACRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FEED_DMACRC_Register_Masks FEED_DMACRC Register Masks
 * @{
 */

/*! @name GEC - Global Enable CRC Register */
/*! @{ */

#define FEED_DMACRC_GEC_GBL_EN_MASK              (0x1U)
#define FEED_DMACRC_GEC_GBL_EN_SHIFT             (0U)
#define FEED_DMACRC_GEC_GBL_EN_WIDTH             (1U)
#define FEED_DMACRC_GEC_GBL_EN(x)                (((uint32_t)(((uint32_t)(x)) << FEED_DMACRC_GEC_GBL_EN_SHIFT)) & FEED_DMACRC_GEC_GBL_EN_MASK)

#define FEED_DMACRC_GEC_SWAP_BYTE_MASK           (0x80U)
#define FEED_DMACRC_GEC_SWAP_BYTE_SHIFT          (7U)
#define FEED_DMACRC_GEC_SWAP_BYTE_WIDTH          (1U)
#define FEED_DMACRC_GEC_SWAP_BYTE(x)             (((uint32_t)(((uint32_t)(x)) << FEED_DMACRC_GEC_SWAP_BYTE_SHIFT)) & FEED_DMACRC_GEC_SWAP_BYTE_MASK)
/*! @} */

/*! @name CTL - CRC Control Register */
/*! @{ */

#define FEED_DMACRC_CTL_CH_SEL_MASK              (0x1FU)
#define FEED_DMACRC_CTL_CH_SEL_SHIFT             (0U)
#define FEED_DMACRC_CTL_CH_SEL_WIDTH             (5U)
#define FEED_DMACRC_CTL_CH_SEL(x)                (((uint32_t)(((uint32_t)(x)) << FEED_DMACRC_CTL_CH_SEL_SHIFT)) & FEED_DMACRC_CTL_CH_SEL_MASK)

#define FEED_DMACRC_CTL_POLY_SEL_MASK            (0x700U)
#define FEED_DMACRC_CTL_POLY_SEL_SHIFT           (8U)
#define FEED_DMACRC_CTL_POLY_SEL_WIDTH           (3U)
#define FEED_DMACRC_CTL_POLY_SEL(x)              (((uint32_t)(((uint32_t)(x)) << FEED_DMACRC_CTL_POLY_SEL_SHIFT)) & FEED_DMACRC_CTL_POLY_SEL_MASK)

#define FEED_DMACRC_CTL_CS_XOR_MASK              (0x1000U)
#define FEED_DMACRC_CTL_CS_XOR_SHIFT             (12U)
#define FEED_DMACRC_CTL_CS_XOR_WIDTH             (1U)
#define FEED_DMACRC_CTL_CS_XOR(x)                (((uint32_t)(((uint32_t)(x)) << FEED_DMACRC_CTL_CS_XOR_SHIFT)) & FEED_DMACRC_CTL_CS_XOR_MASK)

#define FEED_DMACRC_CTL_CS_SWAP_MASK             (0x2000U)
#define FEED_DMACRC_CTL_CS_SWAP_SHIFT            (13U)
#define FEED_DMACRC_CTL_CS_SWAP_WIDTH            (1U)
#define FEED_DMACRC_CTL_CS_SWAP(x)               (((uint32_t)(((uint32_t)(x)) << FEED_DMACRC_CTL_CS_SWAP_SHIFT)) & FEED_DMACRC_CTL_CS_SWAP_MASK)

#define FEED_DMACRC_CTL_SWAP_BIT_MASK            (0x4000U)
#define FEED_DMACRC_CTL_SWAP_BIT_SHIFT           (14U)
#define FEED_DMACRC_CTL_SWAP_BIT_WIDTH           (1U)
#define FEED_DMACRC_CTL_SWAP_BIT(x)              (((uint32_t)(((uint32_t)(x)) << FEED_DMACRC_CTL_SWAP_BIT_SHIFT)) & FEED_DMACRC_CTL_SWAP_BIT_MASK)

#define FEED_DMACRC_CTL_INIT_SEL_MASK            (0x8000U)
#define FEED_DMACRC_CTL_INIT_SEL_SHIFT           (15U)
#define FEED_DMACRC_CTL_INIT_SEL_WIDTH           (1U)
#define FEED_DMACRC_CTL_INIT_SEL(x)              (((uint32_t)(((uint32_t)(x)) << FEED_DMACRC_CTL_INIT_SEL_SHIFT)) & FEED_DMACRC_CTL_INIT_SEL_MASK)

#define FEED_DMACRC_CTL_MODE_MASK                (0x70000U)
#define FEED_DMACRC_CTL_MODE_SHIFT               (16U)
#define FEED_DMACRC_CTL_MODE_WIDTH               (3U)
#define FEED_DMACRC_CTL_MODE(x)                  (((uint32_t)(((uint32_t)(x)) << FEED_DMACRC_CTL_MODE_SHIFT)) & FEED_DMACRC_CTL_MODE_MASK)

#define FEED_DMACRC_CTL_EN_MASK                  (0x80000000U)
#define FEED_DMACRC_CTL_EN_SHIFT                 (31U)
#define FEED_DMACRC_CTL_EN_WIDTH                 (1U)
#define FEED_DMACRC_CTL_EN(x)                    (((uint32_t)(((uint32_t)(x)) << FEED_DMACRC_CTL_EN_SHIFT)) & FEED_DMACRC_CTL_EN_MASK)
/*! @} */

/*! @name ICRC - Initial CRC Value Register */
/*! @{ */

#define FEED_DMACRC_ICRC_INI_CRC_VAL_MASK        (0xFFFFFFFFU)
#define FEED_DMACRC_ICRC_INI_CRC_VAL_SHIFT       (0U)
#define FEED_DMACRC_ICRC_INI_CRC_VAL_WIDTH       (32U)
#define FEED_DMACRC_ICRC_INI_CRC_VAL(x)          (((uint32_t)(((uint32_t)(x)) << FEED_DMACRC_ICRC_INI_CRC_VAL_SHIFT)) & FEED_DMACRC_ICRC_INI_CRC_VAL_MASK)
/*! @} */

/*! @name FCRC - Final CRC Value Register */
/*! @{ */

#define FEED_DMACRC_FCRC_CHKSUM_VAL_MASK         (0xFFFFFFFFU)
#define FEED_DMACRC_FCRC_CHKSUM_VAL_SHIFT        (0U)
#define FEED_DMACRC_FCRC_CHKSUM_VAL_WIDTH        (32U)
#define FEED_DMACRC_FCRC_CHKSUM_VAL(x)           (((uint32_t)(((uint32_t)(x)) << FEED_DMACRC_FCRC_CHKSUM_VAL_SHIFT)) & FEED_DMACRC_FCRC_CHKSUM_VAL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group FEED_DMACRC_Register_Masks */

/*!
 * @}
 */ /* end of group FEED_DMACRC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_FEED_DMACRC_H_) */
