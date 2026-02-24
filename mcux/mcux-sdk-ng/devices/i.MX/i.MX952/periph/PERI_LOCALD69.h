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
**         CMSIS Peripheral Access Layer for locald69
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
 * @file PERI_locald69.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald69
 *
 * CMSIS Peripheral Access Layer for locald69
 */

#if !defined(PERI_LOCALD69_H_)
#define PERI_LOCALD69_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald69 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald69_Peripheral_Access_Layer locald69 Peripheral Access Layer
 * @{
 */

/** locald69 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR540;                          /**< ldprofilereg540, offset: 0x0 */
  __IO uint32_t LDPRR541;                          /**< ldprofilereg541, offset: 0x4 */
  __IO uint32_t LDPRR542;                          /**< ldprofilereg542, offset: 0x8 */
  __IO uint32_t LDPRR543;                          /**< ldprofilereg543, offset: 0xC */
  __IO uint32_t LDPRR544;                          /**< ldprofilereg544, offset: 0x10 */
  __IO uint32_t LDPRR545;                          /**< ldprofilereg545, offset: 0x14 */
  __IO uint32_t LDPRR546;                          /**< ldprofilereg546, offset: 0x18 */
  __IO uint32_t LDPRR547;                          /**< ldprofilereg547, offset: 0x1C */
  __IO uint32_t LDPRR548;                          /**< ldprofilereg548, offset: 0x20 */
  __IO uint32_t LDPRR549;                          /**< ldprofilereg549, offset: 0x24 */
  __IO uint32_t LDPRR54A;                          /**< ldprofilereg54a, offset: 0x28 */
  __IO uint32_t LDPRR54B;                          /**< ldprofilereg54b, offset: 0x2C */
  __IO uint32_t LDPRR54C;                          /**< ldprofilereg54c, offset: 0x30 */
  __IO uint32_t LDPRR54D;                          /**< ldprofilereg54d, offset: 0x34 */
  __IO uint32_t LDPRR54E;                          /**< ldprofilereg54e, offset: 0x38 */
  __IO uint32_t LDPRR54F;                          /**< ldprofilereg54f, offset: 0x3C */
  __IO uint32_t LDPRR550;                          /**< ldprofilereg550, offset: 0x40 */
  __IO uint32_t LDPRR551;                          /**< ldprofilereg551, offset: 0x44 */
  __IO uint32_t LDPRR552;                          /**< ldprofilereg552, offset: 0x48 */
  __IO uint32_t LDPRR553;                          /**< ldprofilereg553, offset: 0x4C */
  __IO uint32_t LDPRR554;                          /**< ldprofilereg554, offset: 0x50 */
  __IO uint32_t LDPRR555;                          /**< ldprofilereg555, offset: 0x54 */
  __IO uint32_t LDPRR556;                          /**< ldprofilereg556, offset: 0x58 */
  __IO uint32_t LDPRR557;                          /**< ldprofilereg557, offset: 0x5C */
} locald69_Type;

/* ----------------------------------------------------------------------------
   -- locald69 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald69_Register_Masks locald69 Register Masks
 * @{
 */

/*! @name LDPRR540 - ldprofilereg540 */
/*! @{ */

#define locald69_LDPRR540_lumd2017_MASK          (0x3FFU)
#define locald69_LDPRR540_lumd2017_SHIFT         (0U)
/*! lumd2017 - lumdat_2017 */
#define locald69_LDPRR540_lumd2017(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR540_lumd2017_SHIFT)) & locald69_LDPRR540_lumd2017_MASK)

#define locald69_LDPRR540_lumd2016_MASK          (0x3FF0000U)
#define locald69_LDPRR540_lumd2016_SHIFT         (16U)
/*! lumd2016 - lumdat_2016 */
#define locald69_LDPRR540_lumd2016(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR540_lumd2016_SHIFT)) & locald69_LDPRR540_lumd2016_MASK)
/*! @} */

/*! @name LDPRR541 - ldprofilereg541 */
/*! @{ */

#define locald69_LDPRR541_lumd2019_MASK          (0x3FFU)
#define locald69_LDPRR541_lumd2019_SHIFT         (0U)
/*! lumd2019 - lumdat_2019 */
#define locald69_LDPRR541_lumd2019(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR541_lumd2019_SHIFT)) & locald69_LDPRR541_lumd2019_MASK)

#define locald69_LDPRR541_lumd2018_MASK          (0x3FF0000U)
#define locald69_LDPRR541_lumd2018_SHIFT         (16U)
/*! lumd2018 - lumdat_2018 */
#define locald69_LDPRR541_lumd2018(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR541_lumd2018_SHIFT)) & locald69_LDPRR541_lumd2018_MASK)
/*! @} */

/*! @name LDPRR542 - ldprofilereg542 */
/*! @{ */

#define locald69_LDPRR542_lumd2021_MASK          (0x3FFU)
#define locald69_LDPRR542_lumd2021_SHIFT         (0U)
/*! lumd2021 - lumdat_2021 */
#define locald69_LDPRR542_lumd2021(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR542_lumd2021_SHIFT)) & locald69_LDPRR542_lumd2021_MASK)

#define locald69_LDPRR542_lumd2020_MASK          (0x3FF0000U)
#define locald69_LDPRR542_lumd2020_SHIFT         (16U)
/*! lumd2020 - lumdat_2020 */
#define locald69_LDPRR542_lumd2020(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR542_lumd2020_SHIFT)) & locald69_LDPRR542_lumd2020_MASK)
/*! @} */

/*! @name LDPRR543 - ldprofilereg543 */
/*! @{ */

#define locald69_LDPRR543_lumd2023_MASK          (0x3FFU)
#define locald69_LDPRR543_lumd2023_SHIFT         (0U)
/*! lumd2023 - lumdat_2023 */
#define locald69_LDPRR543_lumd2023(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR543_lumd2023_SHIFT)) & locald69_LDPRR543_lumd2023_MASK)

#define locald69_LDPRR543_lumd2022_MASK          (0x3FF0000U)
#define locald69_LDPRR543_lumd2022_SHIFT         (16U)
/*! lumd2022 - lumdat_2022 */
#define locald69_LDPRR543_lumd2022(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR543_lumd2022_SHIFT)) & locald69_LDPRR543_lumd2022_MASK)
/*! @} */

/*! @name LDPRR544 - ldprofilereg544 */
/*! @{ */

#define locald69_LDPRR544_lumd2025_MASK          (0x3FFU)
#define locald69_LDPRR544_lumd2025_SHIFT         (0U)
/*! lumd2025 - lumdat_2025 */
#define locald69_LDPRR544_lumd2025(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR544_lumd2025_SHIFT)) & locald69_LDPRR544_lumd2025_MASK)

#define locald69_LDPRR544_lumd2024_MASK          (0x3FF0000U)
#define locald69_LDPRR544_lumd2024_SHIFT         (16U)
/*! lumd2024 - lumdat_2024 */
#define locald69_LDPRR544_lumd2024(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR544_lumd2024_SHIFT)) & locald69_LDPRR544_lumd2024_MASK)
/*! @} */

/*! @name LDPRR545 - ldprofilereg545 */
/*! @{ */

#define locald69_LDPRR545_lumd2027_MASK          (0x3FFU)
#define locald69_LDPRR545_lumd2027_SHIFT         (0U)
/*! lumd2027 - lumdat_2027 */
#define locald69_LDPRR545_lumd2027(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR545_lumd2027_SHIFT)) & locald69_LDPRR545_lumd2027_MASK)

#define locald69_LDPRR545_lumd2026_MASK          (0x3FF0000U)
#define locald69_LDPRR545_lumd2026_SHIFT         (16U)
/*! lumd2026 - lumdat_2026 */
#define locald69_LDPRR545_lumd2026(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR545_lumd2026_SHIFT)) & locald69_LDPRR545_lumd2026_MASK)
/*! @} */

/*! @name LDPRR546 - ldprofilereg546 */
/*! @{ */

#define locald69_LDPRR546_lumd2029_MASK          (0x3FFU)
#define locald69_LDPRR546_lumd2029_SHIFT         (0U)
/*! lumd2029 - lumdat_2029 */
#define locald69_LDPRR546_lumd2029(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR546_lumd2029_SHIFT)) & locald69_LDPRR546_lumd2029_MASK)

#define locald69_LDPRR546_lumd2028_MASK          (0x3FF0000U)
#define locald69_LDPRR546_lumd2028_SHIFT         (16U)
/*! lumd2028 - lumdat_2028 */
#define locald69_LDPRR546_lumd2028(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR546_lumd2028_SHIFT)) & locald69_LDPRR546_lumd2028_MASK)
/*! @} */

/*! @name LDPRR547 - ldprofilereg547 */
/*! @{ */

#define locald69_LDPRR547_lumd2031_MASK          (0x3FFU)
#define locald69_LDPRR547_lumd2031_SHIFT         (0U)
/*! lumd2031 - lumdat_2031 */
#define locald69_LDPRR547_lumd2031(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR547_lumd2031_SHIFT)) & locald69_LDPRR547_lumd2031_MASK)

#define locald69_LDPRR547_lumd2030_MASK          (0x3FF0000U)
#define locald69_LDPRR547_lumd2030_SHIFT         (16U)
/*! lumd2030 - lumdat_2030 */
#define locald69_LDPRR547_lumd2030(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR547_lumd2030_SHIFT)) & locald69_LDPRR547_lumd2030_MASK)
/*! @} */

/*! @name LDPRR548 - ldprofilereg548 */
/*! @{ */

#define locald69_LDPRR548_lumd2033_MASK          (0x3FFU)
#define locald69_LDPRR548_lumd2033_SHIFT         (0U)
/*! lumd2033 - lumdat_2033 */
#define locald69_LDPRR548_lumd2033(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR548_lumd2033_SHIFT)) & locald69_LDPRR548_lumd2033_MASK)

#define locald69_LDPRR548_lumd2032_MASK          (0x3FF0000U)
#define locald69_LDPRR548_lumd2032_SHIFT         (16U)
/*! lumd2032 - lumdat_2032 */
#define locald69_LDPRR548_lumd2032(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR548_lumd2032_SHIFT)) & locald69_LDPRR548_lumd2032_MASK)
/*! @} */

/*! @name LDPRR549 - ldprofilereg549 */
/*! @{ */

#define locald69_LDPRR549_lumd2035_MASK          (0x3FFU)
#define locald69_LDPRR549_lumd2035_SHIFT         (0U)
/*! lumd2035 - lumdat_2035 */
#define locald69_LDPRR549_lumd2035(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR549_lumd2035_SHIFT)) & locald69_LDPRR549_lumd2035_MASK)

#define locald69_LDPRR549_lumd2034_MASK          (0x3FF0000U)
#define locald69_LDPRR549_lumd2034_SHIFT         (16U)
/*! lumd2034 - lumdat_2034 */
#define locald69_LDPRR549_lumd2034(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR549_lumd2034_SHIFT)) & locald69_LDPRR549_lumd2034_MASK)
/*! @} */

/*! @name LDPRR54A - ldprofilereg54a */
/*! @{ */

#define locald69_LDPRR54A_lumd2037_MASK          (0x3FFU)
#define locald69_LDPRR54A_lumd2037_SHIFT         (0U)
/*! lumd2037 - lumdat_2037 */
#define locald69_LDPRR54A_lumd2037(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR54A_lumd2037_SHIFT)) & locald69_LDPRR54A_lumd2037_MASK)

#define locald69_LDPRR54A_lumd2036_MASK          (0x3FF0000U)
#define locald69_LDPRR54A_lumd2036_SHIFT         (16U)
/*! lumd2036 - lumdat_2036 */
#define locald69_LDPRR54A_lumd2036(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR54A_lumd2036_SHIFT)) & locald69_LDPRR54A_lumd2036_MASK)
/*! @} */

/*! @name LDPRR54B - ldprofilereg54b */
/*! @{ */

#define locald69_LDPRR54B_lumd2039_MASK          (0x3FFU)
#define locald69_LDPRR54B_lumd2039_SHIFT         (0U)
/*! lumd2039 - lumdat_2039 */
#define locald69_LDPRR54B_lumd2039(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR54B_lumd2039_SHIFT)) & locald69_LDPRR54B_lumd2039_MASK)

#define locald69_LDPRR54B_lumd2038_MASK          (0x3FF0000U)
#define locald69_LDPRR54B_lumd2038_SHIFT         (16U)
/*! lumd2038 - lumdat_2038 */
#define locald69_LDPRR54B_lumd2038(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR54B_lumd2038_SHIFT)) & locald69_LDPRR54B_lumd2038_MASK)
/*! @} */

/*! @name LDPRR54C - ldprofilereg54c */
/*! @{ */

#define locald69_LDPRR54C_lumd2041_MASK          (0x3FFU)
#define locald69_LDPRR54C_lumd2041_SHIFT         (0U)
/*! lumd2041 - lumdat_2041 */
#define locald69_LDPRR54C_lumd2041(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR54C_lumd2041_SHIFT)) & locald69_LDPRR54C_lumd2041_MASK)

#define locald69_LDPRR54C_lumd2040_MASK          (0x3FF0000U)
#define locald69_LDPRR54C_lumd2040_SHIFT         (16U)
/*! lumd2040 - lumdat_2040 */
#define locald69_LDPRR54C_lumd2040(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR54C_lumd2040_SHIFT)) & locald69_LDPRR54C_lumd2040_MASK)
/*! @} */

/*! @name LDPRR54D - ldprofilereg54d */
/*! @{ */

#define locald69_LDPRR54D_lumd2043_MASK          (0x3FFU)
#define locald69_LDPRR54D_lumd2043_SHIFT         (0U)
/*! lumd2043 - lumdat_2043 */
#define locald69_LDPRR54D_lumd2043(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR54D_lumd2043_SHIFT)) & locald69_LDPRR54D_lumd2043_MASK)

#define locald69_LDPRR54D_lumd2042_MASK          (0x3FF0000U)
#define locald69_LDPRR54D_lumd2042_SHIFT         (16U)
/*! lumd2042 - lumdat_2042 */
#define locald69_LDPRR54D_lumd2042(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR54D_lumd2042_SHIFT)) & locald69_LDPRR54D_lumd2042_MASK)
/*! @} */

/*! @name LDPRR54E - ldprofilereg54e */
/*! @{ */

#define locald69_LDPRR54E_lumd2045_MASK          (0x3FFU)
#define locald69_LDPRR54E_lumd2045_SHIFT         (0U)
/*! lumd2045 - lumdat_2045 */
#define locald69_LDPRR54E_lumd2045(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR54E_lumd2045_SHIFT)) & locald69_LDPRR54E_lumd2045_MASK)

#define locald69_LDPRR54E_lumd2044_MASK          (0x3FF0000U)
#define locald69_LDPRR54E_lumd2044_SHIFT         (16U)
/*! lumd2044 - lumdat_2044 */
#define locald69_LDPRR54E_lumd2044(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR54E_lumd2044_SHIFT)) & locald69_LDPRR54E_lumd2044_MASK)
/*! @} */

/*! @name LDPRR54F - ldprofilereg54f */
/*! @{ */

#define locald69_LDPRR54F_lumd2047_MASK          (0x3FFU)
#define locald69_LDPRR54F_lumd2047_SHIFT         (0U)
/*! lumd2047 - lumdat_2047 */
#define locald69_LDPRR54F_lumd2047(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR54F_lumd2047_SHIFT)) & locald69_LDPRR54F_lumd2047_MASK)

#define locald69_LDPRR54F_lumd2046_MASK          (0x3FF0000U)
#define locald69_LDPRR54F_lumd2046_SHIFT         (16U)
/*! lumd2046 - lumdat_2046 */
#define locald69_LDPRR54F_lumd2046(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR54F_lumd2046_SHIFT)) & locald69_LDPRR54F_lumd2046_MASK)
/*! @} */

/*! @name LDPRR550 - ldprofilereg550 */
/*! @{ */

#define locald69_LDPRR550_lumd2049_MASK          (0x3FFU)
#define locald69_LDPRR550_lumd2049_SHIFT         (0U)
/*! lumd2049 - lumdat_2049 */
#define locald69_LDPRR550_lumd2049(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR550_lumd2049_SHIFT)) & locald69_LDPRR550_lumd2049_MASK)

#define locald69_LDPRR550_lumd2048_MASK          (0x3FF0000U)
#define locald69_LDPRR550_lumd2048_SHIFT         (16U)
/*! lumd2048 - lumdat_2048 */
#define locald69_LDPRR550_lumd2048(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR550_lumd2048_SHIFT)) & locald69_LDPRR550_lumd2048_MASK)
/*! @} */

/*! @name LDPRR551 - ldprofilereg551 */
/*! @{ */

#define locald69_LDPRR551_lumd2051_MASK          (0x3FFU)
#define locald69_LDPRR551_lumd2051_SHIFT         (0U)
/*! lumd2051 - lumdat_2051 */
#define locald69_LDPRR551_lumd2051(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR551_lumd2051_SHIFT)) & locald69_LDPRR551_lumd2051_MASK)

#define locald69_LDPRR551_lumd2050_MASK          (0x3FF0000U)
#define locald69_LDPRR551_lumd2050_SHIFT         (16U)
/*! lumd2050 - lumdat_2050 */
#define locald69_LDPRR551_lumd2050(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR551_lumd2050_SHIFT)) & locald69_LDPRR551_lumd2050_MASK)
/*! @} */

/*! @name LDPRR552 - ldprofilereg552 */
/*! @{ */

#define locald69_LDPRR552_lumd2053_MASK          (0x3FFU)
#define locald69_LDPRR552_lumd2053_SHIFT         (0U)
/*! lumd2053 - lumdat_2053 */
#define locald69_LDPRR552_lumd2053(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR552_lumd2053_SHIFT)) & locald69_LDPRR552_lumd2053_MASK)

#define locald69_LDPRR552_lumd2052_MASK          (0x3FF0000U)
#define locald69_LDPRR552_lumd2052_SHIFT         (16U)
/*! lumd2052 - lumdat_2052 */
#define locald69_LDPRR552_lumd2052(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR552_lumd2052_SHIFT)) & locald69_LDPRR552_lumd2052_MASK)
/*! @} */

/*! @name LDPRR553 - ldprofilereg553 */
/*! @{ */

#define locald69_LDPRR553_lumd2055_MASK          (0x3FFU)
#define locald69_LDPRR553_lumd2055_SHIFT         (0U)
/*! lumd2055 - lumdat_2055 */
#define locald69_LDPRR553_lumd2055(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR553_lumd2055_SHIFT)) & locald69_LDPRR553_lumd2055_MASK)

#define locald69_LDPRR553_lumd2054_MASK          (0x3FF0000U)
#define locald69_LDPRR553_lumd2054_SHIFT         (16U)
/*! lumd2054 - lumdat_2054 */
#define locald69_LDPRR553_lumd2054(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR553_lumd2054_SHIFT)) & locald69_LDPRR553_lumd2054_MASK)
/*! @} */

/*! @name LDPRR554 - ldprofilereg554 */
/*! @{ */

#define locald69_LDPRR554_lumd2057_MASK          (0x3FFU)
#define locald69_LDPRR554_lumd2057_SHIFT         (0U)
/*! lumd2057 - lumdat_2057 */
#define locald69_LDPRR554_lumd2057(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR554_lumd2057_SHIFT)) & locald69_LDPRR554_lumd2057_MASK)

#define locald69_LDPRR554_lumd2056_MASK          (0x3FF0000U)
#define locald69_LDPRR554_lumd2056_SHIFT         (16U)
/*! lumd2056 - lumdat_2056 */
#define locald69_LDPRR554_lumd2056(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR554_lumd2056_SHIFT)) & locald69_LDPRR554_lumd2056_MASK)
/*! @} */

/*! @name LDPRR555 - ldprofilereg555 */
/*! @{ */

#define locald69_LDPRR555_lumd2059_MASK          (0x3FFU)
#define locald69_LDPRR555_lumd2059_SHIFT         (0U)
/*! lumd2059 - lumdat_2059 */
#define locald69_LDPRR555_lumd2059(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR555_lumd2059_SHIFT)) & locald69_LDPRR555_lumd2059_MASK)

#define locald69_LDPRR555_lumd2058_MASK          (0x3FF0000U)
#define locald69_LDPRR555_lumd2058_SHIFT         (16U)
/*! lumd2058 - lumdat_2058 */
#define locald69_LDPRR555_lumd2058(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR555_lumd2058_SHIFT)) & locald69_LDPRR555_lumd2058_MASK)
/*! @} */

/*! @name LDPRR556 - ldprofilereg556 */
/*! @{ */

#define locald69_LDPRR556_lumd2061_MASK          (0x3FFU)
#define locald69_LDPRR556_lumd2061_SHIFT         (0U)
/*! lumd2061 - lumdat_2061 */
#define locald69_LDPRR556_lumd2061(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR556_lumd2061_SHIFT)) & locald69_LDPRR556_lumd2061_MASK)

#define locald69_LDPRR556_lumd2060_MASK          (0x3FF0000U)
#define locald69_LDPRR556_lumd2060_SHIFT         (16U)
/*! lumd2060 - lumdat_2060 */
#define locald69_LDPRR556_lumd2060(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR556_lumd2060_SHIFT)) & locald69_LDPRR556_lumd2060_MASK)
/*! @} */

/*! @name LDPRR557 - ldprofilereg557 */
/*! @{ */

#define locald69_LDPRR557_lumd2063_MASK          (0x3FFU)
#define locald69_LDPRR557_lumd2063_SHIFT         (0U)
/*! lumd2063 - lumdat_2063 */
#define locald69_LDPRR557_lumd2063(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR557_lumd2063_SHIFT)) & locald69_LDPRR557_lumd2063_MASK)

#define locald69_LDPRR557_lumd2062_MASK          (0x3FF0000U)
#define locald69_LDPRR557_lumd2062_SHIFT         (16U)
/*! lumd2062 - lumdat_2062 */
#define locald69_LDPRR557_lumd2062(x)            (((uint32_t)(((uint32_t)(x)) << locald69_LDPRR557_lumd2062_SHIFT)) & locald69_LDPRR557_lumd2062_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald69_Register_Masks */


/*!
 * @}
 */ /* end of group locald69_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD69_H_ */

