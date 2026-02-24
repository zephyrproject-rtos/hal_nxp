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
**         CMSIS Peripheral Access Layer for locald16
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
 * @file PERI_locald16.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald16
 *
 * CMSIS Peripheral Access Layer for locald16
 */

#if !defined(PERI_LOCALD16_H_)
#define PERI_LOCALD16_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald16 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald16_Peripheral_Access_Layer locald16 Peripheral Access Layer
 * @{
 */

/** locald16 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDLED068;                          /**< ldledreg068, offset: 0x0 */
  __IO uint32_t LDLED069;                          /**< ldledreg069, offset: 0x4 */
  __IO uint32_t LDLED06A;                          /**< ldledreg06a, offset: 0x8 */
  __IO uint32_t LDLED06B;                          /**< ldledreg06b, offset: 0xC */
  __IO uint32_t LDLED06C;                          /**< ldledreg06c, offset: 0x10 */
  __IO uint32_t LDLED06D;                          /**< ldledreg06d, offset: 0x14 */
  __IO uint32_t LDLED06E;                          /**< ldledreg06e, offset: 0x18 */
  __IO uint32_t LDLED06F;                          /**< ldledreg06f, offset: 0x1C */
  __IO uint32_t LDLED070;                          /**< ldledreg070, offset: 0x20 */
  __IO uint32_t LDLED071;                          /**< ldledreg071, offset: 0x24 */
  __IO uint32_t LDLED072;                          /**< ldledreg072, offset: 0x28 */
  __IO uint32_t LDLED073;                          /**< ldledreg073, offset: 0x2C */
  __IO uint32_t LDLED074;                          /**< ldledreg074, offset: 0x30 */
  __IO uint32_t LDLED075;                          /**< ldledreg075, offset: 0x34 */
  __IO uint32_t LDLED076;                          /**< ldledreg076, offset: 0x38 */
  __IO uint32_t LDLED077;                          /**< ldledreg077, offset: 0x3C */
  __IO uint32_t LDLED078;                          /**< ldledreg078, offset: 0x40 */
} locald16_Type;

/* ----------------------------------------------------------------------------
   -- locald16 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald16_Register_Masks locald16 Register Masks
 * @{
 */

/*! @name LDLED068 - ldledreg068 */
/*! @{ */

#define locald16_LDLED068_vpos1_MASK             (0xFFFU)
#define locald16_LDLED068_vpos1_SHIFT            (0U)
/*! vpos1 - vpos_1 */
#define locald16_LDLED068_vpos1(x)               (((uint32_t)(((uint32_t)(x)) << locald16_LDLED068_vpos1_SHIFT)) & locald16_LDLED068_vpos1_MASK)

#define locald16_LDLED068_vpos0_MASK             (0xFFF0000U)
#define locald16_LDLED068_vpos0_SHIFT            (16U)
/*! vpos0 - vpos_0 */
#define locald16_LDLED068_vpos0(x)               (((uint32_t)(((uint32_t)(x)) << locald16_LDLED068_vpos0_SHIFT)) & locald16_LDLED068_vpos0_MASK)
/*! @} */

/*! @name LDLED069 - ldledreg069 */
/*! @{ */

#define locald16_LDLED069_vpos3_MASK             (0xFFFU)
#define locald16_LDLED069_vpos3_SHIFT            (0U)
/*! vpos3 - vpos_3 */
#define locald16_LDLED069_vpos3(x)               (((uint32_t)(((uint32_t)(x)) << locald16_LDLED069_vpos3_SHIFT)) & locald16_LDLED069_vpos3_MASK)

#define locald16_LDLED069_vpos2_MASK             (0xFFF0000U)
#define locald16_LDLED069_vpos2_SHIFT            (16U)
/*! vpos2 - vpos_2 */
#define locald16_LDLED069_vpos2(x)               (((uint32_t)(((uint32_t)(x)) << locald16_LDLED069_vpos2_SHIFT)) & locald16_LDLED069_vpos2_MASK)
/*! @} */

/*! @name LDLED06A - ldledreg06a */
/*! @{ */

#define locald16_LDLED06A_vpos5_MASK             (0xFFFU)
#define locald16_LDLED06A_vpos5_SHIFT            (0U)
/*! vpos5 - vpos_5 */
#define locald16_LDLED06A_vpos5(x)               (((uint32_t)(((uint32_t)(x)) << locald16_LDLED06A_vpos5_SHIFT)) & locald16_LDLED06A_vpos5_MASK)

#define locald16_LDLED06A_vpos4_MASK             (0xFFF0000U)
#define locald16_LDLED06A_vpos4_SHIFT            (16U)
/*! vpos4 - vpos_4 */
#define locald16_LDLED06A_vpos4(x)               (((uint32_t)(((uint32_t)(x)) << locald16_LDLED06A_vpos4_SHIFT)) & locald16_LDLED06A_vpos4_MASK)
/*! @} */

/*! @name LDLED06B - ldledreg06b */
/*! @{ */

#define locald16_LDLED06B_vpos7_MASK             (0xFFFU)
#define locald16_LDLED06B_vpos7_SHIFT            (0U)
/*! vpos7 - vpos_7 */
#define locald16_LDLED06B_vpos7(x)               (((uint32_t)(((uint32_t)(x)) << locald16_LDLED06B_vpos7_SHIFT)) & locald16_LDLED06B_vpos7_MASK)

#define locald16_LDLED06B_vpos6_MASK             (0xFFF0000U)
#define locald16_LDLED06B_vpos6_SHIFT            (16U)
/*! vpos6 - vpos_6 */
#define locald16_LDLED06B_vpos6(x)               (((uint32_t)(((uint32_t)(x)) << locald16_LDLED06B_vpos6_SHIFT)) & locald16_LDLED06B_vpos6_MASK)
/*! @} */

/*! @name LDLED06C - ldledreg06c */
/*! @{ */

#define locald16_LDLED06C_vpos9_MASK             (0xFFFU)
#define locald16_LDLED06C_vpos9_SHIFT            (0U)
/*! vpos9 - vpos_9 */
#define locald16_LDLED06C_vpos9(x)               (((uint32_t)(((uint32_t)(x)) << locald16_LDLED06C_vpos9_SHIFT)) & locald16_LDLED06C_vpos9_MASK)

#define locald16_LDLED06C_vpos8_MASK             (0xFFF0000U)
#define locald16_LDLED06C_vpos8_SHIFT            (16U)
/*! vpos8 - vpos_8 */
#define locald16_LDLED06C_vpos8(x)               (((uint32_t)(((uint32_t)(x)) << locald16_LDLED06C_vpos8_SHIFT)) & locald16_LDLED06C_vpos8_MASK)
/*! @} */

/*! @name LDLED06D - ldledreg06d */
/*! @{ */

#define locald16_LDLED06D_vpos11_MASK            (0xFFFU)
#define locald16_LDLED06D_vpos11_SHIFT           (0U)
/*! vpos11 - vpos_11 */
#define locald16_LDLED06D_vpos11(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED06D_vpos11_SHIFT)) & locald16_LDLED06D_vpos11_MASK)

#define locald16_LDLED06D_vpos10_MASK            (0xFFF0000U)
#define locald16_LDLED06D_vpos10_SHIFT           (16U)
/*! vpos10 - vpos_10 */
#define locald16_LDLED06D_vpos10(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED06D_vpos10_SHIFT)) & locald16_LDLED06D_vpos10_MASK)
/*! @} */

/*! @name LDLED06E - ldledreg06e */
/*! @{ */

#define locald16_LDLED06E_vpos13_MASK            (0xFFFU)
#define locald16_LDLED06E_vpos13_SHIFT           (0U)
/*! vpos13 - vpos_13 */
#define locald16_LDLED06E_vpos13(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED06E_vpos13_SHIFT)) & locald16_LDLED06E_vpos13_MASK)

#define locald16_LDLED06E_vpos12_MASK            (0xFFF0000U)
#define locald16_LDLED06E_vpos12_SHIFT           (16U)
/*! vpos12 - vpos_12 */
#define locald16_LDLED06E_vpos12(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED06E_vpos12_SHIFT)) & locald16_LDLED06E_vpos12_MASK)
/*! @} */

/*! @name LDLED06F - ldledreg06f */
/*! @{ */

#define locald16_LDLED06F_vpos15_MASK            (0xFFFU)
#define locald16_LDLED06F_vpos15_SHIFT           (0U)
/*! vpos15 - vpos_15 */
#define locald16_LDLED06F_vpos15(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED06F_vpos15_SHIFT)) & locald16_LDLED06F_vpos15_MASK)

#define locald16_LDLED06F_vpos14_MASK            (0xFFF0000U)
#define locald16_LDLED06F_vpos14_SHIFT           (16U)
/*! vpos14 - vpos_14 */
#define locald16_LDLED06F_vpos14(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED06F_vpos14_SHIFT)) & locald16_LDLED06F_vpos14_MASK)
/*! @} */

/*! @name LDLED070 - ldledreg070 */
/*! @{ */

#define locald16_LDLED070_vpos17_MASK            (0xFFFU)
#define locald16_LDLED070_vpos17_SHIFT           (0U)
/*! vpos17 - vpos_17 */
#define locald16_LDLED070_vpos17(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED070_vpos17_SHIFT)) & locald16_LDLED070_vpos17_MASK)

#define locald16_LDLED070_vpos16_MASK            (0xFFF0000U)
#define locald16_LDLED070_vpos16_SHIFT           (16U)
/*! vpos16 - vpos_16 */
#define locald16_LDLED070_vpos16(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED070_vpos16_SHIFT)) & locald16_LDLED070_vpos16_MASK)
/*! @} */

/*! @name LDLED071 - ldledreg071 */
/*! @{ */

#define locald16_LDLED071_vpos19_MASK            (0xFFFU)
#define locald16_LDLED071_vpos19_SHIFT           (0U)
/*! vpos19 - vpos_19 */
#define locald16_LDLED071_vpos19(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED071_vpos19_SHIFT)) & locald16_LDLED071_vpos19_MASK)

#define locald16_LDLED071_vpos18_MASK            (0xFFF0000U)
#define locald16_LDLED071_vpos18_SHIFT           (16U)
/*! vpos18 - vpos_18 */
#define locald16_LDLED071_vpos18(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED071_vpos18_SHIFT)) & locald16_LDLED071_vpos18_MASK)
/*! @} */

/*! @name LDLED072 - ldledreg072 */
/*! @{ */

#define locald16_LDLED072_vpos21_MASK            (0xFFFU)
#define locald16_LDLED072_vpos21_SHIFT           (0U)
/*! vpos21 - vpos_21 */
#define locald16_LDLED072_vpos21(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED072_vpos21_SHIFT)) & locald16_LDLED072_vpos21_MASK)

#define locald16_LDLED072_vpos20_MASK            (0xFFF0000U)
#define locald16_LDLED072_vpos20_SHIFT           (16U)
/*! vpos20 - vpos_20 */
#define locald16_LDLED072_vpos20(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED072_vpos20_SHIFT)) & locald16_LDLED072_vpos20_MASK)
/*! @} */

/*! @name LDLED073 - ldledreg073 */
/*! @{ */

#define locald16_LDLED073_vpos23_MASK            (0xFFFU)
#define locald16_LDLED073_vpos23_SHIFT           (0U)
/*! vpos23 - vpos_23 */
#define locald16_LDLED073_vpos23(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED073_vpos23_SHIFT)) & locald16_LDLED073_vpos23_MASK)

#define locald16_LDLED073_vpos22_MASK            (0xFFF0000U)
#define locald16_LDLED073_vpos22_SHIFT           (16U)
/*! vpos22 - vpos_22 */
#define locald16_LDLED073_vpos22(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED073_vpos22_SHIFT)) & locald16_LDLED073_vpos22_MASK)
/*! @} */

/*! @name LDLED074 - ldledreg074 */
/*! @{ */

#define locald16_LDLED074_vpos25_MASK            (0xFFFU)
#define locald16_LDLED074_vpos25_SHIFT           (0U)
/*! vpos25 - vpos_25 */
#define locald16_LDLED074_vpos25(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED074_vpos25_SHIFT)) & locald16_LDLED074_vpos25_MASK)

#define locald16_LDLED074_vpos24_MASK            (0xFFF0000U)
#define locald16_LDLED074_vpos24_SHIFT           (16U)
/*! vpos24 - vpos_24 */
#define locald16_LDLED074_vpos24(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED074_vpos24_SHIFT)) & locald16_LDLED074_vpos24_MASK)
/*! @} */

/*! @name LDLED075 - ldledreg075 */
/*! @{ */

#define locald16_LDLED075_vpos27_MASK            (0xFFFU)
#define locald16_LDLED075_vpos27_SHIFT           (0U)
/*! vpos27 - vpos_27 */
#define locald16_LDLED075_vpos27(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED075_vpos27_SHIFT)) & locald16_LDLED075_vpos27_MASK)

#define locald16_LDLED075_vpos26_MASK            (0xFFF0000U)
#define locald16_LDLED075_vpos26_SHIFT           (16U)
/*! vpos26 - vpos_26 */
#define locald16_LDLED075_vpos26(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED075_vpos26_SHIFT)) & locald16_LDLED075_vpos26_MASK)
/*! @} */

/*! @name LDLED076 - ldledreg076 */
/*! @{ */

#define locald16_LDLED076_vpos29_MASK            (0xFFFU)
#define locald16_LDLED076_vpos29_SHIFT           (0U)
/*! vpos29 - vpos_29 */
#define locald16_LDLED076_vpos29(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED076_vpos29_SHIFT)) & locald16_LDLED076_vpos29_MASK)

#define locald16_LDLED076_vpos28_MASK            (0xFFF0000U)
#define locald16_LDLED076_vpos28_SHIFT           (16U)
/*! vpos28 - vpos_28 */
#define locald16_LDLED076_vpos28(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED076_vpos28_SHIFT)) & locald16_LDLED076_vpos28_MASK)
/*! @} */

/*! @name LDLED077 - ldledreg077 */
/*! @{ */

#define locald16_LDLED077_vpos31_MASK            (0xFFFU)
#define locald16_LDLED077_vpos31_SHIFT           (0U)
/*! vpos31 - vpos_31 */
#define locald16_LDLED077_vpos31(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED077_vpos31_SHIFT)) & locald16_LDLED077_vpos31_MASK)

#define locald16_LDLED077_vpos30_MASK            (0xFFF0000U)
#define locald16_LDLED077_vpos30_SHIFT           (16U)
/*! vpos30 - vpos_30 */
#define locald16_LDLED077_vpos30(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED077_vpos30_SHIFT)) & locald16_LDLED077_vpos30_MASK)
/*! @} */

/*! @name LDLED078 - ldledreg078 */
/*! @{ */

#define locald16_LDLED078_vpos32_MASK            (0xFFF0000U)
#define locald16_LDLED078_vpos32_SHIFT           (16U)
/*! vpos32 - vpos_32 */
#define locald16_LDLED078_vpos32(x)              (((uint32_t)(((uint32_t)(x)) << locald16_LDLED078_vpos32_SHIFT)) & locald16_LDLED078_vpos32_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald16_Register_Masks */


/*!
 * @}
 */ /* end of group locald16_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD16_H_ */

