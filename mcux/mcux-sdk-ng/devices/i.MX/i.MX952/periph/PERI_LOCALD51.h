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
**         CMSIS Peripheral Access Layer for locald51
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
 * @file PERI_locald51.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald51
 *
 * CMSIS Peripheral Access Layer for locald51
 */

#if !defined(PERI_LOCALD51_H_)
#define PERI_LOCALD51_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald51 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald51_Peripheral_Access_Layer locald51 Peripheral Access Layer
 * @{
 */

/** locald51 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR300;                          /**< ldprofilereg300, offset: 0x0 */
  __IO uint32_t LDPRR301;                          /**< ldprofilereg301, offset: 0x4 */
  __IO uint32_t LDPRR302;                          /**< ldprofilereg302, offset: 0x8 */
  __IO uint32_t LDPRR303;                          /**< ldprofilereg303, offset: 0xC */
  __IO uint32_t LDPRR304;                          /**< ldprofilereg304, offset: 0x10 */
  __IO uint32_t LDPRR305;                          /**< ldprofilereg305, offset: 0x14 */
  __IO uint32_t LDPRR306;                          /**< ldprofilereg306, offset: 0x18 */
  __IO uint32_t LDPRR307;                          /**< ldprofilereg307, offset: 0x1C */
  __IO uint32_t LDPRR308;                          /**< ldprofilereg308, offset: 0x20 */
  __IO uint32_t LDPRR309;                          /**< ldprofilereg309, offset: 0x24 */
  __IO uint32_t LDPRR30A;                          /**< ldprofilereg30a, offset: 0x28 */
  __IO uint32_t LDPRR30B;                          /**< ldprofilereg30b, offset: 0x2C */
  __IO uint32_t LDPRR30C;                          /**< ldprofilereg30c, offset: 0x30 */
  __IO uint32_t LDPRR30D;                          /**< ldprofilereg30d, offset: 0x34 */
  __IO uint32_t LDPRR30E;                          /**< ldprofilereg30e, offset: 0x38 */
  __IO uint32_t LDPRR30F;                          /**< ldprofilereg30f, offset: 0x3C */
  __IO uint32_t LDPRR310;                          /**< ldprofilereg310, offset: 0x40 */
  __IO uint32_t LDPRR311;                          /**< ldprofilereg311, offset: 0x44 */
  __IO uint32_t LDPRR312;                          /**< ldprofilereg312, offset: 0x48 */
  __IO uint32_t LDPRR313;                          /**< ldprofilereg313, offset: 0x4C */
  __IO uint32_t LDPRR314;                          /**< ldprofilereg314, offset: 0x50 */
  __IO uint32_t LDPRR315;                          /**< ldprofilereg315, offset: 0x54 */
  __IO uint32_t LDPRR316;                          /**< ldprofilereg316, offset: 0x58 */
  __IO uint32_t LDPRR317;                          /**< ldprofilereg317, offset: 0x5C */
} locald51_Type;

/* ----------------------------------------------------------------------------
   -- locald51 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald51_Register_Masks locald51 Register Masks
 * @{
 */

/*! @name LDPRR300 - ldprofilereg300 */
/*! @{ */

#define locald51_LDPRR300_lumd1153_MASK          (0x3FFU)
#define locald51_LDPRR300_lumd1153_SHIFT         (0U)
/*! lumd1153 - lumdat_1153 */
#define locald51_LDPRR300_lumd1153(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR300_lumd1153_SHIFT)) & locald51_LDPRR300_lumd1153_MASK)

#define locald51_LDPRR300_lumd1152_MASK          (0x3FF0000U)
#define locald51_LDPRR300_lumd1152_SHIFT         (16U)
/*! lumd1152 - lumdat_1152 */
#define locald51_LDPRR300_lumd1152(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR300_lumd1152_SHIFT)) & locald51_LDPRR300_lumd1152_MASK)
/*! @} */

/*! @name LDPRR301 - ldprofilereg301 */
/*! @{ */

#define locald51_LDPRR301_lumd1155_MASK          (0x3FFU)
#define locald51_LDPRR301_lumd1155_SHIFT         (0U)
/*! lumd1155 - lumdat_1155 */
#define locald51_LDPRR301_lumd1155(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR301_lumd1155_SHIFT)) & locald51_LDPRR301_lumd1155_MASK)

#define locald51_LDPRR301_lumd1154_MASK          (0x3FF0000U)
#define locald51_LDPRR301_lumd1154_SHIFT         (16U)
/*! lumd1154 - lumdat_1154 */
#define locald51_LDPRR301_lumd1154(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR301_lumd1154_SHIFT)) & locald51_LDPRR301_lumd1154_MASK)
/*! @} */

/*! @name LDPRR302 - ldprofilereg302 */
/*! @{ */

#define locald51_LDPRR302_lumd1157_MASK          (0x3FFU)
#define locald51_LDPRR302_lumd1157_SHIFT         (0U)
/*! lumd1157 - lumdat_1157 */
#define locald51_LDPRR302_lumd1157(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR302_lumd1157_SHIFT)) & locald51_LDPRR302_lumd1157_MASK)

#define locald51_LDPRR302_lumd1156_MASK          (0x3FF0000U)
#define locald51_LDPRR302_lumd1156_SHIFT         (16U)
/*! lumd1156 - lumdat_1156 */
#define locald51_LDPRR302_lumd1156(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR302_lumd1156_SHIFT)) & locald51_LDPRR302_lumd1156_MASK)
/*! @} */

/*! @name LDPRR303 - ldprofilereg303 */
/*! @{ */

#define locald51_LDPRR303_lumd1159_MASK          (0x3FFU)
#define locald51_LDPRR303_lumd1159_SHIFT         (0U)
/*! lumd1159 - lumdat_1159 */
#define locald51_LDPRR303_lumd1159(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR303_lumd1159_SHIFT)) & locald51_LDPRR303_lumd1159_MASK)

#define locald51_LDPRR303_lumd1158_MASK          (0x3FF0000U)
#define locald51_LDPRR303_lumd1158_SHIFT         (16U)
/*! lumd1158 - lumdat_1158 */
#define locald51_LDPRR303_lumd1158(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR303_lumd1158_SHIFT)) & locald51_LDPRR303_lumd1158_MASK)
/*! @} */

/*! @name LDPRR304 - ldprofilereg304 */
/*! @{ */

#define locald51_LDPRR304_lumd1161_MASK          (0x3FFU)
#define locald51_LDPRR304_lumd1161_SHIFT         (0U)
/*! lumd1161 - lumdat_1161 */
#define locald51_LDPRR304_lumd1161(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR304_lumd1161_SHIFT)) & locald51_LDPRR304_lumd1161_MASK)

#define locald51_LDPRR304_lumd1160_MASK          (0x3FF0000U)
#define locald51_LDPRR304_lumd1160_SHIFT         (16U)
/*! lumd1160 - lumdat_1160 */
#define locald51_LDPRR304_lumd1160(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR304_lumd1160_SHIFT)) & locald51_LDPRR304_lumd1160_MASK)
/*! @} */

/*! @name LDPRR305 - ldprofilereg305 */
/*! @{ */

#define locald51_LDPRR305_lumd1163_MASK          (0x3FFU)
#define locald51_LDPRR305_lumd1163_SHIFT         (0U)
/*! lumd1163 - lumdat_1163 */
#define locald51_LDPRR305_lumd1163(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR305_lumd1163_SHIFT)) & locald51_LDPRR305_lumd1163_MASK)

#define locald51_LDPRR305_lumd1162_MASK          (0x3FF0000U)
#define locald51_LDPRR305_lumd1162_SHIFT         (16U)
/*! lumd1162 - lumdat_1162 */
#define locald51_LDPRR305_lumd1162(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR305_lumd1162_SHIFT)) & locald51_LDPRR305_lumd1162_MASK)
/*! @} */

/*! @name LDPRR306 - ldprofilereg306 */
/*! @{ */

#define locald51_LDPRR306_lumd1165_MASK          (0x3FFU)
#define locald51_LDPRR306_lumd1165_SHIFT         (0U)
/*! lumd1165 - lumdat_1165 */
#define locald51_LDPRR306_lumd1165(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR306_lumd1165_SHIFT)) & locald51_LDPRR306_lumd1165_MASK)

#define locald51_LDPRR306_lumd1164_MASK          (0x3FF0000U)
#define locald51_LDPRR306_lumd1164_SHIFT         (16U)
/*! lumd1164 - lumdat_1164 */
#define locald51_LDPRR306_lumd1164(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR306_lumd1164_SHIFT)) & locald51_LDPRR306_lumd1164_MASK)
/*! @} */

/*! @name LDPRR307 - ldprofilereg307 */
/*! @{ */

#define locald51_LDPRR307_lumd1167_MASK          (0x3FFU)
#define locald51_LDPRR307_lumd1167_SHIFT         (0U)
/*! lumd1167 - lumdat_1167 */
#define locald51_LDPRR307_lumd1167(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR307_lumd1167_SHIFT)) & locald51_LDPRR307_lumd1167_MASK)

#define locald51_LDPRR307_lumd1166_MASK          (0x3FF0000U)
#define locald51_LDPRR307_lumd1166_SHIFT         (16U)
/*! lumd1166 - lumdat_1166 */
#define locald51_LDPRR307_lumd1166(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR307_lumd1166_SHIFT)) & locald51_LDPRR307_lumd1166_MASK)
/*! @} */

/*! @name LDPRR308 - ldprofilereg308 */
/*! @{ */

#define locald51_LDPRR308_lumd1169_MASK          (0x3FFU)
#define locald51_LDPRR308_lumd1169_SHIFT         (0U)
/*! lumd1169 - lumdat_1169 */
#define locald51_LDPRR308_lumd1169(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR308_lumd1169_SHIFT)) & locald51_LDPRR308_lumd1169_MASK)

#define locald51_LDPRR308_lumd1168_MASK          (0x3FF0000U)
#define locald51_LDPRR308_lumd1168_SHIFT         (16U)
/*! lumd1168 - lumdat_1168 */
#define locald51_LDPRR308_lumd1168(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR308_lumd1168_SHIFT)) & locald51_LDPRR308_lumd1168_MASK)
/*! @} */

/*! @name LDPRR309 - ldprofilereg309 */
/*! @{ */

#define locald51_LDPRR309_lumd1171_MASK          (0x3FFU)
#define locald51_LDPRR309_lumd1171_SHIFT         (0U)
/*! lumd1171 - lumdat_1171 */
#define locald51_LDPRR309_lumd1171(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR309_lumd1171_SHIFT)) & locald51_LDPRR309_lumd1171_MASK)

#define locald51_LDPRR309_lumd1170_MASK          (0x3FF0000U)
#define locald51_LDPRR309_lumd1170_SHIFT         (16U)
/*! lumd1170 - lumdat_1170 */
#define locald51_LDPRR309_lumd1170(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR309_lumd1170_SHIFT)) & locald51_LDPRR309_lumd1170_MASK)
/*! @} */

/*! @name LDPRR30A - ldprofilereg30a */
/*! @{ */

#define locald51_LDPRR30A_lumd1173_MASK          (0x3FFU)
#define locald51_LDPRR30A_lumd1173_SHIFT         (0U)
/*! lumd1173 - lumdat_1173 */
#define locald51_LDPRR30A_lumd1173(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR30A_lumd1173_SHIFT)) & locald51_LDPRR30A_lumd1173_MASK)

#define locald51_LDPRR30A_lumd1172_MASK          (0x3FF0000U)
#define locald51_LDPRR30A_lumd1172_SHIFT         (16U)
/*! lumd1172 - lumdat_1172 */
#define locald51_LDPRR30A_lumd1172(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR30A_lumd1172_SHIFT)) & locald51_LDPRR30A_lumd1172_MASK)
/*! @} */

/*! @name LDPRR30B - ldprofilereg30b */
/*! @{ */

#define locald51_LDPRR30B_lumd1175_MASK          (0x3FFU)
#define locald51_LDPRR30B_lumd1175_SHIFT         (0U)
/*! lumd1175 - lumdat_1175 */
#define locald51_LDPRR30B_lumd1175(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR30B_lumd1175_SHIFT)) & locald51_LDPRR30B_lumd1175_MASK)

#define locald51_LDPRR30B_lumd1174_MASK          (0x3FF0000U)
#define locald51_LDPRR30B_lumd1174_SHIFT         (16U)
/*! lumd1174 - lumdat_1174 */
#define locald51_LDPRR30B_lumd1174(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR30B_lumd1174_SHIFT)) & locald51_LDPRR30B_lumd1174_MASK)
/*! @} */

/*! @name LDPRR30C - ldprofilereg30c */
/*! @{ */

#define locald51_LDPRR30C_lumd1177_MASK          (0x3FFU)
#define locald51_LDPRR30C_lumd1177_SHIFT         (0U)
/*! lumd1177 - lumdat_1177 */
#define locald51_LDPRR30C_lumd1177(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR30C_lumd1177_SHIFT)) & locald51_LDPRR30C_lumd1177_MASK)

#define locald51_LDPRR30C_lumd1176_MASK          (0x3FF0000U)
#define locald51_LDPRR30C_lumd1176_SHIFT         (16U)
/*! lumd1176 - lumdat_1176 */
#define locald51_LDPRR30C_lumd1176(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR30C_lumd1176_SHIFT)) & locald51_LDPRR30C_lumd1176_MASK)
/*! @} */

/*! @name LDPRR30D - ldprofilereg30d */
/*! @{ */

#define locald51_LDPRR30D_lumd1179_MASK          (0x3FFU)
#define locald51_LDPRR30D_lumd1179_SHIFT         (0U)
/*! lumd1179 - lumdat_1179 */
#define locald51_LDPRR30D_lumd1179(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR30D_lumd1179_SHIFT)) & locald51_LDPRR30D_lumd1179_MASK)

#define locald51_LDPRR30D_lumd1178_MASK          (0x3FF0000U)
#define locald51_LDPRR30D_lumd1178_SHIFT         (16U)
/*! lumd1178 - lumdat_1178 */
#define locald51_LDPRR30D_lumd1178(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR30D_lumd1178_SHIFT)) & locald51_LDPRR30D_lumd1178_MASK)
/*! @} */

/*! @name LDPRR30E - ldprofilereg30e */
/*! @{ */

#define locald51_LDPRR30E_lumd1181_MASK          (0x3FFU)
#define locald51_LDPRR30E_lumd1181_SHIFT         (0U)
/*! lumd1181 - lumdat_1181 */
#define locald51_LDPRR30E_lumd1181(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR30E_lumd1181_SHIFT)) & locald51_LDPRR30E_lumd1181_MASK)

#define locald51_LDPRR30E_lumd1180_MASK          (0x3FF0000U)
#define locald51_LDPRR30E_lumd1180_SHIFT         (16U)
/*! lumd1180 - lumdat_1180 */
#define locald51_LDPRR30E_lumd1180(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR30E_lumd1180_SHIFT)) & locald51_LDPRR30E_lumd1180_MASK)
/*! @} */

/*! @name LDPRR30F - ldprofilereg30f */
/*! @{ */

#define locald51_LDPRR30F_lumd1183_MASK          (0x3FFU)
#define locald51_LDPRR30F_lumd1183_SHIFT         (0U)
/*! lumd1183 - lumdat_1183 */
#define locald51_LDPRR30F_lumd1183(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR30F_lumd1183_SHIFT)) & locald51_LDPRR30F_lumd1183_MASK)

#define locald51_LDPRR30F_lumd1182_MASK          (0x3FF0000U)
#define locald51_LDPRR30F_lumd1182_SHIFT         (16U)
/*! lumd1182 - lumdat_1182 */
#define locald51_LDPRR30F_lumd1182(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR30F_lumd1182_SHIFT)) & locald51_LDPRR30F_lumd1182_MASK)
/*! @} */

/*! @name LDPRR310 - ldprofilereg310 */
/*! @{ */

#define locald51_LDPRR310_lumd1185_MASK          (0x3FFU)
#define locald51_LDPRR310_lumd1185_SHIFT         (0U)
/*! lumd1185 - lumdat_1185 */
#define locald51_LDPRR310_lumd1185(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR310_lumd1185_SHIFT)) & locald51_LDPRR310_lumd1185_MASK)

#define locald51_LDPRR310_lumd1184_MASK          (0x3FF0000U)
#define locald51_LDPRR310_lumd1184_SHIFT         (16U)
/*! lumd1184 - lumdat_1184 */
#define locald51_LDPRR310_lumd1184(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR310_lumd1184_SHIFT)) & locald51_LDPRR310_lumd1184_MASK)
/*! @} */

/*! @name LDPRR311 - ldprofilereg311 */
/*! @{ */

#define locald51_LDPRR311_lumd1187_MASK          (0x3FFU)
#define locald51_LDPRR311_lumd1187_SHIFT         (0U)
/*! lumd1187 - lumdat_1187 */
#define locald51_LDPRR311_lumd1187(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR311_lumd1187_SHIFT)) & locald51_LDPRR311_lumd1187_MASK)

#define locald51_LDPRR311_lumd1186_MASK          (0x3FF0000U)
#define locald51_LDPRR311_lumd1186_SHIFT         (16U)
/*! lumd1186 - lumdat_1186 */
#define locald51_LDPRR311_lumd1186(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR311_lumd1186_SHIFT)) & locald51_LDPRR311_lumd1186_MASK)
/*! @} */

/*! @name LDPRR312 - ldprofilereg312 */
/*! @{ */

#define locald51_LDPRR312_lumd1189_MASK          (0x3FFU)
#define locald51_LDPRR312_lumd1189_SHIFT         (0U)
/*! lumd1189 - lumdat_1189 */
#define locald51_LDPRR312_lumd1189(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR312_lumd1189_SHIFT)) & locald51_LDPRR312_lumd1189_MASK)

#define locald51_LDPRR312_lumd1188_MASK          (0x3FF0000U)
#define locald51_LDPRR312_lumd1188_SHIFT         (16U)
/*! lumd1188 - lumdat_1188 */
#define locald51_LDPRR312_lumd1188(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR312_lumd1188_SHIFT)) & locald51_LDPRR312_lumd1188_MASK)
/*! @} */

/*! @name LDPRR313 - ldprofilereg313 */
/*! @{ */

#define locald51_LDPRR313_lumd1191_MASK          (0x3FFU)
#define locald51_LDPRR313_lumd1191_SHIFT         (0U)
/*! lumd1191 - lumdat_1191 */
#define locald51_LDPRR313_lumd1191(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR313_lumd1191_SHIFT)) & locald51_LDPRR313_lumd1191_MASK)

#define locald51_LDPRR313_lumd1190_MASK          (0x3FF0000U)
#define locald51_LDPRR313_lumd1190_SHIFT         (16U)
/*! lumd1190 - lumdat_1190 */
#define locald51_LDPRR313_lumd1190(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR313_lumd1190_SHIFT)) & locald51_LDPRR313_lumd1190_MASK)
/*! @} */

/*! @name LDPRR314 - ldprofilereg314 */
/*! @{ */

#define locald51_LDPRR314_lumd1193_MASK          (0x3FFU)
#define locald51_LDPRR314_lumd1193_SHIFT         (0U)
/*! lumd1193 - lumdat_1193 */
#define locald51_LDPRR314_lumd1193(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR314_lumd1193_SHIFT)) & locald51_LDPRR314_lumd1193_MASK)

#define locald51_LDPRR314_lumd1192_MASK          (0x3FF0000U)
#define locald51_LDPRR314_lumd1192_SHIFT         (16U)
/*! lumd1192 - lumdat_1192 */
#define locald51_LDPRR314_lumd1192(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR314_lumd1192_SHIFT)) & locald51_LDPRR314_lumd1192_MASK)
/*! @} */

/*! @name LDPRR315 - ldprofilereg315 */
/*! @{ */

#define locald51_LDPRR315_lumd1195_MASK          (0x3FFU)
#define locald51_LDPRR315_lumd1195_SHIFT         (0U)
/*! lumd1195 - lumdat_1195 */
#define locald51_LDPRR315_lumd1195(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR315_lumd1195_SHIFT)) & locald51_LDPRR315_lumd1195_MASK)

#define locald51_LDPRR315_lumd1194_MASK          (0x3FF0000U)
#define locald51_LDPRR315_lumd1194_SHIFT         (16U)
/*! lumd1194 - lumdat_1194 */
#define locald51_LDPRR315_lumd1194(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR315_lumd1194_SHIFT)) & locald51_LDPRR315_lumd1194_MASK)
/*! @} */

/*! @name LDPRR316 - ldprofilereg316 */
/*! @{ */

#define locald51_LDPRR316_lumd1197_MASK          (0x3FFU)
#define locald51_LDPRR316_lumd1197_SHIFT         (0U)
/*! lumd1197 - lumdat_1197 */
#define locald51_LDPRR316_lumd1197(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR316_lumd1197_SHIFT)) & locald51_LDPRR316_lumd1197_MASK)

#define locald51_LDPRR316_lumd1196_MASK          (0x3FF0000U)
#define locald51_LDPRR316_lumd1196_SHIFT         (16U)
/*! lumd1196 - lumdat_1196 */
#define locald51_LDPRR316_lumd1196(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR316_lumd1196_SHIFT)) & locald51_LDPRR316_lumd1196_MASK)
/*! @} */

/*! @name LDPRR317 - ldprofilereg317 */
/*! @{ */

#define locald51_LDPRR317_lumd1199_MASK          (0x3FFU)
#define locald51_LDPRR317_lumd1199_SHIFT         (0U)
/*! lumd1199 - lumdat_1199 */
#define locald51_LDPRR317_lumd1199(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR317_lumd1199_SHIFT)) & locald51_LDPRR317_lumd1199_MASK)

#define locald51_LDPRR317_lumd1198_MASK          (0x3FF0000U)
#define locald51_LDPRR317_lumd1198_SHIFT         (16U)
/*! lumd1198 - lumdat_1198 */
#define locald51_LDPRR317_lumd1198(x)            (((uint32_t)(((uint32_t)(x)) << locald51_LDPRR317_lumd1198_SHIFT)) & locald51_LDPRR317_lumd1198_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald51_Register_Masks */


/*!
 * @}
 */ /* end of group locald51_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD51_H_ */

