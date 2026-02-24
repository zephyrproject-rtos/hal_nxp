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
**         CMSIS Peripheral Access Layer for locald15
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
 * @file PERI_locald15.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald15
 *
 * CMSIS Peripheral Access Layer for locald15
 */

#if !defined(PERI_LOCALD15_H_)
#define PERI_LOCALD15_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald15 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald15_Peripheral_Access_Layer locald15 Peripheral Access Layer
 * @{
 */

/** locald15 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDLED040;                          /**< ldledreg040, offset: 0x0 */
  __IO uint32_t LDLED041;                          /**< ldledreg041, offset: 0x4 */
  __IO uint32_t LDLED042;                          /**< ldledreg042, offset: 0x8 */
  __IO uint32_t LDLED043;                          /**< ldledreg043, offset: 0xC */
  __IO uint32_t LDLED044;                          /**< ldledreg044, offset: 0x10 */
  __IO uint32_t LDLED045;                          /**< ldledreg045, offset: 0x14 */
  __IO uint32_t LDLED046;                          /**< ldledreg046, offset: 0x18 */
  __IO uint32_t LDLED047;                          /**< ldledreg047, offset: 0x1C */
  __IO uint32_t LDLED048;                          /**< ldledreg048, offset: 0x20 */
  __IO uint32_t LDLED049;                          /**< ldledreg049, offset: 0x24 */
  __IO uint32_t LDLED04A;                          /**< ldledreg04a, offset: 0x28 */
  __IO uint32_t LDLED04B;                          /**< ldledreg04b, offset: 0x2C */
  __IO uint32_t LDLED04C;                          /**< ldledreg04c, offset: 0x30 */
  __IO uint32_t LDLED04D;                          /**< ldledreg04d, offset: 0x34 */
  __IO uint32_t LDLED04E;                          /**< ldledreg04e, offset: 0x38 */
  __IO uint32_t LDLED04F;                          /**< ldledreg04f, offset: 0x3C */
  __IO uint32_t LDLED050;                          /**< ldledreg050, offset: 0x40 */
  __IO uint32_t LDLED051;                          /**< ldledreg051, offset: 0x44 */
  __IO uint32_t LDLED052;                          /**< ldledreg052, offset: 0x48 */
  __IO uint32_t LDLED053;                          /**< ldledreg053, offset: 0x4C */
  __IO uint32_t LDLED054;                          /**< ldledreg054, offset: 0x50 */
  __IO uint32_t LDLED055;                          /**< ldledreg055, offset: 0x54 */
  __IO uint32_t LDLED056;                          /**< ldledreg056, offset: 0x58 */
  __IO uint32_t LDLED057;                          /**< ldledreg057, offset: 0x5C */
  __IO uint32_t LDLED058;                          /**< ldledreg058, offset: 0x60 */
  __IO uint32_t LDLED059;                          /**< ldledreg059, offset: 0x64 */
  __IO uint32_t LDLED05A;                          /**< ldledreg05a, offset: 0x68 */
  __IO uint32_t LDLED05B;                          /**< ldledreg05b, offset: 0x6C */
  __IO uint32_t LDLED05C;                          /**< ldledreg05c, offset: 0x70 */
  __IO uint32_t LDLED05D;                          /**< ldledreg05d, offset: 0x74 */
  __IO uint32_t LDLED05E;                          /**< ldledreg05e, offset: 0x78 */
  __IO uint32_t LDLED05F;                          /**< ldledreg05f, offset: 0x7C */
  __IO uint32_t LDLED060;                          /**< ldledreg060, offset: 0x80 */
} locald15_Type;

/* ----------------------------------------------------------------------------
   -- locald15 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald15_Register_Masks locald15 Register Masks
 * @{
 */

/*! @name LDLED040 - ldledreg040 */
/*! @{ */

#define locald15_LDLED040_hpos1_MASK             (0x1FFFU)
#define locald15_LDLED040_hpos1_SHIFT            (0U)
/*! hpos1 - hpos_1 */
#define locald15_LDLED040_hpos1(x)               (((uint32_t)(((uint32_t)(x)) << locald15_LDLED040_hpos1_SHIFT)) & locald15_LDLED040_hpos1_MASK)

#define locald15_LDLED040_hpos0_MASK             (0x1FFF0000U)
#define locald15_LDLED040_hpos0_SHIFT            (16U)
/*! hpos0 - hpos_0 */
#define locald15_LDLED040_hpos0(x)               (((uint32_t)(((uint32_t)(x)) << locald15_LDLED040_hpos0_SHIFT)) & locald15_LDLED040_hpos0_MASK)
/*! @} */

/*! @name LDLED041 - ldledreg041 */
/*! @{ */

#define locald15_LDLED041_hpos3_MASK             (0x1FFFU)
#define locald15_LDLED041_hpos3_SHIFT            (0U)
/*! hpos3 - hpos_3 */
#define locald15_LDLED041_hpos3(x)               (((uint32_t)(((uint32_t)(x)) << locald15_LDLED041_hpos3_SHIFT)) & locald15_LDLED041_hpos3_MASK)

#define locald15_LDLED041_hpos2_MASK             (0x1FFF0000U)
#define locald15_LDLED041_hpos2_SHIFT            (16U)
/*! hpos2 - hpos_2 */
#define locald15_LDLED041_hpos2(x)               (((uint32_t)(((uint32_t)(x)) << locald15_LDLED041_hpos2_SHIFT)) & locald15_LDLED041_hpos2_MASK)
/*! @} */

/*! @name LDLED042 - ldledreg042 */
/*! @{ */

#define locald15_LDLED042_hpos5_MASK             (0x1FFFU)
#define locald15_LDLED042_hpos5_SHIFT            (0U)
/*! hpos5 - hpos_5 */
#define locald15_LDLED042_hpos5(x)               (((uint32_t)(((uint32_t)(x)) << locald15_LDLED042_hpos5_SHIFT)) & locald15_LDLED042_hpos5_MASK)

#define locald15_LDLED042_hpos4_MASK             (0x1FFF0000U)
#define locald15_LDLED042_hpos4_SHIFT            (16U)
/*! hpos4 - hpos_4 */
#define locald15_LDLED042_hpos4(x)               (((uint32_t)(((uint32_t)(x)) << locald15_LDLED042_hpos4_SHIFT)) & locald15_LDLED042_hpos4_MASK)
/*! @} */

/*! @name LDLED043 - ldledreg043 */
/*! @{ */

#define locald15_LDLED043_hpos7_MASK             (0x1FFFU)
#define locald15_LDLED043_hpos7_SHIFT            (0U)
/*! hpos7 - hpos_7 */
#define locald15_LDLED043_hpos7(x)               (((uint32_t)(((uint32_t)(x)) << locald15_LDLED043_hpos7_SHIFT)) & locald15_LDLED043_hpos7_MASK)

#define locald15_LDLED043_hpos6_MASK             (0x1FFF0000U)
#define locald15_LDLED043_hpos6_SHIFT            (16U)
/*! hpos6 - hpos_6 */
#define locald15_LDLED043_hpos6(x)               (((uint32_t)(((uint32_t)(x)) << locald15_LDLED043_hpos6_SHIFT)) & locald15_LDLED043_hpos6_MASK)
/*! @} */

/*! @name LDLED044 - ldledreg044 */
/*! @{ */

#define locald15_LDLED044_hpos9_MASK             (0x1FFFU)
#define locald15_LDLED044_hpos9_SHIFT            (0U)
/*! hpos9 - hpos_9 */
#define locald15_LDLED044_hpos9(x)               (((uint32_t)(((uint32_t)(x)) << locald15_LDLED044_hpos9_SHIFT)) & locald15_LDLED044_hpos9_MASK)

#define locald15_LDLED044_hpos8_MASK             (0x1FFF0000U)
#define locald15_LDLED044_hpos8_SHIFT            (16U)
/*! hpos8 - hpos_8 */
#define locald15_LDLED044_hpos8(x)               (((uint32_t)(((uint32_t)(x)) << locald15_LDLED044_hpos8_SHIFT)) & locald15_LDLED044_hpos8_MASK)
/*! @} */

/*! @name LDLED045 - ldledreg045 */
/*! @{ */

#define locald15_LDLED045_hpos11_MASK            (0x1FFFU)
#define locald15_LDLED045_hpos11_SHIFT           (0U)
/*! hpos11 - hpos_11 */
#define locald15_LDLED045_hpos11(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED045_hpos11_SHIFT)) & locald15_LDLED045_hpos11_MASK)

#define locald15_LDLED045_hpos10_MASK            (0x1FFF0000U)
#define locald15_LDLED045_hpos10_SHIFT           (16U)
/*! hpos10 - hpos_10 */
#define locald15_LDLED045_hpos10(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED045_hpos10_SHIFT)) & locald15_LDLED045_hpos10_MASK)
/*! @} */

/*! @name LDLED046 - ldledreg046 */
/*! @{ */

#define locald15_LDLED046_hpos13_MASK            (0x1FFFU)
#define locald15_LDLED046_hpos13_SHIFT           (0U)
/*! hpos13 - hpos_13 */
#define locald15_LDLED046_hpos13(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED046_hpos13_SHIFT)) & locald15_LDLED046_hpos13_MASK)

#define locald15_LDLED046_hpos12_MASK            (0x1FFF0000U)
#define locald15_LDLED046_hpos12_SHIFT           (16U)
/*! hpos12 - hpos_12 */
#define locald15_LDLED046_hpos12(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED046_hpos12_SHIFT)) & locald15_LDLED046_hpos12_MASK)
/*! @} */

/*! @name LDLED047 - ldledreg047 */
/*! @{ */

#define locald15_LDLED047_hpos15_MASK            (0x1FFFU)
#define locald15_LDLED047_hpos15_SHIFT           (0U)
/*! hpos15 - hpos_15 */
#define locald15_LDLED047_hpos15(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED047_hpos15_SHIFT)) & locald15_LDLED047_hpos15_MASK)

#define locald15_LDLED047_hpos14_MASK            (0x1FFF0000U)
#define locald15_LDLED047_hpos14_SHIFT           (16U)
/*! hpos14 - hpos_14 */
#define locald15_LDLED047_hpos14(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED047_hpos14_SHIFT)) & locald15_LDLED047_hpos14_MASK)
/*! @} */

/*! @name LDLED048 - ldledreg048 */
/*! @{ */

#define locald15_LDLED048_hpos17_MASK            (0x1FFFU)
#define locald15_LDLED048_hpos17_SHIFT           (0U)
/*! hpos17 - hpos_17 */
#define locald15_LDLED048_hpos17(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED048_hpos17_SHIFT)) & locald15_LDLED048_hpos17_MASK)

#define locald15_LDLED048_hpos16_MASK            (0x1FFF0000U)
#define locald15_LDLED048_hpos16_SHIFT           (16U)
/*! hpos16 - hpos_16 */
#define locald15_LDLED048_hpos16(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED048_hpos16_SHIFT)) & locald15_LDLED048_hpos16_MASK)
/*! @} */

/*! @name LDLED049 - ldledreg049 */
/*! @{ */

#define locald15_LDLED049_hpos19_MASK            (0x1FFFU)
#define locald15_LDLED049_hpos19_SHIFT           (0U)
/*! hpos19 - hpos_19 */
#define locald15_LDLED049_hpos19(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED049_hpos19_SHIFT)) & locald15_LDLED049_hpos19_MASK)

#define locald15_LDLED049_hpos18_MASK            (0x1FFF0000U)
#define locald15_LDLED049_hpos18_SHIFT           (16U)
/*! hpos18 - hpos_18 */
#define locald15_LDLED049_hpos18(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED049_hpos18_SHIFT)) & locald15_LDLED049_hpos18_MASK)
/*! @} */

/*! @name LDLED04A - ldledreg04a */
/*! @{ */

#define locald15_LDLED04A_hpos21_MASK            (0x1FFFU)
#define locald15_LDLED04A_hpos21_SHIFT           (0U)
/*! hpos21 - hpos_21 */
#define locald15_LDLED04A_hpos21(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED04A_hpos21_SHIFT)) & locald15_LDLED04A_hpos21_MASK)

#define locald15_LDLED04A_hpos20_MASK            (0x1FFF0000U)
#define locald15_LDLED04A_hpos20_SHIFT           (16U)
/*! hpos20 - hpos_20 */
#define locald15_LDLED04A_hpos20(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED04A_hpos20_SHIFT)) & locald15_LDLED04A_hpos20_MASK)
/*! @} */

/*! @name LDLED04B - ldledreg04b */
/*! @{ */

#define locald15_LDLED04B_hpos23_MASK            (0x1FFFU)
#define locald15_LDLED04B_hpos23_SHIFT           (0U)
/*! hpos23 - hpos_23 */
#define locald15_LDLED04B_hpos23(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED04B_hpos23_SHIFT)) & locald15_LDLED04B_hpos23_MASK)

#define locald15_LDLED04B_hpos22_MASK            (0x1FFF0000U)
#define locald15_LDLED04B_hpos22_SHIFT           (16U)
/*! hpos22 - hpos_22 */
#define locald15_LDLED04B_hpos22(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED04B_hpos22_SHIFT)) & locald15_LDLED04B_hpos22_MASK)
/*! @} */

/*! @name LDLED04C - ldledreg04c */
/*! @{ */

#define locald15_LDLED04C_hpos25_MASK            (0x1FFFU)
#define locald15_LDLED04C_hpos25_SHIFT           (0U)
/*! hpos25 - hpos_25 */
#define locald15_LDLED04C_hpos25(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED04C_hpos25_SHIFT)) & locald15_LDLED04C_hpos25_MASK)

#define locald15_LDLED04C_hpos24_MASK            (0x1FFF0000U)
#define locald15_LDLED04C_hpos24_SHIFT           (16U)
/*! hpos24 - hpos_24 */
#define locald15_LDLED04C_hpos24(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED04C_hpos24_SHIFT)) & locald15_LDLED04C_hpos24_MASK)
/*! @} */

/*! @name LDLED04D - ldledreg04d */
/*! @{ */

#define locald15_LDLED04D_hpos27_MASK            (0x1FFFU)
#define locald15_LDLED04D_hpos27_SHIFT           (0U)
/*! hpos27 - hpos_27 */
#define locald15_LDLED04D_hpos27(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED04D_hpos27_SHIFT)) & locald15_LDLED04D_hpos27_MASK)

#define locald15_LDLED04D_hpos26_MASK            (0x1FFF0000U)
#define locald15_LDLED04D_hpos26_SHIFT           (16U)
/*! hpos26 - hpos_26 */
#define locald15_LDLED04D_hpos26(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED04D_hpos26_SHIFT)) & locald15_LDLED04D_hpos26_MASK)
/*! @} */

/*! @name LDLED04E - ldledreg04e */
/*! @{ */

#define locald15_LDLED04E_hpos29_MASK            (0x1FFFU)
#define locald15_LDLED04E_hpos29_SHIFT           (0U)
/*! hpos29 - hpos_29 */
#define locald15_LDLED04E_hpos29(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED04E_hpos29_SHIFT)) & locald15_LDLED04E_hpos29_MASK)

#define locald15_LDLED04E_hpos28_MASK            (0x1FFF0000U)
#define locald15_LDLED04E_hpos28_SHIFT           (16U)
/*! hpos28 - hpos_28 */
#define locald15_LDLED04E_hpos28(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED04E_hpos28_SHIFT)) & locald15_LDLED04E_hpos28_MASK)
/*! @} */

/*! @name LDLED04F - ldledreg04f */
/*! @{ */

#define locald15_LDLED04F_hpos31_MASK            (0x1FFFU)
#define locald15_LDLED04F_hpos31_SHIFT           (0U)
/*! hpos31 - hpos_31 */
#define locald15_LDLED04F_hpos31(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED04F_hpos31_SHIFT)) & locald15_LDLED04F_hpos31_MASK)

#define locald15_LDLED04F_hpos30_MASK            (0x1FFF0000U)
#define locald15_LDLED04F_hpos30_SHIFT           (16U)
/*! hpos30 - hpos_30 */
#define locald15_LDLED04F_hpos30(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED04F_hpos30_SHIFT)) & locald15_LDLED04F_hpos30_MASK)
/*! @} */

/*! @name LDLED050 - ldledreg050 */
/*! @{ */

#define locald15_LDLED050_hpos33_MASK            (0x1FFFU)
#define locald15_LDLED050_hpos33_SHIFT           (0U)
/*! hpos33 - hpos_33 */
#define locald15_LDLED050_hpos33(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED050_hpos33_SHIFT)) & locald15_LDLED050_hpos33_MASK)

#define locald15_LDLED050_hpos32_MASK            (0x1FFF0000U)
#define locald15_LDLED050_hpos32_SHIFT           (16U)
/*! hpos32 - hpos_32 */
#define locald15_LDLED050_hpos32(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED050_hpos32_SHIFT)) & locald15_LDLED050_hpos32_MASK)
/*! @} */

/*! @name LDLED051 - ldledreg051 */
/*! @{ */

#define locald15_LDLED051_hpos35_MASK            (0x1FFFU)
#define locald15_LDLED051_hpos35_SHIFT           (0U)
/*! hpos35 - hpos_35 */
#define locald15_LDLED051_hpos35(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED051_hpos35_SHIFT)) & locald15_LDLED051_hpos35_MASK)

#define locald15_LDLED051_hpos34_MASK            (0x1FFF0000U)
#define locald15_LDLED051_hpos34_SHIFT           (16U)
/*! hpos34 - hpos_34 */
#define locald15_LDLED051_hpos34(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED051_hpos34_SHIFT)) & locald15_LDLED051_hpos34_MASK)
/*! @} */

/*! @name LDLED052 - ldledreg052 */
/*! @{ */

#define locald15_LDLED052_hpos37_MASK            (0x1FFFU)
#define locald15_LDLED052_hpos37_SHIFT           (0U)
/*! hpos37 - hpos_37 */
#define locald15_LDLED052_hpos37(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED052_hpos37_SHIFT)) & locald15_LDLED052_hpos37_MASK)

#define locald15_LDLED052_hpos36_MASK            (0x1FFF0000U)
#define locald15_LDLED052_hpos36_SHIFT           (16U)
/*! hpos36 - hpos_36 */
#define locald15_LDLED052_hpos36(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED052_hpos36_SHIFT)) & locald15_LDLED052_hpos36_MASK)
/*! @} */

/*! @name LDLED053 - ldledreg053 */
/*! @{ */

#define locald15_LDLED053_hpos39_MASK            (0x1FFFU)
#define locald15_LDLED053_hpos39_SHIFT           (0U)
/*! hpos39 - hpos_39 */
#define locald15_LDLED053_hpos39(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED053_hpos39_SHIFT)) & locald15_LDLED053_hpos39_MASK)

#define locald15_LDLED053_hpos38_MASK            (0x1FFF0000U)
#define locald15_LDLED053_hpos38_SHIFT           (16U)
/*! hpos38 - hpos_38 */
#define locald15_LDLED053_hpos38(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED053_hpos38_SHIFT)) & locald15_LDLED053_hpos38_MASK)
/*! @} */

/*! @name LDLED054 - ldledreg054 */
/*! @{ */

#define locald15_LDLED054_hpos41_MASK            (0x1FFFU)
#define locald15_LDLED054_hpos41_SHIFT           (0U)
/*! hpos41 - hpos_41 */
#define locald15_LDLED054_hpos41(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED054_hpos41_SHIFT)) & locald15_LDLED054_hpos41_MASK)

#define locald15_LDLED054_hpos40_MASK            (0x1FFF0000U)
#define locald15_LDLED054_hpos40_SHIFT           (16U)
/*! hpos40 - hpos_40 */
#define locald15_LDLED054_hpos40(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED054_hpos40_SHIFT)) & locald15_LDLED054_hpos40_MASK)
/*! @} */

/*! @name LDLED055 - ldledreg055 */
/*! @{ */

#define locald15_LDLED055_hpos43_MASK            (0x1FFFU)
#define locald15_LDLED055_hpos43_SHIFT           (0U)
/*! hpos43 - hpos_43 */
#define locald15_LDLED055_hpos43(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED055_hpos43_SHIFT)) & locald15_LDLED055_hpos43_MASK)

#define locald15_LDLED055_hpos42_MASK            (0x1FFF0000U)
#define locald15_LDLED055_hpos42_SHIFT           (16U)
/*! hpos42 - hpos_42 */
#define locald15_LDLED055_hpos42(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED055_hpos42_SHIFT)) & locald15_LDLED055_hpos42_MASK)
/*! @} */

/*! @name LDLED056 - ldledreg056 */
/*! @{ */

#define locald15_LDLED056_hpos45_MASK            (0x1FFFU)
#define locald15_LDLED056_hpos45_SHIFT           (0U)
/*! hpos45 - hpos_45 */
#define locald15_LDLED056_hpos45(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED056_hpos45_SHIFT)) & locald15_LDLED056_hpos45_MASK)

#define locald15_LDLED056_hpos44_MASK            (0x1FFF0000U)
#define locald15_LDLED056_hpos44_SHIFT           (16U)
/*! hpos44 - hpos_44 */
#define locald15_LDLED056_hpos44(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED056_hpos44_SHIFT)) & locald15_LDLED056_hpos44_MASK)
/*! @} */

/*! @name LDLED057 - ldledreg057 */
/*! @{ */

#define locald15_LDLED057_hpos47_MASK            (0x1FFFU)
#define locald15_LDLED057_hpos47_SHIFT           (0U)
/*! hpos47 - hpos_47 */
#define locald15_LDLED057_hpos47(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED057_hpos47_SHIFT)) & locald15_LDLED057_hpos47_MASK)

#define locald15_LDLED057_hpos46_MASK            (0x1FFF0000U)
#define locald15_LDLED057_hpos46_SHIFT           (16U)
/*! hpos46 - hpos_46 */
#define locald15_LDLED057_hpos46(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED057_hpos46_SHIFT)) & locald15_LDLED057_hpos46_MASK)
/*! @} */

/*! @name LDLED058 - ldledreg058 */
/*! @{ */

#define locald15_LDLED058_hpos49_MASK            (0x1FFFU)
#define locald15_LDLED058_hpos49_SHIFT           (0U)
/*! hpos49 - hpos_49 */
#define locald15_LDLED058_hpos49(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED058_hpos49_SHIFT)) & locald15_LDLED058_hpos49_MASK)

#define locald15_LDLED058_hpos48_MASK            (0x1FFF0000U)
#define locald15_LDLED058_hpos48_SHIFT           (16U)
/*! hpos48 - hpos_48 */
#define locald15_LDLED058_hpos48(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED058_hpos48_SHIFT)) & locald15_LDLED058_hpos48_MASK)
/*! @} */

/*! @name LDLED059 - ldledreg059 */
/*! @{ */

#define locald15_LDLED059_hpos51_MASK            (0x1FFFU)
#define locald15_LDLED059_hpos51_SHIFT           (0U)
/*! hpos51 - hpos_51 */
#define locald15_LDLED059_hpos51(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED059_hpos51_SHIFT)) & locald15_LDLED059_hpos51_MASK)

#define locald15_LDLED059_hpos50_MASK            (0x1FFF0000U)
#define locald15_LDLED059_hpos50_SHIFT           (16U)
/*! hpos50 - hpos_50 */
#define locald15_LDLED059_hpos50(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED059_hpos50_SHIFT)) & locald15_LDLED059_hpos50_MASK)
/*! @} */

/*! @name LDLED05A - ldledreg05a */
/*! @{ */

#define locald15_LDLED05A_hpos53_MASK            (0x1FFFU)
#define locald15_LDLED05A_hpos53_SHIFT           (0U)
/*! hpos53 - hpos_53 */
#define locald15_LDLED05A_hpos53(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED05A_hpos53_SHIFT)) & locald15_LDLED05A_hpos53_MASK)

#define locald15_LDLED05A_hpos52_MASK            (0x1FFF0000U)
#define locald15_LDLED05A_hpos52_SHIFT           (16U)
/*! hpos52 - hpos_52 */
#define locald15_LDLED05A_hpos52(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED05A_hpos52_SHIFT)) & locald15_LDLED05A_hpos52_MASK)
/*! @} */

/*! @name LDLED05B - ldledreg05b */
/*! @{ */

#define locald15_LDLED05B_hpos55_MASK            (0x1FFFU)
#define locald15_LDLED05B_hpos55_SHIFT           (0U)
/*! hpos55 - hpos_55 */
#define locald15_LDLED05B_hpos55(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED05B_hpos55_SHIFT)) & locald15_LDLED05B_hpos55_MASK)

#define locald15_LDLED05B_hpos54_MASK            (0x1FFF0000U)
#define locald15_LDLED05B_hpos54_SHIFT           (16U)
/*! hpos54 - hpos_54 */
#define locald15_LDLED05B_hpos54(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED05B_hpos54_SHIFT)) & locald15_LDLED05B_hpos54_MASK)
/*! @} */

/*! @name LDLED05C - ldledreg05c */
/*! @{ */

#define locald15_LDLED05C_hpos57_MASK            (0x1FFFU)
#define locald15_LDLED05C_hpos57_SHIFT           (0U)
/*! hpos57 - hpos_57 */
#define locald15_LDLED05C_hpos57(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED05C_hpos57_SHIFT)) & locald15_LDLED05C_hpos57_MASK)

#define locald15_LDLED05C_hpos56_MASK            (0x1FFF0000U)
#define locald15_LDLED05C_hpos56_SHIFT           (16U)
/*! hpos56 - hpos_56 */
#define locald15_LDLED05C_hpos56(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED05C_hpos56_SHIFT)) & locald15_LDLED05C_hpos56_MASK)
/*! @} */

/*! @name LDLED05D - ldledreg05d */
/*! @{ */

#define locald15_LDLED05D_hpos59_MASK            (0x1FFFU)
#define locald15_LDLED05D_hpos59_SHIFT           (0U)
/*! hpos59 - hpos_59 */
#define locald15_LDLED05D_hpos59(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED05D_hpos59_SHIFT)) & locald15_LDLED05D_hpos59_MASK)

#define locald15_LDLED05D_hpos58_MASK            (0x1FFF0000U)
#define locald15_LDLED05D_hpos58_SHIFT           (16U)
/*! hpos58 - hpos_58 */
#define locald15_LDLED05D_hpos58(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED05D_hpos58_SHIFT)) & locald15_LDLED05D_hpos58_MASK)
/*! @} */

/*! @name LDLED05E - ldledreg05e */
/*! @{ */

#define locald15_LDLED05E_hpos61_MASK            (0x1FFFU)
#define locald15_LDLED05E_hpos61_SHIFT           (0U)
/*! hpos61 - hpos_61 */
#define locald15_LDLED05E_hpos61(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED05E_hpos61_SHIFT)) & locald15_LDLED05E_hpos61_MASK)

#define locald15_LDLED05E_hpos60_MASK            (0x1FFF0000U)
#define locald15_LDLED05E_hpos60_SHIFT           (16U)
/*! hpos60 - hpos_60 */
#define locald15_LDLED05E_hpos60(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED05E_hpos60_SHIFT)) & locald15_LDLED05E_hpos60_MASK)
/*! @} */

/*! @name LDLED05F - ldledreg05f */
/*! @{ */

#define locald15_LDLED05F_hpos63_MASK            (0x1FFFU)
#define locald15_LDLED05F_hpos63_SHIFT           (0U)
/*! hpos63 - hpos_63 */
#define locald15_LDLED05F_hpos63(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED05F_hpos63_SHIFT)) & locald15_LDLED05F_hpos63_MASK)

#define locald15_LDLED05F_hpos62_MASK            (0x1FFF0000U)
#define locald15_LDLED05F_hpos62_SHIFT           (16U)
/*! hpos62 - hpos_62 */
#define locald15_LDLED05F_hpos62(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED05F_hpos62_SHIFT)) & locald15_LDLED05F_hpos62_MASK)
/*! @} */

/*! @name LDLED060 - ldledreg060 */
/*! @{ */

#define locald15_LDLED060_hpos64_MASK            (0x1FFF0000U)
#define locald15_LDLED060_hpos64_SHIFT           (16U)
/*! hpos64 - hpos_64 */
#define locald15_LDLED060_hpos64(x)              (((uint32_t)(((uint32_t)(x)) << locald15_LDLED060_hpos64_SHIFT)) & locald15_LDLED060_hpos64_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald15_Register_Masks */


/*!
 * @}
 */ /* end of group locald15_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD15_H_ */

