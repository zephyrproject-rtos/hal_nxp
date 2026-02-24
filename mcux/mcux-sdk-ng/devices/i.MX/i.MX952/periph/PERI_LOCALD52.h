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
**         CMSIS Peripheral Access Layer for locald52
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
 * @file PERI_locald52.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald52
 *
 * CMSIS Peripheral Access Layer for locald52
 */

#if !defined(PERI_LOCALD52_H_)
#define PERI_LOCALD52_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald52 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald52_Peripheral_Access_Layer locald52 Peripheral Access Layer
 * @{
 */

/** locald52 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR320;                          /**< ldprofilereg320, offset: 0x0 */
  __IO uint32_t LDPRR321;                          /**< ldprofilereg321, offset: 0x4 */
  __IO uint32_t LDPRR322;                          /**< ldprofilereg322, offset: 0x8 */
  __IO uint32_t LDPRR323;                          /**< ldprofilereg323, offset: 0xC */
  __IO uint32_t LDPRR324;                          /**< ldprofilereg324, offset: 0x10 */
  __IO uint32_t LDPRR325;                          /**< ldprofilereg325, offset: 0x14 */
  __IO uint32_t LDPRR326;                          /**< ldprofilereg326, offset: 0x18 */
  __IO uint32_t LDPRR327;                          /**< ldprofilereg327, offset: 0x1C */
  __IO uint32_t LDPRR328;                          /**< ldprofilereg328, offset: 0x20 */
  __IO uint32_t LDPRR329;                          /**< ldprofilereg329, offset: 0x24 */
  __IO uint32_t LDPRR32A;                          /**< ldprofilereg32a, offset: 0x28 */
  __IO uint32_t LDPRR32B;                          /**< ldprofilereg32b, offset: 0x2C */
  __IO uint32_t LDPRR32C;                          /**< ldprofilereg32c, offset: 0x30 */
  __IO uint32_t LDPRR32D;                          /**< ldprofilereg32d, offset: 0x34 */
  __IO uint32_t LDPRR32E;                          /**< ldprofilereg32e, offset: 0x38 */
  __IO uint32_t LDPRR32F;                          /**< ldprofilereg32f, offset: 0x3C */
  __IO uint32_t LDPRR330;                          /**< ldprofilereg330, offset: 0x40 */
  __IO uint32_t LDPRR331;                          /**< ldprofilereg331, offset: 0x44 */
  __IO uint32_t LDPRR332;                          /**< ldprofilereg332, offset: 0x48 */
  __IO uint32_t LDPRR333;                          /**< ldprofilereg333, offset: 0x4C */
  __IO uint32_t LDPRR334;                          /**< ldprofilereg334, offset: 0x50 */
  __IO uint32_t LDPRR335;                          /**< ldprofilereg335, offset: 0x54 */
  __IO uint32_t LDPRR336;                          /**< ldprofilereg336, offset: 0x58 */
  __IO uint32_t LDPRR337;                          /**< ldprofilereg337, offset: 0x5C */
} locald52_Type;

/* ----------------------------------------------------------------------------
   -- locald52 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald52_Register_Masks locald52 Register Masks
 * @{
 */

/*! @name LDPRR320 - ldprofilereg320 */
/*! @{ */

#define locald52_LDPRR320_lumd1201_MASK          (0x3FFU)
#define locald52_LDPRR320_lumd1201_SHIFT         (0U)
/*! lumd1201 - lumdat_1201 */
#define locald52_LDPRR320_lumd1201(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR320_lumd1201_SHIFT)) & locald52_LDPRR320_lumd1201_MASK)

#define locald52_LDPRR320_lumd1200_MASK          (0x3FF0000U)
#define locald52_LDPRR320_lumd1200_SHIFT         (16U)
/*! lumd1200 - lumdat_1200 */
#define locald52_LDPRR320_lumd1200(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR320_lumd1200_SHIFT)) & locald52_LDPRR320_lumd1200_MASK)
/*! @} */

/*! @name LDPRR321 - ldprofilereg321 */
/*! @{ */

#define locald52_LDPRR321_lumd1203_MASK          (0x3FFU)
#define locald52_LDPRR321_lumd1203_SHIFT         (0U)
/*! lumd1203 - lumdat_1203 */
#define locald52_LDPRR321_lumd1203(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR321_lumd1203_SHIFT)) & locald52_LDPRR321_lumd1203_MASK)

#define locald52_LDPRR321_lumd1202_MASK          (0x3FF0000U)
#define locald52_LDPRR321_lumd1202_SHIFT         (16U)
/*! lumd1202 - lumdat_1202 */
#define locald52_LDPRR321_lumd1202(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR321_lumd1202_SHIFT)) & locald52_LDPRR321_lumd1202_MASK)
/*! @} */

/*! @name LDPRR322 - ldprofilereg322 */
/*! @{ */

#define locald52_LDPRR322_lumd1205_MASK          (0x3FFU)
#define locald52_LDPRR322_lumd1205_SHIFT         (0U)
/*! lumd1205 - lumdat_1205 */
#define locald52_LDPRR322_lumd1205(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR322_lumd1205_SHIFT)) & locald52_LDPRR322_lumd1205_MASK)

#define locald52_LDPRR322_lumd1204_MASK          (0x3FF0000U)
#define locald52_LDPRR322_lumd1204_SHIFT         (16U)
/*! lumd1204 - lumdat_1204 */
#define locald52_LDPRR322_lumd1204(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR322_lumd1204_SHIFT)) & locald52_LDPRR322_lumd1204_MASK)
/*! @} */

/*! @name LDPRR323 - ldprofilereg323 */
/*! @{ */

#define locald52_LDPRR323_lumd1207_MASK          (0x3FFU)
#define locald52_LDPRR323_lumd1207_SHIFT         (0U)
/*! lumd1207 - lumdat_1207 */
#define locald52_LDPRR323_lumd1207(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR323_lumd1207_SHIFT)) & locald52_LDPRR323_lumd1207_MASK)

#define locald52_LDPRR323_lumd1206_MASK          (0x3FF0000U)
#define locald52_LDPRR323_lumd1206_SHIFT         (16U)
/*! lumd1206 - lumdat_1206 */
#define locald52_LDPRR323_lumd1206(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR323_lumd1206_SHIFT)) & locald52_LDPRR323_lumd1206_MASK)
/*! @} */

/*! @name LDPRR324 - ldprofilereg324 */
/*! @{ */

#define locald52_LDPRR324_lumd1209_MASK          (0x3FFU)
#define locald52_LDPRR324_lumd1209_SHIFT         (0U)
/*! lumd1209 - lumdat_1209 */
#define locald52_LDPRR324_lumd1209(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR324_lumd1209_SHIFT)) & locald52_LDPRR324_lumd1209_MASK)

#define locald52_LDPRR324_lumd1208_MASK          (0x3FF0000U)
#define locald52_LDPRR324_lumd1208_SHIFT         (16U)
/*! lumd1208 - lumdat_1208 */
#define locald52_LDPRR324_lumd1208(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR324_lumd1208_SHIFT)) & locald52_LDPRR324_lumd1208_MASK)
/*! @} */

/*! @name LDPRR325 - ldprofilereg325 */
/*! @{ */

#define locald52_LDPRR325_lumd1211_MASK          (0x3FFU)
#define locald52_LDPRR325_lumd1211_SHIFT         (0U)
/*! lumd1211 - lumdat_1211 */
#define locald52_LDPRR325_lumd1211(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR325_lumd1211_SHIFT)) & locald52_LDPRR325_lumd1211_MASK)

#define locald52_LDPRR325_lumd1210_MASK          (0x3FF0000U)
#define locald52_LDPRR325_lumd1210_SHIFT         (16U)
/*! lumd1210 - lumdat_1210 */
#define locald52_LDPRR325_lumd1210(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR325_lumd1210_SHIFT)) & locald52_LDPRR325_lumd1210_MASK)
/*! @} */

/*! @name LDPRR326 - ldprofilereg326 */
/*! @{ */

#define locald52_LDPRR326_lumd1213_MASK          (0x3FFU)
#define locald52_LDPRR326_lumd1213_SHIFT         (0U)
/*! lumd1213 - lumdat_1213 */
#define locald52_LDPRR326_lumd1213(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR326_lumd1213_SHIFT)) & locald52_LDPRR326_lumd1213_MASK)

#define locald52_LDPRR326_lumd1212_MASK          (0x3FF0000U)
#define locald52_LDPRR326_lumd1212_SHIFT         (16U)
/*! lumd1212 - lumdat_1212 */
#define locald52_LDPRR326_lumd1212(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR326_lumd1212_SHIFT)) & locald52_LDPRR326_lumd1212_MASK)
/*! @} */

/*! @name LDPRR327 - ldprofilereg327 */
/*! @{ */

#define locald52_LDPRR327_lumd1215_MASK          (0x3FFU)
#define locald52_LDPRR327_lumd1215_SHIFT         (0U)
/*! lumd1215 - lumdat_1215 */
#define locald52_LDPRR327_lumd1215(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR327_lumd1215_SHIFT)) & locald52_LDPRR327_lumd1215_MASK)

#define locald52_LDPRR327_lumd1214_MASK          (0x3FF0000U)
#define locald52_LDPRR327_lumd1214_SHIFT         (16U)
/*! lumd1214 - lumdat_1214 */
#define locald52_LDPRR327_lumd1214(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR327_lumd1214_SHIFT)) & locald52_LDPRR327_lumd1214_MASK)
/*! @} */

/*! @name LDPRR328 - ldprofilereg328 */
/*! @{ */

#define locald52_LDPRR328_lumd1217_MASK          (0x3FFU)
#define locald52_LDPRR328_lumd1217_SHIFT         (0U)
/*! lumd1217 - lumdat_1217 */
#define locald52_LDPRR328_lumd1217(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR328_lumd1217_SHIFT)) & locald52_LDPRR328_lumd1217_MASK)

#define locald52_LDPRR328_lumd1216_MASK          (0x3FF0000U)
#define locald52_LDPRR328_lumd1216_SHIFT         (16U)
/*! lumd1216 - lumdat_1216 */
#define locald52_LDPRR328_lumd1216(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR328_lumd1216_SHIFT)) & locald52_LDPRR328_lumd1216_MASK)
/*! @} */

/*! @name LDPRR329 - ldprofilereg329 */
/*! @{ */

#define locald52_LDPRR329_lumd1219_MASK          (0x3FFU)
#define locald52_LDPRR329_lumd1219_SHIFT         (0U)
/*! lumd1219 - lumdat_1219 */
#define locald52_LDPRR329_lumd1219(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR329_lumd1219_SHIFT)) & locald52_LDPRR329_lumd1219_MASK)

#define locald52_LDPRR329_lumd1218_MASK          (0x3FF0000U)
#define locald52_LDPRR329_lumd1218_SHIFT         (16U)
/*! lumd1218 - lumdat_1218 */
#define locald52_LDPRR329_lumd1218(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR329_lumd1218_SHIFT)) & locald52_LDPRR329_lumd1218_MASK)
/*! @} */

/*! @name LDPRR32A - ldprofilereg32a */
/*! @{ */

#define locald52_LDPRR32A_lumd1221_MASK          (0x3FFU)
#define locald52_LDPRR32A_lumd1221_SHIFT         (0U)
/*! lumd1221 - lumdat_1221 */
#define locald52_LDPRR32A_lumd1221(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR32A_lumd1221_SHIFT)) & locald52_LDPRR32A_lumd1221_MASK)

#define locald52_LDPRR32A_lumd1220_MASK          (0x3FF0000U)
#define locald52_LDPRR32A_lumd1220_SHIFT         (16U)
/*! lumd1220 - lumdat_1220 */
#define locald52_LDPRR32A_lumd1220(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR32A_lumd1220_SHIFT)) & locald52_LDPRR32A_lumd1220_MASK)
/*! @} */

/*! @name LDPRR32B - ldprofilereg32b */
/*! @{ */

#define locald52_LDPRR32B_lumd1223_MASK          (0x3FFU)
#define locald52_LDPRR32B_lumd1223_SHIFT         (0U)
/*! lumd1223 - lumdat_1223 */
#define locald52_LDPRR32B_lumd1223(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR32B_lumd1223_SHIFT)) & locald52_LDPRR32B_lumd1223_MASK)

#define locald52_LDPRR32B_lumd1222_MASK          (0x3FF0000U)
#define locald52_LDPRR32B_lumd1222_SHIFT         (16U)
/*! lumd1222 - lumdat_1222 */
#define locald52_LDPRR32B_lumd1222(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR32B_lumd1222_SHIFT)) & locald52_LDPRR32B_lumd1222_MASK)
/*! @} */

/*! @name LDPRR32C - ldprofilereg32c */
/*! @{ */

#define locald52_LDPRR32C_lumd1225_MASK          (0x3FFU)
#define locald52_LDPRR32C_lumd1225_SHIFT         (0U)
/*! lumd1225 - lumdat_1225 */
#define locald52_LDPRR32C_lumd1225(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR32C_lumd1225_SHIFT)) & locald52_LDPRR32C_lumd1225_MASK)

#define locald52_LDPRR32C_lumd1224_MASK          (0x3FF0000U)
#define locald52_LDPRR32C_lumd1224_SHIFT         (16U)
/*! lumd1224 - lumdat_1224 */
#define locald52_LDPRR32C_lumd1224(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR32C_lumd1224_SHIFT)) & locald52_LDPRR32C_lumd1224_MASK)
/*! @} */

/*! @name LDPRR32D - ldprofilereg32d */
/*! @{ */

#define locald52_LDPRR32D_lumd1227_MASK          (0x3FFU)
#define locald52_LDPRR32D_lumd1227_SHIFT         (0U)
/*! lumd1227 - lumdat_1227 */
#define locald52_LDPRR32D_lumd1227(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR32D_lumd1227_SHIFT)) & locald52_LDPRR32D_lumd1227_MASK)

#define locald52_LDPRR32D_lumd1226_MASK          (0x3FF0000U)
#define locald52_LDPRR32D_lumd1226_SHIFT         (16U)
/*! lumd1226 - lumdat_1226 */
#define locald52_LDPRR32D_lumd1226(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR32D_lumd1226_SHIFT)) & locald52_LDPRR32D_lumd1226_MASK)
/*! @} */

/*! @name LDPRR32E - ldprofilereg32e */
/*! @{ */

#define locald52_LDPRR32E_lumd1229_MASK          (0x3FFU)
#define locald52_LDPRR32E_lumd1229_SHIFT         (0U)
/*! lumd1229 - lumdat_1229 */
#define locald52_LDPRR32E_lumd1229(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR32E_lumd1229_SHIFT)) & locald52_LDPRR32E_lumd1229_MASK)

#define locald52_LDPRR32E_lumd1228_MASK          (0x3FF0000U)
#define locald52_LDPRR32E_lumd1228_SHIFT         (16U)
/*! lumd1228 - lumdat_1228 */
#define locald52_LDPRR32E_lumd1228(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR32E_lumd1228_SHIFT)) & locald52_LDPRR32E_lumd1228_MASK)
/*! @} */

/*! @name LDPRR32F - ldprofilereg32f */
/*! @{ */

#define locald52_LDPRR32F_lumd1231_MASK          (0x3FFU)
#define locald52_LDPRR32F_lumd1231_SHIFT         (0U)
/*! lumd1231 - lumdat_1231 */
#define locald52_LDPRR32F_lumd1231(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR32F_lumd1231_SHIFT)) & locald52_LDPRR32F_lumd1231_MASK)

#define locald52_LDPRR32F_lumd1230_MASK          (0x3FF0000U)
#define locald52_LDPRR32F_lumd1230_SHIFT         (16U)
/*! lumd1230 - lumdat_1230 */
#define locald52_LDPRR32F_lumd1230(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR32F_lumd1230_SHIFT)) & locald52_LDPRR32F_lumd1230_MASK)
/*! @} */

/*! @name LDPRR330 - ldprofilereg330 */
/*! @{ */

#define locald52_LDPRR330_lumd1233_MASK          (0x3FFU)
#define locald52_LDPRR330_lumd1233_SHIFT         (0U)
/*! lumd1233 - lumdat_1233 */
#define locald52_LDPRR330_lumd1233(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR330_lumd1233_SHIFT)) & locald52_LDPRR330_lumd1233_MASK)

#define locald52_LDPRR330_lumd1232_MASK          (0x3FF0000U)
#define locald52_LDPRR330_lumd1232_SHIFT         (16U)
/*! lumd1232 - lumdat_1232 */
#define locald52_LDPRR330_lumd1232(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR330_lumd1232_SHIFT)) & locald52_LDPRR330_lumd1232_MASK)
/*! @} */

/*! @name LDPRR331 - ldprofilereg331 */
/*! @{ */

#define locald52_LDPRR331_lumd1235_MASK          (0x3FFU)
#define locald52_LDPRR331_lumd1235_SHIFT         (0U)
/*! lumd1235 - lumdat_1235 */
#define locald52_LDPRR331_lumd1235(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR331_lumd1235_SHIFT)) & locald52_LDPRR331_lumd1235_MASK)

#define locald52_LDPRR331_lumd1234_MASK          (0x3FF0000U)
#define locald52_LDPRR331_lumd1234_SHIFT         (16U)
/*! lumd1234 - lumdat_1234 */
#define locald52_LDPRR331_lumd1234(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR331_lumd1234_SHIFT)) & locald52_LDPRR331_lumd1234_MASK)
/*! @} */

/*! @name LDPRR332 - ldprofilereg332 */
/*! @{ */

#define locald52_LDPRR332_lumd1237_MASK          (0x3FFU)
#define locald52_LDPRR332_lumd1237_SHIFT         (0U)
/*! lumd1237 - lumdat_1237 */
#define locald52_LDPRR332_lumd1237(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR332_lumd1237_SHIFT)) & locald52_LDPRR332_lumd1237_MASK)

#define locald52_LDPRR332_lumd1236_MASK          (0x3FF0000U)
#define locald52_LDPRR332_lumd1236_SHIFT         (16U)
/*! lumd1236 - lumdat_1236 */
#define locald52_LDPRR332_lumd1236(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR332_lumd1236_SHIFT)) & locald52_LDPRR332_lumd1236_MASK)
/*! @} */

/*! @name LDPRR333 - ldprofilereg333 */
/*! @{ */

#define locald52_LDPRR333_lumd1239_MASK          (0x3FFU)
#define locald52_LDPRR333_lumd1239_SHIFT         (0U)
/*! lumd1239 - lumdat_1239 */
#define locald52_LDPRR333_lumd1239(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR333_lumd1239_SHIFT)) & locald52_LDPRR333_lumd1239_MASK)

#define locald52_LDPRR333_lumd1238_MASK          (0x3FF0000U)
#define locald52_LDPRR333_lumd1238_SHIFT         (16U)
/*! lumd1238 - lumdat_1238 */
#define locald52_LDPRR333_lumd1238(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR333_lumd1238_SHIFT)) & locald52_LDPRR333_lumd1238_MASK)
/*! @} */

/*! @name LDPRR334 - ldprofilereg334 */
/*! @{ */

#define locald52_LDPRR334_lumd1241_MASK          (0x3FFU)
#define locald52_LDPRR334_lumd1241_SHIFT         (0U)
/*! lumd1241 - lumdat_1241 */
#define locald52_LDPRR334_lumd1241(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR334_lumd1241_SHIFT)) & locald52_LDPRR334_lumd1241_MASK)

#define locald52_LDPRR334_lumd1240_MASK          (0x3FF0000U)
#define locald52_LDPRR334_lumd1240_SHIFT         (16U)
/*! lumd1240 - lumdat_1240 */
#define locald52_LDPRR334_lumd1240(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR334_lumd1240_SHIFT)) & locald52_LDPRR334_lumd1240_MASK)
/*! @} */

/*! @name LDPRR335 - ldprofilereg335 */
/*! @{ */

#define locald52_LDPRR335_lumd1243_MASK          (0x3FFU)
#define locald52_LDPRR335_lumd1243_SHIFT         (0U)
/*! lumd1243 - lumdat_1243 */
#define locald52_LDPRR335_lumd1243(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR335_lumd1243_SHIFT)) & locald52_LDPRR335_lumd1243_MASK)

#define locald52_LDPRR335_lumd1242_MASK          (0x3FF0000U)
#define locald52_LDPRR335_lumd1242_SHIFT         (16U)
/*! lumd1242 - lumdat_1242 */
#define locald52_LDPRR335_lumd1242(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR335_lumd1242_SHIFT)) & locald52_LDPRR335_lumd1242_MASK)
/*! @} */

/*! @name LDPRR336 - ldprofilereg336 */
/*! @{ */

#define locald52_LDPRR336_lumd1245_MASK          (0x3FFU)
#define locald52_LDPRR336_lumd1245_SHIFT         (0U)
/*! lumd1245 - lumdat_1245 */
#define locald52_LDPRR336_lumd1245(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR336_lumd1245_SHIFT)) & locald52_LDPRR336_lumd1245_MASK)

#define locald52_LDPRR336_lumd1244_MASK          (0x3FF0000U)
#define locald52_LDPRR336_lumd1244_SHIFT         (16U)
/*! lumd1244 - lumdat_1244 */
#define locald52_LDPRR336_lumd1244(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR336_lumd1244_SHIFT)) & locald52_LDPRR336_lumd1244_MASK)
/*! @} */

/*! @name LDPRR337 - ldprofilereg337 */
/*! @{ */

#define locald52_LDPRR337_lumd1247_MASK          (0x3FFU)
#define locald52_LDPRR337_lumd1247_SHIFT         (0U)
/*! lumd1247 - lumdat_1247 */
#define locald52_LDPRR337_lumd1247(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR337_lumd1247_SHIFT)) & locald52_LDPRR337_lumd1247_MASK)

#define locald52_LDPRR337_lumd1246_MASK          (0x3FF0000U)
#define locald52_LDPRR337_lumd1246_SHIFT         (16U)
/*! lumd1246 - lumdat_1246 */
#define locald52_LDPRR337_lumd1246(x)            (((uint32_t)(((uint32_t)(x)) << locald52_LDPRR337_lumd1246_SHIFT)) & locald52_LDPRR337_lumd1246_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald52_Register_Masks */


/*!
 * @}
 */ /* end of group locald52_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD52_H_ */

