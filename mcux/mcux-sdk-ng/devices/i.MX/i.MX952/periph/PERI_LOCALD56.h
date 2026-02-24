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
**         CMSIS Peripheral Access Layer for locald56
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
 * @file PERI_locald56.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald56
 *
 * CMSIS Peripheral Access Layer for locald56
 */

#if !defined(PERI_LOCALD56_H_)
#define PERI_LOCALD56_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald56 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald56_Peripheral_Access_Layer locald56 Peripheral Access Layer
 * @{
 */

/** locald56 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR3A0;                          /**< ldprofilereg3a0, offset: 0x0 */
  __IO uint32_t LDPRR3A1;                          /**< ldprofilereg3a1, offset: 0x4 */
  __IO uint32_t LDPRR3A2;                          /**< ldprofilereg3a2, offset: 0x8 */
  __IO uint32_t LDPRR3A3;                          /**< ldprofilereg3a3, offset: 0xC */
  __IO uint32_t LDPRR3A4;                          /**< ldprofilereg3a4, offset: 0x10 */
  __IO uint32_t LDPRR3A5;                          /**< ldprofilereg3a5, offset: 0x14 */
  __IO uint32_t LDPRR3A6;                          /**< ldprofilereg3a6, offset: 0x18 */
  __IO uint32_t LDPRR3A7;                          /**< ldprofilereg3a7, offset: 0x1C */
  __IO uint32_t LDPRR3A8;                          /**< ldprofilereg3a8, offset: 0x20 */
  __IO uint32_t LDPRR3A9;                          /**< ldprofilereg3a9, offset: 0x24 */
  __IO uint32_t LDPRR3AA;                          /**< ldprofilereg3aa, offset: 0x28 */
  __IO uint32_t LDPRR3AB;                          /**< ldprofilereg3ab, offset: 0x2C */
  __IO uint32_t LDPRR3AC;                          /**< ldprofilereg3ac, offset: 0x30 */
  __IO uint32_t LDPRR3AD;                          /**< ldprofilereg3ad, offset: 0x34 */
  __IO uint32_t LDPRR3AE;                          /**< ldprofilereg3ae, offset: 0x38 */
  __IO uint32_t LDPRR3AF;                          /**< ldprofilereg3af, offset: 0x3C */
  __IO uint32_t LDPRR3B0;                          /**< ldprofilereg3b0, offset: 0x40 */
  __IO uint32_t LDPRR3B1;                          /**< ldprofilereg3b1, offset: 0x44 */
  __IO uint32_t LDPRR3B2;                          /**< ldprofilereg3b2, offset: 0x48 */
  __IO uint32_t LDPRR3B3;                          /**< ldprofilereg3b3, offset: 0x4C */
  __IO uint32_t LDPRR3B4;                          /**< ldprofilereg3b4, offset: 0x50 */
  __IO uint32_t LDPRR3B5;                          /**< ldprofilereg3b5, offset: 0x54 */
  __IO uint32_t LDPRR3B6;                          /**< ldprofilereg3b6, offset: 0x58 */
  __IO uint32_t LDPRR3B7;                          /**< ldprofilereg3b7, offset: 0x5C */
} locald56_Type;

/* ----------------------------------------------------------------------------
   -- locald56 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald56_Register_Masks locald56 Register Masks
 * @{
 */

/*! @name LDPRR3A0 - ldprofilereg3a0 */
/*! @{ */

#define locald56_LDPRR3A0_lumd1393_MASK          (0x3FFU)
#define locald56_LDPRR3A0_lumd1393_SHIFT         (0U)
/*! lumd1393 - lumdat_1393 */
#define locald56_LDPRR3A0_lumd1393(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3A0_lumd1393_SHIFT)) & locald56_LDPRR3A0_lumd1393_MASK)

#define locald56_LDPRR3A0_lumd1392_MASK          (0x3FF0000U)
#define locald56_LDPRR3A0_lumd1392_SHIFT         (16U)
/*! lumd1392 - lumdat_1392 */
#define locald56_LDPRR3A0_lumd1392(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3A0_lumd1392_SHIFT)) & locald56_LDPRR3A0_lumd1392_MASK)
/*! @} */

/*! @name LDPRR3A1 - ldprofilereg3a1 */
/*! @{ */

#define locald56_LDPRR3A1_lumd1395_MASK          (0x3FFU)
#define locald56_LDPRR3A1_lumd1395_SHIFT         (0U)
/*! lumd1395 - lumdat_1395 */
#define locald56_LDPRR3A1_lumd1395(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3A1_lumd1395_SHIFT)) & locald56_LDPRR3A1_lumd1395_MASK)

#define locald56_LDPRR3A1_lumd1394_MASK          (0x3FF0000U)
#define locald56_LDPRR3A1_lumd1394_SHIFT         (16U)
/*! lumd1394 - lumdat_1394 */
#define locald56_LDPRR3A1_lumd1394(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3A1_lumd1394_SHIFT)) & locald56_LDPRR3A1_lumd1394_MASK)
/*! @} */

/*! @name LDPRR3A2 - ldprofilereg3a2 */
/*! @{ */

#define locald56_LDPRR3A2_lumd1397_MASK          (0x3FFU)
#define locald56_LDPRR3A2_lumd1397_SHIFT         (0U)
/*! lumd1397 - lumdat_1397 */
#define locald56_LDPRR3A2_lumd1397(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3A2_lumd1397_SHIFT)) & locald56_LDPRR3A2_lumd1397_MASK)

#define locald56_LDPRR3A2_lumd1396_MASK          (0x3FF0000U)
#define locald56_LDPRR3A2_lumd1396_SHIFT         (16U)
/*! lumd1396 - lumdat_1396 */
#define locald56_LDPRR3A2_lumd1396(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3A2_lumd1396_SHIFT)) & locald56_LDPRR3A2_lumd1396_MASK)
/*! @} */

/*! @name LDPRR3A3 - ldprofilereg3a3 */
/*! @{ */

#define locald56_LDPRR3A3_lumd1399_MASK          (0x3FFU)
#define locald56_LDPRR3A3_lumd1399_SHIFT         (0U)
/*! lumd1399 - lumdat_1399 */
#define locald56_LDPRR3A3_lumd1399(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3A3_lumd1399_SHIFT)) & locald56_LDPRR3A3_lumd1399_MASK)

#define locald56_LDPRR3A3_lumd1398_MASK          (0x3FF0000U)
#define locald56_LDPRR3A3_lumd1398_SHIFT         (16U)
/*! lumd1398 - lumdat_1398 */
#define locald56_LDPRR3A3_lumd1398(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3A3_lumd1398_SHIFT)) & locald56_LDPRR3A3_lumd1398_MASK)
/*! @} */

/*! @name LDPRR3A4 - ldprofilereg3a4 */
/*! @{ */

#define locald56_LDPRR3A4_lumd1401_MASK          (0x3FFU)
#define locald56_LDPRR3A4_lumd1401_SHIFT         (0U)
/*! lumd1401 - lumdat_1401 */
#define locald56_LDPRR3A4_lumd1401(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3A4_lumd1401_SHIFT)) & locald56_LDPRR3A4_lumd1401_MASK)

#define locald56_LDPRR3A4_lumd1400_MASK          (0x3FF0000U)
#define locald56_LDPRR3A4_lumd1400_SHIFT         (16U)
/*! lumd1400 - lumdat_1400 */
#define locald56_LDPRR3A4_lumd1400(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3A4_lumd1400_SHIFT)) & locald56_LDPRR3A4_lumd1400_MASK)
/*! @} */

/*! @name LDPRR3A5 - ldprofilereg3a5 */
/*! @{ */

#define locald56_LDPRR3A5_lumd1403_MASK          (0x3FFU)
#define locald56_LDPRR3A5_lumd1403_SHIFT         (0U)
/*! lumd1403 - lumdat_1403 */
#define locald56_LDPRR3A5_lumd1403(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3A5_lumd1403_SHIFT)) & locald56_LDPRR3A5_lumd1403_MASK)

#define locald56_LDPRR3A5_lumd1402_MASK          (0x3FF0000U)
#define locald56_LDPRR3A5_lumd1402_SHIFT         (16U)
/*! lumd1402 - lumdat_1402 */
#define locald56_LDPRR3A5_lumd1402(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3A5_lumd1402_SHIFT)) & locald56_LDPRR3A5_lumd1402_MASK)
/*! @} */

/*! @name LDPRR3A6 - ldprofilereg3a6 */
/*! @{ */

#define locald56_LDPRR3A6_lumd1405_MASK          (0x3FFU)
#define locald56_LDPRR3A6_lumd1405_SHIFT         (0U)
/*! lumd1405 - lumdat_1405 */
#define locald56_LDPRR3A6_lumd1405(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3A6_lumd1405_SHIFT)) & locald56_LDPRR3A6_lumd1405_MASK)

#define locald56_LDPRR3A6_lumd1404_MASK          (0x3FF0000U)
#define locald56_LDPRR3A6_lumd1404_SHIFT         (16U)
/*! lumd1404 - lumdat_1404 */
#define locald56_LDPRR3A6_lumd1404(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3A6_lumd1404_SHIFT)) & locald56_LDPRR3A6_lumd1404_MASK)
/*! @} */

/*! @name LDPRR3A7 - ldprofilereg3a7 */
/*! @{ */

#define locald56_LDPRR3A7_lumd1407_MASK          (0x3FFU)
#define locald56_LDPRR3A7_lumd1407_SHIFT         (0U)
/*! lumd1407 - lumdat_1407 */
#define locald56_LDPRR3A7_lumd1407(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3A7_lumd1407_SHIFT)) & locald56_LDPRR3A7_lumd1407_MASK)

#define locald56_LDPRR3A7_lumd1406_MASK          (0x3FF0000U)
#define locald56_LDPRR3A7_lumd1406_SHIFT         (16U)
/*! lumd1406 - lumdat_1406 */
#define locald56_LDPRR3A7_lumd1406(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3A7_lumd1406_SHIFT)) & locald56_LDPRR3A7_lumd1406_MASK)
/*! @} */

/*! @name LDPRR3A8 - ldprofilereg3a8 */
/*! @{ */

#define locald56_LDPRR3A8_lumd1409_MASK          (0x3FFU)
#define locald56_LDPRR3A8_lumd1409_SHIFT         (0U)
/*! lumd1409 - lumdat_1409 */
#define locald56_LDPRR3A8_lumd1409(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3A8_lumd1409_SHIFT)) & locald56_LDPRR3A8_lumd1409_MASK)

#define locald56_LDPRR3A8_lumd1408_MASK          (0x3FF0000U)
#define locald56_LDPRR3A8_lumd1408_SHIFT         (16U)
/*! lumd1408 - lumdat_1408 */
#define locald56_LDPRR3A8_lumd1408(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3A8_lumd1408_SHIFT)) & locald56_LDPRR3A8_lumd1408_MASK)
/*! @} */

/*! @name LDPRR3A9 - ldprofilereg3a9 */
/*! @{ */

#define locald56_LDPRR3A9_lumd1411_MASK          (0x3FFU)
#define locald56_LDPRR3A9_lumd1411_SHIFT         (0U)
/*! lumd1411 - lumdat_1411 */
#define locald56_LDPRR3A9_lumd1411(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3A9_lumd1411_SHIFT)) & locald56_LDPRR3A9_lumd1411_MASK)

#define locald56_LDPRR3A9_lumd1410_MASK          (0x3FF0000U)
#define locald56_LDPRR3A9_lumd1410_SHIFT         (16U)
/*! lumd1410 - lumdat_1410 */
#define locald56_LDPRR3A9_lumd1410(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3A9_lumd1410_SHIFT)) & locald56_LDPRR3A9_lumd1410_MASK)
/*! @} */

/*! @name LDPRR3AA - ldprofilereg3aa */
/*! @{ */

#define locald56_LDPRR3AA_lumd1413_MASK          (0x3FFU)
#define locald56_LDPRR3AA_lumd1413_SHIFT         (0U)
/*! lumd1413 - lumdat_1413 */
#define locald56_LDPRR3AA_lumd1413(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3AA_lumd1413_SHIFT)) & locald56_LDPRR3AA_lumd1413_MASK)

#define locald56_LDPRR3AA_lumd1412_MASK          (0x3FF0000U)
#define locald56_LDPRR3AA_lumd1412_SHIFT         (16U)
/*! lumd1412 - lumdat_1412 */
#define locald56_LDPRR3AA_lumd1412(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3AA_lumd1412_SHIFT)) & locald56_LDPRR3AA_lumd1412_MASK)
/*! @} */

/*! @name LDPRR3AB - ldprofilereg3ab */
/*! @{ */

#define locald56_LDPRR3AB_lumd1415_MASK          (0x3FFU)
#define locald56_LDPRR3AB_lumd1415_SHIFT         (0U)
/*! lumd1415 - lumdat_1415 */
#define locald56_LDPRR3AB_lumd1415(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3AB_lumd1415_SHIFT)) & locald56_LDPRR3AB_lumd1415_MASK)

#define locald56_LDPRR3AB_lumd1414_MASK          (0x3FF0000U)
#define locald56_LDPRR3AB_lumd1414_SHIFT         (16U)
/*! lumd1414 - lumdat_1414 */
#define locald56_LDPRR3AB_lumd1414(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3AB_lumd1414_SHIFT)) & locald56_LDPRR3AB_lumd1414_MASK)
/*! @} */

/*! @name LDPRR3AC - ldprofilereg3ac */
/*! @{ */

#define locald56_LDPRR3AC_lumd1417_MASK          (0x3FFU)
#define locald56_LDPRR3AC_lumd1417_SHIFT         (0U)
/*! lumd1417 - lumdat_1417 */
#define locald56_LDPRR3AC_lumd1417(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3AC_lumd1417_SHIFT)) & locald56_LDPRR3AC_lumd1417_MASK)

#define locald56_LDPRR3AC_lumd1416_MASK          (0x3FF0000U)
#define locald56_LDPRR3AC_lumd1416_SHIFT         (16U)
/*! lumd1416 - lumdat_1416 */
#define locald56_LDPRR3AC_lumd1416(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3AC_lumd1416_SHIFT)) & locald56_LDPRR3AC_lumd1416_MASK)
/*! @} */

/*! @name LDPRR3AD - ldprofilereg3ad */
/*! @{ */

#define locald56_LDPRR3AD_lumd1419_MASK          (0x3FFU)
#define locald56_LDPRR3AD_lumd1419_SHIFT         (0U)
/*! lumd1419 - lumdat_1419 */
#define locald56_LDPRR3AD_lumd1419(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3AD_lumd1419_SHIFT)) & locald56_LDPRR3AD_lumd1419_MASK)

#define locald56_LDPRR3AD_lumd1418_MASK          (0x3FF0000U)
#define locald56_LDPRR3AD_lumd1418_SHIFT         (16U)
/*! lumd1418 - lumdat_1418 */
#define locald56_LDPRR3AD_lumd1418(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3AD_lumd1418_SHIFT)) & locald56_LDPRR3AD_lumd1418_MASK)
/*! @} */

/*! @name LDPRR3AE - ldprofilereg3ae */
/*! @{ */

#define locald56_LDPRR3AE_lumd1421_MASK          (0x3FFU)
#define locald56_LDPRR3AE_lumd1421_SHIFT         (0U)
/*! lumd1421 - lumdat_1421 */
#define locald56_LDPRR3AE_lumd1421(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3AE_lumd1421_SHIFT)) & locald56_LDPRR3AE_lumd1421_MASK)

#define locald56_LDPRR3AE_lumd1420_MASK          (0x3FF0000U)
#define locald56_LDPRR3AE_lumd1420_SHIFT         (16U)
/*! lumd1420 - lumdat_1420 */
#define locald56_LDPRR3AE_lumd1420(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3AE_lumd1420_SHIFT)) & locald56_LDPRR3AE_lumd1420_MASK)
/*! @} */

/*! @name LDPRR3AF - ldprofilereg3af */
/*! @{ */

#define locald56_LDPRR3AF_lumd1423_MASK          (0x3FFU)
#define locald56_LDPRR3AF_lumd1423_SHIFT         (0U)
/*! lumd1423 - lumdat_1423 */
#define locald56_LDPRR3AF_lumd1423(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3AF_lumd1423_SHIFT)) & locald56_LDPRR3AF_lumd1423_MASK)

#define locald56_LDPRR3AF_lumd1422_MASK          (0x3FF0000U)
#define locald56_LDPRR3AF_lumd1422_SHIFT         (16U)
/*! lumd1422 - lumdat_1422 */
#define locald56_LDPRR3AF_lumd1422(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3AF_lumd1422_SHIFT)) & locald56_LDPRR3AF_lumd1422_MASK)
/*! @} */

/*! @name LDPRR3B0 - ldprofilereg3b0 */
/*! @{ */

#define locald56_LDPRR3B0_lumd1425_MASK          (0x3FFU)
#define locald56_LDPRR3B0_lumd1425_SHIFT         (0U)
/*! lumd1425 - lumdat_1425 */
#define locald56_LDPRR3B0_lumd1425(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3B0_lumd1425_SHIFT)) & locald56_LDPRR3B0_lumd1425_MASK)

#define locald56_LDPRR3B0_lumd1424_MASK          (0x3FF0000U)
#define locald56_LDPRR3B0_lumd1424_SHIFT         (16U)
/*! lumd1424 - lumdat_1424 */
#define locald56_LDPRR3B0_lumd1424(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3B0_lumd1424_SHIFT)) & locald56_LDPRR3B0_lumd1424_MASK)
/*! @} */

/*! @name LDPRR3B1 - ldprofilereg3b1 */
/*! @{ */

#define locald56_LDPRR3B1_lumd1427_MASK          (0x3FFU)
#define locald56_LDPRR3B1_lumd1427_SHIFT         (0U)
/*! lumd1427 - lumdat_1427 */
#define locald56_LDPRR3B1_lumd1427(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3B1_lumd1427_SHIFT)) & locald56_LDPRR3B1_lumd1427_MASK)

#define locald56_LDPRR3B1_lumd1426_MASK          (0x3FF0000U)
#define locald56_LDPRR3B1_lumd1426_SHIFT         (16U)
/*! lumd1426 - lumdat_1426 */
#define locald56_LDPRR3B1_lumd1426(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3B1_lumd1426_SHIFT)) & locald56_LDPRR3B1_lumd1426_MASK)
/*! @} */

/*! @name LDPRR3B2 - ldprofilereg3b2 */
/*! @{ */

#define locald56_LDPRR3B2_lumd1429_MASK          (0x3FFU)
#define locald56_LDPRR3B2_lumd1429_SHIFT         (0U)
/*! lumd1429 - lumdat_1429 */
#define locald56_LDPRR3B2_lumd1429(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3B2_lumd1429_SHIFT)) & locald56_LDPRR3B2_lumd1429_MASK)

#define locald56_LDPRR3B2_lumd1428_MASK          (0x3FF0000U)
#define locald56_LDPRR3B2_lumd1428_SHIFT         (16U)
/*! lumd1428 - lumdat_1428 */
#define locald56_LDPRR3B2_lumd1428(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3B2_lumd1428_SHIFT)) & locald56_LDPRR3B2_lumd1428_MASK)
/*! @} */

/*! @name LDPRR3B3 - ldprofilereg3b3 */
/*! @{ */

#define locald56_LDPRR3B3_lumd1431_MASK          (0x3FFU)
#define locald56_LDPRR3B3_lumd1431_SHIFT         (0U)
/*! lumd1431 - lumdat_1431 */
#define locald56_LDPRR3B3_lumd1431(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3B3_lumd1431_SHIFT)) & locald56_LDPRR3B3_lumd1431_MASK)

#define locald56_LDPRR3B3_lumd1430_MASK          (0x3FF0000U)
#define locald56_LDPRR3B3_lumd1430_SHIFT         (16U)
/*! lumd1430 - lumdat_1430 */
#define locald56_LDPRR3B3_lumd1430(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3B3_lumd1430_SHIFT)) & locald56_LDPRR3B3_lumd1430_MASK)
/*! @} */

/*! @name LDPRR3B4 - ldprofilereg3b4 */
/*! @{ */

#define locald56_LDPRR3B4_lumd1433_MASK          (0x3FFU)
#define locald56_LDPRR3B4_lumd1433_SHIFT         (0U)
/*! lumd1433 - lumdat_1433 */
#define locald56_LDPRR3B4_lumd1433(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3B4_lumd1433_SHIFT)) & locald56_LDPRR3B4_lumd1433_MASK)

#define locald56_LDPRR3B4_lumd1432_MASK          (0x3FF0000U)
#define locald56_LDPRR3B4_lumd1432_SHIFT         (16U)
/*! lumd1432 - lumdat_1432 */
#define locald56_LDPRR3B4_lumd1432(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3B4_lumd1432_SHIFT)) & locald56_LDPRR3B4_lumd1432_MASK)
/*! @} */

/*! @name LDPRR3B5 - ldprofilereg3b5 */
/*! @{ */

#define locald56_LDPRR3B5_lumd1435_MASK          (0x3FFU)
#define locald56_LDPRR3B5_lumd1435_SHIFT         (0U)
/*! lumd1435 - lumdat_1435 */
#define locald56_LDPRR3B5_lumd1435(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3B5_lumd1435_SHIFT)) & locald56_LDPRR3B5_lumd1435_MASK)

#define locald56_LDPRR3B5_lumd1434_MASK          (0x3FF0000U)
#define locald56_LDPRR3B5_lumd1434_SHIFT         (16U)
/*! lumd1434 - lumdat_1434 */
#define locald56_LDPRR3B5_lumd1434(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3B5_lumd1434_SHIFT)) & locald56_LDPRR3B5_lumd1434_MASK)
/*! @} */

/*! @name LDPRR3B6 - ldprofilereg3b6 */
/*! @{ */

#define locald56_LDPRR3B6_lumd1437_MASK          (0x3FFU)
#define locald56_LDPRR3B6_lumd1437_SHIFT         (0U)
/*! lumd1437 - lumdat_1437 */
#define locald56_LDPRR3B6_lumd1437(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3B6_lumd1437_SHIFT)) & locald56_LDPRR3B6_lumd1437_MASK)

#define locald56_LDPRR3B6_lumd1436_MASK          (0x3FF0000U)
#define locald56_LDPRR3B6_lumd1436_SHIFT         (16U)
/*! lumd1436 - lumdat_1436 */
#define locald56_LDPRR3B6_lumd1436(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3B6_lumd1436_SHIFT)) & locald56_LDPRR3B6_lumd1436_MASK)
/*! @} */

/*! @name LDPRR3B7 - ldprofilereg3b7 */
/*! @{ */

#define locald56_LDPRR3B7_lumd1439_MASK          (0x3FFU)
#define locald56_LDPRR3B7_lumd1439_SHIFT         (0U)
/*! lumd1439 - lumdat_1439 */
#define locald56_LDPRR3B7_lumd1439(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3B7_lumd1439_SHIFT)) & locald56_LDPRR3B7_lumd1439_MASK)

#define locald56_LDPRR3B7_lumd1438_MASK          (0x3FF0000U)
#define locald56_LDPRR3B7_lumd1438_SHIFT         (16U)
/*! lumd1438 - lumdat_1438 */
#define locald56_LDPRR3B7_lumd1438(x)            (((uint32_t)(((uint32_t)(x)) << locald56_LDPRR3B7_lumd1438_SHIFT)) & locald56_LDPRR3B7_lumd1438_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald56_Register_Masks */


/*!
 * @}
 */ /* end of group locald56_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD56_H_ */

