/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_CANXL_FILTER_BANK.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_CANXL_FILTER_BANK
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
#if !defined(S32Z2_CANXL_FILTER_BANK_H_)  /* Check if memory map has not been already included */
#define S32Z2_CANXL_FILTER_BANK_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CANXL_FILTER_BANK Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CANXL_FILTER_BANK_Peripheral_Access_Layer CANXL_FILTER_BANK Peripheral Access Layer
 * @{
 */

/** CANXL_FILTER_BANK - Register Layout Typedef */
typedef struct {
  __IO uint32_t AFCFG0;                            /**< Acceptance Filter Configuration, offset: 0x0 */
  __IO uint32_t VAMRCFG0;                          /**< VCAN Acceptance Mask or Range Configuration, offset: 0x4 */
  __IO uint32_t SAMRCFG0;                          /**< SDU Acceptance Mask or Range Configuration, offset: 0x8 */
  __IO uint32_t AAMRCFG0;                          /**< ADDR Acceptance Mask or Range Configuration, offset: 0xC */
  uint8_t RESERVED_0[12];
  __IO uint32_t VAFLT0_0;                          /**< VCAN Acceptance Filter, offset: 0x1C */
  __IO uint32_t VAFLT0_2;                          /**< VCAN Acceptance Filter, offset: 0x20 */
  __IO uint32_t VAFLT0_4;                          /**< VCAN Acceptance Filter, offset: 0x24 */
  __IO uint32_t VAFLT0_6;                          /**< VCAN Acceptance Filter, offset: 0x28 */
  __IO uint32_t VAFLT0_8;                          /**< VCAN Acceptance Filter, offset: 0x2C */
  __IO uint32_t VAFLT0_10;                         /**< VCAN Acceptance Filter, offset: 0x30 */
  __IO uint32_t VAFLT0_12;                         /**< VCAN Acceptance Filter, offset: 0x34 */
  __IO uint32_t VAFLT0_14;                         /**< VCAN Acceptance Filter, offset: 0x38 */
  __IO uint32_t VAFLT0_16;                         /**< VCAN Acceptance Filter, offset: 0x3C */
  __IO uint32_t VAFLT0_18;                         /**< VCAN Acceptance Filter, offset: 0x40 */
  __IO uint32_t VAFLT0_20;                         /**< VCAN Acceptance Filter, offset: 0x44 */
  __IO uint32_t VAFLT0_22;                         /**< VCAN Acceptance Filter, offset: 0x48 */
  __IO uint32_t VAFLT0_24;                         /**< VCAN Acceptance Filter, offset: 0x4C */
  __IO uint32_t VAFLT0_26;                         /**< VCAN Acceptance Filter, offset: 0x50 */
  __IO uint32_t VAFLT0_28;                         /**< VCAN Acceptance Filter, offset: 0x54 */
  __IO uint32_t VAFLT0_30;                         /**< VCAN Acceptance Filter, offset: 0x58 */
  __IO uint32_t SAFLT0_0;                          /**< SDU Acceptance Filter, offset: 0x5C */
  __IO uint32_t SAFLT0_2;                          /**< SDU Acceptance Filter, offset: 0x60 */
  __IO uint32_t SAFLT0_4;                          /**< SDU Acceptance Filter, offset: 0x64 */
  __IO uint32_t SAFLT0_6;                          /**< SDU Acceptance Filter, offset: 0x68 */
  __IO uint32_t SAFLT0_8;                          /**< SDU Acceptance Filter, offset: 0x6C */
  __IO uint32_t SAFLT0_10;                         /**< SDU Acceptance Filter, offset: 0x70 */
  __IO uint32_t SAFLT0_12;                         /**< SDU Acceptance Filter, offset: 0x74 */
  __IO uint32_t SAFLT0_14;                         /**< SDU Acceptance Filter, offset: 0x78 */
  __IO uint32_t SAFLT0_16;                         /**< SDU Acceptance Filter, offset: 0x7C */
  __IO uint32_t SAFLT0_18;                         /**< SDU Acceptance Filter, offset: 0x80 */
  __IO uint32_t SAFLT0_20;                         /**< SDU Acceptance Filter, offset: 0x84 */
  __IO uint32_t SAFLT0_22;                         /**< SDU Acceptance Filter, offset: 0x88 */
  __IO uint32_t SAFLT0_24;                         /**< SDU Acceptance Filter, offset: 0x8C */
  __IO uint32_t SAFLT0_26;                         /**< SDU Acceptance Filter, offset: 0x90 */
  __IO uint32_t SAFLT0_28;                         /**< SDU Acceptance Filter, offset: 0x94 */
  __IO uint32_t SAFLT0_30;                         /**< SDU Acceptance Filter, offset: 0x98 */
  __IO uint32_t AAFLT0_0L;                         /**< ADDR Acceptance Filter Low, offset: 0x9C */
  __IO uint32_t AAFLT0_0H;                         /**< ADDR Acceptance Filter High, offset: 0xA0 */
  __IO uint32_t AAFLT0_1L;                         /**< ADDR Acceptance Filter Low, offset: 0xA4 */
  __IO uint32_t AAFLT0_1H;                         /**< ADDR Acceptance Filter High, offset: 0xA8 */
  __IO uint32_t AAFLT0_2L;                         /**< ADDR Acceptance Filter Low, offset: 0xAC */
  __IO uint32_t AAFLT0_2H;                         /**< ADDR Acceptance Filter High, offset: 0xB0 */
  __IO uint32_t AAFLT0_3L;                         /**< ADDR Acceptance Filter Low, offset: 0xB4 */
  __IO uint32_t AAFLT0_3H;                         /**< ADDR Acceptance Filter High, offset: 0xB8 */
  __IO uint32_t AAFLT0_4L;                         /**< ADDR Acceptance Filter Low, offset: 0xBC */
  __IO uint32_t AAFLT0_4H;                         /**< ADDR Acceptance Filter High, offset: 0xC0 */
  __IO uint32_t AAFLT0_5L;                         /**< ADDR Acceptance Filter Low, offset: 0xC4 */
  __IO uint32_t AAFLT0_5H;                         /**< ADDR Acceptance Filter High, offset: 0xC8 */
  __IO uint32_t AAFLT0_6L;                         /**< ADDR Acceptance Filter Low, offset: 0xCC */
  __IO uint32_t AAFLT0_6H;                         /**< ADDR Acceptance Filter High, offset: 0xD0 */
  __IO uint32_t AAFLT0_7L;                         /**< ADDR Acceptance Filter Low, offset: 0xD4 */
  __IO uint32_t AAFLT0_7H;                         /**< ADDR Acceptance Filter High, offset: 0xD8 */
  __IO uint32_t AAFLT0_8L;                         /**< ADDR Acceptance Filter Low, offset: 0xDC */
  __IO uint32_t AAFLT0_8H;                         /**< ADDR Acceptance Filter High, offset: 0xE0 */
  __IO uint32_t AAFLT0_9L;                         /**< ADDR Acceptance Filter Low, offset: 0xE4 */
  __IO uint32_t AAFLT0_9H;                         /**< ADDR Acceptance Filter High, offset: 0xE8 */
  __IO uint32_t AAFLT0_10L;                        /**< ADDR Acceptance Filter Low, offset: 0xEC */
  __IO uint32_t AAFLT0_10H;                        /**< ADDR Acceptance Filter High, offset: 0xF0 */
  __IO uint32_t AAFLT0_11L;                        /**< ADDR Acceptance Filter Low, offset: 0xF4 */
  __IO uint32_t AAFLT0_11H;                        /**< ADDR Acceptance Filter High, offset: 0xF8 */
  __IO uint32_t AAFLT0_12L;                        /**< ADDR Acceptance Filter Low, offset: 0xFC */
  __IO uint32_t AAFLT0_12H;                        /**< ADDR Acceptance Filter High, offset: 0x100 */
  __IO uint32_t AAFLT0_13L;                        /**< ADDR Acceptance Filter Low, offset: 0x104 */
  __IO uint32_t AAFLT0_13H;                        /**< ADDR Acceptance Filter High, offset: 0x108 */
  __IO uint32_t AAFLT0_14L;                        /**< ADDR Acceptance Filter Low, offset: 0x10C */
  __IO uint32_t AAFLT0_14H;                        /**< ADDR Acceptance Filter High, offset: 0x110 */
  __IO uint32_t AAFLT0_15L;                        /**< ADDR Acceptance Filter Low, offset: 0x114 */
  __IO uint32_t AAFLT0_15H;                        /**< ADDR Acceptance Filter High, offset: 0x118 */
  __IO uint32_t AAFLT0_16L;                        /**< ADDR Acceptance Filter Low, offset: 0x11C */
  __IO uint32_t AAFLT0_16H;                        /**< ADDR Acceptance Filter High, offset: 0x120 */
  __IO uint32_t AAFLT0_17L;                        /**< ADDR Acceptance Filter Low, offset: 0x124 */
  __IO uint32_t AAFLT0_17H;                        /**< ADDR Acceptance Filter High, offset: 0x128 */
  __IO uint32_t AAFLT0_18L;                        /**< ADDR Acceptance Filter Low, offset: 0x12C */
  __IO uint32_t AAFLT0_18H;                        /**< ADDR Acceptance Filter High, offset: 0x130 */
  __IO uint32_t AAFLT0_19L;                        /**< ADDR Acceptance Filter Low, offset: 0x134 */
  __IO uint32_t AAFLT0_19H;                        /**< ADDR Acceptance Filter High, offset: 0x138 */
  __IO uint32_t AAFLT0_20L;                        /**< ADDR Acceptance Filter Low, offset: 0x13C */
  __IO uint32_t AAFLT0_20H;                        /**< ADDR Acceptance Filter High, offset: 0x140 */
  __IO uint32_t AAFLT0_21L;                        /**< ADDR Acceptance Filter Low, offset: 0x144 */
  __IO uint32_t AAFLT0_21H;                        /**< ADDR Acceptance Filter High, offset: 0x148 */
  __IO uint32_t AAFLT0_22L;                        /**< ADDR Acceptance Filter Low, offset: 0x14C */
  __IO uint32_t AAFLT0_22H;                        /**< ADDR Acceptance Filter High, offset: 0x150 */
  __IO uint32_t AAFLT0_23L;                        /**< ADDR Acceptance Filter Low, offset: 0x154 */
  __IO uint32_t AAFLT0_23H;                        /**< ADDR Acceptance Filter High, offset: 0x158 */
  __IO uint32_t AAFLT0_24L;                        /**< ADDR Acceptance Filter Low, offset: 0x15C */
  __IO uint32_t AAFLT0_24H;                        /**< ADDR Acceptance Filter High, offset: 0x160 */
  __IO uint32_t AAFLT0_25L;                        /**< ADDR Acceptance Filter Low, offset: 0x164 */
  __IO uint32_t AAFLT0_25H;                        /**< ADDR Acceptance Filter High, offset: 0x168 */
  __IO uint32_t AAFLT0_26L;                        /**< ADDR Acceptance Filter Low, offset: 0x16C */
  __IO uint32_t AAFLT0_26H;                        /**< ADDR Acceptance Filter High, offset: 0x170 */
  __IO uint32_t AAFLT0_27L;                        /**< ADDR Acceptance Filter Low, offset: 0x174 */
  __IO uint32_t AAFLT0_27H;                        /**< ADDR Acceptance Filter High, offset: 0x178 */
  __IO uint32_t AAFLT0_28L;                        /**< ADDR Acceptance Filter Low, offset: 0x17C */
  __IO uint32_t AAFLT0_28H;                        /**< ADDR Acceptance Filter High, offset: 0x180 */
  __IO uint32_t AAFLT0_29L;                        /**< ADDR Acceptance Filter Low, offset: 0x184 */
  __IO uint32_t AAFLT0_29H;                        /**< ADDR Acceptance Filter High, offset: 0x188 */
  __IO uint32_t AAFLT0_30L;                        /**< ADDR Acceptance Filter Low, offset: 0x18C */
  __IO uint32_t AAFLT0_30H;                        /**< ADDR Acceptance Filter High, offset: 0x190 */
  __IO uint32_t AAFLT0_31L;                        /**< ADDR Acceptance Filter Low, offset: 0x194 */
  __IO uint32_t AAFLT0_31H;                        /**< ADDR Acceptance Filter High, offset: 0x198 */
  uint8_t RESERVED_1[100];
  __IO uint32_t RFCFG0;                            /**< Rejection Filter Configuration, offset: 0x200 */
  __IO uint32_t VRMRCFG0;                          /**< VCAN Rejection Mask or Range Configuration, offset: 0x204 */
  __IO uint32_t SRMRCFG0;                          /**< SDU Rejection Mask or Range Configuration, offset: 0x208 */
  __IO uint32_t ARMRCFG0;                          /**< ADDR Rejection Mask or Range Configuration, offset: 0x20C */
  uint8_t RESERVED_2[12];
  __IO uint32_t VRFLT0_0;                          /**< VCAN Rejection Filter, offset: 0x21C */
  __IO uint32_t VRFLT0_2;                          /**< VCAN Rejection Filter, offset: 0x220 */
  __IO uint32_t VRFLT0_4;                          /**< VCAN Rejection Filter, offset: 0x224 */
  __IO uint32_t VRFLT0_6;                          /**< VCAN Rejection Filter, offset: 0x228 */
  __IO uint32_t VRFLT0_8;                          /**< VCAN Rejection Filter, offset: 0x22C */
  __IO uint32_t VRFLT0_10;                         /**< VCAN Rejection Filter, offset: 0x230 */
  __IO uint32_t VRFLT0_12;                         /**< VCAN Rejection Filter, offset: 0x234 */
  __IO uint32_t VRFLT0_14;                         /**< VCAN Rejection Filter, offset: 0x238 */
  __IO uint32_t VRFLT0_16;                         /**< VCAN Rejection Filter, offset: 0x23C */
  __IO uint32_t VRFLT0_18;                         /**< VCAN Rejection Filter, offset: 0x240 */
  __IO uint32_t VRFLT0_20;                         /**< VCAN Rejection Filter, offset: 0x244 */
  __IO uint32_t VRFLT0_22;                         /**< VCAN Rejection Filter, offset: 0x248 */
  __IO uint32_t VRFLT0_24;                         /**< VCAN Rejection Filter, offset: 0x24C */
  __IO uint32_t VRFLT0_26;                         /**< VCAN Rejection Filter, offset: 0x250 */
  __IO uint32_t VRFLT0_28;                         /**< VCAN Rejection Filter, offset: 0x254 */
  __IO uint32_t VRFLT0_30;                         /**< VCAN Rejection Filter, offset: 0x258 */
  __IO uint32_t SRFLT0_0;                          /**< SDU Rejection Filter, offset: 0x25C */
  __IO uint32_t SRFLT0_2;                          /**< SDU Rejection Filter, offset: 0x260 */
  __IO uint32_t SRFLT0_4;                          /**< SDU Rejection Filter, offset: 0x264 */
  __IO uint32_t SRFLT0_6;                          /**< SDU Rejection Filter, offset: 0x268 */
  __IO uint32_t SRFLT0_8;                          /**< SDU Rejection Filter, offset: 0x26C */
  __IO uint32_t SRFLT0_10;                         /**< SDU Rejection Filter, offset: 0x270 */
  __IO uint32_t SRFLT0_12;                         /**< SDU Rejection Filter, offset: 0x274 */
  __IO uint32_t SRFLT0_14;                         /**< SDU Rejection Filter, offset: 0x278 */
  __IO uint32_t SRFLT0_16;                         /**< SDU Rejection Filter, offset: 0x27C */
  __IO uint32_t SRFLT0_18;                         /**< SDU Rejection Filter, offset: 0x280 */
  __IO uint32_t SRFLT0_20;                         /**< SDU Rejection Filter, offset: 0x284 */
  __IO uint32_t SRFLT0_22;                         /**< SDU Rejection Filter, offset: 0x288 */
  __IO uint32_t SRFLT0_24;                         /**< SDU Rejection Filter, offset: 0x28C */
  __IO uint32_t SRFLT0_26;                         /**< SDU Rejection Filter, offset: 0x290 */
  __IO uint32_t SRFLT0_28;                         /**< SDU Rejection Filter, offset: 0x294 */
  __IO uint32_t SRFLT0_30;                         /**< SDU Rejection Filter, offset: 0x298 */
  __IO uint32_t ARFLT0_0L;                         /**< ADDR Rejection Filter Low, offset: 0x29C */
  __IO uint32_t ARFLT0_0H;                         /**< ADDR Rejection Filter High, offset: 0x2A0 */
  __IO uint32_t ARFLT0_1L;                         /**< ADDR Rejection Filter Low, offset: 0x2A4 */
  __IO uint32_t ARFLT0_1H;                         /**< ADDR Rejection Filter High, offset: 0x2A8 */
  __IO uint32_t ARFLT0_2L;                         /**< ADDR Rejection Filter Low, offset: 0x2AC */
  __IO uint32_t ARFLT0_2H;                         /**< ADDR Rejection Filter High, offset: 0x2B0 */
  __IO uint32_t ARFLT0_3L;                         /**< ADDR Rejection Filter Low, offset: 0x2B4 */
  __IO uint32_t ARFLT0_3H;                         /**< ADDR Rejection Filter High, offset: 0x2B8 */
  __IO uint32_t ARFLT0_4L;                         /**< ADDR Rejection Filter Low, offset: 0x2BC */
  __IO uint32_t ARFLT0_4H;                         /**< ADDR Rejection Filter High, offset: 0x2C0 */
  __IO uint32_t ARFLT0_5L;                         /**< ADDR Rejection Filter Low, offset: 0x2C4 */
  __IO uint32_t ARFLT0_5H;                         /**< ADDR Rejection Filter High, offset: 0x2C8 */
  __IO uint32_t ARFLT0_6L;                         /**< ADDR Rejection Filter Low, offset: 0x2CC */
  __IO uint32_t ARFLT0_6H;                         /**< ADDR Rejection Filter High, offset: 0x2D0 */
  __IO uint32_t ARFLT0_7L;                         /**< ADDR Rejection Filter Low, offset: 0x2D4 */
  __IO uint32_t ARFLT0_7H;                         /**< ADDR Rejection Filter High, offset: 0x2D8 */
  __IO uint32_t ARFLT0_8L;                         /**< ADDR Rejection Filter Low, offset: 0x2DC */
  __IO uint32_t ARFLT0_8H;                         /**< ADDR Rejection Filter High, offset: 0x2E0 */
  __IO uint32_t ARFLT0_9L;                         /**< ADDR Rejection Filter Low, offset: 0x2E4 */
  __IO uint32_t ARFLT0_9H;                         /**< ADDR Rejection Filter High, offset: 0x2E8 */
  __IO uint32_t ARFLT0_10L;                        /**< ADDR Rejection Filter Low, offset: 0x2EC */
  __IO uint32_t ARFLT0_10H;                        /**< ADDR Rejection Filter High, offset: 0x2F0 */
  __IO uint32_t ARFLT0_11L;                        /**< ADDR Rejection Filter Low, offset: 0x2F4 */
  __IO uint32_t ARFLT0_11H;                        /**< ADDR Rejection Filter High, offset: 0x2F8 */
  __IO uint32_t ARFLT0_12L;                        /**< ADDR Rejection Filter Low, offset: 0x2FC */
  __IO uint32_t ARFLT0_12H;                        /**< ADDR Rejection Filter High, offset: 0x300 */
  __IO uint32_t ARFLT0_13L;                        /**< ADDR Rejection Filter Low, offset: 0x304 */
  __IO uint32_t ARFLT0_13H;                        /**< ADDR Rejection Filter High, offset: 0x308 */
  __IO uint32_t ARFLT0_14L;                        /**< ADDR Rejection Filter Low, offset: 0x30C */
  __IO uint32_t ARFLT0_14H;                        /**< ADDR Rejection Filter High, offset: 0x310 */
  __IO uint32_t ARFLT0_15L;                        /**< ADDR Rejection Filter Low, offset: 0x314 */
  __IO uint32_t ARFLT0_15H;                        /**< ADDR Rejection Filter High, offset: 0x318 */
  __IO uint32_t ARFLT0_16L;                        /**< ADDR Rejection Filter Low, offset: 0x31C */
  __IO uint32_t ARFLT0_16H;                        /**< ADDR Rejection Filter High, offset: 0x320 */
  __IO uint32_t ARFLT0_17L;                        /**< ADDR Rejection Filter Low, offset: 0x324 */
  __IO uint32_t ARFLT0_17H;                        /**< ADDR Rejection Filter High, offset: 0x328 */
  __IO uint32_t ARFLT0_18L;                        /**< ADDR Rejection Filter Low, offset: 0x32C */
  __IO uint32_t ARFLT0_18H;                        /**< ADDR Rejection Filter High, offset: 0x330 */
  __IO uint32_t ARFLT0_19L;                        /**< ADDR Rejection Filter Low, offset: 0x334 */
  __IO uint32_t ARFLT0_19H;                        /**< ADDR Rejection Filter High, offset: 0x338 */
  __IO uint32_t ARFLT0_20L;                        /**< ADDR Rejection Filter Low, offset: 0x33C */
  __IO uint32_t ARFLT0_20H;                        /**< ADDR Rejection Filter High, offset: 0x340 */
  __IO uint32_t ARFLT0_21L;                        /**< ADDR Rejection Filter Low, offset: 0x344 */
  __IO uint32_t ARFLT0_21H;                        /**< ADDR Rejection Filter High, offset: 0x348 */
  __IO uint32_t ARFLT0_22L;                        /**< ADDR Rejection Filter Low, offset: 0x34C */
  __IO uint32_t ARFLT0_22H;                        /**< ADDR Rejection Filter High, offset: 0x350 */
  __IO uint32_t ARFLT0_23L;                        /**< ADDR Rejection Filter Low, offset: 0x354 */
  __IO uint32_t ARFLT0_23H;                        /**< ADDR Rejection Filter High, offset: 0x358 */
  __IO uint32_t ARFLT0_24L;                        /**< ADDR Rejection Filter Low, offset: 0x35C */
  __IO uint32_t ARFLT0_24H;                        /**< ADDR Rejection Filter High, offset: 0x360 */
  __IO uint32_t ARFLT0_25L;                        /**< ADDR Rejection Filter Low, offset: 0x364 */
  __IO uint32_t ARFLT0_25H;                        /**< ADDR Rejection Filter High, offset: 0x368 */
  __IO uint32_t ARFLT0_26L;                        /**< ADDR Rejection Filter Low, offset: 0x36C */
  __IO uint32_t ARFLT0_26H;                        /**< ADDR Rejection Filter High, offset: 0x370 */
  __IO uint32_t ARFLT0_27L;                        /**< ADDR Rejection Filter Low, offset: 0x374 */
  __IO uint32_t ARFLT0_27H;                        /**< ADDR Rejection Filter High, offset: 0x378 */
  __IO uint32_t ARFLT0_28L;                        /**< ADDR Rejection Filter Low, offset: 0x37C */
  __IO uint32_t ARFLT0_28H;                        /**< ADDR Rejection Filter High, offset: 0x380 */
  __IO uint32_t ARFLT0_29L;                        /**< ADDR Rejection Filter Low, offset: 0x384 */
  __IO uint32_t ARFLT0_29H;                        /**< ADDR Rejection Filter High, offset: 0x388 */
  __IO uint32_t ARFLT0_30L;                        /**< ADDR Rejection Filter Low, offset: 0x38C */
  __IO uint32_t ARFLT0_30H;                        /**< ADDR Rejection Filter High, offset: 0x390 */
  __IO uint32_t ARFLT0_31L;                        /**< ADDR Rejection Filter Low, offset: 0x394 */
  __IO uint32_t ARFLT0_31H;                        /**< ADDR Rejection Filter High, offset: 0x398 */
  uint8_t RESERVED_3[100];
  __IO uint32_t AFCFG1;                            /**< Acceptance Filter Configuration, offset: 0x400 */
  __IO uint32_t VAMRCFG1;                          /**< VCAN Acceptance Mask or Range Configuration, offset: 0x404 */
  __IO uint32_t SAMRCFG1;                          /**< SDU Acceptance Mask or Range Configuration, offset: 0x408 */
  __IO uint32_t AAMRCFG1;                          /**< ADDR Acceptance Mask or Range Configuration, offset: 0x40C */
  uint8_t RESERVED_4[12];
  __IO uint32_t VAFLT1_0;                          /**< VCAN Acceptance Filter, offset: 0x41C */
  __IO uint32_t VAFLT1_2;                          /**< VCAN Acceptance Filter, offset: 0x420 */
  __IO uint32_t VAFLT1_4;                          /**< VCAN Acceptance Filter, offset: 0x424 */
  __IO uint32_t VAFLT1_6;                          /**< VCAN Acceptance Filter, offset: 0x428 */
  __IO uint32_t VAFLT1_8;                          /**< VCAN Acceptance Filter, offset: 0x42C */
  __IO uint32_t VAFLT1_10;                         /**< VCAN Acceptance Filter, offset: 0x430 */
  __IO uint32_t VAFLT1_12;                         /**< VCAN Acceptance Filter, offset: 0x434 */
  __IO uint32_t VAFLT1_14;                         /**< VCAN Acceptance Filter, offset: 0x438 */
  __IO uint32_t VAFLT1_16;                         /**< VCAN Acceptance Filter, offset: 0x43C */
  __IO uint32_t VAFLT1_18;                         /**< VCAN Acceptance Filter, offset: 0x440 */
  __IO uint32_t VAFLT1_20;                         /**< VCAN Acceptance Filter, offset: 0x444 */
  __IO uint32_t VAFLT1_22;                         /**< VCAN Acceptance Filter, offset: 0x448 */
  __IO uint32_t VAFLT1_24;                         /**< VCAN Acceptance Filter, offset: 0x44C */
  __IO uint32_t VAFLT1_26;                         /**< VCAN Acceptance Filter, offset: 0x450 */
  __IO uint32_t VAFLT1_28;                         /**< VCAN Acceptance Filter, offset: 0x454 */
  __IO uint32_t VAFLT1_30;                         /**< VCAN Acceptance Filter, offset: 0x458 */
  __IO uint32_t SAFLT1_0;                          /**< SDU Acceptance Filter, offset: 0x45C */
  __IO uint32_t SAFLT1_2;                          /**< SDU Acceptance Filter, offset: 0x460 */
  __IO uint32_t SAFLT1_4;                          /**< SDU Acceptance Filter, offset: 0x464 */
  __IO uint32_t SAFLT1_6;                          /**< SDU Acceptance Filter, offset: 0x468 */
  __IO uint32_t SAFLT1_8;                          /**< SDU Acceptance Filter, offset: 0x46C */
  __IO uint32_t SAFLT1_10;                         /**< SDU Acceptance Filter, offset: 0x470 */
  __IO uint32_t SAFLT1_12;                         /**< SDU Acceptance Filter, offset: 0x474 */
  __IO uint32_t SAFLT1_14;                         /**< SDU Acceptance Filter, offset: 0x478 */
  __IO uint32_t SAFLT1_16;                         /**< SDU Acceptance Filter, offset: 0x47C */
  __IO uint32_t SAFLT1_18;                         /**< SDU Acceptance Filter, offset: 0x480 */
  __IO uint32_t SAFLT1_20;                         /**< SDU Acceptance Filter, offset: 0x484 */
  __IO uint32_t SAFLT1_22;                         /**< SDU Acceptance Filter, offset: 0x488 */
  __IO uint32_t SAFLT1_24;                         /**< SDU Acceptance Filter, offset: 0x48C */
  __IO uint32_t SAFLT1_26;                         /**< SDU Acceptance Filter, offset: 0x490 */
  __IO uint32_t SAFLT1_28;                         /**< SDU Acceptance Filter, offset: 0x494 */
  __IO uint32_t SAFLT1_30;                         /**< SDU Acceptance Filter, offset: 0x498 */
  __IO uint32_t AAFLT1_0L;                         /**< ADDR Acceptance Filter Low, offset: 0x49C */
  __IO uint32_t AAFLT1_0H;                         /**< ADDR Acceptance Filter High, offset: 0x4A0 */
  __IO uint32_t AAFLT1_1L;                         /**< ADDR Acceptance Filter Low, offset: 0x4A4 */
  __IO uint32_t AAFLT1_1H;                         /**< ADDR Acceptance Filter High, offset: 0x4A8 */
  __IO uint32_t AAFLT1_2L;                         /**< ADDR Acceptance Filter Low, offset: 0x4AC */
  __IO uint32_t AAFLT1_2H;                         /**< ADDR Acceptance Filter High, offset: 0x4B0 */
  __IO uint32_t AAFLT1_3L;                         /**< ADDR Acceptance Filter Low, offset: 0x4B4 */
  __IO uint32_t AAFLT1_3H;                         /**< ADDR Acceptance Filter High, offset: 0x4B8 */
  __IO uint32_t AAFLT1_4L;                         /**< ADDR Acceptance Filter Low, offset: 0x4BC */
  __IO uint32_t AAFLT1_4H;                         /**< ADDR Acceptance Filter High, offset: 0x4C0 */
  __IO uint32_t AAFLT1_5L;                         /**< ADDR Acceptance Filter Low, offset: 0x4C4 */
  __IO uint32_t AAFLT1_5H;                         /**< ADDR Acceptance Filter High, offset: 0x4C8 */
  __IO uint32_t AAFLT1_6L;                         /**< ADDR Acceptance Filter Low, offset: 0x4CC */
  __IO uint32_t AAFLT1_6H;                         /**< ADDR Acceptance Filter High, offset: 0x4D0 */
  __IO uint32_t AAFLT1_7L;                         /**< ADDR Acceptance Filter Low, offset: 0x4D4 */
  __IO uint32_t AAFLT1_7H;                         /**< ADDR Acceptance Filter High, offset: 0x4D8 */
  __IO uint32_t AAFLT1_8L;                         /**< ADDR Acceptance Filter Low, offset: 0x4DC */
  __IO uint32_t AAFLT1_8H;                         /**< ADDR Acceptance Filter High, offset: 0x4E0 */
  __IO uint32_t AAFLT1_9L;                         /**< ADDR Acceptance Filter Low, offset: 0x4E4 */
  __IO uint32_t AAFLT1_9H;                         /**< ADDR Acceptance Filter High, offset: 0x4E8 */
  __IO uint32_t AAFLT1_10L;                        /**< ADDR Acceptance Filter Low, offset: 0x4EC */
  __IO uint32_t AAFLT1_10H;                        /**< ADDR Acceptance Filter High, offset: 0x4F0 */
  __IO uint32_t AAFLT1_11L;                        /**< ADDR Acceptance Filter Low, offset: 0x4F4 */
  __IO uint32_t AAFLT1_11H;                        /**< ADDR Acceptance Filter High, offset: 0x4F8 */
  __IO uint32_t AAFLT1_12L;                        /**< ADDR Acceptance Filter Low, offset: 0x4FC */
  __IO uint32_t AAFLT1_12H;                        /**< ADDR Acceptance Filter High, offset: 0x500 */
  __IO uint32_t AAFLT1_13L;                        /**< ADDR Acceptance Filter Low, offset: 0x504 */
  __IO uint32_t AAFLT1_13H;                        /**< ADDR Acceptance Filter High, offset: 0x508 */
  __IO uint32_t AAFLT1_14L;                        /**< ADDR Acceptance Filter Low, offset: 0x50C */
  __IO uint32_t AAFLT1_14H;                        /**< ADDR Acceptance Filter High, offset: 0x510 */
  __IO uint32_t AAFLT1_15L;                        /**< ADDR Acceptance Filter Low, offset: 0x514 */
  __IO uint32_t AAFLT1_15H;                        /**< ADDR Acceptance Filter High, offset: 0x518 */
  __IO uint32_t AAFLT1_16L;                        /**< ADDR Acceptance Filter Low, offset: 0x51C */
  __IO uint32_t AAFLT1_16H;                        /**< ADDR Acceptance Filter High, offset: 0x520 */
  __IO uint32_t AAFLT1_17L;                        /**< ADDR Acceptance Filter Low, offset: 0x524 */
  __IO uint32_t AAFLT1_17H;                        /**< ADDR Acceptance Filter High, offset: 0x528 */
  __IO uint32_t AAFLT1_18L;                        /**< ADDR Acceptance Filter Low, offset: 0x52C */
  __IO uint32_t AAFLT1_18H;                        /**< ADDR Acceptance Filter High, offset: 0x530 */
  __IO uint32_t AAFLT1_19L;                        /**< ADDR Acceptance Filter Low, offset: 0x534 */
  __IO uint32_t AAFLT1_19H;                        /**< ADDR Acceptance Filter High, offset: 0x538 */
  __IO uint32_t AAFLT1_20L;                        /**< ADDR Acceptance Filter Low, offset: 0x53C */
  __IO uint32_t AAFLT1_20H;                        /**< ADDR Acceptance Filter High, offset: 0x540 */
  __IO uint32_t AAFLT1_21L;                        /**< ADDR Acceptance Filter Low, offset: 0x544 */
  __IO uint32_t AAFLT1_21H;                        /**< ADDR Acceptance Filter High, offset: 0x548 */
  __IO uint32_t AAFLT1_22L;                        /**< ADDR Acceptance Filter Low, offset: 0x54C */
  __IO uint32_t AAFLT1_22H;                        /**< ADDR Acceptance Filter High, offset: 0x550 */
  __IO uint32_t AAFLT1_23L;                        /**< ADDR Acceptance Filter Low, offset: 0x554 */
  __IO uint32_t AAFLT1_23H;                        /**< ADDR Acceptance Filter High, offset: 0x558 */
  __IO uint32_t AAFLT1_24L;                        /**< ADDR Acceptance Filter Low, offset: 0x55C */
  __IO uint32_t AAFLT1_24H;                        /**< ADDR Acceptance Filter High, offset: 0x560 */
  __IO uint32_t AAFLT1_25L;                        /**< ADDR Acceptance Filter Low, offset: 0x564 */
  __IO uint32_t AAFLT1_25H;                        /**< ADDR Acceptance Filter High, offset: 0x568 */
  __IO uint32_t AAFLT1_26L;                        /**< ADDR Acceptance Filter Low, offset: 0x56C */
  __IO uint32_t AAFLT1_26H;                        /**< ADDR Acceptance Filter High, offset: 0x570 */
  __IO uint32_t AAFLT1_27L;                        /**< ADDR Acceptance Filter Low, offset: 0x574 */
  __IO uint32_t AAFLT1_27H;                        /**< ADDR Acceptance Filter High, offset: 0x578 */
  __IO uint32_t AAFLT1_28L;                        /**< ADDR Acceptance Filter Low, offset: 0x57C */
  __IO uint32_t AAFLT1_28H;                        /**< ADDR Acceptance Filter High, offset: 0x580 */
  __IO uint32_t AAFLT1_29L;                        /**< ADDR Acceptance Filter Low, offset: 0x584 */
  __IO uint32_t AAFLT1_29H;                        /**< ADDR Acceptance Filter High, offset: 0x588 */
  __IO uint32_t AAFLT1_30L;                        /**< ADDR Acceptance Filter Low, offset: 0x58C */
  __IO uint32_t AAFLT1_30H;                        /**< ADDR Acceptance Filter High, offset: 0x590 */
  __IO uint32_t AAFLT1_31L;                        /**< ADDR Acceptance Filter Low, offset: 0x594 */
  __IO uint32_t AAFLT1_31H;                        /**< ADDR Acceptance Filter High, offset: 0x598 */
  uint8_t RESERVED_5[100];
  __IO uint32_t RFCFG1;                            /**< Rejection Filter Configuration, offset: 0x600 */
  __IO uint32_t VRMRCFG1;                          /**< VCAN Rejection Mask or Range Configuration, offset: 0x604 */
  __IO uint32_t SRMRCFG1;                          /**< SDU Rejection Mask or Range Configuration, offset: 0x608 */
  __IO uint32_t ARMRCFG1;                          /**< ADDR Rejection Mask or Range Configuration, offset: 0x60C */
  uint8_t RESERVED_6[12];
  __IO uint32_t VRFLT1_0;                          /**< VCAN Rejection Filter, offset: 0x61C */
  __IO uint32_t VRFLT1_2;                          /**< VCAN Rejection Filter, offset: 0x620 */
  __IO uint32_t VRFLT1_4;                          /**< VCAN Rejection Filter, offset: 0x624 */
  __IO uint32_t VRFLT1_6;                          /**< VCAN Rejection Filter, offset: 0x628 */
  __IO uint32_t VRFLT1_8;                          /**< VCAN Rejection Filter, offset: 0x62C */
  __IO uint32_t VRFLT1_10;                         /**< VCAN Rejection Filter, offset: 0x630 */
  __IO uint32_t VRFLT1_12;                         /**< VCAN Rejection Filter, offset: 0x634 */
  __IO uint32_t VRFLT1_14;                         /**< VCAN Rejection Filter, offset: 0x638 */
  __IO uint32_t VRFLT1_16;                         /**< VCAN Rejection Filter, offset: 0x63C */
  __IO uint32_t VRFLT1_18;                         /**< VCAN Rejection Filter, offset: 0x640 */
  __IO uint32_t VRFLT1_20;                         /**< VCAN Rejection Filter, offset: 0x644 */
  __IO uint32_t VRFLT1_22;                         /**< VCAN Rejection Filter, offset: 0x648 */
  __IO uint32_t VRFLT1_24;                         /**< VCAN Rejection Filter, offset: 0x64C */
  __IO uint32_t VRFLT1_26;                         /**< VCAN Rejection Filter, offset: 0x650 */
  __IO uint32_t VRFLT1_28;                         /**< VCAN Rejection Filter, offset: 0x654 */
  __IO uint32_t VRFLT1_30;                         /**< VCAN Rejection Filter, offset: 0x658 */
  __IO uint32_t SRFLT1_0;                          /**< SDU Rejection Filter, offset: 0x65C */
  __IO uint32_t SRFLT1_2;                          /**< SDU Rejection Filter, offset: 0x660 */
  __IO uint32_t SRFLT1_4;                          /**< SDU Rejection Filter, offset: 0x664 */
  __IO uint32_t SRFLT1_6;                          /**< SDU Rejection Filter, offset: 0x668 */
  __IO uint32_t SRFLT1_8;                          /**< SDU Rejection Filter, offset: 0x66C */
  __IO uint32_t SRFLT1_10;                         /**< SDU Rejection Filter, offset: 0x670 */
  __IO uint32_t SRFLT1_12;                         /**< SDU Rejection Filter, offset: 0x674 */
  __IO uint32_t SRFLT1_14;                         /**< SDU Rejection Filter, offset: 0x678 */
  __IO uint32_t SRFLT1_16;                         /**< SDU Rejection Filter, offset: 0x67C */
  __IO uint32_t SRFLT1_18;                         /**< SDU Rejection Filter, offset: 0x680 */
  __IO uint32_t SRFLT1_20;                         /**< SDU Rejection Filter, offset: 0x684 */
  __IO uint32_t SRFLT1_22;                         /**< SDU Rejection Filter, offset: 0x688 */
  __IO uint32_t SRFLT1_24;                         /**< SDU Rejection Filter, offset: 0x68C */
  __IO uint32_t SRFLT1_26;                         /**< SDU Rejection Filter, offset: 0x690 */
  __IO uint32_t SRFLT1_28;                         /**< SDU Rejection Filter, offset: 0x694 */
  __IO uint32_t SRFLT1_30;                         /**< SDU Rejection Filter, offset: 0x698 */
  __IO uint32_t ARFLT1_0L;                         /**< ADDR Rejection Filter Low, offset: 0x69C */
  __IO uint32_t ARFLT1_0H;                         /**< ADDR Rejection Filter High, offset: 0x6A0 */
  __IO uint32_t ARFLT1_1L;                         /**< ADDR Rejection Filter Low, offset: 0x6A4 */
  __IO uint32_t ARFLT1_1H;                         /**< ADDR Rejection Filter High, offset: 0x6A8 */
  __IO uint32_t ARFLT1_2L;                         /**< ADDR Rejection Filter Low, offset: 0x6AC */
  __IO uint32_t ARFLT1_2H;                         /**< ADDR Rejection Filter High, offset: 0x6B0 */
  __IO uint32_t ARFLT1_3L;                         /**< ADDR Rejection Filter Low, offset: 0x6B4 */
  __IO uint32_t ARFLT1_3H;                         /**< ADDR Rejection Filter High, offset: 0x6B8 */
  __IO uint32_t ARFLT1_4L;                         /**< ADDR Rejection Filter Low, offset: 0x6BC */
  __IO uint32_t ARFLT1_4H;                         /**< ADDR Rejection Filter High, offset: 0x6C0 */
  __IO uint32_t ARFLT1_5L;                         /**< ADDR Rejection Filter Low, offset: 0x6C4 */
  __IO uint32_t ARFLT1_5H;                         /**< ADDR Rejection Filter High, offset: 0x6C8 */
  __IO uint32_t ARFLT1_6L;                         /**< ADDR Rejection Filter Low, offset: 0x6CC */
  __IO uint32_t ARFLT1_6H;                         /**< ADDR Rejection Filter High, offset: 0x6D0 */
  __IO uint32_t ARFLT1_7L;                         /**< ADDR Rejection Filter Low, offset: 0x6D4 */
  __IO uint32_t ARFLT1_7H;                         /**< ADDR Rejection Filter High, offset: 0x6D8 */
  __IO uint32_t ARFLT1_8L;                         /**< ADDR Rejection Filter Low, offset: 0x6DC */
  __IO uint32_t ARFLT1_8H;                         /**< ADDR Rejection Filter High, offset: 0x6E0 */
  __IO uint32_t ARFLT1_9L;                         /**< ADDR Rejection Filter Low, offset: 0x6E4 */
  __IO uint32_t ARFLT1_9H;                         /**< ADDR Rejection Filter High, offset: 0x6E8 */
  __IO uint32_t ARFLT1_10L;                        /**< ADDR Rejection Filter Low, offset: 0x6EC */
  __IO uint32_t ARFLT1_10H;                        /**< ADDR Rejection Filter High, offset: 0x6F0 */
  __IO uint32_t ARFLT1_11L;                        /**< ADDR Rejection Filter Low, offset: 0x6F4 */
  __IO uint32_t ARFLT1_11H;                        /**< ADDR Rejection Filter High, offset: 0x6F8 */
  __IO uint32_t ARFLT1_12L;                        /**< ADDR Rejection Filter Low, offset: 0x6FC */
  __IO uint32_t ARFLT1_12H;                        /**< ADDR Rejection Filter High, offset: 0x700 */
  __IO uint32_t ARFLT1_13L;                        /**< ADDR Rejection Filter Low, offset: 0x704 */
  __IO uint32_t ARFLT1_13H;                        /**< ADDR Rejection Filter High, offset: 0x708 */
  __IO uint32_t ARFLT1_14L;                        /**< ADDR Rejection Filter Low, offset: 0x70C */
  __IO uint32_t ARFLT1_14H;                        /**< ADDR Rejection Filter High, offset: 0x710 */
  __IO uint32_t ARFLT1_15L;                        /**< ADDR Rejection Filter Low, offset: 0x714 */
  __IO uint32_t ARFLT1_15H;                        /**< ADDR Rejection Filter High, offset: 0x718 */
  __IO uint32_t ARFLT1_16L;                        /**< ADDR Rejection Filter Low, offset: 0x71C */
  __IO uint32_t ARFLT1_16H;                        /**< ADDR Rejection Filter High, offset: 0x720 */
  __IO uint32_t ARFLT1_17L;                        /**< ADDR Rejection Filter Low, offset: 0x724 */
  __IO uint32_t ARFLT1_17H;                        /**< ADDR Rejection Filter High, offset: 0x728 */
  __IO uint32_t ARFLT1_18L;                        /**< ADDR Rejection Filter Low, offset: 0x72C */
  __IO uint32_t ARFLT1_18H;                        /**< ADDR Rejection Filter High, offset: 0x730 */
  __IO uint32_t ARFLT1_19L;                        /**< ADDR Rejection Filter Low, offset: 0x734 */
  __IO uint32_t ARFLT1_19H;                        /**< ADDR Rejection Filter High, offset: 0x738 */
  __IO uint32_t ARFLT1_20L;                        /**< ADDR Rejection Filter Low, offset: 0x73C */
  __IO uint32_t ARFLT1_20H;                        /**< ADDR Rejection Filter High, offset: 0x740 */
  __IO uint32_t ARFLT1_21L;                        /**< ADDR Rejection Filter Low, offset: 0x744 */
  __IO uint32_t ARFLT1_21H;                        /**< ADDR Rejection Filter High, offset: 0x748 */
  __IO uint32_t ARFLT1_22L;                        /**< ADDR Rejection Filter Low, offset: 0x74C */
  __IO uint32_t ARFLT1_22H;                        /**< ADDR Rejection Filter High, offset: 0x750 */
  __IO uint32_t ARFLT1_23L;                        /**< ADDR Rejection Filter Low, offset: 0x754 */
  __IO uint32_t ARFLT1_23H;                        /**< ADDR Rejection Filter High, offset: 0x758 */
  __IO uint32_t ARFLT1_24L;                        /**< ADDR Rejection Filter Low, offset: 0x75C */
  __IO uint32_t ARFLT1_24H;                        /**< ADDR Rejection Filter High, offset: 0x760 */
  __IO uint32_t ARFLT1_25L;                        /**< ADDR Rejection Filter Low, offset: 0x764 */
  __IO uint32_t ARFLT1_25H;                        /**< ADDR Rejection Filter High, offset: 0x768 */
  __IO uint32_t ARFLT1_26L;                        /**< ADDR Rejection Filter Low, offset: 0x76C */
  __IO uint32_t ARFLT1_26H;                        /**< ADDR Rejection Filter High, offset: 0x770 */
  __IO uint32_t ARFLT1_27L;                        /**< ADDR Rejection Filter Low, offset: 0x774 */
  __IO uint32_t ARFLT1_27H;                        /**< ADDR Rejection Filter High, offset: 0x778 */
  __IO uint32_t ARFLT1_28L;                        /**< ADDR Rejection Filter Low, offset: 0x77C */
  __IO uint32_t ARFLT1_28H;                        /**< ADDR Rejection Filter High, offset: 0x780 */
  __IO uint32_t ARFLT1_29L;                        /**< ADDR Rejection Filter Low, offset: 0x784 */
  __IO uint32_t ARFLT1_29H;                        /**< ADDR Rejection Filter High, offset: 0x788 */
  __IO uint32_t ARFLT1_30L;                        /**< ADDR Rejection Filter Low, offset: 0x78C */
  __IO uint32_t ARFLT1_30H;                        /**< ADDR Rejection Filter High, offset: 0x790 */
  __IO uint32_t ARFLT1_31L;                        /**< ADDR Rejection Filter Low, offset: 0x794 */
  __IO uint32_t ARFLT1_31H;                        /**< ADDR Rejection Filter High, offset: 0x798 */
} CANXL_FILTER_BANK_Type, *CANXL_FILTER_BANK_MemMapPtr;

/** Number of instances of the CANXL_FILTER_BANK module. */
#define CANXL_FILTER_BANK_INSTANCE_COUNT         (2u)

/* CANXL_FILTER_BANK - Peripheral instance base addresses */
/** Peripheral CANXL_0__FILTER_BANK base address */
#define IP_CANXL_0__FILTER_BANK_BASE             (0x47422000u)
/** Peripheral CANXL_0__FILTER_BANK base pointer */
#define IP_CANXL_0__FILTER_BANK                  ((CANXL_FILTER_BANK_Type *)IP_CANXL_0__FILTER_BANK_BASE)
/** Peripheral CANXL_1__FILTER_BANK base address */
#define IP_CANXL_1__FILTER_BANK_BASE             (0x47522000u)
/** Peripheral CANXL_1__FILTER_BANK base pointer */
#define IP_CANXL_1__FILTER_BANK                  ((CANXL_FILTER_BANK_Type *)IP_CANXL_1__FILTER_BANK_BASE)
/** Array initializer of CANXL_FILTER_BANK peripheral base addresses */
#define IP_CANXL_FILTER_BANK_BASE_ADDRS          { IP_CANXL_0__FILTER_BANK_BASE, IP_CANXL_1__FILTER_BANK_BASE }
/** Array initializer of CANXL_FILTER_BANK peripheral base pointers */
#define IP_CANXL_FILTER_BANK_BASE_PTRS           { IP_CANXL_0__FILTER_BANK, IP_CANXL_1__FILTER_BANK }

/* ----------------------------------------------------------------------------
   -- CANXL_FILTER_BANK Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CANXL_FILTER_BANK_Register_Masks CANXL_FILTER_BANK Register Masks
 * @{
 */

/*! @name AFCFG0 - Acceptance Filter Configuration */
/*! @{ */

#define CANXL_FILTER_BANK_AFCFG0_ACPTVCAN_MASK   (0x1FU)
#define CANXL_FILTER_BANK_AFCFG0_ACPTVCAN_SHIFT  (0U)
#define CANXL_FILTER_BANK_AFCFG0_ACPTVCAN_WIDTH  (5U)
#define CANXL_FILTER_BANK_AFCFG0_ACPTVCAN(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AFCFG0_ACPTVCAN_SHIFT)) & CANXL_FILTER_BANK_AFCFG0_ACPTVCAN_MASK)

#define CANXL_FILTER_BANK_AFCFG0_AVCANEN_MASK    (0x80U)
#define CANXL_FILTER_BANK_AFCFG0_AVCANEN_SHIFT   (7U)
#define CANXL_FILTER_BANK_AFCFG0_AVCANEN_WIDTH   (1U)
#define CANXL_FILTER_BANK_AFCFG0_AVCANEN(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AFCFG0_AVCANEN_SHIFT)) & CANXL_FILTER_BANK_AFCFG0_AVCANEN_MASK)

#define CANXL_FILTER_BANK_AFCFG0_ACPTSDU_MASK    (0x1F00U)
#define CANXL_FILTER_BANK_AFCFG0_ACPTSDU_SHIFT   (8U)
#define CANXL_FILTER_BANK_AFCFG0_ACPTSDU_WIDTH   (5U)
#define CANXL_FILTER_BANK_AFCFG0_ACPTSDU(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AFCFG0_ACPTSDU_SHIFT)) & CANXL_FILTER_BANK_AFCFG0_ACPTSDU_MASK)

#define CANXL_FILTER_BANK_AFCFG0_ASDUEN_MASK     (0x8000U)
#define CANXL_FILTER_BANK_AFCFG0_ASDUEN_SHIFT    (15U)
#define CANXL_FILTER_BANK_AFCFG0_ASDUEN_WIDTH    (1U)
#define CANXL_FILTER_BANK_AFCFG0_ASDUEN(x)       (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AFCFG0_ASDUEN_SHIFT)) & CANXL_FILTER_BANK_AFCFG0_ASDUEN_MASK)

#define CANXL_FILTER_BANK_AFCFG0_ACPTADDR_MASK   (0x1F0000U)
#define CANXL_FILTER_BANK_AFCFG0_ACPTADDR_SHIFT  (16U)
#define CANXL_FILTER_BANK_AFCFG0_ACPTADDR_WIDTH  (5U)
#define CANXL_FILTER_BANK_AFCFG0_ACPTADDR(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AFCFG0_ACPTADDR_SHIFT)) & CANXL_FILTER_BANK_AFCFG0_ACPTADDR_MASK)

#define CANXL_FILTER_BANK_AFCFG0_AADDREN_MASK    (0x800000U)
#define CANXL_FILTER_BANK_AFCFG0_AADDREN_SHIFT   (23U)
#define CANXL_FILTER_BANK_AFCFG0_AADDREN_WIDTH   (1U)
#define CANXL_FILTER_BANK_AFCFG0_AADDREN(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AFCFG0_AADDREN_SHIFT)) & CANXL_FILTER_BANK_AFCFG0_AADDREN_MASK)
/*! @} */

/*! @name VAMRCFG0 - VCAN Acceptance Mask or Range Configuration */
/*! @{ */

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R0_MASK  (0x1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R0_SHIFT (0U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R0_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R0(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R0_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R0_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R1_MASK  (0x2U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R1_SHIFT (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R1_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R1(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R1_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R1_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R2_MASK  (0x4U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R2_SHIFT (2U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R2_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R2(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R2_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R2_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R3_MASK  (0x8U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R3_SHIFT (3U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R3_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R3(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R3_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R3_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R4_MASK  (0x10U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R4_SHIFT (4U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R4_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R4(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R4_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R4_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R5_MASK  (0x20U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R5_SHIFT (5U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R5_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R5(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R5_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R5_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R6_MASK  (0x40U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R6_SHIFT (6U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R6_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R6(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R6_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R6_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R7_MASK  (0x80U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R7_SHIFT (7U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R7_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R7(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R7_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R7_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R8_MASK  (0x100U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R8_SHIFT (8U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R8_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R8(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R8_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R8_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R9_MASK  (0x200U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R9_SHIFT (9U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R9_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R9(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R9_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R9_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R10_MASK (0x400U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R10_SHIFT (10U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R10_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R10(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R10_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R10_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R11_MASK (0x800U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R11_SHIFT (11U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R11_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R11(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R11_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R11_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R12_MASK (0x1000U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R12_SHIFT (12U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R12_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R12(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R12_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R12_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R13_MASK (0x2000U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R13_SHIFT (13U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R13_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R13(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R13_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R13_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R14_MASK (0x4000U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R14_SHIFT (14U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R14_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R14(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R14_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R14_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R15_MASK (0x8000U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R15_SHIFT (15U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R15_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R15(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R15_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R15_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R16_MASK (0x10000U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R16_SHIFT (16U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R16_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R16(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R16_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R16_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R17_MASK (0x20000U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R17_SHIFT (17U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R17_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R17(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R17_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R17_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R18_MASK (0x40000U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R18_SHIFT (18U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R18_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R18(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R18_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R18_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R19_MASK (0x80000U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R19_SHIFT (19U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R19_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R19(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R19_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R19_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R20_MASK (0x100000U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R20_SHIFT (20U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R20_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R20(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R20_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R20_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R21_MASK (0x200000U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R21_SHIFT (21U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R21_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R21(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R21_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R21_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R22_MASK (0x400000U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R22_SHIFT (22U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R22_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R22(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R22_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R22_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R23_MASK (0x800000U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R23_SHIFT (23U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R23_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R23(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R23_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R23_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R24_MASK (0x1000000U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R24_SHIFT (24U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R24_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R24(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R24_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R24_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R25_MASK (0x2000000U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R25_SHIFT (25U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R25_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R25(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R25_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R25_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R26_MASK (0x4000000U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R26_SHIFT (26U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R26_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R26(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R26_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R26_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R27_MASK (0x8000000U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R27_SHIFT (27U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R27_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R27(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R27_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R27_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R28_MASK (0x10000000U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R28_SHIFT (28U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R28_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R28(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R28_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R28_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R29_MASK (0x20000000U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R29_SHIFT (29U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R29_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R29(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R29_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R29_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R30_MASK (0x40000000U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R30_SHIFT (30U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R30_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R30(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R30_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R30_MASK)

#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R31_MASK (0x80000000U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R31_SHIFT (31U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R31_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG0_VMSK0R31(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG0_VMSK0R31_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG0_VMSK0R31_MASK)
/*! @} */

/*! @name SAMRCFG0 - SDU Acceptance Mask or Range Configuration */
/*! @{ */

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R0_MASK  (0x1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R0_SHIFT (0U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R0_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R0(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R0_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R0_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R1_MASK  (0x2U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R1_SHIFT (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R1_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R1(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R1_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R1_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R2_MASK  (0x4U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R2_SHIFT (2U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R2_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R2(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R2_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R2_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R3_MASK  (0x8U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R3_SHIFT (3U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R3_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R3(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R3_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R3_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R4_MASK  (0x10U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R4_SHIFT (4U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R4_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R4(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R4_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R4_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R5_MASK  (0x20U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R5_SHIFT (5U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R5_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R5(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R5_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R5_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R6_MASK  (0x40U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R6_SHIFT (6U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R6_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R6(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R6_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R6_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R7_MASK  (0x80U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R7_SHIFT (7U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R7_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R7(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R7_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R7_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R8_MASK  (0x100U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R8_SHIFT (8U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R8_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R8(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R8_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R8_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R9_MASK  (0x200U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R9_SHIFT (9U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R9_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R9(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R9_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R9_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R10_MASK (0x400U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R10_SHIFT (10U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R10_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R10(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R10_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R10_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R11_MASK (0x800U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R11_SHIFT (11U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R11_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R11(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R11_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R11_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R12_MASK (0x1000U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R12_SHIFT (12U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R12_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R12(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R12_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R12_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R13_MASK (0x2000U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R13_SHIFT (13U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R13_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R13(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R13_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R13_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R14_MASK (0x4000U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R14_SHIFT (14U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R14_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R14(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R14_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R14_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R15_MASK (0x8000U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R15_SHIFT (15U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R15_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R15(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R15_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R15_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R16_MASK (0x10000U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R16_SHIFT (16U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R16_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R16(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R16_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R16_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R17_MASK (0x20000U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R17_SHIFT (17U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R17_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R17(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R17_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R17_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R18_MASK (0x40000U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R18_SHIFT (18U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R18_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R18(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R18_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R18_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R19_MASK (0x80000U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R19_SHIFT (19U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R19_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R19(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R19_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R19_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R20_MASK (0x100000U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R20_SHIFT (20U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R20_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R20(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R20_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R20_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R21_MASK (0x200000U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R21_SHIFT (21U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R21_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R21(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R21_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R21_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R22_MASK (0x400000U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R22_SHIFT (22U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R22_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R22(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R22_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R22_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R23_MASK (0x800000U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R23_SHIFT (23U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R23_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R23(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R23_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R23_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R24_MASK (0x1000000U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R24_SHIFT (24U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R24_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R24(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R24_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R24_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R25_MASK (0x2000000U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R25_SHIFT (25U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R25_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R25(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R25_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R25_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R26_MASK (0x4000000U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R26_SHIFT (26U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R26_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R26(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R26_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R26_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R27_MASK (0x8000000U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R27_SHIFT (27U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R27_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R27(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R27_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R27_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R28_MASK (0x10000000U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R28_SHIFT (28U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R28_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R28(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R28_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R28_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R29_MASK (0x20000000U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R29_SHIFT (29U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R29_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R29(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R29_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R29_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R30_MASK (0x40000000U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R30_SHIFT (30U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R30_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R30(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R30_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R30_MASK)

#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R31_MASK (0x80000000U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R31_SHIFT (31U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R31_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG0_SMSK0R31(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG0_SMSK0R31_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG0_SMSK0R31_MASK)
/*! @} */

/*! @name AAMRCFG0 - ADDR Acceptance Mask or Range Configuration */
/*! @{ */

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R0_MASK  (0x1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R0_SHIFT (0U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R0_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R0(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R0_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R0_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R1_MASK  (0x2U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R1_SHIFT (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R1_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R1(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R1_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R1_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R2_MASK  (0x4U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R2_SHIFT (2U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R2_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R2(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R2_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R2_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R3_MASK  (0x8U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R3_SHIFT (3U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R3_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R3(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R3_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R3_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R4_MASK  (0x10U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R4_SHIFT (4U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R4_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R4(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R4_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R4_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R5_MASK  (0x20U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R5_SHIFT (5U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R5_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R5(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R5_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R5_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R6_MASK  (0x40U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R6_SHIFT (6U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R6_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R6(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R6_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R6_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R7_MASK  (0x80U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R7_SHIFT (7U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R7_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R7(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R7_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R7_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R8_MASK  (0x100U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R8_SHIFT (8U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R8_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R8(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R8_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R8_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R9_MASK  (0x200U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R9_SHIFT (9U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R9_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R9(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R9_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R9_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R10_MASK (0x400U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R10_SHIFT (10U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R10_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R10(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R10_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R10_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R11_MASK (0x800U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R11_SHIFT (11U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R11_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R11(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R11_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R11_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R12_MASK (0x1000U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R12_SHIFT (12U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R12_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R12(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R12_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R12_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R13_MASK (0x2000U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R13_SHIFT (13U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R13_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R13(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R13_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R13_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R14_MASK (0x4000U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R14_SHIFT (14U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R14_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R14(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R14_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R14_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R15_MASK (0x8000U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R15_SHIFT (15U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R15_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R15(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R15_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R15_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R16_MASK (0x10000U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R16_SHIFT (16U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R16_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R16(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R16_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R16_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R17_MASK (0x20000U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R17_SHIFT (17U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R17_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R17(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R17_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R17_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R18_MASK (0x40000U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R18_SHIFT (18U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R18_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R18(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R18_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R18_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R19_MASK (0x80000U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R19_SHIFT (19U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R19_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R19(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R19_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R19_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R20_MASK (0x100000U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R20_SHIFT (20U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R20_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R20(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R20_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R20_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R21_MASK (0x200000U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R21_SHIFT (21U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R21_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R21(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R21_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R21_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R22_MASK (0x400000U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R22_SHIFT (22U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R22_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R22(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R22_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R22_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R23_MASK (0x800000U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R23_SHIFT (23U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R23_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R23(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R23_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R23_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R24_MASK (0x1000000U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R24_SHIFT (24U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R24_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R24(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R24_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R24_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R25_MASK (0x2000000U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R25_SHIFT (25U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R25_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R25(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R25_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R25_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R26_MASK (0x4000000U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R26_SHIFT (26U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R26_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R26(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R26_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R26_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R27_MASK (0x8000000U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R27_SHIFT (27U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R27_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R27(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R27_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R27_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R28_MASK (0x10000000U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R28_SHIFT (28U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R28_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R28(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R28_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R28_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R29_MASK (0x20000000U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R29_SHIFT (29U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R29_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R29(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R29_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R29_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R30_MASK (0x40000000U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R30_SHIFT (30U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R30_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R30(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R30_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R30_MASK)

#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R31_MASK (0x80000000U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R31_SHIFT (31U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R31_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG0_AMSK0R31(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG0_AMSK0R31_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG0_AMSK0R31_MASK)
/*! @} */

/*! @name VAFLT0_0 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT0_0_VCANa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_VAFLT0_0_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT0_0_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_0_VCANa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_0_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_0_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_0_VCANa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT0_0_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT0_0_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_0_VCANa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_0_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_0_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT0_0_VCANb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT0_0_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT0_0_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_0_VCANb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_0_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_0_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_0_VCANb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT0_0_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT0_0_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_0_VCANb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_0_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_0_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT0_2 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT0_2_VCANa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_VAFLT0_2_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT0_2_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_2_VCANa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_2_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_2_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_2_VCANa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT0_2_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT0_2_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_2_VCANa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_2_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_2_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT0_2_VCANb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT0_2_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT0_2_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_2_VCANb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_2_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_2_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_2_VCANb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT0_2_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT0_2_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_2_VCANb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_2_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_2_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT0_4 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT0_4_VCANa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_VAFLT0_4_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT0_4_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_4_VCANa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_4_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_4_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_4_VCANa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT0_4_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT0_4_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_4_VCANa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_4_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_4_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT0_4_VCANb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT0_4_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT0_4_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_4_VCANb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_4_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_4_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_4_VCANb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT0_4_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT0_4_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_4_VCANb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_4_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_4_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT0_6 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT0_6_VCANa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_VAFLT0_6_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT0_6_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_6_VCANa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_6_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_6_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_6_VCANa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT0_6_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT0_6_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_6_VCANa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_6_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_6_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT0_6_VCANb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT0_6_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT0_6_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_6_VCANb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_6_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_6_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_6_VCANb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT0_6_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT0_6_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_6_VCANb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_6_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_6_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT0_8 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT0_8_VCANa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_VAFLT0_8_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT0_8_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_8_VCANa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_8_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_8_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_8_VCANa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT0_8_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT0_8_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_8_VCANa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_8_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_8_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT0_8_VCANb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT0_8_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT0_8_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_8_VCANb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_8_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_8_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_8_VCANb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT0_8_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT0_8_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_8_VCANb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_8_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_8_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT0_10 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT0_10_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT0_10_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT0_10_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_10_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_10_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_10_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_10_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT0_10_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT0_10_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_10_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_10_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_10_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT0_10_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT0_10_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT0_10_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_10_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_10_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_10_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_10_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT0_10_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT0_10_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_10_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_10_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_10_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT0_12 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT0_12_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT0_12_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT0_12_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_12_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_12_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_12_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_12_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT0_12_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT0_12_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_12_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_12_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_12_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT0_12_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT0_12_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT0_12_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_12_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_12_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_12_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_12_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT0_12_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT0_12_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_12_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_12_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_12_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT0_14 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT0_14_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT0_14_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT0_14_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_14_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_14_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_14_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_14_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT0_14_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT0_14_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_14_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_14_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_14_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT0_14_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT0_14_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT0_14_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_14_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_14_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_14_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_14_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT0_14_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT0_14_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_14_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_14_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_14_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT0_16 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT0_16_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT0_16_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT0_16_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_16_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_16_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_16_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_16_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT0_16_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT0_16_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_16_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_16_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_16_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT0_16_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT0_16_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT0_16_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_16_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_16_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_16_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_16_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT0_16_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT0_16_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_16_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_16_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_16_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT0_18 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT0_18_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT0_18_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT0_18_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_18_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_18_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_18_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_18_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT0_18_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT0_18_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_18_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_18_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_18_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT0_18_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT0_18_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT0_18_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_18_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_18_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_18_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_18_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT0_18_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT0_18_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_18_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_18_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_18_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT0_20 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT0_20_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT0_20_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT0_20_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_20_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_20_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_20_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_20_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT0_20_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT0_20_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_20_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_20_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_20_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT0_20_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT0_20_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT0_20_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_20_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_20_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_20_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_20_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT0_20_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT0_20_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_20_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_20_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_20_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT0_22 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT0_22_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT0_22_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT0_22_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_22_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_22_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_22_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_22_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT0_22_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT0_22_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_22_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_22_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_22_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT0_22_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT0_22_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT0_22_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_22_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_22_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_22_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_22_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT0_22_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT0_22_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_22_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_22_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_22_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT0_24 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT0_24_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT0_24_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT0_24_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_24_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_24_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_24_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_24_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT0_24_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT0_24_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_24_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_24_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_24_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT0_24_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT0_24_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT0_24_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_24_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_24_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_24_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_24_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT0_24_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT0_24_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_24_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_24_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_24_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT0_26 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT0_26_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT0_26_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT0_26_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_26_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_26_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_26_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_26_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT0_26_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT0_26_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_26_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_26_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_26_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT0_26_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT0_26_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT0_26_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_26_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_26_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_26_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_26_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT0_26_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT0_26_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_26_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_26_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_26_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT0_28 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT0_28_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT0_28_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT0_28_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_28_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_28_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_28_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_28_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT0_28_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT0_28_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_28_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_28_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_28_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT0_28_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT0_28_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT0_28_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_28_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_28_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_28_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_28_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT0_28_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT0_28_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_28_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_28_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_28_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT0_30 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT0_30_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT0_30_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT0_30_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_30_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_30_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_30_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_30_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT0_30_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT0_30_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_30_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_30_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_30_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT0_30_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT0_30_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT0_30_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_30_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_30_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_30_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT0_30_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT0_30_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT0_30_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT0_30_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT0_30_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT0_30_VCANb_H_MASK)
/*! @} */

/*! @name SAFLT0_0 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT0_0_SDUa_L_MASK   (0xFFU)
#define CANXL_FILTER_BANK_SAFLT0_0_SDUa_L_SHIFT  (0U)
#define CANXL_FILTER_BANK_SAFLT0_0_SDUa_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT0_0_SDUa_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_0_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_0_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_0_SDUa_H_MASK   (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT0_0_SDUa_H_SHIFT  (8U)
#define CANXL_FILTER_BANK_SAFLT0_0_SDUa_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT0_0_SDUa_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_0_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_0_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT0_0_SDUb_L_MASK   (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT0_0_SDUb_L_SHIFT  (16U)
#define CANXL_FILTER_BANK_SAFLT0_0_SDUb_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT0_0_SDUb_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_0_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_0_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_0_SDUb_H_MASK   (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT0_0_SDUb_H_SHIFT  (24U)
#define CANXL_FILTER_BANK_SAFLT0_0_SDUb_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT0_0_SDUb_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_0_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_0_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT0_2 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT0_2_SDUa_L_MASK   (0xFFU)
#define CANXL_FILTER_BANK_SAFLT0_2_SDUa_L_SHIFT  (0U)
#define CANXL_FILTER_BANK_SAFLT0_2_SDUa_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT0_2_SDUa_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_2_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_2_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_2_SDUa_H_MASK   (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT0_2_SDUa_H_SHIFT  (8U)
#define CANXL_FILTER_BANK_SAFLT0_2_SDUa_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT0_2_SDUa_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_2_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_2_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT0_2_SDUb_L_MASK   (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT0_2_SDUb_L_SHIFT  (16U)
#define CANXL_FILTER_BANK_SAFLT0_2_SDUb_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT0_2_SDUb_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_2_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_2_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_2_SDUb_H_MASK   (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT0_2_SDUb_H_SHIFT  (24U)
#define CANXL_FILTER_BANK_SAFLT0_2_SDUb_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT0_2_SDUb_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_2_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_2_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT0_4 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT0_4_SDUa_L_MASK   (0xFFU)
#define CANXL_FILTER_BANK_SAFLT0_4_SDUa_L_SHIFT  (0U)
#define CANXL_FILTER_BANK_SAFLT0_4_SDUa_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT0_4_SDUa_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_4_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_4_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_4_SDUa_H_MASK   (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT0_4_SDUa_H_SHIFT  (8U)
#define CANXL_FILTER_BANK_SAFLT0_4_SDUa_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT0_4_SDUa_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_4_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_4_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT0_4_SDUb_L_MASK   (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT0_4_SDUb_L_SHIFT  (16U)
#define CANXL_FILTER_BANK_SAFLT0_4_SDUb_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT0_4_SDUb_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_4_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_4_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_4_SDUb_H_MASK   (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT0_4_SDUb_H_SHIFT  (24U)
#define CANXL_FILTER_BANK_SAFLT0_4_SDUb_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT0_4_SDUb_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_4_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_4_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT0_6 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT0_6_SDUa_L_MASK   (0xFFU)
#define CANXL_FILTER_BANK_SAFLT0_6_SDUa_L_SHIFT  (0U)
#define CANXL_FILTER_BANK_SAFLT0_6_SDUa_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT0_6_SDUa_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_6_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_6_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_6_SDUa_H_MASK   (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT0_6_SDUa_H_SHIFT  (8U)
#define CANXL_FILTER_BANK_SAFLT0_6_SDUa_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT0_6_SDUa_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_6_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_6_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT0_6_SDUb_L_MASK   (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT0_6_SDUb_L_SHIFT  (16U)
#define CANXL_FILTER_BANK_SAFLT0_6_SDUb_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT0_6_SDUb_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_6_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_6_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_6_SDUb_H_MASK   (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT0_6_SDUb_H_SHIFT  (24U)
#define CANXL_FILTER_BANK_SAFLT0_6_SDUb_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT0_6_SDUb_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_6_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_6_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT0_8 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT0_8_SDUa_L_MASK   (0xFFU)
#define CANXL_FILTER_BANK_SAFLT0_8_SDUa_L_SHIFT  (0U)
#define CANXL_FILTER_BANK_SAFLT0_8_SDUa_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT0_8_SDUa_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_8_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_8_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_8_SDUa_H_MASK   (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT0_8_SDUa_H_SHIFT  (8U)
#define CANXL_FILTER_BANK_SAFLT0_8_SDUa_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT0_8_SDUa_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_8_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_8_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT0_8_SDUb_L_MASK   (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT0_8_SDUb_L_SHIFT  (16U)
#define CANXL_FILTER_BANK_SAFLT0_8_SDUb_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT0_8_SDUb_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_8_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_8_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_8_SDUb_H_MASK   (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT0_8_SDUb_H_SHIFT  (24U)
#define CANXL_FILTER_BANK_SAFLT0_8_SDUb_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT0_8_SDUb_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_8_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_8_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT0_10 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT0_10_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT0_10_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT0_10_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_10_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_10_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_10_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_10_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT0_10_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT0_10_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_10_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_10_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_10_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT0_10_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT0_10_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT0_10_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_10_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_10_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_10_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_10_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT0_10_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT0_10_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_10_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_10_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_10_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT0_12 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT0_12_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT0_12_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT0_12_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_12_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_12_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_12_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_12_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT0_12_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT0_12_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_12_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_12_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_12_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT0_12_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT0_12_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT0_12_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_12_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_12_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_12_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_12_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT0_12_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT0_12_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_12_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_12_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_12_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT0_14 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT0_14_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT0_14_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT0_14_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_14_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_14_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_14_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_14_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT0_14_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT0_14_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_14_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_14_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_14_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT0_14_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT0_14_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT0_14_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_14_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_14_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_14_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_14_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT0_14_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT0_14_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_14_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_14_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_14_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT0_16 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT0_16_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT0_16_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT0_16_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_16_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_16_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_16_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_16_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT0_16_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT0_16_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_16_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_16_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_16_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT0_16_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT0_16_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT0_16_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_16_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_16_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_16_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_16_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT0_16_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT0_16_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_16_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_16_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_16_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT0_18 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT0_18_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT0_18_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT0_18_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_18_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_18_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_18_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_18_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT0_18_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT0_18_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_18_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_18_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_18_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT0_18_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT0_18_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT0_18_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_18_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_18_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_18_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_18_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT0_18_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT0_18_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_18_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_18_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_18_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT0_20 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT0_20_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT0_20_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT0_20_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_20_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_20_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_20_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_20_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT0_20_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT0_20_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_20_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_20_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_20_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT0_20_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT0_20_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT0_20_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_20_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_20_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_20_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_20_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT0_20_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT0_20_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_20_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_20_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_20_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT0_22 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT0_22_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT0_22_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT0_22_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_22_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_22_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_22_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_22_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT0_22_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT0_22_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_22_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_22_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_22_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT0_22_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT0_22_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT0_22_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_22_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_22_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_22_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_22_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT0_22_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT0_22_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_22_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_22_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_22_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT0_24 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT0_24_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT0_24_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT0_24_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_24_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_24_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_24_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_24_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT0_24_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT0_24_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_24_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_24_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_24_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT0_24_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT0_24_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT0_24_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_24_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_24_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_24_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_24_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT0_24_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT0_24_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_24_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_24_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_24_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT0_26 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT0_26_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT0_26_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT0_26_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_26_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_26_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_26_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_26_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT0_26_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT0_26_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_26_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_26_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_26_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT0_26_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT0_26_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT0_26_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_26_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_26_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_26_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_26_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT0_26_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT0_26_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_26_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_26_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_26_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT0_28 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT0_28_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT0_28_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT0_28_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_28_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_28_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_28_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_28_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT0_28_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT0_28_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_28_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_28_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_28_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT0_28_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT0_28_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT0_28_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_28_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_28_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_28_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_28_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT0_28_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT0_28_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_28_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_28_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_28_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT0_30 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT0_30_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT0_30_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT0_30_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_30_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_30_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_30_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_30_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT0_30_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT0_30_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_30_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_30_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_30_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT0_30_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT0_30_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT0_30_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_30_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_30_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_30_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT0_30_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT0_30_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT0_30_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT0_30_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT0_30_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT0_30_SDUb_H_MASK)
/*! @} */

/*! @name AAFLT0_0L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_0L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_0L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_0L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_0L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_0L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_0L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_0H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_0H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_0H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_0H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_0H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_0H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_0H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_1L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_1L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_1L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_1L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_1L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_1L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_1L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_1H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_1H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_1H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_1H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_1H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_1H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_1H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_2L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_2L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_2L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_2L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_2L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_2L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_2L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_2H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_2H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_2H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_2H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_2H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_2H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_2H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_3L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_3L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_3L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_3L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_3L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_3L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_3L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_3H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_3H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_3H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_3H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_3H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_3H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_3H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_4L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_4L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_4L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_4L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_4L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_4L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_4L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_4H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_4H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_4H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_4H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_4H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_4H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_4H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_5L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_5L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_5L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_5L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_5L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_5L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_5L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_5H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_5H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_5H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_5H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_5H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_5H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_5H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_6L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_6L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_6L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_6L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_6L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_6L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_6L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_6H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_6H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_6H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_6H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_6H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_6H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_6H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_7L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_7L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_7L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_7L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_7L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_7L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_7L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_7H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_7H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_7H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_7H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_7H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_7H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_7H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_8L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_8L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_8L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_8L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_8L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_8L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_8L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_8H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_8H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_8H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_8H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_8H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_8H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_8H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_9L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_9L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_9L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_9L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_9L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_9L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_9L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_9H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_9H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_9H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_9H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_9H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_9H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_9H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_10L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_10L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_10L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_10L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_10L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_10L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_10L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_10H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_10H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_10H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_10H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_10H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_10H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_10H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_11L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_11L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_11L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_11L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_11L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_11L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_11L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_11H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_11H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_11H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_11H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_11H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_11H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_11H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_12L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_12L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_12L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_12L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_12L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_12L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_12L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_12H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_12H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_12H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_12H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_12H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_12H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_12H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_13L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_13L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_13L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_13L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_13L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_13L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_13L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_13H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_13H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_13H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_13H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_13H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_13H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_13H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_14L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_14L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_14L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_14L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_14L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_14L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_14L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_14H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_14H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_14H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_14H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_14H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_14H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_14H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_15L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_15L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_15L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_15L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_15L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_15L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_15L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_15H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_15H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_15H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_15H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_15H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_15H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_15H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_16L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_16L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_16L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_16L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_16L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_16L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_16L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_16H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_16H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_16H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_16H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_16H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_16H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_16H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_17L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_17L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_17L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_17L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_17L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_17L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_17L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_17H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_17H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_17H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_17H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_17H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_17H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_17H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_18L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_18L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_18L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_18L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_18L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_18L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_18L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_18H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_18H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_18H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_18H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_18H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_18H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_18H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_19L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_19L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_19L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_19L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_19L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_19L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_19L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_19H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_19H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_19H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_19H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_19H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_19H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_19H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_20L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_20L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_20L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_20L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_20L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_20L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_20L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_20H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_20H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_20H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_20H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_20H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_20H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_20H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_21L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_21L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_21L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_21L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_21L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_21L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_21L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_21H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_21H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_21H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_21H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_21H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_21H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_21H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_22L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_22L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_22L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_22L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_22L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_22L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_22L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_22H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_22H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_22H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_22H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_22H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_22H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_22H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_23L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_23L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_23L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_23L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_23L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_23L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_23L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_23H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_23H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_23H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_23H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_23H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_23H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_23H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_24L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_24L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_24L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_24L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_24L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_24L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_24L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_24H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_24H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_24H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_24H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_24H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_24H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_24H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_25L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_25L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_25L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_25L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_25L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_25L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_25L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_25H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_25H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_25H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_25H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_25H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_25H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_25H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_26L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_26L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_26L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_26L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_26L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_26L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_26L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_26H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_26H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_26H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_26H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_26H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_26H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_26H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_27L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_27L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_27L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_27L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_27L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_27L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_27L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_27H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_27H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_27H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_27H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_27H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_27H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_27H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_28L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_28L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_28L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_28L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_28L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_28L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_28L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_28H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_28H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_28H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_28H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_28H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_28H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_28H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_29L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_29L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_29L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_29L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_29L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_29L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_29L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_29H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_29H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_29H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_29H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_29H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_29H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_29H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_30L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_30L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_30L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_30L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_30L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_30L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_30L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_30H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_30H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_30H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_30H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_30H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_30H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_30H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT0_31L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_31L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_31L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_31L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_31L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_31L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_31L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT0_31H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT0_31H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT0_31H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT0_31H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT0_31H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT0_31H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT0_31H_ADDRn_H_MASK)
/*! @} */

/*! @name RFCFG0 - Rejection Filter Configuration */
/*! @{ */

#define CANXL_FILTER_BANK_RFCFG0_REJVCAN_MASK    (0x1FU)
#define CANXL_FILTER_BANK_RFCFG0_REJVCAN_SHIFT   (0U)
#define CANXL_FILTER_BANK_RFCFG0_REJVCAN_WIDTH   (5U)
#define CANXL_FILTER_BANK_RFCFG0_REJVCAN(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_RFCFG0_REJVCAN_SHIFT)) & CANXL_FILTER_BANK_RFCFG0_REJVCAN_MASK)

#define CANXL_FILTER_BANK_RFCFG0_RVCANEN_MASK    (0x80U)
#define CANXL_FILTER_BANK_RFCFG0_RVCANEN_SHIFT   (7U)
#define CANXL_FILTER_BANK_RFCFG0_RVCANEN_WIDTH   (1U)
#define CANXL_FILTER_BANK_RFCFG0_RVCANEN(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_RFCFG0_RVCANEN_SHIFT)) & CANXL_FILTER_BANK_RFCFG0_RVCANEN_MASK)

#define CANXL_FILTER_BANK_RFCFG0_REJSDU_MASK     (0x1F00U)
#define CANXL_FILTER_BANK_RFCFG0_REJSDU_SHIFT    (8U)
#define CANXL_FILTER_BANK_RFCFG0_REJSDU_WIDTH    (5U)
#define CANXL_FILTER_BANK_RFCFG0_REJSDU(x)       (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_RFCFG0_REJSDU_SHIFT)) & CANXL_FILTER_BANK_RFCFG0_REJSDU_MASK)

#define CANXL_FILTER_BANK_RFCFG0_RSDUEN_MASK     (0x8000U)
#define CANXL_FILTER_BANK_RFCFG0_RSDUEN_SHIFT    (15U)
#define CANXL_FILTER_BANK_RFCFG0_RSDUEN_WIDTH    (1U)
#define CANXL_FILTER_BANK_RFCFG0_RSDUEN(x)       (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_RFCFG0_RSDUEN_SHIFT)) & CANXL_FILTER_BANK_RFCFG0_RSDUEN_MASK)

#define CANXL_FILTER_BANK_RFCFG0_REJADDR_MASK    (0x1F0000U)
#define CANXL_FILTER_BANK_RFCFG0_REJADDR_SHIFT   (16U)
#define CANXL_FILTER_BANK_RFCFG0_REJADDR_WIDTH   (5U)
#define CANXL_FILTER_BANK_RFCFG0_REJADDR(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_RFCFG0_REJADDR_SHIFT)) & CANXL_FILTER_BANK_RFCFG0_REJADDR_MASK)

#define CANXL_FILTER_BANK_RFCFG0_RADDREN_MASK    (0x800000U)
#define CANXL_FILTER_BANK_RFCFG0_RADDREN_SHIFT   (23U)
#define CANXL_FILTER_BANK_RFCFG0_RADDREN_WIDTH   (1U)
#define CANXL_FILTER_BANK_RFCFG0_RADDREN(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_RFCFG0_RADDREN_SHIFT)) & CANXL_FILTER_BANK_RFCFG0_RADDREN_MASK)
/*! @} */

/*! @name VRMRCFG0 - VCAN Rejection Mask or Range Configuration */
/*! @{ */

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R0_MASK  (0x1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R0_SHIFT (0U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R0_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R0(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R0_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R0_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R1_MASK  (0x2U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R1_SHIFT (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R1_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R1(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R1_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R1_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R2_MASK  (0x4U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R2_SHIFT (2U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R2_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R2(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R2_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R2_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R3_MASK  (0x8U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R3_SHIFT (3U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R3_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R3(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R3_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R3_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R4_MASK  (0x10U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R4_SHIFT (4U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R4_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R4(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R4_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R4_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R5_MASK  (0x20U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R5_SHIFT (5U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R5_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R5(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R5_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R5_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R6_MASK  (0x40U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R6_SHIFT (6U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R6_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R6(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R6_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R6_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R7_MASK  (0x80U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R7_SHIFT (7U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R7_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R7(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R7_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R7_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R8_MASK  (0x100U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R8_SHIFT (8U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R8_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R8(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R8_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R8_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R9_MASK  (0x200U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R9_SHIFT (9U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R9_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R9(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R9_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R9_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R10_MASK (0x400U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R10_SHIFT (10U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R10_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R10(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R10_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R10_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R11_MASK (0x800U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R11_SHIFT (11U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R11_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R11(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R11_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R11_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R12_MASK (0x1000U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R12_SHIFT (12U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R12_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R12(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R12_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R12_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R13_MASK (0x2000U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R13_SHIFT (13U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R13_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R13(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R13_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R13_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R14_MASK (0x4000U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R14_SHIFT (14U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R14_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R14(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R14_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R14_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R15_MASK (0x8000U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R15_SHIFT (15U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R15_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R15(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R15_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R15_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R16_MASK (0x10000U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R16_SHIFT (16U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R16_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R16(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R16_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R16_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R17_MASK (0x20000U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R17_SHIFT (17U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R17_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R17(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R17_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R17_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R18_MASK (0x40000U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R18_SHIFT (18U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R18_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R18(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R18_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R18_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R19_MASK (0x80000U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R19_SHIFT (19U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R19_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R19(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R19_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R19_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R20_MASK (0x100000U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R20_SHIFT (20U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R20_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R20(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R20_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R20_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R21_MASK (0x200000U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R21_SHIFT (21U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R21_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R21(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R21_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R21_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R22_MASK (0x400000U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R22_SHIFT (22U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R22_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R22(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R22_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R22_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R23_MASK (0x800000U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R23_SHIFT (23U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R23_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R23(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R23_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R23_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R24_MASK (0x1000000U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R24_SHIFT (24U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R24_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R24(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R24_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R24_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R25_MASK (0x2000000U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R25_SHIFT (25U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R25_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R25(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R25_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R25_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R26_MASK (0x4000000U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R26_SHIFT (26U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R26_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R26(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R26_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R26_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R27_MASK (0x8000000U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R27_SHIFT (27U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R27_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R27(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R27_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R27_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R28_MASK (0x10000000U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R28_SHIFT (28U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R28_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R28(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R28_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R28_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R29_MASK (0x20000000U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R29_SHIFT (29U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R29_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R29(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R29_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R29_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R30_MASK (0x40000000U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R30_SHIFT (30U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R30_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R30(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R30_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R30_MASK)

#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R31_MASK (0x80000000U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R31_SHIFT (31U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R31_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG0_VMSK0R31(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG0_VMSK0R31_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG0_VMSK0R31_MASK)
/*! @} */

/*! @name SRMRCFG0 - SDU Rejection Mask or Range Configuration */
/*! @{ */

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R0_MASK  (0x1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R0_SHIFT (0U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R0_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R0(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R0_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R0_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R1_MASK  (0x2U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R1_SHIFT (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R1_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R1(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R1_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R1_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R2_MASK  (0x4U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R2_SHIFT (2U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R2_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R2(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R2_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R2_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R3_MASK  (0x8U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R3_SHIFT (3U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R3_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R3(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R3_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R3_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R4_MASK  (0x10U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R4_SHIFT (4U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R4_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R4(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R4_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R4_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R5_MASK  (0x20U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R5_SHIFT (5U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R5_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R5(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R5_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R5_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R6_MASK  (0x40U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R6_SHIFT (6U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R6_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R6(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R6_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R6_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R7_MASK  (0x80U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R7_SHIFT (7U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R7_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R7(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R7_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R7_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R8_MASK  (0x100U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R8_SHIFT (8U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R8_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R8(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R8_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R8_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R9_MASK  (0x200U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R9_SHIFT (9U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R9_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R9(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R9_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R9_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R10_MASK (0x400U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R10_SHIFT (10U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R10_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R10(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R10_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R10_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R11_MASK (0x800U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R11_SHIFT (11U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R11_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R11(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R11_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R11_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R12_MASK (0x1000U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R12_SHIFT (12U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R12_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R12(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R12_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R12_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R13_MASK (0x2000U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R13_SHIFT (13U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R13_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R13(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R13_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R13_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R14_MASK (0x4000U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R14_SHIFT (14U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R14_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R14(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R14_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R14_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R15_MASK (0x8000U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R15_SHIFT (15U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R15_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R15(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R15_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R15_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R16_MASK (0x10000U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R16_SHIFT (16U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R16_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R16(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R16_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R16_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R17_MASK (0x20000U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R17_SHIFT (17U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R17_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R17(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R17_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R17_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R18_MASK (0x40000U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R18_SHIFT (18U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R18_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R18(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R18_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R18_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R19_MASK (0x80000U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R19_SHIFT (19U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R19_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R19(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R19_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R19_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R20_MASK (0x100000U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R20_SHIFT (20U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R20_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R20(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R20_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R20_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R21_MASK (0x200000U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R21_SHIFT (21U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R21_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R21(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R21_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R21_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R22_MASK (0x400000U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R22_SHIFT (22U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R22_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R22(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R22_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R22_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R23_MASK (0x800000U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R23_SHIFT (23U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R23_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R23(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R23_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R23_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R24_MASK (0x1000000U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R24_SHIFT (24U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R24_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R24(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R24_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R24_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R25_MASK (0x2000000U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R25_SHIFT (25U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R25_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R25(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R25_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R25_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R26_MASK (0x4000000U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R26_SHIFT (26U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R26_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R26(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R26_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R26_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R27_MASK (0x8000000U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R27_SHIFT (27U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R27_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R27(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R27_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R27_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R28_MASK (0x10000000U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R28_SHIFT (28U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R28_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R28(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R28_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R28_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R29_MASK (0x20000000U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R29_SHIFT (29U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R29_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R29(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R29_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R29_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R30_MASK (0x40000000U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R30_SHIFT (30U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R30_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R30(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R30_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R30_MASK)

#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R31_MASK (0x80000000U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R31_SHIFT (31U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R31_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG0_SMSK0R31(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG0_SMSK0R31_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG0_SMSK0R31_MASK)
/*! @} */

/*! @name ARMRCFG0 - ADDR Rejection Mask or Range Configuration */
/*! @{ */

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R0_MASK  (0x1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R0_SHIFT (0U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R0_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R0(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R0_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R0_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R1_MASK  (0x2U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R1_SHIFT (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R1_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R1(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R1_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R1_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R2_MASK  (0x4U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R2_SHIFT (2U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R2_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R2(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R2_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R2_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R3_MASK  (0x8U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R3_SHIFT (3U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R3_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R3(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R3_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R3_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R4_MASK  (0x10U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R4_SHIFT (4U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R4_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R4(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R4_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R4_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R5_MASK  (0x20U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R5_SHIFT (5U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R5_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R5(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R5_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R5_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R6_MASK  (0x40U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R6_SHIFT (6U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R6_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R6(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R6_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R6_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R7_MASK  (0x80U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R7_SHIFT (7U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R7_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R7(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R7_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R7_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R8_MASK  (0x100U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R8_SHIFT (8U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R8_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R8(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R8_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R8_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R9_MASK  (0x200U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R9_SHIFT (9U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R9_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R9(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R9_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R9_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R10_MASK (0x400U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R10_SHIFT (10U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R10_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R10(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R10_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R10_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R11_MASK (0x800U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R11_SHIFT (11U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R11_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R11(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R11_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R11_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R12_MASK (0x1000U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R12_SHIFT (12U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R12_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R12(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R12_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R12_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R13_MASK (0x2000U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R13_SHIFT (13U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R13_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R13(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R13_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R13_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R14_MASK (0x4000U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R14_SHIFT (14U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R14_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R14(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R14_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R14_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R15_MASK (0x8000U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R15_SHIFT (15U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R15_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R15(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R15_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R15_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R16_MASK (0x10000U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R16_SHIFT (16U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R16_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R16(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R16_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R16_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R17_MASK (0x20000U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R17_SHIFT (17U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R17_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R17(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R17_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R17_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R18_MASK (0x40000U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R18_SHIFT (18U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R18_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R18(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R18_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R18_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R19_MASK (0x80000U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R19_SHIFT (19U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R19_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R19(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R19_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R19_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R20_MASK (0x100000U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R20_SHIFT (20U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R20_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R20(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R20_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R20_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R21_MASK (0x200000U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R21_SHIFT (21U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R21_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R21(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R21_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R21_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R22_MASK (0x400000U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R22_SHIFT (22U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R22_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R22(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R22_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R22_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R23_MASK (0x800000U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R23_SHIFT (23U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R23_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R23(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R23_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R23_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R24_MASK (0x1000000U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R24_SHIFT (24U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R24_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R24(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R24_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R24_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R25_MASK (0x2000000U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R25_SHIFT (25U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R25_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R25(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R25_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R25_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R26_MASK (0x4000000U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R26_SHIFT (26U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R26_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R26(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R26_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R26_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R27_MASK (0x8000000U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R27_SHIFT (27U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R27_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R27(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R27_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R27_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R28_MASK (0x10000000U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R28_SHIFT (28U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R28_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R28(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R28_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R28_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R29_MASK (0x20000000U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R29_SHIFT (29U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R29_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R29(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R29_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R29_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R30_MASK (0x40000000U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R30_SHIFT (30U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R30_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R30(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R30_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R30_MASK)

#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R31_MASK (0x80000000U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R31_SHIFT (31U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R31_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG0_AMSK0R31(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG0_AMSK0R31_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG0_AMSK0R31_MASK)
/*! @} */

/*! @name VRFLT0_0 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT0_0_VCANa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_VRFLT0_0_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT0_0_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_0_VCANa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_0_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_0_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_0_VCANa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT0_0_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT0_0_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_0_VCANa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_0_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_0_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT0_0_VCANb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT0_0_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT0_0_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_0_VCANb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_0_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_0_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_0_VCANb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT0_0_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT0_0_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_0_VCANb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_0_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_0_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT0_2 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT0_2_VCANa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_VRFLT0_2_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT0_2_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_2_VCANa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_2_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_2_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_2_VCANa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT0_2_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT0_2_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_2_VCANa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_2_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_2_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT0_2_VCANb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT0_2_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT0_2_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_2_VCANb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_2_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_2_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_2_VCANb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT0_2_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT0_2_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_2_VCANb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_2_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_2_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT0_4 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT0_4_VCANa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_VRFLT0_4_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT0_4_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_4_VCANa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_4_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_4_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_4_VCANa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT0_4_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT0_4_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_4_VCANa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_4_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_4_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT0_4_VCANb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT0_4_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT0_4_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_4_VCANb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_4_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_4_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_4_VCANb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT0_4_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT0_4_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_4_VCANb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_4_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_4_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT0_6 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT0_6_VCANa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_VRFLT0_6_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT0_6_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_6_VCANa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_6_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_6_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_6_VCANa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT0_6_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT0_6_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_6_VCANa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_6_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_6_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT0_6_VCANb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT0_6_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT0_6_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_6_VCANb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_6_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_6_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_6_VCANb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT0_6_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT0_6_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_6_VCANb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_6_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_6_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT0_8 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT0_8_VCANa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_VRFLT0_8_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT0_8_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_8_VCANa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_8_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_8_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_8_VCANa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT0_8_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT0_8_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_8_VCANa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_8_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_8_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT0_8_VCANb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT0_8_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT0_8_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_8_VCANb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_8_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_8_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_8_VCANb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT0_8_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT0_8_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_8_VCANb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_8_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_8_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT0_10 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT0_10_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT0_10_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT0_10_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_10_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_10_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_10_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_10_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT0_10_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT0_10_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_10_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_10_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_10_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT0_10_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT0_10_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT0_10_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_10_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_10_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_10_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_10_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT0_10_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT0_10_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_10_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_10_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_10_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT0_12 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT0_12_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT0_12_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT0_12_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_12_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_12_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_12_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_12_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT0_12_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT0_12_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_12_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_12_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_12_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT0_12_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT0_12_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT0_12_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_12_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_12_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_12_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_12_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT0_12_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT0_12_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_12_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_12_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_12_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT0_14 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT0_14_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT0_14_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT0_14_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_14_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_14_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_14_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_14_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT0_14_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT0_14_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_14_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_14_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_14_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT0_14_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT0_14_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT0_14_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_14_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_14_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_14_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_14_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT0_14_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT0_14_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_14_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_14_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_14_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT0_16 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT0_16_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT0_16_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT0_16_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_16_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_16_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_16_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_16_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT0_16_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT0_16_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_16_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_16_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_16_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT0_16_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT0_16_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT0_16_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_16_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_16_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_16_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_16_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT0_16_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT0_16_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_16_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_16_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_16_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT0_18 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT0_18_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT0_18_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT0_18_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_18_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_18_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_18_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_18_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT0_18_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT0_18_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_18_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_18_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_18_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT0_18_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT0_18_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT0_18_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_18_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_18_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_18_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_18_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT0_18_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT0_18_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_18_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_18_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_18_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT0_20 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT0_20_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT0_20_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT0_20_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_20_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_20_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_20_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_20_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT0_20_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT0_20_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_20_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_20_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_20_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT0_20_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT0_20_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT0_20_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_20_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_20_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_20_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_20_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT0_20_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT0_20_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_20_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_20_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_20_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT0_22 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT0_22_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT0_22_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT0_22_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_22_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_22_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_22_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_22_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT0_22_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT0_22_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_22_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_22_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_22_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT0_22_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT0_22_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT0_22_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_22_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_22_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_22_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_22_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT0_22_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT0_22_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_22_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_22_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_22_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT0_24 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT0_24_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT0_24_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT0_24_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_24_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_24_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_24_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_24_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT0_24_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT0_24_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_24_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_24_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_24_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT0_24_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT0_24_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT0_24_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_24_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_24_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_24_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_24_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT0_24_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT0_24_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_24_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_24_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_24_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT0_26 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT0_26_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT0_26_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT0_26_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_26_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_26_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_26_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_26_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT0_26_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT0_26_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_26_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_26_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_26_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT0_26_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT0_26_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT0_26_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_26_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_26_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_26_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_26_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT0_26_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT0_26_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_26_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_26_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_26_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT0_28 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT0_28_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT0_28_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT0_28_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_28_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_28_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_28_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_28_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT0_28_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT0_28_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_28_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_28_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_28_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT0_28_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT0_28_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT0_28_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_28_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_28_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_28_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_28_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT0_28_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT0_28_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_28_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_28_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_28_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT0_30 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT0_30_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT0_30_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT0_30_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_30_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_30_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_30_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_30_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT0_30_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT0_30_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_30_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_30_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_30_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT0_30_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT0_30_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT0_30_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_30_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_30_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_30_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT0_30_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT0_30_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT0_30_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT0_30_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT0_30_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT0_30_VCANb_H_MASK)
/*! @} */

/*! @name SRFLT0_0 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT0_0_SDUa_L_MASK   (0xFFU)
#define CANXL_FILTER_BANK_SRFLT0_0_SDUa_L_SHIFT  (0U)
#define CANXL_FILTER_BANK_SRFLT0_0_SDUa_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT0_0_SDUa_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_0_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_0_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_0_SDUa_H_MASK   (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT0_0_SDUa_H_SHIFT  (8U)
#define CANXL_FILTER_BANK_SRFLT0_0_SDUa_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT0_0_SDUa_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_0_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_0_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT0_0_SDUb_L_MASK   (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT0_0_SDUb_L_SHIFT  (16U)
#define CANXL_FILTER_BANK_SRFLT0_0_SDUb_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT0_0_SDUb_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_0_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_0_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_0_SDUb_H_MASK   (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT0_0_SDUb_H_SHIFT  (24U)
#define CANXL_FILTER_BANK_SRFLT0_0_SDUb_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT0_0_SDUb_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_0_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_0_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT0_2 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT0_2_SDUa_L_MASK   (0xFFU)
#define CANXL_FILTER_BANK_SRFLT0_2_SDUa_L_SHIFT  (0U)
#define CANXL_FILTER_BANK_SRFLT0_2_SDUa_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT0_2_SDUa_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_2_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_2_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_2_SDUa_H_MASK   (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT0_2_SDUa_H_SHIFT  (8U)
#define CANXL_FILTER_BANK_SRFLT0_2_SDUa_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT0_2_SDUa_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_2_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_2_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT0_2_SDUb_L_MASK   (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT0_2_SDUb_L_SHIFT  (16U)
#define CANXL_FILTER_BANK_SRFLT0_2_SDUb_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT0_2_SDUb_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_2_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_2_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_2_SDUb_H_MASK   (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT0_2_SDUb_H_SHIFT  (24U)
#define CANXL_FILTER_BANK_SRFLT0_2_SDUb_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT0_2_SDUb_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_2_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_2_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT0_4 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT0_4_SDUa_L_MASK   (0xFFU)
#define CANXL_FILTER_BANK_SRFLT0_4_SDUa_L_SHIFT  (0U)
#define CANXL_FILTER_BANK_SRFLT0_4_SDUa_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT0_4_SDUa_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_4_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_4_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_4_SDUa_H_MASK   (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT0_4_SDUa_H_SHIFT  (8U)
#define CANXL_FILTER_BANK_SRFLT0_4_SDUa_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT0_4_SDUa_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_4_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_4_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT0_4_SDUb_L_MASK   (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT0_4_SDUb_L_SHIFT  (16U)
#define CANXL_FILTER_BANK_SRFLT0_4_SDUb_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT0_4_SDUb_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_4_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_4_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_4_SDUb_H_MASK   (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT0_4_SDUb_H_SHIFT  (24U)
#define CANXL_FILTER_BANK_SRFLT0_4_SDUb_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT0_4_SDUb_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_4_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_4_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT0_6 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT0_6_SDUa_L_MASK   (0xFFU)
#define CANXL_FILTER_BANK_SRFLT0_6_SDUa_L_SHIFT  (0U)
#define CANXL_FILTER_BANK_SRFLT0_6_SDUa_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT0_6_SDUa_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_6_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_6_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_6_SDUa_H_MASK   (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT0_6_SDUa_H_SHIFT  (8U)
#define CANXL_FILTER_BANK_SRFLT0_6_SDUa_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT0_6_SDUa_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_6_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_6_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT0_6_SDUb_L_MASK   (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT0_6_SDUb_L_SHIFT  (16U)
#define CANXL_FILTER_BANK_SRFLT0_6_SDUb_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT0_6_SDUb_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_6_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_6_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_6_SDUb_H_MASK   (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT0_6_SDUb_H_SHIFT  (24U)
#define CANXL_FILTER_BANK_SRFLT0_6_SDUb_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT0_6_SDUb_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_6_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_6_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT0_8 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT0_8_SDUa_L_MASK   (0xFFU)
#define CANXL_FILTER_BANK_SRFLT0_8_SDUa_L_SHIFT  (0U)
#define CANXL_FILTER_BANK_SRFLT0_8_SDUa_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT0_8_SDUa_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_8_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_8_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_8_SDUa_H_MASK   (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT0_8_SDUa_H_SHIFT  (8U)
#define CANXL_FILTER_BANK_SRFLT0_8_SDUa_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT0_8_SDUa_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_8_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_8_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT0_8_SDUb_L_MASK   (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT0_8_SDUb_L_SHIFT  (16U)
#define CANXL_FILTER_BANK_SRFLT0_8_SDUb_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT0_8_SDUb_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_8_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_8_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_8_SDUb_H_MASK   (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT0_8_SDUb_H_SHIFT  (24U)
#define CANXL_FILTER_BANK_SRFLT0_8_SDUb_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT0_8_SDUb_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_8_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_8_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT0_10 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT0_10_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT0_10_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT0_10_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_10_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_10_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_10_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_10_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT0_10_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT0_10_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_10_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_10_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_10_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT0_10_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT0_10_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT0_10_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_10_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_10_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_10_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_10_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT0_10_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT0_10_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_10_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_10_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_10_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT0_12 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT0_12_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT0_12_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT0_12_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_12_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_12_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_12_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_12_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT0_12_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT0_12_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_12_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_12_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_12_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT0_12_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT0_12_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT0_12_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_12_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_12_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_12_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_12_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT0_12_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT0_12_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_12_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_12_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_12_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT0_14 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT0_14_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT0_14_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT0_14_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_14_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_14_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_14_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_14_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT0_14_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT0_14_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_14_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_14_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_14_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT0_14_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT0_14_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT0_14_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_14_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_14_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_14_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_14_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT0_14_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT0_14_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_14_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_14_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_14_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT0_16 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT0_16_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT0_16_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT0_16_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_16_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_16_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_16_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_16_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT0_16_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT0_16_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_16_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_16_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_16_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT0_16_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT0_16_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT0_16_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_16_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_16_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_16_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_16_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT0_16_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT0_16_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_16_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_16_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_16_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT0_18 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT0_18_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT0_18_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT0_18_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_18_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_18_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_18_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_18_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT0_18_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT0_18_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_18_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_18_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_18_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT0_18_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT0_18_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT0_18_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_18_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_18_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_18_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_18_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT0_18_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT0_18_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_18_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_18_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_18_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT0_20 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT0_20_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT0_20_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT0_20_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_20_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_20_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_20_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_20_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT0_20_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT0_20_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_20_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_20_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_20_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT0_20_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT0_20_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT0_20_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_20_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_20_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_20_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_20_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT0_20_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT0_20_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_20_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_20_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_20_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT0_22 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT0_22_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT0_22_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT0_22_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_22_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_22_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_22_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_22_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT0_22_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT0_22_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_22_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_22_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_22_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT0_22_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT0_22_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT0_22_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_22_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_22_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_22_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_22_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT0_22_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT0_22_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_22_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_22_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_22_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT0_24 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT0_24_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT0_24_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT0_24_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_24_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_24_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_24_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_24_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT0_24_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT0_24_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_24_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_24_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_24_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT0_24_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT0_24_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT0_24_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_24_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_24_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_24_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_24_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT0_24_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT0_24_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_24_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_24_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_24_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT0_26 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT0_26_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT0_26_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT0_26_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_26_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_26_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_26_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_26_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT0_26_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT0_26_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_26_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_26_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_26_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT0_26_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT0_26_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT0_26_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_26_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_26_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_26_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_26_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT0_26_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT0_26_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_26_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_26_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_26_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT0_28 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT0_28_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT0_28_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT0_28_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_28_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_28_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_28_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_28_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT0_28_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT0_28_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_28_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_28_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_28_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT0_28_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT0_28_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT0_28_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_28_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_28_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_28_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_28_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT0_28_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT0_28_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_28_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_28_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_28_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT0_30 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT0_30_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT0_30_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT0_30_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_30_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_30_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_30_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_30_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT0_30_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT0_30_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_30_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_30_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_30_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT0_30_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT0_30_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT0_30_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_30_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_30_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_30_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT0_30_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT0_30_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT0_30_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT0_30_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT0_30_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT0_30_SDUb_H_MASK)
/*! @} */

/*! @name ARFLT0_0L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_0L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_0L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_0L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_0L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_0L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_0L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_0H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_0H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_0H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_0H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_0H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_0H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_0H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_1L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_1L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_1L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_1L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_1L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_1L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_1L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_1H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_1H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_1H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_1H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_1H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_1H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_1H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_2L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_2L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_2L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_2L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_2L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_2L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_2L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_2H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_2H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_2H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_2H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_2H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_2H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_2H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_3L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_3L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_3L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_3L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_3L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_3L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_3L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_3H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_3H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_3H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_3H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_3H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_3H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_3H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_4L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_4L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_4L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_4L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_4L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_4L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_4L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_4H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_4H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_4H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_4H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_4H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_4H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_4H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_5L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_5L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_5L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_5L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_5L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_5L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_5L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_5H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_5H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_5H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_5H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_5H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_5H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_5H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_6L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_6L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_6L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_6L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_6L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_6L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_6L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_6H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_6H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_6H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_6H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_6H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_6H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_6H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_7L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_7L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_7L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_7L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_7L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_7L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_7L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_7H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_7H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_7H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_7H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_7H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_7H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_7H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_8L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_8L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_8L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_8L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_8L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_8L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_8L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_8H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_8H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_8H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_8H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_8H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_8H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_8H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_9L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_9L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_9L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_9L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_9L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_9L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_9L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_9H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_9H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_9H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_9H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_9H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_9H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_9H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_10L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_10L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_10L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_10L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_10L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_10L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_10L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_10H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_10H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_10H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_10H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_10H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_10H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_10H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_11L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_11L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_11L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_11L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_11L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_11L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_11L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_11H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_11H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_11H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_11H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_11H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_11H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_11H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_12L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_12L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_12L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_12L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_12L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_12L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_12L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_12H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_12H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_12H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_12H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_12H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_12H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_12H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_13L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_13L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_13L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_13L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_13L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_13L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_13L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_13H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_13H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_13H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_13H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_13H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_13H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_13H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_14L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_14L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_14L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_14L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_14L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_14L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_14L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_14H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_14H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_14H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_14H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_14H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_14H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_14H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_15L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_15L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_15L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_15L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_15L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_15L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_15L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_15H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_15H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_15H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_15H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_15H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_15H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_15H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_16L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_16L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_16L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_16L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_16L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_16L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_16L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_16H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_16H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_16H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_16H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_16H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_16H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_16H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_17L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_17L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_17L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_17L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_17L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_17L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_17L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_17H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_17H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_17H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_17H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_17H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_17H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_17H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_18L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_18L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_18L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_18L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_18L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_18L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_18L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_18H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_18H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_18H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_18H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_18H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_18H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_18H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_19L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_19L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_19L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_19L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_19L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_19L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_19L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_19H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_19H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_19H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_19H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_19H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_19H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_19H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_20L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_20L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_20L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_20L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_20L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_20L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_20L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_20H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_20H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_20H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_20H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_20H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_20H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_20H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_21L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_21L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_21L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_21L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_21L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_21L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_21L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_21H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_21H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_21H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_21H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_21H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_21H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_21H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_22L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_22L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_22L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_22L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_22L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_22L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_22L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_22H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_22H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_22H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_22H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_22H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_22H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_22H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_23L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_23L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_23L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_23L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_23L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_23L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_23L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_23H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_23H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_23H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_23H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_23H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_23H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_23H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_24L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_24L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_24L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_24L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_24L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_24L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_24L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_24H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_24H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_24H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_24H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_24H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_24H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_24H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_25L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_25L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_25L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_25L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_25L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_25L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_25L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_25H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_25H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_25H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_25H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_25H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_25H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_25H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_26L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_26L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_26L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_26L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_26L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_26L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_26L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_26H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_26H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_26H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_26H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_26H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_26H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_26H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_27L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_27L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_27L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_27L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_27L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_27L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_27L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_27H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_27H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_27H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_27H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_27H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_27H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_27H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_28L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_28L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_28L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_28L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_28L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_28L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_28L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_28H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_28H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_28H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_28H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_28H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_28H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_28H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_29L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_29L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_29L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_29L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_29L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_29L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_29L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_29H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_29H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_29H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_29H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_29H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_29H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_29H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_30L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_30L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_30L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_30L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_30L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_30L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_30L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_30H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_30H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_30H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_30H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_30H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_30H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_30H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT0_31L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_31L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_31L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_31L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_31L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_31L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_31L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT0_31H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT0_31H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT0_31H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT0_31H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT0_31H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT0_31H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT0_31H_ADDRn_H_MASK)
/*! @} */

/*! @name AFCFG1 - Acceptance Filter Configuration */
/*! @{ */

#define CANXL_FILTER_BANK_AFCFG1_ACPTVCAN_MASK   (0x1FU)
#define CANXL_FILTER_BANK_AFCFG1_ACPTVCAN_SHIFT  (0U)
#define CANXL_FILTER_BANK_AFCFG1_ACPTVCAN_WIDTH  (5U)
#define CANXL_FILTER_BANK_AFCFG1_ACPTVCAN(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AFCFG1_ACPTVCAN_SHIFT)) & CANXL_FILTER_BANK_AFCFG1_ACPTVCAN_MASK)

#define CANXL_FILTER_BANK_AFCFG1_AVCANEN_MASK    (0x80U)
#define CANXL_FILTER_BANK_AFCFG1_AVCANEN_SHIFT   (7U)
#define CANXL_FILTER_BANK_AFCFG1_AVCANEN_WIDTH   (1U)
#define CANXL_FILTER_BANK_AFCFG1_AVCANEN(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AFCFG1_AVCANEN_SHIFT)) & CANXL_FILTER_BANK_AFCFG1_AVCANEN_MASK)

#define CANXL_FILTER_BANK_AFCFG1_ACPTSDU_MASK    (0x1F00U)
#define CANXL_FILTER_BANK_AFCFG1_ACPTSDU_SHIFT   (8U)
#define CANXL_FILTER_BANK_AFCFG1_ACPTSDU_WIDTH   (5U)
#define CANXL_FILTER_BANK_AFCFG1_ACPTSDU(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AFCFG1_ACPTSDU_SHIFT)) & CANXL_FILTER_BANK_AFCFG1_ACPTSDU_MASK)

#define CANXL_FILTER_BANK_AFCFG1_ASDUEN_MASK     (0x8000U)
#define CANXL_FILTER_BANK_AFCFG1_ASDUEN_SHIFT    (15U)
#define CANXL_FILTER_BANK_AFCFG1_ASDUEN_WIDTH    (1U)
#define CANXL_FILTER_BANK_AFCFG1_ASDUEN(x)       (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AFCFG1_ASDUEN_SHIFT)) & CANXL_FILTER_BANK_AFCFG1_ASDUEN_MASK)

#define CANXL_FILTER_BANK_AFCFG1_ACPTADDR_MASK   (0x1F0000U)
#define CANXL_FILTER_BANK_AFCFG1_ACPTADDR_SHIFT  (16U)
#define CANXL_FILTER_BANK_AFCFG1_ACPTADDR_WIDTH  (5U)
#define CANXL_FILTER_BANK_AFCFG1_ACPTADDR(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AFCFG1_ACPTADDR_SHIFT)) & CANXL_FILTER_BANK_AFCFG1_ACPTADDR_MASK)

#define CANXL_FILTER_BANK_AFCFG1_AADDREN_MASK    (0x800000U)
#define CANXL_FILTER_BANK_AFCFG1_AADDREN_SHIFT   (23U)
#define CANXL_FILTER_BANK_AFCFG1_AADDREN_WIDTH   (1U)
#define CANXL_FILTER_BANK_AFCFG1_AADDREN(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AFCFG1_AADDREN_SHIFT)) & CANXL_FILTER_BANK_AFCFG1_AADDREN_MASK)
/*! @} */

/*! @name VAMRCFG1 - VCAN Acceptance Mask or Range Configuration */
/*! @{ */

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R0_MASK  (0x1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R0_SHIFT (0U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R0_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R0(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R0_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R0_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R1_MASK  (0x2U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R1_SHIFT (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R1_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R1(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R1_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R1_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R2_MASK  (0x4U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R2_SHIFT (2U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R2_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R2(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R2_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R2_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R3_MASK  (0x8U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R3_SHIFT (3U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R3_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R3(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R3_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R3_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R4_MASK  (0x10U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R4_SHIFT (4U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R4_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R4(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R4_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R4_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R5_MASK  (0x20U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R5_SHIFT (5U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R5_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R5(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R5_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R5_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R6_MASK  (0x40U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R6_SHIFT (6U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R6_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R6(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R6_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R6_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R7_MASK  (0x80U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R7_SHIFT (7U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R7_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R7(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R7_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R7_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R8_MASK  (0x100U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R8_SHIFT (8U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R8_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R8(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R8_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R8_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R9_MASK  (0x200U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R9_SHIFT (9U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R9_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R9(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R9_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R9_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R10_MASK (0x400U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R10_SHIFT (10U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R10_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R10(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R10_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R10_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R11_MASK (0x800U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R11_SHIFT (11U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R11_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R11(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R11_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R11_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R12_MASK (0x1000U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R12_SHIFT (12U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R12_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R12(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R12_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R12_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R13_MASK (0x2000U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R13_SHIFT (13U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R13_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R13(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R13_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R13_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R14_MASK (0x4000U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R14_SHIFT (14U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R14_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R14(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R14_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R14_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R15_MASK (0x8000U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R15_SHIFT (15U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R15_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R15(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R15_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R15_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R16_MASK (0x10000U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R16_SHIFT (16U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R16_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R16(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R16_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R16_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R17_MASK (0x20000U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R17_SHIFT (17U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R17_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R17(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R17_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R17_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R18_MASK (0x40000U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R18_SHIFT (18U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R18_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R18(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R18_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R18_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R19_MASK (0x80000U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R19_SHIFT (19U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R19_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R19(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R19_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R19_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R20_MASK (0x100000U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R20_SHIFT (20U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R20_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R20(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R20_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R20_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R21_MASK (0x200000U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R21_SHIFT (21U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R21_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R21(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R21_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R21_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R22_MASK (0x400000U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R22_SHIFT (22U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R22_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R22(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R22_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R22_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R23_MASK (0x800000U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R23_SHIFT (23U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R23_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R23(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R23_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R23_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R24_MASK (0x1000000U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R24_SHIFT (24U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R24_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R24(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R24_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R24_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R25_MASK (0x2000000U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R25_SHIFT (25U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R25_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R25(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R25_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R25_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R26_MASK (0x4000000U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R26_SHIFT (26U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R26_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R26(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R26_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R26_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R27_MASK (0x8000000U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R27_SHIFT (27U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R27_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R27(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R27_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R27_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R28_MASK (0x10000000U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R28_SHIFT (28U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R28_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R28(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R28_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R28_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R29_MASK (0x20000000U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R29_SHIFT (29U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R29_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R29(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R29_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R29_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R30_MASK (0x40000000U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R30_SHIFT (30U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R30_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R30(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R30_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R30_MASK)

#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R31_MASK (0x80000000U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R31_SHIFT (31U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R31_WIDTH (1U)
#define CANXL_FILTER_BANK_VAMRCFG1_VMSK0R31(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAMRCFG1_VMSK0R31_SHIFT)) & CANXL_FILTER_BANK_VAMRCFG1_VMSK0R31_MASK)
/*! @} */

/*! @name SAMRCFG1 - SDU Acceptance Mask or Range Configuration */
/*! @{ */

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R0_MASK  (0x1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R0_SHIFT (0U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R0_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R0(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R0_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R0_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R1_MASK  (0x2U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R1_SHIFT (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R1_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R1(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R1_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R1_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R2_MASK  (0x4U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R2_SHIFT (2U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R2_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R2(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R2_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R2_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R3_MASK  (0x8U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R3_SHIFT (3U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R3_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R3(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R3_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R3_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R4_MASK  (0x10U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R4_SHIFT (4U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R4_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R4(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R4_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R4_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R5_MASK  (0x20U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R5_SHIFT (5U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R5_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R5(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R5_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R5_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R6_MASK  (0x40U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R6_SHIFT (6U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R6_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R6(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R6_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R6_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R7_MASK  (0x80U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R7_SHIFT (7U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R7_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R7(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R7_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R7_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R8_MASK  (0x100U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R8_SHIFT (8U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R8_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R8(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R8_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R8_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R9_MASK  (0x200U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R9_SHIFT (9U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R9_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R9(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R9_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R9_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R10_MASK (0x400U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R10_SHIFT (10U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R10_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R10(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R10_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R10_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R11_MASK (0x800U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R11_SHIFT (11U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R11_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R11(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R11_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R11_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R12_MASK (0x1000U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R12_SHIFT (12U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R12_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R12(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R12_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R12_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R13_MASK (0x2000U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R13_SHIFT (13U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R13_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R13(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R13_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R13_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R14_MASK (0x4000U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R14_SHIFT (14U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R14_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R14(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R14_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R14_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R15_MASK (0x8000U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R15_SHIFT (15U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R15_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R15(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R15_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R15_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R16_MASK (0x10000U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R16_SHIFT (16U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R16_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R16(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R16_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R16_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R17_MASK (0x20000U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R17_SHIFT (17U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R17_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R17(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R17_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R17_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R18_MASK (0x40000U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R18_SHIFT (18U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R18_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R18(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R18_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R18_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R19_MASK (0x80000U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R19_SHIFT (19U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R19_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R19(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R19_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R19_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R20_MASK (0x100000U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R20_SHIFT (20U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R20_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R20(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R20_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R20_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R21_MASK (0x200000U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R21_SHIFT (21U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R21_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R21(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R21_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R21_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R22_MASK (0x400000U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R22_SHIFT (22U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R22_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R22(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R22_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R22_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R23_MASK (0x800000U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R23_SHIFT (23U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R23_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R23(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R23_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R23_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R24_MASK (0x1000000U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R24_SHIFT (24U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R24_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R24(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R24_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R24_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R25_MASK (0x2000000U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R25_SHIFT (25U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R25_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R25(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R25_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R25_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R26_MASK (0x4000000U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R26_SHIFT (26U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R26_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R26(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R26_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R26_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R27_MASK (0x8000000U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R27_SHIFT (27U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R27_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R27(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R27_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R27_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R28_MASK (0x10000000U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R28_SHIFT (28U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R28_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R28(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R28_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R28_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R29_MASK (0x20000000U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R29_SHIFT (29U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R29_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R29(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R29_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R29_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R30_MASK (0x40000000U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R30_SHIFT (30U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R30_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R30(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R30_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R30_MASK)

#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R31_MASK (0x80000000U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R31_SHIFT (31U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R31_WIDTH (1U)
#define CANXL_FILTER_BANK_SAMRCFG1_SMSK0R31(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAMRCFG1_SMSK0R31_SHIFT)) & CANXL_FILTER_BANK_SAMRCFG1_SMSK0R31_MASK)
/*! @} */

/*! @name AAMRCFG1 - ADDR Acceptance Mask or Range Configuration */
/*! @{ */

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R0_MASK  (0x1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R0_SHIFT (0U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R0_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R0(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R0_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R0_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R1_MASK  (0x2U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R1_SHIFT (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R1_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R1(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R1_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R1_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R2_MASK  (0x4U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R2_SHIFT (2U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R2_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R2(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R2_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R2_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R3_MASK  (0x8U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R3_SHIFT (3U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R3_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R3(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R3_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R3_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R4_MASK  (0x10U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R4_SHIFT (4U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R4_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R4(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R4_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R4_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R5_MASK  (0x20U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R5_SHIFT (5U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R5_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R5(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R5_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R5_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R6_MASK  (0x40U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R6_SHIFT (6U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R6_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R6(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R6_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R6_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R7_MASK  (0x80U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R7_SHIFT (7U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R7_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R7(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R7_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R7_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R8_MASK  (0x100U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R8_SHIFT (8U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R8_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R8(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R8_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R8_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R9_MASK  (0x200U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R9_SHIFT (9U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R9_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R9(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R9_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R9_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R10_MASK (0x400U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R10_SHIFT (10U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R10_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R10(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R10_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R10_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R11_MASK (0x800U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R11_SHIFT (11U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R11_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R11(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R11_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R11_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R12_MASK (0x1000U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R12_SHIFT (12U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R12_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R12(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R12_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R12_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R13_MASK (0x2000U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R13_SHIFT (13U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R13_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R13(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R13_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R13_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R14_MASK (0x4000U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R14_SHIFT (14U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R14_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R14(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R14_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R14_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R15_MASK (0x8000U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R15_SHIFT (15U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R15_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R15(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R15_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R15_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R16_MASK (0x10000U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R16_SHIFT (16U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R16_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R16(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R16_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R16_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R17_MASK (0x20000U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R17_SHIFT (17U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R17_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R17(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R17_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R17_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R18_MASK (0x40000U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R18_SHIFT (18U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R18_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R18(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R18_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R18_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R19_MASK (0x80000U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R19_SHIFT (19U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R19_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R19(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R19_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R19_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R20_MASK (0x100000U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R20_SHIFT (20U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R20_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R20(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R20_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R20_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R21_MASK (0x200000U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R21_SHIFT (21U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R21_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R21(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R21_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R21_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R22_MASK (0x400000U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R22_SHIFT (22U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R22_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R22(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R22_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R22_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R23_MASK (0x800000U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R23_SHIFT (23U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R23_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R23(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R23_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R23_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R24_MASK (0x1000000U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R24_SHIFT (24U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R24_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R24(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R24_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R24_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R25_MASK (0x2000000U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R25_SHIFT (25U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R25_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R25(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R25_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R25_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R26_MASK (0x4000000U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R26_SHIFT (26U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R26_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R26(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R26_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R26_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R27_MASK (0x8000000U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R27_SHIFT (27U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R27_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R27(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R27_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R27_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R28_MASK (0x10000000U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R28_SHIFT (28U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R28_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R28(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R28_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R28_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R29_MASK (0x20000000U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R29_SHIFT (29U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R29_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R29(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R29_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R29_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R30_MASK (0x40000000U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R30_SHIFT (30U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R30_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R30(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R30_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R30_MASK)

#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R31_MASK (0x80000000U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R31_SHIFT (31U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R31_WIDTH (1U)
#define CANXL_FILTER_BANK_AAMRCFG1_AMSK0R31(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAMRCFG1_AMSK0R31_SHIFT)) & CANXL_FILTER_BANK_AAMRCFG1_AMSK0R31_MASK)
/*! @} */

/*! @name VAFLT1_0 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT1_0_VCANa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_VAFLT1_0_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT1_0_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_0_VCANa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_0_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_0_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_0_VCANa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT1_0_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT1_0_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_0_VCANa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_0_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_0_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT1_0_VCANb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT1_0_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT1_0_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_0_VCANb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_0_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_0_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_0_VCANb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT1_0_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT1_0_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_0_VCANb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_0_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_0_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT1_2 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT1_2_VCANa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_VAFLT1_2_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT1_2_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_2_VCANa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_2_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_2_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_2_VCANa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT1_2_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT1_2_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_2_VCANa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_2_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_2_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT1_2_VCANb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT1_2_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT1_2_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_2_VCANb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_2_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_2_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_2_VCANb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT1_2_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT1_2_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_2_VCANb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_2_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_2_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT1_4 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT1_4_VCANa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_VAFLT1_4_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT1_4_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_4_VCANa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_4_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_4_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_4_VCANa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT1_4_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT1_4_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_4_VCANa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_4_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_4_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT1_4_VCANb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT1_4_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT1_4_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_4_VCANb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_4_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_4_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_4_VCANb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT1_4_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT1_4_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_4_VCANb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_4_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_4_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT1_6 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT1_6_VCANa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_VAFLT1_6_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT1_6_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_6_VCANa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_6_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_6_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_6_VCANa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT1_6_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT1_6_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_6_VCANa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_6_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_6_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT1_6_VCANb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT1_6_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT1_6_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_6_VCANb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_6_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_6_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_6_VCANb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT1_6_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT1_6_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_6_VCANb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_6_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_6_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT1_8 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT1_8_VCANa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_VAFLT1_8_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT1_8_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_8_VCANa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_8_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_8_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_8_VCANa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT1_8_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT1_8_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_8_VCANa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_8_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_8_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT1_8_VCANb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT1_8_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT1_8_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_8_VCANb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_8_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_8_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_8_VCANb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT1_8_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT1_8_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_8_VCANb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_8_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_8_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT1_10 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT1_10_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT1_10_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT1_10_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_10_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_10_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_10_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_10_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT1_10_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT1_10_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_10_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_10_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_10_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT1_10_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT1_10_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT1_10_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_10_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_10_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_10_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_10_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT1_10_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT1_10_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_10_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_10_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_10_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT1_12 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT1_12_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT1_12_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT1_12_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_12_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_12_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_12_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_12_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT1_12_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT1_12_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_12_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_12_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_12_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT1_12_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT1_12_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT1_12_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_12_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_12_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_12_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_12_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT1_12_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT1_12_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_12_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_12_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_12_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT1_14 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT1_14_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT1_14_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT1_14_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_14_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_14_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_14_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_14_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT1_14_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT1_14_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_14_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_14_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_14_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT1_14_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT1_14_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT1_14_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_14_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_14_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_14_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_14_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT1_14_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT1_14_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_14_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_14_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_14_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT1_16 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT1_16_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT1_16_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT1_16_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_16_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_16_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_16_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_16_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT1_16_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT1_16_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_16_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_16_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_16_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT1_16_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT1_16_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT1_16_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_16_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_16_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_16_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_16_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT1_16_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT1_16_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_16_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_16_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_16_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT1_18 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT1_18_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT1_18_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT1_18_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_18_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_18_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_18_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_18_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT1_18_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT1_18_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_18_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_18_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_18_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT1_18_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT1_18_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT1_18_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_18_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_18_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_18_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_18_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT1_18_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT1_18_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_18_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_18_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_18_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT1_20 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT1_20_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT1_20_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT1_20_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_20_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_20_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_20_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_20_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT1_20_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT1_20_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_20_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_20_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_20_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT1_20_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT1_20_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT1_20_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_20_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_20_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_20_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_20_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT1_20_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT1_20_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_20_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_20_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_20_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT1_22 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT1_22_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT1_22_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT1_22_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_22_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_22_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_22_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_22_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT1_22_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT1_22_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_22_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_22_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_22_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT1_22_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT1_22_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT1_22_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_22_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_22_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_22_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_22_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT1_22_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT1_22_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_22_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_22_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_22_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT1_24 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT1_24_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT1_24_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT1_24_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_24_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_24_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_24_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_24_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT1_24_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT1_24_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_24_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_24_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_24_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT1_24_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT1_24_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT1_24_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_24_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_24_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_24_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_24_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT1_24_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT1_24_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_24_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_24_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_24_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT1_26 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT1_26_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT1_26_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT1_26_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_26_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_26_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_26_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_26_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT1_26_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT1_26_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_26_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_26_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_26_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT1_26_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT1_26_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT1_26_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_26_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_26_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_26_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_26_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT1_26_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT1_26_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_26_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_26_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_26_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT1_28 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT1_28_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT1_28_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT1_28_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_28_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_28_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_28_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_28_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT1_28_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT1_28_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_28_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_28_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_28_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT1_28_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT1_28_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT1_28_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_28_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_28_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_28_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_28_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT1_28_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT1_28_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_28_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_28_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_28_VCANb_H_MASK)
/*! @} */

/*! @name VAFLT1_30 - VCAN Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VAFLT1_30_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VAFLT1_30_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VAFLT1_30_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_30_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_30_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_30_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_30_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VAFLT1_30_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VAFLT1_30_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_30_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_30_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_30_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VAFLT1_30_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VAFLT1_30_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VAFLT1_30_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_30_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_30_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_30_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VAFLT1_30_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VAFLT1_30_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VAFLT1_30_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VAFLT1_30_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VAFLT1_30_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VAFLT1_30_VCANb_H_MASK)
/*! @} */

/*! @name SAFLT1_0 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT1_0_SDUa_L_MASK   (0xFFU)
#define CANXL_FILTER_BANK_SAFLT1_0_SDUa_L_SHIFT  (0U)
#define CANXL_FILTER_BANK_SAFLT1_0_SDUa_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT1_0_SDUa_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_0_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_0_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_0_SDUa_H_MASK   (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT1_0_SDUa_H_SHIFT  (8U)
#define CANXL_FILTER_BANK_SAFLT1_0_SDUa_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT1_0_SDUa_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_0_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_0_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT1_0_SDUb_L_MASK   (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT1_0_SDUb_L_SHIFT  (16U)
#define CANXL_FILTER_BANK_SAFLT1_0_SDUb_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT1_0_SDUb_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_0_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_0_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_0_SDUb_H_MASK   (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT1_0_SDUb_H_SHIFT  (24U)
#define CANXL_FILTER_BANK_SAFLT1_0_SDUb_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT1_0_SDUb_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_0_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_0_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT1_2 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT1_2_SDUa_L_MASK   (0xFFU)
#define CANXL_FILTER_BANK_SAFLT1_2_SDUa_L_SHIFT  (0U)
#define CANXL_FILTER_BANK_SAFLT1_2_SDUa_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT1_2_SDUa_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_2_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_2_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_2_SDUa_H_MASK   (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT1_2_SDUa_H_SHIFT  (8U)
#define CANXL_FILTER_BANK_SAFLT1_2_SDUa_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT1_2_SDUa_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_2_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_2_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT1_2_SDUb_L_MASK   (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT1_2_SDUb_L_SHIFT  (16U)
#define CANXL_FILTER_BANK_SAFLT1_2_SDUb_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT1_2_SDUb_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_2_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_2_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_2_SDUb_H_MASK   (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT1_2_SDUb_H_SHIFT  (24U)
#define CANXL_FILTER_BANK_SAFLT1_2_SDUb_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT1_2_SDUb_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_2_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_2_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT1_4 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT1_4_SDUa_L_MASK   (0xFFU)
#define CANXL_FILTER_BANK_SAFLT1_4_SDUa_L_SHIFT  (0U)
#define CANXL_FILTER_BANK_SAFLT1_4_SDUa_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT1_4_SDUa_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_4_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_4_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_4_SDUa_H_MASK   (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT1_4_SDUa_H_SHIFT  (8U)
#define CANXL_FILTER_BANK_SAFLT1_4_SDUa_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT1_4_SDUa_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_4_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_4_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT1_4_SDUb_L_MASK   (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT1_4_SDUb_L_SHIFT  (16U)
#define CANXL_FILTER_BANK_SAFLT1_4_SDUb_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT1_4_SDUb_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_4_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_4_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_4_SDUb_H_MASK   (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT1_4_SDUb_H_SHIFT  (24U)
#define CANXL_FILTER_BANK_SAFLT1_4_SDUb_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT1_4_SDUb_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_4_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_4_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT1_6 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT1_6_SDUa_L_MASK   (0xFFU)
#define CANXL_FILTER_BANK_SAFLT1_6_SDUa_L_SHIFT  (0U)
#define CANXL_FILTER_BANK_SAFLT1_6_SDUa_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT1_6_SDUa_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_6_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_6_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_6_SDUa_H_MASK   (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT1_6_SDUa_H_SHIFT  (8U)
#define CANXL_FILTER_BANK_SAFLT1_6_SDUa_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT1_6_SDUa_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_6_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_6_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT1_6_SDUb_L_MASK   (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT1_6_SDUb_L_SHIFT  (16U)
#define CANXL_FILTER_BANK_SAFLT1_6_SDUb_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT1_6_SDUb_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_6_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_6_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_6_SDUb_H_MASK   (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT1_6_SDUb_H_SHIFT  (24U)
#define CANXL_FILTER_BANK_SAFLT1_6_SDUb_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT1_6_SDUb_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_6_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_6_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT1_8 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT1_8_SDUa_L_MASK   (0xFFU)
#define CANXL_FILTER_BANK_SAFLT1_8_SDUa_L_SHIFT  (0U)
#define CANXL_FILTER_BANK_SAFLT1_8_SDUa_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT1_8_SDUa_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_8_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_8_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_8_SDUa_H_MASK   (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT1_8_SDUa_H_SHIFT  (8U)
#define CANXL_FILTER_BANK_SAFLT1_8_SDUa_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT1_8_SDUa_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_8_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_8_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT1_8_SDUb_L_MASK   (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT1_8_SDUb_L_SHIFT  (16U)
#define CANXL_FILTER_BANK_SAFLT1_8_SDUb_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT1_8_SDUb_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_8_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_8_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_8_SDUb_H_MASK   (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT1_8_SDUb_H_SHIFT  (24U)
#define CANXL_FILTER_BANK_SAFLT1_8_SDUb_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SAFLT1_8_SDUb_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_8_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_8_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT1_10 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT1_10_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT1_10_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT1_10_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_10_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_10_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_10_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_10_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT1_10_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT1_10_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_10_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_10_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_10_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT1_10_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT1_10_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT1_10_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_10_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_10_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_10_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_10_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT1_10_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT1_10_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_10_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_10_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_10_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT1_12 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT1_12_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT1_12_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT1_12_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_12_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_12_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_12_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_12_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT1_12_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT1_12_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_12_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_12_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_12_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT1_12_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT1_12_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT1_12_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_12_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_12_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_12_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_12_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT1_12_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT1_12_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_12_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_12_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_12_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT1_14 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT1_14_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT1_14_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT1_14_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_14_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_14_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_14_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_14_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT1_14_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT1_14_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_14_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_14_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_14_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT1_14_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT1_14_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT1_14_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_14_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_14_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_14_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_14_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT1_14_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT1_14_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_14_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_14_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_14_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT1_16 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT1_16_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT1_16_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT1_16_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_16_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_16_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_16_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_16_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT1_16_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT1_16_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_16_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_16_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_16_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT1_16_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT1_16_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT1_16_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_16_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_16_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_16_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_16_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT1_16_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT1_16_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_16_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_16_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_16_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT1_18 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT1_18_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT1_18_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT1_18_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_18_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_18_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_18_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_18_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT1_18_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT1_18_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_18_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_18_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_18_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT1_18_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT1_18_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT1_18_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_18_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_18_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_18_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_18_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT1_18_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT1_18_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_18_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_18_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_18_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT1_20 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT1_20_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT1_20_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT1_20_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_20_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_20_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_20_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_20_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT1_20_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT1_20_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_20_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_20_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_20_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT1_20_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT1_20_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT1_20_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_20_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_20_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_20_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_20_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT1_20_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT1_20_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_20_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_20_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_20_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT1_22 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT1_22_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT1_22_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT1_22_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_22_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_22_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_22_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_22_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT1_22_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT1_22_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_22_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_22_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_22_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT1_22_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT1_22_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT1_22_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_22_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_22_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_22_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_22_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT1_22_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT1_22_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_22_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_22_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_22_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT1_24 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT1_24_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT1_24_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT1_24_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_24_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_24_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_24_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_24_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT1_24_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT1_24_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_24_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_24_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_24_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT1_24_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT1_24_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT1_24_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_24_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_24_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_24_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_24_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT1_24_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT1_24_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_24_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_24_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_24_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT1_26 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT1_26_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT1_26_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT1_26_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_26_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_26_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_26_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_26_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT1_26_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT1_26_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_26_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_26_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_26_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT1_26_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT1_26_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT1_26_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_26_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_26_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_26_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_26_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT1_26_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT1_26_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_26_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_26_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_26_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT1_28 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT1_28_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT1_28_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT1_28_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_28_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_28_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_28_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_28_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT1_28_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT1_28_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_28_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_28_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_28_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT1_28_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT1_28_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT1_28_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_28_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_28_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_28_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_28_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT1_28_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT1_28_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_28_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_28_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_28_SDUb_H_MASK)
/*! @} */

/*! @name SAFLT1_30 - SDU Acceptance Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SAFLT1_30_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SAFLT1_30_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SAFLT1_30_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_30_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_30_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_30_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_30_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SAFLT1_30_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SAFLT1_30_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_30_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_30_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_30_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SAFLT1_30_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SAFLT1_30_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SAFLT1_30_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_30_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_30_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_30_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SAFLT1_30_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SAFLT1_30_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SAFLT1_30_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SAFLT1_30_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SAFLT1_30_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SAFLT1_30_SDUb_H_MASK)
/*! @} */

/*! @name AAFLT1_0L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_0L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_0L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_0L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_0L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_0L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_0L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_0H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_0H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_0H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_0H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_0H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_0H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_0H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_1L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_1L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_1L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_1L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_1L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_1L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_1L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_1H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_1H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_1H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_1H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_1H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_1H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_1H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_2L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_2L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_2L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_2L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_2L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_2L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_2L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_2H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_2H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_2H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_2H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_2H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_2H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_2H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_3L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_3L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_3L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_3L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_3L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_3L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_3L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_3H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_3H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_3H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_3H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_3H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_3H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_3H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_4L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_4L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_4L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_4L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_4L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_4L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_4L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_4H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_4H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_4H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_4H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_4H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_4H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_4H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_5L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_5L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_5L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_5L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_5L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_5L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_5L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_5H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_5H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_5H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_5H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_5H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_5H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_5H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_6L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_6L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_6L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_6L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_6L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_6L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_6L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_6H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_6H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_6H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_6H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_6H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_6H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_6H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_7L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_7L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_7L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_7L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_7L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_7L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_7L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_7H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_7H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_7H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_7H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_7H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_7H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_7H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_8L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_8L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_8L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_8L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_8L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_8L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_8L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_8H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_8H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_8H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_8H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_8H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_8H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_8H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_9L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_9L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_9L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_9L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_9L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_9L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_9L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_9H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_9H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_9H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_9H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_9H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_9H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_9H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_10L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_10L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_10L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_10L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_10L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_10L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_10L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_10H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_10H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_10H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_10H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_10H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_10H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_10H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_11L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_11L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_11L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_11L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_11L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_11L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_11L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_11H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_11H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_11H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_11H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_11H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_11H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_11H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_12L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_12L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_12L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_12L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_12L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_12L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_12L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_12H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_12H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_12H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_12H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_12H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_12H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_12H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_13L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_13L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_13L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_13L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_13L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_13L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_13L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_13H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_13H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_13H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_13H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_13H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_13H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_13H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_14L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_14L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_14L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_14L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_14L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_14L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_14L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_14H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_14H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_14H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_14H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_14H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_14H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_14H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_15L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_15L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_15L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_15L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_15L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_15L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_15L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_15H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_15H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_15H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_15H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_15H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_15H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_15H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_16L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_16L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_16L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_16L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_16L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_16L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_16L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_16H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_16H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_16H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_16H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_16H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_16H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_16H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_17L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_17L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_17L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_17L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_17L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_17L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_17L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_17H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_17H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_17H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_17H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_17H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_17H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_17H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_18L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_18L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_18L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_18L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_18L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_18L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_18L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_18H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_18H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_18H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_18H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_18H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_18H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_18H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_19L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_19L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_19L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_19L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_19L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_19L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_19L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_19H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_19H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_19H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_19H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_19H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_19H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_19H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_20L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_20L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_20L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_20L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_20L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_20L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_20L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_20H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_20H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_20H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_20H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_20H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_20H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_20H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_21L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_21L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_21L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_21L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_21L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_21L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_21L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_21H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_21H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_21H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_21H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_21H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_21H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_21H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_22L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_22L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_22L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_22L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_22L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_22L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_22L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_22H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_22H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_22H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_22H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_22H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_22H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_22H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_23L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_23L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_23L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_23L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_23L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_23L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_23L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_23H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_23H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_23H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_23H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_23H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_23H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_23H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_24L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_24L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_24L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_24L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_24L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_24L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_24L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_24H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_24H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_24H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_24H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_24H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_24H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_24H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_25L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_25L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_25L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_25L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_25L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_25L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_25L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_25H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_25H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_25H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_25H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_25H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_25H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_25H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_26L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_26L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_26L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_26L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_26L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_26L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_26L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_26H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_26H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_26H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_26H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_26H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_26H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_26H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_27L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_27L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_27L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_27L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_27L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_27L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_27L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_27H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_27H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_27H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_27H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_27H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_27H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_27H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_28L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_28L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_28L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_28L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_28L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_28L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_28L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_28H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_28H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_28H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_28H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_28H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_28H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_28H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_29L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_29L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_29L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_29L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_29L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_29L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_29L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_29H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_29H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_29H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_29H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_29H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_29H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_29H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_30L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_30L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_30L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_30L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_30L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_30L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_30L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_30H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_30H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_30H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_30H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_30H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_30H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_30H_ADDRn_H_MASK)
/*! @} */

/*! @name AAFLT1_31L - ADDR Acceptance Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_31L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_31L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_31L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_31L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_31L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_31L_ADDRn_L_MASK)
/*! @} */

/*! @name AAFLT1_31H - ADDR Acceptance Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_AAFLT1_31H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_AAFLT1_31H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_AAFLT1_31H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_AAFLT1_31H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_AAFLT1_31H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_AAFLT1_31H_ADDRn_H_MASK)
/*! @} */

/*! @name RFCFG1 - Rejection Filter Configuration */
/*! @{ */

#define CANXL_FILTER_BANK_RFCFG1_REJVCAN_MASK    (0x1FU)
#define CANXL_FILTER_BANK_RFCFG1_REJVCAN_SHIFT   (0U)
#define CANXL_FILTER_BANK_RFCFG1_REJVCAN_WIDTH   (5U)
#define CANXL_FILTER_BANK_RFCFG1_REJVCAN(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_RFCFG1_REJVCAN_SHIFT)) & CANXL_FILTER_BANK_RFCFG1_REJVCAN_MASK)

#define CANXL_FILTER_BANK_RFCFG1_RVCANEN_MASK    (0x80U)
#define CANXL_FILTER_BANK_RFCFG1_RVCANEN_SHIFT   (7U)
#define CANXL_FILTER_BANK_RFCFG1_RVCANEN_WIDTH   (1U)
#define CANXL_FILTER_BANK_RFCFG1_RVCANEN(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_RFCFG1_RVCANEN_SHIFT)) & CANXL_FILTER_BANK_RFCFG1_RVCANEN_MASK)

#define CANXL_FILTER_BANK_RFCFG1_REJSDU_MASK     (0x1F00U)
#define CANXL_FILTER_BANK_RFCFG1_REJSDU_SHIFT    (8U)
#define CANXL_FILTER_BANK_RFCFG1_REJSDU_WIDTH    (5U)
#define CANXL_FILTER_BANK_RFCFG1_REJSDU(x)       (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_RFCFG1_REJSDU_SHIFT)) & CANXL_FILTER_BANK_RFCFG1_REJSDU_MASK)

#define CANXL_FILTER_BANK_RFCFG1_RSDUEN_MASK     (0x8000U)
#define CANXL_FILTER_BANK_RFCFG1_RSDUEN_SHIFT    (15U)
#define CANXL_FILTER_BANK_RFCFG1_RSDUEN_WIDTH    (1U)
#define CANXL_FILTER_BANK_RFCFG1_RSDUEN(x)       (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_RFCFG1_RSDUEN_SHIFT)) & CANXL_FILTER_BANK_RFCFG1_RSDUEN_MASK)

#define CANXL_FILTER_BANK_RFCFG1_REJADDR_MASK    (0x1F0000U)
#define CANXL_FILTER_BANK_RFCFG1_REJADDR_SHIFT   (16U)
#define CANXL_FILTER_BANK_RFCFG1_REJADDR_WIDTH   (5U)
#define CANXL_FILTER_BANK_RFCFG1_REJADDR(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_RFCFG1_REJADDR_SHIFT)) & CANXL_FILTER_BANK_RFCFG1_REJADDR_MASK)

#define CANXL_FILTER_BANK_RFCFG1_RADDREN_MASK    (0x800000U)
#define CANXL_FILTER_BANK_RFCFG1_RADDREN_SHIFT   (23U)
#define CANXL_FILTER_BANK_RFCFG1_RADDREN_WIDTH   (1U)
#define CANXL_FILTER_BANK_RFCFG1_RADDREN(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_RFCFG1_RADDREN_SHIFT)) & CANXL_FILTER_BANK_RFCFG1_RADDREN_MASK)
/*! @} */

/*! @name VRMRCFG1 - VCAN Rejection Mask or Range Configuration */
/*! @{ */

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R0_MASK  (0x1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R0_SHIFT (0U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R0_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R0(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R0_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R0_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R1_MASK  (0x2U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R1_SHIFT (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R1_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R1(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R1_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R1_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R2_MASK  (0x4U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R2_SHIFT (2U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R2_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R2(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R2_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R2_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R3_MASK  (0x8U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R3_SHIFT (3U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R3_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R3(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R3_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R3_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R4_MASK  (0x10U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R4_SHIFT (4U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R4_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R4(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R4_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R4_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R5_MASK  (0x20U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R5_SHIFT (5U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R5_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R5(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R5_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R5_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R6_MASK  (0x40U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R6_SHIFT (6U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R6_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R6(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R6_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R6_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R7_MASK  (0x80U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R7_SHIFT (7U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R7_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R7(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R7_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R7_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R8_MASK  (0x100U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R8_SHIFT (8U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R8_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R8(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R8_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R8_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R9_MASK  (0x200U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R9_SHIFT (9U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R9_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R9(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R9_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R9_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R10_MASK (0x400U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R10_SHIFT (10U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R10_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R10(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R10_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R10_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R11_MASK (0x800U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R11_SHIFT (11U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R11_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R11(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R11_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R11_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R12_MASK (0x1000U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R12_SHIFT (12U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R12_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R12(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R12_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R12_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R13_MASK (0x2000U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R13_SHIFT (13U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R13_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R13(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R13_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R13_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R14_MASK (0x4000U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R14_SHIFT (14U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R14_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R14(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R14_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R14_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R15_MASK (0x8000U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R15_SHIFT (15U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R15_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R15(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R15_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R15_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R16_MASK (0x10000U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R16_SHIFT (16U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R16_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R16(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R16_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R16_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R17_MASK (0x20000U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R17_SHIFT (17U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R17_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R17(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R17_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R17_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R18_MASK (0x40000U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R18_SHIFT (18U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R18_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R18(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R18_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R18_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R19_MASK (0x80000U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R19_SHIFT (19U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R19_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R19(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R19_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R19_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R20_MASK (0x100000U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R20_SHIFT (20U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R20_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R20(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R20_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R20_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R21_MASK (0x200000U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R21_SHIFT (21U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R21_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R21(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R21_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R21_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R22_MASK (0x400000U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R22_SHIFT (22U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R22_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R22(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R22_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R22_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R23_MASK (0x800000U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R23_SHIFT (23U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R23_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R23(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R23_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R23_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R24_MASK (0x1000000U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R24_SHIFT (24U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R24_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R24(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R24_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R24_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R25_MASK (0x2000000U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R25_SHIFT (25U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R25_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R25(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R25_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R25_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R26_MASK (0x4000000U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R26_SHIFT (26U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R26_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R26(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R26_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R26_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R27_MASK (0x8000000U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R27_SHIFT (27U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R27_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R27(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R27_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R27_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R28_MASK (0x10000000U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R28_SHIFT (28U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R28_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R28(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R28_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R28_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R29_MASK (0x20000000U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R29_SHIFT (29U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R29_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R29(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R29_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R29_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R30_MASK (0x40000000U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R30_SHIFT (30U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R30_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R30(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R30_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R30_MASK)

#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R31_MASK (0x80000000U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R31_SHIFT (31U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R31_WIDTH (1U)
#define CANXL_FILTER_BANK_VRMRCFG1_VMSK0R31(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRMRCFG1_VMSK0R31_SHIFT)) & CANXL_FILTER_BANK_VRMRCFG1_VMSK0R31_MASK)
/*! @} */

/*! @name SRMRCFG1 - SDU Rejection Mask or Range Configuration */
/*! @{ */

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R0_MASK  (0x1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R0_SHIFT (0U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R0_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R0(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R0_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R0_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R1_MASK  (0x2U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R1_SHIFT (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R1_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R1(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R1_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R1_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R2_MASK  (0x4U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R2_SHIFT (2U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R2_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R2(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R2_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R2_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R3_MASK  (0x8U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R3_SHIFT (3U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R3_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R3(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R3_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R3_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R4_MASK  (0x10U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R4_SHIFT (4U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R4_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R4(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R4_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R4_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R5_MASK  (0x20U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R5_SHIFT (5U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R5_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R5(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R5_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R5_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R6_MASK  (0x40U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R6_SHIFT (6U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R6_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R6(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R6_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R6_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R7_MASK  (0x80U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R7_SHIFT (7U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R7_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R7(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R7_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R7_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R8_MASK  (0x100U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R8_SHIFT (8U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R8_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R8(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R8_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R8_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R9_MASK  (0x200U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R9_SHIFT (9U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R9_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R9(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R9_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R9_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R10_MASK (0x400U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R10_SHIFT (10U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R10_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R10(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R10_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R10_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R11_MASK (0x800U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R11_SHIFT (11U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R11_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R11(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R11_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R11_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R12_MASK (0x1000U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R12_SHIFT (12U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R12_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R12(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R12_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R12_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R13_MASK (0x2000U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R13_SHIFT (13U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R13_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R13(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R13_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R13_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R14_MASK (0x4000U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R14_SHIFT (14U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R14_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R14(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R14_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R14_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R15_MASK (0x8000U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R15_SHIFT (15U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R15_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R15(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R15_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R15_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R16_MASK (0x10000U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R16_SHIFT (16U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R16_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R16(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R16_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R16_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R17_MASK (0x20000U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R17_SHIFT (17U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R17_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R17(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R17_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R17_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R18_MASK (0x40000U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R18_SHIFT (18U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R18_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R18(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R18_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R18_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R19_MASK (0x80000U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R19_SHIFT (19U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R19_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R19(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R19_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R19_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R20_MASK (0x100000U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R20_SHIFT (20U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R20_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R20(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R20_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R20_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R21_MASK (0x200000U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R21_SHIFT (21U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R21_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R21(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R21_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R21_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R22_MASK (0x400000U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R22_SHIFT (22U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R22_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R22(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R22_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R22_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R23_MASK (0x800000U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R23_SHIFT (23U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R23_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R23(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R23_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R23_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R24_MASK (0x1000000U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R24_SHIFT (24U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R24_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R24(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R24_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R24_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R25_MASK (0x2000000U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R25_SHIFT (25U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R25_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R25(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R25_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R25_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R26_MASK (0x4000000U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R26_SHIFT (26U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R26_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R26(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R26_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R26_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R27_MASK (0x8000000U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R27_SHIFT (27U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R27_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R27(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R27_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R27_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R28_MASK (0x10000000U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R28_SHIFT (28U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R28_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R28(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R28_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R28_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R29_MASK (0x20000000U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R29_SHIFT (29U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R29_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R29(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R29_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R29_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R30_MASK (0x40000000U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R30_SHIFT (30U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R30_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R30(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R30_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R30_MASK)

#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R31_MASK (0x80000000U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R31_SHIFT (31U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R31_WIDTH (1U)
#define CANXL_FILTER_BANK_SRMRCFG1_SMSK0R31(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRMRCFG1_SMSK0R31_SHIFT)) & CANXL_FILTER_BANK_SRMRCFG1_SMSK0R31_MASK)
/*! @} */

/*! @name ARMRCFG1 - ADDR Rejection Mask or Range Configuration */
/*! @{ */

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R0_MASK  (0x1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R0_SHIFT (0U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R0_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R0(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R0_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R0_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R1_MASK  (0x2U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R1_SHIFT (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R1_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R1(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R1_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R1_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R2_MASK  (0x4U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R2_SHIFT (2U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R2_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R2(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R2_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R2_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R3_MASK  (0x8U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R3_SHIFT (3U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R3_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R3(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R3_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R3_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R4_MASK  (0x10U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R4_SHIFT (4U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R4_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R4(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R4_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R4_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R5_MASK  (0x20U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R5_SHIFT (5U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R5_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R5(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R5_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R5_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R6_MASK  (0x40U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R6_SHIFT (6U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R6_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R6(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R6_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R6_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R7_MASK  (0x80U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R7_SHIFT (7U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R7_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R7(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R7_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R7_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R8_MASK  (0x100U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R8_SHIFT (8U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R8_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R8(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R8_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R8_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R9_MASK  (0x200U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R9_SHIFT (9U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R9_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R9(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R9_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R9_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R10_MASK (0x400U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R10_SHIFT (10U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R10_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R10(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R10_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R10_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R11_MASK (0x800U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R11_SHIFT (11U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R11_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R11(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R11_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R11_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R12_MASK (0x1000U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R12_SHIFT (12U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R12_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R12(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R12_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R12_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R13_MASK (0x2000U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R13_SHIFT (13U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R13_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R13(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R13_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R13_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R14_MASK (0x4000U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R14_SHIFT (14U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R14_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R14(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R14_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R14_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R15_MASK (0x8000U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R15_SHIFT (15U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R15_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R15(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R15_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R15_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R16_MASK (0x10000U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R16_SHIFT (16U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R16_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R16(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R16_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R16_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R17_MASK (0x20000U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R17_SHIFT (17U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R17_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R17(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R17_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R17_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R18_MASK (0x40000U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R18_SHIFT (18U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R18_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R18(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R18_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R18_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R19_MASK (0x80000U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R19_SHIFT (19U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R19_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R19(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R19_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R19_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R20_MASK (0x100000U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R20_SHIFT (20U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R20_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R20(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R20_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R20_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R21_MASK (0x200000U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R21_SHIFT (21U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R21_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R21(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R21_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R21_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R22_MASK (0x400000U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R22_SHIFT (22U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R22_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R22(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R22_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R22_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R23_MASK (0x800000U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R23_SHIFT (23U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R23_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R23(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R23_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R23_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R24_MASK (0x1000000U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R24_SHIFT (24U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R24_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R24(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R24_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R24_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R25_MASK (0x2000000U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R25_SHIFT (25U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R25_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R25(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R25_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R25_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R26_MASK (0x4000000U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R26_SHIFT (26U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R26_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R26(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R26_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R26_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R27_MASK (0x8000000U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R27_SHIFT (27U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R27_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R27(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R27_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R27_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R28_MASK (0x10000000U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R28_SHIFT (28U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R28_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R28(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R28_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R28_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R29_MASK (0x20000000U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R29_SHIFT (29U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R29_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R29(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R29_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R29_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R30_MASK (0x40000000U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R30_SHIFT (30U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R30_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R30(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R30_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R30_MASK)

#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R31_MASK (0x80000000U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R31_SHIFT (31U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R31_WIDTH (1U)
#define CANXL_FILTER_BANK_ARMRCFG1_AMSK0R31(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARMRCFG1_AMSK0R31_SHIFT)) & CANXL_FILTER_BANK_ARMRCFG1_AMSK0R31_MASK)
/*! @} */

/*! @name VRFLT1_0 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT1_0_VCANa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_VRFLT1_0_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT1_0_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_0_VCANa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_0_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_0_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_0_VCANa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT1_0_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT1_0_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_0_VCANa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_0_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_0_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT1_0_VCANb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT1_0_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT1_0_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_0_VCANb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_0_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_0_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_0_VCANb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT1_0_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT1_0_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_0_VCANb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_0_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_0_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT1_2 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT1_2_VCANa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_VRFLT1_2_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT1_2_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_2_VCANa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_2_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_2_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_2_VCANa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT1_2_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT1_2_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_2_VCANa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_2_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_2_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT1_2_VCANb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT1_2_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT1_2_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_2_VCANb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_2_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_2_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_2_VCANb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT1_2_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT1_2_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_2_VCANb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_2_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_2_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT1_4 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT1_4_VCANa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_VRFLT1_4_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT1_4_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_4_VCANa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_4_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_4_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_4_VCANa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT1_4_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT1_4_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_4_VCANa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_4_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_4_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT1_4_VCANb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT1_4_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT1_4_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_4_VCANb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_4_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_4_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_4_VCANb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT1_4_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT1_4_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_4_VCANb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_4_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_4_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT1_6 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT1_6_VCANa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_VRFLT1_6_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT1_6_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_6_VCANa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_6_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_6_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_6_VCANa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT1_6_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT1_6_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_6_VCANa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_6_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_6_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT1_6_VCANb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT1_6_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT1_6_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_6_VCANb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_6_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_6_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_6_VCANb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT1_6_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT1_6_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_6_VCANb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_6_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_6_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT1_8 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT1_8_VCANa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_VRFLT1_8_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT1_8_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_8_VCANa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_8_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_8_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_8_VCANa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT1_8_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT1_8_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_8_VCANa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_8_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_8_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT1_8_VCANb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT1_8_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT1_8_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_8_VCANb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_8_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_8_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_8_VCANb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT1_8_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT1_8_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_8_VCANb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_8_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_8_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT1_10 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT1_10_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT1_10_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT1_10_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_10_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_10_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_10_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_10_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT1_10_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT1_10_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_10_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_10_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_10_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT1_10_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT1_10_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT1_10_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_10_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_10_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_10_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_10_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT1_10_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT1_10_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_10_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_10_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_10_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT1_12 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT1_12_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT1_12_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT1_12_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_12_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_12_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_12_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_12_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT1_12_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT1_12_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_12_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_12_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_12_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT1_12_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT1_12_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT1_12_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_12_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_12_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_12_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_12_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT1_12_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT1_12_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_12_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_12_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_12_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT1_14 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT1_14_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT1_14_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT1_14_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_14_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_14_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_14_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_14_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT1_14_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT1_14_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_14_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_14_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_14_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT1_14_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT1_14_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT1_14_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_14_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_14_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_14_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_14_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT1_14_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT1_14_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_14_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_14_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_14_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT1_16 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT1_16_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT1_16_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT1_16_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_16_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_16_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_16_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_16_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT1_16_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT1_16_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_16_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_16_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_16_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT1_16_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT1_16_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT1_16_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_16_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_16_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_16_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_16_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT1_16_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT1_16_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_16_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_16_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_16_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT1_18 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT1_18_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT1_18_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT1_18_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_18_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_18_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_18_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_18_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT1_18_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT1_18_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_18_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_18_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_18_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT1_18_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT1_18_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT1_18_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_18_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_18_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_18_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_18_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT1_18_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT1_18_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_18_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_18_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_18_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT1_20 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT1_20_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT1_20_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT1_20_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_20_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_20_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_20_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_20_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT1_20_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT1_20_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_20_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_20_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_20_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT1_20_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT1_20_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT1_20_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_20_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_20_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_20_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_20_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT1_20_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT1_20_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_20_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_20_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_20_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT1_22 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT1_22_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT1_22_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT1_22_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_22_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_22_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_22_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_22_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT1_22_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT1_22_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_22_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_22_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_22_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT1_22_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT1_22_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT1_22_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_22_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_22_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_22_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_22_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT1_22_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT1_22_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_22_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_22_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_22_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT1_24 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT1_24_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT1_24_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT1_24_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_24_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_24_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_24_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_24_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT1_24_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT1_24_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_24_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_24_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_24_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT1_24_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT1_24_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT1_24_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_24_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_24_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_24_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_24_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT1_24_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT1_24_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_24_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_24_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_24_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT1_26 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT1_26_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT1_26_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT1_26_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_26_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_26_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_26_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_26_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT1_26_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT1_26_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_26_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_26_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_26_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT1_26_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT1_26_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT1_26_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_26_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_26_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_26_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_26_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT1_26_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT1_26_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_26_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_26_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_26_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT1_28 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT1_28_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT1_28_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT1_28_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_28_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_28_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_28_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_28_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT1_28_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT1_28_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_28_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_28_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_28_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT1_28_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT1_28_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT1_28_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_28_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_28_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_28_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_28_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT1_28_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT1_28_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_28_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_28_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_28_VCANb_H_MASK)
/*! @} */

/*! @name VRFLT1_30 - VCAN Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_VRFLT1_30_VCANa_L_MASK (0xFFU)
#define CANXL_FILTER_BANK_VRFLT1_30_VCANa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_VRFLT1_30_VCANa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_30_VCANa_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_30_VCANa_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_30_VCANa_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_30_VCANa_H_MASK (0xFF00U)
#define CANXL_FILTER_BANK_VRFLT1_30_VCANa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_VRFLT1_30_VCANa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_30_VCANa_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_30_VCANa_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_30_VCANa_H_MASK)

#define CANXL_FILTER_BANK_VRFLT1_30_VCANb_L_MASK (0xFF0000U)
#define CANXL_FILTER_BANK_VRFLT1_30_VCANb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_VRFLT1_30_VCANb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_30_VCANb_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_30_VCANb_L_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_30_VCANb_L_MASK)

#define CANXL_FILTER_BANK_VRFLT1_30_VCANb_H_MASK (0xFF000000U)
#define CANXL_FILTER_BANK_VRFLT1_30_VCANb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_VRFLT1_30_VCANb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_VRFLT1_30_VCANb_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_VRFLT1_30_VCANb_H_SHIFT)) & CANXL_FILTER_BANK_VRFLT1_30_VCANb_H_MASK)
/*! @} */

/*! @name SRFLT1_0 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT1_0_SDUa_L_MASK   (0xFFU)
#define CANXL_FILTER_BANK_SRFLT1_0_SDUa_L_SHIFT  (0U)
#define CANXL_FILTER_BANK_SRFLT1_0_SDUa_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT1_0_SDUa_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_0_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_0_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_0_SDUa_H_MASK   (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT1_0_SDUa_H_SHIFT  (8U)
#define CANXL_FILTER_BANK_SRFLT1_0_SDUa_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT1_0_SDUa_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_0_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_0_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT1_0_SDUb_L_MASK   (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT1_0_SDUb_L_SHIFT  (16U)
#define CANXL_FILTER_BANK_SRFLT1_0_SDUb_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT1_0_SDUb_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_0_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_0_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_0_SDUb_H_MASK   (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT1_0_SDUb_H_SHIFT  (24U)
#define CANXL_FILTER_BANK_SRFLT1_0_SDUb_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT1_0_SDUb_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_0_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_0_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT1_2 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT1_2_SDUa_L_MASK   (0xFFU)
#define CANXL_FILTER_BANK_SRFLT1_2_SDUa_L_SHIFT  (0U)
#define CANXL_FILTER_BANK_SRFLT1_2_SDUa_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT1_2_SDUa_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_2_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_2_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_2_SDUa_H_MASK   (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT1_2_SDUa_H_SHIFT  (8U)
#define CANXL_FILTER_BANK_SRFLT1_2_SDUa_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT1_2_SDUa_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_2_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_2_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT1_2_SDUb_L_MASK   (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT1_2_SDUb_L_SHIFT  (16U)
#define CANXL_FILTER_BANK_SRFLT1_2_SDUb_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT1_2_SDUb_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_2_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_2_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_2_SDUb_H_MASK   (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT1_2_SDUb_H_SHIFT  (24U)
#define CANXL_FILTER_BANK_SRFLT1_2_SDUb_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT1_2_SDUb_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_2_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_2_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT1_4 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT1_4_SDUa_L_MASK   (0xFFU)
#define CANXL_FILTER_BANK_SRFLT1_4_SDUa_L_SHIFT  (0U)
#define CANXL_FILTER_BANK_SRFLT1_4_SDUa_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT1_4_SDUa_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_4_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_4_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_4_SDUa_H_MASK   (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT1_4_SDUa_H_SHIFT  (8U)
#define CANXL_FILTER_BANK_SRFLT1_4_SDUa_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT1_4_SDUa_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_4_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_4_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT1_4_SDUb_L_MASK   (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT1_4_SDUb_L_SHIFT  (16U)
#define CANXL_FILTER_BANK_SRFLT1_4_SDUb_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT1_4_SDUb_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_4_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_4_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_4_SDUb_H_MASK   (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT1_4_SDUb_H_SHIFT  (24U)
#define CANXL_FILTER_BANK_SRFLT1_4_SDUb_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT1_4_SDUb_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_4_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_4_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT1_6 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT1_6_SDUa_L_MASK   (0xFFU)
#define CANXL_FILTER_BANK_SRFLT1_6_SDUa_L_SHIFT  (0U)
#define CANXL_FILTER_BANK_SRFLT1_6_SDUa_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT1_6_SDUa_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_6_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_6_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_6_SDUa_H_MASK   (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT1_6_SDUa_H_SHIFT  (8U)
#define CANXL_FILTER_BANK_SRFLT1_6_SDUa_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT1_6_SDUa_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_6_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_6_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT1_6_SDUb_L_MASK   (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT1_6_SDUb_L_SHIFT  (16U)
#define CANXL_FILTER_BANK_SRFLT1_6_SDUb_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT1_6_SDUb_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_6_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_6_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_6_SDUb_H_MASK   (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT1_6_SDUb_H_SHIFT  (24U)
#define CANXL_FILTER_BANK_SRFLT1_6_SDUb_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT1_6_SDUb_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_6_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_6_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT1_8 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT1_8_SDUa_L_MASK   (0xFFU)
#define CANXL_FILTER_BANK_SRFLT1_8_SDUa_L_SHIFT  (0U)
#define CANXL_FILTER_BANK_SRFLT1_8_SDUa_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT1_8_SDUa_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_8_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_8_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_8_SDUa_H_MASK   (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT1_8_SDUa_H_SHIFT  (8U)
#define CANXL_FILTER_BANK_SRFLT1_8_SDUa_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT1_8_SDUa_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_8_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_8_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT1_8_SDUb_L_MASK   (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT1_8_SDUb_L_SHIFT  (16U)
#define CANXL_FILTER_BANK_SRFLT1_8_SDUb_L_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT1_8_SDUb_L(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_8_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_8_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_8_SDUb_H_MASK   (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT1_8_SDUb_H_SHIFT  (24U)
#define CANXL_FILTER_BANK_SRFLT1_8_SDUb_H_WIDTH  (8U)
#define CANXL_FILTER_BANK_SRFLT1_8_SDUb_H(x)     (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_8_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_8_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT1_10 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT1_10_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT1_10_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT1_10_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_10_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_10_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_10_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_10_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT1_10_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT1_10_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_10_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_10_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_10_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT1_10_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT1_10_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT1_10_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_10_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_10_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_10_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_10_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT1_10_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT1_10_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_10_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_10_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_10_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT1_12 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT1_12_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT1_12_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT1_12_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_12_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_12_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_12_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_12_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT1_12_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT1_12_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_12_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_12_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_12_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT1_12_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT1_12_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT1_12_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_12_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_12_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_12_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_12_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT1_12_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT1_12_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_12_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_12_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_12_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT1_14 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT1_14_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT1_14_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT1_14_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_14_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_14_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_14_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_14_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT1_14_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT1_14_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_14_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_14_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_14_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT1_14_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT1_14_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT1_14_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_14_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_14_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_14_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_14_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT1_14_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT1_14_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_14_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_14_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_14_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT1_16 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT1_16_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT1_16_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT1_16_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_16_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_16_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_16_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_16_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT1_16_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT1_16_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_16_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_16_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_16_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT1_16_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT1_16_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT1_16_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_16_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_16_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_16_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_16_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT1_16_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT1_16_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_16_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_16_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_16_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT1_18 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT1_18_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT1_18_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT1_18_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_18_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_18_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_18_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_18_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT1_18_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT1_18_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_18_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_18_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_18_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT1_18_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT1_18_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT1_18_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_18_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_18_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_18_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_18_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT1_18_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT1_18_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_18_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_18_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_18_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT1_20 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT1_20_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT1_20_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT1_20_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_20_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_20_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_20_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_20_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT1_20_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT1_20_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_20_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_20_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_20_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT1_20_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT1_20_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT1_20_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_20_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_20_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_20_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_20_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT1_20_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT1_20_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_20_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_20_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_20_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT1_22 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT1_22_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT1_22_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT1_22_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_22_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_22_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_22_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_22_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT1_22_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT1_22_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_22_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_22_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_22_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT1_22_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT1_22_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT1_22_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_22_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_22_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_22_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_22_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT1_22_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT1_22_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_22_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_22_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_22_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT1_24 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT1_24_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT1_24_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT1_24_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_24_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_24_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_24_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_24_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT1_24_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT1_24_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_24_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_24_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_24_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT1_24_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT1_24_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT1_24_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_24_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_24_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_24_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_24_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT1_24_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT1_24_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_24_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_24_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_24_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT1_26 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT1_26_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT1_26_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT1_26_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_26_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_26_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_26_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_26_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT1_26_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT1_26_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_26_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_26_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_26_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT1_26_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT1_26_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT1_26_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_26_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_26_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_26_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_26_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT1_26_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT1_26_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_26_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_26_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_26_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT1_28 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT1_28_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT1_28_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT1_28_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_28_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_28_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_28_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_28_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT1_28_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT1_28_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_28_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_28_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_28_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT1_28_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT1_28_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT1_28_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_28_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_28_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_28_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_28_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT1_28_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT1_28_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_28_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_28_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_28_SDUb_H_MASK)
/*! @} */

/*! @name SRFLT1_30 - SDU Rejection Filter */
/*! @{ */

#define CANXL_FILTER_BANK_SRFLT1_30_SDUa_L_MASK  (0xFFU)
#define CANXL_FILTER_BANK_SRFLT1_30_SDUa_L_SHIFT (0U)
#define CANXL_FILTER_BANK_SRFLT1_30_SDUa_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_30_SDUa_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_30_SDUa_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_30_SDUa_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_30_SDUa_H_MASK  (0xFF00U)
#define CANXL_FILTER_BANK_SRFLT1_30_SDUa_H_SHIFT (8U)
#define CANXL_FILTER_BANK_SRFLT1_30_SDUa_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_30_SDUa_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_30_SDUa_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_30_SDUa_H_MASK)

#define CANXL_FILTER_BANK_SRFLT1_30_SDUb_L_MASK  (0xFF0000U)
#define CANXL_FILTER_BANK_SRFLT1_30_SDUb_L_SHIFT (16U)
#define CANXL_FILTER_BANK_SRFLT1_30_SDUb_L_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_30_SDUb_L(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_30_SDUb_L_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_30_SDUb_L_MASK)

#define CANXL_FILTER_BANK_SRFLT1_30_SDUb_H_MASK  (0xFF000000U)
#define CANXL_FILTER_BANK_SRFLT1_30_SDUb_H_SHIFT (24U)
#define CANXL_FILTER_BANK_SRFLT1_30_SDUb_H_WIDTH (8U)
#define CANXL_FILTER_BANK_SRFLT1_30_SDUb_H(x)    (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_SRFLT1_30_SDUb_H_SHIFT)) & CANXL_FILTER_BANK_SRFLT1_30_SDUb_H_MASK)
/*! @} */

/*! @name ARFLT1_0L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_0L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_0L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_0L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_0L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_0L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_0L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_0H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_0H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_0H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_0H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_0H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_0H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_0H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_1L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_1L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_1L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_1L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_1L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_1L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_1L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_1H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_1H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_1H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_1H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_1H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_1H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_1H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_2L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_2L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_2L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_2L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_2L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_2L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_2L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_2H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_2H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_2H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_2H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_2H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_2H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_2H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_3L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_3L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_3L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_3L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_3L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_3L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_3L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_3H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_3H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_3H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_3H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_3H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_3H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_3H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_4L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_4L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_4L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_4L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_4L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_4L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_4L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_4H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_4H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_4H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_4H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_4H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_4H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_4H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_5L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_5L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_5L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_5L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_5L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_5L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_5L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_5H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_5H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_5H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_5H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_5H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_5H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_5H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_6L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_6L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_6L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_6L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_6L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_6L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_6L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_6H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_6H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_6H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_6H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_6H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_6H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_6H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_7L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_7L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_7L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_7L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_7L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_7L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_7L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_7H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_7H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_7H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_7H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_7H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_7H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_7H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_8L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_8L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_8L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_8L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_8L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_8L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_8L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_8H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_8H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_8H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_8H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_8H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_8H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_8H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_9L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_9L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_9L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_9L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_9L_ADDRn_L(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_9L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_9L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_9H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_9H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_9H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_9H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_9H_ADDRn_H(x)   (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_9H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_9H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_10L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_10L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_10L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_10L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_10L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_10L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_10L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_10H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_10H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_10H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_10H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_10H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_10H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_10H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_11L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_11L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_11L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_11L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_11L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_11L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_11L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_11H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_11H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_11H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_11H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_11H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_11H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_11H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_12L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_12L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_12L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_12L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_12L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_12L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_12L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_12H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_12H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_12H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_12H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_12H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_12H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_12H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_13L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_13L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_13L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_13L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_13L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_13L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_13L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_13H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_13H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_13H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_13H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_13H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_13H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_13H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_14L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_14L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_14L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_14L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_14L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_14L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_14L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_14H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_14H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_14H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_14H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_14H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_14H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_14H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_15L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_15L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_15L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_15L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_15L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_15L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_15L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_15H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_15H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_15H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_15H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_15H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_15H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_15H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_16L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_16L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_16L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_16L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_16L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_16L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_16L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_16H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_16H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_16H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_16H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_16H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_16H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_16H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_17L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_17L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_17L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_17L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_17L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_17L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_17L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_17H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_17H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_17H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_17H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_17H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_17H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_17H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_18L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_18L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_18L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_18L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_18L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_18L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_18L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_18H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_18H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_18H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_18H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_18H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_18H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_18H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_19L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_19L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_19L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_19L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_19L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_19L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_19L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_19H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_19H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_19H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_19H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_19H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_19H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_19H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_20L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_20L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_20L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_20L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_20L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_20L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_20L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_20H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_20H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_20H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_20H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_20H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_20H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_20H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_21L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_21L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_21L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_21L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_21L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_21L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_21L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_21H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_21H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_21H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_21H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_21H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_21H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_21H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_22L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_22L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_22L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_22L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_22L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_22L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_22L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_22H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_22H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_22H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_22H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_22H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_22H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_22H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_23L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_23L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_23L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_23L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_23L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_23L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_23L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_23H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_23H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_23H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_23H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_23H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_23H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_23H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_24L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_24L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_24L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_24L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_24L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_24L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_24L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_24H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_24H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_24H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_24H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_24H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_24H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_24H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_25L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_25L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_25L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_25L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_25L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_25L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_25L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_25H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_25H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_25H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_25H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_25H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_25H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_25H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_26L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_26L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_26L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_26L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_26L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_26L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_26L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_26H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_26H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_26H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_26H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_26H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_26H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_26H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_27L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_27L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_27L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_27L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_27L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_27L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_27L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_27H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_27H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_27H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_27H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_27H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_27H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_27H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_28L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_28L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_28L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_28L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_28L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_28L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_28L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_28H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_28H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_28H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_28H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_28H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_28H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_28H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_29L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_29L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_29L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_29L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_29L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_29L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_29L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_29H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_29H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_29H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_29H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_29H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_29H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_29H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_30L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_30L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_30L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_30L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_30L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_30L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_30L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_30H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_30H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_30H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_30H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_30H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_30H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_30H_ADDRn_H_MASK)
/*! @} */

/*! @name ARFLT1_31L - ADDR Rejection Filter Low */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_31L_ADDRn_L_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_31L_ADDRn_L_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_31L_ADDRn_L_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_31L_ADDRn_L(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_31L_ADDRn_L_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_31L_ADDRn_L_MASK)
/*! @} */

/*! @name ARFLT1_31H - ADDR Rejection Filter High */
/*! @{ */

#define CANXL_FILTER_BANK_ARFLT1_31H_ADDRn_H_MASK (0xFFFFFFFFU)
#define CANXL_FILTER_BANK_ARFLT1_31H_ADDRn_H_SHIFT (0U)
#define CANXL_FILTER_BANK_ARFLT1_31H_ADDRn_H_WIDTH (32U)
#define CANXL_FILTER_BANK_ARFLT1_31H_ADDRn_H(x)  (((uint32_t)(((uint32_t)(x)) << CANXL_FILTER_BANK_ARFLT1_31H_ADDRn_H_SHIFT)) & CANXL_FILTER_BANK_ARFLT1_31H_ADDRn_H_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CANXL_FILTER_BANK_Register_Masks */

/*!
 * @}
 */ /* end of group CANXL_FILTER_BANK_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_CANXL_FILTER_BANK_H_) */
