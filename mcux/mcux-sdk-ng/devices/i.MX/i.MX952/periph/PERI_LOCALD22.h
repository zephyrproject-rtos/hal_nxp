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
**         CMSIS Peripheral Access Layer for locald22
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
 * @file PERI_locald22.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald22
 *
 * CMSIS Peripheral Access Layer for locald22
 */

#if !defined(PERI_LOCALD22_H_)
#define PERI_LOCALD22_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald22 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald22_Peripheral_Access_Layer locald22 Peripheral Access Layer
 * @{
 */

/** locald22 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDRG020;                           /**< ldrgbreg020, offset: 0x0 */
  __IO uint32_t LDRG021;                           /**< ldrgbreg021, offset: 0x4 */
  __IO uint32_t LDRG022;                           /**< ldrgbreg022, offset: 0x8 */
  __IO uint32_t LDRG023;                           /**< ldrgbreg023, offset: 0xC */
  __IO uint32_t LDRG024;                           /**< ldrgbreg024, offset: 0x10 */
  __IO uint32_t LDRG025;                           /**< ldrgbreg025, offset: 0x14 */
  __IO uint32_t LDRG026;                           /**< ldrgbreg026, offset: 0x18 */
  __IO uint32_t LDRG027;                           /**< ldrgbreg027, offset: 0x1C */
  __IO uint32_t LDRG028;                           /**< ldrgbreg028, offset: 0x20 */
  __IO uint32_t LDRG029;                           /**< ldrgbreg029, offset: 0x24 */
  __IO uint32_t LDRG02A;                           /**< ldrgbreg02a, offset: 0x28 */
  __IO uint32_t LDRG02B;                           /**< ldrgbreg02b, offset: 0x2C */
  __IO uint32_t LDRG02C;                           /**< ldrgbreg02c, offset: 0x30 */
  __IO uint32_t LDRG02D;                           /**< ldrgbreg02d, offset: 0x34 */
  __IO uint32_t LDRG02E;                           /**< ldrgbreg02e, offset: 0x38 */
  __IO uint32_t LDRG02F;                           /**< ldrgbreg02f, offset: 0x3C */
  __IO uint32_t LDRG030;                           /**< ldrgbreg030, offset: 0x40 */
  __IO uint32_t LDRG031;                           /**< ldrgbreg031, offset: 0x44 */
  __IO uint32_t LDRG032;                           /**< ldrgbreg032, offset: 0x48 */
  __IO uint32_t LDRG033;                           /**< ldrgbreg033, offset: 0x4C */
  __IO uint32_t LDRG034;                           /**< ldrgbreg034, offset: 0x50 */
  __IO uint32_t LDRG035;                           /**< ldrgbreg035, offset: 0x54 */
  __IO uint32_t LDRG036;                           /**< ldrgbreg036, offset: 0x58 */
  __IO uint32_t LDRG037;                           /**< ldrgbreg037, offset: 0x5C */
  __IO uint32_t LDRG038;                           /**< ldrgbreg038, offset: 0x60 */
  __IO uint32_t LDRG039;                           /**< ldrgbreg039, offset: 0x64 */
  __IO uint32_t LDRG03A;                           /**< ldrgbreg03a, offset: 0x68 */
  __IO uint32_t LDRG03B;                           /**< ldrgbreg03b, offset: 0x6C */
  __IO uint32_t LDRG03C;                           /**< ldrgbreg03c, offset: 0x70 */
  __IO uint32_t LDRG03D;                           /**< ldrgbreg03d, offset: 0x74 */
  __IO uint32_t LDRG03E;                           /**< ldrgbreg03e, offset: 0x78 */
  __IO uint32_t LDRG03F;                           /**< ldrgbreg03f, offset: 0x7C */
  __IO uint32_t LDRG040;                           /**< ldrgbreg040, offset: 0x80 */
  __IO uint32_t LDRG041;                           /**< ldrgbreg041, offset: 0x84 */
  __IO uint32_t LDRG042;                           /**< ldrgbreg042, offset: 0x88 */
  __IO uint32_t LDRG043;                           /**< ldrgbreg043, offset: 0x8C */
  __IO uint32_t LDRG044;                           /**< ldrgbreg044, offset: 0x90 */
  __IO uint32_t LDRG045;                           /**< ldrgbreg045, offset: 0x94 */
  __IO uint32_t LDRG046;                           /**< ldrgbreg046, offset: 0x98 */
  __IO uint32_t LDRG047;                           /**< ldrgbreg047, offset: 0x9C */
  __IO uint32_t LDRG048;                           /**< ldrgbreg048, offset: 0xA0 */
  __IO uint32_t LDRG049;                           /**< ldrgbreg049, offset: 0xA4 */
  __IO uint32_t LDRG04A;                           /**< ldrgbreg04a, offset: 0xA8 */
  __IO uint32_t LDRG04B;                           /**< ldrgbreg04b, offset: 0xAC */
  __IO uint32_t LDRG04C;                           /**< ldrgbreg04c, offset: 0xB0 */
  __IO uint32_t LDRG04D;                           /**< ldrgbreg04d, offset: 0xB4 */
  __IO uint32_t LDRG04E;                           /**< ldrgbreg04e, offset: 0xB8 */
  __IO uint32_t LDRG04F;                           /**< ldrgbreg04f, offset: 0xBC */
  __IO uint32_t LDRG050;                           /**< ldrgbreg050, offset: 0xC0 */
  __IO uint32_t LDRG051;                           /**< ldrgbreg051, offset: 0xC4 */
  __IO uint32_t LDRG052;                           /**< ldrgbreg052, offset: 0xC8 */
  __IO uint32_t LDRG053;                           /**< ldrgbreg053, offset: 0xCC */
  __IO uint32_t LDRG054;                           /**< ldrgbreg054, offset: 0xD0 */
  __IO uint32_t LDRG055;                           /**< ldrgbreg055, offset: 0xD4 */
  __IO uint32_t LDRG056;                           /**< ldrgbreg056, offset: 0xD8 */
  __IO uint32_t LDRG057;                           /**< ldrgbreg057, offset: 0xDC */
  __IO uint32_t LDRG058;                           /**< ldrgbreg058, offset: 0xE0 */
  __IO uint32_t LDRG059;                           /**< ldrgbreg059, offset: 0xE4 */
  __IO uint32_t LDRG05A;                           /**< ldrgbreg05a, offset: 0xE8 */
  __IO uint32_t LDRG05B;                           /**< ldrgbreg05b, offset: 0xEC */
} locald22_Type;

/* ----------------------------------------------------------------------------
   -- locald22 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald22_Register_Masks locald22 Register Masks
 * @{
 */

/*! @name LDRG020 - ldrgbreg020 */
/*! @{ */

#define locald22_LDRG020_rgbeosel_MASK           (0x1U)
#define locald22_LDRG020_rgbeosel_SHIFT          (0U)
/*! rgbeosel - rgbeosel */
#define locald22_LDRG020_rgbeosel(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG020_rgbeosel_SHIFT)) & locald22_LDRG020_rgbeosel_MASK)

#define locald22_LDRG020_rgbsel_MASK             (0x2U)
#define locald22_LDRG020_rgbsel_SHIFT            (1U)
/*! rgbsel - rgboesel */
#define locald22_LDRG020_rgbsel(x)               (((uint32_t)(((uint32_t)(x)) << locald22_LDRG020_rgbsel_SHIFT)) & locald22_LDRG020_rgbsel_MASK)

#define locald22_LDRG020_rgbsel33_MASK           (0x4U)
#define locald22_LDRG020_rgbsel33_SHIFT          (2U)
/*! rgbsel33 - rgboesel33 */
#define locald22_LDRG020_rgbsel33(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG020_rgbsel33_SHIFT)) & locald22_LDRG020_rgbsel33_MASK)
/*! @} */

/*! @name LDRG021 - ldrgbreg021 */
/*! @{ */

#define locald22_LDRG021_rgbut0_MASK             (0xFFFU)
#define locald22_LDRG021_rgbut0_SHIFT            (0U)
/*! rgbut0 - rgbeolut_0 */
#define locald22_LDRG021_rgbut0(x)               (((uint32_t)(((uint32_t)(x)) << locald22_LDRG021_rgbut0_SHIFT)) & locald22_LDRG021_rgbut0_MASK)
/*! @} */

/*! @name LDRG022 - ldrgbreg022 */
/*! @{ */

#define locald22_LDRG022_rgelut2_MASK            (0xFFFU)
#define locald22_LDRG022_rgelut2_SHIFT           (0U)
/*! rgelut2 - rgbeolut_2 */
#define locald22_LDRG022_rgelut2(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG022_rgelut2_SHIFT)) & locald22_LDRG022_rgelut2_MASK)

#define locald22_LDRG022_rgelut1_MASK            (0xFFF0000U)
#define locald22_LDRG022_rgelut1_SHIFT           (16U)
/*! rgelut1 - rgbeolut_1 */
#define locald22_LDRG022_rgelut1(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG022_rgelut1_SHIFT)) & locald22_LDRG022_rgelut1_MASK)
/*! @} */

/*! @name LDRG023 - ldrgbreg023 */
/*! @{ */

#define locald22_LDRG023_rgbelut4_MASK           (0xFFFU)
#define locald22_LDRG023_rgbelut4_SHIFT          (0U)
/*! rgbelut4 - rgbeolut_4 */
#define locald22_LDRG023_rgbelut4(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG023_rgbelut4_SHIFT)) & locald22_LDRG023_rgbelut4_MASK)

#define locald22_LDRG023_rgeblut3_MASK           (0xFFF0000U)
#define locald22_LDRG023_rgeblut3_SHIFT          (16U)
/*! rgeblut3 - rgbeolut_3 */
#define locald22_LDRG023_rgeblut3(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG023_rgeblut3_SHIFT)) & locald22_LDRG023_rgeblut3_MASK)
/*! @} */

/*! @name LDRG024 - ldrgbreg024 */
/*! @{ */

#define locald22_LDRG024_rgbelut6_MASK           (0xFFFU)
#define locald22_LDRG024_rgbelut6_SHIFT          (0U)
/*! rgbelut6 - rgbeolut_6 */
#define locald22_LDRG024_rgbelut6(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG024_rgbelut6_SHIFT)) & locald22_LDRG024_rgbelut6_MASK)

#define locald22_LDRG024_rgbelut5_MASK           (0xFFF0000U)
#define locald22_LDRG024_rgbelut5_SHIFT          (16U)
/*! rgbelut5 - rgbeolut_5 */
#define locald22_LDRG024_rgbelut5(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG024_rgbelut5_SHIFT)) & locald22_LDRG024_rgbelut5_MASK)
/*! @} */

/*! @name LDRG025 - ldrgbreg025 */
/*! @{ */

#define locald22_LDRG025_rgbelut8_MASK           (0xFFFU)
#define locald22_LDRG025_rgbelut8_SHIFT          (0U)
/*! rgbelut8 - rgbeolut_8 */
#define locald22_LDRG025_rgbelut8(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG025_rgbelut8_SHIFT)) & locald22_LDRG025_rgbelut8_MASK)

#define locald22_LDRG025_rgbelut7_MASK           (0xFFF0000U)
#define locald22_LDRG025_rgbelut7_SHIFT          (16U)
/*! rgbelut7 - rgbeolut_7 */
#define locald22_LDRG025_rgbelut7(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG025_rgbelut7_SHIFT)) & locald22_LDRG025_rgbelut7_MASK)
/*! @} */

/*! @name LDRG026 - ldrgbreg026 */
/*! @{ */

#define locald22_LDRG026_rgelut10_MASK           (0xFFFU)
#define locald22_LDRG026_rgelut10_SHIFT          (0U)
/*! rgelut10 - rgbeolut_10 */
#define locald22_LDRG026_rgelut10(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG026_rgelut10_SHIFT)) & locald22_LDRG026_rgelut10_MASK)

#define locald22_LDRG026_rgbelut9_MASK           (0xFFF0000U)
#define locald22_LDRG026_rgbelut9_SHIFT          (16U)
/*! rgbelut9 - rgbeolut_9 */
#define locald22_LDRG026_rgbelut9(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG026_rgbelut9_SHIFT)) & locald22_LDRG026_rgbelut9_MASK)
/*! @} */

/*! @name LDRG027 - ldrgbreg027 */
/*! @{ */

#define locald22_LDRG027_rgelut12_MASK           (0xFFFU)
#define locald22_LDRG027_rgelut12_SHIFT          (0U)
/*! rgelut12 - rgbeolut_12 */
#define locald22_LDRG027_rgelut12(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG027_rgelut12_SHIFT)) & locald22_LDRG027_rgelut12_MASK)

#define locald22_LDRG027_rgelut11_MASK           (0xFFF0000U)
#define locald22_LDRG027_rgelut11_SHIFT          (16U)
/*! rgelut11 - rgbeolut_11 */
#define locald22_LDRG027_rgelut11(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG027_rgelut11_SHIFT)) & locald22_LDRG027_rgelut11_MASK)
/*! @} */

/*! @name LDRG028 - ldrgbreg028 */
/*! @{ */

#define locald22_LDRG028_rgelut14_MASK           (0xFFFU)
#define locald22_LDRG028_rgelut14_SHIFT          (0U)
/*! rgelut14 - rgbeolut_14 */
#define locald22_LDRG028_rgelut14(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG028_rgelut14_SHIFT)) & locald22_LDRG028_rgelut14_MASK)

#define locald22_LDRG028_rgelut13_MASK           (0xFFF0000U)
#define locald22_LDRG028_rgelut13_SHIFT          (16U)
/*! rgelut13 - rgbeolut_13 */
#define locald22_LDRG028_rgelut13(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG028_rgelut13_SHIFT)) & locald22_LDRG028_rgelut13_MASK)
/*! @} */

/*! @name LDRG029 - ldrgbreg029 */
/*! @{ */

#define locald22_LDRG029_rgelut16_MASK           (0xFFFU)
#define locald22_LDRG029_rgelut16_SHIFT          (0U)
/*! rgelut16 - rgbeolut_16 */
#define locald22_LDRG029_rgelut16(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG029_rgelut16_SHIFT)) & locald22_LDRG029_rgelut16_MASK)

#define locald22_LDRG029_rgelut15_MASK           (0xFFF0000U)
#define locald22_LDRG029_rgelut15_SHIFT          (16U)
/*! rgelut15 - rgbeolut_15 */
#define locald22_LDRG029_rgelut15(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG029_rgelut15_SHIFT)) & locald22_LDRG029_rgelut15_MASK)
/*! @} */

/*! @name LDRG02A - ldrgbreg02a */
/*! @{ */

#define locald22_LDRG02A_rgelut18_MASK           (0xFFFU)
#define locald22_LDRG02A_rgelut18_SHIFT          (0U)
/*! rgelut18 - rgbeolut_18 */
#define locald22_LDRG02A_rgelut18(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG02A_rgelut18_SHIFT)) & locald22_LDRG02A_rgelut18_MASK)

#define locald22_LDRG02A_rgelut17_MASK           (0xFFF0000U)
#define locald22_LDRG02A_rgelut17_SHIFT          (16U)
/*! rgelut17 - rgbeolut_17 */
#define locald22_LDRG02A_rgelut17(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG02A_rgelut17_SHIFT)) & locald22_LDRG02A_rgelut17_MASK)
/*! @} */

/*! @name LDRG02B - ldrgbreg02b */
/*! @{ */

#define locald22_LDRG02B_rgelut20_MASK           (0xFFFU)
#define locald22_LDRG02B_rgelut20_SHIFT          (0U)
/*! rgelut20 - rgbeolut_20 */
#define locald22_LDRG02B_rgelut20(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG02B_rgelut20_SHIFT)) & locald22_LDRG02B_rgelut20_MASK)

#define locald22_LDRG02B_rgelut19_MASK           (0xFFF0000U)
#define locald22_LDRG02B_rgelut19_SHIFT          (16U)
/*! rgelut19 - rgbeolut_19 */
#define locald22_LDRG02B_rgelut19(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG02B_rgelut19_SHIFT)) & locald22_LDRG02B_rgelut19_MASK)
/*! @} */

/*! @name LDRG02C - ldrgbreg02c */
/*! @{ */

#define locald22_LDRG02C_rgelut22_MASK           (0xFFFU)
#define locald22_LDRG02C_rgelut22_SHIFT          (0U)
/*! rgelut22 - rgbeolut_22 */
#define locald22_LDRG02C_rgelut22(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG02C_rgelut22_SHIFT)) & locald22_LDRG02C_rgelut22_MASK)

#define locald22_LDRG02C_rgelut21_MASK           (0xFFF0000U)
#define locald22_LDRG02C_rgelut21_SHIFT          (16U)
/*! rgelut21 - rgbeolut_21 */
#define locald22_LDRG02C_rgelut21(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG02C_rgelut21_SHIFT)) & locald22_LDRG02C_rgelut21_MASK)
/*! @} */

/*! @name LDRG02D - ldrgbreg02d */
/*! @{ */

#define locald22_LDRG02D_rgelut24_MASK           (0xFFFU)
#define locald22_LDRG02D_rgelut24_SHIFT          (0U)
/*! rgelut24 - rgbeolut_24 */
#define locald22_LDRG02D_rgelut24(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG02D_rgelut24_SHIFT)) & locald22_LDRG02D_rgelut24_MASK)

#define locald22_LDRG02D_rgelut23_MASK           (0xFFF0000U)
#define locald22_LDRG02D_rgelut23_SHIFT          (16U)
/*! rgelut23 - rgbeolut_23 */
#define locald22_LDRG02D_rgelut23(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG02D_rgelut23_SHIFT)) & locald22_LDRG02D_rgelut23_MASK)
/*! @} */

/*! @name LDRG02E - ldrgbreg02e */
/*! @{ */

#define locald22_LDRG02E_rgelut26_MASK           (0xFFFU)
#define locald22_LDRG02E_rgelut26_SHIFT          (0U)
/*! rgelut26 - rgbeolut_26 */
#define locald22_LDRG02E_rgelut26(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG02E_rgelut26_SHIFT)) & locald22_LDRG02E_rgelut26_MASK)

#define locald22_LDRG02E_rgelut25_MASK           (0xFFF0000U)
#define locald22_LDRG02E_rgelut25_SHIFT          (16U)
/*! rgelut25 - rgbeolut_25 */
#define locald22_LDRG02E_rgelut25(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG02E_rgelut25_SHIFT)) & locald22_LDRG02E_rgelut25_MASK)
/*! @} */

/*! @name LDRG02F - ldrgbreg02f */
/*! @{ */

#define locald22_LDRG02F_rgelut28_MASK           (0xFFFU)
#define locald22_LDRG02F_rgelut28_SHIFT          (0U)
/*! rgelut28 - rgbeolut_28 */
#define locald22_LDRG02F_rgelut28(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG02F_rgelut28_SHIFT)) & locald22_LDRG02F_rgelut28_MASK)

#define locald22_LDRG02F_rgelut27_MASK           (0xFFF0000U)
#define locald22_LDRG02F_rgelut27_SHIFT          (16U)
/*! rgelut27 - rgbeolut_27 */
#define locald22_LDRG02F_rgelut27(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG02F_rgelut27_SHIFT)) & locald22_LDRG02F_rgelut27_MASK)
/*! @} */

/*! @name LDRG030 - ldrgbreg030 */
/*! @{ */

#define locald22_LDRG030_rgelut30_MASK           (0xFFFU)
#define locald22_LDRG030_rgelut30_SHIFT          (0U)
/*! rgelut30 - rgbeolut_30 */
#define locald22_LDRG030_rgelut30(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG030_rgelut30_SHIFT)) & locald22_LDRG030_rgelut30_MASK)

#define locald22_LDRG030_rgelut29_MASK           (0xFFF0000U)
#define locald22_LDRG030_rgelut29_SHIFT          (16U)
/*! rgelut29 - rgbeolut_29 */
#define locald22_LDRG030_rgelut29(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG030_rgelut29_SHIFT)) & locald22_LDRG030_rgelut29_MASK)
/*! @} */

/*! @name LDRG031 - ldrgbreg031 */
/*! @{ */

#define locald22_LDRG031_rgelut32_MASK           (0x1FFFU)
#define locald22_LDRG031_rgelut32_SHIFT          (0U)
/*! rgelut32 - rgbeolut_32 */
#define locald22_LDRG031_rgelut32(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG031_rgelut32_SHIFT)) & locald22_LDRG031_rgelut32_MASK)

#define locald22_LDRG031_rgelut31_MASK           (0xFFF0000U)
#define locald22_LDRG031_rgelut31_SHIFT          (16U)
/*! rgelut31 - rgbeolut_31 */
#define locald22_LDRG031_rgelut31(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG031_rgelut31_SHIFT)) & locald22_LDRG031_rgelut31_MASK)
/*! @} */

/*! @name LDRG032 - ldrgbreg032 */
/*! @{ */

#define locald22_LDRG032_rgbl0_MASK              (0xFFFU)
#define locald22_LDRG032_rgbl0_SHIFT             (0U)
/*! rgbl0 - rgboelut_0 */
#define locald22_LDRG032_rgbl0(x)                (((uint32_t)(((uint32_t)(x)) << locald22_LDRG032_rgbl0_SHIFT)) & locald22_LDRG032_rgbl0_MASK)
/*! @} */

/*! @name LDRG033 - ldrgbreg033 */
/*! @{ */

#define locald22_LDRG033_rgbl2_MASK              (0xFFFU)
#define locald22_LDRG033_rgbl2_SHIFT             (0U)
/*! rgbl2 - rgboelut_2 */
#define locald22_LDRG033_rgbl2(x)                (((uint32_t)(((uint32_t)(x)) << locald22_LDRG033_rgbl2_SHIFT)) & locald22_LDRG033_rgbl2_MASK)

#define locald22_LDRG033_rgbl1_MASK              (0xFFF0000U)
#define locald22_LDRG033_rgbl1_SHIFT             (16U)
/*! rgbl1 - rgboelut_1 */
#define locald22_LDRG033_rgbl1(x)                (((uint32_t)(((uint32_t)(x)) << locald22_LDRG033_rgbl1_SHIFT)) & locald22_LDRG033_rgbl1_MASK)
/*! @} */

/*! @name LDRG034 - ldrgbreg034 */
/*! @{ */

#define locald22_LDRG034_rgbl4_MASK              (0xFFFU)
#define locald22_LDRG034_rgbl4_SHIFT             (0U)
/*! rgbl4 - rgboelut_4 */
#define locald22_LDRG034_rgbl4(x)                (((uint32_t)(((uint32_t)(x)) << locald22_LDRG034_rgbl4_SHIFT)) & locald22_LDRG034_rgbl4_MASK)

#define locald22_LDRG034_rgbl3_MASK              (0xFFF0000U)
#define locald22_LDRG034_rgbl3_SHIFT             (16U)
/*! rgbl3 - rgboelut_3 */
#define locald22_LDRG034_rgbl3(x)                (((uint32_t)(((uint32_t)(x)) << locald22_LDRG034_rgbl3_SHIFT)) & locald22_LDRG034_rgbl3_MASK)
/*! @} */

/*! @name LDRG035 - ldrgbreg035 */
/*! @{ */

#define locald22_LDRG035_rgbl6_MASK              (0xFFFU)
#define locald22_LDRG035_rgbl6_SHIFT             (0U)
/*! rgbl6 - rgboelut_6 */
#define locald22_LDRG035_rgbl6(x)                (((uint32_t)(((uint32_t)(x)) << locald22_LDRG035_rgbl6_SHIFT)) & locald22_LDRG035_rgbl6_MASK)

#define locald22_LDRG035_rgbl5_MASK              (0xFFF0000U)
#define locald22_LDRG035_rgbl5_SHIFT             (16U)
/*! rgbl5 - rgboelut_5 */
#define locald22_LDRG035_rgbl5(x)                (((uint32_t)(((uint32_t)(x)) << locald22_LDRG035_rgbl5_SHIFT)) & locald22_LDRG035_rgbl5_MASK)
/*! @} */

/*! @name LDRG036 - ldrgbreg036 */
/*! @{ */

#define locald22_LDRG036_rgbl8_MASK              (0xFFFU)
#define locald22_LDRG036_rgbl8_SHIFT             (0U)
/*! rgbl8 - rgboelut_8 */
#define locald22_LDRG036_rgbl8(x)                (((uint32_t)(((uint32_t)(x)) << locald22_LDRG036_rgbl8_SHIFT)) & locald22_LDRG036_rgbl8_MASK)

#define locald22_LDRG036_rgbl7_MASK              (0xFFF0000U)
#define locald22_LDRG036_rgbl7_SHIFT             (16U)
/*! rgbl7 - rgboelut_7 */
#define locald22_LDRG036_rgbl7(x)                (((uint32_t)(((uint32_t)(x)) << locald22_LDRG036_rgbl7_SHIFT)) & locald22_LDRG036_rgbl7_MASK)
/*! @} */

/*! @name LDRG037 - ldrgbreg037 */
/*! @{ */

#define locald22_LDRG037_rgbl10_MASK             (0xFFFU)
#define locald22_LDRG037_rgbl10_SHIFT            (0U)
/*! rgbl10 - rgboelut_10 */
#define locald22_LDRG037_rgbl10(x)               (((uint32_t)(((uint32_t)(x)) << locald22_LDRG037_rgbl10_SHIFT)) & locald22_LDRG037_rgbl10_MASK)

#define locald22_LDRG037_rgbl9_MASK              (0xFFF0000U)
#define locald22_LDRG037_rgbl9_SHIFT             (16U)
/*! rgbl9 - rgboelut_9 */
#define locald22_LDRG037_rgbl9(x)                (((uint32_t)(((uint32_t)(x)) << locald22_LDRG037_rgbl9_SHIFT)) & locald22_LDRG037_rgbl9_MASK)
/*! @} */

/*! @name LDRG038 - ldrgbreg038 */
/*! @{ */

#define locald22_LDRG038_rgbl12_MASK             (0xFFFU)
#define locald22_LDRG038_rgbl12_SHIFT            (0U)
/*! rgbl12 - rgboelut_12 */
#define locald22_LDRG038_rgbl12(x)               (((uint32_t)(((uint32_t)(x)) << locald22_LDRG038_rgbl12_SHIFT)) & locald22_LDRG038_rgbl12_MASK)

#define locald22_LDRG038_rgbl11_MASK             (0xFFF0000U)
#define locald22_LDRG038_rgbl11_SHIFT            (16U)
/*! rgbl11 - rgboelut_11 */
#define locald22_LDRG038_rgbl11(x)               (((uint32_t)(((uint32_t)(x)) << locald22_LDRG038_rgbl11_SHIFT)) & locald22_LDRG038_rgbl11_MASK)
/*! @} */

/*! @name LDRG039 - ldrgbreg039 */
/*! @{ */

#define locald22_LDRG039_rgbl14_MASK             (0xFFFU)
#define locald22_LDRG039_rgbl14_SHIFT            (0U)
/*! rgbl14 - rgboelut_14 */
#define locald22_LDRG039_rgbl14(x)               (((uint32_t)(((uint32_t)(x)) << locald22_LDRG039_rgbl14_SHIFT)) & locald22_LDRG039_rgbl14_MASK)

#define locald22_LDRG039_rgbl13_MASK             (0xFFF0000U)
#define locald22_LDRG039_rgbl13_SHIFT            (16U)
/*! rgbl13 - rgboelut_13 */
#define locald22_LDRG039_rgbl13(x)               (((uint32_t)(((uint32_t)(x)) << locald22_LDRG039_rgbl13_SHIFT)) & locald22_LDRG039_rgbl13_MASK)
/*! @} */

/*! @name LDRG03A - ldrgbreg03a */
/*! @{ */

#define locald22_LDRG03A_rgbl16_MASK             (0xFFFU)
#define locald22_LDRG03A_rgbl16_SHIFT            (0U)
/*! rgbl16 - rgboelut_16 */
#define locald22_LDRG03A_rgbl16(x)               (((uint32_t)(((uint32_t)(x)) << locald22_LDRG03A_rgbl16_SHIFT)) & locald22_LDRG03A_rgbl16_MASK)

#define locald22_LDRG03A_rgbl15_MASK             (0xFFF0000U)
#define locald22_LDRG03A_rgbl15_SHIFT            (16U)
/*! rgbl15 - rgboelut_15 */
#define locald22_LDRG03A_rgbl15(x)               (((uint32_t)(((uint32_t)(x)) << locald22_LDRG03A_rgbl15_SHIFT)) & locald22_LDRG03A_rgbl15_MASK)
/*! @} */

/*! @name LDRG03B - ldrgbreg03b */
/*! @{ */

#define locald22_LDRG03B_rgbl18_MASK             (0xFFFU)
#define locald22_LDRG03B_rgbl18_SHIFT            (0U)
/*! rgbl18 - rgboelut_18 */
#define locald22_LDRG03B_rgbl18(x)               (((uint32_t)(((uint32_t)(x)) << locald22_LDRG03B_rgbl18_SHIFT)) & locald22_LDRG03B_rgbl18_MASK)

#define locald22_LDRG03B_rgbl17_MASK             (0xFFF0000U)
#define locald22_LDRG03B_rgbl17_SHIFT            (16U)
/*! rgbl17 - rgboelut_17 */
#define locald22_LDRG03B_rgbl17(x)               (((uint32_t)(((uint32_t)(x)) << locald22_LDRG03B_rgbl17_SHIFT)) & locald22_LDRG03B_rgbl17_MASK)
/*! @} */

/*! @name LDRG03C - ldrgbreg03c */
/*! @{ */

#define locald22_LDRG03C_rgbl20_MASK             (0xFFFU)
#define locald22_LDRG03C_rgbl20_SHIFT            (0U)
/*! rgbl20 - rgboelut_20 */
#define locald22_LDRG03C_rgbl20(x)               (((uint32_t)(((uint32_t)(x)) << locald22_LDRG03C_rgbl20_SHIFT)) & locald22_LDRG03C_rgbl20_MASK)

#define locald22_LDRG03C_rgbl19_MASK             (0xFFF0000U)
#define locald22_LDRG03C_rgbl19_SHIFT            (16U)
/*! rgbl19 - rgboelut_19 */
#define locald22_LDRG03C_rgbl19(x)               (((uint32_t)(((uint32_t)(x)) << locald22_LDRG03C_rgbl19_SHIFT)) & locald22_LDRG03C_rgbl19_MASK)
/*! @} */

/*! @name LDRG03D - ldrgbreg03d */
/*! @{ */

#define locald22_LDRG03D_rgbl22_MASK             (0xFFFU)
#define locald22_LDRG03D_rgbl22_SHIFT            (0U)
/*! rgbl22 - rgboelut_22 */
#define locald22_LDRG03D_rgbl22(x)               (((uint32_t)(((uint32_t)(x)) << locald22_LDRG03D_rgbl22_SHIFT)) & locald22_LDRG03D_rgbl22_MASK)

#define locald22_LDRG03D_rgbl21_MASK             (0xFFF0000U)
#define locald22_LDRG03D_rgbl21_SHIFT            (16U)
/*! rgbl21 - rgboelut_21 */
#define locald22_LDRG03D_rgbl21(x)               (((uint32_t)(((uint32_t)(x)) << locald22_LDRG03D_rgbl21_SHIFT)) & locald22_LDRG03D_rgbl21_MASK)
/*! @} */

/*! @name LDRG03E - ldrgbreg03e */
/*! @{ */

#define locald22_LDRG03E_rgbl24_MASK             (0xFFFU)
#define locald22_LDRG03E_rgbl24_SHIFT            (0U)
/*! rgbl24 - rgboelut_24 */
#define locald22_LDRG03E_rgbl24(x)               (((uint32_t)(((uint32_t)(x)) << locald22_LDRG03E_rgbl24_SHIFT)) & locald22_LDRG03E_rgbl24_MASK)

#define locald22_LDRG03E_rgbl23_MASK             (0xFFF0000U)
#define locald22_LDRG03E_rgbl23_SHIFT            (16U)
/*! rgbl23 - rgboelut_23 */
#define locald22_LDRG03E_rgbl23(x)               (((uint32_t)(((uint32_t)(x)) << locald22_LDRG03E_rgbl23_SHIFT)) & locald22_LDRG03E_rgbl23_MASK)
/*! @} */

/*! @name LDRG03F - ldrgbreg03f */
/*! @{ */

#define locald22_LDRG03F_rgbl26_MASK             (0x1FFFU)
#define locald22_LDRG03F_rgbl26_SHIFT            (0U)
/*! rgbl26 - rgboelut_26 */
#define locald22_LDRG03F_rgbl26(x)               (((uint32_t)(((uint32_t)(x)) << locald22_LDRG03F_rgbl26_SHIFT)) & locald22_LDRG03F_rgbl26_MASK)

#define locald22_LDRG03F_rgbl25_MASK             (0xFFF0000U)
#define locald22_LDRG03F_rgbl25_SHIFT            (16U)
/*! rgbl25 - rgboelut_25 */
#define locald22_LDRG03F_rgbl25(x)               (((uint32_t)(((uint32_t)(x)) << locald22_LDRG03F_rgbl25_SHIFT)) & locald22_LDRG03F_rgbl25_MASK)
/*! @} */

/*! @name LDRG040 - ldrgbreg040 */
/*! @{ */

#define locald22_LDRG040_cnvtermo_MASK           (0x8U)
#define locald22_LDRG040_cnvtermo_SHIFT          (3U)
/*! cnvtermo - cnvtermon */
#define locald22_LDRG040_cnvtermo(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG040_cnvtermo_SHIFT)) & locald22_LDRG040_cnvtermo_MASK)

#define locald22_LDRG040_hprof_MASK              (0x30U)
#define locald22_LDRG040_hprof_SHIFT             (4U)
/*! hprof - hprof */
#define locald22_LDRG040_hprof(x)                (((uint32_t)(((uint32_t)(x)) << locald22_LDRG040_hprof_SHIFT)) & locald22_LDRG040_hprof_MASK)

#define locald22_LDRG040_vprof_MASK              (0xC0U)
#define locald22_LDRG040_vprof_SHIFT             (6U)
/*! vprof - vprof */
#define locald22_LDRG040_vprof(x)                (((uint32_t)(((uint32_t)(x)) << locald22_LDRG040_vprof_SHIFT)) & locald22_LDRG040_vprof_MASK)

#define locald22_LDRG040_profon_MASK             (0x100U)
#define locald22_LDRG040_profon_SHIFT            (8U)
/*! profon - profon */
#define locald22_LDRG040_profon(x)               (((uint32_t)(((uint32_t)(x)) << locald22_LDRG040_profon_SHIFT)) & locald22_LDRG040_profon_MASK)
/*! @} */

/*! @name LDRG041 - ldrgbreg041 */
/*! @{ */

#define locald22_LDRG041_rgbgnsel_MASK           (0x1U)
#define locald22_LDRG041_rgbgnsel_SHIFT          (0U)
/*! rgbgnsel - rgbgainsel */
#define locald22_LDRG041_rgbgnsel(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG041_rgbgnsel_SHIFT)) & locald22_LDRG041_rgbgnsel_MASK)
/*! @} */

/*! @name LDRG042 - ldrgbreg042 */
/*! @{ */

#define locald22_LDRG042_rgbgain_MASK            (0x1FFFU)
#define locald22_LDRG042_rgbgain_SHIFT           (0U)
/*! rgbgain - rgbeogain */
#define locald22_LDRG042_rgbgain(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG042_rgbgain_SHIFT)) & locald22_LDRG042_rgbgain_MASK)
/*! @} */

/*! @name LDRG043 - ldrgbreg043 */
/*! @{ */

#define locald22_LDRG043_rgblut1_MASK            (0xFFFU)
#define locald22_LDRG043_rgblut1_SHIFT           (0U)
/*! rgblut1 - rgboolut_1 */
#define locald22_LDRG043_rgblut1(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG043_rgblut1_SHIFT)) & locald22_LDRG043_rgblut1_MASK)

#define locald22_LDRG043_rgblut0_MASK            (0xFFF0000U)
#define locald22_LDRG043_rgblut0_SHIFT           (16U)
/*! rgblut0 - rgboolut_0 */
#define locald22_LDRG043_rgblut0(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG043_rgblut0_SHIFT)) & locald22_LDRG043_rgblut0_MASK)
/*! @} */

/*! @name LDRG044 - ldrgbreg044 */
/*! @{ */

#define locald22_LDRG044_rgblut3_MASK            (0xFFFU)
#define locald22_LDRG044_rgblut3_SHIFT           (0U)
/*! rgblut3 - rgboolut_3 */
#define locald22_LDRG044_rgblut3(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG044_rgblut3_SHIFT)) & locald22_LDRG044_rgblut3_MASK)

#define locald22_LDRG044_rgblut2_MASK            (0xFFF0000U)
#define locald22_LDRG044_rgblut2_SHIFT           (16U)
/*! rgblut2 - rgboolut_2 */
#define locald22_LDRG044_rgblut2(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG044_rgblut2_SHIFT)) & locald22_LDRG044_rgblut2_MASK)
/*! @} */

/*! @name LDRG045 - ldrgbreg045 */
/*! @{ */

#define locald22_LDRG045_rgblut5_MASK            (0xFFFU)
#define locald22_LDRG045_rgblut5_SHIFT           (0U)
/*! rgblut5 - rgboolut_5 */
#define locald22_LDRG045_rgblut5(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG045_rgblut5_SHIFT)) & locald22_LDRG045_rgblut5_MASK)

#define locald22_LDRG045_rgblut4_MASK            (0xFFF0000U)
#define locald22_LDRG045_rgblut4_SHIFT           (16U)
/*! rgblut4 - rgboolut_4 */
#define locald22_LDRG045_rgblut4(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG045_rgblut4_SHIFT)) & locald22_LDRG045_rgblut4_MASK)
/*! @} */

/*! @name LDRG046 - ldrgbreg046 */
/*! @{ */

#define locald22_LDRG046_rgblut7_MASK            (0xFFFU)
#define locald22_LDRG046_rgblut7_SHIFT           (0U)
/*! rgblut7 - rgboolut_7 */
#define locald22_LDRG046_rgblut7(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG046_rgblut7_SHIFT)) & locald22_LDRG046_rgblut7_MASK)

#define locald22_LDRG046_rgblut6_MASK            (0xFFF0000U)
#define locald22_LDRG046_rgblut6_SHIFT           (16U)
/*! rgblut6 - rgboolut_6 */
#define locald22_LDRG046_rgblut6(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG046_rgblut6_SHIFT)) & locald22_LDRG046_rgblut6_MASK)
/*! @} */

/*! @name LDRG047 - ldrgbreg047 */
/*! @{ */

#define locald22_LDRG047_rgblut9_MASK            (0xFFFU)
#define locald22_LDRG047_rgblut9_SHIFT           (0U)
/*! rgblut9 - rgboolut_9 */
#define locald22_LDRG047_rgblut9(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG047_rgblut9_SHIFT)) & locald22_LDRG047_rgblut9_MASK)

#define locald22_LDRG047_rgblut8_MASK            (0xFFF0000U)
#define locald22_LDRG047_rgblut8_SHIFT           (16U)
/*! rgblut8 - rgboolut_8 */
#define locald22_LDRG047_rgblut8(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG047_rgblut8_SHIFT)) & locald22_LDRG047_rgblut8_MASK)
/*! @} */

/*! @name LDRG048 - ldrgbreg048 */
/*! @{ */

#define locald22_LDRG048_rgblut11_MASK           (0xFFFU)
#define locald22_LDRG048_rgblut11_SHIFT          (0U)
/*! rgblut11 - rgboolut_11 */
#define locald22_LDRG048_rgblut11(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG048_rgblut11_SHIFT)) & locald22_LDRG048_rgblut11_MASK)

#define locald22_LDRG048_rgblut10_MASK           (0xFFF0000U)
#define locald22_LDRG048_rgblut10_SHIFT          (16U)
/*! rgblut10 - rgboolut_10 */
#define locald22_LDRG048_rgblut10(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG048_rgblut10_SHIFT)) & locald22_LDRG048_rgblut10_MASK)
/*! @} */

/*! @name LDRG049 - ldrgbreg049 */
/*! @{ */

#define locald22_LDRG049_rgblut13_MASK           (0xFFFU)
#define locald22_LDRG049_rgblut13_SHIFT          (0U)
/*! rgblut13 - rgboolut_13 */
#define locald22_LDRG049_rgblut13(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG049_rgblut13_SHIFT)) & locald22_LDRG049_rgblut13_MASK)

#define locald22_LDRG049_rgblut12_MASK           (0xFFF0000U)
#define locald22_LDRG049_rgblut12_SHIFT          (16U)
/*! rgblut12 - rgboolut_12 */
#define locald22_LDRG049_rgblut12(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG049_rgblut12_SHIFT)) & locald22_LDRG049_rgblut12_MASK)
/*! @} */

/*! @name LDRG04A - ldrgbreg04a */
/*! @{ */

#define locald22_LDRG04A_rgblut15_MASK           (0xFFFU)
#define locald22_LDRG04A_rgblut15_SHIFT          (0U)
/*! rgblut15 - rgboolut_15 */
#define locald22_LDRG04A_rgblut15(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG04A_rgblut15_SHIFT)) & locald22_LDRG04A_rgblut15_MASK)

#define locald22_LDRG04A_rgblut14_MASK           (0xFFF0000U)
#define locald22_LDRG04A_rgblut14_SHIFT          (16U)
/*! rgblut14 - rgboolut_14 */
#define locald22_LDRG04A_rgblut14(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG04A_rgblut14_SHIFT)) & locald22_LDRG04A_rgblut14_MASK)
/*! @} */

/*! @name LDRG04B - ldrgbreg04b */
/*! @{ */

#define locald22_LDRG04B_rgblut17_MASK           (0xFFFU)
#define locald22_LDRG04B_rgblut17_SHIFT          (0U)
/*! rgblut17 - rgboolut_17 */
#define locald22_LDRG04B_rgblut17(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG04B_rgblut17_SHIFT)) & locald22_LDRG04B_rgblut17_MASK)

#define locald22_LDRG04B_rgblut16_MASK           (0xFFF0000U)
#define locald22_LDRG04B_rgblut16_SHIFT          (16U)
/*! rgblut16 - rgboolut_16 */
#define locald22_LDRG04B_rgblut16(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG04B_rgblut16_SHIFT)) & locald22_LDRG04B_rgblut16_MASK)
/*! @} */

/*! @name LDRG04C - ldrgbreg04c */
/*! @{ */

#define locald22_LDRG04C_rgblut19_MASK           (0xFFFU)
#define locald22_LDRG04C_rgblut19_SHIFT          (0U)
/*! rgblut19 - rgboolut_19 */
#define locald22_LDRG04C_rgblut19(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG04C_rgblut19_SHIFT)) & locald22_LDRG04C_rgblut19_MASK)

#define locald22_LDRG04C_rgblut18_MASK           (0xFFF0000U)
#define locald22_LDRG04C_rgblut18_SHIFT          (16U)
/*! rgblut18 - rgboolut_18 */
#define locald22_LDRG04C_rgblut18(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG04C_rgblut18_SHIFT)) & locald22_LDRG04C_rgblut18_MASK)
/*! @} */

/*! @name LDRG04D - ldrgbreg04d */
/*! @{ */

#define locald22_LDRG04D_rgblut21_MASK           (0xFFFU)
#define locald22_LDRG04D_rgblut21_SHIFT          (0U)
/*! rgblut21 - rgboolut_21 */
#define locald22_LDRG04D_rgblut21(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG04D_rgblut21_SHIFT)) & locald22_LDRG04D_rgblut21_MASK)

#define locald22_LDRG04D_rgblut20_MASK           (0xFFF0000U)
#define locald22_LDRG04D_rgblut20_SHIFT          (16U)
/*! rgblut20 - rgboolut_20 */
#define locald22_LDRG04D_rgblut20(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG04D_rgblut20_SHIFT)) & locald22_LDRG04D_rgblut20_MASK)
/*! @} */

/*! @name LDRG04E - ldrgbreg04e */
/*! @{ */

#define locald22_LDRG04E_rgblut23_MASK           (0xFFFU)
#define locald22_LDRG04E_rgblut23_SHIFT          (0U)
/*! rgblut23 - rgboolut_23 */
#define locald22_LDRG04E_rgblut23(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG04E_rgblut23_SHIFT)) & locald22_LDRG04E_rgblut23_MASK)

#define locald22_LDRG04E_rgblut22_MASK           (0xFFF0000U)
#define locald22_LDRG04E_rgblut22_SHIFT          (16U)
/*! rgblut22 - rgboolut_22 */
#define locald22_LDRG04E_rgblut22(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG04E_rgblut22_SHIFT)) & locald22_LDRG04E_rgblut22_MASK)
/*! @} */

/*! @name LDRG04F - ldrgbreg04f */
/*! @{ */

#define locald22_LDRG04F_rgblut25_MASK           (0xFFFU)
#define locald22_LDRG04F_rgblut25_SHIFT          (0U)
/*! rgblut25 - rgboolut_25 */
#define locald22_LDRG04F_rgblut25(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG04F_rgblut25_SHIFT)) & locald22_LDRG04F_rgblut25_MASK)

#define locald22_LDRG04F_rgblut24_MASK           (0xFFF0000U)
#define locald22_LDRG04F_rgblut24_SHIFT          (16U)
/*! rgblut24 - rgboolut_24 */
#define locald22_LDRG04F_rgblut24(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG04F_rgblut24_SHIFT)) & locald22_LDRG04F_rgblut24_MASK)
/*! @} */

/*! @name LDRG050 - ldrgbreg050 */
/*! @{ */

#define locald22_LDRG050_rgblut27_MASK           (0xFFFU)
#define locald22_LDRG050_rgblut27_SHIFT          (0U)
/*! rgblut27 - rgboolut_27 */
#define locald22_LDRG050_rgblut27(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG050_rgblut27_SHIFT)) & locald22_LDRG050_rgblut27_MASK)

#define locald22_LDRG050_rgblut26_MASK           (0xFFF0000U)
#define locald22_LDRG050_rgblut26_SHIFT          (16U)
/*! rgblut26 - rgboolut_26 */
#define locald22_LDRG050_rgblut26(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG050_rgblut26_SHIFT)) & locald22_LDRG050_rgblut26_MASK)
/*! @} */

/*! @name LDRG051 - ldrgbreg051 */
/*! @{ */

#define locald22_LDRG051_rgblut29_MASK           (0xFFFU)
#define locald22_LDRG051_rgblut29_SHIFT          (0U)
/*! rgblut29 - rgboolut_29 */
#define locald22_LDRG051_rgblut29(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG051_rgblut29_SHIFT)) & locald22_LDRG051_rgblut29_MASK)

#define locald22_LDRG051_rgblut28_MASK           (0xFFF0000U)
#define locald22_LDRG051_rgblut28_SHIFT          (16U)
/*! rgblut28 - rgboolut_28 */
#define locald22_LDRG051_rgblut28(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG051_rgblut28_SHIFT)) & locald22_LDRG051_rgblut28_MASK)
/*! @} */

/*! @name LDRG052 - ldrgbreg052 */
/*! @{ */

#define locald22_LDRG052_rgblut31_MASK           (0xFFFU)
#define locald22_LDRG052_rgblut31_SHIFT          (0U)
/*! rgblut31 - rgboolut_31 */
#define locald22_LDRG052_rgblut31(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG052_rgblut31_SHIFT)) & locald22_LDRG052_rgblut31_MASK)

#define locald22_LDRG052_rgblut30_MASK           (0xFFF0000U)
#define locald22_LDRG052_rgblut30_SHIFT          (16U)
/*! rgblut30 - rgboolut_30 */
#define locald22_LDRG052_rgblut30(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG052_rgblut30_SHIFT)) & locald22_LDRG052_rgblut30_MASK)
/*! @} */

/*! @name LDRG053 - ldrgbreg053 */
/*! @{ */

#define locald22_LDRG053_rgblut32_MASK           (0x1FFF0000U)
#define locald22_LDRG053_rgblut32_SHIFT          (16U)
/*! rgblut32 - rgboolut_32 */
#define locald22_LDRG053_rgblut32(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG053_rgblut32_SHIFT)) & locald22_LDRG053_rgblut32_MASK)
/*! @} */

/*! @name LDRG054 - ldrgbreg054 */
/*! @{ */

#define locald22_LDRG054_rgbtfgai_MASK           (0x1FFFU)
#define locald22_LDRG054_rgbtfgai_SHIFT          (0U)
/*! rgbtfgai - rgbootfgain */
#define locald22_LDRG054_rgbtfgai(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG054_rgbtfgai_SHIFT)) & locald22_LDRG054_rgbtfgai_MASK)
/*! @} */

/*! @name LDRG055 - ldrgbreg055 */
/*! @{ */

#define locald22_LDRG055_rgbsaon_MASK            (0x1U)
#define locald22_LDRG055_rgbsaon_SHIFT           (0U)
/*! rgbsaon - rgbsaon */
#define locald22_LDRG055_rgbsaon(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG055_rgbsaon_SHIFT)) & locald22_LDRG055_rgbsaon_MASK)

#define locald22_LDRG055_rgbstfon_MASK           (0x10000U)
#define locald22_LDRG055_rgbstfon_SHIFT          (16U)
/*! rgbstfon - rgbsatfon */
#define locald22_LDRG055_rgbstfon(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG055_rgbstfon_SHIFT)) & locald22_LDRG055_rgbstfon_MASK)

#define locald22_LDRG055_tfth2on_MASK            (0x20000U)
#define locald22_LDRG055_tfth2on_SHIFT           (17U)
/*! tfth2on - tfth2on */
#define locald22_LDRG055_tfth2on(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG055_tfth2on_SHIFT)) & locald22_LDRG055_tfth2on_MASK)

#define locald22_LDRG055_gaintfon_MASK           (0x80000U)
#define locald22_LDRG055_gaintfon_SHIFT          (19U)
/*! gaintfon - gaintfon */
#define locald22_LDRG055_gaintfon(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG055_gaintfon_SHIFT)) & locald22_LDRG055_gaintfon_MASK)

#define locald22_LDRG055_rgbson_MASK             (0x1000000U)
#define locald22_LDRG055_rgbson_SHIFT            (24U)
/*! rgbson - rgbsceneon */
#define locald22_LDRG055_rgbson(x)               (((uint32_t)(((uint32_t)(x)) << locald22_LDRG055_rgbson_SHIFT)) & locald22_LDRG055_rgbson_MASK)

#define locald22_LDRG055_rgbsgon_MASK            (0x2000000U)
#define locald22_LDRG055_rgbsgon_SHIFT           (25U)
/*! rgbsgon - rgbscenegon */
#define locald22_LDRG055_rgbsgon(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG055_rgbsgon_SHIFT)) & locald22_LDRG055_rgbsgon_MASK)

#define locald22_LDRG055_rgbsoff_MASK            (0x4000000U)
#define locald22_LDRG055_rgbsoff_SHIFT           (26U)
/*! rgbsoff - rgbscenemoff */
#define locald22_LDRG055_rgbsoff(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG055_rgbsoff_SHIFT)) & locald22_LDRG055_rgbsoff_MASK)

#define locald22_LDRG055_rgbsmxsl_MASK           (0x70000000U)
#define locald22_LDRG055_rgbsmxsl_SHIFT          (28U)
/*! rgbsmxsl - rgbsamaxsl */
#define locald22_LDRG055_rgbsmxsl(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG055_rgbsmxsl_SHIFT)) & locald22_LDRG055_rgbsmxsl_MASK)
/*! @} */

/*! @name LDRG056 - ldrgbreg056 */
/*! @{ */

#define locald22_LDRG056_rgbstfcf_MASK           (0x3FU)
#define locald22_LDRG056_rgbstfcf_SHIFT          (0U)
/*! rgbstfcf - rgbsatfcoef */
#define locald22_LDRG056_rgbstfcf(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG056_rgbstfcf_SHIFT)) & locald22_LDRG056_rgbstfcf_MASK)

#define locald22_LDRG056_rgbssth_MASK            (0xFF00U)
#define locald22_LDRG056_rgbssth_SHIFT           (8U)
/*! rgbssth - rgbsasth */
#define locald22_LDRG056_rgbssth(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG056_rgbssth_SHIFT)) & locald22_LDRG056_rgbssth_MASK)

#define locald22_LDRG056_rgbspth_MASK            (0xFFF0000U)
#define locald22_LDRG056_rgbspth_SHIFT           (16U)
/*! rgbspth - rgbsapth */
#define locald22_LDRG056_rgbspth(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG056_rgbspth_SHIFT)) & locald22_LDRG056_rgbspth_MASK)
/*! @} */

/*! @name LDRG057 - ldrgbreg057 */
/*! @{ */

#define locald22_LDRG057_rgbsmix_MASK            (0xFFU)
#define locald22_LDRG057_rgbsmix_SHIFT           (0U)
/*! rgbsmix - rgbsamix */
#define locald22_LDRG057_rgbsmix(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG057_rgbsmix_SHIFT)) & locald22_LDRG057_rgbsmix_MASK)

#define locald22_LDRG057_rgbsmxlm_MASK           (0xFFFFFF00U)
#define locald22_LDRG057_rgbsmxlm_SHIFT          (8U)
/*! rgbsmxlm - rgbsamaxlm */
#define locald22_LDRG057_rgbsmxlm(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG057_rgbsmxlm_SHIFT)) & locald22_LDRG057_rgbsmxlm_MASK)
/*! @} */

/*! @name LDRG058 - ldrgbreg058 */
/*! @{ */

#define locald22_LDRG058_rgbsaglm_MASK           (0xFFU)
#define locald22_LDRG058_rgbsaglm_SHIFT          (0U)
/*! rgbsaglm - rgbsaglm */
#define locald22_LDRG058_rgbsaglm(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG058_rgbsaglm_SHIFT)) & locald22_LDRG058_rgbsaglm_MASK)

#define locald22_LDRG058_srgbsc2_MASK            (0x3F00U)
#define locald22_LDRG058_srgbsc2_SHIFT           (8U)
/*! srgbsc2 - srgbsatfcoef2 */
#define locald22_LDRG058_srgbsc2(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG058_srgbsc2_SHIFT)) & locald22_LDRG058_srgbsc2_MASK)

#define locald22_LDRG058_srgbsc1_MASK            (0x3F0000U)
#define locald22_LDRG058_srgbsc1_SHIFT           (16U)
/*! srgbsc1 - srgbsatfcoef1 */
#define locald22_LDRG058_srgbsc1(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG058_srgbsc1_SHIFT)) & locald22_LDRG058_srgbsc1_MASK)

#define locald22_LDRG058_rgbssth2_MASK           (0xFF000000U)
#define locald22_LDRG058_rgbssth2_SHIFT          (24U)
/*! rgbssth2 - rgbsasth2 */
#define locald22_LDRG058_rgbssth2(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG058_rgbssth2_SHIFT)) & locald22_LDRG058_rgbssth2_MASK)
/*! @} */

/*! @name LDRG059 - ldrgbreg059 */
/*! @{ */

#define locald22_LDRG059_rgbabon_MASK            (0x1U)
#define locald22_LDRG059_rgbabon_SHIFT           (0U)
/*! rgbabon - rgbabon */
#define locald22_LDRG059_rgbabon(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG059_rgbabon_SHIFT)) & locald22_LDRG059_rgbabon_MASK)

#define locald22_LDRG059_rgboprsl_MASK           (0x10000U)
#define locald22_LDRG059_rgboprsl_SHIFT          (16U)
/*! rgboprsl - rgboprsl */
#define locald22_LDRG059_rgboprsl(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG059_rgboprsl_SHIFT)) & locald22_LDRG059_rgboprsl_MASK)

#define locald22_LDRG059_rgbdetsl_MASK           (0x300000U)
#define locald22_LDRG059_rgbdetsl_SHIFT          (20U)
/*! rgbdetsl - rgbdetsl */
#define locald22_LDRG059_rgbdetsl(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG059_rgbdetsl_SHIFT)) & locald22_LDRG059_rgbdetsl_MASK)
/*! @} */

/*! @name LDRG05A - ldrgbreg05a */
/*! @{ */

#define locald22_LDRG05A_rgbabal_MASK            (0xFFU)
#define locald22_LDRG05A_rgbabal_SHIFT           (0U)
/*! rgbabal - rgbabal */
#define locald22_LDRG05A_rgbabal(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG05A_rgbabal_SHIFT)) & locald22_LDRG05A_rgbabal_MASK)

#define locald22_LDRG05A_rgbabst_MASK            (0xFF00U)
#define locald22_LDRG05A_rgbabst_SHIFT           (8U)
/*! rgbabst - rgbabst */
#define locald22_LDRG05A_rgbabst(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG05A_rgbabst_SHIFT)) & locald22_LDRG05A_rgbabst_MASK)

#define locald22_LDRG05A_rgbabga_MASK            (0xFF0000U)
#define locald22_LDRG05A_rgbabga_SHIFT           (16U)
/*! rgbabga - rgbabga */
#define locald22_LDRG05A_rgbabga(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG05A_rgbabga_SHIFT)) & locald22_LDRG05A_rgbabga_MASK)

#define locald22_LDRG05A_rgbablm_MASK            (0xFF000000U)
#define locald22_LDRG05A_rgbablm_SHIFT           (24U)
/*! rgbablm - rgbablm */
#define locald22_LDRG05A_rgbablm(x)              (((uint32_t)(((uint32_t)(x)) << locald22_LDRG05A_rgbablm_SHIFT)) & locald22_LDRG05A_rgbablm_MASK)
/*! @} */

/*! @name LDRG05B - ldrgbreg05b */
/*! @{ */

#define locald22_LDRG05B_terpossl_MASK           (0x1U)
#define locald22_LDRG05B_terpossl_SHIFT          (0U)
/*! terpossl - termpossl */
#define locald22_LDRG05B_terpossl(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG05B_terpossl_SHIFT)) & locald22_LDRG05B_terpossl_MASK)

#define locald22_LDRG05B_ldgainsh_MASK           (0x2U)
#define locald22_LDRG05B_ldgainsh_SHIFT          (1U)
/*! ldgainsh - ldgainshift */
#define locald22_LDRG05B_ldgainsh(x)             (((uint32_t)(((uint32_t)(x)) << locald22_LDRG05B_ldgainsh_SHIFT)) & locald22_LDRG05B_ldgainsh_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald22_Register_Masks */


/*!
 * @}
 */ /* end of group locald22_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD22_H_ */

