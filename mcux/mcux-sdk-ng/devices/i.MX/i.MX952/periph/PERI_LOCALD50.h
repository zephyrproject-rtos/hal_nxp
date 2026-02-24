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
**         CMSIS Peripheral Access Layer for locald50
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
 * @file PERI_locald50.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald50
 *
 * CMSIS Peripheral Access Layer for locald50
 */

#if !defined(PERI_LOCALD50_H_)
#define PERI_LOCALD50_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald50 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald50_Peripheral_Access_Layer locald50 Peripheral Access Layer
 * @{
 */

/** locald50 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR2E0;                          /**< ldprofilereg2e0, offset: 0x0 */
  __IO uint32_t LDPRR2E1;                          /**< ldprofilereg2e1, offset: 0x4 */
  __IO uint32_t LDPRR2E2;                          /**< ldprofilereg2e2, offset: 0x8 */
  __IO uint32_t LDPRR2E3;                          /**< ldprofilereg2e3, offset: 0xC */
  __IO uint32_t LDPRR2E4;                          /**< ldprofilereg2e4, offset: 0x10 */
  __IO uint32_t LDPRR2E5;                          /**< ldprofilereg2e5, offset: 0x14 */
  __IO uint32_t LDPRR2E6;                          /**< ldprofilereg2e6, offset: 0x18 */
  __IO uint32_t LDPRR2E7;                          /**< ldprofilereg2e7, offset: 0x1C */
  __IO uint32_t LDPRR2E8;                          /**< ldprofilereg2e8, offset: 0x20 */
  __IO uint32_t LDPRR2E9;                          /**< ldprofilereg2e9, offset: 0x24 */
  __IO uint32_t LDPRR2EA;                          /**< ldprofilereg2ea, offset: 0x28 */
  __IO uint32_t LDPRR2EB;                          /**< ldprofilereg2eb, offset: 0x2C */
  __IO uint32_t LDPRR2EC;                          /**< ldprofilereg2ec, offset: 0x30 */
  __IO uint32_t LDPRR2ED;                          /**< ldprofilereg2ed, offset: 0x34 */
  __IO uint32_t LDPRR2EE;                          /**< ldprofilereg2ee, offset: 0x38 */
  __IO uint32_t LDPRR2EF;                          /**< ldprofilereg2ef, offset: 0x3C */
  __IO uint32_t LDPRR2F0;                          /**< ldprofilereg2f0, offset: 0x40 */
  __IO uint32_t LDPRR2F1;                          /**< ldprofilereg2f1, offset: 0x44 */
  __IO uint32_t LDPRR2F2;                          /**< ldprofilereg2f2, offset: 0x48 */
  __IO uint32_t LDPRR2F3;                          /**< ldprofilereg2f3, offset: 0x4C */
  __IO uint32_t LDPRR2F4;                          /**< ldprofilereg2f4, offset: 0x50 */
  __IO uint32_t LDPRR2F5;                          /**< ldprofilereg2f5, offset: 0x54 */
  __IO uint32_t LDPRR2F6;                          /**< ldprofilereg2f6, offset: 0x58 */
  __IO uint32_t LDPRR2F7;                          /**< ldprofilereg2f7, offset: 0x5C */
} locald50_Type;

/* ----------------------------------------------------------------------------
   -- locald50 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald50_Register_Masks locald50 Register Masks
 * @{
 */

/*! @name LDPRR2E0 - ldprofilereg2e0 */
/*! @{ */

#define locald50_LDPRR2E0_lumd1105_MASK          (0x3FFU)
#define locald50_LDPRR2E0_lumd1105_SHIFT         (0U)
/*! lumd1105 - lumdat_1105 */
#define locald50_LDPRR2E0_lumd1105(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2E0_lumd1105_SHIFT)) & locald50_LDPRR2E0_lumd1105_MASK)

#define locald50_LDPRR2E0_lumd1104_MASK          (0x3FF0000U)
#define locald50_LDPRR2E0_lumd1104_SHIFT         (16U)
/*! lumd1104 - lumdat_1104 */
#define locald50_LDPRR2E0_lumd1104(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2E0_lumd1104_SHIFT)) & locald50_LDPRR2E0_lumd1104_MASK)
/*! @} */

/*! @name LDPRR2E1 - ldprofilereg2e1 */
/*! @{ */

#define locald50_LDPRR2E1_lumd1107_MASK          (0x3FFU)
#define locald50_LDPRR2E1_lumd1107_SHIFT         (0U)
/*! lumd1107 - lumdat_1107 */
#define locald50_LDPRR2E1_lumd1107(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2E1_lumd1107_SHIFT)) & locald50_LDPRR2E1_lumd1107_MASK)

#define locald50_LDPRR2E1_lumd1106_MASK          (0x3FF0000U)
#define locald50_LDPRR2E1_lumd1106_SHIFT         (16U)
/*! lumd1106 - lumdat_1106 */
#define locald50_LDPRR2E1_lumd1106(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2E1_lumd1106_SHIFT)) & locald50_LDPRR2E1_lumd1106_MASK)
/*! @} */

/*! @name LDPRR2E2 - ldprofilereg2e2 */
/*! @{ */

#define locald50_LDPRR2E2_lumd1109_MASK          (0x3FFU)
#define locald50_LDPRR2E2_lumd1109_SHIFT         (0U)
/*! lumd1109 - lumdat_1109 */
#define locald50_LDPRR2E2_lumd1109(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2E2_lumd1109_SHIFT)) & locald50_LDPRR2E2_lumd1109_MASK)

#define locald50_LDPRR2E2_lumd1108_MASK          (0x3FF0000U)
#define locald50_LDPRR2E2_lumd1108_SHIFT         (16U)
/*! lumd1108 - lumdat_1108 */
#define locald50_LDPRR2E2_lumd1108(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2E2_lumd1108_SHIFT)) & locald50_LDPRR2E2_lumd1108_MASK)
/*! @} */

/*! @name LDPRR2E3 - ldprofilereg2e3 */
/*! @{ */

#define locald50_LDPRR2E3_lumd1111_MASK          (0x3FFU)
#define locald50_LDPRR2E3_lumd1111_SHIFT         (0U)
/*! lumd1111 - lumdat_1111 */
#define locald50_LDPRR2E3_lumd1111(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2E3_lumd1111_SHIFT)) & locald50_LDPRR2E3_lumd1111_MASK)

#define locald50_LDPRR2E3_lumd1110_MASK          (0x3FF0000U)
#define locald50_LDPRR2E3_lumd1110_SHIFT         (16U)
/*! lumd1110 - lumdat_1110 */
#define locald50_LDPRR2E3_lumd1110(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2E3_lumd1110_SHIFT)) & locald50_LDPRR2E3_lumd1110_MASK)
/*! @} */

/*! @name LDPRR2E4 - ldprofilereg2e4 */
/*! @{ */

#define locald50_LDPRR2E4_lumd1113_MASK          (0x3FFU)
#define locald50_LDPRR2E4_lumd1113_SHIFT         (0U)
/*! lumd1113 - lumdat_1113 */
#define locald50_LDPRR2E4_lumd1113(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2E4_lumd1113_SHIFT)) & locald50_LDPRR2E4_lumd1113_MASK)

#define locald50_LDPRR2E4_lumd1112_MASK          (0x3FF0000U)
#define locald50_LDPRR2E4_lumd1112_SHIFT         (16U)
/*! lumd1112 - lumdat_1112 */
#define locald50_LDPRR2E4_lumd1112(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2E4_lumd1112_SHIFT)) & locald50_LDPRR2E4_lumd1112_MASK)
/*! @} */

/*! @name LDPRR2E5 - ldprofilereg2e5 */
/*! @{ */

#define locald50_LDPRR2E5_lumd1115_MASK          (0x3FFU)
#define locald50_LDPRR2E5_lumd1115_SHIFT         (0U)
/*! lumd1115 - lumdat_1115 */
#define locald50_LDPRR2E5_lumd1115(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2E5_lumd1115_SHIFT)) & locald50_LDPRR2E5_lumd1115_MASK)

#define locald50_LDPRR2E5_lumd1114_MASK          (0x3FF0000U)
#define locald50_LDPRR2E5_lumd1114_SHIFT         (16U)
/*! lumd1114 - lumdat_1114 */
#define locald50_LDPRR2E5_lumd1114(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2E5_lumd1114_SHIFT)) & locald50_LDPRR2E5_lumd1114_MASK)
/*! @} */

/*! @name LDPRR2E6 - ldprofilereg2e6 */
/*! @{ */

#define locald50_LDPRR2E6_lumd1117_MASK          (0x3FFU)
#define locald50_LDPRR2E6_lumd1117_SHIFT         (0U)
/*! lumd1117 - lumdat_1117 */
#define locald50_LDPRR2E6_lumd1117(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2E6_lumd1117_SHIFT)) & locald50_LDPRR2E6_lumd1117_MASK)

#define locald50_LDPRR2E6_lumd1116_MASK          (0x3FF0000U)
#define locald50_LDPRR2E6_lumd1116_SHIFT         (16U)
/*! lumd1116 - lumdat_1116 */
#define locald50_LDPRR2E6_lumd1116(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2E6_lumd1116_SHIFT)) & locald50_LDPRR2E6_lumd1116_MASK)
/*! @} */

/*! @name LDPRR2E7 - ldprofilereg2e7 */
/*! @{ */

#define locald50_LDPRR2E7_lumd1119_MASK          (0x3FFU)
#define locald50_LDPRR2E7_lumd1119_SHIFT         (0U)
/*! lumd1119 - lumdat_1119 */
#define locald50_LDPRR2E7_lumd1119(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2E7_lumd1119_SHIFT)) & locald50_LDPRR2E7_lumd1119_MASK)

#define locald50_LDPRR2E7_lumd1118_MASK          (0x3FF0000U)
#define locald50_LDPRR2E7_lumd1118_SHIFT         (16U)
/*! lumd1118 - lumdat_1118 */
#define locald50_LDPRR2E7_lumd1118(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2E7_lumd1118_SHIFT)) & locald50_LDPRR2E7_lumd1118_MASK)
/*! @} */

/*! @name LDPRR2E8 - ldprofilereg2e8 */
/*! @{ */

#define locald50_LDPRR2E8_lumd1121_MASK          (0x3FFU)
#define locald50_LDPRR2E8_lumd1121_SHIFT         (0U)
/*! lumd1121 - lumdat_1121 */
#define locald50_LDPRR2E8_lumd1121(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2E8_lumd1121_SHIFT)) & locald50_LDPRR2E8_lumd1121_MASK)

#define locald50_LDPRR2E8_lumd1120_MASK          (0x3FF0000U)
#define locald50_LDPRR2E8_lumd1120_SHIFT         (16U)
/*! lumd1120 - lumdat_1120 */
#define locald50_LDPRR2E8_lumd1120(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2E8_lumd1120_SHIFT)) & locald50_LDPRR2E8_lumd1120_MASK)
/*! @} */

/*! @name LDPRR2E9 - ldprofilereg2e9 */
/*! @{ */

#define locald50_LDPRR2E9_lumd1123_MASK          (0x3FFU)
#define locald50_LDPRR2E9_lumd1123_SHIFT         (0U)
/*! lumd1123 - lumdat_1123 */
#define locald50_LDPRR2E9_lumd1123(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2E9_lumd1123_SHIFT)) & locald50_LDPRR2E9_lumd1123_MASK)

#define locald50_LDPRR2E9_lumd1122_MASK          (0x3FF0000U)
#define locald50_LDPRR2E9_lumd1122_SHIFT         (16U)
/*! lumd1122 - lumdat_1122 */
#define locald50_LDPRR2E9_lumd1122(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2E9_lumd1122_SHIFT)) & locald50_LDPRR2E9_lumd1122_MASK)
/*! @} */

/*! @name LDPRR2EA - ldprofilereg2ea */
/*! @{ */

#define locald50_LDPRR2EA_lumd1125_MASK          (0x3FFU)
#define locald50_LDPRR2EA_lumd1125_SHIFT         (0U)
/*! lumd1125 - lumdat_1125 */
#define locald50_LDPRR2EA_lumd1125(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2EA_lumd1125_SHIFT)) & locald50_LDPRR2EA_lumd1125_MASK)

#define locald50_LDPRR2EA_lumd1124_MASK          (0x3FF0000U)
#define locald50_LDPRR2EA_lumd1124_SHIFT         (16U)
/*! lumd1124 - lumdat_1124 */
#define locald50_LDPRR2EA_lumd1124(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2EA_lumd1124_SHIFT)) & locald50_LDPRR2EA_lumd1124_MASK)
/*! @} */

/*! @name LDPRR2EB - ldprofilereg2eb */
/*! @{ */

#define locald50_LDPRR2EB_lumd1127_MASK          (0x3FFU)
#define locald50_LDPRR2EB_lumd1127_SHIFT         (0U)
/*! lumd1127 - lumdat_1127 */
#define locald50_LDPRR2EB_lumd1127(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2EB_lumd1127_SHIFT)) & locald50_LDPRR2EB_lumd1127_MASK)

#define locald50_LDPRR2EB_lumd1126_MASK          (0x3FF0000U)
#define locald50_LDPRR2EB_lumd1126_SHIFT         (16U)
/*! lumd1126 - lumdat_1126 */
#define locald50_LDPRR2EB_lumd1126(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2EB_lumd1126_SHIFT)) & locald50_LDPRR2EB_lumd1126_MASK)
/*! @} */

/*! @name LDPRR2EC - ldprofilereg2ec */
/*! @{ */

#define locald50_LDPRR2EC_lumd1129_MASK          (0x3FFU)
#define locald50_LDPRR2EC_lumd1129_SHIFT         (0U)
/*! lumd1129 - lumdat_1129 */
#define locald50_LDPRR2EC_lumd1129(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2EC_lumd1129_SHIFT)) & locald50_LDPRR2EC_lumd1129_MASK)

#define locald50_LDPRR2EC_lumd1128_MASK          (0x3FF0000U)
#define locald50_LDPRR2EC_lumd1128_SHIFT         (16U)
/*! lumd1128 - lumdat_1128 */
#define locald50_LDPRR2EC_lumd1128(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2EC_lumd1128_SHIFT)) & locald50_LDPRR2EC_lumd1128_MASK)
/*! @} */

/*! @name LDPRR2ED - ldprofilereg2ed */
/*! @{ */

#define locald50_LDPRR2ED_lumd1131_MASK          (0x3FFU)
#define locald50_LDPRR2ED_lumd1131_SHIFT         (0U)
/*! lumd1131 - lumdat_1131 */
#define locald50_LDPRR2ED_lumd1131(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2ED_lumd1131_SHIFT)) & locald50_LDPRR2ED_lumd1131_MASK)

#define locald50_LDPRR2ED_lumd1130_MASK          (0x3FF0000U)
#define locald50_LDPRR2ED_lumd1130_SHIFT         (16U)
/*! lumd1130 - lumdat_1130 */
#define locald50_LDPRR2ED_lumd1130(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2ED_lumd1130_SHIFT)) & locald50_LDPRR2ED_lumd1130_MASK)
/*! @} */

/*! @name LDPRR2EE - ldprofilereg2ee */
/*! @{ */

#define locald50_LDPRR2EE_lumd1133_MASK          (0x3FFU)
#define locald50_LDPRR2EE_lumd1133_SHIFT         (0U)
/*! lumd1133 - lumdat_1133 */
#define locald50_LDPRR2EE_lumd1133(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2EE_lumd1133_SHIFT)) & locald50_LDPRR2EE_lumd1133_MASK)

#define locald50_LDPRR2EE_lumd1132_MASK          (0x3FF0000U)
#define locald50_LDPRR2EE_lumd1132_SHIFT         (16U)
/*! lumd1132 - lumdat_1132 */
#define locald50_LDPRR2EE_lumd1132(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2EE_lumd1132_SHIFT)) & locald50_LDPRR2EE_lumd1132_MASK)
/*! @} */

/*! @name LDPRR2EF - ldprofilereg2ef */
/*! @{ */

#define locald50_LDPRR2EF_lumd1135_MASK          (0x3FFU)
#define locald50_LDPRR2EF_lumd1135_SHIFT         (0U)
/*! lumd1135 - lumdat_1135 */
#define locald50_LDPRR2EF_lumd1135(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2EF_lumd1135_SHIFT)) & locald50_LDPRR2EF_lumd1135_MASK)

#define locald50_LDPRR2EF_lumd1134_MASK          (0x3FF0000U)
#define locald50_LDPRR2EF_lumd1134_SHIFT         (16U)
/*! lumd1134 - lumdat_1134 */
#define locald50_LDPRR2EF_lumd1134(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2EF_lumd1134_SHIFT)) & locald50_LDPRR2EF_lumd1134_MASK)
/*! @} */

/*! @name LDPRR2F0 - ldprofilereg2f0 */
/*! @{ */

#define locald50_LDPRR2F0_lumd1137_MASK          (0x3FFU)
#define locald50_LDPRR2F0_lumd1137_SHIFT         (0U)
/*! lumd1137 - lumdat_1137 */
#define locald50_LDPRR2F0_lumd1137(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2F0_lumd1137_SHIFT)) & locald50_LDPRR2F0_lumd1137_MASK)

#define locald50_LDPRR2F0_lumd1136_MASK          (0x3FF0000U)
#define locald50_LDPRR2F0_lumd1136_SHIFT         (16U)
/*! lumd1136 - lumdat_1136 */
#define locald50_LDPRR2F0_lumd1136(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2F0_lumd1136_SHIFT)) & locald50_LDPRR2F0_lumd1136_MASK)
/*! @} */

/*! @name LDPRR2F1 - ldprofilereg2f1 */
/*! @{ */

#define locald50_LDPRR2F1_lumd1139_MASK          (0x3FFU)
#define locald50_LDPRR2F1_lumd1139_SHIFT         (0U)
/*! lumd1139 - lumdat_1139 */
#define locald50_LDPRR2F1_lumd1139(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2F1_lumd1139_SHIFT)) & locald50_LDPRR2F1_lumd1139_MASK)

#define locald50_LDPRR2F1_lumd1138_MASK          (0x3FF0000U)
#define locald50_LDPRR2F1_lumd1138_SHIFT         (16U)
/*! lumd1138 - lumdat_1138 */
#define locald50_LDPRR2F1_lumd1138(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2F1_lumd1138_SHIFT)) & locald50_LDPRR2F1_lumd1138_MASK)
/*! @} */

/*! @name LDPRR2F2 - ldprofilereg2f2 */
/*! @{ */

#define locald50_LDPRR2F2_lumd1141_MASK          (0x3FFU)
#define locald50_LDPRR2F2_lumd1141_SHIFT         (0U)
/*! lumd1141 - lumdat_1141 */
#define locald50_LDPRR2F2_lumd1141(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2F2_lumd1141_SHIFT)) & locald50_LDPRR2F2_lumd1141_MASK)

#define locald50_LDPRR2F2_lumd1140_MASK          (0x3FF0000U)
#define locald50_LDPRR2F2_lumd1140_SHIFT         (16U)
/*! lumd1140 - lumdat_1140 */
#define locald50_LDPRR2F2_lumd1140(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2F2_lumd1140_SHIFT)) & locald50_LDPRR2F2_lumd1140_MASK)
/*! @} */

/*! @name LDPRR2F3 - ldprofilereg2f3 */
/*! @{ */

#define locald50_LDPRR2F3_lumd1143_MASK          (0x3FFU)
#define locald50_LDPRR2F3_lumd1143_SHIFT         (0U)
/*! lumd1143 - lumdat_1143 */
#define locald50_LDPRR2F3_lumd1143(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2F3_lumd1143_SHIFT)) & locald50_LDPRR2F3_lumd1143_MASK)

#define locald50_LDPRR2F3_lumd1142_MASK          (0x3FF0000U)
#define locald50_LDPRR2F3_lumd1142_SHIFT         (16U)
/*! lumd1142 - lumdat_1142 */
#define locald50_LDPRR2F3_lumd1142(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2F3_lumd1142_SHIFT)) & locald50_LDPRR2F3_lumd1142_MASK)
/*! @} */

/*! @name LDPRR2F4 - ldprofilereg2f4 */
/*! @{ */

#define locald50_LDPRR2F4_lumd1145_MASK          (0x3FFU)
#define locald50_LDPRR2F4_lumd1145_SHIFT         (0U)
/*! lumd1145 - lumdat_1145 */
#define locald50_LDPRR2F4_lumd1145(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2F4_lumd1145_SHIFT)) & locald50_LDPRR2F4_lumd1145_MASK)

#define locald50_LDPRR2F4_lumd1144_MASK          (0x3FF0000U)
#define locald50_LDPRR2F4_lumd1144_SHIFT         (16U)
/*! lumd1144 - lumdat_1144 */
#define locald50_LDPRR2F4_lumd1144(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2F4_lumd1144_SHIFT)) & locald50_LDPRR2F4_lumd1144_MASK)
/*! @} */

/*! @name LDPRR2F5 - ldprofilereg2f5 */
/*! @{ */

#define locald50_LDPRR2F5_lumd1147_MASK          (0x3FFU)
#define locald50_LDPRR2F5_lumd1147_SHIFT         (0U)
/*! lumd1147 - lumdat_1147 */
#define locald50_LDPRR2F5_lumd1147(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2F5_lumd1147_SHIFT)) & locald50_LDPRR2F5_lumd1147_MASK)

#define locald50_LDPRR2F5_lumd1146_MASK          (0x3FF0000U)
#define locald50_LDPRR2F5_lumd1146_SHIFT         (16U)
/*! lumd1146 - lumdat_1146 */
#define locald50_LDPRR2F5_lumd1146(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2F5_lumd1146_SHIFT)) & locald50_LDPRR2F5_lumd1146_MASK)
/*! @} */

/*! @name LDPRR2F6 - ldprofilereg2f6 */
/*! @{ */

#define locald50_LDPRR2F6_lumd1149_MASK          (0x3FFU)
#define locald50_LDPRR2F6_lumd1149_SHIFT         (0U)
/*! lumd1149 - lumdat_1149 */
#define locald50_LDPRR2F6_lumd1149(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2F6_lumd1149_SHIFT)) & locald50_LDPRR2F6_lumd1149_MASK)

#define locald50_LDPRR2F6_lumd1148_MASK          (0x3FF0000U)
#define locald50_LDPRR2F6_lumd1148_SHIFT         (16U)
/*! lumd1148 - lumdat_1148 */
#define locald50_LDPRR2F6_lumd1148(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2F6_lumd1148_SHIFT)) & locald50_LDPRR2F6_lumd1148_MASK)
/*! @} */

/*! @name LDPRR2F7 - ldprofilereg2f7 */
/*! @{ */

#define locald50_LDPRR2F7_lumd1151_MASK          (0x3FFU)
#define locald50_LDPRR2F7_lumd1151_SHIFT         (0U)
/*! lumd1151 - lumdat_1151 */
#define locald50_LDPRR2F7_lumd1151(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2F7_lumd1151_SHIFT)) & locald50_LDPRR2F7_lumd1151_MASK)

#define locald50_LDPRR2F7_lumd1150_MASK          (0x3FF0000U)
#define locald50_LDPRR2F7_lumd1150_SHIFT         (16U)
/*! lumd1150 - lumdat_1150 */
#define locald50_LDPRR2F7_lumd1150(x)            (((uint32_t)(((uint32_t)(x)) << locald50_LDPRR2F7_lumd1150_SHIFT)) & locald50_LDPRR2F7_lumd1150_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald50_Register_Masks */


/*!
 * @}
 */ /* end of group locald50_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD50_H_ */

