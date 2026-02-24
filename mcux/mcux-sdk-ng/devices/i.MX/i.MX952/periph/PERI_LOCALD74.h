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
**         CMSIS Peripheral Access Layer for locald74
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
 * @file PERI_locald74.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald74
 *
 * CMSIS Peripheral Access Layer for locald74
 */

#if !defined(PERI_LOCALD74_H_)
#define PERI_LOCALD74_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald74 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald74_Peripheral_Access_Layer locald74 Peripheral Access Layer
 * @{
 */

/** locald74 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR5E0;                          /**< ldprofilereg5e0, offset: 0x0 */
  __IO uint32_t LDPRR5E1;                          /**< ldprofilereg5e1, offset: 0x4 */
  __IO uint32_t LDPRR5E2;                          /**< ldprofilereg5e2, offset: 0x8 */
  __IO uint32_t LDPRR5E3;                          /**< ldprofilereg5e3, offset: 0xC */
  __IO uint32_t LDPRR5E4;                          /**< ldprofilereg5e4, offset: 0x10 */
  __IO uint32_t LDPRR5E5;                          /**< ldprofilereg5e5, offset: 0x14 */
  __IO uint32_t LDPRR5E6;                          /**< ldprofilereg5e6, offset: 0x18 */
  __IO uint32_t LDPRR5E7;                          /**< ldprofilereg5e7, offset: 0x1C */
  __IO uint32_t LDPRR5E8;                          /**< ldprofilereg5e8, offset: 0x20 */
  __IO uint32_t LDPRR5E9;                          /**< ldprofilereg5e9, offset: 0x24 */
  __IO uint32_t LDPRR5EA;                          /**< ldprofilereg5ea, offset: 0x28 */
  __IO uint32_t LDPRR5EB;                          /**< ldprofilereg5eb, offset: 0x2C */
  __IO uint32_t LDPRR5EC;                          /**< ldprofilereg5ec, offset: 0x30 */
  __IO uint32_t LDPRR5ED;                          /**< ldprofilereg5ed, offset: 0x34 */
  __IO uint32_t LDPRR5EE;                          /**< ldprofilereg5ee, offset: 0x38 */
  __IO uint32_t LDPRR5EF;                          /**< ldprofilereg5ef, offset: 0x3C */
  __IO uint32_t LDPRR5F0;                          /**< ldprofilereg5f0, offset: 0x40 */
  __IO uint32_t LDPRR5F1;                          /**< ldprofilereg5f1, offset: 0x44 */
  __IO uint32_t LDPRR5F2;                          /**< ldprofilereg5f2, offset: 0x48 */
  __IO uint32_t LDPRR5F3;                          /**< ldprofilereg5f3, offset: 0x4C */
  __IO uint32_t LDPRR5F4;                          /**< ldprofilereg5f4, offset: 0x50 */
  __IO uint32_t LDPRR5F5;                          /**< ldprofilereg5f5, offset: 0x54 */
  __IO uint32_t LDPRR5F6;                          /**< ldprofilereg5f6, offset: 0x58 */
  __IO uint32_t LDPRR5F7;                          /**< ldprofilereg5f7, offset: 0x5C */
} locald74_Type;

/* ----------------------------------------------------------------------------
   -- locald74 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald74_Register_Masks locald74 Register Masks
 * @{
 */

/*! @name LDPRR5E0 - ldprofilereg5e0 */
/*! @{ */

#define locald74_LDPRR5E0_lumd2257_MASK          (0x3FFU)
#define locald74_LDPRR5E0_lumd2257_SHIFT         (0U)
/*! lumd2257 - lumdat_2257 */
#define locald74_LDPRR5E0_lumd2257(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5E0_lumd2257_SHIFT)) & locald74_LDPRR5E0_lumd2257_MASK)

#define locald74_LDPRR5E0_lumd2256_MASK          (0x3FF0000U)
#define locald74_LDPRR5E0_lumd2256_SHIFT         (16U)
/*! lumd2256 - lumdat_2256 */
#define locald74_LDPRR5E0_lumd2256(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5E0_lumd2256_SHIFT)) & locald74_LDPRR5E0_lumd2256_MASK)
/*! @} */

/*! @name LDPRR5E1 - ldprofilereg5e1 */
/*! @{ */

#define locald74_LDPRR5E1_lumd2259_MASK          (0x3FFU)
#define locald74_LDPRR5E1_lumd2259_SHIFT         (0U)
/*! lumd2259 - lumdat_2259 */
#define locald74_LDPRR5E1_lumd2259(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5E1_lumd2259_SHIFT)) & locald74_LDPRR5E1_lumd2259_MASK)

#define locald74_LDPRR5E1_lumd2258_MASK          (0x3FF0000U)
#define locald74_LDPRR5E1_lumd2258_SHIFT         (16U)
/*! lumd2258 - lumdat_2258 */
#define locald74_LDPRR5E1_lumd2258(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5E1_lumd2258_SHIFT)) & locald74_LDPRR5E1_lumd2258_MASK)
/*! @} */

/*! @name LDPRR5E2 - ldprofilereg5e2 */
/*! @{ */

#define locald74_LDPRR5E2_lumd2261_MASK          (0x3FFU)
#define locald74_LDPRR5E2_lumd2261_SHIFT         (0U)
/*! lumd2261 - lumdat_2261 */
#define locald74_LDPRR5E2_lumd2261(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5E2_lumd2261_SHIFT)) & locald74_LDPRR5E2_lumd2261_MASK)

#define locald74_LDPRR5E2_lumd2260_MASK          (0x3FF0000U)
#define locald74_LDPRR5E2_lumd2260_SHIFT         (16U)
/*! lumd2260 - lumdat_2260 */
#define locald74_LDPRR5E2_lumd2260(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5E2_lumd2260_SHIFT)) & locald74_LDPRR5E2_lumd2260_MASK)
/*! @} */

/*! @name LDPRR5E3 - ldprofilereg5e3 */
/*! @{ */

#define locald74_LDPRR5E3_lumd2263_MASK          (0x3FFU)
#define locald74_LDPRR5E3_lumd2263_SHIFT         (0U)
/*! lumd2263 - lumdat_2263 */
#define locald74_LDPRR5E3_lumd2263(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5E3_lumd2263_SHIFT)) & locald74_LDPRR5E3_lumd2263_MASK)

#define locald74_LDPRR5E3_lumd2262_MASK          (0x3FF0000U)
#define locald74_LDPRR5E3_lumd2262_SHIFT         (16U)
/*! lumd2262 - lumdat_2262 */
#define locald74_LDPRR5E3_lumd2262(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5E3_lumd2262_SHIFT)) & locald74_LDPRR5E3_lumd2262_MASK)
/*! @} */

/*! @name LDPRR5E4 - ldprofilereg5e4 */
/*! @{ */

#define locald74_LDPRR5E4_lumd2265_MASK          (0x3FFU)
#define locald74_LDPRR5E4_lumd2265_SHIFT         (0U)
/*! lumd2265 - lumdat_2265 */
#define locald74_LDPRR5E4_lumd2265(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5E4_lumd2265_SHIFT)) & locald74_LDPRR5E4_lumd2265_MASK)

#define locald74_LDPRR5E4_lumd2264_MASK          (0x3FF0000U)
#define locald74_LDPRR5E4_lumd2264_SHIFT         (16U)
/*! lumd2264 - lumdat_2264 */
#define locald74_LDPRR5E4_lumd2264(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5E4_lumd2264_SHIFT)) & locald74_LDPRR5E4_lumd2264_MASK)
/*! @} */

/*! @name LDPRR5E5 - ldprofilereg5e5 */
/*! @{ */

#define locald74_LDPRR5E5_lumd2267_MASK          (0x3FFU)
#define locald74_LDPRR5E5_lumd2267_SHIFT         (0U)
/*! lumd2267 - lumdat_2267 */
#define locald74_LDPRR5E5_lumd2267(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5E5_lumd2267_SHIFT)) & locald74_LDPRR5E5_lumd2267_MASK)

#define locald74_LDPRR5E5_lumd2266_MASK          (0x3FF0000U)
#define locald74_LDPRR5E5_lumd2266_SHIFT         (16U)
/*! lumd2266 - lumdat_2266 */
#define locald74_LDPRR5E5_lumd2266(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5E5_lumd2266_SHIFT)) & locald74_LDPRR5E5_lumd2266_MASK)
/*! @} */

/*! @name LDPRR5E6 - ldprofilereg5e6 */
/*! @{ */

#define locald74_LDPRR5E6_lumd2269_MASK          (0x3FFU)
#define locald74_LDPRR5E6_lumd2269_SHIFT         (0U)
/*! lumd2269 - lumdat_2269 */
#define locald74_LDPRR5E6_lumd2269(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5E6_lumd2269_SHIFT)) & locald74_LDPRR5E6_lumd2269_MASK)

#define locald74_LDPRR5E6_lumd2268_MASK          (0x3FF0000U)
#define locald74_LDPRR5E6_lumd2268_SHIFT         (16U)
/*! lumd2268 - lumdat_2268 */
#define locald74_LDPRR5E6_lumd2268(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5E6_lumd2268_SHIFT)) & locald74_LDPRR5E6_lumd2268_MASK)
/*! @} */

/*! @name LDPRR5E7 - ldprofilereg5e7 */
/*! @{ */

#define locald74_LDPRR5E7_lumd2271_MASK          (0x3FFU)
#define locald74_LDPRR5E7_lumd2271_SHIFT         (0U)
/*! lumd2271 - lumdat_2271 */
#define locald74_LDPRR5E7_lumd2271(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5E7_lumd2271_SHIFT)) & locald74_LDPRR5E7_lumd2271_MASK)

#define locald74_LDPRR5E7_lumd2270_MASK          (0x3FF0000U)
#define locald74_LDPRR5E7_lumd2270_SHIFT         (16U)
/*! lumd2270 - lumdat_2270 */
#define locald74_LDPRR5E7_lumd2270(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5E7_lumd2270_SHIFT)) & locald74_LDPRR5E7_lumd2270_MASK)
/*! @} */

/*! @name LDPRR5E8 - ldprofilereg5e8 */
/*! @{ */

#define locald74_LDPRR5E8_lumd2273_MASK          (0x3FFU)
#define locald74_LDPRR5E8_lumd2273_SHIFT         (0U)
/*! lumd2273 - lumdat_2273 */
#define locald74_LDPRR5E8_lumd2273(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5E8_lumd2273_SHIFT)) & locald74_LDPRR5E8_lumd2273_MASK)

#define locald74_LDPRR5E8_lumd2272_MASK          (0x3FF0000U)
#define locald74_LDPRR5E8_lumd2272_SHIFT         (16U)
/*! lumd2272 - lumdat_2272 */
#define locald74_LDPRR5E8_lumd2272(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5E8_lumd2272_SHIFT)) & locald74_LDPRR5E8_lumd2272_MASK)
/*! @} */

/*! @name LDPRR5E9 - ldprofilereg5e9 */
/*! @{ */

#define locald74_LDPRR5E9_lumd2275_MASK          (0x3FFU)
#define locald74_LDPRR5E9_lumd2275_SHIFT         (0U)
/*! lumd2275 - lumdat_2275 */
#define locald74_LDPRR5E9_lumd2275(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5E9_lumd2275_SHIFT)) & locald74_LDPRR5E9_lumd2275_MASK)

#define locald74_LDPRR5E9_lumd2274_MASK          (0x3FF0000U)
#define locald74_LDPRR5E9_lumd2274_SHIFT         (16U)
/*! lumd2274 - lumdat_2274 */
#define locald74_LDPRR5E9_lumd2274(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5E9_lumd2274_SHIFT)) & locald74_LDPRR5E9_lumd2274_MASK)
/*! @} */

/*! @name LDPRR5EA - ldprofilereg5ea */
/*! @{ */

#define locald74_LDPRR5EA_lumd2277_MASK          (0x3FFU)
#define locald74_LDPRR5EA_lumd2277_SHIFT         (0U)
/*! lumd2277 - lumdat_2277 */
#define locald74_LDPRR5EA_lumd2277(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5EA_lumd2277_SHIFT)) & locald74_LDPRR5EA_lumd2277_MASK)

#define locald74_LDPRR5EA_lumd2276_MASK          (0x3FF0000U)
#define locald74_LDPRR5EA_lumd2276_SHIFT         (16U)
/*! lumd2276 - lumdat_2276 */
#define locald74_LDPRR5EA_lumd2276(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5EA_lumd2276_SHIFT)) & locald74_LDPRR5EA_lumd2276_MASK)
/*! @} */

/*! @name LDPRR5EB - ldprofilereg5eb */
/*! @{ */

#define locald74_LDPRR5EB_lumd2279_MASK          (0x3FFU)
#define locald74_LDPRR5EB_lumd2279_SHIFT         (0U)
/*! lumd2279 - lumdat_2279 */
#define locald74_LDPRR5EB_lumd2279(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5EB_lumd2279_SHIFT)) & locald74_LDPRR5EB_lumd2279_MASK)

#define locald74_LDPRR5EB_lumd2278_MASK          (0x3FF0000U)
#define locald74_LDPRR5EB_lumd2278_SHIFT         (16U)
/*! lumd2278 - lumdat_2278 */
#define locald74_LDPRR5EB_lumd2278(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5EB_lumd2278_SHIFT)) & locald74_LDPRR5EB_lumd2278_MASK)
/*! @} */

/*! @name LDPRR5EC - ldprofilereg5ec */
/*! @{ */

#define locald74_LDPRR5EC_lumd2281_MASK          (0x3FFU)
#define locald74_LDPRR5EC_lumd2281_SHIFT         (0U)
/*! lumd2281 - lumdat_2281 */
#define locald74_LDPRR5EC_lumd2281(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5EC_lumd2281_SHIFT)) & locald74_LDPRR5EC_lumd2281_MASK)

#define locald74_LDPRR5EC_lumd2280_MASK          (0x3FF0000U)
#define locald74_LDPRR5EC_lumd2280_SHIFT         (16U)
/*! lumd2280 - lumdat_2280 */
#define locald74_LDPRR5EC_lumd2280(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5EC_lumd2280_SHIFT)) & locald74_LDPRR5EC_lumd2280_MASK)
/*! @} */

/*! @name LDPRR5ED - ldprofilereg5ed */
/*! @{ */

#define locald74_LDPRR5ED_lumd2283_MASK          (0x3FFU)
#define locald74_LDPRR5ED_lumd2283_SHIFT         (0U)
/*! lumd2283 - lumdat_2283 */
#define locald74_LDPRR5ED_lumd2283(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5ED_lumd2283_SHIFT)) & locald74_LDPRR5ED_lumd2283_MASK)

#define locald74_LDPRR5ED_lumd2282_MASK          (0x3FF0000U)
#define locald74_LDPRR5ED_lumd2282_SHIFT         (16U)
/*! lumd2282 - lumdat_2282 */
#define locald74_LDPRR5ED_lumd2282(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5ED_lumd2282_SHIFT)) & locald74_LDPRR5ED_lumd2282_MASK)
/*! @} */

/*! @name LDPRR5EE - ldprofilereg5ee */
/*! @{ */

#define locald74_LDPRR5EE_lumd2285_MASK          (0x3FFU)
#define locald74_LDPRR5EE_lumd2285_SHIFT         (0U)
/*! lumd2285 - lumdat_2285 */
#define locald74_LDPRR5EE_lumd2285(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5EE_lumd2285_SHIFT)) & locald74_LDPRR5EE_lumd2285_MASK)

#define locald74_LDPRR5EE_lumd2284_MASK          (0x3FF0000U)
#define locald74_LDPRR5EE_lumd2284_SHIFT         (16U)
/*! lumd2284 - lumdat_2284 */
#define locald74_LDPRR5EE_lumd2284(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5EE_lumd2284_SHIFT)) & locald74_LDPRR5EE_lumd2284_MASK)
/*! @} */

/*! @name LDPRR5EF - ldprofilereg5ef */
/*! @{ */

#define locald74_LDPRR5EF_lumd2287_MASK          (0x3FFU)
#define locald74_LDPRR5EF_lumd2287_SHIFT         (0U)
/*! lumd2287 - lumdat_2287 */
#define locald74_LDPRR5EF_lumd2287(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5EF_lumd2287_SHIFT)) & locald74_LDPRR5EF_lumd2287_MASK)

#define locald74_LDPRR5EF_lumd2286_MASK          (0x3FF0000U)
#define locald74_LDPRR5EF_lumd2286_SHIFT         (16U)
/*! lumd2286 - lumdat_2286 */
#define locald74_LDPRR5EF_lumd2286(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5EF_lumd2286_SHIFT)) & locald74_LDPRR5EF_lumd2286_MASK)
/*! @} */

/*! @name LDPRR5F0 - ldprofilereg5f0 */
/*! @{ */

#define locald74_LDPRR5F0_lumd2289_MASK          (0x3FFU)
#define locald74_LDPRR5F0_lumd2289_SHIFT         (0U)
/*! lumd2289 - lumdat_2289 */
#define locald74_LDPRR5F0_lumd2289(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5F0_lumd2289_SHIFT)) & locald74_LDPRR5F0_lumd2289_MASK)

#define locald74_LDPRR5F0_lumd2288_MASK          (0x3FF0000U)
#define locald74_LDPRR5F0_lumd2288_SHIFT         (16U)
/*! lumd2288 - lumdat_2288 */
#define locald74_LDPRR5F0_lumd2288(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5F0_lumd2288_SHIFT)) & locald74_LDPRR5F0_lumd2288_MASK)
/*! @} */

/*! @name LDPRR5F1 - ldprofilereg5f1 */
/*! @{ */

#define locald74_LDPRR5F1_lumd2291_MASK          (0x3FFU)
#define locald74_LDPRR5F1_lumd2291_SHIFT         (0U)
/*! lumd2291 - lumdat_2291 */
#define locald74_LDPRR5F1_lumd2291(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5F1_lumd2291_SHIFT)) & locald74_LDPRR5F1_lumd2291_MASK)

#define locald74_LDPRR5F1_lumd2290_MASK          (0x3FF0000U)
#define locald74_LDPRR5F1_lumd2290_SHIFT         (16U)
/*! lumd2290 - lumdat_2290 */
#define locald74_LDPRR5F1_lumd2290(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5F1_lumd2290_SHIFT)) & locald74_LDPRR5F1_lumd2290_MASK)
/*! @} */

/*! @name LDPRR5F2 - ldprofilereg5f2 */
/*! @{ */

#define locald74_LDPRR5F2_lumd2293_MASK          (0x3FFU)
#define locald74_LDPRR5F2_lumd2293_SHIFT         (0U)
/*! lumd2293 - lumdat_2293 */
#define locald74_LDPRR5F2_lumd2293(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5F2_lumd2293_SHIFT)) & locald74_LDPRR5F2_lumd2293_MASK)

#define locald74_LDPRR5F2_lumd2292_MASK          (0x3FF0000U)
#define locald74_LDPRR5F2_lumd2292_SHIFT         (16U)
/*! lumd2292 - lumdat_2292 */
#define locald74_LDPRR5F2_lumd2292(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5F2_lumd2292_SHIFT)) & locald74_LDPRR5F2_lumd2292_MASK)
/*! @} */

/*! @name LDPRR5F3 - ldprofilereg5f3 */
/*! @{ */

#define locald74_LDPRR5F3_lumd2295_MASK          (0x3FFU)
#define locald74_LDPRR5F3_lumd2295_SHIFT         (0U)
/*! lumd2295 - lumdat_2295 */
#define locald74_LDPRR5F3_lumd2295(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5F3_lumd2295_SHIFT)) & locald74_LDPRR5F3_lumd2295_MASK)

#define locald74_LDPRR5F3_lumd2294_MASK          (0x3FF0000U)
#define locald74_LDPRR5F3_lumd2294_SHIFT         (16U)
/*! lumd2294 - lumdat_2294 */
#define locald74_LDPRR5F3_lumd2294(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5F3_lumd2294_SHIFT)) & locald74_LDPRR5F3_lumd2294_MASK)
/*! @} */

/*! @name LDPRR5F4 - ldprofilereg5f4 */
/*! @{ */

#define locald74_LDPRR5F4_lumd2297_MASK          (0x3FFU)
#define locald74_LDPRR5F4_lumd2297_SHIFT         (0U)
/*! lumd2297 - lumdat_2297 */
#define locald74_LDPRR5F4_lumd2297(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5F4_lumd2297_SHIFT)) & locald74_LDPRR5F4_lumd2297_MASK)

#define locald74_LDPRR5F4_lumd2296_MASK          (0x3FF0000U)
#define locald74_LDPRR5F4_lumd2296_SHIFT         (16U)
/*! lumd2296 - lumdat_2296 */
#define locald74_LDPRR5F4_lumd2296(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5F4_lumd2296_SHIFT)) & locald74_LDPRR5F4_lumd2296_MASK)
/*! @} */

/*! @name LDPRR5F5 - ldprofilereg5f5 */
/*! @{ */

#define locald74_LDPRR5F5_lumd2299_MASK          (0x3FFU)
#define locald74_LDPRR5F5_lumd2299_SHIFT         (0U)
/*! lumd2299 - lumdat_2299 */
#define locald74_LDPRR5F5_lumd2299(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5F5_lumd2299_SHIFT)) & locald74_LDPRR5F5_lumd2299_MASK)

#define locald74_LDPRR5F5_lumd2298_MASK          (0x3FF0000U)
#define locald74_LDPRR5F5_lumd2298_SHIFT         (16U)
/*! lumd2298 - lumdat_2298 */
#define locald74_LDPRR5F5_lumd2298(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5F5_lumd2298_SHIFT)) & locald74_LDPRR5F5_lumd2298_MASK)
/*! @} */

/*! @name LDPRR5F6 - ldprofilereg5f6 */
/*! @{ */

#define locald74_LDPRR5F6_lumd2301_MASK          (0x3FFU)
#define locald74_LDPRR5F6_lumd2301_SHIFT         (0U)
/*! lumd2301 - lumdat_2301 */
#define locald74_LDPRR5F6_lumd2301(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5F6_lumd2301_SHIFT)) & locald74_LDPRR5F6_lumd2301_MASK)

#define locald74_LDPRR5F6_lumd2300_MASK          (0x3FF0000U)
#define locald74_LDPRR5F6_lumd2300_SHIFT         (16U)
/*! lumd2300 - lumdat_2300 */
#define locald74_LDPRR5F6_lumd2300(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5F6_lumd2300_SHIFT)) & locald74_LDPRR5F6_lumd2300_MASK)
/*! @} */

/*! @name LDPRR5F7 - ldprofilereg5f7 */
/*! @{ */

#define locald74_LDPRR5F7_lumd2303_MASK          (0x3FFU)
#define locald74_LDPRR5F7_lumd2303_SHIFT         (0U)
/*! lumd2303 - lumdat_2303 */
#define locald74_LDPRR5F7_lumd2303(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5F7_lumd2303_SHIFT)) & locald74_LDPRR5F7_lumd2303_MASK)

#define locald74_LDPRR5F7_lumd2302_MASK          (0x3FF0000U)
#define locald74_LDPRR5F7_lumd2302_SHIFT         (16U)
/*! lumd2302 - lumdat_2302 */
#define locald74_LDPRR5F7_lumd2302(x)            (((uint32_t)(((uint32_t)(x)) << locald74_LDPRR5F7_lumd2302_SHIFT)) & locald74_LDPRR5F7_lumd2302_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald74_Register_Masks */


/*!
 * @}
 */ /* end of group locald74_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD74_H_ */

