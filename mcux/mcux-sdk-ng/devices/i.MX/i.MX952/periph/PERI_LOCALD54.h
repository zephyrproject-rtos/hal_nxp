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
**         CMSIS Peripheral Access Layer for locald54
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
 * @file PERI_locald54.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald54
 *
 * CMSIS Peripheral Access Layer for locald54
 */

#if !defined(PERI_LOCALD54_H_)
#define PERI_LOCALD54_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald54 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald54_Peripheral_Access_Layer locald54 Peripheral Access Layer
 * @{
 */

/** locald54 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR360;                          /**< ldprofilereg360, offset: 0x0 */
  __IO uint32_t LDPRR361;                          /**< ldprofilereg361, offset: 0x4 */
  __IO uint32_t LDPRR362;                          /**< ldprofilereg362, offset: 0x8 */
  __IO uint32_t LDPRR363;                          /**< ldprofilereg363, offset: 0xC */
  __IO uint32_t LDPRR364;                          /**< ldprofilereg364, offset: 0x10 */
  __IO uint32_t LDPRR365;                          /**< ldprofilereg365, offset: 0x14 */
  __IO uint32_t LDPRR366;                          /**< ldprofilereg366, offset: 0x18 */
  __IO uint32_t LDPRR367;                          /**< ldprofilereg367, offset: 0x1C */
  __IO uint32_t LDPRR368;                          /**< ldprofilereg368, offset: 0x20 */
  __IO uint32_t LDPRR369;                          /**< ldprofilereg369, offset: 0x24 */
  __IO uint32_t LDPRR36A;                          /**< ldprofilereg36a, offset: 0x28 */
  __IO uint32_t LDPRR36B;                          /**< ldprofilereg36b, offset: 0x2C */
  __IO uint32_t LDPRR36C;                          /**< ldprofilereg36c, offset: 0x30 */
  __IO uint32_t LDPRR36D;                          /**< ldprofilereg36d, offset: 0x34 */
  __IO uint32_t LDPRR36E;                          /**< ldprofilereg36e, offset: 0x38 */
  __IO uint32_t LDPRR36F;                          /**< ldprofilereg36f, offset: 0x3C */
  __IO uint32_t LDPRR370;                          /**< ldprofilereg370, offset: 0x40 */
  __IO uint32_t LDPRR371;                          /**< ldprofilereg371, offset: 0x44 */
  __IO uint32_t LDPRR372;                          /**< ldprofilereg372, offset: 0x48 */
  __IO uint32_t LDPRR373;                          /**< ldprofilereg373, offset: 0x4C */
  __IO uint32_t LDPRR374;                          /**< ldprofilereg374, offset: 0x50 */
  __IO uint32_t LDPRR375;                          /**< ldprofilereg375, offset: 0x54 */
  __IO uint32_t LDPRR376;                          /**< ldprofilereg376, offset: 0x58 */
  __IO uint32_t LDPRR377;                          /**< ldprofilereg377, offset: 0x5C */
} locald54_Type;

/* ----------------------------------------------------------------------------
   -- locald54 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald54_Register_Masks locald54 Register Masks
 * @{
 */

/*! @name LDPRR360 - ldprofilereg360 */
/*! @{ */

#define locald54_LDPRR360_lumd1297_MASK          (0x3FFU)
#define locald54_LDPRR360_lumd1297_SHIFT         (0U)
/*! lumd1297 - lumdat_1297 */
#define locald54_LDPRR360_lumd1297(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR360_lumd1297_SHIFT)) & locald54_LDPRR360_lumd1297_MASK)

#define locald54_LDPRR360_lumd1296_MASK          (0x3FF0000U)
#define locald54_LDPRR360_lumd1296_SHIFT         (16U)
/*! lumd1296 - lumdat_1296 */
#define locald54_LDPRR360_lumd1296(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR360_lumd1296_SHIFT)) & locald54_LDPRR360_lumd1296_MASK)
/*! @} */

/*! @name LDPRR361 - ldprofilereg361 */
/*! @{ */

#define locald54_LDPRR361_lumd1299_MASK          (0x3FFU)
#define locald54_LDPRR361_lumd1299_SHIFT         (0U)
/*! lumd1299 - lumdat_1299 */
#define locald54_LDPRR361_lumd1299(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR361_lumd1299_SHIFT)) & locald54_LDPRR361_lumd1299_MASK)

#define locald54_LDPRR361_lumd1298_MASK          (0x3FF0000U)
#define locald54_LDPRR361_lumd1298_SHIFT         (16U)
/*! lumd1298 - lumdat_1298 */
#define locald54_LDPRR361_lumd1298(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR361_lumd1298_SHIFT)) & locald54_LDPRR361_lumd1298_MASK)
/*! @} */

/*! @name LDPRR362 - ldprofilereg362 */
/*! @{ */

#define locald54_LDPRR362_lumd1301_MASK          (0x3FFU)
#define locald54_LDPRR362_lumd1301_SHIFT         (0U)
/*! lumd1301 - lumdat_1301 */
#define locald54_LDPRR362_lumd1301(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR362_lumd1301_SHIFT)) & locald54_LDPRR362_lumd1301_MASK)

#define locald54_LDPRR362_lumd1300_MASK          (0x3FF0000U)
#define locald54_LDPRR362_lumd1300_SHIFT         (16U)
/*! lumd1300 - lumdat_1300 */
#define locald54_LDPRR362_lumd1300(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR362_lumd1300_SHIFT)) & locald54_LDPRR362_lumd1300_MASK)
/*! @} */

/*! @name LDPRR363 - ldprofilereg363 */
/*! @{ */

#define locald54_LDPRR363_lumd1303_MASK          (0x3FFU)
#define locald54_LDPRR363_lumd1303_SHIFT         (0U)
/*! lumd1303 - lumdat_1303 */
#define locald54_LDPRR363_lumd1303(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR363_lumd1303_SHIFT)) & locald54_LDPRR363_lumd1303_MASK)

#define locald54_LDPRR363_lumd1302_MASK          (0x3FF0000U)
#define locald54_LDPRR363_lumd1302_SHIFT         (16U)
/*! lumd1302 - lumdat_1302 */
#define locald54_LDPRR363_lumd1302(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR363_lumd1302_SHIFT)) & locald54_LDPRR363_lumd1302_MASK)
/*! @} */

/*! @name LDPRR364 - ldprofilereg364 */
/*! @{ */

#define locald54_LDPRR364_lumd1305_MASK          (0x3FFU)
#define locald54_LDPRR364_lumd1305_SHIFT         (0U)
/*! lumd1305 - lumdat_1305 */
#define locald54_LDPRR364_lumd1305(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR364_lumd1305_SHIFT)) & locald54_LDPRR364_lumd1305_MASK)

#define locald54_LDPRR364_lumd1304_MASK          (0x3FF0000U)
#define locald54_LDPRR364_lumd1304_SHIFT         (16U)
/*! lumd1304 - lumdat_1304 */
#define locald54_LDPRR364_lumd1304(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR364_lumd1304_SHIFT)) & locald54_LDPRR364_lumd1304_MASK)
/*! @} */

/*! @name LDPRR365 - ldprofilereg365 */
/*! @{ */

#define locald54_LDPRR365_lumd1307_MASK          (0x3FFU)
#define locald54_LDPRR365_lumd1307_SHIFT         (0U)
/*! lumd1307 - lumdat_1307 */
#define locald54_LDPRR365_lumd1307(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR365_lumd1307_SHIFT)) & locald54_LDPRR365_lumd1307_MASK)

#define locald54_LDPRR365_lumd1306_MASK          (0x3FF0000U)
#define locald54_LDPRR365_lumd1306_SHIFT         (16U)
/*! lumd1306 - lumdat_1306 */
#define locald54_LDPRR365_lumd1306(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR365_lumd1306_SHIFT)) & locald54_LDPRR365_lumd1306_MASK)
/*! @} */

/*! @name LDPRR366 - ldprofilereg366 */
/*! @{ */

#define locald54_LDPRR366_lumd1309_MASK          (0x3FFU)
#define locald54_LDPRR366_lumd1309_SHIFT         (0U)
/*! lumd1309 - lumdat_1309 */
#define locald54_LDPRR366_lumd1309(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR366_lumd1309_SHIFT)) & locald54_LDPRR366_lumd1309_MASK)

#define locald54_LDPRR366_lumd1308_MASK          (0x3FF0000U)
#define locald54_LDPRR366_lumd1308_SHIFT         (16U)
/*! lumd1308 - lumdat_1308 */
#define locald54_LDPRR366_lumd1308(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR366_lumd1308_SHIFT)) & locald54_LDPRR366_lumd1308_MASK)
/*! @} */

/*! @name LDPRR367 - ldprofilereg367 */
/*! @{ */

#define locald54_LDPRR367_lumd1311_MASK          (0x3FFU)
#define locald54_LDPRR367_lumd1311_SHIFT         (0U)
/*! lumd1311 - lumdat_1311 */
#define locald54_LDPRR367_lumd1311(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR367_lumd1311_SHIFT)) & locald54_LDPRR367_lumd1311_MASK)

#define locald54_LDPRR367_lumd1310_MASK          (0x3FF0000U)
#define locald54_LDPRR367_lumd1310_SHIFT         (16U)
/*! lumd1310 - lumdat_1310 */
#define locald54_LDPRR367_lumd1310(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR367_lumd1310_SHIFT)) & locald54_LDPRR367_lumd1310_MASK)
/*! @} */

/*! @name LDPRR368 - ldprofilereg368 */
/*! @{ */

#define locald54_LDPRR368_lumd1313_MASK          (0x3FFU)
#define locald54_LDPRR368_lumd1313_SHIFT         (0U)
/*! lumd1313 - lumdat_1313 */
#define locald54_LDPRR368_lumd1313(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR368_lumd1313_SHIFT)) & locald54_LDPRR368_lumd1313_MASK)

#define locald54_LDPRR368_lumd1312_MASK          (0x3FF0000U)
#define locald54_LDPRR368_lumd1312_SHIFT         (16U)
/*! lumd1312 - lumdat_1312 */
#define locald54_LDPRR368_lumd1312(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR368_lumd1312_SHIFT)) & locald54_LDPRR368_lumd1312_MASK)
/*! @} */

/*! @name LDPRR369 - ldprofilereg369 */
/*! @{ */

#define locald54_LDPRR369_lumd1315_MASK          (0x3FFU)
#define locald54_LDPRR369_lumd1315_SHIFT         (0U)
/*! lumd1315 - lumdat_1315 */
#define locald54_LDPRR369_lumd1315(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR369_lumd1315_SHIFT)) & locald54_LDPRR369_lumd1315_MASK)

#define locald54_LDPRR369_lumd1314_MASK          (0x3FF0000U)
#define locald54_LDPRR369_lumd1314_SHIFT         (16U)
/*! lumd1314 - lumdat_1314 */
#define locald54_LDPRR369_lumd1314(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR369_lumd1314_SHIFT)) & locald54_LDPRR369_lumd1314_MASK)
/*! @} */

/*! @name LDPRR36A - ldprofilereg36a */
/*! @{ */

#define locald54_LDPRR36A_lumd1317_MASK          (0x3FFU)
#define locald54_LDPRR36A_lumd1317_SHIFT         (0U)
/*! lumd1317 - lumdat_1317 */
#define locald54_LDPRR36A_lumd1317(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR36A_lumd1317_SHIFT)) & locald54_LDPRR36A_lumd1317_MASK)

#define locald54_LDPRR36A_lumd1316_MASK          (0x3FF0000U)
#define locald54_LDPRR36A_lumd1316_SHIFT         (16U)
/*! lumd1316 - lumdat_1316 */
#define locald54_LDPRR36A_lumd1316(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR36A_lumd1316_SHIFT)) & locald54_LDPRR36A_lumd1316_MASK)
/*! @} */

/*! @name LDPRR36B - ldprofilereg36b */
/*! @{ */

#define locald54_LDPRR36B_lumd1319_MASK          (0x3FFU)
#define locald54_LDPRR36B_lumd1319_SHIFT         (0U)
/*! lumd1319 - lumdat_1319 */
#define locald54_LDPRR36B_lumd1319(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR36B_lumd1319_SHIFT)) & locald54_LDPRR36B_lumd1319_MASK)

#define locald54_LDPRR36B_lumd1318_MASK          (0x3FF0000U)
#define locald54_LDPRR36B_lumd1318_SHIFT         (16U)
/*! lumd1318 - lumdat_1318 */
#define locald54_LDPRR36B_lumd1318(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR36B_lumd1318_SHIFT)) & locald54_LDPRR36B_lumd1318_MASK)
/*! @} */

/*! @name LDPRR36C - ldprofilereg36c */
/*! @{ */

#define locald54_LDPRR36C_lumd1321_MASK          (0x3FFU)
#define locald54_LDPRR36C_lumd1321_SHIFT         (0U)
/*! lumd1321 - lumdat_1321 */
#define locald54_LDPRR36C_lumd1321(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR36C_lumd1321_SHIFT)) & locald54_LDPRR36C_lumd1321_MASK)

#define locald54_LDPRR36C_lumd1320_MASK          (0x3FF0000U)
#define locald54_LDPRR36C_lumd1320_SHIFT         (16U)
/*! lumd1320 - lumdat_1320 */
#define locald54_LDPRR36C_lumd1320(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR36C_lumd1320_SHIFT)) & locald54_LDPRR36C_lumd1320_MASK)
/*! @} */

/*! @name LDPRR36D - ldprofilereg36d */
/*! @{ */

#define locald54_LDPRR36D_lumd1323_MASK          (0x3FFU)
#define locald54_LDPRR36D_lumd1323_SHIFT         (0U)
/*! lumd1323 - lumdat_1323 */
#define locald54_LDPRR36D_lumd1323(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR36D_lumd1323_SHIFT)) & locald54_LDPRR36D_lumd1323_MASK)

#define locald54_LDPRR36D_lumd1322_MASK          (0x3FF0000U)
#define locald54_LDPRR36D_lumd1322_SHIFT         (16U)
/*! lumd1322 - lumdat_1322 */
#define locald54_LDPRR36D_lumd1322(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR36D_lumd1322_SHIFT)) & locald54_LDPRR36D_lumd1322_MASK)
/*! @} */

/*! @name LDPRR36E - ldprofilereg36e */
/*! @{ */

#define locald54_LDPRR36E_lumd1325_MASK          (0x3FFU)
#define locald54_LDPRR36E_lumd1325_SHIFT         (0U)
/*! lumd1325 - lumdat_1325 */
#define locald54_LDPRR36E_lumd1325(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR36E_lumd1325_SHIFT)) & locald54_LDPRR36E_lumd1325_MASK)

#define locald54_LDPRR36E_lumd1324_MASK          (0x3FF0000U)
#define locald54_LDPRR36E_lumd1324_SHIFT         (16U)
/*! lumd1324 - lumdat_1324 */
#define locald54_LDPRR36E_lumd1324(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR36E_lumd1324_SHIFT)) & locald54_LDPRR36E_lumd1324_MASK)
/*! @} */

/*! @name LDPRR36F - ldprofilereg36f */
/*! @{ */

#define locald54_LDPRR36F_lumd1327_MASK          (0x3FFU)
#define locald54_LDPRR36F_lumd1327_SHIFT         (0U)
/*! lumd1327 - lumdat_1327 */
#define locald54_LDPRR36F_lumd1327(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR36F_lumd1327_SHIFT)) & locald54_LDPRR36F_lumd1327_MASK)

#define locald54_LDPRR36F_lumd1326_MASK          (0x3FF0000U)
#define locald54_LDPRR36F_lumd1326_SHIFT         (16U)
/*! lumd1326 - lumdat_1326 */
#define locald54_LDPRR36F_lumd1326(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR36F_lumd1326_SHIFT)) & locald54_LDPRR36F_lumd1326_MASK)
/*! @} */

/*! @name LDPRR370 - ldprofilereg370 */
/*! @{ */

#define locald54_LDPRR370_lumd1329_MASK          (0x3FFU)
#define locald54_LDPRR370_lumd1329_SHIFT         (0U)
/*! lumd1329 - lumdat_1329 */
#define locald54_LDPRR370_lumd1329(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR370_lumd1329_SHIFT)) & locald54_LDPRR370_lumd1329_MASK)

#define locald54_LDPRR370_lumd1328_MASK          (0x3FF0000U)
#define locald54_LDPRR370_lumd1328_SHIFT         (16U)
/*! lumd1328 - lumdat_1328 */
#define locald54_LDPRR370_lumd1328(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR370_lumd1328_SHIFT)) & locald54_LDPRR370_lumd1328_MASK)
/*! @} */

/*! @name LDPRR371 - ldprofilereg371 */
/*! @{ */

#define locald54_LDPRR371_lumd1331_MASK          (0x3FFU)
#define locald54_LDPRR371_lumd1331_SHIFT         (0U)
/*! lumd1331 - lumdat_1331 */
#define locald54_LDPRR371_lumd1331(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR371_lumd1331_SHIFT)) & locald54_LDPRR371_lumd1331_MASK)

#define locald54_LDPRR371_lumd1330_MASK          (0x3FF0000U)
#define locald54_LDPRR371_lumd1330_SHIFT         (16U)
/*! lumd1330 - lumdat_1330 */
#define locald54_LDPRR371_lumd1330(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR371_lumd1330_SHIFT)) & locald54_LDPRR371_lumd1330_MASK)
/*! @} */

/*! @name LDPRR372 - ldprofilereg372 */
/*! @{ */

#define locald54_LDPRR372_lumd1333_MASK          (0x3FFU)
#define locald54_LDPRR372_lumd1333_SHIFT         (0U)
/*! lumd1333 - lumdat_1333 */
#define locald54_LDPRR372_lumd1333(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR372_lumd1333_SHIFT)) & locald54_LDPRR372_lumd1333_MASK)

#define locald54_LDPRR372_lumd1332_MASK          (0x3FF0000U)
#define locald54_LDPRR372_lumd1332_SHIFT         (16U)
/*! lumd1332 - lumdat_1332 */
#define locald54_LDPRR372_lumd1332(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR372_lumd1332_SHIFT)) & locald54_LDPRR372_lumd1332_MASK)
/*! @} */

/*! @name LDPRR373 - ldprofilereg373 */
/*! @{ */

#define locald54_LDPRR373_lumd1335_MASK          (0x3FFU)
#define locald54_LDPRR373_lumd1335_SHIFT         (0U)
/*! lumd1335 - lumdat_1335 */
#define locald54_LDPRR373_lumd1335(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR373_lumd1335_SHIFT)) & locald54_LDPRR373_lumd1335_MASK)

#define locald54_LDPRR373_lumd1334_MASK          (0x3FF0000U)
#define locald54_LDPRR373_lumd1334_SHIFT         (16U)
/*! lumd1334 - lumdat_1334 */
#define locald54_LDPRR373_lumd1334(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR373_lumd1334_SHIFT)) & locald54_LDPRR373_lumd1334_MASK)
/*! @} */

/*! @name LDPRR374 - ldprofilereg374 */
/*! @{ */

#define locald54_LDPRR374_lumd1337_MASK          (0x3FFU)
#define locald54_LDPRR374_lumd1337_SHIFT         (0U)
/*! lumd1337 - lumdat_1337 */
#define locald54_LDPRR374_lumd1337(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR374_lumd1337_SHIFT)) & locald54_LDPRR374_lumd1337_MASK)

#define locald54_LDPRR374_lumd1336_MASK          (0x3FF0000U)
#define locald54_LDPRR374_lumd1336_SHIFT         (16U)
/*! lumd1336 - lumdat_1336 */
#define locald54_LDPRR374_lumd1336(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR374_lumd1336_SHIFT)) & locald54_LDPRR374_lumd1336_MASK)
/*! @} */

/*! @name LDPRR375 - ldprofilereg375 */
/*! @{ */

#define locald54_LDPRR375_lumd1339_MASK          (0x3FFU)
#define locald54_LDPRR375_lumd1339_SHIFT         (0U)
/*! lumd1339 - lumdat_1339 */
#define locald54_LDPRR375_lumd1339(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR375_lumd1339_SHIFT)) & locald54_LDPRR375_lumd1339_MASK)

#define locald54_LDPRR375_lumd1338_MASK          (0x3FF0000U)
#define locald54_LDPRR375_lumd1338_SHIFT         (16U)
/*! lumd1338 - lumdat_1338 */
#define locald54_LDPRR375_lumd1338(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR375_lumd1338_SHIFT)) & locald54_LDPRR375_lumd1338_MASK)
/*! @} */

/*! @name LDPRR376 - ldprofilereg376 */
/*! @{ */

#define locald54_LDPRR376_lumd1341_MASK          (0x3FFU)
#define locald54_LDPRR376_lumd1341_SHIFT         (0U)
/*! lumd1341 - lumdat_1341 */
#define locald54_LDPRR376_lumd1341(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR376_lumd1341_SHIFT)) & locald54_LDPRR376_lumd1341_MASK)

#define locald54_LDPRR376_lumd1340_MASK          (0x3FF0000U)
#define locald54_LDPRR376_lumd1340_SHIFT         (16U)
/*! lumd1340 - lumdat_1340 */
#define locald54_LDPRR376_lumd1340(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR376_lumd1340_SHIFT)) & locald54_LDPRR376_lumd1340_MASK)
/*! @} */

/*! @name LDPRR377 - ldprofilereg377 */
/*! @{ */

#define locald54_LDPRR377_lumd1343_MASK          (0x3FFU)
#define locald54_LDPRR377_lumd1343_SHIFT         (0U)
/*! lumd1343 - lumdat_1343 */
#define locald54_LDPRR377_lumd1343(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR377_lumd1343_SHIFT)) & locald54_LDPRR377_lumd1343_MASK)

#define locald54_LDPRR377_lumd1342_MASK          (0x3FF0000U)
#define locald54_LDPRR377_lumd1342_SHIFT         (16U)
/*! lumd1342 - lumdat_1342 */
#define locald54_LDPRR377_lumd1342(x)            (((uint32_t)(((uint32_t)(x)) << locald54_LDPRR377_lumd1342_SHIFT)) & locald54_LDPRR377_lumd1342_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald54_Register_Masks */


/*!
 * @}
 */ /* end of group locald54_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD54_H_ */

