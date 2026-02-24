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
**         CMSIS Peripheral Access Layer for locald72
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
 * @file PERI_locald72.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald72
 *
 * CMSIS Peripheral Access Layer for locald72
 */

#if !defined(PERI_LOCALD72_H_)
#define PERI_LOCALD72_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald72 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald72_Peripheral_Access_Layer locald72 Peripheral Access Layer
 * @{
 */

/** locald72 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR5A0;                          /**< ldprofilereg5a0, offset: 0x0 */
  __IO uint32_t LDPRR5A1;                          /**< ldprofilereg5a1, offset: 0x4 */
  __IO uint32_t LDPRR5A2;                          /**< ldprofilereg5a2, offset: 0x8 */
  __IO uint32_t LDPRR5A3;                          /**< ldprofilereg5a3, offset: 0xC */
  __IO uint32_t LDPRR5A4;                          /**< ldprofilereg5a4, offset: 0x10 */
  __IO uint32_t LDPRR5A5;                          /**< ldprofilereg5a5, offset: 0x14 */
  __IO uint32_t LDPRR5A6;                          /**< ldprofilereg5a6, offset: 0x18 */
  __IO uint32_t LDPRR5A7;                          /**< ldprofilereg5a7, offset: 0x1C */
  __IO uint32_t LDPRR5A8;                          /**< ldprofilereg5a8, offset: 0x20 */
  __IO uint32_t LDPRR5A9;                          /**< ldprofilereg5a9, offset: 0x24 */
  __IO uint32_t LDPRR5AA;                          /**< ldprofilereg5aa, offset: 0x28 */
  __IO uint32_t LDPRR5AB;                          /**< ldprofilereg5ab, offset: 0x2C */
  __IO uint32_t LDPRR5AC;                          /**< ldprofilereg5ac, offset: 0x30 */
  __IO uint32_t LDPRR5AD;                          /**< ldprofilereg5ad, offset: 0x34 */
  __IO uint32_t LDPRR5AE;                          /**< ldprofilereg5ae, offset: 0x38 */
  __IO uint32_t LDPRR5AF;                          /**< ldprofilereg5af, offset: 0x3C */
  __IO uint32_t LDPRR5B0;                          /**< ldprofilereg5b0, offset: 0x40 */
  __IO uint32_t LDPRR5B1;                          /**< ldprofilereg5b1, offset: 0x44 */
  __IO uint32_t LDPRR5B2;                          /**< ldprofilereg5b2, offset: 0x48 */
  __IO uint32_t LDPRR5B3;                          /**< ldprofilereg5b3, offset: 0x4C */
  __IO uint32_t LDPRR5B4;                          /**< ldprofilereg5b4, offset: 0x50 */
  __IO uint32_t LDPRR5B5;                          /**< ldprofilereg5b5, offset: 0x54 */
  __IO uint32_t LDPRR5B6;                          /**< ldprofilereg5b6, offset: 0x58 */
  __IO uint32_t LDPRR5B7;                          /**< ldprofilereg5b7, offset: 0x5C */
} locald72_Type;

/* ----------------------------------------------------------------------------
   -- locald72 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald72_Register_Masks locald72 Register Masks
 * @{
 */

/*! @name LDPRR5A0 - ldprofilereg5a0 */
/*! @{ */

#define locald72_LDPRR5A0_lumd2161_MASK          (0x3FFU)
#define locald72_LDPRR5A0_lumd2161_SHIFT         (0U)
/*! lumd2161 - lumdat_2161 */
#define locald72_LDPRR5A0_lumd2161(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5A0_lumd2161_SHIFT)) & locald72_LDPRR5A0_lumd2161_MASK)

#define locald72_LDPRR5A0_lumd2160_MASK          (0x3FF0000U)
#define locald72_LDPRR5A0_lumd2160_SHIFT         (16U)
/*! lumd2160 - lumdat_2160 */
#define locald72_LDPRR5A0_lumd2160(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5A0_lumd2160_SHIFT)) & locald72_LDPRR5A0_lumd2160_MASK)
/*! @} */

/*! @name LDPRR5A1 - ldprofilereg5a1 */
/*! @{ */

#define locald72_LDPRR5A1_lumd2163_MASK          (0x3FFU)
#define locald72_LDPRR5A1_lumd2163_SHIFT         (0U)
/*! lumd2163 - lumdat_2163 */
#define locald72_LDPRR5A1_lumd2163(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5A1_lumd2163_SHIFT)) & locald72_LDPRR5A1_lumd2163_MASK)

#define locald72_LDPRR5A1_lumd2162_MASK          (0x3FF0000U)
#define locald72_LDPRR5A1_lumd2162_SHIFT         (16U)
/*! lumd2162 - lumdat_2162 */
#define locald72_LDPRR5A1_lumd2162(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5A1_lumd2162_SHIFT)) & locald72_LDPRR5A1_lumd2162_MASK)
/*! @} */

/*! @name LDPRR5A2 - ldprofilereg5a2 */
/*! @{ */

#define locald72_LDPRR5A2_lumd2165_MASK          (0x3FFU)
#define locald72_LDPRR5A2_lumd2165_SHIFT         (0U)
/*! lumd2165 - lumdat_2165 */
#define locald72_LDPRR5A2_lumd2165(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5A2_lumd2165_SHIFT)) & locald72_LDPRR5A2_lumd2165_MASK)

#define locald72_LDPRR5A2_lumd2164_MASK          (0x3FF0000U)
#define locald72_LDPRR5A2_lumd2164_SHIFT         (16U)
/*! lumd2164 - lumdat_2164 */
#define locald72_LDPRR5A2_lumd2164(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5A2_lumd2164_SHIFT)) & locald72_LDPRR5A2_lumd2164_MASK)
/*! @} */

/*! @name LDPRR5A3 - ldprofilereg5a3 */
/*! @{ */

#define locald72_LDPRR5A3_lumd2167_MASK          (0x3FFU)
#define locald72_LDPRR5A3_lumd2167_SHIFT         (0U)
/*! lumd2167 - lumdat_2167 */
#define locald72_LDPRR5A3_lumd2167(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5A3_lumd2167_SHIFT)) & locald72_LDPRR5A3_lumd2167_MASK)

#define locald72_LDPRR5A3_lumd2166_MASK          (0x3FF0000U)
#define locald72_LDPRR5A3_lumd2166_SHIFT         (16U)
/*! lumd2166 - lumdat_2166 */
#define locald72_LDPRR5A3_lumd2166(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5A3_lumd2166_SHIFT)) & locald72_LDPRR5A3_lumd2166_MASK)
/*! @} */

/*! @name LDPRR5A4 - ldprofilereg5a4 */
/*! @{ */

#define locald72_LDPRR5A4_lumd2169_MASK          (0x3FFU)
#define locald72_LDPRR5A4_lumd2169_SHIFT         (0U)
/*! lumd2169 - lumdat_2169 */
#define locald72_LDPRR5A4_lumd2169(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5A4_lumd2169_SHIFT)) & locald72_LDPRR5A4_lumd2169_MASK)

#define locald72_LDPRR5A4_lumd2168_MASK          (0x3FF0000U)
#define locald72_LDPRR5A4_lumd2168_SHIFT         (16U)
/*! lumd2168 - lumdat_2168 */
#define locald72_LDPRR5A4_lumd2168(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5A4_lumd2168_SHIFT)) & locald72_LDPRR5A4_lumd2168_MASK)
/*! @} */

/*! @name LDPRR5A5 - ldprofilereg5a5 */
/*! @{ */

#define locald72_LDPRR5A5_lumd2171_MASK          (0x3FFU)
#define locald72_LDPRR5A5_lumd2171_SHIFT         (0U)
/*! lumd2171 - lumdat_2171 */
#define locald72_LDPRR5A5_lumd2171(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5A5_lumd2171_SHIFT)) & locald72_LDPRR5A5_lumd2171_MASK)

#define locald72_LDPRR5A5_lumd2170_MASK          (0x3FF0000U)
#define locald72_LDPRR5A5_lumd2170_SHIFT         (16U)
/*! lumd2170 - lumdat_2170 */
#define locald72_LDPRR5A5_lumd2170(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5A5_lumd2170_SHIFT)) & locald72_LDPRR5A5_lumd2170_MASK)
/*! @} */

/*! @name LDPRR5A6 - ldprofilereg5a6 */
/*! @{ */

#define locald72_LDPRR5A6_lumd2173_MASK          (0x3FFU)
#define locald72_LDPRR5A6_lumd2173_SHIFT         (0U)
/*! lumd2173 - lumdat_2173 */
#define locald72_LDPRR5A6_lumd2173(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5A6_lumd2173_SHIFT)) & locald72_LDPRR5A6_lumd2173_MASK)

#define locald72_LDPRR5A6_lumd2172_MASK          (0x3FF0000U)
#define locald72_LDPRR5A6_lumd2172_SHIFT         (16U)
/*! lumd2172 - lumdat_2172 */
#define locald72_LDPRR5A6_lumd2172(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5A6_lumd2172_SHIFT)) & locald72_LDPRR5A6_lumd2172_MASK)
/*! @} */

/*! @name LDPRR5A7 - ldprofilereg5a7 */
/*! @{ */

#define locald72_LDPRR5A7_lumd2175_MASK          (0x3FFU)
#define locald72_LDPRR5A7_lumd2175_SHIFT         (0U)
/*! lumd2175 - lumdat_2175 */
#define locald72_LDPRR5A7_lumd2175(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5A7_lumd2175_SHIFT)) & locald72_LDPRR5A7_lumd2175_MASK)

#define locald72_LDPRR5A7_lumd2174_MASK          (0x3FF0000U)
#define locald72_LDPRR5A7_lumd2174_SHIFT         (16U)
/*! lumd2174 - lumdat_2174 */
#define locald72_LDPRR5A7_lumd2174(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5A7_lumd2174_SHIFT)) & locald72_LDPRR5A7_lumd2174_MASK)
/*! @} */

/*! @name LDPRR5A8 - ldprofilereg5a8 */
/*! @{ */

#define locald72_LDPRR5A8_lumd2177_MASK          (0x3FFU)
#define locald72_LDPRR5A8_lumd2177_SHIFT         (0U)
/*! lumd2177 - lumdat_2177 */
#define locald72_LDPRR5A8_lumd2177(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5A8_lumd2177_SHIFT)) & locald72_LDPRR5A8_lumd2177_MASK)

#define locald72_LDPRR5A8_lumd2176_MASK          (0x3FF0000U)
#define locald72_LDPRR5A8_lumd2176_SHIFT         (16U)
/*! lumd2176 - lumdat_2176 */
#define locald72_LDPRR5A8_lumd2176(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5A8_lumd2176_SHIFT)) & locald72_LDPRR5A8_lumd2176_MASK)
/*! @} */

/*! @name LDPRR5A9 - ldprofilereg5a9 */
/*! @{ */

#define locald72_LDPRR5A9_lumd2179_MASK          (0x3FFU)
#define locald72_LDPRR5A9_lumd2179_SHIFT         (0U)
/*! lumd2179 - lumdat_2179 */
#define locald72_LDPRR5A9_lumd2179(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5A9_lumd2179_SHIFT)) & locald72_LDPRR5A9_lumd2179_MASK)

#define locald72_LDPRR5A9_lumd2178_MASK          (0x3FF0000U)
#define locald72_LDPRR5A9_lumd2178_SHIFT         (16U)
/*! lumd2178 - lumdat_2178 */
#define locald72_LDPRR5A9_lumd2178(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5A9_lumd2178_SHIFT)) & locald72_LDPRR5A9_lumd2178_MASK)
/*! @} */

/*! @name LDPRR5AA - ldprofilereg5aa */
/*! @{ */

#define locald72_LDPRR5AA_lumd2181_MASK          (0x3FFU)
#define locald72_LDPRR5AA_lumd2181_SHIFT         (0U)
/*! lumd2181 - lumdat_2181 */
#define locald72_LDPRR5AA_lumd2181(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5AA_lumd2181_SHIFT)) & locald72_LDPRR5AA_lumd2181_MASK)

#define locald72_LDPRR5AA_lumd2180_MASK          (0x3FF0000U)
#define locald72_LDPRR5AA_lumd2180_SHIFT         (16U)
/*! lumd2180 - lumdat_2180 */
#define locald72_LDPRR5AA_lumd2180(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5AA_lumd2180_SHIFT)) & locald72_LDPRR5AA_lumd2180_MASK)
/*! @} */

/*! @name LDPRR5AB - ldprofilereg5ab */
/*! @{ */

#define locald72_LDPRR5AB_lumd2183_MASK          (0x3FFU)
#define locald72_LDPRR5AB_lumd2183_SHIFT         (0U)
/*! lumd2183 - lumdat_2183 */
#define locald72_LDPRR5AB_lumd2183(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5AB_lumd2183_SHIFT)) & locald72_LDPRR5AB_lumd2183_MASK)

#define locald72_LDPRR5AB_lumd2182_MASK          (0x3FF0000U)
#define locald72_LDPRR5AB_lumd2182_SHIFT         (16U)
/*! lumd2182 - lumdat_2182 */
#define locald72_LDPRR5AB_lumd2182(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5AB_lumd2182_SHIFT)) & locald72_LDPRR5AB_lumd2182_MASK)
/*! @} */

/*! @name LDPRR5AC - ldprofilereg5ac */
/*! @{ */

#define locald72_LDPRR5AC_lumd2185_MASK          (0x3FFU)
#define locald72_LDPRR5AC_lumd2185_SHIFT         (0U)
/*! lumd2185 - lumdat_2185 */
#define locald72_LDPRR5AC_lumd2185(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5AC_lumd2185_SHIFT)) & locald72_LDPRR5AC_lumd2185_MASK)

#define locald72_LDPRR5AC_lumd2184_MASK          (0x3FF0000U)
#define locald72_LDPRR5AC_lumd2184_SHIFT         (16U)
/*! lumd2184 - lumdat_2184 */
#define locald72_LDPRR5AC_lumd2184(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5AC_lumd2184_SHIFT)) & locald72_LDPRR5AC_lumd2184_MASK)
/*! @} */

/*! @name LDPRR5AD - ldprofilereg5ad */
/*! @{ */

#define locald72_LDPRR5AD_lumd2187_MASK          (0x3FFU)
#define locald72_LDPRR5AD_lumd2187_SHIFT         (0U)
/*! lumd2187 - lumdat_2187 */
#define locald72_LDPRR5AD_lumd2187(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5AD_lumd2187_SHIFT)) & locald72_LDPRR5AD_lumd2187_MASK)

#define locald72_LDPRR5AD_lumd2186_MASK          (0x3FF0000U)
#define locald72_LDPRR5AD_lumd2186_SHIFT         (16U)
/*! lumd2186 - lumdat_2186 */
#define locald72_LDPRR5AD_lumd2186(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5AD_lumd2186_SHIFT)) & locald72_LDPRR5AD_lumd2186_MASK)
/*! @} */

/*! @name LDPRR5AE - ldprofilereg5ae */
/*! @{ */

#define locald72_LDPRR5AE_lumd2189_MASK          (0x3FFU)
#define locald72_LDPRR5AE_lumd2189_SHIFT         (0U)
/*! lumd2189 - lumdat_2189 */
#define locald72_LDPRR5AE_lumd2189(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5AE_lumd2189_SHIFT)) & locald72_LDPRR5AE_lumd2189_MASK)

#define locald72_LDPRR5AE_lumd2188_MASK          (0x3FF0000U)
#define locald72_LDPRR5AE_lumd2188_SHIFT         (16U)
/*! lumd2188 - lumdat_2188 */
#define locald72_LDPRR5AE_lumd2188(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5AE_lumd2188_SHIFT)) & locald72_LDPRR5AE_lumd2188_MASK)
/*! @} */

/*! @name LDPRR5AF - ldprofilereg5af */
/*! @{ */

#define locald72_LDPRR5AF_lumd2191_MASK          (0x3FFU)
#define locald72_LDPRR5AF_lumd2191_SHIFT         (0U)
/*! lumd2191 - lumdat_2191 */
#define locald72_LDPRR5AF_lumd2191(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5AF_lumd2191_SHIFT)) & locald72_LDPRR5AF_lumd2191_MASK)

#define locald72_LDPRR5AF_lumd2190_MASK          (0x3FF0000U)
#define locald72_LDPRR5AF_lumd2190_SHIFT         (16U)
/*! lumd2190 - lumdat_2190 */
#define locald72_LDPRR5AF_lumd2190(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5AF_lumd2190_SHIFT)) & locald72_LDPRR5AF_lumd2190_MASK)
/*! @} */

/*! @name LDPRR5B0 - ldprofilereg5b0 */
/*! @{ */

#define locald72_LDPRR5B0_lumd2193_MASK          (0x3FFU)
#define locald72_LDPRR5B0_lumd2193_SHIFT         (0U)
/*! lumd2193 - lumdat_2193 */
#define locald72_LDPRR5B0_lumd2193(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5B0_lumd2193_SHIFT)) & locald72_LDPRR5B0_lumd2193_MASK)

#define locald72_LDPRR5B0_lumd2192_MASK          (0x3FF0000U)
#define locald72_LDPRR5B0_lumd2192_SHIFT         (16U)
/*! lumd2192 - lumdat_2192 */
#define locald72_LDPRR5B0_lumd2192(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5B0_lumd2192_SHIFT)) & locald72_LDPRR5B0_lumd2192_MASK)
/*! @} */

/*! @name LDPRR5B1 - ldprofilereg5b1 */
/*! @{ */

#define locald72_LDPRR5B1_lumd2195_MASK          (0x3FFU)
#define locald72_LDPRR5B1_lumd2195_SHIFT         (0U)
/*! lumd2195 - lumdat_2195 */
#define locald72_LDPRR5B1_lumd2195(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5B1_lumd2195_SHIFT)) & locald72_LDPRR5B1_lumd2195_MASK)

#define locald72_LDPRR5B1_lumd2194_MASK          (0x3FF0000U)
#define locald72_LDPRR5B1_lumd2194_SHIFT         (16U)
/*! lumd2194 - lumdat_2194 */
#define locald72_LDPRR5B1_lumd2194(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5B1_lumd2194_SHIFT)) & locald72_LDPRR5B1_lumd2194_MASK)
/*! @} */

/*! @name LDPRR5B2 - ldprofilereg5b2 */
/*! @{ */

#define locald72_LDPRR5B2_lumd2197_MASK          (0x3FFU)
#define locald72_LDPRR5B2_lumd2197_SHIFT         (0U)
/*! lumd2197 - lumdat_2197 */
#define locald72_LDPRR5B2_lumd2197(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5B2_lumd2197_SHIFT)) & locald72_LDPRR5B2_lumd2197_MASK)

#define locald72_LDPRR5B2_lumd2196_MASK          (0x3FF0000U)
#define locald72_LDPRR5B2_lumd2196_SHIFT         (16U)
/*! lumd2196 - lumdat_2196 */
#define locald72_LDPRR5B2_lumd2196(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5B2_lumd2196_SHIFT)) & locald72_LDPRR5B2_lumd2196_MASK)
/*! @} */

/*! @name LDPRR5B3 - ldprofilereg5b3 */
/*! @{ */

#define locald72_LDPRR5B3_lumd2199_MASK          (0x3FFU)
#define locald72_LDPRR5B3_lumd2199_SHIFT         (0U)
/*! lumd2199 - lumdat_2199 */
#define locald72_LDPRR5B3_lumd2199(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5B3_lumd2199_SHIFT)) & locald72_LDPRR5B3_lumd2199_MASK)

#define locald72_LDPRR5B3_lumd2198_MASK          (0x3FF0000U)
#define locald72_LDPRR5B3_lumd2198_SHIFT         (16U)
/*! lumd2198 - lumdat_2198 */
#define locald72_LDPRR5B3_lumd2198(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5B3_lumd2198_SHIFT)) & locald72_LDPRR5B3_lumd2198_MASK)
/*! @} */

/*! @name LDPRR5B4 - ldprofilereg5b4 */
/*! @{ */

#define locald72_LDPRR5B4_lumd2201_MASK          (0x3FFU)
#define locald72_LDPRR5B4_lumd2201_SHIFT         (0U)
/*! lumd2201 - lumdat_2201 */
#define locald72_LDPRR5B4_lumd2201(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5B4_lumd2201_SHIFT)) & locald72_LDPRR5B4_lumd2201_MASK)

#define locald72_LDPRR5B4_lumd2200_MASK          (0x3FF0000U)
#define locald72_LDPRR5B4_lumd2200_SHIFT         (16U)
/*! lumd2200 - lumdat_2200 */
#define locald72_LDPRR5B4_lumd2200(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5B4_lumd2200_SHIFT)) & locald72_LDPRR5B4_lumd2200_MASK)
/*! @} */

/*! @name LDPRR5B5 - ldprofilereg5b5 */
/*! @{ */

#define locald72_LDPRR5B5_lumd2203_MASK          (0x3FFU)
#define locald72_LDPRR5B5_lumd2203_SHIFT         (0U)
/*! lumd2203 - lumdat_2203 */
#define locald72_LDPRR5B5_lumd2203(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5B5_lumd2203_SHIFT)) & locald72_LDPRR5B5_lumd2203_MASK)

#define locald72_LDPRR5B5_lumd2202_MASK          (0x3FF0000U)
#define locald72_LDPRR5B5_lumd2202_SHIFT         (16U)
/*! lumd2202 - lumdat_2202 */
#define locald72_LDPRR5B5_lumd2202(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5B5_lumd2202_SHIFT)) & locald72_LDPRR5B5_lumd2202_MASK)
/*! @} */

/*! @name LDPRR5B6 - ldprofilereg5b6 */
/*! @{ */

#define locald72_LDPRR5B6_lumd2205_MASK          (0x3FFU)
#define locald72_LDPRR5B6_lumd2205_SHIFT         (0U)
/*! lumd2205 - lumdat_2205 */
#define locald72_LDPRR5B6_lumd2205(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5B6_lumd2205_SHIFT)) & locald72_LDPRR5B6_lumd2205_MASK)

#define locald72_LDPRR5B6_lumd2204_MASK          (0x3FF0000U)
#define locald72_LDPRR5B6_lumd2204_SHIFT         (16U)
/*! lumd2204 - lumdat_2204 */
#define locald72_LDPRR5B6_lumd2204(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5B6_lumd2204_SHIFT)) & locald72_LDPRR5B6_lumd2204_MASK)
/*! @} */

/*! @name LDPRR5B7 - ldprofilereg5b7 */
/*! @{ */

#define locald72_LDPRR5B7_lumd2207_MASK          (0x3FFU)
#define locald72_LDPRR5B7_lumd2207_SHIFT         (0U)
/*! lumd2207 - lumdat_2207 */
#define locald72_LDPRR5B7_lumd2207(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5B7_lumd2207_SHIFT)) & locald72_LDPRR5B7_lumd2207_MASK)

#define locald72_LDPRR5B7_lumd2206_MASK          (0x3FF0000U)
#define locald72_LDPRR5B7_lumd2206_SHIFT         (16U)
/*! lumd2206 - lumdat_2206 */
#define locald72_LDPRR5B7_lumd2206(x)            (((uint32_t)(((uint32_t)(x)) << locald72_LDPRR5B7_lumd2206_SHIFT)) & locald72_LDPRR5B7_lumd2206_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald72_Register_Masks */


/*!
 * @}
 */ /* end of group locald72_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD72_H_ */

