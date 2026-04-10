/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K39_EIM_2.h
 * @version 1.7
 * @date 2022-11-18
 * @brief Peripheral Access Layer for S32K39_EIM_2
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
#if !defined(S32K39_EIM_2_H_)  /* Check if memory map has not been already included */
#define S32K39_EIM_2_H_

#include "S32K39_COMMON.h"

/* ----------------------------------------------------------------------------
   -- EIM_2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EIM_2_Peripheral_Access_Layer EIM_2 Peripheral Access Layer
 * @{
 */

/** EIM_2 - Register Layout Typedef */
typedef struct {
  __IO uint32_t EIMCR;                             /**< Error Injection Module Configuration Register, offset: 0x0 */
  __IO uint32_t EICHEN;                            /**< Error Injection Channel Enable register, offset: 0x4 */
  uint8_t RESERVED_0[248];
  __IO uint32_t EICHD0_WORD0;                      /**< Error Injection Channel Descriptor 0, Word0, offset: 0x100 */
  __IO uint32_t EICHD0_WORD1;                      /**< Error Injection Channel Descriptor 0, Word1, offset: 0x104 */
  __IO uint32_t EICHD0_WORD2;                      /**< Error Injection Channel Descriptor 0, Word2, offset: 0x108 */
  uint8_t RESERVED_1[52];
  __IO uint32_t EICHD1_WORD0;                      /**< Error Injection Channel Descriptor 1, Word0, offset: 0x140 */
  __IO uint32_t EICHD1_WORD1;                      /**< Error Injection Channel Descriptor 1, Word1, offset: 0x144 */
  __IO uint32_t EICHD1_WORD2;                      /**< Error Injection Channel Descriptor 1, Word2, offset: 0x148 */
  uint8_t RESERVED_2[116];
  __IO uint32_t EICHD3_WORD0;                      /**< Error Injection Channel Descriptor 3, Word0, offset: 0x1C0 */
  __IO uint32_t EICHD3_WORD1;                      /**< Error Injection Channel Descriptor 3, Word1, offset: 0x1C4 */
  __IO uint32_t EICHD3_WORD2;                      /**< Error Injection Channel Descriptor 3, Word2, offset: 0x1C8 */
  uint8_t RESERVED_3[52];
  __IO uint32_t EICHD4_WORD0;                      /**< Error Injection Channel Descriptor 4, Word0, offset: 0x200 */
  __IO uint32_t EICHD4_WORD1;                      /**< Error Injection Channel Descriptor 4, Word1, offset: 0x204 */
  __IO uint32_t EICHD4_WORD2;                      /**< Error Injection Channel Descriptor 4, Word2, offset: 0x208 */
  uint8_t RESERVED_4[56];
  __IO uint32_t EICHD5_WORD1;                      /**< Error Injection Channel Descriptor 5, Word1, offset: 0x244 */
  __IO uint32_t EICHD5_WORD2;                      /**< Error Injection Channel Descriptor 5, Word2, offset: 0x248 */
  __IO uint32_t EICHD5_WORD3;                      /**< Error Injection Channel Descriptor 5, Word3, offset: 0x24C */
  __IO uint32_t EICHD5_WORD4;                      /**< Error Injection Channel Descriptor 5, Word4, offset: 0x250 */
  __IO uint32_t EICHD5_WORD5;                      /**< Error Injection Channel Descriptor 5, Word5, offset: 0x254 */
  __IO uint32_t EICHD5_WORD6;                      /**< Error Injection Channel Descriptor 5, Word6, offset: 0x258 */
  uint8_t RESERVED_5[40];
  __IO uint32_t EICHD6_WORD1;                      /**< Error Injection Channel Descriptor 6, Word1, offset: 0x284 */
  __IO uint32_t EICHD6_WORD2;                      /**< Error Injection Channel Descriptor 6, Word2, offset: 0x288 */
  __IO uint32_t EICHD6_WORD3;                      /**< Error Injection Channel Descriptor 6, Word3, offset: 0x28C */
  __IO uint32_t EICHD6_WORD4;                      /**< Error Injection Channel Descriptor 6, Word4, offset: 0x290 */
  __IO uint32_t EICHD6_WORD5;                      /**< Error Injection Channel Descriptor 6, Word5, offset: 0x294 */
  __IO uint32_t EICHD6_WORD6;                      /**< Error Injection Channel Descriptor 6, Word6, offset: 0x298 */
  uint8_t RESERVED_6[40];
  __IO uint32_t EICHD7_WORD1;                      /**< Error Injection Channel Descriptor 7, Word1, offset: 0x2C4 */
  __IO uint32_t EICHD7_WORD2;                      /**< Error Injection Channel Descriptor 7, Word2, offset: 0x2C8 */
  uint8_t RESERVED_7[56];
  __IO uint32_t EICHD8_WORD1;                      /**< Error Injection Channel Descriptor 8, Word1, offset: 0x304 */
  __IO uint32_t EICHD8_WORD2;                      /**< Error Injection Channel Descriptor 8, Word2, offset: 0x308 */
  uint8_t RESERVED_8[56];
  __IO uint32_t EICHD9_WORD1;                      /**< Error Injection Channel Descriptor 9, Word1, offset: 0x344 */
  __IO uint32_t EICHD9_WORD2;                      /**< Error Injection Channel Descriptor 9, Word2, offset: 0x348 */
  uint8_t RESERVED_9[56];
  __IO uint32_t EICHD10_WORD1;                     /**< Error Injection Channel Descriptor 10, Word1, offset: 0x384 */
  __IO uint32_t EICHD10_WORD2;                     /**< Error Injection Channel Descriptor 10, Word2, offset: 0x388 */
  uint8_t RESERVED_10[56];
  __IO uint32_t EICHD11_WORD1;                     /**< Error Injection Channel Descriptor 11, Word1, offset: 0x3C4 */
  __IO uint32_t EICHD11_WORD2;                     /**< Error Injection Channel Descriptor 11, Word2, offset: 0x3C8 */
  uint8_t RESERVED_11[56];
  __IO uint32_t EICHD12_WORD1;                     /**< Error Injection Channel Descriptor 12, Word1, offset: 0x404 */
  __IO uint32_t EICHD12_WORD2;                     /**< Error Injection Channel Descriptor 12, Word2, offset: 0x408 */
  uint8_t RESERVED_12[56];
  __IO uint32_t EICHD13_WORD1;                     /**< Error Injection Channel Descriptor 13, Word1, offset: 0x444 */
  __IO uint32_t EICHD13_WORD2;                     /**< Error Injection Channel Descriptor 13, Word2, offset: 0x448 */
  uint8_t RESERVED_13[56];
  __IO uint32_t EICHD14_WORD1;                     /**< Error Injection Channel Descriptor 14, Word1, offset: 0x484 */
  __IO uint32_t EICHD14_WORD2;                     /**< Error Injection Channel Descriptor 14, Word2, offset: 0x488 */
  uint8_t RESERVED_14[56];
  __IO uint32_t EICHD15_WORD1;                     /**< Error Injection Channel Descriptor 15, Word1, offset: 0x4C4 */
  __IO uint32_t EICHD15_WORD2;                     /**< Error Injection Channel Descriptor 15, Word2, offset: 0x4C8 */
  uint8_t RESERVED_15[56];
  __IO uint32_t EICHD16_WORD1;                     /**< Error Injection Channel Descriptor 16, Word1, offset: 0x504 */
  __IO uint32_t EICHD16_WORD2;                     /**< Error Injection Channel Descriptor 16, Word2, offset: 0x508 */
  uint8_t RESERVED_16[56];
  __IO uint32_t EICHD17_WORD1;                     /**< Error Injection Channel Descriptor 17, Word1, offset: 0x544 */
  __IO uint32_t EICHD17_WORD2;                     /**< Error Injection Channel Descriptor 17, Word2, offset: 0x548 */
  uint8_t RESERVED_17[56];
  __IO uint32_t EICHD18_WORD1;                     /**< Error Injection Channel Descriptor 18, Word1, offset: 0x584 */
  __IO uint32_t EICHD18_WORD2;                     /**< Error Injection Channel Descriptor 18, Word2, offset: 0x588 */
  uint8_t RESERVED_18[184];
  __IO uint32_t EICHD21_WORD1;                     /**< Error Injection Channel Descriptor 21, Word1, offset: 0x644 */
  uint8_t RESERVED_19[60];
  __IO uint32_t EICHD22_WORD1;                     /**< Error Injection Channel Descriptor 22, Word1, offset: 0x684 */
  __IO uint32_t EICHD22_WORD2;                     /**< Error Injection Channel Descriptor 22, Word2, offset: 0x688 */
  __IO uint32_t EICHD22_WORD3;                     /**< Error Injection Channel Descriptor 22, Word3, offset: 0x68C */
  __IO uint32_t EICHD22_WORD4;                     /**< Error Injection Channel Descriptor 22, Word4, offset: 0x690 */
  __IO uint32_t EICHD22_WORD5;                     /**< Error Injection Channel Descriptor 22, Word5, offset: 0x694 */
  __IO uint32_t EICHD22_WORD6;                     /**< Error Injection Channel Descriptor 22, Word6, offset: 0x698 */
  uint8_t RESERVED_20[36];
  __IO uint32_t EICHD23_WORD0;                     /**< Error Injection Channel Descriptor 23, Word0, offset: 0x6C0 */
  __IO uint32_t EICHD23_WORD1;                     /**< Error Injection Channel Descriptor 23, Word1, offset: 0x6C4 */
  uint8_t RESERVED_21[56];
  __IO uint32_t EICHD24_WORD0;                     /**< Error Injection Channel Descriptor 24, Word0, offset: 0x700 */
  __IO uint32_t EICHD24_WORD1;                     /**< Error Injection Channel Descriptor 24, Word1, offset: 0x704 */
  uint8_t RESERVED_22[56];
  __IO uint32_t EICHD25_WORD0;                     /**< Error Injection Channel Descriptor 25, Word0, offset: 0x740 */
  __IO uint32_t EICHD25_WORD1;                     /**< Error Injection Channel Descriptor 25, Word1, offset: 0x744 */
  uint8_t RESERVED_23[60];
  __IO uint32_t EICHD26_WORD1;                     /**< Error Injection Channel Descriptor 26, Word1, offset: 0x784 */
  uint8_t RESERVED_24[60];
  __IO uint32_t EICHD27_WORD1;                     /**< Error Injection Channel Descriptor 27, Word1, offset: 0x7C4 */
  uint8_t RESERVED_25[60];
  __IO uint32_t EICHD28_WORD1;                     /**< Error Injection Channel Descriptor 28, Word1, offset: 0x804 */
  uint8_t RESERVED_26[60];
  __IO uint32_t EICHD29_WORD1;                     /**< Error Injection Channel Descriptor 29, Word1, offset: 0x844 */
  uint8_t RESERVED_27[60];
  __IO uint32_t EICHD30_WORD1;                     /**< Error Injection Channel Descriptor 30, Word1, offset: 0x884 */
  uint8_t RESERVED_28[60];
  __IO uint32_t EICHD31_WORD1;                     /**< Error Injection Channel Descriptor 31, Word1, offset: 0x8C4 */
} EIM_2_Type, *EIM_2_MemMapPtr;

/** Number of instances of the EIM_2 module. */
#define EIM_2_INSTANCE_COUNT                     (1u)

/* EIM_2 - Peripheral instance base addresses */
/** Peripheral EIM_2 base address */
#define IP_EIM_2_BASE                            (0x40514000u)
/** Peripheral EIM_2 base pointer */
#define IP_EIM_2                                 ((EIM_2_Type *)IP_EIM_2_BASE)
/** Array initializer of EIM_2 peripheral base addresses */
#define IP_EIM_2_BASE_ADDRS                      { IP_EIM_2_BASE }
/** Array initializer of EIM_2 peripheral base pointers */
#define IP_EIM_2_BASE_PTRS                       { IP_EIM_2 }

/* ----------------------------------------------------------------------------
   -- EIM_2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EIM_2_Register_Masks EIM_2 Register Masks
 * @{
 */

/*! @name EIMCR - Error Injection Module Configuration Register */
/*! @{ */

#define EIM_2_EIMCR_GEIEN_MASK                   (0x1U)
#define EIM_2_EIMCR_GEIEN_SHIFT                  (0U)
#define EIM_2_EIMCR_GEIEN_WIDTH                  (1U)
#define EIM_2_EIMCR_GEIEN(x)                     (((uint32_t)(((uint32_t)(x)) << EIM_2_EIMCR_GEIEN_SHIFT)) & EIM_2_EIMCR_GEIEN_MASK)
/*! @} */

/*! @name EICHEN - Error Injection Channel Enable register */
/*! @{ */

#define EIM_2_EICHEN_EICH31EN_MASK               (0x1U)
#define EIM_2_EICHEN_EICH31EN_SHIFT              (0U)
#define EIM_2_EICHEN_EICH31EN_WIDTH              (1U)
#define EIM_2_EICHEN_EICH31EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH31EN_SHIFT)) & EIM_2_EICHEN_EICH31EN_MASK)

#define EIM_2_EICHEN_EICH30EN_MASK               (0x2U)
#define EIM_2_EICHEN_EICH30EN_SHIFT              (1U)
#define EIM_2_EICHEN_EICH30EN_WIDTH              (1U)
#define EIM_2_EICHEN_EICH30EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH30EN_SHIFT)) & EIM_2_EICHEN_EICH30EN_MASK)

#define EIM_2_EICHEN_EICH29EN_MASK               (0x4U)
#define EIM_2_EICHEN_EICH29EN_SHIFT              (2U)
#define EIM_2_EICHEN_EICH29EN_WIDTH              (1U)
#define EIM_2_EICHEN_EICH29EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH29EN_SHIFT)) & EIM_2_EICHEN_EICH29EN_MASK)

#define EIM_2_EICHEN_EICH28EN_MASK               (0x8U)
#define EIM_2_EICHEN_EICH28EN_SHIFT              (3U)
#define EIM_2_EICHEN_EICH28EN_WIDTH              (1U)
#define EIM_2_EICHEN_EICH28EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH28EN_SHIFT)) & EIM_2_EICHEN_EICH28EN_MASK)

#define EIM_2_EICHEN_EICH27EN_MASK               (0x10U)
#define EIM_2_EICHEN_EICH27EN_SHIFT              (4U)
#define EIM_2_EICHEN_EICH27EN_WIDTH              (1U)
#define EIM_2_EICHEN_EICH27EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH27EN_SHIFT)) & EIM_2_EICHEN_EICH27EN_MASK)

#define EIM_2_EICHEN_EICH26EN_MASK               (0x20U)
#define EIM_2_EICHEN_EICH26EN_SHIFT              (5U)
#define EIM_2_EICHEN_EICH26EN_WIDTH              (1U)
#define EIM_2_EICHEN_EICH26EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH26EN_SHIFT)) & EIM_2_EICHEN_EICH26EN_MASK)

#define EIM_2_EICHEN_EICH25EN_MASK               (0x40U)
#define EIM_2_EICHEN_EICH25EN_SHIFT              (6U)
#define EIM_2_EICHEN_EICH25EN_WIDTH              (1U)
#define EIM_2_EICHEN_EICH25EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH25EN_SHIFT)) & EIM_2_EICHEN_EICH25EN_MASK)

#define EIM_2_EICHEN_EICH24EN_MASK               (0x80U)
#define EIM_2_EICHEN_EICH24EN_SHIFT              (7U)
#define EIM_2_EICHEN_EICH24EN_WIDTH              (1U)
#define EIM_2_EICHEN_EICH24EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH24EN_SHIFT)) & EIM_2_EICHEN_EICH24EN_MASK)

#define EIM_2_EICHEN_EICH23EN_MASK               (0x100U)
#define EIM_2_EICHEN_EICH23EN_SHIFT              (8U)
#define EIM_2_EICHEN_EICH23EN_WIDTH              (1U)
#define EIM_2_EICHEN_EICH23EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH23EN_SHIFT)) & EIM_2_EICHEN_EICH23EN_MASK)

#define EIM_2_EICHEN_EICH22EN_MASK               (0x200U)
#define EIM_2_EICHEN_EICH22EN_SHIFT              (9U)
#define EIM_2_EICHEN_EICH22EN_WIDTH              (1U)
#define EIM_2_EICHEN_EICH22EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH22EN_SHIFT)) & EIM_2_EICHEN_EICH22EN_MASK)

#define EIM_2_EICHEN_EICH21EN_MASK               (0x400U)
#define EIM_2_EICHEN_EICH21EN_SHIFT              (10U)
#define EIM_2_EICHEN_EICH21EN_WIDTH              (1U)
#define EIM_2_EICHEN_EICH21EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH21EN_SHIFT)) & EIM_2_EICHEN_EICH21EN_MASK)

#define EIM_2_EICHEN_EICH18EN_MASK               (0x2000U)
#define EIM_2_EICHEN_EICH18EN_SHIFT              (13U)
#define EIM_2_EICHEN_EICH18EN_WIDTH              (1U)
#define EIM_2_EICHEN_EICH18EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH18EN_SHIFT)) & EIM_2_EICHEN_EICH18EN_MASK)

#define EIM_2_EICHEN_EICH17EN_MASK               (0x4000U)
#define EIM_2_EICHEN_EICH17EN_SHIFT              (14U)
#define EIM_2_EICHEN_EICH17EN_WIDTH              (1U)
#define EIM_2_EICHEN_EICH17EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH17EN_SHIFT)) & EIM_2_EICHEN_EICH17EN_MASK)

#define EIM_2_EICHEN_EICH16EN_MASK               (0x8000U)
#define EIM_2_EICHEN_EICH16EN_SHIFT              (15U)
#define EIM_2_EICHEN_EICH16EN_WIDTH              (1U)
#define EIM_2_EICHEN_EICH16EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH16EN_SHIFT)) & EIM_2_EICHEN_EICH16EN_MASK)

#define EIM_2_EICHEN_EICH15EN_MASK               (0x10000U)
#define EIM_2_EICHEN_EICH15EN_SHIFT              (16U)
#define EIM_2_EICHEN_EICH15EN_WIDTH              (1U)
#define EIM_2_EICHEN_EICH15EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH15EN_SHIFT)) & EIM_2_EICHEN_EICH15EN_MASK)

#define EIM_2_EICHEN_EICH14EN_MASK               (0x20000U)
#define EIM_2_EICHEN_EICH14EN_SHIFT              (17U)
#define EIM_2_EICHEN_EICH14EN_WIDTH              (1U)
#define EIM_2_EICHEN_EICH14EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH14EN_SHIFT)) & EIM_2_EICHEN_EICH14EN_MASK)

#define EIM_2_EICHEN_EICH13EN_MASK               (0x40000U)
#define EIM_2_EICHEN_EICH13EN_SHIFT              (18U)
#define EIM_2_EICHEN_EICH13EN_WIDTH              (1U)
#define EIM_2_EICHEN_EICH13EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH13EN_SHIFT)) & EIM_2_EICHEN_EICH13EN_MASK)

#define EIM_2_EICHEN_EICH12EN_MASK               (0x80000U)
#define EIM_2_EICHEN_EICH12EN_SHIFT              (19U)
#define EIM_2_EICHEN_EICH12EN_WIDTH              (1U)
#define EIM_2_EICHEN_EICH12EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH12EN_SHIFT)) & EIM_2_EICHEN_EICH12EN_MASK)

#define EIM_2_EICHEN_EICH11EN_MASK               (0x100000U)
#define EIM_2_EICHEN_EICH11EN_SHIFT              (20U)
#define EIM_2_EICHEN_EICH11EN_WIDTH              (1U)
#define EIM_2_EICHEN_EICH11EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH11EN_SHIFT)) & EIM_2_EICHEN_EICH11EN_MASK)

#define EIM_2_EICHEN_EICH10EN_MASK               (0x200000U)
#define EIM_2_EICHEN_EICH10EN_SHIFT              (21U)
#define EIM_2_EICHEN_EICH10EN_WIDTH              (1U)
#define EIM_2_EICHEN_EICH10EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH10EN_SHIFT)) & EIM_2_EICHEN_EICH10EN_MASK)

#define EIM_2_EICHEN_EICH9EN_MASK                (0x400000U)
#define EIM_2_EICHEN_EICH9EN_SHIFT               (22U)
#define EIM_2_EICHEN_EICH9EN_WIDTH               (1U)
#define EIM_2_EICHEN_EICH9EN(x)                  (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH9EN_SHIFT)) & EIM_2_EICHEN_EICH9EN_MASK)

#define EIM_2_EICHEN_EICH8EN_MASK                (0x800000U)
#define EIM_2_EICHEN_EICH8EN_SHIFT               (23U)
#define EIM_2_EICHEN_EICH8EN_WIDTH               (1U)
#define EIM_2_EICHEN_EICH8EN(x)                  (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH8EN_SHIFT)) & EIM_2_EICHEN_EICH8EN_MASK)

#define EIM_2_EICHEN_EICH7EN_MASK                (0x1000000U)
#define EIM_2_EICHEN_EICH7EN_SHIFT               (24U)
#define EIM_2_EICHEN_EICH7EN_WIDTH               (1U)
#define EIM_2_EICHEN_EICH7EN(x)                  (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH7EN_SHIFT)) & EIM_2_EICHEN_EICH7EN_MASK)

#define EIM_2_EICHEN_EICH6EN_MASK                (0x2000000U)
#define EIM_2_EICHEN_EICH6EN_SHIFT               (25U)
#define EIM_2_EICHEN_EICH6EN_WIDTH               (1U)
#define EIM_2_EICHEN_EICH6EN(x)                  (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH6EN_SHIFT)) & EIM_2_EICHEN_EICH6EN_MASK)

#define EIM_2_EICHEN_EICH5EN_MASK                (0x4000000U)
#define EIM_2_EICHEN_EICH5EN_SHIFT               (26U)
#define EIM_2_EICHEN_EICH5EN_WIDTH               (1U)
#define EIM_2_EICHEN_EICH5EN(x)                  (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH5EN_SHIFT)) & EIM_2_EICHEN_EICH5EN_MASK)

#define EIM_2_EICHEN_EICH4EN_MASK                (0x8000000U)
#define EIM_2_EICHEN_EICH4EN_SHIFT               (27U)
#define EIM_2_EICHEN_EICH4EN_WIDTH               (1U)
#define EIM_2_EICHEN_EICH4EN(x)                  (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH4EN_SHIFT)) & EIM_2_EICHEN_EICH4EN_MASK)

#define EIM_2_EICHEN_EICH3EN_MASK                (0x10000000U)
#define EIM_2_EICHEN_EICH3EN_SHIFT               (28U)
#define EIM_2_EICHEN_EICH3EN_WIDTH               (1U)
#define EIM_2_EICHEN_EICH3EN(x)                  (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH3EN_SHIFT)) & EIM_2_EICHEN_EICH3EN_MASK)

#define EIM_2_EICHEN_EICH1EN_MASK                (0x40000000U)
#define EIM_2_EICHEN_EICH1EN_SHIFT               (30U)
#define EIM_2_EICHEN_EICH1EN_WIDTH               (1U)
#define EIM_2_EICHEN_EICH1EN(x)                  (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH1EN_SHIFT)) & EIM_2_EICHEN_EICH1EN_MASK)

#define EIM_2_EICHEN_EICH0EN_MASK                (0x80000000U)
#define EIM_2_EICHEN_EICH0EN_SHIFT               (31U)
#define EIM_2_EICHEN_EICH0EN_WIDTH               (1U)
#define EIM_2_EICHEN_EICH0EN(x)                  (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHEN_EICH0EN_SHIFT)) & EIM_2_EICHEN_EICH0EN_MASK)
/*! @} */

/*! @name EICHD0_WORD0 - Error Injection Channel Descriptor 0, Word0 */
/*! @{ */

#define EIM_2_EICHD0_WORD0_CHKBIT_MASK_MASK      (0xFF000000U)
#define EIM_2_EICHD0_WORD0_CHKBIT_MASK_SHIFT     (24U)
#define EIM_2_EICHD0_WORD0_CHKBIT_MASK_WIDTH     (8U)
#define EIM_2_EICHD0_WORD0_CHKBIT_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD0_WORD0_CHKBIT_MASK_SHIFT)) & EIM_2_EICHD0_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD0_WORD1 - Error Injection Channel Descriptor 0, Word1 */
/*! @{ */

#define EIM_2_EICHD0_WORD1_B0_3DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_2_EICHD0_WORD1_B0_3DATA_MASK_SHIFT   (0U)
#define EIM_2_EICHD0_WORD1_B0_3DATA_MASK_WIDTH   (32U)
#define EIM_2_EICHD0_WORD1_B0_3DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD0_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD0_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD0_WORD2 - Error Injection Channel Descriptor 0, Word2 */
/*! @{ */

#define EIM_2_EICHD0_WORD2_B4_7DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_2_EICHD0_WORD2_B4_7DATA_MASK_SHIFT   (0U)
#define EIM_2_EICHD0_WORD2_B4_7DATA_MASK_WIDTH   (32U)
#define EIM_2_EICHD0_WORD2_B4_7DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD0_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_2_EICHD0_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD0 - Error Injection Channel Descriptor 1, Word0 */
/*! @{ */

#define EIM_2_EICHD1_WORD0_CHKBIT_MASK_MASK      (0xFF000000U)
#define EIM_2_EICHD1_WORD0_CHKBIT_MASK_SHIFT     (24U)
#define EIM_2_EICHD1_WORD0_CHKBIT_MASK_WIDTH     (8U)
#define EIM_2_EICHD1_WORD0_CHKBIT_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD1_WORD0_CHKBIT_MASK_SHIFT)) & EIM_2_EICHD1_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD1 - Error Injection Channel Descriptor 1, Word1 */
/*! @{ */

#define EIM_2_EICHD1_WORD1_B0_3DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_2_EICHD1_WORD1_B0_3DATA_MASK_SHIFT   (0U)
#define EIM_2_EICHD1_WORD1_B0_3DATA_MASK_WIDTH   (32U)
#define EIM_2_EICHD1_WORD1_B0_3DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD1_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD1_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD2 - Error Injection Channel Descriptor 1, Word2 */
/*! @{ */

#define EIM_2_EICHD1_WORD2_B4_7DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_2_EICHD1_WORD2_B4_7DATA_MASK_SHIFT   (0U)
#define EIM_2_EICHD1_WORD2_B4_7DATA_MASK_WIDTH   (32U)
#define EIM_2_EICHD1_WORD2_B4_7DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD1_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_2_EICHD1_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD0 - Error Injection Channel Descriptor 3, Word0 */
/*! @{ */

#define EIM_2_EICHD3_WORD0_CHKBIT_MASK_MASK      (0xFF000000U)
#define EIM_2_EICHD3_WORD0_CHKBIT_MASK_SHIFT     (24U)
#define EIM_2_EICHD3_WORD0_CHKBIT_MASK_WIDTH     (8U)
#define EIM_2_EICHD3_WORD0_CHKBIT_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD3_WORD0_CHKBIT_MASK_SHIFT)) & EIM_2_EICHD3_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD1 - Error Injection Channel Descriptor 3, Word1 */
/*! @{ */

#define EIM_2_EICHD3_WORD1_B0_3DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_2_EICHD3_WORD1_B0_3DATA_MASK_SHIFT   (0U)
#define EIM_2_EICHD3_WORD1_B0_3DATA_MASK_WIDTH   (32U)
#define EIM_2_EICHD3_WORD1_B0_3DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD3_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD3_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD2 - Error Injection Channel Descriptor 3, Word2 */
/*! @{ */

#define EIM_2_EICHD3_WORD2_B4_7DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_2_EICHD3_WORD2_B4_7DATA_MASK_SHIFT   (0U)
#define EIM_2_EICHD3_WORD2_B4_7DATA_MASK_WIDTH   (32U)
#define EIM_2_EICHD3_WORD2_B4_7DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD3_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_2_EICHD3_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD0 - Error Injection Channel Descriptor 4, Word0 */
/*! @{ */

#define EIM_2_EICHD4_WORD0_CHKBIT_MASK_MASK      (0xFF000000U)
#define EIM_2_EICHD4_WORD0_CHKBIT_MASK_SHIFT     (24U)
#define EIM_2_EICHD4_WORD0_CHKBIT_MASK_WIDTH     (8U)
#define EIM_2_EICHD4_WORD0_CHKBIT_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD4_WORD0_CHKBIT_MASK_SHIFT)) & EIM_2_EICHD4_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD1 - Error Injection Channel Descriptor 4, Word1 */
/*! @{ */

#define EIM_2_EICHD4_WORD1_B0_3DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_2_EICHD4_WORD1_B0_3DATA_MASK_SHIFT   (0U)
#define EIM_2_EICHD4_WORD1_B0_3DATA_MASK_WIDTH   (32U)
#define EIM_2_EICHD4_WORD1_B0_3DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD4_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD4_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD2 - Error Injection Channel Descriptor 4, Word2 */
/*! @{ */

#define EIM_2_EICHD4_WORD2_B4_7DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_2_EICHD4_WORD2_B4_7DATA_MASK_SHIFT   (0U)
#define EIM_2_EICHD4_WORD2_B4_7DATA_MASK_WIDTH   (32U)
#define EIM_2_EICHD4_WORD2_B4_7DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD4_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_2_EICHD4_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD5_WORD1 - Error Injection Channel Descriptor 5, Word1 */
/*! @{ */

#define EIM_2_EICHD5_WORD1_B0_3DATA_MASK_MASK    (0xFFFFFFFU)
#define EIM_2_EICHD5_WORD1_B0_3DATA_MASK_SHIFT   (0U)
#define EIM_2_EICHD5_WORD1_B0_3DATA_MASK_WIDTH   (28U)
#define EIM_2_EICHD5_WORD1_B0_3DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD5_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD5_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD5_WORD2 - Error Injection Channel Descriptor 5, Word2 */
/*! @{ */

#define EIM_2_EICHD5_WORD2_B4_7DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_2_EICHD5_WORD2_B4_7DATA_MASK_SHIFT   (0U)
#define EIM_2_EICHD5_WORD2_B4_7DATA_MASK_WIDTH   (32U)
#define EIM_2_EICHD5_WORD2_B4_7DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD5_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_2_EICHD5_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD5_WORD3 - Error Injection Channel Descriptor 5, Word3 */
/*! @{ */

#define EIM_2_EICHD5_WORD3_B8_11DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_2_EICHD5_WORD3_B8_11DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD5_WORD3_B8_11DATA_MASK_WIDTH  (32U)
#define EIM_2_EICHD5_WORD3_B8_11DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD5_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_2_EICHD5_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD5_WORD4 - Error Injection Channel Descriptor 5, Word4 */
/*! @{ */

#define EIM_2_EICHD5_WORD4_B12_15DATA_MASK_MASK  (0xFFFFFFFFU)
#define EIM_2_EICHD5_WORD4_B12_15DATA_MASK_SHIFT (0U)
#define EIM_2_EICHD5_WORD4_B12_15DATA_MASK_WIDTH (32U)
#define EIM_2_EICHD5_WORD4_B12_15DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD5_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_2_EICHD5_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD5_WORD5 - Error Injection Channel Descriptor 5, Word5 */
/*! @{ */

#define EIM_2_EICHD5_WORD5_B16_19DATA_MASK_MASK  (0xFFFFFFFFU)
#define EIM_2_EICHD5_WORD5_B16_19DATA_MASK_SHIFT (0U)
#define EIM_2_EICHD5_WORD5_B16_19DATA_MASK_WIDTH (32U)
#define EIM_2_EICHD5_WORD5_B16_19DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD5_WORD5_B16_19DATA_MASK_SHIFT)) & EIM_2_EICHD5_WORD5_B16_19DATA_MASK_MASK)
/*! @} */

/*! @name EICHD5_WORD6 - Error Injection Channel Descriptor 5, Word6 */
/*! @{ */

#define EIM_2_EICHD5_WORD6_B20_23DATA_MASK_MASK  (0xFFFFFFFFU)
#define EIM_2_EICHD5_WORD6_B20_23DATA_MASK_SHIFT (0U)
#define EIM_2_EICHD5_WORD6_B20_23DATA_MASK_WIDTH (32U)
#define EIM_2_EICHD5_WORD6_B20_23DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD5_WORD6_B20_23DATA_MASK_SHIFT)) & EIM_2_EICHD5_WORD6_B20_23DATA_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD1 - Error Injection Channel Descriptor 6, Word1 */
/*! @{ */

#define EIM_2_EICHD6_WORD1_B0_3DATA_MASK_MASK    (0xFFFFFFFU)
#define EIM_2_EICHD6_WORD1_B0_3DATA_MASK_SHIFT   (0U)
#define EIM_2_EICHD6_WORD1_B0_3DATA_MASK_WIDTH   (28U)
#define EIM_2_EICHD6_WORD1_B0_3DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD6_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD6_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD2 - Error Injection Channel Descriptor 6, Word2 */
/*! @{ */

#define EIM_2_EICHD6_WORD2_B4_7DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_2_EICHD6_WORD2_B4_7DATA_MASK_SHIFT   (0U)
#define EIM_2_EICHD6_WORD2_B4_7DATA_MASK_WIDTH   (32U)
#define EIM_2_EICHD6_WORD2_B4_7DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD6_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_2_EICHD6_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD3 - Error Injection Channel Descriptor 6, Word3 */
/*! @{ */

#define EIM_2_EICHD6_WORD3_B8_11DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_2_EICHD6_WORD3_B8_11DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD6_WORD3_B8_11DATA_MASK_WIDTH  (32U)
#define EIM_2_EICHD6_WORD3_B8_11DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD6_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_2_EICHD6_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD4 - Error Injection Channel Descriptor 6, Word4 */
/*! @{ */

#define EIM_2_EICHD6_WORD4_B12_15DATA_MASK_MASK  (0xFFFFFFFFU)
#define EIM_2_EICHD6_WORD4_B12_15DATA_MASK_SHIFT (0U)
#define EIM_2_EICHD6_WORD4_B12_15DATA_MASK_WIDTH (32U)
#define EIM_2_EICHD6_WORD4_B12_15DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD6_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_2_EICHD6_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD5 - Error Injection Channel Descriptor 6, Word5 */
/*! @{ */

#define EIM_2_EICHD6_WORD5_B16_19DATA_MASK_MASK  (0xFFFFFFFFU)
#define EIM_2_EICHD6_WORD5_B16_19DATA_MASK_SHIFT (0U)
#define EIM_2_EICHD6_WORD5_B16_19DATA_MASK_WIDTH (32U)
#define EIM_2_EICHD6_WORD5_B16_19DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD6_WORD5_B16_19DATA_MASK_SHIFT)) & EIM_2_EICHD6_WORD5_B16_19DATA_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD6 - Error Injection Channel Descriptor 6, Word6 */
/*! @{ */

#define EIM_2_EICHD6_WORD6_B20_23DATA_MASK_MASK  (0xFFFFFFFFU)
#define EIM_2_EICHD6_WORD6_B20_23DATA_MASK_SHIFT (0U)
#define EIM_2_EICHD6_WORD6_B20_23DATA_MASK_WIDTH (32U)
#define EIM_2_EICHD6_WORD6_B20_23DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD6_WORD6_B20_23DATA_MASK_SHIFT)) & EIM_2_EICHD6_WORD6_B20_23DATA_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD1 - Error Injection Channel Descriptor 7, Word1 */
/*! @{ */

#define EIM_2_EICHD7_WORD1_B0_3DATA_MASK_MASK    (0xFFFFFFFU)
#define EIM_2_EICHD7_WORD1_B0_3DATA_MASK_SHIFT   (0U)
#define EIM_2_EICHD7_WORD1_B0_3DATA_MASK_WIDTH   (28U)
#define EIM_2_EICHD7_WORD1_B0_3DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD7_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD7_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD2 - Error Injection Channel Descriptor 7, Word2 */
/*! @{ */

#define EIM_2_EICHD7_WORD2_B4_7DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_2_EICHD7_WORD2_B4_7DATA_MASK_SHIFT   (0U)
#define EIM_2_EICHD7_WORD2_B4_7DATA_MASK_WIDTH   (32U)
#define EIM_2_EICHD7_WORD2_B4_7DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD7_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_2_EICHD7_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD8_WORD1 - Error Injection Channel Descriptor 8, Word1 */
/*! @{ */

#define EIM_2_EICHD8_WORD1_B0_3DATA_MASK_MASK    (0xFFFFFFFU)
#define EIM_2_EICHD8_WORD1_B0_3DATA_MASK_SHIFT   (0U)
#define EIM_2_EICHD8_WORD1_B0_3DATA_MASK_WIDTH   (28U)
#define EIM_2_EICHD8_WORD1_B0_3DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD8_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD8_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD8_WORD2 - Error Injection Channel Descriptor 8, Word2 */
/*! @{ */

#define EIM_2_EICHD8_WORD2_B4_7DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_2_EICHD8_WORD2_B4_7DATA_MASK_SHIFT   (0U)
#define EIM_2_EICHD8_WORD2_B4_7DATA_MASK_WIDTH   (32U)
#define EIM_2_EICHD8_WORD2_B4_7DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD8_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_2_EICHD8_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD9_WORD1 - Error Injection Channel Descriptor 9, Word1 */
/*! @{ */

#define EIM_2_EICHD9_WORD1_B0_3DATA_MASK_MASK    (0xFFFFFFFU)
#define EIM_2_EICHD9_WORD1_B0_3DATA_MASK_SHIFT   (0U)
#define EIM_2_EICHD9_WORD1_B0_3DATA_MASK_WIDTH   (28U)
#define EIM_2_EICHD9_WORD1_B0_3DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD9_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD9_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD9_WORD2 - Error Injection Channel Descriptor 9, Word2 */
/*! @{ */

#define EIM_2_EICHD9_WORD2_B4_7DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_2_EICHD9_WORD2_B4_7DATA_MASK_SHIFT   (0U)
#define EIM_2_EICHD9_WORD2_B4_7DATA_MASK_WIDTH   (32U)
#define EIM_2_EICHD9_WORD2_B4_7DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD9_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_2_EICHD9_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD10_WORD1 - Error Injection Channel Descriptor 10, Word1 */
/*! @{ */

#define EIM_2_EICHD10_WORD1_B0_3DATA_MASK_MASK   (0xFFFFFFFU)
#define EIM_2_EICHD10_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD10_WORD1_B0_3DATA_MASK_WIDTH  (28U)
#define EIM_2_EICHD10_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD10_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD10_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD10_WORD2 - Error Injection Channel Descriptor 10, Word2 */
/*! @{ */

#define EIM_2_EICHD10_WORD2_B4_7DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_2_EICHD10_WORD2_B4_7DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD10_WORD2_B4_7DATA_MASK_WIDTH  (32U)
#define EIM_2_EICHD10_WORD2_B4_7DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD10_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_2_EICHD10_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD11_WORD1 - Error Injection Channel Descriptor 11, Word1 */
/*! @{ */

#define EIM_2_EICHD11_WORD1_B0_3DATA_MASK_MASK   (0xFFFFFFFU)
#define EIM_2_EICHD11_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD11_WORD1_B0_3DATA_MASK_WIDTH  (28U)
#define EIM_2_EICHD11_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD11_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD11_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD11_WORD2 - Error Injection Channel Descriptor 11, Word2 */
/*! @{ */

#define EIM_2_EICHD11_WORD2_B4_7DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_2_EICHD11_WORD2_B4_7DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD11_WORD2_B4_7DATA_MASK_WIDTH  (32U)
#define EIM_2_EICHD11_WORD2_B4_7DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD11_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_2_EICHD11_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD12_WORD1 - Error Injection Channel Descriptor 12, Word1 */
/*! @{ */

#define EIM_2_EICHD12_WORD1_B0_3DATA_MASK_MASK   (0xFFFFFFFU)
#define EIM_2_EICHD12_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD12_WORD1_B0_3DATA_MASK_WIDTH  (28U)
#define EIM_2_EICHD12_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD12_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD12_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD12_WORD2 - Error Injection Channel Descriptor 12, Word2 */
/*! @{ */

#define EIM_2_EICHD12_WORD2_B4_7DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_2_EICHD12_WORD2_B4_7DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD12_WORD2_B4_7DATA_MASK_WIDTH  (32U)
#define EIM_2_EICHD12_WORD2_B4_7DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD12_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_2_EICHD12_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD13_WORD1 - Error Injection Channel Descriptor 13, Word1 */
/*! @{ */

#define EIM_2_EICHD13_WORD1_B0_3DATA_MASK_MASK   (0xFFFFFFFU)
#define EIM_2_EICHD13_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD13_WORD1_B0_3DATA_MASK_WIDTH  (28U)
#define EIM_2_EICHD13_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD13_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD13_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD13_WORD2 - Error Injection Channel Descriptor 13, Word2 */
/*! @{ */

#define EIM_2_EICHD13_WORD2_B4_7DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_2_EICHD13_WORD2_B4_7DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD13_WORD2_B4_7DATA_MASK_WIDTH  (32U)
#define EIM_2_EICHD13_WORD2_B4_7DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD13_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_2_EICHD13_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD14_WORD1 - Error Injection Channel Descriptor 14, Word1 */
/*! @{ */

#define EIM_2_EICHD14_WORD1_B0_3DATA_MASK_MASK   (0xFFFFFFFU)
#define EIM_2_EICHD14_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD14_WORD1_B0_3DATA_MASK_WIDTH  (28U)
#define EIM_2_EICHD14_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD14_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD14_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD14_WORD2 - Error Injection Channel Descriptor 14, Word2 */
/*! @{ */

#define EIM_2_EICHD14_WORD2_B4_7DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_2_EICHD14_WORD2_B4_7DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD14_WORD2_B4_7DATA_MASK_WIDTH  (32U)
#define EIM_2_EICHD14_WORD2_B4_7DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD14_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_2_EICHD14_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD15_WORD1 - Error Injection Channel Descriptor 15, Word1 */
/*! @{ */

#define EIM_2_EICHD15_WORD1_B0_3DATA_MASK_MASK   (0xFFFFFFFU)
#define EIM_2_EICHD15_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD15_WORD1_B0_3DATA_MASK_WIDTH  (28U)
#define EIM_2_EICHD15_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD15_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD15_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD15_WORD2 - Error Injection Channel Descriptor 15, Word2 */
/*! @{ */

#define EIM_2_EICHD15_WORD2_B4_7DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_2_EICHD15_WORD2_B4_7DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD15_WORD2_B4_7DATA_MASK_WIDTH  (32U)
#define EIM_2_EICHD15_WORD2_B4_7DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD15_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_2_EICHD15_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD16_WORD1 - Error Injection Channel Descriptor 16, Word1 */
/*! @{ */

#define EIM_2_EICHD16_WORD1_B0_3DATA_MASK_MASK   (0xFFFFFFFU)
#define EIM_2_EICHD16_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD16_WORD1_B0_3DATA_MASK_WIDTH  (28U)
#define EIM_2_EICHD16_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD16_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD16_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD16_WORD2 - Error Injection Channel Descriptor 16, Word2 */
/*! @{ */

#define EIM_2_EICHD16_WORD2_B4_7DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_2_EICHD16_WORD2_B4_7DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD16_WORD2_B4_7DATA_MASK_WIDTH  (32U)
#define EIM_2_EICHD16_WORD2_B4_7DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD16_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_2_EICHD16_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD17_WORD1 - Error Injection Channel Descriptor 17, Word1 */
/*! @{ */

#define EIM_2_EICHD17_WORD1_B0_3DATA_MASK_MASK   (0xFFFFFFFU)
#define EIM_2_EICHD17_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD17_WORD1_B0_3DATA_MASK_WIDTH  (28U)
#define EIM_2_EICHD17_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD17_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD17_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD17_WORD2 - Error Injection Channel Descriptor 17, Word2 */
/*! @{ */

#define EIM_2_EICHD17_WORD2_B4_7DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_2_EICHD17_WORD2_B4_7DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD17_WORD2_B4_7DATA_MASK_WIDTH  (32U)
#define EIM_2_EICHD17_WORD2_B4_7DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD17_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_2_EICHD17_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD18_WORD1 - Error Injection Channel Descriptor 18, Word1 */
/*! @{ */

#define EIM_2_EICHD18_WORD1_B0_3DATA_MASK_MASK   (0xFFFFFFFU)
#define EIM_2_EICHD18_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD18_WORD1_B0_3DATA_MASK_WIDTH  (28U)
#define EIM_2_EICHD18_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD18_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD18_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD18_WORD2 - Error Injection Channel Descriptor 18, Word2 */
/*! @{ */

#define EIM_2_EICHD18_WORD2_B4_7DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_2_EICHD18_WORD2_B4_7DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD18_WORD2_B4_7DATA_MASK_WIDTH  (32U)
#define EIM_2_EICHD18_WORD2_B4_7DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD18_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_2_EICHD18_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD21_WORD1 - Error Injection Channel Descriptor 21, Word1 */
/*! @{ */

#define EIM_2_EICHD21_WORD1_B0_3DATA_MASK_MASK   (0xFFU)
#define EIM_2_EICHD21_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD21_WORD1_B0_3DATA_MASK_WIDTH  (8U)
#define EIM_2_EICHD21_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD21_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD21_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD22_WORD1 - Error Injection Channel Descriptor 22, Word1 */
/*! @{ */

#define EIM_2_EICHD22_WORD1_B0_3DATA_MASK_MASK   (0xFFFFFFFU)
#define EIM_2_EICHD22_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD22_WORD1_B0_3DATA_MASK_WIDTH  (28U)
#define EIM_2_EICHD22_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD22_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD22_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD22_WORD2 - Error Injection Channel Descriptor 22, Word2 */
/*! @{ */

#define EIM_2_EICHD22_WORD2_B4_7DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_2_EICHD22_WORD2_B4_7DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD22_WORD2_B4_7DATA_MASK_WIDTH  (32U)
#define EIM_2_EICHD22_WORD2_B4_7DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD22_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_2_EICHD22_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD22_WORD3 - Error Injection Channel Descriptor 22, Word3 */
/*! @{ */

#define EIM_2_EICHD22_WORD3_B8_11DATA_MASK_MASK  (0xFFFFFFFFU)
#define EIM_2_EICHD22_WORD3_B8_11DATA_MASK_SHIFT (0U)
#define EIM_2_EICHD22_WORD3_B8_11DATA_MASK_WIDTH (32U)
#define EIM_2_EICHD22_WORD3_B8_11DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD22_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_2_EICHD22_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD22_WORD4 - Error Injection Channel Descriptor 22, Word4 */
/*! @{ */

#define EIM_2_EICHD22_WORD4_B12_15DATA_MASK_MASK (0xFFFFFFFFU)
#define EIM_2_EICHD22_WORD4_B12_15DATA_MASK_SHIFT (0U)
#define EIM_2_EICHD22_WORD4_B12_15DATA_MASK_WIDTH (32U)
#define EIM_2_EICHD22_WORD4_B12_15DATA_MASK(x)   (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD22_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_2_EICHD22_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD22_WORD5 - Error Injection Channel Descriptor 22, Word5 */
/*! @{ */

#define EIM_2_EICHD22_WORD5_B16_19DATA_MASK_MASK (0xFFFFFFFFU)
#define EIM_2_EICHD22_WORD5_B16_19DATA_MASK_SHIFT (0U)
#define EIM_2_EICHD22_WORD5_B16_19DATA_MASK_WIDTH (32U)
#define EIM_2_EICHD22_WORD5_B16_19DATA_MASK(x)   (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD22_WORD5_B16_19DATA_MASK_SHIFT)) & EIM_2_EICHD22_WORD5_B16_19DATA_MASK_MASK)
/*! @} */

/*! @name EICHD22_WORD6 - Error Injection Channel Descriptor 22, Word6 */
/*! @{ */

#define EIM_2_EICHD22_WORD6_B20_23DATA_MASK_MASK (0xFFFFFFFFU)
#define EIM_2_EICHD22_WORD6_B20_23DATA_MASK_SHIFT (0U)
#define EIM_2_EICHD22_WORD6_B20_23DATA_MASK_WIDTH (32U)
#define EIM_2_EICHD22_WORD6_B20_23DATA_MASK(x)   (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD22_WORD6_B20_23DATA_MASK_SHIFT)) & EIM_2_EICHD22_WORD6_B20_23DATA_MASK_MASK)
/*! @} */

/*! @name EICHD23_WORD0 - Error Injection Channel Descriptor 23, Word0 */
/*! @{ */

#define EIM_2_EICHD23_WORD0_CHKBIT_MASK_MASK     (0xFE000000U)
#define EIM_2_EICHD23_WORD0_CHKBIT_MASK_SHIFT    (25U)
#define EIM_2_EICHD23_WORD0_CHKBIT_MASK_WIDTH    (7U)
#define EIM_2_EICHD23_WORD0_CHKBIT_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD23_WORD0_CHKBIT_MASK_SHIFT)) & EIM_2_EICHD23_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD23_WORD1 - Error Injection Channel Descriptor 23, Word1 */
/*! @{ */

#define EIM_2_EICHD23_WORD1_B0_3DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_2_EICHD23_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD23_WORD1_B0_3DATA_MASK_WIDTH  (32U)
#define EIM_2_EICHD23_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD23_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD23_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD24_WORD0 - Error Injection Channel Descriptor 24, Word0 */
/*! @{ */

#define EIM_2_EICHD24_WORD0_CHKBIT_MASK_MASK     (0xFC000000U)
#define EIM_2_EICHD24_WORD0_CHKBIT_MASK_SHIFT    (26U)
#define EIM_2_EICHD24_WORD0_CHKBIT_MASK_WIDTH    (6U)
#define EIM_2_EICHD24_WORD0_CHKBIT_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD24_WORD0_CHKBIT_MASK_SHIFT)) & EIM_2_EICHD24_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD24_WORD1 - Error Injection Channel Descriptor 24, Word1 */
/*! @{ */

#define EIM_2_EICHD24_WORD1_B0_3DATA_MASK_MASK   (0xFFFFU)
#define EIM_2_EICHD24_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD24_WORD1_B0_3DATA_MASK_WIDTH  (16U)
#define EIM_2_EICHD24_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD24_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD24_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD25_WORD0 - Error Injection Channel Descriptor 25, Word0 */
/*! @{ */

#define EIM_2_EICHD25_WORD0_CHKBIT_MASK_MASK     (0xFC000000U)
#define EIM_2_EICHD25_WORD0_CHKBIT_MASK_SHIFT    (26U)
#define EIM_2_EICHD25_WORD0_CHKBIT_MASK_WIDTH    (6U)
#define EIM_2_EICHD25_WORD0_CHKBIT_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD25_WORD0_CHKBIT_MASK_SHIFT)) & EIM_2_EICHD25_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD25_WORD1 - Error Injection Channel Descriptor 25, Word1 */
/*! @{ */

#define EIM_2_EICHD25_WORD1_B0_3DATA_MASK_MASK   (0xFFFFU)
#define EIM_2_EICHD25_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD25_WORD1_B0_3DATA_MASK_WIDTH  (16U)
#define EIM_2_EICHD25_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD25_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD25_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD26_WORD1 - Error Injection Channel Descriptor 26, Word1 */
/*! @{ */

#define EIM_2_EICHD26_WORD1_B0_3DATA_MASK_MASK   (0x3FFU)
#define EIM_2_EICHD26_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD26_WORD1_B0_3DATA_MASK_WIDTH  (10U)
#define EIM_2_EICHD26_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD26_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD26_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD27_WORD1 - Error Injection Channel Descriptor 27, Word1 */
/*! @{ */

#define EIM_2_EICHD27_WORD1_B0_3DATA_MASK_MASK   (0xFU)
#define EIM_2_EICHD27_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD27_WORD1_B0_3DATA_MASK_WIDTH  (4U)
#define EIM_2_EICHD27_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD27_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD27_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD28_WORD1 - Error Injection Channel Descriptor 28, Word1 */
/*! @{ */

#define EIM_2_EICHD28_WORD1_B0_3DATA_MASK_MASK   (0xFFU)
#define EIM_2_EICHD28_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD28_WORD1_B0_3DATA_MASK_WIDTH  (8U)
#define EIM_2_EICHD28_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD28_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD28_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD29_WORD1 - Error Injection Channel Descriptor 29, Word1 */
/*! @{ */

#define EIM_2_EICHD29_WORD1_B0_3DATA_MASK_MASK   (0xFFFFFFFU)
#define EIM_2_EICHD29_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD29_WORD1_B0_3DATA_MASK_WIDTH  (28U)
#define EIM_2_EICHD29_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD29_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD29_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD30_WORD1 - Error Injection Channel Descriptor 30, Word1 */
/*! @{ */

#define EIM_2_EICHD30_WORD1_B0_3DATA_MASK_MASK   (0x3FFFFU)
#define EIM_2_EICHD30_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD30_WORD1_B0_3DATA_MASK_WIDTH  (18U)
#define EIM_2_EICHD30_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD30_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD30_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD31_WORD1 - Error Injection Channel Descriptor 31, Word1 */
/*! @{ */

#define EIM_2_EICHD31_WORD1_B0_3DATA_MASK_MASK   (0x3FFFFU)
#define EIM_2_EICHD31_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_2_EICHD31_WORD1_B0_3DATA_MASK_WIDTH  (18U)
#define EIM_2_EICHD31_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_2_EICHD31_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_2_EICHD31_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group EIM_2_Register_Masks */

/*!
 * @}
 */ /* end of group EIM_2_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K39_EIM_2_H_) */
