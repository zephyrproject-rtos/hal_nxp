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
**         CMSIS Peripheral Access Layer for locald27
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
 * @file PERI_locald27.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald27
 *
 * CMSIS Peripheral Access Layer for locald27
 */

#if !defined(PERI_LOCALD27_H_)
#define PERI_LOCALD27_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald27 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald27_Peripheral_Access_Layer locald27 Peripheral Access Layer
 * @{
 */

/** locald27 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR000;                          /**< ldprofilereg000, offset: 0x0 */
  __IO uint32_t LDPRR001;                          /**< ldprofilereg001, offset: 0x4 */
  __IO uint32_t LDPRR002;                          /**< ldprofilereg002, offset: 0x8 */
  __IO uint32_t LDPRR003;                          /**< ldprofilereg003, offset: 0xC */
  __IO uint32_t LDPRR004;                          /**< ldprofilereg004, offset: 0x10 */
  __IO uint32_t LDPRR005;                          /**< ldprofilereg005, offset: 0x14 */
  __IO uint32_t LDPRR006;                          /**< ldprofilereg006, offset: 0x18 */
  __IO uint32_t LDPRR007;                          /**< ldprofilereg007, offset: 0x1C */
  __IO uint32_t LDPRR008;                          /**< ldprofilereg008, offset: 0x20 */
  __IO uint32_t LDPRR009;                          /**< ldprofilereg009, offset: 0x24 */
  __IO uint32_t LDPRR00A;                          /**< ldprofilereg00a, offset: 0x28 */
  __IO uint32_t LDPRR00B;                          /**< ldprofilereg00b, offset: 0x2C */
  __IO uint32_t LDPRR00C;                          /**< ldprofilereg00c, offset: 0x30 */
  __IO uint32_t LDPRR00D;                          /**< ldprofilereg00d, offset: 0x34 */
  __IO uint32_t LDPRR00E;                          /**< ldprofilereg00e, offset: 0x38 */
  __IO uint32_t LDPRR00F;                          /**< ldprofilereg00f, offset: 0x3C */
  __IO uint32_t LDPRR010;                          /**< ldprofilereg010, offset: 0x40 */
  __IO uint32_t LDPRR011;                          /**< ldprofilereg011, offset: 0x44 */
  __IO uint32_t LDPRR012;                          /**< ldprofilereg012, offset: 0x48 */
  __IO uint32_t LDPRR013;                          /**< ldprofilereg013, offset: 0x4C */
  __IO uint32_t LDPRR014;                          /**< ldprofilereg014, offset: 0x50 */
  __IO uint32_t LDPRR015;                          /**< ldprofilereg015, offset: 0x54 */
  __IO uint32_t LDPRR016;                          /**< ldprofilereg016, offset: 0x58 */
  __IO uint32_t LDPRR017;                          /**< ldprofilereg017, offset: 0x5C */
} locald27_Type;

/* ----------------------------------------------------------------------------
   -- locald27 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald27_Register_Masks locald27 Register Masks
 * @{
 */

/*! @name LDPRR000 - ldprofilereg000 */
/*! @{ */

#define locald27_LDPRR000_lumdat1_MASK           (0x3FFU)
#define locald27_LDPRR000_lumdat1_SHIFT          (0U)
/*! lumdat1 - lumdat_1 */
#define locald27_LDPRR000_lumdat1(x)             (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR000_lumdat1_SHIFT)) & locald27_LDPRR000_lumdat1_MASK)

#define locald27_LDPRR000_lumdat0_MASK           (0x3FF0000U)
#define locald27_LDPRR000_lumdat0_SHIFT          (16U)
/*! lumdat0 - lumdat_0 */
#define locald27_LDPRR000_lumdat0(x)             (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR000_lumdat0_SHIFT)) & locald27_LDPRR000_lumdat0_MASK)
/*! @} */

/*! @name LDPRR001 - ldprofilereg001 */
/*! @{ */

#define locald27_LDPRR001_lumdat3_MASK           (0x3FFU)
#define locald27_LDPRR001_lumdat3_SHIFT          (0U)
/*! lumdat3 - lumdat_3 */
#define locald27_LDPRR001_lumdat3(x)             (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR001_lumdat3_SHIFT)) & locald27_LDPRR001_lumdat3_MASK)

#define locald27_LDPRR001_lumdat2_MASK           (0x3FF0000U)
#define locald27_LDPRR001_lumdat2_SHIFT          (16U)
/*! lumdat2 - lumdat_2 */
#define locald27_LDPRR001_lumdat2(x)             (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR001_lumdat2_SHIFT)) & locald27_LDPRR001_lumdat2_MASK)
/*! @} */

/*! @name LDPRR002 - ldprofilereg002 */
/*! @{ */

#define locald27_LDPRR002_lumdat5_MASK           (0x3FFU)
#define locald27_LDPRR002_lumdat5_SHIFT          (0U)
/*! lumdat5 - lumdat_5 */
#define locald27_LDPRR002_lumdat5(x)             (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR002_lumdat5_SHIFT)) & locald27_LDPRR002_lumdat5_MASK)

#define locald27_LDPRR002_lumdat4_MASK           (0x3FF0000U)
#define locald27_LDPRR002_lumdat4_SHIFT          (16U)
/*! lumdat4 - lumdat_4 */
#define locald27_LDPRR002_lumdat4(x)             (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR002_lumdat4_SHIFT)) & locald27_LDPRR002_lumdat4_MASK)
/*! @} */

/*! @name LDPRR003 - ldprofilereg003 */
/*! @{ */

#define locald27_LDPRR003_lumdat7_MASK           (0x3FFU)
#define locald27_LDPRR003_lumdat7_SHIFT          (0U)
/*! lumdat7 - lumdat_7 */
#define locald27_LDPRR003_lumdat7(x)             (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR003_lumdat7_SHIFT)) & locald27_LDPRR003_lumdat7_MASK)

#define locald27_LDPRR003_lumdat6_MASK           (0x3FF0000U)
#define locald27_LDPRR003_lumdat6_SHIFT          (16U)
/*! lumdat6 - lumdat_6 */
#define locald27_LDPRR003_lumdat6(x)             (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR003_lumdat6_SHIFT)) & locald27_LDPRR003_lumdat6_MASK)
/*! @} */

/*! @name LDPRR004 - ldprofilereg004 */
/*! @{ */

#define locald27_LDPRR004_lumdat9_MASK           (0x3FFU)
#define locald27_LDPRR004_lumdat9_SHIFT          (0U)
/*! lumdat9 - lumdat_9 */
#define locald27_LDPRR004_lumdat9(x)             (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR004_lumdat9_SHIFT)) & locald27_LDPRR004_lumdat9_MASK)

#define locald27_LDPRR004_lumdat8_MASK           (0x3FF0000U)
#define locald27_LDPRR004_lumdat8_SHIFT          (16U)
/*! lumdat8 - lumdat_8 */
#define locald27_LDPRR004_lumdat8(x)             (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR004_lumdat8_SHIFT)) & locald27_LDPRR004_lumdat8_MASK)
/*! @} */

/*! @name LDPRR005 - ldprofilereg005 */
/*! @{ */

#define locald27_LDPRR005_lumdat11_MASK          (0x3FFU)
#define locald27_LDPRR005_lumdat11_SHIFT         (0U)
/*! lumdat11 - lumdat_11 */
#define locald27_LDPRR005_lumdat11(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR005_lumdat11_SHIFT)) & locald27_LDPRR005_lumdat11_MASK)

#define locald27_LDPRR005_lumdat10_MASK          (0x3FF0000U)
#define locald27_LDPRR005_lumdat10_SHIFT         (16U)
/*! lumdat10 - lumdat_10 */
#define locald27_LDPRR005_lumdat10(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR005_lumdat10_SHIFT)) & locald27_LDPRR005_lumdat10_MASK)
/*! @} */

/*! @name LDPRR006 - ldprofilereg006 */
/*! @{ */

#define locald27_LDPRR006_lumd13_MASK            (0x3FFU)
#define locald27_LDPRR006_lumd13_SHIFT           (0U)
/*! lumd13 - lumdat_13 */
#define locald27_LDPRR006_lumd13(x)              (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR006_lumd13_SHIFT)) & locald27_LDPRR006_lumd13_MASK)

#define locald27_LDPRR006_lumdat12_MASK          (0x3FF0000U)
#define locald27_LDPRR006_lumdat12_SHIFT         (16U)
/*! lumdat12 - lumdat_12 */
#define locald27_LDPRR006_lumdat12(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR006_lumdat12_SHIFT)) & locald27_LDPRR006_lumdat12_MASK)
/*! @} */

/*! @name LDPRR007 - ldprofilereg007 */
/*! @{ */

#define locald27_LDPRR007_lumdat15_MASK          (0x3FFU)
#define locald27_LDPRR007_lumdat15_SHIFT         (0U)
/*! lumdat15 - lumdat_15 */
#define locald27_LDPRR007_lumdat15(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR007_lumdat15_SHIFT)) & locald27_LDPRR007_lumdat15_MASK)

#define locald27_LDPRR007_lumd14_MASK            (0x3FF0000U)
#define locald27_LDPRR007_lumd14_SHIFT           (16U)
/*! lumd14 - lumdat_14 */
#define locald27_LDPRR007_lumd14(x)              (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR007_lumd14_SHIFT)) & locald27_LDPRR007_lumd14_MASK)
/*! @} */

/*! @name LDPRR008 - ldprofilereg008 */
/*! @{ */

#define locald27_LDPRR008_lumdat17_MASK          (0x3FFU)
#define locald27_LDPRR008_lumdat17_SHIFT         (0U)
/*! lumdat17 - lumdat_17 */
#define locald27_LDPRR008_lumdat17(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR008_lumdat17_SHIFT)) & locald27_LDPRR008_lumdat17_MASK)

#define locald27_LDPRR008_lumdat16_MASK          (0x3FF0000U)
#define locald27_LDPRR008_lumdat16_SHIFT         (16U)
/*! lumdat16 - lumdat_16 */
#define locald27_LDPRR008_lumdat16(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR008_lumdat16_SHIFT)) & locald27_LDPRR008_lumdat16_MASK)
/*! @} */

/*! @name LDPRR009 - ldprofilereg009 */
/*! @{ */

#define locald27_LDPRR009_lumdat19_MASK          (0x3FFU)
#define locald27_LDPRR009_lumdat19_SHIFT         (0U)
/*! lumdat19 - lumdat_19 */
#define locald27_LDPRR009_lumdat19(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR009_lumdat19_SHIFT)) & locald27_LDPRR009_lumdat19_MASK)

#define locald27_LDPRR009_lumdat18_MASK          (0x3FF0000U)
#define locald27_LDPRR009_lumdat18_SHIFT         (16U)
/*! lumdat18 - lumdat_18 */
#define locald27_LDPRR009_lumdat18(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR009_lumdat18_SHIFT)) & locald27_LDPRR009_lumdat18_MASK)
/*! @} */

/*! @name LDPRR00A - ldprofilereg00a */
/*! @{ */

#define locald27_LDPRR00A_lumdat21_MASK          (0x3FFU)
#define locald27_LDPRR00A_lumdat21_SHIFT         (0U)
/*! lumdat21 - lumdat_21 */
#define locald27_LDPRR00A_lumdat21(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR00A_lumdat21_SHIFT)) & locald27_LDPRR00A_lumdat21_MASK)

#define locald27_LDPRR00A_lumdat20_MASK          (0x3FF0000U)
#define locald27_LDPRR00A_lumdat20_SHIFT         (16U)
/*! lumdat20 - lumdat_20 */
#define locald27_LDPRR00A_lumdat20(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR00A_lumdat20_SHIFT)) & locald27_LDPRR00A_lumdat20_MASK)
/*! @} */

/*! @name LDPRR00B - ldprofilereg00b */
/*! @{ */

#define locald27_LDPRR00B_lumdat23_MASK          (0x3FFU)
#define locald27_LDPRR00B_lumdat23_SHIFT         (0U)
/*! lumdat23 - lumdat_23 */
#define locald27_LDPRR00B_lumdat23(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR00B_lumdat23_SHIFT)) & locald27_LDPRR00B_lumdat23_MASK)

#define locald27_LDPRR00B_lumdat22_MASK          (0x3FF0000U)
#define locald27_LDPRR00B_lumdat22_SHIFT         (16U)
/*! lumdat22 - lumdat_22 */
#define locald27_LDPRR00B_lumdat22(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR00B_lumdat22_SHIFT)) & locald27_LDPRR00B_lumdat22_MASK)
/*! @} */

/*! @name LDPRR00C - ldprofilereg00c */
/*! @{ */

#define locald27_LDPRR00C_lumdat25_MASK          (0x3FFU)
#define locald27_LDPRR00C_lumdat25_SHIFT         (0U)
/*! lumdat25 - lumdat_25 */
#define locald27_LDPRR00C_lumdat25(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR00C_lumdat25_SHIFT)) & locald27_LDPRR00C_lumdat25_MASK)

#define locald27_LDPRR00C_lumdat24_MASK          (0x3FF0000U)
#define locald27_LDPRR00C_lumdat24_SHIFT         (16U)
/*! lumdat24 - lumdat_24 */
#define locald27_LDPRR00C_lumdat24(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR00C_lumdat24_SHIFT)) & locald27_LDPRR00C_lumdat24_MASK)
/*! @} */

/*! @name LDPRR00D - ldprofilereg00d */
/*! @{ */

#define locald27_LDPRR00D_lumdat27_MASK          (0x3FFU)
#define locald27_LDPRR00D_lumdat27_SHIFT         (0U)
/*! lumdat27 - lumdat_27 */
#define locald27_LDPRR00D_lumdat27(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR00D_lumdat27_SHIFT)) & locald27_LDPRR00D_lumdat27_MASK)

#define locald27_LDPRR00D_lumdat26_MASK          (0x3FF0000U)
#define locald27_LDPRR00D_lumdat26_SHIFT         (16U)
/*! lumdat26 - lumdat_26 */
#define locald27_LDPRR00D_lumdat26(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR00D_lumdat26_SHIFT)) & locald27_LDPRR00D_lumdat26_MASK)
/*! @} */

/*! @name LDPRR00E - ldprofilereg00e */
/*! @{ */

#define locald27_LDPRR00E_lumdat29_MASK          (0x3FFU)
#define locald27_LDPRR00E_lumdat29_SHIFT         (0U)
/*! lumdat29 - lumdat_29 */
#define locald27_LDPRR00E_lumdat29(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR00E_lumdat29_SHIFT)) & locald27_LDPRR00E_lumdat29_MASK)

#define locald27_LDPRR00E_lumdat28_MASK          (0x3FF0000U)
#define locald27_LDPRR00E_lumdat28_SHIFT         (16U)
/*! lumdat28 - lumdat_28 */
#define locald27_LDPRR00E_lumdat28(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR00E_lumdat28_SHIFT)) & locald27_LDPRR00E_lumdat28_MASK)
/*! @} */

/*! @name LDPRR00F - ldprofilereg00f */
/*! @{ */

#define locald27_LDPRR00F_lumdat31_MASK          (0x3FFU)
#define locald27_LDPRR00F_lumdat31_SHIFT         (0U)
/*! lumdat31 - lumdat_31 */
#define locald27_LDPRR00F_lumdat31(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR00F_lumdat31_SHIFT)) & locald27_LDPRR00F_lumdat31_MASK)

#define locald27_LDPRR00F_lumdat30_MASK          (0x3FF0000U)
#define locald27_LDPRR00F_lumdat30_SHIFT         (16U)
/*! lumdat30 - lumdat_30 */
#define locald27_LDPRR00F_lumdat30(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR00F_lumdat30_SHIFT)) & locald27_LDPRR00F_lumdat30_MASK)
/*! @} */

/*! @name LDPRR010 - ldprofilereg010 */
/*! @{ */

#define locald27_LDPRR010_lumdat33_MASK          (0x3FFU)
#define locald27_LDPRR010_lumdat33_SHIFT         (0U)
/*! lumdat33 - lumdat_33 */
#define locald27_LDPRR010_lumdat33(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR010_lumdat33_SHIFT)) & locald27_LDPRR010_lumdat33_MASK)

#define locald27_LDPRR010_lumdat32_MASK          (0x3FF0000U)
#define locald27_LDPRR010_lumdat32_SHIFT         (16U)
/*! lumdat32 - lumdat_32 */
#define locald27_LDPRR010_lumdat32(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR010_lumdat32_SHIFT)) & locald27_LDPRR010_lumdat32_MASK)
/*! @} */

/*! @name LDPRR011 - ldprofilereg011 */
/*! @{ */

#define locald27_LDPRR011_lumdat35_MASK          (0x3FFU)
#define locald27_LDPRR011_lumdat35_SHIFT         (0U)
/*! lumdat35 - lumdat_35 */
#define locald27_LDPRR011_lumdat35(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR011_lumdat35_SHIFT)) & locald27_LDPRR011_lumdat35_MASK)

#define locald27_LDPRR011_lumdat34_MASK          (0x3FF0000U)
#define locald27_LDPRR011_lumdat34_SHIFT         (16U)
/*! lumdat34 - lumdat_34 */
#define locald27_LDPRR011_lumdat34(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR011_lumdat34_SHIFT)) & locald27_LDPRR011_lumdat34_MASK)
/*! @} */

/*! @name LDPRR012 - ldprofilereg012 */
/*! @{ */

#define locald27_LDPRR012_lumdat37_MASK          (0x3FFU)
#define locald27_LDPRR012_lumdat37_SHIFT         (0U)
/*! lumdat37 - lumdat_37 */
#define locald27_LDPRR012_lumdat37(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR012_lumdat37_SHIFT)) & locald27_LDPRR012_lumdat37_MASK)

#define locald27_LDPRR012_lumdat36_MASK          (0x3FF0000U)
#define locald27_LDPRR012_lumdat36_SHIFT         (16U)
/*! lumdat36 - lumdat_36 */
#define locald27_LDPRR012_lumdat36(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR012_lumdat36_SHIFT)) & locald27_LDPRR012_lumdat36_MASK)
/*! @} */

/*! @name LDPRR013 - ldprofilereg013 */
/*! @{ */

#define locald27_LDPRR013_lumdat39_MASK          (0x3FFU)
#define locald27_LDPRR013_lumdat39_SHIFT         (0U)
/*! lumdat39 - lumdat_39 */
#define locald27_LDPRR013_lumdat39(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR013_lumdat39_SHIFT)) & locald27_LDPRR013_lumdat39_MASK)

#define locald27_LDPRR013_lumdat38_MASK          (0x3FF0000U)
#define locald27_LDPRR013_lumdat38_SHIFT         (16U)
/*! lumdat38 - lumdat_38 */
#define locald27_LDPRR013_lumdat38(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR013_lumdat38_SHIFT)) & locald27_LDPRR013_lumdat38_MASK)
/*! @} */

/*! @name LDPRR014 - ldprofilereg014 */
/*! @{ */

#define locald27_LDPRR014_lumdat41_MASK          (0x3FFU)
#define locald27_LDPRR014_lumdat41_SHIFT         (0U)
/*! lumdat41 - lumdat_41 */
#define locald27_LDPRR014_lumdat41(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR014_lumdat41_SHIFT)) & locald27_LDPRR014_lumdat41_MASK)

#define locald27_LDPRR014_lumdat40_MASK          (0x3FF0000U)
#define locald27_LDPRR014_lumdat40_SHIFT         (16U)
/*! lumdat40 - lumdat_40 */
#define locald27_LDPRR014_lumdat40(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR014_lumdat40_SHIFT)) & locald27_LDPRR014_lumdat40_MASK)
/*! @} */

/*! @name LDPRR015 - ldprofilereg015 */
/*! @{ */

#define locald27_LDPRR015_lumdat43_MASK          (0x3FFU)
#define locald27_LDPRR015_lumdat43_SHIFT         (0U)
/*! lumdat43 - lumdat_43 */
#define locald27_LDPRR015_lumdat43(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR015_lumdat43_SHIFT)) & locald27_LDPRR015_lumdat43_MASK)

#define locald27_LDPRR015_lumdat42_MASK          (0x3FF0000U)
#define locald27_LDPRR015_lumdat42_SHIFT         (16U)
/*! lumdat42 - lumdat_42 */
#define locald27_LDPRR015_lumdat42(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR015_lumdat42_SHIFT)) & locald27_LDPRR015_lumdat42_MASK)
/*! @} */

/*! @name LDPRR016 - ldprofilereg016 */
/*! @{ */

#define locald27_LDPRR016_lumdat45_MASK          (0x3FFU)
#define locald27_LDPRR016_lumdat45_SHIFT         (0U)
/*! lumdat45 - lumdat_45 */
#define locald27_LDPRR016_lumdat45(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR016_lumdat45_SHIFT)) & locald27_LDPRR016_lumdat45_MASK)

#define locald27_LDPRR016_lumdat44_MASK          (0x3FF0000U)
#define locald27_LDPRR016_lumdat44_SHIFT         (16U)
/*! lumdat44 - lumdat_44 */
#define locald27_LDPRR016_lumdat44(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR016_lumdat44_SHIFT)) & locald27_LDPRR016_lumdat44_MASK)
/*! @} */

/*! @name LDPRR017 - ldprofilereg017 */
/*! @{ */

#define locald27_LDPRR017_lumdat47_MASK          (0x3FFU)
#define locald27_LDPRR017_lumdat47_SHIFT         (0U)
/*! lumdat47 - lumdat_47 */
#define locald27_LDPRR017_lumdat47(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR017_lumdat47_SHIFT)) & locald27_LDPRR017_lumdat47_MASK)

#define locald27_LDPRR017_lumdat46_MASK          (0x3FF0000U)
#define locald27_LDPRR017_lumdat46_SHIFT         (16U)
/*! lumdat46 - lumdat_46 */
#define locald27_LDPRR017_lumdat46(x)            (((uint32_t)(((uint32_t)(x)) << locald27_LDPRR017_lumdat46_SHIFT)) & locald27_LDPRR017_lumdat46_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald27_Register_Masks */


/*!
 * @}
 */ /* end of group locald27_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD27_H_ */

