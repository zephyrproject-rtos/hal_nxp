/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_EIM.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_EIM
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
#if !defined(S32K566_EIM_H_)  /* Check if memory map has not been already included */
#define S32K566_EIM_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- EIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EIM_Peripheral_Access_Layer EIM Peripheral Access Layer
 * @{
 */

/** EIM - Register Layout Typedef */
typedef struct EIM_Struct {
  __IO uint32_t EIMCR;                             /**< Error Injection Module Configuration Register, offset: 0x0 */
  __IO uint32_t EICHEN;                            /**< Error Injection Channel Enable register, offset: 0x4 */
  uint8_t RESERVED_0[248];
  __IO uint32_t EICHD0_WORD0;                      /**< Error Injection Channel Descriptor 0, Word0, offset: 0x100, available only on: EIM_2, LPE_EIM (missing on CPE_EIM, EIM_0, EIM_3) */
  __IO uint32_t EICHD0_WORD1;                      /**< Error Injection Channel Descriptor 0, Word1, offset: 0x104 */
  __IO uint32_t EICHD0_WORD2;                      /**< Error Injection Channel Descriptor 0, Word2, offset: 0x108, available only on: CPE_EIM, EIM_2, EIM_3 (missing on EIM_0, LPE_EIM) */
  uint8_t RESERVED_1[52];
  __IO uint32_t EICHD1_WORD0;                      /**< Error Injection Channel Descriptor 1, Word0, offset: 0x140, available only on: EIM_2, LPE_EIM (missing on CPE_EIM, EIM_0, EIM_3) */
  __IO uint32_t EICHD1_WORD1;                      /**< Error Injection Channel Descriptor 1, Word1, offset: 0x144 */
  __IO uint32_t EICHD1_WORD2;                      /**< Error Injection Channel Descriptor 1, Word2, offset: 0x148, available only on: EIM_2, EIM_3 (missing on CPE_EIM, EIM_0, LPE_EIM) */
  __IO uint32_t EICHD1_WORD3;                      /**< Error Injection Channel Descriptor 1, Word3, offset: 0x14C, available only on: EIM_2 (missing on CPE_EIM, EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD1_WORD4;                      /**< Error Injection Channel Descriptor 1, Word4, offset: 0x150, available only on: EIM_2 (missing on CPE_EIM, EIM_0, EIM_3, LPE_EIM) */
  uint8_t RESERVED_2[44];
  __IO uint32_t EICHD2_WORD0;                      /**< Error Injection Channel Descriptor 2, Word0, offset: 0x180, available only on: EIM_2, LPE_EIM (missing on CPE_EIM, EIM_0, EIM_3) */
  __IO uint32_t EICHD2_WORD1;                      /**< Error Injection Channel Descriptor 2, Word1, offset: 0x184 */
  __IO uint32_t EICHD2_WORD2;                      /**< Error Injection Channel Descriptor 2, Word2, offset: 0x188, available only on: EIM_2, EIM_3, LPE_EIM (missing on CPE_EIM, EIM_0) */
  __IO uint32_t EICHD2_WORD3;                      /**< Error Injection Channel Descriptor 2, Word3, offset: 0x18C, available only on: EIM_2 (missing on CPE_EIM, EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD2_WORD4;                      /**< Error Injection Channel Descriptor 2, Word4, offset: 0x190, available only on: EIM_2 (missing on CPE_EIM, EIM_0, EIM_3, LPE_EIM) */
  uint8_t RESERVED_3[44];
  __IO uint32_t EICHD3_WORD0;                      /**< Error Injection Channel Descriptor 3, Word0, offset: 0x1C0, available only on: EIM_2, LPE_EIM (missing on CPE_EIM, EIM_0, EIM_3) */
  __IO uint32_t EICHD3_WORD1;                      /**< Error Injection Channel Descriptor 3, Word1, offset: 0x1C4 */
  __IO uint32_t EICHD3_WORD2;                      /**< Error Injection Channel Descriptor 3, Word2, offset: 0x1C8, available only on: EIM_0, EIM_2, EIM_3, LPE_EIM (missing on CPE_EIM) */
  __IO uint32_t EICHD3_WORD3;                      /**< Error Injection Channel Descriptor 3, Word3, offset: 0x1CC, available only on: EIM_2 (missing on CPE_EIM, EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD3_WORD4;                      /**< Error Injection Channel Descriptor 3, Word4, offset: 0x1D0, available only on: EIM_2 (missing on CPE_EIM, EIM_0, EIM_3, LPE_EIM) */
  uint8_t RESERVED_4[44];
  __IO uint32_t EICHD4_WORD0;                      /**< Error Injection Channel Descriptor 4, Word0, offset: 0x200, available only on: EIM_2 (missing on CPE_EIM, EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD4_WORD1;                      /**< Error Injection Channel Descriptor 4, Word1, offset: 0x204 */
  __IO uint32_t EICHD4_WORD2;                      /**< Error Injection Channel Descriptor 4, Word2, offset: 0x208, available only on: EIM_2, EIM_3, LPE_EIM (missing on CPE_EIM, EIM_0) */
  __IO uint32_t EICHD4_WORD3;                      /**< Error Injection Channel Descriptor 4, Word3, offset: 0x20C, available only on: EIM_2, LPE_EIM (missing on CPE_EIM, EIM_0, EIM_3) */
  __IO uint32_t EICHD4_WORD4;                      /**< Error Injection Channel Descriptor 4, Word4, offset: 0x210, available only on: EIM_2, LPE_EIM (missing on CPE_EIM, EIM_0, EIM_3) */
  __IO uint32_t EICHD4_WORD5;                      /**< Error Injection Channel Descriptor 4, Word5, offset: 0x214, available only on: LPE_EIM (missing on CPE_EIM, EIM_0, EIM_2, EIM_3) */
  __IO uint32_t EICHD4_WORD6;                      /**< Error Injection Channel Descriptor 4, Word6, offset: 0x218, available only on: LPE_EIM (missing on CPE_EIM, EIM_0, EIM_2, EIM_3) */
  uint8_t RESERVED_5[36];
  __IO uint32_t EICHD5_WORD0;                      /**< Error Injection Channel Descriptor 5, Word0, offset: 0x240, available only on: EIM_2 (missing on CPE_EIM, EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD5_WORD1;                      /**< Error Injection Channel Descriptor 5, Word1, offset: 0x244 */
  __IO uint32_t EICHD5_WORD2;                      /**< Error Injection Channel Descriptor 5, Word2, offset: 0x248, available only on: EIM_2, EIM_3 (missing on CPE_EIM, EIM_0, LPE_EIM) */
  uint8_t RESERVED_6[52];
  __IO uint32_t EICHD6_WORD0;                      /**< Error Injection Channel Descriptor 6, Word0, offset: 0x280, available only on: EIM_2, LPE_EIM (missing on CPE_EIM, EIM_0, EIM_3) */
  __IO uint32_t EICHD6_WORD1;                      /**< Error Injection Channel Descriptor 6, Word1, offset: 0x284 */
  __IO uint32_t EICHD6_WORD2;                      /**< Error Injection Channel Descriptor 6, Word2, offset: 0x288, available only on: EIM_2, EIM_3, LPE_EIM (missing on CPE_EIM, EIM_0) */
  __IO uint32_t EICHD6_WORD3;                      /**< Error Injection Channel Descriptor 6, Word3, offset: 0x28C, available only on: EIM_2 (missing on CPE_EIM, EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD6_WORD4;                      /**< Error Injection Channel Descriptor 6, Word4, offset: 0x290, available only on: EIM_2 (missing on CPE_EIM, EIM_0, EIM_3, LPE_EIM) */
  uint8_t RESERVED_7[44];
  __IO uint32_t EICHD7_WORD0;                      /**< Error Injection Channel Descriptor 7, Word0, offset: 0x2C0, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD7_WORD1;                      /**< Error Injection Channel Descriptor 7, Word1, offset: 0x2C4, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD7_WORD2;                      /**< Error Injection Channel Descriptor 7, Word2, offset: 0x2C8, available only on: CPE_EIM, EIM_2, EIM_3 (missing on EIM_0, LPE_EIM) */
  __IO uint32_t EICHD7_WORD3;                      /**< Error Injection Channel Descriptor 7, Word3, offset: 0x2CC, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD7_WORD4;                      /**< Error Injection Channel Descriptor 7, Word4, offset: 0x2D0, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  uint8_t RESERVED_8[44];
  __IO uint32_t EICHD8_WORD0;                      /**< Error Injection Channel Descriptor 8, Word0, offset: 0x300, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD8_WORD1;                      /**< Error Injection Channel Descriptor 8, Word1, offset: 0x304, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD8_WORD2;                      /**< Error Injection Channel Descriptor 8, Word2, offset: 0x308, available only on: CPE_EIM, EIM_2, EIM_3 (missing on EIM_0, LPE_EIM) */
  __IO uint32_t EICHD8_WORD3;                      /**< Error Injection Channel Descriptor 8, Word3, offset: 0x30C, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD8_WORD4;                      /**< Error Injection Channel Descriptor 8, Word4, offset: 0x310, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD8_WORD5;                      /**< Error Injection Channel Descriptor 8, Word5, offset: 0x314, available only on: CPE_EIM (missing on EIM_0, EIM_2, EIM_3, LPE_EIM) */
  uint8_t RESERVED_9[40];
  __IO uint32_t EICHD9_WORD0;                      /**< Error Injection Channel Descriptor 9, Word0, offset: 0x340, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD9_WORD1;                      /**< Error Injection Channel Descriptor 9, Word1, offset: 0x344, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD9_WORD2;                      /**< Error Injection Channel Descriptor 9, Word2, offset: 0x348, available only on: CPE_EIM, EIM_2, EIM_3 (missing on EIM_0, LPE_EIM) */
  __IO uint32_t EICHD9_WORD3;                      /**< Error Injection Channel Descriptor 9, Word3, offset: 0x34C, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD9_WORD4;                      /**< Error Injection Channel Descriptor 9, Word4, offset: 0x350, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD9_WORD5;                      /**< Error Injection Channel Descriptor 9, Word5, offset: 0x354, available only on: CPE_EIM (missing on EIM_0, EIM_2, EIM_3, LPE_EIM) */
  uint8_t RESERVED_10[40];
  __IO uint32_t EICHD10_WORD0;                     /**< Error Injection Channel Descriptor 10, Word0, offset: 0x380, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD10_WORD1;                     /**< Error Injection Channel Descriptor 10, Word1, offset: 0x384, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD10_WORD2;                     /**< Error Injection Channel Descriptor 10, Word2, offset: 0x388, available only on: CPE_EIM, EIM_2, EIM_3 (missing on EIM_0, LPE_EIM) */
  __IO uint32_t EICHD10_WORD3;                     /**< Error Injection Channel Descriptor 10, Word3, offset: 0x38C, available only on: CPE_EIM (missing on EIM_0, EIM_2, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD10_WORD4;                     /**< Error Injection Channel Descriptor 10, Word4, offset: 0x390, available only on: CPE_EIM (missing on EIM_0, EIM_2, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD10_WORD5;                     /**< Error Injection Channel Descriptor 10, Word5, offset: 0x394, available only on: CPE_EIM (missing on EIM_0, EIM_2, EIM_3, LPE_EIM) */
  uint8_t RESERVED_11[40];
  __IO uint32_t EICHD11_WORD0;                     /**< Error Injection Channel Descriptor 11, Word0, offset: 0x3C0, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD11_WORD1;                     /**< Error Injection Channel Descriptor 11, Word1, offset: 0x3C4, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD11_WORD2;                     /**< Error Injection Channel Descriptor 11, Word2, offset: 0x3C8, available only on: CPE_EIM, EIM_2, EIM_3 (missing on EIM_0, LPE_EIM) */
  __IO uint32_t EICHD11_WORD3;                     /**< Error Injection Channel Descriptor 11, Word3, offset: 0x3CC, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD11_WORD4;                     /**< Error Injection Channel Descriptor 11, Word4, offset: 0x3D0, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD11_WORD5;                     /**< Error Injection Channel Descriptor 11, Word5, offset: 0x3D4, available only on: CPE_EIM (missing on EIM_0, EIM_2, EIM_3, LPE_EIM) */
  uint8_t RESERVED_12[40];
  __IO uint32_t EICHD12_WORD0;                     /**< Error Injection Channel Descriptor 12, Word0, offset: 0x400, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD12_WORD1;                     /**< Error Injection Channel Descriptor 12, Word1, offset: 0x404, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD12_WORD2;                     /**< Error Injection Channel Descriptor 12, Word2, offset: 0x408, available only on: CPE_EIM, EIM_2, EIM_3 (missing on EIM_0, LPE_EIM) */
  __IO uint32_t EICHD12_WORD3;                     /**< Error Injection Channel Descriptor 12, Word3, offset: 0x40C, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD12_WORD4;                     /**< Error Injection Channel Descriptor 12, Word4, offset: 0x410, available only on: EIM_2 (missing on CPE_EIM, EIM_0, EIM_3, LPE_EIM) */
  uint8_t RESERVED_13[44];
  __IO uint32_t EICHD13_WORD0;                     /**< Error Injection Channel Descriptor 13, Word0, offset: 0x440, available only on: CPE_EIM, EIM_0, EIM_2 (missing on EIM_3, LPE_EIM) */
  __IO uint32_t EICHD13_WORD1;                     /**< Error Injection Channel Descriptor 13, Word1, offset: 0x444, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD13_WORD2;                     /**< Error Injection Channel Descriptor 13, Word2, offset: 0x448, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD13_WORD3;                     /**< Error Injection Channel Descriptor 13, Word3, offset: 0x44C, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD13_WORD4;                     /**< Error Injection Channel Descriptor 13, Word4, offset: 0x450, available only on: EIM_2 (missing on CPE_EIM, EIM_0, EIM_3, LPE_EIM) */
  uint8_t RESERVED_14[44];
  __IO uint32_t EICHD14_WORD0;                     /**< Error Injection Channel Descriptor 14, Word0, offset: 0x480, available only on: CPE_EIM, EIM_0, EIM_2 (missing on EIM_3, LPE_EIM) */
  __IO uint32_t EICHD14_WORD1;                     /**< Error Injection Channel Descriptor 14, Word1, offset: 0x484, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD14_WORD2;                     /**< Error Injection Channel Descriptor 14, Word2, offset: 0x488, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD14_WORD3;                     /**< Error Injection Channel Descriptor 14, Word3, offset: 0x48C, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD14_WORD4;                     /**< Error Injection Channel Descriptor 14, Word4, offset: 0x490, available only on: EIM_2 (missing on CPE_EIM, EIM_0, EIM_3, LPE_EIM) */
  uint8_t RESERVED_15[44];
  __IO uint32_t EICHD15_WORD0;                     /**< Error Injection Channel Descriptor 15, Word0, offset: 0x4C0, available only on: CPE_EIM, EIM_0, EIM_2 (missing on EIM_3, LPE_EIM) */
  __IO uint32_t EICHD15_WORD1;                     /**< Error Injection Channel Descriptor 15, Word1, offset: 0x4C4, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD15_WORD2;                     /**< Error Injection Channel Descriptor 15, Word2, offset: 0x4C8, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD15_WORD3;                     /**< Error Injection Channel Descriptor 15, Word3, offset: 0x4CC, available only on: CPE_EIM (missing on EIM_0, EIM_2, EIM_3, LPE_EIM) */
  uint8_t RESERVED_16[48];
  __IO uint32_t EICHD16_WORD0;                     /**< Error Injection Channel Descriptor 16, Word0, offset: 0x500, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD16_WORD1;                     /**< Error Injection Channel Descriptor 16, Word1, offset: 0x504, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD16_WORD2;                     /**< Error Injection Channel Descriptor 16, Word2, offset: 0x508, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD16_WORD3;                     /**< Error Injection Channel Descriptor 16, Word3, offset: 0x50C, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD16_WORD4;                     /**< Error Injection Channel Descriptor 16, Word4, offset: 0x510, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD16_WORD5;                     /**< Error Injection Channel Descriptor 16, Word5, offset: 0x514, available only on: CPE_EIM (missing on EIM_0, EIM_2, EIM_3, LPE_EIM) */
  uint8_t RESERVED_17[40];
  __IO uint32_t EICHD17_WORD0;                     /**< Error Injection Channel Descriptor 17, Word0, offset: 0x540, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD17_WORD1;                     /**< Error Injection Channel Descriptor 17, Word1, offset: 0x544, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD17_WORD2;                     /**< Error Injection Channel Descriptor 17, Word2, offset: 0x548, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD17_WORD3;                     /**< Error Injection Channel Descriptor 17, Word3, offset: 0x54C, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD17_WORD4;                     /**< Error Injection Channel Descriptor 17, Word4, offset: 0x550, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD17_WORD5;                     /**< Error Injection Channel Descriptor 17, Word5, offset: 0x554, available only on: CPE_EIM (missing on EIM_0, EIM_2, EIM_3, LPE_EIM) */
  uint8_t RESERVED_18[40];
  __IO uint32_t EICHD18_WORD0;                     /**< Error Injection Channel Descriptor 18, Word0, offset: 0x580, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD18_WORD1;                     /**< Error Injection Channel Descriptor 18, Word1, offset: 0x584, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD18_WORD2;                     /**< Error Injection Channel Descriptor 18, Word2, offset: 0x588, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD18_WORD3;                     /**< Error Injection Channel Descriptor 18, Word3, offset: 0x58C, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD18_WORD4;                     /**< Error Injection Channel Descriptor 18, Word4, offset: 0x590, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD18_WORD5;                     /**< Error Injection Channel Descriptor 18, Word5, offset: 0x594, available only on: CPE_EIM (missing on EIM_0, EIM_2, EIM_3, LPE_EIM) */
  uint8_t RESERVED_19[40];
  __IO uint32_t EICHD19_WORD0;                     /**< Error Injection Channel Descriptor 19, Word0, offset: 0x5C0, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD19_WORD1;                     /**< Error Injection Channel Descriptor 19, Word1, offset: 0x5C4, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD19_WORD2;                     /**< Error Injection Channel Descriptor 19, Word2, offset: 0x5C8, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD19_WORD3;                     /**< Error Injection Channel Descriptor 19, Word3, offset: 0x5CC, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD19_WORD4;                     /**< Error Injection Channel Descriptor 19, Word4, offset: 0x5D0, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD19_WORD5;                     /**< Error Injection Channel Descriptor 19, Word5, offset: 0x5D4, available only on: CPE_EIM (missing on EIM_0, EIM_2, EIM_3, LPE_EIM) */
  uint8_t RESERVED_20[40];
  __IO uint32_t EICHD20_WORD0;                     /**< Error Injection Channel Descriptor 20, Word0, offset: 0x600, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD20_WORD1;                     /**< Error Injection Channel Descriptor 20, Word1, offset: 0x604, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD20_WORD2;                     /**< Error Injection Channel Descriptor 20, Word2, offset: 0x608, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD20_WORD3;                     /**< Error Injection Channel Descriptor 20, Word3, offset: 0x60C, available only on: CPE_EIM, EIM_0 (missing on EIM_2, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD20_WORD4;                     /**< Error Injection Channel Descriptor 20, Word4, offset: 0x610, available only on: EIM_0 (missing on CPE_EIM, EIM_2, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD20_WORD5;                     /**< Error Injection Channel Descriptor 20, Word5, offset: 0x614, available only on: EIM_0 (missing on CPE_EIM, EIM_2, EIM_3, LPE_EIM) */
  uint8_t RESERVED_21[40];
  __IO uint32_t EICHD21_WORD0;                     /**< Error Injection Channel Descriptor 21, Word0, offset: 0x640, available only on: CPE_EIM, EIM_0, EIM_2 (missing on EIM_3, LPE_EIM) */
  __IO uint32_t EICHD21_WORD1;                     /**< Error Injection Channel Descriptor 21, Word1, offset: 0x644, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD21_WORD2;                     /**< Error Injection Channel Descriptor 21, Word2, offset: 0x648, available only on: CPE_EIM, EIM_0, EIM_3 (missing on EIM_2, LPE_EIM) */
  __IO uint32_t EICHD21_WORD3;                     /**< Error Injection Channel Descriptor 21, Word3, offset: 0x64C, available only on: CPE_EIM, EIM_0 (missing on EIM_2, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD21_WORD4;                     /**< Error Injection Channel Descriptor 21, Word4, offset: 0x650, available only on: EIM_0 (missing on CPE_EIM, EIM_2, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD21_WORD5;                     /**< Error Injection Channel Descriptor 21, Word5, offset: 0x654, available only on: EIM_0 (missing on CPE_EIM, EIM_2, EIM_3, LPE_EIM) */
  uint8_t RESERVED_22[40];
  __IO uint32_t EICHD22_WORD0;                     /**< Error Injection Channel Descriptor 22, Word0, offset: 0x680, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD22_WORD1;                     /**< Error Injection Channel Descriptor 22, Word1, offset: 0x684, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD22_WORD2;                     /**< Error Injection Channel Descriptor 22, Word2, offset: 0x688, available only on: CPE_EIM, EIM_0, EIM_3 (missing on EIM_2, LPE_EIM) */
  __IO uint32_t EICHD22_WORD3;                     /**< Error Injection Channel Descriptor 22, Word3, offset: 0x68C, available only on: CPE_EIM, EIM_0 (missing on EIM_2, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD22_WORD4;                     /**< Error Injection Channel Descriptor 22, Word4, offset: 0x690, available only on: EIM_0 (missing on CPE_EIM, EIM_2, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD22_WORD5;                     /**< Error Injection Channel Descriptor 22, Word5, offset: 0x694, available only on: EIM_0 (missing on CPE_EIM, EIM_2, EIM_3, LPE_EIM) */
  uint8_t RESERVED_23[40];
  __IO uint32_t EICHD23_WORD0;                     /**< Error Injection Channel Descriptor 23, Word0, offset: 0x6C0, available only on: CPE_EIM, EIM_0, EIM_2 (missing on EIM_3, LPE_EIM) */
  __IO uint32_t EICHD23_WORD1;                     /**< Error Injection Channel Descriptor 23, Word1, offset: 0x6C4, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD23_WORD2;                     /**< Error Injection Channel Descriptor 23, Word2, offset: 0x6C8, available only on: CPE_EIM, EIM_0, EIM_2, EIM_3 (missing on LPE_EIM) */
  __IO uint32_t EICHD23_WORD3;                     /**< Error Injection Channel Descriptor 23, Word3, offset: 0x6CC, available only on: CPE_EIM, EIM_0 (missing on EIM_2, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD23_WORD4;                     /**< Error Injection Channel Descriptor 23, Word4, offset: 0x6D0, available only on: EIM_0 (missing on CPE_EIM, EIM_2, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD23_WORD5;                     /**< Error Injection Channel Descriptor 23, Word5, offset: 0x6D4, available only on: EIM_0 (missing on CPE_EIM, EIM_2, EIM_3, LPE_EIM) */
  uint8_t RESERVED_24[40];
  __IO uint32_t EICHD24_WORD0;                     /**< Error Injection Channel Descriptor 24, Word0, offset: 0x700, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD24_WORD1;                     /**< Error Injection Channel Descriptor 24, Word1, offset: 0x704, available only on: CPE_EIM, EIM_2, EIM_3 (missing on EIM_0, LPE_EIM) */
  __IO uint32_t EICHD24_WORD2;                     /**< Error Injection Channel Descriptor 24, Word2, offset: 0x708, available only on: CPE_EIM, EIM_3 (missing on EIM_0, EIM_2, LPE_EIM) */
  __IO uint32_t EICHD24_WORD3;                     /**< Error Injection Channel Descriptor 24, Word3, offset: 0x70C, available only on: CPE_EIM (missing on EIM_0, EIM_2, EIM_3, LPE_EIM) */
  uint8_t RESERVED_25[48];
  __IO uint32_t EICHD25_WORD0;                     /**< Error Injection Channel Descriptor 25, Word0, offset: 0x740, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD25_WORD1;                     /**< Error Injection Channel Descriptor 25, Word1, offset: 0x744, available only on: CPE_EIM, EIM_2, EIM_3 (missing on EIM_0, LPE_EIM) */
  __IO uint32_t EICHD25_WORD2;                     /**< Error Injection Channel Descriptor 25, Word2, offset: 0x748, available only on: CPE_EIM, EIM_3 (missing on EIM_0, EIM_2, LPE_EIM) */
  __IO uint32_t EICHD25_WORD3;                     /**< Error Injection Channel Descriptor 25, Word3, offset: 0x74C, available only on: CPE_EIM (missing on EIM_0, EIM_2, EIM_3, LPE_EIM) */
  uint8_t RESERVED_26[48];
  __IO uint32_t EICHD26_WORD0;                     /**< Error Injection Channel Descriptor 26, Word0, offset: 0x780, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD26_WORD1;                     /**< Error Injection Channel Descriptor 26, Word1, offset: 0x784, available only on: CPE_EIM, EIM_2, EIM_3 (missing on EIM_0, LPE_EIM) */
  __IO uint32_t EICHD26_WORD2;                     /**< Error Injection Channel Descriptor 26, Word2, offset: 0x788, available only on: CPE_EIM, EIM_2, EIM_3 (missing on EIM_0, LPE_EIM) */
  __IO uint32_t EICHD26_WORD3;                     /**< Error Injection Channel Descriptor 26, Word3, offset: 0x78C, available only on: CPE_EIM (missing on EIM_0, EIM_2, EIM_3, LPE_EIM) */
  uint8_t RESERVED_27[48];
  __IO uint32_t EICHD27_WORD0;                     /**< Error Injection Channel Descriptor 27, Word0, offset: 0x7C0, available only on: CPE_EIM, EIM_2 (missing on EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD27_WORD1;                     /**< Error Injection Channel Descriptor 27, Word1, offset: 0x7C4, available only on: CPE_EIM, EIM_2, EIM_3 (missing on EIM_0, LPE_EIM) */
  __IO uint32_t EICHD27_WORD2;                     /**< Error Injection Channel Descriptor 27, Word2, offset: 0x7C8, available only on: CPE_EIM, EIM_3 (missing on EIM_0, EIM_2, LPE_EIM) */
  __IO uint32_t EICHD27_WORD3;                     /**< Error Injection Channel Descriptor 27, Word3, offset: 0x7CC, available only on: CPE_EIM (missing on EIM_0, EIM_2, EIM_3, LPE_EIM) */
  uint8_t RESERVED_28[48];
  __IO uint32_t EICHD28_WORD0;                     /**< Error Injection Channel Descriptor 28, Word0, offset: 0x800, available only on: EIM_2 (missing on CPE_EIM, EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD28_WORD1;                     /**< Error Injection Channel Descriptor 28, Word1, offset: 0x804, available only on: CPE_EIM, EIM_2, EIM_3 (missing on EIM_0, LPE_EIM) */
  uint8_t RESERVED_29[56];
  __IO uint32_t EICHD29_WORD0;                     /**< Error Injection Channel Descriptor 29, Word0, offset: 0x840, available only on: EIM_2 (missing on CPE_EIM, EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD29_WORD1;                     /**< Error Injection Channel Descriptor 29, Word1, offset: 0x844, available only on: EIM_2, EIM_3 (missing on CPE_EIM, EIM_0, LPE_EIM) */
  __IO uint32_t EICHD29_WORD2;                     /**< Error Injection Channel Descriptor 29, Word2, offset: 0x848, available only on: EIM_2 (missing on CPE_EIM, EIM_0, EIM_3, LPE_EIM) */
  uint8_t RESERVED_30[52];
  __IO uint32_t EICHD30_WORD0;                     /**< Error Injection Channel Descriptor 30, Word0, offset: 0x880, available only on: EIM_2 (missing on CPE_EIM, EIM_0, EIM_3, LPE_EIM) */
  __IO uint32_t EICHD30_WORD1;                     /**< Error Injection Channel Descriptor 30, Word1, offset: 0x884, available only on: EIM_2, EIM_3 (missing on CPE_EIM, EIM_0, LPE_EIM) */
  uint8_t RESERVED_31[56];
  __IO uint32_t EICHD31_WORD0;                     /**< Error Injection Channel Descriptor 31, Word0, offset: 0x8C0, available only on: EIM_2, EIM_3 (missing on CPE_EIM, EIM_0, LPE_EIM) */
  __IO uint32_t EICHD31_WORD1;                     /**< Error Injection Channel Descriptor 31, Word1, offset: 0x8C4, available only on: EIM_2, EIM_3 (missing on CPE_EIM, EIM_0, LPE_EIM) */
  __IO uint32_t EICHD31_WORD2;                     /**< Error Injection Channel Descriptor 31, Word2, offset: 0x8C8, available only on: EIM_3 (missing on CPE_EIM, EIM_0, EIM_2, LPE_EIM) */
} EIM_Type, *EIM_MemMapPtr;

/** Number of instances of the EIM module. */
#define EIM_INSTANCE_COUNT                       (5u)

/* EIM - Peripheral instance base addresses */
/** Peripheral CPE_EIM base address */
#define IP_CPE_EIM_BASE                          (0x4108C000u)
/** Peripheral CPE_EIM base pointer */
#define IP_CPE_EIM                               ((EIM_Type *)IP_CPE_EIM_BASE)
/** Peripheral EIM_0 base address */
#define IP_EIM_0_BASE                            (0x404CC000u)
/** Peripheral EIM_0 base pointer */
#define IP_EIM_0                                 ((EIM_Type *)IP_EIM_0_BASE)
/** Peripheral EIM_2 base address */
#define IP_EIM_2_BASE                            (0x40B4C000u)
/** Peripheral EIM_2 base pointer */
#define IP_EIM_2                                 ((EIM_Type *)IP_EIM_2_BASE)
/** Peripheral EIM_3 base address */
#define IP_EIM_3_BASE                            (0x40B5C000u)
/** Peripheral EIM_3 base pointer */
#define IP_EIM_3                                 ((EIM_Type *)IP_EIM_3_BASE)
/** Peripheral LPE_EIM base address */
#define IP_LPE_EIM_BASE                          (0x4212C000u)
/** Peripheral LPE_EIM base pointer */
#define IP_LPE_EIM                               ((EIM_Type *)IP_LPE_EIM_BASE)
/** Array initializer of EIM peripheral base addresses */
#define IP_EIM_BASE_ADDRS                        { IP_CPE_EIM_BASE, IP_EIM_0_BASE, IP_EIM_2_BASE, IP_EIM_3_BASE, IP_LPE_EIM_BASE }
/** Array initializer of EIM peripheral base pointers */
#define IP_EIM_BASE_PTRS                         { IP_CPE_EIM, IP_EIM_0, IP_EIM_2, IP_EIM_3, IP_LPE_EIM }

/* ----------------------------------------------------------------------------
   -- EIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EIM_Register_Masks EIM Register Masks
 * @{
 */

/*! @name EIMCR - Error Injection Module Configuration Register */
/*! @{ */

#define EIM_EIMCR_GEIEN_MASK                     (0x1U)
#define EIM_EIMCR_GEIEN_SHIFT                    (0U)
#define EIM_EIMCR_GEIEN_WIDTH                    (1U)
#define EIM_EIMCR_GEIEN(x)                       (((uint32_t)(((uint32_t)(x)) << EIM_EIMCR_GEIEN_SHIFT)) & EIM_EIMCR_GEIEN_MASK)
/*! @} */

/*! @name EICHEN - Error Injection Channel Enable register */
/*! @{ */

#define EIM_EICHEN_EICH31EN_MASK                 (0x1U)
#define EIM_EICHEN_EICH31EN_SHIFT                (0U)
#define EIM_EICHEN_EICH31EN_WIDTH                (1U)
#define EIM_EICHEN_EICH31EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH31EN_SHIFT)) & EIM_EICHEN_EICH31EN_MASK)

#define EIM_EICHEN_EICH30EN_MASK                 (0x2U)
#define EIM_EICHEN_EICH30EN_SHIFT                (1U)
#define EIM_EICHEN_EICH30EN_WIDTH                (1U)
#define EIM_EICHEN_EICH30EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH30EN_SHIFT)) & EIM_EICHEN_EICH30EN_MASK)

#define EIM_EICHEN_EICH29EN_MASK                 (0x4U)
#define EIM_EICHEN_EICH29EN_SHIFT                (2U)
#define EIM_EICHEN_EICH29EN_WIDTH                (1U)
#define EIM_EICHEN_EICH29EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH29EN_SHIFT)) & EIM_EICHEN_EICH29EN_MASK)

#define EIM_EICHEN_EICH28EN_MASK                 (0x8U)
#define EIM_EICHEN_EICH28EN_SHIFT                (3U)
#define EIM_EICHEN_EICH28EN_WIDTH                (1U)
#define EIM_EICHEN_EICH28EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH28EN_SHIFT)) & EIM_EICHEN_EICH28EN_MASK)

#define EIM_EICHEN_EICH27EN_MASK                 (0x10U)
#define EIM_EICHEN_EICH27EN_SHIFT                (4U)
#define EIM_EICHEN_EICH27EN_WIDTH                (1U)
#define EIM_EICHEN_EICH27EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH27EN_SHIFT)) & EIM_EICHEN_EICH27EN_MASK)

#define EIM_EICHEN_EICH26EN_MASK                 (0x20U)
#define EIM_EICHEN_EICH26EN_SHIFT                (5U)
#define EIM_EICHEN_EICH26EN_WIDTH                (1U)
#define EIM_EICHEN_EICH26EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH26EN_SHIFT)) & EIM_EICHEN_EICH26EN_MASK)

#define EIM_EICHEN_EICH25EN_MASK                 (0x40U)
#define EIM_EICHEN_EICH25EN_SHIFT                (6U)
#define EIM_EICHEN_EICH25EN_WIDTH                (1U)
#define EIM_EICHEN_EICH25EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH25EN_SHIFT)) & EIM_EICHEN_EICH25EN_MASK)

#define EIM_EICHEN_EICH24EN_MASK                 (0x80U)
#define EIM_EICHEN_EICH24EN_SHIFT                (7U)
#define EIM_EICHEN_EICH24EN_WIDTH                (1U)
#define EIM_EICHEN_EICH24EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH24EN_SHIFT)) & EIM_EICHEN_EICH24EN_MASK)

#define EIM_EICHEN_EICH23EN_MASK                 (0x100U)
#define EIM_EICHEN_EICH23EN_SHIFT                (8U)
#define EIM_EICHEN_EICH23EN_WIDTH                (1U)
#define EIM_EICHEN_EICH23EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH23EN_SHIFT)) & EIM_EICHEN_EICH23EN_MASK)

#define EIM_EICHEN_EICH22EN_MASK                 (0x200U)
#define EIM_EICHEN_EICH22EN_SHIFT                (9U)
#define EIM_EICHEN_EICH22EN_WIDTH                (1U)
#define EIM_EICHEN_EICH22EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH22EN_SHIFT)) & EIM_EICHEN_EICH22EN_MASK)

#define EIM_EICHEN_EICH21EN_MASK                 (0x400U)
#define EIM_EICHEN_EICH21EN_SHIFT                (10U)
#define EIM_EICHEN_EICH21EN_WIDTH                (1U)
#define EIM_EICHEN_EICH21EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH21EN_SHIFT)) & EIM_EICHEN_EICH21EN_MASK)

#define EIM_EICHEN_EICH20EN_MASK                 (0x800U)
#define EIM_EICHEN_EICH20EN_SHIFT                (11U)
#define EIM_EICHEN_EICH20EN_WIDTH                (1U)
#define EIM_EICHEN_EICH20EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH20EN_SHIFT)) & EIM_EICHEN_EICH20EN_MASK)

#define EIM_EICHEN_EICH19EN_MASK                 (0x1000U)
#define EIM_EICHEN_EICH19EN_SHIFT                (12U)
#define EIM_EICHEN_EICH19EN_WIDTH                (1U)
#define EIM_EICHEN_EICH19EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH19EN_SHIFT)) & EIM_EICHEN_EICH19EN_MASK)

#define EIM_EICHEN_EICH18EN_MASK                 (0x2000U)
#define EIM_EICHEN_EICH18EN_SHIFT                (13U)
#define EIM_EICHEN_EICH18EN_WIDTH                (1U)
#define EIM_EICHEN_EICH18EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH18EN_SHIFT)) & EIM_EICHEN_EICH18EN_MASK)

#define EIM_EICHEN_EICH17EN_MASK                 (0x4000U)
#define EIM_EICHEN_EICH17EN_SHIFT                (14U)
#define EIM_EICHEN_EICH17EN_WIDTH                (1U)
#define EIM_EICHEN_EICH17EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH17EN_SHIFT)) & EIM_EICHEN_EICH17EN_MASK)

#define EIM_EICHEN_EICH16EN_MASK                 (0x8000U)
#define EIM_EICHEN_EICH16EN_SHIFT                (15U)
#define EIM_EICHEN_EICH16EN_WIDTH                (1U)
#define EIM_EICHEN_EICH16EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH16EN_SHIFT)) & EIM_EICHEN_EICH16EN_MASK)

#define EIM_EICHEN_EICH15EN_MASK                 (0x10000U)
#define EIM_EICHEN_EICH15EN_SHIFT                (16U)
#define EIM_EICHEN_EICH15EN_WIDTH                (1U)
#define EIM_EICHEN_EICH15EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH15EN_SHIFT)) & EIM_EICHEN_EICH15EN_MASK)

#define EIM_EICHEN_EICH14EN_MASK                 (0x20000U)
#define EIM_EICHEN_EICH14EN_SHIFT                (17U)
#define EIM_EICHEN_EICH14EN_WIDTH                (1U)
#define EIM_EICHEN_EICH14EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH14EN_SHIFT)) & EIM_EICHEN_EICH14EN_MASK)

#define EIM_EICHEN_EICH13EN_MASK                 (0x40000U)
#define EIM_EICHEN_EICH13EN_SHIFT                (18U)
#define EIM_EICHEN_EICH13EN_WIDTH                (1U)
#define EIM_EICHEN_EICH13EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH13EN_SHIFT)) & EIM_EICHEN_EICH13EN_MASK)

#define EIM_EICHEN_EICH12EN_MASK                 (0x80000U)
#define EIM_EICHEN_EICH12EN_SHIFT                (19U)
#define EIM_EICHEN_EICH12EN_WIDTH                (1U)
#define EIM_EICHEN_EICH12EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH12EN_SHIFT)) & EIM_EICHEN_EICH12EN_MASK)

#define EIM_EICHEN_EICH11EN_MASK                 (0x100000U)
#define EIM_EICHEN_EICH11EN_SHIFT                (20U)
#define EIM_EICHEN_EICH11EN_WIDTH                (1U)
#define EIM_EICHEN_EICH11EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH11EN_SHIFT)) & EIM_EICHEN_EICH11EN_MASK)

#define EIM_EICHEN_EICH10EN_MASK                 (0x200000U)
#define EIM_EICHEN_EICH10EN_SHIFT                (21U)
#define EIM_EICHEN_EICH10EN_WIDTH                (1U)
#define EIM_EICHEN_EICH10EN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH10EN_SHIFT)) & EIM_EICHEN_EICH10EN_MASK)

#define EIM_EICHEN_EICH9EN_MASK                  (0x400000U)
#define EIM_EICHEN_EICH9EN_SHIFT                 (22U)
#define EIM_EICHEN_EICH9EN_WIDTH                 (1U)
#define EIM_EICHEN_EICH9EN(x)                    (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH9EN_SHIFT)) & EIM_EICHEN_EICH9EN_MASK)

#define EIM_EICHEN_EICH8EN_MASK                  (0x800000U)
#define EIM_EICHEN_EICH8EN_SHIFT                 (23U)
#define EIM_EICHEN_EICH8EN_WIDTH                 (1U)
#define EIM_EICHEN_EICH8EN(x)                    (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH8EN_SHIFT)) & EIM_EICHEN_EICH8EN_MASK)

#define EIM_EICHEN_EICH7EN_MASK                  (0x1000000U)
#define EIM_EICHEN_EICH7EN_SHIFT                 (24U)
#define EIM_EICHEN_EICH7EN_WIDTH                 (1U)
#define EIM_EICHEN_EICH7EN(x)                    (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH7EN_SHIFT)) & EIM_EICHEN_EICH7EN_MASK)

#define EIM_EICHEN_EICH6EN_MASK                  (0x2000000U)
#define EIM_EICHEN_EICH6EN_SHIFT                 (25U)
#define EIM_EICHEN_EICH6EN_WIDTH                 (1U)
#define EIM_EICHEN_EICH6EN(x)                    (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH6EN_SHIFT)) & EIM_EICHEN_EICH6EN_MASK)

#define EIM_EICHEN_EICH5EN_MASK                  (0x4000000U)
#define EIM_EICHEN_EICH5EN_SHIFT                 (26U)
#define EIM_EICHEN_EICH5EN_WIDTH                 (1U)
#define EIM_EICHEN_EICH5EN(x)                    (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH5EN_SHIFT)) & EIM_EICHEN_EICH5EN_MASK)

#define EIM_EICHEN_EICH4EN_MASK                  (0x8000000U)
#define EIM_EICHEN_EICH4EN_SHIFT                 (27U)
#define EIM_EICHEN_EICH4EN_WIDTH                 (1U)
#define EIM_EICHEN_EICH4EN(x)                    (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH4EN_SHIFT)) & EIM_EICHEN_EICH4EN_MASK)

#define EIM_EICHEN_EICH3EN_MASK                  (0x10000000U)
#define EIM_EICHEN_EICH3EN_SHIFT                 (28U)
#define EIM_EICHEN_EICH3EN_WIDTH                 (1U)
#define EIM_EICHEN_EICH3EN(x)                    (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH3EN_SHIFT)) & EIM_EICHEN_EICH3EN_MASK)

#define EIM_EICHEN_EICH2EN_MASK                  (0x20000000U)
#define EIM_EICHEN_EICH2EN_SHIFT                 (29U)
#define EIM_EICHEN_EICH2EN_WIDTH                 (1U)
#define EIM_EICHEN_EICH2EN(x)                    (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH2EN_SHIFT)) & EIM_EICHEN_EICH2EN_MASK)

#define EIM_EICHEN_EICH1EN_MASK                  (0x40000000U)
#define EIM_EICHEN_EICH1EN_SHIFT                 (30U)
#define EIM_EICHEN_EICH1EN_WIDTH                 (1U)
#define EIM_EICHEN_EICH1EN(x)                    (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH1EN_SHIFT)) & EIM_EICHEN_EICH1EN_MASK)

#define EIM_EICHEN_EICH0EN_MASK                  (0x80000000U)
#define EIM_EICHEN_EICH0EN_SHIFT                 (31U)
#define EIM_EICHEN_EICH0EN_WIDTH                 (1U)
#define EIM_EICHEN_EICH0EN(x)                    (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH0EN_SHIFT)) & EIM_EICHEN_EICH0EN_MASK)
/*! @} */

/*! @name EICHD0_WORD0 - Error Injection Channel Descriptor 0, Word0 */
/*! @{ */

#define EIM_EICHD0_WORD0_CHKBIT_MASK_MASK        (0xFFFC0000U)  /* Merged from fields with different position or width, of widths (7, 14), largest definition used */
#define EIM_EICHD0_WORD0_CHKBIT_MASK_SHIFT       (18U)
#define EIM_EICHD0_WORD0_CHKBIT_MASK_WIDTH       (14U)
#define EIM_EICHD0_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD0_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD0_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (7, 14), largest definition used */
/*! @} */

/*! @name EICHD0_WORD1 - Error Injection Channel Descriptor 0, Word1 */
/*! @{ */

#define EIM_EICHD0_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (6, 12, 18, 28, 32), largest definition used */
#define EIM_EICHD0_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD0_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD0_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD0_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD0_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (6, 12, 18, 28, 32), largest definition used */
/*! @} */

/*! @name EICHD0_WORD2 - Error Injection Channel Descriptor 0, Word2 */
/*! @{ */

#define EIM_EICHD0_WORD2_B4_7DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD0_WORD2_B4_7DATA_MASK_SHIFT     (0U)
#define EIM_EICHD0_WORD2_B4_7DATA_MASK_WIDTH     (32U)
#define EIM_EICHD0_WORD2_B4_7DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD0_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD0_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD0 - Error Injection Channel Descriptor 1, Word0 */
/*! @{ */

#define EIM_EICHD1_WORD0_CHKBIT_MASK_MASK        (0xFFFF0000U)  /* Merged from fields with different position or width, of widths (7, 16), largest definition used */
#define EIM_EICHD1_WORD0_CHKBIT_MASK_SHIFT       (16U)
#define EIM_EICHD1_WORD0_CHKBIT_MASK_WIDTH       (16U)
#define EIM_EICHD1_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD1_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD1_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (7, 16), largest definition used */
/*! @} */

/*! @name EICHD1_WORD1 - Error Injection Channel Descriptor 1, Word1 */
/*! @{ */

#define EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (3, 6, 28, 32), largest definition used */
#define EIM_EICHD1_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD1_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD1_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD1_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (3, 6, 28, 32), largest definition used */
/*! @} */

/*! @name EICHD1_WORD2 - Error Injection Channel Descriptor 1, Word2 */
/*! @{ */

#define EIM_EICHD1_WORD2_B4_7DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD1_WORD2_B4_7DATA_MASK_SHIFT     (0U)
#define EIM_EICHD1_WORD2_B4_7DATA_MASK_WIDTH     (32U)
#define EIM_EICHD1_WORD2_B4_7DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD1_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD1_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD3 - Error Injection Channel Descriptor 1, Word3 */
/*! @{ */

#define EIM_EICHD1_WORD3_B8_11DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD1_WORD3_B8_11DATA_MASK_SHIFT    (0U)
#define EIM_EICHD1_WORD3_B8_11DATA_MASK_WIDTH    (32U)
#define EIM_EICHD1_WORD3_B8_11DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD1_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD1_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD4 - Error Injection Channel Descriptor 1, Word4 */
/*! @{ */

#define EIM_EICHD1_WORD4_B12_15DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD1_WORD4_B12_15DATA_MASK_SHIFT   (0U)
#define EIM_EICHD1_WORD4_B12_15DATA_MASK_WIDTH   (32U)
#define EIM_EICHD1_WORD4_B12_15DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD1_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_EICHD1_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD0 - Error Injection Channel Descriptor 2, Word0 */
/*! @{ */

#define EIM_EICHD2_WORD0_CHKBIT_MASK_MASK        (0xFFFFFFF0U)  /* Merged from fields with different position or width, of widths (14, 28), largest definition used */
#define EIM_EICHD2_WORD0_CHKBIT_MASK_SHIFT       (4U)
#define EIM_EICHD2_WORD0_CHKBIT_MASK_WIDTH       (28U)
#define EIM_EICHD2_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD2_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD2_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (14, 28), largest definition used */
/*! @} */

/*! @name EICHD2_WORD1 - Error Injection Channel Descriptor 2, Word1 */
/*! @{ */

#define EIM_EICHD2_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFU)  /* Merged from fields with different position or width, of widths (1, 6, 8, 12, 28), largest definition used */
#define EIM_EICHD2_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD2_WORD1_B0_3DATA_MASK_WIDTH     (28U)
#define EIM_EICHD2_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD2_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD2_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (1, 6, 8, 12, 28), largest definition used */
/*! @} */

/*! @name EICHD2_WORD2 - Error Injection Channel Descriptor 2, Word2 */
/*! @{ */

#define EIM_EICHD2_WORD2_B4_7DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD2_WORD2_B4_7DATA_MASK_SHIFT     (0U)
#define EIM_EICHD2_WORD2_B4_7DATA_MASK_WIDTH     (32U)
#define EIM_EICHD2_WORD2_B4_7DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD2_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD2_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD3 - Error Injection Channel Descriptor 2, Word3 */
/*! @{ */

#define EIM_EICHD2_WORD3_B8_11DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD2_WORD3_B8_11DATA_MASK_SHIFT    (0U)
#define EIM_EICHD2_WORD3_B8_11DATA_MASK_WIDTH    (32U)
#define EIM_EICHD2_WORD3_B8_11DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD2_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD2_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD4 - Error Injection Channel Descriptor 2, Word4 */
/*! @{ */

#define EIM_EICHD2_WORD4_B12_15DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD2_WORD4_B12_15DATA_MASK_SHIFT   (0U)
#define EIM_EICHD2_WORD4_B12_15DATA_MASK_WIDTH   (32U)
#define EIM_EICHD2_WORD4_B12_15DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD2_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_EICHD2_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD0 - Error Injection Channel Descriptor 3, Word0 */
/*! @{ */

#define EIM_EICHD3_WORD0_CHKBIT_MASK_MASK        (0xFFFFFFF0U)  /* Merged from fields with different position or width, of widths (8, 28), largest definition used */
#define EIM_EICHD3_WORD0_CHKBIT_MASK_SHIFT       (4U)
#define EIM_EICHD3_WORD0_CHKBIT_MASK_WIDTH       (28U)
#define EIM_EICHD3_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD3_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD3_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (8, 28), largest definition used */
/*! @} */

/*! @name EICHD3_WORD1 - Error Injection Channel Descriptor 3, Word1 */
/*! @{ */

#define EIM_EICHD3_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (13, 28, 30, 32), largest definition used */
#define EIM_EICHD3_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD3_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD3_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD3_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD3_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (13, 28, 30, 32), largest definition used */
/*! @} */

/*! @name EICHD3_WORD2 - Error Injection Channel Descriptor 3, Word2 */
/*! @{ */

#define EIM_EICHD3_WORD2_B4_7DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD3_WORD2_B4_7DATA_MASK_SHIFT     (0U)
#define EIM_EICHD3_WORD2_B4_7DATA_MASK_WIDTH     (32U)
#define EIM_EICHD3_WORD2_B4_7DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD3_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD3_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD3 - Error Injection Channel Descriptor 3, Word3 */
/*! @{ */

#define EIM_EICHD3_WORD3_B8_11DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD3_WORD3_B8_11DATA_MASK_SHIFT    (0U)
#define EIM_EICHD3_WORD3_B8_11DATA_MASK_WIDTH    (32U)
#define EIM_EICHD3_WORD3_B8_11DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD3_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD3_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD4 - Error Injection Channel Descriptor 3, Word4 */
/*! @{ */

#define EIM_EICHD3_WORD4_B12_15DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD3_WORD4_B12_15DATA_MASK_SHIFT   (0U)
#define EIM_EICHD3_WORD4_B12_15DATA_MASK_WIDTH   (32U)
#define EIM_EICHD3_WORD4_B12_15DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD3_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_EICHD3_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD0 - Error Injection Channel Descriptor 4, Word0 */
/*! @{ */

#define EIM_EICHD4_WORD0_CHKBIT_MASK_MASK        (0xFFFFFFF0U)
#define EIM_EICHD4_WORD0_CHKBIT_MASK_SHIFT       (4U)
#define EIM_EICHD4_WORD0_CHKBIT_MASK_WIDTH       (28U)
#define EIM_EICHD4_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD4_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD4_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD1 - Error Injection Channel Descriptor 4, Word1 */
/*! @{ */

#define EIM_EICHD4_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (13, 28, 30, 32), largest definition used */
#define EIM_EICHD4_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD4_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD4_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD4_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD4_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (13, 28, 30, 32), largest definition used */
/*! @} */

/*! @name EICHD4_WORD2 - Error Injection Channel Descriptor 4, Word2 */
/*! @{ */

#define EIM_EICHD4_WORD2_B4_7DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD4_WORD2_B4_7DATA_MASK_SHIFT     (0U)
#define EIM_EICHD4_WORD2_B4_7DATA_MASK_WIDTH     (32U)
#define EIM_EICHD4_WORD2_B4_7DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD4_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD4_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD3 - Error Injection Channel Descriptor 4, Word3 */
/*! @{ */

#define EIM_EICHD4_WORD3_B8_11DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD4_WORD3_B8_11DATA_MASK_SHIFT    (0U)
#define EIM_EICHD4_WORD3_B8_11DATA_MASK_WIDTH    (32U)
#define EIM_EICHD4_WORD3_B8_11DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD4_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD4_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD4 - Error Injection Channel Descriptor 4, Word4 */
/*! @{ */

#define EIM_EICHD4_WORD4_B12_15DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD4_WORD4_B12_15DATA_MASK_SHIFT   (0U)
#define EIM_EICHD4_WORD4_B12_15DATA_MASK_WIDTH   (32U)
#define EIM_EICHD4_WORD4_B12_15DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD4_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_EICHD4_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD5 - Error Injection Channel Descriptor 4, Word5 */
/*! @{ */

#define EIM_EICHD4_WORD5_B16_19DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD4_WORD5_B16_19DATA_MASK_SHIFT   (0U)
#define EIM_EICHD4_WORD5_B16_19DATA_MASK_WIDTH   (32U)
#define EIM_EICHD4_WORD5_B16_19DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD4_WORD5_B16_19DATA_MASK_SHIFT)) & EIM_EICHD4_WORD5_B16_19DATA_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD6 - Error Injection Channel Descriptor 4, Word6 */
/*! @{ */

#define EIM_EICHD4_WORD6_B20_23DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD4_WORD6_B20_23DATA_MASK_SHIFT   (0U)
#define EIM_EICHD4_WORD6_B20_23DATA_MASK_WIDTH   (32U)
#define EIM_EICHD4_WORD6_B20_23DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD4_WORD6_B20_23DATA_MASK_SHIFT)) & EIM_EICHD4_WORD6_B20_23DATA_MASK_MASK)
/*! @} */

/*! @name EICHD5_WORD0 - Error Injection Channel Descriptor 5, Word0 */
/*! @{ */

#define EIM_EICHD5_WORD0_CHKBIT_MASK_MASK        (0xFFFC0000U)
#define EIM_EICHD5_WORD0_CHKBIT_MASK_SHIFT       (18U)
#define EIM_EICHD5_WORD0_CHKBIT_MASK_WIDTH       (14U)
#define EIM_EICHD5_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD5_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD5_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD5_WORD1 - Error Injection Channel Descriptor 5, Word1 */
/*! @{ */

#define EIM_EICHD5_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (12, 13, 20, 30, 32), largest definition used */
#define EIM_EICHD5_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD5_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD5_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD5_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD5_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (12, 13, 20, 30, 32), largest definition used */
/*! @} */

/*! @name EICHD5_WORD2 - Error Injection Channel Descriptor 5, Word2 */
/*! @{ */

#define EIM_EICHD5_WORD2_B4_7DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD5_WORD2_B4_7DATA_MASK_SHIFT     (0U)
#define EIM_EICHD5_WORD2_B4_7DATA_MASK_WIDTH     (32U)
#define EIM_EICHD5_WORD2_B4_7DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD5_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD5_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD0 - Error Injection Channel Descriptor 6, Word0 */
/*! @{ */

#define EIM_EICHD6_WORD0_CHKBIT_MASK_MASK        (0xFFFF0000U)  /* Merged from fields with different position or width, of widths (8, 16), largest definition used */
#define EIM_EICHD6_WORD0_CHKBIT_MASK_SHIFT       (16U)
#define EIM_EICHD6_WORD0_CHKBIT_MASK_WIDTH       (16U)
#define EIM_EICHD6_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD6_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD6_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (8, 16), largest definition used */
/*! @} */

/*! @name EICHD6_WORD1 - Error Injection Channel Descriptor 6, Word1 */
/*! @{ */

#define EIM_EICHD6_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (13, 28, 30, 32), largest definition used */
#define EIM_EICHD6_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD6_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD6_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD6_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD6_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (13, 28, 30, 32), largest definition used */
/*! @} */

/*! @name EICHD6_WORD2 - Error Injection Channel Descriptor 6, Word2 */
/*! @{ */

#define EIM_EICHD6_WORD2_B4_7DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD6_WORD2_B4_7DATA_MASK_SHIFT     (0U)
#define EIM_EICHD6_WORD2_B4_7DATA_MASK_WIDTH     (32U)
#define EIM_EICHD6_WORD2_B4_7DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD6_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD6_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD3 - Error Injection Channel Descriptor 6, Word3 */
/*! @{ */

#define EIM_EICHD6_WORD3_B8_11DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD6_WORD3_B8_11DATA_MASK_SHIFT    (0U)
#define EIM_EICHD6_WORD3_B8_11DATA_MASK_WIDTH    (32U)
#define EIM_EICHD6_WORD3_B8_11DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD6_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD6_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD4 - Error Injection Channel Descriptor 6, Word4 */
/*! @{ */

#define EIM_EICHD6_WORD4_B12_15DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD6_WORD4_B12_15DATA_MASK_SHIFT   (0U)
#define EIM_EICHD6_WORD4_B12_15DATA_MASK_WIDTH   (32U)
#define EIM_EICHD6_WORD4_B12_15DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD6_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_EICHD6_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD0 - Error Injection Channel Descriptor 7, Word0 */
/*! @{ */

#define EIM_EICHD7_WORD0_CHKBIT_MASK_MASK        (0xFFFFFFF0U)  /* Merged from fields with different position or width, of widths (16, 28), largest definition used */
#define EIM_EICHD7_WORD0_CHKBIT_MASK_SHIFT       (4U)
#define EIM_EICHD7_WORD0_CHKBIT_MASK_WIDTH       (28U)
#define EIM_EICHD7_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD7_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD7_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (16, 28), largest definition used */
/*! @} */

/*! @name EICHD7_WORD1 - Error Injection Channel Descriptor 7, Word1 */
/*! @{ */

#define EIM_EICHD7_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (8, 12, 32), largest definition used */
#define EIM_EICHD7_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD7_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD7_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD7_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD7_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (8, 12, 32), largest definition used */
/*! @} */

/*! @name EICHD7_WORD2 - Error Injection Channel Descriptor 7, Word2 */
/*! @{ */

#define EIM_EICHD7_WORD2_B4_7DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD7_WORD2_B4_7DATA_MASK_SHIFT     (0U)
#define EIM_EICHD7_WORD2_B4_7DATA_MASK_WIDTH     (32U)
#define EIM_EICHD7_WORD2_B4_7DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD7_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD7_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD3 - Error Injection Channel Descriptor 7, Word3 */
/*! @{ */

#define EIM_EICHD7_WORD3_B8_11DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD7_WORD3_B8_11DATA_MASK_SHIFT    (0U)
#define EIM_EICHD7_WORD3_B8_11DATA_MASK_WIDTH    (32U)
#define EIM_EICHD7_WORD3_B8_11DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD7_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD7_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD4 - Error Injection Channel Descriptor 7, Word4 */
/*! @{ */

#define EIM_EICHD7_WORD4_B12_15DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD7_WORD4_B12_15DATA_MASK_SHIFT   (0U)
#define EIM_EICHD7_WORD4_B12_15DATA_MASK_WIDTH   (32U)
#define EIM_EICHD7_WORD4_B12_15DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD7_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_EICHD7_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD8_WORD0 - Error Injection Channel Descriptor 8, Word0 */
/*! @{ */

#define EIM_EICHD8_WORD0_CHKBIT_MASK_MASK        (0xFFFFFFF0U)  /* Merged from fields with different position or width, of widths (9, 28), largest definition used */
#define EIM_EICHD8_WORD0_CHKBIT_MASK_SHIFT       (4U)
#define EIM_EICHD8_WORD0_CHKBIT_MASK_WIDTH       (28U)
#define EIM_EICHD8_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD8_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD8_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (9, 28), largest definition used */
/*! @} */

/*! @name EICHD8_WORD1 - Error Injection Channel Descriptor 8, Word1 */
/*! @{ */

#define EIM_EICHD8_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (1, 4, 32), largest definition used */
#define EIM_EICHD8_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD8_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD8_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD8_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD8_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (1, 4, 32), largest definition used */
/*! @} */

/*! @name EICHD8_WORD2 - Error Injection Channel Descriptor 8, Word2 */
/*! @{ */

#define EIM_EICHD8_WORD2_B4_7DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD8_WORD2_B4_7DATA_MASK_SHIFT     (0U)
#define EIM_EICHD8_WORD2_B4_7DATA_MASK_WIDTH     (32U)
#define EIM_EICHD8_WORD2_B4_7DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD8_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD8_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD8_WORD3 - Error Injection Channel Descriptor 8, Word3 */
/*! @{ */

#define EIM_EICHD8_WORD3_B8_11DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD8_WORD3_B8_11DATA_MASK_SHIFT    (0U)
#define EIM_EICHD8_WORD3_B8_11DATA_MASK_WIDTH    (32U)
#define EIM_EICHD8_WORD3_B8_11DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD8_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD8_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD8_WORD4 - Error Injection Channel Descriptor 8, Word4 */
/*! @{ */

#define EIM_EICHD8_WORD4_B12_15DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD8_WORD4_B12_15DATA_MASK_SHIFT   (0U)
#define EIM_EICHD8_WORD4_B12_15DATA_MASK_WIDTH   (32U)
#define EIM_EICHD8_WORD4_B12_15DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD8_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_EICHD8_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD8_WORD5 - Error Injection Channel Descriptor 8, Word5 */
/*! @{ */

#define EIM_EICHD8_WORD5_B16_19DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD8_WORD5_B16_19DATA_MASK_SHIFT   (0U)
#define EIM_EICHD8_WORD5_B16_19DATA_MASK_WIDTH   (32U)
#define EIM_EICHD8_WORD5_B16_19DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD8_WORD5_B16_19DATA_MASK_SHIFT)) & EIM_EICHD8_WORD5_B16_19DATA_MASK_MASK)
/*! @} */

/*! @name EICHD9_WORD0 - Error Injection Channel Descriptor 9, Word0 */
/*! @{ */

#define EIM_EICHD9_WORD0_CHKBIT_MASK_MASK        (0xFFFFFFF0U)  /* Merged from fields with different position or width, of widths (9, 28), largest definition used */
#define EIM_EICHD9_WORD0_CHKBIT_MASK_SHIFT       (4U)
#define EIM_EICHD9_WORD0_CHKBIT_MASK_WIDTH       (28U)
#define EIM_EICHD9_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD9_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD9_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (9, 28), largest definition used */
/*! @} */

/*! @name EICHD9_WORD1 - Error Injection Channel Descriptor 9, Word1 */
/*! @{ */

#define EIM_EICHD9_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (1, 20, 28, 32), largest definition used */
#define EIM_EICHD9_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD9_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD9_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD9_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD9_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (1, 20, 28, 32), largest definition used */
/*! @} */

/*! @name EICHD9_WORD2 - Error Injection Channel Descriptor 9, Word2 */
/*! @{ */

#define EIM_EICHD9_WORD2_B4_7DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD9_WORD2_B4_7DATA_MASK_SHIFT     (0U)
#define EIM_EICHD9_WORD2_B4_7DATA_MASK_WIDTH     (32U)
#define EIM_EICHD9_WORD2_B4_7DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD9_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD9_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD9_WORD3 - Error Injection Channel Descriptor 9, Word3 */
/*! @{ */

#define EIM_EICHD9_WORD3_B8_11DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD9_WORD3_B8_11DATA_MASK_SHIFT    (0U)
#define EIM_EICHD9_WORD3_B8_11DATA_MASK_WIDTH    (32U)
#define EIM_EICHD9_WORD3_B8_11DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD9_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD9_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD9_WORD4 - Error Injection Channel Descriptor 9, Word4 */
/*! @{ */

#define EIM_EICHD9_WORD4_B12_15DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD9_WORD4_B12_15DATA_MASK_SHIFT   (0U)
#define EIM_EICHD9_WORD4_B12_15DATA_MASK_WIDTH   (32U)
#define EIM_EICHD9_WORD4_B12_15DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD9_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_EICHD9_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD9_WORD5 - Error Injection Channel Descriptor 9, Word5 */
/*! @{ */

#define EIM_EICHD9_WORD5_B16_19DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD9_WORD5_B16_19DATA_MASK_SHIFT   (0U)
#define EIM_EICHD9_WORD5_B16_19DATA_MASK_WIDTH   (32U)
#define EIM_EICHD9_WORD5_B16_19DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD9_WORD5_B16_19DATA_MASK_SHIFT)) & EIM_EICHD9_WORD5_B16_19DATA_MASK_MASK)
/*! @} */

/*! @name EICHD10_WORD0 - Error Injection Channel Descriptor 10, Word0 */
/*! @{ */

#define EIM_EICHD10_WORD0_CHKBIT_MASK_MASK       (0xFFFC0000U)  /* Merged from fields with different position or width, of widths (9, 14), largest definition used */
#define EIM_EICHD10_WORD0_CHKBIT_MASK_SHIFT      (18U)
#define EIM_EICHD10_WORD0_CHKBIT_MASK_WIDTH      (14U)
#define EIM_EICHD10_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD10_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD10_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (9, 14), largest definition used */
/*! @} */

/*! @name EICHD10_WORD1 - Error Injection Channel Descriptor 10, Word1 */
/*! @{ */

#define EIM_EICHD10_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (1, 12, 20, 32), largest definition used */
#define EIM_EICHD10_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD10_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD10_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD10_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD10_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (1, 12, 20, 32), largest definition used */
/*! @} */

/*! @name EICHD10_WORD2 - Error Injection Channel Descriptor 10, Word2 */
/*! @{ */

#define EIM_EICHD10_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD10_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD10_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD10_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD10_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD10_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD10_WORD3 - Error Injection Channel Descriptor 10, Word3 */
/*! @{ */

#define EIM_EICHD10_WORD3_B8_11DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD10_WORD3_B8_11DATA_MASK_SHIFT   (0U)
#define EIM_EICHD10_WORD3_B8_11DATA_MASK_WIDTH   (32U)
#define EIM_EICHD10_WORD3_B8_11DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD10_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD10_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD10_WORD4 - Error Injection Channel Descriptor 10, Word4 */
/*! @{ */

#define EIM_EICHD10_WORD4_B12_15DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD10_WORD4_B12_15DATA_MASK_SHIFT  (0U)
#define EIM_EICHD10_WORD4_B12_15DATA_MASK_WIDTH  (32U)
#define EIM_EICHD10_WORD4_B12_15DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD10_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_EICHD10_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD10_WORD5 - Error Injection Channel Descriptor 10, Word5 */
/*! @{ */

#define EIM_EICHD10_WORD5_B16_19DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD10_WORD5_B16_19DATA_MASK_SHIFT  (0U)
#define EIM_EICHD10_WORD5_B16_19DATA_MASK_WIDTH  (32U)
#define EIM_EICHD10_WORD5_B16_19DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD10_WORD5_B16_19DATA_MASK_SHIFT)) & EIM_EICHD10_WORD5_B16_19DATA_MASK_MASK)
/*! @} */

/*! @name EICHD11_WORD0 - Error Injection Channel Descriptor 11, Word0 */
/*! @{ */

#define EIM_EICHD11_WORD0_CHKBIT_MASK_MASK       (0xFFFF0000U)  /* Merged from fields with different position or width, of widths (9, 16), largest definition used */
#define EIM_EICHD11_WORD0_CHKBIT_MASK_SHIFT      (16U)
#define EIM_EICHD11_WORD0_CHKBIT_MASK_WIDTH      (16U)
#define EIM_EICHD11_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD11_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD11_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (9, 16), largest definition used */
/*! @} */

/*! @name EICHD11_WORD1 - Error Injection Channel Descriptor 11, Word1 */
/*! @{ */

#define EIM_EICHD11_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (1, 20, 32), largest definition used */
#define EIM_EICHD11_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD11_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD11_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD11_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD11_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (1, 20, 32), largest definition used */
/*! @} */

/*! @name EICHD11_WORD2 - Error Injection Channel Descriptor 11, Word2 */
/*! @{ */

#define EIM_EICHD11_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD11_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD11_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD11_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD11_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD11_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD11_WORD3 - Error Injection Channel Descriptor 11, Word3 */
/*! @{ */

#define EIM_EICHD11_WORD3_B8_11DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD11_WORD3_B8_11DATA_MASK_SHIFT   (0U)
#define EIM_EICHD11_WORD3_B8_11DATA_MASK_WIDTH   (32U)
#define EIM_EICHD11_WORD3_B8_11DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD11_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD11_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD11_WORD4 - Error Injection Channel Descriptor 11, Word4 */
/*! @{ */

#define EIM_EICHD11_WORD4_B12_15DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD11_WORD4_B12_15DATA_MASK_SHIFT  (0U)
#define EIM_EICHD11_WORD4_B12_15DATA_MASK_WIDTH  (32U)
#define EIM_EICHD11_WORD4_B12_15DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD11_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_EICHD11_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD11_WORD5 - Error Injection Channel Descriptor 11, Word5 */
/*! @{ */

#define EIM_EICHD11_WORD5_B16_19DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD11_WORD5_B16_19DATA_MASK_SHIFT  (0U)
#define EIM_EICHD11_WORD5_B16_19DATA_MASK_WIDTH  (32U)
#define EIM_EICHD11_WORD5_B16_19DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD11_WORD5_B16_19DATA_MASK_SHIFT)) & EIM_EICHD11_WORD5_B16_19DATA_MASK_MASK)
/*! @} */

/*! @name EICHD12_WORD0 - Error Injection Channel Descriptor 12, Word0 */
/*! @{ */

#define EIM_EICHD12_WORD0_CHKBIT_MASK_MASK       (0xFFFFFFF0U)  /* Merged from fields with different position or width, of widths (24, 28), largest definition used */
#define EIM_EICHD12_WORD0_CHKBIT_MASK_SHIFT      (4U)
#define EIM_EICHD12_WORD0_CHKBIT_MASK_WIDTH      (28U)
#define EIM_EICHD12_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD12_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD12_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (24, 28), largest definition used */
/*! @} */

/*! @name EICHD12_WORD1 - Error Injection Channel Descriptor 12, Word1 */
/*! @{ */

#define EIM_EICHD12_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFU)  /* Merged from fields with different position or width, of widths (8, 12, 20, 28), largest definition used */
#define EIM_EICHD12_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD12_WORD1_B0_3DATA_MASK_WIDTH    (28U)
#define EIM_EICHD12_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD12_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD12_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (8, 12, 20, 28), largest definition used */
/*! @} */

/*! @name EICHD12_WORD2 - Error Injection Channel Descriptor 12, Word2 */
/*! @{ */

#define EIM_EICHD12_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD12_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD12_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD12_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD12_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD12_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD12_WORD3 - Error Injection Channel Descriptor 12, Word3 */
/*! @{ */

#define EIM_EICHD12_WORD3_B8_11DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD12_WORD3_B8_11DATA_MASK_SHIFT   (0U)
#define EIM_EICHD12_WORD3_B8_11DATA_MASK_WIDTH   (32U)
#define EIM_EICHD12_WORD3_B8_11DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD12_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD12_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD12_WORD4 - Error Injection Channel Descriptor 12, Word4 */
/*! @{ */

#define EIM_EICHD12_WORD4_B12_15DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD12_WORD4_B12_15DATA_MASK_SHIFT  (0U)
#define EIM_EICHD12_WORD4_B12_15DATA_MASK_WIDTH  (32U)
#define EIM_EICHD12_WORD4_B12_15DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD12_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_EICHD12_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD13_WORD0 - Error Injection Channel Descriptor 13, Word0 */
/*! @{ */

#define EIM_EICHD13_WORD0_CHKBIT_MASK_MASK       (0xFFFFFFF0U)  /* Merged from fields with different position or width, of widths (8, 24, 28), largest definition used */
#define EIM_EICHD13_WORD0_CHKBIT_MASK_SHIFT      (4U)
#define EIM_EICHD13_WORD0_CHKBIT_MASK_WIDTH      (28U)
#define EIM_EICHD13_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD13_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD13_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (8, 24, 28), largest definition used */
/*! @} */

/*! @name EICHD13_WORD1 - Error Injection Channel Descriptor 13, Word1 */
/*! @{ */

#define EIM_EICHD13_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (12, 32), largest definition used */
#define EIM_EICHD13_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD13_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD13_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD13_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD13_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (12, 32), largest definition used */
/*! @} */

/*! @name EICHD13_WORD2 - Error Injection Channel Descriptor 13, Word2 */
/*! @{ */

#define EIM_EICHD13_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD13_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD13_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD13_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD13_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD13_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD13_WORD3 - Error Injection Channel Descriptor 13, Word3 */
/*! @{ */

#define EIM_EICHD13_WORD3_B8_11DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD13_WORD3_B8_11DATA_MASK_SHIFT   (0U)
#define EIM_EICHD13_WORD3_B8_11DATA_MASK_WIDTH   (32U)
#define EIM_EICHD13_WORD3_B8_11DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD13_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD13_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD13_WORD4 - Error Injection Channel Descriptor 13, Word4 */
/*! @{ */

#define EIM_EICHD13_WORD4_B12_15DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD13_WORD4_B12_15DATA_MASK_SHIFT  (0U)
#define EIM_EICHD13_WORD4_B12_15DATA_MASK_WIDTH  (32U)
#define EIM_EICHD13_WORD4_B12_15DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD13_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_EICHD13_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD14_WORD0 - Error Injection Channel Descriptor 14, Word0 */
/*! @{ */

#define EIM_EICHD14_WORD0_CHKBIT_MASK_MASK       (0xFFFFFFF0U)  /* Merged from fields with different position or width, of widths (8, 24, 28), largest definition used */
#define EIM_EICHD14_WORD0_CHKBIT_MASK_SHIFT      (4U)
#define EIM_EICHD14_WORD0_CHKBIT_MASK_WIDTH      (28U)
#define EIM_EICHD14_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD14_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD14_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (8, 24, 28), largest definition used */
/*! @} */

/*! @name EICHD14_WORD1 - Error Injection Channel Descriptor 14, Word1 */
/*! @{ */

#define EIM_EICHD14_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (12, 32), largest definition used */
#define EIM_EICHD14_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD14_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD14_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD14_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD14_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (12, 32), largest definition used */
/*! @} */

/*! @name EICHD14_WORD2 - Error Injection Channel Descriptor 14, Word2 */
/*! @{ */

#define EIM_EICHD14_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD14_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD14_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD14_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD14_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD14_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD14_WORD3 - Error Injection Channel Descriptor 14, Word3 */
/*! @{ */

#define EIM_EICHD14_WORD3_B8_11DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD14_WORD3_B8_11DATA_MASK_SHIFT   (0U)
#define EIM_EICHD14_WORD3_B8_11DATA_MASK_WIDTH   (32U)
#define EIM_EICHD14_WORD3_B8_11DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD14_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD14_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD14_WORD4 - Error Injection Channel Descriptor 14, Word4 */
/*! @{ */

#define EIM_EICHD14_WORD4_B12_15DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD14_WORD4_B12_15DATA_MASK_SHIFT  (0U)
#define EIM_EICHD14_WORD4_B12_15DATA_MASK_WIDTH  (32U)
#define EIM_EICHD14_WORD4_B12_15DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD14_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_EICHD14_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD15_WORD0 - Error Injection Channel Descriptor 15, Word0 */
/*! @{ */

#define EIM_EICHD15_WORD0_CHKBIT_MASK_MASK       (0xFFFFFF00U)  /* Merged from fields with different position or width, of widths (8, 14, 24), largest definition used */
#define EIM_EICHD15_WORD0_CHKBIT_MASK_SHIFT      (8U)
#define EIM_EICHD15_WORD0_CHKBIT_MASK_WIDTH      (24U)
#define EIM_EICHD15_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD15_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD15_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (8, 14, 24), largest definition used */
/*! @} */

/*! @name EICHD15_WORD1 - Error Injection Channel Descriptor 15, Word1 */
/*! @{ */

#define EIM_EICHD15_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (12, 28, 32), largest definition used */
#define EIM_EICHD15_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD15_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD15_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD15_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD15_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (12, 28, 32), largest definition used */
/*! @} */

/*! @name EICHD15_WORD2 - Error Injection Channel Descriptor 15, Word2 */
/*! @{ */

#define EIM_EICHD15_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD15_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD15_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD15_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD15_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD15_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD15_WORD3 - Error Injection Channel Descriptor 15, Word3 */
/*! @{ */

#define EIM_EICHD15_WORD3_B8_11DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD15_WORD3_B8_11DATA_MASK_SHIFT   (0U)
#define EIM_EICHD15_WORD3_B8_11DATA_MASK_WIDTH   (32U)
#define EIM_EICHD15_WORD3_B8_11DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD15_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD15_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD16_WORD0 - Error Injection Channel Descriptor 16, Word0 */
/*! @{ */

#define EIM_EICHD16_WORD0_CHKBIT_MASK_MASK       (0xFFFF0000U)  /* Merged from fields with different position or width, of widths (9, 16), largest definition used */
#define EIM_EICHD16_WORD0_CHKBIT_MASK_SHIFT      (16U)
#define EIM_EICHD16_WORD0_CHKBIT_MASK_WIDTH      (16U)
#define EIM_EICHD16_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD16_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD16_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (9, 16), largest definition used */
/*! @} */

/*! @name EICHD16_WORD1 - Error Injection Channel Descriptor 16, Word1 */
/*! @{ */

#define EIM_EICHD16_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (1, 28, 32), largest definition used */
#define EIM_EICHD16_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD16_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD16_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD16_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD16_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (1, 28, 32), largest definition used */
/*! @} */

/*! @name EICHD16_WORD2 - Error Injection Channel Descriptor 16, Word2 */
/*! @{ */

#define EIM_EICHD16_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD16_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD16_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD16_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD16_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD16_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD16_WORD3 - Error Injection Channel Descriptor 16, Word3 */
/*! @{ */

#define EIM_EICHD16_WORD3_B8_11DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD16_WORD3_B8_11DATA_MASK_SHIFT   (0U)
#define EIM_EICHD16_WORD3_B8_11DATA_MASK_WIDTH   (32U)
#define EIM_EICHD16_WORD3_B8_11DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD16_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD16_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD16_WORD4 - Error Injection Channel Descriptor 16, Word4 */
/*! @{ */

#define EIM_EICHD16_WORD4_B12_15DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD16_WORD4_B12_15DATA_MASK_SHIFT  (0U)
#define EIM_EICHD16_WORD4_B12_15DATA_MASK_WIDTH  (32U)
#define EIM_EICHD16_WORD4_B12_15DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD16_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_EICHD16_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD16_WORD5 - Error Injection Channel Descriptor 16, Word5 */
/*! @{ */

#define EIM_EICHD16_WORD5_B16_19DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD16_WORD5_B16_19DATA_MASK_SHIFT  (0U)
#define EIM_EICHD16_WORD5_B16_19DATA_MASK_WIDTH  (32U)
#define EIM_EICHD16_WORD5_B16_19DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD16_WORD5_B16_19DATA_MASK_SHIFT)) & EIM_EICHD16_WORD5_B16_19DATA_MASK_MASK)
/*! @} */

/*! @name EICHD17_WORD0 - Error Injection Channel Descriptor 17, Word0 */
/*! @{ */

#define EIM_EICHD17_WORD0_CHKBIT_MASK_MASK       (0xFFFFFFF0U)  /* Merged from fields with different position or width, of widths (9, 28), largest definition used */
#define EIM_EICHD17_WORD0_CHKBIT_MASK_SHIFT      (4U)
#define EIM_EICHD17_WORD0_CHKBIT_MASK_WIDTH      (28U)
#define EIM_EICHD17_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD17_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD17_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (9, 28), largest definition used */
/*! @} */

/*! @name EICHD17_WORD1 - Error Injection Channel Descriptor 17, Word1 */
/*! @{ */

#define EIM_EICHD17_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (1, 8, 28, 32), largest definition used */
#define EIM_EICHD17_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD17_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD17_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD17_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD17_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (1, 8, 28, 32), largest definition used */
/*! @} */

/*! @name EICHD17_WORD2 - Error Injection Channel Descriptor 17, Word2 */
/*! @{ */

#define EIM_EICHD17_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD17_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD17_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD17_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD17_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD17_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD17_WORD3 - Error Injection Channel Descriptor 17, Word3 */
/*! @{ */

#define EIM_EICHD17_WORD3_B8_11DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD17_WORD3_B8_11DATA_MASK_SHIFT   (0U)
#define EIM_EICHD17_WORD3_B8_11DATA_MASK_WIDTH   (32U)
#define EIM_EICHD17_WORD3_B8_11DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD17_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD17_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD17_WORD4 - Error Injection Channel Descriptor 17, Word4 */
/*! @{ */

#define EIM_EICHD17_WORD4_B12_15DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD17_WORD4_B12_15DATA_MASK_SHIFT  (0U)
#define EIM_EICHD17_WORD4_B12_15DATA_MASK_WIDTH  (32U)
#define EIM_EICHD17_WORD4_B12_15DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD17_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_EICHD17_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD17_WORD5 - Error Injection Channel Descriptor 17, Word5 */
/*! @{ */

#define EIM_EICHD17_WORD5_B16_19DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD17_WORD5_B16_19DATA_MASK_SHIFT  (0U)
#define EIM_EICHD17_WORD5_B16_19DATA_MASK_WIDTH  (32U)
#define EIM_EICHD17_WORD5_B16_19DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD17_WORD5_B16_19DATA_MASK_SHIFT)) & EIM_EICHD17_WORD5_B16_19DATA_MASK_MASK)
/*! @} */

/*! @name EICHD18_WORD0 - Error Injection Channel Descriptor 18, Word0 */
/*! @{ */

#define EIM_EICHD18_WORD0_CHKBIT_MASK_MASK       (0xFFFFFFF0U)  /* Merged from fields with different position or width, of widths (9, 28), largest definition used */
#define EIM_EICHD18_WORD0_CHKBIT_MASK_SHIFT      (4U)
#define EIM_EICHD18_WORD0_CHKBIT_MASK_WIDTH      (28U)
#define EIM_EICHD18_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD18_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD18_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (9, 28), largest definition used */
/*! @} */

/*! @name EICHD18_WORD1 - Error Injection Channel Descriptor 18, Word1 */
/*! @{ */

#define EIM_EICHD18_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (1, 28, 32), largest definition used */
#define EIM_EICHD18_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD18_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD18_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD18_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD18_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (1, 28, 32), largest definition used */
/*! @} */

/*! @name EICHD18_WORD2 - Error Injection Channel Descriptor 18, Word2 */
/*! @{ */

#define EIM_EICHD18_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD18_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD18_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD18_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD18_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD18_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD18_WORD3 - Error Injection Channel Descriptor 18, Word3 */
/*! @{ */

#define EIM_EICHD18_WORD3_B8_11DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD18_WORD3_B8_11DATA_MASK_SHIFT   (0U)
#define EIM_EICHD18_WORD3_B8_11DATA_MASK_WIDTH   (32U)
#define EIM_EICHD18_WORD3_B8_11DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD18_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD18_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD18_WORD4 - Error Injection Channel Descriptor 18, Word4 */
/*! @{ */

#define EIM_EICHD18_WORD4_B12_15DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD18_WORD4_B12_15DATA_MASK_SHIFT  (0U)
#define EIM_EICHD18_WORD4_B12_15DATA_MASK_WIDTH  (32U)
#define EIM_EICHD18_WORD4_B12_15DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD18_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_EICHD18_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD18_WORD5 - Error Injection Channel Descriptor 18, Word5 */
/*! @{ */

#define EIM_EICHD18_WORD5_B16_19DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD18_WORD5_B16_19DATA_MASK_SHIFT  (0U)
#define EIM_EICHD18_WORD5_B16_19DATA_MASK_WIDTH  (32U)
#define EIM_EICHD18_WORD5_B16_19DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD18_WORD5_B16_19DATA_MASK_SHIFT)) & EIM_EICHD18_WORD5_B16_19DATA_MASK_MASK)
/*! @} */

/*! @name EICHD19_WORD0 - Error Injection Channel Descriptor 19, Word0 */
/*! @{ */

#define EIM_EICHD19_WORD0_CHKBIT_MASK_MASK       (0xFFFFFFF0U)  /* Merged from fields with different position or width, of widths (9, 28), largest definition used */
#define EIM_EICHD19_WORD0_CHKBIT_MASK_SHIFT      (4U)
#define EIM_EICHD19_WORD0_CHKBIT_MASK_WIDTH      (28U)
#define EIM_EICHD19_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD19_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD19_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (9, 28), largest definition used */
/*! @} */

/*! @name EICHD19_WORD1 - Error Injection Channel Descriptor 19, Word1 */
/*! @{ */

#define EIM_EICHD19_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (1, 28, 32), largest definition used */
#define EIM_EICHD19_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD19_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD19_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD19_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD19_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (1, 28, 32), largest definition used */
/*! @} */

/*! @name EICHD19_WORD2 - Error Injection Channel Descriptor 19, Word2 */
/*! @{ */

#define EIM_EICHD19_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD19_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD19_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD19_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD19_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD19_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD19_WORD3 - Error Injection Channel Descriptor 19, Word3 */
/*! @{ */

#define EIM_EICHD19_WORD3_B8_11DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD19_WORD3_B8_11DATA_MASK_SHIFT   (0U)
#define EIM_EICHD19_WORD3_B8_11DATA_MASK_WIDTH   (32U)
#define EIM_EICHD19_WORD3_B8_11DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD19_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD19_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD19_WORD4 - Error Injection Channel Descriptor 19, Word4 */
/*! @{ */

#define EIM_EICHD19_WORD4_B12_15DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD19_WORD4_B12_15DATA_MASK_SHIFT  (0U)
#define EIM_EICHD19_WORD4_B12_15DATA_MASK_WIDTH  (32U)
#define EIM_EICHD19_WORD4_B12_15DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD19_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_EICHD19_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD19_WORD5 - Error Injection Channel Descriptor 19, Word5 */
/*! @{ */

#define EIM_EICHD19_WORD5_B16_19DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD19_WORD5_B16_19DATA_MASK_SHIFT  (0U)
#define EIM_EICHD19_WORD5_B16_19DATA_MASK_WIDTH  (32U)
#define EIM_EICHD19_WORD5_B16_19DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD19_WORD5_B16_19DATA_MASK_SHIFT)) & EIM_EICHD19_WORD5_B16_19DATA_MASK_MASK)
/*! @} */

/*! @name EICHD20_WORD0 - Error Injection Channel Descriptor 20, Word0 */
/*! @{ */

#define EIM_EICHD20_WORD0_CHKBIT_MASK_MASK       (0xFFFFFF00U)  /* Merged from fields with different position or width, of widths (8, 24), largest definition used */
#define EIM_EICHD20_WORD0_CHKBIT_MASK_SHIFT      (8U)
#define EIM_EICHD20_WORD0_CHKBIT_MASK_WIDTH      (24U)
#define EIM_EICHD20_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD20_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD20_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (8, 24), largest definition used */
/*! @} */

/*! @name EICHD20_WORD1 - Error Injection Channel Descriptor 20, Word1 */
/*! @{ */

#define EIM_EICHD20_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (10, 12, 28, 32), largest definition used */
#define EIM_EICHD20_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD20_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD20_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD20_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD20_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (10, 12, 28, 32), largest definition used */
/*! @} */

/*! @name EICHD20_WORD2 - Error Injection Channel Descriptor 20, Word2 */
/*! @{ */

#define EIM_EICHD20_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD20_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD20_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD20_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD20_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD20_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD20_WORD3 - Error Injection Channel Descriptor 20, Word3 */
/*! @{ */

#define EIM_EICHD20_WORD3_B8_11DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD20_WORD3_B8_11DATA_MASK_SHIFT   (0U)
#define EIM_EICHD20_WORD3_B8_11DATA_MASK_WIDTH   (32U)
#define EIM_EICHD20_WORD3_B8_11DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD20_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD20_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD20_WORD4 - Error Injection Channel Descriptor 20, Word4 */
/*! @{ */

#define EIM_EICHD20_WORD4_B12_15DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD20_WORD4_B12_15DATA_MASK_SHIFT  (0U)
#define EIM_EICHD20_WORD4_B12_15DATA_MASK_WIDTH  (32U)
#define EIM_EICHD20_WORD4_B12_15DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD20_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_EICHD20_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD20_WORD5 - Error Injection Channel Descriptor 20, Word5 */
/*! @{ */

#define EIM_EICHD20_WORD5_B16_19DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD20_WORD5_B16_19DATA_MASK_SHIFT  (0U)
#define EIM_EICHD20_WORD5_B16_19DATA_MASK_WIDTH  (32U)
#define EIM_EICHD20_WORD5_B16_19DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD20_WORD5_B16_19DATA_MASK_SHIFT)) & EIM_EICHD20_WORD5_B16_19DATA_MASK_MASK)
/*! @} */

/*! @name EICHD21_WORD0 - Error Injection Channel Descriptor 21, Word0 */
/*! @{ */

#define EIM_EICHD21_WORD0_CHKBIT_MASK_MASK       (0xFFFFFF00U)  /* Merged from fields with different position or width, of widths (8, 10, 24), largest definition used */
#define EIM_EICHD21_WORD0_CHKBIT_MASK_SHIFT      (8U)
#define EIM_EICHD21_WORD0_CHKBIT_MASK_WIDTH      (24U)
#define EIM_EICHD21_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD21_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD21_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (8, 10, 24), largest definition used */
/*! @} */

/*! @name EICHD21_WORD1 - Error Injection Channel Descriptor 21, Word1 */
/*! @{ */

#define EIM_EICHD21_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (2, 12, 28, 32), largest definition used */
#define EIM_EICHD21_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD21_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD21_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD21_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD21_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (2, 12, 28, 32), largest definition used */
/*! @} */

/*! @name EICHD21_WORD2 - Error Injection Channel Descriptor 21, Word2 */
/*! @{ */

#define EIM_EICHD21_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD21_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD21_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD21_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD21_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD21_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD21_WORD3 - Error Injection Channel Descriptor 21, Word3 */
/*! @{ */

#define EIM_EICHD21_WORD3_B8_11DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD21_WORD3_B8_11DATA_MASK_SHIFT   (0U)
#define EIM_EICHD21_WORD3_B8_11DATA_MASK_WIDTH   (32U)
#define EIM_EICHD21_WORD3_B8_11DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD21_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD21_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD21_WORD4 - Error Injection Channel Descriptor 21, Word4 */
/*! @{ */

#define EIM_EICHD21_WORD4_B12_15DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD21_WORD4_B12_15DATA_MASK_SHIFT  (0U)
#define EIM_EICHD21_WORD4_B12_15DATA_MASK_WIDTH  (32U)
#define EIM_EICHD21_WORD4_B12_15DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD21_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_EICHD21_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD21_WORD5 - Error Injection Channel Descriptor 21, Word5 */
/*! @{ */

#define EIM_EICHD21_WORD5_B16_19DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD21_WORD5_B16_19DATA_MASK_SHIFT  (0U)
#define EIM_EICHD21_WORD5_B16_19DATA_MASK_WIDTH  (32U)
#define EIM_EICHD21_WORD5_B16_19DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD21_WORD5_B16_19DATA_MASK_SHIFT)) & EIM_EICHD21_WORD5_B16_19DATA_MASK_MASK)
/*! @} */

/*! @name EICHD22_WORD0 - Error Injection Channel Descriptor 22, Word0 */
/*! @{ */

#define EIM_EICHD22_WORD0_CHKBIT_MASK_MASK       (0xFFFFFF00U)  /* Merged from fields with different position or width, of widths (8, 24), largest definition used */
#define EIM_EICHD22_WORD0_CHKBIT_MASK_SHIFT      (8U)
#define EIM_EICHD22_WORD0_CHKBIT_MASK_WIDTH      (24U)
#define EIM_EICHD22_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD22_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD22_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (8, 24), largest definition used */
/*! @} */

/*! @name EICHD22_WORD1 - Error Injection Channel Descriptor 22, Word1 */
/*! @{ */

#define EIM_EICHD22_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (10, 12, 28, 32), largest definition used */
#define EIM_EICHD22_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD22_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD22_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD22_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD22_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (10, 12, 28, 32), largest definition used */
/*! @} */

/*! @name EICHD22_WORD2 - Error Injection Channel Descriptor 22, Word2 */
/*! @{ */

#define EIM_EICHD22_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD22_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD22_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD22_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD22_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD22_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD22_WORD3 - Error Injection Channel Descriptor 22, Word3 */
/*! @{ */

#define EIM_EICHD22_WORD3_B8_11DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD22_WORD3_B8_11DATA_MASK_SHIFT   (0U)
#define EIM_EICHD22_WORD3_B8_11DATA_MASK_WIDTH   (32U)
#define EIM_EICHD22_WORD3_B8_11DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD22_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD22_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD22_WORD4 - Error Injection Channel Descriptor 22, Word4 */
/*! @{ */

#define EIM_EICHD22_WORD4_B12_15DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD22_WORD4_B12_15DATA_MASK_SHIFT  (0U)
#define EIM_EICHD22_WORD4_B12_15DATA_MASK_WIDTH  (32U)
#define EIM_EICHD22_WORD4_B12_15DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD22_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_EICHD22_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD22_WORD5 - Error Injection Channel Descriptor 22, Word5 */
/*! @{ */

#define EIM_EICHD22_WORD5_B16_19DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD22_WORD5_B16_19DATA_MASK_SHIFT  (0U)
#define EIM_EICHD22_WORD5_B16_19DATA_MASK_WIDTH  (32U)
#define EIM_EICHD22_WORD5_B16_19DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD22_WORD5_B16_19DATA_MASK_SHIFT)) & EIM_EICHD22_WORD5_B16_19DATA_MASK_MASK)
/*! @} */

/*! @name EICHD23_WORD0 - Error Injection Channel Descriptor 23, Word0 */
/*! @{ */

#define EIM_EICHD23_WORD0_CHKBIT_MASK_MASK       (0xFFFFFF00U)  /* Merged from fields with different position or width, of widths (8, 10, 24), largest definition used */
#define EIM_EICHD23_WORD0_CHKBIT_MASK_SHIFT      (8U)
#define EIM_EICHD23_WORD0_CHKBIT_MASK_WIDTH      (24U)
#define EIM_EICHD23_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD23_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD23_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (8, 10, 24), largest definition used */
/*! @} */

/*! @name EICHD23_WORD1 - Error Injection Channel Descriptor 23, Word1 */
/*! @{ */

#define EIM_EICHD23_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (2, 12, 28, 32), largest definition used */
#define EIM_EICHD23_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD23_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD23_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD23_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD23_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (2, 12, 28, 32), largest definition used */
/*! @} */

/*! @name EICHD23_WORD2 - Error Injection Channel Descriptor 23, Word2 */
/*! @{ */

#define EIM_EICHD23_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD23_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD23_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD23_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD23_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD23_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD23_WORD3 - Error Injection Channel Descriptor 23, Word3 */
/*! @{ */

#define EIM_EICHD23_WORD3_B8_11DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD23_WORD3_B8_11DATA_MASK_SHIFT   (0U)
#define EIM_EICHD23_WORD3_B8_11DATA_MASK_WIDTH   (32U)
#define EIM_EICHD23_WORD3_B8_11DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD23_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD23_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD23_WORD4 - Error Injection Channel Descriptor 23, Word4 */
/*! @{ */

#define EIM_EICHD23_WORD4_B12_15DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD23_WORD4_B12_15DATA_MASK_SHIFT  (0U)
#define EIM_EICHD23_WORD4_B12_15DATA_MASK_WIDTH  (32U)
#define EIM_EICHD23_WORD4_B12_15DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD23_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_EICHD23_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD23_WORD5 - Error Injection Channel Descriptor 23, Word5 */
/*! @{ */

#define EIM_EICHD23_WORD5_B16_19DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_EICHD23_WORD5_B16_19DATA_MASK_SHIFT  (0U)
#define EIM_EICHD23_WORD5_B16_19DATA_MASK_WIDTH  (32U)
#define EIM_EICHD23_WORD5_B16_19DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_EICHD23_WORD5_B16_19DATA_MASK_SHIFT)) & EIM_EICHD23_WORD5_B16_19DATA_MASK_MASK)
/*! @} */

/*! @name EICHD24_WORD0 - Error Injection Channel Descriptor 24, Word0 */
/*! @{ */

#define EIM_EICHD24_WORD0_CHKBIT_MASK_MASK       (0xFFFFFF00U)  /* Merged from fields with different position or width, of widths (8, 24), largest definition used */
#define EIM_EICHD24_WORD0_CHKBIT_MASK_SHIFT      (8U)
#define EIM_EICHD24_WORD0_CHKBIT_MASK_WIDTH      (24U)
#define EIM_EICHD24_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD24_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD24_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (8, 24), largest definition used */
/*! @} */

/*! @name EICHD24_WORD1 - Error Injection Channel Descriptor 24, Word1 */
/*! @{ */

#define EIM_EICHD24_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (12, 28, 32), largest definition used */
#define EIM_EICHD24_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD24_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD24_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD24_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD24_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (12, 28, 32), largest definition used */
/*! @} */

/*! @name EICHD24_WORD2 - Error Injection Channel Descriptor 24, Word2 */
/*! @{ */

#define EIM_EICHD24_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD24_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD24_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD24_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD24_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD24_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD24_WORD3 - Error Injection Channel Descriptor 24, Word3 */
/*! @{ */

#define EIM_EICHD24_WORD3_B8_11DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD24_WORD3_B8_11DATA_MASK_SHIFT   (0U)
#define EIM_EICHD24_WORD3_B8_11DATA_MASK_WIDTH   (32U)
#define EIM_EICHD24_WORD3_B8_11DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD24_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD24_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD25_WORD0 - Error Injection Channel Descriptor 25, Word0 */
/*! @{ */

#define EIM_EICHD25_WORD0_CHKBIT_MASK_MASK       (0xFFFFFF00U)  /* Merged from fields with different position or width, of widths (8, 24), largest definition used */
#define EIM_EICHD25_WORD0_CHKBIT_MASK_SHIFT      (8U)
#define EIM_EICHD25_WORD0_CHKBIT_MASK_WIDTH      (24U)
#define EIM_EICHD25_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD25_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD25_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (8, 24), largest definition used */
/*! @} */

/*! @name EICHD25_WORD1 - Error Injection Channel Descriptor 25, Word1 */
/*! @{ */

#define EIM_EICHD25_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (12, 32), largest definition used */
#define EIM_EICHD25_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD25_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD25_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD25_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD25_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (12, 32), largest definition used */
/*! @} */

/*! @name EICHD25_WORD2 - Error Injection Channel Descriptor 25, Word2 */
/*! @{ */

#define EIM_EICHD25_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD25_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD25_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD25_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD25_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD25_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD25_WORD3 - Error Injection Channel Descriptor 25, Word3 */
/*! @{ */

#define EIM_EICHD25_WORD3_B8_11DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD25_WORD3_B8_11DATA_MASK_SHIFT   (0U)
#define EIM_EICHD25_WORD3_B8_11DATA_MASK_WIDTH   (32U)
#define EIM_EICHD25_WORD3_B8_11DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD25_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD25_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD26_WORD0 - Error Injection Channel Descriptor 26, Word0 */
/*! @{ */

#define EIM_EICHD26_WORD0_CHKBIT_MASK_MASK       (0xFFFFFF00U)  /* Merged from fields with different position or width, of widths (8, 24), largest definition used */
#define EIM_EICHD26_WORD0_CHKBIT_MASK_SHIFT      (8U)
#define EIM_EICHD26_WORD0_CHKBIT_MASK_WIDTH      (24U)
#define EIM_EICHD26_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD26_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD26_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (8, 24), largest definition used */
/*! @} */

/*! @name EICHD26_WORD1 - Error Injection Channel Descriptor 26, Word1 */
/*! @{ */

#define EIM_EICHD26_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (12, 32), largest definition used */
#define EIM_EICHD26_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD26_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD26_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD26_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD26_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (12, 32), largest definition used */
/*! @} */

/*! @name EICHD26_WORD2 - Error Injection Channel Descriptor 26, Word2 */
/*! @{ */

#define EIM_EICHD26_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD26_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD26_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD26_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD26_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD26_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD26_WORD3 - Error Injection Channel Descriptor 26, Word3 */
/*! @{ */

#define EIM_EICHD26_WORD3_B8_11DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD26_WORD3_B8_11DATA_MASK_SHIFT   (0U)
#define EIM_EICHD26_WORD3_B8_11DATA_MASK_WIDTH   (32U)
#define EIM_EICHD26_WORD3_B8_11DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD26_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD26_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD27_WORD0 - Error Injection Channel Descriptor 27, Word0 */
/*! @{ */

#define EIM_EICHD27_WORD0_CHKBIT_MASK_MASK       (0xFFFFFF00U)  /* Merged from fields with different position or width, of widths (8, 24), largest definition used */
#define EIM_EICHD27_WORD0_CHKBIT_MASK_SHIFT      (8U)
#define EIM_EICHD27_WORD0_CHKBIT_MASK_WIDTH      (24U)
#define EIM_EICHD27_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD27_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD27_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (8, 24), largest definition used */
/*! @} */

/*! @name EICHD27_WORD1 - Error Injection Channel Descriptor 27, Word1 */
/*! @{ */

#define EIM_EICHD27_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (12, 28, 32), largest definition used */
#define EIM_EICHD27_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD27_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD27_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD27_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD27_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (12, 28, 32), largest definition used */
/*! @} */

/*! @name EICHD27_WORD2 - Error Injection Channel Descriptor 27, Word2 */
/*! @{ */

#define EIM_EICHD27_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD27_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD27_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD27_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD27_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD27_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD27_WORD3 - Error Injection Channel Descriptor 27, Word3 */
/*! @{ */

#define EIM_EICHD27_WORD3_B8_11DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD27_WORD3_B8_11DATA_MASK_SHIFT   (0U)
#define EIM_EICHD27_WORD3_B8_11DATA_MASK_WIDTH   (32U)
#define EIM_EICHD27_WORD3_B8_11DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD27_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD27_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD28_WORD0 - Error Injection Channel Descriptor 28, Word0 */
/*! @{ */

#define EIM_EICHD28_WORD0_CHKBIT_MASK_MASK       (0xFF000000U)
#define EIM_EICHD28_WORD0_CHKBIT_MASK_SHIFT      (24U)
#define EIM_EICHD28_WORD0_CHKBIT_MASK_WIDTH      (8U)
#define EIM_EICHD28_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD28_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD28_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD28_WORD1 - Error Injection Channel Descriptor 28, Word1 */
/*! @{ */

#define EIM_EICHD28_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (2, 24, 32), largest definition used */
#define EIM_EICHD28_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD28_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD28_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD28_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD28_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (2, 24, 32), largest definition used */
/*! @} */

/*! @name EICHD29_WORD0 - Error Injection Channel Descriptor 29, Word0 */
/*! @{ */

#define EIM_EICHD29_WORD0_CHKBIT_MASK_MASK       (0xFF000000U)
#define EIM_EICHD29_WORD0_CHKBIT_MASK_SHIFT      (24U)
#define EIM_EICHD29_WORD0_CHKBIT_MASK_WIDTH      (8U)
#define EIM_EICHD29_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD29_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD29_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD29_WORD1 - Error Injection Channel Descriptor 29, Word1 */
/*! @{ */

#define EIM_EICHD29_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (26, 32), largest definition used */
#define EIM_EICHD29_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD29_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD29_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD29_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD29_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (26, 32), largest definition used */
/*! @} */

/*! @name EICHD29_WORD2 - Error Injection Channel Descriptor 29, Word2 */
/*! @{ */

#define EIM_EICHD29_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD29_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD29_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD29_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD29_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD29_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD30_WORD0 - Error Injection Channel Descriptor 30, Word0 */
/*! @{ */

#define EIM_EICHD30_WORD0_CHKBIT_MASK_MASK       (0xFF000000U)
#define EIM_EICHD30_WORD0_CHKBIT_MASK_SHIFT      (24U)
#define EIM_EICHD30_WORD0_CHKBIT_MASK_WIDTH      (8U)
#define EIM_EICHD30_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD30_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD30_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD30_WORD1 - Error Injection Channel Descriptor 30, Word1 */
/*! @{ */

#define EIM_EICHD30_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (26, 32), largest definition used */
#define EIM_EICHD30_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD30_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD30_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD30_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD30_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (26, 32), largest definition used */
/*! @} */

/*! @name EICHD31_WORD0 - Error Injection Channel Descriptor 31, Word0 */
/*! @{ */

#define EIM_EICHD31_WORD0_CHKBIT_MASK_MASK       (0xFF000000U)
#define EIM_EICHD31_WORD0_CHKBIT_MASK_SHIFT      (24U)
#define EIM_EICHD31_WORD0_CHKBIT_MASK_WIDTH      (8U)
#define EIM_EICHD31_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD31_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD31_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD31_WORD1 - Error Injection Channel Descriptor 31, Word1 */
/*! @{ */

#define EIM_EICHD31_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD31_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD31_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD31_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD31_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD31_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD31_WORD2 - Error Injection Channel Descriptor 31, Word2 */
/*! @{ */

#define EIM_EICHD31_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD31_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD31_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD31_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD31_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD31_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group EIM_Register_Masks */

/*!
 * @}
 */ /* end of group EIM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_EIM_H_) */
