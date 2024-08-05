/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_TRGMUX_3.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_TRGMUX_3
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
#if !defined(S32Z2_TRGMUX_3_H_)  /* Check if memory map has not been already included */
#define S32Z2_TRGMUX_3_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- TRGMUX_3 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_3_Peripheral_Access_Layer TRGMUX_3 Peripheral Access Layer
 * @{
 */

/** TRGMUX_3 - Register Layout Typedef */
typedef struct {
  __IO uint32_t GTM_003_000;                       /**< TRGMUX GTM_003_000, offset: 0x0 */
  __IO uint32_t GTM_007_004;                       /**< TRGMUX GTM_007_004, offset: 0x4 */
  __IO uint32_t GTM_011_008;                       /**< TRGMUX GTM_011_008, offset: 0x8 */
  __IO uint32_t GTM_015_012;                       /**< TRGMUX GTM_015_012, offset: 0xC */
  __IO uint32_t GTM_019_016;                       /**< TRGMUX GTM_019_016, offset: 0x10 */
  __IO uint32_t GTM_023_020;                       /**< TRGMUX GTM_023_020, offset: 0x14 */
  __IO uint32_t GTM_027_024;                       /**< TRGMUX GTM_027_024, offset: 0x18 */
  __IO uint32_t GTM_031_028;                       /**< TRGMUX GTM_031_028, offset: 0x1C */
  __IO uint32_t GTM_035_032;                       /**< TRGMUX GTM_035_032, offset: 0x20 */
  __IO uint32_t GTM_039_036;                       /**< TRGMUX GTM_039_036, offset: 0x24 */
  __IO uint32_t GTM_043_040;                       /**< TRGMUX GTM_043_040, offset: 0x28 */
  __IO uint32_t GTM_047_044;                       /**< TRGMUX GTM_047_044, offset: 0x2C */
  __IO uint32_t GTM_051_048;                       /**< TRGMUX GTM_051_048, offset: 0x30 */
  __IO uint32_t GTM_055_052;                       /**< TRGMUX GTM_055_052, offset: 0x34 */
  __IO uint32_t GTM_059_056;                       /**< TRGMUX GTM_059_056, offset: 0x38 */
  __IO uint32_t GTM_063_060;                       /**< TRGMUX GTM_063_060, offset: 0x3C */
  __IO uint32_t GTM_067_064;                       /**< TRGMUX GTM_067_064, offset: 0x40 */
  __IO uint32_t GTM_071_068;                       /**< TRGMUX GTM_071_068, offset: 0x44 */
  __IO uint32_t GTM_075_072;                       /**< TRGMUX GTM_075_072, offset: 0x48 */
  __IO uint32_t GTM_079_076;                       /**< TRGMUX GTM_079_076, offset: 0x4C */
  __IO uint32_t GTM_083_080;                       /**< TRGMUX GTM_083_080, offset: 0x50 */
  __IO uint32_t GTM_087_084;                       /**< TRGMUX GTM_087_084, offset: 0x54 */
  __IO uint32_t GTM_091_088;                       /**< TRGMUX GTM_091_088, offset: 0x58 */
  __IO uint32_t GTM_095_092;                       /**< TRGMUX GTM_095_092, offset: 0x5C */
  __IO uint32_t GTM_099_096;                       /**< TRGMUX GTM_099_096, offset: 0x60 */
  __IO uint32_t GTM_103_100;                       /**< TRGMUX GTM_103_100, offset: 0x64 */
  __IO uint32_t GTM_107_104;                       /**< TRGMUX GTM_107_104, offset: 0x68 */
  __IO uint32_t GTM_111_108;                       /**< TRGMUX GTM_111_108, offset: 0x6C */
  __IO uint32_t GTM_115_112;                       /**< TRGMUX GTM_115_112, offset: 0x70 */
  __IO uint32_t GTM_119_116;                       /**< TRGMUX GTM_119_116, offset: 0x74 */
  __IO uint32_t GTM_123_120;                       /**< TRGMUX GTM_123_120, offset: 0x78 */
  __IO uint32_t GTM_127_124;                       /**< TRGMUX GTM_127_124, offset: 0x7C */
  __IO uint32_t GTM_131_128;                       /**< TRGMUX GTM_131_128, offset: 0x80 */
  __IO uint32_t GTM_135_132;                       /**< TRGMUX GTM_135_132, offset: 0x84 */
  __IO uint32_t GTM_139_136;                       /**< TRGMUX GTM_139_136, offset: 0x88 */
  __IO uint32_t GTM_143_140;                       /**< TRGMUX GTM_143_140, offset: 0x8C */
  __IO uint32_t GTM_147_144;                       /**< TRGMUX GTM_147_144, offset: 0x90 */
  __IO uint32_t GTM_151_148;                       /**< TRGMUX GTM_151_148, offset: 0x94 */
  __IO uint32_t GTM_155_152;                       /**< TRGMUX GTM_155_152, offset: 0x98 */
  __IO uint32_t GTM_159_156;                       /**< TRGMUX GTM_159_156, offset: 0x9C */
  __IO uint32_t GTM_163_160;                       /**< TRGMUX GTM_163_160, offset: 0xA0 */
  __IO uint32_t GTM_167_164;                       /**< TRGMUX GTM_167_164, offset: 0xA4 */
  __IO uint32_t GTM_168;                           /**< TRGMUX GTM_168, offset: 0xA8 */
  __IO uint32_t MSC_03_00;                         /**< TRGMUX MSC_03_00, offset: 0xAC */
  __IO uint32_t MSC_07_04;                         /**< TRGMUX MSC_07_04, offset: 0xB0 */
  __IO uint32_t MSC_11_08;                         /**< TRGMUX MSC_11_08, offset: 0xB4 */
  __IO uint32_t MSC_15_12;                         /**< TRGMUX MSC_15_12, offset: 0xB8 */
  __IO uint32_t MSC_19_16;                         /**< TRGMUX MSC_19_16, offset: 0xBC */
  __IO uint32_t MSC_23_20;                         /**< TRGMUX MSC_23_20, offset: 0xC0 */
  __IO uint32_t MSC_27_24;                         /**< TRGMUX MSC_27_24, offset: 0xC4 */
  __IO uint32_t MSC_31_28;                         /**< TRGMUX MSC_31_28, offset: 0xC8 */
  __IO uint32_t MSC_35_32;                         /**< TRGMUX MSC_35_32, offset: 0xCC */
  __IO uint32_t MSC_39_36;                         /**< TRGMUX MSC_39_36, offset: 0xD0 */
  __IO uint32_t MSC_43_40;                         /**< TRGMUX MSC_43_40, offset: 0xD4 */
  __IO uint32_t MSC_47_44;                         /**< TRGMUX MSC_47_44, offset: 0xD8 */
  __IO uint32_t MSC_51_48;                         /**< TRGMUX MSC_51_48, offset: 0xDC */
  __IO uint32_t MSC_55_52;                         /**< TRGMUX MSC_55_52, offset: 0xE0 */
  __IO uint32_t MSC_59_56;                         /**< TRGMUX MSC_59_56, offset: 0xE4 */
  __IO uint32_t MSC_63_60;                         /**< TRGMUX MSC_63_60, offset: 0xE8 */
  __IO uint32_t CTU_3_0;                           /**< TRGMUX CTU_3_0, offset: 0xEC */
  __IO uint32_t SINC_3_0;                          /**< TRGMUX SINC_3_0, offset: 0xF0 */
} TRGMUX_3_Type, *TRGMUX_3_MemMapPtr;

/** Number of instances of the TRGMUX_3 module. */
#define TRGMUX_3_INSTANCE_COUNT                  (1u)

/* TRGMUX_3 - Peripheral instance base addresses */
/** Peripheral TRGMUX_3 base address */
#define IP_TRGMUX_3_BASE                         (0x40372000u)
/** Peripheral TRGMUX_3 base pointer */
#define IP_TRGMUX_3                              ((TRGMUX_3_Type *)IP_TRGMUX_3_BASE)
/** Array initializer of TRGMUX_3 peripheral base addresses */
#define IP_TRGMUX_3_BASE_ADDRS                   { IP_TRGMUX_3_BASE }
/** Array initializer of TRGMUX_3 peripheral base pointers */
#define IP_TRGMUX_3_BASE_PTRS                    { IP_TRGMUX_3 }

/* ----------------------------------------------------------------------------
   -- TRGMUX_3 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_3_Register_Masks TRGMUX_3 Register Masks
 * @{
 */

/*! @name GTM_003_000 - TRGMUX GTM_003_000 */
/*! @{ */

#define TRGMUX_3_GTM_003_000_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_003_000_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_003_000_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_003_000_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_003_000_SEL0_SHIFT)) & TRGMUX_3_GTM_003_000_SEL0_MASK)

#define TRGMUX_3_GTM_003_000_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_003_000_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_003_000_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_003_000_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_003_000_SEL1_SHIFT)) & TRGMUX_3_GTM_003_000_SEL1_MASK)

#define TRGMUX_3_GTM_003_000_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_003_000_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_003_000_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_003_000_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_003_000_SEL2_SHIFT)) & TRGMUX_3_GTM_003_000_SEL2_MASK)

#define TRGMUX_3_GTM_003_000_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_003_000_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_003_000_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_003_000_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_003_000_SEL3_SHIFT)) & TRGMUX_3_GTM_003_000_SEL3_MASK)

#define TRGMUX_3_GTM_003_000_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_003_000_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_003_000_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_003_000_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_003_000_LK_SHIFT)) & TRGMUX_3_GTM_003_000_LK_MASK)
/*! @} */

/*! @name GTM_007_004 - TRGMUX GTM_007_004 */
/*! @{ */

#define TRGMUX_3_GTM_007_004_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_007_004_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_007_004_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_007_004_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_007_004_SEL0_SHIFT)) & TRGMUX_3_GTM_007_004_SEL0_MASK)

#define TRGMUX_3_GTM_007_004_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_007_004_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_007_004_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_007_004_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_007_004_SEL1_SHIFT)) & TRGMUX_3_GTM_007_004_SEL1_MASK)

#define TRGMUX_3_GTM_007_004_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_007_004_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_007_004_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_007_004_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_007_004_SEL2_SHIFT)) & TRGMUX_3_GTM_007_004_SEL2_MASK)

#define TRGMUX_3_GTM_007_004_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_007_004_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_007_004_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_007_004_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_007_004_SEL3_SHIFT)) & TRGMUX_3_GTM_007_004_SEL3_MASK)

#define TRGMUX_3_GTM_007_004_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_007_004_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_007_004_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_007_004_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_007_004_LK_SHIFT)) & TRGMUX_3_GTM_007_004_LK_MASK)
/*! @} */

/*! @name GTM_011_008 - TRGMUX GTM_011_008 */
/*! @{ */

#define TRGMUX_3_GTM_011_008_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_011_008_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_011_008_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_011_008_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_011_008_SEL0_SHIFT)) & TRGMUX_3_GTM_011_008_SEL0_MASK)

#define TRGMUX_3_GTM_011_008_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_011_008_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_011_008_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_011_008_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_011_008_SEL1_SHIFT)) & TRGMUX_3_GTM_011_008_SEL1_MASK)

#define TRGMUX_3_GTM_011_008_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_011_008_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_011_008_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_011_008_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_011_008_SEL2_SHIFT)) & TRGMUX_3_GTM_011_008_SEL2_MASK)

#define TRGMUX_3_GTM_011_008_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_011_008_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_011_008_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_011_008_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_011_008_SEL3_SHIFT)) & TRGMUX_3_GTM_011_008_SEL3_MASK)

#define TRGMUX_3_GTM_011_008_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_011_008_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_011_008_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_011_008_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_011_008_LK_SHIFT)) & TRGMUX_3_GTM_011_008_LK_MASK)
/*! @} */

/*! @name GTM_015_012 - TRGMUX GTM_015_012 */
/*! @{ */

#define TRGMUX_3_GTM_015_012_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_015_012_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_015_012_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_015_012_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_015_012_SEL0_SHIFT)) & TRGMUX_3_GTM_015_012_SEL0_MASK)

#define TRGMUX_3_GTM_015_012_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_015_012_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_015_012_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_015_012_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_015_012_SEL1_SHIFT)) & TRGMUX_3_GTM_015_012_SEL1_MASK)

#define TRGMUX_3_GTM_015_012_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_015_012_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_015_012_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_015_012_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_015_012_SEL2_SHIFT)) & TRGMUX_3_GTM_015_012_SEL2_MASK)

#define TRGMUX_3_GTM_015_012_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_015_012_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_015_012_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_015_012_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_015_012_SEL3_SHIFT)) & TRGMUX_3_GTM_015_012_SEL3_MASK)

#define TRGMUX_3_GTM_015_012_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_015_012_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_015_012_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_015_012_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_015_012_LK_SHIFT)) & TRGMUX_3_GTM_015_012_LK_MASK)
/*! @} */

/*! @name GTM_019_016 - TRGMUX GTM_019_016 */
/*! @{ */

#define TRGMUX_3_GTM_019_016_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_019_016_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_019_016_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_019_016_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_019_016_SEL0_SHIFT)) & TRGMUX_3_GTM_019_016_SEL0_MASK)

#define TRGMUX_3_GTM_019_016_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_019_016_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_019_016_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_019_016_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_019_016_SEL1_SHIFT)) & TRGMUX_3_GTM_019_016_SEL1_MASK)

#define TRGMUX_3_GTM_019_016_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_019_016_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_019_016_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_019_016_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_019_016_SEL2_SHIFT)) & TRGMUX_3_GTM_019_016_SEL2_MASK)

#define TRGMUX_3_GTM_019_016_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_019_016_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_019_016_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_019_016_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_019_016_SEL3_SHIFT)) & TRGMUX_3_GTM_019_016_SEL3_MASK)

#define TRGMUX_3_GTM_019_016_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_019_016_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_019_016_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_019_016_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_019_016_LK_SHIFT)) & TRGMUX_3_GTM_019_016_LK_MASK)
/*! @} */

/*! @name GTM_023_020 - TRGMUX GTM_023_020 */
/*! @{ */

#define TRGMUX_3_GTM_023_020_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_023_020_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_023_020_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_023_020_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_023_020_SEL0_SHIFT)) & TRGMUX_3_GTM_023_020_SEL0_MASK)

#define TRGMUX_3_GTM_023_020_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_023_020_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_023_020_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_023_020_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_023_020_SEL1_SHIFT)) & TRGMUX_3_GTM_023_020_SEL1_MASK)

#define TRGMUX_3_GTM_023_020_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_023_020_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_023_020_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_023_020_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_023_020_SEL2_SHIFT)) & TRGMUX_3_GTM_023_020_SEL2_MASK)

#define TRGMUX_3_GTM_023_020_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_023_020_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_023_020_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_023_020_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_023_020_SEL3_SHIFT)) & TRGMUX_3_GTM_023_020_SEL3_MASK)

#define TRGMUX_3_GTM_023_020_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_023_020_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_023_020_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_023_020_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_023_020_LK_SHIFT)) & TRGMUX_3_GTM_023_020_LK_MASK)
/*! @} */

/*! @name GTM_027_024 - TRGMUX GTM_027_024 */
/*! @{ */

#define TRGMUX_3_GTM_027_024_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_027_024_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_027_024_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_027_024_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_027_024_SEL0_SHIFT)) & TRGMUX_3_GTM_027_024_SEL0_MASK)

#define TRGMUX_3_GTM_027_024_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_027_024_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_027_024_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_027_024_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_027_024_SEL1_SHIFT)) & TRGMUX_3_GTM_027_024_SEL1_MASK)

#define TRGMUX_3_GTM_027_024_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_027_024_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_027_024_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_027_024_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_027_024_SEL2_SHIFT)) & TRGMUX_3_GTM_027_024_SEL2_MASK)

#define TRGMUX_3_GTM_027_024_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_027_024_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_027_024_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_027_024_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_027_024_SEL3_SHIFT)) & TRGMUX_3_GTM_027_024_SEL3_MASK)

#define TRGMUX_3_GTM_027_024_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_027_024_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_027_024_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_027_024_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_027_024_LK_SHIFT)) & TRGMUX_3_GTM_027_024_LK_MASK)
/*! @} */

/*! @name GTM_031_028 - TRGMUX GTM_031_028 */
/*! @{ */

#define TRGMUX_3_GTM_031_028_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_031_028_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_031_028_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_031_028_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_031_028_SEL0_SHIFT)) & TRGMUX_3_GTM_031_028_SEL0_MASK)

#define TRGMUX_3_GTM_031_028_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_031_028_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_031_028_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_031_028_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_031_028_SEL1_SHIFT)) & TRGMUX_3_GTM_031_028_SEL1_MASK)

#define TRGMUX_3_GTM_031_028_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_031_028_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_031_028_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_031_028_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_031_028_SEL2_SHIFT)) & TRGMUX_3_GTM_031_028_SEL2_MASK)

#define TRGMUX_3_GTM_031_028_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_031_028_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_031_028_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_031_028_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_031_028_SEL3_SHIFT)) & TRGMUX_3_GTM_031_028_SEL3_MASK)

#define TRGMUX_3_GTM_031_028_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_031_028_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_031_028_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_031_028_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_031_028_LK_SHIFT)) & TRGMUX_3_GTM_031_028_LK_MASK)
/*! @} */

/*! @name GTM_035_032 - TRGMUX GTM_035_032 */
/*! @{ */

#define TRGMUX_3_GTM_035_032_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_035_032_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_035_032_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_035_032_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_035_032_SEL0_SHIFT)) & TRGMUX_3_GTM_035_032_SEL0_MASK)

#define TRGMUX_3_GTM_035_032_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_035_032_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_035_032_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_035_032_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_035_032_SEL1_SHIFT)) & TRGMUX_3_GTM_035_032_SEL1_MASK)

#define TRGMUX_3_GTM_035_032_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_035_032_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_035_032_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_035_032_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_035_032_SEL2_SHIFT)) & TRGMUX_3_GTM_035_032_SEL2_MASK)

#define TRGMUX_3_GTM_035_032_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_035_032_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_035_032_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_035_032_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_035_032_SEL3_SHIFT)) & TRGMUX_3_GTM_035_032_SEL3_MASK)

#define TRGMUX_3_GTM_035_032_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_035_032_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_035_032_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_035_032_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_035_032_LK_SHIFT)) & TRGMUX_3_GTM_035_032_LK_MASK)
/*! @} */

/*! @name GTM_039_036 - TRGMUX GTM_039_036 */
/*! @{ */

#define TRGMUX_3_GTM_039_036_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_039_036_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_039_036_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_039_036_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_039_036_SEL0_SHIFT)) & TRGMUX_3_GTM_039_036_SEL0_MASK)

#define TRGMUX_3_GTM_039_036_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_039_036_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_039_036_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_039_036_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_039_036_SEL1_SHIFT)) & TRGMUX_3_GTM_039_036_SEL1_MASK)

#define TRGMUX_3_GTM_039_036_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_039_036_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_039_036_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_039_036_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_039_036_SEL2_SHIFT)) & TRGMUX_3_GTM_039_036_SEL2_MASK)

#define TRGMUX_3_GTM_039_036_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_039_036_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_039_036_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_039_036_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_039_036_SEL3_SHIFT)) & TRGMUX_3_GTM_039_036_SEL3_MASK)

#define TRGMUX_3_GTM_039_036_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_039_036_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_039_036_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_039_036_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_039_036_LK_SHIFT)) & TRGMUX_3_GTM_039_036_LK_MASK)
/*! @} */

/*! @name GTM_043_040 - TRGMUX GTM_043_040 */
/*! @{ */

#define TRGMUX_3_GTM_043_040_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_043_040_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_043_040_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_043_040_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_043_040_SEL0_SHIFT)) & TRGMUX_3_GTM_043_040_SEL0_MASK)

#define TRGMUX_3_GTM_043_040_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_043_040_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_043_040_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_043_040_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_043_040_SEL1_SHIFT)) & TRGMUX_3_GTM_043_040_SEL1_MASK)

#define TRGMUX_3_GTM_043_040_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_043_040_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_043_040_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_043_040_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_043_040_SEL2_SHIFT)) & TRGMUX_3_GTM_043_040_SEL2_MASK)

#define TRGMUX_3_GTM_043_040_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_043_040_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_043_040_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_043_040_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_043_040_SEL3_SHIFT)) & TRGMUX_3_GTM_043_040_SEL3_MASK)

#define TRGMUX_3_GTM_043_040_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_043_040_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_043_040_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_043_040_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_043_040_LK_SHIFT)) & TRGMUX_3_GTM_043_040_LK_MASK)
/*! @} */

/*! @name GTM_047_044 - TRGMUX GTM_047_044 */
/*! @{ */

#define TRGMUX_3_GTM_047_044_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_047_044_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_047_044_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_047_044_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_047_044_SEL0_SHIFT)) & TRGMUX_3_GTM_047_044_SEL0_MASK)

#define TRGMUX_3_GTM_047_044_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_047_044_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_047_044_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_047_044_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_047_044_SEL1_SHIFT)) & TRGMUX_3_GTM_047_044_SEL1_MASK)

#define TRGMUX_3_GTM_047_044_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_047_044_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_047_044_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_047_044_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_047_044_SEL2_SHIFT)) & TRGMUX_3_GTM_047_044_SEL2_MASK)

#define TRGMUX_3_GTM_047_044_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_047_044_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_047_044_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_047_044_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_047_044_SEL3_SHIFT)) & TRGMUX_3_GTM_047_044_SEL3_MASK)

#define TRGMUX_3_GTM_047_044_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_047_044_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_047_044_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_047_044_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_047_044_LK_SHIFT)) & TRGMUX_3_GTM_047_044_LK_MASK)
/*! @} */

/*! @name GTM_051_048 - TRGMUX GTM_051_048 */
/*! @{ */

#define TRGMUX_3_GTM_051_048_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_051_048_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_051_048_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_051_048_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_051_048_SEL0_SHIFT)) & TRGMUX_3_GTM_051_048_SEL0_MASK)

#define TRGMUX_3_GTM_051_048_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_051_048_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_051_048_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_051_048_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_051_048_SEL1_SHIFT)) & TRGMUX_3_GTM_051_048_SEL1_MASK)

#define TRGMUX_3_GTM_051_048_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_051_048_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_051_048_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_051_048_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_051_048_SEL2_SHIFT)) & TRGMUX_3_GTM_051_048_SEL2_MASK)

#define TRGMUX_3_GTM_051_048_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_051_048_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_051_048_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_051_048_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_051_048_SEL3_SHIFT)) & TRGMUX_3_GTM_051_048_SEL3_MASK)

#define TRGMUX_3_GTM_051_048_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_051_048_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_051_048_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_051_048_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_051_048_LK_SHIFT)) & TRGMUX_3_GTM_051_048_LK_MASK)
/*! @} */

/*! @name GTM_055_052 - TRGMUX GTM_055_052 */
/*! @{ */

#define TRGMUX_3_GTM_055_052_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_055_052_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_055_052_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_055_052_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_055_052_SEL0_SHIFT)) & TRGMUX_3_GTM_055_052_SEL0_MASK)

#define TRGMUX_3_GTM_055_052_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_055_052_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_055_052_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_055_052_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_055_052_SEL1_SHIFT)) & TRGMUX_3_GTM_055_052_SEL1_MASK)

#define TRGMUX_3_GTM_055_052_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_055_052_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_055_052_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_055_052_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_055_052_SEL2_SHIFT)) & TRGMUX_3_GTM_055_052_SEL2_MASK)

#define TRGMUX_3_GTM_055_052_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_055_052_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_055_052_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_055_052_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_055_052_SEL3_SHIFT)) & TRGMUX_3_GTM_055_052_SEL3_MASK)

#define TRGMUX_3_GTM_055_052_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_055_052_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_055_052_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_055_052_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_055_052_LK_SHIFT)) & TRGMUX_3_GTM_055_052_LK_MASK)
/*! @} */

/*! @name GTM_059_056 - TRGMUX GTM_059_056 */
/*! @{ */

#define TRGMUX_3_GTM_059_056_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_059_056_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_059_056_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_059_056_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_059_056_SEL0_SHIFT)) & TRGMUX_3_GTM_059_056_SEL0_MASK)

#define TRGMUX_3_GTM_059_056_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_059_056_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_059_056_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_059_056_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_059_056_SEL1_SHIFT)) & TRGMUX_3_GTM_059_056_SEL1_MASK)

#define TRGMUX_3_GTM_059_056_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_059_056_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_059_056_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_059_056_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_059_056_SEL2_SHIFT)) & TRGMUX_3_GTM_059_056_SEL2_MASK)

#define TRGMUX_3_GTM_059_056_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_059_056_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_059_056_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_059_056_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_059_056_SEL3_SHIFT)) & TRGMUX_3_GTM_059_056_SEL3_MASK)

#define TRGMUX_3_GTM_059_056_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_059_056_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_059_056_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_059_056_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_059_056_LK_SHIFT)) & TRGMUX_3_GTM_059_056_LK_MASK)
/*! @} */

/*! @name GTM_063_060 - TRGMUX GTM_063_060 */
/*! @{ */

#define TRGMUX_3_GTM_063_060_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_063_060_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_063_060_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_063_060_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_063_060_SEL0_SHIFT)) & TRGMUX_3_GTM_063_060_SEL0_MASK)

#define TRGMUX_3_GTM_063_060_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_063_060_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_063_060_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_063_060_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_063_060_SEL1_SHIFT)) & TRGMUX_3_GTM_063_060_SEL1_MASK)

#define TRGMUX_3_GTM_063_060_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_063_060_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_063_060_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_063_060_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_063_060_SEL2_SHIFT)) & TRGMUX_3_GTM_063_060_SEL2_MASK)

#define TRGMUX_3_GTM_063_060_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_063_060_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_063_060_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_063_060_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_063_060_SEL3_SHIFT)) & TRGMUX_3_GTM_063_060_SEL3_MASK)

#define TRGMUX_3_GTM_063_060_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_063_060_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_063_060_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_063_060_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_063_060_LK_SHIFT)) & TRGMUX_3_GTM_063_060_LK_MASK)
/*! @} */

/*! @name GTM_067_064 - TRGMUX GTM_067_064 */
/*! @{ */

#define TRGMUX_3_GTM_067_064_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_067_064_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_067_064_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_067_064_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_067_064_SEL0_SHIFT)) & TRGMUX_3_GTM_067_064_SEL0_MASK)

#define TRGMUX_3_GTM_067_064_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_067_064_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_067_064_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_067_064_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_067_064_SEL1_SHIFT)) & TRGMUX_3_GTM_067_064_SEL1_MASK)

#define TRGMUX_3_GTM_067_064_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_067_064_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_067_064_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_067_064_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_067_064_SEL2_SHIFT)) & TRGMUX_3_GTM_067_064_SEL2_MASK)

#define TRGMUX_3_GTM_067_064_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_067_064_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_067_064_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_067_064_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_067_064_SEL3_SHIFT)) & TRGMUX_3_GTM_067_064_SEL3_MASK)

#define TRGMUX_3_GTM_067_064_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_067_064_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_067_064_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_067_064_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_067_064_LK_SHIFT)) & TRGMUX_3_GTM_067_064_LK_MASK)
/*! @} */

/*! @name GTM_071_068 - TRGMUX GTM_071_068 */
/*! @{ */

#define TRGMUX_3_GTM_071_068_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_071_068_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_071_068_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_071_068_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_071_068_SEL0_SHIFT)) & TRGMUX_3_GTM_071_068_SEL0_MASK)

#define TRGMUX_3_GTM_071_068_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_071_068_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_071_068_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_071_068_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_071_068_SEL1_SHIFT)) & TRGMUX_3_GTM_071_068_SEL1_MASK)

#define TRGMUX_3_GTM_071_068_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_071_068_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_071_068_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_071_068_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_071_068_SEL2_SHIFT)) & TRGMUX_3_GTM_071_068_SEL2_MASK)

#define TRGMUX_3_GTM_071_068_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_071_068_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_071_068_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_071_068_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_071_068_SEL3_SHIFT)) & TRGMUX_3_GTM_071_068_SEL3_MASK)

#define TRGMUX_3_GTM_071_068_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_071_068_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_071_068_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_071_068_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_071_068_LK_SHIFT)) & TRGMUX_3_GTM_071_068_LK_MASK)
/*! @} */

/*! @name GTM_075_072 - TRGMUX GTM_075_072 */
/*! @{ */

#define TRGMUX_3_GTM_075_072_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_075_072_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_075_072_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_075_072_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_075_072_SEL0_SHIFT)) & TRGMUX_3_GTM_075_072_SEL0_MASK)

#define TRGMUX_3_GTM_075_072_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_075_072_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_075_072_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_075_072_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_075_072_SEL1_SHIFT)) & TRGMUX_3_GTM_075_072_SEL1_MASK)

#define TRGMUX_3_GTM_075_072_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_075_072_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_075_072_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_075_072_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_075_072_SEL2_SHIFT)) & TRGMUX_3_GTM_075_072_SEL2_MASK)

#define TRGMUX_3_GTM_075_072_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_075_072_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_075_072_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_075_072_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_075_072_SEL3_SHIFT)) & TRGMUX_3_GTM_075_072_SEL3_MASK)

#define TRGMUX_3_GTM_075_072_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_075_072_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_075_072_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_075_072_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_075_072_LK_SHIFT)) & TRGMUX_3_GTM_075_072_LK_MASK)
/*! @} */

/*! @name GTM_079_076 - TRGMUX GTM_079_076 */
/*! @{ */

#define TRGMUX_3_GTM_079_076_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_079_076_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_079_076_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_079_076_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_079_076_SEL0_SHIFT)) & TRGMUX_3_GTM_079_076_SEL0_MASK)

#define TRGMUX_3_GTM_079_076_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_079_076_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_079_076_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_079_076_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_079_076_SEL1_SHIFT)) & TRGMUX_3_GTM_079_076_SEL1_MASK)

#define TRGMUX_3_GTM_079_076_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_079_076_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_079_076_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_079_076_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_079_076_SEL2_SHIFT)) & TRGMUX_3_GTM_079_076_SEL2_MASK)

#define TRGMUX_3_GTM_079_076_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_079_076_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_079_076_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_079_076_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_079_076_SEL3_SHIFT)) & TRGMUX_3_GTM_079_076_SEL3_MASK)

#define TRGMUX_3_GTM_079_076_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_079_076_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_079_076_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_079_076_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_079_076_LK_SHIFT)) & TRGMUX_3_GTM_079_076_LK_MASK)
/*! @} */

/*! @name GTM_083_080 - TRGMUX GTM_083_080 */
/*! @{ */

#define TRGMUX_3_GTM_083_080_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_083_080_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_083_080_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_083_080_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_083_080_SEL0_SHIFT)) & TRGMUX_3_GTM_083_080_SEL0_MASK)

#define TRGMUX_3_GTM_083_080_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_083_080_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_083_080_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_083_080_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_083_080_SEL1_SHIFT)) & TRGMUX_3_GTM_083_080_SEL1_MASK)

#define TRGMUX_3_GTM_083_080_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_083_080_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_083_080_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_083_080_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_083_080_SEL2_SHIFT)) & TRGMUX_3_GTM_083_080_SEL2_MASK)

#define TRGMUX_3_GTM_083_080_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_083_080_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_083_080_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_083_080_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_083_080_SEL3_SHIFT)) & TRGMUX_3_GTM_083_080_SEL3_MASK)

#define TRGMUX_3_GTM_083_080_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_083_080_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_083_080_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_083_080_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_083_080_LK_SHIFT)) & TRGMUX_3_GTM_083_080_LK_MASK)
/*! @} */

/*! @name GTM_087_084 - TRGMUX GTM_087_084 */
/*! @{ */

#define TRGMUX_3_GTM_087_084_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_087_084_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_087_084_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_087_084_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_087_084_SEL0_SHIFT)) & TRGMUX_3_GTM_087_084_SEL0_MASK)

#define TRGMUX_3_GTM_087_084_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_087_084_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_087_084_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_087_084_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_087_084_SEL1_SHIFT)) & TRGMUX_3_GTM_087_084_SEL1_MASK)

#define TRGMUX_3_GTM_087_084_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_087_084_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_087_084_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_087_084_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_087_084_SEL2_SHIFT)) & TRGMUX_3_GTM_087_084_SEL2_MASK)

#define TRGMUX_3_GTM_087_084_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_087_084_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_087_084_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_087_084_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_087_084_SEL3_SHIFT)) & TRGMUX_3_GTM_087_084_SEL3_MASK)

#define TRGMUX_3_GTM_087_084_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_087_084_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_087_084_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_087_084_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_087_084_LK_SHIFT)) & TRGMUX_3_GTM_087_084_LK_MASK)
/*! @} */

/*! @name GTM_091_088 - TRGMUX GTM_091_088 */
/*! @{ */

#define TRGMUX_3_GTM_091_088_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_091_088_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_091_088_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_091_088_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_091_088_SEL0_SHIFT)) & TRGMUX_3_GTM_091_088_SEL0_MASK)

#define TRGMUX_3_GTM_091_088_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_091_088_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_091_088_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_091_088_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_091_088_SEL1_SHIFT)) & TRGMUX_3_GTM_091_088_SEL1_MASK)

#define TRGMUX_3_GTM_091_088_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_091_088_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_091_088_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_091_088_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_091_088_SEL2_SHIFT)) & TRGMUX_3_GTM_091_088_SEL2_MASK)

#define TRGMUX_3_GTM_091_088_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_091_088_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_091_088_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_091_088_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_091_088_SEL3_SHIFT)) & TRGMUX_3_GTM_091_088_SEL3_MASK)

#define TRGMUX_3_GTM_091_088_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_091_088_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_091_088_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_091_088_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_091_088_LK_SHIFT)) & TRGMUX_3_GTM_091_088_LK_MASK)
/*! @} */

/*! @name GTM_095_092 - TRGMUX GTM_095_092 */
/*! @{ */

#define TRGMUX_3_GTM_095_092_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_095_092_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_095_092_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_095_092_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_095_092_SEL0_SHIFT)) & TRGMUX_3_GTM_095_092_SEL0_MASK)

#define TRGMUX_3_GTM_095_092_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_095_092_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_095_092_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_095_092_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_095_092_SEL1_SHIFT)) & TRGMUX_3_GTM_095_092_SEL1_MASK)

#define TRGMUX_3_GTM_095_092_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_095_092_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_095_092_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_095_092_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_095_092_SEL2_SHIFT)) & TRGMUX_3_GTM_095_092_SEL2_MASK)

#define TRGMUX_3_GTM_095_092_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_095_092_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_095_092_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_095_092_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_095_092_SEL3_SHIFT)) & TRGMUX_3_GTM_095_092_SEL3_MASK)

#define TRGMUX_3_GTM_095_092_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_095_092_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_095_092_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_095_092_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_095_092_LK_SHIFT)) & TRGMUX_3_GTM_095_092_LK_MASK)
/*! @} */

/*! @name GTM_099_096 - TRGMUX GTM_099_096 */
/*! @{ */

#define TRGMUX_3_GTM_099_096_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_099_096_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_099_096_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_099_096_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_099_096_SEL0_SHIFT)) & TRGMUX_3_GTM_099_096_SEL0_MASK)

#define TRGMUX_3_GTM_099_096_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_099_096_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_099_096_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_099_096_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_099_096_SEL1_SHIFT)) & TRGMUX_3_GTM_099_096_SEL1_MASK)

#define TRGMUX_3_GTM_099_096_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_099_096_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_099_096_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_099_096_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_099_096_SEL2_SHIFT)) & TRGMUX_3_GTM_099_096_SEL2_MASK)

#define TRGMUX_3_GTM_099_096_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_099_096_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_099_096_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_099_096_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_099_096_SEL3_SHIFT)) & TRGMUX_3_GTM_099_096_SEL3_MASK)

#define TRGMUX_3_GTM_099_096_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_099_096_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_099_096_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_099_096_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_099_096_LK_SHIFT)) & TRGMUX_3_GTM_099_096_LK_MASK)
/*! @} */

/*! @name GTM_103_100 - TRGMUX GTM_103_100 */
/*! @{ */

#define TRGMUX_3_GTM_103_100_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_103_100_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_103_100_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_103_100_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_103_100_SEL0_SHIFT)) & TRGMUX_3_GTM_103_100_SEL0_MASK)

#define TRGMUX_3_GTM_103_100_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_103_100_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_103_100_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_103_100_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_103_100_SEL1_SHIFT)) & TRGMUX_3_GTM_103_100_SEL1_MASK)

#define TRGMUX_3_GTM_103_100_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_103_100_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_103_100_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_103_100_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_103_100_SEL2_SHIFT)) & TRGMUX_3_GTM_103_100_SEL2_MASK)

#define TRGMUX_3_GTM_103_100_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_103_100_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_103_100_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_103_100_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_103_100_SEL3_SHIFT)) & TRGMUX_3_GTM_103_100_SEL3_MASK)

#define TRGMUX_3_GTM_103_100_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_103_100_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_103_100_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_103_100_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_103_100_LK_SHIFT)) & TRGMUX_3_GTM_103_100_LK_MASK)
/*! @} */

/*! @name GTM_107_104 - TRGMUX GTM_107_104 */
/*! @{ */

#define TRGMUX_3_GTM_107_104_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_107_104_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_107_104_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_107_104_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_107_104_SEL0_SHIFT)) & TRGMUX_3_GTM_107_104_SEL0_MASK)

#define TRGMUX_3_GTM_107_104_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_107_104_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_107_104_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_107_104_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_107_104_SEL1_SHIFT)) & TRGMUX_3_GTM_107_104_SEL1_MASK)

#define TRGMUX_3_GTM_107_104_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_107_104_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_107_104_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_107_104_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_107_104_SEL2_SHIFT)) & TRGMUX_3_GTM_107_104_SEL2_MASK)

#define TRGMUX_3_GTM_107_104_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_107_104_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_107_104_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_107_104_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_107_104_SEL3_SHIFT)) & TRGMUX_3_GTM_107_104_SEL3_MASK)

#define TRGMUX_3_GTM_107_104_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_107_104_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_107_104_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_107_104_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_107_104_LK_SHIFT)) & TRGMUX_3_GTM_107_104_LK_MASK)
/*! @} */

/*! @name GTM_111_108 - TRGMUX GTM_111_108 */
/*! @{ */

#define TRGMUX_3_GTM_111_108_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_111_108_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_111_108_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_111_108_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_111_108_SEL0_SHIFT)) & TRGMUX_3_GTM_111_108_SEL0_MASK)

#define TRGMUX_3_GTM_111_108_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_111_108_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_111_108_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_111_108_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_111_108_SEL1_SHIFT)) & TRGMUX_3_GTM_111_108_SEL1_MASK)

#define TRGMUX_3_GTM_111_108_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_111_108_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_111_108_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_111_108_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_111_108_SEL2_SHIFT)) & TRGMUX_3_GTM_111_108_SEL2_MASK)

#define TRGMUX_3_GTM_111_108_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_111_108_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_111_108_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_111_108_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_111_108_SEL3_SHIFT)) & TRGMUX_3_GTM_111_108_SEL3_MASK)

#define TRGMUX_3_GTM_111_108_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_111_108_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_111_108_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_111_108_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_111_108_LK_SHIFT)) & TRGMUX_3_GTM_111_108_LK_MASK)
/*! @} */

/*! @name GTM_115_112 - TRGMUX GTM_115_112 */
/*! @{ */

#define TRGMUX_3_GTM_115_112_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_115_112_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_115_112_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_115_112_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_115_112_SEL0_SHIFT)) & TRGMUX_3_GTM_115_112_SEL0_MASK)

#define TRGMUX_3_GTM_115_112_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_115_112_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_115_112_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_115_112_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_115_112_SEL1_SHIFT)) & TRGMUX_3_GTM_115_112_SEL1_MASK)

#define TRGMUX_3_GTM_115_112_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_115_112_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_115_112_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_115_112_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_115_112_SEL2_SHIFT)) & TRGMUX_3_GTM_115_112_SEL2_MASK)

#define TRGMUX_3_GTM_115_112_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_115_112_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_115_112_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_115_112_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_115_112_SEL3_SHIFT)) & TRGMUX_3_GTM_115_112_SEL3_MASK)

#define TRGMUX_3_GTM_115_112_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_115_112_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_115_112_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_115_112_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_115_112_LK_SHIFT)) & TRGMUX_3_GTM_115_112_LK_MASK)
/*! @} */

/*! @name GTM_119_116 - TRGMUX GTM_119_116 */
/*! @{ */

#define TRGMUX_3_GTM_119_116_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_119_116_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_119_116_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_119_116_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_119_116_SEL0_SHIFT)) & TRGMUX_3_GTM_119_116_SEL0_MASK)

#define TRGMUX_3_GTM_119_116_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_119_116_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_119_116_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_119_116_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_119_116_SEL1_SHIFT)) & TRGMUX_3_GTM_119_116_SEL1_MASK)

#define TRGMUX_3_GTM_119_116_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_119_116_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_119_116_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_119_116_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_119_116_SEL2_SHIFT)) & TRGMUX_3_GTM_119_116_SEL2_MASK)

#define TRGMUX_3_GTM_119_116_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_119_116_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_119_116_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_119_116_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_119_116_SEL3_SHIFT)) & TRGMUX_3_GTM_119_116_SEL3_MASK)

#define TRGMUX_3_GTM_119_116_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_119_116_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_119_116_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_119_116_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_119_116_LK_SHIFT)) & TRGMUX_3_GTM_119_116_LK_MASK)
/*! @} */

/*! @name GTM_123_120 - TRGMUX GTM_123_120 */
/*! @{ */

#define TRGMUX_3_GTM_123_120_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_123_120_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_123_120_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_123_120_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_123_120_SEL0_SHIFT)) & TRGMUX_3_GTM_123_120_SEL0_MASK)

#define TRGMUX_3_GTM_123_120_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_123_120_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_123_120_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_123_120_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_123_120_SEL1_SHIFT)) & TRGMUX_3_GTM_123_120_SEL1_MASK)

#define TRGMUX_3_GTM_123_120_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_123_120_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_123_120_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_123_120_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_123_120_SEL2_SHIFT)) & TRGMUX_3_GTM_123_120_SEL2_MASK)

#define TRGMUX_3_GTM_123_120_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_123_120_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_123_120_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_123_120_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_123_120_SEL3_SHIFT)) & TRGMUX_3_GTM_123_120_SEL3_MASK)

#define TRGMUX_3_GTM_123_120_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_123_120_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_123_120_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_123_120_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_123_120_LK_SHIFT)) & TRGMUX_3_GTM_123_120_LK_MASK)
/*! @} */

/*! @name GTM_127_124 - TRGMUX GTM_127_124 */
/*! @{ */

#define TRGMUX_3_GTM_127_124_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_127_124_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_127_124_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_127_124_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_127_124_SEL0_SHIFT)) & TRGMUX_3_GTM_127_124_SEL0_MASK)

#define TRGMUX_3_GTM_127_124_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_127_124_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_127_124_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_127_124_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_127_124_SEL1_SHIFT)) & TRGMUX_3_GTM_127_124_SEL1_MASK)

#define TRGMUX_3_GTM_127_124_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_127_124_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_127_124_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_127_124_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_127_124_SEL2_SHIFT)) & TRGMUX_3_GTM_127_124_SEL2_MASK)

#define TRGMUX_3_GTM_127_124_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_127_124_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_127_124_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_127_124_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_127_124_SEL3_SHIFT)) & TRGMUX_3_GTM_127_124_SEL3_MASK)

#define TRGMUX_3_GTM_127_124_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_127_124_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_127_124_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_127_124_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_127_124_LK_SHIFT)) & TRGMUX_3_GTM_127_124_LK_MASK)
/*! @} */

/*! @name GTM_131_128 - TRGMUX GTM_131_128 */
/*! @{ */

#define TRGMUX_3_GTM_131_128_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_131_128_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_131_128_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_131_128_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_131_128_SEL0_SHIFT)) & TRGMUX_3_GTM_131_128_SEL0_MASK)

#define TRGMUX_3_GTM_131_128_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_131_128_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_131_128_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_131_128_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_131_128_SEL1_SHIFT)) & TRGMUX_3_GTM_131_128_SEL1_MASK)

#define TRGMUX_3_GTM_131_128_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_131_128_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_131_128_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_131_128_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_131_128_SEL2_SHIFT)) & TRGMUX_3_GTM_131_128_SEL2_MASK)

#define TRGMUX_3_GTM_131_128_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_131_128_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_131_128_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_131_128_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_131_128_SEL3_SHIFT)) & TRGMUX_3_GTM_131_128_SEL3_MASK)

#define TRGMUX_3_GTM_131_128_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_131_128_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_131_128_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_131_128_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_131_128_LK_SHIFT)) & TRGMUX_3_GTM_131_128_LK_MASK)
/*! @} */

/*! @name GTM_135_132 - TRGMUX GTM_135_132 */
/*! @{ */

#define TRGMUX_3_GTM_135_132_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_135_132_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_135_132_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_135_132_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_135_132_SEL0_SHIFT)) & TRGMUX_3_GTM_135_132_SEL0_MASK)

#define TRGMUX_3_GTM_135_132_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_135_132_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_135_132_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_135_132_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_135_132_SEL1_SHIFT)) & TRGMUX_3_GTM_135_132_SEL1_MASK)

#define TRGMUX_3_GTM_135_132_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_135_132_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_135_132_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_135_132_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_135_132_SEL2_SHIFT)) & TRGMUX_3_GTM_135_132_SEL2_MASK)

#define TRGMUX_3_GTM_135_132_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_135_132_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_135_132_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_135_132_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_135_132_SEL3_SHIFT)) & TRGMUX_3_GTM_135_132_SEL3_MASK)

#define TRGMUX_3_GTM_135_132_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_135_132_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_135_132_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_135_132_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_135_132_LK_SHIFT)) & TRGMUX_3_GTM_135_132_LK_MASK)
/*! @} */

/*! @name GTM_139_136 - TRGMUX GTM_139_136 */
/*! @{ */

#define TRGMUX_3_GTM_139_136_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_139_136_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_139_136_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_139_136_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_139_136_SEL0_SHIFT)) & TRGMUX_3_GTM_139_136_SEL0_MASK)

#define TRGMUX_3_GTM_139_136_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_139_136_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_139_136_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_139_136_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_139_136_SEL1_SHIFT)) & TRGMUX_3_GTM_139_136_SEL1_MASK)

#define TRGMUX_3_GTM_139_136_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_139_136_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_139_136_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_139_136_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_139_136_SEL2_SHIFT)) & TRGMUX_3_GTM_139_136_SEL2_MASK)

#define TRGMUX_3_GTM_139_136_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_139_136_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_139_136_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_139_136_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_139_136_SEL3_SHIFT)) & TRGMUX_3_GTM_139_136_SEL3_MASK)

#define TRGMUX_3_GTM_139_136_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_139_136_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_139_136_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_139_136_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_139_136_LK_SHIFT)) & TRGMUX_3_GTM_139_136_LK_MASK)
/*! @} */

/*! @name GTM_143_140 - TRGMUX GTM_143_140 */
/*! @{ */

#define TRGMUX_3_GTM_143_140_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_143_140_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_143_140_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_143_140_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_143_140_SEL0_SHIFT)) & TRGMUX_3_GTM_143_140_SEL0_MASK)

#define TRGMUX_3_GTM_143_140_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_143_140_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_143_140_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_143_140_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_143_140_SEL1_SHIFT)) & TRGMUX_3_GTM_143_140_SEL1_MASK)

#define TRGMUX_3_GTM_143_140_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_143_140_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_143_140_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_143_140_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_143_140_SEL2_SHIFT)) & TRGMUX_3_GTM_143_140_SEL2_MASK)

#define TRGMUX_3_GTM_143_140_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_143_140_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_143_140_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_143_140_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_143_140_SEL3_SHIFT)) & TRGMUX_3_GTM_143_140_SEL3_MASK)

#define TRGMUX_3_GTM_143_140_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_143_140_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_143_140_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_143_140_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_143_140_LK_SHIFT)) & TRGMUX_3_GTM_143_140_LK_MASK)
/*! @} */

/*! @name GTM_147_144 - TRGMUX GTM_147_144 */
/*! @{ */

#define TRGMUX_3_GTM_147_144_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_147_144_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_147_144_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_147_144_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_147_144_SEL0_SHIFT)) & TRGMUX_3_GTM_147_144_SEL0_MASK)

#define TRGMUX_3_GTM_147_144_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_147_144_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_147_144_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_147_144_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_147_144_SEL1_SHIFT)) & TRGMUX_3_GTM_147_144_SEL1_MASK)

#define TRGMUX_3_GTM_147_144_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_147_144_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_147_144_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_147_144_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_147_144_SEL2_SHIFT)) & TRGMUX_3_GTM_147_144_SEL2_MASK)

#define TRGMUX_3_GTM_147_144_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_147_144_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_147_144_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_147_144_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_147_144_SEL3_SHIFT)) & TRGMUX_3_GTM_147_144_SEL3_MASK)

#define TRGMUX_3_GTM_147_144_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_147_144_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_147_144_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_147_144_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_147_144_LK_SHIFT)) & TRGMUX_3_GTM_147_144_LK_MASK)
/*! @} */

/*! @name GTM_151_148 - TRGMUX GTM_151_148 */
/*! @{ */

#define TRGMUX_3_GTM_151_148_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_151_148_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_151_148_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_151_148_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_151_148_SEL0_SHIFT)) & TRGMUX_3_GTM_151_148_SEL0_MASK)

#define TRGMUX_3_GTM_151_148_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_151_148_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_151_148_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_151_148_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_151_148_SEL1_SHIFT)) & TRGMUX_3_GTM_151_148_SEL1_MASK)

#define TRGMUX_3_GTM_151_148_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_151_148_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_151_148_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_151_148_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_151_148_SEL2_SHIFT)) & TRGMUX_3_GTM_151_148_SEL2_MASK)

#define TRGMUX_3_GTM_151_148_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_151_148_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_151_148_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_151_148_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_151_148_SEL3_SHIFT)) & TRGMUX_3_GTM_151_148_SEL3_MASK)

#define TRGMUX_3_GTM_151_148_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_151_148_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_151_148_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_151_148_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_151_148_LK_SHIFT)) & TRGMUX_3_GTM_151_148_LK_MASK)
/*! @} */

/*! @name GTM_155_152 - TRGMUX GTM_155_152 */
/*! @{ */

#define TRGMUX_3_GTM_155_152_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_155_152_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_155_152_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_155_152_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_155_152_SEL0_SHIFT)) & TRGMUX_3_GTM_155_152_SEL0_MASK)

#define TRGMUX_3_GTM_155_152_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_155_152_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_155_152_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_155_152_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_155_152_SEL1_SHIFT)) & TRGMUX_3_GTM_155_152_SEL1_MASK)

#define TRGMUX_3_GTM_155_152_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_155_152_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_155_152_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_155_152_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_155_152_SEL2_SHIFT)) & TRGMUX_3_GTM_155_152_SEL2_MASK)

#define TRGMUX_3_GTM_155_152_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_155_152_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_155_152_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_155_152_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_155_152_SEL3_SHIFT)) & TRGMUX_3_GTM_155_152_SEL3_MASK)

#define TRGMUX_3_GTM_155_152_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_155_152_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_155_152_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_155_152_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_155_152_LK_SHIFT)) & TRGMUX_3_GTM_155_152_LK_MASK)
/*! @} */

/*! @name GTM_159_156 - TRGMUX GTM_159_156 */
/*! @{ */

#define TRGMUX_3_GTM_159_156_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_159_156_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_159_156_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_159_156_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_159_156_SEL0_SHIFT)) & TRGMUX_3_GTM_159_156_SEL0_MASK)

#define TRGMUX_3_GTM_159_156_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_159_156_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_159_156_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_159_156_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_159_156_SEL1_SHIFT)) & TRGMUX_3_GTM_159_156_SEL1_MASK)

#define TRGMUX_3_GTM_159_156_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_159_156_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_159_156_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_159_156_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_159_156_SEL2_SHIFT)) & TRGMUX_3_GTM_159_156_SEL2_MASK)

#define TRGMUX_3_GTM_159_156_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_159_156_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_159_156_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_159_156_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_159_156_SEL3_SHIFT)) & TRGMUX_3_GTM_159_156_SEL3_MASK)

#define TRGMUX_3_GTM_159_156_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_159_156_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_159_156_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_159_156_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_159_156_LK_SHIFT)) & TRGMUX_3_GTM_159_156_LK_MASK)
/*! @} */

/*! @name GTM_163_160 - TRGMUX GTM_163_160 */
/*! @{ */

#define TRGMUX_3_GTM_163_160_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_163_160_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_163_160_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_163_160_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_163_160_SEL0_SHIFT)) & TRGMUX_3_GTM_163_160_SEL0_MASK)

#define TRGMUX_3_GTM_163_160_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_163_160_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_163_160_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_163_160_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_163_160_SEL1_SHIFT)) & TRGMUX_3_GTM_163_160_SEL1_MASK)

#define TRGMUX_3_GTM_163_160_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_163_160_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_163_160_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_163_160_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_163_160_SEL2_SHIFT)) & TRGMUX_3_GTM_163_160_SEL2_MASK)

#define TRGMUX_3_GTM_163_160_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_163_160_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_163_160_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_163_160_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_163_160_SEL3_SHIFT)) & TRGMUX_3_GTM_163_160_SEL3_MASK)

#define TRGMUX_3_GTM_163_160_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_163_160_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_163_160_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_163_160_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_163_160_LK_SHIFT)) & TRGMUX_3_GTM_163_160_LK_MASK)
/*! @} */

/*! @name GTM_167_164 - TRGMUX GTM_167_164 */
/*! @{ */

#define TRGMUX_3_GTM_167_164_SEL0_MASK           (0x7FU)
#define TRGMUX_3_GTM_167_164_SEL0_SHIFT          (0U)
#define TRGMUX_3_GTM_167_164_SEL0_WIDTH          (7U)
#define TRGMUX_3_GTM_167_164_SEL0(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_167_164_SEL0_SHIFT)) & TRGMUX_3_GTM_167_164_SEL0_MASK)

#define TRGMUX_3_GTM_167_164_SEL1_MASK           (0x7F00U)
#define TRGMUX_3_GTM_167_164_SEL1_SHIFT          (8U)
#define TRGMUX_3_GTM_167_164_SEL1_WIDTH          (7U)
#define TRGMUX_3_GTM_167_164_SEL1(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_167_164_SEL1_SHIFT)) & TRGMUX_3_GTM_167_164_SEL1_MASK)

#define TRGMUX_3_GTM_167_164_SEL2_MASK           (0x7F0000U)
#define TRGMUX_3_GTM_167_164_SEL2_SHIFT          (16U)
#define TRGMUX_3_GTM_167_164_SEL2_WIDTH          (7U)
#define TRGMUX_3_GTM_167_164_SEL2(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_167_164_SEL2_SHIFT)) & TRGMUX_3_GTM_167_164_SEL2_MASK)

#define TRGMUX_3_GTM_167_164_SEL3_MASK           (0x7F000000U)
#define TRGMUX_3_GTM_167_164_SEL3_SHIFT          (24U)
#define TRGMUX_3_GTM_167_164_SEL3_WIDTH          (7U)
#define TRGMUX_3_GTM_167_164_SEL3(x)             (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_167_164_SEL3_SHIFT)) & TRGMUX_3_GTM_167_164_SEL3_MASK)

#define TRGMUX_3_GTM_167_164_LK_MASK             (0x80000000U)
#define TRGMUX_3_GTM_167_164_LK_SHIFT            (31U)
#define TRGMUX_3_GTM_167_164_LK_WIDTH            (1U)
#define TRGMUX_3_GTM_167_164_LK(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_167_164_LK_SHIFT)) & TRGMUX_3_GTM_167_164_LK_MASK)
/*! @} */

/*! @name GTM_168 - TRGMUX GTM_168 */
/*! @{ */

#define TRGMUX_3_GTM_168_SEL0_MASK               (0x7FU)
#define TRGMUX_3_GTM_168_SEL0_SHIFT              (0U)
#define TRGMUX_3_GTM_168_SEL0_WIDTH              (7U)
#define TRGMUX_3_GTM_168_SEL0(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_168_SEL0_SHIFT)) & TRGMUX_3_GTM_168_SEL0_MASK)

#define TRGMUX_3_GTM_168_LK_MASK                 (0x80000000U)
#define TRGMUX_3_GTM_168_LK_SHIFT                (31U)
#define TRGMUX_3_GTM_168_LK_WIDTH                (1U)
#define TRGMUX_3_GTM_168_LK(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_GTM_168_LK_SHIFT)) & TRGMUX_3_GTM_168_LK_MASK)
/*! @} */

/*! @name MSC_03_00 - TRGMUX MSC_03_00 */
/*! @{ */

#define TRGMUX_3_MSC_03_00_SEL0_MASK             (0x7FU)
#define TRGMUX_3_MSC_03_00_SEL0_SHIFT            (0U)
#define TRGMUX_3_MSC_03_00_SEL0_WIDTH            (7U)
#define TRGMUX_3_MSC_03_00_SEL0(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_03_00_SEL0_SHIFT)) & TRGMUX_3_MSC_03_00_SEL0_MASK)

#define TRGMUX_3_MSC_03_00_SEL1_MASK             (0x7F00U)
#define TRGMUX_3_MSC_03_00_SEL1_SHIFT            (8U)
#define TRGMUX_3_MSC_03_00_SEL1_WIDTH            (7U)
#define TRGMUX_3_MSC_03_00_SEL1(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_03_00_SEL1_SHIFT)) & TRGMUX_3_MSC_03_00_SEL1_MASK)

#define TRGMUX_3_MSC_03_00_SEL2_MASK             (0x7F0000U)
#define TRGMUX_3_MSC_03_00_SEL2_SHIFT            (16U)
#define TRGMUX_3_MSC_03_00_SEL2_WIDTH            (7U)
#define TRGMUX_3_MSC_03_00_SEL2(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_03_00_SEL2_SHIFT)) & TRGMUX_3_MSC_03_00_SEL2_MASK)

#define TRGMUX_3_MSC_03_00_SEL3_MASK             (0x7F000000U)
#define TRGMUX_3_MSC_03_00_SEL3_SHIFT            (24U)
#define TRGMUX_3_MSC_03_00_SEL3_WIDTH            (7U)
#define TRGMUX_3_MSC_03_00_SEL3(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_03_00_SEL3_SHIFT)) & TRGMUX_3_MSC_03_00_SEL3_MASK)

#define TRGMUX_3_MSC_03_00_LK_MASK               (0x80000000U)
#define TRGMUX_3_MSC_03_00_LK_SHIFT              (31U)
#define TRGMUX_3_MSC_03_00_LK_WIDTH              (1U)
#define TRGMUX_3_MSC_03_00_LK(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_03_00_LK_SHIFT)) & TRGMUX_3_MSC_03_00_LK_MASK)
/*! @} */

/*! @name MSC_07_04 - TRGMUX MSC_07_04 */
/*! @{ */

#define TRGMUX_3_MSC_07_04_SEL0_MASK             (0x7FU)
#define TRGMUX_3_MSC_07_04_SEL0_SHIFT            (0U)
#define TRGMUX_3_MSC_07_04_SEL0_WIDTH            (7U)
#define TRGMUX_3_MSC_07_04_SEL0(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_07_04_SEL0_SHIFT)) & TRGMUX_3_MSC_07_04_SEL0_MASK)

#define TRGMUX_3_MSC_07_04_SEL1_MASK             (0x7F00U)
#define TRGMUX_3_MSC_07_04_SEL1_SHIFT            (8U)
#define TRGMUX_3_MSC_07_04_SEL1_WIDTH            (7U)
#define TRGMUX_3_MSC_07_04_SEL1(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_07_04_SEL1_SHIFT)) & TRGMUX_3_MSC_07_04_SEL1_MASK)

#define TRGMUX_3_MSC_07_04_SEL2_MASK             (0x7F0000U)
#define TRGMUX_3_MSC_07_04_SEL2_SHIFT            (16U)
#define TRGMUX_3_MSC_07_04_SEL2_WIDTH            (7U)
#define TRGMUX_3_MSC_07_04_SEL2(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_07_04_SEL2_SHIFT)) & TRGMUX_3_MSC_07_04_SEL2_MASK)

#define TRGMUX_3_MSC_07_04_SEL3_MASK             (0x7F000000U)
#define TRGMUX_3_MSC_07_04_SEL3_SHIFT            (24U)
#define TRGMUX_3_MSC_07_04_SEL3_WIDTH            (7U)
#define TRGMUX_3_MSC_07_04_SEL3(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_07_04_SEL3_SHIFT)) & TRGMUX_3_MSC_07_04_SEL3_MASK)

#define TRGMUX_3_MSC_07_04_LK_MASK               (0x80000000U)
#define TRGMUX_3_MSC_07_04_LK_SHIFT              (31U)
#define TRGMUX_3_MSC_07_04_LK_WIDTH              (1U)
#define TRGMUX_3_MSC_07_04_LK(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_07_04_LK_SHIFT)) & TRGMUX_3_MSC_07_04_LK_MASK)
/*! @} */

/*! @name MSC_11_08 - TRGMUX MSC_11_08 */
/*! @{ */

#define TRGMUX_3_MSC_11_08_SEL0_MASK             (0x7FU)
#define TRGMUX_3_MSC_11_08_SEL0_SHIFT            (0U)
#define TRGMUX_3_MSC_11_08_SEL0_WIDTH            (7U)
#define TRGMUX_3_MSC_11_08_SEL0(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_11_08_SEL0_SHIFT)) & TRGMUX_3_MSC_11_08_SEL0_MASK)

#define TRGMUX_3_MSC_11_08_SEL1_MASK             (0x7F00U)
#define TRGMUX_3_MSC_11_08_SEL1_SHIFT            (8U)
#define TRGMUX_3_MSC_11_08_SEL1_WIDTH            (7U)
#define TRGMUX_3_MSC_11_08_SEL1(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_11_08_SEL1_SHIFT)) & TRGMUX_3_MSC_11_08_SEL1_MASK)

#define TRGMUX_3_MSC_11_08_SEL2_MASK             (0x7F0000U)
#define TRGMUX_3_MSC_11_08_SEL2_SHIFT            (16U)
#define TRGMUX_3_MSC_11_08_SEL2_WIDTH            (7U)
#define TRGMUX_3_MSC_11_08_SEL2(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_11_08_SEL2_SHIFT)) & TRGMUX_3_MSC_11_08_SEL2_MASK)

#define TRGMUX_3_MSC_11_08_SEL3_MASK             (0x7F000000U)
#define TRGMUX_3_MSC_11_08_SEL3_SHIFT            (24U)
#define TRGMUX_3_MSC_11_08_SEL3_WIDTH            (7U)
#define TRGMUX_3_MSC_11_08_SEL3(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_11_08_SEL3_SHIFT)) & TRGMUX_3_MSC_11_08_SEL3_MASK)

#define TRGMUX_3_MSC_11_08_LK_MASK               (0x80000000U)
#define TRGMUX_3_MSC_11_08_LK_SHIFT              (31U)
#define TRGMUX_3_MSC_11_08_LK_WIDTH              (1U)
#define TRGMUX_3_MSC_11_08_LK(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_11_08_LK_SHIFT)) & TRGMUX_3_MSC_11_08_LK_MASK)
/*! @} */

/*! @name MSC_15_12 - TRGMUX MSC_15_12 */
/*! @{ */

#define TRGMUX_3_MSC_15_12_SEL0_MASK             (0x7FU)
#define TRGMUX_3_MSC_15_12_SEL0_SHIFT            (0U)
#define TRGMUX_3_MSC_15_12_SEL0_WIDTH            (7U)
#define TRGMUX_3_MSC_15_12_SEL0(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_15_12_SEL0_SHIFT)) & TRGMUX_3_MSC_15_12_SEL0_MASK)

#define TRGMUX_3_MSC_15_12_SEL1_MASK             (0x7F00U)
#define TRGMUX_3_MSC_15_12_SEL1_SHIFT            (8U)
#define TRGMUX_3_MSC_15_12_SEL1_WIDTH            (7U)
#define TRGMUX_3_MSC_15_12_SEL1(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_15_12_SEL1_SHIFT)) & TRGMUX_3_MSC_15_12_SEL1_MASK)

#define TRGMUX_3_MSC_15_12_SEL2_MASK             (0x7F0000U)
#define TRGMUX_3_MSC_15_12_SEL2_SHIFT            (16U)
#define TRGMUX_3_MSC_15_12_SEL2_WIDTH            (7U)
#define TRGMUX_3_MSC_15_12_SEL2(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_15_12_SEL2_SHIFT)) & TRGMUX_3_MSC_15_12_SEL2_MASK)

#define TRGMUX_3_MSC_15_12_SEL3_MASK             (0x7F000000U)
#define TRGMUX_3_MSC_15_12_SEL3_SHIFT            (24U)
#define TRGMUX_3_MSC_15_12_SEL3_WIDTH            (7U)
#define TRGMUX_3_MSC_15_12_SEL3(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_15_12_SEL3_SHIFT)) & TRGMUX_3_MSC_15_12_SEL3_MASK)

#define TRGMUX_3_MSC_15_12_LK_MASK               (0x80000000U)
#define TRGMUX_3_MSC_15_12_LK_SHIFT              (31U)
#define TRGMUX_3_MSC_15_12_LK_WIDTH              (1U)
#define TRGMUX_3_MSC_15_12_LK(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_15_12_LK_SHIFT)) & TRGMUX_3_MSC_15_12_LK_MASK)
/*! @} */

/*! @name MSC_19_16 - TRGMUX MSC_19_16 */
/*! @{ */

#define TRGMUX_3_MSC_19_16_SEL0_MASK             (0x7FU)
#define TRGMUX_3_MSC_19_16_SEL0_SHIFT            (0U)
#define TRGMUX_3_MSC_19_16_SEL0_WIDTH            (7U)
#define TRGMUX_3_MSC_19_16_SEL0(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_19_16_SEL0_SHIFT)) & TRGMUX_3_MSC_19_16_SEL0_MASK)

#define TRGMUX_3_MSC_19_16_SEL1_MASK             (0x7F00U)
#define TRGMUX_3_MSC_19_16_SEL1_SHIFT            (8U)
#define TRGMUX_3_MSC_19_16_SEL1_WIDTH            (7U)
#define TRGMUX_3_MSC_19_16_SEL1(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_19_16_SEL1_SHIFT)) & TRGMUX_3_MSC_19_16_SEL1_MASK)

#define TRGMUX_3_MSC_19_16_SEL2_MASK             (0x7F0000U)
#define TRGMUX_3_MSC_19_16_SEL2_SHIFT            (16U)
#define TRGMUX_3_MSC_19_16_SEL2_WIDTH            (7U)
#define TRGMUX_3_MSC_19_16_SEL2(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_19_16_SEL2_SHIFT)) & TRGMUX_3_MSC_19_16_SEL2_MASK)

#define TRGMUX_3_MSC_19_16_SEL3_MASK             (0x7F000000U)
#define TRGMUX_3_MSC_19_16_SEL3_SHIFT            (24U)
#define TRGMUX_3_MSC_19_16_SEL3_WIDTH            (7U)
#define TRGMUX_3_MSC_19_16_SEL3(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_19_16_SEL3_SHIFT)) & TRGMUX_3_MSC_19_16_SEL3_MASK)

#define TRGMUX_3_MSC_19_16_LK_MASK               (0x80000000U)
#define TRGMUX_3_MSC_19_16_LK_SHIFT              (31U)
#define TRGMUX_3_MSC_19_16_LK_WIDTH              (1U)
#define TRGMUX_3_MSC_19_16_LK(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_19_16_LK_SHIFT)) & TRGMUX_3_MSC_19_16_LK_MASK)
/*! @} */

/*! @name MSC_23_20 - TRGMUX MSC_23_20 */
/*! @{ */

#define TRGMUX_3_MSC_23_20_SEL0_MASK             (0x7FU)
#define TRGMUX_3_MSC_23_20_SEL0_SHIFT            (0U)
#define TRGMUX_3_MSC_23_20_SEL0_WIDTH            (7U)
#define TRGMUX_3_MSC_23_20_SEL0(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_23_20_SEL0_SHIFT)) & TRGMUX_3_MSC_23_20_SEL0_MASK)

#define TRGMUX_3_MSC_23_20_SEL1_MASK             (0x7F00U)
#define TRGMUX_3_MSC_23_20_SEL1_SHIFT            (8U)
#define TRGMUX_3_MSC_23_20_SEL1_WIDTH            (7U)
#define TRGMUX_3_MSC_23_20_SEL1(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_23_20_SEL1_SHIFT)) & TRGMUX_3_MSC_23_20_SEL1_MASK)

#define TRGMUX_3_MSC_23_20_SEL2_MASK             (0x7F0000U)
#define TRGMUX_3_MSC_23_20_SEL2_SHIFT            (16U)
#define TRGMUX_3_MSC_23_20_SEL2_WIDTH            (7U)
#define TRGMUX_3_MSC_23_20_SEL2(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_23_20_SEL2_SHIFT)) & TRGMUX_3_MSC_23_20_SEL2_MASK)

#define TRGMUX_3_MSC_23_20_SEL3_MASK             (0x7F000000U)
#define TRGMUX_3_MSC_23_20_SEL3_SHIFT            (24U)
#define TRGMUX_3_MSC_23_20_SEL3_WIDTH            (7U)
#define TRGMUX_3_MSC_23_20_SEL3(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_23_20_SEL3_SHIFT)) & TRGMUX_3_MSC_23_20_SEL3_MASK)

#define TRGMUX_3_MSC_23_20_LK_MASK               (0x80000000U)
#define TRGMUX_3_MSC_23_20_LK_SHIFT              (31U)
#define TRGMUX_3_MSC_23_20_LK_WIDTH              (1U)
#define TRGMUX_3_MSC_23_20_LK(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_23_20_LK_SHIFT)) & TRGMUX_3_MSC_23_20_LK_MASK)
/*! @} */

/*! @name MSC_27_24 - TRGMUX MSC_27_24 */
/*! @{ */

#define TRGMUX_3_MSC_27_24_SEL0_MASK             (0x7FU)
#define TRGMUX_3_MSC_27_24_SEL0_SHIFT            (0U)
#define TRGMUX_3_MSC_27_24_SEL0_WIDTH            (7U)
#define TRGMUX_3_MSC_27_24_SEL0(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_27_24_SEL0_SHIFT)) & TRGMUX_3_MSC_27_24_SEL0_MASK)

#define TRGMUX_3_MSC_27_24_SEL1_MASK             (0x7F00U)
#define TRGMUX_3_MSC_27_24_SEL1_SHIFT            (8U)
#define TRGMUX_3_MSC_27_24_SEL1_WIDTH            (7U)
#define TRGMUX_3_MSC_27_24_SEL1(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_27_24_SEL1_SHIFT)) & TRGMUX_3_MSC_27_24_SEL1_MASK)

#define TRGMUX_3_MSC_27_24_SEL2_MASK             (0x7F0000U)
#define TRGMUX_3_MSC_27_24_SEL2_SHIFT            (16U)
#define TRGMUX_3_MSC_27_24_SEL2_WIDTH            (7U)
#define TRGMUX_3_MSC_27_24_SEL2(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_27_24_SEL2_SHIFT)) & TRGMUX_3_MSC_27_24_SEL2_MASK)

#define TRGMUX_3_MSC_27_24_SEL3_MASK             (0x7F000000U)
#define TRGMUX_3_MSC_27_24_SEL3_SHIFT            (24U)
#define TRGMUX_3_MSC_27_24_SEL3_WIDTH            (7U)
#define TRGMUX_3_MSC_27_24_SEL3(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_27_24_SEL3_SHIFT)) & TRGMUX_3_MSC_27_24_SEL3_MASK)

#define TRGMUX_3_MSC_27_24_LK_MASK               (0x80000000U)
#define TRGMUX_3_MSC_27_24_LK_SHIFT              (31U)
#define TRGMUX_3_MSC_27_24_LK_WIDTH              (1U)
#define TRGMUX_3_MSC_27_24_LK(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_27_24_LK_SHIFT)) & TRGMUX_3_MSC_27_24_LK_MASK)
/*! @} */

/*! @name MSC_31_28 - TRGMUX MSC_31_28 */
/*! @{ */

#define TRGMUX_3_MSC_31_28_SEL0_MASK             (0x7FU)
#define TRGMUX_3_MSC_31_28_SEL0_SHIFT            (0U)
#define TRGMUX_3_MSC_31_28_SEL0_WIDTH            (7U)
#define TRGMUX_3_MSC_31_28_SEL0(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_31_28_SEL0_SHIFT)) & TRGMUX_3_MSC_31_28_SEL0_MASK)

#define TRGMUX_3_MSC_31_28_SEL1_MASK             (0x7F00U)
#define TRGMUX_3_MSC_31_28_SEL1_SHIFT            (8U)
#define TRGMUX_3_MSC_31_28_SEL1_WIDTH            (7U)
#define TRGMUX_3_MSC_31_28_SEL1(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_31_28_SEL1_SHIFT)) & TRGMUX_3_MSC_31_28_SEL1_MASK)

#define TRGMUX_3_MSC_31_28_SEL2_MASK             (0x7F0000U)
#define TRGMUX_3_MSC_31_28_SEL2_SHIFT            (16U)
#define TRGMUX_3_MSC_31_28_SEL2_WIDTH            (7U)
#define TRGMUX_3_MSC_31_28_SEL2(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_31_28_SEL2_SHIFT)) & TRGMUX_3_MSC_31_28_SEL2_MASK)

#define TRGMUX_3_MSC_31_28_SEL3_MASK             (0x7F000000U)
#define TRGMUX_3_MSC_31_28_SEL3_SHIFT            (24U)
#define TRGMUX_3_MSC_31_28_SEL3_WIDTH            (7U)
#define TRGMUX_3_MSC_31_28_SEL3(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_31_28_SEL3_SHIFT)) & TRGMUX_3_MSC_31_28_SEL3_MASK)

#define TRGMUX_3_MSC_31_28_LK_MASK               (0x80000000U)
#define TRGMUX_3_MSC_31_28_LK_SHIFT              (31U)
#define TRGMUX_3_MSC_31_28_LK_WIDTH              (1U)
#define TRGMUX_3_MSC_31_28_LK(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_31_28_LK_SHIFT)) & TRGMUX_3_MSC_31_28_LK_MASK)
/*! @} */

/*! @name MSC_35_32 - TRGMUX MSC_35_32 */
/*! @{ */

#define TRGMUX_3_MSC_35_32_SEL0_MASK             (0x7FU)
#define TRGMUX_3_MSC_35_32_SEL0_SHIFT            (0U)
#define TRGMUX_3_MSC_35_32_SEL0_WIDTH            (7U)
#define TRGMUX_3_MSC_35_32_SEL0(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_35_32_SEL0_SHIFT)) & TRGMUX_3_MSC_35_32_SEL0_MASK)

#define TRGMUX_3_MSC_35_32_SEL1_MASK             (0x7F00U)
#define TRGMUX_3_MSC_35_32_SEL1_SHIFT            (8U)
#define TRGMUX_3_MSC_35_32_SEL1_WIDTH            (7U)
#define TRGMUX_3_MSC_35_32_SEL1(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_35_32_SEL1_SHIFT)) & TRGMUX_3_MSC_35_32_SEL1_MASK)

#define TRGMUX_3_MSC_35_32_SEL2_MASK             (0x7F0000U)
#define TRGMUX_3_MSC_35_32_SEL2_SHIFT            (16U)
#define TRGMUX_3_MSC_35_32_SEL2_WIDTH            (7U)
#define TRGMUX_3_MSC_35_32_SEL2(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_35_32_SEL2_SHIFT)) & TRGMUX_3_MSC_35_32_SEL2_MASK)

#define TRGMUX_3_MSC_35_32_SEL3_MASK             (0x7F000000U)
#define TRGMUX_3_MSC_35_32_SEL3_SHIFT            (24U)
#define TRGMUX_3_MSC_35_32_SEL3_WIDTH            (7U)
#define TRGMUX_3_MSC_35_32_SEL3(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_35_32_SEL3_SHIFT)) & TRGMUX_3_MSC_35_32_SEL3_MASK)

#define TRGMUX_3_MSC_35_32_LK_MASK               (0x80000000U)
#define TRGMUX_3_MSC_35_32_LK_SHIFT              (31U)
#define TRGMUX_3_MSC_35_32_LK_WIDTH              (1U)
#define TRGMUX_3_MSC_35_32_LK(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_35_32_LK_SHIFT)) & TRGMUX_3_MSC_35_32_LK_MASK)
/*! @} */

/*! @name MSC_39_36 - TRGMUX MSC_39_36 */
/*! @{ */

#define TRGMUX_3_MSC_39_36_SEL0_MASK             (0x7FU)
#define TRGMUX_3_MSC_39_36_SEL0_SHIFT            (0U)
#define TRGMUX_3_MSC_39_36_SEL0_WIDTH            (7U)
#define TRGMUX_3_MSC_39_36_SEL0(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_39_36_SEL0_SHIFT)) & TRGMUX_3_MSC_39_36_SEL0_MASK)

#define TRGMUX_3_MSC_39_36_SEL1_MASK             (0x7F00U)
#define TRGMUX_3_MSC_39_36_SEL1_SHIFT            (8U)
#define TRGMUX_3_MSC_39_36_SEL1_WIDTH            (7U)
#define TRGMUX_3_MSC_39_36_SEL1(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_39_36_SEL1_SHIFT)) & TRGMUX_3_MSC_39_36_SEL1_MASK)

#define TRGMUX_3_MSC_39_36_SEL2_MASK             (0x7F0000U)
#define TRGMUX_3_MSC_39_36_SEL2_SHIFT            (16U)
#define TRGMUX_3_MSC_39_36_SEL2_WIDTH            (7U)
#define TRGMUX_3_MSC_39_36_SEL2(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_39_36_SEL2_SHIFT)) & TRGMUX_3_MSC_39_36_SEL2_MASK)

#define TRGMUX_3_MSC_39_36_SEL3_MASK             (0x7F000000U)
#define TRGMUX_3_MSC_39_36_SEL3_SHIFT            (24U)
#define TRGMUX_3_MSC_39_36_SEL3_WIDTH            (7U)
#define TRGMUX_3_MSC_39_36_SEL3(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_39_36_SEL3_SHIFT)) & TRGMUX_3_MSC_39_36_SEL3_MASK)

#define TRGMUX_3_MSC_39_36_LK_MASK               (0x80000000U)
#define TRGMUX_3_MSC_39_36_LK_SHIFT              (31U)
#define TRGMUX_3_MSC_39_36_LK_WIDTH              (1U)
#define TRGMUX_3_MSC_39_36_LK(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_39_36_LK_SHIFT)) & TRGMUX_3_MSC_39_36_LK_MASK)
/*! @} */

/*! @name MSC_43_40 - TRGMUX MSC_43_40 */
/*! @{ */

#define TRGMUX_3_MSC_43_40_SEL0_MASK             (0x7FU)
#define TRGMUX_3_MSC_43_40_SEL0_SHIFT            (0U)
#define TRGMUX_3_MSC_43_40_SEL0_WIDTH            (7U)
#define TRGMUX_3_MSC_43_40_SEL0(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_43_40_SEL0_SHIFT)) & TRGMUX_3_MSC_43_40_SEL0_MASK)

#define TRGMUX_3_MSC_43_40_SEL1_MASK             (0x7F00U)
#define TRGMUX_3_MSC_43_40_SEL1_SHIFT            (8U)
#define TRGMUX_3_MSC_43_40_SEL1_WIDTH            (7U)
#define TRGMUX_3_MSC_43_40_SEL1(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_43_40_SEL1_SHIFT)) & TRGMUX_3_MSC_43_40_SEL1_MASK)

#define TRGMUX_3_MSC_43_40_SEL2_MASK             (0x7F0000U)
#define TRGMUX_3_MSC_43_40_SEL2_SHIFT            (16U)
#define TRGMUX_3_MSC_43_40_SEL2_WIDTH            (7U)
#define TRGMUX_3_MSC_43_40_SEL2(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_43_40_SEL2_SHIFT)) & TRGMUX_3_MSC_43_40_SEL2_MASK)

#define TRGMUX_3_MSC_43_40_SEL3_MASK             (0x7F000000U)
#define TRGMUX_3_MSC_43_40_SEL3_SHIFT            (24U)
#define TRGMUX_3_MSC_43_40_SEL3_WIDTH            (7U)
#define TRGMUX_3_MSC_43_40_SEL3(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_43_40_SEL3_SHIFT)) & TRGMUX_3_MSC_43_40_SEL3_MASK)

#define TRGMUX_3_MSC_43_40_LK_MASK               (0x80000000U)
#define TRGMUX_3_MSC_43_40_LK_SHIFT              (31U)
#define TRGMUX_3_MSC_43_40_LK_WIDTH              (1U)
#define TRGMUX_3_MSC_43_40_LK(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_43_40_LK_SHIFT)) & TRGMUX_3_MSC_43_40_LK_MASK)
/*! @} */

/*! @name MSC_47_44 - TRGMUX MSC_47_44 */
/*! @{ */

#define TRGMUX_3_MSC_47_44_SEL0_MASK             (0x7FU)
#define TRGMUX_3_MSC_47_44_SEL0_SHIFT            (0U)
#define TRGMUX_3_MSC_47_44_SEL0_WIDTH            (7U)
#define TRGMUX_3_MSC_47_44_SEL0(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_47_44_SEL0_SHIFT)) & TRGMUX_3_MSC_47_44_SEL0_MASK)

#define TRGMUX_3_MSC_47_44_SEL1_MASK             (0x7F00U)
#define TRGMUX_3_MSC_47_44_SEL1_SHIFT            (8U)
#define TRGMUX_3_MSC_47_44_SEL1_WIDTH            (7U)
#define TRGMUX_3_MSC_47_44_SEL1(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_47_44_SEL1_SHIFT)) & TRGMUX_3_MSC_47_44_SEL1_MASK)

#define TRGMUX_3_MSC_47_44_SEL2_MASK             (0x7F0000U)
#define TRGMUX_3_MSC_47_44_SEL2_SHIFT            (16U)
#define TRGMUX_3_MSC_47_44_SEL2_WIDTH            (7U)
#define TRGMUX_3_MSC_47_44_SEL2(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_47_44_SEL2_SHIFT)) & TRGMUX_3_MSC_47_44_SEL2_MASK)

#define TRGMUX_3_MSC_47_44_SEL3_MASK             (0x7F000000U)
#define TRGMUX_3_MSC_47_44_SEL3_SHIFT            (24U)
#define TRGMUX_3_MSC_47_44_SEL3_WIDTH            (7U)
#define TRGMUX_3_MSC_47_44_SEL3(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_47_44_SEL3_SHIFT)) & TRGMUX_3_MSC_47_44_SEL3_MASK)

#define TRGMUX_3_MSC_47_44_LK_MASK               (0x80000000U)
#define TRGMUX_3_MSC_47_44_LK_SHIFT              (31U)
#define TRGMUX_3_MSC_47_44_LK_WIDTH              (1U)
#define TRGMUX_3_MSC_47_44_LK(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_47_44_LK_SHIFT)) & TRGMUX_3_MSC_47_44_LK_MASK)
/*! @} */

/*! @name MSC_51_48 - TRGMUX MSC_51_48 */
/*! @{ */

#define TRGMUX_3_MSC_51_48_SEL0_MASK             (0x7FU)
#define TRGMUX_3_MSC_51_48_SEL0_SHIFT            (0U)
#define TRGMUX_3_MSC_51_48_SEL0_WIDTH            (7U)
#define TRGMUX_3_MSC_51_48_SEL0(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_51_48_SEL0_SHIFT)) & TRGMUX_3_MSC_51_48_SEL0_MASK)

#define TRGMUX_3_MSC_51_48_SEL1_MASK             (0x7F00U)
#define TRGMUX_3_MSC_51_48_SEL1_SHIFT            (8U)
#define TRGMUX_3_MSC_51_48_SEL1_WIDTH            (7U)
#define TRGMUX_3_MSC_51_48_SEL1(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_51_48_SEL1_SHIFT)) & TRGMUX_3_MSC_51_48_SEL1_MASK)

#define TRGMUX_3_MSC_51_48_SEL2_MASK             (0x7F0000U)
#define TRGMUX_3_MSC_51_48_SEL2_SHIFT            (16U)
#define TRGMUX_3_MSC_51_48_SEL2_WIDTH            (7U)
#define TRGMUX_3_MSC_51_48_SEL2(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_51_48_SEL2_SHIFT)) & TRGMUX_3_MSC_51_48_SEL2_MASK)

#define TRGMUX_3_MSC_51_48_SEL3_MASK             (0x7F000000U)
#define TRGMUX_3_MSC_51_48_SEL3_SHIFT            (24U)
#define TRGMUX_3_MSC_51_48_SEL3_WIDTH            (7U)
#define TRGMUX_3_MSC_51_48_SEL3(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_51_48_SEL3_SHIFT)) & TRGMUX_3_MSC_51_48_SEL3_MASK)

#define TRGMUX_3_MSC_51_48_LK_MASK               (0x80000000U)
#define TRGMUX_3_MSC_51_48_LK_SHIFT              (31U)
#define TRGMUX_3_MSC_51_48_LK_WIDTH              (1U)
#define TRGMUX_3_MSC_51_48_LK(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_51_48_LK_SHIFT)) & TRGMUX_3_MSC_51_48_LK_MASK)
/*! @} */

/*! @name MSC_55_52 - TRGMUX MSC_55_52 */
/*! @{ */

#define TRGMUX_3_MSC_55_52_SEL0_MASK             (0x7FU)
#define TRGMUX_3_MSC_55_52_SEL0_SHIFT            (0U)
#define TRGMUX_3_MSC_55_52_SEL0_WIDTH            (7U)
#define TRGMUX_3_MSC_55_52_SEL0(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_55_52_SEL0_SHIFT)) & TRGMUX_3_MSC_55_52_SEL0_MASK)

#define TRGMUX_3_MSC_55_52_SEL1_MASK             (0x7F00U)
#define TRGMUX_3_MSC_55_52_SEL1_SHIFT            (8U)
#define TRGMUX_3_MSC_55_52_SEL1_WIDTH            (7U)
#define TRGMUX_3_MSC_55_52_SEL1(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_55_52_SEL1_SHIFT)) & TRGMUX_3_MSC_55_52_SEL1_MASK)

#define TRGMUX_3_MSC_55_52_SEL2_MASK             (0x7F0000U)
#define TRGMUX_3_MSC_55_52_SEL2_SHIFT            (16U)
#define TRGMUX_3_MSC_55_52_SEL2_WIDTH            (7U)
#define TRGMUX_3_MSC_55_52_SEL2(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_55_52_SEL2_SHIFT)) & TRGMUX_3_MSC_55_52_SEL2_MASK)

#define TRGMUX_3_MSC_55_52_SEL3_MASK             (0x7F000000U)
#define TRGMUX_3_MSC_55_52_SEL3_SHIFT            (24U)
#define TRGMUX_3_MSC_55_52_SEL3_WIDTH            (7U)
#define TRGMUX_3_MSC_55_52_SEL3(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_55_52_SEL3_SHIFT)) & TRGMUX_3_MSC_55_52_SEL3_MASK)

#define TRGMUX_3_MSC_55_52_LK_MASK               (0x80000000U)
#define TRGMUX_3_MSC_55_52_LK_SHIFT              (31U)
#define TRGMUX_3_MSC_55_52_LK_WIDTH              (1U)
#define TRGMUX_3_MSC_55_52_LK(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_55_52_LK_SHIFT)) & TRGMUX_3_MSC_55_52_LK_MASK)
/*! @} */

/*! @name MSC_59_56 - TRGMUX MSC_59_56 */
/*! @{ */

#define TRGMUX_3_MSC_59_56_SEL0_MASK             (0x7FU)
#define TRGMUX_3_MSC_59_56_SEL0_SHIFT            (0U)
#define TRGMUX_3_MSC_59_56_SEL0_WIDTH            (7U)
#define TRGMUX_3_MSC_59_56_SEL0(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_59_56_SEL0_SHIFT)) & TRGMUX_3_MSC_59_56_SEL0_MASK)

#define TRGMUX_3_MSC_59_56_SEL1_MASK             (0x7F00U)
#define TRGMUX_3_MSC_59_56_SEL1_SHIFT            (8U)
#define TRGMUX_3_MSC_59_56_SEL1_WIDTH            (7U)
#define TRGMUX_3_MSC_59_56_SEL1(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_59_56_SEL1_SHIFT)) & TRGMUX_3_MSC_59_56_SEL1_MASK)

#define TRGMUX_3_MSC_59_56_SEL2_MASK             (0x7F0000U)
#define TRGMUX_3_MSC_59_56_SEL2_SHIFT            (16U)
#define TRGMUX_3_MSC_59_56_SEL2_WIDTH            (7U)
#define TRGMUX_3_MSC_59_56_SEL2(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_59_56_SEL2_SHIFT)) & TRGMUX_3_MSC_59_56_SEL2_MASK)

#define TRGMUX_3_MSC_59_56_SEL3_MASK             (0x7F000000U)
#define TRGMUX_3_MSC_59_56_SEL3_SHIFT            (24U)
#define TRGMUX_3_MSC_59_56_SEL3_WIDTH            (7U)
#define TRGMUX_3_MSC_59_56_SEL3(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_59_56_SEL3_SHIFT)) & TRGMUX_3_MSC_59_56_SEL3_MASK)

#define TRGMUX_3_MSC_59_56_LK_MASK               (0x80000000U)
#define TRGMUX_3_MSC_59_56_LK_SHIFT              (31U)
#define TRGMUX_3_MSC_59_56_LK_WIDTH              (1U)
#define TRGMUX_3_MSC_59_56_LK(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_59_56_LK_SHIFT)) & TRGMUX_3_MSC_59_56_LK_MASK)
/*! @} */

/*! @name MSC_63_60 - TRGMUX MSC_63_60 */
/*! @{ */

#define TRGMUX_3_MSC_63_60_SEL0_MASK             (0x7FU)
#define TRGMUX_3_MSC_63_60_SEL0_SHIFT            (0U)
#define TRGMUX_3_MSC_63_60_SEL0_WIDTH            (7U)
#define TRGMUX_3_MSC_63_60_SEL0(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_63_60_SEL0_SHIFT)) & TRGMUX_3_MSC_63_60_SEL0_MASK)

#define TRGMUX_3_MSC_63_60_SEL1_MASK             (0x7F00U)
#define TRGMUX_3_MSC_63_60_SEL1_SHIFT            (8U)
#define TRGMUX_3_MSC_63_60_SEL1_WIDTH            (7U)
#define TRGMUX_3_MSC_63_60_SEL1(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_63_60_SEL1_SHIFT)) & TRGMUX_3_MSC_63_60_SEL1_MASK)

#define TRGMUX_3_MSC_63_60_SEL2_MASK             (0x7F0000U)
#define TRGMUX_3_MSC_63_60_SEL2_SHIFT            (16U)
#define TRGMUX_3_MSC_63_60_SEL2_WIDTH            (7U)
#define TRGMUX_3_MSC_63_60_SEL2(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_63_60_SEL2_SHIFT)) & TRGMUX_3_MSC_63_60_SEL2_MASK)

#define TRGMUX_3_MSC_63_60_SEL3_MASK             (0x7F000000U)
#define TRGMUX_3_MSC_63_60_SEL3_SHIFT            (24U)
#define TRGMUX_3_MSC_63_60_SEL3_WIDTH            (7U)
#define TRGMUX_3_MSC_63_60_SEL3(x)               (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_63_60_SEL3_SHIFT)) & TRGMUX_3_MSC_63_60_SEL3_MASK)

#define TRGMUX_3_MSC_63_60_LK_MASK               (0x80000000U)
#define TRGMUX_3_MSC_63_60_LK_SHIFT              (31U)
#define TRGMUX_3_MSC_63_60_LK_WIDTH              (1U)
#define TRGMUX_3_MSC_63_60_LK(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_MSC_63_60_LK_SHIFT)) & TRGMUX_3_MSC_63_60_LK_MASK)
/*! @} */

/*! @name CTU_3_0 - TRGMUX CTU_3_0 */
/*! @{ */

#define TRGMUX_3_CTU_3_0_SEL0_MASK               (0x7FU)
#define TRGMUX_3_CTU_3_0_SEL0_SHIFT              (0U)
#define TRGMUX_3_CTU_3_0_SEL0_WIDTH              (7U)
#define TRGMUX_3_CTU_3_0_SEL0(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_CTU_3_0_SEL0_SHIFT)) & TRGMUX_3_CTU_3_0_SEL0_MASK)

#define TRGMUX_3_CTU_3_0_SEL1_MASK               (0x7F00U)
#define TRGMUX_3_CTU_3_0_SEL1_SHIFT              (8U)
#define TRGMUX_3_CTU_3_0_SEL1_WIDTH              (7U)
#define TRGMUX_3_CTU_3_0_SEL1(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_CTU_3_0_SEL1_SHIFT)) & TRGMUX_3_CTU_3_0_SEL1_MASK)

#define TRGMUX_3_CTU_3_0_SEL2_MASK               (0x7F0000U)
#define TRGMUX_3_CTU_3_0_SEL2_SHIFT              (16U)
#define TRGMUX_3_CTU_3_0_SEL2_WIDTH              (7U)
#define TRGMUX_3_CTU_3_0_SEL2(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_CTU_3_0_SEL2_SHIFT)) & TRGMUX_3_CTU_3_0_SEL2_MASK)

#define TRGMUX_3_CTU_3_0_SEL3_MASK               (0x7F000000U)
#define TRGMUX_3_CTU_3_0_SEL3_SHIFT              (24U)
#define TRGMUX_3_CTU_3_0_SEL3_WIDTH              (7U)
#define TRGMUX_3_CTU_3_0_SEL3(x)                 (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_CTU_3_0_SEL3_SHIFT)) & TRGMUX_3_CTU_3_0_SEL3_MASK)

#define TRGMUX_3_CTU_3_0_LK_MASK                 (0x80000000U)
#define TRGMUX_3_CTU_3_0_LK_SHIFT                (31U)
#define TRGMUX_3_CTU_3_0_LK_WIDTH                (1U)
#define TRGMUX_3_CTU_3_0_LK(x)                   (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_CTU_3_0_LK_SHIFT)) & TRGMUX_3_CTU_3_0_LK_MASK)
/*! @} */

/*! @name SINC_3_0 - TRGMUX SINC_3_0 */
/*! @{ */

#define TRGMUX_3_SINC_3_0_SEL0_MASK              (0x7FU)
#define TRGMUX_3_SINC_3_0_SEL0_SHIFT             (0U)
#define TRGMUX_3_SINC_3_0_SEL0_WIDTH             (7U)
#define TRGMUX_3_SINC_3_0_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_SINC_3_0_SEL0_SHIFT)) & TRGMUX_3_SINC_3_0_SEL0_MASK)

#define TRGMUX_3_SINC_3_0_SEL1_MASK              (0x7F00U)
#define TRGMUX_3_SINC_3_0_SEL1_SHIFT             (8U)
#define TRGMUX_3_SINC_3_0_SEL1_WIDTH             (7U)
#define TRGMUX_3_SINC_3_0_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_SINC_3_0_SEL1_SHIFT)) & TRGMUX_3_SINC_3_0_SEL1_MASK)

#define TRGMUX_3_SINC_3_0_SEL2_MASK              (0x7F0000U)
#define TRGMUX_3_SINC_3_0_SEL2_SHIFT             (16U)
#define TRGMUX_3_SINC_3_0_SEL2_WIDTH             (7U)
#define TRGMUX_3_SINC_3_0_SEL2(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_SINC_3_0_SEL2_SHIFT)) & TRGMUX_3_SINC_3_0_SEL2_MASK)

#define TRGMUX_3_SINC_3_0_SEL3_MASK              (0x7F000000U)
#define TRGMUX_3_SINC_3_0_SEL3_SHIFT             (24U)
#define TRGMUX_3_SINC_3_0_SEL3_WIDTH             (7U)
#define TRGMUX_3_SINC_3_0_SEL3(x)                (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_SINC_3_0_SEL3_SHIFT)) & TRGMUX_3_SINC_3_0_SEL3_MASK)

#define TRGMUX_3_SINC_3_0_LK_MASK                (0x80000000U)
#define TRGMUX_3_SINC_3_0_LK_SHIFT               (31U)
#define TRGMUX_3_SINC_3_0_LK_WIDTH               (1U)
#define TRGMUX_3_SINC_3_0_LK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGMUX_3_SINC_3_0_LK_SHIFT)) & TRGMUX_3_SINC_3_0_LK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group TRGMUX_3_Register_Masks */

/*!
 * @}
 */ /* end of group TRGMUX_3_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_TRGMUX_3_H_) */
