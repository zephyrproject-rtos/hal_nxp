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
**         CMSIS Peripheral Access Layer for locald34
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
 * @file PERI_locald34.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald34
 *
 * CMSIS Peripheral Access Layer for locald34
 */

#if !defined(PERI_LOCALD34_H_)
#define PERI_LOCALD34_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald34 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald34_Peripheral_Access_Layer locald34 Peripheral Access Layer
 * @{
 */

/** locald34 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR0E0;                          /**< ldprofilereg0e0, offset: 0x0 */
  __IO uint32_t LDPRR0E1;                          /**< ldprofilereg0e1, offset: 0x4 */
  __IO uint32_t LDPRR0E2;                          /**< ldprofilereg0e2, offset: 0x8 */
  __IO uint32_t LDPRR0E3;                          /**< ldprofilereg0e3, offset: 0xC */
  __IO uint32_t LDPRR0E4;                          /**< ldprofilereg0e4, offset: 0x10 */
  __IO uint32_t LDPRR0E5;                          /**< ldprofilereg0e5, offset: 0x14 */
  __IO uint32_t LDPRR0E6;                          /**< ldprofilereg0e6, offset: 0x18 */
  __IO uint32_t LDPRR0E7;                          /**< ldprofilereg0e7, offset: 0x1C */
  __IO uint32_t LDPRR0E8;                          /**< ldprofilereg0e8, offset: 0x20 */
  __IO uint32_t LDPRR0E9;                          /**< ldprofilereg0e9, offset: 0x24 */
  __IO uint32_t LDPRR0EA;                          /**< ldprofilereg0ea, offset: 0x28 */
  __IO uint32_t LDPRR0EB;                          /**< ldprofilereg0eb, offset: 0x2C */
  __IO uint32_t LDPRR0EC;                          /**< ldprofilereg0ec, offset: 0x30 */
  __IO uint32_t LDPRR0ED;                          /**< ldprofilereg0ed, offset: 0x34 */
  __IO uint32_t LDPRR0EE;                          /**< ldprofilereg0ee, offset: 0x38 */
  __IO uint32_t LDPRR0EF;                          /**< ldprofilereg0ef, offset: 0x3C */
  __IO uint32_t LDPRR0F0;                          /**< ldprofilereg0f0, offset: 0x40 */
  __IO uint32_t LDPRR0F1;                          /**< ldprofilereg0f1, offset: 0x44 */
  __IO uint32_t LDPRR0F2;                          /**< ldprofilereg0f2, offset: 0x48 */
  __IO uint32_t LDPRR0F3;                          /**< ldprofilereg0f3, offset: 0x4C */
  __IO uint32_t LDPRR0F4;                          /**< ldprofilereg0f4, offset: 0x50 */
  __IO uint32_t LDPRR0F5;                          /**< ldprofilereg0f5, offset: 0x54 */
  __IO uint32_t LDPRR0F6;                          /**< ldprofilereg0f6, offset: 0x58 */
  __IO uint32_t LDPRR0F7;                          /**< ldprofilereg0f7, offset: 0x5C */
} locald34_Type;

/* ----------------------------------------------------------------------------
   -- locald34 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald34_Register_Masks locald34 Register Masks
 * @{
 */

/*! @name LDPRR0E0 - ldprofilereg0e0 */
/*! @{ */

#define locald34_LDPRR0E0_lumd337_MASK           (0x3FFU)
#define locald34_LDPRR0E0_lumd337_SHIFT          (0U)
/*! lumd337 - lumdat_337 */
#define locald34_LDPRR0E0_lumd337(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0E0_lumd337_SHIFT)) & locald34_LDPRR0E0_lumd337_MASK)

#define locald34_LDPRR0E0_lumd336_MASK           (0x3FF0000U)
#define locald34_LDPRR0E0_lumd336_SHIFT          (16U)
/*! lumd336 - lumdat_336 */
#define locald34_LDPRR0E0_lumd336(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0E0_lumd336_SHIFT)) & locald34_LDPRR0E0_lumd336_MASK)
/*! @} */

/*! @name LDPRR0E1 - ldprofilereg0e1 */
/*! @{ */

#define locald34_LDPRR0E1_lumd339_MASK           (0x3FFU)
#define locald34_LDPRR0E1_lumd339_SHIFT          (0U)
/*! lumd339 - lumdat_339 */
#define locald34_LDPRR0E1_lumd339(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0E1_lumd339_SHIFT)) & locald34_LDPRR0E1_lumd339_MASK)

#define locald34_LDPRR0E1_lumd338_MASK           (0x3FF0000U)
#define locald34_LDPRR0E1_lumd338_SHIFT          (16U)
/*! lumd338 - lumdat_338 */
#define locald34_LDPRR0E1_lumd338(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0E1_lumd338_SHIFT)) & locald34_LDPRR0E1_lumd338_MASK)
/*! @} */

/*! @name LDPRR0E2 - ldprofilereg0e2 */
/*! @{ */

#define locald34_LDPRR0E2_lumd341_MASK           (0x3FFU)
#define locald34_LDPRR0E2_lumd341_SHIFT          (0U)
/*! lumd341 - lumdat_341 */
#define locald34_LDPRR0E2_lumd341(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0E2_lumd341_SHIFT)) & locald34_LDPRR0E2_lumd341_MASK)

#define locald34_LDPRR0E2_lumd340_MASK           (0x3FF0000U)
#define locald34_LDPRR0E2_lumd340_SHIFT          (16U)
/*! lumd340 - lumdat_340 */
#define locald34_LDPRR0E2_lumd340(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0E2_lumd340_SHIFT)) & locald34_LDPRR0E2_lumd340_MASK)
/*! @} */

/*! @name LDPRR0E3 - ldprofilereg0e3 */
/*! @{ */

#define locald34_LDPRR0E3_lumd343_MASK           (0x3FFU)
#define locald34_LDPRR0E3_lumd343_SHIFT          (0U)
/*! lumd343 - lumdat_343 */
#define locald34_LDPRR0E3_lumd343(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0E3_lumd343_SHIFT)) & locald34_LDPRR0E3_lumd343_MASK)

#define locald34_LDPRR0E3_lumd342_MASK           (0x3FF0000U)
#define locald34_LDPRR0E3_lumd342_SHIFT          (16U)
/*! lumd342 - lumdat_342 */
#define locald34_LDPRR0E3_lumd342(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0E3_lumd342_SHIFT)) & locald34_LDPRR0E3_lumd342_MASK)
/*! @} */

/*! @name LDPRR0E4 - ldprofilereg0e4 */
/*! @{ */

#define locald34_LDPRR0E4_lumd345_MASK           (0x3FFU)
#define locald34_LDPRR0E4_lumd345_SHIFT          (0U)
/*! lumd345 - lumdat_345 */
#define locald34_LDPRR0E4_lumd345(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0E4_lumd345_SHIFT)) & locald34_LDPRR0E4_lumd345_MASK)

#define locald34_LDPRR0E4_lumd344_MASK           (0x3FF0000U)
#define locald34_LDPRR0E4_lumd344_SHIFT          (16U)
/*! lumd344 - lumdat_344 */
#define locald34_LDPRR0E4_lumd344(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0E4_lumd344_SHIFT)) & locald34_LDPRR0E4_lumd344_MASK)
/*! @} */

/*! @name LDPRR0E5 - ldprofilereg0e5 */
/*! @{ */

#define locald34_LDPRR0E5_lumd347_MASK           (0x3FFU)
#define locald34_LDPRR0E5_lumd347_SHIFT          (0U)
/*! lumd347 - lumdat_347 */
#define locald34_LDPRR0E5_lumd347(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0E5_lumd347_SHIFT)) & locald34_LDPRR0E5_lumd347_MASK)

#define locald34_LDPRR0E5_lumd346_MASK           (0x3FF0000U)
#define locald34_LDPRR0E5_lumd346_SHIFT          (16U)
/*! lumd346 - lumdat_346 */
#define locald34_LDPRR0E5_lumd346(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0E5_lumd346_SHIFT)) & locald34_LDPRR0E5_lumd346_MASK)
/*! @} */

/*! @name LDPRR0E6 - ldprofilereg0e6 */
/*! @{ */

#define locald34_LDPRR0E6_lumd349_MASK           (0x3FFU)
#define locald34_LDPRR0E6_lumd349_SHIFT          (0U)
/*! lumd349 - lumdat_349 */
#define locald34_LDPRR0E6_lumd349(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0E6_lumd349_SHIFT)) & locald34_LDPRR0E6_lumd349_MASK)

#define locald34_LDPRR0E6_lumd348_MASK           (0x3FF0000U)
#define locald34_LDPRR0E6_lumd348_SHIFT          (16U)
/*! lumd348 - lumdat_348 */
#define locald34_LDPRR0E6_lumd348(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0E6_lumd348_SHIFT)) & locald34_LDPRR0E6_lumd348_MASK)
/*! @} */

/*! @name LDPRR0E7 - ldprofilereg0e7 */
/*! @{ */

#define locald34_LDPRR0E7_lumd351_MASK           (0x3FFU)
#define locald34_LDPRR0E7_lumd351_SHIFT          (0U)
/*! lumd351 - lumdat_351 */
#define locald34_LDPRR0E7_lumd351(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0E7_lumd351_SHIFT)) & locald34_LDPRR0E7_lumd351_MASK)

#define locald34_LDPRR0E7_lumd350_MASK           (0x3FF0000U)
#define locald34_LDPRR0E7_lumd350_SHIFT          (16U)
/*! lumd350 - lumdat_350 */
#define locald34_LDPRR0E7_lumd350(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0E7_lumd350_SHIFT)) & locald34_LDPRR0E7_lumd350_MASK)
/*! @} */

/*! @name LDPRR0E8 - ldprofilereg0e8 */
/*! @{ */

#define locald34_LDPRR0E8_lumd353_MASK           (0x3FFU)
#define locald34_LDPRR0E8_lumd353_SHIFT          (0U)
/*! lumd353 - lumdat_353 */
#define locald34_LDPRR0E8_lumd353(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0E8_lumd353_SHIFT)) & locald34_LDPRR0E8_lumd353_MASK)

#define locald34_LDPRR0E8_lumd352_MASK           (0x3FF0000U)
#define locald34_LDPRR0E8_lumd352_SHIFT          (16U)
/*! lumd352 - lumdat_352 */
#define locald34_LDPRR0E8_lumd352(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0E8_lumd352_SHIFT)) & locald34_LDPRR0E8_lumd352_MASK)
/*! @} */

/*! @name LDPRR0E9 - ldprofilereg0e9 */
/*! @{ */

#define locald34_LDPRR0E9_lumd355_MASK           (0x3FFU)
#define locald34_LDPRR0E9_lumd355_SHIFT          (0U)
/*! lumd355 - lumdat_355 */
#define locald34_LDPRR0E9_lumd355(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0E9_lumd355_SHIFT)) & locald34_LDPRR0E9_lumd355_MASK)

#define locald34_LDPRR0E9_lumd354_MASK           (0x3FF0000U)
#define locald34_LDPRR0E9_lumd354_SHIFT          (16U)
/*! lumd354 - lumdat_354 */
#define locald34_LDPRR0E9_lumd354(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0E9_lumd354_SHIFT)) & locald34_LDPRR0E9_lumd354_MASK)
/*! @} */

/*! @name LDPRR0EA - ldprofilereg0ea */
/*! @{ */

#define locald34_LDPRR0EA_lumd357_MASK           (0x3FFU)
#define locald34_LDPRR0EA_lumd357_SHIFT          (0U)
/*! lumd357 - lumdat_357 */
#define locald34_LDPRR0EA_lumd357(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0EA_lumd357_SHIFT)) & locald34_LDPRR0EA_lumd357_MASK)

#define locald34_LDPRR0EA_lumd356_MASK           (0x3FF0000U)
#define locald34_LDPRR0EA_lumd356_SHIFT          (16U)
/*! lumd356 - lumdat_356 */
#define locald34_LDPRR0EA_lumd356(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0EA_lumd356_SHIFT)) & locald34_LDPRR0EA_lumd356_MASK)
/*! @} */

/*! @name LDPRR0EB - ldprofilereg0eb */
/*! @{ */

#define locald34_LDPRR0EB_lumd359_MASK           (0x3FFU)
#define locald34_LDPRR0EB_lumd359_SHIFT          (0U)
/*! lumd359 - lumdat_359 */
#define locald34_LDPRR0EB_lumd359(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0EB_lumd359_SHIFT)) & locald34_LDPRR0EB_lumd359_MASK)

#define locald34_LDPRR0EB_lumd358_MASK           (0x3FF0000U)
#define locald34_LDPRR0EB_lumd358_SHIFT          (16U)
/*! lumd358 - lumdat_358 */
#define locald34_LDPRR0EB_lumd358(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0EB_lumd358_SHIFT)) & locald34_LDPRR0EB_lumd358_MASK)
/*! @} */

/*! @name LDPRR0EC - ldprofilereg0ec */
/*! @{ */

#define locald34_LDPRR0EC_lumd361_MASK           (0x3FFU)
#define locald34_LDPRR0EC_lumd361_SHIFT          (0U)
/*! lumd361 - lumdat_361 */
#define locald34_LDPRR0EC_lumd361(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0EC_lumd361_SHIFT)) & locald34_LDPRR0EC_lumd361_MASK)

#define locald34_LDPRR0EC_lumd360_MASK           (0x3FF0000U)
#define locald34_LDPRR0EC_lumd360_SHIFT          (16U)
/*! lumd360 - lumdat_360 */
#define locald34_LDPRR0EC_lumd360(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0EC_lumd360_SHIFT)) & locald34_LDPRR0EC_lumd360_MASK)
/*! @} */

/*! @name LDPRR0ED - ldprofilereg0ed */
/*! @{ */

#define locald34_LDPRR0ED_lumd363_MASK           (0x3FFU)
#define locald34_LDPRR0ED_lumd363_SHIFT          (0U)
/*! lumd363 - lumdat_363 */
#define locald34_LDPRR0ED_lumd363(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0ED_lumd363_SHIFT)) & locald34_LDPRR0ED_lumd363_MASK)

#define locald34_LDPRR0ED_lumd362_MASK           (0x3FF0000U)
#define locald34_LDPRR0ED_lumd362_SHIFT          (16U)
/*! lumd362 - lumdat_362 */
#define locald34_LDPRR0ED_lumd362(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0ED_lumd362_SHIFT)) & locald34_LDPRR0ED_lumd362_MASK)
/*! @} */

/*! @name LDPRR0EE - ldprofilereg0ee */
/*! @{ */

#define locald34_LDPRR0EE_lumd365_MASK           (0x3FFU)
#define locald34_LDPRR0EE_lumd365_SHIFT          (0U)
/*! lumd365 - lumdat_365 */
#define locald34_LDPRR0EE_lumd365(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0EE_lumd365_SHIFT)) & locald34_LDPRR0EE_lumd365_MASK)

#define locald34_LDPRR0EE_lumd364_MASK           (0x3FF0000U)
#define locald34_LDPRR0EE_lumd364_SHIFT          (16U)
/*! lumd364 - lumdat_364 */
#define locald34_LDPRR0EE_lumd364(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0EE_lumd364_SHIFT)) & locald34_LDPRR0EE_lumd364_MASK)
/*! @} */

/*! @name LDPRR0EF - ldprofilereg0ef */
/*! @{ */

#define locald34_LDPRR0EF_lumd367_MASK           (0x3FFU)
#define locald34_LDPRR0EF_lumd367_SHIFT          (0U)
/*! lumd367 - lumdat_367 */
#define locald34_LDPRR0EF_lumd367(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0EF_lumd367_SHIFT)) & locald34_LDPRR0EF_lumd367_MASK)

#define locald34_LDPRR0EF_lumd366_MASK           (0x3FF0000U)
#define locald34_LDPRR0EF_lumd366_SHIFT          (16U)
/*! lumd366 - lumdat_366 */
#define locald34_LDPRR0EF_lumd366(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0EF_lumd366_SHIFT)) & locald34_LDPRR0EF_lumd366_MASK)
/*! @} */

/*! @name LDPRR0F0 - ldprofilereg0f0 */
/*! @{ */

#define locald34_LDPRR0F0_lumd369_MASK           (0x3FFU)
#define locald34_LDPRR0F0_lumd369_SHIFT          (0U)
/*! lumd369 - lumdat_369 */
#define locald34_LDPRR0F0_lumd369(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0F0_lumd369_SHIFT)) & locald34_LDPRR0F0_lumd369_MASK)

#define locald34_LDPRR0F0_lumd368_MASK           (0x3FF0000U)
#define locald34_LDPRR0F0_lumd368_SHIFT          (16U)
/*! lumd368 - lumdat_368 */
#define locald34_LDPRR0F0_lumd368(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0F0_lumd368_SHIFT)) & locald34_LDPRR0F0_lumd368_MASK)
/*! @} */

/*! @name LDPRR0F1 - ldprofilereg0f1 */
/*! @{ */

#define locald34_LDPRR0F1_lumd371_MASK           (0x3FFU)
#define locald34_LDPRR0F1_lumd371_SHIFT          (0U)
/*! lumd371 - lumdat_371 */
#define locald34_LDPRR0F1_lumd371(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0F1_lumd371_SHIFT)) & locald34_LDPRR0F1_lumd371_MASK)

#define locald34_LDPRR0F1_lumd370_MASK           (0x3FF0000U)
#define locald34_LDPRR0F1_lumd370_SHIFT          (16U)
/*! lumd370 - lumdat_370 */
#define locald34_LDPRR0F1_lumd370(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0F1_lumd370_SHIFT)) & locald34_LDPRR0F1_lumd370_MASK)
/*! @} */

/*! @name LDPRR0F2 - ldprofilereg0f2 */
/*! @{ */

#define locald34_LDPRR0F2_lumd373_MASK           (0x3FFU)
#define locald34_LDPRR0F2_lumd373_SHIFT          (0U)
/*! lumd373 - lumdat_373 */
#define locald34_LDPRR0F2_lumd373(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0F2_lumd373_SHIFT)) & locald34_LDPRR0F2_lumd373_MASK)

#define locald34_LDPRR0F2_lumd372_MASK           (0x3FF0000U)
#define locald34_LDPRR0F2_lumd372_SHIFT          (16U)
/*! lumd372 - lumdat_372 */
#define locald34_LDPRR0F2_lumd372(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0F2_lumd372_SHIFT)) & locald34_LDPRR0F2_lumd372_MASK)
/*! @} */

/*! @name LDPRR0F3 - ldprofilereg0f3 */
/*! @{ */

#define locald34_LDPRR0F3_lumd375_MASK           (0x3FFU)
#define locald34_LDPRR0F3_lumd375_SHIFT          (0U)
/*! lumd375 - lumdat_375 */
#define locald34_LDPRR0F3_lumd375(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0F3_lumd375_SHIFT)) & locald34_LDPRR0F3_lumd375_MASK)

#define locald34_LDPRR0F3_lumd374_MASK           (0x3FF0000U)
#define locald34_LDPRR0F3_lumd374_SHIFT          (16U)
/*! lumd374 - lumdat_374 */
#define locald34_LDPRR0F3_lumd374(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0F3_lumd374_SHIFT)) & locald34_LDPRR0F3_lumd374_MASK)
/*! @} */

/*! @name LDPRR0F4 - ldprofilereg0f4 */
/*! @{ */

#define locald34_LDPRR0F4_lumd377_MASK           (0x3FFU)
#define locald34_LDPRR0F4_lumd377_SHIFT          (0U)
/*! lumd377 - lumdat_377 */
#define locald34_LDPRR0F4_lumd377(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0F4_lumd377_SHIFT)) & locald34_LDPRR0F4_lumd377_MASK)

#define locald34_LDPRR0F4_lumd376_MASK           (0x3FF0000U)
#define locald34_LDPRR0F4_lumd376_SHIFT          (16U)
/*! lumd376 - lumdat_376 */
#define locald34_LDPRR0F4_lumd376(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0F4_lumd376_SHIFT)) & locald34_LDPRR0F4_lumd376_MASK)
/*! @} */

/*! @name LDPRR0F5 - ldprofilereg0f5 */
/*! @{ */

#define locald34_LDPRR0F5_lumd379_MASK           (0x3FFU)
#define locald34_LDPRR0F5_lumd379_SHIFT          (0U)
/*! lumd379 - lumdat_379 */
#define locald34_LDPRR0F5_lumd379(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0F5_lumd379_SHIFT)) & locald34_LDPRR0F5_lumd379_MASK)

#define locald34_LDPRR0F5_lumd378_MASK           (0x3FF0000U)
#define locald34_LDPRR0F5_lumd378_SHIFT          (16U)
/*! lumd378 - lumdat_378 */
#define locald34_LDPRR0F5_lumd378(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0F5_lumd378_SHIFT)) & locald34_LDPRR0F5_lumd378_MASK)
/*! @} */

/*! @name LDPRR0F6 - ldprofilereg0f6 */
/*! @{ */

#define locald34_LDPRR0F6_lumd381_MASK           (0x3FFU)
#define locald34_LDPRR0F6_lumd381_SHIFT          (0U)
/*! lumd381 - lumdat_381 */
#define locald34_LDPRR0F6_lumd381(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0F6_lumd381_SHIFT)) & locald34_LDPRR0F6_lumd381_MASK)

#define locald34_LDPRR0F6_lumd380_MASK           (0x3FF0000U)
#define locald34_LDPRR0F6_lumd380_SHIFT          (16U)
/*! lumd380 - lumdat_380 */
#define locald34_LDPRR0F6_lumd380(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0F6_lumd380_SHIFT)) & locald34_LDPRR0F6_lumd380_MASK)
/*! @} */

/*! @name LDPRR0F7 - ldprofilereg0f7 */
/*! @{ */

#define locald34_LDPRR0F7_lumd383_MASK           (0x3FFU)
#define locald34_LDPRR0F7_lumd383_SHIFT          (0U)
/*! lumd383 - lumdat_383 */
#define locald34_LDPRR0F7_lumd383(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0F7_lumd383_SHIFT)) & locald34_LDPRR0F7_lumd383_MASK)

#define locald34_LDPRR0F7_lumd382_MASK           (0x3FF0000U)
#define locald34_LDPRR0F7_lumd382_SHIFT          (16U)
/*! lumd382 - lumdat_382 */
#define locald34_LDPRR0F7_lumd382(x)             (((uint32_t)(((uint32_t)(x)) << locald34_LDPRR0F7_lumd382_SHIFT)) & locald34_LDPRR0F7_lumd382_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald34_Register_Masks */


/*!
 * @}
 */ /* end of group locald34_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD34_H_ */

