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
**         CMSIS Peripheral Access Layer for locald41
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
 * @file PERI_locald41.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald41
 *
 * CMSIS Peripheral Access Layer for locald41
 */

#if !defined(PERI_LOCALD41_H_)
#define PERI_LOCALD41_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald41 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald41_Peripheral_Access_Layer locald41 Peripheral Access Layer
 * @{
 */

/** locald41 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR1C0;                          /**< ldprofilereg1c0, offset: 0x0 */
  __IO uint32_t LDPRR1C1;                          /**< ldprofilereg1c1, offset: 0x4 */
  __IO uint32_t LDPRR1C2;                          /**< ldprofilereg1c2, offset: 0x8 */
  __IO uint32_t LDPRR1C3;                          /**< ldprofilereg1c3, offset: 0xC */
  __IO uint32_t LDPRR1C4;                          /**< ldprofilereg1c4, offset: 0x10 */
  __IO uint32_t LDPRR1C5;                          /**< ldprofilereg1c5, offset: 0x14 */
  __IO uint32_t LDPRR1C6;                          /**< ldprofilereg1c6, offset: 0x18 */
  __IO uint32_t LDPRR1C7;                          /**< ldprofilereg1c7, offset: 0x1C */
  __IO uint32_t LDPRR1C8;                          /**< ldprofilereg1c8, offset: 0x20 */
  __IO uint32_t LDPRR1C9;                          /**< ldprofilereg1c9, offset: 0x24 */
  __IO uint32_t LDPRR1CA;                          /**< ldprofilereg1ca, offset: 0x28 */
  __IO uint32_t LDPRR1CB;                          /**< ldprofilereg1cb, offset: 0x2C */
  __IO uint32_t LDPRR1CC;                          /**< ldprofilereg1cc, offset: 0x30 */
  __IO uint32_t LDPRR1CD;                          /**< ldprofilereg1cd, offset: 0x34 */
  __IO uint32_t LDPRR1CE;                          /**< ldprofilereg1ce, offset: 0x38 */
  __IO uint32_t LDPRR1CF;                          /**< ldprofilereg1cf, offset: 0x3C */
  __IO uint32_t LDPRR1D0;                          /**< ldprofilereg1d0, offset: 0x40 */
  __IO uint32_t LDPRR1D1;                          /**< ldprofilereg1d1, offset: 0x44 */
  __IO uint32_t LDPRR1D2;                          /**< ldprofilereg1d2, offset: 0x48 */
  __IO uint32_t LDPRR1D3;                          /**< ldprofilereg1d3, offset: 0x4C */
  __IO uint32_t LDPRR1D4;                          /**< ldprofilereg1d4, offset: 0x50 */
  __IO uint32_t LDPRR1D5;                          /**< ldprofilereg1d5, offset: 0x54 */
  __IO uint32_t LDPRR1D6;                          /**< ldprofilereg1d6, offset: 0x58 */
  __IO uint32_t LDPRR1D7;                          /**< ldprofilereg1d7, offset: 0x5C */
} locald41_Type;

/* ----------------------------------------------------------------------------
   -- locald41 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald41_Register_Masks locald41 Register Masks
 * @{
 */

/*! @name LDPRR1C0 - ldprofilereg1c0 */
/*! @{ */

#define locald41_LDPRR1C0_lumd673_MASK           (0x3FFU)
#define locald41_LDPRR1C0_lumd673_SHIFT          (0U)
/*! lumd673 - lumdat_673 */
#define locald41_LDPRR1C0_lumd673(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1C0_lumd673_SHIFT)) & locald41_LDPRR1C0_lumd673_MASK)

#define locald41_LDPRR1C0_lumd672_MASK           (0x3FF0000U)
#define locald41_LDPRR1C0_lumd672_SHIFT          (16U)
/*! lumd672 - lumdat_672 */
#define locald41_LDPRR1C0_lumd672(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1C0_lumd672_SHIFT)) & locald41_LDPRR1C0_lumd672_MASK)
/*! @} */

/*! @name LDPRR1C1 - ldprofilereg1c1 */
/*! @{ */

#define locald41_LDPRR1C1_lumd675_MASK           (0x3FFU)
#define locald41_LDPRR1C1_lumd675_SHIFT          (0U)
/*! lumd675 - lumdat_675 */
#define locald41_LDPRR1C1_lumd675(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1C1_lumd675_SHIFT)) & locald41_LDPRR1C1_lumd675_MASK)

#define locald41_LDPRR1C1_lumd674_MASK           (0x3FF0000U)
#define locald41_LDPRR1C1_lumd674_SHIFT          (16U)
/*! lumd674 - lumdat_674 */
#define locald41_LDPRR1C1_lumd674(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1C1_lumd674_SHIFT)) & locald41_LDPRR1C1_lumd674_MASK)
/*! @} */

/*! @name LDPRR1C2 - ldprofilereg1c2 */
/*! @{ */

#define locald41_LDPRR1C2_lumd677_MASK           (0x3FFU)
#define locald41_LDPRR1C2_lumd677_SHIFT          (0U)
/*! lumd677 - lumdat_677 */
#define locald41_LDPRR1C2_lumd677(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1C2_lumd677_SHIFT)) & locald41_LDPRR1C2_lumd677_MASK)

#define locald41_LDPRR1C2_lumd676_MASK           (0x3FF0000U)
#define locald41_LDPRR1C2_lumd676_SHIFT          (16U)
/*! lumd676 - lumdat_676 */
#define locald41_LDPRR1C2_lumd676(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1C2_lumd676_SHIFT)) & locald41_LDPRR1C2_lumd676_MASK)
/*! @} */

/*! @name LDPRR1C3 - ldprofilereg1c3 */
/*! @{ */

#define locald41_LDPRR1C3_lumd679_MASK           (0x3FFU)
#define locald41_LDPRR1C3_lumd679_SHIFT          (0U)
/*! lumd679 - lumdat_679 */
#define locald41_LDPRR1C3_lumd679(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1C3_lumd679_SHIFT)) & locald41_LDPRR1C3_lumd679_MASK)

#define locald41_LDPRR1C3_lumd678_MASK           (0x3FF0000U)
#define locald41_LDPRR1C3_lumd678_SHIFT          (16U)
/*! lumd678 - lumdat_678 */
#define locald41_LDPRR1C3_lumd678(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1C3_lumd678_SHIFT)) & locald41_LDPRR1C3_lumd678_MASK)
/*! @} */

/*! @name LDPRR1C4 - ldprofilereg1c4 */
/*! @{ */

#define locald41_LDPRR1C4_lumd681_MASK           (0x3FFU)
#define locald41_LDPRR1C4_lumd681_SHIFT          (0U)
/*! lumd681 - lumdat_681 */
#define locald41_LDPRR1C4_lumd681(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1C4_lumd681_SHIFT)) & locald41_LDPRR1C4_lumd681_MASK)

#define locald41_LDPRR1C4_lumd680_MASK           (0x3FF0000U)
#define locald41_LDPRR1C4_lumd680_SHIFT          (16U)
/*! lumd680 - lumdat_680 */
#define locald41_LDPRR1C4_lumd680(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1C4_lumd680_SHIFT)) & locald41_LDPRR1C4_lumd680_MASK)
/*! @} */

/*! @name LDPRR1C5 - ldprofilereg1c5 */
/*! @{ */

#define locald41_LDPRR1C5_lumd683_MASK           (0x3FFU)
#define locald41_LDPRR1C5_lumd683_SHIFT          (0U)
/*! lumd683 - lumdat_683 */
#define locald41_LDPRR1C5_lumd683(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1C5_lumd683_SHIFT)) & locald41_LDPRR1C5_lumd683_MASK)

#define locald41_LDPRR1C5_lumd682_MASK           (0x3FF0000U)
#define locald41_LDPRR1C5_lumd682_SHIFT          (16U)
/*! lumd682 - lumdat_682 */
#define locald41_LDPRR1C5_lumd682(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1C5_lumd682_SHIFT)) & locald41_LDPRR1C5_lumd682_MASK)
/*! @} */

/*! @name LDPRR1C6 - ldprofilereg1c6 */
/*! @{ */

#define locald41_LDPRR1C6_lumd685_MASK           (0x3FFU)
#define locald41_LDPRR1C6_lumd685_SHIFT          (0U)
/*! lumd685 - lumdat_685 */
#define locald41_LDPRR1C6_lumd685(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1C6_lumd685_SHIFT)) & locald41_LDPRR1C6_lumd685_MASK)

#define locald41_LDPRR1C6_lumd684_MASK           (0x3FF0000U)
#define locald41_LDPRR1C6_lumd684_SHIFT          (16U)
/*! lumd684 - lumdat_684 */
#define locald41_LDPRR1C6_lumd684(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1C6_lumd684_SHIFT)) & locald41_LDPRR1C6_lumd684_MASK)
/*! @} */

/*! @name LDPRR1C7 - ldprofilereg1c7 */
/*! @{ */

#define locald41_LDPRR1C7_lumd687_MASK           (0x3FFU)
#define locald41_LDPRR1C7_lumd687_SHIFT          (0U)
/*! lumd687 - lumdat_687 */
#define locald41_LDPRR1C7_lumd687(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1C7_lumd687_SHIFT)) & locald41_LDPRR1C7_lumd687_MASK)

#define locald41_LDPRR1C7_lumd686_MASK           (0x3FF0000U)
#define locald41_LDPRR1C7_lumd686_SHIFT          (16U)
/*! lumd686 - lumdat_686 */
#define locald41_LDPRR1C7_lumd686(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1C7_lumd686_SHIFT)) & locald41_LDPRR1C7_lumd686_MASK)
/*! @} */

/*! @name LDPRR1C8 - ldprofilereg1c8 */
/*! @{ */

#define locald41_LDPRR1C8_lumd689_MASK           (0x3FFU)
#define locald41_LDPRR1C8_lumd689_SHIFT          (0U)
/*! lumd689 - lumdat_689 */
#define locald41_LDPRR1C8_lumd689(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1C8_lumd689_SHIFT)) & locald41_LDPRR1C8_lumd689_MASK)

#define locald41_LDPRR1C8_lumd688_MASK           (0x3FF0000U)
#define locald41_LDPRR1C8_lumd688_SHIFT          (16U)
/*! lumd688 - lumdat_688 */
#define locald41_LDPRR1C8_lumd688(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1C8_lumd688_SHIFT)) & locald41_LDPRR1C8_lumd688_MASK)
/*! @} */

/*! @name LDPRR1C9 - ldprofilereg1c9 */
/*! @{ */

#define locald41_LDPRR1C9_lumd691_MASK           (0x3FFU)
#define locald41_LDPRR1C9_lumd691_SHIFT          (0U)
/*! lumd691 - lumdat_691 */
#define locald41_LDPRR1C9_lumd691(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1C9_lumd691_SHIFT)) & locald41_LDPRR1C9_lumd691_MASK)

#define locald41_LDPRR1C9_lumd690_MASK           (0x3FF0000U)
#define locald41_LDPRR1C9_lumd690_SHIFT          (16U)
/*! lumd690 - lumdat_690 */
#define locald41_LDPRR1C9_lumd690(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1C9_lumd690_SHIFT)) & locald41_LDPRR1C9_lumd690_MASK)
/*! @} */

/*! @name LDPRR1CA - ldprofilereg1ca */
/*! @{ */

#define locald41_LDPRR1CA_lumd693_MASK           (0x3FFU)
#define locald41_LDPRR1CA_lumd693_SHIFT          (0U)
/*! lumd693 - lumdat_693 */
#define locald41_LDPRR1CA_lumd693(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1CA_lumd693_SHIFT)) & locald41_LDPRR1CA_lumd693_MASK)

#define locald41_LDPRR1CA_lumd692_MASK           (0x3FF0000U)
#define locald41_LDPRR1CA_lumd692_SHIFT          (16U)
/*! lumd692 - lumdat_692 */
#define locald41_LDPRR1CA_lumd692(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1CA_lumd692_SHIFT)) & locald41_LDPRR1CA_lumd692_MASK)
/*! @} */

/*! @name LDPRR1CB - ldprofilereg1cb */
/*! @{ */

#define locald41_LDPRR1CB_lumd695_MASK           (0x3FFU)
#define locald41_LDPRR1CB_lumd695_SHIFT          (0U)
/*! lumd695 - lumdat_695 */
#define locald41_LDPRR1CB_lumd695(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1CB_lumd695_SHIFT)) & locald41_LDPRR1CB_lumd695_MASK)

#define locald41_LDPRR1CB_lumd694_MASK           (0x3FF0000U)
#define locald41_LDPRR1CB_lumd694_SHIFT          (16U)
/*! lumd694 - lumdat_694 */
#define locald41_LDPRR1CB_lumd694(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1CB_lumd694_SHIFT)) & locald41_LDPRR1CB_lumd694_MASK)
/*! @} */

/*! @name LDPRR1CC - ldprofilereg1cc */
/*! @{ */

#define locald41_LDPRR1CC_lumd697_MASK           (0x3FFU)
#define locald41_LDPRR1CC_lumd697_SHIFT          (0U)
/*! lumd697 - lumdat_697 */
#define locald41_LDPRR1CC_lumd697(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1CC_lumd697_SHIFT)) & locald41_LDPRR1CC_lumd697_MASK)

#define locald41_LDPRR1CC_lumd696_MASK           (0x3FF0000U)
#define locald41_LDPRR1CC_lumd696_SHIFT          (16U)
/*! lumd696 - lumdat_696 */
#define locald41_LDPRR1CC_lumd696(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1CC_lumd696_SHIFT)) & locald41_LDPRR1CC_lumd696_MASK)
/*! @} */

/*! @name LDPRR1CD - ldprofilereg1cd */
/*! @{ */

#define locald41_LDPRR1CD_lumd699_MASK           (0x3FFU)
#define locald41_LDPRR1CD_lumd699_SHIFT          (0U)
/*! lumd699 - lumdat_699 */
#define locald41_LDPRR1CD_lumd699(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1CD_lumd699_SHIFT)) & locald41_LDPRR1CD_lumd699_MASK)

#define locald41_LDPRR1CD_lumd698_MASK           (0x3FF0000U)
#define locald41_LDPRR1CD_lumd698_SHIFT          (16U)
/*! lumd698 - lumdat_698 */
#define locald41_LDPRR1CD_lumd698(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1CD_lumd698_SHIFT)) & locald41_LDPRR1CD_lumd698_MASK)
/*! @} */

/*! @name LDPRR1CE - ldprofilereg1ce */
/*! @{ */

#define locald41_LDPRR1CE_lumd701_MASK           (0x3FFU)
#define locald41_LDPRR1CE_lumd701_SHIFT          (0U)
/*! lumd701 - lumdat_701 */
#define locald41_LDPRR1CE_lumd701(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1CE_lumd701_SHIFT)) & locald41_LDPRR1CE_lumd701_MASK)

#define locald41_LDPRR1CE_lumd700_MASK           (0x3FF0000U)
#define locald41_LDPRR1CE_lumd700_SHIFT          (16U)
/*! lumd700 - lumdat_700 */
#define locald41_LDPRR1CE_lumd700(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1CE_lumd700_SHIFT)) & locald41_LDPRR1CE_lumd700_MASK)
/*! @} */

/*! @name LDPRR1CF - ldprofilereg1cf */
/*! @{ */

#define locald41_LDPRR1CF_lumd703_MASK           (0x3FFU)
#define locald41_LDPRR1CF_lumd703_SHIFT          (0U)
/*! lumd703 - lumdat_703 */
#define locald41_LDPRR1CF_lumd703(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1CF_lumd703_SHIFT)) & locald41_LDPRR1CF_lumd703_MASK)

#define locald41_LDPRR1CF_lumd702_MASK           (0x3FF0000U)
#define locald41_LDPRR1CF_lumd702_SHIFT          (16U)
/*! lumd702 - lumdat_702 */
#define locald41_LDPRR1CF_lumd702(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1CF_lumd702_SHIFT)) & locald41_LDPRR1CF_lumd702_MASK)
/*! @} */

/*! @name LDPRR1D0 - ldprofilereg1d0 */
/*! @{ */

#define locald41_LDPRR1D0_lumd705_MASK           (0x3FFU)
#define locald41_LDPRR1D0_lumd705_SHIFT          (0U)
/*! lumd705 - lumdat_705 */
#define locald41_LDPRR1D0_lumd705(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1D0_lumd705_SHIFT)) & locald41_LDPRR1D0_lumd705_MASK)

#define locald41_LDPRR1D0_lumd704_MASK           (0x3FF0000U)
#define locald41_LDPRR1D0_lumd704_SHIFT          (16U)
/*! lumd704 - lumdat_704 */
#define locald41_LDPRR1D0_lumd704(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1D0_lumd704_SHIFT)) & locald41_LDPRR1D0_lumd704_MASK)
/*! @} */

/*! @name LDPRR1D1 - ldprofilereg1d1 */
/*! @{ */

#define locald41_LDPRR1D1_lumd707_MASK           (0x3FFU)
#define locald41_LDPRR1D1_lumd707_SHIFT          (0U)
/*! lumd707 - lumdat_707 */
#define locald41_LDPRR1D1_lumd707(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1D1_lumd707_SHIFT)) & locald41_LDPRR1D1_lumd707_MASK)

#define locald41_LDPRR1D1_lumd706_MASK           (0x3FF0000U)
#define locald41_LDPRR1D1_lumd706_SHIFT          (16U)
/*! lumd706 - lumdat_706 */
#define locald41_LDPRR1D1_lumd706(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1D1_lumd706_SHIFT)) & locald41_LDPRR1D1_lumd706_MASK)
/*! @} */

/*! @name LDPRR1D2 - ldprofilereg1d2 */
/*! @{ */

#define locald41_LDPRR1D2_lumd709_MASK           (0x3FFU)
#define locald41_LDPRR1D2_lumd709_SHIFT          (0U)
/*! lumd709 - lumdat_709 */
#define locald41_LDPRR1D2_lumd709(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1D2_lumd709_SHIFT)) & locald41_LDPRR1D2_lumd709_MASK)

#define locald41_LDPRR1D2_lumd708_MASK           (0x3FF0000U)
#define locald41_LDPRR1D2_lumd708_SHIFT          (16U)
/*! lumd708 - lumdat_708 */
#define locald41_LDPRR1D2_lumd708(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1D2_lumd708_SHIFT)) & locald41_LDPRR1D2_lumd708_MASK)
/*! @} */

/*! @name LDPRR1D3 - ldprofilereg1d3 */
/*! @{ */

#define locald41_LDPRR1D3_lumd711_MASK           (0x3FFU)
#define locald41_LDPRR1D3_lumd711_SHIFT          (0U)
/*! lumd711 - lumdat_711 */
#define locald41_LDPRR1D3_lumd711(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1D3_lumd711_SHIFT)) & locald41_LDPRR1D3_lumd711_MASK)

#define locald41_LDPRR1D3_lumd710_MASK           (0x3FF0000U)
#define locald41_LDPRR1D3_lumd710_SHIFT          (16U)
/*! lumd710 - lumdat_710 */
#define locald41_LDPRR1D3_lumd710(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1D3_lumd710_SHIFT)) & locald41_LDPRR1D3_lumd710_MASK)
/*! @} */

/*! @name LDPRR1D4 - ldprofilereg1d4 */
/*! @{ */

#define locald41_LDPRR1D4_lumd713_MASK           (0x3FFU)
#define locald41_LDPRR1D4_lumd713_SHIFT          (0U)
/*! lumd713 - lumdat_713 */
#define locald41_LDPRR1D4_lumd713(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1D4_lumd713_SHIFT)) & locald41_LDPRR1D4_lumd713_MASK)

#define locald41_LDPRR1D4_lumd712_MASK           (0x3FF0000U)
#define locald41_LDPRR1D4_lumd712_SHIFT          (16U)
/*! lumd712 - lumdat_712 */
#define locald41_LDPRR1D4_lumd712(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1D4_lumd712_SHIFT)) & locald41_LDPRR1D4_lumd712_MASK)
/*! @} */

/*! @name LDPRR1D5 - ldprofilereg1d5 */
/*! @{ */

#define locald41_LDPRR1D5_lumd715_MASK           (0x3FFU)
#define locald41_LDPRR1D5_lumd715_SHIFT          (0U)
/*! lumd715 - lumdat_715 */
#define locald41_LDPRR1D5_lumd715(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1D5_lumd715_SHIFT)) & locald41_LDPRR1D5_lumd715_MASK)

#define locald41_LDPRR1D5_lumd714_MASK           (0x3FF0000U)
#define locald41_LDPRR1D5_lumd714_SHIFT          (16U)
/*! lumd714 - lumdat_714 */
#define locald41_LDPRR1D5_lumd714(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1D5_lumd714_SHIFT)) & locald41_LDPRR1D5_lumd714_MASK)
/*! @} */

/*! @name LDPRR1D6 - ldprofilereg1d6 */
/*! @{ */

#define locald41_LDPRR1D6_lumd717_MASK           (0x3FFU)
#define locald41_LDPRR1D6_lumd717_SHIFT          (0U)
/*! lumd717 - lumdat_717 */
#define locald41_LDPRR1D6_lumd717(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1D6_lumd717_SHIFT)) & locald41_LDPRR1D6_lumd717_MASK)

#define locald41_LDPRR1D6_lumd716_MASK           (0x3FF0000U)
#define locald41_LDPRR1D6_lumd716_SHIFT          (16U)
/*! lumd716 - lumdat_716 */
#define locald41_LDPRR1D6_lumd716(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1D6_lumd716_SHIFT)) & locald41_LDPRR1D6_lumd716_MASK)
/*! @} */

/*! @name LDPRR1D7 - ldprofilereg1d7 */
/*! @{ */

#define locald41_LDPRR1D7_lumd719_MASK           (0x3FFU)
#define locald41_LDPRR1D7_lumd719_SHIFT          (0U)
/*! lumd719 - lumdat_719 */
#define locald41_LDPRR1D7_lumd719(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1D7_lumd719_SHIFT)) & locald41_LDPRR1D7_lumd719_MASK)

#define locald41_LDPRR1D7_lumd718_MASK           (0x3FF0000U)
#define locald41_LDPRR1D7_lumd718_SHIFT          (16U)
/*! lumd718 - lumdat_718 */
#define locald41_LDPRR1D7_lumd718(x)             (((uint32_t)(((uint32_t)(x)) << locald41_LDPRR1D7_lumd718_SHIFT)) & locald41_LDPRR1D7_lumd718_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald41_Register_Masks */


/*!
 * @}
 */ /* end of group locald41_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD41_H_ */

