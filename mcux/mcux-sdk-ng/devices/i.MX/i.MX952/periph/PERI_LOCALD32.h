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
**         CMSIS Peripheral Access Layer for locald32
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
 * @file PERI_locald32.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald32
 *
 * CMSIS Peripheral Access Layer for locald32
 */

#if !defined(PERI_LOCALD32_H_)
#define PERI_LOCALD32_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald32 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald32_Peripheral_Access_Layer locald32 Peripheral Access Layer
 * @{
 */

/** locald32 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR0A0;                          /**< ldprofilereg0a0, offset: 0x0 */
  __IO uint32_t LDPRR0A1;                          /**< ldprofilereg0a1, offset: 0x4 */
  __IO uint32_t LDPRR0A2;                          /**< ldprofilereg0a2, offset: 0x8 */
  __IO uint32_t LDPRR0A3;                          /**< ldprofilereg0a3, offset: 0xC */
  __IO uint32_t LDPRR0A4;                          /**< ldprofilereg0a4, offset: 0x10 */
  __IO uint32_t LDPRR0A5;                          /**< ldprofilereg0a5, offset: 0x14 */
  __IO uint32_t LDPRR0A6;                          /**< ldprofilereg0a6, offset: 0x18 */
  __IO uint32_t LDPRR0A7;                          /**< ldprofilereg0a7, offset: 0x1C */
  __IO uint32_t LDPRR0A8;                          /**< ldprofilereg0a8, offset: 0x20 */
  __IO uint32_t LDPRR0A9;                          /**< ldprofilereg0a9, offset: 0x24 */
  __IO uint32_t LDPRR0AA;                          /**< ldprofilereg0aa, offset: 0x28 */
  __IO uint32_t LDPRR0AB;                          /**< ldprofilereg0ab, offset: 0x2C */
  __IO uint32_t LDPRR0AC;                          /**< ldprofilereg0ac, offset: 0x30 */
  __IO uint32_t LDPRR0AD;                          /**< ldprofilereg0ad, offset: 0x34 */
  __IO uint32_t LDPRR0AE;                          /**< ldprofilereg0ae, offset: 0x38 */
  __IO uint32_t LDPRR0AF;                          /**< ldprofilereg0af, offset: 0x3C */
  __IO uint32_t LDPRR0B0;                          /**< ldprofilereg0b0, offset: 0x40 */
  __IO uint32_t LDPRR0B1;                          /**< ldprofilereg0b1, offset: 0x44 */
  __IO uint32_t LDPRR0B2;                          /**< ldprofilereg0b2, offset: 0x48 */
  __IO uint32_t LDPRR0B3;                          /**< ldprofilereg0b3, offset: 0x4C */
  __IO uint32_t LDPRR0B4;                          /**< ldprofilereg0b4, offset: 0x50 */
  __IO uint32_t LDPRR0B5;                          /**< ldprofilereg0b5, offset: 0x54 */
  __IO uint32_t LDPRR0B6;                          /**< ldprofilereg0b6, offset: 0x58 */
  __IO uint32_t LDPRR0B7;                          /**< ldprofilereg0b7, offset: 0x5C */
} locald32_Type;

/* ----------------------------------------------------------------------------
   -- locald32 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald32_Register_Masks locald32 Register Masks
 * @{
 */

/*! @name LDPRR0A0 - ldprofilereg0a0 */
/*! @{ */

#define locald32_LDPRR0A0_lumd241_MASK           (0x3FFU)
#define locald32_LDPRR0A0_lumd241_SHIFT          (0U)
/*! lumd241 - lumdat_241 */
#define locald32_LDPRR0A0_lumd241(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0A0_lumd241_SHIFT)) & locald32_LDPRR0A0_lumd241_MASK)

#define locald32_LDPRR0A0_lumd240_MASK           (0x3FF0000U)
#define locald32_LDPRR0A0_lumd240_SHIFT          (16U)
/*! lumd240 - lumdat_240 */
#define locald32_LDPRR0A0_lumd240(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0A0_lumd240_SHIFT)) & locald32_LDPRR0A0_lumd240_MASK)
/*! @} */

/*! @name LDPRR0A1 - ldprofilereg0a1 */
/*! @{ */

#define locald32_LDPRR0A1_lumd243_MASK           (0x3FFU)
#define locald32_LDPRR0A1_lumd243_SHIFT          (0U)
/*! lumd243 - lumdat_243 */
#define locald32_LDPRR0A1_lumd243(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0A1_lumd243_SHIFT)) & locald32_LDPRR0A1_lumd243_MASK)

#define locald32_LDPRR0A1_lumd242_MASK           (0x3FF0000U)
#define locald32_LDPRR0A1_lumd242_SHIFT          (16U)
/*! lumd242 - lumdat_242 */
#define locald32_LDPRR0A1_lumd242(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0A1_lumd242_SHIFT)) & locald32_LDPRR0A1_lumd242_MASK)
/*! @} */

/*! @name LDPRR0A2 - ldprofilereg0a2 */
/*! @{ */

#define locald32_LDPRR0A2_lumd245_MASK           (0x3FFU)
#define locald32_LDPRR0A2_lumd245_SHIFT          (0U)
/*! lumd245 - lumdat_245 */
#define locald32_LDPRR0A2_lumd245(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0A2_lumd245_SHIFT)) & locald32_LDPRR0A2_lumd245_MASK)

#define locald32_LDPRR0A2_lumd244_MASK           (0x3FF0000U)
#define locald32_LDPRR0A2_lumd244_SHIFT          (16U)
/*! lumd244 - lumdat_244 */
#define locald32_LDPRR0A2_lumd244(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0A2_lumd244_SHIFT)) & locald32_LDPRR0A2_lumd244_MASK)
/*! @} */

/*! @name LDPRR0A3 - ldprofilereg0a3 */
/*! @{ */

#define locald32_LDPRR0A3_lumd247_MASK           (0x3FFU)
#define locald32_LDPRR0A3_lumd247_SHIFT          (0U)
/*! lumd247 - lumdat_247 */
#define locald32_LDPRR0A3_lumd247(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0A3_lumd247_SHIFT)) & locald32_LDPRR0A3_lumd247_MASK)

#define locald32_LDPRR0A3_lumd246_MASK           (0x3FF0000U)
#define locald32_LDPRR0A3_lumd246_SHIFT          (16U)
/*! lumd246 - lumdat_246 */
#define locald32_LDPRR0A3_lumd246(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0A3_lumd246_SHIFT)) & locald32_LDPRR0A3_lumd246_MASK)
/*! @} */

/*! @name LDPRR0A4 - ldprofilereg0a4 */
/*! @{ */

#define locald32_LDPRR0A4_lumd249_MASK           (0x3FFU)
#define locald32_LDPRR0A4_lumd249_SHIFT          (0U)
/*! lumd249 - lumdat_249 */
#define locald32_LDPRR0A4_lumd249(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0A4_lumd249_SHIFT)) & locald32_LDPRR0A4_lumd249_MASK)

#define locald32_LDPRR0A4_lumd248_MASK           (0x3FF0000U)
#define locald32_LDPRR0A4_lumd248_SHIFT          (16U)
/*! lumd248 - lumdat_248 */
#define locald32_LDPRR0A4_lumd248(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0A4_lumd248_SHIFT)) & locald32_LDPRR0A4_lumd248_MASK)
/*! @} */

/*! @name LDPRR0A5 - ldprofilereg0a5 */
/*! @{ */

#define locald32_LDPRR0A5_lumd251_MASK           (0x3FFU)
#define locald32_LDPRR0A5_lumd251_SHIFT          (0U)
/*! lumd251 - lumdat_251 */
#define locald32_LDPRR0A5_lumd251(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0A5_lumd251_SHIFT)) & locald32_LDPRR0A5_lumd251_MASK)

#define locald32_LDPRR0A5_lumd250_MASK           (0x3FF0000U)
#define locald32_LDPRR0A5_lumd250_SHIFT          (16U)
/*! lumd250 - lumdat_250 */
#define locald32_LDPRR0A5_lumd250(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0A5_lumd250_SHIFT)) & locald32_LDPRR0A5_lumd250_MASK)
/*! @} */

/*! @name LDPRR0A6 - ldprofilereg0a6 */
/*! @{ */

#define locald32_LDPRR0A6_lumd253_MASK           (0x3FFU)
#define locald32_LDPRR0A6_lumd253_SHIFT          (0U)
/*! lumd253 - lumdat_253 */
#define locald32_LDPRR0A6_lumd253(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0A6_lumd253_SHIFT)) & locald32_LDPRR0A6_lumd253_MASK)

#define locald32_LDPRR0A6_lumd252_MASK           (0x3FF0000U)
#define locald32_LDPRR0A6_lumd252_SHIFT          (16U)
/*! lumd252 - lumdat_252 */
#define locald32_LDPRR0A6_lumd252(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0A6_lumd252_SHIFT)) & locald32_LDPRR0A6_lumd252_MASK)
/*! @} */

/*! @name LDPRR0A7 - ldprofilereg0a7 */
/*! @{ */

#define locald32_LDPRR0A7_lumd255_MASK           (0x3FFU)
#define locald32_LDPRR0A7_lumd255_SHIFT          (0U)
/*! lumd255 - lumdat_255 */
#define locald32_LDPRR0A7_lumd255(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0A7_lumd255_SHIFT)) & locald32_LDPRR0A7_lumd255_MASK)

#define locald32_LDPRR0A7_lumd254_MASK           (0x3FF0000U)
#define locald32_LDPRR0A7_lumd254_SHIFT          (16U)
/*! lumd254 - lumdat_254 */
#define locald32_LDPRR0A7_lumd254(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0A7_lumd254_SHIFT)) & locald32_LDPRR0A7_lumd254_MASK)
/*! @} */

/*! @name LDPRR0A8 - ldprofilereg0a8 */
/*! @{ */

#define locald32_LDPRR0A8_lumd257_MASK           (0x3FFU)
#define locald32_LDPRR0A8_lumd257_SHIFT          (0U)
/*! lumd257 - lumdat_257 */
#define locald32_LDPRR0A8_lumd257(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0A8_lumd257_SHIFT)) & locald32_LDPRR0A8_lumd257_MASK)

#define locald32_LDPRR0A8_lumd256_MASK           (0x3FF0000U)
#define locald32_LDPRR0A8_lumd256_SHIFT          (16U)
/*! lumd256 - lumdat_256 */
#define locald32_LDPRR0A8_lumd256(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0A8_lumd256_SHIFT)) & locald32_LDPRR0A8_lumd256_MASK)
/*! @} */

/*! @name LDPRR0A9 - ldprofilereg0a9 */
/*! @{ */

#define locald32_LDPRR0A9_lumd259_MASK           (0x3FFU)
#define locald32_LDPRR0A9_lumd259_SHIFT          (0U)
/*! lumd259 - lumdat_259 */
#define locald32_LDPRR0A9_lumd259(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0A9_lumd259_SHIFT)) & locald32_LDPRR0A9_lumd259_MASK)

#define locald32_LDPRR0A9_lumd258_MASK           (0x3FF0000U)
#define locald32_LDPRR0A9_lumd258_SHIFT          (16U)
/*! lumd258 - lumdat_258 */
#define locald32_LDPRR0A9_lumd258(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0A9_lumd258_SHIFT)) & locald32_LDPRR0A9_lumd258_MASK)
/*! @} */

/*! @name LDPRR0AA - ldprofilereg0aa */
/*! @{ */

#define locald32_LDPRR0AA_lumd261_MASK           (0x3FFU)
#define locald32_LDPRR0AA_lumd261_SHIFT          (0U)
/*! lumd261 - lumdat_261 */
#define locald32_LDPRR0AA_lumd261(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0AA_lumd261_SHIFT)) & locald32_LDPRR0AA_lumd261_MASK)

#define locald32_LDPRR0AA_lumd260_MASK           (0x3FF0000U)
#define locald32_LDPRR0AA_lumd260_SHIFT          (16U)
/*! lumd260 - lumdat_260 */
#define locald32_LDPRR0AA_lumd260(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0AA_lumd260_SHIFT)) & locald32_LDPRR0AA_lumd260_MASK)
/*! @} */

/*! @name LDPRR0AB - ldprofilereg0ab */
/*! @{ */

#define locald32_LDPRR0AB_lumd263_MASK           (0x3FFU)
#define locald32_LDPRR0AB_lumd263_SHIFT          (0U)
/*! lumd263 - lumdat_263 */
#define locald32_LDPRR0AB_lumd263(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0AB_lumd263_SHIFT)) & locald32_LDPRR0AB_lumd263_MASK)

#define locald32_LDPRR0AB_lumd262_MASK           (0x3FF0000U)
#define locald32_LDPRR0AB_lumd262_SHIFT          (16U)
/*! lumd262 - lumdat_262 */
#define locald32_LDPRR0AB_lumd262(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0AB_lumd262_SHIFT)) & locald32_LDPRR0AB_lumd262_MASK)
/*! @} */

/*! @name LDPRR0AC - ldprofilereg0ac */
/*! @{ */

#define locald32_LDPRR0AC_lumd265_MASK           (0x3FFU)
#define locald32_LDPRR0AC_lumd265_SHIFT          (0U)
/*! lumd265 - lumdat_265 */
#define locald32_LDPRR0AC_lumd265(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0AC_lumd265_SHIFT)) & locald32_LDPRR0AC_lumd265_MASK)

#define locald32_LDPRR0AC_lumd264_MASK           (0x3FF0000U)
#define locald32_LDPRR0AC_lumd264_SHIFT          (16U)
/*! lumd264 - lumdat_264 */
#define locald32_LDPRR0AC_lumd264(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0AC_lumd264_SHIFT)) & locald32_LDPRR0AC_lumd264_MASK)
/*! @} */

/*! @name LDPRR0AD - ldprofilereg0ad */
/*! @{ */

#define locald32_LDPRR0AD_lumd267_MASK           (0x3FFU)
#define locald32_LDPRR0AD_lumd267_SHIFT          (0U)
/*! lumd267 - lumdat_267 */
#define locald32_LDPRR0AD_lumd267(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0AD_lumd267_SHIFT)) & locald32_LDPRR0AD_lumd267_MASK)

#define locald32_LDPRR0AD_lumd266_MASK           (0x3FF0000U)
#define locald32_LDPRR0AD_lumd266_SHIFT          (16U)
/*! lumd266 - lumdat_266 */
#define locald32_LDPRR0AD_lumd266(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0AD_lumd266_SHIFT)) & locald32_LDPRR0AD_lumd266_MASK)
/*! @} */

/*! @name LDPRR0AE - ldprofilereg0ae */
/*! @{ */

#define locald32_LDPRR0AE_lumd269_MASK           (0x3FFU)
#define locald32_LDPRR0AE_lumd269_SHIFT          (0U)
/*! lumd269 - lumdat_269 */
#define locald32_LDPRR0AE_lumd269(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0AE_lumd269_SHIFT)) & locald32_LDPRR0AE_lumd269_MASK)

#define locald32_LDPRR0AE_lumd268_MASK           (0x3FF0000U)
#define locald32_LDPRR0AE_lumd268_SHIFT          (16U)
/*! lumd268 - lumdat_268 */
#define locald32_LDPRR0AE_lumd268(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0AE_lumd268_SHIFT)) & locald32_LDPRR0AE_lumd268_MASK)
/*! @} */

/*! @name LDPRR0AF - ldprofilereg0af */
/*! @{ */

#define locald32_LDPRR0AF_lumd271_MASK           (0x3FFU)
#define locald32_LDPRR0AF_lumd271_SHIFT          (0U)
/*! lumd271 - lumdat_271 */
#define locald32_LDPRR0AF_lumd271(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0AF_lumd271_SHIFT)) & locald32_LDPRR0AF_lumd271_MASK)

#define locald32_LDPRR0AF_lumd270_MASK           (0x3FF0000U)
#define locald32_LDPRR0AF_lumd270_SHIFT          (16U)
/*! lumd270 - lumdat_270 */
#define locald32_LDPRR0AF_lumd270(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0AF_lumd270_SHIFT)) & locald32_LDPRR0AF_lumd270_MASK)
/*! @} */

/*! @name LDPRR0B0 - ldprofilereg0b0 */
/*! @{ */

#define locald32_LDPRR0B0_lumd273_MASK           (0x3FFU)
#define locald32_LDPRR0B0_lumd273_SHIFT          (0U)
/*! lumd273 - lumdat_273 */
#define locald32_LDPRR0B0_lumd273(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0B0_lumd273_SHIFT)) & locald32_LDPRR0B0_lumd273_MASK)

#define locald32_LDPRR0B0_lumd272_MASK           (0x3FF0000U)
#define locald32_LDPRR0B0_lumd272_SHIFT          (16U)
/*! lumd272 - lumdat_272 */
#define locald32_LDPRR0B0_lumd272(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0B0_lumd272_SHIFT)) & locald32_LDPRR0B0_lumd272_MASK)
/*! @} */

/*! @name LDPRR0B1 - ldprofilereg0b1 */
/*! @{ */

#define locald32_LDPRR0B1_lumd275_MASK           (0x3FFU)
#define locald32_LDPRR0B1_lumd275_SHIFT          (0U)
/*! lumd275 - lumdat_275 */
#define locald32_LDPRR0B1_lumd275(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0B1_lumd275_SHIFT)) & locald32_LDPRR0B1_lumd275_MASK)

#define locald32_LDPRR0B1_lumd274_MASK           (0x3FF0000U)
#define locald32_LDPRR0B1_lumd274_SHIFT          (16U)
/*! lumd274 - lumdat_274 */
#define locald32_LDPRR0B1_lumd274(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0B1_lumd274_SHIFT)) & locald32_LDPRR0B1_lumd274_MASK)
/*! @} */

/*! @name LDPRR0B2 - ldprofilereg0b2 */
/*! @{ */

#define locald32_LDPRR0B2_lumd277_MASK           (0x3FFU)
#define locald32_LDPRR0B2_lumd277_SHIFT          (0U)
/*! lumd277 - lumdat_277 */
#define locald32_LDPRR0B2_lumd277(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0B2_lumd277_SHIFT)) & locald32_LDPRR0B2_lumd277_MASK)

#define locald32_LDPRR0B2_lumd276_MASK           (0x3FF0000U)
#define locald32_LDPRR0B2_lumd276_SHIFT          (16U)
/*! lumd276 - lumdat_276 */
#define locald32_LDPRR0B2_lumd276(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0B2_lumd276_SHIFT)) & locald32_LDPRR0B2_lumd276_MASK)
/*! @} */

/*! @name LDPRR0B3 - ldprofilereg0b3 */
/*! @{ */

#define locald32_LDPRR0B3_lumd279_MASK           (0x3FFU)
#define locald32_LDPRR0B3_lumd279_SHIFT          (0U)
/*! lumd279 - lumdat_279 */
#define locald32_LDPRR0B3_lumd279(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0B3_lumd279_SHIFT)) & locald32_LDPRR0B3_lumd279_MASK)

#define locald32_LDPRR0B3_lumd278_MASK           (0x3FF0000U)
#define locald32_LDPRR0B3_lumd278_SHIFT          (16U)
/*! lumd278 - lumdat_278 */
#define locald32_LDPRR0B3_lumd278(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0B3_lumd278_SHIFT)) & locald32_LDPRR0B3_lumd278_MASK)
/*! @} */

/*! @name LDPRR0B4 - ldprofilereg0b4 */
/*! @{ */

#define locald32_LDPRR0B4_lumd281_MASK           (0x3FFU)
#define locald32_LDPRR0B4_lumd281_SHIFT          (0U)
/*! lumd281 - lumdat_281 */
#define locald32_LDPRR0B4_lumd281(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0B4_lumd281_SHIFT)) & locald32_LDPRR0B4_lumd281_MASK)

#define locald32_LDPRR0B4_lumd280_MASK           (0x3FF0000U)
#define locald32_LDPRR0B4_lumd280_SHIFT          (16U)
/*! lumd280 - lumdat_280 */
#define locald32_LDPRR0B4_lumd280(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0B4_lumd280_SHIFT)) & locald32_LDPRR0B4_lumd280_MASK)
/*! @} */

/*! @name LDPRR0B5 - ldprofilereg0b5 */
/*! @{ */

#define locald32_LDPRR0B5_lumd283_MASK           (0x3FFU)
#define locald32_LDPRR0B5_lumd283_SHIFT          (0U)
/*! lumd283 - lumdat_283 */
#define locald32_LDPRR0B5_lumd283(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0B5_lumd283_SHIFT)) & locald32_LDPRR0B5_lumd283_MASK)

#define locald32_LDPRR0B5_lumd282_MASK           (0x3FF0000U)
#define locald32_LDPRR0B5_lumd282_SHIFT          (16U)
/*! lumd282 - lumdat_282 */
#define locald32_LDPRR0B5_lumd282(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0B5_lumd282_SHIFT)) & locald32_LDPRR0B5_lumd282_MASK)
/*! @} */

/*! @name LDPRR0B6 - ldprofilereg0b6 */
/*! @{ */

#define locald32_LDPRR0B6_lumd285_MASK           (0x3FFU)
#define locald32_LDPRR0B6_lumd285_SHIFT          (0U)
/*! lumd285 - lumdat_285 */
#define locald32_LDPRR0B6_lumd285(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0B6_lumd285_SHIFT)) & locald32_LDPRR0B6_lumd285_MASK)

#define locald32_LDPRR0B6_lumd284_MASK           (0x3FF0000U)
#define locald32_LDPRR0B6_lumd284_SHIFT          (16U)
/*! lumd284 - lumdat_284 */
#define locald32_LDPRR0B6_lumd284(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0B6_lumd284_SHIFT)) & locald32_LDPRR0B6_lumd284_MASK)
/*! @} */

/*! @name LDPRR0B7 - ldprofilereg0b7 */
/*! @{ */

#define locald32_LDPRR0B7_lumd287_MASK           (0x3FFU)
#define locald32_LDPRR0B7_lumd287_SHIFT          (0U)
/*! lumd287 - lumdat_287 */
#define locald32_LDPRR0B7_lumd287(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0B7_lumd287_SHIFT)) & locald32_LDPRR0B7_lumd287_MASK)

#define locald32_LDPRR0B7_lumd286_MASK           (0x3FF0000U)
#define locald32_LDPRR0B7_lumd286_SHIFT          (16U)
/*! lumd286 - lumdat_286 */
#define locald32_LDPRR0B7_lumd286(x)             (((uint32_t)(((uint32_t)(x)) << locald32_LDPRR0B7_lumd286_SHIFT)) & locald32_LDPRR0B7_lumd286_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald32_Register_Masks */


/*!
 * @}
 */ /* end of group locald32_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD32_H_ */

