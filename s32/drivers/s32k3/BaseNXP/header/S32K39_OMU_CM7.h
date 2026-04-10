/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K39_OMU_CM7.h
 * @version 1.7
 * @date 2022-11-18
 * @brief Peripheral Access Layer for S32K39_OMU_CM7
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
#if !defined(S32K39_OMU_CM7_H_)  /* Check if memory map has not been already included */
#define S32K39_OMU_CM7_H_

#include "S32K39_COMMON.h"

/* ----------------------------------------------------------------------------
   -- OMU_CM7 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OMU_CM7_Peripheral_Access_Layer OMU_CM7 Peripheral Access Layer
 * @{
 */

/** OMU_CM7 - Size of Registers Arrays */
#define OMU_CM7_ZONE_REGS_COUNT                   4u
#define OMU_CM7_OVERLAY_REGION_DESCRIPTOR_COUNT   16u

/** OMU_CM7 - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x1000 */
    __I  uint32_t ZZRSR;                             /**< Zone Request Status 0..Zone Request Status 3, array offset: 0x0, array step: 0x1000 */
    __IO uint32_t ZER;                               /**< Zone Enable 0..Zone Enable 3, array offset: 0x4, array step: 0x1000 */
    uint8_t RESERVED_0[4088];
  } ZONE_REGS[OMU_CM7_ZONE_REGS_COUNT];
  __IO uint32_t OER;                               /**< OMU Enable, offset: 0x4000 */
  __IO uint32_t ZRR;                               /**< Zone Request, offset: 0x4004 */
  __I  uint32_t ZESR;                              /**< Zone Enable Status, offset: 0x4008 */
  __IO uint32_t GZRR;                              /**< Global Zone Request, offset: 0x400C */
  uint8_t RESERVED_0[1008];
  struct {                                         /* offset: 0x4400, array step: 0x10 */
    __IO uint32_t ORDLSA;                            /**< ORD0 Logical Start Address..ORD15 Logical Start Address, array offset: 0x4400, array step: 0x10 */
    __IO uint32_t ORDPSA;                            /**< ORD0 Physical Start Address..ORD15 Physical Start Address, array offset: 0x4404, array step: 0x10 */
    __IO uint32_t ORDRS;                             /**< ORD0 Region Size..ORD15 Region Size, array offset: 0x4408, array step: 0x10 */
    __IO uint32_t ORDRZA;                            /**< ORD0 Region Zone Assignment..ORD15 Region Zone Assignment, array offset: 0x440C, array step: 0x10 */
  } OVERLAY_REGION_DESCRIPTOR[OMU_CM7_OVERLAY_REGION_DESCRIPTOR_COUNT];
} OMU_CM7_Type, *OMU_CM7_MemMapPtr;

/** Number of instances of the OMU_CM7 module. */
#define OMU_CM7_INSTANCE_COUNT                   (3u)

/* OMU_CM7 - Peripheral instance base addresses */
/** Peripheral OMU_CM7_0 base address */
#define IP_OMU_CM7_0_BASE                        (0x40518000u)
/** Peripheral OMU_CM7_0 base pointer */
#define IP_OMU_CM7_0                             ((OMU_CM7_Type *)IP_OMU_CM7_0_BASE)
/** Peripheral OMU_CM7_1 base address */
#define IP_OMU_CM7_1_BASE                        (0x40520000u)
/** Peripheral OMU_CM7_1 base pointer */
#define IP_OMU_CM7_1                             ((OMU_CM7_Type *)IP_OMU_CM7_1_BASE)
/** Peripheral OMU_CM7_2 base address */
#define IP_OMU_CM7_2_BASE                        (0x40528000u)
/** Peripheral OMU_CM7_2 base pointer */
#define IP_OMU_CM7_2                             ((OMU_CM7_Type *)IP_OMU_CM7_2_BASE)
/** Array initializer of OMU_CM7 peripheral base addresses */
#define IP_OMU_CM7_BASE_ADDRS                    { IP_OMU_CM7_0_BASE, IP_OMU_CM7_1_BASE, IP_OMU_CM7_2_BASE }
/** Array initializer of OMU_CM7 peripheral base pointers */
#define IP_OMU_CM7_BASE_PTRS                     { IP_OMU_CM7_0, IP_OMU_CM7_1, IP_OMU_CM7_2 }

/* ----------------------------------------------------------------------------
   -- OMU_CM7 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OMU_CM7_Register_Masks OMU_CM7 Register Masks
 * @{
 */

/*! @name ZZRSR - Zone Request Status 0..Zone Request Status 3 */
/*! @{ */

#define OMU_CM7_ZZRSR_Z0RS_MASK                  (0x1U)
#define OMU_CM7_ZZRSR_Z0RS_SHIFT                 (0U)
#define OMU_CM7_ZZRSR_Z0RS_WIDTH                 (1U)
#define OMU_CM7_ZZRSR_Z0RS(x)                    (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZZRSR_Z0RS_SHIFT)) & OMU_CM7_ZZRSR_Z0RS_MASK)

#define OMU_CM7_ZZRSR_Z2RS_MASK                  (0x1U)
#define OMU_CM7_ZZRSR_Z2RS_SHIFT                 (0U)
#define OMU_CM7_ZZRSR_Z2RS_WIDTH                 (1U)
#define OMU_CM7_ZZRSR_Z2RS(x)                    (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZZRSR_Z2RS_SHIFT)) & OMU_CM7_ZZRSR_Z2RS_MASK)

#define OMU_CM7_ZZRSR_Z4RS_MASK                  (0x1U)
#define OMU_CM7_ZZRSR_Z4RS_SHIFT                 (0U)
#define OMU_CM7_ZZRSR_Z4RS_WIDTH                 (1U)
#define OMU_CM7_ZZRSR_Z4RS(x)                    (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZZRSR_Z4RS_SHIFT)) & OMU_CM7_ZZRSR_Z4RS_MASK)

#define OMU_CM7_ZZRSR_Z6RS_MASK                  (0x1U)
#define OMU_CM7_ZZRSR_Z6RS_SHIFT                 (0U)
#define OMU_CM7_ZZRSR_Z6RS_WIDTH                 (1U)
#define OMU_CM7_ZZRSR_Z6RS(x)                    (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZZRSR_Z6RS_SHIFT)) & OMU_CM7_ZZRSR_Z6RS_MASK)

#define OMU_CM7_ZZRSR_Z1RS_MASK                  (0x2U)
#define OMU_CM7_ZZRSR_Z1RS_SHIFT                 (1U)
#define OMU_CM7_ZZRSR_Z1RS_WIDTH                 (1U)
#define OMU_CM7_ZZRSR_Z1RS(x)                    (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZZRSR_Z1RS_SHIFT)) & OMU_CM7_ZZRSR_Z1RS_MASK)

#define OMU_CM7_ZZRSR_Z3RS_MASK                  (0x2U)
#define OMU_CM7_ZZRSR_Z3RS_SHIFT                 (1U)
#define OMU_CM7_ZZRSR_Z3RS_WIDTH                 (1U)
#define OMU_CM7_ZZRSR_Z3RS(x)                    (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZZRSR_Z3RS_SHIFT)) & OMU_CM7_ZZRSR_Z3RS_MASK)

#define OMU_CM7_ZZRSR_Z5RS_MASK                  (0x2U)
#define OMU_CM7_ZZRSR_Z5RS_SHIFT                 (1U)
#define OMU_CM7_ZZRSR_Z5RS_WIDTH                 (1U)
#define OMU_CM7_ZZRSR_Z5RS(x)                    (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZZRSR_Z5RS_SHIFT)) & OMU_CM7_ZZRSR_Z5RS_MASK)

#define OMU_CM7_ZZRSR_Z7RS_MASK                  (0x2U)
#define OMU_CM7_ZZRSR_Z7RS_SHIFT                 (1U)
#define OMU_CM7_ZZRSR_Z7RS_WIDTH                 (1U)
#define OMU_CM7_ZZRSR_Z7RS(x)                    (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZZRSR_Z7RS_SHIFT)) & OMU_CM7_ZZRSR_Z7RS_MASK)
/*! @} */

/*! @name ZER - Zone Enable 0..Zone Enable 3 */
/*! @{ */

#define OMU_CM7_ZER_Z0E_MASK                     (0x1U)
#define OMU_CM7_ZER_Z0E_SHIFT                    (0U)
#define OMU_CM7_ZER_Z0E_WIDTH                    (1U)
#define OMU_CM7_ZER_Z0E(x)                       (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZER_Z0E_SHIFT)) & OMU_CM7_ZER_Z0E_MASK)

#define OMU_CM7_ZER_Z2E_MASK                     (0x1U)
#define OMU_CM7_ZER_Z2E_SHIFT                    (0U)
#define OMU_CM7_ZER_Z2E_WIDTH                    (1U)
#define OMU_CM7_ZER_Z2E(x)                       (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZER_Z2E_SHIFT)) & OMU_CM7_ZER_Z2E_MASK)

#define OMU_CM7_ZER_Z4E_MASK                     (0x1U)
#define OMU_CM7_ZER_Z4E_SHIFT                    (0U)
#define OMU_CM7_ZER_Z4E_WIDTH                    (1U)
#define OMU_CM7_ZER_Z4E(x)                       (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZER_Z4E_SHIFT)) & OMU_CM7_ZER_Z4E_MASK)

#define OMU_CM7_ZER_Z6E_MASK                     (0x1U)
#define OMU_CM7_ZER_Z6E_SHIFT                    (0U)
#define OMU_CM7_ZER_Z6E_WIDTH                    (1U)
#define OMU_CM7_ZER_Z6E(x)                       (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZER_Z6E_SHIFT)) & OMU_CM7_ZER_Z6E_MASK)

#define OMU_CM7_ZER_Z1E_MASK                     (0x2U)
#define OMU_CM7_ZER_Z1E_SHIFT                    (1U)
#define OMU_CM7_ZER_Z1E_WIDTH                    (1U)
#define OMU_CM7_ZER_Z1E(x)                       (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZER_Z1E_SHIFT)) & OMU_CM7_ZER_Z1E_MASK)

#define OMU_CM7_ZER_Z3E_MASK                     (0x2U)
#define OMU_CM7_ZER_Z3E_SHIFT                    (1U)
#define OMU_CM7_ZER_Z3E_WIDTH                    (1U)
#define OMU_CM7_ZER_Z3E(x)                       (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZER_Z3E_SHIFT)) & OMU_CM7_ZER_Z3E_MASK)

#define OMU_CM7_ZER_Z5E_MASK                     (0x2U)
#define OMU_CM7_ZER_Z5E_SHIFT                    (1U)
#define OMU_CM7_ZER_Z5E_WIDTH                    (1U)
#define OMU_CM7_ZER_Z5E(x)                       (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZER_Z5E_SHIFT)) & OMU_CM7_ZER_Z5E_MASK)

#define OMU_CM7_ZER_Z7E_MASK                     (0x2U)
#define OMU_CM7_ZER_Z7E_SHIFT                    (1U)
#define OMU_CM7_ZER_Z7E_WIDTH                    (1U)
#define OMU_CM7_ZER_Z7E(x)                       (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZER_Z7E_SHIFT)) & OMU_CM7_ZER_Z7E_MASK)
/*! @} */

/*! @name OER - OMU Enable */
/*! @{ */

#define OMU_CM7_OER_OE_MASK                      (0x1U)
#define OMU_CM7_OER_OE_SHIFT                     (0U)
#define OMU_CM7_OER_OE_WIDTH                     (1U)
#define OMU_CM7_OER_OE(x)                        (((uint32_t)(((uint32_t)(x)) << OMU_CM7_OER_OE_SHIFT)) & OMU_CM7_OER_OE_MASK)

#define OMU_CM7_OER_ZRGUE_MASK                   (0x2U)
#define OMU_CM7_OER_ZRGUE_SHIFT                  (1U)
#define OMU_CM7_OER_ZRGUE_WIDTH                  (1U)
#define OMU_CM7_OER_ZRGUE(x)                     (((uint32_t)(((uint32_t)(x)) << OMU_CM7_OER_ZRGUE_SHIFT)) & OMU_CM7_OER_ZRGUE_MASK)
/*! @} */

/*! @name ZRR - Zone Request */
/*! @{ */

#define OMU_CM7_ZRR_Z0R_MASK                     (0x1U)
#define OMU_CM7_ZRR_Z0R_SHIFT                    (0U)
#define OMU_CM7_ZRR_Z0R_WIDTH                    (1U)
#define OMU_CM7_ZRR_Z0R(x)                       (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZRR_Z0R_SHIFT)) & OMU_CM7_ZRR_Z0R_MASK)

#define OMU_CM7_ZRR_Z1R_MASK                     (0x2U)
#define OMU_CM7_ZRR_Z1R_SHIFT                    (1U)
#define OMU_CM7_ZRR_Z1R_WIDTH                    (1U)
#define OMU_CM7_ZRR_Z1R(x)                       (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZRR_Z1R_SHIFT)) & OMU_CM7_ZRR_Z1R_MASK)

#define OMU_CM7_ZRR_Z2R_MASK                     (0x4U)
#define OMU_CM7_ZRR_Z2R_SHIFT                    (2U)
#define OMU_CM7_ZRR_Z2R_WIDTH                    (1U)
#define OMU_CM7_ZRR_Z2R(x)                       (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZRR_Z2R_SHIFT)) & OMU_CM7_ZRR_Z2R_MASK)

#define OMU_CM7_ZRR_Z3R_MASK                     (0x8U)
#define OMU_CM7_ZRR_Z3R_SHIFT                    (3U)
#define OMU_CM7_ZRR_Z3R_WIDTH                    (1U)
#define OMU_CM7_ZRR_Z3R(x)                       (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZRR_Z3R_SHIFT)) & OMU_CM7_ZRR_Z3R_MASK)

#define OMU_CM7_ZRR_Z4R_MASK                     (0x10U)
#define OMU_CM7_ZRR_Z4R_SHIFT                    (4U)
#define OMU_CM7_ZRR_Z4R_WIDTH                    (1U)
#define OMU_CM7_ZRR_Z4R(x)                       (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZRR_Z4R_SHIFT)) & OMU_CM7_ZRR_Z4R_MASK)

#define OMU_CM7_ZRR_Z5R_MASK                     (0x20U)
#define OMU_CM7_ZRR_Z5R_SHIFT                    (5U)
#define OMU_CM7_ZRR_Z5R_WIDTH                    (1U)
#define OMU_CM7_ZRR_Z5R(x)                       (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZRR_Z5R_SHIFT)) & OMU_CM7_ZRR_Z5R_MASK)

#define OMU_CM7_ZRR_Z6R_MASK                     (0x40U)
#define OMU_CM7_ZRR_Z6R_SHIFT                    (6U)
#define OMU_CM7_ZRR_Z6R_WIDTH                    (1U)
#define OMU_CM7_ZRR_Z6R(x)                       (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZRR_Z6R_SHIFT)) & OMU_CM7_ZRR_Z6R_MASK)

#define OMU_CM7_ZRR_Z7R_MASK                     (0x80U)
#define OMU_CM7_ZRR_Z7R_SHIFT                    (7U)
#define OMU_CM7_ZRR_Z7R_WIDTH                    (1U)
#define OMU_CM7_ZRR_Z7R(x)                       (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZRR_Z7R_SHIFT)) & OMU_CM7_ZRR_Z7R_MASK)
/*! @} */

/*! @name ZESR - Zone Enable Status */
/*! @{ */

#define OMU_CM7_ZESR_Z0ES_MASK                   (0x1U)
#define OMU_CM7_ZESR_Z0ES_SHIFT                  (0U)
#define OMU_CM7_ZESR_Z0ES_WIDTH                  (1U)
#define OMU_CM7_ZESR_Z0ES(x)                     (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZESR_Z0ES_SHIFT)) & OMU_CM7_ZESR_Z0ES_MASK)

#define OMU_CM7_ZESR_Z1ES_MASK                   (0x2U)
#define OMU_CM7_ZESR_Z1ES_SHIFT                  (1U)
#define OMU_CM7_ZESR_Z1ES_WIDTH                  (1U)
#define OMU_CM7_ZESR_Z1ES(x)                     (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZESR_Z1ES_SHIFT)) & OMU_CM7_ZESR_Z1ES_MASK)

#define OMU_CM7_ZESR_Z2ES_MASK                   (0x4U)
#define OMU_CM7_ZESR_Z2ES_SHIFT                  (2U)
#define OMU_CM7_ZESR_Z2ES_WIDTH                  (1U)
#define OMU_CM7_ZESR_Z2ES(x)                     (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZESR_Z2ES_SHIFT)) & OMU_CM7_ZESR_Z2ES_MASK)

#define OMU_CM7_ZESR_Z3ES_MASK                   (0x8U)
#define OMU_CM7_ZESR_Z3ES_SHIFT                  (3U)
#define OMU_CM7_ZESR_Z3ES_WIDTH                  (1U)
#define OMU_CM7_ZESR_Z3ES(x)                     (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZESR_Z3ES_SHIFT)) & OMU_CM7_ZESR_Z3ES_MASK)

#define OMU_CM7_ZESR_Z4ES_MASK                   (0x10U)
#define OMU_CM7_ZESR_Z4ES_SHIFT                  (4U)
#define OMU_CM7_ZESR_Z4ES_WIDTH                  (1U)
#define OMU_CM7_ZESR_Z4ES(x)                     (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZESR_Z4ES_SHIFT)) & OMU_CM7_ZESR_Z4ES_MASK)

#define OMU_CM7_ZESR_Z5ES_MASK                   (0x20U)
#define OMU_CM7_ZESR_Z5ES_SHIFT                  (5U)
#define OMU_CM7_ZESR_Z5ES_WIDTH                  (1U)
#define OMU_CM7_ZESR_Z5ES(x)                     (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZESR_Z5ES_SHIFT)) & OMU_CM7_ZESR_Z5ES_MASK)

#define OMU_CM7_ZESR_Z6ES_MASK                   (0x40U)
#define OMU_CM7_ZESR_Z6ES_SHIFT                  (6U)
#define OMU_CM7_ZESR_Z6ES_WIDTH                  (1U)
#define OMU_CM7_ZESR_Z6ES(x)                     (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZESR_Z6ES_SHIFT)) & OMU_CM7_ZESR_Z6ES_MASK)

#define OMU_CM7_ZESR_Z7ES_MASK                   (0x80U)
#define OMU_CM7_ZESR_Z7ES_SHIFT                  (7U)
#define OMU_CM7_ZESR_Z7ES_WIDTH                  (1U)
#define OMU_CM7_ZESR_Z7ES(x)                     (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ZESR_Z7ES_SHIFT)) & OMU_CM7_ZESR_Z7ES_MASK)
/*! @} */

/*! @name GZRR - Global Zone Request */
/*! @{ */

#define OMU_CM7_GZRR_GZ0R_MASK                   (0x1U)
#define OMU_CM7_GZRR_GZ0R_SHIFT                  (0U)
#define OMU_CM7_GZRR_GZ0R_WIDTH                  (1U)
#define OMU_CM7_GZRR_GZ0R(x)                     (((uint32_t)(((uint32_t)(x)) << OMU_CM7_GZRR_GZ0R_SHIFT)) & OMU_CM7_GZRR_GZ0R_MASK)

#define OMU_CM7_GZRR_GZ1R_MASK                   (0x2U)
#define OMU_CM7_GZRR_GZ1R_SHIFT                  (1U)
#define OMU_CM7_GZRR_GZ1R_WIDTH                  (1U)
#define OMU_CM7_GZRR_GZ1R(x)                     (((uint32_t)(((uint32_t)(x)) << OMU_CM7_GZRR_GZ1R_SHIFT)) & OMU_CM7_GZRR_GZ1R_MASK)

#define OMU_CM7_GZRR_GZ2R_MASK                   (0x4U)
#define OMU_CM7_GZRR_GZ2R_SHIFT                  (2U)
#define OMU_CM7_GZRR_GZ2R_WIDTH                  (1U)
#define OMU_CM7_GZRR_GZ2R(x)                     (((uint32_t)(((uint32_t)(x)) << OMU_CM7_GZRR_GZ2R_SHIFT)) & OMU_CM7_GZRR_GZ2R_MASK)

#define OMU_CM7_GZRR_GZ3R_MASK                   (0x8U)
#define OMU_CM7_GZRR_GZ3R_SHIFT                  (3U)
#define OMU_CM7_GZRR_GZ3R_WIDTH                  (1U)
#define OMU_CM7_GZRR_GZ3R(x)                     (((uint32_t)(((uint32_t)(x)) << OMU_CM7_GZRR_GZ3R_SHIFT)) & OMU_CM7_GZRR_GZ3R_MASK)

#define OMU_CM7_GZRR_GZ4R_MASK                   (0x10U)
#define OMU_CM7_GZRR_GZ4R_SHIFT                  (4U)
#define OMU_CM7_GZRR_GZ4R_WIDTH                  (1U)
#define OMU_CM7_GZRR_GZ4R(x)                     (((uint32_t)(((uint32_t)(x)) << OMU_CM7_GZRR_GZ4R_SHIFT)) & OMU_CM7_GZRR_GZ4R_MASK)

#define OMU_CM7_GZRR_GZ5R_MASK                   (0x20U)
#define OMU_CM7_GZRR_GZ5R_SHIFT                  (5U)
#define OMU_CM7_GZRR_GZ5R_WIDTH                  (1U)
#define OMU_CM7_GZRR_GZ5R(x)                     (((uint32_t)(((uint32_t)(x)) << OMU_CM7_GZRR_GZ5R_SHIFT)) & OMU_CM7_GZRR_GZ5R_MASK)

#define OMU_CM7_GZRR_GZ6R_MASK                   (0x40U)
#define OMU_CM7_GZRR_GZ6R_SHIFT                  (6U)
#define OMU_CM7_GZRR_GZ6R_WIDTH                  (1U)
#define OMU_CM7_GZRR_GZ6R(x)                     (((uint32_t)(((uint32_t)(x)) << OMU_CM7_GZRR_GZ6R_SHIFT)) & OMU_CM7_GZRR_GZ6R_MASK)

#define OMU_CM7_GZRR_GZ7R_MASK                   (0x80U)
#define OMU_CM7_GZRR_GZ7R_SHIFT                  (7U)
#define OMU_CM7_GZRR_GZ7R_WIDTH                  (1U)
#define OMU_CM7_GZRR_GZ7R(x)                     (((uint32_t)(((uint32_t)(x)) << OMU_CM7_GZRR_GZ7R_SHIFT)) & OMU_CM7_GZRR_GZ7R_MASK)
/*! @} */

/*! @name ORDLSA - ORD0 Logical Start Address..ORD15 Logical Start Address */
/*! @{ */

#define OMU_CM7_ORDLSA_LSA_MASK                  (0xFFFFFC00U)
#define OMU_CM7_ORDLSA_LSA_SHIFT                 (10U)
#define OMU_CM7_ORDLSA_LSA_WIDTH                 (22U)
#define OMU_CM7_ORDLSA_LSA(x)                    (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ORDLSA_LSA_SHIFT)) & OMU_CM7_ORDLSA_LSA_MASK)
/*! @} */

/*! @name ORDPSA - ORD0 Physical Start Address..ORD15 Physical Start Address */
/*! @{ */

#define OMU_CM7_ORDPSA_PSA_MASK                  (0xFFFFFC00U)
#define OMU_CM7_ORDPSA_PSA_SHIFT                 (10U)
#define OMU_CM7_ORDPSA_PSA_WIDTH                 (22U)
#define OMU_CM7_ORDPSA_PSA(x)                    (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ORDPSA_PSA_SHIFT)) & OMU_CM7_ORDPSA_PSA_MASK)
/*! @} */

/*! @name ORDRS - ORD0 Region Size..ORD15 Region Size */
/*! @{ */

#define OMU_CM7_ORDRS_RS_MASK                    (0xFU)
#define OMU_CM7_ORDRS_RS_SHIFT                   (0U)
#define OMU_CM7_ORDRS_RS_WIDTH                   (4U)
#define OMU_CM7_ORDRS_RS(x)                      (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ORDRS_RS_SHIFT)) & OMU_CM7_ORDRS_RS_MASK)
/*! @} */

/*! @name ORDRZA - ORD0 Region Zone Assignment..ORD15 Region Zone Assignment */
/*! @{ */

#define OMU_CM7_ORDRZA_RZA_MASK                  (0xFU)
#define OMU_CM7_ORDRZA_RZA_SHIFT                 (0U)
#define OMU_CM7_ORDRZA_RZA_WIDTH                 (4U)
#define OMU_CM7_ORDRZA_RZA(x)                    (((uint32_t)(((uint32_t)(x)) << OMU_CM7_ORDRZA_RZA_SHIFT)) & OMU_CM7_ORDRZA_RZA_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group OMU_CM7_Register_Masks */

/*!
 * @}
 */ /* end of group OMU_CM7_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K39_OMU_CM7_H_) */
