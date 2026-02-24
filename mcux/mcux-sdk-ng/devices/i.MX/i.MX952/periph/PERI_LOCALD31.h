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
**         CMSIS Peripheral Access Layer for locald31
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
 * @file PERI_locald31.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald31
 *
 * CMSIS Peripheral Access Layer for locald31
 */

#if !defined(PERI_LOCALD31_H_)
#define PERI_LOCALD31_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald31 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald31_Peripheral_Access_Layer locald31 Peripheral Access Layer
 * @{
 */

/** locald31 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR080;                          /**< ldprofilereg080, offset: 0x0 */
  __IO uint32_t LDPRR081;                          /**< ldprofilereg081, offset: 0x4 */
  __IO uint32_t LDPRR082;                          /**< ldprofilereg082, offset: 0x8 */
  __IO uint32_t LDPRR083;                          /**< ldprofilereg083, offset: 0xC */
  __IO uint32_t LDPRR084;                          /**< ldprofilereg084, offset: 0x10 */
  __IO uint32_t LDPRR085;                          /**< ldprofilereg085, offset: 0x14 */
  __IO uint32_t LDPRR086;                          /**< ldprofilereg086, offset: 0x18 */
  __IO uint32_t LDPRR087;                          /**< ldprofilereg087, offset: 0x1C */
  __IO uint32_t LDPRR088;                          /**< ldprofilereg088, offset: 0x20 */
  __IO uint32_t LDPRR089;                          /**< ldprofilereg089, offset: 0x24 */
  __IO uint32_t LDPRR08A;                          /**< ldprofilereg08a, offset: 0x28 */
  __IO uint32_t LDPRR08B;                          /**< ldprofilereg08b, offset: 0x2C */
  __IO uint32_t LDPRR08C;                          /**< ldprofilereg08c, offset: 0x30 */
  __IO uint32_t LDPRR08D;                          /**< ldprofilereg08d, offset: 0x34 */
  __IO uint32_t LDPRR08E;                          /**< ldprofilereg08e, offset: 0x38 */
  __IO uint32_t LDPRR08F;                          /**< ldprofilereg08f, offset: 0x3C */
  __IO uint32_t LDPRR090;                          /**< ldprofilereg090, offset: 0x40 */
  __IO uint32_t LDPRR091;                          /**< ldprofilereg091, offset: 0x44 */
  __IO uint32_t LDPRR092;                          /**< ldprofilereg092, offset: 0x48 */
  __IO uint32_t LDPRR093;                          /**< ldprofilereg093, offset: 0x4C */
  __IO uint32_t LDPRR094;                          /**< ldprofilereg094, offset: 0x50 */
  __IO uint32_t LDPRR095;                          /**< ldprofilereg095, offset: 0x54 */
  __IO uint32_t LDPRR096;                          /**< ldprofilereg096, offset: 0x58 */
  __IO uint32_t LDPRR097;                          /**< ldprofilereg097, offset: 0x5C */
} locald31_Type;

/* ----------------------------------------------------------------------------
   -- locald31 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald31_Register_Masks locald31 Register Masks
 * @{
 */

/*! @name LDPRR080 - ldprofilereg080 */
/*! @{ */

#define locald31_LDPRR080_lumd193_MASK           (0x3FFU)
#define locald31_LDPRR080_lumd193_SHIFT          (0U)
/*! lumd193 - lumdat_193 */
#define locald31_LDPRR080_lumd193(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR080_lumd193_SHIFT)) & locald31_LDPRR080_lumd193_MASK)

#define locald31_LDPRR080_lumd192_MASK           (0x3FF0000U)
#define locald31_LDPRR080_lumd192_SHIFT          (16U)
/*! lumd192 - lumdat_192 */
#define locald31_LDPRR080_lumd192(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR080_lumd192_SHIFT)) & locald31_LDPRR080_lumd192_MASK)
/*! @} */

/*! @name LDPRR081 - ldprofilereg081 */
/*! @{ */

#define locald31_LDPRR081_lumd195_MASK           (0x3FFU)
#define locald31_LDPRR081_lumd195_SHIFT          (0U)
/*! lumd195 - lumdat_195 */
#define locald31_LDPRR081_lumd195(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR081_lumd195_SHIFT)) & locald31_LDPRR081_lumd195_MASK)

#define locald31_LDPRR081_lumd194_MASK           (0x3FF0000U)
#define locald31_LDPRR081_lumd194_SHIFT          (16U)
/*! lumd194 - lumdat_194 */
#define locald31_LDPRR081_lumd194(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR081_lumd194_SHIFT)) & locald31_LDPRR081_lumd194_MASK)
/*! @} */

/*! @name LDPRR082 - ldprofilereg082 */
/*! @{ */

#define locald31_LDPRR082_lumd197_MASK           (0x3FFU)
#define locald31_LDPRR082_lumd197_SHIFT          (0U)
/*! lumd197 - lumdat_197 */
#define locald31_LDPRR082_lumd197(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR082_lumd197_SHIFT)) & locald31_LDPRR082_lumd197_MASK)

#define locald31_LDPRR082_lumd196_MASK           (0x3FF0000U)
#define locald31_LDPRR082_lumd196_SHIFT          (16U)
/*! lumd196 - lumdat_196 */
#define locald31_LDPRR082_lumd196(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR082_lumd196_SHIFT)) & locald31_LDPRR082_lumd196_MASK)
/*! @} */

/*! @name LDPRR083 - ldprofilereg083 */
/*! @{ */

#define locald31_LDPRR083_lumd199_MASK           (0x3FFU)
#define locald31_LDPRR083_lumd199_SHIFT          (0U)
/*! lumd199 - lumdat_199 */
#define locald31_LDPRR083_lumd199(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR083_lumd199_SHIFT)) & locald31_LDPRR083_lumd199_MASK)

#define locald31_LDPRR083_lumd198_MASK           (0x3FF0000U)
#define locald31_LDPRR083_lumd198_SHIFT          (16U)
/*! lumd198 - lumdat_198 */
#define locald31_LDPRR083_lumd198(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR083_lumd198_SHIFT)) & locald31_LDPRR083_lumd198_MASK)
/*! @} */

/*! @name LDPRR084 - ldprofilereg084 */
/*! @{ */

#define locald31_LDPRR084_lumd201_MASK           (0x3FFU)
#define locald31_LDPRR084_lumd201_SHIFT          (0U)
/*! lumd201 - lumdat_201 */
#define locald31_LDPRR084_lumd201(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR084_lumd201_SHIFT)) & locald31_LDPRR084_lumd201_MASK)

#define locald31_LDPRR084_lumd200_MASK           (0x3FF0000U)
#define locald31_LDPRR084_lumd200_SHIFT          (16U)
/*! lumd200 - lumdat_200 */
#define locald31_LDPRR084_lumd200(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR084_lumd200_SHIFT)) & locald31_LDPRR084_lumd200_MASK)
/*! @} */

/*! @name LDPRR085 - ldprofilereg085 */
/*! @{ */

#define locald31_LDPRR085_lumd203_MASK           (0x3FFU)
#define locald31_LDPRR085_lumd203_SHIFT          (0U)
/*! lumd203 - lumdat_203 */
#define locald31_LDPRR085_lumd203(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR085_lumd203_SHIFT)) & locald31_LDPRR085_lumd203_MASK)

#define locald31_LDPRR085_lumd202_MASK           (0x3FF0000U)
#define locald31_LDPRR085_lumd202_SHIFT          (16U)
/*! lumd202 - lumdat_202 */
#define locald31_LDPRR085_lumd202(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR085_lumd202_SHIFT)) & locald31_LDPRR085_lumd202_MASK)
/*! @} */

/*! @name LDPRR086 - ldprofilereg086 */
/*! @{ */

#define locald31_LDPRR086_lumd205_MASK           (0x3FFU)
#define locald31_LDPRR086_lumd205_SHIFT          (0U)
/*! lumd205 - lumdat_205 */
#define locald31_LDPRR086_lumd205(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR086_lumd205_SHIFT)) & locald31_LDPRR086_lumd205_MASK)

#define locald31_LDPRR086_lumd204_MASK           (0x3FF0000U)
#define locald31_LDPRR086_lumd204_SHIFT          (16U)
/*! lumd204 - lumdat_204 */
#define locald31_LDPRR086_lumd204(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR086_lumd204_SHIFT)) & locald31_LDPRR086_lumd204_MASK)
/*! @} */

/*! @name LDPRR087 - ldprofilereg087 */
/*! @{ */

#define locald31_LDPRR087_lumd207_MASK           (0x3FFU)
#define locald31_LDPRR087_lumd207_SHIFT          (0U)
/*! lumd207 - lumdat_207 */
#define locald31_LDPRR087_lumd207(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR087_lumd207_SHIFT)) & locald31_LDPRR087_lumd207_MASK)

#define locald31_LDPRR087_lumd206_MASK           (0x3FF0000U)
#define locald31_LDPRR087_lumd206_SHIFT          (16U)
/*! lumd206 - lumdat_206 */
#define locald31_LDPRR087_lumd206(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR087_lumd206_SHIFT)) & locald31_LDPRR087_lumd206_MASK)
/*! @} */

/*! @name LDPRR088 - ldprofilereg088 */
/*! @{ */

#define locald31_LDPRR088_lumd209_MASK           (0x3FFU)
#define locald31_LDPRR088_lumd209_SHIFT          (0U)
/*! lumd209 - lumdat_209 */
#define locald31_LDPRR088_lumd209(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR088_lumd209_SHIFT)) & locald31_LDPRR088_lumd209_MASK)

#define locald31_LDPRR088_lumd208_MASK           (0x3FF0000U)
#define locald31_LDPRR088_lumd208_SHIFT          (16U)
/*! lumd208 - lumdat_208 */
#define locald31_LDPRR088_lumd208(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR088_lumd208_SHIFT)) & locald31_LDPRR088_lumd208_MASK)
/*! @} */

/*! @name LDPRR089 - ldprofilereg089 */
/*! @{ */

#define locald31_LDPRR089_lumd211_MASK           (0x3FFU)
#define locald31_LDPRR089_lumd211_SHIFT          (0U)
/*! lumd211 - lumdat_211 */
#define locald31_LDPRR089_lumd211(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR089_lumd211_SHIFT)) & locald31_LDPRR089_lumd211_MASK)

#define locald31_LDPRR089_lumd210_MASK           (0x3FF0000U)
#define locald31_LDPRR089_lumd210_SHIFT          (16U)
/*! lumd210 - lumdat_210 */
#define locald31_LDPRR089_lumd210(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR089_lumd210_SHIFT)) & locald31_LDPRR089_lumd210_MASK)
/*! @} */

/*! @name LDPRR08A - ldprofilereg08a */
/*! @{ */

#define locald31_LDPRR08A_lumd213_MASK           (0x3FFU)
#define locald31_LDPRR08A_lumd213_SHIFT          (0U)
/*! lumd213 - lumdat_213 */
#define locald31_LDPRR08A_lumd213(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR08A_lumd213_SHIFT)) & locald31_LDPRR08A_lumd213_MASK)

#define locald31_LDPRR08A_lumd212_MASK           (0x3FF0000U)
#define locald31_LDPRR08A_lumd212_SHIFT          (16U)
/*! lumd212 - lumdat_212 */
#define locald31_LDPRR08A_lumd212(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR08A_lumd212_SHIFT)) & locald31_LDPRR08A_lumd212_MASK)
/*! @} */

/*! @name LDPRR08B - ldprofilereg08b */
/*! @{ */

#define locald31_LDPRR08B_lumd215_MASK           (0x3FFU)
#define locald31_LDPRR08B_lumd215_SHIFT          (0U)
/*! lumd215 - lumdat_215 */
#define locald31_LDPRR08B_lumd215(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR08B_lumd215_SHIFT)) & locald31_LDPRR08B_lumd215_MASK)

#define locald31_LDPRR08B_lumd214_MASK           (0x3FF0000U)
#define locald31_LDPRR08B_lumd214_SHIFT          (16U)
/*! lumd214 - lumdat_214 */
#define locald31_LDPRR08B_lumd214(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR08B_lumd214_SHIFT)) & locald31_LDPRR08B_lumd214_MASK)
/*! @} */

/*! @name LDPRR08C - ldprofilereg08c */
/*! @{ */

#define locald31_LDPRR08C_lumd217_MASK           (0x3FFU)
#define locald31_LDPRR08C_lumd217_SHIFT          (0U)
/*! lumd217 - lumdat_217 */
#define locald31_LDPRR08C_lumd217(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR08C_lumd217_SHIFT)) & locald31_LDPRR08C_lumd217_MASK)

#define locald31_LDPRR08C_lumd216_MASK           (0x3FF0000U)
#define locald31_LDPRR08C_lumd216_SHIFT          (16U)
/*! lumd216 - lumdat_216 */
#define locald31_LDPRR08C_lumd216(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR08C_lumd216_SHIFT)) & locald31_LDPRR08C_lumd216_MASK)
/*! @} */

/*! @name LDPRR08D - ldprofilereg08d */
/*! @{ */

#define locald31_LDPRR08D_lumd219_MASK           (0x3FFU)
#define locald31_LDPRR08D_lumd219_SHIFT          (0U)
/*! lumd219 - lumdat_219 */
#define locald31_LDPRR08D_lumd219(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR08D_lumd219_SHIFT)) & locald31_LDPRR08D_lumd219_MASK)

#define locald31_LDPRR08D_lumd218_MASK           (0x3FF0000U)
#define locald31_LDPRR08D_lumd218_SHIFT          (16U)
/*! lumd218 - lumdat_218 */
#define locald31_LDPRR08D_lumd218(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR08D_lumd218_SHIFT)) & locald31_LDPRR08D_lumd218_MASK)
/*! @} */

/*! @name LDPRR08E - ldprofilereg08e */
/*! @{ */

#define locald31_LDPRR08E_lumd221_MASK           (0x3FFU)
#define locald31_LDPRR08E_lumd221_SHIFT          (0U)
/*! lumd221 - lumdat_221 */
#define locald31_LDPRR08E_lumd221(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR08E_lumd221_SHIFT)) & locald31_LDPRR08E_lumd221_MASK)

#define locald31_LDPRR08E_lumd220_MASK           (0x3FF0000U)
#define locald31_LDPRR08E_lumd220_SHIFT          (16U)
/*! lumd220 - lumdat_220 */
#define locald31_LDPRR08E_lumd220(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR08E_lumd220_SHIFT)) & locald31_LDPRR08E_lumd220_MASK)
/*! @} */

/*! @name LDPRR08F - ldprofilereg08f */
/*! @{ */

#define locald31_LDPRR08F_lumd223_MASK           (0x3FFU)
#define locald31_LDPRR08F_lumd223_SHIFT          (0U)
/*! lumd223 - lumdat_223 */
#define locald31_LDPRR08F_lumd223(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR08F_lumd223_SHIFT)) & locald31_LDPRR08F_lumd223_MASK)

#define locald31_LDPRR08F_lumd222_MASK           (0x3FF0000U)
#define locald31_LDPRR08F_lumd222_SHIFT          (16U)
/*! lumd222 - lumdat_222 */
#define locald31_LDPRR08F_lumd222(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR08F_lumd222_SHIFT)) & locald31_LDPRR08F_lumd222_MASK)
/*! @} */

/*! @name LDPRR090 - ldprofilereg090 */
/*! @{ */

#define locald31_LDPRR090_lumd225_MASK           (0x3FFU)
#define locald31_LDPRR090_lumd225_SHIFT          (0U)
/*! lumd225 - lumdat_225 */
#define locald31_LDPRR090_lumd225(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR090_lumd225_SHIFT)) & locald31_LDPRR090_lumd225_MASK)

#define locald31_LDPRR090_lumd224_MASK           (0x3FF0000U)
#define locald31_LDPRR090_lumd224_SHIFT          (16U)
/*! lumd224 - lumdat_224 */
#define locald31_LDPRR090_lumd224(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR090_lumd224_SHIFT)) & locald31_LDPRR090_lumd224_MASK)
/*! @} */

/*! @name LDPRR091 - ldprofilereg091 */
/*! @{ */

#define locald31_LDPRR091_lumd227_MASK           (0x3FFU)
#define locald31_LDPRR091_lumd227_SHIFT          (0U)
/*! lumd227 - lumdat_227 */
#define locald31_LDPRR091_lumd227(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR091_lumd227_SHIFT)) & locald31_LDPRR091_lumd227_MASK)

#define locald31_LDPRR091_lumd226_MASK           (0x3FF0000U)
#define locald31_LDPRR091_lumd226_SHIFT          (16U)
/*! lumd226 - lumdat_226 */
#define locald31_LDPRR091_lumd226(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR091_lumd226_SHIFT)) & locald31_LDPRR091_lumd226_MASK)
/*! @} */

/*! @name LDPRR092 - ldprofilereg092 */
/*! @{ */

#define locald31_LDPRR092_lumd229_MASK           (0x3FFU)
#define locald31_LDPRR092_lumd229_SHIFT          (0U)
/*! lumd229 - lumdat_229 */
#define locald31_LDPRR092_lumd229(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR092_lumd229_SHIFT)) & locald31_LDPRR092_lumd229_MASK)

#define locald31_LDPRR092_lumd228_MASK           (0x3FF0000U)
#define locald31_LDPRR092_lumd228_SHIFT          (16U)
/*! lumd228 - lumdat_228 */
#define locald31_LDPRR092_lumd228(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR092_lumd228_SHIFT)) & locald31_LDPRR092_lumd228_MASK)
/*! @} */

/*! @name LDPRR093 - ldprofilereg093 */
/*! @{ */

#define locald31_LDPRR093_lumd231_MASK           (0x3FFU)
#define locald31_LDPRR093_lumd231_SHIFT          (0U)
/*! lumd231 - lumdat_231 */
#define locald31_LDPRR093_lumd231(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR093_lumd231_SHIFT)) & locald31_LDPRR093_lumd231_MASK)

#define locald31_LDPRR093_lumd230_MASK           (0x3FF0000U)
#define locald31_LDPRR093_lumd230_SHIFT          (16U)
/*! lumd230 - lumdat_230 */
#define locald31_LDPRR093_lumd230(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR093_lumd230_SHIFT)) & locald31_LDPRR093_lumd230_MASK)
/*! @} */

/*! @name LDPRR094 - ldprofilereg094 */
/*! @{ */

#define locald31_LDPRR094_lumd233_MASK           (0x3FFU)
#define locald31_LDPRR094_lumd233_SHIFT          (0U)
/*! lumd233 - lumdat_233 */
#define locald31_LDPRR094_lumd233(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR094_lumd233_SHIFT)) & locald31_LDPRR094_lumd233_MASK)

#define locald31_LDPRR094_lumd232_MASK           (0x3FF0000U)
#define locald31_LDPRR094_lumd232_SHIFT          (16U)
/*! lumd232 - lumdat_232 */
#define locald31_LDPRR094_lumd232(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR094_lumd232_SHIFT)) & locald31_LDPRR094_lumd232_MASK)
/*! @} */

/*! @name LDPRR095 - ldprofilereg095 */
/*! @{ */

#define locald31_LDPRR095_lumd235_MASK           (0x3FFU)
#define locald31_LDPRR095_lumd235_SHIFT          (0U)
/*! lumd235 - lumdat_235 */
#define locald31_LDPRR095_lumd235(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR095_lumd235_SHIFT)) & locald31_LDPRR095_lumd235_MASK)

#define locald31_LDPRR095_lumd234_MASK           (0x3FF0000U)
#define locald31_LDPRR095_lumd234_SHIFT          (16U)
/*! lumd234 - lumdat_234 */
#define locald31_LDPRR095_lumd234(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR095_lumd234_SHIFT)) & locald31_LDPRR095_lumd234_MASK)
/*! @} */

/*! @name LDPRR096 - ldprofilereg096 */
/*! @{ */

#define locald31_LDPRR096_lumd237_MASK           (0x3FFU)
#define locald31_LDPRR096_lumd237_SHIFT          (0U)
/*! lumd237 - lumdat_237 */
#define locald31_LDPRR096_lumd237(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR096_lumd237_SHIFT)) & locald31_LDPRR096_lumd237_MASK)

#define locald31_LDPRR096_lumd236_MASK           (0x3FF0000U)
#define locald31_LDPRR096_lumd236_SHIFT          (16U)
/*! lumd236 - lumdat_236 */
#define locald31_LDPRR096_lumd236(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR096_lumd236_SHIFT)) & locald31_LDPRR096_lumd236_MASK)
/*! @} */

/*! @name LDPRR097 - ldprofilereg097 */
/*! @{ */

#define locald31_LDPRR097_lumd239_MASK           (0x3FFU)
#define locald31_LDPRR097_lumd239_SHIFT          (0U)
/*! lumd239 - lumdat_239 */
#define locald31_LDPRR097_lumd239(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR097_lumd239_SHIFT)) & locald31_LDPRR097_lumd239_MASK)

#define locald31_LDPRR097_lumd238_MASK           (0x3FF0000U)
#define locald31_LDPRR097_lumd238_SHIFT          (16U)
/*! lumd238 - lumdat_238 */
#define locald31_LDPRR097_lumd238(x)             (((uint32_t)(((uint32_t)(x)) << locald31_LDPRR097_lumd238_SHIFT)) & locald31_LDPRR097_lumd238_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald31_Register_Masks */


/*!
 * @}
 */ /* end of group locald31_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD31_H_ */

