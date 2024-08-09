/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_CE_SRG_S.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_CE_SRG_S
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
#if !defined(S32Z2_CE_SRG_S_H_)  /* Check if memory map has not been already included */
#define S32Z2_CE_SRG_S_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CE_SRG_S Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CE_SRG_S_Peripheral_Access_Layer CE_SRG_S Peripheral Access Layer
 * @{
 */

/** CE_SRG_S - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR0;                               /**< Control 0, offset: 0x0 */
  uint8_t RESERVED_0[252];
  __IO uint32_t LCR0;                              /**< Lock Control 0, offset: 0x100 */
  __IO uint32_t LCR1;                              /**< Lock Control 1, offset: 0x104 */
  __IO uint32_t LCR2;                              /**< Lock Control 2, offset: 0x108 */
  __IO uint32_t LCR3;                              /**< Lock Control 3, offset: 0x10C */
  __IO uint32_t LCR4;                              /**< Lock Control 4, offset: 0x110 */
  uint8_t RESERVED_1[8];
  __IO uint32_t LCR7;                              /**< Lock Control 7, offset: 0x11C */
  uint8_t RESERVED_2[224];
  __IO uint32_t SR0;                               /**< Status 0, offset: 0x200 */
} CE_SRG_S_Type, *CE_SRG_S_MemMapPtr;

/** Number of instances of the CE_SRG_S module. */
#define CE_SRG_S_INSTANCE_COUNT                  (1u)

/* CE_SRG_S - Peripheral instance base addresses */
/** Peripheral CE_SRG_S base address */
#define IP_CE_SRG_S_BASE                         (0x44864000u)
/** Peripheral CE_SRG_S base pointer */
#define IP_CE_SRG_S                              ((CE_SRG_S_Type *)IP_CE_SRG_S_BASE)
/** Array initializer of CE_SRG_S peripheral base addresses */
#define IP_CE_SRG_S_BASE_ADDRS                   { IP_CE_SRG_S_BASE }
/** Array initializer of CE_SRG_S peripheral base pointers */
#define IP_CE_SRG_S_BASE_PTRS                    { IP_CE_SRG_S }

/* ----------------------------------------------------------------------------
   -- CE_SRG_S Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CE_SRG_S_Register_Masks CE_SRG_S Register Masks
 * @{
 */

/*! @name CR0 - Control 0 */
/*! @{ */

#define CE_SRG_S_CR0_MSTR0DOW_MASK               (0x1U)
#define CE_SRG_S_CR0_MSTR0DOW_SHIFT              (0U)
#define CE_SRG_S_CR0_MSTR0DOW_WIDTH              (1U)
#define CE_SRG_S_CR0_MSTR0DOW(x)                 (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_CR0_MSTR0DOW_SHIFT)) & CE_SRG_S_CR0_MSTR0DOW_MASK)

#define CE_SRG_S_CR0_C0CCMDOW_MASK               (0x2U)
#define CE_SRG_S_CR0_C0CCMDOW_SHIFT              (1U)
#define CE_SRG_S_CR0_C0CCMDOW_WIDTH              (1U)
#define CE_SRG_S_CR0_C0CCMDOW(x)                 (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_CR0_C0CCMDOW_SHIFT)) & CE_SRG_S_CR0_C0CCMDOW_MASK)

#define CE_SRG_S_CR0_C0CSMDOW_MASK               (0x4U)
#define CE_SRG_S_CR0_C0CSMDOW_SHIFT              (2U)
#define CE_SRG_S_CR0_C0CSMDOW_WIDTH              (1U)
#define CE_SRG_S_CR0_C0CSMDOW(x)                 (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_CR0_C0CSMDOW_SHIFT)) & CE_SRG_S_CR0_C0CSMDOW_MASK)

#define CE_SRG_S_CR0_DEDOW_MASK                  (0x8U)
#define CE_SRG_S_CR0_DEDOW_SHIFT                 (3U)
#define CE_SRG_S_CR0_DEDOW_WIDTH                 (1U)
#define CE_SRG_S_CR0_DEDOW(x)                    (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_CR0_DEDOW_SHIFT)) & CE_SRG_S_CR0_DEDOW_MASK)

#define CE_SRG_S_CR0_C1CCMDOW_MASK               (0x10U)
#define CE_SRG_S_CR0_C1CCMDOW_SHIFT              (4U)
#define CE_SRG_S_CR0_C1CCMDOW_WIDTH              (1U)
#define CE_SRG_S_CR0_C1CCMDOW(x)                 (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_CR0_C1CCMDOW_SHIFT)) & CE_SRG_S_CR0_C1CCMDOW_MASK)

#define CE_SRG_S_CR0_C1CSMDOW_MASK               (0x20U)
#define CE_SRG_S_CR0_C1CSMDOW_SHIFT              (5U)
#define CE_SRG_S_CR0_C1CSMDOW_WIDTH              (1U)
#define CE_SRG_S_CR0_C1CSMDOW(x)                 (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_CR0_C1CSMDOW_SHIFT)) & CE_SRG_S_CR0_C1CSMDOW_MASK)

#define CE_SRG_S_CR0_MSTR0HPE_MASK               (0x100U)
#define CE_SRG_S_CR0_MSTR0HPE_SHIFT              (8U)
#define CE_SRG_S_CR0_MSTR0HPE_WIDTH              (1U)
#define CE_SRG_S_CR0_MSTR0HPE(x)                 (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_CR0_MSTR0HPE_SHIFT)) & CE_SRG_S_CR0_MSTR0HPE_MASK)

#define CE_SRG_S_CR0_C0CCMHPE_MASK               (0x200U)
#define CE_SRG_S_CR0_C0CCMHPE_SHIFT              (9U)
#define CE_SRG_S_CR0_C0CCMHPE_WIDTH              (1U)
#define CE_SRG_S_CR0_C0CCMHPE(x)                 (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_CR0_C0CCMHPE_SHIFT)) & CE_SRG_S_CR0_C0CCMHPE_MASK)

#define CE_SRG_S_CR0_C0CSMHPE_MASK               (0x400U)
#define CE_SRG_S_CR0_C0CSMHPE_SHIFT              (10U)
#define CE_SRG_S_CR0_C0CSMHPE_WIDTH              (1U)
#define CE_SRG_S_CR0_C0CSMHPE(x)                 (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_CR0_C0CSMHPE_SHIFT)) & CE_SRG_S_CR0_C0CSMHPE_MASK)

#define CE_SRG_S_CR0_C1CCMHPE_MASK               (0x1000U)
#define CE_SRG_S_CR0_C1CCMHPE_SHIFT              (12U)
#define CE_SRG_S_CR0_C1CCMHPE_WIDTH              (1U)
#define CE_SRG_S_CR0_C1CCMHPE(x)                 (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_CR0_C1CCMHPE_SHIFT)) & CE_SRG_S_CR0_C1CCMHPE_MASK)

#define CE_SRG_S_CR0_C1CSMHPE_MASK               (0x2000U)
#define CE_SRG_S_CR0_C1CSMHPE_SHIFT              (13U)
#define CE_SRG_S_CR0_C1CSMHPE_WIDTH              (1U)
#define CE_SRG_S_CR0_C1CSMHPE(x)                 (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_CR0_C1CSMHPE_SHIFT)) & CE_SRG_S_CR0_C1CSMHPE_MASK)

#define CE_SRG_S_CR0_SLV0SBE_MASK                (0x10000U)
#define CE_SRG_S_CR0_SLV0SBE_SHIFT               (16U)
#define CE_SRG_S_CR0_SLV0SBE_WIDTH               (1U)
#define CE_SRG_S_CR0_SLV0SBE(x)                  (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_CR0_SLV0SBE_SHIFT)) & CE_SRG_S_CR0_SLV0SBE_MASK)

#define CE_SRG_S_CR0_AIPS0SBE_MASK               (0x20000U)
#define CE_SRG_S_CR0_AIPS0SBE_SHIFT              (17U)
#define CE_SRG_S_CR0_AIPS0SBE_WIDTH              (1U)
#define CE_SRG_S_CR0_AIPS0SBE(x)                 (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_CR0_AIPS0SBE_SHIFT)) & CE_SRG_S_CR0_AIPS0SBE_MASK)

#define CE_SRG_S_CR0_AIPS1SBE_MASK               (0x40000U)
#define CE_SRG_S_CR0_AIPS1SBE_SHIFT              (18U)
#define CE_SRG_S_CR0_AIPS1SBE_WIDTH              (1U)
#define CE_SRG_S_CR0_AIPS1SBE(x)                 (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_CR0_AIPS1SBE_SHIFT)) & CE_SRG_S_CR0_AIPS1SBE_MASK)

#define CE_SRG_S_CR0_AIPS2SBE_MASK               (0x80000U)
#define CE_SRG_S_CR0_AIPS2SBE_SHIFT              (19U)
#define CE_SRG_S_CR0_AIPS2SBE_WIDTH              (1U)
#define CE_SRG_S_CR0_AIPS2SBE(x)                 (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_CR0_AIPS2SBE_SHIFT)) & CE_SRG_S_CR0_AIPS2SBE_MASK)

#define CE_SRG_S_CR0_AIPS3SBE_MASK               (0x100000U)
#define CE_SRG_S_CR0_AIPS3SBE_SHIFT              (20U)
#define CE_SRG_S_CR0_AIPS3SBE_WIDTH              (1U)
#define CE_SRG_S_CR0_AIPS3SBE(x)                 (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_CR0_AIPS3SBE_SHIFT)) & CE_SRG_S_CR0_AIPS3SBE_MASK)
/*! @} */

/*! @name LCR0 - Lock Control 0 */
/*! @{ */

#define CE_SRG_S_LCR0_LNSMPU_MASK                (0x10000U)
#define CE_SRG_S_LCR0_LNSMPU_SHIFT               (16U)
#define CE_SRG_S_LCR0_LNSMPU_WIDTH               (1U)
#define CE_SRG_S_LCR0_LNSMPU(x)                  (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR0_LNSMPU_SHIFT)) & CE_SRG_S_LCR0_LNSMPU_MASK)

#define CE_SRG_S_LCR0_LNSVTOR_MASK               (0x40000U)
#define CE_SRG_S_LCR0_LNSVTOR_SHIFT              (18U)
#define CE_SRG_S_LCR0_LNSVTOR_WIDTH              (1U)
#define CE_SRG_S_LCR0_LNSVTOR(x)                 (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR0_LNSVTOR_SHIFT)) & CE_SRG_S_LCR0_LNSVTOR_MASK)

#define CE_SRG_S_LCR0_DID_MASK                   (0xF000000U)
#define CE_SRG_S_LCR0_DID_SHIFT                  (24U)
#define CE_SRG_S_LCR0_DID_WIDTH                  (4U)
#define CE_SRG_S_LCR0_DID(x)                     (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR0_DID_SHIFT)) & CE_SRG_S_LCR0_DID_MASK)

#define CE_SRG_S_LCR0_LKR_MASK                   (0xC0000000U)
#define CE_SRG_S_LCR0_LKR_SHIFT                  (30U)
#define CE_SRG_S_LCR0_LKR_WIDTH                  (2U)
#define CE_SRG_S_LCR0_LKR(x)                     (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR0_LKR_SHIFT)) & CE_SRG_S_LCR0_LKR_MASK)
/*! @} */

/*! @name LCR1 - Lock Control 1 */
/*! @{ */

#define CE_SRG_S_LCR1_LNSMPU_MASK                (0x10000U)
#define CE_SRG_S_LCR1_LNSMPU_SHIFT               (16U)
#define CE_SRG_S_LCR1_LNSMPU_WIDTH               (1U)
#define CE_SRG_S_LCR1_LNSMPU(x)                  (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR1_LNSMPU_SHIFT)) & CE_SRG_S_LCR1_LNSMPU_MASK)

#define CE_SRG_S_LCR1_LNSVTOR_MASK               (0x40000U)
#define CE_SRG_S_LCR1_LNSVTOR_SHIFT              (18U)
#define CE_SRG_S_LCR1_LNSVTOR_WIDTH              (1U)
#define CE_SRG_S_LCR1_LNSVTOR(x)                 (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR1_LNSVTOR_SHIFT)) & CE_SRG_S_LCR1_LNSVTOR_MASK)

#define CE_SRG_S_LCR1_DID_MASK                   (0xF000000U)
#define CE_SRG_S_LCR1_DID_SHIFT                  (24U)
#define CE_SRG_S_LCR1_DID_WIDTH                  (4U)
#define CE_SRG_S_LCR1_DID(x)                     (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR1_DID_SHIFT)) & CE_SRG_S_LCR1_DID_MASK)

#define CE_SRG_S_LCR1_LKR_MASK                   (0xC0000000U)
#define CE_SRG_S_LCR1_LKR_SHIFT                  (30U)
#define CE_SRG_S_LCR1_LKR_WIDTH                  (2U)
#define CE_SRG_S_LCR1_LKR(x)                     (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR1_LKR_SHIFT)) & CE_SRG_S_LCR1_LKR_MASK)
/*! @} */

/*! @name LCR2 - Lock Control 2 */
/*! @{ */

#define CE_SRG_S_LCR2_REMAP_EN_MASK              (0x1U)
#define CE_SRG_S_LCR2_REMAP_EN_SHIFT             (0U)
#define CE_SRG_S_LCR2_REMAP_EN_WIDTH             (1U)
#define CE_SRG_S_LCR2_REMAP_EN(x)                (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR2_REMAP_EN_SHIFT)) & CE_SRG_S_LCR2_REMAP_EN_MASK)

#define CE_SRG_S_LCR2_REMAP0_MASK                (0x100U)
#define CE_SRG_S_LCR2_REMAP0_SHIFT               (8U)
#define CE_SRG_S_LCR2_REMAP0_WIDTH               (1U)
#define CE_SRG_S_LCR2_REMAP0(x)                  (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR2_REMAP0_SHIFT)) & CE_SRG_S_LCR2_REMAP0_MASK)

#define CE_SRG_S_LCR2_REMAP1_MASK                (0x200U)
#define CE_SRG_S_LCR2_REMAP1_SHIFT               (9U)
#define CE_SRG_S_LCR2_REMAP1_WIDTH               (1U)
#define CE_SRG_S_LCR2_REMAP1(x)                  (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR2_REMAP1_SHIFT)) & CE_SRG_S_LCR2_REMAP1_MASK)

#define CE_SRG_S_LCR2_REMAP2_MASK                (0x400U)
#define CE_SRG_S_LCR2_REMAP2_SHIFT               (10U)
#define CE_SRG_S_LCR2_REMAP2_WIDTH               (1U)
#define CE_SRG_S_LCR2_REMAP2(x)                  (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR2_REMAP2_SHIFT)) & CE_SRG_S_LCR2_REMAP2_MASK)

#define CE_SRG_S_LCR2_DID_MASK                   (0xF000000U)
#define CE_SRG_S_LCR2_DID_SHIFT                  (24U)
#define CE_SRG_S_LCR2_DID_WIDTH                  (4U)
#define CE_SRG_S_LCR2_DID(x)                     (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR2_DID_SHIFT)) & CE_SRG_S_LCR2_DID_MASK)

#define CE_SRG_S_LCR2_LKR_MASK                   (0xC0000000U)
#define CE_SRG_S_LCR2_LKR_SHIFT                  (30U)
#define CE_SRG_S_LCR2_LKR_WIDTH                  (2U)
#define CE_SRG_S_LCR2_LKR(x)                     (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR2_LKR_SHIFT)) & CE_SRG_S_LCR2_LKR_MASK)
/*! @} */

/*! @name LCR3 - Lock Control 3 */
/*! @{ */

#define CE_SRG_S_LCR3_R0RO_MASK                  (0xF8U)
#define CE_SRG_S_LCR3_R0RO_SHIFT                 (3U)
#define CE_SRG_S_LCR3_R0RO_WIDTH                 (5U)
#define CE_SRG_S_LCR3_R0RO(x)                    (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR3_R0RO_SHIFT)) & CE_SRG_S_LCR3_R0RO_MASK)

#define CE_SRG_S_LCR3_R1RO_MASK                  (0xF800U)
#define CE_SRG_S_LCR3_R1RO_SHIFT                 (11U)
#define CE_SRG_S_LCR3_R1RO_WIDTH                 (5U)
#define CE_SRG_S_LCR3_R1RO(x)                    (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR3_R1RO_SHIFT)) & CE_SRG_S_LCR3_R1RO_MASK)

#define CE_SRG_S_LCR3_DID_MASK                   (0xF000000U)
#define CE_SRG_S_LCR3_DID_SHIFT                  (24U)
#define CE_SRG_S_LCR3_DID_WIDTH                  (4U)
#define CE_SRG_S_LCR3_DID(x)                     (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR3_DID_SHIFT)) & CE_SRG_S_LCR3_DID_MASK)

#define CE_SRG_S_LCR3_LKR_MASK                   (0xC0000000U)
#define CE_SRG_S_LCR3_LKR_SHIFT                  (30U)
#define CE_SRG_S_LCR3_LKR_WIDTH                  (2U)
#define CE_SRG_S_LCR3_LKR(x)                     (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR3_LKR_SHIFT)) & CE_SRG_S_LCR3_LKR_MASK)
/*! @} */

/*! @name LCR4 - Lock Control 4 */
/*! @{ */

#define CE_SRG_S_LCR4_R2RO_MASK                  (0xF8U)
#define CE_SRG_S_LCR4_R2RO_SHIFT                 (3U)
#define CE_SRG_S_LCR4_R2RO_WIDTH                 (5U)
#define CE_SRG_S_LCR4_R2RO(x)                    (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR4_R2RO_SHIFT)) & CE_SRG_S_LCR4_R2RO_MASK)

#define CE_SRG_S_LCR4_DID_MASK                   (0xF000000U)
#define CE_SRG_S_LCR4_DID_SHIFT                  (24U)
#define CE_SRG_S_LCR4_DID_WIDTH                  (4U)
#define CE_SRG_S_LCR4_DID(x)                     (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR4_DID_SHIFT)) & CE_SRG_S_LCR4_DID_MASK)

#define CE_SRG_S_LCR4_LKR_MASK                   (0xC0000000U)
#define CE_SRG_S_LCR4_LKR_SHIFT                  (30U)
#define CE_SRG_S_LCR4_LKR_WIDTH                  (2U)
#define CE_SRG_S_LCR4_LKR(x)                     (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR4_LKR_SHIFT)) & CE_SRG_S_LCR4_LKR_MASK)
/*! @} */

/*! @name LCR7 - Lock Control 7 */
/*! @{ */

#define CE_SRG_S_LCR7_C0DBGSA_MASK               (0x10000U)
#define CE_SRG_S_LCR7_C0DBGSA_SHIFT              (16U)
#define CE_SRG_S_LCR7_C0DBGSA_WIDTH              (1U)
#define CE_SRG_S_LCR7_C0DBGSA(x)                 (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR7_C0DBGSA_SHIFT)) & CE_SRG_S_LCR7_C0DBGSA_MASK)

#define CE_SRG_S_LCR7_C1DBGSA_MASK               (0x20000U)
#define CE_SRG_S_LCR7_C1DBGSA_SHIFT              (17U)
#define CE_SRG_S_LCR7_C1DBGSA_WIDTH              (1U)
#define CE_SRG_S_LCR7_C1DBGSA(x)                 (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR7_C1DBGSA_SHIFT)) & CE_SRG_S_LCR7_C1DBGSA_MASK)

#define CE_SRG_S_LCR7_DID_MASK                   (0xF000000U)
#define CE_SRG_S_LCR7_DID_SHIFT                  (24U)
#define CE_SRG_S_LCR7_DID_WIDTH                  (4U)
#define CE_SRG_S_LCR7_DID(x)                     (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR7_DID_SHIFT)) & CE_SRG_S_LCR7_DID_MASK)

#define CE_SRG_S_LCR7_LKR_MASK                   (0xC0000000U)
#define CE_SRG_S_LCR7_LKR_SHIFT                  (30U)
#define CE_SRG_S_LCR7_LKR_WIDTH                  (2U)
#define CE_SRG_S_LCR7_LKR(x)                     (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_LCR7_LKR_SHIFT)) & CE_SRG_S_LCR7_LKR_MASK)
/*! @} */

/*! @name SR0 - Status 0 */
/*! @{ */

#define CE_SRG_S_SR0_R0EA_MASK                   (0x1U)
#define CE_SRG_S_SR0_R0EA_SHIFT                  (0U)
#define CE_SRG_S_SR0_R0EA_WIDTH                  (1U)
#define CE_SRG_S_SR0_R0EA(x)                     (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_R0EA_SHIFT)) & CE_SRG_S_SR0_R0EA_MASK)

#define CE_SRG_S_SR0_R1EA_MASK                   (0x2U)
#define CE_SRG_S_SR0_R1EA_SHIFT                  (1U)
#define CE_SRG_S_SR0_R1EA_WIDTH                  (1U)
#define CE_SRG_S_SR0_R1EA(x)                     (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_R1EA_SHIFT)) & CE_SRG_S_SR0_R1EA_MASK)

#define CE_SRG_S_SR0_R2EA_MASK                   (0x4U)
#define CE_SRG_S_SR0_R2EA_SHIFT                  (2U)
#define CE_SRG_S_SR0_R2EA_WIDTH                  (1U)
#define CE_SRG_S_SR0_R2EA(x)                     (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_R2EA_SHIFT)) & CE_SRG_S_SR0_R2EA_MASK)

#define CE_SRG_S_SR0_R0WEA_MASK                  (0x10U)
#define CE_SRG_S_SR0_R0WEA_SHIFT                 (4U)
#define CE_SRG_S_SR0_R0WEA_WIDTH                 (1U)
#define CE_SRG_S_SR0_R0WEA(x)                    (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_R0WEA_SHIFT)) & CE_SRG_S_SR0_R0WEA_MASK)

#define CE_SRG_S_SR0_R1WEA_MASK                  (0x20U)
#define CE_SRG_S_SR0_R1WEA_SHIFT                 (5U)
#define CE_SRG_S_SR0_R1WEA_WIDTH                 (1U)
#define CE_SRG_S_SR0_R1WEA(x)                    (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_R1WEA_SHIFT)) & CE_SRG_S_SR0_R1WEA_MASK)

#define CE_SRG_S_SR0_R2WEA_MASK                  (0x40U)
#define CE_SRG_S_SR0_R2WEA_SHIFT                 (6U)
#define CE_SRG_S_SR0_R2WEA_WIDTH                 (1U)
#define CE_SRG_S_SR0_R2WEA(x)                    (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_R2WEA_SHIFT)) & CE_SRG_S_SR0_R2WEA_MASK)

#define CE_SRG_S_SR0_C0CTRE_MASK                 (0x100U)
#define CE_SRG_S_SR0_C0CTRE_SHIFT                (8U)
#define CE_SRG_S_SR0_C0CTRE_WIDTH                (1U)
#define CE_SRG_S_SR0_C0CTRE(x)                   (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_C0CTRE_SHIFT)) & CE_SRG_S_SR0_C0CTRE_MASK)

#define CE_SRG_S_SR0_C0CDRE_MASK                 (0x200U)
#define CE_SRG_S_SR0_C0CDRE_SHIFT                (9U)
#define CE_SRG_S_SR0_C0CDRE_WIDTH                (1U)
#define CE_SRG_S_SR0_C0CDRE(x)                   (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_C0CDRE_SHIFT)) & CE_SRG_S_SR0_C0CDRE_MASK)

#define CE_SRG_S_SR0_C0STRE_MASK                 (0x400U)
#define CE_SRG_S_SR0_C0STRE_SHIFT                (10U)
#define CE_SRG_S_SR0_C0STRE_WIDTH                (1U)
#define CE_SRG_S_SR0_C0STRE(x)                   (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_C0STRE_SHIFT)) & CE_SRG_S_SR0_C0STRE_MASK)

#define CE_SRG_S_SR0_C0SDRE_MASK                 (0x800U)
#define CE_SRG_S_SR0_C0SDRE_SHIFT                (11U)
#define CE_SRG_S_SR0_C0SDRE_WIDTH                (1U)
#define CE_SRG_S_SR0_C0SDRE(x)                   (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_C0SDRE_SHIFT)) & CE_SRG_S_SR0_C0SDRE_MASK)

#define CE_SRG_S_SR0_C1CTRE_MASK                 (0x1000U)
#define CE_SRG_S_SR0_C1CTRE_SHIFT                (12U)
#define CE_SRG_S_SR0_C1CTRE_WIDTH                (1U)
#define CE_SRG_S_SR0_C1CTRE(x)                   (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_C1CTRE_SHIFT)) & CE_SRG_S_SR0_C1CTRE_MASK)

#define CE_SRG_S_SR0_C1CDRE_MASK                 (0x2000U)
#define CE_SRG_S_SR0_C1CDRE_SHIFT                (13U)
#define CE_SRG_S_SR0_C1CDRE_WIDTH                (1U)
#define CE_SRG_S_SR0_C1CDRE(x)                   (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_C1CDRE_SHIFT)) & CE_SRG_S_SR0_C1CDRE_MASK)

#define CE_SRG_S_SR0_C1STRE_MASK                 (0x4000U)
#define CE_SRG_S_SR0_C1STRE_SHIFT                (14U)
#define CE_SRG_S_SR0_C1STRE_WIDTH                (1U)
#define CE_SRG_S_SR0_C1STRE(x)                   (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_C1STRE_SHIFT)) & CE_SRG_S_SR0_C1STRE_MASK)

#define CE_SRG_S_SR0_C1SDRE_MASK                 (0x8000U)
#define CE_SRG_S_SR0_C1SDRE_SHIFT                (15U)
#define CE_SRG_S_SR0_C1SDRE_WIDTH                (1U)
#define CE_SRG_S_SR0_C1SDRE(x)                   (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_C1SDRE_SHIFT)) & CE_SRG_S_SR0_C1SDRE_MASK)

#define CE_SRG_S_SR0_C0CCCMCRE_MASK              (0x10000U)
#define CE_SRG_S_SR0_C0CCCMCRE_SHIFT             (16U)
#define CE_SRG_S_SR0_C0CCCMCRE_WIDTH             (1U)
#define CE_SRG_S_SR0_C0CCCMCRE(x)                (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_C0CCCMCRE_SHIFT)) & CE_SRG_S_SR0_C0CCCMCRE_MASK)

#define CE_SRG_S_SR0_C0SCCMCRE_MASK              (0x20000U)
#define CE_SRG_S_SR0_C0SCCMCRE_SHIFT             (17U)
#define CE_SRG_S_SR0_C0SCCMCRE_WIDTH             (1U)
#define CE_SRG_S_SR0_C0SCCMCRE(x)                (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_C0SCCMCRE_SHIFT)) & CE_SRG_S_SR0_C0SCCMCRE_MASK)

#define CE_SRG_S_SR0_C1CCCMCRE_MASK              (0x40000U)
#define CE_SRG_S_SR0_C1CCCMCRE_SHIFT             (18U)
#define CE_SRG_S_SR0_C1CCCMCRE_WIDTH             (1U)
#define CE_SRG_S_SR0_C1CCCMCRE(x)                (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_C1CCCMCRE_SHIFT)) & CE_SRG_S_SR0_C1CCCMCRE_MASK)

#define CE_SRG_S_SR0_C1SCCMCRE_MASK              (0x80000U)
#define CE_SRG_S_SR0_C1SCCMCRE_SHIFT             (19U)
#define CE_SRG_S_SR0_C1SCCMCRE_WIDTH             (1U)
#define CE_SRG_S_SR0_C1SCCMCRE(x)                (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_C1SCCMCRE_SHIFT)) & CE_SRG_S_SR0_C1SCCMCRE_MASK)

#define CE_SRG_S_SR0_CORE0H_MASK                 (0x100000U)
#define CE_SRG_S_SR0_CORE0H_SHIFT                (20U)
#define CE_SRG_S_SR0_CORE0H_WIDTH                (1U)
#define CE_SRG_S_SR0_CORE0H(x)                   (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_CORE0H_SHIFT)) & CE_SRG_S_SR0_CORE0H_MASK)

#define CE_SRG_S_SR0_CORE0TU_MASK                (0x200000U)
#define CE_SRG_S_SR0_CORE0TU_SHIFT               (21U)
#define CE_SRG_S_SR0_CORE0TU_WIDTH               (1U)
#define CE_SRG_S_SR0_CORE0TU(x)                  (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_CORE0TU_SHIFT)) & CE_SRG_S_SR0_CORE0TU_MASK)

#define CE_SRG_S_SR0_CORE1H_MASK                 (0x400000U)
#define CE_SRG_S_SR0_CORE1H_SHIFT                (22U)
#define CE_SRG_S_SR0_CORE1H_WIDTH                (1U)
#define CE_SRG_S_SR0_CORE1H(x)                   (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_CORE1H_SHIFT)) & CE_SRG_S_SR0_CORE1H_MASK)

#define CE_SRG_S_SR0_CORE1TU_MASK                (0x800000U)
#define CE_SRG_S_SR0_CORE1TU_SHIFT               (23U)
#define CE_SRG_S_SR0_CORE1TU_WIDTH               (1U)
#define CE_SRG_S_SR0_CORE1TU(x)                  (((uint32_t)(((uint32_t)(x)) << CE_SRG_S_SR0_CORE1TU_SHIFT)) & CE_SRG_S_SR0_CORE1TU_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CE_SRG_S_Register_Masks */

/*!
 * @}
 */ /* end of group CE_SRG_S_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_CE_SRG_S_H_) */
