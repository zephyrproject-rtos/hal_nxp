/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_XBIC.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_XBIC
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
#if !defined(S32Z2_XBIC_H_)  /* Check if memory map has not been already included */
#define S32Z2_XBIC_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- XBIC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBIC_Peripheral_Access_Layer XBIC Peripheral Access Layer
 * @{
 */

/** XBIC - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< XBIC Module Control, offset: 0x0 */
  __IO uint32_t EIR;                               /**< XBIC Error Injection Attributes, offset: 0x4 */
  __IO uint32_t ESR;                               /**< XBIC Error Status Attributes, offset: 0x8 */
  __I  uint32_t EAR;                               /**< XBIC Error Address, offset: 0xC */
} XBIC_Type, *XBIC_MemMapPtr;

/** Number of instances of the XBIC module. */
#define XBIC_INSTANCE_COUNT                      (4u)

/* XBIC - Peripheral instance base addresses */
/** Peripheral CE_XBIC base address */
#define IP_CE_XBIC_BASE                          (0x44850000u)
/** Peripheral CE_XBIC base pointer */
#define IP_CE_XBIC                               ((XBIC_Type *)IP_CE_XBIC_BASE)
/** Peripheral AES__FEED_XBIC_AHB base address */
#define IP_AES__FEED_XBIC_AHB_BASE               (0x472C0000u)
/** Peripheral AES__FEED_XBIC_AHB base pointer */
#define IP_AES__FEED_XBIC_AHB                    ((XBIC_Type *)IP_AES__FEED_XBIC_AHB_BASE)
/** Peripheral AES__RESULT_XBIC_AHB base address */
#define IP_AES__RESULT_XBIC_AHB_BASE             (0x472D0000u)
/** Peripheral AES__RESULT_XBIC_AHB base pointer */
#define IP_AES__RESULT_XBIC_AHB                  ((XBIC_Type *)IP_AES__RESULT_XBIC_AHB_BASE)
/** Peripheral SMU__XBIC base address */
#define IP_SMU__XBIC_BASE                        (0x45050000u)
/** Peripheral SMU__XBIC base pointer */
#define IP_SMU__XBIC                             ((XBIC_Type *)IP_SMU__XBIC_BASE)
/** Array initializer of XBIC peripheral base addresses */
#define IP_XBIC_BASE_ADDRS                       { IP_CE_XBIC_BASE, IP_AES__FEED_XBIC_AHB_BASE, IP_AES__RESULT_XBIC_AHB_BASE, IP_SMU__XBIC_BASE }
/** Array initializer of XBIC peripheral base pointers */
#define IP_XBIC_BASE_PTRS                        { IP_CE_XBIC, IP_AES__FEED_XBIC_AHB, IP_AES__RESULT_XBIC_AHB, IP_SMU__XBIC }

/* ----------------------------------------------------------------------------
   -- XBIC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBIC_Register_Masks XBIC Register Masks
 * @{
 */

/*! @name MCR - XBIC Module Control */
/*! @{ */

#define XBIC_MCR_ME5_MASK                        (0x40000U)
#define XBIC_MCR_ME5_SHIFT                       (18U)
#define XBIC_MCR_ME5_WIDTH                       (1U)
#define XBIC_MCR_ME5(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_ME5_SHIFT)) & XBIC_MCR_ME5_MASK)

#define XBIC_MCR_ME4_MASK                        (0x80000U)
#define XBIC_MCR_ME4_SHIFT                       (19U)
#define XBIC_MCR_ME4_WIDTH                       (1U)
#define XBIC_MCR_ME4(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_ME4_SHIFT)) & XBIC_MCR_ME4_MASK)

#define XBIC_MCR_ME3_MASK                        (0x100000U)
#define XBIC_MCR_ME3_SHIFT                       (20U)
#define XBIC_MCR_ME3_WIDTH                       (1U)
#define XBIC_MCR_ME3(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_ME3_SHIFT)) & XBIC_MCR_ME3_MASK)

#define XBIC_MCR_ME2_MASK                        (0x200000U)
#define XBIC_MCR_ME2_SHIFT                       (21U)
#define XBIC_MCR_ME2_WIDTH                       (1U)
#define XBIC_MCR_ME2(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_ME2_SHIFT)) & XBIC_MCR_ME2_MASK)

#define XBIC_MCR_ME1_MASK                        (0x400000U)
#define XBIC_MCR_ME1_SHIFT                       (22U)
#define XBIC_MCR_ME1_WIDTH                       (1U)
#define XBIC_MCR_ME1(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_ME1_SHIFT)) & XBIC_MCR_ME1_MASK)

#define XBIC_MCR_ME0_MASK                        (0x800000U)
#define XBIC_MCR_ME0_SHIFT                       (23U)
#define XBIC_MCR_ME0_WIDTH                       (1U)
#define XBIC_MCR_ME0(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_ME0_SHIFT)) & XBIC_MCR_ME0_MASK)

#define XBIC_MCR_SE7_MASK                        (0x1000000U)
#define XBIC_MCR_SE7_SHIFT                       (24U)
#define XBIC_MCR_SE7_WIDTH                       (1U)
#define XBIC_MCR_SE7(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_SE7_SHIFT)) & XBIC_MCR_SE7_MASK)

#define XBIC_MCR_SE6_MASK                        (0x2000000U)
#define XBIC_MCR_SE6_SHIFT                       (25U)
#define XBIC_MCR_SE6_WIDTH                       (1U)
#define XBIC_MCR_SE6(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_SE6_SHIFT)) & XBIC_MCR_SE6_MASK)

#define XBIC_MCR_SE5_MASK                        (0x4000000U)
#define XBIC_MCR_SE5_SHIFT                       (26U)
#define XBIC_MCR_SE5_WIDTH                       (1U)
#define XBIC_MCR_SE5(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_SE5_SHIFT)) & XBIC_MCR_SE5_MASK)

#define XBIC_MCR_SE4_MASK                        (0x8000000U)
#define XBIC_MCR_SE4_SHIFT                       (27U)
#define XBIC_MCR_SE4_WIDTH                       (1U)
#define XBIC_MCR_SE4(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_SE4_SHIFT)) & XBIC_MCR_SE4_MASK)

#define XBIC_MCR_SE3_MASK                        (0x10000000U)
#define XBIC_MCR_SE3_SHIFT                       (28U)
#define XBIC_MCR_SE3_WIDTH                       (1U)
#define XBIC_MCR_SE3(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_SE3_SHIFT)) & XBIC_MCR_SE3_MASK)

#define XBIC_MCR_SE2_MASK                        (0x20000000U)
#define XBIC_MCR_SE2_SHIFT                       (29U)
#define XBIC_MCR_SE2_WIDTH                       (1U)
#define XBIC_MCR_SE2(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_SE2_SHIFT)) & XBIC_MCR_SE2_MASK)

#define XBIC_MCR_SE1_MASK                        (0x40000000U)
#define XBIC_MCR_SE1_SHIFT                       (30U)
#define XBIC_MCR_SE1_WIDTH                       (1U)
#define XBIC_MCR_SE1(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_SE1_SHIFT)) & XBIC_MCR_SE1_MASK)

#define XBIC_MCR_SE0_MASK                        (0x80000000U)
#define XBIC_MCR_SE0_SHIFT                       (31U)
#define XBIC_MCR_SE0_WIDTH                       (1U)
#define XBIC_MCR_SE0(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_SE0_SHIFT)) & XBIC_MCR_SE0_MASK)
/*! @} */

/*! @name EIR - XBIC Error Injection Attributes */
/*! @{ */

#define XBIC_EIR_SYN_MASK                        (0xFFU)
#define XBIC_EIR_SYN_SHIFT                       (0U)
#define XBIC_EIR_SYN_WIDTH                       (8U)
#define XBIC_EIR_SYN(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_EIR_SYN_SHIFT)) & XBIC_EIR_SYN_MASK)

#define XBIC_EIR_MST_MASK                        (0xF00U)
#define XBIC_EIR_MST_SHIFT                       (8U)
#define XBIC_EIR_MST_WIDTH                       (4U)
#define XBIC_EIR_MST(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_EIR_MST_SHIFT)) & XBIC_EIR_MST_MASK)

#define XBIC_EIR_SLV_MASK                        (0x7000U)
#define XBIC_EIR_SLV_SHIFT                       (12U)
#define XBIC_EIR_SLV_WIDTH                       (3U)
#define XBIC_EIR_SLV(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_EIR_SLV_SHIFT)) & XBIC_EIR_SLV_MASK)

#define XBIC_EIR_EIE_MASK                        (0x80000000U)
#define XBIC_EIR_EIE_SHIFT                       (31U)
#define XBIC_EIR_EIE_WIDTH                       (1U)
#define XBIC_EIR_EIE(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_EIR_EIE_SHIFT)) & XBIC_EIR_EIE_MASK)
/*! @} */

/*! @name ESR - XBIC Error Status Attributes */
/*! @{ */

#define XBIC_ESR_SYN_MASK                        (0xFFU)
#define XBIC_ESR_SYN_SHIFT                       (0U)
#define XBIC_ESR_SYN_WIDTH                       (8U)
#define XBIC_ESR_SYN(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_SYN_SHIFT)) & XBIC_ESR_SYN_MASK)

#define XBIC_ESR_MST_MASK                        (0xF00U)
#define XBIC_ESR_MST_SHIFT                       (8U)
#define XBIC_ESR_MST_WIDTH                       (4U)
#define XBIC_ESR_MST(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_MST_SHIFT)) & XBIC_ESR_MST_MASK)

#define XBIC_ESR_SLV_MASK                        (0x7000U)
#define XBIC_ESR_SLV_SHIFT                       (12U)
#define XBIC_ESR_SLV_WIDTH                       (3U)
#define XBIC_ESR_SLV(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_SLV_SHIFT)) & XBIC_ESR_SLV_MASK)

#define XBIC_ESR_DPME7_MASK                      (0x8000U)
#define XBIC_ESR_DPME7_SHIFT                     (15U)
#define XBIC_ESR_DPME7_WIDTH                     (1U)
#define XBIC_ESR_DPME7(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPME7_SHIFT)) & XBIC_ESR_DPME7_MASK)

#define XBIC_ESR_DPME6_MASK                      (0x10000U)
#define XBIC_ESR_DPME6_SHIFT                     (16U)
#define XBIC_ESR_DPME6_WIDTH                     (1U)
#define XBIC_ESR_DPME6(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPME6_SHIFT)) & XBIC_ESR_DPME6_MASK)

#define XBIC_ESR_DPME5_MASK                      (0x20000U)
#define XBIC_ESR_DPME5_SHIFT                     (17U)
#define XBIC_ESR_DPME5_WIDTH                     (1U)
#define XBIC_ESR_DPME5(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPME5_SHIFT)) & XBIC_ESR_DPME5_MASK)

#define XBIC_ESR_DPME4_MASK                      (0x40000U)
#define XBIC_ESR_DPME4_SHIFT                     (18U)
#define XBIC_ESR_DPME4_WIDTH                     (1U)
#define XBIC_ESR_DPME4(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPME4_SHIFT)) & XBIC_ESR_DPME4_MASK)

#define XBIC_ESR_DPME3_MASK                      (0x80000U)
#define XBIC_ESR_DPME3_SHIFT                     (19U)
#define XBIC_ESR_DPME3_WIDTH                     (1U)
#define XBIC_ESR_DPME3(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPME3_SHIFT)) & XBIC_ESR_DPME3_MASK)

#define XBIC_ESR_DPME2_MASK                      (0x100000U)
#define XBIC_ESR_DPME2_SHIFT                     (20U)
#define XBIC_ESR_DPME2_WIDTH                     (1U)
#define XBIC_ESR_DPME2(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPME2_SHIFT)) & XBIC_ESR_DPME2_MASK)

#define XBIC_ESR_DPME1_MASK                      (0x200000U)
#define XBIC_ESR_DPME1_SHIFT                     (21U)
#define XBIC_ESR_DPME1_WIDTH                     (1U)
#define XBIC_ESR_DPME1(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPME1_SHIFT)) & XBIC_ESR_DPME1_MASK)

#define XBIC_ESR_DPME0_MASK                      (0x400000U)
#define XBIC_ESR_DPME0_SHIFT                     (22U)
#define XBIC_ESR_DPME0_WIDTH                     (1U)
#define XBIC_ESR_DPME0(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPME0_SHIFT)) & XBIC_ESR_DPME0_MASK)

#define XBIC_ESR_DPSE7_MASK                      (0x800000U)
#define XBIC_ESR_DPSE7_SHIFT                     (23U)
#define XBIC_ESR_DPSE7_WIDTH                     (1U)
#define XBIC_ESR_DPSE7(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPSE7_SHIFT)) & XBIC_ESR_DPSE7_MASK)

#define XBIC_ESR_DPSE6_MASK                      (0x1000000U)
#define XBIC_ESR_DPSE6_SHIFT                     (24U)
#define XBIC_ESR_DPSE6_WIDTH                     (1U)
#define XBIC_ESR_DPSE6(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPSE6_SHIFT)) & XBIC_ESR_DPSE6_MASK)

#define XBIC_ESR_DPSE5_MASK                      (0x2000000U)
#define XBIC_ESR_DPSE5_SHIFT                     (25U)
#define XBIC_ESR_DPSE5_WIDTH                     (1U)
#define XBIC_ESR_DPSE5(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPSE5_SHIFT)) & XBIC_ESR_DPSE5_MASK)

#define XBIC_ESR_DPSE4_MASK                      (0x4000000U)
#define XBIC_ESR_DPSE4_SHIFT                     (26U)
#define XBIC_ESR_DPSE4_WIDTH                     (1U)
#define XBIC_ESR_DPSE4(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPSE4_SHIFT)) & XBIC_ESR_DPSE4_MASK)

#define XBIC_ESR_DPSE3_MASK                      (0x8000000U)
#define XBIC_ESR_DPSE3_SHIFT                     (27U)
#define XBIC_ESR_DPSE3_WIDTH                     (1U)
#define XBIC_ESR_DPSE3(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPSE3_SHIFT)) & XBIC_ESR_DPSE3_MASK)

#define XBIC_ESR_DPSE2_MASK                      (0x10000000U)
#define XBIC_ESR_DPSE2_SHIFT                     (28U)
#define XBIC_ESR_DPSE2_WIDTH                     (1U)
#define XBIC_ESR_DPSE2(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPSE2_SHIFT)) & XBIC_ESR_DPSE2_MASK)

#define XBIC_ESR_DPSE1_MASK                      (0x20000000U)
#define XBIC_ESR_DPSE1_SHIFT                     (29U)
#define XBIC_ESR_DPSE1_WIDTH                     (1U)
#define XBIC_ESR_DPSE1(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPSE1_SHIFT)) & XBIC_ESR_DPSE1_MASK)

#define XBIC_ESR_DPSE0_MASK                      (0x40000000U)
#define XBIC_ESR_DPSE0_SHIFT                     (30U)
#define XBIC_ESR_DPSE0_WIDTH                     (1U)
#define XBIC_ESR_DPSE0(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPSE0_SHIFT)) & XBIC_ESR_DPSE0_MASK)

#define XBIC_ESR_VLD_MASK                        (0x80000000U)
#define XBIC_ESR_VLD_SHIFT                       (31U)
#define XBIC_ESR_VLD_WIDTH                       (1U)
#define XBIC_ESR_VLD(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_VLD_SHIFT)) & XBIC_ESR_VLD_MASK)
/*! @} */

/*! @name EAR - XBIC Error Address */
/*! @{ */

#define XBIC_EAR_ADDR_MASK                       (0xFFFFFFFFU)
#define XBIC_EAR_ADDR_SHIFT                      (0U)
#define XBIC_EAR_ADDR_WIDTH                      (32U)
#define XBIC_EAR_ADDR(x)                         (((uint32_t)(((uint32_t)(x)) << XBIC_EAR_ADDR_SHIFT)) & XBIC_EAR_ADDR_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group XBIC_Register_Masks */

/*!
 * @}
 */ /* end of group XBIC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_XBIC_H_) */
