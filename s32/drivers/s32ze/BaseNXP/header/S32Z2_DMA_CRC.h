/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_DMA_CRC.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_DMA_CRC
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
#if !defined(S32Z2_DMA_CRC_H_)  /* Check if memory map has not been already included */
#define S32Z2_DMA_CRC_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- DMA_CRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_CRC_Peripheral_Access_Layer DMA_CRC Peripheral Access Layer
 * @{
 */

/** DMA_CRC - Size of Registers Arrays */
#define DMA_CRC_CONTROL_REGISTER_COUNT            8u

/** DMA_CRC - Register Layout Typedef */
typedef struct {
  __IO uint32_t GEC;                               /**< Global Enable CRC Register, offset: 0x0 */
  uint8_t RESERVED_0[12];
  struct DMA_CRC_CONTROL_REGISTER {                /* offset: 0x10, array step: 0x10 */
    __IO uint32_t CTL;                               /**< CRC Control Register, array offset: 0x10, array step: 0x10 */
    __IO uint32_t ICRC;                              /**< Initial CRC Value Register, array offset: 0x14, array step: 0x10 */
    __I  uint32_t FCRC;                              /**< Final CRC Value Register, array offset: 0x18, array step: 0x10 */
    uint8_t RESERVED_0[4];
  } CONTROL_REGISTER[DMA_CRC_CONTROL_REGISTER_COUNT];
} DMA_CRC_Type, *DMA_CRC_MemMapPtr;

/** Number of instances of the DMA_CRC module. */
#define DMA_CRC_INSTANCE_COUNT                   (6u)

/* DMA_CRC - Peripheral instance base addresses */
/** Peripheral CE_DMA_CRC base address */
#define IP_CE_DMA_CRC_BASE                       (0x44E08000u)
/** Peripheral CE_DMA_CRC base pointer */
#define IP_CE_DMA_CRC                            ((DMA_CRC_Type *)IP_CE_DMA_CRC_BASE)
/** Peripheral DMA_CRC_0 base address */
#define IP_DMA_CRC_0_BASE                        (0x405E0000u)
/** Peripheral DMA_CRC_0 base pointer */
#define IP_DMA_CRC_0                             ((DMA_CRC_Type *)IP_DMA_CRC_0_BASE)
/** Peripheral DMA_CRC_1 base address */
#define IP_DMA_CRC_1_BASE                        (0x40DE0000u)
/** Peripheral DMA_CRC_1 base pointer */
#define IP_DMA_CRC_1                             ((DMA_CRC_Type *)IP_DMA_CRC_1_BASE)
/** Peripheral DMA_CRC_3 base address */
#define IP_DMA_CRC_3_BASE                        (0x41DE0000u)
/** Peripheral DMA_CRC_3 base pointer */
#define IP_DMA_CRC_3                             ((DMA_CRC_Type *)IP_DMA_CRC_3_BASE)
/** Peripheral DMA_CRC_4 base address */
#define IP_DMA_CRC_4_BASE                        (0x425E0000u)
/** Peripheral DMA_CRC_4 base pointer */
#define IP_DMA_CRC_4                             ((DMA_CRC_Type *)IP_DMA_CRC_4_BASE)
/** Peripheral DMA_CRC_5 base address */
#define IP_DMA_CRC_5_BASE                        (0x42DE0000u)
/** Peripheral DMA_CRC_5 base pointer */
#define IP_DMA_CRC_5                             ((DMA_CRC_Type *)IP_DMA_CRC_5_BASE)
/** Array initializer of DMA_CRC peripheral base addresses */
#define IP_DMA_CRC_BASE_ADDRS                    { IP_CE_DMA_CRC_BASE, IP_DMA_CRC_0_BASE, IP_DMA_CRC_1_BASE, IP_DMA_CRC_3_BASE, IP_DMA_CRC_4_BASE, IP_DMA_CRC_5_BASE }
/** Array initializer of DMA_CRC peripheral base pointers */
#define IP_DMA_CRC_BASE_PTRS                     { IP_CE_DMA_CRC, IP_DMA_CRC_0, IP_DMA_CRC_1, IP_DMA_CRC_3, IP_DMA_CRC_4, IP_DMA_CRC_5 }

/* ----------------------------------------------------------------------------
   -- DMA_CRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_CRC_Register_Masks DMA_CRC Register Masks
 * @{
 */

/*! @name GEC - Global Enable CRC Register */
/*! @{ */

#define DMA_CRC_GEC_GBL_EN_MASK                  (0x1U)
#define DMA_CRC_GEC_GBL_EN_SHIFT                 (0U)
#define DMA_CRC_GEC_GBL_EN_WIDTH                 (1U)
#define DMA_CRC_GEC_GBL_EN(x)                    (((uint32_t)(((uint32_t)(x)) << DMA_CRC_GEC_GBL_EN_SHIFT)) & DMA_CRC_GEC_GBL_EN_MASK)

#define DMA_CRC_GEC_SWAP_BYTE_MASK               (0x80U)
#define DMA_CRC_GEC_SWAP_BYTE_SHIFT              (7U)
#define DMA_CRC_GEC_SWAP_BYTE_WIDTH              (1U)
#define DMA_CRC_GEC_SWAP_BYTE(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_CRC_GEC_SWAP_BYTE_SHIFT)) & DMA_CRC_GEC_SWAP_BYTE_MASK)
/*! @} */

/*! @name CTL - CRC Control Register */
/*! @{ */

#define DMA_CRC_CTL_CH_SEL_MASK                  (0x1FU)  /* Merged from fields with different position or width, of widths (4, 5), largest definition used */
#define DMA_CRC_CTL_CH_SEL_SHIFT                 (0U)
#define DMA_CRC_CTL_CH_SEL_WIDTH                 (5U)
#define DMA_CRC_CTL_CH_SEL(x)                    (((uint32_t)(((uint32_t)(x)) << DMA_CRC_CTL_CH_SEL_SHIFT)) & DMA_CRC_CTL_CH_SEL_MASK)  /* Merged from fields with different position or width, of widths (4, 5), largest definition used */

#define DMA_CRC_CTL_POLY_SEL_MASK                (0x700U)
#define DMA_CRC_CTL_POLY_SEL_SHIFT               (8U)
#define DMA_CRC_CTL_POLY_SEL_WIDTH               (3U)
#define DMA_CRC_CTL_POLY_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << DMA_CRC_CTL_POLY_SEL_SHIFT)) & DMA_CRC_CTL_POLY_SEL_MASK)

#define DMA_CRC_CTL_CS_XOR_MASK                  (0x1000U)
#define DMA_CRC_CTL_CS_XOR_SHIFT                 (12U)
#define DMA_CRC_CTL_CS_XOR_WIDTH                 (1U)
#define DMA_CRC_CTL_CS_XOR(x)                    (((uint32_t)(((uint32_t)(x)) << DMA_CRC_CTL_CS_XOR_SHIFT)) & DMA_CRC_CTL_CS_XOR_MASK)

#define DMA_CRC_CTL_CS_SWAP_MASK                 (0x2000U)
#define DMA_CRC_CTL_CS_SWAP_SHIFT                (13U)
#define DMA_CRC_CTL_CS_SWAP_WIDTH                (1U)
#define DMA_CRC_CTL_CS_SWAP(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_CRC_CTL_CS_SWAP_SHIFT)) & DMA_CRC_CTL_CS_SWAP_MASK)

#define DMA_CRC_CTL_SWAP_BIT_MASK                (0x4000U)
#define DMA_CRC_CTL_SWAP_BIT_SHIFT               (14U)
#define DMA_CRC_CTL_SWAP_BIT_WIDTH               (1U)
#define DMA_CRC_CTL_SWAP_BIT(x)                  (((uint32_t)(((uint32_t)(x)) << DMA_CRC_CTL_SWAP_BIT_SHIFT)) & DMA_CRC_CTL_SWAP_BIT_MASK)

#define DMA_CRC_CTL_INIT_SEL_MASK                (0x8000U)
#define DMA_CRC_CTL_INIT_SEL_SHIFT               (15U)
#define DMA_CRC_CTL_INIT_SEL_WIDTH               (1U)
#define DMA_CRC_CTL_INIT_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << DMA_CRC_CTL_INIT_SEL_SHIFT)) & DMA_CRC_CTL_INIT_SEL_MASK)

#define DMA_CRC_CTL_MODE_MASK                    (0x70000U)
#define DMA_CRC_CTL_MODE_SHIFT                   (16U)
#define DMA_CRC_CTL_MODE_WIDTH                   (3U)
#define DMA_CRC_CTL_MODE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_CRC_CTL_MODE_SHIFT)) & DMA_CRC_CTL_MODE_MASK)

#define DMA_CRC_CTL_EN_MASK                      (0x80000000U)
#define DMA_CRC_CTL_EN_SHIFT                     (31U)
#define DMA_CRC_CTL_EN_WIDTH                     (1U)
#define DMA_CRC_CTL_EN(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CRC_CTL_EN_SHIFT)) & DMA_CRC_CTL_EN_MASK)
/*! @} */

/*! @name ICRC - Initial CRC Value Register */
/*! @{ */

#define DMA_CRC_ICRC_INI_CRC_VAL_MASK            (0xFFFFFFFFU)
#define DMA_CRC_ICRC_INI_CRC_VAL_SHIFT           (0U)
#define DMA_CRC_ICRC_INI_CRC_VAL_WIDTH           (32U)
#define DMA_CRC_ICRC_INI_CRC_VAL(x)              (((uint32_t)(((uint32_t)(x)) << DMA_CRC_ICRC_INI_CRC_VAL_SHIFT)) & DMA_CRC_ICRC_INI_CRC_VAL_MASK)
/*! @} */

/*! @name FCRC - Final CRC Value Register */
/*! @{ */

#define DMA_CRC_FCRC_CHKSUM_VAL_MASK             (0xFFFFFFFFU)
#define DMA_CRC_FCRC_CHKSUM_VAL_SHIFT            (0U)
#define DMA_CRC_FCRC_CHKSUM_VAL_WIDTH            (32U)
#define DMA_CRC_FCRC_CHKSUM_VAL(x)               (((uint32_t)(((uint32_t)(x)) << DMA_CRC_FCRC_CHKSUM_VAL_SHIFT)) & DMA_CRC_FCRC_CHKSUM_VAL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group DMA_CRC_Register_Masks */

/*!
 * @}
 */ /* end of group DMA_CRC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_DMA_CRC_H_) */
