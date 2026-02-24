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
**         CMSIS Peripheral Access Layer for locald29
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
 * @file PERI_locald29.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald29
 *
 * CMSIS Peripheral Access Layer for locald29
 */

#if !defined(PERI_LOCALD29_H_)
#define PERI_LOCALD29_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald29 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald29_Peripheral_Access_Layer locald29 Peripheral Access Layer
 * @{
 */

/** locald29 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR040;                          /**< ldprofilereg040, offset: 0x0 */
  __IO uint32_t LDPRR041;                          /**< ldprofilereg041, offset: 0x4 */
  __IO uint32_t LDPRR042;                          /**< ldprofilereg042, offset: 0x8 */
  __IO uint32_t LDPRR043;                          /**< ldprofilereg043, offset: 0xC */
  __IO uint32_t LDPRR044;                          /**< ldprofilereg044, offset: 0x10 */
  __IO uint32_t LDPRR045;                          /**< ldprofilereg045, offset: 0x14 */
  __IO uint32_t LDPRR046;                          /**< ldprofilereg046, offset: 0x18 */
  __IO uint32_t LDPRR047;                          /**< ldprofilereg047, offset: 0x1C */
  __IO uint32_t LDPRR048;                          /**< ldprofilereg048, offset: 0x20 */
  __IO uint32_t LDPRR049;                          /**< ldprofilereg049, offset: 0x24 */
  __IO uint32_t LDPRR04A;                          /**< ldprofilereg04a, offset: 0x28 */
  __IO uint32_t LDPRR04B;                          /**< ldprofilereg04b, offset: 0x2C */
  __IO uint32_t LDPRR04C;                          /**< ldprofilereg04c, offset: 0x30 */
  __IO uint32_t LDPRR04D;                          /**< ldprofilereg04d, offset: 0x34 */
  __IO uint32_t LDPRR04E;                          /**< ldprofilereg04e, offset: 0x38 */
  __IO uint32_t LDPRR04F;                          /**< ldprofilereg04f, offset: 0x3C */
  __IO uint32_t LDPRR050;                          /**< ldprofilereg050, offset: 0x40 */
  __IO uint32_t LDPRR051;                          /**< ldprofilereg051, offset: 0x44 */
  __IO uint32_t LDPRR052;                          /**< ldprofilereg052, offset: 0x48 */
  __IO uint32_t LDPRR053;                          /**< ldprofilereg053, offset: 0x4C */
  __IO uint32_t LDPRR054;                          /**< ldprofilereg054, offset: 0x50 */
  __IO uint32_t LDPRR055;                          /**< ldprofilereg055, offset: 0x54 */
  __IO uint32_t LDPRR056;                          /**< ldprofilereg056, offset: 0x58 */
  __IO uint32_t LDPRR057;                          /**< ldprofilereg057, offset: 0x5C */
} locald29_Type;

/* ----------------------------------------------------------------------------
   -- locald29 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald29_Register_Masks locald29 Register Masks
 * @{
 */

/*! @name LDPRR040 - ldprofilereg040 */
/*! @{ */

#define locald29_LDPRR040_lumdat97_MASK          (0x3FFU)
#define locald29_LDPRR040_lumdat97_SHIFT         (0U)
/*! lumdat97 - lumdat_97 */
#define locald29_LDPRR040_lumdat97(x)            (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR040_lumdat97_SHIFT)) & locald29_LDPRR040_lumdat97_MASK)

#define locald29_LDPRR040_lumdat96_MASK          (0x3FF0000U)
#define locald29_LDPRR040_lumdat96_SHIFT         (16U)
/*! lumdat96 - lumdat_96 */
#define locald29_LDPRR040_lumdat96(x)            (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR040_lumdat96_SHIFT)) & locald29_LDPRR040_lumdat96_MASK)
/*! @} */

/*! @name LDPRR041 - ldprofilereg041 */
/*! @{ */

#define locald29_LDPRR041_lumdat99_MASK          (0x3FFU)
#define locald29_LDPRR041_lumdat99_SHIFT         (0U)
/*! lumdat99 - lumdat_99 */
#define locald29_LDPRR041_lumdat99(x)            (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR041_lumdat99_SHIFT)) & locald29_LDPRR041_lumdat99_MASK)

#define locald29_LDPRR041_lumdat98_MASK          (0x3FF0000U)
#define locald29_LDPRR041_lumdat98_SHIFT         (16U)
/*! lumdat98 - lumdat_98 */
#define locald29_LDPRR041_lumdat98(x)            (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR041_lumdat98_SHIFT)) & locald29_LDPRR041_lumdat98_MASK)
/*! @} */

/*! @name LDPRR042 - ldprofilereg042 */
/*! @{ */

#define locald29_LDPRR042_lumd101_MASK           (0x3FFU)
#define locald29_LDPRR042_lumd101_SHIFT          (0U)
/*! lumd101 - lumdat_101 */
#define locald29_LDPRR042_lumd101(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR042_lumd101_SHIFT)) & locald29_LDPRR042_lumd101_MASK)

#define locald29_LDPRR042_lumd100_MASK           (0x3FF0000U)
#define locald29_LDPRR042_lumd100_SHIFT          (16U)
/*! lumd100 - lumdat_100 */
#define locald29_LDPRR042_lumd100(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR042_lumd100_SHIFT)) & locald29_LDPRR042_lumd100_MASK)
/*! @} */

/*! @name LDPRR043 - ldprofilereg043 */
/*! @{ */

#define locald29_LDPRR043_lumd103_MASK           (0x3FFU)
#define locald29_LDPRR043_lumd103_SHIFT          (0U)
/*! lumd103 - lumdat_103 */
#define locald29_LDPRR043_lumd103(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR043_lumd103_SHIFT)) & locald29_LDPRR043_lumd103_MASK)

#define locald29_LDPRR043_lumd102_MASK           (0x3FF0000U)
#define locald29_LDPRR043_lumd102_SHIFT          (16U)
/*! lumd102 - lumdat_102 */
#define locald29_LDPRR043_lumd102(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR043_lumd102_SHIFT)) & locald29_LDPRR043_lumd102_MASK)
/*! @} */

/*! @name LDPRR044 - ldprofilereg044 */
/*! @{ */

#define locald29_LDPRR044_lumd105_MASK           (0x3FFU)
#define locald29_LDPRR044_lumd105_SHIFT          (0U)
/*! lumd105 - lumdat_105 */
#define locald29_LDPRR044_lumd105(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR044_lumd105_SHIFT)) & locald29_LDPRR044_lumd105_MASK)

#define locald29_LDPRR044_lumd104_MASK           (0x3FF0000U)
#define locald29_LDPRR044_lumd104_SHIFT          (16U)
/*! lumd104 - lumdat_104 */
#define locald29_LDPRR044_lumd104(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR044_lumd104_SHIFT)) & locald29_LDPRR044_lumd104_MASK)
/*! @} */

/*! @name LDPRR045 - ldprofilereg045 */
/*! @{ */

#define locald29_LDPRR045_lumd107_MASK           (0x3FFU)
#define locald29_LDPRR045_lumd107_SHIFT          (0U)
/*! lumd107 - lumdat_107 */
#define locald29_LDPRR045_lumd107(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR045_lumd107_SHIFT)) & locald29_LDPRR045_lumd107_MASK)

#define locald29_LDPRR045_lumd106_MASK           (0x3FF0000U)
#define locald29_LDPRR045_lumd106_SHIFT          (16U)
/*! lumd106 - lumdat_106 */
#define locald29_LDPRR045_lumd106(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR045_lumd106_SHIFT)) & locald29_LDPRR045_lumd106_MASK)
/*! @} */

/*! @name LDPRR046 - ldprofilereg046 */
/*! @{ */

#define locald29_LDPRR046_lumd109_MASK           (0x3FFU)
#define locald29_LDPRR046_lumd109_SHIFT          (0U)
/*! lumd109 - lumdat_109 */
#define locald29_LDPRR046_lumd109(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR046_lumd109_SHIFT)) & locald29_LDPRR046_lumd109_MASK)

#define locald29_LDPRR046_lumd108_MASK           (0x3FF0000U)
#define locald29_LDPRR046_lumd108_SHIFT          (16U)
/*! lumd108 - lumdat_108 */
#define locald29_LDPRR046_lumd108(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR046_lumd108_SHIFT)) & locald29_LDPRR046_lumd108_MASK)
/*! @} */

/*! @name LDPRR047 - ldprofilereg047 */
/*! @{ */

#define locald29_LDPRR047_lumd111_MASK           (0x3FFU)
#define locald29_LDPRR047_lumd111_SHIFT          (0U)
/*! lumd111 - lumdat_111 */
#define locald29_LDPRR047_lumd111(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR047_lumd111_SHIFT)) & locald29_LDPRR047_lumd111_MASK)

#define locald29_LDPRR047_lumd110_MASK           (0x3FF0000U)
#define locald29_LDPRR047_lumd110_SHIFT          (16U)
/*! lumd110 - lumdat_110 */
#define locald29_LDPRR047_lumd110(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR047_lumd110_SHIFT)) & locald29_LDPRR047_lumd110_MASK)
/*! @} */

/*! @name LDPRR048 - ldprofilereg048 */
/*! @{ */

#define locald29_LDPRR048_lumd113_MASK           (0x3FFU)
#define locald29_LDPRR048_lumd113_SHIFT          (0U)
/*! lumd113 - lumdat_113 */
#define locald29_LDPRR048_lumd113(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR048_lumd113_SHIFT)) & locald29_LDPRR048_lumd113_MASK)

#define locald29_LDPRR048_lumd112_MASK           (0x3FF0000U)
#define locald29_LDPRR048_lumd112_SHIFT          (16U)
/*! lumd112 - lumdat_112 */
#define locald29_LDPRR048_lumd112(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR048_lumd112_SHIFT)) & locald29_LDPRR048_lumd112_MASK)
/*! @} */

/*! @name LDPRR049 - ldprofilereg049 */
/*! @{ */

#define locald29_LDPRR049_lumd115_MASK           (0x3FFU)
#define locald29_LDPRR049_lumd115_SHIFT          (0U)
/*! lumd115 - lumdat_115 */
#define locald29_LDPRR049_lumd115(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR049_lumd115_SHIFT)) & locald29_LDPRR049_lumd115_MASK)

#define locald29_LDPRR049_lumd114_MASK           (0x3FF0000U)
#define locald29_LDPRR049_lumd114_SHIFT          (16U)
/*! lumd114 - lumdat_114 */
#define locald29_LDPRR049_lumd114(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR049_lumd114_SHIFT)) & locald29_LDPRR049_lumd114_MASK)
/*! @} */

/*! @name LDPRR04A - ldprofilereg04a */
/*! @{ */

#define locald29_LDPRR04A_lumd117_MASK           (0x3FFU)
#define locald29_LDPRR04A_lumd117_SHIFT          (0U)
/*! lumd117 - lumdat_117 */
#define locald29_LDPRR04A_lumd117(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR04A_lumd117_SHIFT)) & locald29_LDPRR04A_lumd117_MASK)

#define locald29_LDPRR04A_lumd116_MASK           (0x3FF0000U)
#define locald29_LDPRR04A_lumd116_SHIFT          (16U)
/*! lumd116 - lumdat_116 */
#define locald29_LDPRR04A_lumd116(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR04A_lumd116_SHIFT)) & locald29_LDPRR04A_lumd116_MASK)
/*! @} */

/*! @name LDPRR04B - ldprofilereg04b */
/*! @{ */

#define locald29_LDPRR04B_lumd119_MASK           (0x3FFU)
#define locald29_LDPRR04B_lumd119_SHIFT          (0U)
/*! lumd119 - lumdat_119 */
#define locald29_LDPRR04B_lumd119(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR04B_lumd119_SHIFT)) & locald29_LDPRR04B_lumd119_MASK)

#define locald29_LDPRR04B_lumd118_MASK           (0x3FF0000U)
#define locald29_LDPRR04B_lumd118_SHIFT          (16U)
/*! lumd118 - lumdat_118 */
#define locald29_LDPRR04B_lumd118(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR04B_lumd118_SHIFT)) & locald29_LDPRR04B_lumd118_MASK)
/*! @} */

/*! @name LDPRR04C - ldprofilereg04c */
/*! @{ */

#define locald29_LDPRR04C_lumd121_MASK           (0x3FFU)
#define locald29_LDPRR04C_lumd121_SHIFT          (0U)
/*! lumd121 - lumdat_121 */
#define locald29_LDPRR04C_lumd121(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR04C_lumd121_SHIFT)) & locald29_LDPRR04C_lumd121_MASK)

#define locald29_LDPRR04C_lumd120_MASK           (0x3FF0000U)
#define locald29_LDPRR04C_lumd120_SHIFT          (16U)
/*! lumd120 - lumdat_120 */
#define locald29_LDPRR04C_lumd120(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR04C_lumd120_SHIFT)) & locald29_LDPRR04C_lumd120_MASK)
/*! @} */

/*! @name LDPRR04D - ldprofilereg04d */
/*! @{ */

#define locald29_LDPRR04D_lumd123_MASK           (0x3FFU)
#define locald29_LDPRR04D_lumd123_SHIFT          (0U)
/*! lumd123 - lumdat_123 */
#define locald29_LDPRR04D_lumd123(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR04D_lumd123_SHIFT)) & locald29_LDPRR04D_lumd123_MASK)

#define locald29_LDPRR04D_lumd122_MASK           (0x3FF0000U)
#define locald29_LDPRR04D_lumd122_SHIFT          (16U)
/*! lumd122 - lumdat_122 */
#define locald29_LDPRR04D_lumd122(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR04D_lumd122_SHIFT)) & locald29_LDPRR04D_lumd122_MASK)
/*! @} */

/*! @name LDPRR04E - ldprofilereg04e */
/*! @{ */

#define locald29_LDPRR04E_lumd125_MASK           (0x3FFU)
#define locald29_LDPRR04E_lumd125_SHIFT          (0U)
/*! lumd125 - lumdat_125 */
#define locald29_LDPRR04E_lumd125(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR04E_lumd125_SHIFT)) & locald29_LDPRR04E_lumd125_MASK)

#define locald29_LDPRR04E_lumd124_MASK           (0x3FF0000U)
#define locald29_LDPRR04E_lumd124_SHIFT          (16U)
/*! lumd124 - lumdat_124 */
#define locald29_LDPRR04E_lumd124(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR04E_lumd124_SHIFT)) & locald29_LDPRR04E_lumd124_MASK)
/*! @} */

/*! @name LDPRR04F - ldprofilereg04f */
/*! @{ */

#define locald29_LDPRR04F_lumd127_MASK           (0x3FFU)
#define locald29_LDPRR04F_lumd127_SHIFT          (0U)
/*! lumd127 - lumdat_127 */
#define locald29_LDPRR04F_lumd127(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR04F_lumd127_SHIFT)) & locald29_LDPRR04F_lumd127_MASK)

#define locald29_LDPRR04F_lumd126_MASK           (0x3FF0000U)
#define locald29_LDPRR04F_lumd126_SHIFT          (16U)
/*! lumd126 - lumdat_126 */
#define locald29_LDPRR04F_lumd126(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR04F_lumd126_SHIFT)) & locald29_LDPRR04F_lumd126_MASK)
/*! @} */

/*! @name LDPRR050 - ldprofilereg050 */
/*! @{ */

#define locald29_LDPRR050_lumd129_MASK           (0x3FFU)
#define locald29_LDPRR050_lumd129_SHIFT          (0U)
/*! lumd129 - lumdat_129 */
#define locald29_LDPRR050_lumd129(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR050_lumd129_SHIFT)) & locald29_LDPRR050_lumd129_MASK)

#define locald29_LDPRR050_lumd128_MASK           (0x3FF0000U)
#define locald29_LDPRR050_lumd128_SHIFT          (16U)
/*! lumd128 - lumdat_128 */
#define locald29_LDPRR050_lumd128(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR050_lumd128_SHIFT)) & locald29_LDPRR050_lumd128_MASK)
/*! @} */

/*! @name LDPRR051 - ldprofilereg051 */
/*! @{ */

#define locald29_LDPRR051_lumd131_MASK           (0x3FFU)
#define locald29_LDPRR051_lumd131_SHIFT          (0U)
/*! lumd131 - lumdat_131 */
#define locald29_LDPRR051_lumd131(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR051_lumd131_SHIFT)) & locald29_LDPRR051_lumd131_MASK)

#define locald29_LDPRR051_lumd130_MASK           (0x3FF0000U)
#define locald29_LDPRR051_lumd130_SHIFT          (16U)
/*! lumd130 - lumdat_130 */
#define locald29_LDPRR051_lumd130(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR051_lumd130_SHIFT)) & locald29_LDPRR051_lumd130_MASK)
/*! @} */

/*! @name LDPRR052 - ldprofilereg052 */
/*! @{ */

#define locald29_LDPRR052_lumd133_MASK           (0x3FFU)
#define locald29_LDPRR052_lumd133_SHIFT          (0U)
/*! lumd133 - lumdat_133 */
#define locald29_LDPRR052_lumd133(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR052_lumd133_SHIFT)) & locald29_LDPRR052_lumd133_MASK)

#define locald29_LDPRR052_lumd132_MASK           (0x3FF0000U)
#define locald29_LDPRR052_lumd132_SHIFT          (16U)
/*! lumd132 - lumdat_132 */
#define locald29_LDPRR052_lumd132(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR052_lumd132_SHIFT)) & locald29_LDPRR052_lumd132_MASK)
/*! @} */

/*! @name LDPRR053 - ldprofilereg053 */
/*! @{ */

#define locald29_LDPRR053_lumd135_MASK           (0x3FFU)
#define locald29_LDPRR053_lumd135_SHIFT          (0U)
/*! lumd135 - lumdat_135 */
#define locald29_LDPRR053_lumd135(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR053_lumd135_SHIFT)) & locald29_LDPRR053_lumd135_MASK)

#define locald29_LDPRR053_lumd134_MASK           (0x3FF0000U)
#define locald29_LDPRR053_lumd134_SHIFT          (16U)
/*! lumd134 - lumdat_134 */
#define locald29_LDPRR053_lumd134(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR053_lumd134_SHIFT)) & locald29_LDPRR053_lumd134_MASK)
/*! @} */

/*! @name LDPRR054 - ldprofilereg054 */
/*! @{ */

#define locald29_LDPRR054_lumd137_MASK           (0x3FFU)
#define locald29_LDPRR054_lumd137_SHIFT          (0U)
/*! lumd137 - lumdat_137 */
#define locald29_LDPRR054_lumd137(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR054_lumd137_SHIFT)) & locald29_LDPRR054_lumd137_MASK)

#define locald29_LDPRR054_lumd136_MASK           (0x3FF0000U)
#define locald29_LDPRR054_lumd136_SHIFT          (16U)
/*! lumd136 - lumdat_136 */
#define locald29_LDPRR054_lumd136(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR054_lumd136_SHIFT)) & locald29_LDPRR054_lumd136_MASK)
/*! @} */

/*! @name LDPRR055 - ldprofilereg055 */
/*! @{ */

#define locald29_LDPRR055_lumd139_MASK           (0x3FFU)
#define locald29_LDPRR055_lumd139_SHIFT          (0U)
/*! lumd139 - lumdat_139 */
#define locald29_LDPRR055_lumd139(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR055_lumd139_SHIFT)) & locald29_LDPRR055_lumd139_MASK)

#define locald29_LDPRR055_lumd138_MASK           (0x3FF0000U)
#define locald29_LDPRR055_lumd138_SHIFT          (16U)
/*! lumd138 - lumdat_138 */
#define locald29_LDPRR055_lumd138(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR055_lumd138_SHIFT)) & locald29_LDPRR055_lumd138_MASK)
/*! @} */

/*! @name LDPRR056 - ldprofilereg056 */
/*! @{ */

#define locald29_LDPRR056_lumd141_MASK           (0x3FFU)
#define locald29_LDPRR056_lumd141_SHIFT          (0U)
/*! lumd141 - lumdat_141 */
#define locald29_LDPRR056_lumd141(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR056_lumd141_SHIFT)) & locald29_LDPRR056_lumd141_MASK)

#define locald29_LDPRR056_lumd140_MASK           (0x3FF0000U)
#define locald29_LDPRR056_lumd140_SHIFT          (16U)
/*! lumd140 - lumdat_140 */
#define locald29_LDPRR056_lumd140(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR056_lumd140_SHIFT)) & locald29_LDPRR056_lumd140_MASK)
/*! @} */

/*! @name LDPRR057 - ldprofilereg057 */
/*! @{ */

#define locald29_LDPRR057_lumd143_MASK           (0x3FFU)
#define locald29_LDPRR057_lumd143_SHIFT          (0U)
/*! lumd143 - lumdat_143 */
#define locald29_LDPRR057_lumd143(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR057_lumd143_SHIFT)) & locald29_LDPRR057_lumd143_MASK)

#define locald29_LDPRR057_lumd142_MASK           (0x3FF0000U)
#define locald29_LDPRR057_lumd142_SHIFT          (16U)
/*! lumd142 - lumdat_142 */
#define locald29_LDPRR057_lumd142(x)             (((uint32_t)(((uint32_t)(x)) << locald29_LDPRR057_lumd142_SHIFT)) & locald29_LDPRR057_lumd142_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald29_Register_Masks */


/*!
 * @}
 */ /* end of group locald29_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD29_H_ */

