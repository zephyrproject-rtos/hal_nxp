/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_FRO_SE.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_FRO_SE
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
#if !defined(S32K566_FRO_SE_H_)  /* Check if memory map has not been already included */
#define S32K566_FRO_SE_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- FRO_SE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FRO_SE_Peripheral_Access_Layer FRO_SE Peripheral Access Layer
 * @{
 */

/** FRO_SE - Register Layout Typedef */
typedef struct FRO_SE_Struct {
  uint8_t RESERVED_0[512];
  struct FRO_SE_CSR {                              /* offset: 0x200 */
    __IO uint32_t RW;                                /**< Control Status, offset: 0x200 */
    __IO uint32_t SET;                               /**< Control Status, offset: 0x204 */
    __IO uint32_t CLR;                               /**< Control Status, offset: 0x208 */
    __IO uint32_t TOG;                               /**< Control Status, offset: 0x20C */
  } CSR;
  struct FRO_SE_CNFG1 {                            /* offset: 0x210 */
    __IO uint32_t RW;                                /**< Trim Configuration 1, offset: 0x210 */
    __IO uint32_t SET;                               /**< Trim Configuration 1, offset: 0x214 */
    __IO uint32_t CLR;                               /**< Trim Configuration 1, offset: 0x218 */
    __IO uint32_t TOG;                               /**< Trim Configuration 1, offset: 0x21C */
  } CNFG1;
  uint8_t RESERVED_1[16];
  struct FRO_SE_FROTRIM {                          /* offset: 0x230 */
    __IO uint32_t RW;                                /**< FRO Trim, offset: 0x230 */
    __IO uint32_t SET;                               /**< FRO Trim, offset: 0x234 */
    __IO uint32_t CLR;                               /**< FRO Trim, offset: 0x238 */
    __IO uint32_t TOG;                               /**< FRO Trim, offset: 0x23C */
  } FROTRIM;
} FRO_SE_Type, *FRO_SE_MemMapPtr;

/** Number of instances of the FRO_SE module. */
#define FRO_SE_INSTANCE_COUNT                    (1u)

/* FRO_SE - Peripheral instance base addresses */
/** Peripheral LPE_FRO_SE base address */
#define IP_LPE_FRO_SE_BASE                       (0x4211C000u)
/** Peripheral LPE_FRO_SE base pointer */
#define IP_LPE_FRO_SE                            ((FRO_SE_Type *)IP_LPE_FRO_SE_BASE)
/** Array initializer of FRO_SE peripheral base addresses */
#define IP_FRO_SE_BASE_ADDRS                     { IP_LPE_FRO_SE_BASE }
/** Array initializer of FRO_SE peripheral base pointers */
#define IP_FRO_SE_BASE_PTRS                      { IP_LPE_FRO_SE }

/* ----------------------------------------------------------------------------
   -- FRO_SE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FRO_SE_Register_Masks FRO_SE Register Masks
 * @{
 */

/*! @name CSR - Control Status */
/*! @{ */

#define FRO_SE_CSR_FROEN_MASK                    (0x1U)
#define FRO_SE_CSR_FROEN_SHIFT                   (0U)
#define FRO_SE_CSR_FROEN_WIDTH                   (1U)
#define FRO_SE_CSR_FROEN(x)                      (((uint32_t)(((uint32_t)(x)) << FRO_SE_CSR_FROEN_SHIFT)) & FRO_SE_CSR_FROEN_MASK)

#define FRO_SE_CSR_TRIM_START_MASK               (0x4U)
#define FRO_SE_CSR_TRIM_START_SHIFT              (2U)
#define FRO_SE_CSR_TRIM_START_WIDTH              (1U)
#define FRO_SE_CSR_TRIM_START(x)                 (((uint32_t)(((uint32_t)(x)) << FRO_SE_CSR_TRIM_START_SHIFT)) & FRO_SE_CSR_TRIM_START_MASK)

#define FRO_SE_CSR_CLKGATE_MASK                  (0x1F00U)
#define FRO_SE_CSR_CLKGATE_SHIFT                 (8U)
#define FRO_SE_CSR_CLKGATE_WIDTH                 (5U)
#define FRO_SE_CSR_CLKGATE(x)                    (((uint32_t)(((uint32_t)(x)) << FRO_SE_CSR_CLKGATE_SHIFT)) & FRO_SE_CSR_CLKGATE_MASK)

#define FRO_SE_CSR_TRIM_DONE_MASK                (0x4000000U)
#define FRO_SE_CSR_TRIM_DONE_SHIFT               (26U)
#define FRO_SE_CSR_TRIM_DONE_WIDTH               (1U)
#define FRO_SE_CSR_TRIM_DONE(x)                  (((uint32_t)(((uint32_t)(x)) << FRO_SE_CSR_TRIM_DONE_SHIFT)) & FRO_SE_CSR_TRIM_DONE_MASK)
/*! @} */

/*! @name CNFG1 - Trim Configuration 1 */
/*! @{ */

#define FRO_SE_CNFG1_FSTUPEN_MASK                (0x800U)
#define FRO_SE_CNFG1_FSTUPEN_SHIFT               (11U)
#define FRO_SE_CNFG1_FSTUPEN_WIDTH               (1U)
#define FRO_SE_CNFG1_FSTUPEN(x)                  (((uint32_t)(((uint32_t)(x)) << FRO_SE_CNFG1_FSTUPEN_SHIFT)) & FRO_SE_CNFG1_FSTUPEN_MASK)
/*! @} */

/*! @name FROTRIM - FRO Trim */
/*! @{ */

#define FRO_SE_FROTRIM_FINE_TRIM_MASK            (0x7FU)
#define FRO_SE_FROTRIM_FINE_TRIM_SHIFT           (0U)
#define FRO_SE_FROTRIM_FINE_TRIM_WIDTH           (7U)
#define FRO_SE_FROTRIM_FINE_TRIM(x)              (((uint32_t)(((uint32_t)(x)) << FRO_SE_FROTRIM_FINE_TRIM_SHIFT)) & FRO_SE_FROTRIM_FINE_TRIM_MASK)

#define FRO_SE_FROTRIM_COARSE_TRIM_MASK          (0xF80U)
#define FRO_SE_FROTRIM_COARSE_TRIM_SHIFT         (7U)
#define FRO_SE_FROTRIM_COARSE_TRIM_WIDTH         (5U)
#define FRO_SE_FROTRIM_COARSE_TRIM(x)            (((uint32_t)(((uint32_t)(x)) << FRO_SE_FROTRIM_COARSE_TRIM_SHIFT)) & FRO_SE_FROTRIM_COARSE_TRIM_MASK)

#define FRO_SE_FROTRIM_TRIMTEMP_MASK             (0x3F0000U)
#define FRO_SE_FROTRIM_TRIMTEMP_SHIFT            (16U)
#define FRO_SE_FROTRIM_TRIMTEMP_WIDTH            (6U)
#define FRO_SE_FROTRIM_TRIMTEMP(x)               (((uint32_t)(((uint32_t)(x)) << FRO_SE_FROTRIM_TRIMTEMP_SHIFT)) & FRO_SE_FROTRIM_TRIMTEMP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FRO_SE_Register_Masks */

/*!
 * @}
 */ /* end of group FRO_SE_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_FRO_SE_H_) */
