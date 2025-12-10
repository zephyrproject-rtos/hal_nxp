/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_MC_CGM.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_MC_CGM
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
#if !defined(S32K566_MC_CGM_H_)  /* Check if memory map has not been already included */
#define S32K566_MC_CGM_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- MC_CGM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MC_CGM_Peripheral_Access_Layer MC_CGM Peripheral Access Layer
 * @{
 */

/** MC_CGM - Register Layout Typedef */
typedef struct MC_CGM_Struct {
  __IO uint32_t PCFS_SDUR;                         /**< PCFS Step Duration, offset: 0x0, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_3, MC_CGM_4 (missing on MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC1;                        /**< PCFS Divider Change 1, offset: 0x4, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_3 (missing on MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE1;                        /**< PCFS Divider End 1, offset: 0x8, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_3 (missing on MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS1;                        /**< PCFS Divider Start 1, offset: 0xC, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_3 (missing on MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC2;                        /**< PCFS Divider Change 2, offset: 0x10, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_3 (missing on MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE2;                        /**< PCFS Divider End 2, offset: 0x14, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_3 (missing on MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS2;                        /**< PCFS Divider Start 2, offset: 0x18, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_3 (missing on MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC3;                        /**< PCFS Divider Change 3, offset: 0x1C, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_3 (missing on MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE3;                        /**< PCFS Divider End 3, offset: 0x20, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_3 (missing on MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS3;                        /**< PCFS Divider Start 3, offset: 0x24, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_3 (missing on MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC4;                        /**< PCFS Divider Change 4, offset: 0x28, available only on: LPE_MC_CGM, MC_CGM_3 (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE4;                        /**< PCFS Divider End 4, offset: 0x2C, available only on: LPE_MC_CGM, MC_CGM_3 (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS4;                        /**< PCFS Divider Start 4, offset: 0x30, available only on: LPE_MC_CGM, MC_CGM_3 (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC5;                        /**< PCFS Divider Change 5, offset: 0x34, available only on: CPE_MC_CGM, MC_CGM_3, MC_CGM_4 (missing on LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE5;                        /**< PCFS Divider End 5, offset: 0x38, available only on: CPE_MC_CGM, MC_CGM_3, MC_CGM_4 (missing on LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS5;                        /**< PCFS Divider Start 5, offset: 0x3C, available only on: CPE_MC_CGM, MC_CGM_3, MC_CGM_4 (missing on LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC6;                        /**< PCFS Divider Change 6, offset: 0x40, available only on: LPE_MC_CGM (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE6;                        /**< PCFS Divider End 6, offset: 0x44, available only on: LPE_MC_CGM (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS6;                        /**< PCFS Divider Start 6, offset: 0x48, available only on: LPE_MC_CGM (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC7;                        /**< PCFS Divider Change 7, offset: 0x4C, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE7;                        /**< PCFS Divider End 7, offset: 0x50, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS7;                        /**< PCFS Divider Start 7, offset: 0x54, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC8;                        /**< PCFS Divider Change 8, offset: 0x58, available only on: CPE_MC_CGM, LPE_MC_CGM (missing on MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE8;                        /**< PCFS Divider End 8, offset: 0x5C, available only on: CPE_MC_CGM, LPE_MC_CGM (missing on MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS8;                        /**< PCFS Divider Start 8, offset: 0x60, available only on: CPE_MC_CGM, LPE_MC_CGM (missing on MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC9;                        /**< PCFS Divider Change 9, offset: 0x64, available only on: CPE_MC_CGM, MC_CGM_3 (missing on LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE9;                        /**< PCFS Divider End 9, offset: 0x68, available only on: CPE_MC_CGM, MC_CGM_3 (missing on LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS9;                        /**< PCFS Divider Start 9, offset: 0x6C, available only on: CPE_MC_CGM, MC_CGM_3 (missing on LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC10;                       /**< PCFS Divider Change 10, offset: 0x70, available only on: CPE_MC_CGM (missing on LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE10;                       /**< PCFS Divider End 10, offset: 0x74, available only on: CPE_MC_CGM (missing on LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS10;                       /**< PCFS Divider Start 10, offset: 0x78, available only on: CPE_MC_CGM (missing on LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC11;                       /**< PCFS Divider Change 11, offset: 0x7C, available only on: LPE_MC_CGM (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE11;                       /**< PCFS Divider End 11, offset: 0x80, available only on: LPE_MC_CGM (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS11;                       /**< PCFS Divider Start 11, offset: 0x84, available only on: LPE_MC_CGM (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC12;                       /**< PCFS Divider Change 12, offset: 0x88, available only on: LPE_MC_CGM (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE12;                       /**< PCFS Divider End 12, offset: 0x8C, available only on: LPE_MC_CGM (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS12;                       /**< PCFS Divider Start 12, offset: 0x90, available only on: LPE_MC_CGM (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC13;                       /**< PCFS Divider Change 13, offset: 0x94, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE13;                       /**< PCFS Divider End 13, offset: 0x98, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS13;                       /**< PCFS Divider Start 13, offset: 0x9C, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC14;                       /**< PCFS Divider Change 14, offset: 0xA0, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE14;                       /**< PCFS Divider End 14, offset: 0xA4, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS14;                       /**< PCFS Divider Start 14, offset: 0xA8, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC15;                       /**< PCFS Divider Change 15, offset: 0xAC, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE15;                       /**< PCFS Divider End 15, offset: 0xB0, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS15;                       /**< PCFS Divider Start 15, offset: 0xB4, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC16;                       /**< PCFS Divider Change 16, offset: 0xB8, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE16;                       /**< PCFS Divider End 16, offset: 0xBC, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS16;                       /**< PCFS Divider Start 16, offset: 0xC0, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC17;                       /**< PCFS Divider Change 17, offset: 0xC4, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE17;                       /**< PCFS Divider End 17, offset: 0xC8, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS17;                       /**< PCFS Divider Start 17, offset: 0xCC, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC18;                       /**< PCFS Divider Change 18, offset: 0xD0, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE18;                       /**< PCFS Divider End 18, offset: 0xD4, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS18;                       /**< PCFS Divider Start 18, offset: 0xD8, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC19;                       /**< PCFS Divider Change 19, offset: 0xDC, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE19;                       /**< PCFS Divider End 19, offset: 0xE0, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS19;                       /**< PCFS Divider Start 19, offset: 0xE4, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC20;                       /**< PCFS Divider Change 20, offset: 0xE8, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE20;                       /**< PCFS Divider End 20, offset: 0xEC, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS20;                       /**< PCFS Divider Start 20, offset: 0xF0, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  uint8_t RESERVED_0[312];
  __IO uint32_t PCFS_DIVC47;                       /**< PCFS Divider Change 47, offset: 0x22C, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE47;                       /**< PCFS Divider End 47, offset: 0x230, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS47;                       /**< PCFS Divider Start 47, offset: 0x234, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC48;                       /**< PCFS Divider Change 48, offset: 0x238, available only on: LPE_MC_CGM (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE48;                       /**< PCFS Divider End 48, offset: 0x23C, available only on: LPE_MC_CGM (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS48;                       /**< PCFS Divider Start 48, offset: 0x240, available only on: LPE_MC_CGM (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC49;                       /**< PCFS Divider Change 49, offset: 0x244, available only on: LPE_MC_CGM (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE49;                       /**< PCFS Divider End 49, offset: 0x248, available only on: LPE_MC_CGM (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS49;                       /**< PCFS Divider Start 49, offset: 0x24C, available only on: LPE_MC_CGM (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC50;                       /**< PCFS Divider Change 50, offset: 0x250, available only on: LPE_MC_CGM (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE50;                       /**< PCFS Divider End 50, offset: 0x254, available only on: LPE_MC_CGM (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS50;                       /**< PCFS Divider Start 50, offset: 0x258, available only on: LPE_MC_CGM (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC51;                       /**< PCFS Divider Change 51, offset: 0x25C, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE51;                       /**< PCFS Divider End 51, offset: 0x260, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS51;                       /**< PCFS Divider Start 51, offset: 0x264, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVC52;                       /**< PCFS Divider Change 52, offset: 0x268, available only on: LPE_MC_CGM, MC_CGM_3 (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE52;                       /**< PCFS Divider End 52, offset: 0x26C, available only on: LPE_MC_CGM, MC_CGM_3 (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS52;                       /**< PCFS Divider Start 52, offset: 0x270, available only on: LPE_MC_CGM, MC_CGM_3 (missing on CPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  uint8_t RESERVED_1[120];
  __IO uint32_t PCFS_DIVC63;                       /**< PCFS Divider Change 63, offset: 0x2EC, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_3, MC_CGM_4 (missing on MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_5) */
  __IO uint32_t PCFS_DIVE63;                       /**< PCFS Divider End 63, offset: 0x2F0, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_3, MC_CGM_4 (missing on MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_5) */
  __IO uint32_t PCFS_DIVS63;                       /**< PCFS Divider Start 63, offset: 0x2F4, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_3, MC_CGM_4 (missing on MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_5) */
  uint8_t RESERVED_2[8];
  __IO uint32_t SLC_0_CSC;                         /**< Clock Slice 0 Select Control, offset: 0x300, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5 (missing on MC_CGM_1) */
  __I  uint32_t SLC_0_CSS;                         /**< Clock Slice 0 Select Status, offset: 0x304, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5 (missing on MC_CGM_1) */
  __IO uint32_t SLC_0_DC_0;                        /**< Clock Slice 0 Divider 0 Control, offset: 0x308, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5 (missing on MC_CGM_1) */
  __IO uint32_t SLC_0_DC_1;                        /**< Clock Slice 0 Divider 1 Control, offset: 0x30C, available only on: CPE_MC_CGM, MC_CGM_3 (missing on LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_0_DC_2;                        /**< Clock Slice 0 Divider 2 Control, offset: 0x310, available only on: CPE_MC_CGM, MC_CGM_3 (missing on LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_0_DC_3;                        /**< Clock Slice 0 Divider 3 Control, offset: 0x314, available only on: CPE_MC_CGM, MC_CGM_3 (missing on LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  uint8_t RESERVED_3[28];
  __IO uint32_t SLC_0_DIV_TRIG_CTRL;               /**< Clock Slice 0 Divider Trigger Control, offset: 0x334, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_3, MC_CGM_4 (missing on MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_5) */
  __IO uint32_t SLC_0_DIV_TRIG;                    /**< Clock Slice 0 Divider Trigger, offset: 0x338, available only on: CPE_MC_CGM, MC_CGM_3 (missing on LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __I  uint32_t SLC_0_DIV_UPD_STAT;                /**< Clock Slice 0 Divider Update Status, offset: 0x33C, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5 (missing on MC_CGM_1) */
  __IO uint32_t SLC_1_CSC;                         /**< Clock Slice 1 Select Control, offset: 0x340, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_3, MC_CGM_4 (missing on MC_CGM_2, MC_CGM_5) */
  __I  uint32_t SLC_1_CSS;                         /**< Clock Slice 1 Select Status, offset: 0x344, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_3, MC_CGM_4 (missing on MC_CGM_2, MC_CGM_5) */
  __IO uint32_t SLC_1_DC_0;                        /**< Clock Slice 1 Divider 0 Control, offset: 0x348, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_3, MC_CGM_4 (missing on MC_CGM_2, MC_CGM_5) */
  uint8_t RESERVED_4[48];
  __I  uint32_t SLC_1_DIV_UPD_STAT;                /**< Clock Slice 1 Divider Update Status, offset: 0x37C, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_3, MC_CGM_4 (missing on MC_CGM_2, MC_CGM_5) */
  __IO uint32_t SLC_2_CSC;                         /**< Clock Slice 2 Select Control, offset: 0x380, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_3 (missing on MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __I  uint32_t SLC_2_CSS;                         /**< Clock Slice 2 Select Status, offset: 0x384, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_3 (missing on MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_2_DC_0;                        /**< Clock Slice 2 Divider 0 Control, offset: 0x388, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_3 (missing on MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  uint8_t RESERVED_5[48];
  __I  uint32_t SLC_2_DIV_UPD_STAT;                /**< Clock Slice 2 Divider Update Status, offset: 0x3BC, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_3 (missing on MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_3_CSC;                         /**< Clock Slice 3 Select Control, offset: 0x3C0, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_3 (missing on MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __I  uint32_t SLC_3_CSS;                         /**< Clock Slice 3 Select Status, offset: 0x3C4, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_3 (missing on MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_3_DC_0;                        /**< Clock Slice 3 Divider 0 Control, offset: 0x3C8, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_3 (missing on MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  uint8_t RESERVED_6[48];
  __I  uint32_t SLC_3_DIV_UPD_STAT;                /**< Clock Slice 3 Divider Update Status, offset: 0x3FC, available only on: CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_3 (missing on MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_4_CSC;                         /**< Clock Slice 4 Select Control, offset: 0x400, available only on: LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_3 (missing on CPE_MC_CGM, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __I  uint32_t SLC_4_CSS;                         /**< Clock Slice 4 Select Status, offset: 0x404, available only on: LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_3 (missing on CPE_MC_CGM, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_4_DC_0;                        /**< Clock Slice 4 Divider 0 Control, offset: 0x408, available only on: LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_3 (missing on CPE_MC_CGM, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  uint8_t RESERVED_7[40];
  __IO uint32_t SLC_4_DIV_TRIG_CTRL;               /**< Clock Slice 4 Divider Trigger Control, offset: 0x434, available only on: MC_CGM_1 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  uint8_t RESERVED_8[4];
  __I  uint32_t SLC_4_DIV_UPD_STAT;                /**< Clock Slice 4 Divider Update Status, offset: 0x43C, available only on: LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_3 (missing on CPE_MC_CGM, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_5_CSC;                         /**< Clock Slice 5 Select Control, offset: 0x440, available only on: LPE_MC_CGM, MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __I  uint32_t SLC_5_CSS;                         /**< Clock Slice 5 Select Status, offset: 0x444, available only on: LPE_MC_CGM, MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_5_DC_0;                        /**< Clock Slice 5 Divider 0 Control, offset: 0x448, available only on: LPE_MC_CGM, MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  uint8_t RESERVED_9[48];
  __I  uint32_t SLC_5_DIV_UPD_STAT;                /**< Clock Slice 5 Divider Update Status, offset: 0x47C, available only on: LPE_MC_CGM, MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_6_CSC;                         /**< Clock Slice 6 Select Control, offset: 0x480, available only on: LPE_MC_CGM, MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __I  uint32_t SLC_6_CSS;                         /**< Clock Slice 6 Select Status, offset: 0x484, available only on: LPE_MC_CGM, MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_6_DC_0;                        /**< Clock Slice 6 Divider 0 Control, offset: 0x488, available only on: LPE_MC_CGM, MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  uint8_t RESERVED_10[48];
  __I  uint32_t SLC_6_DIV_UPD_STAT;                /**< Clock Slice 6 Divider Update Status, offset: 0x4BC, available only on: LPE_MC_CGM, MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_7_CSC;                         /**< Clock Slice 7 Select Control, offset: 0x4C0, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __I  uint32_t SLC_7_CSS;                         /**< Clock Slice 7 Select Status, offset: 0x4C4, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_7_DC_0;                        /**< Clock Slice 7 Divider 0 Control, offset: 0x4C8, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  uint8_t RESERVED_11[48];
  __I  uint32_t SLC_7_DIV_UPD_STAT;                /**< Clock Slice 7 Divider Update Status, offset: 0x4FC, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_8_CSC;                         /**< Clock Slice 8 Select Control, offset: 0x500, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __I  uint32_t SLC_8_CSS;                         /**< Clock Slice 8 Select Status, offset: 0x504, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_8_DC_0;                        /**< Clock Slice 8 Divider 0 Control, offset: 0x508, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  uint8_t RESERVED_12[48];
  __I  uint32_t SLC_8_DIV_UPD_STAT;                /**< Clock Slice 8 Divider Update Status, offset: 0x53C, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_9_CSC;                         /**< Clock Slice 9 Select Control, offset: 0x540, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __I  uint32_t SLC_9_CSS;                         /**< Clock Slice 9 Select Status, offset: 0x544, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_9_DC_0;                        /**< Clock Slice 9 Divider 0 Control, offset: 0x548, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  uint8_t RESERVED_13[48];
  __I  uint32_t SLC_9_DIV_UPD_STAT;                /**< Clock Slice 9 Divider Update Status, offset: 0x57C, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_10_CSC;                        /**< Clock Slice 10 Select Control, offset: 0x580, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __I  uint32_t SLC_10_CSS;                        /**< Clock Slice 10 Select Status, offset: 0x584, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_10_DC_0;                       /**< Clock Slice 10 Divider 0 Control, offset: 0x588, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  uint8_t RESERVED_14[40];
  __IO uint32_t SLC_10_DIV_TRIG_CTRL;              /**< Clock Slice 10 Divider Trigger Control, offset: 0x5B4, available only on: MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_0, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  uint8_t RESERVED_15[4];
  __I  uint32_t SLC_10_DIV_UPD_STAT;               /**< Clock Slice 10 Divider Update Status, offset: 0x5BC, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_11_CSC;                        /**< Clock Slice 11 Select Control, offset: 0x5C0, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __I  uint32_t SLC_11_CSS;                        /**< Clock Slice 11 Select Status, offset: 0x5C4, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_11_DC_0;                       /**< Clock Slice 11 Divider 0 Control, offset: 0x5C8, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  uint8_t RESERVED_16[48];
  __I  uint32_t SLC_11_DIV_UPD_STAT;               /**< Clock Slice 11 Divider Update Status, offset: 0x5FC, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_12_CSC;                        /**< Clock Slice 12 Select Control, offset: 0x600, available only on: MC_CGM_0 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __I  uint32_t SLC_12_CSS;                        /**< Clock Slice 12 Select Status, offset: 0x604, available only on: MC_CGM_0 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_12_DC_0;                       /**< Clock Slice 12 Divider 0 Control, offset: 0x608, available only on: MC_CGM_0 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  uint8_t RESERVED_17[48];
  __I  uint32_t SLC_12_DIV_UPD_STAT;               /**< Clock Slice 12 Divider Update Status, offset: 0x63C, available only on: MC_CGM_0 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_13_CSC;                        /**< Clock Slice 13 Select Control, offset: 0x640, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __I  uint32_t SLC_13_CSS;                        /**< Clock Slice 13 Select Status, offset: 0x644, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_13_DC_0;                       /**< Clock Slice 13 Divider 0 Control, offset: 0x648, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  uint8_t RESERVED_18[48];
  __I  uint32_t SLC_13_DIV_UPD_STAT;               /**< Clock Slice 13 Divider Update Status, offset: 0x67C, available only on: MC_CGM_0, MC_CGM_3 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_14_CSC;                        /**< Clock Slice 14 Select Control, offset: 0x680, available only on: MC_CGM_0 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __I  uint32_t SLC_14_CSS;                        /**< Clock Slice 14 Select Status, offset: 0x684, available only on: MC_CGM_0 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  __IO uint32_t SLC_14_DC_0;                       /**< Clock Slice 14 Divider 0 Control, offset: 0x688, available only on: MC_CGM_0 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
  uint8_t RESERVED_19[48];
  __I  uint32_t SLC_14_DIV_UPD_STAT;               /**< Clock Slice 14 Divider Update Status, offset: 0x6BC, available only on: MC_CGM_0 (missing on CPE_MC_CGM, LPE_MC_CGM, MC_CGM_1, MC_CGM_2, MC_CGM_3, MC_CGM_4, MC_CGM_5) */
} MC_CGM_Type, *MC_CGM_MemMapPtr;

/** Number of instances of the MC_CGM module. */
#define MC_CGM_INSTANCE_COUNT                    (8u)

/* MC_CGM - Peripheral instance base addresses */
/** Peripheral CPE_MC_CGM base address */
#define IP_CPE_MC_CGM_BASE                       (0x41074000u)
/** Peripheral CPE_MC_CGM base pointer */
#define IP_CPE_MC_CGM                            ((MC_CGM_Type *)IP_CPE_MC_CGM_BASE)
/** Peripheral LPE_MC_CGM base address */
#define IP_LPE_MC_CGM_BASE                       (0x42120000u)
/** Peripheral LPE_MC_CGM base pointer */
#define IP_LPE_MC_CGM                            ((MC_CGM_Type *)IP_LPE_MC_CGM_BASE)
/** Peripheral MC_CGM_0 base address */
#define IP_MC_CGM_0_BASE                         (0x40094000u)
/** Peripheral MC_CGM_0 base pointer */
#define IP_MC_CGM_0                              ((MC_CGM_Type *)IP_MC_CGM_0_BASE)
/** Peripheral MC_CGM_1 base address */
#define IP_MC_CGM_1_BASE                         (0x40098000u)
/** Peripheral MC_CGM_1 base pointer */
#define IP_MC_CGM_1                              ((MC_CGM_Type *)IP_MC_CGM_1_BASE)
/** Peripheral MC_CGM_2 base address */
#define IP_MC_CGM_2_BASE                         (0x402FC000u)
/** Peripheral MC_CGM_2 base pointer */
#define IP_MC_CGM_2                              ((MC_CGM_Type *)IP_MC_CGM_2_BASE)
/** Peripheral MC_CGM_3 base address */
#define IP_MC_CGM_3_BASE                         (0x404B8000u)
/** Peripheral MC_CGM_3 base pointer */
#define IP_MC_CGM_3                              ((MC_CGM_Type *)IP_MC_CGM_3_BASE)
/** Peripheral MC_CGM_4 base address */
#define IP_MC_CGM_4_BASE                         (0x40B38000u)
/** Peripheral MC_CGM_4 base pointer */
#define IP_MC_CGM_4                              ((MC_CGM_Type *)IP_MC_CGM_4_BASE)
/** Peripheral MC_CGM_5 base address */
#define IP_MC_CGM_5_BASE                         (0x40B3C000u)
/** Peripheral MC_CGM_5 base pointer */
#define IP_MC_CGM_5                              ((MC_CGM_Type *)IP_MC_CGM_5_BASE)
/** Array initializer of MC_CGM peripheral base addresses */
#define IP_MC_CGM_BASE_ADDRS                     { IP_CPE_MC_CGM_BASE, IP_LPE_MC_CGM_BASE, IP_MC_CGM_0_BASE, IP_MC_CGM_1_BASE, IP_MC_CGM_2_BASE, IP_MC_CGM_3_BASE, IP_MC_CGM_4_BASE, IP_MC_CGM_5_BASE }
/** Array initializer of MC_CGM peripheral base pointers */
#define IP_MC_CGM_BASE_PTRS                      { IP_CPE_MC_CGM, IP_LPE_MC_CGM, IP_MC_CGM_0, IP_MC_CGM_1, IP_MC_CGM_2, IP_MC_CGM_3, IP_MC_CGM_4, IP_MC_CGM_5 }

/* ----------------------------------------------------------------------------
   -- MC_CGM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MC_CGM_Register_Masks MC_CGM Register Masks
 * @{
 */

/*! @name PCFS_SDUR - PCFS Step Duration */
/*! @{ */

#define MC_CGM_PCFS_SDUR_SDUR_MASK               (0xFFFFU)
#define MC_CGM_PCFS_SDUR_SDUR_SHIFT              (0U)
#define MC_CGM_PCFS_SDUR_SDUR_WIDTH              (16U)
#define MC_CGM_PCFS_SDUR_SDUR(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_SDUR_SDUR_SHIFT)) & MC_CGM_PCFS_SDUR_SDUR_MASK)
/*! @} */

/*! @name PCFS_DIVC1 - PCFS Divider Change 1 */
/*! @{ */

#define MC_CGM_PCFS_DIVC1_RATE_MASK              (0xFFU)
#define MC_CGM_PCFS_DIVC1_RATE_SHIFT             (0U)
#define MC_CGM_PCFS_DIVC1_RATE_WIDTH             (8U)
#define MC_CGM_PCFS_DIVC1_RATE(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC1_RATE_SHIFT)) & MC_CGM_PCFS_DIVC1_RATE_MASK)

#define MC_CGM_PCFS_DIVC1_INIT_MASK              (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC1_INIT_SHIFT             (16U)
#define MC_CGM_PCFS_DIVC1_INIT_WIDTH             (16U)
#define MC_CGM_PCFS_DIVC1_INIT(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC1_INIT_SHIFT)) & MC_CGM_PCFS_DIVC1_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE1 - PCFS Divider End 1 */
/*! @{ */

#define MC_CGM_PCFS_DIVE1_DIVE_MASK              (0xFFFFFU)
#define MC_CGM_PCFS_DIVE1_DIVE_SHIFT             (0U)
#define MC_CGM_PCFS_DIVE1_DIVE_WIDTH             (20U)
#define MC_CGM_PCFS_DIVE1_DIVE(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE1_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE1_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS1 - PCFS Divider Start 1 */
/*! @{ */

#define MC_CGM_PCFS_DIVS1_DIVS_MASK              (0xFFFFFU)
#define MC_CGM_PCFS_DIVS1_DIVS_SHIFT             (0U)
#define MC_CGM_PCFS_DIVS1_DIVS_WIDTH             (20U)
#define MC_CGM_PCFS_DIVS1_DIVS(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS1_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS1_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC2 - PCFS Divider Change 2 */
/*! @{ */

#define MC_CGM_PCFS_DIVC2_RATE_MASK              (0xFFU)
#define MC_CGM_PCFS_DIVC2_RATE_SHIFT             (0U)
#define MC_CGM_PCFS_DIVC2_RATE_WIDTH             (8U)
#define MC_CGM_PCFS_DIVC2_RATE(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC2_RATE_SHIFT)) & MC_CGM_PCFS_DIVC2_RATE_MASK)

#define MC_CGM_PCFS_DIVC2_INIT_MASK              (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC2_INIT_SHIFT             (16U)
#define MC_CGM_PCFS_DIVC2_INIT_WIDTH             (16U)
#define MC_CGM_PCFS_DIVC2_INIT(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC2_INIT_SHIFT)) & MC_CGM_PCFS_DIVC2_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE2 - PCFS Divider End 2 */
/*! @{ */

#define MC_CGM_PCFS_DIVE2_DIVE_MASK              (0xFFFFFU)
#define MC_CGM_PCFS_DIVE2_DIVE_SHIFT             (0U)
#define MC_CGM_PCFS_DIVE2_DIVE_WIDTH             (20U)
#define MC_CGM_PCFS_DIVE2_DIVE(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE2_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE2_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS2 - PCFS Divider Start 2 */
/*! @{ */

#define MC_CGM_PCFS_DIVS2_DIVS_MASK              (0xFFFFFU)
#define MC_CGM_PCFS_DIVS2_DIVS_SHIFT             (0U)
#define MC_CGM_PCFS_DIVS2_DIVS_WIDTH             (20U)
#define MC_CGM_PCFS_DIVS2_DIVS(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS2_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS2_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC3 - PCFS Divider Change 3 */
/*! @{ */

#define MC_CGM_PCFS_DIVC3_RATE_MASK              (0xFFU)
#define MC_CGM_PCFS_DIVC3_RATE_SHIFT             (0U)
#define MC_CGM_PCFS_DIVC3_RATE_WIDTH             (8U)
#define MC_CGM_PCFS_DIVC3_RATE(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC3_RATE_SHIFT)) & MC_CGM_PCFS_DIVC3_RATE_MASK)

#define MC_CGM_PCFS_DIVC3_INIT_MASK              (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC3_INIT_SHIFT             (16U)
#define MC_CGM_PCFS_DIVC3_INIT_WIDTH             (16U)
#define MC_CGM_PCFS_DIVC3_INIT(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC3_INIT_SHIFT)) & MC_CGM_PCFS_DIVC3_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE3 - PCFS Divider End 3 */
/*! @{ */

#define MC_CGM_PCFS_DIVE3_DIVE_MASK              (0xFFFFFU)
#define MC_CGM_PCFS_DIVE3_DIVE_SHIFT             (0U)
#define MC_CGM_PCFS_DIVE3_DIVE_WIDTH             (20U)
#define MC_CGM_PCFS_DIVE3_DIVE(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE3_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE3_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS3 - PCFS Divider Start 3 */
/*! @{ */

#define MC_CGM_PCFS_DIVS3_DIVS_MASK              (0xFFFFFU)
#define MC_CGM_PCFS_DIVS3_DIVS_SHIFT             (0U)
#define MC_CGM_PCFS_DIVS3_DIVS_WIDTH             (20U)
#define MC_CGM_PCFS_DIVS3_DIVS(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS3_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS3_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC4 - PCFS Divider Change 4 */
/*! @{ */

#define MC_CGM_PCFS_DIVC4_RATE_MASK              (0xFFU)
#define MC_CGM_PCFS_DIVC4_RATE_SHIFT             (0U)
#define MC_CGM_PCFS_DIVC4_RATE_WIDTH             (8U)
#define MC_CGM_PCFS_DIVC4_RATE(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC4_RATE_SHIFT)) & MC_CGM_PCFS_DIVC4_RATE_MASK)

#define MC_CGM_PCFS_DIVC4_INIT_MASK              (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC4_INIT_SHIFT             (16U)
#define MC_CGM_PCFS_DIVC4_INIT_WIDTH             (16U)
#define MC_CGM_PCFS_DIVC4_INIT(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC4_INIT_SHIFT)) & MC_CGM_PCFS_DIVC4_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE4 - PCFS Divider End 4 */
/*! @{ */

#define MC_CGM_PCFS_DIVE4_DIVE_MASK              (0xFFFFFU)
#define MC_CGM_PCFS_DIVE4_DIVE_SHIFT             (0U)
#define MC_CGM_PCFS_DIVE4_DIVE_WIDTH             (20U)
#define MC_CGM_PCFS_DIVE4_DIVE(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE4_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE4_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS4 - PCFS Divider Start 4 */
/*! @{ */

#define MC_CGM_PCFS_DIVS4_DIVS_MASK              (0xFFFFFU)
#define MC_CGM_PCFS_DIVS4_DIVS_SHIFT             (0U)
#define MC_CGM_PCFS_DIVS4_DIVS_WIDTH             (20U)
#define MC_CGM_PCFS_DIVS4_DIVS(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS4_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS4_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC5 - PCFS Divider Change 5 */
/*! @{ */

#define MC_CGM_PCFS_DIVC5_RATE_MASK              (0xFFU)
#define MC_CGM_PCFS_DIVC5_RATE_SHIFT             (0U)
#define MC_CGM_PCFS_DIVC5_RATE_WIDTH             (8U)
#define MC_CGM_PCFS_DIVC5_RATE(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC5_RATE_SHIFT)) & MC_CGM_PCFS_DIVC5_RATE_MASK)

#define MC_CGM_PCFS_DIVC5_INIT_MASK              (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC5_INIT_SHIFT             (16U)
#define MC_CGM_PCFS_DIVC5_INIT_WIDTH             (16U)
#define MC_CGM_PCFS_DIVC5_INIT(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC5_INIT_SHIFT)) & MC_CGM_PCFS_DIVC5_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE5 - PCFS Divider End 5 */
/*! @{ */

#define MC_CGM_PCFS_DIVE5_DIVE_MASK              (0xFFFFFU)
#define MC_CGM_PCFS_DIVE5_DIVE_SHIFT             (0U)
#define MC_CGM_PCFS_DIVE5_DIVE_WIDTH             (20U)
#define MC_CGM_PCFS_DIVE5_DIVE(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE5_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE5_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS5 - PCFS Divider Start 5 */
/*! @{ */

#define MC_CGM_PCFS_DIVS5_DIVS_MASK              (0xFFFFFU)
#define MC_CGM_PCFS_DIVS5_DIVS_SHIFT             (0U)
#define MC_CGM_PCFS_DIVS5_DIVS_WIDTH             (20U)
#define MC_CGM_PCFS_DIVS5_DIVS(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS5_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS5_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC6 - PCFS Divider Change 6 */
/*! @{ */

#define MC_CGM_PCFS_DIVC6_RATE_MASK              (0xFFU)
#define MC_CGM_PCFS_DIVC6_RATE_SHIFT             (0U)
#define MC_CGM_PCFS_DIVC6_RATE_WIDTH             (8U)
#define MC_CGM_PCFS_DIVC6_RATE(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC6_RATE_SHIFT)) & MC_CGM_PCFS_DIVC6_RATE_MASK)

#define MC_CGM_PCFS_DIVC6_INIT_MASK              (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC6_INIT_SHIFT             (16U)
#define MC_CGM_PCFS_DIVC6_INIT_WIDTH             (16U)
#define MC_CGM_PCFS_DIVC6_INIT(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC6_INIT_SHIFT)) & MC_CGM_PCFS_DIVC6_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE6 - PCFS Divider End 6 */
/*! @{ */

#define MC_CGM_PCFS_DIVE6_DIVE_MASK              (0xFFFFFU)
#define MC_CGM_PCFS_DIVE6_DIVE_SHIFT             (0U)
#define MC_CGM_PCFS_DIVE6_DIVE_WIDTH             (20U)
#define MC_CGM_PCFS_DIVE6_DIVE(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE6_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE6_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS6 - PCFS Divider Start 6 */
/*! @{ */

#define MC_CGM_PCFS_DIVS6_DIVS_MASK              (0xFFFFFU)
#define MC_CGM_PCFS_DIVS6_DIVS_SHIFT             (0U)
#define MC_CGM_PCFS_DIVS6_DIVS_WIDTH             (20U)
#define MC_CGM_PCFS_DIVS6_DIVS(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS6_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS6_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC7 - PCFS Divider Change 7 */
/*! @{ */

#define MC_CGM_PCFS_DIVC7_RATE_MASK              (0xFFU)
#define MC_CGM_PCFS_DIVC7_RATE_SHIFT             (0U)
#define MC_CGM_PCFS_DIVC7_RATE_WIDTH             (8U)
#define MC_CGM_PCFS_DIVC7_RATE(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC7_RATE_SHIFT)) & MC_CGM_PCFS_DIVC7_RATE_MASK)

#define MC_CGM_PCFS_DIVC7_INIT_MASK              (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC7_INIT_SHIFT             (16U)
#define MC_CGM_PCFS_DIVC7_INIT_WIDTH             (16U)
#define MC_CGM_PCFS_DIVC7_INIT(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC7_INIT_SHIFT)) & MC_CGM_PCFS_DIVC7_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE7 - PCFS Divider End 7 */
/*! @{ */

#define MC_CGM_PCFS_DIVE7_DIVE_MASK              (0xFFFFFU)
#define MC_CGM_PCFS_DIVE7_DIVE_SHIFT             (0U)
#define MC_CGM_PCFS_DIVE7_DIVE_WIDTH             (20U)
#define MC_CGM_PCFS_DIVE7_DIVE(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE7_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE7_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS7 - PCFS Divider Start 7 */
/*! @{ */

#define MC_CGM_PCFS_DIVS7_DIVS_MASK              (0xFFFFFU)
#define MC_CGM_PCFS_DIVS7_DIVS_SHIFT             (0U)
#define MC_CGM_PCFS_DIVS7_DIVS_WIDTH             (20U)
#define MC_CGM_PCFS_DIVS7_DIVS(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS7_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS7_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC8 - PCFS Divider Change 8 */
/*! @{ */

#define MC_CGM_PCFS_DIVC8_RATE_MASK              (0xFFU)
#define MC_CGM_PCFS_DIVC8_RATE_SHIFT             (0U)
#define MC_CGM_PCFS_DIVC8_RATE_WIDTH             (8U)
#define MC_CGM_PCFS_DIVC8_RATE(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC8_RATE_SHIFT)) & MC_CGM_PCFS_DIVC8_RATE_MASK)

#define MC_CGM_PCFS_DIVC8_INIT_MASK              (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC8_INIT_SHIFT             (16U)
#define MC_CGM_PCFS_DIVC8_INIT_WIDTH             (16U)
#define MC_CGM_PCFS_DIVC8_INIT(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC8_INIT_SHIFT)) & MC_CGM_PCFS_DIVC8_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE8 - PCFS Divider End 8 */
/*! @{ */

#define MC_CGM_PCFS_DIVE8_DIVE_MASK              (0xFFFFFU)
#define MC_CGM_PCFS_DIVE8_DIVE_SHIFT             (0U)
#define MC_CGM_PCFS_DIVE8_DIVE_WIDTH             (20U)
#define MC_CGM_PCFS_DIVE8_DIVE(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE8_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE8_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS8 - PCFS Divider Start 8 */
/*! @{ */

#define MC_CGM_PCFS_DIVS8_DIVS_MASK              (0xFFFFFU)
#define MC_CGM_PCFS_DIVS8_DIVS_SHIFT             (0U)
#define MC_CGM_PCFS_DIVS8_DIVS_WIDTH             (20U)
#define MC_CGM_PCFS_DIVS8_DIVS(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS8_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS8_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC9 - PCFS Divider Change 9 */
/*! @{ */

#define MC_CGM_PCFS_DIVC9_RATE_MASK              (0xFFU)
#define MC_CGM_PCFS_DIVC9_RATE_SHIFT             (0U)
#define MC_CGM_PCFS_DIVC9_RATE_WIDTH             (8U)
#define MC_CGM_PCFS_DIVC9_RATE(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC9_RATE_SHIFT)) & MC_CGM_PCFS_DIVC9_RATE_MASK)

#define MC_CGM_PCFS_DIVC9_INIT_MASK              (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC9_INIT_SHIFT             (16U)
#define MC_CGM_PCFS_DIVC9_INIT_WIDTH             (16U)
#define MC_CGM_PCFS_DIVC9_INIT(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC9_INIT_SHIFT)) & MC_CGM_PCFS_DIVC9_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE9 - PCFS Divider End 9 */
/*! @{ */

#define MC_CGM_PCFS_DIVE9_DIVE_MASK              (0xFFFFFU)
#define MC_CGM_PCFS_DIVE9_DIVE_SHIFT             (0U)
#define MC_CGM_PCFS_DIVE9_DIVE_WIDTH             (20U)
#define MC_CGM_PCFS_DIVE9_DIVE(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE9_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE9_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS9 - PCFS Divider Start 9 */
/*! @{ */

#define MC_CGM_PCFS_DIVS9_DIVS_MASK              (0xFFFFFU)
#define MC_CGM_PCFS_DIVS9_DIVS_SHIFT             (0U)
#define MC_CGM_PCFS_DIVS9_DIVS_WIDTH             (20U)
#define MC_CGM_PCFS_DIVS9_DIVS(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS9_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS9_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC10 - PCFS Divider Change 10 */
/*! @{ */

#define MC_CGM_PCFS_DIVC10_RATE_MASK             (0xFFU)
#define MC_CGM_PCFS_DIVC10_RATE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVC10_RATE_WIDTH            (8U)
#define MC_CGM_PCFS_DIVC10_RATE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC10_RATE_SHIFT)) & MC_CGM_PCFS_DIVC10_RATE_MASK)

#define MC_CGM_PCFS_DIVC10_INIT_MASK             (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC10_INIT_SHIFT            (16U)
#define MC_CGM_PCFS_DIVC10_INIT_WIDTH            (16U)
#define MC_CGM_PCFS_DIVC10_INIT(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC10_INIT_SHIFT)) & MC_CGM_PCFS_DIVC10_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE10 - PCFS Divider End 10 */
/*! @{ */

#define MC_CGM_PCFS_DIVE10_DIVE_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVE10_DIVE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVE10_DIVE_WIDTH            (20U)
#define MC_CGM_PCFS_DIVE10_DIVE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE10_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE10_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS10 - PCFS Divider Start 10 */
/*! @{ */

#define MC_CGM_PCFS_DIVS10_DIVS_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVS10_DIVS_SHIFT            (0U)
#define MC_CGM_PCFS_DIVS10_DIVS_WIDTH            (20U)
#define MC_CGM_PCFS_DIVS10_DIVS(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS10_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS10_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC11 - PCFS Divider Change 11 */
/*! @{ */

#define MC_CGM_PCFS_DIVC11_RATE_MASK             (0xFFU)
#define MC_CGM_PCFS_DIVC11_RATE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVC11_RATE_WIDTH            (8U)
#define MC_CGM_PCFS_DIVC11_RATE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC11_RATE_SHIFT)) & MC_CGM_PCFS_DIVC11_RATE_MASK)

#define MC_CGM_PCFS_DIVC11_INIT_MASK             (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC11_INIT_SHIFT            (16U)
#define MC_CGM_PCFS_DIVC11_INIT_WIDTH            (16U)
#define MC_CGM_PCFS_DIVC11_INIT(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC11_INIT_SHIFT)) & MC_CGM_PCFS_DIVC11_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE11 - PCFS Divider End 11 */
/*! @{ */

#define MC_CGM_PCFS_DIVE11_DIVE_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVE11_DIVE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVE11_DIVE_WIDTH            (20U)
#define MC_CGM_PCFS_DIVE11_DIVE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE11_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE11_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS11 - PCFS Divider Start 11 */
/*! @{ */

#define MC_CGM_PCFS_DIVS11_DIVS_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVS11_DIVS_SHIFT            (0U)
#define MC_CGM_PCFS_DIVS11_DIVS_WIDTH            (20U)
#define MC_CGM_PCFS_DIVS11_DIVS(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS11_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS11_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC12 - PCFS Divider Change 12 */
/*! @{ */

#define MC_CGM_PCFS_DIVC12_RATE_MASK             (0xFFU)
#define MC_CGM_PCFS_DIVC12_RATE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVC12_RATE_WIDTH            (8U)
#define MC_CGM_PCFS_DIVC12_RATE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC12_RATE_SHIFT)) & MC_CGM_PCFS_DIVC12_RATE_MASK)

#define MC_CGM_PCFS_DIVC12_INIT_MASK             (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC12_INIT_SHIFT            (16U)
#define MC_CGM_PCFS_DIVC12_INIT_WIDTH            (16U)
#define MC_CGM_PCFS_DIVC12_INIT(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC12_INIT_SHIFT)) & MC_CGM_PCFS_DIVC12_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE12 - PCFS Divider End 12 */
/*! @{ */

#define MC_CGM_PCFS_DIVE12_DIVE_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVE12_DIVE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVE12_DIVE_WIDTH            (20U)
#define MC_CGM_PCFS_DIVE12_DIVE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE12_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE12_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS12 - PCFS Divider Start 12 */
/*! @{ */

#define MC_CGM_PCFS_DIVS12_DIVS_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVS12_DIVS_SHIFT            (0U)
#define MC_CGM_PCFS_DIVS12_DIVS_WIDTH            (20U)
#define MC_CGM_PCFS_DIVS12_DIVS(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS12_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS12_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC13 - PCFS Divider Change 13 */
/*! @{ */

#define MC_CGM_PCFS_DIVC13_RATE_MASK             (0xFFU)
#define MC_CGM_PCFS_DIVC13_RATE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVC13_RATE_WIDTH            (8U)
#define MC_CGM_PCFS_DIVC13_RATE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC13_RATE_SHIFT)) & MC_CGM_PCFS_DIVC13_RATE_MASK)

#define MC_CGM_PCFS_DIVC13_INIT_MASK             (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC13_INIT_SHIFT            (16U)
#define MC_CGM_PCFS_DIVC13_INIT_WIDTH            (16U)
#define MC_CGM_PCFS_DIVC13_INIT(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC13_INIT_SHIFT)) & MC_CGM_PCFS_DIVC13_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE13 - PCFS Divider End 13 */
/*! @{ */

#define MC_CGM_PCFS_DIVE13_DIVE_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVE13_DIVE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVE13_DIVE_WIDTH            (20U)
#define MC_CGM_PCFS_DIVE13_DIVE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE13_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE13_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS13 - PCFS Divider Start 13 */
/*! @{ */

#define MC_CGM_PCFS_DIVS13_DIVS_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVS13_DIVS_SHIFT            (0U)
#define MC_CGM_PCFS_DIVS13_DIVS_WIDTH            (20U)
#define MC_CGM_PCFS_DIVS13_DIVS(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS13_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS13_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC14 - PCFS Divider Change 14 */
/*! @{ */

#define MC_CGM_PCFS_DIVC14_RATE_MASK             (0xFFU)
#define MC_CGM_PCFS_DIVC14_RATE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVC14_RATE_WIDTH            (8U)
#define MC_CGM_PCFS_DIVC14_RATE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC14_RATE_SHIFT)) & MC_CGM_PCFS_DIVC14_RATE_MASK)

#define MC_CGM_PCFS_DIVC14_INIT_MASK             (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC14_INIT_SHIFT            (16U)
#define MC_CGM_PCFS_DIVC14_INIT_WIDTH            (16U)
#define MC_CGM_PCFS_DIVC14_INIT(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC14_INIT_SHIFT)) & MC_CGM_PCFS_DIVC14_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE14 - PCFS Divider End 14 */
/*! @{ */

#define MC_CGM_PCFS_DIVE14_DIVE_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVE14_DIVE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVE14_DIVE_WIDTH            (20U)
#define MC_CGM_PCFS_DIVE14_DIVE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE14_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE14_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS14 - PCFS Divider Start 14 */
/*! @{ */

#define MC_CGM_PCFS_DIVS14_DIVS_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVS14_DIVS_SHIFT            (0U)
#define MC_CGM_PCFS_DIVS14_DIVS_WIDTH            (20U)
#define MC_CGM_PCFS_DIVS14_DIVS(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS14_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS14_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC15 - PCFS Divider Change 15 */
/*! @{ */

#define MC_CGM_PCFS_DIVC15_RATE_MASK             (0xFFU)
#define MC_CGM_PCFS_DIVC15_RATE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVC15_RATE_WIDTH            (8U)
#define MC_CGM_PCFS_DIVC15_RATE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC15_RATE_SHIFT)) & MC_CGM_PCFS_DIVC15_RATE_MASK)

#define MC_CGM_PCFS_DIVC15_INIT_MASK             (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC15_INIT_SHIFT            (16U)
#define MC_CGM_PCFS_DIVC15_INIT_WIDTH            (16U)
#define MC_CGM_PCFS_DIVC15_INIT(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC15_INIT_SHIFT)) & MC_CGM_PCFS_DIVC15_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE15 - PCFS Divider End 15 */
/*! @{ */

#define MC_CGM_PCFS_DIVE15_DIVE_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVE15_DIVE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVE15_DIVE_WIDTH            (20U)
#define MC_CGM_PCFS_DIVE15_DIVE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE15_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE15_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS15 - PCFS Divider Start 15 */
/*! @{ */

#define MC_CGM_PCFS_DIVS15_DIVS_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVS15_DIVS_SHIFT            (0U)
#define MC_CGM_PCFS_DIVS15_DIVS_WIDTH            (20U)
#define MC_CGM_PCFS_DIVS15_DIVS(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS15_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS15_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC16 - PCFS Divider Change 16 */
/*! @{ */

#define MC_CGM_PCFS_DIVC16_RATE_MASK             (0xFFU)
#define MC_CGM_PCFS_DIVC16_RATE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVC16_RATE_WIDTH            (8U)
#define MC_CGM_PCFS_DIVC16_RATE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC16_RATE_SHIFT)) & MC_CGM_PCFS_DIVC16_RATE_MASK)

#define MC_CGM_PCFS_DIVC16_INIT_MASK             (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC16_INIT_SHIFT            (16U)
#define MC_CGM_PCFS_DIVC16_INIT_WIDTH            (16U)
#define MC_CGM_PCFS_DIVC16_INIT(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC16_INIT_SHIFT)) & MC_CGM_PCFS_DIVC16_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE16 - PCFS Divider End 16 */
/*! @{ */

#define MC_CGM_PCFS_DIVE16_DIVE_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVE16_DIVE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVE16_DIVE_WIDTH            (20U)
#define MC_CGM_PCFS_DIVE16_DIVE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE16_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE16_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS16 - PCFS Divider Start 16 */
/*! @{ */

#define MC_CGM_PCFS_DIVS16_DIVS_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVS16_DIVS_SHIFT            (0U)
#define MC_CGM_PCFS_DIVS16_DIVS_WIDTH            (20U)
#define MC_CGM_PCFS_DIVS16_DIVS(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS16_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS16_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC17 - PCFS Divider Change 17 */
/*! @{ */

#define MC_CGM_PCFS_DIVC17_RATE_MASK             (0xFFU)
#define MC_CGM_PCFS_DIVC17_RATE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVC17_RATE_WIDTH            (8U)
#define MC_CGM_PCFS_DIVC17_RATE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC17_RATE_SHIFT)) & MC_CGM_PCFS_DIVC17_RATE_MASK)

#define MC_CGM_PCFS_DIVC17_INIT_MASK             (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC17_INIT_SHIFT            (16U)
#define MC_CGM_PCFS_DIVC17_INIT_WIDTH            (16U)
#define MC_CGM_PCFS_DIVC17_INIT(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC17_INIT_SHIFT)) & MC_CGM_PCFS_DIVC17_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE17 - PCFS Divider End 17 */
/*! @{ */

#define MC_CGM_PCFS_DIVE17_DIVE_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVE17_DIVE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVE17_DIVE_WIDTH            (20U)
#define MC_CGM_PCFS_DIVE17_DIVE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE17_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE17_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS17 - PCFS Divider Start 17 */
/*! @{ */

#define MC_CGM_PCFS_DIVS17_DIVS_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVS17_DIVS_SHIFT            (0U)
#define MC_CGM_PCFS_DIVS17_DIVS_WIDTH            (20U)
#define MC_CGM_PCFS_DIVS17_DIVS(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS17_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS17_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC18 - PCFS Divider Change 18 */
/*! @{ */

#define MC_CGM_PCFS_DIVC18_RATE_MASK             (0xFFU)
#define MC_CGM_PCFS_DIVC18_RATE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVC18_RATE_WIDTH            (8U)
#define MC_CGM_PCFS_DIVC18_RATE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC18_RATE_SHIFT)) & MC_CGM_PCFS_DIVC18_RATE_MASK)

#define MC_CGM_PCFS_DIVC18_INIT_MASK             (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC18_INIT_SHIFT            (16U)
#define MC_CGM_PCFS_DIVC18_INIT_WIDTH            (16U)
#define MC_CGM_PCFS_DIVC18_INIT(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC18_INIT_SHIFT)) & MC_CGM_PCFS_DIVC18_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE18 - PCFS Divider End 18 */
/*! @{ */

#define MC_CGM_PCFS_DIVE18_DIVE_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVE18_DIVE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVE18_DIVE_WIDTH            (20U)
#define MC_CGM_PCFS_DIVE18_DIVE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE18_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE18_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS18 - PCFS Divider Start 18 */
/*! @{ */

#define MC_CGM_PCFS_DIVS18_DIVS_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVS18_DIVS_SHIFT            (0U)
#define MC_CGM_PCFS_DIVS18_DIVS_WIDTH            (20U)
#define MC_CGM_PCFS_DIVS18_DIVS(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS18_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS18_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC19 - PCFS Divider Change 19 */
/*! @{ */

#define MC_CGM_PCFS_DIVC19_RATE_MASK             (0xFFU)
#define MC_CGM_PCFS_DIVC19_RATE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVC19_RATE_WIDTH            (8U)
#define MC_CGM_PCFS_DIVC19_RATE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC19_RATE_SHIFT)) & MC_CGM_PCFS_DIVC19_RATE_MASK)

#define MC_CGM_PCFS_DIVC19_INIT_MASK             (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC19_INIT_SHIFT            (16U)
#define MC_CGM_PCFS_DIVC19_INIT_WIDTH            (16U)
#define MC_CGM_PCFS_DIVC19_INIT(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC19_INIT_SHIFT)) & MC_CGM_PCFS_DIVC19_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE19 - PCFS Divider End 19 */
/*! @{ */

#define MC_CGM_PCFS_DIVE19_DIVE_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVE19_DIVE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVE19_DIVE_WIDTH            (20U)
#define MC_CGM_PCFS_DIVE19_DIVE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE19_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE19_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS19 - PCFS Divider Start 19 */
/*! @{ */

#define MC_CGM_PCFS_DIVS19_DIVS_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVS19_DIVS_SHIFT            (0U)
#define MC_CGM_PCFS_DIVS19_DIVS_WIDTH            (20U)
#define MC_CGM_PCFS_DIVS19_DIVS(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS19_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS19_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC20 - PCFS Divider Change 20 */
/*! @{ */

#define MC_CGM_PCFS_DIVC20_RATE_MASK             (0xFFU)
#define MC_CGM_PCFS_DIVC20_RATE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVC20_RATE_WIDTH            (8U)
#define MC_CGM_PCFS_DIVC20_RATE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC20_RATE_SHIFT)) & MC_CGM_PCFS_DIVC20_RATE_MASK)

#define MC_CGM_PCFS_DIVC20_INIT_MASK             (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC20_INIT_SHIFT            (16U)
#define MC_CGM_PCFS_DIVC20_INIT_WIDTH            (16U)
#define MC_CGM_PCFS_DIVC20_INIT(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC20_INIT_SHIFT)) & MC_CGM_PCFS_DIVC20_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE20 - PCFS Divider End 20 */
/*! @{ */

#define MC_CGM_PCFS_DIVE20_DIVE_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVE20_DIVE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVE20_DIVE_WIDTH            (20U)
#define MC_CGM_PCFS_DIVE20_DIVE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE20_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE20_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS20 - PCFS Divider Start 20 */
/*! @{ */

#define MC_CGM_PCFS_DIVS20_DIVS_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVS20_DIVS_SHIFT            (0U)
#define MC_CGM_PCFS_DIVS20_DIVS_WIDTH            (20U)
#define MC_CGM_PCFS_DIVS20_DIVS(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS20_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS20_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC47 - PCFS Divider Change 47 */
/*! @{ */

#define MC_CGM_PCFS_DIVC47_RATE_MASK             (0xFFU)
#define MC_CGM_PCFS_DIVC47_RATE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVC47_RATE_WIDTH            (8U)
#define MC_CGM_PCFS_DIVC47_RATE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC47_RATE_SHIFT)) & MC_CGM_PCFS_DIVC47_RATE_MASK)

#define MC_CGM_PCFS_DIVC47_INIT_MASK             (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC47_INIT_SHIFT            (16U)
#define MC_CGM_PCFS_DIVC47_INIT_WIDTH            (16U)
#define MC_CGM_PCFS_DIVC47_INIT(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC47_INIT_SHIFT)) & MC_CGM_PCFS_DIVC47_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE47 - PCFS Divider End 47 */
/*! @{ */

#define MC_CGM_PCFS_DIVE47_DIVE_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVE47_DIVE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVE47_DIVE_WIDTH            (20U)
#define MC_CGM_PCFS_DIVE47_DIVE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE47_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE47_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS47 - PCFS Divider Start 47 */
/*! @{ */

#define MC_CGM_PCFS_DIVS47_DIVS_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVS47_DIVS_SHIFT            (0U)
#define MC_CGM_PCFS_DIVS47_DIVS_WIDTH            (20U)
#define MC_CGM_PCFS_DIVS47_DIVS(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS47_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS47_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC48 - PCFS Divider Change 48 */
/*! @{ */

#define MC_CGM_PCFS_DIVC48_RATE_MASK             (0xFFU)
#define MC_CGM_PCFS_DIVC48_RATE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVC48_RATE_WIDTH            (8U)
#define MC_CGM_PCFS_DIVC48_RATE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC48_RATE_SHIFT)) & MC_CGM_PCFS_DIVC48_RATE_MASK)

#define MC_CGM_PCFS_DIVC48_INIT_MASK             (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC48_INIT_SHIFT            (16U)
#define MC_CGM_PCFS_DIVC48_INIT_WIDTH            (16U)
#define MC_CGM_PCFS_DIVC48_INIT(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC48_INIT_SHIFT)) & MC_CGM_PCFS_DIVC48_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE48 - PCFS Divider End 48 */
/*! @{ */

#define MC_CGM_PCFS_DIVE48_DIVE_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVE48_DIVE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVE48_DIVE_WIDTH            (20U)
#define MC_CGM_PCFS_DIVE48_DIVE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE48_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE48_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS48 - PCFS Divider Start 48 */
/*! @{ */

#define MC_CGM_PCFS_DIVS48_DIVS_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVS48_DIVS_SHIFT            (0U)
#define MC_CGM_PCFS_DIVS48_DIVS_WIDTH            (20U)
#define MC_CGM_PCFS_DIVS48_DIVS(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS48_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS48_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC49 - PCFS Divider Change 49 */
/*! @{ */

#define MC_CGM_PCFS_DIVC49_RATE_MASK             (0xFFU)
#define MC_CGM_PCFS_DIVC49_RATE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVC49_RATE_WIDTH            (8U)
#define MC_CGM_PCFS_DIVC49_RATE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC49_RATE_SHIFT)) & MC_CGM_PCFS_DIVC49_RATE_MASK)

#define MC_CGM_PCFS_DIVC49_INIT_MASK             (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC49_INIT_SHIFT            (16U)
#define MC_CGM_PCFS_DIVC49_INIT_WIDTH            (16U)
#define MC_CGM_PCFS_DIVC49_INIT(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC49_INIT_SHIFT)) & MC_CGM_PCFS_DIVC49_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE49 - PCFS Divider End 49 */
/*! @{ */

#define MC_CGM_PCFS_DIVE49_DIVE_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVE49_DIVE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVE49_DIVE_WIDTH            (20U)
#define MC_CGM_PCFS_DIVE49_DIVE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE49_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE49_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS49 - PCFS Divider Start 49 */
/*! @{ */

#define MC_CGM_PCFS_DIVS49_DIVS_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVS49_DIVS_SHIFT            (0U)
#define MC_CGM_PCFS_DIVS49_DIVS_WIDTH            (20U)
#define MC_CGM_PCFS_DIVS49_DIVS(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS49_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS49_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC50 - PCFS Divider Change 50 */
/*! @{ */

#define MC_CGM_PCFS_DIVC50_RATE_MASK             (0xFFU)
#define MC_CGM_PCFS_DIVC50_RATE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVC50_RATE_WIDTH            (8U)
#define MC_CGM_PCFS_DIVC50_RATE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC50_RATE_SHIFT)) & MC_CGM_PCFS_DIVC50_RATE_MASK)

#define MC_CGM_PCFS_DIVC50_INIT_MASK             (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC50_INIT_SHIFT            (16U)
#define MC_CGM_PCFS_DIVC50_INIT_WIDTH            (16U)
#define MC_CGM_PCFS_DIVC50_INIT(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC50_INIT_SHIFT)) & MC_CGM_PCFS_DIVC50_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE50 - PCFS Divider End 50 */
/*! @{ */

#define MC_CGM_PCFS_DIVE50_DIVE_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVE50_DIVE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVE50_DIVE_WIDTH            (20U)
#define MC_CGM_PCFS_DIVE50_DIVE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE50_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE50_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS50 - PCFS Divider Start 50 */
/*! @{ */

#define MC_CGM_PCFS_DIVS50_DIVS_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVS50_DIVS_SHIFT            (0U)
#define MC_CGM_PCFS_DIVS50_DIVS_WIDTH            (20U)
#define MC_CGM_PCFS_DIVS50_DIVS(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS50_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS50_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC51 - PCFS Divider Change 51 */
/*! @{ */

#define MC_CGM_PCFS_DIVC51_RATE_MASK             (0xFFU)
#define MC_CGM_PCFS_DIVC51_RATE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVC51_RATE_WIDTH            (8U)
#define MC_CGM_PCFS_DIVC51_RATE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC51_RATE_SHIFT)) & MC_CGM_PCFS_DIVC51_RATE_MASK)

#define MC_CGM_PCFS_DIVC51_INIT_MASK             (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC51_INIT_SHIFT            (16U)
#define MC_CGM_PCFS_DIVC51_INIT_WIDTH            (16U)
#define MC_CGM_PCFS_DIVC51_INIT(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC51_INIT_SHIFT)) & MC_CGM_PCFS_DIVC51_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE51 - PCFS Divider End 51 */
/*! @{ */

#define MC_CGM_PCFS_DIVE51_DIVE_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVE51_DIVE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVE51_DIVE_WIDTH            (20U)
#define MC_CGM_PCFS_DIVE51_DIVE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE51_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE51_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS51 - PCFS Divider Start 51 */
/*! @{ */

#define MC_CGM_PCFS_DIVS51_DIVS_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVS51_DIVS_SHIFT            (0U)
#define MC_CGM_PCFS_DIVS51_DIVS_WIDTH            (20U)
#define MC_CGM_PCFS_DIVS51_DIVS(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS51_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS51_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC52 - PCFS Divider Change 52 */
/*! @{ */

#define MC_CGM_PCFS_DIVC52_RATE_MASK             (0xFFU)
#define MC_CGM_PCFS_DIVC52_RATE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVC52_RATE_WIDTH            (8U)
#define MC_CGM_PCFS_DIVC52_RATE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC52_RATE_SHIFT)) & MC_CGM_PCFS_DIVC52_RATE_MASK)

#define MC_CGM_PCFS_DIVC52_INIT_MASK             (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC52_INIT_SHIFT            (16U)
#define MC_CGM_PCFS_DIVC52_INIT_WIDTH            (16U)
#define MC_CGM_PCFS_DIVC52_INIT(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC52_INIT_SHIFT)) & MC_CGM_PCFS_DIVC52_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE52 - PCFS Divider End 52 */
/*! @{ */

#define MC_CGM_PCFS_DIVE52_DIVE_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVE52_DIVE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVE52_DIVE_WIDTH            (20U)
#define MC_CGM_PCFS_DIVE52_DIVE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE52_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE52_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS52 - PCFS Divider Start 52 */
/*! @{ */

#define MC_CGM_PCFS_DIVS52_DIVS_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVS52_DIVS_SHIFT            (0U)
#define MC_CGM_PCFS_DIVS52_DIVS_WIDTH            (20U)
#define MC_CGM_PCFS_DIVS52_DIVS(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS52_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS52_DIVS_MASK)
/*! @} */

/*! @name PCFS_DIVC63 - PCFS Divider Change 63 */
/*! @{ */

#define MC_CGM_PCFS_DIVC63_RATE_MASK             (0xFFU)
#define MC_CGM_PCFS_DIVC63_RATE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVC63_RATE_WIDTH            (8U)
#define MC_CGM_PCFS_DIVC63_RATE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC63_RATE_SHIFT)) & MC_CGM_PCFS_DIVC63_RATE_MASK)

#define MC_CGM_PCFS_DIVC63_INIT_MASK             (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC63_INIT_SHIFT            (16U)
#define MC_CGM_PCFS_DIVC63_INIT_WIDTH            (16U)
#define MC_CGM_PCFS_DIVC63_INIT(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC63_INIT_SHIFT)) & MC_CGM_PCFS_DIVC63_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE63 - PCFS Divider End 63 */
/*! @{ */

#define MC_CGM_PCFS_DIVE63_DIVE_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVE63_DIVE_SHIFT            (0U)
#define MC_CGM_PCFS_DIVE63_DIVE_WIDTH            (20U)
#define MC_CGM_PCFS_DIVE63_DIVE(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE63_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE63_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS63 - PCFS Divider Start 63 */
/*! @{ */

#define MC_CGM_PCFS_DIVS63_DIVS_MASK             (0xFFFFFU)
#define MC_CGM_PCFS_DIVS63_DIVS_SHIFT            (0U)
#define MC_CGM_PCFS_DIVS63_DIVS_WIDTH            (20U)
#define MC_CGM_PCFS_DIVS63_DIVS(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS63_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS63_DIVS_MASK)
/*! @} */

/*! @name SLC_0_CSC - Clock Slice 0 Select Control */
/*! @{ */

#define MC_CGM_SLC_0_CSC_RMP_SW_MASK             (0x2U)
#define MC_CGM_SLC_0_CSC_RMP_SW_SHIFT            (1U)
#define MC_CGM_SLC_0_CSC_RMP_SW_WIDTH            (1U)
#define MC_CGM_SLC_0_CSC_RMP_SW(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_0_CSC_RMP_SW_SHIFT)) & MC_CGM_SLC_0_CSC_RMP_SW_MASK)

#define MC_CGM_SLC_0_CSC_CLK_SW_MASK             (0x4U)
#define MC_CGM_SLC_0_CSC_CLK_SW_SHIFT            (2U)
#define MC_CGM_SLC_0_CSC_CLK_SW_WIDTH            (1U)
#define MC_CGM_SLC_0_CSC_CLK_SW(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_0_CSC_CLK_SW_SHIFT)) & MC_CGM_SLC_0_CSC_CLK_SW_MASK)

#define MC_CGM_SLC_0_CSC_SAFE_SW_MASK            (0x8U)
#define MC_CGM_SLC_0_CSC_SAFE_SW_SHIFT           (3U)
#define MC_CGM_SLC_0_CSC_SAFE_SW_WIDTH           (1U)
#define MC_CGM_SLC_0_CSC_SAFE_SW(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_0_CSC_SAFE_SW_SHIFT)) & MC_CGM_SLC_0_CSC_SAFE_SW_MASK)

#define MC_CGM_SLC_0_CSC_SELCTL_MASK             (0x3F000000U)
#define MC_CGM_SLC_0_CSC_SELCTL_SHIFT            (24U)
#define MC_CGM_SLC_0_CSC_SELCTL_WIDTH            (6U)
#define MC_CGM_SLC_0_CSC_SELCTL(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_0_CSC_SELCTL_SHIFT)) & MC_CGM_SLC_0_CSC_SELCTL_MASK)
/*! @} */

/*! @name SLC_0_CSS - Clock Slice 0 Select Status */
/*! @{ */

#define MC_CGM_SLC_0_CSS_SWIP_MASK               (0x4U)
#define MC_CGM_SLC_0_CSS_SWIP_SHIFT              (2U)
#define MC_CGM_SLC_0_CSS_SWIP_WIDTH              (1U)
#define MC_CGM_SLC_0_CSS_SWIP(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_0_CSS_SWIP_SHIFT)) & MC_CGM_SLC_0_CSS_SWIP_MASK)

#define MC_CGM_SLC_0_CSS_SAFESWIP_MASK           (0x8U)
#define MC_CGM_SLC_0_CSS_SAFESWIP_SHIFT          (3U)
#define MC_CGM_SLC_0_CSS_SAFESWIP_WIDTH          (1U)
#define MC_CGM_SLC_0_CSS_SAFESWIP(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_0_CSS_SAFESWIP_SHIFT)) & MC_CGM_SLC_0_CSS_SAFESWIP_MASK)

#define MC_CGM_SLC_0_CSS_SWTRG_MASK              (0x70000U)
#define MC_CGM_SLC_0_CSS_SWTRG_SHIFT             (16U)
#define MC_CGM_SLC_0_CSS_SWTRG_WIDTH             (3U)
#define MC_CGM_SLC_0_CSS_SWTRG(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_0_CSS_SWTRG_SHIFT)) & MC_CGM_SLC_0_CSS_SWTRG_MASK)

#define MC_CGM_SLC_0_CSS_SELSTAT_MASK            (0x3F000000U)
#define MC_CGM_SLC_0_CSS_SELSTAT_SHIFT           (24U)
#define MC_CGM_SLC_0_CSS_SELSTAT_WIDTH           (6U)
#define MC_CGM_SLC_0_CSS_SELSTAT(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_0_CSS_SELSTAT_SHIFT)) & MC_CGM_SLC_0_CSS_SELSTAT_MASK)
/*! @} */

/*! @name SLC_0_DC_0 - Clock Slice 0 Divider 0 Control */
/*! @{ */

#define MC_CGM_SLC_0_DC_0_DIV_MASK               (0xFF0000U)  /* Merged from fields with different position or width, of widths (1, 2, 8), largest definition used */
#define MC_CGM_SLC_0_DC_0_DIV_SHIFT              (16U)
#define MC_CGM_SLC_0_DC_0_DIV_WIDTH              (8U)
#define MC_CGM_SLC_0_DC_0_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_0_DC_0_DIV_SHIFT)) & MC_CGM_SLC_0_DC_0_DIV_MASK)  /* Merged from fields with different position or width, of widths (1, 2, 8), largest definition used */

#define MC_CGM_SLC_0_DC_0_DE_MASK                (0x80000000U)
#define MC_CGM_SLC_0_DC_0_DE_SHIFT               (31U)
#define MC_CGM_SLC_0_DC_0_DE_WIDTH               (1U)
#define MC_CGM_SLC_0_DC_0_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_0_DC_0_DE_SHIFT)) & MC_CGM_SLC_0_DC_0_DE_MASK)
/*! @} */

/*! @name SLC_0_DC_1 - Clock Slice 0 Divider 1 Control */
/*! @{ */

#define MC_CGM_SLC_0_DC_1_DIV_MASK               (0xFF0000U)  /* Merged from fields with different position or width, of widths (1, 8), largest definition used */
#define MC_CGM_SLC_0_DC_1_DIV_SHIFT              (16U)
#define MC_CGM_SLC_0_DC_1_DIV_WIDTH              (8U)
#define MC_CGM_SLC_0_DC_1_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_0_DC_1_DIV_SHIFT)) & MC_CGM_SLC_0_DC_1_DIV_MASK)  /* Merged from fields with different position or width, of widths (1, 8), largest definition used */

#define MC_CGM_SLC_0_DC_1_DE_MASK                (0x80000000U)
#define MC_CGM_SLC_0_DC_1_DE_SHIFT               (31U)
#define MC_CGM_SLC_0_DC_1_DE_WIDTH               (1U)
#define MC_CGM_SLC_0_DC_1_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_0_DC_1_DE_SHIFT)) & MC_CGM_SLC_0_DC_1_DE_MASK)
/*! @} */

/*! @name SLC_0_DC_2 - Clock Slice 0 Divider 2 Control */
/*! @{ */

#define MC_CGM_SLC_0_DC_2_DIV_MASK               (0xFF0000U)  /* Merged from fields with different position or width, of widths (2, 8), largest definition used */
#define MC_CGM_SLC_0_DC_2_DIV_SHIFT              (16U)
#define MC_CGM_SLC_0_DC_2_DIV_WIDTH              (8U)
#define MC_CGM_SLC_0_DC_2_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_0_DC_2_DIV_SHIFT)) & MC_CGM_SLC_0_DC_2_DIV_MASK)  /* Merged from fields with different position or width, of widths (2, 8), largest definition used */

#define MC_CGM_SLC_0_DC_2_DE_MASK                (0x80000000U)
#define MC_CGM_SLC_0_DC_2_DE_SHIFT               (31U)
#define MC_CGM_SLC_0_DC_2_DE_WIDTH               (1U)
#define MC_CGM_SLC_0_DC_2_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_0_DC_2_DE_SHIFT)) & MC_CGM_SLC_0_DC_2_DE_MASK)
/*! @} */

/*! @name SLC_0_DC_3 - Clock Slice 0 Divider 3 Control */
/*! @{ */

#define MC_CGM_SLC_0_DC_3_DIV_MASK               (0xFF0000U)  /* Merged from fields with different position or width, of widths (3, 8), largest definition used */
#define MC_CGM_SLC_0_DC_3_DIV_SHIFT              (16U)
#define MC_CGM_SLC_0_DC_3_DIV_WIDTH              (8U)
#define MC_CGM_SLC_0_DC_3_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_0_DC_3_DIV_SHIFT)) & MC_CGM_SLC_0_DC_3_DIV_MASK)  /* Merged from fields with different position or width, of widths (3, 8), largest definition used */

#define MC_CGM_SLC_0_DC_3_DE_MASK                (0x80000000U)
#define MC_CGM_SLC_0_DC_3_DE_SHIFT               (31U)
#define MC_CGM_SLC_0_DC_3_DE_WIDTH               (1U)
#define MC_CGM_SLC_0_DC_3_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_0_DC_3_DE_SHIFT)) & MC_CGM_SLC_0_DC_3_DE_MASK)
/*! @} */

/*! @name SLC_0_DIV_TRIG_CTRL - Clock Slice 0 Divider Trigger Control */
/*! @{ */

#define MC_CGM_SLC_0_DIV_TRIG_CTRL_TCTL_MASK     (0x1U)
#define MC_CGM_SLC_0_DIV_TRIG_CTRL_TCTL_SHIFT    (0U)
#define MC_CGM_SLC_0_DIV_TRIG_CTRL_TCTL_WIDTH    (1U)
#define MC_CGM_SLC_0_DIV_TRIG_CTRL_TCTL(x)       (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_0_DIV_TRIG_CTRL_TCTL_SHIFT)) & MC_CGM_SLC_0_DIV_TRIG_CTRL_TCTL_MASK)

#define MC_CGM_SLC_0_DIV_TRIG_CTRL_IRE_MASK      (0x10000U)
#define MC_CGM_SLC_0_DIV_TRIG_CTRL_IRE_SHIFT     (16U)
#define MC_CGM_SLC_0_DIV_TRIG_CTRL_IRE_WIDTH     (1U)
#define MC_CGM_SLC_0_DIV_TRIG_CTRL_IRE(x)        (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_0_DIV_TRIG_CTRL_IRE_SHIFT)) & MC_CGM_SLC_0_DIV_TRIG_CTRL_IRE_MASK)

#define MC_CGM_SLC_0_DIV_TRIG_CTRL_HHEN_MASK     (0x80000000U)
#define MC_CGM_SLC_0_DIV_TRIG_CTRL_HHEN_SHIFT    (31U)
#define MC_CGM_SLC_0_DIV_TRIG_CTRL_HHEN_WIDTH    (1U)
#define MC_CGM_SLC_0_DIV_TRIG_CTRL_HHEN(x)       (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_0_DIV_TRIG_CTRL_HHEN_SHIFT)) & MC_CGM_SLC_0_DIV_TRIG_CTRL_HHEN_MASK)
/*! @} */

/*! @name SLC_0_DIV_TRIG - Clock Slice 0 Divider Trigger */
/*! @{ */

#define MC_CGM_SLC_0_DIV_TRIG_TRIGGER_MASK       (0xFFFFFFFFU)
#define MC_CGM_SLC_0_DIV_TRIG_TRIGGER_SHIFT      (0U)
#define MC_CGM_SLC_0_DIV_TRIG_TRIGGER_WIDTH      (32U)
#define MC_CGM_SLC_0_DIV_TRIG_TRIGGER(x)         (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_0_DIV_TRIG_TRIGGER_SHIFT)) & MC_CGM_SLC_0_DIV_TRIG_TRIGGER_MASK)
/*! @} */

/*! @name SLC_0_DIV_UPD_STAT - Clock Slice 0 Divider Update Status */
/*! @{ */

#define MC_CGM_SLC_0_DIV_UPD_STAT_DIV_STAT_MASK  (0x1U)
#define MC_CGM_SLC_0_DIV_UPD_STAT_DIV_STAT_SHIFT (0U)
#define MC_CGM_SLC_0_DIV_UPD_STAT_DIV_STAT_WIDTH (1U)
#define MC_CGM_SLC_0_DIV_UPD_STAT_DIV_STAT(x)    (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_0_DIV_UPD_STAT_DIV_STAT_SHIFT)) & MC_CGM_SLC_0_DIV_UPD_STAT_DIV_STAT_MASK)
/*! @} */

/*! @name SLC_1_CSC - Clock Slice 1 Select Control */
/*! @{ */

#define MC_CGM_SLC_1_CSC_CLK_SW_MASK             (0x4U)
#define MC_CGM_SLC_1_CSC_CLK_SW_SHIFT            (2U)
#define MC_CGM_SLC_1_CSC_CLK_SW_WIDTH            (1U)
#define MC_CGM_SLC_1_CSC_CLK_SW(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_1_CSC_CLK_SW_SHIFT)) & MC_CGM_SLC_1_CSC_CLK_SW_MASK)

#define MC_CGM_SLC_1_CSC_SAFE_SW_MASK            (0x8U)
#define MC_CGM_SLC_1_CSC_SAFE_SW_SHIFT           (3U)
#define MC_CGM_SLC_1_CSC_SAFE_SW_WIDTH           (1U)
#define MC_CGM_SLC_1_CSC_SAFE_SW(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_1_CSC_SAFE_SW_SHIFT)) & MC_CGM_SLC_1_CSC_SAFE_SW_MASK)

#define MC_CGM_SLC_1_CSC_SELCTL_MASK             (0x3F000000U)
#define MC_CGM_SLC_1_CSC_SELCTL_SHIFT            (24U)
#define MC_CGM_SLC_1_CSC_SELCTL_WIDTH            (6U)
#define MC_CGM_SLC_1_CSC_SELCTL(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_1_CSC_SELCTL_SHIFT)) & MC_CGM_SLC_1_CSC_SELCTL_MASK)
/*! @} */

/*! @name SLC_1_CSS - Clock Slice 1 Select Status */
/*! @{ */

#define MC_CGM_SLC_1_CSS_SWIP_MASK               (0x4U)
#define MC_CGM_SLC_1_CSS_SWIP_SHIFT              (2U)
#define MC_CGM_SLC_1_CSS_SWIP_WIDTH              (1U)
#define MC_CGM_SLC_1_CSS_SWIP(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_1_CSS_SWIP_SHIFT)) & MC_CGM_SLC_1_CSS_SWIP_MASK)

#define MC_CGM_SLC_1_CSS_SAFESWIP_MASK           (0x8U)
#define MC_CGM_SLC_1_CSS_SAFESWIP_SHIFT          (3U)
#define MC_CGM_SLC_1_CSS_SAFESWIP_WIDTH          (1U)
#define MC_CGM_SLC_1_CSS_SAFESWIP(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_1_CSS_SAFESWIP_SHIFT)) & MC_CGM_SLC_1_CSS_SAFESWIP_MASK)

#define MC_CGM_SLC_1_CSS_SWTRG_MASK              (0x70000U)
#define MC_CGM_SLC_1_CSS_SWTRG_SHIFT             (16U)
#define MC_CGM_SLC_1_CSS_SWTRG_WIDTH             (3U)
#define MC_CGM_SLC_1_CSS_SWTRG(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_1_CSS_SWTRG_SHIFT)) & MC_CGM_SLC_1_CSS_SWTRG_MASK)

#define MC_CGM_SLC_1_CSS_SELSTAT_MASK            (0x3F000000U)
#define MC_CGM_SLC_1_CSS_SELSTAT_SHIFT           (24U)
#define MC_CGM_SLC_1_CSS_SELSTAT_WIDTH           (6U)
#define MC_CGM_SLC_1_CSS_SELSTAT(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_1_CSS_SELSTAT_SHIFT)) & MC_CGM_SLC_1_CSS_SELSTAT_MASK)
/*! @} */

/*! @name SLC_1_DC_0 - Clock Slice 1 Divider 0 Control */
/*! @{ */

#define MC_CGM_SLC_1_DC_0_DIV_MASK               (0xFF0000U)  /* Merged from fields with different position or width, of widths (3, 4, 5, 8), largest definition used */
#define MC_CGM_SLC_1_DC_0_DIV_SHIFT              (16U)
#define MC_CGM_SLC_1_DC_0_DIV_WIDTH              (8U)
#define MC_CGM_SLC_1_DC_0_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_1_DC_0_DIV_SHIFT)) & MC_CGM_SLC_1_DC_0_DIV_MASK)  /* Merged from fields with different position or width, of widths (3, 4, 5, 8), largest definition used */

#define MC_CGM_SLC_1_DC_0_DE_MASK                (0x80000000U)
#define MC_CGM_SLC_1_DC_0_DE_SHIFT               (31U)
#define MC_CGM_SLC_1_DC_0_DE_WIDTH               (1U)
#define MC_CGM_SLC_1_DC_0_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_1_DC_0_DE_SHIFT)) & MC_CGM_SLC_1_DC_0_DE_MASK)
/*! @} */

/*! @name SLC_1_DIV_UPD_STAT - Clock Slice 1 Divider Update Status */
/*! @{ */

#define MC_CGM_SLC_1_DIV_UPD_STAT_DIV_STAT_MASK  (0x1U)
#define MC_CGM_SLC_1_DIV_UPD_STAT_DIV_STAT_SHIFT (0U)
#define MC_CGM_SLC_1_DIV_UPD_STAT_DIV_STAT_WIDTH (1U)
#define MC_CGM_SLC_1_DIV_UPD_STAT_DIV_STAT(x)    (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_1_DIV_UPD_STAT_DIV_STAT_SHIFT)) & MC_CGM_SLC_1_DIV_UPD_STAT_DIV_STAT_MASK)
/*! @} */

/*! @name SLC_2_CSC - Clock Slice 2 Select Control */
/*! @{ */

#define MC_CGM_SLC_2_CSC_CLK_SW_MASK             (0x4U)
#define MC_CGM_SLC_2_CSC_CLK_SW_SHIFT            (2U)
#define MC_CGM_SLC_2_CSC_CLK_SW_WIDTH            (1U)
#define MC_CGM_SLC_2_CSC_CLK_SW(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_2_CSC_CLK_SW_SHIFT)) & MC_CGM_SLC_2_CSC_CLK_SW_MASK)

#define MC_CGM_SLC_2_CSC_SAFE_SW_MASK            (0x8U)
#define MC_CGM_SLC_2_CSC_SAFE_SW_SHIFT           (3U)
#define MC_CGM_SLC_2_CSC_SAFE_SW_WIDTH           (1U)
#define MC_CGM_SLC_2_CSC_SAFE_SW(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_2_CSC_SAFE_SW_SHIFT)) & MC_CGM_SLC_2_CSC_SAFE_SW_MASK)

#define MC_CGM_SLC_2_CSC_SELCTL_MASK             (0x3F000000U)
#define MC_CGM_SLC_2_CSC_SELCTL_SHIFT            (24U)
#define MC_CGM_SLC_2_CSC_SELCTL_WIDTH            (6U)
#define MC_CGM_SLC_2_CSC_SELCTL(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_2_CSC_SELCTL_SHIFT)) & MC_CGM_SLC_2_CSC_SELCTL_MASK)
/*! @} */

/*! @name SLC_2_CSS - Clock Slice 2 Select Status */
/*! @{ */

#define MC_CGM_SLC_2_CSS_SWIP_MASK               (0x4U)
#define MC_CGM_SLC_2_CSS_SWIP_SHIFT              (2U)
#define MC_CGM_SLC_2_CSS_SWIP_WIDTH              (1U)
#define MC_CGM_SLC_2_CSS_SWIP(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_2_CSS_SWIP_SHIFT)) & MC_CGM_SLC_2_CSS_SWIP_MASK)

#define MC_CGM_SLC_2_CSS_SAFESWIP_MASK           (0x8U)
#define MC_CGM_SLC_2_CSS_SAFESWIP_SHIFT          (3U)
#define MC_CGM_SLC_2_CSS_SAFESWIP_WIDTH          (1U)
#define MC_CGM_SLC_2_CSS_SAFESWIP(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_2_CSS_SAFESWIP_SHIFT)) & MC_CGM_SLC_2_CSS_SAFESWIP_MASK)

#define MC_CGM_SLC_2_CSS_SWTRG_MASK              (0x70000U)
#define MC_CGM_SLC_2_CSS_SWTRG_SHIFT             (16U)
#define MC_CGM_SLC_2_CSS_SWTRG_WIDTH             (3U)
#define MC_CGM_SLC_2_CSS_SWTRG(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_2_CSS_SWTRG_SHIFT)) & MC_CGM_SLC_2_CSS_SWTRG_MASK)

#define MC_CGM_SLC_2_CSS_SELSTAT_MASK            (0x3F000000U)
#define MC_CGM_SLC_2_CSS_SELSTAT_SHIFT           (24U)
#define MC_CGM_SLC_2_CSS_SELSTAT_WIDTH           (6U)
#define MC_CGM_SLC_2_CSS_SELSTAT(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_2_CSS_SELSTAT_SHIFT)) & MC_CGM_SLC_2_CSS_SELSTAT_MASK)
/*! @} */

/*! @name SLC_2_DC_0 - Clock Slice 2 Divider 0 Control */
/*! @{ */

#define MC_CGM_SLC_2_DC_0_DIV_MASK               (0xFF0000U)  /* Merged from fields with different position or width, of widths (2, 3, 8), largest definition used */
#define MC_CGM_SLC_2_DC_0_DIV_SHIFT              (16U)
#define MC_CGM_SLC_2_DC_0_DIV_WIDTH              (8U)
#define MC_CGM_SLC_2_DC_0_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_2_DC_0_DIV_SHIFT)) & MC_CGM_SLC_2_DC_0_DIV_MASK)  /* Merged from fields with different position or width, of widths (2, 3, 8), largest definition used */

#define MC_CGM_SLC_2_DC_0_DE_MASK                (0x80000000U)
#define MC_CGM_SLC_2_DC_0_DE_SHIFT               (31U)
#define MC_CGM_SLC_2_DC_0_DE_WIDTH               (1U)
#define MC_CGM_SLC_2_DC_0_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_2_DC_0_DE_SHIFT)) & MC_CGM_SLC_2_DC_0_DE_MASK)
/*! @} */

/*! @name SLC_2_DIV_UPD_STAT - Clock Slice 2 Divider Update Status */
/*! @{ */

#define MC_CGM_SLC_2_DIV_UPD_STAT_DIV_STAT_MASK  (0x1U)
#define MC_CGM_SLC_2_DIV_UPD_STAT_DIV_STAT_SHIFT (0U)
#define MC_CGM_SLC_2_DIV_UPD_STAT_DIV_STAT_WIDTH (1U)
#define MC_CGM_SLC_2_DIV_UPD_STAT_DIV_STAT(x)    (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_2_DIV_UPD_STAT_DIV_STAT_SHIFT)) & MC_CGM_SLC_2_DIV_UPD_STAT_DIV_STAT_MASK)
/*! @} */

/*! @name SLC_3_CSC - Clock Slice 3 Select Control */
/*! @{ */

#define MC_CGM_SLC_3_CSC_CLK_SW_MASK             (0x4U)
#define MC_CGM_SLC_3_CSC_CLK_SW_SHIFT            (2U)
#define MC_CGM_SLC_3_CSC_CLK_SW_WIDTH            (1U)
#define MC_CGM_SLC_3_CSC_CLK_SW(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_3_CSC_CLK_SW_SHIFT)) & MC_CGM_SLC_3_CSC_CLK_SW_MASK)

#define MC_CGM_SLC_3_CSC_SAFE_SW_MASK            (0x8U)
#define MC_CGM_SLC_3_CSC_SAFE_SW_SHIFT           (3U)
#define MC_CGM_SLC_3_CSC_SAFE_SW_WIDTH           (1U)
#define MC_CGM_SLC_3_CSC_SAFE_SW(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_3_CSC_SAFE_SW_SHIFT)) & MC_CGM_SLC_3_CSC_SAFE_SW_MASK)

#define MC_CGM_SLC_3_CSC_SELCTL_MASK             (0x3F000000U)
#define MC_CGM_SLC_3_CSC_SELCTL_SHIFT            (24U)
#define MC_CGM_SLC_3_CSC_SELCTL_WIDTH            (6U)
#define MC_CGM_SLC_3_CSC_SELCTL(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_3_CSC_SELCTL_SHIFT)) & MC_CGM_SLC_3_CSC_SELCTL_MASK)
/*! @} */

/*! @name SLC_3_CSS - Clock Slice 3 Select Status */
/*! @{ */

#define MC_CGM_SLC_3_CSS_SWIP_MASK               (0x4U)
#define MC_CGM_SLC_3_CSS_SWIP_SHIFT              (2U)
#define MC_CGM_SLC_3_CSS_SWIP_WIDTH              (1U)
#define MC_CGM_SLC_3_CSS_SWIP(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_3_CSS_SWIP_SHIFT)) & MC_CGM_SLC_3_CSS_SWIP_MASK)

#define MC_CGM_SLC_3_CSS_SAFESWIP_MASK           (0x8U)
#define MC_CGM_SLC_3_CSS_SAFESWIP_SHIFT          (3U)
#define MC_CGM_SLC_3_CSS_SAFESWIP_WIDTH          (1U)
#define MC_CGM_SLC_3_CSS_SAFESWIP(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_3_CSS_SAFESWIP_SHIFT)) & MC_CGM_SLC_3_CSS_SAFESWIP_MASK)

#define MC_CGM_SLC_3_CSS_SWTRG_MASK              (0x70000U)
#define MC_CGM_SLC_3_CSS_SWTRG_SHIFT             (16U)
#define MC_CGM_SLC_3_CSS_SWTRG_WIDTH             (3U)
#define MC_CGM_SLC_3_CSS_SWTRG(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_3_CSS_SWTRG_SHIFT)) & MC_CGM_SLC_3_CSS_SWTRG_MASK)

#define MC_CGM_SLC_3_CSS_SELSTAT_MASK            (0x3F000000U)
#define MC_CGM_SLC_3_CSS_SELSTAT_SHIFT           (24U)
#define MC_CGM_SLC_3_CSS_SELSTAT_WIDTH           (6U)
#define MC_CGM_SLC_3_CSS_SELSTAT(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_3_CSS_SELSTAT_SHIFT)) & MC_CGM_SLC_3_CSS_SELSTAT_MASK)
/*! @} */

/*! @name SLC_3_DC_0 - Clock Slice 3 Divider 0 Control */
/*! @{ */

#define MC_CGM_SLC_3_DC_0_DIV_MASK               (0xFF0000U)  /* Merged from fields with different position or width, of widths (3, 4, 8), largest definition used */
#define MC_CGM_SLC_3_DC_0_DIV_SHIFT              (16U)
#define MC_CGM_SLC_3_DC_0_DIV_WIDTH              (8U)
#define MC_CGM_SLC_3_DC_0_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_3_DC_0_DIV_SHIFT)) & MC_CGM_SLC_3_DC_0_DIV_MASK)  /* Merged from fields with different position or width, of widths (3, 4, 8), largest definition used */

#define MC_CGM_SLC_3_DC_0_DE_MASK                (0x80000000U)
#define MC_CGM_SLC_3_DC_0_DE_SHIFT               (31U)
#define MC_CGM_SLC_3_DC_0_DE_WIDTH               (1U)
#define MC_CGM_SLC_3_DC_0_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_3_DC_0_DE_SHIFT)) & MC_CGM_SLC_3_DC_0_DE_MASK)
/*! @} */

/*! @name SLC_3_DIV_UPD_STAT - Clock Slice 3 Divider Update Status */
/*! @{ */

#define MC_CGM_SLC_3_DIV_UPD_STAT_DIV_STAT_MASK  (0x1U)
#define MC_CGM_SLC_3_DIV_UPD_STAT_DIV_STAT_SHIFT (0U)
#define MC_CGM_SLC_3_DIV_UPD_STAT_DIV_STAT_WIDTH (1U)
#define MC_CGM_SLC_3_DIV_UPD_STAT_DIV_STAT(x)    (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_3_DIV_UPD_STAT_DIV_STAT_SHIFT)) & MC_CGM_SLC_3_DIV_UPD_STAT_DIV_STAT_MASK)
/*! @} */

/*! @name SLC_4_CSC - Clock Slice 4 Select Control */
/*! @{ */

#define MC_CGM_SLC_4_CSC_CLK_SW_MASK             (0x4U)
#define MC_CGM_SLC_4_CSC_CLK_SW_SHIFT            (2U)
#define MC_CGM_SLC_4_CSC_CLK_SW_WIDTH            (1U)
#define MC_CGM_SLC_4_CSC_CLK_SW(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_4_CSC_CLK_SW_SHIFT)) & MC_CGM_SLC_4_CSC_CLK_SW_MASK)

#define MC_CGM_SLC_4_CSC_SAFE_SW_MASK            (0x8U)
#define MC_CGM_SLC_4_CSC_SAFE_SW_SHIFT           (3U)
#define MC_CGM_SLC_4_CSC_SAFE_SW_WIDTH           (1U)
#define MC_CGM_SLC_4_CSC_SAFE_SW(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_4_CSC_SAFE_SW_SHIFT)) & MC_CGM_SLC_4_CSC_SAFE_SW_MASK)

#define MC_CGM_SLC_4_CSC_SELCTL_MASK             (0x3F000000U)
#define MC_CGM_SLC_4_CSC_SELCTL_SHIFT            (24U)
#define MC_CGM_SLC_4_CSC_SELCTL_WIDTH            (6U)
#define MC_CGM_SLC_4_CSC_SELCTL(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_4_CSC_SELCTL_SHIFT)) & MC_CGM_SLC_4_CSC_SELCTL_MASK)
/*! @} */

/*! @name SLC_4_CSS - Clock Slice 4 Select Status */
/*! @{ */

#define MC_CGM_SLC_4_CSS_SWIP_MASK               (0x4U)
#define MC_CGM_SLC_4_CSS_SWIP_SHIFT              (2U)
#define MC_CGM_SLC_4_CSS_SWIP_WIDTH              (1U)
#define MC_CGM_SLC_4_CSS_SWIP(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_4_CSS_SWIP_SHIFT)) & MC_CGM_SLC_4_CSS_SWIP_MASK)

#define MC_CGM_SLC_4_CSS_SAFESWIP_MASK           (0x8U)
#define MC_CGM_SLC_4_CSS_SAFESWIP_SHIFT          (3U)
#define MC_CGM_SLC_4_CSS_SAFESWIP_WIDTH          (1U)
#define MC_CGM_SLC_4_CSS_SAFESWIP(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_4_CSS_SAFESWIP_SHIFT)) & MC_CGM_SLC_4_CSS_SAFESWIP_MASK)

#define MC_CGM_SLC_4_CSS_SWTRG_MASK              (0x70000U)
#define MC_CGM_SLC_4_CSS_SWTRG_SHIFT             (16U)
#define MC_CGM_SLC_4_CSS_SWTRG_WIDTH             (3U)
#define MC_CGM_SLC_4_CSS_SWTRG(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_4_CSS_SWTRG_SHIFT)) & MC_CGM_SLC_4_CSS_SWTRG_MASK)

#define MC_CGM_SLC_4_CSS_SELSTAT_MASK            (0x3F000000U)
#define MC_CGM_SLC_4_CSS_SELSTAT_SHIFT           (24U)
#define MC_CGM_SLC_4_CSS_SELSTAT_WIDTH           (6U)
#define MC_CGM_SLC_4_CSS_SELSTAT(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_4_CSS_SELSTAT_SHIFT)) & MC_CGM_SLC_4_CSS_SELSTAT_MASK)
/*! @} */

/*! @name SLC_4_DC_0 - Clock Slice 4 Divider 0 Control */
/*! @{ */

#define MC_CGM_SLC_4_DC_0_DIV_MASK               (0xF0000U)  /* Merged from fields with different position or width, of widths (3, 4), largest definition used */
#define MC_CGM_SLC_4_DC_0_DIV_SHIFT              (16U)
#define MC_CGM_SLC_4_DC_0_DIV_WIDTH              (4U)
#define MC_CGM_SLC_4_DC_0_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_4_DC_0_DIV_SHIFT)) & MC_CGM_SLC_4_DC_0_DIV_MASK)  /* Merged from fields with different position or width, of widths (3, 4), largest definition used */

#define MC_CGM_SLC_4_DC_0_DE_MASK                (0x80000000U)
#define MC_CGM_SLC_4_DC_0_DE_SHIFT               (31U)
#define MC_CGM_SLC_4_DC_0_DE_WIDTH               (1U)
#define MC_CGM_SLC_4_DC_0_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_4_DC_0_DE_SHIFT)) & MC_CGM_SLC_4_DC_0_DE_MASK)
/*! @} */

/*! @name SLC_4_DIV_TRIG_CTRL - Clock Slice 4 Divider Trigger Control */
/*! @{ */

#define MC_CGM_SLC_4_DIV_TRIG_CTRL_IRE_MASK      (0x10000U)
#define MC_CGM_SLC_4_DIV_TRIG_CTRL_IRE_SHIFT     (16U)
#define MC_CGM_SLC_4_DIV_TRIG_CTRL_IRE_WIDTH     (1U)
#define MC_CGM_SLC_4_DIV_TRIG_CTRL_IRE(x)        (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_4_DIV_TRIG_CTRL_IRE_SHIFT)) & MC_CGM_SLC_4_DIV_TRIG_CTRL_IRE_MASK)
/*! @} */

/*! @name SLC_4_DIV_UPD_STAT - Clock Slice 4 Divider Update Status */
/*! @{ */

#define MC_CGM_SLC_4_DIV_UPD_STAT_DIV_STAT_MASK  (0x1U)
#define MC_CGM_SLC_4_DIV_UPD_STAT_DIV_STAT_SHIFT (0U)
#define MC_CGM_SLC_4_DIV_UPD_STAT_DIV_STAT_WIDTH (1U)
#define MC_CGM_SLC_4_DIV_UPD_STAT_DIV_STAT(x)    (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_4_DIV_UPD_STAT_DIV_STAT_SHIFT)) & MC_CGM_SLC_4_DIV_UPD_STAT_DIV_STAT_MASK)
/*! @} */

/*! @name SLC_5_CSC - Clock Slice 5 Select Control */
/*! @{ */

#define MC_CGM_SLC_5_CSC_CLK_SW_MASK             (0x4U)
#define MC_CGM_SLC_5_CSC_CLK_SW_SHIFT            (2U)
#define MC_CGM_SLC_5_CSC_CLK_SW_WIDTH            (1U)
#define MC_CGM_SLC_5_CSC_CLK_SW(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_5_CSC_CLK_SW_SHIFT)) & MC_CGM_SLC_5_CSC_CLK_SW_MASK)

#define MC_CGM_SLC_5_CSC_SAFE_SW_MASK            (0x8U)
#define MC_CGM_SLC_5_CSC_SAFE_SW_SHIFT           (3U)
#define MC_CGM_SLC_5_CSC_SAFE_SW_WIDTH           (1U)
#define MC_CGM_SLC_5_CSC_SAFE_SW(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_5_CSC_SAFE_SW_SHIFT)) & MC_CGM_SLC_5_CSC_SAFE_SW_MASK)

#define MC_CGM_SLC_5_CSC_SELCTL_MASK             (0x3F000000U)
#define MC_CGM_SLC_5_CSC_SELCTL_SHIFT            (24U)
#define MC_CGM_SLC_5_CSC_SELCTL_WIDTH            (6U)
#define MC_CGM_SLC_5_CSC_SELCTL(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_5_CSC_SELCTL_SHIFT)) & MC_CGM_SLC_5_CSC_SELCTL_MASK)
/*! @} */

/*! @name SLC_5_CSS - Clock Slice 5 Select Status */
/*! @{ */

#define MC_CGM_SLC_5_CSS_SWIP_MASK               (0x4U)
#define MC_CGM_SLC_5_CSS_SWIP_SHIFT              (2U)
#define MC_CGM_SLC_5_CSS_SWIP_WIDTH              (1U)
#define MC_CGM_SLC_5_CSS_SWIP(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_5_CSS_SWIP_SHIFT)) & MC_CGM_SLC_5_CSS_SWIP_MASK)

#define MC_CGM_SLC_5_CSS_SAFESWIP_MASK           (0x8U)
#define MC_CGM_SLC_5_CSS_SAFESWIP_SHIFT          (3U)
#define MC_CGM_SLC_5_CSS_SAFESWIP_WIDTH          (1U)
#define MC_CGM_SLC_5_CSS_SAFESWIP(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_5_CSS_SAFESWIP_SHIFT)) & MC_CGM_SLC_5_CSS_SAFESWIP_MASK)

#define MC_CGM_SLC_5_CSS_SWTRG_MASK              (0x70000U)
#define MC_CGM_SLC_5_CSS_SWTRG_SHIFT             (16U)
#define MC_CGM_SLC_5_CSS_SWTRG_WIDTH             (3U)
#define MC_CGM_SLC_5_CSS_SWTRG(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_5_CSS_SWTRG_SHIFT)) & MC_CGM_SLC_5_CSS_SWTRG_MASK)

#define MC_CGM_SLC_5_CSS_SELSTAT_MASK            (0x3F000000U)
#define MC_CGM_SLC_5_CSS_SELSTAT_SHIFT           (24U)
#define MC_CGM_SLC_5_CSS_SELSTAT_WIDTH           (6U)
#define MC_CGM_SLC_5_CSS_SELSTAT(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_5_CSS_SELSTAT_SHIFT)) & MC_CGM_SLC_5_CSS_SELSTAT_MASK)
/*! @} */

/*! @name SLC_5_DC_0 - Clock Slice 5 Divider 0 Control */
/*! @{ */

#define MC_CGM_SLC_5_DC_0_DIV_MASK               (0xF0000U)  /* Merged from fields with different position or width, of widths (3, 4), largest definition used */
#define MC_CGM_SLC_5_DC_0_DIV_SHIFT              (16U)
#define MC_CGM_SLC_5_DC_0_DIV_WIDTH              (4U)
#define MC_CGM_SLC_5_DC_0_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_5_DC_0_DIV_SHIFT)) & MC_CGM_SLC_5_DC_0_DIV_MASK)  /* Merged from fields with different position or width, of widths (3, 4), largest definition used */

#define MC_CGM_SLC_5_DC_0_DE_MASK                (0x80000000U)
#define MC_CGM_SLC_5_DC_0_DE_SHIFT               (31U)
#define MC_CGM_SLC_5_DC_0_DE_WIDTH               (1U)
#define MC_CGM_SLC_5_DC_0_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_5_DC_0_DE_SHIFT)) & MC_CGM_SLC_5_DC_0_DE_MASK)
/*! @} */

/*! @name SLC_5_DIV_UPD_STAT - Clock Slice 5 Divider Update Status */
/*! @{ */

#define MC_CGM_SLC_5_DIV_UPD_STAT_DIV_STAT_MASK  (0x1U)
#define MC_CGM_SLC_5_DIV_UPD_STAT_DIV_STAT_SHIFT (0U)
#define MC_CGM_SLC_5_DIV_UPD_STAT_DIV_STAT_WIDTH (1U)
#define MC_CGM_SLC_5_DIV_UPD_STAT_DIV_STAT(x)    (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_5_DIV_UPD_STAT_DIV_STAT_SHIFT)) & MC_CGM_SLC_5_DIV_UPD_STAT_DIV_STAT_MASK)
/*! @} */

/*! @name SLC_6_CSC - Clock Slice 6 Select Control */
/*! @{ */

#define MC_CGM_SLC_6_CSC_CLK_SW_MASK             (0x4U)
#define MC_CGM_SLC_6_CSC_CLK_SW_SHIFT            (2U)
#define MC_CGM_SLC_6_CSC_CLK_SW_WIDTH            (1U)
#define MC_CGM_SLC_6_CSC_CLK_SW(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_6_CSC_CLK_SW_SHIFT)) & MC_CGM_SLC_6_CSC_CLK_SW_MASK)

#define MC_CGM_SLC_6_CSC_SAFE_SW_MASK            (0x8U)
#define MC_CGM_SLC_6_CSC_SAFE_SW_SHIFT           (3U)
#define MC_CGM_SLC_6_CSC_SAFE_SW_WIDTH           (1U)
#define MC_CGM_SLC_6_CSC_SAFE_SW(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_6_CSC_SAFE_SW_SHIFT)) & MC_CGM_SLC_6_CSC_SAFE_SW_MASK)

#define MC_CGM_SLC_6_CSC_SELCTL_MASK             (0x3F000000U)
#define MC_CGM_SLC_6_CSC_SELCTL_SHIFT            (24U)
#define MC_CGM_SLC_6_CSC_SELCTL_WIDTH            (6U)
#define MC_CGM_SLC_6_CSC_SELCTL(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_6_CSC_SELCTL_SHIFT)) & MC_CGM_SLC_6_CSC_SELCTL_MASK)
/*! @} */

/*! @name SLC_6_CSS - Clock Slice 6 Select Status */
/*! @{ */

#define MC_CGM_SLC_6_CSS_SWIP_MASK               (0x4U)
#define MC_CGM_SLC_6_CSS_SWIP_SHIFT              (2U)
#define MC_CGM_SLC_6_CSS_SWIP_WIDTH              (1U)
#define MC_CGM_SLC_6_CSS_SWIP(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_6_CSS_SWIP_SHIFT)) & MC_CGM_SLC_6_CSS_SWIP_MASK)

#define MC_CGM_SLC_6_CSS_SAFESWIP_MASK           (0x8U)
#define MC_CGM_SLC_6_CSS_SAFESWIP_SHIFT          (3U)
#define MC_CGM_SLC_6_CSS_SAFESWIP_WIDTH          (1U)
#define MC_CGM_SLC_6_CSS_SAFESWIP(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_6_CSS_SAFESWIP_SHIFT)) & MC_CGM_SLC_6_CSS_SAFESWIP_MASK)

#define MC_CGM_SLC_6_CSS_SWTRG_MASK              (0x70000U)
#define MC_CGM_SLC_6_CSS_SWTRG_SHIFT             (16U)
#define MC_CGM_SLC_6_CSS_SWTRG_WIDTH             (3U)
#define MC_CGM_SLC_6_CSS_SWTRG(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_6_CSS_SWTRG_SHIFT)) & MC_CGM_SLC_6_CSS_SWTRG_MASK)

#define MC_CGM_SLC_6_CSS_SELSTAT_MASK            (0x3F000000U)
#define MC_CGM_SLC_6_CSS_SELSTAT_SHIFT           (24U)
#define MC_CGM_SLC_6_CSS_SELSTAT_WIDTH           (6U)
#define MC_CGM_SLC_6_CSS_SELSTAT(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_6_CSS_SELSTAT_SHIFT)) & MC_CGM_SLC_6_CSS_SELSTAT_MASK)
/*! @} */

/*! @name SLC_6_DC_0 - Clock Slice 6 Divider 0 Control */
/*! @{ */

#define MC_CGM_SLC_6_DC_0_DIV_MASK               (0x3F0000U)  /* Merged from fields with different position or width, of widths (3, 4, 6), largest definition used */
#define MC_CGM_SLC_6_DC_0_DIV_SHIFT              (16U)
#define MC_CGM_SLC_6_DC_0_DIV_WIDTH              (6U)
#define MC_CGM_SLC_6_DC_0_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_6_DC_0_DIV_SHIFT)) & MC_CGM_SLC_6_DC_0_DIV_MASK)  /* Merged from fields with different position or width, of widths (3, 4, 6), largest definition used */

#define MC_CGM_SLC_6_DC_0_DE_MASK                (0x80000000U)
#define MC_CGM_SLC_6_DC_0_DE_SHIFT               (31U)
#define MC_CGM_SLC_6_DC_0_DE_WIDTH               (1U)
#define MC_CGM_SLC_6_DC_0_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_6_DC_0_DE_SHIFT)) & MC_CGM_SLC_6_DC_0_DE_MASK)
/*! @} */

/*! @name SLC_6_DIV_UPD_STAT - Clock Slice 6 Divider Update Status */
/*! @{ */

#define MC_CGM_SLC_6_DIV_UPD_STAT_DIV_STAT_MASK  (0x1U)
#define MC_CGM_SLC_6_DIV_UPD_STAT_DIV_STAT_SHIFT (0U)
#define MC_CGM_SLC_6_DIV_UPD_STAT_DIV_STAT_WIDTH (1U)
#define MC_CGM_SLC_6_DIV_UPD_STAT_DIV_STAT(x)    (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_6_DIV_UPD_STAT_DIV_STAT_SHIFT)) & MC_CGM_SLC_6_DIV_UPD_STAT_DIV_STAT_MASK)
/*! @} */

/*! @name SLC_7_CSC - Clock Slice 7 Select Control */
/*! @{ */

#define MC_CGM_SLC_7_CSC_CLK_SW_MASK             (0x4U)
#define MC_CGM_SLC_7_CSC_CLK_SW_SHIFT            (2U)
#define MC_CGM_SLC_7_CSC_CLK_SW_WIDTH            (1U)
#define MC_CGM_SLC_7_CSC_CLK_SW(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_7_CSC_CLK_SW_SHIFT)) & MC_CGM_SLC_7_CSC_CLK_SW_MASK)

#define MC_CGM_SLC_7_CSC_SAFE_SW_MASK            (0x8U)
#define MC_CGM_SLC_7_CSC_SAFE_SW_SHIFT           (3U)
#define MC_CGM_SLC_7_CSC_SAFE_SW_WIDTH           (1U)
#define MC_CGM_SLC_7_CSC_SAFE_SW(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_7_CSC_SAFE_SW_SHIFT)) & MC_CGM_SLC_7_CSC_SAFE_SW_MASK)

#define MC_CGM_SLC_7_CSC_SELCTL_MASK             (0x3F000000U)
#define MC_CGM_SLC_7_CSC_SELCTL_SHIFT            (24U)
#define MC_CGM_SLC_7_CSC_SELCTL_WIDTH            (6U)
#define MC_CGM_SLC_7_CSC_SELCTL(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_7_CSC_SELCTL_SHIFT)) & MC_CGM_SLC_7_CSC_SELCTL_MASK)
/*! @} */

/*! @name SLC_7_CSS - Clock Slice 7 Select Status */
/*! @{ */

#define MC_CGM_SLC_7_CSS_SWIP_MASK               (0x4U)
#define MC_CGM_SLC_7_CSS_SWIP_SHIFT              (2U)
#define MC_CGM_SLC_7_CSS_SWIP_WIDTH              (1U)
#define MC_CGM_SLC_7_CSS_SWIP(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_7_CSS_SWIP_SHIFT)) & MC_CGM_SLC_7_CSS_SWIP_MASK)

#define MC_CGM_SLC_7_CSS_SAFESWIP_MASK           (0x8U)
#define MC_CGM_SLC_7_CSS_SAFESWIP_SHIFT          (3U)
#define MC_CGM_SLC_7_CSS_SAFESWIP_WIDTH          (1U)
#define MC_CGM_SLC_7_CSS_SAFESWIP(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_7_CSS_SAFESWIP_SHIFT)) & MC_CGM_SLC_7_CSS_SAFESWIP_MASK)

#define MC_CGM_SLC_7_CSS_SWTRG_MASK              (0x70000U)
#define MC_CGM_SLC_7_CSS_SWTRG_SHIFT             (16U)
#define MC_CGM_SLC_7_CSS_SWTRG_WIDTH             (3U)
#define MC_CGM_SLC_7_CSS_SWTRG(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_7_CSS_SWTRG_SHIFT)) & MC_CGM_SLC_7_CSS_SWTRG_MASK)

#define MC_CGM_SLC_7_CSS_SELSTAT_MASK            (0x3F000000U)
#define MC_CGM_SLC_7_CSS_SELSTAT_SHIFT           (24U)
#define MC_CGM_SLC_7_CSS_SELSTAT_WIDTH           (6U)
#define MC_CGM_SLC_7_CSS_SELSTAT(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_7_CSS_SELSTAT_SHIFT)) & MC_CGM_SLC_7_CSS_SELSTAT_MASK)
/*! @} */

/*! @name SLC_7_DC_0 - Clock Slice 7 Divider 0 Control */
/*! @{ */

#define MC_CGM_SLC_7_DC_0_DIV_MASK               (0xF0000U)  /* Merged from fields with different position or width, of widths (3, 4), largest definition used */
#define MC_CGM_SLC_7_DC_0_DIV_SHIFT              (16U)
#define MC_CGM_SLC_7_DC_0_DIV_WIDTH              (4U)
#define MC_CGM_SLC_7_DC_0_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_7_DC_0_DIV_SHIFT)) & MC_CGM_SLC_7_DC_0_DIV_MASK)  /* Merged from fields with different position or width, of widths (3, 4), largest definition used */

#define MC_CGM_SLC_7_DC_0_DE_MASK                (0x80000000U)
#define MC_CGM_SLC_7_DC_0_DE_SHIFT               (31U)
#define MC_CGM_SLC_7_DC_0_DE_WIDTH               (1U)
#define MC_CGM_SLC_7_DC_0_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_7_DC_0_DE_SHIFT)) & MC_CGM_SLC_7_DC_0_DE_MASK)
/*! @} */

/*! @name SLC_7_DIV_UPD_STAT - Clock Slice 7 Divider Update Status */
/*! @{ */

#define MC_CGM_SLC_7_DIV_UPD_STAT_DIV_STAT_MASK  (0x1U)
#define MC_CGM_SLC_7_DIV_UPD_STAT_DIV_STAT_SHIFT (0U)
#define MC_CGM_SLC_7_DIV_UPD_STAT_DIV_STAT_WIDTH (1U)
#define MC_CGM_SLC_7_DIV_UPD_STAT_DIV_STAT(x)    (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_7_DIV_UPD_STAT_DIV_STAT_SHIFT)) & MC_CGM_SLC_7_DIV_UPD_STAT_DIV_STAT_MASK)
/*! @} */

/*! @name SLC_8_CSC - Clock Slice 8 Select Control */
/*! @{ */

#define MC_CGM_SLC_8_CSC_CLK_SW_MASK             (0x4U)
#define MC_CGM_SLC_8_CSC_CLK_SW_SHIFT            (2U)
#define MC_CGM_SLC_8_CSC_CLK_SW_WIDTH            (1U)
#define MC_CGM_SLC_8_CSC_CLK_SW(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_8_CSC_CLK_SW_SHIFT)) & MC_CGM_SLC_8_CSC_CLK_SW_MASK)

#define MC_CGM_SLC_8_CSC_SAFE_SW_MASK            (0x8U)
#define MC_CGM_SLC_8_CSC_SAFE_SW_SHIFT           (3U)
#define MC_CGM_SLC_8_CSC_SAFE_SW_WIDTH           (1U)
#define MC_CGM_SLC_8_CSC_SAFE_SW(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_8_CSC_SAFE_SW_SHIFT)) & MC_CGM_SLC_8_CSC_SAFE_SW_MASK)

#define MC_CGM_SLC_8_CSC_SELCTL_MASK             (0x3F000000U)
#define MC_CGM_SLC_8_CSC_SELCTL_SHIFT            (24U)
#define MC_CGM_SLC_8_CSC_SELCTL_WIDTH            (6U)
#define MC_CGM_SLC_8_CSC_SELCTL(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_8_CSC_SELCTL_SHIFT)) & MC_CGM_SLC_8_CSC_SELCTL_MASK)
/*! @} */

/*! @name SLC_8_CSS - Clock Slice 8 Select Status */
/*! @{ */

#define MC_CGM_SLC_8_CSS_SWIP_MASK               (0x4U)
#define MC_CGM_SLC_8_CSS_SWIP_SHIFT              (2U)
#define MC_CGM_SLC_8_CSS_SWIP_WIDTH              (1U)
#define MC_CGM_SLC_8_CSS_SWIP(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_8_CSS_SWIP_SHIFT)) & MC_CGM_SLC_8_CSS_SWIP_MASK)

#define MC_CGM_SLC_8_CSS_SAFESWIP_MASK           (0x8U)
#define MC_CGM_SLC_8_CSS_SAFESWIP_SHIFT          (3U)
#define MC_CGM_SLC_8_CSS_SAFESWIP_WIDTH          (1U)
#define MC_CGM_SLC_8_CSS_SAFESWIP(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_8_CSS_SAFESWIP_SHIFT)) & MC_CGM_SLC_8_CSS_SAFESWIP_MASK)

#define MC_CGM_SLC_8_CSS_SWTRG_MASK              (0x70000U)
#define MC_CGM_SLC_8_CSS_SWTRG_SHIFT             (16U)
#define MC_CGM_SLC_8_CSS_SWTRG_WIDTH             (3U)
#define MC_CGM_SLC_8_CSS_SWTRG(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_8_CSS_SWTRG_SHIFT)) & MC_CGM_SLC_8_CSS_SWTRG_MASK)

#define MC_CGM_SLC_8_CSS_SELSTAT_MASK            (0x3F000000U)
#define MC_CGM_SLC_8_CSS_SELSTAT_SHIFT           (24U)
#define MC_CGM_SLC_8_CSS_SELSTAT_WIDTH           (6U)
#define MC_CGM_SLC_8_CSS_SELSTAT(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_8_CSS_SELSTAT_SHIFT)) & MC_CGM_SLC_8_CSS_SELSTAT_MASK)
/*! @} */

/*! @name SLC_8_DC_0 - Clock Slice 8 Divider 0 Control */
/*! @{ */

#define MC_CGM_SLC_8_DC_0_DIV_MASK               (0xF0000U)  /* Merged from fields with different position or width, of widths (3, 4), largest definition used */
#define MC_CGM_SLC_8_DC_0_DIV_SHIFT              (16U)
#define MC_CGM_SLC_8_DC_0_DIV_WIDTH              (4U)
#define MC_CGM_SLC_8_DC_0_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_8_DC_0_DIV_SHIFT)) & MC_CGM_SLC_8_DC_0_DIV_MASK)  /* Merged from fields with different position or width, of widths (3, 4), largest definition used */

#define MC_CGM_SLC_8_DC_0_DE_MASK                (0x80000000U)
#define MC_CGM_SLC_8_DC_0_DE_SHIFT               (31U)
#define MC_CGM_SLC_8_DC_0_DE_WIDTH               (1U)
#define MC_CGM_SLC_8_DC_0_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_8_DC_0_DE_SHIFT)) & MC_CGM_SLC_8_DC_0_DE_MASK)
/*! @} */

/*! @name SLC_8_DIV_UPD_STAT - Clock Slice 8 Divider Update Status */
/*! @{ */

#define MC_CGM_SLC_8_DIV_UPD_STAT_DIV_STAT_MASK  (0x1U)
#define MC_CGM_SLC_8_DIV_UPD_STAT_DIV_STAT_SHIFT (0U)
#define MC_CGM_SLC_8_DIV_UPD_STAT_DIV_STAT_WIDTH (1U)
#define MC_CGM_SLC_8_DIV_UPD_STAT_DIV_STAT(x)    (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_8_DIV_UPD_STAT_DIV_STAT_SHIFT)) & MC_CGM_SLC_8_DIV_UPD_STAT_DIV_STAT_MASK)
/*! @} */

/*! @name SLC_9_CSC - Clock Slice 9 Select Control */
/*! @{ */

#define MC_CGM_SLC_9_CSC_CLK_SW_MASK             (0x4U)
#define MC_CGM_SLC_9_CSC_CLK_SW_SHIFT            (2U)
#define MC_CGM_SLC_9_CSC_CLK_SW_WIDTH            (1U)
#define MC_CGM_SLC_9_CSC_CLK_SW(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_9_CSC_CLK_SW_SHIFT)) & MC_CGM_SLC_9_CSC_CLK_SW_MASK)

#define MC_CGM_SLC_9_CSC_SAFE_SW_MASK            (0x8U)
#define MC_CGM_SLC_9_CSC_SAFE_SW_SHIFT           (3U)
#define MC_CGM_SLC_9_CSC_SAFE_SW_WIDTH           (1U)
#define MC_CGM_SLC_9_CSC_SAFE_SW(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_9_CSC_SAFE_SW_SHIFT)) & MC_CGM_SLC_9_CSC_SAFE_SW_MASK)

#define MC_CGM_SLC_9_CSC_SELCTL_MASK             (0x3F000000U)
#define MC_CGM_SLC_9_CSC_SELCTL_SHIFT            (24U)
#define MC_CGM_SLC_9_CSC_SELCTL_WIDTH            (6U)
#define MC_CGM_SLC_9_CSC_SELCTL(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_9_CSC_SELCTL_SHIFT)) & MC_CGM_SLC_9_CSC_SELCTL_MASK)
/*! @} */

/*! @name SLC_9_CSS - Clock Slice 9 Select Status */
/*! @{ */

#define MC_CGM_SLC_9_CSS_SWIP_MASK               (0x4U)
#define MC_CGM_SLC_9_CSS_SWIP_SHIFT              (2U)
#define MC_CGM_SLC_9_CSS_SWIP_WIDTH              (1U)
#define MC_CGM_SLC_9_CSS_SWIP(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_9_CSS_SWIP_SHIFT)) & MC_CGM_SLC_9_CSS_SWIP_MASK)

#define MC_CGM_SLC_9_CSS_SAFESWIP_MASK           (0x8U)
#define MC_CGM_SLC_9_CSS_SAFESWIP_SHIFT          (3U)
#define MC_CGM_SLC_9_CSS_SAFESWIP_WIDTH          (1U)
#define MC_CGM_SLC_9_CSS_SAFESWIP(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_9_CSS_SAFESWIP_SHIFT)) & MC_CGM_SLC_9_CSS_SAFESWIP_MASK)

#define MC_CGM_SLC_9_CSS_SWTRG_MASK              (0x70000U)
#define MC_CGM_SLC_9_CSS_SWTRG_SHIFT             (16U)
#define MC_CGM_SLC_9_CSS_SWTRG_WIDTH             (3U)
#define MC_CGM_SLC_9_CSS_SWTRG(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_9_CSS_SWTRG_SHIFT)) & MC_CGM_SLC_9_CSS_SWTRG_MASK)

#define MC_CGM_SLC_9_CSS_SELSTAT_MASK            (0x3F000000U)
#define MC_CGM_SLC_9_CSS_SELSTAT_SHIFT           (24U)
#define MC_CGM_SLC_9_CSS_SELSTAT_WIDTH           (6U)
#define MC_CGM_SLC_9_CSS_SELSTAT(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_9_CSS_SELSTAT_SHIFT)) & MC_CGM_SLC_9_CSS_SELSTAT_MASK)
/*! @} */

/*! @name SLC_9_DC_0 - Clock Slice 9 Divider 0 Control */
/*! @{ */

#define MC_CGM_SLC_9_DC_0_DIV_MASK               (0xF0000U)  /* Merged from fields with different position or width, of widths (3, 4), largest definition used */
#define MC_CGM_SLC_9_DC_0_DIV_SHIFT              (16U)
#define MC_CGM_SLC_9_DC_0_DIV_WIDTH              (4U)
#define MC_CGM_SLC_9_DC_0_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_9_DC_0_DIV_SHIFT)) & MC_CGM_SLC_9_DC_0_DIV_MASK)  /* Merged from fields with different position or width, of widths (3, 4), largest definition used */

#define MC_CGM_SLC_9_DC_0_DE_MASK                (0x80000000U)
#define MC_CGM_SLC_9_DC_0_DE_SHIFT               (31U)
#define MC_CGM_SLC_9_DC_0_DE_WIDTH               (1U)
#define MC_CGM_SLC_9_DC_0_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_9_DC_0_DE_SHIFT)) & MC_CGM_SLC_9_DC_0_DE_MASK)
/*! @} */

/*! @name SLC_9_DIV_UPD_STAT - Clock Slice 9 Divider Update Status */
/*! @{ */

#define MC_CGM_SLC_9_DIV_UPD_STAT_DIV_STAT_MASK  (0x1U)
#define MC_CGM_SLC_9_DIV_UPD_STAT_DIV_STAT_SHIFT (0U)
#define MC_CGM_SLC_9_DIV_UPD_STAT_DIV_STAT_WIDTH (1U)
#define MC_CGM_SLC_9_DIV_UPD_STAT_DIV_STAT(x)    (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_9_DIV_UPD_STAT_DIV_STAT_SHIFT)) & MC_CGM_SLC_9_DIV_UPD_STAT_DIV_STAT_MASK)
/*! @} */

/*! @name SLC_10_CSC - Clock Slice 10 Select Control */
/*! @{ */

#define MC_CGM_SLC_10_CSC_CLK_SW_MASK            (0x4U)
#define MC_CGM_SLC_10_CSC_CLK_SW_SHIFT           (2U)
#define MC_CGM_SLC_10_CSC_CLK_SW_WIDTH           (1U)
#define MC_CGM_SLC_10_CSC_CLK_SW(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_10_CSC_CLK_SW_SHIFT)) & MC_CGM_SLC_10_CSC_CLK_SW_MASK)

#define MC_CGM_SLC_10_CSC_SAFE_SW_MASK           (0x8U)
#define MC_CGM_SLC_10_CSC_SAFE_SW_SHIFT          (3U)
#define MC_CGM_SLC_10_CSC_SAFE_SW_WIDTH          (1U)
#define MC_CGM_SLC_10_CSC_SAFE_SW(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_10_CSC_SAFE_SW_SHIFT)) & MC_CGM_SLC_10_CSC_SAFE_SW_MASK)

#define MC_CGM_SLC_10_CSC_SELCTL_MASK            (0x3F000000U)
#define MC_CGM_SLC_10_CSC_SELCTL_SHIFT           (24U)
#define MC_CGM_SLC_10_CSC_SELCTL_WIDTH           (6U)
#define MC_CGM_SLC_10_CSC_SELCTL(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_10_CSC_SELCTL_SHIFT)) & MC_CGM_SLC_10_CSC_SELCTL_MASK)
/*! @} */

/*! @name SLC_10_CSS - Clock Slice 10 Select Status */
/*! @{ */

#define MC_CGM_SLC_10_CSS_SWIP_MASK              (0x4U)
#define MC_CGM_SLC_10_CSS_SWIP_SHIFT             (2U)
#define MC_CGM_SLC_10_CSS_SWIP_WIDTH             (1U)
#define MC_CGM_SLC_10_CSS_SWIP(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_10_CSS_SWIP_SHIFT)) & MC_CGM_SLC_10_CSS_SWIP_MASK)

#define MC_CGM_SLC_10_CSS_SAFESWIP_MASK          (0x8U)
#define MC_CGM_SLC_10_CSS_SAFESWIP_SHIFT         (3U)
#define MC_CGM_SLC_10_CSS_SAFESWIP_WIDTH         (1U)
#define MC_CGM_SLC_10_CSS_SAFESWIP(x)            (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_10_CSS_SAFESWIP_SHIFT)) & MC_CGM_SLC_10_CSS_SAFESWIP_MASK)

#define MC_CGM_SLC_10_CSS_SWTRG_MASK             (0x70000U)
#define MC_CGM_SLC_10_CSS_SWTRG_SHIFT            (16U)
#define MC_CGM_SLC_10_CSS_SWTRG_WIDTH            (3U)
#define MC_CGM_SLC_10_CSS_SWTRG(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_10_CSS_SWTRG_SHIFT)) & MC_CGM_SLC_10_CSS_SWTRG_MASK)

#define MC_CGM_SLC_10_CSS_SELSTAT_MASK           (0x3F000000U)
#define MC_CGM_SLC_10_CSS_SELSTAT_SHIFT          (24U)
#define MC_CGM_SLC_10_CSS_SELSTAT_WIDTH          (6U)
#define MC_CGM_SLC_10_CSS_SELSTAT(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_10_CSS_SELSTAT_SHIFT)) & MC_CGM_SLC_10_CSS_SELSTAT_MASK)
/*! @} */

/*! @name SLC_10_DC_0 - Clock Slice 10 Divider 0 Control */
/*! @{ */

#define MC_CGM_SLC_10_DC_0_DIV_MASK              (0xF0000U)  /* Merged from fields with different position or width, of widths (3, 4), largest definition used */
#define MC_CGM_SLC_10_DC_0_DIV_SHIFT             (16U)
#define MC_CGM_SLC_10_DC_0_DIV_WIDTH             (4U)
#define MC_CGM_SLC_10_DC_0_DIV(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_10_DC_0_DIV_SHIFT)) & MC_CGM_SLC_10_DC_0_DIV_MASK)  /* Merged from fields with different position or width, of widths (3, 4), largest definition used */

#define MC_CGM_SLC_10_DC_0_DE_MASK               (0x80000000U)
#define MC_CGM_SLC_10_DC_0_DE_SHIFT              (31U)
#define MC_CGM_SLC_10_DC_0_DE_WIDTH              (1U)
#define MC_CGM_SLC_10_DC_0_DE(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_10_DC_0_DE_SHIFT)) & MC_CGM_SLC_10_DC_0_DE_MASK)
/*! @} */

/*! @name SLC_10_DIV_TRIG_CTRL - Clock Slice 10 Divider Trigger Control */
/*! @{ */

#define MC_CGM_SLC_10_DIV_TRIG_CTRL_IRE_MASK     (0x10000U)
#define MC_CGM_SLC_10_DIV_TRIG_CTRL_IRE_SHIFT    (16U)
#define MC_CGM_SLC_10_DIV_TRIG_CTRL_IRE_WIDTH    (1U)
#define MC_CGM_SLC_10_DIV_TRIG_CTRL_IRE(x)       (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_10_DIV_TRIG_CTRL_IRE_SHIFT)) & MC_CGM_SLC_10_DIV_TRIG_CTRL_IRE_MASK)
/*! @} */

/*! @name SLC_10_DIV_UPD_STAT - Clock Slice 10 Divider Update Status */
/*! @{ */

#define MC_CGM_SLC_10_DIV_UPD_STAT_DIV_STAT_MASK (0x1U)
#define MC_CGM_SLC_10_DIV_UPD_STAT_DIV_STAT_SHIFT (0U)
#define MC_CGM_SLC_10_DIV_UPD_STAT_DIV_STAT_WIDTH (1U)
#define MC_CGM_SLC_10_DIV_UPD_STAT_DIV_STAT(x)   (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_10_DIV_UPD_STAT_DIV_STAT_SHIFT)) & MC_CGM_SLC_10_DIV_UPD_STAT_DIV_STAT_MASK)
/*! @} */

/*! @name SLC_11_CSC - Clock Slice 11 Select Control */
/*! @{ */

#define MC_CGM_SLC_11_CSC_CLK_SW_MASK            (0x4U)
#define MC_CGM_SLC_11_CSC_CLK_SW_SHIFT           (2U)
#define MC_CGM_SLC_11_CSC_CLK_SW_WIDTH           (1U)
#define MC_CGM_SLC_11_CSC_CLK_SW(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_11_CSC_CLK_SW_SHIFT)) & MC_CGM_SLC_11_CSC_CLK_SW_MASK)

#define MC_CGM_SLC_11_CSC_SAFE_SW_MASK           (0x8U)
#define MC_CGM_SLC_11_CSC_SAFE_SW_SHIFT          (3U)
#define MC_CGM_SLC_11_CSC_SAFE_SW_WIDTH          (1U)
#define MC_CGM_SLC_11_CSC_SAFE_SW(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_11_CSC_SAFE_SW_SHIFT)) & MC_CGM_SLC_11_CSC_SAFE_SW_MASK)

#define MC_CGM_SLC_11_CSC_SELCTL_MASK            (0x3F000000U)
#define MC_CGM_SLC_11_CSC_SELCTL_SHIFT           (24U)
#define MC_CGM_SLC_11_CSC_SELCTL_WIDTH           (6U)
#define MC_CGM_SLC_11_CSC_SELCTL(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_11_CSC_SELCTL_SHIFT)) & MC_CGM_SLC_11_CSC_SELCTL_MASK)
/*! @} */

/*! @name SLC_11_CSS - Clock Slice 11 Select Status */
/*! @{ */

#define MC_CGM_SLC_11_CSS_SWIP_MASK              (0x4U)
#define MC_CGM_SLC_11_CSS_SWIP_SHIFT             (2U)
#define MC_CGM_SLC_11_CSS_SWIP_WIDTH             (1U)
#define MC_CGM_SLC_11_CSS_SWIP(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_11_CSS_SWIP_SHIFT)) & MC_CGM_SLC_11_CSS_SWIP_MASK)

#define MC_CGM_SLC_11_CSS_SAFESWIP_MASK          (0x8U)
#define MC_CGM_SLC_11_CSS_SAFESWIP_SHIFT         (3U)
#define MC_CGM_SLC_11_CSS_SAFESWIP_WIDTH         (1U)
#define MC_CGM_SLC_11_CSS_SAFESWIP(x)            (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_11_CSS_SAFESWIP_SHIFT)) & MC_CGM_SLC_11_CSS_SAFESWIP_MASK)

#define MC_CGM_SLC_11_CSS_SWTRG_MASK             (0x70000U)
#define MC_CGM_SLC_11_CSS_SWTRG_SHIFT            (16U)
#define MC_CGM_SLC_11_CSS_SWTRG_WIDTH            (3U)
#define MC_CGM_SLC_11_CSS_SWTRG(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_11_CSS_SWTRG_SHIFT)) & MC_CGM_SLC_11_CSS_SWTRG_MASK)

#define MC_CGM_SLC_11_CSS_SELSTAT_MASK           (0x3F000000U)
#define MC_CGM_SLC_11_CSS_SELSTAT_SHIFT          (24U)
#define MC_CGM_SLC_11_CSS_SELSTAT_WIDTH          (6U)
#define MC_CGM_SLC_11_CSS_SELSTAT(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_11_CSS_SELSTAT_SHIFT)) & MC_CGM_SLC_11_CSS_SELSTAT_MASK)
/*! @} */

/*! @name SLC_11_DC_0 - Clock Slice 11 Divider 0 Control */
/*! @{ */

#define MC_CGM_SLC_11_DC_0_DIV_MASK              (0xF0000U)  /* Merged from fields with different position or width, of widths (3, 4), largest definition used */
#define MC_CGM_SLC_11_DC_0_DIV_SHIFT             (16U)
#define MC_CGM_SLC_11_DC_0_DIV_WIDTH             (4U)
#define MC_CGM_SLC_11_DC_0_DIV(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_11_DC_0_DIV_SHIFT)) & MC_CGM_SLC_11_DC_0_DIV_MASK)  /* Merged from fields with different position or width, of widths (3, 4), largest definition used */

#define MC_CGM_SLC_11_DC_0_DE_MASK               (0x80000000U)
#define MC_CGM_SLC_11_DC_0_DE_SHIFT              (31U)
#define MC_CGM_SLC_11_DC_0_DE_WIDTH              (1U)
#define MC_CGM_SLC_11_DC_0_DE(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_11_DC_0_DE_SHIFT)) & MC_CGM_SLC_11_DC_0_DE_MASK)
/*! @} */

/*! @name SLC_11_DIV_UPD_STAT - Clock Slice 11 Divider Update Status */
/*! @{ */

#define MC_CGM_SLC_11_DIV_UPD_STAT_DIV_STAT_MASK (0x1U)
#define MC_CGM_SLC_11_DIV_UPD_STAT_DIV_STAT_SHIFT (0U)
#define MC_CGM_SLC_11_DIV_UPD_STAT_DIV_STAT_WIDTH (1U)
#define MC_CGM_SLC_11_DIV_UPD_STAT_DIV_STAT(x)   (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_11_DIV_UPD_STAT_DIV_STAT_SHIFT)) & MC_CGM_SLC_11_DIV_UPD_STAT_DIV_STAT_MASK)
/*! @} */

/*! @name SLC_12_CSC - Clock Slice 12 Select Control */
/*! @{ */

#define MC_CGM_SLC_12_CSC_CLK_SW_MASK            (0x4U)
#define MC_CGM_SLC_12_CSC_CLK_SW_SHIFT           (2U)
#define MC_CGM_SLC_12_CSC_CLK_SW_WIDTH           (1U)
#define MC_CGM_SLC_12_CSC_CLK_SW(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_12_CSC_CLK_SW_SHIFT)) & MC_CGM_SLC_12_CSC_CLK_SW_MASK)

#define MC_CGM_SLC_12_CSC_SAFE_SW_MASK           (0x8U)
#define MC_CGM_SLC_12_CSC_SAFE_SW_SHIFT          (3U)
#define MC_CGM_SLC_12_CSC_SAFE_SW_WIDTH          (1U)
#define MC_CGM_SLC_12_CSC_SAFE_SW(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_12_CSC_SAFE_SW_SHIFT)) & MC_CGM_SLC_12_CSC_SAFE_SW_MASK)

#define MC_CGM_SLC_12_CSC_SELCTL_MASK            (0x3F000000U)
#define MC_CGM_SLC_12_CSC_SELCTL_SHIFT           (24U)
#define MC_CGM_SLC_12_CSC_SELCTL_WIDTH           (6U)
#define MC_CGM_SLC_12_CSC_SELCTL(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_12_CSC_SELCTL_SHIFT)) & MC_CGM_SLC_12_CSC_SELCTL_MASK)
/*! @} */

/*! @name SLC_12_CSS - Clock Slice 12 Select Status */
/*! @{ */

#define MC_CGM_SLC_12_CSS_SWIP_MASK              (0x4U)
#define MC_CGM_SLC_12_CSS_SWIP_SHIFT             (2U)
#define MC_CGM_SLC_12_CSS_SWIP_WIDTH             (1U)
#define MC_CGM_SLC_12_CSS_SWIP(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_12_CSS_SWIP_SHIFT)) & MC_CGM_SLC_12_CSS_SWIP_MASK)

#define MC_CGM_SLC_12_CSS_SAFESWIP_MASK          (0x8U)
#define MC_CGM_SLC_12_CSS_SAFESWIP_SHIFT         (3U)
#define MC_CGM_SLC_12_CSS_SAFESWIP_WIDTH         (1U)
#define MC_CGM_SLC_12_CSS_SAFESWIP(x)            (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_12_CSS_SAFESWIP_SHIFT)) & MC_CGM_SLC_12_CSS_SAFESWIP_MASK)

#define MC_CGM_SLC_12_CSS_SWTRG_MASK             (0x70000U)
#define MC_CGM_SLC_12_CSS_SWTRG_SHIFT            (16U)
#define MC_CGM_SLC_12_CSS_SWTRG_WIDTH            (3U)
#define MC_CGM_SLC_12_CSS_SWTRG(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_12_CSS_SWTRG_SHIFT)) & MC_CGM_SLC_12_CSS_SWTRG_MASK)

#define MC_CGM_SLC_12_CSS_SELSTAT_MASK           (0x3F000000U)
#define MC_CGM_SLC_12_CSS_SELSTAT_SHIFT          (24U)
#define MC_CGM_SLC_12_CSS_SELSTAT_WIDTH          (6U)
#define MC_CGM_SLC_12_CSS_SELSTAT(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_12_CSS_SELSTAT_SHIFT)) & MC_CGM_SLC_12_CSS_SELSTAT_MASK)
/*! @} */

/*! @name SLC_12_DC_0 - Clock Slice 12 Divider 0 Control */
/*! @{ */

#define MC_CGM_SLC_12_DC_0_DIV_MASK              (0xF0000U)
#define MC_CGM_SLC_12_DC_0_DIV_SHIFT             (16U)
#define MC_CGM_SLC_12_DC_0_DIV_WIDTH             (4U)
#define MC_CGM_SLC_12_DC_0_DIV(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_12_DC_0_DIV_SHIFT)) & MC_CGM_SLC_12_DC_0_DIV_MASK)

#define MC_CGM_SLC_12_DC_0_DE_MASK               (0x80000000U)
#define MC_CGM_SLC_12_DC_0_DE_SHIFT              (31U)
#define MC_CGM_SLC_12_DC_0_DE_WIDTH              (1U)
#define MC_CGM_SLC_12_DC_0_DE(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_12_DC_0_DE_SHIFT)) & MC_CGM_SLC_12_DC_0_DE_MASK)
/*! @} */

/*! @name SLC_12_DIV_UPD_STAT - Clock Slice 12 Divider Update Status */
/*! @{ */

#define MC_CGM_SLC_12_DIV_UPD_STAT_DIV_STAT_MASK (0x1U)
#define MC_CGM_SLC_12_DIV_UPD_STAT_DIV_STAT_SHIFT (0U)
#define MC_CGM_SLC_12_DIV_UPD_STAT_DIV_STAT_WIDTH (1U)
#define MC_CGM_SLC_12_DIV_UPD_STAT_DIV_STAT(x)   (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_12_DIV_UPD_STAT_DIV_STAT_SHIFT)) & MC_CGM_SLC_12_DIV_UPD_STAT_DIV_STAT_MASK)
/*! @} */

/*! @name SLC_13_CSC - Clock Slice 13 Select Control */
/*! @{ */

#define MC_CGM_SLC_13_CSC_CLK_SW_MASK            (0x4U)
#define MC_CGM_SLC_13_CSC_CLK_SW_SHIFT           (2U)
#define MC_CGM_SLC_13_CSC_CLK_SW_WIDTH           (1U)
#define MC_CGM_SLC_13_CSC_CLK_SW(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_13_CSC_CLK_SW_SHIFT)) & MC_CGM_SLC_13_CSC_CLK_SW_MASK)

#define MC_CGM_SLC_13_CSC_SAFE_SW_MASK           (0x8U)
#define MC_CGM_SLC_13_CSC_SAFE_SW_SHIFT          (3U)
#define MC_CGM_SLC_13_CSC_SAFE_SW_WIDTH          (1U)
#define MC_CGM_SLC_13_CSC_SAFE_SW(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_13_CSC_SAFE_SW_SHIFT)) & MC_CGM_SLC_13_CSC_SAFE_SW_MASK)

#define MC_CGM_SLC_13_CSC_SELCTL_MASK            (0x3F000000U)
#define MC_CGM_SLC_13_CSC_SELCTL_SHIFT           (24U)
#define MC_CGM_SLC_13_CSC_SELCTL_WIDTH           (6U)
#define MC_CGM_SLC_13_CSC_SELCTL(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_13_CSC_SELCTL_SHIFT)) & MC_CGM_SLC_13_CSC_SELCTL_MASK)
/*! @} */

/*! @name SLC_13_CSS - Clock Slice 13 Select Status */
/*! @{ */

#define MC_CGM_SLC_13_CSS_SWIP_MASK              (0x4U)
#define MC_CGM_SLC_13_CSS_SWIP_SHIFT             (2U)
#define MC_CGM_SLC_13_CSS_SWIP_WIDTH             (1U)
#define MC_CGM_SLC_13_CSS_SWIP(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_13_CSS_SWIP_SHIFT)) & MC_CGM_SLC_13_CSS_SWIP_MASK)

#define MC_CGM_SLC_13_CSS_SAFESWIP_MASK          (0x8U)
#define MC_CGM_SLC_13_CSS_SAFESWIP_SHIFT         (3U)
#define MC_CGM_SLC_13_CSS_SAFESWIP_WIDTH         (1U)
#define MC_CGM_SLC_13_CSS_SAFESWIP(x)            (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_13_CSS_SAFESWIP_SHIFT)) & MC_CGM_SLC_13_CSS_SAFESWIP_MASK)

#define MC_CGM_SLC_13_CSS_SWTRG_MASK             (0x70000U)
#define MC_CGM_SLC_13_CSS_SWTRG_SHIFT            (16U)
#define MC_CGM_SLC_13_CSS_SWTRG_WIDTH            (3U)
#define MC_CGM_SLC_13_CSS_SWTRG(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_13_CSS_SWTRG_SHIFT)) & MC_CGM_SLC_13_CSS_SWTRG_MASK)

#define MC_CGM_SLC_13_CSS_SELSTAT_MASK           (0x3F000000U)
#define MC_CGM_SLC_13_CSS_SELSTAT_SHIFT          (24U)
#define MC_CGM_SLC_13_CSS_SELSTAT_WIDTH          (6U)
#define MC_CGM_SLC_13_CSS_SELSTAT(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_13_CSS_SELSTAT_SHIFT)) & MC_CGM_SLC_13_CSS_SELSTAT_MASK)
/*! @} */

/*! @name SLC_13_DC_0 - Clock Slice 13 Divider 0 Control */
/*! @{ */

#define MC_CGM_SLC_13_DC_0_DIV_MASK              (0xFF0000U)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
#define MC_CGM_SLC_13_DC_0_DIV_SHIFT             (16U)
#define MC_CGM_SLC_13_DC_0_DIV_WIDTH             (8U)
#define MC_CGM_SLC_13_DC_0_DIV(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_13_DC_0_DIV_SHIFT)) & MC_CGM_SLC_13_DC_0_DIV_MASK)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */

#define MC_CGM_SLC_13_DC_0_DE_MASK               (0x80000000U)
#define MC_CGM_SLC_13_DC_0_DE_SHIFT              (31U)
#define MC_CGM_SLC_13_DC_0_DE_WIDTH              (1U)
#define MC_CGM_SLC_13_DC_0_DE(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_13_DC_0_DE_SHIFT)) & MC_CGM_SLC_13_DC_0_DE_MASK)
/*! @} */

/*! @name SLC_13_DIV_UPD_STAT - Clock Slice 13 Divider Update Status */
/*! @{ */

#define MC_CGM_SLC_13_DIV_UPD_STAT_DIV_STAT_MASK (0x1U)
#define MC_CGM_SLC_13_DIV_UPD_STAT_DIV_STAT_SHIFT (0U)
#define MC_CGM_SLC_13_DIV_UPD_STAT_DIV_STAT_WIDTH (1U)
#define MC_CGM_SLC_13_DIV_UPD_STAT_DIV_STAT(x)   (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_13_DIV_UPD_STAT_DIV_STAT_SHIFT)) & MC_CGM_SLC_13_DIV_UPD_STAT_DIV_STAT_MASK)
/*! @} */

/*! @name SLC_14_CSC - Clock Slice 14 Select Control */
/*! @{ */

#define MC_CGM_SLC_14_CSC_CLK_SW_MASK            (0x4U)
#define MC_CGM_SLC_14_CSC_CLK_SW_SHIFT           (2U)
#define MC_CGM_SLC_14_CSC_CLK_SW_WIDTH           (1U)
#define MC_CGM_SLC_14_CSC_CLK_SW(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_14_CSC_CLK_SW_SHIFT)) & MC_CGM_SLC_14_CSC_CLK_SW_MASK)

#define MC_CGM_SLC_14_CSC_SAFE_SW_MASK           (0x8U)
#define MC_CGM_SLC_14_CSC_SAFE_SW_SHIFT          (3U)
#define MC_CGM_SLC_14_CSC_SAFE_SW_WIDTH          (1U)
#define MC_CGM_SLC_14_CSC_SAFE_SW(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_14_CSC_SAFE_SW_SHIFT)) & MC_CGM_SLC_14_CSC_SAFE_SW_MASK)

#define MC_CGM_SLC_14_CSC_SELCTL_MASK            (0x3F000000U)
#define MC_CGM_SLC_14_CSC_SELCTL_SHIFT           (24U)
#define MC_CGM_SLC_14_CSC_SELCTL_WIDTH           (6U)
#define MC_CGM_SLC_14_CSC_SELCTL(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_14_CSC_SELCTL_SHIFT)) & MC_CGM_SLC_14_CSC_SELCTL_MASK)
/*! @} */

/*! @name SLC_14_CSS - Clock Slice 14 Select Status */
/*! @{ */

#define MC_CGM_SLC_14_CSS_SWIP_MASK              (0x4U)
#define MC_CGM_SLC_14_CSS_SWIP_SHIFT             (2U)
#define MC_CGM_SLC_14_CSS_SWIP_WIDTH             (1U)
#define MC_CGM_SLC_14_CSS_SWIP(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_14_CSS_SWIP_SHIFT)) & MC_CGM_SLC_14_CSS_SWIP_MASK)

#define MC_CGM_SLC_14_CSS_SAFESWIP_MASK          (0x8U)
#define MC_CGM_SLC_14_CSS_SAFESWIP_SHIFT         (3U)
#define MC_CGM_SLC_14_CSS_SAFESWIP_WIDTH         (1U)
#define MC_CGM_SLC_14_CSS_SAFESWIP(x)            (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_14_CSS_SAFESWIP_SHIFT)) & MC_CGM_SLC_14_CSS_SAFESWIP_MASK)

#define MC_CGM_SLC_14_CSS_SWTRG_MASK             (0x70000U)
#define MC_CGM_SLC_14_CSS_SWTRG_SHIFT            (16U)
#define MC_CGM_SLC_14_CSS_SWTRG_WIDTH            (3U)
#define MC_CGM_SLC_14_CSS_SWTRG(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_14_CSS_SWTRG_SHIFT)) & MC_CGM_SLC_14_CSS_SWTRG_MASK)

#define MC_CGM_SLC_14_CSS_SELSTAT_MASK           (0x3F000000U)
#define MC_CGM_SLC_14_CSS_SELSTAT_SHIFT          (24U)
#define MC_CGM_SLC_14_CSS_SELSTAT_WIDTH          (6U)
#define MC_CGM_SLC_14_CSS_SELSTAT(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_14_CSS_SELSTAT_SHIFT)) & MC_CGM_SLC_14_CSS_SELSTAT_MASK)
/*! @} */

/*! @name SLC_14_DC_0 - Clock Slice 14 Divider 0 Control */
/*! @{ */

#define MC_CGM_SLC_14_DC_0_DIV_MASK              (0xF0000U)
#define MC_CGM_SLC_14_DC_0_DIV_SHIFT             (16U)
#define MC_CGM_SLC_14_DC_0_DIV_WIDTH             (4U)
#define MC_CGM_SLC_14_DC_0_DIV(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_14_DC_0_DIV_SHIFT)) & MC_CGM_SLC_14_DC_0_DIV_MASK)

#define MC_CGM_SLC_14_DC_0_DE_MASK               (0x80000000U)
#define MC_CGM_SLC_14_DC_0_DE_SHIFT              (31U)
#define MC_CGM_SLC_14_DC_0_DE_WIDTH              (1U)
#define MC_CGM_SLC_14_DC_0_DE(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_14_DC_0_DE_SHIFT)) & MC_CGM_SLC_14_DC_0_DE_MASK)
/*! @} */

/*! @name SLC_14_DIV_UPD_STAT - Clock Slice 14 Divider Update Status */
/*! @{ */

#define MC_CGM_SLC_14_DIV_UPD_STAT_DIV_STAT_MASK (0x1U)
#define MC_CGM_SLC_14_DIV_UPD_STAT_DIV_STAT_SHIFT (0U)
#define MC_CGM_SLC_14_DIV_UPD_STAT_DIV_STAT_WIDTH (1U)
#define MC_CGM_SLC_14_DIV_UPD_STAT_DIV_STAT(x)   (((uint32_t)(((uint32_t)(x)) << MC_CGM_SLC_14_DIV_UPD_STAT_DIV_STAT_SHIFT)) & MC_CGM_SLC_14_DIV_UPD_STAT_DIV_STAT_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group MC_CGM_Register_Masks */

/*!
 * @}
 */ /* end of group MC_CGM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_MC_CGM_H_) */
