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
**         CMSIS Peripheral Access Layer for locald57
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
 * @file PERI_locald57.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald57
 *
 * CMSIS Peripheral Access Layer for locald57
 */

#if !defined(PERI_LOCALD57_H_)
#define PERI_LOCALD57_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald57 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald57_Peripheral_Access_Layer locald57 Peripheral Access Layer
 * @{
 */

/** locald57 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR3C0;                          /**< ldprofilereg3c0, offset: 0x0 */
  __IO uint32_t LDPRR3C1;                          /**< ldprofilereg3c1, offset: 0x4 */
  __IO uint32_t LDPRR3C2;                          /**< ldprofilereg3c2, offset: 0x8 */
  __IO uint32_t LDPRR3C3;                          /**< ldprofilereg3c3, offset: 0xC */
  __IO uint32_t LDPRR3C4;                          /**< ldprofilereg3c4, offset: 0x10 */
  __IO uint32_t LDPRR3C5;                          /**< ldprofilereg3c5, offset: 0x14 */
  __IO uint32_t LDPRR3C6;                          /**< ldprofilereg3c6, offset: 0x18 */
  __IO uint32_t LDPRR3C7;                          /**< ldprofilereg3c7, offset: 0x1C */
  __IO uint32_t LDPRR3C8;                          /**< ldprofilereg3c8, offset: 0x20 */
  __IO uint32_t LDPRR3C9;                          /**< ldprofilereg3c9, offset: 0x24 */
  __IO uint32_t LDPRR3CA;                          /**< ldprofilereg3ca, offset: 0x28 */
  __IO uint32_t LDPRR3CB;                          /**< ldprofilereg3cb, offset: 0x2C */
  __IO uint32_t LDPRR3CC;                          /**< ldprofilereg3cc, offset: 0x30 */
  __IO uint32_t LDPRR3CD;                          /**< ldprofilereg3cd, offset: 0x34 */
  __IO uint32_t LDPRR3CE;                          /**< ldprofilereg3ce, offset: 0x38 */
  __IO uint32_t LDPRR3CF;                          /**< ldprofilereg3cf, offset: 0x3C */
  __IO uint32_t LDPRR3D0;                          /**< ldprofilereg3d0, offset: 0x40 */
  __IO uint32_t LDPRR3D1;                          /**< ldprofilereg3d1, offset: 0x44 */
  __IO uint32_t LDPRR3D2;                          /**< ldprofilereg3d2, offset: 0x48 */
  __IO uint32_t LDPRR3D3;                          /**< ldprofilereg3d3, offset: 0x4C */
  __IO uint32_t LDPRR3D4;                          /**< ldprofilereg3d4, offset: 0x50 */
  __IO uint32_t LDPRR3D5;                          /**< ldprofilereg3d5, offset: 0x54 */
  __IO uint32_t LDPRR3D6;                          /**< ldprofilereg3d6, offset: 0x58 */
  __IO uint32_t LDPRR3D7;                          /**< ldprofilereg3d7, offset: 0x5C */
} locald57_Type;

/* ----------------------------------------------------------------------------
   -- locald57 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald57_Register_Masks locald57 Register Masks
 * @{
 */

/*! @name LDPRR3C0 - ldprofilereg3c0 */
/*! @{ */

#define locald57_LDPRR3C0_lumd1441_MASK          (0x3FFU)
#define locald57_LDPRR3C0_lumd1441_SHIFT         (0U)
/*! lumd1441 - lumdat_1441 */
#define locald57_LDPRR3C0_lumd1441(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3C0_lumd1441_SHIFT)) & locald57_LDPRR3C0_lumd1441_MASK)

#define locald57_LDPRR3C0_lumd1440_MASK          (0x3FF0000U)
#define locald57_LDPRR3C0_lumd1440_SHIFT         (16U)
/*! lumd1440 - lumdat_1440 */
#define locald57_LDPRR3C0_lumd1440(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3C0_lumd1440_SHIFT)) & locald57_LDPRR3C0_lumd1440_MASK)
/*! @} */

/*! @name LDPRR3C1 - ldprofilereg3c1 */
/*! @{ */

#define locald57_LDPRR3C1_lumd1443_MASK          (0x3FFU)
#define locald57_LDPRR3C1_lumd1443_SHIFT         (0U)
/*! lumd1443 - lumdat_1443 */
#define locald57_LDPRR3C1_lumd1443(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3C1_lumd1443_SHIFT)) & locald57_LDPRR3C1_lumd1443_MASK)

#define locald57_LDPRR3C1_lumd1442_MASK          (0x3FF0000U)
#define locald57_LDPRR3C1_lumd1442_SHIFT         (16U)
/*! lumd1442 - lumdat_1442 */
#define locald57_LDPRR3C1_lumd1442(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3C1_lumd1442_SHIFT)) & locald57_LDPRR3C1_lumd1442_MASK)
/*! @} */

/*! @name LDPRR3C2 - ldprofilereg3c2 */
/*! @{ */

#define locald57_LDPRR3C2_lumd1445_MASK          (0x3FFU)
#define locald57_LDPRR3C2_lumd1445_SHIFT         (0U)
/*! lumd1445 - lumdat_1445 */
#define locald57_LDPRR3C2_lumd1445(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3C2_lumd1445_SHIFT)) & locald57_LDPRR3C2_lumd1445_MASK)

#define locald57_LDPRR3C2_lumd1444_MASK          (0x3FF0000U)
#define locald57_LDPRR3C2_lumd1444_SHIFT         (16U)
/*! lumd1444 - lumdat_1444 */
#define locald57_LDPRR3C2_lumd1444(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3C2_lumd1444_SHIFT)) & locald57_LDPRR3C2_lumd1444_MASK)
/*! @} */

/*! @name LDPRR3C3 - ldprofilereg3c3 */
/*! @{ */

#define locald57_LDPRR3C3_lumd1447_MASK          (0x3FFU)
#define locald57_LDPRR3C3_lumd1447_SHIFT         (0U)
/*! lumd1447 - lumdat_1447 */
#define locald57_LDPRR3C3_lumd1447(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3C3_lumd1447_SHIFT)) & locald57_LDPRR3C3_lumd1447_MASK)

#define locald57_LDPRR3C3_lumd1446_MASK          (0x3FF0000U)
#define locald57_LDPRR3C3_lumd1446_SHIFT         (16U)
/*! lumd1446 - lumdat_1446 */
#define locald57_LDPRR3C3_lumd1446(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3C3_lumd1446_SHIFT)) & locald57_LDPRR3C3_lumd1446_MASK)
/*! @} */

/*! @name LDPRR3C4 - ldprofilereg3c4 */
/*! @{ */

#define locald57_LDPRR3C4_lumd1449_MASK          (0x3FFU)
#define locald57_LDPRR3C4_lumd1449_SHIFT         (0U)
/*! lumd1449 - lumdat_1449 */
#define locald57_LDPRR3C4_lumd1449(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3C4_lumd1449_SHIFT)) & locald57_LDPRR3C4_lumd1449_MASK)

#define locald57_LDPRR3C4_lumd1448_MASK          (0x3FF0000U)
#define locald57_LDPRR3C4_lumd1448_SHIFT         (16U)
/*! lumd1448 - lumdat_1448 */
#define locald57_LDPRR3C4_lumd1448(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3C4_lumd1448_SHIFT)) & locald57_LDPRR3C4_lumd1448_MASK)
/*! @} */

/*! @name LDPRR3C5 - ldprofilereg3c5 */
/*! @{ */

#define locald57_LDPRR3C5_lumd1451_MASK          (0x3FFU)
#define locald57_LDPRR3C5_lumd1451_SHIFT         (0U)
/*! lumd1451 - lumdat_1451 */
#define locald57_LDPRR3C5_lumd1451(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3C5_lumd1451_SHIFT)) & locald57_LDPRR3C5_lumd1451_MASK)

#define locald57_LDPRR3C5_lumd1450_MASK          (0x3FF0000U)
#define locald57_LDPRR3C5_lumd1450_SHIFT         (16U)
/*! lumd1450 - lumdat_1450 */
#define locald57_LDPRR3C5_lumd1450(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3C5_lumd1450_SHIFT)) & locald57_LDPRR3C5_lumd1450_MASK)
/*! @} */

/*! @name LDPRR3C6 - ldprofilereg3c6 */
/*! @{ */

#define locald57_LDPRR3C6_lumd1453_MASK          (0x3FFU)
#define locald57_LDPRR3C6_lumd1453_SHIFT         (0U)
/*! lumd1453 - lumdat_1453 */
#define locald57_LDPRR3C6_lumd1453(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3C6_lumd1453_SHIFT)) & locald57_LDPRR3C6_lumd1453_MASK)

#define locald57_LDPRR3C6_lumd1452_MASK          (0x3FF0000U)
#define locald57_LDPRR3C6_lumd1452_SHIFT         (16U)
/*! lumd1452 - lumdat_1452 */
#define locald57_LDPRR3C6_lumd1452(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3C6_lumd1452_SHIFT)) & locald57_LDPRR3C6_lumd1452_MASK)
/*! @} */

/*! @name LDPRR3C7 - ldprofilereg3c7 */
/*! @{ */

#define locald57_LDPRR3C7_lumd1455_MASK          (0x3FFU)
#define locald57_LDPRR3C7_lumd1455_SHIFT         (0U)
/*! lumd1455 - lumdat_1455 */
#define locald57_LDPRR3C7_lumd1455(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3C7_lumd1455_SHIFT)) & locald57_LDPRR3C7_lumd1455_MASK)

#define locald57_LDPRR3C7_lumd1454_MASK          (0x3FF0000U)
#define locald57_LDPRR3C7_lumd1454_SHIFT         (16U)
/*! lumd1454 - lumdat_1454 */
#define locald57_LDPRR3C7_lumd1454(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3C7_lumd1454_SHIFT)) & locald57_LDPRR3C7_lumd1454_MASK)
/*! @} */

/*! @name LDPRR3C8 - ldprofilereg3c8 */
/*! @{ */

#define locald57_LDPRR3C8_lumd1457_MASK          (0x3FFU)
#define locald57_LDPRR3C8_lumd1457_SHIFT         (0U)
/*! lumd1457 - lumdat_1457 */
#define locald57_LDPRR3C8_lumd1457(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3C8_lumd1457_SHIFT)) & locald57_LDPRR3C8_lumd1457_MASK)

#define locald57_LDPRR3C8_lumd1456_MASK          (0x3FF0000U)
#define locald57_LDPRR3C8_lumd1456_SHIFT         (16U)
/*! lumd1456 - lumdat_1456 */
#define locald57_LDPRR3C8_lumd1456(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3C8_lumd1456_SHIFT)) & locald57_LDPRR3C8_lumd1456_MASK)
/*! @} */

/*! @name LDPRR3C9 - ldprofilereg3c9 */
/*! @{ */

#define locald57_LDPRR3C9_lumd1459_MASK          (0x3FFU)
#define locald57_LDPRR3C9_lumd1459_SHIFT         (0U)
/*! lumd1459 - lumdat_1459 */
#define locald57_LDPRR3C9_lumd1459(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3C9_lumd1459_SHIFT)) & locald57_LDPRR3C9_lumd1459_MASK)

#define locald57_LDPRR3C9_lumd1458_MASK          (0x3FF0000U)
#define locald57_LDPRR3C9_lumd1458_SHIFT         (16U)
/*! lumd1458 - lumdat_1458 */
#define locald57_LDPRR3C9_lumd1458(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3C9_lumd1458_SHIFT)) & locald57_LDPRR3C9_lumd1458_MASK)
/*! @} */

/*! @name LDPRR3CA - ldprofilereg3ca */
/*! @{ */

#define locald57_LDPRR3CA_lumd1461_MASK          (0x3FFU)
#define locald57_LDPRR3CA_lumd1461_SHIFT         (0U)
/*! lumd1461 - lumdat_1461 */
#define locald57_LDPRR3CA_lumd1461(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3CA_lumd1461_SHIFT)) & locald57_LDPRR3CA_lumd1461_MASK)

#define locald57_LDPRR3CA_lumd1460_MASK          (0x3FF0000U)
#define locald57_LDPRR3CA_lumd1460_SHIFT         (16U)
/*! lumd1460 - lumdat_1460 */
#define locald57_LDPRR3CA_lumd1460(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3CA_lumd1460_SHIFT)) & locald57_LDPRR3CA_lumd1460_MASK)
/*! @} */

/*! @name LDPRR3CB - ldprofilereg3cb */
/*! @{ */

#define locald57_LDPRR3CB_lumd1463_MASK          (0x3FFU)
#define locald57_LDPRR3CB_lumd1463_SHIFT         (0U)
/*! lumd1463 - lumdat_1463 */
#define locald57_LDPRR3CB_lumd1463(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3CB_lumd1463_SHIFT)) & locald57_LDPRR3CB_lumd1463_MASK)

#define locald57_LDPRR3CB_lumd1462_MASK          (0x3FF0000U)
#define locald57_LDPRR3CB_lumd1462_SHIFT         (16U)
/*! lumd1462 - lumdat_1462 */
#define locald57_LDPRR3CB_lumd1462(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3CB_lumd1462_SHIFT)) & locald57_LDPRR3CB_lumd1462_MASK)
/*! @} */

/*! @name LDPRR3CC - ldprofilereg3cc */
/*! @{ */

#define locald57_LDPRR3CC_lumd1465_MASK          (0x3FFU)
#define locald57_LDPRR3CC_lumd1465_SHIFT         (0U)
/*! lumd1465 - lumdat_1465 */
#define locald57_LDPRR3CC_lumd1465(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3CC_lumd1465_SHIFT)) & locald57_LDPRR3CC_lumd1465_MASK)

#define locald57_LDPRR3CC_lumd1464_MASK          (0x3FF0000U)
#define locald57_LDPRR3CC_lumd1464_SHIFT         (16U)
/*! lumd1464 - lumdat_1464 */
#define locald57_LDPRR3CC_lumd1464(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3CC_lumd1464_SHIFT)) & locald57_LDPRR3CC_lumd1464_MASK)
/*! @} */

/*! @name LDPRR3CD - ldprofilereg3cd */
/*! @{ */

#define locald57_LDPRR3CD_lumd1467_MASK          (0x3FFU)
#define locald57_LDPRR3CD_lumd1467_SHIFT         (0U)
/*! lumd1467 - lumdat_1467 */
#define locald57_LDPRR3CD_lumd1467(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3CD_lumd1467_SHIFT)) & locald57_LDPRR3CD_lumd1467_MASK)

#define locald57_LDPRR3CD_lumd1466_MASK          (0x3FF0000U)
#define locald57_LDPRR3CD_lumd1466_SHIFT         (16U)
/*! lumd1466 - lumdat_1466 */
#define locald57_LDPRR3CD_lumd1466(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3CD_lumd1466_SHIFT)) & locald57_LDPRR3CD_lumd1466_MASK)
/*! @} */

/*! @name LDPRR3CE - ldprofilereg3ce */
/*! @{ */

#define locald57_LDPRR3CE_lumd1469_MASK          (0x3FFU)
#define locald57_LDPRR3CE_lumd1469_SHIFT         (0U)
/*! lumd1469 - lumdat_1469 */
#define locald57_LDPRR3CE_lumd1469(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3CE_lumd1469_SHIFT)) & locald57_LDPRR3CE_lumd1469_MASK)

#define locald57_LDPRR3CE_lumd1468_MASK          (0x3FF0000U)
#define locald57_LDPRR3CE_lumd1468_SHIFT         (16U)
/*! lumd1468 - lumdat_1468 */
#define locald57_LDPRR3CE_lumd1468(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3CE_lumd1468_SHIFT)) & locald57_LDPRR3CE_lumd1468_MASK)
/*! @} */

/*! @name LDPRR3CF - ldprofilereg3cf */
/*! @{ */

#define locald57_LDPRR3CF_lumd1471_MASK          (0x3FFU)
#define locald57_LDPRR3CF_lumd1471_SHIFT         (0U)
/*! lumd1471 - lumdat_1471 */
#define locald57_LDPRR3CF_lumd1471(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3CF_lumd1471_SHIFT)) & locald57_LDPRR3CF_lumd1471_MASK)

#define locald57_LDPRR3CF_lumd1470_MASK          (0x3FF0000U)
#define locald57_LDPRR3CF_lumd1470_SHIFT         (16U)
/*! lumd1470 - lumdat_1470 */
#define locald57_LDPRR3CF_lumd1470(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3CF_lumd1470_SHIFT)) & locald57_LDPRR3CF_lumd1470_MASK)
/*! @} */

/*! @name LDPRR3D0 - ldprofilereg3d0 */
/*! @{ */

#define locald57_LDPRR3D0_lumd1473_MASK          (0x3FFU)
#define locald57_LDPRR3D0_lumd1473_SHIFT         (0U)
/*! lumd1473 - lumdat_1473 */
#define locald57_LDPRR3D0_lumd1473(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3D0_lumd1473_SHIFT)) & locald57_LDPRR3D0_lumd1473_MASK)

#define locald57_LDPRR3D0_lumd1472_MASK          (0x3FF0000U)
#define locald57_LDPRR3D0_lumd1472_SHIFT         (16U)
/*! lumd1472 - lumdat_1472 */
#define locald57_LDPRR3D0_lumd1472(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3D0_lumd1472_SHIFT)) & locald57_LDPRR3D0_lumd1472_MASK)
/*! @} */

/*! @name LDPRR3D1 - ldprofilereg3d1 */
/*! @{ */

#define locald57_LDPRR3D1_lumd1475_MASK          (0x3FFU)
#define locald57_LDPRR3D1_lumd1475_SHIFT         (0U)
/*! lumd1475 - lumdat_1475 */
#define locald57_LDPRR3D1_lumd1475(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3D1_lumd1475_SHIFT)) & locald57_LDPRR3D1_lumd1475_MASK)

#define locald57_LDPRR3D1_lumd1474_MASK          (0x3FF0000U)
#define locald57_LDPRR3D1_lumd1474_SHIFT         (16U)
/*! lumd1474 - lumdat_1474 */
#define locald57_LDPRR3D1_lumd1474(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3D1_lumd1474_SHIFT)) & locald57_LDPRR3D1_lumd1474_MASK)
/*! @} */

/*! @name LDPRR3D2 - ldprofilereg3d2 */
/*! @{ */

#define locald57_LDPRR3D2_lumd1477_MASK          (0x3FFU)
#define locald57_LDPRR3D2_lumd1477_SHIFT         (0U)
/*! lumd1477 - lumdat_1477 */
#define locald57_LDPRR3D2_lumd1477(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3D2_lumd1477_SHIFT)) & locald57_LDPRR3D2_lumd1477_MASK)

#define locald57_LDPRR3D2_lumd1476_MASK          (0x3FF0000U)
#define locald57_LDPRR3D2_lumd1476_SHIFT         (16U)
/*! lumd1476 - lumdat_1476 */
#define locald57_LDPRR3D2_lumd1476(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3D2_lumd1476_SHIFT)) & locald57_LDPRR3D2_lumd1476_MASK)
/*! @} */

/*! @name LDPRR3D3 - ldprofilereg3d3 */
/*! @{ */

#define locald57_LDPRR3D3_lumd1479_MASK          (0x3FFU)
#define locald57_LDPRR3D3_lumd1479_SHIFT         (0U)
/*! lumd1479 - lumdat_1479 */
#define locald57_LDPRR3D3_lumd1479(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3D3_lumd1479_SHIFT)) & locald57_LDPRR3D3_lumd1479_MASK)

#define locald57_LDPRR3D3_lumd1478_MASK          (0x3FF0000U)
#define locald57_LDPRR3D3_lumd1478_SHIFT         (16U)
/*! lumd1478 - lumdat_1478 */
#define locald57_LDPRR3D3_lumd1478(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3D3_lumd1478_SHIFT)) & locald57_LDPRR3D3_lumd1478_MASK)
/*! @} */

/*! @name LDPRR3D4 - ldprofilereg3d4 */
/*! @{ */

#define locald57_LDPRR3D4_lumd1481_MASK          (0x3FFU)
#define locald57_LDPRR3D4_lumd1481_SHIFT         (0U)
/*! lumd1481 - lumdat_1481 */
#define locald57_LDPRR3D4_lumd1481(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3D4_lumd1481_SHIFT)) & locald57_LDPRR3D4_lumd1481_MASK)

#define locald57_LDPRR3D4_lumd1480_MASK          (0x3FF0000U)
#define locald57_LDPRR3D4_lumd1480_SHIFT         (16U)
/*! lumd1480 - lumdat_1480 */
#define locald57_LDPRR3D4_lumd1480(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3D4_lumd1480_SHIFT)) & locald57_LDPRR3D4_lumd1480_MASK)
/*! @} */

/*! @name LDPRR3D5 - ldprofilereg3d5 */
/*! @{ */

#define locald57_LDPRR3D5_lumd1483_MASK          (0x3FFU)
#define locald57_LDPRR3D5_lumd1483_SHIFT         (0U)
/*! lumd1483 - lumdat_1483 */
#define locald57_LDPRR3D5_lumd1483(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3D5_lumd1483_SHIFT)) & locald57_LDPRR3D5_lumd1483_MASK)

#define locald57_LDPRR3D5_lumd1482_MASK          (0x3FF0000U)
#define locald57_LDPRR3D5_lumd1482_SHIFT         (16U)
/*! lumd1482 - lumdat_1482 */
#define locald57_LDPRR3D5_lumd1482(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3D5_lumd1482_SHIFT)) & locald57_LDPRR3D5_lumd1482_MASK)
/*! @} */

/*! @name LDPRR3D6 - ldprofilereg3d6 */
/*! @{ */

#define locald57_LDPRR3D6_lumd1485_MASK          (0x3FFU)
#define locald57_LDPRR3D6_lumd1485_SHIFT         (0U)
/*! lumd1485 - lumdat_1485 */
#define locald57_LDPRR3D6_lumd1485(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3D6_lumd1485_SHIFT)) & locald57_LDPRR3D6_lumd1485_MASK)

#define locald57_LDPRR3D6_lumd1484_MASK          (0x3FF0000U)
#define locald57_LDPRR3D6_lumd1484_SHIFT         (16U)
/*! lumd1484 - lumdat_1484 */
#define locald57_LDPRR3D6_lumd1484(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3D6_lumd1484_SHIFT)) & locald57_LDPRR3D6_lumd1484_MASK)
/*! @} */

/*! @name LDPRR3D7 - ldprofilereg3d7 */
/*! @{ */

#define locald57_LDPRR3D7_lumd1487_MASK          (0x3FFU)
#define locald57_LDPRR3D7_lumd1487_SHIFT         (0U)
/*! lumd1487 - lumdat_1487 */
#define locald57_LDPRR3D7_lumd1487(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3D7_lumd1487_SHIFT)) & locald57_LDPRR3D7_lumd1487_MASK)

#define locald57_LDPRR3D7_lumd1486_MASK          (0x3FF0000U)
#define locald57_LDPRR3D7_lumd1486_SHIFT         (16U)
/*! lumd1486 - lumdat_1486 */
#define locald57_LDPRR3D7_lumd1486(x)            (((uint32_t)(((uint32_t)(x)) << locald57_LDPRR3D7_lumd1486_SHIFT)) & locald57_LDPRR3D7_lumd1486_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald57_Register_Masks */


/*!
 * @}
 */ /* end of group locald57_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD57_H_ */

