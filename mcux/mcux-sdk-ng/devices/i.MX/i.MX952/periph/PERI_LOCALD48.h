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
**         CMSIS Peripheral Access Layer for locald48
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
 * @file PERI_locald48.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald48
 *
 * CMSIS Peripheral Access Layer for locald48
 */

#if !defined(PERI_LOCALD48_H_)
#define PERI_LOCALD48_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald48 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald48_Peripheral_Access_Layer locald48 Peripheral Access Layer
 * @{
 */

/** locald48 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR2A0;                          /**< ldprofilereg2a0, offset: 0x0 */
  __IO uint32_t LDPRR2A1;                          /**< ldprofilereg2a1, offset: 0x4 */
  __IO uint32_t LDPRR2A2;                          /**< ldprofilereg2a2, offset: 0x8 */
  __IO uint32_t LDPRR2A3;                          /**< ldprofilereg2a3, offset: 0xC */
  __IO uint32_t LDPRR2A4;                          /**< ldprofilereg2a4, offset: 0x10 */
  __IO uint32_t LDPRR2A5;                          /**< ldprofilereg2a5, offset: 0x14 */
  __IO uint32_t LDPRR2A6;                          /**< ldprofilereg2a6, offset: 0x18 */
  __IO uint32_t LDPRR2A7;                          /**< ldprofilereg2a7, offset: 0x1C */
  __IO uint32_t LDPRR2A8;                          /**< ldprofilereg2a8, offset: 0x20 */
  __IO uint32_t LDPRR2A9;                          /**< ldprofilereg2a9, offset: 0x24 */
  __IO uint32_t LDPRR2AA;                          /**< ldprofilereg2aa, offset: 0x28 */
  __IO uint32_t LDPRR2AB;                          /**< ldprofilereg2ab, offset: 0x2C */
  __IO uint32_t LDPRR2AC;                          /**< ldprofilereg2ac, offset: 0x30 */
  __IO uint32_t LDPRR2AD;                          /**< ldprofilereg2ad, offset: 0x34 */
  __IO uint32_t LDPRR2AE;                          /**< ldprofilereg2ae, offset: 0x38 */
  __IO uint32_t LDPRR2AF;                          /**< ldprofilereg2af, offset: 0x3C */
  __IO uint32_t LDPRR2B0;                          /**< ldprofilereg2b0, offset: 0x40 */
  __IO uint32_t LDPRR2B1;                          /**< ldprofilereg2b1, offset: 0x44 */
  __IO uint32_t LDPRR2B2;                          /**< ldprofilereg2b2, offset: 0x48 */
  __IO uint32_t LDPRR2B3;                          /**< ldprofilereg2b3, offset: 0x4C */
  __IO uint32_t LDPRR2B4;                          /**< ldprofilereg2b4, offset: 0x50 */
  __IO uint32_t LDPRR2B5;                          /**< ldprofilereg2b5, offset: 0x54 */
  __IO uint32_t LDPRR2B6;                          /**< ldprofilereg2b6, offset: 0x58 */
  __IO uint32_t LDPRR2B7;                          /**< ldprofilereg2b7, offset: 0x5C */
} locald48_Type;

/* ----------------------------------------------------------------------------
   -- locald48 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald48_Register_Masks locald48 Register Masks
 * @{
 */

/*! @name LDPRR2A0 - ldprofilereg2a0 */
/*! @{ */

#define locald48_LDPRR2A0_lumd1009_MASK          (0x3FFU)
#define locald48_LDPRR2A0_lumd1009_SHIFT         (0U)
/*! lumd1009 - lumdat_1009 */
#define locald48_LDPRR2A0_lumd1009(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2A0_lumd1009_SHIFT)) & locald48_LDPRR2A0_lumd1009_MASK)

#define locald48_LDPRR2A0_lumd1008_MASK          (0x3FF0000U)
#define locald48_LDPRR2A0_lumd1008_SHIFT         (16U)
/*! lumd1008 - lumdat_1008 */
#define locald48_LDPRR2A0_lumd1008(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2A0_lumd1008_SHIFT)) & locald48_LDPRR2A0_lumd1008_MASK)
/*! @} */

/*! @name LDPRR2A1 - ldprofilereg2a1 */
/*! @{ */

#define locald48_LDPRR2A1_lumd1011_MASK          (0x3FFU)
#define locald48_LDPRR2A1_lumd1011_SHIFT         (0U)
/*! lumd1011 - lumdat_1011 */
#define locald48_LDPRR2A1_lumd1011(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2A1_lumd1011_SHIFT)) & locald48_LDPRR2A1_lumd1011_MASK)

#define locald48_LDPRR2A1_lumd1010_MASK          (0x3FF0000U)
#define locald48_LDPRR2A1_lumd1010_SHIFT         (16U)
/*! lumd1010 - lumdat_1010 */
#define locald48_LDPRR2A1_lumd1010(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2A1_lumd1010_SHIFT)) & locald48_LDPRR2A1_lumd1010_MASK)
/*! @} */

/*! @name LDPRR2A2 - ldprofilereg2a2 */
/*! @{ */

#define locald48_LDPRR2A2_lumd1013_MASK          (0x3FFU)
#define locald48_LDPRR2A2_lumd1013_SHIFT         (0U)
/*! lumd1013 - lumdat_1013 */
#define locald48_LDPRR2A2_lumd1013(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2A2_lumd1013_SHIFT)) & locald48_LDPRR2A2_lumd1013_MASK)

#define locald48_LDPRR2A2_lumd1012_MASK          (0x3FF0000U)
#define locald48_LDPRR2A2_lumd1012_SHIFT         (16U)
/*! lumd1012 - lumdat_1012 */
#define locald48_LDPRR2A2_lumd1012(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2A2_lumd1012_SHIFT)) & locald48_LDPRR2A2_lumd1012_MASK)
/*! @} */

/*! @name LDPRR2A3 - ldprofilereg2a3 */
/*! @{ */

#define locald48_LDPRR2A3_lumd1015_MASK          (0x3FFU)
#define locald48_LDPRR2A3_lumd1015_SHIFT         (0U)
/*! lumd1015 - lumdat_1015 */
#define locald48_LDPRR2A3_lumd1015(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2A3_lumd1015_SHIFT)) & locald48_LDPRR2A3_lumd1015_MASK)

#define locald48_LDPRR2A3_lumd1014_MASK          (0x3FF0000U)
#define locald48_LDPRR2A3_lumd1014_SHIFT         (16U)
/*! lumd1014 - lumdat_1014 */
#define locald48_LDPRR2A3_lumd1014(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2A3_lumd1014_SHIFT)) & locald48_LDPRR2A3_lumd1014_MASK)
/*! @} */

/*! @name LDPRR2A4 - ldprofilereg2a4 */
/*! @{ */

#define locald48_LDPRR2A4_lumd1017_MASK          (0x3FFU)
#define locald48_LDPRR2A4_lumd1017_SHIFT         (0U)
/*! lumd1017 - lumdat_1017 */
#define locald48_LDPRR2A4_lumd1017(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2A4_lumd1017_SHIFT)) & locald48_LDPRR2A4_lumd1017_MASK)

#define locald48_LDPRR2A4_lumd1016_MASK          (0x3FF0000U)
#define locald48_LDPRR2A4_lumd1016_SHIFT         (16U)
/*! lumd1016 - lumdat_1016 */
#define locald48_LDPRR2A4_lumd1016(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2A4_lumd1016_SHIFT)) & locald48_LDPRR2A4_lumd1016_MASK)
/*! @} */

/*! @name LDPRR2A5 - ldprofilereg2a5 */
/*! @{ */

#define locald48_LDPRR2A5_lumd1019_MASK          (0x3FFU)
#define locald48_LDPRR2A5_lumd1019_SHIFT         (0U)
/*! lumd1019 - lumdat_1019 */
#define locald48_LDPRR2A5_lumd1019(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2A5_lumd1019_SHIFT)) & locald48_LDPRR2A5_lumd1019_MASK)

#define locald48_LDPRR2A5_lumd1018_MASK          (0x3FF0000U)
#define locald48_LDPRR2A5_lumd1018_SHIFT         (16U)
/*! lumd1018 - lumdat_1018 */
#define locald48_LDPRR2A5_lumd1018(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2A5_lumd1018_SHIFT)) & locald48_LDPRR2A5_lumd1018_MASK)
/*! @} */

/*! @name LDPRR2A6 - ldprofilereg2a6 */
/*! @{ */

#define locald48_LDPRR2A6_lumd1021_MASK          (0x3FFU)
#define locald48_LDPRR2A6_lumd1021_SHIFT         (0U)
/*! lumd1021 - lumdat_1021 */
#define locald48_LDPRR2A6_lumd1021(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2A6_lumd1021_SHIFT)) & locald48_LDPRR2A6_lumd1021_MASK)

#define locald48_LDPRR2A6_lumd1020_MASK          (0x3FF0000U)
#define locald48_LDPRR2A6_lumd1020_SHIFT         (16U)
/*! lumd1020 - lumdat_1020 */
#define locald48_LDPRR2A6_lumd1020(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2A6_lumd1020_SHIFT)) & locald48_LDPRR2A6_lumd1020_MASK)
/*! @} */

/*! @name LDPRR2A7 - ldprofilereg2a7 */
/*! @{ */

#define locald48_LDPRR2A7_lumd1023_MASK          (0x3FFU)
#define locald48_LDPRR2A7_lumd1023_SHIFT         (0U)
/*! lumd1023 - lumdat_1023 */
#define locald48_LDPRR2A7_lumd1023(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2A7_lumd1023_SHIFT)) & locald48_LDPRR2A7_lumd1023_MASK)

#define locald48_LDPRR2A7_lumd1022_MASK          (0x3FF0000U)
#define locald48_LDPRR2A7_lumd1022_SHIFT         (16U)
/*! lumd1022 - lumdat_1022 */
#define locald48_LDPRR2A7_lumd1022(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2A7_lumd1022_SHIFT)) & locald48_LDPRR2A7_lumd1022_MASK)
/*! @} */

/*! @name LDPRR2A8 - ldprofilereg2a8 */
/*! @{ */

#define locald48_LDPRR2A8_lumd1025_MASK          (0x3FFU)
#define locald48_LDPRR2A8_lumd1025_SHIFT         (0U)
/*! lumd1025 - lumdat_1025 */
#define locald48_LDPRR2A8_lumd1025(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2A8_lumd1025_SHIFT)) & locald48_LDPRR2A8_lumd1025_MASK)

#define locald48_LDPRR2A8_lumd1024_MASK          (0x3FF0000U)
#define locald48_LDPRR2A8_lumd1024_SHIFT         (16U)
/*! lumd1024 - lumdat_1024 */
#define locald48_LDPRR2A8_lumd1024(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2A8_lumd1024_SHIFT)) & locald48_LDPRR2A8_lumd1024_MASK)
/*! @} */

/*! @name LDPRR2A9 - ldprofilereg2a9 */
/*! @{ */

#define locald48_LDPRR2A9_lumd1027_MASK          (0x3FFU)
#define locald48_LDPRR2A9_lumd1027_SHIFT         (0U)
/*! lumd1027 - lumdat_1027 */
#define locald48_LDPRR2A9_lumd1027(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2A9_lumd1027_SHIFT)) & locald48_LDPRR2A9_lumd1027_MASK)

#define locald48_LDPRR2A9_lumd1026_MASK          (0x3FF0000U)
#define locald48_LDPRR2A9_lumd1026_SHIFT         (16U)
/*! lumd1026 - lumdat_1026 */
#define locald48_LDPRR2A9_lumd1026(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2A9_lumd1026_SHIFT)) & locald48_LDPRR2A9_lumd1026_MASK)
/*! @} */

/*! @name LDPRR2AA - ldprofilereg2aa */
/*! @{ */

#define locald48_LDPRR2AA_lumd1029_MASK          (0x3FFU)
#define locald48_LDPRR2AA_lumd1029_SHIFT         (0U)
/*! lumd1029 - lumdat_1029 */
#define locald48_LDPRR2AA_lumd1029(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2AA_lumd1029_SHIFT)) & locald48_LDPRR2AA_lumd1029_MASK)

#define locald48_LDPRR2AA_lumd1028_MASK          (0x3FF0000U)
#define locald48_LDPRR2AA_lumd1028_SHIFT         (16U)
/*! lumd1028 - lumdat_1028 */
#define locald48_LDPRR2AA_lumd1028(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2AA_lumd1028_SHIFT)) & locald48_LDPRR2AA_lumd1028_MASK)
/*! @} */

/*! @name LDPRR2AB - ldprofilereg2ab */
/*! @{ */

#define locald48_LDPRR2AB_lumd1031_MASK          (0x3FFU)
#define locald48_LDPRR2AB_lumd1031_SHIFT         (0U)
/*! lumd1031 - lumdat_1031 */
#define locald48_LDPRR2AB_lumd1031(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2AB_lumd1031_SHIFT)) & locald48_LDPRR2AB_lumd1031_MASK)

#define locald48_LDPRR2AB_lumd1030_MASK          (0x3FF0000U)
#define locald48_LDPRR2AB_lumd1030_SHIFT         (16U)
/*! lumd1030 - lumdat_1030 */
#define locald48_LDPRR2AB_lumd1030(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2AB_lumd1030_SHIFT)) & locald48_LDPRR2AB_lumd1030_MASK)
/*! @} */

/*! @name LDPRR2AC - ldprofilereg2ac */
/*! @{ */

#define locald48_LDPRR2AC_lumd1033_MASK          (0x3FFU)
#define locald48_LDPRR2AC_lumd1033_SHIFT         (0U)
/*! lumd1033 - lumdat_1033 */
#define locald48_LDPRR2AC_lumd1033(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2AC_lumd1033_SHIFT)) & locald48_LDPRR2AC_lumd1033_MASK)

#define locald48_LDPRR2AC_lumd1032_MASK          (0x3FF0000U)
#define locald48_LDPRR2AC_lumd1032_SHIFT         (16U)
/*! lumd1032 - lumdat_1032 */
#define locald48_LDPRR2AC_lumd1032(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2AC_lumd1032_SHIFT)) & locald48_LDPRR2AC_lumd1032_MASK)
/*! @} */

/*! @name LDPRR2AD - ldprofilereg2ad */
/*! @{ */

#define locald48_LDPRR2AD_lumd1035_MASK          (0x3FFU)
#define locald48_LDPRR2AD_lumd1035_SHIFT         (0U)
/*! lumd1035 - lumdat_1035 */
#define locald48_LDPRR2AD_lumd1035(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2AD_lumd1035_SHIFT)) & locald48_LDPRR2AD_lumd1035_MASK)

#define locald48_LDPRR2AD_lumd1034_MASK          (0x3FF0000U)
#define locald48_LDPRR2AD_lumd1034_SHIFT         (16U)
/*! lumd1034 - lumdat_1034 */
#define locald48_LDPRR2AD_lumd1034(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2AD_lumd1034_SHIFT)) & locald48_LDPRR2AD_lumd1034_MASK)
/*! @} */

/*! @name LDPRR2AE - ldprofilereg2ae */
/*! @{ */

#define locald48_LDPRR2AE_lumd1037_MASK          (0x3FFU)
#define locald48_LDPRR2AE_lumd1037_SHIFT         (0U)
/*! lumd1037 - lumdat_1037 */
#define locald48_LDPRR2AE_lumd1037(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2AE_lumd1037_SHIFT)) & locald48_LDPRR2AE_lumd1037_MASK)

#define locald48_LDPRR2AE_lumd1036_MASK          (0x3FF0000U)
#define locald48_LDPRR2AE_lumd1036_SHIFT         (16U)
/*! lumd1036 - lumdat_1036 */
#define locald48_LDPRR2AE_lumd1036(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2AE_lumd1036_SHIFT)) & locald48_LDPRR2AE_lumd1036_MASK)
/*! @} */

/*! @name LDPRR2AF - ldprofilereg2af */
/*! @{ */

#define locald48_LDPRR2AF_lumd1039_MASK          (0x3FFU)
#define locald48_LDPRR2AF_lumd1039_SHIFT         (0U)
/*! lumd1039 - lumdat_1039 */
#define locald48_LDPRR2AF_lumd1039(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2AF_lumd1039_SHIFT)) & locald48_LDPRR2AF_lumd1039_MASK)

#define locald48_LDPRR2AF_lumd1038_MASK          (0x3FF0000U)
#define locald48_LDPRR2AF_lumd1038_SHIFT         (16U)
/*! lumd1038 - lumdat_1038 */
#define locald48_LDPRR2AF_lumd1038(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2AF_lumd1038_SHIFT)) & locald48_LDPRR2AF_lumd1038_MASK)
/*! @} */

/*! @name LDPRR2B0 - ldprofilereg2b0 */
/*! @{ */

#define locald48_LDPRR2B0_lumd1041_MASK          (0x3FFU)
#define locald48_LDPRR2B0_lumd1041_SHIFT         (0U)
/*! lumd1041 - lumdat_1041 */
#define locald48_LDPRR2B0_lumd1041(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2B0_lumd1041_SHIFT)) & locald48_LDPRR2B0_lumd1041_MASK)

#define locald48_LDPRR2B0_lumd1040_MASK          (0x3FF0000U)
#define locald48_LDPRR2B0_lumd1040_SHIFT         (16U)
/*! lumd1040 - lumdat_1040 */
#define locald48_LDPRR2B0_lumd1040(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2B0_lumd1040_SHIFT)) & locald48_LDPRR2B0_lumd1040_MASK)
/*! @} */

/*! @name LDPRR2B1 - ldprofilereg2b1 */
/*! @{ */

#define locald48_LDPRR2B1_lumd1043_MASK          (0x3FFU)
#define locald48_LDPRR2B1_lumd1043_SHIFT         (0U)
/*! lumd1043 - lumdat_1043 */
#define locald48_LDPRR2B1_lumd1043(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2B1_lumd1043_SHIFT)) & locald48_LDPRR2B1_lumd1043_MASK)

#define locald48_LDPRR2B1_lumd1042_MASK          (0x3FF0000U)
#define locald48_LDPRR2B1_lumd1042_SHIFT         (16U)
/*! lumd1042 - lumdat_1042 */
#define locald48_LDPRR2B1_lumd1042(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2B1_lumd1042_SHIFT)) & locald48_LDPRR2B1_lumd1042_MASK)
/*! @} */

/*! @name LDPRR2B2 - ldprofilereg2b2 */
/*! @{ */

#define locald48_LDPRR2B2_lumd1045_MASK          (0x3FFU)
#define locald48_LDPRR2B2_lumd1045_SHIFT         (0U)
/*! lumd1045 - lumdat_1045 */
#define locald48_LDPRR2B2_lumd1045(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2B2_lumd1045_SHIFT)) & locald48_LDPRR2B2_lumd1045_MASK)

#define locald48_LDPRR2B2_lumd1044_MASK          (0x3FF0000U)
#define locald48_LDPRR2B2_lumd1044_SHIFT         (16U)
/*! lumd1044 - lumdat_1044 */
#define locald48_LDPRR2B2_lumd1044(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2B2_lumd1044_SHIFT)) & locald48_LDPRR2B2_lumd1044_MASK)
/*! @} */

/*! @name LDPRR2B3 - ldprofilereg2b3 */
/*! @{ */

#define locald48_LDPRR2B3_lumd1047_MASK          (0x3FFU)
#define locald48_LDPRR2B3_lumd1047_SHIFT         (0U)
/*! lumd1047 - lumdat_1047 */
#define locald48_LDPRR2B3_lumd1047(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2B3_lumd1047_SHIFT)) & locald48_LDPRR2B3_lumd1047_MASK)

#define locald48_LDPRR2B3_lumd1046_MASK          (0x3FF0000U)
#define locald48_LDPRR2B3_lumd1046_SHIFT         (16U)
/*! lumd1046 - lumdat_1046 */
#define locald48_LDPRR2B3_lumd1046(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2B3_lumd1046_SHIFT)) & locald48_LDPRR2B3_lumd1046_MASK)
/*! @} */

/*! @name LDPRR2B4 - ldprofilereg2b4 */
/*! @{ */

#define locald48_LDPRR2B4_lumd1049_MASK          (0x3FFU)
#define locald48_LDPRR2B4_lumd1049_SHIFT         (0U)
/*! lumd1049 - lumdat_1049 */
#define locald48_LDPRR2B4_lumd1049(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2B4_lumd1049_SHIFT)) & locald48_LDPRR2B4_lumd1049_MASK)

#define locald48_LDPRR2B4_lumd1048_MASK          (0x3FF0000U)
#define locald48_LDPRR2B4_lumd1048_SHIFT         (16U)
/*! lumd1048 - lumdat_1048 */
#define locald48_LDPRR2B4_lumd1048(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2B4_lumd1048_SHIFT)) & locald48_LDPRR2B4_lumd1048_MASK)
/*! @} */

/*! @name LDPRR2B5 - ldprofilereg2b5 */
/*! @{ */

#define locald48_LDPRR2B5_lumd1051_MASK          (0x3FFU)
#define locald48_LDPRR2B5_lumd1051_SHIFT         (0U)
/*! lumd1051 - lumdat_1051 */
#define locald48_LDPRR2B5_lumd1051(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2B5_lumd1051_SHIFT)) & locald48_LDPRR2B5_lumd1051_MASK)

#define locald48_LDPRR2B5_lumd1050_MASK          (0x3FF0000U)
#define locald48_LDPRR2B5_lumd1050_SHIFT         (16U)
/*! lumd1050 - lumdat_1050 */
#define locald48_LDPRR2B5_lumd1050(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2B5_lumd1050_SHIFT)) & locald48_LDPRR2B5_lumd1050_MASK)
/*! @} */

/*! @name LDPRR2B6 - ldprofilereg2b6 */
/*! @{ */

#define locald48_LDPRR2B6_lumd1053_MASK          (0x3FFU)
#define locald48_LDPRR2B6_lumd1053_SHIFT         (0U)
/*! lumd1053 - lumdat_1053 */
#define locald48_LDPRR2B6_lumd1053(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2B6_lumd1053_SHIFT)) & locald48_LDPRR2B6_lumd1053_MASK)

#define locald48_LDPRR2B6_lumd1052_MASK          (0x3FF0000U)
#define locald48_LDPRR2B6_lumd1052_SHIFT         (16U)
/*! lumd1052 - lumdat_1052 */
#define locald48_LDPRR2B6_lumd1052(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2B6_lumd1052_SHIFT)) & locald48_LDPRR2B6_lumd1052_MASK)
/*! @} */

/*! @name LDPRR2B7 - ldprofilereg2b7 */
/*! @{ */

#define locald48_LDPRR2B7_lumd1055_MASK          (0x3FFU)
#define locald48_LDPRR2B7_lumd1055_SHIFT         (0U)
/*! lumd1055 - lumdat_1055 */
#define locald48_LDPRR2B7_lumd1055(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2B7_lumd1055_SHIFT)) & locald48_LDPRR2B7_lumd1055_MASK)

#define locald48_LDPRR2B7_lumd1054_MASK          (0x3FF0000U)
#define locald48_LDPRR2B7_lumd1054_SHIFT         (16U)
/*! lumd1054 - lumdat_1054 */
#define locald48_LDPRR2B7_lumd1054(x)            (((uint32_t)(((uint32_t)(x)) << locald48_LDPRR2B7_lumd1054_SHIFT)) & locald48_LDPRR2B7_lumd1054_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald48_Register_Masks */


/*!
 * @}
 */ /* end of group locald48_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD48_H_ */

