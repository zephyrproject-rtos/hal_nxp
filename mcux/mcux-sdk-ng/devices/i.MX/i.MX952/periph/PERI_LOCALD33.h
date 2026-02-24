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
**         CMSIS Peripheral Access Layer for locald33
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
 * @file PERI_locald33.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald33
 *
 * CMSIS Peripheral Access Layer for locald33
 */

#if !defined(PERI_LOCALD33_H_)
#define PERI_LOCALD33_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald33 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald33_Peripheral_Access_Layer locald33 Peripheral Access Layer
 * @{
 */

/** locald33 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR0C0;                          /**< ldprofilereg0c0, offset: 0x0 */
  __IO uint32_t LDPRR0C1;                          /**< ldprofilereg0c1, offset: 0x4 */
  __IO uint32_t LDPRR0C2;                          /**< ldprofilereg0c2, offset: 0x8 */
  __IO uint32_t LDPRR0C3;                          /**< ldprofilereg0c3, offset: 0xC */
  __IO uint32_t LDPRR0C4;                          /**< ldprofilereg0c4, offset: 0x10 */
  __IO uint32_t LDPRR0C5;                          /**< ldprofilereg0c5, offset: 0x14 */
  __IO uint32_t LDPRR0C6;                          /**< ldprofilereg0c6, offset: 0x18 */
  __IO uint32_t LDPRR0C7;                          /**< ldprofilereg0c7, offset: 0x1C */
  __IO uint32_t LDPRR0C8;                          /**< ldprofilereg0c8, offset: 0x20 */
  __IO uint32_t LDPRR0C9;                          /**< ldprofilereg0c9, offset: 0x24 */
  __IO uint32_t LDPRR0CA;                          /**< ldprofilereg0ca, offset: 0x28 */
  __IO uint32_t LDPRR0CB;                          /**< ldprofilereg0cb, offset: 0x2C */
  __IO uint32_t LDPRR0CC;                          /**< ldprofilereg0cc, offset: 0x30 */
  __IO uint32_t LDPRR0CD;                          /**< ldprofilereg0cd, offset: 0x34 */
  __IO uint32_t LDPRR0CE;                          /**< ldprofilereg0ce, offset: 0x38 */
  __IO uint32_t LDPRR0CF;                          /**< ldprofilereg0cf, offset: 0x3C */
  __IO uint32_t LDPRR0D0;                          /**< ldprofilereg0d0, offset: 0x40 */
  __IO uint32_t LDPRR0D1;                          /**< ldprofilereg0d1, offset: 0x44 */
  __IO uint32_t LDPRR0D2;                          /**< ldprofilereg0d2, offset: 0x48 */
  __IO uint32_t LDPRR0D3;                          /**< ldprofilereg0d3, offset: 0x4C */
  __IO uint32_t LDPRR0D4;                          /**< ldprofilereg0d4, offset: 0x50 */
  __IO uint32_t LDPRR0D5;                          /**< ldprofilereg0d5, offset: 0x54 */
  __IO uint32_t LDPRR0D6;                          /**< ldprofilereg0d6, offset: 0x58 */
  __IO uint32_t LDPRR0D7;                          /**< ldprofilereg0d7, offset: 0x5C */
} locald33_Type;

/* ----------------------------------------------------------------------------
   -- locald33 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald33_Register_Masks locald33 Register Masks
 * @{
 */

/*! @name LDPRR0C0 - ldprofilereg0c0 */
/*! @{ */

#define locald33_LDPRR0C0_lumd289_MASK           (0x3FFU)
#define locald33_LDPRR0C0_lumd289_SHIFT          (0U)
/*! lumd289 - lumdat_289 */
#define locald33_LDPRR0C0_lumd289(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0C0_lumd289_SHIFT)) & locald33_LDPRR0C0_lumd289_MASK)

#define locald33_LDPRR0C0_lumd288_MASK           (0x3FF0000U)
#define locald33_LDPRR0C0_lumd288_SHIFT          (16U)
/*! lumd288 - lumdat_288 */
#define locald33_LDPRR0C0_lumd288(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0C0_lumd288_SHIFT)) & locald33_LDPRR0C0_lumd288_MASK)
/*! @} */

/*! @name LDPRR0C1 - ldprofilereg0c1 */
/*! @{ */

#define locald33_LDPRR0C1_lumd291_MASK           (0x3FFU)
#define locald33_LDPRR0C1_lumd291_SHIFT          (0U)
/*! lumd291 - lumdat_291 */
#define locald33_LDPRR0C1_lumd291(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0C1_lumd291_SHIFT)) & locald33_LDPRR0C1_lumd291_MASK)

#define locald33_LDPRR0C1_lumd290_MASK           (0x3FF0000U)
#define locald33_LDPRR0C1_lumd290_SHIFT          (16U)
/*! lumd290 - lumdat_290 */
#define locald33_LDPRR0C1_lumd290(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0C1_lumd290_SHIFT)) & locald33_LDPRR0C1_lumd290_MASK)
/*! @} */

/*! @name LDPRR0C2 - ldprofilereg0c2 */
/*! @{ */

#define locald33_LDPRR0C2_lumd293_MASK           (0x3FFU)
#define locald33_LDPRR0C2_lumd293_SHIFT          (0U)
/*! lumd293 - lumdat_293 */
#define locald33_LDPRR0C2_lumd293(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0C2_lumd293_SHIFT)) & locald33_LDPRR0C2_lumd293_MASK)

#define locald33_LDPRR0C2_lumd292_MASK           (0x3FF0000U)
#define locald33_LDPRR0C2_lumd292_SHIFT          (16U)
/*! lumd292 - lumdat_292 */
#define locald33_LDPRR0C2_lumd292(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0C2_lumd292_SHIFT)) & locald33_LDPRR0C2_lumd292_MASK)
/*! @} */

/*! @name LDPRR0C3 - ldprofilereg0c3 */
/*! @{ */

#define locald33_LDPRR0C3_lumd295_MASK           (0x3FFU)
#define locald33_LDPRR0C3_lumd295_SHIFT          (0U)
/*! lumd295 - lumdat_295 */
#define locald33_LDPRR0C3_lumd295(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0C3_lumd295_SHIFT)) & locald33_LDPRR0C3_lumd295_MASK)

#define locald33_LDPRR0C3_lumd294_MASK           (0x3FF0000U)
#define locald33_LDPRR0C3_lumd294_SHIFT          (16U)
/*! lumd294 - lumdat_294 */
#define locald33_LDPRR0C3_lumd294(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0C3_lumd294_SHIFT)) & locald33_LDPRR0C3_lumd294_MASK)
/*! @} */

/*! @name LDPRR0C4 - ldprofilereg0c4 */
/*! @{ */

#define locald33_LDPRR0C4_lumd297_MASK           (0x3FFU)
#define locald33_LDPRR0C4_lumd297_SHIFT          (0U)
/*! lumd297 - lumdat_297 */
#define locald33_LDPRR0C4_lumd297(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0C4_lumd297_SHIFT)) & locald33_LDPRR0C4_lumd297_MASK)

#define locald33_LDPRR0C4_lumd296_MASK           (0x3FF0000U)
#define locald33_LDPRR0C4_lumd296_SHIFT          (16U)
/*! lumd296 - lumdat_296 */
#define locald33_LDPRR0C4_lumd296(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0C4_lumd296_SHIFT)) & locald33_LDPRR0C4_lumd296_MASK)
/*! @} */

/*! @name LDPRR0C5 - ldprofilereg0c5 */
/*! @{ */

#define locald33_LDPRR0C5_lumd299_MASK           (0x3FFU)
#define locald33_LDPRR0C5_lumd299_SHIFT          (0U)
/*! lumd299 - lumdat_299 */
#define locald33_LDPRR0C5_lumd299(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0C5_lumd299_SHIFT)) & locald33_LDPRR0C5_lumd299_MASK)

#define locald33_LDPRR0C5_lumd298_MASK           (0x3FF0000U)
#define locald33_LDPRR0C5_lumd298_SHIFT          (16U)
/*! lumd298 - lumdat_298 */
#define locald33_LDPRR0C5_lumd298(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0C5_lumd298_SHIFT)) & locald33_LDPRR0C5_lumd298_MASK)
/*! @} */

/*! @name LDPRR0C6 - ldprofilereg0c6 */
/*! @{ */

#define locald33_LDPRR0C6_lumd301_MASK           (0x3FFU)
#define locald33_LDPRR0C6_lumd301_SHIFT          (0U)
/*! lumd301 - lumdat_301 */
#define locald33_LDPRR0C6_lumd301(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0C6_lumd301_SHIFT)) & locald33_LDPRR0C6_lumd301_MASK)

#define locald33_LDPRR0C6_lumd300_MASK           (0x3FF0000U)
#define locald33_LDPRR0C6_lumd300_SHIFT          (16U)
/*! lumd300 - lumdat_300 */
#define locald33_LDPRR0C6_lumd300(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0C6_lumd300_SHIFT)) & locald33_LDPRR0C6_lumd300_MASK)
/*! @} */

/*! @name LDPRR0C7 - ldprofilereg0c7 */
/*! @{ */

#define locald33_LDPRR0C7_lumd303_MASK           (0x3FFU)
#define locald33_LDPRR0C7_lumd303_SHIFT          (0U)
/*! lumd303 - lumdat_303 */
#define locald33_LDPRR0C7_lumd303(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0C7_lumd303_SHIFT)) & locald33_LDPRR0C7_lumd303_MASK)

#define locald33_LDPRR0C7_lumd302_MASK           (0x3FF0000U)
#define locald33_LDPRR0C7_lumd302_SHIFT          (16U)
/*! lumd302 - lumdat_302 */
#define locald33_LDPRR0C7_lumd302(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0C7_lumd302_SHIFT)) & locald33_LDPRR0C7_lumd302_MASK)
/*! @} */

/*! @name LDPRR0C8 - ldprofilereg0c8 */
/*! @{ */

#define locald33_LDPRR0C8_lumd305_MASK           (0x3FFU)
#define locald33_LDPRR0C8_lumd305_SHIFT          (0U)
/*! lumd305 - lumdat_305 */
#define locald33_LDPRR0C8_lumd305(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0C8_lumd305_SHIFT)) & locald33_LDPRR0C8_lumd305_MASK)

#define locald33_LDPRR0C8_lumd304_MASK           (0x3FF0000U)
#define locald33_LDPRR0C8_lumd304_SHIFT          (16U)
/*! lumd304 - lumdat_304 */
#define locald33_LDPRR0C8_lumd304(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0C8_lumd304_SHIFT)) & locald33_LDPRR0C8_lumd304_MASK)
/*! @} */

/*! @name LDPRR0C9 - ldprofilereg0c9 */
/*! @{ */

#define locald33_LDPRR0C9_lumd307_MASK           (0x3FFU)
#define locald33_LDPRR0C9_lumd307_SHIFT          (0U)
/*! lumd307 - lumdat_307 */
#define locald33_LDPRR0C9_lumd307(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0C9_lumd307_SHIFT)) & locald33_LDPRR0C9_lumd307_MASK)

#define locald33_LDPRR0C9_lumd306_MASK           (0x3FF0000U)
#define locald33_LDPRR0C9_lumd306_SHIFT          (16U)
/*! lumd306 - lumdat_306 */
#define locald33_LDPRR0C9_lumd306(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0C9_lumd306_SHIFT)) & locald33_LDPRR0C9_lumd306_MASK)
/*! @} */

/*! @name LDPRR0CA - ldprofilereg0ca */
/*! @{ */

#define locald33_LDPRR0CA_lumd309_MASK           (0x3FFU)
#define locald33_LDPRR0CA_lumd309_SHIFT          (0U)
/*! lumd309 - lumdat_309 */
#define locald33_LDPRR0CA_lumd309(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0CA_lumd309_SHIFT)) & locald33_LDPRR0CA_lumd309_MASK)

#define locald33_LDPRR0CA_lumd308_MASK           (0x3FF0000U)
#define locald33_LDPRR0CA_lumd308_SHIFT          (16U)
/*! lumd308 - lumdat_308 */
#define locald33_LDPRR0CA_lumd308(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0CA_lumd308_SHIFT)) & locald33_LDPRR0CA_lumd308_MASK)
/*! @} */

/*! @name LDPRR0CB - ldprofilereg0cb */
/*! @{ */

#define locald33_LDPRR0CB_lumd311_MASK           (0x3FFU)
#define locald33_LDPRR0CB_lumd311_SHIFT          (0U)
/*! lumd311 - lumdat_311 */
#define locald33_LDPRR0CB_lumd311(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0CB_lumd311_SHIFT)) & locald33_LDPRR0CB_lumd311_MASK)

#define locald33_LDPRR0CB_lumd310_MASK           (0x3FF0000U)
#define locald33_LDPRR0CB_lumd310_SHIFT          (16U)
/*! lumd310 - lumdat_310 */
#define locald33_LDPRR0CB_lumd310(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0CB_lumd310_SHIFT)) & locald33_LDPRR0CB_lumd310_MASK)
/*! @} */

/*! @name LDPRR0CC - ldprofilereg0cc */
/*! @{ */

#define locald33_LDPRR0CC_lumd313_MASK           (0x3FFU)
#define locald33_LDPRR0CC_lumd313_SHIFT          (0U)
/*! lumd313 - lumdat_313 */
#define locald33_LDPRR0CC_lumd313(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0CC_lumd313_SHIFT)) & locald33_LDPRR0CC_lumd313_MASK)

#define locald33_LDPRR0CC_lumd312_MASK           (0x3FF0000U)
#define locald33_LDPRR0CC_lumd312_SHIFT          (16U)
/*! lumd312 - lumdat_312 */
#define locald33_LDPRR0CC_lumd312(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0CC_lumd312_SHIFT)) & locald33_LDPRR0CC_lumd312_MASK)
/*! @} */

/*! @name LDPRR0CD - ldprofilereg0cd */
/*! @{ */

#define locald33_LDPRR0CD_lumd315_MASK           (0x3FFU)
#define locald33_LDPRR0CD_lumd315_SHIFT          (0U)
/*! lumd315 - lumdat_315 */
#define locald33_LDPRR0CD_lumd315(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0CD_lumd315_SHIFT)) & locald33_LDPRR0CD_lumd315_MASK)

#define locald33_LDPRR0CD_lumd314_MASK           (0x3FF0000U)
#define locald33_LDPRR0CD_lumd314_SHIFT          (16U)
/*! lumd314 - lumdat_314 */
#define locald33_LDPRR0CD_lumd314(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0CD_lumd314_SHIFT)) & locald33_LDPRR0CD_lumd314_MASK)
/*! @} */

/*! @name LDPRR0CE - ldprofilereg0ce */
/*! @{ */

#define locald33_LDPRR0CE_lumd317_MASK           (0x3FFU)
#define locald33_LDPRR0CE_lumd317_SHIFT          (0U)
/*! lumd317 - lumdat_317 */
#define locald33_LDPRR0CE_lumd317(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0CE_lumd317_SHIFT)) & locald33_LDPRR0CE_lumd317_MASK)

#define locald33_LDPRR0CE_lumd316_MASK           (0x3FF0000U)
#define locald33_LDPRR0CE_lumd316_SHIFT          (16U)
/*! lumd316 - lumdat_316 */
#define locald33_LDPRR0CE_lumd316(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0CE_lumd316_SHIFT)) & locald33_LDPRR0CE_lumd316_MASK)
/*! @} */

/*! @name LDPRR0CF - ldprofilereg0cf */
/*! @{ */

#define locald33_LDPRR0CF_lumd319_MASK           (0x3FFU)
#define locald33_LDPRR0CF_lumd319_SHIFT          (0U)
/*! lumd319 - lumdat_319 */
#define locald33_LDPRR0CF_lumd319(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0CF_lumd319_SHIFT)) & locald33_LDPRR0CF_lumd319_MASK)

#define locald33_LDPRR0CF_lumd318_MASK           (0x3FF0000U)
#define locald33_LDPRR0CF_lumd318_SHIFT          (16U)
/*! lumd318 - lumdat_318 */
#define locald33_LDPRR0CF_lumd318(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0CF_lumd318_SHIFT)) & locald33_LDPRR0CF_lumd318_MASK)
/*! @} */

/*! @name LDPRR0D0 - ldprofilereg0d0 */
/*! @{ */

#define locald33_LDPRR0D0_lumd321_MASK           (0x3FFU)
#define locald33_LDPRR0D0_lumd321_SHIFT          (0U)
/*! lumd321 - lumdat_321 */
#define locald33_LDPRR0D0_lumd321(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0D0_lumd321_SHIFT)) & locald33_LDPRR0D0_lumd321_MASK)

#define locald33_LDPRR0D0_lumd320_MASK           (0x3FF0000U)
#define locald33_LDPRR0D0_lumd320_SHIFT          (16U)
/*! lumd320 - lumdat_320 */
#define locald33_LDPRR0D0_lumd320(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0D0_lumd320_SHIFT)) & locald33_LDPRR0D0_lumd320_MASK)
/*! @} */

/*! @name LDPRR0D1 - ldprofilereg0d1 */
/*! @{ */

#define locald33_LDPRR0D1_lumd323_MASK           (0x3FFU)
#define locald33_LDPRR0D1_lumd323_SHIFT          (0U)
/*! lumd323 - lumdat_323 */
#define locald33_LDPRR0D1_lumd323(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0D1_lumd323_SHIFT)) & locald33_LDPRR0D1_lumd323_MASK)

#define locald33_LDPRR0D1_lumd322_MASK           (0x3FF0000U)
#define locald33_LDPRR0D1_lumd322_SHIFT          (16U)
/*! lumd322 - lumdat_322 */
#define locald33_LDPRR0D1_lumd322(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0D1_lumd322_SHIFT)) & locald33_LDPRR0D1_lumd322_MASK)
/*! @} */

/*! @name LDPRR0D2 - ldprofilereg0d2 */
/*! @{ */

#define locald33_LDPRR0D2_lumd325_MASK           (0x3FFU)
#define locald33_LDPRR0D2_lumd325_SHIFT          (0U)
/*! lumd325 - lumdat_325 */
#define locald33_LDPRR0D2_lumd325(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0D2_lumd325_SHIFT)) & locald33_LDPRR0D2_lumd325_MASK)

#define locald33_LDPRR0D2_lumd324_MASK           (0x3FF0000U)
#define locald33_LDPRR0D2_lumd324_SHIFT          (16U)
/*! lumd324 - lumdat_324 */
#define locald33_LDPRR0D2_lumd324(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0D2_lumd324_SHIFT)) & locald33_LDPRR0D2_lumd324_MASK)
/*! @} */

/*! @name LDPRR0D3 - ldprofilereg0d3 */
/*! @{ */

#define locald33_LDPRR0D3_lumd327_MASK           (0x3FFU)
#define locald33_LDPRR0D3_lumd327_SHIFT          (0U)
/*! lumd327 - lumdat_327 */
#define locald33_LDPRR0D3_lumd327(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0D3_lumd327_SHIFT)) & locald33_LDPRR0D3_lumd327_MASK)

#define locald33_LDPRR0D3_lumd326_MASK           (0x3FF0000U)
#define locald33_LDPRR0D3_lumd326_SHIFT          (16U)
/*! lumd326 - lumdat_326 */
#define locald33_LDPRR0D3_lumd326(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0D3_lumd326_SHIFT)) & locald33_LDPRR0D3_lumd326_MASK)
/*! @} */

/*! @name LDPRR0D4 - ldprofilereg0d4 */
/*! @{ */

#define locald33_LDPRR0D4_lumd329_MASK           (0x3FFU)
#define locald33_LDPRR0D4_lumd329_SHIFT          (0U)
/*! lumd329 - lumdat_329 */
#define locald33_LDPRR0D4_lumd329(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0D4_lumd329_SHIFT)) & locald33_LDPRR0D4_lumd329_MASK)

#define locald33_LDPRR0D4_lumd328_MASK           (0x3FF0000U)
#define locald33_LDPRR0D4_lumd328_SHIFT          (16U)
/*! lumd328 - lumdat_328 */
#define locald33_LDPRR0D4_lumd328(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0D4_lumd328_SHIFT)) & locald33_LDPRR0D4_lumd328_MASK)
/*! @} */

/*! @name LDPRR0D5 - ldprofilereg0d5 */
/*! @{ */

#define locald33_LDPRR0D5_lumd331_MASK           (0x3FFU)
#define locald33_LDPRR0D5_lumd331_SHIFT          (0U)
/*! lumd331 - lumdat_331 */
#define locald33_LDPRR0D5_lumd331(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0D5_lumd331_SHIFT)) & locald33_LDPRR0D5_lumd331_MASK)

#define locald33_LDPRR0D5_lumd330_MASK           (0x3FF0000U)
#define locald33_LDPRR0D5_lumd330_SHIFT          (16U)
/*! lumd330 - lumdat_330 */
#define locald33_LDPRR0D5_lumd330(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0D5_lumd330_SHIFT)) & locald33_LDPRR0D5_lumd330_MASK)
/*! @} */

/*! @name LDPRR0D6 - ldprofilereg0d6 */
/*! @{ */

#define locald33_LDPRR0D6_lumd333_MASK           (0x3FFU)
#define locald33_LDPRR0D6_lumd333_SHIFT          (0U)
/*! lumd333 - lumdat_333 */
#define locald33_LDPRR0D6_lumd333(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0D6_lumd333_SHIFT)) & locald33_LDPRR0D6_lumd333_MASK)

#define locald33_LDPRR0D6_lumd332_MASK           (0x3FF0000U)
#define locald33_LDPRR0D6_lumd332_SHIFT          (16U)
/*! lumd332 - lumdat_332 */
#define locald33_LDPRR0D6_lumd332(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0D6_lumd332_SHIFT)) & locald33_LDPRR0D6_lumd332_MASK)
/*! @} */

/*! @name LDPRR0D7 - ldprofilereg0d7 */
/*! @{ */

#define locald33_LDPRR0D7_lumd335_MASK           (0x3FFU)
#define locald33_LDPRR0D7_lumd335_SHIFT          (0U)
/*! lumd335 - lumdat_335 */
#define locald33_LDPRR0D7_lumd335(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0D7_lumd335_SHIFT)) & locald33_LDPRR0D7_lumd335_MASK)

#define locald33_LDPRR0D7_lumd334_MASK           (0x3FF0000U)
#define locald33_LDPRR0D7_lumd334_SHIFT          (16U)
/*! lumd334 - lumdat_334 */
#define locald33_LDPRR0D7_lumd334(x)             (((uint32_t)(((uint32_t)(x)) << locald33_LDPRR0D7_lumd334_SHIFT)) & locald33_LDPRR0D7_lumd334_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald33_Register_Masks */


/*!
 * @}
 */ /* end of group locald33_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD33_H_ */

