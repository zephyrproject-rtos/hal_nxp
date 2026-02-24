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
**         CMSIS Peripheral Access Layer for locald28
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
 * @file PERI_locald28.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald28
 *
 * CMSIS Peripheral Access Layer for locald28
 */

#if !defined(PERI_LOCALD28_H_)
#define PERI_LOCALD28_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald28 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald28_Peripheral_Access_Layer locald28 Peripheral Access Layer
 * @{
 */

/** locald28 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR020;                          /**< ldprofilereg020, offset: 0x0 */
  __IO uint32_t LDPRR021;                          /**< ldprofilereg021, offset: 0x4 */
  __IO uint32_t LDPRR022;                          /**< ldprofilereg022, offset: 0x8 */
  __IO uint32_t LDPRR023;                          /**< ldprofilereg023, offset: 0xC */
  __IO uint32_t LDPRR024;                          /**< ldprofilereg024, offset: 0x10 */
  __IO uint32_t LDPRR025;                          /**< ldprofilereg025, offset: 0x14 */
  __IO uint32_t LDPRR026;                          /**< ldprofilereg026, offset: 0x18 */
  __IO uint32_t LDPRR027;                          /**< ldprofilereg027, offset: 0x1C */
  __IO uint32_t LDPRR028;                          /**< ldprofilereg028, offset: 0x20 */
  __IO uint32_t LDPRR029;                          /**< ldprofilereg029, offset: 0x24 */
  __IO uint32_t LDPRR02A;                          /**< ldprofilereg02a, offset: 0x28 */
  __IO uint32_t LDPRR02B;                          /**< ldprofilereg02b, offset: 0x2C */
  __IO uint32_t LDPRR02C;                          /**< ldprofilereg02c, offset: 0x30 */
  __IO uint32_t LDPRR02D;                          /**< ldprofilereg02d, offset: 0x34 */
  __IO uint32_t LDPRR02E;                          /**< ldprofilereg02e, offset: 0x38 */
  __IO uint32_t LDPRR02F;                          /**< ldprofilereg02f, offset: 0x3C */
  __IO uint32_t LDPRR030;                          /**< ldprofilereg030, offset: 0x40 */
  __IO uint32_t LDPRR031;                          /**< ldprofilereg031, offset: 0x44 */
  __IO uint32_t LDPRR032;                          /**< ldprofilereg032, offset: 0x48 */
  __IO uint32_t LDPRR033;                          /**< ldprofilereg033, offset: 0x4C */
  __IO uint32_t LDPRR034;                          /**< ldprofilereg034, offset: 0x50 */
  __IO uint32_t LDPRR035;                          /**< ldprofilereg035, offset: 0x54 */
  __IO uint32_t LDPRR036;                          /**< ldprofilereg036, offset: 0x58 */
  __IO uint32_t LDPRR037;                          /**< ldprofilereg037, offset: 0x5C */
} locald28_Type;

/* ----------------------------------------------------------------------------
   -- locald28 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald28_Register_Masks locald28 Register Masks
 * @{
 */

/*! @name LDPRR020 - ldprofilereg020 */
/*! @{ */

#define locald28_LDPRR020_lumdat49_MASK          (0x3FFU)
#define locald28_LDPRR020_lumdat49_SHIFT         (0U)
/*! lumdat49 - lumdat_49 */
#define locald28_LDPRR020_lumdat49(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR020_lumdat49_SHIFT)) & locald28_LDPRR020_lumdat49_MASK)

#define locald28_LDPRR020_lumdat48_MASK          (0x3FF0000U)
#define locald28_LDPRR020_lumdat48_SHIFT         (16U)
/*! lumdat48 - lumdat_48 */
#define locald28_LDPRR020_lumdat48(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR020_lumdat48_SHIFT)) & locald28_LDPRR020_lumdat48_MASK)
/*! @} */

/*! @name LDPRR021 - ldprofilereg021 */
/*! @{ */

#define locald28_LDPRR021_lumdat51_MASK          (0x3FFU)
#define locald28_LDPRR021_lumdat51_SHIFT         (0U)
/*! lumdat51 - lumdat_51 */
#define locald28_LDPRR021_lumdat51(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR021_lumdat51_SHIFT)) & locald28_LDPRR021_lumdat51_MASK)

#define locald28_LDPRR021_lumdat50_MASK          (0x3FF0000U)
#define locald28_LDPRR021_lumdat50_SHIFT         (16U)
/*! lumdat50 - lumdat_50 */
#define locald28_LDPRR021_lumdat50(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR021_lumdat50_SHIFT)) & locald28_LDPRR021_lumdat50_MASK)
/*! @} */

/*! @name LDPRR022 - ldprofilereg022 */
/*! @{ */

#define locald28_LDPRR022_lumdat53_MASK          (0x3FFU)
#define locald28_LDPRR022_lumdat53_SHIFT         (0U)
/*! lumdat53 - lumdat_53 */
#define locald28_LDPRR022_lumdat53(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR022_lumdat53_SHIFT)) & locald28_LDPRR022_lumdat53_MASK)

#define locald28_LDPRR022_lumdat52_MASK          (0x3FF0000U)
#define locald28_LDPRR022_lumdat52_SHIFT         (16U)
/*! lumdat52 - lumdat_52 */
#define locald28_LDPRR022_lumdat52(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR022_lumdat52_SHIFT)) & locald28_LDPRR022_lumdat52_MASK)
/*! @} */

/*! @name LDPRR023 - ldprofilereg023 */
/*! @{ */

#define locald28_LDPRR023_lumdat55_MASK          (0x3FFU)
#define locald28_LDPRR023_lumdat55_SHIFT         (0U)
/*! lumdat55 - lumdat_55 */
#define locald28_LDPRR023_lumdat55(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR023_lumdat55_SHIFT)) & locald28_LDPRR023_lumdat55_MASK)

#define locald28_LDPRR023_lumdat54_MASK          (0x3FF0000U)
#define locald28_LDPRR023_lumdat54_SHIFT         (16U)
/*! lumdat54 - lumdat_54 */
#define locald28_LDPRR023_lumdat54(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR023_lumdat54_SHIFT)) & locald28_LDPRR023_lumdat54_MASK)
/*! @} */

/*! @name LDPRR024 - ldprofilereg024 */
/*! @{ */

#define locald28_LDPRR024_lumdat57_MASK          (0x3FFU)
#define locald28_LDPRR024_lumdat57_SHIFT         (0U)
/*! lumdat57 - lumdat_57 */
#define locald28_LDPRR024_lumdat57(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR024_lumdat57_SHIFT)) & locald28_LDPRR024_lumdat57_MASK)

#define locald28_LDPRR024_lumdat56_MASK          (0x3FF0000U)
#define locald28_LDPRR024_lumdat56_SHIFT         (16U)
/*! lumdat56 - lumdat_56 */
#define locald28_LDPRR024_lumdat56(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR024_lumdat56_SHIFT)) & locald28_LDPRR024_lumdat56_MASK)
/*! @} */

/*! @name LDPRR025 - ldprofilereg025 */
/*! @{ */

#define locald28_LDPRR025_lumdat59_MASK          (0x3FFU)
#define locald28_LDPRR025_lumdat59_SHIFT         (0U)
/*! lumdat59 - lumdat_59 */
#define locald28_LDPRR025_lumdat59(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR025_lumdat59_SHIFT)) & locald28_LDPRR025_lumdat59_MASK)

#define locald28_LDPRR025_lumdat58_MASK          (0x3FF0000U)
#define locald28_LDPRR025_lumdat58_SHIFT         (16U)
/*! lumdat58 - lumdat_58 */
#define locald28_LDPRR025_lumdat58(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR025_lumdat58_SHIFT)) & locald28_LDPRR025_lumdat58_MASK)
/*! @} */

/*! @name LDPRR026 - ldprofilereg026 */
/*! @{ */

#define locald28_LDPRR026_lumdat61_MASK          (0x3FFU)
#define locald28_LDPRR026_lumdat61_SHIFT         (0U)
/*! lumdat61 - lumdat_61 */
#define locald28_LDPRR026_lumdat61(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR026_lumdat61_SHIFT)) & locald28_LDPRR026_lumdat61_MASK)

#define locald28_LDPRR026_lumdat60_MASK          (0x3FF0000U)
#define locald28_LDPRR026_lumdat60_SHIFT         (16U)
/*! lumdat60 - lumdat_60 */
#define locald28_LDPRR026_lumdat60(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR026_lumdat60_SHIFT)) & locald28_LDPRR026_lumdat60_MASK)
/*! @} */

/*! @name LDPRR027 - ldprofilereg027 */
/*! @{ */

#define locald28_LDPRR027_lumdat63_MASK          (0x3FFU)
#define locald28_LDPRR027_lumdat63_SHIFT         (0U)
/*! lumdat63 - lumdat_63 */
#define locald28_LDPRR027_lumdat63(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR027_lumdat63_SHIFT)) & locald28_LDPRR027_lumdat63_MASK)

#define locald28_LDPRR027_lumdat62_MASK          (0x3FF0000U)
#define locald28_LDPRR027_lumdat62_SHIFT         (16U)
/*! lumdat62 - lumdat_62 */
#define locald28_LDPRR027_lumdat62(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR027_lumdat62_SHIFT)) & locald28_LDPRR027_lumdat62_MASK)
/*! @} */

/*! @name LDPRR028 - ldprofilereg028 */
/*! @{ */

#define locald28_LDPRR028_lumdat65_MASK          (0x3FFU)
#define locald28_LDPRR028_lumdat65_SHIFT         (0U)
/*! lumdat65 - lumdat_65 */
#define locald28_LDPRR028_lumdat65(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR028_lumdat65_SHIFT)) & locald28_LDPRR028_lumdat65_MASK)

#define locald28_LDPRR028_lumdat64_MASK          (0x3FF0000U)
#define locald28_LDPRR028_lumdat64_SHIFT         (16U)
/*! lumdat64 - lumdat_64 */
#define locald28_LDPRR028_lumdat64(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR028_lumdat64_SHIFT)) & locald28_LDPRR028_lumdat64_MASK)
/*! @} */

/*! @name LDPRR029 - ldprofilereg029 */
/*! @{ */

#define locald28_LDPRR029_lumdat67_MASK          (0x3FFU)
#define locald28_LDPRR029_lumdat67_SHIFT         (0U)
/*! lumdat67 - lumdat_67 */
#define locald28_LDPRR029_lumdat67(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR029_lumdat67_SHIFT)) & locald28_LDPRR029_lumdat67_MASK)

#define locald28_LDPRR029_lumdat66_MASK          (0x3FF0000U)
#define locald28_LDPRR029_lumdat66_SHIFT         (16U)
/*! lumdat66 - lumdat_66 */
#define locald28_LDPRR029_lumdat66(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR029_lumdat66_SHIFT)) & locald28_LDPRR029_lumdat66_MASK)
/*! @} */

/*! @name LDPRR02A - ldprofilereg02a */
/*! @{ */

#define locald28_LDPRR02A_lumdat69_MASK          (0x3FFU)
#define locald28_LDPRR02A_lumdat69_SHIFT         (0U)
/*! lumdat69 - lumdat_69 */
#define locald28_LDPRR02A_lumdat69(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR02A_lumdat69_SHIFT)) & locald28_LDPRR02A_lumdat69_MASK)

#define locald28_LDPRR02A_lumdat68_MASK          (0x3FF0000U)
#define locald28_LDPRR02A_lumdat68_SHIFT         (16U)
/*! lumdat68 - lumdat_68 */
#define locald28_LDPRR02A_lumdat68(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR02A_lumdat68_SHIFT)) & locald28_LDPRR02A_lumdat68_MASK)
/*! @} */

/*! @name LDPRR02B - ldprofilereg02b */
/*! @{ */

#define locald28_LDPRR02B_lumdat71_MASK          (0x3FFU)
#define locald28_LDPRR02B_lumdat71_SHIFT         (0U)
/*! lumdat71 - lumdat_71 */
#define locald28_LDPRR02B_lumdat71(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR02B_lumdat71_SHIFT)) & locald28_LDPRR02B_lumdat71_MASK)

#define locald28_LDPRR02B_lumdat70_MASK          (0x3FF0000U)
#define locald28_LDPRR02B_lumdat70_SHIFT         (16U)
/*! lumdat70 - lumdat_70 */
#define locald28_LDPRR02B_lumdat70(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR02B_lumdat70_SHIFT)) & locald28_LDPRR02B_lumdat70_MASK)
/*! @} */

/*! @name LDPRR02C - ldprofilereg02c */
/*! @{ */

#define locald28_LDPRR02C_lumdat73_MASK          (0x3FFU)
#define locald28_LDPRR02C_lumdat73_SHIFT         (0U)
/*! lumdat73 - lumdat_73 */
#define locald28_LDPRR02C_lumdat73(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR02C_lumdat73_SHIFT)) & locald28_LDPRR02C_lumdat73_MASK)

#define locald28_LDPRR02C_lumdat72_MASK          (0x3FF0000U)
#define locald28_LDPRR02C_lumdat72_SHIFT         (16U)
/*! lumdat72 - lumdat_72 */
#define locald28_LDPRR02C_lumdat72(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR02C_lumdat72_SHIFT)) & locald28_LDPRR02C_lumdat72_MASK)
/*! @} */

/*! @name LDPRR02D - ldprofilereg02d */
/*! @{ */

#define locald28_LDPRR02D_lumdat75_MASK          (0x3FFU)
#define locald28_LDPRR02D_lumdat75_SHIFT         (0U)
/*! lumdat75 - lumdat_75 */
#define locald28_LDPRR02D_lumdat75(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR02D_lumdat75_SHIFT)) & locald28_LDPRR02D_lumdat75_MASK)

#define locald28_LDPRR02D_lumdat74_MASK          (0x3FF0000U)
#define locald28_LDPRR02D_lumdat74_SHIFT         (16U)
/*! lumdat74 - lumdat_74 */
#define locald28_LDPRR02D_lumdat74(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR02D_lumdat74_SHIFT)) & locald28_LDPRR02D_lumdat74_MASK)
/*! @} */

/*! @name LDPRR02E - ldprofilereg02e */
/*! @{ */

#define locald28_LDPRR02E_lumdat77_MASK          (0x3FFU)
#define locald28_LDPRR02E_lumdat77_SHIFT         (0U)
/*! lumdat77 - lumdat_77 */
#define locald28_LDPRR02E_lumdat77(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR02E_lumdat77_SHIFT)) & locald28_LDPRR02E_lumdat77_MASK)

#define locald28_LDPRR02E_lumdat76_MASK          (0x3FF0000U)
#define locald28_LDPRR02E_lumdat76_SHIFT         (16U)
/*! lumdat76 - lumdat_76 */
#define locald28_LDPRR02E_lumdat76(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR02E_lumdat76_SHIFT)) & locald28_LDPRR02E_lumdat76_MASK)
/*! @} */

/*! @name LDPRR02F - ldprofilereg02f */
/*! @{ */

#define locald28_LDPRR02F_lumdat79_MASK          (0x3FFU)
#define locald28_LDPRR02F_lumdat79_SHIFT         (0U)
/*! lumdat79 - lumdat_79 */
#define locald28_LDPRR02F_lumdat79(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR02F_lumdat79_SHIFT)) & locald28_LDPRR02F_lumdat79_MASK)

#define locald28_LDPRR02F_lumdat78_MASK          (0x3FF0000U)
#define locald28_LDPRR02F_lumdat78_SHIFT         (16U)
/*! lumdat78 - lumdat_78 */
#define locald28_LDPRR02F_lumdat78(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR02F_lumdat78_SHIFT)) & locald28_LDPRR02F_lumdat78_MASK)
/*! @} */

/*! @name LDPRR030 - ldprofilereg030 */
/*! @{ */

#define locald28_LDPRR030_lumdat81_MASK          (0x3FFU)
#define locald28_LDPRR030_lumdat81_SHIFT         (0U)
/*! lumdat81 - lumdat_81 */
#define locald28_LDPRR030_lumdat81(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR030_lumdat81_SHIFT)) & locald28_LDPRR030_lumdat81_MASK)

#define locald28_LDPRR030_lumdat80_MASK          (0x3FF0000U)
#define locald28_LDPRR030_lumdat80_SHIFT         (16U)
/*! lumdat80 - lumdat_80 */
#define locald28_LDPRR030_lumdat80(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR030_lumdat80_SHIFT)) & locald28_LDPRR030_lumdat80_MASK)
/*! @} */

/*! @name LDPRR031 - ldprofilereg031 */
/*! @{ */

#define locald28_LDPRR031_lumdat83_MASK          (0x3FFU)
#define locald28_LDPRR031_lumdat83_SHIFT         (0U)
/*! lumdat83 - lumdat_83 */
#define locald28_LDPRR031_lumdat83(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR031_lumdat83_SHIFT)) & locald28_LDPRR031_lumdat83_MASK)

#define locald28_LDPRR031_lumdat82_MASK          (0x3FF0000U)
#define locald28_LDPRR031_lumdat82_SHIFT         (16U)
/*! lumdat82 - lumdat_82 */
#define locald28_LDPRR031_lumdat82(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR031_lumdat82_SHIFT)) & locald28_LDPRR031_lumdat82_MASK)
/*! @} */

/*! @name LDPRR032 - ldprofilereg032 */
/*! @{ */

#define locald28_LDPRR032_lumdat85_MASK          (0x3FFU)
#define locald28_LDPRR032_lumdat85_SHIFT         (0U)
/*! lumdat85 - lumdat_85 */
#define locald28_LDPRR032_lumdat85(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR032_lumdat85_SHIFT)) & locald28_LDPRR032_lumdat85_MASK)

#define locald28_LDPRR032_lumdat84_MASK          (0x3FF0000U)
#define locald28_LDPRR032_lumdat84_SHIFT         (16U)
/*! lumdat84 - lumdat_84 */
#define locald28_LDPRR032_lumdat84(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR032_lumdat84_SHIFT)) & locald28_LDPRR032_lumdat84_MASK)
/*! @} */

/*! @name LDPRR033 - ldprofilereg033 */
/*! @{ */

#define locald28_LDPRR033_lumdat87_MASK          (0x3FFU)
#define locald28_LDPRR033_lumdat87_SHIFT         (0U)
/*! lumdat87 - lumdat_87 */
#define locald28_LDPRR033_lumdat87(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR033_lumdat87_SHIFT)) & locald28_LDPRR033_lumdat87_MASK)

#define locald28_LDPRR033_lumdat86_MASK          (0x3FF0000U)
#define locald28_LDPRR033_lumdat86_SHIFT         (16U)
/*! lumdat86 - lumdat_86 */
#define locald28_LDPRR033_lumdat86(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR033_lumdat86_SHIFT)) & locald28_LDPRR033_lumdat86_MASK)
/*! @} */

/*! @name LDPRR034 - ldprofilereg034 */
/*! @{ */

#define locald28_LDPRR034_lumdat89_MASK          (0x3FFU)
#define locald28_LDPRR034_lumdat89_SHIFT         (0U)
/*! lumdat89 - lumdat_89 */
#define locald28_LDPRR034_lumdat89(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR034_lumdat89_SHIFT)) & locald28_LDPRR034_lumdat89_MASK)

#define locald28_LDPRR034_lumdat88_MASK          (0x3FF0000U)
#define locald28_LDPRR034_lumdat88_SHIFT         (16U)
/*! lumdat88 - lumdat_88 */
#define locald28_LDPRR034_lumdat88(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR034_lumdat88_SHIFT)) & locald28_LDPRR034_lumdat88_MASK)
/*! @} */

/*! @name LDPRR035 - ldprofilereg035 */
/*! @{ */

#define locald28_LDPRR035_lumdat91_MASK          (0x3FFU)
#define locald28_LDPRR035_lumdat91_SHIFT         (0U)
/*! lumdat91 - lumdat_91 */
#define locald28_LDPRR035_lumdat91(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR035_lumdat91_SHIFT)) & locald28_LDPRR035_lumdat91_MASK)

#define locald28_LDPRR035_lumdat90_MASK          (0x3FF0000U)
#define locald28_LDPRR035_lumdat90_SHIFT         (16U)
/*! lumdat90 - lumdat_90 */
#define locald28_LDPRR035_lumdat90(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR035_lumdat90_SHIFT)) & locald28_LDPRR035_lumdat90_MASK)
/*! @} */

/*! @name LDPRR036 - ldprofilereg036 */
/*! @{ */

#define locald28_LDPRR036_lumdat93_MASK          (0x3FFU)
#define locald28_LDPRR036_lumdat93_SHIFT         (0U)
/*! lumdat93 - lumdat_93 */
#define locald28_LDPRR036_lumdat93(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR036_lumdat93_SHIFT)) & locald28_LDPRR036_lumdat93_MASK)

#define locald28_LDPRR036_lumdat92_MASK          (0x3FF0000U)
#define locald28_LDPRR036_lumdat92_SHIFT         (16U)
/*! lumdat92 - lumdat_92 */
#define locald28_LDPRR036_lumdat92(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR036_lumdat92_SHIFT)) & locald28_LDPRR036_lumdat92_MASK)
/*! @} */

/*! @name LDPRR037 - ldprofilereg037 */
/*! @{ */

#define locald28_LDPRR037_lumdat95_MASK          (0x3FFU)
#define locald28_LDPRR037_lumdat95_SHIFT         (0U)
/*! lumdat95 - lumdat_95 */
#define locald28_LDPRR037_lumdat95(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR037_lumdat95_SHIFT)) & locald28_LDPRR037_lumdat95_MASK)

#define locald28_LDPRR037_lumdat94_MASK          (0x3FF0000U)
#define locald28_LDPRR037_lumdat94_SHIFT         (16U)
/*! lumdat94 - lumdat_94 */
#define locald28_LDPRR037_lumdat94(x)            (((uint32_t)(((uint32_t)(x)) << locald28_LDPRR037_lumdat94_SHIFT)) & locald28_LDPRR037_lumdat94_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald28_Register_Masks */


/*!
 * @}
 */ /* end of group locald28_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD28_H_ */

