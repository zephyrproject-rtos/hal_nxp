/*
** ###################################################################
**     Processors:          MKM34Z256VLL7
**                          MKM34Z256VLQ7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AIPS
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2014-10-17)
**         Initial version.
**     - rev. 1.1 (2015-01-27)
**         Update according to reference manual rev. 1, RC.
**     - rev. 1.2 (2015-03-06)
**         Update according to reference manual rev. 1.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_AIPS.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for AIPS
 *
 * CMSIS Peripheral Access Layer for AIPS
 */

#if !defined(PERI_AIPS_H_)
#define PERI_AIPS_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKM34Z256VLL7) || defined(CPU_MKM34Z256VLQ7))
#include "MKM34Z7_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- AIPS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AIPS_Peripheral_Access_Layer AIPS Peripheral Access Layer
 * @{
 */

/** AIPS - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[32];
  __IO uint32_t PACRA;                             /**< Peripheral Access Control Register, offset: 0x20 */
  __IO uint32_t PACRB;                             /**< Peripheral Access Control Register, offset: 0x24 */
       uint8_t RESERVED_1[24];
  __IO uint32_t PACRE;                             /**< Peripheral Access Control Register, offset: 0x40 */
  __IO uint32_t PACRF;                             /**< Peripheral Access Control Register, offset: 0x44 */
  __IO uint32_t PACRG;                             /**< Peripheral Access Control Register, offset: 0x48 */
  __IO uint32_t PACRH;                             /**< Peripheral Access Control Register, offset: 0x4C */
  __IO uint32_t PACRI;                             /**< Peripheral Access Control Register, offset: 0x50 */
  __IO uint32_t PACRJ;                             /**< Peripheral Access Control Register, offset: 0x54 */
  __IO uint32_t PACRK;                             /**< Peripheral Access Control Register, offset: 0x58 */
  __IO uint32_t PACRL;                             /**< Peripheral Access Control Register, offset: 0x5C */
  __IO uint32_t PACRM;                             /**< Peripheral Access Control Register, offset: 0x60 */
  __IO uint32_t PACRN;                             /**< Peripheral Access Control Register, offset: 0x64 */
  __IO uint32_t PACRO;                             /**< Peripheral Access Control Register, offset: 0x68 */
  __IO uint32_t PACRP;                             /**< Peripheral Access Control Register, offset: 0x6C */
} AIPS_Type;

/* ----------------------------------------------------------------------------
   -- AIPS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AIPS_Register_Masks AIPS Register Masks
 * @{
 */

/*! @name PACRA - Peripheral Access Control Register */
/*! @{ */

#define AIPS_PACRA_AC7_MASK                      (0x7U)
#define AIPS_PACRA_AC7_SHIFT                     (0U)
/*! AC7 - Attribute Check */
#define AIPS_PACRA_AC7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_AC7_SHIFT)) & AIPS_PACRA_AC7_MASK)

#define AIPS_PACRA_RO7_MASK                      (0x8U)
#define AIPS_PACRA_RO7_SHIFT                     (3U)
/*! RO7 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRA_RO7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_RO7_SHIFT)) & AIPS_PACRA_RO7_MASK)

#define AIPS_PACRA_AC6_MASK                      (0x70U)
#define AIPS_PACRA_AC6_SHIFT                     (4U)
/*! AC6 - Attribute Check */
#define AIPS_PACRA_AC6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_AC6_SHIFT)) & AIPS_PACRA_AC6_MASK)

#define AIPS_PACRA_RO6_MASK                      (0x80U)
#define AIPS_PACRA_RO6_SHIFT                     (7U)
/*! RO6 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRA_RO6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_RO6_SHIFT)) & AIPS_PACRA_RO6_MASK)

#define AIPS_PACRA_AC5_MASK                      (0x700U)
#define AIPS_PACRA_AC5_SHIFT                     (8U)
/*! AC5 - Attribute Check */
#define AIPS_PACRA_AC5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_AC5_SHIFT)) & AIPS_PACRA_AC5_MASK)

#define AIPS_PACRA_RO5_MASK                      (0x800U)
#define AIPS_PACRA_RO5_SHIFT                     (11U)
/*! RO5 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRA_RO5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_RO5_SHIFT)) & AIPS_PACRA_RO5_MASK)

#define AIPS_PACRA_AC4_MASK                      (0x7000U)
#define AIPS_PACRA_AC4_SHIFT                     (12U)
/*! AC4 - Attribute Check */
#define AIPS_PACRA_AC4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_AC4_SHIFT)) & AIPS_PACRA_AC4_MASK)

#define AIPS_PACRA_RO4_MASK                      (0x8000U)
#define AIPS_PACRA_RO4_SHIFT                     (15U)
/*! RO4 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRA_RO4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_RO4_SHIFT)) & AIPS_PACRA_RO4_MASK)

#define AIPS_PACRA_AC3_MASK                      (0x70000U)
#define AIPS_PACRA_AC3_SHIFT                     (16U)
/*! AC3 - Attribute Check */
#define AIPS_PACRA_AC3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_AC3_SHIFT)) & AIPS_PACRA_AC3_MASK)

#define AIPS_PACRA_RO3_MASK                      (0x80000U)
#define AIPS_PACRA_RO3_SHIFT                     (19U)
/*! RO3 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRA_RO3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_RO3_SHIFT)) & AIPS_PACRA_RO3_MASK)

#define AIPS_PACRA_AC2_MASK                      (0x700000U)
#define AIPS_PACRA_AC2_SHIFT                     (20U)
/*! AC2 - Attribute Check */
#define AIPS_PACRA_AC2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_AC2_SHIFT)) & AIPS_PACRA_AC2_MASK)

#define AIPS_PACRA_RO2_MASK                      (0x800000U)
#define AIPS_PACRA_RO2_SHIFT                     (23U)
/*! RO2 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRA_RO2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_RO2_SHIFT)) & AIPS_PACRA_RO2_MASK)

#define AIPS_PACRA_AC1_MASK                      (0x7000000U)
#define AIPS_PACRA_AC1_SHIFT                     (24U)
/*! AC1 - Attribute Check */
#define AIPS_PACRA_AC1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_AC1_SHIFT)) & AIPS_PACRA_AC1_MASK)

#define AIPS_PACRA_RO1_MASK                      (0x8000000U)
#define AIPS_PACRA_RO1_SHIFT                     (27U)
/*! RO1 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRA_RO1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_RO1_SHIFT)) & AIPS_PACRA_RO1_MASK)

#define AIPS_PACRA_AC0_MASK                      (0x70000000U)
#define AIPS_PACRA_AC0_SHIFT                     (28U)
/*! AC0 - Attribute Check */
#define AIPS_PACRA_AC0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_AC0_SHIFT)) & AIPS_PACRA_AC0_MASK)

#define AIPS_PACRA_RO0_MASK                      (0x80000000U)
#define AIPS_PACRA_RO0_SHIFT                     (31U)
/*! RO0 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRA_RO0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_RO0_SHIFT)) & AIPS_PACRA_RO0_MASK)
/*! @} */

/*! @name PACRB - Peripheral Access Control Register */
/*! @{ */

#define AIPS_PACRB_AC7_MASK                      (0x7U)
#define AIPS_PACRB_AC7_SHIFT                     (0U)
/*! AC7 - Attribute Check */
#define AIPS_PACRB_AC7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_AC7_SHIFT)) & AIPS_PACRB_AC7_MASK)

#define AIPS_PACRB_RO7_MASK                      (0x8U)
#define AIPS_PACRB_RO7_SHIFT                     (3U)
/*! RO7 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRB_RO7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_RO7_SHIFT)) & AIPS_PACRB_RO7_MASK)

#define AIPS_PACRB_AC6_MASK                      (0x70U)
#define AIPS_PACRB_AC6_SHIFT                     (4U)
/*! AC6 - Attribute Check */
#define AIPS_PACRB_AC6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_AC6_SHIFT)) & AIPS_PACRB_AC6_MASK)

#define AIPS_PACRB_RO6_MASK                      (0x80U)
#define AIPS_PACRB_RO6_SHIFT                     (7U)
/*! RO6 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRB_RO6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_RO6_SHIFT)) & AIPS_PACRB_RO6_MASK)

#define AIPS_PACRB_AC5_MASK                      (0x700U)
#define AIPS_PACRB_AC5_SHIFT                     (8U)
/*! AC5 - Attribute Check */
#define AIPS_PACRB_AC5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_AC5_SHIFT)) & AIPS_PACRB_AC5_MASK)

#define AIPS_PACRB_RO5_MASK                      (0x800U)
#define AIPS_PACRB_RO5_SHIFT                     (11U)
/*! RO5 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRB_RO5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_RO5_SHIFT)) & AIPS_PACRB_RO5_MASK)

#define AIPS_PACRB_AC4_MASK                      (0x7000U)
#define AIPS_PACRB_AC4_SHIFT                     (12U)
/*! AC4 - Attribute Check */
#define AIPS_PACRB_AC4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_AC4_SHIFT)) & AIPS_PACRB_AC4_MASK)

#define AIPS_PACRB_RO4_MASK                      (0x8000U)
#define AIPS_PACRB_RO4_SHIFT                     (15U)
/*! RO4 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRB_RO4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_RO4_SHIFT)) & AIPS_PACRB_RO4_MASK)

#define AIPS_PACRB_AC3_MASK                      (0x70000U)
#define AIPS_PACRB_AC3_SHIFT                     (16U)
/*! AC3 - Attribute Check */
#define AIPS_PACRB_AC3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_AC3_SHIFT)) & AIPS_PACRB_AC3_MASK)

#define AIPS_PACRB_RO3_MASK                      (0x80000U)
#define AIPS_PACRB_RO3_SHIFT                     (19U)
/*! RO3 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRB_RO3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_RO3_SHIFT)) & AIPS_PACRB_RO3_MASK)

#define AIPS_PACRB_AC2_MASK                      (0x700000U)
#define AIPS_PACRB_AC2_SHIFT                     (20U)
/*! AC2 - Attribute Check */
#define AIPS_PACRB_AC2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_AC2_SHIFT)) & AIPS_PACRB_AC2_MASK)

#define AIPS_PACRB_RO2_MASK                      (0x800000U)
#define AIPS_PACRB_RO2_SHIFT                     (23U)
/*! RO2 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRB_RO2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_RO2_SHIFT)) & AIPS_PACRB_RO2_MASK)

#define AIPS_PACRB_AC1_MASK                      (0x7000000U)
#define AIPS_PACRB_AC1_SHIFT                     (24U)
/*! AC1 - Attribute Check */
#define AIPS_PACRB_AC1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_AC1_SHIFT)) & AIPS_PACRB_AC1_MASK)

#define AIPS_PACRB_RO1_MASK                      (0x8000000U)
#define AIPS_PACRB_RO1_SHIFT                     (27U)
/*! RO1 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRB_RO1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_RO1_SHIFT)) & AIPS_PACRB_RO1_MASK)

#define AIPS_PACRB_AC0_MASK                      (0x70000000U)
#define AIPS_PACRB_AC0_SHIFT                     (28U)
/*! AC0 - Attribute Check */
#define AIPS_PACRB_AC0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_AC0_SHIFT)) & AIPS_PACRB_AC0_MASK)

#define AIPS_PACRB_RO0_MASK                      (0x80000000U)
#define AIPS_PACRB_RO0_SHIFT                     (31U)
/*! RO0 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRB_RO0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_RO0_SHIFT)) & AIPS_PACRB_RO0_MASK)
/*! @} */

/*! @name PACRE - Peripheral Access Control Register */
/*! @{ */

#define AIPS_PACRE_AC7_MASK                      (0x7U)
#define AIPS_PACRE_AC7_SHIFT                     (0U)
/*! AC7 - Attribute Check */
#define AIPS_PACRE_AC7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRE_AC7_SHIFT)) & AIPS_PACRE_AC7_MASK)

#define AIPS_PACRE_RO7_MASK                      (0x8U)
#define AIPS_PACRE_RO7_SHIFT                     (3U)
/*! RO7 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRE_RO7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRE_RO7_SHIFT)) & AIPS_PACRE_RO7_MASK)

#define AIPS_PACRE_AC6_MASK                      (0x70U)
#define AIPS_PACRE_AC6_SHIFT                     (4U)
/*! AC6 - Attribute Check */
#define AIPS_PACRE_AC6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRE_AC6_SHIFT)) & AIPS_PACRE_AC6_MASK)

#define AIPS_PACRE_RO6_MASK                      (0x80U)
#define AIPS_PACRE_RO6_SHIFT                     (7U)
/*! RO6 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRE_RO6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRE_RO6_SHIFT)) & AIPS_PACRE_RO6_MASK)

#define AIPS_PACRE_AC5_MASK                      (0x700U)
#define AIPS_PACRE_AC5_SHIFT                     (8U)
/*! AC5 - Attribute Check */
#define AIPS_PACRE_AC5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRE_AC5_SHIFT)) & AIPS_PACRE_AC5_MASK)

#define AIPS_PACRE_RO5_MASK                      (0x800U)
#define AIPS_PACRE_RO5_SHIFT                     (11U)
/*! RO5 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRE_RO5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRE_RO5_SHIFT)) & AIPS_PACRE_RO5_MASK)

#define AIPS_PACRE_AC4_MASK                      (0x7000U)
#define AIPS_PACRE_AC4_SHIFT                     (12U)
/*! AC4 - Attribute Check */
#define AIPS_PACRE_AC4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRE_AC4_SHIFT)) & AIPS_PACRE_AC4_MASK)

#define AIPS_PACRE_RO4_MASK                      (0x8000U)
#define AIPS_PACRE_RO4_SHIFT                     (15U)
/*! RO4 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRE_RO4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRE_RO4_SHIFT)) & AIPS_PACRE_RO4_MASK)

#define AIPS_PACRE_AC3_MASK                      (0x70000U)
#define AIPS_PACRE_AC3_SHIFT                     (16U)
/*! AC3 - Attribute Check */
#define AIPS_PACRE_AC3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRE_AC3_SHIFT)) & AIPS_PACRE_AC3_MASK)

#define AIPS_PACRE_RO3_MASK                      (0x80000U)
#define AIPS_PACRE_RO3_SHIFT                     (19U)
/*! RO3 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRE_RO3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRE_RO3_SHIFT)) & AIPS_PACRE_RO3_MASK)

#define AIPS_PACRE_AC2_MASK                      (0x700000U)
#define AIPS_PACRE_AC2_SHIFT                     (20U)
/*! AC2 - Attribute Check */
#define AIPS_PACRE_AC2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRE_AC2_SHIFT)) & AIPS_PACRE_AC2_MASK)

#define AIPS_PACRE_RO2_MASK                      (0x800000U)
#define AIPS_PACRE_RO2_SHIFT                     (23U)
/*! RO2 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRE_RO2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRE_RO2_SHIFT)) & AIPS_PACRE_RO2_MASK)

#define AIPS_PACRE_AC1_MASK                      (0x7000000U)
#define AIPS_PACRE_AC1_SHIFT                     (24U)
/*! AC1 - Attribute Check */
#define AIPS_PACRE_AC1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRE_AC1_SHIFT)) & AIPS_PACRE_AC1_MASK)

#define AIPS_PACRE_RO1_MASK                      (0x8000000U)
#define AIPS_PACRE_RO1_SHIFT                     (27U)
/*! RO1 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRE_RO1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRE_RO1_SHIFT)) & AIPS_PACRE_RO1_MASK)

#define AIPS_PACRE_AC0_MASK                      (0x70000000U)
#define AIPS_PACRE_AC0_SHIFT                     (28U)
/*! AC0 - Attribute Check */
#define AIPS_PACRE_AC0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRE_AC0_SHIFT)) & AIPS_PACRE_AC0_MASK)

#define AIPS_PACRE_RO0_MASK                      (0x80000000U)
#define AIPS_PACRE_RO0_SHIFT                     (31U)
/*! RO0 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRE_RO0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRE_RO0_SHIFT)) & AIPS_PACRE_RO0_MASK)
/*! @} */

/*! @name PACRF - Peripheral Access Control Register */
/*! @{ */

#define AIPS_PACRF_AC7_MASK                      (0x7U)
#define AIPS_PACRF_AC7_SHIFT                     (0U)
/*! AC7 - Attribute Check */
#define AIPS_PACRF_AC7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRF_AC7_SHIFT)) & AIPS_PACRF_AC7_MASK)

#define AIPS_PACRF_RO7_MASK                      (0x8U)
#define AIPS_PACRF_RO7_SHIFT                     (3U)
/*! RO7 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRF_RO7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRF_RO7_SHIFT)) & AIPS_PACRF_RO7_MASK)

#define AIPS_PACRF_AC6_MASK                      (0x70U)
#define AIPS_PACRF_AC6_SHIFT                     (4U)
/*! AC6 - Attribute Check */
#define AIPS_PACRF_AC6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRF_AC6_SHIFT)) & AIPS_PACRF_AC6_MASK)

#define AIPS_PACRF_RO6_MASK                      (0x80U)
#define AIPS_PACRF_RO6_SHIFT                     (7U)
/*! RO6 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRF_RO6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRF_RO6_SHIFT)) & AIPS_PACRF_RO6_MASK)

#define AIPS_PACRF_AC5_MASK                      (0x700U)
#define AIPS_PACRF_AC5_SHIFT                     (8U)
/*! AC5 - Attribute Check */
#define AIPS_PACRF_AC5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRF_AC5_SHIFT)) & AIPS_PACRF_AC5_MASK)

#define AIPS_PACRF_RO5_MASK                      (0x800U)
#define AIPS_PACRF_RO5_SHIFT                     (11U)
/*! RO5 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRF_RO5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRF_RO5_SHIFT)) & AIPS_PACRF_RO5_MASK)

#define AIPS_PACRF_AC4_MASK                      (0x7000U)
#define AIPS_PACRF_AC4_SHIFT                     (12U)
/*! AC4 - Attribute Check */
#define AIPS_PACRF_AC4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRF_AC4_SHIFT)) & AIPS_PACRF_AC4_MASK)

#define AIPS_PACRF_RO4_MASK                      (0x8000U)
#define AIPS_PACRF_RO4_SHIFT                     (15U)
/*! RO4 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRF_RO4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRF_RO4_SHIFT)) & AIPS_PACRF_RO4_MASK)

#define AIPS_PACRF_AC3_MASK                      (0x70000U)
#define AIPS_PACRF_AC3_SHIFT                     (16U)
/*! AC3 - Attribute Check */
#define AIPS_PACRF_AC3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRF_AC3_SHIFT)) & AIPS_PACRF_AC3_MASK)

#define AIPS_PACRF_RO3_MASK                      (0x80000U)
#define AIPS_PACRF_RO3_SHIFT                     (19U)
/*! RO3 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRF_RO3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRF_RO3_SHIFT)) & AIPS_PACRF_RO3_MASK)

#define AIPS_PACRF_AC2_MASK                      (0x700000U)
#define AIPS_PACRF_AC2_SHIFT                     (20U)
/*! AC2 - Attribute Check */
#define AIPS_PACRF_AC2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRF_AC2_SHIFT)) & AIPS_PACRF_AC2_MASK)

#define AIPS_PACRF_RO2_MASK                      (0x800000U)
#define AIPS_PACRF_RO2_SHIFT                     (23U)
/*! RO2 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRF_RO2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRF_RO2_SHIFT)) & AIPS_PACRF_RO2_MASK)

#define AIPS_PACRF_AC1_MASK                      (0x7000000U)
#define AIPS_PACRF_AC1_SHIFT                     (24U)
/*! AC1 - Attribute Check */
#define AIPS_PACRF_AC1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRF_AC1_SHIFT)) & AIPS_PACRF_AC1_MASK)

#define AIPS_PACRF_RO1_MASK                      (0x8000000U)
#define AIPS_PACRF_RO1_SHIFT                     (27U)
/*! RO1 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRF_RO1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRF_RO1_SHIFT)) & AIPS_PACRF_RO1_MASK)

#define AIPS_PACRF_AC0_MASK                      (0x70000000U)
#define AIPS_PACRF_AC0_SHIFT                     (28U)
/*! AC0 - Attribute Check */
#define AIPS_PACRF_AC0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRF_AC0_SHIFT)) & AIPS_PACRF_AC0_MASK)

#define AIPS_PACRF_RO0_MASK                      (0x80000000U)
#define AIPS_PACRF_RO0_SHIFT                     (31U)
/*! RO0 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRF_RO0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRF_RO0_SHIFT)) & AIPS_PACRF_RO0_MASK)
/*! @} */

/*! @name PACRG - Peripheral Access Control Register */
/*! @{ */

#define AIPS_PACRG_AC7_MASK                      (0x7U)
#define AIPS_PACRG_AC7_SHIFT                     (0U)
/*! AC7 - Attribute Check */
#define AIPS_PACRG_AC7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRG_AC7_SHIFT)) & AIPS_PACRG_AC7_MASK)

#define AIPS_PACRG_RO7_MASK                      (0x8U)
#define AIPS_PACRG_RO7_SHIFT                     (3U)
/*! RO7 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRG_RO7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRG_RO7_SHIFT)) & AIPS_PACRG_RO7_MASK)

#define AIPS_PACRG_AC6_MASK                      (0x70U)
#define AIPS_PACRG_AC6_SHIFT                     (4U)
/*! AC6 - Attribute Check */
#define AIPS_PACRG_AC6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRG_AC6_SHIFT)) & AIPS_PACRG_AC6_MASK)

#define AIPS_PACRG_RO6_MASK                      (0x80U)
#define AIPS_PACRG_RO6_SHIFT                     (7U)
/*! RO6 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRG_RO6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRG_RO6_SHIFT)) & AIPS_PACRG_RO6_MASK)

#define AIPS_PACRG_AC5_MASK                      (0x700U)
#define AIPS_PACRG_AC5_SHIFT                     (8U)
/*! AC5 - Attribute Check */
#define AIPS_PACRG_AC5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRG_AC5_SHIFT)) & AIPS_PACRG_AC5_MASK)

#define AIPS_PACRG_RO5_MASK                      (0x800U)
#define AIPS_PACRG_RO5_SHIFT                     (11U)
/*! RO5 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRG_RO5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRG_RO5_SHIFT)) & AIPS_PACRG_RO5_MASK)

#define AIPS_PACRG_AC4_MASK                      (0x7000U)
#define AIPS_PACRG_AC4_SHIFT                     (12U)
/*! AC4 - Attribute Check */
#define AIPS_PACRG_AC4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRG_AC4_SHIFT)) & AIPS_PACRG_AC4_MASK)

#define AIPS_PACRG_RO4_MASK                      (0x8000U)
#define AIPS_PACRG_RO4_SHIFT                     (15U)
/*! RO4 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRG_RO4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRG_RO4_SHIFT)) & AIPS_PACRG_RO4_MASK)

#define AIPS_PACRG_AC3_MASK                      (0x70000U)
#define AIPS_PACRG_AC3_SHIFT                     (16U)
/*! AC3 - Attribute Check */
#define AIPS_PACRG_AC3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRG_AC3_SHIFT)) & AIPS_PACRG_AC3_MASK)

#define AIPS_PACRG_RO3_MASK                      (0x80000U)
#define AIPS_PACRG_RO3_SHIFT                     (19U)
/*! RO3 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRG_RO3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRG_RO3_SHIFT)) & AIPS_PACRG_RO3_MASK)

#define AIPS_PACRG_AC2_MASK                      (0x700000U)
#define AIPS_PACRG_AC2_SHIFT                     (20U)
/*! AC2 - Attribute Check */
#define AIPS_PACRG_AC2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRG_AC2_SHIFT)) & AIPS_PACRG_AC2_MASK)

#define AIPS_PACRG_RO2_MASK                      (0x800000U)
#define AIPS_PACRG_RO2_SHIFT                     (23U)
/*! RO2 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRG_RO2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRG_RO2_SHIFT)) & AIPS_PACRG_RO2_MASK)

#define AIPS_PACRG_AC1_MASK                      (0x7000000U)
#define AIPS_PACRG_AC1_SHIFT                     (24U)
/*! AC1 - Attribute Check */
#define AIPS_PACRG_AC1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRG_AC1_SHIFT)) & AIPS_PACRG_AC1_MASK)

#define AIPS_PACRG_RO1_MASK                      (0x8000000U)
#define AIPS_PACRG_RO1_SHIFT                     (27U)
/*! RO1 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRG_RO1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRG_RO1_SHIFT)) & AIPS_PACRG_RO1_MASK)

#define AIPS_PACRG_AC0_MASK                      (0x70000000U)
#define AIPS_PACRG_AC0_SHIFT                     (28U)
/*! AC0 - Attribute Check */
#define AIPS_PACRG_AC0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRG_AC0_SHIFT)) & AIPS_PACRG_AC0_MASK)

#define AIPS_PACRG_RO0_MASK                      (0x80000000U)
#define AIPS_PACRG_RO0_SHIFT                     (31U)
/*! RO0 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRG_RO0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRG_RO0_SHIFT)) & AIPS_PACRG_RO0_MASK)
/*! @} */

/*! @name PACRH - Peripheral Access Control Register */
/*! @{ */

#define AIPS_PACRH_AC7_MASK                      (0x7U)
#define AIPS_PACRH_AC7_SHIFT                     (0U)
/*! AC7 - Attribute Check */
#define AIPS_PACRH_AC7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRH_AC7_SHIFT)) & AIPS_PACRH_AC7_MASK)

#define AIPS_PACRH_RO7_MASK                      (0x8U)
#define AIPS_PACRH_RO7_SHIFT                     (3U)
/*! RO7 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRH_RO7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRH_RO7_SHIFT)) & AIPS_PACRH_RO7_MASK)

#define AIPS_PACRH_AC6_MASK                      (0x70U)
#define AIPS_PACRH_AC6_SHIFT                     (4U)
/*! AC6 - Attribute Check */
#define AIPS_PACRH_AC6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRH_AC6_SHIFT)) & AIPS_PACRH_AC6_MASK)

#define AIPS_PACRH_RO6_MASK                      (0x80U)
#define AIPS_PACRH_RO6_SHIFT                     (7U)
/*! RO6 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRH_RO6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRH_RO6_SHIFT)) & AIPS_PACRH_RO6_MASK)

#define AIPS_PACRH_AC5_MASK                      (0x700U)
#define AIPS_PACRH_AC5_SHIFT                     (8U)
/*! AC5 - Attribute Check */
#define AIPS_PACRH_AC5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRH_AC5_SHIFT)) & AIPS_PACRH_AC5_MASK)

#define AIPS_PACRH_RO5_MASK                      (0x800U)
#define AIPS_PACRH_RO5_SHIFT                     (11U)
/*! RO5 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRH_RO5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRH_RO5_SHIFT)) & AIPS_PACRH_RO5_MASK)

#define AIPS_PACRH_AC4_MASK                      (0x7000U)
#define AIPS_PACRH_AC4_SHIFT                     (12U)
/*! AC4 - Attribute Check */
#define AIPS_PACRH_AC4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRH_AC4_SHIFT)) & AIPS_PACRH_AC4_MASK)

#define AIPS_PACRH_RO4_MASK                      (0x8000U)
#define AIPS_PACRH_RO4_SHIFT                     (15U)
/*! RO4 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRH_RO4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRH_RO4_SHIFT)) & AIPS_PACRH_RO4_MASK)

#define AIPS_PACRH_AC3_MASK                      (0x70000U)
#define AIPS_PACRH_AC3_SHIFT                     (16U)
/*! AC3 - Attribute Check */
#define AIPS_PACRH_AC3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRH_AC3_SHIFT)) & AIPS_PACRH_AC3_MASK)

#define AIPS_PACRH_RO3_MASK                      (0x80000U)
#define AIPS_PACRH_RO3_SHIFT                     (19U)
/*! RO3 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRH_RO3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRH_RO3_SHIFT)) & AIPS_PACRH_RO3_MASK)

#define AIPS_PACRH_AC2_MASK                      (0x700000U)
#define AIPS_PACRH_AC2_SHIFT                     (20U)
/*! AC2 - Attribute Check */
#define AIPS_PACRH_AC2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRH_AC2_SHIFT)) & AIPS_PACRH_AC2_MASK)

#define AIPS_PACRH_RO2_MASK                      (0x800000U)
#define AIPS_PACRH_RO2_SHIFT                     (23U)
/*! RO2 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRH_RO2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRH_RO2_SHIFT)) & AIPS_PACRH_RO2_MASK)

#define AIPS_PACRH_AC1_MASK                      (0x7000000U)
#define AIPS_PACRH_AC1_SHIFT                     (24U)
/*! AC1 - Attribute Check */
#define AIPS_PACRH_AC1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRH_AC1_SHIFT)) & AIPS_PACRH_AC1_MASK)

#define AIPS_PACRH_RO1_MASK                      (0x8000000U)
#define AIPS_PACRH_RO1_SHIFT                     (27U)
/*! RO1 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRH_RO1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRH_RO1_SHIFT)) & AIPS_PACRH_RO1_MASK)

#define AIPS_PACRH_AC0_MASK                      (0x70000000U)
#define AIPS_PACRH_AC0_SHIFT                     (28U)
/*! AC0 - Attribute Check */
#define AIPS_PACRH_AC0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRH_AC0_SHIFT)) & AIPS_PACRH_AC0_MASK)

#define AIPS_PACRH_RO0_MASK                      (0x80000000U)
#define AIPS_PACRH_RO0_SHIFT                     (31U)
/*! RO0 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRH_RO0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRH_RO0_SHIFT)) & AIPS_PACRH_RO0_MASK)
/*! @} */

/*! @name PACRI - Peripheral Access Control Register */
/*! @{ */

#define AIPS_PACRI_AC7_MASK                      (0x7U)
#define AIPS_PACRI_AC7_SHIFT                     (0U)
/*! AC7 - Attribute Check */
#define AIPS_PACRI_AC7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRI_AC7_SHIFT)) & AIPS_PACRI_AC7_MASK)

#define AIPS_PACRI_RO7_MASK                      (0x8U)
#define AIPS_PACRI_RO7_SHIFT                     (3U)
/*! RO7 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRI_RO7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRI_RO7_SHIFT)) & AIPS_PACRI_RO7_MASK)

#define AIPS_PACRI_AC6_MASK                      (0x70U)
#define AIPS_PACRI_AC6_SHIFT                     (4U)
/*! AC6 - Attribute Check */
#define AIPS_PACRI_AC6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRI_AC6_SHIFT)) & AIPS_PACRI_AC6_MASK)

#define AIPS_PACRI_RO6_MASK                      (0x80U)
#define AIPS_PACRI_RO6_SHIFT                     (7U)
/*! RO6 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRI_RO6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRI_RO6_SHIFT)) & AIPS_PACRI_RO6_MASK)

#define AIPS_PACRI_AC5_MASK                      (0x700U)
#define AIPS_PACRI_AC5_SHIFT                     (8U)
/*! AC5 - Attribute Check */
#define AIPS_PACRI_AC5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRI_AC5_SHIFT)) & AIPS_PACRI_AC5_MASK)

#define AIPS_PACRI_RO5_MASK                      (0x800U)
#define AIPS_PACRI_RO5_SHIFT                     (11U)
/*! RO5 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRI_RO5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRI_RO5_SHIFT)) & AIPS_PACRI_RO5_MASK)

#define AIPS_PACRI_AC4_MASK                      (0x7000U)
#define AIPS_PACRI_AC4_SHIFT                     (12U)
/*! AC4 - Attribute Check */
#define AIPS_PACRI_AC4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRI_AC4_SHIFT)) & AIPS_PACRI_AC4_MASK)

#define AIPS_PACRI_RO4_MASK                      (0x8000U)
#define AIPS_PACRI_RO4_SHIFT                     (15U)
/*! RO4 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRI_RO4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRI_RO4_SHIFT)) & AIPS_PACRI_RO4_MASK)

#define AIPS_PACRI_AC3_MASK                      (0x70000U)
#define AIPS_PACRI_AC3_SHIFT                     (16U)
/*! AC3 - Attribute Check */
#define AIPS_PACRI_AC3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRI_AC3_SHIFT)) & AIPS_PACRI_AC3_MASK)

#define AIPS_PACRI_RO3_MASK                      (0x80000U)
#define AIPS_PACRI_RO3_SHIFT                     (19U)
/*! RO3 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRI_RO3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRI_RO3_SHIFT)) & AIPS_PACRI_RO3_MASK)

#define AIPS_PACRI_AC2_MASK                      (0x700000U)
#define AIPS_PACRI_AC2_SHIFT                     (20U)
/*! AC2 - Attribute Check */
#define AIPS_PACRI_AC2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRI_AC2_SHIFT)) & AIPS_PACRI_AC2_MASK)

#define AIPS_PACRI_RO2_MASK                      (0x800000U)
#define AIPS_PACRI_RO2_SHIFT                     (23U)
/*! RO2 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRI_RO2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRI_RO2_SHIFT)) & AIPS_PACRI_RO2_MASK)

#define AIPS_PACRI_AC1_MASK                      (0x7000000U)
#define AIPS_PACRI_AC1_SHIFT                     (24U)
/*! AC1 - Attribute Check */
#define AIPS_PACRI_AC1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRI_AC1_SHIFT)) & AIPS_PACRI_AC1_MASK)

#define AIPS_PACRI_RO1_MASK                      (0x8000000U)
#define AIPS_PACRI_RO1_SHIFT                     (27U)
/*! RO1 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRI_RO1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRI_RO1_SHIFT)) & AIPS_PACRI_RO1_MASK)

#define AIPS_PACRI_AC0_MASK                      (0x70000000U)
#define AIPS_PACRI_AC0_SHIFT                     (28U)
/*! AC0 - Attribute Check */
#define AIPS_PACRI_AC0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRI_AC0_SHIFT)) & AIPS_PACRI_AC0_MASK)

#define AIPS_PACRI_RO0_MASK                      (0x80000000U)
#define AIPS_PACRI_RO0_SHIFT                     (31U)
/*! RO0 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRI_RO0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRI_RO0_SHIFT)) & AIPS_PACRI_RO0_MASK)
/*! @} */

/*! @name PACRJ - Peripheral Access Control Register */
/*! @{ */

#define AIPS_PACRJ_AC7_MASK                      (0x7U)
#define AIPS_PACRJ_AC7_SHIFT                     (0U)
/*! AC7 - Attribute Check */
#define AIPS_PACRJ_AC7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRJ_AC7_SHIFT)) & AIPS_PACRJ_AC7_MASK)

#define AIPS_PACRJ_RO7_MASK                      (0x8U)
#define AIPS_PACRJ_RO7_SHIFT                     (3U)
/*! RO7 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRJ_RO7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRJ_RO7_SHIFT)) & AIPS_PACRJ_RO7_MASK)

#define AIPS_PACRJ_AC6_MASK                      (0x70U)
#define AIPS_PACRJ_AC6_SHIFT                     (4U)
/*! AC6 - Attribute Check */
#define AIPS_PACRJ_AC6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRJ_AC6_SHIFT)) & AIPS_PACRJ_AC6_MASK)

#define AIPS_PACRJ_RO6_MASK                      (0x80U)
#define AIPS_PACRJ_RO6_SHIFT                     (7U)
/*! RO6 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRJ_RO6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRJ_RO6_SHIFT)) & AIPS_PACRJ_RO6_MASK)

#define AIPS_PACRJ_AC5_MASK                      (0x700U)
#define AIPS_PACRJ_AC5_SHIFT                     (8U)
/*! AC5 - Attribute Check */
#define AIPS_PACRJ_AC5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRJ_AC5_SHIFT)) & AIPS_PACRJ_AC5_MASK)

#define AIPS_PACRJ_RO5_MASK                      (0x800U)
#define AIPS_PACRJ_RO5_SHIFT                     (11U)
/*! RO5 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRJ_RO5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRJ_RO5_SHIFT)) & AIPS_PACRJ_RO5_MASK)

#define AIPS_PACRJ_AC4_MASK                      (0x7000U)
#define AIPS_PACRJ_AC4_SHIFT                     (12U)
/*! AC4 - Attribute Check */
#define AIPS_PACRJ_AC4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRJ_AC4_SHIFT)) & AIPS_PACRJ_AC4_MASK)

#define AIPS_PACRJ_RO4_MASK                      (0x8000U)
#define AIPS_PACRJ_RO4_SHIFT                     (15U)
/*! RO4 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRJ_RO4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRJ_RO4_SHIFT)) & AIPS_PACRJ_RO4_MASK)

#define AIPS_PACRJ_AC3_MASK                      (0x70000U)
#define AIPS_PACRJ_AC3_SHIFT                     (16U)
/*! AC3 - Attribute Check */
#define AIPS_PACRJ_AC3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRJ_AC3_SHIFT)) & AIPS_PACRJ_AC3_MASK)

#define AIPS_PACRJ_RO3_MASK                      (0x80000U)
#define AIPS_PACRJ_RO3_SHIFT                     (19U)
/*! RO3 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRJ_RO3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRJ_RO3_SHIFT)) & AIPS_PACRJ_RO3_MASK)

#define AIPS_PACRJ_AC2_MASK                      (0x700000U)
#define AIPS_PACRJ_AC2_SHIFT                     (20U)
/*! AC2 - Attribute Check */
#define AIPS_PACRJ_AC2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRJ_AC2_SHIFT)) & AIPS_PACRJ_AC2_MASK)

#define AIPS_PACRJ_RO2_MASK                      (0x800000U)
#define AIPS_PACRJ_RO2_SHIFT                     (23U)
/*! RO2 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRJ_RO2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRJ_RO2_SHIFT)) & AIPS_PACRJ_RO2_MASK)

#define AIPS_PACRJ_AC1_MASK                      (0x7000000U)
#define AIPS_PACRJ_AC1_SHIFT                     (24U)
/*! AC1 - Attribute Check */
#define AIPS_PACRJ_AC1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRJ_AC1_SHIFT)) & AIPS_PACRJ_AC1_MASK)

#define AIPS_PACRJ_RO1_MASK                      (0x8000000U)
#define AIPS_PACRJ_RO1_SHIFT                     (27U)
/*! RO1 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRJ_RO1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRJ_RO1_SHIFT)) & AIPS_PACRJ_RO1_MASK)

#define AIPS_PACRJ_AC0_MASK                      (0x70000000U)
#define AIPS_PACRJ_AC0_SHIFT                     (28U)
/*! AC0 - Attribute Check */
#define AIPS_PACRJ_AC0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRJ_AC0_SHIFT)) & AIPS_PACRJ_AC0_MASK)

#define AIPS_PACRJ_RO0_MASK                      (0x80000000U)
#define AIPS_PACRJ_RO0_SHIFT                     (31U)
/*! RO0 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRJ_RO0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRJ_RO0_SHIFT)) & AIPS_PACRJ_RO0_MASK)
/*! @} */

/*! @name PACRK - Peripheral Access Control Register */
/*! @{ */

#define AIPS_PACRK_AC7_MASK                      (0x7U)
#define AIPS_PACRK_AC7_SHIFT                     (0U)
/*! AC7 - Attribute Check */
#define AIPS_PACRK_AC7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRK_AC7_SHIFT)) & AIPS_PACRK_AC7_MASK)

#define AIPS_PACRK_RO7_MASK                      (0x8U)
#define AIPS_PACRK_RO7_SHIFT                     (3U)
/*! RO7 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRK_RO7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRK_RO7_SHIFT)) & AIPS_PACRK_RO7_MASK)

#define AIPS_PACRK_AC6_MASK                      (0x70U)
#define AIPS_PACRK_AC6_SHIFT                     (4U)
/*! AC6 - Attribute Check */
#define AIPS_PACRK_AC6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRK_AC6_SHIFT)) & AIPS_PACRK_AC6_MASK)

#define AIPS_PACRK_RO6_MASK                      (0x80U)
#define AIPS_PACRK_RO6_SHIFT                     (7U)
/*! RO6 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRK_RO6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRK_RO6_SHIFT)) & AIPS_PACRK_RO6_MASK)

#define AIPS_PACRK_AC5_MASK                      (0x700U)
#define AIPS_PACRK_AC5_SHIFT                     (8U)
/*! AC5 - Attribute Check */
#define AIPS_PACRK_AC5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRK_AC5_SHIFT)) & AIPS_PACRK_AC5_MASK)

#define AIPS_PACRK_RO5_MASK                      (0x800U)
#define AIPS_PACRK_RO5_SHIFT                     (11U)
/*! RO5 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRK_RO5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRK_RO5_SHIFT)) & AIPS_PACRK_RO5_MASK)

#define AIPS_PACRK_AC4_MASK                      (0x7000U)
#define AIPS_PACRK_AC4_SHIFT                     (12U)
/*! AC4 - Attribute Check */
#define AIPS_PACRK_AC4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRK_AC4_SHIFT)) & AIPS_PACRK_AC4_MASK)

#define AIPS_PACRK_RO4_MASK                      (0x8000U)
#define AIPS_PACRK_RO4_SHIFT                     (15U)
/*! RO4 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRK_RO4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRK_RO4_SHIFT)) & AIPS_PACRK_RO4_MASK)

#define AIPS_PACRK_AC3_MASK                      (0x70000U)
#define AIPS_PACRK_AC3_SHIFT                     (16U)
/*! AC3 - Attribute Check */
#define AIPS_PACRK_AC3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRK_AC3_SHIFT)) & AIPS_PACRK_AC3_MASK)

#define AIPS_PACRK_RO3_MASK                      (0x80000U)
#define AIPS_PACRK_RO3_SHIFT                     (19U)
/*! RO3 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRK_RO3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRK_RO3_SHIFT)) & AIPS_PACRK_RO3_MASK)

#define AIPS_PACRK_AC2_MASK                      (0x700000U)
#define AIPS_PACRK_AC2_SHIFT                     (20U)
/*! AC2 - Attribute Check */
#define AIPS_PACRK_AC2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRK_AC2_SHIFT)) & AIPS_PACRK_AC2_MASK)

#define AIPS_PACRK_RO2_MASK                      (0x800000U)
#define AIPS_PACRK_RO2_SHIFT                     (23U)
/*! RO2 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRK_RO2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRK_RO2_SHIFT)) & AIPS_PACRK_RO2_MASK)

#define AIPS_PACRK_AC1_MASK                      (0x7000000U)
#define AIPS_PACRK_AC1_SHIFT                     (24U)
/*! AC1 - Attribute Check */
#define AIPS_PACRK_AC1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRK_AC1_SHIFT)) & AIPS_PACRK_AC1_MASK)

#define AIPS_PACRK_RO1_MASK                      (0x8000000U)
#define AIPS_PACRK_RO1_SHIFT                     (27U)
/*! RO1 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRK_RO1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRK_RO1_SHIFT)) & AIPS_PACRK_RO1_MASK)

#define AIPS_PACRK_AC0_MASK                      (0x70000000U)
#define AIPS_PACRK_AC0_SHIFT                     (28U)
/*! AC0 - Attribute Check */
#define AIPS_PACRK_AC0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRK_AC0_SHIFT)) & AIPS_PACRK_AC0_MASK)

#define AIPS_PACRK_RO0_MASK                      (0x80000000U)
#define AIPS_PACRK_RO0_SHIFT                     (31U)
/*! RO0 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRK_RO0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRK_RO0_SHIFT)) & AIPS_PACRK_RO0_MASK)
/*! @} */

/*! @name PACRL - Peripheral Access Control Register */
/*! @{ */

#define AIPS_PACRL_AC7_MASK                      (0x7U)
#define AIPS_PACRL_AC7_SHIFT                     (0U)
/*! AC7 - Attribute Check */
#define AIPS_PACRL_AC7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRL_AC7_SHIFT)) & AIPS_PACRL_AC7_MASK)

#define AIPS_PACRL_RO7_MASK                      (0x8U)
#define AIPS_PACRL_RO7_SHIFT                     (3U)
/*! RO7 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRL_RO7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRL_RO7_SHIFT)) & AIPS_PACRL_RO7_MASK)

#define AIPS_PACRL_AC6_MASK                      (0x70U)
#define AIPS_PACRL_AC6_SHIFT                     (4U)
/*! AC6 - Attribute Check */
#define AIPS_PACRL_AC6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRL_AC6_SHIFT)) & AIPS_PACRL_AC6_MASK)

#define AIPS_PACRL_RO6_MASK                      (0x80U)
#define AIPS_PACRL_RO6_SHIFT                     (7U)
/*! RO6 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRL_RO6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRL_RO6_SHIFT)) & AIPS_PACRL_RO6_MASK)

#define AIPS_PACRL_AC5_MASK                      (0x700U)
#define AIPS_PACRL_AC5_SHIFT                     (8U)
/*! AC5 - Attribute Check */
#define AIPS_PACRL_AC5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRL_AC5_SHIFT)) & AIPS_PACRL_AC5_MASK)

#define AIPS_PACRL_RO5_MASK                      (0x800U)
#define AIPS_PACRL_RO5_SHIFT                     (11U)
/*! RO5 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRL_RO5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRL_RO5_SHIFT)) & AIPS_PACRL_RO5_MASK)

#define AIPS_PACRL_AC4_MASK                      (0x7000U)
#define AIPS_PACRL_AC4_SHIFT                     (12U)
/*! AC4 - Attribute Check */
#define AIPS_PACRL_AC4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRL_AC4_SHIFT)) & AIPS_PACRL_AC4_MASK)

#define AIPS_PACRL_RO4_MASK                      (0x8000U)
#define AIPS_PACRL_RO4_SHIFT                     (15U)
/*! RO4 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRL_RO4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRL_RO4_SHIFT)) & AIPS_PACRL_RO4_MASK)

#define AIPS_PACRL_AC3_MASK                      (0x70000U)
#define AIPS_PACRL_AC3_SHIFT                     (16U)
/*! AC3 - Attribute Check */
#define AIPS_PACRL_AC3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRL_AC3_SHIFT)) & AIPS_PACRL_AC3_MASK)

#define AIPS_PACRL_RO3_MASK                      (0x80000U)
#define AIPS_PACRL_RO3_SHIFT                     (19U)
/*! RO3 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRL_RO3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRL_RO3_SHIFT)) & AIPS_PACRL_RO3_MASK)

#define AIPS_PACRL_AC2_MASK                      (0x700000U)
#define AIPS_PACRL_AC2_SHIFT                     (20U)
/*! AC2 - Attribute Check */
#define AIPS_PACRL_AC2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRL_AC2_SHIFT)) & AIPS_PACRL_AC2_MASK)

#define AIPS_PACRL_RO2_MASK                      (0x800000U)
#define AIPS_PACRL_RO2_SHIFT                     (23U)
/*! RO2 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRL_RO2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRL_RO2_SHIFT)) & AIPS_PACRL_RO2_MASK)

#define AIPS_PACRL_AC1_MASK                      (0x7000000U)
#define AIPS_PACRL_AC1_SHIFT                     (24U)
/*! AC1 - Attribute Check */
#define AIPS_PACRL_AC1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRL_AC1_SHIFT)) & AIPS_PACRL_AC1_MASK)

#define AIPS_PACRL_RO1_MASK                      (0x8000000U)
#define AIPS_PACRL_RO1_SHIFT                     (27U)
/*! RO1 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRL_RO1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRL_RO1_SHIFT)) & AIPS_PACRL_RO1_MASK)

#define AIPS_PACRL_AC0_MASK                      (0x70000000U)
#define AIPS_PACRL_AC0_SHIFT                     (28U)
/*! AC0 - Attribute Check */
#define AIPS_PACRL_AC0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRL_AC0_SHIFT)) & AIPS_PACRL_AC0_MASK)

#define AIPS_PACRL_RO0_MASK                      (0x80000000U)
#define AIPS_PACRL_RO0_SHIFT                     (31U)
/*! RO0 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRL_RO0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRL_RO0_SHIFT)) & AIPS_PACRL_RO0_MASK)
/*! @} */

/*! @name PACRM - Peripheral Access Control Register */
/*! @{ */

#define AIPS_PACRM_AC7_MASK                      (0x7U)
#define AIPS_PACRM_AC7_SHIFT                     (0U)
/*! AC7 - Attribute Check */
#define AIPS_PACRM_AC7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRM_AC7_SHIFT)) & AIPS_PACRM_AC7_MASK)

#define AIPS_PACRM_RO7_MASK                      (0x8U)
#define AIPS_PACRM_RO7_SHIFT                     (3U)
/*! RO7 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRM_RO7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRM_RO7_SHIFT)) & AIPS_PACRM_RO7_MASK)

#define AIPS_PACRM_AC6_MASK                      (0x70U)
#define AIPS_PACRM_AC6_SHIFT                     (4U)
/*! AC6 - Attribute Check */
#define AIPS_PACRM_AC6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRM_AC6_SHIFT)) & AIPS_PACRM_AC6_MASK)

#define AIPS_PACRM_RO6_MASK                      (0x80U)
#define AIPS_PACRM_RO6_SHIFT                     (7U)
/*! RO6 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRM_RO6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRM_RO6_SHIFT)) & AIPS_PACRM_RO6_MASK)

#define AIPS_PACRM_AC5_MASK                      (0x700U)
#define AIPS_PACRM_AC5_SHIFT                     (8U)
/*! AC5 - Attribute Check */
#define AIPS_PACRM_AC5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRM_AC5_SHIFT)) & AIPS_PACRM_AC5_MASK)

#define AIPS_PACRM_RO5_MASK                      (0x800U)
#define AIPS_PACRM_RO5_SHIFT                     (11U)
/*! RO5 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRM_RO5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRM_RO5_SHIFT)) & AIPS_PACRM_RO5_MASK)

#define AIPS_PACRM_AC4_MASK                      (0x7000U)
#define AIPS_PACRM_AC4_SHIFT                     (12U)
/*! AC4 - Attribute Check */
#define AIPS_PACRM_AC4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRM_AC4_SHIFT)) & AIPS_PACRM_AC4_MASK)

#define AIPS_PACRM_RO4_MASK                      (0x8000U)
#define AIPS_PACRM_RO4_SHIFT                     (15U)
/*! RO4 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRM_RO4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRM_RO4_SHIFT)) & AIPS_PACRM_RO4_MASK)

#define AIPS_PACRM_AC3_MASK                      (0x70000U)
#define AIPS_PACRM_AC3_SHIFT                     (16U)
/*! AC3 - Attribute Check */
#define AIPS_PACRM_AC3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRM_AC3_SHIFT)) & AIPS_PACRM_AC3_MASK)

#define AIPS_PACRM_RO3_MASK                      (0x80000U)
#define AIPS_PACRM_RO3_SHIFT                     (19U)
/*! RO3 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRM_RO3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRM_RO3_SHIFT)) & AIPS_PACRM_RO3_MASK)

#define AIPS_PACRM_AC2_MASK                      (0x700000U)
#define AIPS_PACRM_AC2_SHIFT                     (20U)
/*! AC2 - Attribute Check */
#define AIPS_PACRM_AC2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRM_AC2_SHIFT)) & AIPS_PACRM_AC2_MASK)

#define AIPS_PACRM_RO2_MASK                      (0x800000U)
#define AIPS_PACRM_RO2_SHIFT                     (23U)
/*! RO2 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRM_RO2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRM_RO2_SHIFT)) & AIPS_PACRM_RO2_MASK)

#define AIPS_PACRM_AC1_MASK                      (0x7000000U)
#define AIPS_PACRM_AC1_SHIFT                     (24U)
/*! AC1 - Attribute Check */
#define AIPS_PACRM_AC1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRM_AC1_SHIFT)) & AIPS_PACRM_AC1_MASK)

#define AIPS_PACRM_RO1_MASK                      (0x8000000U)
#define AIPS_PACRM_RO1_SHIFT                     (27U)
/*! RO1 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRM_RO1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRM_RO1_SHIFT)) & AIPS_PACRM_RO1_MASK)

#define AIPS_PACRM_AC0_MASK                      (0x70000000U)
#define AIPS_PACRM_AC0_SHIFT                     (28U)
/*! AC0 - Attribute Check */
#define AIPS_PACRM_AC0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRM_AC0_SHIFT)) & AIPS_PACRM_AC0_MASK)

#define AIPS_PACRM_RO0_MASK                      (0x80000000U)
#define AIPS_PACRM_RO0_SHIFT                     (31U)
/*! RO0 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRM_RO0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRM_RO0_SHIFT)) & AIPS_PACRM_RO0_MASK)
/*! @} */

/*! @name PACRN - Peripheral Access Control Register */
/*! @{ */

#define AIPS_PACRN_AC7_MASK                      (0x7U)
#define AIPS_PACRN_AC7_SHIFT                     (0U)
/*! AC7 - Attribute Check */
#define AIPS_PACRN_AC7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRN_AC7_SHIFT)) & AIPS_PACRN_AC7_MASK)

#define AIPS_PACRN_RO7_MASK                      (0x8U)
#define AIPS_PACRN_RO7_SHIFT                     (3U)
/*! RO7 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRN_RO7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRN_RO7_SHIFT)) & AIPS_PACRN_RO7_MASK)

#define AIPS_PACRN_AC6_MASK                      (0x70U)
#define AIPS_PACRN_AC6_SHIFT                     (4U)
/*! AC6 - Attribute Check */
#define AIPS_PACRN_AC6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRN_AC6_SHIFT)) & AIPS_PACRN_AC6_MASK)

#define AIPS_PACRN_RO6_MASK                      (0x80U)
#define AIPS_PACRN_RO6_SHIFT                     (7U)
/*! RO6 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRN_RO6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRN_RO6_SHIFT)) & AIPS_PACRN_RO6_MASK)

#define AIPS_PACRN_AC5_MASK                      (0x700U)
#define AIPS_PACRN_AC5_SHIFT                     (8U)
/*! AC5 - Attribute Check */
#define AIPS_PACRN_AC5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRN_AC5_SHIFT)) & AIPS_PACRN_AC5_MASK)

#define AIPS_PACRN_RO5_MASK                      (0x800U)
#define AIPS_PACRN_RO5_SHIFT                     (11U)
/*! RO5 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRN_RO5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRN_RO5_SHIFT)) & AIPS_PACRN_RO5_MASK)

#define AIPS_PACRN_AC4_MASK                      (0x7000U)
#define AIPS_PACRN_AC4_SHIFT                     (12U)
/*! AC4 - Attribute Check */
#define AIPS_PACRN_AC4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRN_AC4_SHIFT)) & AIPS_PACRN_AC4_MASK)

#define AIPS_PACRN_RO4_MASK                      (0x8000U)
#define AIPS_PACRN_RO4_SHIFT                     (15U)
/*! RO4 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRN_RO4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRN_RO4_SHIFT)) & AIPS_PACRN_RO4_MASK)

#define AIPS_PACRN_AC3_MASK                      (0x70000U)
#define AIPS_PACRN_AC3_SHIFT                     (16U)
/*! AC3 - Attribute Check */
#define AIPS_PACRN_AC3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRN_AC3_SHIFT)) & AIPS_PACRN_AC3_MASK)

#define AIPS_PACRN_RO3_MASK                      (0x80000U)
#define AIPS_PACRN_RO3_SHIFT                     (19U)
/*! RO3 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRN_RO3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRN_RO3_SHIFT)) & AIPS_PACRN_RO3_MASK)

#define AIPS_PACRN_AC2_MASK                      (0x700000U)
#define AIPS_PACRN_AC2_SHIFT                     (20U)
/*! AC2 - Attribute Check */
#define AIPS_PACRN_AC2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRN_AC2_SHIFT)) & AIPS_PACRN_AC2_MASK)

#define AIPS_PACRN_RO2_MASK                      (0x800000U)
#define AIPS_PACRN_RO2_SHIFT                     (23U)
/*! RO2 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRN_RO2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRN_RO2_SHIFT)) & AIPS_PACRN_RO2_MASK)

#define AIPS_PACRN_AC1_MASK                      (0x7000000U)
#define AIPS_PACRN_AC1_SHIFT                     (24U)
/*! AC1 - Attribute Check */
#define AIPS_PACRN_AC1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRN_AC1_SHIFT)) & AIPS_PACRN_AC1_MASK)

#define AIPS_PACRN_RO1_MASK                      (0x8000000U)
#define AIPS_PACRN_RO1_SHIFT                     (27U)
/*! RO1 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRN_RO1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRN_RO1_SHIFT)) & AIPS_PACRN_RO1_MASK)

#define AIPS_PACRN_AC0_MASK                      (0x70000000U)
#define AIPS_PACRN_AC0_SHIFT                     (28U)
/*! AC0 - Attribute Check */
#define AIPS_PACRN_AC0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRN_AC0_SHIFT)) & AIPS_PACRN_AC0_MASK)

#define AIPS_PACRN_RO0_MASK                      (0x80000000U)
#define AIPS_PACRN_RO0_SHIFT                     (31U)
/*! RO0 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRN_RO0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRN_RO0_SHIFT)) & AIPS_PACRN_RO0_MASK)
/*! @} */

/*! @name PACRO - Peripheral Access Control Register */
/*! @{ */

#define AIPS_PACRO_AC7_MASK                      (0x7U)
#define AIPS_PACRO_AC7_SHIFT                     (0U)
/*! AC7 - Attribute Check */
#define AIPS_PACRO_AC7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRO_AC7_SHIFT)) & AIPS_PACRO_AC7_MASK)

#define AIPS_PACRO_RO7_MASK                      (0x8U)
#define AIPS_PACRO_RO7_SHIFT                     (3U)
/*! RO7 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRO_RO7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRO_RO7_SHIFT)) & AIPS_PACRO_RO7_MASK)

#define AIPS_PACRO_AC6_MASK                      (0x70U)
#define AIPS_PACRO_AC6_SHIFT                     (4U)
/*! AC6 - Attribute Check */
#define AIPS_PACRO_AC6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRO_AC6_SHIFT)) & AIPS_PACRO_AC6_MASK)

#define AIPS_PACRO_RO6_MASK                      (0x80U)
#define AIPS_PACRO_RO6_SHIFT                     (7U)
/*! RO6 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRO_RO6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRO_RO6_SHIFT)) & AIPS_PACRO_RO6_MASK)

#define AIPS_PACRO_AC5_MASK                      (0x700U)
#define AIPS_PACRO_AC5_SHIFT                     (8U)
/*! AC5 - Attribute Check */
#define AIPS_PACRO_AC5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRO_AC5_SHIFT)) & AIPS_PACRO_AC5_MASK)

#define AIPS_PACRO_RO5_MASK                      (0x800U)
#define AIPS_PACRO_RO5_SHIFT                     (11U)
/*! RO5 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRO_RO5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRO_RO5_SHIFT)) & AIPS_PACRO_RO5_MASK)

#define AIPS_PACRO_AC4_MASK                      (0x7000U)
#define AIPS_PACRO_AC4_SHIFT                     (12U)
/*! AC4 - Attribute Check */
#define AIPS_PACRO_AC4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRO_AC4_SHIFT)) & AIPS_PACRO_AC4_MASK)

#define AIPS_PACRO_RO4_MASK                      (0x8000U)
#define AIPS_PACRO_RO4_SHIFT                     (15U)
/*! RO4 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRO_RO4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRO_RO4_SHIFT)) & AIPS_PACRO_RO4_MASK)

#define AIPS_PACRO_AC3_MASK                      (0x70000U)
#define AIPS_PACRO_AC3_SHIFT                     (16U)
/*! AC3 - Attribute Check */
#define AIPS_PACRO_AC3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRO_AC3_SHIFT)) & AIPS_PACRO_AC3_MASK)

#define AIPS_PACRO_RO3_MASK                      (0x80000U)
#define AIPS_PACRO_RO3_SHIFT                     (19U)
/*! RO3 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRO_RO3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRO_RO3_SHIFT)) & AIPS_PACRO_RO3_MASK)

#define AIPS_PACRO_AC2_MASK                      (0x700000U)
#define AIPS_PACRO_AC2_SHIFT                     (20U)
/*! AC2 - Attribute Check */
#define AIPS_PACRO_AC2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRO_AC2_SHIFT)) & AIPS_PACRO_AC2_MASK)

#define AIPS_PACRO_RO2_MASK                      (0x800000U)
#define AIPS_PACRO_RO2_SHIFT                     (23U)
/*! RO2 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRO_RO2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRO_RO2_SHIFT)) & AIPS_PACRO_RO2_MASK)

#define AIPS_PACRO_AC1_MASK                      (0x7000000U)
#define AIPS_PACRO_AC1_SHIFT                     (24U)
/*! AC1 - Attribute Check */
#define AIPS_PACRO_AC1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRO_AC1_SHIFT)) & AIPS_PACRO_AC1_MASK)

#define AIPS_PACRO_RO1_MASK                      (0x8000000U)
#define AIPS_PACRO_RO1_SHIFT                     (27U)
/*! RO1 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRO_RO1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRO_RO1_SHIFT)) & AIPS_PACRO_RO1_MASK)

#define AIPS_PACRO_AC0_MASK                      (0x70000000U)
#define AIPS_PACRO_AC0_SHIFT                     (28U)
/*! AC0 - Attribute Check */
#define AIPS_PACRO_AC0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRO_AC0_SHIFT)) & AIPS_PACRO_AC0_MASK)

#define AIPS_PACRO_RO0_MASK                      (0x80000000U)
#define AIPS_PACRO_RO0_SHIFT                     (31U)
/*! RO0 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRO_RO0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRO_RO0_SHIFT)) & AIPS_PACRO_RO0_MASK)
/*! @} */

/*! @name PACRP - Peripheral Access Control Register */
/*! @{ */

#define AIPS_PACRP_AC7_MASK                      (0x7U)
#define AIPS_PACRP_AC7_SHIFT                     (0U)
/*! AC7 - Attribute Check */
#define AIPS_PACRP_AC7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRP_AC7_SHIFT)) & AIPS_PACRP_AC7_MASK)

#define AIPS_PACRP_RO7_MASK                      (0x8U)
#define AIPS_PACRP_RO7_SHIFT                     (3U)
/*! RO7 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRP_RO7(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRP_RO7_SHIFT)) & AIPS_PACRP_RO7_MASK)

#define AIPS_PACRP_AC6_MASK                      (0x70U)
#define AIPS_PACRP_AC6_SHIFT                     (4U)
/*! AC6 - Attribute Check */
#define AIPS_PACRP_AC6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRP_AC6_SHIFT)) & AIPS_PACRP_AC6_MASK)

#define AIPS_PACRP_RO6_MASK                      (0x80U)
#define AIPS_PACRP_RO6_SHIFT                     (7U)
/*! RO6 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRP_RO6(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRP_RO6_SHIFT)) & AIPS_PACRP_RO6_MASK)

#define AIPS_PACRP_AC5_MASK                      (0x700U)
#define AIPS_PACRP_AC5_SHIFT                     (8U)
/*! AC5 - Attribute Check */
#define AIPS_PACRP_AC5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRP_AC5_SHIFT)) & AIPS_PACRP_AC5_MASK)

#define AIPS_PACRP_RO5_MASK                      (0x800U)
#define AIPS_PACRP_RO5_SHIFT                     (11U)
/*! RO5 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRP_RO5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRP_RO5_SHIFT)) & AIPS_PACRP_RO5_MASK)

#define AIPS_PACRP_AC4_MASK                      (0x7000U)
#define AIPS_PACRP_AC4_SHIFT                     (12U)
/*! AC4 - Attribute Check */
#define AIPS_PACRP_AC4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRP_AC4_SHIFT)) & AIPS_PACRP_AC4_MASK)

#define AIPS_PACRP_RO4_MASK                      (0x8000U)
#define AIPS_PACRP_RO4_SHIFT                     (15U)
/*! RO4 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRP_RO4(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRP_RO4_SHIFT)) & AIPS_PACRP_RO4_MASK)

#define AIPS_PACRP_AC3_MASK                      (0x70000U)
#define AIPS_PACRP_AC3_SHIFT                     (16U)
/*! AC3 - Attribute Check */
#define AIPS_PACRP_AC3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRP_AC3_SHIFT)) & AIPS_PACRP_AC3_MASK)

#define AIPS_PACRP_RO3_MASK                      (0x80000U)
#define AIPS_PACRP_RO3_SHIFT                     (19U)
/*! RO3 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRP_RO3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRP_RO3_SHIFT)) & AIPS_PACRP_RO3_MASK)

#define AIPS_PACRP_AC2_MASK                      (0x700000U)
#define AIPS_PACRP_AC2_SHIFT                     (20U)
/*! AC2 - Attribute Check */
#define AIPS_PACRP_AC2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRP_AC2_SHIFT)) & AIPS_PACRP_AC2_MASK)

#define AIPS_PACRP_RO2_MASK                      (0x800000U)
#define AIPS_PACRP_RO2_SHIFT                     (23U)
/*! RO2 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRP_RO2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRP_RO2_SHIFT)) & AIPS_PACRP_RO2_MASK)

#define AIPS_PACRP_AC1_MASK                      (0x7000000U)
#define AIPS_PACRP_AC1_SHIFT                     (24U)
/*! AC1 - Attribute Check */
#define AIPS_PACRP_AC1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRP_AC1_SHIFT)) & AIPS_PACRP_AC1_MASK)

#define AIPS_PACRP_RO1_MASK                      (0x8000000U)
#define AIPS_PACRP_RO1_SHIFT                     (27U)
/*! RO1 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRP_RO1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRP_RO1_SHIFT)) & AIPS_PACRP_RO1_MASK)

#define AIPS_PACRP_AC0_MASK                      (0x70000000U)
#define AIPS_PACRP_AC0_SHIFT                     (28U)
/*! AC0 - Attribute Check */
#define AIPS_PACRP_AC0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRP_AC0_SHIFT)) & AIPS_PACRP_AC0_MASK)

#define AIPS_PACRP_RO0_MASK                      (0x80000000U)
#define AIPS_PACRP_RO0_SHIFT                     (31U)
/*! RO0 - Read Only
 *  0b0..Writes to corresponding AC field are allowed.
 *  0b1..Writes to corresponding AC field are ignored.
 */
#define AIPS_PACRP_RO0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRP_RO0_SHIFT)) & AIPS_PACRP_RO0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AIPS_Register_Masks */


/*!
 * @}
 */ /* end of group AIPS_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_AIPS_H_ */

