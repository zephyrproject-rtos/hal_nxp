/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_OMU.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_OMU
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
#if !defined(S32Z2_OMU_H_)  /* Check if memory map has not been already included */
#define S32Z2_OMU_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- OMU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OMU_Peripheral_Access_Layer OMU Peripheral Access Layer
 * @{
 */

/** OMU - Size of Registers Arrays */
#define OMU_ZONE_REGS_COUNT                       4u
#define OMU_OVERLAY_REGION_DESCRIPTOR_COUNT       64u

/** OMU - Register Layout Typedef */
typedef struct {
  struct OMU_ZONE_REGS {                           /* offset: 0x0, array step: 0x1000 */
    __I  uint32_t ZZRSR;                             /**< Zone Request Status 0..Zone Request Status 3, array offset: 0x0, array step: 0x1000 */
    __IO uint32_t ZER;                               /**< Zone Enable 0..Zone Enable 3, array offset: 0x4, array step: 0x1000 */
    uint8_t RESERVED_0[4088];
  } ZONE_REGS[OMU_ZONE_REGS_COUNT];
  __IO uint32_t OER;                               /**< OMU Enable, offset: 0x4000 */
  __IO uint32_t ZRR;                               /**< Zone Request, offset: 0x4004 */
  __I  uint32_t ZESR;                              /**< Zone Enable Status, offset: 0x4008 */
  uint8_t RESERVED_0[1012];
  struct OMU_OVERLAY_REGION_DESCRIPTOR {           /* offset: 0x4400, array step: 0x10 */
    __IO uint32_t ORDLSA;                            /**< ORD0 Logical Start Address..ORD63 Logical Start Address, array offset: 0x4400, array step: 0x10 */
    __IO uint32_t ORDPSA;                            /**< ORD0 Physical Start Address..ORD63 Physical Start Address, array offset: 0x4404, array step: 0x10 */
    __IO uint32_t ORDRS;                             /**< ORD0 Region Size..ORD63 Region Size, array offset: 0x4408, array step: 0x10 */
    __IO uint32_t ORDRZA;                            /**< ORD0 Region Zone Assignment..ORD63 Region Zone Assignment, array offset: 0x440C, array step: 0x10 */
  } OVERLAY_REGION_DESCRIPTOR[OMU_OVERLAY_REGION_DESCRIPTOR_COUNT];
} OMU_Type, *OMU_MemMapPtr;

/** Number of instances of the OMU module. */
#define OMU_INSTANCE_COUNT                       (2u)

/* OMU - Peripheral instance base addresses */
/** Peripheral RTU0__OMU base address */
#define IP_RTU0__OMU_BASE                        (0x761A0000u)
/** Peripheral RTU0__OMU base pointer */
#define IP_RTU0__OMU                             ((OMU_Type *)IP_RTU0__OMU_BASE)
/** Peripheral RTU1__OMU base address */
#define IP_RTU1__OMU_BASE                        (0x769A0000u)
/** Peripheral RTU1__OMU base pointer */
#define IP_RTU1__OMU                             ((OMU_Type *)IP_RTU1__OMU_BASE)
/** Array initializer of OMU peripheral base addresses */
#define IP_OMU_BASE_ADDRS                        { IP_RTU0__OMU_BASE, IP_RTU1__OMU_BASE }
/** Array initializer of OMU peripheral base pointers */
#define IP_OMU_BASE_PTRS                         { IP_RTU0__OMU, IP_RTU1__OMU }

/* ----------------------------------------------------------------------------
   -- OMU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OMU_Register_Masks OMU Register Masks
 * @{
 */

/*! @name ZZRSR - Zone Request Status 0..Zone Request Status 3 */
/*! @{ */

#define OMU_ZZRSR_Z0RS_MASK                      (0x1U)
#define OMU_ZZRSR_Z0RS_SHIFT                     (0U)
#define OMU_ZZRSR_Z0RS_WIDTH                     (1U)
#define OMU_ZZRSR_Z0RS(x)                        (((uint32_t)(((uint32_t)(x)) << OMU_ZZRSR_Z0RS_SHIFT)) & OMU_ZZRSR_Z0RS_MASK)

#define OMU_ZZRSR_Z2RS_MASK                      (0x1U)
#define OMU_ZZRSR_Z2RS_SHIFT                     (0U)
#define OMU_ZZRSR_Z2RS_WIDTH                     (1U)
#define OMU_ZZRSR_Z2RS(x)                        (((uint32_t)(((uint32_t)(x)) << OMU_ZZRSR_Z2RS_SHIFT)) & OMU_ZZRSR_Z2RS_MASK)

#define OMU_ZZRSR_Z4RS_MASK                      (0x1U)
#define OMU_ZZRSR_Z4RS_SHIFT                     (0U)
#define OMU_ZZRSR_Z4RS_WIDTH                     (1U)
#define OMU_ZZRSR_Z4RS(x)                        (((uint32_t)(((uint32_t)(x)) << OMU_ZZRSR_Z4RS_SHIFT)) & OMU_ZZRSR_Z4RS_MASK)

#define OMU_ZZRSR_Z6RS_MASK                      (0x1U)
#define OMU_ZZRSR_Z6RS_SHIFT                     (0U)
#define OMU_ZZRSR_Z6RS_WIDTH                     (1U)
#define OMU_ZZRSR_Z6RS(x)                        (((uint32_t)(((uint32_t)(x)) << OMU_ZZRSR_Z6RS_SHIFT)) & OMU_ZZRSR_Z6RS_MASK)

#define OMU_ZZRSR_Z1RS_MASK                      (0x2U)
#define OMU_ZZRSR_Z1RS_SHIFT                     (1U)
#define OMU_ZZRSR_Z1RS_WIDTH                     (1U)
#define OMU_ZZRSR_Z1RS(x)                        (((uint32_t)(((uint32_t)(x)) << OMU_ZZRSR_Z1RS_SHIFT)) & OMU_ZZRSR_Z1RS_MASK)

#define OMU_ZZRSR_Z3RS_MASK                      (0x2U)
#define OMU_ZZRSR_Z3RS_SHIFT                     (1U)
#define OMU_ZZRSR_Z3RS_WIDTH                     (1U)
#define OMU_ZZRSR_Z3RS(x)                        (((uint32_t)(((uint32_t)(x)) << OMU_ZZRSR_Z3RS_SHIFT)) & OMU_ZZRSR_Z3RS_MASK)

#define OMU_ZZRSR_Z5RS_MASK                      (0x2U)
#define OMU_ZZRSR_Z5RS_SHIFT                     (1U)
#define OMU_ZZRSR_Z5RS_WIDTH                     (1U)
#define OMU_ZZRSR_Z5RS(x)                        (((uint32_t)(((uint32_t)(x)) << OMU_ZZRSR_Z5RS_SHIFT)) & OMU_ZZRSR_Z5RS_MASK)

#define OMU_ZZRSR_Z7RS_MASK                      (0x2U)
#define OMU_ZZRSR_Z7RS_SHIFT                     (1U)
#define OMU_ZZRSR_Z7RS_WIDTH                     (1U)
#define OMU_ZZRSR_Z7RS(x)                        (((uint32_t)(((uint32_t)(x)) << OMU_ZZRSR_Z7RS_SHIFT)) & OMU_ZZRSR_Z7RS_MASK)
/*! @} */

/*! @name ZER - Zone Enable 0..Zone Enable 3 */
/*! @{ */

#define OMU_ZER_Z0E_MASK                         (0x1U)
#define OMU_ZER_Z0E_SHIFT                        (0U)
#define OMU_ZER_Z0E_WIDTH                        (1U)
#define OMU_ZER_Z0E(x)                           (((uint32_t)(((uint32_t)(x)) << OMU_ZER_Z0E_SHIFT)) & OMU_ZER_Z0E_MASK)

#define OMU_ZER_Z2E_MASK                         (0x1U)
#define OMU_ZER_Z2E_SHIFT                        (0U)
#define OMU_ZER_Z2E_WIDTH                        (1U)
#define OMU_ZER_Z2E(x)                           (((uint32_t)(((uint32_t)(x)) << OMU_ZER_Z2E_SHIFT)) & OMU_ZER_Z2E_MASK)

#define OMU_ZER_Z4E_MASK                         (0x1U)
#define OMU_ZER_Z4E_SHIFT                        (0U)
#define OMU_ZER_Z4E_WIDTH                        (1U)
#define OMU_ZER_Z4E(x)                           (((uint32_t)(((uint32_t)(x)) << OMU_ZER_Z4E_SHIFT)) & OMU_ZER_Z4E_MASK)

#define OMU_ZER_Z6E_MASK                         (0x1U)
#define OMU_ZER_Z6E_SHIFT                        (0U)
#define OMU_ZER_Z6E_WIDTH                        (1U)
#define OMU_ZER_Z6E(x)                           (((uint32_t)(((uint32_t)(x)) << OMU_ZER_Z6E_SHIFT)) & OMU_ZER_Z6E_MASK)

#define OMU_ZER_Z1E_MASK                         (0x2U)
#define OMU_ZER_Z1E_SHIFT                        (1U)
#define OMU_ZER_Z1E_WIDTH                        (1U)
#define OMU_ZER_Z1E(x)                           (((uint32_t)(((uint32_t)(x)) << OMU_ZER_Z1E_SHIFT)) & OMU_ZER_Z1E_MASK)

#define OMU_ZER_Z3E_MASK                         (0x2U)
#define OMU_ZER_Z3E_SHIFT                        (1U)
#define OMU_ZER_Z3E_WIDTH                        (1U)
#define OMU_ZER_Z3E(x)                           (((uint32_t)(((uint32_t)(x)) << OMU_ZER_Z3E_SHIFT)) & OMU_ZER_Z3E_MASK)

#define OMU_ZER_Z5E_MASK                         (0x2U)
#define OMU_ZER_Z5E_SHIFT                        (1U)
#define OMU_ZER_Z5E_WIDTH                        (1U)
#define OMU_ZER_Z5E(x)                           (((uint32_t)(((uint32_t)(x)) << OMU_ZER_Z5E_SHIFT)) & OMU_ZER_Z5E_MASK)

#define OMU_ZER_Z7E_MASK                         (0x2U)
#define OMU_ZER_Z7E_SHIFT                        (1U)
#define OMU_ZER_Z7E_WIDTH                        (1U)
#define OMU_ZER_Z7E(x)                           (((uint32_t)(((uint32_t)(x)) << OMU_ZER_Z7E_SHIFT)) & OMU_ZER_Z7E_MASK)
/*! @} */

/*! @name OER - OMU Enable */
/*! @{ */

#define OMU_OER_OE_MASK                          (0x1U)
#define OMU_OER_OE_SHIFT                         (0U)
#define OMU_OER_OE_WIDTH                         (1U)
#define OMU_OER_OE(x)                            (((uint32_t)(((uint32_t)(x)) << OMU_OER_OE_SHIFT)) & OMU_OER_OE_MASK)
/*! @} */

/*! @name ZRR - Zone Request */
/*! @{ */

#define OMU_ZRR_Z0R_MASK                         (0x1U)
#define OMU_ZRR_Z0R_SHIFT                        (0U)
#define OMU_ZRR_Z0R_WIDTH                        (1U)
#define OMU_ZRR_Z0R(x)                           (((uint32_t)(((uint32_t)(x)) << OMU_ZRR_Z0R_SHIFT)) & OMU_ZRR_Z0R_MASK)

#define OMU_ZRR_Z1R_MASK                         (0x2U)
#define OMU_ZRR_Z1R_SHIFT                        (1U)
#define OMU_ZRR_Z1R_WIDTH                        (1U)
#define OMU_ZRR_Z1R(x)                           (((uint32_t)(((uint32_t)(x)) << OMU_ZRR_Z1R_SHIFT)) & OMU_ZRR_Z1R_MASK)

#define OMU_ZRR_Z2R_MASK                         (0x4U)
#define OMU_ZRR_Z2R_SHIFT                        (2U)
#define OMU_ZRR_Z2R_WIDTH                        (1U)
#define OMU_ZRR_Z2R(x)                           (((uint32_t)(((uint32_t)(x)) << OMU_ZRR_Z2R_SHIFT)) & OMU_ZRR_Z2R_MASK)

#define OMU_ZRR_Z3R_MASK                         (0x8U)
#define OMU_ZRR_Z3R_SHIFT                        (3U)
#define OMU_ZRR_Z3R_WIDTH                        (1U)
#define OMU_ZRR_Z3R(x)                           (((uint32_t)(((uint32_t)(x)) << OMU_ZRR_Z3R_SHIFT)) & OMU_ZRR_Z3R_MASK)

#define OMU_ZRR_Z4R_MASK                         (0x10U)
#define OMU_ZRR_Z4R_SHIFT                        (4U)
#define OMU_ZRR_Z4R_WIDTH                        (1U)
#define OMU_ZRR_Z4R(x)                           (((uint32_t)(((uint32_t)(x)) << OMU_ZRR_Z4R_SHIFT)) & OMU_ZRR_Z4R_MASK)

#define OMU_ZRR_Z5R_MASK                         (0x20U)
#define OMU_ZRR_Z5R_SHIFT                        (5U)
#define OMU_ZRR_Z5R_WIDTH                        (1U)
#define OMU_ZRR_Z5R(x)                           (((uint32_t)(((uint32_t)(x)) << OMU_ZRR_Z5R_SHIFT)) & OMU_ZRR_Z5R_MASK)

#define OMU_ZRR_Z6R_MASK                         (0x40U)
#define OMU_ZRR_Z6R_SHIFT                        (6U)
#define OMU_ZRR_Z6R_WIDTH                        (1U)
#define OMU_ZRR_Z6R(x)                           (((uint32_t)(((uint32_t)(x)) << OMU_ZRR_Z6R_SHIFT)) & OMU_ZRR_Z6R_MASK)

#define OMU_ZRR_Z7R_MASK                         (0x80U)
#define OMU_ZRR_Z7R_SHIFT                        (7U)
#define OMU_ZRR_Z7R_WIDTH                        (1U)
#define OMU_ZRR_Z7R(x)                           (((uint32_t)(((uint32_t)(x)) << OMU_ZRR_Z7R_SHIFT)) & OMU_ZRR_Z7R_MASK)
/*! @} */

/*! @name ZESR - Zone Enable Status */
/*! @{ */

#define OMU_ZESR_Z0ES_MASK                       (0x1U)
#define OMU_ZESR_Z0ES_SHIFT                      (0U)
#define OMU_ZESR_Z0ES_WIDTH                      (1U)
#define OMU_ZESR_Z0ES(x)                         (((uint32_t)(((uint32_t)(x)) << OMU_ZESR_Z0ES_SHIFT)) & OMU_ZESR_Z0ES_MASK)

#define OMU_ZESR_Z1ES_MASK                       (0x2U)
#define OMU_ZESR_Z1ES_SHIFT                      (1U)
#define OMU_ZESR_Z1ES_WIDTH                      (1U)
#define OMU_ZESR_Z1ES(x)                         (((uint32_t)(((uint32_t)(x)) << OMU_ZESR_Z1ES_SHIFT)) & OMU_ZESR_Z1ES_MASK)

#define OMU_ZESR_Z2ES_MASK                       (0x4U)
#define OMU_ZESR_Z2ES_SHIFT                      (2U)
#define OMU_ZESR_Z2ES_WIDTH                      (1U)
#define OMU_ZESR_Z2ES(x)                         (((uint32_t)(((uint32_t)(x)) << OMU_ZESR_Z2ES_SHIFT)) & OMU_ZESR_Z2ES_MASK)

#define OMU_ZESR_Z3ES_MASK                       (0x8U)
#define OMU_ZESR_Z3ES_SHIFT                      (3U)
#define OMU_ZESR_Z3ES_WIDTH                      (1U)
#define OMU_ZESR_Z3ES(x)                         (((uint32_t)(((uint32_t)(x)) << OMU_ZESR_Z3ES_SHIFT)) & OMU_ZESR_Z3ES_MASK)

#define OMU_ZESR_Z4ES_MASK                       (0x10U)
#define OMU_ZESR_Z4ES_SHIFT                      (4U)
#define OMU_ZESR_Z4ES_WIDTH                      (1U)
#define OMU_ZESR_Z4ES(x)                         (((uint32_t)(((uint32_t)(x)) << OMU_ZESR_Z4ES_SHIFT)) & OMU_ZESR_Z4ES_MASK)

#define OMU_ZESR_Z5ES_MASK                       (0x20U)
#define OMU_ZESR_Z5ES_SHIFT                      (5U)
#define OMU_ZESR_Z5ES_WIDTH                      (1U)
#define OMU_ZESR_Z5ES(x)                         (((uint32_t)(((uint32_t)(x)) << OMU_ZESR_Z5ES_SHIFT)) & OMU_ZESR_Z5ES_MASK)

#define OMU_ZESR_Z6ES_MASK                       (0x40U)
#define OMU_ZESR_Z6ES_SHIFT                      (6U)
#define OMU_ZESR_Z6ES_WIDTH                      (1U)
#define OMU_ZESR_Z6ES(x)                         (((uint32_t)(((uint32_t)(x)) << OMU_ZESR_Z6ES_SHIFT)) & OMU_ZESR_Z6ES_MASK)

#define OMU_ZESR_Z7ES_MASK                       (0x80U)
#define OMU_ZESR_Z7ES_SHIFT                      (7U)
#define OMU_ZESR_Z7ES_WIDTH                      (1U)
#define OMU_ZESR_Z7ES(x)                         (((uint32_t)(((uint32_t)(x)) << OMU_ZESR_Z7ES_SHIFT)) & OMU_ZESR_Z7ES_MASK)
/*! @} */

/*! @name ORDLSA - ORD0 Logical Start Address..ORD63 Logical Start Address */
/*! @{ */

#define OMU_ORDLSA_LSA_MASK                      (0xFFFFFC00U)
#define OMU_ORDLSA_LSA_SHIFT                     (10U)
#define OMU_ORDLSA_LSA_WIDTH                     (22U)
#define OMU_ORDLSA_LSA(x)                        (((uint32_t)(((uint32_t)(x)) << OMU_ORDLSA_LSA_SHIFT)) & OMU_ORDLSA_LSA_MASK)
/*! @} */

/*! @name ORDPSA - ORD0 Physical Start Address..ORD63 Physical Start Address */
/*! @{ */

#define OMU_ORDPSA_PSA_MASK                      (0xFFFFFC00U)
#define OMU_ORDPSA_PSA_SHIFT                     (10U)
#define OMU_ORDPSA_PSA_WIDTH                     (22U)
#define OMU_ORDPSA_PSA(x)                        (((uint32_t)(((uint32_t)(x)) << OMU_ORDPSA_PSA_SHIFT)) & OMU_ORDPSA_PSA_MASK)
/*! @} */

/*! @name ORDRS - ORD0 Region Size..ORD63 Region Size */
/*! @{ */

#define OMU_ORDRS_RS_MASK                        (0xFU)
#define OMU_ORDRS_RS_SHIFT                       (0U)
#define OMU_ORDRS_RS_WIDTH                       (4U)
#define OMU_ORDRS_RS(x)                          (((uint32_t)(((uint32_t)(x)) << OMU_ORDRS_RS_SHIFT)) & OMU_ORDRS_RS_MASK)
/*! @} */

/*! @name ORDRZA - ORD0 Region Zone Assignment..ORD63 Region Zone Assignment */
/*! @{ */

#define OMU_ORDRZA_RZA_MASK                      (0xFU)
#define OMU_ORDRZA_RZA_SHIFT                     (0U)
#define OMU_ORDRZA_RZA_WIDTH                     (4U)
#define OMU_ORDRZA_RZA(x)                        (((uint32_t)(((uint32_t)(x)) << OMU_ORDRZA_RZA_SHIFT)) & OMU_ORDRZA_RZA_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group OMU_Register_Masks */

/*!
 * @}
 */ /* end of group OMU_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_OMU_H_) */
