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
**         CMSIS Peripheral Access Layer for locald73
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
 * @file PERI_locald73.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald73
 *
 * CMSIS Peripheral Access Layer for locald73
 */

#if !defined(PERI_LOCALD73_H_)
#define PERI_LOCALD73_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald73 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald73_Peripheral_Access_Layer locald73 Peripheral Access Layer
 * @{
 */

/** locald73 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR5C0;                          /**< ldprofilereg5c0, offset: 0x0 */
  __IO uint32_t LDPRR5C1;                          /**< ldprofilereg5c1, offset: 0x4 */
  __IO uint32_t LDPRR5C2;                          /**< ldprofilereg5c2, offset: 0x8 */
  __IO uint32_t LDPRR5C3;                          /**< ldprofilereg5c3, offset: 0xC */
  __IO uint32_t LDPRR5C4;                          /**< ldprofilereg5c4, offset: 0x10 */
  __IO uint32_t LDPRR5C5;                          /**< ldprofilereg5c5, offset: 0x14 */
  __IO uint32_t LDPRR5C6;                          /**< ldprofilereg5c6, offset: 0x18 */
  __IO uint32_t LDPRR5C7;                          /**< ldprofilereg5c7, offset: 0x1C */
  __IO uint32_t LDPRR5C8;                          /**< ldprofilereg5c8, offset: 0x20 */
  __IO uint32_t LDPRR5C9;                          /**< ldprofilereg5c9, offset: 0x24 */
  __IO uint32_t LDPRR5CA;                          /**< ldprofilereg5ca, offset: 0x28 */
  __IO uint32_t LDPRR5CB;                          /**< ldprofilereg5cb, offset: 0x2C */
  __IO uint32_t LDPRR5CC;                          /**< ldprofilereg5cc, offset: 0x30 */
  __IO uint32_t LDPRR5CD;                          /**< ldprofilereg5cd, offset: 0x34 */
  __IO uint32_t LDPRR5CE;                          /**< ldprofilereg5ce, offset: 0x38 */
  __IO uint32_t LDPRR5CF;                          /**< ldprofilereg5cf, offset: 0x3C */
  __IO uint32_t LDPRR5D0;                          /**< ldprofilereg5d0, offset: 0x40 */
  __IO uint32_t LDPRR5D1;                          /**< ldprofilereg5d1, offset: 0x44 */
  __IO uint32_t LDPRR5D2;                          /**< ldprofilereg5d2, offset: 0x48 */
  __IO uint32_t LDPRR5D3;                          /**< ldprofilereg5d3, offset: 0x4C */
  __IO uint32_t LDPRR5D4;                          /**< ldprofilereg5d4, offset: 0x50 */
  __IO uint32_t LDPRR5D5;                          /**< ldprofilereg5d5, offset: 0x54 */
  __IO uint32_t LDPRR5D6;                          /**< ldprofilereg5d6, offset: 0x58 */
  __IO uint32_t LDPRR5D7;                          /**< ldprofilereg5d7, offset: 0x5C */
} locald73_Type;

/* ----------------------------------------------------------------------------
   -- locald73 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald73_Register_Masks locald73 Register Masks
 * @{
 */

/*! @name LDPRR5C0 - ldprofilereg5c0 */
/*! @{ */

#define locald73_LDPRR5C0_lumd2209_MASK          (0x3FFU)
#define locald73_LDPRR5C0_lumd2209_SHIFT         (0U)
/*! lumd2209 - lumdat_2209 */
#define locald73_LDPRR5C0_lumd2209(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5C0_lumd2209_SHIFT)) & locald73_LDPRR5C0_lumd2209_MASK)

#define locald73_LDPRR5C0_lumd2208_MASK          (0x3FF0000U)
#define locald73_LDPRR5C0_lumd2208_SHIFT         (16U)
/*! lumd2208 - lumdat_2208 */
#define locald73_LDPRR5C0_lumd2208(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5C0_lumd2208_SHIFT)) & locald73_LDPRR5C0_lumd2208_MASK)
/*! @} */

/*! @name LDPRR5C1 - ldprofilereg5c1 */
/*! @{ */

#define locald73_LDPRR5C1_lumd2211_MASK          (0x3FFU)
#define locald73_LDPRR5C1_lumd2211_SHIFT         (0U)
/*! lumd2211 - lumdat_2211 */
#define locald73_LDPRR5C1_lumd2211(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5C1_lumd2211_SHIFT)) & locald73_LDPRR5C1_lumd2211_MASK)

#define locald73_LDPRR5C1_lumd2210_MASK          (0x3FF0000U)
#define locald73_LDPRR5C1_lumd2210_SHIFT         (16U)
/*! lumd2210 - lumdat_2210 */
#define locald73_LDPRR5C1_lumd2210(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5C1_lumd2210_SHIFT)) & locald73_LDPRR5C1_lumd2210_MASK)
/*! @} */

/*! @name LDPRR5C2 - ldprofilereg5c2 */
/*! @{ */

#define locald73_LDPRR5C2_lumd2213_MASK          (0x3FFU)
#define locald73_LDPRR5C2_lumd2213_SHIFT         (0U)
/*! lumd2213 - lumdat_2213 */
#define locald73_LDPRR5C2_lumd2213(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5C2_lumd2213_SHIFT)) & locald73_LDPRR5C2_lumd2213_MASK)

#define locald73_LDPRR5C2_lumd2212_MASK          (0x3FF0000U)
#define locald73_LDPRR5C2_lumd2212_SHIFT         (16U)
/*! lumd2212 - lumdat_2212 */
#define locald73_LDPRR5C2_lumd2212(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5C2_lumd2212_SHIFT)) & locald73_LDPRR5C2_lumd2212_MASK)
/*! @} */

/*! @name LDPRR5C3 - ldprofilereg5c3 */
/*! @{ */

#define locald73_LDPRR5C3_lumd2215_MASK          (0x3FFU)
#define locald73_LDPRR5C3_lumd2215_SHIFT         (0U)
/*! lumd2215 - lumdat_2215 */
#define locald73_LDPRR5C3_lumd2215(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5C3_lumd2215_SHIFT)) & locald73_LDPRR5C3_lumd2215_MASK)

#define locald73_LDPRR5C3_lumd2214_MASK          (0x3FF0000U)
#define locald73_LDPRR5C3_lumd2214_SHIFT         (16U)
/*! lumd2214 - lumdat_2214 */
#define locald73_LDPRR5C3_lumd2214(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5C3_lumd2214_SHIFT)) & locald73_LDPRR5C3_lumd2214_MASK)
/*! @} */

/*! @name LDPRR5C4 - ldprofilereg5c4 */
/*! @{ */

#define locald73_LDPRR5C4_lumd2217_MASK          (0x3FFU)
#define locald73_LDPRR5C4_lumd2217_SHIFT         (0U)
/*! lumd2217 - lumdat_2217 */
#define locald73_LDPRR5C4_lumd2217(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5C4_lumd2217_SHIFT)) & locald73_LDPRR5C4_lumd2217_MASK)

#define locald73_LDPRR5C4_lumd2216_MASK          (0x3FF0000U)
#define locald73_LDPRR5C4_lumd2216_SHIFT         (16U)
/*! lumd2216 - lumdat_2216 */
#define locald73_LDPRR5C4_lumd2216(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5C4_lumd2216_SHIFT)) & locald73_LDPRR5C4_lumd2216_MASK)
/*! @} */

/*! @name LDPRR5C5 - ldprofilereg5c5 */
/*! @{ */

#define locald73_LDPRR5C5_lumd2219_MASK          (0x3FFU)
#define locald73_LDPRR5C5_lumd2219_SHIFT         (0U)
/*! lumd2219 - lumdat_2219 */
#define locald73_LDPRR5C5_lumd2219(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5C5_lumd2219_SHIFT)) & locald73_LDPRR5C5_lumd2219_MASK)

#define locald73_LDPRR5C5_lumd2218_MASK          (0x3FF0000U)
#define locald73_LDPRR5C5_lumd2218_SHIFT         (16U)
/*! lumd2218 - lumdat_2218 */
#define locald73_LDPRR5C5_lumd2218(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5C5_lumd2218_SHIFT)) & locald73_LDPRR5C5_lumd2218_MASK)
/*! @} */

/*! @name LDPRR5C6 - ldprofilereg5c6 */
/*! @{ */

#define locald73_LDPRR5C6_lumd2221_MASK          (0x3FFU)
#define locald73_LDPRR5C6_lumd2221_SHIFT         (0U)
/*! lumd2221 - lumdat_2221 */
#define locald73_LDPRR5C6_lumd2221(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5C6_lumd2221_SHIFT)) & locald73_LDPRR5C6_lumd2221_MASK)

#define locald73_LDPRR5C6_lumd2220_MASK          (0x3FF0000U)
#define locald73_LDPRR5C6_lumd2220_SHIFT         (16U)
/*! lumd2220 - lumdat_2220 */
#define locald73_LDPRR5C6_lumd2220(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5C6_lumd2220_SHIFT)) & locald73_LDPRR5C6_lumd2220_MASK)
/*! @} */

/*! @name LDPRR5C7 - ldprofilereg5c7 */
/*! @{ */

#define locald73_LDPRR5C7_lumd2223_MASK          (0x3FFU)
#define locald73_LDPRR5C7_lumd2223_SHIFT         (0U)
/*! lumd2223 - lumdat_2223 */
#define locald73_LDPRR5C7_lumd2223(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5C7_lumd2223_SHIFT)) & locald73_LDPRR5C7_lumd2223_MASK)

#define locald73_LDPRR5C7_lumd2222_MASK          (0x3FF0000U)
#define locald73_LDPRR5C7_lumd2222_SHIFT         (16U)
/*! lumd2222 - lumdat_2222 */
#define locald73_LDPRR5C7_lumd2222(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5C7_lumd2222_SHIFT)) & locald73_LDPRR5C7_lumd2222_MASK)
/*! @} */

/*! @name LDPRR5C8 - ldprofilereg5c8 */
/*! @{ */

#define locald73_LDPRR5C8_lumd2225_MASK          (0x3FFU)
#define locald73_LDPRR5C8_lumd2225_SHIFT         (0U)
/*! lumd2225 - lumdat_2225 */
#define locald73_LDPRR5C8_lumd2225(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5C8_lumd2225_SHIFT)) & locald73_LDPRR5C8_lumd2225_MASK)

#define locald73_LDPRR5C8_lumd2224_MASK          (0x3FF0000U)
#define locald73_LDPRR5C8_lumd2224_SHIFT         (16U)
/*! lumd2224 - lumdat_2224 */
#define locald73_LDPRR5C8_lumd2224(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5C8_lumd2224_SHIFT)) & locald73_LDPRR5C8_lumd2224_MASK)
/*! @} */

/*! @name LDPRR5C9 - ldprofilereg5c9 */
/*! @{ */

#define locald73_LDPRR5C9_lumd2227_MASK          (0x3FFU)
#define locald73_LDPRR5C9_lumd2227_SHIFT         (0U)
/*! lumd2227 - lumdat_2227 */
#define locald73_LDPRR5C9_lumd2227(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5C9_lumd2227_SHIFT)) & locald73_LDPRR5C9_lumd2227_MASK)

#define locald73_LDPRR5C9_lumd2226_MASK          (0x3FF0000U)
#define locald73_LDPRR5C9_lumd2226_SHIFT         (16U)
/*! lumd2226 - lumdat_2226 */
#define locald73_LDPRR5C9_lumd2226(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5C9_lumd2226_SHIFT)) & locald73_LDPRR5C9_lumd2226_MASK)
/*! @} */

/*! @name LDPRR5CA - ldprofilereg5ca */
/*! @{ */

#define locald73_LDPRR5CA_lumd2229_MASK          (0x3FFU)
#define locald73_LDPRR5CA_lumd2229_SHIFT         (0U)
/*! lumd2229 - lumdat_2229 */
#define locald73_LDPRR5CA_lumd2229(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5CA_lumd2229_SHIFT)) & locald73_LDPRR5CA_lumd2229_MASK)

#define locald73_LDPRR5CA_lumd2228_MASK          (0x3FF0000U)
#define locald73_LDPRR5CA_lumd2228_SHIFT         (16U)
/*! lumd2228 - lumdat_2228 */
#define locald73_LDPRR5CA_lumd2228(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5CA_lumd2228_SHIFT)) & locald73_LDPRR5CA_lumd2228_MASK)
/*! @} */

/*! @name LDPRR5CB - ldprofilereg5cb */
/*! @{ */

#define locald73_LDPRR5CB_lumd2231_MASK          (0x3FFU)
#define locald73_LDPRR5CB_lumd2231_SHIFT         (0U)
/*! lumd2231 - lumdat_2231 */
#define locald73_LDPRR5CB_lumd2231(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5CB_lumd2231_SHIFT)) & locald73_LDPRR5CB_lumd2231_MASK)

#define locald73_LDPRR5CB_lumd2230_MASK          (0x3FF0000U)
#define locald73_LDPRR5CB_lumd2230_SHIFT         (16U)
/*! lumd2230 - lumdat_2230 */
#define locald73_LDPRR5CB_lumd2230(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5CB_lumd2230_SHIFT)) & locald73_LDPRR5CB_lumd2230_MASK)
/*! @} */

/*! @name LDPRR5CC - ldprofilereg5cc */
/*! @{ */

#define locald73_LDPRR5CC_lumd2233_MASK          (0x3FFU)
#define locald73_LDPRR5CC_lumd2233_SHIFT         (0U)
/*! lumd2233 - lumdat_2233 */
#define locald73_LDPRR5CC_lumd2233(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5CC_lumd2233_SHIFT)) & locald73_LDPRR5CC_lumd2233_MASK)

#define locald73_LDPRR5CC_lumd2232_MASK          (0x3FF0000U)
#define locald73_LDPRR5CC_lumd2232_SHIFT         (16U)
/*! lumd2232 - lumdat_2232 */
#define locald73_LDPRR5CC_lumd2232(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5CC_lumd2232_SHIFT)) & locald73_LDPRR5CC_lumd2232_MASK)
/*! @} */

/*! @name LDPRR5CD - ldprofilereg5cd */
/*! @{ */

#define locald73_LDPRR5CD_lumd2235_MASK          (0x3FFU)
#define locald73_LDPRR5CD_lumd2235_SHIFT         (0U)
/*! lumd2235 - lumdat_2235 */
#define locald73_LDPRR5CD_lumd2235(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5CD_lumd2235_SHIFT)) & locald73_LDPRR5CD_lumd2235_MASK)

#define locald73_LDPRR5CD_lumd2234_MASK          (0x3FF0000U)
#define locald73_LDPRR5CD_lumd2234_SHIFT         (16U)
/*! lumd2234 - lumdat_2234 */
#define locald73_LDPRR5CD_lumd2234(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5CD_lumd2234_SHIFT)) & locald73_LDPRR5CD_lumd2234_MASK)
/*! @} */

/*! @name LDPRR5CE - ldprofilereg5ce */
/*! @{ */

#define locald73_LDPRR5CE_lumd2237_MASK          (0x3FFU)
#define locald73_LDPRR5CE_lumd2237_SHIFT         (0U)
/*! lumd2237 - lumdat_2237 */
#define locald73_LDPRR5CE_lumd2237(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5CE_lumd2237_SHIFT)) & locald73_LDPRR5CE_lumd2237_MASK)

#define locald73_LDPRR5CE_lumd2236_MASK          (0x3FF0000U)
#define locald73_LDPRR5CE_lumd2236_SHIFT         (16U)
/*! lumd2236 - lumdat_2236 */
#define locald73_LDPRR5CE_lumd2236(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5CE_lumd2236_SHIFT)) & locald73_LDPRR5CE_lumd2236_MASK)
/*! @} */

/*! @name LDPRR5CF - ldprofilereg5cf */
/*! @{ */

#define locald73_LDPRR5CF_lumd2239_MASK          (0x3FFU)
#define locald73_LDPRR5CF_lumd2239_SHIFT         (0U)
/*! lumd2239 - lumdat_2239 */
#define locald73_LDPRR5CF_lumd2239(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5CF_lumd2239_SHIFT)) & locald73_LDPRR5CF_lumd2239_MASK)

#define locald73_LDPRR5CF_lumd2238_MASK          (0x3FF0000U)
#define locald73_LDPRR5CF_lumd2238_SHIFT         (16U)
/*! lumd2238 - lumdat_2238 */
#define locald73_LDPRR5CF_lumd2238(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5CF_lumd2238_SHIFT)) & locald73_LDPRR5CF_lumd2238_MASK)
/*! @} */

/*! @name LDPRR5D0 - ldprofilereg5d0 */
/*! @{ */

#define locald73_LDPRR5D0_lumd2241_MASK          (0x3FFU)
#define locald73_LDPRR5D0_lumd2241_SHIFT         (0U)
/*! lumd2241 - lumdat_2241 */
#define locald73_LDPRR5D0_lumd2241(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5D0_lumd2241_SHIFT)) & locald73_LDPRR5D0_lumd2241_MASK)

#define locald73_LDPRR5D0_lumd2240_MASK          (0x3FF0000U)
#define locald73_LDPRR5D0_lumd2240_SHIFT         (16U)
/*! lumd2240 - lumdat_2240 */
#define locald73_LDPRR5D0_lumd2240(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5D0_lumd2240_SHIFT)) & locald73_LDPRR5D0_lumd2240_MASK)
/*! @} */

/*! @name LDPRR5D1 - ldprofilereg5d1 */
/*! @{ */

#define locald73_LDPRR5D1_lumd2243_MASK          (0x3FFU)
#define locald73_LDPRR5D1_lumd2243_SHIFT         (0U)
/*! lumd2243 - lumdat_2243 */
#define locald73_LDPRR5D1_lumd2243(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5D1_lumd2243_SHIFT)) & locald73_LDPRR5D1_lumd2243_MASK)

#define locald73_LDPRR5D1_lumd2242_MASK          (0x3FF0000U)
#define locald73_LDPRR5D1_lumd2242_SHIFT         (16U)
/*! lumd2242 - lumdat_2242 */
#define locald73_LDPRR5D1_lumd2242(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5D1_lumd2242_SHIFT)) & locald73_LDPRR5D1_lumd2242_MASK)
/*! @} */

/*! @name LDPRR5D2 - ldprofilereg5d2 */
/*! @{ */

#define locald73_LDPRR5D2_lumd2245_MASK          (0x3FFU)
#define locald73_LDPRR5D2_lumd2245_SHIFT         (0U)
/*! lumd2245 - lumdat_2245 */
#define locald73_LDPRR5D2_lumd2245(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5D2_lumd2245_SHIFT)) & locald73_LDPRR5D2_lumd2245_MASK)

#define locald73_LDPRR5D2_lumd2244_MASK          (0x3FF0000U)
#define locald73_LDPRR5D2_lumd2244_SHIFT         (16U)
/*! lumd2244 - lumdat_2244 */
#define locald73_LDPRR5D2_lumd2244(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5D2_lumd2244_SHIFT)) & locald73_LDPRR5D2_lumd2244_MASK)
/*! @} */

/*! @name LDPRR5D3 - ldprofilereg5d3 */
/*! @{ */

#define locald73_LDPRR5D3_lumd2247_MASK          (0x3FFU)
#define locald73_LDPRR5D3_lumd2247_SHIFT         (0U)
/*! lumd2247 - lumdat_2247 */
#define locald73_LDPRR5D3_lumd2247(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5D3_lumd2247_SHIFT)) & locald73_LDPRR5D3_lumd2247_MASK)

#define locald73_LDPRR5D3_lumd2246_MASK          (0x3FF0000U)
#define locald73_LDPRR5D3_lumd2246_SHIFT         (16U)
/*! lumd2246 - lumdat_2246 */
#define locald73_LDPRR5D3_lumd2246(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5D3_lumd2246_SHIFT)) & locald73_LDPRR5D3_lumd2246_MASK)
/*! @} */

/*! @name LDPRR5D4 - ldprofilereg5d4 */
/*! @{ */

#define locald73_LDPRR5D4_lumd2249_MASK          (0x3FFU)
#define locald73_LDPRR5D4_lumd2249_SHIFT         (0U)
/*! lumd2249 - lumdat_2249 */
#define locald73_LDPRR5D4_lumd2249(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5D4_lumd2249_SHIFT)) & locald73_LDPRR5D4_lumd2249_MASK)

#define locald73_LDPRR5D4_lumd2248_MASK          (0x3FF0000U)
#define locald73_LDPRR5D4_lumd2248_SHIFT         (16U)
/*! lumd2248 - lumdat_2248 */
#define locald73_LDPRR5D4_lumd2248(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5D4_lumd2248_SHIFT)) & locald73_LDPRR5D4_lumd2248_MASK)
/*! @} */

/*! @name LDPRR5D5 - ldprofilereg5d5 */
/*! @{ */

#define locald73_LDPRR5D5_lumd2251_MASK          (0x3FFU)
#define locald73_LDPRR5D5_lumd2251_SHIFT         (0U)
/*! lumd2251 - lumdat_2251 */
#define locald73_LDPRR5D5_lumd2251(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5D5_lumd2251_SHIFT)) & locald73_LDPRR5D5_lumd2251_MASK)

#define locald73_LDPRR5D5_lumd2250_MASK          (0x3FF0000U)
#define locald73_LDPRR5D5_lumd2250_SHIFT         (16U)
/*! lumd2250 - lumdat_2250 */
#define locald73_LDPRR5D5_lumd2250(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5D5_lumd2250_SHIFT)) & locald73_LDPRR5D5_lumd2250_MASK)
/*! @} */

/*! @name LDPRR5D6 - ldprofilereg5d6 */
/*! @{ */

#define locald73_LDPRR5D6_lumd2253_MASK          (0x3FFU)
#define locald73_LDPRR5D6_lumd2253_SHIFT         (0U)
/*! lumd2253 - lumdat_2253 */
#define locald73_LDPRR5D6_lumd2253(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5D6_lumd2253_SHIFT)) & locald73_LDPRR5D6_lumd2253_MASK)

#define locald73_LDPRR5D6_lumd2252_MASK          (0x3FF0000U)
#define locald73_LDPRR5D6_lumd2252_SHIFT         (16U)
/*! lumd2252 - lumdat_2252 */
#define locald73_LDPRR5D6_lumd2252(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5D6_lumd2252_SHIFT)) & locald73_LDPRR5D6_lumd2252_MASK)
/*! @} */

/*! @name LDPRR5D7 - ldprofilereg5d7 */
/*! @{ */

#define locald73_LDPRR5D7_lumd2255_MASK          (0x3FFU)
#define locald73_LDPRR5D7_lumd2255_SHIFT         (0U)
/*! lumd2255 - lumdat_2255 */
#define locald73_LDPRR5D7_lumd2255(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5D7_lumd2255_SHIFT)) & locald73_LDPRR5D7_lumd2255_MASK)

#define locald73_LDPRR5D7_lumd2254_MASK          (0x3FF0000U)
#define locald73_LDPRR5D7_lumd2254_SHIFT         (16U)
/*! lumd2254 - lumdat_2254 */
#define locald73_LDPRR5D7_lumd2254(x)            (((uint32_t)(((uint32_t)(x)) << locald73_LDPRR5D7_lumd2254_SHIFT)) & locald73_LDPRR5D7_lumd2254_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald73_Register_Masks */


/*!
 * @}
 */ /* end of group locald73_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD73_H_ */

