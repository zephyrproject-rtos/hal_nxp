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
**         CMSIS Peripheral Access Layer for locald53
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
 * @file PERI_locald53.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald53
 *
 * CMSIS Peripheral Access Layer for locald53
 */

#if !defined(PERI_LOCALD53_H_)
#define PERI_LOCALD53_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald53 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald53_Peripheral_Access_Layer locald53 Peripheral Access Layer
 * @{
 */

/** locald53 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR340;                          /**< ldprofilereg340, offset: 0x0 */
  __IO uint32_t LDPRR341;                          /**< ldprofilereg341, offset: 0x4 */
  __IO uint32_t LDPRR342;                          /**< ldprofilereg342, offset: 0x8 */
  __IO uint32_t LDPRR343;                          /**< ldprofilereg343, offset: 0xC */
  __IO uint32_t LDPRR344;                          /**< ldprofilereg344, offset: 0x10 */
  __IO uint32_t LDPRR345;                          /**< ldprofilereg345, offset: 0x14 */
  __IO uint32_t LDPRR346;                          /**< ldprofilereg346, offset: 0x18 */
  __IO uint32_t LDPRR347;                          /**< ldprofilereg347, offset: 0x1C */
  __IO uint32_t LDPRR348;                          /**< ldprofilereg348, offset: 0x20 */
  __IO uint32_t LDPRR349;                          /**< ldprofilereg349, offset: 0x24 */
  __IO uint32_t LDPRR34A;                          /**< ldprofilereg34a, offset: 0x28 */
  __IO uint32_t LDPRR34B;                          /**< ldprofilereg34b, offset: 0x2C */
  __IO uint32_t LDPRR34C;                          /**< ldprofilereg34c, offset: 0x30 */
  __IO uint32_t LDPRR34D;                          /**< ldprofilereg34d, offset: 0x34 */
  __IO uint32_t LDPRR34E;                          /**< ldprofilereg34e, offset: 0x38 */
  __IO uint32_t LDPRR34F;                          /**< ldprofilereg34f, offset: 0x3C */
  __IO uint32_t LDPRR350;                          /**< ldprofilereg350, offset: 0x40 */
  __IO uint32_t LDPRR351;                          /**< ldprofilereg351, offset: 0x44 */
  __IO uint32_t LDPRR352;                          /**< ldprofilereg352, offset: 0x48 */
  __IO uint32_t LDPRR353;                          /**< ldprofilereg353, offset: 0x4C */
  __IO uint32_t LDPRR354;                          /**< ldprofilereg354, offset: 0x50 */
  __IO uint32_t LDPRR355;                          /**< ldprofilereg355, offset: 0x54 */
  __IO uint32_t LDPRR356;                          /**< ldprofilereg356, offset: 0x58 */
  __IO uint32_t LDPRR357;                          /**< ldprofilereg357, offset: 0x5C */
} locald53_Type;

/* ----------------------------------------------------------------------------
   -- locald53 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald53_Register_Masks locald53 Register Masks
 * @{
 */

/*! @name LDPRR340 - ldprofilereg340 */
/*! @{ */

#define locald53_LDPRR340_lumd1249_MASK          (0x3FFU)
#define locald53_LDPRR340_lumd1249_SHIFT         (0U)
/*! lumd1249 - lumdat_1249 */
#define locald53_LDPRR340_lumd1249(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR340_lumd1249_SHIFT)) & locald53_LDPRR340_lumd1249_MASK)

#define locald53_LDPRR340_lumd1248_MASK          (0x3FF0000U)
#define locald53_LDPRR340_lumd1248_SHIFT         (16U)
/*! lumd1248 - lumdat_1248 */
#define locald53_LDPRR340_lumd1248(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR340_lumd1248_SHIFT)) & locald53_LDPRR340_lumd1248_MASK)
/*! @} */

/*! @name LDPRR341 - ldprofilereg341 */
/*! @{ */

#define locald53_LDPRR341_lumd1251_MASK          (0x3FFU)
#define locald53_LDPRR341_lumd1251_SHIFT         (0U)
/*! lumd1251 - lumdat_1251 */
#define locald53_LDPRR341_lumd1251(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR341_lumd1251_SHIFT)) & locald53_LDPRR341_lumd1251_MASK)

#define locald53_LDPRR341_lumd1250_MASK          (0x3FF0000U)
#define locald53_LDPRR341_lumd1250_SHIFT         (16U)
/*! lumd1250 - lumdat_1250 */
#define locald53_LDPRR341_lumd1250(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR341_lumd1250_SHIFT)) & locald53_LDPRR341_lumd1250_MASK)
/*! @} */

/*! @name LDPRR342 - ldprofilereg342 */
/*! @{ */

#define locald53_LDPRR342_lumd1253_MASK          (0x3FFU)
#define locald53_LDPRR342_lumd1253_SHIFT         (0U)
/*! lumd1253 - lumdat_1253 */
#define locald53_LDPRR342_lumd1253(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR342_lumd1253_SHIFT)) & locald53_LDPRR342_lumd1253_MASK)

#define locald53_LDPRR342_lumd1252_MASK          (0x3FF0000U)
#define locald53_LDPRR342_lumd1252_SHIFT         (16U)
/*! lumd1252 - lumdat_1252 */
#define locald53_LDPRR342_lumd1252(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR342_lumd1252_SHIFT)) & locald53_LDPRR342_lumd1252_MASK)
/*! @} */

/*! @name LDPRR343 - ldprofilereg343 */
/*! @{ */

#define locald53_LDPRR343_lumd1255_MASK          (0x3FFU)
#define locald53_LDPRR343_lumd1255_SHIFT         (0U)
/*! lumd1255 - lumdat_1255 */
#define locald53_LDPRR343_lumd1255(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR343_lumd1255_SHIFT)) & locald53_LDPRR343_lumd1255_MASK)

#define locald53_LDPRR343_lumd1254_MASK          (0x3FF0000U)
#define locald53_LDPRR343_lumd1254_SHIFT         (16U)
/*! lumd1254 - lumdat_1254 */
#define locald53_LDPRR343_lumd1254(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR343_lumd1254_SHIFT)) & locald53_LDPRR343_lumd1254_MASK)
/*! @} */

/*! @name LDPRR344 - ldprofilereg344 */
/*! @{ */

#define locald53_LDPRR344_lumd1257_MASK          (0x3FFU)
#define locald53_LDPRR344_lumd1257_SHIFT         (0U)
/*! lumd1257 - lumdat_1257 */
#define locald53_LDPRR344_lumd1257(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR344_lumd1257_SHIFT)) & locald53_LDPRR344_lumd1257_MASK)

#define locald53_LDPRR344_lumd1256_MASK          (0x3FF0000U)
#define locald53_LDPRR344_lumd1256_SHIFT         (16U)
/*! lumd1256 - lumdat_1256 */
#define locald53_LDPRR344_lumd1256(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR344_lumd1256_SHIFT)) & locald53_LDPRR344_lumd1256_MASK)
/*! @} */

/*! @name LDPRR345 - ldprofilereg345 */
/*! @{ */

#define locald53_LDPRR345_lumd1259_MASK          (0x3FFU)
#define locald53_LDPRR345_lumd1259_SHIFT         (0U)
/*! lumd1259 - lumdat_1259 */
#define locald53_LDPRR345_lumd1259(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR345_lumd1259_SHIFT)) & locald53_LDPRR345_lumd1259_MASK)

#define locald53_LDPRR345_lumd1258_MASK          (0x3FF0000U)
#define locald53_LDPRR345_lumd1258_SHIFT         (16U)
/*! lumd1258 - lumdat_1258 */
#define locald53_LDPRR345_lumd1258(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR345_lumd1258_SHIFT)) & locald53_LDPRR345_lumd1258_MASK)
/*! @} */

/*! @name LDPRR346 - ldprofilereg346 */
/*! @{ */

#define locald53_LDPRR346_lumd1261_MASK          (0x3FFU)
#define locald53_LDPRR346_lumd1261_SHIFT         (0U)
/*! lumd1261 - lumdat_1261 */
#define locald53_LDPRR346_lumd1261(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR346_lumd1261_SHIFT)) & locald53_LDPRR346_lumd1261_MASK)

#define locald53_LDPRR346_lumd1260_MASK          (0x3FF0000U)
#define locald53_LDPRR346_lumd1260_SHIFT         (16U)
/*! lumd1260 - lumdat_1260 */
#define locald53_LDPRR346_lumd1260(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR346_lumd1260_SHIFT)) & locald53_LDPRR346_lumd1260_MASK)
/*! @} */

/*! @name LDPRR347 - ldprofilereg347 */
/*! @{ */

#define locald53_LDPRR347_lumd1263_MASK          (0x3FFU)
#define locald53_LDPRR347_lumd1263_SHIFT         (0U)
/*! lumd1263 - lumdat_1263 */
#define locald53_LDPRR347_lumd1263(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR347_lumd1263_SHIFT)) & locald53_LDPRR347_lumd1263_MASK)

#define locald53_LDPRR347_lumd1262_MASK          (0x3FF0000U)
#define locald53_LDPRR347_lumd1262_SHIFT         (16U)
/*! lumd1262 - lumdat_1262 */
#define locald53_LDPRR347_lumd1262(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR347_lumd1262_SHIFT)) & locald53_LDPRR347_lumd1262_MASK)
/*! @} */

/*! @name LDPRR348 - ldprofilereg348 */
/*! @{ */

#define locald53_LDPRR348_lumd1265_MASK          (0x3FFU)
#define locald53_LDPRR348_lumd1265_SHIFT         (0U)
/*! lumd1265 - lumdat_1265 */
#define locald53_LDPRR348_lumd1265(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR348_lumd1265_SHIFT)) & locald53_LDPRR348_lumd1265_MASK)

#define locald53_LDPRR348_lumd1264_MASK          (0x3FF0000U)
#define locald53_LDPRR348_lumd1264_SHIFT         (16U)
/*! lumd1264 - lumdat_1264 */
#define locald53_LDPRR348_lumd1264(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR348_lumd1264_SHIFT)) & locald53_LDPRR348_lumd1264_MASK)
/*! @} */

/*! @name LDPRR349 - ldprofilereg349 */
/*! @{ */

#define locald53_LDPRR349_lumd1267_MASK          (0x3FFU)
#define locald53_LDPRR349_lumd1267_SHIFT         (0U)
/*! lumd1267 - lumdat_1267 */
#define locald53_LDPRR349_lumd1267(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR349_lumd1267_SHIFT)) & locald53_LDPRR349_lumd1267_MASK)

#define locald53_LDPRR349_lumd1266_MASK          (0x3FF0000U)
#define locald53_LDPRR349_lumd1266_SHIFT         (16U)
/*! lumd1266 - lumdat_1266 */
#define locald53_LDPRR349_lumd1266(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR349_lumd1266_SHIFT)) & locald53_LDPRR349_lumd1266_MASK)
/*! @} */

/*! @name LDPRR34A - ldprofilereg34a */
/*! @{ */

#define locald53_LDPRR34A_lumd1269_MASK          (0x3FFU)
#define locald53_LDPRR34A_lumd1269_SHIFT         (0U)
/*! lumd1269 - lumdat_1269 */
#define locald53_LDPRR34A_lumd1269(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR34A_lumd1269_SHIFT)) & locald53_LDPRR34A_lumd1269_MASK)

#define locald53_LDPRR34A_lumd1268_MASK          (0x3FF0000U)
#define locald53_LDPRR34A_lumd1268_SHIFT         (16U)
/*! lumd1268 - lumdat_1268 */
#define locald53_LDPRR34A_lumd1268(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR34A_lumd1268_SHIFT)) & locald53_LDPRR34A_lumd1268_MASK)
/*! @} */

/*! @name LDPRR34B - ldprofilereg34b */
/*! @{ */

#define locald53_LDPRR34B_lumd1271_MASK          (0x3FFU)
#define locald53_LDPRR34B_lumd1271_SHIFT         (0U)
/*! lumd1271 - lumdat_1271 */
#define locald53_LDPRR34B_lumd1271(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR34B_lumd1271_SHIFT)) & locald53_LDPRR34B_lumd1271_MASK)

#define locald53_LDPRR34B_lumd1270_MASK          (0x3FF0000U)
#define locald53_LDPRR34B_lumd1270_SHIFT         (16U)
/*! lumd1270 - lumdat_1270 */
#define locald53_LDPRR34B_lumd1270(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR34B_lumd1270_SHIFT)) & locald53_LDPRR34B_lumd1270_MASK)
/*! @} */

/*! @name LDPRR34C - ldprofilereg34c */
/*! @{ */

#define locald53_LDPRR34C_lumd1273_MASK          (0x3FFU)
#define locald53_LDPRR34C_lumd1273_SHIFT         (0U)
/*! lumd1273 - lumdat_1273 */
#define locald53_LDPRR34C_lumd1273(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR34C_lumd1273_SHIFT)) & locald53_LDPRR34C_lumd1273_MASK)

#define locald53_LDPRR34C_lumd1272_MASK          (0x3FF0000U)
#define locald53_LDPRR34C_lumd1272_SHIFT         (16U)
/*! lumd1272 - lumdat_1272 */
#define locald53_LDPRR34C_lumd1272(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR34C_lumd1272_SHIFT)) & locald53_LDPRR34C_lumd1272_MASK)
/*! @} */

/*! @name LDPRR34D - ldprofilereg34d */
/*! @{ */

#define locald53_LDPRR34D_lumd1275_MASK          (0x3FFU)
#define locald53_LDPRR34D_lumd1275_SHIFT         (0U)
/*! lumd1275 - lumdat_1275 */
#define locald53_LDPRR34D_lumd1275(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR34D_lumd1275_SHIFT)) & locald53_LDPRR34D_lumd1275_MASK)

#define locald53_LDPRR34D_lumd1274_MASK          (0x3FF0000U)
#define locald53_LDPRR34D_lumd1274_SHIFT         (16U)
/*! lumd1274 - lumdat_1274 */
#define locald53_LDPRR34D_lumd1274(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR34D_lumd1274_SHIFT)) & locald53_LDPRR34D_lumd1274_MASK)
/*! @} */

/*! @name LDPRR34E - ldprofilereg34e */
/*! @{ */

#define locald53_LDPRR34E_lumd1277_MASK          (0x3FFU)
#define locald53_LDPRR34E_lumd1277_SHIFT         (0U)
/*! lumd1277 - lumdat_1277 */
#define locald53_LDPRR34E_lumd1277(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR34E_lumd1277_SHIFT)) & locald53_LDPRR34E_lumd1277_MASK)

#define locald53_LDPRR34E_lumd1276_MASK          (0x3FF0000U)
#define locald53_LDPRR34E_lumd1276_SHIFT         (16U)
/*! lumd1276 - lumdat_1276 */
#define locald53_LDPRR34E_lumd1276(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR34E_lumd1276_SHIFT)) & locald53_LDPRR34E_lumd1276_MASK)
/*! @} */

/*! @name LDPRR34F - ldprofilereg34f */
/*! @{ */

#define locald53_LDPRR34F_lumd1279_MASK          (0x3FFU)
#define locald53_LDPRR34F_lumd1279_SHIFT         (0U)
/*! lumd1279 - lumdat_1279 */
#define locald53_LDPRR34F_lumd1279(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR34F_lumd1279_SHIFT)) & locald53_LDPRR34F_lumd1279_MASK)

#define locald53_LDPRR34F_lumd1278_MASK          (0x3FF0000U)
#define locald53_LDPRR34F_lumd1278_SHIFT         (16U)
/*! lumd1278 - lumdat_1278 */
#define locald53_LDPRR34F_lumd1278(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR34F_lumd1278_SHIFT)) & locald53_LDPRR34F_lumd1278_MASK)
/*! @} */

/*! @name LDPRR350 - ldprofilereg350 */
/*! @{ */

#define locald53_LDPRR350_lumd1281_MASK          (0x3FFU)
#define locald53_LDPRR350_lumd1281_SHIFT         (0U)
/*! lumd1281 - lumdat_1281 */
#define locald53_LDPRR350_lumd1281(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR350_lumd1281_SHIFT)) & locald53_LDPRR350_lumd1281_MASK)

#define locald53_LDPRR350_lumd1280_MASK          (0x3FF0000U)
#define locald53_LDPRR350_lumd1280_SHIFT         (16U)
/*! lumd1280 - lumdat_1280 */
#define locald53_LDPRR350_lumd1280(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR350_lumd1280_SHIFT)) & locald53_LDPRR350_lumd1280_MASK)
/*! @} */

/*! @name LDPRR351 - ldprofilereg351 */
/*! @{ */

#define locald53_LDPRR351_lumd1283_MASK          (0x3FFU)
#define locald53_LDPRR351_lumd1283_SHIFT         (0U)
/*! lumd1283 - lumdat_1283 */
#define locald53_LDPRR351_lumd1283(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR351_lumd1283_SHIFT)) & locald53_LDPRR351_lumd1283_MASK)

#define locald53_LDPRR351_lumd1282_MASK          (0x3FF0000U)
#define locald53_LDPRR351_lumd1282_SHIFT         (16U)
/*! lumd1282 - lumdat_1282 */
#define locald53_LDPRR351_lumd1282(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR351_lumd1282_SHIFT)) & locald53_LDPRR351_lumd1282_MASK)
/*! @} */

/*! @name LDPRR352 - ldprofilereg352 */
/*! @{ */

#define locald53_LDPRR352_lumd1285_MASK          (0x3FFU)
#define locald53_LDPRR352_lumd1285_SHIFT         (0U)
/*! lumd1285 - lumdat_1285 */
#define locald53_LDPRR352_lumd1285(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR352_lumd1285_SHIFT)) & locald53_LDPRR352_lumd1285_MASK)

#define locald53_LDPRR352_lumd1284_MASK          (0x3FF0000U)
#define locald53_LDPRR352_lumd1284_SHIFT         (16U)
/*! lumd1284 - lumdat_1284 */
#define locald53_LDPRR352_lumd1284(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR352_lumd1284_SHIFT)) & locald53_LDPRR352_lumd1284_MASK)
/*! @} */

/*! @name LDPRR353 - ldprofilereg353 */
/*! @{ */

#define locald53_LDPRR353_lumd1287_MASK          (0x3FFU)
#define locald53_LDPRR353_lumd1287_SHIFT         (0U)
/*! lumd1287 - lumdat_1287 */
#define locald53_LDPRR353_lumd1287(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR353_lumd1287_SHIFT)) & locald53_LDPRR353_lumd1287_MASK)

#define locald53_LDPRR353_lumd1286_MASK          (0x3FF0000U)
#define locald53_LDPRR353_lumd1286_SHIFT         (16U)
/*! lumd1286 - lumdat_1286 */
#define locald53_LDPRR353_lumd1286(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR353_lumd1286_SHIFT)) & locald53_LDPRR353_lumd1286_MASK)
/*! @} */

/*! @name LDPRR354 - ldprofilereg354 */
/*! @{ */

#define locald53_LDPRR354_lumd1289_MASK          (0x3FFU)
#define locald53_LDPRR354_lumd1289_SHIFT         (0U)
/*! lumd1289 - lumdat_1289 */
#define locald53_LDPRR354_lumd1289(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR354_lumd1289_SHIFT)) & locald53_LDPRR354_lumd1289_MASK)

#define locald53_LDPRR354_lumd1288_MASK          (0x3FF0000U)
#define locald53_LDPRR354_lumd1288_SHIFT         (16U)
/*! lumd1288 - lumdat_1288 */
#define locald53_LDPRR354_lumd1288(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR354_lumd1288_SHIFT)) & locald53_LDPRR354_lumd1288_MASK)
/*! @} */

/*! @name LDPRR355 - ldprofilereg355 */
/*! @{ */

#define locald53_LDPRR355_lumd1291_MASK          (0x3FFU)
#define locald53_LDPRR355_lumd1291_SHIFT         (0U)
/*! lumd1291 - lumdat_1291 */
#define locald53_LDPRR355_lumd1291(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR355_lumd1291_SHIFT)) & locald53_LDPRR355_lumd1291_MASK)

#define locald53_LDPRR355_lumd1290_MASK          (0x3FF0000U)
#define locald53_LDPRR355_lumd1290_SHIFT         (16U)
/*! lumd1290 - lumdat_1290 */
#define locald53_LDPRR355_lumd1290(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR355_lumd1290_SHIFT)) & locald53_LDPRR355_lumd1290_MASK)
/*! @} */

/*! @name LDPRR356 - ldprofilereg356 */
/*! @{ */

#define locald53_LDPRR356_lumd1293_MASK          (0x3FFU)
#define locald53_LDPRR356_lumd1293_SHIFT         (0U)
/*! lumd1293 - lumdat_1293 */
#define locald53_LDPRR356_lumd1293(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR356_lumd1293_SHIFT)) & locald53_LDPRR356_lumd1293_MASK)

#define locald53_LDPRR356_lumd1292_MASK          (0x3FF0000U)
#define locald53_LDPRR356_lumd1292_SHIFT         (16U)
/*! lumd1292 - lumdat_1292 */
#define locald53_LDPRR356_lumd1292(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR356_lumd1292_SHIFT)) & locald53_LDPRR356_lumd1292_MASK)
/*! @} */

/*! @name LDPRR357 - ldprofilereg357 */
/*! @{ */

#define locald53_LDPRR357_lumd1295_MASK          (0x3FFU)
#define locald53_LDPRR357_lumd1295_SHIFT         (0U)
/*! lumd1295 - lumdat_1295 */
#define locald53_LDPRR357_lumd1295(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR357_lumd1295_SHIFT)) & locald53_LDPRR357_lumd1295_MASK)

#define locald53_LDPRR357_lumd1294_MASK          (0x3FF0000U)
#define locald53_LDPRR357_lumd1294_SHIFT         (16U)
/*! lumd1294 - lumdat_1294 */
#define locald53_LDPRR357_lumd1294(x)            (((uint32_t)(((uint32_t)(x)) << locald53_LDPRR357_lumd1294_SHIFT)) & locald53_LDPRR357_lumd1294_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald53_Register_Masks */


/*!
 * @}
 */ /* end of group locald53_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD53_H_ */

