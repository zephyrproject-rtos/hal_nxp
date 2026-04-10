/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K39_EIM.h
 * @version 1.7
 * @date 2022-11-18
 * @brief Peripheral Access Layer for S32K39_EIM
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
#if !defined(S32K39_EIM_H_)  /* Check if memory map has not been already included */
#define S32K39_EIM_H_

#include "S32K39_COMMON.h"

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
  __IO uint32_t EICHD0_WORD0;                      /**< Error Injection Channel Descriptor 0, Word0, offset: 0x100 */
  __IO uint32_t EICHD0_WORD1;                      /**< Error Injection Channel Descriptor 0, Word1, offset: 0x104 */
  __IO uint32_t EICHD0_WORD2;                      /**< Error Injection Channel Descriptor 0, Word2, offset: 0x108 */
  uint8_t RESERVED_1[52];
  __IO uint32_t EICHD1_WORD0;                      /**< Error Injection Channel Descriptor 1, Word0, offset: 0x140 */
  __IO uint32_t EICHD1_WORD1;                      /**< Error Injection Channel Descriptor 1, Word1, offset: 0x144 */
  __IO uint32_t EICHD1_WORD2;                      /**< Error Injection Channel Descriptor 1, Word2, offset: 0x148 */
  __IO uint32_t EICHD1_WORD3;                      /**< Error Injection Channel Descriptor 1, Word3, offset: 0x14C */
  __IO uint32_t EICHD1_WORD4;                      /**< Error Injection Channel Descriptor 1, Word4, offset: 0x150 */
  uint8_t RESERVED_2[44];
  __IO uint32_t EICHD2_WORD0;                      /**< Error Injection Channel Descriptor 2, Word0, offset: 0x180 */
  __IO uint32_t EICHD2_WORD1;                      /**< Error Injection Channel Descriptor 2, Word1, offset: 0x184 */
  __IO uint32_t EICHD2_WORD2;                      /**< Error Injection Channel Descriptor 2, Word2, offset: 0x188 */
  __IO uint32_t EICHD2_WORD3;                      /**< Error Injection Channel Descriptor 2, Word3, offset: 0x18C */
  __IO uint32_t EICHD2_WORD4;                      /**< Error Injection Channel Descriptor 2, Word4, offset: 0x190 */
  uint8_t RESERVED_3[44];
  __IO uint32_t EICHD3_WORD0;                      /**< Error Injection Channel Descriptor 3, Word0, offset: 0x1C0 */
  __IO uint32_t EICHD3_WORD1;                      /**< Error Injection Channel Descriptor 3, Word1, offset: 0x1C4 */
  __IO uint32_t EICHD3_WORD2;                      /**< Error Injection Channel Descriptor 3, Word2, offset: 0x1C8 */
  __IO uint32_t EICHD3_WORD3;                      /**< Error Injection Channel Descriptor 3, Word3, offset: 0x1CC */
  __IO uint32_t EICHD3_WORD4;                      /**< Error Injection Channel Descriptor 3, Word4, offset: 0x1D0 */
  uint8_t RESERVED_4[44];
  __IO uint32_t EICHD4_WORD0;                      /**< Error Injection Channel Descriptor 4, Word0, offset: 0x200 */
  __IO uint32_t EICHD4_WORD1;                      /**< Error Injection Channel Descriptor 4, Word1, offset: 0x204 */
  __IO uint32_t EICHD4_WORD2;                      /**< Error Injection Channel Descriptor 4, Word2, offset: 0x208 */
  __IO uint32_t EICHD4_WORD3;                      /**< Error Injection Channel Descriptor 4, Word3, offset: 0x20C */
  __IO uint32_t EICHD4_WORD4;                      /**< Error Injection Channel Descriptor 4, Word4, offset: 0x210 */
  uint8_t RESERVED_5[44];
  __IO uint32_t EICHD5_WORD0;                      /**< Error Injection Channel Descriptor 5, Word0, offset: 0x240 */
  __IO uint32_t EICHD5_WORD1;                      /**< Error Injection Channel Descriptor 5, Word1, offset: 0x244 */
  __IO uint32_t EICHD5_WORD2;                      /**< Error Injection Channel Descriptor 5, Word2, offset: 0x248 */
  uint8_t RESERVED_6[52];
  __IO uint32_t EICHD6_WORD0;                      /**< Error Injection Channel Descriptor 6, Word0, offset: 0x280 */
  __IO uint32_t EICHD6_WORD1;                      /**< Error Injection Channel Descriptor 6, Word1, offset: 0x284 */
  __IO uint32_t EICHD6_WORD2;                      /**< Error Injection Channel Descriptor 6, Word2, offset: 0x288 */
  __IO uint32_t EICHD6_WORD3;                      /**< Error Injection Channel Descriptor 6, Word3, offset: 0x28C */
  __IO uint32_t EICHD6_WORD4;                      /**< Error Injection Channel Descriptor 6, Word4, offset: 0x290 */
  uint8_t RESERVED_7[44];
  __IO uint32_t EICHD7_WORD0;                      /**< Error Injection Channel Descriptor 7, Word0, offset: 0x2C0 */
  __IO uint32_t EICHD7_WORD1;                      /**< Error Injection Channel Descriptor 7, Word1, offset: 0x2C4 */
  __IO uint32_t EICHD7_WORD2;                      /**< Error Injection Channel Descriptor 7, Word2, offset: 0x2C8 */
  __IO uint32_t EICHD7_WORD3;                      /**< Error Injection Channel Descriptor 7, Word3, offset: 0x2CC */
  __IO uint32_t EICHD7_WORD4;                      /**< Error Injection Channel Descriptor 7, Word4, offset: 0x2D0 */
  uint8_t RESERVED_8[44];
  __IO uint32_t EICHD8_WORD0;                      /**< Error Injection Channel Descriptor 8, Word0, offset: 0x300 */
  __IO uint32_t EICHD8_WORD1;                      /**< Error Injection Channel Descriptor 8, Word1, offset: 0x304 */
  __IO uint32_t EICHD8_WORD2;                      /**< Error Injection Channel Descriptor 8, Word2, offset: 0x308 */
  __IO uint32_t EICHD8_WORD3;                      /**< Error Injection Channel Descriptor 8, Word3, offset: 0x30C */
  __IO uint32_t EICHD8_WORD4;                      /**< Error Injection Channel Descriptor 8, Word4, offset: 0x310 */
  uint8_t RESERVED_9[44];
  __IO uint32_t EICHD9_WORD0;                      /**< Error Injection Channel Descriptor 9, Word0, offset: 0x340 */
  __IO uint32_t EICHD9_WORD1;                      /**< Error Injection Channel Descriptor 9, Word1, offset: 0x344 */
  __IO uint32_t EICHD9_WORD2;                      /**< Error Injection Channel Descriptor 9, Word2, offset: 0x348 */
  __IO uint32_t EICHD9_WORD3;                      /**< Error Injection Channel Descriptor 9, Word3, offset: 0x34C */
  __IO uint32_t EICHD9_WORD4;                      /**< Error Injection Channel Descriptor 9, Word4, offset: 0x350 */
  uint8_t RESERVED_10[44];
  __IO uint32_t EICHD10_WORD0;                     /**< Error Injection Channel Descriptor 10, Word0, offset: 0x380 */
  __IO uint32_t EICHD10_WORD1;                     /**< Error Injection Channel Descriptor 10, Word1, offset: 0x384 */
  __IO uint32_t EICHD10_WORD2;                     /**< Error Injection Channel Descriptor 10, Word2, offset: 0x388 */
  uint8_t RESERVED_11[52];
  __IO uint32_t EICHD11_WORD0;                     /**< Error Injection Channel Descriptor 11, Word0, offset: 0x3C0 */
  __IO uint32_t EICHD11_WORD1;                     /**< Error Injection Channel Descriptor 11, Word1, offset: 0x3C4 */
  uint8_t RESERVED_12[56];
  __IO uint32_t EICHD12_WORD0;                     /**< Error Injection Channel Descriptor 12, Word0, offset: 0x400 */
  __IO uint32_t EICHD12_WORD1;                     /**< Error Injection Channel Descriptor 12, Word1, offset: 0x404 */
  uint8_t RESERVED_13[56];
  __IO uint32_t EICHD13_WORD0;                     /**< Error Injection Channel Descriptor 13, Word0, offset: 0x440 */
  __IO uint32_t EICHD13_WORD1;                     /**< Error Injection Channel Descriptor 13, Word1, offset: 0x444 */
  __IO uint32_t EICHD13_WORD2;                     /**< Error Injection Channel Descriptor 13, Word2, offset: 0x448 */
  uint8_t RESERVED_14[52];
  __IO uint32_t EICHD14_WORD0;                     /**< Error Injection Channel Descriptor 14, Word0, offset: 0x480 */
  __IO uint32_t EICHD14_WORD1;                     /**< Error Injection Channel Descriptor 14, Word1, offset: 0x484 */
  uint8_t RESERVED_15[56];
  __IO uint32_t EICHD15_WORD0;                     /**< Error Injection Channel Descriptor 15, Word0, offset: 0x4C0 */
  __IO uint32_t EICHD15_WORD1;                     /**< Error Injection Channel Descriptor 15, Word1, offset: 0x4C4 */
  uint8_t RESERVED_16[60];
  __IO uint32_t EICHD16_WORD1;                     /**< Error Injection Channel Descriptor 16, Word1, offset: 0x504 */
  uint8_t RESERVED_17[60];
  __IO uint32_t EICHD17_WORD1;                     /**< Error Injection Channel Descriptor 17, Word1, offset: 0x544 */
  __IO uint32_t EICHD17_WORD2;                     /**< Error Injection Channel Descriptor 17, Word2, offset: 0x548 */
  uint8_t RESERVED_18[56];
  __IO uint32_t EICHD18_WORD1;                     /**< Error Injection Channel Descriptor 18, Word1, offset: 0x584 */
  __IO uint32_t EICHD18_WORD2;                     /**< Error Injection Channel Descriptor 18, Word2, offset: 0x588 */
} EIM_Type, *EIM_MemMapPtr;

/** Number of instances of the EIM module. */
#define EIM_INSTANCE_COUNT                       (1u)

/* EIM - Peripheral instance base addresses */
/** Peripheral EIM_0 base address */
#define IP_EIM_0_BASE                            (0x4050C000u)
/** Peripheral EIM_0 base pointer */
#define IP_EIM_0                                 ((EIM_Type *)IP_EIM_0_BASE)
/** Array initializer of EIM peripheral base addresses */
#define IP_EIM_BASE_ADDRS                        { IP_EIM_0_BASE }
/** Array initializer of EIM peripheral base pointers */
#define IP_EIM_BASE_PTRS                         { IP_EIM_0 }

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

#define EIM_EICHD0_WORD0_CHKBIT_MASK_MASK        (0xFFFC0000U)
#define EIM_EICHD0_WORD0_CHKBIT_MASK_SHIFT       (18U)
#define EIM_EICHD0_WORD0_CHKBIT_MASK_WIDTH       (14U)
#define EIM_EICHD0_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD0_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD0_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD0_WORD1 - Error Injection Channel Descriptor 0, Word1 */
/*! @{ */

#define EIM_EICHD0_WORD1_B0_3DATA_MASK_MASK      (0xFFFU)
#define EIM_EICHD0_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD0_WORD1_B0_3DATA_MASK_WIDTH     (12U)
#define EIM_EICHD0_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD0_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD0_WORD1_B0_3DATA_MASK_MASK)
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

#define EIM_EICHD1_WORD0_CHKBIT_MASK_MASK        (0xFFFF0000U)
#define EIM_EICHD1_WORD0_CHKBIT_MASK_SHIFT       (16U)
#define EIM_EICHD1_WORD0_CHKBIT_MASK_WIDTH       (16U)
#define EIM_EICHD1_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD1_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD1_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD1 - Error Injection Channel Descriptor 1, Word1 */
/*! @{ */

#define EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD1_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD1_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD1_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD1_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK)
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

#define EIM_EICHD2_WORD0_CHKBIT_MASK_MASK        (0xFFFFFFF0U)
#define EIM_EICHD2_WORD0_CHKBIT_MASK_SHIFT       (4U)
#define EIM_EICHD2_WORD0_CHKBIT_MASK_WIDTH       (28U)
#define EIM_EICHD2_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD2_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD2_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD1 - Error Injection Channel Descriptor 2, Word1 */
/*! @{ */

#define EIM_EICHD2_WORD1_B0_3DATA_MASK_MASK      (0xFFU)
#define EIM_EICHD2_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD2_WORD1_B0_3DATA_MASK_WIDTH     (8U)
#define EIM_EICHD2_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD2_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD2_WORD1_B0_3DATA_MASK_MASK)
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

#define EIM_EICHD3_WORD0_CHKBIT_MASK_MASK        (0xFFFFFFF0U)
#define EIM_EICHD3_WORD0_CHKBIT_MASK_SHIFT       (4U)
#define EIM_EICHD3_WORD0_CHKBIT_MASK_WIDTH       (28U)
#define EIM_EICHD3_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD3_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD3_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD1 - Error Injection Channel Descriptor 3, Word1 */
/*! @{ */

#define EIM_EICHD3_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD3_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD3_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD3_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD3_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD3_WORD1_B0_3DATA_MASK_MASK)
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

#define EIM_EICHD4_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD4_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD4_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHD4_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD4_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD4_WORD1_B0_3DATA_MASK_MASK)
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

/*! @name EICHD5_WORD0 - Error Injection Channel Descriptor 5, Word0 */
/*! @{ */

#define EIM_EICHD5_WORD0_CHKBIT_MASK_MASK        (0xFFFC0000U)
#define EIM_EICHD5_WORD0_CHKBIT_MASK_SHIFT       (18U)
#define EIM_EICHD5_WORD0_CHKBIT_MASK_WIDTH       (14U)
#define EIM_EICHD5_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD5_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD5_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD5_WORD1 - Error Injection Channel Descriptor 5, Word1 */
/*! @{ */

#define EIM_EICHD5_WORD1_B0_3DATA_MASK_MASK      (0xFFFU)
#define EIM_EICHD5_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD5_WORD1_B0_3DATA_MASK_WIDTH     (12U)
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

#define EIM_EICHD6_WORD0_CHKBIT_MASK_MASK        (0xFFFF0000U)
#define EIM_EICHD6_WORD0_CHKBIT_MASK_SHIFT       (16U)
#define EIM_EICHD6_WORD0_CHKBIT_MASK_WIDTH       (16U)
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

#define EIM_EICHD7_WORD0_CHKBIT_MASK_MASK        (0xFFFFFFF0U)
#define EIM_EICHD7_WORD0_CHKBIT_MASK_SHIFT       (4U)
#define EIM_EICHD7_WORD0_CHKBIT_MASK_WIDTH       (28U)
#define EIM_EICHD7_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD7_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD7_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD1 - Error Injection Channel Descriptor 7, Word1 */
/*! @{ */

#define EIM_EICHD7_WORD1_B0_3DATA_MASK_MASK      (0xFFU)
#define EIM_EICHD7_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHD7_WORD1_B0_3DATA_MASK_WIDTH     (8U)
#define EIM_EICHD7_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD7_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD7_WORD1_B0_3DATA_MASK_MASK)
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

#define EIM_EICHD8_WORD0_CHKBIT_MASK_MASK        (0xFFFFFFF0U)
#define EIM_EICHD8_WORD0_CHKBIT_MASK_SHIFT       (4U)
#define EIM_EICHD8_WORD0_CHKBIT_MASK_WIDTH       (28U)
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

/*! @name EICHD9_WORD0 - Error Injection Channel Descriptor 9, Word0 */
/*! @{ */

#define EIM_EICHD9_WORD0_CHKBIT_MASK_MASK        (0xFFFFFFF0U)
#define EIM_EICHD9_WORD0_CHKBIT_MASK_SHIFT       (4U)
#define EIM_EICHD9_WORD0_CHKBIT_MASK_WIDTH       (28U)
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

/*! @name EICHD10_WORD0 - Error Injection Channel Descriptor 10, Word0 */
/*! @{ */

#define EIM_EICHD10_WORD0_CHKBIT_MASK_MASK       (0xFF000000U)
#define EIM_EICHD10_WORD0_CHKBIT_MASK_SHIFT      (24U)
#define EIM_EICHD10_WORD0_CHKBIT_MASK_WIDTH      (8U)
#define EIM_EICHD10_WORD0_CHKBIT_MASK(x)         (((uint32_t)(((uint32_t)(x)) << EIM_EICHD10_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD10_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD10_WORD1 - Error Injection Channel Descriptor 10, Word1 */
/*! @{ */

#define EIM_EICHD10_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD10_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD10_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD10_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD10_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD10_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD10_WORD2 - Error Injection Channel Descriptor 10, Word2 */
/*! @{ */

#define EIM_EICHD10_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD10_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD10_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD10_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD10_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD10_WORD2_B4_7DATA_MASK_MASK)
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

#define EIM_EICHD11_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD11_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD11_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD11_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD11_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD11_WORD1_B0_3DATA_MASK_MASK)
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

#define EIM_EICHD12_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD12_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD12_WORD1_B0_3DATA_MASK_WIDTH    (32U)
#define EIM_EICHD12_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD12_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD12_WORD1_B0_3DATA_MASK_MASK)
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

/*! @name EICHD16_WORD1 - Error Injection Channel Descriptor 16, Word1 */
/*! @{ */

#define EIM_EICHD16_WORD1_B0_3DATA_MASK_MASK     (0x3FFFFFFFU)
#define EIM_EICHD16_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD16_WORD1_B0_3DATA_MASK_WIDTH    (30U)
#define EIM_EICHD16_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD16_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD16_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD17_WORD1 - Error Injection Channel Descriptor 17, Word1 */
/*! @{ */

#define EIM_EICHD17_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFU)
#define EIM_EICHD17_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD17_WORD1_B0_3DATA_MASK_WIDTH    (28U)
#define EIM_EICHD17_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD17_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD17_WORD1_B0_3DATA_MASK_MASK)
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

#define EIM_EICHD18_WORD1_B0_3DATA_MASK_MASK     (0xFFFFFFFU)
#define EIM_EICHD18_WORD1_B0_3DATA_MASK_SHIFT    (0U)
#define EIM_EICHD18_WORD1_B0_3DATA_MASK_WIDTH    (28U)
#define EIM_EICHD18_WORD1_B0_3DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD18_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD18_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD18_WORD2 - Error Injection Channel Descriptor 18, Word2 */
/*! @{ */

#define EIM_EICHD18_WORD2_B4_7DATA_MASK_MASK     (0xFFFFFFFFU)
#define EIM_EICHD18_WORD2_B4_7DATA_MASK_SHIFT    (0U)
#define EIM_EICHD18_WORD2_B4_7DATA_MASK_WIDTH    (32U)
#define EIM_EICHD18_WORD2_B4_7DATA_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_EICHD18_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_EICHD18_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group EIM_Register_Masks */

/*!
 * @}
 */ /* end of group EIM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K39_EIM_H_) */
