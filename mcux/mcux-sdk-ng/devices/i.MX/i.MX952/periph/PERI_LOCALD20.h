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
**         CMSIS Peripheral Access Layer for locald20
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
 * @file PERI_locald20.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald20
 *
 * CMSIS Peripheral Access Layer for locald20
 */

#if !defined(PERI_LOCALD20_H_)
#define PERI_LOCALD20_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald20 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald20_Peripheral_Access_Layer locald20 Peripheral Access Layer
 * @{
 */

/** locald20 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDBLR010;                          /**< ldblreg010, offset: 0x0 */
  __IO uint32_t LDBLR011;                          /**< ldblreg011, offset: 0x4 */
  __IO uint32_t LDBLR012;                          /**< ldblreg012, offset: 0x8 */
  __IO uint32_t LDBLR013;                          /**< ldblreg013, offset: 0xC */
  __IO uint32_t LDBLR014;                          /**< ldblreg014, offset: 0x10 */
  __IO uint32_t LDBLR015;                          /**< ldblreg015, offset: 0x14 */
  __IO uint32_t LDBLR016;                          /**< ldblreg016, offset: 0x18 */
  __IO uint32_t LDBLR017;                          /**< ldblreg017, offset: 0x1C */
  __IO uint32_t LDBLR018;                          /**< ldblreg018, offset: 0x20 */
  __IO uint32_t LDBLR019;                          /**< ldblreg019, offset: 0x24 */
  __IO uint32_t LDBLR01A;                          /**< ldblreg01a, offset: 0x28 */
  __IO uint32_t LDBLR01B;                          /**< ldblreg01b, offset: 0x2C */
  __IO uint32_t LDBLR01C;                          /**< ldblreg01c, offset: 0x30 */
  __IO uint32_t LDBLR01D;                          /**< ldblreg01d, offset: 0x34 */
  __IO uint32_t LDBLR01E;                          /**< ldblreg01e, offset: 0x38 */
  __IO uint32_t LDBLR01F;                          /**< ldblreg01f, offset: 0x3C */
  __IO uint32_t LDBLR020;                          /**< ldblreg020, offset: 0x40 */
  __IO uint32_t LDBLR021;                          /**< ldblreg021, offset: 0x44 */
  __IO uint32_t LDBLR022;                          /**< ldblreg022, offset: 0x48 */
  __IO uint32_t LDBLR023;                          /**< ldblreg023, offset: 0x4C */
  __IO uint32_t LDBLR024;                          /**< ldblreg024, offset: 0x50 */
} locald20_Type;

/* ----------------------------------------------------------------------------
   -- locald20 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald20_Register_Masks locald20 Register Masks
 * @{
 */

/*! @name LDBLR010 - ldblreg010 */
/*! @{ */

#define locald20_LDBLR010_blelut01_MASK          (0xFFFU)
#define locald20_LDBLR010_blelut01_SHIFT         (0U)
/*! blelut01 - bleolut_1 */
#define locald20_LDBLR010_blelut01(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR010_blelut01_SHIFT)) & locald20_LDBLR010_blelut01_MASK)

#define locald20_LDBLR010_blelut00_MASK          (0xFFF0000U)
#define locald20_LDBLR010_blelut00_SHIFT         (16U)
/*! blelut00 - bleolut_0 */
#define locald20_LDBLR010_blelut00(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR010_blelut00_SHIFT)) & locald20_LDBLR010_blelut00_MASK)
/*! @} */

/*! @name LDBLR011 - ldblreg011 */
/*! @{ */

#define locald20_LDBLR011_blelut3_MASK           (0xFFFU)
#define locald20_LDBLR011_blelut3_SHIFT          (0U)
/*! blelut3 - bleolut_3 */
#define locald20_LDBLR011_blelut3(x)             (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR011_blelut3_SHIFT)) & locald20_LDBLR011_blelut3_MASK)

#define locald20_LDBLR011_blelut02_MASK          (0xFFF0000U)
#define locald20_LDBLR011_blelut02_SHIFT         (16U)
/*! blelut02 - bleolut_2 */
#define locald20_LDBLR011_blelut02(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR011_blelut02_SHIFT)) & locald20_LDBLR011_blelut02_MASK)
/*! @} */

/*! @name LDBLR012 - ldblreg012 */
/*! @{ */

#define locald20_LDBLR012_blelut5_MASK           (0xFFFU)
#define locald20_LDBLR012_blelut5_SHIFT          (0U)
/*! blelut5 - bleolut_5 */
#define locald20_LDBLR012_blelut5(x)             (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR012_blelut5_SHIFT)) & locald20_LDBLR012_blelut5_MASK)

#define locald20_LDBLR012_blelut4_MASK           (0xFFF0000U)
#define locald20_LDBLR012_blelut4_SHIFT          (16U)
/*! blelut4 - bleolut_4 */
#define locald20_LDBLR012_blelut4(x)             (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR012_blelut4_SHIFT)) & locald20_LDBLR012_blelut4_MASK)
/*! @} */

/*! @name LDBLR013 - ldblreg013 */
/*! @{ */

#define locald20_LDBLR013_blelut7_MASK           (0xFFFU)
#define locald20_LDBLR013_blelut7_SHIFT          (0U)
/*! blelut7 - bleolut_7 */
#define locald20_LDBLR013_blelut7(x)             (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR013_blelut7_SHIFT)) & locald20_LDBLR013_blelut7_MASK)

#define locald20_LDBLR013_blelut6_MASK           (0xFFF0000U)
#define locald20_LDBLR013_blelut6_SHIFT          (16U)
/*! blelut6 - bleolut_6 */
#define locald20_LDBLR013_blelut6(x)             (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR013_blelut6_SHIFT)) & locald20_LDBLR013_blelut6_MASK)
/*! @} */

/*! @name LDBLR014 - ldblreg014 */
/*! @{ */

#define locald20_LDBLR014_blelut9_MASK           (0xFFFU)
#define locald20_LDBLR014_blelut9_SHIFT          (0U)
/*! blelut9 - bleolut_9 */
#define locald20_LDBLR014_blelut9(x)             (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR014_blelut9_SHIFT)) & locald20_LDBLR014_blelut9_MASK)

#define locald20_LDBLR014_blelut8_MASK           (0xFFF0000U)
#define locald20_LDBLR014_blelut8_SHIFT          (16U)
/*! blelut8 - bleolut_8 */
#define locald20_LDBLR014_blelut8(x)             (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR014_blelut8_SHIFT)) & locald20_LDBLR014_blelut8_MASK)
/*! @} */

/*! @name LDBLR015 - ldblreg015 */
/*! @{ */

#define locald20_LDBLR015_blelut11_MASK          (0xFFFU)
#define locald20_LDBLR015_blelut11_SHIFT         (0U)
/*! blelut11 - bleolut_11 */
#define locald20_LDBLR015_blelut11(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR015_blelut11_SHIFT)) & locald20_LDBLR015_blelut11_MASK)

#define locald20_LDBLR015_blelut10_MASK          (0xFFF0000U)
#define locald20_LDBLR015_blelut10_SHIFT         (16U)
/*! blelut10 - bleolut_10 */
#define locald20_LDBLR015_blelut10(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR015_blelut10_SHIFT)) & locald20_LDBLR015_blelut10_MASK)
/*! @} */

/*! @name LDBLR016 - ldblreg016 */
/*! @{ */

#define locald20_LDBLR016_blelut13_MASK          (0xFFFU)
#define locald20_LDBLR016_blelut13_SHIFT         (0U)
/*! blelut13 - bleolut_13 */
#define locald20_LDBLR016_blelut13(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR016_blelut13_SHIFT)) & locald20_LDBLR016_blelut13_MASK)

#define locald20_LDBLR016_blelut12_MASK          (0xFFF0000U)
#define locald20_LDBLR016_blelut12_SHIFT         (16U)
/*! blelut12 - bleolut_12 */
#define locald20_LDBLR016_blelut12(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR016_blelut12_SHIFT)) & locald20_LDBLR016_blelut12_MASK)
/*! @} */

/*! @name LDBLR017 - ldblreg017 */
/*! @{ */

#define locald20_LDBLR017_blelut15_MASK          (0xFFFU)
#define locald20_LDBLR017_blelut15_SHIFT         (0U)
/*! blelut15 - bleolut_15 */
#define locald20_LDBLR017_blelut15(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR017_blelut15_SHIFT)) & locald20_LDBLR017_blelut15_MASK)

#define locald20_LDBLR017_blelut14_MASK          (0xFFF0000U)
#define locald20_LDBLR017_blelut14_SHIFT         (16U)
/*! blelut14 - bleolut_14 */
#define locald20_LDBLR017_blelut14(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR017_blelut14_SHIFT)) & locald20_LDBLR017_blelut14_MASK)
/*! @} */

/*! @name LDBLR018 - ldblreg018 */
/*! @{ */

#define locald20_LDBLR018_blelut17_MASK          (0xFFFU)
#define locald20_LDBLR018_blelut17_SHIFT         (0U)
/*! blelut17 - bleolut_17 */
#define locald20_LDBLR018_blelut17(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR018_blelut17_SHIFT)) & locald20_LDBLR018_blelut17_MASK)

#define locald20_LDBLR018_blelut16_MASK          (0xFFF0000U)
#define locald20_LDBLR018_blelut16_SHIFT         (16U)
/*! blelut16 - bleolut_16 */
#define locald20_LDBLR018_blelut16(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR018_blelut16_SHIFT)) & locald20_LDBLR018_blelut16_MASK)
/*! @} */

/*! @name LDBLR019 - ldblreg019 */
/*! @{ */

#define locald20_LDBLR019_blelut19_MASK          (0xFFFU)
#define locald20_LDBLR019_blelut19_SHIFT         (0U)
/*! blelut19 - bleolut_19 */
#define locald20_LDBLR019_blelut19(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR019_blelut19_SHIFT)) & locald20_LDBLR019_blelut19_MASK)

#define locald20_LDBLR019_blelut18_MASK          (0xFFF0000U)
#define locald20_LDBLR019_blelut18_SHIFT         (16U)
/*! blelut18 - bleolut_18 */
#define locald20_LDBLR019_blelut18(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR019_blelut18_SHIFT)) & locald20_LDBLR019_blelut18_MASK)
/*! @} */

/*! @name LDBLR01A - ldblreg01a */
/*! @{ */

#define locald20_LDBLR01A_blelut21_MASK          (0xFFFU)
#define locald20_LDBLR01A_blelut21_SHIFT         (0U)
/*! blelut21 - bleolut_21 */
#define locald20_LDBLR01A_blelut21(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR01A_blelut21_SHIFT)) & locald20_LDBLR01A_blelut21_MASK)

#define locald20_LDBLR01A_blelut20_MASK          (0xFFF0000U)
#define locald20_LDBLR01A_blelut20_SHIFT         (16U)
/*! blelut20 - bleolut_20 */
#define locald20_LDBLR01A_blelut20(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR01A_blelut20_SHIFT)) & locald20_LDBLR01A_blelut20_MASK)
/*! @} */

/*! @name LDBLR01B - ldblreg01b */
/*! @{ */

#define locald20_LDBLR01B_blelut23_MASK          (0xFFFU)
#define locald20_LDBLR01B_blelut23_SHIFT         (0U)
/*! blelut23 - bleolut_23 */
#define locald20_LDBLR01B_blelut23(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR01B_blelut23_SHIFT)) & locald20_LDBLR01B_blelut23_MASK)

#define locald20_LDBLR01B_blelut22_MASK          (0xFFF0000U)
#define locald20_LDBLR01B_blelut22_SHIFT         (16U)
/*! blelut22 - bleolut_22 */
#define locald20_LDBLR01B_blelut22(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR01B_blelut22_SHIFT)) & locald20_LDBLR01B_blelut22_MASK)
/*! @} */

/*! @name LDBLR01C - ldblreg01c */
/*! @{ */

#define locald20_LDBLR01C_blelut25_MASK          (0xFFFU)
#define locald20_LDBLR01C_blelut25_SHIFT         (0U)
/*! blelut25 - bleolut_25 */
#define locald20_LDBLR01C_blelut25(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR01C_blelut25_SHIFT)) & locald20_LDBLR01C_blelut25_MASK)

#define locald20_LDBLR01C_blelut24_MASK          (0xFFF0000U)
#define locald20_LDBLR01C_blelut24_SHIFT         (16U)
/*! blelut24 - bleolut_24 */
#define locald20_LDBLR01C_blelut24(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR01C_blelut24_SHIFT)) & locald20_LDBLR01C_blelut24_MASK)
/*! @} */

/*! @name LDBLR01D - ldblreg01d */
/*! @{ */

#define locald20_LDBLR01D_blelut27_MASK          (0xFFFU)
#define locald20_LDBLR01D_blelut27_SHIFT         (0U)
/*! blelut27 - bleolut_27 */
#define locald20_LDBLR01D_blelut27(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR01D_blelut27_SHIFT)) & locald20_LDBLR01D_blelut27_MASK)

#define locald20_LDBLR01D_blelut26_MASK          (0xFFF0000U)
#define locald20_LDBLR01D_blelut26_SHIFT         (16U)
/*! blelut26 - bleolut_26 */
#define locald20_LDBLR01D_blelut26(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR01D_blelut26_SHIFT)) & locald20_LDBLR01D_blelut26_MASK)
/*! @} */

/*! @name LDBLR01E - ldblreg01e */
/*! @{ */

#define locald20_LDBLR01E_blelut29_MASK          (0xFFFU)
#define locald20_LDBLR01E_blelut29_SHIFT         (0U)
/*! blelut29 - bleolut_29 */
#define locald20_LDBLR01E_blelut29(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR01E_blelut29_SHIFT)) & locald20_LDBLR01E_blelut29_MASK)

#define locald20_LDBLR01E_blelut28_MASK          (0xFFF0000U)
#define locald20_LDBLR01E_blelut28_SHIFT         (16U)
/*! blelut28 - bleolut_28 */
#define locald20_LDBLR01E_blelut28(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR01E_blelut28_SHIFT)) & locald20_LDBLR01E_blelut28_MASK)
/*! @} */

/*! @name LDBLR01F - ldblreg01f */
/*! @{ */

#define locald20_LDBLR01F_blelut31_MASK          (0xFFFU)
#define locald20_LDBLR01F_blelut31_SHIFT         (0U)
/*! blelut31 - bleolut_31 */
#define locald20_LDBLR01F_blelut31(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR01F_blelut31_SHIFT)) & locald20_LDBLR01F_blelut31_MASK)

#define locald20_LDBLR01F_blelut30_MASK          (0xFFF0000U)
#define locald20_LDBLR01F_blelut30_SHIFT         (16U)
/*! blelut30 - bleolut_30 */
#define locald20_LDBLR01F_blelut30(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR01F_blelut30_SHIFT)) & locald20_LDBLR01F_blelut30_MASK)
/*! @} */

/*! @name LDBLR020 - ldblreg020 */
/*! @{ */

#define locald20_LDBLR020_blelut32_MASK          (0x1FFF0000U)
#define locald20_LDBLR020_blelut32_SHIFT         (16U)
/*! blelut32 - bleolut_32 */
#define locald20_LDBLR020_blelut32(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR020_blelut32_SHIFT)) & locald20_LDBLR020_blelut32_MASK)
/*! @} */

/*! @name LDBLR021 - ldblreg021 */
/*! @{ */

#define locald20_LDBLR021_blcntsl_MASK           (0x1U)
#define locald20_LDBLR021_blcntsl_SHIFT          (0U)
/*! blcntsl - blcntsl */
#define locald20_LDBLR021_blcntsl(x)             (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR021_blcntsl_SHIFT)) & locald20_LDBLR021_blcntsl_MASK)
/*! @} */

/*! @name LDBLR022 - ldblreg022 */
/*! @{ */

#define locald20_LDBLR022_bllv_MASK              (0xFFFU)
#define locald20_LDBLR022_bllv_SHIFT             (0U)
/*! bllv - bllv */
#define locald20_LDBLR022_bllv(x)                (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR022_bllv_SHIFT)) & locald20_LDBLR022_bllv_MASK)
/*! @} */

/*! @name LDBLR023 - ldblreg023 */
/*! @{ */

#define locald20_LDBLR023_ldbldetw_MASK          (0x1U)
#define locald20_LDBLR023_ldbldetw_SHIFT         (0U)
/*! ldbldetw - ldbldetwoff */
#define locald20_LDBLR023_ldbldetw(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR023_ldbldetw_SHIFT)) & locald20_LDBLR023_ldbldetw_MASK)
/*! @} */

/*! @name LDBLR024 - ldblreg024 */
/*! @{ */

#define locald20_LDBLR024_blelt256_MASK          (0x1FFFU)
#define locald20_LDBLR024_blelt256_SHIFT         (0U)
/*! blelt256 - bleolut256 */
#define locald20_LDBLR024_blelt256(x)            (((uint32_t)(((uint32_t)(x)) << locald20_LDBLR024_blelt256_SHIFT)) & locald20_LDBLR024_blelt256_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald20_Register_Masks */


/*!
 * @}
 */ /* end of group locald20_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD20_H_ */

