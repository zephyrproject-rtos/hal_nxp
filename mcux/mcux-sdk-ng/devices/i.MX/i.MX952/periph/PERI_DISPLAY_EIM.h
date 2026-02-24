/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DISPLAY_EIM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DISPLAY_EIM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DISPLAY_EIM
 *
 * CMSIS Peripheral Access Layer for DISPLAY_EIM
 */

#if !defined(PERI_DISPLAY_EIM_H_)
#define PERI_DISPLAY_EIM_H_                      /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- DISPLAY_EIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_EIM_Peripheral_Access_Layer DISPLAY_EIM Peripheral Access Layer
 * @{
 */

/** DISPLAY_EIM - Register Layout Typedef */
typedef struct {
  __IO uint32_t EIMCR;                             /**< Error Injection Module Configuration Register, offset: 0x0 */
  __IO uint32_t EICHEN;                            /**< Error Injection Channel Enable register, offset: 0x4 */
       uint8_t RESERVED_0[312];
  __IO uint32_t EICHD1_WORD0;                      /**< Error Injection Channel Descriptor 1, Word0, offset: 0x140 */
  __IO uint32_t EICHD1_WORD1;                      /**< Error Injection Channel Descriptor 1, Word1, offset: 0x144 */
       uint8_t RESERVED_1[56];
  __IO uint32_t EICHD2_WORD0;                      /**< Error Injection Channel Descriptor 2, Word0, offset: 0x180 */
  __IO uint32_t EICHD2_WORD1;                      /**< Error Injection Channel Descriptor 2, Word1, offset: 0x184 */
  __IO uint32_t EICHD2_WORD2;                      /**< Error Injection Channel Descriptor 2, Word2, offset: 0x188 */
  __IO uint32_t EICHD2_WORD3;                      /**< Error Injection Channel Descriptor 2, Word3, offset: 0x18C */
  __IO uint32_t EICHD2_WORD4;                      /**< Error Injection Channel Descriptor 2, Word4, offset: 0x190 */
  __IO uint32_t EICHD2_WORD5;                      /**< Error Injection Channel Descriptor 2, Word5, offset: 0x194 */
       uint8_t RESERVED_2[40];
  __IO uint32_t EICHD3_WORD0;                      /**< Error Injection Channel Descriptor 3, Word0, offset: 0x1C0 */
  __IO uint32_t EICHD3_WORD1;                      /**< Error Injection Channel Descriptor 3, Word1, offset: 0x1C4 */
  __IO uint32_t EICHD3_WORD2;                      /**< Error Injection Channel Descriptor 3, Word2, offset: 0x1C8 */
  __IO uint32_t EICHD3_WORD3;                      /**< Error Injection Channel Descriptor 3, Word3, offset: 0x1CC */
  __IO uint32_t EICHD3_WORD4;                      /**< Error Injection Channel Descriptor 3, Word4, offset: 0x1D0 */
  __IO uint32_t EICHD3_WORD5;                      /**< Error Injection Channel Descriptor 3, Word5, offset: 0x1D4 */
  __IO uint32_t EICHD3_WORD6;                      /**< Error Injection Channel Descriptor 3, Word6, offset: 0x1D8 */
  __IO uint32_t EICHD3_WORD7;                      /**< Error Injection Channel Descriptor 3, Word7, offset: 0x1DC */
       uint8_t RESERVED_3[32];
  __IO uint32_t EICHD4_WORD0;                      /**< Error Injection Channel Descriptor 4, Word0, offset: 0x200 */
  __IO uint32_t EICHD4_WORD1;                      /**< Error Injection Channel Descriptor 4, Word1, offset: 0x204 */
       uint8_t RESERVED_4[56];
  __IO uint32_t EICHD5_WORD0;                      /**< Error Injection Channel Descriptor 5, Word0, offset: 0x240 */
  __IO uint32_t EICHD5_WORD1;                      /**< Error Injection Channel Descriptor 5, Word1, offset: 0x244 */
       uint8_t RESERVED_5[56];
  __IO uint32_t EICHD6_WORD0;                      /**< Error Injection Channel Descriptor 6, Word0, offset: 0x280 */
  __IO uint32_t EICHD6_WORD1;                      /**< Error Injection Channel Descriptor 6, Word1, offset: 0x284 */
  __IO uint32_t EICHD6_WORD2;                      /**< Error Injection Channel Descriptor 6, Word2, offset: 0x288 */
  __IO uint32_t EICHD6_WORD3;                      /**< Error Injection Channel Descriptor 6, Word3, offset: 0x28C */
  __IO uint32_t EICHD6_WORD4;                      /**< Error Injection Channel Descriptor 6, Word4, offset: 0x290 */
  __IO uint32_t EICHD6_WORD5;                      /**< Error Injection Channel Descriptor 6, Word5, offset: 0x294 */
       uint8_t RESERVED_6[40];
  __IO uint32_t EICHD7_WORD0;                      /**< Error Injection Channel Descriptor 7, Word0, offset: 0x2C0 */
  __IO uint32_t EICHD7_WORD1;                      /**< Error Injection Channel Descriptor 7, Word1, offset: 0x2C4 */
  __IO uint32_t EICHD7_WORD2;                      /**< Error Injection Channel Descriptor 7, Word2, offset: 0x2C8 */
  __IO uint32_t EICHD7_WORD3;                      /**< Error Injection Channel Descriptor 7, Word3, offset: 0x2CC */
  __IO uint32_t EICHD7_WORD4;                      /**< Error Injection Channel Descriptor 7, Word4, offset: 0x2D0 */
  __IO uint32_t EICHD7_WORD5;                      /**< Error Injection Channel Descriptor 7, Word5, offset: 0x2D4 */
  __IO uint32_t EICHD7_WORD6;                      /**< Error Injection Channel Descriptor 7, Word6, offset: 0x2D8 */
  __IO uint32_t EICHD7_WORD7;                      /**< Error Injection Channel Descriptor 7, Word7, offset: 0x2DC */
} DISPLAY_EIM_Type;

/* ----------------------------------------------------------------------------
   -- DISPLAY_EIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_EIM_Register_Masks DISPLAY_EIM Register Masks
 * @{
 */

/*! @name EIMCR - Error Injection Module Configuration Register */
/*! @{ */

#define DISPLAY_EIM_EIMCR_GEIEN_MASK             (0x1U)
#define DISPLAY_EIM_EIMCR_GEIEN_SHIFT            (0U)
/*! GEIEN - Global Error Injection Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define DISPLAY_EIM_EIMCR_GEIEN(x)               (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EIMCR_GEIEN_SHIFT)) & DISPLAY_EIM_EIMCR_GEIEN_MASK)
/*! @} */

/*! @name EICHEN - Error Injection Channel Enable register */
/*! @{ */

#define DISPLAY_EIM_EICHEN_EICH7EN_MASK          (0x1000000U)
#define DISPLAY_EIM_EICHEN_EICH7EN_SHIFT         (24U)
/*! EICH7EN - Error Injection Channel 7 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 7
 *  0b1..Error injection is enabled on Error Injection Channel 7
 */
#define DISPLAY_EIM_EICHEN_EICH7EN(x)            (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHEN_EICH7EN_SHIFT)) & DISPLAY_EIM_EICHEN_EICH7EN_MASK)

#define DISPLAY_EIM_EICHEN_EICH6EN_MASK          (0x2000000U)
#define DISPLAY_EIM_EICHEN_EICH6EN_SHIFT         (25U)
/*! EICH6EN - Error Injection Channel 6 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 6
 *  0b1..Error injection is enabled on Error Injection Channel 6
 */
#define DISPLAY_EIM_EICHEN_EICH6EN(x)            (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHEN_EICH6EN_SHIFT)) & DISPLAY_EIM_EICHEN_EICH6EN_MASK)

#define DISPLAY_EIM_EICHEN_EICH5EN_MASK          (0x4000000U)
#define DISPLAY_EIM_EICHEN_EICH5EN_SHIFT         (26U)
/*! EICH5EN - Error Injection Channel 5 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 5
 *  0b1..Error injection is enabled on Error Injection Channel 5
 */
#define DISPLAY_EIM_EICHEN_EICH5EN(x)            (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHEN_EICH5EN_SHIFT)) & DISPLAY_EIM_EICHEN_EICH5EN_MASK)

#define DISPLAY_EIM_EICHEN_EICH4EN_MASK          (0x8000000U)
#define DISPLAY_EIM_EICHEN_EICH4EN_SHIFT         (27U)
/*! EICH4EN - Error Injection Channel 4 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 4
 *  0b1..Error injection is enabled on Error Injection Channel 4
 */
#define DISPLAY_EIM_EICHEN_EICH4EN(x)            (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHEN_EICH4EN_SHIFT)) & DISPLAY_EIM_EICHEN_EICH4EN_MASK)

#define DISPLAY_EIM_EICHEN_EICH3EN_MASK          (0x10000000U)
#define DISPLAY_EIM_EICHEN_EICH3EN_SHIFT         (28U)
/*! EICH3EN - Error Injection Channel 3 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 3
 *  0b1..Error injection is enabled on Error Injection Channel 3
 */
#define DISPLAY_EIM_EICHEN_EICH3EN(x)            (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHEN_EICH3EN_SHIFT)) & DISPLAY_EIM_EICHEN_EICH3EN_MASK)

#define DISPLAY_EIM_EICHEN_EICH2EN_MASK          (0x20000000U)
#define DISPLAY_EIM_EICHEN_EICH2EN_SHIFT         (29U)
/*! EICH2EN - Error Injection Channel 2 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 2
 *  0b1..Error injection is enabled on Error Injection Channel 2
 */
#define DISPLAY_EIM_EICHEN_EICH2EN(x)            (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHEN_EICH2EN_SHIFT)) & DISPLAY_EIM_EICHEN_EICH2EN_MASK)

#define DISPLAY_EIM_EICHEN_EICH1EN_MASK          (0x40000000U)
#define DISPLAY_EIM_EICHEN_EICH1EN_SHIFT         (30U)
/*! EICH1EN - Error Injection Channel 1 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 1
 *  0b1..Error injection is enabled on Error Injection Channel 1
 */
#define DISPLAY_EIM_EICHEN_EICH1EN(x)            (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHEN_EICH1EN_SHIFT)) & DISPLAY_EIM_EICHEN_EICH1EN_MASK)
/*! @} */

/*! @name EICHD1_WORD0 - Error Injection Channel Descriptor 1, Word0 */
/*! @{ */

#define DISPLAY_EIM_EICHD1_WORD0_CHKBIT_MASK_MASK (0xFF000000U)
#define DISPLAY_EIM_EICHD1_WORD0_CHKBIT_MASK_SHIFT (24U)
/*! CHKBIT_MASK - Checkbit Mask */
#define DISPLAY_EIM_EICHD1_WORD0_CHKBIT_MASK(x)  (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD1_WORD0_CHKBIT_MASK_SHIFT)) & DISPLAY_EIM_EICHD1_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD1 - Error Injection Channel Descriptor 1, Word1 */
/*! @{ */

#define DISPLAY_EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD1_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD1_WORD1_B0_3DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD1_WORD1_B0_3DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD0 - Error Injection Channel Descriptor 2, Word0 */
/*! @{ */

#define DISPLAY_EIM_EICHD2_WORD0_CHKBIT_MASK_MASK (0xFFFFFF00U)
#define DISPLAY_EIM_EICHD2_WORD0_CHKBIT_MASK_SHIFT (8U)
/*! CHKBIT_MASK - Checkbit Mask */
#define DISPLAY_EIM_EICHD2_WORD0_CHKBIT_MASK(x)  (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD2_WORD0_CHKBIT_MASK_SHIFT)) & DISPLAY_EIM_EICHD2_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD1 - Error Injection Channel Descriptor 2, Word1 */
/*! @{ */

#define DISPLAY_EIM_EICHD2_WORD1_B0_3DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD2_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD2_WORD1_B0_3DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD2_WORD1_B0_3DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD2_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD2 - Error Injection Channel Descriptor 2, Word2 */
/*! @{ */

#define DISPLAY_EIM_EICHD2_WORD2_B4_7DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD2_WORD2_B4_7DATA_MASK_SHIFT (0U)
/*! B4_7DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD2_WORD2_B4_7DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD2_WORD2_B4_7DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD2_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD3 - Error Injection Channel Descriptor 2, Word3 */
/*! @{ */

#define DISPLAY_EIM_EICHD2_WORD3_B8_11DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD2_WORD3_B8_11DATA_MASK_SHIFT (0U)
/*! B8_11DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD2_WORD3_B8_11DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD2_WORD3_B8_11DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD2_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD4 - Error Injection Channel Descriptor 2, Word4 */
/*! @{ */

#define DISPLAY_EIM_EICHD2_WORD4_B12_15DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD2_WORD4_B12_15DATA_MASK_SHIFT (0U)
/*! B12_15DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD2_WORD4_B12_15DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD2_WORD4_B12_15DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD2_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD5 - Error Injection Channel Descriptor 2, Word5 */
/*! @{ */

#define DISPLAY_EIM_EICHD2_WORD5_B16_19DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD2_WORD5_B16_19DATA_MASK_SHIFT (0U)
/*! B16_19DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD2_WORD5_B16_19DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD2_WORD5_B16_19DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD2_WORD5_B16_19DATA_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD0 - Error Injection Channel Descriptor 3, Word0 */
/*! @{ */

#define DISPLAY_EIM_EICHD3_WORD0_CHKBIT_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD3_WORD0_CHKBIT_MASK_SHIFT (0U)
/*! CHKBIT_MASK - Checkbit Mask */
#define DISPLAY_EIM_EICHD3_WORD0_CHKBIT_MASK(x)  (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD3_WORD0_CHKBIT_MASK_SHIFT)) & DISPLAY_EIM_EICHD3_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD1 - Error Injection Channel Descriptor 3, Word1 */
/*! @{ */

#define DISPLAY_EIM_EICHD3_WORD1_B0_3DATA_MASK_MASK (0xFFU)
#define DISPLAY_EIM_EICHD3_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD3_WORD1_B0_3DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD3_WORD1_B0_3DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD3_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD2 - Error Injection Channel Descriptor 3, Word2 */
/*! @{ */

#define DISPLAY_EIM_EICHD3_WORD2_B4_7DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD3_WORD2_B4_7DATA_MASK_SHIFT (0U)
/*! B4_7DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD3_WORD2_B4_7DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD3_WORD2_B4_7DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD3_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD3 - Error Injection Channel Descriptor 3, Word3 */
/*! @{ */

#define DISPLAY_EIM_EICHD3_WORD3_B8_11DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD3_WORD3_B8_11DATA_MASK_SHIFT (0U)
/*! B8_11DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD3_WORD3_B8_11DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD3_WORD3_B8_11DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD3_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD4 - Error Injection Channel Descriptor 3, Word4 */
/*! @{ */

#define DISPLAY_EIM_EICHD3_WORD4_B12_15DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD3_WORD4_B12_15DATA_MASK_SHIFT (0U)
/*! B12_15DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD3_WORD4_B12_15DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD3_WORD4_B12_15DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD3_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD5 - Error Injection Channel Descriptor 3, Word5 */
/*! @{ */

#define DISPLAY_EIM_EICHD3_WORD5_B16_19DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD3_WORD5_B16_19DATA_MASK_SHIFT (0U)
/*! B16_19DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD3_WORD5_B16_19DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD3_WORD5_B16_19DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD3_WORD5_B16_19DATA_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD6 - Error Injection Channel Descriptor 3, Word6 */
/*! @{ */

#define DISPLAY_EIM_EICHD3_WORD6_B20_23DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD3_WORD6_B20_23DATA_MASK_SHIFT (0U)
/*! B20_23DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD3_WORD6_B20_23DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD3_WORD6_B20_23DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD3_WORD6_B20_23DATA_MASK_MASK)
/*! @} */

/*! @name EICHD3_WORD7 - Error Injection Channel Descriptor 3, Word7 */
/*! @{ */

#define DISPLAY_EIM_EICHD3_WORD7_B24_27DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD3_WORD7_B24_27DATA_MASK_SHIFT (0U)
/*! B24_27DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD3_WORD7_B24_27DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD3_WORD7_B24_27DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD3_WORD7_B24_27DATA_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD0 - Error Injection Channel Descriptor 4, Word0 */
/*! @{ */

#define DISPLAY_EIM_EICHD4_WORD0_CHKBIT_MASK_MASK (0xFF000000U)
#define DISPLAY_EIM_EICHD4_WORD0_CHKBIT_MASK_SHIFT (24U)
/*! CHKBIT_MASK - Checkbit Mask */
#define DISPLAY_EIM_EICHD4_WORD0_CHKBIT_MASK(x)  (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD4_WORD0_CHKBIT_MASK_SHIFT)) & DISPLAY_EIM_EICHD4_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD1 - Error Injection Channel Descriptor 4, Word1 */
/*! @{ */

#define DISPLAY_EIM_EICHD4_WORD1_B0_3DATA_MASK_MASK (0x1U)
#define DISPLAY_EIM_EICHD4_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD4_WORD1_B0_3DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD4_WORD1_B0_3DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD4_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD5_WORD0 - Error Injection Channel Descriptor 5, Word0 */
/*! @{ */

#define DISPLAY_EIM_EICHD5_WORD0_CHKBIT_MASK_MASK (0xFF000000U)
#define DISPLAY_EIM_EICHD5_WORD0_CHKBIT_MASK_SHIFT (24U)
/*! CHKBIT_MASK - Checkbit Mask */
#define DISPLAY_EIM_EICHD5_WORD0_CHKBIT_MASK(x)  (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD5_WORD0_CHKBIT_MASK_SHIFT)) & DISPLAY_EIM_EICHD5_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD5_WORD1 - Error Injection Channel Descriptor 5, Word1 */
/*! @{ */

#define DISPLAY_EIM_EICHD5_WORD1_B0_3DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD5_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD5_WORD1_B0_3DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD5_WORD1_B0_3DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD5_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD0 - Error Injection Channel Descriptor 6, Word0 */
/*! @{ */

#define DISPLAY_EIM_EICHD6_WORD0_CHKBIT_MASK_MASK (0xFFFFFF00U)
#define DISPLAY_EIM_EICHD6_WORD0_CHKBIT_MASK_SHIFT (8U)
/*! CHKBIT_MASK - Checkbit Mask */
#define DISPLAY_EIM_EICHD6_WORD0_CHKBIT_MASK(x)  (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD6_WORD0_CHKBIT_MASK_SHIFT)) & DISPLAY_EIM_EICHD6_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD1 - Error Injection Channel Descriptor 6, Word1 */
/*! @{ */

#define DISPLAY_EIM_EICHD6_WORD1_B0_3DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD6_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD6_WORD1_B0_3DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD6_WORD1_B0_3DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD6_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD2 - Error Injection Channel Descriptor 6, Word2 */
/*! @{ */

#define DISPLAY_EIM_EICHD6_WORD2_B4_7DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD6_WORD2_B4_7DATA_MASK_SHIFT (0U)
/*! B4_7DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD6_WORD2_B4_7DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD6_WORD2_B4_7DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD6_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD3 - Error Injection Channel Descriptor 6, Word3 */
/*! @{ */

#define DISPLAY_EIM_EICHD6_WORD3_B8_11DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD6_WORD3_B8_11DATA_MASK_SHIFT (0U)
/*! B8_11DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD6_WORD3_B8_11DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD6_WORD3_B8_11DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD6_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD4 - Error Injection Channel Descriptor 6, Word4 */
/*! @{ */

#define DISPLAY_EIM_EICHD6_WORD4_B12_15DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD6_WORD4_B12_15DATA_MASK_SHIFT (0U)
/*! B12_15DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD6_WORD4_B12_15DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD6_WORD4_B12_15DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD6_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD5 - Error Injection Channel Descriptor 6, Word5 */
/*! @{ */

#define DISPLAY_EIM_EICHD6_WORD5_B16_19DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD6_WORD5_B16_19DATA_MASK_SHIFT (0U)
/*! B16_19DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD6_WORD5_B16_19DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD6_WORD5_B16_19DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD6_WORD5_B16_19DATA_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD0 - Error Injection Channel Descriptor 7, Word0 */
/*! @{ */

#define DISPLAY_EIM_EICHD7_WORD0_CHKBIT_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD7_WORD0_CHKBIT_MASK_SHIFT (0U)
/*! CHKBIT_MASK - Checkbit Mask */
#define DISPLAY_EIM_EICHD7_WORD0_CHKBIT_MASK(x)  (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD7_WORD0_CHKBIT_MASK_SHIFT)) & DISPLAY_EIM_EICHD7_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD1 - Error Injection Channel Descriptor 7, Word1 */
/*! @{ */

#define DISPLAY_EIM_EICHD7_WORD1_B0_3DATA_MASK_MASK (0xFFU)
#define DISPLAY_EIM_EICHD7_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD7_WORD1_B0_3DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD7_WORD1_B0_3DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD7_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD2 - Error Injection Channel Descriptor 7, Word2 */
/*! @{ */

#define DISPLAY_EIM_EICHD7_WORD2_B4_7DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD7_WORD2_B4_7DATA_MASK_SHIFT (0U)
/*! B4_7DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD7_WORD2_B4_7DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD7_WORD2_B4_7DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD7_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD3 - Error Injection Channel Descriptor 7, Word3 */
/*! @{ */

#define DISPLAY_EIM_EICHD7_WORD3_B8_11DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD7_WORD3_B8_11DATA_MASK_SHIFT (0U)
/*! B8_11DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD7_WORD3_B8_11DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD7_WORD3_B8_11DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD7_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD4 - Error Injection Channel Descriptor 7, Word4 */
/*! @{ */

#define DISPLAY_EIM_EICHD7_WORD4_B12_15DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD7_WORD4_B12_15DATA_MASK_SHIFT (0U)
/*! B12_15DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD7_WORD4_B12_15DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD7_WORD4_B12_15DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD7_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD5 - Error Injection Channel Descriptor 7, Word5 */
/*! @{ */

#define DISPLAY_EIM_EICHD7_WORD5_B16_19DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD7_WORD5_B16_19DATA_MASK_SHIFT (0U)
/*! B16_19DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD7_WORD5_B16_19DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD7_WORD5_B16_19DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD7_WORD5_B16_19DATA_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD6 - Error Injection Channel Descriptor 7, Word6 */
/*! @{ */

#define DISPLAY_EIM_EICHD7_WORD6_B20_23DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD7_WORD6_B20_23DATA_MASK_SHIFT (0U)
/*! B20_23DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD7_WORD6_B20_23DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD7_WORD6_B20_23DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD7_WORD6_B20_23DATA_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD7 - Error Injection Channel Descriptor 7, Word7 */
/*! @{ */

#define DISPLAY_EIM_EICHD7_WORD7_B24_27DATA_MASK_MASK (0xFFFFFFFFU)
#define DISPLAY_EIM_EICHD7_WORD7_B24_27DATA_MASK_SHIFT (0U)
/*! B24_27DATA_MASK - Data Mask Field */
#define DISPLAY_EIM_EICHD7_WORD7_B24_27DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_EIM_EICHD7_WORD7_B24_27DATA_MASK_SHIFT)) & DISPLAY_EIM_EICHD7_WORD7_B24_27DATA_MASK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DISPLAY_EIM_Register_Masks */


/*!
 * @}
 */ /* end of group DISPLAY_EIM_Peripheral_Access_Layer */


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


#endif  /* PERI_DISPLAY_EIM_H_ */

