/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_NETC_PRIV.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_NETC_PRIV
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
#if !defined(S32Z2_NETC_PRIV_H_)  /* Check if memory map has not been already included */
#define S32Z2_NETC_PRIV_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- NETC_PRIV Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_PRIV_Peripheral_Access_Layer NETC_PRIV Peripheral Access Layer
 * @{
 */

/** NETC_PRIV - Register Layout Typedef */
typedef struct {
  uint8_t RESERVED_0[256];
  __IO uint32_t NETCRR;                            /**< NETC reset register, offset: 0x100 */
  __I  uint32_t NETCSR;                            /**< NETC status register, offset: 0x104 */
  uint8_t RESERVED_1[248];
  __IO uint32_t IEICR0;                            /**< Integrity Error Injection Config Register 0, offset: 0x200 */
  __IO uint32_t IEICR1;                            /**< Integrity Error Injection Config Register 1, offset: 0x204 */
  __IO uint32_t MEICR;                             /**< Memory Error Injection Config Register, offset: 0x208 */
  uint8_t RESERVED_2[244];
  __IO uint32_t NETCWDTR;                          /**< NETC watch dog timer register, offset: 0x300 */
  uint8_t RESERVED_3[2812];
  __IO uint32_t CMECR;                             /**< Correctable memory error configuration register, offset: 0xE00 */
  __IO uint32_t CMESR;                             /**< Correctable memory error status register, offset: 0xE04 */
  uint8_t RESERVED_4[4];
  __I  uint32_t CMECTR;                            /**< Correctable memory error count register, offset: 0xE0C */
  uint8_t RESERVED_5[32];
  __IO uint32_t UNMECR;                            /**< Uncorrectable non-fatal memory error configuration register, offset: 0xE30 */
  __IO uint32_t UNMESR0;                           /**< Uncorrectable non-fatal memory error status register 0, offset: 0xE34 */
  __I  uint32_t UNMESR1;                           /**< Uncorrectable non-fatal memory error status register 1, offset: 0xE38 */
  __I  uint32_t UNMECTR;                           /**< Uncorrectable non-fatal memory error count register, offset: 0xE3C */
  __IO uint32_t UFMECR;                            /**< Uncorrectable fatal memory error configuration register, offset: 0xE40 */
  __IO uint32_t UFMESR0;                           /**< Uncorrectable fatal memory error status register 0, offset: 0xE44 */
  __I  uint32_t UFMESR1;                           /**< Uncorrectable fatal memory error status register 1, offset: 0xE48 */
  uint8_t RESERVED_6[4];
  __IO uint32_t UNIECR;                            /**< Uncorrectable non-fatal integrity error configuration register, offset: 0xE50 */
  __IO uint32_t UNIESR;                            /**< Uncorrectable non-fatal integrity error status register, offset: 0xE54 */
  uint8_t RESERVED_7[4];
  __I  uint32_t UNIECTR;                           /**< Uncorrectable non-fatal integrity error count register, offset: 0xE5C */
  __IO uint32_t UFIECR;                            /**< Uncorrectable fatal integrity error configuration register, offset: 0xE60 */
  __IO uint32_t UFIESR;                            /**< Uncorrectable fatal integrity error status register, offset: 0xE64 */
} NETC_PRIV_Type, *NETC_PRIV_MemMapPtr;

/** Number of instances of the NETC_PRIV module. */
#define NETC_PRIV_INSTANCE_COUNT                 (1u)

/* NETC_PRIV - Peripheral instance base addresses */
/** Peripheral NETC__NETC_PRIV base address */
#define IP_NETC__NETC_PRIV_BASE                  (0x74900000u)
/** Peripheral NETC__NETC_PRIV base pointer */
#define IP_NETC__NETC_PRIV                       ((NETC_PRIV_Type *)IP_NETC__NETC_PRIV_BASE)
/** Array initializer of NETC_PRIV peripheral base addresses */
#define IP_NETC_PRIV_BASE_ADDRS                  { IP_NETC__NETC_PRIV_BASE }
/** Array initializer of NETC_PRIV peripheral base pointers */
#define IP_NETC_PRIV_BASE_PTRS                   { IP_NETC__NETC_PRIV }

/* ----------------------------------------------------------------------------
   -- NETC_PRIV Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_PRIV_Register_Masks NETC_PRIV Register Masks
 * @{
 */

/*! @name NETCRR - NETC reset register */
/*! @{ */

#define NETC_PRIV_NETCRR_SR_MASK                 (0x1U)
#define NETC_PRIV_NETCRR_SR_SHIFT                (0U)
#define NETC_PRIV_NETCRR_SR_WIDTH                (1U)
#define NETC_PRIV_NETCRR_SR(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_NETCRR_SR_SHIFT)) & NETC_PRIV_NETCRR_SR_MASK)

#define NETC_PRIV_NETCRR_LOCK_MASK               (0x2U)
#define NETC_PRIV_NETCRR_LOCK_SHIFT              (1U)
#define NETC_PRIV_NETCRR_LOCK_WIDTH              (1U)
#define NETC_PRIV_NETCRR_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_NETCRR_LOCK_SHIFT)) & NETC_PRIV_NETCRR_LOCK_MASK)
/*! @} */

/*! @name NETCSR - NETC status register */
/*! @{ */

#define NETC_PRIV_NETCSR_ERROR_MASK              (0x1U)
#define NETC_PRIV_NETCSR_ERROR_SHIFT             (0U)
#define NETC_PRIV_NETCSR_ERROR_WIDTH             (1U)
#define NETC_PRIV_NETCSR_ERROR(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_NETCSR_ERROR_SHIFT)) & NETC_PRIV_NETCSR_ERROR_MASK)

#define NETC_PRIV_NETCSR_STATE_MASK              (0x2U)
#define NETC_PRIV_NETCSR_STATE_SHIFT             (1U)
#define NETC_PRIV_NETCSR_STATE_WIDTH             (1U)
#define NETC_PRIV_NETCSR_STATE(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_NETCSR_STATE_SHIFT)) & NETC_PRIV_NETCSR_STATE_MASK)
/*! @} */

/*! @name IEICR0 - Integrity Error Injection Config Register 0 */
/*! @{ */

#define NETC_PRIV_IEICR0_LINK_SLICE_ID_MASK      (0xFU)
#define NETC_PRIV_IEICR0_LINK_SLICE_ID_SHIFT     (0U)
#define NETC_PRIV_IEICR0_LINK_SLICE_ID_WIDTH     (4U)
#define NETC_PRIV_IEICR0_LINK_SLICE_ID(x)        (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_IEICR0_LINK_SLICE_ID_SHIFT)) & NETC_PRIV_IEICR0_LINK_SLICE_ID_MASK)

#define NETC_PRIV_IEICR0_BLOCK_ID_MASK           (0xF0U)
#define NETC_PRIV_IEICR0_BLOCK_ID_SHIFT          (4U)
#define NETC_PRIV_IEICR0_BLOCK_ID_WIDTH          (4U)
#define NETC_PRIV_IEICR0_BLOCK_ID(x)             (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_IEICR0_BLOCK_ID_SHIFT)) & NETC_PRIV_IEICR0_BLOCK_ID_MASK)

#define NETC_PRIV_IEICR0_SM_ID_MASK              (0x3F00U)
#define NETC_PRIV_IEICR0_SM_ID_SHIFT             (8U)
#define NETC_PRIV_IEICR0_SM_ID_WIDTH             (6U)
#define NETC_PRIV_IEICR0_SM_ID(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_IEICR0_SM_ID_SHIFT)) & NETC_PRIV_IEICR0_SM_ID_MASK)

#define NETC_PRIV_IEICR0_ENGINE_ID_MASK          (0x10000U)
#define NETC_PRIV_IEICR0_ENGINE_ID_SHIFT         (16U)
#define NETC_PRIV_IEICR0_ENGINE_ID_WIDTH         (1U)
#define NETC_PRIV_IEICR0_ENGINE_ID(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_IEICR0_ENGINE_ID_SHIFT)) & NETC_PRIV_IEICR0_ENGINE_ID_MASK)

#define NETC_PRIV_IEICR0_ARM_MASK                (0x400000U)
#define NETC_PRIV_IEICR0_ARM_SHIFT               (22U)
#define NETC_PRIV_IEICR0_ARM_WIDTH               (1U)
#define NETC_PRIV_IEICR0_ARM(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_IEICR0_ARM_SHIFT)) & NETC_PRIV_IEICR0_ARM_MASK)

#define NETC_PRIV_IEICR0_EN_MASK                 (0xFF000000U)
#define NETC_PRIV_IEICR0_EN_SHIFT                (24U)
#define NETC_PRIV_IEICR0_EN_WIDTH                (8U)
#define NETC_PRIV_IEICR0_EN(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_IEICR0_EN_SHIFT)) & NETC_PRIV_IEICR0_EN_MASK)
/*! @} */

/*! @name IEICR1 - Integrity Error Injection Config Register 1 */
/*! @{ */

#define NETC_PRIV_IEICR1_ENGINE_EN0_MASK         (0x1U)
#define NETC_PRIV_IEICR1_ENGINE_EN0_SHIFT        (0U)
#define NETC_PRIV_IEICR1_ENGINE_EN0_WIDTH        (1U)
#define NETC_PRIV_IEICR1_ENGINE_EN0(x)           (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_IEICR1_ENGINE_EN0_SHIFT)) & NETC_PRIV_IEICR1_ENGINE_EN0_MASK)

#define NETC_PRIV_IEICR1_ENGINE_EN1_MASK         (0x2U)
#define NETC_PRIV_IEICR1_ENGINE_EN1_SHIFT        (1U)
#define NETC_PRIV_IEICR1_ENGINE_EN1_WIDTH        (1U)
#define NETC_PRIV_IEICR1_ENGINE_EN1(x)           (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_IEICR1_ENGINE_EN1_SHIFT)) & NETC_PRIV_IEICR1_ENGINE_EN1_MASK)
/*! @} */

/*! @name MEICR - Memory Error Injection Config Register */
/*! @{ */

#define NETC_PRIV_MEICR_MEM_ID_MASK              (0x1FU)
#define NETC_PRIV_MEICR_MEM_ID_SHIFT             (0U)
#define NETC_PRIV_MEICR_MEM_ID_WIDTH             (5U)
#define NETC_PRIV_MEICR_MEM_ID(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_MEICR_MEM_ID_SHIFT)) & NETC_PRIV_MEICR_MEM_ID_MASK)

#define NETC_PRIV_MEICR_ARM_MASK                 (0xC00000U)
#define NETC_PRIV_MEICR_ARM_SHIFT                (22U)
#define NETC_PRIV_MEICR_ARM_WIDTH                (2U)
#define NETC_PRIV_MEICR_ARM(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_MEICR_ARM_SHIFT)) & NETC_PRIV_MEICR_ARM_MASK)

#define NETC_PRIV_MEICR_EN_MASK                  (0xFF000000U)
#define NETC_PRIV_MEICR_EN_SHIFT                 (24U)
#define NETC_PRIV_MEICR_EN_WIDTH                 (8U)
#define NETC_PRIV_MEICR_EN(x)                    (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_MEICR_EN_SHIFT)) & NETC_PRIV_MEICR_EN_MASK)
/*! @} */

/*! @name NETCWDTR - NETC watch dog timer register */
/*! @{ */

#define NETC_PRIV_NETCWDTR_MCED_MASK             (0x1U)
#define NETC_PRIV_NETCWDTR_MCED_SHIFT            (0U)
#define NETC_PRIV_NETCWDTR_MCED_WIDTH            (1U)
#define NETC_PRIV_NETCWDTR_MCED(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_NETCWDTR_MCED_SHIFT)) & NETC_PRIV_NETCWDTR_MCED_MASK)

#define NETC_PRIV_NETCWDTR_MCPD_MASK             (0x2U)
#define NETC_PRIV_NETCWDTR_MCPD_SHIFT            (1U)
#define NETC_PRIV_NETCWDTR_MCPD_WIDTH            (1U)
#define NETC_PRIV_NETCWDTR_MCPD(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_NETCWDTR_MCPD_SHIFT)) & NETC_PRIV_NETCWDTR_MCPD_MASK)

#define NETC_PRIV_NETCWDTR_PCED_MASK             (0x4U)
#define NETC_PRIV_NETCWDTR_PCED_SHIFT            (2U)
#define NETC_PRIV_NETCWDTR_PCED_WIDTH            (1U)
#define NETC_PRIV_NETCWDTR_PCED(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_NETCWDTR_PCED_SHIFT)) & NETC_PRIV_NETCWDTR_PCED_MASK)

#define NETC_PRIV_NETCWDTR_HTAD_MASK             (0x8U)
#define NETC_PRIV_NETCWDTR_HTAD_SHIFT            (3U)
#define NETC_PRIV_NETCWDTR_HTAD_WIDTH            (1U)
#define NETC_PRIV_NETCWDTR_HTAD(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_NETCWDTR_HTAD_SHIFT)) & NETC_PRIV_NETCWDTR_HTAD_MASK)
/*! @} */

/*! @name CMECR - Correctable memory error configuration register */
/*! @{ */

#define NETC_PRIV_CMECR_THRESHOLD_MASK           (0xFFU)
#define NETC_PRIV_CMECR_THRESHOLD_SHIFT          (0U)
#define NETC_PRIV_CMECR_THRESHOLD_WIDTH          (8U)
#define NETC_PRIV_CMECR_THRESHOLD(x)             (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_CMECR_THRESHOLD_SHIFT)) & NETC_PRIV_CMECR_THRESHOLD_MASK)
/*! @} */

/*! @name CMESR - Correctable memory error status register */
/*! @{ */

#define NETC_PRIV_CMESR_MEM_ID_MASK              (0x1F0000U)
#define NETC_PRIV_CMESR_MEM_ID_SHIFT             (16U)
#define NETC_PRIV_CMESR_MEM_ID_WIDTH             (5U)
#define NETC_PRIV_CMESR_MEM_ID(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_CMESR_MEM_ID_SHIFT)) & NETC_PRIV_CMESR_MEM_ID_MASK)

#define NETC_PRIV_CMESR_SBEE_MASK                (0x80000000U)
#define NETC_PRIV_CMESR_SBEE_SHIFT               (31U)
#define NETC_PRIV_CMESR_SBEE_WIDTH               (1U)
#define NETC_PRIV_CMESR_SBEE(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_CMESR_SBEE_SHIFT)) & NETC_PRIV_CMESR_SBEE_MASK)
/*! @} */

/*! @name CMECTR - Correctable memory error count register */
/*! @{ */

#define NETC_PRIV_CMECTR_COUNT_MASK              (0xFFU)
#define NETC_PRIV_CMECTR_COUNT_SHIFT             (0U)
#define NETC_PRIV_CMECTR_COUNT_WIDTH             (8U)
#define NETC_PRIV_CMECTR_COUNT(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_CMECTR_COUNT_SHIFT)) & NETC_PRIV_CMECTR_COUNT_MASK)
/*! @} */

/*! @name UNMECR - Uncorrectable non-fatal memory error configuration register */
/*! @{ */

#define NETC_PRIV_UNMECR_THRESHOLD_MASK          (0xFFU)
#define NETC_PRIV_UNMECR_THRESHOLD_SHIFT         (0U)
#define NETC_PRIV_UNMECR_THRESHOLD_WIDTH         (8U)
#define NETC_PRIV_UNMECR_THRESHOLD(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMECR_THRESHOLD_SHIFT)) & NETC_PRIV_UNMECR_THRESHOLD_MASK)

#define NETC_PRIV_UNMECR_RD_MASK                 (0x80000000U)
#define NETC_PRIV_UNMECR_RD_SHIFT                (31U)
#define NETC_PRIV_UNMECR_RD_WIDTH                (1U)
#define NETC_PRIV_UNMECR_RD(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMECR_RD_SHIFT)) & NETC_PRIV_UNMECR_RD_MASK)
/*! @} */

/*! @name UNMESR0 - Uncorrectable non-fatal memory error status register 0 */
/*! @{ */

#define NETC_PRIV_UNMESR0_SYNDROME_MASK          (0x7FFU)
#define NETC_PRIV_UNMESR0_SYNDROME_SHIFT         (0U)
#define NETC_PRIV_UNMESR0_SYNDROME_WIDTH         (11U)
#define NETC_PRIV_UNMESR0_SYNDROME(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMESR0_SYNDROME_SHIFT)) & NETC_PRIV_UNMESR0_SYNDROME_MASK)

#define NETC_PRIV_UNMESR0_MEM_ID_MASK            (0x1F0000U)
#define NETC_PRIV_UNMESR0_MEM_ID_SHIFT           (16U)
#define NETC_PRIV_UNMESR0_MEM_ID_WIDTH           (5U)
#define NETC_PRIV_UNMESR0_MEM_ID(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMESR0_MEM_ID_SHIFT)) & NETC_PRIV_UNMESR0_MEM_ID_MASK)

#define NETC_PRIV_UNMESR0_MBEE_MASK              (0x80000000U)
#define NETC_PRIV_UNMESR0_MBEE_SHIFT             (31U)
#define NETC_PRIV_UNMESR0_MBEE_WIDTH             (1U)
#define NETC_PRIV_UNMESR0_MBEE(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMESR0_MBEE_SHIFT)) & NETC_PRIV_UNMESR0_MBEE_MASK)
/*! @} */

/*! @name UNMESR1 - Uncorrectable non-fatal memory error status register 1 */
/*! @{ */

#define NETC_PRIV_UNMESR1_ADDR_MASK              (0xFFFFFFFFU)
#define NETC_PRIV_UNMESR1_ADDR_SHIFT             (0U)
#define NETC_PRIV_UNMESR1_ADDR_WIDTH             (32U)
#define NETC_PRIV_UNMESR1_ADDR(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMESR1_ADDR_SHIFT)) & NETC_PRIV_UNMESR1_ADDR_MASK)
/*! @} */

/*! @name UNMECTR - Uncorrectable non-fatal memory error count register */
/*! @{ */

#define NETC_PRIV_UNMECTR_COUNT_MASK             (0xFFU)
#define NETC_PRIV_UNMECTR_COUNT_SHIFT            (0U)
#define NETC_PRIV_UNMECTR_COUNT_WIDTH            (8U)
#define NETC_PRIV_UNMECTR_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMECTR_COUNT_SHIFT)) & NETC_PRIV_UNMECTR_COUNT_MASK)
/*! @} */

/*! @name UFMECR - Uncorrectable fatal memory error configuration register */
/*! @{ */

#define NETC_PRIV_UFMECR_RD_MASK                 (0x80000000U)
#define NETC_PRIV_UFMECR_RD_SHIFT                (31U)
#define NETC_PRIV_UFMECR_RD_WIDTH                (1U)
#define NETC_PRIV_UFMECR_RD(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFMECR_RD_SHIFT)) & NETC_PRIV_UFMECR_RD_MASK)
/*! @} */

/*! @name UFMESR0 - Uncorrectable fatal memory error status register 0 */
/*! @{ */

#define NETC_PRIV_UFMESR0_SYNDROME_MASK          (0x7FFU)
#define NETC_PRIV_UFMESR0_SYNDROME_SHIFT         (0U)
#define NETC_PRIV_UFMESR0_SYNDROME_WIDTH         (11U)
#define NETC_PRIV_UFMESR0_SYNDROME(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFMESR0_SYNDROME_SHIFT)) & NETC_PRIV_UFMESR0_SYNDROME_MASK)

#define NETC_PRIV_UFMESR0_MEM_ID_MASK            (0x1F0000U)
#define NETC_PRIV_UFMESR0_MEM_ID_SHIFT           (16U)
#define NETC_PRIV_UFMESR0_MEM_ID_WIDTH           (5U)
#define NETC_PRIV_UFMESR0_MEM_ID(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFMESR0_MEM_ID_SHIFT)) & NETC_PRIV_UFMESR0_MEM_ID_MASK)

#define NETC_PRIV_UFMESR0_M_MASK                 (0x40000000U)
#define NETC_PRIV_UFMESR0_M_SHIFT                (30U)
#define NETC_PRIV_UFMESR0_M_WIDTH                (1U)
#define NETC_PRIV_UFMESR0_M(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFMESR0_M_SHIFT)) & NETC_PRIV_UFMESR0_M_MASK)

#define NETC_PRIV_UFMESR0_MBEE_MASK              (0x80000000U)
#define NETC_PRIV_UFMESR0_MBEE_SHIFT             (31U)
#define NETC_PRIV_UFMESR0_MBEE_WIDTH             (1U)
#define NETC_PRIV_UFMESR0_MBEE(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFMESR0_MBEE_SHIFT)) & NETC_PRIV_UFMESR0_MBEE_MASK)
/*! @} */

/*! @name UFMESR1 - Uncorrectable fatal memory error status register 1 */
/*! @{ */

#define NETC_PRIV_UFMESR1_ADDR_MASK              (0xFFFFFFFFU)
#define NETC_PRIV_UFMESR1_ADDR_SHIFT             (0U)
#define NETC_PRIV_UFMESR1_ADDR_WIDTH             (32U)
#define NETC_PRIV_UFMESR1_ADDR(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFMESR1_ADDR_SHIFT)) & NETC_PRIV_UFMESR1_ADDR_MASK)
/*! @} */

/*! @name UNIECR - Uncorrectable non-fatal integrity error configuration register */
/*! @{ */

#define NETC_PRIV_UNIECR_THRESHOLD_MASK          (0xFFU)
#define NETC_PRIV_UNIECR_THRESHOLD_SHIFT         (0U)
#define NETC_PRIV_UNIECR_THRESHOLD_WIDTH         (8U)
#define NETC_PRIV_UNIECR_THRESHOLD(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNIECR_THRESHOLD_SHIFT)) & NETC_PRIV_UNIECR_THRESHOLD_MASK)

#define NETC_PRIV_UNIECR_RD_MASK                 (0x80000000U)
#define NETC_PRIV_UNIECR_RD_SHIFT                (31U)
#define NETC_PRIV_UNIECR_RD_WIDTH                (1U)
#define NETC_PRIV_UNIECR_RD(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNIECR_RD_SHIFT)) & NETC_PRIV_UNIECR_RD_MASK)
/*! @} */

/*! @name UNIESR - Uncorrectable non-fatal integrity error status register */
/*! @{ */

#define NETC_PRIV_UNIESR_LINK_SLICE_ID_MASK      (0xFU)
#define NETC_PRIV_UNIESR_LINK_SLICE_ID_SHIFT     (0U)
#define NETC_PRIV_UNIESR_LINK_SLICE_ID_WIDTH     (4U)
#define NETC_PRIV_UNIESR_LINK_SLICE_ID(x)        (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNIESR_LINK_SLICE_ID_SHIFT)) & NETC_PRIV_UNIESR_LINK_SLICE_ID_MASK)

#define NETC_PRIV_UNIESR_BLOCK_ID_MASK           (0xF0U)
#define NETC_PRIV_UNIESR_BLOCK_ID_SHIFT          (4U)
#define NETC_PRIV_UNIESR_BLOCK_ID_WIDTH          (4U)
#define NETC_PRIV_UNIESR_BLOCK_ID(x)             (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNIESR_BLOCK_ID_SHIFT)) & NETC_PRIV_UNIESR_BLOCK_ID_MASK)

#define NETC_PRIV_UNIESR_SM_ID_MASK              (0x3F00U)
#define NETC_PRIV_UNIESR_SM_ID_SHIFT             (8U)
#define NETC_PRIV_UNIESR_SM_ID_WIDTH             (6U)
#define NETC_PRIV_UNIESR_SM_ID(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNIESR_SM_ID_SHIFT)) & NETC_PRIV_UNIESR_SM_ID_MASK)

#define NETC_PRIV_UNIESR_ENGINE_ID_MASK          (0x10000U)
#define NETC_PRIV_UNIESR_ENGINE_ID_SHIFT         (16U)
#define NETC_PRIV_UNIESR_ENGINE_ID_WIDTH         (1U)
#define NETC_PRIV_UNIESR_ENGINE_ID(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNIESR_ENGINE_ID_SHIFT)) & NETC_PRIV_UNIESR_ENGINE_ID_MASK)

#define NETC_PRIV_UNIESR_INTERR_MASK             (0x80000000U)
#define NETC_PRIV_UNIESR_INTERR_SHIFT            (31U)
#define NETC_PRIV_UNIESR_INTERR_WIDTH            (1U)
#define NETC_PRIV_UNIESR_INTERR(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNIESR_INTERR_SHIFT)) & NETC_PRIV_UNIESR_INTERR_MASK)
/*! @} */

/*! @name UNIECTR - Uncorrectable non-fatal integrity error count register */
/*! @{ */

#define NETC_PRIV_UNIECTR_COUNT_MASK             (0xFFU)
#define NETC_PRIV_UNIECTR_COUNT_SHIFT            (0U)
#define NETC_PRIV_UNIECTR_COUNT_WIDTH            (8U)
#define NETC_PRIV_UNIECTR_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNIECTR_COUNT_SHIFT)) & NETC_PRIV_UNIECTR_COUNT_MASK)
/*! @} */

/*! @name UFIECR - Uncorrectable fatal integrity error configuration register */
/*! @{ */

#define NETC_PRIV_UFIECR_RD_MASK                 (0x80000000U)
#define NETC_PRIV_UFIECR_RD_SHIFT                (31U)
#define NETC_PRIV_UFIECR_RD_WIDTH                (1U)
#define NETC_PRIV_UFIECR_RD(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFIECR_RD_SHIFT)) & NETC_PRIV_UFIECR_RD_MASK)
/*! @} */

/*! @name UFIESR - Uncorrectable fatal integrity error status register */
/*! @{ */

#define NETC_PRIV_UFIESR_LINK_SLICE_ID_MASK      (0xFU)
#define NETC_PRIV_UFIESR_LINK_SLICE_ID_SHIFT     (0U)
#define NETC_PRIV_UFIESR_LINK_SLICE_ID_WIDTH     (4U)
#define NETC_PRIV_UFIESR_LINK_SLICE_ID(x)        (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFIESR_LINK_SLICE_ID_SHIFT)) & NETC_PRIV_UFIESR_LINK_SLICE_ID_MASK)

#define NETC_PRIV_UFIESR_BLOCK_ID_MASK           (0xF0U)
#define NETC_PRIV_UFIESR_BLOCK_ID_SHIFT          (4U)
#define NETC_PRIV_UFIESR_BLOCK_ID_WIDTH          (4U)
#define NETC_PRIV_UFIESR_BLOCK_ID(x)             (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFIESR_BLOCK_ID_SHIFT)) & NETC_PRIV_UFIESR_BLOCK_ID_MASK)

#define NETC_PRIV_UFIESR_SM_ID_MASK              (0x3F00U)
#define NETC_PRIV_UFIESR_SM_ID_SHIFT             (8U)
#define NETC_PRIV_UFIESR_SM_ID_WIDTH             (6U)
#define NETC_PRIV_UFIESR_SM_ID(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFIESR_SM_ID_SHIFT)) & NETC_PRIV_UFIESR_SM_ID_MASK)

#define NETC_PRIV_UFIESR_ENGINE_ID_MASK          (0x10000U)
#define NETC_PRIV_UFIESR_ENGINE_ID_SHIFT         (16U)
#define NETC_PRIV_UFIESR_ENGINE_ID_WIDTH         (1U)
#define NETC_PRIV_UFIESR_ENGINE_ID(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFIESR_ENGINE_ID_SHIFT)) & NETC_PRIV_UFIESR_ENGINE_ID_MASK)

#define NETC_PRIV_UFIESR_M_MASK                  (0x40000000U)
#define NETC_PRIV_UFIESR_M_SHIFT                 (30U)
#define NETC_PRIV_UFIESR_M_WIDTH                 (1U)
#define NETC_PRIV_UFIESR_M(x)                    (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFIESR_M_SHIFT)) & NETC_PRIV_UFIESR_M_MASK)

#define NETC_PRIV_UFIESR_INTERR_MASK             (0x80000000U)
#define NETC_PRIV_UFIESR_INTERR_SHIFT            (31U)
#define NETC_PRIV_UFIESR_INTERR_WIDTH            (1U)
#define NETC_PRIV_UFIESR_INTERR(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFIESR_INTERR_SHIFT)) & NETC_PRIV_UFIESR_INTERR_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group NETC_PRIV_Register_Masks */

/*!
 * @}
 */ /* end of group NETC_PRIV_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_NETC_PRIV_H_) */
