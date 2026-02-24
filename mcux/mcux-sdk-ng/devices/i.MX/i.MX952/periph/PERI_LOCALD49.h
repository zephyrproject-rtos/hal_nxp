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
**         CMSIS Peripheral Access Layer for locald49
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
 * @file PERI_locald49.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald49
 *
 * CMSIS Peripheral Access Layer for locald49
 */

#if !defined(PERI_LOCALD49_H_)
#define PERI_LOCALD49_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald49 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald49_Peripheral_Access_Layer locald49 Peripheral Access Layer
 * @{
 */

/** locald49 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR2C0;                          /**< ldprofilereg2c0, offset: 0x0 */
  __IO uint32_t LDPRR2C1;                          /**< ldprofilereg2c1, offset: 0x4 */
  __IO uint32_t LDPRR2C2;                          /**< ldprofilereg2c2, offset: 0x8 */
  __IO uint32_t LDPRR2C3;                          /**< ldprofilereg2c3, offset: 0xC */
  __IO uint32_t LDPRR2C4;                          /**< ldprofilereg2c4, offset: 0x10 */
  __IO uint32_t LDPRR2C5;                          /**< ldprofilereg2c5, offset: 0x14 */
  __IO uint32_t LDPRR2C6;                          /**< ldprofilereg2c6, offset: 0x18 */
  __IO uint32_t LDPRR2C7;                          /**< ldprofilereg2c7, offset: 0x1C */
  __IO uint32_t LDPRR2C8;                          /**< ldprofilereg2c8, offset: 0x20 */
  __IO uint32_t LDPRR2C9;                          /**< ldprofilereg2c9, offset: 0x24 */
  __IO uint32_t LDPRR2CA;                          /**< ldprofilereg2ca, offset: 0x28 */
  __IO uint32_t LDPRR2CB;                          /**< ldprofilereg2cb, offset: 0x2C */
  __IO uint32_t LDPRR2CC;                          /**< ldprofilereg2cc, offset: 0x30 */
  __IO uint32_t LDPRR2CD;                          /**< ldprofilereg2cd, offset: 0x34 */
  __IO uint32_t LDPRR2CE;                          /**< ldprofilereg2ce, offset: 0x38 */
  __IO uint32_t LDPRR2CF;                          /**< ldprofilereg2cf, offset: 0x3C */
  __IO uint32_t LDPRR2D0;                          /**< ldprofilereg2d0, offset: 0x40 */
  __IO uint32_t LDPRR2D1;                          /**< ldprofilereg2d1, offset: 0x44 */
  __IO uint32_t LDPRR2D2;                          /**< ldprofilereg2d2, offset: 0x48 */
  __IO uint32_t LDPRR2D3;                          /**< ldprofilereg2d3, offset: 0x4C */
  __IO uint32_t LDPRR2D4;                          /**< ldprofilereg2d4, offset: 0x50 */
  __IO uint32_t LDPRR2D5;                          /**< ldprofilereg2d5, offset: 0x54 */
  __IO uint32_t LDPRR2D6;                          /**< ldprofilereg2d6, offset: 0x58 */
  __IO uint32_t LDPRR2D7;                          /**< ldprofilereg2d7, offset: 0x5C */
} locald49_Type;

/* ----------------------------------------------------------------------------
   -- locald49 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald49_Register_Masks locald49 Register Masks
 * @{
 */

/*! @name LDPRR2C0 - ldprofilereg2c0 */
/*! @{ */

#define locald49_LDPRR2C0_lumd1057_MASK          (0x3FFU)
#define locald49_LDPRR2C0_lumd1057_SHIFT         (0U)
/*! lumd1057 - lumdat_1057 */
#define locald49_LDPRR2C0_lumd1057(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2C0_lumd1057_SHIFT)) & locald49_LDPRR2C0_lumd1057_MASK)

#define locald49_LDPRR2C0_lumd1056_MASK          (0x3FF0000U)
#define locald49_LDPRR2C0_lumd1056_SHIFT         (16U)
/*! lumd1056 - lumdat_1056 */
#define locald49_LDPRR2C0_lumd1056(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2C0_lumd1056_SHIFT)) & locald49_LDPRR2C0_lumd1056_MASK)
/*! @} */

/*! @name LDPRR2C1 - ldprofilereg2c1 */
/*! @{ */

#define locald49_LDPRR2C1_lumd1059_MASK          (0x3FFU)
#define locald49_LDPRR2C1_lumd1059_SHIFT         (0U)
/*! lumd1059 - lumdat_1059 */
#define locald49_LDPRR2C1_lumd1059(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2C1_lumd1059_SHIFT)) & locald49_LDPRR2C1_lumd1059_MASK)

#define locald49_LDPRR2C1_lumd1058_MASK          (0x3FF0000U)
#define locald49_LDPRR2C1_lumd1058_SHIFT         (16U)
/*! lumd1058 - lumdat_1058 */
#define locald49_LDPRR2C1_lumd1058(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2C1_lumd1058_SHIFT)) & locald49_LDPRR2C1_lumd1058_MASK)
/*! @} */

/*! @name LDPRR2C2 - ldprofilereg2c2 */
/*! @{ */

#define locald49_LDPRR2C2_lumd1061_MASK          (0x3FFU)
#define locald49_LDPRR2C2_lumd1061_SHIFT         (0U)
/*! lumd1061 - lumdat_1061 */
#define locald49_LDPRR2C2_lumd1061(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2C2_lumd1061_SHIFT)) & locald49_LDPRR2C2_lumd1061_MASK)

#define locald49_LDPRR2C2_lumd1060_MASK          (0x3FF0000U)
#define locald49_LDPRR2C2_lumd1060_SHIFT         (16U)
/*! lumd1060 - lumdat_1060 */
#define locald49_LDPRR2C2_lumd1060(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2C2_lumd1060_SHIFT)) & locald49_LDPRR2C2_lumd1060_MASK)
/*! @} */

/*! @name LDPRR2C3 - ldprofilereg2c3 */
/*! @{ */

#define locald49_LDPRR2C3_lumd1063_MASK          (0x3FFU)
#define locald49_LDPRR2C3_lumd1063_SHIFT         (0U)
/*! lumd1063 - lumdat_1063 */
#define locald49_LDPRR2C3_lumd1063(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2C3_lumd1063_SHIFT)) & locald49_LDPRR2C3_lumd1063_MASK)

#define locald49_LDPRR2C3_lumd1062_MASK          (0x3FF0000U)
#define locald49_LDPRR2C3_lumd1062_SHIFT         (16U)
/*! lumd1062 - lumdat_1062 */
#define locald49_LDPRR2C3_lumd1062(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2C3_lumd1062_SHIFT)) & locald49_LDPRR2C3_lumd1062_MASK)
/*! @} */

/*! @name LDPRR2C4 - ldprofilereg2c4 */
/*! @{ */

#define locald49_LDPRR2C4_lumd1065_MASK          (0x3FFU)
#define locald49_LDPRR2C4_lumd1065_SHIFT         (0U)
/*! lumd1065 - lumdat_1065 */
#define locald49_LDPRR2C4_lumd1065(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2C4_lumd1065_SHIFT)) & locald49_LDPRR2C4_lumd1065_MASK)

#define locald49_LDPRR2C4_lumd1064_MASK          (0x3FF0000U)
#define locald49_LDPRR2C4_lumd1064_SHIFT         (16U)
/*! lumd1064 - lumdat_1064 */
#define locald49_LDPRR2C4_lumd1064(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2C4_lumd1064_SHIFT)) & locald49_LDPRR2C4_lumd1064_MASK)
/*! @} */

/*! @name LDPRR2C5 - ldprofilereg2c5 */
/*! @{ */

#define locald49_LDPRR2C5_lumd1067_MASK          (0x3FFU)
#define locald49_LDPRR2C5_lumd1067_SHIFT         (0U)
/*! lumd1067 - lumdat_1067 */
#define locald49_LDPRR2C5_lumd1067(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2C5_lumd1067_SHIFT)) & locald49_LDPRR2C5_lumd1067_MASK)

#define locald49_LDPRR2C5_lumd1066_MASK          (0x3FF0000U)
#define locald49_LDPRR2C5_lumd1066_SHIFT         (16U)
/*! lumd1066 - lumdat_1066 */
#define locald49_LDPRR2C5_lumd1066(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2C5_lumd1066_SHIFT)) & locald49_LDPRR2C5_lumd1066_MASK)
/*! @} */

/*! @name LDPRR2C6 - ldprofilereg2c6 */
/*! @{ */

#define locald49_LDPRR2C6_lumd1069_MASK          (0x3FFU)
#define locald49_LDPRR2C6_lumd1069_SHIFT         (0U)
/*! lumd1069 - lumdat_1069 */
#define locald49_LDPRR2C6_lumd1069(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2C6_lumd1069_SHIFT)) & locald49_LDPRR2C6_lumd1069_MASK)

#define locald49_LDPRR2C6_lumd1068_MASK          (0x3FF0000U)
#define locald49_LDPRR2C6_lumd1068_SHIFT         (16U)
/*! lumd1068 - lumdat_1068 */
#define locald49_LDPRR2C6_lumd1068(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2C6_lumd1068_SHIFT)) & locald49_LDPRR2C6_lumd1068_MASK)
/*! @} */

/*! @name LDPRR2C7 - ldprofilereg2c7 */
/*! @{ */

#define locald49_LDPRR2C7_lumd1071_MASK          (0x3FFU)
#define locald49_LDPRR2C7_lumd1071_SHIFT         (0U)
/*! lumd1071 - lumdat_1071 */
#define locald49_LDPRR2C7_lumd1071(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2C7_lumd1071_SHIFT)) & locald49_LDPRR2C7_lumd1071_MASK)

#define locald49_LDPRR2C7_lumd1070_MASK          (0x3FF0000U)
#define locald49_LDPRR2C7_lumd1070_SHIFT         (16U)
/*! lumd1070 - lumdat_1070 */
#define locald49_LDPRR2C7_lumd1070(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2C7_lumd1070_SHIFT)) & locald49_LDPRR2C7_lumd1070_MASK)
/*! @} */

/*! @name LDPRR2C8 - ldprofilereg2c8 */
/*! @{ */

#define locald49_LDPRR2C8_lumd1073_MASK          (0x3FFU)
#define locald49_LDPRR2C8_lumd1073_SHIFT         (0U)
/*! lumd1073 - lumdat_1073 */
#define locald49_LDPRR2C8_lumd1073(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2C8_lumd1073_SHIFT)) & locald49_LDPRR2C8_lumd1073_MASK)

#define locald49_LDPRR2C8_lumd1072_MASK          (0x3FF0000U)
#define locald49_LDPRR2C8_lumd1072_SHIFT         (16U)
/*! lumd1072 - lumdat_1072 */
#define locald49_LDPRR2C8_lumd1072(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2C8_lumd1072_SHIFT)) & locald49_LDPRR2C8_lumd1072_MASK)
/*! @} */

/*! @name LDPRR2C9 - ldprofilereg2c9 */
/*! @{ */

#define locald49_LDPRR2C9_lumd1075_MASK          (0x3FFU)
#define locald49_LDPRR2C9_lumd1075_SHIFT         (0U)
/*! lumd1075 - lumdat_1075 */
#define locald49_LDPRR2C9_lumd1075(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2C9_lumd1075_SHIFT)) & locald49_LDPRR2C9_lumd1075_MASK)

#define locald49_LDPRR2C9_lumd1074_MASK          (0x3FF0000U)
#define locald49_LDPRR2C9_lumd1074_SHIFT         (16U)
/*! lumd1074 - lumdat_1074 */
#define locald49_LDPRR2C9_lumd1074(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2C9_lumd1074_SHIFT)) & locald49_LDPRR2C9_lumd1074_MASK)
/*! @} */

/*! @name LDPRR2CA - ldprofilereg2ca */
/*! @{ */

#define locald49_LDPRR2CA_lumd1077_MASK          (0x3FFU)
#define locald49_LDPRR2CA_lumd1077_SHIFT         (0U)
/*! lumd1077 - lumdat_1077 */
#define locald49_LDPRR2CA_lumd1077(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2CA_lumd1077_SHIFT)) & locald49_LDPRR2CA_lumd1077_MASK)

#define locald49_LDPRR2CA_lumd1076_MASK          (0x3FF0000U)
#define locald49_LDPRR2CA_lumd1076_SHIFT         (16U)
/*! lumd1076 - lumdat_1076 */
#define locald49_LDPRR2CA_lumd1076(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2CA_lumd1076_SHIFT)) & locald49_LDPRR2CA_lumd1076_MASK)
/*! @} */

/*! @name LDPRR2CB - ldprofilereg2cb */
/*! @{ */

#define locald49_LDPRR2CB_lumd1079_MASK          (0x3FFU)
#define locald49_LDPRR2CB_lumd1079_SHIFT         (0U)
/*! lumd1079 - lumdat_1079 */
#define locald49_LDPRR2CB_lumd1079(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2CB_lumd1079_SHIFT)) & locald49_LDPRR2CB_lumd1079_MASK)

#define locald49_LDPRR2CB_lumd1078_MASK          (0x3FF0000U)
#define locald49_LDPRR2CB_lumd1078_SHIFT         (16U)
/*! lumd1078 - lumdat_1078 */
#define locald49_LDPRR2CB_lumd1078(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2CB_lumd1078_SHIFT)) & locald49_LDPRR2CB_lumd1078_MASK)
/*! @} */

/*! @name LDPRR2CC - ldprofilereg2cc */
/*! @{ */

#define locald49_LDPRR2CC_lumd1081_MASK          (0x3FFU)
#define locald49_LDPRR2CC_lumd1081_SHIFT         (0U)
/*! lumd1081 - lumdat_1081 */
#define locald49_LDPRR2CC_lumd1081(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2CC_lumd1081_SHIFT)) & locald49_LDPRR2CC_lumd1081_MASK)

#define locald49_LDPRR2CC_lumd1080_MASK          (0x3FF0000U)
#define locald49_LDPRR2CC_lumd1080_SHIFT         (16U)
/*! lumd1080 - lumdat_1080 */
#define locald49_LDPRR2CC_lumd1080(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2CC_lumd1080_SHIFT)) & locald49_LDPRR2CC_lumd1080_MASK)
/*! @} */

/*! @name LDPRR2CD - ldprofilereg2cd */
/*! @{ */

#define locald49_LDPRR2CD_lumd1083_MASK          (0x3FFU)
#define locald49_LDPRR2CD_lumd1083_SHIFT         (0U)
/*! lumd1083 - lumdat_1083 */
#define locald49_LDPRR2CD_lumd1083(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2CD_lumd1083_SHIFT)) & locald49_LDPRR2CD_lumd1083_MASK)

#define locald49_LDPRR2CD_lumd1082_MASK          (0x3FF0000U)
#define locald49_LDPRR2CD_lumd1082_SHIFT         (16U)
/*! lumd1082 - lumdat_1082 */
#define locald49_LDPRR2CD_lumd1082(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2CD_lumd1082_SHIFT)) & locald49_LDPRR2CD_lumd1082_MASK)
/*! @} */

/*! @name LDPRR2CE - ldprofilereg2ce */
/*! @{ */

#define locald49_LDPRR2CE_lumd1085_MASK          (0x3FFU)
#define locald49_LDPRR2CE_lumd1085_SHIFT         (0U)
/*! lumd1085 - lumdat_1085 */
#define locald49_LDPRR2CE_lumd1085(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2CE_lumd1085_SHIFT)) & locald49_LDPRR2CE_lumd1085_MASK)

#define locald49_LDPRR2CE_lumd1084_MASK          (0x3FF0000U)
#define locald49_LDPRR2CE_lumd1084_SHIFT         (16U)
/*! lumd1084 - lumdat_1084 */
#define locald49_LDPRR2CE_lumd1084(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2CE_lumd1084_SHIFT)) & locald49_LDPRR2CE_lumd1084_MASK)
/*! @} */

/*! @name LDPRR2CF - ldprofilereg2cf */
/*! @{ */

#define locald49_LDPRR2CF_lumd1087_MASK          (0x3FFU)
#define locald49_LDPRR2CF_lumd1087_SHIFT         (0U)
/*! lumd1087 - lumdat_1087 */
#define locald49_LDPRR2CF_lumd1087(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2CF_lumd1087_SHIFT)) & locald49_LDPRR2CF_lumd1087_MASK)

#define locald49_LDPRR2CF_lumd1086_MASK          (0x3FF0000U)
#define locald49_LDPRR2CF_lumd1086_SHIFT         (16U)
/*! lumd1086 - lumdat_1086 */
#define locald49_LDPRR2CF_lumd1086(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2CF_lumd1086_SHIFT)) & locald49_LDPRR2CF_lumd1086_MASK)
/*! @} */

/*! @name LDPRR2D0 - ldprofilereg2d0 */
/*! @{ */

#define locald49_LDPRR2D0_lumd1089_MASK          (0x3FFU)
#define locald49_LDPRR2D0_lumd1089_SHIFT         (0U)
/*! lumd1089 - lumdat_1089 */
#define locald49_LDPRR2D0_lumd1089(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2D0_lumd1089_SHIFT)) & locald49_LDPRR2D0_lumd1089_MASK)

#define locald49_LDPRR2D0_lumd1088_MASK          (0x3FF0000U)
#define locald49_LDPRR2D0_lumd1088_SHIFT         (16U)
/*! lumd1088 - lumdat_1088 */
#define locald49_LDPRR2D0_lumd1088(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2D0_lumd1088_SHIFT)) & locald49_LDPRR2D0_lumd1088_MASK)
/*! @} */

/*! @name LDPRR2D1 - ldprofilereg2d1 */
/*! @{ */

#define locald49_LDPRR2D1_lumd1091_MASK          (0x3FFU)
#define locald49_LDPRR2D1_lumd1091_SHIFT         (0U)
/*! lumd1091 - lumdat_1091 */
#define locald49_LDPRR2D1_lumd1091(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2D1_lumd1091_SHIFT)) & locald49_LDPRR2D1_lumd1091_MASK)

#define locald49_LDPRR2D1_lumd1090_MASK          (0x3FF0000U)
#define locald49_LDPRR2D1_lumd1090_SHIFT         (16U)
/*! lumd1090 - lumdat_1090 */
#define locald49_LDPRR2D1_lumd1090(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2D1_lumd1090_SHIFT)) & locald49_LDPRR2D1_lumd1090_MASK)
/*! @} */

/*! @name LDPRR2D2 - ldprofilereg2d2 */
/*! @{ */

#define locald49_LDPRR2D2_lumd1093_MASK          (0x3FFU)
#define locald49_LDPRR2D2_lumd1093_SHIFT         (0U)
/*! lumd1093 - lumdat_1093 */
#define locald49_LDPRR2D2_lumd1093(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2D2_lumd1093_SHIFT)) & locald49_LDPRR2D2_lumd1093_MASK)

#define locald49_LDPRR2D2_lumd1092_MASK          (0x3FF0000U)
#define locald49_LDPRR2D2_lumd1092_SHIFT         (16U)
/*! lumd1092 - lumdat_1092 */
#define locald49_LDPRR2D2_lumd1092(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2D2_lumd1092_SHIFT)) & locald49_LDPRR2D2_lumd1092_MASK)
/*! @} */

/*! @name LDPRR2D3 - ldprofilereg2d3 */
/*! @{ */

#define locald49_LDPRR2D3_lumd1095_MASK          (0x3FFU)
#define locald49_LDPRR2D3_lumd1095_SHIFT         (0U)
/*! lumd1095 - lumdat_1095 */
#define locald49_LDPRR2D3_lumd1095(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2D3_lumd1095_SHIFT)) & locald49_LDPRR2D3_lumd1095_MASK)

#define locald49_LDPRR2D3_lumd1094_MASK          (0x3FF0000U)
#define locald49_LDPRR2D3_lumd1094_SHIFT         (16U)
/*! lumd1094 - lumdat_1094 */
#define locald49_LDPRR2D3_lumd1094(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2D3_lumd1094_SHIFT)) & locald49_LDPRR2D3_lumd1094_MASK)
/*! @} */

/*! @name LDPRR2D4 - ldprofilereg2d4 */
/*! @{ */

#define locald49_LDPRR2D4_lumd1097_MASK          (0x3FFU)
#define locald49_LDPRR2D4_lumd1097_SHIFT         (0U)
/*! lumd1097 - lumdat_1097 */
#define locald49_LDPRR2D4_lumd1097(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2D4_lumd1097_SHIFT)) & locald49_LDPRR2D4_lumd1097_MASK)

#define locald49_LDPRR2D4_lumd1096_MASK          (0x3FF0000U)
#define locald49_LDPRR2D4_lumd1096_SHIFT         (16U)
/*! lumd1096 - lumdat_1096 */
#define locald49_LDPRR2D4_lumd1096(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2D4_lumd1096_SHIFT)) & locald49_LDPRR2D4_lumd1096_MASK)
/*! @} */

/*! @name LDPRR2D5 - ldprofilereg2d5 */
/*! @{ */

#define locald49_LDPRR2D5_lumd1099_MASK          (0x3FFU)
#define locald49_LDPRR2D5_lumd1099_SHIFT         (0U)
/*! lumd1099 - lumdat_1099 */
#define locald49_LDPRR2D5_lumd1099(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2D5_lumd1099_SHIFT)) & locald49_LDPRR2D5_lumd1099_MASK)

#define locald49_LDPRR2D5_lumd1098_MASK          (0x3FF0000U)
#define locald49_LDPRR2D5_lumd1098_SHIFT         (16U)
/*! lumd1098 - lumdat_1098 */
#define locald49_LDPRR2D5_lumd1098(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2D5_lumd1098_SHIFT)) & locald49_LDPRR2D5_lumd1098_MASK)
/*! @} */

/*! @name LDPRR2D6 - ldprofilereg2d6 */
/*! @{ */

#define locald49_LDPRR2D6_lumd1101_MASK          (0x3FFU)
#define locald49_LDPRR2D6_lumd1101_SHIFT         (0U)
/*! lumd1101 - lumdat_1101 */
#define locald49_LDPRR2D6_lumd1101(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2D6_lumd1101_SHIFT)) & locald49_LDPRR2D6_lumd1101_MASK)

#define locald49_LDPRR2D6_lumd1100_MASK          (0x3FF0000U)
#define locald49_LDPRR2D6_lumd1100_SHIFT         (16U)
/*! lumd1100 - lumdat_1100 */
#define locald49_LDPRR2D6_lumd1100(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2D6_lumd1100_SHIFT)) & locald49_LDPRR2D6_lumd1100_MASK)
/*! @} */

/*! @name LDPRR2D7 - ldprofilereg2d7 */
/*! @{ */

#define locald49_LDPRR2D7_lumd1103_MASK          (0x3FFU)
#define locald49_LDPRR2D7_lumd1103_SHIFT         (0U)
/*! lumd1103 - lumdat_1103 */
#define locald49_LDPRR2D7_lumd1103(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2D7_lumd1103_SHIFT)) & locald49_LDPRR2D7_lumd1103_MASK)

#define locald49_LDPRR2D7_lumd1102_MASK          (0x3FF0000U)
#define locald49_LDPRR2D7_lumd1102_SHIFT         (16U)
/*! lumd1102 - lumdat_1102 */
#define locald49_LDPRR2D7_lumd1102(x)            (((uint32_t)(((uint32_t)(x)) << locald49_LDPRR2D7_lumd1102_SHIFT)) & locald49_LDPRR2D7_lumd1102_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald49_Register_Masks */


/*!
 * @}
 */ /* end of group locald49_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD49_H_ */

