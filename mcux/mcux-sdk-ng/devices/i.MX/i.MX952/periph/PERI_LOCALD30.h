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
**         CMSIS Peripheral Access Layer for locald30
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
 * @file PERI_locald30.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald30
 *
 * CMSIS Peripheral Access Layer for locald30
 */

#if !defined(PERI_LOCALD30_H_)
#define PERI_LOCALD30_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald30 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald30_Peripheral_Access_Layer locald30 Peripheral Access Layer
 * @{
 */

/** locald30 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR060;                          /**< ldprofilereg060, offset: 0x0 */
  __IO uint32_t LDPRR061;                          /**< ldprofilereg061, offset: 0x4 */
  __IO uint32_t LDPRR062;                          /**< ldprofilereg062, offset: 0x8 */
  __IO uint32_t LDPRR063;                          /**< ldprofilereg063, offset: 0xC */
  __IO uint32_t LDPRR064;                          /**< ldprofilereg064, offset: 0x10 */
  __IO uint32_t LDPRR065;                          /**< ldprofilereg065, offset: 0x14 */
  __IO uint32_t LDPRR066;                          /**< ldprofilereg066, offset: 0x18 */
  __IO uint32_t LDPRR067;                          /**< ldprofilereg067, offset: 0x1C */
  __IO uint32_t LDPRR068;                          /**< ldprofilereg068, offset: 0x20 */
  __IO uint32_t LDPRR069;                          /**< ldprofilereg069, offset: 0x24 */
  __IO uint32_t LDPRR06A;                          /**< ldprofilereg06a, offset: 0x28 */
  __IO uint32_t LDPRR06B;                          /**< ldprofilereg06b, offset: 0x2C */
  __IO uint32_t LDPRR06C;                          /**< ldprofilereg06c, offset: 0x30 */
  __IO uint32_t LDPRR06D;                          /**< ldprofilereg06d, offset: 0x34 */
  __IO uint32_t LDPRR06E;                          /**< ldprofilereg06e, offset: 0x38 */
  __IO uint32_t LDPRR06F;                          /**< ldprofilereg06f, offset: 0x3C */
  __IO uint32_t LDPRR070;                          /**< ldprofilereg070, offset: 0x40 */
  __IO uint32_t LDPRR071;                          /**< ldprofilereg071, offset: 0x44 */
  __IO uint32_t LDPRR072;                          /**< ldprofilereg072, offset: 0x48 */
  __IO uint32_t LDPRR073;                          /**< ldprofilereg073, offset: 0x4C */
  __IO uint32_t LDPRR074;                          /**< ldprofilereg074, offset: 0x50 */
  __IO uint32_t LDPRR075;                          /**< ldprofilereg075, offset: 0x54 */
  __IO uint32_t LDPRR076;                          /**< ldprofilereg076, offset: 0x58 */
  __IO uint32_t LDPRR077;                          /**< ldprofilereg077, offset: 0x5C */
} locald30_Type;

/* ----------------------------------------------------------------------------
   -- locald30 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald30_Register_Masks locald30 Register Masks
 * @{
 */

/*! @name LDPRR060 - ldprofilereg060 */
/*! @{ */

#define locald30_LDPRR060_lumd145_MASK           (0x3FFU)
#define locald30_LDPRR060_lumd145_SHIFT          (0U)
/*! lumd145 - lumdat_145 */
#define locald30_LDPRR060_lumd145(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR060_lumd145_SHIFT)) & locald30_LDPRR060_lumd145_MASK)

#define locald30_LDPRR060_lumd144_MASK           (0x3FF0000U)
#define locald30_LDPRR060_lumd144_SHIFT          (16U)
/*! lumd144 - lumdat_144 */
#define locald30_LDPRR060_lumd144(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR060_lumd144_SHIFT)) & locald30_LDPRR060_lumd144_MASK)
/*! @} */

/*! @name LDPRR061 - ldprofilereg061 */
/*! @{ */

#define locald30_LDPRR061_lumd147_MASK           (0x3FFU)
#define locald30_LDPRR061_lumd147_SHIFT          (0U)
/*! lumd147 - lumdat_147 */
#define locald30_LDPRR061_lumd147(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR061_lumd147_SHIFT)) & locald30_LDPRR061_lumd147_MASK)

#define locald30_LDPRR061_lumd146_MASK           (0x3FF0000U)
#define locald30_LDPRR061_lumd146_SHIFT          (16U)
/*! lumd146 - lumdat_146 */
#define locald30_LDPRR061_lumd146(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR061_lumd146_SHIFT)) & locald30_LDPRR061_lumd146_MASK)
/*! @} */

/*! @name LDPRR062 - ldprofilereg062 */
/*! @{ */

#define locald30_LDPRR062_lumd149_MASK           (0x3FFU)
#define locald30_LDPRR062_lumd149_SHIFT          (0U)
/*! lumd149 - lumdat_149 */
#define locald30_LDPRR062_lumd149(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR062_lumd149_SHIFT)) & locald30_LDPRR062_lumd149_MASK)

#define locald30_LDPRR062_lumd148_MASK           (0x3FF0000U)
#define locald30_LDPRR062_lumd148_SHIFT          (16U)
/*! lumd148 - lumdat_148 */
#define locald30_LDPRR062_lumd148(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR062_lumd148_SHIFT)) & locald30_LDPRR062_lumd148_MASK)
/*! @} */

/*! @name LDPRR063 - ldprofilereg063 */
/*! @{ */

#define locald30_LDPRR063_lumd151_MASK           (0x3FFU)
#define locald30_LDPRR063_lumd151_SHIFT          (0U)
/*! lumd151 - lumdat_151 */
#define locald30_LDPRR063_lumd151(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR063_lumd151_SHIFT)) & locald30_LDPRR063_lumd151_MASK)

#define locald30_LDPRR063_lumd150_MASK           (0x3FF0000U)
#define locald30_LDPRR063_lumd150_SHIFT          (16U)
/*! lumd150 - lumdat_150 */
#define locald30_LDPRR063_lumd150(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR063_lumd150_SHIFT)) & locald30_LDPRR063_lumd150_MASK)
/*! @} */

/*! @name LDPRR064 - ldprofilereg064 */
/*! @{ */

#define locald30_LDPRR064_lumd153_MASK           (0x3FFU)
#define locald30_LDPRR064_lumd153_SHIFT          (0U)
/*! lumd153 - lumdat_153 */
#define locald30_LDPRR064_lumd153(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR064_lumd153_SHIFT)) & locald30_LDPRR064_lumd153_MASK)

#define locald30_LDPRR064_lumd152_MASK           (0x3FF0000U)
#define locald30_LDPRR064_lumd152_SHIFT          (16U)
/*! lumd152 - lumdat_152 */
#define locald30_LDPRR064_lumd152(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR064_lumd152_SHIFT)) & locald30_LDPRR064_lumd152_MASK)
/*! @} */

/*! @name LDPRR065 - ldprofilereg065 */
/*! @{ */

#define locald30_LDPRR065_lumd155_MASK           (0x3FFU)
#define locald30_LDPRR065_lumd155_SHIFT          (0U)
/*! lumd155 - lumdat_155 */
#define locald30_LDPRR065_lumd155(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR065_lumd155_SHIFT)) & locald30_LDPRR065_lumd155_MASK)

#define locald30_LDPRR065_lumd154_MASK           (0x3FF0000U)
#define locald30_LDPRR065_lumd154_SHIFT          (16U)
/*! lumd154 - lumdat_154 */
#define locald30_LDPRR065_lumd154(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR065_lumd154_SHIFT)) & locald30_LDPRR065_lumd154_MASK)
/*! @} */

/*! @name LDPRR066 - ldprofilereg066 */
/*! @{ */

#define locald30_LDPRR066_lumd157_MASK           (0x3FFU)
#define locald30_LDPRR066_lumd157_SHIFT          (0U)
/*! lumd157 - lumdat_157 */
#define locald30_LDPRR066_lumd157(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR066_lumd157_SHIFT)) & locald30_LDPRR066_lumd157_MASK)

#define locald30_LDPRR066_lumd156_MASK           (0x3FF0000U)
#define locald30_LDPRR066_lumd156_SHIFT          (16U)
/*! lumd156 - lumdat_156 */
#define locald30_LDPRR066_lumd156(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR066_lumd156_SHIFT)) & locald30_LDPRR066_lumd156_MASK)
/*! @} */

/*! @name LDPRR067 - ldprofilereg067 */
/*! @{ */

#define locald30_LDPRR067_lumd159_MASK           (0x3FFU)
#define locald30_LDPRR067_lumd159_SHIFT          (0U)
/*! lumd159 - lumdat_159 */
#define locald30_LDPRR067_lumd159(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR067_lumd159_SHIFT)) & locald30_LDPRR067_lumd159_MASK)

#define locald30_LDPRR067_lumd158_MASK           (0x3FF0000U)
#define locald30_LDPRR067_lumd158_SHIFT          (16U)
/*! lumd158 - lumdat_158 */
#define locald30_LDPRR067_lumd158(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR067_lumd158_SHIFT)) & locald30_LDPRR067_lumd158_MASK)
/*! @} */

/*! @name LDPRR068 - ldprofilereg068 */
/*! @{ */

#define locald30_LDPRR068_lumd161_MASK           (0x3FFU)
#define locald30_LDPRR068_lumd161_SHIFT          (0U)
/*! lumd161 - lumdat_161 */
#define locald30_LDPRR068_lumd161(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR068_lumd161_SHIFT)) & locald30_LDPRR068_lumd161_MASK)

#define locald30_LDPRR068_lumd160_MASK           (0x3FF0000U)
#define locald30_LDPRR068_lumd160_SHIFT          (16U)
/*! lumd160 - lumdat_160 */
#define locald30_LDPRR068_lumd160(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR068_lumd160_SHIFT)) & locald30_LDPRR068_lumd160_MASK)
/*! @} */

/*! @name LDPRR069 - ldprofilereg069 */
/*! @{ */

#define locald30_LDPRR069_lumd163_MASK           (0x3FFU)
#define locald30_LDPRR069_lumd163_SHIFT          (0U)
/*! lumd163 - lumdat_163 */
#define locald30_LDPRR069_lumd163(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR069_lumd163_SHIFT)) & locald30_LDPRR069_lumd163_MASK)

#define locald30_LDPRR069_lumd162_MASK           (0x3FF0000U)
#define locald30_LDPRR069_lumd162_SHIFT          (16U)
/*! lumd162 - lumdat_162 */
#define locald30_LDPRR069_lumd162(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR069_lumd162_SHIFT)) & locald30_LDPRR069_lumd162_MASK)
/*! @} */

/*! @name LDPRR06A - ldprofilereg06a */
/*! @{ */

#define locald30_LDPRR06A_lumd165_MASK           (0x3FFU)
#define locald30_LDPRR06A_lumd165_SHIFT          (0U)
/*! lumd165 - lumdat_165 */
#define locald30_LDPRR06A_lumd165(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR06A_lumd165_SHIFT)) & locald30_LDPRR06A_lumd165_MASK)

#define locald30_LDPRR06A_lumd164_MASK           (0x3FF0000U)
#define locald30_LDPRR06A_lumd164_SHIFT          (16U)
/*! lumd164 - lumdat_164 */
#define locald30_LDPRR06A_lumd164(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR06A_lumd164_SHIFT)) & locald30_LDPRR06A_lumd164_MASK)
/*! @} */

/*! @name LDPRR06B - ldprofilereg06b */
/*! @{ */

#define locald30_LDPRR06B_lumd167_MASK           (0x3FFU)
#define locald30_LDPRR06B_lumd167_SHIFT          (0U)
/*! lumd167 - lumdat_167 */
#define locald30_LDPRR06B_lumd167(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR06B_lumd167_SHIFT)) & locald30_LDPRR06B_lumd167_MASK)

#define locald30_LDPRR06B_lumd166_MASK           (0x3FF0000U)
#define locald30_LDPRR06B_lumd166_SHIFT          (16U)
/*! lumd166 - lumdat_166 */
#define locald30_LDPRR06B_lumd166(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR06B_lumd166_SHIFT)) & locald30_LDPRR06B_lumd166_MASK)
/*! @} */

/*! @name LDPRR06C - ldprofilereg06c */
/*! @{ */

#define locald30_LDPRR06C_lumd169_MASK           (0x3FFU)
#define locald30_LDPRR06C_lumd169_SHIFT          (0U)
/*! lumd169 - lumdat_169 */
#define locald30_LDPRR06C_lumd169(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR06C_lumd169_SHIFT)) & locald30_LDPRR06C_lumd169_MASK)

#define locald30_LDPRR06C_lumd168_MASK           (0x3FF0000U)
#define locald30_LDPRR06C_lumd168_SHIFT          (16U)
/*! lumd168 - lumdat_168 */
#define locald30_LDPRR06C_lumd168(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR06C_lumd168_SHIFT)) & locald30_LDPRR06C_lumd168_MASK)
/*! @} */

/*! @name LDPRR06D - ldprofilereg06d */
/*! @{ */

#define locald30_LDPRR06D_lumd171_MASK           (0x3FFU)
#define locald30_LDPRR06D_lumd171_SHIFT          (0U)
/*! lumd171 - lumdat_171 */
#define locald30_LDPRR06D_lumd171(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR06D_lumd171_SHIFT)) & locald30_LDPRR06D_lumd171_MASK)

#define locald30_LDPRR06D_lumd170_MASK           (0x3FF0000U)
#define locald30_LDPRR06D_lumd170_SHIFT          (16U)
/*! lumd170 - lumdat_170 */
#define locald30_LDPRR06D_lumd170(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR06D_lumd170_SHIFT)) & locald30_LDPRR06D_lumd170_MASK)
/*! @} */

/*! @name LDPRR06E - ldprofilereg06e */
/*! @{ */

#define locald30_LDPRR06E_lumd173_MASK           (0x3FFU)
#define locald30_LDPRR06E_lumd173_SHIFT          (0U)
/*! lumd173 - lumdat_173 */
#define locald30_LDPRR06E_lumd173(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR06E_lumd173_SHIFT)) & locald30_LDPRR06E_lumd173_MASK)

#define locald30_LDPRR06E_lumd172_MASK           (0x3FF0000U)
#define locald30_LDPRR06E_lumd172_SHIFT          (16U)
/*! lumd172 - lumdat_172 */
#define locald30_LDPRR06E_lumd172(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR06E_lumd172_SHIFT)) & locald30_LDPRR06E_lumd172_MASK)
/*! @} */

/*! @name LDPRR06F - ldprofilereg06f */
/*! @{ */

#define locald30_LDPRR06F_lumd175_MASK           (0x3FFU)
#define locald30_LDPRR06F_lumd175_SHIFT          (0U)
/*! lumd175 - lumdat_175 */
#define locald30_LDPRR06F_lumd175(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR06F_lumd175_SHIFT)) & locald30_LDPRR06F_lumd175_MASK)

#define locald30_LDPRR06F_lumd174_MASK           (0x3FF0000U)
#define locald30_LDPRR06F_lumd174_SHIFT          (16U)
/*! lumd174 - lumdat_174 */
#define locald30_LDPRR06F_lumd174(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR06F_lumd174_SHIFT)) & locald30_LDPRR06F_lumd174_MASK)
/*! @} */

/*! @name LDPRR070 - ldprofilereg070 */
/*! @{ */

#define locald30_LDPRR070_lumd177_MASK           (0x3FFU)
#define locald30_LDPRR070_lumd177_SHIFT          (0U)
/*! lumd177 - lumdat_177 */
#define locald30_LDPRR070_lumd177(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR070_lumd177_SHIFT)) & locald30_LDPRR070_lumd177_MASK)

#define locald30_LDPRR070_lumd176_MASK           (0x3FF0000U)
#define locald30_LDPRR070_lumd176_SHIFT          (16U)
/*! lumd176 - lumdat_176 */
#define locald30_LDPRR070_lumd176(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR070_lumd176_SHIFT)) & locald30_LDPRR070_lumd176_MASK)
/*! @} */

/*! @name LDPRR071 - ldprofilereg071 */
/*! @{ */

#define locald30_LDPRR071_lumd179_MASK           (0x3FFU)
#define locald30_LDPRR071_lumd179_SHIFT          (0U)
/*! lumd179 - lumdat_179 */
#define locald30_LDPRR071_lumd179(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR071_lumd179_SHIFT)) & locald30_LDPRR071_lumd179_MASK)

#define locald30_LDPRR071_lumd178_MASK           (0x3FF0000U)
#define locald30_LDPRR071_lumd178_SHIFT          (16U)
/*! lumd178 - lumdat_178 */
#define locald30_LDPRR071_lumd178(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR071_lumd178_SHIFT)) & locald30_LDPRR071_lumd178_MASK)
/*! @} */

/*! @name LDPRR072 - ldprofilereg072 */
/*! @{ */

#define locald30_LDPRR072_lumd181_MASK           (0x3FFU)
#define locald30_LDPRR072_lumd181_SHIFT          (0U)
/*! lumd181 - lumdat_181 */
#define locald30_LDPRR072_lumd181(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR072_lumd181_SHIFT)) & locald30_LDPRR072_lumd181_MASK)

#define locald30_LDPRR072_lumd180_MASK           (0x3FF0000U)
#define locald30_LDPRR072_lumd180_SHIFT          (16U)
/*! lumd180 - lumdat_180 */
#define locald30_LDPRR072_lumd180(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR072_lumd180_SHIFT)) & locald30_LDPRR072_lumd180_MASK)
/*! @} */

/*! @name LDPRR073 - ldprofilereg073 */
/*! @{ */

#define locald30_LDPRR073_lumd183_MASK           (0x3FFU)
#define locald30_LDPRR073_lumd183_SHIFT          (0U)
/*! lumd183 - lumdat_183 */
#define locald30_LDPRR073_lumd183(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR073_lumd183_SHIFT)) & locald30_LDPRR073_lumd183_MASK)

#define locald30_LDPRR073_lumd182_MASK           (0x3FF0000U)
#define locald30_LDPRR073_lumd182_SHIFT          (16U)
/*! lumd182 - lumdat_182 */
#define locald30_LDPRR073_lumd182(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR073_lumd182_SHIFT)) & locald30_LDPRR073_lumd182_MASK)
/*! @} */

/*! @name LDPRR074 - ldprofilereg074 */
/*! @{ */

#define locald30_LDPRR074_lumd185_MASK           (0x3FFU)
#define locald30_LDPRR074_lumd185_SHIFT          (0U)
/*! lumd185 - lumdat_185 */
#define locald30_LDPRR074_lumd185(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR074_lumd185_SHIFT)) & locald30_LDPRR074_lumd185_MASK)

#define locald30_LDPRR074_lumd184_MASK           (0x3FF0000U)
#define locald30_LDPRR074_lumd184_SHIFT          (16U)
/*! lumd184 - lumdat_184 */
#define locald30_LDPRR074_lumd184(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR074_lumd184_SHIFT)) & locald30_LDPRR074_lumd184_MASK)
/*! @} */

/*! @name LDPRR075 - ldprofilereg075 */
/*! @{ */

#define locald30_LDPRR075_lumd187_MASK           (0x3FFU)
#define locald30_LDPRR075_lumd187_SHIFT          (0U)
/*! lumd187 - lumdat_187 */
#define locald30_LDPRR075_lumd187(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR075_lumd187_SHIFT)) & locald30_LDPRR075_lumd187_MASK)

#define locald30_LDPRR075_lumd186_MASK           (0x3FF0000U)
#define locald30_LDPRR075_lumd186_SHIFT          (16U)
/*! lumd186 - lumdat_186 */
#define locald30_LDPRR075_lumd186(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR075_lumd186_SHIFT)) & locald30_LDPRR075_lumd186_MASK)
/*! @} */

/*! @name LDPRR076 - ldprofilereg076 */
/*! @{ */

#define locald30_LDPRR076_lumd189_MASK           (0x3FFU)
#define locald30_LDPRR076_lumd189_SHIFT          (0U)
/*! lumd189 - lumdat_189 */
#define locald30_LDPRR076_lumd189(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR076_lumd189_SHIFT)) & locald30_LDPRR076_lumd189_MASK)

#define locald30_LDPRR076_lumd188_MASK           (0x3FF0000U)
#define locald30_LDPRR076_lumd188_SHIFT          (16U)
/*! lumd188 - lumdat_188 */
#define locald30_LDPRR076_lumd188(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR076_lumd188_SHIFT)) & locald30_LDPRR076_lumd188_MASK)
/*! @} */

/*! @name LDPRR077 - ldprofilereg077 */
/*! @{ */

#define locald30_LDPRR077_lumd191_MASK           (0x3FFU)
#define locald30_LDPRR077_lumd191_SHIFT          (0U)
/*! lumd191 - lumdat_191 */
#define locald30_LDPRR077_lumd191(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR077_lumd191_SHIFT)) & locald30_LDPRR077_lumd191_MASK)

#define locald30_LDPRR077_lumd190_MASK           (0x3FF0000U)
#define locald30_LDPRR077_lumd190_SHIFT          (16U)
/*! lumd190 - lumdat_190 */
#define locald30_LDPRR077_lumd190(x)             (((uint32_t)(((uint32_t)(x)) << locald30_LDPRR077_lumd190_SHIFT)) & locald30_LDPRR077_lumd190_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald30_Register_Masks */


/*!
 * @}
 */ /* end of group locald30_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD30_H_ */

