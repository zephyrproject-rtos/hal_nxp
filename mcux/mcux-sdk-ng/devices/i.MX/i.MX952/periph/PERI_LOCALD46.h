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
**         CMSIS Peripheral Access Layer for locald46
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
 * @file PERI_locald46.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald46
 *
 * CMSIS Peripheral Access Layer for locald46
 */

#if !defined(PERI_LOCALD46_H_)
#define PERI_LOCALD46_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald46 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald46_Peripheral_Access_Layer locald46 Peripheral Access Layer
 * @{
 */

/** locald46 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR260;                          /**< ldprofilereg260, offset: 0x0 */
  __IO uint32_t LDPRR261;                          /**< ldprofilereg261, offset: 0x4 */
  __IO uint32_t LDPRR262;                          /**< ldprofilereg262, offset: 0x8 */
  __IO uint32_t LDPRR263;                          /**< ldprofilereg263, offset: 0xC */
  __IO uint32_t LDPRR264;                          /**< ldprofilereg264, offset: 0x10 */
  __IO uint32_t LDPRR265;                          /**< ldprofilereg265, offset: 0x14 */
  __IO uint32_t LDPRR266;                          /**< ldprofilereg266, offset: 0x18 */
  __IO uint32_t LDPRR267;                          /**< ldprofilereg267, offset: 0x1C */
  __IO uint32_t LDPRR268;                          /**< ldprofilereg268, offset: 0x20 */
  __IO uint32_t LDPRR269;                          /**< ldprofilereg269, offset: 0x24 */
  __IO uint32_t LDPRR26A;                          /**< ldprofilereg26a, offset: 0x28 */
  __IO uint32_t LDPRR26B;                          /**< ldprofilereg26b, offset: 0x2C */
  __IO uint32_t LDPRR26C;                          /**< ldprofilereg26c, offset: 0x30 */
  __IO uint32_t LDPRR26D;                          /**< ldprofilereg26d, offset: 0x34 */
  __IO uint32_t LDPRR26E;                          /**< ldprofilereg26e, offset: 0x38 */
  __IO uint32_t LDPRR26F;                          /**< ldprofilereg26f, offset: 0x3C */
  __IO uint32_t LDPRR270;                          /**< ldprofilereg270, offset: 0x40 */
  __IO uint32_t LDPRR271;                          /**< ldprofilereg271, offset: 0x44 */
  __IO uint32_t LDPRR272;                          /**< ldprofilereg272, offset: 0x48 */
  __IO uint32_t LDPRR273;                          /**< ldprofilereg273, offset: 0x4C */
  __IO uint32_t LDPRR274;                          /**< ldprofilereg274, offset: 0x50 */
  __IO uint32_t LDPRR275;                          /**< ldprofilereg275, offset: 0x54 */
  __IO uint32_t LDPRR276;                          /**< ldprofilereg276, offset: 0x58 */
  __IO uint32_t LDPRR277;                          /**< ldprofilereg277, offset: 0x5C */
} locald46_Type;

/* ----------------------------------------------------------------------------
   -- locald46 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald46_Register_Masks locald46 Register Masks
 * @{
 */

/*! @name LDPRR260 - ldprofilereg260 */
/*! @{ */

#define locald46_LDPRR260_lumd913_MASK           (0x3FFU)
#define locald46_LDPRR260_lumd913_SHIFT          (0U)
/*! lumd913 - lumdat_913 */
#define locald46_LDPRR260_lumd913(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR260_lumd913_SHIFT)) & locald46_LDPRR260_lumd913_MASK)

#define locald46_LDPRR260_lumd912_MASK           (0x3FF0000U)
#define locald46_LDPRR260_lumd912_SHIFT          (16U)
/*! lumd912 - lumdat_912 */
#define locald46_LDPRR260_lumd912(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR260_lumd912_SHIFT)) & locald46_LDPRR260_lumd912_MASK)
/*! @} */

/*! @name LDPRR261 - ldprofilereg261 */
/*! @{ */

#define locald46_LDPRR261_lumd915_MASK           (0x3FFU)
#define locald46_LDPRR261_lumd915_SHIFT          (0U)
/*! lumd915 - lumdat_915 */
#define locald46_LDPRR261_lumd915(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR261_lumd915_SHIFT)) & locald46_LDPRR261_lumd915_MASK)

#define locald46_LDPRR261_lumd914_MASK           (0x3FF0000U)
#define locald46_LDPRR261_lumd914_SHIFT          (16U)
/*! lumd914 - lumdat_914 */
#define locald46_LDPRR261_lumd914(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR261_lumd914_SHIFT)) & locald46_LDPRR261_lumd914_MASK)
/*! @} */

/*! @name LDPRR262 - ldprofilereg262 */
/*! @{ */

#define locald46_LDPRR262_lumd917_MASK           (0x3FFU)
#define locald46_LDPRR262_lumd917_SHIFT          (0U)
/*! lumd917 - lumdat_917 */
#define locald46_LDPRR262_lumd917(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR262_lumd917_SHIFT)) & locald46_LDPRR262_lumd917_MASK)

#define locald46_LDPRR262_lumd916_MASK           (0x3FF0000U)
#define locald46_LDPRR262_lumd916_SHIFT          (16U)
/*! lumd916 - lumdat_916 */
#define locald46_LDPRR262_lumd916(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR262_lumd916_SHIFT)) & locald46_LDPRR262_lumd916_MASK)
/*! @} */

/*! @name LDPRR263 - ldprofilereg263 */
/*! @{ */

#define locald46_LDPRR263_lumd919_MASK           (0x3FFU)
#define locald46_LDPRR263_lumd919_SHIFT          (0U)
/*! lumd919 - lumdat_919 */
#define locald46_LDPRR263_lumd919(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR263_lumd919_SHIFT)) & locald46_LDPRR263_lumd919_MASK)

#define locald46_LDPRR263_lumd918_MASK           (0x3FF0000U)
#define locald46_LDPRR263_lumd918_SHIFT          (16U)
/*! lumd918 - lumdat_918 */
#define locald46_LDPRR263_lumd918(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR263_lumd918_SHIFT)) & locald46_LDPRR263_lumd918_MASK)
/*! @} */

/*! @name LDPRR264 - ldprofilereg264 */
/*! @{ */

#define locald46_LDPRR264_lumd921_MASK           (0x3FFU)
#define locald46_LDPRR264_lumd921_SHIFT          (0U)
/*! lumd921 - lumdat_921 */
#define locald46_LDPRR264_lumd921(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR264_lumd921_SHIFT)) & locald46_LDPRR264_lumd921_MASK)

#define locald46_LDPRR264_lumd920_MASK           (0x3FF0000U)
#define locald46_LDPRR264_lumd920_SHIFT          (16U)
/*! lumd920 - lumdat_920 */
#define locald46_LDPRR264_lumd920(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR264_lumd920_SHIFT)) & locald46_LDPRR264_lumd920_MASK)
/*! @} */

/*! @name LDPRR265 - ldprofilereg265 */
/*! @{ */

#define locald46_LDPRR265_lumd923_MASK           (0x3FFU)
#define locald46_LDPRR265_lumd923_SHIFT          (0U)
/*! lumd923 - lumdat_923 */
#define locald46_LDPRR265_lumd923(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR265_lumd923_SHIFT)) & locald46_LDPRR265_lumd923_MASK)

#define locald46_LDPRR265_lumd922_MASK           (0x3FF0000U)
#define locald46_LDPRR265_lumd922_SHIFT          (16U)
/*! lumd922 - lumdat_922 */
#define locald46_LDPRR265_lumd922(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR265_lumd922_SHIFT)) & locald46_LDPRR265_lumd922_MASK)
/*! @} */

/*! @name LDPRR266 - ldprofilereg266 */
/*! @{ */

#define locald46_LDPRR266_lumd925_MASK           (0x3FFU)
#define locald46_LDPRR266_lumd925_SHIFT          (0U)
/*! lumd925 - lumdat_925 */
#define locald46_LDPRR266_lumd925(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR266_lumd925_SHIFT)) & locald46_LDPRR266_lumd925_MASK)

#define locald46_LDPRR266_lumd924_MASK           (0x3FF0000U)
#define locald46_LDPRR266_lumd924_SHIFT          (16U)
/*! lumd924 - lumdat_924 */
#define locald46_LDPRR266_lumd924(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR266_lumd924_SHIFT)) & locald46_LDPRR266_lumd924_MASK)
/*! @} */

/*! @name LDPRR267 - ldprofilereg267 */
/*! @{ */

#define locald46_LDPRR267_lumd927_MASK           (0x3FFU)
#define locald46_LDPRR267_lumd927_SHIFT          (0U)
/*! lumd927 - lumdat_927 */
#define locald46_LDPRR267_lumd927(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR267_lumd927_SHIFT)) & locald46_LDPRR267_lumd927_MASK)

#define locald46_LDPRR267_lumd926_MASK           (0x3FF0000U)
#define locald46_LDPRR267_lumd926_SHIFT          (16U)
/*! lumd926 - lumdat_926 */
#define locald46_LDPRR267_lumd926(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR267_lumd926_SHIFT)) & locald46_LDPRR267_lumd926_MASK)
/*! @} */

/*! @name LDPRR268 - ldprofilereg268 */
/*! @{ */

#define locald46_LDPRR268_lumd929_MASK           (0x3FFU)
#define locald46_LDPRR268_lumd929_SHIFT          (0U)
/*! lumd929 - lumdat_929 */
#define locald46_LDPRR268_lumd929(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR268_lumd929_SHIFT)) & locald46_LDPRR268_lumd929_MASK)

#define locald46_LDPRR268_lumd928_MASK           (0x3FF0000U)
#define locald46_LDPRR268_lumd928_SHIFT          (16U)
/*! lumd928 - lumdat_928 */
#define locald46_LDPRR268_lumd928(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR268_lumd928_SHIFT)) & locald46_LDPRR268_lumd928_MASK)
/*! @} */

/*! @name LDPRR269 - ldprofilereg269 */
/*! @{ */

#define locald46_LDPRR269_lumd931_MASK           (0x3FFU)
#define locald46_LDPRR269_lumd931_SHIFT          (0U)
/*! lumd931 - lumdat_931 */
#define locald46_LDPRR269_lumd931(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR269_lumd931_SHIFT)) & locald46_LDPRR269_lumd931_MASK)

#define locald46_LDPRR269_lumd930_MASK           (0x3FF0000U)
#define locald46_LDPRR269_lumd930_SHIFT          (16U)
/*! lumd930 - lumdat_930 */
#define locald46_LDPRR269_lumd930(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR269_lumd930_SHIFT)) & locald46_LDPRR269_lumd930_MASK)
/*! @} */

/*! @name LDPRR26A - ldprofilereg26a */
/*! @{ */

#define locald46_LDPRR26A_lumd933_MASK           (0x3FFU)
#define locald46_LDPRR26A_lumd933_SHIFT          (0U)
/*! lumd933 - lumdat_933 */
#define locald46_LDPRR26A_lumd933(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR26A_lumd933_SHIFT)) & locald46_LDPRR26A_lumd933_MASK)

#define locald46_LDPRR26A_lumd932_MASK           (0x3FF0000U)
#define locald46_LDPRR26A_lumd932_SHIFT          (16U)
/*! lumd932 - lumdat_932 */
#define locald46_LDPRR26A_lumd932(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR26A_lumd932_SHIFT)) & locald46_LDPRR26A_lumd932_MASK)
/*! @} */

/*! @name LDPRR26B - ldprofilereg26b */
/*! @{ */

#define locald46_LDPRR26B_lumd935_MASK           (0x3FFU)
#define locald46_LDPRR26B_lumd935_SHIFT          (0U)
/*! lumd935 - lumdat_935 */
#define locald46_LDPRR26B_lumd935(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR26B_lumd935_SHIFT)) & locald46_LDPRR26B_lumd935_MASK)

#define locald46_LDPRR26B_lumd934_MASK           (0x3FF0000U)
#define locald46_LDPRR26B_lumd934_SHIFT          (16U)
/*! lumd934 - lumdat_934 */
#define locald46_LDPRR26B_lumd934(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR26B_lumd934_SHIFT)) & locald46_LDPRR26B_lumd934_MASK)
/*! @} */

/*! @name LDPRR26C - ldprofilereg26c */
/*! @{ */

#define locald46_LDPRR26C_lumd937_MASK           (0x3FFU)
#define locald46_LDPRR26C_lumd937_SHIFT          (0U)
/*! lumd937 - lumdat_937 */
#define locald46_LDPRR26C_lumd937(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR26C_lumd937_SHIFT)) & locald46_LDPRR26C_lumd937_MASK)

#define locald46_LDPRR26C_lumd936_MASK           (0x3FF0000U)
#define locald46_LDPRR26C_lumd936_SHIFT          (16U)
/*! lumd936 - lumdat_936 */
#define locald46_LDPRR26C_lumd936(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR26C_lumd936_SHIFT)) & locald46_LDPRR26C_lumd936_MASK)
/*! @} */

/*! @name LDPRR26D - ldprofilereg26d */
/*! @{ */

#define locald46_LDPRR26D_lumd939_MASK           (0x3FFU)
#define locald46_LDPRR26D_lumd939_SHIFT          (0U)
/*! lumd939 - lumdat_939 */
#define locald46_LDPRR26D_lumd939(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR26D_lumd939_SHIFT)) & locald46_LDPRR26D_lumd939_MASK)

#define locald46_LDPRR26D_lumd938_MASK           (0x3FF0000U)
#define locald46_LDPRR26D_lumd938_SHIFT          (16U)
/*! lumd938 - lumdat_938 */
#define locald46_LDPRR26D_lumd938(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR26D_lumd938_SHIFT)) & locald46_LDPRR26D_lumd938_MASK)
/*! @} */

/*! @name LDPRR26E - ldprofilereg26e */
/*! @{ */

#define locald46_LDPRR26E_lumd941_MASK           (0x3FFU)
#define locald46_LDPRR26E_lumd941_SHIFT          (0U)
/*! lumd941 - lumdat_941 */
#define locald46_LDPRR26E_lumd941(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR26E_lumd941_SHIFT)) & locald46_LDPRR26E_lumd941_MASK)

#define locald46_LDPRR26E_lumd940_MASK           (0x3FF0000U)
#define locald46_LDPRR26E_lumd940_SHIFT          (16U)
/*! lumd940 - lumdat_940 */
#define locald46_LDPRR26E_lumd940(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR26E_lumd940_SHIFT)) & locald46_LDPRR26E_lumd940_MASK)
/*! @} */

/*! @name LDPRR26F - ldprofilereg26f */
/*! @{ */

#define locald46_LDPRR26F_lumd943_MASK           (0x3FFU)
#define locald46_LDPRR26F_lumd943_SHIFT          (0U)
/*! lumd943 - lumdat_943 */
#define locald46_LDPRR26F_lumd943(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR26F_lumd943_SHIFT)) & locald46_LDPRR26F_lumd943_MASK)

#define locald46_LDPRR26F_lumd942_MASK           (0x3FF0000U)
#define locald46_LDPRR26F_lumd942_SHIFT          (16U)
/*! lumd942 - lumdat_942 */
#define locald46_LDPRR26F_lumd942(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR26F_lumd942_SHIFT)) & locald46_LDPRR26F_lumd942_MASK)
/*! @} */

/*! @name LDPRR270 - ldprofilereg270 */
/*! @{ */

#define locald46_LDPRR270_lumd945_MASK           (0x3FFU)
#define locald46_LDPRR270_lumd945_SHIFT          (0U)
/*! lumd945 - lumdat_945 */
#define locald46_LDPRR270_lumd945(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR270_lumd945_SHIFT)) & locald46_LDPRR270_lumd945_MASK)

#define locald46_LDPRR270_lumd944_MASK           (0x3FF0000U)
#define locald46_LDPRR270_lumd944_SHIFT          (16U)
/*! lumd944 - lumdat_944 */
#define locald46_LDPRR270_lumd944(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR270_lumd944_SHIFT)) & locald46_LDPRR270_lumd944_MASK)
/*! @} */

/*! @name LDPRR271 - ldprofilereg271 */
/*! @{ */

#define locald46_LDPRR271_lumd947_MASK           (0x3FFU)
#define locald46_LDPRR271_lumd947_SHIFT          (0U)
/*! lumd947 - lumdat_947 */
#define locald46_LDPRR271_lumd947(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR271_lumd947_SHIFT)) & locald46_LDPRR271_lumd947_MASK)

#define locald46_LDPRR271_lumd946_MASK           (0x3FF0000U)
#define locald46_LDPRR271_lumd946_SHIFT          (16U)
/*! lumd946 - lumdat_946 */
#define locald46_LDPRR271_lumd946(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR271_lumd946_SHIFT)) & locald46_LDPRR271_lumd946_MASK)
/*! @} */

/*! @name LDPRR272 - ldprofilereg272 */
/*! @{ */

#define locald46_LDPRR272_lumd949_MASK           (0x3FFU)
#define locald46_LDPRR272_lumd949_SHIFT          (0U)
/*! lumd949 - lumdat_949 */
#define locald46_LDPRR272_lumd949(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR272_lumd949_SHIFT)) & locald46_LDPRR272_lumd949_MASK)

#define locald46_LDPRR272_lumd948_MASK           (0x3FF0000U)
#define locald46_LDPRR272_lumd948_SHIFT          (16U)
/*! lumd948 - lumdat_948 */
#define locald46_LDPRR272_lumd948(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR272_lumd948_SHIFT)) & locald46_LDPRR272_lumd948_MASK)
/*! @} */

/*! @name LDPRR273 - ldprofilereg273 */
/*! @{ */

#define locald46_LDPRR273_lumd951_MASK           (0x3FFU)
#define locald46_LDPRR273_lumd951_SHIFT          (0U)
/*! lumd951 - lumdat_951 */
#define locald46_LDPRR273_lumd951(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR273_lumd951_SHIFT)) & locald46_LDPRR273_lumd951_MASK)

#define locald46_LDPRR273_lumd950_MASK           (0x3FF0000U)
#define locald46_LDPRR273_lumd950_SHIFT          (16U)
/*! lumd950 - lumdat_950 */
#define locald46_LDPRR273_lumd950(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR273_lumd950_SHIFT)) & locald46_LDPRR273_lumd950_MASK)
/*! @} */

/*! @name LDPRR274 - ldprofilereg274 */
/*! @{ */

#define locald46_LDPRR274_lumd953_MASK           (0x3FFU)
#define locald46_LDPRR274_lumd953_SHIFT          (0U)
/*! lumd953 - lumdat_953 */
#define locald46_LDPRR274_lumd953(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR274_lumd953_SHIFT)) & locald46_LDPRR274_lumd953_MASK)

#define locald46_LDPRR274_lumd952_MASK           (0x3FF0000U)
#define locald46_LDPRR274_lumd952_SHIFT          (16U)
/*! lumd952 - lumdat_952 */
#define locald46_LDPRR274_lumd952(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR274_lumd952_SHIFT)) & locald46_LDPRR274_lumd952_MASK)
/*! @} */

/*! @name LDPRR275 - ldprofilereg275 */
/*! @{ */

#define locald46_LDPRR275_lumd955_MASK           (0x3FFU)
#define locald46_LDPRR275_lumd955_SHIFT          (0U)
/*! lumd955 - lumdat_955 */
#define locald46_LDPRR275_lumd955(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR275_lumd955_SHIFT)) & locald46_LDPRR275_lumd955_MASK)

#define locald46_LDPRR275_lumd954_MASK           (0x3FF0000U)
#define locald46_LDPRR275_lumd954_SHIFT          (16U)
/*! lumd954 - lumdat_954 */
#define locald46_LDPRR275_lumd954(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR275_lumd954_SHIFT)) & locald46_LDPRR275_lumd954_MASK)
/*! @} */

/*! @name LDPRR276 - ldprofilereg276 */
/*! @{ */

#define locald46_LDPRR276_lumd957_MASK           (0x3FFU)
#define locald46_LDPRR276_lumd957_SHIFT          (0U)
/*! lumd957 - lumdat_957 */
#define locald46_LDPRR276_lumd957(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR276_lumd957_SHIFT)) & locald46_LDPRR276_lumd957_MASK)

#define locald46_LDPRR276_lumd956_MASK           (0x3FF0000U)
#define locald46_LDPRR276_lumd956_SHIFT          (16U)
/*! lumd956 - lumdat_956 */
#define locald46_LDPRR276_lumd956(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR276_lumd956_SHIFT)) & locald46_LDPRR276_lumd956_MASK)
/*! @} */

/*! @name LDPRR277 - ldprofilereg277 */
/*! @{ */

#define locald46_LDPRR277_lumd959_MASK           (0x3FFU)
#define locald46_LDPRR277_lumd959_SHIFT          (0U)
/*! lumd959 - lumdat_959 */
#define locald46_LDPRR277_lumd959(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR277_lumd959_SHIFT)) & locald46_LDPRR277_lumd959_MASK)

#define locald46_LDPRR277_lumd958_MASK           (0x3FF0000U)
#define locald46_LDPRR277_lumd958_SHIFT          (16U)
/*! lumd958 - lumdat_958 */
#define locald46_LDPRR277_lumd958(x)             (((uint32_t)(((uint32_t)(x)) << locald46_LDPRR277_lumd958_SHIFT)) & locald46_LDPRR277_lumd958_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald46_Register_Masks */


/*!
 * @}
 */ /* end of group locald46_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD46_H_ */

