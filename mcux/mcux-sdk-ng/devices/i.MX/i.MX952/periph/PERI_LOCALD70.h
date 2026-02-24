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
**         CMSIS Peripheral Access Layer for locald70
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
 * @file PERI_locald70.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald70
 *
 * CMSIS Peripheral Access Layer for locald70
 */

#if !defined(PERI_LOCALD70_H_)
#define PERI_LOCALD70_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald70 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald70_Peripheral_Access_Layer locald70 Peripheral Access Layer
 * @{
 */

/** locald70 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR560;                          /**< ldprofilereg560, offset: 0x0 */
  __IO uint32_t LDPRR561;                          /**< ldprofilereg561, offset: 0x4 */
  __IO uint32_t LDPRR562;                          /**< ldprofilereg562, offset: 0x8 */
  __IO uint32_t LDPRR563;                          /**< ldprofilereg563, offset: 0xC */
  __IO uint32_t LDPRR564;                          /**< ldprofilereg564, offset: 0x10 */
  __IO uint32_t LDPRR565;                          /**< ldprofilereg565, offset: 0x14 */
  __IO uint32_t LDPRR566;                          /**< ldprofilereg566, offset: 0x18 */
  __IO uint32_t LDPRR567;                          /**< ldprofilereg567, offset: 0x1C */
  __IO uint32_t LDPRR568;                          /**< ldprofilereg568, offset: 0x20 */
  __IO uint32_t LDPRR569;                          /**< ldprofilereg569, offset: 0x24 */
  __IO uint32_t LDPRR56A;                          /**< ldprofilereg56a, offset: 0x28 */
  __IO uint32_t LDPRR56B;                          /**< ldprofilereg56b, offset: 0x2C */
  __IO uint32_t LDPRR56C;                          /**< ldprofilereg56c, offset: 0x30 */
  __IO uint32_t LDPRR56D;                          /**< ldprofilereg56d, offset: 0x34 */
  __IO uint32_t LDPRR56E;                          /**< ldprofilereg56e, offset: 0x38 */
  __IO uint32_t LDPRR56F;                          /**< ldprofilereg56f, offset: 0x3C */
  __IO uint32_t LDPRR570;                          /**< ldprofilereg570, offset: 0x40 */
  __IO uint32_t LDPRR571;                          /**< ldprofilereg571, offset: 0x44 */
  __IO uint32_t LDPRR572;                          /**< ldprofilereg572, offset: 0x48 */
  __IO uint32_t LDPRR573;                          /**< ldprofilereg573, offset: 0x4C */
  __IO uint32_t LDPRR574;                          /**< ldprofilereg574, offset: 0x50 */
  __IO uint32_t LDPRR575;                          /**< ldprofilereg575, offset: 0x54 */
  __IO uint32_t LDPRR576;                          /**< ldprofilereg576, offset: 0x58 */
  __IO uint32_t LDPRR577;                          /**< ldprofilereg577, offset: 0x5C */
} locald70_Type;

/* ----------------------------------------------------------------------------
   -- locald70 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald70_Register_Masks locald70 Register Masks
 * @{
 */

/*! @name LDPRR560 - ldprofilereg560 */
/*! @{ */

#define locald70_LDPRR560_lumd2065_MASK          (0x3FFU)
#define locald70_LDPRR560_lumd2065_SHIFT         (0U)
/*! lumd2065 - lumdat_2065 */
#define locald70_LDPRR560_lumd2065(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR560_lumd2065_SHIFT)) & locald70_LDPRR560_lumd2065_MASK)

#define locald70_LDPRR560_lumd2064_MASK          (0x3FF0000U)
#define locald70_LDPRR560_lumd2064_SHIFT         (16U)
/*! lumd2064 - lumdat_2064 */
#define locald70_LDPRR560_lumd2064(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR560_lumd2064_SHIFT)) & locald70_LDPRR560_lumd2064_MASK)
/*! @} */

/*! @name LDPRR561 - ldprofilereg561 */
/*! @{ */

#define locald70_LDPRR561_lumd2067_MASK          (0x3FFU)
#define locald70_LDPRR561_lumd2067_SHIFT         (0U)
/*! lumd2067 - lumdat_2067 */
#define locald70_LDPRR561_lumd2067(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR561_lumd2067_SHIFT)) & locald70_LDPRR561_lumd2067_MASK)

#define locald70_LDPRR561_lumd2066_MASK          (0x3FF0000U)
#define locald70_LDPRR561_lumd2066_SHIFT         (16U)
/*! lumd2066 - lumdat_2066 */
#define locald70_LDPRR561_lumd2066(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR561_lumd2066_SHIFT)) & locald70_LDPRR561_lumd2066_MASK)
/*! @} */

/*! @name LDPRR562 - ldprofilereg562 */
/*! @{ */

#define locald70_LDPRR562_lumd2069_MASK          (0x3FFU)
#define locald70_LDPRR562_lumd2069_SHIFT         (0U)
/*! lumd2069 - lumdat_2069 */
#define locald70_LDPRR562_lumd2069(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR562_lumd2069_SHIFT)) & locald70_LDPRR562_lumd2069_MASK)

#define locald70_LDPRR562_lumd2068_MASK          (0x3FF0000U)
#define locald70_LDPRR562_lumd2068_SHIFT         (16U)
/*! lumd2068 - lumdat_2068 */
#define locald70_LDPRR562_lumd2068(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR562_lumd2068_SHIFT)) & locald70_LDPRR562_lumd2068_MASK)
/*! @} */

/*! @name LDPRR563 - ldprofilereg563 */
/*! @{ */

#define locald70_LDPRR563_lumd2071_MASK          (0x3FFU)
#define locald70_LDPRR563_lumd2071_SHIFT         (0U)
/*! lumd2071 - lumdat_2071 */
#define locald70_LDPRR563_lumd2071(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR563_lumd2071_SHIFT)) & locald70_LDPRR563_lumd2071_MASK)

#define locald70_LDPRR563_lumd2070_MASK          (0x3FF0000U)
#define locald70_LDPRR563_lumd2070_SHIFT         (16U)
/*! lumd2070 - lumdat_2070 */
#define locald70_LDPRR563_lumd2070(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR563_lumd2070_SHIFT)) & locald70_LDPRR563_lumd2070_MASK)
/*! @} */

/*! @name LDPRR564 - ldprofilereg564 */
/*! @{ */

#define locald70_LDPRR564_lumd2073_MASK          (0x3FFU)
#define locald70_LDPRR564_lumd2073_SHIFT         (0U)
/*! lumd2073 - lumdat_2073 */
#define locald70_LDPRR564_lumd2073(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR564_lumd2073_SHIFT)) & locald70_LDPRR564_lumd2073_MASK)

#define locald70_LDPRR564_lumd2072_MASK          (0x3FF0000U)
#define locald70_LDPRR564_lumd2072_SHIFT         (16U)
/*! lumd2072 - lumdat_2072 */
#define locald70_LDPRR564_lumd2072(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR564_lumd2072_SHIFT)) & locald70_LDPRR564_lumd2072_MASK)
/*! @} */

/*! @name LDPRR565 - ldprofilereg565 */
/*! @{ */

#define locald70_LDPRR565_lumd2075_MASK          (0x3FFU)
#define locald70_LDPRR565_lumd2075_SHIFT         (0U)
/*! lumd2075 - lumdat_2075 */
#define locald70_LDPRR565_lumd2075(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR565_lumd2075_SHIFT)) & locald70_LDPRR565_lumd2075_MASK)

#define locald70_LDPRR565_lumd2074_MASK          (0x3FF0000U)
#define locald70_LDPRR565_lumd2074_SHIFT         (16U)
/*! lumd2074 - lumdat_2074 */
#define locald70_LDPRR565_lumd2074(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR565_lumd2074_SHIFT)) & locald70_LDPRR565_lumd2074_MASK)
/*! @} */

/*! @name LDPRR566 - ldprofilereg566 */
/*! @{ */

#define locald70_LDPRR566_lumd2077_MASK          (0x3FFU)
#define locald70_LDPRR566_lumd2077_SHIFT         (0U)
/*! lumd2077 - lumdat_2077 */
#define locald70_LDPRR566_lumd2077(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR566_lumd2077_SHIFT)) & locald70_LDPRR566_lumd2077_MASK)

#define locald70_LDPRR566_lumd2076_MASK          (0x3FF0000U)
#define locald70_LDPRR566_lumd2076_SHIFT         (16U)
/*! lumd2076 - lumdat_2076 */
#define locald70_LDPRR566_lumd2076(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR566_lumd2076_SHIFT)) & locald70_LDPRR566_lumd2076_MASK)
/*! @} */

/*! @name LDPRR567 - ldprofilereg567 */
/*! @{ */

#define locald70_LDPRR567_lumd2079_MASK          (0x3FFU)
#define locald70_LDPRR567_lumd2079_SHIFT         (0U)
/*! lumd2079 - lumdat_2079 */
#define locald70_LDPRR567_lumd2079(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR567_lumd2079_SHIFT)) & locald70_LDPRR567_lumd2079_MASK)

#define locald70_LDPRR567_lumd2078_MASK          (0x3FF0000U)
#define locald70_LDPRR567_lumd2078_SHIFT         (16U)
/*! lumd2078 - lumdat_2078 */
#define locald70_LDPRR567_lumd2078(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR567_lumd2078_SHIFT)) & locald70_LDPRR567_lumd2078_MASK)
/*! @} */

/*! @name LDPRR568 - ldprofilereg568 */
/*! @{ */

#define locald70_LDPRR568_lumd2081_MASK          (0x3FFU)
#define locald70_LDPRR568_lumd2081_SHIFT         (0U)
/*! lumd2081 - lumdat_2081 */
#define locald70_LDPRR568_lumd2081(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR568_lumd2081_SHIFT)) & locald70_LDPRR568_lumd2081_MASK)

#define locald70_LDPRR568_lumd2080_MASK          (0x3FF0000U)
#define locald70_LDPRR568_lumd2080_SHIFT         (16U)
/*! lumd2080 - lumdat_2080 */
#define locald70_LDPRR568_lumd2080(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR568_lumd2080_SHIFT)) & locald70_LDPRR568_lumd2080_MASK)
/*! @} */

/*! @name LDPRR569 - ldprofilereg569 */
/*! @{ */

#define locald70_LDPRR569_lumd2083_MASK          (0x3FFU)
#define locald70_LDPRR569_lumd2083_SHIFT         (0U)
/*! lumd2083 - lumdat_2083 */
#define locald70_LDPRR569_lumd2083(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR569_lumd2083_SHIFT)) & locald70_LDPRR569_lumd2083_MASK)

#define locald70_LDPRR569_lumd2082_MASK          (0x3FF0000U)
#define locald70_LDPRR569_lumd2082_SHIFT         (16U)
/*! lumd2082 - lumdat_2082 */
#define locald70_LDPRR569_lumd2082(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR569_lumd2082_SHIFT)) & locald70_LDPRR569_lumd2082_MASK)
/*! @} */

/*! @name LDPRR56A - ldprofilereg56a */
/*! @{ */

#define locald70_LDPRR56A_lumd2085_MASK          (0x3FFU)
#define locald70_LDPRR56A_lumd2085_SHIFT         (0U)
/*! lumd2085 - lumdat_2085 */
#define locald70_LDPRR56A_lumd2085(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR56A_lumd2085_SHIFT)) & locald70_LDPRR56A_lumd2085_MASK)

#define locald70_LDPRR56A_lumd2084_MASK          (0x3FF0000U)
#define locald70_LDPRR56A_lumd2084_SHIFT         (16U)
/*! lumd2084 - lumdat_2084 */
#define locald70_LDPRR56A_lumd2084(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR56A_lumd2084_SHIFT)) & locald70_LDPRR56A_lumd2084_MASK)
/*! @} */

/*! @name LDPRR56B - ldprofilereg56b */
/*! @{ */

#define locald70_LDPRR56B_lumd2087_MASK          (0x3FFU)
#define locald70_LDPRR56B_lumd2087_SHIFT         (0U)
/*! lumd2087 - lumdat_2087 */
#define locald70_LDPRR56B_lumd2087(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR56B_lumd2087_SHIFT)) & locald70_LDPRR56B_lumd2087_MASK)

#define locald70_LDPRR56B_lumd2086_MASK          (0x3FF0000U)
#define locald70_LDPRR56B_lumd2086_SHIFT         (16U)
/*! lumd2086 - lumdat_2086 */
#define locald70_LDPRR56B_lumd2086(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR56B_lumd2086_SHIFT)) & locald70_LDPRR56B_lumd2086_MASK)
/*! @} */

/*! @name LDPRR56C - ldprofilereg56c */
/*! @{ */

#define locald70_LDPRR56C_lumd2089_MASK          (0x3FFU)
#define locald70_LDPRR56C_lumd2089_SHIFT         (0U)
/*! lumd2089 - lumdat_2089 */
#define locald70_LDPRR56C_lumd2089(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR56C_lumd2089_SHIFT)) & locald70_LDPRR56C_lumd2089_MASK)

#define locald70_LDPRR56C_lumd2088_MASK          (0x3FF0000U)
#define locald70_LDPRR56C_lumd2088_SHIFT         (16U)
/*! lumd2088 - lumdat_2088 */
#define locald70_LDPRR56C_lumd2088(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR56C_lumd2088_SHIFT)) & locald70_LDPRR56C_lumd2088_MASK)
/*! @} */

/*! @name LDPRR56D - ldprofilereg56d */
/*! @{ */

#define locald70_LDPRR56D_lumd2091_MASK          (0x3FFU)
#define locald70_LDPRR56D_lumd2091_SHIFT         (0U)
/*! lumd2091 - lumdat_2091 */
#define locald70_LDPRR56D_lumd2091(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR56D_lumd2091_SHIFT)) & locald70_LDPRR56D_lumd2091_MASK)

#define locald70_LDPRR56D_lumd2090_MASK          (0x3FF0000U)
#define locald70_LDPRR56D_lumd2090_SHIFT         (16U)
/*! lumd2090 - lumdat_2090 */
#define locald70_LDPRR56D_lumd2090(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR56D_lumd2090_SHIFT)) & locald70_LDPRR56D_lumd2090_MASK)
/*! @} */

/*! @name LDPRR56E - ldprofilereg56e */
/*! @{ */

#define locald70_LDPRR56E_lumd2093_MASK          (0x3FFU)
#define locald70_LDPRR56E_lumd2093_SHIFT         (0U)
/*! lumd2093 - lumdat_2093 */
#define locald70_LDPRR56E_lumd2093(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR56E_lumd2093_SHIFT)) & locald70_LDPRR56E_lumd2093_MASK)

#define locald70_LDPRR56E_lumd2092_MASK          (0x3FF0000U)
#define locald70_LDPRR56E_lumd2092_SHIFT         (16U)
/*! lumd2092 - lumdat_2092 */
#define locald70_LDPRR56E_lumd2092(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR56E_lumd2092_SHIFT)) & locald70_LDPRR56E_lumd2092_MASK)
/*! @} */

/*! @name LDPRR56F - ldprofilereg56f */
/*! @{ */

#define locald70_LDPRR56F_lumd2095_MASK          (0x3FFU)
#define locald70_LDPRR56F_lumd2095_SHIFT         (0U)
/*! lumd2095 - lumdat_2095 */
#define locald70_LDPRR56F_lumd2095(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR56F_lumd2095_SHIFT)) & locald70_LDPRR56F_lumd2095_MASK)

#define locald70_LDPRR56F_lumd2094_MASK          (0x3FF0000U)
#define locald70_LDPRR56F_lumd2094_SHIFT         (16U)
/*! lumd2094 - lumdat_2094 */
#define locald70_LDPRR56F_lumd2094(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR56F_lumd2094_SHIFT)) & locald70_LDPRR56F_lumd2094_MASK)
/*! @} */

/*! @name LDPRR570 - ldprofilereg570 */
/*! @{ */

#define locald70_LDPRR570_lumd2097_MASK          (0x3FFU)
#define locald70_LDPRR570_lumd2097_SHIFT         (0U)
/*! lumd2097 - lumdat_2097 */
#define locald70_LDPRR570_lumd2097(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR570_lumd2097_SHIFT)) & locald70_LDPRR570_lumd2097_MASK)

#define locald70_LDPRR570_lumd2096_MASK          (0x3FF0000U)
#define locald70_LDPRR570_lumd2096_SHIFT         (16U)
/*! lumd2096 - lumdat_2096 */
#define locald70_LDPRR570_lumd2096(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR570_lumd2096_SHIFT)) & locald70_LDPRR570_lumd2096_MASK)
/*! @} */

/*! @name LDPRR571 - ldprofilereg571 */
/*! @{ */

#define locald70_LDPRR571_lumd2099_MASK          (0x3FFU)
#define locald70_LDPRR571_lumd2099_SHIFT         (0U)
/*! lumd2099 - lumdat_2099 */
#define locald70_LDPRR571_lumd2099(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR571_lumd2099_SHIFT)) & locald70_LDPRR571_lumd2099_MASK)

#define locald70_LDPRR571_lumd2098_MASK          (0x3FF0000U)
#define locald70_LDPRR571_lumd2098_SHIFT         (16U)
/*! lumd2098 - lumdat_2098 */
#define locald70_LDPRR571_lumd2098(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR571_lumd2098_SHIFT)) & locald70_LDPRR571_lumd2098_MASK)
/*! @} */

/*! @name LDPRR572 - ldprofilereg572 */
/*! @{ */

#define locald70_LDPRR572_lumd2101_MASK          (0x3FFU)
#define locald70_LDPRR572_lumd2101_SHIFT         (0U)
/*! lumd2101 - lumdat_2101 */
#define locald70_LDPRR572_lumd2101(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR572_lumd2101_SHIFT)) & locald70_LDPRR572_lumd2101_MASK)

#define locald70_LDPRR572_lumd2100_MASK          (0x3FF0000U)
#define locald70_LDPRR572_lumd2100_SHIFT         (16U)
/*! lumd2100 - lumdat_2100 */
#define locald70_LDPRR572_lumd2100(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR572_lumd2100_SHIFT)) & locald70_LDPRR572_lumd2100_MASK)
/*! @} */

/*! @name LDPRR573 - ldprofilereg573 */
/*! @{ */

#define locald70_LDPRR573_lumd2103_MASK          (0x3FFU)
#define locald70_LDPRR573_lumd2103_SHIFT         (0U)
/*! lumd2103 - lumdat_2103 */
#define locald70_LDPRR573_lumd2103(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR573_lumd2103_SHIFT)) & locald70_LDPRR573_lumd2103_MASK)

#define locald70_LDPRR573_lumd2102_MASK          (0x3FF0000U)
#define locald70_LDPRR573_lumd2102_SHIFT         (16U)
/*! lumd2102 - lumdat_2102 */
#define locald70_LDPRR573_lumd2102(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR573_lumd2102_SHIFT)) & locald70_LDPRR573_lumd2102_MASK)
/*! @} */

/*! @name LDPRR574 - ldprofilereg574 */
/*! @{ */

#define locald70_LDPRR574_lumd2105_MASK          (0x3FFU)
#define locald70_LDPRR574_lumd2105_SHIFT         (0U)
/*! lumd2105 - lumdat_2105 */
#define locald70_LDPRR574_lumd2105(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR574_lumd2105_SHIFT)) & locald70_LDPRR574_lumd2105_MASK)

#define locald70_LDPRR574_lumd2104_MASK          (0x3FF0000U)
#define locald70_LDPRR574_lumd2104_SHIFT         (16U)
/*! lumd2104 - lumdat_2104 */
#define locald70_LDPRR574_lumd2104(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR574_lumd2104_SHIFT)) & locald70_LDPRR574_lumd2104_MASK)
/*! @} */

/*! @name LDPRR575 - ldprofilereg575 */
/*! @{ */

#define locald70_LDPRR575_lumd2107_MASK          (0x3FFU)
#define locald70_LDPRR575_lumd2107_SHIFT         (0U)
/*! lumd2107 - lumdat_2107 */
#define locald70_LDPRR575_lumd2107(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR575_lumd2107_SHIFT)) & locald70_LDPRR575_lumd2107_MASK)

#define locald70_LDPRR575_lumd2106_MASK          (0x3FF0000U)
#define locald70_LDPRR575_lumd2106_SHIFT         (16U)
/*! lumd2106 - lumdat_2106 */
#define locald70_LDPRR575_lumd2106(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR575_lumd2106_SHIFT)) & locald70_LDPRR575_lumd2106_MASK)
/*! @} */

/*! @name LDPRR576 - ldprofilereg576 */
/*! @{ */

#define locald70_LDPRR576_lumd2109_MASK          (0x3FFU)
#define locald70_LDPRR576_lumd2109_SHIFT         (0U)
/*! lumd2109 - lumdat_2109 */
#define locald70_LDPRR576_lumd2109(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR576_lumd2109_SHIFT)) & locald70_LDPRR576_lumd2109_MASK)

#define locald70_LDPRR576_lumd2108_MASK          (0x3FF0000U)
#define locald70_LDPRR576_lumd2108_SHIFT         (16U)
/*! lumd2108 - lumdat_2108 */
#define locald70_LDPRR576_lumd2108(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR576_lumd2108_SHIFT)) & locald70_LDPRR576_lumd2108_MASK)
/*! @} */

/*! @name LDPRR577 - ldprofilereg577 */
/*! @{ */

#define locald70_LDPRR577_lumd2111_MASK          (0x3FFU)
#define locald70_LDPRR577_lumd2111_SHIFT         (0U)
/*! lumd2111 - lumdat_2111 */
#define locald70_LDPRR577_lumd2111(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR577_lumd2111_SHIFT)) & locald70_LDPRR577_lumd2111_MASK)

#define locald70_LDPRR577_lumd2110_MASK          (0x3FF0000U)
#define locald70_LDPRR577_lumd2110_SHIFT         (16U)
/*! lumd2110 - lumdat_2110 */
#define locald70_LDPRR577_lumd2110(x)            (((uint32_t)(((uint32_t)(x)) << locald70_LDPRR577_lumd2110_SHIFT)) & locald70_LDPRR577_lumd2110_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald70_Register_Masks */


/*!
 * @}
 */ /* end of group locald70_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD70_H_ */

