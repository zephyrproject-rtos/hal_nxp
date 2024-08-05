/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_EIM.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_EIM
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
#if !defined(S32Z2_EIM_H_)  /* Check if memory map has not been already included */
#define S32Z2_EIM_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- EIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EIM_Peripheral_Access_Layer EIM Peripheral Access Layer
 * @{
 */

/** EIM - Register Layout Typedef */
typedef struct {
  __IO uint32_t EIMCR;                             /**< Error Injection Module Configuration Register, offset: 0x0 */
  __IO uint32_t EICHEN;                            /**< Error Injection Channel Enable register, offset: 0x4 */
  uint8_t RESERVED_0[248];
  __IO uint32_t EICHD0_WORD0;                      /**< Error Injection Channel Descriptor 0, Word0, offset: 0x100, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD0_WORD1;                      /**< Error Injection Channel Descriptor 0, Word1, offset: 0x104, not available in all instances (available on 7 out of 8) */
  __IO uint32_t EICHD0_WORD2;                      /**< Error Injection Channel Descriptor 0, Word2, offset: 0x108, not available in all instances (available on 7 out of 8) */
  __IO uint32_t EICHD0_WORD3;                      /**< Error Injection Channel Descriptor 0, Word3, offset: 0x10C, not available in all instances (available on 1 out of 8) */
  uint8_t RESERVED_1[48];
  __IO uint32_t EICHD1_WORD0;                      /**< Error Injection Channel Descriptor 1, Word0, offset: 0x140, not available in all instances (available on 2 out of 8) */
  __IO uint32_t EICHD1_WORD1;                      /**< Error Injection Channel Descriptor 1, Word1, offset: 0x144, not available in all instances (available on 6 out of 8) */
  __IO uint32_t EICHD1_WORD2;                      /**< Error Injection Channel Descriptor 1, Word2, offset: 0x148, not available in all instances (available on 5 out of 8) */
  __IO uint32_t EICHD1_WORD3;                      /**< Error Injection Channel Descriptor 1, Word3, offset: 0x14C, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD1_WORD4;                      /**< Error Injection Channel Descriptor 1, Word4, offset: 0x150, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD1_WORD5;                      /**< Error Injection Channel Descriptor 1, Word5, offset: 0x154, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD1_WORD6;                      /**< Error Injection Channel Descriptor 1, Word6, offset: 0x158, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD1_WORD7;                      /**< Error Injection Channel Descriptor 1, Word7, offset: 0x15C, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD1_WORD8;                      /**< Error Injection Channel Descriptor 1, Word8, offset: 0x160, not available in all instances (available on 1 out of 8) */
  uint8_t RESERVED_2[28];
  __IO uint32_t EICHD2_WORD0;                      /**< Error Injection Channel Descriptor 2, Word0, offset: 0x180, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD2_WORD1;                      /**< Error Injection Channel Descriptor 2, Word1, offset: 0x184, not available in all instances (available on 6 out of 8) */
  __IO uint32_t EICHD2_WORD2;                      /**< Error Injection Channel Descriptor 2, Word2, offset: 0x188, not available in all instances (available on 3 out of 8) */
  uint8_t RESERVED_3[52];
  __IO uint32_t EICHD3_WORD0;                      /**< Error Injection Channel Descriptor 3, Word0, offset: 0x1C0, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD3_WORD1;                      /**< Error Injection Channel Descriptor 3, Word1, offset: 0x1C4, not available in all instances (available on 6 out of 8) */
  __IO uint32_t EICHD3_WORD2;                      /**< Error Injection Channel Descriptor 3, Word2, offset: 0x1C8, not available in all instances (available on 3 out of 8) */
  uint8_t RESERVED_4[52];
  __IO uint32_t EICHD4_WORD0;                      /**< Error Injection Channel Descriptor 4, Word0, offset: 0x200, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD4_WORD1;                      /**< Error Injection Channel Descriptor 4, Word1, offset: 0x204, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD4_WORD2;                      /**< Error Injection Channel Descriptor 4, Word2, offset: 0x208, not available in all instances (available on 1 out of 8) */
  uint8_t RESERVED_5[52];
  __IO uint32_t EICHD5_WORD0;                      /**< Error Injection Channel Descriptor 5, Word0, offset: 0x240, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD5_WORD1;                      /**< Error Injection Channel Descriptor 5, Word1, offset: 0x244, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD5_WORD2;                      /**< Error Injection Channel Descriptor 5, Word2, offset: 0x248, not available in all instances (available on 1 out of 8) */
  uint8_t RESERVED_6[52];
  __IO uint32_t EICHD6_WORD0;                      /**< Error Injection Channel Descriptor 6, Word0, offset: 0x280, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD6_WORD1;                      /**< Error Injection Channel Descriptor 6, Word1, offset: 0x284, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD6_WORD2;                      /**< Error Injection Channel Descriptor 6, Word2, offset: 0x288, not available in all instances (available on 1 out of 8) */
  uint8_t RESERVED_7[52];
  __IO uint32_t EICHD7_WORD0;                      /**< Error Injection Channel Descriptor 7, Word0, offset: 0x2C0, not available in all instances (available on 4 out of 8) */
  __IO uint32_t EICHD7_WORD1;                      /**< Error Injection Channel Descriptor 7, Word1, offset: 0x2C4, not available in all instances (available on 4 out of 8) */
  __IO uint32_t EICHD7_WORD2;                      /**< Error Injection Channel Descriptor 7, Word2, offset: 0x2C8, not available in all instances (available on 4 out of 8) */
  uint8_t RESERVED_8[52];
  __IO uint32_t EICHD8_WORD0;                      /**< Error Injection Channel Descriptor 8, Word0, offset: 0x300, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD8_WORD1;                      /**< Error Injection Channel Descriptor 8, Word1, offset: 0x304, not available in all instances (available on 4 out of 8) */
  __IO uint32_t EICHD8_WORD2;                      /**< Error Injection Channel Descriptor 8, Word2, offset: 0x308, not available in all instances (available on 4 out of 8) */
  __IO uint32_t EICHD8_WORD3;                      /**< Error Injection Channel Descriptor 8, Word3, offset: 0x30C, not available in all instances (available on 4 out of 8) */
  __IO uint32_t EICHD8_WORD4;                      /**< Error Injection Channel Descriptor 8, Word4, offset: 0x310, not available in all instances (available on 4 out of 8) */
  __IO uint32_t EICHD8_WORD5;                      /**< Error Injection Channel Descriptor 8, Word5, offset: 0x314, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD8_WORD6;                      /**< Error Injection Channel Descriptor 8, Word6, offset: 0x318, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD8_WORD7;                      /**< Error Injection Channel Descriptor 8, Word7, offset: 0x31C, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD8_WORD8;                      /**< Error Injection Channel Descriptor 8, Word8, offset: 0x320, not available in all instances (available on 1 out of 8) */
  uint8_t RESERVED_9[28];
  __IO uint32_t EICHD9_WORD0;                      /**< Error Injection Channel Descriptor 9, Word0, offset: 0x340, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD9_WORD1;                      /**< Error Injection Channel Descriptor 9, Word1, offset: 0x344, not available in all instances (available on 4 out of 8) */
  __IO uint32_t EICHD9_WORD2;                      /**< Error Injection Channel Descriptor 9, Word2, offset: 0x348, not available in all instances (available on 4 out of 8) */
  __IO uint32_t EICHD9_WORD3;                      /**< Error Injection Channel Descriptor 9, Word3, offset: 0x34C, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD9_WORD4;                      /**< Error Injection Channel Descriptor 9, Word4, offset: 0x350, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD9_WORD5;                      /**< Error Injection Channel Descriptor 9, Word5, offset: 0x354, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD9_WORD6;                      /**< Error Injection Channel Descriptor 9, Word6, offset: 0x358, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD9_WORD7;                      /**< Error Injection Channel Descriptor 9, Word7, offset: 0x35C, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD9_WORD8;                      /**< Error Injection Channel Descriptor 9, Word8, offset: 0x360, not available in all instances (available on 1 out of 8) */
  uint8_t RESERVED_10[28];
  __IO uint32_t EICHD10_WORD0;                     /**< Error Injection Channel Descriptor 10, Word0, offset: 0x380, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD10_WORD1;                     /**< Error Injection Channel Descriptor 10, Word1, offset: 0x384, not available in all instances (available on 4 out of 8) */
  __IO uint32_t EICHD10_WORD2;                     /**< Error Injection Channel Descriptor 10, Word2, offset: 0x388, not available in all instances (available on 4 out of 8) */
  __IO uint32_t EICHD10_WORD3;                     /**< Error Injection Channel Descriptor 10, Word3, offset: 0x38C, not available in all instances (available on 4 out of 8) */
  __IO uint32_t EICHD10_WORD4;                     /**< Error Injection Channel Descriptor 10, Word4, offset: 0x390, not available in all instances (available on 3 out of 8) */
  uint8_t RESERVED_11[44];
  __IO uint32_t EICHD11_WORD0;                     /**< Error Injection Channel Descriptor 11, Word0, offset: 0x3C0, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD11_WORD1;                     /**< Error Injection Channel Descriptor 11, Word1, offset: 0x3C4, not available in all instances (available on 4 out of 8) */
  __IO uint32_t EICHD11_WORD2;                     /**< Error Injection Channel Descriptor 11, Word2, offset: 0x3C8, not available in all instances (available on 3 out of 8) */
  uint8_t RESERVED_12[52];
  __IO uint32_t EICHD12_WORD0;                     /**< Error Injection Channel Descriptor 12, Word0, offset: 0x400, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD12_WORD1;                     /**< Error Injection Channel Descriptor 12, Word1, offset: 0x404, not available in all instances (available on 4 out of 8) */
  __IO uint32_t EICHD12_WORD2;                     /**< Error Injection Channel Descriptor 12, Word2, offset: 0x408, not available in all instances (available on 3 out of 8) */
  uint8_t RESERVED_13[52];
  __IO uint32_t EICHD13_WORD0;                     /**< Error Injection Channel Descriptor 13, Word0, offset: 0x440, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD13_WORD1;                     /**< Error Injection Channel Descriptor 13, Word1, offset: 0x444, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD13_WORD2;                     /**< Error Injection Channel Descriptor 13, Word2, offset: 0x448, not available in all instances (available on 3 out of 8) */
  uint8_t RESERVED_14[52];
  __IO uint32_t EICHD14_WORD0;                     /**< Error Injection Channel Descriptor 14, Word0, offset: 0x480, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD14_WORD1;                     /**< Error Injection Channel Descriptor 14, Word1, offset: 0x484, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD14_WORD2;                     /**< Error Injection Channel Descriptor 14, Word2, offset: 0x488, not available in all instances (available on 3 out of 8) */
  uint8_t RESERVED_15[52];
  __IO uint32_t EICHD15_WORD0;                     /**< Error Injection Channel Descriptor 15, Word0, offset: 0x4C0, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD15_WORD1;                     /**< Error Injection Channel Descriptor 15, Word1, offset: 0x4C4, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD15_WORD2;                     /**< Error Injection Channel Descriptor 15, Word2, offset: 0x4C8, not available in all instances (available on 3 out of 8) */
  uint8_t RESERVED_16[52];
  __IO uint32_t EICHD16_WORD0;                     /**< Error Injection Channel Descriptor 16, Word0, offset: 0x500, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD16_WORD1;                     /**< Error Injection Channel Descriptor 16, Word1, offset: 0x504, not available in all instances (available on 4 out of 8) */
  __IO uint32_t EICHD16_WORD2;                     /**< Error Injection Channel Descriptor 16, Word2, offset: 0x508, not available in all instances (available on 3 out of 8) */
  uint8_t RESERVED_17[52];
  __IO uint32_t EICHD17_WORD0;                     /**< Error Injection Channel Descriptor 17, Word0, offset: 0x540, not available in all instances (available on 2 out of 8) */
  __IO uint32_t EICHD17_WORD1;                     /**< Error Injection Channel Descriptor 17, Word1, offset: 0x544, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD17_WORD2;                     /**< Error Injection Channel Descriptor 17, Word2, offset: 0x548, not available in all instances (available on 2 out of 8) */
  uint8_t RESERVED_18[56];
  __IO uint32_t EICHD18_WORD1;                     /**< Error Injection Channel Descriptor 18, Word1, offset: 0x584, not available in all instances (available on 4 out of 8) */
  __IO uint32_t EICHD18_WORD2;                     /**< Error Injection Channel Descriptor 18, Word2, offset: 0x588, not available in all instances (available on 3 out of 8) */
  uint8_t RESERVED_19[52];
  __IO uint32_t EICHD19_WORD0;                     /**< Error Injection Channel Descriptor 19, Word0, offset: 0x5C0, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD19_WORD1;                     /**< Error Injection Channel Descriptor 19, Word1, offset: 0x5C4, not available in all instances (available on 4 out of 8) */
  __IO uint32_t EICHD19_WORD2;                     /**< Error Injection Channel Descriptor 19, Word2, offset: 0x5C8, not available in all instances (available on 4 out of 8) */
  uint8_t RESERVED_20[52];
  __IO uint32_t EICHD20_WORD0;                     /**< Error Injection Channel Descriptor 20, Word0, offset: 0x600, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD20_WORD1;                     /**< Error Injection Channel Descriptor 20, Word1, offset: 0x604, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD20_WORD2;                     /**< Error Injection Channel Descriptor 20, Word2, offset: 0x608, not available in all instances (available on 3 out of 8) */
  uint8_t RESERVED_21[52];
  __IO uint32_t EICHD21_WORD0;                     /**< Error Injection Channel Descriptor 21, Word0, offset: 0x640, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD21_WORD1;                     /**< Error Injection Channel Descriptor 21, Word1, offset: 0x644, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD21_WORD2;                     /**< Error Injection Channel Descriptor 21, Word2, offset: 0x648, not available in all instances (available on 3 out of 8) */
  uint8_t RESERVED_22[52];
  __IO uint32_t EICHD22_WORD0;                     /**< Error Injection Channel Descriptor 22, Word0, offset: 0x680, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD22_WORD1;                     /**< Error Injection Channel Descriptor 22, Word1, offset: 0x684, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD22_WORD2;                     /**< Error Injection Channel Descriptor 22, Word2, offset: 0x688, not available in all instances (available on 1 out of 8) */
  uint8_t RESERVED_23[56];
  __IO uint32_t EICHD23_WORD1;                     /**< Error Injection Channel Descriptor 23, Word1, offset: 0x6C4, not available in all instances (available on 3 out of 8) */
  uint8_t RESERVED_24[60];
  __IO uint32_t EICHD24_WORD1;                     /**< Error Injection Channel Descriptor 24, Word1, offset: 0x704, not available in all instances (available on 4 out of 8) */
  uint8_t RESERVED_25[60];
  __IO uint32_t EICHD25_WORD1;                     /**< Error Injection Channel Descriptor 25, Word1, offset: 0x744, not available in all instances (available on 1 out of 8) */
  uint8_t RESERVED_26[56];
  __IO uint32_t EICHD26_WORD0;                     /**< Error Injection Channel Descriptor 26, Word0, offset: 0x780, not available in all instances (available on 2 out of 8) */
  __IO uint32_t EICHD26_WORD1;                     /**< Error Injection Channel Descriptor 26, Word1, offset: 0x784, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD26_WORD2;                     /**< Error Injection Channel Descriptor 26, Word2, offset: 0x788, not available in all instances (available on 2 out of 8) */
  uint8_t RESERVED_27[52];
  __IO uint32_t EICHD27_WORD0;                     /**< Error Injection Channel Descriptor 27, Word0, offset: 0x7C0, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD27_WORD1;                     /**< Error Injection Channel Descriptor 27, Word1, offset: 0x7C4, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD27_WORD2;                     /**< Error Injection Channel Descriptor 27, Word2, offset: 0x7C8, not available in all instances (available on 1 out of 8) */
  uint8_t RESERVED_28[52];
  __IO uint32_t EICHD28_WORD0;                     /**< Error Injection Channel Descriptor 28, Word0, offset: 0x800, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD28_WORD1;                     /**< Error Injection Channel Descriptor 28, Word1, offset: 0x804, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD28_WORD2;                     /**< Error Injection Channel Descriptor 28, Word2, offset: 0x808, not available in all instances (available on 1 out of 8) */
  uint8_t RESERVED_29[52];
  __IO uint32_t EICHD29_WORD0;                     /**< Error Injection Channel Descriptor 29, Word0, offset: 0x840, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD29_WORD1;                     /**< Error Injection Channel Descriptor 29, Word1, offset: 0x844, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD29_WORD2;                     /**< Error Injection Channel Descriptor 29, Word2, offset: 0x848, not available in all instances (available on 1 out of 8) */
  uint8_t RESERVED_30[52];
  __IO uint32_t EICHD30_WORD0;                     /**< Error Injection Channel Descriptor 30, Word0, offset: 0x880, not available in all instances (available on 1 out of 8) */
  __IO uint32_t EICHD30_WORD1;                     /**< Error Injection Channel Descriptor 30, Word1, offset: 0x884, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD30_WORD2;                     /**< Error Injection Channel Descriptor 30, Word2, offset: 0x888, not available in all instances (available on 3 out of 8) */
  uint8_t RESERVED_31[56];
  __IO uint32_t EICHD31_WORD1;                     /**< Error Injection Channel Descriptor 31, Word1, offset: 0x8C4, not available in all instances (available on 3 out of 8) */
  __IO uint32_t EICHD31_WORD2;                     /**< Error Injection Channel Descriptor 31, Word2, offset: 0x8C8, not available in all instances (available on 2 out of 8) */
} EIM_Type, *EIM_MemMapPtr;

/** Number of instances of the EIM module. */
#define EIM_INSTANCE_COUNT                       (8u)

/* EIM - Peripheral instance base addresses */
/** Peripheral CE_EIM_0 base address */
#define IP_CE_EIM_0_BASE                         (0x44814000u)
/** Peripheral CE_EIM_0 base pointer */
#define IP_CE_EIM_0                              ((EIM_Type *)IP_CE_EIM_0_BASE)
/** Peripheral CE_EIM_1 base address */
#define IP_CE_EIM_1_BASE                         (0x4481C000u)
/** Peripheral CE_EIM_1 base pointer */
#define IP_CE_EIM_1                              ((EIM_Type *)IP_CE_EIM_1_BASE)
/** Peripheral EIM_1 base address */
#define IP_EIM_1_BASE                            (0x40880000u)
/** Peripheral EIM_1 base pointer */
#define IP_EIM_1                                 ((EIM_Type *)IP_EIM_1_BASE)
/** Peripheral EIM_2 base address */
#define IP_EIM_2_BASE                            (0x41080000u)
/** Peripheral EIM_2 base pointer */
#define IP_EIM_2                                 ((EIM_Type *)IP_EIM_2_BASE)
/** Peripheral EIM_3 base address */
#define IP_EIM_3_BASE                            (0x41880000u)
/** Peripheral EIM_3 base pointer */
#define IP_EIM_3                                 ((EIM_Type *)IP_EIM_3_BASE)
/** Peripheral RTU0__EIM base address */
#define IP_RTU0__EIM_BASE                        (0x76180000u)
/** Peripheral RTU0__EIM base pointer */
#define IP_RTU0__EIM                             ((EIM_Type *)IP_RTU0__EIM_BASE)
/** Peripheral RTU1__EIM base address */
#define IP_RTU1__EIM_BASE                        (0x76980000u)
/** Peripheral RTU1__EIM base pointer */
#define IP_RTU1__EIM                             ((EIM_Type *)IP_RTU1__EIM_BASE)
/** Peripheral SMU__EIM base address */
#define IP_SMU__EIM_BASE                         (0x45014000u)
/** Peripheral SMU__EIM base pointer */
#define IP_SMU__EIM                              ((EIM_Type *)IP_SMU__EIM_BASE)
/** Array initializer of EIM peripheral base addresses */
#define IP_EIM_BASE_ADDRS                        { IP_CE_EIM_0_BASE, IP_CE_EIM_1_BASE, IP_EIM_1_BASE, IP_EIM_2_BASE, IP_EIM_3_BASE, IP_RTU0__EIM_BASE, IP_RTU1__EIM_BASE, IP_SMU__EIM_BASE }
/** Array initializer of EIM peripheral base pointers */
#define IP_EIM_BASE_PTRS                         { IP_CE_EIM_0, IP_CE_EIM_1, IP_EIM_1, IP_EIM_2, IP_EIM_3, IP_RTU0__EIM, IP_RTU1__EIM, IP_SMU__EIM }

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

#define EIM_EICHD0_WORD0_CHKBIT_MASK_MASK        (0xFF000000U)
#define EIM_EICHD0_WORD0_CHKBIT_MASK_SHIFT       (24U)
#define EIM_EICHD0_WORD0_CHKBIT_MASK_WIDTH       (8U)
#define EIM_EICHD0_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD0_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD0_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD0_WORD1 - Error Injection Channel Descriptor 0, Word1 */
/*! @{ */

#define EIM_EICHD0_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (12, 16, 19, 32), largest definition used */
#define EIM_EICHD0_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD0_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD0_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD0_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD0_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (12, 16, 19, 32), largest definition used */
/*! @} */

/*! @name EICHD0_WORD2 - Error Injection Channel Descriptor 0, Word2 */
/*! @{ */

#define EIM_EICHD0_WORD2_B4_7DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD0_WORD2_B4_7DATA_MASK_SHIFT     (0U)
#define EIM_EICHD0_WORD2_B4_7DATA_MASK_WIDTH     (32U)
#define EIM_EICHD0_WORD2_B4_7DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD0_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD0_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD0_WORD3 - Error Injection Channel Descriptor 0, Word3 */
/*! @{ */

#define EIM_EICHD0_WORD3_B8_11DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD0_WORD3_B8_11DATA_MASK_SHIFT    (0U)
#define EIM_EICHD0_WORD3_B8_11DATA_MASK_WIDTH    (32U)
#define EIM_EICHD0_WORD3_B8_11DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD0_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_EICHD0_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD0 - Error Injection Channel Descriptor 1, Word0 */
/*! @{ */

#define EIM_EICHD1_WORD0_CHKBIT_MASK_MASK        (0xFF000000U)
#define EIM_EICHD1_WORD0_CHKBIT_MASK_SHIFT       (24U)
#define EIM_EICHD1_WORD0_CHKBIT_MASK_WIDTH       (8U)
#define EIM_EICHD1_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD1_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD1_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD1 - Error Injection Channel Descriptor 1, Word1 */
/*! @{ */

#define EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (1, 22, 32), largest definition used */
#define EIM_EICHD1_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD1_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD1_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD1_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (1, 22, 32), largest definition used */
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

/*! @name EICHD1_WORD5 - Error Injection Channel Descriptor 1, Word5 */
/*! @{ */

#define EIM_EICHD1_WORD5_B16_19DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD1_WORD5_B16_19DATA_MASK_SHIFT   (0U)
#define EIM_EICHD1_WORD5_B16_19DATA_MASK_WIDTH   (32U)
#define EIM_EICHD1_WORD5_B16_19DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD1_WORD5_B16_19DATA_MASK_SHIFT)) & EIM_EICHD1_WORD5_B16_19DATA_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD6 - Error Injection Channel Descriptor 1, Word6 */
/*! @{ */

#define EIM_EICHD1_WORD6_B20_23DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD1_WORD6_B20_23DATA_MASK_SHIFT   (0U)
#define EIM_EICHD1_WORD6_B20_23DATA_MASK_WIDTH   (32U)
#define EIM_EICHD1_WORD6_B20_23DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD1_WORD6_B20_23DATA_MASK_SHIFT)) & EIM_EICHD1_WORD6_B20_23DATA_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD7 - Error Injection Channel Descriptor 1, Word7 */
/*! @{ */

#define EIM_EICHD1_WORD7_B24_27DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD1_WORD7_B24_27DATA_MASK_SHIFT   (0U)
#define EIM_EICHD1_WORD7_B24_27DATA_MASK_WIDTH   (32U)
#define EIM_EICHD1_WORD7_B24_27DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD1_WORD7_B24_27DATA_MASK_SHIFT)) & EIM_EICHD1_WORD7_B24_27DATA_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD8 - Error Injection Channel Descriptor 1, Word8 */
/*! @{ */

#define EIM_EICHD1_WORD8_B28_31DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD1_WORD8_B28_31DATA_MASK_SHIFT   (0U)
#define EIM_EICHD1_WORD8_B28_31DATA_MASK_WIDTH   (32U)
#define EIM_EICHD1_WORD8_B28_31DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD1_WORD8_B28_31DATA_MASK_SHIFT)) & EIM_EICHD1_WORD8_B28_31DATA_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD0 - Error Injection Channel Descriptor 2, Word0 */
/*! @{ */

#define EIM_EICHD2_WORD0_CHKBIT_MASK_MASK        (0xFF000000U)
#define EIM_EICHD2_WORD0_CHKBIT_MASK_SHIFT       (24U)
#define EIM_EICHD2_WORD0_CHKBIT_MASK_WIDTH       (8U)
#define EIM_EICHD2_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD2_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD2_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD1 - Error Injection Channel Descriptor 2, Word1 */
/*! @{ */

#define EIM_EICHD2_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (1, 16, 32), largest definition used */
#define EIM_EICHD2_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD2_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD2_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD2_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD2_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (1, 16, 32), largest definition used */
/*! @} */

/*! @name EICHD2_WORD2 - Error Injection Channel Descriptor 2, Word2 */
/*! @{ */

#define EIM_EICHD2_WORD2_B4_7DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD2_WORD2_B4_7DATA_MASK_SHIFT     (0U)
#define EIM_EICHD2_WORD2_B4_7DATA_MASK_WIDTH     (32U)
#define EIM_EICHD2_WORD2_B4_7DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD2_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD2_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD0 - Error Injection Channel Descriptor 3, Word0 */
/*! @{ */

#define EIM_EICHD3_WORD0_CHKBIT_MASK_MASK        (0xFF000000U)
#define EIM_EICHD3_WORD0_CHKBIT_MASK_SHIFT       (24U)
#define EIM_EICHD3_WORD0_CHKBIT_MASK_WIDTH       (8U)
#define EIM_EICHD3_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD3_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD3_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD1 - Error Injection Channel Descriptor 3, Word1 */
/*! @{ */

#define EIM_EICHD3_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (5, 26, 32), largest definition used */
#define EIM_EICHD3_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD3_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD3_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD3_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD3_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (5, 26, 32), largest definition used */
/*! @} */

/*! @name EICHD3_WORD2 - Error Injection Channel Descriptor 3, Word2 */
/*! @{ */

#define EIM_EICHD3_WORD2_B4_7DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD3_WORD2_B4_7DATA_MASK_SHIFT     (0U)
#define EIM_EICHD3_WORD2_B4_7DATA_MASK_WIDTH     (32U)
#define EIM_EICHD3_WORD2_B4_7DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD3_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD3_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD0 - Error Injection Channel Descriptor 4, Word0 */
/*! @{ */

#define EIM_EICHD4_WORD0_CHKBIT_MASK_MASK        (0xFF000000U)
#define EIM_EICHD4_WORD0_CHKBIT_MASK_SHIFT       (24U)
#define EIM_EICHD4_WORD0_CHKBIT_MASK_WIDTH       (8U)
#define EIM_EICHD4_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD4_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD4_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD1 - Error Injection Channel Descriptor 4, Word1 */
/*! @{ */

#define EIM_EICHD4_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (23, 32), largest definition used */
#define EIM_EICHD4_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD4_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD4_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD4_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD4_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (23, 32), largest definition used */
/*! @} */

/*! @name EICHD4_WORD2 - Error Injection Channel Descriptor 4, Word2 */
/*! @{ */

#define EIM_EICHD4_WORD2_B4_7DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD4_WORD2_B4_7DATA_MASK_SHIFT     (0U)
#define EIM_EICHD4_WORD2_B4_7DATA_MASK_WIDTH     (32U)
#define EIM_EICHD4_WORD2_B4_7DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD4_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD4_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD5_WORD0 - Error Injection Channel Descriptor 5, Word0 */
/*! @{ */

#define EIM_EICHD5_WORD0_CHKBIT_MASK_MASK        (0xFF000000U)
#define EIM_EICHD5_WORD0_CHKBIT_MASK_SHIFT       (24U)
#define EIM_EICHD5_WORD0_CHKBIT_MASK_WIDTH       (8U)
#define EIM_EICHD5_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD5_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD5_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD5_WORD1 - Error Injection Channel Descriptor 5, Word1 */
/*! @{ */

#define EIM_EICHD5_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD5_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD5_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD5_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD5_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD5_WORD1_B0_3DATA_MASK_MASK)
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

#define EIM_EICHD6_WORD0_CHKBIT_MASK_MASK        (0xFF000000U)
#define EIM_EICHD6_WORD0_CHKBIT_MASK_SHIFT       (24U)
#define EIM_EICHD6_WORD0_CHKBIT_MASK_WIDTH       (8U)
#define EIM_EICHD6_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD6_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD6_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD1 - Error Injection Channel Descriptor 6, Word1 */
/*! @{ */

#define EIM_EICHD6_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD6_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD6_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD6_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD6_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD6_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD2 - Error Injection Channel Descriptor 6, Word2 */
/*! @{ */

#define EIM_EICHD6_WORD2_B4_7DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD6_WORD2_B4_7DATA_MASK_SHIFT     (0U)
#define EIM_EICHD6_WORD2_B4_7DATA_MASK_WIDTH     (32U)
#define EIM_EICHD6_WORD2_B4_7DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD6_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD6_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD0 - Error Injection Channel Descriptor 7, Word0 */
/*! @{ */

#define EIM_EICHD7_WORD0_CHKBIT_MASK_MASK        (0xFFFC0000U)  /* Merged from fields with different position or width, of widths (8, 14), largest definition used */
#define EIM_EICHD7_WORD0_CHKBIT_MASK_SHIFT       (18U)
#define EIM_EICHD7_WORD0_CHKBIT_MASK_WIDTH       (14U)
#define EIM_EICHD7_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD7_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD7_WORD0_CHKBIT_MASK_MASK)  /* Merged from fields with different position or width, of widths (8, 14), largest definition used */
/*! @} */

/*! @name EICHD7_WORD1 - Error Injection Channel Descriptor 7, Word1 */
/*! @{ */

#define EIM_EICHD7_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD7_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD7_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD7_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD7_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD7_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD2 - Error Injection Channel Descriptor 7, Word2 */
/*! @{ */

#define EIM_EICHD7_WORD2_B4_7DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD7_WORD2_B4_7DATA_MASK_SHIFT     (0U)
#define EIM_EICHD7_WORD2_B4_7DATA_MASK_WIDTH     (32U)
#define EIM_EICHD7_WORD2_B4_7DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD7_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD7_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD8_WORD0 - Error Injection Channel Descriptor 8, Word0 */
/*! @{ */

#define EIM_EICHD8_WORD0_CHKBIT_MASK_MASK        (0xFFFFFFFFU)
#define EIM_EICHD8_WORD0_CHKBIT_MASK_SHIFT       (0U)
#define EIM_EICHD8_WORD0_CHKBIT_MASK_WIDTH       (32U)
#define EIM_EICHD8_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD8_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD8_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD8_WORD1 - Error Injection Channel Descriptor 8, Word1 */
/*! @{ */

#define EIM_EICHD8_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD8_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD8_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD8_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD8_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD8_WORD1_B0_3DATA_MASK_MASK)
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

/*! @name EICHD8_WORD6 - Error Injection Channel Descriptor 8, Word6 */
/*! @{ */

#define EIM_EICHD8_WORD6_B20_23DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD8_WORD6_B20_23DATA_MASK_SHIFT   (0U)
#define EIM_EICHD8_WORD6_B20_23DATA_MASK_WIDTH   (32U)
#define EIM_EICHD8_WORD6_B20_23DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD8_WORD6_B20_23DATA_MASK_SHIFT)) & EIM_EICHD8_WORD6_B20_23DATA_MASK_MASK)
/*! @} */

/*! @name EICHD8_WORD7 - Error Injection Channel Descriptor 8, Word7 */
/*! @{ */

#define EIM_EICHD8_WORD7_B24_27DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD8_WORD7_B24_27DATA_MASK_SHIFT   (0U)
#define EIM_EICHD8_WORD7_B24_27DATA_MASK_WIDTH   (32U)
#define EIM_EICHD8_WORD7_B24_27DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD8_WORD7_B24_27DATA_MASK_SHIFT)) & EIM_EICHD8_WORD7_B24_27DATA_MASK_MASK)
/*! @} */

/*! @name EICHD8_WORD8 - Error Injection Channel Descriptor 8, Word8 */
/*! @{ */

#define EIM_EICHD8_WORD8_B28_31DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD8_WORD8_B28_31DATA_MASK_SHIFT   (0U)
#define EIM_EICHD8_WORD8_B28_31DATA_MASK_WIDTH   (32U)
#define EIM_EICHD8_WORD8_B28_31DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD8_WORD8_B28_31DATA_MASK_SHIFT)) & EIM_EICHD8_WORD8_B28_31DATA_MASK_MASK)
/*! @} */

/*! @name EICHD9_WORD0 - Error Injection Channel Descriptor 9, Word0 */
/*! @{ */

#define EIM_EICHD9_WORD0_CHKBIT_MASK_MASK        (0xFFFC0000U)
#define EIM_EICHD9_WORD0_CHKBIT_MASK_SHIFT       (18U)
#define EIM_EICHD9_WORD0_CHKBIT_MASK_WIDTH       (14U)
#define EIM_EICHD9_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD9_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD9_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD9_WORD1 - Error Injection Channel Descriptor 9, Word1 */
/*! @{ */

#define EIM_EICHD9_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD9_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD9_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD9_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD9_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD9_WORD1_B0_3DATA_MASK_MASK)
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

/*! @name EICHD9_WORD6 - Error Injection Channel Descriptor 9, Word6 */
/*! @{ */

#define EIM_EICHD9_WORD6_B20_23DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD9_WORD6_B20_23DATA_MASK_SHIFT   (0U)
#define EIM_EICHD9_WORD6_B20_23DATA_MASK_WIDTH   (32U)
#define EIM_EICHD9_WORD6_B20_23DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD9_WORD6_B20_23DATA_MASK_SHIFT)) & EIM_EICHD9_WORD6_B20_23DATA_MASK_MASK)
/*! @} */

/*! @name EICHD9_WORD7 - Error Injection Channel Descriptor 9, Word7 */
/*! @{ */

#define EIM_EICHD9_WORD7_B24_27DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD9_WORD7_B24_27DATA_MASK_SHIFT   (0U)
#define EIM_EICHD9_WORD7_B24_27DATA_MASK_WIDTH   (32U)
#define EIM_EICHD9_WORD7_B24_27DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD9_WORD7_B24_27DATA_MASK_SHIFT)) & EIM_EICHD9_WORD7_B24_27DATA_MASK_MASK)
/*! @} */

/*! @name EICHD9_WORD8 - Error Injection Channel Descriptor 9, Word8 */
/*! @{ */

#define EIM_EICHD9_WORD8_B28_31DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_EICHD9_WORD8_B28_31DATA_MASK_SHIFT   (0U)
#define EIM_EICHD9_WORD8_B28_31DATA_MASK_WIDTH   (32U)
#define EIM_EICHD9_WORD8_B28_31DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_EICHD9_WORD8_B28_31DATA_MASK_SHIFT)) & EIM_EICHD9_WORD8_B28_31DATA_MASK_MASK)
/*! @} */

/*! @name EICHD10_WORD0 - Error Injection Channel Descriptor 10, Word0 */
/*! @{ */

#define EIM_EICHD10_WORD0_CHKBIT_MASK_MASK       (0xFFFFFFFFU)
#define EIM_EICHD10_WORD0_CHKBIT_MASK_SHIFT      (0U)
#define EIM_EICHD10_WORD0_CHKBIT_MASK_WIDTH      (32U)
#define EIM_EICHD10_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD10_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD10_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD10_WORD1 - Error Injection Channel Descriptor 10, Word1 */
/*! @{ */

#define EIM_EICHD10_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (8, 32), largest definition used */
#define EIM_EICHD10_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD10_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD10_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD10_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD10_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (8, 32), largest definition used */
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

/*! @name EICHD11_WORD0 - Error Injection Channel Descriptor 11, Word0 */
/*! @{ */

#define EIM_EICHD11_WORD0_CHKBIT_MASK_MASK       (0xFF000000U)
#define EIM_EICHD11_WORD0_CHKBIT_MASK_SHIFT      (24U)
#define EIM_EICHD11_WORD0_CHKBIT_MASK_WIDTH      (8U)
#define EIM_EICHD11_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD11_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD11_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD11_WORD1 - Error Injection Channel Descriptor 11, Word1 */
/*! @{ */

#define EIM_EICHD11_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (24, 32), largest definition used */
#define EIM_EICHD11_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD11_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD11_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD11_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD11_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (24, 32), largest definition used */
/*! @} */

/*! @name EICHD11_WORD2 - Error Injection Channel Descriptor 11, Word2 */
/*! @{ */

#define EIM_EICHD11_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD11_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD11_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD11_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD11_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD11_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD12_WORD0 - Error Injection Channel Descriptor 12, Word0 */
/*! @{ */

#define EIM_EICHD12_WORD0_CHKBIT_MASK_MASK       (0xFF000000U)
#define EIM_EICHD12_WORD0_CHKBIT_MASK_SHIFT      (24U)
#define EIM_EICHD12_WORD0_CHKBIT_MASK_WIDTH      (8U)
#define EIM_EICHD12_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD12_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD12_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD12_WORD1 - Error Injection Channel Descriptor 12, Word1 */
/*! @{ */

#define EIM_EICHD12_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (24, 32), largest definition used */
#define EIM_EICHD12_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD12_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD12_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD12_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD12_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (24, 32), largest definition used */
/*! @} */

/*! @name EICHD12_WORD2 - Error Injection Channel Descriptor 12, Word2 */
/*! @{ */

#define EIM_EICHD12_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD12_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD12_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD12_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD12_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD12_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD13_WORD0 - Error Injection Channel Descriptor 13, Word0 */
/*! @{ */

#define EIM_EICHD13_WORD0_CHKBIT_MASK_MASK       (0xFF000000U)
#define EIM_EICHD13_WORD0_CHKBIT_MASK_SHIFT      (24U)
#define EIM_EICHD13_WORD0_CHKBIT_MASK_WIDTH      (8U)
#define EIM_EICHD13_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD13_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD13_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD13_WORD1 - Error Injection Channel Descriptor 13, Word1 */
/*! @{ */

#define EIM_EICHD13_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD13_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD13_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD13_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD13_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD13_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD13_WORD2 - Error Injection Channel Descriptor 13, Word2 */
/*! @{ */

#define EIM_EICHD13_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD13_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD13_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD13_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD13_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD13_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD14_WORD0 - Error Injection Channel Descriptor 14, Word0 */
/*! @{ */

#define EIM_EICHD14_WORD0_CHKBIT_MASK_MASK       (0xFF000000U)
#define EIM_EICHD14_WORD0_CHKBIT_MASK_SHIFT      (24U)
#define EIM_EICHD14_WORD0_CHKBIT_MASK_WIDTH      (8U)
#define EIM_EICHD14_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD14_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD14_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD14_WORD1 - Error Injection Channel Descriptor 14, Word1 */
/*! @{ */

#define EIM_EICHD14_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD14_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD14_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD14_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD14_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD14_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD14_WORD2 - Error Injection Channel Descriptor 14, Word2 */
/*! @{ */

#define EIM_EICHD14_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD14_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD14_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD14_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD14_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD14_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD15_WORD0 - Error Injection Channel Descriptor 15, Word0 */
/*! @{ */

#define EIM_EICHD15_WORD0_CHKBIT_MASK_MASK       (0xFF000000U)
#define EIM_EICHD15_WORD0_CHKBIT_MASK_SHIFT      (24U)
#define EIM_EICHD15_WORD0_CHKBIT_MASK_WIDTH      (8U)
#define EIM_EICHD15_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD15_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD15_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD15_WORD1 - Error Injection Channel Descriptor 15, Word1 */
/*! @{ */

#define EIM_EICHD15_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD15_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD15_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD15_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD15_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD15_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD15_WORD2 - Error Injection Channel Descriptor 15, Word2 */
/*! @{ */

#define EIM_EICHD15_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD15_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD15_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD15_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD15_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD15_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD16_WORD0 - Error Injection Channel Descriptor 16, Word0 */
/*! @{ */

#define EIM_EICHD16_WORD0_CHKBIT_MASK_MASK       (0xFF000000U)
#define EIM_EICHD16_WORD0_CHKBIT_MASK_SHIFT      (24U)
#define EIM_EICHD16_WORD0_CHKBIT_MASK_WIDTH      (8U)
#define EIM_EICHD16_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD16_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD16_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD16_WORD1 - Error Injection Channel Descriptor 16, Word1 */
/*! @{ */

#define EIM_EICHD16_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (20, 32), largest definition used */
#define EIM_EICHD16_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD16_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD16_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD16_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD16_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (20, 32), largest definition used */
/*! @} */

/*! @name EICHD16_WORD2 - Error Injection Channel Descriptor 16, Word2 */
/*! @{ */

#define EIM_EICHD16_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD16_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD16_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD16_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD16_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD16_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD17_WORD0 - Error Injection Channel Descriptor 17, Word0 */
/*! @{ */

#define EIM_EICHD17_WORD0_CHKBIT_MASK_MASK       (0xFF000000U)
#define EIM_EICHD17_WORD0_CHKBIT_MASK_SHIFT      (24U)
#define EIM_EICHD17_WORD0_CHKBIT_MASK_WIDTH      (8U)
#define EIM_EICHD17_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD17_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD17_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD17_WORD1 - Error Injection Channel Descriptor 17, Word1 */
/*! @{ */

#define EIM_EICHD17_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (11, 32), largest definition used */
#define EIM_EICHD17_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD17_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD17_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD17_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD17_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (11, 32), largest definition used */
/*! @} */

/*! @name EICHD17_WORD2 - Error Injection Channel Descriptor 17, Word2 */
/*! @{ */

#define EIM_EICHD17_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD17_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD17_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD17_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD17_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD17_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD18_WORD1 - Error Injection Channel Descriptor 18, Word1 */
/*! @{ */

#define EIM_EICHD18_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFU)  /* Merged from fields with different position or width, of widths (11, 28), largest definition used */
#define EIM_EICHD18_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD18_WORD1_B0_3DATA_MASK_WIDTH    (28U)
#define EIM_EICHD18_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD18_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD18_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (11, 28), largest definition used */
/*! @} */

/*! @name EICHD18_WORD2 - Error Injection Channel Descriptor 18, Word2 */
/*! @{ */

#define EIM_EICHD18_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD18_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD18_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD18_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD18_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD18_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD19_WORD0 - Error Injection Channel Descriptor 19, Word0 */
/*! @{ */

#define EIM_EICHD19_WORD0_CHKBIT_MASK_MASK       (0xFF000000U)
#define EIM_EICHD19_WORD0_CHKBIT_MASK_SHIFT      (24U)
#define EIM_EICHD19_WORD0_CHKBIT_MASK_WIDTH      (8U)
#define EIM_EICHD19_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD19_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD19_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD19_WORD1 - Error Injection Channel Descriptor 19, Word1 */
/*! @{ */

#define EIM_EICHD19_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (28, 32), largest definition used */
#define EIM_EICHD19_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD19_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD19_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD19_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD19_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (28, 32), largest definition used */
/*! @} */

/*! @name EICHD19_WORD2 - Error Injection Channel Descriptor 19, Word2 */
/*! @{ */

#define EIM_EICHD19_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD19_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD19_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD19_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD19_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD19_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD20_WORD0 - Error Injection Channel Descriptor 20, Word0 */
/*! @{ */

#define EIM_EICHD20_WORD0_CHKBIT_MASK_MASK       (0xFF000000U)
#define EIM_EICHD20_WORD0_CHKBIT_MASK_SHIFT      (24U)
#define EIM_EICHD20_WORD0_CHKBIT_MASK_WIDTH      (8U)
#define EIM_EICHD20_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD20_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD20_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD20_WORD1 - Error Injection Channel Descriptor 20, Word1 */
/*! @{ */

#define EIM_EICHD20_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (28, 32), largest definition used */
#define EIM_EICHD20_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD20_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD20_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD20_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD20_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (28, 32), largest definition used */
/*! @} */

/*! @name EICHD20_WORD2 - Error Injection Channel Descriptor 20, Word2 */
/*! @{ */

#define EIM_EICHD20_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD20_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD20_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD20_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD20_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD20_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD21_WORD0 - Error Injection Channel Descriptor 21, Word0 */
/*! @{ */

#define EIM_EICHD21_WORD0_CHKBIT_MASK_MASK       (0xFF000000U)
#define EIM_EICHD21_WORD0_CHKBIT_MASK_SHIFT      (24U)
#define EIM_EICHD21_WORD0_CHKBIT_MASK_WIDTH      (8U)
#define EIM_EICHD21_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD21_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD21_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD21_WORD1 - Error Injection Channel Descriptor 21, Word1 */
/*! @{ */

#define EIM_EICHD21_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (28, 32), largest definition used */
#define EIM_EICHD21_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD21_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD21_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD21_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD21_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (28, 32), largest definition used */
/*! @} */

/*! @name EICHD21_WORD2 - Error Injection Channel Descriptor 21, Word2 */
/*! @{ */

#define EIM_EICHD21_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD21_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD21_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD21_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD21_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD21_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD22_WORD0 - Error Injection Channel Descriptor 22, Word0 */
/*! @{ */

#define EIM_EICHD22_WORD0_CHKBIT_MASK_MASK       (0xFF000000U)
#define EIM_EICHD22_WORD0_CHKBIT_MASK_SHIFT      (24U)
#define EIM_EICHD22_WORD0_CHKBIT_MASK_WIDTH      (8U)
#define EIM_EICHD22_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD22_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD22_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD22_WORD1 - Error Injection Channel Descriptor 22, Word1 */
/*! @{ */

#define EIM_EICHD22_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (20, 32), largest definition used */
#define EIM_EICHD22_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD22_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD22_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD22_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD22_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (20, 32), largest definition used */
/*! @} */

/*! @name EICHD22_WORD2 - Error Injection Channel Descriptor 22, Word2 */
/*! @{ */

#define EIM_EICHD22_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD22_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD22_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD22_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD22_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD22_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD23_WORD1 - Error Injection Channel Descriptor 23, Word1 */
/*! @{ */

#define EIM_EICHD23_WORD1_B0_3DATA_MASK_MASK     (0x7FFU)  /* Merged from fields with different position or width, of widths (1, 11), largest definition used */
#define EIM_EICHD23_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD23_WORD1_B0_3DATA_MASK_WIDTH    (11U)
#define EIM_EICHD23_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD23_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD23_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (1, 11), largest definition used */
/*! @} */

/*! @name EICHD24_WORD1 - Error Injection Channel Descriptor 24, Word1 */
/*! @{ */

#define EIM_EICHD24_WORD1_B0_3DATA_MASK_MASK     (0x3FFFFFFFU)  /* Merged from fields with different position or width, of widths (1, 30), largest definition used */
#define EIM_EICHD24_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD24_WORD1_B0_3DATA_MASK_WIDTH    (30U)
#define EIM_EICHD24_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD24_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD24_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (1, 30), largest definition used */
/*! @} */

/*! @name EICHD25_WORD1 - Error Injection Channel Descriptor 25, Word1 */
/*! @{ */

#define EIM_EICHD25_WORD1_B0_3DATA_MASK_MASK     (0x3U)
#define EIM_EICHD25_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD25_WORD1_B0_3DATA_MASK_WIDTH    (2U)
#define EIM_EICHD25_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD25_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD25_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD26_WORD0 - Error Injection Channel Descriptor 26, Word0 */
/*! @{ */

#define EIM_EICHD26_WORD0_CHKBIT_MASK_MASK       (0xFF000000U)
#define EIM_EICHD26_WORD0_CHKBIT_MASK_SHIFT      (24U)
#define EIM_EICHD26_WORD0_CHKBIT_MASK_WIDTH      (8U)
#define EIM_EICHD26_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD26_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD26_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD26_WORD1 - Error Injection Channel Descriptor 26, Word1 */
/*! @{ */

#define EIM_EICHD26_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (26, 32), largest definition used */
#define EIM_EICHD26_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD26_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD26_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD26_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD26_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (26, 32), largest definition used */
/*! @} */

/*! @name EICHD26_WORD2 - Error Injection Channel Descriptor 26, Word2 */
/*! @{ */

#define EIM_EICHD26_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD26_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD26_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD26_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD26_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD26_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD27_WORD0 - Error Injection Channel Descriptor 27, Word0 */
/*! @{ */

#define EIM_EICHD27_WORD0_CHKBIT_MASK_MASK       (0xFF000000U)
#define EIM_EICHD27_WORD0_CHKBIT_MASK_SHIFT      (24U)
#define EIM_EICHD27_WORD0_CHKBIT_MASK_WIDTH      (8U)
#define EIM_EICHD27_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD27_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD27_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD27_WORD1 - Error Injection Channel Descriptor 27, Word1 */
/*! @{ */

#define EIM_EICHD27_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (10, 32), largest definition used */
#define EIM_EICHD27_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD27_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD27_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD27_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD27_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (10, 32), largest definition used */
/*! @} */

/*! @name EICHD27_WORD2 - Error Injection Channel Descriptor 27, Word2 */
/*! @{ */

#define EIM_EICHD27_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD27_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD27_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD27_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD27_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD27_WORD2_B4_7DATA_MASK_MASK)
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

#define EIM_EICHD28_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD28_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD28_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD28_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD28_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD28_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD28_WORD2 - Error Injection Channel Descriptor 28, Word2 */
/*! @{ */

#define EIM_EICHD28_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD28_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD28_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD28_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD28_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD28_WORD2_B4_7DATA_MASK_MASK)
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

#define EIM_EICHD29_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (12, 32), largest definition used */
#define EIM_EICHD29_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD29_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD29_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD29_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD29_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (12, 32), largest definition used */
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

#define EIM_EICHD30_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (22, 32), largest definition used */
#define EIM_EICHD30_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD30_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD30_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD30_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD30_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (22, 32), largest definition used */
/*! @} */

/*! @name EICHD30_WORD2 - Error Injection Channel Descriptor 30, Word2 */
/*! @{ */

#define EIM_EICHD30_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD30_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD30_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD30_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD30_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD30_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD31_WORD1 - Error Injection Channel Descriptor 31, Word1 */
/*! @{ */

#define EIM_EICHD31_WORD1_B0_3DATA_MASK_MASK     (0x3FFFFFU)  /* Merged from fields with different position or width, of widths (13, 22), largest definition used */
#define EIM_EICHD31_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD31_WORD1_B0_3DATA_MASK_WIDTH    (22U)
#define EIM_EICHD31_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD31_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD31_WORD1_B0_3DATA_MASK_MASK)  /* Merged from fields with different position or width, of widths (13, 22), largest definition used */
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

#endif  /* #if !defined(S32Z2_EIM_H_) */
