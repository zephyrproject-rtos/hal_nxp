/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_CRC.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_CRC
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
#if !defined(S32Z2_CRC_H_)  /* Check if memory map has not been already included */
#define S32Z2_CRC_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Peripheral_Access_Layer CRC Peripheral Access Layer
 * @{
 */

/** CRC - Size of Registers Arrays */
#define CRC_CHANNEL_COUNT                         3u

/** CRC - Register Layout Typedef */
typedef struct {
  struct CRC_CHANNEL {                             /* offset: 0x0, array step: 0x10 */
    __IO uint32_t CFG;                               /**< Configuration Register, array offset: 0x0, array step: 0x10 */
    __IO uint32_t INP;                               /**< Input Register, array offset: 0x4, array step: 0x10 */
    __IO uint32_t CSTAT;                             /**< Current Status Register, array offset: 0x8, array step: 0x10 */
    __I  uint32_t OUTP;                              /**< Output Register, array offset: 0xC, array step: 0x10 */
  } CHANNEL[CRC_CHANNEL_COUNT];
} CRC_Type, *CRC_MemMapPtr;

/** Number of instances of the CRC module. */
#define CRC_INSTANCE_COUNT                       (8u)

/* CRC - Peripheral instance base addresses */
/** Peripheral CE_CRC_0 base address */
#define IP_CE_CRC_0_BASE                         (0x44A88000u)
/** Peripheral CE_CRC_0 base pointer */
#define IP_CE_CRC_0                              ((CRC_Type *)IP_CE_CRC_0_BASE)
/** Peripheral CE_CRC_1 base address */
#define IP_CE_CRC_1_BASE                         (0x44A98000u)
/** Peripheral CE_CRC_1 base pointer */
#define IP_CE_CRC_1                              ((CRC_Type *)IP_CE_CRC_1_BASE)
/** Peripheral CE_CRC_2 base address */
#define IP_CE_CRC_2_BASE                         (0x44AA8000u)
/** Peripheral CE_CRC_2 base pointer */
#define IP_CE_CRC_2                              ((CRC_Type *)IP_CE_CRC_2_BASE)
/** Peripheral CE_CRC_3 base address */
#define IP_CE_CRC_3_BASE                         (0x44AB8000u)
/** Peripheral CE_CRC_3 base pointer */
#define IP_CE_CRC_3                              ((CRC_Type *)IP_CE_CRC_3_BASE)
/** Peripheral CE_CRC_4 base address */
#define IP_CE_CRC_4_BASE                         (0x44AC8000u)
/** Peripheral CE_CRC_4 base pointer */
#define IP_CE_CRC_4                              ((CRC_Type *)IP_CE_CRC_4_BASE)
/** Peripheral CE_CRC_5 base address */
#define IP_CE_CRC_5_BASE                         (0x44AD8000u)
/** Peripheral CE_CRC_5 base pointer */
#define IP_CE_CRC_5                              ((CRC_Type *)IP_CE_CRC_5_BASE)
/** Peripheral RTU0__CRC base address */
#define IP_RTU0__CRC_BASE                        (0x761C0000u)
/** Peripheral RTU0__CRC base pointer */
#define IP_RTU0__CRC                             ((CRC_Type *)IP_RTU0__CRC_BASE)
/** Peripheral RTU1__CRC base address */
#define IP_RTU1__CRC_BASE                        (0x769C0000u)
/** Peripheral RTU1__CRC base pointer */
#define IP_RTU1__CRC                             ((CRC_Type *)IP_RTU1__CRC_BASE)
/** Array initializer of CRC peripheral base addresses */
#define IP_CRC_BASE_ADDRS                        { IP_CE_CRC_0_BASE, IP_CE_CRC_1_BASE, IP_CE_CRC_2_BASE, IP_CE_CRC_3_BASE, IP_CE_CRC_4_BASE, IP_CE_CRC_5_BASE, IP_RTU0__CRC_BASE, IP_RTU1__CRC_BASE }
/** Array initializer of CRC peripheral base pointers */
#define IP_CRC_BASE_PTRS                         { IP_CE_CRC_0, IP_CE_CRC_1, IP_CE_CRC_2, IP_CE_CRC_3, IP_CE_CRC_4, IP_CE_CRC_5, IP_RTU0__CRC, IP_RTU1__CRC }

/* ----------------------------------------------------------------------------
   -- CRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Register_Masks CRC Register Masks
 * @{
 */

/*! @name CFG - Configuration Register */
/*! @{ */

#define CRC_CFG_INV_MASK                         (0x1U)
#define CRC_CFG_INV_SHIFT                        (0U)
#define CRC_CFG_INV_WIDTH                        (1U)
#define CRC_CFG_INV(x)                           (((uint32_t)(((uint32_t)(x)) << CRC_CFG_INV_SHIFT)) & CRC_CFG_INV_MASK)

#define CRC_CFG_SWAP_MASK                        (0x2U)
#define CRC_CFG_SWAP_SHIFT                       (1U)
#define CRC_CFG_SWAP_WIDTH                       (1U)
#define CRC_CFG_SWAP(x)                          (((uint32_t)(((uint32_t)(x)) << CRC_CFG_SWAP_SHIFT)) & CRC_CFG_SWAP_MASK)

#define CRC_CFG_POLYG_MASK                       (0xCU)
#define CRC_CFG_POLYG_SHIFT                      (2U)
#define CRC_CFG_POLYG_WIDTH                      (2U)
#define CRC_CFG_POLYG(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_CFG_POLYG_SHIFT)) & CRC_CFG_POLYG_MASK)

#define CRC_CFG_SWAP_BITWISE_MASK                (0x10U)
#define CRC_CFG_SWAP_BITWISE_SHIFT               (4U)
#define CRC_CFG_SWAP_BITWISE_WIDTH               (1U)
#define CRC_CFG_SWAP_BITWISE(x)                  (((uint32_t)(((uint32_t)(x)) << CRC_CFG_SWAP_BITWISE_SHIFT)) & CRC_CFG_SWAP_BITWISE_MASK)

#define CRC_CFG_SWAP_BYTEWISE_MASK               (0x20U)
#define CRC_CFG_SWAP_BYTEWISE_SHIFT              (5U)
#define CRC_CFG_SWAP_BYTEWISE_WIDTH              (1U)
#define CRC_CFG_SWAP_BYTEWISE(x)                 (((uint32_t)(((uint32_t)(x)) << CRC_CFG_SWAP_BYTEWISE_SHIFT)) & CRC_CFG_SWAP_BYTEWISE_MASK)
/*! @} */

/*! @name INP - Input Register */
/*! @{ */

#define CRC_INP_INP_MASK                         (0xFFFFFFFFU)
#define CRC_INP_INP_SHIFT                        (0U)
#define CRC_INP_INP_WIDTH                        (32U)
#define CRC_INP_INP(x)                           (((uint32_t)(((uint32_t)(x)) << CRC_INP_INP_SHIFT)) & CRC_INP_INP_MASK)
/*! @} */

/*! @name CSTAT - Current Status Register */
/*! @{ */

#define CRC_CSTAT_CSTAT_MASK                     (0xFFFFFFFFU)
#define CRC_CSTAT_CSTAT_SHIFT                    (0U)
#define CRC_CSTAT_CSTAT_WIDTH                    (32U)
#define CRC_CSTAT_CSTAT(x)                       (((uint32_t)(((uint32_t)(x)) << CRC_CSTAT_CSTAT_SHIFT)) & CRC_CSTAT_CSTAT_MASK)
/*! @} */

/*! @name OUTP - Output Register */
/*! @{ */

#define CRC_OUTP_OUTP_MASK                       (0xFFFFFFFFU)
#define CRC_OUTP_OUTP_SHIFT                      (0U)
#define CRC_OUTP_OUTP_WIDTH                      (32U)
#define CRC_OUTP_OUTP(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_OUTP_OUTP_SHIFT)) & CRC_OUTP_OUTP_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CRC_Register_Masks */

/*!
 * @}
 */ /* end of group CRC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_CRC_H_) */
