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
**         CMSIS Peripheral Access Layer for locald55
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
 * @file PERI_locald55.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald55
 *
 * CMSIS Peripheral Access Layer for locald55
 */

#if !defined(PERI_LOCALD55_H_)
#define PERI_LOCALD55_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald55 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald55_Peripheral_Access_Layer locald55 Peripheral Access Layer
 * @{
 */

/** locald55 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR380;                          /**< ldprofilereg380, offset: 0x0 */
  __IO uint32_t LDPRR381;                          /**< ldprofilereg381, offset: 0x4 */
  __IO uint32_t LDPRR382;                          /**< ldprofilereg382, offset: 0x8 */
  __IO uint32_t LDPRR383;                          /**< ldprofilereg383, offset: 0xC */
  __IO uint32_t LDPRR384;                          /**< ldprofilereg384, offset: 0x10 */
  __IO uint32_t LDPRR385;                          /**< ldprofilereg385, offset: 0x14 */
  __IO uint32_t LDPRR386;                          /**< ldprofilereg386, offset: 0x18 */
  __IO uint32_t LDPRR387;                          /**< ldprofilereg387, offset: 0x1C */
  __IO uint32_t LDPRR388;                          /**< ldprofilereg388, offset: 0x20 */
  __IO uint32_t LDPRR389;                          /**< ldprofilereg389, offset: 0x24 */
  __IO uint32_t LDPRR38A;                          /**< ldprofilereg38a, offset: 0x28 */
  __IO uint32_t LDPRR38B;                          /**< ldprofilereg38b, offset: 0x2C */
  __IO uint32_t LDPRR38C;                          /**< ldprofilereg38c, offset: 0x30 */
  __IO uint32_t LDPRR38D;                          /**< ldprofilereg38d, offset: 0x34 */
  __IO uint32_t LDPRR38E;                          /**< ldprofilereg38e, offset: 0x38 */
  __IO uint32_t LDPRR38F;                          /**< ldprofilereg38f, offset: 0x3C */
  __IO uint32_t LDPRR390;                          /**< ldprofilereg390, offset: 0x40 */
  __IO uint32_t LDPRR391;                          /**< ldprofilereg391, offset: 0x44 */
  __IO uint32_t LDPRR392;                          /**< ldprofilereg392, offset: 0x48 */
  __IO uint32_t LDPRR393;                          /**< ldprofilereg393, offset: 0x4C */
  __IO uint32_t LDPRR394;                          /**< ldprofilereg394, offset: 0x50 */
  __IO uint32_t LDPRR395;                          /**< ldprofilereg395, offset: 0x54 */
  __IO uint32_t LDPRR396;                          /**< ldprofilereg396, offset: 0x58 */
  __IO uint32_t LDPRR397;                          /**< ldprofilereg397, offset: 0x5C */
} locald55_Type;

/* ----------------------------------------------------------------------------
   -- locald55 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald55_Register_Masks locald55 Register Masks
 * @{
 */

/*! @name LDPRR380 - ldprofilereg380 */
/*! @{ */

#define locald55_LDPRR380_lumd1345_MASK          (0x3FFU)
#define locald55_LDPRR380_lumd1345_SHIFT         (0U)
/*! lumd1345 - lumdat_1345 */
#define locald55_LDPRR380_lumd1345(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR380_lumd1345_SHIFT)) & locald55_LDPRR380_lumd1345_MASK)

#define locald55_LDPRR380_lumd1344_MASK          (0x3FF0000U)
#define locald55_LDPRR380_lumd1344_SHIFT         (16U)
/*! lumd1344 - lumdat_1344 */
#define locald55_LDPRR380_lumd1344(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR380_lumd1344_SHIFT)) & locald55_LDPRR380_lumd1344_MASK)
/*! @} */

/*! @name LDPRR381 - ldprofilereg381 */
/*! @{ */

#define locald55_LDPRR381_lumd1347_MASK          (0x3FFU)
#define locald55_LDPRR381_lumd1347_SHIFT         (0U)
/*! lumd1347 - lumdat_1347 */
#define locald55_LDPRR381_lumd1347(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR381_lumd1347_SHIFT)) & locald55_LDPRR381_lumd1347_MASK)

#define locald55_LDPRR381_lumd1346_MASK          (0x3FF0000U)
#define locald55_LDPRR381_lumd1346_SHIFT         (16U)
/*! lumd1346 - lumdat_1346 */
#define locald55_LDPRR381_lumd1346(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR381_lumd1346_SHIFT)) & locald55_LDPRR381_lumd1346_MASK)
/*! @} */

/*! @name LDPRR382 - ldprofilereg382 */
/*! @{ */

#define locald55_LDPRR382_lumd1349_MASK          (0x3FFU)
#define locald55_LDPRR382_lumd1349_SHIFT         (0U)
/*! lumd1349 - lumdat_1349 */
#define locald55_LDPRR382_lumd1349(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR382_lumd1349_SHIFT)) & locald55_LDPRR382_lumd1349_MASK)

#define locald55_LDPRR382_lumd1348_MASK          (0x3FF0000U)
#define locald55_LDPRR382_lumd1348_SHIFT         (16U)
/*! lumd1348 - lumdat_1348 */
#define locald55_LDPRR382_lumd1348(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR382_lumd1348_SHIFT)) & locald55_LDPRR382_lumd1348_MASK)
/*! @} */

/*! @name LDPRR383 - ldprofilereg383 */
/*! @{ */

#define locald55_LDPRR383_lumd1351_MASK          (0x3FFU)
#define locald55_LDPRR383_lumd1351_SHIFT         (0U)
/*! lumd1351 - lumdat_1351 */
#define locald55_LDPRR383_lumd1351(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR383_lumd1351_SHIFT)) & locald55_LDPRR383_lumd1351_MASK)

#define locald55_LDPRR383_lumd1350_MASK          (0x3FF0000U)
#define locald55_LDPRR383_lumd1350_SHIFT         (16U)
/*! lumd1350 - lumdat_1350 */
#define locald55_LDPRR383_lumd1350(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR383_lumd1350_SHIFT)) & locald55_LDPRR383_lumd1350_MASK)
/*! @} */

/*! @name LDPRR384 - ldprofilereg384 */
/*! @{ */

#define locald55_LDPRR384_lumd1353_MASK          (0x3FFU)
#define locald55_LDPRR384_lumd1353_SHIFT         (0U)
/*! lumd1353 - lumdat_1353 */
#define locald55_LDPRR384_lumd1353(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR384_lumd1353_SHIFT)) & locald55_LDPRR384_lumd1353_MASK)

#define locald55_LDPRR384_lumd1352_MASK          (0x3FF0000U)
#define locald55_LDPRR384_lumd1352_SHIFT         (16U)
/*! lumd1352 - lumdat_1352 */
#define locald55_LDPRR384_lumd1352(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR384_lumd1352_SHIFT)) & locald55_LDPRR384_lumd1352_MASK)
/*! @} */

/*! @name LDPRR385 - ldprofilereg385 */
/*! @{ */

#define locald55_LDPRR385_lumd1355_MASK          (0x3FFU)
#define locald55_LDPRR385_lumd1355_SHIFT         (0U)
/*! lumd1355 - lumdat_1355 */
#define locald55_LDPRR385_lumd1355(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR385_lumd1355_SHIFT)) & locald55_LDPRR385_lumd1355_MASK)

#define locald55_LDPRR385_lumd1354_MASK          (0x3FF0000U)
#define locald55_LDPRR385_lumd1354_SHIFT         (16U)
/*! lumd1354 - lumdat_1354 */
#define locald55_LDPRR385_lumd1354(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR385_lumd1354_SHIFT)) & locald55_LDPRR385_lumd1354_MASK)
/*! @} */

/*! @name LDPRR386 - ldprofilereg386 */
/*! @{ */

#define locald55_LDPRR386_lumd1357_MASK          (0x3FFU)
#define locald55_LDPRR386_lumd1357_SHIFT         (0U)
/*! lumd1357 - lumdat_1357 */
#define locald55_LDPRR386_lumd1357(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR386_lumd1357_SHIFT)) & locald55_LDPRR386_lumd1357_MASK)

#define locald55_LDPRR386_lumd1356_MASK          (0x3FF0000U)
#define locald55_LDPRR386_lumd1356_SHIFT         (16U)
/*! lumd1356 - lumdat_1356 */
#define locald55_LDPRR386_lumd1356(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR386_lumd1356_SHIFT)) & locald55_LDPRR386_lumd1356_MASK)
/*! @} */

/*! @name LDPRR387 - ldprofilereg387 */
/*! @{ */

#define locald55_LDPRR387_lumd1359_MASK          (0x3FFU)
#define locald55_LDPRR387_lumd1359_SHIFT         (0U)
/*! lumd1359 - lumdat_1359 */
#define locald55_LDPRR387_lumd1359(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR387_lumd1359_SHIFT)) & locald55_LDPRR387_lumd1359_MASK)

#define locald55_LDPRR387_lumd1358_MASK          (0x3FF0000U)
#define locald55_LDPRR387_lumd1358_SHIFT         (16U)
/*! lumd1358 - lumdat_1358 */
#define locald55_LDPRR387_lumd1358(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR387_lumd1358_SHIFT)) & locald55_LDPRR387_lumd1358_MASK)
/*! @} */

/*! @name LDPRR388 - ldprofilereg388 */
/*! @{ */

#define locald55_LDPRR388_lumd1361_MASK          (0x3FFU)
#define locald55_LDPRR388_lumd1361_SHIFT         (0U)
/*! lumd1361 - lumdat_1361 */
#define locald55_LDPRR388_lumd1361(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR388_lumd1361_SHIFT)) & locald55_LDPRR388_lumd1361_MASK)

#define locald55_LDPRR388_lumd1360_MASK          (0x3FF0000U)
#define locald55_LDPRR388_lumd1360_SHIFT         (16U)
/*! lumd1360 - lumdat_1360 */
#define locald55_LDPRR388_lumd1360(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR388_lumd1360_SHIFT)) & locald55_LDPRR388_lumd1360_MASK)
/*! @} */

/*! @name LDPRR389 - ldprofilereg389 */
/*! @{ */

#define locald55_LDPRR389_lumd1363_MASK          (0x3FFU)
#define locald55_LDPRR389_lumd1363_SHIFT         (0U)
/*! lumd1363 - lumdat_1363 */
#define locald55_LDPRR389_lumd1363(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR389_lumd1363_SHIFT)) & locald55_LDPRR389_lumd1363_MASK)

#define locald55_LDPRR389_lumd1362_MASK          (0x3FF0000U)
#define locald55_LDPRR389_lumd1362_SHIFT         (16U)
/*! lumd1362 - lumdat_1362 */
#define locald55_LDPRR389_lumd1362(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR389_lumd1362_SHIFT)) & locald55_LDPRR389_lumd1362_MASK)
/*! @} */

/*! @name LDPRR38A - ldprofilereg38a */
/*! @{ */

#define locald55_LDPRR38A_lumd1365_MASK          (0x3FFU)
#define locald55_LDPRR38A_lumd1365_SHIFT         (0U)
/*! lumd1365 - lumdat_1365 */
#define locald55_LDPRR38A_lumd1365(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR38A_lumd1365_SHIFT)) & locald55_LDPRR38A_lumd1365_MASK)

#define locald55_LDPRR38A_lumd1364_MASK          (0x3FF0000U)
#define locald55_LDPRR38A_lumd1364_SHIFT         (16U)
/*! lumd1364 - lumdat_1364 */
#define locald55_LDPRR38A_lumd1364(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR38A_lumd1364_SHIFT)) & locald55_LDPRR38A_lumd1364_MASK)
/*! @} */

/*! @name LDPRR38B - ldprofilereg38b */
/*! @{ */

#define locald55_LDPRR38B_lumd1367_MASK          (0x3FFU)
#define locald55_LDPRR38B_lumd1367_SHIFT         (0U)
/*! lumd1367 - lumdat_1367 */
#define locald55_LDPRR38B_lumd1367(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR38B_lumd1367_SHIFT)) & locald55_LDPRR38B_lumd1367_MASK)

#define locald55_LDPRR38B_lumd1366_MASK          (0x3FF0000U)
#define locald55_LDPRR38B_lumd1366_SHIFT         (16U)
/*! lumd1366 - lumdat_1366 */
#define locald55_LDPRR38B_lumd1366(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR38B_lumd1366_SHIFT)) & locald55_LDPRR38B_lumd1366_MASK)
/*! @} */

/*! @name LDPRR38C - ldprofilereg38c */
/*! @{ */

#define locald55_LDPRR38C_lumd1369_MASK          (0x3FFU)
#define locald55_LDPRR38C_lumd1369_SHIFT         (0U)
/*! lumd1369 - lumdat_1369 */
#define locald55_LDPRR38C_lumd1369(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR38C_lumd1369_SHIFT)) & locald55_LDPRR38C_lumd1369_MASK)

#define locald55_LDPRR38C_lumd1368_MASK          (0x3FF0000U)
#define locald55_LDPRR38C_lumd1368_SHIFT         (16U)
/*! lumd1368 - lumdat_1368 */
#define locald55_LDPRR38C_lumd1368(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR38C_lumd1368_SHIFT)) & locald55_LDPRR38C_lumd1368_MASK)
/*! @} */

/*! @name LDPRR38D - ldprofilereg38d */
/*! @{ */

#define locald55_LDPRR38D_lumd1371_MASK          (0x3FFU)
#define locald55_LDPRR38D_lumd1371_SHIFT         (0U)
/*! lumd1371 - lumdat_1371 */
#define locald55_LDPRR38D_lumd1371(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR38D_lumd1371_SHIFT)) & locald55_LDPRR38D_lumd1371_MASK)

#define locald55_LDPRR38D_lumd1370_MASK          (0x3FF0000U)
#define locald55_LDPRR38D_lumd1370_SHIFT         (16U)
/*! lumd1370 - lumdat_1370 */
#define locald55_LDPRR38D_lumd1370(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR38D_lumd1370_SHIFT)) & locald55_LDPRR38D_lumd1370_MASK)
/*! @} */

/*! @name LDPRR38E - ldprofilereg38e */
/*! @{ */

#define locald55_LDPRR38E_lumd1373_MASK          (0x3FFU)
#define locald55_LDPRR38E_lumd1373_SHIFT         (0U)
/*! lumd1373 - lumdat_1373 */
#define locald55_LDPRR38E_lumd1373(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR38E_lumd1373_SHIFT)) & locald55_LDPRR38E_lumd1373_MASK)

#define locald55_LDPRR38E_lumd1372_MASK          (0x3FF0000U)
#define locald55_LDPRR38E_lumd1372_SHIFT         (16U)
/*! lumd1372 - lumdat_1372 */
#define locald55_LDPRR38E_lumd1372(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR38E_lumd1372_SHIFT)) & locald55_LDPRR38E_lumd1372_MASK)
/*! @} */

/*! @name LDPRR38F - ldprofilereg38f */
/*! @{ */

#define locald55_LDPRR38F_lumd1375_MASK          (0x3FFU)
#define locald55_LDPRR38F_lumd1375_SHIFT         (0U)
/*! lumd1375 - lumdat_1375 */
#define locald55_LDPRR38F_lumd1375(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR38F_lumd1375_SHIFT)) & locald55_LDPRR38F_lumd1375_MASK)

#define locald55_LDPRR38F_lumd1374_MASK          (0x3FF0000U)
#define locald55_LDPRR38F_lumd1374_SHIFT         (16U)
/*! lumd1374 - lumdat_1374 */
#define locald55_LDPRR38F_lumd1374(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR38F_lumd1374_SHIFT)) & locald55_LDPRR38F_lumd1374_MASK)
/*! @} */

/*! @name LDPRR390 - ldprofilereg390 */
/*! @{ */

#define locald55_LDPRR390_lumd1377_MASK          (0x3FFU)
#define locald55_LDPRR390_lumd1377_SHIFT         (0U)
/*! lumd1377 - lumdat_1377 */
#define locald55_LDPRR390_lumd1377(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR390_lumd1377_SHIFT)) & locald55_LDPRR390_lumd1377_MASK)

#define locald55_LDPRR390_lumd1376_MASK          (0x3FF0000U)
#define locald55_LDPRR390_lumd1376_SHIFT         (16U)
/*! lumd1376 - lumdat_1376 */
#define locald55_LDPRR390_lumd1376(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR390_lumd1376_SHIFT)) & locald55_LDPRR390_lumd1376_MASK)
/*! @} */

/*! @name LDPRR391 - ldprofilereg391 */
/*! @{ */

#define locald55_LDPRR391_lumd1379_MASK          (0x3FFU)
#define locald55_LDPRR391_lumd1379_SHIFT         (0U)
/*! lumd1379 - lumdat_1379 */
#define locald55_LDPRR391_lumd1379(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR391_lumd1379_SHIFT)) & locald55_LDPRR391_lumd1379_MASK)

#define locald55_LDPRR391_lumd1378_MASK          (0x3FF0000U)
#define locald55_LDPRR391_lumd1378_SHIFT         (16U)
/*! lumd1378 - lumdat_1378 */
#define locald55_LDPRR391_lumd1378(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR391_lumd1378_SHIFT)) & locald55_LDPRR391_lumd1378_MASK)
/*! @} */

/*! @name LDPRR392 - ldprofilereg392 */
/*! @{ */

#define locald55_LDPRR392_lumd1381_MASK          (0x3FFU)
#define locald55_LDPRR392_lumd1381_SHIFT         (0U)
/*! lumd1381 - lumdat_1381 */
#define locald55_LDPRR392_lumd1381(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR392_lumd1381_SHIFT)) & locald55_LDPRR392_lumd1381_MASK)

#define locald55_LDPRR392_lumd1380_MASK          (0x3FF0000U)
#define locald55_LDPRR392_lumd1380_SHIFT         (16U)
/*! lumd1380 - lumdat_1380 */
#define locald55_LDPRR392_lumd1380(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR392_lumd1380_SHIFT)) & locald55_LDPRR392_lumd1380_MASK)
/*! @} */

/*! @name LDPRR393 - ldprofilereg393 */
/*! @{ */

#define locald55_LDPRR393_lumd1383_MASK          (0x3FFU)
#define locald55_LDPRR393_lumd1383_SHIFT         (0U)
/*! lumd1383 - lumdat_1383 */
#define locald55_LDPRR393_lumd1383(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR393_lumd1383_SHIFT)) & locald55_LDPRR393_lumd1383_MASK)

#define locald55_LDPRR393_lumd1382_MASK          (0x3FF0000U)
#define locald55_LDPRR393_lumd1382_SHIFT         (16U)
/*! lumd1382 - lumdat_1382 */
#define locald55_LDPRR393_lumd1382(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR393_lumd1382_SHIFT)) & locald55_LDPRR393_lumd1382_MASK)
/*! @} */

/*! @name LDPRR394 - ldprofilereg394 */
/*! @{ */

#define locald55_LDPRR394_lumd1385_MASK          (0x3FFU)
#define locald55_LDPRR394_lumd1385_SHIFT         (0U)
/*! lumd1385 - lumdat_1385 */
#define locald55_LDPRR394_lumd1385(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR394_lumd1385_SHIFT)) & locald55_LDPRR394_lumd1385_MASK)

#define locald55_LDPRR394_lumd1384_MASK          (0x3FF0000U)
#define locald55_LDPRR394_lumd1384_SHIFT         (16U)
/*! lumd1384 - lumdat_1384 */
#define locald55_LDPRR394_lumd1384(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR394_lumd1384_SHIFT)) & locald55_LDPRR394_lumd1384_MASK)
/*! @} */

/*! @name LDPRR395 - ldprofilereg395 */
/*! @{ */

#define locald55_LDPRR395_lumd1387_MASK          (0x3FFU)
#define locald55_LDPRR395_lumd1387_SHIFT         (0U)
/*! lumd1387 - lumdat_1387 */
#define locald55_LDPRR395_lumd1387(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR395_lumd1387_SHIFT)) & locald55_LDPRR395_lumd1387_MASK)

#define locald55_LDPRR395_lumd1386_MASK          (0x3FF0000U)
#define locald55_LDPRR395_lumd1386_SHIFT         (16U)
/*! lumd1386 - lumdat_1386 */
#define locald55_LDPRR395_lumd1386(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR395_lumd1386_SHIFT)) & locald55_LDPRR395_lumd1386_MASK)
/*! @} */

/*! @name LDPRR396 - ldprofilereg396 */
/*! @{ */

#define locald55_LDPRR396_lumd1389_MASK          (0x3FFU)
#define locald55_LDPRR396_lumd1389_SHIFT         (0U)
/*! lumd1389 - lumdat_1389 */
#define locald55_LDPRR396_lumd1389(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR396_lumd1389_SHIFT)) & locald55_LDPRR396_lumd1389_MASK)

#define locald55_LDPRR396_lumd1388_MASK          (0x3FF0000U)
#define locald55_LDPRR396_lumd1388_SHIFT         (16U)
/*! lumd1388 - lumdat_1388 */
#define locald55_LDPRR396_lumd1388(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR396_lumd1388_SHIFT)) & locald55_LDPRR396_lumd1388_MASK)
/*! @} */

/*! @name LDPRR397 - ldprofilereg397 */
/*! @{ */

#define locald55_LDPRR397_lumd1391_MASK          (0x3FFU)
#define locald55_LDPRR397_lumd1391_SHIFT         (0U)
/*! lumd1391 - lumdat_1391 */
#define locald55_LDPRR397_lumd1391(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR397_lumd1391_SHIFT)) & locald55_LDPRR397_lumd1391_MASK)

#define locald55_LDPRR397_lumd1390_MASK          (0x3FF0000U)
#define locald55_LDPRR397_lumd1390_SHIFT         (16U)
/*! lumd1390 - lumdat_1390 */
#define locald55_LDPRR397_lumd1390(x)            (((uint32_t)(((uint32_t)(x)) << locald55_LDPRR397_lumd1390_SHIFT)) & locald55_LDPRR397_lumd1390_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald55_Register_Masks */


/*!
 * @}
 */ /* end of group locald55_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD55_H_ */

