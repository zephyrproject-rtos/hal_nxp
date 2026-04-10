/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K39_EIM_1.h
 * @version 1.7
 * @date 2022-11-18
 * @brief Peripheral Access Layer for S32K39_EIM_1
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
#if !defined(S32K39_EIM_1_H_)  /* Check if memory map has not been already included */
#define S32K39_EIM_1_H_

#include "S32K39_COMMON.h"

/* ----------------------------------------------------------------------------
   -- EIM_1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EIM_1_Peripheral_Access_Layer EIM_1 Peripheral Access Layer
 * @{
 */

/** EIM_1 - Register Layout Typedef */
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
  uint8_t RESERVED_5[364];
  __IO uint32_t EICHD10_WORD0;                     /**< Error Injection Channel Descriptor 10, Word0, offset: 0x380 */
  __IO uint32_t EICHD10_WORD1;                     /**< Error Injection Channel Descriptor 10, Word1, offset: 0x384 */
  __IO uint32_t EICHD10_WORD2;                     /**< Error Injection Channel Descriptor 10, Word2, offset: 0x388 */
  uint8_t RESERVED_6[52];
  __IO uint32_t EICHD11_WORD0;                     /**< Error Injection Channel Descriptor 11, Word0, offset: 0x3C0 */
  __IO uint32_t EICHD11_WORD1;                     /**< Error Injection Channel Descriptor 11, Word1, offset: 0x3C4 */
  uint8_t RESERVED_7[56];
  __IO uint32_t EICHD12_WORD0;                     /**< Error Injection Channel Descriptor 12, Word0, offset: 0x400 */
  __IO uint32_t EICHD12_WORD1;                     /**< Error Injection Channel Descriptor 12, Word1, offset: 0x404 */
  uint8_t RESERVED_8[252];
  __IO uint32_t EICHD16_WORD1;                     /**< Error Injection Channel Descriptor 16, Word1, offset: 0x504 */
  uint8_t RESERVED_9[60];
  __IO uint32_t EICHD17_WORD1;                     /**< Error Injection Channel Descriptor 17, Word1, offset: 0x544 */
  __IO uint32_t EICHD17_WORD2;                     /**< Error Injection Channel Descriptor 17, Word2, offset: 0x548 */
} EIM_1_Type, *EIM_1_MemMapPtr;

/** Number of instances of the EIM_1 module. */
#define EIM_1_INSTANCE_COUNT                     (1u)

/* EIM_1 - Peripheral instance base addresses */
/** Peripheral EIM_1 base address */
#define IP_EIM_1_BASE                            (0x40510000u)
/** Peripheral EIM_1 base pointer */
#define IP_EIM_1                                 ((EIM_1_Type *)IP_EIM_1_BASE)
/** Array initializer of EIM_1 peripheral base addresses */
#define IP_EIM_1_BASE_ADDRS                      { IP_EIM_1_BASE }
/** Array initializer of EIM_1 peripheral base pointers */
#define IP_EIM_1_BASE_PTRS                       { IP_EIM_1 }

/* ----------------------------------------------------------------------------
   -- EIM_1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EIM_1_Register_Masks EIM_1 Register Masks
 * @{
 */

/*! @name EIMCR - Error Injection Module Configuration Register */
/*! @{ */

#define EIM_1_EIMCR_GEIEN_MASK                   (0x1U)
#define EIM_1_EIMCR_GEIEN_SHIFT                  (0U)
#define EIM_1_EIMCR_GEIEN_WIDTH                  (1U)
#define EIM_1_EIMCR_GEIEN(x)                     (((uint32_t)(((uint32_t)(x)) << EIM_1_EIMCR_GEIEN_SHIFT)) & EIM_1_EIMCR_GEIEN_MASK)
/*! @} */

/*! @name EICHEN - Error Injection Channel Enable register */
/*! @{ */

#define EIM_1_EICHEN_EICH17EN_MASK               (0x4000U)
#define EIM_1_EICHEN_EICH17EN_SHIFT              (14U)
#define EIM_1_EICHEN_EICH17EN_WIDTH              (1U)
#define EIM_1_EICHEN_EICH17EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHEN_EICH17EN_SHIFT)) & EIM_1_EICHEN_EICH17EN_MASK)

#define EIM_1_EICHEN_EICH16EN_MASK               (0x8000U)
#define EIM_1_EICHEN_EICH16EN_SHIFT              (15U)
#define EIM_1_EICHEN_EICH16EN_WIDTH              (1U)
#define EIM_1_EICHEN_EICH16EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHEN_EICH16EN_SHIFT)) & EIM_1_EICHEN_EICH16EN_MASK)

#define EIM_1_EICHEN_EICH12EN_MASK               (0x80000U)
#define EIM_1_EICHEN_EICH12EN_SHIFT              (19U)
#define EIM_1_EICHEN_EICH12EN_WIDTH              (1U)
#define EIM_1_EICHEN_EICH12EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHEN_EICH12EN_SHIFT)) & EIM_1_EICHEN_EICH12EN_MASK)

#define EIM_1_EICHEN_EICH11EN_MASK               (0x100000U)
#define EIM_1_EICHEN_EICH11EN_SHIFT              (20U)
#define EIM_1_EICHEN_EICH11EN_WIDTH              (1U)
#define EIM_1_EICHEN_EICH11EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHEN_EICH11EN_SHIFT)) & EIM_1_EICHEN_EICH11EN_MASK)

#define EIM_1_EICHEN_EICH10EN_MASK               (0x200000U)
#define EIM_1_EICHEN_EICH10EN_SHIFT              (21U)
#define EIM_1_EICHEN_EICH10EN_WIDTH              (1U)
#define EIM_1_EICHEN_EICH10EN(x)                 (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHEN_EICH10EN_SHIFT)) & EIM_1_EICHEN_EICH10EN_MASK)

#define EIM_1_EICHEN_EICH4EN_MASK                (0x8000000U)
#define EIM_1_EICHEN_EICH4EN_SHIFT               (27U)
#define EIM_1_EICHEN_EICH4EN_WIDTH               (1U)
#define EIM_1_EICHEN_EICH4EN(x)                  (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHEN_EICH4EN_SHIFT)) & EIM_1_EICHEN_EICH4EN_MASK)

#define EIM_1_EICHEN_EICH3EN_MASK                (0x10000000U)
#define EIM_1_EICHEN_EICH3EN_SHIFT               (28U)
#define EIM_1_EICHEN_EICH3EN_WIDTH               (1U)
#define EIM_1_EICHEN_EICH3EN(x)                  (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHEN_EICH3EN_SHIFT)) & EIM_1_EICHEN_EICH3EN_MASK)

#define EIM_1_EICHEN_EICH2EN_MASK                (0x20000000U)
#define EIM_1_EICHEN_EICH2EN_SHIFT               (29U)
#define EIM_1_EICHEN_EICH2EN_WIDTH               (1U)
#define EIM_1_EICHEN_EICH2EN(x)                  (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHEN_EICH2EN_SHIFT)) & EIM_1_EICHEN_EICH2EN_MASK)

#define EIM_1_EICHEN_EICH1EN_MASK                (0x40000000U)
#define EIM_1_EICHEN_EICH1EN_SHIFT               (30U)
#define EIM_1_EICHEN_EICH1EN_WIDTH               (1U)
#define EIM_1_EICHEN_EICH1EN(x)                  (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHEN_EICH1EN_SHIFT)) & EIM_1_EICHEN_EICH1EN_MASK)

#define EIM_1_EICHEN_EICH0EN_MASK                (0x80000000U)
#define EIM_1_EICHEN_EICH0EN_SHIFT               (31U)
#define EIM_1_EICHEN_EICH0EN_WIDTH               (1U)
#define EIM_1_EICHEN_EICH0EN(x)                  (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHEN_EICH0EN_SHIFT)) & EIM_1_EICHEN_EICH0EN_MASK)
/*! @} */

/*! @name EICHD0_WORD0 - Error Injection Channel Descriptor 0, Word0 */
/*! @{ */

#define EIM_1_EICHD0_WORD0_CHKBIT_MASK_MASK      (0xFFFC0000U)
#define EIM_1_EICHD0_WORD0_CHKBIT_MASK_SHIFT     (18U)
#define EIM_1_EICHD0_WORD0_CHKBIT_MASK_WIDTH     (14U)
#define EIM_1_EICHD0_WORD0_CHKBIT_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD0_WORD0_CHKBIT_MASK_SHIFT)) & EIM_1_EICHD0_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD0_WORD1 - Error Injection Channel Descriptor 0, Word1 */
/*! @{ */

#define EIM_1_EICHD0_WORD1_B0_3DATA_MASK_MASK    (0xFFFU)
#define EIM_1_EICHD0_WORD1_B0_3DATA_MASK_SHIFT   (0U)
#define EIM_1_EICHD0_WORD1_B0_3DATA_MASK_WIDTH   (12U)
#define EIM_1_EICHD0_WORD1_B0_3DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD0_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_1_EICHD0_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD0_WORD2 - Error Injection Channel Descriptor 0, Word2 */
/*! @{ */

#define EIM_1_EICHD0_WORD2_B4_7DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_1_EICHD0_WORD2_B4_7DATA_MASK_SHIFT   (0U)
#define EIM_1_EICHD0_WORD2_B4_7DATA_MASK_WIDTH   (32U)
#define EIM_1_EICHD0_WORD2_B4_7DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD0_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_1_EICHD0_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD0 - Error Injection Channel Descriptor 1, Word0 */
/*! @{ */

#define EIM_1_EICHD1_WORD0_CHKBIT_MASK_MASK      (0xFFFF0000U)
#define EIM_1_EICHD1_WORD0_CHKBIT_MASK_SHIFT     (16U)
#define EIM_1_EICHD1_WORD0_CHKBIT_MASK_WIDTH     (16U)
#define EIM_1_EICHD1_WORD0_CHKBIT_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD1_WORD0_CHKBIT_MASK_SHIFT)) & EIM_1_EICHD1_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD1 - Error Injection Channel Descriptor 1, Word1 */
/*! @{ */

#define EIM_1_EICHD1_WORD1_B0_3DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_1_EICHD1_WORD1_B0_3DATA_MASK_SHIFT   (0U)
#define EIM_1_EICHD1_WORD1_B0_3DATA_MASK_WIDTH   (32U)
#define EIM_1_EICHD1_WORD1_B0_3DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD1_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_1_EICHD1_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD2 - Error Injection Channel Descriptor 1, Word2 */
/*! @{ */

#define EIM_1_EICHD1_WORD2_B4_7DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_1_EICHD1_WORD2_B4_7DATA_MASK_SHIFT   (0U)
#define EIM_1_EICHD1_WORD2_B4_7DATA_MASK_WIDTH   (32U)
#define EIM_1_EICHD1_WORD2_B4_7DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD1_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_1_EICHD1_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD3 - Error Injection Channel Descriptor 1, Word3 */
/*! @{ */

#define EIM_1_EICHD1_WORD3_B8_11DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_1_EICHD1_WORD3_B8_11DATA_MASK_SHIFT  (0U)
#define EIM_1_EICHD1_WORD3_B8_11DATA_MASK_WIDTH  (32U)
#define EIM_1_EICHD1_WORD3_B8_11DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD1_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_1_EICHD1_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD4 - Error Injection Channel Descriptor 1, Word4 */
/*! @{ */

#define EIM_1_EICHD1_WORD4_B12_15DATA_MASK_MASK  (0xFFFFFFFFU)
#define EIM_1_EICHD1_WORD4_B12_15DATA_MASK_SHIFT (0U)
#define EIM_1_EICHD1_WORD4_B12_15DATA_MASK_WIDTH (32U)
#define EIM_1_EICHD1_WORD4_B12_15DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD1_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_1_EICHD1_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD0 - Error Injection Channel Descriptor 2, Word0 */
/*! @{ */

#define EIM_1_EICHD2_WORD0_CHKBIT_MASK_MASK      (0xFFFFFFF0U)
#define EIM_1_EICHD2_WORD0_CHKBIT_MASK_SHIFT     (4U)
#define EIM_1_EICHD2_WORD0_CHKBIT_MASK_WIDTH     (28U)
#define EIM_1_EICHD2_WORD0_CHKBIT_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD2_WORD0_CHKBIT_MASK_SHIFT)) & EIM_1_EICHD2_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD1 - Error Injection Channel Descriptor 2, Word1 */
/*! @{ */

#define EIM_1_EICHD2_WORD1_B0_3DATA_MASK_MASK    (0xFFU)
#define EIM_1_EICHD2_WORD1_B0_3DATA_MASK_SHIFT   (0U)
#define EIM_1_EICHD2_WORD1_B0_3DATA_MASK_WIDTH   (8U)
#define EIM_1_EICHD2_WORD1_B0_3DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD2_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_1_EICHD2_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD2 - Error Injection Channel Descriptor 2, Word2 */
/*! @{ */

#define EIM_1_EICHD2_WORD2_B4_7DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_1_EICHD2_WORD2_B4_7DATA_MASK_SHIFT   (0U)
#define EIM_1_EICHD2_WORD2_B4_7DATA_MASK_WIDTH   (32U)
#define EIM_1_EICHD2_WORD2_B4_7DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD2_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_1_EICHD2_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD3 - Error Injection Channel Descriptor 2, Word3 */
/*! @{ */

#define EIM_1_EICHD2_WORD3_B8_11DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_1_EICHD2_WORD3_B8_11DATA_MASK_SHIFT  (0U)
#define EIM_1_EICHD2_WORD3_B8_11DATA_MASK_WIDTH  (32U)
#define EIM_1_EICHD2_WORD3_B8_11DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD2_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_1_EICHD2_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD4 - Error Injection Channel Descriptor 2, Word4 */
/*! @{ */

#define EIM_1_EICHD2_WORD4_B12_15DATA_MASK_MASK  (0xFFFFFFFFU)
#define EIM_1_EICHD2_WORD4_B12_15DATA_MASK_SHIFT (0U)
#define EIM_1_EICHD2_WORD4_B12_15DATA_MASK_WIDTH (32U)
#define EIM_1_EICHD2_WORD4_B12_15DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD2_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_1_EICHD2_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD0 - Error Injection Channel Descriptor 3, Word0 */
/*! @{ */

#define EIM_1_EICHD3_WORD0_CHKBIT_MASK_MASK      (0xFFFFFFF0U)
#define EIM_1_EICHD3_WORD0_CHKBIT_MASK_SHIFT     (4U)
#define EIM_1_EICHD3_WORD0_CHKBIT_MASK_WIDTH     (28U)
#define EIM_1_EICHD3_WORD0_CHKBIT_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD3_WORD0_CHKBIT_MASK_SHIFT)) & EIM_1_EICHD3_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD1 - Error Injection Channel Descriptor 3, Word1 */
/*! @{ */

#define EIM_1_EICHD3_WORD1_B0_3DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_1_EICHD3_WORD1_B0_3DATA_MASK_SHIFT   (0U)
#define EIM_1_EICHD3_WORD1_B0_3DATA_MASK_WIDTH   (32U)
#define EIM_1_EICHD3_WORD1_B0_3DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD3_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_1_EICHD3_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD2 - Error Injection Channel Descriptor 3, Word2 */
/*! @{ */

#define EIM_1_EICHD3_WORD2_B4_7DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_1_EICHD3_WORD2_B4_7DATA_MASK_SHIFT   (0U)
#define EIM_1_EICHD3_WORD2_B4_7DATA_MASK_WIDTH   (32U)
#define EIM_1_EICHD3_WORD2_B4_7DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD3_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_1_EICHD3_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD3 - Error Injection Channel Descriptor 3, Word3 */
/*! @{ */

#define EIM_1_EICHD3_WORD3_B8_11DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_1_EICHD3_WORD3_B8_11DATA_MASK_SHIFT  (0U)
#define EIM_1_EICHD3_WORD3_B8_11DATA_MASK_WIDTH  (32U)
#define EIM_1_EICHD3_WORD3_B8_11DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD3_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_1_EICHD3_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD4 - Error Injection Channel Descriptor 3, Word4 */
/*! @{ */

#define EIM_1_EICHD3_WORD4_B12_15DATA_MASK_MASK  (0xFFFFFFFFU)
#define EIM_1_EICHD3_WORD4_B12_15DATA_MASK_SHIFT (0U)
#define EIM_1_EICHD3_WORD4_B12_15DATA_MASK_WIDTH (32U)
#define EIM_1_EICHD3_WORD4_B12_15DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD3_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_1_EICHD3_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD0 - Error Injection Channel Descriptor 4, Word0 */
/*! @{ */

#define EIM_1_EICHD4_WORD0_CHKBIT_MASK_MASK      (0xFFFFFFF0U)
#define EIM_1_EICHD4_WORD0_CHKBIT_MASK_SHIFT     (4U)
#define EIM_1_EICHD4_WORD0_CHKBIT_MASK_WIDTH     (28U)
#define EIM_1_EICHD4_WORD0_CHKBIT_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD4_WORD0_CHKBIT_MASK_SHIFT)) & EIM_1_EICHD4_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD1 - Error Injection Channel Descriptor 4, Word1 */
/*! @{ */

#define EIM_1_EICHD4_WORD1_B0_3DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_1_EICHD4_WORD1_B0_3DATA_MASK_SHIFT   (0U)
#define EIM_1_EICHD4_WORD1_B0_3DATA_MASK_WIDTH   (32U)
#define EIM_1_EICHD4_WORD1_B0_3DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD4_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_1_EICHD4_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD2 - Error Injection Channel Descriptor 4, Word2 */
/*! @{ */

#define EIM_1_EICHD4_WORD2_B4_7DATA_MASK_MASK    (0xFFFFFFFFU)
#define EIM_1_EICHD4_WORD2_B4_7DATA_MASK_SHIFT   (0U)
#define EIM_1_EICHD4_WORD2_B4_7DATA_MASK_WIDTH   (32U)
#define EIM_1_EICHD4_WORD2_B4_7DATA_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD4_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_1_EICHD4_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD3 - Error Injection Channel Descriptor 4, Word3 */
/*! @{ */

#define EIM_1_EICHD4_WORD3_B8_11DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_1_EICHD4_WORD3_B8_11DATA_MASK_SHIFT  (0U)
#define EIM_1_EICHD4_WORD3_B8_11DATA_MASK_WIDTH  (32U)
#define EIM_1_EICHD4_WORD3_B8_11DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD4_WORD3_B8_11DATA_MASK_SHIFT)) & EIM_1_EICHD4_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD4 - Error Injection Channel Descriptor 4, Word4 */
/*! @{ */

#define EIM_1_EICHD4_WORD4_B12_15DATA_MASK_MASK  (0xFFFFFFFFU)
#define EIM_1_EICHD4_WORD4_B12_15DATA_MASK_SHIFT (0U)
#define EIM_1_EICHD4_WORD4_B12_15DATA_MASK_WIDTH (32U)
#define EIM_1_EICHD4_WORD4_B12_15DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD4_WORD4_B12_15DATA_MASK_SHIFT)) & EIM_1_EICHD4_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD10_WORD0 - Error Injection Channel Descriptor 10, Word0 */
/*! @{ */

#define EIM_1_EICHD10_WORD0_CHKBIT_MASK_MASK     (0xFF000000U)
#define EIM_1_EICHD10_WORD0_CHKBIT_MASK_SHIFT    (24U)
#define EIM_1_EICHD10_WORD0_CHKBIT_MASK_WIDTH    (8U)
#define EIM_1_EICHD10_WORD0_CHKBIT_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD10_WORD0_CHKBIT_MASK_SHIFT)) & EIM_1_EICHD10_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD10_WORD1 - Error Injection Channel Descriptor 10, Word1 */
/*! @{ */

#define EIM_1_EICHD10_WORD1_B0_3DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_1_EICHD10_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_1_EICHD10_WORD1_B0_3DATA_MASK_WIDTH  (32U)
#define EIM_1_EICHD10_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD10_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_1_EICHD10_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD10_WORD2 - Error Injection Channel Descriptor 10, Word2 */
/*! @{ */

#define EIM_1_EICHD10_WORD2_B4_7DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_1_EICHD10_WORD2_B4_7DATA_MASK_SHIFT  (0U)
#define EIM_1_EICHD10_WORD2_B4_7DATA_MASK_WIDTH  (32U)
#define EIM_1_EICHD10_WORD2_B4_7DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD10_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_1_EICHD10_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD11_WORD0 - Error Injection Channel Descriptor 11, Word0 */
/*! @{ */

#define EIM_1_EICHD11_WORD0_CHKBIT_MASK_MASK     (0xFF000000U)
#define EIM_1_EICHD11_WORD0_CHKBIT_MASK_SHIFT    (24U)
#define EIM_1_EICHD11_WORD0_CHKBIT_MASK_WIDTH    (8U)
#define EIM_1_EICHD11_WORD0_CHKBIT_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD11_WORD0_CHKBIT_MASK_SHIFT)) & EIM_1_EICHD11_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD11_WORD1 - Error Injection Channel Descriptor 11, Word1 */
/*! @{ */

#define EIM_1_EICHD11_WORD1_B0_3DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_1_EICHD11_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_1_EICHD11_WORD1_B0_3DATA_MASK_WIDTH  (32U)
#define EIM_1_EICHD11_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD11_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_1_EICHD11_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD12_WORD0 - Error Injection Channel Descriptor 12, Word0 */
/*! @{ */

#define EIM_1_EICHD12_WORD0_CHKBIT_MASK_MASK     (0xFF000000U)
#define EIM_1_EICHD12_WORD0_CHKBIT_MASK_SHIFT    (24U)
#define EIM_1_EICHD12_WORD0_CHKBIT_MASK_WIDTH    (8U)
#define EIM_1_EICHD12_WORD0_CHKBIT_MASK(x)       (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD12_WORD0_CHKBIT_MASK_SHIFT)) & EIM_1_EICHD12_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD12_WORD1 - Error Injection Channel Descriptor 12, Word1 */
/*! @{ */

#define EIM_1_EICHD12_WORD1_B0_3DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_1_EICHD12_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_1_EICHD12_WORD1_B0_3DATA_MASK_WIDTH  (32U)
#define EIM_1_EICHD12_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD12_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_1_EICHD12_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD16_WORD1 - Error Injection Channel Descriptor 16, Word1 */
/*! @{ */

#define EIM_1_EICHD16_WORD1_B0_3DATA_MASK_MASK   (0x3FFFFFFFU)
#define EIM_1_EICHD16_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_1_EICHD16_WORD1_B0_3DATA_MASK_WIDTH  (30U)
#define EIM_1_EICHD16_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD16_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_1_EICHD16_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD17_WORD1 - Error Injection Channel Descriptor 17, Word1 */
/*! @{ */

#define EIM_1_EICHD17_WORD1_B0_3DATA_MASK_MASK   (0xFFFFFFFU)
#define EIM_1_EICHD17_WORD1_B0_3DATA_MASK_SHIFT  (0U)
#define EIM_1_EICHD17_WORD1_B0_3DATA_MASK_WIDTH  (28U)
#define EIM_1_EICHD17_WORD1_B0_3DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD17_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_1_EICHD17_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD17_WORD2 - Error Injection Channel Descriptor 17, Word2 */
/*! @{ */

#define EIM_1_EICHD17_WORD2_B4_7DATA_MASK_MASK   (0xFFFFFFFFU)
#define EIM_1_EICHD17_WORD2_B4_7DATA_MASK_SHIFT  (0U)
#define EIM_1_EICHD17_WORD2_B4_7DATA_MASK_WIDTH  (32U)
#define EIM_1_EICHD17_WORD2_B4_7DATA_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_1_EICHD17_WORD2_B4_7DATA_MASK_SHIFT)) & EIM_1_EICHD17_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group EIM_1_Register_Masks */

/*!
 * @}
 */ /* end of group EIM_1_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K39_EIM_1_H_) */
