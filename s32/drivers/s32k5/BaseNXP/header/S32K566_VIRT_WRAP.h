/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_VIRT_WRAP.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_VIRT_WRAP
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
#if !defined(S32K566_VIRT_WRAP_H_)  /* Check if memory map has not been already included */
#define S32K566_VIRT_WRAP_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- VIRT_WRAP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VIRT_WRAP_Peripheral_Access_Layer VIRT_WRAP Peripheral Access Layer
 * @{
 */

/** VIRT_WRAP - Size of Registers Arrays */
#define VIRT_WRAP_REG_C_COUNT                     1u
#define VIRT_WRAP_REG_D_COUNT                     1u

/** VIRT_WRAP - Register Layout Typedef */
typedef struct VIRT_WRAP_Struct {
  __IO uint32_t REG_A3_0;                          /**< Parameter_n Register, offset: 0x0, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A7_4;                          /**< Parameter_n Register, offset: 0x4, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A11_8;                         /**< Parameter_n Register, offset: 0x8, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A15_12;                        /**< Parameter_n Register, offset: 0xC, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A19_16;                        /**< Parameter_n Register, offset: 0x10, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A23_20;                        /**< Parameter_n Register, offset: 0x14, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A27_24;                        /**< Parameter_n Register, offset: 0x18, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A31_28;                        /**< Parameter_n Register, offset: 0x1C, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A35_32;                        /**< Parameter_n Register, offset: 0x20, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A39_36;                        /**< Parameter_n Register, offset: 0x24, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A43_40;                        /**< Parameter_n Register, offset: 0x28, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A47_44;                        /**< Parameter_n Register, offset: 0x2C, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A51_48;                        /**< Parameter_n Register, offset: 0x30, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A55_52;                        /**< Parameter_n Register, offset: 0x34, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A59_56;                        /**< Parameter_n Register, offset: 0x38, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A63_60;                        /**< Parameter_n Register, offset: 0x3C, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A67_64;                        /**< Parameter_n Register, offset: 0x40, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A71_68;                        /**< Parameter_n Register, offset: 0x44, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A75_72;                        /**< Parameter_n Register, offset: 0x48, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A79_76;                        /**< Parameter_n Register, offset: 0x4C, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A83_80;                        /**< Parameter_n Register, offset: 0x50, available only on: VWRAP_1 (missing on LPE_VWRAP, VWRAP_0, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A87_84;                        /**< Parameter_n Register, offset: 0x54, available only on: VWRAP_1 (missing on LPE_VWRAP, VWRAP_0, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A91_88;                        /**< Parameter_n Register, offset: 0x58, available only on: VWRAP_1 (missing on LPE_VWRAP, VWRAP_0, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A95_92;                        /**< Parameter_n Register, offset: 0x5C, available only on: VWRAP_1 (missing on LPE_VWRAP, VWRAP_0, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A99_96;                        /**< Parameter_n Register, offset: 0x60, available only on: VWRAP_1 (missing on LPE_VWRAP, VWRAP_0, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A103_100;                      /**< Parameter_n Register, offset: 0x64, available only on: VWRAP_1 (missing on LPE_VWRAP, VWRAP_0, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A107_104;                      /**< Parameter_n Register, offset: 0x68, available only on: VWRAP_1 (missing on LPE_VWRAP, VWRAP_0, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A111_108;                      /**< Parameter_n Register, offset: 0x6C, available only on: VWRAP_1 (missing on LPE_VWRAP, VWRAP_0, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A115_112;                      /**< Parameter_n Register, offset: 0x70, available only on: VWRAP_1 (missing on LPE_VWRAP, VWRAP_0, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A119_116;                      /**< Parameter_n Register, offset: 0x74, available only on: VWRAP_1 (missing on LPE_VWRAP, VWRAP_0, VWRAP_3, VWRAP_4) */
  uint8_t RESERVED_0[4];
  __IO uint32_t REG_A127_124;                      /**< Parameter_n Register, offset: 0x7C, available only on: VWRAP_1 (missing on LPE_VWRAP, VWRAP_0, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A131_128;                      /**< Parameter_n Register, offset: 0x80, available only on: VWRAP_1 (missing on LPE_VWRAP, VWRAP_0, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A135_132;                      /**< Parameter_n Register, offset: 0x84, available only on: VWRAP_1 (missing on LPE_VWRAP, VWRAP_0, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A139_136;                      /**< Parameter_n Register, offset: 0x88, available only on: VWRAP_1 (missing on LPE_VWRAP, VWRAP_0, VWRAP_3, VWRAP_4) */
  uint8_t RESERVED_1[20];
  __IO uint32_t REG_A163_160;                      /**< Parameter_n Register, offset: 0xA0, available only on: LPE_VWRAP (missing on VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A167_164;                      /**< Parameter_n Register, offset: 0xA4, available only on: LPE_VWRAP (missing on VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A171_168;                      /**< Parameter_n Register, offset: 0xA8, available only on: LPE_VWRAP (missing on VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A175_172;                      /**< Parameter_n Register, offset: 0xAC, available only on: LPE_VWRAP (missing on VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A179_176;                      /**< Parameter_n Register, offset: 0xB0, available only on: LPE_VWRAP (missing on VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A183_180;                      /**< Parameter_n Register, offset: 0xB4, available only on: LPE_VWRAP (missing on VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A187_184;                      /**< Parameter_n Register, offset: 0xB8, available only on: LPE_VWRAP (missing on VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A191_188;                      /**< Parameter_n Register, offset: 0xBC, available only on: LPE_VWRAP (missing on VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A195_192;                      /**< Parameter_n Register, offset: 0xC0, available only on: LPE_VWRAP (missing on VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A199_196;                      /**< Parameter_n Register, offset: 0xC4, available only on: LPE_VWRAP (missing on VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A203_200;                      /**< Parameter_n Register, offset: 0xC8, available only on: LPE_VWRAP (missing on VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A207_204;                      /**< Parameter_n Register, offset: 0xCC, available only on: LPE_VWRAP (missing on VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_A211_208;                      /**< Parameter_n Register, offset: 0xD0, available only on: VWRAP_3 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_A215_212;                      /**< Parameter_n Register, offset: 0xD4, available only on: VWRAP_3 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_A219_216;                      /**< Parameter_n Register, offset: 0xD8, available only on: VWRAP_3 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_A223_220;                      /**< Parameter_n Register, offset: 0xDC, available only on: VWRAP_3 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_A227_224;                      /**< Parameter_n Register, offset: 0xE0, available only on: VWRAP_3 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_A231_228;                      /**< Parameter_n Register, offset: 0xE4, available only on: VWRAP_3 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_A235_232;                      /**< Parameter_n Register, offset: 0xE8, available only on: VWRAP_3 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_A239_236;                      /**< Parameter_n Register, offset: 0xEC, available only on: VWRAP_3 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_A243_240;                      /**< Parameter_n Register, offset: 0xF0, available only on: VWRAP_3 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_A247_244;                      /**< Parameter_n Register, offset: 0xF4, available only on: VWRAP_3 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_A251_248;                      /**< Parameter_n Register, offset: 0xF8, available only on: VWRAP_3 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_A255_252;                      /**< Parameter_n Register, offset: 0xFC, available only on: VWRAP_3 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_A259_256;                      /**< Parameter_n Register, offset: 0x100, available only on: VWRAP_3 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_A263_260;                      /**< Parameter_n Register, offset: 0x104, available only on: VWRAP_3 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_4) */
  uint8_t RESERVED_2[40];
  __IO uint32_t REG_A307_304;                      /**< Parameter_n Register, offset: 0x130, available only on: VWRAP_4 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_3) */
  __IO uint32_t REG_A311_308;                      /**< Parameter_n Register, offset: 0x134, available only on: VWRAP_4 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_3) */
  __IO uint32_t REG_A315_312;                      /**< Parameter_n Register, offset: 0x138, available only on: VWRAP_4 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_3) */
  __IO uint32_t REG_A319_316;                      /**< Parameter_n Register, offset: 0x13C, available only on: VWRAP_4 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_3) */
  __IO uint32_t REG_A323_320;                      /**< Parameter_n Register, offset: 0x140, available only on: VWRAP_4 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_3) */
  __IO uint32_t REG_A327_324;                      /**< Parameter_n Register, offset: 0x144, available only on: VWRAP_4 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_3) */
  __IO uint32_t REG_A331_328;                      /**< Parameter_n Register, offset: 0x148, available only on: VWRAP_4 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_3) */
  __IO uint32_t REG_A335_332;                      /**< Parameter_n Register, offset: 0x14C, available only on: VWRAP_4 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_3) */
  __IO uint32_t REG_A339_336;                      /**< Parameter_n Register, offset: 0x150, available only on: VWRAP_4 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_3) */
  __IO uint32_t REG_A343_340;                      /**< Parameter_n Register, offset: 0x154, available only on: VWRAP_4 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_3) */
  __IO uint32_t REG_A347_344;                      /**< Parameter_n Register, offset: 0x158, available only on: VWRAP_4 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_3) */
  __IO uint32_t REG_A351_348;                      /**< Parameter_n Register, offset: 0x15C, available only on: VWRAP_4 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_3) */
  __IO uint32_t REG_A355_352;                      /**< Parameter_n Register, offset: 0x160, available only on: VWRAP_4 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_3) */
  __IO uint32_t REG_A359_356;                      /**< Parameter_n Register, offset: 0x164, available only on: VWRAP_4 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_3) */
  __IO uint32_t REG_A363_360;                      /**< Parameter_n Register, offset: 0x168, available only on: VWRAP_4 (missing on LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_3) */
  uint8_t RESERVED_3[660];
  __IO uint32_t REG_B3_0;                          /**< Parameter_n Register, offset: 0x400 */
  __IO uint32_t REG_B7_4;                          /**< Parameter_n Register, offset: 0x404 */
  __IO uint32_t REG_B11_8;                         /**< Parameter_n Register, offset: 0x408 */
  __IO uint32_t REG_B15_12;                        /**< Parameter_n Register, offset: 0x40C */
  __IO uint32_t REG_B19_16;                        /**< Parameter_n Register, offset: 0x410, available only on: LPE_VWRAP (missing on VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_B23_20;                        /**< Parameter_n Register, offset: 0x414, available only on: LPE_VWRAP (missing on VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_B27_24;                        /**< Parameter_n Register, offset: 0x418, available only on: LPE_VWRAP (missing on VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_B31_28;                        /**< Parameter_n Register, offset: 0x41C, available only on: LPE_VWRAP (missing on VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_B35_32;                        /**< Parameter_n Register, offset: 0x420 */
  __IO uint32_t REG_B39_36;                        /**< Parameter_n Register, offset: 0x424 */
  __IO uint32_t REG_B43_40;                        /**< Parameter_n Register, offset: 0x428 */
  __IO uint32_t REG_B47_44;                        /**< Parameter_n Register, offset: 0x42C */
  __IO uint32_t REG_B51_48;                        /**< Parameter_n Register, offset: 0x430, available only on: LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_3 (missing on VWRAP_4) */
  __IO uint32_t REG_B55_52;                        /**< Parameter_n Register, offset: 0x434, available only on: LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_3 (missing on VWRAP_4) */
  __IO uint32_t REG_B59_56;                        /**< Parameter_n Register, offset: 0x438, available only on: LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_3 (missing on VWRAP_4) */
  __IO uint32_t REG_B63_60;                        /**< Parameter_n Register, offset: 0x43C, available only on: LPE_VWRAP, VWRAP_0, VWRAP_1, VWRAP_3 (missing on VWRAP_4) */
  __IO uint32_t REG_B67_64;                        /**< Parameter_n Register, offset: 0x440, available only on: VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP) */
  __IO uint32_t REG_B71_68;                        /**< Parameter_n Register, offset: 0x444, available only on: VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP) */
  __IO uint32_t REG_B75_72;                        /**< Parameter_n Register, offset: 0x448 */
  __IO uint32_t REG_B79_76;                        /**< Parameter_n Register, offset: 0x44C */
  __IO uint32_t REG_B83_80;                        /**< Parameter_n Register, offset: 0x450 */
  __IO uint32_t REG_B87_84;                        /**< Parameter_n Register, offset: 0x454, available only on: LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4 (missing on VWRAP_0) */
  __IO uint32_t REG_B91_88;                        /**< Parameter_n Register, offset: 0x458, available only on: VWRAP_1, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP, VWRAP_0) */
  __IO uint32_t REG_B95_92;                        /**< Parameter_n Register, offset: 0x45C, available only on: LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4 (missing on VWRAP_0) */
  __IO uint32_t REG_B99_96;                        /**< Parameter_n Register, offset: 0x460 */
  __IO uint32_t REG_B103_100;                      /**< Parameter_n Register, offset: 0x464 */
  __IO uint32_t REG_B107_104;                      /**< Parameter_n Register, offset: 0x468, available only on: VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP) */
  __IO uint32_t REG_B111_108;                      /**< Parameter_n Register, offset: 0x46C */
  __IO uint32_t REG_B115_112;                      /**< Parameter_n Register, offset: 0x470, available only on: VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP) */
  __IO uint32_t REG_B119_116;                      /**< Parameter_n Register, offset: 0x474, available only on: VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP) */
  __IO uint32_t REG_B123_120;                      /**< Parameter_n Register, offset: 0x478, available only on: VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP) */
  __IO uint32_t REG_B127_124;                      /**< Parameter_n Register, offset: 0x47C, available only on: VWRAP_1, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP, VWRAP_0) */
  __IO uint32_t REG_B131_128;                      /**< Parameter_n Register, offset: 0x480, available only on: VWRAP_1, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP, VWRAP_0) */
  __IO uint32_t REG_B135_132;                      /**< Parameter_n Register, offset: 0x484, available only on: VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP) */
  __IO uint32_t REG_B139_136;                      /**< Parameter_n Register, offset: 0x488, available only on: VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP) */
  __IO uint32_t REG_B143_140;                      /**< Parameter_n Register, offset: 0x48C, available only on: VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP) */
  __IO uint32_t REG_B147_144;                      /**< Parameter_n Register, offset: 0x490, available only on: VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP) */
  __IO uint32_t REG_B151_148;                      /**< Parameter_n Register, offset: 0x494, available only on: VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP) */
  __IO uint32_t REG_B155_152;                      /**< Parameter_n Register, offset: 0x498, available only on: VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP) */
  __IO uint32_t REG_B159_156;                      /**< Parameter_n Register, offset: 0x49C, available only on: VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP) */
  __IO uint32_t REG_B163_160;                      /**< Parameter_n Register, offset: 0x4A0, available only on: VWRAP_0, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP, VWRAP_1) */
  __IO uint32_t REG_B167_164;                      /**< Parameter_n Register, offset: 0x4A4, available only on: VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP) */
  __IO uint32_t REG_B171_168;                      /**< Parameter_n Register, offset: 0x4A8, available only on: VWRAP_0, VWRAP_1, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP) */
  __IO uint32_t REG_B175_172;                      /**< Parameter_n Register, offset: 0x4AC, available only on: VWRAP_0, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP, VWRAP_1) */
  __IO uint32_t REG_B179_176;                      /**< Parameter_n Register, offset: 0x4B0, available only on: VWRAP_0, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP, VWRAP_1) */
  __IO uint32_t REG_B183_180;                      /**< Parameter_n Register, offset: 0x4B4, available only on: VWRAP_0, VWRAP_4 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3) */
  __IO uint32_t REG_B187_184;                      /**< Parameter_n Register, offset: 0x4B8, available only on: VWRAP_0, VWRAP_3, VWRAP_4 (missing on LPE_VWRAP, VWRAP_1) */
  __IO uint32_t REG_B191_188;                      /**< Parameter_n Register, offset: 0x4BC, available only on: VWRAP_0, VWRAP_3 (missing on LPE_VWRAP, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_B195_192;                      /**< Parameter_n Register, offset: 0x4C0, available only on: VWRAP_0, VWRAP_3 (missing on LPE_VWRAP, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_B199_196;                      /**< Parameter_n Register, offset: 0x4C4, available only on: VWRAP_0, VWRAP_3 (missing on LPE_VWRAP, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_B203_200;                      /**< Parameter_n Register, offset: 0x4C8, available only on: VWRAP_0, VWRAP_1, VWRAP_3 (missing on LPE_VWRAP, VWRAP_4) */
  __IO uint32_t REG_B207_204;                      /**< Parameter_n Register, offset: 0x4CC, available only on: VWRAP_0, VWRAP_3 (missing on LPE_VWRAP, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_B211_208;                      /**< Parameter_n Register, offset: 0x4D0, available only on: VWRAP_0, VWRAP_3 (missing on LPE_VWRAP, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_B215_212;                      /**< Parameter_n Register, offset: 0x4D4, available only on: VWRAP_0, VWRAP_3 (missing on LPE_VWRAP, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_B219_216;                      /**< Parameter_n Register, offset: 0x4D8, available only on: VWRAP_0, VWRAP_3 (missing on LPE_VWRAP, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_B223_220;                      /**< Parameter_n Register, offset: 0x4DC, available only on: VWRAP_0, VWRAP_3 (missing on LPE_VWRAP, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_B227_224;                      /**< Parameter_n Register, offset: 0x4E0, available only on: VWRAP_0, VWRAP_3 (missing on LPE_VWRAP, VWRAP_1, VWRAP_4) */
  __IO uint32_t REG_B231_228;                      /**< Parameter_n Register, offset: 0x4E4, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_B235_232;                      /**< Parameter_n Register, offset: 0x4E8, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_B239_236;                      /**< Parameter_n Register, offset: 0x4EC, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_B243_240;                      /**< Parameter_n Register, offset: 0x4F0, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_B247_244;                      /**< Parameter_n Register, offset: 0x4F4, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_B251_248;                      /**< Parameter_n Register, offset: 0x4F8, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  __IO uint32_t REG_B255_252;                      /**< Parameter_n Register, offset: 0x4FC, available only on: VWRAP_0 (missing on LPE_VWRAP, VWRAP_1, VWRAP_3, VWRAP_4) */
  uint8_t RESERVED_4[768];
  __IO uint32_t REG_C[VIRT_WRAP_REG_C_COUNT];      /**< Parameter_n Register, array offset: 0x800, array step: 0x4 */
  uint8_t RESERVED_5[1020];
  __IO uint32_t REG_D[VIRT_WRAP_REG_D_COUNT];      /**< Parameter_n Register, array offset: 0xC00, array step: 0x4 */
} VIRT_WRAP_Type, *VIRT_WRAP_MemMapPtr;

/** Number of instances of the VIRT_WRAP module. */
#define VIRT_WRAP_INSTANCE_COUNT                 (5u)

/* VIRT_WRAP - Peripheral instance base addresses */
/** Peripheral LPE_VWRAP base address */
#define IP_LPE_VWRAP_BASE                        (0x42088000u)
/** Peripheral LPE_VWRAP base pointer */
#define IP_LPE_VWRAP                             ((VIRT_WRAP_Type *)IP_LPE_VWRAP_BASE)
/** Peripheral VWRAP_0 base address */
#define IP_VWRAP_0_BASE                          (0x40010000u)
/** Peripheral VWRAP_0 base pointer */
#define IP_VWRAP_0                               ((VIRT_WRAP_Type *)IP_VWRAP_0_BASE)
/** Peripheral VWRAP_1 base address */
#define IP_VWRAP_1_BASE                          (0x40200000u)
/** Peripheral VWRAP_1 base pointer */
#define IP_VWRAP_1                               ((VIRT_WRAP_Type *)IP_VWRAP_1_BASE)
/** Peripheral VWRAP_3 base address */
#define IP_VWRAP_3_BASE                          (0x4060C000u)
/** Peripheral VWRAP_3 base pointer */
#define IP_VWRAP_3                               ((VIRT_WRAP_Type *)IP_VWRAP_3_BASE)
/** Peripheral VWRAP_4 base address */
#define IP_VWRAP_4_BASE                          (0x40800000u)
/** Peripheral VWRAP_4 base pointer */
#define IP_VWRAP_4                               ((VIRT_WRAP_Type *)IP_VWRAP_4_BASE)
/** Array initializer of VIRT_WRAP peripheral base addresses */
#define IP_VIRT_WRAP_BASE_ADDRS                  { IP_LPE_VWRAP_BASE, IP_VWRAP_0_BASE, IP_VWRAP_1_BASE, IP_VWRAP_3_BASE, IP_VWRAP_4_BASE }
/** Array initializer of VIRT_WRAP peripheral base pointers */
#define IP_VIRT_WRAP_BASE_PTRS                   { IP_LPE_VWRAP, IP_VWRAP_0, IP_VWRAP_1, IP_VWRAP_3, IP_VWRAP_4 }

/* ----------------------------------------------------------------------------
   -- VIRT_WRAP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VIRT_WRAP_Register_Masks VIRT_WRAP Register Masks
 * @{
 */

/*! @name REG_A3_0 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A3_0_PAD_0_MASK            (0xFU)
#define VIRT_WRAP_REG_A3_0_PAD_0_SHIFT           (0U)
#define VIRT_WRAP_REG_A3_0_PAD_0_WIDTH           (4U)
#define VIRT_WRAP_REG_A3_0_PAD_0(x)              (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A3_0_PAD_0_SHIFT)) & VIRT_WRAP_REG_A3_0_PAD_0_MASK)

#define VIRT_WRAP_REG_A3_0_PAD_1_MASK            (0xF00U)
#define VIRT_WRAP_REG_A3_0_PAD_1_SHIFT           (8U)
#define VIRT_WRAP_REG_A3_0_PAD_1_WIDTH           (4U)
#define VIRT_WRAP_REG_A3_0_PAD_1(x)              (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A3_0_PAD_1_SHIFT)) & VIRT_WRAP_REG_A3_0_PAD_1_MASK)

#define VIRT_WRAP_REG_A3_0_PAD_2_MASK            (0xF0000U)
#define VIRT_WRAP_REG_A3_0_PAD_2_SHIFT           (16U)
#define VIRT_WRAP_REG_A3_0_PAD_2_WIDTH           (4U)
#define VIRT_WRAP_REG_A3_0_PAD_2(x)              (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A3_0_PAD_2_SHIFT)) & VIRT_WRAP_REG_A3_0_PAD_2_MASK)

#define VIRT_WRAP_REG_A3_0_PAD_3_MASK            (0xF000000U)
#define VIRT_WRAP_REG_A3_0_PAD_3_SHIFT           (24U)
#define VIRT_WRAP_REG_A3_0_PAD_3_WIDTH           (4U)
#define VIRT_WRAP_REG_A3_0_PAD_3(x)              (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A3_0_PAD_3_SHIFT)) & VIRT_WRAP_REG_A3_0_PAD_3_MASK)
/*! @} */

/*! @name REG_A7_4 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A7_4_PAD_0_MASK            (0xFU)
#define VIRT_WRAP_REG_A7_4_PAD_0_SHIFT           (0U)
#define VIRT_WRAP_REG_A7_4_PAD_0_WIDTH           (4U)
#define VIRT_WRAP_REG_A7_4_PAD_0(x)              (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A7_4_PAD_0_SHIFT)) & VIRT_WRAP_REG_A7_4_PAD_0_MASK)

#define VIRT_WRAP_REG_A7_4_PAD_1_MASK            (0xF00U)
#define VIRT_WRAP_REG_A7_4_PAD_1_SHIFT           (8U)
#define VIRT_WRAP_REG_A7_4_PAD_1_WIDTH           (4U)
#define VIRT_WRAP_REG_A7_4_PAD_1(x)              (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A7_4_PAD_1_SHIFT)) & VIRT_WRAP_REG_A7_4_PAD_1_MASK)

#define VIRT_WRAP_REG_A7_4_PAD_2_MASK            (0xF0000U)
#define VIRT_WRAP_REG_A7_4_PAD_2_SHIFT           (16U)
#define VIRT_WRAP_REG_A7_4_PAD_2_WIDTH           (4U)
#define VIRT_WRAP_REG_A7_4_PAD_2(x)              (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A7_4_PAD_2_SHIFT)) & VIRT_WRAP_REG_A7_4_PAD_2_MASK)

#define VIRT_WRAP_REG_A7_4_PAD_3_MASK            (0xF000000U)
#define VIRT_WRAP_REG_A7_4_PAD_3_SHIFT           (24U)
#define VIRT_WRAP_REG_A7_4_PAD_3_WIDTH           (4U)
#define VIRT_WRAP_REG_A7_4_PAD_3(x)              (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A7_4_PAD_3_SHIFT)) & VIRT_WRAP_REG_A7_4_PAD_3_MASK)
/*! @} */

/*! @name REG_A11_8 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A11_8_PAD_0_MASK           (0xFU)
#define VIRT_WRAP_REG_A11_8_PAD_0_SHIFT          (0U)
#define VIRT_WRAP_REG_A11_8_PAD_0_WIDTH          (4U)
#define VIRT_WRAP_REG_A11_8_PAD_0(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A11_8_PAD_0_SHIFT)) & VIRT_WRAP_REG_A11_8_PAD_0_MASK)

#define VIRT_WRAP_REG_A11_8_PAD_1_MASK           (0xF00U)
#define VIRT_WRAP_REG_A11_8_PAD_1_SHIFT          (8U)
#define VIRT_WRAP_REG_A11_8_PAD_1_WIDTH          (4U)
#define VIRT_WRAP_REG_A11_8_PAD_1(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A11_8_PAD_1_SHIFT)) & VIRT_WRAP_REG_A11_8_PAD_1_MASK)

#define VIRT_WRAP_REG_A11_8_PAD_2_MASK           (0xF0000U)
#define VIRT_WRAP_REG_A11_8_PAD_2_SHIFT          (16U)
#define VIRT_WRAP_REG_A11_8_PAD_2_WIDTH          (4U)
#define VIRT_WRAP_REG_A11_8_PAD_2(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A11_8_PAD_2_SHIFT)) & VIRT_WRAP_REG_A11_8_PAD_2_MASK)

#define VIRT_WRAP_REG_A11_8_PAD_3_MASK           (0xF000000U)
#define VIRT_WRAP_REG_A11_8_PAD_3_SHIFT          (24U)
#define VIRT_WRAP_REG_A11_8_PAD_3_WIDTH          (4U)
#define VIRT_WRAP_REG_A11_8_PAD_3(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A11_8_PAD_3_SHIFT)) & VIRT_WRAP_REG_A11_8_PAD_3_MASK)
/*! @} */

/*! @name REG_A15_12 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A15_12_PAD_0_MASK          (0xFU)
#define VIRT_WRAP_REG_A15_12_PAD_0_SHIFT         (0U)
#define VIRT_WRAP_REG_A15_12_PAD_0_WIDTH         (4U)
#define VIRT_WRAP_REG_A15_12_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A15_12_PAD_0_SHIFT)) & VIRT_WRAP_REG_A15_12_PAD_0_MASK)

#define VIRT_WRAP_REG_A15_12_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A15_12_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A15_12_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A15_12_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A15_12_PAD_1_SHIFT)) & VIRT_WRAP_REG_A15_12_PAD_1_MASK)

#define VIRT_WRAP_REG_A15_12_PAD_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_A15_12_PAD_2_SHIFT         (16U)
#define VIRT_WRAP_REG_A15_12_PAD_2_WIDTH         (4U)
#define VIRT_WRAP_REG_A15_12_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A15_12_PAD_2_SHIFT)) & VIRT_WRAP_REG_A15_12_PAD_2_MASK)

#define VIRT_WRAP_REG_A15_12_PAD_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_A15_12_PAD_3_SHIFT         (24U)
#define VIRT_WRAP_REG_A15_12_PAD_3_WIDTH         (4U)
#define VIRT_WRAP_REG_A15_12_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A15_12_PAD_3_SHIFT)) & VIRT_WRAP_REG_A15_12_PAD_3_MASK)
/*! @} */

/*! @name REG_A19_16 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A19_16_PAD_0_MASK          (0xFU)
#define VIRT_WRAP_REG_A19_16_PAD_0_SHIFT         (0U)
#define VIRT_WRAP_REG_A19_16_PAD_0_WIDTH         (4U)
#define VIRT_WRAP_REG_A19_16_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A19_16_PAD_0_SHIFT)) & VIRT_WRAP_REG_A19_16_PAD_0_MASK)

#define VIRT_WRAP_REG_A19_16_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A19_16_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A19_16_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A19_16_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A19_16_PAD_1_SHIFT)) & VIRT_WRAP_REG_A19_16_PAD_1_MASK)

#define VIRT_WRAP_REG_A19_16_PAD_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_A19_16_PAD_2_SHIFT         (16U)
#define VIRT_WRAP_REG_A19_16_PAD_2_WIDTH         (4U)
#define VIRT_WRAP_REG_A19_16_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A19_16_PAD_2_SHIFT)) & VIRT_WRAP_REG_A19_16_PAD_2_MASK)

#define VIRT_WRAP_REG_A19_16_PAD_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_A19_16_PAD_3_SHIFT         (24U)
#define VIRT_WRAP_REG_A19_16_PAD_3_WIDTH         (4U)
#define VIRT_WRAP_REG_A19_16_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A19_16_PAD_3_SHIFT)) & VIRT_WRAP_REG_A19_16_PAD_3_MASK)
/*! @} */

/*! @name REG_A23_20 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A23_20_PAD_0_MASK          (0xFU)
#define VIRT_WRAP_REG_A23_20_PAD_0_SHIFT         (0U)
#define VIRT_WRAP_REG_A23_20_PAD_0_WIDTH         (4U)
#define VIRT_WRAP_REG_A23_20_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A23_20_PAD_0_SHIFT)) & VIRT_WRAP_REG_A23_20_PAD_0_MASK)

#define VIRT_WRAP_REG_A23_20_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A23_20_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A23_20_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A23_20_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A23_20_PAD_1_SHIFT)) & VIRT_WRAP_REG_A23_20_PAD_1_MASK)

#define VIRT_WRAP_REG_A23_20_PAD_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_A23_20_PAD_2_SHIFT         (16U)
#define VIRT_WRAP_REG_A23_20_PAD_2_WIDTH         (4U)
#define VIRT_WRAP_REG_A23_20_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A23_20_PAD_2_SHIFT)) & VIRT_WRAP_REG_A23_20_PAD_2_MASK)

#define VIRT_WRAP_REG_A23_20_PAD_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_A23_20_PAD_3_SHIFT         (24U)
#define VIRT_WRAP_REG_A23_20_PAD_3_WIDTH         (4U)
#define VIRT_WRAP_REG_A23_20_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A23_20_PAD_3_SHIFT)) & VIRT_WRAP_REG_A23_20_PAD_3_MASK)
/*! @} */

/*! @name REG_A27_24 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A27_24_PAD_0_MASK          (0xFU)
#define VIRT_WRAP_REG_A27_24_PAD_0_SHIFT         (0U)
#define VIRT_WRAP_REG_A27_24_PAD_0_WIDTH         (4U)
#define VIRT_WRAP_REG_A27_24_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A27_24_PAD_0_SHIFT)) & VIRT_WRAP_REG_A27_24_PAD_0_MASK)

#define VIRT_WRAP_REG_A27_24_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A27_24_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A27_24_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A27_24_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A27_24_PAD_1_SHIFT)) & VIRT_WRAP_REG_A27_24_PAD_1_MASK)

#define VIRT_WRAP_REG_A27_24_PAD_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_A27_24_PAD_2_SHIFT         (16U)
#define VIRT_WRAP_REG_A27_24_PAD_2_WIDTH         (4U)
#define VIRT_WRAP_REG_A27_24_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A27_24_PAD_2_SHIFT)) & VIRT_WRAP_REG_A27_24_PAD_2_MASK)

#define VIRT_WRAP_REG_A27_24_PAD_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_A27_24_PAD_3_SHIFT         (24U)
#define VIRT_WRAP_REG_A27_24_PAD_3_WIDTH         (4U)
#define VIRT_WRAP_REG_A27_24_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A27_24_PAD_3_SHIFT)) & VIRT_WRAP_REG_A27_24_PAD_3_MASK)
/*! @} */

/*! @name REG_A31_28 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A31_28_PAD_0_MASK          (0xFU)
#define VIRT_WRAP_REG_A31_28_PAD_0_SHIFT         (0U)
#define VIRT_WRAP_REG_A31_28_PAD_0_WIDTH         (4U)
#define VIRT_WRAP_REG_A31_28_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A31_28_PAD_0_SHIFT)) & VIRT_WRAP_REG_A31_28_PAD_0_MASK)

#define VIRT_WRAP_REG_A31_28_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A31_28_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A31_28_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A31_28_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A31_28_PAD_1_SHIFT)) & VIRT_WRAP_REG_A31_28_PAD_1_MASK)

#define VIRT_WRAP_REG_A31_28_PAD_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_A31_28_PAD_2_SHIFT         (16U)
#define VIRT_WRAP_REG_A31_28_PAD_2_WIDTH         (4U)
#define VIRT_WRAP_REG_A31_28_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A31_28_PAD_2_SHIFT)) & VIRT_WRAP_REG_A31_28_PAD_2_MASK)

#define VIRT_WRAP_REG_A31_28_PAD_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_A31_28_PAD_3_SHIFT         (24U)
#define VIRT_WRAP_REG_A31_28_PAD_3_WIDTH         (4U)
#define VIRT_WRAP_REG_A31_28_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A31_28_PAD_3_SHIFT)) & VIRT_WRAP_REG_A31_28_PAD_3_MASK)
/*! @} */

/*! @name REG_A35_32 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A35_32_PAD_0_MASK          (0xFU)
#define VIRT_WRAP_REG_A35_32_PAD_0_SHIFT         (0U)
#define VIRT_WRAP_REG_A35_32_PAD_0_WIDTH         (4U)
#define VIRT_WRAP_REG_A35_32_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A35_32_PAD_0_SHIFT)) & VIRT_WRAP_REG_A35_32_PAD_0_MASK)

#define VIRT_WRAP_REG_A35_32_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A35_32_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A35_32_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A35_32_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A35_32_PAD_1_SHIFT)) & VIRT_WRAP_REG_A35_32_PAD_1_MASK)

#define VIRT_WRAP_REG_A35_32_PAD_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_A35_32_PAD_2_SHIFT         (16U)
#define VIRT_WRAP_REG_A35_32_PAD_2_WIDTH         (4U)
#define VIRT_WRAP_REG_A35_32_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A35_32_PAD_2_SHIFT)) & VIRT_WRAP_REG_A35_32_PAD_2_MASK)

#define VIRT_WRAP_REG_A35_32_PAD_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_A35_32_PAD_3_SHIFT         (24U)
#define VIRT_WRAP_REG_A35_32_PAD_3_WIDTH         (4U)
#define VIRT_WRAP_REG_A35_32_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A35_32_PAD_3_SHIFT)) & VIRT_WRAP_REG_A35_32_PAD_3_MASK)
/*! @} */

/*! @name REG_A39_36 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A39_36_PAD_0_MASK          (0xFU)
#define VIRT_WRAP_REG_A39_36_PAD_0_SHIFT         (0U)
#define VIRT_WRAP_REG_A39_36_PAD_0_WIDTH         (4U)
#define VIRT_WRAP_REG_A39_36_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A39_36_PAD_0_SHIFT)) & VIRT_WRAP_REG_A39_36_PAD_0_MASK)

#define VIRT_WRAP_REG_A39_36_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A39_36_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A39_36_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A39_36_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A39_36_PAD_1_SHIFT)) & VIRT_WRAP_REG_A39_36_PAD_1_MASK)

#define VIRT_WRAP_REG_A39_36_PAD_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_A39_36_PAD_2_SHIFT         (16U)
#define VIRT_WRAP_REG_A39_36_PAD_2_WIDTH         (4U)
#define VIRT_WRAP_REG_A39_36_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A39_36_PAD_2_SHIFT)) & VIRT_WRAP_REG_A39_36_PAD_2_MASK)

#define VIRT_WRAP_REG_A39_36_PAD_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_A39_36_PAD_3_SHIFT         (24U)
#define VIRT_WRAP_REG_A39_36_PAD_3_WIDTH         (4U)
#define VIRT_WRAP_REG_A39_36_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A39_36_PAD_3_SHIFT)) & VIRT_WRAP_REG_A39_36_PAD_3_MASK)
/*! @} */

/*! @name REG_A43_40 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A43_40_PAD_0_MASK          (0xFU)
#define VIRT_WRAP_REG_A43_40_PAD_0_SHIFT         (0U)
#define VIRT_WRAP_REG_A43_40_PAD_0_WIDTH         (4U)
#define VIRT_WRAP_REG_A43_40_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A43_40_PAD_0_SHIFT)) & VIRT_WRAP_REG_A43_40_PAD_0_MASK)

#define VIRT_WRAP_REG_A43_40_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A43_40_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A43_40_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A43_40_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A43_40_PAD_1_SHIFT)) & VIRT_WRAP_REG_A43_40_PAD_1_MASK)

#define VIRT_WRAP_REG_A43_40_PAD_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_A43_40_PAD_2_SHIFT         (16U)
#define VIRT_WRAP_REG_A43_40_PAD_2_WIDTH         (4U)
#define VIRT_WRAP_REG_A43_40_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A43_40_PAD_2_SHIFT)) & VIRT_WRAP_REG_A43_40_PAD_2_MASK)

#define VIRT_WRAP_REG_A43_40_PAD_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_A43_40_PAD_3_SHIFT         (24U)
#define VIRT_WRAP_REG_A43_40_PAD_3_WIDTH         (4U)
#define VIRT_WRAP_REG_A43_40_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A43_40_PAD_3_SHIFT)) & VIRT_WRAP_REG_A43_40_PAD_3_MASK)
/*! @} */

/*! @name REG_A47_44 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A47_44_PAD_0_MASK          (0xFU)
#define VIRT_WRAP_REG_A47_44_PAD_0_SHIFT         (0U)
#define VIRT_WRAP_REG_A47_44_PAD_0_WIDTH         (4U)
#define VIRT_WRAP_REG_A47_44_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A47_44_PAD_0_SHIFT)) & VIRT_WRAP_REG_A47_44_PAD_0_MASK)

#define VIRT_WRAP_REG_A47_44_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A47_44_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A47_44_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A47_44_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A47_44_PAD_1_SHIFT)) & VIRT_WRAP_REG_A47_44_PAD_1_MASK)

#define VIRT_WRAP_REG_A47_44_PAD_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_A47_44_PAD_2_SHIFT         (16U)
#define VIRT_WRAP_REG_A47_44_PAD_2_WIDTH         (4U)
#define VIRT_WRAP_REG_A47_44_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A47_44_PAD_2_SHIFT)) & VIRT_WRAP_REG_A47_44_PAD_2_MASK)

#define VIRT_WRAP_REG_A47_44_PAD_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_A47_44_PAD_3_SHIFT         (24U)
#define VIRT_WRAP_REG_A47_44_PAD_3_WIDTH         (4U)
#define VIRT_WRAP_REG_A47_44_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A47_44_PAD_3_SHIFT)) & VIRT_WRAP_REG_A47_44_PAD_3_MASK)
/*! @} */

/*! @name REG_A51_48 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A51_48_PAD_0_MASK          (0xFU)
#define VIRT_WRAP_REG_A51_48_PAD_0_SHIFT         (0U)
#define VIRT_WRAP_REG_A51_48_PAD_0_WIDTH         (4U)
#define VIRT_WRAP_REG_A51_48_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A51_48_PAD_0_SHIFT)) & VIRT_WRAP_REG_A51_48_PAD_0_MASK)

#define VIRT_WRAP_REG_A51_48_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A51_48_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A51_48_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A51_48_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A51_48_PAD_1_SHIFT)) & VIRT_WRAP_REG_A51_48_PAD_1_MASK)

#define VIRT_WRAP_REG_A51_48_PAD_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_A51_48_PAD_3_SHIFT         (24U)
#define VIRT_WRAP_REG_A51_48_PAD_3_WIDTH         (4U)
#define VIRT_WRAP_REG_A51_48_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A51_48_PAD_3_SHIFT)) & VIRT_WRAP_REG_A51_48_PAD_3_MASK)
/*! @} */

/*! @name REG_A55_52 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A55_52_PAD_0_MASK          (0xFU)
#define VIRT_WRAP_REG_A55_52_PAD_0_SHIFT         (0U)
#define VIRT_WRAP_REG_A55_52_PAD_0_WIDTH         (4U)
#define VIRT_WRAP_REG_A55_52_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A55_52_PAD_0_SHIFT)) & VIRT_WRAP_REG_A55_52_PAD_0_MASK)

#define VIRT_WRAP_REG_A55_52_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A55_52_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A55_52_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A55_52_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A55_52_PAD_1_SHIFT)) & VIRT_WRAP_REG_A55_52_PAD_1_MASK)

#define VIRT_WRAP_REG_A55_52_PAD_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_A55_52_PAD_2_SHIFT         (16U)
#define VIRT_WRAP_REG_A55_52_PAD_2_WIDTH         (4U)
#define VIRT_WRAP_REG_A55_52_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A55_52_PAD_2_SHIFT)) & VIRT_WRAP_REG_A55_52_PAD_2_MASK)

#define VIRT_WRAP_REG_A55_52_PAD_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_A55_52_PAD_3_SHIFT         (24U)
#define VIRT_WRAP_REG_A55_52_PAD_3_WIDTH         (4U)
#define VIRT_WRAP_REG_A55_52_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A55_52_PAD_3_SHIFT)) & VIRT_WRAP_REG_A55_52_PAD_3_MASK)
/*! @} */

/*! @name REG_A59_56 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A59_56_PAD_0_MASK          (0xFU)
#define VIRT_WRAP_REG_A59_56_PAD_0_SHIFT         (0U)
#define VIRT_WRAP_REG_A59_56_PAD_0_WIDTH         (4U)
#define VIRT_WRAP_REG_A59_56_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A59_56_PAD_0_SHIFT)) & VIRT_WRAP_REG_A59_56_PAD_0_MASK)

#define VIRT_WRAP_REG_A59_56_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A59_56_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A59_56_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A59_56_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A59_56_PAD_1_SHIFT)) & VIRT_WRAP_REG_A59_56_PAD_1_MASK)

#define VIRT_WRAP_REG_A59_56_PAD_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_A59_56_PAD_2_SHIFT         (16U)
#define VIRT_WRAP_REG_A59_56_PAD_2_WIDTH         (4U)
#define VIRT_WRAP_REG_A59_56_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A59_56_PAD_2_SHIFT)) & VIRT_WRAP_REG_A59_56_PAD_2_MASK)

#define VIRT_WRAP_REG_A59_56_PAD_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_A59_56_PAD_3_SHIFT         (24U)
#define VIRT_WRAP_REG_A59_56_PAD_3_WIDTH         (4U)
#define VIRT_WRAP_REG_A59_56_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A59_56_PAD_3_SHIFT)) & VIRT_WRAP_REG_A59_56_PAD_3_MASK)
/*! @} */

/*! @name REG_A63_60 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A63_60_PAD_0_MASK          (0xFU)
#define VIRT_WRAP_REG_A63_60_PAD_0_SHIFT         (0U)
#define VIRT_WRAP_REG_A63_60_PAD_0_WIDTH         (4U)
#define VIRT_WRAP_REG_A63_60_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A63_60_PAD_0_SHIFT)) & VIRT_WRAP_REG_A63_60_PAD_0_MASK)

#define VIRT_WRAP_REG_A63_60_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A63_60_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A63_60_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A63_60_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A63_60_PAD_1_SHIFT)) & VIRT_WRAP_REG_A63_60_PAD_1_MASK)

#define VIRT_WRAP_REG_A63_60_PAD_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_A63_60_PAD_2_SHIFT         (16U)
#define VIRT_WRAP_REG_A63_60_PAD_2_WIDTH         (4U)
#define VIRT_WRAP_REG_A63_60_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A63_60_PAD_2_SHIFT)) & VIRT_WRAP_REG_A63_60_PAD_2_MASK)

#define VIRT_WRAP_REG_A63_60_PAD_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_A63_60_PAD_3_SHIFT         (24U)
#define VIRT_WRAP_REG_A63_60_PAD_3_WIDTH         (4U)
#define VIRT_WRAP_REG_A63_60_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A63_60_PAD_3_SHIFT)) & VIRT_WRAP_REG_A63_60_PAD_3_MASK)
/*! @} */

/*! @name REG_A67_64 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A67_64_PAD_0_MASK          (0xFU)
#define VIRT_WRAP_REG_A67_64_PAD_0_SHIFT         (0U)
#define VIRT_WRAP_REG_A67_64_PAD_0_WIDTH         (4U)
#define VIRT_WRAP_REG_A67_64_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A67_64_PAD_0_SHIFT)) & VIRT_WRAP_REG_A67_64_PAD_0_MASK)

#define VIRT_WRAP_REG_A67_64_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A67_64_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A67_64_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A67_64_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A67_64_PAD_1_SHIFT)) & VIRT_WRAP_REG_A67_64_PAD_1_MASK)

#define VIRT_WRAP_REG_A67_64_PAD_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_A67_64_PAD_2_SHIFT         (16U)
#define VIRT_WRAP_REG_A67_64_PAD_2_WIDTH         (4U)
#define VIRT_WRAP_REG_A67_64_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A67_64_PAD_2_SHIFT)) & VIRT_WRAP_REG_A67_64_PAD_2_MASK)

#define VIRT_WRAP_REG_A67_64_PAD_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_A67_64_PAD_3_SHIFT         (24U)
#define VIRT_WRAP_REG_A67_64_PAD_3_WIDTH         (4U)
#define VIRT_WRAP_REG_A67_64_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A67_64_PAD_3_SHIFT)) & VIRT_WRAP_REG_A67_64_PAD_3_MASK)
/*! @} */

/*! @name REG_A71_68 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A71_68_PAD_0_MASK          (0xFU)
#define VIRT_WRAP_REG_A71_68_PAD_0_SHIFT         (0U)
#define VIRT_WRAP_REG_A71_68_PAD_0_WIDTH         (4U)
#define VIRT_WRAP_REG_A71_68_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A71_68_PAD_0_SHIFT)) & VIRT_WRAP_REG_A71_68_PAD_0_MASK)

#define VIRT_WRAP_REG_A71_68_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A71_68_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A71_68_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A71_68_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A71_68_PAD_1_SHIFT)) & VIRT_WRAP_REG_A71_68_PAD_1_MASK)

#define VIRT_WRAP_REG_A71_68_PAD_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_A71_68_PAD_2_SHIFT         (16U)
#define VIRT_WRAP_REG_A71_68_PAD_2_WIDTH         (4U)
#define VIRT_WRAP_REG_A71_68_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A71_68_PAD_2_SHIFT)) & VIRT_WRAP_REG_A71_68_PAD_2_MASK)

#define VIRT_WRAP_REG_A71_68_PAD_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_A71_68_PAD_3_SHIFT         (24U)
#define VIRT_WRAP_REG_A71_68_PAD_3_WIDTH         (4U)
#define VIRT_WRAP_REG_A71_68_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A71_68_PAD_3_SHIFT)) & VIRT_WRAP_REG_A71_68_PAD_3_MASK)
/*! @} */

/*! @name REG_A75_72 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A75_72_PAD_0_MASK          (0xFU)
#define VIRT_WRAP_REG_A75_72_PAD_0_SHIFT         (0U)
#define VIRT_WRAP_REG_A75_72_PAD_0_WIDTH         (4U)
#define VIRT_WRAP_REG_A75_72_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A75_72_PAD_0_SHIFT)) & VIRT_WRAP_REG_A75_72_PAD_0_MASK)

#define VIRT_WRAP_REG_A75_72_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A75_72_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A75_72_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A75_72_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A75_72_PAD_1_SHIFT)) & VIRT_WRAP_REG_A75_72_PAD_1_MASK)

#define VIRT_WRAP_REG_A75_72_PAD_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_A75_72_PAD_2_SHIFT         (16U)
#define VIRT_WRAP_REG_A75_72_PAD_2_WIDTH         (4U)
#define VIRT_WRAP_REG_A75_72_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A75_72_PAD_2_SHIFT)) & VIRT_WRAP_REG_A75_72_PAD_2_MASK)

#define VIRT_WRAP_REG_A75_72_PAD_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_A75_72_PAD_3_SHIFT         (24U)
#define VIRT_WRAP_REG_A75_72_PAD_3_WIDTH         (4U)
#define VIRT_WRAP_REG_A75_72_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A75_72_PAD_3_SHIFT)) & VIRT_WRAP_REG_A75_72_PAD_3_MASK)
/*! @} */

/*! @name REG_A79_76 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A79_76_PAD_0_MASK          (0xFU)
#define VIRT_WRAP_REG_A79_76_PAD_0_SHIFT         (0U)
#define VIRT_WRAP_REG_A79_76_PAD_0_WIDTH         (4U)
#define VIRT_WRAP_REG_A79_76_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A79_76_PAD_0_SHIFT)) & VIRT_WRAP_REG_A79_76_PAD_0_MASK)

#define VIRT_WRAP_REG_A79_76_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A79_76_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A79_76_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A79_76_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A79_76_PAD_1_SHIFT)) & VIRT_WRAP_REG_A79_76_PAD_1_MASK)

#define VIRT_WRAP_REG_A79_76_PAD_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_A79_76_PAD_2_SHIFT         (16U)
#define VIRT_WRAP_REG_A79_76_PAD_2_WIDTH         (4U)
#define VIRT_WRAP_REG_A79_76_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A79_76_PAD_2_SHIFT)) & VIRT_WRAP_REG_A79_76_PAD_2_MASK)
/*! @} */

/*! @name REG_A83_80 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A83_80_PAD_0_MASK          (0xFU)
#define VIRT_WRAP_REG_A83_80_PAD_0_SHIFT         (0U)
#define VIRT_WRAP_REG_A83_80_PAD_0_WIDTH         (4U)
#define VIRT_WRAP_REG_A83_80_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A83_80_PAD_0_SHIFT)) & VIRT_WRAP_REG_A83_80_PAD_0_MASK)

#define VIRT_WRAP_REG_A83_80_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A83_80_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A83_80_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A83_80_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A83_80_PAD_1_SHIFT)) & VIRT_WRAP_REG_A83_80_PAD_1_MASK)

#define VIRT_WRAP_REG_A83_80_PAD_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_A83_80_PAD_2_SHIFT         (16U)
#define VIRT_WRAP_REG_A83_80_PAD_2_WIDTH         (4U)
#define VIRT_WRAP_REG_A83_80_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A83_80_PAD_2_SHIFT)) & VIRT_WRAP_REG_A83_80_PAD_2_MASK)

#define VIRT_WRAP_REG_A83_80_PAD_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_A83_80_PAD_3_SHIFT         (24U)
#define VIRT_WRAP_REG_A83_80_PAD_3_WIDTH         (4U)
#define VIRT_WRAP_REG_A83_80_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A83_80_PAD_3_SHIFT)) & VIRT_WRAP_REG_A83_80_PAD_3_MASK)
/*! @} */

/*! @name REG_A87_84 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A87_84_PAD_0_MASK          (0xFU)
#define VIRT_WRAP_REG_A87_84_PAD_0_SHIFT         (0U)
#define VIRT_WRAP_REG_A87_84_PAD_0_WIDTH         (4U)
#define VIRT_WRAP_REG_A87_84_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A87_84_PAD_0_SHIFT)) & VIRT_WRAP_REG_A87_84_PAD_0_MASK)

#define VIRT_WRAP_REG_A87_84_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A87_84_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A87_84_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A87_84_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A87_84_PAD_1_SHIFT)) & VIRT_WRAP_REG_A87_84_PAD_1_MASK)

#define VIRT_WRAP_REG_A87_84_PAD_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_A87_84_PAD_2_SHIFT         (16U)
#define VIRT_WRAP_REG_A87_84_PAD_2_WIDTH         (4U)
#define VIRT_WRAP_REG_A87_84_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A87_84_PAD_2_SHIFT)) & VIRT_WRAP_REG_A87_84_PAD_2_MASK)

#define VIRT_WRAP_REG_A87_84_PAD_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_A87_84_PAD_3_SHIFT         (24U)
#define VIRT_WRAP_REG_A87_84_PAD_3_WIDTH         (4U)
#define VIRT_WRAP_REG_A87_84_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A87_84_PAD_3_SHIFT)) & VIRT_WRAP_REG_A87_84_PAD_3_MASK)
/*! @} */

/*! @name REG_A91_88 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A91_88_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A91_88_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A91_88_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A91_88_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A91_88_PAD_1_SHIFT)) & VIRT_WRAP_REG_A91_88_PAD_1_MASK)

#define VIRT_WRAP_REG_A91_88_PAD_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_A91_88_PAD_2_SHIFT         (16U)
#define VIRT_WRAP_REG_A91_88_PAD_2_WIDTH         (4U)
#define VIRT_WRAP_REG_A91_88_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A91_88_PAD_2_SHIFT)) & VIRT_WRAP_REG_A91_88_PAD_2_MASK)

#define VIRT_WRAP_REG_A91_88_PAD_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_A91_88_PAD_3_SHIFT         (24U)
#define VIRT_WRAP_REG_A91_88_PAD_3_WIDTH         (4U)
#define VIRT_WRAP_REG_A91_88_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A91_88_PAD_3_SHIFT)) & VIRT_WRAP_REG_A91_88_PAD_3_MASK)
/*! @} */

/*! @name REG_A95_92 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A95_92_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A95_92_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A95_92_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A95_92_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A95_92_PAD_1_SHIFT)) & VIRT_WRAP_REG_A95_92_PAD_1_MASK)

#define VIRT_WRAP_REG_A95_92_PAD_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_A95_92_PAD_2_SHIFT         (16U)
#define VIRT_WRAP_REG_A95_92_PAD_2_WIDTH         (4U)
#define VIRT_WRAP_REG_A95_92_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A95_92_PAD_2_SHIFT)) & VIRT_WRAP_REG_A95_92_PAD_2_MASK)

#define VIRT_WRAP_REG_A95_92_PAD_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_A95_92_PAD_3_SHIFT         (24U)
#define VIRT_WRAP_REG_A95_92_PAD_3_WIDTH         (4U)
#define VIRT_WRAP_REG_A95_92_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A95_92_PAD_3_SHIFT)) & VIRT_WRAP_REG_A95_92_PAD_3_MASK)
/*! @} */

/*! @name REG_A99_96 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A99_96_PAD_0_MASK          (0xFU)
#define VIRT_WRAP_REG_A99_96_PAD_0_SHIFT         (0U)
#define VIRT_WRAP_REG_A99_96_PAD_0_WIDTH         (4U)
#define VIRT_WRAP_REG_A99_96_PAD_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A99_96_PAD_0_SHIFT)) & VIRT_WRAP_REG_A99_96_PAD_0_MASK)

#define VIRT_WRAP_REG_A99_96_PAD_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_A99_96_PAD_1_SHIFT         (8U)
#define VIRT_WRAP_REG_A99_96_PAD_1_WIDTH         (4U)
#define VIRT_WRAP_REG_A99_96_PAD_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A99_96_PAD_1_SHIFT)) & VIRT_WRAP_REG_A99_96_PAD_1_MASK)

#define VIRT_WRAP_REG_A99_96_PAD_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_A99_96_PAD_2_SHIFT         (16U)
#define VIRT_WRAP_REG_A99_96_PAD_2_WIDTH         (4U)
#define VIRT_WRAP_REG_A99_96_PAD_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A99_96_PAD_2_SHIFT)) & VIRT_WRAP_REG_A99_96_PAD_2_MASK)

#define VIRT_WRAP_REG_A99_96_PAD_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_A99_96_PAD_3_SHIFT         (24U)
#define VIRT_WRAP_REG_A99_96_PAD_3_WIDTH         (4U)
#define VIRT_WRAP_REG_A99_96_PAD_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A99_96_PAD_3_SHIFT)) & VIRT_WRAP_REG_A99_96_PAD_3_MASK)
/*! @} */

/*! @name REG_A103_100 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A103_100_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A103_100_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A103_100_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A103_100_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A103_100_PAD_0_SHIFT)) & VIRT_WRAP_REG_A103_100_PAD_0_MASK)

#define VIRT_WRAP_REG_A103_100_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A103_100_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A103_100_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A103_100_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A103_100_PAD_1_SHIFT)) & VIRT_WRAP_REG_A103_100_PAD_1_MASK)

#define VIRT_WRAP_REG_A103_100_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A103_100_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A103_100_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A103_100_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A103_100_PAD_2_SHIFT)) & VIRT_WRAP_REG_A103_100_PAD_2_MASK)

#define VIRT_WRAP_REG_A103_100_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A103_100_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A103_100_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A103_100_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A103_100_PAD_3_SHIFT)) & VIRT_WRAP_REG_A103_100_PAD_3_MASK)
/*! @} */

/*! @name REG_A107_104 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A107_104_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A107_104_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A107_104_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A107_104_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A107_104_PAD_0_SHIFT)) & VIRT_WRAP_REG_A107_104_PAD_0_MASK)

#define VIRT_WRAP_REG_A107_104_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A107_104_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A107_104_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A107_104_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A107_104_PAD_1_SHIFT)) & VIRT_WRAP_REG_A107_104_PAD_1_MASK)

#define VIRT_WRAP_REG_A107_104_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A107_104_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A107_104_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A107_104_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A107_104_PAD_2_SHIFT)) & VIRT_WRAP_REG_A107_104_PAD_2_MASK)

#define VIRT_WRAP_REG_A107_104_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A107_104_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A107_104_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A107_104_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A107_104_PAD_3_SHIFT)) & VIRT_WRAP_REG_A107_104_PAD_3_MASK)
/*! @} */

/*! @name REG_A111_108 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A111_108_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A111_108_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A111_108_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A111_108_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A111_108_PAD_0_SHIFT)) & VIRT_WRAP_REG_A111_108_PAD_0_MASK)

#define VIRT_WRAP_REG_A111_108_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A111_108_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A111_108_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A111_108_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A111_108_PAD_1_SHIFT)) & VIRT_WRAP_REG_A111_108_PAD_1_MASK)

#define VIRT_WRAP_REG_A111_108_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A111_108_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A111_108_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A111_108_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A111_108_PAD_2_SHIFT)) & VIRT_WRAP_REG_A111_108_PAD_2_MASK)

#define VIRT_WRAP_REG_A111_108_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A111_108_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A111_108_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A111_108_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A111_108_PAD_3_SHIFT)) & VIRT_WRAP_REG_A111_108_PAD_3_MASK)
/*! @} */

/*! @name REG_A115_112 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A115_112_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A115_112_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A115_112_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A115_112_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A115_112_PAD_0_SHIFT)) & VIRT_WRAP_REG_A115_112_PAD_0_MASK)
/*! @} */

/*! @name REG_A119_116 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A119_116_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A119_116_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A119_116_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A119_116_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A119_116_PAD_0_SHIFT)) & VIRT_WRAP_REG_A119_116_PAD_0_MASK)
/*! @} */

/*! @name REG_A127_124 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A127_124_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A127_124_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A127_124_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A127_124_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A127_124_PAD_2_SHIFT)) & VIRT_WRAP_REG_A127_124_PAD_2_MASK)

#define VIRT_WRAP_REG_A127_124_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A127_124_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A127_124_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A127_124_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A127_124_PAD_3_SHIFT)) & VIRT_WRAP_REG_A127_124_PAD_3_MASK)
/*! @} */

/*! @name REG_A131_128 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A131_128_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A131_128_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A131_128_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A131_128_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A131_128_PAD_0_SHIFT)) & VIRT_WRAP_REG_A131_128_PAD_0_MASK)

#define VIRT_WRAP_REG_A131_128_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A131_128_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A131_128_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A131_128_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A131_128_PAD_1_SHIFT)) & VIRT_WRAP_REG_A131_128_PAD_1_MASK)

#define VIRT_WRAP_REG_A131_128_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A131_128_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A131_128_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A131_128_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A131_128_PAD_2_SHIFT)) & VIRT_WRAP_REG_A131_128_PAD_2_MASK)

#define VIRT_WRAP_REG_A131_128_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A131_128_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A131_128_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A131_128_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A131_128_PAD_3_SHIFT)) & VIRT_WRAP_REG_A131_128_PAD_3_MASK)
/*! @} */

/*! @name REG_A135_132 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A135_132_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A135_132_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A135_132_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A135_132_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A135_132_PAD_0_SHIFT)) & VIRT_WRAP_REG_A135_132_PAD_0_MASK)

#define VIRT_WRAP_REG_A135_132_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A135_132_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A135_132_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A135_132_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A135_132_PAD_1_SHIFT)) & VIRT_WRAP_REG_A135_132_PAD_1_MASK)

#define VIRT_WRAP_REG_A135_132_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A135_132_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A135_132_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A135_132_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A135_132_PAD_2_SHIFT)) & VIRT_WRAP_REG_A135_132_PAD_2_MASK)

#define VIRT_WRAP_REG_A135_132_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A135_132_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A135_132_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A135_132_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A135_132_PAD_3_SHIFT)) & VIRT_WRAP_REG_A135_132_PAD_3_MASK)
/*! @} */

/*! @name REG_A139_136 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A139_136_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A139_136_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A139_136_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A139_136_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A139_136_PAD_0_SHIFT)) & VIRT_WRAP_REG_A139_136_PAD_0_MASK)

#define VIRT_WRAP_REG_A139_136_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A139_136_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A139_136_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A139_136_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A139_136_PAD_1_SHIFT)) & VIRT_WRAP_REG_A139_136_PAD_1_MASK)

#define VIRT_WRAP_REG_A139_136_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A139_136_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A139_136_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A139_136_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A139_136_PAD_2_SHIFT)) & VIRT_WRAP_REG_A139_136_PAD_2_MASK)
/*! @} */

/*! @name REG_A163_160 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A163_160_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A163_160_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A163_160_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A163_160_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A163_160_PAD_0_SHIFT)) & VIRT_WRAP_REG_A163_160_PAD_0_MASK)

#define VIRT_WRAP_REG_A163_160_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A163_160_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A163_160_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A163_160_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A163_160_PAD_1_SHIFT)) & VIRT_WRAP_REG_A163_160_PAD_1_MASK)

#define VIRT_WRAP_REG_A163_160_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A163_160_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A163_160_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A163_160_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A163_160_PAD_2_SHIFT)) & VIRT_WRAP_REG_A163_160_PAD_2_MASK)

#define VIRT_WRAP_REG_A163_160_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A163_160_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A163_160_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A163_160_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A163_160_PAD_3_SHIFT)) & VIRT_WRAP_REG_A163_160_PAD_3_MASK)
/*! @} */

/*! @name REG_A167_164 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A167_164_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A167_164_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A167_164_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A167_164_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A167_164_PAD_0_SHIFT)) & VIRT_WRAP_REG_A167_164_PAD_0_MASK)

#define VIRT_WRAP_REG_A167_164_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A167_164_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A167_164_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A167_164_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A167_164_PAD_1_SHIFT)) & VIRT_WRAP_REG_A167_164_PAD_1_MASK)

#define VIRT_WRAP_REG_A167_164_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A167_164_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A167_164_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A167_164_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A167_164_PAD_2_SHIFT)) & VIRT_WRAP_REG_A167_164_PAD_2_MASK)

#define VIRT_WRAP_REG_A167_164_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A167_164_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A167_164_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A167_164_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A167_164_PAD_3_SHIFT)) & VIRT_WRAP_REG_A167_164_PAD_3_MASK)
/*! @} */

/*! @name REG_A171_168 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A171_168_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A171_168_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A171_168_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A171_168_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A171_168_PAD_0_SHIFT)) & VIRT_WRAP_REG_A171_168_PAD_0_MASK)

#define VIRT_WRAP_REG_A171_168_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A171_168_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A171_168_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A171_168_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A171_168_PAD_1_SHIFT)) & VIRT_WRAP_REG_A171_168_PAD_1_MASK)

#define VIRT_WRAP_REG_A171_168_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A171_168_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A171_168_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A171_168_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A171_168_PAD_2_SHIFT)) & VIRT_WRAP_REG_A171_168_PAD_2_MASK)

#define VIRT_WRAP_REG_A171_168_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A171_168_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A171_168_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A171_168_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A171_168_PAD_3_SHIFT)) & VIRT_WRAP_REG_A171_168_PAD_3_MASK)
/*! @} */

/*! @name REG_A175_172 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A175_172_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A175_172_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A175_172_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A175_172_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A175_172_PAD_0_SHIFT)) & VIRT_WRAP_REG_A175_172_PAD_0_MASK)

#define VIRT_WRAP_REG_A175_172_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A175_172_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A175_172_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A175_172_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A175_172_PAD_1_SHIFT)) & VIRT_WRAP_REG_A175_172_PAD_1_MASK)

#define VIRT_WRAP_REG_A175_172_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A175_172_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A175_172_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A175_172_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A175_172_PAD_2_SHIFT)) & VIRT_WRAP_REG_A175_172_PAD_2_MASK)

#define VIRT_WRAP_REG_A175_172_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A175_172_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A175_172_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A175_172_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A175_172_PAD_3_SHIFT)) & VIRT_WRAP_REG_A175_172_PAD_3_MASK)
/*! @} */

/*! @name REG_A179_176 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A179_176_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A179_176_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A179_176_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A179_176_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A179_176_PAD_0_SHIFT)) & VIRT_WRAP_REG_A179_176_PAD_0_MASK)

#define VIRT_WRAP_REG_A179_176_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A179_176_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A179_176_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A179_176_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A179_176_PAD_1_SHIFT)) & VIRT_WRAP_REG_A179_176_PAD_1_MASK)

#define VIRT_WRAP_REG_A179_176_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A179_176_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A179_176_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A179_176_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A179_176_PAD_2_SHIFT)) & VIRT_WRAP_REG_A179_176_PAD_2_MASK)

#define VIRT_WRAP_REG_A179_176_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A179_176_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A179_176_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A179_176_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A179_176_PAD_3_SHIFT)) & VIRT_WRAP_REG_A179_176_PAD_3_MASK)
/*! @} */

/*! @name REG_A183_180 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A183_180_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A183_180_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A183_180_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A183_180_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A183_180_PAD_0_SHIFT)) & VIRT_WRAP_REG_A183_180_PAD_0_MASK)

#define VIRT_WRAP_REG_A183_180_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A183_180_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A183_180_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A183_180_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A183_180_PAD_1_SHIFT)) & VIRT_WRAP_REG_A183_180_PAD_1_MASK)

#define VIRT_WRAP_REG_A183_180_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A183_180_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A183_180_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A183_180_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A183_180_PAD_2_SHIFT)) & VIRT_WRAP_REG_A183_180_PAD_2_MASK)

#define VIRT_WRAP_REG_A183_180_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A183_180_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A183_180_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A183_180_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A183_180_PAD_3_SHIFT)) & VIRT_WRAP_REG_A183_180_PAD_3_MASK)
/*! @} */

/*! @name REG_A187_184 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A187_184_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A187_184_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A187_184_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A187_184_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A187_184_PAD_0_SHIFT)) & VIRT_WRAP_REG_A187_184_PAD_0_MASK)

#define VIRT_WRAP_REG_A187_184_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A187_184_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A187_184_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A187_184_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A187_184_PAD_1_SHIFT)) & VIRT_WRAP_REG_A187_184_PAD_1_MASK)

#define VIRT_WRAP_REG_A187_184_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A187_184_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A187_184_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A187_184_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A187_184_PAD_2_SHIFT)) & VIRT_WRAP_REG_A187_184_PAD_2_MASK)

#define VIRT_WRAP_REG_A187_184_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A187_184_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A187_184_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A187_184_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A187_184_PAD_3_SHIFT)) & VIRT_WRAP_REG_A187_184_PAD_3_MASK)
/*! @} */

/*! @name REG_A191_188 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A191_188_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A191_188_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A191_188_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A191_188_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A191_188_PAD_0_SHIFT)) & VIRT_WRAP_REG_A191_188_PAD_0_MASK)

#define VIRT_WRAP_REG_A191_188_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A191_188_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A191_188_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A191_188_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A191_188_PAD_1_SHIFT)) & VIRT_WRAP_REG_A191_188_PAD_1_MASK)

#define VIRT_WRAP_REG_A191_188_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A191_188_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A191_188_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A191_188_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A191_188_PAD_2_SHIFT)) & VIRT_WRAP_REG_A191_188_PAD_2_MASK)

#define VIRT_WRAP_REG_A191_188_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A191_188_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A191_188_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A191_188_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A191_188_PAD_3_SHIFT)) & VIRT_WRAP_REG_A191_188_PAD_3_MASK)
/*! @} */

/*! @name REG_A195_192 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A195_192_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A195_192_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A195_192_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A195_192_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A195_192_PAD_0_SHIFT)) & VIRT_WRAP_REG_A195_192_PAD_0_MASK)

#define VIRT_WRAP_REG_A195_192_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A195_192_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A195_192_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A195_192_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A195_192_PAD_1_SHIFT)) & VIRT_WRAP_REG_A195_192_PAD_1_MASK)

#define VIRT_WRAP_REG_A195_192_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A195_192_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A195_192_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A195_192_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A195_192_PAD_2_SHIFT)) & VIRT_WRAP_REG_A195_192_PAD_2_MASK)

#define VIRT_WRAP_REG_A195_192_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A195_192_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A195_192_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A195_192_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A195_192_PAD_3_SHIFT)) & VIRT_WRAP_REG_A195_192_PAD_3_MASK)
/*! @} */

/*! @name REG_A199_196 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A199_196_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A199_196_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A199_196_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A199_196_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A199_196_PAD_0_SHIFT)) & VIRT_WRAP_REG_A199_196_PAD_0_MASK)

#define VIRT_WRAP_REG_A199_196_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A199_196_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A199_196_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A199_196_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A199_196_PAD_1_SHIFT)) & VIRT_WRAP_REG_A199_196_PAD_1_MASK)

#define VIRT_WRAP_REG_A199_196_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A199_196_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A199_196_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A199_196_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A199_196_PAD_2_SHIFT)) & VIRT_WRAP_REG_A199_196_PAD_2_MASK)

#define VIRT_WRAP_REG_A199_196_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A199_196_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A199_196_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A199_196_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A199_196_PAD_3_SHIFT)) & VIRT_WRAP_REG_A199_196_PAD_3_MASK)
/*! @} */

/*! @name REG_A203_200 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A203_200_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A203_200_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A203_200_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A203_200_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A203_200_PAD_0_SHIFT)) & VIRT_WRAP_REG_A203_200_PAD_0_MASK)

#define VIRT_WRAP_REG_A203_200_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A203_200_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A203_200_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A203_200_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A203_200_PAD_1_SHIFT)) & VIRT_WRAP_REG_A203_200_PAD_1_MASK)

#define VIRT_WRAP_REG_A203_200_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A203_200_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A203_200_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A203_200_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A203_200_PAD_2_SHIFT)) & VIRT_WRAP_REG_A203_200_PAD_2_MASK)

#define VIRT_WRAP_REG_A203_200_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A203_200_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A203_200_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A203_200_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A203_200_PAD_3_SHIFT)) & VIRT_WRAP_REG_A203_200_PAD_3_MASK)
/*! @} */

/*! @name REG_A207_204 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A207_204_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A207_204_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A207_204_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A207_204_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A207_204_PAD_0_SHIFT)) & VIRT_WRAP_REG_A207_204_PAD_0_MASK)

#define VIRT_WRAP_REG_A207_204_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A207_204_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A207_204_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A207_204_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A207_204_PAD_1_SHIFT)) & VIRT_WRAP_REG_A207_204_PAD_1_MASK)

#define VIRT_WRAP_REG_A207_204_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A207_204_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A207_204_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A207_204_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A207_204_PAD_2_SHIFT)) & VIRT_WRAP_REG_A207_204_PAD_2_MASK)

#define VIRT_WRAP_REG_A207_204_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A207_204_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A207_204_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A207_204_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A207_204_PAD_3_SHIFT)) & VIRT_WRAP_REG_A207_204_PAD_3_MASK)
/*! @} */

/*! @name REG_A211_208 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A211_208_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A211_208_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A211_208_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A211_208_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A211_208_PAD_0_SHIFT)) & VIRT_WRAP_REG_A211_208_PAD_0_MASK)

#define VIRT_WRAP_REG_A211_208_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A211_208_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A211_208_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A211_208_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A211_208_PAD_1_SHIFT)) & VIRT_WRAP_REG_A211_208_PAD_1_MASK)
/*! @} */

/*! @name REG_A215_212 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A215_212_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A215_212_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A215_212_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A215_212_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A215_212_PAD_0_SHIFT)) & VIRT_WRAP_REG_A215_212_PAD_0_MASK)

#define VIRT_WRAP_REG_A215_212_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A215_212_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A215_212_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A215_212_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A215_212_PAD_1_SHIFT)) & VIRT_WRAP_REG_A215_212_PAD_1_MASK)

#define VIRT_WRAP_REG_A215_212_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A215_212_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A215_212_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A215_212_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A215_212_PAD_2_SHIFT)) & VIRT_WRAP_REG_A215_212_PAD_2_MASK)

#define VIRT_WRAP_REG_A215_212_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A215_212_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A215_212_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A215_212_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A215_212_PAD_3_SHIFT)) & VIRT_WRAP_REG_A215_212_PAD_3_MASK)
/*! @} */

/*! @name REG_A219_216 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A219_216_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A219_216_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A219_216_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A219_216_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A219_216_PAD_0_SHIFT)) & VIRT_WRAP_REG_A219_216_PAD_0_MASK)

#define VIRT_WRAP_REG_A219_216_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A219_216_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A219_216_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A219_216_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A219_216_PAD_1_SHIFT)) & VIRT_WRAP_REG_A219_216_PAD_1_MASK)

#define VIRT_WRAP_REG_A219_216_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A219_216_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A219_216_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A219_216_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A219_216_PAD_2_SHIFT)) & VIRT_WRAP_REG_A219_216_PAD_2_MASK)

#define VIRT_WRAP_REG_A219_216_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A219_216_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A219_216_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A219_216_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A219_216_PAD_3_SHIFT)) & VIRT_WRAP_REG_A219_216_PAD_3_MASK)
/*! @} */

/*! @name REG_A223_220 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A223_220_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A223_220_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A223_220_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A223_220_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A223_220_PAD_2_SHIFT)) & VIRT_WRAP_REG_A223_220_PAD_2_MASK)

#define VIRT_WRAP_REG_A223_220_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A223_220_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A223_220_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A223_220_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A223_220_PAD_3_SHIFT)) & VIRT_WRAP_REG_A223_220_PAD_3_MASK)
/*! @} */

/*! @name REG_A227_224 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A227_224_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A227_224_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A227_224_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A227_224_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A227_224_PAD_0_SHIFT)) & VIRT_WRAP_REG_A227_224_PAD_0_MASK)

#define VIRT_WRAP_REG_A227_224_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A227_224_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A227_224_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A227_224_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A227_224_PAD_1_SHIFT)) & VIRT_WRAP_REG_A227_224_PAD_1_MASK)

#define VIRT_WRAP_REG_A227_224_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A227_224_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A227_224_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A227_224_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A227_224_PAD_2_SHIFT)) & VIRT_WRAP_REG_A227_224_PAD_2_MASK)

#define VIRT_WRAP_REG_A227_224_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A227_224_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A227_224_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A227_224_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A227_224_PAD_3_SHIFT)) & VIRT_WRAP_REG_A227_224_PAD_3_MASK)
/*! @} */

/*! @name REG_A231_228 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A231_228_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A231_228_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A231_228_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A231_228_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A231_228_PAD_0_SHIFT)) & VIRT_WRAP_REG_A231_228_PAD_0_MASK)

#define VIRT_WRAP_REG_A231_228_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A231_228_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A231_228_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A231_228_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A231_228_PAD_3_SHIFT)) & VIRT_WRAP_REG_A231_228_PAD_3_MASK)
/*! @} */

/*! @name REG_A235_232 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A235_232_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A235_232_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A235_232_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A235_232_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A235_232_PAD_0_SHIFT)) & VIRT_WRAP_REG_A235_232_PAD_0_MASK)

#define VIRT_WRAP_REG_A235_232_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A235_232_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A235_232_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A235_232_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A235_232_PAD_1_SHIFT)) & VIRT_WRAP_REG_A235_232_PAD_1_MASK)

#define VIRT_WRAP_REG_A235_232_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A235_232_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A235_232_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A235_232_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A235_232_PAD_2_SHIFT)) & VIRT_WRAP_REG_A235_232_PAD_2_MASK)

#define VIRT_WRAP_REG_A235_232_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A235_232_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A235_232_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A235_232_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A235_232_PAD_3_SHIFT)) & VIRT_WRAP_REG_A235_232_PAD_3_MASK)
/*! @} */

/*! @name REG_A239_236 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A239_236_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A239_236_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A239_236_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A239_236_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A239_236_PAD_0_SHIFT)) & VIRT_WRAP_REG_A239_236_PAD_0_MASK)

#define VIRT_WRAP_REG_A239_236_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A239_236_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A239_236_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A239_236_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A239_236_PAD_1_SHIFT)) & VIRT_WRAP_REG_A239_236_PAD_1_MASK)

#define VIRT_WRAP_REG_A239_236_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A239_236_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A239_236_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A239_236_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A239_236_PAD_2_SHIFT)) & VIRT_WRAP_REG_A239_236_PAD_2_MASK)

#define VIRT_WRAP_REG_A239_236_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A239_236_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A239_236_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A239_236_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A239_236_PAD_3_SHIFT)) & VIRT_WRAP_REG_A239_236_PAD_3_MASK)
/*! @} */

/*! @name REG_A243_240 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A243_240_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A243_240_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A243_240_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A243_240_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A243_240_PAD_0_SHIFT)) & VIRT_WRAP_REG_A243_240_PAD_0_MASK)

#define VIRT_WRAP_REG_A243_240_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A243_240_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A243_240_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A243_240_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A243_240_PAD_1_SHIFT)) & VIRT_WRAP_REG_A243_240_PAD_1_MASK)

#define VIRT_WRAP_REG_A243_240_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A243_240_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A243_240_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A243_240_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A243_240_PAD_2_SHIFT)) & VIRT_WRAP_REG_A243_240_PAD_2_MASK)

#define VIRT_WRAP_REG_A243_240_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A243_240_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A243_240_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A243_240_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A243_240_PAD_3_SHIFT)) & VIRT_WRAP_REG_A243_240_PAD_3_MASK)
/*! @} */

/*! @name REG_A247_244 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A247_244_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A247_244_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A247_244_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A247_244_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A247_244_PAD_0_SHIFT)) & VIRT_WRAP_REG_A247_244_PAD_0_MASK)

#define VIRT_WRAP_REG_A247_244_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A247_244_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A247_244_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A247_244_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A247_244_PAD_1_SHIFT)) & VIRT_WRAP_REG_A247_244_PAD_1_MASK)

#define VIRT_WRAP_REG_A247_244_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A247_244_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A247_244_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A247_244_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A247_244_PAD_2_SHIFT)) & VIRT_WRAP_REG_A247_244_PAD_2_MASK)

#define VIRT_WRAP_REG_A247_244_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A247_244_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A247_244_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A247_244_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A247_244_PAD_3_SHIFT)) & VIRT_WRAP_REG_A247_244_PAD_3_MASK)
/*! @} */

/*! @name REG_A251_248 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A251_248_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A251_248_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A251_248_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A251_248_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A251_248_PAD_1_SHIFT)) & VIRT_WRAP_REG_A251_248_PAD_1_MASK)

#define VIRT_WRAP_REG_A251_248_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A251_248_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A251_248_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A251_248_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A251_248_PAD_3_SHIFT)) & VIRT_WRAP_REG_A251_248_PAD_3_MASK)
/*! @} */

/*! @name REG_A255_252 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A255_252_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A255_252_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A255_252_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A255_252_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A255_252_PAD_1_SHIFT)) & VIRT_WRAP_REG_A255_252_PAD_1_MASK)

#define VIRT_WRAP_REG_A255_252_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A255_252_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A255_252_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A255_252_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A255_252_PAD_2_SHIFT)) & VIRT_WRAP_REG_A255_252_PAD_2_MASK)
/*! @} */

/*! @name REG_A259_256 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A259_256_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A259_256_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A259_256_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A259_256_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A259_256_PAD_0_SHIFT)) & VIRT_WRAP_REG_A259_256_PAD_0_MASK)

#define VIRT_WRAP_REG_A259_256_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A259_256_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A259_256_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A259_256_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A259_256_PAD_1_SHIFT)) & VIRT_WRAP_REG_A259_256_PAD_1_MASK)

#define VIRT_WRAP_REG_A259_256_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A259_256_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A259_256_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A259_256_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A259_256_PAD_2_SHIFT)) & VIRT_WRAP_REG_A259_256_PAD_2_MASK)

#define VIRT_WRAP_REG_A259_256_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A259_256_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A259_256_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A259_256_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A259_256_PAD_3_SHIFT)) & VIRT_WRAP_REG_A259_256_PAD_3_MASK)
/*! @} */

/*! @name REG_A263_260 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A263_260_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A263_260_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A263_260_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A263_260_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A263_260_PAD_0_SHIFT)) & VIRT_WRAP_REG_A263_260_PAD_0_MASK)

#define VIRT_WRAP_REG_A263_260_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A263_260_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A263_260_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A263_260_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A263_260_PAD_1_SHIFT)) & VIRT_WRAP_REG_A263_260_PAD_1_MASK)

#define VIRT_WRAP_REG_A263_260_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A263_260_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A263_260_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A263_260_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A263_260_PAD_2_SHIFT)) & VIRT_WRAP_REG_A263_260_PAD_2_MASK)

#define VIRT_WRAP_REG_A263_260_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A263_260_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A263_260_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A263_260_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A263_260_PAD_3_SHIFT)) & VIRT_WRAP_REG_A263_260_PAD_3_MASK)
/*! @} */

/*! @name REG_A307_304 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A307_304_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A307_304_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A307_304_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A307_304_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A307_304_PAD_0_SHIFT)) & VIRT_WRAP_REG_A307_304_PAD_0_MASK)

#define VIRT_WRAP_REG_A307_304_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A307_304_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A307_304_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A307_304_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A307_304_PAD_1_SHIFT)) & VIRT_WRAP_REG_A307_304_PAD_1_MASK)

#define VIRT_WRAP_REG_A307_304_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A307_304_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A307_304_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A307_304_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A307_304_PAD_2_SHIFT)) & VIRT_WRAP_REG_A307_304_PAD_2_MASK)

#define VIRT_WRAP_REG_A307_304_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A307_304_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A307_304_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A307_304_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A307_304_PAD_3_SHIFT)) & VIRT_WRAP_REG_A307_304_PAD_3_MASK)
/*! @} */

/*! @name REG_A311_308 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A311_308_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A311_308_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A311_308_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A311_308_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A311_308_PAD_0_SHIFT)) & VIRT_WRAP_REG_A311_308_PAD_0_MASK)

#define VIRT_WRAP_REG_A311_308_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A311_308_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A311_308_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A311_308_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A311_308_PAD_1_SHIFT)) & VIRT_WRAP_REG_A311_308_PAD_1_MASK)

#define VIRT_WRAP_REG_A311_308_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A311_308_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A311_308_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A311_308_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A311_308_PAD_2_SHIFT)) & VIRT_WRAP_REG_A311_308_PAD_2_MASK)

#define VIRT_WRAP_REG_A311_308_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A311_308_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A311_308_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A311_308_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A311_308_PAD_3_SHIFT)) & VIRT_WRAP_REG_A311_308_PAD_3_MASK)
/*! @} */

/*! @name REG_A315_312 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A315_312_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A315_312_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A315_312_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A315_312_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A315_312_PAD_0_SHIFT)) & VIRT_WRAP_REG_A315_312_PAD_0_MASK)

#define VIRT_WRAP_REG_A315_312_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A315_312_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A315_312_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A315_312_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A315_312_PAD_1_SHIFT)) & VIRT_WRAP_REG_A315_312_PAD_1_MASK)

#define VIRT_WRAP_REG_A315_312_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A315_312_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A315_312_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A315_312_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A315_312_PAD_2_SHIFT)) & VIRT_WRAP_REG_A315_312_PAD_2_MASK)

#define VIRT_WRAP_REG_A315_312_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A315_312_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A315_312_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A315_312_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A315_312_PAD_3_SHIFT)) & VIRT_WRAP_REG_A315_312_PAD_3_MASK)
/*! @} */

/*! @name REG_A319_316 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A319_316_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A319_316_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A319_316_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A319_316_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A319_316_PAD_0_SHIFT)) & VIRT_WRAP_REG_A319_316_PAD_0_MASK)

#define VIRT_WRAP_REG_A319_316_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A319_316_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A319_316_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A319_316_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A319_316_PAD_1_SHIFT)) & VIRT_WRAP_REG_A319_316_PAD_1_MASK)

#define VIRT_WRAP_REG_A319_316_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A319_316_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A319_316_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A319_316_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A319_316_PAD_2_SHIFT)) & VIRT_WRAP_REG_A319_316_PAD_2_MASK)

#define VIRT_WRAP_REG_A319_316_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A319_316_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A319_316_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A319_316_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A319_316_PAD_3_SHIFT)) & VIRT_WRAP_REG_A319_316_PAD_3_MASK)
/*! @} */

/*! @name REG_A323_320 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A323_320_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A323_320_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A323_320_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A323_320_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A323_320_PAD_0_SHIFT)) & VIRT_WRAP_REG_A323_320_PAD_0_MASK)

#define VIRT_WRAP_REG_A323_320_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A323_320_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A323_320_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A323_320_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A323_320_PAD_1_SHIFT)) & VIRT_WRAP_REG_A323_320_PAD_1_MASK)

#define VIRT_WRAP_REG_A323_320_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A323_320_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A323_320_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A323_320_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A323_320_PAD_2_SHIFT)) & VIRT_WRAP_REG_A323_320_PAD_2_MASK)

#define VIRT_WRAP_REG_A323_320_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A323_320_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A323_320_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A323_320_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A323_320_PAD_3_SHIFT)) & VIRT_WRAP_REG_A323_320_PAD_3_MASK)
/*! @} */

/*! @name REG_A327_324 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A327_324_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A327_324_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A327_324_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A327_324_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A327_324_PAD_0_SHIFT)) & VIRT_WRAP_REG_A327_324_PAD_0_MASK)

#define VIRT_WRAP_REG_A327_324_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A327_324_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A327_324_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A327_324_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A327_324_PAD_1_SHIFT)) & VIRT_WRAP_REG_A327_324_PAD_1_MASK)

#define VIRT_WRAP_REG_A327_324_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A327_324_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A327_324_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A327_324_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A327_324_PAD_2_SHIFT)) & VIRT_WRAP_REG_A327_324_PAD_2_MASK)

#define VIRT_WRAP_REG_A327_324_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A327_324_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A327_324_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A327_324_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A327_324_PAD_3_SHIFT)) & VIRT_WRAP_REG_A327_324_PAD_3_MASK)
/*! @} */

/*! @name REG_A331_328 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A331_328_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A331_328_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A331_328_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A331_328_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A331_328_PAD_0_SHIFT)) & VIRT_WRAP_REG_A331_328_PAD_0_MASK)

#define VIRT_WRAP_REG_A331_328_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A331_328_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A331_328_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A331_328_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A331_328_PAD_1_SHIFT)) & VIRT_WRAP_REG_A331_328_PAD_1_MASK)

#define VIRT_WRAP_REG_A331_328_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A331_328_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A331_328_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A331_328_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A331_328_PAD_2_SHIFT)) & VIRT_WRAP_REG_A331_328_PAD_2_MASK)

#define VIRT_WRAP_REG_A331_328_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A331_328_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A331_328_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A331_328_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A331_328_PAD_3_SHIFT)) & VIRT_WRAP_REG_A331_328_PAD_3_MASK)
/*! @} */

/*! @name REG_A335_332 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A335_332_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A335_332_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A335_332_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A335_332_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A335_332_PAD_0_SHIFT)) & VIRT_WRAP_REG_A335_332_PAD_0_MASK)

#define VIRT_WRAP_REG_A335_332_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A335_332_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A335_332_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A335_332_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A335_332_PAD_1_SHIFT)) & VIRT_WRAP_REG_A335_332_PAD_1_MASK)

#define VIRT_WRAP_REG_A335_332_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A335_332_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A335_332_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A335_332_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A335_332_PAD_2_SHIFT)) & VIRT_WRAP_REG_A335_332_PAD_2_MASK)

#define VIRT_WRAP_REG_A335_332_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A335_332_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A335_332_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A335_332_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A335_332_PAD_3_SHIFT)) & VIRT_WRAP_REG_A335_332_PAD_3_MASK)
/*! @} */

/*! @name REG_A339_336 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A339_336_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A339_336_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A339_336_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A339_336_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A339_336_PAD_0_SHIFT)) & VIRT_WRAP_REG_A339_336_PAD_0_MASK)

#define VIRT_WRAP_REG_A339_336_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A339_336_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A339_336_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A339_336_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A339_336_PAD_1_SHIFT)) & VIRT_WRAP_REG_A339_336_PAD_1_MASK)

#define VIRT_WRAP_REG_A339_336_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A339_336_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A339_336_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A339_336_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A339_336_PAD_2_SHIFT)) & VIRT_WRAP_REG_A339_336_PAD_2_MASK)

#define VIRT_WRAP_REG_A339_336_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A339_336_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A339_336_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A339_336_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A339_336_PAD_3_SHIFT)) & VIRT_WRAP_REG_A339_336_PAD_3_MASK)
/*! @} */

/*! @name REG_A343_340 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A343_340_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A343_340_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A343_340_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A343_340_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A343_340_PAD_0_SHIFT)) & VIRT_WRAP_REG_A343_340_PAD_0_MASK)

#define VIRT_WRAP_REG_A343_340_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A343_340_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A343_340_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A343_340_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A343_340_PAD_1_SHIFT)) & VIRT_WRAP_REG_A343_340_PAD_1_MASK)

#define VIRT_WRAP_REG_A343_340_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A343_340_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A343_340_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A343_340_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A343_340_PAD_2_SHIFT)) & VIRT_WRAP_REG_A343_340_PAD_2_MASK)

#define VIRT_WRAP_REG_A343_340_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A343_340_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A343_340_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A343_340_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A343_340_PAD_3_SHIFT)) & VIRT_WRAP_REG_A343_340_PAD_3_MASK)
/*! @} */

/*! @name REG_A347_344 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A347_344_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A347_344_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A347_344_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A347_344_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A347_344_PAD_0_SHIFT)) & VIRT_WRAP_REG_A347_344_PAD_0_MASK)

#define VIRT_WRAP_REG_A347_344_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A347_344_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A347_344_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A347_344_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A347_344_PAD_1_SHIFT)) & VIRT_WRAP_REG_A347_344_PAD_1_MASK)

#define VIRT_WRAP_REG_A347_344_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A347_344_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A347_344_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A347_344_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A347_344_PAD_2_SHIFT)) & VIRT_WRAP_REG_A347_344_PAD_2_MASK)

#define VIRT_WRAP_REG_A347_344_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A347_344_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A347_344_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A347_344_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A347_344_PAD_3_SHIFT)) & VIRT_WRAP_REG_A347_344_PAD_3_MASK)
/*! @} */

/*! @name REG_A351_348 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A351_348_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A351_348_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A351_348_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A351_348_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A351_348_PAD_0_SHIFT)) & VIRT_WRAP_REG_A351_348_PAD_0_MASK)

#define VIRT_WRAP_REG_A351_348_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A351_348_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A351_348_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A351_348_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A351_348_PAD_1_SHIFT)) & VIRT_WRAP_REG_A351_348_PAD_1_MASK)

#define VIRT_WRAP_REG_A351_348_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A351_348_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A351_348_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A351_348_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A351_348_PAD_2_SHIFT)) & VIRT_WRAP_REG_A351_348_PAD_2_MASK)

#define VIRT_WRAP_REG_A351_348_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A351_348_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A351_348_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A351_348_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A351_348_PAD_3_SHIFT)) & VIRT_WRAP_REG_A351_348_PAD_3_MASK)
/*! @} */

/*! @name REG_A355_352 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A355_352_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A355_352_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A355_352_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A355_352_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A355_352_PAD_0_SHIFT)) & VIRT_WRAP_REG_A355_352_PAD_0_MASK)

#define VIRT_WRAP_REG_A355_352_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A355_352_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A355_352_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A355_352_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A355_352_PAD_1_SHIFT)) & VIRT_WRAP_REG_A355_352_PAD_1_MASK)

#define VIRT_WRAP_REG_A355_352_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A355_352_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A355_352_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A355_352_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A355_352_PAD_2_SHIFT)) & VIRT_WRAP_REG_A355_352_PAD_2_MASK)

#define VIRT_WRAP_REG_A355_352_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A355_352_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A355_352_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A355_352_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A355_352_PAD_3_SHIFT)) & VIRT_WRAP_REG_A355_352_PAD_3_MASK)
/*! @} */

/*! @name REG_A359_356 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A359_356_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A359_356_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A359_356_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A359_356_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A359_356_PAD_0_SHIFT)) & VIRT_WRAP_REG_A359_356_PAD_0_MASK)

#define VIRT_WRAP_REG_A359_356_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A359_356_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A359_356_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A359_356_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A359_356_PAD_1_SHIFT)) & VIRT_WRAP_REG_A359_356_PAD_1_MASK)

#define VIRT_WRAP_REG_A359_356_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A359_356_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A359_356_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A359_356_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A359_356_PAD_2_SHIFT)) & VIRT_WRAP_REG_A359_356_PAD_2_MASK)

#define VIRT_WRAP_REG_A359_356_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A359_356_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A359_356_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A359_356_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A359_356_PAD_3_SHIFT)) & VIRT_WRAP_REG_A359_356_PAD_3_MASK)
/*! @} */

/*! @name REG_A363_360 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_A363_360_PAD_0_MASK        (0xFU)
#define VIRT_WRAP_REG_A363_360_PAD_0_SHIFT       (0U)
#define VIRT_WRAP_REG_A363_360_PAD_0_WIDTH       (4U)
#define VIRT_WRAP_REG_A363_360_PAD_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A363_360_PAD_0_SHIFT)) & VIRT_WRAP_REG_A363_360_PAD_0_MASK)

#define VIRT_WRAP_REG_A363_360_PAD_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_A363_360_PAD_1_SHIFT       (8U)
#define VIRT_WRAP_REG_A363_360_PAD_1_WIDTH       (4U)
#define VIRT_WRAP_REG_A363_360_PAD_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A363_360_PAD_1_SHIFT)) & VIRT_WRAP_REG_A363_360_PAD_1_MASK)

#define VIRT_WRAP_REG_A363_360_PAD_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_A363_360_PAD_2_SHIFT       (16U)
#define VIRT_WRAP_REG_A363_360_PAD_2_WIDTH       (4U)
#define VIRT_WRAP_REG_A363_360_PAD_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A363_360_PAD_2_SHIFT)) & VIRT_WRAP_REG_A363_360_PAD_2_MASK)

#define VIRT_WRAP_REG_A363_360_PAD_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_A363_360_PAD_3_SHIFT       (24U)
#define VIRT_WRAP_REG_A363_360_PAD_3_WIDTH       (4U)
#define VIRT_WRAP_REG_A363_360_PAD_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_A363_360_PAD_3_SHIFT)) & VIRT_WRAP_REG_A363_360_PAD_3_MASK)
/*! @} */

/*! @name REG_B3_0 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B3_0_INMUX_0_MASK          (0xFU)
#define VIRT_WRAP_REG_B3_0_INMUX_0_SHIFT         (0U)
#define VIRT_WRAP_REG_B3_0_INMUX_0_WIDTH         (4U)
#define VIRT_WRAP_REG_B3_0_INMUX_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B3_0_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B3_0_INMUX_0_MASK)

#define VIRT_WRAP_REG_B3_0_INMUX_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_B3_0_INMUX_1_SHIFT         (8U)
#define VIRT_WRAP_REG_B3_0_INMUX_1_WIDTH         (4U)
#define VIRT_WRAP_REG_B3_0_INMUX_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B3_0_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B3_0_INMUX_1_MASK)

#define VIRT_WRAP_REG_B3_0_INMUX_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_B3_0_INMUX_2_SHIFT         (16U)
#define VIRT_WRAP_REG_B3_0_INMUX_2_WIDTH         (4U)
#define VIRT_WRAP_REG_B3_0_INMUX_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B3_0_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B3_0_INMUX_2_MASK)

#define VIRT_WRAP_REG_B3_0_INMUX_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_B3_0_INMUX_3_SHIFT         (24U)
#define VIRT_WRAP_REG_B3_0_INMUX_3_WIDTH         (4U)
#define VIRT_WRAP_REG_B3_0_INMUX_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B3_0_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B3_0_INMUX_3_MASK)
/*! @} */

/*! @name REG_B7_4 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B7_4_INMUX_0_MASK          (0xFU)
#define VIRT_WRAP_REG_B7_4_INMUX_0_SHIFT         (0U)
#define VIRT_WRAP_REG_B7_4_INMUX_0_WIDTH         (4U)
#define VIRT_WRAP_REG_B7_4_INMUX_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B7_4_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B7_4_INMUX_0_MASK)

#define VIRT_WRAP_REG_B7_4_INMUX_1_MASK          (0xF00U)
#define VIRT_WRAP_REG_B7_4_INMUX_1_SHIFT         (8U)
#define VIRT_WRAP_REG_B7_4_INMUX_1_WIDTH         (4U)
#define VIRT_WRAP_REG_B7_4_INMUX_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B7_4_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B7_4_INMUX_1_MASK)

#define VIRT_WRAP_REG_B7_4_INMUX_2_MASK          (0xF0000U)
#define VIRT_WRAP_REG_B7_4_INMUX_2_SHIFT         (16U)
#define VIRT_WRAP_REG_B7_4_INMUX_2_WIDTH         (4U)
#define VIRT_WRAP_REG_B7_4_INMUX_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B7_4_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B7_4_INMUX_2_MASK)

#define VIRT_WRAP_REG_B7_4_INMUX_3_MASK          (0xF000000U)
#define VIRT_WRAP_REG_B7_4_INMUX_3_SHIFT         (24U)
#define VIRT_WRAP_REG_B7_4_INMUX_3_WIDTH         (4U)
#define VIRT_WRAP_REG_B7_4_INMUX_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B7_4_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B7_4_INMUX_3_MASK)
/*! @} */

/*! @name REG_B11_8 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B11_8_INMUX_0_MASK         (0xFU)
#define VIRT_WRAP_REG_B11_8_INMUX_0_SHIFT        (0U)
#define VIRT_WRAP_REG_B11_8_INMUX_0_WIDTH        (4U)
#define VIRT_WRAP_REG_B11_8_INMUX_0(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B11_8_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B11_8_INMUX_0_MASK)

#define VIRT_WRAP_REG_B11_8_INMUX_1_MASK         (0xF00U)
#define VIRT_WRAP_REG_B11_8_INMUX_1_SHIFT        (8U)
#define VIRT_WRAP_REG_B11_8_INMUX_1_WIDTH        (4U)
#define VIRT_WRAP_REG_B11_8_INMUX_1(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B11_8_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B11_8_INMUX_1_MASK)

#define VIRT_WRAP_REG_B11_8_INMUX_2_MASK         (0xF0000U)
#define VIRT_WRAP_REG_B11_8_INMUX_2_SHIFT        (16U)
#define VIRT_WRAP_REG_B11_8_INMUX_2_WIDTH        (4U)
#define VIRT_WRAP_REG_B11_8_INMUX_2(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B11_8_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B11_8_INMUX_2_MASK)

#define VIRT_WRAP_REG_B11_8_INMUX_3_MASK         (0xF000000U)
#define VIRT_WRAP_REG_B11_8_INMUX_3_SHIFT        (24U)
#define VIRT_WRAP_REG_B11_8_INMUX_3_WIDTH        (4U)
#define VIRT_WRAP_REG_B11_8_INMUX_3(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B11_8_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B11_8_INMUX_3_MASK)
/*! @} */

/*! @name REG_B15_12 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B15_12_INMUX_0_MASK        (0xFU)
#define VIRT_WRAP_REG_B15_12_INMUX_0_SHIFT       (0U)
#define VIRT_WRAP_REG_B15_12_INMUX_0_WIDTH       (4U)
#define VIRT_WRAP_REG_B15_12_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B15_12_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B15_12_INMUX_0_MASK)

#define VIRT_WRAP_REG_B15_12_INMUX_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_B15_12_INMUX_1_SHIFT       (8U)
#define VIRT_WRAP_REG_B15_12_INMUX_1_WIDTH       (4U)
#define VIRT_WRAP_REG_B15_12_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B15_12_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B15_12_INMUX_1_MASK)

#define VIRT_WRAP_REG_B15_12_INMUX_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_B15_12_INMUX_2_SHIFT       (16U)
#define VIRT_WRAP_REG_B15_12_INMUX_2_WIDTH       (4U)
#define VIRT_WRAP_REG_B15_12_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B15_12_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B15_12_INMUX_2_MASK)

#define VIRT_WRAP_REG_B15_12_INMUX_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_B15_12_INMUX_3_SHIFT       (24U)
#define VIRT_WRAP_REG_B15_12_INMUX_3_WIDTH       (4U)
#define VIRT_WRAP_REG_B15_12_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B15_12_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B15_12_INMUX_3_MASK)
/*! @} */

/*! @name REG_B19_16 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B19_16_INMUX_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_B19_16_INMUX_3_SHIFT       (24U)
#define VIRT_WRAP_REG_B19_16_INMUX_3_WIDTH       (4U)
#define VIRT_WRAP_REG_B19_16_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B19_16_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B19_16_INMUX_3_MASK)
/*! @} */

/*! @name REG_B23_20 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B23_20_INMUX_0_MASK        (0xFU)
#define VIRT_WRAP_REG_B23_20_INMUX_0_SHIFT       (0U)
#define VIRT_WRAP_REG_B23_20_INMUX_0_WIDTH       (4U)
#define VIRT_WRAP_REG_B23_20_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B23_20_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B23_20_INMUX_0_MASK)

#define VIRT_WRAP_REG_B23_20_INMUX_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_B23_20_INMUX_1_SHIFT       (8U)
#define VIRT_WRAP_REG_B23_20_INMUX_1_WIDTH       (4U)
#define VIRT_WRAP_REG_B23_20_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B23_20_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B23_20_INMUX_1_MASK)

#define VIRT_WRAP_REG_B23_20_INMUX_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_B23_20_INMUX_2_SHIFT       (16U)
#define VIRT_WRAP_REG_B23_20_INMUX_2_WIDTH       (4U)
#define VIRT_WRAP_REG_B23_20_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B23_20_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B23_20_INMUX_2_MASK)

#define VIRT_WRAP_REG_B23_20_INMUX_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_B23_20_INMUX_3_SHIFT       (24U)
#define VIRT_WRAP_REG_B23_20_INMUX_3_WIDTH       (4U)
#define VIRT_WRAP_REG_B23_20_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B23_20_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B23_20_INMUX_3_MASK)
/*! @} */

/*! @name REG_B27_24 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B27_24_INMUX_0_MASK        (0xFU)
#define VIRT_WRAP_REG_B27_24_INMUX_0_SHIFT       (0U)
#define VIRT_WRAP_REG_B27_24_INMUX_0_WIDTH       (4U)
#define VIRT_WRAP_REG_B27_24_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B27_24_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B27_24_INMUX_0_MASK)

#define VIRT_WRAP_REG_B27_24_INMUX_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_B27_24_INMUX_1_SHIFT       (8U)
#define VIRT_WRAP_REG_B27_24_INMUX_1_WIDTH       (4U)
#define VIRT_WRAP_REG_B27_24_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B27_24_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B27_24_INMUX_1_MASK)
/*! @} */

/*! @name REG_B31_28 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B31_28_INMUX_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_B31_28_INMUX_1_SHIFT       (8U)
#define VIRT_WRAP_REG_B31_28_INMUX_1_WIDTH       (4U)
#define VIRT_WRAP_REG_B31_28_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B31_28_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B31_28_INMUX_1_MASK)

#define VIRT_WRAP_REG_B31_28_INMUX_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_B31_28_INMUX_2_SHIFT       (16U)
#define VIRT_WRAP_REG_B31_28_INMUX_2_WIDTH       (4U)
#define VIRT_WRAP_REG_B31_28_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B31_28_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B31_28_INMUX_2_MASK)

#define VIRT_WRAP_REG_B31_28_INMUX_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_B31_28_INMUX_3_SHIFT       (24U)
#define VIRT_WRAP_REG_B31_28_INMUX_3_WIDTH       (4U)
#define VIRT_WRAP_REG_B31_28_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B31_28_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B31_28_INMUX_3_MASK)
/*! @} */

/*! @name REG_B35_32 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B35_32_INMUX_0_MASK        (0xFU)
#define VIRT_WRAP_REG_B35_32_INMUX_0_SHIFT       (0U)
#define VIRT_WRAP_REG_B35_32_INMUX_0_WIDTH       (4U)
#define VIRT_WRAP_REG_B35_32_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B35_32_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B35_32_INMUX_0_MASK)

#define VIRT_WRAP_REG_B35_32_INMUX_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_B35_32_INMUX_1_SHIFT       (8U)
#define VIRT_WRAP_REG_B35_32_INMUX_1_WIDTH       (4U)
#define VIRT_WRAP_REG_B35_32_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B35_32_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B35_32_INMUX_1_MASK)

#define VIRT_WRAP_REG_B35_32_INMUX_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_B35_32_INMUX_3_SHIFT       (24U)
#define VIRT_WRAP_REG_B35_32_INMUX_3_WIDTH       (4U)
#define VIRT_WRAP_REG_B35_32_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B35_32_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B35_32_INMUX_3_MASK)
/*! @} */

/*! @name REG_B39_36 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B39_36_INMUX_0_MASK        (0xFU)
#define VIRT_WRAP_REG_B39_36_INMUX_0_SHIFT       (0U)
#define VIRT_WRAP_REG_B39_36_INMUX_0_WIDTH       (4U)
#define VIRT_WRAP_REG_B39_36_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B39_36_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B39_36_INMUX_0_MASK)

#define VIRT_WRAP_REG_B39_36_INMUX_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_B39_36_INMUX_1_SHIFT       (8U)
#define VIRT_WRAP_REG_B39_36_INMUX_1_WIDTH       (4U)
#define VIRT_WRAP_REG_B39_36_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B39_36_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B39_36_INMUX_1_MASK)

#define VIRT_WRAP_REG_B39_36_INMUX_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_B39_36_INMUX_2_SHIFT       (16U)
#define VIRT_WRAP_REG_B39_36_INMUX_2_WIDTH       (4U)
#define VIRT_WRAP_REG_B39_36_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B39_36_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B39_36_INMUX_2_MASK)

#define VIRT_WRAP_REG_B39_36_INMUX_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_B39_36_INMUX_3_SHIFT       (24U)
#define VIRT_WRAP_REG_B39_36_INMUX_3_WIDTH       (4U)
#define VIRT_WRAP_REG_B39_36_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B39_36_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B39_36_INMUX_3_MASK)
/*! @} */

/*! @name REG_B43_40 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B43_40_INMUX_0_MASK        (0xFU)
#define VIRT_WRAP_REG_B43_40_INMUX_0_SHIFT       (0U)
#define VIRT_WRAP_REG_B43_40_INMUX_0_WIDTH       (4U)
#define VIRT_WRAP_REG_B43_40_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B43_40_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B43_40_INMUX_0_MASK)

#define VIRT_WRAP_REG_B43_40_INMUX_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_B43_40_INMUX_1_SHIFT       (8U)
#define VIRT_WRAP_REG_B43_40_INMUX_1_WIDTH       (4U)
#define VIRT_WRAP_REG_B43_40_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B43_40_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B43_40_INMUX_1_MASK)

#define VIRT_WRAP_REG_B43_40_INMUX_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_B43_40_INMUX_2_SHIFT       (16U)
#define VIRT_WRAP_REG_B43_40_INMUX_2_WIDTH       (4U)
#define VIRT_WRAP_REG_B43_40_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B43_40_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B43_40_INMUX_2_MASK)

#define VIRT_WRAP_REG_B43_40_INMUX_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_B43_40_INMUX_3_SHIFT       (24U)
#define VIRT_WRAP_REG_B43_40_INMUX_3_WIDTH       (4U)
#define VIRT_WRAP_REG_B43_40_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B43_40_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B43_40_INMUX_3_MASK)
/*! @} */

/*! @name REG_B47_44 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B47_44_INMUX_0_MASK        (0xFU)
#define VIRT_WRAP_REG_B47_44_INMUX_0_SHIFT       (0U)
#define VIRT_WRAP_REG_B47_44_INMUX_0_WIDTH       (4U)
#define VIRT_WRAP_REG_B47_44_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B47_44_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B47_44_INMUX_0_MASK)

#define VIRT_WRAP_REG_B47_44_INMUX_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_B47_44_INMUX_1_SHIFT       (8U)
#define VIRT_WRAP_REG_B47_44_INMUX_1_WIDTH       (4U)
#define VIRT_WRAP_REG_B47_44_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B47_44_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B47_44_INMUX_1_MASK)

#define VIRT_WRAP_REG_B47_44_INMUX_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_B47_44_INMUX_2_SHIFT       (16U)
#define VIRT_WRAP_REG_B47_44_INMUX_2_WIDTH       (4U)
#define VIRT_WRAP_REG_B47_44_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B47_44_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B47_44_INMUX_2_MASK)

#define VIRT_WRAP_REG_B47_44_INMUX_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_B47_44_INMUX_3_SHIFT       (24U)
#define VIRT_WRAP_REG_B47_44_INMUX_3_WIDTH       (4U)
#define VIRT_WRAP_REG_B47_44_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B47_44_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B47_44_INMUX_3_MASK)
/*! @} */

/*! @name REG_B51_48 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B51_48_INMUX_0_MASK        (0xFU)
#define VIRT_WRAP_REG_B51_48_INMUX_0_SHIFT       (0U)
#define VIRT_WRAP_REG_B51_48_INMUX_0_WIDTH       (4U)
#define VIRT_WRAP_REG_B51_48_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B51_48_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B51_48_INMUX_0_MASK)

#define VIRT_WRAP_REG_B51_48_INMUX_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_B51_48_INMUX_1_SHIFT       (8U)
#define VIRT_WRAP_REG_B51_48_INMUX_1_WIDTH       (4U)
#define VIRT_WRAP_REG_B51_48_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B51_48_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B51_48_INMUX_1_MASK)

#define VIRT_WRAP_REG_B51_48_INMUX_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_B51_48_INMUX_2_SHIFT       (16U)
#define VIRT_WRAP_REG_B51_48_INMUX_2_WIDTH       (4U)
#define VIRT_WRAP_REG_B51_48_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B51_48_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B51_48_INMUX_2_MASK)

#define VIRT_WRAP_REG_B51_48_INMUX_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_B51_48_INMUX_3_SHIFT       (24U)
#define VIRT_WRAP_REG_B51_48_INMUX_3_WIDTH       (4U)
#define VIRT_WRAP_REG_B51_48_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B51_48_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B51_48_INMUX_3_MASK)
/*! @} */

/*! @name REG_B55_52 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B55_52_INMUX_0_MASK        (0xFU)
#define VIRT_WRAP_REG_B55_52_INMUX_0_SHIFT       (0U)
#define VIRT_WRAP_REG_B55_52_INMUX_0_WIDTH       (4U)
#define VIRT_WRAP_REG_B55_52_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B55_52_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B55_52_INMUX_0_MASK)

#define VIRT_WRAP_REG_B55_52_INMUX_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_B55_52_INMUX_1_SHIFT       (8U)
#define VIRT_WRAP_REG_B55_52_INMUX_1_WIDTH       (4U)
#define VIRT_WRAP_REG_B55_52_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B55_52_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B55_52_INMUX_1_MASK)

#define VIRT_WRAP_REG_B55_52_INMUX_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_B55_52_INMUX_2_SHIFT       (16U)
#define VIRT_WRAP_REG_B55_52_INMUX_2_WIDTH       (4U)
#define VIRT_WRAP_REG_B55_52_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B55_52_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B55_52_INMUX_2_MASK)

#define VIRT_WRAP_REG_B55_52_INMUX_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_B55_52_INMUX_3_SHIFT       (24U)
#define VIRT_WRAP_REG_B55_52_INMUX_3_WIDTH       (4U)
#define VIRT_WRAP_REG_B55_52_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B55_52_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B55_52_INMUX_3_MASK)
/*! @} */

/*! @name REG_B59_56 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B59_56_INMUX_0_MASK        (0xFU)
#define VIRT_WRAP_REG_B59_56_INMUX_0_SHIFT       (0U)
#define VIRT_WRAP_REG_B59_56_INMUX_0_WIDTH       (4U)
#define VIRT_WRAP_REG_B59_56_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B59_56_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B59_56_INMUX_0_MASK)

#define VIRT_WRAP_REG_B59_56_INMUX_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_B59_56_INMUX_1_SHIFT       (8U)
#define VIRT_WRAP_REG_B59_56_INMUX_1_WIDTH       (4U)
#define VIRT_WRAP_REG_B59_56_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B59_56_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B59_56_INMUX_1_MASK)

#define VIRT_WRAP_REG_B59_56_INMUX_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_B59_56_INMUX_2_SHIFT       (16U)
#define VIRT_WRAP_REG_B59_56_INMUX_2_WIDTH       (4U)
#define VIRT_WRAP_REG_B59_56_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B59_56_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B59_56_INMUX_2_MASK)

#define VIRT_WRAP_REG_B59_56_INMUX_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_B59_56_INMUX_3_SHIFT       (24U)
#define VIRT_WRAP_REG_B59_56_INMUX_3_WIDTH       (4U)
#define VIRT_WRAP_REG_B59_56_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B59_56_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B59_56_INMUX_3_MASK)
/*! @} */

/*! @name REG_B63_60 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B63_60_INMUX_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_B63_60_INMUX_1_SHIFT       (8U)
#define VIRT_WRAP_REG_B63_60_INMUX_1_WIDTH       (4U)
#define VIRT_WRAP_REG_B63_60_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B63_60_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B63_60_INMUX_1_MASK)

#define VIRT_WRAP_REG_B63_60_INMUX_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_B63_60_INMUX_2_SHIFT       (16U)
#define VIRT_WRAP_REG_B63_60_INMUX_2_WIDTH       (4U)
#define VIRT_WRAP_REG_B63_60_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B63_60_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B63_60_INMUX_2_MASK)

#define VIRT_WRAP_REG_B63_60_INMUX_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_B63_60_INMUX_3_SHIFT       (24U)
#define VIRT_WRAP_REG_B63_60_INMUX_3_WIDTH       (4U)
#define VIRT_WRAP_REG_B63_60_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B63_60_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B63_60_INMUX_3_MASK)
/*! @} */

/*! @name REG_B67_64 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B67_64_INMUX_0_MASK        (0xFU)
#define VIRT_WRAP_REG_B67_64_INMUX_0_SHIFT       (0U)
#define VIRT_WRAP_REG_B67_64_INMUX_0_WIDTH       (4U)
#define VIRT_WRAP_REG_B67_64_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B67_64_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B67_64_INMUX_0_MASK)

#define VIRT_WRAP_REG_B67_64_INMUX_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_B67_64_INMUX_1_SHIFT       (8U)
#define VIRT_WRAP_REG_B67_64_INMUX_1_WIDTH       (4U)
#define VIRT_WRAP_REG_B67_64_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B67_64_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B67_64_INMUX_1_MASK)

#define VIRT_WRAP_REG_B67_64_INMUX_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_B67_64_INMUX_2_SHIFT       (16U)
#define VIRT_WRAP_REG_B67_64_INMUX_2_WIDTH       (4U)
#define VIRT_WRAP_REG_B67_64_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B67_64_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B67_64_INMUX_2_MASK)

#define VIRT_WRAP_REG_B67_64_INMUX_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_B67_64_INMUX_3_SHIFT       (24U)
#define VIRT_WRAP_REG_B67_64_INMUX_3_WIDTH       (4U)
#define VIRT_WRAP_REG_B67_64_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B67_64_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B67_64_INMUX_3_MASK)
/*! @} */

/*! @name REG_B71_68 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B71_68_INMUX_0_MASK        (0xFU)
#define VIRT_WRAP_REG_B71_68_INMUX_0_SHIFT       (0U)
#define VIRT_WRAP_REG_B71_68_INMUX_0_WIDTH       (4U)
#define VIRT_WRAP_REG_B71_68_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B71_68_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B71_68_INMUX_0_MASK)

#define VIRT_WRAP_REG_B71_68_INMUX_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_B71_68_INMUX_1_SHIFT       (8U)
#define VIRT_WRAP_REG_B71_68_INMUX_1_WIDTH       (4U)
#define VIRT_WRAP_REG_B71_68_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B71_68_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B71_68_INMUX_1_MASK)

#define VIRT_WRAP_REG_B71_68_INMUX_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_B71_68_INMUX_2_SHIFT       (16U)
#define VIRT_WRAP_REG_B71_68_INMUX_2_WIDTH       (4U)
#define VIRT_WRAP_REG_B71_68_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B71_68_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B71_68_INMUX_2_MASK)

#define VIRT_WRAP_REG_B71_68_INMUX_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_B71_68_INMUX_3_SHIFT       (24U)
#define VIRT_WRAP_REG_B71_68_INMUX_3_WIDTH       (4U)
#define VIRT_WRAP_REG_B71_68_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B71_68_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B71_68_INMUX_3_MASK)
/*! @} */

/*! @name REG_B75_72 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B75_72_INMUX_0_MASK        (0xFU)
#define VIRT_WRAP_REG_B75_72_INMUX_0_SHIFT       (0U)
#define VIRT_WRAP_REG_B75_72_INMUX_0_WIDTH       (4U)
#define VIRT_WRAP_REG_B75_72_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B75_72_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B75_72_INMUX_0_MASK)

#define VIRT_WRAP_REG_B75_72_INMUX_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_B75_72_INMUX_1_SHIFT       (8U)
#define VIRT_WRAP_REG_B75_72_INMUX_1_WIDTH       (4U)
#define VIRT_WRAP_REG_B75_72_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B75_72_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B75_72_INMUX_1_MASK)

#define VIRT_WRAP_REG_B75_72_INMUX_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_B75_72_INMUX_2_SHIFT       (16U)
#define VIRT_WRAP_REG_B75_72_INMUX_2_WIDTH       (4U)
#define VIRT_WRAP_REG_B75_72_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B75_72_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B75_72_INMUX_2_MASK)

#define VIRT_WRAP_REG_B75_72_INMUX_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_B75_72_INMUX_3_SHIFT       (24U)
#define VIRT_WRAP_REG_B75_72_INMUX_3_WIDTH       (4U)
#define VIRT_WRAP_REG_B75_72_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B75_72_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B75_72_INMUX_3_MASK)
/*! @} */

/*! @name REG_B79_76 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B79_76_INMUX_0_MASK        (0xFU)
#define VIRT_WRAP_REG_B79_76_INMUX_0_SHIFT       (0U)
#define VIRT_WRAP_REG_B79_76_INMUX_0_WIDTH       (4U)
#define VIRT_WRAP_REG_B79_76_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B79_76_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B79_76_INMUX_0_MASK)

#define VIRT_WRAP_REG_B79_76_INMUX_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_B79_76_INMUX_1_SHIFT       (8U)
#define VIRT_WRAP_REG_B79_76_INMUX_1_WIDTH       (4U)
#define VIRT_WRAP_REG_B79_76_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B79_76_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B79_76_INMUX_1_MASK)

#define VIRT_WRAP_REG_B79_76_INMUX_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_B79_76_INMUX_2_SHIFT       (16U)
#define VIRT_WRAP_REG_B79_76_INMUX_2_WIDTH       (4U)
#define VIRT_WRAP_REG_B79_76_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B79_76_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B79_76_INMUX_2_MASK)

#define VIRT_WRAP_REG_B79_76_INMUX_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_B79_76_INMUX_3_SHIFT       (24U)
#define VIRT_WRAP_REG_B79_76_INMUX_3_WIDTH       (4U)
#define VIRT_WRAP_REG_B79_76_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B79_76_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B79_76_INMUX_3_MASK)
/*! @} */

/*! @name REG_B83_80 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B83_80_INMUX_0_MASK        (0xFU)
#define VIRT_WRAP_REG_B83_80_INMUX_0_SHIFT       (0U)
#define VIRT_WRAP_REG_B83_80_INMUX_0_WIDTH       (4U)
#define VIRT_WRAP_REG_B83_80_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B83_80_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B83_80_INMUX_0_MASK)

#define VIRT_WRAP_REG_B83_80_INMUX_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_B83_80_INMUX_1_SHIFT       (8U)
#define VIRT_WRAP_REG_B83_80_INMUX_1_WIDTH       (4U)
#define VIRT_WRAP_REG_B83_80_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B83_80_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B83_80_INMUX_1_MASK)

#define VIRT_WRAP_REG_B83_80_INMUX_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_B83_80_INMUX_2_SHIFT       (16U)
#define VIRT_WRAP_REG_B83_80_INMUX_2_WIDTH       (4U)
#define VIRT_WRAP_REG_B83_80_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B83_80_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B83_80_INMUX_2_MASK)

#define VIRT_WRAP_REG_B83_80_INMUX_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_B83_80_INMUX_3_SHIFT       (24U)
#define VIRT_WRAP_REG_B83_80_INMUX_3_WIDTH       (4U)
#define VIRT_WRAP_REG_B83_80_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B83_80_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B83_80_INMUX_3_MASK)
/*! @} */

/*! @name REG_B87_84 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B87_84_INMUX_0_MASK        (0xFU)
#define VIRT_WRAP_REG_B87_84_INMUX_0_SHIFT       (0U)
#define VIRT_WRAP_REG_B87_84_INMUX_0_WIDTH       (4U)
#define VIRT_WRAP_REG_B87_84_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B87_84_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B87_84_INMUX_0_MASK)

#define VIRT_WRAP_REG_B87_84_INMUX_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_B87_84_INMUX_1_SHIFT       (8U)
#define VIRT_WRAP_REG_B87_84_INMUX_1_WIDTH       (4U)
#define VIRT_WRAP_REG_B87_84_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B87_84_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B87_84_INMUX_1_MASK)

#define VIRT_WRAP_REG_B87_84_INMUX_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_B87_84_INMUX_2_SHIFT       (16U)
#define VIRT_WRAP_REG_B87_84_INMUX_2_WIDTH       (4U)
#define VIRT_WRAP_REG_B87_84_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B87_84_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B87_84_INMUX_2_MASK)

#define VIRT_WRAP_REG_B87_84_INMUX_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_B87_84_INMUX_3_SHIFT       (24U)
#define VIRT_WRAP_REG_B87_84_INMUX_3_WIDTH       (4U)
#define VIRT_WRAP_REG_B87_84_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B87_84_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B87_84_INMUX_3_MASK)
/*! @} */

/*! @name REG_B91_88 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B91_88_INMUX_0_MASK        (0xFU)
#define VIRT_WRAP_REG_B91_88_INMUX_0_SHIFT       (0U)
#define VIRT_WRAP_REG_B91_88_INMUX_0_WIDTH       (4U)
#define VIRT_WRAP_REG_B91_88_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B91_88_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B91_88_INMUX_0_MASK)

#define VIRT_WRAP_REG_B91_88_INMUX_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_B91_88_INMUX_1_SHIFT       (8U)
#define VIRT_WRAP_REG_B91_88_INMUX_1_WIDTH       (4U)
#define VIRT_WRAP_REG_B91_88_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B91_88_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B91_88_INMUX_1_MASK)

#define VIRT_WRAP_REG_B91_88_INMUX_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_B91_88_INMUX_2_SHIFT       (16U)
#define VIRT_WRAP_REG_B91_88_INMUX_2_WIDTH       (4U)
#define VIRT_WRAP_REG_B91_88_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B91_88_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B91_88_INMUX_2_MASK)

#define VIRT_WRAP_REG_B91_88_INMUX_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_B91_88_INMUX_3_SHIFT       (24U)
#define VIRT_WRAP_REG_B91_88_INMUX_3_WIDTH       (4U)
#define VIRT_WRAP_REG_B91_88_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B91_88_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B91_88_INMUX_3_MASK)
/*! @} */

/*! @name REG_B95_92 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B95_92_INMUX_0_MASK        (0xFU)
#define VIRT_WRAP_REG_B95_92_INMUX_0_SHIFT       (0U)
#define VIRT_WRAP_REG_B95_92_INMUX_0_WIDTH       (4U)
#define VIRT_WRAP_REG_B95_92_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B95_92_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B95_92_INMUX_0_MASK)

#define VIRT_WRAP_REG_B95_92_INMUX_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_B95_92_INMUX_1_SHIFT       (8U)
#define VIRT_WRAP_REG_B95_92_INMUX_1_WIDTH       (4U)
#define VIRT_WRAP_REG_B95_92_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B95_92_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B95_92_INMUX_1_MASK)

#define VIRT_WRAP_REG_B95_92_INMUX_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_B95_92_INMUX_2_SHIFT       (16U)
#define VIRT_WRAP_REG_B95_92_INMUX_2_WIDTH       (4U)
#define VIRT_WRAP_REG_B95_92_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B95_92_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B95_92_INMUX_2_MASK)

#define VIRT_WRAP_REG_B95_92_INMUX_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_B95_92_INMUX_3_SHIFT       (24U)
#define VIRT_WRAP_REG_B95_92_INMUX_3_WIDTH       (4U)
#define VIRT_WRAP_REG_B95_92_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B95_92_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B95_92_INMUX_3_MASK)
/*! @} */

/*! @name REG_B99_96 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B99_96_INMUX_0_MASK        (0xFU)
#define VIRT_WRAP_REG_B99_96_INMUX_0_SHIFT       (0U)
#define VIRT_WRAP_REG_B99_96_INMUX_0_WIDTH       (4U)
#define VIRT_WRAP_REG_B99_96_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B99_96_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B99_96_INMUX_0_MASK)

#define VIRT_WRAP_REG_B99_96_INMUX_1_MASK        (0xF00U)
#define VIRT_WRAP_REG_B99_96_INMUX_1_SHIFT       (8U)
#define VIRT_WRAP_REG_B99_96_INMUX_1_WIDTH       (4U)
#define VIRT_WRAP_REG_B99_96_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B99_96_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B99_96_INMUX_1_MASK)

#define VIRT_WRAP_REG_B99_96_INMUX_2_MASK        (0xF0000U)
#define VIRT_WRAP_REG_B99_96_INMUX_2_SHIFT       (16U)
#define VIRT_WRAP_REG_B99_96_INMUX_2_WIDTH       (4U)
#define VIRT_WRAP_REG_B99_96_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B99_96_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B99_96_INMUX_2_MASK)

#define VIRT_WRAP_REG_B99_96_INMUX_3_MASK        (0xF000000U)
#define VIRT_WRAP_REG_B99_96_INMUX_3_SHIFT       (24U)
#define VIRT_WRAP_REG_B99_96_INMUX_3_WIDTH       (4U)
#define VIRT_WRAP_REG_B99_96_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B99_96_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B99_96_INMUX_3_MASK)
/*! @} */

/*! @name REG_B103_100 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B103_100_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B103_100_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B103_100_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B103_100_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B103_100_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B103_100_INMUX_0_MASK)

#define VIRT_WRAP_REG_B103_100_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B103_100_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B103_100_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B103_100_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B103_100_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B103_100_INMUX_1_MASK)

#define VIRT_WRAP_REG_B103_100_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B103_100_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B103_100_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B103_100_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B103_100_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B103_100_INMUX_2_MASK)

#define VIRT_WRAP_REG_B103_100_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B103_100_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B103_100_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B103_100_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B103_100_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B103_100_INMUX_3_MASK)
/*! @} */

/*! @name REG_B107_104 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B107_104_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B107_104_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B107_104_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B107_104_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B107_104_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B107_104_INMUX_0_MASK)

#define VIRT_WRAP_REG_B107_104_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B107_104_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B107_104_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B107_104_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B107_104_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B107_104_INMUX_1_MASK)

#define VIRT_WRAP_REG_B107_104_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B107_104_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B107_104_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B107_104_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B107_104_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B107_104_INMUX_2_MASK)

#define VIRT_WRAP_REG_B107_104_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B107_104_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B107_104_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B107_104_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B107_104_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B107_104_INMUX_3_MASK)
/*! @} */

/*! @name REG_B111_108 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B111_108_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B111_108_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B111_108_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B111_108_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B111_108_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B111_108_INMUX_0_MASK)

#define VIRT_WRAP_REG_B111_108_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B111_108_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B111_108_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B111_108_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B111_108_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B111_108_INMUX_1_MASK)

#define VIRT_WRAP_REG_B111_108_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B111_108_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B111_108_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B111_108_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B111_108_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B111_108_INMUX_2_MASK)

#define VIRT_WRAP_REG_B111_108_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B111_108_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B111_108_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B111_108_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B111_108_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B111_108_INMUX_3_MASK)
/*! @} */

/*! @name REG_B115_112 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B115_112_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B115_112_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B115_112_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B115_112_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B115_112_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B115_112_INMUX_0_MASK)

#define VIRT_WRAP_REG_B115_112_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B115_112_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B115_112_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B115_112_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B115_112_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B115_112_INMUX_1_MASK)

#define VIRT_WRAP_REG_B115_112_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B115_112_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B115_112_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B115_112_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B115_112_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B115_112_INMUX_2_MASK)

#define VIRT_WRAP_REG_B115_112_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B115_112_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B115_112_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B115_112_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B115_112_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B115_112_INMUX_3_MASK)
/*! @} */

/*! @name REG_B119_116 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B119_116_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B119_116_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B119_116_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B119_116_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B119_116_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B119_116_INMUX_0_MASK)

#define VIRT_WRAP_REG_B119_116_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B119_116_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B119_116_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B119_116_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B119_116_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B119_116_INMUX_1_MASK)

#define VIRT_WRAP_REG_B119_116_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B119_116_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B119_116_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B119_116_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B119_116_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B119_116_INMUX_2_MASK)

#define VIRT_WRAP_REG_B119_116_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B119_116_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B119_116_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B119_116_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B119_116_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B119_116_INMUX_3_MASK)
/*! @} */

/*! @name REG_B123_120 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B123_120_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B123_120_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B123_120_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B123_120_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B123_120_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B123_120_INMUX_0_MASK)

#define VIRT_WRAP_REG_B123_120_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B123_120_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B123_120_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B123_120_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B123_120_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B123_120_INMUX_1_MASK)

#define VIRT_WRAP_REG_B123_120_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B123_120_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B123_120_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B123_120_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B123_120_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B123_120_INMUX_2_MASK)

#define VIRT_WRAP_REG_B123_120_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B123_120_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B123_120_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B123_120_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B123_120_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B123_120_INMUX_3_MASK)
/*! @} */

/*! @name REG_B127_124 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B127_124_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B127_124_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B127_124_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B127_124_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B127_124_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B127_124_INMUX_0_MASK)

#define VIRT_WRAP_REG_B127_124_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B127_124_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B127_124_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B127_124_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B127_124_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B127_124_INMUX_1_MASK)

#define VIRT_WRAP_REG_B127_124_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B127_124_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B127_124_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B127_124_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B127_124_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B127_124_INMUX_2_MASK)

#define VIRT_WRAP_REG_B127_124_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B127_124_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B127_124_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B127_124_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B127_124_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B127_124_INMUX_3_MASK)
/*! @} */

/*! @name REG_B131_128 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B131_128_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B131_128_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B131_128_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B131_128_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B131_128_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B131_128_INMUX_0_MASK)

#define VIRT_WRAP_REG_B131_128_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B131_128_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B131_128_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B131_128_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B131_128_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B131_128_INMUX_1_MASK)

#define VIRT_WRAP_REG_B131_128_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B131_128_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B131_128_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B131_128_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B131_128_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B131_128_INMUX_2_MASK)

#define VIRT_WRAP_REG_B131_128_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B131_128_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B131_128_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B131_128_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B131_128_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B131_128_INMUX_3_MASK)
/*! @} */

/*! @name REG_B135_132 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B135_132_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B135_132_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B135_132_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B135_132_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B135_132_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B135_132_INMUX_0_MASK)

#define VIRT_WRAP_REG_B135_132_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B135_132_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B135_132_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B135_132_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B135_132_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B135_132_INMUX_1_MASK)

#define VIRT_WRAP_REG_B135_132_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B135_132_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B135_132_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B135_132_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B135_132_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B135_132_INMUX_2_MASK)

#define VIRT_WRAP_REG_B135_132_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B135_132_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B135_132_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B135_132_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B135_132_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B135_132_INMUX_3_MASK)
/*! @} */

/*! @name REG_B139_136 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B139_136_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B139_136_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B139_136_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B139_136_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B139_136_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B139_136_INMUX_0_MASK)

#define VIRT_WRAP_REG_B139_136_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B139_136_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B139_136_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B139_136_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B139_136_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B139_136_INMUX_1_MASK)

#define VIRT_WRAP_REG_B139_136_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B139_136_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B139_136_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B139_136_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B139_136_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B139_136_INMUX_2_MASK)

#define VIRT_WRAP_REG_B139_136_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B139_136_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B139_136_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B139_136_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B139_136_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B139_136_INMUX_3_MASK)
/*! @} */

/*! @name REG_B143_140 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B143_140_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B143_140_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B143_140_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B143_140_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B143_140_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B143_140_INMUX_0_MASK)

#define VIRT_WRAP_REG_B143_140_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B143_140_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B143_140_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B143_140_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B143_140_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B143_140_INMUX_1_MASK)

#define VIRT_WRAP_REG_B143_140_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B143_140_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B143_140_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B143_140_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B143_140_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B143_140_INMUX_2_MASK)

#define VIRT_WRAP_REG_B143_140_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B143_140_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B143_140_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B143_140_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B143_140_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B143_140_INMUX_3_MASK)
/*! @} */

/*! @name REG_B147_144 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B147_144_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B147_144_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B147_144_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B147_144_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B147_144_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B147_144_INMUX_0_MASK)

#define VIRT_WRAP_REG_B147_144_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B147_144_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B147_144_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B147_144_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B147_144_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B147_144_INMUX_1_MASK)

#define VIRT_WRAP_REG_B147_144_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B147_144_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B147_144_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B147_144_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B147_144_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B147_144_INMUX_2_MASK)

#define VIRT_WRAP_REG_B147_144_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B147_144_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B147_144_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B147_144_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B147_144_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B147_144_INMUX_3_MASK)
/*! @} */

/*! @name REG_B151_148 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B151_148_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B151_148_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B151_148_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B151_148_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B151_148_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B151_148_INMUX_0_MASK)

#define VIRT_WRAP_REG_B151_148_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B151_148_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B151_148_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B151_148_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B151_148_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B151_148_INMUX_1_MASK)

#define VIRT_WRAP_REG_B151_148_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B151_148_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B151_148_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B151_148_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B151_148_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B151_148_INMUX_2_MASK)

#define VIRT_WRAP_REG_B151_148_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B151_148_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B151_148_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B151_148_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B151_148_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B151_148_INMUX_3_MASK)
/*! @} */

/*! @name REG_B155_152 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B155_152_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B155_152_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B155_152_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B155_152_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B155_152_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B155_152_INMUX_0_MASK)

#define VIRT_WRAP_REG_B155_152_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B155_152_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B155_152_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B155_152_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B155_152_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B155_152_INMUX_1_MASK)

#define VIRT_WRAP_REG_B155_152_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B155_152_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B155_152_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B155_152_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B155_152_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B155_152_INMUX_2_MASK)

#define VIRT_WRAP_REG_B155_152_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B155_152_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B155_152_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B155_152_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B155_152_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B155_152_INMUX_3_MASK)
/*! @} */

/*! @name REG_B159_156 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B159_156_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B159_156_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B159_156_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B159_156_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B159_156_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B159_156_INMUX_0_MASK)

#define VIRT_WRAP_REG_B159_156_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B159_156_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B159_156_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B159_156_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B159_156_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B159_156_INMUX_1_MASK)

#define VIRT_WRAP_REG_B159_156_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B159_156_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B159_156_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B159_156_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B159_156_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B159_156_INMUX_2_MASK)

#define VIRT_WRAP_REG_B159_156_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B159_156_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B159_156_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B159_156_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B159_156_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B159_156_INMUX_3_MASK)
/*! @} */

/*! @name REG_B163_160 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B163_160_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B163_160_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B163_160_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B163_160_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B163_160_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B163_160_INMUX_0_MASK)

#define VIRT_WRAP_REG_B163_160_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B163_160_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B163_160_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B163_160_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B163_160_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B163_160_INMUX_1_MASK)

#define VIRT_WRAP_REG_B163_160_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B163_160_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B163_160_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B163_160_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B163_160_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B163_160_INMUX_2_MASK)

#define VIRT_WRAP_REG_B163_160_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B163_160_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B163_160_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B163_160_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B163_160_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B163_160_INMUX_3_MASK)
/*! @} */

/*! @name REG_B167_164 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B167_164_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B167_164_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B167_164_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B167_164_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B167_164_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B167_164_INMUX_0_MASK)

#define VIRT_WRAP_REG_B167_164_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B167_164_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B167_164_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B167_164_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B167_164_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B167_164_INMUX_1_MASK)

#define VIRT_WRAP_REG_B167_164_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B167_164_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B167_164_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B167_164_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B167_164_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B167_164_INMUX_2_MASK)

#define VIRT_WRAP_REG_B167_164_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B167_164_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B167_164_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B167_164_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B167_164_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B167_164_INMUX_3_MASK)
/*! @} */

/*! @name REG_B171_168 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B171_168_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B171_168_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B171_168_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B171_168_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B171_168_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B171_168_INMUX_0_MASK)

#define VIRT_WRAP_REG_B171_168_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B171_168_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B171_168_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B171_168_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B171_168_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B171_168_INMUX_1_MASK)

#define VIRT_WRAP_REG_B171_168_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B171_168_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B171_168_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B171_168_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B171_168_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B171_168_INMUX_2_MASK)

#define VIRT_WRAP_REG_B171_168_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B171_168_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B171_168_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B171_168_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B171_168_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B171_168_INMUX_3_MASK)
/*! @} */

/*! @name REG_B175_172 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B175_172_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B175_172_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B175_172_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B175_172_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B175_172_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B175_172_INMUX_0_MASK)

#define VIRT_WRAP_REG_B175_172_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B175_172_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B175_172_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B175_172_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B175_172_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B175_172_INMUX_1_MASK)

#define VIRT_WRAP_REG_B175_172_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B175_172_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B175_172_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B175_172_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B175_172_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B175_172_INMUX_2_MASK)

#define VIRT_WRAP_REG_B175_172_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B175_172_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B175_172_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B175_172_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B175_172_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B175_172_INMUX_3_MASK)
/*! @} */

/*! @name REG_B179_176 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B179_176_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B179_176_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B179_176_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B179_176_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B179_176_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B179_176_INMUX_0_MASK)

#define VIRT_WRAP_REG_B179_176_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B179_176_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B179_176_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B179_176_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B179_176_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B179_176_INMUX_1_MASK)

#define VIRT_WRAP_REG_B179_176_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B179_176_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B179_176_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B179_176_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B179_176_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B179_176_INMUX_2_MASK)

#define VIRT_WRAP_REG_B179_176_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B179_176_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B179_176_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B179_176_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B179_176_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B179_176_INMUX_3_MASK)
/*! @} */

/*! @name REG_B183_180 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B183_180_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B183_180_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B183_180_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B183_180_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B183_180_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B183_180_INMUX_0_MASK)

#define VIRT_WRAP_REG_B183_180_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B183_180_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B183_180_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B183_180_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B183_180_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B183_180_INMUX_1_MASK)

#define VIRT_WRAP_REG_B183_180_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B183_180_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B183_180_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B183_180_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B183_180_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B183_180_INMUX_2_MASK)

#define VIRT_WRAP_REG_B183_180_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B183_180_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B183_180_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B183_180_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B183_180_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B183_180_INMUX_3_MASK)
/*! @} */

/*! @name REG_B187_184 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B187_184_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B187_184_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B187_184_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B187_184_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B187_184_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B187_184_INMUX_0_MASK)

#define VIRT_WRAP_REG_B187_184_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B187_184_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B187_184_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B187_184_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B187_184_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B187_184_INMUX_1_MASK)

#define VIRT_WRAP_REG_B187_184_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B187_184_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B187_184_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B187_184_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B187_184_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B187_184_INMUX_2_MASK)

#define VIRT_WRAP_REG_B187_184_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B187_184_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B187_184_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B187_184_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B187_184_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B187_184_INMUX_3_MASK)
/*! @} */

/*! @name REG_B191_188 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B191_188_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B191_188_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B191_188_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B191_188_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B191_188_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B191_188_INMUX_0_MASK)

#define VIRT_WRAP_REG_B191_188_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B191_188_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B191_188_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B191_188_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B191_188_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B191_188_INMUX_1_MASK)

#define VIRT_WRAP_REG_B191_188_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B191_188_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B191_188_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B191_188_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B191_188_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B191_188_INMUX_2_MASK)

#define VIRT_WRAP_REG_B191_188_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B191_188_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B191_188_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B191_188_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B191_188_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B191_188_INMUX_3_MASK)
/*! @} */

/*! @name REG_B195_192 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B195_192_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B195_192_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B195_192_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B195_192_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B195_192_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B195_192_INMUX_0_MASK)

#define VIRT_WRAP_REG_B195_192_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B195_192_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B195_192_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B195_192_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B195_192_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B195_192_INMUX_1_MASK)

#define VIRT_WRAP_REG_B195_192_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B195_192_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B195_192_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B195_192_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B195_192_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B195_192_INMUX_2_MASK)

#define VIRT_WRAP_REG_B195_192_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B195_192_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B195_192_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B195_192_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B195_192_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B195_192_INMUX_3_MASK)
/*! @} */

/*! @name REG_B199_196 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B199_196_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B199_196_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B199_196_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B199_196_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B199_196_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B199_196_INMUX_0_MASK)

#define VIRT_WRAP_REG_B199_196_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B199_196_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B199_196_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B199_196_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B199_196_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B199_196_INMUX_1_MASK)

#define VIRT_WRAP_REG_B199_196_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B199_196_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B199_196_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B199_196_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B199_196_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B199_196_INMUX_2_MASK)

#define VIRT_WRAP_REG_B199_196_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B199_196_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B199_196_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B199_196_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B199_196_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B199_196_INMUX_3_MASK)
/*! @} */

/*! @name REG_B203_200 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B203_200_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B203_200_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B203_200_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B203_200_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B203_200_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B203_200_INMUX_0_MASK)

#define VIRT_WRAP_REG_B203_200_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B203_200_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B203_200_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B203_200_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B203_200_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B203_200_INMUX_1_MASK)

#define VIRT_WRAP_REG_B203_200_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B203_200_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B203_200_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B203_200_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B203_200_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B203_200_INMUX_2_MASK)

#define VIRT_WRAP_REG_B203_200_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B203_200_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B203_200_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B203_200_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B203_200_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B203_200_INMUX_3_MASK)
/*! @} */

/*! @name REG_B207_204 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B207_204_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B207_204_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B207_204_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B207_204_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B207_204_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B207_204_INMUX_0_MASK)

#define VIRT_WRAP_REG_B207_204_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B207_204_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B207_204_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B207_204_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B207_204_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B207_204_INMUX_1_MASK)

#define VIRT_WRAP_REG_B207_204_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B207_204_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B207_204_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B207_204_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B207_204_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B207_204_INMUX_2_MASK)

#define VIRT_WRAP_REG_B207_204_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B207_204_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B207_204_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B207_204_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B207_204_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B207_204_INMUX_3_MASK)
/*! @} */

/*! @name REG_B211_208 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B211_208_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B211_208_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B211_208_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B211_208_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B211_208_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B211_208_INMUX_0_MASK)

#define VIRT_WRAP_REG_B211_208_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B211_208_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B211_208_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B211_208_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B211_208_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B211_208_INMUX_1_MASK)

#define VIRT_WRAP_REG_B211_208_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B211_208_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B211_208_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B211_208_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B211_208_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B211_208_INMUX_2_MASK)

#define VIRT_WRAP_REG_B211_208_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B211_208_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B211_208_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B211_208_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B211_208_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B211_208_INMUX_3_MASK)
/*! @} */

/*! @name REG_B215_212 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B215_212_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B215_212_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B215_212_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B215_212_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B215_212_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B215_212_INMUX_0_MASK)

#define VIRT_WRAP_REG_B215_212_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B215_212_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B215_212_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B215_212_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B215_212_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B215_212_INMUX_1_MASK)

#define VIRT_WRAP_REG_B215_212_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B215_212_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B215_212_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B215_212_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B215_212_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B215_212_INMUX_2_MASK)

#define VIRT_WRAP_REG_B215_212_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B215_212_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B215_212_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B215_212_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B215_212_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B215_212_INMUX_3_MASK)
/*! @} */

/*! @name REG_B219_216 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B219_216_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B219_216_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B219_216_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B219_216_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B219_216_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B219_216_INMUX_1_MASK)

#define VIRT_WRAP_REG_B219_216_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B219_216_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B219_216_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B219_216_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B219_216_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B219_216_INMUX_3_MASK)
/*! @} */

/*! @name REG_B223_220 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B223_220_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B223_220_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B223_220_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B223_220_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B223_220_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B223_220_INMUX_0_MASK)

#define VIRT_WRAP_REG_B223_220_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B223_220_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B223_220_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B223_220_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B223_220_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B223_220_INMUX_1_MASK)

#define VIRT_WRAP_REG_B223_220_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B223_220_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B223_220_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B223_220_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B223_220_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B223_220_INMUX_2_MASK)

#define VIRT_WRAP_REG_B223_220_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B223_220_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B223_220_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B223_220_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B223_220_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B223_220_INMUX_3_MASK)
/*! @} */

/*! @name REG_B227_224 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B227_224_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B227_224_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B227_224_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B227_224_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B227_224_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B227_224_INMUX_0_MASK)

#define VIRT_WRAP_REG_B227_224_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B227_224_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B227_224_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B227_224_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B227_224_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B227_224_INMUX_1_MASK)

#define VIRT_WRAP_REG_B227_224_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B227_224_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B227_224_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B227_224_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B227_224_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B227_224_INMUX_2_MASK)

#define VIRT_WRAP_REG_B227_224_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B227_224_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B227_224_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B227_224_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B227_224_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B227_224_INMUX_3_MASK)
/*! @} */

/*! @name REG_B231_228 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B231_228_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B231_228_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B231_228_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B231_228_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B231_228_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B231_228_INMUX_3_MASK)
/*! @} */

/*! @name REG_B235_232 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B235_232_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B235_232_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B235_232_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B235_232_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B235_232_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B235_232_INMUX_0_MASK)

#define VIRT_WRAP_REG_B235_232_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B235_232_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B235_232_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B235_232_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B235_232_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B235_232_INMUX_3_MASK)
/*! @} */

/*! @name REG_B239_236 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B239_236_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B239_236_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B239_236_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B239_236_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B239_236_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B239_236_INMUX_0_MASK)

#define VIRT_WRAP_REG_B239_236_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B239_236_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B239_236_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B239_236_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B239_236_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B239_236_INMUX_1_MASK)

#define VIRT_WRAP_REG_B239_236_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B239_236_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B239_236_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B239_236_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B239_236_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B239_236_INMUX_2_MASK)

#define VIRT_WRAP_REG_B239_236_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B239_236_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B239_236_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B239_236_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B239_236_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B239_236_INMUX_3_MASK)
/*! @} */

/*! @name REG_B243_240 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B243_240_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B243_240_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B243_240_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B243_240_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B243_240_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B243_240_INMUX_0_MASK)

#define VIRT_WRAP_REG_B243_240_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B243_240_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B243_240_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B243_240_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B243_240_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B243_240_INMUX_1_MASK)

#define VIRT_WRAP_REG_B243_240_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B243_240_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B243_240_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B243_240_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B243_240_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B243_240_INMUX_2_MASK)

#define VIRT_WRAP_REG_B243_240_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B243_240_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B243_240_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B243_240_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B243_240_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B243_240_INMUX_3_MASK)
/*! @} */

/*! @name REG_B247_244 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B247_244_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B247_244_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B247_244_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B247_244_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B247_244_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B247_244_INMUX_0_MASK)

#define VIRT_WRAP_REG_B247_244_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B247_244_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B247_244_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B247_244_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B247_244_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B247_244_INMUX_1_MASK)

#define VIRT_WRAP_REG_B247_244_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B247_244_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B247_244_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B247_244_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B247_244_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B247_244_INMUX_2_MASK)

#define VIRT_WRAP_REG_B247_244_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B247_244_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B247_244_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B247_244_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B247_244_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B247_244_INMUX_3_MASK)
/*! @} */

/*! @name REG_B251_248 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B251_248_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B251_248_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B251_248_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B251_248_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B251_248_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B251_248_INMUX_0_MASK)

#define VIRT_WRAP_REG_B251_248_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B251_248_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B251_248_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B251_248_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B251_248_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B251_248_INMUX_1_MASK)

#define VIRT_WRAP_REG_B251_248_INMUX_2_MASK      (0xF0000U)
#define VIRT_WRAP_REG_B251_248_INMUX_2_SHIFT     (16U)
#define VIRT_WRAP_REG_B251_248_INMUX_2_WIDTH     (4U)
#define VIRT_WRAP_REG_B251_248_INMUX_2(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B251_248_INMUX_2_SHIFT)) & VIRT_WRAP_REG_B251_248_INMUX_2_MASK)

#define VIRT_WRAP_REG_B251_248_INMUX_3_MASK      (0xF000000U)
#define VIRT_WRAP_REG_B251_248_INMUX_3_SHIFT     (24U)
#define VIRT_WRAP_REG_B251_248_INMUX_3_WIDTH     (4U)
#define VIRT_WRAP_REG_B251_248_INMUX_3(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B251_248_INMUX_3_SHIFT)) & VIRT_WRAP_REG_B251_248_INMUX_3_MASK)
/*! @} */

/*! @name REG_B255_252 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_B255_252_INMUX_0_MASK      (0xFU)
#define VIRT_WRAP_REG_B255_252_INMUX_0_SHIFT     (0U)
#define VIRT_WRAP_REG_B255_252_INMUX_0_WIDTH     (4U)
#define VIRT_WRAP_REG_B255_252_INMUX_0(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B255_252_INMUX_0_SHIFT)) & VIRT_WRAP_REG_B255_252_INMUX_0_MASK)

#define VIRT_WRAP_REG_B255_252_INMUX_1_MASK      (0xF00U)
#define VIRT_WRAP_REG_B255_252_INMUX_1_SHIFT     (8U)
#define VIRT_WRAP_REG_B255_252_INMUX_1_WIDTH     (4U)
#define VIRT_WRAP_REG_B255_252_INMUX_1(x)        (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_B255_252_INMUX_1_SHIFT)) & VIRT_WRAP_REG_B255_252_INMUX_1_MASK)
/*! @} */

/*! @name REG_C - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_C_INTC_CTRL_MASK           (0xFU)
#define VIRT_WRAP_REG_C_INTC_CTRL_SHIFT          (0U)
#define VIRT_WRAP_REG_C_INTC_CTRL_WIDTH          (4U)
#define VIRT_WRAP_REG_C_INTC_CTRL(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_C_INTC_CTRL_SHIFT)) & VIRT_WRAP_REG_C_INTC_CTRL_MASK)
/*! @} */

/*! @name REG_D - Parameter_n Register */
/*! @{ */

#define VIRT_WRAP_REG_D_REG_GCR_MASK             (0xFU)
#define VIRT_WRAP_REG_D_REG_GCR_SHIFT            (0U)
#define VIRT_WRAP_REG_D_REG_GCR_WIDTH            (4U)
#define VIRT_WRAP_REG_D_REG_GCR(x)               (((uint32_t)(((uint32_t)(x)) << VIRT_WRAP_REG_D_REG_GCR_SHIFT)) & VIRT_WRAP_REG_D_REG_GCR_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group VIRT_WRAP_Register_Masks */

/*!
 * @}
 */ /* end of group VIRT_WRAP_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_VIRT_WRAP_H_) */
