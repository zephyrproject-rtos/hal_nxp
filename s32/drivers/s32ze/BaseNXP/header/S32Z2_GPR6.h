/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_GPR6.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_GPR6
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
#if !defined(S32Z2_GPR6_H_)  /* Check if memory map has not been already included */
#define S32Z2_GPR6_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- GPR6 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPR6_Peripheral_Access_Layer GPR6 Peripheral Access Layer
 * @{
 */

/** GPR6 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LVFCCUGD6;                         /**< VFCCU Global DID register 6, offset: 0x0 */
  __IO uint32_t LVFCCULD18;                        /**< VFCCU Local DID register 18, offset: 0x4 */
  __IO uint32_t LVFCCULD19;                        /**< VFCCU Local DID register 19, offset: 0x8 */
  __IO uint32_t LVFCCULD20;                        /**< VFCCU Local DID register 20, offset: 0xC */
  uint8_t RESERVED_0[4];
  __I  uint32_t TARGTMS6;                          /**< NoC Target NIU Timeout Status, offset: 0x14 */
  __IO uint32_t TARGTMC6;                          /**< NoC Target NIU Timeout Control, offset: 0x18 */
  uint8_t RESERVED_1[28];
  __IO uint32_t XPAR5;                             /**< Interface parity control and status register, offset: 0x38 */
} GPR6_Type, *GPR6_MemMapPtr;

/** Number of instances of the GPR6 module. */
#define GPR6_INSTANCE_COUNT                      (1u)

/* GPR6 - Peripheral instance base addresses */
/** Peripheral GPR6 base address */
#define IP_GPR6_BASE                             (0x44060000u)
/** Peripheral GPR6 base pointer */
#define IP_GPR6                                  ((GPR6_Type *)IP_GPR6_BASE)
/** Array initializer of GPR6 peripheral base addresses */
#define IP_GPR6_BASE_ADDRS                       { IP_GPR6_BASE }
/** Array initializer of GPR6 peripheral base pointers */
#define IP_GPR6_BASE_PTRS                        { IP_GPR6 }

/* ----------------------------------------------------------------------------
   -- GPR6 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPR6_Register_Masks GPR6 Register Masks
 * @{
 */

/*! @name LVFCCUGD6 - VFCCU Global DID register 6 */
/*! @{ */

#define GPR6_LVFCCUGD6_FHID_MASK                 (0xFU)
#define GPR6_LVFCCUGD6_FHID_SHIFT                (0U)
#define GPR6_LVFCCUGD6_FHID_WIDTH                (4U)
#define GPR6_LVFCCUGD6_FHID(x)                   (((uint32_t)(((uint32_t)(x)) << GPR6_LVFCCUGD6_FHID_SHIFT)) & GPR6_LVFCCUGD6_FHID_MASK)
/*! @} */

/*! @name LVFCCULD18 - VFCCU Local DID register 18 */
/*! @{ */

#define GPR6_LVFCCULD18_FHID_MASK                (0xFFFFFFFFU)
#define GPR6_LVFCCULD18_FHID_SHIFT               (0U)
#define GPR6_LVFCCULD18_FHID_WIDTH               (32U)
#define GPR6_LVFCCULD18_FHID(x)                  (((uint32_t)(((uint32_t)(x)) << GPR6_LVFCCULD18_FHID_SHIFT)) & GPR6_LVFCCULD18_FHID_MASK)
/*! @} */

/*! @name LVFCCULD19 - VFCCU Local DID register 19 */
/*! @{ */

#define GPR6_LVFCCULD19_FHID_MASK                (0xFFFFFFFFU)
#define GPR6_LVFCCULD19_FHID_SHIFT               (0U)
#define GPR6_LVFCCULD19_FHID_WIDTH               (32U)
#define GPR6_LVFCCULD19_FHID(x)                  (((uint32_t)(((uint32_t)(x)) << GPR6_LVFCCULD19_FHID_SHIFT)) & GPR6_LVFCCULD19_FHID_MASK)
/*! @} */

/*! @name LVFCCULD20 - VFCCU Local DID register 20 */
/*! @{ */

#define GPR6_LVFCCULD20_FHID_MASK                (0xFFFFFFFFU)
#define GPR6_LVFCCULD20_FHID_SHIFT               (0U)
#define GPR6_LVFCCULD20_FHID_WIDTH               (32U)
#define GPR6_LVFCCULD20_FHID(x)                  (((uint32_t)(((uint32_t)(x)) << GPR6_LVFCCULD20_FHID_SHIFT)) & GPR6_LVFCCULD20_FHID_MASK)
/*! @} */

/*! @name TARGTMS6 - NoC Target NIU Timeout Status */
/*! @{ */

#define GPR6_TARGTMS6_STAT_MASK                  (0xFFFFFFFFU)
#define GPR6_TARGTMS6_STAT_SHIFT                 (0U)
#define GPR6_TARGTMS6_STAT_WIDTH                 (32U)
#define GPR6_TARGTMS6_STAT(x)                    (((uint32_t)(((uint32_t)(x)) << GPR6_TARGTMS6_STAT_SHIFT)) & GPR6_TARGTMS6_STAT_MASK)
/*! @} */

/*! @name TARGTMC6 - NoC Target NIU Timeout Control */
/*! @{ */

#define GPR6_TARGTMC6_EN_MASK                    (0xFFFFFFFFU)
#define GPR6_TARGTMC6_EN_SHIFT                   (0U)
#define GPR6_TARGTMC6_EN_WIDTH                   (32U)
#define GPR6_TARGTMC6_EN(x)                      (((uint32_t)(((uint32_t)(x)) << GPR6_TARGTMC6_EN_SHIFT)) & GPR6_TARGTMC6_EN_MASK)
/*! @} */

/*! @name XPAR5 - Interface parity control and status register */
/*! @{ */

#define GPR6_XPAR5_DIS_MASK                      (0x1U)
#define GPR6_XPAR5_DIS_SHIFT                     (0U)
#define GPR6_XPAR5_DIS_WIDTH                     (1U)
#define GPR6_XPAR5_DIS(x)                        (((uint32_t)(((uint32_t)(x)) << GPR6_XPAR5_DIS_SHIFT)) & GPR6_XPAR5_DIS_MASK)

#define GPR6_XPAR5_STAT_MASK                     (0x100U)
#define GPR6_XPAR5_STAT_SHIFT                    (8U)
#define GPR6_XPAR5_STAT_WIDTH                    (1U)
#define GPR6_XPAR5_STAT(x)                       (((uint32_t)(((uint32_t)(x)) << GPR6_XPAR5_STAT_SHIFT)) & GPR6_XPAR5_STAT_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group GPR6_Register_Masks */

/*!
 * @}
 */ /* end of group GPR6_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_GPR6_H_) */
