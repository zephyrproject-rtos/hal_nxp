/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_EIM_GTM.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_EIM_GTM
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
#if !defined(S32Z2_EIM_GTM_H_)  /* Check if memory map has not been already included */
#define S32Z2_EIM_GTM_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- EIM_GTM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EIM_GTM_Peripheral_Access_Layer EIM_GTM Peripheral Access Layer
 * @{
 */

/** EIM_GTM - Register Layout Typedef */
typedef struct {
  __IO uint32_t EIMCR;                             /**< Error Injection Module Configuration Register, offset: 0x0 */
  __IO uint32_t EICHEN;                            /**< Error Injection Channel Enable register, offset: 0x4 */
  uint8_t RESERVED_0[248];
  __IO uint32_t EICHD0_WORD0;                      /**< Error Injection Channel Descriptor 0, Word0, offset: 0x100 */
  __IO uint32_t EICHD0_WORD1;                      /**< Error Injection Channel Descriptor 0, Word1, offset: 0x104 */
  uint8_t RESERVED_1[56];
  __IO uint32_t EICHD1_WORD0;                      /**< Error Injection Channel Descriptor 1, Word0, offset: 0x140 */
  __IO uint32_t EICHD1_WORD1;                      /**< Error Injection Channel Descriptor 1, Word1, offset: 0x144 */
  uint8_t RESERVED_2[56];
  __IO uint32_t EICHD2_WORD0;                      /**< Error Injection Channel Descriptor 2, Word0, offset: 0x180 */
  __IO uint32_t EICHD2_WORD1;                      /**< Error Injection Channel Descriptor 2, Word1, offset: 0x184 */
  uint8_t RESERVED_3[56];
  __IO uint32_t EICHD3_WORD0;                      /**< Error Injection Channel Descriptor 3, Word0, offset: 0x1C0 */
  __IO uint32_t EICHD3_WORD1;                      /**< Error Injection Channel Descriptor 3, Word1, offset: 0x1C4 */
  uint8_t RESERVED_4[56];
  __IO uint32_t EICHD4_WORD0;                      /**< Error Injection Channel Descriptor 4, Word0, offset: 0x200 */
  __IO uint32_t EICHD4_WORD1;                      /**< Error Injection Channel Descriptor 4, Word1, offset: 0x204 */
  uint8_t RESERVED_5[56];
  __IO uint32_t EICHD5_WORD0;                      /**< Error Injection Channel Descriptor 5, Word0, offset: 0x240 */
  __IO uint32_t EICHD5_WORD1;                      /**< Error Injection Channel Descriptor 5, Word1, offset: 0x244 */
  uint8_t RESERVED_6[56];
  __IO uint32_t EICHD6_WORD0;                      /**< Error Injection Channel Descriptor 6, Word0, offset: 0x280 */
  __IO uint32_t EICHD6_WORD1;                      /**< Error Injection Channel Descriptor 6, Word1, offset: 0x284 */
  uint8_t RESERVED_7[56];
  __IO uint32_t EICHD7_WORD0;                      /**< Error Injection Channel Descriptor 7, Word0, offset: 0x2C0 */
  __IO uint32_t EICHD7_WORD1;                      /**< Error Injection Channel Descriptor 7, Word1, offset: 0x2C4 */
  uint8_t RESERVED_8[56];
  __IO uint32_t EICHD8_WORD0;                      /**< Error Injection Channel Descriptor 8, Word0, offset: 0x300 */
  __IO uint32_t EICHD8_WORD1;                      /**< Error Injection Channel Descriptor 8, Word1, offset: 0x304 */
  uint8_t RESERVED_9[56];
  __IO uint32_t EICHD9_WORD0;                      /**< Error Injection Channel Descriptor 9, Word0, offset: 0x340 */
  __IO uint32_t EICHD9_WORD1;                      /**< Error Injection Channel Descriptor 9, Word1, offset: 0x344 */
  uint8_t RESERVED_10[56];
  __IO uint32_t EICHD10_WORD0;                     /**< Error Injection Channel Descriptor 10, Word0, offset: 0x380 */
  __IO uint32_t EICHD10_WORD1;                     /**< Error Injection Channel Descriptor 10, Word1, offset: 0x384 */
  uint8_t RESERVED_11[56];
  __IO uint32_t EICHD11_WORD0;                     /**< Error Injection Channel Descriptor 11, Word0, offset: 0x3C0 */
  __IO uint32_t EICHD11_WORD1;                     /**< Error Injection Channel Descriptor 11, Word1, offset: 0x3C4 */
} EIM_GTM_Type, *EIM_GTM_MemMapPtr;

/** Number of instances of the EIM_GTM module. */
#define EIM_GTM_INSTANCE_COUNT                   (1u)

/* EIM_GTM - Peripheral instance base addresses */
/** Peripheral EIM_GTM base address */
#define IP_EIM_GTM_BASE                          (0x40378000u)
/** Peripheral EIM_GTM base pointer */
#define IP_EIM_GTM                               ((EIM_GTM_Type *)IP_EIM_GTM_BASE)
/** Array initializer of EIM_GTM peripheral base addresses */
#define IP_EIM_GTM_BASE_ADDRS                    { IP_EIM_GTM_BASE }
/** Array initializer of EIM_GTM peripheral base pointers */
#define IP_EIM_GTM_BASE_PTRS                     { IP_EIM_GTM }

/* ----------------------------------------------------------------------------
   -- EIM_GTM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EIM_GTM_Register_Masks EIM_GTM Register Masks
 * @{
 */

/*! @name EIMCR - Error Injection Module Configuration Register */
/*! @{ */

#define EIM_GTM_EIMCR_GEIEN_MASK                 (0x1U)
#define EIM_GTM_EIMCR_GEIEN_SHIFT                (0U)
#define EIM_GTM_EIMCR_GEIEN_WIDTH                (1U)
#define EIM_GTM_EIMCR_GEIEN(x)                   (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EIMCR_GEIEN_SHIFT)) & EIM_GTM_EIMCR_GEIEN_MASK)
/*! @} */

/*! @name EICHEN - Error Injection Channel Enable register */
/*! @{ */

#define EIM_GTM_EICHEN_EICH11EN_MASK             (0x100000U)
#define EIM_GTM_EICHEN_EICH11EN_SHIFT            (20U)
#define EIM_GTM_EICHEN_EICH11EN_WIDTH            (1U)
#define EIM_GTM_EICHEN_EICH11EN(x)               (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHEN_EICH11EN_SHIFT)) & EIM_GTM_EICHEN_EICH11EN_MASK)

#define EIM_GTM_EICHEN_EICH10EN_MASK             (0x200000U)
#define EIM_GTM_EICHEN_EICH10EN_SHIFT            (21U)
#define EIM_GTM_EICHEN_EICH10EN_WIDTH            (1U)
#define EIM_GTM_EICHEN_EICH10EN(x)               (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHEN_EICH10EN_SHIFT)) & EIM_GTM_EICHEN_EICH10EN_MASK)

#define EIM_GTM_EICHEN_EICH9EN_MASK              (0x400000U)
#define EIM_GTM_EICHEN_EICH9EN_SHIFT             (22U)
#define EIM_GTM_EICHEN_EICH9EN_WIDTH             (1U)
#define EIM_GTM_EICHEN_EICH9EN(x)                (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHEN_EICH9EN_SHIFT)) & EIM_GTM_EICHEN_EICH9EN_MASK)

#define EIM_GTM_EICHEN_EICH8EN_MASK              (0x800000U)
#define EIM_GTM_EICHEN_EICH8EN_SHIFT             (23U)
#define EIM_GTM_EICHEN_EICH8EN_WIDTH             (1U)
#define EIM_GTM_EICHEN_EICH8EN(x)                (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHEN_EICH8EN_SHIFT)) & EIM_GTM_EICHEN_EICH8EN_MASK)

#define EIM_GTM_EICHEN_EICH7EN_MASK              (0x1000000U)
#define EIM_GTM_EICHEN_EICH7EN_SHIFT             (24U)
#define EIM_GTM_EICHEN_EICH7EN_WIDTH             (1U)
#define EIM_GTM_EICHEN_EICH7EN(x)                (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHEN_EICH7EN_SHIFT)) & EIM_GTM_EICHEN_EICH7EN_MASK)

#define EIM_GTM_EICHEN_EICH6EN_MASK              (0x2000000U)
#define EIM_GTM_EICHEN_EICH6EN_SHIFT             (25U)
#define EIM_GTM_EICHEN_EICH6EN_WIDTH             (1U)
#define EIM_GTM_EICHEN_EICH6EN(x)                (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHEN_EICH6EN_SHIFT)) & EIM_GTM_EICHEN_EICH6EN_MASK)

#define EIM_GTM_EICHEN_EICH5EN_MASK              (0x4000000U)
#define EIM_GTM_EICHEN_EICH5EN_SHIFT             (26U)
#define EIM_GTM_EICHEN_EICH5EN_WIDTH             (1U)
#define EIM_GTM_EICHEN_EICH5EN(x)                (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHEN_EICH5EN_SHIFT)) & EIM_GTM_EICHEN_EICH5EN_MASK)

#define EIM_GTM_EICHEN_EICH4EN_MASK              (0x8000000U)
#define EIM_GTM_EICHEN_EICH4EN_SHIFT             (27U)
#define EIM_GTM_EICHEN_EICH4EN_WIDTH             (1U)
#define EIM_GTM_EICHEN_EICH4EN(x)                (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHEN_EICH4EN_SHIFT)) & EIM_GTM_EICHEN_EICH4EN_MASK)

#define EIM_GTM_EICHEN_EICH3EN_MASK              (0x10000000U)
#define EIM_GTM_EICHEN_EICH3EN_SHIFT             (28U)
#define EIM_GTM_EICHEN_EICH3EN_WIDTH             (1U)
#define EIM_GTM_EICHEN_EICH3EN(x)                (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHEN_EICH3EN_SHIFT)) & EIM_GTM_EICHEN_EICH3EN_MASK)

#define EIM_GTM_EICHEN_EICH2EN_MASK              (0x20000000U)
#define EIM_GTM_EICHEN_EICH2EN_SHIFT             (29U)
#define EIM_GTM_EICHEN_EICH2EN_WIDTH             (1U)
#define EIM_GTM_EICHEN_EICH2EN(x)                (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHEN_EICH2EN_SHIFT)) & EIM_GTM_EICHEN_EICH2EN_MASK)

#define EIM_GTM_EICHEN_EICH1EN_MASK              (0x40000000U)
#define EIM_GTM_EICHEN_EICH1EN_SHIFT             (30U)
#define EIM_GTM_EICHEN_EICH1EN_WIDTH             (1U)
#define EIM_GTM_EICHEN_EICH1EN(x)                (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHEN_EICH1EN_SHIFT)) & EIM_GTM_EICHEN_EICH1EN_MASK)

#define EIM_GTM_EICHEN_EICH0EN_MASK              (0x80000000U)
#define EIM_GTM_EICHEN_EICH0EN_SHIFT             (31U)
#define EIM_GTM_EICHEN_EICH0EN_WIDTH             (1U)
#define EIM_GTM_EICHEN_EICH0EN(x)                (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHEN_EICH0EN_SHIFT)) & EIM_GTM_EICHEN_EICH0EN_MASK)
/*! @} */

/*! @name EICHD0_WORD0 - Error Injection Channel Descriptor 0, Word0 */
/*! @{ */

#define EIM_GTM_EICHD0_WORD0_CHKBIT_MASK_MASK    (0xFF000000U)
#define EIM_GTM_EICHD0_WORD0_CHKBIT_MASK_SHIFT   (24U)
#define EIM_GTM_EICHD0_WORD0_CHKBIT_MASK_WIDTH   (8U)
#define EIM_GTM_EICHD0_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD0_WORD0_CHKBIT_MASK_SHIFT)) & EIM_GTM_EICHD0_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD0_WORD1 - Error Injection Channel Descriptor 0, Word1 */
/*! @{ */

#define EIM_GTM_EICHD0_WORD1_B0_3DATA_MASK_MASK  (0xFFFFFFFFU)
#define EIM_GTM_EICHD0_WORD1_B0_3DATA_MASK_SHIFT (0U)
#define EIM_GTM_EICHD0_WORD1_B0_3DATA_MASK_WIDTH (32U)
#define EIM_GTM_EICHD0_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD0_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_GTM_EICHD0_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD0 - Error Injection Channel Descriptor 1, Word0 */
/*! @{ */

#define EIM_GTM_EICHD1_WORD0_CHKBIT_MASK_MASK    (0xFF000000U)
#define EIM_GTM_EICHD1_WORD0_CHKBIT_MASK_SHIFT   (24U)
#define EIM_GTM_EICHD1_WORD0_CHKBIT_MASK_WIDTH   (8U)
#define EIM_GTM_EICHD1_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD1_WORD0_CHKBIT_MASK_SHIFT)) & EIM_GTM_EICHD1_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD1 - Error Injection Channel Descriptor 1, Word1 */
/*! @{ */

#define EIM_GTM_EICHD1_WORD1_B0_3DATA_MASK_MASK  (0xFFFFFFFFU)
#define EIM_GTM_EICHD1_WORD1_B0_3DATA_MASK_SHIFT (0U)
#define EIM_GTM_EICHD1_WORD1_B0_3DATA_MASK_WIDTH (32U)
#define EIM_GTM_EICHD1_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD1_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_GTM_EICHD1_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD0 - Error Injection Channel Descriptor 2, Word0 */
/*! @{ */

#define EIM_GTM_EICHD2_WORD0_CHKBIT_MASK_MASK    (0xFF000000U)
#define EIM_GTM_EICHD2_WORD0_CHKBIT_MASK_SHIFT   (24U)
#define EIM_GTM_EICHD2_WORD0_CHKBIT_MASK_WIDTH   (8U)
#define EIM_GTM_EICHD2_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD2_WORD0_CHKBIT_MASK_SHIFT)) & EIM_GTM_EICHD2_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD1 - Error Injection Channel Descriptor 2, Word1 */
/*! @{ */

#define EIM_GTM_EICHD2_WORD1_B0_3DATA_MASK_MASK  (0xFFFFFFU)
#define EIM_GTM_EICHD2_WORD1_B0_3DATA_MASK_SHIFT (0U)
#define EIM_GTM_EICHD2_WORD1_B0_3DATA_MASK_WIDTH (24U)
#define EIM_GTM_EICHD2_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD2_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_GTM_EICHD2_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD0 - Error Injection Channel Descriptor 3, Word0 */
/*! @{ */

#define EIM_GTM_EICHD3_WORD0_CHKBIT_MASK_MASK    (0xFF000000U)
#define EIM_GTM_EICHD3_WORD0_CHKBIT_MASK_SHIFT   (24U)
#define EIM_GTM_EICHD3_WORD0_CHKBIT_MASK_WIDTH   (8U)
#define EIM_GTM_EICHD3_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD3_WORD0_CHKBIT_MASK_SHIFT)) & EIM_GTM_EICHD3_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD1 - Error Injection Channel Descriptor 3, Word1 */
/*! @{ */

#define EIM_GTM_EICHD3_WORD1_B0_3DATA_MASK_MASK  (0xFFFFFFU)
#define EIM_GTM_EICHD3_WORD1_B0_3DATA_MASK_SHIFT (0U)
#define EIM_GTM_EICHD3_WORD1_B0_3DATA_MASK_WIDTH (24U)
#define EIM_GTM_EICHD3_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD3_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_GTM_EICHD3_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD0 - Error Injection Channel Descriptor 4, Word0 */
/*! @{ */

#define EIM_GTM_EICHD4_WORD0_CHKBIT_MASK_MASK    (0xFF000000U)
#define EIM_GTM_EICHD4_WORD0_CHKBIT_MASK_SHIFT   (24U)
#define EIM_GTM_EICHD4_WORD0_CHKBIT_MASK_WIDTH   (8U)
#define EIM_GTM_EICHD4_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD4_WORD0_CHKBIT_MASK_SHIFT)) & EIM_GTM_EICHD4_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD1 - Error Injection Channel Descriptor 4, Word1 */
/*! @{ */

#define EIM_GTM_EICHD4_WORD1_B0_3DATA_MASK_MASK  (0xFFFFFFU)
#define EIM_GTM_EICHD4_WORD1_B0_3DATA_MASK_SHIFT (0U)
#define EIM_GTM_EICHD4_WORD1_B0_3DATA_MASK_WIDTH (24U)
#define EIM_GTM_EICHD4_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD4_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_GTM_EICHD4_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD5_WORD0 - Error Injection Channel Descriptor 5, Word0 */
/*! @{ */

#define EIM_GTM_EICHD5_WORD0_CHKBIT_MASK_MASK    (0xFF000000U)
#define EIM_GTM_EICHD5_WORD0_CHKBIT_MASK_SHIFT   (24U)
#define EIM_GTM_EICHD5_WORD0_CHKBIT_MASK_WIDTH   (8U)
#define EIM_GTM_EICHD5_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD5_WORD0_CHKBIT_MASK_SHIFT)) & EIM_GTM_EICHD5_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD5_WORD1 - Error Injection Channel Descriptor 5, Word1 */
/*! @{ */

#define EIM_GTM_EICHD5_WORD1_B0_3DATA_MASK_MASK  (0x1FFFFFFFU)
#define EIM_GTM_EICHD5_WORD1_B0_3DATA_MASK_SHIFT (0U)
#define EIM_GTM_EICHD5_WORD1_B0_3DATA_MASK_WIDTH (29U)
#define EIM_GTM_EICHD5_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD5_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_GTM_EICHD5_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD0 - Error Injection Channel Descriptor 6, Word0 */
/*! @{ */

#define EIM_GTM_EICHD6_WORD0_CHKBIT_MASK_MASK    (0xFF000000U)
#define EIM_GTM_EICHD6_WORD0_CHKBIT_MASK_SHIFT   (24U)
#define EIM_GTM_EICHD6_WORD0_CHKBIT_MASK_WIDTH   (8U)
#define EIM_GTM_EICHD6_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD6_WORD0_CHKBIT_MASK_SHIFT)) & EIM_GTM_EICHD6_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD1 - Error Injection Channel Descriptor 6, Word1 */
/*! @{ */

#define EIM_GTM_EICHD6_WORD1_B0_3DATA_MASK_MASK  (0xFFFFFFFFU)
#define EIM_GTM_EICHD6_WORD1_B0_3DATA_MASK_SHIFT (0U)
#define EIM_GTM_EICHD6_WORD1_B0_3DATA_MASK_WIDTH (32U)
#define EIM_GTM_EICHD6_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD6_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_GTM_EICHD6_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD0 - Error Injection Channel Descriptor 7, Word0 */
/*! @{ */

#define EIM_GTM_EICHD7_WORD0_CHKBIT_MASK_MASK    (0xFF000000U)
#define EIM_GTM_EICHD7_WORD0_CHKBIT_MASK_SHIFT   (24U)
#define EIM_GTM_EICHD7_WORD0_CHKBIT_MASK_WIDTH   (8U)
#define EIM_GTM_EICHD7_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD7_WORD0_CHKBIT_MASK_SHIFT)) & EIM_GTM_EICHD7_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD1 - Error Injection Channel Descriptor 7, Word1 */
/*! @{ */

#define EIM_GTM_EICHD7_WORD1_B0_3DATA_MASK_MASK  (0xFFFFFFFFU)
#define EIM_GTM_EICHD7_WORD1_B0_3DATA_MASK_SHIFT (0U)
#define EIM_GTM_EICHD7_WORD1_B0_3DATA_MASK_WIDTH (32U)
#define EIM_GTM_EICHD7_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD7_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_GTM_EICHD7_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD8_WORD0 - Error Injection Channel Descriptor 8, Word0 */
/*! @{ */

#define EIM_GTM_EICHD8_WORD0_CHKBIT_MASK_MASK    (0xFF000000U)
#define EIM_GTM_EICHD8_WORD0_CHKBIT_MASK_SHIFT   (24U)
#define EIM_GTM_EICHD8_WORD0_CHKBIT_MASK_WIDTH   (8U)
#define EIM_GTM_EICHD8_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD8_WORD0_CHKBIT_MASK_SHIFT)) & EIM_GTM_EICHD8_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD8_WORD1 - Error Injection Channel Descriptor 8, Word1 */
/*! @{ */

#define EIM_GTM_EICHD8_WORD1_B0_3DATA_MASK_MASK  (0xFFFFFFFFU)
#define EIM_GTM_EICHD8_WORD1_B0_3DATA_MASK_SHIFT (0U)
#define EIM_GTM_EICHD8_WORD1_B0_3DATA_MASK_WIDTH (32U)
#define EIM_GTM_EICHD8_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD8_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_GTM_EICHD8_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD9_WORD0 - Error Injection Channel Descriptor 9, Word0 */
/*! @{ */

#define EIM_GTM_EICHD9_WORD0_CHKBIT_MASK_MASK    (0xFF000000U)
#define EIM_GTM_EICHD9_WORD0_CHKBIT_MASK_SHIFT   (24U)
#define EIM_GTM_EICHD9_WORD0_CHKBIT_MASK_WIDTH   (8U)
#define EIM_GTM_EICHD9_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD9_WORD0_CHKBIT_MASK_SHIFT)) & EIM_GTM_EICHD9_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD9_WORD1 - Error Injection Channel Descriptor 9, Word1 */
/*! @{ */

#define EIM_GTM_EICHD9_WORD1_B0_3DATA_MASK_MASK  (0xFFFFFFFFU)
#define EIM_GTM_EICHD9_WORD1_B0_3DATA_MASK_SHIFT (0U)
#define EIM_GTM_EICHD9_WORD1_B0_3DATA_MASK_WIDTH (32U)
#define EIM_GTM_EICHD9_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD9_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_GTM_EICHD9_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD10_WORD0 - Error Injection Channel Descriptor 10, Word0 */
/*! @{ */

#define EIM_GTM_EICHD10_WORD0_CHKBIT_MASK_MASK   (0xFF000000U)
#define EIM_GTM_EICHD10_WORD0_CHKBIT_MASK_SHIFT  (24U)
#define EIM_GTM_EICHD10_WORD0_CHKBIT_MASK_WIDTH  (8U)
#define EIM_GTM_EICHD10_WORD0_CHKBIT_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD10_WORD0_CHKBIT_MASK_SHIFT)) & EIM_GTM_EICHD10_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD10_WORD1 - Error Injection Channel Descriptor 10, Word1 */
/*! @{ */

#define EIM_GTM_EICHD10_WORD1_B0_3DATA_MASK_MASK (0xFFFFFFFFU)
#define EIM_GTM_EICHD10_WORD1_B0_3DATA_MASK_SHIFT (0U)
#define EIM_GTM_EICHD10_WORD1_B0_3DATA_MASK_WIDTH (32U)
#define EIM_GTM_EICHD10_WORD1_B0_3DATA_MASK(x)   (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD10_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_GTM_EICHD10_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD11_WORD0 - Error Injection Channel Descriptor 11, Word0 */
/*! @{ */

#define EIM_GTM_EICHD11_WORD0_CHKBIT_MASK_MASK   (0xFF000000U)
#define EIM_GTM_EICHD11_WORD0_CHKBIT_MASK_SHIFT  (24U)
#define EIM_GTM_EICHD11_WORD0_CHKBIT_MASK_WIDTH  (8U)
#define EIM_GTM_EICHD11_WORD0_CHKBIT_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD11_WORD0_CHKBIT_MASK_SHIFT)) & EIM_GTM_EICHD11_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD11_WORD1 - Error Injection Channel Descriptor 11, Word1 */
/*! @{ */

#define EIM_GTM_EICHD11_WORD1_B0_3DATA_MASK_MASK (0xFFFFFFFFU)
#define EIM_GTM_EICHD11_WORD1_B0_3DATA_MASK_SHIFT (0U)
#define EIM_GTM_EICHD11_WORD1_B0_3DATA_MASK_WIDTH (32U)
#define EIM_GTM_EICHD11_WORD1_B0_3DATA_MASK(x)   (((uint32_t)(((uint32_t)(x)) << EIM_GTM_EICHD11_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_GTM_EICHD11_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group EIM_GTM_Register_Masks */

/*!
 * @}
 */ /* end of group EIM_GTM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_EIM_GTM_H_) */
