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
**         CMSIS Peripheral Access Layer for locald42
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
 * @file PERI_locald42.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald42
 *
 * CMSIS Peripheral Access Layer for locald42
 */

#if !defined(PERI_LOCALD42_H_)
#define PERI_LOCALD42_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald42 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald42_Peripheral_Access_Layer locald42 Peripheral Access Layer
 * @{
 */

/** locald42 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR1E0;                          /**< ldprofilereg1e0, offset: 0x0 */
  __IO uint32_t LDPRR1E1;                          /**< ldprofilereg1e1, offset: 0x4 */
  __IO uint32_t LDPRR1E2;                          /**< ldprofilereg1e2, offset: 0x8 */
  __IO uint32_t LDPRR1E3;                          /**< ldprofilereg1e3, offset: 0xC */
  __IO uint32_t LDPRR1E4;                          /**< ldprofilereg1e4, offset: 0x10 */
  __IO uint32_t LDPRR1E5;                          /**< ldprofilereg1e5, offset: 0x14 */
  __IO uint32_t LDPRR1E6;                          /**< ldprofilereg1e6, offset: 0x18 */
  __IO uint32_t LDPRR1E7;                          /**< ldprofilereg1e7, offset: 0x1C */
  __IO uint32_t LDPRR1E8;                          /**< ldprofilereg1e8, offset: 0x20 */
  __IO uint32_t LDPRR1E9;                          /**< ldprofilereg1e9, offset: 0x24 */
  __IO uint32_t LDPRR1EA;                          /**< ldprofilereg1ea, offset: 0x28 */
  __IO uint32_t LDPRR1EB;                          /**< ldprofilereg1eb, offset: 0x2C */
  __IO uint32_t LDPRR1EC;                          /**< ldprofilereg1ec, offset: 0x30 */
  __IO uint32_t LDPRR1ED;                          /**< ldprofilereg1ed, offset: 0x34 */
  __IO uint32_t LDPRR1EE;                          /**< ldprofilereg1ee, offset: 0x38 */
  __IO uint32_t LDPRR1EF;                          /**< ldprofilereg1ef, offset: 0x3C */
  __IO uint32_t LDPRR1F0;                          /**< ldprofilereg1f0, offset: 0x40 */
  __IO uint32_t LDPRR1F1;                          /**< ldprofilereg1f1, offset: 0x44 */
  __IO uint32_t LDPRR1F2;                          /**< ldprofilereg1f2, offset: 0x48 */
  __IO uint32_t LDPRR1F3;                          /**< ldprofilereg1f3, offset: 0x4C */
  __IO uint32_t LDPRR1F4;                          /**< ldprofilereg1f4, offset: 0x50 */
  __IO uint32_t LDPRR1F5;                          /**< ldprofilereg1f5, offset: 0x54 */
  __IO uint32_t LDPRR1F6;                          /**< ldprofilereg1f6, offset: 0x58 */
  __IO uint32_t LDPRR1F7;                          /**< ldprofilereg1f7, offset: 0x5C */
} locald42_Type;

/* ----------------------------------------------------------------------------
   -- locald42 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald42_Register_Masks locald42 Register Masks
 * @{
 */

/*! @name LDPRR1E0 - ldprofilereg1e0 */
/*! @{ */

#define locald42_LDPRR1E0_lumd721_MASK           (0x3FFU)
#define locald42_LDPRR1E0_lumd721_SHIFT          (0U)
/*! lumd721 - lumdat_721 */
#define locald42_LDPRR1E0_lumd721(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1E0_lumd721_SHIFT)) & locald42_LDPRR1E0_lumd721_MASK)

#define locald42_LDPRR1E0_lumd720_MASK           (0x3FF0000U)
#define locald42_LDPRR1E0_lumd720_SHIFT          (16U)
/*! lumd720 - lumdat_720 */
#define locald42_LDPRR1E0_lumd720(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1E0_lumd720_SHIFT)) & locald42_LDPRR1E0_lumd720_MASK)
/*! @} */

/*! @name LDPRR1E1 - ldprofilereg1e1 */
/*! @{ */

#define locald42_LDPRR1E1_lumd723_MASK           (0x3FFU)
#define locald42_LDPRR1E1_lumd723_SHIFT          (0U)
/*! lumd723 - lumdat_723 */
#define locald42_LDPRR1E1_lumd723(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1E1_lumd723_SHIFT)) & locald42_LDPRR1E1_lumd723_MASK)

#define locald42_LDPRR1E1_lumd722_MASK           (0x3FF0000U)
#define locald42_LDPRR1E1_lumd722_SHIFT          (16U)
/*! lumd722 - lumdat_722 */
#define locald42_LDPRR1E1_lumd722(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1E1_lumd722_SHIFT)) & locald42_LDPRR1E1_lumd722_MASK)
/*! @} */

/*! @name LDPRR1E2 - ldprofilereg1e2 */
/*! @{ */

#define locald42_LDPRR1E2_lumd725_MASK           (0x3FFU)
#define locald42_LDPRR1E2_lumd725_SHIFT          (0U)
/*! lumd725 - lumdat_725 */
#define locald42_LDPRR1E2_lumd725(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1E2_lumd725_SHIFT)) & locald42_LDPRR1E2_lumd725_MASK)

#define locald42_LDPRR1E2_lumd724_MASK           (0x3FF0000U)
#define locald42_LDPRR1E2_lumd724_SHIFT          (16U)
/*! lumd724 - lumdat_724 */
#define locald42_LDPRR1E2_lumd724(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1E2_lumd724_SHIFT)) & locald42_LDPRR1E2_lumd724_MASK)
/*! @} */

/*! @name LDPRR1E3 - ldprofilereg1e3 */
/*! @{ */

#define locald42_LDPRR1E3_lumd727_MASK           (0x3FFU)
#define locald42_LDPRR1E3_lumd727_SHIFT          (0U)
/*! lumd727 - lumdat_727 */
#define locald42_LDPRR1E3_lumd727(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1E3_lumd727_SHIFT)) & locald42_LDPRR1E3_lumd727_MASK)

#define locald42_LDPRR1E3_lumd726_MASK           (0x3FF0000U)
#define locald42_LDPRR1E3_lumd726_SHIFT          (16U)
/*! lumd726 - lumdat_726 */
#define locald42_LDPRR1E3_lumd726(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1E3_lumd726_SHIFT)) & locald42_LDPRR1E3_lumd726_MASK)
/*! @} */

/*! @name LDPRR1E4 - ldprofilereg1e4 */
/*! @{ */

#define locald42_LDPRR1E4_lumd729_MASK           (0x3FFU)
#define locald42_LDPRR1E4_lumd729_SHIFT          (0U)
/*! lumd729 - lumdat_729 */
#define locald42_LDPRR1E4_lumd729(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1E4_lumd729_SHIFT)) & locald42_LDPRR1E4_lumd729_MASK)

#define locald42_LDPRR1E4_lumd728_MASK           (0x3FF0000U)
#define locald42_LDPRR1E4_lumd728_SHIFT          (16U)
/*! lumd728 - lumdat_728 */
#define locald42_LDPRR1E4_lumd728(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1E4_lumd728_SHIFT)) & locald42_LDPRR1E4_lumd728_MASK)
/*! @} */

/*! @name LDPRR1E5 - ldprofilereg1e5 */
/*! @{ */

#define locald42_LDPRR1E5_lumd731_MASK           (0x3FFU)
#define locald42_LDPRR1E5_lumd731_SHIFT          (0U)
/*! lumd731 - lumdat_731 */
#define locald42_LDPRR1E5_lumd731(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1E5_lumd731_SHIFT)) & locald42_LDPRR1E5_lumd731_MASK)

#define locald42_LDPRR1E5_lumd730_MASK           (0x3FF0000U)
#define locald42_LDPRR1E5_lumd730_SHIFT          (16U)
/*! lumd730 - lumdat_730 */
#define locald42_LDPRR1E5_lumd730(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1E5_lumd730_SHIFT)) & locald42_LDPRR1E5_lumd730_MASK)
/*! @} */

/*! @name LDPRR1E6 - ldprofilereg1e6 */
/*! @{ */

#define locald42_LDPRR1E6_lumd733_MASK           (0x3FFU)
#define locald42_LDPRR1E6_lumd733_SHIFT          (0U)
/*! lumd733 - lumdat_733 */
#define locald42_LDPRR1E6_lumd733(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1E6_lumd733_SHIFT)) & locald42_LDPRR1E6_lumd733_MASK)

#define locald42_LDPRR1E6_lumd732_MASK           (0x3FF0000U)
#define locald42_LDPRR1E6_lumd732_SHIFT          (16U)
/*! lumd732 - lumdat_732 */
#define locald42_LDPRR1E6_lumd732(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1E6_lumd732_SHIFT)) & locald42_LDPRR1E6_lumd732_MASK)
/*! @} */

/*! @name LDPRR1E7 - ldprofilereg1e7 */
/*! @{ */

#define locald42_LDPRR1E7_lumd735_MASK           (0x3FFU)
#define locald42_LDPRR1E7_lumd735_SHIFT          (0U)
/*! lumd735 - lumdat_735 */
#define locald42_LDPRR1E7_lumd735(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1E7_lumd735_SHIFT)) & locald42_LDPRR1E7_lumd735_MASK)

#define locald42_LDPRR1E7_lumd734_MASK           (0x3FF0000U)
#define locald42_LDPRR1E7_lumd734_SHIFT          (16U)
/*! lumd734 - lumdat_734 */
#define locald42_LDPRR1E7_lumd734(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1E7_lumd734_SHIFT)) & locald42_LDPRR1E7_lumd734_MASK)
/*! @} */

/*! @name LDPRR1E8 - ldprofilereg1e8 */
/*! @{ */

#define locald42_LDPRR1E8_lumd737_MASK           (0x3FFU)
#define locald42_LDPRR1E8_lumd737_SHIFT          (0U)
/*! lumd737 - lumdat_737 */
#define locald42_LDPRR1E8_lumd737(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1E8_lumd737_SHIFT)) & locald42_LDPRR1E8_lumd737_MASK)

#define locald42_LDPRR1E8_lumd736_MASK           (0x3FF0000U)
#define locald42_LDPRR1E8_lumd736_SHIFT          (16U)
/*! lumd736 - lumdat_736 */
#define locald42_LDPRR1E8_lumd736(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1E8_lumd736_SHIFT)) & locald42_LDPRR1E8_lumd736_MASK)
/*! @} */

/*! @name LDPRR1E9 - ldprofilereg1e9 */
/*! @{ */

#define locald42_LDPRR1E9_lumd739_MASK           (0x3FFU)
#define locald42_LDPRR1E9_lumd739_SHIFT          (0U)
/*! lumd739 - lumdat_739 */
#define locald42_LDPRR1E9_lumd739(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1E9_lumd739_SHIFT)) & locald42_LDPRR1E9_lumd739_MASK)

#define locald42_LDPRR1E9_lumd738_MASK           (0x3FF0000U)
#define locald42_LDPRR1E9_lumd738_SHIFT          (16U)
/*! lumd738 - lumdat_738 */
#define locald42_LDPRR1E9_lumd738(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1E9_lumd738_SHIFT)) & locald42_LDPRR1E9_lumd738_MASK)
/*! @} */

/*! @name LDPRR1EA - ldprofilereg1ea */
/*! @{ */

#define locald42_LDPRR1EA_lumd741_MASK           (0x3FFU)
#define locald42_LDPRR1EA_lumd741_SHIFT          (0U)
/*! lumd741 - lumdat_741 */
#define locald42_LDPRR1EA_lumd741(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1EA_lumd741_SHIFT)) & locald42_LDPRR1EA_lumd741_MASK)

#define locald42_LDPRR1EA_lumd740_MASK           (0x3FF0000U)
#define locald42_LDPRR1EA_lumd740_SHIFT          (16U)
/*! lumd740 - lumdat_740 */
#define locald42_LDPRR1EA_lumd740(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1EA_lumd740_SHIFT)) & locald42_LDPRR1EA_lumd740_MASK)
/*! @} */

/*! @name LDPRR1EB - ldprofilereg1eb */
/*! @{ */

#define locald42_LDPRR1EB_lumd743_MASK           (0x3FFU)
#define locald42_LDPRR1EB_lumd743_SHIFT          (0U)
/*! lumd743 - lumdat_743 */
#define locald42_LDPRR1EB_lumd743(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1EB_lumd743_SHIFT)) & locald42_LDPRR1EB_lumd743_MASK)

#define locald42_LDPRR1EB_lumd742_MASK           (0x3FF0000U)
#define locald42_LDPRR1EB_lumd742_SHIFT          (16U)
/*! lumd742 - lumdat_742 */
#define locald42_LDPRR1EB_lumd742(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1EB_lumd742_SHIFT)) & locald42_LDPRR1EB_lumd742_MASK)
/*! @} */

/*! @name LDPRR1EC - ldprofilereg1ec */
/*! @{ */

#define locald42_LDPRR1EC_lumd745_MASK           (0x3FFU)
#define locald42_LDPRR1EC_lumd745_SHIFT          (0U)
/*! lumd745 - lumdat_745 */
#define locald42_LDPRR1EC_lumd745(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1EC_lumd745_SHIFT)) & locald42_LDPRR1EC_lumd745_MASK)

#define locald42_LDPRR1EC_lumd744_MASK           (0x3FF0000U)
#define locald42_LDPRR1EC_lumd744_SHIFT          (16U)
/*! lumd744 - lumdat_744 */
#define locald42_LDPRR1EC_lumd744(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1EC_lumd744_SHIFT)) & locald42_LDPRR1EC_lumd744_MASK)
/*! @} */

/*! @name LDPRR1ED - ldprofilereg1ed */
/*! @{ */

#define locald42_LDPRR1ED_lumd747_MASK           (0x3FFU)
#define locald42_LDPRR1ED_lumd747_SHIFT          (0U)
/*! lumd747 - lumdat_747 */
#define locald42_LDPRR1ED_lumd747(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1ED_lumd747_SHIFT)) & locald42_LDPRR1ED_lumd747_MASK)

#define locald42_LDPRR1ED_lumd746_MASK           (0x3FF0000U)
#define locald42_LDPRR1ED_lumd746_SHIFT          (16U)
/*! lumd746 - lumdat_746 */
#define locald42_LDPRR1ED_lumd746(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1ED_lumd746_SHIFT)) & locald42_LDPRR1ED_lumd746_MASK)
/*! @} */

/*! @name LDPRR1EE - ldprofilereg1ee */
/*! @{ */

#define locald42_LDPRR1EE_lumd749_MASK           (0x3FFU)
#define locald42_LDPRR1EE_lumd749_SHIFT          (0U)
/*! lumd749 - lumdat_749 */
#define locald42_LDPRR1EE_lumd749(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1EE_lumd749_SHIFT)) & locald42_LDPRR1EE_lumd749_MASK)

#define locald42_LDPRR1EE_lumd748_MASK           (0x3FF0000U)
#define locald42_LDPRR1EE_lumd748_SHIFT          (16U)
/*! lumd748 - lumdat_748 */
#define locald42_LDPRR1EE_lumd748(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1EE_lumd748_SHIFT)) & locald42_LDPRR1EE_lumd748_MASK)
/*! @} */

/*! @name LDPRR1EF - ldprofilereg1ef */
/*! @{ */

#define locald42_LDPRR1EF_lumd751_MASK           (0x3FFU)
#define locald42_LDPRR1EF_lumd751_SHIFT          (0U)
/*! lumd751 - lumdat_751 */
#define locald42_LDPRR1EF_lumd751(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1EF_lumd751_SHIFT)) & locald42_LDPRR1EF_lumd751_MASK)

#define locald42_LDPRR1EF_lumd750_MASK           (0x3FF0000U)
#define locald42_LDPRR1EF_lumd750_SHIFT          (16U)
/*! lumd750 - lumdat_750 */
#define locald42_LDPRR1EF_lumd750(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1EF_lumd750_SHIFT)) & locald42_LDPRR1EF_lumd750_MASK)
/*! @} */

/*! @name LDPRR1F0 - ldprofilereg1f0 */
/*! @{ */

#define locald42_LDPRR1F0_lumd753_MASK           (0x3FFU)
#define locald42_LDPRR1F0_lumd753_SHIFT          (0U)
/*! lumd753 - lumdat_753 */
#define locald42_LDPRR1F0_lumd753(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1F0_lumd753_SHIFT)) & locald42_LDPRR1F0_lumd753_MASK)

#define locald42_LDPRR1F0_lumd752_MASK           (0x3FF0000U)
#define locald42_LDPRR1F0_lumd752_SHIFT          (16U)
/*! lumd752 - lumdat_752 */
#define locald42_LDPRR1F0_lumd752(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1F0_lumd752_SHIFT)) & locald42_LDPRR1F0_lumd752_MASK)
/*! @} */

/*! @name LDPRR1F1 - ldprofilereg1f1 */
/*! @{ */

#define locald42_LDPRR1F1_lumd755_MASK           (0x3FFU)
#define locald42_LDPRR1F1_lumd755_SHIFT          (0U)
/*! lumd755 - lumdat_755 */
#define locald42_LDPRR1F1_lumd755(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1F1_lumd755_SHIFT)) & locald42_LDPRR1F1_lumd755_MASK)

#define locald42_LDPRR1F1_lumd754_MASK           (0x3FF0000U)
#define locald42_LDPRR1F1_lumd754_SHIFT          (16U)
/*! lumd754 - lumdat_754 */
#define locald42_LDPRR1F1_lumd754(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1F1_lumd754_SHIFT)) & locald42_LDPRR1F1_lumd754_MASK)
/*! @} */

/*! @name LDPRR1F2 - ldprofilereg1f2 */
/*! @{ */

#define locald42_LDPRR1F2_lumd757_MASK           (0x3FFU)
#define locald42_LDPRR1F2_lumd757_SHIFT          (0U)
/*! lumd757 - lumdat_757 */
#define locald42_LDPRR1F2_lumd757(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1F2_lumd757_SHIFT)) & locald42_LDPRR1F2_lumd757_MASK)

#define locald42_LDPRR1F2_lumd756_MASK           (0x3FF0000U)
#define locald42_LDPRR1F2_lumd756_SHIFT          (16U)
/*! lumd756 - lumdat_756 */
#define locald42_LDPRR1F2_lumd756(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1F2_lumd756_SHIFT)) & locald42_LDPRR1F2_lumd756_MASK)
/*! @} */

/*! @name LDPRR1F3 - ldprofilereg1f3 */
/*! @{ */

#define locald42_LDPRR1F3_lumd759_MASK           (0x3FFU)
#define locald42_LDPRR1F3_lumd759_SHIFT          (0U)
/*! lumd759 - lumdat_759 */
#define locald42_LDPRR1F3_lumd759(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1F3_lumd759_SHIFT)) & locald42_LDPRR1F3_lumd759_MASK)

#define locald42_LDPRR1F3_lumd758_MASK           (0x3FF0000U)
#define locald42_LDPRR1F3_lumd758_SHIFT          (16U)
/*! lumd758 - lumdat_758 */
#define locald42_LDPRR1F3_lumd758(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1F3_lumd758_SHIFT)) & locald42_LDPRR1F3_lumd758_MASK)
/*! @} */

/*! @name LDPRR1F4 - ldprofilereg1f4 */
/*! @{ */

#define locald42_LDPRR1F4_lumd761_MASK           (0x3FFU)
#define locald42_LDPRR1F4_lumd761_SHIFT          (0U)
/*! lumd761 - lumdat_761 */
#define locald42_LDPRR1F4_lumd761(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1F4_lumd761_SHIFT)) & locald42_LDPRR1F4_lumd761_MASK)

#define locald42_LDPRR1F4_lumd760_MASK           (0x3FF0000U)
#define locald42_LDPRR1F4_lumd760_SHIFT          (16U)
/*! lumd760 - lumdat_760 */
#define locald42_LDPRR1F4_lumd760(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1F4_lumd760_SHIFT)) & locald42_LDPRR1F4_lumd760_MASK)
/*! @} */

/*! @name LDPRR1F5 - ldprofilereg1f5 */
/*! @{ */

#define locald42_LDPRR1F5_lumd763_MASK           (0x3FFU)
#define locald42_LDPRR1F5_lumd763_SHIFT          (0U)
/*! lumd763 - lumdat_763 */
#define locald42_LDPRR1F5_lumd763(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1F5_lumd763_SHIFT)) & locald42_LDPRR1F5_lumd763_MASK)

#define locald42_LDPRR1F5_lumd762_MASK           (0x3FF0000U)
#define locald42_LDPRR1F5_lumd762_SHIFT          (16U)
/*! lumd762 - lumdat_762 */
#define locald42_LDPRR1F5_lumd762(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1F5_lumd762_SHIFT)) & locald42_LDPRR1F5_lumd762_MASK)
/*! @} */

/*! @name LDPRR1F6 - ldprofilereg1f6 */
/*! @{ */

#define locald42_LDPRR1F6_lumd765_MASK           (0x3FFU)
#define locald42_LDPRR1F6_lumd765_SHIFT          (0U)
/*! lumd765 - lumdat_765 */
#define locald42_LDPRR1F6_lumd765(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1F6_lumd765_SHIFT)) & locald42_LDPRR1F6_lumd765_MASK)

#define locald42_LDPRR1F6_lumd764_MASK           (0x3FF0000U)
#define locald42_LDPRR1F6_lumd764_SHIFT          (16U)
/*! lumd764 - lumdat_764 */
#define locald42_LDPRR1F6_lumd764(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1F6_lumd764_SHIFT)) & locald42_LDPRR1F6_lumd764_MASK)
/*! @} */

/*! @name LDPRR1F7 - ldprofilereg1f7 */
/*! @{ */

#define locald42_LDPRR1F7_lumd767_MASK           (0x3FFU)
#define locald42_LDPRR1F7_lumd767_SHIFT          (0U)
/*! lumd767 - lumdat_767 */
#define locald42_LDPRR1F7_lumd767(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1F7_lumd767_SHIFT)) & locald42_LDPRR1F7_lumd767_MASK)

#define locald42_LDPRR1F7_lumd766_MASK           (0x3FF0000U)
#define locald42_LDPRR1F7_lumd766_SHIFT          (16U)
/*! lumd766 - lumdat_766 */
#define locald42_LDPRR1F7_lumd766(x)             (((uint32_t)(((uint32_t)(x)) << locald42_LDPRR1F7_lumd766_SHIFT)) & locald42_LDPRR1F7_lumd766_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald42_Register_Masks */


/*!
 * @}
 */ /* end of group locald42_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD42_H_ */

