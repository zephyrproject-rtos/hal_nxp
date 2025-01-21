/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AON_EIM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file AON_EIM.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for AON_EIM
 *
 * CMSIS Peripheral Access Layer for AON_EIM
 */

#if !defined(AON_EIM_H_)
#define AON_EIM_H_                               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- AON_EIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AON_EIM_Peripheral_Access_Layer AON_EIM Peripheral Access Layer
 * @{
 */

/** AON_EIM - Register Layout Typedef */
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
       uint8_t RESERVED_2[52];
  __IO uint32_t EICHD2_WORD0;                      /**< Error Injection Channel Descriptor 2, Word0, offset: 0x180 */
  __IO uint32_t EICHD2_WORD1;                      /**< Error Injection Channel Descriptor 2, Word1, offset: 0x184 */
  __IO uint32_t EICHD2_WORD2;                      /**< Error Injection Channel Descriptor 2, Word2, offset: 0x188 */
       uint8_t RESERVED_3[52];
  __IO uint32_t EICHD3_WORD0;                      /**< Error Injection Channel Descriptor 3, Word0, offset: 0x1C0 */
  __IO uint32_t EICHD3_WORD1;                      /**< Error Injection Channel Descriptor 3, Word1, offset: 0x1C4 */
  __IO uint32_t EICHD3_WORD2;                      /**< Error Injection Channel Descriptor 3, Word2, offset: 0x1C8 */
       uint8_t RESERVED_4[52];
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
       uint8_t RESERVED_12[56];
  __IO uint32_t EICHD12_WORD0;                     /**< Error Injection Channel Descriptor 12, Word0, offset: 0x400 */
  __IO uint32_t EICHD12_WORD1;                     /**< Error Injection Channel Descriptor 12, Word1, offset: 0x404 */
} AON_EIM_Type;

/* ----------------------------------------------------------------------------
   -- AON_EIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AON_EIM_Register_Masks AON_EIM Register Masks
 * @{
 */

/*! @name EIMCR - Error Injection Module Configuration Register */
/*! @{ */

#define AON_EIM_EIMCR_GEIEN_MASK                 (0x1U)
#define AON_EIM_EIMCR_GEIEN_SHIFT                (0U)
/*! GEIEN - Global Error Injection Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define AON_EIM_EIMCR_GEIEN(x)                   (((uint32_t)(((uint32_t)(x)) << AON_EIM_EIMCR_GEIEN_SHIFT)) & AON_EIM_EIMCR_GEIEN_MASK)
/*! @} */

/*! @name EICHEN - Error Injection Channel Enable register */
/*! @{ */

#define AON_EIM_EICHEN_EICH12EN_MASK             (0x80000U)
#define AON_EIM_EICHEN_EICH12EN_SHIFT            (19U)
/*! EICH12EN - Error Injection Channel 12 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 12
 *  0b1..Error injection is enabled on Error Injection Channel 12
 */
#define AON_EIM_EICHEN_EICH12EN(x)               (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHEN_EICH12EN_SHIFT)) & AON_EIM_EICHEN_EICH12EN_MASK)

#define AON_EIM_EICHEN_EICH11EN_MASK             (0x100000U)
#define AON_EIM_EICHEN_EICH11EN_SHIFT            (20U)
/*! EICH11EN - Error Injection Channel 11 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 11
 *  0b1..Error injection is enabled on Error Injection Channel 11
 */
#define AON_EIM_EICHEN_EICH11EN(x)               (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHEN_EICH11EN_SHIFT)) & AON_EIM_EICHEN_EICH11EN_MASK)

#define AON_EIM_EICHEN_EICH10EN_MASK             (0x200000U)
#define AON_EIM_EICHEN_EICH10EN_SHIFT            (21U)
/*! EICH10EN - Error Injection Channel 10 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 10
 *  0b1..Error injection is enabled on Error Injection Channel 10
 */
#define AON_EIM_EICHEN_EICH10EN(x)               (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHEN_EICH10EN_SHIFT)) & AON_EIM_EICHEN_EICH10EN_MASK)

#define AON_EIM_EICHEN_EICH9EN_MASK              (0x400000U)
#define AON_EIM_EICHEN_EICH9EN_SHIFT             (22U)
/*! EICH9EN - Error Injection Channel 9 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 9
 *  0b1..Error injection is enabled on Error Injection Channel 9
 */
#define AON_EIM_EICHEN_EICH9EN(x)                (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHEN_EICH9EN_SHIFT)) & AON_EIM_EICHEN_EICH9EN_MASK)

#define AON_EIM_EICHEN_EICH8EN_MASK              (0x800000U)
#define AON_EIM_EICHEN_EICH8EN_SHIFT             (23U)
/*! EICH8EN - Error Injection Channel 8 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 8
 *  0b1..Error injection is enabled on Error Injection Channel 8
 */
#define AON_EIM_EICHEN_EICH8EN(x)                (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHEN_EICH8EN_SHIFT)) & AON_EIM_EICHEN_EICH8EN_MASK)

#define AON_EIM_EICHEN_EICH7EN_MASK              (0x1000000U)
#define AON_EIM_EICHEN_EICH7EN_SHIFT             (24U)
/*! EICH7EN - Error Injection Channel 7 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 7
 *  0b1..Error injection is enabled on Error Injection Channel 7
 */
#define AON_EIM_EICHEN_EICH7EN(x)                (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHEN_EICH7EN_SHIFT)) & AON_EIM_EICHEN_EICH7EN_MASK)

#define AON_EIM_EICHEN_EICH6EN_MASK              (0x2000000U)
#define AON_EIM_EICHEN_EICH6EN_SHIFT             (25U)
/*! EICH6EN - Error Injection Channel 6 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 6
 *  0b1..Error injection is enabled on Error Injection Channel 6
 */
#define AON_EIM_EICHEN_EICH6EN(x)                (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHEN_EICH6EN_SHIFT)) & AON_EIM_EICHEN_EICH6EN_MASK)

#define AON_EIM_EICHEN_EICH5EN_MASK              (0x4000000U)
#define AON_EIM_EICHEN_EICH5EN_SHIFT             (26U)
/*! EICH5EN - Error Injection Channel 5 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 5
 *  0b1..Error injection is enabled on Error Injection Channel 5
 */
#define AON_EIM_EICHEN_EICH5EN(x)                (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHEN_EICH5EN_SHIFT)) & AON_EIM_EICHEN_EICH5EN_MASK)

#define AON_EIM_EICHEN_EICH4EN_MASK              (0x8000000U)
#define AON_EIM_EICHEN_EICH4EN_SHIFT             (27U)
/*! EICH4EN - Error Injection Channel 4 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 4
 *  0b1..Error injection is enabled on Error Injection Channel 4
 */
#define AON_EIM_EICHEN_EICH4EN(x)                (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHEN_EICH4EN_SHIFT)) & AON_EIM_EICHEN_EICH4EN_MASK)

#define AON_EIM_EICHEN_EICH3EN_MASK              (0x10000000U)
#define AON_EIM_EICHEN_EICH3EN_SHIFT             (28U)
/*! EICH3EN - Error Injection Channel 3 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 3
 *  0b1..Error injection is enabled on Error Injection Channel 3
 */
#define AON_EIM_EICHEN_EICH3EN(x)                (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHEN_EICH3EN_SHIFT)) & AON_EIM_EICHEN_EICH3EN_MASK)

#define AON_EIM_EICHEN_EICH2EN_MASK              (0x20000000U)
#define AON_EIM_EICHEN_EICH2EN_SHIFT             (29U)
/*! EICH2EN - Error Injection Channel 2 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 2
 *  0b1..Error injection is enabled on Error Injection Channel 2
 */
#define AON_EIM_EICHEN_EICH2EN(x)                (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHEN_EICH2EN_SHIFT)) & AON_EIM_EICHEN_EICH2EN_MASK)

#define AON_EIM_EICHEN_EICH1EN_MASK              (0x40000000U)
#define AON_EIM_EICHEN_EICH1EN_SHIFT             (30U)
/*! EICH1EN - Error Injection Channel 1 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 1
 *  0b1..Error injection is enabled on Error Injection Channel 1
 */
#define AON_EIM_EICHEN_EICH1EN(x)                (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHEN_EICH1EN_SHIFT)) & AON_EIM_EICHEN_EICH1EN_MASK)

#define AON_EIM_EICHEN_EICH0EN_MASK              (0x80000000U)
#define AON_EIM_EICHEN_EICH0EN_SHIFT             (31U)
/*! EICH0EN - Error Injection Channel 0 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 0
 *  0b1..Error injection is enabled on Error Injection Channel 0
 */
#define AON_EIM_EICHEN_EICH0EN(x)                (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHEN_EICH0EN_SHIFT)) & AON_EIM_EICHEN_EICH0EN_MASK)
/*! @} */

/*! @name EICHD0_WORD0 - Error Injection Channel Descriptor 0, Word0 */
/*! @{ */

#define AON_EIM_EICHD0_WORD0_CHKBIT_MASK_MASK    (0xFF000000U)
#define AON_EIM_EICHD0_WORD0_CHKBIT_MASK_SHIFT   (24U)
/*! CHKBIT_MASK - Checkbit Mask */
#define AON_EIM_EICHD0_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD0_WORD0_CHKBIT_MASK_SHIFT)) & AON_EIM_EICHD0_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD0_WORD1 - Error Injection Channel Descriptor 0, Word1 */
/*! @{ */

#define AON_EIM_EICHD0_WORD1_B0_3DATA_MASK_MASK  (0xFU)
#define AON_EIM_EICHD0_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define AON_EIM_EICHD0_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD0_WORD1_B0_3DATA_MASK_SHIFT)) & AON_EIM_EICHD0_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD0_WORD2 - Error Injection Channel Descriptor 0, Word2 */
/*! @{ */

#define AON_EIM_EICHD0_WORD2_B4_7DATA_MASK_MASK  (0xFFFFFFFFU)
#define AON_EIM_EICHD0_WORD2_B4_7DATA_MASK_SHIFT (0U)
/*! B4_7DATA_MASK - Data Mask Bytes 4-7 */
#define AON_EIM_EICHD0_WORD2_B4_7DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD0_WORD2_B4_7DATA_MASK_SHIFT)) & AON_EIM_EICHD0_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD0 - Error Injection Channel Descriptor 1, Word0 */
/*! @{ */

#define AON_EIM_EICHD1_WORD0_CHKBIT_MASK_MASK    (0xFF000000U)
#define AON_EIM_EICHD1_WORD0_CHKBIT_MASK_SHIFT   (24U)
/*! CHKBIT_MASK - Checkbit Mask */
#define AON_EIM_EICHD1_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD1_WORD0_CHKBIT_MASK_SHIFT)) & AON_EIM_EICHD1_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD1 - Error Injection Channel Descriptor 1, Word1 */
/*! @{ */

#define AON_EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK  (0xFU)
#define AON_EIM_EICHD1_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define AON_EIM_EICHD1_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD1_WORD1_B0_3DATA_MASK_SHIFT)) & AON_EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD2 - Error Injection Channel Descriptor 1, Word2 */
/*! @{ */

#define AON_EIM_EICHD1_WORD2_B4_7DATA_MASK_MASK  (0xFFFFFFFFU)
#define AON_EIM_EICHD1_WORD2_B4_7DATA_MASK_SHIFT (0U)
/*! B4_7DATA_MASK - Data Mask Bytes 4-7 */
#define AON_EIM_EICHD1_WORD2_B4_7DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD1_WORD2_B4_7DATA_MASK_SHIFT)) & AON_EIM_EICHD1_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD0 - Error Injection Channel Descriptor 2, Word0 */
/*! @{ */

#define AON_EIM_EICHD2_WORD0_CHKBIT_MASK_MASK    (0xFF000000U)
#define AON_EIM_EICHD2_WORD0_CHKBIT_MASK_SHIFT   (24U)
/*! CHKBIT_MASK - Checkbit Mask */
#define AON_EIM_EICHD2_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD2_WORD0_CHKBIT_MASK_SHIFT)) & AON_EIM_EICHD2_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD1 - Error Injection Channel Descriptor 2, Word1 */
/*! @{ */

#define AON_EIM_EICHD2_WORD1_B0_3DATA_MASK_MASK  (0xFU)
#define AON_EIM_EICHD2_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define AON_EIM_EICHD2_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD2_WORD1_B0_3DATA_MASK_SHIFT)) & AON_EIM_EICHD2_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD2 - Error Injection Channel Descriptor 2, Word2 */
/*! @{ */

#define AON_EIM_EICHD2_WORD2_B4_7DATA_MASK_MASK  (0xFFFFFFFFU)
#define AON_EIM_EICHD2_WORD2_B4_7DATA_MASK_SHIFT (0U)
/*! B4_7DATA_MASK - Data Mask Bytes 4-7 */
#define AON_EIM_EICHD2_WORD2_B4_7DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD2_WORD2_B4_7DATA_MASK_SHIFT)) & AON_EIM_EICHD2_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD0 - Error Injection Channel Descriptor 3, Word0 */
/*! @{ */

#define AON_EIM_EICHD3_WORD0_CHKBIT_MASK_MASK    (0xFF000000U)
#define AON_EIM_EICHD3_WORD0_CHKBIT_MASK_SHIFT   (24U)
/*! CHKBIT_MASK - Checkbit Mask */
#define AON_EIM_EICHD3_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD3_WORD0_CHKBIT_MASK_SHIFT)) & AON_EIM_EICHD3_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD1 - Error Injection Channel Descriptor 3, Word1 */
/*! @{ */

#define AON_EIM_EICHD3_WORD1_B0_3DATA_MASK_MASK  (0xFU)
#define AON_EIM_EICHD3_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define AON_EIM_EICHD3_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD3_WORD1_B0_3DATA_MASK_SHIFT)) & AON_EIM_EICHD3_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD2 - Error Injection Channel Descriptor 3, Word2 */
/*! @{ */

#define AON_EIM_EICHD3_WORD2_B4_7DATA_MASK_MASK  (0xFFFFFFFFU)
#define AON_EIM_EICHD3_WORD2_B4_7DATA_MASK_SHIFT (0U)
/*! B4_7DATA_MASK - Data Mask Bytes 4-7 */
#define AON_EIM_EICHD3_WORD2_B4_7DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD3_WORD2_B4_7DATA_MASK_SHIFT)) & AON_EIM_EICHD3_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD0 - Error Injection Channel Descriptor 4, Word0 */
/*! @{ */

#define AON_EIM_EICHD4_WORD0_CHKBIT_MASK_MASK    (0xFE000000U)
#define AON_EIM_EICHD4_WORD0_CHKBIT_MASK_SHIFT   (25U)
/*! CHKBIT_MASK - Checkbit Mask */
#define AON_EIM_EICHD4_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD4_WORD0_CHKBIT_MASK_SHIFT)) & AON_EIM_EICHD4_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD1 - Error Injection Channel Descriptor 4, Word1 */
/*! @{ */

#define AON_EIM_EICHD4_WORD1_B0_3DATA_MASK_MASK  (0xFFFFFFFFU)
#define AON_EIM_EICHD4_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define AON_EIM_EICHD4_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD4_WORD1_B0_3DATA_MASK_SHIFT)) & AON_EIM_EICHD4_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD5_WORD0 - Error Injection Channel Descriptor 5, Word0 */
/*! @{ */

#define AON_EIM_EICHD5_WORD0_CHKBIT_MASK_MASK    (0xFE000000U)
#define AON_EIM_EICHD5_WORD0_CHKBIT_MASK_SHIFT   (25U)
/*! CHKBIT_MASK - Checkbit Mask */
#define AON_EIM_EICHD5_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD5_WORD0_CHKBIT_MASK_SHIFT)) & AON_EIM_EICHD5_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD5_WORD1 - Error Injection Channel Descriptor 5, Word1 */
/*! @{ */

#define AON_EIM_EICHD5_WORD1_B0_3DATA_MASK_MASK  (0xFFFFFFFFU)
#define AON_EIM_EICHD5_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define AON_EIM_EICHD5_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD5_WORD1_B0_3DATA_MASK_SHIFT)) & AON_EIM_EICHD5_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD0 - Error Injection Channel Descriptor 6, Word0 */
/*! @{ */

#define AON_EIM_EICHD6_WORD0_CHKBIT_MASK_MASK    (0xFE000000U)
#define AON_EIM_EICHD6_WORD0_CHKBIT_MASK_SHIFT   (25U)
/*! CHKBIT_MASK - Checkbit Mask */
#define AON_EIM_EICHD6_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD6_WORD0_CHKBIT_MASK_SHIFT)) & AON_EIM_EICHD6_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD1 - Error Injection Channel Descriptor 6, Word1 */
/*! @{ */

#define AON_EIM_EICHD6_WORD1_B0_3DATA_MASK_MASK  (0xFFFFFFFFU)
#define AON_EIM_EICHD6_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define AON_EIM_EICHD6_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD6_WORD1_B0_3DATA_MASK_SHIFT)) & AON_EIM_EICHD6_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD0 - Error Injection Channel Descriptor 7, Word0 */
/*! @{ */

#define AON_EIM_EICHD7_WORD0_CHKBIT_MASK_MASK    (0xFE000000U)
#define AON_EIM_EICHD7_WORD0_CHKBIT_MASK_SHIFT   (25U)
/*! CHKBIT_MASK - Checkbit Mask */
#define AON_EIM_EICHD7_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD7_WORD0_CHKBIT_MASK_SHIFT)) & AON_EIM_EICHD7_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD1 - Error Injection Channel Descriptor 7, Word1 */
/*! @{ */

#define AON_EIM_EICHD7_WORD1_B0_3DATA_MASK_MASK  (0xFFFFFFFFU)
#define AON_EIM_EICHD7_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define AON_EIM_EICHD7_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD7_WORD1_B0_3DATA_MASK_SHIFT)) & AON_EIM_EICHD7_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD8_WORD0 - Error Injection Channel Descriptor 8, Word0 */
/*! @{ */

#define AON_EIM_EICHD8_WORD0_CHKBIT_MASK_MASK    (0xFE000000U)
#define AON_EIM_EICHD8_WORD0_CHKBIT_MASK_SHIFT   (25U)
/*! CHKBIT_MASK - Checkbit Mask */
#define AON_EIM_EICHD8_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD8_WORD0_CHKBIT_MASK_SHIFT)) & AON_EIM_EICHD8_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD8_WORD1 - Error Injection Channel Descriptor 8, Word1 */
/*! @{ */

#define AON_EIM_EICHD8_WORD1_B0_3DATA_MASK_MASK  (0xFFFFFFFFU)
#define AON_EIM_EICHD8_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define AON_EIM_EICHD8_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD8_WORD1_B0_3DATA_MASK_SHIFT)) & AON_EIM_EICHD8_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD9_WORD0 - Error Injection Channel Descriptor 9, Word0 */
/*! @{ */

#define AON_EIM_EICHD9_WORD0_CHKBIT_MASK_MASK    (0xFE000000U)
#define AON_EIM_EICHD9_WORD0_CHKBIT_MASK_SHIFT   (25U)
/*! CHKBIT_MASK - Checkbit Mask */
#define AON_EIM_EICHD9_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD9_WORD0_CHKBIT_MASK_SHIFT)) & AON_EIM_EICHD9_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD9_WORD1 - Error Injection Channel Descriptor 9, Word1 */
/*! @{ */

#define AON_EIM_EICHD9_WORD1_B0_3DATA_MASK_MASK  (0xFFFFFFFFU)
#define AON_EIM_EICHD9_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define AON_EIM_EICHD9_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD9_WORD1_B0_3DATA_MASK_SHIFT)) & AON_EIM_EICHD9_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD10_WORD0 - Error Injection Channel Descriptor 10, Word0 */
/*! @{ */

#define AON_EIM_EICHD10_WORD0_CHKBIT_MASK_MASK   (0xC0000000U)
#define AON_EIM_EICHD10_WORD0_CHKBIT_MASK_SHIFT  (30U)
/*! CHKBIT_MASK - Checkbit Mask */
#define AON_EIM_EICHD10_WORD0_CHKBIT_MASK(x)     (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD10_WORD0_CHKBIT_MASK_SHIFT)) & AON_EIM_EICHD10_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD10_WORD1 - Error Injection Channel Descriptor 10, Word1 */
/*! @{ */

#define AON_EIM_EICHD10_WORD1_B0_3DATA_MASK_MASK (0x1U)
#define AON_EIM_EICHD10_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define AON_EIM_EICHD10_WORD1_B0_3DATA_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD10_WORD1_B0_3DATA_MASK_SHIFT)) & AON_EIM_EICHD10_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD11_WORD0 - Error Injection Channel Descriptor 11, Word0 */
/*! @{ */

#define AON_EIM_EICHD11_WORD0_CHKBIT_MASK_MASK   (0xF8000000U)
#define AON_EIM_EICHD11_WORD0_CHKBIT_MASK_SHIFT  (27U)
/*! CHKBIT_MASK - Checkbit Mask */
#define AON_EIM_EICHD11_WORD0_CHKBIT_MASK(x)     (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD11_WORD0_CHKBIT_MASK_SHIFT)) & AON_EIM_EICHD11_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD11_WORD1 - Error Injection Channel Descriptor 11, Word1 */
/*! @{ */

#define AON_EIM_EICHD11_WORD1_B0_3DATA_MASK_MASK (0x1U)
#define AON_EIM_EICHD11_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define AON_EIM_EICHD11_WORD1_B0_3DATA_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD11_WORD1_B0_3DATA_MASK_SHIFT)) & AON_EIM_EICHD11_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD12_WORD0 - Error Injection Channel Descriptor 12, Word0 */
/*! @{ */

#define AON_EIM_EICHD12_WORD0_CHKBIT_MASK_MASK   (0xFE000000U)
#define AON_EIM_EICHD12_WORD0_CHKBIT_MASK_SHIFT  (25U)
/*! CHKBIT_MASK - Checkbit Mask */
#define AON_EIM_EICHD12_WORD0_CHKBIT_MASK(x)     (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD12_WORD0_CHKBIT_MASK_SHIFT)) & AON_EIM_EICHD12_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD12_WORD1 - Error Injection Channel Descriptor 12, Word1 */
/*! @{ */

#define AON_EIM_EICHD12_WORD1_B0_3DATA_MASK_MASK (0x1U)
#define AON_EIM_EICHD12_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define AON_EIM_EICHD12_WORD1_B0_3DATA_MASK(x)   (((uint32_t)(((uint32_t)(x)) << AON_EIM_EICHD12_WORD1_B0_3DATA_MASK_SHIFT)) & AON_EIM_EICHD12_WORD1_B0_3DATA_MASK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AON_EIM_Register_Masks */


/*!
 * @}
 */ /* end of group AON_EIM_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* AON_EIM_H_ */

